/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup fdir_srv
 * @{
 *
 * @file     fdir_srv.c
 * @brief    FDIR service implementation
 *
 * @}
 */

#include <assert.h>
#include "fdir_srv.h"
#include "cmsis_os2.h"
#include "assertions.h"
#include "trace.h"
#include "taskmon.h"
#include "taskmon_stat.h"
#include "nvm.h"
#include "timer.h"
#include "if_sys_conf.h"
#include "fdir_srv_log.h"
#include "fdir_srv_internal.h"

INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

#define FDIR_AGENT_TASK_PERIOD_MS (10000U)

#define FDIR_THREAD_FLAG_FAULT_UPDATE (0x01)

#define FDIR_MESSAGE_QUEUE_SIZE (50)

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

/**
 * @brief Structure for messages between the API for set/simulate faults and the FDIR service task
 */
typedef struct
{
    fdir_fault_id_t fault_id; /**< FDIR fault id */
    fdir_agent_id_t agent_id; /**< FDIR agent id */
    bool            active;   /**< New fault state */
    void           *p_ctx;    /**< Context information to be passed to the handler */
} PACKED fdir_message_t;

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

/**
 *  @brief Attributes of the FDIR service mutex
 */
static const osMutexAttr_t h_fdir_mutex_attr = {
    .name      = NULL,
    .attr_bits = osMutexPrioInherit | osMutexRecursive, // Mutex can be locked again if an action handler invokes
                                                        // reporting another fault (e.g. during escalation)
    .cb_mem  = NULL,
    .cb_size = 0
};

/**
 *  @brief FDIR level for the entire system. This is the highest FDIR level detected by the FDIR
 *         agents in the system
 */
static uint8_t system_fdir_level = 0;

/**
 *  @brief The level below which the system won't go.
 *         It can be changed only by an operator.
 *         This is for testing purposes and should be set to 0 in normal operation
 */
static uint8_t system_fdir_level_min = 0;

/**
 *  @brief Mutex used to protect FDIR service data from concurrent access
 *
 *  @note This mutex is used only in the public methods of the FDIR service
 */
static osMutexId_t h_fdir_mutex = NULL;

/**
 * @brief Handle for the cmsis message queue used for communication between the FDIR service and the FDIR agent task
 */
static osMessageQueueId_t h_fdir_fault_queue = NULL;

/**
 * @brief OS thread handle for the FDIR agent task
 */
static osThreadId_t h_fdir_agent_task = NULL;

/**
 * @brief OS thread name for the FDIR agent task
 */
static const char *const fdir_task_name = "fdir_task";

/**
 *  @brief Array of dynamic data objects for all faults in the system
 */
fdir_fault_dyn_t fdir_faults_dyn[FDIR_FAULT_COUNT];

/**
 *  @brief Array of counters that gives how many faults are active for each system FDIR level
 */
static uint8_t fdir_level_counter[FDIR_LEVEL_COUNT];

/**
 * @brief FDIR levels for all agents in the system
 */
static uint8_t fdir_agent_level[FDIR_AGENT_COUNT];

/**
 * @brief FDIR levels for all agents in the system
 */
static bool fdir_agent_fault_table[FDIR_AGENT_COUNT][FDIR_FAULT_COUNT];

/**
 * @brief Configuration for the FDIR service.
 *      This structure is stored in NVM and is used to configure the FDIR service
 *      It contains the following fields:
 *      - fault_automatic_clear_limit: The FDIR level at which or above no automatic clearing of the fault will happen by the system.
 *                                     The fault can be cleared only by the operator.
 *      - fault_detection_active: Array of flags that indicate if the detection of the fault is active or not.
 *      The data is initialized by the NVM block values.
 */
// static fdir_srv_nvm_data_t fdir_fault_config = {.fault_automatic_clear_limit = FDIR_LEVEL_MAJOR, .fault_detection_active = {[0 ... FDIR_FAULT_COUNT - 1] = true}};
static fdir_srv_nvm_data_t fdir_fault_config;

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/

/**
 * @brief Static pre-compilation checks the configuration of the FDIR service
 */
