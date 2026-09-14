/*
 * Copyright (c) 2023 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef PAYLOAD_SHARED_TYPES_H
#define PAYLOAD_SHARED_TYPES_H
/**
 * @addtogroup payload_ctrl
 * @{
 *
 * @file payload_shared_types.h
 * @brief Payload shared types header
 * @}
 */

#include "es_cdef.h"
#include "fm_mng.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

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

/** @brief Generic argument structure with flags and argument buffer
 *
 *  @note Rationale for choosing size of pl_args based on longest allowed file path in the
 *  system is that if the arguments are big, they can be defined in a file.*/
typedef struct
{
    uint8_t flags;                /**< Payload-specific setup flags */
    uint8_t pl_args[FM_MAX_PATH]; /**< Buffer for payload-specific arguments */
} PACKED pl_args_t;

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
#endif /* __cplusplus */
#endif /* PAYLOAD_SHARED_TYPES_H */
