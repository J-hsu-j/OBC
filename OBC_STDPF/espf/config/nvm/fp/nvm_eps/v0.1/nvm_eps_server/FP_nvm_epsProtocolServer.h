/*!
********************************************************************************************
* @file FP_nvm_epsProtocolServer.h
* @brief ESSA Stack server-side public API declaration
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

#ifndef FP_NVM_EPSPROTOCOLSERVER_H
#define FP_NVM_EPSPROTOCOLSERVER_H

#include "FP_nvm_epsProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define nvm_eps_PROTOCOL_VERSION_MAJOR   ((uint8_t) 0)
#define nvm_eps_PROTOCOL_VERSION_MINOR   ((uint8_t) 1)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfnvm_eps_set_eps2_bp_mac_addressRequestHandler_t)(ReqContext_t *ctx, const nvm_epsset_eps2_bp_mac_addressRequestData_t *pRequestData);
typedef void (*pfnvm_eps_get_eps2_bp_mac_addressRequestHandler_t)(ReqContext_t *ctx, const nvm_epsget_eps2_bp_mac_addressRequestData_t *pRequestData);
typedef void (*pfnvm_eps_set_eps3_bp_mac_addressesRequestHandler_t)(ReqContext_t *ctx, const nvm_epsset_eps3_bp_mac_addressesRequestData_t *pRequestData);
typedef void (*pfnvm_eps_get_eps3_bp_mac_addressesRequestHandler_t)(ReqContext_t *ctx, const nvm_epsget_eps3_bp_mac_addressesRequestData_t *pRequestData);
typedef void (*pfnvm_eps_set_eps3_pdm_a_mac_addressesRequestHandler_t)(ReqContext_t *ctx, const nvm_epsset_eps3_pdm_a_mac_addressesRequestData_t *pRequestData);
typedef void (*pfnvm_eps_get_eps3_pdm_a_mac_addressesRequestHandler_t)(ReqContext_t *ctx, const nvm_epsget_eps3_pdm_a_mac_addressesRequestData_t *pRequestData);
typedef void (*pfnvm_eps_set_eps3_pdm_b_mac_addressesRequestHandler_t)(ReqContext_t *ctx, const nvm_epsset_eps3_pdm_b_mac_addressesRequestData_t *pRequestData);
typedef void (*pfnvm_eps_get_eps3_pdm_b_mac_addressesRequestHandler_t)(ReqContext_t *ctx, const nvm_epsget_eps3_pdm_b_mac_addressesRequestData_t *pRequestData);
typedef void (*pfnvm_eps_set_eps3_expander_mac_addressesRequestHandler_t)(ReqContext_t *ctx, const nvm_epsset_eps3_expander_mac_addressesRequestData_t *pRequestData);
typedef void (*pfnvm_eps_get_eps3_expander_mac_addressesRequestHandler_t)(ReqContext_t *ctx, const nvm_epsget_eps3_expander_mac_addressesRequestData_t *pRequestData);
typedef void (*pfnvm_eps_set_eps3_input_stage_mac_addressesRequestHandler_t)(ReqContext_t *ctx, const nvm_epsset_eps3_input_stage_mac_addressesRequestData_t *pRequestData);
typedef void (*pfnvm_eps_get_eps3_input_stage_mac_addressesRequestHandler_t)(ReqContext_t *ctx, const nvm_epsget_eps3_input_stage_mac_addressesRequestData_t *pRequestData);

typedef struct {
    pfnvm_eps_set_eps2_bp_mac_addressRequestHandler_t nvm_eps_set_eps2_bp_mac_addressRequestHandler;
    pfnvm_eps_get_eps2_bp_mac_addressRequestHandler_t nvm_eps_get_eps2_bp_mac_addressRequestHandler;
    pfnvm_eps_set_eps3_bp_mac_addressesRequestHandler_t nvm_eps_set_eps3_bp_mac_addressesRequestHandler;
    pfnvm_eps_get_eps3_bp_mac_addressesRequestHandler_t nvm_eps_get_eps3_bp_mac_addressesRequestHandler;
    pfnvm_eps_set_eps3_pdm_a_mac_addressesRequestHandler_t nvm_eps_set_eps3_pdm_a_mac_addressesRequestHandler;
    pfnvm_eps_get_eps3_pdm_a_mac_addressesRequestHandler_t nvm_eps_get_eps3_pdm_a_mac_addressesRequestHandler;
    pfnvm_eps_set_eps3_pdm_b_mac_addressesRequestHandler_t nvm_eps_set_eps3_pdm_b_mac_addressesRequestHandler;
    pfnvm_eps_get_eps3_pdm_b_mac_addressesRequestHandler_t nvm_eps_get_eps3_pdm_b_mac_addressesRequestHandler;
    pfnvm_eps_set_eps3_expander_mac_addressesRequestHandler_t nvm_eps_set_eps3_expander_mac_addressesRequestHandler;
    pfnvm_eps_get_eps3_expander_mac_addressesRequestHandler_t nvm_eps_get_eps3_expander_mac_addressesRequestHandler;
    pfnvm_eps_set_eps3_input_stage_mac_addressesRequestHandler_t nvm_eps_set_eps3_input_stage_mac_addressesRequestHandler;
    pfnvm_eps_get_eps3_input_stage_mac_addressesRequestHandler_t nvm_eps_get_eps3_input_stage_mac_addressesRequestHandler;
} nvm_eps_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_nvm_epsProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void nvm_eps_registerServerApi(nvm_eps_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_nvm_epsProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t nvm_eps_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes nvm_eps_set_eps2_bp_mac_addressResp(
                RespContext_t* ctx,
                const NVM_EPS_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes nvm_eps_get_eps2_bp_mac_addressResp(
                RespContext_t* ctx,
                const uint8_t u8Mac_address,
                const NVM_EPS_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes nvm_eps_set_eps3_bp_mac_addressesResp(
                RespContext_t* ctx,
                const NVM_EPS_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes nvm_eps_get_eps3_bp_mac_addressesResp(
                RespContext_t* ctx,
                const uint8_t u8Mac_address,
                const NVM_EPS_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes nvm_eps_set_eps3_pdm_a_mac_addressesResp(
                RespContext_t* ctx,
                const NVM_EPS_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes nvm_eps_get_eps3_pdm_a_mac_addressesResp(
                RespContext_t* ctx,
                const uint8_t u8Mac_address,
                const NVM_EPS_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes nvm_eps_set_eps3_pdm_b_mac_addressesResp(
                RespContext_t* ctx,
                const NVM_EPS_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes nvm_eps_get_eps3_pdm_b_mac_addressesResp(
                RespContext_t* ctx,
                const uint8_t u8Mac_address,
                const NVM_EPS_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes nvm_eps_set_eps3_expander_mac_addressesResp(
                RespContext_t* ctx,
                const NVM_EPS_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes nvm_eps_get_eps3_expander_mac_addressesResp(
                RespContext_t* ctx,
                const uint8_t u8Mac_address,
                const NVM_EPS_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes nvm_eps_set_eps3_input_stage_mac_addressesResp(
                RespContext_t* ctx,
                const NVM_EPS_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes nvm_eps_get_eps3_input_stage_mac_addressesResp(
                RespContext_t* ctx,
                const uint8_t u8Mac_address,
                const NVM_EPS_StandardResult_t eOp_result
);


#endif  // #ifndef FP_NVM_EPSPROTOCOLSERVER_H
