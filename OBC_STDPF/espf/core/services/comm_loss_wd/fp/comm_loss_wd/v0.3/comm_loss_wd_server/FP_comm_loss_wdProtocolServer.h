/*!
********************************************************************************************
* @file FP_comm_loss_wdProtocolServer.h
* @brief ESSA Stack server-side public API declaration
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

#ifndef FP_COMM_LOSS_WDPROTOCOLSERVER_H
#define FP_COMM_LOSS_WDPROTOCOLSERVER_H

#include "FP_comm_loss_wdProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define comm_loss_wd_PROTOCOL_VERSION_MAJOR   ((uint8_t) 0)
#define comm_loss_wd_PROTOCOL_VERSION_MINOR   ((uint8_t) 3)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfcomm_loss_wd_set_wd_timeoutRequestHandler_t)(ReqContext_t *ctx, const comm_loss_wdset_wd_timeoutRequestData_t *pRequestData);
typedef void (*pfcomm_loss_wd_set_wd_enableRequestHandler_t)(ReqContext_t *ctx, const comm_loss_wdset_wd_enableRequestData_t *pRequestData);
typedef void (*pfcomm_loss_wd_get_wd_timeoutRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfcomm_loss_wd_get_wd_statRequestHandler_t)(ReqContext_t *ctx);

typedef struct {
    pfcomm_loss_wd_set_wd_timeoutRequestHandler_t comm_loss_wd_set_wd_timeoutRequestHandler;
    pfcomm_loss_wd_set_wd_enableRequestHandler_t comm_loss_wd_set_wd_enableRequestHandler;
    pfcomm_loss_wd_get_wd_timeoutRequestHandler_t comm_loss_wd_get_wd_timeoutRequestHandler;
    pfcomm_loss_wd_get_wd_statRequestHandler_t comm_loss_wd_get_wd_statRequestHandler;
} comm_loss_wd_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_comm_loss_wdProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void comm_loss_wd_registerServerApi(comm_loss_wd_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_comm_loss_wdProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t comm_loss_wd_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes comm_loss_wd_set_wd_timeoutResp(
                RespContext_t* ctx,
                const COMM_LOSS_WD_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes comm_loss_wd_set_wd_enableResp(
                RespContext_t* ctx,
                const COMM_LOSS_WD_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes comm_loss_wd_get_wd_timeoutResp(
                RespContext_t* ctx,
                const uint32_t u32Wd_timeout
);

ESSATMAC_ErrCodes comm_loss_wd_get_wd_statResp(
                RespContext_t* ctx,
                const bool bWd_stat
);


#endif  // #ifndef FP_COMM_LOSS_WDPROTOCOLSERVER_H
