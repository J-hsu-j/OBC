/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup eps_iii
 * @{
 *
 * @file if_eps_dev.c
 * @brief common implementation for all EPS devices
 *
 * @}
 *
 */

#include "if_eps_dev.h"
#include "if_esps_dev.h"
#include <assertions.h>
#include <string.h>

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
void eps_dev_init(eps_dev_t *const self, uint8_t mac_address)
{
    BREAK_ASSERT(NULL != self);

    if (NULL != self)
    {
        self->esps_dev_info.mac_addr = mac_address;

        for (uint8_t cmd_id = 0; cmd_id < self->cmd_list_cnt; cmd_id++)
        {
            uint32_t data_size = dc_get_data_size(self->datacache_cmd_list[cmd_id]);
            uint8_t  buffer_to_write[data_size];

            memset(buffer_to_write, 0, data_size);

            dc_set_raw_data(DC_DATA_INPUT_INTERNAL,
                            self->datacache_cmd_list[cmd_id],
                            &buffer_to_write,
                            data_size);
        }

        memset(self->p_fdir_exec_status, 0, self->fault_exec_status_cnt);
    }
}

bool eps_dev_is_seq_expected(const eps_dev_t *const self, SeqId_t seq_id)
{
    bool res = false;
    BREAK_ASSERT(NULL != self);

    if (NULL != self)
    {
        res = (self->esps_dev_info.seq_id == seq_id);
    }

    return res;
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
