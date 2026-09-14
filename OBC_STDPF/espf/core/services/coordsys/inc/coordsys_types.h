/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef COORDSYS_TYPES_H_
#define COORDSYS_TYPES_H_

/**
 * @addtogroup coordsys
 * @{
 *
 * @file   coordsys_types.h
 * @brief  Coordinate System Transformation service types file
 *
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
/* No External defines */

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/
/** @brief General coordsys service result enum */
typedef enum
{
    COORDSYS_RESULT_OK,  /**< Operation was successful */
    COORDSYS_RESULT_FAIL /**< Operation has failed */
    // extend when needed
} coordsys_result_t;

/** @brief Satellite axes enum */
typedef enum
{
    SAT_X_AXIS_POSITIVE, /**< Body (satellite) frame positive X axis */
    SAT_Y_AXIS_POSITIVE, /**< Body (satellite) frame positive Y axis */
    SAT_Z_AXIS_POSITIVE, /**< Body (satellite) frame positive Z axis */
    SAT_X_AXIS_NEGATIVE, /**< Body (satellite) frame negative X axis */
    SAT_Y_AXIS_NEGATIVE, /**< Body (satellite) frame negative Y axis */
    SAT_Z_AXIS_NEGATIVE  /**< Body (satellite) frame negative Z axis */
} coordsys_satellite_axis_t;

/** @brief Frame type - could be different sensors or different actuators */
typedef enum
{
    FRAME_GYROSCOPE,         /**< The gyroscope rotation/mapping matrix enumeration */
    FRAME_MAGNETOMETER,      /**< The magnetometer rotation/mapping matrix enumeration */
    FRAME_COARSE_SUN_SENSOR, /**< The coarse sun sensor rotation/mapping matrix enumeration */
    FRAME_MAGNETORQUER,      /**< The magnetorquer rotation/mapping matrix enumeration */
    FRAME_COUNT
} coordsys_frame_type_t;

/** @brief Error codes for the coordsys service */
typedef enum
{
    ERROR_NONE,                   /**< No error during operation */
    ERROR_NVM_CONFIG_CORRUPTED,   /**< The nvm configuration has failed the validation step */
    ERROR_FRAME_TYPE_INVALID,     /**< The frame type given to an operation is invalid */
    ERROR_SATELLITE_AXIS_INVALID, /**< The satellite axis given to an operation is invalid */
    ERROR_ELEMENT_OUT_OF_RANGE,   /**< An element of a rotation/mapping matrix is outside the expected value range */
    ERROR_INVALID_ROW_OR_COLUMN,  /**< A column or row of a rotation/mapping matrix has failed the validation step */
    ERROR_COUNT
} coordsys_error_t;

/** @brief Status of the individual components/frames */
typedef struct
{
    coordsys_error_t status_1; /**< The first error code for the frame */
    coordsys_error_t status_2; /**< The second error code for the frame */
} coordsys_frame_status_t;

/** @brief Status of the coordsys service. Each coordinate frame has its own status entry */
typedef struct
{
    coordsys_result_t gyroscope_frame;         /**< The status code for the gyroscope frame */
    coordsys_result_t magnetometer_frame;      /**< The status code for the magnetometer frame */
    coordsys_result_t coarse_sun_sensor_frame; /**< The status code for the coarse sun sensor frame */
    coordsys_result_t magnetorquer_frame;      /**< The status code for the magnetorquer frame */
    coordsys_error_t  general_error;           /**< The status code for any errors that are general to the coordsys service and not to a specific frame (e.g. state machine out of bounds) */
} coordsys_status_t;

/** @brief General rotation/mapping frame. Some sensors/actuators may not have all the axes, which will be taken care of in the builder functions */
typedef struct
{
    coordsys_satellite_axis_t frame_axis_1; /**< Which satellite axis does the first sensor/actuator axis correspond to */
    coordsys_satellite_axis_t frame_axis_2; /**< Which satellite axis does the second sensor/actuator axis correspond to */
    coordsys_satellite_axis_t frame_axis_3; /**< Which satellite axis does the third sensor/actuator axis correspond to */
    coordsys_satellite_axis_t frame_axis_4; /**< Which satellite axis does the fourth sensor/actuator axis correspond to */
    coordsys_satellite_axis_t frame_axis_5; /**< Which satellite axis does the fifth sensor/actuator axis correspond to */
    coordsys_satellite_axis_t frame_axis_6; /**< Which satellite axis does the sixth sensor/actuator axis correspond to */
} coordsys_frame_t;

/** @brief All sensor/actuator frames */
typedef struct
{
    coordsys_frame_t gyroscope_frame;         /**< Gyroscope frame */
    coordsys_frame_t magnetometer_frame;      /**< Magnetometer frame */
    coordsys_frame_t coarse_sun_sensor_frame; /**< Coarse Sun Sensor frame */
    coordsys_frame_t magnetorquer_frame;      /**< Magnetorquer frame */
    uint32_t         u32Crc;
} coordsys_frames_t;

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
/* No External routines declarations */

#ifdef __cplusplus
}
#endif

#endif /* COORDSYS_TYPES_H_ */
