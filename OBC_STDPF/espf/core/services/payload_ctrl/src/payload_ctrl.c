/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup payload_ctrl
 * @{
 *
 * @file payload_ctrl.c
 *
 * @brief Payload Controller main implementation.
 *
 * @}
 */

#include "es_cdef.h"
#include <string.h>
#include "payload_ctrl.h"
#include "cmsis_os2.h"
#include "es_exeh.h"
#include "taskmon.h"
#include "timer.h"
#include "assertions.h"
#include "trace.h"
#include "taskmon_stat.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

/** @brief Module ID used for this file to report error events in EXEH */
#define EXEH_CURRENT_MODULE_ID eEXEHModuleID_PAYLOAD_CTRL

/** @brief activation flags to unblock the main OS task */
#define PAYLOAD_TASK_ACTIVATE_FLAGS (0x01U)

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

/** @brief Critical errors to report via EXEH */
typedef enum
{
    ERR_CANNOT_SPAWN_TASK /**< Service could not spawn its main task */
} exeh_error_codes_t;

/** @brief Flag values used with @ref pl_state_mon_t::pending_flags field */
enum
{
    PENDING_FLAG_CLEAR_ALL = 0x00U,
    PENDING_FLAG_START     = 0x01U
};

/** @brief State monitoring data structure */
typedef struct
{
    pl_state_t               last_reported_state; /**< Last reported payload state */
    timer_handle_t           state_timer;         /**< Timer handle used to detect payload operation timeouts */
    uint8_t                  pending_flags;       /**< Flags indicating that there is a pending operation */
    payload_ctrl_start_cfg_t start_cfg;           /**< Start configuration data provided with the @ref payload_ctrl_start request */
} pl_state_mon_t;

/** @brief Runtime context of the payload controller */
typedef struct
{
    osThreadId_t    h_os_task;                     /**< OS task handle */
    p_payload_event p_user_event_cbk;              /**< User event callback for payload events */
    pl_state_mon_t  state_mon_data[PAYLOAD_COUNT]; /**< State monitoring data set for all configured payloads */
} pl_ctrl_runtime_context_t;

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

INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/** @brief Payload monitoring OS task started after a call to @ref payload_ctrl_init */
static pl_ctrl_runtime_context_t pl_ctrl_runtime_context = {
    .h_os_task        = NULL,
    .p_user_event_cbk = NULL,
};

/**< Attributes of the main synchronization mutex of the payload controller */
static const osMutexAttr_t payload_ctrl_lock_attr = {
    "payload_ctrl_mutex",                  // human readable mutex name
    osMutexRecursive | osMutexPrioInherit, // attr_bits
    NULL,                                  // memory for control block
    0U                                     // size for control block
};

/**< Attributes of the main task of the payload controller */
static const osThreadAttr_t task_attr = {
    .name       = "payload_ctrl_task",
    .attr_bits  = osThreadDetached,
    .cb_mem     = NULL,
    .cb_size    = 0U,
    .stack_mem  = NULL,
    .stack_size = PAYLOAD_CTRL_STACK_SIZE,
    .priority   = osPriorityNormal,
    .tz_module  = 0,
    .reserved   = 0
};

/** @brief Mutex to use for synchronizing access to the component structures */
static osMutexId_t h_payload_ctrl_lock;

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/

/**
 * @brief Payload monitoring OS task started after a call to @ref payload_ctrl_init.
 *
 * @param[in] p_task_arg Pointer to any task arguments provided at task creation
 */
static void payload_ctrl_task(void *p_task_arg);

/**
 * @brief Handles the timeout on payload switching between states.
 *
 * @param[in] pl_id ID of the processed payload
 */
static void payload_ctrl_check_transient_state(const payload_ctrl_payload_t pl_id);

/**
 * @brief Converts payload status to payload controller status for simple cases.
 *
 * @param[in] pld_status Payload status
 *
 * @return Payload controller status corresponding to the provided payload status
 */
static payload_ctrl_op_res_t payload_ctrl_pld_to_ctrl_status(const pl_op_status_t pld_status);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

