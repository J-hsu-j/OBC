
#ifndef FP_CONOPSPROTOCOLTYPES_H
#define FP_CONOPSPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_CONOPS ((uint16_t) (0x00000010))

#define CONOPS_SEND_NEW_EVENT_FUNC_ID ((funcIdType_t) 0x00000000)
#define CONOPS_GET_OP_MODE_FUNC_ID ((funcIdType_t) 0x00000001)
#define CONOPS_SET_THRESH_VAL_FUNC_ID ((funcIdType_t) 0x00000002)
#define CONOPS_GET_THRESH_VAL_FUNC_ID ((funcIdType_t) 0x00000003)
#define CONOPS_SET_ALL_THRESH_VAL_FUNC_ID ((funcIdType_t) 0x00000004)
#define CONOPS_GET_ALL_THRESH_VAL_FUNC_ID ((funcIdType_t) 0x00000005)
#define CONOPS_REQUEST_MISSION_MODE_ENTER_FUNC_ID ((funcIdType_t) 0x00000006)
#define CONOPS_REQUEST_MISSION_MODE_EXIT_FUNC_ID ((funcIdType_t) 0x00000007)
#define CONOPS_GET_DEFAULT_CONTROL_MODE_FUNC_ID ((funcIdType_t) 0x00000008)
#define CONOPS_SET_DEFAULT_CONTROL_MODE_FUNC_ID ((funcIdType_t) 0x00000009)
#define CONOPS_SET_FORCE_ALLOW_PAYLOADS_FUNC_ID ((funcIdType_t) 0x0000000A)
#define CONOPS_GET_FORCE_ALLOW_PAYLOADS_FUNC_ID ((funcIdType_t) 0x0000000B)
#define CONOPS_SEND_NEW_EVENT_FUNCRESP_ID ((funcIdType_t) 0x00000000)
#define CONOPS_GET_OP_MODE_FUNCRESP_ID ((funcIdType_t) 0x00000001)
#define CONOPS_SET_THRESH_VAL_FUNCRESP_ID ((funcIdType_t) 0x00000002)
#define CONOPS_GET_THRESH_VAL_FUNCRESP_ID ((funcIdType_t) 0x00000003)
#define CONOPS_SET_ALL_THRESH_VAL_FUNCRESP_ID ((funcIdType_t) 0x00000004)
#define CONOPS_GET_ALL_THRESH_VAL_FUNCRESP_ID ((funcIdType_t) 0x00000005)
#define CONOPS_REQUEST_MISSION_MODE_ENTER_FUNCRESP_ID ((funcIdType_t) 0x00000006)
#define CONOPS_REQUEST_MISSION_MODE_EXIT_FUNCRESP_ID ((funcIdType_t) 0x00000007)
#define CONOPS_GET_DEFAULT_CONTROL_MODE_FUNCRESP_ID ((funcIdType_t) 0x00000008)
#define CONOPS_SET_DEFAULT_CONTROL_MODE_FUNCRESP_ID ((funcIdType_t) 0x00000009)
#define CONOPS_SET_FORCE_ALLOW_PAYLOADS_FUNCRESP_ID ((funcIdType_t) 0x0000000A)
#define CONOPS_GET_FORCE_ALLOW_PAYLOADS_FUNCRESP_ID ((funcIdType_t) 0x0000000B)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    The enumeration defines the different threshold types configurable for the ConOps feature
*/
#define CONOPS_THRESHOLDVALUETYPES_DEFAULT ((uint8_t) 0)
#define CONOPS_THRESHOLDVALUETYPES_VBATT_SAFE ((uint8_t) 1)
#define CONOPS_THRESHOLDVALUETYPES_TBATT_SAFE_LOWER ((uint8_t) 2)
#define CONOPS_THRESHOLDVALUETYPES_TBATT_SAFE_UPPER ((uint8_t) 3)
#define CONOPS_THRESHOLDVALUETYPES_ANGVEL_MAX ((uint8_t) 4)
#define CONOPS_THRESHOLDVALUETYPES_ANGVEL_MIN ((uint8_t) 5)
#define CONOPS_THRESHOLDVALUETYPES_ANGVEL_Y_THOMSON_HIGH ((uint8_t) 6)
#define CONOPS_THRESHOLDVALUETYPES_ANGVEL_Y_THOMSON_LOW ((uint8_t) 7)
#define CONOPS_THRESHOLDVALUETYPES_MAX_CNT  ((uint8_t) 8)
typedef uint8_t CONOPS_ThresholdValueTypes_t;

