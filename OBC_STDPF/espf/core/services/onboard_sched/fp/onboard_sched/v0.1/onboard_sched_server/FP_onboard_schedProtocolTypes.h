/*!
********************************************************************************************
* @file FP_onboard_schedProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface onboard_sched v0.1
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

#ifndef FP_ONBOARD_SCHEDPROTOCOLTYPES_H
#define FP_ONBOARD_SCHEDPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_ONBOARD_SCHED ((uint16_t) (0x0000001C))

#define ONBOARD_SCHED_SET_SCHEDULER_STATE_FUNC_ID ((funcIdType_t) 0x00000001)
#define ONBOARD_SCHED_GET_SCHEDULER_STATE_FUNC_ID ((funcIdType_t) 0x00000002)
#define ONBOARD_SCHED_SET_ACTIVE_SCHEDULE_FUNC_ID ((funcIdType_t) 0x00000003)
#define ONBOARD_SCHED_GET_ACTIVE_SCHEDULE_FUNC_ID ((funcIdType_t) 0x00000004)
#define ONBOARD_SCHED_GET_NEXT_SLOT_FUNC_ID ((funcIdType_t) 0x00000005)
#define ONBOARD_SCHED_SET_SCHEDULER_STATE_FUNCRESP_ID ((funcIdType_t) 0x00000001)
#define ONBOARD_SCHED_GET_SCHEDULER_STATE_FUNCRESP_ID ((funcIdType_t) 0x00000002)
#define ONBOARD_SCHED_SET_ACTIVE_SCHEDULE_FUNCRESP_ID ((funcIdType_t) 0x00000003)
#define ONBOARD_SCHED_GET_ACTIVE_SCHEDULE_FUNCRESP_ID ((funcIdType_t) 0x00000004)
#define ONBOARD_SCHED_GET_NEXT_SLOT_FUNCRESP_ID ((funcIdType_t) 0x00000005)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
#define ONBOARD_SCHED_SCHEDLOADRESULT_SUCCESS ((uint8_t) 0)
#define ONBOARD_SCHED_SCHEDLOADRESULT_ERROR_SYSTEM ((uint8_t) 1)
#define ONBOARD_SCHED_SCHEDLOADRESULT_ERROR_NO_FILE ((uint8_t) 2)
#define ONBOARD_SCHED_SCHEDLOADRESULT_ERROR_SCHED_RUNNING ((uint8_t) 3)
#define ONBOARD_SCHED_SCHEDLOADRESULT_MAX_CNT  ((uint8_t) 4)
typedef uint8_t ONBOARD_SCHED_SchedLoadResult_t;

#define ONBOARD_SCHED_SCHEDSTATE_RUNNING ((uint8_t) 0)
#define ONBOARD_SCHED_SCHEDSTATE_STOPPED ((uint8_t) 1)
#define ONBOARD_SCHED_SCHEDSTATE_MAX_CNT  ((uint8_t) 2)
typedef uint8_t ONBOARD_SCHED_SchedState_t;


typedef struct {
    ONBOARD_SCHED_SchedState_t eSch_state;
} PACKED_STRUCT onboard_schedset_scheduler_stateRequestData_t;

typedef struct {
    uint8_t u8File_nameSize;
    char strFile_name[47];
} PACKED_STRUCT onboard_schedset_active_scheduleRequestData_t;


typedef struct {
    ONBOARD_SCHED_SchedState_t eNew_state;
} PACKED_STRUCT onboard_schedset_scheduler_stateResponseData_t;

typedef struct {
    ONBOARD_SCHED_SchedState_t eSch_state;
} PACKED_STRUCT onboard_schedget_scheduler_stateResponseData_t;

typedef struct {
    ONBOARD_SCHED_SchedLoadResult_t eResult;
} PACKED_STRUCT onboard_schedset_active_scheduleResponseData_t;

typedef struct {
    uint8_t u8File_nameSize;
    char strFile_name[47];
    ONBOARD_SCHED_SchedLoadResult_t eResult;
} PACKED_STRUCT onboard_schedget_active_scheduleResponseData_t;

typedef struct {
    uint32_t u32Offset;
} PACKED_STRUCT onboard_schedget_next_slotResponseData_t;


#endif  // #ifndef FP_ONBOARD_SCHEDPROTOCOLTYPES_H

