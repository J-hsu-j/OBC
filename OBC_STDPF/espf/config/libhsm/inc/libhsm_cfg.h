/*
 * Copyright (c) 2020-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef LIBHSM_CFG_H
#define LIBHSM_CFG_H

#ifdef UTEST
#include <stdbool.h>
void test_assert(bool cond);
void test_trace(const char *msg, ...);

#define HSM_ASSERT(cond)          test_assert(cond)
#define HSM_TRACE_INFO(msg, ...)  test_trace(msg, ##__VA_ARGS__)
#define HSM_TRACE_DEBUG(msg, ...) test_trace(msg, ##__VA_ARGS__)
#define HSM_TRACE_ERROR(msg, ...) test_trace(msg, ##__VA_ARGS__)
#else

#include "libhsm_trace.h"

#ifndef HSM_TRACE_INFO
#define HSM_TRACE_INFO(msg, ...)
#endif /* HSM_TRACE_INFO */

#ifndef HSM_TRACE_DEBUG
#define HSM_TRACE_DEBUG(msg, ...)
#endif /* HSM_TRACE_DEBUG */

#ifndef HSM_TRACE_ERROR
#define HSM_TRACE_ERROR(msg, ...)
#endif /* HSM_TRACE_ERROR */

#ifndef HSM_ASSERT
#include "main.h"
#include "trace.h"

#define HSM_ASSERT(cond)     \
    do                       \
    {                        \
        if (!(cond))         \
        {                    \
            Error_Handler(); \
        }                    \
    } while (false)
#endif /* HSM_ASSERT */
#endif /* UTEST */

#endif /* LIBHSM_CFG_H */
