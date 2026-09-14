/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup Services
 * @{
 *
 * @defgroup comm_gw
 * @{
 *
 * @file comm_gw_if.c
 * @brief COMM GW interface references management implementation
 *
 * @}
 * @}
 */

#include <stddef.h>
#include "comm_gw_cmn.h"
#include "comm_gw_if_cfg.h"
#include "assertions.h"

/** @breif Debug string used to replace any invalid ID passed to one of the comm_gw_cfg_get_*_str() functions */
static const char *str_unknown = "UNKNOWN";

/** @brief String representation of the COMM GW user IDs for debug purposes */
static const char *const str_comm_gw_users[COMM_GW_USER_ID_MAX] = {
    [COMM_GW_USER_ID_UPY]           = "upy",
    [COMM_GW_USER_ID_OBC_SCHEDULER] = "sched",
    [COMM_GW_USER_ID_CP_HANDLER]    = "cp",
    [COMM_GW_USER_ID_CSP_FP_SRV]    = "csp_fp_srv",
    [COMM_GW_USER_ID_XBAND_FE]      = "xband_fe"
};

/** @brief String representation of the COMM GW interface IDs for debug purposes */
static const char *const str_comm_gw_ifs[COMM_GW_IF_ID_MAX] = {
    [COMM_GW_IF_ID_FP] = "fp",
    [COMM_GW_IF_ID_CP] = "cp",
    [COMM_GW_IF_ID_CSP] = "csp"
};

/** @brief String representation of the COMM GW error IDs for debug purposes */
static const char *const str_comm_errors[COMM_GW_RES_MAX] = {
    [COMM_GW_RES_OK]           = "OK",
    [COMM_GW_RES_OK_PARTIAL]   = "OK PARTIAL",
    [COMM_GW_RES_ERR]          = "ERR",
    [COMM_GW_RES_INVALID_ARGS] = "INV ARGS",
    [COMM_GW_RES_SEND_ERR]     = "SEND ERR",
    [COMM_GW_RES_SND_TIMEOUT]  = "SEND TOUT",
    [COMM_GW_RES_RCV_TIMEOUT]  = "RCV TOUT"
};

static const comm_gw_if_t *comm_gw_interfaces[COMM_GW_IF_ID_MAX] = {
#if defined(COMM_RS485_MAC_LAYER_ENABLED)
    [COMM_GW_IF_ID_FP] = &comm_gw_fp_if_instance,
    [COMM_GW_IF_ID_CP] = &comm_gw_cp_if_instance,
#else
    [COMM_GW_IF_ID_FP] = NULL,
    [COMM_GW_IF_ID_CP] = NULL,
#endif
#if defined(CSP_SUPPORT_ENABLED)
    [COMM_GW_IF_ID_CSP] = &comm_gw_csp_if_instance
#else
    [COMM_GW_IF_ID_CSP] = NULL
#endif
};

const comm_gw_if_t *comm_gw_cfg_get_intf_ref(const comm_gw_if_id_t if_id)
{
    BREAK_ASSERT(if_id < COMM_GW_IF_ID_MAX);

    if (if_id < (uint8_t)COMM_GW_IF_ID_MAX)
    {
        return comm_gw_interfaces[if_id];
    }
    else
    {
        return NULL;
    }
}

const char *comm_gw_cfg_get_user_str(const comm_gw_user_id_t user_id)
{
    return (user_id < COMM_GW_USER_ID_MAX) ? str_comm_gw_users[(uint8_t)user_id] : str_unknown;
}

const char *comm_gw_cfg_get_gw_str(const comm_gw_if_id_t gw_id)
{
    return (gw_id < COMM_GW_IF_ID_MAX) ? str_comm_gw_ifs[(uint8_t)gw_id] : str_unknown;
}

const char *comm_gw_cfg_get_err_str(const comm_gw_comm_res_t err_id)
{
    return (err_id < COMM_GW_RES_MAX) ? str_comm_errors[(uint8_t)err_id] : str_unknown;
}
