/**
 * Copyright (c) 2020-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef GNSS_IRQ_H
#define GNSS_IRQ_H

/**
 * @addtogroup Drivers
 * @{
 * @defgroup gnss
 * @{
 * @file gnss_irq.h
 * @}
 * @}
 */

#ifdef __cplusplus
extern "C" {
#endif

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/
/**
 * @brief process an interrupt in the UART peripheral
 */
void gnss_irq_uart_handler(void);

/**
 * @brief process an interrupt in the DMA peripheral
 */
void gnss_irq_dma_handler(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* GNSS_IRQ_H */
