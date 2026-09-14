/*!
********************************************************************************************
* @file FP_eps_iii_pdm_aClientApp.c
* @brief ClientApp implementation template generator
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

#include "FP_eps_iii_pdm_aProtocolClient.h"

// @START_USER@ USER_INCLUDES
// Place user includes here to preserve them during merge!!!

#include "eps_iii_pdm_a.h"

// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL

static void eps_iii_pdm_a_get_telemetryResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_pdm_aget_telemetryResponseData_t* pResponseData);

static void eps_iii_pdm_a_external_system_bus_controlResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_pdm_aexternal_system_bus_controlResponseData_t* pResponseData);

static void eps_iii_pdm_a_low_volt_controlResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_pdm_alow_volt_controlResponseData_t* pResponseData);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_VARS_DECL

static eps_iii_pdm_a_ClientApi_t eps_iii_pdm_aClientApiCtx =
{
  .eps_iii_pdm_a_get_telemetryResponseHandler = (pfeps_iii_pdm_a_get_telemetryResponseHandler_t) eps_iii_pdm_a_get_telemetryResponseHandlerImpl,
  .eps_iii_pdm_a_external_system_bus_controlResponseHandler = (pfeps_iii_pdm_a_external_system_bus_controlResponseHandler_t) eps_iii_pdm_a_external_system_bus_controlResponseHandlerImpl,
  .eps_iii_pdm_a_low_volt_controlResponseHandler = (pfeps_iii_pdm_a_low_volt_controlResponseHandler_t) eps_iii_pdm_a_low_volt_controlResponseHandlerImpl,
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Response handler for method eps_iii_pdm_a::get_telemetry (ID = 0x00000000)
static void eps_iii_pdm_a_get_telemetryResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_pdm_aget_telemetryResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@eps_iii_pdm_a::get_telemetry@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@eps_iii_pdm_a::get_telemetry@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@eps_iii_pdm_a::get_telemetry@
        
        eps_iii_pdm_a_get_telemetry_notif(pRespCtx, pResponseData);
        // @USER_CODE_SECTION_END@eps_iii_pdm_a::get_telemetry@
    }
}
// @END@ Response handler for method eps_iii_pdm_a::get_telemetry (ID = 0x00000000)

// @START@ Response handler for method eps_iii_pdm_a::external_system_bus_control (ID = 0x00000020)
static void eps_iii_pdm_a_external_system_bus_controlResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_pdm_aexternal_system_bus_controlResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@eps_iii_pdm_a::external_system_bus_control@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@eps_iii_pdm_a::external_system_bus_control@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@eps_iii_pdm_a::external_system_bus_control@
        
        eps_iii_pdm_a_system_bus_notif(pRespCtx, pResponseData);

        // @USER_CODE_SECTION_END@eps_iii_pdm_a::external_system_bus_control@
    }
}
// @END@ Response handler for method eps_iii_pdm_a::external_system_bus_control (ID = 0x00000020)

// @START@ Response handler for method eps_iii_pdm_a::low_volt_control (ID = 0x00000030)
static void eps_iii_pdm_a_low_volt_controlResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_pdm_alow_volt_controlResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@eps_iii_pdm_a::low_volt_control@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@eps_iii_pdm_a::low_volt_control@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@eps_iii_pdm_a::low_volt_control@
        
        eps_iii_pdm_a_low_volt_notif(pRespCtx, pResponseData);
        
        // @USER_CODE_SECTION_END@eps_iii_pdm_a::low_volt_control@
    }
}
// @END@ Response handler for method eps_iii_pdm_a::low_volt_control (ID = 0x00000030)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void eps_iii_pdm_aClientAppInit(void)
{
    eps_iii_pdm_a_registerClientApi(&eps_iii_pdm_aClientApiCtx);
}
