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
 * @file rlf.c
 *
 * @brief Implementation of the rolling write file.
 *
 * @}
 *
 */

#include "rlf.h"
#include "fm_mng.h"
#include "fm_common_def.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

/**
 * @brief This macro is used to return the lesser value of a calculated string size and the size of
 * the buffer that is supposed to contain the string after an sprintf operation.
 *
 * @param buf_len Size of the destination buffer
 * @param calc_len Calculated string size
 *
 * @note This macro cannot be replaced by a static inline function without compiler warnings.
 */
#define MIN_INDEX_STRLEN(buf_len, calc_len) (calc_len < buf_len ? calc_len : (buf_len - 1))

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/

static fm_result_t rlf_init(rlf_ctx_t *const p_ctx);
static fm_result_t rlf_next(rlf_ctx_t *const p_ctx);
static fm_result_t rlf_flush(rlf_ctx_t *const p_ctx, const void *const p_buff, const uint32_t bytes_to_write, uint32_t *const p_bytes_written);
static fm_result_t rlf_flush_unbroken(rlf_ctx_t *const p_ctx, const void *const p_buff, const uint32_t bytes_to_write, uint32_t *const p_bytes_written);
static fm_result_t rlf_write_internal(
    rlf_ctx_t *const  p_ctx,
    const void *const p_in_buff,
    const uint32_t    bytes_to_write,
    uint32_t *const   p_out_bytes_written,
    fm_result_t       (*rlf_flush_func)(rlf_ctx_t *const p_ctx, const void *const p_in_buff, const uint32_t total_bytes_to_write, uint32_t *const p_total_bytes_written));

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

fm_result_t rlf_open(rlf_ctx_t *const p_ctx)
{
    fm_result_t ret = FM_RES_INT_ERR;

    if (NULL != p_ctx)
    {
        if (false == p_ctx->is_open)
        {
            static_assert(sizeof(((rlf_cfg_t *)0)->max_count) <= 2, "The current algorithm in rlf does not expect large values for max_count");

            const rlf_cfg_t *p_cfg        = p_ctx->p_cfg;
            size_t           index_strlen = 1;
            for (uint32_t i = p_cfg->max_count - 1; i >= 10; i /= 10)
            {
                index_strlen++;
            }
            p_ctx->index_strlen = (uint8_t)index_strlen;

            uint32_t len = strnlen(p_cfg->pattern, sizeof(p_cfg->pattern));
            if (((p_cfg->pos_index > p_cfg->pos_marker) ||
                 (p_cfg->pos_index + index_strlen <= p_cfg->pos_marker)) &&
                (len >= p_cfg->pos_index + index_strlen) &&
                (len >= p_cfg->pos_marker))
            {
                ret            = rlf_init(p_ctx);
                p_ctx->is_open = (FM_RES_OK == ret);
            }
            else
            {
                ret = FM_RES_INVALID_PARAMETER;
            }
        }
        else
        {
            // the file is already opened.
            ret = FM_RES_OK;
        }
    }
    else
    {
        ret = FM_RES_INVALID_PARAMETER;
    }

    return ret;
}

fm_result_t rlf_close(rlf_ctx_t *const p_ctx)
{
    fm_result_t ret = FM_RES_INT_ERR;

    if (NULL != p_ctx)
    {
        if (p_ctx->is_open)
        {
            ret            = fm_close(p_ctx->handle);
            p_ctx->is_open = false;
        }
        else
        {
            ret = FM_RES_NO_FILE;
        }
    }
    else
    {
        ret = FM_RES_INVALID_PARAMETER;
    }

    return ret;
}

fm_result_t rlf_write(
    rlf_ctx_t *const  p_ctx,
    const void *const p_in_buff,
    const uint32_t    bytes_to_write,
    uint32_t *const   p_out_bytes_written)
{
    return rlf_write_internal(p_ctx, p_in_buff, bytes_to_write, p_out_bytes_written, rlf_flush);
}

