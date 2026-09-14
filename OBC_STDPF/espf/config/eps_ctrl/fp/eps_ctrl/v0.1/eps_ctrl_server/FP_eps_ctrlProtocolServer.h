/*!
********************************************************************************************
* @file FP_eps_ctrlProtocolServer.h
* @brief ESSA Stack server-side public API declaration
********************************************************************************************
* @version           interface eps_ctrl v0.1
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

#ifndef FP_EPS_CTRLPROTOCOLSERVER_H
#define FP_EPS_CTRLPROTOCOLSERVER_H

#include "FP_eps_ctrlProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define eps_ctrl_PROTOCOL_VERSION_MAJOR   ((uint8_t) 0)
#define eps_ctrl_PROTOCOL_VERSION_MINOR   ((uint8_t) 1)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfeps_ctrl_get_ch_outputRequestHandler_t)(ReqContext_t *ctx, const eps_ctrlget_ch_outputRequestData_t *pRequestData);
typedef void (*pfeps_ctrl_set_ch_outputRequestHandler_t)(ReqContext_t *ctx, const eps_ctrlset_ch_outputRequestData_t *pRequestData);

typedef struct {
    pfeps_ctrl_get_ch_outputRequestHandler_t eps_ctrl_get_ch_outputRequestHandler;
    pfeps_ctrl_set_ch_outputRequestHandler_t eps_ctrl_set_ch_outputRequestHandler;
} eps_ctrl_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_eps_ctrlProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void eps_ctrl_registerServerApi(eps_ctrl_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_eps_ctrlProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t eps_ctrl_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes eps_ctrl_get_ch_outputResp(
                RespContext_t* ctx,
                const bool bCh_state,
                const EPS_CTRL_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes eps_ctrl_set_ch_outputResp(
                RespContext_t* ctx,
                const EPS_CTRL_StandardResult_t eOp_result
);


#endif  // #ifndef FP_EPS_CTRLPROTOCOLSERVER_H
