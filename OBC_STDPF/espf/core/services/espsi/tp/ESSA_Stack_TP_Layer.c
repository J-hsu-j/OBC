/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup tp
 * @{
 *
 * @file     ESSA_Stack_TP_Layer.c
 * @brief    TP layer handler definitions
 *
 * @}
 */

#include <esps_drv_config.h>
#include <esps_drv_def.h>
#include "cmsis_os2.h"
#include "stm32h7xx_hal.h"
#include "es_exeh.h"
#include "ESSA_Stack_TP_Layer.h"
#include "ESPLATFORM_NETWORK_STACK/ES_TL_LAYER/ESTL_Drv.h"
#include "CP_Handler.h"
#include "FWUPD_Handler.h"
#include "ESSA_CommonUtils.h"
#include "taskmon.h"
#include "taskmon_stat.h"

#define EXEH_CURRENT_MODULE_ID (eEXEHModuleID_ESSA_STACK_TP_LAYER)
#define UNBLOCK_TP_THREAD_FLAG (1U)
#define TASK_PERIOD_MS         (50)
#define WD_KICK_PERIOD         (2000)

static osThreadId_t     MACTL_TaskHandle = NULL;
static ESTL_TL_HostIntf tlIntf;

static const osThreadAttr_t MACTL_Task_attributes = {
    .name       = "MACTLDrvTask",
    .priority   = (osPriority_t)osPriorityNormal,
    .stack_size = 6500
};

/** @brief Handle to a TP layer thread which is currently blocked */
static osThreadId_t h_waiting_thread = NULL;

static void MACTL_Task(void *argument);
static void OnESTL_Exception(uint16_t nFileID, uint16_t nLine);
static void OnESTL_Notification(uint16_t nFileID, uint16_t nLine);

static void OnESTL_Exception(uint16_t nFileID, uint16_t nLine)
{
    EXEH_vException(eEXEHSeverity_Error, EXEH_CURRENT_MODULE_ID, nFileID, (uint32_t)nLine);
}

static void OnESTL_Notification(uint16_t nFileID, uint16_t nLine)
{
    EXEH_vException(eEXEHSeverity_Warning, EXEH_CURRENT_MODULE_ID, nFileID, (uint32_t)nLine);
}

static void MACTL_Task(void *argument)
{
    (void)argument;

    uint8_t u8AliveCntr = 0U;

    while (true)
    {
        ESTL_Drv_Task();
        ESCP_ModDrv_Task();
        ESCCP_ModDrv_Task();
        ESFWUPD_ModDrv_Task();

        // user-handling of CP commands
        CP_Handler_Task();

        osDelay(TASK_PERIOD_MS);

        u8AliveCntr++;

        if ((u8AliveCntr * TASK_PERIOD_MS) >= WD_KICK_PERIOD)
        {
            u8AliveCntr = 0U;
            task_mon_i_am_alive(TASK_ID_MACTL_DISPATCHER);
            task_mon_low_stack_check(TASK_ID_MACTL_DISPATCHER);
        }
    }
}

osThreadId_t ESSA_Stack_TP_Layer_GetMainThreadHandle(void)
{
    return MACTL_TaskHandle;
}

void ESSA_Stack_TP_Layer_Init(void)
{
    // Initialise the 'Transport Layer'
    tlIntf.nMacAddress    = MacCfg_u8GetMacAddress(eMAC_Interface_Primary);
    tlIntf.TickGet16      = &ESSA_CommonUtils_getTickU16;
    tlIntf.TickGet32      = &HAL_GetTick;
    tlIntf.OnException    = OnESTL_Exception;
    tlIntf.OnNotification = OnESTL_Notification;

    ESTL_Drv_Init(&tlIntf, true);

    FWUPD_Handler_Init();

    CP_Handler_Init();

    MACTL_TaskHandle = osThreadNew(MACTL_Task, NULL, &MACTL_Task_attributes);
    CRIT_ASSERT(MACTL_TaskHandle);
    task_mon_register_for_stats(TASK_ID_MACTL_DISPATCHER, MACTL_TaskHandle);

    task_mon_task_initialized(TASK_ID_MACTL_DISPATCHER);
}

bool ESSA_Stack_TP_Layer_PrepareThreadWait(void)
{
    bool result = false;

    if (NULL == h_waiting_thread)
    {
        h_waiting_thread = osThreadGetId();
        result           = true;
    }

    return result;
}

eThreadBlockEvt_t ESSA_Stack_TP_Layer_ThreadWaitForEvent(uint32_t u32TimeoutMs)
{
    uint32_t          u32OsThreadFlagsResult = 0U;
    eThreadBlockEvt_t result                 = THREADBLOCKEVT_ERROR;

    if (NULL != h_waiting_thread)
    {
        u32OsThreadFlagsResult = osThreadFlagsWait(UNBLOCK_TP_THREAD_FLAG,
                                                   osFlagsWaitAll,
                                                   u32TimeoutMs);

        if ((u32OsThreadFlagsResult & UNBLOCK_TP_THREAD_FLAG) == UNBLOCK_TP_THREAD_FLAG)
        {
            result = THREADBLOCKEVT_WAITFINISHED;
        }
        else if (u32OsThreadFlagsResult == (uint32_t)osErrorTimeout)
        {
            result           = THREADBLOCKEVT_WAITTIMEOUT;
            h_waiting_thread = NULL;
        }
    }
    else
    {
        // Cleanup, just in case ReleaseThreadWait has already been called before
        osThreadFlagsClear(UNBLOCK_TP_THREAD_FLAG);

        // Release has been called in advance. No need to wait
        result = THREADBLOCKEVT_WAITFINISHED;
    }

    return result;
}

void ESSA_Stack_TP_Layer_ReleaseThreadWait(void)
{
    if (h_waiting_thread != NULL)
    {
        (void)osThreadFlagsSet(h_waiting_thread, UNBLOCK_TP_THREAD_FLAG);
        h_waiting_thread = NULL;
    }
}
