/*!
********************************************************************************************
* @file FP_EPSII_PDM_1ProtocolClient.c
* @brief ESSA Stack client-side implementation
********************************************************************************************
* @version           interface EPSII_PDM_1 v1.0
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

#include "FP_EPSII_PDM_1ProtocolClient.h"
    #include "FP_common/FP_Helpers.h"
#define EPSII_PDM_1_PROTOCOL_VERSION_MAJOR   ((uint8_t) 1)
#define EPSII_PDM_1_PROTOCOL_VERSION_MINOR   ((uint8_t) 0)

/**********************************************************************
 *
 *  Local type definitions
 *
 **********************************************************************/
typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT EPSII_PDM_1GetPowerDistributionInfoProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    EPSII_PDM_1GetPowerDistributionInfoResponseData_t data;
} PACKED_STRUCT EPSII_PDM_1GetPowerDistributionInfoProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT EPSII_PDM_1GetDeviceHealthInfoProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    EPSII_PDM_1GetDeviceHealthInfoResponseData_t data;
} PACKED_STRUCT EPSII_PDM_1GetDeviceHealthInfoProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    EPSII_PDM_1SetPC104GPIORequestData_t data;
} PACKED_STRUCT EPSII_PDM_1SetPC104GPIOProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    EPSII_PDM_1SetPC104GPIOResponseData_t data;
} PACKED_STRUCT EPSII_PDM_1SetPC104GPIOProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT EPSII_PDM_1GetPC104GPIOProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    EPSII_PDM_1GetPC104GPIOResponseData_t data;
} PACKED_STRUCT EPSII_PDM_1GetPC104GPIOProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    EPSII_PDM_1GetRAWSensorsRequestData_t data;
} PACKED_STRUCT EPSII_PDM_1GetRAWSensorsProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    EPSII_PDM_1GetRAWSensorsResponseData_t data;
} PACKED_STRUCT EPSII_PDM_1GetRAWSensorsProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    EPSII_PDM_1SetPowerOutputsRequestData_t data;
} PACKED_STRUCT EPSII_PDM_1SetPowerOutputsProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    EPSII_PDM_1SetPowerOutputsResponseData_t data;
} PACKED_STRUCT EPSII_PDM_1SetPowerOutputsProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT EPSII_PDM_1GetPowerOutputsProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    EPSII_PDM_1GetPowerOutputsResponseData_t data;
} PACKED_STRUCT EPSII_PDM_1GetPowerOutputsProtocolResponseData_t;


/**********************************************************************
 *
 *  Static methods declarations
 *
 **********************************************************************/
static bool fs_HandleData(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_GetPowerDistributionInfoResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_GetDeviceHealthInfoResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_SetPC104GPIOResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_GetPC104GPIOResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_GetRAWSensorsResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_SetPowerOutputsResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_GetPowerOutputsResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);

/**********************************************************************
 *
 *  Public variable definitions
 *
 **********************************************************************/
const ESSA_Stack_FunctionProtocolInfo_t FP_EPSII_PDM_1ProtocolClientInfo = {
    .u16ProtocolId    = ES_SAT_FUNC_PROTOCOL_ID_EPSII_PDM_1,
        .pfDataHandlerCbk = &fs_HandleData
};

/**********************************************************************
 *
 *  Static variable definitions
 *
 **********************************************************************/
static EPSII_PDM_1_ClientApi_t *pCliApiHnd = NULL;