payload_ctrl_op_res_t payload_ctrl_init(void)
{
    payload_ctrl_op_res_t res = PL_CTRL_OP_RES_FAILED;

    EXEH_INIT_MODULE_FILENAME();

    // call configured payload init functions...
    for (payload_ctrl_payload_t pl_id = 0; pl_id < PAYLOAD_COUNT; pl_id++)
    {
        const payload_immutable_cfg_t *p_pl_cfg = payload_ctrl_cfg_get(pl_id);

        if ((NULL != p_pl_cfg) &&
            (NULL != p_pl_cfg->p_pl_interface) &&
            (NULL != p_pl_cfg->p_pl_interface->init))
        {
            pl_ctrl_runtime_context.state_mon_data[pl_id].last_reported_state = PL_STATE_NOT_INIT;
            timer_stop(&pl_ctrl_runtime_context.state_mon_data[pl_id].state_timer);
            pl_ctrl_runtime_context.state_mon_data[pl_id].pending_flags = PENDING_FLAG_CLEAR_ALL;

            (void)p_pl_cfg->p_pl_interface->init(p_pl_cfg->internal_inst_id,
                                                 &p_pl_cfg->init_config,
                                                 p_pl_cfg->p_pl_notif_cbk);
        }
    }

    // create thread only if not already existing...
    if (NULL == pl_ctrl_runtime_context.h_os_task)
    {
        h_payload_ctrl_lock = osMutexNew(&payload_ctrl_lock_attr);

        pl_ctrl_runtime_context.h_os_task = osThreadNew(payload_ctrl_task,
                                                        NULL,
                                                        &task_attr);

        if ((NULL == pl_ctrl_runtime_context.h_os_task) || (NULL == h_payload_ctrl_lock))
        {
            EXEH_HANDLE(eEXEHSeverity_Fatal,
                        (int32_t)ERR_CANNOT_SPAWN_TASK);
        }
        else
        {
            task_mon_task_initialized(TASK_ID_PAYLOAD_CTRL);
            task_mon_register_for_stats(TASK_ID_PAYLOAD_CTRL, pl_ctrl_runtime_context.h_os_task);
            res = PL_CTRL_OP_RES_OK;
        }
    }

    return res;
}

payload_ctrl_op_res_t payload_ctrl_deinit(void)
{
    payload_ctrl_op_res_t op_res = PL_CTRL_OP_RES_OK;

    for (payload_ctrl_payload_t pl_id = 0; pl_id < PAYLOAD_COUNT; pl_id++)
    {
        const payload_immutable_cfg_t *p_pl_cfg = payload_ctrl_cfg_get(pl_id);
        pl_op_status_t                 res      = PL_OP_STATUS_REJECT;
        if ((NULL != p_pl_cfg) &&
            (NULL != p_pl_cfg->p_pl_interface) &&
            (NULL != p_pl_cfg->p_pl_interface->deinit))
        {
            res = p_pl_cfg->p_pl_interface->deinit(p_pl_cfg->internal_inst_id);
            if (PL_OP_STATUS_OK != res)
            {
                op_res = PL_CTRL_OP_RES_FAILED;
                ES_TRACE_ERROR("deinit failed for payload '%d'", pl_id);
            }
        }
        else
        {
            op_res = PL_CTRL_OP_RES_FAILED;
            ES_TRACE_ERROR("wrong configuration for payload '%d'", pl_id);
            BREAK_ASSERT(false);
        }
    }

    return op_res;
}

