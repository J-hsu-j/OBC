/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup sdr
 * @{
 *
 * @file sdr_pl_ctrl.c
 *
 * @brief SDR payload interface implementation
 * @}
 *
 */

#include "es_cdef.h"
#include "trace.h"
#include "sdr_pl_ctrl.h"
#include "eps_ctrl.h"
#include "eps_ctrl_cfg.h"
#include "sdr_sm_user.h"
#include "sdr_critical.h"
#include "sdr_cfg.h"

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
    pl_state_t          sdr_state;          /**< payload operating state of the SDR instance */
    p_pl_event_notify_t p_sdr_state_notify; /**< SDR state notification callback */
    eps_ctrl_channels_t sdr_power_channel;  /**< EPS channel used to control the SDR power */
} sdr_inst_t;                               /**< SDR instance structure */

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

static sdr_inst_t sdr_instance[SDR_INST_CNT] = {
    {
     .sdr_state          = PL_STATE_NOT_INIT,
     .p_sdr_state_notify = NULL,
     .sdr_power_channel  = POWER_OUT_SDR_EN,
     }
};

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
/** @brief See pl_control_if_t description for details. This is a standard operation for all payloads. */
static pl_op_status_t sdr_pl_ctrl_init(const pl_instance_id_t instance_id, const pl_config_t *const p_init_cfg, const p_pl_event_notify_t p_event_notify_cb);
/** @brief See pl_control_if_t description for details. This is a standard operation for all payloads. */
static pl_op_status_t sdr_pl_ctrl_deinit(const pl_instance_id_t instance_id);
/** @brief See pl_control_if_t description for details. This is a standard operation for all payloads. */
static pl_op_status_t sdr_pl_ctrl_start(const pl_instance_id_t instance_id, const pl_config_t *const p_start_cfg);
/** @brief See pl_control_if_t description for details. This is a standard operation for all payloads. */
static pl_op_status_t sdr_pl_ctrl_stop(const pl_instance_id_t instance_id, const pl_op_stop_mode_t stop_mode);
/** @brief See pl_control_if_t description for details. This is a standard operation for all payloads. */
static pl_state_t sdr_pl_ctrl_get_active_state(const pl_instance_id_t instance_id);
/** @brief See pl_control_if_t description for details. This is a standard operation for all payloads. */
static uint32_t sdr_pl_ctrl_get_last_error(const pl_instance_id_t instance_id);
/** @brief See pl_control_if_t description for details. This is a standard operation for all payloads. */
static void update_state_and_notify(const pl_instance_id_t instance_id, const pl_state_t new_state);

/** @brief Validates the instance of the SDR
 *  @param[in] instance_id SDR payload instance ID
 *  @return true - if instance is valid and can be used, false - otherwise
 *
 */
static bool is_valid_sdr_instance(const pl_instance_id_t instance_id);

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/
const pl_control_if_t sdr_pl_ctrl_if = {
    .init           = sdr_pl_ctrl_init,
    .deinit         = sdr_pl_ctrl_deinit,
    .start          = sdr_pl_ctrl_start,
    .stop           = sdr_pl_ctrl_stop,
    .get_state      = sdr_pl_ctrl_get_active_state,
    .get_last_error = sdr_pl_ctrl_get_last_error,
};

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
static inline bool is_valid_sdr_instance(const pl_instance_id_t instance_id)
{
    return (instance_id < SDR_INST_CNT);
}

static void update_state_and_notify(const pl_instance_id_t instance_id, const pl_state_t new_state)
{
    CRIT_ASSERT(true == is_valid_sdr_instance(instance_id));

    sdr_instance[instance_id].sdr_state = new_state;

    if (sdr_instance[instance_id].p_sdr_state_notify != NULL)
    {
        (*sdr_instance[instance_id].p_sdr_state_notify)(instance_id, sdr_instance[instance_id].sdr_state);
    }
}

static pl_op_status_t sdr_pl_ctrl_init(const pl_instance_id_t instance_id, const pl_config_t *const p_init_cfg, const p_pl_event_notify_t p_event_notify_cb)
{
    pl_op_status_t res = PL_OP_STATUS_REJECT;
    (void)p_init_cfg;

    if (true == is_valid_sdr_instance(instance_id))
    {
        // execute sdr initialization routines
        sdr_critical_init(); // init sdr mutex control module
        sdr_thread_init();   // init sdr thread
        sdr_tl_init();       // register sdr csp as transport layer

        if (true == sdr_trigger_hsm(eHSM_StdEvent_Reset))
        {
            sdr_instance[instance_id].p_sdr_state_notify = p_event_notify_cb;
            update_state_and_notify(instance_id, PL_STATE_STOPPED);
            res = PL_OP_STATUS_OK;
        }
    }
    else
    {
        BREAK_ASSERT(false);
    }

    return res;
}

static pl_op_status_t sdr_pl_ctrl_deinit(const pl_instance_id_t instance_id)
{
    pl_op_status_t res = PL_OP_STATUS_REJECT;

    if (true == is_valid_sdr_instance(instance_id))
    {
        if (true == sdr_trigger_hsm(eHSM_StdEvent_Reset))
        {
            update_state_and_notify(instance_id, PL_STATE_NOT_INIT);
            sdr_instance[instance_id].p_sdr_state_notify = NULL;
            res                                          = PL_OP_STATUS_OK;
        }
    }
    else
    {
        BREAK_ASSERT(false);
    }

    return res;
}

static pl_op_status_t sdr_pl_ctrl_start(const pl_instance_id_t instance_id, const pl_config_t *const p_start_cfg)
{
    (void)p_start_cfg; // payload configuration for SDR is not used
    pl_op_status_t res = PL_OP_STATUS_REJECT;

    if (true == is_valid_sdr_instance(instance_id))
    {
        (void)eps_ctrl_set_channel_output(sdr_instance[instance_id].sdr_power_channel, true);

        if (true == sdr_trigger_hsm(ev_sdr_sm_boot))
        {
            update_state_and_notify(instance_id, PL_STATE_STARTED);
            res = PL_OP_STATUS_OK;
        }
    }
    else
    {
        BREAK_ASSERT(false);
    }

    return res;
}

static pl_op_status_t sdr_pl_ctrl_stop(const pl_instance_id_t instance_id, const pl_op_stop_mode_t stop_mode)
{
    // stop the power regardless of the mode
    (void)stop_mode;
    pl_op_status_t res = PL_OP_STATUS_REJECT;

    if (true == is_valid_sdr_instance(instance_id))
    {
        (void)eps_ctrl_set_channel_output(sdr_instance[instance_id].sdr_power_channel, false);

        // sdr sm transition any_state->not_init (initial state)
        if (true == sdr_trigger_hsm(eHSM_StdEvent_Reset))
        {
            update_state_and_notify(instance_id, PL_STATE_STOPPED);
            res = PL_OP_STATUS_OK;
        }
    }
    else
    {
        BREAK_ASSERT(false);
    }

    return res;
}

static pl_state_t sdr_pl_ctrl_get_active_state(const pl_instance_id_t instance_id)
{
    pl_state_t res = PL_STATE_NOT_INIT;

    if (true == is_valid_sdr_instance(instance_id))
    {
        res = sdr_instance[instance_id].sdr_state;
    }
    else
    {
        BREAK_ASSERT(false);
    }

    return res;
}

static uint32_t sdr_pl_ctrl_get_last_error(const pl_instance_id_t instance_id)
{
    if (true == is_valid_sdr_instance(instance_id))
    {
        return PL_OP_STATUS_OK;
    }
    else
    {
        return PL_OP_STATUS_REJECT;
    }
}
