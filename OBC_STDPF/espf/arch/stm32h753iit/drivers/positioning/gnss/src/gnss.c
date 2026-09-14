/**
 * Copyright (c) 2020-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup Drivers
 * @{
 * @defgroup gnss
 * @{
 * GNSS Receiver communication interface
 *
 * @file gnss.c
 * @brief GNSS driver
 * @}
 * @}
 */

#include "es_cdef.h"
#include "gnss.h"
#include "gnss_cfg.h"
#include "gnss_critical.h"
#include "gnss_cmd.h"
#include "gnss_resp.h"
#include "gnss_logs.h"
#include "FP_gnssProtocolTypes.h"
#include "gnss_uart.h"
#include "gnss_power.h"
#include "timer.h"
#include "cmsis_os2.h"
#include "taskmon.h"
#include "trace.h"
#include "assertions.h"
#include <string.h>
#include "taskmon_stat.h"
#include "datacache.h"
#include "fdir_srv.h"
#include "pps.h"

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

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/
/**
 * @brief GNSS module configuration
 */
if_sys_mod_t gnss_module_configuration = {
    .init   = gnss_init,
    .run    = gnss_run,
    .stop   = gnss_stop,
    .deinit = gnss_deinit,
};

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
/** @brief used for reading raw messages from the low level driver */
static gnss_uart_resp_t gnss_raw_resp = { 0 };

/** @brief init task handle */
static osThreadId_t h_init_task = NULL;

/** @brief response task handle */
static osThreadId_t h_resp_task = NULL;

/** @brief software timer used to mark the time since last successfully received bestxyz log */
static timer_handle_t h_bestxyz_tim;

/** @brief software timer used to mark the time since last successfully received time log */
static timer_handle_t h_time_tim;

/** @brief flag used to keep track of whether the user has instructed us to remain powered off */
static bool external_stop = false;

/** @brief flag used to prevent consecutive power on */
static bool already_on = false;

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
static mod_op_status_id_t start(const bool external_req);
static mod_op_status_id_t stop(const bool external_req);
static void               init_task(void *args);
static void               resp_task(void *args);
static inline void        reset_data_buffers(void);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
/** @brief PV log callback - must be implemented by the user */
extern void gnss_cfg_pv_callback(const gnss_xyz_t *pv);

/** @brief TIME log callback - must be implemented by the user */
extern void gnss_cfg_tm_callback(const gnss_time_t *t);

/** @brief gnss user command response callback - must be implemented by the user */
extern void gnss_user_cmd_resp_cbk(void);

mod_op_status_id_t gnss_init(sys_init_level_id_t level)
{
    mod_op_status_id_t ret = STATUS_NOT_SUPPORTED;

    if (INIT_OS == level)
    {
        ret = STATUS_OK;

        if (NULL == h_init_task)
        {
            osThreadAttr_t attr = {
                .attr_bits  = osThreadDetached,
                .name       = "gnss_init",
                .priority   = osPriorityNormal,
                .cb_mem     = NULL,
                .cb_size    = 0U,
                .stack_mem  = NULL,
                .stack_size = GNSS_INIT_TASK_STACK_SIZE,
                .tz_module  = 0U,
                .reserved   = 0U
            };

            h_init_task = osThreadNew(init_task, NULL, &attr);

            if (NULL == h_init_task)
            {
                ret = STATUS_FAILED;
            }
            task_mon_register_for_stats(TASK_ID_GNSS_INIT, h_init_task);
        }

        if ((true == ret) && (NULL == h_resp_task))
        {
            osThreadAttr_t attr = {
                .attr_bits  = osThreadDetached,
                .name       = "gnss_resp",
                .priority   = osPriorityNormal,
                .cb_mem     = NULL,
                .cb_size    = 0U,
                .stack_mem  = NULL,
                .stack_size = GNSS_RESP_TASK_STACK_SIZE,
                .tz_module  = 0U,
                .reserved   = 0U
            };

            h_resp_task = osThreadNew(resp_task, NULL, &attr);

            if (NULL == h_resp_task)
            {
                ret = STATUS_FAILED;
            }
            task_mon_register_for_stats(TASK_ID_GNSS_LISTEN, h_resp_task);
        }

        // initialize gnss critical section module
        gnss_critical_init();

        // initialize gnss command manager
        if (false == gnss_cmd_init())
        {
            ret = STATUS_FAILED;
        }
    }
    else if (INIT_HW == level)
    {
        // initialize pps telemetry collection
        pps_init();
        ret = STATUS_OK;
    }
    else
    {
        ret = STATUS_NOT_SUPPORTED;
    }

    return ret;
}

