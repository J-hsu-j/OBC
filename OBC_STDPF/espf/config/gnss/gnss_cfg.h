/**
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef GNSS_CFG_H
#define GNSS_CFG_H

/**
 * @addtogroup Drivers
 * @{
 * @defgroup gnss
 * @{
 * gnss communication interface
 *
 * @file gnss.h
 * @brief gnss driver
 * @}
 * @}
 */

#include "timer.h"
#include "cmsis_os2.h"
#include "gnss_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
/**
 * @brief Conversion multiplier for position and velocity vector data
 */
#define NUM_CM_IN_M (100U)

/**
 * @brief Conversion multiplier for fractional part of the Unix time stamp
 */
#define NUM_NS_IN_MS (1000000U)

/**
 * @brief Number of microseconds in a millisecond
 */
#define NUM_US_IN_MS (1000U)

/**
 * @brief Number of microseconds in a second
 */
#define NUM_US_IN_SEC (1000000U)

/**
 * @brief Number of milliseconds in a second
 */
#define NUM_MS_IN_SEC (1000U)

/**
 * @brief 60 seconds * 60 minutes * 24 hours * 7 days
 */
#define NUM_SEC_IN_WEEK (604800U)

/**
 * @brief The number of seconds between 00:00:00 UTC on 1 January 1970 (Unix epoch) and 00:00:00 UTC on January 6, 1980 (GPS epoch)
 */
#define GPS_TO_UNIX_OFFSET (315964800U)

/**
 * @brief Value of the clock status which indicates that the clock data can be used
 */
#define GNSS_CLOCK_STATUS_VALID (0U)

/**
 * @brief Value of the position and velocity vectors' solution status which indicates that XYZ data can be used
 */
#define GNSS_XYZ_SOL_STAT_COMPUTED (0U)

/**
 * @brief Value of the time status which indicates that time data can be used (resolution +-10milliseconds)
 */
#define GNSS_TIM_STAT_COARSE (100U)

/**
 * @brief Value of the lowest time status which indicates that time is known with sufficient precision
 */
#define GNSS_TIM_STAT_FINE (160U)

/**
 * @brief Time is fine set and is being steered - we need this time status for microsecond precision
 */
#define GNSS_TIM_STAT_FINESTEERING (180U)

/**
 * @brief Value of the UTC status which indicates that time data cannot be used
 */
#define GNSS_UTC_STATUS_INVALID (0U)

/**
 * @brief Value of the UTC status which indicates that time data can be used
 */
#define GNSS_UTC_STATUS_VALID (1U)

/**
 * @brief Value of the UTC status which indicates that the leap second value is used as a default due to the lack of an almanac
 * @note In general, the utc status can have the following values:
            1. INVALID = 0
            2. VALID = 1
            3. WARNING = 2
         When the value is WARNING, this means that the transceiver has not yet received almanac data from any satellite of a constellations it has been tuning in to.
         In general, for position and time, we need 4 satellites. If the receiver has not received recent almanac data, it might have outdated or incorrect assumptions
         about satellite positions. This can lead to errors in calculating the travel time of the signals, subsequently affecting the accuracy of the time estimation.
         Since this function is used for synchronizing the OBC RTC, for maximum accuracy, TIME data, carrying a utc WARNING status is unacceptable. NovAtel have not provided
         a detailed description of the accuracy impact if we use data carrying the WARNING status, but lack of almanac is synonymous with "just going to assume my last available data is correct and go with it.."
 */
#define GNSS_UTC_STATUS_WARNING (2U)

/**
 * @brief Multiplier reciprocal to the accuracy of the GPS seconds reported by GNSS (milliseconds)
 */
#define GPS_SEC_ACCURACY_MULT (1000U)

/**
 * @brief Floating point comparison epsilon for the GPS seconds of TIME and BESTXYZ GNSS logs
 */
#define REF_TIME_EPSILON (0.5F)

/**
 * @brief Timeout in milliseconds for the attempt to enter critical section of the ADCS API
 *
 * @note This timeout should be as small as possible. It is better to skip sending GNSS data than to send it with
 *       an unknown delay due to other components holding the critical section for an unknown amount of time
 */
