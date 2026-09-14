/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/*
*********************************************************************************************
* INCLUDES
*********************************************************************************************
*/
#include "AppTasks.h"
#include "taskmon.h"
#include "taskmon_stat.h"
#include "datacache.h"
#include "conops.h"
#include "nvm_rc.h"
#include "limits.h"
#include "drv_led.h"
#include "if_sys_conf.h"
#include "cmsis_os2.h"
#include "arm_fault_handler.h"
#include "fault_persistor.h"
#include "datetime.h"
#include "fm_mng.h"
#include "FreeRTOSConfig.h"

#include <stdint.h>
#include <stdatomic.h>

/*
*********************************************************************************************
* INTERNAL DEFINES
*********************************************************************************************
*/
#define APP_LED_ON_TIME      (5)    /**< Given time in ms */
#define APP_TASK_CALL_PERIOD (1000) /**< Period for the aplication task */
/**< Used to convert FreeRTOS's TICK_RATE_HZ callback to seconds */
#define UPTIME_RESOLUTION_1S (1000U)

/*
*********************************************************************************************
* INTERNAL TYPES DEFINITION
*********************************************************************************************
*/

/*
*********************************************************************************************
* EXTERNAL VARIABLES DEFINITION
*********************************************************************************************
*/

/*
*********************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
*********************************************************************************************
*/
static osThreadId_t         StartAppTask_TaskHandle;
static const osThreadAttr_t StartAppTask_attributes = {
    .name       = "StartAppTask",
    .priority   = (osPriority_t)osPriorityNormal,
    .stack_size = 2500
};

/**
 * @brief Time in seconds since last reset
 */
static __attribute__((aligned(4))) atomic_uint_fast32_t uptime_seconds = ATOMIC_VAR_INIT(0U);

/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
*********************************************************************************************
*/
static void app_task(void *argument);
static void apptask_update_obc_data(void);

// Agent_change_1: Bench test 用的 UART6 連續送 0xAA task（用獨立 thread 避免阻塞既有流程）/////////
#if defined(PAYLOAD_UART6_TX_TEST)
static osThreadId_t         PayloadUart6TxTaskHandle;
static const osThreadAttr_t PayloadUart6TxTask_attributes = {
    .name       = "PayU6Tx",
    .priority   = (osPriority_t)osPriorityBelowNormal,
    .stack_size = 1024
};

static void payload_uart6_tx_task(void *argument)
{
    (void)argument;
    payload_communication_start();
}
#endif
////////////////////////////////////////////////////////////////////////////

/*
*********************************************************************************************
* EXTERNAL (NONE STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/

void AppTask_Init(void)
{
    StartAppTask_TaskHandle =
        osThreadNew(app_task, NULL, &StartAppTask_attributes);

    task_mon_register_for_stats(TASK_ID_APP, StartAppTask_TaskHandle);
    CRIT_ASSERT(StartAppTask_TaskHandle);

// Agent_change_1: 建立 bench test thread（不影響既有 StartAppTask）/////////
#if defined(PAYLOAD_UART6_TX_TEST)
    PayloadUart6TxTaskHandle = osThreadNew(payload_uart6_tx_task, NULL, &PayloadUart6TxTask_attributes);
    CRIT_ASSERT(PayloadUart6TxTaskHandle);
#endif
////////////////////////////////////////////////////////////////////////////
}

uint32_t get_uptime_seconds(void)
{
    return (uint32_t)(atomic_load_explicit(&uptime_seconds, memory_order_relaxed));
}

/**
 * @brief Task function of the application task
 */
static void app_task(void *argument)
{
    arm_fault_handler_env_t env_data = {
        .rtc_time = 0U,
        .uptime   = 0U
    };

    static bool exceptions_persisted_to_file = false;

    datetime_stamp_t timestamp_now;

    (void)memset(&timestamp_now, 0U, sizeof(datetime_stamp_t));

    task_mon_task_initialized(TASK_ID_APP); /* The task is initialized and is ready */

    uint32_t wait_mark = osKernelGetTickCount() + APP_TASK_CALL_PERIOD;
    for (;;)
    {
        task_mon_i_am_alive(TASK_ID_APP); /* Prevent from WatchDog reset */

        if (false != sys_conf_is_valid())
        {
            /* blink the Green LED for 50ms to indicate the OBC is running */
            drv_led_set(DRV_LED_ID_GREEN, DRV_LED_STATE_ON);
            osDelay(APP_LED_ON_TIME);
            drv_led_set(DRV_LED_ID_GREEN, DRV_LED_STATE_OFF);
        }
        else
        {
            /* blink the amber LED to indicate there is an error in the configuration validation */
            drv_led_set(DRV_LED_ID_AMBER, DRV_LED_STATE_ON);
            osDelay(APP_LED_ON_TIME);
            drv_led_set(DRV_LED_ID_AMBER, DRV_LED_STATE_OFF);
        }

        // update general DataCache entries...
        apptask_update_obc_data();

        // update fault context
        datetime_now(&timestamp_now);

        env_data.uptime   = osKernelGetTickCount();
        env_data.rtc_time = (uint32_t)datetime_to_unix(&timestamp_now);
        arm_fault_handler_set_env(&env_data);

        if ((true == fm_storage_status_ready(FM_VOL_SD_PATH)) && (!exceptions_persisted_to_file))
        {
            fault_persistor_dump_to_file("fault.dmp");
            exceptions_persisted_to_file = true;
        }

        osDelayUntil(wait_mark);                                   /* Give processing time for the other tasks */
        wait_mark = osKernelGetTickCount() + APP_TASK_CALL_PERIOD; /* Immediately get kernel tick after return for best precision */

        task_mon_low_stack_check(TASK_ID_APP);
    }
}

/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/
/**
 * @brief Updates DataCache with some general OBC data
 */
static void apptask_update_obc_data(void)
{
    DATA_CACHE_OBC_0_t obc_data;

    conops_get_hsm_active_state(&obc_data.u8OpMode);
    obc_data.u32UpTime = get_uptime_seconds();

    // to avoid potential unaligned memory access, we use a stack variable to get the value and then assign it
    // to obc_data entry
    uint16_t u16ResetReasonBitField = 0U;
    uint32_t total_reset_count      = nvm_rc_get_total(&u16ResetReasonBitField);
    obc_data.u16ResetReasonBitField = u16ResetReasonBitField;

    obc_data.u16TotalResetCount = (total_reset_count <= UINT16_MAX) ? ((uint16_t)total_reset_count) : (UINT16_MAX);

    obc_data.u16PayloadModesStatus = 0U;

    // TODO: Data Transfer mode still in discussion and no status available at the moment

    dc_set_obc_0_data(&obc_data);
}

/**
 * @brief Calculates the increment of the uptime counter based on FreeRTOS's interrupt hook
 * every 1ms for FreeRTOSConfig -> configTICK_RATE_HZ = 1000
 */
void vApplicationTickHook (void)
{
    static_assert(configTICK_RATE_HZ == ((TickType_t)1000), "configTICK_RATE_HZ must be 1000 for upTime to work properly");
    static_assert(configUSE_TICK_HOOK == 1, "configUSE_TICK_HOOK must be 1 for upTime to work properly");
    static_assert(configUSE_TICKLESS_IDLE == 0, "configUSE_TICKLESS_IDLE must be 0 for upTime to work properly");

    static uint32_t ms_counter = 0U;
    ms_counter++;

    if(UPTIME_RESOLUTION_1S <= ms_counter)
    {
        ms_counter = 0U;
        atomic_fetch_add(&uptime_seconds, 1U);
    }
}

/********************************************************************************************* */
