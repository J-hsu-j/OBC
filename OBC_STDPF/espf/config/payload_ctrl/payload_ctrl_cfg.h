/*
 * Copyright (c) 2023 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef PAYLOAD_CTRL_CFG_USER_H
#define PAYLOAD_CTRL_CFG_USER_H
/**
 * @addtogroup payload_ctrl
 * @{
 *
 * @file payload_ctrl_cfg.h
 * @brief Compile-time configuration of the payload controller service.
 * @}
 */
#include <stdbool.h>
#include "if_payload_control.h"
#include "payload_ctrl_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/

/** @brief Timeout in milliseconds after which the main task gets automatically unblocked if
 *         @ref PAYLOAD_TASK_ACTIVATE_FLAGS is not set
 */
#define PAYLOAD_TASK_TIMEOUT_MS (1000U)

/** @brief Timeout after which a warning is raised if the payload is
 *         still in starting or stopping state.
 */
#define PAYLOAD_TRANSIENT_STATE_TIMEOUT_MS (10000U)

/** @brief Size of the stack that has to be allocated for the payload controller service main task. */
#define PAYLOAD_CTRL_STACK_SIZE (3000U)

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/**
 *  @brief Enumeration with identifiers for each payload in the system
 */
typedef enum
{
    PAYLOAD_SX_BAND,
#if defined(SDR_ENABLED)
    PAYLOAD_SDR,
#endif
#if defined(XBAND_FE_ENABLED)
    PAYLOAD_XBAND_FE,
#endif
    PAYLOAD_COUNT
} payload_ctrl_payload_t;

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

/**
 * @brief Used to obtain the payload-specific configuration from FLASH.
 * @param[in] payload_id Payload identifier
 *
 * @return Pointer to the payload configuration structure
 */
const payload_immutable_cfg_t *const payload_ctrl_cfg_get(const payload_ctrl_payload_t payload_id);

/**
 * @brief Checks if the sysem is in a mode that allows payloads to run.
 *
 * @retval true  System is in a mode that allows payloads to run.
 * @retval false System is in a mode that doesn't allow payloads to run.
 */
bool payload_ctrl_cfg_is_payload_mode(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PAYLOAD_CTRL_CFG_USER_H */
