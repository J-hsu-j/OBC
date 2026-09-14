/*!
********************************************************************************************
* @file FP_csp_serviceServerApp.c
* @brief ServerApp implementation template generator
********************************************************************************************
* @version           interface csp_service v0.1
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

#include "FP_csp_serviceProtocolServer.h"

// @START_USER@ USER_INCLUDES
// Place user includes here to preserve them during merge!!!

#include "csp_service.h"
#include "csp_service_cfg.h"

// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL
static void csp_service_get_trace_debug_levelRequestHandlerImpl(ReqContext_t* pReqCtx);

static void csp_service_set_trace_debug_levelRequestHandlerImpl(ReqContext_t* pReqCtx,
            const csp_serviceset_trace_debug_levelRequestData_t* pRequestData);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_VARS_DECL

static csp_service_ServerApi_t csp_serviceServerApiCtx =
{
  .csp_service_get_trace_debug_levelRequestHandler = csp_service_get_trace_debug_levelRequestHandlerImpl,
  .csp_service_set_trace_debug_levelRequestHandler = csp_service_set_trace_debug_levelRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method csp_service::get_trace_debug_level (ID = 0x00000000)
static void csp_service_get_trace_debug_levelRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    CSP_SERVICE_debug_levels_t sTrace_debug_level;

    // @USER_VAR_SECTION_START@csp_service::get_trace_debug_level@
    // Put your local variables in this section to preserve during merge!

    // @USER_VAR_SECTION_END@csp_service::get_trace_debug_level@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@csp_service::get_trace_debug_level@
        
        // TODO: Put your implementation to handle the
        // received server response here!

        sTrace_debug_level = csp_service_get_trace_level();

        // @USER_CODE_SECTION_END@csp_service::get_trace_debug_level@

        respResult = csp_service_get_trace_debug_levelResp(
                        &respCtx,
                        &sTrace_debug_level
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_CSP_SERVICE, CSP_SERVICE_GET_TRACE_DEBUG_LEVEL_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method csp_service::get_trace_debug_level (ID = 0x00000000)

// @START@ Request handler for method csp_service::set_trace_debug_level (ID = 0x00000001)
static void csp_service_set_trace_debug_levelRequestHandlerImpl(ReqContext_t *pReqCtx,
            const csp_serviceset_trace_debug_levelRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    CSP_SERVICE_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@csp_service::set_trace_debug_level@
    // Put your local variables in this section to preserve during merge!

    bool op_result = false;

    // @USER_VAR_SECTION_END@csp_service::set_trace_debug_level@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@csp_service::set_trace_debug_level@
        
        // TODO: Put your implementation to handle the
        // received server response here!

        op_result = csp_service_set_trace_level(pRequestData->sTrace_debug_level);

        if (true == op_result)
          {
           eOp_result = CSP_SERVICE_STANDARDRESULT_SUCCESS;
          }
        else
          {
           eOp_result = CSP_SERVICE_STANDARDRESULT_ERROR;
          }

        // @USER_CODE_SECTION_END@csp_service::set_trace_debug_level@

        respResult = csp_service_set_trace_debug_levelResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_CSP_SERVICE, CSP_SERVICE_SET_TRACE_DEBUG_LEVEL_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method csp_service::set_trace_debug_level (ID = 0x00000001)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void csp_serviceServerAppInit(void)
{
    csp_service_registerServerApi(&csp_serviceServerApiCtx);
}
