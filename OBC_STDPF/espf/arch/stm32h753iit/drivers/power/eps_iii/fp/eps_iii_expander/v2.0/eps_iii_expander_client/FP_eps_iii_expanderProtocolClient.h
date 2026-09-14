/*!
********************************************************************************************
* @file FP_eps_iii_expanderProtocolClient.h
* @brief ESSA Stack client-side public API declaration
********************************************************************************************
* @version           interface eps_iii_expander v2.0
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

#ifndef FP_EPS_III_EXPANDERPROTOCOLCLIENT_H
#define FP_EPS_III_EXPANDERPROTOCOLCLIENT_H

#include "FP_eps_iii_expanderProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define eps_iii_expander_PROTOCOL_VERSION_MAJOR   ((uint8_t) 2)
#define eps_iii_expander_PROTOCOL_VERSION_MINOR   ((uint8_t) 0)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfeps_iii_expander_get_telemetryResponseHandler_t)(RespContext_t *pRespCtx,
              const eps_iii_expanderget_telemetryResponseData_t *pResponseData);

typedef void (*pfeps_iii_expander_h1_channels_controlResponseHandler_t)(RespContext_t *pRespCtx,
              const eps_iii_expanderh1_channels_controlResponseData_t *pResponseData);

typedef void (*pfeps_iii_expander_gpio_controlResponseHandler_t)(RespContext_t *pRespCtx,
              const eps_iii_expandergpio_controlResponseData_t *pResponseData);

typedef void (*pfeps_iii_expander_interconnect_controlResponseHandler_t)(RespContext_t *pRespCtx,
              const eps_iii_expanderinterconnect_controlResponseData_t *pResponseData);

typedef void (*pfeps_iii_expander_release_5vResponseHandler_t)(RespContext_t *pRespCtx,
              const eps_iii_expanderrelease_5vResponseData_t *pResponseData);

typedef void (*pfeps_iii_expander_release_controlResponseHandler_t)(RespContext_t *pRespCtx,
              const eps_iii_expanderrelease_controlResponseData_t *pResponseData);


typedef struct {
    pfeps_iii_expander_get_telemetryResponseHandler_t eps_iii_expander_get_telemetryResponseHandler;
    pfeps_iii_expander_h1_channels_controlResponseHandler_t eps_iii_expander_h1_channels_controlResponseHandler;
    pfeps_iii_expander_gpio_controlResponseHandler_t eps_iii_expander_gpio_controlResponseHandler;
    pfeps_iii_expander_interconnect_controlResponseHandler_t eps_iii_expander_interconnect_controlResponseHandler;
    pfeps_iii_expander_release_5vResponseHandler_t eps_iii_expander_release_5vResponseHandler;
    pfeps_iii_expander_release_controlResponseHandler_t eps_iii_expander_release_controlResponseHandler;
} eps_iii_expander_ClientApi_t;

/**********************************************************************
 *
 *  Client protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_eps_iii_expanderProtocolClientInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void eps_iii_expander_registerClientApi(eps_iii_expander_ClientApi_t *pCliApiHandlers);

// @deprecated - will be removed in the future - use FP_eps_iii_expanderProtocolClientInfo directly
ESSA_pStack_FunctionProtocolInfo_t eps_iii_expander_getClientProtocolDescriptor(void);

ESSATMAC_ErrCodes eps_iii_expander_get_telemetryReq(
                ReqContext_t* ctx);

ESSATMAC_ErrCodes eps_iii_expander_h1_channels_controlReq(
                ReqContext_t* ctx,
                const EPS_III_EXPANDER_HLVChannelId_t eH1_channel,
                const EPS_III_EXPANDER_ChannelOpt_t eH1_option,
                const uint16_t u16H1_time
);

ESSATMAC_ErrCodes eps_iii_expander_gpio_controlReq(
                ReqContext_t* ctx,
                const EPS_III_EXPANDER_GPIOChannelId_t eGo_channel,
                const EPS_III_EXPANDER_ChannelOpt_t eGo_option,
                const uint16_t u16Go_time
);

ESSATMAC_ErrCodes eps_iii_expander_interconnect_controlReq(
                ReqContext_t* ctx,
                const EPS_III_EXPANDER_IntercChannelId_t eIc_channel,
                const EPS_III_EXPANDER_ChannelOpt_t eIc_option,
                const uint16_t u16Ic_time
);

ESSATMAC_ErrCodes eps_iii_expander_release_5vReq(
                ReqContext_t* ctx,
                const EPS_III_EXPANDER_R5VChannelId_t eRl_5v_channel,
                const EPS_III_EXPANDER_ChannelOpt_t eRl_5v_option,
                const uint16_t u16Rl_5v_time
);

ESSATMAC_ErrCodes eps_iii_expander_release_controlReq(
                ReqContext_t* ctx,
                const EPS_III_EXPANDER_RChannelId_t eRl_channel,
                const EPS_III_EXPANDER_RChannelOpt_t eRl_option,
                const uint16_t u16Rl_time
);


#endif  // #ifndef FP_EPS_III_EXPANDERPROTOCOLCLIENT_H

