/*!
********************************************************************************************
* @file FP_eps_iii_expanderProtocolClient.c
* @brief ESSA Stack client-side implementation
********************************************************************************************
* @version           interface eps_iii_expander v2.0
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

#include "FP_eps_iii_expanderProtocolClient.h"
    #include "FP_common/FP_Helpers.h"
#define eps_iii_expander_PROTOCOL_VERSION_MAJOR   ((uint8_t) 2)
#define eps_iii_expander_PROTOCOL_VERSION_MINOR   ((uint8_t) 0)

/**********************************************************************
 *
 *  Local type definitions
 *
 **********************************************************************/
typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT eps_iii_expanderget_telemetryProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    eps_iii_expanderget_telemetryResponseData_t data;
} PACKED_STRUCT eps_iii_expanderget_telemetryProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    eps_iii_expanderh1_channels_controlRequestData_t data;
} PACKED_STRUCT eps_iii_expanderh1_channels_controlProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    eps_iii_expanderh1_channels_controlResponseData_t data;
} PACKED_STRUCT eps_iii_expanderh1_channels_controlProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    eps_iii_expandergpio_controlRequestData_t data;
} PACKED_STRUCT eps_iii_expandergpio_controlProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    eps_iii_expandergpio_controlResponseData_t data;
} PACKED_STRUCT eps_iii_expandergpio_controlProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    eps_iii_expanderinterconnect_controlRequestData_t data;
} PACKED_STRUCT eps_iii_expanderinterconnect_controlProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    eps_iii_expanderinterconnect_controlResponseData_t data;
} PACKED_STRUCT eps_iii_expanderinterconnect_controlProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    eps_iii_expanderrelease_5vRequestData_t data;
} PACKED_STRUCT eps_iii_expanderrelease_5vProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    eps_iii_expanderrelease_5vResponseData_t data;
} PACKED_STRUCT eps_iii_expanderrelease_5vProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    eps_iii_expanderrelease_controlRequestData_t data;
} PACKED_STRUCT eps_iii_expanderrelease_controlProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    eps_iii_expanderrelease_controlResponseData_t data;
} PACKED_STRUCT eps_iii_expanderrelease_controlProtocolResponseData_t;


/**********************************************************************
 *
 *  Static methods declarations
 *
 **********************************************************************/
static bool fs_HandleData(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_telemetryResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_h1_channels_controlResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_gpio_controlResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_interconnect_controlResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_release_5vResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_release_controlResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);

/**********************************************************************
 *
 *  Public variable definitions
 *
 **********************************************************************/
const ESSA_Stack_FunctionProtocolInfo_t FP_eps_iii_expanderProtocolClientInfo = {
    .u16ProtocolId    = ES_SAT_FUNC_PROTOCOL_ID_EPS_III_EXPANDER,
        .pfDataHandlerCbk = &fs_HandleData
};

/**********************************************************************
 *
 *  Static variable definitions
 *
 **********************************************************************/
static eps_iii_expander_ClientApi_t *pCliApiHnd = NULL;

static const ProtocolFuncArrayEntry_t fs_aFuncArray[] = {
    { EPS_III_EXPANDER_GET_TELEMETRY_FUNCRESP_ID, fs_get_telemetryResp },
    { EPS_III_EXPANDER_H1_CHANNELS_CONTROL_FUNCRESP_ID, fs_h1_channels_controlResp },
    { EPS_III_EXPANDER_GPIO_CONTROL_FUNCRESP_ID, fs_gpio_controlResp },
    { EPS_III_EXPANDER_INTERCONNECT_CONTROL_FUNCRESP_ID, fs_interconnect_controlResp },
    { EPS_III_EXPANDER_RELEASE_5V_FUNCRESP_ID, fs_release_5vResp },
    { EPS_III_EXPANDER_RELEASE_CONTROL_FUNCRESP_ID, fs_release_controlResp }
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


static void fs_get_telemetryResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    eps_iii_expanderget_telemetryProtocolResponseData_t *fullresponse = (eps_iii_expanderget_telemetryProtocolResponseData_t *) fp_DataInfo->pu8Data;
    eps_iii_expanderget_telemetryResponseData_t *responsePayload = NULL;
    RespContext_t responseCtx;

    STATIC_ASSERT_SIZE_CHECK(eps_iii_expanderget_telemetryProtocolResponseData_t);

    if ((fullresponse == NULL) || (pCliApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullresponse)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    responsePayload = (eps_iii_expanderget_telemetryResponseData_t *) &fullresponse->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pCliApiHnd->eps_iii_expander_get_telemetryResponseHandler != NULL)
    {
        responseCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        responseCtx.netType = fp_DataInfo->pMACContext->netType;
        responseCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        responseCtx.seqId = fullresponse->hdr.seqId;

        pCliApiHnd->eps_iii_expander_get_telemetryResponseHandler(&responseCtx,
                                        ((fullresponse->hdr).errCode != ESSA_FP_ERRCODE_NOERROR) ? (NULL) : (responsePayload));
    }
}

