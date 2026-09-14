/*!
********************************************************************************************
* @file FP_onboard_schedProtocolServer.h
* @brief ESSA Stack server-side public API declaration
********************************************************************************************
* @version           interface onboard_sched v0.1
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

#ifndef FP_ONBOARD_SCHEDPROTOCOLSERVER_H
#define FP_ONBOARD_SCHEDPROTOCOLSERVER_H

#include "FP_onboard_schedProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define onboard_sched_PROTOCOL_VERSION_MAJOR   ((uint8_t) 0)
#define onboard_sched_PROTOCOL_VERSION_MINOR   ((uint8_t) 1)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfonboard_sched_set_scheduler_stateRequestHandler_t)(ReqContext_t *ctx, const onboard_schedset_scheduler_stateRequestData_t *pRequestData);
typedef void (*pfonboard_sched_get_scheduler_stateRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfonboard_sched_set_active_scheduleRequestHandler_t)(ReqContext_t *ctx, const onboard_schedset_active_scheduleRequestData_t *pRequestData);
typedef void (*pfonboard_sched_get_active_scheduleRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfonboard_sched_get_next_slotRequestHandler_t)(ReqContext_t *ctx);

typedef struct {
    pfonboard_sched_set_scheduler_stateRequestHandler_t onboard_sched_set_scheduler_stateRequestHandler;
    pfonboard_sched_get_scheduler_stateRequestHandler_t onboard_sched_get_scheduler_stateRequestHandler;
    pfonboard_sched_set_active_scheduleRequestHandler_t onboard_sched_set_active_scheduleRequestHandler;
    pfonboard_sched_get_active_scheduleRequestHandler_t onboard_sched_get_active_scheduleRequestHandler;
    pfonboard_sched_get_next_slotRequestHandler_t onboard_sched_get_next_slotRequestHandler;
} onboard_sched_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_onboard_schedProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void onboard_sched_registerServerApi(onboard_sched_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_onboard_schedProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t onboard_sched_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes onboard_sched_set_scheduler_stateResp(
                RespContext_t* ctx,
                const ONBOARD_SCHED_SchedState_t eNew_state
);

ESSATMAC_ErrCodes onboard_sched_get_scheduler_stateResp(
                RespContext_t* ctx,
                const ONBOARD_SCHED_SchedState_t eSch_state
);

ESSATMAC_ErrCodes onboard_sched_set_active_scheduleResp(
                RespContext_t* ctx,
                const ONBOARD_SCHED_SchedLoadResult_t eResult
);

ESSATMAC_ErrCodes onboard_sched_get_active_scheduleResp(
                RespContext_t* ctx,
                char * const strFile_name,
                const uint8_t u8File_nameSize,
                const ONBOARD_SCHED_SchedLoadResult_t eResult
);

ESSATMAC_ErrCodes onboard_sched_get_next_slotResp(
                RespContext_t* ctx,
                const uint32_t u32Offset
);


#endif  // #ifndef FP_ONBOARD_SCHEDPROTOCOLSERVER_H
