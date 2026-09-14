/*
 * Copyright (c) EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#include "libhsm.h"
#include "sxband_sched_sm_config_user.h"

// USER_CODE_START::@main@
#include <string.h>
#include "sxband_cmd_iter_file.h"
#include "sxband_sched_report.h"
#include "trace.h"
#include "S_X_Band_Trnsm.h"
#include "cmsis_os2.h"
#include "assertions.h"
#include "file_helper.h"

static inline void deinit_rt_context(void);
static void trigger_cmd_send(void);
static bool is_file_cmd(const cmd_list_command_t * const p_cmd_entry);
static void trace_cmd(const sxband_sched_cmd_t *p_cmd_data);

/**
 * @brief Command timeout in milliseconds
 */
#define CMD_TIMEOUT_MS                        (60000U)   /**< maximum timeout for a single command in milliseconds */
#define FILE_CMD_TIMEOUT_MIN_MS               (1000.)    /**< minimum timeout in milliseconds for file operations */
#define BIT_CNT_IN_1_BYTE                     (8U)       /**< number of bits in a single byte */
#define MS_IN_1_SEC                           (1000U)    /**< number of milliseconds in 1 second */
#define FILE_TX_TIMEOUT_EXTRA_PERCENTAGE      (4.)       /**< factor to multiply calculated file upload timeout value to (e.g. this number is based on actual rate of transfer including protocol overhead) */

INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/**
 * @brief The function performs command data tracing (used to assist in debugging the scheduler).
 *
 * @param[in] p_cmd_data a pointer to the command data
 */
static void trace_cmd(const sxband_sched_cmd_t *p_cmd_data)
{
    ES_TRACE_DEBUG("executing cmd %d (%c) [%d bytes]...", p_cmd_data->p_cmd_hdr->cmd, p_cmd_data->p_cmd_hdr->type, p_cmd_data->p_cmd_hdr->size);
}

/**
 * @brief Helper function to deinitialize the file-related fields of the runtime context
 *
 * Used when the "in progress" state is left for some reason which means that the command sequence was
 * terminated for some reason.
 */
static inline void deinit_rt_context(void)
{
    ES_TRACE_DEBUG("deinit_rt_context\r\n");

    // first close the report before deinitializing the memory runtime contexts
    sxband_sched_report_close();
    (void)fm_close(&sxband_sched_rt_context.file_iter_ctx.f_hnd);
    (void)memset(sxband_sched_rt_context.file_iter_ctx.cmd_file_name, 0U, sizeof(sxband_sched_rt_context.file_iter_ctx.cmd_file_name));
    sxband_sched_rt_context.file_iter_ctx.cmd_idx = 0U;
    sxband_sched_rt_context.file_iter_ctx.fs_last_res = FM_RES_OK;
    sxband_sched_rt_context.file_iter_ctx.find_iter_res = FM_RES_OK;
    (void)memset(&sxband_sched_rt_context.file_iter_ctx.cmd_list_hdr, 0U, sizeof(sxband_sched_rt_context.file_iter_ctx.cmd_list_hdr));
    (void)memset(&sxband_sched_rt_context.file_iter_ctx.iter_cmd_entry, 0U, sizeof(sxband_sched_rt_context.file_iter_ctx.iter_cmd_entry));
}

/**
 * @brief Triggers sending of a command which is already loaded in sxband_sched_rt_context.current_cmd_entry
 */
