/*
 * Copyright (c) 2023-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup service_file_tools
 * @{
 *
 * @file fm_mng.c
 *
 * @brief File Manager functions containing the public API and higher level internal functions.
 * @details Terminology:
 * - storage - an abstract representation of a device which provides the space for the file system.
 * - storage api - a list of basic functions to access the storage device.
 * - file system - same meaning as in the context of a computer file system.
 * - file system api - a list of basic functions to access the file system.
 * - file system api object - structure which is manipulated by the api.
 * - volume - a structure combining a storage device with a file system.
 * - fm_file_obj_t - an opaque structure used to allocated the bytes necessary for a file object.
 * - fm_int_file_t - the internally used structure to represent a file object. It contains a header and a file object used by the underlying file system.
 * - fm_handle_t - a pointer to a file or directory object.
 * - fm_header_t - an internal structure that contains the file manager metadata for a handle object and also the bytes necessary for the file system.
 * - fm_index_t - a pointer to a fm_header_t. It is used for simplification, otherwise a lot of asterix would be written in the code causing unreadability and confusion.
 * @details Although currently there is only one file system (FATFS) and one storage device (SD Card),\n
 *  the file manager is designed to be able to handle multiple storage devices and file systems.\n
 *  Also file systems and storage devices are intended to be combined in any way.\n
 *  This would would require extension of either storage of file system API whenever additional functionalities are needed.\n
 *  The file manager is designed to be thread safe and to be able to handle multiple threads accessing the file system.\n
 *  The file manager is also designed to be able to handle multiple file operations at the same time.\n
 *  Currently, the storage api does not use a "storage API object" like the file system API does, but this will be implemented in the future.\n
 *  A volume has a list of available fm_index_t and a list of preallocated file objects.\n
 *  The preallocated file objects may be none but must be no more then the count of the fm_index_t provided to the volume.\n
 *  Two or more volumes may share the same pool of fm_index_t or preallocated file objects or each have its own them exclusively.\n
 *  The inclusion of ff.h is necessary to have the correct size for the file objects used by the FATFS file system.\n
 *  Both ff.h and diskio.h as needed to assert that the types defined in fm_mng.h are the equal to the ones in ff.h.\n
 *  The file manager is based mostly on the interface provided by ff.h, due to its simplicity and the fact that it was already used in the project.
 *  The changes to the file manager are expected to not change the current interface, but internally a few fixed types and structures would be changed.
 *
 * @}
 */

#include "es_cdef.h"
#include "cmsis_os2.h"
#include <string.h>
#include "debug.h"
#include "es_exeh.h"
#include "trace.h"
#include "nvm.h"
#include "stack_file.h"
#include "sd_mng.h"
#include "ff_mng.h"
#include "fm_mng_def.h"
#include "fm_mng.h"
#include "fm_common_def.h"
#include "ff.h"
#include "taskmon.h"
#include "taskmon_stat.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

/**
 * @brief The size of stack allocated for the file manager task in bytes.
 */
#define FM_TASK_STACK_SIZE (1024)

/**
 * @brief The name of the SD volume without the leading path delimiter.
 */
#define FM_VOL_SD_NAME "sd"

/**
 * @brief The maximum length of the volume path prefix.
 * @details The prefix is the leading path delimiter(s), the volume name and the trailing path delimiter(s).
 */
#define FM_VOLUME_MAX_PREFIX_LEN (10)
/**
 * @brief The maximum number of consequitive path delimiters in a file path.
 */
#define FM_MAX_DELIMITER (5)
/**
 * @brief The maximum length of a volume name.
 */
#define FM_VOLUME_MAX_NAMELEN (5)
/**
 * @brief The size of the message queue in message count used for inter task communication.
 */
#define FM_QUEUE_SIZE (10)
/**
 * @brief The size of a single message in bytes used for inter task communication.
 */
#define FM_QUEUE_MESSAGE_SIZE (sizeof(fm_message_t))

/**
 * @brief The char symbol used to represent a directory in the file system in the resulting fm_list file.
 */
#define DIR_MARKER ((char)'d')
/**
 * @brief The char symbol used to represent a file in the file system in the resulting fm_list file.
 */
#define FILE_MARKER ((char)'f')

/**
 * @brief The ascii delete character, used as a upper limit for permitted ascii chars.
 */
#define ASCII_DELETE_CHAR ((char)0x7F)
/**
 * @brief The ascii space character, used as a lower limit for permitted ascii chars.
 */
#define ASCII_SPACE_CHAR ((char)' ')
/**
 * @brief The default (unix-style) character for a path delimiter.
 */
#define PATH_DELIMITER_CHAR ((char)'/')
/**
 * @brief The alternative (windows-style) character for a path delimiter.
 */
#define PATH_DELIMITER_ALT_CHAR ((char)'\\')
/**
 * @brief The default (unix-style) string for a path delimiter. Used for string operations.
 */
#define PATH_DELIMITER_STR ("/")
/**
 * @brief The alternative (windows-style) string for a path delimiter. Used for string operations.
 */
#define PATH_DELIMITER_ALT_STR ("\\")
/**
 * @brief An empty string constant. Used for string operations.
 */
#define EMPTY_STR ("")
/**
 * @brief The default (unix-style) string length for a path delimiter. Used for string operations.
 */
#define PATH_DELIMITER_LEN (sizeof(PATH_DELIMITER_STR) - sizeof(TERMINATING_ZERO_CHAR))
/**
 * @brief The forbidden ascii characters in a file path. For file base name also path delimiters are forbidden.
 */
#define FM_FORBIDDEN_CHARS ("\"*:<>?|,")

/**
 * @brief The glob pattern used to match all files within given context.
 */
#define MATCH_ALL ("*")
/**
 * @brief The name for the temporary file used for recursive directory operations. See @ref fm_foreach, @ref fm_list.
 */
#define INTERNAL_STACK_FILE "__stack.tmp"

/**
 * @brief The amount of time in milliseconds for waiting for a message from the file manager task.
 * @details If no message is received within the timeout, maintenance tasks are performed.
 */
#define FM_TASK_MESSAGE_TIMEOUT (10000)

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/**
 * @brief A list of all currently implemented volumes.
 */
typedef enum
{
    VOL_SD = 0, /**< The SD card volume */
    VOL_COUNT   /**< The number of volumes */
} volume_index_t;

/**
 * @brief Mount status of a volume.
 */
typedef enum
{
    NOMOUNT = 0, /**< Ignore the volume mount status */
    MOUNT   = 1, /**< The volume is mounted */
    UMOUNT  = 2  /**< The volume is unmounted */
} mount_action_t;

/**
 * @brief The type of the handle object.
 */
typedef enum
{
    HANDLE_TYPE_EMPTY, /**< The handle is not used */
    HANDLE_TYPE_FILE,  /**< The handle is used for a file */
    HANDLE_TYPE_DIR,   /**< The handle is used for a directory */
} handle_type_t;

/**
 * @brief A hollow declaration for the fm_header_t.
 * @details It is needed because fm_header_t contains members that are a pointer to itself.
 */
struct fm_header_tag;

/**
 * @brief A pointer to the fm_header_t.
 * @details Used for simplified abstraction.
 */
typedef struct fm_header_tag *fm_index_t;

/**
 * @brief The structure representing a volume.
 */
typedef struct volume_tag
{
    char                    name[FM_VOLUME_MAX_NAMELEN + sizeof("")]; /**< The name of the volume */
    uint8_t                 namelen;                                  /**< The length of the name of the volume */
    const fm_storage_api_t *p_drv_api;                                /**< The driver api for the volume */
    diskio_obj_t            drv_obj;                                  /**< The driver object for the volume */
    const fs_api_t         *p_fs_api;                                 /**< The file system api for the volume */
    fs_api_obj_t            fs_obj;                                   /**< The file system object for the volume */
    fm_storage_status_t     storage_status;                           /**< The status of the storage device */
    mount_action_t          mount_status;                             /**< The mount status of the volume */
    fm_index_t             *index_list;                               /**< The list available file objects */
    size_t                  index_list_count;                         /**< The count of available file objects */
    fm_index_t             *header_list;                              /**< The list of preallocated file objects */
    size_t                  header_list_count;                        /**< The count of preallocated file objects */
    int8_t                  handle_use;                               /**< The count of used file objects */
    int8_t                  dir_use;                                  /**< The count of used directory objects */
    int8_t                  max_handle_use;                           /**< The maximum count of used file objects */
    int8_t                  max_dir_use;                              /**< The maximum count of used directory objects */
} volume_t;

/**
 * @brief The structure representing a file manager header.
 */
typedef struct fm_header_tag
{
    volume_t     *p_volume; /**< The volume of the file */
    fm_index_t   *p_index;  /**< The header structure of the file */
    handle_type_t type;     /**< The type of the object */
} fm_header_t;

/**
 * @brief The structure representing a the real file object.
 */
typedef struct
{
    fm_header_t hdr;           /**< The header (i.e. file manager metadata) of the file */
    FIL         do_not_access; /**< The file object of the file used by the file system below */
} fm_int_file_t;

/**
 * @brief The structure representing a the real directory object.
 */
typedef struct
{
    fm_header_t hdr;           /**< The header (i.e. file manager metadata) of the directory */
    FF_DIR      do_not_access; /**< The directory object of the directory used by the file system below */
} fm_int_dir_t;

/**
 * @brief The structure representing a file manager message.
 */
typedef struct
{
    volume_t           *p_vol;  /**< The volume of the message */
    fm_storage_status_t status; /**< The status of the storage device */
} fm_message_t;

/**
 * @brief An internal structure for passing data and handler to the recursive foreach_stack function.
 */
typedef struct
{
    fm_foreach_handler_t handler; /**< The handler function */
    void                *p_data;  /**< arbitrary data used internally */
} foreach_info_t;

/**
 * @brief A structure for passing internal data for the fm_list function.
 */
typedef struct
{
    handle_obj_t   *handle; /**< The handle to the file receiving the file list */
    const volume_t *p_vol;  /**< The volume of the file */
} list_handler_data_t;

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/

/**
 * @brief The list of opened file or dir objects.
 */
static fm_index_t sd_index_list[FM_VOL_SD_MAX_INDEX] = { 0 };
/**
 * @brief The list of pre-allocated file objects for the sd volume.
 * @note The sd_file_list is never accessed directly, but through the header list, see implementation of fm_init().
 */
