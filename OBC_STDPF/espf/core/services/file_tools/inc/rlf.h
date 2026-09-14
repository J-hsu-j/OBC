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
 * @file rlf.h
 *
 * @brief Rolling write file.
 *  A simplified API to write to a series of files that are used as a circular buffer.
 *
 * @}
 *
 */

#ifndef RLF_H
#define RLF_H

#include "fm_mng.h"

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/**
 * @struct rlf_cfg_t
 * @brief Configuration for a rolling-buffer file.
 *
 * This structure is used to configure a rolling-buffer file.
 */
typedef struct
{
    uint32_t max_size;             /**< Maximum size of the rolling-buffer file in bytes. */
    char     pattern[FM_MAX_PATH]; /**< Name used as a template for the rolling file name. */
    uint8_t  pos_marker;           /**< Position of the marker character in the file name. */
    uint8_t  pos_index;            /**< Position of the index character in the file name. */
    uint8_t  max_count;            /**< Maximum number of preserved files before starting to erase old content. */
    char     marker_active;        /**< A file name ending with this character is the currently active file. */
    char     marker_inactive;      /**< File names ending with this character indicate older reports. */
} rlf_cfg_t;

/**
 * @struct rlf_ctx_t
 * @brief Context for a rolling-buffer file.
 *
 * This structure is used to manage the context of a rolling-buffer file.
 */
typedef struct
{
    const rlf_cfg_t *p_cfg;                    /**< Pointer to the configuration for the rolling-buffer file. */
    fm_handle_t      handle;                   /**< Handle to the rolling-buffer file. If use_internal_file_object is true, set this to the address of a fm_file_obj_t object */
    bool             use_internal_file_object; /**< Flag to indicate whether the file handle is use_internal_file_object. */
    char             filename[FM_MAX_PATH];    /**< Name of the rolling-buffer file. */
    uint8_t          current_index;            /**< Current index of the rolling-buffer file. */
    uint8_t          index_strlen;             /**< Current index of the rolling-buffer file. */
    bool             is_open;                  /**< Flag to indicate whether the file is open. */
} rlf_ctx_t;

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

/**
 * @brief Opens a rolling-buffer file for reading and writing.
 *
 * @param[in,out] p_ctx User-provided context to manage the file. It will be
 * initialized by the function.
 *
 * @return see @ref fm_result_t for details on possible error codes.
 */
fm_result_t rlf_open(rlf_ctx_t *const p_ctx);

/**
 * @brief Closes the rolling-buffer file.
 *
 * @param[in,out] p_ctx User-provided context to manage the file. It should have been
 * initialized by the @ref rlf_open function before use.
 *
 * @return see @ref fm_result_t for details on possible error codes.
 */
fm_result_t rlf_close(rlf_ctx_t *const p_ctx);

/**
 * @brief Writes data to the rolling-buffer file.
 * @note The function will write the data to the current file or the next one if the current file is full.
 *
 * @param[in]  p_ctx User-provided context to manage the file. It should have been
 * initialized by the @ref rlf_open function before use.
 * @param[in]  p_in_buff A pointer to the user buffer which contains the data to write.
 * @param[in]  bytes_to_write The number of bytes to write from the buffer to the file.
 * @param[out] p_out_bytes_written A pointer to a variable where the function will store the number of bytes actually written.
 *
 * @return see @ref fm_result_t for details on possible error codes.
 */
fm_result_t rlf_write(rlf_ctx_t *const p_ctx, const void *const p_in_buff, const uint32_t bytes_to_write, uint32_t *const p_out_bytes_written);

/**
 * @brief Same as @ref rlf_write but writes the whole buffer to current rlf file or next one without breaking it up.
 * @note Using this function instead of @ref rlf_write will fill the rlf file below their configured maximum size depending on the bytes_to_write param.
 *
 * @param[in]  p_ctx User-provided context to manage the file. It should have been
 * initialized by the @ref rlf_open function before use.
 * @param[in]  p_in_buff A pointer to the user buffer which contains the data to write.
 * @param[in]  bytes_to_write The number of bytes to write from the buffer to the file.
 * @param[out] p_out_bytes_written A pointer to a variable where the function will store the number of bytes actually written.
 *
 * @return see @ref fm_result_t for details on possible error codes.
 */
fm_result_t rlf_write_unbroken(rlf_ctx_t *const p_ctx, const void *const p_in_buff, const uint32_t bytes_to_write, uint32_t *const p_out_bytes_written);

#endif /* RLF_H */