static void fs_h1_channels_controlResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    eps_iii_expanderh1_channels_controlProtocolResponseData_t *fullresponse = (eps_iii_expanderh1_channels_controlProtocolResponseData_t *) fp_DataInfo->pu8Data;
    eps_iii_expanderh1_channels_controlResponseData_t *responsePayload = NULL;
    RespContext_t responseCtx;

    STATIC_ASSERT_SIZE_CHECK(eps_iii_expanderh1_channels_controlProtocolResponseData_t);

    if ((fullresponse == NULL) || (pCliApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullresponse)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    responsePayload = (eps_iii_expanderh1_channels_controlResponseData_t *) &fullresponse->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pCliApiHnd->eps_iii_expander_h1_channels_controlResponseHandler != NULL)
    {
        responseCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        responseCtx.netType = fp_DataInfo->pMACContext->netType;
        responseCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        responseCtx.seqId = fullresponse->hdr.seqId;

        pCliApiHnd->eps_iii_expander_h1_channels_controlResponseHandler(&responseCtx,
                                        ((fullresponse->hdr).errCode != ESSA_FP_ERRCODE_NOERROR) ? (NULL) : (responsePayload));
    }
}

static void fs_gpio_controlResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    eps_iii_expandergpio_controlProtocolResponseData_t *fullresponse = (eps_iii_expandergpio_controlProtocolResponseData_t *) fp_DataInfo->pu8Data;
    eps_iii_expandergpio_controlResponseData_t *responsePayload = NULL;
    RespContext_t responseCtx;

    STATIC_ASSERT_SIZE_CHECK(eps_iii_expandergpio_controlProtocolResponseData_t);

    if ((fullresponse == NULL) || (pCliApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullresponse)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    responsePayload = (eps_iii_expandergpio_controlResponseData_t *) &fullresponse->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pCliApiHnd->eps_iii_expander_gpio_controlResponseHandler != NULL)
    {
        responseCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        responseCtx.netType = fp_DataInfo->pMACContext->netType;
        responseCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        responseCtx.seqId = fullresponse->hdr.seqId;

        pCliApiHnd->eps_iii_expander_gpio_controlResponseHandler(&responseCtx,
                                        ((fullresponse->hdr).errCode != ESSA_FP_ERRCODE_NOERROR) ? (NULL) : (responsePayload));
    }
}

static void fs_interconnect_controlResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    eps_iii_expanderinterconnect_controlProtocolResponseData_t *fullresponse = (eps_iii_expanderinterconnect_controlProtocolResponseData_t *) fp_DataInfo->pu8Data;
    eps_iii_expanderinterconnect_controlResponseData_t *responsePayload = NULL;
    RespContext_t responseCtx;

    STATIC_ASSERT_SIZE_CHECK(eps_iii_expanderinterconnect_controlProtocolResponseData_t);

    if ((fullresponse == NULL) || (pCliApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullresponse)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    responsePayload = (eps_iii_expanderinterconnect_controlResponseData_t *) &fullresponse->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pCliApiHnd->eps_iii_expander_interconnect_controlResponseHandler != NULL)
    {
        responseCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        responseCtx.netType = fp_DataInfo->pMACContext->netType;
        responseCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        responseCtx.seqId = fullresponse->hdr.seqId;

        pCliApiHnd->eps_iii_expander_interconnect_controlResponseHandler(&responseCtx,
                                        ((fullresponse->hdr).errCode != ESSA_FP_ERRCODE_NOERROR) ? (NULL) : (responsePayload));
    }
}

static void fs_release_5vResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    eps_iii_expanderrelease_5vProtocolResponseData_t *fullresponse = (eps_iii_expanderrelease_5vProtocolResponseData_t *) fp_DataInfo->pu8Data;
    eps_iii_expanderrelease_5vResponseData_t *responsePayload = NULL;
    RespContext_t responseCtx;

    STATIC_ASSERT_SIZE_CHECK(eps_iii_expanderrelease_5vProtocolResponseData_t);

    if ((fullresponse == NULL) || (pCliApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullresponse)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    responsePayload = (eps_iii_expanderrelease_5vResponseData_t *) &fullresponse->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pCliApiHnd->eps_iii_expander_release_5vResponseHandler != NULL)
    {
        responseCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        responseCtx.netType = fp_DataInfo->pMACContext->netType;
        responseCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        responseCtx.seqId = fullresponse->hdr.seqId;

        pCliApiHnd->eps_iii_expander_release_5vResponseHandler(&responseCtx,
                                        ((fullresponse->hdr).errCode != ESSA_FP_ERRCODE_NOERROR) ? (NULL) : (responsePayload));
    }
}

