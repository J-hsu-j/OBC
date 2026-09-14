/*
 * Copyright (c) EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#include "libhsm.h"
#include "conops_sm_config_user.h"

// USER_CODE_START::@main@
#include "conops.h"
#include "conops_internal.h"
#include "payload_ctrl.h"
#include "conops_sm_user.h"
#include "aocs_cntrl.h"
#include "fdir_srv.h"
#include "timer.h"

#include <string.h>

/** @brief Timer used to exit Mission mode after a certain timeout. Started on entry in Mission mode.
 *         Checked and stopped in the main task of conops.
 */
static timer_handle_t mission_mode_timer = { .timestamp = 0, .is_running = SAFE_FALSE };

/** @brief Value of the mission mode timer's timeout. This is set on entry in Mission mode, if provided */
static uint32_t mission_mode_timeout = 0;

static bool conops_sm_has_control(void)
{
    aocs_cms_status_t cms_status;
    const bool read_status = aocs_cntrl_get_cms_status(&cms_status);
    return ((FDIR_LEVEL_CRITICAL > fdir_srv_system_get_fdir_level()) &&
            (false != read_status) &&
            (CMS_COMPLETE == cms_status));
}

static bool conops_sm_is_mode_detumble(const aocs_cntrl_sys_state_types_t mode)
{
    bool ret = false;
    switch (mode)
    {
    case AOCS_CNTRL_SYS_STATE_NORMAL_DETUMBLING:
    case AOCS_CNTRL_SYS_STATE_FAST_DETUMBLING:
    case AOCS_CNTRL_SYS_STATE_VERY_FAST_DETUMBLING:
        ret = true;
        break;
    default:
        break;
    }

    return ret;
}

// USER_CODE_END::@main@

// Entry/Exit functions

// GEN_OBJ_START::conops_sm_on_entry_Safe
void conops_sm_on_entry_Safe(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::onEntry_Safe
    for ( uint8_t payload_id = 0; payload_id < PAYLOAD_COUNT; payload_id++)
    {
        (void)payload_ctrl_stop((payload_ctrl_payload_t)payload_id, PL_OP_STOP_MODE_EMERGENCY);
    }

    // USER_CODE_END::onEntry_Safe
}
// GEN_OBJ_END::conops_sm_on_entry_Safe



// GEN_OBJ_START::conops_sm_on_entry_Control
void conops_sm_on_entry_Control(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::onEntry_Control
    CONOPS_AocsRefParams_t params;
    const aocs_cntrl_sys_state_types_t def_ctrl = conops_get_default_control(CONOPS_MODESWITHDEFCTRL_SAFE, &params);
    conops_set_aocs_sys_state(def_ctrl, (const aocs_cntrl_reference_params_t * const)&params);

    // USER_CODE_END::onEntry_Control
}
// GEN_OBJ_END::conops_sm_on_entry_Control


// GEN_OBJ_START::conops_sm_on_entry_No_control
void conops_sm_on_entry_No_control(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::onEntry_No_control
    conops_set_aocs_sys_state(AOCS_CNTRL_SYS_STATE_NO_CONTROL, NULL);
    // USER_CODE_END::onEntry_No_control
}
// GEN_OBJ_END::conops_sm_on_entry_No_control


// GEN_OBJ_START::conops_sm_on_entry_Idle
void conops_sm_on_entry_Idle(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::onEntry_Idle
    CONOPS_AocsRefParams_t params;
    const aocs_cntrl_sys_state_types_t def_ctrl = conops_get_default_control(CONOPS_MODESWITHDEFCTRL_IDLE, &params);

    conops_set_aocs_sys_state(def_ctrl, (const aocs_cntrl_reference_params_t *const)&params);
    // USER_CODE_END::onEntry_Idle
}
// GEN_OBJ_END::conops_sm_on_entry_Idle


// GEN_OBJ_START::conops_sm_on_entry_Mission
void conops_sm_on_entry_Mission(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::onEntry_Mission
    // Some SW components may need to know when Mission mode has been entered. Put callbacks to
    // this components here

    // Start Mission mode timer
    if (NULL != pEvent)
    {
        const uint32_t * const p_timeout = (const uint32_t * const)(((const conops_event_t *)pEvent)->p_event_data);
        if (NULL != p_timeout)
        {
            mission_mode_timeout = *p_timeout;
            if (mission_mode_timeout > 0)
            {
                timer_start(&mission_mode_timer);
            }
        }
    }

    // Force the ConOps main task to resume. This is done to trigger the timeout monitoring logic
    // with minimum delay so that timeout is respected with precision.
    conops_trigger_task();

    // USER_CODE_END::onEntry_Mission
}
// GEN_OBJ_END::conops_sm_on_entry_Mission

