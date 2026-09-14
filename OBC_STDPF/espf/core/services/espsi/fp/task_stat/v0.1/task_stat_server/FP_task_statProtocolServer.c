/*!
********************************************************************************************
* @file FP_task_statProtocolServer.c
* @brief ESSA Stack server-side implementation
********************************************************************************************
* @version           interface task_stat v0.1
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

#include "FP_task_statProtocolServer.h"
#include "FP_common/FP_ProtocolServerCommon.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Local type definitions
 *
 **********************************************************************/
typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT task_statget_configurationProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    task_statget_configurationResponseData_t data;
} PACKED_STRUCT task_statget_configurationProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    task_statset_configuration_global_enableRequestData_t data;
} PACKED_STRUCT task_statset_configuration_global_enableProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    task_statset_configuration_global_enableResponseData_t data;
} PACKED_STRUCT task_statset_configuration_global_enableProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    task_statset_configuration_global_loggingRequestData_t data;
} PACKED_STRUCT task_statset_configuration_global_loggingProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    task_statset_configuration_global_loggingResponseData_t data;
} PACKED_STRUCT task_statset_configuration_global_loggingProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    task_statset_configuration_global_priorityRequestData_t data;
} PACKED_STRUCT task_statset_configuration_global_priorityProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    task_statset_configuration_global_priorityResponseData_t data;
} PACKED_STRUCT task_statset_configuration_global_priorityProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    task_statset_configuration_global_sampling_periodRequestData_t data;
} PACKED_STRUCT task_statset_configuration_global_sampling_periodProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    task_statset_configuration_global_sampling_periodResponseData_t data;
} PACKED_STRUCT task_statset_configuration_global_sampling_periodProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    task_statset_configuration_global_id_fileRequestData_t data;
} PACKED_STRUCT task_statset_configuration_global_id_fileProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    task_statset_configuration_global_id_fileResponseData_t data;
} PACKED_STRUCT task_statset_configuration_global_id_fileProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT task_statset_configuration_global_defaultsProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    task_statset_configuration_global_defaultsResponseData_t data;
} PACKED_STRUCT task_statset_configuration_global_defaultsProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    task_statget_configuration_per_task_idRequestData_t data;
} PACKED_STRUCT task_statget_configuration_per_task_idProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    task_statget_configuration_per_task_idResponseData_t data;
} PACKED_STRUCT task_statget_configuration_per_task_idProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    task_statset_configuration_per_task_idRequestData_t data;
} PACKED_STRUCT task_statset_configuration_per_task_idProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    task_statset_configuration_per_task_idResponseData_t data;
} PACKED_STRUCT task_statset_configuration_per_task_idProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT task_statget_free_heapProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    task_statget_free_heapResponseData_t data;
} PACKED_STRUCT task_statget_free_heapProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    task_statget_latest_task_statRequestData_t data;
} PACKED_STRUCT task_statget_latest_task_statProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    task_statget_latest_task_statResponseData_t data;
} PACKED_STRUCT task_statget_latest_task_statProtocolResponseData_t;


/**********************************************************************
 *
 *  Static methods declarations
 *
 **********************************************************************/
static bool fs_HandleData(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_configurationReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_configuration_global_enableReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_configuration_global_loggingReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_configuration_global_priorityReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_configuration_global_sampling_periodReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_configuration_global_id_fileReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_configuration_global_defaultsReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_configuration_per_task_idReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_configuration_per_task_idReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_free_heapReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_latest_task_statReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);

/**********************************************************************
 *
 *  Public variable definitions
 *
 **********************************************************************/
const ESSA_Stack_FunctionProtocolInfo_t FP_task_statProtocolServerInfo = {
    .u16ProtocolId    = ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT,
        .pfDataHandlerCbk = &fs_HandleData
};

/**********************************************************************
 *
 *  Static variable definitions
 *
 **********************************************************************/
static task_stat_ServerApi_t *pSrvApiHnd = NULL;

