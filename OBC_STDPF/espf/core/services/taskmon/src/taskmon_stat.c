/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup taskmon
 * @{
 *
 * @file    task_mon.c
 * @brief   Monitors if all task are running.
 *
 * @}
 *
 */

#include "es_cdef.h"
#include "taskmon.h"
#include "taskmon_stat.h"
#include <stdio.h>
#include <string.h>
#include "rlf.h"
#include "nvm.h"
#include "trace.h"

/** @brief The default period for task statistics sampling in milliseconds. */
#define TASK_MON_STAT_DEFAULT_PERIOD (1000)

/** @brief The default name for the file to be filled with the description of the task ids. */
#define TASK_DEFAULT_ID_TABLE_FILE "task_id_table.txt"

/** @brief The delay in milliseconds for the file system to initialize. This is a rough estimate */
#define TASK_STAT_WAIT_FOR_FM_MNG (1000)

/** @brief The size of the char buffer used for preparing the formatted text for writing to the log file */
#define TASK_STAT_LOG_BUFFER (512)

/*
*********************************************************************************************
* INTERNAL TYPES DEFINITION
*********************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/*
*********************************************************************************************
* EXTERNAL VARIABLES DEFINITION
*********************************************************************************************
*/
/* No External variables definition */

/*
*********************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
*********************************************************************************************
*/

osThreadId_t                task_mon_stat_handle    = NULL;
static const osThreadAttr_t task_mon_stat_task_attr = {
    .name       = NULL,
    .priority   = (osPriority_t)osPriorityNormal,
    .stack_size = (1 << 11),
    .attr_bits  = 0,
    .cb_mem     = NULL,
    .cb_size    = 0,
    .tz_module  = 0,
    .reserved   = 0,
    .stack_mem  = NULL,
};

/** @brief The default configuration for the task statistics */
static const task_mon_stat_config_t task_mon_stat_config_default = {
    .enabled       = false,
    .logging       = false,
    .priority      = osPriorityLow,
    .period        = TASK_MON_STAT_DEFAULT_PERIOD,
    .id_table_file = TASK_DEFAULT_ID_TABLE_FILE,
    .last_update   = 0,
    .free_heap     = 0,
};

/**
 * @brief Array of the names of the tasks with their corresponding id as index.
 */
static const char *const task_mon_stat_id_name[TASK_ID_MAX] = {
#define TASK_MON_ID_MACRO(id) #id
#include "taskmon_id.inc"
#undef TASK_MON_ID_MACRO
};

/** @brief The current configuration for the task statistics */
static task_mon_stat_config_t task_mon_stat_config = {
    .enabled       = false,
    .logging       = false,
    .priority      = osPriorityLow,
    .period        = TASK_MON_STAT_DEFAULT_PERIOD,
    .id_table_file = TASK_DEFAULT_ID_TABLE_FILE,
    .last_update   = 0,
    .free_heap     = 0,
};

/** @brief The configuration and last statistics sample for all tasks */
static task_stat_t task_mon_stat[TASK_ID_MAX] = { 0 };

/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
*********************************************************************************************
*/

/**
 * @brief Load the nvm configuration for the task statistics.
 */
static void task_mon_stat_init_config(void);

/**
 * @brief Task that does the sampling and logging for the task statistics.
 *
 * @param arg: Unused
 */
static void task_mon_stat_task(void *arg);

/**
 * @brief Update the task id table file.
 * @details This function fills the file defined in the task_mon_stat_config.id_table_file with the task id names and their corresponding id.
 *
 * @param[in] table_file_name The name of the file to be filled.
 *
 * @retval true: The file was successfully updated.
 * @retval false: The file was not updated due to issues with file name or the file system.
 */
static bool task_mon_stat_update_id_table_file(const char *table_file_name);

/**
 * @brief Check if a task with a specific id is enabled for statistics.
 *
 * @param[in] task The task id to check.
 *
 * @note For a task to be considered enabled, it must be initialized, have a valid handle and be enabled in the task_mon_stat array.
 */
static inline bool task_mon_stat_is_task_enabled(task_mon_id_t task);

/**
 * @brief Update tasks runtime statistics.
 *
 * @note This function is intentionally **NOT** thread-safe. The goal is speed and simplicity. It should only be called from a single task.
 */
static void task_mon_stat_sampling(void);

