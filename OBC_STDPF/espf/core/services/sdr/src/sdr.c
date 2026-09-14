/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup sdr
 * @{
 *
 * @file sdr.c
 *
 * @brief SDR operation task implementation
 * @}
 */

#include "sdr.h"
#include "taskmon.h"
#include "sdr_sm_user.h"
#include "sdr_sm_config_user.h"
#include "sdr_critical.h"
#include "trace.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

/** @brief Component runtime context structure */
sdr_runtime_context_t sdr_rt_context = {
    .os_task_hnd      = NULL,
    .sdr_ft_status    = ES_TFTP_ERR_NOT_DEFINED,
    .boot_timer       = { 0 },
    .sync_timer       = { 0 },
    .is_boot_complete = false,
    .sdr_sync_dt      = {
                         .date = { 0 },
                         .time = { 0 } },
    .is_ready_to_sync = false,
    .sync_data_rdy    = false,
    .is_op_pending    = false,
    .sdr_op_req       = { 0 },
    .sdr_ft_req       = { 0 }
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
/** @brief Main sdr service task function
 *
 *  @param p_task_arg a pointer to a task-specific context structure (if applicable)
 *
 */
static void sdr_task(void *p_task_arg);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
bool sdr_trigger_hsm(const uint32_t event_id)
{
    bool ret = false;

    if (true == sdr_critical_enter(SDR_LOCK_OP_STAT_TIMEOUT_MS))
    {
        if (true == HSM_TriggerEvent(sdr_sm_instance, event_id))
        {
            ret = true;
        }
        sdr_critical_exit();
    }

    return ret;
}

void sdr_thread_init(void)
{
    static const osThreadAttr_t sdr_task_attr = {
        .attr_bits  = osThreadDetached,
        .name       = "sdr_op",
        .priority   = osPriorityNormal,
        .cb_mem     = NULL,
        .cb_size    = 0U,
        .stack_mem  = NULL,
        .stack_size = 8192,
        .tz_module  = 0U,
        .reserved   = 0U
    };

    if (NULL == sdr_rt_context.os_task_hnd)
    {
        sdr_rt_context.os_task_hnd = osThreadNew(sdr_task, NULL, &sdr_task_attr);

        if (NULL == sdr_rt_context.os_task_hnd)
        {
            ES_TRACE_ERROR("sdr> thread creation failure");
        }
        else
        {
            task_mon_task_initialized(TASK_ID_SDR_OP);
            task_mon_set_task_policy(TASK_ID_SDR_OP, TASK_MON_POLICY_DONT_CARE);
            task_mon_register_for_stats(TASK_ID_SDR_OP, sdr_rt_context.os_task_hnd);
        }
    }
}

void sdr_tl_init(void)
{
    // init sdr logging system
    es_log_iface_t log_iface = es_log_iface_init_default;
    es_log_init(&log_iface);
    es_log_set_lvl(ES_TRACE);

    // init sdr client library & csp as transport layer
    if ((false == es_sdr_client_init()) ||
        (false == es_sdr_client_csp_tl_init(SDR_CSP_ADDRESS)))
    {
        ES_TRACE_ERROR("sdr> tl & ser/des handlers init failure");
    }
}

void sdr_comm_deinit(void)
{
    es_sdr_client_deinit();
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
/**
 * @brief sdr service
 *
 * @param[in] p_task_arg not used
 */
static void sdr_task(void *p_task_arg)
{
    (void)p_task_arg;

    for (;;)
    {
        (void)sdr_trigger_hsm(eHSM_StdEvent_Periodic);

        osDelay(SDR_SERVICE_DELAY_MS);

        task_mon_i_am_alive(TASK_ID_SDR_OP);
        task_mon_low_stack_check(TASK_ID_SDR_OP);
    }
}