static fm_int_file_t sd_file_list[FM_VOL_SD_MAX_PREALLOCATED_FILES] = { 0 };

/**
 * @brief The list of pointers to header objects to available files for the sd volume.
 */
static fm_header_t *sd_header_list[FM_VOL_SD_MAX_PREALLOCATED_FILES] = { 0 };

/**
 * @brief The list of all currently implemented volumes.
 */
static volume_t volume_list[VOL_COUNT] = {
    [VOL_SD] = {
                .name              = FM_VOL_SD_NAME,
                .namelen           = sizeof(FM_VOL_SD_NAME) - sizeof(""),
                .p_drv_api         = NULL,
                .drv_obj           = NULL,
                .p_fs_api          = NULL,
                .fs_obj            = NULL,
                .storage_status    = STORAGE_STATUS_EJECTED,
                .mount_status      = UMOUNT,
                .index_list        = sd_index_list,
                .index_list_count  = CDEF_ELEMENT_COUNT(sd_index_list),
                .header_list       = sd_header_list,
                .header_list_count = CDEF_ELEMENT_COUNT(sd_header_list),
                .handle_use        = 0,
                .dir_use           = 0,
                .max_handle_use    = 0,
                .max_dir_use       = 0,
                }
};

/**
 * @brief The default volume used for file operations.
 */
static volume_t *const p_default_volume = &volume_list[VOL_SD];

/**
 * @brief The mutex used for file manager operations.
 */
static osMutexId_t fm_mutex = NULL;

/**
 * @brief The queue object used for inter task communication.
 */
static osMessageQueueId_t ATOMIC_ALIGN fm_queue = NULL;

/**
 * @brief The thread object of the file manager task.
 */
static osThreadId_t ATOMIC_ALIGN fm_task_handle = NULL;

/**
 * @brief The global statistics of the file manager.
 */
static fm_stats_t fm_stats = { 0 };

/**
 * @brief The flag indicating whether the statistics should be stored in the NVM.
 */
static bool should_store_stats = false;

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/

/**
 * @brief Get a string representation of the mount action.
 */
static inline const char *getcstr_mount_action(const mount_action_t e);

/**
 * @brief Get a string representation of the storage status.
 */
static inline const char *getcstr_storage_status(const fm_storage_status_t status);

/**
 * @brief Lock the file manager mutex.
 */
static inline void fm_lock(void);

/**
 * @brief Unlock the file manager mutex.
 */
static inline void fm_unlock(void);

/**
 * @brief Check if the given character is a path delimiter.
 * @param[in] ch The character to check.
 */
static inline bool is_char_path_delimiter(const char ch);

/**
 * @brief Check if the given character is a path delimiter or zero.
 * @param[in] ch The character to check.
 */
static inline bool is_char_path_delimiter_or_zero(const char ch);

/**
 * @brief Check if the given character is a valid path character.
 * @param[in] ch The character to check.
 */
static inline bool is_char_path_valid(const char ch);

/**
 * @brief Get the default volume used for file operations.
 * @param[out] p_out_p_vol Pointer to the pointer which will be set to point to the default volume.
 */
static fm_result_t get_default_volume(volume_t **p_out_p_vol);

/**
 * @brief Find the volume matching the beginning of the given path and move the pointer to the next character after the volume name and delimiter(s) suffix if any.
 * @param[in,out] p_out_p_path Pointer to string pointer, which will be read and matched to the volume name. The pointer will be moved past the volume name and delimiter(s) suffix, if any.
 * @param[out] p_out_p_vol Pointer to the pointer which will be set to point to the default volume.
 * @retval FM_RES_OK The volume was found.
 * @retval FM_RES_NO_PATH The volume was not found.
 * @note This functions will not match for a default volume.
 */
static fm_result_t find_volume(const char **p_out_p_path, volume_t **p_out_vol);

/**
 * @brief Parse the beginning of the string and try to find a matching volume.
 * @param[in,out] p_out_p_path Pointer to string pointer, which will be read and matched to the volume name. The pointer will be moved past the volume name and delimiter(s) suffix, if any. The pointer to pointer or the pointed pointer must not be NULL.
 * @param[out] p_out_p_vol Pointer to the pointer which will be set to point to the default volume. Must not be NULL.
 * @retval FM_RES_OK The volume was found.
 * @retval FM_RES_NO_PATH The volume was not found.
 * @note This functions will match also the default volume, i.e. paths not starting with path delimiter(s) or an empty string.
 */
static fm_result_t adjust_path_and_get_volume(const char **const p_out_p_path, volume_t **p_out_p_vol);

/**
 * @brief Move a pointer string after any path delimiter(s) in the beginning of the string.
 * @param[in,out] p_out_p_path Pointer to string pointer, which will be read and moved past the delimiter(s). The pointer to pointer or the pointed pointer must not be NULL.
 * @param[in] max_chars The maximum number of characters to move the pointer.
 * @retval true The pointer was moved past the delimiter(s).
 * @retval false The pointer was not moved past the delimiter(s).
 */
static bool skip_path_delimiter(const char **p_out_p_path, size_t max_chars);

/**
 * @brief Read the path and normalize it.
 * @details Normalization means removing redundant path delimiters and skipping the leading volume prefix, if any.
 * @param[in] p_in_source The source path to normalize.
 * @param[out] p_out_destination The destination buffer for the normalized path.
 * @return Result of performed operation, @ref fm_result_t
 */
static fm_result_t normalize_path(const char *const p_in_source, char *const p_out_destination);

/**
 * @brief Get the volume and normalize the path.
 * @details this is like @ref adjust_path_and_get_volume and @ref normalize_path combined.
 * @param[in] p_in_path The source path to normalize.
 * @param[out] p_out_normal_path The destination buffer for the normalized path.
 * @param[out] p_out_p_vol Pointer to the pointer which will be set to point to the matched volume. Must not be NULL.
 * @return Result of performed operation, @ref fm_result_t
 */
static fm_result_t get_volume_and_normalize_path(
    const char *const p_in_path,
    char *const       p_out_normal_path,
    volume_t        **p_out_p_vol);

/**
 * @brief Get the volume from the path.
 * @details This function is a simplification of @ref adjust_path_and_get_volume.
 *          It will only match a volume prefix, and does not expect a file/dir path afterwards.
 *          Also, no path normalization is made.
 * @param[in] p_in_path The source path to normalize.
 * @param[out] p_out_p_vol Pointer to the pointer which will be set to point to the matched volume. Must not be NULL.
 * @return Result of performed operation, @ref fm_result_t
 */
static fm_result_t get_volume_from_path(const char *const p_in_path, volume_t **p_out_p_vol);

/**
 * @brief Bind a file object to a volume. Same as @ref get_free_index, but without locking.
 * @note @ref fm_lock is expected to be called already in this context.
 * @param[in] p_in_vol The volume to be bound to.
 * @param[in,out] p_inout_file The file object to be initialized.
 * @return Result of performed operation, @ref fm_result_t
 */
static fm_result_t get_free_index_without_lock(volume_t *const p_in_vol, fm_header_t *const p_inout_file);

/**
 * @brief Bind a file object to a volume.
 * @param[in] p_in_vol The volume to be bound to.
 * @param[in,out] p_inout_file The file object to be initialized.
 * @return Result of performed operation, @ref fm_result_t
 */
static fm_result_t get_free_index(volume_t *const p_in_vol, fm_header_t *const p_inout_file);

/**
 * @brief Set a fm_header_t pointer to point to a preallocated file object.
 * @param[in] p_in_vol The volume to be bound to.
 * @param[out] p_out_p_header Pointer to a pointer, which will be set to an internally preallocated file object.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t get_free_file_object(volume_t *const p_in_vol, fm_header_t **const p_out_p_header);

/**
 * @brief Check if the given handle is valid and of the given type.
 * @param[in] handle The handle to check.
 */
static bool is_valid_handle(c_fm_handle_t handle, const handle_type_t type);

/**
 * @brief Integrity check if the given handle is correctly bound to a volume.
 * @param[in] handle The handle to check.
 * @retval true The handle is correctly bound to a volume.
 * @retval false The handle is not correctly bound to a volume.
 */
static bool is_handle_in_index_list(c_fm_handle_t handle);

/**
 * @brief Unbind a file object from a volum without locking. Same as @ref release_index, but without locking.
 * @note @ref fm_lock is expected to be called already in this context.
 * @param[in] p_in_index The file object to be released.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t release_index_without_lock(fm_index_t *const p_in_index);

/**
 * @brief Unbind a file object from a volume.
 * @param[in] p_in_index The file object to be released.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t release_index(fm_index_t *p_index);

/**
 * @brief Unbind all file objects from a given volume.
 * @param[in] p_vol The volume to release all file objects from.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t release_index_by_volume(const volume_t *const p_vol);

/**
 * @brief Unbind file handle from a volume.
 * @param[in] handle The handle to release.
 * @return Result of performed operation, @ref fm_result_t.
 */
static inline fm_result_t release_handle(fm_handle_t handle);

/**
 * @brief Get count of bound file objects to all volumes.
 * @return The count of bound file objects to all volumes.
 */
static uint32_t get_opened_handle_count_all_volumes(void);

/**
 * @brief Get count of bound file objects to a given volume.
 * @param[in] p_in_vol The volume to get the count of bound file objects.
 * @return The count of bound file objects to a given volume.
 */
static uint32_t get_opened_handle_count(const volume_t *const p_in_vol);

/**
 * @brief Helper function to get the implicit file object used by the lower layer file system.
 * @note To put it bluntly, fm_header_t is a file manager metadata, while any bytes after it are the file object used by the file system.
 *       In case of FATFS that would be a FIL object.
 * @param[in] p_hdr The file to get the lower layer bytes from.
 * @return The file object used by the lower layer file system.
 */
static inline handle_obj_t get_file_obj(fm_header_t *p_hdr);

/**
 * @brief Callback function which responds to storage status updates.
 * @details This function triggers a message to the file manager task to update the storage status of the volume.
 *          The purpose is to decouple the calling thread from file manager task.
 * @param[in] status The status of the storage device.
 * @param[in,out] p_inout_user_data The user data which was set when registering the callback. See @ref fm_init.
 */
static void storage_status_update_callback(const fm_storage_status_t status, void *const p_inout_user_data);

/**
 * @brief Update the storage status of a volume.
 * @param[in] p_in_vol The volume to update the storage status of.
 * @param[in] status The new storage status of the volume.
 */
static void update_storage_status(volume_t *const p_in_vol, const fm_storage_status_t status);

