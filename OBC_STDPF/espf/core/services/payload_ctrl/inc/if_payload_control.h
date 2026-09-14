/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef IF_PAYLOAD_CONTROL_H
#define IF_PAYLOAD_CONTROL_H
/**
 * @addtogroup payload_ctrl
 * @{
 *
 * @file if_payload_control.h
 * @brief Payload Control Interface Header. This interface shall be implemented by all
 *        payload configured in the system to enable uniform control and query operation from
 *        ConOps mechanisms.
 *
 * @}
 */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

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

/** @brief These values describe the possible outcomes of a payload operation */
typedef enum
{
    PL_OP_STATUS_REJECT,  /**< Used to indicate that the payload operation is rejected */
    PL_OP_STATUS_FAILURE, /**< Used to indicate that the payload operation failed */
    PL_OP_STATUS_OK       /**< Used to indicate that the payload operation succeeded */
} pl_op_status_t;

/** @brief These values describe the possible stop modes of the payloads. */
typedef enum
{
    PL_OP_STOP_MODE_NORMAL    = 0x00, /**< Standard stop mode sequence executed */
    PL_OP_STOP_MODE_EMERGENCY = 0xFF  /**< Immediate power cut of the payload */
} pl_op_stop_mode_t;

/** @brief Enumeration of states used by the Payload Controller to handle the common payload behavior */
typedef enum
{
    PL_STATE_NOT_INIT, /**< Payload state indicating the init operation is not started */
    PL_STATE_STOPPED,  /**< Payload state indicating the init operation is executed successfully but the payload is not yet started */
    PL_STATE_STARTED,  /**< Payload state indicating the start operation is confirmed */
    PL_STATE_STARTING, /**< Payload state indicating that the payload is in the process of starting up */
    PL_STATE_STOPPING, /**< Payload state indicating that the payload is in the process of stopping */
    PL_STATE_ERROR,    /**< Error state which can be entered from any other state if the payload reports an issue */
    PL_STATE_MAX       /**< Used for range checking */
} pl_state_t;

/** @brief Payload configuration structure */
typedef struct
{
    void          *p_config_data; /**< Pointer to the payload-specific configuration data */
    const uint32_t size;          /**< Size of the data pointed to by p_config_data */
} pl_config_t;

/** @brief Payload instance type used to represent instances internally in the payload managers
 *  	   which implement the interface described in this file.
 */
typedef uint8_t pl_instance_id_t;

/**
 * @brief Notification sent by the payload manager when a state change occurs.
 *
 * @param[in] instance_id: Payload instance identifier (0 - if single instance).
 * @param[in] to_state:    Payload state which was just reached.
 */
typedef void (*p_pl_event_notify_t)(const pl_instance_id_t instance_id, pl_state_t to_state);

/**
 * @brief Initializes the payload interfaces and puts the payload in stop mode.
 * @param[in] instance_id:       Payload instance identifier (0 - if single instance).
 * @param[in] p_init_cfg:        A pointer to a payload-specific configuration structure used for initialization
 *                               (if NULL, default configuration is used).
 * @param[in] p_event_notify_cb: Asynchronous notification function provided by the user (can be NULL if polling
 *                               is used to check the payload state).
 *
 * @return Operation status result (see @ref pl_op_status_t values for details).
 */
typedef pl_op_status_t (*p_pl_init_t)(const pl_instance_id_t    instance_id,
                                      const pl_config_t *const  p_init_cfg,
                                      const p_pl_event_notify_t p_event_notify_cb);

/**
 * @brief Performs a deinitialization and disabling of related clocks and peripherals required by the payload.
 *        After this call the system can be put safely to power down mode.
 *
 * @param[in] instance_id: Payload instance identifier (0 - if single instance).
 *
 * @return Operation status result (see @ref pl_op_status_t values for details).
 */
typedef pl_op_status_t (*p_pl_deinit_t)(const pl_instance_id_t instance_id);

/**
 * @brief Triggers the payload start-up sequence.
 *
    @param[in] instance_id payload instance identifier (0 - if single instance).
    @param p_start_cfg a pointer to a payload-specific data used to configure the particular start operation.

    @return operation status result (see \ref pl_op_status_t values for details).
*/
typedef pl_op_status_t (*p_pl_start_t)(const pl_instance_id_t instance_id, const pl_config_t *const p_start_cfg);

/**
 * @brief Triggers the payload shutdown sequence.
 *
 * @param[in] instance_id: payload instance identifier (0 - if single instance).
 * @param[in] stop_mode:   specifies how the payload shall be stopped.
 *
 * @return Operation status result (see \ref pl_op_status_t values for details).
 */
typedef pl_op_status_t (*p_pl_stop_t)(const pl_instance_id_t instance_id, const pl_op_stop_mode_t stop_mode);

/**
 * @brief Queries the payload manager for the currently active operational state of the payload.
 *        Shall return the same information as provided by \ref p_pl_event_notify_t.
 *
 * @param[in] instance_id: Payload instance identifier (0 - if single instance).
 *
 * @return Active state of the payload.
 */
typedef pl_state_t (*p_pl_get_active_state_t)(const pl_instance_id_t instance_id);

/**
 * @brief Provides a payload-specific error code which triggered the last entry to the ERROR state (if any).
 *
 * @param[in] instance_id: Payload instance identifier (0 - if single instance).
 * @return 0 - if no error; error code detected.
 */
typedef uint32_t (*p_pl_get_last_error_t)(const pl_instance_id_t instance_id);

/**
 * @brief Payload control interface structure to be implemented by each payload in the system.
          This interface is to be used by the Payload Controller implementation.
*/
typedef struct
{
    p_pl_init_t             init;           /**< Initializes the payload */
    p_pl_deinit_t           deinit;         /**< Deinitializes the payload */
    p_pl_start_t            start;          /**< Starts payload operations */
    p_pl_stop_t             stop;           /**< Stops payload operations */
    p_pl_get_active_state_t get_state;      /**< Retrieves the current state of the payload */
    p_pl_get_last_error_t   get_last_error; /**< Retrieves status of the last error detected by the payload */
} pl_control_if_t;

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

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* IF_PAYLOAD_CONTROL_H */
