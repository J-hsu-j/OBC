/*!
********************************************************************************************
* @file FP_comm_loss_wdServerApp.c
* @brief ServerApp implementation template generator
********************************************************************************************
* @version           interface comm_loss_wd v0.3
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

#include "FP_comm_loss_wdProtocolServer.h"

// @START_USER@ USER_INCLUDES
// Place user includes here to preserve them during merge!!!

#include "comm_loss_wd.h"

// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL
static void comm_loss_wd_set_wd_timeoutRequestHandlerImpl(ReqContext_t* pReqCtx,
            const comm_loss_wdset_wd_timeoutRequestData_t* pRequestData);

static void comm_loss_wd_set_wd_enableRequestHandlerImpl(ReqContext_t* pReqCtx,
            const comm_loss_wdset_wd_enableRequestData_t* pRequestData);

static void comm_loss_wd_get_wd_timeoutRequestHandlerImpl(ReqContext_t* pReqCtx);

static void comm_loss_wd_get_wd_statRequestHandlerImpl(ReqContext_t* pReqCtx);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_VARS_DECL

static comm_loss_wd_ServerApi_t comm_loss_wdServerApiCtx =
{
  .comm_loss_wd_set_wd_timeoutRequestHandler = comm_loss_wd_set_wd_timeoutRequestHandlerImpl,
  .comm_loss_wd_set_wd_enableRequestHandler = comm_loss_wd_set_wd_enableRequestHandlerImpl,
  .comm_loss_wd_get_wd_timeoutRequestHandler = comm_loss_wd_get_wd_timeoutRequestHandlerImpl,
  .comm_loss_wd_get_wd_statRequestHandler = comm_loss_wd_get_wd_statRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method comm_loss_wd::set_wd_timeout (ID = 0x00000001)
static void comm_loss_wd_set_wd_timeoutRequestHandlerImpl(ReqContext_t *pReqCtx,
            const comm_loss_wdset_wd_timeoutRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    COMM_LOSS_WD_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@comm_loss_wd::set_wd_timeout@
    // Put your local variables in this section to preserve during merge!

    bool op_result = false;

    // @USER_VAR_SECTION_END@comm_loss_wd::set_wd_timeout@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@comm_loss_wd::set_wd_timeout@
        
        // TODO: Put your implementation to handle the
        // received server response here!

        op_result = comm_loss_wd_set_timeout((uint32_t)pRequestData->u32Wd_timeout);
       
        if (true == op_result)
           eOp_result = COMM_LOSS_WD_STANDARDRESULT_SUCCESS;
        else
           eOp_result = COMM_LOSS_WD_STANDARDRESULT_ERROR;

        // @USER_CODE_SECTION_END@comm_loss_wd::set_wd_timeout@

        respResult = comm_loss_wd_set_wd_timeoutResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_COMM_LOSS_WD, COMM_LOSS_WD_SET_WD_TIMEOUT_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method comm_loss_wd::set_wd_timeout (ID = 0x00000001)

// @START@ Request handler for method comm_loss_wd::set_wd_enable (ID = 0x00000002)
static void comm_loss_wd_set_wd_enableRequestHandlerImpl(ReqContext_t *pReqCtx,
            const comm_loss_wdset_wd_enableRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    COMM_LOSS_WD_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@comm_loss_wd::set_wd_enable@
    // Put your local variables in this section to preserve during merge!

    bool op_result = false;

    // @USER_VAR_SECTION_END@comm_loss_wd::set_wd_enable@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@comm_loss_wd::set_wd_enable@
        
        // TODO: Put your implementation to handle the
        // received server response here!

        op_result = comm_loss_wd_set_enable((bool)pRequestData->bWd_enable);

        if (true == op_result)
           eOp_result = COMM_LOSS_WD_STANDARDRESULT_SUCCESS;
        else
           eOp_result = COMM_LOSS_WD_STANDARDRESULT_ERROR;

        // @USER_CODE_SECTION_END@comm_loss_wd::set_wd_enable@

        respResult = comm_loss_wd_set_wd_enableResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_COMM_LOSS_WD, COMM_LOSS_WD_SET_WD_ENABLE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method comm_loss_wd::set_wd_enable (ID = 0x00000002)

// @START@ Request handler for method comm_loss_wd::get_wd_timeout (ID = 0x00000003)
static void comm_loss_wd_get_wd_timeoutRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    uint32_t u32Wd_timeout;

    // @USER_VAR_SECTION_START@comm_loss_wd::get_wd_timeout@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@comm_loss_wd::get_wd_timeout@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@comm_loss_wd::get_wd_timeout@
        
        // TODO: Put your implementation to handle the
        // received server response here!

        u32Wd_timeout = comm_loss_wd_get_timeout();

        
        // @USER_CODE_SECTION_END@comm_loss_wd::get_wd_timeout@

        respResult = comm_loss_wd_get_wd_timeoutResp(
                        &respCtx,
                        u32Wd_timeout
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_COMM_LOSS_WD, COMM_LOSS_WD_GET_WD_TIMEOUT_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method comm_loss_wd::get_wd_timeout (ID = 0x00000003)

// @START@ Request handler for method comm_loss_wd::get_wd_stat (ID = 0x00000004)
static void comm_loss_wd_get_wd_statRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    bool bWd_stat;

    // @USER_VAR_SECTION_START@comm_loss_wd::get_wd_stat@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@comm_loss_wd::get_wd_stat@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@comm_loss_wd::get_wd_stat@
        
        // TODO: Put your implementation to handle the
        // received server response here!

        bWd_stat = comm_loss_wd_get_enable();
        
        // @USER_CODE_SECTION_END@comm_loss_wd::get_wd_stat@

        respResult = comm_loss_wd_get_wd_statResp(
                        &respCtx,
                        bWd_stat
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_COMM_LOSS_WD, COMM_LOSS_WD_GET_WD_STAT_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method comm_loss_wd::get_wd_stat (ID = 0x00000004)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void comm_loss_wdServerAppInit(void)
{
    comm_loss_wd_registerServerApi(&comm_loss_wdServerApiCtx);
}
