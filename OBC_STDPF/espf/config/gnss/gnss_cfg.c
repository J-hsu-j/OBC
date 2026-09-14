/**
 * Copyright (c) 2020-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup Drivers
 * @{
 *
 * @defgroup gnss
 * @{
 *
 * @file gnss_cfg.c
 *
 * @brief GNSS driver configuration
 *
 * @}
 * @}
 */

#include "gnss.h"
#include "gnss_cfg.h"
#include "pps.h"
#include "sys_time.h"
#include "datacache.h"
#include "trace.h"
#include "assertions.h"
#include <assert.h>

#if defined SDR_ENABLED
#include "sdr_op.h"
#endif // SDR_ENABLED

#if defined CUBEADCS_GEN2_ENABLED
#include "if_sys_conf.h"
#include "cubeadcs_gen2_gw.h"
#include <cubeObc/arch/cubeObc_critical.h>
#endif // CUBEADCS_GEN2_ENABLED

/*
*********************************************************************************************
* INTERNAL DEFINES
*********************************************************************************************
*/

/*
*********************************************************************************************
* INTERNAL TYPES DEFINITION
*********************************************************************************************
*/
/**
 * @brief Seconds with fractional part (offsets accounted for)
 */
typedef double unix_sec_dbl_t;

/**
 * @brief Defines the structure used to deserialize seconds and millisecond fractional part from
 *       the GNSS log data
 */
typedef struct
{
    unix_sec_dbl_t unix_sec_dbl;
    uint16_t       ms;
    uint16_t       us;
} gnss_header_timedata_t;

/*
*********************************************************************************************
* EXTERNAL VARIABLES DEFINITION
*********************************************************************************************
*/

/*
*********************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
*********************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/** @brief State holder for log processing flow
 *  @note This is used to synchronize the position and velocity log with the time log
 *        in case the logs are received at different frequencies.
 *        This flag is set to true when the time log is received and is reset when the position/velocity (pv) log is received.
 *        This is a consequence of the fact that the time log is received at a lower frequency (1Hz) than the position/velocity log (10Hz),
 *        and it is required that only the pv log that corresponds to the time log is sent to the ADCS.
 */
static bool b_send_time_synched_pos = false;

/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
*********************************************************************************************
*/
static bool gnss_time_to_unix(const gnss_time_t *const p_time, gnss_header_timedata_t *const p_gnss_header_time);

static void gnss_pps_rtc_sync_callback(const gnss_time_t *const t);
static void gnss_pps_rtc_sync_compensation(sys_date_t *const p_date, sys_time_t *const p_time);

#if defined SDR_ENABLED
static void sdr_time_sync_callback(const gnss_time_t *const p_time);
#endif // SDR_ENABLED

#if defined CUBEADCS_GEN2_ENABLED
static void send_cmd_to_gen2_cubeadcs(const gnss_time_t *const p_time, const gnss_xyz_t *const p_xyz);
static void gnss_cfg_adcs_sync_callback(void);
#endif // CUBEADCS_GEN2_ENABLED

/*
*********************************************************************************************
* EXTERNAL (NON-STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/
/**
 * @brief gnss user command response callback
 * @note: modify as per application needs
 */
void gnss_user_cmd_resp_cbk(void)
{
    // this callback can be used to do anything with the response data..
}

/**
 * @brief This callback is invoked on every new reception of position/velocity logs.
 *
 * @note Make sure to not put heavy operations inside the callback as this might lead to
 *       missed log events.
 *
 * @param[in] pv Parsed position/velocity log
 */
void gnss_cfg_pv_callback(const gnss_xyz_t *pv)
{
    dc_set_raw_data(DC_DATA_INPUT_INTERNAL, DC_DID_GNSS_BESTXYZ_DATA, pv, sizeof(gnss_xyz_t));

#if defined CUBEADCS_GEN2_ENABLED
    // sending time log to ADCS for synchronization purposes
    if (true == b_send_time_synched_pos)
    {
        b_send_time_synched_pos = false;
        gnss_cfg_adcs_sync_callback();
    }
#endif // CUBEADCS_GEN2_ENABLED
}

