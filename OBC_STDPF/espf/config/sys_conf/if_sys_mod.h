/*
 * Copyright (c) 2020-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef ESPF_CONFIG_SYS_INSTANCER_IF_SYS_MOD_H_
#define ESPF_CONFIG_SYS_INSTANCER_IF_SYS_MOD_H_

/**
 * @addtogroup sys_instancer
 * @{
 *
 * @file    if_sys_mod.h
 * @brief   System Module interface definition
 *
 * @}
 *
 */

#include "sys_instancer_ct.h"
#include "if_sys_conf.h"
#include "main.h"

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
/** @brief Interface for the sys_instancer to interact with the modules */
typedef struct
{
    mod_op_status_id_t (*init)(sys_init_level_id_t level);   /**> initialize the module */
    mod_op_status_id_t (*run)(void);                         /**> start running the module */
    mod_op_status_id_t (*stop)(void);                        /**> stop running the module */
    mod_op_status_id_t (*deinit)(sys_init_level_id_t level); /**> deinitialize the module */

} if_sys_mod_t;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/
/** @brief List of all possible active modules */
extern if_sys_mod_t *g_p_modules_interface_list[SYS_MODULE_ID_MAX];

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

#ifdef __cplusplus
}
#endif
#endif /* ESPF_CONFIG_SYS_INSTANCER_IF_SYS_MOD_H_ */
