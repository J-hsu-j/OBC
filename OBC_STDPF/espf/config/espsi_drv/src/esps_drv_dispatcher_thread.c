/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup espsi_drv
 * @{
 *
 * @file     esps_drv_dispatcher_thread.c
 * @brief    Message dispatcher thread for the ESPS I MAC Driver
 *
 * @}
 */

#include <cmsis_os2.h>

#include "esps_drv_config.h"
#include "esps_drv_exeh_config.h"
#include "taskmon.h"
#include "taskmon_stat.h"

#include <esps_drv.h>
#include <esps_drv_dispatcher.h>
#include <esps_drv_debug.h>
#include "assertions.h"

extern bool MAC_bProtocolProcessMessage(eMACInterface_t fp_eMACId, ESSATMAC_Message *fp_psMsg);

/******************************************************************************
 * Local Preprocessor Definitions
 *****************************************************************************/
#define EXEH_CURRENT_MODULE_ID (eEXEHModuleID_MAC_DISPATCHER)
/// Error mask, returned by osThreadFlagsWait in case there are errors.
#define MAC_DISPATCH_ERROR (1U << 31U)
/// Flag for stopping the dispatcher.
#define MAC_DISPATCH_STOP_FLAG (0x02U)
/// Flag for activating the dispatcher.
#define MAC_DISPATCH_ACTIVATE_FLAG (0x01U)
/// All flags the dispatcher is waiting for (with osThreadFlagsWait)
#define MAC_DISPATCH_FLAGS (MAC_DISPATCH_STOP_FLAG | MAC_DISPATCH_ACTIVATE_FLAG)

typedef struct
{
    // ESPS Interface info
    sMACInterfaceState_t *psInterfaceState;
    // FreeRTOS thread
    osThreadId_t pvThread;
    // Command dispatcher instance to use with the active thread
    sMACDispatcher_t *psThreadDisp;
    // Task Monitor ID to assign to this thread
    task_mon_id_t tmon_id;
} sDispatcherThread_t;

static sDispatcherThread_t fs_sDispatcherThread_main = {
    .psInterfaceState = NULL,
    .pvThread         = NULL,
    .psThreadDisp     = NULL,
    .tmon_id          = TASK_ID_MACDRV_DISPATCHER
};

static sDispatcherThread_t fs_sDispatcherThread_prio = {
    .psInterfaceState = NULL,
    .pvThread         = NULL,
    .psThreadDisp     = NULL,
    .tmon_id          = TASK_ID_MACDRV_DISPATCHER_PRIO
};

/******************************************************************************
 * File Local Function Prototypes
 *****************************************************************************/
/**
 * Dispatcher thread entry function.
 *
 * @param fp_pvArg - Argument for the thread (MAC interface state).
 */
static void fs_vDispatchThread(void *fp_pvArg);

/**
 * Called to notify the dispatch threads that there are incoming frames to process.
 *
 * @param pDispatchThread - Dispatch thread context
 */
static void fs_vNotifyDispatcherThread(sDispatcherThread_t *const pDispatchThread);

static void fs_SpawnDispatchThread(sDispatcherThread_t *const fp_DispThreadCtx, task_mon_id_t tmon_task_id);

/******************************************************************************
 * Public function definitions
 *****************************************************************************/

// Initialize the dispatcher.
void DISP_vThreadInit(eMACInterface_t fp_eInterface)
{
    fs_sDispatcherThread_main.psInterfaceState = MacCfg_sGetMacInterfaceById(fp_eInterface);
    fs_sDispatcherThread_main.psThreadDisp     = &fs_sDispatcherThread_main.psInterfaceState->sDisp;
    fs_SpawnDispatchThread(&fs_sDispatcherThread_main, TASK_ID_MACDRV_DISPATCHER);

    fs_sDispatcherThread_prio.psInterfaceState = MacCfg_sGetMacInterfaceById(fp_eInterface);
    fs_sDispatcherThread_prio.psThreadDisp     = &fs_sDispatcherThread_main.psInterfaceState->sDispAlt;
    fs_SpawnDispatchThread(&fs_sDispatcherThread_prio, TASK_ID_MACDRV_DISPATCHER_PRIO);
}

