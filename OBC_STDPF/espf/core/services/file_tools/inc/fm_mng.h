/*
 * Copyright (c) 2023-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup Services
 * @{
 *
 * @defgroup service_file_tools File tools
 * @{
 *
 * The file manager service is responsible for:
 *     - Creating, opening, reading, writing, closing, deleting, renaming, and truncating files, and more.
 *     - Getting file, directory and volume metadata (size, modification time, attributes, volume status, statistics, etc.).
 *     - Managing the file system (mounting, unmounting, formating, and getting various metadata).
 *     - Managing the underlying storage devices (initialization, status, error recovery, etc...).
 *
 * @}
 * @}
 *
 */

/**
 * @addtogroup service_file_tools
 * @{
 *
 * @file fm_mng.h
 *
 * @brief File Manager header containing the public API for file operations
 *
 * @}
 */

#ifndef FM_MNG_H
#define FM_MNG_H

#include "es_cdef.h"
#include "fm_def.h"
#include <stdarg.h>

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/

/**
 * @brief The size of a file object in bytes.
 */
#define FM_FILE_OBJECT_SIZE (572LU)

/**
 * @brief The size of a directory object in bytes.
 */
#define FM_DIR_OBJECT_SIZE (68LU)

/**
 * @brief The attribute value for a directory.
 */
#define FM_ATTR_DIR (0x10)

/**
 * @brief The maximum number preallocated of files in the SD card volume.
 */
#define FM_VOL_SD_MAX_PREALLOCATED_FILES (10)

/**
 * @brief The maximum count of opened files in the SD card volume.
 * @details This includes both externally and internally allocated file objects.
 */
#define FM_VOL_SD_MAX_INDEX (40)

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/**
 * @brief Result from file operation.
 */
typedef enum
{
    FM_RES_OK = 0,              /**< Succeeded */
    FM_RES_DISK_ERR,            /**< A hard error occurred in the low level disk I/O layer */
    FM_RES_INT_ERR,             /**< Assertion failed */
    FM_RES_NOT_READY,           /**< The physical drive cannot work */
    FM_RES_NO_FILE,             /**< Could not find the file */
    FM_RES_NO_PATH,             /**< Could not find the path */
    FM_RES_INVALID_NAME,        /**< The path name format is invalid */
    FM_RES_DENIED,              /**< Access denied due to prohibited access or directory full */
    FM_RES_EXIST,               /**< Access denied due to prohibited access */
    FM_RES_INVALID_OBJECT,      /**< The file/directory object is invalid */
    FM_RES_WRITE_PROTECTED,     /**< The physical drive is write protected */
    FM_RES_INVALID_DRIVE,       /**< The logical drive number is invalid */
    FM_RES_NOT_ENABLED,         /**< The volume has no work area */
    FM_RES_NO_FILESYSTEM,       /**< There is no valid FAT volume */
    FM_RES_MKFS_ABORTED,        /**< The f_mkfs() aborted due to any problem */
    FM_RES_TIMEOUT,             /**< Could not get a grant to access the volume within defined period */
    FM_RES_LOCKED,              /**< The operation is rejected according to the file sharing policy */
    FM_RES_NOT_ENOUGH_CORE,     /**< LFN working buffer could not be allocated */
    FM_RES_TOO_MANY_OPEN_FILES, /**< Number of open files > FF_FS_LOCK */
    FM_RES_INVALID_PARAMETER,   /**< Given parameter is invalid */
    FM_RES_COUNT                /**< Not a real value, used to calculate the highest valid value for a fm_result_t */
} fm_result_t;

/**
 * @brief Generic status for a storage device.
 */
typedef enum
{
    STORAGE_STATUS_ERROR,        /**< Error has occurred with storage */
    STORAGE_STATUS_EJECTED,      /**< No connectivity to storage media */
    STORAGE_STATUS_NOT_INIT,     /**< Storage media is connected, but not ready for operations */
    STORAGE_STATUS_INITIALIZING, /**< Storage is preparing for ready state */
    STORAGE_STATUS_BUSY,         /**< Storage is initialized but currently is busy */
    STORAGE_STATUS_READY,        /**< Storage is initialized and ready for operation */
    STORAGE_STATUS_COUNT         /**< Not a real status, used to calculate the highest valid value for a fm_storage_status_t */
} fm_storage_status_t;

