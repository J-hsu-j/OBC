/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup Services
 * @{
 *
 * @defgroup csp_service
 * @{
 *
 * @file csp_service.c
 *
 * @brief Initialisation of the CSP stack (router task, ping handler, default route, etc.)
 *
 * @}
 * @}
 */

#include "es_cdef.h"
#include "csp_service.h"
#include "csp_service_cfg.h"
#include "cmsis_os2.h"
#include "can.h"
#include "trace.h"
#include "assertions.h"

/**< suppress warnings */

#include "csp_access.h"

#if !defined(CSP_ERROR_TRC_LVL)
#define CSP_ERROR_TRC_LVL (true)
#endif

#if !defined(CSP_WARN_TRC_LVL)
#define CSP_WARN_TRC_LVL (true)
#endif

#if !defined(CSP_INFO_TRC_LVL)
#define CSP_INFO_TRC_LVL (false)
#endif

#if !defined(CSP_BUFFER_TRC_LVL)
#define CSP_BUFFER_TRC_LVL (false)
#endif

#if !defined(CSP_PROTOCOL_TRC_LVL)
#define CSP_PROTOCOL_TRC_LVL (false)
#endif

#if !defined(CSP_PACKET_TRC_LVL)
#define CSP_PACKET_TRC_LVL (false)
#endif

#if !defined(CSP_LOCK_TRC_LVL)
#define CSP_LOCK_TRC_LVL (false)
#endif

#define FS_CSP_DISPATCH_NOTIFY_FLAG     (1)     /**< signals the CAN dispatcher thread about received message */
#define FS_CSP_DISPATCH_WAIT_TIMEOUT    (1000)  /**< CAN dispatcher thread notification timeout */
#define FS_CSP_ACCEPT_TIMEOUT           (10000) /**< csp_accept(...) timeout */
#define FS_CSP_LISTEN_BACKLOG_SZ        (10)    /**< csp_listen(...) backlog */
#define FS_CSP_READ_TIMEOUT             (50)    /**< csp_read(...) timeout (assuming max MTU size of 2KB at 1Mbit bus speed */
#define FS_CSP_ROUTER_TH_STACK_SZ       (500)   /**< Router's task stack size */
#define FS_CSP_SERVICE_TH_STACK_SZ      (580)   /**< Service's task stack size */
#define FS_CSP_CAN_DISPATCH_TH_STACK_SZ (500)   /**< CAN dispatcher's task stack size */

static int fs_can_transmit(void *driver_data, uint32_t id, const uint8_t *data, uint8_t data_sz);

/** @brief CSP debug hook handler for the OBC
 *
 *  @param[in] level trace level
 *  @param[in] format printf-like format string
 *  @param[in] args variable list of arguments for the specified format string
 */
static void csp_service_debug_trace_hook(csp_debug_level_t level, const char *format, va_list args);

INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/** @brief can interface data */
static csp_can_interface_data_t fs_iface_data_can = {
    .cfp_frame_id = 0,
    .tx_func      = fs_can_transmit
};

/** @brief can interface */
static csp_iface_t fs_iface_can = {
    .name              = CSP_IF_CAN_DEFAULT_NAME,
    .interface_data    = (void *)(&fs_iface_data_can),
    .driver_data       = NULL,
    .nexthop           = NULL,
    .mtu               = 0,
    .split_horizon_off = 0,
    .tx                = 0,
    .rx                = 0,
    .tx_error          = 0,
    .rx_error          = 0,
    .drop              = 0,
    .autherr           = 0,
    .frame             = 0,
    .txbytes           = 0,
    .rxbytes           = 0,
    .irq               = 0,
    .next              = NULL
};

/** @brief can dispatcher thread handle */
static csp_thread_handle_t fs_can_dispatch_h = NULL;

/** @brief csp service thread handle */
static csp_thread_handle_t fs_csp_service_h = NULL;

/**
 * @brief CSP service task. Handles ping request, etc.
 */
static CSP_DEFINE_TASK(fs_csp_service_thread)
{
    csp_socket_t *socket = csp_socket(CSP_SO_NONE);
    csp_bind(socket, CSP_CMP);
    csp_bind(socket, CSP_PING);
    csp_bind(socket, CSP_UPTIME);
    csp_listen(socket, FS_CSP_LISTEN_BACKLOG_SZ);
    csp_conn_t *conn;

    while (1)
    {
        conn = csp_accept(socket, FS_CSP_ACCEPT_TIMEOUT);

        if (NULL != conn)
        {
            csp_packet_t *packet;

            while (NULL != (packet = csp_read(conn, FS_CSP_READ_TIMEOUT)))
            {
                csp_service_handler(conn, packet);
            }

            csp_close(conn);
        }
    }
}

/**
 * @brief CAN dispatcher task.
 *        Reads received CAN messages from the driver
 *        and injects them into the CSP stack.
 */
