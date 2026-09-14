/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef __AOCS_CNTRL_DBG_H__
#define __AOCS_CNTRL_DBG_H__

/**
 * @addtogroup aocs_cntrl
 * @{
 *
 * @file     aocs_cntrl_dbg.h
 * @brief    Debug macros used throughout the AOCS control logic
 *
 * @}
 */

#include "trace.h"

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
#define AOCS_CNTRL_HEAD_DBG "[AOCS_CNTRL]"

#define AOCS_CNTRL_TRACE_INFO(msg, ...) ES_TRACE_INFO(msg OPT_VA_ARGS(__VA_ARGS__))
#define AOCS_CNTRL_TRACE_DBG(msg, ...)  ES_TRACE_DEBUG(msg OPT_VA_ARGS(__VA_ARGS__))

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
#endif // #ifdef __cplusplus

#endif // #ifndef __AOCS_CNTRL_DBG_H__
