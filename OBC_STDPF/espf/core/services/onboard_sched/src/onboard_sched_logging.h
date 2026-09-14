/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup onboard_sched
 * @{
 *
 * @file     onboard_sched_logging.h
 * @brief    Internal interface to the result logging functionality of the service
 *
 * @}
 *
 */

#ifndef ONBOARD_SCHED_LOGGING_H
#define ONBOARD_SCHED_LOGGING_H

#ifdef COMM_GW_ENABLED
#include "comm_gw.h"
#endif /* COMM_GW_ENABLED */

#ifdef MICROPYTHON_SERVICE_ENABLED
#include "upy.h"
#endif /* MICROPYTHON_SERVICE_ENABLED */

#include "onboard_sched_cfg.h"
#include "onboard_sched_types.h"

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

/** @brief Lists all types of log entries reported by the scheduler. */
typedef enum
{
    ENTRY_SLOT_LOAD_ERROR, /**< Unable to read slot data. Usually due to corruption of the schedule file. */
    ENTRY_CRC_ERROR,       /**< CRC mismatch for an entry. */
    ENTRY_MISSED_ERROR,    /**< The scheduled time for an entry has already passed. */
    NO_CMD_GW_ERROR,       /**< Attempt to execute direct command when command gateway is not enabled in the build. */
    NO_SCRIPTING_ERROR,    /**< Attempt to execute a script when scripting service is not enabled in the build. */
    CMD_RESULT,            /**< Result of command execution. */
    SCRIPT_STARTED,        /**< Entry marks the start of script execution. */
    SCRIPT_RESULT,         /**< Entry marks the end of script execution and contains the result of the operation. */
    SCRIPT_REJECTED,       /**< A script has been rejected because MicroPython is busy executing another one. */
    NUM_SCHED_TYPE         /**< Number of elements in the enumeration. */
} sched_entry_result_type;

/** @brief Attributes common to all log entry types. */
typedef struct
{
    sched_entry_result_type type;      /**< Type of the log entry. */
    uint32_t                timestamp; /**< Time at which the log entry was logged. */
} PACKED sched_out_entry_hdr_t;

/** @brief Type used to define the maximum size of entries that contain data related only to schedule slots. */
typedef struct
{
    char              sched_name[SCHED_MAX_NAME_BUF_LEN]; /**< Name of the schedule file containing the slot. */
    uint32_t          slot_offset;                        /**< Offset of the slot from the beginning of the file. */
    sched_entry_crc_t crc;                                /**< CRC of the schedule entry. */
} PACKED slot_data_max_t;

/** @brief Type used to define specific data related to scheduling. */
typedef struct
{
    uint32_t timestamp; /**< Scheduled time for the entry's execution. */
    uint32_t seq_id;    /**< ID of the scheduled entry. */
} PACKED entry_data_specific_t;

/** @brief Type used to define the maximum size of entries that contain scheduling data without command specifics. */
typedef struct
{
    slot_data_max_t       base_data; /**< The common data so far. */
    entry_data_specific_t spec_data; /**< Data specific to scheduling. */
} PACKED entry_data_max_t;

/** @brief Type used to define the maximum size of entries that contain script data without result. */
typedef struct
{
    entry_data_max_t base_data;                       /**< The common data so far. */
    char             script_name[SCHED_MAX_NAME_LEN]; /**< Name of the script scheduled for execution. */
} PACKED script_data_max_t;

#ifdef COMM_GW_ENABLED

/** @brief Type used to define the maximum size of entries that contain command execution results. */
typedef struct
{
    entry_data_max_t   base_data;                               /**< The common data so far. */
    uint8_t            comm_if_type;                            /**< Protocol interface ID. */
    uint8_t            comm_params_size;                        /**< Size in bytes of the communication parameters data. */
    uint8_t            comm_params[SCHED_COMM_PARAMS_MAX_SIZE]; /**< Communication parameters of the command. */
    comm_gw_comm_res_t cmd_result;                              /**< Status code from the command's execution. */
    uint8_t            resp_bytes[SCHED_CMD_MAX_SIZE];          /**< Buffer for the command's response. */
} PACKED cmd_result_max_t;

#endif /* COMM_GW_ENABLED */

#ifdef MICROPYTHON_SERVICE_ENABLED

/** @brief Type used to define specific script execution data common to SCRIPT_STARTED and SCRIPT_RESULT entries. */
typedef struct
{
    uint8_t          script_id;     /**< ID of the script assigned by the script execution service. */
    eObcPortResult_t script_result; /**< Result of the script's execution. */
} PACKED script_result_common_t;

