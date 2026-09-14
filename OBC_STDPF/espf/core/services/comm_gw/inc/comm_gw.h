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
 * @file comm_gw.h
 * @brief COMM GW public interface declaration
 *
 * @}
 * @}
 */
#ifndef COMM_GW_H
#define COMM_GW_H

#include "comm_gw_cmn.h"
#include "comm_gw_if_cfg.h"

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

/** @brief Initialize the COMM GW functionality for operation
 *
 */
void comm_gw_init(void);

/** @brief Blocking send of a raw buffer to a local or remote node via the specified interface.
 *
 *  @param[in] gw_if_id COMM GW interface ID (type of communication needed)
 *  @param[in] gw_user_id COMM GW user ID
 *  @param[in/out] p_send_ctx send request parameters
 *
 *  @return operation status as a direct result and the actual received response (if any) as part of the @ref p_send_ctx
 *  structure
 */
comm_gw_comm_res_t comm_gw_send(const comm_gw_if_id_t gw_if_id, const uint8_t comm_gw_user_id, comm_gw_send_ctx_t *const p_send_ctx);

#endif /* COMM_GW_H */
