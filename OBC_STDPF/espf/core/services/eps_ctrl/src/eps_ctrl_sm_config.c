/*
 * Copyright (c) EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#include <stddef.h>
#include "libhsm.h"
#include "eps_ctrl_sm_config_user.h"
#include "eps_ctrl_sm_user.h"


static const sTransition_t tran_off_ev_initialized_idle;
static const sTransition_t tran_idle_ev_new_request_active_request;
static const sTransition_t tran_active_request_ev_periodic_retry_request;
static const sTransition_t tran_active_request_ev_response_received_finish_request;
static const sTransition_t tran_retry_request_ev_periodic_active_request;
static const sTransition_t tran_retry_request_ev_periodic_finish_request;
static const sTransition_t tran_finish_request_ev_periodic_active_request;
static const sTransition_t tran_finish_request_ev_periodic_idle;


static const sTransition_t* trans_off[2] =
{
    &tran_off_ev_initialized_idle,
    NULL
};

static const sTransition_t* trans_idle[2] =
{
    &tran_idle_ev_new_request_active_request,
    NULL
};

static const sTransition_t* trans_active_request[3] =
{
    &tran_active_request_ev_periodic_retry_request,
    &tran_active_request_ev_response_received_finish_request,
    NULL
};

static const sTransition_t* trans_retry_request[3] =
{
    &tran_retry_request_ev_periodic_active_request,
    &tran_retry_request_ev_periodic_finish_request,
    NULL
};

static const sTransition_t* trans_finish_request[3] =
{
    &tran_finish_request_ev_periodic_active_request,
    &tran_finish_request_ev_periodic_idle,
    NULL
};


// eps_ctrl_sm states forward declarations
static const sState_t state_off;
static const sState_t state_idle;
static const sState_t state_active_request;
static const sState_t state_retry_request;
static const sState_t state_finish_request;

// history/active states instance lists definitions

static sState_t *p_eps_ctrl_sm_inst_history[EPS_CTRL_SM_INSTANCE_CNT] = {
    HSM_UPCAST_STATE(&state_off),
};

static sState_t *p_eps_ctrl_sm_inst_active_states[EPS_CTRL_SM_INSTANCE_CNT] = {
    HSM_UPCAST_STATE(&state_eps_ctrl_sm),
};

// eps_ctrl_sm root state definition
sCompositeState_t state_eps_ctrl_sm =
{
    .state =
    {
        .state_id = STATE_ROOT,
        .pName = "state_eps_ctrl_sm",
        .onEntryFunc = NULL,
        .onExitFunc = NULL,
        .pTransitionList = NULL,
        .eType = eHSM_StateType_Composite,
        .pParent = NULL
    },
    .pInitialState = HSM_UPCAST_STATE(&state_off),
    .instanceCnt = 1,
    .ppHistoryState = p_eps_ctrl_sm_inst_history,
    .ppActiveState = p_eps_ctrl_sm_inst_active_states
};

static const sState_t state_off =
{
    .state_id = STATE_OFF,
    .pName = "state_off",
    .onEntryFunc = NULL,
    .onExitFunc = &eps_ctrl_sm_on_exit_off,
    .pTransitionList = trans_off,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_eps_ctrl_sm)
};


static const sState_t state_idle =
{
    .state_id = STATE_IDLE,
    .pName = "state_idle",
    .onEntryFunc = NULL,
    .onExitFunc = NULL,
    .pTransitionList = trans_idle,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_eps_ctrl_sm)
};


static const sState_t state_active_request =
{
    .state_id = STATE_ACTIVE_REQUEST,
    .pName = "state_active_request",
    .onEntryFunc = &eps_ctrl_sm_on_entry_active_request,
    .onExitFunc = NULL,
    .pTransitionList = trans_active_request,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_eps_ctrl_sm)
};


static const sState_t state_retry_request =
{
    .state_id = STATE_RETRY_REQUEST,
    .pName = "state_retry_request",
    .onEntryFunc = &eps_ctrl_sm_on_entry_retry_request,
    .onExitFunc = NULL,
    .pTransitionList = trans_retry_request,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_eps_ctrl_sm)
};


static const sState_t state_finish_request =
{
    .state_id = STATE_FINISH_REQUEST,
    .pName = "state_finish_request",
    .onEntryFunc = &eps_ctrl_sm_on_entry_finish_request,
    .onExitFunc = NULL,
    .pTransitionList = trans_finish_request,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_eps_ctrl_sm)
};

static const sTransition_t tran_off_ev_initialized_idle =
{
    .eventId = ev_eps_ctrl_sm_initialized,
    .guardFunc = NULL,
    .pTargetState = HSM_UPCAST_STATE(&state_idle),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_idle_ev_new_request_active_request =
{
    .eventId = ev_eps_ctrl_sm_new_request,
    .guardFunc = NULL,
    .pTargetState = HSM_UPCAST_STATE(&state_active_request),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_active_request_ev_periodic_retry_request =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &eps_ctrl_sm_guard_response_timeout_elapsed,
    .pTargetState = HSM_UPCAST_STATE(&state_retry_request),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_active_request_ev_response_received_finish_request =
{
    .eventId = ev_eps_ctrl_sm_response_received,
    .guardFunc = NULL,
    .pTargetState = HSM_UPCAST_STATE(&state_finish_request),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_retry_request_ev_periodic_active_request =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &eps_ctrl_sm_guard_retries_left,
    .pTargetState = HSM_UPCAST_STATE(&state_active_request),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_retry_request_ev_periodic_finish_request =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &eps_ctrl_sm_guard_max_retries,
    .pTargetState = HSM_UPCAST_STATE(&state_finish_request),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_finish_request_ev_periodic_active_request =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &eps_ctrl_sm_guard_queue_not_empty,
    .pTargetState = HSM_UPCAST_STATE(&state_active_request),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_finish_request_ev_periodic_idle =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &eps_ctrl_sm_guard_queue_empty,
    .pTargetState = HSM_UPCAST_STATE(&state_idle),
    .onTransitionActionFunc = NULL
};
