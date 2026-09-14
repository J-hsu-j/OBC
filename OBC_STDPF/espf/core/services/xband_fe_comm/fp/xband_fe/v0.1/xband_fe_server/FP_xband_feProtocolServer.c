/*!
********************************************************************************************
* @file FP_xband_feProtocolServer.c
* @brief ESSA Stack server-side implementation
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
#include "FP_common/FP_ProtocolServerCommon.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Local type definitions
 *
 **********************************************************************/
typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT xband_feget_obc_xband_fe_nvm_cfgProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    xband_feget_obc_xband_fe_nvm_cfgResponseData_t data;
} PACKED_STRUCT xband_feget_obc_xband_fe_nvm_cfgProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    xband_feset_obc_xband_fe_nvm_cfgRequestData_t data;
} PACKED_STRUCT xband_feset_obc_xband_fe_nvm_cfgProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    xband_feset_obc_xband_fe_nvm_cfgResponseData_t data;
} PACKED_STRUCT xband_feset_obc_xband_fe_nvm_cfgProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT xband_feget_status_reportProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    xband_feget_status_reportResponseData_t data;
} PACKED_STRUCT xband_feget_status_reportProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT xband_feset_sys_mngr_run_modeProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    xband_feset_sys_mngr_run_modeResponseData_t data;
} PACKED_STRUCT xband_feset_sys_mngr_run_modeProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT xband_feset_sys_mngr_standby_modeProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    xband_feset_sys_mngr_standby_modeResponseData_t data;
} PACKED_STRUCT xband_feset_sys_mngr_standby_modeProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    xband_feset_mod_all_paramsRequestData_t data;
} PACKED_STRUCT xband_feset_mod_all_paramsProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    xband_feset_mod_all_paramsResponseData_t data;
} PACKED_STRUCT xband_feset_mod_all_paramsProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT xband_feget_mod_all_paramsProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    xband_feget_mod_all_paramsResponseData_t data;
} PACKED_STRUCT xband_feget_mod_all_paramsProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    xband_feset_tx_powerRequestData_t data;
} PACKED_STRUCT xband_feset_tx_powerProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    xband_feset_tx_powerResponseData_t data;
} PACKED_STRUCT xband_feset_tx_powerProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT xband_feget_tx_powerProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    xband_feget_tx_powerResponseData_t data;
} PACKED_STRUCT xband_feget_tx_powerProtocolResponseData_t;


/**********************************************************************
 *
 *  Static methods declarations
 *
 **********************************************************************/
static bool fs_HandleData(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_obc_xband_fe_nvm_cfgReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_obc_xband_fe_nvm_cfgReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_status_reportReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_sys_mngr_run_modeReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_sys_mngr_standby_modeReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_mod_all_paramsReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_mod_all_paramsReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_tx_powerReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_tx_powerReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);

/**********************************************************************
 *
 *  Public variable definitions
 *
 **********************************************************************/
const ESSA_Stack_FunctionProtocolInfo_t FP_xband_feProtocolServerInfo = {
    .u16ProtocolId    = ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE,
        .pfDataHandlerCbk = &fs_HandleData
};

/**********************************************************************
 *
 *  Static variable definitions
 *
 **********************************************************************/
static xband_fe_ServerApi_t *pSrvApiHnd = NULL;

static const ProtocolFuncArrayEntry_t fs_aFuncArray[] = {
    { XBAND_FE_GET_OBC_XBAND_FE_NVM_CFG_FUNC_ID, fs_get_obc_xband_fe_nvm_cfgReq },
    { XBAND_FE_SET_OBC_XBAND_FE_NVM_CFG_FUNC_ID, fs_set_obc_xband_fe_nvm_cfgReq },
    { XBAND_FE_GET_STATUS_REPORT_FUNC_ID, fs_get_status_reportReq },
    { XBAND_FE_SET_SYS_MNGR_RUN_MODE_FUNC_ID, fs_set_sys_mngr_run_modeReq },
    { XBAND_FE_SET_SYS_MNGR_STANDBY_MODE_FUNC_ID, fs_set_sys_mngr_standby_modeReq },
    { XBAND_FE_SET_MOD_ALL_PARAMS_FUNC_ID, fs_set_mod_all_paramsReq },
    { XBAND_FE_GET_MOD_ALL_PARAMS_FUNC_ID, fs_get_mod_all_paramsReq },
    { XBAND_FE_SET_TX_POWER_FUNC_ID, fs_set_tx_powerReq },
    { XBAND_FE_GET_TX_POWER_FUNC_ID, fs_get_tx_powerReq }
};

