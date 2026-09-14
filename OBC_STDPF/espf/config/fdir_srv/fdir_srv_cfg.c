/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup fdir_srv
 * @{
 *
 * @file     fdir_srv_cfg.c
 * @brief    Link-time configuration for the FDIR service
 *
 * @}
 */

#include "fdir_srv_cfg.h"
#include "fdir_srv.h"
#include "datacache.h"
#include "conops.h"
#include "eps_ii_telemetry_cfg.h"
#include "eps_iii_bp_cfg.h"
#include "eps_iii_pdm_a_cfg.h"
#include "eps_iii_pdm_b_cfg.h"
#include "eps_iii_expander_cfg.h"
#include "eps_iii_input_stage_cfg.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

#define FDIR_FAULT_COUNT_FOR_S_BAND_TMTC    1
#define FDIR_FAULT_COUNT_FOR_UHF            1
#define FDIR_FAULT_COUNT_FOR_GNSS           1
#define FDIR_FAULT_COUNT_FOR_SDR            1
#define FDIR_FAULT_COUNT_FOR_S_X_BAND       1
#define FDIR_FAULT_COUNT_FOR_THRUSTER       6
#define FDIR_FAULT_COUNT_FOR_EPS_I          2
#define FDIR_FAULT_COUNT_FOR_EPS_II         4
#define FDIR_FAULT_COUNT_FOR_EPS_M          0
#define FDIR_FAULT_COUNT_FOR_CUBE_ADCS      0
#define FDIR_FAULT_COUNT_FOR_CUBE_ADCS_GEN2 29
// BEGIN_ES_ADCS_MARKER
#define FDIR_FAULT_COUNT_FOR_ES_ADCS 0
// END_ES_ADCS_MARKER
#define FDIR_FAULT_COUNT_FOR_CONOPS     0
#define FDIR_FAULT_COUNT_FOR_OPERATOR   0
#define FDIR_FAULT_COUNT_FOR_DUMMY      1
#define FDIR_FAULT_COUNT_FOR_TEST_LEVEL 4

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/

const fdir_action_t fdir_act_fault_batt = { .p_action_func = NULL, .p_escalated_action = NULL, .fdir_level = FDIR_LEVEL_MAJOR };

// this may be a static function entirely defined in this file or an external function in completely different module
static fdir_action_result_t fdir_action_func_dummy_alpha(fdir_fault_id_t fault, void *const p_ctx);
static fdir_action_result_t fdir_action_func_dummy_beta(fdir_fault_id_t fault, void *const p_ctx);
static fdir_action_result_t fdir_action_func_dummy_gamma(fdir_fault_id_t fault, void *const p_ctx);

const fdir_action_t fdir_action_dummy_gamma = { .p_action_func = fdir_action_func_dummy_gamma, .p_escalated_action = NULL, .fdir_level = FDIR_LEVEL_CRITICAL };
const fdir_action_t fdir_action_dummy_beta  = { .p_action_func = fdir_action_func_dummy_beta, .p_escalated_action = &fdir_action_dummy_gamma, .fdir_level = FDIR_LEVEL_MAJOR };