/**
 * @brief Flush current statistics to file. The actual worker function behing task_mon_stat_do_log()
 *
 * @note This function is intentionally **NOT** thread-safe. The goal is speed and simplicity. It should only be called from a single task.
 */
static void task_mon_stat_log_loop(void);

/**
 * @brief Flush current statistics to file.
 *
 * @note This function is intentionally **NOT** thread-safe. The goal is speed and simplicity. It should only be called from a single task.
 */
static void task_mon_stat_do_log(void);

static bool task_mon_stat_update_id_table_file(const char *table_file_name)
{
    bool          ret = true;
    fm_file_obj_t stat_id_file;
    if (FM_RES_OK == fm_open(&stat_id_file, table_file_name, FM_MODE_CREATE_ALWAYS | FM_MODE_WRITE))
    {
        for (uint8_t i = 0; i < TASK_ID_MAX; i++)
        {
            if (FM_RES_OK != fm_printf(&stat_id_file, NULL, "%s=%u\n", task_mon_stat_id_name[i], i))
            {
                ret = false;
                break;
            }
        }
        fm_close(&stat_id_file);
        if (false == ret)
        {
            fm_delete(table_file_name);
        }
    }
    else
    {
        ret = false;
    }
    return ret;
}

void task_mon_register_for_stats(task_mon_id_t task, TaskHandle_t handle)
{
    if (task < TASK_ID_MAX)
    {
        if (NULL != handle)
        {
            TaskStatus_t task_status;
            vTaskGetInfo(handle, &task_status, pdFALSE, eReady); // if eState is not eInvalid, the state value in task_status is not updated which saves time.
            if (task_status.xHandle == handle)
            {
                task_mon_stat[task].task_handle = handle;
            }
        }
        else
        {
            task_mon_stat[task].task_handle = NULL;
        }
    }
}

static void task_mon_stat_init_config(void)
{
    task_stat_config_nvm_t nvm_data;
    Nvm_GetBlockById(NVM_BLOCK_TASK_STATS_CONFIG, &nvm_data);
    task_mon_stat_config.enabled = nvm_data.enabled;
    task_mon_stat_config.logging = nvm_data.logging;
    task_mon_stat_config.priority = nvm_data.priority;
    task_mon_stat_config.period = nvm_data.period;
    strncpy(task_mon_stat_config.id_table_file, nvm_data.id_table_file, sizeof(task_mon_stat_config.id_table_file) - 1);
    task_mon_stat_config.id_table_file[sizeof(task_mon_stat_config.id_table_file) - 1] = '\0';

    task_stat_config_specific_nvm_t nvm_data_per_task;
    Nvm_GetBlockById(NVM_BLOCK_TASK_STATS_CONFIG, &nvm_data_per_task);
    for (uint8_t i = 0; i < TASK_ID_MAX; i++)
    {
        task_mon_stat[i].enabled = nvm_data_per_task.enabled[i];
        task_mon_stat[i].logging = nvm_data_per_task.logging[i];
    }
}

static void task_mon_stat_task(void *arg)
{
    task_mon_stat_init_config();

    osDelay(TASK_STAT_WAIT_FOR_FM_MNG);
    task_mon_stat_update_id_table_file(task_mon_stat_config.id_table_file);
    TaskHandle_t idle_handle;
    idle_handle = xTaskGetIdleTaskHandle();
    if (NULL != idle_handle)
    {
        task_mon_task_initialized(TASK_ID_IDLE);
        task_mon_set_task_policy(TASK_ID_IDLE, TASK_MON_POLICY_DONT_CARE);
        task_mon_register_for_stats(TASK_ID_IDLE, idle_handle);
    }

    while (true)
    {
        osDelay(task_mon_stat_config.period);
        task_mon_stat_sampling();

        task_mon_stat_do_log();
    }
}

static inline bool task_mon_stat_is_task_enabled(task_mon_id_t task)
{
    return ((task < TASK_ID_MAX) && (true == task_mon_check_init(task)) && (NULL != task_mon_stat[task].task_handle) && (true == task_mon_stat[task].enabled));
}

