/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup cp
 * @{
 *
 * @file    cp_cmd_handler.c
 * @brief   Command Protocol commands declarations
 *
 * @}
 */

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "cmsis_os2.h"
#include "ESSA_Stack_TP_Layer.h"
#include "cp_cmd_handler.h"

#include "cubeadcs_usercmds.h"
#include "CP_Handler.h"
#include "ESPLATFORM_NETWORK_STACK/ES_TL_LAYER/ES_TL_Layer.h"
#include "module_id.h"
#include "ESCP_CommandsLocalConf.h"
#include "es_exeh.h"
#include "FWUPD_Persistor.h"
#include "ESPLATFORM_NETWORK_STACK/ES_SAT_API/include/ESSA_Stack.h"
#include "DataSink.h"
#include "fm_mng.h"

#if defined(COMM_GW_ENABLED)
#include "comm_gw.h"
#endif

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
#define NULL_TERMINATOR_LEN           ((uint8_t)1)
#define SHORTEST_POSSIBLE_FNAME_LEN   ((uint8_t)1 + NULL_TERMINATOR_LEN)
#define MAX_FILE_PATH                 ((uint8_t)FM_MAX_PATH)
#define FILEDOWNLOAD_CRCREAD_BUF_SIZE ((uint16_t)512)

#define MACFPGW_RESPONSE_TIMEOUT_MS  ((uint32_t)4000)
#define CUBEADCS_RESPONSE_TIMEOUT_MS ((uint32_t)4000)
#define CP_CMD_RESPONSE_TIMEOUT_MS   ((uint32_t)300000UL) /**< maximum time to wait for a response */

#define MACFPGW_IF_ID     (ESSASNI_PAY_PRI)
#define FILE_DW_ERROR_MSG "FILE DOWNLOAD ERROR"

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

typedef struct
{
    // size of GW frame which includes the MAC FP header and data payload
    uint8_t payload_size;
} PACKED mac_fp_gw_hdr_t;

typedef struct
{
    uint32_t file_offset;
    char     file_path[MAX_FILE_PATH];
} PACKED dw_file_by_chunks_in_args_t;

typedef struct
{
    const char  error_msg[sizeof(FILE_DW_ERROR_MSG)]; /**< Human readable error message to make it clear to the user that the operation failed and the returned content is not the real requested file */
    fm_result_t error;                                /**< File System Error ID */
    uint32_t    src_line_no;                          /**< Line number where the file system error was detected */
} PACKED dw_file_error_result_t;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
// CP command GW response context (only one because only one CP command can be served at a time)
static sUserResponseCtx_t user_resp_ctx;

// static context for the CPCmdHandler_DownloadFileByChunks() handler which needs to
// exchange data with the dw_file_by_chunks_cbk callback
static dw_file_by_chunks_in_args_t dw_file_by_chunks_in_args = {
    .file_offset = 0,
    .file_path   = "\0"
};

static dw_file_error_result_t dw_file_error_result = {
    .error_msg   = FILE_DW_ERROR_MSG,
    .error       = FM_RES_OK,
    .src_line_no = 0U
};

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
static void        on_cmd_response_ready_cbk(void *const p_user_ctx);
static inline void dw_store_error_res(const fm_result_t error, const uint32_t src_line_no);
static uint8_t     dw_file_by_chunks_cbk(const uint64_t cmd_id,
                                         const uint32_t cmd_type,
                                         const uint32_t required_chunk_size,
                                         const uint32_t offset,
                                         uint8_t       *p_chunk);
static bool        b_calc_file_crc(const uint32_t file_offset, uint8_t *const p_buff, const uint32_t buff_size);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
void cp_cmd_handler_init(void)
{
    // Will probably do something meaningful in the future...
    return;
}

