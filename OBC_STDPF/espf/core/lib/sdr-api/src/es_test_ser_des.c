/* Automatically generated. Do not edit manually */

/******************************** INCLUDE FILES *******************************/
#include <pb_encode.h>
#include <pb_decode.h>

#include "es_sdr_client_tl_iface.h"
/* Client interface for passing commands */
#include "es_test_ser_des.h"

/* Protocol definitions */
#include "es_test.pb.h"

#include "es_log.h"
/******************************** LOCAL DEFINES *******************************/
#define ES_MODULE_NAME  "es_test"

/******************************* LOCAL TYPEDEFS *******************************/

/********************************* LOCAL DATA *********************************/

/******************************* LOCAL FUNCTIONS ******************************/

static int __es_test_ser(int rpc_id, char *req_buffer, void *in_msg)
{
    int status = -1;
    pb_ostream_t o_stream;

    es_test_rpc es_test = es_test_rpc_init_zero;

    ES_LOG_MSG(ES_TRACE, " [%s] ", __func__);

    /*
     * RPC Encapsulation
     */

    switch(rpc_id)
    {
        case es_test_rpc_loopback_tag:
            es_test.which_rpc = es_test_rpc_loopback_tag;
            es_test.rpc.loopback.which_payload = loopback_rpc_req_tag;
            es_test.rpc.loopback.payload.req = *(es_loopback_req *)in_msg;
            es_test.rpc.loopback.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_test_rpc_test_cfg_set_tag:
            es_test.which_rpc = es_test_rpc_test_cfg_set_tag;
            es_test.rpc.test_cfg_set.which_payload = test_cfg_set_rpc_req_tag;
            es_test.rpc.test_cfg_set.payload.req = *(es_test_cfg_set_req *)in_msg;
            es_test.rpc.test_cfg_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_test_rpc_test_cfg_get_tag:
            es_test.which_rpc = es_test_rpc_test_cfg_get_tag;
            es_test.rpc.test_cfg_get.which_payload = test_cfg_get_rpc_req_tag;
            es_test.rpc.test_cfg_get.payload.req = *(es_test_cfg_get_req *)in_msg;
            es_test.rpc.test_cfg_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_test_rpc_hello_test_tag:
            es_test.which_rpc = es_test_rpc_hello_test_tag;
            es_test.rpc.hello_test.which_payload = hello_test_rpc_req_tag;
            es_test.rpc.hello_test.payload.req = *(es_hello_test_req *)in_msg;
            es_test.rpc.hello_test.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;


        default:
            ES_LOG_MSG(ES_ERROR, "Invalid RPC id: %d\n", rpc_id);
            return -1;
    }

    /* Set out stream encoder */
    o_stream = pb_ostream_from_buffer((pb_byte_t *)req_buffer, CLIENT_IO_BUFFER_SIZE);

    /* Now we are ready to encode the message */
    status = pb_encode_delimited(&o_stream, es_test_rpc_fields, &es_test);
    if (!status)
    {
        ES_LOG_MSG(ES_ERROR, "Failed to encode message %s", PB_GET_ERROR(&o_stream));
        return -1;
    }

    return o_stream.bytes_written;
}

static int __es_test_des(int rpc_id, char *res_buffer, void *out_msg)
{
    int status = 0;
    pb_istream_t i_stream;

    es_test_rpc es_test = es_test_rpc_init_zero;

    ES_LOG_MSG(ES_TRACE, " [%s] ", __func__);

    /* Create a stream that will read from our buffer. */
    i_stream = pb_istream_from_buffer((pb_byte_t *)res_buffer, CLIENT_IO_BUFFER_SIZE);

    /* The input message starts with the message size as varint. */
    status = pb_decode_delimited(&i_stream, es_test_rpc_fields, &es_test);
    if (!status)
    {
        ES_LOG_MSG(ES_ERROR, "Failed to decode message %s", PB_GET_ERROR(&i_stream));
        return -1;
    }

    switch(rpc_id)
    {
        case es_test_rpc_loopback_tag:
            if (es_test.which_rpc != es_test_rpc_loopback_tag ||
                es_test.rpc.loopback.which_payload != loopback_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_loopback_res *)out_msg = es_test.rpc.loopback.payload.res;
            break;
        case es_test_rpc_test_cfg_set_tag:
            if (es_test.which_rpc != es_test_rpc_test_cfg_set_tag ||
                es_test.rpc.test_cfg_set.which_payload != test_cfg_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_test_cfg_set_res *)out_msg = es_test.rpc.test_cfg_set.payload.res;
            break;
        case es_test_rpc_test_cfg_get_tag:
            if (es_test.which_rpc != es_test_rpc_test_cfg_get_tag ||
                es_test.rpc.test_cfg_get.which_payload != test_cfg_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_test_cfg_get_res *)out_msg = es_test.rpc.test_cfg_get.payload.res;
            break;
        case es_test_rpc_hello_test_tag:
            if (es_test.which_rpc != es_test_rpc_hello_test_tag ||
                es_test.rpc.hello_test.which_payload != hello_test_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_hello_test_res *)out_msg = es_test.rpc.hello_test.payload.res;
            break;


        default:
            ES_LOG_MSG(ES_ERROR, "Invalid RPC id: %d\n", rpc_id);
            return -1;
    }

    return 0;
}

static es_ser_des_t es_test_serdes = {
    .ser = __es_test_ser,
    .des = __es_test_des,
};

/***************************** INTERFACE FUNCTIONS ****************************/
es_ser_des_t *es_test_ser_des_get_hndlrs(void)
{
    return &es_test_serdes;
}
