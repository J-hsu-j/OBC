/*!
********************************************************************************************
* @file FP_xband_feServerApp.c
* @brief ServerApp implementation template generator
********************************************************************************************
* @version           interface xband_fe v0.1
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

#include "FP_xband_feProtocolServer.h"

// @START_USER@ USER_INCLUDES
// Place user includes here to preserve them during merge!!!
#include "xband_fe_proto.h"
#include "comm_gw.h"
#include "nvm.h"
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!

/** @brief Converts an internal comm_gw status to a FIDL status
 *  @param[in] comm_res_internal internal status provided by comm_gw
 *
 *  @return FIDL comm_gw status
 */
static XBAND_FE_CommRes_t convert_comm_res_internal(const comm_gw_comm_res_t comm_res_internal);

// @END_USER@ USER_LOCAL_FUNC_DECL
static void xband_fe_get_obc_xband_fe_nvm_cfgRequestHandlerImpl(ReqContext_t* pReqCtx);

static void xband_fe_set_obc_xband_fe_nvm_cfgRequestHandlerImpl(ReqContext_t* pReqCtx,
            const xband_feset_obc_xband_fe_nvm_cfgRequestData_t* pRequestData);

static void xband_fe_get_status_reportRequestHandlerImpl(ReqContext_t* pReqCtx);

static void xband_fe_set_sys_mngr_run_modeRequestHandlerImpl(ReqContext_t* pReqCtx);

static void xband_fe_set_sys_mngr_standby_modeRequestHandlerImpl(ReqContext_t* pReqCtx);

static void xband_fe_set_mod_all_paramsRequestHandlerImpl(ReqContext_t* pReqCtx,
            const xband_feset_mod_all_paramsRequestData_t* pRequestData);

static void xband_fe_get_mod_all_paramsRequestHandlerImpl(ReqContext_t* pReqCtx);

static void xband_fe_set_tx_powerRequestHandlerImpl(ReqContext_t* pReqCtx,
            const xband_feset_tx_powerRequestData_t* pRequestData);

static void xband_fe_get_tx_powerRequestHandlerImpl(ReqContext_t* pReqCtx);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_VARS_DECL

