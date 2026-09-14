/*
 * payload_communication.c
 *
 * Simple PAY1 UART6 transmitter for bench testing.
 * Sends 0xAA continuously over USART6 (TX on PC6) so an external tool
 * can verify the payload-side RS422/RS485 transceiver path.
 *
 * Architecture follows uhf_app.c pattern:
 * - Static thread handle and attributes
 * - payload_comm_init() called from main.c before osKernelStart()
 * - Task function runs the continuous TX loop
 */

#include "payload_communication.h"
#include "main.h"
#include "cmsis_os2.h"
#include "stm32h7xx_hal.h"

#include "MCU_Init.h"
#include "drv_led.h"

// ============================================================================
// Thread handle and attributes (與 uhf_app.c 風格一致)
// ============================================================================
static osThreadId_t payload_comm_task_handle;
static const osThreadAttr_t payload_comm_task_attributes = {
    .name       = "PayComm",
    .priority   = (osPriority_t)osPriorityNormal,
    .stack_size = 128 * 16
};

// ============================================================================
// UART handle
// ============================================================================
static UART_HandleTypeDef g_payload_uart6;

// ============================================================================
// Forward declarations
// ============================================================================
static void payload_comm_task(void *argument);
static void fs_uart6_rs422_enable(void);
static void fs_uart6_init(uint32_t baudrate);

// ============================================================================
// Public API: payload_comm_init() - 在 main.c 的 osKernelStart() 前呼叫
// ============================================================================
void payload_comm_init(void)
{
    payload_comm_task_handle = osThreadNew(payload_comm_task, NULL, &payload_comm_task_attributes);
}

// ============================================================================
// RS-422 transceiver enable (DE/nRE control)
// ============================================================================
static void fs_uart6_rs422_enable(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // 設定 PAY1 的 transceiver 控制腳（DE / nRE）到可發送狀態
    __HAL_RCC_GPIOG_CLK_ENABLE();  // HS2 DE/nRE 在 GPIOG (reference_NCYU)

    // Configure DE and nRE pins as output
    GPIO_InitStruct.Pin = RS422_HS2_DE_UART6_PAY1_Pin | RS422_HS2_nRE_UART6_PAY1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(RS422_HS2_DE_UART6_PAY1_GPIO_Port, &GPIO_InitStruct);

    // DE = HIGH (enable TX driver), nRE = HIGH (disable receiver)
    HAL_GPIO_WritePin(RS422_HS2_DE_UART6_PAY1_GPIO_Port, RS422_HS2_DE_UART6_PAY1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(RS422_HS2_nRE_UART6_PAY1_GPIO_Port, RS422_HS2_nRE_UART6_PAY1_Pin, GPIO_PIN_SET);
    
    osDelay(1);  // 切換後等 1ms 讓 transceiver 穩定
}

// ============================================================================
// UART6 initialization (TX only)
// ============================================================================
static void fs_uart6_init(uint32_t baudrate)
{
    g_payload_uart6.Instance = USART6;
    g_payload_uart6.Init.BaudRate = baudrate;
    g_payload_uart6.Init.WordLength = UART_WORDLENGTH_8B;
    g_payload_uart6.Init.StopBits = UART_STOPBITS_1;
    g_payload_uart6.Init.Parity = UART_PARITY_NONE;
    g_payload_uart6.Init.Mode = UART_MODE_TX;
    g_payload_uart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    g_payload_uart6.Init.OverSampling = UART_OVERSAMPLING_16;
    g_payload_uart6.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
    g_payload_uart6.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;

    if (HAL_UART_Init(&g_payload_uart6) != HAL_OK)
    {
        Error_Handler();
    }
}

// ============================================================================
// Task function: 持續發送 0xAA
// ============================================================================
static void payload_comm_task(void *argument)
{
    (void)argument;
    
    const uint32_t baudrate = 115200U;
    const uint32_t gap_ms = 1000U;

    // DEBUG - 進入 task 時閃 AMBER LED 3 次
    for (int i = 0; i < 3; i++)
    {
        drv_led_set(DRV_LED_ID_AMBER, DRV_LED_STATE_ON);
        osDelay(200);
        drv_led_set(DRV_LED_ID_AMBER, DRV_LED_STATE_OFF);
        osDelay(200);
    }

    fs_uart6_rs422_enable();
    
    // DEBUG - RS422 enable 完成後閃 GREEN LED 2 次
    for (int i = 0; i < 2; i++)
    {
        drv_led_set(DRV_LED_ID_GREEN, DRV_LED_STATE_ON);
        osDelay(200);
        drv_led_set(DRV_LED_ID_GREEN, DRV_LED_STATE_OFF);
        osDelay(200);
    }

    fs_uart6_init(baudrate);

    // DEBUG - UART init 完成後閃 AMBER + GREEN 同時亮 2 次
    for (int i = 0; i < 2; i++)
    {
        drv_led_set(DRV_LED_ID_AMBER, DRV_LED_STATE_ON);
        drv_led_set(DRV_LED_ID_GREEN, DRV_LED_STATE_ON);
        osDelay(200);
        drv_led_set(DRV_LED_ID_AMBER, DRV_LED_STATE_OFF);
        drv_led_set(DRV_LED_ID_GREEN, DRV_LED_STATE_OFF);
        osDelay(200);
    }

    static const char pattern[] = "PYRAS";  // 6 bytes: P Y R A S \0

    while (1)
    {
        HAL_UART_Transmit(&g_payload_uart6,
                        (uint8_t *)pattern,
                        5U,          // 只送 P Y R A S，不送 '\0'
                        gap_ms);

        drv_led_toggle(DRV_LED_ID_GREEN);
        osDelay(gap_ms);
    }
}
