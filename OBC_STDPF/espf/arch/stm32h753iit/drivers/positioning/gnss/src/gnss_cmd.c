/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup gnss
 * @{
 * @file gnss_cmd.c
 * @brief gnss user command module
 * @}
 */

#include "trace.h"
#include "cmsis_os2.h"
#include "sys_instancer_ct.h"
#include "gnss_critical.h"
#include "taskmon.h"
#include "taskmon_stat.h"
#include "gnss_cfg.h"
#include "fdir_srv.h"
#include "gnss_uart.h"
#include "gnss_critical.h"
#include "gnss_types.h"
#include "FP_gnssProtocolTypes.h"
#include "sys_time.h"
#include "gnss_cmd.h"
#include "timer.h"
#include <string.h>

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

#define SYS_TIME_INIT \
    {                 \
        .hour = 0,    \
        .min  = 0,    \
        .sec  = 0,    \
        .ms   = 0,    \
        .us   = 0     \
    }

#define GNSS_CMD_DATA_INIT                  \
    {                                       \
        .gnss_cmd_buffer   = { 0 },         \
        .gnss_cmd_sz       = (uint8_t)0,    \
        .gnss_cmd_exec_cbk = NULL,          \
        .timeout_ms        = (uint32_t)0,   \
        .duration_ms       = (uint32_t)0,   \
        .time_requested    = SYS_TIME_INIT, \
        .time_started      = SYS_TIME_INIT, \
        .cmd_status        = CMD_ERROR      \
    }

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/
/** @brief internal state variable, used to track the state of the currently processed command */
typedef enum
{
    NOT_STARTED,
    IN_PROGRESS,
    TIMED_OUT,
    DONE
} gnss_processing_cmd_state_t;

/** @brief internal gnss user command structure containing the command currently being processed */
typedef struct
{
    uint8_t                     id;
    gnss_cmd_data_t             data;
    gnss_processing_cmd_state_t state;
} processing_cmd_t;

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
/** @brief gnss user commands queue handle initializers */
static gnss_cmd_t gnss_cmd_handles[GNSS_CMD_QUEUE_LEN] = {
    { GNSS_CMD_DATA_INIT, INVALID_CMD_ID },
    { GNSS_CMD_DATA_INIT, INVALID_CMD_ID }
};

/** @brief next free index in the command queue */
static uint8_t next_free_index = 0;

/** @brief last processed index in the command queue */
static int32_t last_processed_index = -1;

/** @brief static state variable containing the current command id */
static uint8_t current_cmd_id = INVALID_CMD_ID;

/** @brief command thread handle */
static osThreadId_t h_cmd_task = NULL;

/** @brief command thread stack size */
static StaticTask_t gnss_cmd_task_static_mem;

/** @brief command thread stack */
static uint8_t gnss_cmd_stack_static[GNSS_CMD_TASK_STACK_SIZE];

/** @brief command timeout timer handle */
static osTimerId_t gnss_cmd_timeout_timer_id;

/** @brief command static timeout timer */
static StaticTimer_t gnss_cmd_static_timeout_tim;

/** @brief static command queue handle */
static StaticQueue_t gnss_cmd_queue_cb;

/** @brief command queue data */
static uint8_t gnss_cmd_queue_data[GNSS_CMD_QUEUE_LEN];

/** @brief command message queue id */
static osMessageQueueId_t h_gnss_cmd_queue;

/** @brief command processing context */
static processing_cmd_t processing_cmd = {
    .id    = INVALID_CMD_ID,
    .state = NOT_STARTED
};

/** @brief command execution duration timer handle */
static timer_handle_t h_timer;

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
/**
 * @brief ensure that the command is properly terminated with '\r\n'
 * @param[in] cmd_pld command payload
 * @param[in] cmd_pld_sz command payload size
 * @return uint8_t new command payload size based on termination checks
 */