// this function will be called by the ESSA Stack when the FP layer replies back to the received CP request
ESSATMAC_ErrCodes cp_cmd_handler_mac_fp_gw_enq_message(const ESSATMAC_Context *p_mac_ctx, const uint8_t *p_msg_data, uint8_t msg_data_sz)
{
    ESSATMAC_ErrCodes result = ESSATMAC_EC_ERROR;

    if ((p_mac_ctx != NULL) && (p_msg_data != NULL) && (msg_data_sz >= sizeof(mac_fp_gw_hdr_t)))
    {
        if ((p_mac_ctx->netType == ESSASNETT_GS_MACFP_GW) &&
            (p_mac_ctx->nInterfaceNumber == MACFPGW_IF_ID) &&
            (p_mac_ctx->nPayloadProtocol == ES_SAT_MAC_PROTOCOL_ID_FP_LAYER) &&
            (user_resp_ctx.pu8DataBuf != NULL) &&
            (user_resp_ctx.u32MaxDataSize >= msg_data_sz))
        {
            // transfer message data back to CP buffer
            (void)memcpy(user_resp_ctx.pu8DataBuf, p_msg_data, msg_data_sz);

            // store actual data size for CP command reply dispatch in cp_cmd_handler_mac_fp_gw_send_cmd(...)
            user_resp_ctx.u32ResponseSize = msg_data_sz;

            ESSA_Stack_TP_Layer_ReleaseThreadWait();

            result = ESSATMAC_EC_OK;
        }
        else
        {
            result = ESSATMAC_EC_INVALID_PARAMS;
        }
    }

    return result;
}

eCPDispatchResult_t cp_cmd_handler_mac_fp_gw_send_cmd(sCPDispatchContext_t *const p_disp_ctx)
{
    if (!CPCmdHandler_IsDispContextValid(p_disp_ctx, CP_CMD_MACFP_GWSEND))
    {
        return ECPDISPATCHRESULT_ERROR;
    }

    ESSATMAC_Context       mac_ctx;
    const mac_fp_gw_hdr_t *p_fp_gw_hdr = (const mac_fp_gw_hdr_t *)p_disp_ctx->pu8CmdData;

    if (p_disp_ctx->u32CmdDataSize >= p_fp_gw_hdr->payload_size)
    {
        (void)memset((void *)&mac_ctx, (uint8_t)0, sizeof(ESSATMAC_Context));

        // setup response buffer for ESSA Stack
        user_resp_ctx.pu8DataBuf         = p_disp_ctx->pu8ResponseBuf;
        user_resp_ctx.u32MaxDataSize     = p_disp_ctx->u32ResponseBufSize;
        user_resp_ctx.u32ResponseSize    = 0U;
        user_resp_ctx.onCmdResponseReady = NULL;
        user_resp_ctx.pUserCtx           = NULL;

        mac_ctx.nInterfaceNumber = MACFPGW_IF_ID;
        mac_ctx.nPayloadProtocol = ES_SAT_MAC_PROTOCOL_ID_FP_LAYER;
        mac_ctx.nSourceAddr      = 0x00U;
        mac_ctx.nTargetAddr      = 0x00U;
        mac_ctx.netType          = ESSASNETT_GS_MACFP_GW;

        eThreadBlockEvt_t waitResult = THREADBLOCKEVT_ERROR;

        if (false != ESSA_Stack_TP_Layer_PrepareThreadWait())
        {
            // inject message to ESSA Stack for FP dispatching...
            ESSA_Stack_DataDispatch(&mac_ctx,
                                    &p_disp_ctx->pu8CmdData[sizeof(mac_fp_gw_hdr_t)],
                                    p_fp_gw_hdr->payload_size);

            // wait for cp_cmd_handler_mac_fp_gw_enq_message() to be called or timeout...
            waitResult = ESSA_Stack_TP_Layer_ThreadWaitForEvent(CPCmdHandler_GetTimeout(p_disp_ctx, MACFPGW_RESPONSE_TIMEOUT_MS));
        }
        else
        {
            // Error - another thread is already waiting
        }

        if (waitResult == THREADBLOCKEVT_WAITFINISHED)
        {
            if (p_disp_ctx->u32ResponseBufSize >= sizeof(ESSA_Stack_FP_MsgHdr_t))
            {
                // user-data is already written in the response buffer
                p_disp_ctx->u32ResponseActualSize = user_resp_ctx.u32ResponseSize;
                p_disp_ctx->u8TLError             = EESTL_SFERR_SUCCESS;
            }
            else
            {
                p_disp_ctx->u32ResponseActualSize = 0U;
                p_disp_ctx->u8TLError             = EESTL_SFERR_OUT_OF_MEM;
            }
        }
        else if (waitResult == THREADBLOCKEVT_WAITTIMEOUT)
        {
            p_disp_ctx->u32ResponseActualSize = 0U;
            p_disp_ctx->u8TLError             = EESTL_SFERR_RECEIVE_TIMEOUT;
        }
        else
        {
            (void)memcpy(p_disp_ctx->pu8ResponseBuf, &waitResult, sizeof(waitResult));
            p_disp_ctx->u32ResponseActualSize = sizeof(waitResult);
            p_disp_ctx->u8TLError             = EESTL_SFERR_UNKNOWN;
        }
    }
    else
    {
        p_disp_ctx->u32ResponseActualSize = 0U;
        p_disp_ctx->u8TLError             = EESTL_SFERR_BAD_CMD_PARAMS;
    }

    return ECPDISPATCHRESULT_RESULT_OK;
}

