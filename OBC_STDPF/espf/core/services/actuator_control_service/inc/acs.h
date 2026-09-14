/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef ACS_H_
#define ACS_H_

/**
 * @addtogroup Services
 * @{
 *
 * @defgroup ACS Actuator Control Service
 * @{
 * This service provides an interface to initialize and control actuators that are connected to the OBC hardware. It relies on
 * the DataCache to retrieve desired torque data. The specific actuation algorithm for every actuator type is different, with some requiring
 * additional data to work.
 * The @ref coordsys service is also used to transform between the body (satellite) frame and the specific actuator frame. All input data is expected
 * to be in the body (satellite) frame.
 *
 * ## Initialization
 * The function **acs_init()** will initialize and launch the RTOS task that handles the functionality of the whole service. This task
 * runs every @ref ACS_SAMPLING_TIME_MS milliseconds and updates the actuators based on latest data.
 *
 * ## Modes of operation
 * The Actuator Control Service (ACS) has three modes of operation, represented by the @ref acs_state_t enumeration. They can be
 * changed using the **acs_set_op_mode()** function and read through the corresponding **acs_get_op_mode()** function. These functions
 * are also exposed through the ACS FIDL file, named `acs.fidl`, with their names being similar to the aforementioned functions.
 *
 * When in @ref ACS_STATE_RUN, the service will continuously retrieve desired torque values from the DataCache, apply necessary calculations
 * and transformations to achieve data format that is understood by the physical hardware (e.g. Duty cycle of a PWM signal) and then apply it.
 *
 * When in @ref ACS_STATE_STOPPED, the service will not retrieve data from the DataCache and it will not apply any control values to the physical hardware.
 *
 * When in @ref ACS_STATE_MANUAL, the service will continuously apply operator-commanded values, which are configured using the **acs_set_manual_mtq_control_mtq_frame()** function.
 * The service will not read values from the DataCache and will only apply the configured values.
 *
 * These values can be retrieved using the corresponding **acs_get_manual_mtq_control_mtq_frame()** function.
 *
 * Both of these functions are also exposed through the already mentioned `acs.fidl` file.
 *
 * ## Examples of usage
 * ### Normal (run) mode
 * @code {.c}
 * // Initialize the service
 * acs_init();
 *
 * // Move the service to RUN mode
 * acs_set_op_mode(ACS_STATE_RUN);
 *
 * // Write data continuously to appropriate DataCache entry, e.g. magnetorquers require both desired torque and magnetic field samples
 * // The example entries are DATA_CACHE_ACTUATOR_TORQUE_VALUES_t and DATA_CACHE_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_t
 *
 * // Retrieve the last body frame control values
 * int8_t last_body_frame_values[MAGNETORQUER_QUANTITY];
 * acs_get_last_mtq_control_body_frame(last_body_frame_values);
 *
 * // Retrieve the last actuator (MTQ) frame control values
 * int8_t last_mtq_frame_values[MAGNETORQUER_QUANTITY];
 * acs_get_last_mtq_control_mtq_frame(last_mtq_frame_values);
 *
 * // Your normal information handling logic here
 *
 * // Stop the service when needed
 * acs_set_op_mode(ACS_STATE_STOPPED);
 * @endcode
 *
 * The ACS will depend on the DataCache entries being updated often enough so that the data does not time out. For precise timeout lengths, check DataCache documentation.
 *
 * Errors and warnings that occur during the operation of ACS can be retrieved using the **acs_get_status()** function.
 *
 * ### Manual mode
 * @code {.c}
 * // Initialize the service
 * acs_init();
 *
 * // Move the service to MANUAL mode
 * acs_set_op_mode(ACS_STATE_MANUAL);
 *
 * // Set manual control values for the magnetorquers
 * int8_t mtq_values[MAGNETORQUER_QUANTITY] = {10, -20, 30};
 * acs_set_manual_mtq_control_mtq_frame(mtq_values[0], mtq_values[1], mtq_values[2]);
 *
 * // Retrieve the current status
 * acs_status_t current_status = acs_get_status();
 *
 * // Your normal information handling logic here based on the status
 *
 * // Retrieve the manually set control values
 * int8_t manual_control_values[MAGNETORQUER_QUANTITY];
 * acs_get_manual_mtq_control_mtq_frame(manual_control_values);
 *
 * // Your normal information handling logic here
 *
 * // Stop the service when needed
 * acs_set_op_mode(ACS_STATE_STOPPED);
 * @endcode
 *
 * The ACS will depend on the DataCache entries being updated often enough so that the data does not time out. For precise timeout lengths, check DataCache documentation.
 *
 * Errors and warnings that occur during the operation of ACS can be retrieved using the **acs_get_status()** function.
 *
 * All of the examples can be replicated using FIDL functions found in `acs.fidl`.
 *
 * @file   acs.h
 * @brief  Actuator Control Service header file
 *
 * @}
 * @}
 */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
