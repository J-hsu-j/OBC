/*!
********************************************************************************************
* @file FP_eps_iii_pdm_aProtocolClient.h
* @brief ESSA Stack client-side public API declaration
********************************************************************************************
* @version           interface eps_iii_pdm_a v2.0
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

#ifndef FP_EPS_III_PDM_APROTOCOLCLIENT_H
#define FP_EPS_III_PDM_APROTOCOLCLIENT_H

#include "FP_eps_iii_pdm_aProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define eps_iii_pdm_a_PROTOCOL_VERSION_MAJOR   ((uint8_t) 2)
#define eps_iii_pdm_a_PROTOCOL_VERSION_MINOR   ((uint8_t) 0)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfeps_iii_pdm_a_get_telemetryResponseHandler_t)(RespContext_t *pRespCtx,
              const eps_iii_pdm_aget_telemetryResponseData_t *pResponseData);

typedef void (*pfeps_iii_pdm_a_external_system_bus_controlResponseHandler_t)(RespContext_t *pRespCtx,
              const eps_iii_pdm_aexternal_system_bus_controlResponseData_t *pResponseData);

typedef void (*pfeps_iii_pdm_a_low_volt_controlResponseHandler_t)(RespContext_t *pRespCtx,
              const eps_iii_pdm_alow_volt_controlResponseData_t *pResponseData);


typedef struct {
    pfeps_iii_pdm_a_get_telemetryResponseHandler_t eps_iii_pdm_a_get_telemetryResponseHandler;
    pfeps_iii_pdm_a_external_system_bus_controlResponseHandler_t eps_iii_pdm_a_external_system_bus_controlResponseHandler;
    pfeps_iii_pdm_a_low_volt_controlResponseHandler_t eps_iii_pdm_a_low_volt_controlResponseHandler;
} eps_iii_pdm_a_ClientApi_t;

/**********************************************************************
 *
 *  Client protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_eps_iii_pdm_aProtocolClientInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void eps_iii_pdm_a_registerClientApi(eps_iii_pdm_a_ClientApi_t *pCliApiHandlers);

// @deprecated - will be removed in the future - use FP_eps_iii_pdm_aProtocolClientInfo directly
ESSA_pStack_FunctionProtocolInfo_t eps_iii_pdm_a_getClientProtocolDescriptor(void);

ESSATMAC_ErrCodes eps_iii_pdm_a_get_telemetryReq(
                ReqContext_t* ctx);

ESSATMAC_ErrCodes eps_iii_pdm_a_external_system_bus_controlReq(
                ReqContext_t* ctx,
                const EPS_III_PDM_A_ChannelOpt_t eExt_sys_bus_option,
                const uint16_t u16Ext_sys_bus_time
);

ESSATMAC_ErrCodes eps_iii_pdm_a_low_volt_controlReq(
                ReqContext_t* ctx,
                const EPS_III_PDM_A_LowVoltageChannels_t eLow_volt_ch,
                const EPS_III_PDM_A_ChannelOpt_t eLow_volt_option,
                const uint16_t u16Low_volt_time
);


#endif  // #ifndef FP_EPS_III_PDM_APROTOCOLCLIENT_H

