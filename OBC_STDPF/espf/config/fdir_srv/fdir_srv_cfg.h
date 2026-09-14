/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef FDIR_SRV_CFG_H
#define FDIR_SRV_CFG_H

/**
 * @addtogroup fdir_srv
 * @{
 *
 * @file     fdir_srv_cfg.h
 * @brief    Types compile-time configuration definitions and link-time configuration
 *           declarations for the FDIR service
 *
 * @}
 */

#include "fdir_srv_types.h"

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/

/**
 *  @brief Value used to force generation of enumerations with a minimum bit size
 */
#define FDIR_ENUM_BIT_EXTENDER (0xFFFF)

/**
 *  @brief Constant that indicates unknown FDIR fault due to some error
 */
#define FDIR_FAULT_INVALID ((fdir_fault_id_t)0xFFFF)
/**
 *  @brief Constant that indicates unknown FDIR agent due to some error
 */
#define FDIR_AGENT_INVALID ((fdir_agent_id_t)0xFFFF)

/**
 *  @brief FDIR levels
 */
#define FDIR_LEVEL_WARNING  ((uint8_t)0x00)       /**< Faults at level 0 are only logged, no automatic action is to be taken. */
#define FDIR_LEVEL_MINOR    ((uint8_t)0x01)       /**< Level 1 only occur in mission submodes and no automatic action is to be taken, but the level can be used as a hint for the payload handler component to stop operating with the payload.*/
#define FDIR_LEVEL_MAJOR    ((uint8_t)0x02)       /**< Level 2 sets to SAFE mode. Can only be cleared from ground command. */
#define FDIR_LEVEL_CRITICAL ((uint8_t)0x03)       /**< Level 3 deactiveate all sat functions except ground comm. */
#define FDIR_LEVEL_MAX      (FDIR_LEVEL_CRITICAL) /**< The maximum valid fdir level. */
#define FDIR_LEVEL_COUNT    (1 + FDIR_LEVEL_MAX)  /**< The count of fdir levels. */
#define FDIR_LEVEL_INVALID  ((uint8_t)0xFF)       /**< This is invalid value for FDIR level. */

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/**
 *  @brief Enumeration with all FDIR faults
 *
 *  @note The list is platform- and/or mission-specific
 */
