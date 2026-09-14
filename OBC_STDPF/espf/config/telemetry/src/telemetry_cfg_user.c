/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/** @file telemetry_cfg_user.c
 *
 * @brief Telemetry service user configuration
 *
 * This file provides helper functions used to simulate certain behaviors of the telemetry service.
 */

#include "telemetry_cfg_user.h"
#include "datacache.h"
#include "conops.h"
#include "fp/conops/v2.0/conops_server/FP_conopsProtocolTypes.h"
#include "assertions.h"
#include "nvm.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/
typedef struct
{
    bool    sim_mode_active; /**< indicates whether sim mode is activated */
    uint8_t req_preset_id;   /**< requested preset id in simulation mode */
} sim_mode_t;

/** @brief Define a map between a telemetry instance and the corresponding NVM block identifiers
 *  for the respective configuration types which the telemetry uses
 */
typedef struct
{
    uint16_t bl_id_gen_cfg;    /**< NVM block ID of the general config for the given telemetry instance */
    uint16_t bl_id_preset_cfg; /**< NVM block ID of the preset config for the given telemetry instance */
    uint16_t bl_id_file_cfg;   /**< NVM block ID of the file config for the given telemetry instance */
    uint16_t bl_id_pd;         /**< NVM block ID of the persistent data stored for the given telemetry instance */
} tlm_instance_nvm_map_t;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/
/** @brief Component runtime context structure for all telemetry instances */
// clang-format off
static tlm_runtime_context_t tlm_rt_context[TELEMETRY_TELEMETRYINSTANCE_MAX_CNT] =
{
    [TELEMETRY_TELEMETRYINSTANCE_TLM_INST_0] =
    {
        .sm_instance_id = TELEMETRY_TELEMETRYINSTANCE_TLM_INST_0,
        .task_mon_id = TASK_ID_TELEMETRY_0,
        .tlm_file_sink_rt.task_mon_id = TASK_ID_TELEMETRY_FILE_SINK_0,
        .tlm_file_sink_rt.sm_instance_id = TELEMETRY_TELEMETRYINSTANCE_TLM_INST_0
    },

    [TELEMETRY_TELEMETRYINSTANCE_TLM_INST_1] =
    {
        .sm_instance_id = TELEMETRY_TELEMETRYINSTANCE_TLM_INST_1,
        .task_mon_id = TASK_ID_TELEMETRY_1,
        .tlm_file_sink_rt.task_mon_id = TASK_ID_TELEMETRY_FILE_SINK_1,
        .tlm_file_sink_rt.sm_instance_id = TELEMETRY_TELEMETRYINSTANCE_TLM_INST_1
    }
};
// clang-format on

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
// clang-format off
static sim_mode_t sim_mode_ctx[TELEMETRY_TELEMETRYINSTANCE_MAX_CNT] =
{
    [TELEMETRY_TELEMETRYINSTANCE_TLM_INST_0] =
    {
        .sim_mode_active = false,
        .req_preset_id   = 0U
    },

    [TELEMETRY_TELEMETRYINSTANCE_TLM_INST_1] =
    {
        .sim_mode_active = false,
        .req_preset_id   = 0U
    }
};

static const tlm_instance_nvm_map_t nvm_cfg_map[TELEMETRY_TELEMETRYINSTANCE_MAX_CNT] =
{
    [TELEMETRY_TELEMETRYINSTANCE_TLM_INST_0] =
    {
        .bl_id_gen_cfg    = NVM_BLOCK_TELEMETRY_GENERAL_0,
        .bl_id_preset_cfg = NVM_BLOCK_TELEMETRY_PRESETS_0,
        .bl_id_file_cfg   = NVM_BLOCK_TELEMETRY_FILE_CFG_0,
        .bl_id_pd    = NVM_BLOCK_TELEMETRY_PERSISTENT_DATA_0
    },

    [TELEMETRY_TELEMETRYINSTANCE_TLM_INST_1] =
    {
        .bl_id_gen_cfg    = NVM_BLOCK_TELEMETRY_GENERAL_1,
        .bl_id_preset_cfg = NVM_BLOCK_TELEMETRY_PRESETS_1,
        .bl_id_file_cfg   = NVM_BLOCK_TELEMETRY_FILE_CFG_1,
        .bl_id_pd    = NVM_BLOCK_TELEMETRY_PERSISTENT_DATA_1
    }
};

// clang-format on

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

