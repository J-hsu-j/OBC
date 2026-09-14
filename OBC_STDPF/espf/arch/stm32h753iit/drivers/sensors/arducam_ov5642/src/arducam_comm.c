/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup service_arducam
 * @{
 *
 * @file arducam_comm.c
 * @brief ArduCam service communications implementation.
 *
 * @}
 */
#include "arducam_comm.h"
#include "ov5642.h"
#include "stm32h7xx_hal.h"
#include "cmsis_os.h"
#include "trace.h"

#include <User_types.h>
#include <MX_I2C.h>

/*
*********************************************************************************************
* INTERNAL DEFINES
*********************************************************************************************
*/

/* SPI Handle */
SPI_HandleTypeDef arducam_spi;
/* DMA Handle */
DMA_HandleTypeDef hdma_spi5_rx;
DMA_HandleTypeDef hdma_spi5_tx;
/* SPI flag for interrupt and DMA */
osEventFlagsId_t arducam_img_event_Id;

#define TIMEOUT_SPI_MS       (50)
#define TIMEOUT_SPI_BURST_MS (500U)
#define SPI_TRANSMIT_DONE    (0x01)

#define pgm_read_word(x) (((*((unsigned char *)x + 1)) << 8) + (*((unsigned char *)x)))

/*
*********************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
*********************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
*********************************************************************************************
*/

/*
*********************************************************************************************
* EXTERNAL (NONE STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/
/**
 * @brief En_Cam GPIO Initialization Function
 */
void arducam_pin_enable_init(void)
{
    HAL_GPIO_WritePin(EN_CAM_GPIO_Port, EN_CAM_Pin, GPIO_PIN_RESET);

    GPIO_InitTypeDef GPIO_InitStruct = { 0 };
    GPIO_InitStruct.Pin              = EN_CAM_Pin;
    GPIO_InitStruct.Mode             = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull             = GPIO_NOPULL;
    GPIO_InitStruct.Speed            = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(EN_CAM_GPIO_Port, &GPIO_InitStruct);
}

void arducam_pin_enable_deinit(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };
    GPIO_InitStruct.Pin              = EN_CAM_Pin;
    GPIO_InitStruct.Mode             = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull             = GPIO_NOPULL;
    HAL_GPIO_Init(EN_CAM_GPIO_Port, &GPIO_InitStruct);
}

/**
 * @brief SPI5 Initialization Function
 */
