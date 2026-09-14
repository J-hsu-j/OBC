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
 * @file sd_mng.h
 *
 * @brief File Manager header containing the public API for file operations
 *
 * @}
 */

#ifndef SD_MNG_H
#define SD_MNG_H

#include "fm_mng_def.h"

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

/**
 * Initialize the SD Card module.
 * @details This function must be called before any usage of this module.
 *
 */
void sd_init(void);

/**
 * Register a callback function for when the sd card status changes.
 * @details Only one function can be regisitered at any time.
 *          NULL may be set to "unregister" the function.
 *
 */
void sd_set_status_change_callback(const storage_status_change_callback_t callback, void *const p_user_data);

const fm_storage_api_t *sd_get_default_driver(void);

#endif /* SD_MNG_H */
