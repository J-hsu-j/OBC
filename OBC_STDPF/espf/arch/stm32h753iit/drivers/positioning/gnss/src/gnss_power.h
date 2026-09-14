/**
 * Copyright (c) 2020-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef GNSS_POWER_H
#define GNSS_POWER_H

/**
 * @addtogroup Drivers
 * @{
 * @defgroup gnss
 * @{
 * @file gnss_power.h
 * @}
 * @}
 */

#include "es_cdef.h"

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
 * @brief power on gnss
 */
void gnss_power_on(void);

/**
 * @brief power off gnss
 */
void gnss_power_off(void);

/**
 * @brief check if gnss powered on or off
 *
 * @retVal true  gnss is powered on
 * @retVal false gnss is powered off
 */
bool gnss_power_is_on(void);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // GNSS_POWER_H
