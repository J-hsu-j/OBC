/*!
********************************************************************************************
* @file FP_EPSII_BP_1ClientApp.c
* @brief ClientApp implementation template generator
********************************************************************************************
* @version           interface EPSII_BP_1 v3.0
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

#include "FP_EPSII_BP_1ProtocolClient.h"

// @START_USER@ USER_INCLUDES
// Place user includes here to preserve them during merge!!!
#include "eps_ii_telemetry.h"
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL

static void EPSII_BP_1_GetRAWSensorsResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_BP_1GetRAWSensorsResponseData_t* pResponseData);

static void EPSII_BP_1_GetBatteryInfoResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_BP_1GetBatteryInfoResponseData_t* pResponseData);

static void EPSII_BP_1_GetDeviceHealthInfoResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_BP_1GetDeviceHealthInfoResponseData_t* pResponseData);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)
// @END_USER@ USER_LOCAL_VARS_DECL

static EPSII_BP_1_ClientApi_t EPSII_BP_1ClientApiCtx =
{
  .EPSII_BP_1_GetRAWSensorsResponseHandler = (pfEPSII_BP_1_GetRAWSensorsResponseHandler_t) EPSII_BP_1_GetRAWSensorsResponseHandlerImpl,
  .EPSII_BP_1_GetBatteryInfoResponseHandler = (pfEPSII_BP_1_GetBatteryInfoResponseHandler_t) EPSII_BP_1_GetBatteryInfoResponseHandlerImpl,
  .EPSII_BP_1_GetDeviceHealthInfoResponseHandler = (pfEPSII_BP_1_GetDeviceHealthInfoResponseHandler_t) EPSII_BP_1_GetDeviceHealthInfoResponseHandlerImpl,
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Response handler for method EPSII_BP_1::GetRAWSensors (ID = 0x00000002)
static void EPSII_BP_1_GetRAWSensorsResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_BP_1GetRAWSensorsResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@EPSII_BP_1::GetRAWSensors@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@EPSII_BP_1::GetRAWSensors@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@EPSII_BP_1::GetRAWSensors@
        
        eps_ii_raw_sensors_notif(pRespCtx, pResponseData);
        
        // @USER_CODE_SECTION_END@EPSII_BP_1::GetRAWSensors@
    }
}
// @END@ Response handler for method EPSII_BP_1::GetRAWSensors (ID = 0x00000002)

// @START@ Response handler for method EPSII_BP_1::GetBatteryInfo (ID = 0x00000003)
static void EPSII_BP_1_GetBatteryInfoResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_BP_1GetBatteryInfoResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@EPSII_BP_1::GetBatteryInfo@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@EPSII_BP_1::GetBatteryInfo@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@EPSII_BP_1::GetBatteryInfo@
        
        // Callback to eps_ii drivers to update the datacache
        eps_ii_batt_info_notif(pRespCtx, pResponseData);
        
        // @USER_CODE_SECTION_END@EPSII_BP_1::GetBatteryInfo@
    }
}
// @END@ Response handler for method EPSII_BP_1::GetBatteryInfo (ID = 0x00000003)

// @START@ Response handler for method EPSII_BP_1::GetDeviceHealthInfo (ID = 0x00000004)
static void EPSII_BP_1_GetDeviceHealthInfoResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_BP_1GetDeviceHealthInfoResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@EPSII_BP_1::GetDeviceHealthInfo@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@EPSII_BP_1::GetDeviceHealthInfo@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@EPSII_BP_1::GetDeviceHealthInfo@
        
        eps_ii_bp_dev_health_notif(pRespCtx, pResponseData);
        
        // @USER_CODE_SECTION_END@EPSII_BP_1::GetDeviceHealthInfo@
    }
}
// @END@ Response handler for method EPSII_BP_1::GetDeviceHealthInfo (ID = 0x00000004)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void EPSII_BP_1ClientAppInit(void)
{
    EPSII_BP_1_registerClientApi(&EPSII_BP_1ClientApiCtx);
}
