/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef ONBOARD_SCHED_H
#define ONBOARD_SCHED_H

/**
 * @addtogroup Services
 * @{
 *
 * @defgroup onboard_sched Onboard Scheduler
 * @{
 * Onboard scheduling service. Provides execution of pre-loaded schedules. Schedules contain timestamped sequences of
 * entries which can be either direct commands to the comm_gw service or commands to invoke
 * MicroPython scripts.
 *
 * @file     onboard_sched.h
 * @brief    Onboard scheduling service interface
 *
 * @}
 * @}
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "FP_onboard_schedProtocolTypes.h"
#include "es_cdef.h"
#include "onboard_sched_cfg.h"

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
 * @brief Performs initialization activities for the onboard scheduling service.
 *
 * @retval true:  Initialization performed successfully and the service can be trusted
 * @retval false: Something went wrong with initialization of OS objects used by the service
 *                and the service may not be started or worse - it could be running with
 *                incorrect setup.
 */
bool onboard_sched_init(void);

/**
 * @brief Stores a request to change the current schedule file to a file from the SD card.
 *
 * @param p_path[in]: null-terminated path to the file containing the new schedule.
 *
 * @retval ONBOARD_SCHED_SCHEDLOADRESULT_SUCCESS: Request submitted successfully.
 * @retval ONBOARD_SCHED_SCHEDLOADRESULT_ERROR_SYSTEM: Errors related to OS objects
 *         have prevented the proper submission of the request.
 * @retval ONBOARD_SCHED_SCHEDLOADRESULT_ERROR_NO_FILE: File not found at the provided path.
 * @retval ONBOARD_SCHED_SCHEDLOADRESULT_ERROR_SCHED_RUNNING: Request is submitted while the
 *         scheduling service is running.
 *
 * @note The current schedule is not set immediately, only the file path is stored. Actual update
 *       occurs in the main task.
 */
ONBOARD_SCHED_SchedLoadResult_t onboard_sched_set_active_schedule(const char *const p_path);

/**
 * @brief Retrieves the name of the file containing the current active schedule.
 *
 * @param p_path[out]: Reference to a buffer where the name shall be stored.
 * @param max_size[in]: Size of the output buffer.
 * @param p_size[out]: Reference to a buffer where the actual length of the name shall be stored.
 *
 * @retval ONBOARD_SCHED_SCHEDLOADRESULT_SUCCESS: Schedule name read successfully.
 * @retval ONBOARD_SCHED_SCHEDLOADRESULT_ERROR_SYSTEM: Errors related to OS objects
 *         have prevented the proper reading of the name.
 * @retval ONBOARD_SCHED_SCHEDLOADRESULT_ERROR_NO_FILE: There is no active schedule.
 *
 * @note Only one file may be requested at a time. In case of multiple requests, each subsequent one
 *       will overwrite the previous.
 * @note In case there is no active schedule, the string "No active schedule" shall be returned in addition
 *       to the error status.
 */
ONBOARD_SCHED_SchedLoadResult_t onboard_sched_get_active_schedule(char *const p_path, const uint8_t max_size, uint8_t *const p_size);

/**
 * @brief Sets the global state of the onboard scheduling service.
 *
 * @param state[in]: Target state to be set.
 *
 * @note State change is immediate.
 */
void onboard_sched_set_state(const ONBOARD_SCHED_SchedState_t state);

/**
 * @brief Gets the global state of the onboard scheduling service.
 *
 * @return See values of @ref ONBOARD_SCHED_SchedState_t
 *
 */
ONBOARD_SCHED_SchedState_t onboard_sched_get_state(void);

/**
 * @brief Gets the slot offset of the next entry to be released.
 *
 * @return Offset from the beginning of the schedule file.
 *
 */
uint32_t onboard_sched_get_next_slot(void);

#ifdef __cplusplus
}
#endif

#endif /* ONBOARD_SCHED_H */
