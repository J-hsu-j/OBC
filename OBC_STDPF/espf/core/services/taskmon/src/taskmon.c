/*
 * Copyright (c) 2020-2024 EnduroSat AD. All rights reserved.
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

#include "taskmon.h" /* Include own header file */
#include "taskmon_stat.h"
#include "es_exeh.h"
#include "trace.h"
#include "timer.h"
#include "drv_iwdg.h"
#include "arm_fault_handler.h"
#include "assertions.h"
#include <assert.h>

#define timer_is_running(timer_hnd) IS_TRUE((timer_hnd).is_running)

/*
*********************************************************************************************
* INTERNAL DEFINES
*********************************************************************************************
*/
/* Period in ms at witch the watchdog timer will be refreshed: see hwwdg.Init.Window 7ms min, 10 is with 50% reserve */
#define TASK_MONITOR_REFRESH_WDG_PERIOD (100)

// WD periodic activity check timeout in milliseconds
#define TASK_MONITOR_TASK_CHECK_PERIOD_MS (10U * 60U * 1000U) // 10 min

/** @brief Time interval (in ms) for reporting free RTOS heap size to the trace console */
#define HEAP_FREE_TRACE_INTERVAL_MS (60000)

#define TASK_MONITOR_LOW_MEMORY_STACK_PER_TASK (50)
#define TASK_MONITOR_LOW_MEMORY_TOTAL_HEAP     (1024)

#define EXEH_CURRENT_MODULE_ID (eEXEHModuleID_TASK_MONITOR)

/*
*********************************************************************************************
* INTERNAL TYPES DEFINITION
*********************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

// Used instead of a bool to increase the Hamming distance between the Inactive and Active state
// Therefore unexpected bit-flips could not easily go from Inactive to Active state and trigger
// a reset
typedef enum
{
    COUNTDOWN_INACTIVE = 0,
    COUNTDOWN_ACTIVE   = 0xFF
} reset_countdown_activation_flag_t;

typedef struct
{
    uint32_t                          ms_until_reset;
    reset_countdown_activation_flag_t delayed_reset_countdown_active;
} delayed_reset_ctx_t;

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
static uint8_t  task_mon_run_counter[TASK_ID_MAX];
static uint8_t  task_mon_init_complete[TASK_ID_MAX];
static uint16_t task_mon_unused_stack_size[TASK_ID_MAX];
static uint8_t  task_mon_policy_list[TASK_ID_MAX];

static delayed_reset_ctx_t delayed_reset_data = {
    .ms_until_reset                 = 0U,
    .delayed_reset_countdown_active = COUNTDOWN_INACTIVE
};

static osThreadId_t         task_mon_handle;
static const osThreadAttr_t task_mon_attributes = {
    .name       = "task_mon_task",
    .priority   = (osPriority_t)osPriorityRealtime,
    .stack_size = 1000,
};

/** @brief Periodic timer used to trigger task activity checks at runtime.
 */
static timer_handle_t wd_periodic_check_timer_hnd;

/** @brief Periodic timer used to trigger heap free bytes trace */
static timer_handle_t heap_check_timer;

/** @brief Total size of the allocated RTOS heap */
static uint32_t os_heap_size = 0U;

/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
*********************************************************************************************
*/
static task_mon_id_t            task_mon_check_tasks(void);
static void                     task_mon_manage_delayed_reset(const uint32_t ms_since_last_call);
static inline const char *const task_mon_get_reset_type_desc(const task_mon_reset_t reset_type);

