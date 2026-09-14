/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup service_tlm
 * @{
 *
 * @file telemetry.c
 *
 * @brief Telemetry service core implementation
 *
 *
 * @}
 */

#include <string.h>
#include "trace.h"
#include "telemetry.h"
#include "taskmon.h"
#include "timer.h"
#include "assertions.h"
#include "telemetry_sm_user.h"
#include "telemetry_sm_config_user.h"
#include "telemetry_cfg_user.h"
#include "telemetry_file_sink.h"
#include "telemetry_file_sink_sm_user.h"
#include "telemetry_queue.h"
#include "taskmon_stat.h"
#include "FP_telemetryProtocolTypes.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

/** default period of the telemetry service task in milliseconds */
#define TLM_TASK_DEFAULT_PERIOD_MS (500U)
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
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
*********************************************************************************************
*/

// Initialize the trace logger
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

static const osMutexAttr_t telemetry_lock_attr = {
    "tlm_mutex",      // human readable mutex name
    osMutexRecursive, // attr_bits
    NULL,             // memory for control block
    0U                // size for control block
};

/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
*********************************************************************************************
*/
/** @brief Main beacons service task function
 *
 *  @param p_task_arg pointer to the active telemetry context of type @ref tlm_runtime_context_t
 *
 */
static void telemetry_task(void *p_task_arg);

/** @brief Sends an event to the internal HSM for processing but ensures locking of state
 *            via mutex.
 *
 *  @param[in/out] p_tlm_rt_ctx pointer to the currently active telemetry context
 *  @param[in] event_id HSM event id to process
 *
 *  @retval true  - event was processed by the current state
 *  @retval false - event was ignored
 */
static bool inline telemetry_trigger_hsm(tlm_runtime_context_t *const p_tlm_rt_ctx, const uint32_t event_id);

/** @brief Updates the OS task period based on the active telemetry preset
 *
 *  @param[in/out] p_tlm_rt_ctx pointer to the currently active telemetry context
 */
static void update_os_task_period(tlm_runtime_context_t *const p_tlm_rt_ctx);

/** @brief It uses the Euclidean algorithm to calculate the GCD.
 */
static uint32_t calc_gcd(uint32_t a, uint32_t b);

