/*!
********************************************************************************************
* @file FP_acsProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface acs v1.2
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

#ifndef FP_ACSPROTOCOLTYPES_H
#define FP_ACSPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_ACS ((uint16_t) (0x00000046))

#define ACS_SET_OP_MODE_FUNC_ID ((funcIdType_t) 0x00000001)
#define ACS_GET_OP_MODE_FUNC_ID ((funcIdType_t) 0x00000002)
#define ACS_GET_STATUS_FUNC_ID ((funcIdType_t) 0x00000003)
#define ACS_SET_MANUAL_MTQ_CONTROL_FUNC_ID ((funcIdType_t) 0x00000004)
#define ACS_GET_MANUAL_MTQ_CONTROL_FUNC_ID ((funcIdType_t) 0x00000005)
#define ACS_GET_LAST_MTQ_CONTROL_FUNC_ID ((funcIdType_t) 0x00000006)
#define ACS_SET_OP_MODE_FUNCRESP_ID ((funcIdType_t) 0x00000001)
#define ACS_GET_OP_MODE_FUNCRESP_ID ((funcIdType_t) 0x00000002)
#define ACS_GET_STATUS_FUNCRESP_ID ((funcIdType_t) 0x00000003)
#define ACS_SET_MANUAL_MTQ_CONTROL_FUNCRESP_ID ((funcIdType_t) 0x00000004)
#define ACS_GET_MANUAL_MTQ_CONTROL_FUNCRESP_ID ((funcIdType_t) 0x00000005)
#define ACS_GET_LAST_MTQ_CONTROL_FUNCRESP_ID ((funcIdType_t) 0x00000006)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    This corresponds to enum acs_warning_t
*/
#define ACS_WARNING_ES_NONE ((uint8_t) 0)
#define ACS_WARNING_ES_SATURATION_UPPER ((uint8_t) 1)
#define ACS_WARNING_ES_SATURATION_LOWER ((uint8_t) 2)
#define ACS_WARNING_MAX_CNT  ((uint8_t) 3)
typedef uint8_t ACS_Warning_t;

/*
    This corresponds to enum acs_state_t
*/
#define ACS_STATE_ES_RUN ((uint8_t) 0)
#define ACS_STATE_ES_MANUAL ((uint8_t) 1)
#define ACS_STATE_ES_STOPPED ((uint8_t) 2)
#define ACS_STATE_MAX_CNT  ((uint8_t) 3)
typedef uint8_t ACS_State_t;

/*
    Holds the last commanded MTQ values (in Body Frame and Actuator Frame) that were sent to the physical magnetorquers
*/
typedef struct {
    int8_t i8Mtq_x_body_frame;
    int8_t i8Mtq_y_body_frame;
    int8_t i8Mtq_z_body_frame;
    int8_t i8Mtq_x_mtq_frame;
    int8_t i8Mtq_y_mtq_frame;
    int8_t i8Mtq_z_mtq_frame;
} PACKED_STRUCT ACS_LastMtqData_t;

/*
    This corresponds to enum acs_error_t
*/
#define ACS_ERROR_ES_NONE ((uint8_t) 0)
#define ACS_ERROR_ES_DATA_CACHE_GET ((uint8_t) 1)
#define ACS_ERROR_ES_MATH_FAILED ((uint8_t) 2)
#define ACS_ERROR_MAX_CNT  ((uint8_t) 3)
typedef uint8_t ACS_Error_t;

/*
    Holds the manually set or retrieved MTQ values (in Actuator Frame)
*/
typedef struct {
    int8_t i8Mtq_1_mtq_frame;
    int8_t i8Mtq_2_mtq_frame;
    int8_t i8Mtq_3_mtq_frame;
} PACKED_STRUCT ACS_ManualMtqData_t;

/*
    Result of operation
*/
#define ACS_RESULT_ES_OK ((uint8_t) 0)
#define ACS_RESULT_ES_FAIL ((uint8_t) 1)
#define ACS_RESULT_MAX_CNT  ((uint8_t) 2)
typedef uint8_t ACS_Result_t;

/*
    This corresponds to struct acs_status_t
*/
typedef struct {
    ACS_Warning_t eLast_warning;
    ACS_Error_t eLast_error;
    ACS_State_t eActive_state;
} PACKED_STRUCT ACS_Status_t;


typedef struct {
    ACS_State_t eDesired_mode;
} PACKED_STRUCT acsset_op_modeRequestData_t;

typedef struct {
    ACS_ManualMtqData_t sDesired_manual_magnetorquer_control_values;
} PACKED_STRUCT acsset_manual_mtq_controlRequestData_t;


typedef struct {
    ACS_Result_t eOp_result;
} PACKED_STRUCT acsset_op_modeResponseData_t;

typedef struct {
    ACS_State_t eActive_mode;
    ACS_Result_t eOp_result;
} PACKED_STRUCT acsget_op_modeResponseData_t;

typedef struct {
    ACS_Status_t sCurrent_status;
    ACS_Result_t eOp_result;
} PACKED_STRUCT acsget_statusResponseData_t;

typedef struct {
    ACS_Result_t eOp_result;
} PACKED_STRUCT acsset_manual_mtq_controlResponseData_t;

typedef struct {
    ACS_ManualMtqData_t sManual_magnetorquer_control_values;
    ACS_Result_t eOp_result;
} PACKED_STRUCT acsget_manual_mtq_controlResponseData_t;

typedef struct {
    ACS_LastMtqData_t sLast_magnetorquer_control_values;
    ACS_Result_t eOp_result;
} PACKED_STRUCT acsget_last_mtq_controlResponseData_t;


#endif  // #ifndef FP_ACSPROTOCOLTYPES_H

