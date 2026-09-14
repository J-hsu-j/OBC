/*
 * Copyright (c) 2020-2023 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @defgroup service_tlm
 * @{
 *
 * @file telemetry_file_sink.c
 *
 * @brief Telemetry file sink implementation.
 *
 * The module implements the standard `if_telemetry_sink` interface and provides:
 * - File storage of telemetry frames on the SD card.
 * - Data distribution over multiple files according to the applied NVM configuration.
 *
 * @}
 */

#include <string.h>
#include "es_cdef.h"
#include "trace.h"
#include "assertions.h"
#include "if_telemetry_sink.h"
#include "telemetry_cfg_user.h"
#include "telemetry_file_sink_sm_user.h"
#include "telemetry_file_sink_sm_config_user.h"
#include "taskmon.h"
#include "taskmon_stat.h"
#include "telemetry_context_types.h"
#include "telemetry_queue.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
/*
*********************************************************************************************
* INTERNAL TYPES DEFINITION
*********************************************************************************************
*/
/*
*********************************************************************************************
* EXTERNAL VARIABLES DEFINITION
*********************************************************************************************
*/
/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
*********************************************************************************************
*/
/** @brief Initialize the telemetry file sink */
static void telemetry_file_sink_init(tlm_file_sink_rt_ctx_t *const p_tlm_filesink_rt_ctx);

/** @brief Execute any pending external tasks which must be synchronous to the main task execution to
 *         avoid context corruption.
 */
static void telemetry_file_sink_exec_syncd_tasks(tlm_file_sink_rt_ctx_t *const p_tlm_filesink_rt_ctx);

/** @brief Main telemetry file sink task function
 *
 *  @param p_task_arg a pointer to a task-specific context structure (if applicable)
 *
 */
static void telemetry_file_sink_task(void *p_task_arg);

/** @brief Trigger the telemetry file sink state machine
 *
 *  @param[in] event_id HSM event ID to send to the SM engine
 *
 *  @retval true: the event was processed by the HSM
 *  @retval false: the event wasn't processed by the HSM
 */
static bool inline telemetry_file_trigger_hsm(tlm_file_sink_rt_ctx_t *const p_tlm_filesink_rt_ctx, const uint32_t event_id);

/** @brief Execute a file sink command
 *
 *  @param[in] p_tlm_filesink_rt_ctx file sink runtime context data pointer
 *  @param[in] cmd command ID to execute
 */
static void telemetry_file_sink_adapter_cmd(tlm_file_sink_rt_ctx_t *const p_tlm_filesink_rt_ctx, const telemetry_sink_adapter_cmd_t cmd);

/*
*********************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
*********************************************************************************************
*/
// Initialize the trace logger
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

static const osMutexAttr_t telemetry_file_lock_attr = {
    "tlm_file_sink_mutex",
    osMutexRecursive,
    NULL,
    0U
};

telemetry_sink_if_t telemetry_file_sink_if = {
    .cmd = &telemetry_file_sink_adapter_cmd
};