/**
 * @brief Bitfields for possible file open and access modes.
 * @details FM_MODE_READ and FM_MODE_WRITE are access bits. They can be used alone or in combination.
 * @details The rest are open mode bits. Only one of them can be used at a time.
 * @details The value of FM_MODE_OPEN_EXISTING is 0, so if no open mode bits is specified, it is assumed.
 * @code
 *      // Examples of valid combinations
 *      uint8_t mode = FM_MODE_READ | FM_MODE_OPEN_EXISTING; // Open file for reading. Fail if file does not exist.
 *      uint8_t mode = FM_MODE_READ; // same as above
 *      uint8_t mode = FM_MODE_WRITE | FM_MODE_CREATE_ALWAYS; // Create file for writing. Deletes old file if existed.
 *      uint8_t mode = FM_MODE_READ | FM_MODE_WRITE | FM_MODE_OPEN_ALWAYS; // Opens a file if exists, otherwise create a new one. Can both read and write.
 *      uint8_t mode = FM_MODE_OPEN_EXISTING; // Open file. Fail if file does not exist. Although no reading or writing can be done, the user can still read the metadata. This can also be used to check for file existence, but fm_stat(path, NULL) is easier way to do it.
 *      uint8_t mode = FM_MODE_CREATE_ALWAYS; // Just delete a file if exists and create a new empty one. Writing permission is not required, as deletion is done on directory(file system) level.
 *      // INVALID combinations
 *      uint8_t mode = FM_MODE_CREATE_ALWAYS | FM_MODE_OPEN_ALWAYS; // This is invalid, as it is not clear if the file should be deleted before being opened.
 *      uint8_t mode = FM_MODE_OPEN_ALWAYS | FM_MODE_OPEN_EXISTING; // This is not strictly invalid, as FM_MODE_OPEN_EXISTING is 0, but it is confusing and should be avoided.
 * @endcode
 */
typedef enum
{
    FM_MODE_READ          = 0x01, /**< Open file for reading. Not required for reading metadata */
    FM_MODE_WRITE         = 0x02, /**< Open file for writing. */
    FM_MODE_OPEN_EXISTING = 0x00, /**< Default open mode. Fail if file does not exist. */
    FM_MODE_CREATE_NEW    = 0x04, /**< Create file. Fails if old file existed. */
    FM_MODE_CREATE_ALWAYS = 0x08, /**< Create file. Deletes old file if existed. */
    FM_MODE_OPEN_ALWAYS   = 0x10, /**< Opens a file if exists, otherwise create a new one. */
    FM_MODE_OPEN_APPEND   = 0x30, /**< Same a OPEN_ALWAYS but moves the file pointer to the end */
} fm_mode_t;

/**
 * @brief A structure the size of the internally used file object.
 * @details The point of this type is to allocate memory for a file object in the caller stack.
 * @details It can be also allocated using malloc() or similar, bit this is not recommended on an embedded platform.
 */
typedef struct
{
    uint8_t object_data[FM_FILE_OBJECT_SIZE]; /**< Placeholder the size of an internally used file object. */
} fm_file_obj_t;

/**
 * @brief A structure the size of the internally used dir object.
 * @details The point of this type is to allocate memory for a dir object in the caller stack.
 * @details It can be also allocated using malloc() or similar, bit this is not recommended on an embedded platform.
 */
typedef struct
{
    uint8_t object_data[FM_DIR_OBJECT_SIZE]; /**< Placeholder the size of an internally used dir object. */
} fm_dir_obj_t;

/**
 * @brief An abstraction for the opaque @ref fm_file_obj_t type.
 */
typedef fm_file_obj_t *fm_handle_t;

/**
 * @brief A type for a pointer to a constant file object.
 */
typedef const fm_file_obj_t *c_fm_handle_t;

/**
 * @brief An abstraction for the opaque @ref fm_dir_obj_t type.
 */
typedef fm_dir_obj_t *fm_dir_handle_t;

/**
 * @brief A structure containing information about a file matched in the fm_dir_xxx traversal functions.
 */
typedef struct
{
    uint32_t attr;                   /**< Attributes of the file. Currently only @ref FM_ATTR_DIR. */
    uint32_t size;                   /**< File size in bytes. The size on disk may be different. */
    uint32_t unix_mtime;             /**< Modification time in unix seconds since 1 January 1970. */
    char     full_path[FM_MAX_PATH]; /**< The full path to the file. */
} fm_file_info_t;