static const ProtocolFuncArrayEntry_t fs_aFuncArray[] = {
    { EPSII_PDM_1_GETPOWERDISTRIBUTIONINFO_FUNCRESP_ID, fs_GetPowerDistributionInfoResp },
    { EPSII_PDM_1_GETDEVICEHEALTHINFO_FUNCRESP_ID, fs_GetDeviceHealthInfoResp },
    { EPSII_PDM_1_SETPC104GPIO_FUNCRESP_ID, fs_SetPC104GPIOResp },
    { EPSII_PDM_1_GETPC104GPIO_FUNCRESP_ID, fs_GetPC104GPIOResp },
    { EPSII_PDM_1_GETRAWSENSORS_FUNCRESP_ID, fs_GetRAWSensorsResp },
    { EPSII_PDM_1_SETPOWEROUTPUTS_FUNCRESP_ID, fs_SetPowerOutputsResp },
    { EPSII_PDM_1_GETPOWEROUTPUTS_FUNCRESP_ID, fs_GetPowerOutputsResp }
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


static void fs_GetPowerDistributionInfoResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    EPSII_PDM_1GetPowerDistributionInfoProtocolResponseData_t *fullresponse = (EPSII_PDM_1GetPowerDistributionInfoProtocolResponseData_t *) fp_DataInfo->pu8Data;
    EPSII_PDM_1GetPowerDistributionInfoResponseData_t *responsePayload = NULL;
    RespContext_t responseCtx;

    STATIC_ASSERT_SIZE_CHECK(EPSII_PDM_1GetPowerDistributionInfoProtocolResponseData_t);

    if ((fullresponse == NULL) || (pCliApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullresponse)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    responsePayload = (EPSII_PDM_1GetPowerDistributionInfoResponseData_t *) &fullresponse->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pCliApiHnd->EPSII_PDM_1_GetPowerDistributionInfoResponseHandler != NULL)
    {
        responseCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        responseCtx.netType = fp_DataInfo->pMACContext->netType;
        responseCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        responseCtx.seqId = fullresponse->hdr.seqId;

        pCliApiHnd->EPSII_PDM_1_GetPowerDistributionInfoResponseHandler(&responseCtx,
                                        ((fullresponse->hdr).errCode != ESSA_FP_ERRCODE_NOERROR) ? (NULL) : (responsePayload));
    }
}

static void fs_GetDeviceHealthInfoResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    EPSII_PDM_1GetDeviceHealthInfoProtocolResponseData_t *fullresponse = (EPSII_PDM_1GetDeviceHealthInfoProtocolResponseData_t *) fp_DataInfo->pu8Data;
    EPSII_PDM_1GetDeviceHealthInfoResponseData_t *responsePayload = NULL;
    RespContext_t responseCtx;

    STATIC_ASSERT_SIZE_CHECK(EPSII_PDM_1GetDeviceHealthInfoProtocolResponseData_t);

    if ((fullresponse == NULL) || (pCliApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullresponse)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    responsePayload = (EPSII_PDM_1GetDeviceHealthInfoResponseData_t *) &fullresponse->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pCliApiHnd->EPSII_PDM_1_GetDeviceHealthInfoResponseHandler != NULL)
    {
        responseCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        responseCtx.netType = fp_DataInfo->pMACContext->netType;
        responseCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        responseCtx.seqId = fullresponse->hdr.seqId;

        pCliApiHnd->EPSII_PDM_1_GetDeviceHealthInfoResponseHandler(&responseCtx,
                                        ((fullresponse->hdr).errCode != ESSA_FP_ERRCODE_NOERROR) ? (NULL) : (responsePayload));
    }
}

static void fs_SetPC104GPIOResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    EPSII_PDM_1SetPC104GPIOProtocolResponseData_t *fullresponse = (EPSII_PDM_1SetPC104GPIOProtocolResponseData_t *) fp_DataInfo->pu8Data;
    EPSII_PDM_1SetPC104GPIOResponseData_t *responsePayload = NULL;
    RespContext_t responseCtx;

    STATIC_ASSERT_SIZE_CHECK(EPSII_PDM_1SetPC104GPIOProtocolResponseData_t);

    if ((fullresponse == NULL) || (pCliApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullresponse)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    responsePayload = (EPSII_PDM_1SetPC104GPIOResponseData_t *) &fullresponse->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pCliApiHnd->EPSII_PDM_1_SetPC104GPIOResponseHandler != NULL)
    {
        responseCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        responseCtx.netType = fp_DataInfo->pMACContext->netType;
        responseCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        responseCtx.seqId = fullresponse->hdr.seqId;

        pCliApiHnd->EPSII_PDM_1_SetPC104GPIOResponseHandler(&responseCtx,
                                        ((fullresponse->hdr).errCode != ESSA_FP_ERRCODE_NOERROR) ? (NULL) : (responsePayload));
    }
}

