/*
 * Copyright (c) 2023-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef FM_COMMON_DEF_H
#define FM_COMMON_DEF_H

/**
 * @addtogroup service_file_tools
 * @{
 *
 * @file fm_common_def.h
 *
 * @brief private non-API related definitions used throughout the file tools services.
 *
 * @}
 *
 */

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/

/**
 * @brief 4-byte aligned data is atomic by design in the ARM Cortex-M7 architecture
 * See Armv7-M Architecture Reference Manual page 79 section A3.5.3
 */
#define ATOMIC_ALIGN __attribute__((aligned(4)))

/**
 * @brief The ascii zero character.
 */
#define TERMINATING_ZERO_CHAR     ((char)'\0')
#define TERMINATING_ZERO_CHAR_LEN (sizeof(""))

#endif // FM_COMMON_DEF_H
