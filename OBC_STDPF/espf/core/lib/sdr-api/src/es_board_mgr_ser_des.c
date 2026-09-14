/* Automatically generated. Do not edit manually */

/******************************** INCLUDE FILES *******************************/
#include <pb_encode.h>
#include <pb_decode.h>

#include "es_sdr_client_tl_iface.h"
/* Client interface for passing commands */
#include "es_board_mgr_ser_des.h"

/* Protocol definitions */
#include "es_board_mgr.pb.h"

#include "es_log.h"
/******************************** LOCAL DEFINES *******************************/
#define ES_MODULE_NAME  "es_board_mgr"

/******************************* LOCAL TYPEDEFS *******************************/

/********************************* LOCAL DATA *********************************/

/******************************* LOCAL FUNCTIONS ******************************/

static int __es_board_mgr_ser(int rpc_id, char *req_buffer, void *in_msg)
{
    int status = -1;
    pb_ostream_t o_stream;

    es_board_mgr_rpc es_board_mgr = es_board_mgr_rpc_init_zero;

    ES_LOG_MSG(ES_TRACE, " [%s] ", __func__);

    /*
     * RPC Encapsulation
     */

    switch(rpc_id)
    {
        case es_board_mgr_rpc_eth_cfg_set_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_eth_cfg_set_tag;
            es_board_mgr.rpc.eth_cfg_set.which_payload = eth_cfg_set_rpc_req_tag;
            es_board_mgr.rpc.eth_cfg_set.payload.req = *(es_eth_cfg_set_req *)in_msg;
            es_board_mgr.rpc.eth_cfg_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_eth_cfg_get_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_eth_cfg_get_tag;
            es_board_mgr.rpc.eth_cfg_get.which_payload = eth_cfg_get_rpc_req_tag;
            es_board_mgr.rpc.eth_cfg_get.payload.req = *(es_eth_cfg_get_req *)in_msg;
            es_board_mgr.rpc.eth_cfg_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_csp_cfg_set_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_csp_cfg_set_tag;
            es_board_mgr.rpc.csp_cfg_set.which_payload = csp_cfg_set_rpc_req_tag;
            es_board_mgr.rpc.csp_cfg_set.payload.req = *(es_csp_cfg_set_req *)in_msg;
            es_board_mgr.rpc.csp_cfg_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_csp_cfg_get_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_csp_cfg_get_tag;
            es_board_mgr.rpc.csp_cfg_get.which_payload = csp_cfg_get_rpc_req_tag;
            es_board_mgr.rpc.csp_cfg_get.payload.req = *(es_csp_cfg_get_req *)in_msg;
            es_board_mgr.rpc.csp_cfg_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_esps_cfg_set_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_esps_cfg_set_tag;
            es_board_mgr.rpc.esps_cfg_set.which_payload = esps_cfg_set_rpc_req_tag;
            es_board_mgr.rpc.esps_cfg_set.payload.req = *(es_esps_cfg_set_req *)in_msg;
            es_board_mgr.rpc.esps_cfg_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_esps_cfg_get_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_esps_cfg_get_tag;
            es_board_mgr.rpc.esps_cfg_get.which_payload = esps_cfg_get_rpc_req_tag;
            es_board_mgr.rpc.esps_cfg_get.payload.req = *(es_esps_cfg_get_req *)in_msg;
            es_board_mgr.rpc.esps_cfg_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_bundle_info_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_bundle_info_tag;
            es_board_mgr.rpc.bundle_info.which_payload = bundle_info_rpc_req_tag;
            es_board_mgr.rpc.bundle_info.payload.req = *(es_bundle_info_req *)in_msg;
            es_board_mgr.rpc.bundle_info.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_bundle_install_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_bundle_install_tag;
            es_board_mgr.rpc.bundle_install.which_payload = bundle_install_rpc_req_tag;
            es_board_mgr.rpc.bundle_install.payload.req = *(es_bundle_install_req *)in_msg;
            es_board_mgr.rpc.bundle_install.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_update_progress_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_update_progress_tag;
            es_board_mgr.rpc.update_progress.which_payload = update_progress_rpc_req_tag;
            es_board_mgr.rpc.update_progress.payload.req = *(es_update_progress_req *)in_msg;
            es_board_mgr.rpc.update_progress.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_slot_status_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_slot_status_tag;
            es_board_mgr.rpc.slot_status.which_payload = slot_status_rpc_req_tag;
            es_board_mgr.rpc.slot_status.payload.req = *(es_slot_status_req *)in_msg;
            es_board_mgr.rpc.slot_status.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_mark_slot_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_mark_slot_tag;
            es_board_mgr.rpc.mark_slot.which_payload = mark_slot_rpc_req_tag;
            es_board_mgr.rpc.mark_slot.payload.req = *(es_mark_slot_req *)in_msg;
            es_board_mgr.rpc.mark_slot.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_get_primary_slot_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_get_primary_slot_tag;
            es_board_mgr.rpc.get_primary_slot.which_payload = get_primary_slot_rpc_req_tag;
            es_board_mgr.rpc.get_primary_slot.payload.req = *(es_get_primary_slot_req *)in_msg;
            es_board_mgr.rpc.get_primary_slot.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_sys_time_set_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_sys_time_set_tag;
            es_board_mgr.rpc.sys_time_set.which_payload = sys_time_set_rpc_req_tag;
            es_board_mgr.rpc.sys_time_set.payload.req = *(es_sys_time_set_req *)in_msg;
            es_board_mgr.rpc.sys_time_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_sys_time_get_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_sys_time_get_tag;
            es_board_mgr.rpc.sys_time_get.which_payload = sys_time_get_rpc_req_tag;
            es_board_mgr.rpc.sys_time_get.payload.req = *(es_sys_time_get_req *)in_msg;
            es_board_mgr.rpc.sys_time_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_sys_time_pps_lock_stat_get_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_sys_time_pps_lock_stat_get_tag;
            es_board_mgr.rpc.sys_time_pps_lock_stat_get.which_payload = sys_time_pps_lock_stat_get_rpc_req_tag;
            es_board_mgr.rpc.sys_time_pps_lock_stat_get.payload.req = *(es_sys_time_pps_lock_stat_get_req *)in_msg;
            es_board_mgr.rpc.sys_time_pps_lock_stat_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_sys_time_pps_offset_get_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_sys_time_pps_offset_get_tag;
            es_board_mgr.rpc.sys_time_pps_offset_get.which_payload = sys_time_pps_offset_get_rpc_req_tag;
            es_board_mgr.rpc.sys_time_pps_offset_get.payload.req = *(es_sys_time_pps_offset_get_req *)in_msg;
            es_board_mgr.rpc.sys_time_pps_offset_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_rtc_time_get_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_rtc_time_get_tag;
            es_board_mgr.rpc.rtc_time_get.which_payload = rtc_time_get_rpc_req_tag;
            es_board_mgr.rpc.rtc_time_get.payload.req = *(es_rtc_time_get_req *)in_msg;
            es_board_mgr.rpc.rtc_time_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_rtc_time_force_sync_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_rtc_time_force_sync_tag;
            es_board_mgr.rpc.rtc_time_force_sync.which_payload = rtc_time_force_sync_rpc_req_tag;
            es_board_mgr.rpc.rtc_time_force_sync.payload.req = *(es_rtc_time_force_sync_req *)in_msg;
            es_board_mgr.rpc.rtc_time_force_sync.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_rf_board_stat_set_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_rf_board_stat_set_tag;
            es_board_mgr.rpc.rf_board_stat_set.which_payload = rf_board_stat_set_rpc_req_tag;
            es_board_mgr.rpc.rf_board_stat_set.payload.req = *(es_rf_board_stat_set_req *)in_msg;
            es_board_mgr.rpc.rf_board_stat_set.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_rf_board_stat_get_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_rf_board_stat_get_tag;
            es_board_mgr.rpc.rf_board_stat_get.which_payload = rf_board_stat_get_rpc_req_tag;
            es_board_mgr.rpc.rf_board_stat_get.payload.req = *(es_rf_board_stat_get_req *)in_msg;
            es_board_mgr.rpc.rf_board_stat_get.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;
        case es_board_mgr_rpc_system_halt_tag:
            es_board_mgr.which_rpc = es_board_mgr_rpc_system_halt_tag;
            es_board_mgr.rpc.system_halt.which_payload = system_halt_rpc_req_tag;
            es_board_mgr.rpc.system_halt.payload.req = *(es_system_halt_req *)in_msg;
            es_board_mgr.rpc.system_halt.payload.req.hdr.timestamp = 0;//es_utils_timestamp();
            break;


        default:
            ES_LOG_MSG(ES_ERROR, "Invalid RPC id: %d\n", rpc_id);
            return -1;
    }

    /* Set out stream encoder */
    o_stream = pb_ostream_from_buffer((pb_byte_t *)req_buffer, CLIENT_IO_BUFFER_SIZE);

    /* Now we are ready to encode the message */
    status = pb_encode_delimited(&o_stream, es_board_mgr_rpc_fields, &es_board_mgr);
    if (!status)
    {
        ES_LOG_MSG(ES_ERROR, "Failed to encode message %s", PB_GET_ERROR(&o_stream));
        return -1;
    }

    return o_stream.bytes_written;
}

