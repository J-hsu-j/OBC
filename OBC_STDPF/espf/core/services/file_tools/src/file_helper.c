/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup service_file_tools
 * @{
 *
 * @file file_helper.c
 *
 * @brief Public interface used to provide helper functions when dealing
 *        with file names.
 *
 * @}
 */

#include "file_helper.h"
#include <string.h>

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
bool file_helper_is_wc_matching(const char *const pFilePattern, const uint32_t patSize, const char *const pFileName, const uint32_t fnSize)
{
    const char *p_pat                = pFilePattern;
    const char *p_fil                = pFileName;
    uint8_t     pat_idx              = 0;
    uint8_t     fli_idx              = 0;
    bool        starts_with_asterisk = false;

    while ((pat_idx < patSize) && (fli_idx < patSize))
    {
        while (*p_pat == '*')
        {
            starts_with_asterisk = true;
            p_pat++;
            pat_idx++;

            if (pat_idx >= patSize)
            {
                // pattern string finished with an asterisk, so we match the rest of the filename automatically
                return true;
            }
        }

        if (starts_with_asterisk)
        {
            while (toupper(*p_pat) != toupper(*p_fil))
            {
                if (fli_idx >= fnSize)
                {
                    // we reached end of the file name string without any match
                    return false;
                }

                fli_idx++;
                p_fil++;
            }
        }

        // match fixed part
        while (toupper(*p_pat) == toupper(*p_fil))
        {
            if ((pat_idx >= patSize) && (fli_idx >= fnSize))
            {
                // both strings finished and comparison didn't fail up to now - we have a match
                return true;
            }

            p_pat++;
            p_fil++;

            pat_idx++;
            fli_idx++;
        }

        if (*p_pat != '*')
        {
            // match sequence stopped and the pattern doesn't continue with a wildcard symbol in
            // order to continue matching
            return false;
        }
    }

    return true;
}

void file_helper_parse_path(const char *full_path, size_t length, char *p_path,
                            size_t path_size, char *p_file_name, size_t file_name_size)
{
    struct
    {
        bool path_buf_valid;
        bool file_name_buf_valid;
    } flags = {
        .path_buf_valid      = false,
        .file_name_buf_valid = false
    };

    // Handle empty or invalid input
    if ((0 == length) || (NULL == full_path))
    {
        return;
    }

    // Ensure buffers are empty
    if ((NULL != p_path) && (path_size > 0))
    {
        p_path[0]            = '\0';
        flags.path_buf_valid = true;
    }

    if ((NULL != p_file_name) && (file_name_size > 0))
    {
        p_file_name[0]            = '\0';
        flags.file_name_buf_valid = true;
    }

    if ((!flags.path_buf_valid) && (!flags.file_name_buf_valid))
    {
        return;
    }

    // Limit length to actual string if it's longer than full_path
    size_t actual_length = strnlen(full_path, length);

    // Find the last occurrence of '/'
    const char *p_last_slash = strrchr(full_path, '/');

    // If no slash found, the entire input is considered as the file name
    if (p_last_slash == NULL)
    {
        if (true == flags.file_name_buf_valid)
        {
            strncpy(p_file_name, full_path, file_name_size - 1);
            p_file_name[file_name_size - 1] = '\0';
        }

        return;
    }

    if (true == flags.path_buf_valid)
    {
        // Copy directory path (everything up to the last slash)
        size_t path_length = (size_t)(p_last_slash - full_path);
        if (path_length > path_size - 1)
        {
            path_length = path_size - 1; // Truncate if necessary
        }
        strncpy(p_path, full_path, path_length);
        p_path[path_length] = '\0';
    }

    if (true == flags.file_name_buf_valid)
    {
        // Copy file name (everything after the last slash)
        const char *file_name_start  = p_last_slash + 1;
        size_t      file_name_length = actual_length - (size_t)(file_name_start - full_path);
        if (file_name_length > file_name_size - 1)
        {
            file_name_length = file_name_size - 1; // Truncate if necessary
        }
        strncpy(p_file_name, file_name_start, file_name_length);
        p_file_name[file_name_length] = '\0';
    }
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
