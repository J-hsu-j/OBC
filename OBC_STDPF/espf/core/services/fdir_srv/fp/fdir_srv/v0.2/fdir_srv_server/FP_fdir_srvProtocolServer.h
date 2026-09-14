/*!
********************************************************************************************
* @file FP_fdir_srvProtocolServer.h
* @brief ESSA Stack server-side public API declaration
********************************************************************************************
* @version           interface fdir_srv v0.2
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

#ifndef FP_FDIR_SRVPROTOCOLSERVER_H
#define FP_FDIR_SRVPROTOCOLSERVER_H

#include "FP_fdir_srvProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define fdir_srv_PROTOCOL_VERSION_MAJOR   ((uint8_t) 0)
#define fdir_srv_PROTOCOL_VERSION_MINOR   ((uint8_t) 2)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pffdir_srv_get_system_fdir_levelRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pffdir_srv_get_agent_fdir_levelRequestHandler_t)(ReqContext_t *ctx, const fdir_srvget_agent_fdir_levelRequestData_t *pRequestData);
typedef void (*pffdir_srv_get_detection_for_faultRequestHandler_t)(ReqContext_t *ctx, const fdir_srvget_detection_for_faultRequestData_t *pRequestData);
typedef void (*pffdir_srv_set_detection_for_faultRequestHandler_t)(ReqContext_t *ctx, const fdir_srvset_detection_for_faultRequestData_t *pRequestData);
typedef void (*pffdir_srv_set_detection_for_all_faultsRequestHandler_t)(ReqContext_t *ctx, const fdir_srvset_detection_for_all_faultsRequestData_t *pRequestData);
typedef void (*pffdir_srv_get_min_active_fdirRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pffdir_srv_set_min_active_fdirRequestHandler_t)(ReqContext_t *ctx, const fdir_srvset_min_active_fdirRequestData_t *pRequestData);
typedef void (*pffdir_srv_get_fault_user_clear_levelRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pffdir_srv_set_fault_user_clear_levelRequestHandler_t)(ReqContext_t *ctx, const fdir_srvset_fault_user_clear_levelRequestData_t *pRequestData);
typedef void (*pffdir_srv_get_faultRequestHandler_t)(ReqContext_t *ctx, const fdir_srvget_faultRequestData_t *pRequestData);
typedef void (*pffdir_srv_set_faultRequestHandler_t)(ReqContext_t *ctx, const fdir_srvset_faultRequestData_t *pRequestData);
typedef void (*pffdir_srv_force_clear_faultRequestHandler_t)(ReqContext_t *ctx, const fdir_srvforce_clear_faultRequestData_t *pRequestData);
typedef void (*pffdir_srv_force_clear_all_faultsRequestHandler_t)(ReqContext_t *ctx);

typedef struct {
    pffdir_srv_get_system_fdir_levelRequestHandler_t fdir_srv_get_system_fdir_levelRequestHandler;
    pffdir_srv_get_agent_fdir_levelRequestHandler_t fdir_srv_get_agent_fdir_levelRequestHandler;
    pffdir_srv_get_detection_for_faultRequestHandler_t fdir_srv_get_detection_for_faultRequestHandler;
    pffdir_srv_set_detection_for_faultRequestHandler_t fdir_srv_set_detection_for_faultRequestHandler;
    pffdir_srv_set_detection_for_all_faultsRequestHandler_t fdir_srv_set_detection_for_all_faultsRequestHandler;
    pffdir_srv_get_min_active_fdirRequestHandler_t fdir_srv_get_min_active_fdirRequestHandler;
    pffdir_srv_set_min_active_fdirRequestHandler_t fdir_srv_set_min_active_fdirRequestHandler;
    pffdir_srv_get_fault_user_clear_levelRequestHandler_t fdir_srv_get_fault_user_clear_levelRequestHandler;
    pffdir_srv_set_fault_user_clear_levelRequestHandler_t fdir_srv_set_fault_user_clear_levelRequestHandler;
    pffdir_srv_get_faultRequestHandler_t fdir_srv_get_faultRequestHandler;
    pffdir_srv_set_faultRequestHandler_t fdir_srv_set_faultRequestHandler;
    pffdir_srv_force_clear_faultRequestHandler_t fdir_srv_force_clear_faultRequestHandler;
    pffdir_srv_force_clear_all_faultsRequestHandler_t fdir_srv_force_clear_all_faultsRequestHandler;
} fdir_srv_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_fdir_srvProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void fdir_srv_registerServerApi(fdir_srv_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_fdir_srvProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t fdir_srv_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes fdir_srv_get_system_fdir_levelResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const uint8_t u8Fdir_level
);

ESSATMAC_ErrCodes fdir_srv_get_agent_fdir_levelResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const uint8_t u8Fdir_level
);

ESSATMAC_ErrCodes fdir_srv_get_detection_for_faultResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const bool bDetection_enabled
);

ESSATMAC_ErrCodes fdir_srv_set_detection_for_faultResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const bool bDetection_enabled
);

ESSATMAC_ErrCodes fdir_srv_set_detection_for_all_faultsResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const uint16_t u16Fault_id
);

ESSATMAC_ErrCodes fdir_srv_get_min_active_fdirResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const uint8_t u8Fdir_level_set
);

ESSATMAC_ErrCodes fdir_srv_set_min_active_fdirResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const uint8_t u8Fdir_level_set
);

ESSATMAC_ErrCodes fdir_srv_get_fault_user_clear_levelResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const uint8_t u8Fdir_level
);

ESSATMAC_ErrCodes fdir_srv_set_fault_user_clear_levelResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const uint8_t u8Fdir_level_set
);

ESSATMAC_ErrCodes fdir_srv_get_faultResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const bool bIs_active,
                const uint8_t u8Fdir_level
);

ESSATMAC_ErrCodes fdir_srv_set_faultResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus
);

ESSATMAC_ErrCodes fdir_srv_force_clear_faultResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus
);

ESSATMAC_ErrCodes fdir_srv_force_clear_all_faultsResp(
                RespContext_t* ctx,
                const FDIR_SRV_return_status_t eStatus,
                const uint16_t u16Fault_id
);


#endif  // #ifndef FP_FDIR_SRVPROTOCOLSERVER_H