static const char *const fault_id_name[FDIR_FAULT_COUNT] = {
    // S-Band faults
    [FDIR_FAULT_S_BAND_TMTC_CMD_EXEC_FAILURE] = "FDIR_FAULT_S_BAND_TMTC_CMD_EXEC_FAILURE",

    // UHF faults
    [FDIR_FAULT_UHF_CMD_EXEC_FAILURE] = "FDIR_FAULT_UHF_CMD_EXEC_FAILURE",

    // GNSS faults
    [FDIR_FAULT_GNSS_CMD_EXEC_FAILURE] = "FDIR_FAULT_GNSS_CMD_EXEC_FAILURE",

    // SDR faults
    [FDIR_FAULT_SDR_CMD_EXEC_FAILURE] = "FDIR_FAULT_SDR_CMD_EXEC_FAILURE",

    // X-Band faults
    [FDIR_FAULT_S_X_BAND_CMD_EXEC_FAILURE] = "FDIR_FAULT_S_X_BAND_CMD_EXEC_FAILURE",
    [FDIR_FAULT_X_BAND_FE_CMD_EXEC_FAILURE] = "FDIR_FAULT_X_BAND_FE_CMD_EXEC_FAILURE",

    // Thruster faults
    [FDIR_FAULT_THRUSTER_CMD_EXEC_FAILURE]    = "FDIR_FAULT_THRUSTER_CMD_EXEC_FAILURE",
    [FDIR_FAULT_THRUSTER_FIRING_DENIAL]       = "FDIR_FAULT_THRUSTER_FIRING_DENIAL",
    [FDIR_FAULT_THRUSTER_GROUND_TEST_DENIAL]  = "FDIR_FAULT_THRUSTER_GROUND_TEST_DENIAL",
    [FDIR_FAULT_THRUSTER_PREPARING_DENIAL]    = "FDIR_FAULT_THRUSTER_PREPARING_DENIAL",
    [FDIR_FAULT_THRUSTER_SELF_TEST_FAILURE]   = "FDIR_FAULT_THRUSTER_SELF_TEST_FAILURE",
    [FDIR_FAULT_THRUSTER_GROUND_TEST_FAILURE] = "FDIR_FAULT_THRUSTER_GROUND_TEST_FAILURE",

    // EPS faults
    [FDIR_FAULT_EPS_BATT_VOLTAGE_BELOW_SAFE] = "FDIR_FAULT_EPS_BATT_VOLTAGE_BELOW_SAFE",
    [FDIR_FAULT_EPS_PDM_CMD_EXEC_FAILURE]    = "FDIR_FAULT_EPS_PDM_CMD_EXEC_FAILURE",
    // clang-format off

// begin EPS BP generated code

    [FDIR_FAULT_EPS_INST0_CMD_EXEC_FAILURE]        = "FDIR_FAULT_EPS_INST0_CMD_EXEC_FAILURE",
    [FDIR_FAULT_EPS_INST0_BATT_VOLTAGE_BELOW_SAFE] = "FDIR_FAULT_EPS_INST0_BATT_VOLTAGE_BELOW_SAFE",
    [FDIR_FAULT_EPS_INST0_BATT_TEMP_BELOW_SAFE]    = "FDIR_FAULT_EPS_INST0_BATT_TEMP_BELOW_SAFE",
    [FDIR_FAULT_EPS_INST0_BATT_TEMP_ABOVE_SAFE]    = "FDIR_FAULT_EPS_INST0_BATT_TEMP_ABOVE_SAFE",
    [FDIR_FAULT_EPS_INST1_CMD_EXEC_FAILURE]        = "FDIR_FAULT_EPS_INST1_CMD_EXEC_FAILURE",
    [FDIR_FAULT_EPS_INST1_BATT_VOLTAGE_BELOW_SAFE] = "FDIR_FAULT_EPS_INST1_BATT_VOLTAGE_BELOW_SAFE",
    [FDIR_FAULT_EPS_INST1_BATT_TEMP_BELOW_SAFE]    = "FDIR_FAULT_EPS_INST1_BATT_TEMP_BELOW_SAFE",
    [FDIR_FAULT_EPS_INST1_BATT_TEMP_ABOVE_SAFE]    = "FDIR_FAULT_EPS_INST1_BATT_TEMP_ABOVE_SAFE",
// end EPS BP generated code

// begin EPS_III BP generated code

    [FDIR_FAULT_EPSIII_BP_INST0_CMD_EXEC_FAILURE]           = "FDIR_EPSIII_BP_INST0_CMD_EXEC_FAILURE",
    [FDIR_FAULT_EPSIII_BP_INST0_BATT_VOLTAGE_BELOW_SAFE]    = "FDIR_EPSIII_BP_INST0_BATT_VOLTAGE_BELOW_SAFE",
    [FDIR_FAULT_EPSIII_BP_INST0_BATT_TEMP_BELOW_SAFE]       = "FDIR_EPSIII_BP_INST0_BATT_TEMP_BELOW_SAFE",
    [FDIR_FAULT_EPSIII_BP_INST0_BATT_TEMP_ABOVE_SAFE]       = "FDIR_EPSIII_BP_INST0_BATT_TEMP_ABOVE_SAFE",
// end EPS_III BP generated code

// begin EPS_III PDM_A generated code

    [FDIR_FAULT_EPSIII_PDM_A_INST0_CMD_EXEC_FAILURE]        = "FDIR_EPSIII_PDM_A_INST0_CMD_EXEC_FAILURE",
// end EPS_III PDM_A generated code
// begin EPS_III PDM_B generated code

    [FDIR_FAULT_EPSIII_PDM_B_INST0_CMD_EXEC_FAILURE]        = "FDIR_EPSIII_PDM_B_INST0_CMD_EXEC_FAILURE",
// end EPS_III PDM_B generated code
// begin EPS_III EXPANDER generated code

    [FDIR_FAULT_EPSIII_EXPANDER_INST0_CMD_EXEC_FAILURE]        = "FDIR_EPSIII_EXPANDER_INST0_CMD_EXEC_FAILURE",
// end EPS_III EXPANDER generated code
// begin EPS_III INPUT_STAGE generated code

    [FDIR_FAULT_EPSIII_INPUT_STAGE_INST0_CMD_EXEC_FAILURE]           = "FDIR_EPSIII_INPUT_STAGE_INST0_CMD_EXEC_FAILURE",
// end EPS_III INPUT_STAGE generated code

    // clang-format on
    // ADCS faults
    [FDIR_FAULT_ADCS_CMD_EXEC_FAILURE]                = "FDIR_FAULT_ADCS_CMD_EXEC_FAILURE",
    [FDIR_FAULT_ADCS_RWL_NOT_IN_APPL_MODE]            = "FDIR_FAULT_ADCS_RWL_NOT_IN_APPL_MODE",
    [FDIR_FAULT_ADCS_RWL_COMM_ERROR]                  = "FDIR_FAULT_ADCS_RWL_COMM_ERROR",
    [FDIR_FAULT_ADCS_RWL_FAILURE]                     = "FDIR_FAULT_ADCS_RWL_FAILURE",
    [FDIR_FAULT_ADCS_RWL_SETUP_ERROR]                 = "FDIR_FAULT_ADCS_RWL_SETUP_ERROR",
    [FDIR_FAULT_ADCS_RWL_DISCOVERY_ERROR]             = "FDIR_FAULT_ADCS_RWL_DISCOVERY_ERROR",
    [FDIR_FAULT_ADCS_RWL_PORT_VALIDATION_ERROR]       = "FDIR_FAULT_ADCS_RWL_PORT_VALIDATION_ERROR",
    [FDIR_FAULT_ADCS_PRIM_MAGN_NOT_IN_APPL_MODE]      = "FDIR_FAULT_ADCS_PRIM_MAGN_NOT_IN_APPL_MODE",
    [FDIR_FAULT_ADCS_PRIM_MAGN_COMM_ERROR]            = "FDIR_FAULT_ADCS_PRIM_MAGN_COMM_ERROR",
    [FDIR_FAULT_ADCS_PRIM_MAGN_FAILURE]               = "FDIR_FAULT_ADCS_PRIM_MAGN_FAILURE",
    [FDIR_FAULT_ADCS_PRIM_MAGN_SETUP_ERROR]           = "FDIR_FAULT_ADCS_PRIM_MAGN_SETUP_ERROR",
    [FDIR_FAULT_ADCS_PRIM_MAGN_DISCOVERY_ERROR]       = "FDIR_FAULT_ADCS_PRIM_MAGN_DISCOVERY_ERROR",
    [FDIR_FAULT_ADCS_PRIM_MAGN_PORT_VALIDATION_ERROR] = "FDIR_FAULT_ADCS_PRIM_MAGN_PORT_VALIDATION_ERROR",
    [FDIR_FAULT_ADCS_BOTH_MAGN_NOT_IN_APPL_MODE]      = "FDIR_FAULT_ADCS_BOTH_MAGN_NOT_IN_APPL_MODE",
    [FDIR_FAULT_ADCS_BOTH_MAGN_COMM_ERROR]            = "FDIR_FAULT_ADCS_BOTH_MAGN_COMM_ERROR",
    [FDIR_FAULT_ADCS_BOTH_MAGN_FAILURE]               = "FDIR_FAULT_ADCS_BOTH_MAGN_FAILURE",
    [FDIR_FAULT_ADCS_BOTH_MAGN_SETUP_ERROR]           = "FDIR_FAULT_ADCS_BOTH_MAGN_SETUP_ERROR",
    [FDIR_FAULT_ADCS_BOTH_MAGN_DISCOVERY_ERROR]       = "FDIR_FAULT_ADCS_BOTH_MAGN_DISCOVERY_ERROR",
    [FDIR_FAULT_ADCS_BOTH_MAGN_PORT_VALIDATION_ERROR] = "FDIR_FAULT_ADCS_BOTH_MAGN_PORT_VALIDATION_ERROR",
    [FDIR_FAULT_ADCS_PRIM_GYRO_VOLTAGE_ERROR]         = "FDIR_FAULT_ADCS_PRIM_GYRO_VOLTAGE_ERROR",
    [FDIR_FAULT_ADCS_PRIM_GYRO_CRITICAL_ERROR]        = "FDIR_FAULT_ADCS_PRIM_GYRO_CRITICAL_ERROR",
    [FDIR_FAULT_ADCS_BOTH_GYRO_VOLTAGE_ERROR]         = "FDIR_FAULT_ADCS_BOTH_GYRO_VOLTAGE_ERROR",
    [FDIR_FAULT_ADCS_BOTH_GYRO_CRITICAL_ERROR]        = "FDIR_FAULT_ADCS_BOTH_GYRO_CRITICAL_ERROR",
    [FDIR_FAULT_ADCS_CONTROL_LOOP_FAILURE]            = "FDIR_FAULT_ADCS_CONTROL_LOOP_FAILURE",
    [FDIR_FAULT_ADCS_CONTROL_LOOP_CRITICAL_ERROR]     = "FDIR_FAULT_ADCS_CONTROL_LOOP_CRITICAL_ERROR",
    [FDIR_FAULT_ADCS_CONFIGURATION_VALIDATION_ERROR]  = "FDIR_FAULT_ADCS_CONFIGURATION_VALIDATION_ERROR",
    [FDIR_FAULT_ADCS_CONFIGURATION_PERSIST_ERROR]     = "FDIR_FAULT_ADCS_CONFIGURATION_PERSIST_ERROR",
    [FDIR_FAULT_ADCS_VIRTUAL_WATCHDOG_ERROR]          = "FDIR_FAULT_ADCS_VIRTUAL_WATCHDOG_ERROR",
    [FDIR_FAULT_ADCS_REACTION_WHEEL_ABOVE_10000RPM]   = "FDIR_FAULT_ADCS_REACTION_WHEEL_ABOVE_10000RPM",

    // the following group of faults are for testing and should be removed in the released version
    [FDIR_FAULT_DUMMY]    = "FDIR_FAULT_DUMMY",
    [FDIR_FAULT_WARNING]  = "FDIR_FAULT_WARNING",
    [FDIR_FAULT_MINOR]    = "FDIR_FAULT_MINOR",
    [FDIR_FAULT_MAJOR]    = "FDIR_FAULT_MAJOR",
    [FDIR_FAULT_CRITICAL] = "FDIR_FAULT_CRITICAL",
};

