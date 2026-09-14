/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup eps_iii
 * @{
 *
 * @file     eps_iii.c
 * @brief    Driver for Endurosat Electric Power System III (EPS III)
 *
 * @}
 */

#include "eps_iii.h"
#include "eps_iii_config.h"
#include "eps_iii_pdm_a.h"

#include "eps_ctrl_cfg.h"

#include "assertions.h"
#include "cmsis_os.h"
#include "taskmon.h"

#include "fp/eps_iii_pdm_a/v2.0/eps_iii_pdm_a_client/FP_eps_iii_pdm_aProtocolClient.h"
#include "fp/eps_iii_pdm_a/v2.0/eps_iii_pdm_a_client/FP_eps_iii_pdm_aProtocolTypes.h"
#include "fp/eps_iii_batt_pack/v2.0/eps_iii_batt_pack_client/FP_eps_iii_batt_packProtocolClient.h"
#include "fp/eps_iii_batt_pack/v2.0/eps_iii_batt_pack_client/FP_eps_iii_batt_packProtocolTypes.h"
#include "fp/data_cache/v0.1/data_cache_server/FP_data_cacheProtocolTypes.h"

#include "if_eps_dev.h"
#include "if_eps_ctrl.h"
#include "if_tlm_dev.h"
#include "if_eps_base_dev.h"

#include "eps_iii_pdm_a.h"
#include "eps_iii_pdm_a_cfg.h"

#include "eps_iii_pdm_b.h"
#include "eps_iii_pdm_b_cfg.h"

#include "eps_iii_expander.h"
#include "eps_iii_expander_cfg.h"

#include "eps_iii_bp.h"
#include "eps_iii_bp_cfg.h"

#include "eps_iii_input_stage.h"
#include "eps_iii_input_stage_cfg.h"

#include "ESSA_Stack_Facade.h"

#include "taskmon_stat.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
/**
 * @brief Time to wait between checking if ESSA stack is initialized. If the ESSA stack is not initialized the component EPS III driver
 * component will not continue.
 *
 */
#define TIME_CHECK_ESSA_INIT_MS ((uint32_t)10)

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/
/**
 * @brief Implementation of @ref p_on_set_output_response_received_t from @ref if_eps_ctrl.h interface
 *
 *  Using this notification the component forward the response to the EPS Control service @ref eps_ctrl.c component
 */
static void eps_iii_on_set_output_response_received(bool is_successful);

/**
 * @brief Implementation of @ref p_on_get_output_response_received_t from @ref if_eps_ctrl.h interface
 *
 *  Using this notification the component forward the response to the EPS Control service @ref eps_ctrl.c component
 */
static void eps_iii_on_get_output_response_received(bool is_successful, bool status);

/*
 *
 ***************************************************************************************************
 * PRIVATE VARIABLES DECLARATION FOR EPS III SUBSYSTEM
 ***************************************************************************************************
 */
/**
 * Array with pointers to EPS III Battery Pack instances.
 */
eps_iii_bp_t bp_modules[EPS_III_BP_INST_CNT];

/**
 * Array with pointers to EPS III PDM A instances.
 */
eps_iii_pdm_a_t pdm_a_modules[EPS_III_PDM_A_INST_CNT];

/**
 * Array with pointers to EPS III PDM B instances.
 */
eps_iii_pdm_b_t pdm_b_modules[EPS_III_PDM_B_INST_CNT];

/**
 * Array with pointers to EPS III Expander instances.
 */
eps_iii_expander_t expander_modules[EPS_III_EXPANDER_INST_CNT];

/**
 * Array with pointers to EPS III Input Stage instances.
 */
eps_iii_input_stage_t input_stage_modules[EPS_III_INPUT_STAGE_INST_CNT];

/**
 * Array with pointers to instances of eps_dev_base type. These are all submodules of the EPS III subsystem.
 */
static eps_dev_base_t *const eps_dev_base[EPS_III_DEV_COUNT];

/**
 * Array with pointers to instances of Telemetry modules. These are all submodules of the EPS III subsystem which have
 * telemetry interface implementation @ref if_tlm_t.
 */
const if_tlm_t *const tlm_dev[TLM_DEV_CNT];

/**
 * Array with pointers to instances of Telemetry modules. These are all submodules of the EPS III subsystem which have
 * eps controller interface implementation @ref if_eps_ctrl_t.
 */