static void trigger_cmd_send(void)
{
    ES_TRACE_DEBUG("trigger_cmd_send\r\n");

    sxband_sched_rt_context.cmd_resp_ctx.onCmdResponseReady = &sxband_sched_on_cmd_complete;
    sxband_sched_rt_context.cmd_resp_ctx.pUserCtx = &sxband_sched_rt_context.cmd_resp_ctx;
    sxband_sched_rt_context.cmd_resp_ctx.is_all_data_in_buf = true;
    // no need to setup data buffers, we just need the onCmdResponseReady notification and
    // the full command output will be taken from the produced file by the SXBand driver
    sxband_sched_rt_context.cmd_resp_ctx.pu8DataBuf = NULL;
    sxband_sched_rt_context.cmd_resp_ctx.u32MaxDataSize = 0U;
    sxband_sched_rt_context.cmd_resp_ctx.u32ResponseSize = 0U;

    // remove the last stored file containing SXBand command output status
    (void)fm_delete(SX_BAND_FOUTPUT_NAME);

    sxband_sched_rt_context.sxband_result_notified = false;

    timer_start(&sxband_sched_rt_context.cmd_timer);

    S_X_BAND_TRNSM_ESTTC_StartCmd(sxband_sched_rt_context.file_iter_ctx.cmd_list_hdr.sxband_dev_id,
                                  sxband_sched_rt_context.current_cmd_entry.p_cmd_hdr->cmd,
                                  (uint8_t) sxband_sched_rt_context.current_cmd_entry.p_cmd_hdr->type,
                                  sxband_sched_rt_context.current_cmd_entry.p_cmd_hdr->size,
                                  (sxband_sched_rt_context.current_cmd_entry.p_cmd_hdr->size > 0U) ?
                                  (sxband_sched_rt_context.current_cmd_entry.p_data) : (NULL),
                                  &sxband_sched_rt_context.cmd_resp_ctx,
                                  &sxband_sched_rt_context.cmd_timeout_ms);

    trace_cmd(&sxband_sched_rt_context.current_cmd_entry);
}

/**
 * @brief Checks if the command entry is a file upload operation.
 *
 * @param[in] p_cmd_entry a pointer to the command entry data
 *
 * @return true - this is a file pattern, otherwise - false
 */
static inline bool is_file_cmd(const cmd_list_command_t * const p_cmd_entry)
{
    CRIT_ASSERT(NULL != p_cmd_entry);

    return S_X_BAND_TRNSM_GW_CMD_ID_UPLOAD_FILE == sxband_sched_rt_context.file_iter_ctx.iter_cmd_entry.hdr.cmd;
}

/** @brief Performs a zero-bound difference calculation of two numbers
 *  @param[in] minuend the number which you subtract from
 *  @param[in] subtrahend the number being subtracted
 *
 *  @return the difference between minuend and subtrahend or zero if the result would be negative
 */
static inline uint32_t dec_zb(const uint32_t minuend, const uint32_t subtrahend)
{
    return (minuend >= subtrahend) ? (minuend - subtrahend) : 0;
}

// USER_CODE_END::@main@

// Entry/Exit functions




// GEN_OBJ_START::sxband_sched_sm_on_entry_wait_file_tx
void sxband_sched_sm_on_entry_wait_file_tx(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::onEntry_wait_file_tx
    uint32_t fsize = (FM_RES_OK == sxband_sched_rt_context.file_iter_ctx.fs_last_res) ? sxband_sched_rt_context.file_iter_ctx.ffi.size : 0U;

    (void) fsize;

    ES_TRACE_DEBUG("SXBand sched> file size: %ld bytes => tx timeout set to %ld ms\r\n", fsize, sxband_sched_rt_context.cmd_timeout_ms);
    // USER_CODE_END::onEntry_wait_file_tx
}
// GEN_OBJ_END::sxband_sched_sm_on_entry_wait_file_tx


// GEN_OBJ_START::sxband_sched_sm_on_entry_file_tx_finished
void sxband_sched_sm_on_entry_file_tx_finished(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::onEntry_file_tx_finished
    sxband_sched_rt_context.last_cmd_finished = true;
    // USER_CODE_END::onEntry_file_tx_finished
}
// GEN_OBJ_END::sxband_sched_sm_on_entry_file_tx_finished


// GEN_OBJ_START::sxband_sched_sm_on_exit_file_tx_in_progress
void sxband_sched_sm_on_exit_file_tx_in_progress(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::onExit_file_tx_in_progress
    (void)fm_dir_close(&sxband_sched_rt_context.file_iter_ctx.dir_obj);
    // USER_CODE_END::onExit_file_tx_in_progress
}
// GEN_OBJ_END::sxband_sched_sm_on_exit_file_tx_in_progress


