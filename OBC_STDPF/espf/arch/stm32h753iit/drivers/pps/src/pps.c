/*
 * Copyright (c) 2023 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup Drivers
 * @{
 * @defgroup pps
 * @{
 * Provide pps signal detection
 * @file pps.c
 * @brief pps driver
 * @}
 * @}
 */

#include "pps.h"
#include "pps_cfg.h"
#include "es_cdef.h"
#include "stm32h7xx_hal.h"
#include "stm32h7xx_hal_gpio.h"
#include "trace.h"
#include "sys_time.h"
#include "taskmon.h"
#include "taskmon_stat.h"
#include "cmsis_os2.h"
#include "AppTasks.h"
#include "datacache.h"
#include "timer.h"
#include <string.h>

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/** @brief pps detection flag signalling thread for datacache entry write */
#define PPS_FLAG ((uint32_t)0x00000008U)

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/
/** @brief internal pps driver status */
typedef enum pps_drv_status
{
    PPS_DRV_OK = 0U,    // driver is ok
    PPS_DRV_ERROR,      // some unknown error has occurred in the driver
    PPS_DRV_NOT_INIT,   // driver not initialized
    PPS_DRV_INIT,       // driver initialized
    PPS_DRV_TIM_ERROR,  // error with the timer used to calculate pps<->data offset
    PPS_DRV_GPIO_ERROR, // error with the gpio pin configuration
    PPS_DRV_TIMEOUT     // pps detection timeout
} pps_drv_status_t;

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
/**
 * @brief timer msp (mcu support package) initialization (required timer & gpio clock enable and configurations)
 * @param[in] TIM_HandleTypeDef *htim Timer handle
 */
static void pps_tim_msp_init(TIM_HandleTypeDef *htim);

/**
 * @brief timer msp (mcu support package) de-initialization
 * @param[in] TIM_HandleTypeDef *htim Timer handle
 */
static void pps_tim_msp_deinit(TIM_HandleTypeDef *htim);

/** @brief pps gpio pin configuration validation */
static bool pps_gpio_validate_cfg(void);

/**
 * @brief calculates the prescaler value for the timer, based on timer resolution & bus clock
 * @param[in] uint32_t timer_resolution desired timer resolution in Hz
 * @return calculated prescaler value
 */
static uint32_t pps_tim_calc_prescaler(uint32_t timer_resolution);

/** @brief starts the pps hardware timer */
static bool pps_tim_start(void);

/** @brief stops the pps hardware timer base generation */
static bool pps_tim_stop(void);

/** @brief restarts the pps hardware timer */
static void pps_tim_reset(void);

/** @brief writes pps telemetry to the data cache */
static void pps_tlm_entry(void);

/** @brief pps detection thread */
static void pps_thread(void *argument);
/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
/** @brief Timer handle to measure time [us] after pps signal detection */
static TIM_HandleTypeDef htim2 = {
    .Instance               = PPS_TIMER,
    .Init.Prescaler         = PPS_TIMER_PRESCALER,
    .Init.CounterMode       = TIM_COUNTERMODE_UP,
    .Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1,
    .Init.RepetitionCounter = PPS_TIMER_REPCOUNT,
    .Init.Period            = PPS_TIMER_PERIOD,
    .Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE,
    .Base_MspInitCallback   = &pps_tim_msp_init,
    .Base_MspDeInitCallback = &pps_tim_msp_deinit
};

/** @brief GPIO handle for pps signal */
static GPIO_InitTypeDef pps_gpio = {
    .Pin       = PPS_PIN,
    .Mode      = PPS_POLARITY,
    .Pull      = PPS_PP,
    .Speed     = PPS_GPIO_SPEED,
    .Alternate = PPS_ALTERNATE
};

/** @brief pps timer to track detection timeout */
static timer_handle_t pps_timeout_timer;

/** @brief pps thread handle */
static osThreadId_t pps_thread_h = NULL;