static xband_fe_ServerApi_t xband_feServerApiCtx =
{
  .xband_fe_get_obc_xband_fe_nvm_cfgRequestHandler = xband_fe_get_obc_xband_fe_nvm_cfgRequestHandlerImpl,
  .xband_fe_set_obc_xband_fe_nvm_cfgRequestHandler = xband_fe_set_obc_xband_fe_nvm_cfgRequestHandlerImpl,
  .xband_fe_get_status_reportRequestHandler = xband_fe_get_status_reportRequestHandlerImpl,
  .xband_fe_set_sys_mngr_run_modeRequestHandler = xband_fe_set_sys_mngr_run_modeRequestHandlerImpl,
  .xband_fe_set_sys_mngr_standby_modeRequestHandler = xband_fe_set_sys_mngr_standby_modeRequestHandlerImpl,
  .xband_fe_set_mod_all_paramsRequestHandler = xband_fe_set_mod_all_paramsRequestHandlerImpl,
  .xband_fe_get_mod_all_paramsRequestHandler = xband_fe_get_mod_all_paramsRequestHandlerImpl,
  .xband_fe_set_tx_powerRequestHandler = xband_fe_set_tx_powerRequestHandlerImpl,
  .xband_fe_get_tx_powerRequestHandler = xband_fe_get_tx_powerRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
static XBAND_FE_CommRes_t convert_comm_res_internal(const comm_gw_comm_res_t comm_res_internal)
{
    switch (comm_res_internal)
    {
        case COMM_GW_RES_OK:
        {
            return XBAND_FE_COMMRES_OK;
        }

        case COMM_GW_RES_OK_PARTIAL:
        {
            return XBAND_FE_COMMRES_OK_PARTIAL;
        }

        case COMM_GW_RES_ERR:
        {
            return XBAND_FE_COMMRES_ERR;
        }

        case COMM_GW_RES_INVALID_ARGS:
        {
            return XBAND_FE_COMMRES_INVALID_ARGS;
        }

        case COMM_GW_RES_SEND_ERR:
        {
            return XBAND_FE_COMMRES_SEND_ERR;
        }

        case COMM_GW_RES_SND_TIMEOUT:
        {
            return XBAND_FE_COMMRES_SND_TIMEOUT;
        }

        case COMM_GW_RES_RCV_TIMEOUT:
        {
            return XBAND_FE_COMMRES_RCV_TIMEOUT;
        }

        default:
        {
            return XBAND_FE_COMMRES_INVALID_ARGS;
        }
    }
}
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method xband_fe::get_obc_xband_fe_nvm_cfg (ID = 0x00000000)
static void xband_fe_get_obc_xband_fe_nvm_cfgRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    XBAND_FE_ObcXBandFeNvmCfg_t sNvm_params;

    // @USER_VAR_SECTION_START@xband_fe::get_obc_xband_fe_nvm_cfg@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@xband_fe::get_obc_xband_fe_nvm_cfg@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@xband_fe::get_obc_xband_fe_nvm_cfg@
        xband_fe_config_t xband_cfg;
        
        Nvm_GetBlockById(NVM_BLOCK_XBAND_FE_CFG, &xband_cfg);
        
        sNvm_params.u8Target_node_addr = xband_cfg.target_node_addr;
        sNvm_params.u8Port = xband_cfg.port;
        sNvm_params.u8Prio = xband_cfg.prio;
        sNvm_params.u32Opts = xband_cfg.opts;
        // @USER_CODE_SECTION_END@xband_fe::get_obc_xband_fe_nvm_cfg@

        respResult = xband_fe_get_obc_xband_fe_nvm_cfgResp(
                        &respCtx,
                        &sNvm_params
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE, XBAND_FE_GET_OBC_XBAND_FE_NVM_CFG_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method xband_fe::get_obc_xband_fe_nvm_cfg (ID = 0x00000000)

// @START@ Request handler for method xband_fe::set_obc_xband_fe_nvm_cfg (ID = 0x00000001)
static void xband_fe_set_obc_xband_fe_nvm_cfgRequestHandlerImpl(ReqContext_t *pReqCtx,
            const xband_feset_obc_xband_fe_nvm_cfgRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    bool bSuccess;

    // @USER_VAR_SECTION_START@xband_fe::set_obc_xband_fe_nvm_cfg@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@xband_fe::set_obc_xband_fe_nvm_cfg@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@xband_fe::set_obc_xband_fe_nvm_cfg@
        xband_fe_config_t xband_cfg;

        xband_cfg.target_node_addr = pRequestData->sNvm_params_in.u8Target_node_addr;
        xband_cfg.port = pRequestData->sNvm_params_in.u8Port;
        xband_cfg.prio = pRequestData->sNvm_params_in.u8Prio;
        xband_cfg.opts = pRequestData->sNvm_params_in.u32Opts;

        Nvm_SetBlockById(NVM_BLOCK_XBAND_FE_CFG, &xband_cfg, NVMSETBLOCK_STORE_IMMEDIATELY);
        
        bSuccess = true;
        // @USER_CODE_SECTION_END@xband_fe::set_obc_xband_fe_nvm_cfg@

        respResult = xband_fe_set_obc_xband_fe_nvm_cfgResp(
                        &respCtx,
                        bSuccess
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE, XBAND_FE_SET_OBC_XBAND_FE_NVM_CFG_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method xband_fe::set_obc_xband_fe_nvm_cfg (ID = 0x00000001)

// @START@ Request handler for method xband_fe::get_status_report (ID = 0x0000004B)
static void xband_fe_get_status_reportRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    XBAND_FE_CommRes_t eComm_res;
    XBAND_FE_ModStatusReportParamsWrapper_t sStatus_params;

    // @USER_VAR_SECTION_START@xband_fe::get_status_report@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@xband_fe::get_status_report@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@xband_fe::get_status_report@
        eComm_res = convert_comm_res_internal(xband_fe_proto_get_status_report(NULL, &sStatus_params));
        
        // @USER_CODE_SECTION_END@xband_fe::get_status_report@

        respResult = xband_fe_get_status_reportResp(
                        &respCtx,
                        eComm_res,
                        &sStatus_params
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE, XBAND_FE_GET_STATUS_REPORT_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method xband_fe::get_status_report (ID = 0x0000004B)

// @START@ Request handler for method xband_fe::set_sys_mngr_run_mode (ID = 0x000000B2)
static void xband_fe_set_sys_mngr_run_modeRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    XBAND_FE_CommRes_t eComm_res;
    XBAND_FE_StdResponseWrapper_t sCmd_resp;

    // @USER_VAR_SECTION_START@xband_fe::set_sys_mngr_run_mode@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@xband_fe::set_sys_mngr_run_mode@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@xband_fe::set_sys_mngr_run_mode@
        eComm_res = convert_comm_res_internal(xband_fe_proto_exec_sys_mngr_run(NULL, &sCmd_resp));
        // @USER_CODE_SECTION_END@xband_fe::set_sys_mngr_run_mode@

        respResult = xband_fe_set_sys_mngr_run_modeResp(
                        &respCtx,
                        eComm_res,
                        &sCmd_resp
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE, XBAND_FE_SET_SYS_MNGR_RUN_MODE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method xband_fe::set_sys_mngr_run_mode (ID = 0x000000B2)

// @START@ Request handler for method xband_fe::set_sys_mngr_standby_mode (ID = 0x000000B3)
static void xband_fe_set_sys_mngr_standby_modeRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    XBAND_FE_CommRes_t eComm_res;
    XBAND_FE_StdResponseWrapper_t sCmd_resp;

    // @USER_VAR_SECTION_START@xband_fe::set_sys_mngr_standby_mode@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@xband_fe::set_sys_mngr_standby_mode@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@xband_fe::set_sys_mngr_standby_mode@
        eComm_res = convert_comm_res_internal(xband_fe_proto_exec_sys_mngr_stand_by(NULL, &sCmd_resp));
        // @USER_CODE_SECTION_END@xband_fe::set_sys_mngr_standby_mode@

        respResult = xband_fe_set_sys_mngr_standby_modeResp(
                        &respCtx,
                        eComm_res,
                        &sCmd_resp
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE, XBAND_FE_SET_SYS_MNGR_STANDBY_MODE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method xband_fe::set_sys_mngr_standby_mode (ID = 0x000000B3)

// @START@ Request handler for method xband_fe::set_mod_all_params (ID = 0x000000BA)
static void xband_fe_set_mod_all_paramsRequestHandlerImpl(ReqContext_t *pReqCtx,
            const xband_feset_mod_all_paramsRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    XBAND_FE_CommRes_t eComm_res;
    XBAND_FE_StdResponseWrapper_t sCmd_resp;

    // @USER_VAR_SECTION_START@xband_fe::set_mod_all_params@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@xband_fe::set_mod_all_params@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@xband_fe::set_mod_all_params@
        eComm_res = convert_comm_res_internal(xband_fe_proto_set_mod_all_params(pRequestData, &sCmd_resp));
        // @USER_CODE_SECTION_END@xband_fe::set_mod_all_params@

        respResult = xband_fe_set_mod_all_paramsResp(
                        &respCtx,
                        eComm_res,
                        &sCmd_resp
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE, XBAND_FE_SET_MOD_ALL_PARAMS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method xband_fe::set_mod_all_params (ID = 0x000000BA)

// @START@ Request handler for method xband_fe::get_mod_all_params (ID = 0x000000BB)
static void xband_fe_get_mod_all_paramsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    XBAND_FE_CommRes_t eComm_res;
    XBAND_FE_ModCfgParamsWrapper_t sCfg_params;

    // @USER_VAR_SECTION_START@xband_fe::get_mod_all_params@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@xband_fe::get_mod_all_params@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@xband_fe::get_mod_all_params@
        eComm_res = convert_comm_res_internal(xband_fe_proto_get_mod_all_params(NULL, &sCfg_params));
        // @USER_CODE_SECTION_END@xband_fe::get_mod_all_params@

        respResult = xband_fe_get_mod_all_paramsResp(
                        &respCtx,
                        eComm_res,
                        &sCfg_params
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE, XBAND_FE_GET_MOD_ALL_PARAMS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method xband_fe::get_mod_all_params (ID = 0x000000BB)

// @START@ Request handler for method xband_fe::set_tx_power (ID = 0x000000BD)
static void xband_fe_set_tx_powerRequestHandlerImpl(ReqContext_t *pReqCtx,
            const xband_feset_tx_powerRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    XBAND_FE_CommRes_t eComm_res;
    XBAND_FE_StdResponseWrapper_t sCmd_resp;

    // @USER_VAR_SECTION_START@xband_fe::set_tx_power@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@xband_fe::set_tx_power@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@xband_fe::set_tx_power@
        eComm_res = convert_comm_res_internal(xband_fe_proto_set_tx_power(pRequestData, &sCmd_resp));
        // @USER_CODE_SECTION_END@xband_fe::set_tx_power@

        respResult = xband_fe_set_tx_powerResp(
                        &respCtx,
                        eComm_res,
                        &sCmd_resp
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE, XBAND_FE_SET_TX_POWER_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method xband_fe::set_tx_power (ID = 0x000000BD)

// @START@ Request handler for method xband_fe::get_tx_power (ID = 0x000000BE)
static void xband_fe_get_tx_powerRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    XBAND_FE_CommRes_t eComm_res;
    XBAND_FE_XBandFeTxPowerInfoWrapper_t sTx_power_info;

    // @USER_VAR_SECTION_START@xband_fe::get_tx_power@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@xband_fe::get_tx_power@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@xband_fe::get_tx_power@
        eComm_res = convert_comm_res_internal(xband_fe_proto_get_tx_power(NULL, &sTx_power_info));
        // @USER_CODE_SECTION_END@xband_fe::get_tx_power@

        respResult = xband_fe_get_tx_powerResp(
                        &respCtx,
                        eComm_res,
                        &sTx_power_info
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE, XBAND_FE_GET_TX_POWER_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method xband_fe::get_tx_power (ID = 0x000000BE)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void xband_feServerAppInit(void)
{
    xband_fe_registerServerApi(&xband_feServerApiCtx);
}
