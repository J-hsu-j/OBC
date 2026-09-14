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
 * @file     onboard_sched_logging.c
 * @brief    Implementation of the result logging functionality of the service
 *
 * @}
 *
 */

#include <string.h>
#include "onboard_sched_logging.h"

#include "fm_mng.h"
#include "trace.h"
#include "crc16-ccitt.h"
#include "cobs.h"
#include "datetime.h"
#include "assertions.h"
#include "cmsis_os2.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
/** @brief Number of entry-specific bytes of the longest entry type. */
#define OUT_ENTRY_MAX_LEN sizeof(sched_out_entry_max_t)

/** @brief Size in bytes of the buffer used for COBS encoding of log entries. */
#define COBS_ENC_BUF_SIZE (OUT_ENTRY_MAX_LEN + OUT_ENTRY_MAX_LEN / 254 + 2)

/** @brief Value of the delimiter used in COBS encoding to separate the packets (in this case log entries). */
#define COBS_FRAME_DELIMITER 0

/** @brief File extension for the schedule execution log files. */
#define SCHED_LOG_EXT ".slog"

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

INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/** @brief Attributes of the mutex used for critical section on output buffer operations. */
static const osMutexAttr_t sched_log_buf_mutex_attr = {
    .name      = "sched_log_buf",
    .attr_bits = osMutexPrioInherit,
    .cb_mem    = NULL,
    .cb_size   = 0U
};

/** @brief Mutex used for critical section on output buffer operations. */
static osMutexId_t h_sched_log_buf_mutex = NULL;

/** @brief Buffer used for COBS encoding of the separate log entries. */
static uint8_t cobs_enc_buf[COBS_ENC_BUF_SIZE] = { 0 };

/** @brief Name of the current file used to log scheduler operation. */
static char sched_log_file_name[SCHED_MAX_NAME_BUF_LEN] = { 0 };

/** @brief Buffer where the log entries are being constructed. This is done by gradually appending
 *         bytes depending on the entry type (error, execution result, etc.). */
static uint8_t entry_build_buf[OUT_ENTRY_MAX_LEN] = { 0 };

/** @brief Tracks the current write position in the build buffer. */
static sched_entry_payload_size_t build_buf_write_idx = 0;

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/

/**
 * @brief Sets header data for the current log entry.
 *
 * @param type[in]: Type of the entry.
 *
 */
static void onboard_sched_logging_set_header(const sched_entry_result_type type);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

bool onboard_sched_logging_init(void)
{
    bool ret = false;

    h_sched_log_buf_mutex = osMutexNew(&sched_log_buf_mutex_attr);
    if (NULL != h_sched_log_buf_mutex)
    {
        ret = true;
    }

    return ret;
}

void onboard_sched_logging_set_file_name(const char file_name[SCHED_MAX_NAME_BUF_LEN])
{
    char *const p_ext = strstr(file_name, SCHED_FILE_EXT); // This function is called after validation
                                                           // of file extension so there is no need to
                                                           // check p_ext
    const size_t name_part_size = (size_t)p_ext - (size_t)file_name;

    // Copy name up to the extension
    memcpy(sched_log_file_name, file_name, name_part_size);

    // Add the new extension
    (void)strncpy(&sched_log_file_name[name_part_size], SCHED_LOG_EXT, sizeof(sched_log_file_name) - name_part_size);
    sched_log_file_name[sizeof(sched_log_file_name) - 1] = STRING_TERMINATOR; // For safety
}

void onboard_sched_logging_start_log(void)
{
    // The result of osMutexAcquire is not used, the rationale being that a failure
    // in acquiring the output buffer mutex must not stop scheduling operations
    (void)osMutexAcquire(h_sched_log_buf_mutex, osWaitForever);

    // We are starting a new construction of the scheduling result. Reset the write index,
    // but leave some space for entry header
    build_buf_write_idx = sizeof(sched_out_entry_hdr_t);

    ES_TRACE_DEBUG("onboard_sched new entry [\n");
}