/**
 * @brief Update the statistics of the file manager.
 * @note Currently all statistics are aggegated for all volumes in one place.
 *       There is an intention to have separate statistics for each volume in the future.
 *       The statistics are stored in the NVM and that complicates things.
 */
static void update_stats(fm_result_t fr);

/**
 * @brief Helper function for calculating the CRC of a file.
 * @param[in] p_vol The volume of the file.
 * @param[in] p_header The file which CRC is to be calculated.
 * @param[in] p_buffer The buffer to read the file into.
 * @param[in] buffer_size The size of the buffer.
 * @param[out] p_out_crc The calculated CRC of the file.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t crc_read(
    const volume_t *const p_vol,
    fm_header_t *const    p_header,
    uint8_t *const        p_buffer,
    const size_t          buffer_size,
    uint32_t *const       p_out_crc);

/**
 * @brief Helper function for calculating the CRC of an opened file.
 * @param[in] p_in_vol The volume of the file.
 * @param[in] p_header The file which CRC is to be calculated.
 * @param[out] p_out_crc The calculated CRC of the file.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t crc_opened_file(const volume_t *const p_in_vol, fm_header_t *const p_header, uint32_t *const p_out_crc);

/**
 * @brief Helper handler function for @ref fm_list.
 * @details This function is used to write the matched files to the list file.
 * @param[in] info File info of the matched file.
 * @param[in] user_data The user data passed to the handler. In this case the volume and the listing file.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t file_list_handler(const fm_fast_file_info_t *const info, void *const user_data);

/**
 * @brief Helper function for @ref fm_list for filtering directories to recurse into.
 * @details This function is called on all items within a directory to decide whether to recurse into the directory or not.
 * @param[in] info Info of the matched directory item (file or directory).
 * @param[in] user_data The user data passed to the handler. In this case the stack file context.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t foreach_dir_handler(const fm_fast_file_info_t *const p_info, void *const p_inout_user_data);

/**
 * @brief Helper function for @ref fm_list for matching the user glob pattern.
 * @details @ref INTERNAL_STACK_FILE is skipped. @ref file_list_handler() is called on all other files/directories.
 * @param[in] p_info Info of the matched file.
 * @param[in] p_inout_user_data The user data passed to the handler. In this case the volume and the listing file.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t foreach_match_handler(const fm_fast_file_info_t *const p_info, void *const p_inout_user_data);

/**
 * @brief Helper function for @ref fm_list which does most of the work.
 * @details This function uses a stack file (see @ref stack_file.h) to store the recursive directory list.
 * @param[in] p_vol The volume to list the files from.
 * @param[in] p_in_path The path to list the files from. The root path of the given volume in this case.
 * @param[in] p_in_glob The glob pattern to match the files against.
 * @param[in] handler The handler function to call on the matched files. In this case @ref file_list_handler.
 * @param[in] p_inout_user_data The user data passed to the handler. In this case the volume and the listing file.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t foreach_stack(const volume_t *const p_vol, const char *const p_in_path, const char *const p_in_glob, const fm_foreach_handler_t handler, void *const p_inout_user_data);

/**
 * @brief The function for the file manager task.
 * @details This function is the main loop of the file manager task.
 *          The loop checks for statistics update events to store them in the NVM.
 *          It also checks for messages from the storage status update callback.
 * @param[in] p_arg The argument passed to the task. Not used.
 */
static void fm_task(void *p_arg);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

const char *fm_result_to_str(fm_result_t result)
{
    static const char *str_fm_result[] = {
        "FM_RES_OK",
        "FM_RES_DISK_ERR",
        "FM_RES_INT_ERR",
        "FM_RES_NOT_READY",
        "FM_RES_NO_FILE",
        "FM_RES_NO_PATH",
        "FM_RES_INVALID_NAME",
        "FM_RES_DENIED",
        "FM_RES_EXIST",
        "FM_RES_INVALID_OBJECT",
        "FM_RES_WRITE_PROTECTED",
        "FM_RES_INVALID_DRIVE",
        "FM_RES_NOT_ENABLED",
        "FM_RES_NO_FILESYSTEM",
        "FM_RES_MKFS_ABORTED",
        "FM_RES_TIMEOUT",
        "FM_RES_LOCKED",
        "FM_RES_NOT_ENOUGH_CORE",
        "FM_RES_TOO_MANY_OPEN_FILES",
        "FM_RES_INVALID_PARAMETER",
    };

    if (result < CDEF_ELEMENT_COUNT(str_fm_result))
    {
        return str_fm_result[result];
    }
    return "FM_RES_UNKNOWN";
}

void fm_init(void)
{
    static_assert(sizeof(fm_int_file_t) == sizeof(fm_file_obj_t), "fm_int_file_t and fm_file_obj_t must be the same size");
    static_assert(sizeof(fm_int_dir_t) == sizeof(fm_dir_obj_t), "fm_int_dir_t and fm_dir_obj_t must be the same size");

    fm_mutex = osMutexNew(NULL);

    (void)sd_init();
    (void)ff_init();

    static_assert(CDEF_ELEMENT_COUNT(sd_file_list) == CDEF_ELEMENT_COUNT(sd_header_list));
    fm_header_t  **hdr                = sd_header_list;
    fm_int_file_t *file               = sd_file_list;
    size_t         sd_file_list_count = CDEF_ELEMENT_COUNT(sd_file_list);
    for (size_t i = 0; i < sd_file_list_count; i++, hdr++, file++)
    {
        *hdr = &file->hdr;
    }

    Nvm_GetBlockById(NVM_FM_STATS, &fm_stats);

    volume_t *const p_sd_vol = &volume_list[VOL_SD];
    p_sd_vol->p_drv_api      = sd_get_default_driver();

    ff_get_default_api_and_obj(&p_sd_vol->fs_obj, &p_sd_vol->p_fs_api);
    ff_set_driver(p_sd_vol->fs_obj, p_sd_vol->p_drv_api);

    sd_set_status_change_callback(&storage_status_update_callback, (void *)p_sd_vol);

    fm_queue                            = osMessageQueueNew(FM_QUEUE_SIZE, FM_QUEUE_MESSAGE_SIZE, NULL);
    static osThreadAttr_t thread_attr   = { 0 };
    static const char    *p_thread_name = "fm_mng_task";
    thread_attr.name                    = p_thread_name;
    thread_attr.priority                = osPriorityNormal;
    thread_attr.stack_size              = FM_TASK_STACK_SIZE;

    fm_task_handle = osThreadNew(fm_task, NULL, &thread_attr);
    task_mon_register_for_stats(TASK_ID_FM_MANAGER, fm_task_handle);
}

fm_result_t fm_open(fm_handle_t handle, const char *const p_in_path, const uint32_t mode)
{
    fm_result_t  ret                     = FM_RES_INVALID_OBJECT;
    fm_result_t  ret_norm                = FM_RES_INT_ERR;
    fm_result_t  ret_free                = FM_RES_INT_ERR;
    bool         handle_is_in_index_list = false;
    char         norm_path[FM_MAX_PATH]  = { 0 };
    volume_t    *p_vol;
    fm_header_t *p_header = (fm_header_t *)handle;

    handle_is_in_index_list = is_handle_in_index_list(handle);
    if (false == handle_is_in_index_list)
    {
        ret = ret_norm = get_volume_and_normalize_path(p_in_path, norm_path, &p_vol);
    }
    else
    {
        ES_TRACE_INFO("Handle '%p' is already used to open a file", handle);
    }
    if (FM_RES_OK == ret_norm)
    {
        ret = ret_free = get_free_index(p_vol, p_header);
    }
    else
    {
        ES_TRACE_INFO("Could not resolve path '%.*s', error %d '%s'", FM_MAX_PATH, p_in_path == NULL ? "(NULL)" : p_in_path, ret, fm_result_to_str(ret));
    }

    if (FM_RES_OK == ret_free)
    {
        ret = p_vol->p_fs_api->open(p_vol->fs_obj, get_file_obj(p_header), norm_path, mode);
        if (FM_RES_OK == ret)
        {
            ES_TRACE_DEBUG("Successfully opened \"%s\", handle: %p", norm_path, handle);
            p_header->type = HANDLE_TYPE_FILE;
        }
        else
        {
            ES_TRACE_INFO("Could not open path '%s', error %d '%s'", norm_path, ret, fm_result_to_str(ret));
            (void)release_index(p_header->p_index);
        }
        update_stats(ret);
    }
    return ret;
}

fm_result_t fm_open_internal(fm_handle_t *const p_out_handle, const char *const p_in_path, const uint32_t mode)
{
    fm_result_t  ret      = FM_RES_INVALID_OBJECT;
    fm_result_t  ret_norm = FM_RES_INT_ERR;
    fm_result_t  ret_free = FM_RES_INT_ERR;
    volume_t    *p_vol;
    char         norm_path[FM_MAX_PATH] = { 0 };
    fm_header_t *p_header;

    ret = ret_norm = get_volume_and_normalize_path(p_in_path, norm_path, &p_vol);
    if (FM_RES_OK == ret_norm)
    {
        ret = ret_free = get_free_file_object(p_vol, &p_header);
    }
    else
    {
        ES_TRACE_INFO("Could not resolve path '%.*s', error %d '%s'", FM_MAX_PATH, p_in_path == NULL ? "(NULL)" : p_in_path, ret, fm_result_to_str(ret));
    }

    if (FM_RES_OK == ret_free)
    {
        ret = p_vol->p_fs_api->open(p_vol->fs_obj, get_file_obj(p_header), norm_path, mode);
        if (FM_RES_OK == ret)
        {
            p_header->type = HANDLE_TYPE_FILE;
            *p_out_handle  = (fm_handle_t)p_header;
            ES_TRACE_DEBUG("Successfully opened \"%s\", handle: %p", norm_path, *p_out_handle);
        }
        else
        {
            ES_TRACE_INFO("Could not open path '%s', error %d '%s'", norm_path, ret, fm_result_to_str(ret));
            (void)release_index(p_header->p_index);
        }
        update_stats(ret);
    }
    return ret;
}

bool fm_is_open(c_fm_handle_t handle)
{
    return is_handle_in_index_list(handle);
}

