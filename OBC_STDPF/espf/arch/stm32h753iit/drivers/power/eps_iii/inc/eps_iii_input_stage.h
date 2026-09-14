/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_EPS_III_INC_EPS_III_INPUT_STAGE_H_
#define ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_EPS_III_INC_EPS_III_INPUT_STAGE_H_

#include "if_tlm_dev.h"
#include "datacache.h"
#include "fdir_srv_cfg.h"
#include "fp/eps_iii_input_stage/v2.0/eps_iii_input_stage_client/FP_eps_iii_input_stageProtocolTypes.h"
#include "eps_iii_cfg.h"
#include "if_eps_base_dev.h"

/**
 *
 * @addtogroup eps_iii
 * @{
 *
 * @defgroup eps_iii_input_stage EPS III Input Stage
 * @{
 *
 * @file eps_iii_input_stage.h
 * @brief Public interface of EPS III Input Stage driver.
 *
 * @}
 * @}
 */

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
 * @brief Enumeration with IDs of each FD command used for gathering information from the Input Stage module. It is used to provide common configuration
 * of each Input Stage module. In the configuration file for each element of this enum a specific DC_DID has to be provided
 */
typedef enum
{
    INPUT_STAGE_CMD_TLM_GET_TELEMETRY,
    INPUT_STAGE_TLM_CMD_CNT
} eps_iii_input_stage_tlm_cmd_e;

/**
 * @brief Enumeration with IDs of each FD command used for gathering information from the Input Stage module. It is used to provide common configuration
 * of each Input Stage module. In the configuration file for each element of this enum a specific DC_DID has to be provided
 */
typedef enum
{
    EPS_III_INPUT_STAGE_CMD_CNT = INPUT_STAGE_TLM_CMD_CNT,
} eps_iii_input_stage_cmd_e;

/**
 * @brief  Enumeration with all supported datacache elements for a Input Stage instance
 *
 */
typedef enum
{
    EPS_III_INPUT_STAGE_UPTIME_IN_SECONDS,
    EPS_III_INPUT_STAGE_COMMON,
    EPS_III_INPUT_STAGE_HIB_MODE_STATUS,
    EPS_III_INPUT_STAGE_SELFLOCK_ON,
    EPS_III_INPUT_STAGE_SP1,
    EPS_III_INPUT_STAGE_SP2,
    EPS_III_INPUT_STAGE_SP3,
    EPS_III_INPUT_STAGE_SYSTEM_BUS,
    EPS_III_INPUT_STAGE_BUS_7V5,
    EPS_III_INPUT_STAGE_BUS_7V5_POWER_GOOD,
    EPS_III_INPUT_STAGE_UNDERVOLTAGE_7V5,
    EPS_III_INPUT_STAGE_BUS_3V3,
    EPS_III_INPUT_STAGE_UNDERVOLTAGE_3V3,
    EPS_III_INPUT_STAGE_FDIR_EXEC_STATUS,
    EPS_III_INPUT_STAGE_DATACACHE_CMD_COUNT
} eps_iii_input_stage_datacache_info_types_t;

/**
 * @brief Common Input Stage module faults enumerator. Those faults will be checked for each Input Stage module
 *
 */
typedef enum
{
    EPS_III_INPUT_STAGE_FDIR_CMD_EXEC_FAILURE,
    EPS_III_INPUT_STAGE_FDIR_BATT_VOLTAGE_BELOW_SAFE,
    EPS_III_INPUT_STAGE_FDIR_BATT_TEMP_BELOW_SAFE,
    EPS_III_INPUT_STAGE_FDIR_BATT_TEMP_ABOVE_SAFE,
    EPS_III_INPUT_STAGE_FDIR_COUNT
} input_stage_fdir_faults_t;

typedef DATA_CACHE_Eps3Inst0_FDIR_CMD_EXEC_STATUS_type_t input_stage_fdir_exec_status_t;

/**
 * @brief Enumeration which contains IDs of all available INPUT STAGE instances.
 *
 */
typedef enum
{
    EPS_III_INPUT_STAGE_INST_CFG,
    EPS_III_INPUT_STAGE_INST_CNT
} eps_iii_input_stage_id_t;

/**
 * @brief EPS Input Stage class definition.
 *
 */
typedef struct
{
    const eps_dev_base_t base;
    const if_tlm_t       tlm;
} eps_iii_input_stage_t;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/
/**
 * Specific configuration of telemetry for EPS Input Stage module follows the following type: @ref eps_dev_s.tlm_req_cmds
 */
extern const get_telemetry_req_t input_stage_tlm_req_cmds[INPUT_STAGE_TLM_CMD_CNT];

/**
 * Specific configuration of EPS Input Stage device follows the following type: @ref eps_dev_s.datacache_cmd_list
 */
extern const dc_did_id input_stage_datacache_cmd_list[EPS_III_INPUT_STAGE_INST_CNT][EPS_III_INPUT_STAGE_DATACACHE_CMD_COUNT];

/**
 * Specific configuration of EPS Input Stage device follows the following type: @ref eps_dev_s.fdir_fault_ids
 */
extern const fdir_fault_id_t input_stage_fdir_fault_ids[EPS_III_INPUT_STAGE_INST_CNT][EPS_III_INPUT_STAGE_FDIR_COUNT];

/**
 * Specific configuration of EPS Input Stage device follows the following type: @ref eps_dev_s.p_fdir_exec_status
 */
extern input_stage_fdir_exec_status_t input_stage_fdir_exec_status[EPS_III_INPUT_STAGE_INST_CNT][EPS_III_INPUT_STAGE_FDIR_COUNT];

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

/**
 * @brief Specific Input Stage module implementation of @ref process_fdir_faults_t function
 */
void eps_iii_input_stage_process_fdir_faults(const eps_dev_t *const self);

/**
 * @brief Implementation FP notification received by the device. This function has to be invoked from ESPS Stack
 */
void eps_iii_input_stage_get_telemetry_notif(const RespContext_t *const pRespCtx, const eps_iii_input_stageget_telemetryResponseData_t *const pResponseData);

/**
 * @brief Initialization function for Input Stage module
 *
 * @param self pointer to an instance of EPS III Input Stage
 * @param mac_address the mac address to be applied to this instance
 */
void eps_iii_input_stage_init(eps_iii_input_stage_t *const self, uint8_t mac_address);

#ifdef __cplusplus
}
#endif

#endif /* ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_EPS_III_INC_EPS_III_INPUT_STAGE_H_ */