/** @brief Type used to define specific data related to SCRIPT_STARTED entries. */
typedef struct
{
    uint32_t               timeout; /**< The maximum time in milliseconds that a script is allowed to execute.*/
    script_result_common_t common;  /**< See description of the type. */
} PACKED script_result_started_t;

/** @brief Type used to define specific data related to SCRIPT_RESULT entries. */
typedef struct
{
    script_result_common_t common;   /**< See description of the type. */
    uint32_t               duration; /**< Time in milliseconds taken by the script to execute. */
} PACKED script_result_res_t;

/** @brief Type used to define the maximum size of entries that contain script data with result. */
typedef struct
{
    script_data_max_t base_data; /**< The common data so far. */
    union
    {
        script_result_started_t started_data; /**< If the result entry contains start of execution data */
        script_result_res_t     result_data;  /**< If the result entry contains end of execution data */
    };
} PACKED script_result_max_t;

#endif /* MICROPYTHON_SERVICE_ENABLED */

/** @brief Type used to define the maximum size of a log entry. */
typedef struct
{
    sched_out_entry_hdr_t hdr; /** @brief Common entry header. */
    union
    {
#ifdef COMM_GW_ENABLED
        cmd_result_max_t cmd_buf; /** @brief Buffer needed for log entries of commands. */
#endif                            /* COMM_GW_ENABLED */

#ifdef MICROPYTHON_SERVICE_ENABLED
        script_result_max_t script_buf; /** @brief Buffer needed for log entries of scripts. */
#endif                                  /* MICROPYTHON_SERVICE_ENABLED */

        entry_data_max_t entry_data; /** @brief Logger shall always be able to output scheduling data. */
    };
} PACKED sched_out_entry_max_t;

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
 * @brief Performs initialization activities for the logging part of the scheduling service.
 *
 * @retval true:  Initialization performed successfully and logging can be used
 * @retval false: Something went wrong with initialization of OS objects used by logging.
 *                The scheduling service should not be running.
 *
 */
bool onboard_sched_logging_init(void);

/**
 * @brief Sets the name of the log file.
 *
 * @param name[in]: The name.
 *
 */
void onboard_sched_logging_set_file_name(const char name[SCHED_MAX_NAME_BUF_LEN]);

/**
 * @brief Marks the beginning of a log entry construction. Enters the critical section
 *        for buffer operations and initializes the buffer write index.
 *
 * @note Because there is a critical section entry, make sure that this call is paired
 *       with a call to @ref onboard_sched_logging_end_log
 */
void onboard_sched_logging_start_log(void);

/**
 * @brief Marks the end of a log entry construction. Calculates CRC, performs COBS encoding,
 *        writes to log file and exits the critical section for buffer operations.
 *
 * @param type[in]: Type of the log entry.
 *
 * @note Because there is a critical section exit, make sure that this call is paired
 *       with a call to @ref onboard_sched_logging_start_log
 */
void onboard_sched_logging_end_log(const sched_entry_result_type type);

/**
 * @brief Puts data related to the scheduling slot in the log buffer.
 *
 * @param p_file_name[in]: Null-terminated string with the name of the schedule file.
 * @param offset[in]:      Offset of the slot in the schedule file.
 *
 */
void onboard_sched_logging_add_slot_data(const char *const p_file_name,
                                         const uint32_t    offset);

/**
 * @brief Puts common data related to scheduling in the log buffer.
 *
 * @param timestamp[in]: Null-terminated string with the name of the schedule file.
 * @param seq_id[in]:    ID of the schedule entry.
 *
 */
void onboard_sched_logging_add_entry_data(const uint32_t timestamp,
                                          const uint32_t seq_id);

/**
 * @brief Puts common data related to scripts in the log buffer.
 *
 * @param p_script[in]: Null-terminated string with the name of the executed script.
 *
 */
void onboard_sched_logging_add_script_data(const char *const p_script);

/**
 * @brief Gets a reference to the current position of the log buffer write operations.
 *
 * @return Reference to the position in the log buffer which next write operations shall target.
 *
 * @note This is used only by specific entry execution handlers.
 *
 */
uint8_t *onboard_sched_logging_get_build_buf_current(void);

/**
 * @brief Increments the current position of the log buffer write operations.
 *
 * @param increment[in]: Number to increase the write index by.
 *
 * @note This is used only by specific entry execution handlers.
 *
 */
void onboard_sched_logging_inc_build_index(const sched_entry_payload_size_t increment);

#endif /* ONBOARD_SCHED_LOGGING_H */