static CSP_DEFINE_TASK(fs_csp_can_dispatch_thread)
{
    can_msg_t msg;

    while (1)
    {
        uint32_t flags = osThreadFlagsWait(
            FS_CSP_DISPATCH_NOTIFY_FLAG, osFlagsWaitAny, FS_CSP_DISPATCH_WAIT_TIMEOUT);

        if (FS_CSP_DISPATCH_NOTIFY_FLAG == flags)
        {
            while (true == can_rx(&msg, CAN_ID_EXTENDED))
            {
                csp_can_rx(&fs_iface_can, msg.id, msg.data, msg.data_sz, NULL);
            }
        }
    }
}

/**
 * @brief CAN RX handler. Wakes the dispatcher thread when a full message has been received.
 *        Function format is dictated by the CAN driver.
 *
 * @param msg    Received CAN message
 *
 * @retval false  Message not processed. Must be saved to RX Q.
 */
static bool fs_can_rx_callback(const can_msg_t *const msg)
{
    // check if this is the last message from a packet.
    // check csp_if_can.c for more info. if we don't use this we don't know when
    // a given message has been fully transmitted. This leads to too many interrupts and
    // the communication gets slower.
    if ((NULL != fs_can_dispatch_h) && (NULL != msg) && (0 == CFP_REMAIN(msg->id)))
    {
        osThreadFlagsSet(fs_can_dispatch_h, FS_CSP_DISPATCH_NOTIFY_FLAG);
    }

    return false;
}

/**
 * @brief transmits can message. function format is dictated by CSP stack
 *
 * @param driver_data     Not used
 * @param id              CAN message ID
 * @param data            CAN message data
 * @param data_sz         CAN message size
 *
 * @retval CSP_ERR_NONE   message transmitted
 * @retval CSP_ERR_DRIVER error while transmitting the message
 */
static int fs_can_transmit(void *driver_data, uint32_t id, const uint8_t *data, uint8_t data_sz)
{
    (void)driver_data;

    int       ret = CSP_ERR_TX;
    can_msg_t msg;

    if ((NULL != data) && (sizeof(msg.data) >= data_sz))
    {
        msg.id_type = CAN_ID_EXTENDED;
        msg.id      = id;
        msg.data_sz = data_sz;

        memcpy(msg.data, data, data_sz);

        if (true == can_tx(&msg))
        {
            ret = CSP_ERR_NONE;
        }
        else
        {
            ret = CSP_ERR_DRIVER;
        }
    }

    return ret;
}

static void csp_service_debug_trace_hook(csp_debug_level_t level, const char *format, va_list args)
{
    BREAK_ASSERT(NULL != format);

    static const char *p_csp_dbg_trace_lvl_str_unknown = "unknown";
    static const char *p_csp_dbg_trace_lvl_str_buffer  = "buffer";
    static const char *p_csp_dbg_trace_lvl_str_packet  = "packet";
    static const char *p_csp_dbg_trace_lvl_str_proto   = "proto";
    static const char *p_csp_dbg_trace_lvl_str_lock    = "lock";

    // buffer to hold the CSP formatted string
    char csp_trace_msg[CSP_SERVICE_TRACE_BUF_SZ] = { '\0' };

    int32_t trace_str_sz = (int32_t)vsnprintf((char *)csp_trace_msg,
                                              CDEF_ELEMENT_COUNT(csp_trace_msg),
                                              format,
                                              args);

    // add terminating null just in case
    csp_trace_msg[sizeof(csp_trace_msg) - 1] = '\0';

    if ((trace_str_sz > 0) && (trace_str_sz > (int32_t)sizeof(csp_trace_msg)))
    {
        ES_TRACE_WARN("CSP trace requires %ld characters but only %ld reserved", trace_str_sz, sizeof(csp_trace_msg));
    }
    else if (trace_str_sz <= 0)
    {
        ES_TRACE_ERROR("CSP trace format failed with error %d", trace_str_sz);
    }
    else
    {
        switch (level)
        {
            case CSP_INFO:
                {
                    ES_TRACE_INFO("%s", csp_trace_msg);
                    break;
                }

            case CSP_ERROR:
                {
                    ES_TRACE_ERROR("%s", csp_trace_msg);
                    break;
                }

            case CSP_WARN:
                {
                    ES_TRACE_WARN("%s", csp_trace_msg);
                    break;
                }

            case CSP_BUFFER:
                {
                    ES_TRACE_DEBUG("|%s| %s", p_csp_dbg_trace_lvl_str_buffer, csp_trace_msg);
                    break;
                }

            case CSP_PACKET:
                {
                    ES_TRACE_DEBUG("|%s| %s", p_csp_dbg_trace_lvl_str_packet, csp_trace_msg);
                    break;
                }

            case CSP_PROTOCOL:
                {
                    ES_TRACE_DEBUG("|%s| %s", p_csp_dbg_trace_lvl_str_proto, csp_trace_msg);
                    break;
                }

            case CSP_LOCK:
                {
                    ES_TRACE_DEBUG("|%s| %s", p_csp_dbg_trace_lvl_str_lock, csp_trace_msg);
                    break;
                }

            default:
                {
                    ES_TRACE_DEBUG("|%s(%d)| %s", p_csp_dbg_trace_lvl_str_unknown, (uint8_t)level, csp_trace_msg);
                    ES_TRACE_WARN("bad CSP trace level '%d'", (uint8_t)level);
                }
        }
    }
}

