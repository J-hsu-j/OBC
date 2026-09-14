/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup service_tlm
 * @{
 *
 * @file telemetry_queue.c
 *
 * @brief Telemetry cyclic data queue implementation
 *
 * @}
 */

#include <limits.h>
#include <string.h>
#include "es_cdef.h"
#include "telemetry_queue.h"
#include "telemetry_cfg_user.h"
#include "cmsis_os2.h"
#include "assertions.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

/** @brief OS Mutex configuration structure */
static const osMutexAttr_t tlm_queue_lock_attr = {
    "tlm_queue_mutex", /**< Human readable mutex name */
    osMutexRecursive,  /**< Mutex attributes\ref osMutexAttr_t */
    NULL,              /**< Memory for the mutex control block */
    0U                 /**< Size for the control block */
};

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/
/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
static void telemetry_queue_lock(tlm_queue_rt_t *const p_queue_inst);
static void telemetry_queue_unlock(tlm_queue_rt_t *const p_queue_inst);
/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
void telemetry_queue_init(tlm_queue_rt_t *const p_queue_inst)
{
    BREAK_ASSERT(NULL != p_queue_inst);

    if (NULL != p_queue_inst)
    {
        p_queue_inst->head_idx                      = 0U;
        p_queue_inst->tail_idx                      = 0U;
        p_queue_inst->free_bytes                    = TLM_QUEUE_SIZE;
        p_queue_inst->stats.msg_pushed_cnt          = 0U;
        p_queue_inst->stats.msg_popped_cnt          = 0U;
        p_queue_inst->stats.free_bytes_min          = TLM_QUEUE_SIZE;
        p_queue_inst->stats.discarded_messages_cnt  = 0U;
        p_queue_inst->stats.max_number_of_batch_msg = 0U;
        p_queue_inst->stats.active_slot_id          = 0U;

        if (NULL == p_queue_inst->tlm_queue_lock_id)
        {
            p_queue_inst->tlm_queue_lock_id = osMutexNew(&tlm_queue_lock_attr);
        }
    }
}

bool telemetry_queue_push(tlm_queue_rt_t *const p_queue_inst, const uint8_t *const p_data, const uint16_t data_size)
{
    BREAK_ASSERT(NULL != p_queue_inst);
    BREAK_ASSERT(NULL != p_data);
    BREAK_ASSERT(data_size <= sizeof(p_queue_inst->qbuf));

    bool success = false;

    if ((NULL == p_queue_inst) || (NULL == p_data) || (data_size > sizeof(p_queue_inst->qbuf)))
    {
        return false;
    }

    if (data_size < p_queue_inst->free_bytes)
    {
        telemetry_queue_lock(p_queue_inst);

        uint8_t       *p_queue_pos   = &p_queue_inst->qbuf[p_queue_inst->tail_idx];
        uint16_t       queue_idx     = p_queue_inst->tail_idx;
        const uint8_t *p_data_pos    = p_data;
        uint16_t       bytes_written = 0U;

        while (bytes_written < data_size)
        {
            *p_queue_pos = *p_data_pos++;

            queue_idx   = (queue_idx + 1) % TLM_QUEUE_SIZE;
            p_queue_pos = &p_queue_inst->qbuf[queue_idx];

            bytes_written++;

            // did we end up at the first message to be read?
            if (((queue_idx + 1U) % TLM_QUEUE_SIZE) == p_queue_inst->head_idx)
            {
                break;
            }
        }

        p_queue_inst->free_bytes -= bytes_written;

        if (p_queue_inst->stats.free_bytes_min > p_queue_inst->free_bytes)
        {
            p_queue_inst->stats.free_bytes_min = p_queue_inst->free_bytes;
        }

        p_queue_inst->tail_idx = (p_queue_inst->tail_idx + bytes_written) % TLM_QUEUE_SIZE;
        success                = true;

        if (p_queue_inst->stats.msg_pushed_cnt < ULONG_MAX)
        {
            p_queue_inst->stats.msg_pushed_cnt++;
        }

        telemetry_queue_unlock(p_queue_inst);
    }

    if ((!success) && (p_queue_inst->stats.discarded_messages_cnt < ULONG_MAX))
    {
        p_queue_inst->stats.discarded_messages_cnt++;
    }

    return success;
}

