/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef CSP_SERVICE_CFG_H_
#define CSP_SERVICE_CFG_H_

/**
 * @addtogroup csp_service
 * @{
 *
 * @file csp_service_cfg.h
 * @brief `csp_service` configuration macros
 *
 * @}
 */

#define CSP_SERVICE_CFG_NUM_BUFFERS (20U)
#define CSP_SERVICE_CFG_BUFFER_SZ   (300U)
#define CSP_SERVICE_CFG_OWN_ADDRESS (1U)

/** @brief Trace buffer size in bytes reserved for CSP-related traces */
#define CSP_SERVICE_TRACE_BUF_SZ (150U)

//
//  Configuration of the CSP default trace levels
//
#define CSP_ERROR_TRC_LVL    (true)
#define CSP_WARN_TRC_LVL     (true)
#define CSP_INFO_TRC_LVL     (false)
#define CSP_BUFFER_TRC_LVL   (false)
#define CSP_PROTOCOL_TRC_LVL (false)
#define CSP_PACKET_TRC_LVL   (false)
#define CSP_LOCK_TRC_LVL     (false)

#endif /* CSP_SERVICE_CFG_H_ */
