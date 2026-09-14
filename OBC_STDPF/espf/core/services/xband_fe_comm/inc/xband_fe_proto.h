/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef XBAND_FE_PROTO_H
#define XBAND_FE_PROTO_H

/**
 * @defgroup xband_fe_comm Template Group
 * @{
 *
 * This file contains the public interface for sending and receiving the X-Band Front End protocol
 * commands.
 *
 * @file xband_fe_proto.h
 * @brief xband_fe_comm public interface
 *
 * @}
 */

#include <es_cdef.h>
#include "FP_xband_feProtocolTypes.h"
#include "comm_gw.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
/** @brief Macro to declare an XBand FE command function
 *
 *  The function is defined using the XBAND_FE_CMD_IN_OUT_DEF() macro
 *
 *  @param[in] cmd_name Function name of the respective command handler
 *  @param[in] in_args_type C type name of the CSP data request field
 *  @param[in] out_args_type C type name of the CSP data response field
 * */
#define XBAND_FE_CMD_IN_OUT_DECL(cmd_name, in_args_type, out_args_type) \
    comm_gw_comm_res_t(cmd_name)(const in_args_type *const p_in_args, out_args_type *const p_resp)

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/** @brief XBand FE command header
 *
 *  Each CSP command supported by the XBand FE module requires this header before passing the
 *  command arguments. The header is used by the XBand FE module to determine the actual command
 *  being addressed.
 */
typedef struct
{
    uint16_t cmd_id; /**< identifier of the CSP command */
} PACKED xband_fe_csp_hdr_t;

/** @brief Dummy type used when there are no input arguments to a command */
typedef uint8_t no_args_t;

/** @brief CSP standard request type - contains only a command header */
typedef struct
{
    xband_fe_csp_hdr_t hdr;  /**< CSP command header */
    no_args_t          data; /**< dummy data byte to avoid compilation issues with common macro code */
} PACKED xband_fe_csp_std_req_t;

/** @brief CSP response of the Get Module Status Report command */
typedef struct
{
    xband_fe_csp_hdr_t                      hdr;  /**< CSP command header */
    XBAND_FE_ModStatusReportParamsWrapper_t data; /**< command data */
} xband_fe_csp_get_status_report_resp_t;

/** @brief CSP response for the Sys Manager Run command */
typedef struct
{
    xband_fe_csp_hdr_t            hdr;  /**< CSP command header */
    XBAND_FE_StdResponseWrapper_t data; /**< command data */
} xband_fe_csp_sys_mgr_run_resp_t;

/** @brief CSP response for the Sys Manager Stand-By command */
typedef struct
{
    xband_fe_csp_hdr_t            hdr;  /**< CSP command header */
    XBAND_FE_StdResponseWrapper_t data; /**< command data */
} xband_fe_csp_sys_mgr_standby_resp_t;

/** @brief CSP request for the Set Mode All Params command */
typedef struct
{
    xband_fe_csp_hdr_t                      hdr;  /**< CSP command header */
    xband_feset_mod_all_paramsRequestData_t data; /**< command data */
} xband_fe_csp_set_mode_all_params_req_t;

/** @brief CSP response for the Set Mode All Params command */
typedef struct
{
    xband_fe_csp_hdr_t            hdr;  /**< CSP command header */
    XBAND_FE_StdResponseWrapper_t data; /**< response data */
} xband_fe_csp_set_mode_all_params_resp_t;

/** @brief CSP respnse for the Get Mode All Params command */
typedef struct
{
    xband_fe_csp_hdr_t             hdr;  /**< CSP command header */
    XBAND_FE_ModCfgParamsWrapper_t data; /**< command data */
} xband_fe_csp_get_mode_all_params_resp_t;

/** @brief CSP request for the Set Tx Power command */
typedef struct
{
    xband_fe_csp_hdr_t                hdr;  /**< CSP command header */
    xband_feset_tx_powerRequestData_t data; /**< command data */
} xband_fe_csp_set_tx_pwr_req_t;

/** @brief CSP response for the Set Tx Power command */
typedef struct
{
    xband_fe_csp_hdr_t            hdr;  /**< CSP command header */
    XBAND_FE_StdResponseWrapper_t data; /**< response data */
} xband_fe_csp_set_tx_pwr_resp_t;

/** @brief CSP response for the Get Tx Power command */
typedef struct
{
    xband_fe_csp_hdr_t                   hdr;  /**< CSP command header */
    XBAND_FE_XBandFeTxPowerInfoWrapper_t data; /**< command data */
} xband_fe_csp_get_tx_pwr_resp_t;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/
/* No External variables declarations */

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

/**
 * @brief Retrieve status information from the XBand FE module
 *
 */
XBAND_FE_CMD_IN_OUT_DECL(xband_fe_proto_get_status_report,
                         no_args_t,
                         XBAND_FE_ModStatusReportParamsWrapper_t);

/**
 * @brief Send a command to switch the XBand FE to Run mode
 *
 */
XBAND_FE_CMD_IN_OUT_DECL(xband_fe_proto_exec_sys_mngr_run,
                         no_args_t,
                         XBAND_FE_StdResponseWrapper_t);

/**
 * @brief Send a command to switch the XBand FE to Stand-by mode
 *
 */
XBAND_FE_CMD_IN_OUT_DECL(xband_fe_proto_exec_sys_mngr_stand_by,
                         no_args_t,
                         XBAND_FE_StdResponseWrapper_t);

/**
 * @brief Send a command to change XBand FE module operational parameters
 *
 */
XBAND_FE_CMD_IN_OUT_DECL(xband_fe_proto_set_mod_all_params,
                         xband_feset_mod_all_paramsRequestData_t,
                         XBAND_FE_StdResponseWrapper_t);

/**
 * @brief Send a command to query the XBand FE module operational parameters
 *
 */
XBAND_FE_CMD_IN_OUT_DECL(xband_fe_proto_get_mod_all_params,
                         no_args_t,
                         XBAND_FE_ModCfgParamsWrapper_t);

/**
 * @brief Send a command to set the XBand FE module Tx power level
 *
 */
XBAND_FE_CMD_IN_OUT_DECL(xband_fe_proto_set_tx_power,
                         xband_feset_tx_powerRequestData_t,
                         XBAND_FE_StdResponseWrapper_t);

/**
 * @brief Send a command to query the XBand FE module Tx power level
 *
 */
XBAND_FE_CMD_IN_OUT_DECL(xband_fe_proto_get_tx_power,
                         no_args_t,
                         XBAND_FE_XBandFeTxPowerInfoWrapper_t);

#ifdef __cplusplus
}
#endif

#endif /* XBAND_FE_PROTO_H */
