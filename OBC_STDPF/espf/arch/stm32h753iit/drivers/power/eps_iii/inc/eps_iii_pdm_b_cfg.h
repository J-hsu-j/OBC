/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup eps_iii_pdm_b
 * @{
 *
 * ## Power Distribution Module TypeB configuration
 *
 * Most of the PDM_B configuration file is generated based on the count of PDM_B modules configured by changing
 * EPS_III_PDM_B_COUNT CMake variable in /build/CMakeList.txt file.
 *
 * There are additional configuration parameters for each EPS III PDM_B instance:
 * - EPSIII_PDM_B_INST{X}_DELAY_BETWEEN_SENDING - how much delay to be introduced between two batch of requests
 * - EPSIII_PDM_B_INST{X}_MAX_MESSAGES_TO_SEND - how many messages to be sent in a batch, this is important, because each device can have different queues for receiving and transmitting messages.
 * - Default values for FDIR supported faults:
 * each fault has the following parameters:
 *  - FDIR_EPSIII_PDM_B_INST{X}_{FAULT_NAME}_DETECTION_STATE - detection could be DETECTION_ENABLED/DETECTION_DISABLED
 *  - FDIR_EPSIII_PDM_B_INST{X}_{FAULT_NAME}_LEVEL - @ref FDIR_LEVEL_MINOR
 *
 * supported faults:
 * - CMD_EXEC_FAILURE
 *
 * @file     eps_iii_pdm_b_cfg.h
 * @brief    Configuration file for EPS III Power Distribution Module TypeB
 *
 * @}
 */

#ifndef EPS_III_PDM_B_CFG_H_
#define EPS_III_PDM_B_CFG_H_

#include "es_cdef.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
#define DETECTION_ENABLED  (true)
#define DETECTION_DISABLED (false)

// clang-format off
// begin EPS_III PDM_B cfg generated code

#define EPS_III_PDM_B_CFG                                                                                               \
    {                                                                                                                   \
        .base.eps_dev_info.p_dev_init            = &eps_dev_init,                                                       \
        .base.eps_dev_info.p_is_seq_expected     = &eps_dev_is_seq_expected,                                            \
        .base.eps_dev_info.esps_dev_info         = { 0, 1, 0 },                                                         \
        .base.eps_dev_info.p_process_fdir_faults = &eps_iii_pdm_b_process_fdir_faults,                                  \
        .base.eps_dev_info.datacache_cmd_list    = pdm_b_datacache_cmd_list[EPS_III_PDM_B_INST0],                       \
        .base.eps_dev_info.cmd_list_cnt          = EPS_III_PDM_B_DATACACHE_CMD_COUNT,                                   \
        .base.eps_dev_info.p_fdir_exec_status    = (fault_exec_status_t *)&pdm_b_fdir_exec_status[EPS_III_PDM_B_INST0], \
        .base.eps_dev_info.fault_exec_status_cnt = EPS_III_PDM_B_CMD_CNT,                                               \
        .base.eps_dev_info.fdir_fault_ids        = pdm_b_fdir_fault_ids[EPS_III_PDM_B_INST0],                           \
        .base.p_init                             = (p_init_t)&eps_iii_pdm_b_init,                                       \
        .tlm.p_device_info                       = (eps_dev_t *)eps_dev_base[EPS_III_DEV_PDM_B_INST0],                  \
        .tlm.tlm_cfg                             = {                                                                    \
                EPSIII_PDM_B_INST0_DELAY_BETWEEN_SENDING,                                                               \
                EPSIII_PDM_B_INST0_MAX_MESSAGES_TO_SEND                                                                 \
        },                                                                                                              \
        .tlm.p_get_telemetry                     = &tlm_dev_get_telemetry,                                              \
        .tlm.p_tlm_req_cmds                      = &pdm_b_tlm_req_cmds[0],                                              \
        .tlm.tlm_cmd_cnt                         = PDM_B_TLM_CMD_CNT,                                                   \
        .ctrl.p_device_info                      = (eps_dev_t *)eps_dev_base[EPS_III_DEV_PDM_B_INST0],                  \
        .ctrl.p_set_output                       = &eps_iii_pdm_b_set_channel_output,                                   \
        .ctrl.p_get_output                       = &eps_iii_pdm_b_get_channel_output,                                   \
        .ctrl.p_on_set_output_response_received  = &eps_iii_on_set_output_response_received,                            \
        .ctrl.p_on_get_output_response_received  = &eps_iii_on_get_output_response_received                             \
    }