fm_result_t fm_close(fm_handle_t handle)
{
    fm_result_t ret = FM_RES_INVALID_OBJECT;
    if (true == is_valid_handle(handle, HANDLE_TYPE_FILE))
    {
        ES_TRACE_DEBUG("Closing handle: %p", handle);
        ret = release_handle(handle);
        update_stats(ret);
    }
    else
    {
        ES_TRACE_INFO("Error attempt to close invalid handle: %p", handle);
    }
    return ret;
}

fm_result_t fm_gets(
    fm_handle_t    handle,
    void *const    p_out_buff,
    const uint32_t buffer_size)
{
    fm_result_t ret = FM_RES_INVALID_OBJECT;
    if (NULL == p_out_buff)
    {
        return FM_RES_INVALID_PARAMETER;
    }
    if (true == is_valid_handle(handle, HANDLE_TYPE_FILE))
    {
        fm_header_t *const p_header = (fm_header_t *)handle;
        volume_t *const    p_vol    = p_header->p_volume;
        ret                         = p_vol->p_fs_api->xgets(p_vol->fs_obj, get_file_obj(p_header), p_out_buff, buffer_size);
        update_stats(ret);
    }
    return ret;
}

fm_result_t fm_read(fm_handle_t handle, void *const p_out_buff, const uint32_t bytes_to_read, uint32_t *const p_out_bytes_read)
{
    fm_result_t        ret      = FM_RES_INVALID_OBJECT;
    fm_header_t *const p_header = (fm_header_t *)handle;
    if (NULL == p_out_buff)
    {
        return FM_RES_INVALID_PARAMETER;
    }
    if (true == is_valid_handle(handle, HANDLE_TYPE_FILE))
    {
        volume_t *const p_vol = p_header->p_volume;
        uint32_t        safe_bytes_read;
        ret = p_vol->p_fs_api->read(p_vol->fs_obj, get_file_obj(p_header), p_out_buff, bytes_to_read, &safe_bytes_read);
        if ((FM_RES_OK == ret) && (NULL != p_out_bytes_read))
        {
            *p_out_bytes_read = safe_bytes_read;
        }
        else
        {
            ES_TRACE_INFO("Could not read handle %p, error %d '%s'", handle, ret, fm_result_to_str(ret));
        }
        update_stats(ret);
    }
    else
    {
        ES_TRACE_INFO("Error attempt to read invalid handle: %p", handle);
    }

    return ret;
}

fm_result_t fm_read_at_pos(fm_handle_t handle, void *const p_out_buff, const uint32_t bytes_to_read, uint32_t *const p_out_bytes_read, const uint32_t pos)
{
    fm_result_t ret = FM_RES_INVALID_OBJECT;
    if (NULL == p_out_buff)
    {
        return FM_RES_INVALID_PARAMETER;
    }
    if (true == is_valid_handle(handle, HANDLE_TYPE_FILE))
    {
        fm_header_t *const p_header = (fm_header_t *)handle;
        volume_t *const    p_vol    = p_header->p_volume;
        ret                         = p_vol->p_fs_api->seek(p_vol->fs_obj, get_file_obj(p_header), pos);
        if (FM_RES_OK == ret)
        {
            uint32_t safe_bytes_read;
            ret = p_vol->p_fs_api->read(p_vol->fs_obj, get_file_obj(p_header), p_out_buff, bytes_to_read, &safe_bytes_read);
            if ((FM_RES_OK == ret) && (NULL != p_out_bytes_read))
            {
                *p_out_bytes_read = safe_bytes_read;
            }
            else
            {
                ES_TRACE_INFO("Could not read at pos %u handle %p, error %d '%s'", pos, handle, ret, fm_result_to_str(ret));
            }
        }
        else
        {
            ES_TRACE_INFO("Could not seek to pos %u handle %p, error %d '%s'", pos, handle, ret, fm_result_to_str(ret));
        }
        update_stats(ret);
    }
    else
    {
        ES_TRACE_INFO("Error attempt to read at pos invalid handle: %p", handle);
    }
    return ret;
}

fm_result_t fm_write(fm_handle_t handle, const void *p_in_buff, const uint32_t bytes_to_write, uint32_t *const p_out_bytes_written)
{
    fm_result_t ret = FM_RES_INVALID_OBJECT;
    if (NULL == p_in_buff)
    {
        return FM_RES_INVALID_PARAMETER;
    }
    if (true == is_valid_handle(handle, HANDLE_TYPE_FILE))
    {
        fm_header_t *const p_header = (fm_header_t *)handle;
        volume_t *const    p_vol    = p_header->p_volume;
        uint32_t           safe_bytes_written;

        ret = p_vol->p_fs_api->write(p_vol->fs_obj, get_file_obj(p_header), p_in_buff, bytes_to_write, &safe_bytes_written);
        if (FM_RES_OK == ret)
        {
            if (NULL != p_out_bytes_written)
            {
                *p_out_bytes_written = safe_bytes_written;
            }
        }
        else
        {
            ES_TRACE_INFO("Could not write with handle %p, error %d '%s'", handle, ret, fm_result_to_str(ret));
        }
        update_stats(ret);
    }
    else
    {
        ES_TRACE_INFO("Error attempt to write with invalid handle: %p", handle);
    }
    return ret;
}

fm_result_t fm_write_at_pos(fm_handle_t handle, const void *const p_in_buff, const uint32_t bytes_to_write, uint32_t *const p_out_bytes_written, const uint32_t pos)
{
    fm_result_t ret = FM_RES_INVALID_OBJECT;
    if (NULL == p_in_buff)
    {
        return FM_RES_INVALID_PARAMETER;
    }
    if (true == is_valid_handle(handle, HANDLE_TYPE_FILE))
    {
        fm_header_t *const p_header = (fm_header_t *)handle;
        volume_t *const    p_vol    = p_header->p_volume;

        ret = p_vol->p_fs_api->seek(p_vol->fs_obj, get_file_obj(p_header), pos);
        if (FM_RES_OK == ret)
        {
            uint32_t safe_bytes_written;
            ret = p_vol->p_fs_api->write(p_vol->fs_obj, get_file_obj(p_header), p_in_buff, bytes_to_write, &safe_bytes_written);
            if ((FM_RES_OK == ret) && (NULL != p_out_bytes_written))
            {
                *p_out_bytes_written = safe_bytes_written;
            }
            else
            {
                ES_TRACE_INFO("Could not write with handle %p, error %d '%s'", handle, ret, fm_result_to_str(ret));
            }
        }
        else
        {
            ES_TRACE_INFO("Could not seek to pos %u handle %p, error %d '%s'", pos, handle, ret, fm_result_to_str(ret));
        }
        update_stats(ret);
    }
    else
    {
        ES_TRACE_INFO("Error attempt to write with invalid handle: %p", handle);
    }

    return ret;
}

fm_result_t fm_printf(fm_handle_t handle, uint32_t *const p_out_bytes_written, const char *const p_in_fmt, ...)
{
    fm_result_t ret = FM_RES_INVALID_OBJECT;
    if (NULL == p_in_fmt)
    {
        return FM_RES_INVALID_PARAMETER;
    }
    if (true == is_valid_handle(handle, HANDLE_TYPE_FILE))
    {
        fm_header_t *const p_header = (fm_header_t *)handle;
        volume_t *const    p_vol    = p_header->p_volume;
        uint32_t           safe_bytes_written;
        va_list            ap;
        va_start(ap, p_in_fmt);
        ret = p_vol->p_fs_api->vprintf(p_vol->fs_obj, get_file_obj(p_header), &safe_bytes_written, p_in_fmt, ap);
        va_end(ap);
        if ((FM_RES_OK == ret) && (NULL != p_out_bytes_written))
        {
            *p_out_bytes_written = safe_bytes_written;
        }
        else if (FM_RES_INVALID_OBJECT == ret)
        {
            (void)release_handle(handle);
        }
        else
        {
            // do nothing
        }
        update_stats(ret);
    }
    else
    {
        ES_TRACE_INFO("Error attempt to printf with invalid handle: %p", handle);
    }

    return ret;
}

fm_result_t fm_vprintf(fm_handle_t handle, uint32_t *const p_out_bytes_written, const char *const p_in_fmt, va_list ap)
{
    fm_result_t ret = FM_RES_INVALID_OBJECT;
    if (NULL == p_in_fmt)
    {
        return FM_RES_INVALID_PARAMETER;
    }
    if (true == is_valid_handle(handle, HANDLE_TYPE_FILE))
    {
        fm_header_t *const p_header = (fm_header_t *)handle;
        volume_t *const    p_vol    = p_header->p_volume;
        uint32_t           safe_bytes_written;
        ret = p_vol->p_fs_api->vprintf(p_vol->fs_obj, get_file_obj(p_header), &safe_bytes_written, p_in_fmt, ap);
        if ((FM_RES_OK == ret) && (NULL != p_out_bytes_written))
        {
            *p_out_bytes_written = safe_bytes_written;
        }
        else if (FM_RES_INVALID_OBJECT == ret)
        {
            (void)release_handle(handle);
        }
        else
        {
            // do nothing
        }
        update_stats(ret);
    }
    else
    {
        ES_TRACE_INFO("Error attempt to vprintf with invalid handle: %p", handle);
    }

    return ret;
}

fm_result_t fm_truncate(fm_handle_t handle, const uint32_t pos)
{
    fm_result_t ret = FM_RES_INVALID_OBJECT;
    if (true == is_valid_handle(handle, HANDLE_TYPE_FILE))
    {
        fm_header_t *const p_header = (fm_header_t *)handle;
        volume_t *const    p_vol    = p_header->p_volume;
        ret                         = p_vol->p_fs_api->seek(p_vol->fs_obj, get_file_obj(p_header), pos);
        if (FM_RES_INVALID_OBJECT == ret)
        {
            (void)release_handle(handle);
        }
        else if (FM_RES_OK == ret)
        {
            ret = p_vol->p_fs_api->truncate(p_vol->fs_obj, get_file_obj(p_header));
            if (FM_RES_INVALID_OBJECT == ret)
            {
                (void)release_handle(handle);
            }
        }
        else
        {
            // do nothing
        }
        update_stats(ret);
    }
    else
    {
        ES_TRACE_INFO("Error attempt to truncate with invalid handle: %p", handle);
    }

    return ret;
}

