/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef SDR_PL_CTRL_H
#define SDR_PL_CTRL_H
/**
 * @addtogroup sdr
 * @{
 *
 * Declaration of the SDR payload controller interface
 *
 * @file sdr_pl_ctrl.h
 * @brief SDR payload controller public interface
 *
 * @}
 */

#include "if_payload_control.h"
#include "sdr.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

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
/** Control interface for the SDR payload */
extern const pl_control_if_t sdr_pl_ctrl_if;

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SDR_PL_CTRL_H */
