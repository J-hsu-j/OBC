/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup gnss
 * @{
 * @file gnss_logs.c
 * @brief gnss log module
 * @}
 */

#include "trace.h"
#include "gnss_logs.h"
#include "fdir_srv.h"
#include "gnss_cfg.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/
/** @brief internal generic gnss log structure */
typedef struct
{
    const uint8_t  *command;
    uint16_t        command_length;
    fdir_fault_id_t fdir_fault_code;
} gnss_log_t;

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
/** @brief internal gnss log array for all defined logs */
static gnss_log_t logs[GNSS_LOGS_CNT] = {
    { (const uint8_t *)GNSS_CMD_UNLOG_RXSTATUSEVENTA,
     GNSS_STATIC_STRLEN(GNSS_CMD_UNLOG_RXSTATUSEVENTA),
     FDIR_FAULT_GNSS_CMD_EXEC_FAILURE },
    { (const uint8_t *)GNSS_CMD_LOG_BESTXYZA,
     GNSS_STATIC_STRLEN(GNSS_CMD_LOG_BESTXYZA),
     FDIR_FAULT_GNSS_CMD_EXEC_FAILURE },
    { (const uint8_t *)GNSS_CMD_LOG_TIMEA,
     GNSS_STATIC_STRLEN(GNSS_CMD_LOG_TIMEA),
     FDIR_FAULT_GNSS_CMD_EXEC_FAILURE }
};

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
/**
 * @brief configure a single log
 * @param[in] log pointer to the log structure
 * @retval true log configuration succeeded
 * @retval false log configuration failed
 */
static bool configure_log(const gnss_log_t *log);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
bool configure_all_logs(void)
{
    bool success = true;

    for (uint8_t log = 0; log < sizeof(logs) / sizeof(logs[0]); log++)
    {
        success = success && configure_log(&logs[log]);

        osDelay(GNSS_AFTER_OP_WAIT_MS);
    }

    return success;
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
static bool configure_log(const gnss_log_t *log)
{
    bool result = gnss_uart_tx(log->command, log->command_length);

    if (!result)
    {
        fdir_srv_log_if_clear(log->fdir_fault_code, FDIR_AGENT_GNSS, "Failed UART TX: %s", log->command);
    }

    return result;
}
