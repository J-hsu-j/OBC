/*
 * Copyright (c) 2020-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/** @addtogroup service_beacons
 * @{
 * @file beacons_sink_uhf.c
 *
 * @brief Beacon UHF sink adapter
 *
 * The component is responsible to forward beacon data to UHF over ESPS I.
 * @}
 */

#include <string.h>
#include "if_beacons_sink.h"
#include "assertions.h"
#include "fp/UHF/v0.5/UHF_client/FP_UHFProtocolClient.h"
#include "config/beacons/beacons_cfg_user.h"
#include "config/nvm/inc/nvm_data_types.h"
#include "assertions.h"
#include "trace.h"
#include "fdir_srv.h"
#include "fdir_srv_log.h"
#include "datacache.h"

INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/** @brief See @ref p_beacons_sink_adapter_cmd documentation for details */
static void beacons_uhf_cmd(const beacons_sink_adapter_cmd_t cmd)
{
    // the UHF subsystem should already be initialized by the ESPS stack so
    // this call is only here for completeness and doesn't do anything
    (void)cmd;
}

/** @brief See @ref p_beacons_sink_adapter_send documentation for details */
static bool beacons_uhf_send(const uint8_t *const p_data, const uint8_t size, uint16_t *const p_id)
{
    BREAK_ASSERT(NULL != p_data);
    BREAK_ASSERT(size > 0U);

    ESSATMAC_ErrCodes res = ESSATMAC_EC_ERROR;

    if ((NULL != p_data) && (size > 0U))
    {
        ReqContext_t esps_req_ctx = { .nAddr            = BEACONS_UHF_SINK_ESPS_ADDRESS,
                                      .nInterfaceNumber = ESSASNI_SYS_PRI,
                                      .netType          = ESSASNETT_INTERNAL,
                                      .seqId            = 0 };

        UHF_sExBeacon_t bcn_data;

        bcn_data.u8Size = MIN(size, sizeof(bcn_data.au8Data));

        (void)memcpy(bcn_data.au8Data, p_data, MIN(size, sizeof(bcn_data.au8Data)));

        // fill-up remaining bytes in beacon frame with zeroes
        if (size <= sizeof(bcn_data.au8Data))
        {
            (void)memset(&bcn_data.au8Data[size], INVALID_BEACON_SLOT_ASSIGNMENT,
                         sizeof(bcn_data.au8Data) - size);
        }

        res = UHF_ExBeaconSetSendReq(&esps_req_ctx, &bcn_data);

        DATA_CACHE_FDIR_UHF_CMD_EXEC_STATUS_t exec_status;
        exec_status.bError_occured = false;
        if (ESSATMAC_EC_OK != res)
        {
            exec_status.bError_occured = true;

            fdir_srv_log(FDIR_FAULT_UHF_CMD_EXEC_FAILURE, FDIR_AGENT_UHF, "UHF command failed with err code %d, addr %d, interface %d, netType %d, seqid: %u", res, esps_req_ctx.nAddr, esps_req_ctx.nInterfaceNumber, esps_req_ctx.netType, esps_req_ctx.seqId);
        }
        dc_set_fdir_uhf_cmd_exec_status_data(&exec_status);
        (void)dc_get_fdir_uhf_cmd_exec_status_data(&exec_status);
        (void)fdir_srv_fault_set_state(FDIR_FAULT_UHF_CMD_EXEC_FAILURE, FDIR_AGENT_UHF, exec_status.bError_occured, NULL);

        ES_TRACE_DEBUG("sending UHF beacon frame [size: %d] | status = %d | seq_id = %d", size, res, esps_req_ctx.seqId);

        if (NULL != p_id)
        {
            static_assert(sizeof(esps_req_ctx.seqId) == sizeof(uint16_t));

            // the seqId field is assigned by the UHF_ExBeaconSetSendReq() call
            *p_id = esps_req_ctx.seqId;
        }
    }
    else
    {
        ES_TRACE_WARN("invalid UHF beacon data parameters passed");

        DATA_CACHE_FDIR_UHF_CMD_EXEC_STATUS_t exec_status;
        exec_status.bError_occured = true;
        fdir_srv_log(FDIR_FAULT_UHF_CMD_EXEC_FAILURE, FDIR_AGENT_UHF, "UHF command failed - invalid parameter");
        dc_set_fdir_uhf_cmd_exec_status_data(&exec_status);
        (void)dc_get_fdir_uhf_cmd_exec_status_data(&exec_status);
        (void)fdir_srv_fault_set_state(FDIR_FAULT_UHF_CMD_EXEC_FAILURE, FDIR_AGENT_UHF, exec_status.bError_occured, NULL);
    }

    return (ESSATMAC_EC_OK == res);
}

void beacons_sink_uhf_send_status_cbk(
    const RespContext_t *const                    p_resp_ctx,
    const UHFExBeaconSetSendResponseData_t *const p_resp_data)
{
    BREAK_ASSERT(NULL != p_resp_ctx);
    BREAK_ASSERT(NULL != p_resp_data);

    if ((NULL != p_resp_ctx) && (NULL != p_resp_data))
    {
        ES_TRACE_DEBUG("UHF beacon response rcvd [status = %d] | seq_id = %d", (uint16_t)p_resp_data->eOpResult, p_resp_ctx->seqId);

        DATA_CACHE_FDIR_UHF_CMD_EXEC_STATUS_t exec_status;
        exec_status.bError_occured = false;
        if ((UHF_EESSA_UHFSTATUS_OK != p_resp_data->eOpResult) &&
            (UHF_EESSA_UHFSTATUS_UHF_ERR_BUSY != p_resp_data->eOpResult))
        {
            exec_status.bError_occured = true;

            fdir_srv_log(FDIR_FAULT_UHF_CMD_EXEC_FAILURE, FDIR_AGENT_UHF, "UHF command failed with response status %d, addr %d, interface %d, netType %d, seqid: %u", p_resp_data->eOpResult, p_resp_ctx->nAddr, p_resp_ctx->nInterfaceNumber, p_resp_ctx->netType, p_resp_ctx->seqId);
        }
        dc_set_fdir_uhf_cmd_exec_status_data(&exec_status);
        (void)dc_get_fdir_uhf_cmd_exec_status_data(&exec_status);
        (void)fdir_srv_fault_set_state(FDIR_FAULT_UHF_CMD_EXEC_FAILURE, FDIR_AGENT_UHF, exec_status.bError_occured, NULL);

        beacons_confirm_sink_send(
            p_resp_ctx->seqId, (UHF_EESSA_UHFSTATUS_OK == p_resp_data->eOpResult));
    }
}

const beacons_sink_if_t beacons_sink = { .cmd  = &beacons_uhf_cmd,
                                         .send = &beacons_uhf_send };
