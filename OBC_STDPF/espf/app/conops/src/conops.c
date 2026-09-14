/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup app_conops
 * @{
 *
 * @file conops.c
 * @brief Concept of Operations main implementation
 *
 * @}
 *
 */

#include "conops.h"
#include "conops_internal.h"

#include "aocs_cntrl.h"

#include "if_sys_conf.h"
#include "taskmon.h"
#include "taskmon_stat.h"
#include "assertions.h"
#include "es_exeh.h"
#include "nvm/inc/nvm.h"
#include "timer.h"
#include "string.h"
/*
*********************************************************************************************
* INTERNAL DEFINES
*********************************************************************************************
*/

/** @brief Module ID used for this file to report error events in EXEH */
#define EXEH_CURRENT_MODULE_ID (eEXEHModuleID_CON_OPS)

/** @brief Value of the default threshold */
#define CONOPS_DEFAULT_MULT (1000U)

/** @brief Number of checks required to verify that stable Y-Thomson spin is achieved */
#define CONOPS_ADCS_T_YHOMSON_STABLE_VERIFIED ((uint8_t)0x03)

/** @brief Thread flag used to signal the ConOps main thread to resume */
#define CONOPS_TRIGGER_TASK_FLAG (0x01)

/*
*********************************************************************************************
* INTERNAL TYPES DEFINITION
*********************************************************************************************
*/

/** @brief Specific exceptions raised by ConOps */
typedef enum
{
    eConOpsException_Runtime_Error, /**< Generic runtime error */
} conops_exception_t;

/** @brief XYZ axis values in the data arrays */
typedef enum
{
    x = 0,
    y = 1,
    z = 2
} axis_idx_t;

/** @brief Parameters of a 3-axis vector */
typedef struct
{
    int32_t x;
    int32_t y;
    int32_t z;

} conops_3axis_vec_t;

/*
*********************************************************************************************
* EXTERNAL VARIABLES DEFINITION
*********************************************************************************************
*/

/*
*********************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
*********************************************************************************************
*/

INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/** @brief Attributes of the ConOps SM event mutex */
static const osMutexAttr_t conops_ev_mutex_attr = {
    "ConOpsEventTriggerMutex",
    osMutexRecursive | osMutexPrioInherit,
    NULL,
    0U
};

/** @brief Attributes of the main ConOps task */
static const osThreadAttr_t conops_p_ev_task_attributes = {
    .name       = "conops_task",
    .attr_bits  = 0,
    .cb_mem     = NULL,
    .cb_size    = 0,
    .stack_mem  = NULL,
    .stack_size = CONOPS_PER_EV_TASK_STACK_SIZE,
    .priority   = (osPriority_t)osPriorityNormal,
    .tz_module  = 0,
    .reserved   = 0
};

/** @brief Handle for the main ConOps task */
static osThreadId_t h_conops_p_ev_task;

/** @brief Mutex guarding ConOps SM event triggers */
static osMutexId_t h_conops_ev_mutex;

/** @brief Runtime copy of the conops NVM configuration
 *
 *  @note This data is refreshed at each iteration of the main conops task and is used for
 *        faster access to data during execution of the iteration.
 */
static conops_config_t conops_cfg;

/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
*********************************************************************************************
*/

/**
 * @brief Initialises the ConOps periodic event task.
 */
static void conops_p_ev_init(void);

/**
 * @brief Check if we are in a stable Y-Thomson mode
 *
 * @param[in] p_ang_rate_vec Angular rate in milli-radians per second
 *
 * @retval true  Stable Y-Thomson spin verified.
 * @retval false Stable Y-Thomson spin cannot be verified.
 *
 */
static bool conops_chk_stable_y_thomson(const conops_3axis_vec_t *const p_ang_rate_vec);

/**
 * @brief Main task function of ConOps. Refreshes the runtime copies of the relevant NVM entries.
 *        Triggers the periodic event for the ConOps StateMachine.
 *
 * @param[in] arg Unused
 */
static void conops_task(void *arg);

