/*
 * Copyright (c) 2023 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup payload_ctrl
 * @{
 *
 * @file payload_ctrl_cfg.c
 * @brief Link-time configuration of the payload controller service.
 * @}
 */

#include "payload_ctrl_cfg.h"

#include "es_cdef.h"
#include "payload_ctrl.h"
#include "sxband_pl_ctrl.h"
#if defined(SDR_ENABLED)
#include "sdr_pl_ctrl.h"
#endif
#if defined(XBAND_FE_ENABLED)
#include "xband_fe_comm.h"
#endif
#include "conops.h"

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

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/

static void payload_sxband_state_notify(const pl_instance_id_t instance_id, pl_state_t to_state);

#if defined(SDR_ENABLED)
static void payload_sdr_state_notify(const pl_instance_id_t instance_id, pl_state_t to_state);
#endif

#if defined(XBAND_FE_ENABLED)
static void payload_xband_fe_state_notify(const pl_instance_id_t instance_id, pl_state_t to_state);
#endif

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/

/** @brief Configuration data for each payload */
static const payload_immutable_cfg_t payload_ctrl_pld_configs[PAYLOAD_COUNT] = {
  // clang-format off
    // PAYLOAD_SX_BAND
    {
        .p_pl_interface   = &sxband_pl_ctrl_if,
        .internal_inst_id = 0U,
        .init_config      = {.p_config_data = NULL, .size = 0U },
        .p_pl_notif_cbk = &payload_sxband_state_notify
    },

    // PAYLOAD_SDR
#if defined(SDR_ENABLED)
    {
        .p_pl_interface = &sdr_pl_ctrl_if,
        .internal_inst_id = 0U,
        .init_config = {.p_config_data = NULL, .size = 0U},
        .p_pl_notif_cbk = &payload_sdr_state_notify
    },
#endif

    // PAYLOAD_XBAND_FE
#if defined(XBAND_FE_ENABLED)
    {
        .p_pl_interface   = &xband_fe_pl_ctrl_if,
        .internal_inst_id = 0U,
        .init_config      = { .p_config_data = NULL, .size = 0U },
        .p_pl_notif_cbk   = &payload_xband_fe_state_notify
    }
#endif
  // clang-format on
};

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

const payload_immutable_cfg_t *const payload_ctrl_cfg_get(const payload_ctrl_payload_t payload_id)
{
    const payload_immutable_cfg_t *p_ret = NULL;

    if (payload_id < PAYLOAD_COUNT)
    {
        p_ret = &payload_ctrl_pld_configs[payload_id];
    }

    return p_ret;
}

bool payload_ctrl_cfg_is_payload_mode(void)
{
    return conops_is_payload_allowed();
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

/**
 * @brief See @ref p_pl_event_notify_t.
 */
static void payload_sxband_state_notify(const pl_instance_id_t instance_id, pl_state_t to_state)
{
    (void)instance_id;
    payload_ctrl_event_notify(PAYLOAD_SX_BAND, to_state);
}

#if defined(SDR_ENABLED)
/**
 * @brief See @ref p_pl_event_notify_t.
 */
static void payload_sdr_state_notify(const pl_instance_id_t instance_id, pl_state_t to_state)
{
    (void)instance_id;
    payload_ctrl_event_notify(PAYLOAD_SDR, to_state);
}
#endif

#if defined(XBAND_FE_ENABLED)
/**
 * @brief See @ref p_pl_init_t.
 */
static void payload_xband_fe_state_notify(const pl_instance_id_t instance_id, pl_state_t to_state)
{
    (void)instance_id;
    payload_ctrl_event_notify(PAYLOAD_XBAND_FE, to_state);
}
#endif
