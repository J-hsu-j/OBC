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
 * @file     esps_drv_config.c
 * @brief    Configuration for the ESPS I MAC Driver
 *
 * @}
 */

#include <string.h>
#include <assert.h>
#if defined(COMM_GW_ENABLED)
#include "core/services/comm_gw/inc/comm_gw_fp.h"
#endif
#include "esps_drv_config.h"
#include "esps_drv_dispatcher_thread.h"
#include "es_mac_notif.h"
#include "nvm/inc/nvm.h"
#include "FP_common/FP_BaseProtocolTypes.h"
#include "taskmon.h"

#include "esps_drv_debug.h"
#include "esps_drv.h"
#include "assertions.h"
#if defined(MICROPYTHON_SERVICE_ENABLED)
#include "upy_cfg.h"
#endif

#define RS485_TX_Pin        GPIO_PIN_9
#define RS485_TX_GPIO_Port  GPIOA
#define RS485_RX_Pin        GPIO_PIN_10
#define RS485_RX_GPIO_Port  GPIOA
#define RS485_nRE_Pin       GPIO_PIN_11
#define RS485_nRE_GPIO_Port GPIOA
#define RS485_DE_Pin        GPIO_PIN_12
#define RS485_DE_GPIO_Port  GPIOA
#define RS485_TE_Pin        GPIO_PIN_12
#define RS485_TE_GPIO_Port  GPIOD

// Interrupt to MAC device mapping configuration
#define MAC_USART1_DEVICE (eMAC_Interface_Primary)

static void fs_Uart1Init(const sMACConfig_t *cfg);
static void fs_Uart1Deinit(const sMACConfig_t *const cfg);
static void fs_vRS485DriverEnable(void);
static void fs_vRS485DriverDisable(void);
static void fs_vRS485ReceptionEnable(void);
static void fs_vRS485ReceptionDisable(void);

static UART_HandleTypeDef huart1;

static const sMACInterfaceImmutableConfig_t fs_MacConfig[eMAC_Interface_Count] = {
    {.pfEnableTX   = fs_vRS485DriverEnable,
     .pfDisableTX  = fs_vRS485DriverDisable,
     .pfEnableRX   = fs_vRS485ReceptionEnable,
     .pfDisableRX  = fs_vRS485ReceptionDisable,
     .pfUartInit   = fs_Uart1Init,
     .pfUartDeinit = fs_Uart1Deinit,
     .sHwConfig    = {
             .psUART       = USART1,
             .u32Baudrate  = MAC_DEFAULT_BAUDRATE,
             .u16TQVal     = MAC_DEFAULT_TQ,
             .u32NVICMask  = USART1_IRQn,
             .u32RCCMask   = RCC_APB2ENR_USART1EN,
             .eClockSource = eRCCPeripheralClock_APB2,
             .eTXTIMID     = eTIM_TIM16_ID,
             .eRXTIMID     = eTIM_TIM17_ID,
      }},
};

static sMACInterfaceState_t fs_asMACStates[eMAC_Interface_Count] = {
    {// NOSONAR
      .macIfId                  = eMAC_Interface_Primary,
     .u16Address               = MAC_DEFAULT_ADDRESS_PRI,
     .psCfg                    = &fs_MacConfig[eMAC_Interface_Primary],
     .bInitDone                = false,
     .u8BasePrio               = MAC_DEFAULT_BASEPRIO,
     .criticalSectionNestLevel = 0U},
};

// Return the MAC Interface for a given ESSA Stack ID
eMACInterface_t MacCfg_eGetMacDrvIf(ESSASNetInterface netIfId)
{
    eMACInterface_t macDrvIf;

    switch (netIfId) // NOSONAR
    {
        case ESSASNI_SYS_PRI:
            macDrvIf = eMAC_Interface_Primary;
            break;

        default:
            macDrvIf = eMAC_Interface_Count;
            break;
    }

    return macDrvIf;
}