fm_result_t fm_size(fm_handle_t handle, uint32_t *const p_out_size)
{
    fm_result_t ret = FM_RES_INVALID_OBJECT;
    if (NULL == p_out_size)
    {
        return FM_RES_INVALID_PARAMETER;
    }
    if (true == is_valid_handle(handle, HANDLE_TYPE_FILE))
    {
        fm_header_t *const p_header = (fm_header_t *)handle;
        volume_t *const    p_vol    = p_header->p_volume;
        ret                         = p_vol->p_fs_api->size(p_vol->fs_obj, get_file_obj(p_header), p_out_size);
        if (FM_RES_INVALID_OBJECT == ret)
        {
            (void)release_handle(handle);
        }
        update_stats(ret);
    }
    return ret;
}

fm_result_t fm_tell(fm_handle_t handle, uint32_t *const p_out_pos)
{
    fm_result_t ret = FM_RES_INVALID_OBJECT;
    if (NULL == p_out_pos)
    {
        return FM_RES_INVALID_PARAMETER;
    }
    if (true == is_valid_handle(handle, HANDLE_TYPE_FILE))
    {
        fm_header_t *const p_header = (fm_header_t *)handle;
        volume_t *const    p_vol    = p_header->p_volume;
        ret                         = p_vol->p_fs_api->tell(p_vol->fs_obj, get_file_obj(p_header), p_out_pos);
        if (FM_RES_INVALID_OBJECT == ret)
        {
            (void)release_handle(handle);
        }
        update_stats(ret);
    }
    return ret;
}

fm_result_t fm_seek(fm_handle_t handle, const uint32_t pos)
{
    fm_result_t ret = FM_RES_INVALID_OBJECT;
    if (true == is_valid_handle(handle, HANDLE_TYPE_FILE))
    {
        fm_header_t *const p_header = (fm_header_t *)handle;
        volume_t *const    p_vol    = p_header->p_volume;
        ret                         = p_vol->p_fs_api->seek(p_vol->fs_obj, get_file_obj(p_header), pos);
        if (FM_RES_INVALID_OBJECT == ret)
        {
            (void)release_handle(handle);
        }
        update_stats(ret);
    }
    return ret;
}

fm_result_t fm_sync(fm_handle_t handle)
{
    fm_result_t ret = FM_RES_INVALID_OBJECT;
    if (true == is_valid_handle(handle, HANDLE_TYPE_FILE))
    {
        fm_header_t *const p_header = (fm_header_t *)handle;
        volume_t *const    p_vol    = p_header->p_volume;
        ret                         = p_vol->p_fs_api->sync(p_vol->fs_obj, get_file_obj(p_header));
        if (FM_RES_INVALID_OBJECT == ret)
        {
            (void)release_handle(handle);
        }
        update_stats(ret);
    }
    return ret;
}

fm_result_t fm_stat(const char *const p_in_path, fm_fast_file_info_t *const p_out_tfi)
{
    fm_result_t ret = FM_RES_INT_ERR;
    volume_t   *p_vol;
    char        norm_path[FM_MAX_PATH] = { 0 };
    ret                                = get_volume_and_normalize_path(p_in_path, norm_path, &p_vol);
    if (FM_RES_OK == ret)
    {
        if (NULL != p_out_tfi)
        {
            ret = p_vol->p_fs_api->stat(p_vol->fs_obj, norm_path, p_out_tfi);
        }
        else
        {
            fm_fast_file_info_t ffi;
            ret = p_vol->p_fs_api->stat(p_vol->fs_obj, norm_path, &ffi);
        }
        update_stats(ret);
    }
    return ret;
}

fm_result_t fm_crc(const char *const p_in_path, uint32_t *const p_out_crc)
{
    fm_result_t  ret      = FM_RES_INT_ERR;
    fm_result_t  ret_norm = FM_RES_INT_ERR;
    fm_result_t  ret_free = FM_RES_INT_ERR;
    volume_t    *p_vol;
    char         norm_path[FM_MAX_PATH] = { 0 };
    fm_header_t *p_header;

    if (NULL == p_out_crc)
    {
        return FM_RES_INVALID_PARAMETER;
    }

    ret = ret_norm = get_volume_and_normalize_path(p_in_path, norm_path, &p_vol);
    if (FM_RES_OK == ret_norm)
    {
        ret = ret_free = get_free_file_object(p_vol, &p_header);
    }

    if (FM_RES_OK == ret_free)
    {
        ret = p_vol->p_fs_api->open(p_vol->fs_obj, get_file_obj(p_header), norm_path, FM_MODE_OPEN_EXISTING | FM_MODE_READ);
        if (FM_RES_OK == ret)
        {
            p_header->type = HANDLE_TYPE_FILE;
            ret            = crc_opened_file(p_vol, p_header, p_out_crc);
            (void)release_index(p_header->p_index);
        }
        update_stats(ret);
    }
    return ret;
}

fm_result_t fm_rename(const char *const p_in_path_old, const char *const p_in_path_new)
{
    fm_result_t ret     = FM_RES_INT_ERR;
    fm_result_t ret_old = FM_RES_INT_ERR;
    fm_result_t ret_new = FM_RES_INT_ERR;
    volume_t   *p_vol_old;
    volume_t   *p_vol_new;
    char        norm_path_old[FM_MAX_PATH] = { 0 };
    char        norm_path_new[FM_MAX_PATH] = { 0 };

    ret = ret_old = get_volume_and_normalize_path(p_in_path_old, norm_path_old, &p_vol_old);
    if (FM_RES_OK == ret_old)
    {
        ret = ret_new = get_volume_and_normalize_path(p_in_path_new, norm_path_new, &p_vol_new);
    }

    if (FM_RES_OK == ret_new)
    {
        if (p_vol_old == p_vol_new)
        {
            ret = p_vol_old->p_fs_api->rename(p_vol_old->fs_obj, norm_path_old, norm_path_new);
        }
        else
        {
            ret = FM_RES_DENIED;
        }
        update_stats(ret);
    }
    return ret;
}

fm_result_t fm_delete(const char *const p_in_path)
{
    fm_result_t ret = FM_RES_INT_ERR;
    volume_t   *p_vol;
    char        norm_path[FM_MAX_PATH] = { 0 };

    ret = get_volume_and_normalize_path(p_in_path, norm_path, &p_vol);
    if (FM_RES_OK == ret)
    {
        ret = p_vol->p_fs_api->delete (p_vol->fs_obj, norm_path);
        update_stats(ret);
    }
    return ret;
}

fm_result_t fm_mkdir(const char *const p_in_path)
{
    fm_result_t ret = FM_RES_INT_ERR;
    volume_t   *p_vol;
    char        norm_path[FM_MAX_PATH] = { 0 };
    ret                                = get_volume_and_normalize_path(p_in_path, norm_path, &p_vol);
    if (FM_RES_OK == ret)
    {
        ret = p_vol->p_fs_api->mkdir(p_vol->fs_obj, norm_path);
        update_stats(ret);
    }
    return ret;
}

fm_result_t fm_list(const char *const p_in_path, const char *const p_in_glob)
{
    fm_result_t       ret      = FM_RES_INT_ERR;
    fm_result_t       ret_norm = FM_RES_INT_ERR;
    fm_result_t       ret_free = FM_RES_INT_ERR;
    const char *const p_glob   = (NULL != p_in_glob) ? p_in_glob : MATCH_ALL;
    volume_t         *p_vol;
    fm_header_t      *p_header;
    char              norm_path[FM_MAX_PATH] = { 0 };

    ret = ret_norm = get_volume_and_normalize_path(p_in_path, norm_path, &p_vol);
    if (FM_RES_OK == ret_norm)
    {
        ret = ret_free = get_free_file_object(p_vol, &p_header);
    }

    if (FM_RES_OK == ret_free)
    {
        handle_obj_t handle = get_file_obj(p_header);
        ret                 = p_vol->p_fs_api->open(p_vol->fs_obj, handle, norm_path, FM_MODE_WRITE | FM_MODE_CREATE_ALWAYS);

        if (FM_RES_OK == ret)
        {
            p_header->type = HANDLE_TYPE_FILE;
            ret            = p_vol->p_fs_api->xprintf(p_vol->fs_obj, handle, NULL, "file_name,size(in bytes),attributes,timestamp\n");
            if (FM_RES_OK == ret)
            {
                list_handler_data_t lhd = { .p_vol = p_vol, .handle = handle };
                ret                     = foreach_stack(p_vol, "", p_glob, &file_list_handler, &lhd);
            }

            (void)release_index(p_header->p_index);

            if (FM_RES_OK != ret)
            {
                (void)p_vol->p_fs_api->delete (p_vol->fs_obj, norm_path);
            }
        }
        update_stats(ret);
    }
    return ret;
}

fm_result_t fm_foreach_flat(const char *p_in_path, const char *const p_in_glob, const fm_foreach_handler_t handler, void *const p_inout_user_data)
{
    fm_result_t       ret = FM_RES_INT_ERR;
    volume_t         *p_vol;
    const char *const p_glob                 = (NULL != p_in_glob) ? p_in_glob : MATCH_ALL;
    char              norm_path[FM_MAX_PATH] = { 0 };

    if (NULL == handler)
    {
        return FM_RES_INVALID_PARAMETER;
    }

    ret = get_volume_and_normalize_path(p_in_path, norm_path, &p_vol);
    if (FM_RES_OK == ret)
    {
        ret = p_vol->p_fs_api->foreach_flat(p_vol->fs_obj, norm_path, p_glob, handler, p_inout_user_data);
        update_stats(ret);
    }
    return ret;
}

fm_result_t fm_foreach(
    const char *const          p_in_path,
    const char *const          p_in_glob,
    const fm_foreach_handler_t handler,
    void *const                p_inout_user_data)
{
    fm_result_t       ret = FM_RES_INT_ERR;
    volume_t         *p_vol;
    const char *const p_glob                 = (NULL != p_in_glob) ? p_in_glob : MATCH_ALL;
    char              norm_path[FM_MAX_PATH] = { 0 };

    if (NULL == handler)
    {
        return FM_RES_INVALID_PARAMETER;
    }

    ret = get_volume_and_normalize_path(p_in_path, norm_path, &p_vol);
    if (FM_RES_OK == ret)
    {
        ret = foreach_stack(p_vol, norm_path, p_glob, handler, p_inout_user_data);
        update_stats(ret);
    }
    return ret;
}

