#ifndef FP_CSP_BINDER_CFG_H
#define FP_CSP_BINDER_CFG_H

#include "cmsis_os2.h"
#include "csp_service_cfg.h"

/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/** @brief Max number of bytes reserved for CSP FP response datagrams */
#define FS_MAX_CSP_BUF_SZ_BYTES (CSP_SERVICE_CFG_BUFFER_SZ)

/** @brief Server port for UDP FP communication */
#define CSP_FP_UDP_SERVER_PORT (12)

/** @brief Server port for RDP FP communication (used for ground station exchanges) */
#define CSP_FP_RDP_SERVER_PORT (13)

/** @brief Max number of UDP connections allocated for FP communication */
#define CSP_FP_UDP_BACKLOG_CNT (5)

/** @brief Max number of RDP connections allocated for FP communication */
#define CSP_FP_RDP_BACKLOG_CNT (2)

/** @brief Number of stack bytes reserved for each server thread */
#define SERVER_THREAD_STACK_SZ (500)

/** @brief OS priority level used for each server thread */
#define SERVER_THREAD_PRIO (osPriorityNormal)

#endif /* FP_CSP_BINDER_CFG_H */
