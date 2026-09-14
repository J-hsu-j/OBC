/*
 * Copyright (c) 2020-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup sys_instancer
 * @{
 *
 * @file    sys_mod.c
 * @brief   Interfaces of the modules defined during the runtime configuration (sys_conf).
 *
 * @}
 *
 */

#include "if_sys_mod.h"
#include <eps_i.h>
#include <eps_ii.h>
#include <eps_iii.h>
#include <eps_m.h>
#include <cubeadcs.h>
#include <S_X_Band_Trnsm.h>
#include <sp_service.h>

#if defined(CUBEADCS_GEN2_ENABLED)
#include <cubeObc_config.h>
#endif

#if defined(GNSS_ENABLED)
#include "gnss.h"
#endif

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

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

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
/** @brief To avoid some problems when running without providing a full sys_mod interface */
if_sys_mod_t null_sys_mod = { NULL, NULL, NULL, NULL };

/** @brief List of the modules interface to interact with the sys_instancer */
if_sys_mod_t *g_p_modules_interface_list[SYS_MODULE_ID_MAX] = {
    &eps_i_module_configuration,     // SYS_MODULE_ID_EPS_I,
    &eps_ii_module_configuration,    // SYS_MODULE_ID_EPS_II,
    &eps_m_module_configuration,     // SYS_MODULE_ID_EPS_M,
    &cube_adcs_module_configuration, // SYS_MODULE_ID_CUBE_ADCS,
#if defined(GNSS_ENABLED)
    &gnss_module_configuration, // SYS_MODULE_ID_GNSS,
#else
    &null_sys_mod, // SYS_MODULE_ID_GNSS,
#endif
    &sx_band_module_configuration, // SYS_MODULE_SXBAND,
    &sp_module_configuration,      // SYS_MODULE_SP
#if defined(CUBEADCS_GEN2_ENABLED)
    &cube_adcs_g2_module_configuration, // SYS_MODULE_ID_CUBE_ADCS_GEN2
#else
    &null_sys_mod, // SYS_MODULE_ID_CUBE_ADCS_GEN2
#endif
    &eps_iii_module_configuration // SYS_MODULE_ID_EPS_III,
};

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

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
