/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef FILE_HELPER_H
#define FILE_HELPER_H

/**
 * @addtogroup service_file_tools
 * @{
 *
 * @file file_helper.h
 *
 * @brief Public interface used to provide helper functions when dealing
 *        with file names.
 * @}
 */

#include "fm_mng.h"

#include <ctype.h>

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

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/
/**
 * @brief Checks if a specified pattern matches a file name
 *
 *  Supports wildcards with an asterisk '*' symbol only (it represents any string, character or even lack of string).
 *
 *  @param[in] pFilePattern Valid SXBand SendFiles file pattern string
 *  @param[in] patSize size of pFilePattern in bytes (without any NULLZ characters)
 *  @param[in] pFileName File name to check against the pattern
 *  @param[in] fnSize size of pFilePattern in bytes (without any NULLZ characters)*
 *
 *  @return true: the file name matches the pattern; false: otherwise
 */
bool file_helper_is_wc_matching(const char *const pFilePattern, const uint32_t patSize, const char *const pFileName, const uint32_t fnSize);

/**
 * @brief Parses a file system path into its directory path and file name components.
 *
 * Given a full path, this function separates it into the directory path and
 * the file name (which might be a wildcard pattern). If there are no slashes
 * in the input, the full string is treated as the file name.
 *
 * @param[in] full_path The complete file path as a string to be parsed.
 * @param[in] length The length of the string in `full_path`.
 * @param[out] p_path A buffer to store the directory path component.
 * @param[in] path_size The size of the `path` buffer.
 * @param[out] p_file_name A buffer to store the file name component.
 * @param[in] file_name_size The size of the `file_name` buffer.
 */
void file_helper_parse_path(const char *full_path, size_t length, char *p_path, size_t path_size, char *p_file_name, size_t file_name_size);

#endif /* FILE_HELPER_H */
