/* Automatically generated. Do not edit manually */

/******************************** INCLUDE FILES *******************************/
#include <pb_encode.h>
#include <pb_decode.h>

#include "es_sdr_client_tl_iface.h"
/* Client interface for passing commands */
#include "es_adrv9009_ser_des.h"

/* Protocol definitions */
#include "es_adrv9009.pb.h"

#include "es_log.h"
/******************************** LOCAL DEFINES *******************************/
#define ES_MODULE_NAME  "es_adrv9009"

/******************************* LOCAL TYPEDEFS *******************************/

/********************************* LOCAL DATA *********************************/

/******************************* LOCAL FUNCTIONS ******************************/

static int __es_adrv9009_ser(int rpc_id, char *req_buffer, void *in_msg)
{
    int status = -1;
    pb_ostream_t o_stream;

    es_adrv9009_rpc es_adrv9009 = es_adrv9009_rpc_init_zero;

    ES_LOG_MSG(ES_TRACE, " [%s] ", __func__);

    /*
     * RPC Encapsulation
     */

    switch(rpc_id)
    {
        case es_adrv9009_rpc_phya_telemetry_get_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phya_telemetry_get_tag;
            es_adrv9009.rpc.phya_telemetry_get.which_payload = phya_telemetry_get_rpc_req_tag;
            es_adrv9009.rpc.phya_telemetry_get.payload.req = *(es_phya_telemetry_get_req *)in_msg;
            es_adrv9009.rpc.phya_telemetry_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phyb_telemetry_get_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phyb_telemetry_get_tag;
            es_adrv9009.rpc.phyb_telemetry_get.which_payload = phyb_telemetry_get_rpc_req_tag;
            es_adrv9009.rpc.phyb_telemetry_get.payload.req = *(es_phyb_telemetry_get_req *)in_msg;
            es_adrv9009.rpc.phyb_telemetry_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phya_altvoltage0_set_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phya_altvoltage0_set_tag;
            es_adrv9009.rpc.phya_altvoltage0_set.which_payload = phya_altvoltage0_set_rpc_req_tag;
            es_adrv9009.rpc.phya_altvoltage0_set.payload.req = *(es_phya_altvoltage0_set_req *)in_msg;
            es_adrv9009.rpc.phya_altvoltage0_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phya_altvoltage0_get_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phya_altvoltage0_get_tag;
            es_adrv9009.rpc.phya_altvoltage0_get.which_payload = phya_altvoltage0_get_rpc_req_tag;
            es_adrv9009.rpc.phya_altvoltage0_get.payload.req = *(es_phya_altvoltage0_get_req *)in_msg;
            es_adrv9009.rpc.phya_altvoltage0_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phyb_altvoltage0_set_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phyb_altvoltage0_set_tag;
            es_adrv9009.rpc.phyb_altvoltage0_set.which_payload = phyb_altvoltage0_set_rpc_req_tag;
            es_adrv9009.rpc.phyb_altvoltage0_set.payload.req = *(es_phyb_altvoltage0_set_req *)in_msg;
            es_adrv9009.rpc.phyb_altvoltage0_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phyb_altvoltage0_get_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phyb_altvoltage0_get_tag;
            es_adrv9009.rpc.phyb_altvoltage0_get.which_payload = phyb_altvoltage0_get_rpc_req_tag;
            es_adrv9009.rpc.phyb_altvoltage0_get.payload.req = *(es_phyb_altvoltage0_get_req *)in_msg;
            es_adrv9009.rpc.phyb_altvoltage0_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phya_tx1out_voltage0_set_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phya_tx1out_voltage0_set_tag;
            es_adrv9009.rpc.phya_tx1out_voltage0_set.which_payload = phya_tx1out_voltage0_set_rpc_req_tag;
            es_adrv9009.rpc.phya_tx1out_voltage0_set.payload.req = *(es_phya_tx1out_voltage0_set_req *)in_msg;
            es_adrv9009.rpc.phya_tx1out_voltage0_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phya_tx1out_voltage0_get_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phya_tx1out_voltage0_get_tag;
            es_adrv9009.rpc.phya_tx1out_voltage0_get.which_payload = phya_tx1out_voltage0_get_rpc_req_tag;
            es_adrv9009.rpc.phya_tx1out_voltage0_get.payload.req = *(es_phya_tx1out_voltage0_get_req *)in_msg;
            es_adrv9009.rpc.phya_tx1out_voltage0_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phyb_tx1out_voltage0_set_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phyb_tx1out_voltage0_set_tag;
            es_adrv9009.rpc.phyb_tx1out_voltage0_set.which_payload = phyb_tx1out_voltage0_set_rpc_req_tag;
            es_adrv9009.rpc.phyb_tx1out_voltage0_set.payload.req = *(es_phyb_tx1out_voltage0_set_req *)in_msg;
            es_adrv9009.rpc.phyb_tx1out_voltage0_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phyb_tx1out_voltage0_get_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phyb_tx1out_voltage0_get_tag;
            es_adrv9009.rpc.phyb_tx1out_voltage0_get.which_payload = phyb_tx1out_voltage0_get_rpc_req_tag;
            es_adrv9009.rpc.phyb_tx1out_voltage0_get.payload.req = *(es_phyb_tx1out_voltage0_get_req *)in_msg;
            es_adrv9009.rpc.phyb_tx1out_voltage0_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phya_tx2out_voltage1_set_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phya_tx2out_voltage1_set_tag;
            es_adrv9009.rpc.phya_tx2out_voltage1_set.which_payload = phya_tx2out_voltage1_set_rpc_req_tag;
            es_adrv9009.rpc.phya_tx2out_voltage1_set.payload.req = *(es_phya_tx2out_voltage1_set_req *)in_msg;
            es_adrv9009.rpc.phya_tx2out_voltage1_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phya_tx2out_voltage1_get_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phya_tx2out_voltage1_get_tag;
            es_adrv9009.rpc.phya_tx2out_voltage1_get.which_payload = phya_tx2out_voltage1_get_rpc_req_tag;
            es_adrv9009.rpc.phya_tx2out_voltage1_get.payload.req = *(es_phya_tx2out_voltage1_get_req *)in_msg;
            es_adrv9009.rpc.phya_tx2out_voltage1_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phyb_tx2out_voltage1_set_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phyb_tx2out_voltage1_set_tag;
            es_adrv9009.rpc.phyb_tx2out_voltage1_set.which_payload = phyb_tx2out_voltage1_set_rpc_req_tag;
            es_adrv9009.rpc.phyb_tx2out_voltage1_set.payload.req = *(es_phyb_tx2out_voltage1_set_req *)in_msg;
            es_adrv9009.rpc.phyb_tx2out_voltage1_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phyb_tx2out_voltage1_get_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phyb_tx2out_voltage1_get_tag;
            es_adrv9009.rpc.phyb_tx2out_voltage1_get.which_payload = phyb_tx2out_voltage1_get_rpc_req_tag;
            es_adrv9009.rpc.phyb_tx2out_voltage1_get.payload.req = *(es_phyb_tx2out_voltage1_get_req *)in_msg;
            es_adrv9009.rpc.phyb_tx2out_voltage1_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phya_orx1in_voltage2_set_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phya_orx1in_voltage2_set_tag;
            es_adrv9009.rpc.phya_orx1in_voltage2_set.which_payload = phya_orx1in_voltage2_set_rpc_req_tag;
            es_adrv9009.rpc.phya_orx1in_voltage2_set.payload.req = *(es_phya_orx1in_voltage2_set_req *)in_msg;
            es_adrv9009.rpc.phya_orx1in_voltage2_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phya_orx1in_voltage2_get_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phya_orx1in_voltage2_get_tag;
            es_adrv9009.rpc.phya_orx1in_voltage2_get.which_payload = phya_orx1in_voltage2_get_rpc_req_tag;
            es_adrv9009.rpc.phya_orx1in_voltage2_get.payload.req = *(es_phya_orx1in_voltage2_get_req *)in_msg;
            es_adrv9009.rpc.phya_orx1in_voltage2_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phyb_orx1in_voltage2_set_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phyb_orx1in_voltage2_set_tag;
            es_adrv9009.rpc.phyb_orx1in_voltage2_set.which_payload = phyb_orx1in_voltage2_set_rpc_req_tag;
            es_adrv9009.rpc.phyb_orx1in_voltage2_set.payload.req = *(es_phyb_orx1in_voltage2_set_req *)in_msg;
            es_adrv9009.rpc.phyb_orx1in_voltage2_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phyb_orx1in_voltage2_get_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phyb_orx1in_voltage2_get_tag;
            es_adrv9009.rpc.phyb_orx1in_voltage2_get.which_payload = phyb_orx1in_voltage2_get_rpc_req_tag;
            es_adrv9009.rpc.phyb_orx1in_voltage2_get.payload.req = *(es_phyb_orx1in_voltage2_get_req *)in_msg;
            es_adrv9009.rpc.phyb_orx1in_voltage2_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phya_orx2in_voltage3_set_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phya_orx2in_voltage3_set_tag;
            es_adrv9009.rpc.phya_orx2in_voltage3_set.which_payload = phya_orx2in_voltage3_set_rpc_req_tag;
            es_adrv9009.rpc.phya_orx2in_voltage3_set.payload.req = *(es_phya_orx2in_voltage3_set_req *)in_msg;
            es_adrv9009.rpc.phya_orx2in_voltage3_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phya_orx2in_voltage3_get_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phya_orx2in_voltage3_get_tag;
            es_adrv9009.rpc.phya_orx2in_voltage3_get.which_payload = phya_orx2in_voltage3_get_rpc_req_tag;
            es_adrv9009.rpc.phya_orx2in_voltage3_get.payload.req = *(es_phya_orx2in_voltage3_get_req *)in_msg;
            es_adrv9009.rpc.phya_orx2in_voltage3_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phyb_orx2in_voltage3_set_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phyb_orx2in_voltage3_set_tag;
            es_adrv9009.rpc.phyb_orx2in_voltage3_set.which_payload = phyb_orx2in_voltage3_set_rpc_req_tag;
            es_adrv9009.rpc.phyb_orx2in_voltage3_set.payload.req = *(es_phyb_orx2in_voltage3_set_req *)in_msg;
            es_adrv9009.rpc.phyb_orx2in_voltage3_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phyb_orx2in_voltage3_get_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phyb_orx2in_voltage3_get_tag;
            es_adrv9009.rpc.phyb_orx2in_voltage3_get.which_payload = phyb_orx2in_voltage3_get_rpc_req_tag;
            es_adrv9009.rpc.phyb_orx2in_voltage3_get.payload.req = *(es_phyb_orx2in_voltage3_get_req *)in_msg;
            es_adrv9009.rpc.phyb_orx2in_voltage3_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phya_rx1in_voltage0_set_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phya_rx1in_voltage0_set_tag;
            es_adrv9009.rpc.phya_rx1in_voltage0_set.which_payload = phya_rx1in_voltage0_set_rpc_req_tag;
            es_adrv9009.rpc.phya_rx1in_voltage0_set.payload.req = *(es_phya_rx1in_voltage0_set_req *)in_msg;
            es_adrv9009.rpc.phya_rx1in_voltage0_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phya_rx1in_voltage0_get_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phya_rx1in_voltage0_get_tag;
            es_adrv9009.rpc.phya_rx1in_voltage0_get.which_payload = phya_rx1in_voltage0_get_rpc_req_tag;
            es_adrv9009.rpc.phya_rx1in_voltage0_get.payload.req = *(es_phya_rx1in_voltage0_get_req *)in_msg;
            es_adrv9009.rpc.phya_rx1in_voltage0_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phyb_rx1in_voltage0_set_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phyb_rx1in_voltage0_set_tag;
            es_adrv9009.rpc.phyb_rx1in_voltage0_set.which_payload = phyb_rx1in_voltage0_set_rpc_req_tag;
            es_adrv9009.rpc.phyb_rx1in_voltage0_set.payload.req = *(es_phyb_rx1in_voltage0_set_req *)in_msg;
            es_adrv9009.rpc.phyb_rx1in_voltage0_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phyb_rx1in_voltage0_get_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phyb_rx1in_voltage0_get_tag;
            es_adrv9009.rpc.phyb_rx1in_voltage0_get.which_payload = phyb_rx1in_voltage0_get_rpc_req_tag;
            es_adrv9009.rpc.phyb_rx1in_voltage0_get.payload.req = *(es_phyb_rx1in_voltage0_get_req *)in_msg;
            es_adrv9009.rpc.phyb_rx1in_voltage0_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phya_rx2in_voltage1_set_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phya_rx2in_voltage1_set_tag;
            es_adrv9009.rpc.phya_rx2in_voltage1_set.which_payload = phya_rx2in_voltage1_set_rpc_req_tag;
            es_adrv9009.rpc.phya_rx2in_voltage1_set.payload.req = *(es_phya_rx2in_voltage1_set_req *)in_msg;
            es_adrv9009.rpc.phya_rx2in_voltage1_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phya_rx2in_voltage1_get_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phya_rx2in_voltage1_get_tag;
            es_adrv9009.rpc.phya_rx2in_voltage1_get.which_payload = phya_rx2in_voltage1_get_rpc_req_tag;
            es_adrv9009.rpc.phya_rx2in_voltage1_get.payload.req = *(es_phya_rx2in_voltage1_get_req *)in_msg;
            es_adrv9009.rpc.phya_rx2in_voltage1_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phyb_rx2in_voltage1_set_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phyb_rx2in_voltage1_set_tag;
            es_adrv9009.rpc.phyb_rx2in_voltage1_set.which_payload = phyb_rx2in_voltage1_set_rpc_req_tag;
            es_adrv9009.rpc.phyb_rx2in_voltage1_set.payload.req = *(es_phyb_rx2in_voltage1_set_req *)in_msg;
            es_adrv9009.rpc.phyb_rx2in_voltage1_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_adrv9009_rpc_phyb_rx2in_voltage1_get_tag:
            es_adrv9009.which_rpc = es_adrv9009_rpc_phyb_rx2in_voltage1_get_tag;
            es_adrv9009.rpc.phyb_rx2in_voltage1_get.which_payload = phyb_rx2in_voltage1_get_rpc_req_tag;
            es_adrv9009.rpc.phyb_rx2in_voltage1_get.payload.req = *(es_phyb_rx2in_voltage1_get_req *)in_msg;
            es_adrv9009.rpc.phyb_rx2in_voltage1_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;


        default:
            ES_LOG_MSG(ES_ERROR, "Invalid RPC id: %d\n", rpc_id);
            return -1;
    }

    /* Set out stream encoder */
    o_stream = pb_ostream_from_buffer((pb_byte_t *)req_buffer, CLIENT_IO_BUFFER_SIZE);

    /* Now we are ready to encode the message */
    status = pb_encode_delimited(&o_stream, es_adrv9009_rpc_fields, &es_adrv9009);
    if (!status)
    {
        ES_LOG_MSG(ES_ERROR, "Failed to encode message %s", PB_GET_ERROR(&o_stream));
        return -1;
    }

    return o_stream.bytes_written;
}