// GEN_OBJ_START::sxband_sched_sm_on_entry_prepare_cmd
void sxband_sched_sm_on_entry_prepare_cmd(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::onEntry_prepare_cmd

    sxband_sched_rt_context.cmd_timeout_ms = 0U;

    // USER_CODE_END::onEntry_prepare_cmd
}
// GEN_OBJ_END::sxband_sched_sm_on_entry_prepare_cmd



// GEN_OBJ_START::sxband_sched_sm_on_entry_cmd_finished
void sxband_sched_sm_on_entry_cmd_finished(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::onEntry_cmd_finished
    sxband_sched_rt_context.last_cmd_finished = true;
    // USER_CODE_END::onEntry_cmd_finished
}
// GEN_OBJ_END::sxband_sched_sm_on_entry_cmd_finished


// GEN_OBJ_START::sxband_sched_sm_on_entry_in_progress
void sxband_sched_sm_on_entry_in_progress(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::onEntry_in_progress
    sxband_sched_rt_context.is_file_seq_in_progress = true;
    // USER_CODE_END::onEntry_in_progress
}
// GEN_OBJ_END::sxband_sched_sm_on_entry_in_progress

// GEN_OBJ_START::sxband_sched_sm_on_exit_in_progress
void sxband_sched_sm_on_exit_in_progress(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::onExit_in_progress
    sxband_sched_rt_context.is_file_seq_in_progress = false;
    // USER_CODE_END::onExit_in_progress
}
// GEN_OBJ_END::sxband_sched_sm_on_exit_in_progress



// Guard condition functions
// GEN_OBJ_START::sxband_sched_sm_guard_is_valid_context
bool sxband_sched_sm_guard_is_valid_context(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_is_valid_context
    return (SXB_INIT_STATUS_OK == sxband_sched_rt_context.file_iter_status);

    // USER_CODE_END::guard_is_valid_context
}
// GEN_OBJ_END::sxband_sched_sm_guard_is_valid_context

// GEN_OBJ_START::sxband_sched_sm_guard_is_cmd_timeout_elapsed
bool sxband_sched_sm_guard_is_cmd_timeout_elapsed(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_is_cmd_timeout_elapsed
    return timer_is_elapsed(&sxband_sched_rt_context.cmd_timer, sxband_sched_rt_context.cmd_timeout_ms);
    // USER_CODE_END::guard_is_cmd_timeout_elapsed
}
// GEN_OBJ_END::sxband_sched_sm_guard_is_cmd_timeout_elapsed

// GEN_OBJ_START::sxband_sched_sm_guard_has_more_files
bool sxband_sched_sm_guard_has_more_files(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_has_more_files
    // move iterator to next file in the list (if any)...
    do
    {
        sxband_sched_rt_context.file_iter_ctx.find_iter_res = \
                fm_dir_next(&sxband_sched_rt_context.file_iter_ctx.dir_obj,
                                &sxband_sched_rt_context.file_iter_ctx.ffi);
    // skip invalid file names
    } while (FM_RES_INVALID_NAME == sxband_sched_rt_context.file_iter_ctx.find_iter_res);

    sxband_sched_rt_context.file_iter_ctx.has_more_files = \
        ((FM_RES_OK == sxband_sched_rt_context.file_iter_ctx.find_iter_res) &&
        ('\0' != sxband_sched_rt_context.file_iter_ctx.ffi.full_path[0]));

    ES_TRACE_DEBUG("has_more_files: %d (iter_status: %d, fname: '%s')\r\n", sxband_sched_rt_context.file_iter_ctx.has_more_files, sxband_sched_rt_context.file_iter_ctx.find_iter_res, sxband_sched_rt_context.file_iter_ctx.ffi.full_path);

    return sxband_sched_rt_context.file_iter_ctx.has_more_files;
    // USER_CODE_END::guard_has_more_files
}
// GEN_OBJ_END::sxband_sched_sm_guard_has_more_files

// GEN_OBJ_START::sxband_sched_sm_guard_more_cmd_to_process
bool sxband_sched_sm_guard_more_cmd_to_process(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_more_cmd_to_process
    return ((!sxband_sched_rt_context.file_iter_ctx.has_more_files) &&
            (true == sxband_sched_sm_guard_has_more_commands(instance_id, pSMRoot, pEvent)));
    // USER_CODE_END::guard_more_cmd_to_process
}
// GEN_OBJ_END::sxband_sched_sm_guard_more_cmd_to_process

