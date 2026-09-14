/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_EPS_III_INC_EPS_III_BP_H_
#define ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_EPS_III_INC_EPS_III_BP_H_

/**
 *
 * @addtogroup eps_iii
 * @{
 *
 * @defgroup eps_iii_bp EPS III Battery Pack
 * @{
 *
 * @file eps_iii_bp.h
 * @brief Public interface of EPS III Battery Pack driver.
 *
 * @}
 * @}
 */

#include "fp/eps_iii_batt_pack/v2.0/eps_iii_batt_pack_client/FP_eps_iii_batt_packProtocolTypes.h"

#include "if_tlm_dev.h"
#include "datacache.h"
#include "fdir_srv_cfg.h"
#include "eps_iii_cfg.h"
#include "eps_iii.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
/* No External defines*/

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/
/**
 * @brief Enumeration with IDs of each FD command used for gathering information from the Battery Pack. It is used to provide common configuration
 * of each battery pack. In the configuration file for each element of this enum a specific DC_DID has to be provided
 */
typedef enum
{
    BP_CMD_TLM_GET_TELEMETRY,
    BP_TLM_CMD_CNT
} eps_iii_bp_tlm_cmd_e;

/**
 * @brief Enumeration with IDs of each FD command used for gathering information from the Battery Pack. It is used to provide common configuration
 * of each battery pack. In the configuration file for each element of this enum a specific DC_DID has to be provided
 */
typedef enum
{
    EPS_III_BP_CMD_CNT = BP_TLM_CMD_CNT,
} eps_iii_bp_cmd_e;

/**
 * @brief  Enumeration with all supported datacache elements for a BP instance
 *
 */
typedef enum
{
    EPS_III_BP_UPTIME_IN_SECONDS,
    EPS_III_BP_COMMON,
    EPS_III_BP_HIB_MODE_STATUS,
    EPS_III_BP_MEASUREMENTS,
    EPS_III_BP_DISCHARGING_STATE,
    EPS_III_BP_CHARGE_STATUS,
    EPS_III_BP_BALANCERS_STATUS,
    EPS_III_BP_BATTERY_CELLS_STATUS,
    EPS_III_BP_HEATERS_STATUS,
    EPS_III_BP_FDIR_EXEC_STATUS,
    EPS_III_BP_DATACACHE_CMD_COUNT
} eps_iii_bp_datacache_info_types_t;

/**
 * @brief Common Battery Pack faults enumerator. Those faults will be checked for each Battery Pack
 *
 */
typedef enum
{
    EPS_III_BP_FDIR_CMD_EXEC_FAILURE,
    EPS_III_BP_FDIR_BATT_VOLTAGE_BELOW_SAFE,
    EPS_III_BP_FDIR_BATT_TEMP_BELOW_SAFE,
    EPS_III_BP_FDIR_BATT_TEMP_ABOVE_SAFE,
    EPS_III_BP_FDIR_COUNT
} bp_fdir_faults_t;

typedef DATA_CACHE_Eps3Inst0_FDIR_CMD_EXEC_STATUS_type_t bp_fdir_exec_status_t;

/**
 * @brief Enumeration which contains IDs of all available BP instances.
 *
 */
typedef enum
{
    EPS_III_BP_INST_CFG,
    EPS_III_BP_INST_CNT
} eps_iii_bp_id_t;

/**
 * @brief EPS Battery pack class definition.
 *
 * This structure encapsulates the backplane information for an EPS III device.
 * It consists of a base device and telemetry data, both defined as constant to
 * ensure integrity and prevent accidental modification.
 *
 */
typedef struct
{
    /** Base properties and attributes of the EPS device. */
    const eps_dev_base_t base;
    /** Telemetry data specific to the  EPS III Battery Pack device. */
    const if_tlm_t tlm;
} eps_iii_bp_t;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/
/**
 * Specific configuration of telemetry for EPS Battery Pack module follows the following type: @ref eps_dev_s.tlm_req_cmds
 */
extern const get_telemetry_req_t bp_tlm_req_cmds[BP_TLM_CMD_CNT];

/**
 * Specific configuration of EPS Battery pack device follows the following type: @ref eps_dev_s.datacache_cmd_list
 */
extern const dc_did_id bp_datacache_cmd_list[EPS_III_BP_INST_CNT][EPS_III_BP_DATACACHE_CMD_COUNT];

/**
 * Specific configuration of EPS Battery pack device follows the following type: @ref eps_dev_s.fdir_fault_ids
 */
extern const fdir_fault_id_t bp_fdir_fault_ids[EPS_III_BP_INST_CNT][EPS_III_BP_FDIR_COUNT];

/**
 * Specific configuration of EPS Battery pack device follows the following type: @ref eps_dev_s.p_fdir_exec_status
 */
extern bp_fdir_exec_status_t bp_fdir_exec_status[EPS_III_BP_INST_CNT][EPS_III_BP_FDIR_COUNT];

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

/**
 * @brief Specific Battery Pack implementation of @ref process_fdir_faults_t function
 */
void eps_iii_bp_process_fdir_faults(const eps_dev_t *const self);

/**
 * @brief Implementation FP notification received by the device. This function has to be invoked from eps_iii_batt_pack_get_telemetryResponseHandlerImpl
 */
void eps_iii_bp_get_telemetry_notif(const RespContext_t *const pRespCtx, const eps_iii_batt_packget_telemetryResponseData_t *const pResponseData);

/**
 * @brief Initialization function for Battery Pack module
 *
 * @param self pointer to an instance of EPS III Battery Pack
 * @param mac_address the mac address to be applied to this instance
 */
void eps_iii_bp_init(eps_iii_bp_t *const self, uint8_t mac_address);

#ifdef __cplusplus
}
#endif

#endif /* ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_EPS_III_INC_EPS_III_BP_H_ */