static uint8_t gnss_ensure_cmd_termination(char *cmd_pld, uint8_t cmd_pld_sz);

/**
 * @brief gnss user command task routine
 * @param args: not used
 */
static void gnss_cmd_task(void *args);

/**
 * @brief is gnss communication initialized
 * @note gnss communication is considered initialized if:
 *  1. gnss critical section is initialized
 *  2. gnss user command thread is initialized
 *  3. gnss uart communication is initialized
 * @retval true  gnss communication is initialized
 * @retval false gnss communication is not initialized
 */
static bool gnss_comm_is_init(void);

/**
 * @brief a decisor function, which determines whether commands in the queue should be processed
 * @retval true  there is a command ready for processing and can be popped from the queue
 * @retval false no command is ready for processing and no command should be popped from the queue
 */
static bool fetch_cmd_to_dequeue(void);

/**
 * @brief command timeout callback
 * @note this function is invoked when the command timeout timer expires
 * @param argument: not used
 */
static void gnss_cmd_timeout_cbk(void *argument);

/**
 * @brief Crawls through the command queue to find available space.
 *
 * This function iterates through the command queue to determine if there is
 * sufficient space available for new commands. It checks each entry in the
 * queue and updates the space availability status accordingly. It keeps track
 * of the next free index in the queue, based on previous insertions.
 *
 * @param[in] cmd_idx Pointer to the index of the command queue.
 * @retval true if space is available in the command queue.
 * @retval false if space is not available in the command queue.
 */
static bool crawl_cmd_q_for_space(uint8_t *cmd_idx);

/**
 * @brief Retrieves the index of a command in the command queue based on its ID.
 *
 * This function iterates through the command queue to find the index of the command
 * that matches the provided command ID. It returns the index of the command if found.
 *
 * @param[in] cmd_id The ID of the command to find.
 * @return uint8_t The index of the command in the command queue.
 */
static uint8_t get_idx_from_id(uint8_t cmd_id);

/**
 * @brief register user gnss command in the command queue
 * @param[in] p_cmd_pld         pointer to command payload
 * @param[in] cmd_pld_sz        command payload size
 * @param[in] timeout_ms        command timeout in milliseconds
 * @param[in] p_cmd_exec_cbk    pointer to command execution callback
 * @param[out] p_cmd_id         pointer to command id
 * @return gnss_cmd_status_t command manager operation status
 */
static gnss_cmd_status_t gnss_register_cmd(const char            *p_cmd_pld,
                                           uint8_t                cmd_pld_sz,
                                           const uint32_t         timeout_ms,
                                           pf_gnss_cmd_exec_cbk_t p_cmd_exec_cbk,
                                           uint8_t *const         p_cmd_id);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
bool gnss_cmd_init(void)
{
    bool ret = true;

    // initialize user command queue
    osMessageQueueAttr_t gnss_cmd_queue_attr = {
        .name      = "gnss_cmd_queue",
        .attr_bits = 0,
        .cb_mem    = &gnss_cmd_queue_cb,
        .cb_size   = sizeof(gnss_cmd_queue_cb),
        .mq_mem    = gnss_cmd_queue_data,
        .mq_size   = sizeof(gnss_cmd_queue_data)
    };

    h_gnss_cmd_queue = osMessageQueueNew(GNSS_CMD_QUEUE_LEN, sizeof(uint8_t), &gnss_cmd_queue_attr);

    // initialize gnss user command static timer
    const osTimerAttr_t gnss_cmd_timeout_timer_attr = {
        .name      = "gnss_cmd_timeout_timer",
        .attr_bits = 1,
        .cb_mem    = &gnss_cmd_static_timeout_tim,
        .cb_size   = sizeof(gnss_cmd_static_timeout_tim)
    };

    gnss_cmd_timeout_timer_id = osTimerNew(
        &gnss_cmd_timeout_cbk,
        osTimerOnce,
        NULL,
        &gnss_cmd_timeout_timer_attr);

    // initialize gnss user command static thread
    if ((NULL == h_cmd_task) &&
        (NULL != h_gnss_cmd_queue))
    {
        static const osThreadAttr_t gnss_cmd_thread_attr = {
            .name       = "gnss_cmd",
            .priority   = (osPriority_t)osPriorityNormal,
            .stack_size = GNSS_CMD_TASK_STACK_SIZE,
            .cb_mem     = &gnss_cmd_task_static_mem,
            .cb_size    = sizeof(gnss_cmd_task_static_mem),
            .stack_mem  = &gnss_cmd_stack_static,
            .stack_size = sizeof(gnss_cmd_stack_static),
            .tz_module  = 0U,
            .reserved   = 0U
        };

        h_cmd_task = osThreadNew(gnss_cmd_task, NULL, &gnss_cmd_thread_attr);

        if (NULL == h_cmd_task)
        {
            ret = false;
        }
        task_mon_register_for_stats(TASK_ID_GNSS_CMD, h_cmd_task);
    }

    return ret;
}