typedef enum
{
    // Test faults
    FDIR_FAULT_WARNING,
    FDIR_FAULT_MINOR,
    FDIR_FAULT_MAJOR,
    FDIR_FAULT_CRITICAL,
    FDIR_FAULT_DUMMY,

    // S-Band TMTC faults
    FDIR_FAULT_S_BAND_TMTC_CMD_EXEC_FAILURE,

    // UHF faults
    FDIR_FAULT_UHF_CMD_EXEC_FAILURE,

    // GNSS faults
    FDIR_FAULT_GNSS_CMD_EXEC_FAILURE,

    // SDR faults
    FDIR_FAULT_SDR_CMD_EXEC_FAILURE,

    // S/X-Band faults
    FDIR_FAULT_S_X_BAND_CMD_EXEC_FAILURE,

    // Thruster faults
    FDIR_FAULT_THRUSTER_CMD_EXEC_FAILURE,
    FDIR_FAULT_THRUSTER_FIRING_DENIAL,
    FDIR_FAULT_THRUSTER_GROUND_TEST_DENIAL,
    FDIR_FAULT_THRUSTER_PREPARING_DENIAL,
    FDIR_FAULT_THRUSTER_SELF_TEST_FAILURE,
    FDIR_FAULT_THRUSTER_GROUND_TEST_FAILURE,

    FDIR_FAULT_EPS_BATT_VOLTAGE_BELOW_SAFE,
    // clang-format off

// begin EPS BP generated code

    FDIR_FAULT_EPS_INST0_CMD_EXEC_FAILURE,
    FDIR_FAULT_EPS_INST0_BATT_VOLTAGE_BELOW_SAFE,
    FDIR_FAULT_EPS_INST0_BATT_TEMP_BELOW_SAFE,
    FDIR_FAULT_EPS_INST0_BATT_TEMP_ABOVE_SAFE,
    FDIR_FAULT_EPS_INST1_CMD_EXEC_FAILURE,
    FDIR_FAULT_EPS_INST1_BATT_VOLTAGE_BELOW_SAFE,
    FDIR_FAULT_EPS_INST1_BATT_TEMP_BELOW_SAFE,
    FDIR_FAULT_EPS_INST1_BATT_TEMP_ABOVE_SAFE,
// end EPS BP generated code

// begin EPS_III BP generated code

    FDIR_FAULT_EPSIII_BP_INST0_CMD_EXEC_FAILURE,
    FDIR_FAULT_EPSIII_BP_INST0_BATT_VOLTAGE_BELOW_SAFE,
    FDIR_FAULT_EPSIII_BP_INST0_BATT_TEMP_BELOW_SAFE,
    FDIR_FAULT_EPSIII_BP_INST0_BATT_TEMP_ABOVE_SAFE,
// end EPS_III BP generated code

// begin EPS_III PDM_A generated code

    FDIR_FAULT_EPSIII_PDM_A_INST0_CMD_EXEC_FAILURE,
// end EPS_III PDM_A generated code
// begin EPS_III PDM_B generated code

    FDIR_FAULT_EPSIII_PDM_B_INST0_CMD_EXEC_FAILURE,
// end EPS_III PDM_B generated code
// begin EPS_III EXPANDER generated code

    FDIR_FAULT_EPSIII_EXPANDER_INST0_CMD_EXEC_FAILURE,
// end EPS_III EXPANDER generated code
// begin EPS_III INPUT_STAGE generated code

    FDIR_FAULT_EPSIII_INPUT_STAGE_INST0_CMD_EXEC_FAILURE,
// end EPS_III INPUT_STAGE generated code

    // clang-format on

    FDIR_FAULT_EPS_PDM_CMD_EXEC_FAILURE,
    // ADCS faults
    FDIR_FAULT_ADCS_CMD_EXEC_FAILURE,
    FDIR_FAULT_ADCS_RWL_NOT_IN_APPL_MODE,
    FDIR_FAULT_ADCS_RWL_COMM_ERROR,
    FDIR_FAULT_ADCS_RWL_FAILURE,
    FDIR_FAULT_ADCS_RWL_SETUP_ERROR,
    FDIR_FAULT_ADCS_RWL_DISCOVERY_ERROR,
    FDIR_FAULT_ADCS_RWL_PORT_VALIDATION_ERROR,
    FDIR_FAULT_ADCS_PRIM_MAGN_NOT_IN_APPL_MODE,
    FDIR_FAULT_ADCS_PRIM_MAGN_COMM_ERROR,
    FDIR_FAULT_ADCS_PRIM_MAGN_FAILURE,
    FDIR_FAULT_ADCS_PRIM_MAGN_SETUP_ERROR,
    FDIR_FAULT_ADCS_PRIM_MAGN_DISCOVERY_ERROR,
    FDIR_FAULT_ADCS_PRIM_MAGN_PORT_VALIDATION_ERROR,
    FDIR_FAULT_ADCS_BOTH_MAGN_NOT_IN_APPL_MODE,
    FDIR_FAULT_ADCS_BOTH_MAGN_COMM_ERROR,
    FDIR_FAULT_ADCS_BOTH_MAGN_FAILURE,
    FDIR_FAULT_ADCS_BOTH_MAGN_SETUP_ERROR,
    FDIR_FAULT_ADCS_BOTH_MAGN_DISCOVERY_ERROR,
    FDIR_FAULT_ADCS_BOTH_MAGN_PORT_VALIDATION_ERROR,
    FDIR_FAULT_ADCS_PRIM_GYRO_VOLTAGE_ERROR,
    FDIR_FAULT_ADCS_PRIM_GYRO_CRITICAL_ERROR,
    FDIR_FAULT_ADCS_BOTH_GYRO_VOLTAGE_ERROR,
    FDIR_FAULT_ADCS_BOTH_GYRO_CRITICAL_ERROR,
    FDIR_FAULT_ADCS_CONTROL_LOOP_FAILURE,
    FDIR_FAULT_ADCS_CONTROL_LOOP_CRITICAL_ERROR,
    FDIR_FAULT_ADCS_CONFIGURATION_VALIDATION_ERROR,
    FDIR_FAULT_ADCS_CONFIGURATION_PERSIST_ERROR,
    FDIR_FAULT_ADCS_VIRTUAL_WATCHDOG_ERROR,
    FDIR_FAULT_ADCS_REACTION_WHEEL_ABOVE_10000RPM,

    // X-Band Front-End faults
    FDIR_FAULT_X_BAND_FE_CMD_EXEC_FAILURE,

    FDIR_FAULT_COUNT,

    FDIR_FAULT_TYPE_EXTENDER = FDIR_ENUM_BIT_EXTENDER
} fdir_fault_id_t;

