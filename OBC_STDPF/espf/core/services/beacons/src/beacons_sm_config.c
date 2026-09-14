/*
 * Copyright (c) EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#include <stddef.h>
#include "libhsm.h"
#include "beacons_sm_config_user.h"
#include "beacons_sm_user.h"


static const sTransition_t tran_Not_Init_ev_init_Init;
static const sTransition_t tran_Init_ev_start_Started;
static const sTransition_t tran_Init_ev_periodic_self;
static const sTransition_t tran_Started_ev_stop_Stopped;
static const sTransition_t tran_Beacon_Wait_Time_ev_periodic_Beacon_Transmission;
static const sTransition_t tran_Beacon_Transmission_ev_periodic_Beacon_Wait_Time;
static const sTransition_t tran_Beacon_Transmission_ev_periodic_Beacon_Wait_Time_1;
static const sTransition_t tran_Beacon_Transmission_ev_periodic_self;
static const sTransition_t tran_Stopped_ev_start_Started;
static const sTransition_t tran_Stopped_ev_periodic_self;


static const sTransition_t* trans_Not_Init[2] =
{
    &tran_Not_Init_ev_init_Init,
    NULL
};

static const sTransition_t* trans_Init[3] =
{
    &tran_Init_ev_start_Started,
    &tran_Init_ev_periodic_self,
    NULL
};

static const sTransition_t* trans_Started[2] =
{
    &tran_Started_ev_stop_Stopped,
    NULL
};

static const sTransition_t* trans_Beacon_Wait_Time[2] =
{
    &tran_Beacon_Wait_Time_ev_periodic_Beacon_Transmission,
    NULL
};

static const sTransition_t* trans_Beacon_Transmission[4] =
{
    &tran_Beacon_Transmission_ev_periodic_Beacon_Wait_Time,
    &tran_Beacon_Transmission_ev_periodic_Beacon_Wait_Time_1,
    &tran_Beacon_Transmission_ev_periodic_self,
    NULL
};

static const sTransition_t* trans_Stopped[3] =
{
    &tran_Stopped_ev_start_Started,
    &tran_Stopped_ev_periodic_self,
    NULL
};


// beacons_sm states forward declarations
static const sState_t state_Not_Init;
static const sState_t state_Init;
static sCompositeState_t state_Started;
static const sState_t state_Beacon_Wait_Time;
static const sState_t state_Beacon_Transmission;
static const sState_t state_Stopped;

// history/active states instance lists definitions
static sState_t *p_Started_inst_history[BEACONS_SM_INSTANCE_CNT] = {
    HSM_UPCAST_STATE(&state_Beacon_Wait_Time),
};

static sState_t *p_Started_inst_active_states[BEACONS_SM_INSTANCE_CNT] = {
    HSM_UPCAST_STATE(&state_Started),
};

static sState_t *p_beacons_sm_inst_history[BEACONS_SM_INSTANCE_CNT] = {
    HSM_UPCAST_STATE(&state_Not_Init),
};

static sState_t *p_beacons_sm_inst_active_states[BEACONS_SM_INSTANCE_CNT] = {
    HSM_UPCAST_STATE(&state_beacons_sm),
};

// beacons_sm root state definition
sCompositeState_t state_beacons_sm =
{
    .state =
    {
        .state_id = STATE_ROOT,
        .pName = "state_beacons_sm",
        .onEntryFunc = NULL,
        .onExitFunc = NULL,
        .pTransitionList = NULL,
        .eType = eHSM_StateType_Composite,
        .pParent = NULL
    },
    .pInitialState = HSM_UPCAST_STATE(&state_Not_Init),
    .instanceCnt = 1,
    .ppHistoryState = p_beacons_sm_inst_history,
    .ppActiveState = p_beacons_sm_inst_active_states
};

static const sState_t state_Not_Init =
{
    .state_id = STATE_NOT_INIT,
    .pName = "state_Not_Init",
    .onEntryFunc = NULL,
    .onExitFunc = NULL,
    .pTransitionList = trans_Not_Init,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_beacons_sm)
};


static const sState_t state_Init =
{
    .state_id = STATE_INIT,
    .pName = "state_Init",
    .onEntryFunc = &beacons_sm_on_entry_Init,
    .onExitFunc = NULL,
    .pTransitionList = trans_Init,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_beacons_sm)
};


static sCompositeState_t state_Started =
{
    .state =
    {
        .state_id = STATE_STARTED,
        .pName = "state_Started",
        .onEntryFunc = &beacons_sm_on_entry_Started,
        .onExitFunc = &beacons_sm_on_exit_Started,
        .pTransitionList = trans_Started,
        .eType = eHSM_StateType_Composite,
        .pParent = HSM_UPCAST_STATE(&state_beacons_sm)
    },
    .pInitialState = HSM_UPCAST_STATE(&state_Beacon_Wait_Time),
    .instanceCnt = 1,
    .ppHistoryState = p_Started_inst_history,
    .ppActiveState = p_Started_inst_active_states
    };


static const sState_t state_Beacon_Wait_Time =
{
    .state_id = STATE_BEACON_WAIT_TIME,
    .pName = "state_Beacon_Wait_Time",
    .onEntryFunc = &beacons_sm_on_entry_Beacon_Wait_Time,
    .onExitFunc = NULL,
    .pTransitionList = trans_Beacon_Wait_Time,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_Started)
};


static const sState_t state_Beacon_Transmission =
{
    .state_id = STATE_BEACON_TRANSMISSION,
    .pName = "state_Beacon_Transmission",
    .onEntryFunc = NULL,
    .onExitFunc = NULL,
    .pTransitionList = trans_Beacon_Transmission,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_Started)
};


static const sState_t state_Stopped =
{
    .state_id = STATE_STOPPED,
    .pName = "state_Stopped",
    .onEntryFunc = &beacons_sm_on_entry_Stopped,
    .onExitFunc = NULL,
    .pTransitionList = trans_Stopped,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_beacons_sm)
};

static const sTransition_t tran_Not_Init_ev_init_Init =
{
    .eventId = ev_beacons_sm_init,
    .guardFunc = NULL,
    .pTargetState = HSM_UPCAST_STATE(&state_Init),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_Init_ev_start_Started =
{
    .eventId = ev_beacons_sm_start,
    .guardFunc = NULL,
    .pTargetState = HSM_UPCAST_STATE(&state_Started),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_Init_ev_periodic_self =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = NULL,
    .pTargetState = NULL,
    .onTransitionActionFunc = &beacons_sm_action_reload_config,
};

static const sTransition_t tran_Started_ev_stop_Stopped =
{
    .eventId = ev_beacons_sm_stop,
    .guardFunc = &beacons_sm_guard_can_stop_operation,
    .pTargetState = HSM_UPCAST_STATE(&state_Stopped),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_Beacon_Wait_Time_ev_periodic_Beacon_Transmission =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &beacons_sm_guard_is_beacon_time_expired,
    .pTargetState = HSM_UPCAST_STATE(&state_Beacon_Transmission),
    .onTransitionActionFunc = &beacons_sm_action_start_beacon_burst,
};

static const sTransition_t tran_Beacon_Transmission_ev_periodic_Beacon_Wait_Time =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &beacons_sm_guard_all_beacons_transmitted,
    .pTargetState = HSM_UPCAST_STATE(&state_Beacon_Wait_Time),
    .onTransitionActionFunc = &beacons_sm_action_reset_send_state,
};

static const sTransition_t tran_Beacon_Transmission_ev_periodic_Beacon_Wait_Time_1 =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &beacons_sm_guard_is_sink_timeout_expired,
    .pTargetState = HSM_UPCAST_STATE(&state_Beacon_Wait_Time),
    .onTransitionActionFunc = &beacons_sm_action_log_sink_timeout_error,
};

static const sTransition_t tran_Beacon_Transmission_ev_periodic_self =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &beacons_sm_guard_can_continue_transmission,
    .pTargetState = NULL,
    .onTransitionActionFunc = &beacons_sm_action_send_beacon,
};

static const sTransition_t tran_Stopped_ev_start_Started =
{
    .eventId = ev_beacons_sm_start,
    .guardFunc = NULL,
    .pTargetState = HSM_UPCAST_STATE(&state_Started),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_Stopped_ev_periodic_self =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = NULL,
    .pTargetState = NULL,
    .onTransitionActionFunc = &beacons_sm_action_reload_config,
};
