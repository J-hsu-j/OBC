/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#include "es_cdef.h"
#include <assert.h>
#include <stdbool.h>
#include "fp_csp_binder.h"
#include "csp_service.h"
#include "config/fp_csp_binder/fp_csp_binder_cfg.h"
#include "csp_access.h"
#include "config/csp/inc/csp_service_cfg.h"
#include "trace.h"
#include "comm_gw.h"
#include "taskmon.h"
#include "taskmon_stat.h"

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
/** @brief CSP server configuration structure */
typedef struct
{
    const char                *p_cfg_name;                                                       /**< user-friednly name of the server configuration represented by this structure (e.g. "UDP+CRC32"  */
    csp_conn_t                *p_active_conn;                                                    /**< a pointer to the currently active CSP connection accepted by the server */
    csp_socket_t              *p_server_socket;                                                  /**< a pointer to a server socket handle */
    const uint32_t             opts;                                                             /**< CSP listen sockets options */
    const uint8_t              listen_port;                                                      /**< CSP listen port */
    const size_t               backlog_cnt;                                                      /**< max number of connection instances to reserve */
    csp_thread_handle_t *const p_thread_hnd;                                                     /**< CSP listen thread handle */
    const char                *p_thread_name;                                                    /**< name of the server thread */
    csp_thread_func_t          p_thread_func;                                                    /**< pointer to the server thread function */
    uint32_t                   thread_stack_size;                                                /**< number of bytes to reserve for task stack */
    uint32_t                   thread_prio;                                                      /**< task priority */
    uint8_t                    fp_resp_buf[FS_MAX_CSP_BUF_SZ_BYTES] __attribute__((aligned(4))); /**< FP response buffer storage */
    task_mon_id_t              task_mon_id;                                                      /**< identifier used by task_mon to monitor task health */
} csp_server_cfg_t;

/** @brief FP CSP command header (expected at the beginning of each FP command request received over CSP */
typedef struct
{
    comm_gw_fp_comm_params_t comm_params; /**< FP communication parameters */
    uint32_t                 timeout;     /**< maximum time in milliseconds to wait for the response */
} PACKED fp_csp_binder_cmd_hdr_t;

/** @brief FP CSP command response header (placed at the beginning of each FP command response sent over CSP */
typedef struct
{
    comm_gw_comm_res_t cmd_res; /**< command execution result code */
} PACKED fp_csp_binder_cmd_resp_hdr_t;

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/

/** @brief Generic server task spawned to serve a connection with preset options (part of the csp_server_cfg_t)
 *
 *  @param param the task function expects a pointer to the csp_server_cfg_t configuration
 */
static CSP_DEFINE_TASK(csp_fp_rx_thread_func);

/** @brief Spawn a CSP server task with the specified parameters
 *  @param[in] p_server_cfg configuration for the server
 *
 *  @retval true: the server is up and running
 *  @retval false: the server setup failed
 */
static bool csp_start_fp_server(csp_server_cfg_t *const p_server_cfg);

/** @brief Perform basic validation of the provided FP parameters
 *  @param[in] p_fp_csp_cmd_hdr pointer to the CSP FP command header structure in the data packet
 *
 *  @retval true: the parameters are valid
 *  @retval false: one or more parameters are invalid
 */
static bool is_csp_fp_cmd_hdr_valid(const fp_csp_binder_cmd_hdr_t *p_fp_csp_cmd_hdr);

/** @brief Send a reply to a CSP FP command
 *  @param[in] p_send_ctx connection context information
 *  @param[in] p_server_cfg server configuration parameters
 *
 *  @return csp_send() return result
 */
static int32_t fp_csp_binder_send_reply(const comm_gw_send_ctx_t *p_send_ctx, csp_server_cfg_t *const p_server_cfg);

