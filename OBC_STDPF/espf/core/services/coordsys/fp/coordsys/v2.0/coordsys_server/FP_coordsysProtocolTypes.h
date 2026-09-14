/*!
********************************************************************************************
* @file FP_coordsysProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface coordsys v2.0
*
* @copyright         (C) Copyright EnduroSat
*
*                    Contents and presentations are protected world-wide.
*                    Any kind of using, copying etc. is prohibited without prior permission.
*                    All rights - incl. industrial property rights - are reserved.
*
*-------------------------------------------------------------------------------------------
* GENERATOR: org.endurosat.generators.macchiato.binders.Gen_C v2.15
*-------------------------------------------------------------------------------------------
* !!! Please note that this code is fully GENERATED and shall not be manually modified as
* all changes will be overwritten !!!
********************************************************************************************
*/

#ifndef FP_COORDSYSPROTOCOLTYPES_H
#define FP_COORDSYSPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_COORDSYS ((uint16_t) (0x00000044))

#define COORDSYS_GET_STATUS_FUNC_ID ((funcIdType_t) 0x00000001)
#define COORDSYS_SET_GYROSCOPE_FRAME_FUNC_ID ((funcIdType_t) 0x00000002)
#define COORDSYS_GET_GYROSCOPE_FRAME_FUNC_ID ((funcIdType_t) 0x00000003)
#define COORDSYS_GET_GYROSCOPE_FRAME_STATUS_FUNC_ID ((funcIdType_t) 0x00000004)
#define COORDSYS_SET_MAGNETOMETER_FRAME_FUNC_ID ((funcIdType_t) 0x00000005)
#define COORDSYS_GET_MAGNETOMETER_FRAME_FUNC_ID ((funcIdType_t) 0x00000006)
#define COORDSYS_GET_MAGNETOMETER_FRAME_STATUS_FUNC_ID ((funcIdType_t) 0x00000007)
#define COORDSYS_SET_COARSE_SUN_SENSOR_FRAME_FUNC_ID ((funcIdType_t) 0x00000008)
#define COORDSYS_GET_COARSE_SUN_SENSOR_FRAME_FUNC_ID ((funcIdType_t) 0x00000009)
#define COORDSYS_GET_COARSE_SUN_SENSOR_FRAME_STATUS_FUNC_ID ((funcIdType_t) 0x0000000A)
#define COORDSYS_SET_MAGNETORQUER_FRAME_FUNC_ID ((funcIdType_t) 0x0000000E)
#define COORDSYS_GET_MAGNETORQUER_FRAME_FUNC_ID ((funcIdType_t) 0x0000000F)
#define COORDSYS_GET_MAGNETORQUER_FRAME_STATUS_FUNC_ID ((funcIdType_t) 0x00000010)
#define COORDSYS_SAVE_COORDSYS_CONFIG_FUNC_ID ((funcIdType_t) 0x00000011)
#define COORDSYS_LOAD_COORDSYS_CONFIG_FUNC_ID ((funcIdType_t) 0x00000012)
#define COORDSYS_GET_STATUS_FUNCRESP_ID ((funcIdType_t) 0x00000001)
#define COORDSYS_SET_GYROSCOPE_FRAME_FUNCRESP_ID ((funcIdType_t) 0x00000002)
#define COORDSYS_GET_GYROSCOPE_FRAME_FUNCRESP_ID ((funcIdType_t) 0x00000003)
#define COORDSYS_GET_GYROSCOPE_FRAME_STATUS_FUNCRESP_ID ((funcIdType_t) 0x00000004)
#define COORDSYS_SET_MAGNETOMETER_FRAME_FUNCRESP_ID ((funcIdType_t) 0x00000005)
#define COORDSYS_GET_MAGNETOMETER_FRAME_FUNCRESP_ID ((funcIdType_t) 0x00000006)
#define COORDSYS_GET_MAGNETOMETER_FRAME_STATUS_FUNCRESP_ID ((funcIdType_t) 0x00000007)
#define COORDSYS_SET_COARSE_SUN_SENSOR_FRAME_FUNCRESP_ID ((funcIdType_t) 0x00000008)
#define COORDSYS_GET_COARSE_SUN_SENSOR_FRAME_FUNCRESP_ID ((funcIdType_t) 0x00000009)
#define COORDSYS_GET_COARSE_SUN_SENSOR_FRAME_STATUS_FUNCRESP_ID ((funcIdType_t) 0x0000000A)
#define COORDSYS_SET_MAGNETORQUER_FRAME_FUNCRESP_ID ((funcIdType_t) 0x0000000E)
#define COORDSYS_GET_MAGNETORQUER_FRAME_FUNCRESP_ID ((funcIdType_t) 0x0000000F)
#define COORDSYS_GET_MAGNETORQUER_FRAME_STATUS_FUNCRESP_ID ((funcIdType_t) 0x00000010)
#define COORDSYS_SAVE_COORDSYS_CONFIG_FUNCRESP_ID ((funcIdType_t) 0x00000011)
#define COORDSYS_LOAD_COORDSYS_CONFIG_FUNCRESP_ID ((funcIdType_t) 0x00000012)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    This corresponds to enum coordsys_error_t
*/
#define COORDSYS_ERROR_NONE ((uint8_t) 0)
#define COORDSYS_ERROR_NVM_CONFIG_CORRUPTED ((uint8_t) 1)
#define COORDSYS_ERROR_FRAME_TYPE_INVALID ((uint8_t) 2)
#define COORDSYS_ERROR_SATELLITE_AXIS_INVALID ((uint8_t) 3)
#define COORDSYS_ERROR_ELEMENT_OUT_OF_RANGE ((uint8_t) 4)
#define COORDSYS_ERROR_INVALID_ROW_OR_COLUMN ((uint8_t) 5)
#define COORDSYS_ERROR_MAX_CNT  ((uint8_t) 6)
typedef uint8_t COORDSYS_Error_t;

