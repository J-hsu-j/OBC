/*!
********************************************************************************************
* @file FP_adis16265_gyroServerApp.c
* @brief ServerApp implementation template generator
********************************************************************************************
* @version           interface adis16265_gyro v1.0
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

#include "FP_adis16265_gyroProtocolServer.h"

// @START_USER@ USER_INCLUDES
#include "adis16265_driver.h"
#include "panels.h"
#include <assert.h>
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL
static void adis16265_gyro_set_gyroscope_configRequestHandlerImpl(ReqContext_t* pReqCtx,
            const adis16265_gyroset_gyroscope_configRequestData_t* pRequestData);

static void adis16265_gyro_get_gyroscope_configRequestHandlerImpl(ReqContext_t* pReqCtx);

static void adis16265_gyro_save_gyroscope_configRequestHandlerImpl(ReqContext_t* pReqCtx);

static void adis16265_gyro_load_gyroscope_configRequestHandlerImpl(ReqContext_t* pReqCtx);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)
// @END_USER@ USER_LOCAL_VARS_DECL

static adis16265_gyro_ServerApi_t adis16265_gyroServerApiCtx =
{
  .adis16265_gyro_set_gyroscope_configRequestHandler = adis16265_gyro_set_gyroscope_configRequestHandlerImpl,
  .adis16265_gyro_get_gyroscope_configRequestHandler = adis16265_gyro_get_gyroscope_configRequestHandlerImpl,
  .adis16265_gyro_save_gyroscope_configRequestHandler = adis16265_gyro_save_gyroscope_configRequestHandlerImpl,
  .adis16265_gyro_load_gyroscope_configRequestHandler = adis16265_gyro_load_gyroscope_configRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method adis16265_gyro::set_gyroscope_config (ID = 0x00000001)
static void adis16265_gyro_set_gyroscope_configRequestHandlerImpl(ReqContext_t *pReqCtx,
            const adis16265_gyroset_gyroscope_configRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    ADIS16265_GYRO_Result_t eOp_result;

    // @USER_VAR_SECTION_START@adis16265_gyro::set_gyroscope_config@
    /* MISRA C++:2008, 8-0-1 */
    Panel_Number_t first_panel;
    Panel_Number_t second_panel;
    Panel_Number_t third_panel;
    // @USER_VAR_SECTION_END@adis16265_gyro::set_gyroscope_config@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@adis16265_gyro::set_gyroscope_config@

        first_panel  = pRequestData->eGyroscope_1;
        second_panel = pRequestData->eGyroscope_2;
        third_panel  = pRequestData->eGyroscope_3;

        adis16265_set_panel(PAN_X_P, first_panel);
        adis16265_set_panel(PAN_Y_P, second_panel);
        adis16265_set_panel(PAN_Z_P, third_panel);

        eOp_result = ADIS16265_GYRO_RESULT_OK;

        // @USER_CODE_SECTION_END@adis16265_gyro::set_gyroscope_config@

        respResult = adis16265_gyro_set_gyroscope_configResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_ADIS16265_GYRO, ADIS16265_GYRO_SET_GYROSCOPE_CONFIG_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method adis16265_gyro::set_gyroscope_config (ID = 0x00000001)

