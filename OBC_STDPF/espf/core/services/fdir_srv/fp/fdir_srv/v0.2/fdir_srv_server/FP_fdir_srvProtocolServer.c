/*!
********************************************************************************************
* @file FP_fdir_srvProtocolServer.c
* @brief ESSA Stack server-side implementation
********************************************************************************************
* @version           interface fdir_srv v0.2
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

#include "FP_fdir_srvProtocolServer.h"
#include "FP_common/FP_ProtocolServerCommon.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Local type definitions
 *
 **********************************************************************/
typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT fdir_srvget_system_fdir_levelProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvget_system_fdir_levelResponseData_t data;
} PACKED_STRUCT fdir_srvget_system_fdir_levelProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvget_agent_fdir_levelRequestData_t data;
} PACKED_STRUCT fdir_srvget_agent_fdir_levelProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvget_agent_fdir_levelResponseData_t data;
} PACKED_STRUCT fdir_srvget_agent_fdir_levelProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvget_detection_for_faultRequestData_t data;
} PACKED_STRUCT fdir_srvget_detection_for_faultProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvget_detection_for_faultResponseData_t data;
} PACKED_STRUCT fdir_srvget_detection_for_faultProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvset_detection_for_faultRequestData_t data;
} PACKED_STRUCT fdir_srvset_detection_for_faultProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvset_detection_for_faultResponseData_t data;
} PACKED_STRUCT fdir_srvset_detection_for_faultProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvset_detection_for_all_faultsRequestData_t data;
} PACKED_STRUCT fdir_srvset_detection_for_all_faultsProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvset_detection_for_all_faultsResponseData_t data;
} PACKED_STRUCT fdir_srvset_detection_for_all_faultsProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT fdir_srvget_min_active_fdirProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvget_min_active_fdirResponseData_t data;
} PACKED_STRUCT fdir_srvget_min_active_fdirProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvset_min_active_fdirRequestData_t data;
} PACKED_STRUCT fdir_srvset_min_active_fdirProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvset_min_active_fdirResponseData_t data;
} PACKED_STRUCT fdir_srvset_min_active_fdirProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT fdir_srvget_fault_user_clear_levelProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvget_fault_user_clear_levelResponseData_t data;
} PACKED_STRUCT fdir_srvget_fault_user_clear_levelProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvset_fault_user_clear_levelRequestData_t data;
} PACKED_STRUCT fdir_srvset_fault_user_clear_levelProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvset_fault_user_clear_levelResponseData_t data;
} PACKED_STRUCT fdir_srvset_fault_user_clear_levelProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvget_faultRequestData_t data;
} PACKED_STRUCT fdir_srvget_faultProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvget_faultResponseData_t data;
} PACKED_STRUCT fdir_srvget_faultProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvset_faultRequestData_t data;
} PACKED_STRUCT fdir_srvset_faultProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvset_faultResponseData_t data;
} PACKED_STRUCT fdir_srvset_faultProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvforce_clear_faultRequestData_t data;
} PACKED_STRUCT fdir_srvforce_clear_faultProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvforce_clear_faultResponseData_t data;
} PACKED_STRUCT fdir_srvforce_clear_faultProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT fdir_srvforce_clear_all_faultsProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    fdir_srvforce_clear_all_faultsResponseData_t data;
} PACKED_STRUCT fdir_srvforce_clear_all_faultsProtocolResponseData_t;


/**********************************************************************
 *
 *  Static methods declarations
 *
 **********************************************************************/
static bool fs_HandleData(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_system_fdir_levelReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_agent_fdir_levelReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_detection_for_faultReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_detection_for_faultReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_detection_for_all_faultsReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_min_active_fdirReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_min_active_fdirReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_fault_user_clear_levelReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_fault_user_clear_levelReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_faultReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_faultReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_force_clear_faultReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_force_clear_all_faultsReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);

/**********************************************************************
 *
 *  Public variable definitions
 *
 **********************************************************************/
const ESSA_Stack_FunctionProtocolInfo_t FP_fdir_srvProtocolServerInfo = {
    .u16ProtocolId    = ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV,
        .pfDataHandlerCbk = &fs_HandleData
};

/**********************************************************************
 *
 *  Static variable definitions
 *
 **********************************************************************/
static fdir_srv_ServerApi_t *pSrvApiHnd = NULL;

