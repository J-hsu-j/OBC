/*
 * Copyright (c) 2023 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef ONBOARD_SCHED_CFG_H
#define ONBOARD_SCHED_CFG_H

/**
 * @addtogroup onboard_sched
 * @{
 *
 * @file     onboard_sched_cfg.h
 * @brief    Compile-time configuration of the onboard scheduling service
 *
 * @}
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "fm_mng.h"
#include "comm_gw_if_cfg.h"

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/

/** @brief Cycle period of the main task of the onboard scheduling service.
 *
 *  @note Period should be chosen in such a way as to minimize the effects of OS
 *  scheduling overhead and subsequent jitter in the activation periods of tasks.
 */
#define SCHED_CYCLE_PERIOD 500U

/** @brief Maximum size of a command that can be scheduled. This is pure payload, for example
 *         the raw bytes of an FP command, or the name and execution timeout of a script.
 */
#define SCHED_CMD_MAX_SIZE 1024

/** @brief Maximum size of the byte sequence containing communication parameters for a scheduled command. */
#define SCHED_COMM_PARAMS_MAX_SIZE COMM_GW_COMM_PARAMS_MAX_SIZE

/** @brief Maximum size for buffers containing file names, including paths. Usually corresponds to the limitations
 *         set by the used file management service.
 */
#define SCHED_MAX_NAME_BUF_LEN FM_MAX_PATH

/** @brief Maximum number of characters for file names, including paths. This number excludes the null terminator. */
#define SCHED_MAX_NAME_LEN SCHED_MAX_NAME_BUF_LEN - 1

/** @brief Size of the stack that has to be allocated for the onboard scheduler service main task. */
#define SCHED_MAIN_STACK_SIZE 2048

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/** @brief Type for size and index calculations within a schedule entry. Depends on @ref SCHED_CMD_MAX_SIZE  */
typedef uint16_t sched_entry_payload_size_t;

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

#endif /* ONBOARD_SCHED_CFG_H */