/** @brief Dispatch the comm_gw FP send operation and return a response if any available.
 *
 *  @param [in] p_srv_cfg server configuration parameters
 *  @param [in] p_pkt pointer to the received FP CSP packet buffer
 *
 *  @return result from the comm_gw_send() operation
 */
static comm_gw_comm_res_t dispatch_comm_gw_send(csp_server_cfg_t *const p_srv_cfg, csp_packet_t *p_pkt);

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/** @brief UDP server configuration */
static csp_server_cfg_t udp_server_cfg = {
    .p_cfg_name        = "UDP/opts:CRC32",
    .backlog_cnt       = CSP_FP_UDP_BACKLOG_CNT,
    .listen_port       = CSP_FP_UDP_SERVER_PORT,
    .opts              = CSP_O_CRC32,
    .p_active_conn     = NULL,
    .p_server_socket   = NULL,
    .p_thread_func     = &csp_fp_rx_thread_func,
    .p_thread_hnd      = NULL,
    .p_thread_name     = "fp-udp-thread",
    .thread_stack_size = SERVER_THREAD_STACK_SZ,
    .thread_prio       = SERVER_THREAD_PRIO,
    .fp_resp_buf       = { 0 },
    .task_mon_id       = TASK_ID_FP_CSP_UDP
};

/** @brief RDP server configuration */
static csp_server_cfg_t rdp_server_cfg = {
    .p_cfg_name        = "RDP/opts:CRC32",
    .backlog_cnt       = CSP_FP_RDP_BACKLOG_CNT,
    .listen_port       = CSP_FP_RDP_SERVER_PORT,
    .opts              = CSP_O_RDP | CSP_O_CRC32,
    .p_active_conn     = NULL,
    .p_server_socket   = NULL,
    .p_thread_func     = &csp_fp_rx_thread_func,
    .p_thread_hnd      = NULL,
    .p_thread_name     = "fp-rdp-thread",
    .thread_stack_size = SERVER_THREAD_STACK_SZ,
    .thread_prio       = SERVER_THREAD_PRIO,
    .fp_resp_buf       = { 0 },
    .task_mon_id       = TASK_ID_FP_CSP_RDP
};

/** @brief Format string for the server started announcement message */
static const char *const p_server_announce_fmt_msg = "csp fp binder %s server listening on '%u:%u'/(opts: 0x%04x)";

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

