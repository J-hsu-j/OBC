/*!
********************************************************************************************
* @file FP_onboard_schedProtocolServer.c
* @brief ESSA Stack server-side implementation
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
#include "FP_common/FP_ProtocolServerCommon.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Local type definitions
 *
 **********************************************************************/
typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    onboard_schedset_scheduler_stateRequestData_t data;
} PACKED_STRUCT onboard_schedset_scheduler_stateProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    onboard_schedset_scheduler_stateResponseData_t data;
} PACKED_STRUCT onboard_schedset_scheduler_stateProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT onboard_schedget_scheduler_stateProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    onboard_schedget_scheduler_stateResponseData_t data;
} PACKED_STRUCT onboard_schedget_scheduler_stateProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    onboard_schedset_active_scheduleRequestData_t data;
} PACKED_STRUCT onboard_schedset_active_scheduleProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    onboard_schedset_active_scheduleResponseData_t data;
} PACKED_STRUCT onboard_schedset_active_scheduleProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT onboard_schedget_active_scheduleProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    onboard_schedget_active_scheduleResponseData_t data;
} PACKED_STRUCT onboard_schedget_active_scheduleProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT onboard_schedget_next_slotProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    onboard_schedget_next_slotResponseData_t data;
} PACKED_STRUCT onboard_schedget_next_slotProtocolResponseData_t;


/**********************************************************************
 *
 *  Static methods declarations
 *
 **********************************************************************/
static bool fs_HandleData(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_scheduler_stateReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_scheduler_stateReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_active_scheduleReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_active_scheduleReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_next_slotReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);

/**********************************************************************
 *
 *  Public variable definitions
 *
 **********************************************************************/
const ESSA_Stack_FunctionProtocolInfo_t FP_onboard_schedProtocolServerInfo = {
    .u16ProtocolId    = ES_SAT_FUNC_PROTOCOL_ID_ONBOARD_SCHED,
        .pfDataHandlerCbk = &fs_HandleData
};

/**********************************************************************
 *
 *  Static variable definitions
 *
 **********************************************************************/
static onboard_sched_ServerApi_t *pSrvApiHnd = NULL;

