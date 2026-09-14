/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_EPS_III_INC_EPS_III_EXPANDER_H_
#define ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_EPS_III_INC_EPS_III_EXPANDER_H_

/**
 *
 * @addtogroup eps_iii
 * @{
 *
 * @defgroup eps_iii_expander EPS III Expander
 * @{
 *
 * @file eps_iii_expnader.h
 * @brief Public interface of EPS III Expander driver.
 *
 * @}
 * @}
 */

#include "if_tlm_dev.h"
#include "if_eps_ctrl.h"
#include "datacache.h"
#include "fdir_srv_cfg.h"
#include "fp/eps_iii_expander/v2.0/eps_iii_expander_client/FP_eps_iii_expanderProtocolTypes.h"
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

/**
 * @brief Enumerator of all channels supported by one Expander module
 *
 */
typedef enum
{
    EPS_III_EXPANDER_CHANNEL_LV_H1_47_48,
    EPS_III_EXPANDER_CHANNEL_HV_H1_47_48,
    EPS_III_EXPANDER_CHANNEL_LV_H1_49_50,
    EPS_III_EXPANDER_CHANNEL_HV_H1_49_50,
    EPS_III_EXPANDER_CHANNEL_LV_H1_51_52,
    EPS_III_EXPANDER_CHANNEL_HV_H1_51_52,
    EPS_III_EXPANDER_CHANNEL_GPIO_1,
    EPS_III_EXPANDER_CHANNEL_GPIO_2,
    EPS_III_EXPANDER_CHANNEL_GPIO_3,
    EPS_III_EXPANDER_CHANNEL_GPIO_4,
    EPS_III_EXPANDER_CHANNEL_GPIO_5,
    EPS_III_EXPANDER_CHANNEL_GPIO_6,
    EPS_III_EXPANDER_CHANNEL_GPIO_7,
    EPS_III_EXPANDER_CHANNEL_GPIO_8,
    EPS_III_EXPANDER_CHANNEL_INTERCONNECT_3V3,
    EPS_III_EXPANDER_CHANNEL_INTERCONNECT_5V,
    EPS_III_EXPANDER_CHANNEL_INTERCONNECT_12V,
    EPS_III_EXPANDER_CHANNEL_INTERCONNECT_BATTERY,
    EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_1_5V,
    EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_2_5V,
    EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_3_5V,
    EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_4_5V,
    EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_1_A,
    EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_1_B,
    EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_2_A,
    EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_2_B,
    EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_3_A,
    EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_3_B,
    EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_4_A,
    EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_4_B,
    EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_1_Fb1,
    EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_1_Fb2,
    EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_2_Fb1,
    EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_2_Fb2,
    EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_3_Fb1,
    EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_3_Fb2,
    EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_4_Fb1,
    EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_4_Fb2,
    EPS_III_EXPANDER_CHANNELS_CNT
} eps_iii_expander_chn_t;

/**
 * @brief Enumeration with IDs of each FD command used for gathering information from the Expander device. It is used to provide common configuration
 * of each Expander device. In the configuration file for each element of this enum a specific DC_DID has to be provided
 */
typedef enum
{
    EXPANDER_CMD_TLM_GET_TELEMETRY,
    EXPANDER_TLM_CMD_CNT
} eps_iii_expander_tlm_cmd_e;

/**
 * @brief Enumeration with IDs of each FD command used for gathering information from the Expander module. It is used to provide common configuration
 * of each Expander module. In the configuration file for each element of this enum a specific DC_DID has to be provided
 */
typedef enum
{
    EPS_III_EXPANDER_CMD_H1_CHANNELS_CONTROL = EXPANDER_TLM_CMD_CNT,
    EPS_III_EXPANDER_CMD_GPIO_CONTROL,
    EPS_III_EXPANDER_CMD_INTERCONNECT_CONTROL,
    EPS_III_EXPANDER_CMD_RELEASE_CONTROL,
    EPS_III_EXPANDER_CMD_RELEASE_5V_CONTROL,
    EPS_III_EXPANDER_CMD_CNT
} eps_iii_expander_cmd_e;

/**
 * @brief Enumerator with all supported datacache elements for one Expander module
 *
 */
typedef enum
{
    EPS_III_EXPANDER_UPTIME_IN_SECONDS,
    EPS_III_EXPANDER_COMMON,
    EPS_III_EXPANDER_OUTPUTS,
    EPS_III_EXPANDER_GENERAL_INPUTS,
    EPS_III_EXPANDER_FEEDBACKS,
    EPS_III_EXPANDER_VOLT_AMP_MEASUREMENTS,
    EPS_III_EXPANDER_FDIR_EXEC_STATUS,
    EPS_III_EXPANDER_DATACACHE_CMD_COUNT
} eps_iii_expander_datacache_info_types_t;

/**
 * @brief Common Expander faults enumerator. Those faults will be checked for each Expander
 *
 */