/**
 * @brief This callback is invoked on every new reception of time logs.
 *
 * @note Make sure to not put heavy operations inside the callback as this might lead to
 *       missed log events.
 *
 * @note The data is validated only for its format and CRC. In order to make sure that the time itself
 *       is correct the user can use @ref gnss_is_tm_valid()
 *
 * @param[in] tim Parsed time log
 */
void gnss_cfg_tm_callback(const gnss_time_t *t)
{
#if defined GNSS_ENABLED
    gnss_pps_rtc_sync_callback(t);
#endif // GNSS_ENABLED

#if defined SDR_ENABLED
    sdr_time_sync_callback(t);
#endif // SDR_ENABLED

    dc_set_raw_data(DC_DATA_INPUT_INTERNAL, DC_DID_GNSS_TIME_DATA, t, sizeof(gnss_time_t));

#if defined CUBEADCS_GEN2_ENABLED
    b_send_time_synched_pos = true;
    gnss_cfg_adcs_sync_callback();
#endif // CUBEADCS_GEN2_ENABLED
}

/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/

/**
 * @brief This function deserializes the time data from the GNSS log and converts it to a Unix timestamp.
 *
 * @note Make sure to not put heavy operations inside the callback as this might lead to
 *       missed log events.
 *
 * @note Relevant log data is read from DataCache.
 */
static bool gnss_time_to_unix(const gnss_time_t *const p_time, gnss_header_timedata_t *const p_gnss_header_time)
{
    CRIT_ASSERT(NULL != p_time);
    CRIT_ASSERT(NULL != p_gnss_header_time);

    bool res = false;

    // Accumulate Unix seconds by beginning with the whole weeks since the GPS epoch.
    // We use 64-bit integer to avoid multiple overflow checks
    uint64_t unix_sec_long = ((uint64_t)p_time->header.week * NUM_SEC_IN_WEEK) + GPS_TO_UNIX_OFFSET;

    // Add the seconds in current week.
    // Compensate deviation (dOffset) of GPS receiver clock from GPS system time to increase accuracy.
    // Also adjust with UTC offset to get the UTC time encoded in the Unix timestamp.
    // Double type is used to avoid overflow checks.
    const unix_sec_dbl_t unix_sec_dbl = (unix_sec_dbl_t)unix_sec_long + p_time->header.seconds + p_time->utc_offset - p_time->offset;

    if (unix_sec_dbl < ((unix_sec_dbl_t)UINT_MAX + 1)) // Because check for equality is a bit tricky with doubles
    {
        // calculate fractional part
        const unix_sec_dbl_t fract_part = (unix_sec_dbl - (uint32_t)unix_sec_dbl);

        const uint16_t msec = (uint16_t)(fract_part * GPS_SEC_ACCURACY_MULT);
        const uint16_t usec = (uint16_t)(((uint32_t)(fract_part * GPS_SEC_ACCURACY_MULT * NUM_US_IN_MS)) % NUM_US_IN_MS);

        p_gnss_header_time->unix_sec_dbl = unix_sec_dbl; // total seconds with fractional part (offsets accounted for)
        p_gnss_header_time->ms           = msec;         // fractional millisecond part
        p_gnss_header_time->us           = usec;         // fractional microsecond part
        res                              = true;
    }

    return res;
}

#if defined GNSS_ENABLED
/**
 * @brief This callback is invoked on every new reception of logs that contain data to be sent to ADCS module.
 *
 * @param[in] p_time Reference to TIME log data from GNSS
 */
static void gnss_pps_rtc_sync_compensation(sys_date_t *const p_date, sys_time_t *const p_time)
{
    CRIT_ASSERT(NULL != p_time);
    CRIT_ASSERT(NULL != p_date);

    uint32_t pps_offset = 0U;

    // register successful pps compensation event
    if (false != pps_get_offset(&pps_offset))
    {
        pps_set_rtc_sync_status(RTC_SYNC_SUCCESS);
        pps_increment_sync_success();
    }
    else
    {
        pps_set_rtc_sync_status(RTC_SYNC_NULL_PPS_COMPENSATION);
        pps_increment_sync_fail();
    }

    uint32_t total_us = (uint32_t)p_time->us + pps_offset;
    p_time->sec += total_us / NUM_US_IN_SEC;
    total_us %= NUM_US_IN_SEC;

    p_time->ms += total_us / NUM_US_IN_MS;
    p_time->us = total_us % NUM_US_IN_MS;

    uint8_t additional_sec = p_time->ms / NUM_MS_IN_SEC;
    p_time->ms %= NUM_MS_IN_SEC;

    uint16_t temp_ms = p_time->ms;
    uint16_t temp_us = p_time->us;

    datetime_stamp_t date_stamp = { .date = *p_date, .time = *p_time };
    unix_time_t      unix_stamp = datetime_to_unix(&date_stamp) + additional_sec;

    datetime_unix_to_tstamp(unix_stamp, &date_stamp);

    *p_date = date_stamp.date;
    *p_time = date_stamp.time;

    p_time->ms = temp_ms;
    p_time->us = temp_us;
}

