/******************************** INCLUDE FILES *******************************/

#include "csp_access.h"

#include "cmsis_os2.h"

#include "essdr_classes.h"

#include "es_sdr_client_csp.h"

#include "es_tftp_pkt.h"

/* Internal gp utils & classes */
#include "es_plf.h"
#include "es_port_fm.h"

/*********************************** DEFINES **********************************/
#define ES_MODULE_NAME "es_csp"
// #define ES_CSP_SFP

/******* CSP Client connection properties *******/
#define ES_CSP_RECV_TIMEOUT (SDR_CSP_RECEIVE_TIMEOUT_MS)
#define ES_CSP_SEND_TIMEOUT (SDR_CSP_SEND_TIMEOUT_MS)

#define ES_CSP_CONN_RETRIES     (SDR_CSP_CONNECTION_RETRIES)
#define ES_CSP_CONN_RETRIE_WAIT (SDR_CSP_CONNECTION_RETRIES_WAIT)
#define ES_CSP_CONN_OPTIONS     (SDR_CSP_CONNECTION_OPTIONS)

#define ES_CSP_MTU (CLIENT_IO_BUFFER_SIZE)

#define ES_CSP_RPC_PORT  (SDR_CSP_RPC_PORT)
#define ES_CSP_TFTP_PORT (SDR_CSP_TFTP_PORT)
/********************************* TYPEDEF ************************************/
typedef struct _es_csp_state_t
{
    uint32_t dest_addr;
} es_csp_state_t;

/********************************* LOCAL DATA *********************************/

/***************************** FUNCTION PROTOTYPES ****************************/

/********************************* LOCAL DATA *********************************/
static uint16_t es_sdr_client_app_port[ES_SDR_CLIENT_APP_N] = {
    ES_CSP_RPC_PORT,
    ES_CSP_TFTP_PORT
};

/********************************* LOCAL STATE ********************************/
static es_csp_state_t     es_csp_state;
static es_sdr_client_tl_t es_sdr_csp_tl;

/******************************* LOCAL FUNCTIONS *******************************/
/**
 * Initialize CSP Context
 *
 */
static int8_t es_sdr_client_csp_init(void *args)
{
    es_csp_conf_t *csp_conf = (es_csp_conf_t *)args;
    es_csp_state.dest_addr  = csp_conf->addr;

    return 0;
}

static void es_sdr_client_csp_deinit()
{
    /* this might do something in the future */
}

static int8_t es_sdr_client_csp_connect(void *conn_ctx)
{
    int8_t                connection_retries = ES_CSP_CONN_RETRIES;
    int8_t                connected          = 0;
    es_sdr_client_conn_t *conn               = (es_sdr_client_conn_t *)conn_ctx;
    /**
     * TODO: Implement timeout
     */
    do
    {
        conn->descriptor = csp_connect(0, es_csp_state.dest_addr,
                                       conn->dest_port, 15000, (ES_CSP_CONN_OPTIONS));
        if (conn->descriptor == NULL)
        {
            /* Connect failed */
            connected = 0;
            connection_retries--;
            ES_LOG_MSG(ES_WARNING, "Connection failed (%u)", connection_retries);
            osDelay(ES_CSP_CONN_RETRIE_WAIT);
        }
        else
        {
            connected = 1;
        }
    } while (connection_retries && !connected);

    return connected ? 0 : -1;
}

static int8_t es_sdr_client_csp_disconnect(void *conn_ctx)
{
    int8_t ret = CSP_ERR_NONE;

    es_sdr_client_conn_t *conn = (es_sdr_client_conn_t *)conn_ctx;

    ret = csp_close(conn->descriptor);
    if (CSP_ERR_NONE != ret)
    {
        ES_LOG_MSG(ES_ERROR, "Failed to close connection");
        return -1;
    }
    conn->descriptor = NULL;

    return 0;
}

