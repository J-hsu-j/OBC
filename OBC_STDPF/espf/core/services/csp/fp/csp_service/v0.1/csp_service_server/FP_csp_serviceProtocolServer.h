/*!
********************************************************************************************
* @file FP_csp_serviceProtocolServer.h
* @brief ESSA Stack server-side public API declaration
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

#ifndef FP_CSP_SERVICEPROTOCOLSERVER_H
#define FP_CSP_SERVICEPROTOCOLSERVER_H

#include "FP_csp_serviceProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define csp_service_PROTOCOL_VERSION_MAJOR   ((uint8_t) 0)
#define csp_service_PROTOCOL_VERSION_MINOR   ((uint8_t) 1)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfcsp_service_get_trace_debug_levelRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfcsp_service_set_trace_debug_levelRequestHandler_t)(ReqContext_t *ctx, const csp_serviceset_trace_debug_levelRequestData_t *pRequestData);

typedef struct {
    pfcsp_service_get_trace_debug_levelRequestHandler_t csp_service_get_trace_debug_levelRequestHandler;
    pfcsp_service_set_trace_debug_levelRequestHandler_t csp_service_set_trace_debug_levelRequestHandler;
} csp_service_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_csp_serviceProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void csp_service_registerServerApi(csp_service_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_csp_serviceProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t csp_service_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes csp_service_get_trace_debug_levelResp(
                RespContext_t* ctx,
                const CSP_SERVICE_debug_levels_t * const sTrace_debug_level
);

ESSATMAC_ErrCodes csp_service_set_trace_debug_levelResp(
                RespContext_t* ctx,
                const CSP_SERVICE_StandardResult_t eOp_result
);


#endif  // #ifndef FP_CSP_SERVICEPROTOCOLSERVER_H