/**
 * @brief A structure containing information about a file matched in the fm_foreach_xxx handler functions
 */
typedef struct
{
    uint32_t    attr;       /**< Attributes of the file. Currently only @ref FM_ATTR_DIR. */
    uint32_t    size;       /**< File size in bytes. The size on disk may be different. */
    uint32_t    unix_mtime; /**< Modification time in unix seconds since 1 January 1970. */
    const char *p_name;     /**< The basename of to the file. */
    const char *p_path;     /**< The dirname (i.e. full path of the containing directory) to the file. */
} fm_fast_file_info_t;

/**
 * @brief A handler function for the fm_foreach_xxx functions.
 * @see fm_foreach
 * @see fm_foreach_flat
 */
typedef fm_result_t (*fm_foreach_handler_t)(const fm_fast_file_info_t *const p_info, void *const p_inout_user_data);

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

/**
 * @brief Get a string representation of the result.
 */
const char *fm_result_to_str(const fm_result_t result);

/**
 * @brief File Manager initialisation routine
 * @details This routine **must** be called once before any other file manager functions.
 */
void fm_init(void);

/**
 * @brief open a file using a file object allocated by the caller.
 *
 * @param[in] handle a pointer to an uninitialized file object. The file object must be of equal or greater size to @ref fm_file_obj_t
 *      The value handle is to be used in all subsequent file operations.
 * @param[in] p_in_path a zero-terminated ascii string with the full path of the file.
 * @param[in] mode a combination of bitfield values of @ref fm_mode_t OR'd together.
 *
 * @return Result of performed operation, @ref fm_result_t
 *
 * @code
 *      fm_file_obj_t file_obj;
 *      fm_open(&file_obj, "some_existing_file.txt", FM_MODE_READ); \/\/ FM_MODE_OPEN_EXISTING is implied
 * @endcode
 * @code
 *      fm_file_obj_t file_obj;
 *      fm_open(&file_obj, "output.log", FM_MODE_WRITE | FM_MODE_CREATE_ALWAYS);
 * @endcode
 */
fm_result_t fm_open(fm_handle_t handle, const char *const p_in_path, const uint32_t mode);

/**
 * @brief open a file using an internally preallocated static file object.
 *
 * @param[out] p_out_handle a pointer to a fm_handle_t type.
 *      The value stored in fm_handle_t is to be used in all subsequent file operations.
 * @param[in] p_in_path a zero-terminated ascii string with the full path of the file.
 * @param[in] mode a combination of bitfield values of @ref fm_mode_t OR'd together.
 *
 * @return Result of performed operation, @ref fm_result_t
 *
 * @note This function is usually reserved for use by the file manager fidl service.
 *      It may be used if stack size is a concern and file would be released quickly (fm_close()).
 *      Amount of preallocated file objects is limited.
 *      Typical usage is same as fm_open(), with the difference that the file object is not allocated by the caller.
 *      The file handle is used the same way as a pointer to a fm_file_obj_t with the other file functions.
 * @code
 *      fm_handle_t file_handle;
 *      fm_open_internal(&file_handle, "some_file.bin", FM_MODE_WRITE | FM_MODE_READ | FM_MODE_CREATE_ALWAYS);
 * @endcode
 */
fm_result_t fm_open_internal(fm_handle_t *const p_out_handle, const char *const p_in_path, const uint32_t mode);

/**
 * @brief Check if a handle points to a valid opened file object.
 *
 * @param[in] handle a pointer to a file object.
 *
 * @retval true - handle is a valid opened file
 */
bool fm_is_open(c_fm_handle_t handle);

/**
 * @brief close a file
 * @details Operations that change the metadata of a file are not completely flushed until fm_sync() or fm_close() is called.
 *
 * @param[in] handle a pointer to a file object. It must have been initialized by fm_open() or fm_open_internal() beforehand.
 *
 * @return Result of performed operation, @ref fm_result_t
 */
fm_result_t fm_close(fm_handle_t handle);

