/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup eps_iii_pdm_a
 * @{
 *
 * @file     eps_iii_pdm_a.c
 * @brief    Power Distribution Module TypeA Driver implementation
 *
 * @}
 */

#include "eps_iii_pdm_a_cfg.h"
#include "eps_iii_pdm_a.h"

#include "if_tlm_dev.h"
#include "if_esps_dev.h"

#include "eps_iii_cfg.h"
#include "eps_iii.h"

#include <assert.h>
#include "assertions.h"

#include "FP_common/FP_BaseProtocolTypes.h"
#include "fp/eps_iii_pdm_a/v2.0/eps_iii_pdm_a_client/FP_eps_iii_pdm_aProtocolTypes.h"
#include "fp/eps_iii_pdm_a/v2.0/eps_iii_pdm_a_client/FP_eps_iii_pdm_aProtocolClient.h"

#include "fdir_srv.h"

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
typedef ESSATMAC_ErrCodes (*telemetry_req)(ReqContext_t *ctx);

typedef struct
{
    const char                          *cmd_name;
    eps_iii_pdm_a_datacache_info_types_t dc_element;
} eps_fdir_cmd_exec_info_type;

pdm_a_fdir_exec_status_t pdm_a_fdir_exec_status[EPS_III_PDM_A_INST_CNT][EPS_III_PDM_A_FDIR_COUNT];

const fdir_fault_id_t pdm_a_fdir_fault_ids[EPS_III_PDM_A_INST_CNT][EPS_III_PDM_A_FDIR_COUNT] = {
    EPS_III_PDM_A_FDIR_FAULTS_IDS
};

const get_telemetry_req_t pdm_a_tlm_req_cmds[PDM_A_TLM_CMD_CNT] = {
    &eps_iii_pdm_a_get_telemetryReq
};

const dc_did_id pdm_a_datacache_cmd_list[EPS_III_PDM_A_INST_CNT][EPS_III_PDM_A_DATACACHE_CMD_COUNT] = {
    EPS_III_PDM_A_DATACACHE_LIST_CMD
};

static const eps_fdir_cmd_exec_info_type pdm_а_map_dc_to_cmd[EPS_III_PDM_A_CMD_CNT] = {
    {"eps_iii_pdm_a_get_telemetry",                EPS_III_PDM_A_ALL_MEASUREMENTS   }, /* PDM_A_GET_1 */
    { "eps_iii_pdm_a_low_volt_control",            EPS_III_PDM_A_DATACACHE_CMD_COUNT}, /* PDM_A_DATACACHE_CMD_COUNT */
    { "eps_iii_pdm_a_external_system_bus_control", EPS_III_PDM_A_DATACACHE_CMD_COUNT}, /* PDM_A_DATACACHE_CMD_COUNT */
};

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
static eps_iii_pdm_a_chn_t requested_chn_id = EPS_III_PDM_A_CHANNELS_CNT;

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
static ESSATMAC_ErrCodes send_ch_cmd(uint8_t chn_id, bool is_cmd_set, bool new_state, ReqContext_t *p_req_ctx, eps_iii_pdm_a_cmd_e *const p_fp_cmd_id);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
void eps_iii_pdm_a_init(eps_iii_pdm_a_t *const self, uint8_t mac_address)
{
    // the type with command execution statuses must be aligned with the enumerator which contains the commands
    static_assert(EPS_III_PDM_A_CMD_CNT == sizeof(pdm_a_fdir_exec_status_t));

    BREAK_ASSERT(NULL != self);

    eps_dev_t *eps_dev_ctx = (eps_dev_t *)self;

    if ((NULL != self) && (NULL != eps_dev_ctx->p_dev_init))
    {
        // call parent init
        eps_dev_ctx->p_dev_init(eps_dev_ctx, mac_address);
    }
}