/*
*********************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/

void telemetry_file_sink_syncd_clean(tlm_file_sink_rt_ctx_t *const p_tlm_filesink_rt_ctx)
{
    telemetry_file_sink_prepare_file_access(p_tlm_filesink_rt_ctx);

    p_tlm_filesink_rt_ctx->main_task_sync_op_flags[TLM_FILE_SINK_OP_CLEAN] = true;

    (void)telemetry_file_trigger_hsm(p_tlm_filesink_rt_ctx, ev_telemetry_file_sink_sm_file_cleanup_triggered);
}

void telemetry_file_sink_config_update(tlm_file_sink_rt_ctx_t *const p_tlm_filesink_rt_ctx)
{
    p_tlm_filesink_rt_ctx->main_task_sync_op_flags[TLM_FILE_SINK_OP_CFG_UPDATE] = true;
}

/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/
static void telemetry_file_sink_init(tlm_file_sink_rt_ctx_t *const p_tlm_filesink_rt_ctx)
{
    CRIT_ASSERT(NULL != p_tlm_filesink_rt_ctx);

    static const osThreadAttr_t task_attr = {
        .attr_bits  = osThreadDetached,
        .name       = "tlm_file_sink_task",
        .priority   = osPriorityNormal,
        .cb_mem     = NULL,
        .cb_size    = 0U,
        .stack_mem  = NULL,
        .stack_size = 2500,
        .reserved   = 0U,
        .tz_module  = 0
    };

    for (uint8_t idx = 0; idx < TLM_FILE_SINK_OP_MAX; idx++)
    {
        p_tlm_filesink_rt_ctx->main_task_sync_op_flags[idx] = false;
    }

    CRIT_ASSERT(sizeof(TLM_FILE_SINK_EXT) <= 4U);

    p_tlm_filesink_rt_ctx->max_file_size_bytes = 0;

    (void)strcat(p_tlm_filesink_rt_ctx->wildcard, TLM_FILE_NAME_MASK);
    (void)strcat(p_tlm_filesink_rt_ctx->wildcard, TLM_FILE_SINK_EXT);

    if (NULL == p_tlm_filesink_rt_ctx->telemetry_file_lock_id)
    {
        p_tlm_filesink_rt_ctx->telemetry_file_lock_id = osMutexNew(&telemetry_file_lock_attr);
    }

    // create thread only if not already existing...
    if (NULL == p_tlm_filesink_rt_ctx->os_task_hnd)
    {
        p_tlm_filesink_rt_ctx->os_task_hnd = osThreadNew(&telemetry_file_sink_task, (void *)p_tlm_filesink_rt_ctx, &task_attr);

        if (NULL == p_tlm_filesink_rt_ctx->os_task_hnd)
        {
            ES_TRACE_FATAL("tlm file sink task creation failed!");
            BREAK_ASSERT(false);
        }
        else
        {
            task_mon_task_initialized(p_tlm_filesink_rt_ctx->task_mon_id);
            task_mon_register_for_stats(p_tlm_filesink_rt_ctx->task_mon_id, p_tlm_filesink_rt_ctx->os_task_hnd);
        }
    }
}

static void telemetry_file_sink_exec_syncd_tasks(tlm_file_sink_rt_ctx_t *const p_tlm_filesink_rt_ctx)
{
    CRIT_ASSERT(NULL != p_tlm_filesink_rt_ctx);

    for (uint8_t idx = 0; idx < (uint8_t)TLM_FILE_SINK_OP_MAX; idx++)
    {
        if (true == p_tlm_filesink_rt_ctx->main_task_sync_op_flags[idx])
        {
            if (idx == (uint8_t)TLM_FILE_SINK_OP_CFG_UPDATE)
            {
                (void)telemetry_file_trigger_hsm(p_tlm_filesink_rt_ctx, ev_telemetry_file_sink_sm_restart);
            }

            if (idx == (uint8_t)TLM_FILE_SINK_OP_CLEAN)
            {
                telemetry_file_sink_clean(p_tlm_filesink_rt_ctx);
                telemetry_reset_stats(&telemetry_cfg_get_ctx_u16(p_tlm_filesink_rt_ctx->sm_instance_id)->tlm_queue);
            }

            p_tlm_filesink_rt_ctx->main_task_sync_op_flags[idx] = false;
        }
    }
}

static void telemetry_file_sink_adapter_cmd(tlm_file_sink_rt_ctx_t *const p_tlm_filesink_rt_ctx, const telemetry_sink_adapter_cmd_t cmd)
{
    CRIT_ASSERT(NULL != p_tlm_filesink_rt_ctx);

    switch (cmd)
    {
        case TELEMETRY_SINK_ADAPTER_CMD_INIT:
            {
                telemetry_file_sink_init(p_tlm_filesink_rt_ctx);

                (void)telemetry_file_trigger_hsm(p_tlm_filesink_rt_ctx, eHSM_StdEvent_Reset);
                (void)telemetry_file_trigger_hsm(p_tlm_filesink_rt_ctx, ev_telemetry_file_sink_sm_init);
                break;
            }

        case TELEMETRY_SINK_ADAPTER_CMD_START:
            {
                (void)telemetry_file_trigger_hsm(p_tlm_filesink_rt_ctx, ev_telemetry_file_sink_sm_start);

                break;
            }

        case TELEMETRY_SINK_ADAPTER_CMD_STOP:
            {
                (void)telemetry_file_trigger_hsm(p_tlm_filesink_rt_ctx, ev_telemetry_file_sink_sm_stop);
                break;
            }

        case TELEMETRY_SINK_ADAPTER_CMD_FLUSH:
            {
                uint32_t res = osThreadFlagsSet(p_tlm_filesink_rt_ctx->os_task_hnd, TLM_FILE_SINK_STORE_FLAG);
                if (res != TLM_FILE_SINK_STORE_FLAG)
                {
                    ES_TRACE_WARN("[%u] file sink failed to set flush flag: 0x%08X", (uint8_t)p_tlm_filesink_rt_ctx->sm_instance_id, res);
                }
                break;
            }

        default:
            {
                CRIT_ASSERT(false);
                break;
            }
    }
}

static void telemetry_file_sink_task(void *p_task_arg)
{
    tlm_file_sink_rt_ctx_t *const p_tlm_filesink_rt_ctx = (tlm_file_sink_rt_ctx_t *)p_task_arg;

    CRIT_ASSERT(NULL != p_tlm_filesink_rt_ctx);

    uint32_t thread_flags = 0U;

    for (;;)
    {
        telemetry_file_sink_exec_syncd_tasks(p_tlm_filesink_rt_ctx);

        // Wait for activation
        thread_flags = osThreadFlagsWait(TLM_FILE_SINK_STORE_FLAG, osFlagsWaitAny, TLM_FILE_SINK_TASK_PERIOD_MS);

        if ((osFlagsError == (thread_flags & osFlagsError)) && (thread_flags != (uint32_t)osErrorTimeout))
        {
            ES_TRACE_ERROR("file sink task flags error: 0x%08X", thread_flags);
        }

        (void)telemetry_file_trigger_hsm(p_tlm_filesink_rt_ctx, eHSM_StdEvent_Periodic);

        task_mon_i_am_alive(p_tlm_filesink_rt_ctx->task_mon_id);
        task_mon_low_stack_check(p_tlm_filesink_rt_ctx->task_mon_id);
    }
}

static bool inline telemetry_file_trigger_hsm(tlm_file_sink_rt_ctx_t *const p_tlm_filesink_rt_ctx, const uint32_t event_id)
{
    CRIT_ASSERT(NULL != p_tlm_filesink_rt_ctx);

    bool res = false;

    if (osOK == osMutexAcquire(p_tlm_filesink_rt_ctx->telemetry_file_lock_id, MAX_MUTEX_WAIT_TIMEOUT_MS))
    {
        res = HSM_TriggerEventForInstance(p_tlm_filesink_rt_ctx->sm_instance_id, telemetry_file_sink_sm_instance, event_id);
        (void)osMutexRelease(p_tlm_filesink_rt_ctx->telemetry_file_lock_id);
    }

    return res;
}
