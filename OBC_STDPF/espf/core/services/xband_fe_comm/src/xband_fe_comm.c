/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup xband_fe_comm
 * @{
 *
 * @file xband_fe_comm.c
 * @brief Implementation of the X-Band-Front-End-related services such as telemetry collection and
 * health monitoring.
 *
 * @}
 *
 */

#include "es_cdef.h"
#include "xband_fe_proto.h"
#include "if_payload_control.h"
#include "payload_shared_types.h"
#include "trace.h"
#include "xband_fe_comm.h"
#include "eps_ctrl.h"
#include "eps_ctrl_cfg.h"
#include "xband_fe_proto.h"
#include "cmsis_os2.h"
#include "taskmon.h"
#include "taskmon_stat.h"
#include "datacache.h"
#include "fdir_srv.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
/** @brief Number of XBand FE instances supported by this module */
#define XBAND_FE_INST_CNT (1U)

/** @brief Number of bytes to allocate for the XBand FE main task */
#define XBAND_FE_TASK_STACK_SIZE (2000U)

/** @brief XBand FE OS task period in milliseconds */
#define XBAND_FE_TASK_PERIOD (250U)

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

typedef struct
{
    pl_state_t          xband_fe_state;          /**< payload operating state of the XBand FE instance */
    p_pl_event_notify_t p_xband_fe_state_notify; /**< XBand FE state notification callback */
    uint8_t             pwr_chn_id;              /**< power channel ID used to control the XBand FE instance */
    comm_gw_comm_res_t  last_comm_res;           /**< last reported communication status with the module instance */
} xband_fe_inst_t;

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/** @brief Keeps information about the configured XBand FE instances */
static xband_fe_inst_t xband_instance[XBAND_FE_INST_CNT] = {
    {.xband_fe_state          = PL_STATE_NOT_INIT,
     .p_xband_fe_state_notify = NULL,
     .pwr_chn_id              = EPSCTRL_POWER_OUT_X_BAND_FE_EN,
     .last_comm_res           = COMM_GW_RES_MAX}
};

/**< Attributes of XBand FE main OS task r */
static const osThreadAttr_t task_attr = {
    .name       = "xband_fe_task",
    .attr_bits  = osThreadDetached,
    .cb_mem     = NULL,
    .cb_size    = 0U,
    .stack_mem  = NULL,
    .stack_size = XBAND_FE_TASK_STACK_SIZE,
    .priority   = osPriorityNormal,
    .tz_module  = 0,
    .reserved   = 0
};

static osThreadId_t h_os_task; /**< OS task handle for all XBand FE instances */

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
/** @brief See pl_control_if_t description for details. This is a standard operation for all payloads. */
static pl_op_status_t xband_fe_pl_ctrl_init(const pl_instance_id_t instance_id, const pl_config_t *const p_init_cfg, const p_pl_event_notify_t p_event_notify_cb);
/** @brief See pl_control_if_t description for details. This is a standard operation for all payloads. */
static pl_op_status_t xband_fe_pl_ctrl_deinit(const pl_instance_id_t instance_id);
/** @brief See pl_control_if_t description for details. This is a standard operation for all payloads. */
static pl_op_status_t xband_fe_pl_ctrl_start(const pl_instance_id_t instance_id, const pl_config_t *const p_start_cfg);
/** @brief See pl_control_if_t description for details. This is a standard operation for all payloads. */
static pl_op_status_t xband_fe_pl_ctrl_stop(const pl_instance_id_t instance_id, const pl_op_stop_mode_t stop_mode);
/** @brief See pl_control_if_t description for details. This is a standard operation for all payloads. */
static pl_state_t xband_fe_pl_ctrl_get_state(const pl_instance_id_t instance_id);
/** @brief See pl_control_if_t description for details. This is a standard operation for all payloads. */
static uint32_t xband_fe_pl_ctrl_get_last_error(const pl_instance_id_t instance_id);
/** @brief See pl_control_if_t description for details. This is a standard operation for all payloads. */
static void update_state_and_notify(const pl_instance_id_t instance_id, const pl_state_t new_state);
/** @brief Validates the instance of the XBand FE
 *  @param[in] instance_id XBand FE payload instance ID
 *
 *  @return true - if instance is valid and can be used, false - otherwise
 * */
static bool is_valid_xband_fe_instance(const pl_instance_id_t instance_id);

/** @brief Query the XBand FE instance for telemtry and store it to datacache.
 *
 *  @param[in] instance_id ID of the XBand FE module instance
 */
static void xband_fe_capture_telemetry(pl_instance_id_t instance_id);

