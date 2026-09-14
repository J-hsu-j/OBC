/*!
********************************************************************************************
* @file FP_eps_ctrlServerApp.c
* @brief ServerApp implementation template generator
********************************************************************************************
* @version           interface eps_ctrl v0.1
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

#include "FP_eps_ctrlProtocolServer.h"

// @START_USER@ USER_INCLUDES
// Place user includes here to preserve them during merge!!!
#include "eps_ctrl.h"
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL

// @END_USER@ USER_LOCAL_FUNC_DECL
static void eps_ctrl_get_ch_outputRequestHandlerImpl(ReqContext_t* pReqCtx,
            const eps_ctrlget_ch_outputRequestData_t* pRequestData);

static void eps_ctrl_set_ch_outputRequestHandlerImpl(ReqContext_t* pReqCtx,
            const eps_ctrlset_ch_outputRequestData_t* pRequestData);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL

#define BP_OFFSET          (0)
#define PDM_A_OFFSET       (NVM_EPS_EPSIIIBPIDTYPE_MAX_CNT)
#define PDM_B_OFFSET       (PDM_A_OFFSET + NVM_EPS_EPSIIIPDMAIDTYPE_MAX_CNT)
#define EXPANDER_OFFSET    (PDM_B_OFFSET + NVM_EPS_EPSIIIPDMBIDTYPE_MAX_CNT)
#define INPUT_STAGE_OFFSET (EXPANDER_OFFSET + NVM_EPS_EPSIIIEXPANDERIDTYPE_MAX_CNT)

#define EPS3_DEV_CNT (INPUT_STAGE_OFFSET + NVM_EPS_EPSIIIINPUTSTAGEIDTYPE_MAX_CNT)

// @END_USER@ USER_LOCAL_VARS_DECL

static eps_ctrl_ServerApi_t eps_ctrlServerApiCtx =
{
  .eps_ctrl_get_ch_outputRequestHandler = eps_ctrl_get_ch_outputRequestHandlerImpl,
  .eps_ctrl_set_ch_outputRequestHandler = eps_ctrl_set_ch_outputRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL

// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method eps_ctrl::get_ch_output (ID = 0x00000001)
static void eps_ctrl_get_ch_outputRequestHandlerImpl(ReqContext_t *pReqCtx,
            const eps_ctrlget_ch_outputRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    bool bCh_state;
    EPS_CTRL_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@eps_ctrl::get_ch_output@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@eps_ctrl::get_ch_output@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@eps_ctrl::get_ch_output@

        eps_ctrl_result_t res = eps_ctrl_get_channel_output(pRequestData->u8Ch_id, &bCh_state);

        switch (res)
        {
            case EPS_CTRL_DONE:
                eOp_result = EPS_CTRL_STANDARDRESULT_SUCCESS;
                break;
            case EPS_CTRL_WRONG_PARAMS:
                eOp_result = EPS_CTRL_STANDARDRESULT_INVALID_ARGS;
                break;
            default:
                eOp_result = EPS_CTRL_STANDARDRESULT_ERROR;
                break;
        }

        // @USER_CODE_SECTION_END@eps_ctrl::get_ch_output@

        respResult = eps_ctrl_get_ch_outputResp(
                        &respCtx,
                        bCh_state,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_EPS_CTRL, EPS_CTRL_GET_CH_OUTPUT_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method eps_ctrl::get_ch_output (ID = 0x00000001)

// @START@ Request handler for method eps_ctrl::set_ch_output (ID = 0x00000002)
static void eps_ctrl_set_ch_outputRequestHandlerImpl(ReqContext_t *pReqCtx,
            const eps_ctrlset_ch_outputRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    EPS_CTRL_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@eps_ctrl::set_ch_output@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@eps_ctrl::set_ch_output@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@eps_ctrl::set_ch_output@

        eps_ctrl_result_t res = eps_ctrl_set_channel_output(pRequestData->u8Ch_id, pRequestData->bNew_state);

        switch (res)
        {
            case EPS_CTRL_DONE:
                eOp_result = EPS_CTRL_STANDARDRESULT_SUCCESS;
                break;
            case EPS_CTRL_WRONG_PARAMS:
                eOp_result = EPS_CTRL_STANDARDRESULT_INVALID_ARGS;
                break;
            default:
                eOp_result = EPS_CTRL_STANDARDRESULT_ERROR;
                break;
        }

        // @USER_CODE_SECTION_END@eps_ctrl::set_ch_output@

        respResult = eps_ctrl_set_ch_outputResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_EPS_CTRL, EPS_CTRL_SET_CH_OUTPUT_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method eps_ctrl::set_ch_output (ID = 0x00000002)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void eps_ctrlServerAppInit(void)
{
    eps_ctrl_registerServerApi(&eps_ctrlServerApiCtx);
}
