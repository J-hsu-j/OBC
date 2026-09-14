/*!
********************************************************************************************
* @file FP_telemetryProtocolServer.c
* @brief ESSA Stack server-side implementation
********************************************************************************************
* @version           interface telemetry v2.0
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

#include "FP_telemetryProtocolServer.h"
#include "FP_common/FP_ProtocolServerCommon.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Local type definitions
 *
 **********************************************************************/
typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrygetTelemetryGeneralConfigRequestData_t data;
} PACKED_STRUCT telemetrygetTelemetryGeneralConfigProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrygetTelemetryGeneralConfigResponseData_t data;
} PACKED_STRUCT telemetrygetTelemetryGeneralConfigProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrysetTelemetryGeneralConfigRequestData_t data;
} PACKED_STRUCT telemetrysetTelemetryGeneralConfigProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrysetTelemetryGeneralConfigResponseData_t data;
} PACKED_STRUCT telemetrysetTelemetryGeneralConfigProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrygetTelemetryPresetConfigRequestData_t data;
} PACKED_STRUCT telemetrygetTelemetryPresetConfigProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrygetTelemetryPresetConfigResponseData_t data;
} PACKED_STRUCT telemetrygetTelemetryPresetConfigProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrysetTelemetryPresetConfigRequestData_t data;
} PACKED_STRUCT telemetrysetTelemetryPresetConfigProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrysetTelemetryPresetConfigResponseData_t data;
} PACKED_STRUCT telemetrysetTelemetryPresetConfigProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrysetActivePresetRequestData_t data;
} PACKED_STRUCT telemetrysetActivePresetProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrysetActivePresetResponseData_t data;
} PACKED_STRUCT telemetrysetActivePresetProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrygetActivePresetRequestData_t data;
} PACKED_STRUCT telemetrygetActivePresetProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrygetActivePresetResponseData_t data;
} PACKED_STRUCT telemetrygetActivePresetProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetryrestoreActivePresetRequestData_t data;
} PACKED_STRUCT telemetryrestoreActivePresetProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetryrestoreActivePresetResponseData_t data;
} PACKED_STRUCT telemetryrestoreActivePresetProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrygetTelemetryFileSinkConfigRequestData_t data;
} PACKED_STRUCT telemetrygetTelemetryFileSinkConfigProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrygetTelemetryFileSinkConfigResponseData_t data;
} PACKED_STRUCT telemetrygetTelemetryFileSinkConfigProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrysetTelemetryFileSzLimitConfigRequestData_t data;
} PACKED_STRUCT telemetrysetTelemetryFileSzLimitConfigProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrysetTelemetryFileSzLimitConfigResponseData_t data;
} PACKED_STRUCT telemetrysetTelemetryFileSzLimitConfigProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrycleanTelemetryFilesRequestData_t data;
} PACKED_STRUCT telemetrycleanTelemetryFilesProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrycleanTelemetryFilesResponseData_t data;
} PACKED_STRUCT telemetrycleanTelemetryFilesProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrygetTelemetryOperationStatsRequestData_t data;
} PACKED_STRUCT telemetrygetTelemetryOperationStatsProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrygetTelemetryOperationStatsResponseData_t data;
} PACKED_STRUCT telemetrygetTelemetryOperationStatsProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrystartTelemetryRequestData_t data;
} PACKED_STRUCT telemetrystartTelemetryProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrystartTelemetryResponseData_t data;
} PACKED_STRUCT telemetrystartTelemetryProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrystopTelemetryRequestData_t data;
} PACKED_STRUCT telemetrystopTelemetryProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    telemetrystopTelemetryResponseData_t data;
} PACKED_STRUCT telemetrystopTelemetryProtocolResponseData_t;


/**********************************************************************
 *
 *  Static methods declarations
 *
 **********************************************************************/
static bool fs_HandleData(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_getTelemetryGeneralConfigReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_setTelemetryGeneralConfigReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_getTelemetryPresetConfigReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_setTelemetryPresetConfigReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_setActivePresetReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_getActivePresetReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_restoreActivePresetReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_getTelemetryFileSinkConfigReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_setTelemetryFileSzLimitConfigReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_cleanTelemetryFilesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_getTelemetryOperationStatsReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_startTelemetryReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_stopTelemetryReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);

