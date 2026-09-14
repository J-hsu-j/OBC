/*!
********************************************************************************************
* @file FP_nvmProtocolServer.h
* @brief ESSA Stack server-side public API declaration
********************************************************************************************
* @version           interface nvm v1.0
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

#ifndef FP_NVMPROTOCOLSERVER_H
#define FP_NVMPROTOCOLSERVER_H

#include "FP_nvmProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define nvm_PROTOCOL_VERSION_MAJOR   ((uint8_t) 1)
#define nvm_PROTOCOL_VERSION_MINOR   ((uint8_t) 0)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfnvm_restore_defaultsRequestHandler_t)(ReqContext_t *ctx, const nvmrestore_defaultsRequestData_t *pRequestData);

typedef struct {
    pfnvm_restore_defaultsRequestHandler_t nvm_restore_defaultsRequestHandler;
} nvm_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_nvmProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void nvm_registerServerApi(nvm_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_nvmProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t nvm_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes nvm_restore_defaultsResp(
                RespContext_t* ctx,
                const NVM_StandardResult_t eOp_result
);


#endif  // #ifndef FP_NVMPROTOCOLSERVER_H
