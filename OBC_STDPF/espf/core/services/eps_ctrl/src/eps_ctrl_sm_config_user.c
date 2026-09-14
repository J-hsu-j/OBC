/*
 * Copyright (c) EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#include "libhsm.h"
#include "eps_ctrl_sm_config_user.h"

// USER_CODE_START::@main@
/**
 * @addtogroup eps_ctrl
 * @{
 *
 * @file     eps_ctrl_sm_config_user.c
 * @brief    Generated EPS Control libhsm
 *
 * @}
 */

#include "timer.h"
#include "eps_ctrl_cfg.h"
#include "eps_ctrl_queue.h"

static bool eps_sm_request_sent_ok = false;
static uint32_t retries = 0;

timer_handle_t response_timer;

// USER_CODE_END::@main@

// Entry/Exit functions

// GEN_OBJ_START::eps_ctrl_sm_on_exit_off
void eps_ctrl_sm_on_exit_off(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::onExit_off

    // Initialize the timer library
    timer_init();

    // USER_CODE_END::onExit_off
}
// GEN_OBJ_END::eps_ctrl_sm_on_exit_off



// GEN_OBJ_START::eps_ctrl_sm_on_entry_active_request
void eps_ctrl_sm_on_entry_active_request(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::onEntry_active_request
    eps_ctrl_result_t res = EPS_CTRL_FAIL;

    // Call eps_ctrl to send the request
    eps_ctrl_request_t head_copy;
    eps_ctrl_request_t const * p_request = eps_ctrl_queue_head(&head_copy);

    if (NULL != p_request)
    {
        switch (head_copy.type)
        {
        case EPS_CTRL_REQ_SET_CH:
            res = eps_ctrl_cfg_set_channel_output(&head_copy);
            break;

        case EPS_CTRL_REQ_GET_CH:
            res = eps_ctrl_cfg_get_channel_output(&head_copy);
            break;

        default:
            // Wrong parameter
            break;
        }
    }

    // If the response was not send correctly, the timeout periodic event will trigger the retry
    eps_sm_request_sent_ok = (EPS_CTRL_DONE == res);

    // Start the timer
    timer_start(&response_timer);

    // USER_CODE_END::onEntry_active_request
}
// GEN_OBJ_END::eps_ctrl_sm_on_entry_active_request


// GEN_OBJ_START::eps_ctrl_sm_on_entry_retry_request
void eps_ctrl_sm_on_entry_retry_request(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::onEntry_retry_request
    // Increase the retry count
    retries ++;

    // Stop timer
    timer_stop(&response_timer);

    // USER_CODE_END::onEntry_retry_request
}
// GEN_OBJ_END::eps_ctrl_sm_on_entry_retry_request


// GEN_OBJ_START::eps_ctrl_sm_on_entry_finish_request
void eps_ctrl_sm_on_entry_finish_request(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::onEntry_finish_request
    // Make sure the timer is not running
    timer_stop(&response_timer);

    // Send event to the eps_ctrl to unblock the thread that issued the current request
    if (retries >= EPS_CTRL_MAX_RETRIES)
    {
        // Adjust status for the error case
        eps_ctrl_cfg_max_retries_notification();
    }

    // Unblock requesting thread
    eps_ctrl_unblock_user_thread();

    // Reset the retries counter
    retries = 0;

    // Remove the request from the queue
    eps_ctrl_queue_pop();

    // USER_CODE_END::onEntry_finish_request
}
// GEN_OBJ_END::eps_ctrl_sm_on_entry_finish_request



// Guard condition functions
// GEN_OBJ_START::eps_ctrl_sm_guard_response_timeout_elapsed
bool eps_ctrl_sm_guard_response_timeout_elapsed(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_response_timeout_elapsed
    bool res = false;

    // Trigger a retry if the request failed to be sent
    if (eps_sm_request_sent_ok == false){
        res = true;
    }
    else
    {
        res = timer_is_elapsed(&response_timer, EPS_CTRL_RESP_TIMEOUT);
    }

    return res;

    // USER_CODE_END::guard_response_timeout_elapsed
}
// GEN_OBJ_END::eps_ctrl_sm_guard_response_timeout_elapsed

// GEN_OBJ_START::eps_ctrl_sm_guard_retries_left
bool eps_ctrl_sm_guard_retries_left(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_retries_left

    // If we didn't reach the max retries, there are retries left
    return ! eps_ctrl_sm_guard_max_retries(instance_id, pSMRoot, pEvent);

    // USER_CODE_END::guard_retries_left
}
// GEN_OBJ_END::eps_ctrl_sm_guard_retries_left

// GEN_OBJ_START::eps_ctrl_sm_guard_max_retries
bool eps_ctrl_sm_guard_max_retries(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_max_retries
    // Your implementation goes here...
    return (retries >= EPS_CTRL_MAX_RETRIES);

    // USER_CODE_END::guard_max_retries
}
// GEN_OBJ_END::eps_ctrl_sm_guard_max_retries

// GEN_OBJ_START::eps_ctrl_sm_guard_queue_not_empty
bool eps_ctrl_sm_guard_queue_not_empty(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_queue_not_empty

    // Return NOT queue_empty
    return ! eps_ctrl_sm_guard_queue_empty(instance_id, pSMRoot, pEvent);

    // USER_CODE_END::guard_queue_not_empty
}
// GEN_OBJ_END::eps_ctrl_sm_guard_queue_not_empty

// GEN_OBJ_START::eps_ctrl_sm_guard_queue_empty
bool eps_ctrl_sm_guard_queue_empty(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_queue_empty
    // Your implementation goes here...
    return eps_ctrl_queue_is_empty();

    // USER_CODE_END::guard_queue_empty
}
// GEN_OBJ_END::eps_ctrl_sm_guard_queue_empty


// Action handlers