static void fs_GetPC104GPIOResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    EPSII_PDM_1GetPC104GPIOProtocolResponseData_t *fullresponse = (EPSII_PDM_1GetPC104GPIOProtocolResponseData_t *) fp_DataInfo->pu8Data;
    EPSII_PDM_1GetPC104GPIOResponseData_t *responsePayload = NULL;
    RespContext_t responseCtx;

    STATIC_ASSERT_SIZE_CHECK(EPSII_PDM_1GetPC104GPIOProtocolResponseData_t);

    if ((fullresponse == NULL) || (pCliApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullresponse)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    responsePayload = (EPSII_PDM_1GetPC104GPIOResponseData_t *) &fullresponse->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pCliApiHnd->EPSII_PDM_1_GetPC104GPIOResponseHandler != NULL)
    {
        responseCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        responseCtx.netType = fp_DataInfo->pMACContext->netType;
        responseCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        responseCtx.seqId = fullresponse->hdr.seqId;

        pCliApiHnd->EPSII_PDM_1_GetPC104GPIOResponseHandler(&responseCtx,
                                        ((fullresponse->hdr).errCode != ESSA_FP_ERRCODE_NOERROR) ? (NULL) : (responsePayload));
    }
}

static void fs_GetRAWSensorsResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    EPSII_PDM_1GetRAWSensorsProtocolResponseData_t *fullresponse = (EPSII_PDM_1GetRAWSensorsProtocolResponseData_t *) fp_DataInfo->pu8Data;
    EPSII_PDM_1GetRAWSensorsResponseData_t *responsePayload = NULL;
    RespContext_t responseCtx;

    STATIC_ASSERT_SIZE_CHECK(EPSII_PDM_1GetRAWSensorsProtocolResponseData_t);

    if ((fullresponse == NULL) || (pCliApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullresponse)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    responsePayload = (EPSII_PDM_1GetRAWSensorsResponseData_t *) &fullresponse->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pCliApiHnd->EPSII_PDM_1_GetRAWSensorsResponseHandler != NULL)
    {
        responseCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        responseCtx.netType = fp_DataInfo->pMACContext->netType;
        responseCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        responseCtx.seqId = fullresponse->hdr.seqId;

        pCliApiHnd->EPSII_PDM_1_GetRAWSensorsResponseHandler(&responseCtx,
                                        ((fullresponse->hdr).errCode != ESSA_FP_ERRCODE_NOERROR) ? (NULL) : (responsePayload));
    }
}

static void fs_SetPowerOutputsResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    EPSII_PDM_1SetPowerOutputsProtocolResponseData_t *fullresponse = (EPSII_PDM_1SetPowerOutputsProtocolResponseData_t *) fp_DataInfo->pu8Data;
    EPSII_PDM_1SetPowerOutputsResponseData_t *responsePayload = NULL;
    RespContext_t responseCtx;

    STATIC_ASSERT_SIZE_CHECK(EPSII_PDM_1SetPowerOutputsProtocolResponseData_t);

    if ((fullresponse == NULL) || (pCliApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullresponse)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    responsePayload = (EPSII_PDM_1SetPowerOutputsResponseData_t *) &fullresponse->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pCliApiHnd->EPSII_PDM_1_SetPowerOutputsResponseHandler != NULL)
    {
        responseCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        responseCtx.netType = fp_DataInfo->pMACContext->netType;
        responseCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        responseCtx.seqId = fullresponse->hdr.seqId;

        pCliApiHnd->EPSII_PDM_1_SetPowerOutputsResponseHandler(&responseCtx,
                                        ((fullresponse->hdr).errCode != ESSA_FP_ERRCODE_NOERROR) ? (NULL) : (responsePayload));
    }
}