static int __es_board_mgr_des(int rpc_id, char *res_buffer, void *out_msg)
{
    int status = 0;
    pb_istream_t i_stream;

    es_board_mgr_rpc es_board_mgr = es_board_mgr_rpc_init_zero;

    ES_LOG_MSG(ES_TRACE, " [%s] ", __func__);

    /* Create a stream that will read from our buffer. */
    i_stream = pb_istream_from_buffer((pb_byte_t *)res_buffer, CLIENT_IO_BUFFER_SIZE);

    /* The input message starts with the message size as varint. */
    status = pb_decode_delimited(&i_stream, es_board_mgr_rpc_fields, &es_board_mgr);
    if (!status)
    {
        ES_LOG_MSG(ES_ERROR, "Failed to decode message %s", PB_GET_ERROR(&i_stream));
        return -1;
    }

    switch(rpc_id)
    {
        case es_board_mgr_rpc_eth_cfg_set_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_eth_cfg_set_tag ||
                es_board_mgr.rpc.eth_cfg_set.which_payload != eth_cfg_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_eth_cfg_set_res *)out_msg = es_board_mgr.rpc.eth_cfg_set.payload.res;
            break;
        case es_board_mgr_rpc_eth_cfg_get_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_eth_cfg_get_tag ||
                es_board_mgr.rpc.eth_cfg_get.which_payload != eth_cfg_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_eth_cfg_get_res *)out_msg = es_board_mgr.rpc.eth_cfg_get.payload.res;
            break;
        case es_board_mgr_rpc_csp_cfg_set_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_csp_cfg_set_tag ||
                es_board_mgr.rpc.csp_cfg_set.which_payload != csp_cfg_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_csp_cfg_set_res *)out_msg = es_board_mgr.rpc.csp_cfg_set.payload.res;
            break;
        case es_board_mgr_rpc_csp_cfg_get_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_csp_cfg_get_tag ||
                es_board_mgr.rpc.csp_cfg_get.which_payload != csp_cfg_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_csp_cfg_get_res *)out_msg = es_board_mgr.rpc.csp_cfg_get.payload.res;
            break;
        case es_board_mgr_rpc_esps_cfg_set_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_esps_cfg_set_tag ||
                es_board_mgr.rpc.esps_cfg_set.which_payload != esps_cfg_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_esps_cfg_set_res *)out_msg = es_board_mgr.rpc.esps_cfg_set.payload.res;
            break;
        case es_board_mgr_rpc_esps_cfg_get_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_esps_cfg_get_tag ||
                es_board_mgr.rpc.esps_cfg_get.which_payload != esps_cfg_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_esps_cfg_get_res *)out_msg = es_board_mgr.rpc.esps_cfg_get.payload.res;
            break;
        case es_board_mgr_rpc_bundle_info_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_bundle_info_tag ||
                es_board_mgr.rpc.bundle_info.which_payload != bundle_info_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_bundle_info_res *)out_msg = es_board_mgr.rpc.bundle_info.payload.res;
            break;
        case es_board_mgr_rpc_bundle_install_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_bundle_install_tag ||
                es_board_mgr.rpc.bundle_install.which_payload != bundle_install_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_bundle_install_res *)out_msg = es_board_mgr.rpc.bundle_install.payload.res;
            break;
        case es_board_mgr_rpc_update_progress_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_update_progress_tag ||
                es_board_mgr.rpc.update_progress.which_payload != update_progress_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_update_progress_res *)out_msg = es_board_mgr.rpc.update_progress.payload.res;
            break;
        case es_board_mgr_rpc_slot_status_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_slot_status_tag ||
                es_board_mgr.rpc.slot_status.which_payload != slot_status_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_slot_status_res *)out_msg = es_board_mgr.rpc.slot_status.payload.res;
            break;
        case es_board_mgr_rpc_mark_slot_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_mark_slot_tag ||
                es_board_mgr.rpc.mark_slot.which_payload != mark_slot_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_mark_slot_res *)out_msg = es_board_mgr.rpc.mark_slot.payload.res;
            break;
        case es_board_mgr_rpc_get_primary_slot_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_get_primary_slot_tag ||
                es_board_mgr.rpc.get_primary_slot.which_payload != get_primary_slot_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_get_primary_slot_res *)out_msg = es_board_mgr.rpc.get_primary_slot.payload.res;
            break;
        case es_board_mgr_rpc_sys_time_set_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_sys_time_set_tag ||
                es_board_mgr.rpc.sys_time_set.which_payload != sys_time_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_sys_time_set_res *)out_msg = es_board_mgr.rpc.sys_time_set.payload.res;
            break;
        case es_board_mgr_rpc_sys_time_get_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_sys_time_get_tag ||
                es_board_mgr.rpc.sys_time_get.which_payload != sys_time_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_sys_time_get_res *)out_msg = es_board_mgr.rpc.sys_time_get.payload.res;
            break;
        case es_board_mgr_rpc_sys_time_pps_lock_stat_get_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_sys_time_pps_lock_stat_get_tag ||
                es_board_mgr.rpc.sys_time_pps_lock_stat_get.which_payload != sys_time_pps_lock_stat_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_sys_time_pps_lock_stat_get_res *)out_msg = es_board_mgr.rpc.sys_time_pps_lock_stat_get.payload.res;
            break;
        case es_board_mgr_rpc_sys_time_pps_offset_get_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_sys_time_pps_offset_get_tag ||
                es_board_mgr.rpc.sys_time_pps_offset_get.which_payload != sys_time_pps_offset_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_sys_time_pps_offset_get_res *)out_msg = es_board_mgr.rpc.sys_time_pps_offset_get.payload.res;
            break;
        case es_board_mgr_rpc_rtc_time_get_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_rtc_time_get_tag ||
                es_board_mgr.rpc.rtc_time_get.which_payload != rtc_time_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_rtc_time_get_res *)out_msg = es_board_mgr.rpc.rtc_time_get.payload.res;
            break;
        case es_board_mgr_rpc_rtc_time_force_sync_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_rtc_time_force_sync_tag ||
                es_board_mgr.rpc.rtc_time_force_sync.which_payload != rtc_time_force_sync_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_rtc_time_force_sync_res *)out_msg = es_board_mgr.rpc.rtc_time_force_sync.payload.res;
            break;
        case es_board_mgr_rpc_rf_board_stat_set_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_rf_board_stat_set_tag ||
                es_board_mgr.rpc.rf_board_stat_set.which_payload != rf_board_stat_set_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_rf_board_stat_set_res *)out_msg = es_board_mgr.rpc.rf_board_stat_set.payload.res;
            break;
        case es_board_mgr_rpc_rf_board_stat_get_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_rf_board_stat_get_tag ||
                es_board_mgr.rpc.rf_board_stat_get.which_payload != rf_board_stat_get_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_rf_board_stat_get_res *)out_msg = es_board_mgr.rpc.rf_board_stat_get.payload.res;
            break;
        case es_board_mgr_rpc_system_halt_tag:
            if (es_board_mgr.which_rpc != es_board_mgr_rpc_system_halt_tag ||
                es_board_mgr.rpc.system_halt.which_payload != system_halt_rpc_res_tag)
            {
                ES_LOG_MSG(ES_ERROR, "Failed to get response!");
                return -1;
            }
            *(es_system_halt_res *)out_msg = es_board_mgr.rpc.system_halt.payload.res;
            break;


        default:
            ES_LOG_MSG(ES_ERROR, "Invalid RPC id: %d\n", rpc_id);
            return -1;
    }

    return 0;
}

static es_ser_des_t es_board_mgr_serdes = {
    .ser = __es_board_mgr_ser,
    .des = __es_board_mgr_des,
};

/***************************** INTERFACE FUNCTIONS ****************************/
es_ser_des_t *es_board_mgr_ser_des_get_hndlrs(void)
{
    return &es_board_mgr_serdes;
}