fm_result_t fm_dir_open(fm_dir_handle_t const dir_handle, const char *p_in_path, const char *const p_in_glob)
{
    fm_result_t       ret                     = FM_RES_INVALID_OBJECT;
    fm_result_t       ret_norm                = FM_RES_INT_ERR;
    fm_result_t       ret_free                = FM_RES_INT_ERR;
    const char *const p_glob                  = (NULL != p_in_glob) ? p_in_glob : MATCH_ALL;
    bool              handle_is_in_index_list = false;
    volume_t         *p_vol;
    char              norm_path[FM_MAX_PATH] = { 0 };
    fm_header_t      *p_header;

    handle_is_in_index_list = is_handle_in_index_list((fm_handle_t)dir_handle);
    if (false == handle_is_in_index_list)
    {
        ret = ret_norm = get_volume_and_normalize_path(p_in_path, norm_path, &p_vol);
    }
    p_header = (fm_header_t *)dir_handle;
    if (FM_RES_OK == ret_norm)
    {
        ret = ret_free = get_free_index(p_vol, p_header);
    }

    if (FM_RES_OK == ret_free)
    {
        ret = p_vol->p_fs_api->dir_open(p_vol->fs_obj, get_file_obj(p_header), norm_path, p_glob);
        if (FM_RES_OK == ret)
        {
            p_header->type = HANDLE_TYPE_DIR;
        }
        else
        {
            (void)release_index(p_header->p_index);
        }
        update_stats(ret);
    }
    return ret;
}

fm_result_t fm_dir_open_internal(fm_dir_handle_t *const p_out_dir_handle, const char *p_in_path, const char *const p_in_glob)
{
    fm_result_t  ret      = FM_RES_INVALID_OBJECT;
    fm_result_t  ret_norm = FM_RES_INT_ERR;
    fm_result_t  ret_free = FM_RES_INT_ERR;
    volume_t    *p_vol;
    char         norm_path[FM_MAX_PATH] = { 0 };
    fm_header_t *p_header;

    ret = ret_norm = get_volume_and_normalize_path(p_in_path, norm_path, &p_vol);
    if (FM_RES_OK == ret_norm)
    {
        ret = ret_free = get_free_file_object(p_vol, &p_header);
    }

    if (FM_RES_OK == ret_free)
    {
        ret = p_vol->p_fs_api->dir_open(p_vol->fs_obj, get_file_obj(p_header), norm_path, p_in_glob);
        if (FM_RES_OK == ret)
        {
            p_header->type    = HANDLE_TYPE_DIR;
            *p_out_dir_handle = (fm_dir_handle_t)p_header;
        }
        else
        {
            (void)release_index(p_header->p_index);
        }
        update_stats(ret);
    }
    return ret;
}

fm_result_t fm_dir_next(fm_dir_handle_t handle, fm_file_info_t *const p_out_ffi)
{
    fm_result_t ret = FM_RES_INT_ERR;

    if (NULL == p_out_ffi)
    {
        return FM_RES_INVALID_PARAMETER;
    }

    if (true == is_valid_handle((fm_handle_t)handle, HANDLE_TYPE_DIR))
    {
        fm_header_t *const p_header = (fm_header_t *)handle;
        volume_t *const    p_vol    = p_header->p_volume;
        ret                         = p_vol->p_fs_api->dir_next(p_vol->fs_obj, get_file_obj(p_header), p_out_ffi);
        update_stats(ret);
    }
    else
    {
        ret = FM_RES_INVALID_OBJECT;
    }
    return ret;
}

fm_result_t fm_dir_close(fm_dir_handle_t handle)
{
    fm_result_t ret = FM_RES_INVALID_OBJECT;
    if (true == is_valid_handle((fm_handle_t)handle, HANDLE_TYPE_DIR))
    {
        fm_header_t *const p_header = (fm_header_t *)handle;
        ret                         = release_index(p_header->p_index);
        update_stats(ret);
    }
    return ret;
}

fm_result_t fm_format(const char *const p_in_path)
{
    fm_result_t ret = FM_RES_INT_ERR;
    volume_t   *p_vol;
    ret = get_volume_from_path(p_in_path, &p_vol);
    if (FM_RES_OK == ret)
    {
        release_index_by_volume(p_vol);
        ret = p_vol->p_fs_api->format(p_vol->fs_obj);
        update_stats(ret);
    }
    return ret;
}

fm_result_t fm_get_handle_count(const char *const p_in_path, uint32_t *const p_out_count)
{
    fm_result_t ret   = FM_RES_INT_ERR;
    volume_t   *p_vol = NULL;

    if (NULL != p_out_count)
    {
        // we will use NULL to mean all the volumes, see get_opened_handle_count
        if (NULL != p_in_path)
        {
            ret = get_volume_from_path(p_in_path, &p_vol);
        }
        else
        {
            ret   = FM_RES_OK;
            p_vol = NULL;
        }
    }
    else
    {
        ret = FM_RES_INVALID_PARAMETER;
    }

    if (FM_RES_OK == ret)
    {
        *p_out_count = get_opened_handle_count(p_vol);
    }
    update_stats(ret);
    return ret;
}

fm_result_t fm_get_free(const char *const p_in_path, uint32_t *const p_out_kb_size)
{
    fm_result_t ret = FM_RES_INT_ERR;
    volume_t   *p_vol;
    if (NULL != p_out_kb_size)
    {
        ret = get_volume_from_path(p_in_path, &p_vol);
        if (FM_RES_OK == ret)
        {
            ret = p_vol->p_fs_api->get_free(p_vol->fs_obj, p_out_kb_size);
            update_stats(ret);
        }
    }
    else
    {
        ret = FM_RES_INVALID_PARAMETER;
    }
    return ret;
}

fm_result_t fm_get_stat_by_id(const fm_result_t id, uint16_t *const p_out_stat)
{
    fm_result_t ret = FM_RES_INT_ERR;
    if (NULL != p_out_stat)
    {
        ret = FM_RES_INVALID_PARAMETER;
        if (FM_RES_INVALID_PARAMETER >= id)
        {
            taskENTER_CRITICAL();
            *p_out_stat = fm_stats.api_err_counters[id];
            taskEXIT_CRITICAL();
            ret = FM_RES_OK;
        }
    }
    else
    {
        ret = FM_RES_INVALID_PARAMETER;
    }
    return ret;
}

fm_result_t fm_clear_stats(void)
{
    taskENTER_CRITICAL();
    memset(&fm_stats.api_err_counters, 0, sizeof(fm_stats.api_err_counters));
    should_store_stats = true;
    taskEXIT_CRITICAL();
    return FM_RES_OK;
}

fm_result_t fm_storage_init(const char *const p_in_path, const uint32_t timeout, fm_storage_status_t *const p_out_status)
{
    fm_result_t ret;
    volume_t   *p_vol;
    ret = get_volume_from_path(p_in_path, &p_vol);
    if (FM_RES_OK == ret)
    {
        fm_storage_status_t status;
        release_index_by_volume(p_vol);
        status = p_vol->p_drv_api->storage_init(timeout);
        if (NULL != p_out_status)
        {
            *p_out_status = status;
        }
    }
    return ret;
}

fm_result_t fm_storage_status(const char *const p_in_path, fm_storage_status_t *const p_out_status)
{
    fm_result_t ret = FM_RES_INT_ERR;
    volume_t   *p_vol;
    if (NULL != p_out_status)
    {
        ret = get_volume_from_path(p_in_path, &p_vol);
        if (FM_RES_OK == ret)
        {
            *p_out_status = p_vol->p_drv_api->storage_status();
        }
    }
    else
    {
        ret = FM_RES_INVALID_PARAMETER;
    }
    return ret;
}

