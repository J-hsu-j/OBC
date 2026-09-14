/*
 * Copyright (c) 2023-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup service_file_tools
 * @{
 *
 * @file sd_mng.c
 *
 * @brief Manages common SD card functionalities and do some service operations
 *
 * @}
 */

#include "taskmon.h"
#include "taskmon_stat.h"
#include "timer.h"
#include "trace.h"
#include "debug.h"
#include <stm32h7xx_hal_sd.h>
#include <string.h>
#include <assert.h>
#include "sd_mng.h"
#include "sd_hook.h"
#include "fm_common_def.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

#define RAM_D1_START (&_Ram_D1_Min_Address)
#define RAM_D1_LAST  (&_Ram_D1_Max_Address)

#define SECTION_D1 __attribute__((section(".bss")))

#define SD_INIT_TIMEOUT                  (2000)
#define SD_PERIPH_RESET_COUNTER          (10000000LU)
#define SD_IO_RETRY_TIMEOUT              (1000)
#define SD_LOCK_TIMEOUT                  (1000)
#define SD_BUSY_TIMEOUT                  (500)
#define SD_TASK_WAIT                     (2000)
#define SD_BLOCKING_REINIT_POLL_INTERVAL (10)
#define SD_CARD_DISCHARGE_DELAY          (150)
#define SD_CARD_POWERUP_DELAY            (10)
#define SD_TRANSFER_DELAY                (1)
#define AHB_PERIPH_RESET_DELAY           (1)

#define SD_TASK_STACK_SIZE        (1280)
#define SD_DEFAULT_BLOCK_SIZE     (512)
#define SD_QUEUE_SIZE             (10)
#define SD_QUEUE_MESSAGE_SIZE     (sizeof(sd_message_t))
#define SD_READ_CPLT_MSG          ((sd_message_t)1)
#define SD_WRITE_CPLT_MSG         ((sd_message_t)2)
#define SD_EVENT_FLAG_NOTIFY_TASK (0x04)
#define SD_READ_TIMEOUT           (200)
#define SD_WRITE_TIMEOUT          (200)
#define SD_IO_RETRIES             (3)

#define SD_PIN_STATE_FULL_CLEAR (0x00)
#define SD_PIN_STATE_FULL_SET   (0xFF)
#define SD_PIN_STATE_INIT       (0x55)
#define SD_PIN_STATE_TIMEOUT_MS (5)

#define SD_DETECT_COUNT         (30)
#define SD_DETECT_COUNT_ABSENT  (SD_DETECT_COUNT)
#define SD_DETECT_COUNT_PRESENT (SD_DETECT_COUNT)

#define EXTI15_10_IRQ_PRIORITY (5)
#define SDMMC1_IRQ_PRIORITY    (5)

#define SD_INIT_ZERO       (0)
#define SD_INIT_PERIPH     (0x01)
#define SD_INIT_CLOCK      (0x02)
#define SD_INIT_POWER_PINS (0x04)
#define SD_INIT_POWER      (0x08)
#define SD_INIT_PINS       (0x10)
#define SD_INIT_IRQ        (0x20)
#define SD_INIT_HSD        (0x40)
#define SD_INIT_HAL        (0x80)
#define SD_INIT_FULL       (SD_INIT_PERIPH | SD_INIT_CLOCK | SD_INIT_POWER_PINS | SD_INIT_POWER | SD_INIT_PINS | SD_INIT_IRQ | SD_INIT_HSD | SD_INIT_HAL)

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

typedef enum
{
    SD_CARD_STATUS_ERROR,
    SD_CARD_STATUS_EJECTED,
    SD_CARD_STATUS_NOT_INIT,
    SD_CARD_STATUS_INITIALIZING,
    SD_CARD_STATUS_BUSY,
    SD_CARD_STATUS_READY,
    SD_CARD_STATUS_COUNT
} sd_card_status_t;

typedef uint16_t sd_message_t;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/

// the following variables are defined in the STM32H753IITx_FLASH.ld / STM32H753IITx_FLASH_No_Bootloader.ld linker scripts
// their memory addresses represent the start and end of the D1 memory address range
// this info is needed for DMA read/write from/to the SDMMC hardware interface
// See RM0433#104@2.1 and RM0433#2407@55.5
extern const uint32_t _Ram_D1_Min_Address; // NOSONAR
extern const uint32_t _Ram_D1_Max_Address; // NOSONAR

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

static uint32_t ATOMIC_ALIGN         init_status              = SD_INIT_ZERO;
static sd_card_status_t ATOMIC_ALIGN card_state               = SD_CARD_STATUS_EJECTED;
static bool ATOMIC_ALIGN             irq_card_change_detected = true;
// See comment above `_Ram_D1_Min_Address` declaration
static uint8_t ATOMIC_ALIGN SECTION_D1 sector_buffer[SD_DEFAULT_BLOCK_SIZE];

static osMessageQueueId_t ATOMIC_ALIGN  sd_queue              = NULL;
static osThreadId_t ATOMIC_ALIGN        sd_task_handle        = NULL;
static osMutexId_t ATOMIC_ALIGN         sd_mutex              = NULL;
static osEventFlagsId_t ATOMIC_ALIGN    sd_event              = NULL;
static storage_status_change_callback_t sd_status_callback    = NULL;
static void                            *p_sd_status_user_data = NULL;

