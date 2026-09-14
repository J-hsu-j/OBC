/*
 * Copyright (c) EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#include <stddef.h>
#include "libhsm.h"
#include "conops_sm_config_user.h"
#include "conops_sm_user.h"


static const sTransition_t tran_Safe_ev_force_enter_idle_Idle;
static const sTransition_t tran_Safe_entry_ev_periodic_Control;
static const sTransition_t tran_Safe_entry_ev_periodic_No_control;
static const sTransition_t tran_Control_ev_fdir_lvl_updated_No_control;
static const sTransition_t tran_Control_ev_periodic_self;
static const sTransition_t tran_No_control_ev_fdir_lvl_updated_Control;
static const sTransition_t tran_No_control_ev_periodic_Control;
static const sTransition_t tran_Idle_ev_force_enter_safe_Safe;
static const sTransition_t tran_Idle_ev_fdir_lvl_updated_Safe;
static const sTransition_t tran_Idle_ev_force_enter_mission_Mission;
static const sTransition_t tran_Mission_ev_force_enter_safe_Safe;
static const sTransition_t tran_Mission_ev_fdir_lvl_updated_Safe;
static const sTransition_t tran_Mission_ev_force_enter_idle_Idle;
static const sTransition_t tran_Mission_ev_periodic_Idle;


static const sTransition_t* trans_Safe[2] =
{
    &tran_Safe_ev_force_enter_idle_Idle,
    NULL
};

static const sTransition_t* trans_Safe_entry[3] =
{
    &tran_Safe_entry_ev_periodic_Control,
    &tran_Safe_entry_ev_periodic_No_control,
    NULL
};

static const sTransition_t* trans_Control[3] =
{
    &tran_Control_ev_fdir_lvl_updated_No_control,
    &tran_Control_ev_periodic_self,
    NULL
};

static const sTransition_t* trans_No_control[3] =
{
    &tran_No_control_ev_fdir_lvl_updated_Control,
    &tran_No_control_ev_periodic_Control,
    NULL
};

static const sTransition_t* trans_Idle[4] =
{
    &tran_Idle_ev_force_enter_safe_Safe,
    &tran_Idle_ev_fdir_lvl_updated_Safe,
    &tran_Idle_ev_force_enter_mission_Mission,
    NULL
};

static const sTransition_t* trans_Mission[5] =
{
    &tran_Mission_ev_force_enter_safe_Safe,
    &tran_Mission_ev_fdir_lvl_updated_Safe,
    &tran_Mission_ev_force_enter_idle_Idle,
    &tran_Mission_ev_periodic_Idle,
    NULL
};


// conops_sm states forward declarations
static sCompositeState_t state_Safe;
static const sState_t state_Safe_entry;
static const sState_t state_Control;
static const sState_t state_No_control;
static const sState_t state_Idle;
static const sState_t state_Mission;

// history/active states instance lists definitions
static sState_t *p_Safe_inst_history[CONOPS_SM_INSTANCE_CNT] = {
    HSM_UPCAST_STATE(&state_Safe_entry),
};

static sState_t *p_Safe_inst_active_states[CONOPS_SM_INSTANCE_CNT] = {
    HSM_UPCAST_STATE(&state_Safe),
};

static sState_t *p_conops_sm_inst_history[CONOPS_SM_INSTANCE_CNT] = {
    HSM_UPCAST_STATE(&state_Safe),
};

static sState_t *p_conops_sm_inst_active_states[CONOPS_SM_INSTANCE_CNT] = {
    HSM_UPCAST_STATE(&state_conops_sm),
};

// conops_sm root state definition
sCompositeState_t state_conops_sm =
{
    .state =
    {
        .state_id = STATE_ROOT,
        .pName = "state_conops_sm",
        .onEntryFunc = NULL,
        .onExitFunc = NULL,
        .pTransitionList = NULL,
        .eType = eHSM_StateType_Composite,
        .pParent = NULL
    },
    .pInitialState = HSM_UPCAST_STATE(&state_Safe),
    .instanceCnt = 1,
    .ppHistoryState = p_conops_sm_inst_history,
    .ppActiveState = p_conops_sm_inst_active_states
};

static sCompositeState_t state_Safe =
{
    .state =
    {
        .state_id = STATE_SAFE,
        .pName = "state_Safe",
        .onEntryFunc = &conops_sm_on_entry_Safe,
        .onExitFunc = NULL,
        .pTransitionList = trans_Safe,
        .eType = eHSM_StateType_Composite,
        .pParent = HSM_UPCAST_STATE(&state_conops_sm)
    },
    .pInitialState = HSM_UPCAST_STATE(&state_Safe_entry),
    .instanceCnt = 1,
    .ppHistoryState = p_Safe_inst_history,
    .ppActiveState = p_Safe_inst_active_states
    };


static const sState_t state_Safe_entry =
{
    .state_id = STATE_SAFE_ENTRY,
    .pName = "state_Safe_entry",
    .onEntryFunc = NULL,
    .onExitFunc = NULL,
    .pTransitionList = trans_Safe_entry,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_Safe)
};


static const sState_t state_Control =
{
    .state_id = STATE_CONTROL,
    .pName = "state_Control",
    .onEntryFunc = &conops_sm_on_entry_Control,
    .onExitFunc = NULL,
    .pTransitionList = trans_Control,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_Safe)
};


static const sState_t state_No_control =
{
    .state_id = STATE_NO_CONTROL,
    .pName = "state_No_control",
    .onEntryFunc = &conops_sm_on_entry_No_control,
    .onExitFunc = NULL,
    .pTransitionList = trans_No_control,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_Safe)
};


static const sState_t state_Idle =
{
    .state_id = STATE_IDLE,
    .pName = "state_Idle",
    .onEntryFunc = &conops_sm_on_entry_Idle,
    .onExitFunc = NULL,
    .pTransitionList = trans_Idle,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_conops_sm)
};


static const sState_t state_Mission =
{
    .state_id = STATE_MISSION,
    .pName = "state_Mission",
    .onEntryFunc = &conops_sm_on_entry_Mission,
    .onExitFunc = &conops_sm_on_exit_Mission,
    .pTransitionList = trans_Mission,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_conops_sm)
};

static const sTransition_t tran_Safe_ev_force_enter_idle_Idle =
{
    .eventId = ev_conops_sm_force_enter_idle,
    .guardFunc = &conops_sm_guard_is_fdir_idle,
    .pTargetState = HSM_UPCAST_STATE(&state_Idle),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_Safe_entry_ev_periodic_Control =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &conops_sm_guard_has_control,
    .pTargetState = HSM_UPCAST_STATE(&state_Control),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_Safe_entry_ev_periodic_No_control =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &conops_sm_guard_hasno_control,
    .pTargetState = HSM_UPCAST_STATE(&state_No_control),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_Control_ev_fdir_lvl_updated_No_control =
{
    .eventId = ev_conops_sm_fdir_lvl_updated,
    .guardFunc = &conops_sm_guard_is_fdir_critical,
    .pTargetState = HSM_UPCAST_STATE(&state_No_control),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_Control_ev_periodic_self =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = NULL,
    .pTargetState = NULL,
    .onTransitionActionFunc = &conops_sm_action_detumble,
};

static const sTransition_t tran_No_control_ev_fdir_lvl_updated_Control =
{
    .eventId = ev_conops_sm_fdir_lvl_updated,
    .guardFunc = &conops_sm_guard_has_control,
    .pTargetState = HSM_UPCAST_STATE(&state_Control),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_No_control_ev_periodic_Control =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &conops_sm_guard_has_control,
    .pTargetState = HSM_UPCAST_STATE(&state_Control),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_Idle_ev_force_enter_safe_Safe =
{
    .eventId = ev_conops_sm_force_enter_safe,
    .guardFunc = NULL,
    .pTargetState = HSM_UPCAST_STATE(&state_Safe),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_Idle_ev_fdir_lvl_updated_Safe =
{
    .eventId = ev_conops_sm_fdir_lvl_updated,
    .guardFunc = &conops_sm_guard_is_fdir_safe,
    .pTargetState = HSM_UPCAST_STATE(&state_Safe),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_Idle_ev_force_enter_mission_Mission =
{
    .eventId = ev_conops_sm_force_enter_mission,
    .guardFunc = NULL,
    .pTargetState = HSM_UPCAST_STATE(&state_Mission),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_Mission_ev_force_enter_safe_Safe =
{
    .eventId = ev_conops_sm_force_enter_safe,
    .guardFunc = NULL,
    .pTargetState = HSM_UPCAST_STATE(&state_Safe),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_Mission_ev_fdir_lvl_updated_Safe =
{
    .eventId = ev_conops_sm_fdir_lvl_updated,
    .guardFunc = &conops_sm_guard_is_fdir_safe,
    .pTargetState = HSM_UPCAST_STATE(&state_Safe),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_Mission_ev_force_enter_idle_Idle =
{
    .eventId = ev_conops_sm_force_enter_idle,
    .guardFunc = NULL,
    .pTargetState = HSM_UPCAST_STATE(&state_Idle),
    .onTransitionActionFunc = &conops_sm_action_mission_to_idle,
};

static const sTransition_t tran_Mission_ev_periodic_Idle =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &conops_sm_guard_mission_timer_expired,
    .pTargetState = HSM_UPCAST_STATE(&state_Idle),
    .onTransitionActionFunc = NULL
};
