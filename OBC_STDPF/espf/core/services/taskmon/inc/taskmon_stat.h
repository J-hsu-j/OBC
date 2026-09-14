/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef TASK_MON_STAT_H
#define TASK_MON_STAT_H

/**
 * @addtogroup taskmon
 * @{
 *
 * @file    task_mon_stat.h
 * @brief   Samples and logs task statistics.
 *
 * @}
 *
 */

#include "taskmon_cfg.h"
#include "cmsis_os.h"
#include "fm_def.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef ES_TASK_STATS_ENABLED

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/

/**
 * @brief Bit flags for updating the task statistics configuration.
 */
#define TASK_STAT_UPDATE_ENABLE     (0x01) /** @brief: Update only the enable parameter */
#define TASK_STAT_UPDATE_LOGGING    (0x02) /** @brief: Update only the logging parameter */
#define TASK_STAT_UPDATE_PRIORITY   (0x04) /** @brief: Update only the priority parameter */
#define TASK_STAT_UPDATE_PERIOD     (0x08) /** @brief: Update only the period parameter */
#define TASK_STAT_UPDATE_ID_TABLE   (0x10) /** @brief: Update only the id table file name parameter */
#define TASK_STAT_UPDATE_DEFAULT    (0x80) /** @brief: Set the default values to the configuration, then update the other parameters, if any */

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/**
 * @brief The general task statistics configuration.
*/
typedef struct
{
    bool            enabled; /**< General enable for all statistics. */
    bool            logging; /**< General logging enable for all statistics */
    UBaseType_t     priority; /**< Set the priority of the statistics task. May be 1-55, recommended default is 8(Low Priority) */
    uint32_t        period; /**< The period for sampling in milliseconds. Default is 1000 ms (ie 1 second). */
    char            id_table_file[FM_MAX_PATH]; /**< The file name for the task id table. */
    uint32_t        last_update; /**< The timer value at the last sampling */
    uint32_t        free_heap; /**< The available heap not allocated to tasks (free stack of tasks is not included in this value) */
} task_mon_stat_config_t;

/**
 * @brief The task statistics configuration and sampling per task id.
*/
typedef struct
{
    TaskHandle_t    task_handle; /**< The handle of the task in FreeRTOS */
    bool            enabled; /**< Whether sampling for this task is enabled */
    bool            logging; /**< Whether logging for this task is enabled */
    uint32_t        runtime; /**< The amounted runtime in the configured timer for this task. This value overflows, so usually diffs with consequitive values should be used as a measurement. */
    uint16_t        stack_unused_bytes; /**< The least amount of available bytes from the stack ever reached by this task since reset. */
} task_stat_t;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/
/* No External variables declarations */

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

/**
 * @brief Initialize the task statistics module.
*/
void task_mon_stat_init(void);

/**
 * @brief Get the current task statistics configuration.
 *
 * @return See @ref task_mon_stat_config_t.
*/
task_mon_stat_config_t task_mon_stat_get_configuration(void);

/**
 * @brief Set the task statistics configuration. See @ref task_mon_stat_config_t.
 *
 * @param[in] flags The flags for updating the configuration. See @ref TASK_STAT_UPDATE_ENABLE and the other constants for the flags parameter.
 * @param[in] enabled The general enable for all statistics. Applied only if flags has @ref TASK_STAT_UPDATE_ENABLE.
 * @param[in] logging The general logging enable for all statistics. Applied only if flags has @ref TASK_STAT_UPDATE_LOGGING.
 * @param[in] priority The priority for the statistics task. Applied only if flags has @ref TASK_STAT_UPDATE_PRIORITY.
 * @param[in] period The period for sampling in milliseconds. Applied only if flags has @ref TASK_STAT_UPDATE_PERIOD.
 * @param[in] id_table_file The file name for the task id table. Applied only if flags has @ref TASK_STAT_UPDATE_ID_TABLE. If applied the file will be refilled with the current task name=ids.
 *
 * @retval true The configuration was successfully updated.
 * @retval false The configuration was not updated. This may be due to invalid parameter values or file access.
*/
bool task_mon_stat_set_configuration(uint8_t flags, bool enabled, bool logging, UBaseType_t priority, uint32_t period, const char* id_table_file);

/**
 * @brief Get the task statistics configuration per task id.
 *
 * @param[in] id The task id to get the configuration for.
 *
 * @return See @ref task_stat_t.
*/
task_stat_t task_mon_stat_get_configuration_per_id(uint8_t id);

/**
 * @brief Set the task statistics configuration per task id. See @ref task_stat_t.
 *
 * @param[in] id The task id to set the configuration for.
 * @param[in] enabled Whether sampling for this task is enabled.
 * @param[in] logging Whether logging for this task is enabled.
 *
 * @retval true The configuration was successfully updated.
 * @retval false The configuration was not updated. This is due to invalid id.
*/
bool task_mon_stat_set_configuration_per_id(uint8_t id, bool enabled, bool logging);

/**
 * @brief Register a task for statistics.
 *
 * @param[in] task The task id to register. See @ref task_mon_id_t.
 * @param[in] handle The handle of the task in FreeRTOS. If NULL, it is considered an "unregistration".
 *
*/
void task_mon_register_for_stats(task_mon_id_t task, TaskHandle_t handle);

#else

/**
 * @brief Register a task for statistics.
 *
 * @param[in] task The task id to register. See @ref task_mon_id_t.
 * @param[in] handle The handle of the task in FreeRTOS. If NULL, it is considered an "unregistration".
 *
*/
inline void task_mon_register_for_stats(task_mon_id_t task, TaskHandle_t handle){}

#endif /* ES_TASK_STATS_ENABLED */

#ifdef __cplusplus
}
#endif

#endif /* TASK_MON_STAT_H */