static const fm_storage_api_t default_driver;

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/

static inline sd_card_status_t    sd_convert_card_state(const HAL_SD_CardStateTypeDef state);
static inline fm_storage_status_t convert_sdcard_to_storage_status(const sd_card_status_t status);

static inline bool sd_lock(void);
static inline bool sd_unlock(void);

static void        sd_task(void *p_argument);
static inline void sd_task_notify_isr(void);
static inline void sd_task_notify(void);

static bool sd_filter_detection_pin(void);
static void sd_detect_card(void);

// some of the init funcs don't have a deinit complement; this is intentional
// because resetting some stuff requires more status checking and timeouts
// and has no practical use for us
static inline void             sd_init_periph(void);
static inline void             sd_init_clock(void);
static inline void             sd_deinit_clock(void);
static inline void             sd_init_power_pins(void);
static inline void             sd_init_power(void);
static inline void             sd_deinit_power(void);
static inline void             sd_init_pins(void);
static inline void             sd_deinit_pins(void);
static inline void             sd_init_irq(void);
static inline void             sd_deinit_irq(void);
static inline void             sd_init_hsd(void);
static inline void             sd_init_hal(void);
static inline void             sd_mcu_deinit(void);
static inline void             sd_mcu_init(void);
static inline sd_card_status_t sd_hal_init(void);
static inline sd_card_status_t sd_full_reinit(void);

static sd_card_status_t sd_wait_for_transfer(const uint32_t timeout);

static inline bool is_memory_inside_D1(const void *p_loc, const uint32_t size);
static inline bool is_memory_dma_aligned(const void *p_loc, const uint32_t size);

static fm_dresult_t sd_read_dma(void *p_buff, const uint32_t sector, const uint32_t count);
static fm_dresult_t sd_read_dma_with_sector_buffering(void *const p_buff, const uint32_t sector, const uint32_t count);
static fm_dresult_t sd_read(void *const p_buff, const uint32_t sector, const uint32_t count);
static fm_dresult_t sd_read_retry(void *const p_buff, const uint32_t sector, const uint32_t count);

static fm_dresult_t sd_write_dma(const void *const p_buff, const uint32_t sector, const uint32_t count);
static fm_dresult_t sd_write_dma_with_sector_buffering(const void *const p_buff, const uint32_t sector, const uint32_t count);
static fm_dresult_t sd_write(const void *const p_buff, const uint32_t sector, const uint32_t count);
static fm_dresult_t sd_write_retry(const void *const p_buff, const uint32_t sector, const uint32_t count);

static fm_dresult_t sd_ioctl(const uint8_t cmd, void *const p_value);
static void         sd_update_card_state(const sd_card_status_t status);

static sd_card_status_t sd_get_status(void);
static sd_card_status_t sd_reinit(const uint32_t timeout, const bool force);

static fm_storage_status_t sd_get_status_generic(void);
static fm_storage_status_t sd_reinit_generic(const uint32_t timeout);

static const fm_storage_api_t default_driver = {
    .storage_read   = &sd_read_retry,
    .storage_write  = &sd_write_retry,
    .storage_ioctl  = &sd_ioctl,
    .storage_init   = &sd_reinit_generic,
    .storage_status = &sd_get_status_generic
};

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

void sd_init(void)
{
    if (NULL != sd_task_handle)
    {
        ES_TRACE_ERROR("sd_init() called twice");
        return;
    }

    (void)sd_mcu_init();

    sd_queue = osMessageQueueNew(SD_QUEUE_SIZE, SD_QUEUE_MESSAGE_SIZE, NULL);
    ES_TRACE_DEBUG("osMessageQueueNew() -> [%p]", sd_queue);

    sd_event = osEventFlagsNew(NULL);
    ES_TRACE_DEBUG("osEventFlagsNew() -> [%p]", sd_event);

    osMutexAttr_t mutex_attr = {
        .name      = NULL,
        .attr_bits = osMutexRecursive | osMutexPrioInherit,
        .cb_mem    = NULL,
        .cb_size   = 0
    };
    sd_mutex = osMutexNew(&mutex_attr);
    ES_TRACE_DEBUG("osMutexNew() -> [%p]", sd_mutex);

    static osThreadAttr_t thread_attr   = { 0 };
    static const char    *p_thread_name = "sd_mng_task";
    thread_attr.name                    = p_thread_name;
    thread_attr.priority                = osPriorityNormal;
    thread_attr.stack_size              = SD_TASK_STACK_SIZE;

    sd_task_handle = osThreadNew(sd_task, NULL, &thread_attr);
    task_mon_register_for_stats(TASK_ID_SD_MANAGER, sd_task_handle);
    ES_TRACE_DEBUG("osThreadNew() -> [%p]", sd_task_handle);
}

void sd_card_presence_change_notify_isr(void)
{
    irq_card_change_detected = true;

    sd_task_notify_isr();
}

const fm_storage_api_t *sd_get_default_driver(void)
{
    return &default_driver;
}

void sd_set_status_change_callback(const storage_status_change_callback_t callback, void *const p_user_data)
{
    sd_status_callback    = callback;
    p_sd_status_user_data = p_user_data;
}