void eps_iii_pdm_a_process_fdir_faults(const eps_dev_t *const self)
{
    ESSATMAC_ErrCodes err_code;
    bool              cmd_exec_failure = false;

    BREAK_ASSERT(NULL != self);

    if (NULL != self)
    {
        for (uint8_t cmd_id = 0; cmd_id < EPS_III_PDM_A_CMD_CNT; cmd_id++)
        {
            uint8_t          buffer_to_read_in;
            dc_data_status_t res;
            if (EPS_III_PDM_A_DATACACHE_CMD_COUNT != pdm_а_map_dc_to_cmd[cmd_id].dc_element)
            {
                res = dc_get_raw_data(self->datacache_cmd_list[pdm_а_map_dc_to_cmd[cmd_id].dc_element],
                                      &buffer_to_read_in,
                                      sizeof(uint8_t),
                                      0,
                                      sizeof(uint8_t));

                if ((FDIR_CMD_EXEC_OK == ((uint8_t *)self->p_fdir_exec_status)[cmd_id]) && (DC_DATA_STATUS_TOUT == res))
                {
                    static_assert(FDIR_CMD_EXEC_TIMEOUT <= UINT8_MAX);
                    (self->p_fdir_exec_status)[cmd_id] = (uint8_t)FDIR_CMD_EXEC_TIMEOUT;
                }
            }
            else
            {
                // skip commands not associated to DC element
            }
        }

        dc_set_raw_data(DC_DATA_INPUT_INTERNAL,
                        self->datacache_cmd_list[EPS_III_PDM_A_FDIR_CMD_EXEC_STATUS_DATA],
                        self->p_fdir_exec_status,
                        sizeof(pdm_a_fdir_exec_status_t));

        dc_get_raw_data(self->datacache_cmd_list[EPS_III_PDM_A_FDIR_CMD_EXEC_STATUS_DATA],
                        self->p_fdir_exec_status,
                        sizeof(pdm_a_fdir_exec_status_t),
                        0,
                        sizeof(pdm_a_fdir_exec_status_t));

        for (uint8_t cmd_id = 0; cmd_id < EPS_III_PDM_A_CMD_CNT; cmd_id++)
        {
            // info and health
            err_code = ((uint8_t *)self->p_fdir_exec_status)[cmd_id];
            if (ESSATMAC_EC_OK != err_code)
            {
                cmd_exec_failure = true;
                fdir_srv_log_if_clear(self->fdir_fault_ids[EPS_III_PDM_A_FDIR_CMD_EXEC_FAILURE],
                                      FDIR_AGENT_EPS_III,
                                      "FP %s failed with err code %d, BP mac %u",
                                      pdm_а_map_dc_to_cmd[cmd_id].cmd_name,
                                      err_code,
                                      self->esps_dev_info.mac_addr);
            }
        }

        if (false == cmd_exec_failure)
        {
            fdir_srv_log_if_raised(self->fdir_fault_ids[EPS_III_PDM_A_FDIR_CMD_EXEC_FAILURE],
                                   FDIR_AGENT_EPS_III,
                                   "All EPS II commands in current cycle succeeded");
        }
        (void)fdir_srv_fault_set_state(self->fdir_fault_ids[EPS_III_PDM_A_FDIR_CMD_EXEC_FAILURE],
                                       FDIR_AGENT_EPS_III,
                                       cmd_exec_failure,
                                       NULL);
    }
}

// serve notifications from FP commands.
void eps_iii_pdm_a_get_telemetry_notif(const RespContext_t *const pRespCtx, const eps_iii_pdm_aget_telemetryResponseData_t *const pResponseData)
{
    BREAK_ASSERT(NULL != pResponseData);

    if (NULL != pResponseData)
    {
        const bp_response_map_type map_response_to_dc_element[EPS_III_PDM_A_FDIR_CMD_EXEC_STATUS_DATA] = {
            {(const uint8_t *)&pResponseData->u32Uptime_in_seconds, sizeof(pResponseData->u32Uptime_in_seconds)},
            { (const uint8_t *)&pResponseData->sCommon,             sizeof(pResponseData->sCommon)             },
            { (const uint8_t *)&pResponseData->sGeneral_outputs,    sizeof(pResponseData->sGeneral_outputs)    },
            { (const uint8_t *)&pResponseData->sGeneral_faults,     sizeof(pResponseData->sGeneral_faults)     },
            { (const uint8_t *)&pResponseData->sAll_measurments,    sizeof(pResponseData->sAll_measurments)    }
        };

        telemetry_notif_process(pRespCtx, map_response_to_dc_element, EPS_III_PDM_A_FDIR_CMD_EXEC_STATUS_DATA);
    }
}