static uint16_t es_sdr_client_csp_get_port(es_sdr_client_app_t app_type)
{
    if (app_type < ES_SDR_CLIENT_RPC || app_type >= ES_SDR_CLIENT_APP_N)
    {
        ES_LOG_MSG(ES_ERROR, "Invalid application type: %d", app_type);
        return ES_SDR_CLIENT_INVALID;
    }

    return es_sdr_client_app_port[app_type];
}

static int8_t es_sdr_client_csp_send(void *conn_ctx, uint8_t *o_buffer,
                                     int32_t o_buffer_size)
{
    int8_t ret = CSP_ERR_NONE;

    es_sdr_client_conn_t *conn = (es_sdr_client_conn_t *)conn_ctx;

#ifdef ES_CSP_SFP
    ret = csp_sfp_send(conn->descriptor, (void *)o_buffer,
                       o_buffer_size, (unsigned int)ES_CSP_SFP_CHUNK_SIZE, ES_CSP_SEND_TIMEOUT);
    if (CSP_ERR_NONE != ret)
    {
        /* Send failed */
        ES_LOG_MSG(ES_ERROR, "Send failed");
    }
#else
    csp_packet_t *packet = csp_buffer_get(ES_CSP_MTU);
    if (packet == NULL)
    {
        /* Could not get buffer element */
        ES_LOG_MSG(ES_ERROR, "Failed to get CSP buffer");
        return -1;
    }
    memcpy(packet->data, o_buffer, o_buffer_size);
    packet->length = o_buffer_size;

    if (1 != csp_send(conn->descriptor, packet, ES_CSP_SEND_TIMEOUT))
    {
        /* Send failed */
        ES_LOG_MSG(ES_ERROR, "Send failed");
        csp_buffer_free(packet);
    }
#endif

    return ret;
}

static int8_t es_sdr_client_csp_recv(void *conn_ctx, uint8_t *i_buffer,
                                     int32_t *i_buffer_size, uint32_t i_buffer_max_size)
{
    int8_t                ret  = CSP_ERR_NONE;
    es_sdr_client_conn_t *conn = (es_sdr_client_conn_t *)conn_ctx;

#ifdef ES_CSP_SFP
    /* The data is dynamically allocated by the sfp recv function */
    void *data     = NULL;
    int   data_len = 0;

    ret = csp_sfp_recv(conn->descriptor, &data, &data_len, ES_CSP_RECV_TIMEOUT);
    if (CSP_ERR_NONE != ret)
    {
        ES_LOG_MSG(ES_ERROR, "Receive failed (%d)", ret);
        *i_buffer_size = 0;
        goto err;
    }
    memcpy(i_buffer, data, data_len);
    *i_buffer_size = data_len;

err:
    if (data != NULL)
    {
        csp_free(data);
    }
#else
    csp_packet_t *packet = NULL;
    packet               = csp_read(conn->descriptor, ES_CSP_RECV_TIMEOUT);

    // check packet
    // ES_TFTP_PKT_MAX_SIZE is the maximum size of a packet we can receive from the sdr
    if ((NULL != packet) &&
        (packet->length <= i_buffer_max_size))
    {
        memcpy(i_buffer, packet->data, packet->length);
        *i_buffer_size = packet->length;
        csp_buffer_free(packet);
    }
    else
    {
        ret = CSP_ERR_TIMEDOUT;
        ES_LOG_MSG(ES_ERROR, "TIMED OUT (%d)", ret);
    }
#endif

    return ret;
}

/***************************** INTERFACE FUNCTIONS ****************************/
es_sdr_client_tl_t *es_sdr_client_csp_get(void)
{
    es_sdr_csp_tl.init   = es_sdr_client_csp_init;
    es_sdr_csp_tl.deinit = es_sdr_client_csp_deinit;

    es_sdr_csp_tl.get_port = es_sdr_client_csp_get_port;

    es_sdr_csp_tl.connect    = es_sdr_client_csp_connect;
    es_sdr_csp_tl.disconnect = es_sdr_client_csp_disconnect;

    es_sdr_csp_tl.send = es_sdr_client_csp_send;
    es_sdr_csp_tl.recv = es_sdr_client_csp_recv;

    return &es_sdr_csp_tl;
}