void HAL_SD_RxCpltCallback(SD_HandleTypeDef *p_hsd)
{
    if (p_hsd == &hsd1)
    {
        const sd_message_t msg = SD_READ_CPLT_MSG;
        (void)osMessageQueuePut(sd_queue, (const void *)&msg, 0, 0);
    }
}

void HAL_SD_TxCpltCallback(SD_HandleTypeDef *p_hsd)
{
    if (p_hsd == &hsd1)
    {
        const sd_message_t msg = SD_WRITE_CPLT_MSG;
        (void)osMessageQueuePut(sd_queue, (const void *)&msg, 0, 0);
    }
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

static const char *sd_str_card_status(sd_card_status_t status)
{
    switch (status)
    {
        case SD_CARD_STATUS_ERROR:
            return "SD_CARD_STATUS_ERROR";
        case SD_CARD_STATUS_EJECTED:
            return "SD_CARD_STATUS_EJECTED";
        case SD_CARD_STATUS_NOT_INIT:
            return "SD_CARD_STATUS_NOT_INIT";
        case SD_CARD_STATUS_INITIALIZING:
            return "SD_CARD_STATUS_INITIALIZING";
        case SD_CARD_STATUS_BUSY:
            return "SD_CARD_STATUS_BUSY";
        case SD_CARD_STATUS_READY:
            return "SD_CARD_STATUS_READY";
        default:
            return "SD_CARD_STATUS_UNKNOWN";
    }
}

static const char *sd_str_dresult(fm_dresult_t res)
{
    switch (res)
    {
        case FM_DRES_OK:
            return "FM_DRES_OK";
        case FM_DRES_ERROR:
            return "FM_DRES_ERROR";
        case FM_DRES_WRPRT:
            return "FM_DRES_WRPRT";
        case FM_DRES_NOTRDY:
            return "FM_DRES_NOTRDY";
        case FM_DRES_PARERR:
            return "FM_DRES_PARERR";
        default:
            return "FM_DRESULT_UNKNOWN";
    }
}

static const char *sd_str_ioctl(fm_ioctl_cmd_t cmd)
{
    switch (cmd)
    {
        case FM_IOCTL_CTRL_SYNC:
            return "FM_IOCTL_CTRL_SYNC";
        case FM_IOCTL_GET_SECTOR_COUNT:
            return "FM_IOCTL_GET_SECTOR_COUNT";
        case FM_IOCTL_GET_SECTOR_SIZE:
            return "FM_IOCTL_GET_SECTOR_SIZE";
        case FM_IOCTL_GET_BLOCK_SIZE:
            return "FM_IOCTL_GET_BLOCK_SIZE";
        case FM_IOCTL_CTRL_TRIM:
            return "FM_IOCTL_CTRL_TRIM";
        case FM_IOCTL_INIT:
            return "FM_IOCTL_INIT";
        case FM_IOCTL_STATUS:
            return "FM_IOCTL_STATUS";
        default:
            return "FM_IOCTL_UNKNOWN";
    }
}

static inline fm_storage_status_t convert_sdcard_to_storage_status(const sd_card_status_t status)
{
    // Currently fm_storage_status_t and sd_card_status_t are the same
    // The static asserts are here to warn future devs to adjust code in case of divergence
    static_assert((sd_card_status_t)STORAGE_STATUS_ERROR == SD_CARD_STATUS_ERROR, "Changes between fm_storage_status_t and sd_card_status_t must be adjusted");
    static_assert((sd_card_status_t)STORAGE_STATUS_EJECTED == SD_CARD_STATUS_EJECTED, "Changes between fm_storage_status_t and sd_card_status_t must be adjusted");
    static_assert((sd_card_status_t)STORAGE_STATUS_NOT_INIT == SD_CARD_STATUS_NOT_INIT, "Changes between fm_storage_status_t and sd_card_status_t must be adjusted");
    static_assert((sd_card_status_t)STORAGE_STATUS_INITIALIZING == SD_CARD_STATUS_INITIALIZING, "Changes between fm_storage_status_t and sd_card_status_t must be adjusted");
    static_assert((sd_card_status_t)STORAGE_STATUS_BUSY == SD_CARD_STATUS_BUSY, "Changes between fm_storage_status_t and sd_card_status_t must be adjusted");
    static_assert((sd_card_status_t)STORAGE_STATUS_READY == SD_CARD_STATUS_READY, "Changes between fm_storage_status_t and sd_card_status_t must be adjusted");
    static_assert((sd_card_status_t)STORAGE_STATUS_COUNT == SD_CARD_STATUS_COUNT, "Changes between fm_storage_status_t and sd_card_status_t must be adjusted");
    return (fm_storage_status_t)status;
}

static inline sd_card_status_t sd_convert_card_state(const HAL_SD_CardStateTypeDef state)
{
    sd_card_status_t status;

    switch (state)
    {
        // The TRANSFER state is the one that means "ready for data transfer" which is what we want
        // The READY state means the card is still in identification mode
        // See section 4. from SD Specifications Part 1 Physical Layer Simplified Specification Version 9.10 December 1, 2023
        // The standard can be downloaded from https://www.sdcard.org/downloads/pls/ (It should be the first item in the table)
        case HAL_SD_CARD_TRANSFER:
            status = SD_CARD_STATUS_READY;
            break;
        case HAL_SD_CARD_READY:
        case HAL_SD_CARD_IDENTIFICATION:
        case HAL_SD_CARD_STANDBY:
        case HAL_SD_CARD_SENDING:
        case HAL_SD_CARD_RECEIVING:
        case HAL_SD_CARD_PROGRAMMING:
        case HAL_SD_CARD_DISCONNECTED:
            status = SD_CARD_STATUS_BUSY;
            break;
        default:
            status = SD_CARD_STATUS_ERROR;
            break;
    }

    return status;
}

static inline bool sd_lock(void)
{
    return (osOK == osMutexAcquire(sd_mutex, SD_LOCK_TIMEOUT));
}

static inline bool sd_unlock(void)
{
    return (osOK == osMutexRelease(sd_mutex));
}

static void sd_task(void *p_argument)
{
    UNUSED(p_argument);
    task_mon_task_initialized(TASK_ID_SD_MANAGER);
    task_mon_set_task_policy(TASK_ID_SD_MANAGER, TASK_MON_POLICY_MONITOR);
    ES_TRACE_INFO("<%p> sd_task() started", osThreadGetId());

    for (;;)
    {
        sd_detect_card();

        if (SD_CARD_STATUS_NOT_INIT == card_state)
        {
            (void)osMessageQueueReset(sd_queue);
            ES_TRACE_DEBUG("SD Card initializing");
            (void)sd_full_reinit();
            ES_TRACE_DEBUG("SD Card initialization done");
        }

        (void)osEventFlagsWait(sd_event, SD_EVENT_FLAG_NOTIFY_TASK, osFlagsWaitAny, SD_TASK_WAIT);

        task_mon_i_am_alive(TASK_ID_SD_MANAGER);
        task_mon_low_stack_check(TASK_ID_SD_MANAGER);
    }
}

static inline void sd_task_notify_isr(void)
{
    // sd_event is initialized in sd_init() before any potential code that may call sd_task_notify()
    // so we don't special mutex guards here
    if (NULL != sd_event)
    {
        (void)osEventFlagsSet(sd_event, SD_EVENT_FLAG_NOTIFY_TASK);
    }
}

static inline void sd_task_notify(void)
{
    // sd_event is initialized in sd_init() before any potential code that may call sd_task_notify()
    // so we don't special mutex guards here
    if (NULL != sd_event)
    {
        (void)osEventFlagsSet(sd_event, SD_EVENT_FLAG_NOTIFY_TASK);
        (void)osThreadYield();
    }
}

static bool sd_filter_detection_pin(void)
{
    uint8_t present = SD_DETECT_COUNT_PRESENT;
    uint8_t absent  = SD_DETECT_COUNT_ABSENT;
    bool    ret     = false;

    if (READ_BIT(init_status, SD_INIT_POWER_PINS))
    {
        do
        {
            if (GPIO_PIN_RESET == HAL_GPIO_ReadPin(SD_GPIO_DETECT, SD_PIN_DETECT))
            {
                absent--;
                present = SD_DETECT_COUNT_PRESENT;
            }
            else
            {
                present--;
                absent = SD_DETECT_COUNT_ABSENT;
            }
            (void)osDelay(SD_PIN_STATE_TIMEOUT_MS);
        } while ((0 != absent) && (0 != present));
        ret = (0 == present);
    }

    return ret;
}

static void sd_detect_card(void)
{
    if ((true == irq_card_change_detected) || (SD_CARD_STATUS_ERROR == card_state) || (SD_CARD_STATUS_EJECTED == card_state))
    {
        irq_card_change_detected = false;

        if (true == sd_filter_detection_pin())
        {
            if (card_state != SD_CARD_STATUS_NOT_INIT)
            {
                sd_update_card_state(SD_CARD_STATUS_NOT_INIT);
                ES_TRACE_DEBUG("Card DETECTED!");
            }
        }
        else
        {
            if (card_state != SD_CARD_STATUS_EJECTED)
            {
                sd_update_card_state(SD_CARD_STATUS_EJECTED);
                ES_TRACE_DEBUG("Card EJECTED!");
            }
        }
    }
}

static inline void sd_init_periph(void)
{
    // This function may be called before RTOS kernel is started, so we can't use timer libs
    uint32_t timer = 0;
    __HAL_RCC_SDMMC1_FORCE_RESET();
    while ((RCC->AHB3RSTR & RCC_AHB3RSTR_SDMMC1RST) != RCC_AHB3RSTR_SDMMC1RST)
    {
        ++timer;
        if (timer > SD_PERIPH_RESET_COUNTER)
        {
            return;
        }
    }
    (void)osDelay(AHB_PERIPH_RESET_DELAY);
    timer = 0;
    __HAL_RCC_SDMMC1_RELEASE_RESET();
    while ((RCC->AHB3RSTR & RCC_AHB3RSTR_SDMMC1RST) == RCC_AHB3RSTR_SDMMC1RST)
    {
        ++timer;
        if (timer > SD_PERIPH_RESET_COUNTER)
        {
            return;
        }
    }
    SET_BIT(init_status, SD_INIT_PERIPH);
}

static inline void sd_init_clock(void)
{
    RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = { 0 };
    PeriphClkInitStruct.PeriphClockSelection     = RCC_PERIPHCLK_SDMMC;
    PeriphClkInitStruct.SdmmcClockSelection      = RCC_SDMMCCLKSOURCE_PLL;
    HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct);
    __HAL_RCC_SDMMC1_CLK_ENABLE();

    SET_BIT(init_status, SD_INIT_CLOCK);
}

