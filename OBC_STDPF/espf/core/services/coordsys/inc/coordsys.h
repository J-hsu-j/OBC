/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef COORDSYS_H_
#define COORDSYS_H_

/**
 * @addtogroup Services
 * @{
 *
 * @defgroup coordsys Coordsys Transformations
 * @{
 * This service provides an interface to initialize, configure and apply coordinate frame transformations for sensor and actuator data.
 * The sensor data is transformed from each individual sensor's coordinate frame to the body (satellite) frame. The actuator data is
 * transformed from the body (satellite) frame to each actuator's own coordinate frame. Each sensor/actuator type's transformation matrix
 * defines the rotation from the individual sensor/actuator frame to the body frame. For the case of actuators, the rotation matrices are internally
 * corrected to conform with the inverted data flow (body frame conversion to actuator frame).
 *
 * The basic operation that all **coordsys_transform_...()** functions do is the following:
 *
 * The input parameter(**x**) is considered a column vector, which is then multiplied by the corresponding rotation matrix(**R**). The output(**y**)
 * is also a column vector and the location where it is written is given as the 2nd parameter of each function.
 *
 * y = R*x
 *
 * The rotation matrices are represented as 1D arrays of M elements, where M = NxN and N is the dimensionality of the transformation.
 * For example, the gyroscope frame transformation is a 3D transformation, therefore the input and output column vectors are of size 3x1 and the rotation
 * matrix is of size 3x3, represented by 1D array of M=3x3=9 elements.
 *
 * ## Initialization
 * The function **coordsys_init()** loads the frame configurations from non-volatile memory (@ref Nvm).
 * The initialization procedure uses the @ref Nvm stored data to populate variables that hold transformation (rotation) matrices for each sensor type. Each configuration goes through a validation step and the initialization may fail
 * if any of the configurations are incorrect. This can be caused by incorrect setup during the initial software upload to the OBC module or by anomalies caused during operation in orbit.
 *
 * ## Reading active frame configurations
 * The currently active configuration for each sensor/actuator type can be read using the **coordsys_get_frame()** function.
 * The input parameters are the frame type to be read (@ref coordsys_frame_type_t) and a variable to hold the active configuration (coordsys_frame_t) for the specific sensor/actuator.
 *
 * The function **coordsys_load_config_from_nvm()** will load the coordinate frame configurations currently stored in the non-volatile memory (@ref Nvm) and perform a validation step on them.
 * On success, it will overwrite the active configurations that are in use by the service.
 *
 * The read function and the @ref Nvm loading function are also exposed through the coordsys FIDL file, named `coordsys.fidl`. For a better user experience, the read function is separated into
 * individual functions for each frame type, eliminating the need for the user to input the frame type.
 *
 * ## Writing new frame configurations
 * The currently active configurations for each sensor/actuator type can be changed using the **coordsys_set_frame()** function.
 * The input parameters are the frame type to be set (@ref coordsys_frame_type_t) and a variable to hold the desired new configuration (coordsys_frame_t) for the specific sensor/actuator.
 *
 * The function **coordsys_save_config_to_nvm()** will save the current coordinate frame configurations to the non-volatile memory (@ref Nvm). This will overwrite the previous configurations stored in the @ref Nvm
 * and will result in the new configurations being automatically loaded during subsequent initialization procedures.
 *
 * The set function and the @ref Nvm save function are also exposed through the coordsys FIDL file, named `coordsys.fidl`. For a better user experience, the set function is separated into
 * individual functions for each frame type, eliminating the need for the user to input the frame type.
 *
 * ## Error reporting
 * The coordsys service has the capability to report errors that occur during operation. Most of the time, it will report errors related to the configuration of new frames, as there is an internal validation step
 * for each new frame that will guarantee that the rotation/mapping matrix will be uniquely mapped. The service has a general status struct that has basic error reporting simplified to OK/FAIL and it has an entry for each frame type (coordsys_status_t).
 * Each frame type has its' own error reporting structure with more detailed information about what has happened to prevent normal operation (coordsys_frame_status_t). This information is represented by the @ref coordsys_error_t enumeration.
 *
 * Within the SDK, the function to retrieve the general status is coordsys_get_status(), while the function to retrieve individual frame status information is coordsys_get_status_frame() with a parameter of type @ref coordsys_frame_type_t that will
 * determine which frame status is returned.
 *
 * On every load of configurations from the @ref Nvm, the data is also validated. In case of corruption of @ref Nvm data, the general status (coordsys_status_t) will signal this in the `general_error` member. This status cannot be reset until the configuration within the
 * @ref Nvm is fixed. This can happen by individually going through all active frame types and making sure that they are all correct, followed by saving the active configuration to @ref Nvm using coordsys_save_config_to_nvm().
 * Upon resolution of the corrupted configuration, the status will automatically clear, along with the per-frame status flags, upon the next load of data from @ref Nvm or the next initialization of the coordsys service.
 *
 * The `coordsys.fidl` file contains functions for reading the general status and individual frame status flags. For ease of use by the user, the per-frame status function coordsys_get_status_frame() is split into multiple
 * frame-specific `get_status_...` functions that will not require the user to input frame type.
 *
 * ## Examples of usage
 * ### Transform gyroscope data.
 * @code {.c}
 * if (false == coordsys_init())
 * {
 *     // Your error handling code here
 * }
 *
 * // Example gyroscope data in the sensor frame
 * const double gyro_data_sensor_frame[3] = {1.0, 2.0, 3.0};
 * double gyro_data_body_frame[3] = {0};
 *
 * // Transform gyroscope data from sensor frame to body frame
 * if (false == coordsys_transform_gyr(gyro_data_sensor_frame, gyro_data_body_frame))
 * {
 *     // Your error handling code here
 * }
 *
 * // Your normal information handling logic here
 *
 * @endcode
 *
 * ### Get magnetometer frame.
 * @code {.c}
 * coordsys_frame_type_t magnetometer_frame;
 *
 * // Retrieve the currently active magnetometer frame configuration
 * if (false == coordsys_get_frame(FRAME_MAGNETOMETER, &magnetometer_frame))
 * {
 *     // Your error handling code here
 * }
 *
 * // Your normal information handling logic here
 *
 * @endcode
 *
 * ### Set gyroscope frame.
 * @code {.c}
 * // Define a new gyroscope frame configuration
 * coordsys_frame_type_t new_gyr_frame = {
 *     SAT_Z_AXIS_POSITIVE, // Gyroscope 1 is mounted on the Z+ body (satellite) frame axis
 *     SAT_Y_AXIS_NEGATIVE, // Gyroscope 2 is mounted on the Y- body (satellite) frame axis
 *     SAT_X_AXIS_POSITIVE  // Gyroscope 3 is mounted on the X+ body (satellite) frame axis
 * };
 *
 * // Set the new gyroscope frame configuration
 * if (false == coordsys_set_frame(FRAME_GYROSCOPE, &new_gyr_frame))
 * {
 *     // Your error handling code here
 * }
 *
 * // Your normal information handling logic here
 *
 * @endcode
 *
 * ### Set coarse sun sensor frame.
 * @code {.c}
 * // Define a new coarse sun sensor frame configuration
 * coordsys_css_frame_t new_css_frame = {
 *     SAT_Z_AXIS_POSITIVE, // Coarse sun sensor 1 is mounted on the Z+ body (satellite) frame axis
 *     SAT_Y_AXIS_NEGATIVE, // Coarse sun sensor 2 is mounted on the Y- body (satellite) frame axis
 *     SAT_X_AXIS_POSITIVE, // Coarse sun sensor 3 is mounted on the X+ body (satellite) frame axis
 *     SAT_X_AXIS_NEGATIVE, // Coarse sun sensor 4 is mounted on the X+ body (satellite) frame axis
 *     SAT_Z_AXIS_NEGATIVE, // Coarse sun sensor 5 is mounted on the Z- body (satellite) frame axis
 *     SAT_Y_AXIS_POSITIVE  // Coarse sun sensor 6 is mounted on the Y+ body (satellite) frame axis
 * };
 *
 * // Set the new coarse sun sensor frame configuration
 * if (false == coordsys_set_frame(FRAME_COARSE_SUN_SENSOR, &new_css_frame))
 * {
 *     // Your error handling code here
 * }
 *
 * // Your normal information handling logic here
 *
 * @endcode
 *
 * @file   coordsys.h
 * @brief  Coordinate system transformation service header file
 *
 * @}
 * @}
 */

