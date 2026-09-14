/*!
********************************************************************************************
* @file FP_payload_ctrlProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface payload_ctrl v2.0
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

#ifndef FP_PAYLOAD_CTRLPROTOCOLTYPES_H
#define FP_PAYLOAD_CTRLPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_PAYLOAD_CTRL ((uint16_t) (0x0000006F))

#define PAYLOAD_CTRL_START_PAYLOAD_FUNC_ID ((funcIdType_t) 0x00000000)
#define PAYLOAD_CTRL_STOP_PAYLOAD_FUNC_ID ((funcIdType_t) 0x00000001)
#define PAYLOAD_CTRL_GET_PAYLOAD_INFO_FUNC_ID ((funcIdType_t) 0x00000002)
#define PAYLOAD_CTRL_START_PAYLOAD_FUNCRESP_ID ((funcIdType_t) 0x00000000)
#define PAYLOAD_CTRL_STOP_PAYLOAD_FUNCRESP_ID ((funcIdType_t) 0x00000001)
#define PAYLOAD_CTRL_GET_PAYLOAD_INFO_FUNCRESP_ID ((funcIdType_t) 0x00000002)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    Payload controller operation result
*/
#define PAYLOAD_CTRL_PAYLOADOPRESULT_NOT_INIT ((uint8_t) 0)
#define PAYLOAD_CTRL_PAYLOADOPRESULT_INVALID_PL_ID ((uint8_t) 1)
#define PAYLOAD_CTRL_PAYLOADOPRESULT_REFUSE_CMD ((uint8_t) 2)
#define PAYLOAD_CTRL_PAYLOADOPRESULT_FAILED ((uint8_t) 3)
#define PAYLOAD_CTRL_PAYLOADOPRESULT_OK ((uint8_t) 4)
#define PAYLOAD_CTRL_PAYLOADOPRESULT_MAX_CNT  ((uint8_t) 5)
typedef uint8_t PAYLOAD_CTRL_PayloadOpResult_t;

/*
    Urgency of a payload stop operation
*/
#define PAYLOAD_CTRL_STOPMODE_NORMAL ((uint8_t) 0)
#define PAYLOAD_CTRL_STOPMODE_EMERGENCY ((uint8_t) 255)
#define PAYLOAD_CTRL_STOPMODE_MAX_CNT  ((uint8_t) 256)
typedef uint8_t PAYLOAD_CTRL_StopMode_t;

/*
    Configuration arguments for starting a payload
*/
typedef struct {
    uint8_t u8Flags;
    uint8_t au8Pl_args[47];
} PACKED_STRUCT PAYLOAD_CTRL_PayloadStartCfg_t;

/*
    State of a payload
*/
#define PAYLOAD_CTRL_PAYLOADSTATE_NOT_INIT ((uint8_t) 0)
#define PAYLOAD_CTRL_PAYLOADSTATE_STOPPED ((uint8_t) 1)
#define PAYLOAD_CTRL_PAYLOADSTATE_STARTED ((uint8_t) 2)
#define PAYLOAD_CTRL_PAYLOADSTATE_STARTING ((uint8_t) 3)
#define PAYLOAD_CTRL_PAYLOADSTATE_STOPPING ((uint8_t) 4)
#define PAYLOAD_CTRL_PAYLOADSTATE_ERROR ((uint8_t) 5)
#define PAYLOAD_CTRL_PAYLOADSTATE_MAX_CNT  ((uint8_t) 6)
typedef uint8_t PAYLOAD_CTRL_PayloadState_t;

/*
    Status information about a payload
*/
typedef struct {
    PAYLOAD_CTRL_PayloadState_t ePl_state;
    uint32_t u32Last_error_code;
} PACKED_STRUCT PAYLOAD_CTRL_PayloadInfo_t;


typedef struct {
    uint8_t u8Payload_id;
    PAYLOAD_CTRL_PayloadStartCfg_t sStart_cfg;
} PACKED_STRUCT payload_ctrlstart_payloadRequestData_t;

typedef struct {
    uint8_t u8Payload_id;
    PAYLOAD_CTRL_StopMode_t eReq_stop_mode;
} PACKED_STRUCT payload_ctrlstop_payloadRequestData_t;

typedef struct {
    uint8_t u8Payload_id;
} PACKED_STRUCT payload_ctrlget_payload_infoRequestData_t;


typedef struct {
    PAYLOAD_CTRL_PayloadOpResult_t eOp_result;
} PACKED_STRUCT payload_ctrlstart_payloadResponseData_t;

typedef struct {
    PAYLOAD_CTRL_PayloadOpResult_t eOp_result;
} PACKED_STRUCT payload_ctrlstop_payloadResponseData_t;

typedef struct {
    PAYLOAD_CTRL_PayloadInfo_t sInfo;
} PACKED_STRUCT payload_ctrlget_payload_infoResponseData_t;


#endif  // #ifndef FP_PAYLOAD_CTRLPROTOCOLTYPES_H