const if_eps_ctrl_t *const eps_ctrl_devices[EPS_III_CTRL_DEV_INST_CNT];
/*
***************************************************************************************************
* PRIVATE VARIABLES DEFINITION
***************************************************************************************************
*/
static eps_dev_base_t *const eps_dev_base[EPS_III_DEV_COUNT] = {
    EPS_III_BP_DEV_INSTANCES_CFG,
    EPS_III_PDM_A_DEV_INSTANCES_CFG,
    EPS_III_PDM_B_DEV_INSTANCES_CFG,
    EPS_III_EXPANDER_DEV_INSTANCES_CFG,
    EPS_III_INPUT_STAGE_DEV_INSTANCES_CFG
};

const if_tlm_t *const tlm_dev[TLM_DEV_CNT] = {
    EPS_III_BP_TLM_INST_CFG,
    EPS_III_PDM_A_TLM_INST_CFG,
    EPS_III_PDM_B_TLM_INST_CFG,
    EPS_III_EXPANDER_TLM_INST_CFG,
    EPS_III_INPUT_STAGE_TLM_INST_CFG
};

const if_eps_ctrl_t *const eps_ctrl_devices[EPS_III_CTRL_DEV_INST_CNT] = {
    EPS_III_PDM_A_CTRL_INSTANCES_CFG,
    EPS_III_PDM_B_CTRL_INSTANCES_CFG,
    EPS_III_EXPANDER_CTRL_INSTANCES_CFG,
};

eps_iii_bp_t bp_modules[EPS_III_BP_INST_CNT] = {
    EPS_III_BP_CFG
};

eps_iii_pdm_a_t pdm_a_modules[EPS_III_PDM_A_INST_CNT] = {
    EPS_III_PDM_A_CFG
};

eps_iii_pdm_b_t pdm_b_modules[EPS_III_PDM_B_INST_CNT] = {
    EPS_III_PDM_B_CFG
};

eps_iii_expander_t expander_modules[EPS_III_EXPANDER_INST_CNT] = {
    EPS_III_EXPANDER_CFG
};

eps_iii_input_stage_t input_stage_modules[EPS_III_INPUT_STAGE_INST_CNT] = {
    EPS_III_INPUT_STAGE_CFG
};

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/
/**
 *  Configuration interface for the system instancer
 */
if_sys_mod_t eps_iii_module_configuration = {
    .init   = eps_iii_init,
    .run    = eps_iii_run,
    .stop   = eps_iii_stop,
    .deinit = eps_iii_deinit,
};

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/

/**
 * eps iii thread handler
 */
static osThreadId_t eps_iii_task_handle = NULL;

/**
 * eps iii thread attributes
 */
static const osThreadAttr_t eps_iii_task_attributes = {
    .name       = "EPS_III_Task",
    .priority   = (osPriority_t)osPriorityNormal,
    .stack_size = 2048
};

/**
 * Internal mapping of all channels supported by EPS III specific configuration. This mapping vary based on the configuration,
 * because EPS III can have different type of PDMs and different count of PDMs.
 */
static const eps_iii_ch_map_t ch_map[eps_iii_CTRL_MAX] = {
    EPS_III_CHANNEL_MAPPING_CFG
};

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
****************************************************************************************************/
/*
 * SYS INSTANCER DECLARATIONS
 ***************************/

/** @brief Memory initialisation for the EPS III module
 */
static void eps_iii_init_memory(void);

/** @brief OS initialisation for the EPS III module
 */
static void eps_iii_init_os(void);

/**
 * @brief This is EPS III function executed in a separate thread. The EPS III driver main function.
 *
 * @param args Argument needed for the thread interface @ref osThreadFunc_t In this module the argument is not used.
 */
static void eps_iii_task(void *args);

/**
 * @brief Function used to gather all the data from all BPs in the EPS III subsystem and publish an overall info about the EPS III BP state
 *
 */
static void calculate_average_values_for_all_bps(void);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
/*
 * SYS INSTANCER FUNCTIONS DEFINITIONS
 *************************/
mod_op_status_id_t eps_iii_init(sys_init_level_id_t level)
{
    // in case there is an issue on this line it's clear that there is a problem in configuration of the EPSIII
    static_assert(EPS_DEV_CNT == EPS_III_DEV_COUNT);

    mod_op_status_id_t ret = STATUS_NOT_SUPPORTED;

    // Eventually, to split the initialisation into the different levels
    switch (level)
    {
        case INIT_MEM:
            eps_iii_init_memory();
            ret = STATUS_OK;
            break;
        case INIT_HW:
            // currently there is no need of HW initialization
            ret = STATUS_OK;
            break;
        case INIT_OS:
            eps_iii_init_os();
            ret = STATUS_OK;
            break;
        default:
            ret = STATUS_NOT_SUPPORTED;
            break;
    }

    return ret;
}

