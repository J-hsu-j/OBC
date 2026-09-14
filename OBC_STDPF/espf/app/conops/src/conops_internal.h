/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef CONOPS_INTERNAL_TYPES_H
#define CONOPS_INTERNAL_TYPES_H
/**
 * @addtogroup app_conops
 * @{
 *
 * @file conops_internal_types.h
 * @brief Declarations and definitions shared between sub-components of the ConOps application
 *
 * @}
 *
 */

#ifdef __cplusplus
extern "C" {
#endif
/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/** @brief Event to the ConOps state machine */
typedef struct
{
    sHSM_EventType_t base_event;   /**< Data pertaining to all events of a libhsm state machine */
    const void      *p_event_data; /**< Arguments to the state machine event. Handling depends on
                                        the specific event. */
} conops_event_t;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

/**
 * @brief Retrieves default AOCS control mode for a given ConOps mode.
 * @param[in]  mode_id  ID of the ConOps mode
 * @param[out] p_params Parameters of the AOCS control mode
 *
 * @return ID of the default AOCS control mode for the given ConOps mode
 */
aocs_cntrl_sys_state_types_t conops_get_default_control(const CONOPS_ModesWithDefCtrl_t mode_id,
                                                        CONOPS_AocsRefParams_t *const   p_params);

/**
 * @brief Checks if the satellite's angular velocity is above a pre-configured threshold.
 *
 * @param[in] aocs_state Current state of the AOCS service
 *
 * @retval true One of the following:
 *               - Satellite is not in stable Y-Thomson spin.
 *               - Angular velocity is above pre-configured threshold.
 * @retval false One of the following:
 *               - Reading of threshold value has failed.
 *               - AOCS is not in a detumbling state.
 */
bool conops_is_omega_above_thresh(const aocs_cntrl_sys_state_types_t aocs_state);

/**
 * @brief Checks if detumbling is completed.
 *
 * @retval true Detumbling is completed.
 * @retval false Detumbling is not completed.
 *
 * @note Check assumes we are in some sort of detumbling. It does not perform evaluation
 *       of all the different control modes the ADCS can be in.
 */
bool conops_is_detumb_completed(void);

/**
 * @brief Refreshes runtime copies of the NVM stored configurations.
 *
 * @note To be used only by the periodic task of conops.
 */
void conops_refresh_runtime_nvm_copies(void);

/**
 * @brief Retrieves the current AOCS system state.
 *
 * @param[out] p_sys_state           Current AOCS system state if the relevant data cache is STATUS_OK.
 *                                   Set to max system state if request failed.
 * @param[out] p_sys_state_req_state AOCS system state request state.
 *                                   Set to max if request failed.
 *
 * @retval true AOCS system state retrieved successfully.
 * @retval false An error occurred while retrieving AOCS system state.
 */
bool conops_get_aocs_sys_state(aocs_cntrl_sys_state_types_t *const p_sys_state, aocs_cntrl_sys_state_req_state_t *const p_sys_state_req_state);

/**
 * @brief Requests a new AOCS system state.
 *
 * @param[in] sys_state    New system state
 * @param[in] p_ref_params Reference parameters for the requested AOCS state
 *
 */
void conops_set_aocs_sys_state(const aocs_cntrl_sys_state_types_t sys_state, const aocs_cntrl_reference_params_t *const p_ref_params);

/**
 * @brief Forces the main task of ConOps to resume execution.
 */
void conops_trigger_task(void);

#ifdef __cplusplus
}
#endif
#endif /* CONOPS_INTERNAL_TYPES_H */