/**
 *  @brief Enumeration with all FDIR agents
 *
 *  @note The list is platform- and/or mission-specific
 */
typedef enum
{
    FDIR_AGENT_TEST_LEVEL, // for testing
    FDIR_AGENT_DUMMY,      // for testing

    FDIR_AGENT_S_BAND_TMTC,
    FDIR_AGENT_UHF,
    FDIR_AGENT_GNSS,
    FDIR_AGENT_SDR,
    FDIR_AGENT_S_X_BAND,
    FDIR_AGENT_THRUSTER,
    FDIR_AGENT_EPS_I,
    FDIR_AGENT_EPS_II,
    FDIR_AGENT_EPS_III,
    FDIR_AGENT_EPS_M,
    FDIR_AGENT_CUBE_ADCS,
    FDIR_AGENT_CUBE_ADCS_GEN2,
    // BEGIN_ES_ADCS_MARKER
    FDIR_AGENT_ES_ADCS,
    // END_ES_ADCS_MARKER

    FDIR_AGENT_OPERATOR,
    FDIR_AGENT_CONOPS,

    FDIR_AGENT_XBAND_FE,

    FDIR_AGENT_COUNT,
    FDIR_AGENT_TYPE_EXTENDER = FDIR_ENUM_BIT_EXTENDER
} fdir_agent_id_t;

typedef bool (*fp_fdir_detection_t)(void *ctx);

/**
 *  @brief Result codes for FDIR handler actions
 */
typedef enum
{
    FDIR_ACTION_RESULT_OK,       /**< Isolation/recovery executed successfully */
    FDIR_ACTION_RESULT_ESCALATE, /**< Higher-level handler needs to be invoked */
    FDIR_ACTION_RESULT_ERROR     /**< Undefined state */
} fdir_action_result_t;

/**
 *  @brief Interface for an action handler function
 *
 *  @param p_ctx[in,out]: Context information to be passed to the handler. Could also be modified inside the handler
 *                        for purposes of extended feedback
 *
 *  @return Result of the handler's invocation
 */
typedef fdir_action_result_t (*fdir_action_func_t)(fdir_fault_id_t fault, void *const p_ctx);

/**
 *  @brief Definition of an isolation/recovery action
 */
typedef struct fdir_action_tag
{
    const fdir_action_func_t p_action_func;           /**< Handler function to be invoked for isolation/recovery. Executed in
                                                           a critical section, so it should be as fast as possible, preferably
                                                           without blocking calls inside */
    const struct fdir_action_tag *p_escalated_action; /**< Action to be performed in case higher-level handling is needed */
    const uint8_t                 fdir_level;         /**< The FDIR level associated with this action */
} fdir_action_t;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/

extern const fdir_action_t g_fdir_action[FDIR_FAULT_COUNT];

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

void fdir_srv_cfg_sys_level_update_notif(void);

const fdir_fault_id_t *get_fault_per_agent_list(const fdir_agent_id_t agent_id);
const size_t           get_fault_per_agent_count(const fdir_agent_id_t agent_id);
const char            *get_agent_id_name(const fdir_agent_id_t id);
const char            *get_fault_id_name(const fdir_fault_id_t id);

#endif /* FDIR_SRV_CFG_H */