void eps_iii_pdm_a_low_volt_notif(const RespContext_t *const pRespCtx, const eps_iii_pdm_alow_volt_controlResponseData_t *const response)
{
    BREAK_ASSERT((NULL != response) && (NULL != pRespCtx));

    if ((NULL != response) && (NULL != pRespCtx))
    {
        const if_eps_ctrl_t *p_eps_ctrl_dev = eps_iii_get_eps_ctrl_by_addr(pRespCtx->nAddr);

        BREAK_ASSERT(NULL != p_eps_ctrl_dev);

        if ((NULL != p_eps_ctrl_dev) && (true == p_eps_ctrl_dev->p_device_info->p_is_seq_expected(p_eps_ctrl_dev->p_device_info, pRespCtx->seqId)))
        {
            if (EPS_III_PDM_A_CHANNELS_CNT != requested_chn_id)
            {
                bool status = (EPS_III_PDM_A_READENDFTSTATUS_ON == response->eLow_volt_status) || (EPS_III_PDM_A_READENDFTSTATUS_ON_FOR_TIME == response->eLow_volt_status) || (EPS_III_PDM_A_READENDFTSTATUS_TOGGLE_BUSY_ON_FOR_TIME == response->eLow_volt_status);

                // process get channel notification
                p_eps_ctrl_dev->p_on_get_output_response_received(EPS_III_PDM_A_COMMANDSTATUS_SUCCESS == response->eCommand_status, status);
            }
            else
            { // process set channel notification
                p_eps_ctrl_dev->p_on_set_output_response_received(EPS_III_PDM_A_COMMANDSTATUS_SUCCESS == response->eCommand_status);
            }
        }
    }
}

void eps_iii_pdm_a_system_bus_notif(const RespContext_t *const pRespCtx, const eps_iii_pdm_aexternal_system_bus_controlResponseData_t *const response)
{
    BREAK_ASSERT((NULL != response) && (NULL != pRespCtx));

    if ((NULL != response) && (NULL != pRespCtx))
    {
        const if_eps_ctrl_t *p_eps_ctrl_dev = eps_iii_get_eps_ctrl_by_addr(pRespCtx->nAddr);

        if (NULL != p_eps_ctrl_dev)
        {
            if (true == p_eps_ctrl_dev->p_device_info->p_is_seq_expected(p_eps_ctrl_dev->p_device_info, pRespCtx->seqId))
            {
                if (EPS_III_PDM_A_CHANNELS_CNT != requested_chn_id)
                {
                    bool status = (EPS_III_PDM_A_READENDFTSTATUS_ON == response->eExt_sys_bus_status) || (EPS_III_PDM_A_READENDFTSTATUS_ON_FOR_TIME == response->eExt_sys_bus_status) || (EPS_III_PDM_A_READENDFTSTATUS_TOGGLE_BUSY_ON_FOR_TIME == response->eExt_sys_bus_status);

                    p_eps_ctrl_dev->p_on_get_output_response_received(EPS_III_PDM_A_COMMANDSTATUS_SUCCESS == response->eCommand_status, status);
                }
                else
                {
                    // process notification
                    p_eps_ctrl_dev->p_on_set_output_response_received(EPS_III_PDM_A_COMMANDSTATUS_SUCCESS == response->eCommand_status);
                }
            }
            else
            {
                // nothing to do
            }
        }
        else
        {
            BREAK_ASSERT(false);
        }
    }
}

bool eps_iii_pdm_a_set_channel_output(const if_eps_ctrl_t *const p_eps_ctrl, uint8_t chn_id, bool new_state)
{
    ReqContext_t req_ctx = {
        .nAddr            = 0,
        .nInterfaceNumber = ESSASNI_SYS_PRI,
        .seqId            = 0, // Value to be updated by the ESPS Stack once the request is sent
        .netType          = ESSASNETT_INTERNAL
    };

    ESSATMAC_ErrCodes res                = ESSATMAC_EC_ERROR;
    bool              result             = false;
    uint8_t           response_of_cmd_id = UINT8_MAX;

    if (NULL != p_eps_ctrl)
    {
        // clear status for read requests, this is important because one and the same fp command is used for reading and writing to the channel
        // if read operation was sent and no answer was returned the flags have to be cleared.
        requested_chn_id = EPS_III_PDM_A_CHANNELS_CNT;

        req_ctx.nAddr = p_eps_ctrl->p_device_info->esps_dev_info.mac_addr;

        res = send_ch_cmd(chn_id, true, new_state, &req_ctx, &response_of_cmd_id);

        if (UINT8_MAX != response_of_cmd_id)
        {
            p_eps_ctrl->p_device_info->p_fdir_exec_status[response_of_cmd_id] = (fault_exec_status_t)res;
        }

        if (ESSATMAC_EC_OK == res)
        {
            p_eps_ctrl->p_device_info->esps_dev_info.seq_id = req_ctx.seqId;
            result                                          = true;
        }
    }
    else
    {
        BREAK_ASSERT(false);
    }

    return result;
}