mod_op_status_id_t eps_iii_run(void)
{
    // To be used by the system instancer
    return STATUS_NOT_SUPPORTED;
}

mod_op_status_id_t eps_iii_stop(void)
{
    // To be used by the system instancer
    return STATUS_NOT_SUPPORTED;
}

mod_op_status_id_t eps_iii_deinit(sys_init_level_id_t level)
{
    if (INIT_OS == level)
    {
        task_mon_set_task_policy(TASK_ID_EPS_III, TASK_MON_POLICY_DONT_CARE);
    }
    return STATUS_OK;
}

/*
 * EPS CONTROL
 *************/
bool eps_iii_set_channel_output(eps_iii_ctrl_ch_t channel, bool state)
{
    return ch_map[channel].eps_ctrl_ctx->p_set_output(ch_map[channel].eps_ctrl_ctx, ch_map[channel].eps_ctrl_dev_ch_id, state);
}

bool eps_iii_get_channel_output(eps_iii_ctrl_ch_t channel)
{
    return ch_map[channel].eps_ctrl_ctx->p_get_output(ch_map[channel].eps_ctrl_ctx, ch_map[channel].eps_ctrl_dev_ch_id);
}

void telemetry_notif_process(const RespContext_t *const pRespCtx, const bp_response_map_type *const p_map_response_to_dc_element, uint8_t telemetry_dc_elements_cnt)
{
    BREAK_ASSERT((NULL != pRespCtx) && (NULL != p_map_response_to_dc_element));
    if ((NULL != pRespCtx) && (NULL != p_map_response_to_dc_element))
    {
        const eps_dev_base_t *p_eps_dev = eps_iii_get_eps_dev_by_addr(pRespCtx->nAddr);

        BREAK_ASSERT(NULL != p_eps_dev);

        if ((NULL != p_eps_dev) && (true == p_eps_dev->eps_dev_info.p_is_seq_expected(&p_eps_dev->eps_dev_info, pRespCtx->seqId)))
        {
            for (uint8_t dc_id = 0; dc_id < telemetry_dc_elements_cnt; dc_id++)
            {
                uint32_t datacache_element_size = dc_get_data_size(p_eps_dev->eps_dev_info.datacache_cmd_list[dc_id]);
                uint8_t  data[datacache_element_size];

                if (datacache_element_size == p_map_response_to_dc_element[dc_id].size)
                {
                    memcpy(&data[0], p_map_response_to_dc_element[dc_id].address_of_dc_value_in_response, datacache_element_size);
                    dc_set_raw_data(DC_DATA_INPUT_INTERNAL, p_eps_dev->eps_dev_info.datacache_cmd_list[dc_id], &data, datacache_element_size);
                }
                else
                {
                    BREAK_ASSERT(false);
                }
            }
        }
    }
}

const eps_dev_base_t *eps_iii_get_eps_dev_by_addr(uint8_t addr)
{
    const eps_dev_base_t *res = NULL;

    for (uint8_t i = 0; i < EPS_III_DEV_COUNT; i++)
    {
        if (eps_dev_base[i]->eps_dev_info.esps_dev_info.mac_addr == addr)
        {
            res = eps_dev_base[i];
            break;
        }
    }

    return res;
}

const if_eps_ctrl_t *eps_iii_get_eps_ctrl_by_addr(uint8_t addr)
{
    const if_eps_ctrl_t *res = NULL;

    for (uint8_t i = 0; i < EPS_III_CTRL_DEV_INST_CNT; i++)
    {
        if (eps_ctrl_devices[i]->p_device_info->esps_dev_info.mac_addr == addr)
        {
            res = eps_ctrl_devices[i];
            break;
        }
    }

    return res;
}

/*
********************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
********************************************************************************************
*/

static void eps_iii_init_memory(void)
{
    uint8_t eps3_addresses[EPS_III_DEV_COUNT];

    eps_iii_cfg_get_eps_iii_mac_addresses(eps3_addresses, EPS_III_DEV_COUNT);

    for (uint8_t eps_dev_id = 0; eps_dev_id < EPS_III_DEV_COUNT; eps_dev_id++)
    {
        eps_dev_base[eps_dev_id]->p_init(eps_dev_base[eps_dev_id], eps3_addresses[eps_dev_id]);
    }
}