#define ADCS_CRITICAL_SECTION_TIMEOUT (1U)

/**
 * @brief Timeout in milliseconds of the command to ADCS which carries time and position data
 *
 * @note Value must be chosen so that the time between PPS pulse and completed transmission of the data
 *       is less than 100ms. This is requested by CubeSpace
 */
#define ADCS_COMM_TIMEOUT (60U)

/**
 * @brief Defines whether the RTC of Gen2 CubeADCS is to be synchronized with the time data coming from GNSS
 *
 * @note  Usually set to FALSE if the ADCS has the PPS of the GNSS as direct input
 */
#define ADCS_RTC_SYNCH FALSE

/**
 * @brief Stack size dedicated to the gnss initialization task
 */
#define GNSS_INIT_TASK_STACK_SIZE (2U * 1024U)

/**
 * @brief Stack size dedicated to the gnss response task
 */
#define GNSS_RESP_TASK_STACK_SIZE (3U * 1024U)

/**
 * @brief Stack size dedicated to the gnss command task
 */
#define GNSS_CMD_TASK_STACK_SIZE (4U * 1024U)

/**
 * @brief maximum number of commands in the queue
 */
#define GNSS_CMD_QUEUE_LEN (2U)

/**
 * @brief gnss user command minimum timeout duration in milliseconds
 */
#define GNSS_CMD_MIN_TIMEOUT_MS (1U)

/**
 * @brief gnss user command task period
 */
#define GNSS_CMD_TASK_PERIOD_MS (1000U)

/** @brief gnss typical after operation wait period */
#define GNSS_AFTER_OP_WAIT_MS (100U)

/** @brief gnss no log response timeout */
#define GNSS_NO_RESPONSE_TIMEOUT_MS (30000U)

/** @brief gnss boot timeout - communication is attempted after this time has elapsed */
#define GNSS_BOOT_TIMEOUT_MS (10000U)

/** @brief gnss critical section timeout */
#define GNSS_LOCK_TIMEOUT_MS ((uint32_t)1000U)

/** @brief flag used to signal gnss to power on */
#define GNSS_START_FLAG (0x02U) // binary 0010

/** @brief command to turn off RX status event log (if the cmd is changed, the CRC32 has to be recalculated! - EXCLUDE THE # CHARACTER) */
#define GNSS_CMD_UNLOG_RXSTATUSEVENTA "#UNLOGA,COM1,0,0,UNKNOWN,0,0.0,0,0,0;COM1,RXSTATUSEVENTA*c78f6618\r\n"

/** @brief command to configure BESTXYZ log (if the cmd is changed, the CRC32 has to be recalculated - EXCLUDE THE # CHARACTER) */
#define GNSS_CMD_LOG_BESTXYZA "#LOGA,COM1,0,0,UNKNOWN,0,0.0,0,0,0;COM1,BESTXYZA,ONTIME,0.100000*57ed88df\r\n"

/** @brief command to configure TIME log (if the cmd is changed, the CRC32 has to be recalculated! - EXCLUDE THE # CHARACTER) */
#define GNSS_CMD_LOG_TIMEA "#LOGA,COM1,0,0,UNKNOWN,0,0.0,0,0,0;COM1,TIMEA,ONTIME,1.000000*87b62eba\r\n"

/** @brief number of logs to configure */
#define GNSS_LOGS_CNT (3U)

/** @brief abbreviated ASCII BESTXYZ log response header */
#define GNSS_RESP_LOG_BESTXYZA_HDR "#BESTXYZA"

/** @brief abbreviated ASCII TIME log response header */
#define GNSS_RESP_LOG_TIMEA_HDR "#TIMEA"

/** @brief gnss strlen */
#define GNSS_STATIC_STRLEN(str) (sizeof(str) - 1)

/** @brief ascii user commands response status - OK */
#define GNSS_CMD_RESP_STATUS_OK "<OK"

/** @brief ascii user commands response status size - OK */
#define GNSS_CMD_RESP_STATUS_OK_SZ (GNSS_STATIC_STRLEN(GNSS_CMD_RESP_STATUS_OK))

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

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* GNSS_CFG_H */
