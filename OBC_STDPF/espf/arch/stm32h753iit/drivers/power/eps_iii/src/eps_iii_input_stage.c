/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup eps_iii_input_stage
 * @{
 *
 * @file     eps_iii_input_stage.c
 * @brief    EPS III Input Stage Driver implementation
 *
 * @}
 */

#include "eps_iii_input_stage_cfg.h"
#include "eps_iii_input_stage.h"

#include "if_tlm_dev.h"
#include "if_esps_dev.h"
#include "if_eps_dev.h"

#include "eps_iii_cfg.h"
#include "eps_iii.h"

#include <assert.h>
#include "assertions.h"

#include "FP_common/FP_BaseProtocolTypes.h"
#include "fp/eps_iii_input_stage/v2.0/eps_iii_input_stage_client/FP_eps_iii_input_stageProtocolTypes.h"
#include "fp/eps_iii_input_stage/v2.0/eps_iii_input_stage_client/FP_eps_iii_input_stageProtocolClient.h"

#include "fdir_srv.h"

typedef ESSATMAC_ErrCodes (*telemetry_req)(ReqContext_t *ctx);

typedef struct
{
    const char                                *cmd_name;
    eps_iii_input_stage_datacache_info_types_t dc_element;
} eps_fdir_cmd_exec_info_type;

input_stage_fdir_exec_status_t input_stage_fdir_exec_status[EPS_III_INPUT_STAGE_INST_CNT][EPS_III_INPUT_STAGE_FDIR_COUNT];
const fdir_fault_id_t          input_stage_fdir_fault_ids[EPS_III_INPUT_STAGE_INST_CNT][EPS_III_INPUT_STAGE_FDIR_COUNT] = {
    EPS_III_INPUT_STAGE_FDIR_FAULTS_IDS
};

const get_telemetry_req_t input_stage_tlm_req_cmds[INPUT_STAGE_TLM_CMD_CNT] = {
    &eps_iii_input_stage_get_telemetryReq
};

const dc_did_id input_stage_datacache_cmd_list[EPS_III_INPUT_STAGE_INST_CNT][EPS_III_INPUT_STAGE_DATACACHE_CMD_COUNT] = {
    EPS_III_INPUT_STAGE_DATACACHE_LIST_CMD
};

static const eps_fdir_cmd_exec_info_type input_stage_map_dc_to_cmd[INPUT_STAGE_TLM_CMD_CNT] = {
    {"eps_iii_input_stage_get_telemetry", EPS_III_INPUT_STAGE_COMMON},
};

void eps_iii_input_stage_init(eps_iii_input_stage_t *const self, uint8_t mac_address)
{
    // the type with command execution statuses must be aligned with the enumerator which contains the commands
    static_assert(EPS_III_INPUT_STAGE_CMD_CNT == sizeof(input_stage_fdir_exec_status_t));

    BREAK_ASSERT(NULL != self);
    eps_dev_t *eps_dev_ctx = (eps_dev_t *)self;

    if ((NULL != self) && (NULL != eps_dev_ctx->p_dev_init))
    {
        // call parent init
        eps_dev_ctx->p_dev_init(eps_dev_ctx, mac_address);
    }
}

