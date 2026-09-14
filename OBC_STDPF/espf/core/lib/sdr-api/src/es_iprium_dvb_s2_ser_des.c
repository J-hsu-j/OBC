/* Automatically generated. Do not edit manually */

/******************************** INCLUDE FILES *******************************/
#include <pb_encode.h>
#include <pb_decode.h>

#include "es_sdr_client_tl_iface.h"
/* Client interface for passing commands */
#include "es_iprium_dvb_s2_ser_des.h"

/* Protocol definitions */
#include "es_iprium_dvb_s2.pb.h"

#include "es_log.h"
/******************************** LOCAL DEFINES *******************************/
#define ES_MODULE_NAME  "es_iprium_dvb_s2"

/******************************* LOCAL TYPEDEFS *******************************/

/********************************* LOCAL DATA *********************************/

/******************************* LOCAL FUNCTIONS ******************************/

static int __es_iprium_dvb_s2_ser(int rpc_id, char *req_buffer, void *in_msg)
{
    int status = -1;
    pb_ostream_t o_stream;

    es_iprium_dvb_s2_rpc es_iprium_dvb_s2 = es_iprium_dvb_s2_rpc_init_zero;

    ES_LOG_MSG(ES_TRACE, " [%s] ", __func__);

    /*
     * RPC Encapsulation
     */

    switch(rpc_id)
    {
        case es_iprium_dvb_s2_rpc_dvb_s2_core0_set_tag:
            es_iprium_dvb_s2.which_rpc = es_iprium_dvb_s2_rpc_dvb_s2_core0_set_tag;
            es_iprium_dvb_s2.rpc.dvb_s2_core0_set.which_payload = dvb_s2_core0_set_rpc_req_tag;
            es_iprium_dvb_s2.rpc.dvb_s2_core0_set.payload.req = *(es_dvb_s2_core0_set_req *)in_msg;
            es_iprium_dvb_s2.rpc.dvb_s2_core0_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_iprium_dvb_s2_rpc_dvb_s2_core0_get_tag:
            es_iprium_dvb_s2.which_rpc = es_iprium_dvb_s2_rpc_dvb_s2_core0_get_tag;
            es_iprium_dvb_s2.rpc.dvb_s2_core0_get.which_payload = dvb_s2_core0_get_rpc_req_tag;
            es_iprium_dvb_s2.rpc.dvb_s2_core0_get.payload.req = *(es_dvb_s2_core0_get_req *)in_msg;
            es_iprium_dvb_s2.rpc.dvb_s2_core0_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_iprium_dvb_s2_rpc_tsgen_set_tag:
            es_iprium_dvb_s2.which_rpc = es_iprium_dvb_s2_rpc_tsgen_set_tag;
            es_iprium_dvb_s2.rpc.tsgen_set.which_payload = tsgen_set_rpc_req_tag;
            es_iprium_dvb_s2.rpc.tsgen_set.payload.req = *(es_tsgen_set_req *)in_msg;
            es_iprium_dvb_s2.rpc.tsgen_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_iprium_dvb_s2_rpc_tsgen_get_tag:
            es_iprium_dvb_s2.which_rpc = es_iprium_dvb_s2_rpc_tsgen_get_tag;
            es_iprium_dvb_s2.rpc.tsgen_get.which_payload = tsgen_get_rpc_req_tag;
            es_iprium_dvb_s2.rpc.tsgen_get.payload.req = *(es_tsgen_get_req *)in_msg;
            es_iprium_dvb_s2.rpc.tsgen_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_iprium_dvb_s2_rpc_clk_wiz_set_tag:
            es_iprium_dvb_s2.which_rpc = es_iprium_dvb_s2_rpc_clk_wiz_set_tag;
            es_iprium_dvb_s2.rpc.clk_wiz_set.which_payload = clk_wiz_set_rpc_req_tag;
            es_iprium_dvb_s2.rpc.clk_wiz_set.payload.req = *(es_clk_wiz_set_req *)in_msg;
            es_iprium_dvb_s2.rpc.clk_wiz_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_iprium_dvb_s2_rpc_clk_wiz_get_tag:
            es_iprium_dvb_s2.which_rpc = es_iprium_dvb_s2_rpc_clk_wiz_get_tag;
            es_iprium_dvb_s2.rpc.clk_wiz_get.which_payload = clk_wiz_get_rpc_req_tag;
            es_iprium_dvb_s2.rpc.clk_wiz_get.payload.req = *(es_clk_wiz_get_req *)in_msg;
            es_iprium_dvb_s2.rpc.clk_wiz_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_iprium_dvb_s2_rpc_xbar_set_tag:
            es_iprium_dvb_s2.which_rpc = es_iprium_dvb_s2_rpc_xbar_set_tag;
            es_iprium_dvb_s2.rpc.xbar_set.which_payload = xbar_set_rpc_req_tag;
            es_iprium_dvb_s2.rpc.xbar_set.payload.req = *(es_xbar_set_req *)in_msg;
            es_iprium_dvb_s2.rpc.xbar_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_iprium_dvb_s2_rpc_xbar_get_tag:
            es_iprium_dvb_s2.which_rpc = es_iprium_dvb_s2_rpc_xbar_get_tag;
            es_iprium_dvb_s2.rpc.xbar_get.which_payload = xbar_get_rpc_req_tag;
            es_iprium_dvb_s2.rpc.xbar_get.payload.req = *(es_xbar_get_req *)in_msg;
            es_iprium_dvb_s2.rpc.xbar_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;


        default:
            ES_LOG_MSG(ES_ERROR, "Invalid RPC id: %d\n", rpc_id);
            return -1;
    }

    /* Set out stream encoder */
    o_stream = pb_ostream_from_buffer((pb_byte_t *)req_buffer, CLIENT_IO_BUFFER_SIZE);

    /* Now we are ready to encode the message */
    status = pb_encode_delimited(&o_stream, es_iprium_dvb_s2_rpc_fields, &es_iprium_dvb_s2);
    if (!status)
    {
        ES_LOG_MSG(ES_ERROR, "Failed to encode message %s", PB_GET_ERROR(&o_stream));
        return -1;
    }

    return o_stream.bytes_written;
}

