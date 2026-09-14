/*!
********************************************************************************************
* @file FP_trace_level_configProtocolServer.c
* @brief ESSA Stack server-side implementation
********************************************************************************************
* @version           interface trace_level_config v0.1
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

#include "FP_trace_level_configProtocolServer.h"
#include "FP_common/FP_ProtocolServerCommon.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Local type definitions
 *
 **********************************************************************/
typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    trace_level_configset_channel_trace_levelRequestData_t data;
} PACKED_STRUCT trace_level_configset_channel_trace_levelProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    trace_level_configset_channel_trace_levelResponseData_t data;
} PACKED_STRUCT trace_level_configset_channel_trace_levelProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT trace_level_configget_channel_infoProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    trace_level_configget_channel_infoResponseData_t data;
} PACKED_STRUCT trace_level_configget_channel_infoProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    trace_level_configset_channel_active_statusRequestData_t data;
} PACKED_STRUCT trace_level_configset_channel_active_statusProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    trace_level_configset_channel_active_statusResponseData_t data;
} PACKED_STRUCT trace_level_configset_channel_active_statusProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    trace_level_configset_module_active_statusRequestData_t data;
} PACKED_STRUCT trace_level_configset_module_active_statusProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    trace_level_configset_module_active_statusResponseData_t data;
} PACKED_STRUCT trace_level_configset_module_active_statusProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    trace_level_configset_module_trace_levelRequestData_t data;
} PACKED_STRUCT trace_level_configset_module_trace_levelProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    trace_level_configset_module_trace_levelResponseData_t data;
} PACKED_STRUCT trace_level_configset_module_trace_levelProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    trace_level_configget_module_infoRequestData_t data;
} PACKED_STRUCT trace_level_configget_module_infoProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    trace_level_configget_module_infoResponseData_t data;
} PACKED_STRUCT trace_level_configget_module_infoProtocolResponseData_t;


/**********************************************************************
 *
 *  Static methods declarations
 *
 **********************************************************************/
static bool fs_HandleData(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_channel_trace_levelReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_channel_infoReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_channel_active_statusReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_module_active_statusReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_module_trace_levelReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_module_infoReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);

/**********************************************************************
 *
 *  Public variable definitions
 *
 **********************************************************************/
const ESSA_Stack_FunctionProtocolInfo_t FP_trace_level_configProtocolServerInfo = {
    .u16ProtocolId    = ES_SAT_FUNC_PROTOCOL_ID_TRACE_LEVEL_CONFIG,
        .pfDataHandlerCbk = &fs_HandleData
};

/**********************************************************************
 *
 *  Static variable definitions
 *
 **********************************************************************/
static trace_level_config_ServerApi_t *pSrvApiHnd = NULL;