static void fdir_srv_check_cfg(void);

/**
 *  @brief Raises a fault and updates the FDIR level of the reporting agent and system
 *
 *  @param fault_id[in]:  ID of the fault that is reported by the invoking agent
 *  @param agent[in]:     ID of the agent determining the state of the fault
 *  @param p_ctx[in]: Context information to be passed to the handler. Could also be modified in the handler function
 */
static void raise_fault(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent_id, void *p_ctx);

/**
 *  @brief Clears a fault and updates the FDIR level of the reporting agent and system
 *  @note The fault is cleared only if it is below the autoclear level unless force is true
 *
 *  @param fault_id[in]: ID of the fault that is reported by the invoking agent
 *  @param agent[in]: ID of the agent determining the state of the fault
 *  @param force[in]: Optional internal argument to bypass the autoclear level, so an operator can clear the fault
 *  @param p_ctx[in]: Context information to be passed to the handler. Could also be modified in the handler function
 */
static void clear_fault(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent_id, bool force, void *p_ctx);

/**
 *  @brief Calls the handler actions configured for a specified fault. For each action the function reads
 *         the associated FDIR level and reports the level of the final action
 *
 *  @param fault_id[in]:  ID of the fault that has its actions invoked
 *  @param p_ctx[in,out]: Context information to be passed to the handlers. Could also be modified in the handler functions
 *
 *  @return FDIR level reached after calling all configured actions
 */
static uint8_t fdir_srv_invoke_actions(const fdir_fault_id_t fault_id, void *const p_ctx);

/**
 * @brief Cycles through all faults and updates the FDIR level of the system
 */
static bool fdir_srv_update_sys_fdir_level(void);

/**
 * @brief Cycles through all faults and updates the FDIR level of the agents
 */
static void fdir_srv_update_agent_fdir_level(const fdir_agent_id_t agent_id);

/**
 * @brief Task for the FDIR service
 */
static void fdir_srv_task(void *arg);

/**
 *  @brief Updates the FDIR state in the FDIR task based on the message received from the agents.
 */
static void update_fdir_state(const fdir_message_t *const message);

/**
 * @brief Internal subfuction for setting the state of a fault
 */
static bool fault_set_state(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent_id, bool active, bool force, void *p_ctx);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

bool fdir_srv_init(void)
{
    bool keep_processing = true;

    memset(fdir_faults_dyn, 0, sizeof(fdir_faults_dyn));
    memset(fdir_level_counter, 0, sizeof(fdir_level_counter));
    memset(fdir_agent_level, 0, sizeof(fdir_agent_level));

    Nvm_GetBlockById(NVM_BLOCK_FDIR_SRV_DATA, &fdir_fault_config);

    fdir_srv_check_cfg();

    if (true == keep_processing)
    {
        h_fdir_mutex    = osMutexNew(&h_fdir_mutex_attr);
        keep_processing = (NULL != h_fdir_mutex);
    }

    if (true == keep_processing)
    {
        h_fdir_fault_queue = osMessageQueueNew(FDIR_MESSAGE_QUEUE_SIZE, sizeof(fdir_message_t), NULL);
        keep_processing    = (NULL != h_fdir_mutex);
    }

    if (true == keep_processing)
    {
        osThreadAttr_t attr = {
            .name       = fdir_task_name,
            .attr_bits  = 0,
            .cb_mem     = NULL,
            .cb_size    = 0,
            .stack_mem  = NULL,
            .stack_size = 2048,
            .priority   = osPriorityNormal,
            .tz_module  = 0,
            .reserved   = 0
        };
        h_fdir_agent_task = osThreadNew(fdir_srv_task, NULL, &attr);
        keep_processing   = (NULL != h_fdir_agent_task);
    }

    if (true == keep_processing)
    {
        task_mon_set_task_policy(TASK_ID_FDIR, TASK_MON_POLICY_MONITOR);
        task_mon_register_for_stats(TASK_ID_FDIR, h_fdir_agent_task);
    }

    return keep_processing;
}