#include <stdbool.h>
#include "coordsys_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
/* No External defines */

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/
/* No External types declarations */

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
/** @brief Initializes all coordinate frames
 *  @return bool - 1(true) for success, 0(false) for fail */
bool coordsys_init(void);

/** @brief Retrieve the general status for the whole coordsys service
 *  @return coordsys_status_t - struct with status for each frame, simplified to OK/FAIL */
coordsys_status_t coordsys_get_status(void);

/** @brief Retrieve the status of a specific frame
 *  @param[in] const coordsys_frame_type_t frame_type - the frame type for which the status is retrieved
 *  @return          coordsys_frame_status_t          - struct with specific frame status */
coordsys_frame_status_t coordsys_get_status_frame(const coordsys_frame_type_t frame_type);

/** @brief Transforms gyroscope data (angles, rates) to body frame
 *  @param[in]  const double * const p_input_data  - pointer to array with gyroscope data in sensor frame
 *  @param[out]       double * const p_output_data - pointer to array with gyroscope data in body frame */
void coordsys_transform_gyr(const double *const p_input_data, double *const p_output_data);

/** @brief Transforms magnetometer data to body frame
 *  @param[in]  const double * const p_input_data  - pointer to array with magnetometer data in sensor frame
 *  @param[out]       double * const p_output_data - pointer to array with magnetometer data in body frame */