/** @brief XBand FE OS task function
 *  @param[in] p_task_arg pointer to task-specific arguments (not used currently)
 * */
static void xband_fe_task(void *p_task_arg);
/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/
const pl_control_if_t xband_fe_pl_ctrl_if = {
    .init           = xband_fe_pl_ctrl_init,
    .deinit         = xband_fe_pl_ctrl_deinit,
    .start          = xband_fe_pl_ctrl_start,
    .stop           = xband_fe_pl_ctrl_stop,
    .get_state      = xband_fe_pl_ctrl_get_state,
    .get_last_error = xband_fe_pl_ctrl_get_last_error,
};

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

static inline bool is_valid_xband_fe_instance(const pl_instance_id_t instance_id)
{
    return (instance_id < XBAND_FE_INST_CNT);
}

static void update_state_and_notify(const pl_instance_id_t instance_id, const pl_state_t new_state)
{
    CRIT_ASSERT(true == is_valid_xband_fe_instance(instance_id));

    xband_instance[instance_id].xband_fe_state = new_state;

    if (xband_instance[instance_id].p_xband_fe_state_notify != NULL)
    {
        (*xband_instance[instance_id].p_xband_fe_state_notify)(instance_id, xband_instance[instance_id].xband_fe_state);
    }
}

static pl_op_status_t xband_fe_pl_ctrl_init(const pl_instance_id_t instance_id, const pl_config_t *const p_init_cfg, const p_pl_event_notify_t p_event_notify_cb)
{
    pl_op_status_t res = PL_OP_STATUS_REJECT;
    (void)p_init_cfg;

    if (true == is_valid_xband_fe_instance(instance_id))
    {
        if (NULL == h_os_task)
        {
            h_os_task = osThreadNew(xband_fe_task,
                                    NULL,
                                    &task_attr);
        }

        if (NULL == h_os_task)
        {
            ES_TRACE_ERROR("XBand FE main task could not be started due to error");
        }
        else
        {
            ES_TRACE_DEBUG("XBand FE main task initialized");

            task_mon_task_initialized(TASK_ID_XBAND_FE);
            task_mon_register_for_stats(TASK_ID_XBAND_FE, h_os_task);
        }

        xband_instance[instance_id].p_xband_fe_state_notify = p_event_notify_cb;
        update_state_and_notify(instance_id, PL_STATE_STOPPED);
        res = PL_OP_STATUS_OK;
    }
    else
    {
        BREAK_ASSERT(false);
    }

    return res;
}

static pl_op_status_t xband_fe_pl_ctrl_deinit(const pl_instance_id_t instance_id)
{
    pl_op_status_t res = PL_OP_STATUS_REJECT;

    if (true == is_valid_xband_fe_instance(instance_id))
    {
        update_state_and_notify(instance_id, PL_STATE_NOT_INIT);

        xband_instance[instance_id].p_xband_fe_state_notify = NULL;

        res = PL_OP_STATUS_OK;
    }
    else
    {
        BREAK_ASSERT(false);
    }

    return res;
}

static pl_op_status_t xband_fe_pl_ctrl_start(const pl_instance_id_t instance_id, const pl_config_t *const p_start_cfg)
{
    pl_op_status_t res = PL_OP_STATUS_REJECT;

    (void)p_start_cfg; // payload configuration for XBand FE is not used

    if (true == is_valid_xband_fe_instance(instance_id))
    {
        eps_ctrl_result_t ch_set_res = eps_ctrl_set_channel_output(xband_instance[instance_id].pwr_chn_id, true);

        if (EPS_CTRL_DONE == ch_set_res)
        {
            update_state_and_notify(instance_id, PL_STATE_STARTED);
            res = PL_OP_STATUS_OK;
        }
        else
        {
            res = PL_OP_STATUS_FAILURE;
        }
    }
    else
    {
        BREAK_ASSERT(false);
    }

    return res;
}

static pl_op_status_t xband_fe_pl_ctrl_stop(const pl_instance_id_t instance_id, const pl_op_stop_mode_t stop_mode)
{
    pl_op_status_t res = PL_OP_STATUS_REJECT;

    if (true == is_valid_xband_fe_instance(instance_id))
    {
        // stop the power regardless of the mode
        (void)stop_mode;

        eps_ctrl_result_t ch_set_res = eps_ctrl_set_channel_output(xband_instance[instance_id].pwr_chn_id, false);

        if (EPS_CTRL_DONE == ch_set_res)
        {
            update_state_and_notify(instance_id, PL_STATE_STOPPED);
            res = PL_OP_STATUS_OK;
        }
        else
        {
            res = PL_OP_STATUS_FAILURE;
        }
    }
    else
    {
        BREAK_ASSERT(false);
    }

    return res;
}