/**********************************************************************
 *
 *  Static methods implementation
 *
 **********************************************************************/
static bool fs_HandleData(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    return FP_Helpers_HandleDataInternal(fp_DataInfo, &fs_aFuncArray[0], (const uint16_t) COUNT_OF(fs_aFuncArray));
}







static void fs_get_obc_xband_fe_nvm_cfgReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    xband_feget_obc_xband_fe_nvm_cfgProtocolRequestData_t *fullrequest = (xband_feget_obc_xband_fe_nvm_cfgProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(xband_feget_obc_xband_fe_nvm_cfgProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->xband_fe_get_obc_xband_fe_nvm_cfgRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->xband_fe_get_obc_xband_fe_nvm_cfgRequestHandler(&requestCtx);
    }
}

static void fs_set_obc_xband_fe_nvm_cfgReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    xband_feset_obc_xband_fe_nvm_cfgProtocolRequestData_t *fullrequest = (xband_feset_obc_xband_fe_nvm_cfgProtocolRequestData_t *) fp_DataInfo->pu8Data;
    xband_feset_obc_xband_fe_nvm_cfgRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(xband_feset_obc_xband_fe_nvm_cfgProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (xband_feset_obc_xband_fe_nvm_cfgRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->xband_fe_set_obc_xband_fe_nvm_cfgRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->xband_fe_set_obc_xband_fe_nvm_cfgRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_status_reportReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    xband_feget_status_reportProtocolRequestData_t *fullrequest = (xband_feget_status_reportProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(xband_feget_status_reportProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->xband_fe_get_status_reportRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->xband_fe_get_status_reportRequestHandler(&requestCtx);
    }
}

static void fs_set_sys_mngr_run_modeReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    xband_feset_sys_mngr_run_modeProtocolRequestData_t *fullrequest = (xband_feset_sys_mngr_run_modeProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(xband_feset_sys_mngr_run_modeProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->xband_fe_set_sys_mngr_run_modeRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->xband_fe_set_sys_mngr_run_modeRequestHandler(&requestCtx);
    }
}

static void fs_set_sys_mngr_standby_modeReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    xband_feset_sys_mngr_standby_modeProtocolRequestData_t *fullrequest = (xband_feset_sys_mngr_standby_modeProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(xband_feset_sys_mngr_standby_modeProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->xband_fe_set_sys_mngr_standby_modeRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->xband_fe_set_sys_mngr_standby_modeRequestHandler(&requestCtx);
    }
}

static void fs_set_mod_all_paramsReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    xband_feset_mod_all_paramsProtocolRequestData_t *fullrequest = (xband_feset_mod_all_paramsProtocolRequestData_t *) fp_DataInfo->pu8Data;
    xband_feset_mod_all_paramsRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(xband_feset_mod_all_paramsProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (xband_feset_mod_all_paramsRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->xband_fe_set_mod_all_paramsRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->xband_fe_set_mod_all_paramsRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_mod_all_paramsReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    xband_feget_mod_all_paramsProtocolRequestData_t *fullrequest = (xband_feget_mod_all_paramsProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(xband_feget_mod_all_paramsProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->xband_fe_get_mod_all_paramsRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->xband_fe_get_mod_all_paramsRequestHandler(&requestCtx);
    }
}

static void fs_set_tx_powerReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    xband_feset_tx_powerProtocolRequestData_t *fullrequest = (xband_feset_tx_powerProtocolRequestData_t *) fp_DataInfo->pu8Data;
    xband_feset_tx_powerRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(xband_feset_tx_powerProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (xband_feset_tx_powerRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->xband_fe_set_tx_powerRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->xband_fe_set_tx_powerRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_tx_powerReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    xband_feget_tx_powerProtocolRequestData_t *fullrequest = (xband_feget_tx_powerProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(xband_feget_tx_powerProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->xband_fe_get_tx_powerRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->xband_fe_get_tx_powerRequestHandler(&requestCtx);
    }
}


/**********************************************************************
 *
 *  Public methods implementation
 *
 **********************************************************************/
void xband_fe_registerServerApi(xband_fe_ServerApi_t *pSrvApiHandlers)
{
    pSrvApiHnd = pSrvApiHandlers;
}

ESSA_pStack_FunctionProtocolInfo_t xband_fe_getServerProtocolDescriptor(void)
{
    return (ESSA_pStack_FunctionProtocolInfo_t) &FP_xband_feProtocolServerInfo;
}

ESSATMAC_ErrCodes xband_fe_get_obc_xband_fe_nvm_cfgResp(
                RespContext_t* ctx,
                const XBAND_FE_ObcXBandFeNvmCfg_t * const sNvm_params
)
{
#ifndef BIG_ENDIAN_PLATFORM
    xband_feget_obc_xband_fe_nvm_cfgProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(xband_feget_obc_xband_fe_nvm_cfgProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(xband_feget_obc_xband_fe_nvm_cfgProtocolResponseData_t);

    if ((ctx != NULL) && (sNvm_params != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE;
        responseParams.hdr.funcId  = XBAND_FE_GET_OBC_XBAND_FE_NVM_CFG_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        if (sNvm_params != NULL)
        {
            responseParams.data.sNvm_params = *(sNvm_params);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sNvm_params,
                          0U,
                          sizeof(responseParams.data.sNvm_params));
        }
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(xband_feget_obc_xband_fe_nvm_cfgProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes xband_fe_set_obc_xband_fe_nvm_cfgResp(
                RespContext_t* ctx,
                const bool bSuccess
)
{
#ifndef BIG_ENDIAN_PLATFORM
    xband_feset_obc_xband_fe_nvm_cfgProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(xband_feset_obc_xband_fe_nvm_cfgProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(xband_feset_obc_xband_fe_nvm_cfgProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE;
        responseParams.hdr.funcId  = XBAND_FE_SET_OBC_XBAND_FE_NVM_CFG_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.bSuccess = bSuccess;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(xband_feset_obc_xband_fe_nvm_cfgProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes xband_fe_get_status_reportResp(
                RespContext_t* ctx,
                const XBAND_FE_CommRes_t eComm_res,
                const XBAND_FE_ModStatusReportParamsWrapper_t * const sStatus_params
)
{
#ifndef BIG_ENDIAN_PLATFORM
    xband_feget_status_reportProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(xband_feget_status_reportProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(xband_feget_status_reportProtocolResponseData_t);

    if ((ctx != NULL) && (sStatus_params != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE;
        responseParams.hdr.funcId  = XBAND_FE_GET_STATUS_REPORT_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eComm_res = eComm_res;
        if (sStatus_params != NULL)
        {
            responseParams.data.sStatus_params = *(sStatus_params);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sStatus_params,
                          0U,
                          sizeof(responseParams.data.sStatus_params));
        }
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(xband_feget_status_reportProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes xband_fe_set_sys_mngr_run_modeResp(
                RespContext_t* ctx,
                const XBAND_FE_CommRes_t eComm_res,
                const XBAND_FE_StdResponseWrapper_t * const sCmd_resp
)
{
#ifndef BIG_ENDIAN_PLATFORM
    xband_feset_sys_mngr_run_modeProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(xband_feset_sys_mngr_run_modeProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(xband_feset_sys_mngr_run_modeProtocolResponseData_t);

    if ((ctx != NULL) && (sCmd_resp != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE;
        responseParams.hdr.funcId  = XBAND_FE_SET_SYS_MNGR_RUN_MODE_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eComm_res = eComm_res;
        if (sCmd_resp != NULL)
        {
            responseParams.data.sCmd_resp = *(sCmd_resp);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sCmd_resp,
                          0U,
                          sizeof(responseParams.data.sCmd_resp));
        }
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(xband_feset_sys_mngr_run_modeProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes xband_fe_set_sys_mngr_standby_modeResp(
                RespContext_t* ctx,
                const XBAND_FE_CommRes_t eComm_res,
                const XBAND_FE_StdResponseWrapper_t * const sCmd_resp
)
{
#ifndef BIG_ENDIAN_PLATFORM
    xband_feset_sys_mngr_standby_modeProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(xband_feset_sys_mngr_standby_modeProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(xband_feset_sys_mngr_standby_modeProtocolResponseData_t);

    if ((ctx != NULL) && (sCmd_resp != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE;
        responseParams.hdr.funcId  = XBAND_FE_SET_SYS_MNGR_STANDBY_MODE_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eComm_res = eComm_res;
        if (sCmd_resp != NULL)
        {
            responseParams.data.sCmd_resp = *(sCmd_resp);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sCmd_resp,
                          0U,
                          sizeof(responseParams.data.sCmd_resp));
        }
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(xband_feset_sys_mngr_standby_modeProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes xband_fe_set_mod_all_paramsResp(
                RespContext_t* ctx,
                const XBAND_FE_CommRes_t eComm_res,
                const XBAND_FE_StdResponseWrapper_t * const sCmd_resp
)
{
#ifndef BIG_ENDIAN_PLATFORM
    xband_feset_mod_all_paramsProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(xband_feset_mod_all_paramsProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(xband_feset_mod_all_paramsProtocolResponseData_t);

    if ((ctx != NULL) && (sCmd_resp != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE;
        responseParams.hdr.funcId  = XBAND_FE_SET_MOD_ALL_PARAMS_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eComm_res = eComm_res;
        if (sCmd_resp != NULL)
        {
            responseParams.data.sCmd_resp = *(sCmd_resp);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sCmd_resp,
                          0U,
                          sizeof(responseParams.data.sCmd_resp));
        }
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(xband_feset_mod_all_paramsProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes xband_fe_get_mod_all_paramsResp(
                RespContext_t* ctx,
                const XBAND_FE_CommRes_t eComm_res,
                const XBAND_FE_ModCfgParamsWrapper_t * const sCfg_params
)
{
#ifndef BIG_ENDIAN_PLATFORM
    xband_feget_mod_all_paramsProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(xband_feget_mod_all_paramsProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(xband_feget_mod_all_paramsProtocolResponseData_t);

    if ((ctx != NULL) && (sCfg_params != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE;
        responseParams.hdr.funcId  = XBAND_FE_GET_MOD_ALL_PARAMS_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eComm_res = eComm_res;
        if (sCfg_params != NULL)
        {
            responseParams.data.sCfg_params = *(sCfg_params);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sCfg_params,
                          0U,
                          sizeof(responseParams.data.sCfg_params));
        }
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(xband_feget_mod_all_paramsProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes xband_fe_set_tx_powerResp(
                RespContext_t* ctx,
                const XBAND_FE_CommRes_t eComm_res,
                const XBAND_FE_StdResponseWrapper_t * const sCmd_resp
)
{
#ifndef BIG_ENDIAN_PLATFORM
    xband_feset_tx_powerProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(xband_feset_tx_powerProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(xband_feset_tx_powerProtocolResponseData_t);

    if ((ctx != NULL) && (sCmd_resp != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE;
        responseParams.hdr.funcId  = XBAND_FE_SET_TX_POWER_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eComm_res = eComm_res;
        if (sCmd_resp != NULL)
        {
            responseParams.data.sCmd_resp = *(sCmd_resp);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sCmd_resp,
                          0U,
                          sizeof(responseParams.data.sCmd_resp));
        }
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(xband_feset_tx_powerProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes xband_fe_get_tx_powerResp(
                RespContext_t* ctx,
                const XBAND_FE_CommRes_t eComm_res,
                const XBAND_FE_XBandFeTxPowerInfoWrapper_t * const sTx_power_info
)
{
#ifndef BIG_ENDIAN_PLATFORM
    xband_feget_tx_powerProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(xband_feget_tx_powerProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(xband_feget_tx_powerProtocolResponseData_t);

    if ((ctx != NULL) && (sTx_power_info != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE;
        responseParams.hdr.funcId  = XBAND_FE_GET_TX_POWER_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eComm_res = eComm_res;
        if (sTx_power_info != NULL)
        {
            responseParams.data.sTx_power_info = *(sTx_power_info);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sTx_power_info,
                          0U,
                          sizeof(responseParams.data.sTx_power_info));
        }
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(xband_feget_tx_powerProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}