const char *const agent_id_name[FDIR_AGENT_COUNT] = {
    [FDIR_AGENT_S_BAND_TMTC]    = "FDIR_AGENT_S_BAND_TMTC",
    [FDIR_AGENT_UHF]            = "FDIR_AGENT_UHF",
    [FDIR_AGENT_GNSS]           = "FDIR_AGENT_GNSS",
    [FDIR_AGENT_SDR]            = "FDIR_AGENT_SDR",
    [FDIR_AGENT_S_X_BAND]       = "FDIR_AGENT_S_X_BAND",
    [FDIR_AGENT_THRUSTER]       = "FDIR_AGENT_THRUSTER",
    [FDIR_AGENT_EPS_I]          = "FDIR_AGENT_EPS_I",
    [FDIR_AGENT_EPS_II]         = "FDIR_AGENT_EPS_II",
    [FDIR_AGENT_EPS_M]          = "FDIR_AGENT_EPS_M",
    [FDIR_AGENT_CUBE_ADCS]      = "FDIR_AGENT_CUBE_ADCS",
    [FDIR_AGENT_CUBE_ADCS_GEN2] = "FDIR_AGENT_CUBE_ADCS_GEN2",
    // BEGIN_ES_ADCS_MARKER
    [FDIR_AGENT_ES_ADCS] = "FDIR_AGENT_ES_ADCS",
    // BEGIN_ES_ADCS_MARKER

    [FDIR_AGENT_OPERATOR] = "FDIR_AGENT_OPERATOR",
    [FDIR_AGENT_CONOPS]   = "FDIR_AGENT_CONOPS",
    [FDIR_AGENT_XBAND_FE] = "FDIR_AGENT_XBAND_FE",
    [FDIR_AGENT_EPS_III]  = "FDIR_AGENT_EPS_III",

    [FDIR_AGENT_DUMMY]      = "FDIR_AGENT_DUMMY",      // Remove this once actual agents are configured
    [FDIR_AGENT_TEST_LEVEL] = "FDIR_AGENT_TEST_LEVEL", // Remove this once actual agents are configured
};

