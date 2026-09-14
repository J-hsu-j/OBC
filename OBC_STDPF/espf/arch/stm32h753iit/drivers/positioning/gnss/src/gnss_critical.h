/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef GNSS_CRITICAL_H
#define GNSS_CRITICAL_H

/**
 * @addtogroup gnss
 * @{
 *
 * @file gnss_critical.h
 * @brief gnss synchronization primitive public interface
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
 * @brief initialize gnss synchronization primitive
 * @return bool
 */
void gnss_critical_init(void);

/**
 * @brief enter gnss critical section
 * @param[in] lock_timeout_ms timeout in ms to wait for the lock
 * @retval true if lock acquisition succeeded
 * @retval false if lock acquisition failed
 */
bool gnss_critical_enter(uint32_t lock_timeout_ms);

/**
 * @brief exit gnss critical section
 */
void gnss_critical_exit(void);

/**
 * @brief check if gnss synchronization primitive is initialized
 * @retval true if initialized
 * @retval false if not initialized
 */
bool gnss_critical_is_init(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* GNSS_CRITICAL_H */
