/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup I2C
 * @{
 *
 * This file is an I2C HAL wrapper which enables use of the I2C bus from multiple OS threads.
 * Access to the individual supported buses is protected by semaphores and the operations are
 * synchronous. This file contains some legacy implementation and it depends directly on FreeRTOS APIs
 * instead of using CMSIS APIs.
 *
 * @file MX_I2C.c
 * @brief I2C HAL wrapper implementation
 *
 * @}
 */

/*
*********************************************************************************************
* INCLUDES
*********************************************************************************************
*/
#include "MX_I2C.h"
#include "es_exeh.h"
#include "semphr.h"
#include "stm32h7xx_ll_i2c.h"
#include "assertions.h"

/*
*********************************************************************************************
* INTERNAL DEFINES
*********************************************************************************************
*/
#define MX_I2C_MAX_RETRIES            (5u)         /**< max number of attempts to reset the I2C interface in case of error */
#define MX_I2C_RETRY_DELAY_MS         (5u)         /**< number of milliseconds to wait before making another attempt to communicate in case of error */
#define MX_I2C_RW_TIMEOUT_MS          (30u)        /**< number of milliseconds to wait before a read/write operation times out => 30ms ~= max 750 Bytes (200kbps => 25Bk/s => 25B/ms) */
#define MX_I2C_ERR_CNT_BEFORE_BUS_RST (1u)         /**< number of communication attempts to perform before making an explicit bus reset */
#define MX_I2C_DISABLE_DELAY_MS       (1u)         /**< number of milliseconds to wait after disabling the I2C peripheral before enabling it again */
#define MX_I2C_SCL_PULSE_CNT          (16u)        /**< number of SCL high-to-low pulses performed on bus reset */
#define MX_I2C_OWN_ADDR_DEFAULT       (0u)         /**< Default I2C OBC node address */
#define MX_I2C_TIMING_REG_VAL_DEFAULT (0x6000030D) /**< Default setting for the I2C timing register */

/*
*********************************************************************************************
* INTERNAL TYPES DEFINITION
*********************************************************************************************
*/
/** @brief Define the list of handles needed for the operation of this module */
typedef struct
{
    SemaphoreHandle_t sem_hnd;            /**< handle of the FreeRTOS semaphore object */
    StaticSemaphore_t mutex_buf;          /**< static memory allocated for use by @ref mx_i2c_handles_t::sem_hnd */
    TaskHandle_t      bus_owner_task_hnd; /**< handle of the task which currently owns the bus */
} mx_i2c_handles_t;

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
static mx_i2c_handles_t i2c_handles[MX_I2C_BUS_COUNT]; /**< Keeps the handles for all configured I2C buses */

/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
*********************************************************************************************
*/
/** @brief Return the corresponding I2C instance handle for a given bus ID
 *
 *  @param[in] bus I2C bus ID
 *
 *  @return I2C handle to the underlying peripheral
 */
static I2C_HandleTypeDef *mx_i2c_get_bus_handle(const mx_i2c_bus_t bus);

/** @brief Initialize a specified I2C bus
 *  @param[in] bus I2C bus ID
 */
static void mx_i2c_bus_init(mx_i2c_bus_t bus);

/** @brief Perform internal initialization of the I2C system bus */
static void mx_system_i2c_init(void);

/** @brief Perform a bus reset on a specified I2C bus
 *  @param[in] bus I2C bus ID
 */
static void mx_i2c_bus_reset(mx_i2c_bus_t bus);

/** @brief Perform internal de-initialization of the I2C system bus */
static void mx_system_i2c_deinit(void);

/** @brief Perform internal initialization of the I2C sensors bus */
static void mx_sensors_i2c_init(void);

/** @brief Perform internal de-initialization of the I2C sensors bus */
static void mx_sensors_i2c_deinit(void);

/** @brief Perform internal initialization of the I2C payload bus */
static void mx_payload_i2c_init(void);

/** @brief Perform internal de-initialization of the I2C payload bus */
static void mx_payload_i2c_deinit(void);

/** @brief Reset the system I2C bus */
static void system_i2c_reset(void);