/** @brief internal pps driver telemetry storage */
static DATA_CACHE_PPS_Telemetry_t tlm_pps = {
    .u32Pps_detect_cnt        = 0U,                               // pps detection counter
    .u32Last_pps_uptime       = 0U,                               // last pps uptime value
    .u8Current_drv_status     = (uint8_t)PPS_DRV_NOT_INIT,        // current driver status
    .u8Latest_rtc_sync_status = (uint8_t)RTC_SYNC_NOT_YET_SYNCED, // latest rtc sync status
    .u32Rtc_sync_success_cnt  = 0U,                               // rtc sync success counter
    .u32Rtc_sync_fail_cnt     = 0U,                               // rtc sync fail counter
    .u32Pps_timeout_cnt       = 0U                                // pps timeout counter
};

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
void pps_init(void)
{
    uint32_t tim_prescaler = pps_tim_calc_prescaler(PPS_TIMER_RES);

    // check for prescaler underflow, due to low resolution
    if ((tim_prescaler > 0xFFFFU) || (tim_prescaler == 0xFFFFFFFFU))
    {
        tlm_pps.u8Current_drv_status = (uint8_t)PPS_DRV_TIM_ERROR;
        return; // return error for unachievable prescaler settings
    }

    htim2.Init.Prescaler         = tim_prescaler;
    tlm_pps.u8Current_drv_status = (uint8_t)PPS_DRV_INIT;

    if (HAL_OK != HAL_TIM_Base_Init(&htim2))
    {
        ES_TRACE_ERROR("[pps] failed tim init");
        tlm_pps.u8Current_drv_status = (uint8_t)PPS_DRV_TIM_ERROR;
    }

    // validate pps pin configuration
    if (true != pps_gpio_validate_cfg())
    {
        (void)pps_tim_stop();
        tlm_pps.u8Current_drv_status = (uint8_t)PPS_DRV_GPIO_ERROR;
    }

    // initialize pps thread for datacache telemetry writing
    osThreadAttr_t pps_thread_attr = {
        .name       = "pps_thread",
        .stack_size = 256U,
        .priority   = osPriorityNormal,
        .attr_bits  = osThreadDetached,
        .cb_mem     = NULL,
        .cb_size    = 0U,
        .stack_mem  = NULL,
        .tz_module  = 0U,
        .reserved   = 0U
    };

    if (NULL == pps_thread_h)
    {
        pps_thread_h = osThreadNew(pps_thread, NULL, &pps_thread_attr);
    }

    if (NULL == pps_thread_h)
    {
        ES_TRACE_ERROR("[pps] thread creation failed");
        tlm_pps.u8Current_drv_status = (uint8_t)PPS_DRV_ERROR;
    }
    else
    {
        task_mon_register_for_stats(TASK_ID_PPS, pps_thread_h);
    }
}

void pps_deinit(void)
{
    if (HAL_TIM_STATE_RESET != HAL_TIM_Base_GetState(&htim2))
    {
        bool success = (HAL_OK == HAL_TIM_Base_Stop(&htim2));
        success      = success && (HAL_OK == HAL_TIM_Base_DeInit(&htim2));

        if (false == success)
        {
            ES_TRACE_ERROR("[pps] failed tim deinit");
        }
    }

    task_mon_set_task_policy(TASK_ID_PPS, TASK_MON_POLICY_DONT_CARE);
    (void)pps_tim_stop();
    timer_stop(&pps_timeout_timer);
    (void)memset(&tlm_pps, 0U, sizeof(tlm_pps));
}

static bool pps_tim_start(void)
{
    bool res = false;

    if (tlm_pps.u8Current_drv_status != (uint8_t)PPS_DRV_TIM_ERROR)
    {
        if (HAL_OK != HAL_TIM_Base_Start(&htim2))
        {
            ES_TRACE_WARN("[pps] could not start timer");
            tlm_pps.u8Current_drv_status = (uint8_t)PPS_DRV_TIM_ERROR;
        }
        else
        {
            res = true;
        }
    }

    return res;
}

static bool pps_tim_stop(void)
{
    bool res = false;

    if (tlm_pps.u8Current_drv_status != (uint8_t)PPS_DRV_TIM_ERROR)
    {
        if ((HAL_TIM_STATE_RESET != HAL_TIM_Base_GetState(&htim2)) &&
            (HAL_OK != HAL_TIM_Base_Stop(&htim2)))
        {
            res = false;
            ES_TRACE_WARN("[pps] could not stop timer");
            tlm_pps.u8Current_drv_status = (uint8_t)PPS_DRV_TIM_ERROR;
        }
        else
        {
            __HAL_TIM_SET_COUNTER(&htim2, 0U);
            res = true;
        }
    }

    return res;
}

static void pps_tim_reset(void)
{
    if (true == pps_tim_stop())
    {
        if (true != pps_tim_start())
        {
            tlm_pps.u8Current_drv_status = (uint8_t)PPS_DRV_TIM_ERROR;
        }
        else
        {
            tlm_pps.u8Current_drv_status = (uint8_t)PPS_DRV_OK;
        }
    }
    else
    {
        tlm_pps.u8Current_drv_status = (uint8_t)PPS_DRV_TIM_ERROR;
    }
}

static void pps_tlm_entry(void)
{
    // get timer counter value
    if ((IS_TRUE(pps_timeout_timer.is_running)) &&
        (timer_is_elapsed(&pps_timeout_timer, PPS_DETECT_TIMEOUT_MS)))
    {
        tlm_pps.u32Pps_timeout_cnt++;
        tlm_pps.u8Current_drv_status = (uint8_t)PPS_DRV_TIMEOUT;
    }

    // stop pps timeout timer & update pps telemetry
    timer_stop(&pps_timeout_timer);
    tlm_pps.u32Pps_detect_cnt++;
    tlm_pps.u32Last_pps_uptime = get_uptime_seconds();

    dc_set_raw_data(DC_DATA_INPUT_INTERNAL,
                    DC_DID_PPS_TELEMETRY_DATA,
                    (void *)&tlm_pps,
                    sizeof(tlm_pps));

    // restart pps timeout timer
    timer_start(&pps_timeout_timer);
}