/**
 * @brief read data from an opened file. the data will be read from the current file position.
 *
 * @param[in] handle a pointer to a file object. It must have been initialized by fm_open() or fm_open_internal()
 * @param[out] p_out_buff a pointer to memory which will be filled with the data from the file. The memory size must be at least bytes_to_read.
 * @param[in] bytes_to_read the amount of bytes to be read from the file
 * @param[out] p_out_bytes_read the amount of bytes successfully read from the file. May be NULL.
 *
 * @return Result of performed operation, @ref fm_result_t
 *
 * @code
 *      fm_result_t res;
 *      fm_file_obj_t file_obj;
 *      char buffer[1024];
 *      res = fm_open(&file_obj, "some_existing_file.txt", FM_MODE_READ);
 *      if (FM_RES_OK == res) {
 *          fm_read(&file_obj, buffer, sizeof(buffer), NULL);
 *          fm_close(&file_obj);
 *      }
 * @endcode
 */
fm_result_t fm_read(
    fm_handle_t     handle,
    void *const     p_out_buff,
    const uint32_t  bytes_to_read,
    uint32_t *const p_out_bytes_read);

/**
 * @brief Read a line from an opened file. The line is delimited by '\\n'.
 *
 * @param[in] handle a pointer to a file object. It must have been initialized by fm_open() or fm_open_internal()
 * @param[out] p_out_buff a pointer to memory which will be filled with the data from the file. The memory size must be at least bytes_to_read.
 * @param[in] buffer_size the maximum bytes to be read into the buffer.
 *
 * @return Result of performed operation, @ref fm_result_t
 *
 * @see fm_list
 */
fm_result_t fm_gets(fm_handle_t handle, void *const p_out_buff, const uint32_t buffer_size);

/**
 * @brief read data from an opened file at a specified positon.
 *
 * @param[in] handle a pointer to a file object. It must have been initialized by fm_open() or fm_open_internal()
 * @param[out] p_out_buff a pointer to memory which will be filled with the data from the file. The memory size must be at least bytes_to_read.
 * @param[in] bytes_to_read the amount of bytes to be read from the file
 * @param[out] p_out_bytes_read the amount of bytes successfully read from the file. May be NULL.
 * @param[in] pos the position at which the file will be set before reading.
 *
 * @return Result of performed operation, @ref fm_result_t
 *
 * @note
 *      On success, the file position will be moved (*p_out_bytes_read) bytes ahead.
 *          (*p_out_bytes_read) may be less than bytes_to_read if current position + bytes_to_read is greater than file size.
 *          p_out_buff will have the amount of (*p_out_bytes_read) bytes copied from the file.
 *      On failure, file position is undefined and should be reset by fm_seek() or read by fm_tell()
 *          the contents of p_out_buff are undefined.
 *
 * @see fm_read
 */
fm_result_t fm_read_at_pos(
    fm_handle_t     handle,
    void *const     p_out_buff,
    const uint32_t  bytes_to_read,
    uint32_t *const p_out_bytes_read,
    const uint32_t  pos);

/**
 * @brief write data to an opened file at the current position.
 *
 * @param[in] handle a pointer to a file object. It must have been initialized by fm_open() or fm_open_internal()
 * @param[in] p_in_buff a pointer to memory which will be copied to the file. The memory size must be at least bytes_to_write.
 * @param[in] bytes_to_write the amount of bytes to be written from the file
 * @param[out] p_out_bytes_written the amount of bytes successfully written to the file. May be NULL.
 *
 * @return Result of performed operation, @ref fm_result_t
 *
 * @note
 *      On success, the file position will be moved (*p_out_bytes_written) bytes ahead.
 *          p_out_buff will have the amount of (*p_out_bytes_read) bytes copied from the file.
 *      On failure, file position is undefined and should be reset by fm_seek() or read by fm_tell()
 *          the contents of p_out_buff are undefined.
 *
 * @code
 *      fm_result_t res;
 *      fm_file_obj_t file_obj;
 *      char buffer[32];
 *      sprintf("Some random info");
 *      res = fm_open(&file_obj, "output.log", FM_MODE_WRITE | FM_MODE_OPEN_APPEND);
 *      if (FM_RES_OK == res) {
 *          uint32_t bytes_written;
 *          fm_write(&file_obj, buffer, sizeof(buffer), &bytes_written);
 *          fm_close(&file_obj);
 *          if (sizoeof(buffer) != bytes_written) {
 *              printf("Error writing to file\n");
 *          }
 *      }
 * @endcode
 */
