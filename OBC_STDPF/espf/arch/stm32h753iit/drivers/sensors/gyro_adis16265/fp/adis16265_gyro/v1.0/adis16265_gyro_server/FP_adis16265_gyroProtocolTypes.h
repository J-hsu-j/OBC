/*!
********************************************************************************************
* @file FP_adis16265_gyroProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface adis16265_gyro v1.0
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

#ifndef FP_ADIS16265_GYROPROTOCOLTYPES_H
#define FP_ADIS16265_GYROPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_ADIS16265_GYRO ((uint16_t) (0x00000048))

#define ADIS16265_GYRO_SET_GYROSCOPE_CONFIG_FUNC_ID ((funcIdType_t) 0x00000001)
#define ADIS16265_GYRO_GET_GYROSCOPE_CONFIG_FUNC_ID ((funcIdType_t) 0x00000002)
#define ADIS16265_GYRO_SAVE_GYROSCOPE_CONFIG_FUNC_ID ((funcIdType_t) 0x00000003)
#define ADIS16265_GYRO_LOAD_GYROSCOPE_CONFIG_FUNC_ID ((funcIdType_t) 0x00000004)
#define ADIS16265_GYRO_SET_GYROSCOPE_CONFIG_FUNCRESP_ID ((funcIdType_t) 0x00000001)
#define ADIS16265_GYRO_GET_GYROSCOPE_CONFIG_FUNCRESP_ID ((funcIdType_t) 0x00000002)
#define ADIS16265_GYRO_SAVE_GYROSCOPE_CONFIG_FUNCRESP_ID ((funcIdType_t) 0x00000003)
#define ADIS16265_GYRO_LOAD_GYROSCOPE_CONFIG_FUNCRESP_ID ((funcIdType_t) 0x00000004)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    This corresponds to enum Panel_Number_t from panels.h
*/
#define ADIS16265_GYRO_PANEL_ONE ((uint8_t) 1)
#define ADIS16265_GYRO_PANEL_TWO ((uint8_t) 2)
#define ADIS16265_GYRO_PANEL_THREE ((uint8_t) 3)
#define ADIS16265_GYRO_PANEL_FOUR ((uint8_t) 4)
#define ADIS16265_GYRO_PANEL_FIVE ((uint8_t) 5)
#define ADIS16265_GYRO_PANEL_SIX ((uint8_t) 6)
#define ADIS16265_GYRO_PANEL_MAX_CNT  ((uint8_t) 7)
typedef uint8_t ADIS16265_GYRO_Panel_t;

/*
    Result of operation
*/
#define ADIS16265_GYRO_RESULT_OK ((uint8_t) 0)
#define ADIS16265_GYRO_RESULT_FAIL ((uint8_t) 1)
#define ADIS16265_GYRO_RESULT_MAX_CNT  ((uint8_t) 2)
typedef uint8_t ADIS16265_GYRO_Result_t;


typedef struct {
    ADIS16265_GYRO_Panel_t eGyroscope_1;
    ADIS16265_GYRO_Panel_t eGyroscope_2;
    ADIS16265_GYRO_Panel_t eGyroscope_3;
} PACKED_STRUCT adis16265_gyroset_gyroscope_configRequestData_t;


typedef struct {
    ADIS16265_GYRO_Result_t eOp_result;
} PACKED_STRUCT adis16265_gyroset_gyroscope_configResponseData_t;

typedef struct {
    ADIS16265_GYRO_Panel_t eGyroscope_1;
    ADIS16265_GYRO_Panel_t eGyroscope_2;
    ADIS16265_GYRO_Panel_t eGyroscope_3;
    ADIS16265_GYRO_Result_t eOp_result;
} PACKED_STRUCT adis16265_gyroget_gyroscope_configResponseData_t;

typedef struct {
    ADIS16265_GYRO_Result_t eOp_result;
} PACKED_STRUCT adis16265_gyrosave_gyroscope_configResponseData_t;

typedef struct {
    ADIS16265_GYRO_Result_t eOp_result;
} PACKED_STRUCT adis16265_gyroload_gyroscope_configResponseData_t;


#endif  // #ifndef FP_ADIS16265_GYROPROTOCOLTYPES_H