void arducam_spi5_init(void)
{
    GPIO_InitTypeDef         GPIO_InitStruct     = { 0 };
    RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = { 0 };

    /* Peripheral clock enable */
    __HAL_RCC_SPI5_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_DMA1_CLK_ENABLE();

    /* Peripheral clock configuration */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SPI5;
    PeriphClkInitStruct.Spi45ClockSelection  = RCC_SPI45CLKSOURCE_PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    /**SPI5 GPIO Configuration
      PF7     ------> SPI5_SCK
      PF8     ------> SPI5_MISO
      PF9     ------> SPI5_MOSI
    */
    GPIO_InitStruct.Pin       = SPI5_SCK_Pin | SPI5_MISO_Pin | SPI5_MOSI_Pin;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI5;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    // Init CS
    GPIO_InitStruct.Pin   = ARDU_CAM_CS_Pin;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(ARDU_CAM_CS_GPIO_Port, &GPIO_InitStruct);

    // SPI5 setup
    arducam_spi.Instance                        = SPI5;
    arducam_spi.Init.Mode                       = SPI_MODE_MASTER;
    arducam_spi.Init.Direction                  = SPI_DIRECTION_2LINES;
    arducam_spi.Init.DataSize                   = SPI_DATASIZE_8BIT;
    arducam_spi.Init.CLKPolarity                = SPI_POLARITY_LOW;
    arducam_spi.Init.CLKPhase                   = SPI_PHASE_1EDGE;
    arducam_spi.Init.NSS                        = SPI_NSS_SOFT;
    arducam_spi.Init.BaudRatePrescaler          = SPI_BAUDRATEPRESCALER_32; // TODO: Test faster, up to 8 MHz for the ArduCam
    arducam_spi.Init.FirstBit                   = SPI_FIRSTBIT_MSB;
    arducam_spi.Init.TIMode                     = SPI_TIMODE_DISABLE;
    arducam_spi.Init.CRCCalculation             = SPI_CRCCALCULATION_DISABLE;
    arducam_spi.Init.CRCPolynomial              = 7;
    arducam_spi.Init.CRCLength                  = SPI_CRC_LENGTH_DATASIZE;
    arducam_spi.Init.NSSPMode                   = SPI_NSS_PULSE_ENABLE;
    arducam_spi.Init.NSSPolarity                = SPI_NSS_POLARITY_LOW;
    arducam_spi.Init.FifoThreshold              = SPI_FIFO_THRESHOLD_06DATA;
    arducam_spi.Init.TxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
    arducam_spi.Init.RxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
    arducam_spi.Init.MasterSSIdleness           = SPI_MASTER_SS_IDLENESS_00CYCLE;
    arducam_spi.Init.MasterInterDataIdleness    = SPI_MASTER_INTERDATA_IDLENESS_00CYCLE;
    arducam_spi.Init.MasterReceiverAutoSusp     = SPI_MASTER_RX_AUTOSUSP_DISABLE;
    arducam_spi.Init.MasterKeepIOState          = SPI_MASTER_KEEP_IO_STATE_ENABLE;
    arducam_spi.Init.IOSwap                     = SPI_IO_SWAP_DISABLE;

    HAL_SPI_DMAStop(&arducam_spi);
    HAL_SPI_DeInit(&arducam_spi);

    if (HAL_SPI_Init(&arducam_spi) != HAL_OK)
    {
        Error_Handler();
    }

    HAL_NVIC_SetPriority(SPI5_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(SPI5_IRQn);

    // DMA Controller
    /* SPI5_RX Init */
    hdma_spi5_rx.Instance                 = DMA1_Stream4;
    hdma_spi5_rx.Init.Request             = DMA_REQUEST_SPI5_RX;
    hdma_spi5_rx.Init.Direction           = DMA_PERIPH_TO_MEMORY;
    hdma_spi5_rx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_spi5_rx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_spi5_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_spi5_rx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_spi5_rx.Init.Mode                = DMA_NORMAL;
    hdma_spi5_rx.Init.Priority            = DMA_PRIORITY_VERY_HIGH;
    hdma_spi5_rx.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;

    if (HAL_DMA_Init(&hdma_spi5_rx) != HAL_OK)
    {
        Error_Handler();
    }

    __HAL_LINKDMA(&arducam_spi, hdmarx, hdma_spi5_rx);

    /* SPI5_TX Init */
    hdma_spi5_tx.Instance                 = DMA1_Stream6;
    hdma_spi5_tx.Init.Request             = DMA_REQUEST_SPI5_TX;
    hdma_spi5_tx.Init.Direction           = DMA_MEMORY_TO_PERIPH;
    hdma_spi5_tx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_spi5_tx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_spi5_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_spi5_tx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_spi5_tx.Init.Mode                = DMA_NORMAL;
    hdma_spi5_tx.Init.Priority            = DMA_PRIORITY_VERY_HIGH;
    hdma_spi5_tx.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;

    if (HAL_DMA_Init(&hdma_spi5_tx) != HAL_OK)
    {
        Error_Handler();
    }
    __HAL_LINKDMA(&arducam_spi, hdmatx, hdma_spi5_tx);

    /* DMA interrupt init */
    HAL_NVIC_SetPriority(DMA1_Stream4_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(DMA1_Stream4_IRQn);
    HAL_NVIC_SetPriority(DMA1_Stream6_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(DMA1_Stream6_IRQn);

    /* DMAMUX1_OVR_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMAMUX1_OVR_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(DMAMUX1_OVR_IRQn);

    arducam_img_event_Id = osEventFlagsNew(NULL);
    HAL_GPIO_WritePin(ARDU_CAM_CS_GPIO_Port, ARDU_CAM_CS_Pin, GPIO_PIN_SET);

    // One dummy transfer for HAL
    uint8_t txdata;
    (void)HAL_SPI_Transmit(&arducam_spi, &txdata, 1, 10);
}

void arducam_spi5_deinit(void)
{
    HAL_SPI_DeInit(&arducam_spi);

    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    GPIO_InitStruct.Pin  = SPI5_SCK_Pin | SPI5_MISO_Pin | SPI5_MOSI_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    __HAL_RCC_SPI5_CLK_DISABLE();

    /**SPI5 GPIO Configuration
    PF7     ------> SPI5_SCK
    PF8     ------> SPI5_MISO
    PF9     ------> SPI5_MOSI
    */
    HAL_GPIO_DeInit(GPIOF, SPI5_SCK_Pin | SPI5_MISO_Pin | SPI5_MOSI_Pin);
}

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
    ARDUCAM_CS_LOW;
    osEventFlagsSet(arducam_img_event_Id, SPI_TRANSMIT_DONE);
}
void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
    ARDUCAM_CS_LOW;
    osEventFlagsSet(arducam_img_event_Id, SPI_TRANSMIT_DONE);
}
void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
{
    ARDUCAM_CS_LOW;
    osEventFlagsSet(arducam_img_event_Id, SPI_TRANSMIT_DONE);
}

void SPI5_IRQHandler(void)
{
    HAL_SPI_IRQHandler(&arducam_spi);
}

/**
 * @brief This function handles DMA1 stream5 global interrupt.
 */
void DMA1_Stream4_IRQHandler(void)
{
    HAL_DMA_IRQHandler(&hdma_spi5_rx);
}
/**
 * @brief This function handles DMA1 stream6 global interrupt.
 */
void DMA1_Stream6_IRQHandler(void)
{
    HAL_DMA_IRQHandler(&hdma_spi5_tx);
}

/*********/
uint8_t arducam_comm_read_ov5642(uint16_t addr)
{
    uint8_t data;

    if (HAL_OK != HAL_I2C_Mem_Read(&system_i2c_handle, ARDUCAM_ADDR, addr, sizeof(addr), &data, sizeof(data), 10))
    {
        ES_TRACE_ERROR("Read I2C error device %d: addr: %d.\n", ARDUCAM_ADDR, addr);
    }
    ES_TRACE_DEBUG("I2C read 0x%x: 0x%x\n", addr, data);

    return data;
}

bool arducam_comm_write_ov5642(uint16_t addr, uint8_t val)
{
    uint8_t i    = 0;
    uint8_t data = val;

    while (HAL_OK != HAL_I2C_Mem_Write(&system_i2c_handle, ARDUCAM_ADDR, addr, sizeof(addr), &data, sizeof(data), 10))
    {
        i++;
        if (i > 250)
        {
            ES_TRACE_ERROR("Write I2C error device %d: addr: %d.\n", ARDUCAM_ADDR, addr);
            return false;
        }
    }
    osDelay(AC_INTER_I2C_OP_DELAY_MS);
    ES_TRACE_DEBUG("I2C write 0x%x: 0x%x\n", addr, data);

    return true;
}

bool arducam_comm_write_regs_ov5642(const struct sensor_reg reglist[])
{
    uint16_t                 reg_addr = 0;
    uint8_t                  reg_val  = 0;
    const struct sensor_reg *next     = reglist;

    while ((reg_addr != 0xffff) || (reg_val != 0xff))
    {
        reg_addr = (uint16_t)pgm_read_word(&next->reg);
        reg_val  = next->val;
        if (!arducam_comm_write_ov5642(reg_addr, reg_val))
        {
            return false;
        }
        next++;
    }

    return true;
}

uint8_t arducam_comm_read_addr_spi(uint8_t addr)
{
    uint8_t tx[2];
    tx[0] = addr & 0x7F; // Provide CMD[7]=0 for read operation
    tx[1] = 0;

    // Clear the events flag
    osEventFlagsClear(arducam_img_event_Id, SPI_TRANSMIT_DONE);

    ARDUCAM_CS_LOW;

    uint8_t rx[2];
    ES_TRACE_DEBUG("SPI read TX: 0x%x 0x%x\n", tx[0], tx[1]);
    HAL_StatusTypeDef hal_ret = HAL_SPI_TransmitReceive_DMA(&arducam_spi, tx, rx, 2);
    if (HAL_OK != hal_ret)
    {
        ES_TRACE_ERROR("Error reading SPI at addr %d: %d.\n", addr, hal_ret);
    }

    /* Wait for SPI_TRANSMIT_DONE flag to be raised in the interrupt after SPI_TransmitReceive is done */
    int32_t flags = osEventFlagsWait(arducam_img_event_Id, SPI_TRANSMIT_DONE, osFlagsWaitAny, TIMEOUT_SPI_MS);
    if (flags < 0)
    {
        ES_TRACE_ERROR("Event flags error: %d\n", flags);
    }

    ES_TRACE_DEBUG("SPI read RX: 0x%x 0x%x\n", rx[0], rx[1]);

    ARDUCAM_CS_HIGH;

    return rx[1];
}

void arducam_comm_read_burst_spi(uint8_t *buff, uint16_t size)
{
    // Clear the events flag
    osEventFlagsClear(arducam_img_event_Id, SPI_TRANSMIT_DONE);

    ARDUCAM_CS_LOW;

    // Set burst mode
    uint8_t tx[1] = { BURST_FIFO_READ };
    uint8_t rx[1] = { 0x00 };

    HAL_StatusTypeDef hal_ret = HAL_SPI_TransmitReceive_DMA(&arducam_spi, tx, rx, 1);
    if (HAL_OK != hal_ret)
    {
        ES_TRACE_ERROR("Error reading SPI byte: %d.\n", hal_ret);
    }

    /* Wait for SPI_TRANSMIT_DONE flag to be raised in the interrupt after SPI_TransmitReceive is done */
    int32_t flags = osEventFlagsWait(arducam_img_event_Id, SPI_TRANSMIT_DONE, osFlagsWaitAny, TIMEOUT_SPI_MS);
    if (flags < 0)
    {
        ES_TRACE_ERROR("Event flags error: %d\n", flags);
    }

    // Clear the events flag
    osEventFlagsClear(arducam_img_event_Id, SPI_TRANSMIT_DONE);

    hal_ret = HAL_SPI_TransmitReceive_DMA(&arducam_spi, buff, buff, size);
    if (HAL_OK != hal_ret)
    {
        ES_TRACE_ERROR("Read SPI Burst HAL error: %d.\n", hal_ret);
    }

    /* Wait for SPI_TRANSMIT_DONE flag to be raised in the interrupt after SPI_TransmitReceive is done */
    flags = osEventFlagsWait(arducam_img_event_Id, SPI_TRANSMIT_DONE, osFlagsWaitAny, TIMEOUT_SPI_BURST_MS);
    if (flags < 0)
    {
        ES_TRACE_ERROR("Event flags error: %d\n", flags);
    }

    ARDUCAM_CS_HIGH;
}

void arducam_write_addr_spi(uint8_t addr, uint8_t data)
{
    uint8_t tx[2];
    tx[0] = addr | 0x80; // Provide CMD[7]=1 for write operation
    tx[1] = data;

    uint8_t rx[2];

    // Clear the events flag
    osEventFlagsClear(arducam_img_event_Id, SPI_TRANSMIT_DONE);

    ARDUCAM_CS_LOW;

    ES_TRACE_DEBUG("SPI write TX: 0x%x 0x%x\n", tx[0], tx[1]);
    HAL_StatusTypeDef hal_ret = HAL_SPI_TransmitReceive_DMA(&arducam_spi, tx, rx, 2);
    if (HAL_OK != hal_ret)
    {
        ES_TRACE_ERROR("Write SPI error addr %d: %d.\n", addr, hal_ret);
    }

    /* Wait for SPI_TRANSMIT_DONE flag to be raised in the interrupt after SPI_TransmitReceive is done */
    int32_t flags = osEventFlagsWait(arducam_img_event_Id, SPI_TRANSMIT_DONE, osFlagsWaitAny, TIMEOUT_SPI_MS);
    if (flags < 0)
    {
        ES_TRACE_ERROR("Event flags error: %d\n", flags);
    }

    ES_TRACE_DEBUG("SPI write RX: 0x%x 0x%x\n", rx[0], rx[1]);

    ARDUCAM_CS_HIGH;
    osDelay(AC_INTER_SPI_OP_DELAY_MS);
}
