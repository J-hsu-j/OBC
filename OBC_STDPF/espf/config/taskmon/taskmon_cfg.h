/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef TASKMONITOR_CFG_H
#define TASKMONITOR_CFG_H

/**
 * @addtogroup taskmon
 * @{
 *
 * @file    taskmon_cfg.h
 * @brief   Configuration Header for the Task Monitor service
 *
 * @}
 *
 */

/*
*********************************************************************************************
* EXTERNAL TYPES DECLARATIONS
*********************************************************************************************
*/

typedef enum
{
#define TASK_MON_ID_MACRO(id) id
#include "taskmon_id.inc"
#undef TASK_MON_ID_MACRO
    TASK_ID_MAX
} task_mon_id_t;

typedef enum
{
    TASK_MONITOR_SW_RESET,
    TASK_MONITOR_FAULT_RESET,
    TASK_MONITOR_USER_DELAYED_RESET,
    TASK_MONITOR_TASK_TIMEOUT,
    TASK_MONITOR_RESET_NUMBER
} task_mon_reset_t;

typedef enum
{
    TASK_MON_POLICY_MONITOR,   // task monitoring is active as soon as task initializes
    TASK_MON_POLICY_DONT_CARE, // task monitoring skips this task because it doesn't expect it to be operational
    TASK_MON_POLICY_MAX
} task_mon_policy_t;

#endif /* TASKMONITOR_CFG_H */
