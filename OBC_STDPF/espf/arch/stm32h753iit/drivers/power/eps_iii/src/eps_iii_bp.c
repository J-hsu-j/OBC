/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup eps_iii_bp
 * @{
 *
 * @file     eps_iii_bp.c
 * @brief    EPS III Battery Pack Driver implementation
 *
 * @}
 */

#include "eps_iii_bp_cfg.h"
#include "eps_iii_bp.h"

#include "if_tlm_dev.h"
#include "if_esps_dev.h"

#include "eps_iii_cfg.h"
#include "eps_iii.h"

#include <assert.h>
#include "assertions.h"

#include "FP_common/FP_BaseProtocolTypes.h"
#include "fp/eps_iii_batt_pack/v2.0/eps_iii_batt_pack_client/FP_eps_iii_batt_packProtocolTypes.h"
#include "fp/eps_iii_batt_pack/v2.0/eps_iii_batt_pack_client/FP_eps_iii_batt_packProtocolClient.h"

#include "fdir_srv.h"

#include "conops.h"
#include "datacache.h"

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
    const char                       *cmd_name;
    eps_iii_bp_datacache_info_types_t dc_element;
} eps_fdir_cmd_exec_info_type;

bp_fdir_exec_status_t bp_fdir_exec_status[EPS_III_BP_INST_CNT][EPS_III_BP_FDIR_COUNT];
const fdir_fault_id_t bp_fdir_fault_ids[EPS_III_BP_INST_CNT][EPS_III_BP_FDIR_COUNT] = {
    EPS_III_BP_FDIR_FAULTS_IDS
};

const get_telemetry_req_t bp_tlm_req_cmds[BP_TLM_CMD_CNT] = {
    &eps_iii_batt_pack_get_telemetryReq
};

const dc_did_id bp_datacache_cmd_list[EPS_III_BP_INST_CNT][EPS_III_BP_DATACACHE_CMD_COUNT] = {
    EPS_III_BP_DATACACHE_LIST_CMD
};

static const eps_fdir_cmd_exec_info_type bp_map_dc_to_cmd[BP_TLM_CMD_CNT] = {
    {"eps_iii_bp_get_telemetry", EPS_III_BP_MEASUREMENTS}, /* BP_GET_1 */
};

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
static void eps_iii_bp_fdir_checks(const eps_dev_t *const device_info);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
void eps_iii_bp_init(eps_iii_bp_t *const self, uint8_t mac_address)
{
    // the type with command execution statuses must be aligned with the enumerator which contains the commands
    static_assert(EPS_III_BP_CMD_CNT == sizeof(bp_fdir_exec_status_t));
    BREAK_ASSERT(NULL != self);

    eps_dev_t *p_parent = (eps_dev_t *)self;

    if ((NULL != self) && (NULL != p_parent->p_dev_init))
    {
        // call parent init
        p_parent->p_dev_init(p_parent, mac_address);
    }
}