static void eps_iii_init_os(void)
{
    // Init telemetry task
    eps_iii_task_handle = osThreadNew(&eps_iii_task, NULL, &eps_iii_task_attributes);
    CRIT_ASSERT(eps_iii_task_handle);
    task_mon_register_for_stats(TASK_ID_EPS_III, eps_iii_task_handle);

    // Notify task_mon
    task_mon_set_task_policy(TASK_ID_EPS_III, TASK_MON_POLICY_MONITOR);
    task_mon_task_initialized(TASK_ID_EPS_III);
}

static void eps_iii_task(void *args)
{
    (void)args;

    while (SAFE_TRUE != ESSA_Stack_Facade_Is_Init())
    {
        osDelay(TIME_CHECK_ESSA_INIT_MS);
    }

    for (;;)
    {
        for (uint8_t tlm_id = 0; tlm_id < EPS_III_TLM_DEV_COUNT; tlm_id++)
        {
            tlm_dev[tlm_id]->p_get_telemetry(tlm_dev[tlm_id]);
            task_mon_i_am_alive(TASK_ID_EPS_III);
        }

        for (uint8_t dev_id = 0; dev_id < EPS_III_DEV_COUNT; dev_id++)
        {
            eps_dev_base[dev_id]->eps_dev_info.p_process_fdir_faults(&(eps_dev_base[dev_id]->eps_dev_info));
            task_mon_i_am_alive(TASK_ID_EPS_III);
        }

        calculate_average_values_for_all_bps();

        task_mon_i_am_alive(TASK_ID_EPS_III);
        task_mon_low_stack_check(TASK_ID_EPS_III);
    }
}

static void eps_iii_on_set_output_response_received(bool is_successful)
{
    eps_ctrl_cfg_set_ch_notif_eps_iii(is_successful);
}

static void eps_iii_on_get_output_response_received(bool is_successful, bool status)
{
    (void)is_successful;
    eps_ctrl_cfg_get_ch_notif_eps_iii(status);
}

static void calculate_average_values_for_all_bps(void)
{
    DATA_CACHE_EpsOverallBatteryInfoType_t overall_bp_info        = { 0 };
    uint32_t                               average_voltage        = 0;
    uint8_t                                normal_state_bps_count = 0;

    enum
    {
        STATUS_OFF,    // Current status is inactive
        STATUS_ON,     // Current status is active
        STATUS_UNKNOWN // Current status is unknown
    };

    for (uint8_t dev_id = EPS_III_DEV_BP_INST0; dev_id < (EPS_III_DEV_BP_INST0 + NVM_EPS_EPSIIIBPIDTYPE_MAX_CNT); dev_id++)
    {
        DATA_CACHE_Eps3Inst0MeasurementsType_t  bp_info;
        DATA_CACHE_Eps3Inst0HIBModeStatusType_t bp_status;
        dc_data_status_t                        res_bp_info = dc_get_raw_data(eps_dev_base[dev_id]->eps_dev_info.datacache_cmd_list[EPS_III_BP_MEASUREMENTS],
                                                                              &bp_info,
                                                                              sizeof(DATA_CACHE_Eps3Inst0MeasurementsType_t),
                                                                              0U,
                                                                              sizeof(DATA_CACHE_Eps3Inst0MeasurementsType_t));

        dc_data_status_t res_bp_status = dc_get_raw_data(eps_dev_base[dev_id]->eps_dev_info.datacache_cmd_list[EPS_III_PDM_B_HIB_MODE],
                                                         &bp_status,
                                                         sizeof(DATA_CACHE_Eps3Inst0HIBModeStatusType_t),
                                                         0U,
                                                         sizeof(DATA_CACHE_Eps3Inst0HIBModeStatusType_t));

        if ((DC_DATA_STATUS_OK == res_bp_info) && (DC_DATA_STATUS_OK == res_bp_status) && (STATUS_ON != bp_status.u8Battery_dead))
        {
            normal_state_bps_count++;
            average_voltage += bp_info.u16V_batt;
        }
    }

    if (0 < normal_state_bps_count)
    {
        overall_bp_info.u16Voltage = (uint16_t)(average_voltage / normal_state_bps_count);
    }

    // currently EPS_III battery packs do not support capacity
    overall_bp_info.u32Capacity = 0;

    dc_set_epsoverallbatteryinfo_data(&overall_bp_info);
}
