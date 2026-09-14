/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/******************************** INCLUDE FILES *******************************/
#include <string.h>
#include "essdr_classes.h"

/*** Transport layer ***/
#include "es_sdr_client_tl_iface.h"
/* ES CSP */
#include "es_sdr_client_csp.h"

/*** Services Topology ***/
#include "es_services_routing_pdu.h"
#include "es_services_routing_table.h"

/* ES Client Ser Des Iface */
#include "es_sdr_client_ser_des_iface.h"

/* Ser/des Encode/Decode */
#include "es_adrv9009_ser_des.h"
#include "es_board_info_ser_des.h"
#include "es_board_mgr_ser_des.h"
#include "es_iprium_dvb_s2_ser_des.h"
#include "es_rce_ser_des.h"
#include "es_test_ser_des.h"

#include "es_tftp_pkt.h"
#include "es_port_fm.h"

#include "es_log.h"

/******************************** LOCAL DEFINES *******************************/
#define ES_MODULE_NAME "es_sdr_client"

/*  Structure of our class */
typedef struct _es_sdr_client_t
{
    /*** Transport layer ***/
    bool transport_layer_init_done;

    /* Indicates which transport layer is used by the instance */
    es_sdr_client_transport_t transport_layer_type;
    /* Transport Layer abstraction */
    es_sdr_client_tl_t *transport_layer;

    /* Protobuffer RPC ser/des handlers (per service) */
    es_ser_des_t *ser_des_hndlrs[ES_SERVICES_SERDES_IDS];
} es_sdr_client_t;

/********************************* LOCAL DATA *********************************/
static es_sdr_client_t sdr_client;

static const char *transport_layers[ES_SDR_CLIENT_TL_N] = {
    "CSP",
};

/******************************* INTERFACE DATA *******************************/

/******************************* LOCAL FUNCTIONS ******************************/
bool es_client_transport_init_done(void)
{
    if (true == sdr_client.transport_layer_init_done)
    {
        return true;
    }

    return false;
}

static uint16_t es_service_port_get(int service_id)
{
    uint16_t service_port = 0;

    switch (service_id)
    {
        case ES_TEST_SERDES_ID:
            service_port = TEST_SERVICE_ID;
            break;

        case ES_ADRV9009_SERDES_ID:
            service_port = ADRV9009_SERVICE_ID;
            break;

        case ES_BOARD_INFO_SERDES_ID:
            service_port = BOARD_INFO_SERVICE_ID;
            break;

        case ES_IPRIUM_DVB_S2_SERDES_ID:
            service_port = IPRIUM_DVB_S2_SERVICE_ID;
            break;

        case ES_BOARD_MGR_SERDES_ID:
            service_port = BOARD_MGR_SERVICE_ID;
            break;

        case ES_RCE_SERDES_ID:
            service_port = REMOTE_CODE_EXECUTION_SERVICE_ID;
            break;

        case VYOMA_SERDES_ID:
            service_port = VYOMA_SERVICE_ID;
            break;

        default:
            ES_LOG_MSG(ES_ERROR, "Invalid service ID: %d", service_id);
            service_port = ES_SERVICE_INVALID;
            break;
    }

    return service_port;
}

static int8_t es_client_parse_conn_status(es_service_conn_statuses_t conn_status)
{
    /* Just parse and print the conn_stat info */
    if (conn_status != ES_SERVICE_CONN_SUCCESS)
    {
        if (conn_status >= ES_SERVICE_CONN_STATUSES)
        {
            ES_LOG_MSG(ES_ERROR, "Service Connection failed (Unknown status)");
        }
        else
        {
            ES_LOG_MSG(ES_ERROR, "Service Connection failed");
            ES_LOG_MSG(ES_ERROR, es_services_routing_pdu_conn_status_print(conn_status));
        }

        return -1;
    }

    return 0;
}

static int32_t es_sdr_client_encode(uint32_t service_id, uint32_t rpc_id, void *msg, uint8_t *buffer)
{
    es_services_routing_pdu_t *o_pdu = es_services_routing_pdu_new(buffer);
    o_pdu->service_port              = es_service_port_get(service_id);
    ES_LOG_MSG(ES_TRACE, "Service port: %u", o_pdu->service_port);

    o_pdu->data_length = sdr_client.ser_des_hndlrs[service_id]->ser(rpc_id,
                                                                    (char *)o_pdu->data, msg);
    ES_LOG_MSG(ES_TRACE, "Encoded o_pdu len: %d", o_pdu->data_length + sizeof(es_services_routing_pdu_t));

    return o_pdu->data_length + sizeof(es_services_routing_pdu_t);
}