/*
    This corresponds to enum coordsys_satellite_axis_t
*/
#define COORDSYS_SATELLITEAXIS_X_POSITIVE ((uint8_t) 0)
#define COORDSYS_SATELLITEAXIS_Y_POSITIVE ((uint8_t) 1)
#define COORDSYS_SATELLITEAXIS_Z_POSITIVE ((uint8_t) 2)
#define COORDSYS_SATELLITEAXIS_X_NEGATIVE ((uint8_t) 3)
#define COORDSYS_SATELLITEAXIS_Y_NEGATIVE ((uint8_t) 4)
#define COORDSYS_SATELLITEAXIS_Z_NEGATIVE ((uint8_t) 5)
#define COORDSYS_SATELLITEAXIS_MAX_CNT  ((uint8_t) 6)
typedef uint8_t COORDSYS_SatelliteAxis_t;

/*
    Result of operation
*/
#define COORDSYS_RESULT_ES_OK ((uint8_t) 0)
#define COORDSYS_RESULT_ES_FAIL ((uint8_t) 1)
#define COORDSYS_RESULT_MAX_CNT  ((uint8_t) 2)
typedef uint8_t COORDSYS_Result_t;

/*
    This corresponds to struct coordsys_frame_status_t
*/
typedef struct {
    COORDSYS_Error_t eStatus_1;
    COORDSYS_Error_t eStatus_2;
} PACKED_STRUCT COORDSYS_FrameStatus_t;

/*
    This corresponds to a half of the struct coordsys_frame_t due to the magnetorquer transformation being a 3D mapping instead of a full 6D mapping
*/
typedef struct {
    COORDSYS_SatelliteAxis_t eMagnetorquer_1;
    COORDSYS_SatelliteAxis_t eMagnetorquer_2;
    COORDSYS_SatelliteAxis_t eMagnetorquer_3;
} PACKED_STRUCT COORDSYS_MagnetorquerFrame_t;

/*
    This corresponds to a half of the struct coordsys_frame_t due to the gyroscope transformation being a 3D mapping instead of a full 6D mapping
*/
typedef struct {
    COORDSYS_SatelliteAxis_t eGyroscope_1;
    COORDSYS_SatelliteAxis_t eGyroscope_2;
    COORDSYS_SatelliteAxis_t eGyroscope_3;
} PACKED_STRUCT COORDSYS_GyroscopeFrame_t;

/*
    This corresponds to the full struct coordsys_frame_t due to the coarse sun sensor transformation being a full 6D mapping
*/
typedef struct {
    COORDSYS_SatelliteAxis_t eCoarse_sun_sensor_1;
    COORDSYS_SatelliteAxis_t eCoarse_sun_sensor_2;
    COORDSYS_SatelliteAxis_t eCoarse_sun_sensor_3;
    COORDSYS_SatelliteAxis_t eCoarse_sun_sensor_4;
    COORDSYS_SatelliteAxis_t eCoarse_sun_sensor_5;
    COORDSYS_SatelliteAxis_t eCoarse_sun_sensor_6;
} PACKED_STRUCT COORDSYS_CoarseSunSensorFrame_t;

