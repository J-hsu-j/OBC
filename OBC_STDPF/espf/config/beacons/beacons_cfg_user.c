/*
 * Copyright (c) 2020-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup service_beacons
 * @{
 *
 * @file beacons_cfg_user.c
 *
 * @brief Beacon service user configuration main implementation
 *
 * This file describes the set of beacons that need to be transmitted by the beacon service.
 *
 * @}
 */

#include "beacon_cfg_types.h"
#include "nvm_appcfg/inc/nvm_app_types.h"
#include "datacache.h"
#include "conops.h"
#include "fp/conops/v2.0/conops_server/FP_conopsProtocolTypes.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

/** @brief Preset ID of the data to be set in beacons while in SAFE ConOps mode */
#define CONOPS_PRESET_ID_SAFE (0U)

/** @brief Preset ID of the data to be set in beacons while in IDLE ConOps mode */
#define CONOPS_PRESET_ID_IDLE (1U)

/** @brief Preset ID of the data to be set in beacons while in MISSION ConOps mode */
#define CONOPS_PRESET_ID_MISSION (2U)

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

typedef struct
{
    safe_bool_t sim_mode_active; /**< indicates whether sim mode is activated */
    uint8_t     req_preset_id;   /**< requested preset id in simulation mode */
} sim_mode_t;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/

static sim_mode_t sim_mode_ctx = {
    .sim_mode_active = SAFE_FALSE,
    .req_preset_id   = 0U
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

uint8_t beacons_get_op_mode(void)
{
    uint8_t state_id = 0xFF;

    conops_get_hsm_active_state(&state_id);

    return state_id;
}

uint8_t beacons_cfg_get_active_preset(void)
{
    uint8_t conops_preset_id = 0U;

    if (IS_TRUE(sim_mode_ctx.sim_mode_active))
    {
        if (sim_mode_ctx.req_preset_id >= BEACON_PRESETS_COUNT)
        {
            sim_mode_ctx.req_preset_id = 0U;
        }

        conops_preset_id = sim_mode_ctx.req_preset_id;
    }
    else
    {
        uint8_t state_id = 0U;

        conops_get_hsm_active_state(&state_id);

        switch (state_id)
        {
            case CONOPS_OPMODES_MODE_SAFE:
                {
                    conops_preset_id = CONOPS_PRESET_ID_SAFE;

                    break;
                }

            case CONOPS_OPMODES_MODE_IDLE:
                {
                    conops_preset_id = CONOPS_PRESET_ID_IDLE;

                    break;
                }

            case CONOPS_OPMODES_MODE_MISSION:
                {
                    conops_preset_id = CONOPS_PRESET_ID_MISSION;

                    break;
                }

            default:
                {
                    break;
                }
        }
    }

    return conops_preset_id;
}

void beacons_cfg_restore_active_preset(void)
{
    SET_FALSE(sim_mode_ctx.sim_mode_active);
    sim_mode_ctx.req_preset_id = 0U;
}

bool beacons_cfg_set_active_preset(uint8_t preset_id)
{
    bool valid_cfg = false;

    if (preset_id < BEACON_PRESETS_COUNT)
    {
        sim_mode_ctx.req_preset_id = preset_id;
        SET_TRUE(sim_mode_ctx.sim_mode_active);

        valid_cfg = true;
    }

    return valid_cfg;
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
