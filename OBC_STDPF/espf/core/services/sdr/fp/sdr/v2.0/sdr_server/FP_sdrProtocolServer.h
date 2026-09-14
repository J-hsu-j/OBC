/*!
********************************************************************************************
* @file FP_sdrProtocolServer.h
* @brief ESSA Stack server-side public API declaration
********************************************************************************************
* @version           interface sdr v2.0
*
* @copyright         (C) Copyright EnduroSat
*
*                    Contents and presentations are protected world-wide.
*                    Any kind of using, copying etc. is prohibited without prior permission.
*                    All rights - incl. industrial property rights - are reserved.
*
*-------------------------------------------------------------------------------------------
* GENERATOR: org.endurosat.generators.macchiato.binders.Gen_C v2.14
*-------------------------------------------------------------------------------------------
* !!! Please note that this code is fully GENERATED and shall not be manually modified as
* all changes will be overwritten !!!
********************************************************************************************
*/

#ifndef FP_SDRPROTOCOLSERVER_H
#define FP_SDRPROTOCOLSERVER_H

#include "FP_sdrProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define sdr_PROTOCOL_VERSION_MAJOR   ((uint8_t) 2)
#define sdr_PROTOCOL_VERSION_MINOR   ((uint8_t) 0)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfsdr_sdr_uploadRequestHandler_t)(ReqContext_t *ctx, const sdrsdr_uploadRequestData_t *pRequestData);
typedef void (*pfsdr_sdr_downloadRequestHandler_t)(ReqContext_t *ctx, const sdrsdr_downloadRequestData_t *pRequestData);
typedef void (*pfsdr_sdr_poll_latest_ft_statusRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfsdr_sdr_get_stateRequestHandler_t)(ReqContext_t *ctx);

typedef struct {
    pfsdr_sdr_uploadRequestHandler_t sdr_sdr_uploadRequestHandler;
    pfsdr_sdr_downloadRequestHandler_t sdr_sdr_downloadRequestHandler;
    pfsdr_sdr_poll_latest_ft_statusRequestHandler_t sdr_sdr_poll_latest_ft_statusRequestHandler;
    pfsdr_sdr_get_stateRequestHandler_t sdr_sdr_get_stateRequestHandler;
} sdr_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_sdrProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void sdr_registerServerApi(sdr_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_sdrProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t sdr_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes sdr_sdr_uploadResp(
                RespContext_t* ctx,
                const SDR_FileStatus_t eStatus
);

ESSATMAC_ErrCodes sdr_sdr_downloadResp(
                RespContext_t* ctx,
                const SDR_FileStatus_t eStatus
);

ESSATMAC_ErrCodes sdr_sdr_poll_latest_ft_statusResp(
                RespContext_t* ctx,
                const SDR_FileStatus_t eStatus
);

ESSATMAC_ErrCodes sdr_sdr_get_stateResp(
                RespContext_t* ctx,
                const SDR_StateMachineState_t eSm_state
);


#endif  // #ifndef FP_SDRPROTOCOLSERVER_H
