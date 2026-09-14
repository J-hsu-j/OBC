/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef TASKMONITOR_H
#define TASKMONITOR_H

/**
 * @addtogroup Services
 * @{
 *
 * @defgroup taskmon Task Monitor
 * @{
 *
 * The module takes care of the following task supervision activities:
 *  - Periodic monitoring of the tasks
 *  - Task stack size monitoring
 *  - Heap size monitoring
 * Problematic situations detected by Task Monitor service (such as stack and heap usage under a certain
 *  predefined limit or lack of activity reporting from a supervised task) do lead to an immediate system
 *  reset in an attempt to recover normal operation of the system.
 *
 *  ### Example of use
 *  1. Extend the `task_mon_id_t` enumerator with your new task
 *  ```C
 *     typedef enum {
 *         // ...
 *         TASK_CRITICAL_TASK_FOO
 *         // ...
 *         TASK_ID_MAX
 *     } task_mon_id_t;
 *  ```
 *  2. Instrument your task function to report certain events to Task Monitor
 *  ```C
 *  #include "taskmon.h"
 *
 *  static void critical_task_foo(void *argument)
 *  {
 *      task_mon_task_initialized(TASK_CRITICAL_TASK_FOO);
 *
 *      while (true)
 *      {
 *          // do your task processing here...
 *
 *          // signal task_mon that the task is still operational...
 *          task_mon_i_am_alive(TASK_CRITICAL_TASK_FOO);
 *
 *          // this call is optional but recommended to enable stack size limit checking in task_mon for your task
 *          task_mon_low_stack_check(TASK_CRITICAL_TASK_FOO);
 *      }
 *  }
 *  ```
 *
 * @file    taskmon.h
 * @brief   Header of taskmon.c
 *
 * @}
 * @}
 *
 */

#include "main.h"
#include "cmsis_os.h"
#include "taskmon_cfg.h"

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

/**
 * @brief Init routine for the task_mon component
 */
void task_mon_init(void);

/**
 * @brief Task routine of the Task monitor
 * @param argument: not used
 */
void task_mon_task(void * argument);

/**
 * @brief Calling that function from all task listed in task_mon_id_t will prevent from watchdog reset
 * @param task: the number of the task according to the task_mon_id_t
 */
void task_mon_i_am_alive(task_mon_id_t task);

/**
 * @brief Set flag that the current task is initialised and ready
 * @param task: the number of the task according to the task_mon_id_t
 */
void task_mon_task_initialized(task_mon_id_t task);

/**
 * @brief Called from the if_sys_mod to start or stop monitoring a task
 * @param task: the number of the task according to the task_mon_id_t
 * @param policy: the new task_mon_policy_t to apply
 */
void task_mon_set_task_policy(task_mon_id_t task, task_mon_policy_t policy);

/**
 * @brief Check if all tasks are initialised
 * @retval 1: all task are ready
 * @retval 0: at least one task is not ready
 */
uint8_t task_mon_check_task_init(void);

/**
 * @brief Check if a task is initialized.
 * @param[in] task Id of the task.
 * @retval true: task is initialized.
 * @retval false: task is not initialized or invalid id.
 */
bool task_mon_check_init(task_mon_id_t task);

/**
 * @brief Get the lowest free stack reached by a task
 * @param[in] task Id of the task.
 * @return Amount of minimum free stack reached in bytes
 * @retval 0xFFFF: task is not initialized or invalid id.
 */
uint16_t task_mon_get_free_stack(task_mon_id_t task);

/**
 * @brief Calling that function causes immediate reset
 * @param reset_type:
 *                  - TASK_MONITOR_SW_RESET: Software reset
 *                  - TASK_MONITOR_WD_RESET: Watchdog reset
 */
void task_mon_immediate_reset(task_mon_reset_t reset_type);

/**
 * @brief This function is called to check the unused stack for the task it is called from
 */
void task_mon_low_stack_check(task_mon_id_t task_number);

/**
 * @brief This function is called to check the unused total heap
 */
void task_mon_low_total_heap_check(void);

/**
 * @brief The function triggers a CPU reset after a specified number of milliseconds
 * @param wait_ms: milliseconds to wait before performing a reset
 */
void task_mon_trigger_delayed_reset(const uint32_t wait_ms);

#ifdef DEBUG_ENABLED
/**
 * @brief This function will fill up the memory (stack and heap) almost up to the limit. It can be
 *       used to force the reset and recovery of the OBC SDK
 *
 * @note: Only for debug purposes, it is not available in the release version of the SDK
 */
void task_mon_ram_test_stack_fill(void);

/**
 * @brief Verify that there is still memory available. If not, it calls Error_Handler()
 *
 * @note: Only for debug purposes, it is not available in the release version of the SDK
 */
void task_mon_ram_test_stack_usage_check(void);
#endif

#endif    /* TASKMONITOR_H */