static const ProtocolFuncArrayEntry_t fs_aFuncArray[] = {
    { FDIR_SRV_GET_SYSTEM_FDIR_LEVEL_FUNC_ID, fs_get_system_fdir_levelReq },
    { FDIR_SRV_GET_AGENT_FDIR_LEVEL_FUNC_ID, fs_get_agent_fdir_levelReq },
    { FDIR_SRV_GET_DETECTION_FOR_FAULT_FUNC_ID, fs_get_detection_for_faultReq },
    { FDIR_SRV_SET_DETECTION_FOR_FAULT_FUNC_ID, fs_set_detection_for_faultReq },
    { FDIR_SRV_SET_DETECTION_FOR_ALL_FAULTS_FUNC_ID, fs_set_detection_for_all_faultsReq },
    { FDIR_SRV_GET_MIN_ACTIVE_FDIR_FUNC_ID, fs_get_min_active_fdirReq },
    { FDIR_SRV_SET_MIN_ACTIVE_FDIR_FUNC_ID, fs_set_min_active_fdirReq },
    { FDIR_SRV_GET_FAULT_USER_CLEAR_LEVEL_FUNC_ID, fs_get_fault_user_clear_levelReq },
    { FDIR_SRV_SET_FAULT_USER_CLEAR_LEVEL_FUNC_ID, fs_set_fault_user_clear_levelReq },
    { FDIR_SRV_GET_FAULT_FUNC_ID, fs_get_faultReq },
    { FDIR_SRV_SET_FAULT_FUNC_ID, fs_set_faultReq },
    { FDIR_SRV_FORCE_CLEAR_FAULT_FUNC_ID, fs_force_clear_faultReq },
    { FDIR_SRV_FORCE_CLEAR_ALL_FAULTS_FUNC_ID, fs_force_clear_all_faultsReq }
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







static void fs_get_system_fdir_levelReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    fdir_srvget_system_fdir_levelProtocolRequestData_t *fullrequest = (fdir_srvget_system_fdir_levelProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvget_system_fdir_levelProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->fdir_srv_get_system_fdir_levelRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->fdir_srv_get_system_fdir_levelRequestHandler(&requestCtx);
    }
}

