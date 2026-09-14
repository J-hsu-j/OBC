/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup onboard_sched
 * @{
 *
 * @file     onboard_sched_scripting.h
 * @brief    Internal interface to the execution logic for MicroPython scripts
 *
 * @}
 *
 */

#ifndef ONBOARD_SCHED_SCRIPTING_H
#define ONBOARD_SCHED_SCRIPTING_H

#ifdef MICROPYTHON_SERVICE_ENABLED

#include <stdatomic.h>
#include "upy.h"
#include "es_cdef.h"

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

/** @brief Declaration used in the inline getter. */
extern atomic_bool g_onboard_sched_scripting_script_running;

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

/**
 * @brief Requests script execution from the script execution service
 * @param p_buf[in]: Reference to the schedule entry bytes.
 *
 */
void onboard_sched_scripting_execute_script(const uint8_t *const p_buf);

/**
 * @brief Retrieves the status of script execution.
 *
 * @retval true:  A scheduled script is being executed.
 * @retval false: No script is being executed
 *
 */
inline bool onboard_sched_scripting_get_runnning(void)
{
    return atomic_load(&g_onboard_sched_scripting_script_running);
}

#endif /* MICROPYTHON_SERVICE_ENABLED */

#endif /* ONBOARD_SCHED_SCRIPTING_H */