/** @brief Reset the sensor I2C bus */
static void sensors_i2c_reset(void);

/** @brief Reset the payload I2C bus */
static void payload_i2c_reset(void);

/*
*********************************************************************************************
* EXTERNAL (NON-STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/
void mx_i2c_init(void)
{
    for (uint8_t i = 0; i < MX_I2C_BUS_COUNT; i++)
    {
        i2c_handles[i].sem_hnd = xSemaphoreCreateMutexStatic(&i2c_handles[i].mutex_buf);
        BREAK_ASSERT(i2c_handles[i].sem_hnd);
    }
}

void mx_i2c_deinit(void)
{
    for (uint8_t i = 0; i < MX_I2C_BUS_COUNT; i++)
    {
        TaskHandle_t tempTaskHandler = xSemaphoreGetMutexHolder(i2c_handles[i].sem_hnd);
        if (tempTaskHandler != NULL)
        {
            mx_i2c_release(i);
        }
    }
}

HAL_StatusTypeDef mx_i2c_take(const mx_i2c_bus_t bus, const TickType_t max_ticks_to_wait)
{
    BaseType_t        getSemVal = pdFALSE;
    HAL_StatusTypeDef retVal    = HAL_ERROR;

    if (bus < MX_I2C_BUS_COUNT)
    {
        getSemVal = xSemaphoreTake(i2c_handles[bus].sem_hnd, max_ticks_to_wait);
    }

    if (getSemVal == pdTRUE)
    {
        mx_i2c_bus_init(bus);
        i2c_handles[bus].bus_owner_task_hnd = xSemaphoreGetMutexHolder(i2c_handles[bus].sem_hnd);
        retVal                              = HAL_OK;
    }

    return retVal;
}

void mx_i2c_release(const mx_i2c_bus_t bus)
{
    BaseType_t getSemVal = pdFALSE;

    if (bus < MX_I2C_BUS_COUNT)
    {
        getSemVal = xSemaphoreGive(i2c_handles[bus].sem_hnd);
    }

    if (getSemVal == pdTRUE)
    {
        mx_i2c_bus_deinit(bus);
    }
    else
    {
        BREAK_ASSERT(false);
    }
}

HAL_StatusTypeDef mx_i2c_block_tx(const mx_i2c_bus_t bus, const uint16_t dev_addr, uint8_t *const p_data, const uint16_t size)
{
    uint8_t           timeout     = 0;
    HAL_StatusTypeDef I2C_retStat = HAL_ERROR;

    BREAK_ASSERT(NULL != p_data);
    BREAK_ASSERT(size > 0);
    BREAK_ASSERT(bus < MX_I2C_BUS_COUNT);

    if ((NULL == p_data) || (0 == size) || (bus >= MX_I2C_BUS_COUNT))
    {
        return HAL_ERROR;
    }

    TaskHandle_t tempTaskHandler = xSemaphoreGetMutexHolder(i2c_handles[bus].sem_hnd);
    if (i2c_handles[bus].bus_owner_task_hnd == tempTaskHandler)
    {
        do
        {
            if (timeout >= MX_I2C_ERR_CNT_BEFORE_BUS_RST)
            {
                if ((I2C_retStat == HAL_ERROR) || (I2C_retStat == HAL_TIMEOUT) || ((I2C_retStat == HAL_BUSY) && (hi2c1.State == HAL_I2C_STATE_READY)))
                {
                    mx_i2c_bus_reset(bus);
                }
                osDelay(MX_I2C_RETRY_DELAY_MS);

                if (timeout >= MX_I2C_MAX_RETRIES)
                {
                    break;
                }
            }
            I2C_retStat = HAL_I2C_Master_Transmit(mx_i2c_get_bus_handle(bus), dev_addr << 1, (uint8_t *)p_data, size, MX_I2C_RW_TIMEOUT_MS);

            timeout++;
        } while (I2C_retStat != HAL_OK);
    }

    return I2C_retStat;
}

HAL_StatusTypeDef mx_i2c_block_rx(const mx_i2c_bus_t bus, const uint16_t dev_addr, uint8_t *const p_data, const uint16_t size)
{
    uint8_t           timeout     = 0;
    HAL_StatusTypeDef I2C_retStat = HAL_ERROR;

    BREAK_ASSERT(NULL != p_data);
    BREAK_ASSERT(size > 0);
    BREAK_ASSERT(bus < MX_I2C_BUS_COUNT);

    if ((NULL == p_data) || (0 == size) || (bus >= MX_I2C_BUS_COUNT))
    {
        return HAL_ERROR;
    }

    TaskHandle_t tempTaskHandler = xSemaphoreGetMutexHolder(i2c_handles[bus].sem_hnd);
    if (i2c_handles[bus].bus_owner_task_hnd == tempTaskHandler)
    {
        do
        {
            if (timeout >= MX_I2C_ERR_CNT_BEFORE_BUS_RST)
            {
                // if there is any error reset the I2C interface
                if ((I2C_retStat == HAL_ERROR) || (I2C_retStat == HAL_TIMEOUT) || ((I2C_retStat == HAL_BUSY) && (hi2c1.State == HAL_I2C_STATE_READY)))
                {
                    mx_i2c_bus_reset(bus);
                }
                osDelay(MX_I2C_RETRY_DELAY_MS);

                if (timeout >= MX_I2C_MAX_RETRIES)
                {
                    // Stop trying after certain times
                    EXEH_vException(eEXEHSeverity_Error, eEXEHModuleID_EPS_COMM, eEXEH_EPS_EXCEPTION_ID_COMM_ERROR, __LINE__);
                    break;
                }
            }

            // Read the register from the EPS
            I2C_retStat = HAL_I2C_Master_Receive(mx_i2c_get_bus_handle(bus), dev_addr << 1, p_data, size, MX_I2C_RW_TIMEOUT_MS);

            timeout++; // count one more try
        } while (I2C_retStat != HAL_OK);
    }

    return I2C_retStat;
}

HAL_StatusTypeDef mx_i2c_block_mem_write(const mx_i2c_bus_t bus, const uint16_t dev_addr, const uint16_t mem_addr, const uint16_t addr_sz, uint8_t *const p_data, const uint16_t size)
{
    uint8_t           timeout     = 0;
    HAL_StatusTypeDef I2C_retStat = HAL_ERROR;

    BREAK_ASSERT(NULL != p_data);
    BREAK_ASSERT(size > 0);
    BREAK_ASSERT(bus < MX_I2C_BUS_COUNT);

    if ((NULL == p_data) || (0 == size) || (bus >= MX_I2C_BUS_COUNT))
    {
        return HAL_ERROR;
    }

    TaskHandle_t tempTaskHandler = xSemaphoreGetMutexHolder(i2c_handles[bus].sem_hnd);
    if (i2c_handles[bus].bus_owner_task_hnd == tempTaskHandler)
    {
        do
        {
            if (timeout >= MX_I2C_ERR_CNT_BEFORE_BUS_RST)
            {
                if ((I2C_retStat == HAL_ERROR) || (I2C_retStat == HAL_TIMEOUT) || ((I2C_retStat == HAL_BUSY) && (hi2c1.State == HAL_I2C_STATE_READY)))
                {
                    mx_i2c_bus_reset(bus);
                }
                osDelay(MX_I2C_RETRY_DELAY_MS);

                if (timeout >= MX_I2C_MAX_RETRIES)
                {
                    break;
                }
            }

            I2C_retStat = HAL_I2C_Mem_Write(mx_i2c_get_bus_handle(bus), dev_addr << 1, mem_addr, addr_sz, (uint8_t *)p_data, size, MX_I2C_RW_TIMEOUT_MS);

            timeout++;
        } while (I2C_retStat != HAL_OK);
    }

    return I2C_retStat;
}

HAL_StatusTypeDef mx_i2c_block_mem_read(const mx_i2c_bus_t bus, const uint16_t dev_addr, const uint16_t mem_addr, const uint16_t addr_sz, uint8_t *const p_data, const uint16_t size)
{
    uint8_t           timeout     = 0;
    HAL_StatusTypeDef I2C_retStat = HAL_ERROR;

    BREAK_ASSERT(NULL != p_data);
    BREAK_ASSERT(size > 0);
    BREAK_ASSERT(bus < MX_I2C_BUS_COUNT);

    if ((NULL == p_data) || (0 == size) || (bus >= MX_I2C_BUS_COUNT))
    {
        return HAL_ERROR;
    }

    TaskHandle_t tempTaskHandler = xSemaphoreGetMutexHolder(i2c_handles[bus].sem_hnd);
    if (i2c_handles[bus].bus_owner_task_hnd == tempTaskHandler)
    {
        do
        {
            if (timeout >= MX_I2C_ERR_CNT_BEFORE_BUS_RST)
            {
                // if there is any error reset the I2C interface
                if ((I2C_retStat == HAL_ERROR) || (I2C_retStat == HAL_TIMEOUT) || ((I2C_retStat == HAL_BUSY) && (hi2c1.State == HAL_I2C_STATE_READY)))
                {
                    mx_i2c_bus_reset(bus);
                }
                osDelay(MX_I2C_RETRY_DELAY_MS);

                if (timeout >= MX_I2C_MAX_RETRIES)
                {
                    // Stop trying after certain times
                    EXEH_vException(eEXEHSeverity_Error, eEXEHModuleID_EPS_COMM, eEXEH_EPS_EXCEPTION_ID_COMM_ERROR, __LINE__);
                    break;
                }
            }

            // Read the register from the EPS
            I2C_retStat = HAL_I2C_Mem_Read(mx_i2c_get_bus_handle(bus), dev_addr << 1, mem_addr, addr_sz, (uint8_t *)p_data, size, MX_I2C_RW_TIMEOUT_MS);

            timeout++; // count one more try
        } while (I2C_retStat != HAL_OK);
    }

    return I2C_retStat;
}

static void mx_i2c_bus_init(mx_i2c_bus_t bus)
{
    switch (bus)
    {
        case MX_I2C_BUS_SYSTEM:
            {
                mx_system_i2c_init();
            }
            break;

        case MX_I2C_BUS_SENSORS:
            {
                mx_sensors_i2c_init();
            }
            break;

        case MX_I2C_BUS_PAYLOAD:
            {
                mx_payload_i2c_init();
            }
            break;

        default:
            {
                BREAK_ASSERT(false);
                break;
            }
    }
}

void mx_i2c_bus_deinit(const mx_i2c_bus_t bus)
{
    switch (bus)
    {
        case MX_I2C_BUS_SYSTEM:
            {
                mx_system_i2c_deinit();
                break;
            }

        case MX_I2C_BUS_SENSORS:
            {
                mx_sensors_i2c_deinit();
                break;
            }

        case MX_I2C_BUS_PAYLOAD:
            {
                mx_payload_i2c_deinit();
                break;
            }

        default:
            {
                BREAK_ASSERT(false);
                break;
            }
    }
}

static void mx_i2c_bus_reset(mx_i2c_bus_t bus)
{
    switch (bus)
    {
        case MX_I2C_BUS_SYSTEM:
            {
                system_i2c_reset();
                break;
            }

        case MX_I2C_BUS_SENSORS:
            {
                sensors_i2c_reset();
                break;
            }

        case MX_I2C_BUS_PAYLOAD:
            {
                payload_i2c_reset();
                break;
            }

        default:
            {
                BREAK_ASSERT(false);
                break;
            }
    }
}

/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/
static void system_i2c_reset(void)
{
    EXEH_vException(eEXEHSeverity_Error, eEXEHModuleID_MCU_INIT, eEXEH_MCU_INIT_EXCEPTION_ID_I2C_RST, __LINE__);

    LL_I2C_Disable(SYSTEM_I2C);
    osDelay(MX_I2C_DISABLE_DELAY_MS);
    LL_I2C_Enable(SYSTEM_I2C);

    mx_system_i2c_deinit();

    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    GPIO_InitStruct.Pin   = I2C1_SYS_SDA_Pin;
    GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(I2C1_SYS_SDA_GPIO_Port, &GPIO_InitStruct);

    HAL_GPIO_WritePin(I2C1_SYS_SCL_GPIO_Port, I2C1_SYS_SCL_Pin, GPIO_PIN_RESET);
    GPIO_InitStruct.Pin   = I2C1_SYS_SCL_Pin;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(I2C1_SYS_SCL_GPIO_Port, &GPIO_InitStruct);

    for (char i = 0; i < MX_I2C_SCL_PULSE_CNT; i++)
    {
        if (GPIO_PIN_SET == HAL_GPIO_ReadPin(I2C1_SYS_SDA_GPIO_Port, I2C1_SYS_SDA_Pin))
        {
            break;
        }
        else // if I2C SDA pin is reset, the I2C SCL must do some clocks to make the data bit let go to high
        {
            HAL_GPIO_WritePin(I2C1_SYS_SCL_GPIO_Port, I2C1_SYS_SCL_Pin, GPIO_PIN_SET);
            HAL_Delay(0); // keep a short pause of several instructions between pin toggles
            HAL_GPIO_WritePin(I2C1_SYS_SCL_GPIO_Port, I2C1_SYS_SCL_Pin, GPIO_PIN_RESET);
            HAL_Delay(0); // keep a short pause of several instructions between pin toggles
        }
    }

    system_i2c_handle.State = HAL_I2C_STATE_RESET;

    mx_system_i2c_init();
}

static void sensors_i2c_reset(void)
{
    LL_I2C_Disable(SENSORS_I2C); // SENSORS_I2C_HANDLER.Instance->CR1 &= ~I2C_CR1_PE;
    osDelay(MX_I2C_DISABLE_DELAY_MS);
    LL_I2C_Enable(SENSORS_I2C); // SENSORS_I2C_HANDLER.Instance->CR1 |= I2C_CR1_PE;

    mx_sensors_i2c_deinit();

    GPIO_InitTypeDef GPIO_InitStruct = { 0 };
    GPIO_InitStruct.Pin              = I2C2_SEN_SDA_Pin;
    GPIO_InitStruct.Mode             = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull             = GPIO_NOPULL;
    GPIO_InitStruct.Speed            = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(I2C2_SEN_SDA_GPIO_Port, &GPIO_InitStruct);

    HAL_GPIO_WritePin(I2C2_SEN_SCL_GPIO_Port, I2C2_SEN_SCL_Pin, GPIO_PIN_RESET);
    GPIO_InitStruct.Pin   = I2C2_SEN_SCL_Pin;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(I2C2_SEN_SCL_GPIO_Port, &GPIO_InitStruct);

    for (char i = 0; i < MX_I2C_SCL_PULSE_CNT; i++)
    {
        if (GPIO_PIN_SET == HAL_GPIO_ReadPin(I2C2_SEN_SDA_GPIO_Port, I2C2_SEN_SDA_Pin))
        {
            break;
        }
        else // if I2C SDA pin is reset, the I2C SCL must do some clocks to make the data bit let go to high
        {
            HAL_GPIO_WritePin(I2C2_SEN_SCL_GPIO_Port, I2C2_SEN_SCL_Pin, GPIO_PIN_SET);
            HAL_Delay(0); // keep a short pause of several instructions between pin toggles
            HAL_GPIO_WritePin(I2C2_SEN_SCL_GPIO_Port, I2C2_SEN_SCL_Pin, GPIO_PIN_RESET);
            HAL_Delay(0); // keep a short pause of several instructions between pin toggles
        }
    }

    sensors_i2c_handle.State = HAL_I2C_STATE_RESET;

    mx_sensors_i2c_init();
}

static void payload_i2c_reset(void)
{
    EXEH_vException(eEXEHSeverity_Error, eEXEHModuleID_MCU_INIT, eEXEH_MCU_INIT_EXCEPTION_ID_I2C_RST, __LINE__);

    LL_I2C_Disable(PAYLOAD_I2C);
    osDelay(MX_I2C_DISABLE_DELAY_MS);
    LL_I2C_Enable(PAYLOAD_I2C);

    mx_payload_i2c_deinit();

    GPIO_InitTypeDef GPIO_InitStruct = { 0 };
    GPIO_InitStruct.Pin              = I2C3_PAY_SDA_Pin;
    GPIO_InitStruct.Mode             = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull             = GPIO_NOPULL;
    GPIO_InitStruct.Speed            = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(I2C3_PAY_SDA_GPIO_Port, &GPIO_InitStruct);

    HAL_GPIO_WritePin(I2C3_PAY_SCL_GPIO_Port, I2C3_PAY_SCL_Pin, GPIO_PIN_RESET);
    GPIO_InitStruct.Pin   = I2C3_PAY_SCL_Pin;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(I2C3_PAY_SCL_GPIO_Port, &GPIO_InitStruct);

    for (char i = 0; i < MX_I2C_SCL_PULSE_CNT; i++)
    {
        if (GPIO_PIN_SET == HAL_GPIO_ReadPin(I2C3_PAY_SDA_GPIO_Port, I2C3_PAY_SDA_Pin))
        {
            break;
        }
        else // if I2C SDA pin is reset, the I2C SCL must do some clocks to make the data bit let go to high
        {
            HAL_GPIO_WritePin(I2C3_PAY_SCL_GPIO_Port, I2C3_PAY_SCL_Pin, GPIO_PIN_SET);
            HAL_Delay(0); // keep a short pause of several instructions between pin toggles
            HAL_GPIO_WritePin(I2C3_PAY_SCL_GPIO_Port, I2C3_PAY_SCL_Pin, GPIO_PIN_RESET);
            HAL_Delay(0); // keep a short pause of several instructions between pin toggles
        }
    }

    payload_i2c_handle.State = HAL_I2C_STATE_RESET;

    mx_payload_i2c_init();
}

static I2C_HandleTypeDef *mx_i2c_get_bus_handle(const mx_i2c_bus_t bus)
{
    I2C_HandleTypeDef *handler = NULL;

    switch (bus)
    {
        case MX_I2C_BUS_SYSTEM:
            {
                handler = &system_i2c_handle;
                break;
            }

        case MX_I2C_BUS_SENSORS:
            {
                handler = &sensors_i2c_handle;
                break;
            }

        case MX_I2C_BUS_PAYLOAD:
            {
                handler = &payload_i2c_handle;
                break;
            }

        default:
            {
                BREAK_ASSERT(false);
                break;
            }
    }

    return handler;
}

static void mx_system_i2c_init(void)
{
    system_i2c_handle.Instance              = SYSTEM_I2C;
    system_i2c_handle.Init.Timing           = MX_I2C_TIMING_REG_VAL_DEFAULT;
    system_i2c_handle.Init.OwnAddress1      = MX_I2C_OWN_ADDR_DEFAULT;
    system_i2c_handle.Init.AddressingMode   = I2C_ADDRESSINGMODE_7BIT;
    system_i2c_handle.Init.DualAddressMode  = I2C_DUALADDRESS_DISABLE;
    system_i2c_handle.Init.OwnAddress2      = MX_I2C_OWN_ADDR_DEFAULT;
    system_i2c_handle.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
    system_i2c_handle.Init.GeneralCallMode  = I2C_GENERALCALL_DISABLE;
    system_i2c_handle.Init.NoStretchMode    = I2C_NOSTRETCH_DISABLE;

    if (HAL_I2C_Init(&system_i2c_handle) != HAL_OK)
    {
        BREAK_ASSERT(false);
    }
    // Configure analog filter
    if (HAL_I2CEx_ConfigAnalogFilter(&system_i2c_handle, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
    {
        BREAK_ASSERT(false);
    }

    // Configure Digital filter
    if (HAL_I2CEx_ConfigDigitalFilter(&system_i2c_handle, 0) != HAL_OK)
    {
        BREAK_ASSERT(false);
    }
}

static void mx_system_i2c_deinit(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    GPIO_InitStruct.Pin  = I2C1_SYS_SCL_Pin | I2C1_SYS_SDA_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(I2C1_SYS_SCL_GPIO_Port, &GPIO_InitStruct);

    if (HAL_I2C_STATE_RESET != HAL_I2C_GetState(&system_i2c_handle))
    {
        HAL_I2C_DeInit(&system_i2c_handle);
    }
}

static void mx_sensors_i2c_init(void)
{
    sensors_i2c_handle.Instance              = SENSORS_I2C;
    sensors_i2c_handle.Init.Timing           = MX_I2C_TIMING_REG_VAL_DEFAULT;
    sensors_i2c_handle.Init.OwnAddress1      = MX_I2C_OWN_ADDR_DEFAULT;
    sensors_i2c_handle.Init.AddressingMode   = I2C_ADDRESSINGMODE_7BIT;
    sensors_i2c_handle.Init.DualAddressMode  = I2C_DUALADDRESS_DISABLE;
    sensors_i2c_handle.Init.OwnAddress2      = MX_I2C_OWN_ADDR_DEFAULT;
    sensors_i2c_handle.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
    sensors_i2c_handle.Init.GeneralCallMode  = I2C_GENERALCALL_DISABLE;
    sensors_i2c_handle.Init.NoStretchMode    = I2C_NOSTRETCH_DISABLE;

    if (HAL_I2C_Init(&sensors_i2c_handle) != HAL_OK)
    {
        BREAK_ASSERT(false);
    }

    // Configure Analog filter
    if (HAL_I2CEx_ConfigAnalogFilter(&sensors_i2c_handle, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
    {
        BREAK_ASSERT(false);
    }

    // Configure Digital filter
    if (HAL_I2CEx_ConfigDigitalFilter(&sensors_i2c_handle, 0) != HAL_OK)
    {
        BREAK_ASSERT(false);
    }
}

static void mx_sensors_i2c_deinit(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    GPIO_InitStruct.Pin  = I2C2_SEN_SCL_Pin | I2C2_SEN_SDA_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(I2C2_SEN_SCL_GPIO_Port, &GPIO_InitStruct);

    if (HAL_I2C_STATE_RESET != HAL_I2C_GetState(&sensors_i2c_handle))
    {
        HAL_I2C_DeInit(&sensors_i2c_handle);
    }
}

static void mx_payload_i2c_init(void)
{
    payload_i2c_handle.Instance              = PAYLOAD_I2C;
    payload_i2c_handle.Init.Timing           = MX_I2C_TIMING_REG_VAL_DEFAULT;
    payload_i2c_handle.Init.OwnAddress1      = MX_I2C_OWN_ADDR_DEFAULT;
    payload_i2c_handle.Init.AddressingMode   = I2C_ADDRESSINGMODE_7BIT;
    payload_i2c_handle.Init.DualAddressMode  = I2C_DUALADDRESS_DISABLE;
    payload_i2c_handle.Init.OwnAddress2      = MX_I2C_OWN_ADDR_DEFAULT;
    payload_i2c_handle.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
    payload_i2c_handle.Init.GeneralCallMode  = I2C_GENERALCALL_DISABLE;
    payload_i2c_handle.Init.NoStretchMode    = I2C_NOSTRETCH_DISABLE;

    if (HAL_I2C_Init(&payload_i2c_handle) != HAL_OK)
    {
        BREAK_ASSERT(false);
    }

    // Configure Analog filter
    if (HAL_I2CEx_ConfigAnalogFilter(&payload_i2c_handle, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
    {
        BREAK_ASSERT(false);
    }

    // Configure Digital filter
    if (HAL_I2CEx_ConfigDigitalFilter(&payload_i2c_handle, 0) != HAL_OK)
    {
        BREAK_ASSERT(false);
    }
}

static void mx_payload_i2c_deinit(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    GPIO_InitStruct.Pin  = I2C3_PAY_SCL_Pin | I2C3_PAY_SDA_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(I2C3_PAY_SCL_GPIO_Port, &GPIO_InitStruct);

    if (HAL_I2C_STATE_RESET != HAL_I2C_GetState(&payload_i2c_handle))
    {
        HAL_I2C_DeInit(&payload_i2c_handle);
    }
}
