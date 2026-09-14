/*!
********************************************************************************************
* @file FP_eps_iii_batt_packClientApp.c
* @brief ClientApp implementation template generator
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

#include "FP_eps_iii_batt_packProtocolClient.h"

// @START_USER@ USER_INCLUDES
#include "eps_iii_bp.h"
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL

static void eps_iii_batt_pack_get_telemetryResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_batt_packget_telemetryResponseData_t* pResponseData);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_VARS_DECL

static eps_iii_batt_pack_ClientApi_t eps_iii_batt_packClientApiCtx =
{
  .eps_iii_batt_pack_get_telemetryResponseHandler = (pfeps_iii_batt_pack_get_telemetryResponseHandler_t) eps_iii_batt_pack_get_telemetryResponseHandlerImpl,
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Response handler for method eps_iii_batt_pack::get_telemetry (ID = 0x00000000)
static void eps_iii_batt_pack_get_telemetryResponseHandlerImpl(RespContext_t* pRespCtx,
            const eps_iii_batt_packget_telemetryResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@eps_iii_batt_pack::get_telemetry@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@eps_iii_batt_pack::get_telemetry@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@eps_iii_batt_pack::get_telemetry@
        
        eps_iii_bp_get_telemetry_notif(pRespCtx, pResponseData);

        // @USER_CODE_SECTION_END@eps_iii_batt_pack::get_telemetry@
    }
}
// @END@ Response handler for method eps_iii_batt_pack::get_telemetry (ID = 0x00000000)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void eps_iii_batt_packClientAppInit(void)
{
    eps_iii_batt_pack_registerClientApi(&eps_iii_batt_packClientApiCtx);
}