static int8_t es_sdr_client_decode(uint32_t service_id, uint32_t rpc_id, uint8_t *buffer, void *msg)
{
    int ret = 0;

    es_services_routing_pdu_t *i_pdu = es_services_routing_pdu_new(buffer);

    ES_LOG_MSG(ES_TRACE, "Service port: %u", i_pdu->service_port);
    ret = sdr_client.ser_des_hndlrs[service_id]->des(rpc_id, (char *)i_pdu->data, msg);

    return ret;
}

static es_tftp_err_code_t es_sdr_client_send(void *conn, uint8_t *o_buffer, int32_t o_buffer_size)
{
    es_tftp_err_code_t ret = ES_TFTP_ERR_NOT_DEFINED;

    if (false == es_client_transport_init_done())
    {
        ES_LOG_MSG(ES_ERROR, "Transport layer not initialized!");
        ret = ES_TFTP_TL_NOT_INIT;
        return ret;
    }

    /* The tranport layer must be initialized to send/recv */
    // ES_LOG_HEXDUMP("____Protobuffer request___", o_buffer, o_buffer_size);

    int8_t connect_ret = sdr_client.transport_layer->connect(conn);
    if (0 != connect_ret)
    {
        ES_LOG_MSG(ES_ERROR, "Connection to server failed");
        ret = ES_TFTP_CONNECTION_TO_SERVER_FAILED;
    }
    else
    {
        int8_t send_ret = sdr_client.transport_layer->send(conn, o_buffer, o_buffer_size);
        if (0 != send_ret)
        {
            ES_LOG_MSG(ES_ERROR, "Send failed!");
            ret = ES_TFTP_SEND_FAILED;
        }
        ret = ES_TFTP_STATUS_OK;
    }

    return ret;
}

static es_tftp_err_code_t es_sdr_client_recv(void *conn, uint8_t *i_buffer, int32_t *i_buffer_size, uint32_t i_buffer_max_size)
{
    es_tftp_err_code_t ret = ES_TFTP_STATUS_OK;

    int8_t recv_ret = sdr_client.transport_layer->recv(conn, i_buffer, i_buffer_size, i_buffer_max_size);
    if (0 != recv_ret)
    {
        ES_LOG_MSG(ES_ERROR, "Read failed!");
        ret = ES_TFTP_RECV_FAILED;
    }
    else
    {
        // ES_LOG_HEXDUMP("___Protobuffer response___", i_buffer, *i_buffer_size);
    }

    int8_t disc_ret = sdr_client.transport_layer->disconnect(conn);
    if (0 != disc_ret)
    {
        ES_LOG_MSG(ES_ERROR, "Disconnect failed!");
        ret = ES_TFTP_FAILED_TO_DISCONNECT_FROM_SERVER;
    }

    return ret;
}

/**************************** INTERFACE FUNCTIONS *****************************/
bool es_sdr_client_init(void)
{
    ES_LOG_MSG(ES_TRACE, "Initializing ES SDR client");

    bool ret = true;

    sdr_client.ser_des_hndlrs[ES_TEST_SERDES_ID]          = es_test_ser_des_get_hndlrs();
    sdr_client.ser_des_hndlrs[ES_ADRV9009_SERDES_ID]      = es_adrv9009_ser_des_get_hndlrs();
    sdr_client.ser_des_hndlrs[ES_BOARD_INFO_SERDES_ID]    = es_board_info_ser_des_get_hndlrs();
    sdr_client.ser_des_hndlrs[ES_IPRIUM_DVB_S2_SERDES_ID] = es_iprium_dvb_s2_ser_des_get_hndlrs();
    sdr_client.ser_des_hndlrs[ES_BOARD_MGR_SERDES_ID]     = es_board_mgr_ser_des_get_hndlrs();
    sdr_client.ser_des_hndlrs[ES_RCE_SERDES_ID]           = es_rce_ser_des_get_hndlrs();

    // check if the ser/des handlers are initialized
    // Note: it is important not to have any services with protobuf-defined commands
    // put in the service enumeration es_sdr_client_ser_des_handlers_t after VYOMA_SERDES_ID.
    // Anything after ES_RCE_SERDES_ID is application-based and not internal to the SDR
    for (uint8_t i = 0; i < VYOMA_SERDES_ID; i++)
    {
        if (sdr_client.ser_des_hndlrs[i] == NULL)
        {
            ret = false;
            break;
        }
    }

    //  Initialize class properties here
    sdr_client.transport_layer_init_done = false;
    sdr_client.transport_layer           = NULL;

    return ret;
}