/**********************************************************************
 *
 *  Public variable definitions
 *
 **********************************************************************/
const ESSA_Stack_FunctionProtocolInfo_t FP_telemetryProtocolServerInfo = {
    .u16ProtocolId    = ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY,
        .pfDataHandlerCbk = &fs_HandleData
};

/**********************************************************************
 *
 *  Static variable definitions
 *
 **********************************************************************/
static telemetry_ServerApi_t *pSrvApiHnd = NULL;

static const ProtocolFuncArrayEntry_t fs_aFuncArray[] = {
    { TELEMETRY_GETTELEMETRYGENERALCONFIG_FUNC_ID, fs_getTelemetryGeneralConfigReq },
    { TELEMETRY_SETTELEMETRYGENERALCONFIG_FUNC_ID, fs_setTelemetryGeneralConfigReq },
    { TELEMETRY_GETTELEMETRYPRESETCONFIG_FUNC_ID, fs_getTelemetryPresetConfigReq },
    { TELEMETRY_SETTELEMETRYPRESETCONFIG_FUNC_ID, fs_setTelemetryPresetConfigReq },
    { TELEMETRY_SETACTIVEPRESET_FUNC_ID, fs_setActivePresetReq },
    { TELEMETRY_GETACTIVEPRESET_FUNC_ID, fs_getActivePresetReq },
    { TELEMETRY_RESTOREACTIVEPRESET_FUNC_ID, fs_restoreActivePresetReq },
    { TELEMETRY_GETTELEMETRYFILESINKCONFIG_FUNC_ID, fs_getTelemetryFileSinkConfigReq },
    { TELEMETRY_SETTELEMETRYFILESZLIMITCONFIG_FUNC_ID, fs_setTelemetryFileSzLimitConfigReq },
    { TELEMETRY_CLEANTELEMETRYFILES_FUNC_ID, fs_cleanTelemetryFilesReq },
    { TELEMETRY_GETTELEMETRYOPERATIONSTATS_FUNC_ID, fs_getTelemetryOperationStatsReq },
    { TELEMETRY_STARTTELEMETRY_FUNC_ID, fs_startTelemetryReq },
    { TELEMETRY_STOPTELEMETRY_FUNC_ID, fs_stopTelemetryReq }
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







static void fs_getTelemetryGeneralConfigReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    telemetrygetTelemetryGeneralConfigProtocolRequestData_t *fullrequest = (telemetrygetTelemetryGeneralConfigProtocolRequestData_t *) fp_DataInfo->pu8Data;
    telemetrygetTelemetryGeneralConfigRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(telemetrygetTelemetryGeneralConfigProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (telemetrygetTelemetryGeneralConfigRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->telemetry_getTelemetryGeneralConfigRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->telemetry_getTelemetryGeneralConfigRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_setTelemetryGeneralConfigReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    telemetrysetTelemetryGeneralConfigProtocolRequestData_t *fullrequest = (telemetrysetTelemetryGeneralConfigProtocolRequestData_t *) fp_DataInfo->pu8Data;
    telemetrysetTelemetryGeneralConfigRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(telemetrysetTelemetryGeneralConfigProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (telemetrysetTelemetryGeneralConfigRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->telemetry_setTelemetryGeneralConfigRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->telemetry_setTelemetryGeneralConfigRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_getTelemetryPresetConfigReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    telemetrygetTelemetryPresetConfigProtocolRequestData_t *fullrequest = (telemetrygetTelemetryPresetConfigProtocolRequestData_t *) fp_DataInfo->pu8Data;
    telemetrygetTelemetryPresetConfigRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(telemetrygetTelemetryPresetConfigProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (telemetrygetTelemetryPresetConfigRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->telemetry_getTelemetryPresetConfigRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->telemetry_getTelemetryPresetConfigRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_setTelemetryPresetConfigReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    telemetrysetTelemetryPresetConfigProtocolRequestData_t *fullrequest = (telemetrysetTelemetryPresetConfigProtocolRequestData_t *) fp_DataInfo->pu8Data;
    telemetrysetTelemetryPresetConfigRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(telemetrysetTelemetryPresetConfigProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (telemetrysetTelemetryPresetConfigRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->telemetry_setTelemetryPresetConfigRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->telemetry_setTelemetryPresetConfigRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_setActivePresetReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    telemetrysetActivePresetProtocolRequestData_t *fullrequest = (telemetrysetActivePresetProtocolRequestData_t *) fp_DataInfo->pu8Data;
    telemetrysetActivePresetRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(telemetrysetActivePresetProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (telemetrysetActivePresetRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->telemetry_setActivePresetRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->telemetry_setActivePresetRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_getActivePresetReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    telemetrygetActivePresetProtocolRequestData_t *fullrequest = (telemetrygetActivePresetProtocolRequestData_t *) fp_DataInfo->pu8Data;
    telemetrygetActivePresetRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(telemetrygetActivePresetProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (telemetrygetActivePresetRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->telemetry_getActivePresetRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->telemetry_getActivePresetRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_restoreActivePresetReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    telemetryrestoreActivePresetProtocolRequestData_t *fullrequest = (telemetryrestoreActivePresetProtocolRequestData_t *) fp_DataInfo->pu8Data;
    telemetryrestoreActivePresetRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(telemetryrestoreActivePresetProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (telemetryrestoreActivePresetRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->telemetry_restoreActivePresetRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->telemetry_restoreActivePresetRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_getTelemetryFileSinkConfigReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    telemetrygetTelemetryFileSinkConfigProtocolRequestData_t *fullrequest = (telemetrygetTelemetryFileSinkConfigProtocolRequestData_t *) fp_DataInfo->pu8Data;
    telemetrygetTelemetryFileSinkConfigRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(telemetrygetTelemetryFileSinkConfigProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (telemetrygetTelemetryFileSinkConfigRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->telemetry_getTelemetryFileSinkConfigRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->telemetry_getTelemetryFileSinkConfigRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_setTelemetryFileSzLimitConfigReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    telemetrysetTelemetryFileSzLimitConfigProtocolRequestData_t *fullrequest = (telemetrysetTelemetryFileSzLimitConfigProtocolRequestData_t *) fp_DataInfo->pu8Data;
    telemetrysetTelemetryFileSzLimitConfigRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(telemetrysetTelemetryFileSzLimitConfigProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (telemetrysetTelemetryFileSzLimitConfigRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->telemetry_setTelemetryFileSzLimitConfigRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->telemetry_setTelemetryFileSzLimitConfigRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_cleanTelemetryFilesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    telemetrycleanTelemetryFilesProtocolRequestData_t *fullrequest = (telemetrycleanTelemetryFilesProtocolRequestData_t *) fp_DataInfo->pu8Data;
    telemetrycleanTelemetryFilesRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(telemetrycleanTelemetryFilesProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (telemetrycleanTelemetryFilesRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->telemetry_cleanTelemetryFilesRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->telemetry_cleanTelemetryFilesRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_getTelemetryOperationStatsReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    telemetrygetTelemetryOperationStatsProtocolRequestData_t *fullrequest = (telemetrygetTelemetryOperationStatsProtocolRequestData_t *) fp_DataInfo->pu8Data;
    telemetrygetTelemetryOperationStatsRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(telemetrygetTelemetryOperationStatsProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (telemetrygetTelemetryOperationStatsRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->telemetry_getTelemetryOperationStatsRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->telemetry_getTelemetryOperationStatsRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_startTelemetryReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    telemetrystartTelemetryProtocolRequestData_t *fullrequest = (telemetrystartTelemetryProtocolRequestData_t *) fp_DataInfo->pu8Data;
    telemetrystartTelemetryRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(telemetrystartTelemetryProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (telemetrystartTelemetryRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->telemetry_startTelemetryRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->telemetry_startTelemetryRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_stopTelemetryReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    telemetrystopTelemetryProtocolRequestData_t *fullrequest = (telemetrystopTelemetryProtocolRequestData_t *) fp_DataInfo->pu8Data;
    telemetrystopTelemetryRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(telemetrystopTelemetryProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (telemetrystopTelemetryRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->telemetry_stopTelemetryRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->telemetry_stopTelemetryRequestHandler(&requestCtx,
                                        requestPayload);
    }
}


/**********************************************************************
 *
 *  Public methods implementation
 *
 **********************************************************************/
void telemetry_registerServerApi(telemetry_ServerApi_t *pSrvApiHandlers)
{
    pSrvApiHnd = pSrvApiHandlers;
}

ESSA_pStack_FunctionProtocolInfo_t telemetry_getServerProtocolDescriptor(void)
{
    return (ESSA_pStack_FunctionProtocolInfo_t) &FP_telemetryProtocolServerInfo;
}

ESSATMAC_ErrCodes telemetry_getTelemetryGeneralConfigResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes,
                const TELEMETRY_tlm_general_cfg_t * const sCfg
)
{
#ifndef BIG_ENDIAN_PLATFORM
    telemetrygetTelemetryGeneralConfigProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(telemetrygetTelemetryGeneralConfigProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(telemetrygetTelemetryGeneralConfigProtocolResponseData_t);

    if ((ctx != NULL) && (sCfg != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY;
        responseParams.hdr.funcId  = TELEMETRY_GETTELEMETRYGENERALCONFIG_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eRes = eRes;
        if (sCfg != NULL)
        {
            responseParams.data.sCfg = *(sCfg);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sCfg,
                          0U,
                          sizeof(responseParams.data.sCfg));
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
                                            sizeof(telemetrygetTelemetryGeneralConfigProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes telemetry_setTelemetryGeneralConfigResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes
)
{
#ifndef BIG_ENDIAN_PLATFORM
    telemetrysetTelemetryGeneralConfigProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(telemetrysetTelemetryGeneralConfigProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(telemetrysetTelemetryGeneralConfigProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY;
        responseParams.hdr.funcId  = TELEMETRY_SETTELEMETRYGENERALCONFIG_FUNCRESP_ID;
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
                                            sizeof(telemetrysetTelemetryGeneralConfigProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes telemetry_getTelemetryPresetConfigResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes,
                const uint8_t u8Slot_preset_cnt,
                const uint8_t u8Max_tlm_msg_cnt,
                const TELEMETRY_tlm_preset_cfg_t * const asTelemetry_preset_cfg
)
{
#ifndef BIG_ENDIAN_PLATFORM
    telemetrygetTelemetryPresetConfigProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(telemetrygetTelemetryPresetConfigProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(telemetrygetTelemetryPresetConfigProtocolResponseData_t);

    if ((ctx != NULL) && (asTelemetry_preset_cfg != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY;
        responseParams.hdr.funcId  = TELEMETRY_GETTELEMETRYPRESETCONFIG_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eRes = eRes;
        responseParams.data.u8Slot_preset_cnt = u8Slot_preset_cnt;
        responseParams.data.u8Max_tlm_msg_cnt = u8Max_tlm_msg_cnt;
        if (asTelemetry_preset_cfg != NULL)
        {
            (void) memcpy((void *) &responseParams.data.asTelemetry_preset_cfg,
                          (const void *) asTelemetry_preset_cfg,
                          sizeof(responseParams.data.asTelemetry_preset_cfg));
        }
        else
        {
            (void) memset((void *) &responseParams.data.asTelemetry_preset_cfg,
                          0U,
                          sizeof(responseParams.data.asTelemetry_preset_cfg));
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
                                            sizeof(telemetrygetTelemetryPresetConfigProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes telemetry_setTelemetryPresetConfigResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes
)
{
#ifndef BIG_ENDIAN_PLATFORM
    telemetrysetTelemetryPresetConfigProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(telemetrysetTelemetryPresetConfigProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(telemetrysetTelemetryPresetConfigProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY;
        responseParams.hdr.funcId  = TELEMETRY_SETTELEMETRYPRESETCONFIG_FUNCRESP_ID;
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
                                            sizeof(telemetrysetTelemetryPresetConfigProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes telemetry_setActivePresetResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes,
                const uint8_t u8Avail_presets_cnt
)
{
#ifndef BIG_ENDIAN_PLATFORM
    telemetrysetActivePresetProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(telemetrysetActivePresetProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(telemetrysetActivePresetProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY;
        responseParams.hdr.funcId  = TELEMETRY_SETACTIVEPRESET_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eRes = eRes;
        responseParams.data.u8Avail_presets_cnt = u8Avail_presets_cnt;
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
                                            sizeof(telemetrysetActivePresetProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes telemetry_getActivePresetResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes,
                const uint8_t u8Active_preset_id
)
{
#ifndef BIG_ENDIAN_PLATFORM
    telemetrygetActivePresetProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(telemetrygetActivePresetProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(telemetrygetActivePresetProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY;
        responseParams.hdr.funcId  = TELEMETRY_GETACTIVEPRESET_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eRes = eRes;
        responseParams.data.u8Active_preset_id = u8Active_preset_id;
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
                                            sizeof(telemetrygetActivePresetProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes telemetry_restoreActivePresetResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes
)
{
#ifndef BIG_ENDIAN_PLATFORM
    telemetryrestoreActivePresetProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(telemetryrestoreActivePresetProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(telemetryrestoreActivePresetProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY;
        responseParams.hdr.funcId  = TELEMETRY_RESTOREACTIVEPRESET_FUNCRESP_ID;
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
                                            sizeof(telemetryrestoreActivePresetProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes telemetry_getTelemetryFileSinkConfigResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes,
                const TELEMETRY_tlm_file_logging_type_t eActive_file_cfg_type,
                const TELEMETRY_tlm_file_size_limit_cfg_t * const sSize_limit_cfg
)
{
#ifndef BIG_ENDIAN_PLATFORM
    telemetrygetTelemetryFileSinkConfigProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(telemetrygetTelemetryFileSinkConfigProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(telemetrygetTelemetryFileSinkConfigProtocolResponseData_t);

    if ((ctx != NULL) && (sSize_limit_cfg != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY;
        responseParams.hdr.funcId  = TELEMETRY_GETTELEMETRYFILESINKCONFIG_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eRes = eRes;
        responseParams.data.eActive_file_cfg_type = eActive_file_cfg_type;
        if (sSize_limit_cfg != NULL)
        {
            responseParams.data.sSize_limit_cfg = *(sSize_limit_cfg);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sSize_limit_cfg,
                          0U,
                          sizeof(responseParams.data.sSize_limit_cfg));
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
                                            sizeof(telemetrygetTelemetryFileSinkConfigProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes telemetry_setTelemetryFileSzLimitConfigResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes
)
{
#ifndef BIG_ENDIAN_PLATFORM
    telemetrysetTelemetryFileSzLimitConfigProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(telemetrysetTelemetryFileSzLimitConfigProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(telemetrysetTelemetryFileSzLimitConfigProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY;
        responseParams.hdr.funcId  = TELEMETRY_SETTELEMETRYFILESZLIMITCONFIG_FUNCRESP_ID;
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
                                            sizeof(telemetrysetTelemetryFileSzLimitConfigProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes telemetry_cleanTelemetryFilesResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes
)
{
#ifndef BIG_ENDIAN_PLATFORM
    telemetrycleanTelemetryFilesProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(telemetrycleanTelemetryFilesProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(telemetrycleanTelemetryFilesProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY;
        responseParams.hdr.funcId  = TELEMETRY_CLEANTELEMETRYFILES_FUNCRESP_ID;
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
                                            sizeof(telemetrycleanTelemetryFilesProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes telemetry_getTelemetryOperationStatsResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes,
                const TELEMETRY_tlm_stats_t * const sTelemetry_stats
)
{
#ifndef BIG_ENDIAN_PLATFORM
    telemetrygetTelemetryOperationStatsProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(telemetrygetTelemetryOperationStatsProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(telemetrygetTelemetryOperationStatsProtocolResponseData_t);

    if ((ctx != NULL) && (sTelemetry_stats != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY;
        responseParams.hdr.funcId  = TELEMETRY_GETTELEMETRYOPERATIONSTATS_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eRes = eRes;
        if (sTelemetry_stats != NULL)
        {
            responseParams.data.sTelemetry_stats = *(sTelemetry_stats);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sTelemetry_stats,
                          0U,
                          sizeof(responseParams.data.sTelemetry_stats));
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
                                            sizeof(telemetrygetTelemetryOperationStatsProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes telemetry_startTelemetryResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes
)
{
#ifndef BIG_ENDIAN_PLATFORM
    telemetrystartTelemetryProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(telemetrystartTelemetryProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(telemetrystartTelemetryProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY;
        responseParams.hdr.funcId  = TELEMETRY_STARTTELEMETRY_FUNCRESP_ID;
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
                                            sizeof(telemetrystartTelemetryProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes telemetry_stopTelemetryResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes
)
{
#ifndef BIG_ENDIAN_PLATFORM
    telemetrystopTelemetryProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(telemetrystopTelemetryProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(telemetrystopTelemetryProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY;
        responseParams.hdr.funcId  = TELEMETRY_STOPTELEMETRY_FUNCRESP_ID;
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
                                            sizeof(telemetrystopTelemetryProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}