/*
*********************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/

void task_mon_init(void)
{
    os_heap_size = freertos_user_get_heap_size();

    delayed_reset_data.delayed_reset_countdown_active = COUNTDOWN_INACTIVE;
    delayed_reset_data.ms_until_reset                 = 0U;

    for (uint8_t i = 0; i < TASK_ID_MAX; i++)
    {
        task_mon_run_counter[i]       = 0;
        task_mon_init_complete[i]     = 0;
        task_mon_policy_list[i]       = TASK_MON_POLICY_MONITOR;
        task_mon_unused_stack_size[i] = -1;
    }

#ifdef ES_TASK_STATS_ENABLED
    task_mon_stat_init();
#endif

#if (defined(DEBUG_ENABLED) && defined(DEBUG_MODE_WD_ENABLED)) || !defined(DEBUG_ENABLED)
    task_mon_handle = osThreadNew(task_mon_task, NULL, &task_mon_attributes);
    CRIT_ASSERT(task_mon_handle);
    task_mon_register_for_stats(TASK_ID_MONITOR, task_mon_handle);
#endif

    timer_stop(&wd_periodic_check_timer_hnd);
    timer_stop(&heap_check_timer);

    EXEH_INIT_MODULE_FILENAME();
}

void task_mon_task(void *argument)
{
    timer_start(&wd_periodic_check_timer_hnd);
    timer_start(&heap_check_timer);
    task_mon_task_initialized(TASK_ID_MONITOR);

    while (true)
    {
        osDelay(TASK_MONITOR_REFRESH_WDG_PERIOD);
        task_mon_manage_delayed_reset(TASK_MONITOR_REFRESH_WDG_PERIOD);

        if (timer_is_elapsed(&wd_periodic_check_timer_hnd, TASK_MONITOR_TASK_CHECK_PERIOD_MS))
        {
            volatile task_mon_id_t last_task_checked = task_mon_check_tasks();

            // sanity check (if timer is not actually running, timer_is_elapsed() will return true right away;
            // this situation should not happen but if it does, we will not be checking task
            // activity because we may end up with a false positive where some tasks didn't have a
            // chance to report aliveness yet; therefore we just restart the timer hoping that next
            // time what caused it to stop, will not happen again
            if (timer_is_running(wd_periodic_check_timer_hnd))
            {
                if (last_task_checked == TASK_ID_MAX)
                {
                    drv_iwdg_refresh();

                    // restart timer
                    timer_start(&wd_periodic_check_timer_hnd);
                }
                else
                {
                    const char *const reset_type_descr = task_mon_get_reset_type_desc(TASK_MONITOR_TASK_TIMEOUT);
                    (void)reset_type_descr;

                    ES_TRACE_DEBUG("%s (task_id: %d)", reset_type_descr, last_task_checked);
                    task_mon_immediate_reset(TASK_MONITOR_TASK_TIMEOUT);
                }
            }

            // restart timer
            timer_start(&wd_periodic_check_timer_hnd);
        }
        else
        {
            drv_iwdg_refresh();
        }

        task_mon_i_am_alive(TASK_ID_MONITOR);
        task_mon_low_stack_check(TASK_ID_MONITOR);

#ifdef DEBUG_ENABLED
        task_mon_low_total_heap_check();
#endif
    }
}

void task_mon_i_am_alive(task_mon_id_t task)
{
    if (task < TASK_ID_MAX)
    {
        if (task_mon_run_counter[task] < 0xFE) /* Prevent from rolling over */
        {
            /* Set the task as alive (run one more time) */
            task_mon_run_counter[task]++;
        }
    }
}

void task_mon_set_task_policy(task_mon_id_t task, task_mon_policy_t policy)
{
    if (task < TASK_ID_MAX)
    {
        /* Set the new task policy */
        task_mon_policy_list[task] = policy;
    }
}

void task_mon_task_initialized(task_mon_id_t task)
{
    if (task < TASK_ID_MAX)
    {
        task_mon_init_complete[task] = 1;
    }
}

uint8_t task_mon_check_task_init(void)
{
    uint8_t i;
    uint8_t retval = 1; /* assume all task has passed at least once */

    for (i = 0; i < TASK_ID_MAX; i++)
    {
        if (task_mon_init_complete[i] == 0)
        {
            /* One task is not alive */
            retval = 0;
            break;
        }
    }

    return retval;
}

bool task_mon_check_init(task_mon_id_t task)
{
    if (task < TASK_ID_MAX)
    {
        return (0 == task_mon_init_complete[task]) ? false : true;
    }
    return false;
}

uint16_t task_mon_get_free_stack(task_mon_id_t task)
{
    if (task < TASK_ID_MAX)
    {
        return task_mon_unused_stack_size[task];
    }
    return (uint16_t)-1;
}

void task_mon_immediate_reset(task_mon_reset_t reset_type)
{
    (void)reset_type;

    arm_fault_handler_bkpt_if_debug();

    NVIC_SystemReset();
}

void task_mon_low_stack_check(task_mon_id_t taskNumber)
{
    // uxTaskGetStackHighWaterMark returns words, we want bytes (1 word = 4 bytes)
    UBaseType_t uxHighWaterMark_bytes = uxTaskGetStackHighWaterMark(NULL) * 4;

    if (task_mon_unused_stack_size[taskNumber] > (uint16_t)uxHighWaterMark_bytes)
    {
        task_mon_unused_stack_size[taskNumber] = (uint16_t)uxHighWaterMark_bytes;
    }

    if (task_mon_unused_stack_size[taskNumber] < 2 * TASK_MONITOR_LOW_MEMORY_STACK_PER_TASK)
    {
        EXEH_HANDLE(eEXEHSeverity_Warning, eEXEH_TASK_MONITOR_TASK_STACK_WARN | ((uint32_t)taskNumber << 24U));
    }

    // Minimum stack size over the needed
    if (task_mon_unused_stack_size[taskNumber] < TASK_MONITOR_LOW_MEMORY_STACK_PER_TASK)
    {
        ES_TRACE_WARN("Remaining stack for task id '%d' is critically low => %lu byte(s)", taskNumber, task_mon_unused_stack_size[taskNumber]);
    }
}

void task_mon_low_total_heap_check(void)
{
    size_t free_heap = xPortGetFreeHeapSize();

    if (timer_is_elapsed(&heap_check_timer, HEAP_FREE_TRACE_INTERVAL_MS))
    {
        ES_TRACE_DEBUG("RTOS heap [free: %lu (%0.2f%%), total: %lu] (bytes)", free_heap, (float)free_heap * 100. / os_heap_size, os_heap_size);
        timer_start(&heap_check_timer);
    }

    BREAK_ASSERT(free_heap >= TASK_MONITOR_LOW_MEMORY_TOTAL_HEAP);
    CRIT_ASSERT(free_heap != 0);
}