static const ProtocolFuncArrayEntry_t fs_aFuncArray[] = {
    { TASK_STAT_GET_CONFIGURATION_FUNC_ID, fs_get_configurationReq },
    { TASK_STAT_SET_CONFIGURATION_GLOBAL_ENABLE_FUNC_ID, fs_set_configuration_global_enableReq },
    { TASK_STAT_SET_CONFIGURATION_GLOBAL_LOGGING_FUNC_ID, fs_set_configuration_global_loggingReq },
    { TASK_STAT_SET_CONFIGURATION_GLOBAL_PRIORITY_FUNC_ID, fs_set_configuration_global_priorityReq },
    { TASK_STAT_SET_CONFIGURATION_GLOBAL_SAMPLING_PERIOD_FUNC_ID, fs_set_configuration_global_sampling_periodReq },
    { TASK_STAT_SET_CONFIGURATION_GLOBAL_ID_FILE_FUNC_ID, fs_set_configuration_global_id_fileReq },
    { TASK_STAT_SET_CONFIGURATION_GLOBAL_DEFAULTS_FUNC_ID, fs_set_configuration_global_defaultsReq },
    { TASK_STAT_GET_CONFIGURATION_PER_TASK_ID_FUNC_ID, fs_get_configuration_per_task_idReq },
    { TASK_STAT_SET_CONFIGURATION_PER_TASK_ID_FUNC_ID, fs_set_configuration_per_task_idReq },
    { TASK_STAT_GET_FREE_HEAP_FUNC_ID, fs_get_free_heapReq },
    { TASK_STAT_GET_LATEST_TASK_STAT_FUNC_ID, fs_get_latest_task_statReq }
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







static void fs_get_configurationReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    task_statget_configurationProtocolRequestData_t *fullrequest = (task_statget_configurationProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(task_statget_configurationProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->task_stat_get_configurationRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->task_stat_get_configurationRequestHandler(&requestCtx);
    }
}

static void fs_set_configuration_global_enableReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    task_statset_configuration_global_enableProtocolRequestData_t *fullrequest = (task_statset_configuration_global_enableProtocolRequestData_t *) fp_DataInfo->pu8Data;
    task_statset_configuration_global_enableRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(task_statset_configuration_global_enableProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (task_statset_configuration_global_enableRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->task_stat_set_configuration_global_enableRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->task_stat_set_configuration_global_enableRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_set_configuration_global_loggingReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    task_statset_configuration_global_loggingProtocolRequestData_t *fullrequest = (task_statset_configuration_global_loggingProtocolRequestData_t *) fp_DataInfo->pu8Data;
    task_statset_configuration_global_loggingRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(task_statset_configuration_global_loggingProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (task_statset_configuration_global_loggingRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->task_stat_set_configuration_global_loggingRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->task_stat_set_configuration_global_loggingRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_set_configuration_global_priorityReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    task_statset_configuration_global_priorityProtocolRequestData_t *fullrequest = (task_statset_configuration_global_priorityProtocolRequestData_t *) fp_DataInfo->pu8Data;
    task_statset_configuration_global_priorityRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(task_statset_configuration_global_priorityProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (task_statset_configuration_global_priorityRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->task_stat_set_configuration_global_priorityRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->task_stat_set_configuration_global_priorityRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_set_configuration_global_sampling_periodReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    task_statset_configuration_global_sampling_periodProtocolRequestData_t *fullrequest = (task_statset_configuration_global_sampling_periodProtocolRequestData_t *) fp_DataInfo->pu8Data;
    task_statset_configuration_global_sampling_periodRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(task_statset_configuration_global_sampling_periodProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (task_statset_configuration_global_sampling_periodRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->task_stat_set_configuration_global_sampling_periodRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->task_stat_set_configuration_global_sampling_periodRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_set_configuration_global_id_fileReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    task_statset_configuration_global_id_fileProtocolRequestData_t *fullrequest = (task_statset_configuration_global_id_fileProtocolRequestData_t *) fp_DataInfo->pu8Data;
    task_statset_configuration_global_id_fileRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(task_statset_configuration_global_id_fileProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (task_statset_configuration_global_id_fileRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->task_stat_set_configuration_global_id_fileRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->task_stat_set_configuration_global_id_fileRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_set_configuration_global_defaultsReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    task_statset_configuration_global_defaultsProtocolRequestData_t *fullrequest = (task_statset_configuration_global_defaultsProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(task_statset_configuration_global_defaultsProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->task_stat_set_configuration_global_defaultsRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->task_stat_set_configuration_global_defaultsRequestHandler(&requestCtx);
    }
}

static void fs_get_configuration_per_task_idReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    task_statget_configuration_per_task_idProtocolRequestData_t *fullrequest = (task_statget_configuration_per_task_idProtocolRequestData_t *) fp_DataInfo->pu8Data;
    task_statget_configuration_per_task_idRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(task_statget_configuration_per_task_idProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (task_statget_configuration_per_task_idRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->task_stat_get_configuration_per_task_idRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->task_stat_get_configuration_per_task_idRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_set_configuration_per_task_idReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    task_statset_configuration_per_task_idProtocolRequestData_t *fullrequest = (task_statset_configuration_per_task_idProtocolRequestData_t *) fp_DataInfo->pu8Data;
    task_statset_configuration_per_task_idRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(task_statset_configuration_per_task_idProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (task_statset_configuration_per_task_idRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->task_stat_set_configuration_per_task_idRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->task_stat_set_configuration_per_task_idRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_free_heapReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    task_statget_free_heapProtocolRequestData_t *fullrequest = (task_statget_free_heapProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(task_statget_free_heapProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->task_stat_get_free_heapRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->task_stat_get_free_heapRequestHandler(&requestCtx);
    }
}

static void fs_get_latest_task_statReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    task_statget_latest_task_statProtocolRequestData_t *fullrequest = (task_statget_latest_task_statProtocolRequestData_t *) fp_DataInfo->pu8Data;
    task_statget_latest_task_statRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(task_statget_latest_task_statProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (task_statget_latest_task_statRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->task_stat_get_latest_task_statRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->task_stat_get_latest_task_statRequestHandler(&requestCtx,
                                        requestPayload);
    }
}


/**********************************************************************
 *
 *  Public methods implementation
 *
 **********************************************************************/
void task_stat_registerServerApi(task_stat_ServerApi_t *pSrvApiHandlers)
{
    pSrvApiHnd = pSrvApiHandlers;
}

ESSA_pStack_FunctionProtocolInfo_t task_stat_getServerProtocolDescriptor(void)
{
    return (ESSA_pStack_FunctionProtocolInfo_t) &FP_task_statProtocolServerInfo;
}

ESSATMAC_ErrCodes task_stat_get_configurationResp(
                RespContext_t* ctx,
                const TASK_STAT_OpStatus_t eStatus,
                const TASK_STAT_StatsConfig_t * const sConfig
)
{
#ifndef BIG_ENDIAN_PLATFORM
    task_statget_configurationProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(task_statget_configurationProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(task_statget_configurationProtocolResponseData_t);

    if ((ctx != NULL) && (sConfig != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT;
        responseParams.hdr.funcId  = TASK_STAT_GET_CONFIGURATION_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eStatus = eStatus;
        if (sConfig != NULL)
        {
            responseParams.data.sConfig = *(sConfig);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sConfig,
                          0U,
                          sizeof(responseParams.data.sConfig));
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
                                            sizeof(task_statget_configurationProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes task_stat_set_configuration_global_enableResp(
                RespContext_t* ctx,
                const bool bStatus
)
{
#ifndef BIG_ENDIAN_PLATFORM
    task_statset_configuration_global_enableProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(task_statset_configuration_global_enableProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(task_statset_configuration_global_enableProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT;
        responseParams.hdr.funcId  = TASK_STAT_SET_CONFIGURATION_GLOBAL_ENABLE_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.bStatus = bStatus;
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
                                            sizeof(task_statset_configuration_global_enableProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes task_stat_set_configuration_global_loggingResp(
                RespContext_t* ctx,
                const bool bStatus
)
{
#ifndef BIG_ENDIAN_PLATFORM
    task_statset_configuration_global_loggingProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(task_statset_configuration_global_loggingProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(task_statset_configuration_global_loggingProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT;
        responseParams.hdr.funcId  = TASK_STAT_SET_CONFIGURATION_GLOBAL_LOGGING_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.bStatus = bStatus;
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
                                            sizeof(task_statset_configuration_global_loggingProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes task_stat_set_configuration_global_priorityResp(
                RespContext_t* ctx,
                const bool bStatus
)
{
#ifndef BIG_ENDIAN_PLATFORM
    task_statset_configuration_global_priorityProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(task_statset_configuration_global_priorityProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(task_statset_configuration_global_priorityProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT;
        responseParams.hdr.funcId  = TASK_STAT_SET_CONFIGURATION_GLOBAL_PRIORITY_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.bStatus = bStatus;
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
                                            sizeof(task_statset_configuration_global_priorityProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes task_stat_set_configuration_global_sampling_periodResp(
                RespContext_t* ctx,
                const bool bStatus
)
{
#ifndef BIG_ENDIAN_PLATFORM
    task_statset_configuration_global_sampling_periodProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(task_statset_configuration_global_sampling_periodProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(task_statset_configuration_global_sampling_periodProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT;
        responseParams.hdr.funcId  = TASK_STAT_SET_CONFIGURATION_GLOBAL_SAMPLING_PERIOD_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.bStatus = bStatus;
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
                                            sizeof(task_statset_configuration_global_sampling_periodProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes task_stat_set_configuration_global_id_fileResp(
                RespContext_t* ctx,
                const bool bStatus
)
{
#ifndef BIG_ENDIAN_PLATFORM
    task_statset_configuration_global_id_fileProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(task_statset_configuration_global_id_fileProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(task_statset_configuration_global_id_fileProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT;
        responseParams.hdr.funcId  = TASK_STAT_SET_CONFIGURATION_GLOBAL_ID_FILE_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.bStatus = bStatus;
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
                                            sizeof(task_statset_configuration_global_id_fileProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes task_stat_set_configuration_global_defaultsResp(
                RespContext_t* ctx,
                const bool bStatus
)
{
#ifndef BIG_ENDIAN_PLATFORM
    task_statset_configuration_global_defaultsProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(task_statset_configuration_global_defaultsProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(task_statset_configuration_global_defaultsProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT;
        responseParams.hdr.funcId  = TASK_STAT_SET_CONFIGURATION_GLOBAL_DEFAULTS_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.bStatus = bStatus;
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
                                            sizeof(task_statset_configuration_global_defaultsProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes task_stat_get_configuration_per_task_idResp(
                RespContext_t* ctx,
                const TASK_STAT_OpStatus_t eStatus,
                const TASK_STAT_TaskStatConfig_t * const sTask_cfg
)
{
#ifndef BIG_ENDIAN_PLATFORM
    task_statget_configuration_per_task_idProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(task_statget_configuration_per_task_idProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(task_statget_configuration_per_task_idProtocolResponseData_t);

    if ((ctx != NULL) && (sTask_cfg != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT;
        responseParams.hdr.funcId  = TASK_STAT_GET_CONFIGURATION_PER_TASK_ID_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eStatus = eStatus;
        if (sTask_cfg != NULL)
        {
            responseParams.data.sTask_cfg = *(sTask_cfg);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sTask_cfg,
                          0U,
                          sizeof(responseParams.data.sTask_cfg));
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
                                            sizeof(task_statget_configuration_per_task_idProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes task_stat_set_configuration_per_task_idResp(
                RespContext_t* ctx,
                const TASK_STAT_OpStatus_t eStatus
)
{
#ifndef BIG_ENDIAN_PLATFORM
    task_statset_configuration_per_task_idProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(task_statset_configuration_per_task_idProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(task_statset_configuration_per_task_idProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT;
        responseParams.hdr.funcId  = TASK_STAT_SET_CONFIGURATION_PER_TASK_ID_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eStatus = eStatus;
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
                                            sizeof(task_statset_configuration_per_task_idProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes task_stat_get_free_heapResp(
                RespContext_t* ctx,
                const TASK_STAT_OpStatus_t eStatus,
                const uint32_t u32Free_heap
)
{
#ifndef BIG_ENDIAN_PLATFORM
    task_statget_free_heapProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(task_statget_free_heapProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(task_statget_free_heapProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT;
        responseParams.hdr.funcId  = TASK_STAT_GET_FREE_HEAP_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eStatus = eStatus;
        responseParams.data.u32Free_heap = u32Free_heap;
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
                                            sizeof(task_statget_free_heapProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes task_stat_get_latest_task_statResp(
                RespContext_t* ctx,
                const TASK_STAT_OpStatus_t eStatus,
                const TASK_STAT_TaskStatSample_t * const sStat
)
{
#ifndef BIG_ENDIAN_PLATFORM
    task_statget_latest_task_statProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(task_statget_latest_task_statProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(task_statget_latest_task_statProtocolResponseData_t);

    if ((ctx != NULL) && (sStat != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT;
        responseParams.hdr.funcId  = TASK_STAT_GET_LATEST_TASK_STAT_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eStatus = eStatus;
        if (sStat != NULL)
        {
            responseParams.data.sStat = *(sStat);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sStat,
                          0U,
                          sizeof(responseParams.data.sStat));
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
                                            sizeof(task_statget_latest_task_statProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}


