/*!
********************************************************************************************
* @file FP_EPSII_PDM_1ProtocolClient.h
* @brief ESSA Stack client-side public API declaration
********************************************************************************************
* @version           interface EPSII_PDM_1 v1.0
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

#ifndef FP_EPSII_PDM_1PROTOCOLCLIENT_H
#define FP_EPSII_PDM_1PROTOCOLCLIENT_H

#include "FP_EPSII_PDM_1ProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define EPSII_PDM_1_PROTOCOL_VERSION_MAJOR   ((uint8_t) 1)
#define EPSII_PDM_1_PROTOCOL_VERSION_MINOR   ((uint8_t) 0)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfEPSII_PDM_1_GetPowerDistributionInfoResponseHandler_t)(RespContext_t *pRespCtx,
              const EPSII_PDM_1GetPowerDistributionInfoResponseData_t *pResponseData);

typedef void (*pfEPSII_PDM_1_GetDeviceHealthInfoResponseHandler_t)(RespContext_t *pRespCtx,
              const EPSII_PDM_1GetDeviceHealthInfoResponseData_t *pResponseData);

typedef void (*pfEPSII_PDM_1_SetPC104GPIOResponseHandler_t)(RespContext_t *pRespCtx,
              const EPSII_PDM_1SetPC104GPIOResponseData_t *pResponseData);

typedef void (*pfEPSII_PDM_1_GetPC104GPIOResponseHandler_t)(RespContext_t *pRespCtx,
              const EPSII_PDM_1GetPC104GPIOResponseData_t *pResponseData);

typedef void (*pfEPSII_PDM_1_GetRAWSensorsResponseHandler_t)(RespContext_t *pRespCtx,
              const EPSII_PDM_1GetRAWSensorsResponseData_t *pResponseData);

typedef void (*pfEPSII_PDM_1_SetPowerOutputsResponseHandler_t)(RespContext_t *pRespCtx,
              const EPSII_PDM_1SetPowerOutputsResponseData_t *pResponseData);

typedef void (*pfEPSII_PDM_1_GetPowerOutputsResponseHandler_t)(RespContext_t *pRespCtx,
              const EPSII_PDM_1GetPowerOutputsResponseData_t *pResponseData);


typedef struct {
    pfEPSII_PDM_1_GetPowerDistributionInfoResponseHandler_t EPSII_PDM_1_GetPowerDistributionInfoResponseHandler;
    pfEPSII_PDM_1_GetDeviceHealthInfoResponseHandler_t EPSII_PDM_1_GetDeviceHealthInfoResponseHandler;
    pfEPSII_PDM_1_SetPC104GPIOResponseHandler_t EPSII_PDM_1_SetPC104GPIOResponseHandler;
    pfEPSII_PDM_1_GetPC104GPIOResponseHandler_t EPSII_PDM_1_GetPC104GPIOResponseHandler;
    pfEPSII_PDM_1_GetRAWSensorsResponseHandler_t EPSII_PDM_1_GetRAWSensorsResponseHandler;
    pfEPSII_PDM_1_SetPowerOutputsResponseHandler_t EPSII_PDM_1_SetPowerOutputsResponseHandler;
    pfEPSII_PDM_1_GetPowerOutputsResponseHandler_t EPSII_PDM_1_GetPowerOutputsResponseHandler;
} EPSII_PDM_1_ClientApi_t;

/**********************************************************************
 *
 *  Client protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_EPSII_PDM_1ProtocolClientInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void EPSII_PDM_1_registerClientApi(EPSII_PDM_1_ClientApi_t *pCliApiHandlers);

// @deprecated - will be removed in the future - use FP_EPSII_PDM_1ProtocolClientInfo directly
ESSA_pStack_FunctionProtocolInfo_t EPSII_PDM_1_getClientProtocolDescriptor(void);

ESSATMAC_ErrCodes EPSII_PDM_1_GetPowerDistributionInfoReq(
                ReqContext_t* ctx);

ESSATMAC_ErrCodes EPSII_PDM_1_GetDeviceHealthInfoReq(
                ReqContext_t* ctx);

ESSATMAC_ErrCodes EPSII_PDM_1_SetPC104GPIOReq(
                ReqContext_t* ctx,
                const EPSII_PDM_1_SGGPIO_Bitmask_t eFilterMask,
                const EPSII_PDM_1_SGGPIO_OnOff_mask_t eValuesMaskReq
);

ESSATMAC_ErrCodes EPSII_PDM_1_GetPC104GPIOReq(
                ReqContext_t* ctx);

ESSATMAC_ErrCodes EPSII_PDM_1_GetRAWSensorsReq(
                ReqContext_t* ctx,
                const uint32_t u32PktIDReq,
                const EPSII_PDM_1_ESEPSII_PDM_SensorIDs_t * const aeSensorsIDs
);

ESSATMAC_ErrCodes EPSII_PDM_1_SetPowerOutputsReq(
                ReqContext_t* ctx,
                const EPSII_PDM_1_SGPO_Bitmask_t eFilterMask,
                const EPSII_PDM_1_SGPO_ON_Off_Bitmask_t eValuesMask
);

ESSATMAC_ErrCodes EPSII_PDM_1_GetPowerOutputsReq(
                ReqContext_t* ctx);


#endif  // #ifndef FP_EPSII_PDM_1PROTOCOLCLIENT_H