/**
 * Deinit es_client object.
 */
void es_sdr_client_deinit(void)
{
    /* If the transport layer is initialized free the object/deinit */
    if (sdr_client.transport_layer != NULL)
    {
        sdr_client.transport_layer->deinit();
    }
}

bool es_sdr_client_csp_tl_init(uint16_t dest_addr)
{
    bool   ret      = false;
    int8_t init_ret = -1;

    if (true == es_client_transport_init_done())
    {
        ES_LOG_MSG(ES_WARNING, "Transport layer already initialized: %s",
                   transport_layers[sdr_client.transport_layer_type]);
        ret = true;
        return ret;
    }

    es_csp_conf_t csp_conf;
    csp_conf.addr = dest_addr;

    /* Indicate that the transport layer that will be used is CSP */
    sdr_client.transport_layer_type = ES_SDR_CLIENT_TL_CSP;
    sdr_client.transport_layer      = es_sdr_client_csp_get();
    init_ret                        = sdr_client.transport_layer->init(&csp_conf);

    if (0 != init_ret)
    {
        ES_LOG_MSG(ES_ERROR, "Failed to initialize CSP transport layer");
        sdr_client.transport_layer_init_done = false;
        sdr_client.transport_layer           = NULL;
        return ret;
    }

    sdr_client.transport_layer_init_done = true;
    ret                                  = true;

    return ret;
}

