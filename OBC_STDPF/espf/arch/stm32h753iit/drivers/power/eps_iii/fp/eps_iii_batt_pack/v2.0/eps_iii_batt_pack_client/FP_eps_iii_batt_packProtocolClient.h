/*!
********************************************************************************************
* @file FP_eps_iii_batt_packProtocolClient.h
* @brief ESSA Stack client-side public API declaration
********************************************************************************************
* @version           interface eps_iii_batt_pack v2.0
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

#ifndef FP_EPS_III_BATT_PACKPROTOCOLCLIENT_H
#define FP_EPS_III_BATT_PACKPROTOCOLCLIENT_H

#include "FP_eps_iii_batt_packProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define eps_iii_batt_pack_PROTOCOL_VERSION_MAJOR   ((uint8_t) 2)
#define eps_iii_batt_pack_PROTOCOL_VERSION_MINOR   ((uint8_t) 0)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfeps_iii_batt_pack_get_telemetryResponseHandler_t)(RespContext_t *pRespCtx,
              const eps_iii_batt_packget_telemetryResponseData_t *pResponseData);


typedef struct {
    pfeps_iii_batt_pack_get_telemetryResponseHandler_t eps_iii_batt_pack_get_telemetryResponseHandler;
} eps_iii_batt_pack_ClientApi_t;

/**********************************************************************
 *
 *  Client protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_eps_iii_batt_packProtocolClientInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void eps_iii_batt_pack_registerClientApi(eps_iii_batt_pack_ClientApi_t *pCliApiHandlers);

// @deprecated - will be removed in the future - use FP_eps_iii_batt_packProtocolClientInfo directly
ESSA_pStack_FunctionProtocolInfo_t eps_iii_batt_pack_getClientProtocolDescriptor(void);

ESSATMAC_ErrCodes eps_iii_batt_pack_get_telemetryReq(
                ReqContext_t* ctx);


#endif  // #ifndef FP_EPS_III_BATT_PACKPROTOCOLCLIENT_H