static void fs_release_controlResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    eps_iii_expanderrelease_controlProtocolResponseData_t *fullresponse = (eps_iii_expanderrelease_controlProtocolResponseData_t *) fp_DataInfo->pu8Data;
    eps_iii_expanderrelease_controlResponseData_t *responsePayload = NULL;
    RespContext_t responseCtx;

    STATIC_ASSERT_SIZE_CHECK(eps_iii_expanderrelease_controlProtocolResponseData_t);

    if ((fullresponse == NULL) || (pCliApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullresponse)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    responsePayload = (eps_iii_expanderrelease_controlResponseData_t *) &fullresponse->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pCliApiHnd->eps_iii_expander_release_controlResponseHandler != NULL)
    {
        responseCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        responseCtx.netType = fp_DataInfo->pMACContext->netType;
        responseCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        responseCtx.seqId = fullresponse->hdr.seqId;

        pCliApiHnd->eps_iii_expander_release_controlResponseHandler(&responseCtx,
                                        ((fullresponse->hdr).errCode != ESSA_FP_ERRCODE_NOERROR) ? (NULL) : (responsePayload));
    }
}


/**********************************************************************
 *
 *  Public methods implementation
 *
 **********************************************************************/
void eps_iii_expander_registerClientApi(eps_iii_expander_ClientApi_t *pCliApiHandlers)
{
    pCliApiHnd = pCliApiHandlers;
}

ESSA_pStack_FunctionProtocolInfo_t eps_iii_expander_getClientProtocolDescriptor(void)
{
    return (ESSA_pStack_FunctionProtocolInfo_t) &FP_eps_iii_expanderProtocolClientInfo;
}

