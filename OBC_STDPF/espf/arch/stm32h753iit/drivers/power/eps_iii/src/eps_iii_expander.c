/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup eps_iii_expander
 * @{
 *
 * @file     eps_iii_expander.c
 * @brief    EPS III Expander Driver implementation
 *
 * @}
 */

#include "eps_iii_expander_cfg.h"
#include "eps_iii_expander.h"

#include "if_tlm_dev.h"
#include "if_esps_dev.h"

#include "eps_iii_cfg.h"
#include "eps_iii.h"

#include <assert.h>
#include "assertions.h"

#include "FP_common/FP_BaseProtocolTypes.h"
#include "fp/eps_iii_expander/v2.0/eps_iii_expander_client/FP_eps_iii_expanderProtocolTypes.h"
#include "fp/eps_iii_expander/v2.0/eps_iii_expander_client/FP_eps_iii_expanderProtocolClient.h"

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
    const char                             *cmd_name;
    eps_iii_expander_datacache_info_types_t dc_element;
} eps_fdir_cmd_exec_info_type;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/
expander_fdir_exec_status_t expander_fdir_exec_status[EPS_III_EXPANDER_INST_CNT][EPS_III_EXPANDER_FDIR_COUNT];

const fdir_fault_id_t expander_fdir_fault_ids[EPS_III_EXPANDER_INST_CNT][EPS_III_EXPANDER_FDIR_COUNT] = {
    EPS_III_EXPANDER_FDIR_FAULTS_IDS
};

const get_telemetry_req_t expander_tlm_req_cmds[EXPANDER_TLM_CMD_CNT] = {
    &eps_iii_expander_get_telemetryReq
};

const dc_did_id expander_datacache_cmd_list[EPS_III_EXPANDER_INST_CNT][EPS_III_EXPANDER_DATACACHE_CMD_COUNT] = {
    EPS_III_EXPANDER_DATACACHE_LIST_CMD
};

static const eps_fdir_cmd_exec_info_type expander_map_dc_to_cmd[EPS_III_EXPANDER_CMD_CNT] = {
    {"eps_iii_expander_get_telemetry",         EPS_III_EXPANDER_VOLT_AMP_MEASUREMENTS},
    { "eps_iii_expander_h1_channels_control",  EPS_III_EXPANDER_DATACACHE_CMD_COUNT  },
    { "eps_iii_expander_gpio_control",         EPS_III_EXPANDER_DATACACHE_CMD_COUNT  },
    { "eps_iii_expander_interconnect_control", EPS_III_EXPANDER_DATACACHE_CMD_COUNT  },
    { "eps_iii_expander_release_control",      EPS_III_EXPANDER_DATACACHE_CMD_COUNT  },
    { "eps_iii_expander_release_5v",           EPS_III_EXPANDER_DATACACHE_CMD_COUNT  }
};

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
/**
 * This variable is used to store the requested channel in case we have get command. It's important to have the channel
 * id for the get operation because when receiving the response there may be a different way of handling the response
 * depending on the channel ID.
 * When set operation is executed this variable is always set to EPS_III_EXPANDER_CHANNELS_CNT
 */
static eps_iii_expander_chn_t requested_chn_id = EPS_III_EXPANDER_CHANNELS_CNT;

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
static ESSATMAC_ErrCodes send_ch_cmd(uint8_t chn_id, bool is_cmd_set, bool new_state, ReqContext_t *p_req_ctx, eps_iii_expander_cmd_e *const p_fp_cmd_id);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
void eps_iii_expander_init(eps_iii_expander_t *const self, uint8_t mac_address)
{
    // the type with command execution statuses must be aligned with the enumerator which contains the commands
    static_assert(EPS_III_EXPANDER_CMD_CNT == sizeof(expander_fdir_exec_status_t));

    BREAK_ASSERT(NULL != self);

    eps_dev_t *eps_dev_ctx = (eps_dev_t *)self;

    if ((NULL != self) && (NULL != eps_dev_ctx->p_dev_init))
    {
        // call parent init
        eps_dev_ctx->p_dev_init(eps_dev_ctx, mac_address);
    }
}

