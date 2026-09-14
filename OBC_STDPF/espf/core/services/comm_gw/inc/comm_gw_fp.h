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
 * @defgroup fp_gw
 * @{
 *
 * @file comm_gw_fp.h
 * @brief FP GW PHY interface related types
 *
 * @}
 * @}
 */

#ifndef COMM_GW_FP_H
#define COMM_GW_FP_H

#include "es_cdef.h"
#include "comm_gw_cmn.h"
#include <stdint.h>
#include <stdbool.h>
#include "ESPLATFORM_NETWORK_STACK/ES_SAT_API/include/ESSA_Stack.h"

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/
/** @brief Communication parameters structure for the ESPS FP interface */
typedef struct
{
    uint8_t              mac_if_id;        /**< MAC interface ID */
    uint8_t              target_node_addr; /**< MAC address of the target node */
    ESSATMAC_MsgPriority msg_prio;         /**< message bus priority used for the transmission (only used for external bus transfers) */
} PACKED comm_gw_fp_comm_params_t;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/
/** @brief FP GW interface descriptor */
extern const comm_gw_if_t comm_gw_fp_if_instance;

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/
/** @brief Called by the FP stack to capture a reply frame (in case of local command execution) or called by
 *  the ESPS driver dispatch logic when a frame is received on the physical ESPS bus (in case of external node
 *  communication).
 *
 *  This is the main entry point to capture any response received to an FP request (could be locally generated or
 *  remotely by another node). After receiving the response and validating it, the function notifies its caller about
 *  the completion of the reception.
 *
 *  @param[in] p_mac_ctx contextual information about the received frame
 *  @param[in] p_msg_data pointer to the frame data bytes
 *  @param[in] msg_data_size size of the received frame
 *
 *  @return status of the operation
 */
ESSATMAC_ErrCodes comm_gw_fp_enq_message(const ESSATMAC_Context *p_mac_ctx, const uint8_t *p_msg_data, uint8_t msg_data_size);

/** @brief Check if a virtual node address is a valid address assigned to one of the COMM GW users.
 *
 *  @param[in] vnode_addr virtual node address to check
 *
 *  @retval true: the address is assigned to a COMM GW user and is valid to accept incoming frames
 *  @retval false: the address is not found on the COMM GW user list and incoming frames can be ignored
 */
bool comm_gw_fp_is_valid_vnode_addr(const uint8_t vnode_addr);

#endif /* COMM_GW_FP_H */
