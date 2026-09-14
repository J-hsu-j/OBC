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
 * @file ff_mng.c
 *
 * @brief Manages interface between fatfs and other obc sw modules
 *
 * @}
 */

#include "fatfs.h"
#include "assertions.h"
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include "ff_mng.h"
#include "fm_common_def.h"
#include "ff.h"
#include "diskio.h"
#include "trace.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

/**
 * @brief Maximum number of simultaneous api usage
 */
#define FF_MAX_API_USE (FF_FS_LOCK * 2)

/**
 * @brief The combination all possible mode bits. Not a valid value.
 */
#define FF_MODE_MASK (FM_MODE_READ | FM_MODE_WRITE | FM_MODE_OPEN_EXISTING | FM_MODE_CREATE_NEW | FM_MODE_CREATE_ALWAYS | FM_MODE_OPEN_ALWAYS | FM_MODE_OPEN_APPEND)

/**
 * @brief The combination of all possible open modes.
 */
#define FF_MODE_OPEN_MASK (FM_MODE_CREATE_NEW | FM_MODE_CREATE_ALWAYS | FM_MODE_OPEN_ALWAYS | FM_MODE_OPEN_APPEND)

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

/**
 * @brief FATFS manager object
 */
typedef struct
{
    FATFS                   fat;         /**> FATFS object */
    const fm_storage_api_t *p_drv_api;   /**> storage driver api */
    osMutexId_t             lock;        /**> control access for api use counter */
    int8_t                  api_use;     /**> use count for non-format and non-mount api calls */
    int8_t                  fat_use;     /**> use count for format and mount api calls */
    int8_t                  max_api_use; /**> the maximum number of simultaneous api usage */
    int8_t                  max_fat_use; /**> the maximum number of simultaneous fat usage */
} ff_mng_t;

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/**
 * @brief Default FATFS manager object
 */
static ff_mng_t default_ff_mng = { 0 };

/**
 * @brief Default API interface function list object
 */
static const fs_api_t default_api;

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/

/**
 * @brief Increment the api use counter.
 */
static inline bool inc_api_use(ff_mng_t *p_mng);

/**
 * @brief Decrement the api use counter.
 */
static inline void dec_api_use(ff_mng_t *p_mng);

/**
 * @brief Increment the fat use counter.
 */
static inline void inc_fat_use(ff_mng_t *p_mng);

/**
 * @brief Decrement the fat use counter.
 */
static inline void dec_fat_use(ff_mng_t *p_mng);

