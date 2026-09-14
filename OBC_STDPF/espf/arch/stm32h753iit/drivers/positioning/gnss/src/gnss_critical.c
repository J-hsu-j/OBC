/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup gnss
 * @{
 * @file gnss_critical.c
 * @brief gnss synchronization primitive definition
 * @}
 */

#include "trace.h"
#include "cmsis_os2.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/
/** @brief gnss synchronization primitive (mutex) */
static osMutexId_t gnss_op_lock = NULL;

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
bool gnss_critical_is_init(void)
{
    return (NULL == gnss_op_lock) ? false : true;
}

void gnss_critical_init(void)
{
    if (NULL == gnss_op_lock)
    {
        osMutexAttr_t gnss_op_lock_attr = {
            .name      = "gnss_op_lock",
            .cb_mem    = NULL,
            .cb_size   = 0U,
            .attr_bits = (osMutexRecursive | osMutexPrioInherit)
        };

        gnss_op_lock = osMutexNew(&gnss_op_lock_attr);

        if (NULL == gnss_op_lock)
        {
            ES_TRACE_ERROR("gnss> mutex init failure");
        }
    }
}

bool gnss_critical_enter(uint32_t lock_timeout_ms)
{
    bool op_res = false;

    if (osOK == osMutexAcquire(gnss_op_lock, lock_timeout_ms))
    {
        op_res = true;
    }

    return op_res;
}

void gnss_critical_exit(void)
{
    (void)osMutexRelease(gnss_op_lock);
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