static void fs_GetPowerOutputsResp(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    EPSII_PDM_1GetPowerOutputsProtocolResponseData_t *fullresponse = (EPSII_PDM_1GetPowerOutputsProtocolResponseData_t *) fp_DataInfo->pu8Data;
    EPSII_PDM_1GetPowerOutputsResponseData_t *responsePayload = NULL;
    RespContext_t responseCtx;

    STATIC_ASSERT_SIZE_CHECK(EPSII_PDM_1GetPowerOutputsProtocolResponseData_t);

    if ((fullresponse == NULL) || (pCliApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullresponse)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    responsePayload = (EPSII_PDM_1GetPowerOutputsResponseData_t *) &fullresponse->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pCliApiHnd->EPSII_PDM_1_GetPowerOutputsResponseHandler != NULL)
    {
        responseCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        responseCtx.netType = fp_DataInfo->pMACContext->netType;
        responseCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        responseCtx.seqId = fullresponse->hdr.seqId;

        pCliApiHnd->EPSII_PDM_1_GetPowerOutputsResponseHandler(&responseCtx,
                                        ((fullresponse->hdr).errCode != ESSA_FP_ERRCODE_NOERROR) ? (NULL) : (responsePayload));
    }
}


/**********************************************************************
 *
 *  Public methods implementation
 *
 **********************************************************************/
void EPSII_PDM_1_registerClientApi(EPSII_PDM_1_ClientApi_t *pCliApiHandlers)
{
    pCliApiHnd = pCliApiHandlers;
}

ESSA_pStack_FunctionProtocolInfo_t EPSII_PDM_1_getClientProtocolDescriptor(void)
{
    return (ESSA_pStack_FunctionProtocolInfo_t) &FP_EPSII_PDM_1ProtocolClientInfo;
}