fm_result_t fm_write(
    fm_handle_t     handle,
    const void     *p_in_buff,
    const uint32_t  bytes_to_write,
    uint32_t *const p_out_bytes_written);

/**
 * @brief write data to an opened file at a specified positon.
 * @note Although data written to file is flushed immediately, the cluster chain is not updated until fm_sync() or fm_close() is called.
 *
 * @param[in] handle a pointer to a file object. It must have been initialized by fm_open() or fm_open_internal()
 * @param[in] p_in_buff a pointer to memory which will be copied to the file. The memory size must be at least bytes_to_write.
 * @param[in] bytes_to_write the amount of bytes to be written from the file
 * @param[out] p_out_bytes_written the amount of bytes successfully written to the file. May be NULL.
 * @param[in] pos the position at which the file will be set before reading.
 *
 * @return Result of performed operation, @ref fm_result_t
 *
 * @see fm_write
 */
fm_result_t fm_write_at_pos(
    fm_handle_t       handle,
    const void *const p_in_buff,
    const uint32_t    bytes_to_write,
    uint32_t *const   p_out_bytes_written,
    const uint32_t    pos);

/**
 * @brief Write formatted text to an opened file at the current positon.
 * @details Supported specifiers: %d, %u, %x, %o, %b, %c, %s, length width, precision, padding, left/right justification, integer size
 * @details Supported modifiers: width (both fixed and parametrized (e.g. '%.*d')), padding (space ' ' and zero '0'), left/right justification ('-'), integer size ('l')
 * @note Although data written to file is flushed immediately, the cluster chain is not updated until fm_sync() or fm_close() is called.
 * @param[in] handle a pointer to a file object. It must have been initialized by fm_open() or fm_open_internal()
 * @param[out] p_out_bytes_written the amount of bytes successfully written to the file. May be NULL.
 * @param[in] p_in_fmt format string
 *
 * @return Result of performed operation, @ref fm_result_t
 *
 * @see fm_write
 * @code
 *      ...
 *      fm_printf(&file_obj, NULL, "Some text %d\n", 42);
 *      ...
 * @endcode
 */
fm_result_t fm_printf(fm_handle_t handle, uint32_t *const p_out_bytes_written, const char *const p_in_fmt, ...);

/**
 * @brief Write initialized varargs to an opened file at the current positon.
 * @note Although data written to file is flushed immediately, the cluster chain is not updated until fm_sync() or fm_close() is called.
 *
 * @param[in] handle a pointer to a file object. It must have been initialized by fm_open() or fm_open_internal()
 * @param[out] p_out_bytes_written the amount of bytes successfully written to the file. May be NULL.
 * @param[in] p_in_fmt format string
 * @param[in] ap initialized vararg list
 *
 * @return Result of performed operation, @ref fm_result_t
 */
fm_result_t fm_vprintf(fm_handle_t handle, uint32_t *const p_out_bytes_written, const char *const p_in_fmt, va_list ap);

/**
 * @brief Set file size. file must be opened with the FM_MODE_WRITE flag.
 * @note It is neccessary to call fm_sync() or fm_close() to update the cluster chain.
 *
 * @param[in] handle a pointer to a file object. It must have been initialized by fm_open() or fm_open_internal()
 * @param[in] pos the size of the file which it will be set to. this may be less or greater than the current size.
 *
 * @return Result of performed operation, @ref fm_result_t
 */
fm_result_t fm_truncate(fm_handle_t handle, const uint32_t pos);

/**
 * @brief Get opened file current size.
 *
 * @param[in] handle a pointer to a file object. It must have been initialized by fm_open() or fm_open_internal()
 * @param[out] p_out_size pointer to a value which will be set with the current size.
 *
 * @return Result of performed operation, @ref fm_result_t
 */
fm_result_t fm_size(fm_handle_t handle, uint32_t *const p_out_size);

/**
 * @brief Get opened file current position.
 *
 * @param[in] handle a pointer to a file object. It must have been initialized by fm_open() or fm_open_internal()
 * @param[out] p_out_pos pointer to a value which will be set with the current position.
 *
 * @return Result of performed operation, @ref fm_result_t
 */
fm_result_t fm_tell(fm_handle_t handle, uint32_t *const p_out_pos);

