/**
 * Copyright (c) 2020-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup Drivers
 * @{
 * @defgroup gnss
 * @{
 * @file gnss_uart.c
 * @}
 * @}
 */

#include "gnss_uart.h"
#include "gnss_irq.h"
#include "gnss_cfg.h"
#include "stm32h7xx_hal.h"
#include "stm32h7xx_hal_uart.h"
#include "stm32h7xx_hal_dma.h"
#include "FP_gnssProtocolTypes.h"
#include "nvm.h"
#include "cmsis_os2.h"
#include "assertions.h"
#include <string.h>

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
/** @brief RX queue length */
#define RX_Q_SZ (5U)

/** @brief gnss uart peripheral HAL initialization status mask */
#define UART_STATE_INIT_MASK (0x20U)

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
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/

/**
 * @brief initializes the UART MSP
 * @param[in] p_huart pointer to gnss UART handle
 */
static void msp_init_callback(UART_HandleTypeDef *p_huart);

/**
 * @brief deinitializes the UART MSP
 * @param[in] p_huart pointer to gnss UART handle
 */
static void msp_deinit_callback(UART_HandleTypeDef *p_huart);

/**
 * @brief reception event callback
 * @param[in] p_huart pointer to gnss UART handle
 * @param[in] size  number of data available in application reception buffer
 */
static void rx_event_callback(UART_HandleTypeDef *p_huart, uint16_t size);

/**
 * @brief re-initialize the UART peripheral with a new baudrate
 * @retval true if baudrate mapping succeeded
 * @retval false if baudrate mapping failed
 */
static bool gnss_uart_reset_with_new_baudrate(void);

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
/** @brief UART current baudrate value. The GNSS UART peripheral has successfully initialized with this baudrate */
static GNSS_BaudRate_t gnss_handle_current_baudrate;

/** @brief UART handle */
static UART_HandleTypeDef gnss_uart_handle = {
    .Instance                         = UART5,
    .Init.WordLength                  = UART_WORDLENGTH_8B,
    .Init.StopBits                    = UART_STOPBITS_1,
    .Init.Parity                      = UART_PARITY_NONE,
    .Init.Mode                        = UART_MODE_TX_RX,
    .Init.HwFlowCtl                   = UART_HWCONTROL_NONE,
    .Init.OverSampling                = UART_OVERSAMPLING_16,
    .Init.OneBitSampling              = UART_ONE_BIT_SAMPLE_DISABLE,
    .Init.ClockPrescaler              = UART_PRESCALER_DIV1,
    .AdvancedInit.AdvFeatureInit      = UART_ADVFEATURE_RXOVERRUNDISABLE_INIT | UART_ADVFEATURE_DMADISABLEONERROR_INIT,
    .AdvancedInit.OverrunDisable      = UART_ADVFEATURE_OVERRUN_DISABLE,
    .AdvancedInit.DMADisableonRxError = UART_ADVFEATURE_DMA_DISABLEONRXERROR,
    .MspInitCallback                  = msp_init_callback,
    .MspDeInitCallback                = msp_deinit_callback
};

/** @brief DMA handle */
static DMA_HandleTypeDef hdma_uart_rx = {
    .Instance                 = DMA2_Stream1,
    .Init.Request             = DMA_REQUEST_UART5_RX,
    .Init.Direction           = DMA_PERIPH_TO_MEMORY,
    .Init.PeriphInc           = DMA_PINC_DISABLE,
    .Init.MemInc              = DMA_MINC_ENABLE,
    .Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE,
    .Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE,
    .Init.Mode                = DMA_NORMAL,
    .Init.Priority            = DMA_PRIORITY_LOW,
    .Init.FIFOMode            = DMA_FIFOMODE_DISABLE
};

/** @brief UART RX queue used to store receive messages */
static osMessageQueueId_t rx_q = NULL;

