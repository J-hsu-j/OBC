/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup sdr
 * @{
 *
 * @file sdr_critical.c
 * @brief sdr synchronization primitive definition
 *
 * @}
 *
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

/* sdr synchronization primitive (mutex) variable */
static osMutexId_t sdr_op_lock = NULL;

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
bool sdr_critical_is_init(void)
{
    return (NULL == sdr_op_lock) ? false : true;
}

void sdr_critical_init(void)
{
    if (NULL == sdr_op_lock)
    {
        osMutexAttr_t sdr_op_lock_attr = {
            .name      = "sdr_op_lock",
            .cb_mem    = NULL,
            .cb_size   = 0U,
            .attr_bits = (osMutexRecursive | osMutexPrioInherit)
        };

        sdr_op_lock = osMutexNew(&sdr_op_lock_attr);

        if (NULL == sdr_op_lock)
        {
            ES_TRACE_ERROR("sdr> mutex init failure");
        }
    }
}

bool sdr_critical_enter(uint32_t lock_timeout_ms)
{
    bool op_res = false;

    if (osOK == osMutexAcquire(sdr_op_lock, lock_timeout_ms))
    {
        op_res = true;
    }

    return op_res;
}

void sdr_critical_exit(void)
{
    (void)osMutexRelease(sdr_op_lock);
}
/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