// @START@ Request handler for method adis16265_gyro::get_gyroscope_config (ID = 0x00000002)
static void adis16265_gyro_get_gyroscope_configRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    ADIS16265_GYRO_Panel_t eGyroscope_1;
    ADIS16265_GYRO_Panel_t eGyroscope_2;
    ADIS16265_GYRO_Panel_t eGyroscope_3;
    ADIS16265_GYRO_Result_t eOp_result;

    // @USER_VAR_SECTION_START@adis16265_gyro::get_gyroscope_config@
    /* MISRA C++:2008, 8-0-1 */
    Panel_Number_t gyroscope_1_panel;
    Panel_Number_t gyroscope_2_panel;
    Panel_Number_t gyroscope_3_panel;
    // @USER_VAR_SECTION_END@adis16265_gyro::get_gyroscope_config@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@adis16265_gyro::get_gyroscope_config@

        static_assert(PANEL_1 == ADIS16265_GYRO_PANEL_ONE, "Gyroscope panel enum values mismatch");
        static_assert(PANEL_2 == ADIS16265_GYRO_PANEL_TWO, "Gyroscope panel enum values mismatch");
        static_assert(PANEL_3 == ADIS16265_GYRO_PANEL_THREE, "Gyroscope panel enum values mismatch");
        static_assert(PANEL_4 == ADIS16265_GYRO_PANEL_FOUR, "Gyroscope panel enum values mismatch");
        static_assert(PANEL_5 == ADIS16265_GYRO_PANEL_FIVE, "Gyroscope panel enum values mismatch");
        static_assert(PANEL_6 == ADIS16265_GYRO_PANEL_SIX, "Gyroscope panel enum values mismatch");
        static_assert(MAX_PANEL == ADIS16265_GYRO_PANEL_MAX_CNT, "Gyroscope panel enum values mismatch");

        gyroscope_1_panel = adis16265_get_panel(PAN_X_P);
        gyroscope_2_panel = adis16265_get_panel(PAN_Y_P);
        gyroscope_3_panel = adis16265_get_panel(PAN_Z_P);

        eGyroscope_1 = (ADIS16265_GYRO_Panel_t)gyroscope_1_panel;
        eGyroscope_2 = (ADIS16265_GYRO_Panel_t)gyroscope_2_panel;
        eGyroscope_3 = (ADIS16265_GYRO_Panel_t)gyroscope_3_panel;

        eOp_result = ADIS16265_GYRO_RESULT_OK;

        // @USER_CODE_SECTION_END@adis16265_gyro::get_gyroscope_config@

        respResult = adis16265_gyro_get_gyroscope_configResp(
                        &respCtx,
                        eGyroscope_1,
                        eGyroscope_2,
                        eGyroscope_3,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_ADIS16265_GYRO, ADIS16265_GYRO_GET_GYROSCOPE_CONFIG_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method adis16265_gyro::get_gyroscope_config (ID = 0x00000002)

// @START@ Request handler for method adis16265_gyro::save_gyroscope_config (ID = 0x00000003)
static void adis16265_gyro_save_gyroscope_configRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    ADIS16265_GYRO_Result_t eOp_result;

    // @USER_VAR_SECTION_START@adis16265_gyro::save_gyroscope_config@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@adis16265_gyro::save_gyroscope_config@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@adis16265_gyro::save_gyroscope_config@

        adis16265_save_config_to_nvm();

        eOp_result = ADIS16265_GYRO_RESULT_OK;

        // @USER_CODE_SECTION_END@adis16265_gyro::save_gyroscope_config@

        respResult = adis16265_gyro_save_gyroscope_configResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_ADIS16265_GYRO, ADIS16265_GYRO_SAVE_GYROSCOPE_CONFIG_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method adis16265_gyro::save_gyroscope_config (ID = 0x00000003)

// @START@ Request handler for method adis16265_gyro::load_gyroscope_config (ID = 0x00000004)
static void adis16265_gyro_load_gyroscope_configRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    ADIS16265_GYRO_Result_t eOp_result;

    // @USER_VAR_SECTION_START@adis16265_gyro::load_gyroscope_config@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@adis16265_gyro::load_gyroscope_config@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@adis16265_gyro::load_gyroscope_config@

        adis16265_load_config_from_nvm();

        eOp_result = ADIS16265_GYRO_RESULT_OK;

        // @USER_CODE_SECTION_END@adis16265_gyro::load_gyroscope_config@

        respResult = adis16265_gyro_load_gyroscope_configResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_ADIS16265_GYRO, ADIS16265_GYRO_LOAD_GYROSCOPE_CONFIG_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method adis16265_gyro::load_gyroscope_config (ID = 0x00000004)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void adis16265_gyroServerAppInit(void)
{
    adis16265_gyro_registerServerApi(&adis16265_gyroServerApiCtx);
}
