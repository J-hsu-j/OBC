/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef PPS_IRQ_H
#define PPS_IRQ_H

/**
 * @addtogroup Drivers
 * @{
 *
 * @defgroup pps
 * @{
 *
 * @file pps_irq.h
 *
 *
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
/* No External defines*/

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/
/* No External types declarations */

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/
/* No External variables declarations */

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/
/**
 * @brief PPS signal IRQ handler
 * @note  triggers on PPS signal detection
 */
void pps_irq_handler(void);

#ifdef __cplusplus
}
#endif

#endif // PPS_IRQ_H
