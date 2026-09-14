/*
 * Copyright (c) 2023 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup eps_iii
 * @{
 *
 * @file if_tlm_dev.c
 * @brief common implementation for all EPS telemetry devices.
 *
 * @}
 *
 */

#include "if_tlm_dev.h"
#include "assertions.h"
#include "string.h"
#include "datacache.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

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
void tlm_dev_get_telemetry(const if_tlm_t *const self)
{
    ReqContext_t send_ctx = {
        .nAddr            = 0,
        .nInterfaceNumber = ESSASNI_SYS_PRI,
        .seqId            = 0, // Value to be updated by the ESPS Stack once the request is sent
        .netType          = ESSASNETT_INTERNAL
    };
    uint8_t sent_cmds = 0;

    BREAK_ASSERT(NULL != self);

    if (NULL != self)
    {
        send_ctx.nAddr = self->p_device_info->esps_dev_info.mac_addr;

        for (uint8_t i = 0; ((i < self->tlm_cfg.max_msg_to_send) && (self->tlm_cmd_cnt > sent_cmds)); i++)
        {
            ESSATMAC_ErrCodes res = self->p_tlm_req_cmds[sent_cmds](&send_ctx);

            uint8_t *p_fdir_exec_status   = self->p_device_info->p_fdir_exec_status;
            p_fdir_exec_status[sent_cmds] = res;

            if (ESSATMAC_EC_OK == res)
            {
                self->p_device_info->esps_dev_info.seq_id = send_ctx.seqId;
            }
            sent_cmds++;
            osDelay(self->tlm_cfg.delay_between_sending * 1000);
        }
    }
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
