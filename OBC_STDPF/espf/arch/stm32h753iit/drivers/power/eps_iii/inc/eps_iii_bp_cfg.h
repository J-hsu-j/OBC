/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup eps_iii_bp
 * @{
 *
 * ## Battery Pack configuration
 *
 * Most of the BP configuration file is generated based on the count of Battery packs configured by changing
 * EPS_III_BP_COUNT CMake variable in /build/CMakeList.txt file.
 *
 * There are additional configuration parameters for each EPS III Battery Pack instance:
 * - 'EPSIII_BP_INST{X}DELAY_BETWEEN_SENDING' - how much delay to be introduced between two batch of requests
 * - 'EPSIII_BP_INST{X}_MAX_MESSAGES_TO_SEND' - how many messages to be sent in a batch, this is important, because each device can have different queues for receiving and transmitting messages. If this number is too big there is risk of
 * - Default values for FDIR supported faults:
 * each fault has the following parameters:
 *  - FDIR_EPSIII_BP_INST{X}_{FAULT_NAME}_DETECTION_STATE - detection could be DETECTION_ENABLED/DETECTION_DISABLED
 *  - FDIR_EPSIII_BP_INST{X}_{FAULT_NAME}_LEVEL - @ref FDIR_LEVEL_MINOR
 *
 * supported faults:
 * - CMD_EXEC_FAILURE
 * - VOLTAGE_BELOW_SAFE
 * - TEMP_BELOW_SAFE
 * - TEMP_ABOVE_SAFE
 *
 * @note In the text the parameter:
 * - **X**: Represents an index that should be replaced with a the id of the instance.
 * - **FAULT_NAME**: Represents different fault
 *
 * Example:
 * - `FDIR_EPSIII_BP_INST0_OVERHEAT_DETECTION_STATE` - could be `DETECTION_ENABLED`/`DETECTION_DISABLED`
 *
 *
 * @file eps_iii_bp_cfg.h
 * @brief Configuration file for EPS III Battery Pack
 *
 * @}
 */

#ifndef EPS_III_BP_CFG_H_
#define EPS_III_BP_CFG_H_

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
// begin EPS_III BP cfg generated code

#define EPS_III_BP_CFG                                                                                            \
    {                                                                                                             \
        .base.eps_dev_info.p_dev_init            = &eps_dev_init,                                                 \
        .base.eps_dev_info.p_is_seq_expected     = &eps_dev_is_seq_expected,                                      \
        .base.eps_dev_info.esps_dev_info         = { 0, 1, 0 },                                                   \
        .base.eps_dev_info.p_process_fdir_faults = &eps_iii_bp_process_fdir_faults,                               \
        .base.eps_dev_info.datacache_cmd_list    = bp_datacache_cmd_list[EPS_III_BP_INST0],                       \
        .base.eps_dev_info.cmd_list_cnt          = EPS_III_BP_DATACACHE_CMD_COUNT,                                \
        .base.eps_dev_info.p_fdir_exec_status    = (fault_exec_status_t *)&bp_fdir_exec_status[EPS_III_BP_INST0], \
        .base.eps_dev_info.fault_exec_status_cnt = EPS_III_BP_CMD_CNT,                                            \
        .base.eps_dev_info.fdir_fault_ids        = bp_fdir_fault_ids[EPS_III_BP_INST0],                           \
        .base.p_init                             = (p_init_t)&eps_iii_bp_init,                                    \
        .tlm.p_device_info                       = (eps_dev_t *)eps_dev_base[EPS_III_DEV_BP_INST0],               \
        .tlm.tlm_cfg                             = {                                                              \
                EPSIII_BP_INST0_DELAY_BETWEEN_SENDING,                                                            \
                EPSIII_BP_INST0_MAX_MESSAGES_TO_SEND                                                              \
        },                                                                                                        \
        .tlm.p_get_telemetry                     = &tlm_dev_get_telemetry,                                        \
        .tlm.p_tlm_req_cmds                      = &bp_tlm_req_cmds[0],                                           \
        .tlm.tlm_cmd_cnt                         = BP_TLM_CMD_CNT                                                 \
    }

