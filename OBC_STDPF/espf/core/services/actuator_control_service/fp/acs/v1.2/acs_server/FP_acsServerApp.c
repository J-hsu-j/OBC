/*!
********************************************************************************************
* @file FP_acsServerApp.c
* @brief ServerApp implementation template generator
********************************************************************************************
* @version           interface acs v1.2
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

#include "FP_acsProtocolServer.h"

// @START_USER@ USER_INCLUDES
#include "acs.h"
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
static void acs_set_op_modeRequestHandlerImpl(ReqContext_t* pReqCtx,
            const acsset_op_modeRequestData_t* pRequestData);

static void acs_get_op_modeRequestHandlerImpl(ReqContext_t* pReqCtx);

static void acs_get_statusRequestHandlerImpl(ReqContext_t* pReqCtx);

static void acs_set_manual_mtq_controlRequestHandlerImpl(ReqContext_t* pReqCtx,
            const acsset_manual_mtq_controlRequestData_t* pRequestData);

static void acs_get_manual_mtq_controlRequestHandlerImpl(ReqContext_t* pReqCtx);

static void acs_get_last_mtq_controlRequestHandlerImpl(ReqContext_t* pReqCtx);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)
// @END_USER@ USER_LOCAL_VARS_DECL

static acs_ServerApi_t acsServerApiCtx =
{
  .acs_set_op_modeRequestHandler = acs_set_op_modeRequestHandlerImpl,
  .acs_get_op_modeRequestHandler = acs_get_op_modeRequestHandlerImpl,
  .acs_get_statusRequestHandler = acs_get_statusRequestHandlerImpl,
  .acs_set_manual_mtq_controlRequestHandler = acs_set_manual_mtq_controlRequestHandlerImpl,
  .acs_get_manual_mtq_controlRequestHandler = acs_get_manual_mtq_controlRequestHandlerImpl,
  .acs_get_last_mtq_controlRequestHandler = acs_get_last_mtq_controlRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method acs::set_op_mode (ID = 0x00000001)
static void acs_set_op_modeRequestHandlerImpl(ReqContext_t *pReqCtx,
            const acsset_op_modeRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    ACS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@acs::set_op_mode@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@acs::set_op_mode@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@acs::set_op_mode@

        acs_set_op_mode(pRequestData->eDesired_mode);

        if (acs_get_op_mode() == pRequestData->eDesired_mode)
        {
            eOp_result = ACS_RESULT_ES_OK;
        }
        else
        {
            eOp_result = ACS_RESULT_ES_FAIL;
        }

        // @USER_CODE_SECTION_END@acs::set_op_mode@

        respResult = acs_set_op_modeResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_ACS, ACS_SET_OP_MODE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method acs::set_op_mode (ID = 0x00000001)

// @START@ Request handler for method acs::get_op_mode (ID = 0x00000002)
static void acs_get_op_modeRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    ACS_State_t eActive_mode;
    ACS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@acs::get_op_mode@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@acs::get_op_mode@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@acs::get_op_mode@

        static_assert(ACS_STATE_RUN == ACS_STATE_ES_RUN, "ACS State values mismatch");
        static_assert(ACS_STATE_MANUAL == ACS_STATE_ES_MANUAL, "ACS State values mismatch");
        static_assert(ACS_STATE_STOPPED == ACS_STATE_ES_STOPPED, "ACS State values mismatch");
        static_assert((ACS_STATE_STOPPED + 1) == ACS_STATE_MAX_CNT, "ACS State values mismatch");

        eActive_mode = (ACS_State_t)acs_get_op_mode();
        eOp_result = ACS_RESULT_ES_OK;

        // @USER_CODE_SECTION_END@acs::get_op_mode@

        respResult = acs_get_op_modeResp(
                        &respCtx,
                        eActive_mode,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_ACS, ACS_GET_OP_MODE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method acs::get_op_mode (ID = 0x00000002)

// @START@ Request handler for method acs::get_status (ID = 0x00000003)
static void acs_get_statusRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    ACS_Status_t sCurrent_status;
    ACS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@acs::get_status@
    acs_status_t current_status;
    // @USER_VAR_SECTION_END@acs::get_status@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@acs::get_status@

        static_assert(ACS_ERROR_NONE == ACS_ERROR_ES_NONE, "ACS Error values mismatch");
        static_assert(ACS_ERROR_DATA_CACHE_GET == ACS_ERROR_ES_DATA_CACHE_GET, "ACS Error values mismatch");
        static_assert(ACS_ERROR_DIVISION_BY_ZERO == ACS_ERROR_ES_MATH_FAILED, "ACS Error values mismatch");
        static_assert((ACS_ERROR_DIVISION_BY_ZERO + 1) == ACS_ERROR_MAX_CNT, "ACS Error values mismatch");
        static_assert(ACS_WARN_NONE == ACS_WARNING_ES_NONE, "ACS Warning values mismatch");
        static_assert(ACS_WARN_SATURATION_UPPER == ACS_WARNING_ES_SATURATION_UPPER, "ACS Warning values mismatch");
        static_assert(ACS_WARN_SATURATION_LOWER == ACS_WARNING_ES_SATURATION_LOWER, "ACS Warning values mismatch");
        static_assert((ACS_WARN_SATURATION_LOWER + 1) == ACS_WARNING_MAX_CNT, "ACS Warning values mismatch");

        current_status = acs_get_status();

        sCurrent_status.eActive_state = (ACS_State_t)current_status.state;
        sCurrent_status.eLast_error   = (ACS_Error_t)current_status.last_error;
        sCurrent_status.eLast_warning = (ACS_Warning_t)current_status.last_warning;

        eOp_result = ACS_RESULT_ES_OK;

        // @USER_CODE_SECTION_END@acs::get_status@

        respResult = acs_get_statusResp(
                        &respCtx,
                        &sCurrent_status,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_ACS, ACS_GET_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method acs::get_status (ID = 0x00000003)

// @START@ Request handler for method acs::set_manual_mtq_control (ID = 0x00000004)
static void acs_set_manual_mtq_controlRequestHandlerImpl(ReqContext_t *pReqCtx,
            const acsset_manual_mtq_controlRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    ACS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@acs::set_manual_mtq_control@
    int8_t desired_mtq_1_value;
    int8_t desired_mtq_2_value;
    int8_t desired_mtq_3_value;
    // @USER_VAR_SECTION_END@acs::set_manual_mtq_control@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@acs::set_manual_mtq_control@

        desired_mtq_1_value = pRequestData->sDesired_manual_magnetorquer_control_values.i8Mtq_1_mtq_frame;
        desired_mtq_2_value = pRequestData->sDesired_manual_magnetorquer_control_values.i8Mtq_2_mtq_frame;
        desired_mtq_3_value = pRequestData->sDesired_manual_magnetorquer_control_values.i8Mtq_3_mtq_frame;

        acs_set_manual_mtq_control_mtq_frame(desired_mtq_1_value, desired_mtq_2_value, desired_mtq_3_value);

        eOp_result = ACS_RESULT_ES_OK;

        // @USER_CODE_SECTION_END@acs::set_manual_mtq_control@

        respResult = acs_set_manual_mtq_controlResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_ACS, ACS_SET_MANUAL_MTQ_CONTROL_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method acs::set_manual_mtq_control (ID = 0x00000004)

// @START@ Request handler for method acs::get_manual_mtq_control (ID = 0x00000005)
static void acs_get_manual_mtq_controlRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    ACS_ManualMtqData_t sManual_magnetorquer_control_values;
    ACS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@acs::get_manual_mtq_control@
    int8_t manual_magnetorquer_values_mtq_frame[MAGNETORQUER_QUANTITY];
    // @USER_VAR_SECTION_END@acs::get_manual_mtq_control@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@acs::get_manual_mtq_control@

        acs_get_manual_mtq_control_mtq_frame(manual_magnetorquer_values_mtq_frame);

        sManual_magnetorquer_control_values.i8Mtq_1_mtq_frame = manual_magnetorquer_values_mtq_frame[0];
        sManual_magnetorquer_control_values.i8Mtq_2_mtq_frame = manual_magnetorquer_values_mtq_frame[1];
        sManual_magnetorquer_control_values.i8Mtq_3_mtq_frame = manual_magnetorquer_values_mtq_frame[2];

        eOp_result = ACS_RESULT_ES_OK;

        // @USER_CODE_SECTION_END@acs::get_manual_mtq_control@

        respResult = acs_get_manual_mtq_controlResp(
                        &respCtx,
                        &sManual_magnetorquer_control_values,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_ACS, ACS_GET_MANUAL_MTQ_CONTROL_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method acs::get_manual_mtq_control (ID = 0x00000005)

// @START@ Request handler for method acs::get_last_mtq_control (ID = 0x00000006)
static void acs_get_last_mtq_controlRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    ACS_LastMtqData_t sLast_magnetorquer_control_values;
    ACS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@acs::get_last_mtq_control@
    int8_t last_magnetorquer_values_body_frame[MAGNETORQUER_QUANTITY];
    int8_t last_magnetorquer_values_mtq_frame[MAGNETORQUER_QUANTITY];
    // @USER_VAR_SECTION_END@acs::get_last_mtq_control@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@acs::get_last_mtq_control@

        acs_get_last_mtq_control_body_frame(last_magnetorquer_values_body_frame);
        acs_get_last_mtq_control_mtq_frame(last_magnetorquer_values_mtq_frame);

        sLast_magnetorquer_control_values.i8Mtq_x_body_frame = last_magnetorquer_values_body_frame[0];
        sLast_magnetorquer_control_values.i8Mtq_y_body_frame = last_magnetorquer_values_body_frame[1];
        sLast_magnetorquer_control_values.i8Mtq_z_body_frame = last_magnetorquer_values_body_frame[2];
        sLast_magnetorquer_control_values.i8Mtq_x_mtq_frame = last_magnetorquer_values_mtq_frame[0];
        sLast_magnetorquer_control_values.i8Mtq_y_mtq_frame = last_magnetorquer_values_mtq_frame[1];
        sLast_magnetorquer_control_values.i8Mtq_z_mtq_frame = last_magnetorquer_values_mtq_frame[2];

        eOp_result = ACS_RESULT_ES_OK;

        // @USER_CODE_SECTION_END@acs::get_last_mtq_control@

        respResult = acs_get_last_mtq_controlResp(
                        &respCtx,
                        &sLast_magnetorquer_control_values,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_ACS, ACS_GET_LAST_MTQ_CONTROL_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method acs::get_last_mtq_control (ID = 0x00000006)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void acsServerAppInit(void)
{
    acs_registerServerApi(&acsServerApiCtx);
}