bool fm_storage_status_ready(const char *const p_in_path)
{
    fm_storage_status_t status;
    if (FM_RES_OK == fm_storage_status(p_in_path, &status))
    {
        return (STORAGE_STATUS_READY == status);
    }
    return false;
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

static inline const char *getcstr_mount_action(const mount_action_t mount)
{
    switch (mount)
    {
        case NOMOUNT:
            return "NOMOUNT";
        case MOUNT:
            return "MOUNT";
        case UMOUNT:
            return "UMOUNT";
        default:;
    }
    return "MOUNT_???";
}

static inline const char *getcstr_storage_status(const fm_storage_status_t status)
{
    switch (status)
    {
        case STORAGE_STATUS_ERROR:
            return "STORAGE_ERROR";
        case STORAGE_STATUS_EJECTED:
            return "STORAGE_EJECTED";
        case STORAGE_STATUS_NOT_INIT:
            return "STORAGE_NOT_INIT";
        case STORAGE_STATUS_INITIALIZING:
            return "STORAGE_INITIALIZING";
        case STORAGE_STATUS_BUSY:
            return "STORAGE_BUSY";
        case STORAGE_STATUS_READY:
            return "STORAGE_READY";
        default:;
    }
    return "STORAGE_???";
}

static inline void fm_lock(void)
{
    osMutexAcquire(fm_mutex, osWaitForever);
}

static inline void fm_unlock(void)
{
    osMutexRelease(fm_mutex);
}

static inline bool is_char_path_delimiter(char ch)
{
    return ((PATH_DELIMITER_CHAR == ch) || (PATH_DELIMITER_ALT_CHAR == ch));
}

static inline bool is_char_path_delimiter_or_zero(char ch)
{
    return (is_char_path_delimiter(ch) || (TERMINATING_ZERO_CHAR == ch));
}

static inline bool is_char_path_valid(const char ch)
{
    return ((ASCII_DELETE_CHAR > ch) && (ASCII_SPACE_CHAR <= ch) && (NULL == strchr(FM_FORBIDDEN_CHARS, ch)));
}

static bool skip_path_delimiter(const char **ret_path, size_t max_chars)
{
    const char *s;
    const char *end;
    s   = *ret_path;
    end = &s[max_chars];
    while ((true == is_char_path_delimiter(*s)) && (end > s))
    {
        ++s;
    }
    *ret_path = s;
    return (s < end);
}

static fm_result_t normalize_path(const char *const p_in_source, char *const p_out_destination)
{
    const char *p_src;
    const char *p_src_max;
    char       *p_dst;
    bool        delim;
    fm_result_t ret = FM_RES_OK;

    p_src     = p_in_source;
    p_src_max = &p_in_source[FM_MAX_PATH - 1];
    p_dst     = p_out_destination;
    delim     = false;

    if (false == skip_path_delimiter(&p_src, FM_MAX_PATH - 1))
    {
        return FM_RES_INVALID_NAME;
    }

    while ((TERMINATING_ZERO_CHAR != *p_src) && (p_src < p_src_max))
    {
        char ch = *p_src;
        if (true == is_char_path_delimiter(ch))
        {
            if (false == delim)
            {
                *p_dst++ = PATH_DELIMITER_CHAR;
                delim    = true;
            }
        }
        else if (true == is_char_path_valid(ch))
        {
            delim    = false;
            *p_dst++ = ch;
        }
        else
        {
            break;
        }
        ++p_src;
    }

    if (TERMINATING_ZERO_CHAR == *p_src)
    {
        *p_dst = TERMINATING_ZERO_CHAR;

        // remove trailing delimiter, skip if destination is an empty string
        if (p_out_destination != p_dst)
        {
            --p_dst;
            if (true == is_char_path_delimiter(*p_dst))
            {
                *p_dst = TERMINATING_ZERO_CHAR;
            }
        }
    }
    else
    {
        ret = FM_RES_INVALID_NAME;
    }

    return ret;
}

static fm_result_t get_default_volume(volume_t **p_out_p_volume)
{
    if ((NULL != p_default_volume) && (NULL != p_default_volume->p_fs_api) && (NULL != p_default_volume->p_drv_api))
    {
        *p_out_p_volume = p_default_volume;
        return FM_RES_OK;
    }
    return FM_RES_INVALID_DRIVE;
}

static fm_result_t find_volume(const char **p_inout_p_path, volume_t **p_out_p_vol)
{
    for (size_t i = 0; i < CDEF_ELEMENT_COUNT(volume_list); i++)
    {
        volume_t *p_vol = &volume_list[i];
        if ((NULL != p_vol->p_fs_api) && (NULL != p_vol->fs_obj) && (0 == strncmp(*p_inout_p_path, p_vol->name, p_vol->namelen)) && (is_char_path_delimiter_or_zero((*p_inout_p_path)[p_vol->namelen])))
        {
            *p_inout_p_path = &(*p_inout_p_path)[p_vol->namelen];
            if (false == skip_path_delimiter(p_inout_p_path, FM_MAX_DELIMITER))
            {
                return FM_RES_INVALID_NAME;
            }
            *p_out_p_vol = p_vol;
            return FM_RES_OK;
        }
    }
    return FM_RES_INVALID_DRIVE;
}

static fm_result_t get_volume_and_normalize_path(
    const char *const p_in_path,
    char *const       p_out_normal_path,
    volume_t        **p_out_p_vol)
{
    fm_result_t ret;
    const char *p_work_path = p_in_path;
    ret                     = adjust_path_and_get_volume(&p_work_path, p_out_p_vol);
    if (FM_RES_OK == ret)
    {
        ret = normalize_path(p_work_path, p_out_normal_path);
    }
    return ret;
}

static fm_result_t get_volume_from_path(const char *const p_in_path, volume_t **p_out_p_vol)
{
    fm_result_t ret = FM_RES_INT_ERR;
    const char *work_path;

    if ((NULL == p_in_path) || (NULL == p_out_p_vol))
    {
        return FM_RES_INVALID_PARAMETER;
    }

    work_path = p_in_path;

    if (false == skip_path_delimiter(&work_path, FM_MAX_DELIMITER))
    {
        return FM_RES_INVALID_NAME;
    }

    if (TERMINATING_ZERO_CHAR == *work_path)
    {
        return get_default_volume(p_out_p_vol);
    }

    if (p_in_path == work_path)
    {
        return FM_RES_INVALID_DRIVE;
    }
    else
    {
        volume_t *p_temp_vol;
        ret = find_volume(&work_path, &p_temp_vol);

        if (FM_RES_OK == ret)
        {
            if (TERMINATING_ZERO_CHAR != *work_path)
            {
                ret = FM_RES_INVALID_NAME;
            }
            else
            {
                *p_out_p_vol = p_temp_vol;
            }
        }
    }

    return ret;
}

static fm_result_t adjust_path_and_get_volume(const char **const p_out_p_path, volume_t **p_out_p_vol)
{
    fm_result_t ret = FM_RES_INT_ERR;
    const char *work_path;

    if ((NULL == p_out_p_path) || (NULL == *p_out_p_path) || (NULL == p_out_p_vol))
    {
        return FM_RES_INVALID_PARAMETER;
    }

    work_path = *p_out_p_path;

    if (false == skip_path_delimiter(&work_path, FM_MAX_DELIMITER))
    {
        return FM_RES_INVALID_NAME;
    }

    if (TERMINATING_ZERO_CHAR == *work_path)
    {
        return get_default_volume(p_out_p_vol);
    }

    if (*p_out_p_path == work_path)
    {
        return get_default_volume(p_out_p_vol);
    }
    else
    {
        volume_t *p_temp_vol;
        ret = find_volume(&work_path, &p_temp_vol);

        if (FM_RES_OK == ret)
        {
            *p_out_p_path = work_path;
            *p_out_p_vol  = p_temp_vol;
        }
    }

    return ret;
}

static fm_result_t get_free_index_without_lock(volume_t *const p_in_vol, fm_header_t *const p_inout_header)
{
    fm_result_t ret     = FM_RES_TOO_MANY_OPEN_FILES;
    fm_index_t *p_index = p_in_vol->index_list;
    for (size_t i = 0; i < p_in_vol->index_list_count; i++, p_index++)
    {
        if (NULL == *p_index)
        {
            *p_index                 = p_inout_header;
            p_inout_header->p_index  = p_index;
            p_inout_header->p_volume = p_in_vol;
            p_inout_header->type     = HANDLE_TYPE_EMPTY;

            ret = FM_RES_OK;
            break;
        }
    }
    return ret;
}

static fm_result_t get_free_index(volume_t *const p_in_vol, fm_header_t *const p_inout_file)
{
    fm_result_t ret = FM_RES_TOO_MANY_OPEN_FILES;
    fm_lock();
    ret = get_free_index_without_lock(p_in_vol, p_inout_file);
    fm_unlock();
    return ret;
}

static fm_result_t get_free_file_object(volume_t *const p_in_vol, fm_header_t **const p_out_p_header)
{
    fm_result_t ret = FM_RES_TOO_MANY_OPEN_FILES;
    fm_lock();
    fm_header_t **p_iter_header = p_in_vol->header_list;
    for (size_t i = 0; i < p_in_vol->header_list_count; i++, p_iter_header++)
    {
        fm_header_t *p_header = *p_iter_header;
        if (NULL == p_header->p_index)
        {
            if (FM_RES_OK == get_free_index_without_lock(p_in_vol, p_header))
            {
                *p_out_p_header = p_header;
                ret             = FM_RES_OK;
            }
            break;
        }
    }
    fm_unlock();
    return ret;
}

static bool is_handle_in_index_list(c_fm_handle_t handle)
{
    bool                     ret      = false;
    const fm_header_t *const p_header = (const fm_header_t *)handle;
    if (NULL == handle)
    {
        return false;
    }
    fm_lock();
    const volume_t *p_vol             = volume_list;
    size_t          volume_list_count = CDEF_ELEMENT_COUNT(volume_list);
    for (size_t i = 0; i < volume_list_count; i++, p_vol++)
    {
        const fm_index_t *p_index = p_vol->index_list;
        for (size_t j = 0; j < p_vol->index_list_count; j++, p_index++)
        {
            if (p_header == *p_index)
            {
                ret = true;
            }
        }
    }
    fm_unlock();
    return ret;
}

static bool is_valid_handle(c_fm_handle_t handle, const handle_type_t type)
{
    const fm_header_t *const p_header = (const fm_header_t *)handle;
    bool                     ret      = false;
    fm_lock();
    if ((NULL != p_header) && (type == p_header->type))
    {
        const volume_t *p_vol;
        p_vol = p_header->p_volume;
        if ((p_vol >= volume_list) && (p_vol < (volume_list + CDEF_ELEMENT_COUNT(volume_list))) && (0 == ((size_t)p_vol - (size_t)volume_list) % sizeof(volume_t)) && (p_header->p_index >= p_vol->index_list) && (p_header->p_index < (p_vol->index_list + p_vol->index_list_count)) && (0 == (((size_t)p_header->p_index) - ((size_t)p_vol->index_list)) % sizeof(p_vol->index_list[0])))
        {
            ret = true;
        }
    }
    fm_unlock();
    return ret;
}

static fm_result_t release_index_without_lock(fm_index_t *const p_in_index)
{
    fm_result_t           ret      = FM_RES_OK;
    fm_header_t          *p_header = *p_in_index;
    const volume_t *const p_vol    = p_header->p_volume;
    handle_type_t         type     = p_header->type;

    CRIT_ASSERT(p_header->p_index == p_in_index);
    if (NULL != p_vol)
    {
        if (HANDLE_TYPE_FILE == type)
        {
            ret = p_vol->p_fs_api->close(p_vol->fs_obj, get_file_obj(p_header));
        }
        else if (HANDLE_TYPE_DIR == type)
        {
            ret = p_vol->p_fs_api->dir_close(p_vol->fs_obj, get_file_obj(p_header));
        }
        else
        {
            // do nothing
        }
    }
    p_header->p_volume = NULL;
    p_header->p_index  = NULL;
    *p_in_index        = NULL;

    return ret;
}

static fm_result_t release_index(fm_index_t *const p_in_index)
{
    fm_result_t ret;
    fm_lock();
    ret = release_index_without_lock(p_in_index);
    fm_unlock();
    return ret;
}

static fm_result_t release_index_by_volume(const volume_t *const p_vol)
{
    fm_lock();
    fm_index_t *p_index = p_vol->index_list;
    for (size_t i = 0; i < p_vol->index_list_count; i++, p_index++)
    {
        if (NULL != *p_index)
        {
            (void)release_index_without_lock(p_index);
        }
    }
    fm_unlock();
    return FM_RES_OK;
}

static inline fm_result_t release_handle(fm_handle_t handle)
{
    return release_index(((fm_header_t *)handle)->p_index);
}

static uint32_t get_opened_handle_count_all_volumes(void)
{
    uint32_t        ret               = 0;
    const volume_t *p_vol             = volume_list;
    size_t          volume_list_count = CDEF_ELEMENT_COUNT(volume_list);
    for (size_t i = 0; i < volume_list_count; i++, p_vol++)
    {
        const fm_index_t *p_index = p_vol->index_list;
        for (size_t j = 0; j < p_vol->index_list_count; j++, p_index++)
        {
            if ((NULL != *p_index) && (NULL != (*p_index)->p_volume))
            {
                ++ret;
            }
        }
    }
    return ret;
}

static uint32_t get_opened_handle_count(const volume_t *const p_in_vol)
{
    uint32_t ret = 0;
    fm_lock();
    if (NULL == p_in_vol)
    {
        ret = get_opened_handle_count_all_volumes();
    }
    else
    {
        const fm_index_t *p_index = p_in_vol->index_list;
        for (size_t i = 0; i < p_in_vol->index_list_count; i++, p_index++)
        {
            if ((NULL != *p_index) && (NULL != (*p_index)->p_volume))
            {
                ++ret;
            }
        }
    }
    fm_unlock();
    return ret;
}

static inline handle_obj_t get_file_obj(fm_header_t *p_hdr)
{
    return (handle_obj_t)(p_hdr + 1);
}

static void storage_status_update_callback(const fm_storage_status_t status, void *const p_inout_user_data)
{
    fm_message_t msg;
    msg.p_vol  = (volume_t *)p_inout_user_data;
    msg.status = status;
    (void)osMessageQueuePut(fm_queue, (const void *)&msg, 0, 0);
}

static void update_storage_status(volume_t *const p_in_vol, const fm_storage_status_t status)
{
    mount_action_t mount_action;
    if (p_in_vol->storage_status != status)
    {
        p_in_vol->storage_status = status;
        switch (status)
        {
            case STORAGE_STATUS_READY:
                mount_action = MOUNT;
                break;
            case STORAGE_STATUS_EJECTED:
                mount_action = UMOUNT;
                break;
            default:
                mount_action = NOMOUNT;
        }
        if ((NOMOUNT != mount_action) && (mount_action != p_in_vol->mount_status))
        {
            p_in_vol->mount_status = mount_action;
            ES_TRACE_DEBUG("\"/%s\" storage state changed to <%s>, mount action: %s(%d)", p_in_vol->name, getcstr_storage_status(status), getcstr_mount_action(mount_action), mount_action);
            switch (mount_action)
            {
                case MOUNT:
                    p_in_vol->p_fs_api->mount(p_in_vol->fs_obj, true);
                    break;
                case UMOUNT:
                    p_in_vol->p_fs_api->mount(p_in_vol->fs_obj, false);
                    break;
                default:;
            }
        }
    }
}

static void update_stats(fm_result_t fr)
{
    CRIT_ASSERT(FM_RES_INVALID_PARAMETER >= fr);
    taskENTER_CRITICAL();
    ++fm_stats.api_err_counters[fr];
    should_store_stats = true;
    taskEXIT_CRITICAL();
}

static void fm_task(void *p_arg)
{
    (void)p_arg;
    fm_message_t msg;

    task_mon_task_initialized(TASK_ID_FM_MANAGER);
    task_mon_set_task_policy(TASK_ID_FM_MANAGER, TASK_MON_POLICY_MONITOR);
    ES_TRACE_INFO("<%p> sd_task() started", osThreadGetId());
    for (;;)
    {
        osStatus_t status;

        status = osMessageQueueGet(fm_queue, (void *)&msg, 0, FM_TASK_MESSAGE_TIMEOUT);

        if (osOK == status)
        {
            update_storage_status(msg.p_vol, msg.status);
        }

        if (true == should_store_stats)
        {
            should_store_stats = false;
            fm_stats_t temp_stats;
            taskENTER_CRITICAL();
            memcpy(&temp_stats, &fm_stats, sizeof(fm_stats_t));
            taskEXIT_CRITICAL();
            Nvm_SetBlockById(NVM_FM_STATS, &temp_stats, NVMSETBLOCK_STORE_POSTPONED);
        }
        task_mon_i_am_alive(TASK_ID_FM_MANAGER);
        task_mon_low_stack_check(TASK_ID_FM_MANAGER);
    }
}

static fm_result_t crc_read(
    const volume_t *const p_vol,
    fm_header_t *const    p_header,
    uint8_t *const        p_buffer,
    const size_t          buffer_size,
    uint32_t *const       p_out_crc)
{
    fm_result_t ret;
    uint32_t    bytes_remaining = 0;
    uint32_t    bytes_copied_to_buffer;

    *p_out_crc = 0;

    ret = p_vol->p_fs_api->size(p_vol->fs_obj, get_file_obj(p_header), &bytes_remaining);

    bytes_copied_to_buffer = bytes_remaining;

    while ((bytes_remaining > 0) && (bytes_copied_to_buffer > 0) && (FM_RES_OK == ret))
    {
        ret = p_vol->p_fs_api->read(p_vol->fs_obj, get_file_obj(p_header), p_buffer, buffer_size, &bytes_copied_to_buffer);

        if (FM_RES_OK == ret)
        {
            for (uint32_t i = 0; i < bytes_copied_to_buffer; i++)
            {
                // the current "crc" algorithm is just a byte checksum
                *p_out_crc += p_buffer[i];
            }

            if (bytes_remaining < bytes_copied_to_buffer)
            {
                ret = FM_RES_INT_ERR;
                break;
            }
            bytes_remaining -= bytes_copied_to_buffer;
        }
    }

    return ret;
}

static fm_result_t crc_opened_file(const volume_t *const p_in_vol, fm_header_t *const p_header, uint32_t *const p_out_crc)
{
    fm_result_t  ret;
    fm_dresult_t dres;
    size_t       block_size = 0;

    dres = p_in_vol->p_drv_api->storage_ioctl(FM_IOCTL_GET_BLOCK_SIZE, &block_size);

    ret = FM_RES_DISK_ERR;
    if ((FM_DRES_OK == dres) && (0 != block_size))
    {
        uint8_t *read_buffer;

        read_buffer = pvPortMalloc(block_size);

        ret = FM_RES_NOT_ENOUGH_CORE;
        if (NULL != read_buffer)
        {
            ret = crc_read(p_in_vol, p_header, read_buffer, block_size, p_out_crc);

            vPortFree(read_buffer);
        }
    }
    return ret;
}

static fm_result_t file_list_handler(const fm_fast_file_info_t *const info, void *const user_data)
{
    list_handler_data_t *lhd = (list_handler_data_t *)user_data;
    return lhd->p_vol->p_fs_api->xprintf(lhd->p_vol->fs_obj, lhd->handle, NULL, "/%s%s%s/%s,%lu,%c,%lu\n",
                                         lhd->p_vol->name,
                                         ((NULL != info->p_path) && (TERMINATING_ZERO_CHAR != *info->p_path))
                                             ? PATH_DELIMITER_STR
                                             : EMPTY_STR,
                                         info->p_path,
                                         info->p_name,
                                         info->size,
                                         (info->attr == (info->attr & FM_ATTR_DIR)) ? DIR_MARKER : FILE_MARKER,
                                         info->unix_mtime);
}

static fm_result_t foreach_dir_handler(const fm_fast_file_info_t *const p_info, void *const p_inout_user_data)
{
    fm_result_t       ret     = FM_RES_OK;
    stack_file_ctx_t *p_stack = p_inout_user_data;

    char   tmp_stack_full_path[FM_MAX_PATH] = { TERMINATING_ZERO_CHAR };
    size_t path_len;
    size_t name_len;

    (void)strncpy(tmp_stack_full_path, p_info->p_path, sizeof(tmp_stack_full_path) - 1);
    tmp_stack_full_path[sizeof(tmp_stack_full_path) - 1] = TERMINATING_ZERO_CHAR;

    name_len = strnlen(p_info->p_name, sizeof(tmp_stack_full_path));

    path_len = strlen(tmp_stack_full_path);
    if (path_len > 0)
    {
        path_len += PATH_DELIMITER_LEN;
    }
    path_len += name_len;
    path_len += TERMINATING_ZERO_CHAR_LEN;

    if (sizeof(tmp_stack_full_path) > path_len)
    {
        if (p_info->attr == (p_info->attr & FM_ATTR_DIR))
        {
            if (TERMINATING_ZERO_CHAR != p_info->p_path[0])
            {
                (void)strcat(tmp_stack_full_path, PATH_DELIMITER_STR);
            }
            (void)strncat(tmp_stack_full_path, p_info->p_name, name_len);
            tmp_stack_full_path[sizeof(tmp_stack_full_path) - 1] = TERMINATING_ZERO_CHAR;

            ret = stack_file_push(p_stack, tmp_stack_full_path);
        }
    }
    else
    {
        ES_TRACE_WARN("file '%s' in folder '%s' hit the name limit size of %d bytes", p_info->p_name, p_info->p_path, FM_MAX_PATH);
    }

    return ret;
}

static fm_result_t foreach_match_handler(const fm_fast_file_info_t *const p_info, void *const p_inout_user_data)
{
    foreach_info_t *p_fi = (foreach_info_t *)p_inout_user_data;

    if (0 == strcmp(INTERNAL_STACK_FILE, p_info->p_name))
    {
        return FM_RES_OK;
    }

    return p_fi->handler(p_info, p_fi->p_data);
}

static fm_result_t foreach_stack(const volume_t *const p_vol, const char *const p_in_path, const char *const p_in_glob, const fm_foreach_handler_t handler, void *const p_inout_user_data)
{
    fm_result_t      ret                              = FM_RES_INVALID_PARAMETER;
    char             current_folder_path[FM_MAX_PATH] = { 0 };
    stack_file_ctx_t stack_ctx                        = {
                               .filename                 = INTERNAL_STACK_FILE,
                               .elem_size                = FM_MAX_PATH * sizeof(char),
                               .count                    = 0,
                               .handle                   = NULL,
                               .use_internal_file_object = true,
                               .is_open                  = false
    };
    foreach_info_t fi = {
        .p_data  = p_inout_user_data,
        .handler = handler,
    };

    ret = stack_file_open(&stack_ctx);

    if (FM_RES_OK != ret)
    {
        return ret;
    }

    ret = stack_file_push(&stack_ctx, p_in_path);

    while ((stack_file_count(&stack_ctx) > 0U) && (FM_RES_OK == ret))
    {
        ret = stack_file_pop(&stack_ctx, current_folder_path);

        if (FM_RES_OK != ret)
        {
            break;
        }

        current_folder_path[sizeof(current_folder_path) - 1] = TERMINATING_ZERO_CHAR;

        p_vol->p_fs_api->foreach_flat(p_vol->fs_obj, current_folder_path, MATCH_ALL, foreach_dir_handler, &stack_ctx);
        p_vol->p_fs_api->foreach_flat(p_vol->fs_obj, current_folder_path, p_in_glob, foreach_match_handler, &fi);
    }

    (void)stack_file_close(&stack_ctx, true);

    return ret;
}
