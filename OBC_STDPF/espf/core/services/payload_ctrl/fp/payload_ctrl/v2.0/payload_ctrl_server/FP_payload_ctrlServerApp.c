/*!
********************************************************************************************
* @file FP_payload_ctrlServerApp.c
* @brief ServerApp implementation template generator
********************************************************************************************
* @version           interface payload_ctrl v2.0
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

#include "FP_payload_ctrlProtocolServer.h"

// @START_USER@ USER_INCLUDES
#include "payload_ctrl.h"
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL
static void payload_ctrl_start_payloadRequestHandlerImpl(ReqContext_t* pReqCtx,
            const payload_ctrlstart_payloadRequestData_t* pRequestData);

static void payload_ctrl_stop_payloadRequestHandlerImpl(ReqContext_t* pReqCtx,
            const payload_ctrlstop_payloadRequestData_t* pRequestData);

static void payload_ctrl_get_payload_infoRequestHandlerImpl(ReqContext_t* pReqCtx,
            const payload_ctrlget_payload_infoRequestData_t* pRequestData);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_VARS_DECL

static payload_ctrl_ServerApi_t payload_ctrlServerApiCtx =
{
  .payload_ctrl_start_payloadRequestHandler = payload_ctrl_start_payloadRequestHandlerImpl,
  .payload_ctrl_stop_payloadRequestHandler = payload_ctrl_stop_payloadRequestHandlerImpl,
  .payload_ctrl_get_payload_infoRequestHandler = payload_ctrl_get_payload_infoRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method payload_ctrl::start_payload (ID = 0x00000000)
static void payload_ctrl_start_payloadRequestHandlerImpl(ReqContext_t *pReqCtx,
            const payload_ctrlstart_payloadRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    PAYLOAD_CTRL_PayloadOpResult_t eOp_result;

    // @USER_VAR_SECTION_START@payload_ctrl::start_payload@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@payload_ctrl::start_payload@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@payload_ctrl::start_payload@

        static_assert(sizeof(payload_ctrl_start_cfg_t) == sizeof(pRequestData->sStart_cfg));
        
        if (pRequestData->u8Payload_id < PAYLOAD_COUNT)
        {

            eOp_result = (PAYLOAD_CTRL_PayloadOpResult_t)
                    payload_ctrl_start((payload_ctrl_payload_t) pRequestData->u8Payload_id,
                                       (const payload_ctrl_start_cfg_t * const)&pRequestData->sStart_cfg);
        }
        else
        {
            eOp_result = PAYLOAD_CTRL_PAYLOADOPRESULT_INVALID_PL_ID;
        }
		
        // @USER_CODE_SECTION_END@payload_ctrl::start_payload@

        respResult = payload_ctrl_start_payloadResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_PAYLOAD_CTRL, PAYLOAD_CTRL_START_PAYLOAD_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method payload_ctrl::start_payload (ID = 0x00000000)

// @START@ Request handler for method payload_ctrl::stop_payload (ID = 0x00000001)
static void payload_ctrl_stop_payloadRequestHandlerImpl(ReqContext_t *pReqCtx,
            const payload_ctrlstop_payloadRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    PAYLOAD_CTRL_PayloadOpResult_t eOp_result;

    // @USER_VAR_SECTION_START@payload_ctrl::stop_payload@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@payload_ctrl::stop_payload@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@payload_ctrl::stop_payload@

        if (pRequestData->u8Payload_id < PAYLOAD_COUNT)
        {
            eOp_result = (PAYLOAD_CTRL_PayloadOpResult_t)
                    payload_ctrl_stop(pRequestData->u8Payload_id, (pl_op_stop_mode_t) pRequestData->eReq_stop_mode);
        }
        else
        {
            eOp_result = PAYLOAD_CTRL_PAYLOADOPRESULT_INVALID_PL_ID;
        }
        
        // @USER_CODE_SECTION_END@payload_ctrl::stop_payload@

        respResult = payload_ctrl_stop_payloadResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_PAYLOAD_CTRL, PAYLOAD_CTRL_STOP_PAYLOAD_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method payload_ctrl::stop_payload (ID = 0x00000001)

// @START@ Request handler for method payload_ctrl::get_payload_info (ID = 0x00000002)
static void payload_ctrl_get_payload_infoRequestHandlerImpl(ReqContext_t *pReqCtx,
            const payload_ctrlget_payload_infoRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    PAYLOAD_CTRL_PayloadInfo_t sInfo;

    // @USER_VAR_SECTION_START@payload_ctrl::get_payload_info@
    uint32_t last_error_code = 0U;
    // @USER_VAR_SECTION_END@payload_ctrl::get_payload_info@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@payload_ctrl::get_payload_info@

        static_assert(PAYLOAD_CTRL_PAYLOADSTATE_NOT_INIT == PL_STATE_NOT_INIT);
        static_assert(PAYLOAD_CTRL_PAYLOADSTATE_STOPPED == PL_STATE_STOPPED);
        static_assert(PAYLOAD_CTRL_PAYLOADSTATE_STARTED == PL_STATE_STARTED);
        static_assert(PAYLOAD_CTRL_PAYLOADSTATE_STARTING == PL_STATE_STARTING);
        static_assert(PAYLOAD_CTRL_PAYLOADSTATE_STOPPING == PL_STATE_STOPPING);
        static_assert(PAYLOAD_CTRL_PAYLOADSTATE_ERROR == PL_STATE_ERROR);
        static_assert(PAYLOAD_CTRL_PAYLOADSTATE_MAX_CNT == PL_STATE_MAX);

        const payload_ctrl_op_res_t op_res = payload_ctrl_get_state(pRequestData->u8Payload_id,
                                                                    (pl_state_t *) &sInfo.ePl_state,
                                                                    &last_error_code);

        if (PL_CTRL_OP_RES_OK == op_res)
        {
            // this assignment is here to avoid passing a pointer to a member of a packed structure above
            sInfo.u32Last_error_code = last_error_code;
        }
        else
        {
            sInfo.ePl_state = PAYLOAD_CTRL_PAYLOADSTATE_ERROR;
            sInfo.u32Last_error_code = 0xFFFFFFFFU;
        }

        // @USER_CODE_SECTION_END@payload_ctrl::get_payload_info@

        respResult = payload_ctrl_get_payload_infoResp(
                        &respCtx,
                        &sInfo
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_PAYLOAD_CTRL, PAYLOAD_CTRL_GET_PAYLOAD_INFO_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method payload_ctrl::get_payload_info (ID = 0x00000002)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void payload_ctrlServerAppInit(void)
{
    payload_ctrl_registerServerApi(&payload_ctrlServerApiCtx);
}