#if defined(COMM_GW_ENABLED)

/** @brief COMM GW FP request header used as a CP command wrapper */
typedef struct
{
    uint8_t                  if_id;        /**< COMM GW interface ID (see @ref comm_gw_if_id_t type for available options )*/
    comm_gw_fp_comm_params_t comm_params;  /**< FP communication parameters */
    uint32_t                 resp_timeout; /**< response timeout in milliseconds */
    uint32_t                 req_size;     /**< size of the request in bytes */
} comm_gw_fp_hdr_t;

#if defined(CSP_SUPPORT_ENABLED)
/** @brief COMM GW CSP request header used as a CP command wrapper */
typedef struct
{
    uint8_t                   if_id;        /**< COMM GW interface ID (see @ref comm_gw_if_id_t type for available options )*/
    comm_gw_csp_comm_params_t comm_params;  /**< CSP communication parameters */
    uint32_t                  resp_timeout; /**< response timeout in milliseconds */
    uint32_t                  req_size;     /**< size of the request in bytes */
} PACKED comm_gw_csp_hdr_t;
#endif

typedef struct
{
    uint8_t  comm_gw_res;
    uint32_t resp_size;
} PACKED comm_gw_cp_response_t;

/** @brief A mapping between COMM GW IF and the size of the communication parameters structure used to properly calculate
 *  the offset to the request start...
 */
static const uint32_t comm_gw_params_size_map[COMM_GW_IF_ID_MAX] = {
    [COMM_GW_IF_ID_FP]  = sizeof(comm_gw_fp_comm_params_t),
    [COMM_GW_IF_ID_CP]  = sizeof(comm_gw_cp_comm_params_t),
    [COMM_GW_IF_ID_CSP] = sizeof(comm_gw_csp_comm_params_t)
};

/** @brief Return the comm_gw interface ID corresponding to a given comm_gw CP ID
 *
 *  @param[in] cmd_id CP command ID
 *  @return comm_gw interface ID
 */
static comm_gw_if_id_t get_gw_id_by_cp_cmd_id(const uint32_t cmd_id)
{
    switch (cmd_id)
    {
        case CP_CMD_COMM_GW_FP_SEND:
            {
                return COMM_GW_IF_ID_FP;
            }

        case CP_CMD_COMM_GW_CSP_SEND:
            {
                return COMM_GW_IF_ID_CSP;
            }

        default:
            {
                return COMM_GW_IF_ID_FP;
            }
    }
}

