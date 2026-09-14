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
 * @defgroup cp_gw
 * @{
 *
 * @file comm_gw_cp.h
 * @brief COMM GW ESPS CP commands extension
 *
 * @}
 * @}
 */

#ifndef COMM_GW_CP_H
#define COMM_GW_CP_H

#include "es_cdef.h"
#include "comm_gw_cmn.h"

/** @brief Communication parameters for the ESPS CP interface */
typedef struct
{
    uint32_t cmd_id; /**< ID of the CP command */
} PACKED comm_gw_cp_comm_params_t;

/** @brief FP GW interface descriptor */
extern const comm_gw_if_t comm_gw_cp_if_instance;

#endif /* COMM_GW_CP_H */