ESSATMAC_ErrCodes eps_iii_expander_get_telemetryReq(
                ReqContext_t* ctx)
{
#ifndef BIG_ENDIAN_PLATFORM
    eps_iii_expanderget_telemetryProtocolRequestData_t requestParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t requestParams[sizeof(eps_iii_expanderget_telemetryProtocolRequestData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(eps_iii_expanderget_telemetryProtocolRequestData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        requestParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_EPS_III_EXPANDER;
        requestParams.hdr.funcId  = EPS_III_EXPANDER_GET_TELEMETRY_FUNC_ID;
        requestParams.hdr.seqId   = FP_Helpers_GenMsgId();
        requestParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_REQUEST(requestParams.hdr);
        // Make seqId available to sender 
        ctx->seqId = requestParams.hdr.seqId;

#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &requestParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) requestParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(eps_iii_expanderget_telemetryProtocolRequestData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes eps_iii_expander_h1_channels_controlReq(
                ReqContext_t* ctx,
                const EPS_III_EXPANDER_HLVChannelId_t eH1_channel,
                const EPS_III_EXPANDER_ChannelOpt_t eH1_option,
                const uint16_t u16H1_time
)
{
#ifndef BIG_ENDIAN_PLATFORM
    eps_iii_expanderh1_channels_controlProtocolRequestData_t requestParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t requestParams[sizeof(eps_iii_expanderh1_channels_controlProtocolRequestData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(eps_iii_expanderh1_channels_controlProtocolRequestData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        requestParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_EPS_III_EXPANDER;
        requestParams.hdr.funcId  = EPS_III_EXPANDER_H1_CHANNELS_CONTROL_FUNC_ID;
        requestParams.hdr.seqId   = FP_Helpers_GenMsgId();
        requestParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_REQUEST(requestParams.hdr);
        // Make seqId available to sender 
        ctx->seqId = requestParams.hdr.seqId;

        // fill message data
        requestParams.data.eH1_channel = eH1_channel;
        requestParams.data.eH1_option = eH1_option;
        requestParams.data.u16H1_time = u16H1_time;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &requestParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) requestParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(eps_iii_expanderh1_channels_controlProtocolRequestData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes eps_iii_expander_gpio_controlReq(
                ReqContext_t* ctx,
                const EPS_III_EXPANDER_GPIOChannelId_t eGo_channel,
                const EPS_III_EXPANDER_ChannelOpt_t eGo_option,
                const uint16_t u16Go_time
)
{
#ifndef BIG_ENDIAN_PLATFORM
    eps_iii_expandergpio_controlProtocolRequestData_t requestParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t requestParams[sizeof(eps_iii_expandergpio_controlProtocolRequestData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(eps_iii_expandergpio_controlProtocolRequestData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        requestParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_EPS_III_EXPANDER;
        requestParams.hdr.funcId  = EPS_III_EXPANDER_GPIO_CONTROL_FUNC_ID;
        requestParams.hdr.seqId   = FP_Helpers_GenMsgId();
        requestParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_REQUEST(requestParams.hdr);
        // Make seqId available to sender 
        ctx->seqId = requestParams.hdr.seqId;

        // fill message data
        requestParams.data.eGo_channel = eGo_channel;
        requestParams.data.eGo_option = eGo_option;
        requestParams.data.u16Go_time = u16Go_time;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &requestParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) requestParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(eps_iii_expandergpio_controlProtocolRequestData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes eps_iii_expander_interconnect_controlReq(
                ReqContext_t* ctx,
                const EPS_III_EXPANDER_IntercChannelId_t eIc_channel,
                const EPS_III_EXPANDER_ChannelOpt_t eIc_option,
                const uint16_t u16Ic_time
)
{
#ifndef BIG_ENDIAN_PLATFORM
    eps_iii_expanderinterconnect_controlProtocolRequestData_t requestParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t requestParams[sizeof(eps_iii_expanderinterconnect_controlProtocolRequestData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(eps_iii_expanderinterconnect_controlProtocolRequestData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        requestParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_EPS_III_EXPANDER;
        requestParams.hdr.funcId  = EPS_III_EXPANDER_INTERCONNECT_CONTROL_FUNC_ID;
        requestParams.hdr.seqId   = FP_Helpers_GenMsgId();
        requestParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_REQUEST(requestParams.hdr);
        // Make seqId available to sender 
        ctx->seqId = requestParams.hdr.seqId;

        // fill message data
        requestParams.data.eIc_channel = eIc_channel;
        requestParams.data.eIc_option = eIc_option;
        requestParams.data.u16Ic_time = u16Ic_time;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &requestParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) requestParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(eps_iii_expanderinterconnect_controlProtocolRequestData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes eps_iii_expander_release_5vReq(
                ReqContext_t* ctx,
                const EPS_III_EXPANDER_R5VChannelId_t eRl_5v_channel,
                const EPS_III_EXPANDER_ChannelOpt_t eRl_5v_option,
                const uint16_t u16Rl_5v_time
)
{
#ifndef BIG_ENDIAN_PLATFORM
    eps_iii_expanderrelease_5vProtocolRequestData_t requestParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t requestParams[sizeof(eps_iii_expanderrelease_5vProtocolRequestData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(eps_iii_expanderrelease_5vProtocolRequestData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        requestParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_EPS_III_EXPANDER;
        requestParams.hdr.funcId  = EPS_III_EXPANDER_RELEASE_5V_FUNC_ID;
        requestParams.hdr.seqId   = FP_Helpers_GenMsgId();
        requestParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_REQUEST(requestParams.hdr);
        // Make seqId available to sender 
        ctx->seqId = requestParams.hdr.seqId;

        // fill message data
        requestParams.data.eRl_5v_channel = eRl_5v_channel;
        requestParams.data.eRl_5v_option = eRl_5v_option;
        requestParams.data.u16Rl_5v_time = u16Rl_5v_time;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &requestParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) requestParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(eps_iii_expanderrelease_5vProtocolRequestData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes eps_iii_expander_release_controlReq(
                ReqContext_t* ctx,
                const EPS_III_EXPANDER_RChannelId_t eRl_channel,
                const EPS_III_EXPANDER_RChannelOpt_t eRl_option,
                const uint16_t u16Rl_time
)
{
#ifndef BIG_ENDIAN_PLATFORM
    eps_iii_expanderrelease_controlProtocolRequestData_t requestParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t requestParams[sizeof(eps_iii_expanderrelease_controlProtocolRequestData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(eps_iii_expanderrelease_controlProtocolRequestData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        requestParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_EPS_III_EXPANDER;
        requestParams.hdr.funcId  = EPS_III_EXPANDER_RELEASE_CONTROL_FUNC_ID;
        requestParams.hdr.seqId   = FP_Helpers_GenMsgId();
        requestParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_REQUEST(requestParams.hdr);
        // Make seqId available to sender 
        ctx->seqId = requestParams.hdr.seqId;

        // fill message data
        requestParams.data.eRl_channel = eRl_channel;
        requestParams.data.eRl_option = eRl_option;
        requestParams.data.u16Rl_time = u16Rl_time;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &requestParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) requestParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(eps_iii_expanderrelease_controlProtocolRequestData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}


