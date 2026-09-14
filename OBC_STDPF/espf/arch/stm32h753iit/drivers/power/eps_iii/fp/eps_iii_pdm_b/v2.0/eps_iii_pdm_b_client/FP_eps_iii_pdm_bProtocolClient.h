/*!
********************************************************************************************
* @file FP_eps_iii_pdm_bProtocolClient.h
* @brief ESSA Stack client-side public API declaration
********************************************************************************************
* @version           interface eps_iii_pdm_b v2.0
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

#ifndef FP_EPS_III_PDM_BPROTOCOLCLIENT_H
#define FP_EPS_III_PDM_BPROTOCOLCLIENT_H

#include "FP_eps_iii_pdm_bProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define eps_iii_pdm_b_PROTOCOL_VERSION_MAJOR   ((uint8_t) 2)
#define eps_iii_pdm_b_PROTOCOL_VERSION_MINOR   ((uint8_t) 0)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfeps_iii_pdm_b_get_telemetryResponseHandler_t)(RespContext_t *pRespCtx,
              const eps_iii_pdm_bget_telemetryResponseData_t *pResponseData);

typedef void (*pfeps_iii_pdm_b_A_B_controlResponseHandler_t)(RespContext_t *pRespCtx,
              const eps_iii_pdm_bA_B_controlResponseData_t *pResponseData);


typedef struct {
    pfeps_iii_pdm_b_get_telemetryResponseHandler_t eps_iii_pdm_b_get_telemetryResponseHandler;
    pfeps_iii_pdm_b_A_B_controlResponseHandler_t eps_iii_pdm_b_A_B_controlResponseHandler;
} eps_iii_pdm_b_ClientApi_t;

/**********************************************************************
 *
 *  Client protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_eps_iii_pdm_bProtocolClientInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void eps_iii_pdm_b_registerClientApi(eps_iii_pdm_b_ClientApi_t *pCliApiHandlers);

// @deprecated - will be removed in the future - use FP_eps_iii_pdm_bProtocolClientInfo directly
ESSA_pStack_FunctionProtocolInfo_t eps_iii_pdm_b_getClientProtocolDescriptor(void);

ESSATMAC_ErrCodes eps_iii_pdm_b_get_telemetryReq(
                ReqContext_t* ctx);

ESSATMAC_ErrCodes eps_iii_pdm_b_A_B_controlReq(
                ReqContext_t* ctx,
                const EPS_III_PDM_B_A_B_Channels_t eChannel_id,
                const EPS_III_PDM_B_ChannelOpt_t eChannel_opt,
                const uint16_t u16Channel_opt_time
);


#endif  // #ifndef FP_EPS_III_PDM_BPROTOCOLCLIENT_H

