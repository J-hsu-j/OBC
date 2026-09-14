/*!
********************************************************************************************
* @file FP_EPS1ProtocolClient.h
* @brief ESSA Stack client-side public API declaration
********************************************************************************************
* @version           interface EPS1 v0.1
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

#ifndef FP_EPS1PROTOCOLCLIENT_H
#define FP_EPS1PROTOCOLCLIENT_H

#include "FP_EPS1ProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define EPS1_PROTOCOL_VERSION_MAJOR   ((uint8_t) 0)
#define EPS1_PROTOCOL_VERSION_MINOR   ((uint8_t) 1)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfEPS1_getBatteryInfoResponseHandler_t)(RespContext_t *pRespCtx,
              const EPS1getBatteryInfoResponseData_t *pResponseData);

typedef void (*pfEPS1_getConfigurationInfoResponseHandler_t)(RespContext_t *pRespCtx,
              const EPS1getConfigurationInfoResponseData_t *pResponseData);

typedef void (*pfEPS1_queryControlsResponseHandler_t)(RespContext_t *pRespCtx,
              const EPS1queryControlsResponseData_t *pResponseData);

typedef void (*pfEPS1_ToggleOutPutResponseHandler_t)(RespContext_t *pRespCtx,
              const EPS1ToggleOutPutResponseData_t *pResponseData);


typedef struct {
    pfEPS1_getBatteryInfoResponseHandler_t EPS1_getBatteryInfoResponseHandler;
    pfEPS1_getConfigurationInfoResponseHandler_t EPS1_getConfigurationInfoResponseHandler;
    pfEPS1_queryControlsResponseHandler_t EPS1_queryControlsResponseHandler;
    pfEPS1_ToggleOutPutResponseHandler_t EPS1_ToggleOutPutResponseHandler;
} EPS1_ClientApi_t;

/**********************************************************************
 *
 *  Client protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_EPS1ProtocolClientInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void EPS1_registerClientApi(EPS1_ClientApi_t *pCliApiHandlers);

// @deprecated - will be removed in the future - use FP_EPS1ProtocolClientInfo directly
ESSA_pStack_FunctionProtocolInfo_t EPS1_getClientProtocolDescriptor(void);

ESSATMAC_ErrCodes EPS1_getBatteryInfoReq(
                ReqContext_t* ctx);

ESSATMAC_ErrCodes EPS1_getConfigurationInfoReq(
                ReqContext_t* ctx);

ESSATMAC_ErrCodes EPS1_queryControlsReq(
                ReqContext_t* ctx,
                const EPS1_QueryState_t * const aeRequested
);

ESSATMAC_ErrCodes EPS1_ToggleOutPutReq(
                ReqContext_t* ctx,
                const EPS1_QueryControlsIndex_t eToggleOutput,
                const uint8_t u8TimeAtToggledState
);


#endif  // #ifndef FP_EPS1PROTOCOLCLIENT_H