mod_op_status_id_t gnss_deinit(sys_init_level_id_t level)
{
    mod_op_status_id_t ret = STATUS_OK;

    switch (level)
    {
        case INIT_HW:
            pps_deinit(); // pps
            break;

        case INIT_OS:
            // gnss initialization task
            task_mon_set_task_policy(TASK_ID_GNSS_INIT, TASK_MON_POLICY_DONT_CARE);

            // gnss data reception task
            task_mon_set_task_policy(TASK_ID_GNSS_LISTEN, TASK_MON_POLICY_DONT_CARE);

            // gnss user commanding task
            gnss_cmd_deinit();
            break;

        case INIT_MEM:
            ret = STATUS_NOT_SUPPORTED;
            break;

        default:
            break;
    }

    return ret;
}

mod_op_status_id_t gnss_run(void)
{
    return start(true);
}

mod_op_status_id_t gnss_stop(void)
{
    return stop(true);
}

bool gnss_is_on(void)
{
    bool res = false;

    if (true == gnss_critical_enter(osWaitForever))
    {
        res = gnss_power_is_on();
        gnss_critical_exit();
    }

    return res;
}

bool gnss_is_tm_valid(const gnss_time_t *tim)
{
    bool res = false;

    // this is a basic check taken from oem719 user manual
    if ((NULL != tim) &&
        (GNSS_UTC_STATUS_INVALID != tim->utc_status) &&
        (0 != tim->utc_month) &&
        (0 != tim->utc_day) &&
        (60000 > tim->utc_ms))
    {
        res = true;
    }

    return res;
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
/**
 * @brief start gnss
 *
 * @param[in] external_req if true - request is from outside the driver (higher priority)
 *
 * @retval STATUS_NOT_SUPPORTED
 * @retval STATUS_FAILED
 * @retval STATUS_OK
 */
static mod_op_status_id_t start(const bool external_req)
{
    mod_op_status_id_t res = STATUS_NOT_SUPPORTED;

    if ((NULL != h_init_task) &&
        (true == gnss_critical_is_init()))
    {
        res = STATUS_FAILED;

        if (true == gnss_critical_enter(osWaitForever))
        {
            // always turn on if the request is from outside the driver
            // otherwise we 1st check if the user has instructed to remain stopped
            // in such case the device won't be turned on since external requests are
            // with higher priority
            if ((true == external_req) || (false == external_stop))
            {
                // if the GNSS is already on there is no need to start it again
                if (false == already_on)
                {
                    (void)osThreadFlagsSet(h_init_task, GNSS_START_FLAG);
                    gnss_power_on();
                    already_on    = true;
                    external_stop = false;
                }

                res = STATUS_OK;
            }

            gnss_critical_exit();
        }
    }

    return res;
}

/**
 * @brief stop gnss
 *
 * @param[in] external_req if true - request is from outside the driver (higher priority)
 *
 * @retval STATUS_NOT_SUPPORTED
 * @retval STATUS_FAILED
 * @retval STATUS_OK
 */
static mod_op_status_id_t stop(const bool external_req)
{
    mod_op_status_id_t res = STATUS_NOT_SUPPORTED;

    if (true == gnss_critical_is_init())
    {
        res = STATUS_FAILED;

        if (true == gnss_critical_enter(osWaitForever))
        {
            gnss_power_off(); // cut power to the gnss

            if (true == external_req)
            {
                external_stop = external_req;
            }

            already_on = false;
            gnss_critical_exit();
            res = STATUS_OK;
        }
    }

    return res;
}

/**
 * @brief safely reset timer
 *
 * @param[in] p_handle timer handle
 */
static void response_timer_reset(timer_handle_t *const p_handle)
{
    if (true == gnss_critical_enter(osWaitForever))
    {
        timer_start(p_handle);
        gnss_critical_exit();
    }
}

/**
 * @brief check if timer is elapsed
 *
 * @param[in] p_handle timer handle
 *
 * @retval true  timer is elapsed
 * @retval false timer is not elapsed
 */
static bool response_timer_elapsed(timer_handle_t *const p_handle)
{
    bool res = false;

    if (true == gnss_critical_enter(osWaitForever))
    {
        res = timer_is_elapsed(p_handle, GNSS_NO_RESPONSE_TIMEOUT_MS);
        gnss_critical_exit();
    }

    return res;
}

/**
 * @brief performs full device power cycle
 */
static bool power_cycle(void)
{
    mod_op_status_id_t mod_op;
    bool               status = true;

    // stop communication on OBC side
    if (false == gnss_uart_deinit())
    {
        fdir_srv_log_if_clear(FDIR_FAULT_GNSS_CMD_EXEC_FAILURE, FDIR_AGENT_GNSS, "Failed GNSS UART deinit");
        status = false;
    }

    // shutdown gnss
    if (true == status)
    {
        mod_op = stop(false);
        if (STATUS_OK != mod_op)
        {
            fdir_srv_log_if_clear(FDIR_FAULT_GNSS_CMD_EXEC_FAILURE, FDIR_AGENT_GNSS, "Failed shutdown GNSS with error %d", mod_op);
            status = false;
        }
    }

    // allow gnss some time for shutdown
    osDelay(1000);

    if (true == status)
    {
        // start gnss, if user has not forced a shutdown
        mod_op = start(false);
        if (STATUS_OK != mod_op)
        {
            fdir_srv_log_if_clear(FDIR_FAULT_GNSS_CMD_EXEC_FAILURE, FDIR_AGENT_GNSS, "Failed start GNSS with error %d", mod_op);
            status = false;
        }
    }

    return status;
}

/**
 * @brief ready data buffers for storing data from response queue
 */
static inline void reset_data_buffers(void)
{
    memset(gnss_raw_resp.data, 0, GNSS_UART_BUFFER_DATA_SZ);
    gnss_raw_resp.data_sz = 0;
}

/**
 * @brief task that initializes obc<>gnss communication
 *
 * @param[in] p_task_args not used
 */
static void init_task(void *p_task_args)
{
    (void)p_task_args;

    task_mon_task_initialized(TASK_ID_GNSS_INIT);
    task_mon_set_task_policy(TASK_ID_GNSS_INIT, TASK_MON_POLICY_MONITOR);

    for (;;)
    {
        task_mon_i_am_alive(TASK_ID_GNSS_INIT);

        if (GNSS_START_FLAG == osThreadFlagsWait(GNSS_START_FLAG, osFlagsWaitAny, 10000))
        {
            bool status;

            // restart the response timers to prevent expiration while we are initializing the gnss
            response_timer_reset(&h_bestxyz_tim);
            response_timer_reset(&h_time_tim);

            // wait for gnss to boot
            osDelay(GNSS_BOOT_TIMEOUT_MS);

            status = gnss_uart_init();
            if (false == status)
            {
                GNSS_BaudRate_t cur_br;
                GNSS_BaudRate_t nvm_br;
                (void)gnss_uart_baudrate_get(&nvm_br, &cur_br);

                fdir_srv_log_if_clear(FDIR_FAULT_GNSS_CMD_EXEC_FAILURE,
                                      FDIR_AGENT_GNSS,
                                      "Failed UART init with current %u baud | nvm %u baud",
                                      gnss_uart_baudrate_map(cur_br),
                                      gnss_uart_baudrate_map(nvm_br));
            }
            osDelay(GNSS_AFTER_OP_WAIT_MS);

            if (true == status)
            {
                // send command to gnss to configure disabling the RX status event log
                status = configure_all_logs();
            }

            // something failed during gnss startup, initialization or setting - restart the device
            if ((false == status) &&
                (false == power_cycle()))
            {
                fdir_srv_log_if_clear(FDIR_FAULT_GNSS_CMD_EXEC_FAILURE, FDIR_AGENT_GNSS, "Failed to reset power to GNSS");
            }

            // if status is true - all init operations have succeeded, therefore bError_occured is false and vice-versa
            DATA_CACHE_FDIR_GNSS_CMD_EXEC_STATUS_t exec_status = { .bError_occured = true };
            exec_status.bError_occured                         = !status;

            dc_set_fdir_gnss_cmd_exec_status_data(&exec_status);
            (void)dc_get_fdir_gnss_cmd_exec_status_data(&exec_status);
            fdir_srv_fault_set_state(FDIR_FAULT_GNSS_CMD_EXEC_FAILURE, FDIR_AGENT_GNSS, exec_status.bError_occured, NULL);
        }

        task_mon_low_stack_check(TASK_ID_GNSS_INIT);
    }
}

/**
 * @brief task that handles gnss responses
 *
 * @param[in] p_task_arg not used
 */
static void resp_task(void *p_task_arg)
{
    (void)p_task_arg;

    gnss_ascii_resp_info_t resp_info;
    gnss_time_t            gnss_time = { 0 };
    gnss_xyz_t             gnss_xyz  = { 0 };

    task_mon_task_initialized(TASK_ID_GNSS_LISTEN);
    task_mon_set_task_policy(TASK_ID_GNSS_LISTEN, TASK_MON_POLICY_MONITOR);

    response_timer_reset(&h_bestxyz_tim);
    response_timer_reset(&h_time_tim);

    for (;;)
    {
        task_mon_i_am_alive(TASK_ID_GNSS_LISTEN);
        reset_data_buffers();

        if (true == gnss_uart_rx(&gnss_raw_resp, 1000))
        {
            if ((true == gnss_resp_is_ascii((const char *)gnss_raw_resp.data, gnss_raw_resp.data_sz)) &&
                (true == gnss_resp_get_ascii_info((const char *)gnss_raw_resp.data, gnss_raw_resp.data_sz, &resp_info)) &&
                (true == gnss_resp_is_ascii_crc_valid(&resp_info)))
            {
                // is this BESTXYZ log
                if (NULL != strnstr(resp_info.p_header_start, GNSS_RESP_LOG_BESTXYZA_HDR, resp_info.header_size))
                {
                    // parse ascii response to binary
                    if (true == gnss_resp_parse_ascii_pv(&resp_info, &gnss_xyz))
                    {
                        // invoking user callback processing pv log
                        gnss_cfg_pv_callback(&gnss_xyz);

                        // reset response timer
                        response_timer_reset(&h_bestxyz_tim);
                    }
                }
                // is this TIME log
                else if (NULL != strnstr(resp_info.p_header_start, GNSS_RESP_LOG_TIMEA_HDR, resp_info.header_size))
                {
                    // parse ascii response to binary
                    if (true == gnss_resp_parse_ascii_tm(&resp_info, &gnss_time))
                    {
                        // invoking user callback processing t log
                        gnss_cfg_tm_callback(&gnss_time);

                        // reset response timer
                        response_timer_reset(&h_time_tim);
                    }
                }
                else
                {
                    // received an unexpected log here, so we discard it
                }
            }
            else
            {
                if (NULL != strnstr((const char *)gnss_raw_resp.data, GNSS_CMD_RESP_STATUS_OK, GNSS_CMD_RESP_STATUS_OK_SZ))
                {
                    // we have received a response to a user command
                    gnss_register_cmd_resp();
                    gnss_user_cmd_resp_cbk();
                }
            }
        }

        // if any log is not received in time - restart the device
        if ((true == response_timer_elapsed(&h_bestxyz_tim)) ||
            (true == response_timer_elapsed(&h_time_tim)))
        {
            response_timer_reset(&h_bestxyz_tim);
            response_timer_reset(&h_time_tim);
            power_cycle();
        }

        task_mon_low_stack_check(TASK_ID_GNSS_LISTEN);
    }
}