/*
    Defines the set of supported ConOps modes in the system
*/
#define CONOPS_OPMODES_MODE_SAFE ((uint8_t) 1)
#define CONOPS_OPMODES_MODE_SAFE_ENTRY ((uint8_t) 2)
#define CONOPS_OPMODES_MODE_SAFE_CONTROL ((uint8_t) 3)
#define CONOPS_OPMODES_MODE_SAFE_NO_CONTROL ((uint8_t) 4)
#define CONOPS_OPMODES_MODE_IDLE ((uint8_t) 5)
#define CONOPS_OPMODES_MODE_MISSION ((uint8_t) 6)
#define CONOPS_OPMODES_MAX_CNT  ((uint8_t) 7)
typedef uint8_t CONOPS_OpModes_t;

/*
    Contains the threshold settings for the ConOps
*/
typedef struct {
    int32_t i32V_batt_safe;
    int32_t i32T_batt_safe_lower;
    int32_t i32T_batt_safe_upper;
    int32_t i32Ang_vel_max;
    int32_t i32Ang_vel_low;
    int32_t i32Ang_vel_y_thom_high;
    int32_t i32Ang_vel_y_thom_low;
} PACKED_STRUCT CONOPS_ThresholdValues_t;

/*
    Control modes of the AOCS service
*/
#define CONOPS_AOCSSTATE_AOCS_STATE_UNDEFINED ((uint8_t) 0)
#define CONOPS_AOCSSTATE_AOCS_STATE_EXISTING_CONTROL ((uint8_t) 1)
#define CONOPS_AOCSSTATE_AOCS_STATE_NO_CONTROL ((uint8_t) 2)
#define CONOPS_AOCSSTATE_AOCS_STATE_NORMAL_DETUMBLING ((uint8_t) 3)
#define CONOPS_AOCSSTATE_AOCS_STATE_Y_THOMSON ((uint8_t) 4)
#define CONOPS_AOCSSTATE_AOCS_STATE_Y_THOMSON_MEMS_RATE ((uint8_t) 5)
#define CONOPS_AOCSSTATE_AOCS_STATE_FAST_DETUMBLING ((uint8_t) 6)
#define CONOPS_AOCSSTATE_AOCS_STATE_VERY_FAST_DETUMBLING ((uint8_t) 7)
#define CONOPS_AOCSSTATE_AOCS_STATE_Y_MOMENTUM ((uint8_t) 8)
#define CONOPS_AOCSSTATE_AOCS_STATE_Y_MOMENTUM_FULL_STATE_EKF ((uint8_t) 9)
#define CONOPS_AOCSSTATE_AOCS_STATE_3AXIS ((uint8_t) 10)
#define CONOPS_AOCSSTATE_AOCS_STATE_SUN_TRACKING ((uint8_t) 11)
#define CONOPS_AOCSSTATE_AOCS_STATE_TARGET_TRACKING ((uint8_t) 12)
#define CONOPS_AOCSSTATE_AOCS_STATE_USER1 ((uint8_t) 13)
#define CONOPS_AOCSSTATE_AOCS_STATE_USER2 ((uint8_t) 14)
#define CONOPS_AOCSSTATE_AOCS_STATE_USER3 ((uint8_t) 15)
#define CONOPS_AOCSSTATE_MAX_CNT  ((uint8_t) 16)
typedef uint8_t CONOPS_AocsState_t;

/*
    Parameters of control modes of the AOCS service
*/
typedef struct {
    float fRefParam1;
    float fRefParam2;
    float fRefParam3;
} PACKED_STRUCT CONOPS_AocsRefParams_t;

/*
    Defines the set of supported ConOps state machine events
*/
#define CONOPS_EVENTS_RESET ((uint8_t) 0)
#define CONOPS_EVENTS_PERIODIC ((uint8_t) 1)
#define CONOPS_EVENTS_ENTER_IDLE ((uint8_t) 2)
#define CONOPS_EVENTS_ENTER_SAFE ((uint8_t) 3)
#define CONOPS_EVENTS_ENTER_MISSION ((uint8_t) 4)
#define CONOPS_EVENTS_MAX_CNT  ((uint8_t) 5)
typedef uint8_t CONOPS_Events_t;

/*
    Standard result enumeration which can be used in most situations as a return code
*/
#define CONOPS_STANDARDRESULT_SUCCESS ((uint8_t) 0)
#define CONOPS_STANDARDRESULT_ERROR ((uint8_t) 1)
#define CONOPS_STANDARDRESULT_INVALID_ARGS ((uint8_t) 2)
#define CONOPS_STANDARDRESULT_NOT_SUPPORTED ((uint8_t) 3)
#define CONOPS_STANDARDRESULT_MAX_CNT  ((uint8_t) 4)
typedef uint8_t CONOPS_StandardResult_t;