static int __es_iprium_dvb_s2_des(int rpc_id, char *res_buffer, void *out_msg)
{
    int status = 0;
    pb_istream_t i_stream;

    es_iprium_dvb_s2_rpc es_iprium_dvb_s2 = es_iprium_dvb_s2_rpc_init_zero;

    ES_LOG_MSG(ES_TRACE, " [%s] ", __func__);

    /* Create a stream that will read from our buffer. */
    i_stream = pb_istream_from_buffer((pb_byte_t *)res_buffer, CLIENT_IO_BUFFER_SIZE);

    /* The input message starts with the message size as varint. */
    status = pb_decode_delimited(&i_stream, es_iprium_dvb_s2_rpc_fields, &es_iprium_dvb_s2);
    if (!status)
    {
        ES_LOG_MSG(ES_ERROR, "Failed to decode message %s", PB_GET_ERROR(&i_stream));
        return -1;
    }

    switch(rpc_id)
    {
        case es_iprium_dvb_s2_rpc_dvb_s2_core0_set_tag:
            if (es_iprium_dvb_s2.which_rpc != es_iprium_dvb_s2_rpc_dvb_s2_core0_set_tag ||
                es_iprium_dvb_s2.rpc.dvb_s2_core0_set.which_payload != dvb_s2_core0_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_dvb_s2_core0_set_res *)out_msg = es_iprium_dvb_s2.rpc.dvb_s2_core0_set.payload.res;
            break;
        case es_iprium_dvb_s2_rpc_dvb_s2_core0_get_tag:
            if (es_iprium_dvb_s2.which_rpc != es_iprium_dvb_s2_rpc_dvb_s2_core0_get_tag ||
                es_iprium_dvb_s2.rpc.dvb_s2_core0_get.which_payload != dvb_s2_core0_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_dvb_s2_core0_get_res *)out_msg = es_iprium_dvb_s2.rpc.dvb_s2_core0_get.payload.res;
            break;
        case es_iprium_dvb_s2_rpc_tsgen_set_tag:
            if (es_iprium_dvb_s2.which_rpc != es_iprium_dvb_s2_rpc_tsgen_set_tag ||
                es_iprium_dvb_s2.rpc.tsgen_set.which_payload != tsgen_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_tsgen_set_res *)out_msg = es_iprium_dvb_s2.rpc.tsgen_set.payload.res;
            break;
        case es_iprium_dvb_s2_rpc_tsgen_get_tag:
            if (es_iprium_dvb_s2.which_rpc != es_iprium_dvb_s2_rpc_tsgen_get_tag ||
                es_iprium_dvb_s2.rpc.tsgen_get.which_payload != tsgen_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_tsgen_get_res *)out_msg = es_iprium_dvb_s2.rpc.tsgen_get.payload.res;
            break;
        case es_iprium_dvb_s2_rpc_clk_wiz_set_tag:
            if (es_iprium_dvb_s2.which_rpc != es_iprium_dvb_s2_rpc_clk_wiz_set_tag ||
                es_iprium_dvb_s2.rpc.clk_wiz_set.which_payload != clk_wiz_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_clk_wiz_set_res *)out_msg = es_iprium_dvb_s2.rpc.clk_wiz_set.payload.res;
            break;
        case es_iprium_dvb_s2_rpc_clk_wiz_get_tag:
            if (es_iprium_dvb_s2.which_rpc != es_iprium_dvb_s2_rpc_clk_wiz_get_tag ||
                es_iprium_dvb_s2.rpc.clk_wiz_get.which_payload != clk_wiz_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_clk_wiz_get_res *)out_msg = es_iprium_dvb_s2.rpc.clk_wiz_get.payload.res;
            break;
        case es_iprium_dvb_s2_rpc_xbar_set_tag:
            if (es_iprium_dvb_s2.which_rpc != es_iprium_dvb_s2_rpc_xbar_set_tag ||
                es_iprium_dvb_s2.rpc.xbar_set.which_payload != xbar_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_xbar_set_res *)out_msg = es_iprium_dvb_s2.rpc.xbar_set.payload.res;
            break;
        case es_iprium_dvb_s2_rpc_xbar_get_tag:
            if (es_iprium_dvb_s2.which_rpc != es_iprium_dvb_s2_rpc_xbar_get_tag ||
                es_iprium_dvb_s2.rpc.xbar_get.which_payload != xbar_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_xbar_get_res *)out_msg = es_iprium_dvb_s2.rpc.xbar_get.payload.res;
            break;


        default:
            ES_LOG_MSG(ES_ERROR, "Invalid RPC id: %d\n", rpc_id);
            return -1;
    }

    return 0;
}

static es_ser_des_t es_iprium_dvb_s2_serdes = {
    .ser = __es_iprium_dvb_s2_ser,
    .des = __es_iprium_dvb_s2_des,
};

/***************************** INTERFACE FUNCTIONS ****************************/
es_ser_des_t *es_iprium_dvb_s2_ser_des_get_hndlrs(void)
{
    return &es_iprium_dvb_s2_serdes;
}