void eps_iii_input_stage_process_fdir_faults(const eps_dev_t *const self)
{
    ESSATMAC_ErrCodes err_code;
    bool              cmd_exec_failure = false;

    BREAK_ASSERT(NULL != self);

    if (NULL != self)
    {
        for (uint8_t cmd_id = 0; cmd_id < INPUT_STAGE_TLM_CMD_CNT; cmd_id++)
        {
            uint8_t          buffer_to_read_in;
            dc_data_status_t res;
            if (EPS_III_INPUT_STAGE_DATACACHE_CMD_COUNT != input_stage_map_dc_to_cmd[cmd_id].dc_element)
            {
                res = dc_get_raw_data(self->datacache_cmd_list[input_stage_map_dc_to_cmd[cmd_id].dc_element],
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
                        self->datacache_cmd_list[EPS_III_INPUT_STAGE_FDIR_EXEC_STATUS],
                        self->p_fdir_exec_status,
                        sizeof(input_stage_fdir_exec_status_t));

        dc_get_raw_data(self->datacache_cmd_list[EPS_III_INPUT_STAGE_FDIR_EXEC_STATUS],
                        self->p_fdir_exec_status,
                        sizeof(input_stage_fdir_exec_status_t),
                        0,
                        sizeof(input_stage_fdir_exec_status_t));

        for (uint8_t cmd_id = 0; cmd_id < INPUT_STAGE_TLM_CMD_CNT; cmd_id++)
        {
            // info and health
            err_code = ((uint8_t *)self->p_fdir_exec_status)[cmd_id];
            if (ESSATMAC_EC_OK != err_code)
            {
                cmd_exec_failure = true;
                fdir_srv_log_if_clear(self->fdir_fault_ids[EPS_III_INPUT_STAGE_FDIR_CMD_EXEC_FAILURE],
                                      FDIR_AGENT_EPS_III,
                                      "FP %s failed with err code %d, BP mac %u",
                                      input_stage_map_dc_to_cmd[cmd_id].cmd_name,
                                      err_code,
                                      self->esps_dev_info.mac_addr);
            }
        }

        if (false == cmd_exec_failure)
        {
            fdir_srv_log_if_raised(self->fdir_fault_ids[EPS_III_INPUT_STAGE_FDIR_CMD_EXEC_FAILURE],
                                   FDIR_AGENT_EPS_III,
                                   "All EPS II commands in current cycle succeeded");
        }
        (void)fdir_srv_fault_set_state(self->fdir_fault_ids[EPS_III_INPUT_STAGE_FDIR_CMD_EXEC_FAILURE],
                                       FDIR_AGENT_EPS_III,
                                       cmd_exec_failure,
                                       NULL);
    }
}

// serve notifications from FP commands.
void eps_iii_input_stage_get_telemetry_notif(const RespContext_t *const pRespCtx, const eps_iii_input_stageget_telemetryResponseData_t *const pResponseData)
{
    BREAK_ASSERT(NULL != pResponseData);

    if (NULL != pResponseData)
    {
        const bp_response_map_type map_response_to_dc_element[EPS_III_INPUT_STAGE_FDIR_EXEC_STATUS] = {
            {(const uint8_t *)&pResponseData->u32Uptime_in_seconds, sizeof(pResponseData->u32Uptime_in_seconds)},
            { (const uint8_t *)&pResponseData->sCommon,             sizeof(pResponseData->sCommon)             },
            { &pResponseData->eHib_mode,                            sizeof(pResponseData->eHib_mode)           },
            { &pResponseData->eSelflock_on,                         sizeof(pResponseData->eSelflock_on)        },
            { (const uint8_t *)&pResponseData->sSp1,                sizeof(pResponseData->sSp1)                },
            { (const uint8_t *)&pResponseData->sSp2,                sizeof(pResponseData->sSp2)                },
            { (const uint8_t *)&pResponseData->sSp3,                sizeof(pResponseData->sSp3)                },
            { (const uint8_t *)&pResponseData->sSystem_bus,         sizeof(pResponseData->sSystem_bus)         },
            { (const uint8_t *)&pResponseData->sBus_7v5,            sizeof(pResponseData->sBus_7v5)            },
            { &pResponseData->eBus_7v5_power_good,                  sizeof(pResponseData->eBus_7v5_power_good) },
            { &pResponseData->eUndervoltage_7V5,                    sizeof(pResponseData->eUndervoltage_7V5)   },
            { (const uint8_t *)&pResponseData->sBus_3v3,            sizeof(pResponseData->sBus_3v3)            },
            { &pResponseData->eUndervoltage_3V3,                    sizeof(pResponseData->eUndervoltage_3V3)   }
        };
        telemetry_notif_process(pRespCtx, map_response_to_dc_element, EPS_III_INPUT_STAGE_FDIR_EXEC_STATUS);
    }
}