void coordsys_transform_mag(const double *const p_input_data, double *const p_output_data);

/** @brief Transforms coarse sun sensor (photosensor) data to body frame
 *  @param[in]  const int32_t * const p_input_data  - pointer to array with coarse sun sensor data in sensor frame
 *  @param[out]       int32_t * const p_output_data - pointer to array with coarse sun sensor data in body frame */
void coordsys_transform_css(const int32_t *const p_input_data, int32_t *const p_output_data);

/** @brief Transforms magnetorquer control values from body frame to actuator frame
 *  @param[in]  const int8_t * const p_input_data  - pointer to array with magnetorquer data in body frame
 *  @param[out]       int8_t * const p_output_data - pointer to array with magnetorquer data in actuator frame */
void coordsys_transform_mtq(const int8_t *const p_input_data, int8_t *const p_output_data);

/** @brief Transforms panel temperature data to body frame. This makes a call to coordsys_transform_css
 *         as the CSS and temperature sensors are mounted on the same sides
 *  @param[in]  const double * const p_input_data  - pointer to array with panel temperature data in sensor frame
 *  @param[out]       double * const p_output_data - pointer to array with panel temperature data in satellite frame */
void coordsys_transform_panel_temp(const double *const p_input_data, double *const p_output_data);

/** @brief Transforms gyro temperature data to body frame. This makes a call to coordsys_transform_gyr as
 *         it is the same gyroscope
 *  @param[in]  const double * const p_input_data  - pointer to array with panel temperature data in sensor frame
 *  @param[out]       double * const p_output_data - pointer to array with panel temperature data in body frame */
void coordsys_transform_gyro_temp(const double *const p_input_data, double *const p_output_data);

/** @brief Set a coordinate frame
 *  @param[in] const coordsys_frame_type_t         frame_type   - the frame type that is to be configured
 *  @param[in] const coordsys_frame_t      * const p_new_frame  - pointer to the desired frame configuration to be applied
 *  @return          bool                                       - 1(true) for success, 0(false) for fail */
bool coordsys_set_frame(const coordsys_frame_type_t frame_type, const coordsys_frame_t *const p_new_frame);

/** @brief Get a coordinate frame
 *  @param[in] const coordsys_frame_type_t         frame_type     - the frame type that is to be retrieved
 *  @param[in]       coordsys_frame_t      * const p_active_frame - pointer to the currently active frame configuration */
void coordsys_get_frame(const coordsys_frame_type_t frame_type, coordsys_frame_t *const p_active_frame);

/** @brief Save the current coordinate frames configuration to nvm */
void coordsys_save_config_to_nvm(void);

/** @brief Load the current coordinate frames configuration from nvm */
void coordsys_load_config_from_nvm(void);

#ifdef __cplusplus
}
#endif

#endif /* COORDSYS_H_ */
