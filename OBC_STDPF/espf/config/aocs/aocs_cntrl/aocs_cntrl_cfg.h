/*
 * Copyright (c) 2020-2023 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef __AOCS_CNTRL_CFG_H__
#define __AOCS_CNTRL_CFG_H__

/**
 * @addtogroup aocs_cntrl
 * @{
 *
 * @file     aocs_cntrl_cfg.h
 * @brief    AOCS control service configuration
 *
 * @}
 */

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

#include <stdint.h>
#include "if_aocs_cntrl.h"

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/

/* @brief Period of the main task of AOCS control service */
#define AOCS_CNTRL_TASK_PERIOD_MS (1000U)

/* @brief Maximum number of retires to set a new AOCS system state */
#define AOCS_SYS_STATE_REQ_MAX_RETRIES (3U)

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/* @brief Enumeration of all the supported AOCS types */
typedef enum
{
    AOCS_CNTRL_TYPE_CUBEADCS,
#if defined(CUBEADCS_GEN2_ENABLED)
    AOCS_CNTRL_TYPE_CUBEADCS_GEN2,
#endif
    AOCS_CNTRL_TYPE_MAX

} aocs_cntrl_types_t;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/
/* @brief AOCS control configuration array */
extern const aocs_cntrl_base_cfg_t aocs_cntrl_cfg[AOCS_CNTRL_TYPE_MAX];

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

/* @brief Gets the enabled aocs as per the system configuration and returns the relevant AOCS type in the cfg enum
 *
 * @return the enabled AOCS type
 */
aocs_cntrl_types_t get_enabled_aocs_type(void);

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #ifndef __AOCS_CNTRL_CFG_H__
