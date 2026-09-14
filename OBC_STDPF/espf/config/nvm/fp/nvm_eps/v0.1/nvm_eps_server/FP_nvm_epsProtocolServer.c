/*!
********************************************************************************************
* @file FP_nvm_epsProtocolServer.c
* @brief ESSA Stack server-side implementation
********************************************************************************************
* @version           interface nvm_eps v0.1
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

#include "FP_nvm_epsProtocolServer.h"
#include "FP_common/FP_ProtocolServerCommon.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Local type definitions
 *
 **********************************************************************/
typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsset_eps2_bp_mac_addressRequestData_t data;
} PACKED_STRUCT nvm_epsset_eps2_bp_mac_addressProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsset_eps2_bp_mac_addressResponseData_t data;
} PACKED_STRUCT nvm_epsset_eps2_bp_mac_addressProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsget_eps2_bp_mac_addressRequestData_t data;
} PACKED_STRUCT nvm_epsget_eps2_bp_mac_addressProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsget_eps2_bp_mac_addressResponseData_t data;
} PACKED_STRUCT nvm_epsget_eps2_bp_mac_addressProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsset_eps3_bp_mac_addressesRequestData_t data;
} PACKED_STRUCT nvm_epsset_eps3_bp_mac_addressesProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsset_eps3_bp_mac_addressesResponseData_t data;
} PACKED_STRUCT nvm_epsset_eps3_bp_mac_addressesProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsget_eps3_bp_mac_addressesRequestData_t data;
} PACKED_STRUCT nvm_epsget_eps3_bp_mac_addressesProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsget_eps3_bp_mac_addressesResponseData_t data;
} PACKED_STRUCT nvm_epsget_eps3_bp_mac_addressesProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsset_eps3_pdm_a_mac_addressesRequestData_t data;
} PACKED_STRUCT nvm_epsset_eps3_pdm_a_mac_addressesProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsset_eps3_pdm_a_mac_addressesResponseData_t data;
} PACKED_STRUCT nvm_epsset_eps3_pdm_a_mac_addressesProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsget_eps3_pdm_a_mac_addressesRequestData_t data;
} PACKED_STRUCT nvm_epsget_eps3_pdm_a_mac_addressesProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsget_eps3_pdm_a_mac_addressesResponseData_t data;
} PACKED_STRUCT nvm_epsget_eps3_pdm_a_mac_addressesProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsset_eps3_pdm_b_mac_addressesRequestData_t data;
} PACKED_STRUCT nvm_epsset_eps3_pdm_b_mac_addressesProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsset_eps3_pdm_b_mac_addressesResponseData_t data;
} PACKED_STRUCT nvm_epsset_eps3_pdm_b_mac_addressesProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsget_eps3_pdm_b_mac_addressesRequestData_t data;
} PACKED_STRUCT nvm_epsget_eps3_pdm_b_mac_addressesProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsget_eps3_pdm_b_mac_addressesResponseData_t data;
} PACKED_STRUCT nvm_epsget_eps3_pdm_b_mac_addressesProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsset_eps3_expander_mac_addressesRequestData_t data;
} PACKED_STRUCT nvm_epsset_eps3_expander_mac_addressesProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsset_eps3_expander_mac_addressesResponseData_t data;
} PACKED_STRUCT nvm_epsset_eps3_expander_mac_addressesProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsget_eps3_expander_mac_addressesRequestData_t data;
} PACKED_STRUCT nvm_epsget_eps3_expander_mac_addressesProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsget_eps3_expander_mac_addressesResponseData_t data;
} PACKED_STRUCT nvm_epsget_eps3_expander_mac_addressesProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsset_eps3_input_stage_mac_addressesRequestData_t data;
} PACKED_STRUCT nvm_epsset_eps3_input_stage_mac_addressesProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsset_eps3_input_stage_mac_addressesResponseData_t data;
} PACKED_STRUCT nvm_epsset_eps3_input_stage_mac_addressesProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsget_eps3_input_stage_mac_addressesRequestData_t data;
} PACKED_STRUCT nvm_epsget_eps3_input_stage_mac_addressesProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    nvm_epsget_eps3_input_stage_mac_addressesResponseData_t data;
} PACKED_STRUCT nvm_epsget_eps3_input_stage_mac_addressesProtocolResponseData_t;


/**********************************************************************
 *
 *  Static methods declarations
 *
 **********************************************************************/
