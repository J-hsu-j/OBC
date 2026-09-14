/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup Services
 * @{
 *
 * @defgroup comm_gw
 * @{
 *
 * @file comm_gw_cmn.h
 * @brief COMM GW common types and interfaces
 *
 * @}
 * @}
 */

#ifndef COMM_GW_CMN_H
#define COMM_GW_CMN_H

#include <stdint.h>
#include "config/comm_gw/inc/comm_gw_users.h"

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/
/** @brief Defines the parameters for an FP GW send operation */
typedef struct
{
    const void    *p_comm_params;      /**< communication parameters used by the specific interface for addressing purposes (specific to each COMM GW interface */
    const uint8_t *p_req_data;         /**< pointer to the message data to send */
    uint32_t       req_data_size;      /**< size of the frame to send (in bytes) */
    uint8_t       *p_resp_data;        /**< pointer to the buffer which receives the response data */
    uint32_t      *p_resp_data_size;   /**< pointer to receive the actual size of the response frame */
    uint32_t       resp_data_max_size; /**< maximum size of the response which can be placed in the p_resp_data buffer */
    uint32_t       resp_timeout;       /**< milliseconds to wait for the response before reporting failure */
} comm_gw_send_ctx_t;

/** @brief Possible outcomes of the FP GW communication */
typedef enum
{
    COMM_GW_RES_OK = 0,       /**< the request was executed successfully */
    COMM_GW_RES_OK_PARTIAL,   /**< the request executed successfully but there is no space in the response buffer to hold the complete response */
    COMM_GW_RES_ERR,          /**< the request was sent but a response was not received due to communication error */
    COMM_GW_RES_INVALID_ARGS, /**< invalid arguments passed to send operation */
    COMM_GW_RES_SEND_ERR,     /**< send confirmation callback reported an error (see node trace for details) */
    COMM_GW_RES_SND_TIMEOUT,  /**< request sending timed out */
    COMM_GW_RES_RCV_TIMEOUT,  /**< response reception timed out */
    COMM_GW_RES_MAX           /**< value used for range checking only */
} comm_gw_comm_res_t;

/** @brief Interface notification function to be called upon completion of the requested communication either successfully or
 *  due to error or timeout.
 *
 *  @param[in] user_id user ID for which the communication completed (see @ref comm_gw_user_id_t for possible values)
 *  @param[in] op_status status of the operation
 *
 */
typedef void (*comm_gw_comm_finished_func_t)(const uint8_t user_id, const comm_gw_comm_res_t op_status);

/** @brief Provides a common interface to be implemented by specific COMM GW extensions */
typedef struct
{
    void (*p_comm_gw_if_init)(void);
    void (*p_comm_gw_if_send)(const uint8_t user_id, comm_gw_send_ctx_t *const p_send_ctx, const comm_gw_comm_finished_func_t p_comm_finished_cb);
} comm_gw_if_t;

#endif /* COMM_GW_CMN_H */
