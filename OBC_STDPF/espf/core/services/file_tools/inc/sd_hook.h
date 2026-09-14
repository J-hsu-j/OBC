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
 * @file sd_hook.h
 *
 * @brief Callback function for the SD Card detection pin hardware change interrupt and hardware pin macro alias.
 *
 * @}
 *
 */

#ifndef SD_HOOK_H
#define SD_HOOK_H

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/

/**
 * @brief The port for the SD Card power pin.
 */
#define SD_GPIO_POWER GPIOD

/**
 * @brief The number in the GPIO port for the SD Card power pin.
 */
#define SD_PIN_POWER GPIO_PIN_3

/**
 * @brief The port for the SD Card detection pin.
 */
#define SD_GPIO_DETECT GPIOG

/**
 * @brief The number in the GPIO port for the SD Card detection pin.
 */
#define SD_PIN_DETECT GPIO_PIN_15

/**
 * @brief The port for the SD Card data pins.
 */
#define SD_GPIO_DATA GPIOC

/**
 * @brief The port for the SD Card clock pin.
 */
#define SD_GPIO_CLK GPIOC

/**
 * @brief The number in the GPIO port for the SD Card clock pin.
 */
#define SD_PIN_CLK GPIO_PIN_12

/**
 * @brief The port for the SD Card command pin.
 */
#define SD_GPIO_CMD GPIOD

/**
 * @brief The number in the GPIO port for the SD Card command pin.
 */
#define SD_PIN_CMD GPIO_PIN_2

/**
 * @brief The number in the GPIO port for the SD Card data 0 pin.
 */
#define SD_PIN_D0 GPIO_PIN_8

/**
 * @brief The number in the GPIO port for the SD Card data 1 pin.
 */
#define SD_PIN_D1 GPIO_PIN_9

/**
 * @brief The number in the GPIO port for the SD Card data 2 pin.
 */
#define SD_PIN_D2 GPIO_PIN_10

/**
 * @brief The number in the GPIO port for the SD Card data 3 pin.
 */
#define SD_PIN_D3 GPIO_PIN_11

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

void sd_card_presence_change_notify_isr(void);

#endif /* SD_HOOK_H */
