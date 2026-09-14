/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef FDIR_SRV_TYPES_H
#define FDIR_SRV_TYPES_H

/**
 * @addtogroup fdir_srv
 * @{
 *
 * @file     fdir_srv_types.h
 * @brief    FDIR service common types
 *
 * @}
 */

#include "es_cdef.h"

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

/**
 *  @brief Dynamic data of a fault detectable by an FDIR agent
 */
typedef struct
{
    bool    fault_active;   /**< Indicates if the fault is present in the system */
    uint8_t fdir_level_dyn; /**< The current contribution of the fault to its agent FDIR level*/
} fdir_fault_dyn_t;

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

#endif /* FDIR_SRV_TYPES_H */
