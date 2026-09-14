/*!
********************************************************************************************
* @file FP_eps_iii_expanderClientApp.c
* @brief ClientApp implementation template generator
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

#include "FP_eps_iii_expanderProtocolClient.h"

// @START_USER@ USER_INCLUDES
#include "eps_iii_expander.h"
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL

static void eps_iii_expander_get_telemetryResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_expanderget_telemetryResponseData_t* pResponseData);

static void eps_iii_expander_h1_channels_controlResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_expanderh1_channels_controlResponseData_t* pResponseData);

static void eps_iii_expander_gpio_controlResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_expandergpio_controlResponseData_t* pResponseData);

static void eps_iii_expander_interconnect_controlResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_expanderinterconnect_controlResponseData_t* pResponseData);

static void eps_iii_expander_release_5vResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_expanderrelease_5vResponseData_t* pResponseData);

static void eps_iii_expander_release_controlResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_expanderrelease_controlResponseData_t* pResponseData);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_VARS_DECL

static eps_iii_expander_ClientApi_t eps_iii_expanderClientApiCtx =
{
  .eps_iii_expander_get_telemetryResponseHandler = (pfeps_iii_expander_get_telemetryResponseHandler_t) eps_iii_expander_get_telemetryResponseHandlerImpl,
  .eps_iii_expander_h1_channels_controlResponseHandler = (pfeps_iii_expander_h1_channels_controlResponseHandler_t) eps_iii_expander_h1_channels_controlResponseHandlerImpl,
  .eps_iii_expander_gpio_controlResponseHandler = (pfeps_iii_expander_gpio_controlResponseHandler_t) eps_iii_expander_gpio_controlResponseHandlerImpl,
  .eps_iii_expander_interconnect_controlResponseHandler = (pfeps_iii_expander_interconnect_controlResponseHandler_t) eps_iii_expander_interconnect_controlResponseHandlerImpl,
  .eps_iii_expander_release_5vResponseHandler = (pfeps_iii_expander_release_5vResponseHandler_t) eps_iii_expander_release_5vResponseHandlerImpl,
  .eps_iii_expander_release_controlResponseHandler = (pfeps_iii_expander_release_controlResponseHandler_t) eps_iii_expander_release_controlResponseHandlerImpl,
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Response handler for method eps_iii_expander::get_telemetry (ID = 0x00000000)
static void eps_iii_expander_get_telemetryResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_expanderget_telemetryResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@eps_iii_expander::get_telemetry@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@eps_iii_expander::get_telemetry@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@eps_iii_expander::get_telemetry@
        
        eps_iii_expander_get_telemetry_notif(pRespCtx, pResponseData);
        
        // @USER_CODE_SECTION_END@eps_iii_expander::get_telemetry@
    }
}
// @END@ Response handler for method eps_iii_expander::get_telemetry (ID = 0x00000000)

// @START@ Response handler for method eps_iii_expander::h1_channels_control (ID = 0x00000020)
static void eps_iii_expander_h1_channels_controlResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_expanderh1_channels_controlResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@eps_iii_expander::h1_channels_control@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@eps_iii_expander::h1_channels_control@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@eps_iii_expander::h1_channels_control@
        
        eps_iii_expander_h1_channels_control_notif(pRespCtx, pResponseData);
        
        // @USER_CODE_SECTION_END@eps_iii_expander::h1_channels_control@
    }
}
// @END@ Response handler for method eps_iii_expander::h1_channels_control (ID = 0x00000020)

// @START@ Response handler for method eps_iii_expander::gpio_control (ID = 0x00000030)
static void eps_iii_expander_gpio_controlResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_expandergpio_controlResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@eps_iii_expander::gpio_control@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@eps_iii_expander::gpio_control@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@eps_iii_expander::gpio_control@
        
        eps_iii_expander_gpio_control_notif(pRespCtx, pResponseData);
        
        // @USER_CODE_SECTION_END@eps_iii_expander::gpio_control@
    }
}
// @END@ Response handler for method eps_iii_expander::gpio_control (ID = 0x00000030)

// @START@ Response handler for method eps_iii_expander::interconnect_control (ID = 0x00000040)
static void eps_iii_expander_interconnect_controlResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_expanderinterconnect_controlResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@eps_iii_expander::interconnect_control@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@eps_iii_expander::interconnect_control@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@eps_iii_expander::interconnect_control@
        
        eps_iii_expander_interconnect_control_notif(pRespCtx, pResponseData);
        
        // @USER_CODE_SECTION_END@eps_iii_expander::interconnect_control@
    }
}
// @END@ Response handler for method eps_iii_expander::interconnect_control (ID = 0x00000040)

// @START@ Response handler for method eps_iii_expander::release_5v (ID = 0x00000050)
static void eps_iii_expander_release_5vResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_expanderrelease_5vResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@eps_iii_expander::release_5v@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@eps_iii_expander::release_5v@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@eps_iii_expander::release_5v@
        
        eps_iii_expander_release_5v_control_notif(pRespCtx, pResponseData);
        
        // @USER_CODE_SECTION_END@eps_iii_expander::release_5v@
    }
}
// @END@ Response handler for method eps_iii_expander::release_5v (ID = 0x00000050)

// @START@ Response handler for method eps_iii_expander::release_control (ID = 0x00000060)
static void eps_iii_expander_release_controlResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_expanderrelease_controlResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@eps_iii_expander::release_control@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@eps_iii_expander::release_control@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@eps_iii_expander::release_control@
        
        eps_iii_expander_release_control_notif(pRespCtx, pResponseData);
        
        // @USER_CODE_SECTION_END@eps_iii_expander::release_control@
    }
}
// @END@ Response handler for method eps_iii_expander::release_control (ID = 0x00000060)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void eps_iii_expanderClientAppInit(void)
{
    eps_iii_expander_registerClientApi(&eps_iii_expanderClientApiCtx);
}
