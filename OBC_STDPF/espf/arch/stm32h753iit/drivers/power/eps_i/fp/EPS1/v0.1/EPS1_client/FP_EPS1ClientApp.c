/*!
********************************************************************************************
* @file FP_EPS1ClientApp.c
* @brief ClientApp implementation template generator
********************************************************************************************
* @version           interface EPS1 v0.1
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

#include "FP_EPS1ProtocolClient.h"

// @START_USER@ USER_INCLUDES
#include "eps_ctrl_cfg.h"
#include "eps_i.h"
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL

static void EPS1_getBatteryInfoResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPS1getBatteryInfoResponseData_t* pResponseData);

static void EPS1_getConfigurationInfoResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPS1getConfigurationInfoResponseData_t* pResponseData);

static void EPS1_queryControlsResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPS1queryControlsResponseData_t* pResponseData);

static void EPS1_ToggleOutPutResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPS1ToggleOutPutResponseData_t* pResponseData);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)
// @END_USER@ USER_LOCAL_VARS_DECL

static EPS1_ClientApi_t EPS1ClientApiCtx =
{
  .EPS1_getBatteryInfoResponseHandler = (pfEPS1_getBatteryInfoResponseHandler_t) EPS1_getBatteryInfoResponseHandlerImpl,
  .EPS1_getConfigurationInfoResponseHandler = (pfEPS1_getConfigurationInfoResponseHandler_t) EPS1_getConfigurationInfoResponseHandlerImpl,
  .EPS1_queryControlsResponseHandler = (pfEPS1_queryControlsResponseHandler_t) EPS1_queryControlsResponseHandlerImpl,
  .EPS1_ToggleOutPutResponseHandler = (pfEPS1_ToggleOutPutResponseHandler_t) EPS1_ToggleOutPutResponseHandlerImpl,
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Response handler for method EPS1::getBatteryInfo (ID = 0x00000001)
static void EPS1_getBatteryInfoResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPS1getBatteryInfoResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@EPS1::getBatteryInfo@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@EPS1::getBatteryInfo@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@EPS1::getBatteryInfo@

    	// Send the battery info the the EPS I module
    	eps_i_info_to_datacache(pResponseData);

        // @USER_CODE_SECTION_END@EPS1::getBatteryInfo@
    }
}
// @END@ Response handler for method EPS1::getBatteryInfo (ID = 0x00000001)

// @START@ Response handler for method EPS1::getConfigurationInfo (ID = 0x00000006)
static void EPS1_getConfigurationInfoResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPS1getConfigurationInfoResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@EPS1::getConfigurationInfo@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@EPS1::getConfigurationInfo@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@EPS1::getConfigurationInfo@
		eps_ctrl_cfg_get_ch_notif_eps_i(pRespCtx->seqId, pResponseData->sConfig);

        // @USER_CODE_SECTION_END@EPS1::getConfigurationInfo@
    }
}
// @END@ Response handler for method EPS1::getConfigurationInfo (ID = 0x00000006)

// @START@ Response handler for method EPS1::queryControls (ID = 0x00000007)
static void EPS1_queryControlsResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPS1queryControlsResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@EPS1::queryControls@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@EPS1::queryControls@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@EPS1::queryControls@

        // No need of passing the response data, we assume the request is being processed in the EPS I
		eps_ctrl_cfg_set_ch_notif_eps_i(pRespCtx->seqId);

        // @USER_CODE_SECTION_END@EPS1::queryControls@
    }
}
// @END@ Response handler for method EPS1::queryControls (ID = 0x00000007)

// @START@ Response handler for method EPS1::ToggleOutPut (ID = 0x00000014)
static void EPS1_ToggleOutPutResponseHandlerImpl(RespContext_t* pRespCtx,
            const EPS1ToggleOutPutResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@EPS1::ToggleOutPut@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@EPS1::ToggleOutPut@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@EPS1::ToggleOutPut@

        // TODO: Put your implementation to handle the
        // received server response here!

        // @USER_CODE_SECTION_END@EPS1::ToggleOutPut@
    }
}
// @END@ Response handler for method EPS1::ToggleOutPut (ID = 0x00000014)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void EPS1ClientAppInit(void)
{
    EPS1_registerClientApi(&EPS1ClientApiCtx);
}
