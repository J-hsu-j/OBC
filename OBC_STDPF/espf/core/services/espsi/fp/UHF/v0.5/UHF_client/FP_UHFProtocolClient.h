/*!
********************************************************************************************
* @file FP_UHFProtocolClient.h
* @brief ESSA Stack client-side public API declaration
********************************************************************************************
* @version           interface UHF v0.5
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

#ifndef FP_UHFPROTOCOLCLIENT_H
#define FP_UHFPROTOCOLCLIENT_H

#include "FP_UHFProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define UHF_PROTOCOL_VERSION_MAJOR   ((uint8_t) 0)
#define UHF_PROTOCOL_VERSION_MINOR   ((uint8_t) 5)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfUHF_ReadNumberOfRxPacketsResponseHandler_t)(RespContext_t *pRespCtx,
              const UHFReadNumberOfRxPacketsResponseData_t *pResponseData);

typedef void (*pfUHF_ExBeaconSetSendResponseHandler_t)(RespContext_t *pRespCtx,
              const UHFExBeaconSetSendResponseData_t *pResponseData);

typedef void (*pfUHF_ReadCountersResponseHandler_t)(RespContext_t *pRespCtx,
              const UHFReadCountersResponseData_t *pResponseData);


typedef struct {
    pfUHF_ReadNumberOfRxPacketsResponseHandler_t UHF_ReadNumberOfRxPacketsResponseHandler;
    pfUHF_ExBeaconSetSendResponseHandler_t UHF_ExBeaconSetSendResponseHandler;
    pfUHF_ReadCountersResponseHandler_t UHF_ReadCountersResponseHandler;
} UHF_ClientApi_t;

/**********************************************************************
 *
 *  Client protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_UHFProtocolClientInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void UHF_registerClientApi(UHF_ClientApi_t *pCliApiHandlers);

// @deprecated - will be removed in the future - use FP_UHFProtocolClientInfo directly
ESSA_pStack_FunctionProtocolInfo_t UHF_getClientProtocolDescriptor(void);

ESSATMAC_ErrCodes UHF_ReadNumberOfRxPacketsReq(
                ReqContext_t* ctx);

ESSATMAC_ErrCodes UHF_ExBeaconSetSendReq(
                ReqContext_t* ctx,
                const UHF_sExBeacon_t * const sData
);

ESSATMAC_ErrCodes UHF_ReadCountersReq(
                ReqContext_t* ctx);


#endif  // #ifndef FP_UHFPROTOCOLCLIENT_H

