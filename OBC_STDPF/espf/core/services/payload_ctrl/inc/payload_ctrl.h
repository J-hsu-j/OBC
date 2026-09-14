/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef PAYLOAD_CTRL_H
#define PAYLOAD_CTRL_H
/**
 * @addtogroup Services
 * @{
 *
 * @defgroup payload_ctrl Payload Controller
 * @{
 *
 * Responsible for:
 * - individual payload activation/deactivation
 * - payload state tracking and error handling
 *
 * @file payload_ctrl.h
 * @brief Payload Controller public interface
 *
 *
 * @}
 * @}
 */

#include <stdint.h>
#include "if_payload_control.h"
#include "payload_shared_types.h"
#include "payload_ctrl_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/** @brief Payload Controller operation status codes. */
typedef enum
{
    PL_CTRL_OP_RES_NOT_INIT,      /**< Component not initialized */
    PL_CTRL_OP_RES_INVALID_PL_ID, /**< Invalid payload id provided */
    PL_CTRL_OP_RES_REFUSE_CMD,    /**< Command is refused because operating conditions do not allow it */
    PL_CTRL_OP_RES_FAILED,        /**< Command execution failed */
    PL_CTRL_OP_RES_OK,            /**< Operation successful */
    PL_CTRL_OP_RES_MAX            /**< Used for validity checking only */
} payload_ctrl_op_res_t;

/** @brief Payload event structure. */
typedef struct
{
    payload_ctrl_payload_t payload_id; /**< Unique payload instance identifier */
    pl_state_t             op_state;   /**< Operating state to which a transition occurred */
    uint32_t               error_code; /**< Payload error code in case op_state = PL_STATE_ERROR */
} payload_ctrl_event_t;

/** @brief Payload starting configuration. */
typedef struct
{
    pl_args_t payload_args; /**< Payload-specific buffer passed transparently to the respective payload manager */
} PACKED payload_ctrl_start_cfg_t;

/**
 * 	@brief Payload event callback used to signal payload state changes to client components.
 *
 * 	@param p_event	State change event data
 */
typedef void (*p_payload_event)(const payload_ctrl_event_t *const p_event);

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
 * @brief Initializes all configured payloads.
 *
 * @retval PL_CTRL_OP_RES_OK All payloads initialized successfully.
 * @retval PL_CTRL_OP_FAILED At least one payload init failed.
 */
payload_ctrl_op_res_t payload_ctrl_init(void);

/**
 * @brief Deinitializes all configured payloads.
 *
 * @retval PL_CTRL_OP_RES_OK All payloads deinitialized successfully.
 * @retval PL_CTRL_OP_FAILED At least one payload deinit failed.
 */
payload_ctrl_op_res_t payload_ctrl_deinit(void);

/**
 * @brief Starts a specified payload instance.
 *
 * @param[in] payload_id  Unique payload instance identifier.
 * @param[in] p_start_cfg Pointer to the payload start configuration.
 *
 * @retval PL_CTRL_OP_RES_OK Payload started successfully.
 * @retval PL_CTRL_OP_FAILED Starting of the payload failed.
 * @retval PL_CTRL_OP_RES_REFUSE_CMD Starting of the payload rejected by handler.
 */
payload_ctrl_op_res_t payload_ctrl_start(const payload_ctrl_payload_t          payload_id,
                                         const payload_ctrl_start_cfg_t *const p_start_cfg);

/**
 * @brief Stops a specified payload instance.
 *
 * @param[in] payload_id Unique payload instance identifier.
 * @param[in] stop_mode  Specifies how the stop operation shall be performed.
 *
 * @retval PL_CTRL_OP_RES_OK         Payload stopped successfully.
 * @retval PL_CTRL_OP_FAILED         Stopping of the payload failed.
 * @retval PL_CTRL_OP_RES_REFUSE_CMD Stopping of the payload rejected by handler.
 */
payload_ctrl_op_res_t payload_ctrl_stop(const payload_ctrl_payload_t payload_id,
                                        const pl_op_stop_mode_t      stop_mode);

/**
 * @brief Registers a callback invoked on event occurring in any payload.
 *
 * @param[in] p_evt_callback Pointer to an event notification function called when payload state changes;
 *                           if NULL specified, the subscription is removed.
 */
void payload_ctrl_subscribe_events(p_payload_event const p_evt_callback);

/**
 * @brief Queries the state of a specified payload.
 *
 * @param[in]  payload_id    Unique payload instance identifier.
 * @param[out] p_state       Pointer to receive the payload state.
 * @param[out] p_error_code  Only to be used if the p_state is set to PL_STATE_ERROR.
 *
 * @retval PL_CTRL_OP_RES_OK              State retrieved successfully.
 * @retval PL_CTRL_OP_RES_INVALID_PL_ID   Wrong parameter value for payload_id.
 * @retval PL_CTRL_OP_RES_FAILED          An error occurred while getting the state.
 */
payload_ctrl_op_res_t payload_ctrl_get_state(const payload_ctrl_payload_t payload_id,
                                             pl_state_t *const            p_state,
                                             uint32_t *const              p_error_code);

/**
 * @brief Notification function to be used by the payload_cfg.c implementation to properly
 *        route payload manager notifications from multi-instance payloads to the correct
 *        external payload_id.
 *
 *  @param[in] payload_id External payload id (unique for each payload instance no matter if it is
 *                        of the same kind and managed by the same payload manager.
 *  @param[in] to_state   Target state which was reached by the payload.
 */
void payload_ctrl_event_notify(const payload_ctrl_payload_t payload_id, const pl_state_t to_state);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* PAYLOAD_CTRL_H */