/**
 * @brief Set opened file current position.
 *
 * @param[in] handle a pointer to a file object. It must have been initialized by fm_open() or fm_open_internal()
 * @param[out] pos position to set the file to.
 *
 * @note If file is opened with FM_MODE_WRITE and pos is greater than current file size,
 *      file will be expanded to reach the position. The newly allocated bytes are undefined.
 * @note It is neccessary to call fm_sync() or fm_close() to update the cluster chain.
 *
 * @return Result of performed operation, @ref fm_result_t
 */
fm_result_t fm_seek(fm_handle_t handle, const uint32_t pos);

/**
 * @brief Flush explicitly data to file.
 * @details Operations that change the metadata of a file are not flushed until fm_sync() or fm_close() is called.
 *
 * @param[in] handle a pointer to a file object. It must have been initialized by fm_open() or fm_open_internal()
 *
 * @return Result of performed operation, @ref fm_result_t
 */
fm_result_t fm_sync(fm_handle_t handle);

/**
 * @brief Get metadata about a file.
 *
 * @param[in] p_in_path a zero-terminated ascii string with the full path of the file.
 * @param[out] p_out_tfi a pointer to a structure to be filled with info. the structure is allocated by the caller.
 *
 * @return Result of performed operation, @ref fm_result_t
 * @note p_out_tfi may be NULL, in which case fm_stat may be used for a quick check of file existence.
 */
fm_result_t fm_stat(const char *const p_in_path, fm_fast_file_info_t *const p_out_tfi);

/**
 * @brief Get checksum of a file.
 *
 * @param[in] p_in_path a zero-terminated ascii string with the full path of the file.
 * @param[out] p_out_tfi a pointer to the value which will receive the checksum.
 *
 * @return Result of performed operation, @ref fm_result_t
 */
fm_result_t fm_crc(const char *const p_in_path, uint32_t *const p_out_crc);

/**
 * @brief Rename/move a file or dir.
 * @details The function will fail if the new file exists.
 * @details Both the source and destination must be on the same volume.
 * @param[in] p_in_path_old a zero-terminated ascii string with the full path of the current file or dir.
 * @param[in] p_in_path_new a zero-terminated ascii string with the full path of the new file or dir.
 *
 * @return Result of performed operation, @ref fm_result_t
 */
fm_result_t fm_rename(const char *const p_in_path_old, const char *const p_in_path_new);

/**
 * @brief Delete a file or dir.
 * @details The will fail if the source is a directory which is not empty.
 *
 * @param[in] p_in_path a zero-terminated ascii string with the full path of the file or dir.
 *
 * @return Result of performed operation, @ref fm_result_t
 *
 * @note If p_in_path is a dir, it must be empty for the function to succeed.
 *
 */
fm_result_t fm_delete(const char *const p_in_path);

/**
 * @brief Create a dir.
 * @details Intermediate directories are not created if they do not exist, so the function will fail if this is the case.
 * @param[in] p_in_path a zero-terminated ascii string with the full path of the file or dir.
 * @return Result of performed operation @see fm_result_t
 * @note This function does not create the intermediate directories, if any.
 */
fm_result_t fm_mkdir(const char *const p_in_path);

/**
 * @brief Store a list of all files and dirs in a text file.
 * @details The listing file will be overwritten if it exists.
 * @details The file list is stored in CSV format with a header.
 * @details The header is "file_name,size(in bytes),attributes,timestamp", lines are with unix-style line endings, paths also unix style - single forward slash per directory.
 *
 * @param[in] p_in_path a zero-terminated ascii string with the full path of the file which is to be filled with the list entries.
 * @param[in] p_in_glob the string for matching the filenames. the basic glob operators ? and * are supported.
 *
 * @return Result of performed operation, @ref fm_result_t
 *
 * @note After the file is filled it must be opened and read like a regular file.
 *      Order of entries is not guaranteed.
 *
 * @code
 *      // Example usage. List all files in the filesystem and calculate the total size of all files.
 *      // This is not expected to strictly work as is, but to give an idea of how to use the function.
 *      fm_file_obj_t file_obj;
 *      uint32_t total_size = 0;
 *      char buffer[FM_MAX_PATH+32]; // file path is FM_MAX_PATH bytes, the other fields are uint32_t, so this should be more than enough;
 *      fm_list("dirlist.txt", NULL);
 *      fm_open(&file_obj, "dirlist.txt", FM_MODE_READ);
 *      while(FM_RES_OK == fm_gets(&file_obj, buffer, sizeof(buffer))) {
 *          char * p = strchr(buffer, ',');
 *          total_size += strtoul(++p, NULL, 10);
 *      }
 *      fm_close(&file_obj);
 *      printf("Total size of all files in the filesystem: %u\n", total_size);
 * @endcode
 */
