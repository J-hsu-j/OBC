/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef CONOPS_CFG_H
#define CONOPS_CFG_H
/**
 * @addtogroup app_conops
 * @{
 *
 * @file conops_cfg.h
 * @brief Concept of operations compile-time configuration
 *
 * @}
 *
 */

#include "trace.h"
#include "conops_sm_user.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
********************************************************************************************
* EXTERNAL DEFINES
********************************************************************************************
*/

/** @brief Trace prefix marking results of testing conditions */
#define CONOPS_SM_TEST_COND "[TEST_COND]"

/** @brief Period in ms of the main task of ConOps */
#define CONOPS_PER_EV_TASK_PERIOD (1000U)

/** @brief Size in bytes of the stack to be allocated to the main ConOps task */
#define CONOPS_PER_EV_TASK_STACK_SIZE (2048)

/*
 * @brief If in Y-Thomson, the X and Z should be contained within +1:-1 range.
 *        This value corresponds to the "1" (~ 1 deg/s, or 17 mRad/s)
 */
#define CONOPS_ADCS_Y_THOMSON_POS_THRESH_MRAD_S ((int16_t)0x0011)

/*
 * @brief See description of @ref CONOPS_ADCS_Y_THOMSON_POS_THRESH_MRAD_S.
 * This value corresponds to the "-1" (~ -1 deg/s, or -17 mRad/s).
 */
#define CONOPS_ADCS_Y_THOMSON_NEG_THRESH_MRAD_S ((int16_t)0xFFEF)

/*
********************************************************************************************
* EXTERNAL TYPES DECLARATIONS
********************************************************************************************
*/

/*
********************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
********************************************************************************************
*/

/*
********************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
********************************************************************************************
*/

#ifdef __cplusplus
}
#endif

#endif /* CONOPS_CFG_H */
/* ******************************************************************************************* */