/**
 * @brief Check the mode.
 * @param[in] mode The mode to be checked.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t check_open_mode(const uint32_t mode);

/**
 * @brief Open a file.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in,out] handle The file handle object. File object is initialised in a successful call.
 * @param[in] p_in_path The path to the file.
 * @param[in] mode The mode to open the file.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_open(fs_api_obj_t api_obj, handle_obj_t handle, const char *const p_in_path, const uint32_t mode);

/**
 * @brief Close a file.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] handle The file handle object.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_close(fs_api_obj_t api_obj, handle_obj_t handle);

/**
 * @brief Read a line delimited by '\\n'.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] handle The file handle object.
 * @param[out] p_out_buff The buffer to store the read line.
 * @param[in] buffer_size The size of the buffer.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_gets(
    fs_api_obj_t   api_obj,
    handle_obj_t   handle,
    void *const    p_out_buff,
    const uint32_t buffer_size);

/**
 * @brief Read data from the file.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] handle The file handle object.
 * @param[out] p_out_buff The buffer to store the read data.
 * @param[in] bytes_to_read The number of bytes to read.
 * @param[out] p_out_bytes_read The number of bytes actually read. May be NULL.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_read(
    fs_api_obj_t    api_obj,
    handle_obj_t    handle,
    void *const     p_out_buff,
    const uint32_t  bytes_to_read,
    uint32_t *const p_out_bytes_read);

/**
 * @brief Write data to the file.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] handle The file handle object.
 * @param[in] p_in_buff The buffer containing the data to write.
 * @param[in] bytes_to_write The number of bytes to write.
 * @param[out] p_out_bytes_written The number of bytes actually written. May be NULL.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_write(
    fs_api_obj_t      api_obj,
    handle_obj_t      handle,
    const void *const p_in_buff,
    const uint32_t    btw,
    uint32_t *const   p_out_bytes_written);

/**
 * @brief Write a formatted string to the file.
 * @details Supported specifiers: %%d, %%u, %%x, %%o, %%b, %%c, %%s.
 * @details Supported modifiers: width (both fixed and parametrized (e.g. '%.*d')), padding (space ' ' and zero '0'), left/right justification ('-'), integer size ('l')
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] handle The file handle object.
 * @param[out] p_out_bytes_written The number of bytes actually written. May be NULL.
 * @param[in] p_in_fmt The format string.
 * @param[in] ... The format arguments.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_printf(fs_api_obj_t api_obj, handle_obj_t handle, uint32_t *const p_out_bytes_written, const char *const p_in_fmt, ...);

/**
 * @brief Write initialized varargs to an opened file at the current positon.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] handle The file handle object.
 * @param[out] p_out_bytes_written The number of bytes actually written. May be NULL.
 * @param[in] p_in_fmt The format string.
 * @param[in] ap The initialized varargs.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_vprintf(fs_api_obj_t api_obj, handle_obj_t handle, uint32_t *const p_out_bytes_written, const char *const p_in_fmt, va_list ap);

/**
 * @brief Truncate the file to current position.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] handle The file handle object.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_truncate(fs_api_obj_t api_obj, handle_obj_t handle);

/**
 * @brief Get the size of the opened file.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] handle The file handle object.
 * @param[out] p_out_size Pointer to the value which will store the size of the file.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_size(fs_api_obj_t api_obj, c_handle_obj_t handle, uint32_t *const p_out_size);

/**
 * @brief Get the current file pointer position.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] handle The file handle object.
 * @param[out] p_out_pos Pointer to the value which will store the current file pointer position.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_tell(fs_api_obj_t api_obj, c_handle_obj_t handle, uint32_t *const p_out_pos);

/**
 * @brief Move the file pointer of the file object.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] handle The file handle object.
 * @param[in] pos The new position of the file pointer. This value is absolute, not relative.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_seek(fs_api_obj_t api_obj, handle_obj_t handle, const uint32_t pos);

/**
 * @brief Flush cached data of the writing file.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] handle The file handle object.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_sync(fs_api_obj_t api_obj, handle_obj_t handle);

/**
 * @brief Get file status.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] p_in_path The path to the file.
 * @param[out] p_out_tfi Pointer to the file status structure.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_stat(fs_api_obj_t api_obj, const char *p_in_path, fm_fast_file_info_t *const p_out_tfi);

/**
 * @brief Rename/Move a file or directory.
 * @details The function will fail if the new file exists.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] p_in_path_old The old path to the file or directory.
 * @param[in] p_in_path_new The new path to the file or directory.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_rename(fs_api_obj_t api_obj, const char *const p_in_path_old, const char *const p_in_path_new);

/**
 * @brief Delete a file or directory.
 * @details The function will fail if the file is open.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] p_in_path The path to the file.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_delete(fs_api_obj_t api_obj, const char *const p_in_path);

/**
 * @brief Create a directory.
 * @details The function will fail if the directory exists.
 * @details Intermediate directories are not created if they do not exist, so the function will fail if this is the case.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] p_in_path The path to the directory.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_mkdir(fs_api_obj_t api_obj, const char *const p_in_path);

/**
 * @brief Iterate through all files in directory without recursion.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] p_in_start_path The path to the directory.
 * @param[in] p_in_glob The glob pattern to match.
 * @param[in] handler The handler function to call for each file. See @ref fm_forech_handler_t for details.
 * @param[in,out] p_inout_user_data The user data to pass to the handler function.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_foreach_flat(
    fs_api_obj_t               api_obj,
    const char *const          p_in_start_path,
    const char *const          p_in_glob,
    const fm_foreach_handler_t handler,
    void *const                p_inout_user_data);

/**
 * @brief Open a directory object.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] handle The file handle object.
 * @param[in] p_in_path The path to the directory.
 * @param[in] p_in_glob The glob pattern to match.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_dir_open(
    fs_api_obj_t      api_obj,
    handle_obj_t      handle,
    const char *const p_in_path,
    const char *const p_in_glob);

/**
 * @brief Get the next item in the directory.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] handle The directory handle object.
 * @param[out] p_out_ffi Pointer to the file info structure.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_dir_next(fs_api_obj_t api_obj, handle_obj_t handle, fm_file_info_t *const p_out_ffi);

/**
 * @brief Close the directory object.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] handle The directory handle object.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_dir_close(fs_api_obj_t api_obj, handle_obj_t handle);

/**
 * @brief Mount/Unmount a logical drive.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[in] mount The mount flag. If true, the function will mount the drive. If false, the function will unmount the drive.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_mount(fs_api_obj_t api_obj, const bool mount);

/**
 * @brief Create a FAT volume.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @return Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_format(fs_api_obj_t api_obj);

/**
 * @brief Get the number of free space in KB for a file system.
 * @details This function is internal to the file_tools library. It should not be called outside file_tools.
 * @param[in] api_obj The file system api object.
 * @param[out] p_out_kb_size Pointer to the value which will store the number of free space in KB.
 * @result Result of performed operation, @ref fm_result_t.
 */