/**
 * @brief This callback is invoked on every new reception of GNSS time logs for PPS <-> RTC synchronization.
 *
 * @param[in] p_time Reference to TIME log data from GNSS
 */
static void gnss_pps_rtc_sync_callback(const gnss_time_t *const p_time)
{
    CRIT_ASSERT(NULL != p_time);

    if ((gnss_is_tm_valid(p_time)) &&
        (GNSS_TIM_STAT_FINESTEERING <= p_time->header.time_status) &&
        (GNSS_UTC_STATUS_VALID == p_time->utc_status))
    {
        gnss_header_timedata_t gnss_header_time = { 0 };
        datetime_stamp_t       dt               = { 0 };
        unix_time_t            ut               = 0;

        if (true == gnss_time_to_unix(p_time, &gnss_header_time))
        {
            ut = (U32)gnss_header_time.unix_sec_dbl;
            datetime_unix_to_tstamp(ut, &dt);

            dt.time.ms = gnss_header_time.ms;
            dt.time.us = gnss_header_time.us;

            if (false == sys_time_set_stamp(&dt.date, &dt.time, &gnss_pps_rtc_sync_compensation, 0))
            {
                pps_set_rtc_sync_status(RTC_SYNC_SET_SYSTEM_STAMP_FAILURE);
                ES_TRACE_WARN("[pps] Could not set system time!");
            }
        }
        else
        {
            pps_set_rtc_sync_status(RTC_SYNC_TIME_COMPUTE_FROM_GNSS_FAILURE);
            ES_TRACE_WARN("[pps] Could not compute time from GNSS!");
        }
    }
}

#endif // GNSS_ENABLED

#if defined SDR_ENABLED
/**
 * @brief This callback is invoked on every new reception of GNSS time logs.
 * This is for the purpose of synchronizing the SDR system time, using the GNSS time.
 *
 * @param[in] p_time Reference to TIME log data from GNSS
 */
static void sdr_time_sync_callback(const gnss_time_t *const p_time)
{
    CRIT_ASSERT(NULL != p_time);

    if ((gnss_is_tm_valid(p_time)) &&
        (GNSS_TIM_STAT_COARSE <= p_time->header.time_status) &&
        (GNSS_UTC_STATUS_VALID == p_time->utc_status))
    {
        gnss_header_timedata_t gnss_header_time = { 0 };
        datetime_stamp_t       dt               = { 0 };
        unix_time_t            ut               = 0;

        if (true == gnss_time_to_unix(p_time, &gnss_header_time))
        {
            ut = (U32)gnss_header_time.unix_sec_dbl;
            datetime_unix_to_tstamp(ut, &dt);

            dt.time.ms = gnss_header_time.ms;
            dt.time.us = gnss_header_time.us;

            // send time to sdr if sdr state -> ready
            sdr_time_sync_data_set(&dt);
        }
        else
        {
            ES_TRACE_WARN("[sdr] Could not compute time from GNSS!");
        }
    }
}
#endif // SDR_ENABLED

#if defined CUBEADCS_GEN2_ENABLED
/**
 * @brief Sends time and position data to ADCS for synchronization purposes
 *
 * @param[in] p_time Reference to TIME log data from GNSS
 * @param[in] p_xyz Reference to BESTXYZ log data from GNSS
 */