bool csp_service_init(void)
{
    csp_conf_t config;

    // install a custom CSP trace handler function to forward all traces to
    // the OBC trace module
    csp_debug_hook_set(&csp_service_debug_trace_hook);

    // setup default trace levels
    csp_debug_set_level(CSP_ERROR, CSP_ERROR_TRC_LVL);
    csp_debug_set_level(CSP_WARN, CSP_WARN_TRC_LVL);
    csp_debug_set_level(CSP_INFO, CSP_INFO_TRC_LVL);
    csp_debug_set_level(CSP_BUFFER, CSP_BUFFER_TRC_LVL);
    csp_debug_set_level(CSP_PROTOCOL, CSP_PROTOCOL_TRC_LVL);
    csp_debug_set_level(CSP_PACKET, CSP_PACKET_TRC_LVL);
    csp_debug_set_level(CSP_LOCK, CSP_LOCK_TRC_LVL);

    csp_conf_get_defaults(&config);

    config.address          = CSP_SERVICE_CFG_OWN_ADDRESS;
    config.buffers          = CSP_SERVICE_CFG_NUM_BUFFERS;
    config.buffer_data_size = CSP_SERVICE_CFG_BUFFER_SZ;

    if (CSP_ERR_NONE != csp_init(&config))
    {
        return false;
    }

    can_reg_rx(CAN_ID_EXTENDED, fs_can_rx_callback);

    if (CSP_ERR_NONE != csp_can_add_interface(&fs_iface_can))
    {
        return false;
    }

    if (CSP_ERR_NONE != csp_thread_create(
                            fs_csp_can_dispatch_thread,
                            "csp_can_disp",
                            FS_CSP_CAN_DISPATCH_TH_STACK_SZ,
                            NULL,
                            osPriorityNormal,
                            &fs_can_dispatch_h))
    {
        return false;
    }

    if (CSP_ERR_NONE != csp_rtable_set(
                            CSP_SERVICE_CFG_OWN_ADDRESS, CSP_ID_HOST_SIZE, &csp_if_lo, CSP_NO_VIA_ADDRESS))
    {
        return false;
    }

    if (CSP_ERR_NONE != csp_rtable_set(
                            CSP_DEFAULT_ROUTE, CSP_ID_HOST_SIZE, &fs_iface_can, CSP_NO_VIA_ADDRESS))
    {
        return false;
    }

    if (CSP_ERR_NONE != csp_route_start_task(
                            FS_CSP_ROUTER_TH_STACK_SZ, osPriorityNormal))
    {
        return false;
    }

    if (CSP_ERR_NONE != csp_thread_create(
                            fs_csp_service_thread,
                            "csp_service",
                            FS_CSP_SERVICE_TH_STACK_SZ,
                            NULL,
                            osPriorityNormal,
                            &fs_csp_service_h))
    {
        return false;
    }

    return true;
}

bool csp_service_set_trace_level(CSP_SERVICE_debug_levels_t trace_levels)
{
    // Install a custom CSP trace handler function to forward all traces to the OBC trace module
    csp_debug_hook_set(&csp_service_debug_trace_hook);

    // Set runtime selected trace levels
    csp_debug_set_level(CSP_ERROR, trace_levels.bCSP_ERROR_FLAG);
    csp_debug_set_level(CSP_WARN, trace_levels.bCSP_WARN_FLAG);
    csp_debug_set_level(CSP_INFO, trace_levels.bCSP_INFO_FLAG);
    csp_debug_set_level(CSP_BUFFER, trace_levels.bCSP_BUFFER_FLAG);
    csp_debug_set_level(CSP_PROTOCOL, trace_levels.bCSP_PROTOCOL_FLAG);
    csp_debug_set_level(CSP_PACKET, trace_levels.bCSP_PACKET_FLAG);
    csp_debug_set_level(CSP_LOCK, trace_levels.bCSP_LOCK_FLAG);

    return true;
}

CSP_SERVICE_debug_levels_t csp_service_get_trace_level(void)
{
    CSP_SERVICE_debug_levels_t csp_service_debug_levels;

    csp_service_debug_levels.bCSP_ERROR_FLAG    = csp_debug_get_level(CSP_ERROR);
    csp_service_debug_levels.bCSP_WARN_FLAG     = csp_debug_get_level(CSP_WARN);
    csp_service_debug_levels.bCSP_INFO_FLAG     = csp_debug_get_level(CSP_INFO);
    csp_service_debug_levels.bCSP_BUFFER_FLAG   = csp_debug_get_level(CSP_BUFFER);
    csp_service_debug_levels.bCSP_PACKET_FLAG   = csp_debug_get_level(CSP_PACKET);
    csp_service_debug_levels.bCSP_PROTOCOL_FLAG = csp_debug_get_level(CSP_PROTOCOL);
    csp_service_debug_levels.bCSP_LOCK_FLAG     = csp_debug_get_level(CSP_LOCK);

    return csp_service_debug_levels;
}
