/**
 * Copyright (c) 2020-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup Drivers
 * @{
 * @defgroup gnss
 * @{
 * @file gnss_resp.c
 * @}
 * @}
 */

#include "gnss_resp.h"
#include <string.h>
#include <stdlib.h>

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
#define CRC32_POLYNOMIAL   0xEDB88320L
#define STATIC_STRLEN(str) (sizeof(str) - 1)

#define UNKNOWN                  "UNKNOWN"
#define APPROXIMATE              "APPROXIMATE"
#define COARSEADJUSTING          "COARSEADJUSTING"
#define COARSE                   "COARSE"
#define COARSESTEERING           "COARSESTEERING"
#define FREEWHEELING             "FREEWHEELING"
#define FINEADJUSTING            "FINEADJUSTING"
#define FINE                     "FINE"
#define FINEBACKUPSTEERING       "FINEBACKUPSTEERING"
#define FINESTEERING             "FINESTEERING"
#define SATTIME                  "SATTIME"
#define VALID                    "VALID"
#define CONVERGING               "CONVERGIN"
#define ITERATING                "ITERATING"
#define INVALID                  "INVALID"
#define WARNING                  "WARNING"
#define SOL_COMPUTED             "SOL_COMPUTED"
#define INSUFFICIENT_OBS         "INSUFFICIENT_OBS"
#define NO_CONVERGENCE           "NO_CONVERGENCE"
#define SINGULARITY              "SINGULARITY"
#define COV_TRACE                "COV_TRACE"
#define TEST_DIST                "TEST_DIST"
#define COLD_START               "COLD_START"
#define V_H_LIMIT                "V_H_LIMIT"
#define VARIANCE                 "VARIANCE"
#define RESIDUALS                "RESIDUALS"
#define INTEGRITY_WARNING        "INTEGRITY_WARNING"
#define PENDING                  "PENDING"
#define INVALID_FIX              "INVALID_FIX"
#define UNAUTHORIZED             "UNAUTHORIZED"
#define INVALID_RATE             "INVALID_RATE"
#define NONE                     "NONE"
#define FIXEDPOS                 "FIXEDPOS"
#define FIXEDHEIGHT              "FIXEDHEIGHT"
#define DOPPLER_VELOCITY         "DOPPLER_VELOCITY"
#define SINGLE                   "SINGLE"
#define PSRDIFF                  "PSRDIFF"
#define WAAS                     "WAAS"
#define PROPAGATED               "PROPAGATED"
#define L1_FLOAT                 "L1_FLOAT"
#define NARROW_FLOAT             "NARROW_FLOAT"
#define L1_INT                   "L1_INT"
#define WIDE_INT                 "WIDE_INT"
#define NARROW_INT               "NARROW_INT"
#define RTK_DIRECT_INS           "RTK_DIRECT_INS"
#define INS_SBAS                 "INS_SBAS"
#define INS_PSRSP                "INS_PSRSP"
#define INS_PSRDIFF              "INS_PSRDIFF"
#define INS_RTKFLOAT             "INS_RTKFLOAT"
#define INS_RTKFIXED             "INS_RTKFIXED"
#define PPP_CONVERGING           "PPP_CONVERGING"
#define PPP                      "PPP"
#define OPERATIONAL              "OPERATIONAL"
#define OUT_OF_BOUNDS            "OUT_OF_BOUNDS"
#define INS_PPP_CONVERGING       "INS_PPP_CONVERGING"
#define INS_PPP                  "INS_PPP"
#define PPP_BASIC_CONVERGING     "PPP_BASIC_CONVERGING"
#define PPP_BASIC                "PPP_BASIC"
#define INS_PPP_BASIC_CONVERGING "INS_PPP_BASIC_CONVERGING"
#define INS_PPP_BASIC            "INS_PPP_BASIC"

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
/**
 * @brief extracts response header from raw data
 * @param[in] p_info pointer to response information
 * @param[out] p_hdr  pointer to parsed header
 * @retval true header parsing succeeded
 * @retval false header parsing failed
 */
static bool parse_ascii_hdr(const gnss_ascii_resp_info_t *const p_info, gnss_hdr_t *const p_hdr);

/**
 * @brief verifies info structure limits
 * @param[in] p_info pointer to structure to be tested
 * @retval true  structure info verification succeeded
 * @retval false structure info verification failed
 */
static bool verify_info(const gnss_ascii_resp_info_t *const p_info);

