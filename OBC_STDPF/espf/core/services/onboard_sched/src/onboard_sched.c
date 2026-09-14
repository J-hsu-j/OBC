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
 * @file     onboard_sched.c
 * @brief    Main implementation of the onboard scheduling service
 *
 * @}
 *
 */

#include <string.h>

#include "cmsis_os.h"
#include "onboard_sched.h"
#include "onboard_sched_types.h"
#include "fm_mng.h"
#include "nvm.h"
#include "crc16-ccitt.h"
#include "datetime.h"
#include "trace.h"
#include "taskmon.h"
#include "FP_onboard_schedProtocolTypes.h"
#include "onboard_sched_scripting.h"
#include "onboard_sched_commands.h"
#include "onboard_sched_logging.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

/** @brief Offset of the first schedule slot from the beginning of the schedule file. */
#define FIRST_SLOT_OFFSET (uint32_t)sizeof(sched_file_hdr_t)

/** @brief String put at the beginning of the schedule used as a human-readable hint about the contents of the file. */
#define SCHED_FILE_ASCII_ID "SCHED"

/** @brief Response to be returned on requests for the current active schedule when there isn't one configured. */
#define NO_SCHEDULE_MSG "No active schedule"

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

/** @brief Schedule file header. */
typedef struct
{
    char     ascii_id[sizeof(SCHED_FILE_ASCII_ID)]; /**< String used to show that the file is a schedule file. */
    uint8_t  format_version_major;                  /**< Major version of the schedule file format. Reserved for future use. */
    uint8_t  format_version_minor;                  /**< Minor version of the schedule file format. Reserved for future use. */
    uint32_t next_free_offset;                      /**< Offset from the beginning of file to the first free address where new
                                                         slots can be entered. Reserved for future use.*/
} PACKED sched_file_hdr_t;

/** @brief Service data contained in one schedule slot. */
typedef struct
{
    sched_slot_hdr_t header; /**< Data related to the slot management part of schedule execution. */
    sched_entry_t    entry;  /**< Scheduling parameters of the entry. */
} PACKED sched_slot_t;

/** @brief All the data contained in one schedule slot. */
typedef struct
{
    sched_slot_t service_data;                                                                     /**< See the definition of @ref sched_slot_t. */
    uint8_t      buf[sizeof(cmd_service_data_t) + SCHED_CMD_MAX_SIZE + sizeof(sched_entry_crc_t)]; /**< Command data + CRC. */
} PACKED sched_slot_buf_t;

/** @brief Contextual data used when schedule entries are dispatching to their respective execution handlers. */
typedef struct
{
    const char *const             p_sched_name; /**< @brief Name of the schedule file. */
    const sched_entry_t *const    p_entry;      /**< @brief Reference to schedule entry data according to @ref sched_entry_t. */
    const sched_slot_buf_t *const p_slot_buf;   /**< @brief Reference to service data according to @ref sched_slot_buf_t. */
    const uint32_t                slot_offset;  /**< @brief Offset in bytes of a slot from the beginning of the schedule file. */
} sched_disp_ctx_t;

/** @brief Status of trying to load slot data from the schedule file. */
typedef enum
{
    SLOT_LOAD_OK,        /**< @brief Slot data loaded successfully from file. */
    SLOT_LOAD_NOT_READY, /**< @brief File management service is not ready. */
    SLOT_LOAD_EOF,       /**< @brief End of schedule file reached and slot cannot be loaded. */
    SLOT_LOAD_ERROR      /**< @brief Some other error occurred while reading from the schedule file. */
} slot_load_result_t;

/** @brief Result of checking the scheduled time of a entry. */
typedef enum
{
    RELEASE, /**< @brief It is time to release the entry. */
    FUTURE,  /**< @brief Entry is scheduled for some time in the future. */
    MISSED   /**< @brief Entry has missed its intended release time. */
} time_check_result_t;

/** @brief Decision on how to proceed after the execution of a schedule entry. */
typedef enum
{
    STAY, /**< @brief Entry was not executed, but shall be attempted again. For example, because it is not yet time ). */
    NEXT, /**< @brief Next entry shall be processed. */
    ABORT /**< @brief Execution of the entire schedule shall be aborted due to an error or end of schedule. */
} entry_exec_result_t;

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

