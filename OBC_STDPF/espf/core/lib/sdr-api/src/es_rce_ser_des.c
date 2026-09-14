/* Automatically generated. Do not edit manually */

/******************************** INCLUDE FILES *******************************/
#include <pb_encode.h>
#include <pb_decode.h>

#include "es_sdr_client_tl_iface.h"
/* Client interface for passing commands */
#include "es_rce_ser_des.h"

/* Protocol definitions */
#include "es_rce.pb.h"

#include "es_log.h"
/******************************** LOCAL DEFINES *******************************/
#define ES_MODULE_NAME  "es_rce"

/******************************* LOCAL TYPEDEFS *******************************/

/********************************* LOCAL DATA *********************************/

/******************************* LOCAL FUNCTIONS ******************************/

static int __es_rce_ser(int rpc_id, char *req_buffer, void *in_msg)
{
    int status = -1;
    pb_ostream_t o_stream;

    es_rce_rpc es_rce = es_rce_rpc_init_zero;

    ES_LOG_MSG(ES_TRACE, " [%s] ", __func__);

    /*
     * RPC Encapsulation
     */

    switch(rpc_id)
    {
        case es_rce_rpc_cmd_exec_tag:
            es_rce.which_rpc = es_rce_rpc_cmd_exec_tag;
            es_rce.rpc.cmd_exec.which_payload = cmd_exec_rpc_req_tag;
            es_rce.rpc.cmd_exec.payload.req = *(es_cmd_exec_req *)in_msg;
            es_rce.rpc.cmd_exec.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_rce_rpc_cmd_get_status_tag:
            es_rce.which_rpc = es_rce_rpc_cmd_get_status_tag;
            es_rce.rpc.cmd_get_status.which_payload = cmd_get_status_rpc_req_tag;
            es_rce.rpc.cmd_get_status.payload.req = *(es_cmd_get_status_req *)in_msg;
            es_rce.rpc.cmd_get_status.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;


        default:
            ES_LOG_MSG(ES_ERROR, "Invalid RPC id: %d\n", rpc_id);
            return -1;
    }

    /* Set out stream encoder */
    o_stream = pb_ostream_from_buffer((pb_byte_t *)req_buffer, CLIENT_IO_BUFFER_SIZE);

    /* Now we are ready to encode the message */
    status = pb_encode_delimited(&o_stream, es_rce_rpc_fields, &es_rce);
    if (!status)
    {
        ES_LOG_MSG(ES_ERROR, "Failed to encode message %s", PB_GET_ERROR(&o_stream));
        return -1;
    }

    return o_stream.bytes_written;
}

static int __es_rce_des(int rpc_id, char *res_buffer, void *out_msg)
{
    int status = 0;
    pb_istream_t i_stream;

    es_rce_rpc es_rce = es_rce_rpc_init_zero;

    ES_LOG_MSG(ES_TRACE, " [%s] ", __func__);

    /* Create a stream that will read from our buffer. */
    i_stream = pb_istream_from_buffer((pb_byte_t *)res_buffer, CLIENT_IO_BUFFER_SIZE);

    /* The input message starts with the message size as varint. */
    status = pb_decode_delimited(&i_stream, es_rce_rpc_fields, &es_rce);
    if (!status)
    {
        ES_LOG_MSG(ES_ERROR, "Failed to decode message %s", PB_GET_ERROR(&i_stream));
        return -1;
    }

    switch(rpc_id)
    {
        case es_rce_rpc_cmd_exec_tag:
            if (es_rce.which_rpc != es_rce_rpc_cmd_exec_tag ||
                es_rce.rpc.cmd_exec.which_payload != cmd_exec_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_cmd_exec_res *)out_msg = es_rce.rpc.cmd_exec.payload.res;
            break;
        case es_rce_rpc_cmd_get_status_tag:
            if (es_rce.which_rpc != es_rce_rpc_cmd_get_status_tag ||
                es_rce.rpc.cmd_get_status.which_payload != cmd_get_status_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_cmd_get_status_res *)out_msg = es_rce.rpc.cmd_get_status.payload.res;
            break;


        default:
            ES_LOG_MSG(ES_ERROR, "Invalid RPC id: %d\n", rpc_id);
            return -1;
    }

    return 0;
}

static es_ser_des_t es_rce_serdes = {
    .ser = __es_rce_ser,
    .des = __es_rce_des,
};

/***************************** INTERFACE FUNCTIONS ****************************/
es_ser_des_t *es_rce_ser_des_get_hndlrs(void)
{
    return &es_rce_serdes;
}