bool eps_iii_pdm_a_get_channel_output(const if_eps_ctrl_t *const p_eps_ctrl, uint8_t chn_id)
{
    ReqContext_t req_ctx = {
        .nAddr            = 0,
        .nInterfaceNumber = ESSASNI_SYS_PRI,
        .seqId            = 0, // Value to be updated by the ESPS Stack once the request is sent
        .netType          = ESSASNETT_INTERNAL
    };

    ESSATMAC_ErrCodes res                = ESSATMAC_EC_ERROR;
    bool              result             = false;
    uint8_t           response_of_cmd_id = UINT8_MAX;

    if (NULL != p_eps_ctrl)
    {
        // clear status for read requests, this is important because one and the same fp command is used for reading and writing to the channel
        // if read operation was sent and no answer was returned the flags have to be cleared.
        requested_chn_id = EPS_III_PDM_A_CHANNELS_CNT;

        req_ctx.nAddr = p_eps_ctrl->p_device_info->esps_dev_info.mac_addr;

        res = send_ch_cmd(chn_id, false, false, &req_ctx, &response_of_cmd_id);

        if (UINT8_MAX != response_of_cmd_id)
        {
            p_eps_ctrl->p_device_info->p_fdir_exec_status[response_of_cmd_id] = (fault_exec_status_t)res;
        }

        if (ESSATMAC_EC_OK == res)
        {
            requested_chn_id                                = chn_id;
            p_eps_ctrl->p_device_info->esps_dev_info.seq_id = req_ctx.seqId;
            result                                          = true;
        }
    }
    else
    {
        BREAK_ASSERT(false);
    }

    return result;
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
static ESSATMAC_ErrCodes send_ch_cmd(uint8_t chn_id, bool is_cmd_set, bool new_state, ReqContext_t *p_req_ctx, eps_iii_pdm_a_cmd_e *const p_fp_cmd_id)
{
    ESSATMAC_ErrCodes res = ESSATMAC_EC_ERROR;

    CRIT_ASSERT(NULL != p_fp_cmd_id);
    CRIT_ASSERT(NULL != p_req_ctx);

    EPS_III_PDM_A_ChannelOpt_t req_state = EPS_III_PDM_A_CHANNELOPT_READ_STATUS;

    if (is_cmd_set)
    {
        req_state = new_state ? EPS_III_PDM_A_CHANNELOPT_SET_ON : EPS_III_PDM_A_CHANNELOPT_SET_OFF;
    }

    switch (chn_id)
    {
        case EPS_III_PDM_A_CHANNEL_3V3:
            res          = eps_iii_pdm_a_low_volt_controlReq(p_req_ctx, EPS_III_PDM_A_LOWVOLTAGECHANNELS_CHANNEL_3V3, req_state, 0);
            *p_fp_cmd_id = EPS_III_PDM_A_CMD_LOW_VOLTAGE;
            break;
        case EPS_III_PDM_A_CHANNEL_12V:
            res          = eps_iii_pdm_a_low_volt_controlReq(p_req_ctx, EPS_III_PDM_A_LOWVOLTAGECHANNELS_CHANNEL_12V, req_state, 0);
            *p_fp_cmd_id = EPS_III_PDM_A_CMD_LOW_VOLTAGE;
            break;
        case EPS_III_PDM_A_CHANNEL_5V:
            res          = eps_iii_pdm_a_low_volt_controlReq(p_req_ctx, EPS_III_PDM_A_LOWVOLTAGECHANNELS_CHANNEL_5V, req_state, 0);
            *p_fp_cmd_id = EPS_III_PDM_A_CMD_LOW_VOLTAGE;
            break;
        case EPS_III_PDM_A_GPIO_EXT_SYS_BUS:
            res          = eps_iii_pdm_a_external_system_bus_controlReq(p_req_ctx, req_state, 0);
            *p_fp_cmd_id = EPS_III_PDM_A_CMD_EXTERNAL_BUS;
            break;
        default:
            break;
    }

    return res;
}