fm_result_t fm_list(const char *const p_in_path, const char *const p_in_glob);

/**
 * @brief Iterate through files and recursively through dirs and run handler on each match.
 *
 * @param[in] p_in_path must be a dir or empty for root. starting point for the matching.
 * @param[in] p_in_glob the string for matching the filenames. the basic glob operators ? and * are supported. NULL is interpreted as "*", i.e. match all.
 * @param[in] handler function to be executed on each match
 * @param[in,out] p_inout_user_data arbitrary pointer to user data, that is passed to the handler function
 *
 * @return Result of performed operation, @ref fm_result_t
 *
 * @note `glob` will match dir names as well.
 *      Subdirectories will be traversed recursively.
 *      Order of matches and recursion are not guaranteed.
 */
fm_result_t fm_foreach(const char *const p_in_path, const char *const p_in_glob, const fm_foreach_handler_t handler, void *const p_inout_user_data);

/**
 * @brief Iterate through files in a dir and run handler on each match.
 *
 * @param[in] p_in_path must be a dir or empty for root.
 * @param[in] p_in_glob the string for matching the filenames. the basic glob operators ? and * are supported. NULL is interpreted as "*", i.e. match all.
 * @param[in] handler function to be executed on each match
 * @param[in,out] p_inout_user_data arbitrary pointer to user data, that is passed to the handler function
 *
 * @return Result of performed operation, @ref fm_result_t
 *
 * @note `glob` will match directory names as well.
 *      Subdirectories will NOT traversed.
 *      Order of matches is not guaranteed.
 *      To check if a match is a directory, @see fm_file_info_t
 */
fm_result_t fm_foreach_flat(const char *p_in_path, const char *const p_in_glob, const fm_foreach_handler_t handler, void *const p_inout_user_data);

/**
 * @brief Iterate through files in a dir
 *
 * @param[out] handle pointer to a dir object, allocated by the caller. object must be at least fm_dir_obj_t big.
 * @param[in] p_in_path must be a dir or empty for root.
 * @param[in] p_in_glob the string for matching the filenames. the basic glob operators ? and * are supported. NULL is interpreted as "*", i.e. match all.
 *
 * @return Result of performed operation, @ref fm_result_t
 *
 * @note `glob` will match directory names as well.
 *      Subdirectories will NOT traversed.
 *      Order of matches is not guaranteed.
 *      To check if a match is a directory, @see fm_file_info_t
 */
fm_result_t fm_dir_open(fm_dir_handle_t const handle, const char *p_in_path, const char *const p_in_glob);

/**
 * @brief Iterate through files in a dir, using an internally preallocated dir object.
 *
 * @param[out] p_out_handle pointer to a dir handle which will be set to point to the internally allocated dir object.
 * @param[in] p_in_path must be a dir or empty for root.
 * @param[in] p_in_glob the string for matching the filenames. the basic glob operators ? and * are supported.
 *
 * @return Result of performed operation
 * @see fm_result_t
 * @see fm_dir_open
 * @see fm_dir_next
 * @see fm_dir_close
 *
 * @note Glob will match directory names as well.
 *       Subdirectories will NOT traversed.
 *       Order of matches is not guaranteed.
 *       To check if a match is a directory, @see fm_file_info_t
 */
fm_result_t fm_dir_open_internal(fm_dir_handle_t *const p_out_handle, const char *p_in_path, const char *const p_in_glob);

/**
 * @brief Match the next file
 *
 * @param[out] handle pointer to a dir object which has been initialized by fm_dir_open() or fm_dir_open_internal()
 * @param[out] p_out_ffi pointer to a an object, allocated by the caller where the matched file info will be stored.
 *
 * @return Result of performed operation, @ref fm_result_t
 */
fm_result_t fm_dir_next(const fm_dir_handle_t handle, fm_file_info_t *const p_out_ffi);