static bool pps_gpio_validate_cfg(void)
{
    const GPIO_TypeDef *const GPIOx     = PPS_PIN_PORT;
    uint32_t                  pinNumber = PPS_PIN_NUMBER;

    uint32_t const mode_config = (GPIOx->MODER >> (pinNumber * 2U)) & 0x03U; // read PPS pin mode configuration
    uint32_t const pull_config = (GPIOx->PUPDR >> (pinNumber * 2U)) & 0x03U; // read PPS pin pull configuration

    if (PPS_INPUT_MODE == mode_config)
    {
        switch (PPS_POLARITY)
        {
            case GPIO_MODE_IT_FALLING:
                if (PPS_PULLUP_CONFIG == pull_config)
                {
                    return true; // pin configured as IT_FALLING with PULLUP
                }
                break;

            case GPIO_MODE_IT_RISING:
                if (PPS_PULLDOWN_CONFIG == pull_config)
                {
                    return true; // pin configured as IT_RISING with PULLDOWN
                }

                break;

            default:
                break; // pin not configured as IT_FALLING or IT_RISING - this is wrong
        }
    }

    return false;
}

void pps_irq_handler(void)
{
    (void)pps_tim_reset();
    (void)osThreadFlagsSet(pps_thread_h, PPS_FLAG);
}

bool pps_get_offset(uint32_t *const p_offset_value)
{
    BREAK_ASSERT(NULL != p_offset_value);

    *p_offset_value = __HAL_TIM_GET_COUNTER(&htim2);

    bool res = true;

    // the timer counter value must be discarded if there is some error with stopping the timer
    // this is to avoid any large, potentially misleading positive offset values, obtained
    // after pps detection failure (we reset timer on detection)
    if (true != pps_tim_stop())
    {
        res = false;
    }

    return res;
}

void pps_set_rtc_sync_status(rtc_sync_status_t status)
{
    tlm_pps.u8Latest_rtc_sync_status = (uint8_t)status;
}

void pps_increment_sync_success(void)
{
    tlm_pps.u32Rtc_sync_success_cnt++;
}

void pps_increment_sync_fail(void)
{
    tlm_pps.u32Rtc_sync_fail_cnt++;
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
static uint32_t pps_tim_calc_prescaler(uint32_t timer_resolution)
{
    CRIT_ASSERT(timer_resolution > 0U);

    RCC_ClkInitTypeDef clk_config;
    uint32_t           timer_clock   = 0U;
    uint32_t           flash_latency = 0U;

    // get clock configuration
    HAL_RCC_GetClockConfig(&clk_config, &flash_latency);

    // get apb1 prescaler (divider)
    uint32_t apb1_clk_divider = clk_config.APB1CLKDivider;

    // select timer clock based on pclk (check Ratio between clock timer and pclk in STM32H7 rm0433 RM)
    if (apb1_clk_divider == RCC_HCLK_DIV1)
    {
        timer_clock = HAL_RCC_GetPCLK1Freq();
    }
    else
    {
        // timer clock is twice as fast as the bus clock, if timer prescaler is > 1 (rm0433 RM Ratio between clock timer and pclk)
        timer_clock = 2UL * HAL_RCC_GetPCLK1Freq();
    }

    // calculate prescaler (if timer_clock < timer_resolution underflow may occur, handle case ourside accordingly)
    return ((timer_clock / timer_resolution) - 1U);
}

static void pps_tim_msp_init(TIM_HandleTypeDef *htim)
{
    if ((PPS_TIMER == htim->Instance) && (htim == &htim2))
    {
        __HAL_RCC_GPIOF_CLK_ENABLE();
        __HAL_RCC_TIM2_CLK_ENABLE();

        HAL_GPIO_Init(PPS_PIN_PORT, &pps_gpio);                // initialize PPS pin
        if (HAL_OK != HAL_GPIO_LockPin(PPS_PIN_PORT, PPS_PIN)) // enable PPS pin configuration lock
        {
            ES_TRACE_WARN("[pps] pps pin configuration lock failed");
        }

        HAL_NVIC_SetPriority(PPS_IRQ, 5, 0);
        HAL_NVIC_EnableIRQ(PPS_IRQ);
    }
}

static void pps_tim_msp_deinit(TIM_HandleTypeDef *htim)
{
    if ((PPS_TIMER == htim->Instance) && (htim == &htim2))
    {
        __HAL_RCC_TIM2_CLK_DISABLE();
        HAL_GPIO_DeInit(PPS_PIN_PORT, PPS_PIN);
    }
}

static void pps_thread(void *argument)
{
    (void)argument;

    uint32_t flags;

    task_mon_task_initialized(TASK_ID_PPS);
    task_mon_set_task_policy(TASK_ID_PPS, TASK_MON_POLICY_DONT_CARE);

    for (;;)
    {
        task_mon_i_am_alive(TASK_ID_PPS);

        flags = osThreadFlagsWait(PPS_FLAG, osFlagsWaitAny, osWaitForever);

        if (PPS_FLAG == (flags & PPS_FLAG))
        {
            (void)pps_tlm_entry();
        }

        task_mon_low_stack_check(TASK_ID_PPS);
    }
}