/** @brief Attributes of the main OS task of the scheduling service. */
static const osThreadAttr_t sched_task_attr = {
    .name       = "onboard_sched",
    .priority   = osPriorityNormal,
    .stack_size = SCHED_MAIN_STACK_SIZE,
    .attr_bits  = osThreadDetached,
    .cb_mem     = NULL,
    .cb_size    = 0U,
    .stack_mem  = NULL,
    .tz_module  = 0U,
    .reserved   = 0U
};

/** @brief Attributes of the mutex used for critical section on the schedule file request buffer. */
static const osMutexAttr_t file_mutex_attr = {
    .name      = "sched_file",
    .attr_bits = osMutexPrioInherit,
    .cb_mem    = NULL,
    .cb_size   = 0U
};

/** @brief Reference to the no active schedule string. */
static const char *p_no_schedule_str = NO_SCHEDULE_MSG;

/** @brief Handler for the main OS task of the scheduling service. */
static osThreadId_t h_sched_task = NULL;

/** @brief Handler for the mutex on schedule file request buffer. */
static osMutexId_t h_sched_file_mutex = NULL;

/** @brief Buffer used to store the name of a newly requested schedule file. */
static char requested_file[SCHED_MAX_NAME_BUF_LEN] = { 0 };

/** @brief Buffer used to store the currently processed entry. */
static sched_slot_buf_t current_slot = { 0 };

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/

/**
 * @brief Main task of the scheduling service.
 *
 * @param p_args: Not used
 *
 */
static void onboard_sched_task(void *p_args);

/**
 * @brief Loads slot from the schedule file and attempts to execute the entry. Performs CRC and
 *        schedule time checks.
 *
 * @param p_file_name[in]: Name of the schedule this entry is part of.
 * @param p_slot_buf[in]:  Reference to the slot data of the entry.
 * @param slot_offset[in]: Offset of the entry's slot from the beginning of the schedule file.
 * @param sys_time:        Current system time.
 *
 * @return See description of @ref entry_exec_result_t
 */
static entry_exec_result_t onboard_sched_execute_entry(const char *const       p_file_name,
                                                       sched_slot_buf_t *const p_slot_buf,
                                                       const uint32_t          slot_offset,
                                                       const unix_time_t       sys_time);

/**
 * @brief Attempts to execute as many entries as possible within one iteration of the main task.
 *
 * @retval true:  Execution of the schedule shall proceed
 * @retval false: Execution of the schedule shall be aborted
 *
 */
static bool onboard_sched_execute_schedule(void);

/**
 * @brief Reads slot data from the schedule file.
 *
 * @param p_file_name[in]: Name of the schedule file.
 * @param p_slot[out]: Buffer to load the slot data into.
 * @param slot_offset[in]: Offset of the slot from the beginning of the schedule file.
 *
 * @return See description of @ref slot_load_result_t
 *
 */
static slot_load_result_t onboard_sched_load_slot(const char *const p_file_name, sched_slot_buf_t *const p_slot, const uint32_t slot_offset);

/**
 * @brief Performs a CRC check on the schedule entry.
 *
 * @param p_entry[in]: Reference to the entry data.
 *
 * @retval true:  Calculated and stored CRCs match.
 * @retval false: Calculated and stored CRCs don't match.
 *
 * @note The function relies on the argument pointing to a place in a full-sized slot buffer.
 *       This is required because the calculation goes outside the boundaries of a @ref sched_entry_t structure.
 */
static bool onboard_sched_check_crc(const sched_entry_t *const p_entry);

/**
 * @brief Checks if a schedule entry is to be released.
 *
 * @param sys_time[in]:      Current system time.
 * @param entry_time[in]:    Time at which the entry is scheduled to be released.
 *
 * @return See description of @ref time_check_result_t.
 *
 */
static time_check_result_t onboard_sched_check_time(const unix_time_t sys_time, const unix_time_t entry_time);

/**
 * @brief Calls the appropriate handler for a scheduled entry.
 *
 * @param p_ctx[in]: Dispatch context used to decide which handler to call.
 *
 */
static void onboard_sched_dispatch_cmd(const sched_disp_ctx_t *const p_ctx);

