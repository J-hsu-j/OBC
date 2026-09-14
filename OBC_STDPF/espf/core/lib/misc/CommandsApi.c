/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup misc
 * @{
 *
 * @file CommandsApi.c
 * @brief Implementation of the Commands API
 *
 * @}
 */

#include "es_cdef.h"
#include <CommandsApi.h>
#include "DAT_Inputs.h"
#include "main.h"
#include "taskmon.h"
#include "nvm_rc.h"
#include "nvm/inc/nvm.h"

StdResult_t WriteHandler_ResetInBootOrAppMode(const AppMode_t appMode)
{
    StdResult_t res = STDRESULT_SUCCESS;
    boot_struct BootData;

    Nvm_GetBlockById(NVM_BLOCK_BOOTDATA, &BootData);
    switch (appMode)
    {
        case APPMODE_APPLICATION:
            BootData.Mailbox = MAILBOX_VAL_APPL;
            break;

        case APPMODE_BOOTLOADER:
            BootData.Mailbox = MAILBOX_VAL_BOOT;
            break;

        case APPMODE_AUTO_FW_UPDATE:
            BootData.Mailbox = MAILBOX_VAL_AUTO_FLASH;
            break;
        default:
            res = STDRESULT_INVALID_ARGS;
            break;
    }

    if (res == STDRESULT_SUCCESS)
    {
        nvm_rc_clear(RSTCOUNTERID_ALL);
        BootData.RebootRequest = pdTRUE;
        // set valid checksum for the RTC backup registers after changing the mailbox
        Nvm_SetBlockById(NVM_BLOCK_BOOTDATA, &BootData, NVMSETBLOCK_STORE_IMMEDIATELY);

        // Reset the OBC
        task_mon_trigger_delayed_reset(1000U);
    }

    return res;
}
