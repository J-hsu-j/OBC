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
 * @file comm_gw_fp.c
 * @brief ESPS FP Communication Gateway Implementation
 *
 * This is a COMM GW extension which provides:
 * - execution of locally implemented FP commands (a.k.a. FP injection)
 * - sending of FP commands to remote nodes on the ESPS bus and capturing the response.
 *
 * @}
 * @}
 */

#include "comm_gw_if_cfg.h"
#include "comm_gw_cmn.h"
#include "comm_gw_fp.h"
#include "cmsis_os2.h"
#include "esps_drv_config.h"
#include <string.h>
#include "assertions.h"
#include "trace.h"

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

/** @brief FP-specific per user context definition
 *
 *  Every FP GW request is impersonated by a virtual node which has a predefined reserved address (in the range of bus addresses which are not reserved
 *  by other modules). This is necessary to properly route responses to the individual FP GW users. For that purpose, at system level, each user is
 *  assigned a specific virtual node address by this service and the service dedicates a slot for each of its clients.
 *  From FP GW perspective a user is a dedicated RTOS thread. This enables the FP GW to block the caller
 *  automatically when sending a request and unblock it when the corresponding response is received or the communication times out.
 * */
typedef struct
{
    uint8_t                      user_id;            /**< this is a convenience field to enable easy matching of user id by virtual_node_addr or sent_msg_id fields */
    uint8_t                      mac_if_id;          /**< MAC interface to which the request was sent */
    uint8_t                      virtual_node_addr;  /**< calculated physical node address for the user which will be used for bus communication */
    uint32_t                     sent_msg_id;        /**< ID of the originating FP message on the bus */
    ESSATMAC_ErrCodes            last_send_err;      /**< Send error code for the last requested transmission */
    uint8_t                     *p_resp_buf;         /**< pointer to the buffer which receives the response data */
    uint32_t                    *p_resp_buf_size;    /**< actual size (in bytes) of the response frame */
    uint32_t                     resp_buf_max_size;  /**< maximum size of the buffer pointed to by p_resp_buf */
    comm_gw_comm_finished_func_t p_comm_finished_cb; /**< function to call after communication is finalized */
} comm_gw_fp_user_t;

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/** @brief Search the list of users and return a pointer to the one whose virtual address matches the specified one.
 *
 *  @param[in] vnode_addr virtual address to match to an FP GW user
 *  @return pointer to a user context corresponding to @ref vnode_addr
 */
static comm_gw_fp_user_t *get_user_data_by_vnode_addr(const uint8_t vnode_addr);

/** @brief Search the list of users and return a pointer to the one whose transmit message ID matches the specified one.
 *
 *  @param[in] tx_msg_id transmit message ID returned by the ESSA stack upon queuing a message for transmission
 *  @return pointer to a user context corresponding to @ref vnode_addr
 */
static comm_gw_fp_user_t *get_user_data_by_tx_msg_id(const uint32_t tx_msg_id);

/** @brief This function is called when an FP frame is sent over the bus or if an error occurred during the send process.
 *
 *  @param[in] msg_id identifier of the message which was physically transmitted on the bus
 *  @param[in] ret_code diagnostic code which is used to check if the message was sent or transmission failed for some reason
 */
static void comm_gw_fp_frame_send_confirm_cbk(uint32_t msg_id, ESSATMAC_ErrCodes ret_code);

/** @brief Initialize the COMM GW FP interface */
static void comm_gw_fp_init(void);

/** @brief Send an FP frame with the specified communication parameters
 *
 *  @param[in] user_id ID of the user requesting the operation
 *  @param[in/out] p_send_ctx a reference to the communication and buffer parameters for the send operations
 *  @param[in] p_comm_finished_cb function pointer to use as notification mechanism when the send operations and corresponding response are received
 */
