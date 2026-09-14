
/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup fdir_srv
 * @{
 *
 * @file     fdir_srv_internal.h
 * @brief    File containing internal definitions for the FDIR service API
 *
 * @}
 */


#ifndef FDIR_SRV_INTERNAL_H
#define FDIR_SRV_INTERNAL_H

#include "fdir_srv_cfg.h"
#include <stdint.h>

/**
 *  @brief Array of dynamic data objects for all faults in the system
 */
extern fdir_fault_dyn_t fdir_faults_dyn[FDIR_FAULT_COUNT];


#endif // FDIR_SRV_INTERNAL_H