#define EPS_III_PDM_B_DEV_INSTANCES_CFG                       \
    (eps_dev_base_t *)&pdm_b_modules[EPS_III_PDM_B_INST0]

#define EPS_III_PDM_B_TLM_INST_CFG                            \
    &pdm_b_modules[EPS_III_PDM_B_INST0].tlm

#define EPS_III_PDM_B_CTRL_INSTANCES_CFG                      \
    &pdm_b_modules[EPS_III_PDM_B_INST0].ctrl
// end EPS_III PDM_B cfg generated code

// begin EPS_III PDM_B instances generated code

#define EPS_III_PDM_B_INST_CFG                                   \
    EPS_III_PDM_B_INST0
// end EPS_III PDM_B instances generated code

// begin EPS_III PDM_B ctrl instances generated code

#define EPS_III_PDM_B_CTRL_INST_CFG                              \
    EPS_III_PDM_B_CTRL_INST0
// end EPS_III PDM_B ctrl instances generated code

// begin EPS_III PDM_B dev instances generated code

#define EPS_III_DEV_PDM_B_INST_CFG                               \
    EPS_III_DEV_PDM_B_INST0
// end EPS_III PDM_B dev instances generated code

// begin EPS_III PDM_B datacache lists generated code

#define EPS_III_PDM_B_DATACACHE_LIST_CMD                         \
    {                                                            \
        DC_DID_EPS3_PDM_B_INST0_UPTIME_IN_SECONDS,               \
        DC_DID_EPS3_PDM_B_INST0_COMMON,                          \
        DC_DID_EPS3_PDM_B_INST0_HIB_MODE,                        \
        DC_DID_EPS3_PDM_B_INST0_GENERAL_OUTPUTS,                 \
        DC_DID_EPS3_PDM_B_INST0_CHANNEL_FLAG_STATE,              \
        DC_DID_EPS3_PDM_B_INST0_TEMPERATURE,                     \
        DC_DID_EPS3_PDM_B_INST0_ALL_MEASUREMENTS,                 \
        DC_DID_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DATA             \
    }
// end EPS_III PDM_B datacache lists generated code

// begin EPS_III PDM_B FDIR FAULTs generated code

#define EPS_III_PDM_B_FDIR_FAULTS_IDS                       \
    {                                                       \
        FDIR_FAULT_EPSIII_PDM_B_INST0_CMD_EXEC_FAILURE,     \
    }
// end EPS_III PDM_B FDIR FAULTs generated code

// clang-format on

TODO(NOTICE !Different EPS device instances FDIR levels shall be determined according to the mission requirements)
// FDIR Configuration per instance. As the code is generated based on number of PDM_B instances the configuration
// is moved(from FDIR configuration) to this place where it has to be updated according to the needs for different instances.

#define EPSIII_PDM_B_INST0_DELAY_BETWEEN_SENDING ((uint8_t)1)
#define EPSIII_PDM_B_INST0_MAX_MESSAGES_TO_SEND  ((uint8_t)3)

#define FDIR_EPSIII_PDM_B_INST0_CMD_EXEC_FAILURE_DETECTION_STATE DETECTION_ENABLED
#define FDIR_EPSIII_PDM_B_INST0_CMD_EXEC_FAILURE_LEVEL           FDIR_LEVEL_MINOR

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
/* No External variables declarations */

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

#ifdef __cplusplus
}
#endif

#endif /* EPS_III_TELEMETRY_H_ */