// GEN_OBJ_START::conops_sm_on_exit_Mission
void conops_sm_on_exit_Mission(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::onExit_Mission
    // Some SW components may need to know when Mission mode has been exited. Put callbacks to
    // this components here

    // Stop Mission mode timer
    mission_mode_timeout = 0;
    timer_stop(&mission_mode_timer);

    // USER_CODE_END::onExit_Mission
}
// GEN_OBJ_END::conops_sm_on_exit_Mission



// Guard condition functions
// GEN_OBJ_START::conops_sm_guard_is_fdir_idle
bool conops_sm_guard_is_fdir_idle(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_is_fdir_idle
    return (fdir_srv_system_get_fdir_level() <= FDIR_LEVEL_MINOR);
    // USER_CODE_END::guard_is_fdir_idle
}
// GEN_OBJ_END::conops_sm_guard_is_fdir_idle

// GEN_OBJ_START::conops_sm_guard_has_control
bool conops_sm_guard_has_control(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_has_control
    return conops_sm_has_control();
    // USER_CODE_END::guard_has_control
}
// GEN_OBJ_END::conops_sm_guard_has_control

// GEN_OBJ_START::conops_sm_guard_hasno_control
bool conops_sm_guard_hasno_control(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_hasno_control
    return !conops_sm_has_control();
    // USER_CODE_END::guard_hasno_control
}
// GEN_OBJ_END::conops_sm_guard_hasno_control

// GEN_OBJ_START::conops_sm_guard_is_fdir_critical
bool conops_sm_guard_is_fdir_critical(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_is_fdir_critical
    return (FDIR_LEVEL_CRITICAL == fdir_srv_system_get_fdir_level());
    // USER_CODE_END::guard_is_fdir_critical
}
// GEN_OBJ_END::conops_sm_guard_is_fdir_critical

// GEN_OBJ_START::conops_sm_guard_is_fdir_safe
bool conops_sm_guard_is_fdir_safe(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_is_fdir_safe
    return (fdir_srv_system_get_fdir_level() > FDIR_LEVEL_MINOR);
    // USER_CODE_END::guard_is_fdir_safe
}
// GEN_OBJ_END::conops_sm_guard_is_fdir_safe

// GEN_OBJ_START::conops_sm_guard_mission_timer_expired
bool conops_sm_guard_mission_timer_expired(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_mission_timer_expired
    bool ret = false;
    if ((SAFE_FALSE != mission_mode_timer.is_running) &&
        (false != timer_is_elapsed(&mission_mode_timer, mission_mode_timeout)))
    {
        ret = true;
    }

    return ret;
    // USER_CODE_END::guard_mission_timer_expired
}
// GEN_OBJ_END::conops_sm_guard_mission_timer_expired


// Action handlers
// GEN_OBJ_START::conops_sm_action_detumble
void conops_sm_action_detumble(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::action_detumble
    static bool active_detumbling = false;
    CONOPS_AocsRefParams_t params;
    const aocs_cntrl_sys_state_types_t def_ctrl = conops_get_default_control(CONOPS_MODESWITHDEFCTRL_SAFE, &params);

    if (false != conops_sm_is_mode_detumble(def_ctrl))
    {
        if (false != conops_is_omega_above_thresh(def_ctrl))
        {
            active_detumbling = true;
            conops_set_aocs_sys_state(def_ctrl, (const aocs_cntrl_reference_params_t * const)&params);
        }
        else if ( (false != active_detumbling) && (false != conops_is_detumb_completed()))
        {
            conops_set_aocs_sys_state(AOCS_CNTRL_SYS_STATE_NO_CONTROL, NULL);
            active_detumbling = false;
        }
        else
        {
            // Do nothing
        }
    }

    // USER_CODE_END::action_detumble
}
// GEN_OBJ_END::conops_sm_action_detumble

// GEN_OBJ_START::conops_sm_action_mission_to_idle
void conops_sm_action_mission_to_idle(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::action_mission_to_idle
    for ( uint8_t payload_id = 0; payload_id < PAYLOAD_COUNT; payload_id++)
    {
        (void)payload_ctrl_stop((payload_ctrl_payload_t)payload_id, PL_OP_STOP_MODE_NORMAL);
    }
    // USER_CODE_END::action_mission_to_idle
}
// GEN_OBJ_END::conops_sm_action_mission_to_idle
