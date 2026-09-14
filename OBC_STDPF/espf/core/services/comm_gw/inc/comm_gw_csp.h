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
 * @file comm_gw_csp.h
 * @brief COMM GW CSP PHY interface related types
 *
 * @}
 * @}
 */

#ifndef COMM_GW_CSP_H
#define COMM_GW_CSP_H

#include "es_cdef.h"
#include "comm_gw_cmn.h"

/** @brief Communication parameters for the CSP interface */
typedef struct
{
    uint8_t  target_node_addr; /**< address of the target node on the CSP bus */
    uint8_t  port;             /**< CSP target port to forward the data to */
    uint8_t  prio;             /**< CSP message priority */
    uint32_t opts;             /**< CSP connection-specific option flags */
} PACKED comm_gw_csp_comm_params_t;

/** @brief FP GW interface descriptor */
extern const comm_gw_if_t comm_gw_csp_if_instance;

#endif /* COMM_GW_CSP_H */