// GEN_OBJ_START::sxband_sched_sm_guard_no_more_commands
bool sxband_sched_sm_guard_no_more_commands(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_no_more_commands
    return (true == sxband_sched_rt_context.last_cmd_finished) &&
           (false == sxband_sched_sm_guard_has_more_commands(instance_id, pSMRoot, pEvent));
    // USER_CODE_END::guard_no_more_commands
}
// GEN_OBJ_END::sxband_sched_sm_guard_no_more_commands

// GEN_OBJ_START::sxband_sched_sm_guard_is_regular_cmd
bool sxband_sched_sm_guard_is_regular_cmd(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_is_regular_cmd
    return !is_file_cmd(&sxband_sched_rt_context.file_iter_ctx.iter_cmd_entry);
    // USER_CODE_END::guard_is_regular_cmd
}
// GEN_OBJ_END::sxband_sched_sm_guard_is_regular_cmd

// GEN_OBJ_START::sxband_sched_sm_guard_can_iterate_files_with_pattern
bool sxband_sched_sm_guard_can_iterate_files_with_pattern(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_can_iterate_files_with_pattern
    sxband_sched_rt_context.file_iter_ctx.has_more_files = false;

    if (true == is_file_cmd(&sxband_sched_rt_context.file_iter_ctx.iter_cmd_entry))
    {
        size_t pattern_copy_sz = 0;

        if (sizeof(sxband_sched_rt_context.file_iter_ctx.file_pattern) >= sxband_sched_rt_context.file_iter_ctx.iter_cmd_entry.hdr.size)
        {
            pattern_copy_sz = sxband_sched_rt_context.file_iter_ctx.iter_cmd_entry.hdr.size;
        }
        else
        {
            pattern_copy_sz = sizeof(sxband_sched_rt_context.file_iter_ctx.file_pattern);
        }

        // make a temporary copy of the file iterator pattern and path from the data field because the data buffer will be
        // used to store the file names during iteration and the FATFS iterator only keeps a pointer to the pattern
        file_helper_parse_path((char *) sxband_sched_rt_context.file_iter_ctx.iter_cmd_entry.data,
                               pattern_copy_sz,
                               sxband_sched_rt_context.file_iter_ctx.file_path,
                               sizeof(sxband_sched_rt_context.file_iter_ctx.file_path),
                               sxband_sched_rt_context.file_iter_ctx.file_pattern,
                               sizeof(sxband_sched_rt_context.file_iter_ctx.file_pattern));

        CRIT_ASSERT(pattern_copy_sz >= 1);

        fm_result_t res;
        res = fm_dir_open(&sxband_sched_rt_context.file_iter_ctx.dir_obj,
                    sxband_sched_rt_context.file_iter_ctx.file_path,
                    sxband_sched_rt_context.file_iter_ctx.file_pattern);
        if (FM_RES_OK == res)
        {
            do
            {
                res = fm_dir_next(&sxband_sched_rt_context.file_iter_ctx.dir_obj,
                                &sxband_sched_rt_context.file_iter_ctx.ffi);
            // skip invalid file names
            } while (FM_RES_INVALID_NAME == res);

            if (FM_RES_OK != res)
            {
                (void)fm_dir_close(&sxband_sched_rt_context.file_iter_ctx.dir_obj);
            }
        }
        sxband_sched_rt_context.file_iter_ctx.find_iter_res = res;

        // check if the pattern iterator initialization points to a real file
        sxband_sched_rt_context.file_iter_ctx.has_more_files = \
                (FM_RES_OK == sxband_sched_rt_context.file_iter_ctx.find_iter_res) &&
                ('\0' != sxband_sched_rt_context.file_iter_ctx.ffi.full_path[0]);
    }

    return sxband_sched_rt_context.file_iter_ctx.has_more_files;

    // USER_CODE_END::guard_can_iterate_files_with_pattern
}
// GEN_OBJ_END::sxband_sched_sm_guard_can_iterate_files_with_pattern