static void send_cmd_to_gen2_cubeadcs(const gnss_time_t *const p_time, const gnss_xyz_t *const p_xyz)
{
    CRIT_ASSERT(NULL != p_time);
    CRIT_ASSERT(NULL != p_xyz);

    if ((GNSS_XYZ_SOL_STAT_COMPUTED == p_xyz->p_sol_status) && // Is the BESTXYZ position vector data reliable?
        (GNSS_XYZ_SOL_STAT_COMPUTED == p_xyz->v_sol_status) && // Is the BESTXYZ velocity vector data reliable?
        (GNSS_TIM_STAT_FINE <= p_xyz->header.time_status) &&   // Is the quality of GPS time measurements sufficient?
        (GNSS_UTC_STATUS_VALID == p_time->utc_status))         // Can we trust the UTC time data?
    {
        gnss_header_timedata_t gnss_header_time = { 0 };

        if (true == gnss_time_to_unix(p_time, &gnss_header_time))
        {
            // Prepare command to ADCS
            TypesCubeComputerControlProgram8_GnssSensorCmd adcs_cmd = { 0 };
            // No overflow expected for the position coordinates, because they are normally between -7000000m and 7000000m
            adcs_cmd.gnssSatPosX = (S32)(p_xyz->px * NUM_CM_IN_M);
            adcs_cmd.gnssSatPosY = (S32)(p_xyz->py * NUM_CM_IN_M);
            adcs_cmd.gnssSatPosZ = (S32)(p_xyz->pz * NUM_CM_IN_M);
            // No overflow for the velocity vectors, because they cannot exceed 8000m/s
            adcs_cmd.gnssSatVelX     = (S32)(p_xyz->vx * NUM_CM_IN_M);
            adcs_cmd.gnssSatVelY     = (S32)(p_xyz->vy * NUM_CM_IN_M);
            adcs_cmd.gnssSatVelZ     = (S32)(p_xyz->vz * NUM_CM_IN_M);
            adcs_cmd.gnssTimeSeconds = (U32)gnss_header_time.unix_sec_dbl;
            adcs_cmd.gnssTimeNs      = (U32)gnss_header_time.ms * NUM_NS_IN_MS;

            adcs_cmd.syncTime = ADCS_RTC_SYNCH;

            // Send command to ADCS
            if (true == cubeObc_critical_enter(ADCS_CRITICAL_SECTION_TIMEOUT))
            {
                TypeDef_TctlmEndpoint endpoint;
                cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, ADCS_COMM_TIMEOUT);
                const ErrorCode err = tctlmCubeComputerControlProgram8_setGnssSensorCmd(&endpoint, &adcs_cmd);
                cubeObc_critical_exit();
                if (err != CUBEOBC_ERROR_OK)
                {
                    ES_TRACE_WARN("[gnss] could not send GNSS data to Gen2 CubeADCS!");
                }
            }
        }
        else
        {
            ES_TRACE_ERROR("[gnss] overflow error!");
        }
    }
}

/**
 * @brief This callback is invoked on every new reception of logs that contain data to be sent to ADCS module.
 *
 * @note Make sure to not put heavy operations inside the callback as this might lead to
 *       missed log events.
 *
 * @note Relevant log data is read from DataCache.
 */
static void gnss_cfg_adcs_sync_callback(void)
{
    if (false != sys_conf_is_module_active(SYS_MODULE_ID_CUBE_ADCS_GEN2))
    {
        DATA_CACHE_GNSS_TIME_t time_data = { 0 };

        (void)dc_get_gnss_time_data(&time_data);
        static_assert(sizeof(DATA_CACHE_GNSS_TIME_t) == sizeof(gnss_time_t));
        const gnss_time_t *const p_time = (const gnss_time_t *const)&time_data;

        if (true == gnss_is_tm_valid(p_time))
        {
            DATA_CACHE_GNSS_BESTXYZ_t pos_data = { 0 };

            (void)dc_get_gnss_bestxyz_data(&pos_data);
            static_assert(sizeof(DATA_CACHE_GNSS_BESTXYZ_t) == sizeof(gnss_xyz_t));
            const gnss_xyz_t *const p_xyz = (const gnss_xyz_t *const)&pos_data;

            if (fabs(p_xyz->header.seconds - p_time->header.seconds) < REF_TIME_EPSILON) // Are TIME and BESTXYZ logs for the same second?
            {
                send_cmd_to_gen2_cubeadcs(p_time, p_xyz);
            }
        }
    }
}

#endif // CUBEADCS_GEN2_ENABLED
