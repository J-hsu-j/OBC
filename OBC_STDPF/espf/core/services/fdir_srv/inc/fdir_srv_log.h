/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup fdir_srv
 * @{
 *
 * @file     fdir_srv_log.h
 * @brief    FDIR logging header
 *
 * @}
 */

#ifndef FDIR_LOG_H
#define FDIR_LOG_H

#include "fdir_srv_cfg.h"

/**
 * @brief Log a message to the FDIR log
 * @param fault_id The fault ID. See @ref fdir_fault_id_t
 * @param agent_id The agent ID. See @ref fdir_agent_id_t
 * @param fmt The format string. Same as sprintf capabilities
 * @param ... The arguments to be formatted. Resulting string should not exceed 221 bytes, otherwise it will be truncated with "..." at the end
 *
 */
void fdir_srv_log(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent_id, const char * fmt, ...);

/**
 * @brief Same as @ref fdir_srv_log, but only logs if the cond is not equal to fault status.
 *
 * @param fault_id The fault ID. See @ref fdir_fault_id_t
 * @param agent_id The agent ID. See @ref fdir_agent_id_t
 * @param cond The condition to be checked against the fault status. Must be different to or the log will be ignored.
 * @param fmt The format string. Same as sprintf capabilities
 * @param ... The arguments to be formatted. Resulting string should not exceed 221 bytes, otherwise it will be truncated with "..." at the end
 *
 */
void fdir_srv_log_if_not_same(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent_id, bool cond, const char * fmt, ...);

/**
 * @brief Same as @ref fdir_srv_log, but only logs if the fault is inactive (cleared).
 *
 * @param fault_id The fault ID. See @ref fdir_fault_id_t
 * @param agent_id The agent ID. See @ref fdir_agent_id_t
 * @param cond The condition to be checked against the fault status. Must be different to or the log will be ignored.
 * @param fmt The format string. Same as sprintf capabilities
 * @param ... The arguments to be formatted. Resulting string should not exceed 221 bytes, otherwise it will be truncated with "..." at the end
 *
 */
void fdir_srv_log_if_clear(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent_id, const char * fmt, ...);

/**
 * @brief Same as @ref fdir_srv_log, but only logs if the fault is active (raised).
 *
 * @param fault_id The fault ID. See @ref fdir_fault_id_t
 * @param agent_id The agent ID. See @ref fdir_agent_id_t
 * @param cond The condition to be checked against the fault status. Must be different to or the log will be ignored.
 * @param fmt The format string. Same as sprintf capabilities
 * @param ... The arguments to be formatted. Resulting string should not exceed 221 bytes, otherwise it will be truncated with "..." at the end
 *
 */
void fdir_srv_log_if_raised(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent_id, const char * fmt, ...);


#endif // FDIR_LOG_H