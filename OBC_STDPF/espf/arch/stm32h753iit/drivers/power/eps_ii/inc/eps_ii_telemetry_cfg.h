/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup eps_ii
 * @{
 *
 * ## Telemetry
 *
 * The telemetry of the EPS II is split between the PDM (Power Distribution Module) and the BP
 * (Battery Pack). Both devices have a number of sensors from which telemetry can be requested.
 *
 * The task `eps_ii_telemetry_task` is periodically sending requests to both modules and it takes care
 * of receiving the responses with the `eps_ii_*_notif` callback functions and filling up the information in the
 * datacache.
 *
 * The period is defined as @ref EPS_II_TELEMETRY_PERIOD.
 *
 * @file     eps_ii_telemetry.h
 * @brief    Telemetry definitions for gathering EPS II telemetry
 *
 * @}
 */

#ifndef EPS_II_TELEMETRY_CFG_H_
#define EPS_II_TELEMETRY_CFG_H_

// clang-format off

// begin EPS BP generated code

//
// Global declarations for EPS BP INSTANCE
//
#define EPS_BP_CONFIGURATION                                 \
    {                                                        \
        .p_address          = &eps_bp_mac_address[0],        \
        .datacache_cmd_list = {                              \
            DC_DID_EPS2_BP_INST0_BP_INFO_DATA,               \
            DC_DID_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DATA,    \
            DC_DID_EPS2_BP_INST0_INA_SENSOR1_DATA,           \
            DC_DID_EPS2_BP_INST0_INA_SENSOR2_DATA,           \
            DC_DID_EPS2_BP_INST0_BALANCER_INFO_DATA,         \
            DC_DID_EPS2_BP_INST0_BALANCER_STATUS_DATA,       \
            DC_DID_EPS2_BP_INST0_BALANCER_CELLS_INFO_DATA,   \
            DC_DID_EPS2_BP_INST0_CHARGER_XP_DATA,            \
            DC_DID_EPS2_BP_INST0_CHARGER_XR_DATA,            \
            DC_DID_EPS2_BP_INST0_CHARGER_YP_DATA,            \
            DC_DID_EPS2_BP_INST0_CHARGER_YR_DATA,            \
            DC_DID_EPS2_BP_INST0_CHARGER_ZP_DATA,            \
            DC_DID_EPS2_BP_INST0_CHARGER_ZR_DATA,            \
            DC_DID_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DATA \
        },                                                   \
        .fdir_faults = {                                     \
            FDIR_FAULT_EPS_INST0_CMD_EXEC_FAILURE,           \
            FDIR_FAULT_EPS_INST0_BATT_VOLTAGE_BELOW_SAFE,    \
            FDIR_FAULT_EPS_INST0_BATT_TEMP_BELOW_SAFE,       \
            FDIR_FAULT_EPS_INST0_BATT_TEMP_ABOVE_SAFE        \
        }                                                    \
    },                                                        \
    {                                                        \
        .p_address          = &eps_bp_mac_address[1],        \
        .datacache_cmd_list = {                              \
            DC_DID_EPS2_BP_INST1_BP_INFO_DATA,               \
            DC_DID_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DATA,    \
            DC_DID_EPS2_BP_INST1_INA_SENSOR1_DATA,           \
            DC_DID_EPS2_BP_INST1_INA_SENSOR2_DATA,           \
            DC_DID_EPS2_BP_INST1_BALANCER_INFO_DATA,         \
            DC_DID_EPS2_BP_INST1_BALANCER_STATUS_DATA,       \
            DC_DID_EPS2_BP_INST1_BALANCER_CELLS_INFO_DATA,   \
            DC_DID_EPS2_BP_INST1_CHARGER_XP_DATA,            \
            DC_DID_EPS2_BP_INST1_CHARGER_XR_DATA,            \
            DC_DID_EPS2_BP_INST1_CHARGER_YP_DATA,            \
            DC_DID_EPS2_BP_INST1_CHARGER_YR_DATA,            \
            DC_DID_EPS2_BP_INST1_CHARGER_ZP_DATA,            \
            DC_DID_EPS2_BP_INST1_CHARGER_ZR_DATA,            \
            DC_DID_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DATA \
        },                                                   \
        .fdir_faults = {                                     \
            FDIR_FAULT_EPS_INST1_CMD_EXEC_FAILURE,           \
            FDIR_FAULT_EPS_INST1_BATT_VOLTAGE_BELOW_SAFE,    \
            FDIR_FAULT_EPS_INST1_BATT_TEMP_BELOW_SAFE,       \
            FDIR_FAULT_EPS_INST1_BATT_TEMP_ABOVE_SAFE        \
        }                                                    \
    }                                                        \
// end EPS BP generated code

// clang-format on

#define DETECTION_ENABLED  (true)
#define DETECTION_DISABLED (false)

// FDIR Configuration per instance. As the code is generated based on number of BP instances the configuration
// is moved(from FDIR configuration) to this place where it has to be updated according to the needs for different instances.

TODO(NOTICE !Different EPS instances FDIR levels shall be determined according to the mission requirements)

#define FDIR_EPS_INST0_CMD_EXEC_FAILURE_DETECTION_STATE DETECTION_DISABLED
#define FDIR_EPS_INST0_CMD_EXEC_FAILURE_LEVEL           FDIR_LEVEL_WARNING

#define FDIR_EPS_INST0_BATT_VOLTAGE_BELOW_SAFE_DETECTION_STATE DETECTION_DISABLED
#define FDIR_EPS_INST0_BATT_VOLTAGE_BELOW_SAFE_LEVEL           FDIR_LEVEL_WARNING

#define FDIR_EPS_INST0_BATT_TEMP_BELOW_SAFE_DETECTION_STATE DETECTION_DISABLED
#define FDIR_EPS_INST0_BATT_TEMP_BELOW_SAFE_LEVEL           FDIR_LEVEL_WARNING

#define FDIR_EPS_INST0_BATT_TEMP_ABOVE_SAFE_DETECTION_STATE DETECTION_DISABLED
#define FDIR_EPS_INST0_BATT_TEMP_ABOVE_SAFE_LEVEL           FDIR_LEVEL_WARNING

// Instance 1 (EPS_II_BP_COUNT is set to 2 in build/CMakeLists.txt). Same defaults as instance 0.
#define FDIR_EPS_INST1_CMD_EXEC_FAILURE_DETECTION_STATE DETECTION_DISABLED
#define FDIR_EPS_INST1_CMD_EXEC_FAILURE_LEVEL           FDIR_LEVEL_WARNING

#define FDIR_EPS_INST1_BATT_VOLTAGE_BELOW_SAFE_DETECTION_STATE DETECTION_DISABLED
#define FDIR_EPS_INST1_BATT_VOLTAGE_BELOW_SAFE_LEVEL           FDIR_LEVEL_WARNING

#define FDIR_EPS_INST1_BATT_TEMP_BELOW_SAFE_DETECTION_STATE DETECTION_DISABLED
#define FDIR_EPS_INST1_BATT_TEMP_BELOW_SAFE_LEVEL           FDIR_LEVEL_WARNING

#define FDIR_EPS_INST1_BATT_TEMP_ABOVE_SAFE_DETECTION_STATE DETECTION_DISABLED
#define FDIR_EPS_INST1_BATT_TEMP_ABOVE_SAFE_LEVEL           FDIR_LEVEL_WARNING

#endif /* EPS_II_TELEMETRY_H_ */