/**
 * @brief finds first occurrence of a character in a string
 * @param[in] p_start pointer to the start of the string
 * @param[in] p_end   pointer to the end of the string
 * @param[in] ch    character to search for
 * @return NULL or valid pointer in range 'start <= pointer < end'
 */
static const char *strnchr(const char *start, const char *p_end, const char p_ch);

/**
 * @brief checks if a string fully matches the beginning of another string
 * @param[in] p_str1     Pointer to the sub string that is to be searched. Its length must be known.
 * @param[in] str1_len Maximum length to search through
 * @param[in] p_str2     Pointer to the string that must be inspected
 * @param[in] str2_len Maximum length to search through
 * @retval NULL str1 is not equivalent to str2 beginning
 * @retval pointer to the first matched character
 */
static const char *strnstrn(const char *p_str1, const uint32_t str1_len, const char *p_str2, const uint32_t str2_len);

/**
 * @brief Calculates CRC of single byte. Algorithm taken from OEM719 user manual
 * @param[in] i integer
 * @return byte CRC
 */
static uint32_t crc32_value(const uint32_t i);

/**
 * @brief Calculates CRC32 of a byte buffer. Algorithm taken from OEM719 user manual.
 * @param[in] p_buf    pointer to byte buffer
 * @param[in] buf_sz byte buffer size
 * @return CRC32
 */
static uint32_t crc32_calculate_block(const uint8_t *p_buf, const uint32_t buf_sz);

/**
 * @brief Converts time status string to integer. The values are taken from oem719 user manual
 * @param[in] p_data pointer to string
 * @param[in] data_sz string size in bytes
 * @return equivalent integer value
 */
static uint32_t get_ascii_time_status(const char *p_data, uint32_t data_sz);

/**
 * @brief Converts clock status string to integer. The values are taken from oem719 user manual
 * @param[in] p_data pointer to string
 * @param[in] data_sz string size in bytes
 * @return equivalent integer value
 */
static uint32_t get_clock_status(const char *p_data, uint32_t data_sz);

/**
 * @brief Converts utc status string to integer. The values are taken from oem719 user manual
 * @param[in] p_data pointer to string
 * @param[in] data_sz string size in bytes
 * @return equivalent integer value
 */
static uint32_t get_utc_status(const char *p_data, uint32_t data_sz);

/**
 * @brief Converts solution status string to integer. The values are taken from oem719 user manual
 * @param[in] p_data pointer to string
 * @param[in] data_sz string size in bytes
 * @return equivalent integer value
 */
static uint32_t get_solution_status(const char *p_data, uint32_t data_sz);

/**
 * @brief Converts position type string to integer. The values are taken from oem719 user manual
 * @param[in] p_data pointer to string
 * @param[in] data_sz string size in bytes
 * @return equivalent integer value
 */
