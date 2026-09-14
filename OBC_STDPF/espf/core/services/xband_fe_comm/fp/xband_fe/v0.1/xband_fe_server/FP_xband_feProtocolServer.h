/*!
********************************************************************************************
* @file FP_xband_feProtocolServer.h
* @brief ESSA Stack server-side public API declaration
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

#ifndef FP_XBAND_FEPROTOCOLSERVER_H
#define FP_XBAND_FEPROTOCOLSERVER_H

#include "FP_xband_feProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define xband_fe_PROTOCOL_VERSION_MAJOR   ((uint8_t) 0)
#define xband_fe_PROTOCOL_VERSION_MINOR   ((uint8_t) 1)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfxband_fe_get_obc_xband_fe_nvm_cfgRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfxband_fe_set_obc_xband_fe_nvm_cfgRequestHandler_t)(ReqContext_t *ctx, const xband_feset_obc_xband_fe_nvm_cfgRequestData_t *pRequestData);
typedef void (*pfxband_fe_get_status_reportRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfxband_fe_set_sys_mngr_run_modeRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfxband_fe_set_sys_mngr_standby_modeRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfxband_fe_set_mod_all_paramsRequestHandler_t)(ReqContext_t *ctx, const xband_feset_mod_all_paramsRequestData_t *pRequestData);
typedef void (*pfxband_fe_get_mod_all_paramsRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfxband_fe_set_tx_powerRequestHandler_t)(ReqContext_t *ctx, const xband_feset_tx_powerRequestData_t *pRequestData);
typedef void (*pfxband_fe_get_tx_powerRequestHandler_t)(ReqContext_t *ctx);

typedef struct {
    pfxband_fe_get_obc_xband_fe_nvm_cfgRequestHandler_t xband_fe_get_obc_xband_fe_nvm_cfgRequestHandler;
    pfxband_fe_set_obc_xband_fe_nvm_cfgRequestHandler_t xband_fe_set_obc_xband_fe_nvm_cfgRequestHandler;
    pfxband_fe_get_status_reportRequestHandler_t xband_fe_get_status_reportRequestHandler;
    pfxband_fe_set_sys_mngr_run_modeRequestHandler_t xband_fe_set_sys_mngr_run_modeRequestHandler;
    pfxband_fe_set_sys_mngr_standby_modeRequestHandler_t xband_fe_set_sys_mngr_standby_modeRequestHandler;
    pfxband_fe_set_mod_all_paramsRequestHandler_t xband_fe_set_mod_all_paramsRequestHandler;
    pfxband_fe_get_mod_all_paramsRequestHandler_t xband_fe_get_mod_all_paramsRequestHandler;
    pfxband_fe_set_tx_powerRequestHandler_t xband_fe_set_tx_powerRequestHandler;
    pfxband_fe_get_tx_powerRequestHandler_t xband_fe_get_tx_powerRequestHandler;
} xband_fe_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_xband_feProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void xband_fe_registerServerApi(xband_fe_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_xband_feProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t xband_fe_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes xband_fe_get_obc_xband_fe_nvm_cfgResp(
                RespContext_t* ctx,
                const XBAND_FE_ObcXBandFeNvmCfg_t * const sNvm_params
);

ESSATMAC_ErrCodes xband_fe_set_obc_xband_fe_nvm_cfgResp(
                RespContext_t* ctx,
                const bool bSuccess
);

ESSATMAC_ErrCodes xband_fe_get_status_reportResp(
                RespContext_t* ctx,
                const XBAND_FE_CommRes_t eComm_res,
                const XBAND_FE_ModStatusReportParamsWrapper_t * const sStatus_params
);

ESSATMAC_ErrCodes xband_fe_set_sys_mngr_run_modeResp(
                RespContext_t* ctx,
                const XBAND_FE_CommRes_t eComm_res,
                const XBAND_FE_StdResponseWrapper_t * const sCmd_resp
);

ESSATMAC_ErrCodes xband_fe_set_sys_mngr_standby_modeResp(
                RespContext_t* ctx,
                const XBAND_FE_CommRes_t eComm_res,
                const XBAND_FE_StdResponseWrapper_t * const sCmd_resp
);

ESSATMAC_ErrCodes xband_fe_set_mod_all_paramsResp(
                RespContext_t* ctx,
                const XBAND_FE_CommRes_t eComm_res,
                const XBAND_FE_StdResponseWrapper_t * const sCmd_resp
);

ESSATMAC_ErrCodes xband_fe_get_mod_all_paramsResp(
                RespContext_t* ctx,
                const XBAND_FE_CommRes_t eComm_res,
                const XBAND_FE_ModCfgParamsWrapper_t * const sCfg_params
);

ESSATMAC_ErrCodes xband_fe_set_tx_powerResp(
                RespContext_t* ctx,
                const XBAND_FE_CommRes_t eComm_res,
                const XBAND_FE_StdResponseWrapper_t * const sCmd_resp
);

ESSATMAC_ErrCodes xband_fe_get_tx_powerResp(
                RespContext_t* ctx,
                const XBAND_FE_CommRes_t eComm_res,
                const XBAND_FE_XBandFeTxPowerInfoWrapper_t * const sTx_power_info
);


#endif  // #ifndef FP_XBAND_FEPROTOCOLSERVER_H
