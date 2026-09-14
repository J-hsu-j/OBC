/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup onboard_sched
 * @{
 *
 * @file     onboard_sched_commands.h
 * @brief    Internal interface to the execution logic for comm_gw commands
 *
 * @}
 *
 */

#ifndef ONBOARD_SCHED_COMMANDS_H
#define ONBOARD_SCHED_COMMANDS_H

#ifdef COMM_GW_ENABLED

#include "es_cdef.h"
#include "onboard_sched_types.h"

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
/**
 * @brief Sends a command to the communication gateway.
 *
 * @param p_buf[in]: Reference to the schedule entry bytes.
 * @param size[in]: Number of bytes behind p_buf.
 *
 */
void onboard_sched_commands_execute_command(const uint8_t *const             p_buf,
                                            const sched_entry_payload_size_t size);

#endif /* COMM_GW_ENABLED */

#endif /* ONBOARD_SCHED_COMMANDS_H */
