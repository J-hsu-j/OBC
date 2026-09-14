/*!
********************************************************************************************
* @file FP_onboard_schedServerApp.c
* @brief ServerApp implementation template generator
********************************************************************************************
* @version           interface onboard_sched v0.1
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

#include "FP_onboard_schedProtocolServer.h"

// @START_USER@ USER_INCLUDES
// Place user includes here to preserve them during merge!!!
#include "onboard_sched.h"
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL
static void onboard_sched_set_scheduler_stateRequestHandlerImpl(ReqContext_t* pReqCtx,
            const onboard_schedset_scheduler_stateRequestData_t* pRequestData);

static void onboard_sched_get_scheduler_stateRequestHandlerImpl(ReqContext_t* pReqCtx);

static void onboard_sched_set_active_scheduleRequestHandlerImpl(ReqContext_t* pReqCtx,
            const onboard_schedset_active_scheduleRequestData_t* pRequestData);

static void onboard_sched_get_active_scheduleRequestHandlerImpl(ReqContext_t* pReqCtx);

static void onboard_sched_get_next_slotRequestHandlerImpl(ReqContext_t* pReqCtx);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL

INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

// @END_USER@ USER_LOCAL_VARS_DECL

static onboard_sched_ServerApi_t onboard_schedServerApiCtx =
{
  .onboard_sched_set_scheduler_stateRequestHandler = onboard_sched_set_scheduler_stateRequestHandlerImpl,
  .onboard_sched_get_scheduler_stateRequestHandler = onboard_sched_get_scheduler_stateRequestHandlerImpl,
  .onboard_sched_set_active_scheduleRequestHandler = onboard_sched_set_active_scheduleRequestHandlerImpl,
  .onboard_sched_get_active_scheduleRequestHandler = onboard_sched_get_active_scheduleRequestHandlerImpl,
  .onboard_sched_get_next_slotRequestHandler = onboard_sched_get_next_slotRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method onboard_sched::set_scheduler_state (ID = 0x00000001)
static void onboard_sched_set_scheduler_stateRequestHandlerImpl(ReqContext_t *pReqCtx,
            const onboard_schedset_scheduler_stateRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    ONBOARD_SCHED_SchedState_t eNew_state;

    // @USER_VAR_SECTION_START@onboard_sched::set_scheduler_state@

    // @USER_VAR_SECTION_END@onboard_sched::set_scheduler_state@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@onboard_sched::set_scheduler_state@

        onboard_sched_set_state(pRequestData->eSch_state);
        eNew_state = onboard_sched_get_state();

        // @USER_CODE_SECTION_END@onboard_sched::set_scheduler_state@

        respResult = onboard_sched_set_scheduler_stateResp(
                        &respCtx,
                        eNew_state
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_ONBOARD_SCHED, ONBOARD_SCHED_SET_SCHEDULER_STATE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method onboard_sched::set_scheduler_state (ID = 0x00000001)

// @START@ Request handler for method onboard_sched::get_scheduler_state (ID = 0x00000002)
static void onboard_sched_get_scheduler_stateRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    ONBOARD_SCHED_SchedState_t eSch_state;

    // @USER_VAR_SECTION_START@onboard_sched::get_scheduler_state@

    // @USER_VAR_SECTION_END@onboard_sched::get_scheduler_state@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@onboard_sched::get_scheduler_state@

        eSch_state = onboard_sched_get_state();
        
        // @USER_CODE_SECTION_END@onboard_sched::get_scheduler_state@

        respResult = onboard_sched_get_scheduler_stateResp(
                        &respCtx,
                        eSch_state
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_ONBOARD_SCHED, ONBOARD_SCHED_GET_SCHEDULER_STATE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method onboard_sched::get_scheduler_state (ID = 0x00000002)

// @START@ Request handler for method onboard_sched::set_active_schedule (ID = 0x00000003)
static void onboard_sched_set_active_scheduleRequestHandlerImpl(ReqContext_t *pReqCtx,
            const onboard_schedset_active_scheduleRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    ONBOARD_SCHED_SchedLoadResult_t eResult;

    // @USER_VAR_SECTION_START@onboard_sched::set_active_schedule@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@onboard_sched::set_active_schedule@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@onboard_sched::set_active_schedule@
        
        eResult = onboard_sched_set_active_schedule(pRequestData->strFile_name);
        
        // @USER_CODE_SECTION_END@onboard_sched::set_active_schedule@

        respResult = onboard_sched_set_active_scheduleResp(
                        &respCtx,
                        eResult
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_ONBOARD_SCHED, ONBOARD_SCHED_SET_ACTIVE_SCHEDULE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method onboard_sched::set_active_schedule (ID = 0x00000003)

// @START@ Request handler for method onboard_sched::get_active_schedule (ID = 0x00000004)
static void onboard_sched_get_active_scheduleRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    char strFile_name[47];
    uint8_t u8File_nameSize;
    ONBOARD_SCHED_SchedLoadResult_t eResult;

    // @USER_VAR_SECTION_START@onboard_sched::get_active_schedule@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@onboard_sched::get_active_schedule@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@onboard_sched::get_active_schedule@
        
        eResult = onboard_sched_get_active_schedule(strFile_name, sizeof(strFile_name), &u8File_nameSize);
        
        // @USER_CODE_SECTION_END@onboard_sched::get_active_schedule@

        respResult = onboard_sched_get_active_scheduleResp(
                        &respCtx,
                        strFile_name,
                        u8File_nameSize,
                        eResult
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_ONBOARD_SCHED, ONBOARD_SCHED_GET_ACTIVE_SCHEDULE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method onboard_sched::get_active_schedule (ID = 0x00000004)

// @START@ Request handler for method onboard_sched::get_next_slot (ID = 0x00000005)
static void onboard_sched_get_next_slotRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    uint32_t u32Offset;

    // @USER_VAR_SECTION_START@onboard_sched::get_next_slot@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@onboard_sched::get_next_slot@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@onboard_sched::get_next_slot@
        
        u32Offset = onboard_sched_get_next_slot();
        
        // @USER_CODE_SECTION_END@onboard_sched::get_next_slot@

        respResult = onboard_sched_get_next_slotResp(
                        &respCtx,
                        u32Offset
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_ONBOARD_SCHED, ONBOARD_SCHED_GET_NEXT_SLOT_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method onboard_sched::get_next_slot (ID = 0x00000005)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void onboard_schedServerAppInit(void)
{
    onboard_sched_registerServerApi(&onboard_schedServerApiCtx);
}