// GEN_OBJ_START::sxband_sched_sm_guard_empty_pattern
bool sxband_sched_sm_guard_empty_pattern(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_empty_pattern
    // in case of an empty file pattern, no more files will be available for iteration...
    return !sxband_sched_rt_context.file_iter_ctx.has_more_files;
    // USER_CODE_END::guard_empty_pattern
}
// GEN_OBJ_END::sxband_sched_sm_guard_empty_pattern

// GEN_OBJ_START::sxband_sched_sm_guard_has_more_commands
bool sxband_sched_sm_guard_has_more_commands(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_has_more_commands
    return sxband_cmd_iter_file.p_has_next(&sxband_sched_rt_context.file_iter_ctx);
    // USER_CODE_END::guard_has_more_commands
}
// GEN_OBJ_END::sxband_sched_sm_guard_has_more_commands

// GEN_OBJ_START::sxband_sched_sm_guard_general_failure
bool sxband_sched_sm_guard_general_failure(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::guard_general_failure
    bool general_error = (PL_CTRL_ITER_STATUS_NOK == sxband_sched_rt_context.cmd_iter_status);

    sxband_sched_rt_context.final_sched_status = (true == general_error) ? SXBAND_SCHED_STATUS_FAILED : SXBAND_SCHED_STATUS_OK;

    return general_error;
    // USER_CODE_END::guard_general_failure
}
// GEN_OBJ_END::sxband_sched_sm_guard_general_failure


// Action handlers
// GEN_OBJ_START::sxband_sched_sm_action_reset_cmd_iterator
void sxband_sched_sm_action_reset_cmd_iterator(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::action_reset_cmd_iterator
    sxband_sched_rt_context.cmd_iter_status = sxband_cmd_iter_file.p_reset(&sxband_sched_rt_context.file_iter_ctx);

    // load first command entry from the iterator
    sxband_sched_rt_context.cmd_iter_status = sxband_cmd_iter_file.p_next(&sxband_sched_rt_context.file_iter_ctx, &sxband_sched_rt_context.current_cmd_entry);

    if (true == sxband_sched_rt_context.file_iter_ctx.cmd_list_hdr.store_file_summary)
    {
        sxband_sched_report_open(sxband_sched_rt_context.file_iter_ctx.cmd_list_hdr.summary_fname);
    }

    sxband_sched_rt_context.last_cmd_finished = false;
    // USER_CODE_END::action_reset_cmd_iterator
}
// GEN_OBJ_END::sxband_sched_sm_action_reset_cmd_iterator

// GEN_OBJ_START::sxband_sched_sm_action_update_cmd_status
void sxband_sched_sm_action_update_cmd_status(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::action_update_cmd_status
    if (true == sxband_sched_rt_context.file_iter_ctx.cmd_list_hdr.store_file_summary)
    {
        sxband_sched_report_append(&sxband_sched_rt_context.current_cmd_entry, SXBAND_SCHED_CMD_STATUS_DEFAULT);
    }
    // USER_CODE_END::action_update_cmd_status
}
// GEN_OBJ_END::sxband_sched_sm_action_update_cmd_status

// GEN_OBJ_START::sxband_sched_sm_action_update_cmd_status_timeout
void sxband_sched_sm_action_update_cmd_status_timeout(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::action_update_cmd_status_timeout
    if (true == sxband_sched_rt_context.file_iter_ctx.cmd_list_hdr.store_file_summary)
    {
        sxband_sched_report_append(&sxband_sched_rt_context.current_cmd_entry, SXBAND_SCHED_CMD_STATUS_TIMEDOUT);
    }
    // USER_CODE_END::action_update_cmd_status_timeout
}
// GEN_OBJ_END::sxband_sched_sm_action_update_cmd_status_timeout