es_tftp_err_code_t es_sdr_client_file_download(const char *src_file, const char *dest_file)
{
    es_tftp_err_code_t   ret = ES_TFTP_ERR_NOT_DEFINED;
    uint8_t              buff[SDR_CSP_MTU];
    int32_t              buff_size     = 0;
    es_tftp_pkt_t       *i_pkt         = NULL;
    fm_file_obj_t        file_obj      = { 0 };
    fm_handle_t          fp            = &file_obj; /* File handle */
    es_sdr_client_conn_t conn          = es_sdr_client_conn_init_default;
    uint32_t             bytes_written = 0; /* Bytes written (for a single data transaction) to the file */

    /*
    * initialize tftp buffer
    */
    memset(buff, 0, sizeof(buff));

    if (false == es_client_transport_init_done())
    {
        ES_LOG_MSG(ES_ERROR, "Transport layer not initialized!");
        ret = ES_TFTP_TL_NOT_INIT;
        return ret;
    }

/**
 *  The file is always truncated upon open
 */
#if 0
    ret = es_port_file_exist(dest_file);
    if (ret == 0)
        es_port_file_remove(dest_file);
#endif

    if (FM_RES_OK != es_port_file_open(fp, dest_file, (FM_MODE_WRITE | FM_MODE_CREATE_ALWAYS)))
    {
        ES_LOG_MSG(ES_ERROR, "Failed to open destination file for writing!");
        ret = ES_TFTP_CANNOT_OPEN_DEST_FILE_FOR_WRITE;
        return ret;
    }

    conn.dest_port     = sdr_client.transport_layer->get_port(ES_SDR_CLIENT_TFPT);
    int8_t connect_ret = sdr_client.transport_layer->connect(&conn);

    if (0 != connect_ret)
    {
        ES_LOG_MSG(ES_ERROR, "Connection to server failed");
        (void)es_port_file_close(fp);
        ret = ES_TFTP_CONNECTION_TO_SERVER_FAILED;
        return ret;
    }

    /* Send Read request */
    buff_size = es_tftp_opkt_request(buff, ES_TFTP_RRQ, (const uint8_t *)src_file);
    sdr_client.transport_layer->send(&conn, buff, buff_size);

    uint16_t block_size = 0;

    /* Start receiving:
     *       <--- DATA
     * ACK --->
     *       <--- DATA
     * ACK --->
     *    ...
     *    ...
     *       <--- DATA
     * ACK --->
     * Stop condition: bytes_received [0; 511] or intermediary step failiure
     */

    for (;;)
    {
        int8_t recv_ret = sdr_client.transport_layer->recv(&conn, buff, &buff_size, sizeof(buff));
        if (0 != recv_ret)
        {
            ES_LOG_MSG(ES_ERROR, "Read failed!");
            ret = ES_TFTP_RECV_FAILED;
            break;
        }

        i_pkt = es_tftp_ipkt_get(buff, (size_t)buff_size);
        if (i_pkt->opcode == ES_TFTP_ERROR)
        {
            ES_LOG_MSG(ES_ERROR, "Error: %s (%d)", i_pkt->err.msg, i_pkt->err.code);
            ret = (es_tftp_err_code_t)i_pkt->err.code;
            break;
        }

        /* We expect this to be a data packet */
        if (i_pkt->opcode != ES_TFTP_DATA)
        {
            buff_size = es_tftp_opkt_err(buff, ES_TFTP_ERR_ILLEGAL_TFTP_OPERATION,
                                         (const uint8_t *)"Expected data block!");
            sdr_client.transport_layer->send(&conn, buff, buff_size);
            ret = ES_TFTP_ERR_ILLEGAL_TFTP_OPERATION;
            break;
        }

        /* Get data packet's block size */
        block_size = (uint16_t)es_tftp_ipkt_data_size(i_pkt, (ssize_t)buff_size);

        /* Write data on the disk */
        if (FM_RES_OK != es_port_file_write(fp, i_pkt->data.block, block_size, &bytes_written))
        {
            ES_LOG_MSG(ES_ERROR, "Failed to write to destination file");
            ret = ES_TFTP_FAILED_TO_WRITE_TO_DEST_FILE;
            break;
        }

        /* Send ack */
        buff_size = es_tftp_opkt_ack(buff, i_pkt->data.block_number);
        sdr_client.transport_layer->send(&conn, buff, buff_size);
        if (block_size < ES_TFTP_BLOCK_SIZE)
        {
            ret = ES_TFTP_STATUS_OK;
            break;
        }
    }

    if (FM_RES_OK != es_port_file_close(fp))
    {
        ES_LOG_MSG(ES_ERROR, "Failed to close destination file");
        ret = ES_TFTP_FAILED_TO_CLOSE_DEST_FILE;
    }
    sdr_client.transport_layer->disconnect(&conn);

    return ret;
}

