/*
 * Copyright (c) EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef EPS_CTRL_SM_USER_H
#define EPS_CTRL_SM_USER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "libhsm.h"

// State identifiers
enum eps_ctrl_sm_states
{
    STATE_ROOT,
    STATE_OFF,
    STATE_IDLE,
    STATE_ACTIVE_REQUEST,
    STATE_RETRY_REQUEST,
    STATE_FINISH_REQUEST,
    STATE_MAX
};

// User state machine events
enum eps_ctrl_sm_events
{
    evStart = eHSM_StdEvent_UserEvStart,
    ev_eps_ctrl_sm_initialized,
    ev_eps_ctrl_sm_new_request,
    ev_eps_ctrl_sm_response_received,
    evMAX
};

// State machine root object
extern sCompositeState_t state_eps_ctrl_sm;

// Use this macro to access the SM instance instead of a direct reference to
// state_eps_ctrl_sm variable
#define eps_ctrl_sm_instance  HSM_UPCAST_STATE(&state_eps_ctrl_sm)

// Number of SM instances configured in the SM model
#define EPS_CTRL_SM_INSTANCE_CNT    (1U)

#ifdef __cplusplus
};
#endif

#endif  // #ifndef EPS_CTRL_SM_USER_H