#define EPS_III_BP_DEV_INSTANCES_CFG                                     \
    (eps_dev_base_t *)&bp_modules[EPS_III_BP_INST0]

#define EPS_III_BP_TLM_INST_CFG                                          \
    &bp_modules[EPS_III_BP_INST0].tlm
// end EPS_III BP cfg generated code


// begin EPS_III BP instances generated code

#define EPS_III_BP_INST_CFG                                 \
    EPS_III_BP_INST0
// end EPS_III BP instances generated code

// begin EPS_III BP dev instances generated code

#define EPS_III_DEV_BP_INST_CFG                             \
    EPS_III_DEV_BP_INST0
// end EPS_III BP dev instances generated code

// begin EPS_III BP datacache lists generated code

#define EPS_III_BP_DATACACHE_LIST_CMD                       \
    {                                                       \
        DC_DID_EPS3_BP_INST0_UPTIME_IN_SECONDS,             \
        DC_DID_EPS3_BP_INST0COMMON,                         \
        DC_DID_EPS3_BP_INST0HIB_MODE_STATUS,                \
        DC_DID_EPS3_BP_INST0MEASUREMENTS,                   \
        DC_DID_EPS3_BP_INST0DISCHARGING_STATE,              \
        DC_DID_EPS3_BP_INST0CHARGE_STATUS,                  \
        DC_DID_EPS3_BP_INST0BALANCERS_STATUS,               \
        DC_DID_EPS3_BP_INST0BATTERY_CELLS_STATUS,           \
        DC_DID_EPS3_BP_INST0HEATERS_STATUS,                 \
        DC_DID_EPS3_BP_INST0_CMD_EXEC_STATUS_DATA           \
    }
// end EPS_III BP datacache lists generated code

// begin EPS_III BP FDIR FAULTs generated code

#define EPS_III_BP_FDIR_FAULTS_IDS                          \
    {                                                       \
        FDIR_FAULT_EPSIII_BP_INST0_CMD_EXEC_FAILURE,        \
        FDIR_FAULT_EPSIII_BP_INST0_BATT_VOLTAGE_BELOW_SAFE, \
        FDIR_FAULT_EPSIII_BP_INST0_BATT_TEMP_BELOW_SAFE,    \
        FDIR_FAULT_EPSIII_BP_INST0_BATT_TEMP_ABOVE_SAFE     \
    }
// end EPS_III BP FDIR FAULTs generated code

// clang-format on

TODO(NOTICE !Different EPS device instances FDIR levels shall be determined according to the mission requirements)
// FDIR Configuration per instance. As the code is generated based on number of BP instances the configuration
// is moved(from FDIR configuration) to this place where it has to be updated according to the needs for different instances.
#define EPSIII_BP_INST0_DELAY_BETWEEN_SENDING ((uint8_t)1)
#define EPSIII_BP_INST0_MAX_MESSAGES_TO_SEND  ((uint8_t)3)

#define FDIR_EPSIII_BP_INST0_CMD_EXEC_FAILURE_DETECTION_STATE        DETECTION_ENABLED
#define FDIR_EPSIII_BP_INST0_BATT_VOLTAGE_BELOW_SAFE_DETECTION_STATE DETECTION_ENABLED
#define FDIR_EPSIII_BP_INST0_BATT_TEMP_BELOW_SAFE_DETECTION_STATE    DETECTION_ENABLED
#define FDIR_EPSIII_BP_INST0_BATT_TEMP_ABOVE_SAFE_DETECTION_STATE    DETECTION_ENABLED

#define FDIR_EPSIII_BP_INST0_CMD_EXEC_FAILURE_LEVEL        FDIR_LEVEL_MINOR
#define FDIR_EPSIII_BP_INST0_BATT_VOLTAGE_BELOW_SAFE_LEVEL FDIR_LEVEL_MINOR
#define FDIR_EPSIII_BP_INST0_BATT_TEMP_BELOW_SAFE_LEVEL    FDIR_LEVEL_MINOR
#define FDIR_EPSIII_BP_INST0_BATT_TEMP_ABOVE_SAFE_LEVEL    FDIR_LEVEL_MINOR

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
