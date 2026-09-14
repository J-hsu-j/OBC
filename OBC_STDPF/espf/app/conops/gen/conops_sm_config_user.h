/*
 * Copyright (c) EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef CONOPS_SM_CONFIG_USER_H
#define CONOPS_SM_CONFIG_USER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "libhsm.h"

// USER_CODE_START::@main@
// Any code placed between these two tags will be preserved during code generation!
// USER_CODE_END::@main@

// Entry/Exit functions
void conops_sm_on_entry_Safe(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void conops_sm_on_entry_Control(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void conops_sm_on_entry_No_control(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void conops_sm_on_entry_Idle(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void conops_sm_on_entry_Mission(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void conops_sm_on_exit_Mission(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);

// Guard condition functions
bool conops_sm_guard_is_fdir_idle(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent);
bool conops_sm_guard_has_control(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent);
bool conops_sm_guard_hasno_control(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent);
bool conops_sm_guard_is_fdir_critical(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent);
bool conops_sm_guard_is_fdir_safe(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent);
bool conops_sm_guard_mission_timer_expired(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent);

// Action handlers
void conops_sm_action_detumble(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void conops_sm_action_mission_to_idle(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);

#ifdef __cplusplus
};
#endif

#endif  // #ifndef CONOPS_SM_CONFIG_USER_H