static const ProtocolFuncArrayEntry_t fs_aFuncArray[] = {
    { TRACE_LEVEL_CONFIG_SET_CHANNEL_TRACE_LEVEL_FUNC_ID, fs_set_channel_trace_levelReq },
    { TRACE_LEVEL_CONFIG_GET_CHANNEL_INFO_FUNC_ID, fs_get_channel_infoReq },
    { TRACE_LEVEL_CONFIG_SET_CHANNEL_ACTIVE_STATUS_FUNC_ID, fs_set_channel_active_statusReq },
    { TRACE_LEVEL_CONFIG_SET_MODULE_ACTIVE_STATUS_FUNC_ID, fs_set_module_active_statusReq },
    { TRACE_LEVEL_CONFIG_SET_MODULE_TRACE_LEVEL_FUNC_ID, fs_set_module_trace_levelReq },
    { TRACE_LEVEL_CONFIG_GET_MODULE_INFO_FUNC_ID, fs_get_module_infoReq }
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







static void fs_set_channel_trace_levelReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    trace_level_configset_channel_trace_levelProtocolRequestData_t *fullrequest = (trace_level_configset_channel_trace_levelProtocolRequestData_t *) fp_DataInfo->pu8Data;
    trace_level_configset_channel_trace_levelRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(trace_level_configset_channel_trace_levelProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (trace_level_configset_channel_trace_levelRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->trace_level_config_set_channel_trace_levelRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->trace_level_config_set_channel_trace_levelRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_channel_infoReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    trace_level_configget_channel_infoProtocolRequestData_t *fullrequest = (trace_level_configget_channel_infoProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(trace_level_configget_channel_infoProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->trace_level_config_get_channel_infoRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->trace_level_config_get_channel_infoRequestHandler(&requestCtx);
    }
}

static void fs_set_channel_active_statusReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    trace_level_configset_channel_active_statusProtocolRequestData_t *fullrequest = (trace_level_configset_channel_active_statusProtocolRequestData_t *) fp_DataInfo->pu8Data;
    trace_level_configset_channel_active_statusRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(trace_level_configset_channel_active_statusProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (trace_level_configset_channel_active_statusRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->trace_level_config_set_channel_active_statusRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->trace_level_config_set_channel_active_statusRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_set_module_active_statusReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    trace_level_configset_module_active_statusProtocolRequestData_t *fullrequest = (trace_level_configset_module_active_statusProtocolRequestData_t *) fp_DataInfo->pu8Data;
    trace_level_configset_module_active_statusRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(trace_level_configset_module_active_statusProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (trace_level_configset_module_active_statusRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->trace_level_config_set_module_active_statusRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->trace_level_config_set_module_active_statusRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_set_module_trace_levelReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    trace_level_configset_module_trace_levelProtocolRequestData_t *fullrequest = (trace_level_configset_module_trace_levelProtocolRequestData_t *) fp_DataInfo->pu8Data;
    trace_level_configset_module_trace_levelRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(trace_level_configset_module_trace_levelProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (trace_level_configset_module_trace_levelRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->trace_level_config_set_module_trace_levelRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->trace_level_config_set_module_trace_levelRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_module_infoReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    trace_level_configget_module_infoProtocolRequestData_t *fullrequest = (trace_level_configget_module_infoProtocolRequestData_t *) fp_DataInfo->pu8Data;
    trace_level_configget_module_infoRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(trace_level_configget_module_infoProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (trace_level_configget_module_infoRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->trace_level_config_get_module_infoRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->trace_level_config_get_module_infoRequestHandler(&requestCtx,
                                        requestPayload);
    }
}


/**********************************************************************
 *
 *  Public methods implementation
 *
 **********************************************************************/
void trace_level_config_registerServerApi(trace_level_config_ServerApi_t *pSrvApiHandlers)
{
    pSrvApiHnd = pSrvApiHandlers;
}

ESSA_pStack_FunctionProtocolInfo_t trace_level_config_getServerProtocolDescriptor(void)
{
    return (ESSA_pStack_FunctionProtocolInfo_t) &FP_trace_level_configProtocolServerInfo;
}

ESSATMAC_ErrCodes trace_level_config_set_channel_trace_levelResp(
                RespContext_t* ctx,
                const TRACE_LEVEL_CONFIG_Result_t eRes
)
{
#ifndef BIG_ENDIAN_PLATFORM
    trace_level_configset_channel_trace_levelProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(trace_level_configset_channel_trace_levelProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(trace_level_configset_channel_trace_levelProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TRACE_LEVEL_CONFIG;
        responseParams.hdr.funcId  = TRACE_LEVEL_CONFIG_SET_CHANNEL_TRACE_LEVEL_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eRes = eRes;
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
                                            sizeof(trace_level_configset_channel_trace_levelProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes trace_level_config_get_channel_infoResp(
                RespContext_t* ctx,
                const TRACE_LEVEL_CONFIG_ChannelInfo_t * const asChannels,
                const TRACE_LEVEL_CONFIG_Result_t eRes
)
{
#ifndef BIG_ENDIAN_PLATFORM
    trace_level_configget_channel_infoProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(trace_level_configget_channel_infoProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(trace_level_configget_channel_infoProtocolResponseData_t);

    if ((ctx != NULL) && (asChannels != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TRACE_LEVEL_CONFIG;
        responseParams.hdr.funcId  = TRACE_LEVEL_CONFIG_GET_CHANNEL_INFO_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        if (asChannels != NULL)
        {
            (void) memcpy((void *) &responseParams.data.asChannels,
                          (const void *) asChannels,
                          sizeof(responseParams.data.asChannels));
        }
        else
        {
            (void) memset((void *) &responseParams.data.asChannels,
                          0U,
                          sizeof(responseParams.data.asChannels));
        }
        responseParams.data.eRes = eRes;
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
                                            sizeof(trace_level_configget_channel_infoProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes trace_level_config_set_channel_active_statusResp(
                RespContext_t* ctx,
                const TRACE_LEVEL_CONFIG_Result_t eRes
)
{
#ifndef BIG_ENDIAN_PLATFORM
    trace_level_configset_channel_active_statusProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(trace_level_configset_channel_active_statusProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(trace_level_configset_channel_active_statusProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TRACE_LEVEL_CONFIG;
        responseParams.hdr.funcId  = TRACE_LEVEL_CONFIG_SET_CHANNEL_ACTIVE_STATUS_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eRes = eRes;
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
                                            sizeof(trace_level_configset_channel_active_statusProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes trace_level_config_set_module_active_statusResp(
                RespContext_t* ctx,
                const TRACE_LEVEL_CONFIG_Result_t eRes
)
{
#ifndef BIG_ENDIAN_PLATFORM
    trace_level_configset_module_active_statusProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(trace_level_configset_module_active_statusProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(trace_level_configset_module_active_statusProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TRACE_LEVEL_CONFIG;
        responseParams.hdr.funcId  = TRACE_LEVEL_CONFIG_SET_MODULE_ACTIVE_STATUS_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eRes = eRes;
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
                                            sizeof(trace_level_configset_module_active_statusProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes trace_level_config_set_module_trace_levelResp(
                RespContext_t* ctx,
                const TRACE_LEVEL_CONFIG_Result_t eRes
)
{
#ifndef BIG_ENDIAN_PLATFORM
    trace_level_configset_module_trace_levelProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(trace_level_configset_module_trace_levelProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(trace_level_configset_module_trace_levelProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TRACE_LEVEL_CONFIG;
        responseParams.hdr.funcId  = TRACE_LEVEL_CONFIG_SET_MODULE_TRACE_LEVEL_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eRes = eRes;
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
                                            sizeof(trace_level_configset_module_trace_levelProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes trace_level_config_get_module_infoResp(
                RespContext_t* ctx,
                const TRACE_LEVEL_CONFIG_ModuleInfo_t * const sModule_output,
                const TRACE_LEVEL_CONFIG_Result_t eRes
)
{
#ifndef BIG_ENDIAN_PLATFORM
    trace_level_configget_module_infoProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(trace_level_configget_module_infoProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(trace_level_configget_module_infoProtocolResponseData_t);

    if ((ctx != NULL) && (sModule_output != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TRACE_LEVEL_CONFIG;
        responseParams.hdr.funcId  = TRACE_LEVEL_CONFIG_GET_MODULE_INFO_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        if (sModule_output != NULL)
        {
            responseParams.data.sModule_output = *(sModule_output);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sModule_output,
                          0U,
                          sizeof(responseParams.data.sModule_output));
        }
        responseParams.data.eRes = eRes;
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
                                            sizeof(trace_level_configget_module_infoProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}