bool fp_csp_binder_start(void)
{
    bool udp_server_res = csp_start_fp_server(&udp_server_cfg);
    bool rdp_server_res = csp_start_fp_server(&rdp_server_cfg);

    return udp_server_res && rdp_server_res;
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
static int32_t fp_csp_binder_send_reply(const comm_gw_send_ctx_t *p_send_ctx, csp_server_cfg_t *const p_server_cfg)
{
    BREAK_ASSERT(NULL != p_send_ctx);
    BREAK_ASSERT(NULL != p_server_cfg);
    BREAK_ASSERT(NULL != p_send_ctx->p_req_data);
    BREAK_ASSERT(p_send_ctx->req_data_size > 0);
    BREAK_ASSERT(NULL != p_server_cfg->p_active_conn);

    if (NULL == p_server_cfg->p_active_conn)
    {
        return ESSATMAC_EC_ERROR;
    }

    csp_packet_t *p_packet = csp_buffer_get((size_t) * (p_send_ctx->p_resp_data_size));

    if (NULL == p_packet)
    {
        ES_TRACE_ERROR("could not allocate packet of size %u", (size_t) * (p_send_ctx->p_resp_data_size));
        return ESSATMAC_EC_NO_MEM;
    }

    BREAK_ASSERT(*(p_send_ctx->p_resp_data_size) <= UINT16_MAX);
    p_packet->length = (uint16_t) * (p_send_ctx->p_resp_data_size);

    (void)memcpy(p_packet->data, p_send_ctx->p_resp_data, (size_t)p_packet->length);

    ES_TRACE_DEBUG("sending %d byte(s) to node addr '%u:%u'", p_packet->length, csp_conn_dst(p_server_cfg->p_active_conn), csp_conn_dport(p_server_cfg->p_active_conn));

    int32_t send_res = csp_send(p_server_cfg->p_active_conn, p_packet, 2000);

    if (1 != send_res)
    {
        ES_TRACE_ERROR("[%d] failed to send message to node addr '%u:%u' (%u byte(s))", send_res, csp_conn_dst(p_server_cfg->p_active_conn), csp_conn_dport(p_server_cfg->p_active_conn), p_packet->length);
        csp_buffer_free(p_packet);
    }

    return send_res;
}

static bool csp_start_fp_server(csp_server_cfg_t *const p_server_cfg)
{
    BREAK_ASSERT(NULL != p_server_cfg);
    // the following guarantee that this function is called only once
    BREAK_ASSERT(NULL == p_server_cfg->p_server_socket);
    BREAK_ASSERT(NULL == p_server_cfg->p_thread_hnd);

    p_server_cfg->p_server_socket = csp_socket(p_server_cfg->opts);

    int32_t csp_res = csp_bind(p_server_cfg->p_server_socket, p_server_cfg->listen_port);

    if (CSP_ERR_NONE != csp_res)
    {
        return false;
    }

    csp_res = csp_listen(p_server_cfg->p_server_socket, p_server_cfg->backlog_cnt);

    if (CSP_ERR_NONE != csp_res)
    {
        return false;
    }

    if ((NULL == p_server_cfg->p_thread_hnd) &&
        (CSP_ERR_NONE != csp_thread_create(p_server_cfg->p_thread_func,
                                           p_server_cfg->p_thread_name,
                                           p_server_cfg->thread_stack_size,
                                           p_server_cfg,
                                           p_server_cfg->thread_prio,
                                           p_server_cfg->p_thread_hnd)))
    {
        ES_TRACE_ERROR("could not create thread '%s'", p_server_cfg->p_thread_name);

        return false;
    }

    task_mon_task_initialized(p_server_cfg->task_mon_id);
    task_mon_register_for_stats(p_server_cfg->task_mon_id, (TaskHandle_t)((void *)p_server_cfg->p_thread_hnd));

    return true;
}

static bool is_csp_fp_cmd_hdr_valid(const fp_csp_binder_cmd_hdr_t *p_fp_csp_cmd_hdr)
{
    return (NULL != p_fp_csp_cmd_hdr) &&
           (p_fp_csp_cmd_hdr->comm_params.mac_if_id == ESSASNI_SYS_PRI) &&
           (p_fp_csp_cmd_hdr->comm_params.msg_prio <= ESSASMP_LOW);
}

static comm_gw_comm_res_t dispatch_comm_gw_send(csp_server_cfg_t *const p_srv_cfg, csp_packet_t *p_pkt)
{
    BREAK_ASSERT(NULL != p_srv_cfg);
    BREAK_ASSERT(NULL != p_pkt);

    comm_gw_send_ctx_t       send_params;
    fp_csp_binder_cmd_hdr_t *p_fp_csp_cmd_hdr = (fp_csp_binder_cmd_hdr_t *)NULL;
    uint32_t                 gw_resp_size     = 0UL;
    comm_gw_comm_res_t       cmd_send_result  = COMM_GW_RES_ERR;

    // The received CSP packet shall be formatted in the following way:
    //
    // p_pkt->data => { [ packed header of type fp_csp_binder_cmd_hdr_t ] [ packed FP header ] [optional FP args] }
    //
    p_fp_csp_cmd_hdr = (p_pkt->length > sizeof(fp_csp_binder_cmd_hdr_t)) ? (fp_csp_binder_cmd_hdr_t *)p_pkt->data : (fp_csp_binder_cmd_hdr_t *)NULL;

    if (true == is_csp_fp_cmd_hdr_valid(p_fp_csp_cmd_hdr))
    {
        send_params.p_req_data    = &p_pkt->data[sizeof(fp_csp_binder_cmd_hdr_t)];
        send_params.req_data_size = ((uint32_t)p_pkt->length - sizeof(fp_csp_binder_cmd_hdr_t));
        // zero-out response header bytes
        (void)memset(p_srv_cfg->fp_resp_buf, 0U, sizeof(fp_csp_binder_cmd_resp_hdr_t));
        send_params.p_resp_data = &p_srv_cfg->fp_resp_buf[sizeof(fp_csp_binder_cmd_resp_hdr_t)];

        static_assert(sizeof(p_srv_cfg->fp_resp_buf) > sizeof(fp_csp_binder_cmd_resp_hdr_t));

        send_params.resp_data_max_size = (uint32_t)sizeof(p_srv_cfg->fp_resp_buf) - sizeof(fp_csp_binder_cmd_resp_hdr_t);
        send_params.p_resp_data_size   = &gw_resp_size;
        send_params.p_comm_params      = &p_fp_csp_cmd_hdr->comm_params;
        send_params.resp_timeout       = ((fp_csp_binder_cmd_hdr_t *)p_pkt->data)->timeout;

        cmd_send_result = comm_gw_send(COMM_GW_IF_ID_FP, COMM_GW_USER_ID_CSP_FP_SRV, &send_params);

        // if the size of the return type changes, this code must be modified
        static_assert(sizeof(comm_gw_comm_res_t) == 1);

        BREAK_ASSERT(cmd_send_result <= UINT8_MAX);

        // The CSP response is formatted in the following way:
        //
        // p_srv_cfg->fp_resp_buf => { [ packed header of type fp_csp_binder_cmd_resp_hdr_t ] [ packed FP response header ] [ optional FP output parameters ] }
        //                                                                                    ---------------------------------------------------------------
        //                                                                                                                 |
        //                                                                                                  handled by comm_gw_send()
        ((fp_csp_binder_cmd_resp_hdr_t *)p_srv_cfg->fp_resp_buf)->cmd_res = cmd_send_result;
        // move response pointer back to beginning before sending the reply back over CSP
        send_params.p_resp_data = p_srv_cfg->fp_resp_buf;
        gw_resp_size += sizeof(fp_csp_binder_cmd_resp_hdr_t);

        (void)fp_csp_binder_send_reply(&send_params, p_srv_cfg);
    }
    else
    {
        ES_TRACE_ERROR("Invalid communication parameters specified.");
    }

    return cmd_send_result;
}

static CSP_DEFINE_TASK(csp_fp_rx_thread_func)
{
    csp_packet_t           *p_rpacket    = NULL;
    csp_server_cfg_t *const p_server_cfg = (csp_server_cfg_t *)param;

    CRIT_ASSERT(NULL != p_server_cfg);

    ES_TRACE_DEBUG(p_server_announce_fmt_msg, p_server_cfg->p_cfg_name, CSP_SERVICE_CFG_OWN_ADDRESS, p_server_cfg->listen_port, p_server_cfg->opts);

    while (true)
    {
        p_server_cfg->p_active_conn = csp_accept(p_server_cfg->p_server_socket, 30000);

        if (NULL != p_server_cfg->p_active_conn)
        {
            while (NULL != (p_rpacket = csp_read(p_server_cfg->p_active_conn, 50)))
            {
                ES_TRACE_DEBUG("[%s] packet rcvd with len %u byte(s)", p_server_cfg->p_cfg_name, p_rpacket->length);

                (void)dispatch_comm_gw_send(p_server_cfg, p_rpacket);

                csp_buffer_free(p_rpacket);
            }

            csp_close(p_server_cfg->p_active_conn);
        }

        task_mon_i_am_alive(p_server_cfg->task_mon_id);
        task_mon_low_stack_check(p_server_cfg->task_mon_id);
    }

    return CSP_TASK_RETURN;
}
