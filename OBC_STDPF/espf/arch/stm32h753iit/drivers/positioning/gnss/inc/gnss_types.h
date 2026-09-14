/**
 * Copyright (c) 2020-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef GNSS_TYPES_H
#define GNSS_TYPES_H

/**
 * @addtogroup Drivers
 * @{
 * @defgroup gnss
 * @{
 * @file gnss_types.h
 * @}
 * @}
 */

#include "es_cdef.h"
#include "sys_time.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
/**
 * @brief GNSS command buffer size
 * @note  The maximum size of the command buffer is 242 bytes.
 *        This is because FP payload size is 244 bytes, and 2 bytes are required for CR + LF.
 *        Check comments in gnss_ensure_cmd_termination() for more details.
 */
#define GNSS_CMD_BUFFER_DATA_SZ (242U)

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/
/**
 * @brief ASCII message header (structure taken from OEM719 user manual)
 */
typedef struct
{
    char     sync;                // Sync character. The ASCII message is always preceded by a single ‘#’ symbol
    char     message[25];         // The ASCII name of the log or command
    char     port[8];             // The name of the port from which the log was generated
    int32_t  sequence;            // Used for multiple related logs
    float    idle_time;           // Time the processor is idle, calculated once per second. This value is a percentage, ranging from 0 to 100 %
    uint32_t time_status;         // Indicates the quality of the GPS reference time
    uint32_t week;                // GPS reference week number
    float    seconds;             // Seconds from the beginning of the GPS reference week
    uint32_t receiver_status;     // 32-bits representing the status of various hardware and software components of the receiver
    uint32_t reserved;            // Reserved for internal use
    uint32_t receiver_sw_version; // A value (0 - 65535) representing the receiver software build number
    char     end;                 // The character indicates the end of the header ‘;’ symbol
} PACKED gnss_hdr_t;

/**
 * @brief response to LOG BESTXYZA (structure taken from OEM719 user manual)
 */
typedef struct
{
    gnss_hdr_t header;
    uint32_t   p_sol_status;                // Solution status
    uint32_t   pos_type;                    // Position type
    double     px;                          // Position X-coordinate (m)
    double     py;                          // Position Y-coordinate (m)
    double     pz;                          // Position Z-coordinate (m)
    float      pxo;                         // Standard deviation of P-X (m)
    float      pyo;                         // Standard deviation of P-Y (m)
    float      pzo;                         // Standard deviation of P-Z (m)
    uint32_t   v_sol_status;                // Solution status
    uint32_t   vel_type;                    // Velocity type
    double     vx;                          // Velocity vector along X-axis (m/s)
    double     vy;                          // Velocity vector along Y-axis (m/s)
    double     vz;                          // Velocity vector along Z-axis (m/s)
    float      vxo;                         // Standard deviation of V-X (m/s)
    float      vyo;                         // Standard deviation of V-Y (m/s)
    float      vzo;                         // Standard deviation of V-Z (m/s)
    char       stn_id[4];                   // Base station identification
    float      v_latency;                   // A measure of the latency in the velocity time tag in seconds
    float      diff_age;                    // Differential age in seconds
    float      sol_age;                     // Solution age in seconds
    uint8_t    svs;                         // Number of satellites tracked
    uint8_t    solnsvs;                     // Number of satellite vehicles used in solution
    uint8_t    ggl1;                        // Number of GPS plus GLONASS plus BDS L1/B1 used in solution
    uint8_t    solnmultisvs;                // Number of satellites with L1/E1/B1 signals used in solution
    uint8_t    reserved;                    // Reserved
    uint8_t    ext_sol_stat;                // Extended solution status
    uint8_t    galileo_and_beidou_sig_mask; // Galileo and BeiDou signals used mask
    uint8_t    gps_and_glonass_sig_mask;    // GPS and GLONASS signals used mask
    uint32_t   crc32;                       // 32-bit CRC
    char       end[2];                      // CR + LF
} PACKED gnss_xyz_t;

/**
 * @brief response to LOG TIMEA (structure taken from OEM719 user manual)
 */
typedef struct
{
    gnss_hdr_t header;
    uint32_t   clock_status; // Clock model status (not including current measurement data)
    double     offset;       // Receiver clock offset in seconds from GPS system time
    double     offset_std;   // Receiver clock offset standard deviation (s)
    double     utc_offset;   // The offset of GPS system time from UTC time, computed using almanac parameters
    uint32_t   utc_year;     // UTC year
    uint8_t    utc_month;    // UTC month (0-12). If UTC time is unknown, the value for month is 0
    uint8_t    utc_day;      // UTC day (0-31). If UTC time is unknown, the value for day is 0
    uint8_t    utc_hour;     // UTC hour (0-23)
    uint8_t    utc_min;      // UTC minute (0-59)
    uint32_t   utc_ms;       // UTC millisecond (0-60999). Maximum of 60999 when leap second is applied.
    uint32_t   utc_status;   // UTC status 0 = Invalid, 1 = Valid, 2 = Warning
    uint32_t   crc32;        // 32-bit CRC
    char       end[2];       // CR + LF
} PACKED gnss_time_t;

/**
 * @brief gnss command manager status type
 */
typedef enum
{
    CMD_OK,           // command execution is successful
    CMD_ERROR,        // a general error occurred (check uart initialization/transmission, gnss cmd thread/critical section initialization)
    CMD_QUEUE_FULL,   // the command queue is full and can not accept new commands
    CMD_WRONG_PARAMS, // command payload is invalid or command execution callbacks are not specified
    CMD_PROCESSING,   // a command is curently being processed
    CMD_PENDING,      // command is pending to be processed (awaits processing)
    CMD_NOT_FOUND,    // the command is not found in the command queue
    CMD_TIMED_OUT,    // command has timed out, according to the user-specified timeout
    CMD_MUTEX_ERROR,  // mutex acquisition has failed
    CMD_CNT
} gnss_cmd_status_t;

/**
 * @brief gnss command execution callback type
 */
typedef void (*pf_gnss_cmd_exec_cbk_t)(gnss_cmd_status_t cmd_status, const uint32_t duration_ms, const uint8_t cmd_id);

/**
 * @brief gnss command data type
 */
typedef struct
{
    char                   gnss_cmd_buffer[GNSS_CMD_BUFFER_DATA_SZ]; /**< command data buffer */
    uint8_t                gnss_cmd_sz;                              /**< command data size */
    pf_gnss_cmd_exec_cbk_t gnss_cmd_exec_cbk;                        /**< callback invoked on command execution */
    uint32_t               timeout_ms;                               /**< command timeout (dependent on user-supplied timeout or minimum 1ms)*/
    uint32_t               duration_ms;                              /**< command duration (until successful response reception) */
    sys_time_t             time_requested;                           /**< time of command execution request */
    sys_time_t             time_started;                             /**< time of command execution start */
    gnss_cmd_status_t      cmd_status;                               /**< command status */
} gnss_cmd_data_t;

/**
 * @brief gnss command type
 */
typedef struct
{
    gnss_cmd_data_t gnss_cmd_data; /**< command data */
    uint8_t         gnss_cmd_id;   /**< command ID */
} gnss_cmd_t;

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
#endif // __cplusplus
#endif // GNSS_TYPES_H
