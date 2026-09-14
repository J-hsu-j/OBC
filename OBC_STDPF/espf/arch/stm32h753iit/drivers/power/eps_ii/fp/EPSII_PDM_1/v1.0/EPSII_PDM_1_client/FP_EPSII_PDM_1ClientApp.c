/*!
********************************************************************************************
* @file FP_EPSII_PDM_1ClientApp.c
* @brief ClientApp implementation template generator
********************************************************************************************
* @version           interface EPSII_PDM_1 v1.0
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

#include "FP_EPSII_PDM_1ProtocolClient.h"

// @START_USER@ USER_INCLUDES
#include "eps_ctrl_cfg.h"
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

static void EPSII_PDM_1_GetPowerDistributionInfoResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_PDM_1GetPowerDistributionInfoResponseData_t* pResponseData);

static void EPSII_PDM_1_GetDeviceHealthInfoResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_PDM_1GetDeviceHealthInfoResponseData_t* pResponseData);

static void EPSII_PDM_1_SetPC104GPIOResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_PDM_1SetPC104GPIOResponseData_t* pResponseData);

static void EPSII_PDM_1_GetPC104GPIOResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_PDM_1GetPC104GPIOResponseData_t* pResponseData);

static void EPSII_PDM_1_GetRAWSensorsResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_PDM_1GetRAWSensorsResponseData_t* pResponseData);

static void EPSII_PDM_1_SetPowerOutputsResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_PDM_1SetPowerOutputsResponseData_t* pResponseData);

static void EPSII_PDM_1_GetPowerOutputsResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_PDM_1GetPowerOutputsResponseData_t* pResponseData);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)
// @END_USER@ USER_LOCAL_VARS_DECL

static EPSII_PDM_1_ClientApi_t EPSII_PDM_1ClientApiCtx =
{
  .EPSII_PDM_1_GetPowerDistributionInfoResponseHandler = (pfEPSII_PDM_1_GetPowerDistributionInfoResponseHandler_t) EPSII_PDM_1_GetPowerDistributionInfoResponseHandlerImpl,
  .EPSII_PDM_1_GetDeviceHealthInfoResponseHandler = (pfEPSII_PDM_1_GetDeviceHealthInfoResponseHandler_t) EPSII_PDM_1_GetDeviceHealthInfoResponseHandlerImpl,
  .EPSII_PDM_1_SetPC104GPIOResponseHandler = (pfEPSII_PDM_1_SetPC104GPIOResponseHandler_t) EPSII_PDM_1_SetPC104GPIOResponseHandlerImpl,
  .EPSII_PDM_1_GetPC104GPIOResponseHandler = (pfEPSII_PDM_1_GetPC104GPIOResponseHandler_t) EPSII_PDM_1_GetPC104GPIOResponseHandlerImpl,
  .EPSII_PDM_1_GetRAWSensorsResponseHandler = (pfEPSII_PDM_1_GetRAWSensorsResponseHandler_t) EPSII_PDM_1_GetRAWSensorsResponseHandlerImpl,
  .EPSII_PDM_1_SetPowerOutputsResponseHandler = (pfEPSII_PDM_1_SetPowerOutputsResponseHandler_t) EPSII_PDM_1_SetPowerOutputsResponseHandlerImpl,
  .EPSII_PDM_1_GetPowerOutputsResponseHandler = (pfEPSII_PDM_1_GetPowerOutputsResponseHandler_t) EPSII_PDM_1_GetPowerOutputsResponseHandlerImpl,
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Response handler for method EPSII_PDM_1::GetPowerDistributionInfo (ID = 0x00000002)
static void EPSII_PDM_1_GetPowerDistributionInfoResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_PDM_1GetPowerDistributionInfoResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@EPSII_PDM_1::GetPowerDistributionInfo@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@EPSII_PDM_1::GetPowerDistributionInfo@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@EPSII_PDM_1::GetPowerDistributionInfo@
        
        eps_ii_pow_dist_info_notif(pResponseData);
        
        // @USER_CODE_SECTION_END@EPSII_PDM_1::GetPowerDistributionInfo@
    }
}
// @END@ Response handler for method EPSII_PDM_1::GetPowerDistributionInfo (ID = 0x00000002)

// @START@ Response handler for method EPSII_PDM_1::GetDeviceHealthInfo (ID = 0x00000003)
static void EPSII_PDM_1_GetDeviceHealthInfoResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_PDM_1GetDeviceHealthInfoResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@EPSII_PDM_1::GetDeviceHealthInfo@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@EPSII_PDM_1::GetDeviceHealthInfo@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@EPSII_PDM_1::GetDeviceHealthInfo@
        
        eps_ii_pdm_dev_health_notif(pResponseData);
        
        // @USER_CODE_SECTION_END@EPSII_PDM_1::GetDeviceHealthInfo@
    }
}
// @END@ Response handler for method EPSII_PDM_1::GetDeviceHealthInfo (ID = 0x00000003)

// @START@ Response handler for method EPSII_PDM_1::SetPC104GPIO (ID = 0x00000004)
static void EPSII_PDM_1_SetPC104GPIOResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_PDM_1SetPC104GPIOResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@EPSII_PDM_1::SetPC104GPIO@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@EPSII_PDM_1::SetPC104GPIO@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@EPSII_PDM_1::SetPC104GPIO@
        
        // Notify eps_ctrl
        bool b_success = (EPSII_PDM_1_SGGPIO_SETERROR_SGGPIOE_SUCCESS == pResponseData->eErr);
        eps_ctrl_cfg_set_ch_notif_eps_ii(pRespCtx->seqId, b_success);
        
        // @USER_CODE_SECTION_END@EPSII_PDM_1::SetPC104GPIO@
    }
}
// @END@ Response handler for method EPSII_PDM_1::SetPC104GPIO (ID = 0x00000004)

// @START@ Response handler for method EPSII_PDM_1::GetPC104GPIO (ID = 0x00000005)
static void EPSII_PDM_1_GetPC104GPIOResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_PDM_1GetPC104GPIOResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@EPSII_PDM_1::GetPC104GPIO@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@EPSII_PDM_1::GetPC104GPIO@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@EPSII_PDM_1::GetPC104GPIO@
        
        eps_ctrl_cfg_get_ch_notif_eps_ii_gpio(pRespCtx->seqId, pResponseData->u8CurrentValues);
        
        // @USER_CODE_SECTION_END@EPSII_PDM_1::GetPC104GPIO@
    }
}
// @END@ Response handler for method EPSII_PDM_1::GetPC104GPIO (ID = 0x00000005)

// @START@ Response handler for method EPSII_PDM_1::GetRAWSensors (ID = 0x00000006)
static void EPSII_PDM_1_GetRAWSensorsResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_PDM_1GetRAWSensorsResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@EPSII_PDM_1::GetRAWSensors@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@EPSII_PDM_1::GetRAWSensors@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@EPSII_PDM_1::GetRAWSensors@
        
        eps_ii_raw_sensors_notif(pRespCtx, pResponseData);
        
        // @USER_CODE_SECTION_END@EPSII_PDM_1::GetRAWSensors@
    }
}
// @END@ Response handler for method EPSII_PDM_1::GetRAWSensors (ID = 0x00000006)

// @START@ Response handler for method EPSII_PDM_1::SetPowerOutputs (ID = 0x00000007)
static void EPSII_PDM_1_SetPowerOutputsResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_PDM_1SetPowerOutputsResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@EPSII_PDM_1::SetPowerOutputs@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@EPSII_PDM_1::SetPowerOutputs@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@EPSII_PDM_1::SetPowerOutputs@

        // Notify eps_ctrl
        bool b_success = (EPSII_PDM_1_SGPO_SETERROR_SGPOSE_SUCCESS == pResponseData->eErr);
        eps_ctrl_cfg_set_ch_notif_eps_ii(pRespCtx->seqId, b_success);

        // @USER_CODE_SECTION_END@EPSII_PDM_1::SetPowerOutputs@
    }
}
// @END@ Response handler for method EPSII_PDM_1::SetPowerOutputs (ID = 0x00000007)

// @START@ Response handler for method EPSII_PDM_1::GetPowerOutputs (ID = 0x00000008)
static void EPSII_PDM_1_GetPowerOutputsResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPSII_PDM_1GetPowerOutputsResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@EPSII_PDM_1::GetPowerOutputs@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@EPSII_PDM_1::GetPowerOutputs@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@EPSII_PDM_1::GetPowerOutputs@

        eps_ctrl_cfg_get_ch_notif_eps_ii_sgpo(pRespCtx->seqId, pResponseData->u32ValuesMask);

        // @USER_CODE_SECTION_END@EPSII_PDM_1::GetPowerOutputs@
    }
}
// @END@ Response handler for method EPSII_PDM_1::GetPowerOutputs (ID = 0x00000008)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void EPSII_PDM_1ClientAppInit(void)
{
    EPSII_PDM_1_registerClientApi(&EPSII_PDM_1ClientApiCtx);
}
