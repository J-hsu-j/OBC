/*
 * Copyright (c) EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef SXBAND_SCHED_SM_CONFIG_USER_H
#define SXBAND_SCHED_SM_CONFIG_USER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "libhsm.h"

// USER_CODE_START::@main@
// Any code placed between these two tags will be preserved during code generation!

#include "cmsis_os2.h"
#include "sxband_cmd_iter_file.h"
#include "sxband_sched.h"
#include "timer.h"
#include "DataSink.h"

/**
 * @brief Shared contextual data between main OS task and SM implementation
 */
typedef struct
{
    osThreadId_t os_task_hnd;                                /**< OS task handle */
    sxband_cmd_file_iter_ctx_t file_iter_ctx;                /**< Commands file iterator context */
    sxband_cmd_iter_init_status_t file_iter_status;          /**< Status of the last iterator context initialization */
    sxband_sched_notif_t p_sched_notif;                      /**< Notification callback configured by the user when a file sequence is started */
    sxband_sched_cmd_t current_cmd_entry;                    /**< Information about the current command entry in execution */
    timer_handle_t cmd_timer;                                /**< Timer used to track the command timeout */
    sUserResponseCtx_t cmd_resp_ctx;                         /**< Response context for SXBand command execution */
    bool sxband_result_notified;							 /**< Indicates whether the SXBand driver callback for buffer completion has been called */
    bool last_cmd_finished;									 /**< Indicates whether the last command has already been executed */
    bool is_file_seq_in_progress;							 /**< Indicates whether a sequence is in progress */
    sxband_sched_status_t final_sched_status;				 /**< Indicates the final scheduler status to report to users when leaving the in_progress state */
    pl_ctrl_iter_status_t cmd_iter_status;					 /**< Contains the last command iteration status */
    uint32_t cmd_timeout_ms;                                 /**< command timeout in milliseconds as calculated by the SXBand driver */
} sxband_sched_rt_ctx_t;

extern sxband_sched_rt_ctx_t sxband_sched_rt_context;

/**
 * @brief Notification callback from SXBand driver to inform the SXBand scheduler that a
 *        command finished execution and response is ready
 *
 * @param[in] p_user_ctx user-provided context upon starting the command
 */
void sxband_sched_on_cmd_complete(void * const p_user_ctx);

// USER_CODE_END::@main@

// Entry/Exit functions
void sxband_sched_sm_on_entry_wait_file_tx(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void sxband_sched_sm_on_entry_file_tx_finished(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void sxband_sched_sm_on_exit_file_tx_in_progress(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void sxband_sched_sm_on_entry_prepare_cmd(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void sxband_sched_sm_on_entry_cmd_finished(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void sxband_sched_sm_on_entry_in_progress(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void sxband_sched_sm_on_exit_in_progress(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);

// Guard condition functions
bool sxband_sched_sm_guard_is_valid_context(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent);
bool sxband_sched_sm_guard_is_cmd_timeout_elapsed(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent);
bool sxband_sched_sm_guard_has_more_files(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent);
bool sxband_sched_sm_guard_more_cmd_to_process(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent);
bool sxband_sched_sm_guard_no_more_commands(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent);
bool sxband_sched_sm_guard_is_regular_cmd(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent);
bool sxband_sched_sm_guard_can_iterate_files_with_pattern(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent);
bool sxband_sched_sm_guard_empty_pattern(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent);
bool sxband_sched_sm_guard_has_more_commands(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent);
bool sxband_sched_sm_guard_general_failure(const uint16_t instance_id, const sState_t* const pSMRoot, const sHSM_EventType_t * const pEvent);

// Action handlers
void sxband_sched_sm_action_reset_cmd_iterator(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void sxband_sched_sm_action_update_cmd_status(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void sxband_sched_sm_action_update_cmd_status_timeout(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void sxband_sched_sm_action_send_next_file_cmd(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void sxband_sched_sm_action_load_next_cmd(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void sxband_sched_sm_action_deinit_sm_context(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void sxband_sched_sm_action_send_next_cmd(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void sxband_sched_sm_action_send_first_file_cmd(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void sxband_sched_sm_action_load_next_cmd_empty_pattern(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void sxband_sched_sm_action_deinit_sm_context_stop(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);
void sxband_sched_sm_action_deinit_sm_context_fail(const uint16_t instance_id, const sState_t * const pSMRoot, const sHSM_EventType_t * const pEvent);

#ifdef __cplusplus
};
#endif

#endif  // #ifndef SXBAND_SCHED_SM_CONFIG_USER_H