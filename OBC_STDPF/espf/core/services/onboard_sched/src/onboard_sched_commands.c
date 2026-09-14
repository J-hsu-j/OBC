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
 * @file     onboard_sched_commands.c
 * @brief    Implementation of the execution logic for comm_gw commands
 *
 * @}
 *
 */

#include <string.h>
#include "onboard_sched_commands.h"
#include "onboard_sched_cfg.h"
#include "onboard_sched_logging.h"
#include "assertions.h"
#include "trace.h"

#ifdef COMM_GW_ENABLED
#include "comm_gw.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

/** Offset of the communication interface (protocol) type from the beginning of the
 *  command-specific bytes in the scheduled entry. */
#define COMM_IF_TYPE_OFFSET 0

/** Offset of the size in bytes of the communication parameter structure for the command,
 *  from the beginning of the command-specific bytes in the scheduled entry. */
#define COMM_PARAMS_SIZE_OFFSET (COMM_IF_TYPE_OFFSET + 1)

/** Offset of the communication parameters for the command, from the beginning of the command-specific
 *  bytes in the scheduled entry. */
#define COMM_PARAMS_OFFSET (COMM_PARAMS_SIZE_OFFSET + 1)

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

INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

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

void onboard_sched_commands_execute_command(const uint8_t *const             p_buf,
                                            const sched_entry_payload_size_t size)
{
    if (NULL == p_buf)
    {
        BREAK_ASSERT(false);
        return;
    }

    // Layout of the command bytes pointed at by p_buf:
    //   __________________________________________________________________________________________
    //  | Command IF type | Command params size | Command params |  Timeout  |    Command bytes    |
    //  |    (1 byte)     |      (1 byte)       |   (variable)   | (4 bytes) |   (variable, max    |
    //  |_________________|_____________________|________________|___________|_SCHED_CMD_MAX_SIZE)_|

    comm_gw_send_ctx_t ctx;
    uint32_t           resp_size = 0;
    uint8_t *const     p_out_buf = onboard_sched_logging_get_build_buf_current();

    const uint8_t comm_if_type = p_buf[COMM_IF_TYPE_OFFSET];

    // Communication parameters may vary according to the protocol used for the command, thus the
    // dynamic size
    uint8_t comm_params_size = p_buf[COMM_PARAMS_SIZE_OFFSET];
    if (SCHED_COMM_PARAMS_MAX_SIZE < comm_params_size)
    {
        comm_params_size = SCHED_COMM_PARAMS_MAX_SIZE;
    }

    // Calculate the position in p_buf of the command's timeout
    const size_t cmd_timeout_offset = COMM_PARAMS_OFFSET + comm_params_size;

    // This is where the actual protocol command starts
    const size_t in_data_offset = cmd_timeout_offset + sizeof(uint32_t);

    // This is where the actual response bytes shall be written - after the byte holding the
    // execution result
    const size_t out_data_offset = in_data_offset + sizeof(comm_gw_comm_res_t);

    // Generated command doesn't have a result byte, hence the index
    ctx.p_resp_data      = &p_out_buf[out_data_offset];
    ctx.p_resp_data_size = &resp_size;
    ctx.p_comm_params    = &p_buf[COMM_PARAMS_OFFSET];

    ctx.resp_timeout = *(const uint32_t *const)&p_buf[cmd_timeout_offset];
    ctx.p_req_data   = &p_buf[in_data_offset];
    // Generation should guarantee that command entry has some actual protocol command
    BREAK_ASSERT(size > in_data_offset);
    ctx.req_data_size      = size - in_data_offset;
    ctx.resp_data_max_size = SCHED_CMD_MAX_SIZE;

    // Store all command parameters in the output buffer. This is basically everything
    // from the beginning of the input buffer to the protocol command bytes. Hence
    // the use of in_data_offset as number of bytes to be copied
    memcpy(&p_out_buf[COMM_IF_TYPE_OFFSET], p_buf, in_data_offset);

    // Invoke command. This is a synchronous call
    const comm_gw_comm_res_t res = comm_gw_send((const comm_gw_if_id_t)comm_if_type,
                                                COMM_GW_USER_ID_OBC_SCHEDULER, &ctx);

    // Store result
    *(comm_gw_comm_res_t *)(&p_out_buf[in_data_offset]) = res; // Reuse the index for input data

    // Move the current write index of the builder buffer
    onboard_sched_logging_inc_build_index((sched_entry_payload_size_t)(resp_size + out_data_offset));

    ES_TRACE_DEBUG(", COMMAND\n");
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

#endif /* COMM_GW_ENABLED */