const char *get_fault_id_name(const fdir_fault_id_t id)
{
    if (id >= FDIR_FAULT_COUNT)
    {
        return "FDIR_FAULT_INVALID_ID";
    }
    return fault_id_name[id];
}

const char *get_agent_id_name(const fdir_agent_id_t id)
{
    if (id >= FDIR_AGENT_COUNT)
    {
        return "FDIR_AGENT_INVALID_ID";
    }
    return agent_id_name[id];
}

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/

const fdir_action_t g_fdir_action[FDIR_FAULT_COUNT] = {
    [FDIR_FAULT_S_BAND_TMTC_CMD_EXEC_FAILURE] = {.fdir_level = FDIR_LEVEL_MAJOR,     .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_UHF_CMD_EXEC_FAILURE]         = { .fdir_level = FDIR_LEVEL_WARNING,  .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_GNSS_CMD_EXEC_FAILURE]        = { .fdir_level = FDIR_LEVEL_WARNING,  .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_SDR_CMD_EXEC_FAILURE]         = { .fdir_level = FDIR_LEVEL_MINOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_S_X_BAND_CMD_EXEC_FAILURE]    = { .fdir_level = FDIR_LEVEL_MINOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_THRUSTER_CMD_EXEC_FAILURE]    = { .fdir_level = FDIR_LEVEL_MINOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_THRUSTER_FIRING_DENIAL]       = { .fdir_level = FDIR_LEVEL_MINOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_THRUSTER_GROUND_TEST_DENIAL]  = { .fdir_level = FDIR_LEVEL_MINOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_THRUSTER_PREPARING_DENIAL]    = { .fdir_level = FDIR_LEVEL_MINOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_THRUSTER_SELF_TEST_FAILURE]   = { .fdir_level = FDIR_LEVEL_MINOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_THRUSTER_GROUND_TEST_FAILURE] = { .fdir_level = FDIR_LEVEL_MINOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_EPS_PDM_CMD_EXEC_FAILURE]     = { .fdir_level = FDIR_LEVEL_WARNING,  .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_EPS_BATT_VOLTAGE_BELOW_SAFE]  = { .fdir_level = FDIR_LEVEL_MAJOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
 // clang-format off

// begin EPS BP generated configuration

    [FDIR_FAULT_EPS_INST0_CMD_EXEC_FAILURE]        = { .fdir_level = FDIR_EPS_INST0_CMD_EXEC_FAILURE_LEVEL,        .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_EPS_INST0_BATT_VOLTAGE_BELOW_SAFE] = { .fdir_level = FDIR_EPS_INST0_BATT_VOLTAGE_BELOW_SAFE_LEVEL, .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_EPS_INST0_BATT_TEMP_BELOW_SAFE]    = { .fdir_level = FDIR_EPS_INST0_BATT_TEMP_BELOW_SAFE_LEVEL,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_EPS_INST0_BATT_TEMP_ABOVE_SAFE]    = { .fdir_level = FDIR_EPS_INST0_BATT_TEMP_ABOVE_SAFE_LEVEL,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_EPS_INST1_CMD_EXEC_FAILURE]        = { .fdir_level = FDIR_EPS_INST1_CMD_EXEC_FAILURE_LEVEL,        .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_EPS_INST1_BATT_VOLTAGE_BELOW_SAFE] = { .fdir_level = FDIR_EPS_INST1_BATT_VOLTAGE_BELOW_SAFE_LEVEL, .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_EPS_INST1_BATT_TEMP_BELOW_SAFE]    = { .fdir_level = FDIR_EPS_INST1_BATT_TEMP_BELOW_SAFE_LEVEL,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_EPS_INST1_BATT_TEMP_ABOVE_SAFE]    = { .fdir_level = FDIR_EPS_INST1_BATT_TEMP_ABOVE_SAFE_LEVEL,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
// end EPS BP generated configuration
// begin EPS_III BP generated configuration

    [FDIR_FAULT_EPSIII_BP_INST0_CMD_EXEC_FAILURE]           = { .fdir_level = FDIR_EPSIII_BP_INST0_CMD_EXEC_FAILURE_LEVEL,         .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_EPSIII_BP_INST0_BATT_VOLTAGE_BELOW_SAFE]    = { .fdir_level = FDIR_EPSIII_BP_INST0_BATT_VOLTAGE_BELOW_SAFE_LEVEL,  .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_EPSIII_BP_INST0_BATT_TEMP_BELOW_SAFE]       = { .fdir_level = FDIR_EPSIII_BP_INST0_BATT_TEMP_BELOW_SAFE_LEVEL,     .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_EPSIII_BP_INST0_BATT_TEMP_ABOVE_SAFE]       = { .fdir_level = FDIR_EPSIII_BP_INST0_BATT_TEMP_ABOVE_SAFE_LEVEL,     .p_action_func = NULL,                         .p_escalated_action = NULL                   },
// end EPS_III BP generated configuration
// begin EPS_III PDM_A generated configuration

    [FDIR_FAULT_EPSIII_PDM_A_INST0_CMD_EXEC_FAILURE]        = { .fdir_level = FDIR_EPSIII_PDM_A_INST0_CMD_EXEC_FAILURE_LEVEL,        .p_action_func = NULL,                         .p_escalated_action = NULL                   },
// end EPS_III PDM_A generated configuration
// begin EPS_III PDM_B generated configuration

    [FDIR_FAULT_EPSIII_PDM_B_INST0_CMD_EXEC_FAILURE]        = { .fdir_level = FDIR_EPSIII_PDM_B_INST0_CMD_EXEC_FAILURE_LEVEL,        .p_action_func = NULL,                         .p_escalated_action = NULL                   },
// end EPS_III PDM_B generated configuration
// begin EPS_III EXPANDER generated configuration

    [FDIR_FAULT_EPSIII_EXPANDER_INST0_CMD_EXEC_FAILURE]        = { .fdir_level = FDIR_EPSIII_EXPANDER_INST0_CMD_EXEC_FAILURE_LEVEL,        .p_action_func = NULL,                         .p_escalated_action = NULL                   },
// end EPS_III EXPANDER generated configuration
// begin EPS_III INPUT_STAGE generated configuration

    [FDIR_FAULT_EPSIII_INPUT_STAGE_INST0_CMD_EXEC_FAILURE]           = { .fdir_level = FDIR_EPSIII_INPUT_STAGE_INST0_CMD_EXEC_FAILURE_LEVEL,         .p_action_func = NULL,                         .p_escalated_action = NULL                   },
// end EPS_III INPUT_STAGE generated configuration

  // clang-format on

    [FDIR_FAULT_ADCS_CMD_EXEC_FAILURE]                = { .fdir_level = FDIR_LEVEL_MAJOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_RWL_NOT_IN_APPL_MODE]            = { .fdir_level = FDIR_LEVEL_MAJOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_RWL_COMM_ERROR]                  = { .fdir_level = FDIR_LEVEL_MAJOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_RWL_FAILURE]                     = { .fdir_level = FDIR_LEVEL_MAJOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_RWL_SETUP_ERROR]                 = { .fdir_level = FDIR_LEVEL_MAJOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_RWL_DISCOVERY_ERROR]             = { .fdir_level = FDIR_LEVEL_MAJOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_RWL_PORT_VALIDATION_ERROR]       = { .fdir_level = FDIR_LEVEL_MAJOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_PRIM_MAGN_NOT_IN_APPL_MODE]      = { .fdir_level = FDIR_LEVEL_MAJOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_PRIM_MAGN_COMM_ERROR]            = { .fdir_level = FDIR_LEVEL_MAJOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_PRIM_MAGN_FAILURE]               = { .fdir_level = FDIR_LEVEL_MAJOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_PRIM_MAGN_SETUP_ERROR]           = { .fdir_level = FDIR_LEVEL_MAJOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_PRIM_MAGN_DISCOVERY_ERROR]       = { .fdir_level = FDIR_LEVEL_MAJOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_PRIM_MAGN_PORT_VALIDATION_ERROR] = { .fdir_level = FDIR_LEVEL_MAJOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_BOTH_MAGN_NOT_IN_APPL_MODE]      = { .fdir_level = FDIR_LEVEL_CRITICAL, .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_BOTH_MAGN_COMM_ERROR]            = { .fdir_level = FDIR_LEVEL_CRITICAL, .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_BOTH_MAGN_FAILURE]               = { .fdir_level = FDIR_LEVEL_CRITICAL, .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_BOTH_MAGN_SETUP_ERROR]           = { .fdir_level = FDIR_LEVEL_CRITICAL, .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_BOTH_MAGN_DISCOVERY_ERROR]       = { .fdir_level = FDIR_LEVEL_CRITICAL, .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_BOTH_MAGN_PORT_VALIDATION_ERROR] = { .fdir_level = FDIR_LEVEL_CRITICAL, .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_PRIM_GYRO_VOLTAGE_ERROR]         = { .fdir_level = FDIR_LEVEL_MAJOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_PRIM_GYRO_CRITICAL_ERROR]        = { .fdir_level = FDIR_LEVEL_MAJOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_BOTH_GYRO_VOLTAGE_ERROR]         = { .fdir_level = FDIR_LEVEL_CRITICAL, .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_BOTH_GYRO_CRITICAL_ERROR]        = { .fdir_level = FDIR_LEVEL_CRITICAL, .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_CONTROL_LOOP_FAILURE]            = { .fdir_level = FDIR_LEVEL_MAJOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_CONTROL_LOOP_CRITICAL_ERROR]     = { .fdir_level = FDIR_LEVEL_CRITICAL, .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_CONFIGURATION_VALIDATION_ERROR]  = { .fdir_level = FDIR_LEVEL_CRITICAL, .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_CONFIGURATION_PERSIST_ERROR]     = { .fdir_level = FDIR_LEVEL_CRITICAL, .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_VIRTUAL_WATCHDOG_ERROR]          = { .fdir_level = FDIR_LEVEL_CRITICAL, .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_ADCS_REACTION_WHEEL_ABOVE_10000RPM]   = { .fdir_level = FDIR_LEVEL_MAJOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_X_BAND_FE_CMD_EXEC_FAILURE]           = { .fdir_level = FDIR_LEVEL_MINOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },

    [FDIR_FAULT_DUMMY] = { .fdir_level = FDIR_LEVEL_MINOR,    .p_action_func = fdir_action_func_dummy_alpha, .p_escalated_action = &fdir_action_dummy_beta},

    [FDIR_FAULT_WARNING]  = { .fdir_level = FDIR_LEVEL_WARNING,  .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_MINOR]    = { .fdir_level = FDIR_LEVEL_MINOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_MAJOR]    = { .fdir_level = FDIR_LEVEL_MAJOR,    .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_CRITICAL] = { .fdir_level = FDIR_LEVEL_CRITICAL, .p_action_func = NULL,                         .p_escalated_action = NULL                   },
};

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

void fdir_srv_cfg_sys_level_update_notif(void)
{
    conops_trigger_hsm(ev_conops_sm_fdir_lvl_updated, NULL);
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

static fdir_action_result_t fdir_action_func_dummy_alpha(fdir_fault_id_t fault, void *const p_ctx)
{
    /* do some Isolation and Recovery actions */
    fdir_srv_log(fault, FDIR_LEVEL_MAJOR, "Dummy fault alpha");
    /* for example action does not manage to recover/isolate fault and tries to escalate */
    return FDIR_ACTION_RESULT_ESCALATE;
}

static fdir_action_result_t fdir_action_func_dummy_beta(fdir_fault_id_t fault, void *const p_ctx)
{
    /* example of successfull recovery:
    fdir_srv_fault_set_state(fault, FDIR_AGENT_DUMMY, false, NULL);
    */
    return FDIR_ACTION_RESULT_OK;
}

static fdir_action_result_t fdir_action_func_dummy_gamma(fdir_fault_id_t fault, void *const p_ctx)
{
    /** In this example this function will never be executed, because dummy_beta returns OK;
     *  normally there would be some logic that would return different results */
    return FDIR_ACTION_RESULT_OK;
}