static void task_mon_stat_sampling(void)
{
    if (false == task_mon_stat_config.enabled)
    {
        return;
    }
    task_mon_stat_config.last_update = get_runtime_counter_value();
    task_mon_stat_config.free_heap   = xPortGetFreeHeapSize();

    task_stat_t *p_stat = &task_mon_stat[TASK_ID_IDLE];
    if (true == task_mon_stat_is_task_enabled(TASK_ID_IDLE))
    {
        p_stat->runtime            = xTaskGetIdleRunTimeCounter();
        p_stat->stack_unused_bytes = (uint16_t)-1;
    }

    for (uint8_t task = TASK_ID_IDLE + 1; task < TASK_ID_MAX; task++)
    {
        if (true == task_mon_stat_is_task_enabled(task))
        {
            p_stat = &task_mon_stat[task];
            TaskStatus_t task_status;
            vTaskGetInfo(p_stat->task_handle, &task_status, pdFALSE, eReady); // if eState is not eInvalid, the state value in task_status is not updated which saves time.
            p_stat->runtime            = task_status.ulRunTimeCounter;
            p_stat->stack_unused_bytes = task_mon_get_free_stack(task);
        }
    }
}

static const rlf_cfg_t rlf_stat_cfg = {
    .marker_active   = 'o',
    .marker_inactive = 'x',
    .max_count       = 10,
    .max_size        = (1 << 20), // 1MB
    .pattern         = "task_stats.__.log",
    .pos_index       = 12,
    .pos_marker      = 11,
};

static fm_file_obj_t stat_log_file_obj = { 0 };

static rlf_ctx_t rlf_stat_ctx = {
    .p_cfg                    = &rlf_stat_cfg,
    .current_index            = 0,
    .filename                 = "",
    .handle                   = &stat_log_file_obj,
    .is_open                  = false,
    .use_internal_file_object = false,
};

static void task_mon_stat_log_loop(void)
{
    char                buffer[TASK_STAT_LOG_BUFFER];
    static const size_t max_sprintf_per_task  = 3 + 3 + 10 + 5; // 3 delimiters (,,:), task is 1 byte (up to 3 chars), runtime is uint32_t (up to 10 chars), stack_unused_bytes is uint16_t (up to 5 chars)
    size_t              unflushed_bytes_count = 0;
    fm_result_t         fm_res                = FM_RES_OK;

    unflushed_bytes_count = (size_t)snprintf(buffer, sizeof(buffer), "%lu,%lu", task_mon_stat_config.last_update, task_mon_stat_config.free_heap);

    for (uint8_t task = 0; task < TASK_ID_MAX; task++)
    {
        const task_stat_t *p_stat = &task_mon_stat[task];
        if ((true == task_mon_stat_is_task_enabled(task)) &&
            (true == p_stat->logging))
        {
            // format: :id1,runtime1,free_stack1:id2,...
            unflushed_bytes_count += (size_t)sprintf(buffer + unflushed_bytes_count, ":%hhu,%lu,%hu",
                                                     task,
                                                     p_stat->runtime,
                                                     p_stat->stack_unused_bytes);

            if (unflushed_bytes_count + max_sprintf_per_task > sizeof(buffer))
            {
                fm_res                = rlf_write(&rlf_stat_ctx, buffer, unflushed_bytes_count, NULL);
                unflushed_bytes_count = 0;
            }
        }
        if (FM_RES_OK != fm_res)
        {
            break;
        }
    }

    if ((FM_RES_OK == fm_res) &&
        (0 < unflushed_bytes_count))
    {
        fm_res = rlf_write(&rlf_stat_ctx, buffer, unflushed_bytes_count, NULL);
    }
    (void)rlf_write(&rlf_stat_ctx, "\n", 1, NULL);
    if (FM_RES_OK != fm_res)
    {
        ES_TRACE_WARN("Failed to write to task stats file, rlf_write() returned %d", fm_res);
    }
}

static void task_mon_stat_do_log(void)
{
    fm_result_t fm_res;
    if ((false == task_mon_stat_config.enabled) ||
        (false == task_mon_stat_config.logging))
    {
        return;
    }

    fm_res = rlf_open(&rlf_stat_ctx);
    if ((FM_RES_OK == fm_res) &&
        (true == rlf_stat_ctx.is_open))
    {
        task_mon_stat_log_loop();
        (void)rlf_close(&rlf_stat_ctx);
    }
    else
    {
        ES_TRACE_WARN("Failed to open task stats file, rlf_open() returned %d", fm_res);
    }
}

