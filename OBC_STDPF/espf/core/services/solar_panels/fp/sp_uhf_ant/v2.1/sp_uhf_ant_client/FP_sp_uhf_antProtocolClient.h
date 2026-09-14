/*!
********************************************************************************************
* @file FP_sp_uhf_antProtocolClient.h
* @brief ESSA Stack client-side public API declaration
********************************************************************************************
* @version           interface sp_uhf_ant v2.1
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

#ifndef FP_SP_UHF_ANTPROTOCOLCLIENT_H
#define FP_SP_UHF_ANTPROTOCOLCLIENT_H

#include "FP_sp_uhf_antProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define sp_uhf_ant_PROTOCOL_VERSION_MAJOR   ((uint8_t) 2)
#define sp_uhf_ant_PROTOCOL_VERSION_MINOR   ((uint8_t) 1)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfsp_uhf_ant_telemetryResponseHandler_t)(RespContext_t *pRespCtx,
              const sp_uhf_anttelemetryResponseData_t *pResponseData);


typedef struct {
    pfsp_uhf_ant_telemetryResponseHandler_t sp_uhf_ant_telemetryResponseHandler;
} sp_uhf_ant_ClientApi_t;

/**********************************************************************
 *
 *  Client protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_sp_uhf_antProtocolClientInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void sp_uhf_ant_registerClientApi(sp_uhf_ant_ClientApi_t *pCliApiHandlers);

// @deprecated - will be removed in the future - use FP_sp_uhf_antProtocolClientInfo directly
ESSA_pStack_FunctionProtocolInfo_t sp_uhf_ant_getClientProtocolDescriptor(void);

ESSATMAC_ErrCodes sp_uhf_ant_telemetryReq(
                ReqContext_t* ctx);


#endif  // #ifndef FP_SP_UHF_ANTPROTOCOLCLIENT_H

