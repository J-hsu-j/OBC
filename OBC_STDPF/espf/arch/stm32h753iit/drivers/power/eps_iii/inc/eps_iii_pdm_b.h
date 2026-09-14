/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_EPS_III_INC_EPS_III_PDM_B_H_
#define ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_EPS_III_INC_EPS_III_PDM_B_H_

/**
 *
 * @addtogroup eps_iii
 * @{
 *
 * @defgroup eps_iii_pdm_b EPS III Power Distribution Module TypeB
 * @{
 *
 * @file eps_iii_pdm_b.h
 * @brief Public interface of EPS III Power Distribution Module TypeB.
 *
 * @}
 * @}
 */

#include "if_tlm_dev.h"
#include "if_eps_ctrl.h"
#include "datacache.h"
#include "fdir_srv_cfg.h"
#include "fp/eps_iii_pdm_b/v2.0/eps_iii_pdm_b_client/FP_eps_iii_pdm_bProtocolTypes.h"
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
    EPS_III_PDM_B_CHANNEL_A,
    EPS_III_PDM_B_CHANNEL_B,
    EPS_III_PDM_B_CHANNELS_CNT
} eps_iii_pdm_b_chn_t;

/**
 * @brief Enumeration with IDs of each FD command used for gathering information from the Power Distribution Module TypeB. It is used to provide common configuration
 * of each Power Distribution Module TypeB. In the configuration file for each element of this enum a specific DC_DID has to be provided
 */
typedef enum
{
    PDM_B_CMD_TLM_GET_TELEMETRY,
    PDM_B_TLM_CMD_CNT
} eps_iii_pdm_b_tlm_cmd_e;

/**
 * @brief Enumeration with IDs of each FD command used for gathering information from the Power Distribution Module TypeB. It is used to provide common configuration
 * of each Power Distribution Module TypeB. In the configuration file for each element of this enum a specific DC_DID has to be provided
 */
typedef enum
{
    EPS_III_PDM_B_CMD_A_B = PDM_B_TLM_CMD_CNT,
    EPS_III_PDM_B_CMD_CNT
} eps_iii_pdm_b_cmd_e;

typedef enum
{
    EPS_III_PDM_B_UPTIME_IN_SECONDS,
    EPS_III_PDM_B_COMMON,
    EPS_III_PDM_B_HIB_MODE,
    EPS_III_PDM_B_GENERAL_OUTPUTS,
    EPS_III_PDM_B_CHANNEL_FLAG_STATE,
    EPS_III_PDM_B_TEMPERATURE,
    EPS_III_PDM_B_ALL_MEASUREMENTS,
    EPS_III_PDM_B_FDIR_EXEC_STATUS,
    EPS_III_PDM_B_DATACACHE_CMD_COUNT
} eps_iii_pdm_b_datacache_info_types_t;

/**
 * @brief Common Power Distribution Module TypeB faults enumerator. Those faults will be checked for each Power Distribution Module TypeB
 *
 */
typedef enum
{
    EPS_III_PDM_B_FDIR_CMD_EXEC_FAILURE,
    EPS_III_PDM_B_FDIR_COUNT
} pdm_b_fdir_faults_t;

typedef DATA_CACHE_Eps3_PDM_B_Inst0_FDIR_CMD_EXEC_STATUS_type_t pdm_b_fdir_exec_status_t;

/**
 * @brief Enumeration which contains IDs of all available PDM_A instances.
 *
 */
typedef enum
{
    EPS_III_PDM_B_INST_CFG,
    EPS_III_PDM_B_INST_CNT
} eps_iii_pdm_b_id_t;

/**
 * @brief EPS Power Distribution Module TypeB class definition.
 *
 */
typedef struct
{
    const eps_dev_base_t base;
    const if_tlm_t       tlm;
    const if_eps_ctrl_t  ctrl;
} eps_iii_pdm_b_t;
/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/
/**
 * Specific configuration of telemetry for EPS Power Distribution Module TypeB module follows the following type: @ref eps_dev_s.tlm_req_cmds
 */
extern const get_telemetry_req_t pdm_b_tlm_req_cmds[PDM_B_TLM_CMD_CNT];

/**
 * Specific configuration of EPS Power Distribution Module TypeB device follows the following type: @ref eps_dev_s.datacache_cmd_list
 */
extern const dc_did_id pdm_b_datacache_cmd_list[EPS_III_PDM_B_INST_CNT][EPS_III_PDM_B_DATACACHE_CMD_COUNT];

/**
 * Specific configuration of EPS Power Distribution Module TypeB device follows the following type: @ref eps_dev_s.fdir_fault_ids
 */
extern const fdir_fault_id_t pdm_b_fdir_fault_ids[EPS_III_PDM_B_INST_CNT][EPS_III_PDM_B_FDIR_COUNT];

/**
 * Specific configuration of EPS Power Distribution Module TypeB device follows the following type: @ref eps_dev_s.p_fdir_exec_status
 */
extern pdm_b_fdir_exec_status_t pdm_b_fdir_exec_status[EPS_III_PDM_B_INST_CNT][EPS_III_PDM_B_FDIR_COUNT];

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/
// if_esps_dev interface realization
/**
 * @brief Implementation FP notification received by the device. This function has to be invoked from eps_iii_batt_pack_get_telemetryResponseHandlerImpl
 */
void eps_iii_pdm_b_get_telemetry(void *const self);

/**
 * @brief Specific Power Distribution Module TypeB implementation of @ref process_fdir_faults_t function
 */
void eps_iii_pdm_b_process_fdir_faults(const eps_dev_t *const self);

/**
 * @brief Specific Power Distribution Module TypeB implementation of @ref if_eps_ctrl_s.p_on_set_output_response_received_t function
 */
bool eps_iii_pdm_b_set_channel_output(const if_eps_ctrl_t *const self, uint8_t chn_id, bool new_state);

/**
 * @brief Specific Power Distribution Module TypeB implementation of @ref if_eps_ctrl_s.p_on_get_output_response_received_t function
 */
bool eps_iii_pdm_b_get_channel_output(const if_eps_ctrl_t *const self, uint8_t chn_id);

// fp notification handlers
/**
 * @brief Implementation FP notification received by the device. This function has to be invoked from the ESPS Stack
 */
void eps_iii_pdm_b_get_telemetry_notif(const RespContext_t *const pRespCtx, const eps_iii_pdm_bget_telemetryResponseData_t *const pResponseData);

/**
 * @brief Implementation FP notification received by the device. This function has to be invoked from the ESPS Stack
 */
void eps_iii_pdm_b_A_B_control_notif(const RespContext_t *const pRespCtx, const eps_iii_pdm_bA_B_controlResponseData_t *const response);

/**
 * @brief Initialization function for Power Distribution Module TypeB module
 *
 * @param self pointer to an instance of EPS III Power Distribution Module TypeB
 * @param mac_address the mac address to be applied to this instance
 */
void eps_iii_pdm_b_init(eps_iii_pdm_b_t *const self, uint8_t mac_address);

#ifdef __cplusplus
}
#endif

#endif /* ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_EPS_III_INC_EPS_III_PDM_B_H_ */
