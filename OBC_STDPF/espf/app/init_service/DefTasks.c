/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/*
********************************************************************************************
* INCLUDES
********************************************************************************************
*/
#include "es_cdef.h"
#include "AppTasks.h"
#include "taskmon.h"
#include "taskmon_stat.h"
#include "trace.h"
#include "if_sys_conf.h"
#include "datetime.h"
#include "sensor_data_service.h"

#ifdef COMM_RS485_MAC_LAYER_ENABLED
#include "ESSA_Stack_Facade.h"
#endif

#if defined(BEACONS_ENABLED)
#include "beacons.h"
#endif

/*
********************************************************************************************
* INTERNAL DEFINES
********************************************************************************************
*/
#define APP_LED_ON_TIME (50) /* given time in ms */

/*
********************************************************************************************
* INTERNAL TYPES DEFINITION
********************************************************************************************
*/

/*
********************************************************************************************
* EXTERNAL VARIABLES DEFINITION
********************************************************************************************
*/

/*
********************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
********************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

static unix_time_t ServicesTask_RTC_StartTime;

static osThreadId_t         ServicesTask_TaskHandle;
static const osThreadAttr_t ServicesTask_attributes = {
    .name     = "ServicesTask",
    .priority = osPriorityAboveNormal1, // This task shall initialize the ESSA stack so it must be
                                        // executed with highest priority in the system.
    .stack_size = 3000U
};

/*
********************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
********************************************************************************************
*/
static void InitCompleted(void);
static void ServicesTask(void *argument);

/*
********************************************************************************************
* EXTERNAL (NONE STATIC) ROUTINES DEFINITION
********************************************************************************************
*/
/*!
*********************************************************************************************
* @brief Init routine for the DefTasks component
*********************************************************************************************
* @param[input]      none
* @param[output]     none
* @return            none
* @note              none
*********************************************************************************************
*/
void ServicesTask_Init(void)
{
    ServicesTask_RTC_StartTime = datetime_to_unix_now();

    ServicesTask_TaskHandle = osThreadNew(ServicesTask, NULL, &ServicesTask_attributes);
    CRIT_ASSERT(NULL != ServicesTask_TaskHandle);
    task_mon_register_for_stats(TASK_ID_SERVICES, ServicesTask_TaskHandle);
    task_mon_task_initialized(TASK_ID_SERVICES); /* The task is initialized and is ready */
}

/*!
********************************************************************************************
* @brief Routine utilised by the task, that handles all service operations.
********************************************************************************************
* @param[input]      none
* @param[output]     none
* @return            none
* @note              none
********************************************************************************************
*/
static void ServicesTask(void *argument)
{
    static safe_bool_t esps_started = SAFE_FALSE;

    InitCompleted();

    while (1)
    {
        task_mon_i_am_alive(TASK_ID_SERVICES); /* Prevent from WatchDog reset */

        // NOTE:
        // ESPS-related initialization is performed in a task context to ensure the OS is
        // already started when ESPS driver is activated because heavy communication at OBC start
        // could introduce too many interrupts which will prevent the OS to initialize properly
        if (IS_FALSE(esps_started))
        {
            // First initilize the ESSA stack. Don't put any other functions before this one, especially
            // if they call osDelay
            ESSA_Stack_Facade_Init();

            /* Initialize the service for reading sensors. This is done in a task because
             * some of the drivers use OS primitives */
            sds_init();

#if defined(BEACONS_ENABLED)
            beacons_init();

            beacons_start();
#endif // #if defined(BEACONS_ENABLED)

            esps_started = SAFE_TRUE;
        }

        osDelay(SERVICE_TASK_PERIOD);

        task_mon_low_stack_check(TASK_ID_SERVICES);
    }
}

void vApplicationIdleHook(void)
{
    // Ram / Rom check
    // Some functions in service task can run here
}

/*
********************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
********************************************************************************************
*/
/*!
********************************************************************************************
* @brief Check if all tasks has been initialised and if yes - prints a string once.
********************************************************************************************
* @param[input]      none
* @param[output]     none
* @return            none
* @note              none
********************************************************************************************
*/
static void InitCompleted(void)
{
    static uint8_t complete = 0;

    if ((0 == complete) && (0 != task_mon_check_task_init()))
    {
        ES_TRACE_INFO("OK+OBC initialisation completed\r\n"); /* OBC GUI application needs that string to end or start a operation */
        complete = 1;
    }
}

uint32_t ServicesTask_UptimeSeconds(void)
{
    return (datetime_to_unix_now() - ServicesTask_RTC_StartTime);
}

/* **************************************************************************************** */