/*
*********************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/
void telemetry_init(void)
{
    static const osThreadAttr_t task_attr = {
        .attr_bits  = osThreadDetached,
        .name       = "Telemetry_Service_Task",
        .priority   = osPriorityNormal,
        .cb_mem     = NULL,
        .cb_size    = 0U,
        .stack_mem  = NULL,
        .stack_size = 2500
    };

    for (uint8_t instance_id = 0; instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT; instance_id++)
    {
        tlm_runtime_context_t *p_tlm_rt_ctx = telemetry_cfg_get_ctx(instance_id);

        p_tlm_rt_ctx->os_task_hnd       = NULL;
        p_tlm_rt_ctx->os_task_period_ms = TLM_TASK_DEFAULT_PERIOD_MS;
        p_tlm_rt_ctx->prev_preset_id    = 0;
        p_tlm_rt_ctx->rolling_cntr      = 0;
        p_tlm_rt_ctx->hold_period_s     = 0;
        timer_stop(&p_tlm_rt_ctx->hold_timer);

        if (NULL == p_tlm_rt_ctx->telemetry_lock_id)
        {
            p_tlm_rt_ctx->telemetry_lock_id = osMutexNew(&telemetry_lock_attr);
        }

        telemetry_trigger_hsm(p_tlm_rt_ctx, eHSM_StdEvent_Reset);
        telemetry_trigger_hsm(p_tlm_rt_ctx, ev_telemetry_sm_init);

        telemetry_file_sink_if.cmd(&p_tlm_rt_ctx->tlm_file_sink_rt, TELEMETRY_SINK_ADAPTER_CMD_INIT);

        // create thread only if not already existing...
        if (NULL == p_tlm_rt_ctx->os_task_hnd)
        {
            p_tlm_rt_ctx->os_task_hnd = osThreadNew(telemetry_task,
                                                    (void *)p_tlm_rt_ctx,
                                                    &task_attr);

            if (NULL == p_tlm_rt_ctx->os_task_hnd)
            {
                ES_TRACE_FATAL("[%d] Failed to spawn telemetry task!", (uint8_t)instance_id);
                BREAK_ASSERT(false);
            }
            else
            {
                task_mon_task_initialized(p_tlm_rt_ctx->task_mon_id);
                task_mon_register_for_stats(p_tlm_rt_ctx->task_mon_id, p_tlm_rt_ctx->os_task_hnd);
            }
        }
    }
}

void telemetry_start(tlm_runtime_context_t *const p_tlm_rt_ctx, const uint16_t hold_period_s)
{
    BREAK_ASSERT(NULL != p_tlm_rt_ctx);

    if (NULL != p_tlm_rt_ctx)
    {
        p_tlm_rt_ctx->hold_period_s = hold_period_s;

        (void)telemetry_trigger_hsm(p_tlm_rt_ctx, ev_telemetry_sm_start);
        telemetry_file_sink_if.cmd(&p_tlm_rt_ctx->tlm_file_sink_rt, TELEMETRY_SINK_ADAPTER_CMD_START);
        ES_TRACE_DEBUG("[%u] telemetry instance started", p_tlm_rt_ctx->sm_instance_id);
    }
}

void telemetry_stop(tlm_runtime_context_t *const p_tlm_rt_ctx, const uint16_t hold_period_s)
{
    BREAK_ASSERT(NULL != p_tlm_rt_ctx);

    if (NULL != p_tlm_rt_ctx)
    {
        p_tlm_rt_ctx->hold_period_s = hold_period_s;

        (void)telemetry_trigger_hsm(p_tlm_rt_ctx, ev_telemetry_sm_stop);
        telemetry_file_sink_if.cmd(&p_tlm_rt_ctx->tlm_file_sink_rt, TELEMETRY_SINK_ADAPTER_CMD_STOP);
        ES_TRACE_DEBUG("[%u] telemetry instance stopped", p_tlm_rt_ctx->sm_instance_id);
    }
}

bool telemetry_is_started(tlm_runtime_context_t *const p_tlm_rt_ctx)
{
    BREAK_ASSERT(NULL != p_tlm_rt_ctx);
    bool is_started = false;

    if (NULL != p_tlm_rt_ctx)
    {
        uint8_t tlm_state_id      = HSM_GetActiveStateForInstance((uint16_t)p_tlm_rt_ctx->sm_instance_id, telemetry_sm_instance)->state_id;
        uint8_t tlm_sink_state_id = HSM_GetActiveStateForInstance((uint16_t)p_tlm_rt_ctx->sm_instance_id, telemetry_file_sink_sm_instance)->state_id;

        is_started = ((TELEMETRY_SM_STATE_STARTED == tlm_state_id) && (TELEMETRY_FILE_SINK_SM_STATE_STARTED == tlm_sink_state_id));
    }

    return is_started;
}

void telemetry_load_config(tlm_runtime_context_t *const p_tlm_rt_ctx)
{
    BREAK_ASSERT(NULL != p_tlm_rt_ctx);

    if (NULL != p_tlm_rt_ctx)
    {
        telemetry_cfg_get_tlm_config(p_tlm_rt_ctx->sm_instance_id, &p_tlm_rt_ctx->gen_cfg);
        telemetry_cfg_get_preset_config(p_tlm_rt_ctx->sm_instance_id, &p_tlm_rt_ctx->preset_cfg);
        p_tlm_rt_ctx->active_preset_id = telemetry_cfg_get_active_preset(p_tlm_rt_ctx->sm_instance_id);

        if (p_tlm_rt_ctx->prev_preset_id != p_tlm_rt_ctx->active_preset_id)
        {
            // reset acquisition counters...
            (void)memset(p_tlm_rt_ctx->tlm_entry_timer, 0U, sizeof(p_tlm_rt_ctx->tlm_entry_timer));

            p_tlm_rt_ctx->prev_preset_id = p_tlm_rt_ctx->active_preset_id;
        }

        update_os_task_period(p_tlm_rt_ctx);

        BREAK_ASSERT(p_tlm_rt_ctx->active_preset_id < TELEMETRY_PRESETS_COUNT);
    }
}

/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/
static void telemetry_task(void *p_task_arg)
{
    tlm_runtime_context_t *const p_tlm_context = (tlm_runtime_context_t *)p_task_arg;

    CRIT_ASSERT(NULL != p_tlm_context);

    telemetry_load_config(p_tlm_context);

    ES_TRACE_INFO("[%u] applying tlm auto-start status: [%d]", p_tlm_context->sm_instance_id, (uint8_t)p_tlm_context->gen_cfg.params.bTlm_auto_start_en);

    if (true == p_tlm_context->gen_cfg.params.bTlm_auto_start_en)
    {
        telemetry_start(p_tlm_context, 0U);
    }

    for (;;)
    {
        // execute periodic SM activities...
        (void)telemetry_trigger_hsm(p_tlm_context, eHSM_StdEvent_Periodic);

        // If the queue is almost full, trigger the file sink to flush the data
        if (true == telemetry_queue_reached_threshold(&p_tlm_context->tlm_queue))
        {
            telemetry_file_sink_if.cmd(&p_tlm_context->tlm_file_sink_rt, TELEMETRY_SINK_ADAPTER_CMD_FLUSH);
        }

        osDelay(p_tlm_context->os_task_period_ms);

        task_mon_i_am_alive(p_tlm_context->task_mon_id);
        task_mon_low_stack_check(p_tlm_context->task_mon_id);
    }
}

static bool inline telemetry_trigger_hsm(tlm_runtime_context_t *const p_tlm_rt_ctx, const uint32_t event_id)
{
    CRIT_ASSERT(NULL != p_tlm_rt_ctx);

    bool res = false;

    if (osOK == osMutexAcquire(p_tlm_rt_ctx->telemetry_lock_id, MAX_MUTEX_WAIT_TIMEOUT_MS))
    {
        res = HSM_TriggerEventForInstance(p_tlm_rt_ctx->sm_instance_id, telemetry_sm_instance, event_id);
        (void)osMutexRelease(p_tlm_rt_ctx->telemetry_lock_id);
    }

    return res;
}

static void update_os_task_period(tlm_runtime_context_t *const p_tlm_rt_ctx)
{
    CRIT_ASSERT(NULL != p_tlm_rt_ctx);

    // Set the default period if the telemetry is not enabled
    if (false == p_tlm_rt_ctx->gen_cfg.params.bTlm_auto_start_en)
    {
        p_tlm_rt_ctx->os_task_period_ms = TLM_TASK_DEFAULT_PERIOD_MS;
    }
    else
    {
        // The task period shall be the Greatest Common Divisor of all telemetry periods of the active preset
        const TELEMETRY_tlm_preset_cfg_t *p_tlm_slots = p_tlm_rt_ctx->preset_cfg.tlm_slots_setting[p_tlm_rt_ctx->active_preset_id];

        // Initialize with the first slot
        uint32_t gcd = 0;

        for (uint8_t slot = 0; slot < TELEMETRY_MAX_CONFIGURABLE_ENTRIES; slot++)
        {
            // GCD is 1, no need to continue
            if (gcd == 1)
            {
                break;
            }

            if (true == p_tlm_slots[slot].bActive)
            {
                gcd = (0 == gcd) ? p_tlm_slots[slot].u16Acq_period_ms : calc_gcd(gcd, p_tlm_slots[slot].u16Acq_period_ms);
            }
        }

        p_tlm_rt_ctx->os_task_period_ms = gcd;
    }
}

/** @brief It uses the Euclidean algorithm to calculate the GCD.
 */
static uint32_t calc_gcd(uint32_t a, uint32_t b)
{
    uint32_t temp;
    uint32_t modulo;
    uint32_t gcd = a;

    if (a != b)
    {
        modulo = b;

        while (modulo > 0)
        {
            temp   = modulo;
            modulo = gcd % modulo;
            gcd    = temp;
        }
    }

    return gcd;
}