// Set MAC_DISPATCH_FLAGS as active
void MacCfg_vDispatcherNotifCallback(eMACInterface_t fp_eMACId, sMACDispatcher_t *const fp_psDisp)
{
    if (fp_psDisp == fs_sDispatcherThread_main.psThreadDisp)
    {
        fs_vNotifyDispatcherThread(&fs_sDispatcherThread_main);
    }
    else
    {
        fs_vNotifyDispatcherThread(&fs_sDispatcherThread_prio);
    }
}

/******************************************************************************
 * Local Function Definitions
 *****************************************************************************/
static void fs_vNotifyDispatcherThread(sDispatcherThread_t *const pDispatchThread)
{
    uint32_t eStatus;

    CRIT_ASSERT(NULL != pDispatchThread);
    CRIT_ASSERT(NULL != pDispatchThread->pvThread);

    eStatus = osThreadFlagsSet(pDispatchThread->pvThread, MAC_DISPATCH_ACTIVATE_FLAG);

    if (eStatus != MAC_DISPATCH_ACTIVATE_FLAG)
    {
        EXEH_HANDLE(eEXEHSeverity_Fatal, (int32_t)eMACException_SystemCallFailed);
    }
}

// Spawn a single dispatch thread with the given parameters
static void fs_SpawnDispatchThread(sDispatcherThread_t *const fp_DispThreadCtx, task_mon_id_t tmon_task_id)
{
    CRIT_ASSERT(NULL != fp_DispThreadCtx);

    if (fp_DispThreadCtx->psInterfaceState != NULL)
    {
        // create thread only if not already existing...
        if (fp_DispThreadCtx->pvThread == NULL)
        {
            osThreadAttr_t dispAttr = {
                .attr_bits  = osThreadDetached,
                .name       = "MAC_DISP",
                .priority   = osPriorityNormal,
                .cb_mem     = NULL,
                .cb_size    = 0U,
                .stack_mem  = NULL,
                .stack_size = 3000
            };

            fp_DispThreadCtx->pvThread = osThreadNew(fs_vDispatchThread, (void *)fp_DispThreadCtx, &dispAttr);

            if (fp_DispThreadCtx->pvThread == NULL)
            {
                EXEH_HANDLE(eEXEHSeverity_Fatal, (int32_t)eMACException_SystemCallFailed);
            }
            else
            {
                task_mon_task_initialized(tmon_task_id);
                task_mon_register_for_stats(tmon_task_id, fp_DispThreadCtx->pvThread);
            }
        }
    }
}

// Dispatcher thread
static void fs_vDispatchThread(void *fp_pvArg)
{
    bool     bRunning = true;
    uint32_t u32Flags;

    CRIT_ASSERT(NULL != fp_pvArg);

    sDispatcherThread_t  *psDispThread = ((sDispatcherThread_t *)fp_pvArg);
    sMACInterfaceState_t *psInterface  = psDispThread->psInterfaceState;

    CRIT_ASSERT(NULL != psInterface);

    MACDRV_DBG_PRINT("MAC dispatcher thread started (instance: %ld @ 0x%08x)\r\n", (uint32_t)psInterface->macIfId, (uint32_t)fp_pvArg);

    while (bRunning)
    {
        // Wait for activation
        u32Flags = osThreadFlagsWait(MAC_DISPATCH_FLAGS, osFlagsWaitAny, 1000);

        if ((u32Flags & MAC_DISPATCH_ERROR) && (u32Flags != osErrorTimeout))
        {
            EXEH_HANDLE(eEXEHSeverity_Fatal, (int32_t)eMACException_SystemCallFailed);
        }
        else
        {
            if (((u32Flags != osErrorTimeout) && (u32Flags & MAC_DISPATCH_ACTIVATE_FLAG)) ||
                (u32Flags == osErrorTimeout))
            {
                MACDRV_DBG_PRINT("Trg RxQ %ld [flg: %ld])\r\n", (uint32_t)psInterface->macIfId, (uint32_t)u32Flags);

                MAC_DISP_vDispatchMessages(psInterface, psDispThread->psThreadDisp);
            }

            if ((u32Flags != osErrorTimeout) && (u32Flags & MAC_DISPATCH_STOP_FLAG))
            {
                EXEH_HANDLE(eEXEHSeverity_Fatal, (int32_t)eMACException_SystemCallFailed);
            }
        }
        task_mon_i_am_alive(psDispThread->tmon_id);
        task_mon_low_stack_check(psDispThread->tmon_id);
    }
}
