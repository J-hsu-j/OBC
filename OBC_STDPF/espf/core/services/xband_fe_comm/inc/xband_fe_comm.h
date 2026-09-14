/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef XBAND_FE_COMM_H
#define XBAND_FE_COMM_H

/**
 * @defgroup xband_fe_comm Template Group
 * @{
 *
 * This file contains the public interface of the X-Band Front End communication module.
 *
 * @file xband_fe_comm.h
 * @brief xband_fe_comm public interface
 *
 * @}
 */

#include "if_payload_control.h"

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

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/
/** Control interface for the XBand FE payload */
extern const pl_control_if_t xband_fe_pl_ctrl_if;

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

#ifdef __cplusplus
}
#endif

#endif /* XBAND_FE_COMM_H */
