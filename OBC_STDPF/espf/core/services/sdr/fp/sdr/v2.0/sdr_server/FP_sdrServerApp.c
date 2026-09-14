/*!
********************************************************************************************
* @file FP_sdrServerApp.c
* @brief ServerApp implementation template generator
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

#include "FP_sdrProtocolServer.h"

// @START_USER@ USER_INCLUDES
#include "sdr_sm_config_user.h"
#include "sdr_sm_user.h"
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL

/**
 * @brief Converts an internal sdr status to a FIDL status
 * @param [in] sdr_res_internal internal status provided by sdr
 * 
 * @return FIDL sdr status
 */
static SDR_FileStatus_t convert_sdr_res_internal(const es_tftp_err_code_t sdr_res_internal);

/**
 * @brief Converts an internal sdr state to a FIDL state
 * @param [in] sdr_state_internal internal state provided by sdr
 * 
 * @return FIDL sdr state
 */
static SDR_StateMachineState_t convert_sdr_state_internal(const uint8_t sdr_state_internal);

// @END_USER@ USER_LOCAL_FUNC_DECL
static void sdr_sdr_uploadRequestHandlerImpl(ReqContext_t* pReqCtx,
            const sdrsdr_uploadRequestData_t* pRequestData);

static void sdr_sdr_downloadRequestHandlerImpl(ReqContext_t* pReqCtx,
            const sdrsdr_downloadRequestData_t* pRequestData);

static void sdr_sdr_poll_latest_ft_statusRequestHandlerImpl(ReqContext_t* pReqCtx);

static void sdr_sdr_get_stateRequestHandlerImpl(ReqContext_t* pReqCtx);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_VARS_DECL

