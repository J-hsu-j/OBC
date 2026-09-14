/*!
********************************************************************************************
* @file FP_sp_uhf_antClientApp.c
* @brief ClientApp implementation template generator
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

#include "FP_sp_uhf_antProtocolClient.h"

// @START_USER@ USER_INCLUDES
#include "sp_service.h"
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL

static void sp_uhf_ant_telemetryResponseHandlerImpl(RespContext_t* pRespCtx,
            const sp_uhf_anttelemetryResponseData_t* pResponseData);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_VARS_DECL

static sp_uhf_ant_ClientApi_t sp_uhf_antClientApiCtx =
{
  .sp_uhf_ant_telemetryResponseHandler = (pfsp_uhf_ant_telemetryResponseHandler_t) sp_uhf_ant_telemetryResponseHandlerImpl,
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Response handler for method sp_uhf_ant::telemetry (ID = 0x00000500)
static void sp_uhf_ant_telemetryResponseHandlerImpl(RespContext_t* pRespCtx,
            const sp_uhf_anttelemetryResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@sp_uhf_ant::telemetry@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@sp_uhf_ant::telemetry@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@sp_uhf_ant::telemetry@
        
        sp_response_received(pRespCtx, pResponseData);
        
        // @USER_CODE_SECTION_END@sp_uhf_ant::telemetry@
    }
}
// @END@ Response handler for method sp_uhf_ant::telemetry (ID = 0x00000500)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void sp_uhf_antClientAppInit(void)
{
    sp_uhf_ant_registerClientApi(&sp_uhf_antClientApiCtx);
}
