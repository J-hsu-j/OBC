/*!
********************************************************************************************
* @file FP_conopsProtocolServer.h
* @brief ESSA Stack server-side public API declaration
********************************************************************************************
* @version           interface conops v2.0
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

#ifndef FP_CONOPSPROTOCOLSERVER_H
#define FP_CONOPSPROTOCOLSERVER_H

#include "FP_conopsProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define conops_PROTOCOL_VERSION_MAJOR   ((uint8_t) 2)
#define conops_PROTOCOL_VERSION_MINOR   ((uint8_t) 0)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfconops_send_new_eventRequestHandler_t)(ReqContext_t *ctx, const conopssend_new_eventRequestData_t *pRequestData);
typedef void (*pfconops_get_op_modeRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfconops_set_thresh_valRequestHandler_t)(ReqContext_t *ctx, const conopsset_thresh_valRequestData_t *pRequestData);
typedef void (*pfconops_get_thresh_valRequestHandler_t)(ReqContext_t *ctx, const conopsget_thresh_valRequestData_t *pRequestData);
typedef void (*pfconops_set_all_thresh_valRequestHandler_t)(ReqContext_t *ctx, const conopsset_all_thresh_valRequestData_t *pRequestData);
typedef void (*pfconops_get_all_thresh_valRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfconops_request_mission_mode_enterRequestHandler_t)(ReqContext_t *ctx, const conopsrequest_mission_mode_enterRequestData_t *pRequestData);
typedef void (*pfconops_request_mission_mode_exitRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfconops_get_default_control_modeRequestHandler_t)(ReqContext_t *ctx, const conopsget_default_control_modeRequestData_t *pRequestData);
typedef void (*pfconops_set_default_control_modeRequestHandler_t)(ReqContext_t *ctx, const conopsset_default_control_modeRequestData_t *pRequestData);
typedef void (*pfconops_set_force_allow_payloadsRequestHandler_t)(ReqContext_t *ctx, const conopsset_force_allow_payloadsRequestData_t *pRequestData);
typedef void (*pfconops_get_force_allow_payloadsRequestHandler_t)(ReqContext_t *ctx);

typedef struct {
    pfconops_send_new_eventRequestHandler_t conops_send_new_eventRequestHandler;
    pfconops_get_op_modeRequestHandler_t conops_get_op_modeRequestHandler;
    pfconops_set_thresh_valRequestHandler_t conops_set_thresh_valRequestHandler;
    pfconops_get_thresh_valRequestHandler_t conops_get_thresh_valRequestHandler;
    pfconops_set_all_thresh_valRequestHandler_t conops_set_all_thresh_valRequestHandler;
    pfconops_get_all_thresh_valRequestHandler_t conops_get_all_thresh_valRequestHandler;
    pfconops_request_mission_mode_enterRequestHandler_t conops_request_mission_mode_enterRequestHandler;
    pfconops_request_mission_mode_exitRequestHandler_t conops_request_mission_mode_exitRequestHandler;
    pfconops_get_default_control_modeRequestHandler_t conops_get_default_control_modeRequestHandler;
    pfconops_set_default_control_modeRequestHandler_t conops_set_default_control_modeRequestHandler;
    pfconops_set_force_allow_payloadsRequestHandler_t conops_set_force_allow_payloadsRequestHandler;
    pfconops_get_force_allow_payloadsRequestHandler_t conops_get_force_allow_payloadsRequestHandler;
} conops_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_conopsProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void conops_registerServerApi(conops_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_conopsProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t conops_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes conops_send_new_eventResp(
                RespContext_t* ctx,
                const CONOPS_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes conops_get_op_modeResp(
                RespContext_t* ctx,
                const CONOPS_StandardResult_t eOp_result,
                const CONOPS_OpModes_t eOp_mode
);

ESSATMAC_ErrCodes conops_set_thresh_valResp(
                RespContext_t* ctx,
                const CONOPS_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes conops_get_thresh_valResp(
                RespContext_t* ctx,
                const CONOPS_StandardResult_t eOp_result,
                const int32_t i32Thresh_value
);

ESSATMAC_ErrCodes conops_set_all_thresh_valResp(
                RespContext_t* ctx,
                const CONOPS_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes conops_get_all_thresh_valResp(
                RespContext_t* ctx,
                const CONOPS_StandardResult_t eOp_result,
                const CONOPS_ThresholdValues_t * const sThresh_vals
);

ESSATMAC_ErrCodes conops_request_mission_mode_enterResp(
                RespContext_t* ctx,
                const CONOPS_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes conops_request_mission_mode_exitResp(
                RespContext_t* ctx,
                const CONOPS_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes conops_get_default_control_modeResp(
                RespContext_t* ctx,
                const CONOPS_StandardResult_t eOp_result,
                const CONOPS_ControlMode_t * const sControl_mode
);

ESSATMAC_ErrCodes conops_set_default_control_modeResp(
                RespContext_t* ctx,
                const CONOPS_StandardResult_t eOp_result,
                const CONOPS_ControlMode_t * const sSet_control_mode
);

ESSATMAC_ErrCodes conops_set_force_allow_payloadsResp(
                RespContext_t* ctx,
                const CONOPS_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes conops_get_force_allow_payloadsResp(
                RespContext_t* ctx,
                const CONOPS_SafeBool_t eSet_is_allowed
);


#endif  // #ifndef FP_CONOPSPROTOCOLSERVER_H
