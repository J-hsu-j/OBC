
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
 * @file stack_file.c
 *
 * @brief Implementation of the stack file tool.
 *
 * @}
 */

#include "stack_file.h"
#include <string.h>

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

fm_result_t stack_file_open(stack_file_ctx_t *const p_ctx)
{
    fm_result_t ret = FM_RES_INT_ERR;
    p_ctx->count    = 0U;

    if (true == p_ctx->use_internal_file_object)
    {
        ret = fm_open_internal(&p_ctx->handle, p_ctx->filename, FM_MODE_CREATE_ALWAYS | FM_MODE_READ | FM_MODE_WRITE);
    }
    else
    {
        ret = fm_open(p_ctx->handle, p_ctx->filename, FM_MODE_CREATE_ALWAYS | FM_MODE_READ | FM_MODE_WRITE);
    }
    return ret;
}

fm_result_t stack_file_push(stack_file_ctx_t *const p_ctx, const void *const p_elem)
{
    fm_result_t ret = FM_RES_INVALID_PARAMETER;

    uint32_t pos           = p_ctx->elem_size * p_ctx->count;
    uint32_t bytes_written = 0U;

    ret = fm_write_at_pos(p_ctx->handle, p_elem, p_ctx->elem_size, &bytes_written, pos);

    if (FM_RES_OK == ret)
    {
        if (bytes_written == p_ctx->elem_size)
        {
            ++(p_ctx->count);
        }
        else
        {
            ret = FM_RES_INT_ERR;
        }
    }

    return ret;
}

fm_result_t stack_file_pop(stack_file_ctx_t *p_ctx, void *const p_elem)
{
    fm_result_t ret = FM_RES_INVALID_PARAMETER;

    if (0 == p_ctx->count)
    {
        return ret;
    }

    uint32_t pos        = (p_ctx->count - 1) * p_ctx->elem_size;
    uint32_t bytes_read = 0U;

    ret = fm_read_at_pos(p_ctx->handle, p_elem, p_ctx->elem_size, &bytes_read, pos);

    if (FM_RES_OK == ret)
    {
        if (bytes_read == p_ctx->elem_size)
        {
            --(p_ctx->count);
        }
        else
        {
            ret = FM_RES_INT_ERR;
        }
    }

    return ret;
}

uint32_t stack_file_count(const stack_file_ctx_t *const p_ctx)
{
    return (NULL != p_ctx) ? p_ctx->count : 0;
}

fm_result_t stack_file_close(stack_file_ctx_t *const p_ctx, const bool delete)
{
    fm_result_t ret = FM_RES_INVALID_PARAMETER;

    if (NULL != p_ctx)
    {
        ret = fm_close(p_ctx->handle);
        if (delete)
        {
            ret = fm_delete(p_ctx->filename);
        }
    }

    return ret;
}