bool fdir_srv_fault_is_detection_enabled(const fdir_fault_id_t fault_id)
{
    bool       is_enabled      = false;
    bool       keep_processing = true;
    osStatus_t status;
    if (FDIR_FAULT_COUNT <= fault_id)
    {
        BREAK_ASSERT(false);
        ES_TRACE_WARN("Status of invalid fault ID %d cannot be determined", fault_id);
        keep_processing = false;
    }

    if (true == keep_processing)
    {
        status = osMutexAcquire(h_fdir_mutex, osWaitForever);
        if (osOK != status)
        {
            BREAK_ASSERT(false);
            ES_TRACE_WARN("Error acquiring mutex %d", status);
            keep_processing = false;
        }
    }

    if (true == keep_processing)
    {
        is_enabled = fdir_fault_config.fault_detection_active[fault_id];
        (void)osMutexRelease(h_fdir_mutex);
    }

    return is_enabled;
}

bool fdir_srv_fault_enable_detection(const fdir_fault_id_t fault_id, const bool detect)
{
    bool       keep_processing = true;
    osStatus_t status;

    if (FDIR_FAULT_COUNT <= fault_id)
    {
        BREAK_ASSERT(false);
        ES_TRACE_WARN("Trying to set detection of invalid fault ID %d to %s", fault_id, detect ? "enabled" : "disabled");
        keep_processing = false;
    }

    if (true == keep_processing)
    {
        status = osMutexAcquire(h_fdir_mutex, osWaitForever);
        if (osOK != status)
        {
            BREAK_ASSERT(false);
            ES_TRACE_WARN("Error acquiring mutex %d", status);
            keep_processing = false;
        }
    }

    if (true == keep_processing)
    {
        if (detect != fdir_fault_config.fault_detection_active[fault_id])
        {
            fdir_fault_config.fault_detection_active[fault_id] = detect;
            Nvm_SetBlockById(NVM_BLOCK_FDIR_SRV_DATA, &fdir_fault_config, NVMSETBLOCK_STORE_IMMEDIATELY);
        }
        (void)osMutexRelease(h_fdir_mutex);
    }

    return keep_processing;
}

bool fdir_srv_fault_set_state(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent_id, bool active, void *p_ctx)
{
    return fault_set_state(fault_id, agent_id, active, false, p_ctx);
}

bool fdir_srv_fault_set_state_force(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent_id, bool active, void *p_ctx)
{
    return fault_set_state(fault_id, agent_id, active, true, p_ctx);
}

fdir_fault_dyn_t fdir_srv_fault_get_state(const fdir_fault_id_t fault_id)
{
    bool             keep_processing = true;
    osStatus_t       status;
    fdir_fault_dyn_t ret = { .fault_active = false, .fdir_level_dyn = FDIR_LEVEL_INVALID };

    if (FDIR_FAULT_COUNT <= fault_id)
    {
        BREAK_ASSERT(false);
        ES_TRACE_WARN("Status of invalid fault ID %d cannot be determined", fault_id);
        keep_processing = false;
    }

    if (true == keep_processing)
    {
        status = osMutexAcquire(h_fdir_mutex, osWaitForever);
        if (osOK != status)
        {
            BREAK_ASSERT(false);
            ES_TRACE_WARN("Error acquiring mutex %d", status);
            keep_processing = false;
        }
    }

    if (true == keep_processing)
    {
        ret = fdir_faults_dyn[fault_id];
        (void)osMutexRelease(h_fdir_mutex);
    }

    return ret;
}

uint8_t fdir_srv_system_get_fdir_level(void)
{
    bool     keep_processing = true;
    uint8_t  ret             = FDIR_LEVEL_INVALID;
    osStatus status;

    status = osMutexAcquire(h_fdir_mutex, osWaitForever);
    if (osOK != status)
    {
        BREAK_ASSERT(false);
        ES_TRACE_WARN("Error acquiring mutex %d", status);
        keep_processing = false;
    }

    if (true == keep_processing)
    {
        ret = system_fdir_level > system_fdir_level_min ? system_fdir_level : system_fdir_level_min;
        (void)osMutexRelease(h_fdir_mutex);
    }

    return ret;
}

