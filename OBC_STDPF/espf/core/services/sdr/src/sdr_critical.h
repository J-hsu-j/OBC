/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef SDR_CRITICAL_H
#define SDR_CRITICAL_H

/**
 * @addtogroup sdr
 * @{
 *
 * @file sdr_critical.h
 * @brief sdr synchronization primitive public interface
 *
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
 * @brief Initialize sdr synchronization primitive
 * @return bool
 */
void sdr_critical_init(void);

/**
 * @brief Enter sdr critical section
 * @param[in] lock_timeout_ms timeout in ms to wait for the lock
 * @return bool
 */
bool sdr_critical_enter(uint32_t lock_timeout_ms);

/**
 * @brief Exit sdr critical section
 */
void sdr_critical_exit(void);

/**
 * @brief Check if sdr synchronization primitive is initialized
 * @return bool
 */
bool sdr_critical_is_init(void);

#ifdef __cplusplus
}
#endif

#endif /* SDR_CRITICAL_H */
