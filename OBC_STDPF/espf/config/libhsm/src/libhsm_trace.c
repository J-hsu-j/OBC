/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup libhsm_trace
 * @{
 *
 * @file    libhsm_trace.c
 * @brief   Trace adapter, integrated with libtrace, maps the libhsm trace macros
 *
 * @}
 */
#include <stdio.h>

#include "libhsm_trace.h"
/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
#define LIBHSM_SERVICE_TRACE_MSG_SZ (128U)

INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
void libhsm_trace_hook(libhsm_debug_level_t level, const char *msg, ...)
{

    BREAK_ASSERT(NULL != msg);

    va_list args;
    va_start(args, msg);

    /* Buffer to hold the libhsm formatted message */
    char libhsm_trace_msg[LIBHSM_SERVICE_TRACE_MSG_SZ] = { '\0' };

    int32_t trace_str_sz = vsnprintf((char *)libhsm_trace_msg,
                                     CDEF_ELEMENT_COUNT(libhsm_trace_msg),
                                     msg,
                                     args);

    /* Add terminating null just in case */
    libhsm_trace_msg[sizeof(libhsm_trace_msg) - 1] = '\0';

    if ((trace_str_sz > 0) && ((uint32_t)trace_str_sz > sizeof(libhsm_trace_msg)))
    {
        ES_TRACE_WARN("Libhsm trace requires %ld characters but only %ld reserved",
                      trace_str_sz,
                      sizeof(libhsm_trace_msg));
    }

    if (trace_str_sz <= 0)
    {
        ES_TRACE_ERROR("Libhsm trace format failed with error %d", trace_str_sz);
    }

    switch (level)
    {
        case LIBHSM_INFO:
            ES_TRACE_INFO("%s", libhsm_trace_msg);
            break;

        case LIBHSM_DEBUG:
            ES_TRACE_DEBUG("%s", libhsm_trace_msg);
            break;

        case LIBHSM_ERROR:
            ES_TRACE_ERROR("%s", libhsm_trace_msg);
            break;

        default:
            {
                ES_TRACE_DEBUG("|Unknown(%d)| %s", (uint8_t)level, libhsm_trace_msg);
                ES_TRACE_WARN("Bad libhsm trace level '%d'", (uint8_t)level);
            }
    }

    va_end(args);
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