/*
*********************************************************************************************
* EXTERNAL (NON-STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/

bool conops_init(void)
{
    bool ret = false;

    h_conops_ev_mutex = osMutexNew(&conops_ev_mutex_attr);
    conops_p_ev_init();

    if (NULL != h_conops_ev_mutex)
    {
        Nvm_GetBlockById(NVM_APP_BLOCK_CONOPS_CONFIG, &conops_cfg);

        ret = true;
    }

    return ret;
}

bool conops_trigger_hsm(const uint32_t event_id, const void *const p_event_data)
{
    conops_event_t trigger_event;

    (void)osMutexAcquire(h_conops_ev_mutex, osWaitForever);

    trigger_event.base_event.id = event_id;
    trigger_event.p_event_data  = p_event_data;

    bool ret = HSM_TriggerEvent_raw(conops_sm_instance, &trigger_event.base_event);

    (void)osMutexRelease(h_conops_ev_mutex);

    return ret;
}

void conops_get_hsm_active_state(uint8_t *const p_active_state)
{
    if (NULL != p_active_state)
    {
        // There is no mutex here so as not to block operation of components requesting
        // the active state while the state machine is performing a lengthy transition
        *p_active_state = HSM_GetActiveState(conops_sm_instance)->state_id;
    }
    else
    {
        BREAK_ASSERT(false);
    }
}

bool conops_set_thresh_val(const int32_t thresh_val, const CONOPS_ThresholdValueTypes_t thresh_type)
{
    // Return true unless an error is detected
    bool ret = true;

    switch (thresh_type)
    {
        case CONOPS_THRESHOLDVALUETYPES_VBATT_SAFE:
            conops_cfg.thresh.i32V_batt_safe = thresh_val;
            break;
        case CONOPS_THRESHOLDVALUETYPES_TBATT_SAFE_LOWER:
            conops_cfg.thresh.i32T_batt_safe_lower = thresh_val;
            break;
        case CONOPS_THRESHOLDVALUETYPES_TBATT_SAFE_UPPER:
            conops_cfg.thresh.i32T_batt_safe_upper = thresh_val;
            break;
        case CONOPS_THRESHOLDVALUETYPES_ANGVEL_MAX:
            conops_cfg.thresh.i32Ang_vel_max = thresh_val;
            break;
        case CONOPS_THRESHOLDVALUETYPES_ANGVEL_MIN:
            conops_cfg.thresh.i32Ang_vel_low = thresh_val;
            break;
        case CONOPS_THRESHOLDVALUETYPES_ANGVEL_Y_THOMSON_HIGH:
            conops_cfg.thresh.i32Ang_vel_y_thom_high = thresh_val;
            break;
        case CONOPS_THRESHOLDVALUETYPES_ANGVEL_Y_THOMSON_LOW:
            conops_cfg.thresh.i32Ang_vel_y_thom_low = thresh_val;
            break;
        default:
            EXEH_HANDLE(eEXEHSeverity_Error, (int32_t)eConOpsException_Runtime_Error);

            ret = false;
            break;
    }

    if (false != ret)
    {
        Nvm_SetBlockById(NVM_APP_BLOCK_CONOPS_CONFIG, &conops_cfg, NVMSETBLOCK_STORE_IMMEDIATELY);
        Nvm_GetBlockById(NVM_APP_BLOCK_CONOPS_CONFIG, &conops_cfg);
    }

    return ret;
}

bool conops_get_thresh_val(int32_t *const p_thresh_val, const CONOPS_ThresholdValueTypes_t thresh_type)
{
    if (NULL == p_thresh_val)
    {
        BREAK_ASSERT(false);
        return false;
    }

    // Return true unless an error is detected
    bool ret = true;

    switch (thresh_type)
    {
        case CONOPS_THRESHOLDVALUETYPES_VBATT_SAFE:
            *p_thresh_val = conops_cfg.thresh.i32V_batt_safe;
            break;
        case CONOPS_THRESHOLDVALUETYPES_TBATT_SAFE_LOWER:
            *p_thresh_val = conops_cfg.thresh.i32T_batt_safe_lower;
            break;
        case CONOPS_THRESHOLDVALUETYPES_TBATT_SAFE_UPPER:
            *p_thresh_val = conops_cfg.thresh.i32T_batt_safe_upper;
            break;
        case CONOPS_THRESHOLDVALUETYPES_ANGVEL_MAX:
            *p_thresh_val = conops_cfg.thresh.i32Ang_vel_max;
            break;
        case CONOPS_THRESHOLDVALUETYPES_ANGVEL_MIN:
            *p_thresh_val = conops_cfg.thresh.i32Ang_vel_low;
            break;
        case CONOPS_THRESHOLDVALUETYPES_ANGVEL_Y_THOMSON_HIGH:
            *p_thresh_val = conops_cfg.thresh.i32Ang_vel_y_thom_high;
            break;
        case CONOPS_THRESHOLDVALUETYPES_ANGVEL_Y_THOMSON_LOW:
            *p_thresh_val = conops_cfg.thresh.i32Ang_vel_y_thom_low;
            break;
        case CONOPS_THRESHOLDVALUETYPES_DEFAULT:
            *p_thresh_val = (int32_t)CONOPS_DEFAULT_MULT;
            break;
        default:
            EXEH_HANDLE(eEXEHSeverity_Error, (int32_t)eConOpsException_Runtime_Error);
            ret = false;
            break;
    }

    return ret;
}

bool conops_set_all_thresh_val(const CONOPS_ThresholdValues_t *const p_thresh_config)
{
    if (NULL == p_thresh_config)
    {
        BREAK_ASSERT(false);
        return false;
    }

    // Update the runtime values structure
    memcpy(&conops_cfg, p_thresh_config, sizeof(*p_thresh_config));

    // Update the nvm
    Nvm_SetBlockById(NVM_APP_BLOCK_CONOPS_CONFIG, &conops_cfg, NVMSETBLOCK_STORE_IMMEDIATELY);
    Nvm_GetBlockById(NVM_APP_BLOCK_CONOPS_CONFIG, &conops_cfg);

    return true;
}

bool conops_get_all_thresh_val(CONOPS_ThresholdValues_t *const p_thresh_vals)
{
    if (NULL == p_thresh_vals)
    {
        BREAK_ASSERT(false);
        return false;
    }

    // Copy only the size of the data, excluding the CRC
    memcpy(p_thresh_vals, &conops_cfg.thresh, sizeof(CONOPS_ThresholdValues_t));

    return true;
}

aocs_cntrl_sys_state_types_t conops_get_default_control(const CONOPS_ModesWithDefCtrl_t mode_id,
                                                        CONOPS_AocsRefParams_t *const   p_params)
{
    aocs_cntrl_sys_state_types_t ret = AOCS_CNTRL_SYS_NUMBER;

    if ((NULL != p_params) && (mode_id < CONOPS_MODESWITHDEFCTRL_MAX_CNT))
    {
        memcpy(p_params, &conops_cfg.def_control[mode_id].sParams, sizeof(*p_params));
        ret = conops_cfg.def_control[mode_id].eMode;
    }
    else
    {
        BREAK_ASSERT(false);
    }

    return ret;
}

bool conops_is_omega_above_thresh(const aocs_cntrl_sys_state_types_t aocs_state)
{
    bool ret;

    int32_t                     omega_thresh;
    DATA_CACHE_AOCS_CNTRL_TLM_t aocs_data;

    ret = false;

    if (aocs_state > AOCS_CNTRL_SYS_STATE_VERY_FAST_DETUMBLING)
    {
        return false;
    }

    if (true != conops_get_thresh_val(&omega_thresh, CONOPS_THRESHOLDVALUETYPES_ANGVEL_MAX))
    {
        return false;
    }

    if (DC_DATA_STATUS_OK == dc_get_aocs_cntrl_tlm_data(&aocs_data))
    {
        if ((AOCS_CNTRL_SYS_STATE_Y_THOMSON == aocs_state) || (AOCS_CNTRL_SYS_STATE_Y_THOMSON_MEMS_RATE == aocs_state))
        {
            conops_3axis_vec_t and_rate_vec_tmp;

            and_rate_vec_tmp.x = aocs_data.ai32EstAngRateVec[0];
            and_rate_vec_tmp.y = aocs_data.ai32EstAngRateVec[1];
            and_rate_vec_tmp.z = aocs_data.ai32EstAngRateVec[2];

            if (false == conops_chk_stable_y_thomson(&and_rate_vec_tmp))
            {
                ret = true;
            }
        }
        else if (aocs_data.i32EstAngRateNorm > omega_thresh)
        {
            ret = true;
        }
        else
        {
            ret = false;
        }
    }

    ES_TRACE_DEBUG("%s: conops_is_omega_above_thresh: %d\r", CONOPS_SM_TEST_COND, ret);

    return ret;
}

bool conops_is_detumb_completed(void)
{
    bool ret = false;

    DATA_CACHE_AOCS_CNTRL_TLM_t aocs_data;

    if (DC_DATA_STATUS_OK != dc_get_aocs_cntrl_tlm_data(&aocs_data))
    {
        return ret;
    }

    aocs_cntrl_sys_state_types_t     aocs_state;
    aocs_cntrl_sys_state_req_state_t aocs_state_req_state;

    if (conops_get_aocs_sys_state(&aocs_state, &aocs_state_req_state) &&
        (AOCS_CNTRL_SYS_STATE_STATE_REQ_COMPLETED == aocs_state_req_state))
    {
        if (AOCS_CNTRL_SYS_STATE_Y_THOMSON == aocs_state)
        {
            conops_3axis_vec_t sAngRateVecTmp;

            sAngRateVecTmp.x = aocs_data.ai32EstAngRateVec[0];
            sAngRateVecTmp.y = aocs_data.ai32EstAngRateVec[1];
            sAngRateVecTmp.z = aocs_data.ai32EstAngRateVec[2];

            ret = conops_chk_stable_y_thomson(&sAngRateVecTmp);
        }
        else
        {
            int32_t omega_thresh;

            if (true != conops_get_thresh_val(&omega_thresh, CONOPS_THRESHOLDVALUETYPES_ANGVEL_MIN))
            {
                return ret;
            }

            if (omega_thresh > aocs_data.i32EstAngRateNorm)
            {
                ret = true;
            }
        }
    }

    ES_TRACE_DEBUG("%s: conops_is_detumb_completed: %d\r", CONOPS_SM_TEST_COND, ret);

    return ret;
}

void conops_refresh_runtime_nvm_copies(void)
{
    Nvm_GetBlockById(NVM_APP_BLOCK_CONOPS_CONFIG, &conops_cfg);
}

bool conops_get_aocs_sys_state(aocs_cntrl_sys_state_types_t *const p_sys_state, aocs_cntrl_sys_state_req_state_t *const p_sys_state_req_state)
{
    return (AOCS_CNTRL_ERR_OK == aocs_cntrl_get_aocs_state(p_sys_state, p_sys_state_req_state));
}

void conops_set_aocs_sys_state(aocs_cntrl_sys_state_types_t sys_state, const aocs_cntrl_reference_params_t *const p_ref_params)
{
    (void)aocs_cntrl_request_aocs_state(sys_state, p_ref_params);
}

void conops_trigger_task(void)
{
    (void)osThreadFlagsSet(h_conops_p_ev_task, CONOPS_TRIGGER_TASK_FLAG);
}

bool conops_is_payload_allowed(void)
{
    bool ret = false;

    uint8_t conops_mode;
    conops_get_hsm_active_state(&conops_mode);
    conops_nvm_data_t nvm_data;
    Nvm_GetBlockById(NVM_BLOCK_CONOPS_DATA, &nvm_data);

    if ((STATE_MISSION == conops_mode) || IS_TRUE(nvm_data.force_enable_payload))
    {
        ret = true;
    }

    return ret;
}

/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/

static void conops_p_ev_init(void)
{
    EXEH_INIT_MODULE_FILENAME();

    h_conops_p_ev_task = osThreadNew(conops_task, NULL, &conops_p_ev_task_attributes);

    if (NULL == h_conops_p_ev_task)
    {
        EXEH_HANDLE(eEXEHSeverity_Fatal, eEXEH_CON_OPS_EXCEPTION_TASK_INIT_FAILURE);
    }
    else
    {
        task_mon_task_initialized(TASK_ID_CONOPS_PERIODIC_EV);
        task_mon_register_for_stats(TASK_ID_CONOPS_PERIODIC_EV, h_conops_p_ev_task);
    }
}

static bool conops_chk_stable_y_thomson(const conops_3axis_vec_t *const p_ang_rate_vec)
{
    bool ret = false;

    int32_t omega_low_thresh;
    int32_t omega_high_thresh;

    if ((false != conops_get_thresh_val(&omega_low_thresh, CONOPS_THRESHOLDVALUETYPES_ANGVEL_Y_THOMSON_LOW)) &&
        (false != conops_get_thresh_val(&omega_high_thresh, CONOPS_THRESHOLDVALUETYPES_ANGVEL_Y_THOMSON_HIGH)))
    {
        ret = true;
    }

    if (false != ret)
    {
        uint8_t chk_cnt = 0;

        if ((omega_low_thresh < p_ang_rate_vec->y) && (p_ang_rate_vec->y < omega_high_thresh))
        {
            ++chk_cnt;
        }

        if ((CONOPS_ADCS_Y_THOMSON_POS_THRESH_MRAD_S > p_ang_rate_vec->x) && (p_ang_rate_vec->x > CONOPS_ADCS_Y_THOMSON_NEG_THRESH_MRAD_S))
        {
            ++chk_cnt;
        }

        if ((CONOPS_ADCS_Y_THOMSON_POS_THRESH_MRAD_S > p_ang_rate_vec->z) && (p_ang_rate_vec->z > CONOPS_ADCS_Y_THOMSON_NEG_THRESH_MRAD_S))
        {
            ++chk_cnt;
        }

        if (CONOPS_ADCS_T_YHOMSON_STABLE_VERIFIED == chk_cnt)
        {
            ret = true;
        }
        else
        {
            ret = false;
        }
    }

    return ret;
}

static void conops_task(void *arg)
{
    (void)arg;

    // Reset of the state machine is done here because some of its internal logic is expected
    // to call OS APIs which have to be called from the context of an OS thread.
    (void)conops_trigger_hsm(eHSM_StdEvent_Reset, NULL);

    for (;;)
    {
        (void)osThreadFlagsWait(CONOPS_TRIGGER_TASK_FLAG, osFlagsWaitAny, CONOPS_PER_EV_TASK_PERIOD);

        conops_refresh_runtime_nvm_copies();

        (void)conops_trigger_hsm(eHSM_StdEvent_Periodic, NULL);

        task_mon_i_am_alive(TASK_ID_CONOPS_PERIODIC_EV);
        task_mon_low_stack_check(TASK_ID_CONOPS_PERIODIC_EV);
    }
}
