/*!
********************************************************************************************
* @file FP_nvm_epsServerApp.c
* @brief ServerApp implementation template generator
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

// @START_USER@ USER_INCLUDES
// Place user includes here to preserve them during merge!!!
#include "module_id.h"
#include "nvm.h"
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL

static NVM_EPS_StandardResult_t set_eps3_address(uint8_t new_mac_address, uint8_t device_id);

// @END_USER@ USER_LOCAL_FUNC_DECL
static void nvm_eps_set_eps2_bp_mac_addressRequestHandlerImpl(ReqContext_t* pReqCtx,
            const nvm_epsset_eps2_bp_mac_addressRequestData_t* pRequestData);

static void nvm_eps_get_eps2_bp_mac_addressRequestHandlerImpl(ReqContext_t* pReqCtx,
            const nvm_epsget_eps2_bp_mac_addressRequestData_t* pRequestData);

static void nvm_eps_set_eps3_bp_mac_addressesRequestHandlerImpl(ReqContext_t* pReqCtx,
            const nvm_epsset_eps3_bp_mac_addressesRequestData_t* pRequestData);

static void nvm_eps_get_eps3_bp_mac_addressesRequestHandlerImpl(ReqContext_t* pReqCtx,
            const nvm_epsget_eps3_bp_mac_addressesRequestData_t* pRequestData);

static void nvm_eps_set_eps3_pdm_a_mac_addressesRequestHandlerImpl(ReqContext_t* pReqCtx,
            const nvm_epsset_eps3_pdm_a_mac_addressesRequestData_t* pRequestData);

static void nvm_eps_get_eps3_pdm_a_mac_addressesRequestHandlerImpl(ReqContext_t* pReqCtx,
            const nvm_epsget_eps3_pdm_a_mac_addressesRequestData_t* pRequestData);

static void nvm_eps_set_eps3_pdm_b_mac_addressesRequestHandlerImpl(ReqContext_t* pReqCtx,
            const nvm_epsset_eps3_pdm_b_mac_addressesRequestData_t* pRequestData);

static void nvm_eps_get_eps3_pdm_b_mac_addressesRequestHandlerImpl(ReqContext_t* pReqCtx,
            const nvm_epsget_eps3_pdm_b_mac_addressesRequestData_t* pRequestData);

static void nvm_eps_set_eps3_expander_mac_addressesRequestHandlerImpl(ReqContext_t* pReqCtx,
            const nvm_epsset_eps3_expander_mac_addressesRequestData_t* pRequestData);

static void nvm_eps_get_eps3_expander_mac_addressesRequestHandlerImpl(ReqContext_t* pReqCtx,
            const nvm_epsget_eps3_expander_mac_addressesRequestData_t* pRequestData);

static void nvm_eps_set_eps3_input_stage_mac_addressesRequestHandlerImpl(ReqContext_t* pReqCtx,
            const nvm_epsset_eps3_input_stage_mac_addressesRequestData_t* pRequestData);

static void nvm_eps_get_eps3_input_stage_mac_addressesRequestHandlerImpl(ReqContext_t* pReqCtx,
            const nvm_epsget_eps3_input_stage_mac_addressesRequestData_t* pRequestData);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL

#define BP_OFFSET          (0)
#define PDM_A_OFFSET       (NVM_EPS_EPSIIIBPIDTYPE_MAX_CNT)
#define PDM_B_OFFSET       (PDM_A_OFFSET + NVM_EPS_EPSIIIPDMAIDTYPE_MAX_CNT)
#define EXPANDER_OFFSET    (PDM_B_OFFSET + NVM_EPS_EPSIIIPDMBIDTYPE_MAX_CNT)
#define INPUT_STAGE_OFFSET (EXPANDER_OFFSET + NVM_EPS_EPSIIIEXPANDERIDTYPE_MAX_CNT)

#define EPS3_DEV_CNT (INPUT_STAGE_OFFSET + NVM_EPS_EPSIIIINPUTSTAGEIDTYPE_MAX_CNT)

// @END_USER@ USER_LOCAL_VARS_DECL

static nvm_eps_ServerApi_t nvm_epsServerApiCtx =
{
  .nvm_eps_set_eps2_bp_mac_addressRequestHandler = nvm_eps_set_eps2_bp_mac_addressRequestHandlerImpl,
  .nvm_eps_get_eps2_bp_mac_addressRequestHandler = nvm_eps_get_eps2_bp_mac_addressRequestHandlerImpl,
  .nvm_eps_set_eps3_bp_mac_addressesRequestHandler = nvm_eps_set_eps3_bp_mac_addressesRequestHandlerImpl,
  .nvm_eps_get_eps3_bp_mac_addressesRequestHandler = nvm_eps_get_eps3_bp_mac_addressesRequestHandlerImpl,
  .nvm_eps_set_eps3_pdm_a_mac_addressesRequestHandler = nvm_eps_set_eps3_pdm_a_mac_addressesRequestHandlerImpl,
  .nvm_eps_get_eps3_pdm_a_mac_addressesRequestHandler = nvm_eps_get_eps3_pdm_a_mac_addressesRequestHandlerImpl,
  .nvm_eps_set_eps3_pdm_b_mac_addressesRequestHandler = nvm_eps_set_eps3_pdm_b_mac_addressesRequestHandlerImpl,
  .nvm_eps_get_eps3_pdm_b_mac_addressesRequestHandler = nvm_eps_get_eps3_pdm_b_mac_addressesRequestHandlerImpl,
  .nvm_eps_set_eps3_expander_mac_addressesRequestHandler = nvm_eps_set_eps3_expander_mac_addressesRequestHandlerImpl,
  .nvm_eps_get_eps3_expander_mac_addressesRequestHandler = nvm_eps_get_eps3_expander_mac_addressesRequestHandlerImpl,
  .nvm_eps_set_eps3_input_stage_mac_addressesRequestHandler = nvm_eps_set_eps3_input_stage_mac_addressesRequestHandlerImpl,
  .nvm_eps_get_eps3_input_stage_mac_addressesRequestHandler = nvm_eps_get_eps3_input_stage_mac_addressesRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL

static NVM_EPS_StandardResult_t set_eps3_address(uint8_t new_mac_address, uint8_t device_id)
{
    mac_address_book_t       addresses = { 0 };
    NVM_EPS_StandardResult_t eOp_result;

    if (EPS3_DEV_CNT <= device_id)
    {
        eOp_result = NVM_EPS_STANDARDRESULT_INVALID_ARGS;
    }
    // Check for invalid MAC ADDRESSES
    else if (0x00 == new_mac_address || ESSATMAC_ADDR_BROADCAST == new_mac_address || ESSATMAC_ADDR_GATEWAY_DEV == new_mac_address || ESSATMAC_ADDR_UNINITIALIZED_DEV == new_mac_address || ESSATMAC_ADDR_GATEWAY_EPSIIBP == new_mac_address || ESSATMAC_ADDR_GATEWAY_EPSIIPDM == new_mac_address || ESSATMAC_ADDR_EXTERNAL_MAC_DONGLE == new_mac_address)
    {
        eOp_result = NVM_EPS_STANDARDRESULT_INVALID_ARGS;
    }
    else
    {
        // Read the NVM
        Nvm_GetBlockById(NVM_MAC_ADDRESS_BOOK, &addresses);

        // Verify if the nvm was read
        addresses.a_eps_iii_addresses[device_id] = new_mac_address;
        Nvm_SetBlockById(NVM_MAC_ADDRESS_BOOK, &addresses, true);
        eOp_result = NVM_EPS_STANDARDRESULT_SUCCESS;
    }
    return eOp_result;
}

static NVM_EPS_StandardResult_t get_eps3_address(uint8_t *p_read_mac_address, uint8_t device_id)
{
    mac_address_book_t       addresses  = { 0 };
    NVM_EPS_StandardResult_t eOp_result = NVM_EPS_STANDARDRESULT_ERROR;

    CRIT_ASSERT(NULL != p_read_mac_address);

    *p_read_mac_address = 0;

    if (EPS3_DEV_CNT <= device_id)
    {
        eOp_result = NVM_EPS_STANDARDRESULT_INVALID_ARGS;
    }
    else
    {
        // Read the NVM
        Nvm_GetBlockById(NVM_MAC_ADDRESS_BOOK, &addresses);

        *p_read_mac_address = addresses.a_eps_iii_addresses[device_id];
        eOp_result          = NVM_EPS_STANDARDRESULT_SUCCESS;
    }

    return eOp_result;
}

// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method nvm_eps::set_eps2_bp_mac_address (ID = 0x00000001)
static void nvm_eps_set_eps2_bp_mac_addressRequestHandlerImpl(ReqContext_t *pReqCtx,
            const nvm_epsset_eps2_bp_mac_addressRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    NVM_EPS_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@nvm_eps::set_eps2_bp_mac_address@
    mac_address_book_t addresses = { 0 };
    // @USER_VAR_SECTION_END@nvm_eps::set_eps2_bp_mac_address@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@nvm_eps::set_eps2_bp_mac_address@

        if (NVM_EPS_EPSBPIDTYPE_MAX_CNT <= pRequestData->eDevice_id)
        {
            eOp_result = NVM_EPS_STANDARDRESULT_INVALID_ARGS;
        }
        // Check for invalid MAC ADDRESSES
        else if (0x00 == pRequestData->u8New_mac_address || ESSATMAC_ADDR_BROADCAST == pRequestData->u8New_mac_address || ESSATMAC_ADDR_GATEWAY_DEV == pRequestData->u8New_mac_address || ESSATMAC_ADDR_UNINITIALIZED_DEV == pRequestData->u8New_mac_address || ESSATMAC_ADDR_GATEWAY_EPSIIBP == pRequestData->u8New_mac_address || ESSATMAC_ADDR_GATEWAY_EPSIIPDM == pRequestData->u8New_mac_address || ESSATMAC_ADDR_EXTERNAL_MAC_DONGLE == pRequestData->u8New_mac_address)
        {
            eOp_result = NVM_EPS_STANDARDRESULT_INVALID_ARGS;
        }
        else
        {
            // Read the NVM
            Nvm_GetBlockById(NVM_MAC_ADDRESS_BOOK, &addresses);

            // Verify if the nvm was read
            addresses.a_eps_batterypack_addresses[pRequestData->eDevice_id] = pRequestData->u8New_mac_address;
            Nvm_SetBlockById(NVM_MAC_ADDRESS_BOOK, &addresses, true);
            eOp_result = NVM_EPS_STANDARDRESULT_SUCCESS;
        }

        // @USER_CODE_SECTION_END@nvm_eps::set_eps2_bp_mac_address@

        respResult = nvm_eps_set_eps2_bp_mac_addressResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS, NVM_EPS_SET_EPS2_BP_MAC_ADDRESS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method nvm_eps::set_eps2_bp_mac_address (ID = 0x00000001)

// @START@ Request handler for method nvm_eps::get_eps2_bp_mac_address (ID = 0x00000002)
static void nvm_eps_get_eps2_bp_mac_addressRequestHandlerImpl(ReqContext_t *pReqCtx,
            const nvm_epsget_eps2_bp_mac_addressRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    uint8_t u8Mac_address;
    NVM_EPS_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@nvm_eps::get_eps2_bp_mac_address@
    mac_address_book_t addresses = { 0 };
    // @USER_VAR_SECTION_END@nvm_eps::get_eps2_bp_mac_address@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@nvm_eps::get_eps2_bp_mac_address@

        u8Mac_address = 0;

        if (NVM_EPS_EPSBPIDTYPE_MAX_CNT <= pRequestData->eDevice_id)
        {
            eOp_result = NVM_EPS_STANDARDRESULT_INVALID_ARGS;
        }
        else
        {
            // Read the NVM
            Nvm_GetBlockById(NVM_MAC_ADDRESS_BOOK, &addresses);

            u8Mac_address = addresses.a_eps_batterypack_addresses[pRequestData->eDevice_id];
            eOp_result    = NVM_EPS_STANDARDRESULT_SUCCESS;
        }

        // @USER_CODE_SECTION_END@nvm_eps::get_eps2_bp_mac_address@

        respResult = nvm_eps_get_eps2_bp_mac_addressResp(
                        &respCtx,
                        u8Mac_address,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS, NVM_EPS_GET_EPS2_BP_MAC_ADDRESS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method nvm_eps::get_eps2_bp_mac_address (ID = 0x00000002)

// @START@ Request handler for method nvm_eps::set_eps3_bp_mac_addresses (ID = 0x00000003)
static void nvm_eps_set_eps3_bp_mac_addressesRequestHandlerImpl(ReqContext_t *pReqCtx,
            const nvm_epsset_eps3_bp_mac_addressesRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    NVM_EPS_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@nvm_eps::set_eps3_bp_mac_addresses@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@nvm_eps::set_eps3_bp_mac_addresses@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@nvm_eps::set_eps3_bp_mac_addresses@

        eOp_result = set_eps3_address(pRequestData->u8New_mac_address, pRequestData->eDevice_id + BP_OFFSET);

        // @USER_CODE_SECTION_END@nvm_eps::set_eps3_bp_mac_addresses@

        respResult = nvm_eps_set_eps3_bp_mac_addressesResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS, NVM_EPS_SET_EPS3_BP_MAC_ADDRESSES_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method nvm_eps::set_eps3_bp_mac_addresses (ID = 0x00000003)

// @START@ Request handler for method nvm_eps::get_eps3_bp_mac_addresses (ID = 0x00000004)
static void nvm_eps_get_eps3_bp_mac_addressesRequestHandlerImpl(ReqContext_t *pReqCtx,
            const nvm_epsget_eps3_bp_mac_addressesRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    uint8_t u8Mac_address;
    NVM_EPS_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@nvm_eps::get_eps3_bp_mac_addresses@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@nvm_eps::get_eps3_bp_mac_addresses@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@nvm_eps::get_eps3_bp_mac_addresses@

        eOp_result = get_eps3_address(&u8Mac_address, pRequestData->eDevice_id + BP_OFFSET);

        // @USER_CODE_SECTION_END@nvm_eps::get_eps3_bp_mac_addresses@

        respResult = nvm_eps_get_eps3_bp_mac_addressesResp(
                        &respCtx,
                        u8Mac_address,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS, NVM_EPS_GET_EPS3_BP_MAC_ADDRESSES_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method nvm_eps::get_eps3_bp_mac_addresses (ID = 0x00000004)

// @START@ Request handler for method nvm_eps::set_eps3_pdm_a_mac_addresses (ID = 0x00000005)
static void nvm_eps_set_eps3_pdm_a_mac_addressesRequestHandlerImpl(ReqContext_t *pReqCtx,
            const nvm_epsset_eps3_pdm_a_mac_addressesRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    NVM_EPS_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@nvm_eps::set_eps3_pdm_a_mac_addresses@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@nvm_eps::set_eps3_pdm_a_mac_addresses@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@nvm_eps::set_eps3_pdm_a_mac_addresses@

        eOp_result = set_eps3_address(pRequestData->u8New_mac_address, pRequestData->eDevice_id + PDM_A_OFFSET);

        // @USER_CODE_SECTION_END@nvm_eps::set_eps3_pdm_a_mac_addresses@

        respResult = nvm_eps_set_eps3_pdm_a_mac_addressesResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS, NVM_EPS_SET_EPS3_PDM_A_MAC_ADDRESSES_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method nvm_eps::set_eps3_pdm_a_mac_addresses (ID = 0x00000005)

// @START@ Request handler for method nvm_eps::get_eps3_pdm_a_mac_addresses (ID = 0x00000006)
static void nvm_eps_get_eps3_pdm_a_mac_addressesRequestHandlerImpl(ReqContext_t *pReqCtx,
            const nvm_epsget_eps3_pdm_a_mac_addressesRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    uint8_t u8Mac_address;
    NVM_EPS_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@nvm_eps::get_eps3_pdm_a_mac_addresses@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@nvm_eps::get_eps3_pdm_a_mac_addresses@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@nvm_eps::get_eps3_pdm_a_mac_addresses@

        eOp_result = get_eps3_address(&u8Mac_address, pRequestData->eDevice_id + PDM_A_OFFSET);

        // @USER_CODE_SECTION_END@nvm_eps::get_eps3_pdm_a_mac_addresses@

        respResult = nvm_eps_get_eps3_pdm_a_mac_addressesResp(
                        &respCtx,
                        u8Mac_address,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS, NVM_EPS_GET_EPS3_PDM_A_MAC_ADDRESSES_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method nvm_eps::get_eps3_pdm_a_mac_addresses (ID = 0x00000006)

// @START@ Request handler for method nvm_eps::set_eps3_pdm_b_mac_addresses (ID = 0x00000007)
static void nvm_eps_set_eps3_pdm_b_mac_addressesRequestHandlerImpl(ReqContext_t *pReqCtx,
            const nvm_epsset_eps3_pdm_b_mac_addressesRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    NVM_EPS_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@nvm_eps::set_eps3_pdm_b_mac_addresses@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@nvm_eps::set_eps3_pdm_b_mac_addresses@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@nvm_eps::set_eps3_pdm_b_mac_addresses@

        eOp_result = set_eps3_address(pRequestData->u8New_mac_address, pRequestData->eDevice_id + PDM_B_OFFSET);

        // @USER_CODE_SECTION_END@nvm_eps::set_eps3_pdm_b_mac_addresses@

        respResult = nvm_eps_set_eps3_pdm_b_mac_addressesResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS, NVM_EPS_SET_EPS3_PDM_B_MAC_ADDRESSES_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method nvm_eps::set_eps3_pdm_b_mac_addresses (ID = 0x00000007)

// @START@ Request handler for method nvm_eps::get_eps3_pdm_b_mac_addresses (ID = 0x00000008)
static void nvm_eps_get_eps3_pdm_b_mac_addressesRequestHandlerImpl(ReqContext_t *pReqCtx,
            const nvm_epsget_eps3_pdm_b_mac_addressesRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    uint8_t u8Mac_address;
    NVM_EPS_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@nvm_eps::get_eps3_pdm_b_mac_addresses@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@nvm_eps::get_eps3_pdm_b_mac_addresses@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@nvm_eps::get_eps3_pdm_b_mac_addresses@

        eOp_result = get_eps3_address(&u8Mac_address, pRequestData->eDevice_id + PDM_B_OFFSET);

        // @USER_CODE_SECTION_END@nvm_eps::get_eps3_pdm_b_mac_addresses@

        respResult = nvm_eps_get_eps3_pdm_b_mac_addressesResp(
                        &respCtx,
                        u8Mac_address,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS, NVM_EPS_GET_EPS3_PDM_B_MAC_ADDRESSES_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method nvm_eps::get_eps3_pdm_b_mac_addresses (ID = 0x00000008)

// @START@ Request handler for method nvm_eps::set_eps3_expander_mac_addresses (ID = 0x00000009)
static void nvm_eps_set_eps3_expander_mac_addressesRequestHandlerImpl(ReqContext_t *pReqCtx,
            const nvm_epsset_eps3_expander_mac_addressesRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    NVM_EPS_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@nvm_eps::set_eps3_expander_mac_addresses@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@nvm_eps::set_eps3_expander_mac_addresses@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@nvm_eps::set_eps3_expander_mac_addresses@

        eOp_result = set_eps3_address(pRequestData->u8New_mac_address, pRequestData->eDevice_id + EXPANDER_OFFSET);

        // @USER_CODE_SECTION_END@nvm_eps::set_eps3_expander_mac_addresses@

        respResult = nvm_eps_set_eps3_expander_mac_addressesResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS, NVM_EPS_SET_EPS3_EXPANDER_MAC_ADDRESSES_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method nvm_eps::set_eps3_expander_mac_addresses (ID = 0x00000009)

// @START@ Request handler for method nvm_eps::get_eps3_expander_mac_addresses (ID = 0x0000000A)
static void nvm_eps_get_eps3_expander_mac_addressesRequestHandlerImpl(ReqContext_t *pReqCtx,
            const nvm_epsget_eps3_expander_mac_addressesRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    uint8_t u8Mac_address;
    NVM_EPS_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@nvm_eps::get_eps3_expander_mac_addresses@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@nvm_eps::get_eps3_expander_mac_addresses@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@nvm_eps::get_eps3_expander_mac_addresses@

        eOp_result = get_eps3_address(&u8Mac_address, pRequestData->eDevice_id + EXPANDER_OFFSET);

        // @USER_CODE_SECTION_END@nvm_eps::get_eps3_expander_mac_addresses@

        respResult = nvm_eps_get_eps3_expander_mac_addressesResp(
                        &respCtx,
                        u8Mac_address,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS, NVM_EPS_GET_EPS3_EXPANDER_MAC_ADDRESSES_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method nvm_eps::get_eps3_expander_mac_addresses (ID = 0x0000000A)

// @START@ Request handler for method nvm_eps::set_eps3_input_stage_mac_addresses (ID = 0x0000000B)
static void nvm_eps_set_eps3_input_stage_mac_addressesRequestHandlerImpl(ReqContext_t *pReqCtx,
            const nvm_epsset_eps3_input_stage_mac_addressesRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    NVM_EPS_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@nvm_eps::set_eps3_input_stage_mac_addresses@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@nvm_eps::set_eps3_input_stage_mac_addresses@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@nvm_eps::set_eps3_input_stage_mac_addresses@

        eOp_result = set_eps3_address(pRequestData->u8New_mac_address, pRequestData->eDevice_id + INPUT_STAGE_OFFSET);

        // @USER_CODE_SECTION_END@nvm_eps::set_eps3_input_stage_mac_addresses@

        respResult = nvm_eps_set_eps3_input_stage_mac_addressesResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS, NVM_EPS_SET_EPS3_INPUT_STAGE_MAC_ADDRESSES_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method nvm_eps::set_eps3_input_stage_mac_addresses (ID = 0x0000000B)

// @START@ Request handler for method nvm_eps::get_eps3_input_stage_mac_addresses (ID = 0x0000000C)
static void nvm_eps_get_eps3_input_stage_mac_addressesRequestHandlerImpl(ReqContext_t *pReqCtx,
            const nvm_epsget_eps3_input_stage_mac_addressesRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    uint8_t u8Mac_address;
    NVM_EPS_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@nvm_eps::get_eps3_input_stage_mac_addresses@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@nvm_eps::get_eps3_input_stage_mac_addresses@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@nvm_eps::get_eps3_input_stage_mac_addresses@

        eOp_result = get_eps3_address(&u8Mac_address, pRequestData->eDevice_id + INPUT_STAGE_OFFSET);

        // @USER_CODE_SECTION_END@nvm_eps::get_eps3_input_stage_mac_addresses@

        respResult = nvm_eps_get_eps3_input_stage_mac_addressesResp(
                        &respCtx,
                        u8Mac_address,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS, NVM_EPS_GET_EPS3_INPUT_STAGE_MAC_ADDRESSES_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method nvm_eps::get_eps3_input_stage_mac_addresses (ID = 0x0000000C)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void nvm_epsServerAppInit(void)
{
    nvm_eps_registerServerApi(&nvm_epsServerApiCtx);
}
