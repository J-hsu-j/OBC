/*!
********************************************************************************************
* @file FP_gnssServerApp.c
* @brief ServerApp implementation template generator
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

#include "FP_gnssProtocolServer.h"

// @START_USER@ USER_INCLUDES
#include "gnss.h"
#include "gnss_cmd.h"
#include "gnss_uart.h"
#include "gnss_logs.h"
#include "sys_instancer_ct.h"
#include "trace.h"

INIT_CMP_LOGGER(true, TRACE_LVL_WARN)
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL

static void on_gnss_cmd_exec_result_cbk(gnss_cmd_status_t result,
                                        const uint32_t duration_ms,
                                        const uint8_t cmd_id);

// @END_USER@ USER_LOCAL_FUNC_DECL
static void gnss_set_powerRequestHandlerImpl(ReqContext_t* pReqCtx,
            const gnssset_powerRequestData_t* pRequestData);

static void gnss_get_powerRequestHandlerImpl(ReqContext_t* pReqCtx);

static void gnss_request_command_executionRequestHandlerImpl(ReqContext_t* pReqCtx,
            const gnssrequest_command_executionRequestData_t* pRequestData);

static void gnss_get_command_execution_statusRequestHandlerImpl(ReqContext_t* pReqCtx,
            const gnssget_command_execution_statusRequestData_t* pRequestData);

static void gnss_set_gnss_uart_baudrateRequestHandlerImpl(ReqContext_t* pReqCtx,
            const gnssset_gnss_uart_baudrateRequestData_t* pRequestData);

static void gnss_get_gnss_uart_baudrateRequestHandlerImpl(ReqContext_t* pReqCtx);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
static const GNSS_CommandStatus_t gnss_cmd_status_map[CMD_CNT] = {
    [CMD_OK] = GNSS_COMMANDSTATUS_OK,
    [CMD_ERROR] = GNSS_COMMANDSTATUS_ERROR,
    [CMD_QUEUE_FULL] = GNSS_COMMANDSTATUS_QUEUE_FULL,
    [CMD_WRONG_PARAMS] = GNSS_COMMANDSTATUS_WRONG_PARAMS,
    [CMD_PROCESSING] = GNSS_COMMANDSTATUS_PROCESSING,
    [CMD_PENDING] = GNSS_COMMANDSTATUS_PENDING,
    [CMD_NOT_FOUND] = GNSS_COMMANDSTATUS_NOT_FOUND,
    [CMD_TIMED_OUT] = GNSS_COMMANDSTATUS_TIMED_OUT,
    [CMD_MUTEX_ERROR] = GNSS_COMMANDSTATUS_MUTEX_FAIL
};
// @END_USER@ USER_LOCAL_VARS_DECL

static gnss_ServerApi_t gnssServerApiCtx =
{
  .gnss_set_powerRequestHandler = gnss_set_powerRequestHandlerImpl,
  .gnss_get_powerRequestHandler = gnss_get_powerRequestHandlerImpl,
  .gnss_request_command_executionRequestHandler = gnss_request_command_executionRequestHandlerImpl,
  .gnss_get_command_execution_statusRequestHandler = gnss_get_command_execution_statusRequestHandlerImpl,
  .gnss_set_gnss_uart_baudrateRequestHandler = gnss_set_gnss_uart_baudrateRequestHandlerImpl,
  .gnss_get_gnss_uart_baudrateRequestHandler = gnss_get_gnss_uart_baudrateRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
static void on_gnss_cmd_exec_result_cbk(gnss_cmd_status_t result,
                                        const uint32_t duration_ms,
                                        const uint8_t cmd_id)
{
    gnss_cmd_data_t cmd_data = {0};
    gnss_cmd_status_t res = gnss_get_cmd_status(cmd_id, &cmd_data);

    // update the status if the element is still in the status array
    if (CMD_OK == res)
    {
        cmd_data.cmd_status = result;
        cmd_data.duration_ms = duration_ms;

        res = gnss_set_cmd_status(cmd_id, &cmd_data);
    }

    if (CMD_OK != res)
    {
        if (CMD_NOT_FOUND == res)
        {
            ES_TRACE_WARN("[gnss] (not found) command [%d]", cmd_id);
        }
        else
        {
            ES_TRACE_WARN("[gnss] (update error [%d]) command [%d]", res, cmd_id);
        }
    }
}
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method gnss::set_power (ID = 0x00000001)
static void gnss_set_powerRequestHandlerImpl(ReqContext_t *pReqCtx,
            const gnssset_powerRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    GNSS_Operation_t eOp_status;

    // @USER_VAR_SECTION_START@gnss::set_power@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@gnss::set_power@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@gnss::set_power@

        eOp_status = GNSS_OPERATION_ERROR;

        if (GNSS_POWER_ON == pRequestData->ePwr_status)
        {
            if (STATUS_OK == gnss_run())
            {
                eOp_status = GNSS_OPERATION_OK;
            }
        }
        else
        {
            if (STATUS_OK == gnss_stop())
            {
                eOp_status = GNSS_OPERATION_OK;
            }
        }

        // @USER_CODE_SECTION_END@gnss::set_power@

        respResult = gnss_set_powerResp(
                        &respCtx,
                        eOp_status
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_GNSS, GNSS_SET_POWER_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method gnss::set_power (ID = 0x00000001)

// @START@ Request handler for method gnss::get_power (ID = 0x00000002)
static void gnss_get_powerRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    GNSS_Power_t ePwr_status;
    GNSS_Operation_t eOp_status;

    // @USER_VAR_SECTION_START@gnss::get_power@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@gnss::get_power@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@gnss::get_power@

        eOp_status = GNSS_OPERATION_OK;
        ePwr_status = GNSS_POWER_OFF;

        if (true == gnss_is_on())
        {
            ePwr_status = GNSS_POWER_ON;
        }

        // @USER_CODE_SECTION_END@gnss::get_power@

        respResult = gnss_get_powerResp(
                        &respCtx,
                        ePwr_status,
                        eOp_status
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_GNSS, GNSS_GET_POWER_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method gnss::get_power (ID = 0x00000002)

// @START@ Request handler for method gnss::request_command_execution (ID = 0x00000003)
static void gnss_request_command_executionRequestHandlerImpl(ReqContext_t *pReqCtx,
            const gnssrequest_command_executionRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    uint8_t u8Cmd_id;
    GNSS_CommandStatus_t eCommand_status;

    // @USER_VAR_SECTION_START@gnss::request_command_execution@
    gnss_cmd_status_t status;
    // @USER_VAR_SECTION_END@gnss::request_command_execution@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@gnss::request_command_execution@
        status = gnss_send_cmd(pRequestData->strCmd,
                                pRequestData->u8CmdSize,
                                pRequestData->u32Timeout_ms,
                                &on_gnss_cmd_exec_result_cbk,
                                &u8Cmd_id);

        eCommand_status = gnss_cmd_status_map[status];
        // @USER_CODE_SECTION_END@gnss::request_command_execution@

        respResult = gnss_request_command_executionResp(
                        &respCtx,
                        u8Cmd_id,
                        eCommand_status
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_GNSS, GNSS_REQUEST_COMMAND_EXECUTION_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method gnss::request_command_execution (ID = 0x00000003)

// @START@ Request handler for method gnss::get_command_execution_status (ID = 0x00000004)
static void gnss_get_command_execution_statusRequestHandlerImpl(ReqContext_t *pReqCtx,
            const gnssget_command_execution_statusRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    GNSS_CommandStatus_t eCommand_status;
    uint32_t u32Duration_ms;
    GNSS_TimeStruct_t sRequested_time;
    GNSS_TimeStruct_t sTime_started;

    // @USER_VAR_SECTION_START@gnss::get_command_execution_status@
    gnss_cmd_data_t cmd_data = {0};
    // @USER_VAR_SECTION_END@gnss::get_command_execution_status@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@gnss::get_command_execution_status@
        gnss_cmd_status_t res = gnss_get_cmd_status(pRequestData->u8Cmd_id, &cmd_data);

        if (CMD_OK == res)
        {
            // get times
            static_assert(sizeof(sys_time_t) == sizeof(GNSS_TimeStruct_t));

            memcpy(&sRequested_time, &cmd_data.time_requested, sizeof(GNSS_TimeStruct_t));
            memcpy(&sTime_started, &cmd_data.time_started, sizeof(GNSS_TimeStruct_t));
            u32Duration_ms = cmd_data.duration_ms;
            eCommand_status = gnss_cmd_status_map[cmd_data.cmd_status];
        }
        else
        {
            memset(&sRequested_time, 0, sizeof(GNSS_TimeStruct_t));
            memset(&sTime_started, 0, sizeof(GNSS_TimeStruct_t));
            u32Duration_ms = 0;
            eCommand_status = gnss_cmd_status_map[res];
        }

        // @USER_CODE_SECTION_END@gnss::get_command_execution_status@

        respResult = gnss_get_command_execution_statusResp(
                        &respCtx,
                        eCommand_status,
                        u32Duration_ms,
                        &sRequested_time,
                        &sTime_started
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_GNSS, GNSS_GET_COMMAND_EXECUTION_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method gnss::get_command_execution_status (ID = 0x00000004)

// @START@ Request handler for method gnss::set_gnss_uart_baudrate (ID = 0x00000005)
static void gnss_set_gnss_uart_baudrateRequestHandlerImpl(ReqContext_t *pReqCtx,
            const gnssset_gnss_uart_baudrateRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    GNSS_Operation_t eOp_status;

    // @USER_VAR_SECTION_START@gnss::set_gnss_uart_baudrate@
    eOp_status = GNSS_OPERATION_ERROR;
    GNSS_BaudRate_t baudrate;
    // @USER_VAR_SECTION_END@gnss::set_gnss_uart_baudrate@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@gnss::set_gnss_uart_baudrate@
        baudrate = pRequestData->eBaud_rate;

        if ((true == gnss_uart_baudrate_set(&baudrate)) &&
            (true == configure_all_logs()))
        {
            ES_TRACE_DEBUG("[gnss] baudrate set to %d", gnss_uart_baudrate_map(baudrate));
            eOp_status = GNSS_OPERATION_OK;
        }
        // @USER_CODE_SECTION_END@gnss::set_gnss_uart_baudrate@

        respResult = gnss_set_gnss_uart_baudrateResp(
                        &respCtx,
                        eOp_status
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_GNSS, GNSS_SET_GNSS_UART_BAUDRATE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method gnss::set_gnss_uart_baudrate (ID = 0x00000005)

// @START@ Request handler for method gnss::get_gnss_uart_baudrate (ID = 0x00000006)
static void gnss_get_gnss_uart_baudrateRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    GNSS_BaudRate_t eGnss_uart_baudrate_nvm;
    GNSS_BaudRate_t eGnss_uart_baudrate_current;
    GNSS_Operation_t eOp_status;

    // @USER_VAR_SECTION_START@gnss::get_gnss_uart_baudrate@
    eOp_status = GNSS_OPERATION_ERROR;
    eGnss_uart_baudrate_nvm = GNSS_BAUDRATE_BAUD_9600_BPS;
    eGnss_uart_baudrate_current = GNSS_BAUDRATE_BAUD_9600_BPS;
    // @USER_VAR_SECTION_END@gnss::get_gnss_uart_baudrate@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@gnss::get_gnss_uart_baudrate@
        if (true == gnss_uart_baudrate_get(
                                    &eGnss_uart_baudrate_nvm,
                                    &eGnss_uart_baudrate_current))
        {
            eOp_status = GNSS_OPERATION_OK;
        }
        // @USER_CODE_SECTION_END@gnss::get_gnss_uart_baudrate@

        respResult = gnss_get_gnss_uart_baudrateResp(
                        &respCtx,
                        eGnss_uart_baudrate_nvm,
                        eGnss_uart_baudrate_current,
                        eOp_status
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_GNSS, GNSS_GET_GNSS_UART_BAUDRATE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method gnss::get_gnss_uart_baudrate (ID = 0x00000006)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void gnssServerAppInit(void)
{
    gnss_registerServerApi(&gnssServerApiCtx);
}