payload_ctrl_op_res_t payload_ctrl_start(const payload_ctrl_payload_t          payload_id,
                                         const payload_ctrl_start_cfg_t *const p_start_cfg)
{

    // Check if the system is in a mode that allows payload to run
    if (false == payload_ctrl_cfg_is_payload_mode())
    {
        ES_TRACE_WARN("request to start payload '%d' ignored due to conops conditions", payload_id);
        return PL_CTRL_OP_RES_REFUSE_CMD;
    }

    payload_ctrl_op_res_t op_res = PL_CTRL_OP_RES_FAILED;

    const payload_immutable_cfg_t *p_pl_cfg = payload_ctrl_cfg_get(payload_id);

    if ((NULL != p_pl_cfg) &&
        (NULL != p_pl_cfg->p_pl_interface) &&
        (NULL != p_pl_cfg->p_pl_interface->start) &&
        (NULL != p_pl_cfg->p_pl_interface->get_state))
    {
        const pl_state_t pl_state = p_pl_cfg->p_pl_interface->get_state(p_pl_cfg->internal_inst_id);

        if (osOK == osMutexAcquire(h_payload_ctrl_lock, osWaitForever))
        {
            if (PL_STATE_STOPPED == pl_state)
            {
                (void)memcpy((void *volatile)&pl_ctrl_runtime_context.state_mon_data[payload_id].start_cfg,
                             (const void *volatile)p_start_cfg,
                             sizeof(payload_ctrl_start_cfg_t));

                pl_ctrl_runtime_context.state_mon_data[payload_id].pending_flags |= PENDING_FLAG_START;
                (void)osThreadFlagsSet(pl_ctrl_runtime_context.h_os_task, PAYLOAD_TASK_ACTIVATE_FLAGS);
                pl_config_t start_args = {
                    .p_config_data = &pl_ctrl_runtime_context.state_mon_data[payload_id].start_cfg.payload_args,
                    .size          = sizeof(pl_ctrl_runtime_context.state_mon_data[payload_id].start_cfg.payload_args)

                };
                ES_TRACE_DEBUG("starting payload '%d[%d]'...", payload_id, p_pl_cfg->internal_inst_id);
                const pl_op_status_t payload_result = p_pl_cfg->p_pl_interface->start(p_pl_cfg->internal_inst_id,
                                                                                      &start_args);
                op_res                              = payload_ctrl_pld_to_ctrl_status(payload_result);
                ES_TRACE_DEBUG("payload '%d[%d]' start result - %d", payload_id, p_pl_cfg->internal_inst_id, op_res);
            }
            else
            {
                ES_TRACE_WARN("attempted start of payload '%d[%d]' which is not stopped", payload_id, p_pl_cfg->internal_inst_id);
            }
            osMutexRelease(h_payload_ctrl_lock);
        }
    }

    return op_res;
}

payload_ctrl_op_res_t payload_ctrl_stop(const payload_ctrl_payload_t payload_id,
                                        const pl_op_stop_mode_t      stop_mode)
{
    payload_ctrl_op_res_t op_res = PL_CTRL_OP_RES_FAILED;

    const payload_immutable_cfg_t *p_pl_cfg = payload_ctrl_cfg_get(payload_id);

    if ((NULL != p_pl_cfg) &&
        (NULL != p_pl_cfg->p_pl_interface) &&
        (NULL != p_pl_cfg->p_pl_interface->stop) &&
        (NULL != p_pl_cfg->p_pl_interface->get_state))
    {
        if (osOK == osMutexAcquire(h_payload_ctrl_lock, osWaitForever))
        {
            ES_TRACE_DEBUG("stopping payload '%d[%d]'...", payload_id, p_pl_cfg->internal_inst_id);
            const pl_op_status_t payload_result = p_pl_cfg->p_pl_interface->stop(p_pl_cfg->internal_inst_id, stop_mode);
            op_res                              = payload_ctrl_pld_to_ctrl_status(payload_result);
            ES_TRACE_DEBUG("payload '%d[%d]' stop result - %d", payload_id, p_pl_cfg->internal_inst_id, op_res);

            osMutexRelease(h_payload_ctrl_lock);
        }
    }

    return op_res;
}

void payload_ctrl_subscribe_events(p_payload_event const p_evt_callback)
{
    pl_ctrl_runtime_context.p_user_event_cbk = p_evt_callback;
}

payload_ctrl_op_res_t payload_ctrl_get_state(const payload_ctrl_payload_t payload_id,
                                             pl_state_t *const            p_state,
                                             uint32_t *const              p_error_code)
{
    payload_ctrl_op_res_t op_res = PL_CTRL_OP_RES_FAILED;

    if (payload_id < PAYLOAD_COUNT)
    {
        const payload_immutable_cfg_t *p_pl_cfg = payload_ctrl_cfg_get(payload_id);

        if ((NULL != p_state) &&
            (NULL != p_pl_cfg) &&
            (NULL != p_pl_cfg->p_pl_interface) &&
            (NULL != p_pl_cfg->p_pl_interface->get_state) &&
            (NULL != p_pl_cfg->p_pl_interface->get_last_error) &&
            (NULL != p_error_code))
        {
            (void)osMutexAcquire(h_payload_ctrl_lock, osWaitForever);
            *p_state      = p_pl_cfg->p_pl_interface->get_state(p_pl_cfg->internal_inst_id);
            *p_error_code = p_pl_cfg->p_pl_interface->get_last_error(p_pl_cfg->internal_inst_id);
            (void)osMutexRelease(h_payload_ctrl_lock);

            op_res = PL_CTRL_OP_RES_OK;
        }
    }
    else
    {
        op_res = PL_CTRL_OP_RES_INVALID_PL_ID;
    }

    return op_res;
}