static fm_result_t ff_get_free(fs_api_obj_t api_obj, uint32_t *const p_out_kb_size);

/**
 * @brief Initialization of the default constant API list.
 */
static const fs_api_t default_api = {
    .open     = &ff_open,
    .close    = &ff_close,
    .xgets    = &ff_gets,
    .read     = &ff_read,
    .write    = &ff_write,
    .xprintf  = &ff_printf,
    .vprintf  = &ff_vprintf,
    .truncate = &ff_truncate,
    .size     = &ff_size,
    .tell     = &ff_tell,
    .seek     = &ff_seek,
    .sync     = &ff_sync,

    .stat   = &ff_stat,
    .rename = &ff_rename,
    .delete = &ff_delete,
    .mkdir  = &ff_mkdir,

    .foreach_flat = &ff_foreach_flat,
    .dir_open     = &ff_dir_open,
    .dir_next     = &ff_dir_next,
    .dir_close    = &ff_dir_close,

    .mount    = &ff_mount,
    .format   = &ff_format,
    .get_free = &ff_get_free
};

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

void ff_init(void)
{
    // A lot of the enums and constants used by file_tools are parallel to the ones in ff.h for FATFS, so we need to make sure they match
    static_assert(FM_RES_OK == (fm_result_t)FR_OK, "FM_RES_OK must be equal to FR_OK");
    static_assert(FM_RES_DISK_ERR == (fm_result_t)FR_DISK_ERR, "FM_RES_DISK_ERR must be equal to FR_DISK_ERR");
    static_assert(FM_RES_INT_ERR == (fm_result_t)FR_INT_ERR, "FM_RES_INT_ERR must be equal to FR_INT_ERR");
    static_assert(FM_RES_NOT_READY == (fm_result_t)FR_NOT_READY, "FM_RES_NOT_READY must be equal to FR_NOT_READY");
    static_assert(FM_RES_NO_FILE == (fm_result_t)FR_NO_FILE, "FM_RES_NO_FILE must be equal to FR_NO_FILE");
    static_assert(FM_RES_NO_PATH == (fm_result_t)FR_NO_PATH, "FM_RES_NO_PATH must be equal to FR_NO_PATH");
    static_assert(FM_RES_INVALID_NAME == (fm_result_t)FR_INVALID_NAME, "FM_RES_INVALID_NAME must be equal to FR_INVALID_NAME");
    static_assert(FM_RES_DENIED == (fm_result_t)FR_DENIED, "FM_RES_DENIED must be equal to FR_DENIED");
    static_assert(FM_RES_EXIST == (fm_result_t)FR_EXIST, "FM_RES_EXIST must be equal to FR_EXIST");
    static_assert(FM_RES_INVALID_OBJECT == (fm_result_t)FR_INVALID_OBJECT, "FM_RES_INVALID_OBJECT must be equal to FR_INVALID_OBJECT");
    static_assert(FM_RES_WRITE_PROTECTED == (fm_result_t)FR_WRITE_PROTECTED, "FM_RES_WRITE_PROTECTED must be equal to FR_WRITE_PROTECTED");
    static_assert(FM_RES_NOT_ENABLED == (fm_result_t)FR_NOT_ENABLED, "FM_RES_NOT_ENABLED must be equal to FR_NOT_ENABLED");
    static_assert(FM_RES_NO_FILESYSTEM == (fm_result_t)FR_NO_FILESYSTEM, "FM_RES_NO_FILESYSTEM must be equal to FR_NO_FILESYSTEM");
    static_assert(FM_RES_MKFS_ABORTED == (fm_result_t)FR_MKFS_ABORTED, "FM_RES_MKFS_ABORTED must be equal to FR_MKFS_ABORTED");
    static_assert(FM_RES_TIMEOUT == (fm_result_t)FR_TIMEOUT, "FM_RES_TIMEOUT must be equal to FR_TIMEOUT");
    static_assert(FM_RES_LOCKED == (fm_result_t)FR_LOCKED, "FM_RES_LOCKED must be equal to FR_LOCKED");
    static_assert(FM_RES_NOT_ENOUGH_CORE == (fm_result_t)FR_NOT_ENOUGH_CORE, "FM_RES_NOT_ENOUGH_CORE must be equal to FR_NOT_ENOUGH_CORE");
    static_assert(FM_RES_TOO_MANY_OPEN_FILES == (fm_result_t)FR_TOO_MANY_OPEN_FILES, "FM_RES_TOO_MANY_OPEN_FILES must be equal to FR_TOO_MANY_OPEN_FILES");
    static_assert(FM_RES_INVALID_PARAMETER == (fm_result_t)FR_INVALID_PARAMETER, "FM_RES_INVALID_PARAMETER must be equal to FR_INVALID_PARAMETER");

    static_assert(sizeof(uint32_t) == sizeof(UINT), "if size of integer params in interface and ff.h differ, code must be adjusted");
    static_assert(FM_MAX_PATH == FF_LFN_BUF, "FM_MAX_PATH and FF_LFN_BUF must be the same size");
    static_assert(FM_MAX_PATH == FF_MAX_LFN, "FM_MAX_PATH and FF_MAX_LFN must be the same size");
    static_assert(FM_MODE_READ == (fm_mode_t)FA_READ, "Value of FM_MODE_READ must match FA_READ");
    static_assert(FM_MODE_WRITE == (fm_mode_t)FA_WRITE, "Value of FM_MODE_WRITE must match FA_WRITE");
    static_assert(FM_MODE_OPEN_EXISTING == (fm_mode_t)FA_OPEN_EXISTING, "Value of FM_MODE_OPEN_EXISTING must match FA_OPEN_EXISTING");
    static_assert(FM_MODE_CREATE_NEW == (fm_mode_t)FA_CREATE_NEW, "Value of FM_MODE_CREATE_NEW must match FA_CREATE_NEW");
    static_assert(FM_MODE_CREATE_ALWAYS == (fm_mode_t)FA_CREATE_ALWAYS, "Value of FM_MODE_CREATE_ALWAYS must match FA_CREATE_ALWAYS");
    static_assert(FM_MODE_OPEN_ALWAYS == (fm_mode_t)FA_OPEN_ALWAYS, "Value of FM_MODE_OPEN_ALWAYS must match FA_OPEN_ALWAYS");
    static_assert(FM_MODE_OPEN_APPEND == (fm_mode_t)FA_OPEN_APPEND, "Value of FM_MODE_OPEN_APPEND must match FA_OPEN_APPEND");

    static_assert(FM_DRES_OK == (fm_dresult_t)RES_OK, "Value of FM_DRES_OK must match RES_OK");
    static_assert(FM_DRES_ERROR == (fm_dresult_t)RES_ERROR, "Value of FM_DRES_ERROR must match RES_ERROR");
    static_assert(FM_DRES_WRPRT == (fm_dresult_t)RES_WRPRT, "Value of FM_DRES_WRPRT must match RES_WRPRT");
    static_assert(FM_DRES_NOTRDY == (fm_dresult_t)RES_NOTRDY, "Value of FM_DRES_NOTRDY must match RES_NOTRDY");
    static_assert(FM_DRES_PARERR == (fm_dresult_t)RES_PARERR, "Value of FM_DRES_PARERR must match RES_PARERR");

    static_assert(FM_DSTA_NOINIT == (fm_dstatus_t)STA_NOINIT, "Value of FM_DSTA_NOINIT must match STA_NOINIT");
    static_assert(FM_DSTA_NODISK == (fm_dstatus_t)STA_NODISK, "Value of FM_DSTA_NODISK must match STA_NODISK");
    static_assert(FM_DSTA_PROTECT == (fm_dstatus_t)STA_PROTECT, "Value of FM_DSTA_PROTECT must match STA_PROTECT");

    static_assert(FM_IOCTL_CTRL_SYNC == (fm_ioctl_cmd_t)CTRL_SYNC, "Value of FM_IOCTL_CTRL_SYNC must match CTRL_SYNC");
    static_assert(FM_IOCTL_GET_SECTOR_COUNT == (fm_ioctl_cmd_t)GET_SECTOR_COUNT, "Value of FM_IOCTL_GET_SECTOR_COUNT must match GET_SECTOR_COUNT");
    static_assert(FM_IOCTL_GET_SECTOR_SIZE == (fm_ioctl_cmd_t)GET_SECTOR_SIZE, "Value of FM_IOCTL_GET_SECTOR_SIZE must match GET_SECTOR_SIZE");
    static_assert(FM_IOCTL_GET_BLOCK_SIZE == (fm_ioctl_cmd_t)GET_BLOCK_SIZE, "Value of FM_IOCTL_GET_BLOCK_SIZE must match GET_BLOCK_SIZE");
    static_assert(FM_IOCTL_CTRL_TRIM == (fm_ioctl_cmd_t)CTRL_TRIM, "Value of FM_IOCTL_CTRL_TRIM must match CTRL_TRIM");
    static_assert(FM_IOCTL_INIT == (fm_ioctl_cmd_t)IOCTL_INIT, "Value of FM_IOCTL_INIT must match IOCTL_INIT");
    static_assert(FM_IOCTL_STATUS == (fm_ioctl_cmd_t)IOCTL_STATUS, "Value of FM_IOCTL_STATUS must match IOCTL_STATUS");

    static_assert(FM_ATTR_DIR == AM_DIR, "FM_ATTR_DIR must mirror AM_DIR");

    (void)memset(&default_ff_mng, 0, sizeof(default_ff_mng));
    osMutexAttr_t mutex_attr = { 0 };
    mutex_attr.attr_bits     = osMutexRecursive | osMutexPrioInherit;
    default_ff_mng.lock      = osMutexNew(&mutex_attr);
}

