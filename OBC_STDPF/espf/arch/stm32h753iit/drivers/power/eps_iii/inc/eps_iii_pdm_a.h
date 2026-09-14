/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_EPS_III_INC_EPS_III_PDM_A_H_
#define ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_EPS_III_INC_EPS_III_PDM_A_H_

/**
 *
 * @addtogroup eps_iii
 * @{
 *
 * @defgroup eps_iii_pdm_a EPS III Power Distribution Module TypeA
 * @{
 *
 * @file eps_iii_pdm_a.h
 * @brief Public interface of EPS III Power Distribution Module TypeA.
 *
 * @}
 * @}
 */

#include "if_tlm_dev.h"
#include "if_eps_ctrl.h"
#include "datacache.h"
#include "fdir_srv_cfg.h"
#include "fp/eps_iii_pdm_a/v2.0/eps_iii_pdm_a_client/FP_eps_iii_pdm_aProtocolTypes.h"
#include "eps_iii_cfg.h"
#include "if_eps_base_dev.h"

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
typedef enum
{
    EPS_III_PDM_A_CHANNEL_3V3,
    EPS_III_PDM_A_CHANNEL_5V,
    EPS_III_PDM_A_CHANNEL_12V,
    EPS_III_PDM_A_GPIO_EXT_SYS_BUS,
    EPS_III_PDM_A_CHANNELS_CNT
} eps_iii_pdm_a_chn_t;

/**
 * @brief Enumeration with IDs of each FD command used for gathering information from the Power Distribution Module TypeA. It is used to provide common configuration
 * of each Power Distribution Module TypeA. In the configuration file for each element of this enum a specific DC_DID has to be provided
 */
typedef enum
{
    PDM_A_CMD_TLM_GET_TELEMETRY,
    PDM_A_TLM_CMD_CNT
} eps_iii_pdm_a_tlm_cmd_e;

/**
 * @brief Enumeration with IDs of each FD command used for gathering information from the Power Distribution Module TypeA. It is used to provide common configuration
 * of each Power Distribution Module TypeA. In the configuration file for each element of this enum a specific DC_DID has to be provided
 */
typedef enum
{
    EPS_III_PDM_A_CMD_LOW_VOLTAGE = PDM_A_TLM_CMD_CNT,
    EPS_III_PDM_A_CMD_EXTERNAL_BUS,
    EPS_III_PDM_A_CMD_CNT
} eps_iii_pdm_a_cmd_e;

typedef enum
{
    EPS_III_PDM_A_UPTIME_IN_SECONDS,
    EPS_III_PDM_A_COMMON,
    EPS_III_PDM_A_GENERAL_OUTPUTS,
    EPS_III_PDM_A_GENERAL_FAULTS,
    EPS_III_PDM_A_ALL_MEASUREMENTS,
    EPS_III_PDM_A_FDIR_CMD_EXEC_STATUS_DATA,
    EPS_III_PDM_A_DATACACHE_CMD_COUNT
} eps_iii_pdm_a_datacache_info_types_t;

/**
 * @brief Common Power Distribution Module TypeA faults enumerator. Those faults will be checked for each Power Distribution Module TypeA
 *
 */
typedef enum
{
    EPS_III_PDM_A_FDIR_CMD_EXEC_FAILURE,
    EPS_III_PDM_A_FDIR_COUNT
} pdm_a_fdir_faults_t;

typedef DATA_CACHE_Eps3_PDM_A_Inst0_FDIR_CMD_EXEC_STATUS_type_t pdm_a_fdir_exec_status_t;

/**
 * @brief Enumeration which contains IDs of all available PDM_A instances.
 *
 */
typedef enum
{
    EPS_III_PDM_A_INST_CFG,
    EPS_III_PDM_A_INST_CNT
} eps_iii_pdm_a_id_t;

/**
 * @brief EPS Power Distribution Module TypeA class definition.
 *
 */
typedef struct
{
    const eps_dev_base_t base;
    const if_tlm_t       tlm;
    const if_eps_ctrl_t  ctrl;
} eps_iii_pdm_a_t;
/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/
/**
 * Specific configuration of telemetry for EPS Power Distribution Module TypeA module follows the following type: @ref eps_dev_s.tlm_req_cmds
 */
extern const get_telemetry_req_t pdm_a_tlm_req_cmds[PDM_A_TLM_CMD_CNT];

/**
 * Specific configuration of EPS Power Distribution Module TypeA device follows the following type: @ref eps_dev_s.datacache_cmd_list
 */
extern const dc_did_id pdm_a_datacache_cmd_list[EPS_III_PDM_A_INST_CNT][EPS_III_PDM_A_DATACACHE_CMD_COUNT];

/**
 * Specific configuration of EPS Power Distribution Module TypeA device follows the following type: @ref eps_dev_s.fdir_fault_ids
 */
extern const fdir_fault_id_t pdm_a_fdir_fault_ids[EPS_III_PDM_A_INST_CNT][EPS_III_PDM_A_FDIR_COUNT];

/**
 * Specific configuration of EPS Power Distribution Module TypeA device follows the following type: @ref eps_dev_s.p_fdir_exec_status
 */
extern pdm_a_fdir_exec_status_t pdm_a_fdir_exec_status[EPS_III_PDM_A_INST_CNT][EPS_III_PDM_A_FDIR_COUNT];

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/
// if_esps_dev interface realization
/**
 * @brief Implementation FP notification received by the device. This function has to be invoked from eps_iii_batt_pack_get_telemetryResponseHandlerImpl
 */
void eps_iii_pdm_a_get_telemetry(eps_dev_t *const self);

/**
 * @brief Specific Power Distribution Module TypeA implementation of @ref process_fdir_faults_t function
 */
void eps_iii_pdm_a_process_fdir_faults(const eps_dev_t *const self);

/**
 * @brief Specific Power Distribution Module TypeA implementation of @ref if_eps_ctrl_s.p_on_set_output_response_received_t function
 */
bool eps_iii_pdm_a_set_channel_output(const if_eps_ctrl_t *const self, uint8_t chn_id, bool new_state);

/**
 * @brief Specific Power Distribution Module TypeA implementation of @ref if_eps_ctrl_s.p_on_get_output_response_received_t function
 */
bool eps_iii_pdm_a_get_channel_output(const if_eps_ctrl_t *const self, uint8_t chn_id);

// fp notification handlers
/**
 * @brief Implementation FP notification received by the device. This function has to be invoked from the ESPS Stack
 */
void eps_iii_pdm_a_get_telemetry_notif(const RespContext_t *const pRespCtx, const eps_iii_pdm_aget_telemetryResponseData_t *const pResponseData);

/**
 * @brief Implementation FP notification received by the device. This function has to be invoked from the ESPS Stack
 */
void eps_iii_pdm_a_system_bus_notif(const RespContext_t *const pRespCtx, const eps_iii_pdm_aexternal_system_bus_controlResponseData_t *const response);

/**
 * @brief Implementation FP notification received by the device. This function has to be invoked from the ESPS Stack
 */
void eps_iii_pdm_a_low_volt_notif(const RespContext_t *const pRespCtx, const eps_iii_pdm_alow_volt_controlResponseData_t *const response);

/**
 * @brief Initialization function for Power Distribution Module TypeA module
 *
 * @param self pointer to an instance of EPS III Power Distribution Module TypeA
 * @param mac_address the mac address to be applied to this instance
 */
void eps_iii_pdm_a_init(eps_iii_pdm_a_t *const self, uint8_t mac_address);

#ifdef __cplusplus
}
#endif

#endif /* ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_EPS_III_INC_EPS_III_PDM_A_H_ */