eCPDispatchResult_t cp_cmd_handler_comm_gw_generic_send(sCPDispatchContext_t *const p_disp_ctx)
{
    if (!((p_disp_ctx != NULL) &&
          // CP comm_gw extension is not usable through this CP command because it doesn't make sense - you can
          // execute CP commands directly and there is no need to go through comm_gw from GS CP context
          ((p_disp_ctx->u32CmdType == CP_CMD_COMM_GW_FP_SEND) || (p_disp_ctx->u32CmdType == CP_CMD_COMM_GW_CSP_SEND)) &&
          (p_disp_ctx->pu8CmdData != NULL) &&
          (p_disp_ctx->pu8ResponseBuf != NULL) &&
          (p_disp_ctx->u32ResponseBufSize > 0U)))
    {
        return ECPDISPATCHRESULT_ERROR;
    }

    comm_gw_if_id_t comm_gw_if_id = get_gw_id_by_cp_cmd_id(p_disp_ctx->u32CmdType);

    comm_gw_send_ctx_t     gw_send_ctx;
    comm_gw_comm_res_t     gw_res;
    comm_gw_cp_response_t *gw_resp           = (comm_gw_cp_response_t *)p_disp_ctx->pu8ResponseBuf;
    const uint32_t         resp_timeout_offs = comm_gw_params_size_map[(uint8_t)comm_gw_if_id];
    const uint32_t         req_size_offs     = resp_timeout_offs + sizeof(uint32_t);
    const uint32_t         req_buf_offs      = req_size_offs + sizeof(uint32_t);

    // passing a pointer to a stack variable here is safe because comm_gw functions are blocking and will return control
    // only after completion of the operation
    gw_send_ctx.p_comm_params      = (const void *)p_disp_ctx->pu8CmdData;
    gw_send_ctx.p_req_data         = &p_disp_ctx->pu8CmdData[req_buf_offs];
    gw_send_ctx.req_data_size      = *(const uint32_t *)&p_disp_ctx->pu8CmdData[req_size_offs];
    gw_send_ctx.p_resp_data        = &p_disp_ctx->pu8ResponseBuf[sizeof(comm_gw_cp_response_t)];
    gw_send_ctx.resp_data_max_size = (p_disp_ctx->u32ResponseBufSize > sizeof(comm_gw_cp_response_t)) ? (p_disp_ctx->u32ResponseBufSize - sizeof(comm_gw_cp_response_t)) : 0;
    gw_send_ctx.p_resp_data_size   = &p_disp_ctx->u32ResponseActualSize;
    gw_send_ctx.resp_timeout       = *(const uint32_t *)&p_disp_ctx->pu8CmdData[resp_timeout_offs];

    if (gw_send_ctx.resp_timeout > CP_CMD_RESPONSE_TIMEOUT_MS)
    {
        gw_send_ctx.resp_timeout = CP_CMD_RESPONSE_TIMEOUT_MS;
    }

    // this is a blocking call...
    gw_res = comm_gw_send(comm_gw_if_id, COMM_GW_USER_ID_CP_HANDLER, &gw_send_ctx);

    gw_resp->comm_gw_res = (uint8_t)gw_res;
    gw_resp->resp_size   = p_disp_ctx->u32ResponseActualSize;

    // add CP response header size to the overall response size, otherwise the message will be truncated
    p_disp_ctx->u32ResponseActualSize += sizeof(comm_gw_cp_response_t);

    p_disp_ctx->u8TLError = EESTL_SFERR_SUCCESS;

    return ECPDISPATCHRESULT_RESULT_OK;
}

#endif

