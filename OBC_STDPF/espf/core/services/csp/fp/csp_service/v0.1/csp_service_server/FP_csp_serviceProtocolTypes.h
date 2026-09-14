/*!
********************************************************************************************
* @file FP_csp_serviceProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface csp_service v0.1
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

#ifndef FP_CSP_SERVICEPROTOCOLTYPES_H
#define FP_CSP_SERVICEPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_CSP_SERVICE ((uint16_t) (0x00000066))

#define CSP_SERVICE_GET_TRACE_DEBUG_LEVEL_FUNC_ID ((funcIdType_t) 0x00000000)
#define CSP_SERVICE_SET_TRACE_DEBUG_LEVEL_FUNC_ID ((funcIdType_t) 0x00000001)
#define CSP_SERVICE_GET_TRACE_DEBUG_LEVEL_FUNCRESP_ID ((funcIdType_t) 0x00000000)
#define CSP_SERVICE_SET_TRACE_DEBUG_LEVEL_FUNCRESP_ID ((funcIdType_t) 0x00000001)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    Structure for trace_debug_levels.
*/
typedef struct {
    bool bCSP_ERROR_FLAG;
    bool bCSP_WARN_FLAG;
    bool bCSP_INFO_FLAG;
    bool bCSP_BUFFER_FLAG;
    bool bCSP_PACKET_FLAG;
    bool bCSP_PROTOCOL_FLAG;
    bool bCSP_LOCK_FLAG;
} PACKED_STRUCT CSP_SERVICE_debug_levels_t;

/*
    General status type used for SW-related communication and/or settings.
*/
#define CSP_SERVICE_STANDARDRESULT_SUCCESS ((uint8_t) 0)
#define CSP_SERVICE_STANDARDRESULT_ERROR ((uint8_t) 1)
#define CSP_SERVICE_STANDARDRESULT_INVALID_ARGS ((uint8_t) 2)
#define CSP_SERVICE_STANDARDRESULT_NOT_SUPPORTED ((uint8_t) 3)
#define CSP_SERVICE_STANDARDRESULT_MAX_CNT  ((uint8_t) 4)
typedef uint8_t CSP_SERVICE_StandardResult_t;


typedef struct {
    CSP_SERVICE_debug_levels_t sTrace_debug_level;
} PACKED_STRUCT csp_serviceset_trace_debug_levelRequestData_t;


typedef struct {
    CSP_SERVICE_debug_levels_t sTrace_debug_level;
} PACKED_STRUCT csp_serviceget_trace_debug_levelResponseData_t;

typedef struct {
    CSP_SERVICE_StandardResult_t eOp_result;
} PACKED_STRUCT csp_serviceset_trace_debug_levelResponseData_t;


#endif  // #ifndef FP_CSP_SERVICEPROTOCOLTYPES_H