static const ProtocolFuncArrayEntry_t fs_aFuncArray[] = {
    { ONBOARD_SCHED_SET_SCHEDULER_STATE_FUNC_ID, fs_set_scheduler_stateReq },
    { ONBOARD_SCHED_GET_SCHEDULER_STATE_FUNC_ID, fs_get_scheduler_stateReq },
    { ONBOARD_SCHED_SET_ACTIVE_SCHEDULE_FUNC_ID, fs_set_active_scheduleReq },
    { ONBOARD_SCHED_GET_ACTIVE_SCHEDULE_FUNC_ID, fs_get_active_scheduleReq },
    { ONBOARD_SCHED_GET_NEXT_SLOT_FUNC_ID, fs_get_next_slotReq }
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







static void fs_set_scheduler_stateReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    onboard_schedset_scheduler_stateProtocolRequestData_t *fullrequest = (onboard_schedset_scheduler_stateProtocolRequestData_t *) fp_DataInfo->pu8Data;
    onboard_schedset_scheduler_stateRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(onboard_schedset_scheduler_stateProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (onboard_schedset_scheduler_stateRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->onboard_sched_set_scheduler_stateRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->onboard_sched_set_scheduler_stateRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_scheduler_stateReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    onboard_schedget_scheduler_stateProtocolRequestData_t *fullrequest = (onboard_schedget_scheduler_stateProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(onboard_schedget_scheduler_stateProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->onboard_sched_get_scheduler_stateRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->onboard_sched_get_scheduler_stateRequestHandler(&requestCtx);
    }
}

static void fs_set_active_scheduleReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    onboard_schedset_active_scheduleProtocolRequestData_t *fullrequest = (onboard_schedset_active_scheduleProtocolRequestData_t *) fp_DataInfo->pu8Data;
    onboard_schedset_active_scheduleRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(onboard_schedset_active_scheduleProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (onboard_schedset_active_scheduleRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->onboard_sched_set_active_scheduleRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->onboard_sched_set_active_scheduleRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_active_scheduleReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    onboard_schedget_active_scheduleProtocolRequestData_t *fullrequest = (onboard_schedget_active_scheduleProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(onboard_schedget_active_scheduleProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->onboard_sched_get_active_scheduleRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->onboard_sched_get_active_scheduleRequestHandler(&requestCtx);
    }
}

static void fs_get_next_slotReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    onboard_schedget_next_slotProtocolRequestData_t *fullrequest = (onboard_schedget_next_slotProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(onboard_schedget_next_slotProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->onboard_sched_get_next_slotRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->onboard_sched_get_next_slotRequestHandler(&requestCtx);
    }
}


/**********************************************************************
 *
 *  Public methods implementation
 *
 **********************************************************************/
void onboard_sched_registerServerApi(onboard_sched_ServerApi_t *pSrvApiHandlers)
{
    pSrvApiHnd = pSrvApiHandlers;
}

ESSA_pStack_FunctionProtocolInfo_t onboard_sched_getServerProtocolDescriptor(void)
{
    return (ESSA_pStack_FunctionProtocolInfo_t) &FP_onboard_schedProtocolServerInfo;
}

ESSATMAC_ErrCodes onboard_sched_set_scheduler_stateResp(
                RespContext_t* ctx,
                const ONBOARD_SCHED_SchedState_t eNew_state
)
{
#ifndef BIG_ENDIAN_PLATFORM
    onboard_schedset_scheduler_stateProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(onboard_schedset_scheduler_stateProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(onboard_schedset_scheduler_stateProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_ONBOARD_SCHED;
        responseParams.hdr.funcId  = ONBOARD_SCHED_SET_SCHEDULER_STATE_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eNew_state = eNew_state;
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
                                            sizeof(onboard_schedset_scheduler_stateProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes onboard_sched_get_scheduler_stateResp(
                RespContext_t* ctx,
                const ONBOARD_SCHED_SchedState_t eSch_state
)
{
#ifndef BIG_ENDIAN_PLATFORM
    onboard_schedget_scheduler_stateProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(onboard_schedget_scheduler_stateProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(onboard_schedget_scheduler_stateProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_ONBOARD_SCHED;
        responseParams.hdr.funcId  = ONBOARD_SCHED_GET_SCHEDULER_STATE_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eSch_state = eSch_state;
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
                                            sizeof(onboard_schedget_scheduler_stateProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes onboard_sched_set_active_scheduleResp(
                RespContext_t* ctx,
                const ONBOARD_SCHED_SchedLoadResult_t eResult
)
{
#ifndef BIG_ENDIAN_PLATFORM
    onboard_schedset_active_scheduleProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(onboard_schedset_active_scheduleProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(onboard_schedset_active_scheduleProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_ONBOARD_SCHED;
        responseParams.hdr.funcId  = ONBOARD_SCHED_SET_ACTIVE_SCHEDULE_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eResult = eResult;
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
                                            sizeof(onboard_schedset_active_scheduleProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes onboard_sched_get_active_scheduleResp(
                RespContext_t* ctx,
                char * const strFile_name,
                const uint8_t u8File_nameSize,
                const ONBOARD_SCHED_SchedLoadResult_t eResult
)
{
#ifndef BIG_ENDIAN_PLATFORM
    onboard_schedget_active_scheduleProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(onboard_schedget_active_scheduleProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(onboard_schedget_active_scheduleProtocolResponseData_t);

    if ((ctx != NULL) && (strFile_name != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_ONBOARD_SCHED;
        responseParams.hdr.funcId  = ONBOARD_SCHED_GET_ACTIVE_SCHEDULE_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        if (strFile_name != NULL)
        {
            if (u8File_nameSize > 0U)
            {
                // zero-out complete message buffer before copying user data to avoid confusion if
                // buffer is only partially filled-in by user
                (void) memset((void *) responseParams.data.strFile_name,
                              0U,
                              sizeof(responseParams.data.strFile_name));
                (void) memcpy((void *) responseParams.data.strFile_name,
                              (const void *) strFile_name,
                              MIN(u8File_nameSize, sizeof(responseParams.data.strFile_name)));
            
                // add NULLZ termination for string types
                if (u8File_nameSize < sizeof(responseParams.data.strFile_name))
                    responseParams.data.strFile_name[u8File_nameSize] = '\0';
                else
                    responseParams.data.strFile_name[sizeof(responseParams.data.strFile_name) - 1] = '\0';
            }
            
            responseParams.data.u8File_nameSize = MIN(u8File_nameSize, sizeof(responseParams.data.strFile_name));
        }
        else
        {
            (void) memset((void *) responseParams.data.strFile_name,
                          0U,
                          sizeof(responseParams.data.strFile_name));
            responseParams.data.u8File_nameSize = 0U;
        }
        responseParams.data.eResult = eResult;
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
                                            sizeof(onboard_schedget_active_scheduleProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes onboard_sched_get_next_slotResp(
                RespContext_t* ctx,
                const uint32_t u32Offset
)
{
#ifndef BIG_ENDIAN_PLATFORM
    onboard_schedget_next_slotProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(onboard_schedget_next_slotProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(onboard_schedget_next_slotProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_ONBOARD_SCHED;
        responseParams.hdr.funcId  = ONBOARD_SCHED_GET_NEXT_SLOT_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.u32Offset = u32Offset;
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
                                            sizeof(onboard_schedget_next_slotProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}


