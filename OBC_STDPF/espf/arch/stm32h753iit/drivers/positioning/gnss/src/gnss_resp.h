/**
 * Copyright (c) 2020-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef GNSS_RESP_H
#define GNSS_RESP_H

/**
 * @addtogroup Drivers
 * @{
 * @defgroup gnss
 * @{
 * @file gnss_resp.h
 * @}
 * @}
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "gnss_types.h"

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
/**
 * @brief defines gnss ascii response information structure
 */
typedef struct
{
    const char *p_header_start; // pointer to header start
    const char *p_header_end;   // pointer to header end
    uint32_t    header_size;    // header size in bytes
    const char *p_data_start;   // pointer to message payload start
    const char *p_data_end;     // pointer to message payload end
    uint32_t    data_size;      // data size in bytes
    const char *p_star;         // pointer to asterisk character
    const char *p_crc_start;    // pointer to crc start
    const char *p_crc_end;      // pointer to crc end
    uint32_t    crc_size;       // crc size in bytes
    uint32_t    total_size;     // total response size in bytes
} gnss_ascii_resp_info_t;

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
 * @brief checks if the gnss response is in ascii format
 *
 * @param[in] p_data pointer to raw ascii response
 * @param[in] data_sz raw ascii response size in bytes
 *
 * @retval true  gnss response is in ascii format
 * @retval false gnss response is not in ascii format
 */
bool gnss_resp_is_ascii(const char *const p_data, const uint32_t data_sz);

/**
 * @brief extracts ascii response information from raw ascii response
 *
 * @param[in]  p_data pointer to raw ascii response
 * @param[in]  data_sz raw ascii response size in bytes
 * @param[out] p_info pointer to raw ascii response information
 *
 * @retval true  gnss ascii response structure is verified to be valid
 * @retval false gnss ascii response structure is not valid
 */
bool gnss_resp_get_ascii_info(const char *const p_data, const uint32_t data_sz, gnss_ascii_resp_info_t *const p_info);

/**
 * @brief checks if raw ascii message crc is valid
 *
 * @param[in] p_info pointer to ascii response information
 *
 * @retval true  gnss response crc is valid
 * @retval false gnss response crc is not valid
 */
bool gnss_resp_is_ascii_crc_valid(const gnss_ascii_resp_info_t *const p_info);

/**
 * @brief parses raw ascii position log to binary data
 *
 * @param[in]  p_info pointer to ascii response information
 * @param[out] p_pv   pointer to parsed position/velocity log
 *
 * @retval true  parsing raw ascii position into binary data succeeded
 * @retval false parsing raw ascii position into binary data failed
 */
bool gnss_resp_parse_ascii_pv(const gnss_ascii_resp_info_t *const p_info, gnss_xyz_t *const p_pv);

/**
 * @brief parses raw ascii time log to binary data
 *
 * @param[in]  p_info ascii response information
 * @param[out] p_tim  pointer to parsed time log
 *
 * @retval true  parsing raw ascii time into binary data succeeded
 * @retval false parsing raw ascii time into binary data failed
 */
bool gnss_resp_parse_ascii_tm(const gnss_ascii_resp_info_t *const p_info, gnss_time_t *const p_tim);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // GNSS_RESP_H