static int __es_adrv9009_des(int rpc_id, char *res_buffer, void *out_msg)
{
    int status = 0;
    pb_istream_t i_stream;

    es_adrv9009_rpc es_adrv9009 = es_adrv9009_rpc_init_zero;

    ES_LOG_MSG(ES_TRACE, " [%s] ", __func__);

    /* Create a stream that will read from our buffer. */
    i_stream = pb_istream_from_buffer((pb_byte_t *)res_buffer, CLIENT_IO_BUFFER_SIZE);

    /* The input message starts with the message size as varint. */
    status = pb_decode_delimited(&i_stream, es_adrv9009_rpc_fields, &es_adrv9009);
    if (!status)
    {
        ES_LOG_MSG(ES_ERROR, "Failed to decode message %s", PB_GET_ERROR(&i_stream));
        return -1;
    }

    switch(rpc_id)
    {
        case es_adrv9009_rpc_phya_telemetry_get_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phya_telemetry_get_tag ||
                es_adrv9009.rpc.phya_telemetry_get.which_payload != phya_telemetry_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phya_telemetry_get_res *)out_msg = es_adrv9009.rpc.phya_telemetry_get.payload.res;
            break;
        case es_adrv9009_rpc_phyb_telemetry_get_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phyb_telemetry_get_tag ||
                es_adrv9009.rpc.phyb_telemetry_get.which_payload != phyb_telemetry_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phyb_telemetry_get_res *)out_msg = es_adrv9009.rpc.phyb_telemetry_get.payload.res;
            break;
        case es_adrv9009_rpc_phya_altvoltage0_set_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phya_altvoltage0_set_tag ||
                es_adrv9009.rpc.phya_altvoltage0_set.which_payload != phya_altvoltage0_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phya_altvoltage0_set_res *)out_msg = es_adrv9009.rpc.phya_altvoltage0_set.payload.res;
            break;
        case es_adrv9009_rpc_phya_altvoltage0_get_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phya_altvoltage0_get_tag ||
                es_adrv9009.rpc.phya_altvoltage0_get.which_payload != phya_altvoltage0_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phya_altvoltage0_get_res *)out_msg = es_adrv9009.rpc.phya_altvoltage0_get.payload.res;
            break;
        case es_adrv9009_rpc_phyb_altvoltage0_set_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phyb_altvoltage0_set_tag ||
                es_adrv9009.rpc.phyb_altvoltage0_set.which_payload != phyb_altvoltage0_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phyb_altvoltage0_set_res *)out_msg = es_adrv9009.rpc.phyb_altvoltage0_set.payload.res;
            break;
        case es_adrv9009_rpc_phyb_altvoltage0_get_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phyb_altvoltage0_get_tag ||
                es_adrv9009.rpc.phyb_altvoltage0_get.which_payload != phyb_altvoltage0_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phyb_altvoltage0_get_res *)out_msg = es_adrv9009.rpc.phyb_altvoltage0_get.payload.res;
            break;
        case es_adrv9009_rpc_phya_tx1out_voltage0_set_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phya_tx1out_voltage0_set_tag ||
                es_adrv9009.rpc.phya_tx1out_voltage0_set.which_payload != phya_tx1out_voltage0_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phya_tx1out_voltage0_set_res *)out_msg = es_adrv9009.rpc.phya_tx1out_voltage0_set.payload.res;
            break;
        case es_adrv9009_rpc_phya_tx1out_voltage0_get_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phya_tx1out_voltage0_get_tag ||
                es_adrv9009.rpc.phya_tx1out_voltage0_get.which_payload != phya_tx1out_voltage0_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phya_tx1out_voltage0_get_res *)out_msg = es_adrv9009.rpc.phya_tx1out_voltage0_get.payload.res;
            break;
        case es_adrv9009_rpc_phyb_tx1out_voltage0_set_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phyb_tx1out_voltage0_set_tag ||
                es_adrv9009.rpc.phyb_tx1out_voltage0_set.which_payload != phyb_tx1out_voltage0_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phyb_tx1out_voltage0_set_res *)out_msg = es_adrv9009.rpc.phyb_tx1out_voltage0_set.payload.res;
            break;
        case es_adrv9009_rpc_phyb_tx1out_voltage0_get_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phyb_tx1out_voltage0_get_tag ||
                es_adrv9009.rpc.phyb_tx1out_voltage0_get.which_payload != phyb_tx1out_voltage0_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phyb_tx1out_voltage0_get_res *)out_msg = es_adrv9009.rpc.phyb_tx1out_voltage0_get.payload.res;
            break;
        case es_adrv9009_rpc_phya_tx2out_voltage1_set_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phya_tx2out_voltage1_set_tag ||
                es_adrv9009.rpc.phya_tx2out_voltage1_set.which_payload != phya_tx2out_voltage1_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phya_tx2out_voltage1_set_res *)out_msg = es_adrv9009.rpc.phya_tx2out_voltage1_set.payload.res;
            break;
        case es_adrv9009_rpc_phya_tx2out_voltage1_get_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phya_tx2out_voltage1_get_tag ||
                es_adrv9009.rpc.phya_tx2out_voltage1_get.which_payload != phya_tx2out_voltage1_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phya_tx2out_voltage1_get_res *)out_msg = es_adrv9009.rpc.phya_tx2out_voltage1_get.payload.res;
            break;
        case es_adrv9009_rpc_phyb_tx2out_voltage1_set_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phyb_tx2out_voltage1_set_tag ||
                es_adrv9009.rpc.phyb_tx2out_voltage1_set.which_payload != phyb_tx2out_voltage1_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phyb_tx2out_voltage1_set_res *)out_msg = es_adrv9009.rpc.phyb_tx2out_voltage1_set.payload.res;
            break;
        case es_adrv9009_rpc_phyb_tx2out_voltage1_get_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phyb_tx2out_voltage1_get_tag ||
                es_adrv9009.rpc.phyb_tx2out_voltage1_get.which_payload != phyb_tx2out_voltage1_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phyb_tx2out_voltage1_get_res *)out_msg = es_adrv9009.rpc.phyb_tx2out_voltage1_get.payload.res;
            break;
        case es_adrv9009_rpc_phya_orx1in_voltage2_set_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phya_orx1in_voltage2_set_tag ||
                es_adrv9009.rpc.phya_orx1in_voltage2_set.which_payload != phya_orx1in_voltage2_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phya_orx1in_voltage2_set_res *)out_msg = es_adrv9009.rpc.phya_orx1in_voltage2_set.payload.res;
            break;
        case es_adrv9009_rpc_phya_orx1in_voltage2_get_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phya_orx1in_voltage2_get_tag ||
                es_adrv9009.rpc.phya_orx1in_voltage2_get.which_payload != phya_orx1in_voltage2_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phya_orx1in_voltage2_get_res *)out_msg = es_adrv9009.rpc.phya_orx1in_voltage2_get.payload.res;
            break;
        case es_adrv9009_rpc_phyb_orx1in_voltage2_set_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phyb_orx1in_voltage2_set_tag ||
                es_adrv9009.rpc.phyb_orx1in_voltage2_set.which_payload != phyb_orx1in_voltage2_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phyb_orx1in_voltage2_set_res *)out_msg = es_adrv9009.rpc.phyb_orx1in_voltage2_set.payload.res;
            break;
        case es_adrv9009_rpc_phyb_orx1in_voltage2_get_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phyb_orx1in_voltage2_get_tag ||
                es_adrv9009.rpc.phyb_orx1in_voltage2_get.which_payload != phyb_orx1in_voltage2_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phyb_orx1in_voltage2_get_res *)out_msg = es_adrv9009.rpc.phyb_orx1in_voltage2_get.payload.res;
            break;
        case es_adrv9009_rpc_phya_orx2in_voltage3_set_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phya_orx2in_voltage3_set_tag ||
                es_adrv9009.rpc.phya_orx2in_voltage3_set.which_payload != phya_orx2in_voltage3_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phya_orx2in_voltage3_set_res *)out_msg = es_adrv9009.rpc.phya_orx2in_voltage3_set.payload.res;
            break;
        case es_adrv9009_rpc_phya_orx2in_voltage3_get_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phya_orx2in_voltage3_get_tag ||
                es_adrv9009.rpc.phya_orx2in_voltage3_get.which_payload != phya_orx2in_voltage3_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phya_orx2in_voltage3_get_res *)out_msg = es_adrv9009.rpc.phya_orx2in_voltage3_get.payload.res;
            break;
        case es_adrv9009_rpc_phyb_orx2in_voltage3_set_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phyb_orx2in_voltage3_set_tag ||
                es_adrv9009.rpc.phyb_orx2in_voltage3_set.which_payload != phyb_orx2in_voltage3_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phyb_orx2in_voltage3_set_res *)out_msg = es_adrv9009.rpc.phyb_orx2in_voltage3_set.payload.res;
            break;
        case es_adrv9009_rpc_phyb_orx2in_voltage3_get_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phyb_orx2in_voltage3_get_tag ||
                es_adrv9009.rpc.phyb_orx2in_voltage3_get.which_payload != phyb_orx2in_voltage3_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phyb_orx2in_voltage3_get_res *)out_msg = es_adrv9009.rpc.phyb_orx2in_voltage3_get.payload.res;
            break;
        case es_adrv9009_rpc_phya_rx1in_voltage0_set_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phya_rx1in_voltage0_set_tag ||
                es_adrv9009.rpc.phya_rx1in_voltage0_set.which_payload != phya_rx1in_voltage0_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phya_rx1in_voltage0_set_res *)out_msg = es_adrv9009.rpc.phya_rx1in_voltage0_set.payload.res;
            break;
        case es_adrv9009_rpc_phya_rx1in_voltage0_get_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phya_rx1in_voltage0_get_tag ||
                es_adrv9009.rpc.phya_rx1in_voltage0_get.which_payload != phya_rx1in_voltage0_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phya_rx1in_voltage0_get_res *)out_msg = es_adrv9009.rpc.phya_rx1in_voltage0_get.payload.res;
            break;
        case es_adrv9009_rpc_phyb_rx1in_voltage0_set_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phyb_rx1in_voltage0_set_tag ||
                es_adrv9009.rpc.phyb_rx1in_voltage0_set.which_payload != phyb_rx1in_voltage0_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phyb_rx1in_voltage0_set_res *)out_msg = es_adrv9009.rpc.phyb_rx1in_voltage0_set.payload.res;
            break;
        case es_adrv9009_rpc_phyb_rx1in_voltage0_get_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phyb_rx1in_voltage0_get_tag ||
                es_adrv9009.rpc.phyb_rx1in_voltage0_get.which_payload != phyb_rx1in_voltage0_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phyb_rx1in_voltage0_get_res *)out_msg = es_adrv9009.rpc.phyb_rx1in_voltage0_get.payload.res;
            break;
        case es_adrv9009_rpc_phya_rx2in_voltage1_set_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phya_rx2in_voltage1_set_tag ||
                es_adrv9009.rpc.phya_rx2in_voltage1_set.which_payload != phya_rx2in_voltage1_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phya_rx2in_voltage1_set_res *)out_msg = es_adrv9009.rpc.phya_rx2in_voltage1_set.payload.res;
            break;
        case es_adrv9009_rpc_phya_rx2in_voltage1_get_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phya_rx2in_voltage1_get_tag ||
                es_adrv9009.rpc.phya_rx2in_voltage1_get.which_payload != phya_rx2in_voltage1_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phya_rx2in_voltage1_get_res *)out_msg = es_adrv9009.rpc.phya_rx2in_voltage1_get.payload.res;
            break;
        case es_adrv9009_rpc_phyb_rx2in_voltage1_set_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phyb_rx2in_voltage1_set_tag ||
                es_adrv9009.rpc.phyb_rx2in_voltage1_set.which_payload != phyb_rx2in_voltage1_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phyb_rx2in_voltage1_set_res *)out_msg = es_adrv9009.rpc.phyb_rx2in_voltage1_set.payload.res;
            break;
        case es_adrv9009_rpc_phyb_rx2in_voltage1_get_tag:
            if (es_adrv9009.which_rpc != es_adrv9009_rpc_phyb_rx2in_voltage1_get_tag ||
                es_adrv9009.rpc.phyb_rx2in_voltage1_get.which_payload != phyb_rx2in_voltage1_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_phyb_rx2in_voltage1_get_res *)out_msg = es_adrv9009.rpc.phyb_rx2in_voltage1_get.payload.res;
            break;


        default:
            ES_LOG_MSG(ES_ERROR, "Invalid RPC id: %d\n", rpc_id);
            return -1;
    }

    return 0;
}

static es_ser_des_t es_adrv9009_serdes = {
    .ser = __es_adrv9009_ser,
    .des = __es_adrv9009_des,
};

/***************************** INTERFACE FUNCTIONS ****************************/
es_ser_des_t *es_adrv9009_ser_des_get_hndlrs(void)
{
    return &es_adrv9009_serdes;
}
