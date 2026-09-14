/*!
********************************************************************************************
* @file FP_ModuleIdProtocolServer.h
* @brief ESSA Stack server-side public API declaration
********************************************************************************************
* @version           interface ModuleId v0.1
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

#ifndef FP_MODULEIDPROTOCOLSERVER_H
#define FP_MODULEIDPROTOCOLSERVER_H

#include "FP_ModuleIdProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define ModuleId_PROTOCOL_VERSION_MAJOR   ((uint8_t) 0)
#define ModuleId_PROTOCOL_VERSION_MINOR   ((uint8_t) 1)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfModuleId_getModuleVersionInfoRequestHandler_t)(ReqContext_t *ctx);

typedef struct {
    pfModuleId_getModuleVersionInfoRequestHandler_t ModuleId_getModuleVersionInfoRequestHandler;
} ModuleId_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_ModuleIdProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void ModuleId_registerServerApi(ModuleId_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_ModuleIdProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t ModuleId_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes ModuleId_getModuleVersionInfoResp(
                RespContext_t* ctx,
                const MODULEID_VersionInfo_t * const sSettings
);


#endif  // #ifndef FP_MODULEIDPROTOCOLSERVER_H