// GEN_OBJ_START::sxband_sched_sm_action_send_next_file_cmd
void sxband_sched_sm_action_send_next_file_cmd(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::action_send_next_file_cmd
    // strlen() is safe here, because .ffi.full_path is always null-terminated by the fm_dir_next() function
    uint8_t base_folder_sz = (uint8_t) strlen(sxband_sched_rt_context.file_iter_ctx.file_path);
    uint8_t file_name_sz = (uint8_t) strlen(sxband_sched_rt_context.file_iter_ctx.ffi.full_path);
    size_t cmd_buf_size = sizeof(((cmd_list_command_t *) NULL)->data);
    size_t full_path_size = file_name_sz + 1;    // +1 -> NULLZ

    if (full_path_size <= cmd_buf_size)
    {
        if (base_folder_sz > 0)
        {
            full_path_size += base_folder_sz + 1;    // +1 -> add '/' path delimiter if we have a file inside a folder
            (void) memcpy(sxband_sched_rt_context.current_cmd_entry.p_data,
                          sxband_sched_rt_context.file_iter_ctx.file_path,
                          base_folder_sz);

            // add path delimiter between the base folder and the file name or pattern
            sxband_sched_rt_context.current_cmd_entry.p_data[base_folder_sz] = '/';
            ++base_folder_sz;    // account for the added delimiter in next operations which use this size below
        }

        sxband_sched_rt_context.current_cmd_entry.p_cmd_hdr->size = (uint8_t) full_path_size;

        (void) memcpy(sxband_sched_rt_context.current_cmd_entry.p_data + base_folder_sz,
                      sxband_sched_rt_context.file_iter_ctx.ffi.full_path,
                      file_name_sz);

        sxband_sched_rt_context.current_cmd_entry.p_data[dec_zb(sxband_sched_rt_context.current_cmd_entry.p_cmd_hdr->size, 1)] = '\0';

        ES_TRACE_DEBUG("send_next_file: sz = %d, fname = %s\r\n", sxband_sched_rt_context.current_cmd_entry.p_cmd_hdr->size, sxband_sched_rt_context.file_iter_ctx.ffi.full_path);
        sxband_sched_rt_context.last_cmd_finished = false;

        ES_TRACE_DEBUG(">>>> last file tx: %ld ms\r\n", timer_get_elapsed_time(&sxband_sched_rt_context.cmd_timer));

        trigger_cmd_send();
    }
    else
    {
        // no space for the full path but truncating the path would anyway lead to errors so we just keep it empty
        // so to jump to the next file in the list which may possibly fit
        sxband_sched_rt_context.current_cmd_entry.p_cmd_hdr->size = 0;

        // stop timeout timer which will trigger a jump to the next file in the list
        timer_stop(&sxband_sched_rt_context.cmd_timer);

        ES_TRACE_WARN("[file name too long] send_next_file: sz = %d, skipping fname = %s\r\n", sxband_sched_rt_context.current_cmd_entry.p_cmd_hdr->size, sxband_sched_rt_context.file_iter_ctx.ffi.full_path);

    }
    // USER_CODE_END::action_send_next_file_cmd
}
// GEN_OBJ_END::sxband_sched_sm_action_send_next_file_cmd

// GEN_OBJ_START::sxband_sched_sm_action_load_next_cmd
void sxband_sched_sm_action_load_next_cmd(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::action_load_next_cmd
    sxband_sched_rt_context.cmd_iter_status = sxband_cmd_iter_file.p_next(&sxband_sched_rt_context.file_iter_ctx, &sxband_sched_rt_context.current_cmd_entry);

    if (PL_CTRL_ITER_STATUS_OK == sxband_sched_rt_context.cmd_iter_status)
    {
        sxband_sched_rt_context.last_cmd_finished = false;
    }
    else
    {
        sxband_sched_rt_context.last_cmd_finished = true;
    }
    // USER_CODE_END::action_load_next_cmd
}
// GEN_OBJ_END::sxband_sched_sm_action_load_next_cmd

// GEN_OBJ_START::sxband_sched_sm_action_deinit_sm_context
void sxband_sched_sm_action_deinit_sm_context(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::action_deinit_sm_context
    // notify user that the command sequence is over
    if (NULL != sxband_sched_rt_context.p_sched_notif)
    {
        (*sxband_sched_rt_context.p_sched_notif)(
                        sxband_sched_rt_context.final_sched_status,
                        sxband_sched_rt_context.file_iter_ctx.cmd_list_hdr.summary_fname);
    }

    // deinitialize the context after the notification because the summary_fname property
    // will be cleared before notifying the user
    deinit_rt_context();

    // USER_CODE_END::action_deinit_sm_context
}
// GEN_OBJ_END::sxband_sched_sm_action_deinit_sm_context