void onboard_sched_logging_end_log(const sched_entry_result_type type)
{
    const size_t entry_size     = build_buf_write_idx;
    const size_t entry_size_crc = entry_size + sizeof(sched_entry_crc_t);

    if (entry_size_crc > OUT_ENTRY_MAX_LEN)
    {
        ES_TRACE_WARN("Result of scheduled command is too big to log!");
        (void)osMutexRelease(h_sched_log_buf_mutex);
        return;
    }

    // Set common header data in the builder buffer
    onboard_sched_logging_set_header(type);

    // Calculate CRC
    const sched_entry_crc_t crc                        = crc16_ccitt_table(entry_build_buf, entry_size);
    *(sched_entry_crc_t *)&entry_build_buf[entry_size] = crc;

    // Apply COBS encoding
    uint32_t cobs_len        = cobs_encode(entry_build_buf, entry_size_crc, cobs_enc_buf);
    cobs_enc_buf[cobs_len++] = COBS_FRAME_DELIMITER;

    // Write file
    fm_file_obj_t h_file;
    fm_result_t   file_res = fm_open(&h_file, sched_log_file_name, FM_MODE_WRITE | FM_MODE_OPEN_APPEND);
    if (FM_RES_OK == file_res)
    {
        // Set the offset to next element
        uint32_t written_bytes = 0;
        file_res               = fm_write(&h_file, cobs_enc_buf, cobs_len, &written_bytes);
        if ((FM_RES_OK != file_res) || (written_bytes != cobs_len))
        {
            ES_TRACE_WARN("Error writing to log file %s", sched_log_file_name);
        }
        fm_close(&h_file);
    }
    else
    {
        ES_TRACE_WARN("Could not open log file %s", sched_log_file_name);
    }

    // Since this is the last operation that uses the builder buffer we exit the critical
    // section here
    (void)osMutexRelease(h_sched_log_buf_mutex);

    ES_TRACE_DEBUG("] of type %d\n", type);
}

void onboard_sched_logging_add_slot_data(const char *const p_file_name, const uint32_t offset)
{
    if ((build_buf_write_idx <= sizeof(sched_out_entry_hdr_t)) && (NULL != p_file_name))
    {
        char *const p_out_file = (char *const)&entry_build_buf[build_buf_write_idx];
        (void)strncpy(p_out_file, p_file_name, SCHED_MAX_NAME_BUF_LEN);
        build_buf_write_idx += (sched_entry_payload_size_t)strnlen(p_out_file, SCHED_MAX_NAME_LEN);
        entry_build_buf[build_buf_write_idx++]               = STRING_TERMINATOR; // for safety
        *(uint32_t *)(&entry_build_buf[build_buf_write_idx]) = offset;
        build_buf_write_idx += sizeof(offset);

        ES_TRACE_DEBUG("sched_name=%s, offset=%d\n");
    }
    else
    {
        BREAK_ASSERT(false);
    }
}

void onboard_sched_logging_add_entry_data(const uint32_t timestamp,
                                          const uint32_t seq_id)
{
    if (build_buf_write_idx <= sizeof(slot_data_max_t))
    {
        entry_data_specific_t *const p_out_data = (entry_data_specific_t *const)&entry_build_buf[build_buf_write_idx];
        // Add the original schedule timestamp
        p_out_data->timestamp = timestamp;

        // Add the original schedule sequence ID
        p_out_data->seq_id = seq_id;

        build_buf_write_idx += sizeof(entry_data_specific_t);

        ES_TRACE_DEBUG(", timestamp=%d, seq_id=%d\n", timestamp, seq_id);
    }
    else
    {
        BREAK_ASSERT(false);
    }
}

void onboard_sched_logging_add_script_data(const char *const p_script_name)
{
    if ((build_buf_write_idx <= sizeof(entry_data_max_t)) && (NULL != p_script_name))
    {
        const size_t name_size = strnlen(p_script_name, SCHED_MAX_NAME_LEN);
        (void)strncpy((char *)&entry_build_buf[build_buf_write_idx], p_script_name, name_size + 1);
        build_buf_write_idx += name_size;
        entry_build_buf[build_buf_write_idx++] = STRING_TERMINATOR;

        ES_TRACE_DEBUG("script_name= %s\n", p_script_name);
    }
    else
    {
        BREAK_ASSERT(false);
    }
}

uint8_t *onboard_sched_logging_get_build_buf_current(void)
{
    uint8_t *ret = NULL;

    if (build_buf_write_idx < sizeof(entry_build_buf))
    {
        ret = &entry_build_buf[build_buf_write_idx];
    }

    return ret;
}

void onboard_sched_logging_inc_build_index(const sched_entry_payload_size_t increment)
{
    // Check is only for command size overflow because this function is meant to be used for
    // payload bytes only
    if (increment <= SCHED_CMD_MAX_SIZE)
    {
        build_buf_write_idx += increment;
    }
    else
    {
        build_buf_write_idx += SCHED_CMD_MAX_SIZE;
    }
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

static void onboard_sched_logging_set_header(const sched_entry_result_type type)
{
    sched_out_entry_hdr_t *const p_hdr = (sched_out_entry_hdr_t *)&entry_build_buf[0];
    p_hdr->type                        = type;
    p_hdr->timestamp                   = datetime_to_unix_now();
}
