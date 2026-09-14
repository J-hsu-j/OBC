/**
 * Copyright (c) 2024 EnduroSat AD. All rights reserved
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef TRACE_DEFS_H_
#define TRACE_DEFS_H_

/**
 * @addtogroup Libraries
 * @{
 *
 * @addtogroup libtrace
 * @{
 *
 * @file trace_defs.h
 *
 * @}
 * @}
 */

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

    /*
    ***************************************************************************************************
    * EXTERNAL DEFINES
    ***************************************************************************************************
    */

#define TRACE_LVL_ENABLE(lvl) (1 << (uint8_t)(lvl))

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

#endif /* TRACE_DEFS_H_ */
