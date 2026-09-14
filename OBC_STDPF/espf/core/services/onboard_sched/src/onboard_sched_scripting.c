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
 * @file     onboard_sched_scripting.c
 * @brief    Implementation of the execution logic for MicroPython scripts
 *
 * @}
 *
 */

#include <string.h>
#include "onboard_sched_scripting.h"
#include "onboard_sched_logging.h"
#include "assertions.h"
#include "trace.h"

#ifdef MICROPYTHON_SERVICE_ENABLED

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/

/** @brief Flag indicating whether a script execution has started. */
atomic_bool g_onboard_sched_scripting_script_running = ATOMIC_VAR_INIT(false);

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/

INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/

/**
 * @brief Callback invoked by the script execution service on finished execution.
 *
 * @param result[in]: Result of the script's execution.
 * @param duration_in_ms[in]: Time it took the script service to complete execution.
 * @param script_id[in]: ID of the script that has finished its execution.
 *
 */
static void onboard_sched_scripting_finished_callback(eObcPortResult_t result, const uint32_t duration_in_ms, const uint8_t script_id);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

void onboard_sched_scripting_execute_script(const uint8_t *const p_buf)
{
    if (NULL != p_buf)
    {
        const uint8_t          name_end = (uint8_t)strnlen((const char *const)p_buf, (size_t)SCHED_MAX_NAME_LEN);
        const uint32_t         timeout  = *(const uint32_t *)(&p_buf[name_end + 1]);
        uint8_t                script_id;
        const eObcPortResult_t res = upy_req_script_execution((const char *const)p_buf, name_end, timeout,
                                                              onboard_sched_scripting_finished_callback, &script_id);
        if (UPY_OK == res)
        {
            g_onboard_sched_scripting_script_running = true;
        }
        uint8_t *const             p_out_buf  = onboard_sched_logging_get_build_buf_current();
        sched_entry_payload_size_t out_offset = 0;

        // Set script name in output buffer
        memcpy(p_out_buf, p_buf, name_end);
        out_offset += name_end;
        p_out_buf[out_offset++] = STRING_TERMINATOR;

        script_result_started_t *const p_out_data = (script_result_started_t *const)&p_out_buf[out_offset];
        // Set execution timeout
        p_out_data->timeout = timeout;

        // Set script ID
        p_out_data->common.script_id = script_id;

        // Set execution result
        p_out_data->common.script_result = res;

        out_offset += sizeof(timeout) + sizeof(script_id) + sizeof(res);

        onboard_sched_logging_inc_build_index(out_offset);

        ES_TRACE_DEBUG(", SCRIPT, script_name=%s, res=%d\n", p_buf, res);
    }
    else
    {
        BREAK_ASSERT(false);
    }
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

static void onboard_sched_scripting_finished_callback(eObcPortResult_t result, const uint32_t duration_in_ms, const uint8_t script_id)
{
    sScriptData_t script_data;

    eObcPortResult_t res = upy_get_script_status(script_id, &script_data);
    // update the status if the element is still in the status array
    if (UPY_OK == res)
    {
        script_data.eScriptStatus   = result;
        script_data.u32DurationInMs = duration_in_ms;

        (void)upy_set_script_status(script_id, &script_data);
    }

    TODO(Remove everything before this line when upy is fixed)

    // Log script execution finished
    onboard_sched_logging_start_log();

    script_result_res_t *const p_out_data = (script_result_res_t *const)onboard_sched_logging_get_build_buf_current();
    // Set script ID in the output buffer
    p_out_data->common.script_id = script_id;

    // Set execution result
    p_out_data->common.script_result = result;

    // Set execution duration
    p_out_data->duration = duration_in_ms;

    const sched_entry_payload_size_t write_idx = sizeof(script_id) + sizeof(result) + sizeof(duration_in_ms);
    onboard_sched_logging_inc_build_index(write_idx);

    onboard_sched_logging_end_log(SCRIPT_RESULT);

    g_onboard_sched_scripting_script_running = false;
}

#endif /* MICROPYTHON_SERVICE_ENABLED */