void ff_set_driver(const fs_api_obj_t api_obj, const fm_storage_api_t *const p_in_drv)
{
    ff_mng_t *p_mng  = (ff_mng_t *)api_obj;
    p_mng->p_drv_api = p_in_drv;
    p_mng->fat.drv   = (void *)p_in_drv;
}

void ff_get_default_api_and_obj(fs_api_obj_t *const p_out_api_obj, const fs_api_t **const p_out_api)
{
    *p_out_api_obj = &default_ff_mng;
    *p_out_api     = &default_api;
}

/**
 *
 */
DRESULT disk_read(void *p_drv, BYTE *p_buff, DWORD sector, UINT count)
{
    fm_dresult_t            ret = FM_DRES_ERROR;
    const fm_storage_api_t *io;
    io = (const fm_storage_api_t *)p_drv;
    if (NULL != io)
    {
        ret = io->storage_read(p_buff, sector, count);
    }
    return (DRESULT)ret;
}

DRESULT disk_write(void *p_drv, const BYTE *p_buff, DWORD sector, UINT count)
{
    fm_dresult_t            ret = FM_DRES_ERROR;
    const fm_storage_api_t *io;
    io = (const fm_storage_api_t *)p_drv;
    if (NULL != io)
    {
        ret = io->storage_write(p_buff, sector, count);
    }
    return (DRESULT)ret;
}

