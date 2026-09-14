/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef ESPF_CONFIG_LWIP_LWIP_TRACER_H_
#define ESPF_CONFIG_LWIP_LWIP_TRACER_H_

/**
 * @addtogroup lwip
 * @{
 *
 * @brief Lightweight IP stack
 *
 * @defgroup lwip_tracer LWIP Tracer
 * @{
 *
 * @brief LWIP trace wrapper
 *
 * The LWIP Tracer is a wrapper, connecting the tracing mechanism and
 * the LWIP external library. All calls for tracing are forwarded trough
 * this module
 *
 * @file lwip_tracer.h
 *
 * LWIP trace wrapper public interface
 *
 * @}
 * @}
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Trace buffer size in bytes reserved for LWIP-related traces */
#define LWIP_SERVICE_TRACE_BUF_SZ (150U)

/** @brief lwIP tracer wrapper for the OBC
 *
 *  @param[in] format printf-like format string
 *  @param[in] args variable list of arguments for the specified format string
 */
void lwip_es_trace_fatal(const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif /* ESPF_CONFIG_LWIP_LWIP_TRACER_H_ */