es_tftp_err_code_t es_sdr_client_file_upload(const char *src_file, const char *dest_file)
{
    es_tftp_err_code_t   ret          = ES_TFTP_ERR_NOT_DEFINED;
    uint32_t             bytes_read   = 0; /* Bytes read (for a single data transaction) from the file */
    uint16_t             block_number = 0; /* Block ID */
    uint8_t              buff[SDR_CSP_MTU];
    int32_t              buff_size = 0;
    es_tftp_pkt_t       *i_pkt     = NULL;
    es_sdr_client_conn_t conn;
    fm_file_obj_t        file_obj = { 0 };
    fm_handle_t          fp       = &file_obj; /* File handle */

    /*
    * initialize tftp buffer
    */
    memset(buff, 0, sizeof(buff));

    if (false == es_client_transport_init_done())
    {
        ES_LOG_MSG(ES_ERROR, "Transport layer not initialized!");
        ret = ES_TFTP_TL_NOT_INIT;
        return ret;
    }

    if (FM_RES_OK != es_port_file_open(fp, src_file, FM_MODE_READ))
    {
        ES_LOG_MSG(ES_ERROR, "Failed to open source file for reading!");
        ret = ES_TFTP_CANNOT_OPEN_SOURCE_FILE_FOR_READ;
        return ret;
    }

    conn.dest_port     = sdr_client.transport_layer->get_port(ES_SDR_CLIENT_TFPT);
    int8_t connect_ret = sdr_client.transport_layer->connect(&conn);

    if (0 != connect_ret)
    {
        ES_LOG_MSG(ES_ERROR, "Connection to server failed");
        (void)es_port_file_close(fp);
        ret = ES_TFTP_CONNECTION_TO_SERVER_FAILED;
        return ret;
    }

    /* Send Write request */
    buff_size = es_tftp_opkt_request(buff, ES_TFTP_WRQ, (const uint8_t *)dest_file);
    sdr_client.transport_layer->send(&conn, buff, buff_size);

    /* Start sending:
     *       <--- ACK
     * DATA --->
     *       <--- ACK
     *    ...
     *    ...
     * DATA --->
     *       <--- ACK
     * Stop condition: bytes_read [0; 511] or intermediary step failiure
     */

    bool transfer_finished = false;
    for (;;)
    {
        /**
         * 1. Create Data packet
         * 2. Send Data packet
         * 3. Receive Packet
         * 4. Check for acknowedged data block
         */

        /* 1. Create Data packet */
        int8_t recv_ret = sdr_client.transport_layer->recv(&conn, buff, &buff_size, sizeof(buff));
        if (0 != recv_ret)
        {
            ES_LOG_MSG(ES_ERROR, "Read failed!");
            ret = ES_TFTP_RECV_FAILED;
            break;
        }

        i_pkt = es_tftp_ipkt_get(buff, (size_t)buff_size);
        if (i_pkt == NULL)
        {
            /* Mallformed packet */
            const char *err_msg = "Mallformed TFTP packet!";
            ES_LOG_MSG(ES_ERROR, "Error: %s", err_msg);
            buff_size = es_tftp_opkt_err(buff, ES_TFTP_ERR_ILLEGAL_TFTP_OPERATION,
                                         (const uint8_t *)err_msg);
            ret       = ES_TFTP_ERR_ILLEGAL_TFTP_OPERATION;
            break;
        }

        /* 4. Check for acknowedged data block */
        /* The client is telling us that an error has occured on his side */
        if (i_pkt->opcode == ES_TFTP_ERROR)
        {
            /* At this point the client has disconnected, so we close the transfer here
             * as well.
             */
            ES_LOG_MSG(ES_ERROR, "Error: %s (%d)", i_pkt->err.msg, i_pkt->err.code);
            ret = (es_tftp_err_code_t)i_pkt->err.code;
            break;
        }

        /**
         * Waiting for ACK of the DATA block that we have sent
         * Any other opcode is threated as an error.
         */
        if (i_pkt->opcode != ES_TFTP_ACK)
        {
            const uint8_t *err_msg = (const uint8_t *)"Illegal TFTP operation!";
            ES_LOG_MSG(ES_ERROR, "%s", err_msg);
            buff_size = es_tftp_opkt_err(buff, ES_TFTP_ERR_ILLEGAL_TFTP_OPERATION,
                                         err_msg);
            ret       = ES_TFTP_ERR_ILLEGAL_TFTP_OPERATION;
            break;
        }

        /* ACK received. Check block n */
        if (i_pkt->ack.block_number != block_number)
        {
            ES_LOG_MSG(ES_ERROR, "Block number missmatch! i:%d Expected: %d",
                       i_pkt->ack.block_number, block_number);
            ret = ES_TFTP_BLOCK_NUMBER_MISMATCH;
            break;
        }

        if (transfer_finished)
        {
            ret = ES_TFTP_STATUS_OK;
            break;
        }

        block_number = (block_number + 1) % ES_TFTP_BLOCK_N_MAX_VALUE;

        buff_size = es_tftp_opkt_data(buff,
                                      block_number,
                                      &es_port_file_read,
                                      fp,
                                      &bytes_read);

        sdr_client.transport_layer->send(&conn, buff, buff_size);
        if (bytes_read < ES_TFTP_BLOCK_SIZE)
        {
            transfer_finished = true;
        }
    }

    if (FM_RES_OK != es_port_file_close(fp))
    {
        ES_LOG_MSG(ES_ERROR, "Failed to close destination file");
        ret = ES_TFTP_FAILED_TO_CLOSE_DEST_FILE;
    }
    sdr_client.transport_layer->disconnect(&conn);

    return ret;
}