/**
 * @brief Close a dir object and free resources
 *
 * @param[out] handle pointer to a dir object which has been initialized by fm_dir_open() or fm_dir_open_internal()
 *
 * @return Result of performed operation, @ref fm_result_t
 */
fm_result_t fm_dir_close(const fm_dir_handle_t handle);

/**
 * @brief format the storage device
 *
 * @param[in] p_in_path must point to a volume path or empty for default
 *
 * @return Result of performed operation, @ref fm_result_t
 *
 * @note formatting the storage device resets all file handles
 */
fm_result_t fm_format(const char *const p_in_path);

/**
 * @brief Get number of handles opened within one or all volumes.
 *
 * @param[in] p_in_path must point to a volume path or empty for default, NULL for all volumes
 * @param[out] p_out_count pointer to value which will be set to the handle count.
 *
 * @return Result of performed operation, @ref fm_result_t
 */
fm_result_t fm_get_handle_count(const char *const p_in_path, uint32_t *const p_out_count);

/**
 * @brief get size of storage device in kilobytes (1024 bytes)
 *
 * @param[in] p_in_path must point to a volume path or empty for default
 * @param[out] p_out_kb_size pointer to value which will be set to the free kb size.
 *
 * @return Result of performed operation, @ref fm_result_t
 * @note p_out_kb_size is rounded down to the nearest kilobyte.
 *       Amount of available bytes does not mean that they can all be used for writing to a file.
 *       The file system may reserve some space for metadata upon file creations or expansion.
 *       Also data may allocated in sectors, which are bigger than 1 byte and a 1 byte file may take a whole sector which is unshareable with other files.
 *       Fragmentation may also lead to additional internal used of available space.
 */
fm_result_t fm_get_free(const char *const p_in_path, uint32_t *const p_out_kb_size);

/**
 * @brief Initialize a storage device.
 *
 * @param[in] p_in_path Must be a volume path only or empty for default volume.
 * @param[in] timeout Time in milliseconds to wait for the device to initialize.
 * @param[out] p_out_status Pointer to value which will be set to the status of the device. May be NULL.
 *
 * @return Result of performed operation, @ref fm_result_t
 *
 * @note initializing the storage device resets all file handles
 * @note FM_RES_OK result does NOT mean that the device is initialized successfully
 *      it means no errors have occured during the process
 *      p_out_status must be checked for device status.
 */
fm_result_t fm_storage_init(const char *const p_in_path, const uint32_t timeout, fm_storage_status_t *const p_out_status);

/**
 * @brief Get status of a storage device
 *
 * @param[in] p_in_path must point to a volume path or empty for default
 * @param[out] p_out_status pointer to value which will be set to the status of the device.
 *
 * @return Result of performed operation, @ref fm_result_t
 *
 * @code
 *      fm_storage_status_t status;
 *      fm_result_t res = fm_storage_status(FM_VOL_SD_PATH, &status);
 *      if (FM_RES_OK == res && STORAGE_STATUS_READY == status) {
 *          // do whatever
 *      }
 * @endcode
 */
fm_result_t fm_storage_status(const char *const p_in_path, fm_storage_status_t *const p_out_status);

/**
 * @brief Simplified version of fm_storage_status()
 *
 * @param[in] p_in_path must point to a volume path or empty for default
 *
 * @return true - is ready, false - error or not ready
 * @code
 *      if (true == fm_storage_status_ready(FM_VOL_SD_PATH)) {
 *          // do whatever
 *      }
 * @endcode
 */
bool fm_storage_status_ready(const char *const p_in_path);

/**
 * @brief Get statistics about an error
 *
 * @param[in] id error to get information about
 * @param[out] p_out_stat pointer to value which will be set to the stats.
 *
 * @return Result of performed operation, @ref fm_result_t
 *
 * @code
 *      uint16_t stat;
 *      fm_get_stat_by_id(FM_RES_DISK_ERR, &stat);
 *      printf("Disk error count: %d\n", stat);
 * @endcode
 */
fm_result_t fm_get_stat_by_id(const fm_result_t id, uint16_t *const p_out_stat);

/**
 * @brief Set all statistics counters to zero
 *
 * @return Result of performed operation, @ref fm_result_t
 */
fm_result_t fm_clear_stats(void);

#endif /* FM_MNG_H */