eCPDispatchResult_t cp_cmd_handler_cubeadcs_gw_send_cmd(sCPDispatchContext_t *const p_disp_ctx)
{
    if (!CPCmdHandler_IsDispContextValid(p_disp_ctx, CP_CMD_CUBEADCS_GWSEND))
    {
        return ECPDISPATCHRESULT_ERROR;
    }

    p_disp_ctx->u32ResponseActualSize = 0U;

    if (sys_conf_is_module_active(SYS_MODULE_ID_CUBE_ADCS))
    {
        bool bSendCmdStatus = true;

        CubeADCS_CmdCfg_t sCmd;

        sCmd.u8CmdID = p_disp_ctx->pu8CmdData[0];

        sCmd.u16CmdDataSize = (uint16_t)(p_disp_ctx->u32CmdDataSize - sizeof(sCmd.u8CmdID));

        if (p_disp_ctx->u32CmdDataSize == sizeof(sCmd.u8CmdID))
        {
            sCmd.pu8CmdData = NULL;
        }
        else
        {
            sCmd.pu8CmdData = (uint8_t *)&p_disp_ctx->pu8CmdData[sizeof(sCmd.u8CmdID)];
        }

        if (p_disp_ctx->u32CmdDataSize >= sCmd.u16CmdDataSize + sizeof(sCmd.u8CmdID))
        {
            user_resp_ctx.pu8DataBuf         = p_disp_ctx->pu8ResponseBuf;
            user_resp_ctx.u32MaxDataSize     = p_disp_ctx->u32ResponseBufSize;
            user_resp_ctx.u32ResponseSize    = 0U;
            user_resp_ctx.onCmdResponseReady = on_cmd_response_ready_cbk;
            user_resp_ctx.pUserCtx           = (void *)&user_resp_ctx;

            sCmd.pvCmdResDst      = (void *)user_resp_ctx.pu8DataBuf;
            sCmd.u16CmdResDstSize = (uint16_t)user_resp_ctx.u32MaxDataSize;
            sCmd.u16CmdResSize    = (uint16_t *)&p_disp_ctx->u32ResponseActualSize;

            if (false != ESSA_Stack_TP_Layer_PrepareThreadWait())
            {
                bSendCmdStatus = CubeADCS_UsrCmd_CmdHandler(eCUBEADCS_USR_CMDS_GENERIC, &sCmd, &user_resp_ctx);
            }
            else
            {
                p_disp_ctx->u8TLError = EESTL_SFERR_UNKNOWN;
            }

            if (!bSendCmdStatus)
            {
                // block here to wait answer from CUBE_ADCS...
                eThreadBlockEvt_t waitResult = ESSA_Stack_TP_Layer_ThreadWaitForEvent(CPCmdHandler_GetTimeout(p_disp_ctx, CUBEADCS_RESPONSE_TIMEOUT_MS));

                if (waitResult == THREADBLOCKEVT_WAITFINISHED)
                {
                    if (user_resp_ctx.u32ResponseSize <= p_disp_ctx->u32ResponseBufSize)
                    {
                        // user-data is already written in the response buffer which was passed before the call to
                        // CubeADCS_UsrCmd_CmdHandler(...)
                        p_disp_ctx->u32ResponseActualSize = user_resp_ctx.u32ResponseSize;
                        p_disp_ctx->u8TLError             = EESTL_SFERR_SUCCESS;
                    }
                    else
                    {
                        p_disp_ctx->u8TLError = EESTL_SFERR_OUT_OF_MEM;
                    }
                }
                else if (waitResult == THREADBLOCKEVT_WAITTIMEOUT)
                {
                    p_disp_ctx->u8TLError = EESTL_SFERR_RECEIVE_TIMEOUT;
                }
                else
                {
                    (void)memcpy(p_disp_ctx->pu8ResponseBuf, &waitResult, sizeof(waitResult));
                    p_disp_ctx->u32ResponseActualSize = sizeof(waitResult);
                    p_disp_ctx->u8TLError             = EESTL_SFERR_UNKNOWN;
                }
            }
            else
            {
                p_disp_ctx->u8TLError = EESTL_SFERR_BAD_CMD_PARAMS;
            }
        }
        else
        {
            p_disp_ctx->u8TLError = EESTL_SFERR_BAD_CMD_PARAMS;
        }
    }
    else // not SYS_MODULE_ID_CUBE_ADCS
    {
        p_disp_ctx->u8TLError = EESTL_SFERR_CMD_NOT_SUPP;
    }

    return ECPDISPATCHRESULT_RESULT_OK;
}

