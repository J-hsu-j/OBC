/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#include "comm_gw.h"
#include "comm_gw_if_cfg.h"
#include <string.h>
#include "assertions.h"
#include "es_cdef.h"
#include "trace.h"
#include "cmsis_os2.h"

/**
 * @addtogroup Services
 * @{
 *
 * @defgroup comm_gw
 * @{
 *
 * @file comm_gw.c
 * @brief Communication Gateway Implementation
 *
 * Provides a blocking interface to execute commands locally or remotely. Used to enable
 * other services to directly operate with raw command to OBC or external payloads and handle responses privately
 * without executing any globally configured handlers.
 *
 * @}
 * @}
 */

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
/** @brief Thread event flag used to unblock the execution of the COMM GW main thread when a response is
 *         received or a timeout occurs */
#define COMM_GW_UNBLOCK_THREAD_FLAG (0x01U)

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/
/** Return codes for the thread blocking functionality */
typedef enum
{
    THR_BLOCK_STATUS_WAITFINISHED, /**< Received the releasing event before timeout */
    THR_BLOCK_STATUS_WAITTIMEOUT,  /**< Timeout before the event was received */
    THR_BLOCK_STATUS_ERROR,        /**< An undefined error ocurred */
    THR_BLOCK_STATUS_MAX
} thr_block_status_t;

/** @brief COMM GW user context
 *
 *  Used to provide command level thread blocking functionality per user.
 * */
typedef struct
{
    osThreadId_t       caller_tid;     /**< caller thread ID (used to unblock caller in case a response is received or the operation timed-out */
    osMutexId_t        user_lock;      /**< user lock to avoid calls with the same user id from multiple threads */
    comm_gw_comm_res_t last_op_status; /**< result from the last send operation */
} comm_gw_user_t;

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/** @brief Allocated user slots used for FP GW communication */
static comm_gw_user_t comm_gw_users[COMM_GW_USER_ID_MAX];

static osMutexAttr_t user_lock_attr = {
    .name      = "comm_gw_lock",
    .cb_mem    = NULL,
    .cb_size   = 0,
    .attr_bits = osMutexRecursive
};

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
/** @brief Prepares the COMM GW user thread for response waiting */
static void prep_user_thread_wait(void);

/** @brief Blocks the COMM GW user thread until a response comes or a timeout occurs.
 *
 *  @param[in] timeout_ms milliseconds to wait for the response
 *  @return status of the wait operation
 */
static thr_block_status_t user_thread_wait_for_response(uint32_t time_out_ms);

/** @brief Unblocks the user thread which is waiting for a response
 *
 *  Called when the response is received before the timeout period elapsed.
 *
 *  @param[in] p_user user context populated when the FP GW request was triggered
 */
static void release_user_thread(comm_gw_user_t *const p_user);

/** @brief Callback from the corresponding COMM GW plug-in to inform of the status of the operation
 *
 *  See @ref p_comm_gw_comm_finished_func_t for details
 *
 */
static void comm_gw_op_finished_notify(const uint8_t user_id, const comm_gw_comm_res_t op_status);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
void comm_gw_init(void)
{
    // initialize local user slots
    for (uint8_t idx = 0; idx < CDEF_ELEMENT_COUNT(comm_gw_users); idx++)
    {
        comm_gw_users[idx].caller_tid = NULL;

        if (NULL == comm_gw_users[idx].user_lock)
        {
            comm_gw_users[idx].user_lock = osMutexNew(&user_lock_attr);
        }

        comm_gw_users[idx].last_op_status = COMM_GW_RES_MAX;
    }

    // initialize interface-specific user slots
    for (uint8_t if_idx = 0; if_idx < COMM_GW_IF_ID_MAX; if_idx++)
    {
        const comm_gw_if_t *p_comm_gw_if_ref = comm_gw_cfg_get_intf_ref(if_idx);

        if (NULL != p_comm_gw_if_ref)
        {
            p_comm_gw_if_ref->p_comm_gw_if_init();
        }
    }
}