DRESULT disk_ioctl(void *p_drv, BYTE cmd, void *p_buff)
{
    fm_dresult_t            ret = FM_DRES_ERROR;
    const fm_storage_api_t *io;
    io = (const fm_storage_api_t *)p_drv;
    if (NULL != io)
    {
        ret = io->storage_ioctl(cmd, p_buff);
    }
    return (DRESULT)ret;
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

static void ff_lock(fs_api_obj_t api_obj)
{
    ff_mng_t *p_mng = (ff_mng_t *)api_obj;
    BREAK_ASSERT(NULL != p_mng);
    BREAK_ASSERT(NULL != p_mng->lock);
    (void)osMutexAcquire(p_mng->lock, osWaitForever);
}

static void ff_unlock(fs_api_obj_t api_obj)
{
    ff_mng_t *p_mng = (ff_mng_t *)api_obj;
    BREAK_ASSERT(NULL != p_mng);
    BREAK_ASSERT(NULL != p_mng->lock);
    (void)osMutexRelease(p_mng->lock);
}

static inline bool inc_api_use(ff_mng_t *p_mng)
{
    bool ret = false;
    ff_lock(p_mng);
    while (true)
    {
        int8_t fat_use = p_mng->fat_use;
        if ((0 == fat_use) // do not increase file use until fs use is done, to prevent dead-lock
            && (NULL != p_mng->fat.sobj))
        {
            ++p_mng->api_use; // fs use is done, we lock
            ret = true;
            if (p_mng->api_use > p_mng->max_api_use)
            {
                p_mng->max_api_use = p_mng->api_use;
                CRIT_ASSERT(FF_MAX_API_USE >= p_mng->max_api_use);
            }
        }
        if (0 == fat_use)
        {
            break;
        }
        ff_unlock(p_mng);
        osThreadYield();
        ff_lock(p_mng);
    }
    ff_unlock(p_mng);
    return ret;
}

static inline void dec_api_use(ff_mng_t *p_mng)
{
    ff_lock(p_mng);
    --p_mng->api_use;
    CRIT_ASSERT(0 <= p_mng->api_use);
    ff_unlock(p_mng);
}

static inline void inc_fat_use(ff_mng_t *p_mng)
{
    ff_lock(p_mng);
    // we increase fat object use preemptevely to prevent increase in api use
    ++p_mng->fat_use;
    if (p_mng->fat_use > p_mng->max_fat_use)
    {
        p_mng->max_fat_use = p_mng->fat_use;
        CRIT_ASSERT(FF_MAX_API_USE >= p_mng->max_fat_use);
    }

    while (true)
    {
        if (0 < p_mng->api_use) // when fat_use > 0, api_use can only decrease, preventing a live-lock
        {
            ff_unlock(p_mng);
            osThreadYield();
        }
        else
        {
            // all file operations are finished, we can rework the FAT object
            break;
        }
        ff_lock(p_mng);
    }
    ff_unlock(p_mng);
}

static inline void dec_fat_use(ff_mng_t *p_mng)
{
    ff_lock(p_mng);
    --p_mng->fat_use;
    CRIT_ASSERT(0 <= p_mng->fat_use);
    ff_unlock(p_mng);
}

static fm_result_t check_open_mode(const uint32_t mode)
{
    if (0 != (mode & ~((uint32_t)FF_MODE_MASK)))
    {
        return FM_RES_INVALID_PARAMETER;
    }
    uint32_t open_mode = mode & FF_MODE_OPEN_MASK;
    switch (open_mode)
    {
        case FM_MODE_OPEN_EXISTING:
        case FM_MODE_CREATE_NEW:
        case FM_MODE_CREATE_ALWAYS:
        case FM_MODE_OPEN_ALWAYS:
        case FM_MODE_OPEN_APPEND:
            break;
        default:
            return FM_RES_INVALID_PARAMETER;
    }
    return FM_RES_OK;
}

static fm_result_t ff_open(fs_api_obj_t api_obj, handle_obj_t handle, const char *const p_in_path, const uint32_t mode)
{
    fm_result_t ret;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    if (FM_RES_OK == (ret = check_open_mode(mode)))
    {
        ret = (fm_result_t)f_open(&p_mng->fat, (FIL *)handle, p_in_path, (const BYTE)mode);
        if (ret != FM_RES_OK)
        {
            ES_TRACE_DEBUG("Could not open path '%s', error %d '%s'", p_in_path, ret, fm_result_to_str(ret));
        }
    }
    else
    {
        ES_TRACE_DEBUG("Invalid open mode 0x%02X, error %d '%s'", mode, ret, fm_result_to_str(ret));
    }

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_close(fs_api_obj_t api_obj, handle_obj_t handle)
{
    fm_result_t ret;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    ret = (fm_result_t)f_close((FIL *)handle);

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_gets(
    fs_api_obj_t   api_obj,
    handle_obj_t   handle,
    void *const    p_out_buff,
    const uint32_t buffer_size)
{
    fm_result_t ret;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;
    FIL        *fp;

    if (buffer_size > INT_MAX)
    {
        return FM_RES_INVALID_PARAMETER;
    }

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }
    fp = (FIL *)handle;

    f_gets(p_out_buff, (int)buffer_size, fp);
    ret = fp->err;

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_read(
    fs_api_obj_t    api_obj,
    handle_obj_t    handle,
    void *const     p_out_buff,
    const uint32_t  bytes_to_read,
    uint32_t *const p_out_bytes_read)
{
    fm_result_t ret;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    ret = (fm_result_t)f_read((FIL *)handle, p_out_buff, (UINT)bytes_to_read, (UINT *)p_out_bytes_read);

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_write(
    fs_api_obj_t      api_obj,
    handle_obj_t      handle,
    const void *const p_in_buff,
    const uint32_t    bytes_to_write,
    uint32_t *const   p_out_bytes_written)
{
    fm_result_t ret;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;
    static_assert(sizeof(uint32_t) == sizeof(UINT), "if size of integer params in interface and ff.h differ, code must be adjusted");

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    ret = (fm_result_t)f_write((FIL *)handle, p_in_buff, (UINT)bytes_to_write, (UINT *)p_out_bytes_written);

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_printf(fs_api_obj_t api_obj, handle_obj_t handle, uint32_t *const p_out_bytes_written, const char *const p_in_fmt, ...)
{
    fm_result_t ret;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;
    FIL        *p_fil = (FIL *)handle;
    va_list     ap;
    int         bytes_written;

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    va_start(ap, p_in_fmt);
    bytes_written = f_vprintf(p_fil, p_in_fmt, ap);
    va_end(ap);
    ret = p_fil->err;

    *p_out_bytes_written = (bytes_written > 0) ? (uint32_t)bytes_written : 0;

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_vprintf(fs_api_obj_t api_obj, handle_obj_t handle, uint32_t *const p_out_bytes_written, const char *const p_in_fmt, va_list ap)
{
    fm_result_t ret;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;
    FIL        *p_fil = (FIL *)handle;
    int         bytes_written;

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    bytes_written = f_vprintf(p_fil, p_in_fmt, ap);
    ret           = p_fil->err;

    *p_out_bytes_written = (bytes_written > 0) ? (uint32_t)bytes_written : 0;

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_truncate(fs_api_obj_t api_obj, handle_obj_t handle)
{
    fm_result_t ret;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    ret = (fm_result_t)f_truncate((FIL *)handle);

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_size(fs_api_obj_t api_obj, c_handle_obj_t handle, uint32_t *const p_out_size)
{
    fm_result_t ret   = FM_RES_INVALID_PARAMETER;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;
    static_assert(sizeof(uint32_t) == sizeof(FSIZE_t), "if size of integer params in interface and ff.h differ, code must be adjusted");

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    *p_out_size = f_size((const FIL *)handle);
    ret         = FM_RES_OK;

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_tell(fs_api_obj_t api_obj, c_handle_obj_t handle, uint32_t *const p_out_pos)
{
    fm_result_t ret;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;
    static_assert(sizeof(uint32_t) == sizeof(FSIZE_t), "if size of integer params in interface and ff.h differ, code must be adjusted");

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    *p_out_pos = f_tell((const FIL *)handle);
    ret        = FM_RES_OK;

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_seek(fs_api_obj_t api_obj, handle_obj_t handle, const uint32_t pos)
{
    fm_result_t ret;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;
    static_assert(sizeof(uint32_t) == sizeof(FSIZE_t), "if size of integer params in interface and ff.h differ, code must be adjusted");

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    ret = (fm_result_t)f_lseek((FIL *)handle, pos);

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_sync(fs_api_obj_t api_obj, handle_obj_t handle)
{
    fm_result_t ret;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    ret = (fm_result_t)f_sync((FIL *)handle);

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_stat(fs_api_obj_t api_obj, const char *p_in_path, fm_fast_file_info_t *const p_out_tfi)
{
    fm_result_t ret;
    FILINFO     fno;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    ret = (fm_result_t)f_stat(&p_mng->fat, p_in_path, &fno);

    if ((FM_RES_OK == ret) && (NULL != p_out_tfi))
    {
        memset(p_out_tfi, 0, sizeof(*p_out_tfi));
        p_out_tfi->attr       = fno.fattrib;
        p_out_tfi->size       = fno.fsize;
        p_out_tfi->unix_mtime = fattime_to_unix(fno.fdate, fno.ftime);
    }

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_rename(fs_api_obj_t api_obj, const char *const p_in_path_old, const char *const p_in_path_new)
{
    fm_result_t ret;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    ret = (fm_result_t)f_rename(&p_mng->fat, p_in_path_old, p_in_path_new);

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_delete(fs_api_obj_t api_obj, const char *const p_in_path)
{
    fm_result_t ret;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    ret = (fm_result_t)f_unlink(&p_mng->fat, p_in_path);

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_mkdir(fs_api_obj_t api_obj, const char *const p_in_path)
{
    fm_result_t ret;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    ret = (fm_result_t)f_mkdir(&p_mng->fat, p_in_path);

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_foreach_flat(
    fs_api_obj_t               api_obj,
    const char *const          p_in_start_path,
    const char *const          p_in_glob,
    const fm_foreach_handler_t handler,
    void *const                p_inout_user_data)
{
    fm_result_t ret   = FM_RES_INVALID_PARAMETER;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;
    FF_DIR      dir;
    FILINFO     finfo;

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    ret = (fm_result_t)f_findfirst(&p_mng->fat, &dir, &finfo, p_in_start_path, p_in_glob);

    while ((FM_RES_OK == ret) && (TERMINATING_ZERO_CHAR != finfo.fname[0]))
    {
        fm_fast_file_info_t tfi;
        tfi.attr       = finfo.fattrib;
        tfi.p_name     = finfo.fname;
        tfi.p_path     = p_in_start_path;
        tfi.size       = finfo.fsize;
        tfi.unix_mtime = fattime_to_unix(finfo.fdate, finfo.ftime);
        ret            = handler(&tfi, p_inout_user_data);
        if (FM_RES_OK != ret)
        {
            break;
        }

        ret = (fm_result_t)f_findnext(&dir, &finfo);
    }

    (void)f_closedir(&dir);

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_dir_open(
    fs_api_obj_t      api_obj,
    handle_obj_t      handle,
    const char *const p_in_path,
    const char *const p_in_glob)
{
    fm_result_t ret;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    FF_DIR *dir = (FF_DIR *)handle;
    dir->pat    = p_in_glob;
    ret         = (fm_result_t)f_opendir(&p_mng->fat, dir, p_in_path);

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_dir_next(fs_api_obj_t api_obj, handle_obj_t handle, fm_file_info_t *const p_out_ffi)
{
    fm_result_t ret;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;
    FILINFO     fno;

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    ret = (fm_result_t)f_findnext((FF_DIR *)handle, &fno);
    if (FM_RES_OK == ret)
    {
        if (sizeof(p_out_ffi->full_path) <= strnlen(fno.fname, sizeof(p_out_ffi->full_path)))
        {
            ret = FM_RES_INVALID_NAME;
        }
        strncpy(p_out_ffi->full_path, fno.fname, sizeof(p_out_ffi->full_path) - 1);
        p_out_ffi->full_path[sizeof(p_out_ffi->full_path) - 1] = TERMINATING_ZERO_CHAR;
        p_out_ffi->attr                                        = fno.fattrib;
        p_out_ffi->size                                        = fno.fsize;
        p_out_ffi->unix_mtime                                  = fattime_to_unix(fno.fdate, fno.ftime);
    }

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_dir_close(fs_api_obj_t api_obj, handle_obj_t handle)
{
    fm_result_t ret;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    ret = (fm_result_t)f_closedir((FF_DIR *)handle);

    dec_api_use(p_mng);

    return ret;
}

static fm_result_t ff_mount(fs_api_obj_t api_obj, const bool mount)
{
    fm_result_t ret   = FM_RES_OK;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;

    inc_fat_use(p_mng);

    if ((true == mount) && (NULL == p_mng->fat.sobj))
    {
        ret = (fm_result_t)f_mount(&p_mng->fat);
    }
    else if ((false == mount) && (NULL != p_mng->fat.sobj))
    {
        ret             = (fm_result_t)f_umount(&p_mng->fat);
        p_mng->fat.sobj = NULL;
    }
    else
    {
        // SonarQube requires an ``else`` statement after the final ``else if``
    }

    dec_fat_use(p_mng);

    return ret;
}

static fm_result_t ff_format(fs_api_obj_t api_obj)
{
    fm_result_t ret   = FM_RES_DISK_ERR;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;
    uint32_t    sector_size;

    inc_fat_use(p_mng); // blocks new calls to use the FAT object

    ff_mount(p_mng, false);

    (void)memset(&p_mng->fat, 0, sizeof(p_mng->fat));

    p_mng->fat.drv = (void *)p_mng->p_drv_api;
    if (FM_DRES_OK == p_mng->p_drv_api->storage_ioctl(GET_SECTOR_SIZE, &sector_size))
    {
        void *format_buffer = ff_malloc(sector_size);
        ret                 = FM_RES_NOT_ENOUGH_CORE;
        if (NULL != format_buffer)
        {
            fm_dresult_t dres;
            ret  = (fm_result_t)f_mkfs(&p_mng->fat, FM_FAT32, 0, format_buffer, sector_size);
            dres = p_mng->p_drv_api->storage_ioctl(CTRL_SYNC, NULL);
            ff_free(format_buffer);
            if ((FM_RES_OK == ret) && (FM_DRES_OK == dres))
            {
                ret  = ff_mount(p_mng, true);
                dres = p_mng->p_drv_api->storage_ioctl(CTRL_SYNC, NULL);
            }
            if (FM_DRES_OK != dres)
            {
                ret = FM_RES_NOT_READY;
            }
        }
    }

    dec_fat_use(p_mng);

    return ret;
}

static fm_result_t ff_get_free(fs_api_obj_t api_obj, uint32_t *const p_out_kb_size)
{
    fm_result_t ret;
    ff_mng_t   *p_mng = (ff_mng_t *)api_obj;
    DWORD       nclst;
    uint32_t    sector_size;
    static_assert(sizeof(uint32_t) == sizeof(DWORD), "if size of integer params in interface and ff.h differ, code must be adjusted");

    if (false == inc_api_use(p_mng))
    {
        return FM_RES_NOT_READY;
    }

    ret = (fm_result_t)f_getfree(&p_mng->fat, &nclst);

    if (FM_RES_OK == ret)
    {
        if (FM_DRES_OK == p_mng->p_drv_api->storage_ioctl(GET_SECTOR_SIZE, &sector_size))
        {
            uint64_t safe_size;
            safe_size = p_mng->fat.csize;
            safe_size *= sector_size;
            safe_size >>= 10;
            safe_size *= nclst;
            *p_out_kb_size = ((1LLU << 32) > safe_size) ? (uint32_t)safe_size : 0xFFFFFFFFLU;
        }
        else
        {
            ret = FM_RES_DISK_ERR;
        }
    }

    dec_api_use(p_mng);

    return ret;
}
