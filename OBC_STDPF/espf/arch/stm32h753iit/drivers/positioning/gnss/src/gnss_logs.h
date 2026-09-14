/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef GNSS_LOGS_H
#define GNSS_LOGS_H

/**
 * @defgroup gnss
 * @{
 *
 * @file gnss_logs.h
 * @brief gnss log module interface
 *
 * @}
 */

#include "es_cdef.h"
#include "gnss_uart.h"

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
 * @brief configure all logs
 * @retval true if all logs are configured successfully
 * @retval false if any log configuration failed
 */
bool configure_all_logs(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* GNSS_LOGS_H */
