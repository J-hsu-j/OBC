/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup lwip_tracer
 * @{
 *
 * @file lwip_tracer.c
 *
 * LWIP trace wrapper implementation
 *
 * @}
 */

#include "lwip_tracer.h"

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>

#include "es_cdef.h"
#include "trace.h"

INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

void lwip_es_trace_fatal(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    // Buffer to hold the LWIP formatted string
    char lwip_trace_msg[LWIP_SERVICE_TRACE_BUF_SZ] = { '\0' };

    int32_t trace_str_sz = (int32_t)vsnprintf((char *)lwip_trace_msg,
                                              sizeof(lwip_trace_msg),
                                              format,
                                              args);

    // Add terminating null just in case
    lwip_trace_msg[sizeof(lwip_trace_msg) - 1] = '\0';

    if ((trace_str_sz > 0) && (trace_str_sz > (int32_t)sizeof(lwip_trace_msg)))
    {
        ES_TRACE_WARN("LWIP trace requires %ld characters but only %ld reserved", trace_str_sz, sizeof(lwip_trace_msg));
    }
    else if (trace_str_sz <= 0)
    {
        ES_TRACE_ERROR("LWIP trace format failed with error %d", trace_str_sz);
    }
    else
    {
        ES_TRACE_FATAL("%s", lwip_trace_msg);
    }

    va_end(args);
}