static sdr_ServerApi_t sdrServerApiCtx =
{
  .sdr_sdr_uploadRequestHandler = sdr_sdr_uploadRequestHandlerImpl,
  .sdr_sdr_downloadRequestHandler = sdr_sdr_downloadRequestHandlerImpl,
  .sdr_sdr_poll_latest_ft_statusRequestHandler = sdr_sdr_poll_latest_ft_statusRequestHandlerImpl,
  .sdr_sdr_get_stateRequestHandler = sdr_sdr_get_stateRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
static SDR_StateMachineState_t convert_sdr_state_internal(const uint8_t sdr_state_internal)
{
    switch (sdr_state_internal)
    {
        case SDR_SM_STATE_INACTIVE:
        {
            return SDR_STATEMACHINESTATE_INACTIVE;
        }

        case SDR_SM_STATE_BOOTING:
        {
            return SDR_STATEMACHINESTATE_BOOTING;
        }

        case SDR_SM_STATE_SYNCING:
        {
            return SDR_STATEMACHINESTATE_SYNCING;
        }

        case SDR_SM_STATE_READY:
        {
            return SDR_STATEMACHINESTATE_READY;
        }

        case SDR_SM_STATE_BUSY:
        {
            return SDR_STATEMACHINESTATE_BUSY;
        }

        default:
        {
            return SDR_STATEMACHINESTATE_MAX_CNT;
        }
    }
}

static SDR_FileStatus_t convert_sdr_res_internal(const es_tftp_err_code_t sdr_res_internal)
{
    switch (sdr_res_internal)
    {
        case ES_TFTP_ERR_NOT_DEFINED:
        {
            return SDR_FILESTATUS_ES_TFTP_ERR_NOT_DEFINED;
        }

        case ES_TFTP_ERR_FILE_NOT_FOUND:
        {
            return SDR_FILESTATUS_ES_TFTP_ERR_FILE_NOT_FOUND;
        }

        case ES_TFTP_ERR_ACESS_VIOLATION:
        {
            return SDR_FILESTATUS_ES_TFTP_ERR_ACESS_VIOLATION;
        }

        case ES_TFTP_ERR_DISK_FULL_OR_ALLOCATION_EXCEEDED:
        {
            return SDR_FILESTATUS_ES_TFTP_ERR_DISK_FULL_OR_ALLOCATION_EXCEEDED;
        }

        case ES_TFTP_ERR_ILLEGAL_TFTP_OPERATION:
        {
            return SDR_FILESTATUS_ES_TFTP_ERR_ILLEGAL_TFTP_OPERATION;
        }

        case ES_TFTP_ERR_UNKNOWN_TRANSFER_ID:
        {
            return SDR_FILESTATUS_ES_TFTP_ERR_UNKNOWN_TRANSFER_ID;
        }

        case ES_TFTP_ERR_FILE_ALREADY_EXISTS:
        {
            return SDR_FILESTATUS_ES_TFTP_ERR_FILE_ALREADY_EXISTS;
        }

        case ES_TFTP_ERR_NO_SUCH_USER:
        {
            return SDR_FILESTATUS_ES_TFTP_ERR_NO_SUCH_USER;
        }

        case ES_TFTP_STATUS_OK:
        {
            return SDR_FILESTATUS_ES_TFTP_STATUS_OK;
        }

        case ES_TFTP_TL_NOT_INIT:
        {
            return SDR_FILESTATUS_ES_TFTP_TL_NOT_INIT;
        }

        case ES_TFTP_CANNOT_OPEN_DEST_FILE_FOR_WRITE:
        {
            return SDR_FILESTATUS_ES_TFTP_CANNOT_OPEN_DEST_FILE_FOR_WRITE;
        }

        case ES_TFTP_FAILED_TO_WRITE_TO_DEST_FILE:
        {
            return SDR_FILESTATUS_ES_TFTP_FAILED_TO_WRITE_TO_DEST_FILE;
        }

        case ES_TFTP_FAILED_TO_CLOSE_DEST_FILE:
        {
            return SDR_FILESTATUS_ES_TFTP_FAILED_TO_CLOSE_DEST_FILE;
        }

        case ES_TFTP_CANNOT_OPEN_SOURCE_FILE_FOR_READ:
        {
            return SDR_FILESTATUS_ES_TFTP_CANNOT_OPEN_SOURCE_FILE_FOR_READ;
        }

        case ES_TFTP_FILE_NOT_FOUND_ON_SOURCE:
        {
            return SDR_FILESTATUS_ES_TFTP_FILE_NOT_FOUND_ON_SOURCE;
        }

        case ES_TFTP_FAILED_TO_READ_FROM_SOURCE_FILE:
        {
            return SDR_FILESTATUS_ES_TFTP_FAILED_TO_READ_FROM_SOURCE_FILE;
        }

        case ES_TFTP_FAILED_TO_CLOSE_SOURCE_FILE:
        {
            return SDR_FILESTATUS_ES_TFTP_FAILED_TO_CLOSE_SOURCE_FILE;
        }

        case ES_TFTP_CONNECTION_TO_SERVER_FAILED:
        {
            return SDR_FILESTATUS_ES_TFTP_CONNECTION_TO_SERVER_FAILED;
        }

        case ES_TFTP_FAILED_TO_DISCONNECT_FROM_SERVER:
        {
            return SDR_FILESTATUS_ES_TFTP_FAILED_TO_DISCONNECT_FROM_SERVER;
        }

        case ES_TFTP_RECV_FAILED:
        {
            return SDR_FILESTATUS_ES_TFTP_RECV_FAILED;
        }

        case ES_TFTP_SEND_FAILED:
        {
            return SDR_FILESTATUS_ES_TFTP_SEND_FAILED;
        }

        case ES_TFTP_BLOCK_NUMBER_MISMATCH:
        {
            return SDR_FILESTATUS_ES_TFTP_BLOCK_NUMBER_MISMATCH;
        }

        case ES_TFTP_DOWNLOADED_FILE_EMPTY:
        {
            return SDR_FILESTATUS_ES_TFTP_DOWNLOADED_FILE_EMPTY;
        }

        case ES_TFTP_TRANSFER_PENDING:
        {
            return SDR_FILESTATUS_ES_TFTP_TRANSFER_PENDING;
        }

        case ES_TFTP_BUSY:
        {
            return SDR_FILESTATUS_ES_TFTP_BUSY;
        }

        default:
        {
            return SDR_FILESTATUS_ES_TFTP_ERR_NOT_DEFINED;
        }
    }
}
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method sdr::sdr_upload (ID = 0x00000000)
static void sdr_sdr_uploadRequestHandlerImpl(ReqContext_t *pReqCtx,
            const sdrsdr_uploadRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    SDR_FileStatus_t eStatus;

    // @USER_VAR_SECTION_START@sdr::sdr_upload@
    sdr_file_op_t file_op = {0};
    es_tftp_err_code_t upload_result = ES_TFTP_ERR_NOT_DEFINED;
    // @USER_VAR_SECTION_END@sdr::sdr_upload@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@sdr::sdr_upload@

        // set request type
        sdr_rt_context.sdr_op_req.op = OP_FILE_TRANSFER;

        // construct upload request
        file_op.ft_op = UPLOAD;
        file_op.obc_file = pRequestData->sFile.strObc_file;
        file_op.sdr_file = pRequestData->sFile.strSdr_file;

        // set & execute request
        if (true == ft_op_set(&file_op))
        {
            upload_result = ES_TFTP_TRANSFER_PENDING;
        }
        else
        {
            upload_result = ES_TFTP_BUSY;
        }

        eStatus = convert_sdr_res_internal(upload_result);

        // @USER_CODE_SECTION_END@sdr::sdr_upload@

        respResult = sdr_sdr_uploadResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_SDR, SDR_SDR_UPLOAD_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method sdr::sdr_upload (ID = 0x00000000)

// @START@ Request handler for method sdr::sdr_download (ID = 0x00000001)
static void sdr_sdr_downloadRequestHandlerImpl(ReqContext_t *pReqCtx,
            const sdrsdr_downloadRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    SDR_FileStatus_t eStatus;

    // @USER_VAR_SECTION_START@sdr::sdr_download@
    sdr_file_op_t file_op = {0};
    es_tftp_err_code_t download_result = ES_TFTP_ERR_NOT_DEFINED;
    // @USER_VAR_SECTION_END@sdr::sdr_download@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@sdr::sdr_download@

        // set request type
        sdr_rt_context.sdr_op_req.op = OP_FILE_TRANSFER;

        // construct download request
        file_op.ft_op = DOWNLOAD;
        file_op.obc_file = pRequestData->sFile.strObc_file;
        file_op.sdr_file = pRequestData->sFile.strSdr_file;

        // set & execute request
        if (true == ft_op_set(&file_op))
        {
            download_result = ES_TFTP_TRANSFER_PENDING;
        }
        else
        {
            download_result = ES_TFTP_BUSY;
        }

        eStatus = convert_sdr_res_internal(download_result);

        // @USER_CODE_SECTION_END@sdr::sdr_download@

        respResult = sdr_sdr_downloadResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_SDR, SDR_SDR_DOWNLOAD_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method sdr::sdr_download (ID = 0x00000001)

// @START@ Request handler for method sdr::sdr_poll_latest_ft_status (ID = 0x00000002)
static void sdr_sdr_poll_latest_ft_statusRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    SDR_FileStatus_t eStatus;

    // @USER_VAR_SECTION_START@sdr::sdr_poll_latest_ft_status@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@sdr::sdr_poll_latest_ft_status@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@sdr::sdr_poll_latest_ft_status@
        es_tftp_err_code_t poll_result = sdr_poll_file_transfer_status();
        eStatus = convert_sdr_res_internal(poll_result);
        // @USER_CODE_SECTION_END@sdr::sdr_poll_latest_ft_status@

        respResult = sdr_sdr_poll_latest_ft_statusResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_SDR, SDR_SDR_POLL_LATEST_FT_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method sdr::sdr_poll_latest_ft_status (ID = 0x00000002)

// @START@ Request handler for method sdr::sdr_get_state (ID = 0x00000003)
static void sdr_sdr_get_stateRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    SDR_StateMachineState_t eSm_state;

    // @USER_VAR_SECTION_START@sdr::sdr_get_state@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@sdr::sdr_get_state@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@sdr::sdr_get_state@
        uint8_t active_state;
        sdr_get_state(&active_state);
        eSm_state = convert_sdr_state_internal(active_state);
        // @USER_CODE_SECTION_END@sdr::sdr_get_state@

        respResult = sdr_sdr_get_stateResp(
                        &respCtx,
                        eSm_state
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_SDR, SDR_SDR_GET_STATE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method sdr::sdr_get_state (ID = 0x00000003)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void sdrServerAppInit(void)
{
    sdr_registerServerApi(&sdrServerApiCtx);
}