// Returns the ESSA Stack ID of the interface for a given MAC Interface
uint8_t MacCfg_u8GetStackIfId(eMACInterface_t macIf)
{
    uint8_t stackIfId;

    switch (macIf) // NOSONAR
    {
        case eMAC_Interface_Primary:
            stackIfId = ESSASNI_SYS_PRI;
            break;

        default:
            stackIfId = 0xFF;
            break;
    }

    return stackIfId;
}

sMACInterfaceState_t *MacCfg_sGetMacInterfaceById(const eMACInterface_t macId)
{
    return (macId < eMAC_Interface_Count) ? &fs_asMACStates[macId] : NULL;
}

static void fs_vRS485DriverEnable(void)
{
    // RTS ACTIVE (Driver Enable)
    HAL_GPIO_WritePin(RS485_DE_GPIO_Port, RS485_DE_Pin, GPIO_PIN_SET);
}

static void fs_vRS485DriverDisable(void)
{
    // RTS INACTIVE (Driver Disable)
    HAL_GPIO_WritePin(RS485_DE_GPIO_Port, RS485_DE_Pin, GPIO_PIN_RESET);
}

static void fs_vRS485ReceptionEnable(void)
{
    // RE ACTIVE (Receive Enable)
    HAL_GPIO_WritePin(RS485_nRE_GPIO_Port, RS485_nRE_Pin, GPIO_PIN_RESET);
}

static void fs_vRS485ReceptionDisable(void)
{
    // RE INACTIVE (Receive Disable)
    HAL_GPIO_WritePin(RS485_nRE_GPIO_Port, RS485_nRE_Pin, GPIO_PIN_SET);
}

void MacCfg_vSetBusTerminationState(const eMACInterface_t eMacIf, const bool bNewState, const bool bPersistSetting)
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };
    bool             bSettingIsValid = true;

    switch (eMacIf) // NOSONAR
    {
        case eMAC_Interface_Primary:
            {
                // - RS4xx_HS1_TE
                __HAL_RCC_GPIOD_CLK_ENABLE();

                /* Configure GPIO pin : RS485_TE_Pin */
                GPIO_InitStruct.Pin   = RS485_TE_Pin;
                GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
                GPIO_InitStruct.Pull  = GPIO_NOPULL;
                GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
                HAL_GPIO_Init(RS485_TE_GPIO_Port, &GPIO_InitStruct);

                HAL_GPIO_WritePin(RS485_TE_GPIO_Port,
                                  RS485_TE_Pin,
                                  (true == bNewState) ? GPIO_PIN_SET : GPIO_PIN_RESET);

                break;
            }

        default:
            {
                bSettingIsValid = false;
                CRIT_ASSERT(false);
                break;
            }
    }
#if defined(COMM_RS485_MAC_LAYER_ENABLED)
    if (bSettingIsValid && bPersistSetting)
    {
        sMacConfig_t macNvmCfg;

        Nvm_GetBlockById(NVM_BLOCK_MACCONFIG, &macNvmCfg);

        if (bNewState)
        {
            macNvmCfg.macDrvConfig.u8MacBusTerminationBitField |= (uint8_t)(0x01U << (uint8_t)eMacIf);
        }
        else
        {
            macNvmCfg.macDrvConfig.u8MacBusTerminationBitField &= (uint8_t) ~(0x01U << (uint8_t)eMacIf);
        }

        Nvm_SetBlockById(NVM_BLOCK_MACCONFIG, &macNvmCfg, NVMSETBLOCK_STORE_IMMEDIATELY);
    }
#endif
}

