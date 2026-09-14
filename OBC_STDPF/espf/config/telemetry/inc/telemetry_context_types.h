/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup service_tlm
 * @{
 *
 * @file telemetry_context_types.h
 * @brief Telemetry service runtime context types header
 *
 * @}
 */

#ifndef TELEMETRY_CONTEXT_TYPES_H
#define TELEMETRY_CONTEXT_TYPES_H

#include "es_cdef.h"
#include <stdatomic.h>
#include "nvm.h"
#include "timer.h"
#include "telemetry_cfg_defs.h"
#include "cmsis_os2.h"
#include "FP_telemetryProtocolTypes.h"

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

/** Flag to indicate that the tlm queue is ready to store the data */
#define TLM_FILE_SINK_STORE_FLAG (0x01)

/** @brief Operation types which require synchronization with the main file sink task.
 *         The enumeration values serve as indices in tlm_file_sink_rt_ctx_t::main_task_sync_op_flags array.
 */
typedef enum
{
    TLM_FILE_SINK_OP_CFG_UPDATE = 0,
    TLM_FILE_SINK_OP_CLEAN      = 1,
    TLM_FILE_SINK_OP_MAX        = 2
} tlm_file_sink_op_t;

/** @brief Queue runtime context data */
typedef struct
{
    uint32_t msg_pushed_cnt;          /**< number of pushed messages since system boot */
    uint32_t msg_popped_cnt;          /**< number of popped messages since system boot */
    uint32_t free_bytes_min;          /**< minimum value reached for the free space in the queue */
    uint32_t discarded_messages_cnt;  /**< number of discarded messages due to lack of space in the queue */
    uint32_t max_number_of_batch_msg; /**< maximum number of messages processed in a batch on a single run */
    uint32_t active_slot_id;          /**< identifier of the active slot where telemetry is currently stored */
} tlm_queue_stats_t;

typedef enum
{
    TLM_STATS_ID_BATCH_COUNT, /**< Used to report the number of telemetry frames transmitted in a single batch */
    TLM_STATS_ID_ACTIVE_SLOT, /**< Used to report the ID of the currently active file slot in which telemetry gets stored on the SD card */
    TLM_STATS_MAX             /**< Used to perform range-checking on the values of this enumeration type */
} tlm_queue_stats_id_t;

typedef struct
{
    uint16_t          head_idx;             /**< index of the queue head, where next message will be read from */
    uint16_t          tail_idx;             /**< index of the queue tail, where next message will be written to */
    uint16_t          free_bytes;           /**< number of free bytes remaining in the queue */
    uint8_t           qbuf[TLM_QUEUE_SIZE]; /**< queue internal data buffer */
    tlm_queue_stats_t stats;                /**< queue run-time statistics */
    osMutexId_t       tlm_queue_lock_id;    /**< queue lock mutex used to sync access from different contexts */
} tlm_queue_rt_t;

/**
 * @brief File sink runtime data
 */
typedef struct
{
    const TELEMETRY_TelemetryInstance_t sm_instance_id;                                                        /**< ID of the corresponding SM instance */
    const uint8_t                       task_mon_id;                                                           /**< TaskMonitor task ID */
    osThreadId_t                        os_task_hnd;                                                           /**< OS task handle */
    osMutexId_t                         telemetry_file_lock_id;                                                /**< SM access lock for the telemetry instnace */
    telemetry_file_cfg_t                cfg;                                                                   /**< NVM configuration of the file sink */
    telemetry_file_cfg_t                prev_cfg;                                                              /**< last used NVM configuration of the file sink */
    uint32_t                            max_file_size_bytes;                                                   /**< max individual telemetry file size in bytes */
    char                                current_folder_name[TLM_DIR_MAX_NAME_SIZE];                            /**< folder name used to store telemetry files for the specified instance */
    char                                current_file_name[TLM_FILE_SINK_MAX_FN_SIZE];                          /**< current file name in use for next write */
    char                                wildcard[sizeof(TLM_FILE_NAME_MASK) + sizeof(TLM_FILE_SINK_EXT) - 1U]; /**< contains the telemetry files wildcard used to enumerate the files plus space for 1 NULLZ character */
    uint8_t                             tlm_msg_buffer[TLM_BUF_SIZE];                                          /**< runtime telemetry message buffer used to pop messages from queue temporarily */
    atomic_bool                         main_task_sync_op_flags[TLM_FILE_SINK_OP_MAX];                         /**< flags used to synchronize external operations to main task */
    telemetry_persistent_data_t         persistent_data;                                                       /**< auxiliary persistent telemetry data loaded from NVM */
} tlm_file_sink_rt_ctx_t;

/** @typedef runtime_context_t
 *  @brief Runtime context information for the telemetry service
 *
 */
typedef struct
{
    const TELEMETRY_TelemetryInstance_t sm_instance_id;                                      /**< ID of the corresponding SM instance */
    const uint8_t                       task_mon_id;                                         /**< TaskMonitor task ID */
    osThreadId_t                        os_task_hnd;                                         /**< OS task handle */
    osMutexId_t                         telemetry_lock_id;                                   /**< SM access lock for the telemetry instnace */
    uint32_t                            os_task_period_ms;                                   /**< OS task period in milliseconds */
    timer_handle_t                      reload_config_timer;                                 /**< timer used to trigger reloading of NVM config while in stop mode */
    telemetry_cfg_t                     gen_cfg;                                             /**< telemetry configuration loaded from NVM */
    telemetry_preset_cfg_t              preset_cfg;                                          /**< telemetry preset configuration loaded from NVM */
    uint8_t                             active_preset_id;                                    /**< currently used preset id for the telemetry configuration */
    uint8_t                             prev_preset_id;                                      /**< previously used preset id for the telemetry configuration (used to detect preset change) */
    uint8_t                             tlm_msg_buffer[TLM_BUF_SIZE];                        /**< runtime telemetry message buffer used to frame messages before forwarding them to the data sink */
    uint8_t                             tlm_msg_encode_buffer[TLM_ENCODE_BUF_SIZE];          /**< runtime telemetry message buffer used to encode frames before pushing them to the data queue */
    uint8_t                             rolling_cntr;                                        /**< telemetry frames rolling counter */
    timer_handle_t                      tlm_entry_timer[TELEMETRY_MAX_CONFIGURABLE_ENTRIES]; /**< timer to trigger the data acquisition */
    tlm_file_sink_rt_ctx_t              tlm_file_sink_rt;                                    /**< telemetry file sink runtime context */
    tlm_queue_rt_t                      tlm_queue;                                           /**< telemetry queue context */
    timer_handle_t                      hold_timer;                                          /**< timer used to wait for the specified time to keep the telemetry started/stopped */
    uint16_t                            hold_period_s;                                       /**< telemetry start/stop hold period in seconds (0 - means indefinite) */
    uint16_t                            next_start_slot_idx;                                 /**< holds the slot index of the preset to use for the next collection round  */
} tlm_runtime_context_t;

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif /* TELEMETRY_CONTEXT_TYPES_H */