void gnss_cmd_deinit(void)
{
    task_mon_set_task_policy(TASK_ID_GNSS_CMD, TASK_MON_POLICY_DONT_CARE);
}

gnss_cmd_status_t gnss_send_cmd(const char            *p_cmd_pld,
                                const uint8_t          cmd_pld_sz,
                                const uint32_t         timeout_ms,
                                pf_gnss_cmd_exec_cbk_t gnss_cmd_exec_cbk,
                                uint8_t *const         p_cmd_id)
{
    BREAK_ASSERT(NULL != p_cmd_pld);
    BREAK_ASSERT(0 != cmd_pld_sz);

    gnss_cmd_status_t ret = CMD_ERROR;
    *p_cmd_id             = INVALID_CMD_ID;

    if ((NULL != p_cmd_pld) &&
        (0 != cmd_pld_sz) &&
        (NULL != gnss_cmd_exec_cbk) &&
        (NULL != p_cmd_id))
    {

        if (true == gnss_critical_enter(GNSS_LOCK_TIMEOUT_MS))
        {
            if (true == gnss_comm_is_init())
            {
                // enqueue command for execution
                gnss_cmd_status_t add_cmd_to_q_res = gnss_register_cmd(
                    p_cmd_pld,
                    cmd_pld_sz,
                    timeout_ms,
                    gnss_cmd_exec_cbk,
                    p_cmd_id);

                // enqueue command for execution, if successfully added to command handle array
                if (CMD_OK == add_cmd_to_q_res)
                {
                    // add command id to currently processed command
                    ES_TRACE_DEBUG("[gnss] (enqueue) command [%d]", *p_cmd_id);

                    ret = CMD_OK;
                }
                else
                {
                    ret = add_cmd_to_q_res;
                }
            }
            else
            {
                ret = CMD_ERROR;
            }
            gnss_critical_exit();
        }
        else
        {
            current_cmd_id = INVALID_CMD_ID;
            ret            = CMD_MUTEX_ERROR;
        }
    }
    else
    {
        ret = CMD_WRONG_PARAMS;
    }

    return ret;
}

bool is_gnss_cmd_init(void)
{
    return (NULL != h_cmd_task) ? true : false;
}

gnss_cmd_status_t gnss_get_cmd_status(uint8_t cmd_id, gnss_cmd_data_t *const p_cmd_data)
{
    gnss_cmd_status_t status = CMD_ERROR;

    if (NULL != p_cmd_data)
    {
        if (true == gnss_critical_enter(GNSS_LOCK_TIMEOUT_MS))
        {
            uint8_t cmd_idx = get_idx_from_id(cmd_id);
            if (gnss_cmd_handles[cmd_idx].gnss_cmd_id == cmd_id)
            {
                (void)memcpy(p_cmd_data, &gnss_cmd_handles[cmd_idx].gnss_cmd_data, sizeof(gnss_cmd_data_t));
                status = CMD_OK;
            }
            else
            {
                status = CMD_NOT_FOUND;
            }

            gnss_critical_exit();
        }
        else
        {
            status = CMD_MUTEX_ERROR;
        }
    }

    return status;
}

