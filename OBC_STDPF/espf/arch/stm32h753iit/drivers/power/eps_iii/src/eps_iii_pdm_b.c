/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup eps_iii_pdm_b
 * @{
 *
 * @file     eps_iii_pdm_b.c
 * @brief    Power Distribution Module TypeB Driver implementation
 *
 * @}
 */

#include "eps_iii_pdm_b_cfg.h"
#include "eps_iii_pdm_b.h"

#include "if_tlm_dev.h"
#include "if_esps_dev.h"

#include "eps_iii_cfg.h"
#include "eps_iii.h"

#include <assert.h>
#include "assertions.h"

#include "FP_common/FP_BaseProtocolTypes.h"
#include "fp/eps_iii_pdm_b/v2.0/eps_iii_pdm_b_client/FP_eps_iii_pdm_bProtocolTypes.h"
#include "fp/eps_iii_pdm_b/v2.0/eps_iii_pdm_b_client/FP_eps_iii_pdm_bProtocolClient.h"

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
    eps_iii_pdm_b_datacache_info_types_t dc_element;
} eps_fdir_cmd_exec_info_type;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/
pdm_b_fdir_exec_status_t pdm_b_fdir_exec_status[EPS_III_PDM_B_INST_CNT][EPS_III_PDM_B_FDIR_COUNT];

const fdir_fault_id_t pdm_b_fdir_fault_ids[EPS_III_PDM_B_INST_CNT][EPS_III_PDM_B_FDIR_COUNT] = {
    EPS_III_PDM_B_FDIR_FAULTS_IDS
};

const get_telemetry_req_t pdm_b_tlm_req_cmds[PDM_B_TLM_CMD_CNT] = {
    &eps_iii_pdm_b_get_telemetryReq
};

const dc_did_id pdm_b_datacache_cmd_list[EPS_III_PDM_B_INST_CNT][EPS_III_PDM_B_DATACACHE_CMD_COUNT] = {
    EPS_III_PDM_B_DATACACHE_LIST_CMD
};

static const eps_fdir_cmd_exec_info_type pdm_b_map_dc_to_cmd[EPS_III_PDM_B_CMD_CNT] = {
    {"eps_iii_pdm_b_get_telemetry", EPS_III_PDM_B_ALL_MEASUREMENTS   },
    { "eps_iii_pdm_b_A_B_control",  EPS_III_PDM_B_DATACACHE_CMD_COUNT}
};

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
static eps_iii_pdm_b_chn_t requested_chn_id = EPS_III_PDM_B_CHANNELS_CNT;

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
static ESSATMAC_ErrCodes send_ch_cmd(uint8_t chn_id, bool is_cmd_set, bool new_state, ReqContext_t *p_req_ctx, eps_iii_pdm_b_cmd_e *const p_fp_cmd_id);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
void eps_iii_pdm_b_init(eps_iii_pdm_b_t *const self, uint8_t mac_address)
{
    // the type with command execution statuses must be aligned with the enumerator which contains the commands
    static_assert(EPS_III_PDM_B_CMD_CNT == sizeof(pdm_b_fdir_exec_status_t));

    BREAK_ASSERT(NULL != self);

    eps_dev_t *eps_dev_ctx = (eps_dev_t *)self;

    if ((NULL != self) && (NULL != eps_dev_ctx->p_dev_init))
    {
        // call parent init
        eps_dev_ctx->p_dev_init(eps_dev_ctx, mac_address);
    }
}