/*
    Enumeration for SAFE booleans
*/
#define CONOPS_SAFEBOOL_FALSE ((uint8_t) 0)
#define CONOPS_SAFEBOOL_TRUE ((uint8_t) 255)
#define CONOPS_SAFEBOOL_MAX_CNT  ((uint8_t) 256)
typedef uint8_t CONOPS_SafeBool_t;

/*
    ConOps modes that have control mode configuration applied automatically when the mode is entered
*/
#define CONOPS_MODESWITHDEFCTRL_SAFE ((uint8_t) 0)
#define CONOPS_MODESWITHDEFCTRL_IDLE ((uint8_t) 1)
#define CONOPS_MODESWITHDEFCTRL_MAX_CNT  ((uint8_t) 2)
typedef uint8_t CONOPS_ModesWithDefCtrl_t;

/*
    Data used for default mode configuration
*/
typedef struct {
    CONOPS_AocsState_t eMode;
    CONOPS_AocsRefParams_t sParams;
} PACKED_STRUCT CONOPS_ControlMode_t;


typedef struct {
    CONOPS_Events_t eEvent_type;
} PACKED_STRUCT conopssend_new_eventRequestData_t;

typedef struct {
    int32_t i32Thresh_value;
    CONOPS_ThresholdValueTypes_t eThresh_type;
} PACKED_STRUCT conopsset_thresh_valRequestData_t;

typedef struct {
    CONOPS_ThresholdValueTypes_t eThresh_type;
} PACKED_STRUCT conopsget_thresh_valRequestData_t;

typedef struct {
    CONOPS_ThresholdValues_t sThresh_vals;
} PACKED_STRUCT conopsset_all_thresh_valRequestData_t;

typedef struct {
    uint32_t u32Timeout;
} PACKED_STRUCT conopsrequest_mission_mode_enterRequestData_t;

typedef struct {
    CONOPS_ModesWithDefCtrl_t eConops_mode;
} PACKED_STRUCT conopsget_default_control_modeRequestData_t;

typedef struct {
    CONOPS_ModesWithDefCtrl_t eConops_mode;
    CONOPS_ControlMode_t sControl_mode;
} PACKED_STRUCT conopsset_default_control_modeRequestData_t;

typedef struct {
    CONOPS_SafeBool_t eIs_allowed;
} PACKED_STRUCT conopsset_force_allow_payloadsRequestData_t;


typedef struct {
    CONOPS_StandardResult_t eOp_result;
} PACKED_STRUCT conopssend_new_eventResponseData_t;

typedef struct {
    CONOPS_StandardResult_t eOp_result;
    CONOPS_OpModes_t eOp_mode;
} PACKED_STRUCT conopsget_op_modeResponseData_t;

typedef struct {
    CONOPS_StandardResult_t eOp_result;
} PACKED_STRUCT conopsset_thresh_valResponseData_t;

typedef struct {
    CONOPS_StandardResult_t eOp_result;
    int32_t i32Thresh_value;
} PACKED_STRUCT conopsget_thresh_valResponseData_t;

typedef struct {
    CONOPS_StandardResult_t eOp_result;
} PACKED_STRUCT conopsset_all_thresh_valResponseData_t;

typedef struct {
    CONOPS_StandardResult_t eOp_result;
    CONOPS_ThresholdValues_t sThresh_vals;
} PACKED_STRUCT conopsget_all_thresh_valResponseData_t;

typedef struct {
    CONOPS_StandardResult_t eOp_result;
} PACKED_STRUCT conopsrequest_mission_mode_enterResponseData_t;

typedef struct {
    CONOPS_StandardResult_t eOp_result;
} PACKED_STRUCT conopsrequest_mission_mode_exitResponseData_t;

typedef struct {
    CONOPS_StandardResult_t eOp_result;
    CONOPS_ControlMode_t sControl_mode;
} PACKED_STRUCT conopsget_default_control_modeResponseData_t;

typedef struct {
    CONOPS_StandardResult_t eOp_result;
    CONOPS_ControlMode_t sSet_control_mode;
} PACKED_STRUCT conopsset_default_control_modeResponseData_t;

typedef struct {
    CONOPS_StandardResult_t eOp_result;
} PACKED_STRUCT conopsset_force_allow_payloadsResponseData_t;

typedef struct {
    CONOPS_SafeBool_t eSet_is_allowed;
} PACKED_STRUCT conopsget_force_allow_payloadsResponseData_t;


#endif  // #ifndef FP_CONOPSPROTOCOLTYPES_H

