/*
 * Copyright (c) 2023-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup service_file_tools
 * @{
 *
 * @file ff_mng.h
 *
 * @brief Manages interface between fatfs and other obc sw modules
 *
 * @}
 *
 */

#ifndef FF_MNG_H
#define FF_MNG_H

#include "fm_mng_def.h"

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

/**
 * @brief Initialize fatfs wrapper for file_tools
 */
void ff_init(void);

/**
 * @brief Get the default FATFS file object and api. See @ref fm_mng_def.h for the api description
 *
 * @param[out] p_out_api_obj pointer to a fs_api_obj_t object which would store the "handle" to the default api object
 * @param[out] p_out_api pointer to the pointer which will point to the default api methods
 *
 * @return Result of performed operation, @ref fm_result_t
 */
void ff_get_default_api_and_obj(fs_api_obj_t *const p_out_api_obj, const fs_api_t **const p_out_api);

/**
 * @brief Attach a storage device api to an opaque api object
 *
 * @param[in] api_obj an initialized api obj handle which will use the storage driver
 * @param[in] p_in_drv pointer to the storage driver api list to be used by the file system object.
 *
 * @return Result of performed operation, @ref fm_result_t
 */
void ff_set_driver(const fs_api_obj_t api_obj, const fm_storage_api_t *const p_in_drv);

#endif /* FF_MNG_H */