void eps_iii_pdm_b_process_fdir_faults(const eps_dev_t *const self)
{
    fault_exec_status_t err_code;
    bool                cmd_exec_failure = false;

    BREAK_ASSERT((NULL != self) && (NULL != self->datacache_cmd_list));

    if ((NULL != self) && (NULL != self->datacache_cmd_list))
    {
        for (uint8_t cmd_id = 0; cmd_id < EPS_III_PDM_B_CMD_CNT; cmd_id++)
        {
            uint8_t          buffer_to_read_in;
            dc_data_status_t res;
            if (EPS_III_PDM_B_DATACACHE_CMD_COUNT != pdm_b_map_dc_to_cmd[cmd_id].dc_element)
            {
                res = dc_get_raw_data(self->datacache_cmd_list[pdm_b_map_dc_to_cmd[cmd_id].dc_element],
                                      &buffer_to_read_in,
                                      sizeof(uint8_t),
                                      0,
                                      sizeof(uint8_t));

                if ((FDIR_CMD_EXEC_OK == self->p_fdir_exec_status[cmd_id]) && (DC_DATA_STATUS_TOUT == res))
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
                        self->datacache_cmd_list[EPS_III_PDM_B_FDIR_EXEC_STATUS],
                        self->p_fdir_exec_status,
                        sizeof(pdm_b_fdir_exec_status_t));

        dc_get_raw_data(self->datacache_cmd_list[EPS_III_PDM_B_FDIR_EXEC_STATUS],
                        self->p_fdir_exec_status,
                        sizeof(pdm_b_fdir_exec_status_t),
                        0,
                        sizeof(pdm_b_fdir_exec_status_t));

        for (uint8_t cmd_id = 0; cmd_id < EPS_III_PDM_B_CMD_CNT; cmd_id++)
        {
            // info and health
            err_code = self->p_fdir_exec_status[cmd_id];
            if (FDIR_CMD_EXEC_OK != err_code)
            {
                cmd_exec_failure = true;
                fdir_srv_log_if_clear(self->fdir_fault_ids[EPS_III_PDM_B_FDIR_CMD_EXEC_FAILURE],
                                      FDIR_AGENT_EPS_III,
                                      "FP %s failed with err code %d, BP mac %u",
                                      pdm_b_map_dc_to_cmd[cmd_id].cmd_name,
                                      err_code,
                                      self->esps_dev_info.mac_addr);
            }
        }

        if (false == cmd_exec_failure)
        {
            fdir_srv_log_if_raised(self->fdir_fault_ids[EPS_III_PDM_B_FDIR_CMD_EXEC_FAILURE],
                                   FDIR_AGENT_EPS_III,
                                   "All EPS II commands in current cycle succeeded");
        }
        (void)fdir_srv_fault_set_state(self->fdir_fault_ids[EPS_III_PDM_B_FDIR_CMD_EXEC_FAILURE],
                                       FDIR_AGENT_EPS_III,
                                       cmd_exec_failure,
                                       NULL);
    }
}

// serve notifications from FP commands.

void eps_iii_pdm_b_get_telemetry_notif(const RespContext_t *const pRespCtx, const eps_iii_pdm_bget_telemetryResponseData_t *const pResponseData)
{
    BREAK_ASSERT(NULL != pResponseData);

    if (NULL != pResponseData)
    {
        const bp_response_map_type map_response_to_dc_element[EPS_III_PDM_B_FDIR_EXEC_STATUS] = {
            {(const uint8_t *)&pResponseData->u32Uptime_in_seconds, sizeof(pResponseData->u32Uptime_in_seconds)},
            { (const uint8_t *)&pResponseData->sCommon,             sizeof(pResponseData->sCommon)             },
            { &pResponseData->eHib_mode,                            sizeof(pResponseData->eHib_mode)           },
            { (const uint8_t *)&pResponseData->sGeneral_outputs,    sizeof(pResponseData->sGeneral_outputs)    },
            { (const uint8_t *)&pResponseData->sChannel_flag_state, sizeof(pResponseData->sChannel_flag_state) },
            { (const uint8_t *)&pResponseData->sTemperature,        sizeof(pResponseData->sTemperature)        },
            { (const uint8_t *)&pResponseData->sAll_measurments,    sizeof(pResponseData->sAll_measurments)    }
        };

        telemetry_notif_process(pRespCtx, map_response_to_dc_element, EPS_III_PDM_B_FDIR_EXEC_STATUS);
    }
}

void eps_iii_pdm_b_A_B_control_notif(const RespContext_t *const pRespCtx, const eps_iii_pdm_bA_B_controlResponseData_t *const response)
{
    BREAK_ASSERT((NULL != response) && (NULL != pRespCtx));

    if ((NULL != response) && (NULL != pRespCtx))
    {
        const if_eps_ctrl_t *p_eps_ctrl_dev = eps_iii_get_eps_ctrl_by_addr(pRespCtx->nAddr);

        BREAK_ASSERT(NULL != p_eps_ctrl_dev);

        if ((NULL != p_eps_ctrl_dev) && (true == p_eps_ctrl_dev->p_device_info->p_is_seq_expected(p_eps_ctrl_dev->p_device_info, pRespCtx->seqId)))
        {
            if (EPS_III_PDM_B_CHANNELS_CNT != requested_chn_id)
            {
                EPS_III_PDM_B_ReadEnDftStatus_t returned_status = EPS_III_PDM_B_READENDFTSTATUS_MAX_CNT;
                switch (requested_chn_id)
                {
                    case EPS_III_PDM_B_CHANNEL_A:
                        returned_status = response->sData_a_channel.eChannel_status;
                        break;
                    case EPS_III_PDM_B_CHANNEL_B:
                        returned_status = response->sData_b_channel.eChannel_status;
                        break;
                    default:
                        break;
                }

                bool status = (EPS_III_PDM_B_READENDFTSTATUS_ON == returned_status) || (EPS_III_PDM_B_READENDFTSTATUS_ON_FOR_TIME == returned_status) || (EPS_III_PDM_B_READENDFTSTATUS_TOGGLE_BUSY_ON_FOR_TIME == returned_status);

                p_eps_ctrl_dev->p_on_get_output_response_received(EPS_III_PDM_B_COMMANDSTATUS_SUCCESS == response->eCommand_status, status);
            }
            else
            {
                // process notification
                p_eps_ctrl_dev->p_on_set_output_response_received(EPS_III_PDM_B_COMMANDSTATUS_SUCCESS == response->eCommand_status);
            }
        }
    }
}

bool eps_iii_pdm_b_set_channel_output(const if_eps_ctrl_t *const p_eps_ctrl, uint8_t chn_id, bool new_state)
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

    if ((NULL != p_eps_ctrl) && (NULL != p_eps_ctrl->p_device_info))
    {
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

bool eps_iii_pdm_b_get_channel_output(const if_eps_ctrl_t *const self, uint8_t chn_id)
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

    if ((NULL != self) && (NULL != self->p_device_info))
    {
        req_ctx.nAddr = self->p_device_info->esps_dev_info.mac_addr;

        res = send_ch_cmd(chn_id, false, false, &req_ctx, &response_of_cmd_id);

        if (UINT8_MAX != response_of_cmd_id)
        {
            self->p_device_info->p_fdir_exec_status[response_of_cmd_id] = (fault_exec_status_t)res;
        }

        if (ESSATMAC_EC_OK == res)
        {
            self->p_device_info->esps_dev_info.seq_id = req_ctx.seqId;
            result                                    = true;
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
static ESSATMAC_ErrCodes send_ch_cmd(uint8_t chn_id, bool is_cmd_set, bool new_state, ReqContext_t *p_req_ctx, eps_iii_pdm_b_cmd_e *const p_fp_cmd_id)
{
    ESSATMAC_ErrCodes res = ESSATMAC_EC_ERROR;

    CRIT_ASSERT(NULL != p_fp_cmd_id);
    CRIT_ASSERT(NULL != p_req_ctx);

    EPS_III_PDM_B_ChannelOpt_t req_state = EPS_III_PDM_B_CHANNELOPT_READ_STATUS;

    if (is_cmd_set)
    {
        req_state = new_state ? EPS_III_PDM_B_CHANNELOPT_SET_ON : EPS_III_PDM_B_CHANNELOPT_SET_OFF;
    }

    switch (chn_id)
    {
        case EPS_III_PDM_B_CHANNEL_A:
            res          = eps_iii_pdm_b_A_B_controlReq(p_req_ctx, EPS_III_PDM_B_A_B_CHANNELS_BUS_A, req_state, 0);
            *p_fp_cmd_id = EPS_III_PDM_B_CMD_A_B;
            break;
        case EPS_III_PDM_B_CHANNEL_B:
            res          = eps_iii_pdm_b_A_B_controlReq(p_req_ctx, EPS_III_PDM_B_A_B_CHANNELS_BUS_B, req_state, 0);
            *p_fp_cmd_id = EPS_III_PDM_B_CMD_A_B;
            break;
        default:
            break;
    }

    return res;
}