//
//  File-commands section
//

eCPDispatchResult_t cp_cmd_handler_download_file(sCPDispatchContext_t *const p_disp_ctx)
{
    eCPDispatchResult_t res       = ECPDISPATCHRESULT_ERROR;
    uint32_t            file_size = 0U;
    fm_fast_file_info_t ffi       = { 0 };

    if (CPCmdHandler_IsDispContextValid(p_disp_ctx, CP_CMD_DBG_DOWNLOADFILE))
    {
        // 4 bytes for file_offset parameter and a valid file name(1 symbol and Null terminator)
        if (p_disp_ctx->u32CmdDataSize >=
            sizeof(dw_file_by_chunks_in_args.file_offset) + SHORTEST_POSSIBLE_FNAME_LEN)
        {
            dw_file_by_chunks_in_args = *((dw_file_by_chunks_in_args_t *)p_disp_ctx->pu8CmdData);

            // clear any pending errors
            dw_file_error_result.error       = FM_RES_OK;
            dw_file_error_result.src_line_no = 0U;

            fm_result_t fres = fm_stat(dw_file_by_chunks_in_args.file_path, &ffi);
            if (FM_RES_OK == fres)
            {
                file_size = ffi.size;
                if (file_size > dw_file_by_chunks_in_args.file_offset)
                {
                    file_size -= dw_file_by_chunks_in_args.file_offset;
                    // does the file fit in a single response buffer?
                    if (file_size <= p_disp_ctx->u32ResponseBufSize)
                    {
                        // file fits, just read it in the current buffer and respond back
                        // NOTE:
                        //      Ensure that dw_file_by_chunks_in_args already contains the file path information
                        //      because the following function doesn't accept a context parameter and shall somehow
                        //      know which file to attempt to read
                        uint8_t cbk_res = dw_file_by_chunks_cbk(0U,
                                                                CP_CMD_DBG_DOWNLOADFILE,
                                                                file_size,
                                                                dw_file_by_chunks_in_args.file_offset,
                                                                p_disp_ctx->pu8ResponseBuf);

                        if (cbk_res == EESTL_SFERR_SUCCESS)
                        {
                            p_disp_ctx->u32ResponseActualSize = file_size;
                            p_disp_ctx->u8TLError             = EESTL_SFERR_SUCCESS;
                            res                               = ECPDISPATCHRESULT_RESULT_OK;
                        }
                    }
                    else
                    { // file doesn't fit, therefore request chunk-based transfer to GS
                        // prepare file CRC before triggering chunk-based transfer
                        uint8_t crc_tmp_buff[FILEDOWNLOAD_CRCREAD_BUF_SIZE];
                        if (b_calc_file_crc(dw_file_by_chunks_in_args.file_offset, crc_tmp_buff, sizeof(crc_tmp_buff)))
                        {
                            p_disp_ctx->pChunkRequestCbk      = dw_file_by_chunks_cbk;
                            p_disp_ctx->u32ResponseActualSize = file_size;
                            p_disp_ctx->u8TLError             = EESTL_SFERR_SUCCESS;
                            res                               = ECPDISPATCHRESULT_RESULT_BY_CHUNKS;
                        }
                    }
                }
                else
                {
                    p_disp_ctx->u32ResponseActualSize = 0;
                    p_disp_ctx->u8TLError             = EESTL_SFERR_SUCCESS;
                    res                               = ECPDISPATCHRESULT_RESULT_OK;
                }
            }
            else
            {
                dw_store_error_res(fres, __LINE__);
            }
        }
        else
        {
            p_disp_ctx->u32ResponseActualSize = 0U;
            p_disp_ctx->u8TLError             = EESTL_SFERR_BAD_CMD_PARAMS;
            res                               = ECPDISPATCHRESULT_SIMPLERESULT_OK;
        }
    }

    if (ECPDISPATCHRESULT_ERROR == res)
    {
        // attempt to make a human-readable error message
        int32_t ch_count = (int32_t)snprintf((char *volatile)p_disp_ctx->pu8ResponseBuf,
                                             (size_t)(p_disp_ctx->u32ResponseBufSize),
                                             "%s: %d @ line: %lu\n",
                                             FILE_DW_ERROR_MSG,
                                             dw_file_error_result.error,
                                             dw_file_error_result.src_line_no);

        if (ch_count > 0)
        {
            p_disp_ctx->u32ResponseActualSize = (uint32_t)ch_count;
        }
        else
        {
            (void)memcpy(p_disp_ctx->pu8ResponseBuf, &dw_file_error_result, sizeof(dw_file_error_result));
            p_disp_ctx->u32ResponseActualSize = sizeof(dw_file_error_result);
        }

        p_disp_ctx->u8TLError = EESTL_SFERR_SUCCESS;
        res                   = ECPDISPATCHRESULT_RESULT_OK;
    }

    return res;
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

static void on_cmd_response_ready_cbk(void *const p_user_ctx)
{
    ESSA_Stack_TP_Layer_ReleaseThreadWait();

    (void)p_user_ctx;
}

static inline void dw_store_error_res(const fm_result_t error, const uint32_t src_line_no)
{
    dw_file_error_result.error       = error;
    dw_file_error_result.src_line_no = src_line_no;
}

static uint8_t dw_file_by_chunks_cbk(const uint64_t cmd_id,
                                     const uint32_t cmd_type,
                                     const uint32_t required_chunk_size,
                                     const uint32_t offset,
                                     uint8_t       *p_chunk)
{
    uint8_t     res = EESTL_SFERR_UNKNOWN;
    fm_handle_t h_file;

    (void)cmd_id;
    (void)cmd_type;

    fm_result_t fres = fm_open_internal(&h_file, dw_file_by_chunks_in_args.file_path,
                                        FM_MODE_OPEN_EXISTING | FM_MODE_READ);

    if (fres == FM_RES_OK)
    {
        uint32_t bytes_read = 0U;

        fres = fm_read_at_pos(h_file, p_chunk, required_chunk_size, &bytes_read, dw_file_by_chunks_in_args.file_offset + offset);

        if ((fres == FM_RES_OK) && (bytes_read == required_chunk_size))
        {
            res = EESTL_SFERR_SUCCESS;
        }
        else
        {
            dw_store_error_res(fres, __LINE__);
        }

        (void)fm_close(h_file);
    }
    else
    {
        dw_store_error_res(fres, __LINE__);
    }

    return res;
}

static bool b_calc_file_crc(const uint32_t file_offset, uint8_t *const p_buff, const uint32_t buff_size)
{
    uint32_t    offset        = file_offset;
    uint32_t    bytes_read    = 0U;
    bool        b_first_block = true;
    bool        b_success     = true;
    fm_handle_t h_file;

    fm_result_t fres = fm_open_internal(&h_file, dw_file_by_chunks_in_args.file_path,
                                        FM_MODE_OPEN_EXISTING | FM_MODE_READ);

    if (fres == FM_RES_OK)
    {
        do
        {
            fres = fm_read_at_pos(h_file, p_buff, buff_size, &bytes_read, offset);

            if (fres == FM_RES_OK)
            {
                ESCP_ModDrv_CalcBlockCRC(p_buff, bytes_read, b_first_block);

                b_first_block = false;

                offset += bytes_read;
            }
            else
            {
                dw_store_error_res(fres, __LINE__);
                b_success = false;
                break;
            }
        } while (bytes_read > 0U);

        (void)fm_close(h_file);
    }
    else
    {
        dw_store_error_res(fres, __LINE__);
    }

    return b_success;
}