static pl_state_t xband_fe_pl_ctrl_get_state(const pl_instance_id_t instance_id)
{
    pl_state_t res = PL_STATE_NOT_INIT;

    if (true == is_valid_xband_fe_instance(instance_id))
    {
        res = xband_instance[instance_id].xband_fe_state;
    }
    else
    {
        BREAK_ASSERT(false);
    }

    return res;
}

static uint32_t xband_fe_pl_ctrl_get_last_error(const pl_instance_id_t instance_id)
{
    uint32_t res = COMM_GW_RES_ERR;

    if (true == is_valid_xband_fe_instance(instance_id))
    {
        res = xband_instance[instance_id].last_comm_res;
    }
    else
    {
        BREAK_ASSERT(false);
    }

    return res;
}

static void xband_fe_capture_telemetry(pl_instance_id_t instance_id)
{
    CRIT_ASSERT(true == is_valid_xband_fe_instance(instance_id));

    XBAND_FE_ModStatusReportParamsWrapper_t tlm_data;
    bool                                    comm_failed = true;

    // Note: The following call relies on NVM configuration for the instance of the XBand to which to communicate. If multi-instance
    // XBand FE communication is required in the future, the proto interfaces must be extended to support more than one instance.
    xband_instance[instance_id].last_comm_res = xband_fe_proto_get_status_report(NULL, &tlm_data);

    if (COMM_GW_RES_OK == xband_instance[instance_id].last_comm_res)
    {
        DATA_CACHE_XBandFeTelemetry_t xband_dc_tlm;

        (void)memset(&xband_dc_tlm, 0U, sizeof(xband_dc_tlm));

        xband_dc_tlm.i16Cpu_temperature   = tlm_data.sStatus_report.i16Cpu_temperature;
        xband_dc_tlm.i16Pa_pwr_det        = tlm_data.sStatus_report.i16Pa_pwr_det;
        xband_dc_tlm.i16Pa_temperature    = tlm_data.sStatus_report.i16Pa_temperature;
        xband_dc_tlm.i16Pa_vgg            = tlm_data.sStatus_report.i16Pa_vgg;
        xband_dc_tlm.u16Adc_vref_internal = tlm_data.sStatus_report.u16Adc_vref_internal;
        xband_dc_tlm.u16Cpu_vdd           = tlm_data.sStatus_report.u16Cpu_vdd;
        xband_dc_tlm.u16Pa_idd            = tlm_data.sStatus_report.u16Pa_idd;
        xband_dc_tlm.u16Pa_vdd            = tlm_data.sStatus_report.u16Pa_vdd;
        xband_dc_tlm.u16Powsup_3v3_pll    = tlm_data.sStatus_report.u16Powsup_3v3_pll;
        xband_dc_tlm.u16Powsup_5v_att     = tlm_data.sStatus_report.u16Powsup_5v_att;
        xband_dc_tlm.u16Powsup_5v_if_amp  = tlm_data.sStatus_report.u16Powsup_5v_if_amp;
        xband_dc_tlm.u16Powsup_5v_rf_drv  = tlm_data.sStatus_report.u16Powsup_5v_rf_drv;
        xband_dc_tlm.u16Powsup_5v_vco_drv = tlm_data.sStatus_report.u16Powsup_5v_vco_drv;
        xband_dc_tlm.u8Status_flags       = tlm_data.sStatus_report.u8Status_flags;
        xband_dc_tlm.u8System_state       = tlm_data.sStatus_report.eSystem_state;

        dc_set_xband_fe_data(&xband_dc_tlm);

        comm_failed = false;
    }

    (void)fdir_srv_fault_set_state(FDIR_FAULT_X_BAND_FE_CMD_EXEC_FAILURE, FDIR_AGENT_XBAND_FE, comm_failed, NULL);
}

static void xband_fe_task(void *p_task_arg)
{
    // currently unused
    (void)p_task_arg;

    if (XBAND_FE_INST_CNT > 1)
    {
        ES_TRACE_WARN("XBand FE currently supports only one module instance to save resources!");
    }

    for (;;)
    {
        for (uint8_t inst_id = 0; inst_id < XBAND_FE_INST_CNT; inst_id++)
        {
            if (PL_STATE_STARTED == xband_instance[inst_id].xband_fe_state)
            {
                xband_fe_capture_telemetry(inst_id);
            }
        }

        osDelay(XBAND_FE_TASK_PERIOD);

        task_mon_i_am_alive(TASK_ID_XBAND_FE);
        task_mon_low_stack_check(TASK_ID_XBAND_FE);
    }
}