bool MacCfg_bGetBusTerminationState(const eMACInterface_t eMacIf, const bool bReadPersistentSetting)
{
    GPIO_PinState pinState;
    bool          bBusTerminationState = false;

#if defined(COMM_RS485_MAC_LAYER_ENABLED)
    sMacConfig_t macNvmCfg;

    Nvm_GetBlockById(NVM_BLOCK_MACCONFIG, &macNvmCfg);

    switch (eMacIf) // NOSONAR
    {
        case eMAC_Interface_Primary:
            {
                if (bReadPersistentSetting)
                {
                    bBusTerminationState = (bool)((macNvmCfg.macDrvConfig.u8MacBusTerminationBitField >> ((uint8_t)eMAC_Interface_Primary)) & 0x01U);
                }
                else
                {
                    pinState             = HAL_GPIO_ReadPin(RS485_TE_GPIO_Port, RS485_TE_Pin);
                    bBusTerminationState = (pinState == GPIO_PIN_SET) ? true : false;
                }

                break;
            }

        default:
            {
                CRIT_ASSERT(false);
                break;
            }
    }
#endif

    return bBusTerminationState;
}

void MacCfg_vApplyMacAddrConfig(const eMACInterface_t eMacIf, const uint8_t u8MacAddr)
{
    (void)eMacIf; // provision in case different addresses will be needed in the future
    // apply change to all MAC interfaces
    for (uint8_t u8MacIfId = 0U; u8MacIfId < eMAC_Interface_Count; u8MacIfId++)
    {
        fs_asMACStates[u8MacIfId].u16Address = (uint16_t)u8MacAddr;
    }
}

bool MacCfg_bSetMacAddress(const eMACInterface_t eMacIf, const uint8_t u8MacAddr)
{
    bool bResult = false;
#if defined(COMM_RS485_MAC_LAYER_ENABLED)
    if ((eMacIf < eMAC_Interface_Count) &&
        (u8MacAddr != 0x00U) &&
        (u8MacAddr != ESSATMAC_ADDR_GATEWAY_DEV) &&
        (u8MacAddr != ESSATMAC_ADDR_BROADCAST))
    {
        if (u8MacAddr != MacCfg_u8GetMacAddress(eMacIf))
        {
            sMacConfig_t macNvmCfg;

            Nvm_GetBlockById(NVM_BLOCK_MACCONFIG, &macNvmCfg);
            macNvmCfg.macDrvConfig.u8MacAddress = u8MacAddr;
            Nvm_SetBlockById(NVM_BLOCK_MACCONFIG, &macNvmCfg, NVMSETBLOCK_STORE_IMMEDIATELY);
        }

        // the new setting will be taken into account after OBC reset
        bResult = true;
    }
#endif
    return bResult;
}

uint8_t MacCfg_u8GetMacAddress(const eMACInterface_t eMacIf)
{
    (void)eMacIf;
#if defined(COMM_RS485_MAC_LAYER_ENABLED)
    sMacConfig_t macNvmCfg;

    Nvm_GetBlockById(NVM_BLOCK_MACCONFIG, &macNvmCfg);

    // if for some reason, the persisted address is missing or set to one of the
    // broadcast groups, then use the default MAC SYS1 address
    if ((macNvmCfg.macDrvConfig.u8MacAddress == 0xFFU) ||
        (macNvmCfg.macDrvConfig.u8MacAddress == 0x00U) ||
        (macNvmCfg.macDrvConfig.u8MacAddress == ESSATMAC_ADDR_GATEWAY_DEV) ||
        (macNvmCfg.macDrvConfig.u8MacAddress == ESSATMAC_ADDR_BROADCAST))
    {
        return MAC_SYS1_ADDRESS_PRI;
    }
    else
    {
        return macNvmCfg.macDrvConfig.u8MacAddress;
    }
#endif
}

