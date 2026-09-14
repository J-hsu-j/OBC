/*!
********************************************************************************************
* @file FP_trace_level_configProtocolServer.h
* @brief ESSA Stack server-side public API declaration
********************************************************************************************
* @version           interface trace_level_config v0.1
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

#ifndef FP_TRACE_LEVEL_CONFIGPROTOCOLSERVER_H
#define FP_TRACE_LEVEL_CONFIGPROTOCOLSERVER_H

#include "FP_trace_level_configProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define trace_level_config_PROTOCOL_VERSION_MAJOR   ((uint8_t) 0)
#define trace_level_config_PROTOCOL_VERSION_MINOR   ((uint8_t) 1)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pftrace_level_config_set_channel_trace_levelRequestHandler_t)(ReqContext_t *ctx, const trace_level_configset_channel_trace_levelRequestData_t *pRequestData);
typedef void (*pftrace_level_config_get_channel_infoRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pftrace_level_config_set_channel_active_statusRequestHandler_t)(ReqContext_t *ctx, const trace_level_configset_channel_active_statusRequestData_t *pRequestData);
typedef void (*pftrace_level_config_set_module_active_statusRequestHandler_t)(ReqContext_t *ctx, const trace_level_configset_module_active_statusRequestData_t *pRequestData);
typedef void (*pftrace_level_config_set_module_trace_levelRequestHandler_t)(ReqContext_t *ctx, const trace_level_configset_module_trace_levelRequestData_t *pRequestData);
typedef void (*pftrace_level_config_get_module_infoRequestHandler_t)(ReqContext_t *ctx, const trace_level_configget_module_infoRequestData_t *pRequestData);

typedef struct {
    pftrace_level_config_set_channel_trace_levelRequestHandler_t trace_level_config_set_channel_trace_levelRequestHandler;
    pftrace_level_config_get_channel_infoRequestHandler_t trace_level_config_get_channel_infoRequestHandler;
    pftrace_level_config_set_channel_active_statusRequestHandler_t trace_level_config_set_channel_active_statusRequestHandler;
    pftrace_level_config_set_module_active_statusRequestHandler_t trace_level_config_set_module_active_statusRequestHandler;
    pftrace_level_config_set_module_trace_levelRequestHandler_t trace_level_config_set_module_trace_levelRequestHandler;
    pftrace_level_config_get_module_infoRequestHandler_t trace_level_config_get_module_infoRequestHandler;
} trace_level_config_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_trace_level_configProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void trace_level_config_registerServerApi(trace_level_config_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_trace_level_configProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t trace_level_config_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes trace_level_config_set_channel_trace_levelResp(
                RespContext_t* ctx,
                const TRACE_LEVEL_CONFIG_Result_t eRes
);

ESSATMAC_ErrCodes trace_level_config_get_channel_infoResp(
                RespContext_t* ctx,
                const TRACE_LEVEL_CONFIG_ChannelInfo_t * const asChannels,
                const TRACE_LEVEL_CONFIG_Result_t eRes
);

ESSATMAC_ErrCodes trace_level_config_set_channel_active_statusResp(
                RespContext_t* ctx,
                const TRACE_LEVEL_CONFIG_Result_t eRes
);

ESSATMAC_ErrCodes trace_level_config_set_module_active_statusResp(
                RespContext_t* ctx,
                const TRACE_LEVEL_CONFIG_Result_t eRes
);

ESSATMAC_ErrCodes trace_level_config_set_module_trace_levelResp(
                RespContext_t* ctx,
                const TRACE_LEVEL_CONFIG_Result_t eRes
);

ESSATMAC_ErrCodes trace_level_config_get_module_infoResp(
                RespContext_t* ctx,
                const TRACE_LEVEL_CONFIG_ModuleInfo_t * const sModule_output,
                const TRACE_LEVEL_CONFIG_Result_t eRes
);


#endif  // #ifndef FP_TRACE_LEVEL_CONFIGPROTOCOLSERVER_H