// GEN_OBJ_START::sxband_sched_sm_action_send_next_cmd
void sxband_sched_sm_action_send_next_cmd(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::action_send_next_cmd
    trigger_cmd_send();
    // USER_CODE_END::action_send_next_cmd
}
// GEN_OBJ_END::sxband_sched_sm_action_send_next_cmd

// GEN_OBJ_START::sxband_sched_sm_action_send_first_file_cmd
void sxband_sched_sm_action_send_first_file_cmd(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::action_send_first_file_cmd
    // strlen is safe here, because .ffi.full_path is always null-terminated by the fm_dir_next() function
    sxband_sched_rt_context.current_cmd_entry.p_cmd_hdr->size = (uint8_t) strlen(sxband_sched_rt_context.file_iter_ctx.ffi.full_path) + 1U;
    (void) memcpy(sxband_sched_rt_context.current_cmd_entry.p_data,
                  sxband_sched_rt_context.file_iter_ctx.ffi.full_path,
                  sxband_sched_rt_context.current_cmd_entry.p_cmd_hdr->size);

    ES_TRACE_DEBUG("send_first_file: sz = %d, fname = %s\r\n", sxband_sched_rt_context.current_cmd_entry.p_cmd_hdr->size, sxband_sched_rt_context.file_iter_ctx.ffi.full_path);

    trigger_cmd_send();
    // USER_CODE_END::action_send_first_file_cmd
}
// GEN_OBJ_END::sxband_sched_sm_action_send_first_file_cmd

// GEN_OBJ_START::sxband_sched_sm_action_load_next_cmd_empty_pattern
void sxband_sched_sm_action_load_next_cmd_empty_pattern(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::action_load_next_cmd_empty_pattern
    // explicitly report command status as "NO_FILES" because it didn't match any files on the storage
    sxband_sched_report_append(&sxband_sched_rt_context.current_cmd_entry, SXBAND_SCHED_CMD_STATUS_NO_FILES);

    // ensure the directory handle is closed for the next attempt
    (void)fm_dir_close(&sxband_sched_rt_context.file_iter_ctx.dir_obj);

    sxband_sched_sm_action_load_next_cmd(instance_id, pSMRoot, pEvent);
    // USER_CODE_END::action_load_next_cmd_empty_pattern
}
// GEN_OBJ_END::sxband_sched_sm_action_load_next_cmd_empty_pattern

// GEN_OBJ_START::sxband_sched_sm_action_deinit_sm_context_stop
void sxband_sched_sm_action_deinit_sm_context_stop(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::action_deinit_sm_context_stop
    const char * const p_failure_msg = "Command execution interrupted by user!\r\n";
    sxband_sched_report_append_free_text(p_failure_msg, strlen(p_failure_msg));

    sxband_sched_sm_action_deinit_sm_context(instance_id, pSMRoot, pEvent);
    // USER_CODE_END::action_deinit_sm_context_stop
}
// GEN_OBJ_END::sxband_sched_sm_action_deinit_sm_context_stop

// GEN_OBJ_START::sxband_sched_sm_action_deinit_sm_context_fail
void sxband_sched_sm_action_deinit_sm_context_fail(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent)
{
    (void) instance_id;
    (void) pSMRoot;
    (void) pEvent;

    // USER_CODE_START::action_deinit_sm_context_fail
    const char * const p_failure_msg = "Execution stopped. Command iterator failure!\r\n";
    sxband_sched_report_append_free_text(p_failure_msg, strlen(p_failure_msg));

    sxband_sched_sm_action_deinit_sm_context(instance_id, pSMRoot, pEvent);
    // USER_CODE_END::action_deinit_sm_context_fail
}
// GEN_OBJ_END::sxband_sched_sm_action_deinit_sm_context_fail
