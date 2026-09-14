/*!
********************************************************************************************
* @file FP_EPSII_BP_1ProtocolClient.h
* @brief ESSA Stack client-side public API declaration
********************************************************************************************
* @version           interface EPSII_BP_1 v3.0
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

#ifndef FP_EPSII_BP_1PROTOCOLCLIENT_H
#define FP_EPSII_BP_1PROTOCOLCLIENT_H

#include "FP_EPSII_BP_1ProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define EPSII_BP_1_PROTOCOL_VERSION_MAJOR   ((uint8_t) 3)
#define EPSII_BP_1_PROTOCOL_VERSION_MINOR   ((uint8_t) 0)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfEPSII_BP_1_GetRAWSensorsResponseHandler_t)(RespContext_t *pRespCtx,
              const EPSII_BP_1GetRAWSensorsResponseData_t *pResponseData);

typedef void (*pfEPSII_BP_1_GetBatteryInfoResponseHandler_t)(RespContext_t *pRespCtx,
              const EPSII_BP_1GetBatteryInfoResponseData_t *pResponseData);

typedef void (*pfEPSII_BP_1_GetDeviceHealthInfoResponseHandler_t)(RespContext_t *pRespCtx,
              const EPSII_BP_1GetDeviceHealthInfoResponseData_t *pResponseData);


typedef struct {
    pfEPSII_BP_1_GetRAWSensorsResponseHandler_t EPSII_BP_1_GetRAWSensorsResponseHandler;
    pfEPSII_BP_1_GetBatteryInfoResponseHandler_t EPSII_BP_1_GetBatteryInfoResponseHandler;
    pfEPSII_BP_1_GetDeviceHealthInfoResponseHandler_t EPSII_BP_1_GetDeviceHealthInfoResponseHandler;
} EPSII_BP_1_ClientApi_t;

/**********************************************************************
 *
 *  Client protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_EPSII_BP_1ProtocolClientInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void EPSII_BP_1_registerClientApi(EPSII_BP_1_ClientApi_t *pCliApiHandlers);

// @deprecated - will be removed in the future - use FP_EPSII_BP_1ProtocolClientInfo directly
ESSA_pStack_FunctionProtocolInfo_t EPSII_BP_1_getClientProtocolDescriptor(void);

ESSATMAC_ErrCodes EPSII_BP_1_GetRAWSensorsReq(
                ReqContext_t* ctx,
                const uint32_t u32PktIDReq,
                const EPSII_BP_1_EPSIIT_SensorIDs_t * const aeSensorsIDs
);

ESSATMAC_ErrCodes EPSII_BP_1_GetBatteryInfoReq(
                ReqContext_t* ctx);

ESSATMAC_ErrCodes EPSII_BP_1_GetDeviceHealthInfoReq(
                ReqContext_t* ctx);


#endif  // #ifndef FP_EPSII_BP_1PROTOCOLCLIENT_H