void eps_iii_expander_process_fdir_faults(const eps_dev_t *const self)
{
    ESSATMAC_ErrCodes err_code;
    bool              cmd_exec_failure = false;

    BREAK_ASSERT(NULL != self);

    if (NULL != self)
    {
        for (uint8_t cmd_id = 0; cmd_id < EPS_III_EXPANDER_CMD_CNT; cmd_id++)
        {
            uint8_t          buffer_to_read_in;
            dc_data_status_t res;
            if (EPS_III_EXPANDER_DATACACHE_CMD_COUNT != expander_map_dc_to_cmd[cmd_id].dc_element)
            {
                res = dc_get_raw_data(self->datacache_cmd_list[expander_map_dc_to_cmd[cmd_id].dc_element],
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
                        self->datacache_cmd_list[EPS_III_EXPANDER_FDIR_EXEC_STATUS],
                        self->p_fdir_exec_status,
                        sizeof(expander_fdir_exec_status_t));

        dc_get_raw_data(self->datacache_cmd_list[EPS_III_EXPANDER_FDIR_EXEC_STATUS],
                        self->p_fdir_exec_status,
                        sizeof(expander_fdir_exec_status_t),
                        0,
                        sizeof(expander_fdir_exec_status_t));

        for (uint8_t cmd_id = 0; cmd_id < EPS_III_EXPANDER_CMD_CNT; cmd_id++)
        {
            // info and health
            err_code = ((uint8_t *)self->p_fdir_exec_status)[cmd_id];
            if (ESSATMAC_EC_OK != err_code)
            {
                cmd_exec_failure = true;
                fdir_srv_log_if_clear(self->fdir_fault_ids[EPS_III_EXPANDER_FDIR_CMD_EXEC_FAILURE],
                                      FDIR_AGENT_EPS_III,
                                      "FP %s failed with err code %d, BP mac %u",
                                      expander_map_dc_to_cmd[cmd_id].cmd_name,
                                      err_code,
                                      self->esps_dev_info.mac_addr);
            }
        }

        if (false == cmd_exec_failure)
        {
            fdir_srv_log_if_raised(self->fdir_fault_ids[EPS_III_EXPANDER_FDIR_CMD_EXEC_FAILURE],
                                   FDIR_AGENT_EPS_III,
                                   "All EPS II commands in current cycle succeeded");
        }
        (void)fdir_srv_fault_set_state(self->fdir_fault_ids[EPS_III_EXPANDER_FDIR_CMD_EXEC_FAILURE],
                                       FDIR_AGENT_EPS_III,
                                       cmd_exec_failure,
                                       NULL);
    }
}

// serve notifications from FP commands.

void eps_iii_expander_get_telemetry_notif(const RespContext_t *const pRespCtx, const eps_iii_expanderget_telemetryResponseData_t *const pResponseData)
{
    BREAK_ASSERT(NULL != pResponseData);

    if (NULL != pResponseData)
    {
        const bp_response_map_type map_response_to_dc_element[EPS_III_EXPANDER_FDIR_EXEC_STATUS] = {
            {(const uint8_t *)&pResponseData->u32Uptime_in_seconds,  sizeof(pResponseData->u32Uptime_in_seconds)},
            { (const uint8_t *)&pResponseData->sCommon,              sizeof(pResponseData->sCommon)             },
            { (const uint8_t *)&pResponseData->sOutputs,             sizeof(pResponseData->sOutputs)            },
            { (const uint8_t *)&pResponseData->sGeneral_inputs,      sizeof(pResponseData->sGeneral_inputs)     },
            { (const uint8_t *)&pResponseData->sFeedbacks,           sizeof(pResponseData->sFeedbacks)          },
            { (const uint8_t *)&pResponseData->sVolt_amp_mesurments, sizeof(pResponseData->sVolt_amp_mesurments)}
        };

        telemetry_notif_process(pRespCtx, map_response_to_dc_element, EPS_III_EXPANDER_FDIR_EXEC_STATUS);
    }
}

void eps_iii_expander_h1_channels_control_notif(const RespContext_t *const pRespCtx, const eps_iii_expanderh1_channels_controlResponseData_t *const response)
{
    BREAK_ASSERT((NULL != response) && (NULL != pRespCtx));

    if ((NULL != response) && (NULL != pRespCtx))
    {
        const if_eps_ctrl_t *p_eps_ctrl_dev = eps_iii_get_eps_ctrl_by_addr(pRespCtx->nAddr);

        BREAK_ASSERT(NULL != p_eps_ctrl_dev);

        if (NULL != p_eps_ctrl_dev)
        {
            if (true == p_eps_ctrl_dev->p_device_info->p_is_seq_expected(p_eps_ctrl_dev->p_device_info, pRespCtx->seqId))
            {
                if (EPS_III_EXPANDER_CHANNELS_CNT != requested_chn_id)
                {
                    // process get channel notification
                    bool status = ((EPS_III_EXPANDER_READENDFTSTATUS_ON == response->eH1_status) || (EPS_III_EXPANDER_READENDFTSTATUS_ON_FOR_TIME == response->eH1_status));
                    p_eps_ctrl_dev->p_on_get_output_response_received(EPS_III_EXPANDER_COMMANDSTATUS_SUCCESS == response->eCommand_status, status);
                }
                else
                {
                    // process set channel notification
                    p_eps_ctrl_dev->p_on_set_output_response_received(EPS_III_EXPANDER_COMMANDSTATUS_SUCCESS == response->eCommand_status);
                }
            }
            else
            {
                // nothing to do
            }
        }
    }
}
void eps_iii_expander_gpio_control_notif(const RespContext_t *const pRespCtx, const eps_iii_expandergpio_controlResponseData_t *const response)
{
    BREAK_ASSERT((NULL != response) && (NULL != pRespCtx));

    if ((NULL != response) && (NULL != pRespCtx))
    {
        const if_eps_ctrl_t *p_eps_ctrl_dev = eps_iii_get_eps_ctrl_by_addr(pRespCtx->nAddr);

        BREAK_ASSERT(NULL != p_eps_ctrl_dev);

        if (NULL != p_eps_ctrl_dev)
        {
            if (true == p_eps_ctrl_dev->p_device_info->p_is_seq_expected(p_eps_ctrl_dev->p_device_info, pRespCtx->seqId))
            {
                if (EPS_III_EXPANDER_CHANNELS_CNT != requested_chn_id)
                {
                    bool status = ((EPS_III_EXPANDER_READENDFTSTATUS_ON == response->eGpio_input_state) || (EPS_III_EXPANDER_READENDFTSTATUS_ON_FOR_TIME == response->eGpio_input_state));
                    // process get channel notification
                    p_eps_ctrl_dev->p_on_get_output_response_received(EPS_III_EXPANDER_COMMANDSTATUS_SUCCESS == response->eCommand_status, status);
                }
                else
                { // process set channel notification
                    p_eps_ctrl_dev->p_on_set_output_response_received(EPS_III_EXPANDER_COMMANDSTATUS_SUCCESS == response->eCommand_status);
                }
            }
            else
            {
                // nothing to do
            }
        }
    }
}

void eps_iii_expander_interconnect_control_notif(const RespContext_t *const pRespCtx, const eps_iii_expanderinterconnect_controlResponseData_t *const response)
{
    BREAK_ASSERT((NULL != response) && (NULL != pRespCtx));

    if ((NULL != response) && (NULL != pRespCtx))
    {
        const if_eps_ctrl_t *p_eps_ctrl_dev = eps_iii_get_eps_ctrl_by_addr(pRespCtx->nAddr);

        BREAK_ASSERT(NULL != p_eps_ctrl_dev);

        if (NULL != p_eps_ctrl_dev)
        {
            if (true == p_eps_ctrl_dev->p_device_info->p_is_seq_expected(p_eps_ctrl_dev->p_device_info, pRespCtx->seqId))
            {
                if (EPS_III_EXPANDER_CHANNELS_CNT != requested_chn_id)
                {
                    bool status = ((EPS_III_EXPANDER_READENDFTSTATUS_ON == response->eInterc_status) || (EPS_III_EXPANDER_READENDFTSTATUS_ON_FOR_TIME == response->eInterc_status));
                    // process get channel notification
                    p_eps_ctrl_dev->p_on_get_output_response_received(EPS_III_EXPANDER_COMMANDSTATUS_SUCCESS == response->eCommand_status, status);
                }
                else
                { // process set channel notification
                    p_eps_ctrl_dev->p_on_set_output_response_received(EPS_III_EXPANDER_COMMANDSTATUS_SUCCESS == response->eCommand_status);
                }
            }
            else
            {
                // nothing to do
            }
        }
    }
}

void eps_iii_expander_release_control_notif(const RespContext_t *const pRespCtx, const eps_iii_expanderrelease_controlResponseData_t *const response)
{
    BREAK_ASSERT((NULL != response));
    BREAK_ASSERT(NULL != pRespCtx);
    if ((NULL != response) && (NULL != pRespCtx))
    {
        const if_eps_ctrl_t *p_eps_ctrl_dev = eps_iii_get_eps_ctrl_by_addr(pRespCtx->nAddr);

        BREAK_ASSERT(NULL != p_eps_ctrl_dev);
        BREAK_ASSERT(NULL != p_eps_ctrl_dev->p_device_info);
        BREAK_ASSERT(NULL != p_eps_ctrl_dev->p_device_info->p_is_seq_expected);

        if ((NULL != p_eps_ctrl_dev) && (NULL != p_eps_ctrl_dev->p_device_info) && (NULL != p_eps_ctrl_dev->p_device_info->p_is_seq_expected))
        {
            bool is_seq_ok = p_eps_ctrl_dev->p_device_info->p_is_seq_expected(p_eps_ctrl_dev->p_device_info, pRespCtx->seqId);
            if (true == is_seq_ok)
            {
                // we care about channel number only in case we have a get command because we may need to get results from different place
                // when set command is used only status is returned and it's always one
                if (EPS_III_EXPANDER_CHANNELS_CNT != requested_chn_id)
                {
                    EPS_III_EXPANDER_ReadRlStatus_t ch_status        = EPS_III_EXPANDER_READRLSTATUS_MAX_CNT;
                    EPS_III_EXPANDER_ReadLvlState_t in_ch_status     = EPS_III_EXPANDER_READLVLSTATE_MAX_CNT;
                    bool                            is_input_channel = false;
                    switch (requested_chn_id)
                    {
                        case EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_1_A:
                        case EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_2_A:
                        case EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_3_A:
                        case EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_4_A:
                            ch_status = response->sA_status.eRl_a_b_status;
                            break;
                        case EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_1_B:
                        case EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_2_B:
                        case EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_3_B:
                        case EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_4_B:
                            ch_status = response->sB_status.eRl_a_b_status;
                            break;
                        case EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_1_Fb1:
                        case EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_2_Fb1:
                        case EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_3_Fb1:
                        case EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_4_Fb1:
                            in_ch_status     = response->eFb_1_state;
                            is_input_channel = true;
                            break;
                        case EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_1_Fb2:
                        case EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_2_Fb2:
                        case EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_3_Fb2:
                        case EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_4_Fb2:
                            in_ch_status     = response->eFb_2_state;
                            is_input_channel = true;
                            break;
                        default:
                            break;
                    }

                    // process get channel notification
                    if (is_input_channel)
                    {
                        p_eps_ctrl_dev->p_on_get_output_response_received(EPS_III_EXPANDER_COMMANDSTATUS_SUCCESS == response->eCommand_status, EPS_III_EXPANDER_READLVLSTATE_HIGH == in_ch_status);
                    }
                    else
                    {
                        p_eps_ctrl_dev->p_on_get_output_response_received(EPS_III_EXPANDER_COMMANDSTATUS_SUCCESS == response->eCommand_status, EPS_III_EXPANDER_READRLSTATUS_ON_FOR_TIME == ch_status);
                    }
                }
                else
                {
                    // process set channel notification
                    p_eps_ctrl_dev->p_on_set_output_response_received(EPS_III_EXPANDER_COMMANDSTATUS_SUCCESS == response->eCommand_status);
                }
            }
        }
    }
}

void eps_iii_expander_release_5v_control_notif(const RespContext_t *const pRespCtx, const eps_iii_expanderrelease_5vResponseData_t *const response)
{
    BREAK_ASSERT((NULL != response) && (NULL != pRespCtx));

    if ((NULL != response) && (NULL != pRespCtx))
    {
        const if_eps_ctrl_t *p_eps_ctrl_dev = eps_iii_get_eps_ctrl_by_addr(pRespCtx->nAddr);

        BREAK_ASSERT(NULL != p_eps_ctrl_dev);

        if (NULL != p_eps_ctrl_dev)
        {
            if (true == p_eps_ctrl_dev->p_device_info->p_is_seq_expected(p_eps_ctrl_dev->p_device_info, pRespCtx->seqId))
            {
                if (EPS_III_EXPANDER_CHANNELS_CNT != requested_chn_id)
                {
                    bool status = ((EPS_III_EXPANDER_READENDFTSTATUS_ON == response->sRl_5v_data.eRl_5v_status) || (EPS_III_EXPANDER_READENDFTSTATUS_ON_FOR_TIME == response->sRl_5v_data.eRl_5v_status));
                    // process get channel notification
                    p_eps_ctrl_dev->p_on_get_output_response_received(EPS_III_EXPANDER_COMMANDSTATUS_SUCCESS == response->eCommand_status, status);
                }
                else
                {
                    // process set channel notification
                    p_eps_ctrl_dev->p_on_set_output_response_received(EPS_III_EXPANDER_COMMANDSTATUS_SUCCESS == response->eCommand_status);
                }
            }
        }
    }
}

bool eps_iii_expander_set_channel_output(const if_eps_ctrl_t *const p_eps_ctrl, uint8_t chn_id, bool new_state)
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

    BREAK_ASSERT(NULL != p_eps_ctrl);
    BREAK_ASSERT(EPS_III_EXPANDER_CHANNELS_CNT > chn_id);

    requested_chn_id = EPS_III_EXPANDER_CHANNELS_CNT;

    // the check makes sure that if request for setting an input channel is done false result will be returned.
    if ((NULL != p_eps_ctrl) && (EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_1_Fb1 > chn_id))
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

    return result;
}

bool eps_iii_expander_get_channel_output(const if_eps_ctrl_t *const p_eps_ctrl, uint8_t chn_id)
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

    requested_chn_id = EPS_III_EXPANDER_CHANNELS_CNT;

    if (NULL != p_eps_ctrl)
    {
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
static ESSATMAC_ErrCodes send_ch_cmd(uint8_t chn_id, bool is_cmd_set, bool new_state, ReqContext_t *p_req_ctx, eps_iii_expander_cmd_e *const p_fp_cmd_id)
{
    typedef struct
    {
        eps_iii_expander_cmd_e cmd_id;
        uint8_t                expander_ch_id;
    } map_eps_iii_ch_to_expander_ch_id_t;

    const map_eps_iii_ch_to_expander_ch_id_t map_ch_id_to_cmd_id[EPS_III_EXPANDER_CHANNELS_CNT] = {
        {EPS_III_EXPANDER_CMD_H1_CHANNELS_CONTROL,   EPS_III_EXPANDER_HLVCHANNELID_LV_H1_47_48            },
        { EPS_III_EXPANDER_CMD_H1_CHANNELS_CONTROL,  EPS_III_EXPANDER_HLVCHANNELID_HV_H1_47_48            },
        { EPS_III_EXPANDER_CMD_H1_CHANNELS_CONTROL,  EPS_III_EXPANDER_HLVCHANNELID_LV_H1_49_50            },
        { EPS_III_EXPANDER_CMD_H1_CHANNELS_CONTROL,  EPS_III_EXPANDER_HLVCHANNELID_HV_H1_49_50            },
        { EPS_III_EXPANDER_CMD_H1_CHANNELS_CONTROL,  EPS_III_EXPANDER_HLVCHANNELID_LV_H1_51_52            },
        { EPS_III_EXPANDER_CMD_H1_CHANNELS_CONTROL,  EPS_III_EXPANDER_HLVCHANNELID_HV_H1_51_52            },
        { EPS_III_EXPANDER_CMD_GPIO_CONTROL,         EPS_III_EXPANDER_GPIOCHANNELID_GPIO_1                },
        { EPS_III_EXPANDER_CMD_GPIO_CONTROL,         EPS_III_EXPANDER_GPIOCHANNELID_GPIO_2                },
        { EPS_III_EXPANDER_CMD_GPIO_CONTROL,         EPS_III_EXPANDER_GPIOCHANNELID_GPIO_3                },
        { EPS_III_EXPANDER_CMD_GPIO_CONTROL,         EPS_III_EXPANDER_GPIOCHANNELID_GPIO_4                },
        { EPS_III_EXPANDER_CMD_GPIO_CONTROL,         EPS_III_EXPANDER_GPIOCHANNELID_GPIO_5                },
        { EPS_III_EXPANDER_CMD_GPIO_CONTROL,         EPS_III_EXPANDER_GPIOCHANNELID_GPIO_6                },
        { EPS_III_EXPANDER_CMD_GPIO_CONTROL,         EPS_III_EXPANDER_GPIOCHANNELID_GPIO_7                },
        { EPS_III_EXPANDER_CMD_GPIO_CONTROL,         EPS_III_EXPANDER_GPIOCHANNELID_GPIO_8                },
        { EPS_III_EXPANDER_CMD_INTERCONNECT_CONTROL, EPS_III_EXPANDER_INTERCCHANNELID_INTERCONNECT_3V3    },
        { EPS_III_EXPANDER_CMD_INTERCONNECT_CONTROL, EPS_III_EXPANDER_INTERCCHANNELID_INTERCONNECT_5V     },
        { EPS_III_EXPANDER_CMD_INTERCONNECT_CONTROL, EPS_III_EXPANDER_INTERCCHANNELID_INTERCONNECT_12V    },
        { EPS_III_EXPANDER_CMD_INTERCONNECT_CONTROL, EPS_III_EXPANDER_INTERCCHANNELID_INTERCONNECT_BATTERY},
        { EPS_III_EXPANDER_CMD_RELEASE_5V_CONTROL,   EPS_III_EXPANDER_R5VCHANNELID_RELEASE_CONNECTOR_1_5V },
        { EPS_III_EXPANDER_CMD_RELEASE_5V_CONTROL,   EPS_III_EXPANDER_R5VCHANNELID_RELEASE_CONNECTOR_2_5V },
        { EPS_III_EXPANDER_CMD_RELEASE_5V_CONTROL,   EPS_III_EXPANDER_R5VCHANNELID_RELEASE_CONNECTOR_3_5V },
        { EPS_III_EXPANDER_CMD_RELEASE_5V_CONTROL,   EPS_III_EXPANDER_R5VCHANNELID_RELEASE_CONNECTOR_4_5V },
        { EPS_III_EXPANDER_CMD_RELEASE_CONTROL,      EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_1_A    },
        { EPS_III_EXPANDER_CMD_RELEASE_CONTROL,      EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_1_B    },
        { EPS_III_EXPANDER_CMD_RELEASE_CONTROL,      EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_2_A    },
        { EPS_III_EXPANDER_CMD_RELEASE_CONTROL,      EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_2_B    },
        { EPS_III_EXPANDER_CMD_RELEASE_CONTROL,      EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_3_A    },
        { EPS_III_EXPANDER_CMD_RELEASE_CONTROL,      EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_3_B    },
        { EPS_III_EXPANDER_CMD_RELEASE_CONTROL,      EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_4_A    },
        { EPS_III_EXPANDER_CMD_RELEASE_CONTROL,      EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_4_B    },
        { EPS_III_EXPANDER_CMD_RELEASE_CONTROL,      EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_1_A    },
        { EPS_III_EXPANDER_CMD_RELEASE_CONTROL,      EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_1_A    },
        { EPS_III_EXPANDER_CMD_RELEASE_CONTROL,      EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_1_A    },
        { EPS_III_EXPANDER_CMD_RELEASE_CONTROL,      EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_1_A    },
        { EPS_III_EXPANDER_CMD_RELEASE_CONTROL,      EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_1_A    },
        { EPS_III_EXPANDER_CMD_RELEASE_CONTROL,      EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_1_A    },
        { EPS_III_EXPANDER_CMD_RELEASE_CONTROL,      EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_1_A    },
        { EPS_III_EXPANDER_CMD_RELEASE_CONTROL,      EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_1_A    }
    };
    ESSATMAC_ErrCodes res       = ESSATMAC_EC_ERROR;
    uint8_t           req_state = EPS_III_EXPANDER_CHANNELOPT_READ_STATUS;

    CRIT_ASSERT(NULL != p_fp_cmd_id);
    CRIT_ASSERT(NULL != p_req_ctx);
    CRIT_ASSERT(EPS_III_EXPANDER_CHANNELS_CNT > chn_id);

    requested_chn_id = EPS_III_EXPANDER_CHANNELS_CNT;

    if (is_cmd_set)
    {
        // ensure this channel is not only an input
        if (chn_id < EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_1_Fb1)
        {
            if ((chn_id >= EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_1_A) && (chn_id <= EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_4_B))
            {
                req_state = new_state ? EPS_III_EXPANDER_RCHANNELOPT_SET_ON_FOR_TIME_MAX : EPS_III_EXPANDER_RCHANNELOPT_SET_OFF;
            }
            else
            {
                req_state = new_state ? EPS_III_EXPANDER_CHANNELOPT_SET_ON : EPS_III_EXPANDER_CHANNELOPT_SET_OFF;
            }
        }
        else
        {
            res = ESSATMAC_EC_INVALID_PARAMS;
        }
    }

    if (ESSATMAC_EC_INVALID_PARAMS != res)
    {
        switch (map_ch_id_to_cmd_id[chn_id].cmd_id)
        {
            case EPS_III_EXPANDER_CMD_H1_CHANNELS_CONTROL:
                res = eps_iii_expander_h1_channels_controlReq(p_req_ctx, map_ch_id_to_cmd_id[chn_id].expander_ch_id, req_state, 0);
                break;
            case EPS_III_EXPANDER_CMD_GPIO_CONTROL:
                res = eps_iii_expander_gpio_controlReq(p_req_ctx, map_ch_id_to_cmd_id[chn_id].expander_ch_id, req_state, 0);
                break;
            case EPS_III_EXPANDER_CMD_INTERCONNECT_CONTROL:
                res = eps_iii_expander_interconnect_controlReq(p_req_ctx, map_ch_id_to_cmd_id[chn_id].expander_ch_id, req_state, 0);
                break;
            case EPS_III_EXPANDER_CMD_RELEASE_CONTROL:
                res = eps_iii_expander_release_controlReq(p_req_ctx, map_ch_id_to_cmd_id[chn_id].expander_ch_id, req_state, 0);
                break;
            case EPS_III_EXPANDER_CMD_RELEASE_5V_CONTROL:
                res = eps_iii_expander_release_5vReq(p_req_ctx, map_ch_id_to_cmd_id[chn_id].expander_ch_id, req_state, 0);
                break;
            default:
                break;
        }

        *p_fp_cmd_id = map_ch_id_to_cmd_id[chn_id].cmd_id;
    }

    return res;
}
