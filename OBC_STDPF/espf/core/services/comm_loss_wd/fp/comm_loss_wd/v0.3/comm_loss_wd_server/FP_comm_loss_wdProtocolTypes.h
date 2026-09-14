/*!
********************************************************************************************
* @file FP_comm_loss_wdProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface comm_loss_wd v0.3
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

#ifndef FP_COMM_LOSS_WDPROTOCOLTYPES_H
#define FP_COMM_LOSS_WDPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_COMM_LOSS_WD ((uint16_t) (0x00000065))

#define COMM_LOSS_WD_SET_WD_TIMEOUT_FUNC_ID ((funcIdType_t) 0x00000001)
#define COMM_LOSS_WD_SET_WD_ENABLE_FUNC_ID ((funcIdType_t) 0x00000002)
#define COMM_LOSS_WD_GET_WD_TIMEOUT_FUNC_ID ((funcIdType_t) 0x00000003)
#define COMM_LOSS_WD_GET_WD_STAT_FUNC_ID ((funcIdType_t) 0x00000004)
#define COMM_LOSS_WD_SET_WD_TIMEOUT_FUNCRESP_ID ((funcIdType_t) 0x00000001)
#define COMM_LOSS_WD_SET_WD_ENABLE_FUNCRESP_ID ((funcIdType_t) 0x00000002)
#define COMM_LOSS_WD_GET_WD_TIMEOUT_FUNCRESP_ID ((funcIdType_t) 0x00000003)
#define COMM_LOSS_WD_GET_WD_STAT_FUNCRESP_ID ((funcIdType_t) 0x00000004)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    General status type used for SW-related communication and/or settings.
*/
#define COMM_LOSS_WD_STANDARDRESULT_SUCCESS ((uint8_t) 0)
#define COMM_LOSS_WD_STANDARDRESULT_ERROR ((uint8_t) 1)
#define COMM_LOSS_WD_STANDARDRESULT_INVALID_ARGS ((uint8_t) 2)
#define COMM_LOSS_WD_STANDARDRESULT_NOT_SUPPORTED ((uint8_t) 3)
#define COMM_LOSS_WD_STANDARDRESULT_MAX_CNT  ((uint8_t) 4)
typedef uint8_t COMM_LOSS_WD_StandardResult_t;


typedef struct {
    uint32_t u32Wd_timeout;
} PACKED_STRUCT comm_loss_wdset_wd_timeoutRequestData_t;

typedef struct {
    bool bWd_enable;
} PACKED_STRUCT comm_loss_wdset_wd_enableRequestData_t;


typedef struct {
    COMM_LOSS_WD_StandardResult_t eOp_result;
} PACKED_STRUCT comm_loss_wdset_wd_timeoutResponseData_t;

typedef struct {
    COMM_LOSS_WD_StandardResult_t eOp_result;
} PACKED_STRUCT comm_loss_wdset_wd_enableResponseData_t;

typedef struct {
    uint32_t u32Wd_timeout;
} PACKED_STRUCT comm_loss_wdget_wd_timeoutResponseData_t;

typedef struct {
    bool bWd_stat;
} PACKED_STRUCT comm_loss_wdget_wd_statResponseData_t;


#endif  // #ifndef FP_COMM_LOSS_WDPROTOCOLTYPES_H