fm_result_t rlf_write_unbroken(
    rlf_ctx_t *const  p_ctx,
    const void *const p_in_buff,
    const uint32_t    bytes_to_write,
    uint32_t *const   p_out_bytes_written)
{
    return rlf_write_internal(p_ctx, p_in_buff, bytes_to_write, p_out_bytes_written, rlf_flush_unbroken);
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

static fm_result_t rlf_init(rlf_ctx_t *const p_ctx)
{
    fm_result_t ret = FM_RES_INT_ERR;

    bool          has_free_slot = false;
    char          index_str[12];
    const uint8_t idx_len = MIN_INDEX_STRLEN(sizeof(index_str), p_ctx->index_strlen);

    // try to determine the next file name to use for writing...
    // the currently active file slot ends with an "marker_active", while older dumps end with an "marker_inactive"
    (void)strncpy(p_ctx->filename, p_ctx->p_cfg->pattern, sizeof(p_ctx->filename) - 1);
    p_ctx->filename[sizeof(p_ctx->filename) - 1] = TERMINATING_ZERO_CHAR;
    p_ctx->filename[p_ctx->p_cfg->pos_marker]    = p_ctx->p_cfg->marker_active;

    // first try with the current file index
    snprintf(index_str, sizeof(index_str), "%0*d", idx_len, p_ctx->current_index);
    memcpy(&p_ctx->filename[p_ctx->p_cfg->pos_index], index_str, p_ctx->index_strlen);

    ret = fm_stat(p_ctx->filename, NULL);
    if (FM_RES_OK == ret)
    {
        has_free_slot = true;
    }
    else
    {
        // if not found, try all possible file slots matching the given pattern, until a matching file is found
        for (uint8_t index = 0U; index < p_ctx->p_cfg->max_count; index++)
        {
            snprintf(index_str, sizeof(index_str), "%0*d", idx_len, index);
            memcpy(&p_ctx->filename[p_ctx->p_cfg->pos_index], index_str, p_ctx->index_strlen);

            ret = fm_stat(p_ctx->filename, NULL);
            if (FM_RES_OK == ret)
            {
                has_free_slot        = true;
                p_ctx->current_index = index;
                break;
            }
        }
    }

    // if no active slot found, use zero slot...
    if (!has_free_slot)
    {
        sprintf(index_str, "%0*d", p_ctx->index_strlen, 0);
        memcpy(&p_ctx->filename[p_ctx->p_cfg->pos_index], index_str, p_ctx->index_strlen);
    }

    if (true == p_ctx->use_internal_file_object)
    {
        ret = fm_open_internal(&p_ctx->handle, p_ctx->filename, FM_MODE_OPEN_APPEND | FM_MODE_READ | FM_MODE_WRITE);
    }
    else
    {
        ret = fm_open(p_ctx->handle, p_ctx->filename, FM_MODE_OPEN_APPEND | FM_MODE_READ | FM_MODE_WRITE);
    }

    return ret;
}

static fm_result_t rlf_next(rlf_ctx_t *const p_ctx)
{
    fm_result_t ret = FM_RES_INT_ERR;

    if (NULL != p_ctx)
    {
        if (true == p_ctx->is_open)
        {
            char file_name_temp[FM_MAX_PATH];

            (void)fm_close(p_ctx->handle);

            (void)strncpy(file_name_temp, p_ctx->filename, sizeof(file_name_temp) - 1);
            file_name_temp[sizeof(file_name_temp) - 1] = TERMINATING_ZERO_CHAR;

            // preserve the existing file under a different name
            file_name_temp[p_ctx->p_cfg->pos_marker] = p_ctx->p_cfg->marker_inactive;

            // delete any old dump with the same name...
            (void)fm_delete(file_name_temp);

            // rename current dump
            (void)fm_rename(p_ctx->filename, file_name_temp);

            p_ctx->current_index += 1U;
            p_ctx->current_index %= p_ctx->p_cfg->max_count;

            // move index position for new file and mark it as active
            char index_str[12];
            snprintf(index_str, sizeof(index_str), "%0*d", MIN_INDEX_STRLEN(sizeof(index_str), p_ctx->index_strlen), p_ctx->current_index);
            memcpy(&p_ctx->filename[p_ctx->p_cfg->pos_index], index_str, p_ctx->index_strlen);

            if (true == p_ctx->use_internal_file_object)
            {
                ret = fm_open_internal(&p_ctx->handle, p_ctx->filename, FM_MODE_CREATE_ALWAYS | FM_MODE_WRITE);
            }
            else
            {
                ret = fm_open(p_ctx->handle, p_ctx->filename, FM_MODE_CREATE_ALWAYS | FM_MODE_WRITE);
            }

            if (FM_RES_OK == ret)
            {
                p_ctx->is_open = true;
            }
        }
        else
        {
            ret = FM_RES_NO_FILE;
        }
    }
    else
    {
        ret = FM_RES_INVALID_PARAMETER;
    }

    return ret;
}

static fm_result_t rlf_flush(rlf_ctx_t *const p_ctx, const void *const p_in_buff, const uint32_t total_bytes_to_write, uint32_t *const p_total_bytes_written)
{
    fm_result_t    ret = FM_RES_INT_ERR;
    uint32_t       safe_p_total_bytes_written;
    uint32_t       safe_total_bytes_to_write;
    const uint8_t *p_buff;

    p_buff = (const uint8_t *)p_in_buff;

    safe_total_bytes_to_write  = total_bytes_to_write;
    safe_p_total_bytes_written = 0;

    do
    {
        uint32_t free_size;
        uint32_t size;
        uint32_t bytes_to_write = 0;
        uint32_t bytes_written  = 0;

        ret = fm_size(p_ctx->handle, &size);
        if (FM_RES_OK != ret)
        {
            break;
        }

        free_size = p_ctx->p_cfg->max_size - size;

        if (safe_total_bytes_to_write < free_size)
        {
            bytes_to_write = safe_total_bytes_to_write;
        }
        else
        {
            bytes_to_write = free_size;
        }

        ret = fm_write(p_ctx->handle, p_buff, bytes_to_write, &bytes_written);

        if (FM_RES_OK == ret)
        {
            safe_total_bytes_to_write -= bytes_written;
            p_buff += bytes_written;
            safe_p_total_bytes_written += bytes_written;

            if (safe_total_bytes_to_write > 0)
            {
                ret = rlf_next(p_ctx);
            }
        }
    } while ((safe_total_bytes_to_write != 0) && (ret == FM_RES_OK));

    if (NULL != p_total_bytes_written)
    {
        *p_total_bytes_written = safe_p_total_bytes_written;
    }

    return ret;
}

static fm_result_t rlf_flush_unbroken(rlf_ctx_t *const p_ctx, const void *const p_in_buff, const uint32_t total_bytes_to_write, uint32_t *const p_total_bytes_written)
{
    fm_result_t ret = FM_RES_OK;
    uint32_t    free_size;
    uint32_t    size;

    if (total_bytes_to_write > p_ctx->p_cfg->max_size)
    {
        ret = FM_RES_INVALID_PARAMETER;
    }

    if (FM_RES_OK == ret)
    {
        ret = fm_size(p_ctx->handle, &size);
    }

    if (FM_RES_OK == ret)
    {
        free_size = p_ctx->p_cfg->max_size - size;

        if (total_bytes_to_write > free_size)
        {
            ret = rlf_next(p_ctx);
        }
    }

    if (FM_RES_OK == ret)
    {
        ret = fm_write(p_ctx->handle, p_in_buff, total_bytes_to_write, p_total_bytes_written);
    }

    return ret;
}

static fm_result_t rlf_write_internal(
    rlf_ctx_t *const  p_ctx,
    const void *const p_in_buff,
    const uint32_t    bytes_to_write,
    uint32_t *const   p_out_bytes_written,
    fm_result_t       (*rlf_flush_func)(rlf_ctx_t *const p_ctx, const void *const p_in_buff, const uint32_t total_bytes_to_write, uint32_t *const p_total_bytes_written))
{
    fm_result_t ret = FM_RES_OK;

    if ((NULL != p_ctx) && (NULL != p_in_buff))
    {
        if (p_ctx->is_open)
        {
            // make sure that the file is not already full
            uint32_t size;
            ret = fm_size(p_ctx->handle, &size);
            if ((FM_RES_OK == ret) && (p_ctx->p_cfg->max_size <= size))
            {
                ret = rlf_next(p_ctx);
            }

            if (FM_RES_OK == ret)
            {
                // at this place most of the checks are already done so we can do the logic for writing.
                ret = rlf_flush_func(p_ctx, p_in_buff, bytes_to_write, p_out_bytes_written);
            }
        }
        else
        {
            ret = FM_RES_NO_FILE;
        }
    }
    else
    {
        ret = FM_RES_INVALID_PARAMETER;
    }

    return ret;
}
