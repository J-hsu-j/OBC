/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup Services
 * @{
 *
 * @defgroup comm_gw
 * @{
 *
 * @file comm_gw_cp.c
 * @brief ESPS CP Communication Gateway Implementation
 *
 * This is a COMM GW extension which provides execution of locally implemented CP commands (a.k.a. CP injection).
 * Remote CP commands are not currently supported by the ESPS stack.
 *
 * @}
 * @}
 */

#include "comm_gw_if_cfg.h"
#include "comm_gw_cmn.h"
#include "comm_gw_cp.h"
#include "cmsis_os2.h"
#include "esps_drv_config.h"
#include <string.h>
#include "assertions.h"
#include "trace.h"
#include "CP_Handler.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/** @brief Initialize the COMM GW CP interface */
static void comm_gw_cp_init(void);

/** @brief Send a CP frame with the specified communication parameters
 *
 *  @param[in] user_id ID of the user requesting the operation
 *  @param[in/out] p_send_ctx a reference to the communication and buffer parameters for the send operations
 *  @param[in] p_comm_finished_cb function pointer to use as notification mechanism when the send operations and corresponding response are received
 */
static void comm_gw_cp_send(const uint8_t user_id, comm_gw_send_ctx_t *const p_send_ctx, const comm_gw_comm_finished_func_t p_comm_finished_cb);

/** @brief Checks the provided comm_gw context for validity taking into account specific CP command restrictions
 *
 *  Used also to ensure that it will not be possible to call the comm_gw recursively from specific context, e.g. by making a comm_gw call
 *  from the comm_gw CP FIDL to execute an FP command (again through the comm_gw).
 *
 *  @param[in] user_id comm_gw user ID
 *  @param[in] cmd_id CP command ID
 *
 *  @retval true: the command can be executed
 *  @retval false: the command shall not be executed
 */
static bool comm_gw_is_valid_ctx(const uint8_t user_id, const uint32_t cmd_id);

/** @brief Returns the CP command handler function based on the specified identifier
 *
 *  @param[in] cmd_id Unique identifier of the CP command
 *
 *  @return pointer to the CP command handler or NULL if the given ID is not supported
 *
 *  @note This is a special macro-compiled static function whose body is defined by the entries given in
 *  @ref ESCP_CommandsLocalConf.h. It is done this way to effectively avoid searching the list of the IDs.
 */
#define ESTL_CP_HANDLER_BEGIN_COMMAND_MAP()                             \
    static pfCPCmdHandler comm_gw_cp_get_cmd_hnd(const uint32_t cmd_id) \
    {                                                                   \
        switch (cmd_id)                                                 \
        {

#define ESTL_CP_HANDLER_REGISTER_COMMAND(cmd_id, hnd_func) \
    case cmd_id:                                           \
        return &(hnd_func);

#define ESTL_CP_HANDLER_END_COMMAND_MAP() \
    }                                     \
    return (pfCPCmdHandler)NULL;          \
    }

// include list of CP command handlers as configured in the system
#define __CP_HANDLER_C__
#include "ESCP_CommandsLocalConf.h"

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
static const char *comm_gw_cp_err_dbg_str[ECPDISPATCHRESULT_MAX] = {
    [ECPDISPATCHRESULT_SIMPLERESULT_OK]  = "SIMPLERESULT_OK",
    [ECPDISPATCHRESULT_RESULT_OK]        = "RESULT_OK",
    [ECPDISPATCHRESULT_RESULT_POSTPONED] = "RESULT_POSTPONED",
    [ECPDISPATCHRESULT_RESULT_BY_CHUNKS] = "RESULT_BY_CHUNKS",
    [ECPDISPATCHRESULT_ERROR]            = "ERROR",
};

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/
/** @brief COMM GW interface instance definition */
const comm_gw_if_t comm_gw_cp_if_instance = {
    .p_comm_gw_if_init = &comm_gw_cp_init,
    .p_comm_gw_if_send = &comm_gw_cp_send
};

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
static void comm_gw_cp_init(void)
{
    // This function doesn't do anything useful right now but is part of the standard comm_gw_if interface
    // and must be preserved.
    return;
}