uint8_t telemetry_cfg_get_active_preset(const TELEMETRY_TelemetryInstance_t instance_id)
{
    BREAK_ASSERT(instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT);

    uint8_t conops_preset_id = 0U;

    if (instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT)
    {
        if (true == sim_mode_ctx[instance_id].sim_mode_active)
        {
            if (sim_mode_ctx[instance_id].req_preset_id >= TELEMETRY_PRESETS_COUNT)
            {
                sim_mode_ctx[instance_id].req_preset_id = 0U;
            }

            conops_preset_id = sim_mode_ctx[instance_id].req_preset_id;
        }
        else
        {
            uint8_t state_id = 0U;

            conops_get_hsm_active_state(&state_id);

            switch (state_id)
            {
                case CONOPS_OPMODES_MODE_SAFE:
                case CONOPS_OPMODES_MODE_SAFE_ENTRY:
                case CONOPS_OPMODES_MODE_SAFE_CONTROL:
                case CONOPS_OPMODES_MODE_SAFE_NO_CONTROL:
                    {
                        conops_preset_id = 0U;

                        break;
                    }

                case CONOPS_OPMODES_MODE_IDLE:
                    {
                        conops_preset_id = 1U;

                        break;
                    }

                case CONOPS_OPMODES_MODE_MISSION:
                    {
                        conops_preset_id = 2U;

                        break;
                    }

                default:
                    {
                        break;
                    }
            }
        }
    }

    return conops_preset_id;
}

void telemetry_cfg_restore_active_preset(const TELEMETRY_TelemetryInstance_t instance_id)
{
    BREAK_ASSERT(instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT);

    if (instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT)
    {
        sim_mode_ctx[instance_id].sim_mode_active = false;
        sim_mode_ctx[instance_id].req_preset_id   = 0U;
    }
}

bool telemetry_cfg_set_active_preset(const TELEMETRY_TelemetryInstance_t instance_id, uint8_t preset_id)
{
    BREAK_ASSERT(instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT);

    bool valid_cfg = false;

    if ((instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT) && (preset_id < TELEMETRY_PRESETS_COUNT))
    {
        sim_mode_ctx[instance_id].req_preset_id   = preset_id;
        sim_mode_ctx[instance_id].sim_mode_active = true;

        valid_cfg = true;
    }

    return valid_cfg;
}

void telemetry_cfg_get_tlm_config(const TELEMETRY_TelemetryInstance_t instance_id, telemetry_cfg_t *const p_tlm_cfg)
{
    BREAK_ASSERT(instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT);
    BREAK_ASSERT(NULL != p_tlm_cfg);

    if ((instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT) && (NULL != p_tlm_cfg))
    {
        Nvm_GetBlockById(nvm_cfg_map[instance_id].bl_id_gen_cfg, p_tlm_cfg);
    }
}

void telemetry_cfg_get_preset_config(const TELEMETRY_TelemetryInstance_t instance_id, telemetry_preset_cfg_t *const p_tlm_preset_cfg)
{
    BREAK_ASSERT(instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT);
    BREAK_ASSERT(NULL != p_tlm_preset_cfg);

    if ((instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT) && (NULL != p_tlm_preset_cfg))
    {
        Nvm_GetBlockById(nvm_cfg_map[instance_id].bl_id_preset_cfg, p_tlm_preset_cfg);
    }
}

void telemetry_cfg_get_file_config(const TELEMETRY_TelemetryInstance_t instance_id, telemetry_file_cfg_t *const p_tlm_file_cfg)
{
    BREAK_ASSERT(instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT);
    BREAK_ASSERT(NULL != p_tlm_file_cfg);

    if ((instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT) && (NULL != p_tlm_file_cfg))
    {
        Nvm_GetBlockById(nvm_cfg_map[instance_id].bl_id_file_cfg, p_tlm_file_cfg);
    }
}

void telemetry_cfg_get_persistent_data(const TELEMETRY_TelemetryInstance_t instance_id, telemetry_persistent_data_t *const p_tlm_pd)
{
    BREAK_ASSERT(instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT);
    BREAK_ASSERT(NULL != p_tlm_pd);

    if ((instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT) && (NULL != p_tlm_pd))
    {
        Nvm_GetBlockById(nvm_cfg_map[instance_id].bl_id_pd, p_tlm_pd);
    }
}