ESSATMAC_ErrCodes EPSII_PDM_1_GetPowerDistributionInfoReq(
                ReqContext_t* ctx)
{
#ifndef BIG_ENDIAN_PLATFORM
    EPSII_PDM_1GetPowerDistributionInfoProtocolRequestData_t requestParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t requestParams[sizeof(EPSII_PDM_1GetPowerDistributionInfoProtocolRequestData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(EPSII_PDM_1GetPowerDistributionInfoProtocolRequestData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        requestParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_EPSII_PDM_1;
        requestParams.hdr.funcId  = EPSII_PDM_1_GETPOWERDISTRIBUTIONINFO_FUNC_ID;
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
                                            sizeof(EPSII_PDM_1GetPowerDistributionInfoProtocolRequestData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes EPSII_PDM_1_GetDeviceHealthInfoReq(
                ReqContext_t* ctx)
{
#ifndef BIG_ENDIAN_PLATFORM
    EPSII_PDM_1GetDeviceHealthInfoProtocolRequestData_t requestParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t requestParams[sizeof(EPSII_PDM_1GetDeviceHealthInfoProtocolRequestData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(EPSII_PDM_1GetDeviceHealthInfoProtocolRequestData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        requestParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_EPSII_PDM_1;
        requestParams.hdr.funcId  = EPSII_PDM_1_GETDEVICEHEALTHINFO_FUNC_ID;
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
                                            sizeof(EPSII_PDM_1GetDeviceHealthInfoProtocolRequestData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes EPSII_PDM_1_SetPC104GPIOReq(
                ReqContext_t* ctx,
                const EPSII_PDM_1_SGGPIO_Bitmask_t eFilterMask,
                const EPSII_PDM_1_SGGPIO_OnOff_mask_t eValuesMaskReq
)
{
#ifndef BIG_ENDIAN_PLATFORM
    EPSII_PDM_1SetPC104GPIOProtocolRequestData_t requestParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t requestParams[sizeof(EPSII_PDM_1SetPC104GPIOProtocolRequestData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(EPSII_PDM_1SetPC104GPIOProtocolRequestData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        requestParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_EPSII_PDM_1;
        requestParams.hdr.funcId  = EPSII_PDM_1_SETPC104GPIO_FUNC_ID;
        requestParams.hdr.seqId   = FP_Helpers_GenMsgId();
        requestParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_REQUEST(requestParams.hdr);
        // Make seqId available to sender 
        ctx->seqId = requestParams.hdr.seqId;

        // fill message data
        requestParams.data.eFilterMask = eFilterMask;
        requestParams.data.eValuesMaskReq = eValuesMaskReq;
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
                                            sizeof(EPSII_PDM_1SetPC104GPIOProtocolRequestData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes EPSII_PDM_1_GetPC104GPIOReq(
                ReqContext_t* ctx)
{
#ifndef BIG_ENDIAN_PLATFORM
    EPSII_PDM_1GetPC104GPIOProtocolRequestData_t requestParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t requestParams[sizeof(EPSII_PDM_1GetPC104GPIOProtocolRequestData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(EPSII_PDM_1GetPC104GPIOProtocolRequestData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        requestParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_EPSII_PDM_1;
        requestParams.hdr.funcId  = EPSII_PDM_1_GETPC104GPIO_FUNC_ID;
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
                                            sizeof(EPSII_PDM_1GetPC104GPIOProtocolRequestData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes EPSII_PDM_1_GetRAWSensorsReq(
                ReqContext_t* ctx,
                const uint32_t u32PktIDReq,
                const EPSII_PDM_1_ESEPSII_PDM_SensorIDs_t * const aeSensorsIDs
)
{
#ifndef BIG_ENDIAN_PLATFORM
    EPSII_PDM_1GetRAWSensorsProtocolRequestData_t requestParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t requestParams[sizeof(EPSII_PDM_1GetRAWSensorsProtocolRequestData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(EPSII_PDM_1GetRAWSensorsProtocolRequestData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        requestParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_EPSII_PDM_1;
        requestParams.hdr.funcId  = EPSII_PDM_1_GETRAWSENSORS_FUNC_ID;
        requestParams.hdr.seqId   = FP_Helpers_GenMsgId();
        requestParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_REQUEST(requestParams.hdr);
        // Make seqId available to sender 
        ctx->seqId = requestParams.hdr.seqId;

        // fill message data
        requestParams.data.u32PktIDReq = u32PktIDReq;
        if (aeSensorsIDs != NULL)
        {
            (void) memcpy((void *) requestParams.data.aeSensorsIDs,
                          (const void *) aeSensorsIDs,
                          sizeof(requestParams.data.aeSensorsIDs));
        }
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
                                            sizeof(EPSII_PDM_1GetRAWSensorsProtocolRequestData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes EPSII_PDM_1_SetPowerOutputsReq(
                ReqContext_t* ctx,
                const EPSII_PDM_1_SGPO_Bitmask_t eFilterMask,
                const EPSII_PDM_1_SGPO_ON_Off_Bitmask_t eValuesMask
)
{
#ifndef BIG_ENDIAN_PLATFORM
    EPSII_PDM_1SetPowerOutputsProtocolRequestData_t requestParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t requestParams[sizeof(EPSII_PDM_1SetPowerOutputsProtocolRequestData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(EPSII_PDM_1SetPowerOutputsProtocolRequestData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        requestParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_EPSII_PDM_1;
        requestParams.hdr.funcId  = EPSII_PDM_1_SETPOWEROUTPUTS_FUNC_ID;
        requestParams.hdr.seqId   = FP_Helpers_GenMsgId();
        requestParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_REQUEST(requestParams.hdr);
        // Make seqId available to sender 
        ctx->seqId = requestParams.hdr.seqId;

        // fill message data
        requestParams.data.eFilterMask = eFilterMask;
        requestParams.data.eValuesMask = eValuesMask;
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
                                            sizeof(EPSII_PDM_1SetPowerOutputsProtocolRequestData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes EPSII_PDM_1_GetPowerOutputsReq(
                ReqContext_t* ctx)
{
#ifndef BIG_ENDIAN_PLATFORM
    EPSII_PDM_1GetPowerOutputsProtocolRequestData_t requestParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t requestParams[sizeof(EPSII_PDM_1GetPowerOutputsProtocolRequestData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(EPSII_PDM_1GetPowerOutputsProtocolRequestData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        requestParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_EPSII_PDM_1;
        requestParams.hdr.funcId  = EPSII_PDM_1_GETPOWEROUTPUTS_FUNC_ID;
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
                                            sizeof(EPSII_PDM_1GetPowerOutputsProtocolRequestData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}


