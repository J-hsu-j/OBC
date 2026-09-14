/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef LIBHSM_TRACE_H
#define LIBHSM_TRACE_H

/**
 * @addtogroup libhsm
 * @{
 *
 * @defgroup libhsm_trace Libhsm trace
 * @{
 *
 * The libhsm trace adapter provides:
 *     - Mapping between the HSM_TRACE_* macros
 *     - Execution of the trace function responsible for the actual tracing
 *
 * @file libhsm_trace.h
 *
 * @brief The trace adapter, integrated with libtrace, maps the libhsm trace macros
 *
 * @}
 * @}
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>

#include "es_cdef.h"
#include "trace.h"
#include "assertions.h"

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
#define HSM_TRACE_INFO(msg, ...)  libhsm_trace_hook(LIBHSM_INFO, msg, ##__VA_ARGS__)
#define HSM_TRACE_DEBUG(msg, ...) libhsm_trace_hook(LIBHSM_DEBUG, msg, ##__VA_ARGS__)
#define HSM_TRACE_ERROR(msg, ...) libhsm_trace_hook(LIBHSM_ERROR, msg, ##__VA_ARGS__)

/* Map HSM_ASSERT macro to CRIT_ASSERT from assertions.h */
#define HSM_ASSERT(condition) CRIT_ASSERT(condition)

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/
/** @brief Libhsm debug level enumeration */
typedef enum
{
    LIBHSM_INFO,
    LIBHSM_DEBUG,
    LIBHSM_ERROR
} libhsm_debug_level_t;
/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/
/** @brief libshm debug hook handler
 *
 *  @param level debug trace level
 *  @param msg   format printf-like format string
 *  @param ...   variable list of arguments which match the given `format` string
 */
void libhsm_trace_hook(libhsm_debug_level_t level, const char *msg, ...);

#ifdef __cplusplus
}
#endif

#endif /* LIBHSM_TRACE_H */