/** @brief The sampling time of the actuator control service */
#define ACS_SAMPLING_TIME_MS (20U)

/** @brief Total amount of magnetorquers */
#define MAGNETORQUER_QUANTITY (3U)

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/
/** @brief Actuator control service states */
typedef enum
{
    ACS_STATE_RUN,    /**< All actuators are updated with values from DataCache */
    ACS_STATE_MANUAL, /**< All actuators are updated with values fed through operator command */
    ACS_STATE_STOPPED /**< All actuators are deinitialized and not updated */
    // extend when needed
} acs_state_t;

/** @brief Actuator control service error codes */
typedef enum
{
    ACS_ERROR_NONE,            /**< No errors have occurred during normal execution */
    ACS_ERROR_DATA_CACHE_GET,  /**< An error occurred while reading data from the DataCache */
    ACS_ERROR_DIVISION_BY_ZERO /**< Attempted division by zero detected */
    // extend when needed
} acs_error_t;

/** @brief Actuator control service error codes */
typedef enum
{
    ACS_WARN_NONE,             /**< No warnings */
    ACS_WARN_SATURATION_UPPER, /**< Reached upper limit of allowed control values */
    ACS_WARN_SATURATION_LOWER, /**< Reached lower limit of allowed control values */
    // extend when needed
} acs_warning_t;

/** @brief Actuator control service status struct */
typedef struct
{
    acs_warning_t last_warning; /**< Last warning that occurred in the service */
    acs_error_t   last_error;   /**< Last error that occurred in the service */
    acs_state_t   state;        /**< State of the actuator control service */
    // extend when needed
} acs_status_t;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/
/* No External variables declarations */

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/
/** @brief Initialization routine for the actuator control service component */
void acs_init(void);

/** @brief Set the mode for the actuator control service
 *  @param[in] acs_state_t desired_op_mode - move the actuator control service to the desired mode */
void acs_set_op_mode(acs_state_t desired_op_mode);

/** @brief Get the mode for the actuator control service
 *  @return acs_state_t - the currently active mode of the actuator control service */
acs_state_t acs_get_op_mode(void);

/** @brief Retrieve the actuator control service status
 *  @return acs_status_t - current status of the actuator control service */
acs_status_t acs_get_status(void);

/** @brief Set the actuator frame control values to the magnetorquers
 *  @param[in] const int8_t mtq_1 - value for magnetorquer_1, attached to physical connector PAN4
 *  @param[in] const int8_t mtq_2 - value for magnetorquer_2, attached to physical connector PAN5
 *  @param[in] const int8_t mtq_3 - value for magnetorquer_3, attached to physical connector PAN6
 *  @note These values are only used when the ACS is in ACS_STATE_MANUAL mode */
void acs_set_manual_mtq_control_mtq_frame(const int8_t mtq_1, const int8_t mtq_2, const int8_t mtq_3);

/** @brief Get the manually set actuator frame control values to the magnetorquers
 *  @param[out] int8_t * const manual_mtq_control_mtq_frame - pointer to an array with the last manually set magnetorquer values
 *  @note These values are only used when the ACS is in ACS_STATE_MANUAL mode */
void acs_get_manual_mtq_control_mtq_frame(int8_t *const manual_mtq_control_mtq_frame);

/** @brief Retrieve the last body (satellite) frame control values to the magnetorquers
 *  @param[out] int8_t * const last_mtq_control_body_frame - pointer to an array with the last magnetorquer values in body frame */
void acs_get_last_mtq_control_body_frame(int8_t *const last_mtq_control_body_frame);

/** @brief Retrieve the last actuator frame control values to the magnetorquers
 *  @param[out] int8_t * const last_mtq_control_mtq_frame - pointer to an array with the last magnetorquer values sent to the physical hardware */
void acs_get_last_mtq_control_mtq_frame(int8_t *const last_mtq_control_mtq_frame);

#ifdef __cplusplus
}
#endif

#endif /* ACS_H_ */
