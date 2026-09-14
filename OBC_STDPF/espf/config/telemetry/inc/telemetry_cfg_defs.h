/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef TELEMETRY_CFG_DEFS_H
#define TELEMETRY_CFG_DEFS_H

/**
 * @addtogroup service_tlm
 * @{
 *
 * @file telemetry_cfg_defs.h
 * @brief Telemetry service configuration defines
 *
 * @}
 */

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

#include "fm_def.h"

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
/** Telemetry frame delimiter value (for COBS encoding we use 0) */
#define TLM_FRM_DELIMITER (0U)

/** 3-letter file extension used for telemetry files */
#define TLM_FILE_SINK_EXT "tlm"

/** telemetry files clean-up search mask (combined with @ref TLM_FILE_SINK_EXT, e.g. "*.tlm" */
#define TLM_FILE_NAME_MASK "*."

/** maximum size of the telemetry file name (including folder name) */
#define TLM_FILE_SINK_MAX_FN_SIZE (FM_MAX_PATH)

/** maximum size of the telemetry folder name on the SD card, e.g. tlm_0 */
#define TLM_DIR_MAX_NAME_SIZE (12)

/** size of the internal telemetry buffer used to frame messages before forwarding them to the data sink interface */
#define TLM_BUF_SIZE (400)

/** 10% over the TLM_BUF_SIZE used for COBS encoding */
#define TLM_ENCODE_BUF_SIZE (TLM_BUF_SIZE + (TLM_BUF_SIZE / 10U))

/** number of bytes reserved for the Telemetry queue used to buffer messages before they get stored to SD card */
#define TLM_QUEUE_SIZE (5 * TLM_ENCODE_BUF_SIZE)

/** number of free bytes in the telemetry queue, after which, a write to the output sink is initiated
 * (e.g. dump the data to the SD card)
 */
#define TELEMETRY_QUEUE_LOW_SPACE_THRESHOLD ((TLM_QUEUE_SIZE / 5U)) // 20%

/** period of the telemetry service task in milliseconds */
#define TLM_FILE_SINK_TASK_PERIOD_MS (1500U)

/** number of milliseconds to pause telemetry file sink operation when a TL frame is received on ESPS I bus
(e.g. during ground station communication) */
#define TLM_FILE_SINK_PAUSE_ON_TL_FRAME_MS (3000U)

/** NVM configuration reload time in milliseconds taken into account only in Stopped mode to detect possible reactivation of the telemetry service */
#define TLM_RELOAD_CFG_TIME_MS (1000U)

/** Maximum time to wait for the telemetry mutex acqusition */
#define MAX_MUTEX_WAIT_TIMEOUT_MS (5000U)

/** Minimum ACQ period safeguard protection. Prevent any period lower than MIN_ACQ_PERIOD_MS to enter the NVM configuration.  */
#define MIN_ACQ_PERIOD_MS (100U)

/** Maximum number of allowed telemetry files on the SD card */
#define MAX_TLM_FILES_COUNT (1000U)

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
#endif // #ifdef __cplusplus

#endif // #ifndef TELEMETRY_CFG_DEFS_H