typedef enum
{
    EPS_III_EXPANDER_FDIR_CMD_EXEC_FAILURE,
    EPS_III_EXPANDER_FDIR_CMD_H1_CHANNELS_CONTROL,
    EPS_III_EXPANDER_FDIR_CMD_GPIO_CONTROL,
    EPS_III_EXPANDER_FDIR_CMD_INTERCONNECT_CONTROL,
    EPS_III_EXPANDER_FDIR_CMD_RELEASE_CONTROL,
    EPS_III_EXPANDER_FDIR_COUNT
} expander_fdir_faults_t;

typedef DATA_CACHE_Eps3_EXPANDER_Inst0_FDIR_CMD_EXEC_STATUS_type_t expander_fdir_exec_status_t;

/**
 * @brief Enumeration which contains IDs of all available Expander instances.
 *
 */
typedef enum
{
    EPS_III_EXPANDER_INST_CFG,
    EPS_III_EXPANDER_INST_CNT
} eps_iii_expander_id_t;

/**
 * @brief EPS III Expander module class definition.
 *
 */
typedef struct
{
    const eps_dev_base_t base;
    const if_tlm_t       tlm;
    const if_eps_ctrl_t  ctrl;
} eps_iii_expander_t;
/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/
/**
 * Specific configuration of telemetry for EPS Expander module follows the following type: @ref eps_dev_s.tlm_req_cmds
 */
extern const get_telemetry_req_t expander_tlm_req_cmds[EXPANDER_TLM_CMD_CNT];

/**
 * Specific configuration of EPS Expander device follows the following type: @ref eps_dev_s.datacache_cmd_list
 */
extern const dc_did_id expander_datacache_cmd_list[EPS_III_EXPANDER_INST_CNT][EPS_III_EXPANDER_DATACACHE_CMD_COUNT];

/**
 * Specific configuration of EPS Expander device follows the following type: @ref eps_dev_s.fdir_fault_ids
 */
extern const fdir_fault_id_t expander_fdir_fault_ids[EPS_III_EXPANDER_INST_CNT][EPS_III_EXPANDER_FDIR_COUNT];

/**
 * Specific configuration of EPS Expander device follows the following type: @ref eps_dev_s.p_fdir_exec_status
 */
extern expander_fdir_exec_status_t expander_fdir_exec_status[EPS_III_EXPANDER_INST_CNT][EPS_III_EXPANDER_FDIR_COUNT];

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/
// if_esps_dev interface realization
/**
 * @brief Specific Expander module implementation of @ref process_fdir_faults_t function
 */
void eps_iii_expander_process_fdir_faults(const eps_dev_t *const self);

bool eps_iii_expander_set_channel_output(const if_eps_ctrl_t *const self, uint8_t chn_id, bool new_state);
bool eps_iii_expander_get_channel_output(const if_eps_ctrl_t *const p_eps_ctrl, uint8_t chn_id);

// fp notification handlers
/**
 * @brief Implementation FP notification received by the device. This function has to be invoked from the ESPS Stack
 */
void eps_iii_expander_get_telemetry_notif(const RespContext_t *const pRespCtx, const eps_iii_expanderget_telemetryResponseData_t *const pResponseData);

/**
 * @brief Implementation FP notification received by the device. This function has to be invoked from the ESPS Stack
 */
void eps_iii_expander_h1_channels_control_notif(const RespContext_t *const pRespCtx, const eps_iii_expanderh1_channels_controlResponseData_t *const response);

/**
 * @brief Implementation FP notification received by the device. This function has to be invoked from the ESPS Stack
 */
void eps_iii_expander_gpio_control_notif(const RespContext_t *const pRespCtx, const eps_iii_expandergpio_controlResponseData_t *const response);

/**
 * @brief Implementation FP notification received by the device. This function has to be invoked from the ESPS Stack
 */
void eps_iii_expander_interconnect_control_notif(const RespContext_t *const pRespCtx, const eps_iii_expanderinterconnect_controlResponseData_t *const response);

/**
 * @brief Implementation FP notification received by the device. This function has to be invoked from the ESPS Stack
 */
void eps_iii_expander_release_control_notif(const RespContext_t *const pRespCtx, const eps_iii_expanderrelease_controlResponseData_t *const response);

/**
 * @brief Implementation FP notification received by the device. This function has to be invoked from the ESPS Stack
 */
void eps_iii_expander_release_5v_control_notif(const RespContext_t *const pRespCtx, const eps_iii_expanderrelease_5vResponseData_t *const response);

/**
 * @brief Initialization function for Expander module
 *
 * @param self pointer to an instance of EPS III Expander
 * @param mac_address the mac address to be applied to this instance
 */
void eps_iii_expander_init(eps_iii_expander_t *const self, uint8_t mac_address);

#ifdef __cplusplus
}
#endif

#endif /* ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_EPS_III_INC_EPS_III_EXPANDER_H_ */
