/**
 * Copyright (c) 2020-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef GNSS_H
#define GNSS_H

/**
 * @addtogroup Drivers
 * @{
 * @defgroup gnss
 * @{
 * gnss communication interface
 *
 * @file gnss.h
 * @brief gnss driver
 * @}
 * @}
 */

#include "gnss_types.h"
#include "if_sys_mod.h"
#include "sys_instancer_ct.h"

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
/** @brief configuration interface for the gnss system instancer */
extern if_sys_mod_t gnss_module_configuration;

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/
/**
 * @brief initializes the driver
 * @param[in] level not used
 * @return @ref mod_op_status_id_t
 */
mod_op_status_id_t gnss_init(sys_init_level_id_t level);

/**
 * @brief de-initializes the driver
 * @param[in] level not used
 * @return @ref mod_op_status_id_t
 */
mod_op_status_id_t gnss_deinit(sys_init_level_id_t level);

/**
 * @brief power on
 * @return @ref mod_op_status_id_t
 */
mod_op_status_id_t gnss_run(void);

/**
 * @brief power off
 * @return @ref mod_op_status_id_t
 */
mod_op_status_id_t gnss_stop(void);

/**
 * @brief check if the gnss is powered on or off
 * @retval true  gnss is powered on
 * @retval false gnss is powered off
 */
bool gnss_is_on(void);

/**
 * @brief check if the gnss is ready for communication
 * @retval true gnss is ready
 * @retval false gnss is not ready
 */
bool gnss_comm_is_init(void);

/**
 * @brief check gnss time validity
 * @param[in] tim
 * @retval true  gnss time is valid
 * @retval false gnss time is not valid
 */
bool gnss_is_tm_valid(const gnss_time_t *tim);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* GNSS_H */