static void fs_get_agent_fdir_levelReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    fdir_srvget_agent_fdir_levelProtocolRequestData_t *fullrequest = (fdir_srvget_agent_fdir_levelProtocolRequestData_t *) fp_DataInfo->pu8Data;
    fdir_srvget_agent_fdir_levelRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvget_agent_fdir_levelProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (fdir_srvget_agent_fdir_levelRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->fdir_srv_get_agent_fdir_levelRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->fdir_srv_get_agent_fdir_levelRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_detection_for_faultReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    fdir_srvget_detection_for_faultProtocolRequestData_t *fullrequest = (fdir_srvget_detection_for_faultProtocolRequestData_t *) fp_DataInfo->pu8Data;
    fdir_srvget_detection_for_faultRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvget_detection_for_faultProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (fdir_srvget_detection_for_faultRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->fdir_srv_get_detection_for_faultRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->fdir_srv_get_detection_for_faultRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_set_detection_for_faultReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    fdir_srvset_detection_for_faultProtocolRequestData_t *fullrequest = (fdir_srvset_detection_for_faultProtocolRequestData_t *) fp_DataInfo->pu8Data;
    fdir_srvset_detection_for_faultRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvset_detection_for_faultProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (fdir_srvset_detection_for_faultRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->fdir_srv_set_detection_for_faultRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->fdir_srv_set_detection_for_faultRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_set_detection_for_all_faultsReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    fdir_srvset_detection_for_all_faultsProtocolRequestData_t *fullrequest = (fdir_srvset_detection_for_all_faultsProtocolRequestData_t *) fp_DataInfo->pu8Data;
    fdir_srvset_detection_for_all_faultsRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvset_detection_for_all_faultsProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (fdir_srvset_detection_for_all_faultsRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->fdir_srv_set_detection_for_all_faultsRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->fdir_srv_set_detection_for_all_faultsRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_min_active_fdirReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    fdir_srvget_min_active_fdirProtocolRequestData_t *fullrequest = (fdir_srvget_min_active_fdirProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvget_min_active_fdirProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->fdir_srv_get_min_active_fdirRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->fdir_srv_get_min_active_fdirRequestHandler(&requestCtx);
    }
}

static void fs_set_min_active_fdirReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    fdir_srvset_min_active_fdirProtocolRequestData_t *fullrequest = (fdir_srvset_min_active_fdirProtocolRequestData_t *) fp_DataInfo->pu8Data;
    fdir_srvset_min_active_fdirRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvset_min_active_fdirProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (fdir_srvset_min_active_fdirRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->fdir_srv_set_min_active_fdirRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->fdir_srv_set_min_active_fdirRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_fault_user_clear_levelReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    fdir_srvget_fault_user_clear_levelProtocolRequestData_t *fullrequest = (fdir_srvget_fault_user_clear_levelProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvget_fault_user_clear_levelProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->fdir_srv_get_fault_user_clear_levelRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->fdir_srv_get_fault_user_clear_levelRequestHandler(&requestCtx);
    }
}

static void fs_set_fault_user_clear_levelReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    fdir_srvset_fault_user_clear_levelProtocolRequestData_t *fullrequest = (fdir_srvset_fault_user_clear_levelProtocolRequestData_t *) fp_DataInfo->pu8Data;
    fdir_srvset_fault_user_clear_levelRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvset_fault_user_clear_levelProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (fdir_srvset_fault_user_clear_levelRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->fdir_srv_set_fault_user_clear_levelRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->fdir_srv_set_fault_user_clear_levelRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_faultReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    fdir_srvget_faultProtocolRequestData_t *fullrequest = (fdir_srvget_faultProtocolRequestData_t *) fp_DataInfo->pu8Data;
    fdir_srvget_faultRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvget_faultProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (fdir_srvget_faultRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->fdir_srv_get_faultRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->fdir_srv_get_faultRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_set_faultReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    fdir_srvset_faultProtocolRequestData_t *fullrequest = (fdir_srvset_faultProtocolRequestData_t *) fp_DataInfo->pu8Data;
    fdir_srvset_faultRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvset_faultProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (fdir_srvset_faultRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->fdir_srv_set_faultRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->fdir_srv_set_faultRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_force_clear_faultReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    fdir_srvforce_clear_faultProtocolRequestData_t *fullrequest = (fdir_srvforce_clear_faultProtocolRequestData_t *) fp_DataInfo->pu8Data;
    fdir_srvforce_clear_faultRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvforce_clear_faultProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (fdir_srvforce_clear_faultRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->fdir_srv_force_clear_faultRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->fdir_srv_force_clear_faultRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_force_clear_all_faultsReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    fdir_srvforce_clear_all_faultsProtocolRequestData_t *fullrequest = (fdir_srvforce_clear_all_faultsProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvforce_clear_all_faultsProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->fdir_srv_force_clear_all_faultsRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->fdir_srv_force_clear_all_faultsRequestHandler(&requestCtx);
    }
}


/**********************************************************************
 *
 *  Public methods implementation
 *
 **********************************************************************/
void fdir_srv_registerServerApi(fdir_srv_ServerApi_t *pSrvApiHandlers)
{
    pSrvApiHnd = pSrvApiHandlers;
}

ESSA_pStack_FunctionProtocolInfo_t fdir_srv_getServerProtocolDescriptor(void)
{
    return (ESSA_pStack_FunctionProtocolInfo_t) &FP_fdir_srvProtocolServerInfo;
}

ESSATMAC_ErrCodes fdir_srv_get_system_fdir_levelResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const uint8_t u8Fdir_level
)
{
#ifndef BIG_ENDIAN_PLATFORM
    fdir_srvget_system_fdir_levelProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(fdir_srvget_system_fdir_levelProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvget_system_fdir_levelProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV;
        responseParams.hdr.funcId  = FDIR_SRV_GET_SYSTEM_FDIR_LEVEL_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eStatus = eStatus;
        responseParams.data.u8Fdir_level = u8Fdir_level;
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
                                            sizeof(fdir_srvget_system_fdir_levelProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes fdir_srv_get_agent_fdir_levelResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const uint8_t u8Fdir_level
)
{
#ifndef BIG_ENDIAN_PLATFORM
    fdir_srvget_agent_fdir_levelProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(fdir_srvget_agent_fdir_levelProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvget_agent_fdir_levelProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV;
        responseParams.hdr.funcId  = FDIR_SRV_GET_AGENT_FDIR_LEVEL_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eStatus = eStatus;
        responseParams.data.u8Fdir_level = u8Fdir_level;
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
                                            sizeof(fdir_srvget_agent_fdir_levelProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes fdir_srv_get_detection_for_faultResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const bool bDetection_enabled
)
{
#ifndef BIG_ENDIAN_PLATFORM
    fdir_srvget_detection_for_faultProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(fdir_srvget_detection_for_faultProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvget_detection_for_faultProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV;
        responseParams.hdr.funcId  = FDIR_SRV_GET_DETECTION_FOR_FAULT_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eStatus = eStatus;
        responseParams.data.bDetection_enabled = bDetection_enabled;
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
                                            sizeof(fdir_srvget_detection_for_faultProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes fdir_srv_set_detection_for_faultResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const bool bDetection_enabled
)
{
#ifndef BIG_ENDIAN_PLATFORM
    fdir_srvset_detection_for_faultProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(fdir_srvset_detection_for_faultProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvset_detection_for_faultProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV;
        responseParams.hdr.funcId  = FDIR_SRV_SET_DETECTION_FOR_FAULT_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eStatus = eStatus;
        responseParams.data.bDetection_enabled = bDetection_enabled;
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
                                            sizeof(fdir_srvset_detection_for_faultProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes fdir_srv_set_detection_for_all_faultsResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const uint16_t u16Fault_id
)
{
#ifndef BIG_ENDIAN_PLATFORM
    fdir_srvset_detection_for_all_faultsProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(fdir_srvset_detection_for_all_faultsProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvset_detection_for_all_faultsProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV;
        responseParams.hdr.funcId  = FDIR_SRV_SET_DETECTION_FOR_ALL_FAULTS_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eStatus = eStatus;
        responseParams.data.u16Fault_id = u16Fault_id;
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
                                            sizeof(fdir_srvset_detection_for_all_faultsProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes fdir_srv_get_min_active_fdirResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const uint8_t u8Fdir_level_set
)
{
#ifndef BIG_ENDIAN_PLATFORM
    fdir_srvget_min_active_fdirProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(fdir_srvget_min_active_fdirProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvget_min_active_fdirProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV;
        responseParams.hdr.funcId  = FDIR_SRV_GET_MIN_ACTIVE_FDIR_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eStatus = eStatus;
        responseParams.data.u8Fdir_level_set = u8Fdir_level_set;
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
                                            sizeof(fdir_srvget_min_active_fdirProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes fdir_srv_set_min_active_fdirResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const uint8_t u8Fdir_level_set
)
{
#ifndef BIG_ENDIAN_PLATFORM
    fdir_srvset_min_active_fdirProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(fdir_srvset_min_active_fdirProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvset_min_active_fdirProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV;
        responseParams.hdr.funcId  = FDIR_SRV_SET_MIN_ACTIVE_FDIR_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eStatus = eStatus;
        responseParams.data.u8Fdir_level_set = u8Fdir_level_set;
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
                                            sizeof(fdir_srvset_min_active_fdirProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes fdir_srv_get_fault_user_clear_levelResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const uint8_t u8Fdir_level
)
{
#ifndef BIG_ENDIAN_PLATFORM
    fdir_srvget_fault_user_clear_levelProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(fdir_srvget_fault_user_clear_levelProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvget_fault_user_clear_levelProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV;
        responseParams.hdr.funcId  = FDIR_SRV_GET_FAULT_USER_CLEAR_LEVEL_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eStatus = eStatus;
        responseParams.data.u8Fdir_level = u8Fdir_level;
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
                                            sizeof(fdir_srvget_fault_user_clear_levelProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes fdir_srv_set_fault_user_clear_levelResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const uint8_t u8Fdir_level_set
)
{
#ifndef BIG_ENDIAN_PLATFORM
    fdir_srvset_fault_user_clear_levelProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(fdir_srvset_fault_user_clear_levelProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvset_fault_user_clear_levelProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV;
        responseParams.hdr.funcId  = FDIR_SRV_SET_FAULT_USER_CLEAR_LEVEL_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eStatus = eStatus;
        responseParams.data.u8Fdir_level_set = u8Fdir_level_set;
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
                                            sizeof(fdir_srvset_fault_user_clear_levelProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes fdir_srv_get_faultResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const bool bIs_active,
                const uint8_t u8Fdir_level
)
{
#ifndef BIG_ENDIAN_PLATFORM
    fdir_srvget_faultProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(fdir_srvget_faultProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvget_faultProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV;
        responseParams.hdr.funcId  = FDIR_SRV_GET_FAULT_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eStatus = eStatus;
        responseParams.data.bIs_active = bIs_active;
        responseParams.data.u8Fdir_level = u8Fdir_level;
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
                                            sizeof(fdir_srvget_faultProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes fdir_srv_set_faultResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus
)
{
#ifndef BIG_ENDIAN_PLATFORM
    fdir_srvset_faultProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(fdir_srvset_faultProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvset_faultProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV;
        responseParams.hdr.funcId  = FDIR_SRV_SET_FAULT_FUNCRESP_ID;
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
                                            sizeof(fdir_srvset_faultProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes fdir_srv_force_clear_faultResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus
)
{
#ifndef BIG_ENDIAN_PLATFORM
    fdir_srvforce_clear_faultProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(fdir_srvforce_clear_faultProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvforce_clear_faultProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV;
        responseParams.hdr.funcId  = FDIR_SRV_FORCE_CLEAR_FAULT_FUNCRESP_ID;
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
                                            sizeof(fdir_srvforce_clear_faultProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes fdir_srv_force_clear_all_faultsResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const uint16_t u16Fault_id
)
{
#ifndef BIG_ENDIAN_PLATFORM
    fdir_srvforce_clear_all_faultsProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(fdir_srvforce_clear_all_faultsProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(fdir_srvforce_clear_all_faultsProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV;
        responseParams.hdr.funcId  = FDIR_SRV_FORCE_CLEAR_ALL_FAULTS_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eStatus = eStatus;
        responseParams.data.u16Fault_id = u16Fault_id;
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
                                            sizeof(fdir_srvforce_clear_all_faultsProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}