void telemetry_cfg_set_persistent_data(const TELEMETRY_TelemetryInstance_t instance_id, telemetry_persistent_data_t *const p_tlm_pd)
{
    BREAK_ASSERT(instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT);
    BREAK_ASSERT(NULL != p_tlm_pd);

    if ((instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT) && (NULL != p_tlm_pd))
    {
        Nvm_SetBlockById(nvm_cfg_map[instance_id].bl_id_pd, p_tlm_pd, NVMSETBLOCK_STORE_IMMEDIATELY);
    }
}

void telemetry_cfg_set_tlm_config(const TELEMETRY_TelemetryInstance_t instance_id, telemetry_cfg_t *const p_tlm_cfg)
{
    BREAK_ASSERT(instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT);
    BREAK_ASSERT(NULL != p_tlm_cfg);

    if ((instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT) && (NULL != p_tlm_cfg))
    {
        Nvm_SetBlockById(nvm_cfg_map[instance_id].bl_id_gen_cfg, p_tlm_cfg, NVMSETBLOCK_STORE_IMMEDIATELY);
    }
}

bool telemetry_cfg_set_preset_config(const TELEMETRY_TelemetryInstance_t instance_id, telemetry_preset_cfg_t *const p_tlm_preset_cfg)
{
    BREAK_ASSERT(instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT);
    BREAK_ASSERT(NULL != p_tlm_preset_cfg);

    bool config_set_ok = true;

    if ((instance_id >= TELEMETRY_TELEMETRYINSTANCE_MAX_CNT) || (NULL == p_tlm_preset_cfg))
    {
        return false;
    }

    for (uint8_t preset_idx = 0; preset_idx < TELEMETRY_PRESETS_COUNT; preset_idx++)
    {
        for (uint16_t slot_idx = 0; slot_idx < TELEMETRY_MAX_CONFIGURABLE_ENTRIES; slot_idx++)
        {
            dc_did_id dc_item_idx = dc_get_index_by_data_id(p_tlm_preset_cfg->tlm_slots_setting[preset_idx][slot_idx].u16Data_id);

            if (DC_DID_MAX == dc_item_idx)
            {
                // invalid data id specified, hence rewrite the invalid slot
                p_tlm_preset_cfg->tlm_slots_setting[preset_idx][slot_idx].u16Data_id       = INVALID_TLM_SLOT_ASSIGNMENT;
                p_tlm_preset_cfg->tlm_slots_setting[preset_idx][slot_idx].bActive          = false;
                p_tlm_preset_cfg->tlm_slots_setting[preset_idx][slot_idx].u16Acq_period_ms = 0xFFFF;

                config_set_ok = false;
            }

            // Minimum ACQ period safeguard protection. Prevent any period lower than MIN_ACQ_PERIOD_MS to enter the NVM configuration.
            if (MIN_ACQ_PERIOD_MS > p_tlm_preset_cfg->tlm_slots_setting[preset_idx][slot_idx].u16Acq_period_ms)
            {
                p_tlm_preset_cfg->tlm_slots_setting[preset_idx][slot_idx].u16Acq_period_ms = MIN_ACQ_PERIOD_MS;

                config_set_ok = false;
            }
        }
    }

    Nvm_SetBlockById(nvm_cfg_map[instance_id].bl_id_preset_cfg, p_tlm_preset_cfg, NVMSETBLOCK_STORE_IMMEDIATELY);

    return config_set_ok;
}

void telemetry_cfg_set_file_config(const TELEMETRY_TelemetryInstance_t instance_id, telemetry_file_cfg_t *const p_tlm_file_cfg)
{
    BREAK_ASSERT(instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT);
    BREAK_ASSERT(NULL != p_tlm_file_cfg);

    if ((instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT) && (NULL != p_tlm_file_cfg))
    {
        Nvm_SetBlockById(nvm_cfg_map[instance_id].bl_id_file_cfg, p_tlm_file_cfg, NVMSETBLOCK_STORE_IMMEDIATELY);
    }
}

tlm_runtime_context_t *telemetry_cfg_get_ctx(const TELEMETRY_TelemetryInstance_t instance_id)
{
    return telemetry_cfg_get_ctx_u16((uint16_t)instance_id);
}

tlm_runtime_context_t *telemetry_cfg_get_ctx_u16(const uint16_t instance_id)
{
    BREAK_ASSERT(instance_id < (uint16_t)TELEMETRY_TELEMETRYINSTANCE_MAX_CNT);

    return (instance_id < (uint16_t)TELEMETRY_TELEMETRYINSTANCE_MAX_CNT) ? &tlm_rt_context[instance_id] : (tlm_runtime_context_t *)NULL;
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