/**
 * @brief Verifies that a specified file name has a specified extension.
 *
 * @param p_name[in]:  Null-terminated path to the file.
 * @param p_ext[in]:   Null-terminated checked extension.
 * @param ext_len[in]: Length of the extension string. Excludes the null terminator.
 *
 * @retval true:  File extension matches the one provided.
 * @retval false: File extention doesn't match.
 *
 */
static bool onboard_sched_check_file_extension(const char *const p_name,
                                               const char *const p_ext,
                                               const size_t      ext_len);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

bool onboard_sched_init(void)
{
    bool ret = false;

    h_sched_task = osThreadNew(onboard_sched_task, NULL, &sched_task_attr);
    if (NULL != h_sched_task)
    {
        h_sched_file_mutex = osMutexNew(&file_mutex_attr);

        if (NULL != h_sched_file_mutex)
        {
            ret = true;
        }
    }

    task_mon_task_initialized(TASK_ID_ONBOARD_SCHED);
    task_mon_set_task_policy(TASK_ID_ONBOARD_SCHED, TASK_MON_POLICY_MONITOR);

    ret = ((false != ret) && onboard_sched_logging_init());

    return ret;
}

ONBOARD_SCHED_SchedLoadResult_t onboard_sched_set_active_schedule(const char *const p_path)
{

    if (ONBOARD_SCHED_SCHEDSTATE_RUNNING == onboard_sched_get_state())
    {
        return ONBOARD_SCHED_SCHEDLOADRESULT_ERROR_SCHED_RUNNING;
    }

    ONBOARD_SCHED_SchedLoadResult_t ret = ONBOARD_SCHED_SCHEDLOADRESULT_ERROR_NO_FILE;

    // Check if this is a valid schedule file
    if (false != onboard_sched_check_file_extension(p_path, SCHED_FILE_EXT, sizeof(SCHED_FILE_EXT) - 1))
    {
        fm_file_obj_t     h_file;
        const fm_result_t file_res = fm_open(&h_file, p_path, FM_MODE_READ);
        if (FM_RES_OK == file_res)
        {
            if (osOK == osMutexAcquire(h_sched_file_mutex, osWaitForever))
            {
                strncpy(requested_file, p_path, SCHED_MAX_NAME_BUF_LEN);
                requested_file[SCHED_MAX_NAME_LEN] = STRING_TERMINATOR; // For safety

                (void)osMutexRelease(h_sched_file_mutex);

                ret = ONBOARD_SCHED_SCHEDLOADRESULT_SUCCESS;
            }
            else
            {
                ret = ONBOARD_SCHED_SCHEDLOADRESULT_ERROR_SYSTEM;
            }

            (void)fm_close(&h_file);
        }
        else if (FM_RES_NO_FILE != file_res)
        {
            ret = ONBOARD_SCHED_SCHEDLOADRESULT_ERROR_SYSTEM;
        }
        else
        {
            // File not found
        }
    }

    return ret;
}

ONBOARD_SCHED_SchedLoadResult_t onboard_sched_get_active_schedule(char *const p_path, const uint8_t max_size, uint8_t *const p_size)
{
    ONBOARD_SCHED_SchedLoadResult_t ret = ONBOARD_SCHED_SCHEDLOADRESULT_ERROR_SYSTEM;

    if ((osOK == osMutexAcquire(h_sched_file_mutex, osWaitForever)) && (NULL != p_path) && (NULL != p_size))
    {
        onboard_sched_nvm_data_t nvm_data;
        Nvm_GetBlockById(NVM_BLOCK_SCHEDULER_DATA, &nvm_data);
        if (STRING_TERMINATOR != nvm_data.last_schedule[0])
        {
            strncpy(p_path, nvm_data.last_schedule, max_size); // Current file name is always null-terminated
            *p_size = (uint8_t)strnlen(nvm_data.last_schedule, SCHED_MAX_NAME_LEN);
            ret     = ONBOARD_SCHED_SCHEDLOADRESULT_SUCCESS;
        }
        else
        {
            strncpy(p_path, p_no_schedule_str, max_size);
            *p_size = sizeof(NO_SCHEDULE_MSG);
            ret     = ONBOARD_SCHED_SCHEDLOADRESULT_ERROR_NO_FILE;
        }

        p_path[max_size - 1] = STRING_TERMINATOR;

        (void)osMutexRelease(h_sched_file_mutex);
    }

    return ret;
}

