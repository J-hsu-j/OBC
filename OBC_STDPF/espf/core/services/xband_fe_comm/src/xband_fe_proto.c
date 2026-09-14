/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup xband_fe_comm
 * @{
 *
 * @file xband_fe_proto.c
 * @brief Implementation of the X-Band Front End communication protocol (executed over CSP)
 *
 * This module basically formats the proper CSP data packets and parses the responses. The general
 * format of all XBand FE CSP commands is the following (Little Endian encoding for multi-byte values):
 *
 * - CSP request
 * ----------------------------------------------------
 * | 2-byte command ID  | command payload bytes ...   |
 * ----------------------------------------------------
 *
 * - CSP response
 * ----------------------------------------------------
 * | 2-byte response ID  | response payload bytes ... |
 * ----------------------------------------------------
 *
 * The 2-byte cmd ID is not part of the FIDL description and is handled internally by this module.
 * This allows scripts and any other users of the API to avoid dealing with internal CSP identifiers
 * in order to communicate to the module.
 * The `command payload bytes` field is entierly described in the FIDL.
 * Currently the CSP command ID (specified in the FIDL) in most cases is equal to (response ID - 1) but not for all commands
 * :-( Unfortunately there is no standard way to describe those exceptions in the FIDL, hence the
 * command response ID is defined in this implementation below (XBAND_FE_GENERIC_CMD_RESP_ID). Still other commands,
 * have the same response ID as the command. In general, there is no pattern so we have to account for this here in
 * the implementation to at least keep the end-users away from keeping track of this.
 *
 * If the XBand FE command description need to be modified, the following steps must be taken:
 *
 * - update the `espf/core/fidl/xband_fe/fp/xband_fe.fidl` file with the new changes
 *   (the FIDL is our primary source of truth and the command structure is defined solely in the FIDL
 *   and generated as typedefs by macchiato)
 * - declare the command-wrapper functions for new commands by using the xband_fe_proto.h::XBAND_FE_CMD_IN_OUT_DECL() macro
 * - define the command-wrapper function body for new commands by using the XBAND_FE_CMD_IN_OUT_DEF() macro in this file
 * - call the command-wrapper function from the respective generated FP_xband_feServerApp.c handler for it
 *
 * The macros mentioned above make a distinction between CSP types and in/out arg types. This is necessary
 * because the actual CSP command executed requires an additional header which the xband_fe_proto
 * implementation manages.
 *
 * @}
 *
 */

#include "xband_fe_proto.h"
#include "comm_gw.h"
#include "nvm.h"
#include "assertions.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
/** @brief Maximum timeout in milliseconds to wait for the XBand FE response on any command */
#define MAX_RESP_TIMEOUT_MS (15000)

/** @brief XBand FE Generic command response ID used by most `set` commands
 * (not part of the FIDL because there is no standard way to describe it there and have it generated)
 * */
#define XBAND_FE_GENERIC_CMD_RESP_ID ((funcIdType_t)0x000000B1)

/** @brief Macro to define a static function which sends a typed XBand FE command and gets the response back
 *
 *  @param[in] cmd_name Name of the command for which to create the function
 *  @param[in] cmd_req_id Command request ID (as defined by XBand CSP protocol)
 *  @param[in] cmd_resp_id Command response ID (as defined by XBand CSP protocol)
 *  @param[in] csp_req_type CSP request type (including command header)
 *  @param[in] in_args_type C type name to use for the request
 *  @param[in] csp_resp_type CSP response type (including command header)
 *  @param[in] csp_data_fld_name name of the data subfield which corresponds to the XBand FE response (not accounting for additional comm_gw status)
 *  @param[in] out_args_type C type name to use for the response
 */
#define XBAND_FE_CMD_IN_OUT_DEF(cmd_name, cmd_req_id, cmd_resp_id, csp_req_type, in_args_type, csp_resp_type, csp_data_fld_name, out_args_type) \
    comm_gw_comm_res_t(cmd_name)(const in_args_type *const p_in_args, out_args_type *const p_resp)                                              \
    {                                                                                                                                           \
        csp_req_type  csp_data_req;                                                                                                             \
        csp_resp_type csp_data_resp;                                                                                                            \
        uint32_t      actual_resp_sz = 0U;                                                                                                      \
        csp_data_req.hdr.cmd_id      = (cmd_req_id);                                                                                            \
        if (NULL != p_in_args)                                                                                                                  \
        {                                                                                                                                       \
            csp_data_req.data = *p_in_args;                                                                                                     \
        }                                                                                                                                       \
        (void)memset((void *)&csp_data_resp.data.csp_data_fld_name, 0U, sizeof(csp_data_resp.data.csp_data_fld_name));                          \
        comm_gw_comm_res_t req_res = xband_fe_proto_send_cmd((uint8_t *)&csp_data_req,                                                          \
                                                             (NULL != p_in_args) ? sizeof(csp_data_req) : sizeof(csp_data_req.hdr),             \
                                                             MAX_RESP_TIMEOUT_MS,                                                               \
                                                             (uint8_t *)&csp_data_resp,                                                         \
                                                             sizeof(csp_data_resp),                                                             \
                                                             &actual_resp_sz);                                                                  \
        if (NULL == p_resp)                                                                                                                     \
        {                                                                                                                                       \
            return COMM_GW_RES_INVALID_ARGS;                                                                                                    \
        }                                                                                                                                       \
        if (COMM_GW_RES_OK == req_res)                                                                                                          \
        {                                                                                                                                       \
            BREAK_ASSERT(sizeof(csp_data_resp.data.csp_data_fld_name) == sizeof(out_args_type));                                                \
            (void)memcpy(p_resp, (void *)&csp_data_resp.data.csp_data_fld_name, sizeof(csp_data_resp.data.csp_data_fld_name));                  \
            return (csp_data_resp.hdr.cmd_id == (cmd_resp_id)) ? COMM_GW_RES_OK : COMM_GW_RES_ERR;                                              \
        }                                                                                                                                       \
        return req_res;                                                                                                                         \
    }

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

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

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
/** @brief This is a generic send wrapper function which forwards a raw command to the XBand FE module and
 *         provides the response back.
 *
 *  The function relies on comm_gw to do the actual transfer. It only sets up the CSP connection parameters.
 *
 *  @param[in] p_cmd buffer for the command bytes
 *  @param[in] size number of bytes in the command
 *  @param[in] timeout milliseconds to wait for the command response
 *  @param[out] p_resp_buf buffer where the response shall be written
 *  @param[in] resp_buf_sz maximum size of the response buffer
 *  @param[out] p_resp_sz a buffer to keep the size of the received response
 *
 *  @return comm_gw status of the operation
 */
static comm_gw_comm_res_t xband_fe_proto_send_cmd(const uint8_t *const p_cmd,
                                                  uint16_t             sz,
                                                  uint32_t             timeout,
                                                  uint8_t *const       p_resp_buf,
                                                  const uint16_t       resp_buf_sz,
                                                  uint32_t *const      p_resp_sz);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
XBAND_FE_CMD_IN_OUT_DEF(xband_fe_proto_get_status_report,
                        XBAND_FE_GET_STATUS_REPORT_FUNC_ID,
                        XBAND_FE_GET_STATUS_REPORT_FUNC_ID,
                        xband_fe_csp_std_req_t,
                        no_args_t,
                        xband_fe_csp_get_status_report_resp_t,
                        sStatus_report,
                        XBAND_FE_ModStatusReportParamsWrapper_t)

XBAND_FE_CMD_IN_OUT_DEF(xband_fe_proto_exec_sys_mngr_run,
                        XBAND_FE_SET_SYS_MNGR_RUN_MODE_FUNC_ID,
                        XBAND_FE_GENERIC_CMD_RESP_ID,
                        xband_fe_csp_std_req_t,
                        no_args_t,
                        xband_fe_csp_sys_mgr_run_resp_t,
                        eStd_resp,
                        XBAND_FE_StdResponseWrapper_t)

XBAND_FE_CMD_IN_OUT_DEF(xband_fe_proto_exec_sys_mngr_stand_by,
                        XBAND_FE_SET_SYS_MNGR_STANDBY_MODE_FUNC_ID,
                        XBAND_FE_GENERIC_CMD_RESP_ID,
                        xband_fe_csp_std_req_t,
                        no_args_t,
                        xband_fe_csp_sys_mgr_standby_resp_t,
                        eStd_resp,
                        XBAND_FE_StdResponseWrapper_t)

XBAND_FE_CMD_IN_OUT_DEF(xband_fe_proto_set_mod_all_params,
                        XBAND_FE_SET_MOD_ALL_PARAMS_FUNC_ID,
                        XBAND_FE_GENERIC_CMD_RESP_ID,
                        xband_fe_csp_set_mode_all_params_req_t,
                        xband_feset_mod_all_paramsRequestData_t,
                        xband_fe_csp_set_mode_all_params_resp_t,
                        eStd_resp,
                        XBAND_FE_StdResponseWrapper_t)

XBAND_FE_CMD_IN_OUT_DEF(xband_fe_proto_get_mod_all_params,
                        XBAND_FE_GET_MOD_ALL_PARAMS_FUNC_ID,
                        XBAND_FE_GET_MOD_ALL_PARAMS_FUNC_ID + 1,
                        xband_fe_csp_std_req_t,
                        no_args_t,
                        xband_fe_csp_get_mode_all_params_resp_t,
                        sMod_params,
                        XBAND_FE_ModCfgParamsWrapper_t)

XBAND_FE_CMD_IN_OUT_DEF(xband_fe_proto_set_tx_power,
                        XBAND_FE_SET_TX_POWER_FUNC_ID,
                        XBAND_FE_GENERIC_CMD_RESP_ID,
                        xband_fe_csp_set_tx_pwr_req_t,
                        xband_feset_tx_powerRequestData_t,
                        xband_fe_csp_set_tx_pwr_resp_t,
                        eStd_resp,
                        XBAND_FE_StdResponseWrapper_t)

XBAND_FE_CMD_IN_OUT_DEF(xband_fe_proto_get_tx_power,
                        XBAND_FE_GET_TX_POWER_FUNC_ID,
                        XBAND_FE_GET_TX_POWER_FUNC_ID + 1,
                        xband_fe_csp_std_req_t,
                        no_args_t,
                        xband_fe_csp_get_tx_pwr_resp_t,
                        sPwr_info,
                        XBAND_FE_XBandFeTxPowerInfoWrapper_t)

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
static comm_gw_comm_res_t xband_fe_proto_send_cmd(const uint8_t *const p_cmd,
                                                  uint16_t sz, uint32_t timeout,
                                                  uint8_t *const  p_resp_buf,
                                                  const uint16_t  resp_buf_sz,
                                                  uint32_t *const p_resp_sz)
{
    comm_gw_send_ctx_t        send_params;
    comm_gw_csp_comm_params_t csp_comm_params;
    xband_fe_config_t         xband_fe_cfg;

    BREAK_ASSERT(NULL != p_cmd);
    BREAK_ASSERT(NULL != p_cmd);
    BREAK_ASSERT(NULL != p_resp_buf);
    BREAK_ASSERT(resp_buf_sz > 0);
    BREAK_ASSERT(NULL != p_resp_sz);

    Nvm_GetBlockById(NVM_BLOCK_XBAND_FE_CFG, &xband_fe_cfg);

    send_params.p_req_data         = p_cmd;
    send_params.req_data_size      = (uint32_t)sz;
    send_params.p_resp_data        = p_resp_buf;
    send_params.resp_data_max_size = (uint32_t)resp_buf_sz;
    send_params.p_resp_data_size   = p_resp_sz;
    send_params.resp_timeout       = timeout;

    csp_comm_params.target_node_addr = xband_fe_cfg.target_node_addr;
    csp_comm_params.port             = xband_fe_cfg.port;
    csp_comm_params.prio             = xband_fe_cfg.prio;
    csp_comm_params.opts             = xband_fe_cfg.opts;

    // using a local stack pointer here is safe because the comm_gw_send() function is blocking and will not return control
    // until it finishes
    send_params.p_comm_params = &csp_comm_params;

    return comm_gw_send(COMM_GW_IF_ID_CSP, COMM_GW_USER_ID_XBAND_FE, &send_params);
}