static uint32_t get_pv_type(const char *p_data, uint32_t data_sz);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
bool gnss_resp_parse_ascii_pv(const gnss_ascii_resp_info_t *const p_info, gnss_xyz_t *const p_pv)
{
    if (false == verify_info(p_info))
    {
        return false;
    }

    if (false == parse_ascii_hdr(p_info, (gnss_hdr_t *)p_pv))
    {
        return false;
    }

    const char delim = ',';

    const char *ch1 = strnchr(p_info->p_data_start, p_info->p_data_end, delim);
    if (NULL == ch1)
    {
        return false;
    }

    p_pv->p_sol_status = get_solution_status(p_info->p_data_start, (uint32_t)(ch1 - p_info->p_data_start));
    ch1 += 1;
    const char *ch2 = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_pv->pos_type = get_pv_type(ch1, (uint32_t)(ch2 - ch1));
    ch1            = ch2 + 1;
    ch2            = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_pv->px = strtof(ch1, NULL);
    ch1      = ch2 + 1;
    ch2      = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_pv->py = strtof(ch1, NULL);
    ch1      = ch2 + 1;
    ch2      = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_pv->pz = strtof(ch1, NULL);
    ch1      = ch2 + 1;
    ch2      = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_pv->pxo = strtof(ch1, NULL);
    ch1       = ch2 + 1;
    ch2       = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_pv->pyo = strtof(ch1, NULL);
    ch1       = ch2 + 1;
    ch2       = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_pv->pzo = strtof(ch1, NULL);
    ch1       = ch2 + 1;
    ch2       = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_pv->v_sol_status = get_solution_status(ch1, (uint32_t)(ch2 - ch1));
    ch1                = ch2 + 1;
    ch2                = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_pv->vel_type = get_pv_type(ch1, (uint32_t)(ch2 - ch1));
    ch1            = ch2 + 1;
    ch2            = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_pv->vx = strtof(ch1, NULL);
    ch1      = ch2 + 1;
    ch2      = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_pv->vy = strtof(ch1, NULL);
    ch1      = ch2 + 1;
    ch2      = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_pv->vz = strtof(ch1, NULL);
    ch1      = ch2 + 1;
    ch2      = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_pv->vxo = strtof(ch1, NULL);
    ch1       = ch2 + 1;
    ch2       = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_pv->vyo = strtof(ch1, NULL);
    ch1       = ch2 + 1;
    ch2       = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_pv->vzo = strtof(ch1, NULL);
    ch1       = ch2 + 1;
    ch2       = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    if (ch2 < ch1)
    {
        return false;
    }

    if (sizeof(p_pv->stn_id) < (size_t)(ch2 - ch1))
    {
        return false;
    }

    (void)memset(p_pv->stn_id, 0, sizeof(p_pv->stn_id));
    (void)memcpy(p_pv->stn_id, ch1, (size_t)(ch2 - ch1));
    ch1 = ch2 + 1;
    ch2 = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_pv->v_latency = strtof(ch1, NULL);
    ch1             = ch2 + 1;
    ch2             = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_pv->diff_age = strtof(ch1, NULL);
    ch1            = ch2 + 1;
    ch2            = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_pv->sol_age = strtof(ch1, NULL);
    ch1           = ch2 + 1;
    ch2           = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    uint32_t val;

    val = strtoul(ch1, NULL, 10);

    if (UINT8_MAX < val)
    {
        return false;
    }

    p_pv->svs = (uint8_t)val;
    ch1       = ch2 + 1;
    ch2       = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    val = strtoul(ch1, NULL, 10);

    if (UINT8_MAX < val)
    {
        return false;
    }

    p_pv->solnsvs = (uint8_t)val;
    ch1           = ch2 + 1;
    ch2           = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    val = strtoul(ch1, NULL, 10);

    if (UINT8_MAX < val)
    {
        return false;
    }

    p_pv->ggl1 = (uint8_t)val;
    ch1        = ch2 + 1;
    ch2        = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    val = strtoul(ch1, NULL, 10);

    if (UINT8_MAX < val)
    {
        return false;
    }

    p_pv->solnmultisvs = (uint8_t)val;
    ch1                = ch2 + 1;
    ch2                = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    val = strtoul(ch1, NULL, 10);

    if (UINT8_MAX < val)
    {
        return false;
    }

    p_pv->reserved = (uint8_t)val;
    ch1            = ch2 + 1;
    ch2            = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    val = strtoul(ch1, NULL, 16);

    if (UINT8_MAX < val)
    {
        return false;
    }

    p_pv->ext_sol_stat = (uint8_t)val;
    ch1                = ch2 + 1;
    ch2                = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    val = strtoul(ch1, NULL, 16);

    if (UINT8_MAX < val)
    {
        return false;
    }

    p_pv->galileo_and_beidou_sig_mask = (uint8_t)val;
    ch1                               = ch2 + 1;
    ch2                               = strnchr(ch1, p_info->p_crc_start, '*');
    if (NULL == ch2)
    {
        return false;
    }

    val = strtoul(ch1, NULL, 16);

    if (UINT8_MAX < val)
    {
        return false;
    }

    p_pv->gps_and_glonass_sig_mask = (uint8_t)val;
    ch1                            = ch2 + 1;
    if (p_info->p_crc_end < ch1)
    {
        return false;
    }

    p_pv->crc32 = strtoul(p_info->p_crc_start, NULL, 16);

    p_pv->end[0] = *p_info->p_crc_end;
    p_pv->end[1] = '\n';

    return true;
}

