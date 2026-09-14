/*!
********************************************************************************************
* @file FP_obcProtocolServer.h
* @brief ESSA Stack server-side public API declaration
********************************************************************************************
* @version           interface obc v4.1
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

#ifndef FP_OBCPROTOCOLSERVER_H
#define FP_OBCPROTOCOLSERVER_H

#include "FP_obcProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define obc_PROTOCOL_VERSION_MAJOR   ((uint8_t) 4)
#define obc_PROTOCOL_VERSION_MINOR   ((uint8_t) 1)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfobc_get_all_gpo_valuesRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfobc_set_all_gpo_valuesRequestHandler_t)(ReqContext_t *ctx, const obcset_all_gpo_valuesRequestData_t *pRequestData);
typedef void (*pfobc_get_i2c_pull_ups_stateRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfobc_set_i2c_pull_ups_stateRequestHandler_t)(ReqContext_t *ctx, const obcset_i2c_pull_ups_stateRequestData_t *pRequestData);
typedef void (*pfobc_get_uptimeRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfobc_get_reset_countersRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfobc_clear_reset_counterRequestHandler_t)(ReqContext_t *ctx, const obcclear_reset_counterRequestData_t *pRequestData);
typedef void (*pfobc_trigger_reset_in_modeRequestHandler_t)(ReqContext_t *ctx, const obctrigger_reset_in_modeRequestData_t *pRequestData);
typedef void (*pfobc_set_device_mac_addressRequestHandler_t)(ReqContext_t *ctx, const obcset_device_mac_addressRequestData_t *pRequestData);
typedef void (*pfobc_get_device_mac_addressRequestHandler_t)(ReqContext_t *ctx, const obcget_device_mac_addressRequestData_t *pRequestData);

typedef struct {
    pfobc_get_all_gpo_valuesRequestHandler_t obc_get_all_gpo_valuesRequestHandler;
    pfobc_set_all_gpo_valuesRequestHandler_t obc_set_all_gpo_valuesRequestHandler;
    pfobc_get_i2c_pull_ups_stateRequestHandler_t obc_get_i2c_pull_ups_stateRequestHandler;
    pfobc_set_i2c_pull_ups_stateRequestHandler_t obc_set_i2c_pull_ups_stateRequestHandler;
    pfobc_get_uptimeRequestHandler_t obc_get_uptimeRequestHandler;
    pfobc_get_reset_countersRequestHandler_t obc_get_reset_countersRequestHandler;
    pfobc_clear_reset_counterRequestHandler_t obc_clear_reset_counterRequestHandler;
    pfobc_trigger_reset_in_modeRequestHandler_t obc_trigger_reset_in_modeRequestHandler;
    pfobc_set_device_mac_addressRequestHandler_t obc_set_device_mac_addressRequestHandler;
    pfobc_get_device_mac_addressRequestHandler_t obc_get_device_mac_addressRequestHandler;
} obc_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_obcProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void obc_registerServerApi(obc_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_obcProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t obc_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes obc_get_all_gpo_valuesResp(
                RespContext_t* ctx,
                const OBC_GpoPortsGetStruct_t * const sGpo,
                const OBC_StandardResult_t eResult
);

ESSATMAC_ErrCodes obc_set_all_gpo_valuesResp(
                RespContext_t* ctx,
                const OBC_StandardResult_t eResult
);

ESSATMAC_ErrCodes obc_get_i2c_pull_ups_stateResp(
                RespContext_t* ctx,
                const OBC_I2CPullUpsState_t * const sNvm_pull_ups_state,
                const OBC_I2CPullUpsState_t * const sIo_pull_ups_state
);

ESSATMAC_ErrCodes obc_set_i2c_pull_ups_stateResp(
                RespContext_t* ctx,
                const OBC_I2CPullUpsState_t * const sPull_ups_io_state
);

ESSATMAC_ErrCodes obc_get_uptimeResp(
                RespContext_t* ctx,
                const uint32_t u32Uptime
);

ESSATMAC_ErrCodes obc_get_reset_countersResp(
                RespContext_t* ctx,
                const OBC_ResetCountersInfo_t * const sStatus
);

ESSATMAC_ErrCodes obc_clear_reset_counterResp(
                RespContext_t* ctx,
                const OBC_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes obc_trigger_reset_in_modeResp(
                RespContext_t* ctx,
                const OBC_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes obc_set_device_mac_addressResp(
                RespContext_t* ctx,
                const OBC_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes obc_get_device_mac_addressResp(
                RespContext_t* ctx,
                const uint8_t u8Mac_address,
                const OBC_StandardResult_t eOp_result
);


#endif  // #ifndef FP_OBCPROTOCOLSERVER_H
