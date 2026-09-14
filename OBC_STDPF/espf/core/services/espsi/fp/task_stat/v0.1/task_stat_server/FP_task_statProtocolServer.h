/*!
********************************************************************************************
* @file FP_task_statProtocolServer.h
* @brief ESSA Stack server-side public API declaration
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

#ifndef FP_TASK_STATPROTOCOLSERVER_H
#define FP_TASK_STATPROTOCOLSERVER_H

#include "FP_task_statProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define task_stat_PROTOCOL_VERSION_MAJOR   ((uint8_t) 0)
#define task_stat_PROTOCOL_VERSION_MINOR   ((uint8_t) 1)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pftask_stat_get_configurationRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pftask_stat_set_configuration_global_enableRequestHandler_t)(ReqContext_t *ctx, const task_statset_configuration_global_enableRequestData_t *pRequestData);
typedef void (*pftask_stat_set_configuration_global_loggingRequestHandler_t)(ReqContext_t *ctx, const task_statset_configuration_global_loggingRequestData_t *pRequestData);
typedef void (*pftask_stat_set_configuration_global_priorityRequestHandler_t)(ReqContext_t *ctx, const task_statset_configuration_global_priorityRequestData_t *pRequestData);
typedef void (*pftask_stat_set_configuration_global_sampling_periodRequestHandler_t)(ReqContext_t *ctx, const task_statset_configuration_global_sampling_periodRequestData_t *pRequestData);
typedef void (*pftask_stat_set_configuration_global_id_fileRequestHandler_t)(ReqContext_t *ctx, const task_statset_configuration_global_id_fileRequestData_t *pRequestData);
typedef void (*pftask_stat_set_configuration_global_defaultsRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pftask_stat_get_configuration_per_task_idRequestHandler_t)(ReqContext_t *ctx, const task_statget_configuration_per_task_idRequestData_t *pRequestData);
typedef void (*pftask_stat_set_configuration_per_task_idRequestHandler_t)(ReqContext_t *ctx, const task_statset_configuration_per_task_idRequestData_t *pRequestData);
typedef void (*pftask_stat_get_free_heapRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pftask_stat_get_latest_task_statRequestHandler_t)(ReqContext_t *ctx, const task_statget_latest_task_statRequestData_t *pRequestData);

typedef struct {
    pftask_stat_get_configurationRequestHandler_t task_stat_get_configurationRequestHandler;
    pftask_stat_set_configuration_global_enableRequestHandler_t task_stat_set_configuration_global_enableRequestHandler;
    pftask_stat_set_configuration_global_loggingRequestHandler_t task_stat_set_configuration_global_loggingRequestHandler;
    pftask_stat_set_configuration_global_priorityRequestHandler_t task_stat_set_configuration_global_priorityRequestHandler;
    pftask_stat_set_configuration_global_sampling_periodRequestHandler_t task_stat_set_configuration_global_sampling_periodRequestHandler;
    pftask_stat_set_configuration_global_id_fileRequestHandler_t task_stat_set_configuration_global_id_fileRequestHandler;
    pftask_stat_set_configuration_global_defaultsRequestHandler_t task_stat_set_configuration_global_defaultsRequestHandler;
    pftask_stat_get_configuration_per_task_idRequestHandler_t task_stat_get_configuration_per_task_idRequestHandler;
    pftask_stat_set_configuration_per_task_idRequestHandler_t task_stat_set_configuration_per_task_idRequestHandler;
    pftask_stat_get_free_heapRequestHandler_t task_stat_get_free_heapRequestHandler;
    pftask_stat_get_latest_task_statRequestHandler_t task_stat_get_latest_task_statRequestHandler;
} task_stat_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_task_statProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void task_stat_registerServerApi(task_stat_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_task_statProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t task_stat_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes task_stat_get_configurationResp(
                RespContext_t* ctx,
                const TASK_STAT_OpStatus_t eStatus,
                const TASK_STAT_StatsConfig_t * const sConfig
);

ESSATMAC_ErrCodes task_stat_set_configuration_global_enableResp(
                RespContext_t* ctx,
                const bool bStatus
);

ESSATMAC_ErrCodes task_stat_set_configuration_global_loggingResp(
                RespContext_t* ctx,
                const bool bStatus
);

ESSATMAC_ErrCodes task_stat_set_configuration_global_priorityResp(
                RespContext_t* ctx,
                const bool bStatus
);

ESSATMAC_ErrCodes task_stat_set_configuration_global_sampling_periodResp(
                RespContext_t* ctx,
                const bool bStatus
);

ESSATMAC_ErrCodes task_stat_set_configuration_global_id_fileResp(
                RespContext_t* ctx,
                const bool bStatus
);

ESSATMAC_ErrCodes task_stat_set_configuration_global_defaultsResp(
                RespContext_t* ctx,
                const bool bStatus
);

ESSATMAC_ErrCodes task_stat_get_configuration_per_task_idResp(
                RespContext_t* ctx,
                const TASK_STAT_OpStatus_t eStatus,
                const TASK_STAT_TaskStatConfig_t * const sTask_cfg
);

ESSATMAC_ErrCodes task_stat_set_configuration_per_task_idResp(
                RespContext_t* ctx,
                const TASK_STAT_OpStatus_t eStatus
);

ESSATMAC_ErrCodes task_stat_get_free_heapResp(
                RespContext_t* ctx,
                const TASK_STAT_OpStatus_t eStatus,
                const uint32_t u32Free_heap
);

ESSATMAC_ErrCodes task_stat_get_latest_task_statResp(
                RespContext_t* ctx,
                const TASK_STAT_OpStatus_t eStatus,
                const TASK_STAT_TaskStatSample_t * const sStat
);


#endif  // #ifndef FP_TASK_STATPROTOCOLSERVER_H