void payload_ctrl_event_notify(const payload_ctrl_payload_t payload_id, const pl_state_t to_state)
{
    (void)osMutexAcquire(h_payload_ctrl_lock, osWaitForever);
    pl_ctrl_runtime_context.state_mon_data[payload_id].last_reported_state = to_state;

    switch (to_state)
    {
        case PL_STATE_STARTING:
        case PL_STATE_STOPPING:
            {
                // start tracking payload transient state time...
                timer_start(&pl_ctrl_runtime_context.state_mon_data[payload_id].state_timer);
                break;
            }

        default:
            {
                timer_stop(&pl_ctrl_runtime_context.state_mon_data[payload_id].state_timer);
                break;
            }
    }

    if (NULL != pl_ctrl_runtime_context.p_user_event_cbk)
    {
        const payload_immutable_cfg_t *p_pl_cfg = payload_ctrl_cfg_get(payload_id);

        if ((NULL != p_pl_cfg) &&
            (NULL != p_pl_cfg->p_pl_interface) &&
            (NULL != p_pl_cfg->p_pl_interface->get_last_error))
        {
            payload_ctrl_event_t pl_event = {
                .payload_id = payload_id,
                .op_state   = to_state,
                .error_code = p_pl_cfg->p_pl_interface->get_last_error(p_pl_cfg->internal_inst_id)
            };
            pl_ctrl_runtime_context.p_user_event_cbk(&pl_event);
        }
        else
        {
            BREAK_ASSERT(false);
        }
    }
    (void)osMutexRelease(h_payload_ctrl_lock);
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

static void payload_ctrl_task(void *p_task_arg)
{
    // currently unused
    (void)p_task_arg;

    for (;;)
    {
        (void)osThreadFlagsWait(PAYLOAD_TASK_ACTIVATE_FLAGS,
                                osFlagsWaitAny,
                                PAYLOAD_TASK_TIMEOUT_MS);

        for (uint8_t pl_id = 0; pl_id < (uint8_t)PAYLOAD_COUNT; pl_id++)
        {
            payload_ctrl_check_transient_state((payload_ctrl_payload_t)pl_id);
        }

        task_mon_i_am_alive(TASK_ID_PAYLOAD_CTRL);
        task_mon_low_stack_check(TASK_ID_PAYLOAD_CTRL);
    }
}

static void payload_ctrl_check_transient_state(const payload_ctrl_payload_t pl_id)
{
    (void)osMutexAcquire(h_payload_ctrl_lock, osWaitForever);
    if ((SAFE_TRUE == pl_ctrl_runtime_context.state_mon_data[pl_id].state_timer.is_running) &&
        (timer_is_elapsed(&pl_ctrl_runtime_context.state_mon_data[pl_id].state_timer, PAYLOAD_TRANSIENT_STATE_TIMEOUT_MS)))
    {
        timer_stop(&pl_ctrl_runtime_context.state_mon_data[pl_id].state_timer);

        ES_TRACE_WARN("payload '%d' is staying in a transient state '%d' for too long.",
                      pl_id,
                      pl_ctrl_runtime_context.state_mon_data[pl_id].last_reported_state);
    }
    (void)osMutexRelease(h_payload_ctrl_lock);
}

static payload_ctrl_op_res_t payload_ctrl_pld_to_ctrl_status(const pl_op_status_t pld_status)
{
    payload_ctrl_op_res_t op_res = PL_CTRL_OP_RES_FAILED;

    switch (pld_status)
    {
        case PL_OP_STATUS_OK:
            op_res = PL_CTRL_OP_RES_OK;
            break;
        case PL_OP_STATUS_REJECT:
            op_res = PL_CTRL_OP_RES_REFUSE_CMD;
            break;
        default:
            break;
    }

    return op_res;
}
