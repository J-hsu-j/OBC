/*!
********************************************************************************************
* @file FP_gnssProtocolServer.h
* @brief ESSA Stack server-side public API declaration
********************************************************************************************
* @version           interface gnss v1.2
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

#ifndef FP_GNSSPROTOCOLSERVER_H
#define FP_GNSSPROTOCOLSERVER_H

#include "FP_gnssProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define gnss_PROTOCOL_VERSION_MAJOR   ((uint8_t) 1)
#define gnss_PROTOCOL_VERSION_MINOR   ((uint8_t) 2)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfgnss_set_powerRequestHandler_t)(ReqContext_t *ctx, const gnssset_powerRequestData_t *pRequestData);
typedef void (*pfgnss_get_powerRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfgnss_request_command_executionRequestHandler_t)(ReqContext_t *ctx, const gnssrequest_command_executionRequestData_t *pRequestData);
typedef void (*pfgnss_get_command_execution_statusRequestHandler_t)(ReqContext_t *ctx, const gnssget_command_execution_statusRequestData_t *pRequestData);
typedef void (*pfgnss_set_gnss_uart_baudrateRequestHandler_t)(ReqContext_t *ctx, const gnssset_gnss_uart_baudrateRequestData_t *pRequestData);
typedef void (*pfgnss_get_gnss_uart_baudrateRequestHandler_t)(ReqContext_t *ctx);

typedef struct {
    pfgnss_set_powerRequestHandler_t gnss_set_powerRequestHandler;
    pfgnss_get_powerRequestHandler_t gnss_get_powerRequestHandler;
    pfgnss_request_command_executionRequestHandler_t gnss_request_command_executionRequestHandler;
    pfgnss_get_command_execution_statusRequestHandler_t gnss_get_command_execution_statusRequestHandler;
    pfgnss_set_gnss_uart_baudrateRequestHandler_t gnss_set_gnss_uart_baudrateRequestHandler;
    pfgnss_get_gnss_uart_baudrateRequestHandler_t gnss_get_gnss_uart_baudrateRequestHandler;
} gnss_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_gnssProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void gnss_registerServerApi(gnss_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_gnssProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t gnss_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes gnss_set_powerResp(
                RespContext_t* ctx,
                const GNSS_Operation_t eOp_status
);

ESSATMAC_ErrCodes gnss_get_powerResp(
                RespContext_t* ctx,
                const GNSS_Power_t ePwr_status,
                const GNSS_Operation_t eOp_status
);

ESSATMAC_ErrCodes gnss_request_command_executionResp(
                RespContext_t* ctx,
                const uint8_t u8Cmd_id,
                const GNSS_CommandStatus_t eCommand_status
);

ESSATMAC_ErrCodes gnss_get_command_execution_statusResp(
                RespContext_t* ctx,
                const GNSS_CommandStatus_t eCommand_status,
                const uint32_t u32Duration_ms,
                const GNSS_TimeStruct_t * const sRequested_time,
                const GNSS_TimeStruct_t * const sTime_started
);

ESSATMAC_ErrCodes gnss_set_gnss_uart_baudrateResp(
                RespContext_t* ctx,
                const GNSS_Operation_t eOp_status
);

ESSATMAC_ErrCodes gnss_get_gnss_uart_baudrateResp(
                RespContext_t* ctx,
                const GNSS_BaudRate_t eGnss_uart_baudrate_nvm,
                const GNSS_BaudRate_t eGnss_uart_baudrate_current,
                const GNSS_Operation_t eOp_status
);


#endif  // #ifndef FP_GNSSPROTOCOLSERVER_H