void eps_iii_bp_process_fdir_faults(const eps_dev_t *const self)
{
    fault_exec_status_t err_code;
    bool                cmd_exec_failure = false;

    BREAK_ASSERT(NULL != self);

    if (NULL != self)
    {
        for (uint8_t cmd_id = 0; cmd_id < BP_TLM_CMD_CNT; cmd_id++)
        {
            uint8_t          buffer_to_read_in;
            dc_data_status_t res;
            if (EPS_III_BP_DATACACHE_CMD_COUNT != bp_map_dc_to_cmd[cmd_id].dc_element)
            {
                res = dc_get_raw_data(self->datacache_cmd_list[bp_map_dc_to_cmd[cmd_id].dc_element],
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
                        self->datacache_cmd_list[EPS_III_BP_FDIR_EXEC_STATUS],
                        self->p_fdir_exec_status,
                        sizeof(bp_fdir_exec_status_t));

        dc_get_raw_data(self->datacache_cmd_list[EPS_III_BP_FDIR_EXEC_STATUS],
                        self->p_fdir_exec_status,
                        sizeof(bp_fdir_exec_status_t),
                        0,
                        sizeof(bp_fdir_exec_status_t));

        for (uint8_t cmd_id = 0; cmd_id < BP_TLM_CMD_CNT; cmd_id++)
        {
            // info and health
            err_code = self->p_fdir_exec_status[cmd_id];
            if (FDIR_CMD_EXEC_OK != err_code)
            {
                cmd_exec_failure = true;
                fdir_srv_log_if_clear(self->fdir_fault_ids[EPS_III_BP_FDIR_CMD_EXEC_FAILURE],
                                      FDIR_AGENT_EPS_III,
                                      "FP %s failed with err code %d, BP mac %u",
                                      bp_map_dc_to_cmd[cmd_id].cmd_name,
                                      err_code,
                                      self->esps_dev_info.mac_addr);
            }
        }

        if (false == cmd_exec_failure)
        {
            fdir_srv_log_if_raised(self->fdir_fault_ids[EPS_III_BP_FDIR_CMD_EXEC_FAILURE],
                                   FDIR_AGENT_EPS_III,
                                   "All EPS III commands in current cycle succeeded");
        }
        (void)fdir_srv_fault_set_state(self->fdir_fault_ids[EPS_III_BP_FDIR_CMD_EXEC_FAILURE],
                                       FDIR_AGENT_EPS_III,
                                       cmd_exec_failure,
                                       NULL);

        eps_iii_bp_fdir_checks(self);
    }
}

// serve notifications from FP commands.
void eps_iii_bp_get_telemetry_notif(const RespContext_t *const pRespCtx, const eps_iii_batt_packget_telemetryResponseData_t *const pResponseData)
{
    BREAK_ASSERT(NULL != pResponseData);
    if (NULL != pResponseData)
    {
        const bp_response_map_type map_response_to_dc_element[EPS_III_BP_FDIR_EXEC_STATUS] = {
            {(const uint8_t *)&pResponseData->u32Uptime_in_seconds,   sizeof(pResponseData->u32Uptime_in_seconds) },
            { (const uint8_t *)&pResponseData->sCommon,               sizeof(pResponseData->sCommon)              },
            { (const uint8_t *)&pResponseData->sHib_mode_status,      sizeof(pResponseData->sHib_mode_status)     },
            { (const uint8_t *)&pResponseData->sMeasurements,         sizeof(pResponseData->sMeasurements)        },
            { (const uint8_t *)&pResponseData->sDischarging_state,    sizeof(pResponseData->sDischarging_state)   },
            { (const uint8_t *)&pResponseData->sCharge_status,        sizeof(pResponseData->sCharge_status)       },
            { (const uint8_t *)&pResponseData->sBalancers_status,     sizeof(pResponseData->sBalancers_status)    },
            { (const uint8_t *)&pResponseData->sBattery_cells_status, sizeof(pResponseData->sBattery_cells_status)},
            { (const uint8_t *)&pResponseData->sHeaters_status,       sizeof(pResponseData->sHeaters_status)      }
        };

        telemetry_notif_process(pRespCtx, map_response_to_dc_element, EPS_III_BP_FDIR_EXEC_STATUS);
    }
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
static void eps_iii_bp_fdir_checks(const eps_dev_t *const device_info)
{
    DATA_CACHE_Eps3Inst0MeasurementsType_t bp_info;
    CONOPS_ThresholdValues_t               thresh_cfg;
    bool                                   is_cfg_read = conops_get_all_thresh_val(&thresh_cfg);

    CRIT_ASSERT(NULL != device_info);

    if (is_cfg_read && (DC_DATA_STATUS_OK == dc_get_raw_data(device_info->datacache_cmd_list[EPS_III_BP_MEASUREMENTS],
                                                             &bp_info,
                                                             sizeof(DATA_CACHE_Eps3Inst0MeasurementsType_t),
                                                             0, sizeof(DATA_CACHE_Eps3Inst0MeasurementsType_t))))
    {
        fdir_agent_id_t agent_id         = FDIR_AGENT_INVALID;
        bool            low_voltage      = false;
        bool            low_temperature  = false;
        bool            high_temperature = false;

        agent_id = FDIR_AGENT_EPS_III;

        if (bp_info.u16V_batt < thresh_cfg.i32V_batt_safe)
        {
            fdir_srv_log_if_clear(device_info->fdir_fault_ids[EPS_III_BP_FDIR_BATT_VOLTAGE_BELOW_SAFE], agent_id, "Battery voltage (%d mV) is below safe level (%d mV)", bp_info.u16V_batt, thresh_cfg.i32V_batt_safe);
            low_voltage = true;
        }

        if (bp_info.i32T_batt < thresh_cfg.i32T_batt_safe_lower)
        {
            fdir_srv_log_if_clear(device_info->fdir_fault_ids[EPS_III_BP_FDIR_BATT_TEMP_BELOW_SAFE], agent_id, "Battery temperature (%d mC) is below safe level (%d mC)", bp_info.i32T_batt, thresh_cfg.i32T_batt_safe_lower);
            low_temperature = true;
        }
        else if (bp_info.i32T_batt > thresh_cfg.i32T_batt_safe_upper)
        {
            fdir_srv_log_if_clear(device_info->fdir_fault_ids[EPS_III_BP_FDIR_BATT_TEMP_ABOVE_SAFE], agent_id, "Battery temperature (%d mC) is above safe level (%d mC)", bp_info.i32T_batt, thresh_cfg.i32T_batt_safe_upper);
            high_temperature = true;
        }
        else
        {
            // SonarQube warning suppression
        }

        fdir_srv_fault_set_state(device_info->fdir_fault_ids[EPS_III_BP_FDIR_BATT_VOLTAGE_BELOW_SAFE], agent_id, low_voltage, NULL);
        fdir_srv_fault_set_state(device_info->fdir_fault_ids[EPS_III_BP_FDIR_BATT_TEMP_BELOW_SAFE], agent_id, low_temperature, NULL);
        fdir_srv_fault_set_state(device_info->fdir_fault_ids[EPS_III_BP_FDIR_BATT_TEMP_ABOVE_SAFE], agent_id, high_temperature, NULL);
    }
}