uint8_t fdir_srv_system_get_fdir_level_min(void)
{
    bool       keep_processing = true;
    osStatus_t status;
    uint8_t    ret = FDIR_LEVEL_INVALID;

    status = osMutexAcquire(h_fdir_mutex, osWaitForever);
    if (osOK != status)
    {
        BREAK_ASSERT(false);
        ES_TRACE_WARN("Error acquiring mutex %d", status);
        keep_processing = false;
    }

    if (true == keep_processing)
    {
        ret = system_fdir_level_min;
        (void)osMutexRelease(h_fdir_mutex);
    }

    return ret;
}

bool fdir_srv_system_set_fdir_level_min(const uint8_t level)
{
    bool       keep_processing = true;
    bool       notify          = false;
    osStatus_t status;
    status = osMutexAcquire(h_fdir_mutex, osWaitForever);
    if (osOK != status)
    {
        BREAK_ASSERT(false);
        ES_TRACE_WARN("Error acquiring mutex %d", status);
        keep_processing = false;
    }

    if (true == keep_processing)
    {
        fdir_srv_update_sys_fdir_level();
        system_fdir_level_min = level;
        if (system_fdir_level_min > system_fdir_level)
        {
            system_fdir_level = system_fdir_level_min;
            notify            = true;
        }
        osMutexRelease(h_fdir_mutex);
        if (true == notify)
        {
            fdir_srv_cfg_sys_level_update_notif();
        }
    }
    return keep_processing;
}

uint8_t fdir_srv_agent_get_fdir_level(const fdir_agent_id_t agent_id)
{
    bool       keep_processing = true;
    uint8_t    ret             = FDIR_LEVEL_INVALID;
    osStatus_t status;

    if (FDIR_AGENT_COUNT <= agent_id)
    {
        BREAK_ASSERT(false);
        ES_TRACE_WARN("Attempt to get status of invalid agent ID %d", agent_id);
        keep_processing = false;
    }

    if (true == keep_processing)
    {
        status = osMutexAcquire(h_fdir_mutex, osWaitForever);
        if (osOK != status)
        {
            ES_TRACE_WARN("Failed to acquire mutex with error %u", status);
            BREAK_ASSERT(false);
            keep_processing = false;
        }
    }

    if (true == keep_processing)
    {
        ret = fdir_agent_level[agent_id];

        (void)osMutexRelease(h_fdir_mutex);
    }

    return ret;
}

uint8_t fdir_srv_system_get_user_clear_level(void)
{
    bool       keep_processing = true;
    uint8_t    ret             = FDIR_LEVEL_INVALID;
    osStatus_t status;

    status = osMutexAcquire(h_fdir_mutex, osWaitForever);
    if (osOK != status)
    {
        BREAK_ASSERT(false);
        ES_TRACE_WARN("Error acquiring mutex %d", status);
        keep_processing = false;
    }

    if (true == keep_processing)
    {
        ret = fdir_fault_config.fault_automatic_clear_limit;
        (void)osMutexRelease(h_fdir_mutex);
    }

    return ret;
}