static void comm_gw_fp_send(const uint8_t user_id, comm_gw_send_ctx_t *const p_send_ctx, const comm_gw_comm_finished_func_t p_comm_finished_cb);

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
/** @brief Allocated user slots used for FP GW communication */
static comm_gw_fp_user_t comm_gw_fp_users[COMM_GW_USER_ID_MAX];

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/
/** @brief COMM GW interface instance definition */
const comm_gw_if_t comm_gw_fp_if_instance = {
    .p_comm_gw_if_init = &comm_gw_fp_init,
    .p_comm_gw_if_send = &comm_gw_fp_send
};

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
ESSATMAC_ErrCodes comm_gw_fp_enq_message(const ESSATMAC_Context *p_mac_ctx, const uint8_t *p_msg_data, uint8_t msg_data_size)
{
    ESSATMAC_ErrCodes result = ESSATMAC_EC_ERROR;

    if ((p_mac_ctx != NULL) && (p_msg_data != NULL) && (msg_data_size > 0U))
    {
        comm_gw_comm_res_t comm_gw_res = COMM_GW_RES_INVALID_ARGS;
        comm_gw_fp_user_t *p_user      = get_user_data_by_vnode_addr(p_mac_ctx->nTargetAddr);

        if (((COMM_GW_LOOPBACK_REQ_NETTYPE == p_mac_ctx->netType) ||
             (COMM_GW_EXT_RESP_NETTYPE == p_mac_ctx->netType)) &&
            (p_user->mac_if_id == p_mac_ctx->nInterfaceNumber) &&
            (NULL != p_user) &&
            (ES_SAT_MAC_PROTOCOL_ID_FP_LAYER == p_mac_ctx->nPayloadProtocol) &&
            (NULL != p_user->p_resp_buf))
        {
            if (p_user->resp_buf_max_size >= msg_data_size)
            {
                (void)memcpy(p_user->p_resp_buf, p_msg_data, msg_data_size);
            }
            else
            {
                (void)memcpy(p_user->p_resp_buf, p_msg_data, p_user->resp_buf_max_size);
            }

            if (NULL != p_user->p_resp_buf_size)
            {
                // the full message size is always returned (regardless of whether we had a
                // partial copy); this allows the user to know how many bytes were not copied
                // (if that information may be useful, e.g. for tracing purposes, etc.)
                *(p_user->p_resp_buf_size) = (uint32_t)msg_data_size;
            }

            comm_gw_res = COMM_GW_RES_OK;

            result = ESSATMAC_EC_OK;
        }
        else
        {
            result = ESSATMAC_EC_INVALID_PARAMS;
        }

        if ((NULL != p_user) && (NULL != p_user->p_comm_finished_cb))
        {
            (*p_user->p_comm_finished_cb)(p_user->user_id, comm_gw_res);
        }
    }

    return result;
}

