/*!
********************************************************************************************
* @file FP_payload_ctrlProtocolServer.h
* @brief ESSA Stack server-side public API declaration
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

#ifndef FP_PAYLOAD_CTRLPROTOCOLSERVER_H
#define FP_PAYLOAD_CTRLPROTOCOLSERVER_H

#include "FP_payload_ctrlProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define payload_ctrl_PROTOCOL_VERSION_MAJOR   ((uint8_t) 2)
#define payload_ctrl_PROTOCOL_VERSION_MINOR   ((uint8_t) 0)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfpayload_ctrl_start_payloadRequestHandler_t)(ReqContext_t *ctx, const payload_ctrlstart_payloadRequestData_t *pRequestData);
typedef void (*pfpayload_ctrl_stop_payloadRequestHandler_t)(ReqContext_t *ctx, const payload_ctrlstop_payloadRequestData_t *pRequestData);
typedef void (*pfpayload_ctrl_get_payload_infoRequestHandler_t)(ReqContext_t *ctx, const payload_ctrlget_payload_infoRequestData_t *pRequestData);

typedef struct {
    pfpayload_ctrl_start_payloadRequestHandler_t payload_ctrl_start_payloadRequestHandler;
    pfpayload_ctrl_stop_payloadRequestHandler_t payload_ctrl_stop_payloadRequestHandler;
    pfpayload_ctrl_get_payload_infoRequestHandler_t payload_ctrl_get_payload_infoRequestHandler;
} payload_ctrl_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_payload_ctrlProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void payload_ctrl_registerServerApi(payload_ctrl_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_payload_ctrlProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t payload_ctrl_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes payload_ctrl_start_payloadResp(
                RespContext_t* ctx,
                const PAYLOAD_CTRL_PayloadOpResult_t eOp_result
);

ESSATMAC_ErrCodes payload_ctrl_stop_payloadResp(
                RespContext_t* ctx,
                const PAYLOAD_CTRL_PayloadOpResult_t eOp_result
);

ESSATMAC_ErrCodes payload_ctrl_get_payload_infoResp(
                RespContext_t* ctx,
                const PAYLOAD_CTRL_PayloadInfo_t * const sInfo
);


#endif  // #ifndef FP_PAYLOAD_CTRLPROTOCOLSERVER_H
