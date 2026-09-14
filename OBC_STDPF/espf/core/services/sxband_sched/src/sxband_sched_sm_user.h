/*
 * Copyright (c) EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef SXBAND_SCHED_SM_USER_H
#define SXBAND_SCHED_SM_USER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "libhsm.h"

// State identifiers
enum sxband_sched_sm_states
{
    STATE_ROOT,
    STATE_NOT_INIT,
    STATE_INIT,
    STATE_IDLE,
    STATE_WAIT_FILE_TX,
    STATE_FILE_TX_FINISHED,
    STATE_FILE_TX_IN_PROGRESS,
    STATE_PREPARE_CMD,
    STATE_WAIT_CMD_RESULT,
    STATE_CMD_FINISHED,
    STATE_IN_PROGRESS,
    STATE_MAX
};

// User state machine events
enum sxband_sched_sm_events
{
    evStart = eHSM_StdEvent_UserEvStart,
    ev_sxband_sched_sm_init,
    ev_sxband_sched_sm_start,
    ev_sxband_sched_sm_cmd_confirmed,
    ev_sxband_sched_sm_stop,
    ev_sxband_sched_sm_failure_check,
    evMAX
};

// State machine root object
extern sCompositeState_t state_sxband_sched_sm;

// Use this macro to access the SM instance instead of a direct reference to
// state_sxband_sched_sm variable
#define sxband_sched_sm_instance  HSM_UPCAST_STATE(&state_sxband_sched_sm)

// Number of SM instances configured in the SM model
#define SXBAND_SCHED_SM_INSTANCE_CNT    (1U)

#ifdef __cplusplus
};
#endif

#endif  // #ifndef SXBAND_SCHED_SM_USER_H