static void fs_Uart1Init(const sMACConfig_t *cfg)
{
    assert(cfg != NULL);

    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    /* Peripheral clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /**USART1 GPIO Configuration
    PA9    ------> USART1_TX
    PA10   ------> USART1_RX
    PA12   ------> USART1_DE (RTS)
    */
    huart1.Instance                    = USART1;
    huart1.Init.BaudRate               = cfg->u32Baudrate;
    huart1.Init.WordLength             = UART_WORDLENGTH_9B;
    huart1.Init.StopBits               = UART_STOPBITS_1;
    huart1.Init.Parity                 = UART_PARITY_NONE;
    huart1.Init.Mode                   = UART_MODE_TX_RX;
    huart1.Init.HwFlowCtl              = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling           = UART_OVERSAMPLING_16;
    huart1.Init.OneBitSampling         = UART_ONE_BIT_SAMPLE_DISABLE;
    huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;

    if (HAL_UART_Init(&huart1) != HAL_OK)
    {
        Error_Handler();
    }

    GPIO_InitStruct.Pin       = RS485_TX_Pin | RS485_RX_Pin;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(RS485_DE_GPIO_Port, RS485_DE_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(RS485_TE_GPIO_Port, RS485_TE_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(RS485_nRE_GPIO_Port, RS485_nRE_Pin, GPIO_PIN_RESET);

    GPIO_InitStruct.Pin   = RS485_DE_Pin;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(RS485_DE_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pin : RS485_TE_Pin */
    GPIO_InitStruct.Pin   = RS485_TE_Pin;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(RS485_TE_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pin : RS485_nRE_Pin */
    GPIO_InitStruct.Pin   = RS485_nRE_Pin;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(RS485_nRE_GPIO_Port, &GPIO_InitStruct);

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, MAC_UART_ISR_PRIO, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);

    // Receive Enable ACTIVE
    fs_vRS485ReceptionEnable();

    // Termination Enable ACTIVE
    MacCfg_vSetBusTerminationState(eMAC_Interface_Primary, MacCfg_bGetBusTerminationState(eMAC_Interface_Primary, true), true);

    // Start with a disabled communication driver...
    fs_vRS485DriverDisable();
}

static void fs_Uart1Deinit(const sMACConfig_t *cfg)
{
    (void)cfg;
    __HAL_RCC_USART1_CLK_DISABLE();
    // RS485_TX_GPIO_Port and RS485_RX_GPIO_Port are the same, GPIOA
    HAL_GPIO_DeInit(GPIOA, RS485_TX_Pin | RS485_RX_Pin);
    HAL_NVIC_DisableIRQ(USART1_IRQn);
}

// Overriding STM32f startup Exception handler
void USART1_IRQHandler(void);
void USART1_IRQHandler(void)
{
    MAC_vDispatchUARTEvent(&fs_asMACStates[MAC_USART1_DEVICE]);
}

// Overriding STM32f startup Exception handler
void TIM16_IRQHandler(void)
{
    MAC_TIM_IRQ_Handler_Generic(TIM16, eTIM_TIM16_ID);
}

// Overriding STM32f startup Exception handler
void TIM17_IRQHandler(void)
{
    MAC_TIM_IRQ_Handler_Generic(TIM17, eTIM_TIM17_ID);
}

void mac_notif_onevent_cfg(const eMACInterface_t eMacIf, const eMacNotification_t eMacEvent, eventData_t evtData);

//  Called from MAC_bProtocolProcessMessage to be notified on a received frame
void MacCfg_vHandleFrameNotifications(eMACInterface_t fp_eMACId, ESSATMAC_Message *fp_psMsg)
{
    // USER CODE
    switch (fp_psMsg->u8Protocol)
    {
        case ES_SAT_MAC_PROTOCOL_ID_FP_LAYER:
            {
#ifndef BIG_ENDIAN_PLATFORM
                const ESSA_Stack_FP_MsgHdr_t *pFPHeader = (ESSA_Stack_FP_MsgHdr_t *)fp_psMsg->au8Data;
#else
#error Big-endian encoding of the header is not supported currently!
#endif

                // we are interested only in request FP frames
                if ((pFPHeader != NULL) && (true == IS_REQUEST(*pFPHeader)))
                {
                    mac_notif_onevent_cfg(fp_eMACId,
                                          EMACNOTIFICATION_ON_FP_REQ_RCVD,
                                          (eventData_t)fp_psMsg);
                }

                break;
            }

        case ES_SAT_MAC_PROTOCOL_ID_TRANSPORT_LAYER:
            {
                mac_notif_onevent_cfg(fp_eMACId,
                                      EMACNOTIFICATION_ON_TL_FRAME_RCVD,
                                      (eventData_t)fp_psMsg);
                break;
            }

        default:
            mac_notif_onevent_cfg(fp_eMACId,
                                  EMACNOTIFICATION_ON_GEN_FRAME_RCVD,
                                  (eventData_t)fp_psMsg);
            break;
    }
    // END OF USER CODE
    return;
}

void MAC_Stats_getEventsBuffer(eMACInterface_t fp_eMACId,
                               uint8_t *const  pu8UserBuf,
                               uint32_t        u32UserBufSize,
                               uint32_t *const pu32ResponseSize,
                               uint32_t *const pu32EventsCount)
{
    uint32_t user_buf_size = u32UserBufSize;

    if ((pu8UserBuf != NULL) &&
        (user_buf_size > 0U) &&
        (pu32EventsCount != NULL) &&
        (pu32ResponseSize != NULL) &&
        (fp_eMACId < eMAC_Interface_Count))
    {
        if (user_buf_size >= sizeof(macStats_t))
        {
            user_buf_size = sizeof(macStats_t);
        }

        *pu32EventsCount = eMACStatId_MAX;

        taskENTER_CRITICAL();

        (void)memcpy(pu8UserBuf, (const void *)fs_asMACStates[fp_eMACId].macStats, user_buf_size);

        taskEXIT_CRITICAL();

        // size contains also the event count which is part of the returned buffer
        *pu32ResponseSize = sizeof(uint32_t) + sizeof(fs_asMACStates[fp_eMACId].macStats);
    }
}

bool MacCfg_Match_Target_Addr(const uint8_t addr, const eMACInterface_t mac_if)
{
    bool ext_addr_match = false;

#if defined(COMM_GW_ENABLED)
    ext_addr_match = comm_gw_fp_is_valid_vnode_addr(addr);
#endif

    return ((addr == MacCfg_u8GetMacAddress(mac_if)) ||
            (addr == ESSATMAC_ADDR_BROADCAST) ||
            (addr == ESSATMAC_ADDR_GATEWAY_DEV) ||
            (true == ext_addr_match));
}

void custom_esps_data_dispatch(ESSATMAC_Context *pMACContext, const uint8_t *pMsgData, uint8_t nMsgDataSize)
{
    if ((pMACContext == NULL) || (pMsgData == NULL) || (nMsgDataSize == (uint8_t)0))
    {
        return;
    }

#if defined(COMM_GW_ENABLED)
    // if the data was sent in response to a uPy virtual node, route the response directly to the uPy
    // handler instead of handling the frame by the OBC SDK
    if (true == comm_gw_fp_is_valid_vnode_addr(pMACContext->nTargetAddr))
    {
        comm_gw_fp_enq_message(pMACContext, pMsgData, nMsgDataSize);
    }
    else
    {
#endif
        ESSA_Stack_DataDispatch(pMACContext, pMsgData, nMsgDataSize);
#if defined(COMM_GW_ENABLED)
    }
#endif
}

bool MacCfg_vUseAltDispatchForFrame(sMACRXPoolEntry_t *const psMsgEntry)
{
    bool isFpResponse = false;

    if ((NULL != psMsgEntry) && (ES_SAT_MAC_PROTOCOL_ID_FP_LAYER == psMsgEntry->sMessage.u8Protocol))
    {
        const ESSA_Stack_FP_MsgHdr_t *pFPHeader = (ESSA_Stack_FP_MsgHdr_t *)psMsgEntry->sMessage.au8Data;
        isFpResponse                            = IS_RESPONSE(*pFPHeader);
    }

    return isFpResponse;
}
