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
 * @file comm_gw_csp.c
 * @brief CSP Communication Gateway Implementation
 *
 * This is a COMM GW extension which provides direct execution of raw CSP commands.
 *
 * @}
 * @}
 */

#include "comm_gw_if_cfg.h"
#include "comm_gw_cmn.h"
#include "comm_gw_csp.h"
#include "cmsis_os2.h"
#include <string.h>
#include "assertions.h"
#include "trace.h"

#include "csp_access.h"

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

/** @brief Initialize the COMM GW CSP interface */
static void comm_gw_csp_init(void);

/** @breif Blocking send of a CSP frame with the specified communication parameters
 *
 *  This is a helper function called by comm_gw_csp_send() to avoid some SonarQube warnings.
 *
 *  @param[in/out] p_send_ctx a reference to the communication and buffer parameters for the send operations
 *
 *  @returns operation status
 */
static comm_gw_comm_res_t comm_gw_csp_send_internal(comm_gw_send_ctx_t *const p_send_ctx);

/** @brief Send a CSP frame with the specified communication parameters
 *
 *  @param[in] user_id ID of the user requesting the operation
 *  @param[in/out] p_send_ctx a reference to the communication and buffer parameters for the send operations
 *  @param[in] p_comm_finished_cb function pointer to use as notification mechanism when the send operations and corresponding response are received
 */
static void comm_gw_csp_send(const uint8_t user_id, comm_gw_send_ctx_t *const p_send_ctx, const comm_gw_comm_finished_func_t p_comm_finished_cb);

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/
/** @brief COMM GW interface instance definition */
const comm_gw_if_t comm_gw_csp_if_instance = {
    .p_comm_gw_if_init = &comm_gw_csp_init,
    .p_comm_gw_if_send = &comm_gw_csp_send
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
static void comm_gw_csp_init(void)
{
    // This function doesn't do anything useful right now but is part of the standard comm_gw_if interface
    // and must be preserved.
    return;
}

static comm_gw_comm_res_t comm_gw_csp_send_internal(comm_gw_send_ctx_t *const p_send_ctx)
{
    BREAK_ASSERT(NULL != p_send_ctx->p_resp_data_size);
    BREAK_ASSERT((NULL != p_send_ctx) &&
                 (NULL != p_send_ctx->p_req_data) &&
                 (0 < p_send_ctx->req_data_size));

    const comm_gw_csp_comm_params_t *p_comm_params = (const comm_gw_csp_comm_params_t *)p_send_ctx->p_comm_params;
    comm_gw_comm_res_t               comm_gw_res   = COMM_GW_RES_ERR;

    *(p_send_ctx->p_resp_data_size) = 0UL;

    csp_conn_t *conn = csp_connect(p_comm_params->prio, p_comm_params->target_node_addr, p_comm_params->port, 0, p_comm_params->opts);

    if (conn == NULL)
    {
        return COMM_GW_RES_SEND_ERR;
    }

    csp_packet_t *p_req_packet = csp_buffer_get(p_send_ctx->req_data_size);

    if (NULL == p_req_packet)
    {
        (void)csp_close(conn);
        return COMM_GW_RES_SEND_ERR;
    }

    if ((p_send_ctx->req_data_size > 0) && (p_send_ctx->p_req_data != NULL))
    {
        (void)memcpy(p_req_packet->data, p_send_ctx->p_req_data, p_send_ctx->req_data_size);
    }

    // CSP data length is limited to uint16_t
    BREAK_ASSERT(p_send_ctx->req_data_size <= 0xFFFF);

    p_req_packet->length = (uint16_t)p_send_ctx->req_data_size;

    if (0 == csp_send(conn, p_req_packet, p_send_ctx->resp_timeout))
    {
        csp_close(conn);
        return COMM_GW_RES_SEND_ERR;
    }

    if ((NULL == p_send_ctx->p_resp_data) || (0UL == p_send_ctx->resp_data_max_size))
    {
        (void)csp_close(conn);
        return COMM_GW_RES_OK;
    }

    ES_TRACE_DEBUG("[csp] sent frame to node '0x%02x' with prio %ld (%ld byte(s) / tout: %ld ms)", p_comm_params->target_node_addr, (uint32_t)p_comm_params->prio, p_send_ctx->req_data_size, p_send_ctx->resp_timeout);

    csp_packet_t *p_resp_packet = csp_read(conn, p_send_ctx->resp_timeout);

    if (NULL == p_resp_packet)
    {
        (void)csp_close(conn);
        return COMM_GW_RES_RCV_TIMEOUT;
    }

    if (p_send_ctx->resp_data_max_size >= p_resp_packet->length)
    {
        (void)memcpy(p_send_ctx->p_resp_data, p_resp_packet->data, p_resp_packet->length);
    }
    else
    {
        (void)memcpy(p_send_ctx->p_resp_data, p_resp_packet->data, p_send_ctx->resp_data_max_size);
    }

    comm_gw_res = COMM_GW_RES_OK;

    // full message size always returned (regardless of partial copy or not)
    *(p_send_ctx->p_resp_data_size) = (uint32_t)p_resp_packet->length;

    // free received packet
    csp_buffer_free(p_resp_packet);
    (void)csp_close(conn);

    return comm_gw_res;
}

static void comm_gw_csp_send(const uint8_t user_id, comm_gw_send_ctx_t *const p_send_ctx, const comm_gw_comm_finished_func_t p_comm_finished_cb)
{
    BREAK_ASSERT((NULL != p_send_ctx) &&
                 (NULL != p_send_ctx->p_req_data) &&
                 (0 < p_send_ctx->req_data_size));

    comm_gw_comm_res_t op_res = COMM_GW_RES_ERR;

    op_res = comm_gw_csp_send_internal(p_send_ctx);

    if (NULL != p_comm_finished_cb)
    {
        (*p_comm_finished_cb)(user_id, op_res);
    }
}
