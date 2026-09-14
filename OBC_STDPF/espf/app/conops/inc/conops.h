/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef CONOPS_H
#define CONOPS_H

/** @addtogroup app
 * @{
 *
 * @defgroup app_conops conops
 * @{
 *
 * @file conops.h
 * @brief Interface of the Concept of Operations application
 *
 * @}
 * @}
 */

#include "cmsis_os2.h"
#include "es_cdef.h"
#include "conops_cfg.h"
#include "aocs_cntrl_types.h"
#include "fp/conops/v2.0/conops_server/FP_conopsProtocolTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
********************************************************************************************
* EXTERNAL DEFINES
********************************************************************************************
*/

/*
********************************************************************************************
* EXTERNAL TYPES DECLARATIONS
********************************************************************************************
*/

/*
********************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
********************************************************************************************
*/

/*
********************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
********************************************************************************************
*/

/**
 * @brief Initialises the ConOps logic
 *
 * @retval true  Initialization completed successfully.
 * @retval false An error occurred during initialization. Application cannot be used
 */
bool conops_init(void);

/**
 * @brief Triggers the ConOps HSM.
 *
 * @param[in] event_id     ID of the event used to trigger the HSM
 * @param[in] p_event_data Parameters specific to the event
 *
 * @retval true  HSM successfully executed transition.
 * @retval false HSM couldn't execute transition.
 */
bool conops_trigger_hsm(const uint32_t event_id, const void *const p_event_data);

/**
 * @brief Gets the currently active state of the ConOps HSM.
 *
 * @param[out] p_active_state Reference to the memory to hold the result
 */
void conops_get_hsm_active_state(uint8_t *const p_active_state);

/**
 * @brief Sets a ConOps threshold value.
 *
 * @param[in] thresh_val  Value to set
 * @param[in] thresh_type Specific threshold to set the value to
 *
 * @retval true  Threshold successfully set.
 * @retval false An error occurred while setting the threshold.
 */
bool conops_set_thresh_val(const int32_t thresh_val, const CONOPS_ThresholdValueTypes_t thresh_type);

/**
 * @brief Retrieves a ConOps threshold value.
 *
 * @param[out] p_thresh_val Reference to the memory that shall hold the result
 * @param[in]  thresh_type  Threshold value to retrieve
 *
 * @retval true  Threshold successfully retrieved.
 * @retval false An error occurred while retrieving the threshold.
 */
bool conops_get_thresh_val(int32_t *const p_thresh_val, const CONOPS_ThresholdValueTypes_t thresh_type);

/**
 * @brief Sets all ConOps threshold values according to a provided configuration.
 *
 * @param[in] p_thresh_config Reference to threshold values' configuration
 *
 * @retval true  Thresholds successfully set.
 * @retval false An error occurred while setting the thresholds.
 */
bool conops_set_all_thresh_val(const CONOPS_ThresholdValues_t *const p_thresh_config);

/**
 * @brief Retrieves all ConOps threshold values.
 *
 * @param[out] p_thresh_vals Reference to the memory that shall hold the result
 *
 * @retval true  Thresholds successfully retrieved.
 * @retval false An error occurred while retrieving the thresholds.
 */
bool conops_get_all_thresh_val(CONOPS_ThresholdValues_t *const p_thresh_vals);

/**
 * @brief Checks if payloads are allowed to run in the current ConOps mode.
 *
 * @retval true  Payloads are allowed to run.
 * @retval false Payloads are not allowed to run.
 */
bool conops_is_payload_allowed(void);

#ifdef __cplusplus
}
#endif

#endif /* CONOPS_H */
