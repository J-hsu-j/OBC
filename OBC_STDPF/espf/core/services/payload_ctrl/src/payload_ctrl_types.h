/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef PAYLOAD_CTRL_TYPES_H
#define PAYLOAD_CTRL_TYPES_H

/**
 * @addtogroup payload_ctrl
 * @{
 *
 * @file payload_ctrl_types.h
 * @brief Types used internally by the component and its configuration
 * @}
 */

#include "if_payload_control.h"

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

/** @brief Payload configuration structure in FLASH */
typedef struct
{
    const pl_control_if_t *const p_pl_interface;   /**< Pointer to the payload manager interface */
    const pl_instance_id_t       internal_inst_id; /**< Internal id of the individual payload manager instance */
    const pl_config_t            init_config;      /**< Payload-specific configuration data */
    const p_pl_event_notify_t    p_pl_notif_cbk;   /**< Pointer to the payload instance notification callback */
} payload_immutable_cfg_t;

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

#endif /* PAYLOAD_CTRL_TYPES_H */
