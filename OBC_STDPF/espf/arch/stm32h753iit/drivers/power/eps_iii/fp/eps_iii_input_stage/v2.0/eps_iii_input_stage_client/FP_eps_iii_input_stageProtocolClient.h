/*!
********************************************************************************************
* @file FP_eps_iii_input_stageProtocolClient.h
* @brief ESSA Stack client-side public API declaration
********************************************************************************************
* @version           interface eps_iii_input_stage v2.0
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

#ifndef FP_EPS_III_INPUT_STAGEPROTOCOLCLIENT_H
#define FP_EPS_III_INPUT_STAGEPROTOCOLCLIENT_H

#include "FP_eps_iii_input_stageProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define eps_iii_input_stage_PROTOCOL_VERSION_MAJOR   ((uint8_t) 2)
#define eps_iii_input_stage_PROTOCOL_VERSION_MINOR   ((uint8_t) 0)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfeps_iii_input_stage_get_telemetryResponseHandler_t)(RespContext_t *pRespCtx,
              const eps_iii_input_stageget_telemetryResponseData_t *pResponseData);


typedef struct {
    pfeps_iii_input_stage_get_telemetryResponseHandler_t eps_iii_input_stage_get_telemetryResponseHandler;
} eps_iii_input_stage_ClientApi_t;

/**********************************************************************
 *
 *  Client protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_eps_iii_input_stageProtocolClientInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void eps_iii_input_stage_registerClientApi(eps_iii_input_stage_ClientApi_t *pCliApiHandlers);

// @deprecated - will be removed in the future - use FP_eps_iii_input_stageProtocolClientInfo directly
ESSA_pStack_FunctionProtocolInfo_t eps_iii_input_stage_getClientProtocolDescriptor(void);

ESSATMAC_ErrCodes eps_iii_input_stage_get_telemetryReq(
                ReqContext_t* ctx);


#endif  // #ifndef FP_EPS_III_INPUT_STAGEPROTOCOLCLIENT_H