void onboard_sched_set_state(const ONBOARD_SCHED_SchedState_t state)
{
    onboard_sched_nvm_data_t nvm_data;
    Nvm_GetBlockById(NVM_BLOCK_SCHEDULER_DATA, &nvm_data);
    nvm_data.sched_state = state;
    Nvm_SetBlockById(NVM_BLOCK_SCHEDULER_DATA, &nvm_data, NVMSETBLOCK_STORE_IMMEDIATELY);
}

ONBOARD_SCHED_SchedState_t onboard_sched_get_state(void)
{
    onboard_sched_nvm_data_t nvm_data;
    Nvm_GetBlockById(NVM_BLOCK_SCHEDULER_DATA, &nvm_data);

    return nvm_data.sched_state;
}

uint32_t onboard_sched_get_next_slot(void)
{
    onboard_sched_nvm_data_t nvm_data;
    Nvm_GetBlockById(NVM_BLOCK_SCHEDULER_DATA, &nvm_data);

    return nvm_data.active_slot_offset;
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

static void onboard_sched_task(void *p_args)
{
    (void)p_args;

    // After reset check NVM for valid stored schedule file
    onboard_sched_nvm_data_t nvm_data;
    Nvm_GetBlockById(NVM_BLOCK_SCHEDULER_DATA, &nvm_data);
    bool schedule_valid                                        = false;
    nvm_data.last_schedule[sizeof(nvm_data.last_schedule) - 1] = STRING_TERMINATOR; // For safety in next calls
    const char *const p_name                                   = nvm_data.last_schedule;

    if ((p_name[0] != STRING_TERMINATOR) &&
        (false != onboard_sched_check_file_extension(p_name, SCHED_FILE_EXT, sizeof(SCHED_FILE_EXT) - 1)))
    {
        // Restore the name of the persisted schedule's log file
        onboard_sched_logging_set_file_name(nvm_data.last_schedule);
        schedule_valid = true;
    }

    while (1)
    {
        // Set the current file
        if (osOK == osMutexAcquire(h_sched_file_mutex, osWaitForever))
        {
            if (0 < strnlen(requested_file, SCHED_MAX_NAME_LEN))
            {
                // There is a newly requested file. Copy its name as current file
                Nvm_GetBlockById(NVM_BLOCK_SCHEDULER_DATA, &nvm_data);
                strncpy(nvm_data.last_schedule, requested_file, SCHED_MAX_NAME_BUF_LEN);
                nvm_data.last_schedule[SCHED_MAX_NAME_LEN] = STRING_TERMINATOR; // For safety

                // Set a new name for the log file
                onboard_sched_logging_set_file_name(nvm_data.last_schedule);

                // Mark the request buffer as empty string
                requested_file[0] = STRING_TERMINATOR;
                // Set active index to the first slot in the file
                nvm_data.active_slot_offset = FIRST_SLOT_OFFSET;
                Nvm_SetBlockById(NVM_BLOCK_SCHEDULER_DATA, &nvm_data, NVMSETBLOCK_STORE_IMMEDIATELY);

                schedule_valid = true;
            }

            osMutexRelease(h_sched_file_mutex);
        }

        if ((ONBOARD_SCHED_SCHEDSTATE_RUNNING == onboard_sched_get_state()) && schedule_valid)
        {
            schedule_valid = onboard_sched_execute_schedule();
        }

        task_mon_i_am_alive(TASK_ID_ONBOARD_SCHED);
        task_mon_low_stack_check(TASK_ID_ONBOARD_SCHED);

        osDelay(SCHED_CYCLE_PERIOD);
    }
}

static entry_exec_result_t onboard_sched_execute_entry(const char *const       p_file_name,
                                                       sched_slot_buf_t *const p_slot_buf,
                                                       const uint32_t          slot_offset,
                                                       const unix_time_t       sys_time)
{
    CRIT_ASSERT((NULL != p_file_name) && (NULL != p_slot_buf));

    entry_exec_result_t ret = STAY;

    const sched_entry_t *const p_entry  = &(p_slot_buf->service_data.entry);
    const slot_load_result_t   load_res = onboard_sched_load_slot(p_file_name, p_slot_buf, slot_offset);

    if (SLOT_LOAD_OK == load_res)
    {
        // Check CRC of the entry
        bool proceed = onboard_sched_check_crc(p_entry);

        // Check if it is time to release the entry
        if (false != proceed)
        {
            const time_check_result_t time_res = onboard_sched_check_time(sys_time, p_entry->timestamp);
            if (MISSED == time_res)
            {
                // The scheduled time has already elapsed. Log missed schedule error
                onboard_sched_logging_start_log();
                onboard_sched_logging_add_slot_data(p_file_name, slot_offset);
                onboard_sched_logging_add_entry_data(p_entry->timestamp, p_entry->seq_id);
                onboard_sched_logging_end_log(ENTRY_MISSED_ERROR);

                ret = NEXT;
            }
            proceed = (RELEASE == time_res);
        }
        else
        {
            // Log CRC error
            onboard_sched_logging_start_log();
            onboard_sched_logging_add_slot_data(p_file_name, slot_offset);
            onboard_sched_logging_end_log(ENTRY_CRC_ERROR);
            // Entry is compromised, skip it and proceed with next one
            ret = NEXT;
        }

        if (false != proceed)
        {
            // Dispatch command to respective handler
            const sched_disp_ctx_t disp_ctx = { .p_sched_name = p_file_name, .p_entry = p_entry, .p_slot_buf = p_slot_buf, .slot_offset = slot_offset };

            onboard_sched_dispatch_cmd(&disp_ctx);

            // Move to next active slot
            ret = NEXT;
        }
    }
    else
    {
        if (SLOT_LOAD_ERROR == load_res)
        {
            // Log slot load error
            onboard_sched_logging_start_log();
            onboard_sched_logging_add_slot_data(p_file_name, slot_offset);
            onboard_sched_logging_end_log(ENTRY_SLOT_LOAD_ERROR);
        }

        // If the schedule storage is not yet ready do not abort schedule execution
        if (SLOT_LOAD_NOT_READY != load_res)
        {
            // Schedule file is either compromised or its end is reached. Abort further operations
            ret = ABORT;
        }
    }

    return ret;
}

static bool onboard_sched_execute_schedule(void)
{
    const unix_time_t   time_now  = datetime_to_unix_now();
    entry_exec_result_t entry_res = STAY;

    do
    {
        onboard_sched_nvm_data_t nvm_data;
        Nvm_GetBlockById(NVM_BLOCK_SCHEDULER_DATA, &nvm_data);
        entry_res = onboard_sched_execute_entry(nvm_data.last_schedule, &current_slot, nvm_data.active_slot_offset, time_now);
        if (NEXT == entry_res)
        {
            nvm_data.active_slot_offset = current_slot.service_data.header.next;
            Nvm_SetBlockById(NVM_BLOCK_SCHEDULER_DATA, &nvm_data, NVMSETBLOCK_STORE_IMMEDIATELY);
        }
    } while (NEXT == entry_res);

    return (ABORT != entry_res);
}

static slot_load_result_t onboard_sched_load_slot(const char *const p_file_name, sched_slot_buf_t *const p_slot, const uint32_t slot_offset)
{
    CRIT_ASSERT((NULL != p_file_name) && (NULL != p_slot));

    slot_load_result_t ret = SLOT_LOAD_ERROR;

    fm_file_obj_t h_file;
    fm_result_t   file_res = fm_open(&h_file, p_file_name, FM_MODE_READ);
    if (FM_RES_OK == file_res)
    {
        uint32_t bytes_read = 0;
        // Read the current entry from the schedule file
        file_res = fm_read_at_pos(&h_file, p_slot, sizeof(sched_slot_t), &bytes_read, slot_offset);
        if (FM_RES_OK == file_res)
        {
            if (bytes_read == sizeof(sched_slot_t))
            {
                // Read command and CRC
                const uint16_t cmd_size = ((const sched_slot_t *const)p_slot)->entry.cmd_size + sizeof(sched_entry_crc_t);
                file_res                = fm_read(&h_file, (uint8_t *const)p_slot + sizeof(sched_slot_t), cmd_size, &bytes_read);
                if ((FM_RES_OK == file_res) && (cmd_size == bytes_read))
                {
                    ret = SLOT_LOAD_OK;
                }
            }
            else if (bytes_read == 0)
            {
                // No more slots in the schedule file or partial or excessive read from file.
                // In any case, stop processing the file
                ret = SLOT_LOAD_EOF;
            }
            else
            {
                // Slot load error
            }
        }

        (void)fm_close(&h_file);
    }
    else
    {
        if (FM_RES_NOT_READY == file_res)
        {
            ret = SLOT_LOAD_NOT_READY;
        }
    }

    return ret;
}

static bool onboard_sched_check_crc(const sched_entry_t *const p_entry)
{
    CRIT_ASSERT(NULL != p_entry);

    bool                 ret       = false;
    const uint8_t *const p_calc    = (const uint8_t *const)p_entry;
    const uint32_t       calc_size = sizeof(sched_entry_t) + p_entry->cmd_size;
    const uint16_t       crc       = *(const uint16_t *const)(&p_calc[calc_size]);
    if (crc16_ccitt_table(p_calc, calc_size) == crc)
    {
        ret = true;
    }

    return ret;
}

static time_check_result_t onboard_sched_check_time(const unix_time_t sys_time, const unix_time_t entry_time)
{
    time_check_result_t ret = RELEASE;

    if (sys_time < entry_time)
    {
        // It is not yet time for the entry to be released
        ret = FUTURE;
    }
    else if (sys_time > entry_time)
    {
        // The time to release the entry has been missed
        ret = MISSED;
    }
    else
    {
        // The time has come to release the entry
    }

    return ret;
}

static void onboard_sched_dispatch_cmd(const sched_disp_ctx_t *const p_ctx)
{
    CRIT_ASSERT((NULL != p_ctx) && (NULL != p_ctx->p_sched_name) &&
                (NULL != p_ctx->p_entry) && (NULL != p_ctx->p_slot_buf));

    const char *const             p_file_name = p_ctx->p_sched_name;
    const sched_entry_t *const    p_entry     = p_ctx->p_entry;
    const sched_slot_buf_t *const p_slot_buf  = p_ctx->p_slot_buf;

    const bool is_script = ((p_entry->flags & SCHED_ENTRY_MASK_SCRIPT) != 0);

    onboard_sched_logging_start_log();
    onboard_sched_logging_add_slot_data(p_file_name, p_ctx->slot_offset);
    onboard_sched_logging_add_entry_data(p_entry->timestamp, p_entry->seq_id);

    if (false != is_script)
    {
#ifdef MICROPYTHON_SERVICE_ENABLED
        // Check if there is an already running script
        if (false == onboard_sched_scripting_get_runnning())
        {

            onboard_sched_scripting_execute_script(p_slot_buf->buf);
            onboard_sched_logging_end_log(SCRIPT_STARTED);
        }
        else
        {
            // Log script rejected
            onboard_sched_logging_add_script_data((const char *const)p_slot_buf->buf);
            onboard_sched_logging_end_log(SCRIPT_REJECTED);
        }
#else
        onboard_sched_logging_add_script_data((const char *const)p_slot_buf->buf);
        onboard_sched_logging_end_log(NO_SCRIPTING_ERROR);
#endif /* MICROPYTHON_SERVICE_ENABLED */
    }
    else
    {
#ifdef COMM_GW_ENABLED
        onboard_sched_commands_execute_command(p_slot_buf->buf, p_entry->cmd_size);
        onboard_sched_logging_end_log(CMD_RESULT);
#else
        // Log lack of command gateway
        onboard_sched_logging_end_log(NO_CMD_GW_ERROR);
#endif /* COMM_GW_ENABLED */
    }
}

static bool onboard_sched_check_file_extension(const char *const p_name,
                                               const char *const p_ext,
                                               const size_t      ext_len)
{
    bool res = false;

    const size_t name_len = strnlen(p_name, SCHED_MAX_NAME_LEN);
    if (ext_len < name_len)
    {
        res = (0 == strncmp(p_name + name_len - ext_len, p_ext, ext_len));
    }

    return res;
}
