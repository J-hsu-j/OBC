/*!
********************************************************************************************
* @file FP_conopsServerApp.c
* @brief ServerApp implementation template generator
********************************************************************************************
* @version           interface conops v2.0
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

#include "FP_conopsProtocolServer.h"

// @START_USER@ USER_INCLUDES
#include "conops.h"
#include "conops_internal.h"
#include "nvm/inc/nvm.h"
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL

// @END_USER@ USER_LOCAL_FUNC_DECL
static void conops_send_new_eventRequestHandlerImpl(ReqContext_t* pReqCtx,
            const conopssend_new_eventRequestData_t* pRequestData);

static void conops_get_op_modeRequestHandlerImpl(ReqContext_t* pReqCtx);

static void conops_set_thresh_valRequestHandlerImpl(ReqContext_t* pReqCtx,
            const conopsset_thresh_valRequestData_t* pRequestData);

static void conops_get_thresh_valRequestHandlerImpl(ReqContext_t* pReqCtx,
            const conopsget_thresh_valRequestData_t* pRequestData);

static void conops_set_all_thresh_valRequestHandlerImpl(ReqContext_t* pReqCtx,
            const conopsset_all_thresh_valRequestData_t* pRequestData);

static void conops_get_all_thresh_valRequestHandlerImpl(ReqContext_t* pReqCtx);

static void conops_request_mission_mode_enterRequestHandlerImpl(ReqContext_t* pReqCtx,
            const conopsrequest_mission_mode_enterRequestData_t* pRequestData);

static void conops_request_mission_mode_exitRequestHandlerImpl(ReqContext_t* pReqCtx);

static void conops_get_default_control_modeRequestHandlerImpl(ReqContext_t* pReqCtx,
            const conopsget_default_control_modeRequestData_t* pRequestData);

static void conops_set_default_control_modeRequestHandlerImpl(ReqContext_t* pReqCtx,
            const conopsset_default_control_modeRequestData_t* pRequestData);

static void conops_set_force_allow_payloadsRequestHandlerImpl(ReqContext_t* pReqCtx,
            const conopsset_force_allow_payloadsRequestData_t* pRequestData);

static void conops_get_force_allow_payloadsRequestHandlerImpl(ReqContext_t* pReqCtx);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_VARS_DECL

static conops_ServerApi_t conopsServerApiCtx =
{
  .conops_send_new_eventRequestHandler = conops_send_new_eventRequestHandlerImpl,
  .conops_get_op_modeRequestHandler = conops_get_op_modeRequestHandlerImpl,
  .conops_set_thresh_valRequestHandler = conops_set_thresh_valRequestHandlerImpl,
  .conops_get_thresh_valRequestHandler = conops_get_thresh_valRequestHandlerImpl,
  .conops_set_all_thresh_valRequestHandler = conops_set_all_thresh_valRequestHandlerImpl,
  .conops_get_all_thresh_valRequestHandler = conops_get_all_thresh_valRequestHandlerImpl,
  .conops_request_mission_mode_enterRequestHandler = conops_request_mission_mode_enterRequestHandlerImpl,
  .conops_request_mission_mode_exitRequestHandler = conops_request_mission_mode_exitRequestHandlerImpl,
  .conops_get_default_control_modeRequestHandler = conops_get_default_control_modeRequestHandlerImpl,
  .conops_set_default_control_modeRequestHandler = conops_set_default_control_modeRequestHandlerImpl,
  .conops_set_force_allow_payloadsRequestHandler = conops_set_force_allow_payloadsRequestHandlerImpl,
  .conops_get_force_allow_payloadsRequestHandler = conops_get_force_allow_payloadsRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL


// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method conops::send_new_event (ID = 0x00000000)
static void conops_send_new_eventRequestHandlerImpl(ReqContext_t *pReqCtx,
            const conopssend_new_eventRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    CONOPS_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@conops::send_new_event@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@conops::send_new_event@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@conops::send_new_event@

        if (pRequestData->eEvent_type < CONOPS_EVENTS_MAX_CNT)
        {
            CONOPS_Events_t event;

            switch (pRequestData->eEvent_type)
            {
            case CONOPS_EVENTS_RESET:
                event = eHSM_StdEvent_Reset;
                break;

            case CONOPS_EVENTS_ENTER_IDLE:
                event = ev_conops_sm_force_enter_idle;
                break;

            case CONOPS_EVENTS_ENTER_SAFE:
                event = ev_conops_sm_force_enter_safe;
                break;

            case CONOPS_EVENTS_ENTER_MISSION:
                event = ev_conops_sm_force_enter_mission;
                break;

            default:
                event = eHSM_StdEvent_Periodic;
            }

            if (false != conops_trigger_hsm(event, NULL))
            {
                eOp_result = CONOPS_STANDARDRESULT_SUCCESS;
            }
            else
            {
                eOp_result = CONOPS_STANDARDRESULT_ERROR;
            }
        }
        else
        {
            eOp_result = CONOPS_STANDARDRESULT_INVALID_ARGS;
        }

        // @USER_CODE_SECTION_END@conops::send_new_event@

        respResult = conops_send_new_eventResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_CONOPS, CONOPS_SEND_NEW_EVENT_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method conops::send_new_event (ID = 0x00000000)

// @START@ Request handler for method conops::get_op_mode (ID = 0x00000001)
static void conops_get_op_modeRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    CONOPS_StandardResult_t eOp_result;
    CONOPS_OpModes_t eOp_mode;

    // @USER_VAR_SECTION_START@conops::get_op_mode@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@conops::get_op_mode@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@conops::get_op_mode@
        
        uint8_t active_state;
        conops_get_hsm_active_state(&active_state);

        switch (active_state)
        {
        case STATE_SAFE:
            eOp_mode = CONOPS_OPMODES_MODE_SAFE;
            break;

        case STATE_SAFE_ENTRY:
            eOp_mode = CONOPS_OPMODES_MODE_SAFE_ENTRY;
            break;

        case STATE_CONTROL:
            eOp_mode = CONOPS_OPMODES_MODE_SAFE_CONTROL;
            break;

        case STATE_NO_CONTROL:
            eOp_mode = CONOPS_OPMODES_MODE_SAFE_NO_CONTROL;
            break;

        case STATE_IDLE:
            eOp_mode = CONOPS_OPMODES_MODE_IDLE;
            break;

        case STATE_MISSION:
            eOp_mode = CONOPS_OPMODES_MODE_MISSION;
            break;

        default:
            eOp_mode = CONOPS_OPMODES_MAX_CNT;
            break;
        }

        if (CONOPS_OPMODES_MAX_CNT != eOp_mode)
        {
            eOp_result = CONOPS_STANDARDRESULT_SUCCESS;
        }
        else
        {
            eOp_result = CONOPS_STANDARDRESULT_ERROR;
        }

        // @USER_CODE_SECTION_END@conops::get_op_mode@

        respResult = conops_get_op_modeResp(
                        &respCtx,
                        eOp_result,
                        eOp_mode
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_CONOPS, CONOPS_GET_OP_MODE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method conops::get_op_mode (ID = 0x00000001)

// @START@ Request handler for method conops::set_thresh_val (ID = 0x00000002)
static void conops_set_thresh_valRequestHandlerImpl(ReqContext_t *pReqCtx,
            const conopsset_thresh_valRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    CONOPS_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@conops::set_thresh_val@

    // Put your local variables in this section to preserve during merge!

    // @USER_VAR_SECTION_END@conops::set_thresh_val@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@conops::set_thresh_val@
        
        if (false != conops_set_thresh_val(pRequestData->i32Thresh_value, pRequestData->eThresh_type) )
        {
            eOp_result = CONOPS_STANDARDRESULT_SUCCESS;
        }
        else
        {
            eOp_result = CONOPS_STANDARDRESULT_ERROR;
        }
        
        // @USER_CODE_SECTION_END@conops::set_thresh_val@

        respResult = conops_set_thresh_valResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_CONOPS, CONOPS_SET_THRESH_VAL_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method conops::set_thresh_val (ID = 0x00000002)

// @START@ Request handler for method conops::get_thresh_val (ID = 0x00000003)
static void conops_get_thresh_valRequestHandlerImpl(ReqContext_t *pReqCtx,
            const conopsget_thresh_valRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    CONOPS_StandardResult_t eOp_result;
    int32_t i32Thresh_value;

    // @USER_VAR_SECTION_START@conops::get_thresh_val@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@conops::get_thresh_val@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@conops::get_thresh_val@
        
        if (false != conops_get_thresh_val((void *)&i32Thresh_value, pRequestData->eThresh_type) )
        {
            eOp_result = CONOPS_STANDARDRESULT_SUCCESS;
        }
        else
        {
            eOp_result = CONOPS_STANDARDRESULT_ERROR;
        }
        
        // @USER_CODE_SECTION_END@conops::get_thresh_val@

        respResult = conops_get_thresh_valResp(
                        &respCtx,
                        eOp_result,
                        i32Thresh_value
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_CONOPS, CONOPS_GET_THRESH_VAL_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method conops::get_thresh_val (ID = 0x00000003)

// @START@ Request handler for method conops::set_all_thresh_val (ID = 0x00000004)
static void conops_set_all_thresh_valRequestHandlerImpl(ReqContext_t *pReqCtx,
            const conopsset_all_thresh_valRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    CONOPS_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@conops::set_all_thresh_val@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@conops::set_all_thresh_val@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@conops::set_all_thresh_val@
        
        if (true == conops_set_all_thresh_val(&pRequestData->sThresh_vals))
        {
           eOp_result = CONOPS_STANDARDRESULT_SUCCESS;
        }
        else
        {
           eOp_result = CONOPS_STANDARDRESULT_ERROR;
        }
        
        // @USER_CODE_SECTION_END@conops::set_all_thresh_val@

        respResult = conops_set_all_thresh_valResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_CONOPS, CONOPS_SET_ALL_THRESH_VAL_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method conops::set_all_thresh_val (ID = 0x00000004)

// @START@ Request handler for method conops::get_all_thresh_val (ID = 0x00000005)
static void conops_get_all_thresh_valRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    CONOPS_StandardResult_t eOp_result;
    CONOPS_ThresholdValues_t sThresh_vals;

    // @USER_VAR_SECTION_START@conops::get_all_thresh_val@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@conops::get_all_thresh_val@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@conops::get_all_thresh_val@
        
        if (true == conops_get_all_thresh_val(&sThresh_vals))
        {
            eOp_result = CONOPS_STANDARDRESULT_SUCCESS;
        }
         else
        {
            eOp_result = CONOPS_STANDARDRESULT_ERROR;
        }
        
        // @USER_CODE_SECTION_END@conops::get_all_thresh_val@

        respResult = conops_get_all_thresh_valResp(
                        &respCtx,
                        eOp_result,
                        &sThresh_vals
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_CONOPS, CONOPS_GET_ALL_THRESH_VAL_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method conops::get_all_thresh_val (ID = 0x00000005)

// @START@ Request handler for method conops::request_mission_mode_enter (ID = 0x00000006)
static void conops_request_mission_mode_enterRequestHandlerImpl(ReqContext_t *pReqCtx,
            const conopsrequest_mission_mode_enterRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    CONOPS_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@conops::request_mission_mode_enter@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@conops::request_mission_mode_enter@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@conops::request_mission_mode_enter@
        
        if (false != conops_trigger_hsm(ev_conops_sm_force_enter_mission, (const void*)&pRequestData->u32Timeout))
        {
            eOp_result = CONOPS_STANDARDRESULT_SUCCESS;
        }
        else
        {
            eOp_result = CONOPS_STANDARDRESULT_ERROR;
        }

        // @USER_CODE_SECTION_END@conops::request_mission_mode_enter@

        respResult = conops_request_mission_mode_enterResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_CONOPS, CONOPS_REQUEST_MISSION_MODE_ENTER_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method conops::request_mission_mode_enter (ID = 0x00000006)

// @START@ Request handler for method conops::request_mission_mode_exit (ID = 0x00000007)
static void conops_request_mission_mode_exitRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    CONOPS_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@conops::request_mission_mode_exit@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@conops::request_mission_mode_exit@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@conops::request_mission_mode_exit@

        if (false != conops_trigger_hsm(ev_conops_sm_force_enter_idle, NULL))
        {
            eOp_result = CONOPS_STANDARDRESULT_SUCCESS;
        }
        else
        {
            eOp_result = CONOPS_STANDARDRESULT_ERROR;
        }
        
        // @USER_CODE_SECTION_END@conops::request_mission_mode_exit@

        respResult = conops_request_mission_mode_exitResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_CONOPS, CONOPS_REQUEST_MISSION_MODE_EXIT_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method conops::request_mission_mode_exit (ID = 0x00000007)

// @START@ Request handler for method conops::get_default_control_mode (ID = 0x00000008)
static void conops_get_default_control_modeRequestHandlerImpl(ReqContext_t *pReqCtx,
            const conopsget_default_control_modeRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    CONOPS_StandardResult_t eOp_result;
    CONOPS_ControlMode_t sControl_mode;

    // @USER_VAR_SECTION_START@conops::get_default_control_mode@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@conops::get_default_control_mode@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@conops::get_default_control_mode@
        
        if (pRequestData->eConops_mode < CONOPS_MODESWITHDEFCTRL_MAX_CNT)
        {
            conops_config_t cfg;
            Nvm_GetBlockById(NVM_APP_BLOCK_CONOPS_CONFIG, &cfg);
            memcpy(&sControl_mode, &cfg.def_control[pRequestData->eConops_mode], sizeof(sControl_mode));

            eOp_result = CONOPS_STANDARDRESULT_SUCCESS;
        }
        else
        {
            eOp_result = CONOPS_STANDARDRESULT_INVALID_ARGS;
        }

        // @USER_CODE_SECTION_END@conops::get_default_control_mode@

        respResult = conops_get_default_control_modeResp(
                        &respCtx,
                        eOp_result,
                        &sControl_mode
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_CONOPS, CONOPS_GET_DEFAULT_CONTROL_MODE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method conops::get_default_control_mode (ID = 0x00000008)

// @START@ Request handler for method conops::set_default_control_mode (ID = 0x00000009)
static void conops_set_default_control_modeRequestHandlerImpl(ReqContext_t *pReqCtx,
            const conopsset_default_control_modeRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    CONOPS_StandardResult_t eOp_result;
    CONOPS_ControlMode_t sSet_control_mode;

    // @USER_VAR_SECTION_START@conops::set_default_control_mode@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@conops::set_default_control_mode@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@conops::set_default_control_mode@
        
        if (pRequestData->eConops_mode < CONOPS_MODESWITHDEFCTRL_MAX_CNT)
        {
            conops_config_t cfg;
            Nvm_GetBlockById(NVM_APP_BLOCK_CONOPS_CONFIG, &cfg);
            memcpy(&cfg.def_control[pRequestData->eConops_mode], &pRequestData->sControl_mode,
                   sizeof(cfg.def_control[pRequestData->eConops_mode]));
            Nvm_SetBlockById(NVM_APP_BLOCK_CONOPS_CONFIG, &cfg, NVMSETBLOCK_STORE_IMMEDIATELY);
            Nvm_GetBlockById(NVM_APP_BLOCK_CONOPS_CONFIG, &cfg);
            memcpy(&sSet_control_mode, &cfg.def_control[pRequestData->eConops_mode], sizeof(sSet_control_mode));

            eOp_result = CONOPS_STANDARDRESULT_SUCCESS;
        }
        else
        {
            eOp_result = CONOPS_STANDARDRESULT_INVALID_ARGS;
        }

        // @USER_CODE_SECTION_END@conops::set_default_control_mode@

        respResult = conops_set_default_control_modeResp(
                        &respCtx,
                        eOp_result,
                        &sSet_control_mode
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_CONOPS, CONOPS_SET_DEFAULT_CONTROL_MODE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method conops::set_default_control_mode (ID = 0x00000009)

// @START@ Request handler for method conops::set_force_allow_payloads (ID = 0x0000000A)
static void conops_set_force_allow_payloadsRequestHandlerImpl(ReqContext_t *pReqCtx,
            const conopsset_force_allow_payloadsRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    CONOPS_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@conops::set_force_allow_payloads@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@conops::set_force_allow_payloads@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@conops::set_force_allow_payloads@

        conops_nvm_data_t nvm_data;
        nvm_data.force_enable_payload = pRequestData->eIs_allowed;
        Nvm_SetBlockById(NVM_BLOCK_CONOPS_DATA, &nvm_data, NVMSETBLOCK_STORE_POSTPONED);
        eOp_result = CONOPS_STANDARDRESULT_SUCCESS;
        
        // @USER_CODE_SECTION_END@conops::set_force_allow_payloads@

        respResult = conops_set_force_allow_payloadsResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_CONOPS, CONOPS_SET_FORCE_ALLOW_PAYLOADS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method conops::set_force_allow_payloads (ID = 0x0000000A)

// @START@ Request handler for method conops::get_force_allow_payloads (ID = 0x0000000B)
static void conops_get_force_allow_payloadsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    CONOPS_SafeBool_t eSet_is_allowed;

    // @USER_VAR_SECTION_START@conops::get_force_allow_payloads@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@conops::get_force_allow_payloads@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@conops::get_force_allow_payloads@
        
        conops_nvm_data_t nvm_data;
        Nvm_GetBlockById(NVM_BLOCK_CONOPS_DATA, &nvm_data);
        eSet_is_allowed = nvm_data.force_enable_payload;
        
        // @USER_CODE_SECTION_END@conops::get_force_allow_payloads@

        respResult = conops_get_force_allow_payloadsResp(
                        &respCtx,
                        eSet_is_allowed
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_CONOPS, CONOPS_GET_FORCE_ALLOW_PAYLOADS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method conops::get_force_allow_payloads (ID = 0x0000000B)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void conopsServerAppInit(void)
{
    conops_registerServerApi(&conopsServerApiCtx);
}