static bool comm_gw_is_valid_ctx(const uint8_t user_id, const uint32_t cmd_id)
{
    // Note: The following use cases will not be serviced by the CP comm_gw extension:
    // 1) calls to comm_gw from within a CP command handler (which doesn't make any sense - direct bindings shall be used instead)
    // 2) calls from uPy context to execute comm_gw commands through the CP comm_gw extension (direct uPy bindings for
    //    the respective command type shall be used instead to avoid recursion)
    // 3) calls to the CP FP gateway (direct comm_gw FP bindings shall be used instead)
    // 4) calls to the CP_CMD_DBG_DOWNLOADFILE CP command which uses chunk-based transfers (not supported by comm_gw)
    return ((COMM_GW_USER_ID_CP_HANDLER == user_id) ||
            ((COMM_GW_USER_ID_UPY == user_id) &&
             ((CP_CMD_COMM_GW_FP_SEND == cmd_id) ||
              (CP_CMD_COMM_GW_CSP_SEND == cmd_id) ||
              (CP_CMD_MACFP_GWSEND == cmd_id) ||
              (CP_CMD_DBG_DOWNLOADFILE == cmd_id))));
}

static void comm_gw_cp_send(const uint8_t user_id, comm_gw_send_ctx_t *const p_send_ctx, const comm_gw_comm_finished_func_t p_comm_finished_cb)
{
    BREAK_ASSERT((NULL != p_send_ctx) &&
                 (NULL != p_send_ctx->p_req_data) &&
                 (0 < p_send_ctx->req_data_size) &&
                 (NULL != p_send_ctx->p_resp_data_size));

    const comm_gw_cp_comm_params_t *p_comm_params = (const comm_gw_cp_comm_params_t *)p_send_ctx->p_comm_params;
    comm_gw_comm_res_t              cp_comm_res   = COMM_GW_RES_MAX;

    if (comm_gw_is_valid_ctx(user_id, p_comm_params->cmd_id))
    {
        ES_TRACE_WARN("[id:%ld | user:%d] comm_gw used from inappropriate context - send operation ignored",
                      p_comm_params->cmd_id,
                      user_id);

        if (NULL != p_comm_finished_cb)
        {
            (*p_comm_finished_cb)(user_id, COMM_GW_RES_ERR);
        }

        return;
    }

    pfCPCmdHandler p_cp_cmd_hnd = comm_gw_cp_get_cmd_hnd(p_comm_params->cmd_id);

    if (NULL != p_cp_cmd_hnd)
    {
        sCPDispatchContext_t cp_disp_ctx;

        // prepare the local CP command context
        cp_disp_ctx.pChunkRequestCbk      = NULL;
        cp_disp_ctx.u32CmdType            = p_comm_params->cmd_id; // as confusing as it may be, u32CmdType is actually the cmd_id (legacy naming)
        cp_disp_ctx.pu8CmdData            = p_send_ctx->p_req_data;
        cp_disp_ctx.u32CmdDataSize        = p_send_ctx->req_data_size;
        cp_disp_ctx.pu8ResponseBuf        = p_send_ctx->p_resp_data;
        cp_disp_ctx.u32ResponseActualSize = 0UL;
        cp_disp_ctx.u32ResponseBufSize    = p_send_ctx->resp_data_max_size;
        cp_disp_ctx.u8TLError             = EESTL_SFERR_UNKNOWN;
        *(p_send_ctx->p_resp_data_size)   = 0UL;
        cp_disp_ctx.u32UserTimeout        = p_send_ctx->resp_timeout;

        ES_TRACE_DEBUG("[id:%ld] injecting CP frame (%ld byte(s) / tout: %ld ms)", p_comm_params->cmd_id, p_send_ctx->req_data_size, p_send_ctx->resp_timeout);

        // execute the configured CP handler
        eCPDispatchResult_t disp_res = (*p_cp_cmd_hnd)(&cp_disp_ctx);

        if (((ECPDISPATCHRESULT_SIMPLERESULT_OK == disp_res) ||
             (ECPDISPATCHRESULT_RESULT_OK == disp_res)) &&
            (EESTL_SFERR_SUCCESS == cp_disp_ctx.u8TLError))
        {
            // full message size always returned (regardless of partial copy or not)
            *(p_send_ctx->p_resp_data_size) = cp_disp_ctx.u32ResponseActualSize;

            cp_comm_res = COMM_GW_RES_OK;
        }
        else
        {
            ES_TRACE_ERROR("[id:%ld] CP command failed with error '%s' | TL err: '%d'",
                           p_comm_params->cmd_id,
                           comm_gw_cp_err_dbg_str[(uint8_t)(disp_res < ECPDISPATCHRESULT_MAX ? disp_res : ECPDISPATCHRESULT_ERROR)],
                           cp_disp_ctx.u8TLError);

            cp_comm_res = COMM_GW_RES_ERR;
        }
    }
    else
    {
        ES_TRACE_WARN("[id:%ld] provided CP command ID not supported", p_comm_params->cmd_id);

        cp_comm_res = COMM_GW_RES_INVALID_ARGS;
    }

    if (NULL != p_comm_finished_cb)
    {
        (*p_comm_finished_cb)(user_id, cp_comm_res);
    }
}