/** @brief UART RX buffer to be filled by DMA */
static volatile gnss_uart_resp_t rx_msg;

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
bool gnss_uart_init(void)
{
    if (NULL == rx_q)
    {
        rx_q = osMessageQueueNew(RX_Q_SZ, sizeof(gnss_uart_resp_t), NULL);

        if (NULL == rx_q)
        {
            return false;
        }
    }

    __HAL_RCC_DMA2_CLK_ENABLE();

    // get baudrate from nvm
    GNSS_BaudRate_t baudrate_nvm;
    Nvm_GetBlockById(NVM_BLOCK_GNSS_COMM_SETTINGS, &baudrate_nvm);
    gnss_uart_handle.Init.BaudRate = gnss_uart_baudrate_map(baudrate_nvm);
    gnss_handle_current_baudrate   = baudrate_nvm;

    if ((HAL_OK != HAL_UART_Init(&gnss_uart_handle)) ||
        (HAL_OK != HAL_DMA_Init(&hdma_uart_rx)))
    {
        return false;
    }

    __HAL_LINKDMA(&gnss_uart_handle, hdmarx, hdma_uart_rx);
    __HAL_DMA_DISABLE_IT(&hdma_uart_rx, DMA_IT_HT);

    if ((HAL_OK != HAL_UART_RegisterRxEventCallback(&gnss_uart_handle, rx_event_callback)) ||
        (HAL_OK != HAL_UART_AbortReceive(&gnss_uart_handle)) ||
        (HAL_OK != HAL_UARTEx_ReceiveToIdle_DMA(&gnss_uart_handle, (uint8_t *)rx_msg.data, sizeof(rx_msg.data))))
    {
        return false;
    }

    HAL_NVIC_SetPriority(DMA2_Stream1_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(DMA2_Stream1_IRQn);

    HAL_NVIC_SetPriority(UART5_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(UART5_IRQn);

    return true;
}

bool gnss_uart_deinit(void)
{
    HAL_NVIC_DisableIRQ(DMA2_Stream1_IRQn);
    HAL_NVIC_DisableIRQ(UART5_IRQn);

    if (HAL_OK != HAL_UART_DeInit(&gnss_uart_handle))
    {
        return false;
    }

    if (HAL_OK != HAL_DMA_DeInit(&hdma_uart_rx))
    {
        return false;
    }

    return true;
}

bool gnss_uart_tx(const uint8_t *p_data, const uint16_t data_sz)
{
    BREAK_ASSERT(p_data != NULL);
    BREAK_ASSERT(data_sz > 0);

    bool res = false;

    if ((NULL != p_data) &&
        (0 < data_sz) &&
        (HAL_OK == HAL_UART_Transmit(&gnss_uart_handle, (uint8_t *)p_data, data_sz, 1000)))
    {
        res = true;
    }

    return res;
}

bool gnss_uart_rx(gnss_uart_resp_t *resp, uint16_t timeout)
{
    osStatus_t gnss_get_q_stat = osError;

    if ((NULL != resp) &&
        (NULL != rx_q))
    {
        uint8_t msg_prio = 0;
        gnss_get_q_stat  = osMessageQueueGet(rx_q, (void *)resp, &msg_prio, timeout);
    }
    else
    {
        osDelay(timeout);
    }

    return (gnss_get_q_stat == osOK);
}

bool is_gnss_uart_init(void)
{
    /* check b5 (initialization status) in HAL_UART_StateTypeDef (gnss_uart_handle.gState) */
    return ((HAL_UART_GetState(&gnss_uart_handle) & UART_STATE_INIT_MASK) == UART_STATE_INIT_MASK) ? true : false;
}

bool gnss_uart_baudrate_set(const GNSS_BaudRate_t *const baudrate)
{
    bool res = false;

    if ((NULL != baudrate) &&
        (true == is_gnss_uart_init()))
    {
        GNSS_BaudRate_t baudrate_tmp = *baudrate;
        Nvm_SetBlockById(NVM_BLOCK_GNSS_COMM_SETTINGS, &baudrate_tmp, NVMSETBLOCK_STORE_IMMEDIATELY);

        if (true == gnss_uart_reset_with_new_baudrate())
        {
            res = true;
        }
    }

    return res;
}

bool gnss_uart_baudrate_get(GNSS_BaudRate_t *const baudrate_nvm, GNSS_BaudRate_t *const baudrate_current)
{
    bool res = false;

    if ((NULL != baudrate_nvm) && (NULL != baudrate_current))
    {
        GNSS_BaudRate_t baudrate_nvm_tmp;
        Nvm_GetBlockById(NVM_BLOCK_GNSS_COMM_SETTINGS, &baudrate_nvm_tmp);
        *baudrate_nvm     = baudrate_nvm_tmp;
        *baudrate_current = gnss_handle_current_baudrate;
        res               = true;
    }

    return res;
}

uint32_t gnss_uart_baudrate_map(GNSS_BaudRate_t baudrate)
{
    uint32_t res = 0U;

    switch (baudrate)
    {
        case GNSS_BAUDRATE_BAUD_9600_BPS:
            res = 9600U;
            break;
        case GNSS_BAUDRATE_BAUD_19200_BPS:
            res = 19200U;
            break;
        case GNSS_BAUDRATE_BAUD_38400_BPS:
            res = 38400U;
            break;
        case GNSS_BAUDRATE_BAUD_57600_BPS:
            res = 57600U;
            break;
        case GNSS_BAUDRATE_BAUD_115200_BPS:
            res = 115200U;
            break;
        case GNSS_BAUDRATE_BAUD_230400_BPS:
            res = 230400U;
            break;
        case GNSS_BAUDRATE_BAUD_460800_BPS:
            res = 460800U;
            break;
        default:
            res = 460800U;
    }

    return res;
}

void gnss_irq_uart_handler(void)
{
    HAL_UART_IRQHandler(&gnss_uart_handle);
}

void gnss_irq_dma_handler(void)
{
    HAL_DMA_IRQHandler(&hdma_uart_rx);
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
static void msp_init_callback(UART_HandleTypeDef *p_huart)
{
    if ((UART5 == p_huart->Instance) && (p_huart == &gnss_uart_handle))
    {
        __HAL_RCC_UART5_CLK_ENABLE();
        __HAL_RCC_GPIOB_CLK_ENABLE();

        GPIO_InitTypeDef gpio_init_struct = { 0 };
        gpio_init_struct.Pin              = GPIO_PIN_5 | GPIO_PIN_6;
        gpio_init_struct.Mode             = GPIO_MODE_AF_PP;
        gpio_init_struct.Pull             = GPIO_NOPULL;
        gpio_init_struct.Speed            = GPIO_SPEED_FREQ_LOW;
        gpio_init_struct.Alternate        = GPIO_AF14_UART5;
        HAL_GPIO_Init(GPIOB, &gpio_init_struct);
    }
}

static void msp_deinit_callback(UART_HandleTypeDef *p_huart)
{
    if ((UART5 == p_huart->Instance) && (p_huart == &gnss_uart_handle))
    {
        __HAL_RCC_UART5_CLK_DISABLE();

        HAL_GPIO_DeInit(GPIOB, GPIO_PIN_5 | GPIO_PIN_6);
    }
}

static void rx_event_callback(UART_HandleTypeDef *p_huart, uint16_t size)
{
    if ((UART5 == p_huart->Instance) && (p_huart == &gnss_uart_handle))
    {
        CRIT_ASSERT(NULL != rx_q);

        rx_msg.data_sz = size;

        (void)osMessageQueuePut(rx_q, (const void *)&rx_msg, 0, 0);

        __HAL_DMA_DISABLE_IT(&hdma_uart_rx, DMA_IT_HT);
        (void)HAL_UARTEx_ReceiveToIdle_DMA(&gnss_uart_handle, (uint8_t *)rx_msg.data, sizeof(rx_msg.data));
    }
}

static bool gnss_uart_reset_with_new_baudrate(void)
{
    bool res = false;

    // set new desired baudrate
    if ((true == gnss_uart_deinit()) &&
        (true == gnss_uart_init()))
    {
        res = true;
    }

    return res;
}