/*
    This corresponds to a half of the struct coordsys_frame_t due to the magnetometer transformation being a 3D mapping instead of a full 6D mapping
*/
typedef struct {
    COORDSYS_SatelliteAxis_t eMagnetometer_x;
    COORDSYS_SatelliteAxis_t eMagnetometer_y;
    COORDSYS_SatelliteAxis_t eMagnetometer_z;
} PACKED_STRUCT COORDSYS_MagnetometerFrame_t;

/*
    This corresponds to struct coordsys_status_t
*/
typedef struct {
    COORDSYS_Result_t eGyroscope_frame;
    COORDSYS_Result_t eMagnetometer_frame;
    COORDSYS_Result_t eCoarse_sun_sensor_frame;
    COORDSYS_Result_t eMagnetorquer_frame;
    COORDSYS_Error_t eGeneral_error;
} PACKED_STRUCT COORDSYS_Status_t;


typedef struct {
    COORDSYS_GyroscopeFrame_t sDesired_gyr_frame;
} PACKED_STRUCT coordsysset_gyroscope_frameRequestData_t;

typedef struct {
    COORDSYS_MagnetometerFrame_t sDesired_mag_frame;
} PACKED_STRUCT coordsysset_magnetometer_frameRequestData_t;

typedef struct {
    COORDSYS_CoarseSunSensorFrame_t sDesired_css_frame;
} PACKED_STRUCT coordsysset_coarse_sun_sensor_frameRequestData_t;

typedef struct {
    COORDSYS_MagnetorquerFrame_t sDesired_mtq_frame;
} PACKED_STRUCT coordsysset_magnetorquer_frameRequestData_t;


typedef struct {
    COORDSYS_Status_t sService_status;
    COORDSYS_Result_t eOp_result;
} PACKED_STRUCT coordsysget_statusResponseData_t;

typedef struct {
    COORDSYS_Result_t eOp_result;
} PACKED_STRUCT coordsysset_gyroscope_frameResponseData_t;

typedef struct {
    COORDSYS_GyroscopeFrame_t sActive_gyr_frame;
    COORDSYS_Result_t eOp_result;
} PACKED_STRUCT coordsysget_gyroscope_frameResponseData_t;

typedef struct {
    COORDSYS_FrameStatus_t sGyr_frame_status;
    COORDSYS_Result_t eOp_result;
} PACKED_STRUCT coordsysget_gyroscope_frame_statusResponseData_t;

typedef struct {
    COORDSYS_Result_t eOp_result;
} PACKED_STRUCT coordsysset_magnetometer_frameResponseData_t;

typedef struct {
    COORDSYS_MagnetometerFrame_t sActive_mag_frame;
    COORDSYS_Result_t eOp_result;
} PACKED_STRUCT coordsysget_magnetometer_frameResponseData_t;

typedef struct {
    COORDSYS_FrameStatus_t sMag_frame_status;
    COORDSYS_Result_t eOp_result;
} PACKED_STRUCT coordsysget_magnetometer_frame_statusResponseData_t;

typedef struct {
    COORDSYS_Result_t eOp_result;
} PACKED_STRUCT coordsysset_coarse_sun_sensor_frameResponseData_t;

typedef struct {
    COORDSYS_CoarseSunSensorFrame_t sActive_css_frame;
    COORDSYS_Result_t eOp_result;
} PACKED_STRUCT coordsysget_coarse_sun_sensor_frameResponseData_t;

typedef struct {
    COORDSYS_FrameStatus_t sCss_frame_status;
    COORDSYS_Result_t eOp_result;
} PACKED_STRUCT coordsysget_coarse_sun_sensor_frame_statusResponseData_t;

typedef struct {
    COORDSYS_Result_t eOp_result;
} PACKED_STRUCT coordsysset_magnetorquer_frameResponseData_t;

typedef struct {
    COORDSYS_MagnetorquerFrame_t sActive_mtq_frame;
    COORDSYS_Result_t eOp_result;
} PACKED_STRUCT coordsysget_magnetorquer_frameResponseData_t;

typedef struct {
    COORDSYS_FrameStatus_t sMtq_frame_status;
    COORDSYS_Result_t eOp_result;
} PACKED_STRUCT coordsysget_magnetorquer_frame_statusResponseData_t;

typedef struct {
    COORDSYS_Result_t eOp_result;
} PACKED_STRUCT coordsyssave_coordsys_configResponseData_t;

typedef struct {
    COORDSYS_Result_t eOp_result;
} PACKED_STRUCT coordsysload_coordsys_configResponseData_t;


#endif  // #ifndef FP_COORDSYSPROTOCOLTYPES_H