/*
*********************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/
void task_mon_stat_init(void)
{
    for (size_t i = 0; i < CDEF_ELEMENT_COUNT(task_mon_stat); i++)
    {
        task_mon_stat[i].enabled = false;
        task_mon_stat[i].logging = false;
    }
    task_mon_stat_handle = osThreadNew(task_mon_stat_task, NULL, &task_mon_stat_task_attr);
    CRIT_ASSERT(task_mon_stat_handle);
}

task_mon_stat_config_t task_mon_stat_get_configuration(void)
{
    return task_mon_stat_config;
}

bool task_mon_stat_set_configuration(uint8_t flags, bool enabled, bool logging, UBaseType_t priority, uint32_t period, const char *id_table_file)
{
    bool                   ret = true;
    task_mon_stat_config_t temp;

    if (0 == flags)
    {
        return true;
    }

    if (0 != (flags & TASK_STAT_UPDATE_DEFAULT))
    {
        memcpy(&temp, &task_mon_stat_config_default, sizeof(task_mon_stat_config_t));
    }
    else
    {
        memcpy(&temp, &task_mon_stat_config, sizeof(task_mon_stat_config_t));
    }

    if (0 != (flags & TASK_STAT_UPDATE_ENABLE))
    {
        temp.enabled = enabled;
    }

    if (0 != (flags & TASK_STAT_UPDATE_LOGGING))
    {
        temp.logging = logging;
    }

    if (0 != (flags & TASK_STAT_UPDATE_PRIORITY))
    {
        if ((0 < temp.priority) &&
            (temp.priority < 56))
        {
            temp.priority = priority;
        }
        else
        {
            ret = false;
        }
    }

    if (0 != (flags & TASK_STAT_UPDATE_PERIOD))
    {
        temp.period = period;
    }

    if (0 != (flags & TASK_STAT_UPDATE_ID_TABLE))
    {
        ret = task_mon_stat_update_id_table_file(id_table_file);
        if (true == ret)
        {
            // no need to check for too long id_table_file, file manager does that for us in  task_mon_stat_update_id_table_file
            strcpy(temp.id_table_file, id_table_file);
        }
        else
        {
            ret = false;
        }
    }

    if (true == ret)
    {
        if ((0 != (flags & TASK_STAT_UPDATE_ID_TABLE)) &&
            (0 != strncmp(task_mon_stat_config.id_table_file, temp.id_table_file, sizeof(task_mon_stat_config.id_table_file))))
        {
            fm_delete(task_mon_stat_config.id_table_file);
        }
        if (0 != (flags & TASK_STAT_UPDATE_PRIORITY))
        {
            vTaskPrioritySet(task_mon_stat_handle, task_mon_stat_config.priority);
        }

        temp.free_heap = task_mon_stat_config.free_heap;
        temp.last_update = task_mon_stat_config.last_update;
        memcpy(&task_mon_stat_config, &temp, sizeof(task_mon_stat_config));

        task_stat_config_nvm_t nvm_data;
        nvm_data.enabled = task_mon_stat_config.enabled;
        nvm_data.logging = task_mon_stat_config.logging;
        nvm_data.priority = task_mon_stat_config.priority;
        nvm_data.period = task_mon_stat_config.period;
        strncpy(nvm_data.id_table_file, task_mon_stat_config.id_table_file, sizeof(nvm_data.id_table_file) - 1);
        nvm_data.id_table_file[sizeof(nvm_data.id_table_file) - 1] = '\0';
        Nvm_SetBlockById(NVM_BLOCK_TASK_STATS_CONFIG, &nvm_data, sizeof(nvm_data));

    }
    return ret;
}

task_stat_t task_mon_stat_get_configuration_per_id(uint8_t id)
{
    task_stat_t ret = { 0 };
    if (id < TASK_ID_MAX)
    {
        ret = task_mon_stat[id];
    }
    return ret;
}

bool task_mon_stat_set_configuration_per_id(uint8_t id, bool enabled, bool logging)
{
    bool ret = true;
    if (id < TASK_ID_MAX)
    {
        task_mon_stat[id].enabled = enabled;
        task_mon_stat[id].logging = logging;

        task_stat_config_specific_nvm_t nvm_data;
        nvm_data.enabled[id] = enabled;
        nvm_data.logging[id] = logging;
        Nvm_SetBlockById(NVM_BLOCK_TASK_STATS_CONFIG, &nvm_data, sizeof(nvm_data));
    }
    else
    {
        ret = false;
    }
    return ret;
}
