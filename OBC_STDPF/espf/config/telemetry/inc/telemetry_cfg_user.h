/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef TELEMETRY_CFG_USER_H
#define TELEMETRY_CFG_USER_H

/**
 * @addtogroup service_tlm
 * @{
 *
 * @file telemetry_cfg_user.h
 * @brief Telemetry service configuration header
 *
 * @}
 */

#include "es_cdef.h"
#include "nvm.h"
#include "FP_telemetryProtocolTypes.h"
#include "telemetry_cfg_defs.h"
#include "telemetry_context_types.h"

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

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

/** @brief Determines the active telemetry preset id to use for the selection of telemetry messages
 *
 *  The telemetry configuration provides a set of telemetry preset identifiers which are coupled with a set of
 *  telemetry messages to transmit. In this case, the preset id is determined from the OBC operational mode.
 *
 *  @param[in] instance_id telemetry instance identifier
 *
 * @return ID of the active telemetry preset
 */
uint8_t telemetry_cfg_get_active_preset(const TELEMETRY_TelemetryInstance_t instance_id);

/** @brief The function is used to simulate a change in the active telemetry preset. Its effect will remain
 *  until next reboot or until the @ref telemetry_cfg_restore_active_preset is gets called.
 *
 *  @param[in] instance_id telemetry instance identifier
 *  @param[in] preset_id Active preset id to be used by the telemetry collection service
 *
 *  @retval true the configuration was applied successfully
 *  @retval false the configuration was not applied successfully
 */
bool telemetry_cfg_set_active_preset(const TELEMETRY_TelemetryInstance_t instance_id, uint8_t preset_id);

/** @brief The function removes the effect of the @ref telemetry_cfg_set_active_preset request.
 *
 */
void telemetry_cfg_restore_active_preset(const TELEMETRY_TelemetryInstance_t instance_id);

/** @brief Retrieve the NVM general telemetry configuration for a given telemetry instance
 *
 *
 *  @param[in] instance_id ID of the telemetry instance as described in the telemetry FIDL file
 *  @param[out] p_tlm_cfg user buffer to receive the configuration
 *
 *  @note The function is an NVM-wrapper which performs mapping between telemetry instances and NVM blocks.
 */
void telemetry_cfg_get_tlm_config(const TELEMETRY_TelemetryInstance_t instance_id, telemetry_cfg_t *const p_tlm_cfg);

/** @brief Retrieve the NVM telemetry presets configuration for a given telemetry instance
 *
 *
 *  @param[in] instance_id ID of the telemetry instance as described in the telemetry FIDL file
 *  @param[out] p_tlm_preset_cfg user buffer to receive the configuration
 *
 *  @note The function is an NVM-wrapper which performs mapping between telemetry instances and NVM blocks.
 */
void telemetry_cfg_get_preset_config(const TELEMETRY_TelemetryInstance_t instance_id, telemetry_preset_cfg_t *const p_tlm_preset_cfg);

/** @brief Retrieve the NVM telemetry file sink configuration for a given telemetry instance
 *
 *
 *  @param[in] instance_id ID of the telemetry instance as described in the telemetry FIDL file
 *  @param[out] p_tlm_file_cfg user buffer to receive the configuration
 *
 *  @note The function is an NVM-wrapper which performs mapping between telemetry instances and NVM blocks.
 */
void telemetry_cfg_get_file_config(const TELEMETRY_TelemetryInstance_t instance_id, telemetry_file_cfg_t *const p_tlm_file_cfg);

/** @brief Retrieve the NVM telemetry persistent data for a given telemetry instance
 *
 *
 *  @param[in] instance_id ID of the telemetry instance as described in the telemetry FIDL file
 *  @param[out] p_tlm_pd user buffer to receive the configuration
 *
 *  @note The function is an NVM-wrapper which performs mapping between telemetry instances and NVM blocks.
 */
void telemetry_cfg_get_persistent_data(const TELEMETRY_TelemetryInstance_t instance_id, telemetry_persistent_data_t *const p_tlm_pd);

/** @brief Update the NVM telemetry persistent data for a given telemetry instance
 *
 *
 *  @param[in] instance_id ID of the telemetry instance as described in the telemetry FIDL file
 *  @param[out] p_tlm_cfg updated configuration to set
 *
 *  @note The function is an NVM-wrapper which performs mapping between telemetry instances and NVM blocks.
 */
void telemetry_cfg_set_tlm_config(const TELEMETRY_TelemetryInstance_t instance_id, telemetry_cfg_t *const p_tlm_cfg);

/** @brief Update the NVM telemetry presets configuration for a given telemetry instance
 *
 *
 *  @param[in] instance_id ID of the telemetry instance as described in the telemetry FIDL file
 *  @param[out] p_tlm_preset_cfg updated configuration to set
 *
 *  @retval true: The configuration was fully accepted and set.
 *  @retval false: There is at least one invalid preset slot assignment, hence the configuration was not
 *  fully set.
 *
 *  @note The function is an NVM-wrapper which performs mapping between telemetry instances and NVM blocks.
 */
bool telemetry_cfg_set_preset_config(const TELEMETRY_TelemetryInstance_t instance_id, telemetry_preset_cfg_t *const p_tlm_preset_cfg);

/** @brief Update the NVM telemetry file sink configuration for a given telemetry instance
 *
 *
 *  @param[in] instance_id ID of the telemetry instance as described in the telemetry FIDL file
 *  @param[out] p_tlm_file_cfg updated configuration to set
 *
 *  @note The function is an NVM-wrapper which performs mapping between telemetry instances and NVM blocks.
 */
void telemetry_cfg_set_file_config(const TELEMETRY_TelemetryInstance_t instance_id, telemetry_file_cfg_t *const p_tlm_file_cfg);

/** @brief Update the NVM telemetry auxiliary configuration for a given telemetry instance
 *
 *
 *  @param[in] instance_id ID of the telemetry instance as described in the telemetry FIDL file
 *  @param[out] p_tlm_pd updated configuration to set
 *
 *  @note The function is an NVM-wrapper which performs mapping between telemetry instances and NVM blocks.
 */
void telemetry_cfg_set_persistent_data(const TELEMETRY_TelemetryInstance_t instance_id, telemetry_persistent_data_t *const p_tlm_pd);

/** @brief A TELEMETRY_TelemetryInstance_t-type wrapper of telemetry_cfg_get_ctx_u16() to avoid SonarQube warnings.
 *
 *  @param[in] instance_id telemetry instance ID for which to retrieve the context
 */
tlm_runtime_context_t *telemetry_cfg_get_ctx(const TELEMETRY_TelemetryInstance_t instance_id);

/** @brief Return the telemetry runtime context for a given instance using a uint16_t instance ID
 *
 *  @param[in] instance_id telemetry instance ID for which to retrieve the context
 */
tlm_runtime_context_t *telemetry_cfg_get_ctx_u16(const uint16_t instance_id);

/** @brief Derives a telemetry file name based on index and folder.
 *
 *  @param[in] p_tlm_filesink_rt_ctx telemetry file sink runtime context
 *  @param[in] index telemetry file index
 *
 *  @note Relies on an external static memory buffer! The function also creates any required
 *  directories if they don't exist.
 */
void telemetry_file_sink_prepare_file_access(tlm_file_sink_rt_ctx_t *const p_tlm_filesink_rt_ctx);

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #ifndef TELEMETRY_CFG_USER_H
