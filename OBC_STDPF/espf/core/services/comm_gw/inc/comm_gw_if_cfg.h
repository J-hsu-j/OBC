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
 * @file comm_gw_if_cfg.h
 * @brief COMM GW configuration file
 *
 * @}
 * @}
 */

#ifndef COMM_GW_CFG_H
#define COMM_GW_CFG_H

#include "comm_gw_cmn.h"

#if defined(COMM_RS485_MAC_LAYER_ENABLED)
#include "comm_gw_fp.h"
#include "comm_gw_cp.h"
#endif // #if defined(COMM_RS485_MAC_LAYER_ENABLED)

#if defined(CSP_SUPPORT_ENABLED)
#include "comm_gw_csp.h"
#endif // #if defined(CSP_SUPPORT_ENABLED)

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
/** @brief Size of the biggest comm_gw_*_comm_params_t structure
 *
 *  Can be used by comm_gw users to statically allocate space for the communication parameters
 *  structure without taking into account the specific structure type used internally.
 */
#define COMM_GW_COMM_PARAMS_MAX_SIZE (sizeof(comm_gw_comm_params_max_t))

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/
/** @brief This type serves to account for the maximum size needed for any comm_gw-supported
 *  comm_gw_*_comm_params_t extensions.
 */
typedef union
{
#if defined(COMM_RS485_MAC_LAYER_ENABLED)
    comm_gw_fp_comm_params_t fp_comm_params;
    comm_gw_cp_comm_params_t cp_comm_params;
#endif // #if defined(COMM_RS485_MAC_LAYER_ENABLED)
#if defined(CSP_SUPPORT_ENABLED)
    comm_gw_csp_comm_params_t csp_comm_params;
#endif // #if defined(CSP_SUPPORT_ENABLED)
} comm_gw_comm_params_max_t;

/** @brief Describes the available comm gateway interfaces */
typedef enum
{
    COMM_GW_IF_ID_FP, /**< FP communication over ESPS RS485 bus */
    COMM_GW_IF_ID_CP, /**< Local CP command execution */
    COMM_GW_IF_ID_CSP, /**< CSP communication (phy bus type depends on CSP routing table configuration and could vary) */
    COMM_GW_IF_ID_MAX /**< used for validity checking only */
} comm_gw_if_id_t;

#define COMM_GW_RESPONSE_TIMEOUT_MS  ((uint32_t)4000UL)  /**< maximum time to wait for a response from the remote side */
#define COMM_GW_USER_LOCK_TIMEOUT_MS ((uint32_t)30000UL) /**< maximum time to wait for the user lock to be released before attempting to send another command */

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
#if defined(COMM_RS485_MAC_LAYER_ENABLED)
/** @brief This is the base address from which FP GW user requests will be offset and sent to the ESPS bus.
 *  The point here is to be able to easily route back any responses based on this address instead of
 *  keeping a dedicated queue of requests. If the OBC node address is used here, then we need a
 *  way to distinguish responses to commands sent by modules relying on the FP-generated bindings and those sent directly
 *  by the @ref comm_gw module.
 *  Now we just rely on the ESPS stack queues and care only for the response node address to match
 *  our virtual node address. In such cases, the reply is directly routed to the @ref comm_gw_fp module. Any
 *  other response will be processed by its original sender.
 * */
#define COMM_GW_VIRTUAL_NODE_ADDRESS_BASE ((uint8_t)0xF5)

/** @brief This is the net type for the ESSA stack which will be used to forward requests to other ESPS bus nodes.
 *  This net type is special because it forces the ESPS driver to use the source address of the node as given in the
 *  @ref ESSATMAC_Context argument. With any other net type, the driver will automatically assign the configured OBC
 *  node address but we would like to use @ref COMM_GW_VIRTUAL_NODE_ADDRESS_BASE instead.
 */
#define COMM_GW_EXT_REQ_NETTYPE (ESSASNETT_UART_BRIDGE)

/** @brief COMM GW external requests get responded on the internal ESPS bus net type and not on the net type
 * used for initiating the request.
 */
#define COMM_GW_EXT_RESP_NETTYPE (ESSASNETT_INTERNAL)

/** @brief This is a net type which enables loopback FP command execution using a predefined fp_gw driver function */
#define COMM_GW_LOOPBACK_REQ_NETTYPE (ESSASNETT_COMM_GW_LOOPBACK)
#endif // #if defined(COMM_RS485_MAC_LAYER_ENABLED)

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/
/** @brief Provides a reference to a communication interface given its identifier
 *
 *  @param[in] if_id communication interface ID for which to obtain a reference
 *
 *  @return reference to a communication interface
 */
const comm_gw_if_t *comm_gw_cfg_get_intf_ref(const comm_gw_if_id_t if_id);

/** @brief Provide the string representation of a COMM GW user identifier.
 *
 *  @param[in] user_id ID of the COMM GW user
 *
 *  @return a pointer to a ROM string describing the user ID given
 */
const char *comm_gw_cfg_get_user_str(const comm_gw_user_id_t user_id);

/** @brief Provide the string representation of a COMM GW interface identifier.
 *
 *  @param[in] gw_id ID of the COMM GW interface
 *
 *  @return a pointer to a ROM string describing the GW interface ID given
 */
const char *comm_gw_cfg_get_gw_str(const comm_gw_if_id_t gw_id);

/** @brief Provide the string representation of a COMM GW error identifier.
 *
 *  @param[in] err_id ID of the COMM GW error
 *
 *  @return a pointer to a ROM string describing the error ID given
 */
const char *comm_gw_cfg_get_err_str(const comm_gw_comm_res_t err_id);

#endif /* COMM_GW_CFG_H */