es_sdr_rpc_code_t es_sdr_client_rpc(uint32_t service_id, uint32_t rpc_id, void *req, void *res)
{
    es_sdr_rpc_code_t          ret = ES_RPC_OK;
    uint8_t                    o_buffer[SDR_CSP_MTU];
    int32_t                    o_buffer_size = 0;
    uint8_t                    i_buffer[SDR_CSP_MTU];
    int32_t                    i_buffer_size = 0;
    es_services_routing_pdu_t *i_pdu         = NULL;
    es_service_conn_statuses_t conn_status   = ES_SERVICE_CONN_UNKNOW_ERR;
    es_sdr_client_conn_t       conn          = es_sdr_client_conn_init_default;

    conn.dest_port = sdr_client.transport_layer->get_port(ES_SDR_CLIENT_RPC);

    /*
    * initialize i/o buffers
    */
    memset(o_buffer, 0, SDR_CSP_MTU);
    memset(i_buffer, 0, SDR_CSP_MTU);

    /*
     * 1. Encode
     * 2. Send
     * 3. Recv
     * 4. Decode
     * 5. Check input PDU status
     */

    o_buffer_size = es_sdr_client_encode(service_id, rpc_id, req, o_buffer);
    if (0 >= o_buffer_size)
    {
        ret = ES_RPC_ENCODE_FAILED;
        return ret;
    }

    es_tftp_err_code_t send_ret = es_sdr_client_send(&conn, o_buffer, o_buffer_size);
    if (ES_TFTP_STATUS_OK != send_ret)
    {
        ret = ES_RPC_SEND_FAILED;
        return ret;
    }

    es_tftp_err_code_t recv_ret = es_sdr_client_recv(&conn, i_buffer, &i_buffer_size, sizeof(i_buffer));
    if (ES_TFTP_STATUS_OK != recv_ret)
    {
        ret = ES_RPC_RECV_FAILED;
        return ret;
    }

    int8_t decode_ret = es_sdr_client_decode(service_id, rpc_id, i_buffer, res);
    if (0 != decode_ret)
    {
        ret = ES_RPC_DECODE_FAILED;
        return ret;
    }

    i_pdu            = es_services_routing_pdu_new((uint8_t *)i_buffer);
    conn_status      = es_services_routing_pdu_conn_status_get(i_pdu);
    int8_t parse_ret = es_client_parse_conn_status(conn_status);

    if (0 != parse_ret)
    {
        ret = ES_RPC_SERVICE_CONNECTION_STATUS_PARSE_ERR;
        return ret;
    }

    return ret;
}

es_tftp_err_code_t es_sdr_client_send_pdu(void *conn, int service_id, char *o_buffer, uint32_t o_buffer_size)
{
    int8_t ret = 0;
    char buffer[SDR_CSP_MTU];
    es_services_routing_pdu_t *o_pdu = NULL;
    size_t o_pdu_size = 0;

    es_sdr_client_conn_t *_conn = (es_sdr_client_conn_t *)conn;
    _conn->dest_port = sdr_client.transport_layer->get_port(ES_SDR_CLIENT_RPC);

    o_pdu = es_services_routing_pdu_new((uint8_t *)buffer);
    o_pdu->service_port = es_service_port_get(service_id);

    memcpy(o_pdu->data, o_buffer, o_buffer_size);
    o_pdu->data_length = o_buffer_size;
    o_pdu_size = o_pdu->data_length + sizeof(es_services_routing_pdu_t);

    ret = es_sdr_client_send(_conn, (uint8_t *)o_pdu, o_pdu_size);

    return ret;
}

int8_t es_sdr_client_recv_pdu(void *conn, char *i_buffer, uint32_t *i_buffer_size)
{
    int ret = -1;

    char buffer[SDR_CSP_MTU];
    int32_t buffer_size = 0;
    es_services_routing_pdu_t *i_pdu = NULL;
    es_service_conn_statuses_t conn_status = ES_SERVICE_CONN_UNKNOW_ERR;
    es_sdr_client_conn_t *_conn = (es_sdr_client_conn_t *)conn;

    /* Check recv status */
    ret = es_sdr_client_recv(_conn, (uint8_t *)buffer, &buffer_size, sizeof(buffer));

    i_pdu = es_services_routing_pdu_new((uint8_t *)buffer);
    conn_status = es_services_routing_pdu_conn_status_get(i_pdu);
    ret = es_client_parse_conn_status(conn_status);

    if (0 == ret)
    {
        memcpy(i_buffer, i_pdu->data, i_pdu->data_length);
        *i_buffer_size = i_pdu->data_length;
    }
    return ret;
}