uint16_t telemetry_queue_pop(tlm_queue_rt_t *const p_queue_inst, uint8_t *const p_data_buf, const uint16_t buf_size)
{
    BREAK_ASSERT(NULL != p_queue_inst);
    BREAK_ASSERT(NULL != p_data_buf);
    BREAK_ASSERT(buf_size > 0);

    if ((NULL == p_queue_inst) || (NULL == p_data_buf) || (0 == buf_size))
    {
        return 0;
    }

    uint16_t bytes_written = 0U;

    // are there any messages in the queue?
    if (p_queue_inst->free_bytes < TLM_QUEUE_SIZE)
    {
        telemetry_queue_lock(p_queue_inst);

        uint8_t *p_queue_pos = &p_queue_inst->qbuf[p_queue_inst->head_idx];
        uint16_t queue_idx   = p_queue_inst->head_idx;
        uint8_t *p_data_pos  = p_data_buf;

        while ((bytes_written < buf_size) &&
               (TLM_FRM_DELIMITER != *p_queue_pos))
        {
            *p_data_pos++ = *p_queue_pos;
            *p_queue_pos  = TLM_FRM_DELIMITER;
            queue_idx     = (queue_idx + 1) % TLM_QUEUE_SIZE;
            p_queue_pos   = &p_queue_inst->qbuf[queue_idx];

            bytes_written++;
        }

        // did we actually reach the end of a frame?
        if (TLM_FRM_DELIMITER != *p_queue_pos)
        {
            // no, probably some invalid data was placed in the queue
            bytes_written = 0U;
        }
        else
        {
            *p_data_pos++ = *p_queue_pos;
            bytes_written++;

            p_queue_inst->free_bytes += bytes_written;
            p_queue_inst->head_idx = (p_queue_inst->head_idx + bytes_written) % TLM_QUEUE_SIZE;

            if (p_queue_inst->stats.msg_popped_cnt < ULONG_MAX)
            {
                p_queue_inst->stats.msg_popped_cnt++;
            }
        }

        telemetry_queue_unlock(p_queue_inst);
    }

    return bytes_written;
}

uint16_t telemetry_queue_peek(tlm_queue_rt_t *const p_queue_inst)
{
    BREAK_ASSERT(NULL != p_queue_inst);

    if (NULL == p_queue_inst)
    {
        return 0;
    }

    uint16_t bytes_read = 0U;

    if (p_queue_inst->free_bytes < TLM_QUEUE_SIZE)
    {
        telemetry_queue_lock(p_queue_inst);

        const uint8_t *p_queue_pos = &p_queue_inst->qbuf[p_queue_inst->head_idx];
        uint16_t       queue_idx   = p_queue_inst->head_idx;

        while ((queue_idx != p_queue_inst->tail_idx) &&
               (TLM_FRM_DELIMITER != *p_queue_pos))
        {
            queue_idx   = (queue_idx + 1) % TLM_QUEUE_SIZE;
            p_queue_pos = &p_queue_inst->qbuf[queue_idx];

            bytes_read++;
        }

        // did we actually reach the end of a frame?
        if (TLM_FRM_DELIMITER != *p_queue_pos)
        {
            // no, probably some invalid data was placed in the queue
            bytes_read = 0U;
        }
        else
        {
            bytes_read++;
        }

        telemetry_queue_unlock(p_queue_inst);
    }

    return bytes_read;
}

void telemetry_queue_get_stats(tlm_queue_rt_t *const p_queue_inst, tlm_queue_stats_t *const p_user_buf)
{
    BREAK_ASSERT(NULL != p_queue_inst);
    BREAK_ASSERT(NULL != p_user_buf);

    if ((NULL == p_queue_inst) || (NULL == p_user_buf))
    {
        return;
    }

    telemetry_queue_lock(p_queue_inst);

    if (NULL != p_user_buf)
    {
        (void)memcpy(p_user_buf, &p_queue_inst->stats, sizeof(p_queue_inst->stats));
    }

    telemetry_queue_unlock(p_queue_inst);
}

void telemetry_reset_stats(tlm_queue_rt_t *const p_queue_inst)
{
    BREAK_ASSERT(NULL != p_queue_inst);

    if (NULL == p_queue_inst)
    {
        return;
    }

    telemetry_queue_lock(p_queue_inst);

    (void)memset(&p_queue_inst->stats, 0, sizeof(p_queue_inst->stats));

    telemetry_queue_unlock(p_queue_inst);
}

void telemetry_queue_update_stats(tlm_queue_rt_t *const p_queue_inst, const tlm_queue_stats_id_t stat_id, const uint32_t value)
{
    BREAK_ASSERT(NULL != p_queue_inst);
    BREAK_ASSERT(stat_id < TLM_STATS_MAX);

    if ((NULL == p_queue_inst) || (stat_id >= TLM_STATS_MAX))
    {
        return;
    }

    telemetry_queue_lock(p_queue_inst);

    switch (stat_id)
    {
        case TLM_STATS_ID_BATCH_COUNT:
            {
                if (p_queue_inst->stats.max_number_of_batch_msg < value)
                {
                    p_queue_inst->stats.max_number_of_batch_msg = value;
                }

                break;
            }

        case TLM_STATS_ID_ACTIVE_SLOT:
            {
                p_queue_inst->stats.active_slot_id = value;
                break;
            }

        default:
            {
                CRIT_ASSERT(false);
                break;
            }
    }

    telemetry_queue_unlock(p_queue_inst);
}

bool telemetry_queue_reached_threshold(const tlm_queue_rt_t *const p_queue_inst)
{
    BREAK_ASSERT(NULL != p_queue_inst);

    return (NULL != p_queue_inst) ? (p_queue_inst->free_bytes < TELEMETRY_QUEUE_LOW_SPACE_THRESHOLD) : false;
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
static void telemetry_queue_lock(tlm_queue_rt_t *const p_queue_inst)
{
    CRIT_ASSERT(NULL != p_queue_inst);

    osMutexAcquire(p_queue_inst->tlm_queue_lock_id, osWaitForever);
}

static void telemetry_queue_unlock(tlm_queue_rt_t *const p_queue_inst)
{
    CRIT_ASSERT(NULL != p_queue_inst);

    osMutexRelease(p_queue_inst->tlm_queue_lock_id);
}
