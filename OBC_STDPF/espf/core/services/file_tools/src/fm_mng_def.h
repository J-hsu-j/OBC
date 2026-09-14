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
 * @file fm_mng_def.h
 *
 * @brief private API definitions used throughout the file tools services.
 *
 * @}
 *
 */

#ifndef FM_MNG_DEF_H
#define FM_MNG_DEF_H

#include "es_cdef.h"
#include "integer.h"
#include "fm_mng.h"

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/**
 * @brief disk operation result
 */
typedef enum
{
    FM_DRES_OK = 0, /**< 0: Successful */
    FM_DRES_ERROR,  /**< 1: R/W Error */
    FM_DRES_WRPRT,  /**< 2: Write Protected */
    FM_DRES_NOTRDY, /**< 3: Not Ready */
    FM_DRES_PARERR  /**< 4: Invalid Parameter */
} fm_dresult_t;

/**
 * @brief disk status
 */
typedef enum
{
    FM_DSTA_OK      = 0, /**< Successful */
    FM_DSTA_NOINIT  = 1, /**< Drive not initialized */
    FM_DSTA_NODISK  = 2, /**< No medium in the drive */
    FM_DSTA_PROTECT = 4, /**< Write protected */
} fm_dstatus_t;

/**
 * @brief Ioctl commands.
 */
typedef enum
{
    FM_IOCTL_CTRL_SYNC,        /**< Complete pending write process (needed at _FS_READONLY == 0) */
    FM_IOCTL_GET_SECTOR_COUNT, /**< Get sector  (needed at _USE_MKFS == 1) */
    FM_IOCTL_GET_SECTOR_SIZE,  /**< Get sector size */
    FM_IOCTL_GET_BLOCK_SIZE,   /**< Get block size */
    FM_IOCTL_CTRL_TRIM,        /**< Inform device that the data on the block of sectors is no longer used (needed at _USE_TRIM == 1) */
    FM_IOCTL_INIT,             /**< Initialize the storage device */
    FM_IOCTL_STATUS,           /**< Get the status of the storage device */
} fm_ioctl_cmd_t;

/**
 * @brief Storage device API interface structure.
 */
typedef struct
{
    fm_dresult_t        (*storage_read)(void *const p_out_buff, const uint32_t address, const uint32_t size);       /**< Read data from the storage device */
    fm_dresult_t        (*storage_write)(const void *const p_in_buff, const uint32_t address, const uint32_t size); /**< Write data to the storage device */
    fm_dresult_t        (*storage_ioctl)(const uint8_t cmd, void *p_inout_data);                                    /**< Perform device specific control operations */
    fm_storage_status_t (*storage_init)(const uint32_t timeout);                                                    /**< Initialize the storage device */
    fm_storage_status_t (*storage_status)(void);                                                                    /**< Get the status of the storage device */
} fm_storage_api_t;

/**
 * @brief Storage api abstraction object.
 */
typedef void *diskio_obj_t;

/**
 * @brief Function type for the storage status change callback.
 * @param[in] status The new status of the storage device.
 * @param[in,out] p_inout_user_data User data pointer.
 */
typedef void (*storage_status_change_callback_t)(const fm_storage_status_t status, void *const p_inout_user_data);

/**
 * @brief Abstract file object.
 */
typedef void *handle_obj_t;

/**
 * @brief Constant abstract file object.
 */
typedef const void *c_handle_obj_t;

/**
 * @brief File system API abstraction object.
 */
typedef void *fs_api_obj_t;

/**
 * @brief File system API interface structure.
 */