static inline void sd_deinit_clock(void)
{
    __HAL_RCC_SDMMC1_CLK_DISABLE();
    CLEAR_BIT(init_status, SD_INIT_CLOCK);
}

static inline void sd_init_power_pins(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    __HAL_RCC_GPIOD_CLK_ENABLE();
    GPIO_InitStruct.Pin   = SD_PIN_POWER;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(SD_GPIO_POWER, &GPIO_InitStruct);

    __HAL_RCC_GPIOG_CLK_ENABLE();
    GPIO_InitStruct.Pin  = SD_PIN_DETECT;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(SD_GPIO_DETECT, &GPIO_InitStruct);

    SET_BIT(init_status, SD_INIT_POWER_PINS);
}

static inline void sd_init_power(void)
{
    HAL_GPIO_WritePin(SD_GPIO_POWER, SD_PIN_POWER, GPIO_PIN_RESET);
    SET_BIT(init_status, SD_INIT_POWER);
}

static inline void sd_deinit_power(void)
{
    HAL_GPIO_WritePin(SD_GPIO_POWER, SD_PIN_POWER, GPIO_PIN_SET);
    CLEAR_BIT(init_status, SD_INIT_POWER);
}

static inline void sd_init_pins(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();

    GPIO_InitStruct.Pin       = SD_PIN_D0 | SD_PIN_D1 | SD_PIN_D2 | SD_PIN_D3 | SD_PIN_CLK;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF12_SDIO1;
    HAL_GPIO_Init(SD_GPIO_DATA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin       = SD_PIN_CMD;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF12_SDIO1;
    HAL_GPIO_Init(SD_GPIO_CMD, &GPIO_InitStruct);

    SET_BIT(init_status, SD_INIT_PINS);
}

static inline void sd_deinit_pins(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    GPIO_InitStruct.Pin  = SD_PIN_D0 | SD_PIN_D1 | SD_PIN_D2 | SD_PIN_D3 | SD_PIN_CLK;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(SD_GPIO_DATA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin  = SD_PIN_CMD;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(SD_GPIO_CMD, &GPIO_InitStruct);

    CLEAR_BIT(init_status, SD_INIT_PINS);
}

static inline void sd_init_irq(void)
{
    HAL_NVIC_SetPriority(EXTI15_10_IRQn, EXTI15_10_IRQ_PRIORITY, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
    HAL_NVIC_SetPriority(SDMMC1_IRQn, SDMMC1_IRQ_PRIORITY, 0);
    HAL_NVIC_EnableIRQ(SDMMC1_IRQn);

    SET_BIT(init_status, SD_INIT_IRQ);
}

static inline void sd_deinit_irq(void)
{
    HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);
    HAL_NVIC_DisableIRQ(SDMMC1_IRQn);

    CLEAR_BIT(init_status, SD_INIT_IRQ);
}

static inline void sd_init_hsd(void)
{
    (void)memset(&hsd1, 0, sizeof(hsd1));

    hsd1.Instance                 = SDMMC1;
    hsd1.Init.ClockEdge           = SDMMC_CLOCK_EDGE_RISING;
    hsd1.Init.ClockPowerSave      = SDMMC_CLOCK_POWER_SAVE_DISABLE;
    hsd1.Init.BusWide             = SDMMC_BUS_WIDE_4B;
    hsd1.Init.HardwareFlowControl = SDMMC_HARDWARE_FLOW_CONTROL_DISABLE;
    hsd1.Init.ClockDiv            = 0;

    SET_BIT(init_status, SD_INIT_HSD);
}

static inline void sd_init_hal(void)
{
    if (READ_BIT(init_status, SD_INIT_HSD) && (HAL_OK == HAL_SD_Init(&hsd1)) && (HAL_OK == HAL_SD_ConfigWideBusOperation(&hsd1, SDMMC_BUS_WIDE_4B)))
    {
        SET_BIT(init_status, SD_INIT_HAL);
    }
}

static inline void sd_mcu_deinit(void)
{
    sd_deinit_power();
    sd_deinit_clock();
    sd_deinit_irq();
    sd_deinit_pins();
    (void)osDelay(SD_CARD_DISCHARGE_DELAY);
}

static inline void sd_mcu_init(void)
{
    sd_init_periph();
    sd_init_clock();
    sd_init_power_pins();
    sd_init_power();
    sd_init_pins();
    sd_init_irq();
    (void)osDelay(SD_CARD_POWERUP_DELAY);
}

static inline sd_card_status_t sd_hal_init(void)
{
    sd_init_hsd();
    sd_init_hal();

    if (SD_INIT_FULL == init_status)
    {
        sd_update_card_state(SD_CARD_STATUS_BUSY);
        (void)sd_get_status();
    }
    else
    {
        sd_update_card_state(SD_CARD_STATUS_ERROR);
    }
    return card_state;
}

static inline sd_card_status_t sd_full_reinit(void)
{
    sd_update_card_state(SD_CARD_STATUS_INITIALIZING);
    sd_mcu_deinit();
    sd_mcu_init();
    return sd_hal_init();
}

static sd_card_status_t sd_wait_for_transfer(const uint32_t timeout)
{
    sd_card_status_t status;
    status = card_state;

    if ((SD_CARD_STATUS_READY == status) || (SD_CARD_STATUS_BUSY == status))
    {
        HAL_SD_CardStateTypeDef state;
        state = HAL_SD_GetCardState(&hsd1);

        if ((HAL_SD_CARD_TRANSFER != state) && (0 != timeout))
        {
            timer_handle_t th;
            timer_start(&th);
            do
            {
                (void)osDelay(SD_TRANSFER_DELAY);
                state = HAL_SD_GetCardState(&hsd1);
            } while ((false == timer_is_elapsed(&th, timeout)) && (HAL_SD_CARD_TRANSFER != state) && ((SD_CARD_STATUS_READY == card_state) || (SD_CARD_STATUS_BUSY == card_state)));
        }
        status = sd_convert_card_state(state);
    }
    return status;
}

static inline bool is_memory_inside_D1(const void *const p_loc, const uint32_t size)
{
    return ((((uint32_t)p_loc) >= (uint32_t)RAM_D1_START) && (((uint32_t)p_loc) + size - sizeof(uint8_t) <= (uint32_t)(RAM_D1_LAST)));
}

static inline bool is_memory_dma_aligned(const void *const p_loc, const uint32_t size)
{
    return ((0 == (((size_t)p_loc) & 0x3)) && (0 == (size & 0x4)) && (true == is_memory_inside_D1(p_loc, size)));
}

static fm_dresult_t sd_read_dma(void *const p_out_buff, const uint32_t sector, const uint32_t count)
{
    fm_dresult_t ret = FM_DRES_ERROR;
    sd_message_t msg;
    osStatus_t   msg_status;

    if (HAL_OK == HAL_SD_ReadBlocks_DMA(&hsd1, (uint8_t *)p_out_buff, sector, count))
    {
        do
        {
            msg_status = osMessageQueueGet(sd_queue, (void *)&msg, NULL, SD_READ_TIMEOUT);
            if ((msg_status == osOK) && (msg == SD_READ_CPLT_MSG))
            {
                ret = FM_DRES_OK;
                break;
            }
        } while (osOK == msg_status);
    }

    return ret;
}

static fm_dresult_t sd_read_dma_with_sector_buffering(void *const p_out_buff, const uint32_t sector, const uint32_t count)
{
    fm_dresult_t ret            = FM_DRES_ERROR;
    uint32_t     current_sector = sector;
    uint8_t     *p_read_loc     = (uint8_t *)p_out_buff;
    for (uint32_t i = 0; i < count; i++)
    {
        ret = sd_read_dma(sector_buffer, current_sector, 1);
        if (FM_DRES_OK != ret)
        {
            break;
        }
        memcpy(p_read_loc, sector_buffer, sizeof(sector_buffer));
        p_read_loc += sizeof(sector_buffer);
        current_sector++;
    }
    return ret;
}

static fm_dresult_t sd_read(void *const p_out_buff, const uint32_t sector, const uint32_t count)
{
    fm_dresult_t ret = FM_DRES_ERROR;

    if (NULL == p_out_buff)
    {
        ES_TRACE_DEBUG("Error on sd card read NULL input buffer");
        return FM_DRES_PARERR;
    }

    if (false == sd_lock())
    {
        ES_TRACE_DEBUG("Error on sd card read, could not lock sd mutex");
        return FM_DRES_NOTRDY;
    }

    sd_card_status_t status;
    status = sd_wait_for_transfer(SD_BUSY_TIMEOUT);
    if (SD_CARD_STATUS_READY == status)
    {
        if (0 == count)
        {
            ret = FM_DRES_OK;
        }
        else if (true == is_memory_dma_aligned(p_out_buff, count * SD_DEFAULT_BLOCK_SIZE))
        {
            ret = sd_read_dma(p_out_buff, sector, count);
        }
        else
        {
            ret = sd_read_dma_with_sector_buffering(p_out_buff, sector, count);
        }
    }
    else
    {
        ES_TRACE_DEBUG("Error on sd card read, wait for transfer timeout, error %d '%s'", status, sd_str_card_status(status));
        ret = FM_DRES_NOTRDY;
    }

    (void)sd_unlock();

    return ret;
}

static fm_dresult_t sd_read_retry(void *const p_out_buff, const uint32_t sector, const uint32_t count)
{
    fm_dresult_t     ret        = FM_DRES_ERROR;
    uint8_t          tries_left = SD_IO_RETRIES;
    sd_card_status_t status     = card_state;
    uint32_t         currentCID[sizeof(((SD_HandleTypeDef *)0)->CID)];

    memcpy(currentCID, hsd1.CID, sizeof(hsd1.CID));

    do
    {
        if ((SD_CARD_STATUS_READY == status) || (SD_CARD_STATUS_BUSY == card_state))
        {
            ret = sd_read(p_out_buff, sector, count);
        }
        if ((FM_DRES_OK != ret) && (SD_CARD_STATUS_READY != card_state) && (SD_CARD_STATUS_BUSY != card_state))
        {
            status = sd_reinit(SD_IO_RETRY_TIMEOUT, false);

            // if card is initialized, check if the same card we started with just in case
            if (((SD_CARD_STATUS_READY == status) || (SD_CARD_STATUS_BUSY == card_state)) && (0 != memcmp(currentCID, hsd1.CID, sizeof(hsd1.CID))))
            {
                ret = FM_DRES_ERROR;
                break;
            }
        }
        // if error was not caused by card, then simply try again
        --tries_left;
    } while ((0 < tries_left) && (FM_DRES_OK != ret));

    return ret;
}

static fm_dresult_t sd_write_dma(const void *const p_in_buff, const uint32_t sector, const uint32_t count)
{
    fm_dresult_t ret = FM_DRES_ERROR;
    sd_message_t msg;
    osStatus_t   msg_status;

    if (HAL_OK == HAL_SD_WriteBlocks_DMA(&hsd1, (uint8_t *)p_in_buff, sector, count))
    {
        do
        {
            msg_status = osMessageQueueGet(sd_queue, (void *)&msg, NULL, SD_WRITE_TIMEOUT);
            if ((msg_status == osOK) && (msg == SD_WRITE_CPLT_MSG))
            {
                ret = FM_DRES_OK;
                break;
            }
        } while (osOK == msg_status);
    }
    return ret;
}

static fm_dresult_t sd_write_dma_with_sector_buffering(const void *const p_in_buff, const uint32_t sector, const uint32_t count)
{
    fm_dresult_t   ret            = FM_DRES_ERROR;
    uint32_t       current_sector = sector;
    const uint8_t *p_write_loc    = (const uint8_t *)p_in_buff;
    for (uint32_t i = 0; i < count; i++)
    {
        memcpy(sector_buffer, p_write_loc, sizeof(sector_buffer));
        ret = sd_write_dma(sector_buffer, current_sector, 1);
        if (FM_DRES_OK != ret)
        {
            break;
        }
        p_write_loc += sizeof(sector_buffer);
        current_sector++;
    }
    return ret;
}

static fm_dresult_t sd_write(const void *const p_in_buff, const uint32_t sector, const uint32_t count)
{
    fm_dresult_t ret = FM_DRES_ERROR;

    if (NULL == p_in_buff)
    {
        ES_TRACE_DEBUG("Error on sd card write NULL input buffer");
        return FM_DRES_PARERR;
    }

    if (false == sd_lock())
    {
        ES_TRACE_DEBUG("Error on sd card write, could not lock sd mutex");
        return FM_DRES_NOTRDY;
    }

    sd_card_status_t status;
    status = sd_wait_for_transfer(SD_BUSY_TIMEOUT);
    if (SD_CARD_STATUS_READY == status)
    {
        if (0 == count)
        {
            ret = FM_DRES_OK;
        }
        else if (true == is_memory_dma_aligned(p_in_buff, count * SD_DEFAULT_BLOCK_SIZE))
        {
            ret = sd_write_dma(p_in_buff, sector, count);
        }
        else
        {
            ret = sd_write_dma_with_sector_buffering(p_in_buff, sector, count);
        }
    }
    else
    {
        ES_TRACE_DEBUG("Error on sd card write, wait for transfer timeout, error %d '%s'", status, sd_str_card_status(status));
        ret = FM_DRES_NOTRDY;
    }

    (void)sd_unlock();

    return ret;
}

static fm_dresult_t sd_write_retry(const void *const p_in_buff, const uint32_t sector, const uint32_t count)
{
    fm_dresult_t     ret        = FM_DRES_ERROR;
    uint8_t          tries_left = SD_IO_RETRIES;
    sd_card_status_t status     = card_state;
    uint32_t         currentCID[sizeof(((SD_HandleTypeDef *)0)->CID)];

    (void)memcpy(currentCID, hsd1.CID, sizeof(hsd1.CID));

    do
    {
        if ((SD_CARD_STATUS_READY == status) || (SD_CARD_STATUS_BUSY == card_state))
        {
            ret = sd_write(p_in_buff, sector, count);
        }
        if ((FM_DRES_OK != ret) && (SD_CARD_STATUS_READY != card_state) && (SD_CARD_STATUS_BUSY != card_state))
        {
            // if error was caused by SD card error, signal sd_task() to fix it
            status = sd_reinit(SD_IO_RETRY_TIMEOUT, false);

            // check if the same card we started with, just in case
            if ((SD_CARD_STATUS_READY == status) && (0 != memcmp(currentCID, hsd1.CID, sizeof(hsd1.CID))))
            {
                ret = FM_DRES_ERROR;
                break;
            }
        }
        // if error was not caused by card, then simply try again
        --tries_left;
    } while ((0 < tries_left) && (FM_DRES_OK != ret));

    return ret;
}

static fm_dresult_t sd_ioctl(const uint8_t cmd, void *const p_value)
{
    fm_dresult_t     ret = FM_DRES_ERROR;
    sd_card_status_t status;

    if (false == sd_lock())
    {
        ES_TRACE_DEBUG("Error on sd card ioctl, could not lock sd mutex");
        return FM_DRES_NOTRDY;
    }

    if (((FM_IOCTL_INIT == cmd) && (NULL != p_value)) || ((SD_INIT_FULL == init_status) && ((NULL != p_value) || (FM_IOCTL_CTRL_SYNC == cmd))))
    {
        switch (cmd)
        {
            case FM_IOCTL_CTRL_SYNC:
                if (SD_CARD_STATUS_READY == sd_wait_for_transfer(SD_INIT_TIMEOUT))
                {
                    ret = FM_DRES_OK;
                }
                break;

            case FM_IOCTL_GET_SECTOR_COUNT:
                if ((SD_CARD_STATUS_READY == card_state) || (SD_CARD_STATUS_BUSY == card_state))
                {
                    *(uint32_t *)p_value = hsd1.SdCard.LogBlockNbr;
                    ret                  = FM_DRES_OK;
                }
                break;

            case FM_IOCTL_GET_SECTOR_SIZE:
                if ((SD_CARD_STATUS_READY == card_state) || (SD_CARD_STATUS_BUSY == card_state))
                {
                    *(uint32_t *)p_value = hsd1.SdCard.LogBlockSize;
                    ret                  = FM_DRES_OK;
                }
                break;

            case FM_IOCTL_GET_BLOCK_SIZE:
                if ((SD_CARD_STATUS_READY == card_state) || (SD_CARD_STATUS_BUSY == card_state))
                {
                    *(uint32_t *)p_value = hsd1.SdCard.LogBlockSize / SD_DEFAULT_BLOCK_SIZE;
                    ret                  = FM_DRES_OK;
                }
                break;

            case FM_IOCTL_INIT:
                status = card_state;
                if (SD_CARD_STATUS_BUSY == status)
                {
                    (void)sd_wait_for_transfer(SD_INIT_TIMEOUT);
                }
                else if (SD_CARD_STATUS_READY != status)
                {
                    (void)sd_reinit(SD_INIT_TIMEOUT, false);
                }
                else
                {
                    // Avoid SonarQube warning
                }
                __attribute__((fallthrough));

            case FM_IOCTL_STATUS:
                status = card_state;
                switch (status)
                {
                    case SD_CARD_STATUS_NOT_INIT:
                    case SD_CARD_STATUS_INITIALIZING:
                        *(fm_dstatus_t *)p_value = FM_DSTA_NOINIT;
                        ret                      = FM_DRES_NOTRDY;
                        break;
                    case SD_CARD_STATUS_BUSY:
                    case SD_CARD_STATUS_READY:
                        *(fm_dstatus_t *)p_value = 0; // there is no FM_DSTA_OK, but 0 is interpreted as OK in ff.c
                        ret                      = FM_DRES_OK;
                        break;
                    default:
                        *(fm_dstatus_t *)p_value = FM_DSTA_NODISK;
                        ret                      = FM_DRES_ERROR;
                        break;
                }
                break;

            default:
                ret = FM_DRES_PARERR;
        }
    }

    (void)sd_unlock();

    if (ret != FM_DRES_OK)
    {
        ES_TRACE_DEBUG("Error on sd card ioctl %d '%s', dresult %d '%s'", cmd, sd_str_ioctl(cmd), ret, sd_str_dresult(ret));
    }

    return ret;
}

static void sd_update_card_state(const sd_card_status_t status)
{
    static sd_card_status_t prev_card_status = SD_CARD_STATUS_EJECTED;
    card_state                               = status;
    if ((NULL != sd_status_callback) && (prev_card_status != status))
    {
        prev_card_status = status;
        sd_status_callback(convert_sdcard_to_storage_status(status), p_sd_status_user_data);
    }
}

static sd_card_status_t sd_get_status(void)
{
    sd_card_status_t ret;

    if (false == sd_lock())
    {
        if (SD_CARD_STATUS_READY == card_state)
        {
            return SD_CARD_STATUS_BUSY;
        }
        return card_state;
    }

    ret = card_state;

    if ((SD_CARD_STATUS_READY == ret) || (SD_CARD_STATUS_BUSY == ret))
    {
        ret = sd_convert_card_state(HAL_SD_GetCardState(&hsd1));
        if (HAL_SD_ERROR_NONE != hsd1.ErrorCode)
        {
            ret = SD_CARD_STATUS_ERROR;
        }
        sd_update_card_state(ret);
    }

    (void)sd_unlock();
    return ret;
}

static sd_card_status_t sd_reinit(const uint32_t timeout, const bool force)
{
    sd_card_status_t status;

    if ((true == force) || (SD_CARD_STATUS_INITIALIZING != card_state))
    {
        sd_update_card_state(SD_CARD_STATUS_NOT_INIT);
        sd_task_notify();
    }

    status = card_state;

    if (0 != timeout)
    {
        timer_handle_t th;
        timer_start(&th);

        while ((false == timer_is_elapsed(&th, timeout)) && (SD_CARD_STATUS_READY != status))
        {
            (void)osDelay(SD_BLOCKING_REINIT_POLL_INTERVAL);
            status = card_state;
        }
    }

    return status;
}

static fm_storage_status_t sd_get_status_generic(void)
{
    return (fm_storage_status_t)sd_get_status();
}

static fm_storage_status_t sd_reinit_generic(const uint32_t timeout)
{
    return (fm_storage_status_t)sd_reinit(timeout, true);
}
