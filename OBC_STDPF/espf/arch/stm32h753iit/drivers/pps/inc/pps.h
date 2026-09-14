/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef PPS_H
#define PPS_H

/**
 * @addtogroup Drivers
 * @{
 *
 * @defgroup pps
 * @{
 * Provide pps signal detection
 *
 * @file pps.h
 *
 * @brief pps driver public interface
 *
 * @}
 * @}
 */

#include "es_cdef.h"

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
typedef enum rtc_sync_status
{
    RTC_SYNC_SUCCESS = 0U,                  /* RTC successfully synchronized, using valid GNSS TIME data */
    RTC_SYNC_NOT_YET_SYNCED,                /* RTC not yet synchronized since last reset */
    RTC_SYNC_NULL_PPS_COMPENSATION,         /* RTC sync failed, no meaningful PPS<->data offset compensation registered (it is possible no PPS was detected) */
    RTC_SYNC_SET_SYSTEM_STAMP_FAILURE,      /* RTC sync failed, because setting system stamp (RTC) failed */
    RTC_SYNC_TIME_COMPUTE_FROM_GNSS_FAILURE /* RTC sync failed, because time computation from GNSS data failed (possible invalid / corrupted TIME data) */
} rtc_sync_status_t;

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
 * @brief PPS driver init routine
 */
void pps_init(void);

/**
 * @brief PPS driver deinit routine
 */
void pps_deinit(void);

/**
 * @brief  PPS driver get offset routine
 * @param[out] p_offset_value PPS offset in [microseconds]
 * @retval true if offset is valid, false otherwise
 * @retval false if offset is invalid
 */
bool pps_get_offset(uint32_t *const p_offset_value);

/**
 * @brief  PPS driver get sync status routine
 * @param[in] status RTC sync status to set
 * @return rtc_sync_status_t RTC sync status
 */
void pps_set_rtc_sync_status(rtc_sync_status_t status);

/**
 * @brief  PPS driver increment sync success routine
 */
void pps_increment_sync_success(void);

/**
 * @brief  PPS driver increment sync fail routine
 */
void pps_increment_sync_fail(void);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // PPS_H