bool fdir_srv_system_set_user_clear_level(const uint8_t level)
{
    bool       keep_processing = true;
    osStatus_t status;

    // level may be above the maximum FDIR level
    if (level > FDIR_LEVEL_COUNT)
    {
        ES_TRACE_WARN("Invalid FDIR level %d", level);
        BREAK_ASSERT(false);
        keep_processing = false;
    }

    if (true == keep_processing)
    {
        status = osMutexAcquire(h_fdir_mutex, osWaitForever);
        if (osOK != status)
        {
            ES_TRACE_WARN("Failed to acquire mutex with error %u", status);
            BREAK_ASSERT(false);
            keep_processing = false;
        }
    }

    if (true == keep_processing)
    {
        fdir_fault_config.fault_automatic_clear_limit = level;
        Nvm_SetBlockById(NVM_BLOCK_FDIR_SRV_DATA, &fdir_fault_config, NVMSETBLOCK_STORE_IMMEDIATELY);

        (void)osMutexRelease(h_fdir_mutex);
    }
    return keep_processing;
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

static void update_fdir_state(const fdir_message_t *const message)
{
    bool                  keep_processing = true;
    const fdir_fault_id_t fault_id        = message->fault_id;
    const fdir_agent_id_t agent_id        = message->agent_id;
    const bool            active          = message->active;
    osStatus_t            status;
    uint8_t               fault_fdir_level;
    BREAK_ASSERT(FDIR_AGENT_COUNT > agent_id);
    BREAK_ASSERT(FDIR_FAULT_COUNT > fault_id);
    bool update_sys_level = false;

    if (true == active)
    {
        // Invoke isolation/recovery actions
        fault_fdir_level = fdir_srv_invoke_actions(fault_id, message->p_ctx);
    }

    status = osMutexAcquire(h_fdir_mutex, osWaitForever);
    if (osOK != status)
    {
        BREAK_ASSERT(false);
        ES_TRACE_WARN("Error acquiring mutex %d", status);
        keep_processing = false;
    }

    if (true == keep_processing)
    {
        if (true == active)
        {
            // Update FDIR level of the reporting agent
            fdir_faults_dyn[fault_id].fdir_level_dyn = fault_fdir_level;

            fdir_agent_fault_table[agent_id][fault_id] = true;

            uint8_t *const p_agent_level = &fdir_agent_level[agent_id];
            if (fault_fdir_level > *p_agent_level)
            {
                *p_agent_level = fault_fdir_level;
            }

            // Increase the number of errors with the same FDIR level as the fault
            if (fault_fdir_level < FDIR_LEVEL_COUNT)
            {
                fdir_level_counter[fault_fdir_level]++;
            }

            // Update system FDIR level
            if (fault_fdir_level > system_fdir_level)
            {
                system_fdir_level = fault_fdir_level;
                update_sys_level  = true;
            }
        }
        else
        {
            fdir_level_counter[fdir_faults_dyn[fault_id].fdir_level_dyn]--;

            fdir_faults_dyn[fault_id].fdir_level_dyn = 0;

            // clear the fault for all affected agents
            for (fdir_agent_id_t idx = 0; idx < FDIR_AGENT_COUNT; idx++)
            {
                fdir_agent_fault_table[idx][fault_id] = false;
                fdir_srv_update_agent_fdir_level(idx);
            }

            // Update system FDIR level
            (void)fdir_srv_update_sys_fdir_level();
        }

        (void)osMutexRelease(h_fdir_mutex);

        if (true == update_sys_level)
        {
            fdir_srv_cfg_sys_level_update_notif();
        }
    }
}

static void fdir_srv_task(void *arg)
{
    (void)arg;
    timer_handle_t th;
    timer_start(&th);
    while (1)
    {
        uint32_t       wait_ms;
        uint32_t       elapsed_ms;
        osStatus_t     status;
        fdir_message_t message;

        elapsed_ms = timer_get_elapsed_time(&th);
        if (FDIR_AGENT_TASK_PERIOD_MS > elapsed_ms)
        {
            wait_ms = FDIR_AGENT_TASK_PERIOD_MS - elapsed_ms;
        }
        else
        {
            wait_ms = 0;
        }

        status = osMessageQueueGet(h_fdir_fault_queue, &message, NULL, wait_ms);
        if (osOK == status)
        {
            update_fdir_state(&message);
        }
        else if ((osErrorTimeout == status) ||
                 (osErrorResource == status))
        {
            // no new fault messages
            timer_start(&th);
            // low stack check is a slow operation, so do it rarely and only if no messages are present
            task_mon_low_stack_check(TASK_ID_FDIR);
        }
        else
        {
            ES_TRACE_FATAL("Error getting fault id from queue with status %d", status);
            CRIT_ASSERT(false);
        }

        task_mon_i_am_alive(TASK_ID_FDIR);

        status = osMutexAcquire(h_fdir_mutex, osWaitForever);
        if (osOK != status)
        {
            BREAK_ASSERT(false);
            ES_TRACE_WARN("Error acquiring mutex %d", status);
        }
        else
        {
            Nvm_GetBlockById(NVM_BLOCK_FDIR_SRV_DATA, &fdir_fault_config);
            osMutexRelease(h_fdir_mutex);
        }
    }
}

static void fdir_srv_check_cfg(void)
{
    static_assert(FDIR_FAULT_COUNT < FDIR_ENUM_BIT_EXTENDER - 1,
                  "Enumeration fdir_fault_id_t contains"
                  " more literals than supported by FIDL interface");
    static_assert(FDIR_AGENT_COUNT < FDIR_ENUM_BIT_EXTENDER - 1,
                  "Enumeration fdir_agent_id_t contains"
                  " more literals than supported by FIDL interface");
}

static bool fault_set_state(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent_id, bool active, bool force, void *p_ctx)
{
    bool       keep_processing = true;
    osStatus_t status;

    if (FDIR_FAULT_COUNT <= fault_id)
    {
        BREAK_ASSERT(false);
        ES_TRACE_WARN("Status of invalid fault ID %d set to %d (agent id %d)", fault_id, active, agent_id);
        fdir_srv_log(fault_id, agent_id, "%c, Invalid fault ID", active ? 'A' : 'I');
        keep_processing = false;
    }

    if (FDIR_AGENT_COUNT <= agent_id)
    {
        BREAK_ASSERT(false);
        ES_TRACE_WARN("Status of invalid agent ID %d (fault id %d set to %d )", agent_id, fault_id, active);
        fdir_srv_log(fault_id, agent_id, "%c, Invalid agent ID", active ? 'A' : 'I');
        keep_processing = false;
    }

    if (true == keep_processing)
    {
        status = osMutexAcquire(h_fdir_mutex, osWaitForever);
        if (osOK != status)
        {
            BREAK_ASSERT(false);
            ES_TRACE_WARN("Error acquiring mutex %d", status);
            keep_processing = false;
        }
    }

    if (true == keep_processing)
    {
        ES_TRACE_DEBUG("Setting fault id %d %s as %s", fault_id, get_fault_id_name(fault_id), active ? "active" : "clear");
        // Don't do any updates and notifications if there is no change in status
        if (active != fdir_faults_dyn[fault_id].fault_active)
        {
            fdir_srv_log(fault_id, agent_id, "Transition to %s state", active ? "active" : "inactive");

            if (true == active)
            {
                if (true == fdir_srv_fault_is_detection_enabled(fault_id))
                {
                    raise_fault(fault_id, agent_id, p_ctx);
                }
                else
                {
                    ES_TRACE_DEBUG("Detection for fault id %d is disabled", fault_id, get_fault_id_name(fault_id));
                }
            }
            else
            {
                clear_fault(fault_id, agent_id, force, p_ctx);
            }
        }

        (void)osMutexRelease(h_fdir_mutex);
    }

    return (true == keep_processing);
}

static void raise_fault(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent_id, void *p_ctx)
{
    BREAK_ASSERT(FDIR_FAULT_COUNT > fault_id);
    const uint8_t  level   = g_fdir_action[fault_id].fdir_level;
    fdir_message_t message = { .fault_id = fault_id, .agent_id = agent_id, .active = true, .p_ctx = p_ctx };

    osStatus_t status;
    ES_TRACE_INFO("Raising fault %d %s by %d %s", fault_id, get_fault_id_name(fault_id), agent_id, get_agent_id_name(agent_id));

    fdir_faults_dyn[fault_id].fault_active = true;

    status = osMessageQueuePut(h_fdir_fault_queue, &message, level, osWaitForever);
    if (osOK != status)
    {
        // We should never have a full queue, otherwise faults will be dropped
        ES_TRACE_FATAL("Error putting fault id %d to queue with status %d", fault_id, status);
        CRIT_ASSERT(false);
    }
}

static void clear_fault(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent_id, bool force, void *p_ctx)
{
    BREAK_ASSERT(FDIR_FAULT_COUNT > fault_id);
    fdir_fault_dyn_t *const p_fault = &fdir_faults_dyn[fault_id];
    const uint8_t           level   = g_fdir_action[fault_id].fdir_level;
    fdir_message_t          message = { .fault_id = fault_id, .agent_id = agent_id, .active = false, .p_ctx = p_ctx };
    osStatus_t              status;
    if ((true == force) ||
        (fdir_fault_config.fault_automatic_clear_limit > p_fault->fdir_level_dyn))
    {
        ES_TRACE_DEBUG("Clearing fault %d %s by %d %s", fault_id, get_fault_id_name(fault_id), agent_id, get_agent_id_name(agent_id));

        // It shall be possible to clear faults when detection is disabled
        p_fault->fault_active = false;

        status = osMessageQueuePut(h_fdir_fault_queue, &message, level, osWaitForever);
        if (osOK != status)
        {
            // We should never have a full queue, otherwise faults will be dropped
            ES_TRACE_FATAL("Error putting fault id %d to queue with status %d", fault_id, status);
            CRIT_ASSERT(false);
        }
    }
}

static uint8_t fdir_srv_invoke_actions(const fdir_fault_id_t fault_id, void *const p_ctx)
{
    uint8_t              fault_fdir_level = FDIR_LEVEL_INVALID;
    const fdir_action_t *p_action         = &g_fdir_action[fault_id];

    if (NULL != p_action)
    {
        fault_fdir_level = p_action->fdir_level;
    }

    while (NULL != p_action)
    {
        // On every subsequent escalated action set the FDIR level to the one configured for the action
        if (p_action->fdir_level > fault_fdir_level)
        {
            fault_fdir_level = p_action->fdir_level;
        }

        if (NULL != p_action->p_action_func)
        {
            // Execute the configured action function
            const fdir_action_result_t res = p_action->p_action_func(fault_id, p_ctx);
            if ((FDIR_ACTION_RESULT_ESCALATE == res) && (NULL != p_action->p_escalated_action))
            {
                // Move to the escalated action only if the action function requires escalation
                p_action = p_action->p_escalated_action;
            }
            else
            {
                // Exit the loop because no escalation is required
                p_action = NULL;
            }
        }
        else
        {
            // Exit the loop because there is no configured action
            p_action = NULL;
        }
    }

    return fault_fdir_level;
}

/**
 *  @brief Goes through the counters for all active FDIR levels and sets the highest FDIR level as a system one
 */
static bool fdir_srv_update_sys_fdir_level(void)
{
    bool    ret            = false;
    uint8_t tmp_fdir_level = 0;
    for (uint8_t lvl = FDIR_LEVEL_COUNT - 1; lvl > 0; lvl--)
    {
        if (fdir_level_counter[lvl] > 0)
        {
            tmp_fdir_level = lvl;
            break;
        }
    }

    if (tmp_fdir_level != system_fdir_level)
    {
        system_fdir_level = tmp_fdir_level;
        ret               = true;
    }

    return ret;
}

/**
 *  @brief Goes through all the faults and for those reported by a specified agent selects the highest
 *         FDIR level active for a fault and sets it as the current FDIR level for the agent
 */
static void fdir_srv_update_agent_fdir_level(const fdir_agent_id_t agent_id)
{
    bool    keep_processing = true;
    uint8_t max_fdir_level  = 0;

    BREAK_ASSERT(FDIR_AGENT_COUNT > agent_id);

    if (true == keep_processing)
    {
        const bool *agent_fault_table = fdir_agent_fault_table[agent_id];

        for (fdir_fault_id_t fault_id = 0; fault_id < FDIR_FAULT_COUNT; fault_id++)
        {
            if ((true == agent_fault_table[fault_id]) &&
                (false != fdir_faults_dyn[fault_id].fault_active) &&
                (fdir_faults_dyn[fault_id].fdir_level_dyn > max_fdir_level))
            {
                max_fdir_level = fdir_faults_dyn[fault_id].fdir_level_dyn;
            }
        }

        fdir_agent_level[agent_id] = max_fdir_level;
    }
}
