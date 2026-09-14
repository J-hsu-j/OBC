project(stm32_hal C)

add_library(${PROJECT_NAME} STATIC
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_adc.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_adc_ex.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_cortex.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_dma.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_dma_ex.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_exti.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_fdcan.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_flash.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_flash_ex.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_gpio.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_hsem.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_i2c.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_i2c_ex.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_iwdg.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_mdma.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_pwr.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_pwr_ex.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_rcc.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_rcc_ex.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_rng.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_rng_ex.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_rtc.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_rtc_ex.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_sd.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_sd_ex.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_spi.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_spi_ex.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_tim.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_tim_ex.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_uart.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_uart_ex.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_wwdg.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_ll_delayblock.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_ll_dma.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_ll_exti.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_ll_gpio.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_ll_i2c.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_ll_rcc.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_ll_rtc.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_ll_sdmmc.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_ll_tim.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_ll_usart.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_ll_utils.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_crc.c
    ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_crc_ex.c
)
if(ETHERNET_SUPPORT_ENABLED)
    target_sources(${PROJECT_NAME} PRIVATE
        ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_eth.c
        ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_eth_ex.c
    )
endif(ETHERNET_SUPPORT_ENABLED)

if (SXBAND_CRYPTO_ENABLED)
    target_sources(${PROJECT_NAME} PRIVATE
        ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_cryp.c
        ${PROJECT_SOURCE_DIR}/src/stm32h7xx_hal_cryp_ex.c
    )
endif (SXBAND_CRYPTO_ENABLED)

list(APPEND module_includes
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/cmsis/device/st/stm32h7xx/include
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