static bool fs_HandleData(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_eps2_bp_mac_addressReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_eps2_bp_mac_addressReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_eps3_bp_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_eps3_bp_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_eps3_pdm_a_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_eps3_pdm_a_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_eps3_pdm_b_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_eps3_pdm_b_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_eps3_expander_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_eps3_expander_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_eps3_input_stage_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_eps3_input_stage_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);

/**********************************************************************
 *
 *  Public variable definitions
 *
 **********************************************************************/
const ESSA_Stack_FunctionProtocolInfo_t FP_nvm_epsProtocolServerInfo = {
    .u16ProtocolId    = ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS,
        .pfDataHandlerCbk = &fs_HandleData
};

/**********************************************************************
 *
 *  Static variable definitions
 *
 **********************************************************************/
static nvm_eps_ServerApi_t *pSrvApiHnd = NULL;

static const ProtocolFuncArrayEntry_t fs_aFuncArray[] = {
    { NVM_EPS_SET_EPS2_BP_MAC_ADDRESS_FUNC_ID, fs_set_eps2_bp_mac_addressReq },
    { NVM_EPS_GET_EPS2_BP_MAC_ADDRESS_FUNC_ID, fs_get_eps2_bp_mac_addressReq },
    { NVM_EPS_SET_EPS3_BP_MAC_ADDRESSES_FUNC_ID, fs_set_eps3_bp_mac_addressesReq },
    { NVM_EPS_GET_EPS3_BP_MAC_ADDRESSES_FUNC_ID, fs_get_eps3_bp_mac_addressesReq },
    { NVM_EPS_SET_EPS3_PDM_A_MAC_ADDRESSES_FUNC_ID, fs_set_eps3_pdm_a_mac_addressesReq },
    { NVM_EPS_GET_EPS3_PDM_A_MAC_ADDRESSES_FUNC_ID, fs_get_eps3_pdm_a_mac_addressesReq },
    { NVM_EPS_SET_EPS3_PDM_B_MAC_ADDRESSES_FUNC_ID, fs_set_eps3_pdm_b_mac_addressesReq },
    { NVM_EPS_GET_EPS3_PDM_B_MAC_ADDRESSES_FUNC_ID, fs_get_eps3_pdm_b_mac_addressesReq },
    { NVM_EPS_SET_EPS3_EXPANDER_MAC_ADDRESSES_FUNC_ID, fs_set_eps3_expander_mac_addressesReq },
    { NVM_EPS_GET_EPS3_EXPANDER_MAC_ADDRESSES_FUNC_ID, fs_get_eps3_expander_mac_addressesReq },
    { NVM_EPS_SET_EPS3_INPUT_STAGE_MAC_ADDRESSES_FUNC_ID, fs_set_eps3_input_stage_mac_addressesReq },
    { NVM_EPS_GET_EPS3_INPUT_STAGE_MAC_ADDRESSES_FUNC_ID, fs_get_eps3_input_stage_mac_addressesReq }
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







static void fs_set_eps2_bp_mac_addressReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    nvm_epsset_eps2_bp_mac_addressProtocolRequestData_t *fullrequest = (nvm_epsset_eps2_bp_mac_addressProtocolRequestData_t *) fp_DataInfo->pu8Data;
    nvm_epsset_eps2_bp_mac_addressRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsset_eps2_bp_mac_addressProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (nvm_epsset_eps2_bp_mac_addressRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->nvm_eps_set_eps2_bp_mac_addressRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->nvm_eps_set_eps2_bp_mac_addressRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_eps2_bp_mac_addressReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    nvm_epsget_eps2_bp_mac_addressProtocolRequestData_t *fullrequest = (nvm_epsget_eps2_bp_mac_addressProtocolRequestData_t *) fp_DataInfo->pu8Data;
    nvm_epsget_eps2_bp_mac_addressRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsget_eps2_bp_mac_addressProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (nvm_epsget_eps2_bp_mac_addressRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->nvm_eps_get_eps2_bp_mac_addressRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->nvm_eps_get_eps2_bp_mac_addressRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_set_eps3_bp_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    nvm_epsset_eps3_bp_mac_addressesProtocolRequestData_t *fullrequest = (nvm_epsset_eps3_bp_mac_addressesProtocolRequestData_t *) fp_DataInfo->pu8Data;
    nvm_epsset_eps3_bp_mac_addressesRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsset_eps3_bp_mac_addressesProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (nvm_epsset_eps3_bp_mac_addressesRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->nvm_eps_set_eps3_bp_mac_addressesRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->nvm_eps_set_eps3_bp_mac_addressesRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_eps3_bp_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    nvm_epsget_eps3_bp_mac_addressesProtocolRequestData_t *fullrequest = (nvm_epsget_eps3_bp_mac_addressesProtocolRequestData_t *) fp_DataInfo->pu8Data;
    nvm_epsget_eps3_bp_mac_addressesRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsget_eps3_bp_mac_addressesProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (nvm_epsget_eps3_bp_mac_addressesRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->nvm_eps_get_eps3_bp_mac_addressesRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->nvm_eps_get_eps3_bp_mac_addressesRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_set_eps3_pdm_a_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    nvm_epsset_eps3_pdm_a_mac_addressesProtocolRequestData_t *fullrequest = (nvm_epsset_eps3_pdm_a_mac_addressesProtocolRequestData_t *) fp_DataInfo->pu8Data;
    nvm_epsset_eps3_pdm_a_mac_addressesRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsset_eps3_pdm_a_mac_addressesProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (nvm_epsset_eps3_pdm_a_mac_addressesRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->nvm_eps_set_eps3_pdm_a_mac_addressesRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->nvm_eps_set_eps3_pdm_a_mac_addressesRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_eps3_pdm_a_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    nvm_epsget_eps3_pdm_a_mac_addressesProtocolRequestData_t *fullrequest = (nvm_epsget_eps3_pdm_a_mac_addressesProtocolRequestData_t *) fp_DataInfo->pu8Data;
    nvm_epsget_eps3_pdm_a_mac_addressesRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsget_eps3_pdm_a_mac_addressesProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (nvm_epsget_eps3_pdm_a_mac_addressesRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->nvm_eps_get_eps3_pdm_a_mac_addressesRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->nvm_eps_get_eps3_pdm_a_mac_addressesRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_set_eps3_pdm_b_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    nvm_epsset_eps3_pdm_b_mac_addressesProtocolRequestData_t *fullrequest = (nvm_epsset_eps3_pdm_b_mac_addressesProtocolRequestData_t *) fp_DataInfo->pu8Data;
    nvm_epsset_eps3_pdm_b_mac_addressesRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsset_eps3_pdm_b_mac_addressesProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (nvm_epsset_eps3_pdm_b_mac_addressesRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->nvm_eps_set_eps3_pdm_b_mac_addressesRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->nvm_eps_set_eps3_pdm_b_mac_addressesRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_eps3_pdm_b_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    nvm_epsget_eps3_pdm_b_mac_addressesProtocolRequestData_t *fullrequest = (nvm_epsget_eps3_pdm_b_mac_addressesProtocolRequestData_t *) fp_DataInfo->pu8Data;
    nvm_epsget_eps3_pdm_b_mac_addressesRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsget_eps3_pdm_b_mac_addressesProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (nvm_epsget_eps3_pdm_b_mac_addressesRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->nvm_eps_get_eps3_pdm_b_mac_addressesRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->nvm_eps_get_eps3_pdm_b_mac_addressesRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_set_eps3_expander_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    nvm_epsset_eps3_expander_mac_addressesProtocolRequestData_t *fullrequest = (nvm_epsset_eps3_expander_mac_addressesProtocolRequestData_t *) fp_DataInfo->pu8Data;
    nvm_epsset_eps3_expander_mac_addressesRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsset_eps3_expander_mac_addressesProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (nvm_epsset_eps3_expander_mac_addressesRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->nvm_eps_set_eps3_expander_mac_addressesRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->nvm_eps_set_eps3_expander_mac_addressesRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_eps3_expander_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    nvm_epsget_eps3_expander_mac_addressesProtocolRequestData_t *fullrequest = (nvm_epsget_eps3_expander_mac_addressesProtocolRequestData_t *) fp_DataInfo->pu8Data;
    nvm_epsget_eps3_expander_mac_addressesRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsget_eps3_expander_mac_addressesProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (nvm_epsget_eps3_expander_mac_addressesRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->nvm_eps_get_eps3_expander_mac_addressesRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->nvm_eps_get_eps3_expander_mac_addressesRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_set_eps3_input_stage_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    nvm_epsset_eps3_input_stage_mac_addressesProtocolRequestData_t *fullrequest = (nvm_epsset_eps3_input_stage_mac_addressesProtocolRequestData_t *) fp_DataInfo->pu8Data;
    nvm_epsset_eps3_input_stage_mac_addressesRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsset_eps3_input_stage_mac_addressesProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (nvm_epsset_eps3_input_stage_mac_addressesRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->nvm_eps_set_eps3_input_stage_mac_addressesRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->nvm_eps_set_eps3_input_stage_mac_addressesRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_eps3_input_stage_mac_addressesReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    nvm_epsget_eps3_input_stage_mac_addressesProtocolRequestData_t *fullrequest = (nvm_epsget_eps3_input_stage_mac_addressesProtocolRequestData_t *) fp_DataInfo->pu8Data;
    nvm_epsget_eps3_input_stage_mac_addressesRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsget_eps3_input_stage_mac_addressesProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (nvm_epsget_eps3_input_stage_mac_addressesRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->nvm_eps_get_eps3_input_stage_mac_addressesRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->nvm_eps_get_eps3_input_stage_mac_addressesRequestHandler(&requestCtx,
                                        requestPayload);
    }
}


/**********************************************************************
 *
 *  Public methods implementation
 *
 **********************************************************************/
void nvm_eps_registerServerApi(nvm_eps_ServerApi_t *pSrvApiHandlers)
{
    pSrvApiHnd = pSrvApiHandlers;
}

ESSA_pStack_FunctionProtocolInfo_t nvm_eps_getServerProtocolDescriptor(void)
{
    return (ESSA_pStack_FunctionProtocolInfo_t) &FP_nvm_epsProtocolServerInfo;
}

ESSATMAC_ErrCodes nvm_eps_set_eps2_bp_mac_addressResp(
                RespContext_t* ctx,
                const NVM_EPS_StandardResult_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    nvm_epsset_eps2_bp_mac_addressProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(nvm_epsset_eps2_bp_mac_addressProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsset_eps2_bp_mac_addressProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS;
        responseParams.hdr.funcId  = NVM_EPS_SET_EPS2_BP_MAC_ADDRESS_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eOp_result = eOp_result;
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
                                            sizeof(nvm_epsset_eps2_bp_mac_addressProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes nvm_eps_get_eps2_bp_mac_addressResp(
                RespContext_t* ctx,
                const uint8_t u8Mac_address,
                const NVM_EPS_StandardResult_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    nvm_epsget_eps2_bp_mac_addressProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(nvm_epsget_eps2_bp_mac_addressProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsget_eps2_bp_mac_addressProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS;
        responseParams.hdr.funcId  = NVM_EPS_GET_EPS2_BP_MAC_ADDRESS_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.u8Mac_address = u8Mac_address;
        responseParams.data.eOp_result = eOp_result;
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
                                            sizeof(nvm_epsget_eps2_bp_mac_addressProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes nvm_eps_set_eps3_bp_mac_addressesResp(
                RespContext_t* ctx,
                const NVM_EPS_StandardResult_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    nvm_epsset_eps3_bp_mac_addressesProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(nvm_epsset_eps3_bp_mac_addressesProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsset_eps3_bp_mac_addressesProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS;
        responseParams.hdr.funcId  = NVM_EPS_SET_EPS3_BP_MAC_ADDRESSES_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eOp_result = eOp_result;
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
                                            sizeof(nvm_epsset_eps3_bp_mac_addressesProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes nvm_eps_get_eps3_bp_mac_addressesResp(
                RespContext_t* ctx,
                const uint8_t u8Mac_address,
                const NVM_EPS_StandardResult_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    nvm_epsget_eps3_bp_mac_addressesProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(nvm_epsget_eps3_bp_mac_addressesProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsget_eps3_bp_mac_addressesProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS;
        responseParams.hdr.funcId  = NVM_EPS_GET_EPS3_BP_MAC_ADDRESSES_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.u8Mac_address = u8Mac_address;
        responseParams.data.eOp_result = eOp_result;
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
                                            sizeof(nvm_epsget_eps3_bp_mac_addressesProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes nvm_eps_set_eps3_pdm_a_mac_addressesResp(
                RespContext_t* ctx,
                const NVM_EPS_StandardResult_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    nvm_epsset_eps3_pdm_a_mac_addressesProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(nvm_epsset_eps3_pdm_a_mac_addressesProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsset_eps3_pdm_a_mac_addressesProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS;
        responseParams.hdr.funcId  = NVM_EPS_SET_EPS3_PDM_A_MAC_ADDRESSES_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eOp_result = eOp_result;
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
                                            sizeof(nvm_epsset_eps3_pdm_a_mac_addressesProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes nvm_eps_get_eps3_pdm_a_mac_addressesResp(
                RespContext_t* ctx,
                const uint8_t u8Mac_address,
                const NVM_EPS_StandardResult_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    nvm_epsget_eps3_pdm_a_mac_addressesProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(nvm_epsget_eps3_pdm_a_mac_addressesProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsget_eps3_pdm_a_mac_addressesProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS;
        responseParams.hdr.funcId  = NVM_EPS_GET_EPS3_PDM_A_MAC_ADDRESSES_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.u8Mac_address = u8Mac_address;
        responseParams.data.eOp_result = eOp_result;
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
                                            sizeof(nvm_epsget_eps3_pdm_a_mac_addressesProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes nvm_eps_set_eps3_pdm_b_mac_addressesResp(
                RespContext_t* ctx,
                const NVM_EPS_StandardResult_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    nvm_epsset_eps3_pdm_b_mac_addressesProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(nvm_epsset_eps3_pdm_b_mac_addressesProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsset_eps3_pdm_b_mac_addressesProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS;
        responseParams.hdr.funcId  = NVM_EPS_SET_EPS3_PDM_B_MAC_ADDRESSES_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eOp_result = eOp_result;
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
                                            sizeof(nvm_epsset_eps3_pdm_b_mac_addressesProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes nvm_eps_get_eps3_pdm_b_mac_addressesResp(
                RespContext_t* ctx,
                const uint8_t u8Mac_address,
                const NVM_EPS_StandardResult_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    nvm_epsget_eps3_pdm_b_mac_addressesProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(nvm_epsget_eps3_pdm_b_mac_addressesProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsget_eps3_pdm_b_mac_addressesProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS;
        responseParams.hdr.funcId  = NVM_EPS_GET_EPS3_PDM_B_MAC_ADDRESSES_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.u8Mac_address = u8Mac_address;
        responseParams.data.eOp_result = eOp_result;
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
                                            sizeof(nvm_epsget_eps3_pdm_b_mac_addressesProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes nvm_eps_set_eps3_expander_mac_addressesResp(
                RespContext_t* ctx,
                const NVM_EPS_StandardResult_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    nvm_epsset_eps3_expander_mac_addressesProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(nvm_epsset_eps3_expander_mac_addressesProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsset_eps3_expander_mac_addressesProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS;
        responseParams.hdr.funcId  = NVM_EPS_SET_EPS3_EXPANDER_MAC_ADDRESSES_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eOp_result = eOp_result;
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
                                            sizeof(nvm_epsset_eps3_expander_mac_addressesProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes nvm_eps_get_eps3_expander_mac_addressesResp(
                RespContext_t* ctx,
                const uint8_t u8Mac_address,
                const NVM_EPS_StandardResult_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    nvm_epsget_eps3_expander_mac_addressesProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(nvm_epsget_eps3_expander_mac_addressesProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsget_eps3_expander_mac_addressesProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS;
        responseParams.hdr.funcId  = NVM_EPS_GET_EPS3_EXPANDER_MAC_ADDRESSES_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.u8Mac_address = u8Mac_address;
        responseParams.data.eOp_result = eOp_result;
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
                                            sizeof(nvm_epsget_eps3_expander_mac_addressesProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes nvm_eps_set_eps3_input_stage_mac_addressesResp(
                RespContext_t* ctx,
                const NVM_EPS_StandardResult_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    nvm_epsset_eps3_input_stage_mac_addressesProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(nvm_epsset_eps3_input_stage_mac_addressesProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsset_eps3_input_stage_mac_addressesProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS;
        responseParams.hdr.funcId  = NVM_EPS_SET_EPS3_INPUT_STAGE_MAC_ADDRESSES_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eOp_result = eOp_result;
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
                                            sizeof(nvm_epsset_eps3_input_stage_mac_addressesProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes nvm_eps_get_eps3_input_stage_mac_addressesResp(
                RespContext_t* ctx,
                const uint8_t u8Mac_address,
                const NVM_EPS_StandardResult_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    nvm_epsget_eps3_input_stage_mac_addressesProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(nvm_epsget_eps3_input_stage_mac_addressesProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(nvm_epsget_eps3_input_stage_mac_addressesProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS;
        responseParams.hdr.funcId  = NVM_EPS_GET_EPS3_INPUT_STAGE_MAC_ADDRESSES_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.u8Mac_address = u8Mac_address;
        responseParams.data.eOp_result = eOp_result;
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
                                            sizeof(nvm_epsget_eps3_input_stage_mac_addressesProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}


