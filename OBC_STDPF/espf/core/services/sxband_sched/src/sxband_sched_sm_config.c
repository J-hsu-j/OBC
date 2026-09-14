/*
 * Copyright (c) EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#include <stddef.h>
#include "libhsm.h"
#include "sxband_sched_sm_config_user.h"
#include "sxband_sched_sm_user.h"


static const sTransition_t tran_not_init_ev_init_init;
static const sTransition_t tran_idle_ev_start_in_progress;
static const sTransition_t tran_wait_file_tx_ev_cmd_confirmed_file_tx_finished;
static const sTransition_t tran_wait_file_tx_ev_periodic_file_tx_finished;
static const sTransition_t tran_file_tx_finished_ev_periodic_wait_file_tx;
static const sTransition_t tran_file_tx_finished_ev_periodic_prepare_cmd;
static const sTransition_t tran_file_tx_finished_ev_periodic_idle;
static const sTransition_t tran_prepare_cmd_ev_periodic_idle;
static const sTransition_t tran_prepare_cmd_ev_periodic_wait_cmd_result;
static const sTransition_t tran_prepare_cmd_ev_periodic_file_tx_in_progress;
static const sTransition_t tran_prepare_cmd_ev_periodic_self;
static const sTransition_t tran_wait_cmd_result_ev_cmd_confirmed_cmd_finished;
static const sTransition_t tran_wait_cmd_result_ev_periodic_cmd_finished;
static const sTransition_t tran_cmd_finished_ev_periodic_prepare_cmd;
static const sTransition_t tran_cmd_finished_ev_periodic_idle;
static const sTransition_t tran_in_progress_ev_stop_idle;
static const sTransition_t tran_in_progress_ev_failure_check_idle;


static const sTransition_t* trans_not_init[2] =
{
    &tran_not_init_ev_init_init,
    NULL
};

static const sTransition_t* trans_idle[2] =
{
    &tran_idle_ev_start_in_progress,
    NULL
};

static const sTransition_t* trans_wait_file_tx[3] =
{
    &tran_wait_file_tx_ev_cmd_confirmed_file_tx_finished,
    &tran_wait_file_tx_ev_periodic_file_tx_finished,
    NULL
};

static const sTransition_t* trans_file_tx_finished[4] =
{
    &tran_file_tx_finished_ev_periodic_wait_file_tx,
    &tran_file_tx_finished_ev_periodic_prepare_cmd,
    &tran_file_tx_finished_ev_periodic_idle,
    NULL
};

static const sTransition_t* trans_prepare_cmd[5] =
{
    &tran_prepare_cmd_ev_periodic_idle,
    &tran_prepare_cmd_ev_periodic_wait_cmd_result,
    &tran_prepare_cmd_ev_periodic_file_tx_in_progress,
    &tran_prepare_cmd_ev_periodic_self,
    NULL
};

static const sTransition_t* trans_wait_cmd_result[3] =
{
    &tran_wait_cmd_result_ev_cmd_confirmed_cmd_finished,
    &tran_wait_cmd_result_ev_periodic_cmd_finished,
    NULL
};

static const sTransition_t* trans_cmd_finished[3] =
{
    &tran_cmd_finished_ev_periodic_prepare_cmd,
    &tran_cmd_finished_ev_periodic_idle,
    NULL
};

static const sTransition_t* trans_in_progress[3] =
{
    &tran_in_progress_ev_stop_idle,
    &tran_in_progress_ev_failure_check_idle,
    NULL
};


// sxband_sched_sm states forward declarations
static const sState_t state_not_init;
static sCompositeState_t state_init;
static const sState_t state_idle;
static const sState_t state_wait_file_tx;
static const sState_t state_file_tx_finished;
static sCompositeState_t state_file_tx_in_progress;
static const sState_t state_prepare_cmd;
static const sState_t state_wait_cmd_result;
static const sState_t state_cmd_finished;
static sCompositeState_t state_in_progress;

// history/active states instance lists definitions
static sState_t *p_init_inst_history[SXBAND_SCHED_SM_INSTANCE_CNT] = {
    HSM_UPCAST_STATE(&state_idle),
};

static sState_t *p_init_inst_active_states[SXBAND_SCHED_SM_INSTANCE_CNT] = {
    HSM_UPCAST_STATE(&state_init),
};
static sState_t *p_file_tx_in_progress_inst_history[SXBAND_SCHED_SM_INSTANCE_CNT] = {
    HSM_UPCAST_STATE(&state_wait_file_tx),
};

static sState_t *p_file_tx_in_progress_inst_active_states[SXBAND_SCHED_SM_INSTANCE_CNT] = {
    HSM_UPCAST_STATE(&state_file_tx_in_progress),
};
static sState_t *p_in_progress_inst_history[SXBAND_SCHED_SM_INSTANCE_CNT] = {
    HSM_UPCAST_STATE(&state_prepare_cmd),
};

static sState_t *p_in_progress_inst_active_states[SXBAND_SCHED_SM_INSTANCE_CNT] = {
    HSM_UPCAST_STATE(&state_in_progress),
};

static sState_t *p_sxband_sched_sm_inst_history[SXBAND_SCHED_SM_INSTANCE_CNT] = {
    HSM_UPCAST_STATE(&state_not_init),
};

static sState_t *p_sxband_sched_sm_inst_active_states[SXBAND_SCHED_SM_INSTANCE_CNT] = {
    HSM_UPCAST_STATE(&state_sxband_sched_sm),
};

// sxband_sched_sm root state definition
sCompositeState_t state_sxband_sched_sm =
{
    .state =
    {
        .state_id = STATE_ROOT,
        .pName = "state_sxband_sched_sm",
        .onEntryFunc = NULL,
        .onExitFunc = NULL,
        .pTransitionList = NULL,
        .eType = eHSM_StateType_Composite,
        .pParent = NULL
    },
    .pInitialState = HSM_UPCAST_STATE(&state_not_init),
    .instanceCnt = 1,
    .ppHistoryState = p_sxband_sched_sm_inst_history,
    .ppActiveState = p_sxband_sched_sm_inst_active_states
};

static const sState_t state_not_init =
{
    .state_id = STATE_NOT_INIT,
    .pName = "state_not_init",
    .onEntryFunc = NULL,
    .onExitFunc = NULL,
    .pTransitionList = trans_not_init,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_sxband_sched_sm)
};


static sCompositeState_t state_init =
{
    .state =
    {
        .state_id = STATE_INIT,
        .pName = "state_init",
        .onEntryFunc = NULL,
        .onExitFunc = NULL,
        .pTransitionList = NULL,
        .eType = eHSM_StateType_Composite,
        .pParent = HSM_UPCAST_STATE(&state_sxband_sched_sm)
    },
    .pInitialState = HSM_UPCAST_STATE(&state_idle),
    .instanceCnt = 1,
    .ppHistoryState = p_init_inst_history,
    .ppActiveState = p_init_inst_active_states
    };


static const sState_t state_idle =
{
    .state_id = STATE_IDLE,
    .pName = "state_idle",
    .onEntryFunc = NULL,
    .onExitFunc = NULL,
    .pTransitionList = trans_idle,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_init)
};


static const sState_t state_wait_file_tx =
{
    .state_id = STATE_WAIT_FILE_TX,
    .pName = "state_wait_file_tx",
    .onEntryFunc = &sxband_sched_sm_on_entry_wait_file_tx,
    .onExitFunc = NULL,
    .pTransitionList = trans_wait_file_tx,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_file_tx_in_progress)
};


static const sState_t state_file_tx_finished =
{
    .state_id = STATE_FILE_TX_FINISHED,
    .pName = "state_file_tx_finished",
    .onEntryFunc = &sxband_sched_sm_on_entry_file_tx_finished,
    .onExitFunc = NULL,
    .pTransitionList = trans_file_tx_finished,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_file_tx_in_progress)
};


static sCompositeState_t state_file_tx_in_progress =
{
    .state =
    {
        .state_id = STATE_FILE_TX_IN_PROGRESS,
        .pName = "state_file_tx_in_progress",
        .onEntryFunc = NULL,
        .onExitFunc = &sxband_sched_sm_on_exit_file_tx_in_progress,
        .pTransitionList = NULL,
        .eType = eHSM_StateType_Composite,
        .pParent = HSM_UPCAST_STATE(&state_in_progress)
    },
    .pInitialState = HSM_UPCAST_STATE(&state_wait_file_tx),
    .instanceCnt = 1,
    .ppHistoryState = p_file_tx_in_progress_inst_history,
    .ppActiveState = p_file_tx_in_progress_inst_active_states
    };


static const sState_t state_prepare_cmd =
{
    .state_id = STATE_PREPARE_CMD,
    .pName = "state_prepare_cmd",
    .onEntryFunc = &sxband_sched_sm_on_entry_prepare_cmd,
    .onExitFunc = NULL,
    .pTransitionList = trans_prepare_cmd,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_in_progress)
};


static const sState_t state_wait_cmd_result =
{
    .state_id = STATE_WAIT_CMD_RESULT,
    .pName = "state_wait_cmd_result",
    .onEntryFunc = NULL,
    .onExitFunc = NULL,
    .pTransitionList = trans_wait_cmd_result,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_in_progress)
};


static const sState_t state_cmd_finished =
{
    .state_id = STATE_CMD_FINISHED,
    .pName = "state_cmd_finished",
    .onEntryFunc = &sxband_sched_sm_on_entry_cmd_finished,
    .onExitFunc = NULL,
    .pTransitionList = trans_cmd_finished,
    .eType = eHSM_StateType_Simple,
    .pParent = HSM_UPCAST_STATE(&state_in_progress)
};


static sCompositeState_t state_in_progress =
{
    .state =
    {
        .state_id = STATE_IN_PROGRESS,
        .pName = "state_in_progress",
        .onEntryFunc = &sxband_sched_sm_on_entry_in_progress,
        .onExitFunc = &sxband_sched_sm_on_exit_in_progress,
        .pTransitionList = trans_in_progress,
        .eType = eHSM_StateType_Composite,
        .pParent = HSM_UPCAST_STATE(&state_init)
    },
    .pInitialState = HSM_UPCAST_STATE(&state_prepare_cmd),
    .instanceCnt = 1,
    .ppHistoryState = p_in_progress_inst_history,
    .ppActiveState = p_in_progress_inst_active_states
    };

static const sTransition_t tran_not_init_ev_init_init =
{
    .eventId = ev_sxband_sched_sm_init,
    .guardFunc = NULL,
    .pTargetState = HSM_UPCAST_STATE(&state_init),
    .onTransitionActionFunc = NULL
};

static const sTransition_t tran_idle_ev_start_in_progress =
{
    .eventId = ev_sxband_sched_sm_start,
    .guardFunc = &sxband_sched_sm_guard_is_valid_context,
    .pTargetState = HSM_UPCAST_STATE(&state_in_progress),
    .onTransitionActionFunc = &sxband_sched_sm_action_reset_cmd_iterator,
};

static const sTransition_t tran_wait_file_tx_ev_cmd_confirmed_file_tx_finished =
{
    .eventId = ev_sxband_sched_sm_cmd_confirmed,
    .guardFunc = NULL,
    .pTargetState = HSM_UPCAST_STATE(&state_file_tx_finished),
    .onTransitionActionFunc = &sxband_sched_sm_action_update_cmd_status,
};

static const sTransition_t tran_wait_file_tx_ev_periodic_file_tx_finished =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &sxband_sched_sm_guard_is_cmd_timeout_elapsed,
    .pTargetState = HSM_UPCAST_STATE(&state_file_tx_finished),
    .onTransitionActionFunc = &sxband_sched_sm_action_update_cmd_status_timeout,
};

static const sTransition_t tran_file_tx_finished_ev_periodic_wait_file_tx =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &sxband_sched_sm_guard_has_more_files,
    .pTargetState = HSM_UPCAST_STATE(&state_wait_file_tx),
    .onTransitionActionFunc = &sxband_sched_sm_action_send_next_file_cmd,
};

static const sTransition_t tran_file_tx_finished_ev_periodic_prepare_cmd =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &sxband_sched_sm_guard_more_cmd_to_process,
    .pTargetState = HSM_UPCAST_STATE(&state_prepare_cmd),
    .onTransitionActionFunc = &sxband_sched_sm_action_load_next_cmd,
};

static const sTransition_t tran_file_tx_finished_ev_periodic_idle =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &sxband_sched_sm_guard_no_more_commands,
    .pTargetState = HSM_UPCAST_STATE(&state_idle),
    .onTransitionActionFunc = &sxband_sched_sm_action_deinit_sm_context,
};

static const sTransition_t tran_prepare_cmd_ev_periodic_idle =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &sxband_sched_sm_guard_no_more_commands,
    .pTargetState = HSM_UPCAST_STATE(&state_idle),
    .onTransitionActionFunc = &sxband_sched_sm_action_deinit_sm_context,
};

static const sTransition_t tran_prepare_cmd_ev_periodic_wait_cmd_result =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &sxband_sched_sm_guard_is_regular_cmd,
    .pTargetState = HSM_UPCAST_STATE(&state_wait_cmd_result),
    .onTransitionActionFunc = &sxband_sched_sm_action_send_next_cmd,
};

static const sTransition_t tran_prepare_cmd_ev_periodic_file_tx_in_progress =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &sxband_sched_sm_guard_can_iterate_files_with_pattern,
    .pTargetState = HSM_UPCAST_STATE(&state_file_tx_in_progress),
    .onTransitionActionFunc = &sxband_sched_sm_action_send_first_file_cmd,
};

static const sTransition_t tran_prepare_cmd_ev_periodic_self =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &sxband_sched_sm_guard_empty_pattern,
    .pTargetState = NULL,
    .onTransitionActionFunc = &sxband_sched_sm_action_load_next_cmd_empty_pattern,
};

static const sTransition_t tran_wait_cmd_result_ev_cmd_confirmed_cmd_finished =
{
    .eventId = ev_sxband_sched_sm_cmd_confirmed,
    .guardFunc = NULL,
    .pTargetState = HSM_UPCAST_STATE(&state_cmd_finished),
    .onTransitionActionFunc = &sxband_sched_sm_action_update_cmd_status,
};

static const sTransition_t tran_wait_cmd_result_ev_periodic_cmd_finished =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &sxband_sched_sm_guard_is_cmd_timeout_elapsed,
    .pTargetState = HSM_UPCAST_STATE(&state_cmd_finished),
    .onTransitionActionFunc = &sxband_sched_sm_action_update_cmd_status_timeout,
};

static const sTransition_t tran_cmd_finished_ev_periodic_prepare_cmd =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &sxband_sched_sm_guard_has_more_commands,
    .pTargetState = HSM_UPCAST_STATE(&state_prepare_cmd),
    .onTransitionActionFunc = &sxband_sched_sm_action_load_next_cmd,
};

static const sTransition_t tran_cmd_finished_ev_periodic_idle =
{
    .eventId = eHSM_StdEvent_Periodic,
    .guardFunc = &sxband_sched_sm_guard_no_more_commands,
    .pTargetState = HSM_UPCAST_STATE(&state_idle),
    .onTransitionActionFunc = &sxband_sched_sm_action_deinit_sm_context,
};

static const sTransition_t tran_in_progress_ev_stop_idle =
{
    .eventId = ev_sxband_sched_sm_stop,
    .guardFunc = NULL,
    .pTargetState = HSM_UPCAST_STATE(&state_idle),
    .onTransitionActionFunc = &sxband_sched_sm_action_deinit_sm_context_stop,
};

static const sTransition_t tran_in_progress_ev_failure_check_idle =
{
    .eventId = ev_sxband_sched_sm_failure_check,
    .guardFunc = &sxband_sched_sm_guard_general_failure,
    .pTargetState = HSM_UPCAST_STATE(&state_idle),
    .onTransitionActionFunc = &sxband_sched_sm_action_deinit_sm_context_fail,
};
