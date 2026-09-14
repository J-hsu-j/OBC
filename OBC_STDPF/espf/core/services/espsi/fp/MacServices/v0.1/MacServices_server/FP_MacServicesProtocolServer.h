/*!
********************************************************************************************
* @file FP_MacServicesProtocolServer.h
* @brief ESSA Stack server-side public API declaration
********************************************************************************************
* @version           interface MacServices v0.1
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

#ifndef FP_MACSERVICESPROTOCOLSERVER_H
#define FP_MACSERVICESPROTOCOLSERVER_H

#include "FP_MacServicesProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define MacServices_PROTOCOL_VERSION_MAJOR   ((uint8_t) 0)
#define MacServices_PROTOCOL_VERSION_MINOR   ((uint8_t) 1)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfMacServices_getMacBusTerminationSettingRequestHandler_t)(ReqContext_t *ctx, const MacServicesgetMacBusTerminationSettingRequestData_t *pRequestData);
typedef void (*pfMacServices_setMacBusTerminationSettingRequestHandler_t)(ReqContext_t *ctx, const MacServicessetMacBusTerminationSettingRequestData_t *pRequestData);
typedef void (*pfMacServices_setMacAddressRequestHandler_t)(ReqContext_t *ctx, const MacServicessetMacAddressRequestData_t *pRequestData);

typedef struct {
    pfMacServices_getMacBusTerminationSettingRequestHandler_t MacServices_getMacBusTerminationSettingRequestHandler;
    pfMacServices_setMacBusTerminationSettingRequestHandler_t MacServices_setMacBusTerminationSettingRequestHandler;
    pfMacServices_setMacAddressRequestHandler_t MacServices_setMacAddressRequestHandler;
} MacServices_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_MacServicesProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void MacServices_registerServerApi(MacServices_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_MacServicesProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t MacServices_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes MacServices_getMacBusTerminationSettingResp(
                RespContext_t* ctx,
                const uint8_t u8SupportedInterfacesBitField,
                const uint8_t u8BusTerminationSettingsBitField
);

ESSATMAC_ErrCodes MacServices_setMacBusTerminationSettingResp(
                RespContext_t* ctx);

ESSATMAC_ErrCodes MacServices_setMacAddressResp(
                RespContext_t* ctx,
                const uint8_t u8UpdatedMacAddr
);


#endif  // #ifndef FP_MACSERVICESPROTOCOLSERVER_H