gnss_cmd_status_t gnss_set_cmd_status(uint8_t cmd_id, const gnss_cmd_data_t *const p_cmd_data)
{
    gnss_cmd_status_t status = CMD_ERROR;

    if (NULL != p_cmd_data)
    {
        if (true == gnss_critical_enter(GNSS_LOCK_TIMEOUT_MS))
        {
            uint8_t cmd_idx = get_idx_from_id(cmd_id);

            if (gnss_cmd_handles[cmd_idx].gnss_cmd_id == cmd_id)
            {
                (void)memcpy(&gnss_cmd_handles[cmd_idx].gnss_cmd_data, p_cmd_data, sizeof(gnss_cmd_data_t));
                status = CMD_OK;
            }
            else
            {
                status = CMD_NOT_FOUND;
            }

            gnss_critical_exit();
        }
        else
        {
            status = CMD_MUTEX_ERROR;
        }
    }
    else
    {
        status = CMD_ERROR;
    }

    return status;
}

void gnss_register_cmd_resp(void)
{
    // stop command timeout & duration timers
    uint32_t cmd_duration_ms = timer_get_elapsed_time(&h_timer);
    osTimerStop(gnss_cmd_timeout_timer_id);
    timer_stop(&h_timer);

    // check if the current command has not already timed out
    gnss_cmd_status_t cmd_stat = gnss_get_cmd_status(processing_cmd.id, &processing_cmd.data);

    if ((CMD_ERROR != cmd_stat) &&
        (CMD_MUTEX_ERROR != cmd_stat) &&
        (CMD_NOT_FOUND != cmd_stat) &&
        (CMD_TIMED_OUT != processing_cmd.data.cmd_status))
    {
        processing_cmd.data.gnss_cmd_exec_cbk(
            CMD_OK,
            cmd_duration_ms,
            processing_cmd.id);
    }
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
static uint8_t get_idx_from_id(uint8_t cmd_id)
{
    uint8_t idx = 0;

    for (uint8_t i = 0; i < GNSS_CMD_QUEUE_LEN; i++)
    {
        if (gnss_cmd_handles[i].gnss_cmd_id == cmd_id)
        {
            idx = i;
            break;
        }
    }

    return idx;
}

static bool crawl_cmd_q_for_space(uint8_t *cmd_idx)
{
    uint8_t active_count = 0;

    // Check active commands before searching for space
    for (uint8_t i = 0; i < GNSS_CMD_QUEUE_LEN; i++)
    {
        if ((gnss_cmd_handles[i].gnss_cmd_data.cmd_status == CMD_PENDING) ||
            (gnss_cmd_handles[i].gnss_cmd_data.cmd_status == CMD_PROCESSING))
        {
            active_count++;
        }
    }

    // Only search for space if there's operational capacity
    if (active_count < GNSS_CMD_QUEUE_LEN)
    {
        uint8_t start_idx   = next_free_index;
        bool    space_found = false;

        for (uint8_t i = 0; i < GNSS_CMD_QUEUE_LEN; i++)
        {
            uint8_t current_idx = (start_idx + i) % GNSS_CMD_QUEUE_LEN;
            if ((gnss_cmd_handles[current_idx].gnss_cmd_data.cmd_status != CMD_PENDING) &&
                (gnss_cmd_handles[current_idx].gnss_cmd_data.cmd_status != CMD_PROCESSING))
            {
                space_found     = true;
                *cmd_idx        = current_idx;
                next_free_index = (current_idx + 1) % GNSS_CMD_QUEUE_LEN;
                break;
            }
        }
        return space_found;
    }
    return false;
}

static gnss_cmd_status_t gnss_register_cmd(const char            *p_cmd_pld,
                                           uint8_t                cmd_pld_sz,
                                           uint32_t               timeout_ms,
                                           pf_gnss_cmd_exec_cbk_t p_cmd_exec_cbk,
                                           uint8_t *const         p_cmd_id)
{
    CRIT_ASSERT(NULL != p_cmd_pld);
    CRIT_ASSERT(NULL != p_cmd_id);
    CRIT_ASSERT(NULL != p_cmd_exec_cbk);

    gnss_cmd_status_t res             = CMD_ERROR;
    sys_time_t        time_of_request = SYS_TIME_INIT;

    // attempt to find space for the new command in the command queue
    uint8_t cmd_idx;
    if (false == crawl_cmd_q_for_space(&cmd_idx))
    {
        return CMD_QUEUE_FULL;
    }

    // check if command timeout is a reasonable value
    uint32_t effective_timeout_ms = timeout_ms;
    if (effective_timeout_ms == 0)
    {
        effective_timeout_ms = GNSS_CMD_MIN_TIMEOUT_MS;
    }

    current_cmd_id += 1; // increment for new command id
    current_cmd_id = (current_cmd_id == INVALID_CMD_ID) ? 0 : current_cmd_id;

    gnss_cmd_data_t *const p_cmd_data = &gnss_cmd_handles[cmd_idx].gnss_cmd_data;

    // check if command length is valid
    static_assert(GNSS_CMD_BUFFER_DATA_SZ == (sizeof(((gnssrequest_command_executionRequestData_t *)NULL)->strCmd) + 2));

    // copy command payload to command buffer
    (void)memcpy(p_cmd_data->gnss_cmd_buffer, p_cmd_pld, cmd_pld_sz);

    // ensure correct termination of command buffer
    uint8_t cmd_pld_recalc_sz = gnss_ensure_cmd_termination(p_cmd_data->gnss_cmd_buffer, cmd_pld_sz);

    // initialize command data
    gnss_cmd_handles[cmd_idx].gnss_cmd_id = current_cmd_id;
    p_cmd_data->gnss_cmd_sz               = cmd_pld_recalc_sz;
    p_cmd_data->gnss_cmd_exec_cbk         = p_cmd_exec_cbk;
    p_cmd_data->timeout_ms                = effective_timeout_ms;
    p_cmd_data->duration_ms               = 0U;
    p_cmd_data->cmd_status                = CMD_PENDING;

    // note the time of command request
    // and initialize time_started, which gets set right before command transmission
    (void)sys_time_get(&time_of_request);
    (void)memcpy(&p_cmd_data->time_requested, &time_of_request, sizeof(sys_time_t));
    memset(&p_cmd_data->time_started, 0, sizeof(sys_time_t));
    res = CMD_OK;

    // return a valid id (to the user) assigned to the current command that is requested to be executed
    *p_cmd_id = current_cmd_id;

    return res;
}

static uint8_t gnss_ensure_cmd_termination(char *cmd_pld, uint8_t cmd_pld_sz)
{
    CRIT_ASSERT(NULL != cmd_pld);

    uint8_t new_cmd_pld_sz = cmd_pld_sz;

    // check if the data is already properly terminated
    if ((cmd_pld_sz >= 2) &&
        (cmd_pld[cmd_pld_sz - 2] == '\r') &&
        (cmd_pld[cmd_pld_sz - 1] == '\n'))
    {
        return new_cmd_pld_sz;
    }

    // as long as the user-supplied command payload is not larger than the allotted buffer
    // there will always be enough space in the fp packet for the termination characters
    cmd_pld[cmd_pld_sz]     = '\r';
    cmd_pld[cmd_pld_sz + 1] = '\n';
    new_cmd_pld_sz += 2;

    return new_cmd_pld_sz;
}

static bool gnss_comm_is_init(void)
{
    bool res = false;

    if ((true == gnss_critical_is_init()) &&
        (true == is_gnss_cmd_init()) &&
        (true == is_gnss_uart_init()))
    {
        res = true;
    }

    return res;
}

static bool fetch_cmd_to_dequeue(void)
{
    bool ret = false;

    if (gnss_critical_enter(GNSS_LOCK_TIMEOUT_MS))
    {
        // if any command is being processed, there is nothing to do
        for (uint8_t i = 0; i < GNSS_CMD_QUEUE_LEN; i++)
        {
            if (gnss_cmd_handles[i].gnss_cmd_data.cmd_status == CMD_PROCESSING)
            {
                gnss_critical_exit();
                return false;
            }
        }

        for (uint8_t i = 0; i < GNSS_CMD_QUEUE_LEN; i++)
        {
            uint8_t idx = (last_processed_index + 1 + i) % GNSS_CMD_QUEUE_LEN; // wrap around queue, based on last processed command index
            if (gnss_cmd_handles[idx].gnss_cmd_data.cmd_status == CMD_PENDING)
            {
                // a pending command is found and no command is currently being processed, so processing starts for the pending one
                gnss_cmd_handles[idx].gnss_cmd_data.cmd_status = CMD_PROCESSING;

                (void)sys_time_get(&gnss_cmd_handles[idx].gnss_cmd_data.time_started);
                (void)memcpy(&processing_cmd.data, &gnss_cmd_handles[idx].gnss_cmd_data, sizeof(gnss_cmd_data_t));

                processing_cmd.id = gnss_cmd_handles[idx].gnss_cmd_id;

                last_processed_index = idx;  // update the last processed index to the current one
                ret                  = true; // indicate that a command has been picked for processing

                ES_TRACE_DEBUG("[gnss] (dequeue) command [%d] ", processing_cmd.id);
                break;
            }
        }

        gnss_critical_exit();
    }

    return ret;
}

static void gnss_cmd_task(void *p_task_arg)
{
    (void)p_task_arg;

    task_mon_task_initialized(TASK_ID_GNSS_CMD);
    task_mon_set_task_policy(TASK_ID_GNSS_CMD, TASK_MON_POLICY_MONITOR);

    for (;;)
    {
        if (true == fetch_cmd_to_dequeue())
        {
            // start command timeout timer for current user command execution
            (void)osTimerStart(
                gnss_cmd_timeout_timer_id,
                pdMS_TO_TICKS(processing_cmd.data.timeout_ms));

            ES_TRACE_DEBUG("[gnss] (transmitting) command [%d]", processing_cmd.id);

            timer_start(&h_timer); // start command duration timer

            if (false == gnss_uart_tx(
                             (const uint8_t *)processing_cmd.data.gnss_cmd_buffer,
                             ((const uint16_t)processing_cmd.data.gnss_cmd_sz) - 1))
            {
                // if command transmission fails - invoke the registered command execution callback to update the command status to ERROR
                processing_cmd.data.gnss_cmd_exec_cbk(
                    CMD_ERROR,
                    processing_cmd.data.duration_ms,
                    processing_cmd.id);
            }
        }

        osDelay(GNSS_CMD_TASK_PERIOD_MS);
        task_mon_i_am_alive(TASK_ID_GNSS_CMD);
        task_mon_low_stack_check(TASK_ID_GNSS_CMD);
    }
}

static void gnss_cmd_timeout_cbk(void *argument)
{
    (void)argument;
    ES_TRACE_DEBUG("[gnss] (timeout) command [%d]", processing_cmd.id);

    if (INVALID_CMD_ID != processing_cmd.id)
    {
        processing_cmd.state = TIMED_OUT;
        processing_cmd.data.gnss_cmd_exec_cbk(
            CMD_TIMED_OUT,
            processing_cmd.data.timeout_ms,
            processing_cmd.id);
    }
}