comm_gw_comm_res_t comm_gw_send(const comm_gw_if_id_t gw_if_id, const uint8_t comm_gw_user_id, comm_gw_send_ctx_t *const p_send_ctx)
{
    comm_gw_comm_res_t op_res   = COMM_GW_RES_INVALID_ARGS;
    thr_block_status_t wait_res = THR_BLOCK_STATUS_ERROR;

    const comm_gw_if_t *p_gw_if_ref = comm_gw_cfg_get_intf_ref(gw_if_id);

    if ((NULL != p_send_ctx) &&
        (NULL != p_send_ctx->p_req_data) &&
        (0 < p_send_ctx->req_data_size) &&
        (comm_gw_user_id < COMM_GW_USER_ID_MAX) &&
        (NULL != p_gw_if_ref))
    {
        comm_gw_user_t *p_user = &comm_gw_users[comm_gw_user_id];

        osStatus_t lock_status = osMutexAcquire(p_user->user_lock, COMM_GW_USER_LOCK_TIMEOUT_MS);

        if (osOK == lock_status)
        {
            // setup node response context for later use
            p_user->caller_tid = osThreadGetId();

            prep_user_thread_wait();

            ES_TRACE_DEBUG("[user '%s', if '%s'] %ld bytes sent", comm_gw_cfg_get_user_str(comm_gw_user_id), comm_gw_cfg_get_gw_str(gw_if_id), p_send_ctx->req_data_size);

            p_gw_if_ref->p_comm_gw_if_send(comm_gw_user_id, p_send_ctx, &comm_gw_op_finished_notify);

            wait_res = user_thread_wait_for_response((0UL == p_send_ctx->resp_timeout) ? COMM_GW_RESPONSE_TIMEOUT_MS : p_send_ctx->resp_timeout);

            switch (wait_res)
            {
                case THR_BLOCK_STATUS_WAITFINISHED:
                    {
                        op_res = p_user->last_op_status;

                        p_user->last_op_status = COMM_GW_RES_MAX;

                        break;
                    }

                case THR_BLOCK_STATUS_WAITTIMEOUT:
                    {
                        op_res = COMM_GW_RES_RCV_TIMEOUT;
                        break;
                    }

                default:
                    {
                        op_res = COMM_GW_RES_ERR;
                        break;
                    }
            }
            (void)osMutexRelease(p_user->user_lock);
        }
        else
        {
            if (osErrorTimeout == lock_status)
            {
                op_res = COMM_GW_RES_SND_TIMEOUT;
            }
            else
            {
                op_res = COMM_GW_RES_SEND_ERR;
            }
        }
    }
    else
    {
        if (NULL != p_gw_if_ref)
        {
            ES_TRACE_ERROR("Request to send gw command with invalid arguments");
        }
        else
        {
            ES_TRACE_ERROR("comm interface '%s' (%d) requested by user '%s' is NULL",
                            comm_gw_cfg_get_gw_str(gw_if_id), gw_if_id,
                            comm_gw_cfg_get_user_str(comm_gw_user_id));
        }
    }

    if ((COMM_GW_RES_OK == op_res) &&
        (NULL != p_send_ctx->p_resp_data_size) &&
        (*(p_send_ctx->p_resp_data_size) > p_send_ctx->resp_data_max_size))
    {
        op_res = COMM_GW_RES_OK_PARTIAL;
    }

    ES_TRACE_DEBUG("[user '%s', if '%s'] op finished with res '%s' (%ld byte(s) rcvd)",
                   comm_gw_cfg_get_user_str(comm_gw_user_id),
                   comm_gw_cfg_get_gw_str(gw_if_id),
                   comm_gw_cfg_get_err_str(op_res),
                   (NULL != p_send_ctx->p_resp_data_size) ? *p_send_ctx->p_resp_data_size : 0);

    return op_res;
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
static void prep_user_thread_wait(void)
{
    (void)osThreadFlagsClear(COMM_GW_UNBLOCK_THREAD_FLAG);
}

static thr_block_status_t user_thread_wait_for_response(uint32_t time_out_ms)
{
    thr_block_status_t result;

    uint32_t os_thread_flags_result =
        osThreadFlagsWait(COMM_GW_UNBLOCK_THREAD_FLAG, osFlagsWaitAll, time_out_ms);

    if ((os_thread_flags_result & COMM_GW_UNBLOCK_THREAD_FLAG) == COMM_GW_UNBLOCK_THREAD_FLAG)
    {
        result = THR_BLOCK_STATUS_WAITFINISHED;
    }
    else if ((osStatus_t)os_thread_flags_result == osErrorTimeout)
    {
        result = THR_BLOCK_STATUS_WAITTIMEOUT;
    }
    else
    {
        result = THR_BLOCK_STATUS_ERROR;
    }

    return result;
}

static void release_user_thread(comm_gw_user_t *const p_user)
{
    BREAK_ASSERT(NULL != p_user);

    (void)osThreadFlagsSet(p_user->caller_tid, COMM_GW_UNBLOCK_THREAD_FLAG); // NOSONAR (check already made in BREAK_ASSERT)
}

static void comm_gw_op_finished_notify(const uint8_t user_id, const comm_gw_comm_res_t op_status)
{
    BREAK_ASSERT(user_id < (uint8_t)COMM_GW_USER_ID_MAX);
    BREAK_ASSERT(op_status < COMM_GW_RES_MAX);

    comm_gw_user_t *p_user = &comm_gw_users[user_id];

    p_user->last_op_status = op_status;

    release_user_thread(p_user);
}
