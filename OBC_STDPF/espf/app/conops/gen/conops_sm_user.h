/*
 * Copyright (c) EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef CONOPS_SM_USER_H
#define CONOPS_SM_USER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "libhsm.h"

// State identifiers
enum conops_sm_states
{
    STATE_ROOT,
    STATE_SAFE,
    STATE_SAFE_ENTRY,
    STATE_CONTROL,
    STATE_NO_CONTROL,
    STATE_IDLE,
    STATE_MISSION,
    STATE_MAX
};

// User state machine events
enum conops_sm_events
{
    evStart = eHSM_StdEvent_UserEvStart,
    ev_conops_sm_force_enter_idle,
    ev_conops_sm_fdir_lvl_updated,
    ev_conops_sm_force_enter_safe,
    ev_conops_sm_force_enter_mission,
    evMAX
};

// State machine root object
extern sCompositeState_t state_conops_sm;

// Use this macro to access the SM instance instead of a direct reference to
// state_conops_sm variable
#define conops_sm_instance  HSM_UPCAST_STATE(&state_conops_sm)

// Number of SM instances configured in the SM model
#define CONOPS_SM_INSTANCE_CNT    (1U)

#ifdef __cplusplus
};
#endif

#endif  // #ifndef CONOPS_SM_USER_H