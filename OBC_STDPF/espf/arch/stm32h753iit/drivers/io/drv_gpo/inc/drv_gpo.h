/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef DRV_GPO_H_
#define DRV_GPO_H_

/**
 * @addtogroup Drivers
 * @{
 *
 * @defgroup drv_gpo GPO driver
 * @{
 *
 * The gpo driver takes responsibility of:
 *     - initializing the OBC general-purpose outputs from 1 to 8
 *     - setting new default values in NVM
 *     - setting temporary active state for GPO without NVM default update.
 *     - getting all outputs including both NVM default and current active states
 *
 * @file drv_gpo.h
 *
 * @brief OBC general-purpose outputs 1-8 driver interface
 *
 * @}
 * @}
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "fp/obc/v4.1/obc_server/FP_obcProtocolTypes.h"
#include "es_cdef.h"

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
#define OBC_OUT_MAX_COUNT ((uint8_t)7)

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/
/** @brief OBC output bit enumeration */
typedef enum
{
    OBC_OUT_1,
    OBC_OUT_2,
    OBC_OUT_3,
    OBC_OUT_5,
    OBC_OUT_4_6,
    OBC_OUT_7,
    OBC_OUT_8
} gpo_out_t;

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
 * @brief Initialize OBC general-purpose outputs 1-8
 *
 * @note Make sure to call the function after Nvm_Init(), because it loads the default values
 * from the nvm
 */
void drv_gpo_init(void);

/**
 * @brief Sets all GPO ports nvm(default) and/or current(active) state.
 *
 * @param gpo_pins_conf     Structure of all GPOs true/false. True - set to a high voltage level, False - low voltage level.
 *
 * @retval true      Everything is set correctly
 * @retval false     Failed to set GPOs.
 */
bool set_all_gpo_values(OBC_GpoPortsSetStruct_t gpo_pins_conf);

/**
 * @brief Gets all GPO ports nvm(default) and/or current(active) state.
 *
 * @param p_gpo_pins_conf   Pointer to structure for all GPOs true/false. True - set to a high voltage level, False - low voltage level.
 *
 * @retval true     The operation was successful
 * @retval false    Failed to get GPOs states.
 */
bool get_all_gpo_values(OBC_GpoPortsGetStruct_t *p_gpo_pins_conf);

#ifdef __cplusplus
}
#endif

#endif /* DRV_GPO_H_ */
