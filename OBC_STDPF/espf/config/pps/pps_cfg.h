/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef PPS_CFG_H
#define PPS_CFG_H

/**
 * @addtogroup Drivers
 * @{
 *
 * @defgroup pps
 * @{
 *
 * @file pps_cfg.h
 * @brief pps driver configuration
 *
 * @}
 * @}
 */

#include "stm32h7xx_hal.h"
#include "stm32h7xx_hal_gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @brief PPS signal characteristics */
#define PPS_PIN        GPIO_PIN_8             /* pps pin */
#define PPS_PIN_NUMBER (8U)                   /* pps pin number */
#define PPS_PIN_PORT   GPIOF                  /* pps port */
#define PPS_POLARITY   GPIO_MODE_IT_FALLING   /* pps polarity */
#define PPS_IRQ        EXTI9_5_IRQn           /* pps irq */
#define PPS_GPIO_SPEED GPIO_SPEED_FREQ_MEDIUM /* pps gpio init speed */
#define PPS_ALTERNATE  (0U)                   /* pps gpio init alternate */

#define PPS_INPUT_MODE      (0U) /* GPIO MODER (input mode) */
#define PPS_PULLUP_CONFIG   (1U) /* GPIO PUPDR (pull-up) */
#define PPS_PULLDOWN_CONFIG (2U) /* GPIO PUPDR (pull-down) */

#ifdef PPS_POLARITY
#if PPS_POLARITY == GPIO_MODE_IT_FALLING
#define PPS_PP GPIO_PULLUP
#elif PPS_POLARITY == GPIO_MODE_IT_RISING
#define PPS_PP GPIO_PULLDOWN
#endif
#endif

#ifndef PPS_PP
#error "PPS polarity not defined!"
#endif

/** @brief PPS signal timer characteristics */
#define PPS_TIMER           TIM2          /* pps timer */
#define PPS_TIMER_RES       (1000000U)    /* pps timer resolution [us] */
#define PPS_TIMER_PERIOD    (0xFFFFFFFFU) /* pps timer period */
#define PPS_TIMER_PRESCALER (0U)          /* pps timer init prescaler */
#define PPS_TIMER_REPCOUNT  (0U)          /* pps timer init repetition counter */

/** @brief pps detection timeout timer value */
#define PPS_DETECT_TIMEOUT_MS (1100U) /* pps detection timeout [ms] */

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // PPS_CFG_H
