/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef CSP_ACCESS_H
#define CSP_ACCESS_H
#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @addtogroup csp_service
 * @{
 *
 * @file csp_access.h
 * @brief Common access header for the CSP stack where compiler diagnostic suppressions may be added on demand.
 *
 * @}
 */

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push                 // Store current compiler diagnostic options
#pragma GCC diagnostic ignored "-Wpedantic" // Ignore the -pedantic setting because CSP uses some non-standard extensions
#endif
#include "csp/csp.h"
#include "csp/arch/csp_thread.h"
#include "csp/arch/csp_malloc.h"
#include "csp/interfaces/csp_if_kiss.h"
#include "csp/interfaces/csp_if_can.h"
#include "csp/interfaces/csp_if_lo.h"
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic pop // Restore compiler diagnostic options
#endif
/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/
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
#ifdef __cplusplus
}
#endif
#endif /* CSP_ACCESS_H */
