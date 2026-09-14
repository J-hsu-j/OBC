
#ifndef FP_FDIR_SRVPROTOCOLTYPES_H
#define FP_FDIR_SRVPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV ((uint16_t) (0x0000001D))

#define FDIR_SRV_GET_SYSTEM_FDIR_LEVEL_FUNC_ID ((funcIdType_t) 0x00000001)
#define FDIR_SRV_GET_AGENT_FDIR_LEVEL_FUNC_ID ((funcIdType_t) 0x00000002)
#define FDIR_SRV_GET_DETECTION_FOR_FAULT_FUNC_ID ((funcIdType_t) 0x00000003)
#define FDIR_SRV_SET_DETECTION_FOR_FAULT_FUNC_ID ((funcIdType_t) 0x00000004)
#define FDIR_SRV_SET_DETECTION_FOR_ALL_FAULTS_FUNC_ID ((funcIdType_t) 0x00000014)
#define FDIR_SRV_GET_MIN_ACTIVE_FDIR_FUNC_ID ((funcIdType_t) 0x00000015)
#define FDIR_SRV_SET_MIN_ACTIVE_FDIR_FUNC_ID ((funcIdType_t) 0x00000005)
#define FDIR_SRV_GET_FAULT_USER_CLEAR_LEVEL_FUNC_ID ((funcIdType_t) 0x00000007)
#define FDIR_SRV_SET_FAULT_USER_CLEAR_LEVEL_FUNC_ID ((funcIdType_t) 0x00000006)
#define FDIR_SRV_GET_FAULT_FUNC_ID ((funcIdType_t) 0x00000008)
#define FDIR_SRV_SET_FAULT_FUNC_ID ((funcIdType_t) 0x00000009)
#define FDIR_SRV_FORCE_CLEAR_FAULT_FUNC_ID ((funcIdType_t) 0x0000000A)
#define FDIR_SRV_FORCE_CLEAR_ALL_FAULTS_FUNC_ID ((funcIdType_t) 0x0000000B)
#define FDIR_SRV_GET_SYSTEM_FDIR_LEVEL_FUNCRESP_ID ((funcIdType_t) 0x00000001)
#define FDIR_SRV_GET_AGENT_FDIR_LEVEL_FUNCRESP_ID ((funcIdType_t) 0x00000002)
#define FDIR_SRV_GET_DETECTION_FOR_FAULT_FUNCRESP_ID ((funcIdType_t) 0x00000003)
#define FDIR_SRV_SET_DETECTION_FOR_FAULT_FUNCRESP_ID ((funcIdType_t) 0x00000004)
#define FDIR_SRV_SET_DETECTION_FOR_ALL_FAULTS_FUNCRESP_ID ((funcIdType_t) 0x00000014)
#define FDIR_SRV_GET_MIN_ACTIVE_FDIR_FUNCRESP_ID ((funcIdType_t) 0x00000015)
#define FDIR_SRV_SET_MIN_ACTIVE_FDIR_FUNCRESP_ID ((funcIdType_t) 0x00000005)
#define FDIR_SRV_GET_FAULT_USER_CLEAR_LEVEL_FUNCRESP_ID ((funcIdType_t) 0x00000007)
#define FDIR_SRV_SET_FAULT_USER_CLEAR_LEVEL_FUNCRESP_ID ((funcIdType_t) 0x00000006)
#define FDIR_SRV_GET_FAULT_FUNCRESP_ID ((funcIdType_t) 0x00000008)
#define FDIR_SRV_SET_FAULT_FUNCRESP_ID ((funcIdType_t) 0x00000009)
#define FDIR_SRV_FORCE_CLEAR_FAULT_FUNCRESP_ID ((funcIdType_t) 0x0000000A)
#define FDIR_SRV_FORCE_CLEAR_ALL_FAULTS_FUNCRESP_ID ((funcIdType_t) 0x0000000B)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
#define FDIR_SRV_RETURN_STATUS_SUCCESS ((uint8_t) 0)
#define FDIR_SRV_RETURN_STATUS_ERROR_INVALID_FAULT_ID ((uint8_t) 1)
#define FDIR_SRV_RETURN_STATUS_ERROR_INVALID_AGENT_ID ((uint8_t) 2)
#define FDIR_SRV_RETURN_STATUS_ERROR_INVALID_FDIR_LEVEL ((uint8_t) 3)
#define FDIR_SRV_RETURN_STATUS_ERROR_FAULT_DETECTION_DISABLED ((uint8_t) 4)
#define FDIR_SRV_RETURN_STATUS_ERROR_FAULT_LEVEL_ABOVE_AUTOCLEAR ((uint8_t) 5)
#define FDIR_SRV_RETURN_STATUS_ERROR_INTERNAL ((uint8_t) 6)
#define FDIR_SRV_RETURN_STATUS_MAX_CNT  ((uint8_t) 7)
typedef uint8_t FDIR_SRV_return_status_t;