typedef struct
{
    /**
     * @brief Open a file.
     * @param[in] api_obj The file system api object.
     * @param[in,out] handle The file handle object. File object is initialised in a successful call.
     * @param[in] p_in_path The path to the file.
     * @param[in] mode The mode to open the file.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*open)(
        fs_api_obj_t      api_obj,
        handle_obj_t      handle,
        const char *const p_in_path,
        const uint32_t    mode);

    /**
     * @brief Close a file.
     * @param[in] api_obj The file system api object.
     * @param[in] handle The file handle object.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*close)(
        fs_api_obj_t api_obj,
        handle_obj_t handle);

    /**
     * @brief Read a line delimited by '\\n'.
     * @param[in] api_obj The file system api object.
     * @param[in] handle The file handle object.
     * @param[out] p_out_buff The buffer to store the read line.
     * @param[in] buffer_size The size of the buffer.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*xgets)(
        fs_api_obj_t   api_obj,
        handle_obj_t   handle,
        void *const    p_out_buff,
        const uint32_t buffer_size);

    /**
     * @brief Read data from the file.
     * @param[in] api_obj The file system api object.
     * @param[in] handle The file handle object.
     * @param[out] p_out_buff The buffer to store the read data.
     * @param[in] bytes_to_read The number of bytes to read.
     * @param[out] p_out_bytes_read The number of bytes actually read. May be NULL.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*read)(
        fs_api_obj_t    api_obj,
        handle_obj_t    handle,
        void *const     p_out_buff,
        const uint32_t  bytes_to_read,
        uint32_t *const p_out_bytes_read);

    /**
     * @brief Write data to the file.
     * @param[in] api_obj The file system api object.
     * @param[in] handle The file handle object.
     * @param[in] p_in_buff The buffer containing the data to write.
     * @param[in] bytes_to_write The number of bytes to write.
     * @param[out] p_out_bytes_written The number of bytes actually written. May be NULL.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*write)(
        fs_api_obj_t      api_obj,
        handle_obj_t      handle,
        const void *const p_in_buff,
        const uint32_t    bytes_to_write,
        uint32_t *const   p_out_bytes_written);

    /**
     * @brief Write a formatted string to the file.
     * @details Supported specifiers: %%d, %%u, %%x, %%o, %%b, %%c, %%s.
     * @details Supported modifiers: width (both fixed and parametrized (e.g. '%.*d')), padding (space ' ' and zero '0'), left/right justification ('-'), integer size ('l')
     * @param[in] api_obj The file system api object.
     * @param[in] handle The file handle object.
     * @param[out] p_out_bytes_written The number of bytes actually written. May be NULL.
     * @param[in] p_in_fmt The format string.
     * @param[in] ... The format arguments.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*xprintf)(
        fs_api_obj_t      api_obj,
        handle_obj_t      handle,
        uint32_t *const   p_out_bytes_written,
        const char *const p_in_fmt,
        ...);

    /**
     * @brief Write initialized varargs to an opened file at the current positon.
     * @param[in] api_obj The file system api object.
     * @param[in] handle The file handle object.
     * @param[out] p_out_bytes_written The number of bytes actually written. May be NULL.
     * @param[in] p_in_fmt The format string.
     * @param[in] ap The initialized varargs.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*vprintf)(
        fs_api_obj_t      api_obj,
        handle_obj_t      handle,
        uint32_t *const   p_out_bytes_written,
        const char *const p_in_fmt,
        va_list           va);

    /**
     * @brief Truncate the file to current position.
     * @param[in] api_obj The file system api object.
     * @param[in] handle The file handle object.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*truncate)(
        fs_api_obj_t api_obj,
        handle_obj_t handle);

    /**
     * @brief Get the size of the opened file.
     * @param[in] api_obj The file system api object.
     * @param[in] handle The file handle object.
     * @param[out] p_out_size Pointer to the value which will store the size of the file.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*size)(
        fs_api_obj_t    api_obj,
        c_handle_obj_t  handle,
        uint32_t *const p_out_size);

    /**
     * @brief Get the current file pointer position.
     * @param[in] api_obj The file system api object.
     * @param[in] handle The file handle object.
     * @param[out] p_out_pos Pointer to the value which will store the current file pointer position.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*tell)(
        fs_api_obj_t   api_obj,
        c_handle_obj_t handle,
        uint32_t      *p_out_offset);

    /**
     * @brief Move the file pointer of the file object.
     * @param[in] api_obj The file system api object.
     * @param[in] handle The file handle object.
     * @param[in] pos The new position of the file pointer. This value is absolute, not relative.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*seek)(
        fs_api_obj_t   api_obj,
        handle_obj_t   handle,
        const uint32_t offset);

    /**
     * @brief Flush cached data of the writing file.
     * @param[in] api_obj The file system api object.
     * @param[in] handle The file handle object.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*sync)(
        fs_api_obj_t api_obj,
        handle_obj_t handle);

    /**
     * @brief Get file status.
     * @param[in] api_obj The file system api object.
     * @param[in] p_in_path The path to the file.
     * @param[out] p_out_tfi Pointer to the file status structure.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*stat)(
        fs_api_obj_t               api_obj,
        const char                *path,
        fm_fast_file_info_t *const p_out_tfi);

    /**
     * @brief Rename/Move a file or directory.
     * @details The function will fail if the new file exists.
     * @param[in] api_obj The file system api object.
     * @param[in] p_in_path_old The old path to the file or directory.
     * @param[in] p_in_path_new The new path to the file or directory.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*rename)(
        fs_api_obj_t      api_obj,
        const char *const p_in_path_old,
        const char *const p_in_path_new);

    /**
     * @brief Delete a file or directory.
     * @details The function will fail if the file is open.
     * @param[in] api_obj The file system api object.
     * @param[in] p_in_path The path to the file.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*delete)(
        fs_api_obj_t      api_obj,
        const char *const p_in_path);

    /**
     * @brief Create a directory.
     * @details The function will fail if the directory exists.
     * @details Intermediate directories are not created if they do not exist, so the function will fail if this is the case.
     * @param[in] api_obj The file system api object.
     * @param[in] p_in_path The path to the directory.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*mkdir)(
        fs_api_obj_t      api_obj,
        const char *const p_in_path);

    /**
     * @brief Iterate through all files in directory without recursion.
     * @param[in] api_obj The file system api object.
     * @param[in] p_in_start_path The path to the directory.
     * @param[in] p_in_glob The glob pattern to match.
     * @param[in] handler The handler function to call for each file. See @ref fm_forech_handler_t for details.
     * @param[in,out] p_inout_user_data The user data to pass to the handler function.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*foreach_flat)(
        fs_api_obj_t               api_obj,
        const char *const          start_path,
        const char *const          p_in_glob,
        const fm_foreach_handler_t handler,
        void *const                p_inout_user_data);

    /**
     * @brief Open a directory object.
     * @param[in] api_obj The file system api object.
     * @param[in] handle The file handle object.
     * @param[in] p_in_path The path to the directory.
     * @param[in] p_in_glob The glob pattern to match.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*dir_open)(
        fs_api_obj_t      api_obj,
        handle_obj_t      handle,
        const char *const path,
        const char *const p_in_glob);

    /**
     * @brief Get the next item in the directory.
     * @param[in] api_obj The file system api object.
     * @param[in] handle The directory handle object.
     * @param[out] p_out_ffi Pointer to the file info structure.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*dir_next)(
        fs_api_obj_t          api_obj,
        handle_obj_t          handle,
        fm_file_info_t *const p_out_ffi);

    /**
     * @brief Close the directory object.
     * @param[in] api_obj The file system api object.
     * @param[in] handle The directory handle object.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*dir_close)(
        fs_api_obj_t api_obj,
        handle_obj_t handle);

    /**
     * @brief Mount/Unmount a logical drive.
     * @param[in] api_obj The file system api object.
     * @param[in] mount The mount flag. If true, the function will mount the drive. If false, the function will unmount the drive.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*mount)(
        fs_api_obj_t api_obj,
        const bool   mount);

    /**
     * @brief Create a FAT volume.
     * @param[in] api_obj The file system api object.
     * @return Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*format)(
        fs_api_obj_t api_obj);

    /**
     * @brief Get the number of free space in KB for a file system.
     * @param[in] api_obj The file system api object.
     * @param[out] p_out_kb_size Pointer to the value which will store the number of free space in KB.
     * @result Result of performed operation, @ref fm_result_t.
     */
    fm_result_t (*get_free)(
        fs_api_obj_t    api_obj,
        uint32_t *const p_out_kb_size);
} fs_api_t;

#endif // FM_MNG_DEF_H