void task_mon_trigger_delayed_reset(const uint32_t u32WaitMs)
{
    // order is important since this information is used in the task_mon_task() and
    // the bDelayedResetCountdownActive flag could be checked before setting the ms_until_reset
    // value causing an immediate reset - no protection is needed here since bDelayedResetCountdownActive
    // is read atomically
    delayed_reset_data.ms_until_reset                 = u32WaitMs;
    delayed_reset_data.delayed_reset_countdown_active = COUNTDOWN_ACTIVE;
}

/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/

/**
 * @brief Check if all task are still running, but not stuck
 * @retval 1: All tasks are alive
 * @retval 0: At least one frozen task has been found
 */
static task_mon_id_t task_mon_check_tasks(void)
{
    task_mon_id_t i;
    task_mon_id_t last_task_checked = TASK_ID_MAX; /* assume all task has passed at least once */

    for (i = 0; i < TASK_ID_MAX; i++)
    {
        if (task_mon_policy_list[i] == TASK_MON_POLICY_MONITOR)
        {
            if (task_mon_run_counter[i] == 0)
            {
                // report task which was not alive
                last_task_checked = i;
                break;
            }
            else
            {
                task_mon_run_counter[i] = 0;
            }
        }
    }

    return last_task_checked;
}

/**
 * @brief Manage the delayed reset mechanism
 * @param ms_since_last_call: milliseconds passed since last call of this function
 *                            in the main task
 */
static void task_mon_manage_delayed_reset(const uint32_t ms_since_last_call)
{
    if (delayed_reset_data.delayed_reset_countdown_active == COUNTDOWN_ACTIVE)
    {
        if (delayed_reset_data.ms_until_reset >= ms_since_last_call)
        {
            delayed_reset_data.ms_until_reset -= ms_since_last_call;
        }
        else
        {
            task_mon_immediate_reset(TASK_MONITOR_USER_DELAYED_RESET);
        }
    }
}
/* **************************************************************************************** */

static inline const char *const task_mon_get_reset_type_desc(const task_mon_reset_t reset_type)
{
    static const char *reset_types_description[TASK_MONITOR_RESET_NUMBER] = {
        "SW_RESET",
        "FAULT_RESET",
        "USER_DELAYED_RESET",
        "TASK_TIMEOUT"
    };

    if (reset_type < TASK_MONITOR_RESET_NUMBER)
    {
        return reset_types_description[(uint8_t)reset_type];
    }
    else
    {
        return "UNKNOWN";
    }
}

#ifdef DEBUG_ENABLED
//
// linker imports
//
extern uint32_t lnk_user_main_stack_size_bytes; // allocates user stack size
extern uint32_t lnk_user_main_stack_start_addr; // stack start address
extern uint32_t _estack;                        // highest address of user stack

#define USER_STACK_PATTERN    (0x52)
#define USER_STACK_SIZE       ((uint32_t) & lnk_user_main_stack_size_bytes)
#define USER_STACK_TOP_ADDR   ((uint8_t *)&_estack)
#define USER_STACK_START_ADDR ((uint8_t *)&lnk_user_main_stack_start_addr)
#define MIN_FREE_SIZE_STACK   (50)

/** @brief Initializes the main stack buffer with a special value so that the stack growth can be
 *         measured upon startup.
 *
 *  @note The function initializes only the main stack region defined in the linker. RTOS task stacks are
 *        monitored by the RTOS itself.
 *
 *  @warning This function shall be the first to be called in main() so that main stack usage can be
 *           measured. If you call this from a function which must return, the stack will be corrupted!
 */
void task_mon_ram_test_stack_fill(void)
{
    // memset() not used because this function will be called by the assembly startup code before initializing the C runtime
    for (uint8_t *p_stack_mem_index = USER_STACK_START_ADDR; p_stack_mem_index < USER_STACK_TOP_ADDR; p_stack_mem_index++)
    {
        *p_stack_mem_index = USER_STACK_PATTERN;
    }
}

void task_mon_ram_test_stack_usage_check(void)
{
    const uint8_t *p_stack_mem_index;

    for (p_stack_mem_index = USER_STACK_START_ADDR; p_stack_mem_index < USER_STACK_TOP_ADDR; p_stack_mem_index++)
    {
        if (USER_STACK_PATTERN != *p_stack_mem_index)
        {
            break;
        }
    }

    volatile uint32_t free_stack_bytes = (uint32_t)p_stack_mem_index - (uint32_t)USER_STACK_START_ADDR;

    ES_TRACE_DEBUG("main stack [free: %lu (%0.2f%%)/total: %lu] (bytes)", free_stack_bytes, (float)free_stack_bytes * 100. / USER_STACK_SIZE, USER_STACK_SIZE);

    ES_CDEF_UNUSED(free_stack_bytes);

    BREAK_ASSERT(free_stack_bytes >= MIN_FREE_SIZE_STACK);
    CRIT_ASSERT(0 != free_stack_bytes);
}
#endif