bool comm_gw_fp_is_valid_vnode_addr(const uint8_t vnode_addr)
{
    return (NULL != get_user_data_by_vnode_addr(vnode_addr));
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
static void comm_gw_fp_init(void)
{
    for (uint8_t idx = 0; idx < CDEF_ELEMENT_COUNT(comm_gw_fp_users); idx++)
    {
        comm_gw_fp_users[idx].mac_if_id          = ESSASNI_SYS_PRI;
        comm_gw_fp_users[idx].p_comm_finished_cb = NULL;
        comm_gw_fp_users[idx].p_resp_buf         = NULL;
        comm_gw_fp_users[idx].p_resp_buf_size    = NULL;
        comm_gw_fp_users[idx].resp_buf_max_size  = 0;
        comm_gw_fp_users[idx].virtual_node_addr  = COMM_GW_VIRTUAL_NODE_ADDRESS_BASE + idx;
        BREAK_ASSERT(comm_gw_fp_users[idx].virtual_node_addr < 0xFF);
        comm_gw_fp_users[idx].last_send_err = ESSATMAC_EC_ERROR;
        comm_gw_fp_users[idx].sent_msg_id   = 0U;

        // this is only for convenience to avoid using a separate typedef to provide @ref comm_gw_fp_user_t and user_id
        // information when using one of the search functions (i.e. get_user_data_by_*)
        comm_gw_fp_users[idx].user_id = idx;
    }
}

static void comm_gw_fp_send(const uint8_t user_id, comm_gw_send_ctx_t *const p_send_ctx, const comm_gw_comm_finished_func_t p_comm_finished_cb)
{
    ESSATMAC_Context mac_ctx;

    BREAK_ASSERT((NULL != p_send_ctx) &&
                 (NULL != p_send_ctx->p_req_data) &&
                 (NULL != p_send_ctx->p_comm_params) &&
                 (0 < p_send_ctx->req_data_size) &&
                 (user_id < CDEF_ELEMENT_COUNT(comm_gw_fp_users)));

    const comm_gw_fp_comm_params_t *p_comm_params = (const comm_gw_fp_comm_params_t *)p_send_ctx->p_comm_params;

    if (p_comm_params->mac_if_id >= eMAC_Interface_Count)
    {
        if (NULL != p_comm_finished_cb)
        {
            (*p_comm_finished_cb)(user_id, COMM_GW_RES_INVALID_ARGS);
        }

        return;
    }

    comm_gw_fp_user_t *p_user = &comm_gw_fp_users[user_id];

    uint8_t local_node_addr = MacCfg_u8GetMacAddress(p_comm_params->mac_if_id);
    bool    use_loopback    = (p_comm_params->target_node_addr == local_node_addr);

    (void)memset((void *)&mac_ctx, (uint8_t)0, sizeof(ESSATMAC_Context));

    // setup node response context for later use
    p_user->mac_if_id          = p_comm_params->mac_if_id;
    p_user->p_resp_buf         = p_send_ctx->p_resp_data;
    p_user->resp_buf_max_size  = p_send_ctx->resp_data_max_size;
    p_user->p_resp_buf_size    = p_send_ctx->p_resp_data_size;
    p_user->p_comm_finished_cb = p_comm_finished_cb;

    mac_ctx.nInterfaceNumber = p_comm_params->mac_if_id;
    mac_ctx.nPayloadProtocol = ES_SAT_MAC_PROTOCOL_ID_FP_LAYER;
    // for any request we will use as source address a special virtual node address for the uPy environment so that it easier to perform
    // the response dispatch specifically to the COMM GW handler
    mac_ctx.nSourceAddr = p_user->virtual_node_addr;
    mac_ctx.nTargetAddr = p_comm_params->target_node_addr;
    // for external node addresses, we have to use a different net type so that our requests get send to the ESPS bus
    // using the standard ESPS driver
    mac_ctx.netType = (true == use_loopback) ? COMM_GW_LOOPBACK_REQ_NETTYPE : COMM_GW_EXT_REQ_NETTYPE;

    if (true == use_loopback)
    {
        ES_TRACE_DEBUG("injected loopback frame of size %ld byte(s) (tout: %ld ms)", p_send_ctx->req_data_size, p_send_ctx->resp_timeout);
        // inject message to ESSA Stack for local FP dispatch...
        ESSA_Stack_DataDispatch(&mac_ctx, p_send_ctx->p_req_data, (uint8_t)p_send_ctx->req_data_size);
    }
    else
    {
        p_user->sent_msg_id   = 0;
        p_user->last_send_err = ESSATMAC_EC_ERROR;

        // the message is to an external node, hence send it over to the bus
        (void)ESSA_Stack_SendFrameEx_Bridge(mac_ctx.nInterfaceNumber,
                                            mac_ctx.netType,
                                            mac_ctx.nSourceAddr,
                                            mac_ctx.nTargetAddr,
                                            mac_ctx.nPayloadProtocol,
                                            p_send_ctx->p_req_data,
                                            (uint8_t)p_send_ctx->req_data_size,
                                            p_comm_params->msg_prio,
                                            &comm_gw_fp_frame_send_confirm_cbk,
                                            &p_user->sent_msg_id);

        ES_TRACE_DEBUG("[mac if '%d'] sent frame '%ld' to ext node '0x%02x' with prio %ld (%ld byte(s) / tout: %ld ms)", p_comm_params->mac_if_id, p_user->sent_msg_id, p_comm_params->target_node_addr, (uint32_t)p_comm_params->msg_prio, p_send_ctx->req_data_size, p_send_ctx->resp_timeout);
    }
}

static comm_gw_fp_user_t *get_user_data_by_vnode_addr(const uint8_t vnode_addr)
{
    for (uint8_t idx = 0; idx < CDEF_ELEMENT_COUNT(comm_gw_fp_users); idx++)
    {
        if (comm_gw_fp_users[idx].virtual_node_addr == vnode_addr)
        {
            return &comm_gw_fp_users[idx];
        }
    }

    return (comm_gw_fp_user_t *)NULL;
}

static comm_gw_fp_user_t *get_user_data_by_tx_msg_id(const uint32_t tx_msg_id)
{
    for (uint8_t idx = 0; idx < CDEF_ELEMENT_COUNT(comm_gw_fp_users); idx++)
    {
        if (comm_gw_fp_users[idx].sent_msg_id == tx_msg_id)
        {
            return &comm_gw_fp_users[idx];
        }
    }

    return (comm_gw_fp_user_t *)NULL;
}

static void comm_gw_fp_frame_send_confirm_cbk(uint32_t msg_id, ESSATMAC_ErrCodes ret_code)
{
    comm_gw_fp_user_t *p_user = get_user_data_by_tx_msg_id(msg_id);

    if (NULL != p_user)
    {
        p_user->last_send_err = ret_code;

        if (ESSATMAC_EC_OK != ret_code)
        {
            ES_TRACE_ERROR("msg id '%ld' send failed with code '%ld'", msg_id, (uint32_t)ret_code);
        }
    }
    else
    {
        ES_TRACE_ERROR("expecting frame with ID '%ld' but received confirmation for '%ld'", p_user->sent_msg_id, msg_id);
    }
}
