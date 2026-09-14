/*!
********************************************************************************************
* @file FP_acsProtocolServer.h
* @brief ESSA Stack server-side public API declaration
********************************************************************************************
* @version           interface acs v1.2
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

#ifndef FP_ACSPROTOCOLSERVER_H
#define FP_ACSPROTOCOLSERVER_H

#include "FP_acsProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define acs_PROTOCOL_VERSION_MAJOR   ((uint8_t) 1)
#define acs_PROTOCOL_VERSION_MINOR   ((uint8_t) 2)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfacs_set_op_modeRequestHandler_t)(ReqContext_t *ctx, const acsset_op_modeRequestData_t *pRequestData);
typedef void (*pfacs_get_op_modeRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfacs_get_statusRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfacs_set_manual_mtq_controlRequestHandler_t)(ReqContext_t *ctx, const acsset_manual_mtq_controlRequestData_t *pRequestData);
typedef void (*pfacs_get_manual_mtq_controlRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfacs_get_last_mtq_controlRequestHandler_t)(ReqContext_t *ctx);

typedef struct {
    pfacs_set_op_modeRequestHandler_t acs_set_op_modeRequestHandler;
    pfacs_get_op_modeRequestHandler_t acs_get_op_modeRequestHandler;
    pfacs_get_statusRequestHandler_t acs_get_statusRequestHandler;
    pfacs_set_manual_mtq_controlRequestHandler_t acs_set_manual_mtq_controlRequestHandler;
    pfacs_get_manual_mtq_controlRequestHandler_t acs_get_manual_mtq_controlRequestHandler;
    pfacs_get_last_mtq_controlRequestHandler_t acs_get_last_mtq_controlRequestHandler;
} acs_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_acsProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void acs_registerServerApi(acs_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_acsProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t acs_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes acs_set_op_modeResp(
                RespContext_t* ctx,
                const ACS_Result_t eOp_result
);

ESSATMAC_ErrCodes acs_get_op_modeResp(
                RespContext_t* ctx,
                const ACS_State_t eActive_mode,
                const ACS_Result_t eOp_result
);

ESSATMAC_ErrCodes acs_get_statusResp(
                RespContext_t* ctx,
                const ACS_Status_t * const sCurrent_status,
                const ACS_Result_t eOp_result
);

ESSATMAC_ErrCodes acs_set_manual_mtq_controlResp(
                RespContext_t* ctx,
                const ACS_Result_t eOp_result
);

ESSATMAC_ErrCodes acs_get_manual_mtq_controlResp(
                RespContext_t* ctx,
                const ACS_ManualMtqData_t * const sManual_magnetorquer_control_values,
                const ACS_Result_t eOp_result
);

ESSATMAC_ErrCodes acs_get_last_mtq_controlResp(
                RespContext_t* ctx,
                const ACS_LastMtqData_t * const sLast_magnetorquer_control_values,
                const ACS_Result_t eOp_result
);


#endif  // #ifndef FP_ACSPROTOCOLSERVER_H