bool gnss_resp_parse_ascii_tm(const gnss_ascii_resp_info_t *const p_info, gnss_time_t *const p_tim)
{
    if (false == verify_info(p_info))
    {
        return false;
    }

    if (false == parse_ascii_hdr(p_info, (gnss_hdr_t *)p_tim))
    {
        return false;
    }

    const char  delim = ',';
    const char *ch1   = strnchr(p_info->p_data_start, p_info->p_data_end, delim);

    p_tim->clock_status = get_clock_status(p_info->p_data_start, (uint32_t)(ch1 - p_info->p_data_start));
    ch1 += 1;
    const char *ch2 = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_tim->offset = strtof(ch1, NULL);
    ch1           = ch2 + 1;
    ch2           = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_tim->offset_std = strtof(ch1, NULL);
    ch1               = ch2 + 1;
    ch2               = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_tim->utc_offset = strtof(ch1, NULL);
    ch1               = ch2 + 1;
    ch2               = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_tim->utc_year = strtoul(ch1, NULL, 10);
    ch1             = ch2 + 1;
    ch2             = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    uint32_t val;

    val = strtoul(ch1, NULL, 10);

    if (UINT8_MAX < val)
    {
        return false;
    }

    p_tim->utc_month = (uint8_t)val;
    ch1              = ch2 + 1;
    ch2              = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    val = strtoul(ch1, NULL, 10);

    if (UINT8_MAX < val)
    {
        return false;
    }

    p_tim->utc_day = (uint8_t)val;
    ch1            = ch2 + 1;
    ch2            = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    val = strtoul(ch1, NULL, 10);

    if (UINT8_MAX < val)
    {
        return false;
    }

    p_tim->utc_hour = (uint8_t)val;
    ch1             = ch2 + 1;
    ch2             = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    val = strtoul(ch1, NULL, 10);

    if (UINT8_MAX < val)
    {
        return false;
    }

    p_tim->utc_min = (uint8_t)val;
    ch1            = ch2 + 1;
    ch2            = strnchr(ch1, p_info->p_data_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    p_tim->utc_ms = strtoul(ch1, NULL, 10);
    ch1           = ch2 + 1;
    ch2           = strnchr(ch1, p_info->p_crc_start, '*');
    if (NULL == ch2)
    {
        return false;
    }

    p_tim->utc_status = get_utc_status(ch1, (uint32_t)(ch2 - ch1));
    ch1               = ch2 + 1;
    if (p_info->p_crc_end < ch1)
    {
        return false;
    }

    p_tim->crc32 = strtoul(ch1, NULL, 16);

    p_tim->end[0] = '\r';
    p_tim->end[1] = '\n';

    return true;
}

bool gnss_resp_is_ascii(const char *const p_data, const uint32_t data_sz)
{
    bool res = false;

    for (uint32_t i = 0; i < data_sz; i++)
    {
        // The receiver only accepts the following ASCII characters:
        //   1. characters between space (ASCII value 32) and '~' (ASCII value 126) inclusive
        //   2. vertical tab (ASCII value 9)
        //   3. line feed (ASCII value 10)
        //   4. horizontal tab (ASCII value 11)
        //   5. carriage return (ASCII value 13)
        if (((32 <= p_data[i]) &&
             (132 >= p_data[i])) ||
            (9 == p_data[i]) ||
            (10 == p_data[i]) ||
            (11 == p_data[i]) ||
            (13 == p_data[i]))
        {
            res = true;
        }
        else
        {
            res = false;
            break;
        }
    }

    return res;
}

bool gnss_resp_is_ascii_crc_valid(const gnss_ascii_resp_info_t *const p_info)
{
    bool ret = false;

    if (true == verify_info(p_info))
    {
        uint32_t size       = p_info->header_size + p_info->data_size;
        uint32_t crc32_calc = crc32_calculate_block((const uint8_t *)p_info->p_header_start + 1, size);
        uint32_t crc32_recv = strtoul(p_info->p_crc_start, NULL, 16);

        if (crc32_calc == crc32_recv)
        {
            ret = true;
        }
    }

    return ret;
}

bool gnss_resp_get_ascii_info(const char *const p_data, const uint32_t data_sz, gnss_ascii_resp_info_t *const p_info)
{
    bool ret = false;

    if ((NULL != p_data) && (0 != data_sz) && (NULL != p_info))
    {
        p_info->p_header_start = strnchr(p_data, (p_data + data_sz), '#');
        p_info->p_header_end   = strnchr(p_info->p_header_start, (p_data + data_sz), ';');
        p_info->header_size    = (uint32_t)(p_info->p_header_end - p_info->p_header_start);
        p_info->p_data_start   = p_info->p_header_end + 1;
        p_info->p_data_end     = strnchr(p_info->p_data_start, (p_data + data_sz), '*');
        p_info->data_size      = (uint32_t)(p_info->p_data_end - p_info->p_data_start);
        p_info->p_star         = p_info->p_data_end;
        p_info->p_crc_start    = p_info->p_star + 1;
        p_info->p_crc_end      = strnchr(p_info->p_star, (p_data + data_sz), '\r');
        p_info->crc_size       = (uint32_t)(p_info->p_crc_end - p_info->p_crc_start);
        p_info->total_size     = (uint32_t)(p_info->p_crc_end + 2 - p_info->p_header_start); // +2 because of CR/LF

        if (true == verify_info(p_info))
        {
            ret = true;
        }
    }

    return ret;
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
static bool verify_info(const gnss_ascii_resp_info_t *const p_info)
{
    bool ret = true;

    // clang-format off
    if ((NULL == p_info) ||
        ((NULL == p_info->p_header_start) || ((p_info->p_header_start + p_info->total_size) < p_info->p_header_start)) ||
        ((NULL == p_info->p_header_end  ) || ((p_info->p_header_start + p_info->total_size) < p_info->p_header_end  )) ||
        ((NULL == p_info->p_data_start  ) || ((p_info->p_header_start + p_info->total_size) < p_info->p_data_start  )) ||
        ((NULL == p_info->p_data_end    ) || ((p_info->p_header_start + p_info->total_size) < p_info->p_data_end    )) ||
        ((NULL == p_info->p_star        ) || ((p_info->p_header_start + p_info->total_size) < p_info->p_star        )) ||
        ((NULL == p_info->p_crc_start   ) || ((p_info->p_header_start + p_info->total_size) < p_info->p_crc_start   )) ||
        ((NULL == p_info->p_crc_end     ) || ((p_info->p_header_start + p_info->total_size) < p_info->p_crc_end     )))
    {
        ret = false;
    }
    // clang-format on

    return ret;
}

static bool parse_ascii_hdr(const gnss_ascii_resp_info_t *const p_info, gnss_hdr_t *const p_hdr)
{
    if ((NULL == p_hdr) || (NULL == p_info) || (NULL == p_info->p_header_start))
    {
        return false;
    }

    const char *name_start = p_info->p_header_start + 1;
    const char  delim      = ',';

    const char *ch1 = strnchr(name_start, p_info->p_header_end, delim);
    if (NULL == ch1)
    {
        return false;
    }

    // sync
    p_hdr->sync = p_info->p_header_start[0];

    if (sizeof(p_hdr->message) < (size_t)(ch1 - name_start))
    {
        return false;
    }

    (void)memset(p_hdr->message, 0, sizeof(p_hdr->message));
    (void)memcpy(p_hdr->message, name_start, (size_t)(ch1 - name_start));
    ch1 += 1;
    const char *ch2 = strnchr(ch1, p_info->p_header_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    // port
    if (ch2 < ch1)
    {
        return false;
    }

    if (sizeof(p_hdr->port) < (size_t)(ch2 - ch1))
    {
        return false;
    }

    (void)memset(p_hdr->port, 0, sizeof(p_hdr->port));
    (void)memcpy(p_hdr->port, ch1, (size_t)(ch2 - ch1));
    ch1 = ch2 + 1;
    ch2 = strnchr(ch1, p_info->p_header_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    // sequence
    p_hdr->sequence = strtol(ch1, NULL, 10);
    ch1             = ch2 + 1;
    ch2             = strnchr(ch1, p_info->p_header_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    // idle time
    p_hdr->idle_time = strtof(ch1, NULL);
    ch1              = ch2 + 1;
    ch2              = strnchr(ch1, p_info->p_header_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    // time status
    p_hdr->time_status = get_ascii_time_status(ch1, (uint32_t)(ch2 - ch1));
    ch1                = ch2 + 1;
    ch2                = strnchr(ch1, p_info->p_header_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    // week
    p_hdr->week = strtoul(ch1, NULL, 10);
    ch1         = ch2 + 1;
    ch2         = strnchr(ch1, p_info->p_header_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    // seconds
    p_hdr->seconds = strtof(ch1, NULL);
    ch1            = ch2 + 1;
    ch2            = strnchr(ch1, p_info->p_header_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    // receiver status
    p_hdr->receiver_status = strtoul(ch1, NULL, 16);
    ch1                    = ch2 + 1;
    ch2                    = strnchr(ch1, p_info->p_header_end, delim);
    if (NULL == ch2)
    {
        return false;
    }

    // reserved
    p_hdr->reserved = strtoul(ch1, NULL, 10);
    ch1             = ch2 + 1;
    if ((NULL == ch1) || (p_info->p_header_end < ch1))
    {
        return false;
    }

    // receiver sw version
    p_hdr->receiver_sw_version = strtoul(ch1, NULL, 10);

    // end
    p_hdr->end = p_info->p_header_end[0];

    return true;
}

static uint32_t crc32_value(const uint32_t i)
{
    uint32_t crc32 = i;

    for (uint8_t j = 8; j > 0; j--)
    {
        if (0 != (crc32 & 1))
        {
            crc32 = (crc32 >> 1) ^ CRC32_POLYNOMIAL;
        }
        else
        {
            crc32 >>= 1;
        }
    }

    return crc32;
}

static uint32_t crc32_calculate_block(const uint8_t *p_buf, const uint32_t buf_sz)
{
    uint32_t temp1;
    uint32_t temp2;
    uint32_t crc32 = 0;
    uint32_t sz    = buf_sz;
    uint32_t i     = 0;

    while (sz != 0)
    {
        temp1 = (crc32 >> 8) & 0x00FFFFFFL;
        temp2 = crc32_value((crc32 ^ p_buf[i]) & 0xFF);
        crc32 = temp1 ^ temp2;

        sz--;
        i++;
    }

    return crc32;
}

static uint32_t get_ascii_time_status(const char *p_data, uint32_t data_sz)
{
    uint32_t ret;

    // clang-format off
    if      (NULL != strnstrn(UNKNOWN,            STATIC_STRLEN(UNKNOWN           ), p_data, data_sz)) { ret =  20; }
    else if (NULL != strnstrn(APPROXIMATE,        STATIC_STRLEN(APPROXIMATE       ), p_data, data_sz)) { ret =  60; }
    else if (NULL != strnstrn(COARSEADJUSTING,    STATIC_STRLEN(COARSEADJUSTING   ), p_data, data_sz)) { ret =  80; }
    else if (NULL != strnstrn(COARSE,             STATIC_STRLEN(COARSE            ), p_data, data_sz)) { ret = 100; }
    else if (NULL != strnstrn(COARSESTEERING,     STATIC_STRLEN(COARSESTEERING    ), p_data, data_sz)) { ret = 120; }
    else if (NULL != strnstrn(FREEWHEELING,       STATIC_STRLEN(FREEWHEELING      ), p_data, data_sz)) { ret = 130; }
    else if (NULL != strnstrn(FINEADJUSTING,      STATIC_STRLEN(FINEADJUSTING     ), p_data, data_sz)) { ret = 140; }
    else if (NULL != strnstrn(FINE,               STATIC_STRLEN(FINE              ), p_data, data_sz)) { ret = 160; }
    else if (NULL != strnstrn(FINEBACKUPSTEERING, STATIC_STRLEN(FINEBACKUPSTEERING), p_data, data_sz)) { ret = 170; }
    else if (NULL != strnstrn(FINESTEERING,       STATIC_STRLEN(FINESTEERING      ), p_data, data_sz)) { ret = 180; }
    else if (NULL != strnstrn(SATTIME,            STATIC_STRLEN(SATTIME           ), p_data, data_sz)) { ret = 200; }
    else                                                                                               { ret =   0; }
    // clang-format on

    return ret;
}

static uint32_t get_clock_status(const char *p_data, uint32_t data_sz)
{
    uint32_t ret;
    // clang-format off
    if      (NULL != strnstrn(VALID,      STATIC_STRLEN(VALID     ), p_data, data_sz)) { ret = 0; }
    else if (NULL != strnstrn(CONVERGING, STATIC_STRLEN(CONVERGING), p_data, data_sz)) { ret = 1; }
    else if (NULL != strnstrn(ITERATING,  STATIC_STRLEN(ITERATING ), p_data, data_sz)) { ret = 2; }
    else if (NULL != strnstrn(INVALID,    STATIC_STRLEN(INVALID   ), p_data, data_sz)) { ret = 3; }
    else                                                                                   { ret = 4; }
    // clang-format on

    return ret;
}

static uint32_t get_utc_status(const char *p_data, uint32_t data_sz)
{
    uint32_t ret;

    // clang-format off
    if      (NULL != strnstrn(INVALID, STATIC_STRLEN(INVALID), p_data, data_sz)) { ret = 0; }
    else if (NULL != strnstrn(VALID,   STATIC_STRLEN(VALID),   p_data, data_sz)) { ret = 1; }
    else if (NULL != strnstrn(WARNING, STATIC_STRLEN(WARNING), p_data, data_sz)) { ret = 2; }
    else                                                                             { ret = 3; }
    // clang-format on

    return ret;
}

static uint32_t get_solution_status(const char *p_data, uint32_t data_sz)
{
    uint32_t ret;

    // clang-format off
    if      (NULL != strnstrn(SOL_COMPUTED,      STATIC_STRLEN(SOL_COMPUTED     ), p_data, data_sz)) { ret =  0; }
    else if (NULL != strnstrn(INSUFFICIENT_OBS,  STATIC_STRLEN(INSUFFICIENT_OBS ), p_data, data_sz)) { ret =  1; }
    else if (NULL != strnstrn(NO_CONVERGENCE,    STATIC_STRLEN(NO_CONVERGENCE   ), p_data, data_sz)) { ret =  2; }
    else if (NULL != strnstrn(SINGULARITY,       STATIC_STRLEN(SINGULARITY      ), p_data, data_sz)) { ret =  3; }
    else if (NULL != strnstrn(COV_TRACE,         STATIC_STRLEN(COV_TRACE        ), p_data, data_sz)) { ret =  4; }
    else if (NULL != strnstrn(TEST_DIST,         STATIC_STRLEN(TEST_DIST        ), p_data, data_sz)) { ret =  5; }
    else if (NULL != strnstrn(COLD_START,        STATIC_STRLEN(COLD_START       ), p_data, data_sz)) { ret =  6; }
    else if (NULL != strnstrn(V_H_LIMIT,         STATIC_STRLEN(V_H_LIMIT        ), p_data, data_sz)) { ret =  7; }
    else if (NULL != strnstrn(VARIANCE,          STATIC_STRLEN(VARIANCE         ), p_data, data_sz)) { ret =  8; }
    else if (NULL != strnstrn(RESIDUALS,         STATIC_STRLEN(RESIDUALS        ), p_data, data_sz)) { ret =  9; }
    else if (NULL != strnstrn(INTEGRITY_WARNING, STATIC_STRLEN(INTEGRITY_WARNING), p_data, data_sz)) { ret = 13; }
    else if (NULL != strnstrn(PENDING,           STATIC_STRLEN(PENDING          ), p_data, data_sz)) { ret = 18; }
    else if (NULL != strnstrn(INVALID_FIX,       STATIC_STRLEN(INVALID_FIX      ), p_data, data_sz)) { ret = 19; }
    else if (NULL != strnstrn(UNAUTHORIZED,      STATIC_STRLEN(UNAUTHORIZED     ), p_data, data_sz)) { ret = 20; }
    else if (NULL != strnstrn(INVALID_RATE,      STATIC_STRLEN(INVALID_RATE     ), p_data, data_sz)) { ret = 22; }
    else                                                                                             { ret = 23; }
    // clang-format on

    return ret;
}

static uint32_t get_pv_type(const char *p_data, uint32_t data_sz)
{
    uint32_t ret;

    // clang-format off
    if      (NULL != strnstrn(NONE,                     STATIC_STRLEN(NONE                    ), p_data, data_sz)) { ret =  0; }
    else if (NULL != strnstrn(FIXEDPOS,                 STATIC_STRLEN(FIXEDPOS                ), p_data, data_sz)) { ret =  1; }
    else if (NULL != strnstrn(FIXEDHEIGHT,              STATIC_STRLEN(FIXEDHEIGHT             ), p_data, data_sz)) { ret =  2; }
    else if (NULL != strnstrn(DOPPLER_VELOCITY,         STATIC_STRLEN(DOPPLER_VELOCITY        ), p_data, data_sz)) { ret =  8; }
    else if (NULL != strnstrn(SINGLE,                   STATIC_STRLEN(SINGLE                  ), p_data, data_sz)) { ret = 16; }
    else if (NULL != strnstrn(PSRDIFF,                  STATIC_STRLEN(PSRDIFF                 ), p_data, data_sz)) { ret = 17; }
    else if (NULL != strnstrn(WAAS,                     STATIC_STRLEN(WAAS                    ), p_data, data_sz)) { ret = 18; }
    else if (NULL != strnstrn(PROPAGATED,               STATIC_STRLEN(PROPAGATED              ), p_data, data_sz)) { ret = 19; }
    else if (NULL != strnstrn(L1_FLOAT,                 STATIC_STRLEN(L1_FLOAT                ), p_data, data_sz)) { ret = 32; }
    else if (NULL != strnstrn(NARROW_FLOAT,             STATIC_STRLEN(NARROW_FLOAT            ), p_data, data_sz)) { ret = 34; }
    else if (NULL != strnstrn(L1_INT,                   STATIC_STRLEN(L1_INT                  ), p_data, data_sz)) { ret = 48; }
    else if (NULL != strnstrn(WIDE_INT,                 STATIC_STRLEN(WIDE_INT                ), p_data, data_sz)) { ret = 49; }
    else if (NULL != strnstrn(NARROW_INT,               STATIC_STRLEN(NARROW_INT              ), p_data, data_sz)) { ret = 50; }
    else if (NULL != strnstrn(RTK_DIRECT_INS,           STATIC_STRLEN(RTK_DIRECT_INS          ), p_data, data_sz)) { ret = 51; }
    else if (NULL != strnstrn(INS_SBAS,                 STATIC_STRLEN(INS_SBAS                ), p_data, data_sz)) { ret = 52; }
    else if (NULL != strnstrn(INS_PSRSP,                STATIC_STRLEN(INS_PSRSP               ), p_data, data_sz)) { ret = 53; }
    else if (NULL != strnstrn(INS_PSRDIFF,              STATIC_STRLEN(INS_PSRDIFF             ), p_data, data_sz)) { ret = 54; }
    else if (NULL != strnstrn(INS_RTKFLOAT,             STATIC_STRLEN(INS_RTKFLOAT            ), p_data, data_sz)) { ret = 55; }
    else if (NULL != strnstrn(INS_RTKFIXED,             STATIC_STRLEN(INS_RTKFIXED            ), p_data, data_sz)) { ret = 56; }
    else if (NULL != strnstrn(PPP_CONVERGING,           STATIC_STRLEN(PPP_CONVERGING          ), p_data, data_sz)) { ret = 68; }
    else if (NULL != strnstrn(PPP,                      STATIC_STRLEN(PPP                     ), p_data, data_sz)) { ret = 69; }
    else if (NULL != strnstrn(OPERATIONAL,              STATIC_STRLEN(OPERATIONAL             ), p_data, data_sz)) { ret = 70; }
    else if (NULL != strnstrn(WARNING,                  STATIC_STRLEN(WARNING                 ), p_data, data_sz)) { ret = 71; }
    else if (NULL != strnstrn(OUT_OF_BOUNDS,            STATIC_STRLEN(OUT_OF_BOUNDS           ), p_data, data_sz)) { ret = 72; }
    else if (NULL != strnstrn(INS_PPP_CONVERGING,       STATIC_STRLEN(INS_PPP_CONVERGING      ), p_data, data_sz)) { ret = 73; }
    else if (NULL != strnstrn(INS_PPP,                  STATIC_STRLEN(INS_PPP                 ), p_data, data_sz)) { ret = 74; }
    else if (NULL != strnstrn(PPP_BASIC_CONVERGING,     STATIC_STRLEN(PPP_BASIC_CONVERGING    ), p_data, data_sz)) { ret = 77; }
    else if (NULL != strnstrn(PPP_BASIC,                STATIC_STRLEN(PPP_BASIC               ), p_data, data_sz)) { ret = 78; }
    else if (NULL != strnstrn(INS_PPP_BASIC_CONVERGING, STATIC_STRLEN(INS_PPP_BASIC_CONVERGING), p_data, data_sz)) { ret = 79; }
    else if (NULL != strnstrn(INS_PPP_BASIC,            STATIC_STRLEN(INS_PPP_BASIC           ), p_data, data_sz)) { ret = 80; }
    else                                                                                                           { ret = 81; }
    // clang-format on

    return ret;
}

static const char *strnstrn(const char *p_str1, const uint32_t str1_len, const char *p_str2, const uint32_t str2_len)
{
    if ((NULL == p_str1) || (NULL == p_str2) || (0 == str1_len) || (0 == str2_len))
    {
        return NULL;
    }

    bool     last_char_matched = false;
    uint32_t num_matched_chars = 0;
    uint32_t i                 = 0;
    uint32_t j                 = 0;

    while ((i < str1_len) && (j < str2_len))
    {
        if (!last_char_matched)
        {
            num_matched_chars = 0;
        }

        if (p_str1[i] == p_str2[j])
        {
            i++;
            j++;
            num_matched_chars++;
            last_char_matched = true;
        }
        else
        {
            return NULL;
        }
    }

    if ((num_matched_chars == str2_len) && (0 < num_matched_chars))
    {
        return (p_str1 + i - j);
    }
    else
    {
        return NULL;
    }
}

static const char *strnchr(const char *p_start, const char *p_end, const char ch)
{
    const char *ret = NULL;

    if ((NULL != p_start) && (NULL != p_end))
    {
        for (const char *i = p_start; i < p_end; i++)
        {
            if (*i == ch)
            {
                ret = i;
                break;
            }
        }
    }

    return ret;
}