typedef struct {
    uint16_t u16Agent_id;
} PACKED_STRUCT fdir_srvget_agent_fdir_levelRequestData_t;

typedef struct {
    uint16_t u16Fault_id;
} PACKED_STRUCT fdir_srvget_detection_for_faultRequestData_t;

typedef struct {
    uint16_t u16Fault_id;
    bool bSet_detection_enabled;
} PACKED_STRUCT fdir_srvset_detection_for_faultRequestData_t;

typedef struct {
    bool bSet_detection_enabled;
} PACKED_STRUCT fdir_srvset_detection_for_all_faultsRequestData_t;

typedef struct {
    uint8_t u8Fdir_level;
} PACKED_STRUCT fdir_srvset_min_active_fdirRequestData_t;

typedef struct {
    uint8_t u8Fdir_level;
} PACKED_STRUCT fdir_srvset_fault_user_clear_levelRequestData_t;

typedef struct {
    uint16_t u16Fault_id;
} PACKED_STRUCT fdir_srvget_faultRequestData_t;

typedef struct {
    uint16_t u16Fault_id;
    uint16_t u16Agent_id;
    bool bActive;
} PACKED_STRUCT fdir_srvset_faultRequestData_t;

typedef struct {
    uint16_t u16Fault_id;
} PACKED_STRUCT fdir_srvforce_clear_faultRequestData_t;


typedef struct {
    FDIR_SRV_return_status_t eStatus;
    uint8_t u8Fdir_level;
} PACKED_STRUCT fdir_srvget_system_fdir_levelResponseData_t;

typedef struct {
    FDIR_SRV_return_status_t eStatus;
    uint8_t u8Fdir_level;
} PACKED_STRUCT fdir_srvget_agent_fdir_levelResponseData_t;

typedef struct {
    FDIR_SRV_return_status_t eStatus;
    bool bDetection_enabled;
} PACKED_STRUCT fdir_srvget_detection_for_faultResponseData_t;

typedef struct {
    FDIR_SRV_return_status_t eStatus;
    bool bDetection_enabled;
} PACKED_STRUCT fdir_srvset_detection_for_faultResponseData_t;

typedef struct {
    FDIR_SRV_return_status_t eStatus;
    uint16_t u16Fault_id;
} PACKED_STRUCT fdir_srvset_detection_for_all_faultsResponseData_t;

typedef struct {
    FDIR_SRV_return_status_t eStatus;
    uint8_t u8Fdir_level_set;
} PACKED_STRUCT fdir_srvget_min_active_fdirResponseData_t;

typedef struct {
    FDIR_SRV_return_status_t eStatus;
    uint8_t u8Fdir_level_set;
} PACKED_STRUCT fdir_srvset_min_active_fdirResponseData_t;

typedef struct {
    FDIR_SRV_return_status_t eStatus;
    uint8_t u8Fdir_level;
} PACKED_STRUCT fdir_srvget_fault_user_clear_levelResponseData_t;

typedef struct {
    FDIR_SRV_return_status_t eStatus;
    uint8_t u8Fdir_level_set;
} PACKED_STRUCT fdir_srvset_fault_user_clear_levelResponseData_t;

typedef struct {
    FDIR_SRV_return_status_t eStatus;
    bool bIs_active;
    uint8_t u8Fdir_level;
} PACKED_STRUCT fdir_srvget_faultResponseData_t;

typedef struct {
    FDIR_SRV_return_status_t eStatus;
} PACKED_STRUCT fdir_srvset_faultResponseData_t;

typedef struct {
    FDIR_SRV_return_status_t eStatus;
} PACKED_STRUCT fdir_srvforce_clear_faultResponseData_t;

typedef struct {
    FDIR_SRV_return_status_t eStatus;
    uint16_t u16Fault_id;
} PACKED_STRUCT fdir_srvforce_clear_all_faultsResponseData_t;


#endif  // #ifndef FP_FDIR_SRVPROTOCOLTYPES_H

