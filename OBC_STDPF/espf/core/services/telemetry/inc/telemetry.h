/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef __TELEMETRY_H__
#define __TELEMETRY_H__

/**
 * @addtogroup Services
 * @{
 *
 * @defgroup service_tlm Telemetry
 * @{
 *
 * The telemetry service takes responsibility of:
 *     - periodic collection of data directly from the DataCache;
 *     - assembly of telemetry frames and forwarding to a data sink adapter
 *       (e.g. sending over to a serial connection or storage to a file, etc.);
 *
 * The service is implemented as two state machines. The first one (described in `telemetry_sm.yaml`),
 * is responsible for gathering the telemetry from datacache and the second one (described in
 * `telemetry_file_sink_sm.yaml`), is responsible for writing the telemetry to the files.
 *
 * The link between the two state machines is the telemetry queue. The telemetry state machine is
 * placing the collected data into the queue and the file sink state machine is reading the data from it.
 * The telemetry state machine is checking that the queue has enough space to place the data in the file
 * and it will trigger the file sink state machine to start writing the data to the file whenever the low space
 * threshold is reached (@see TELEMETRY_QUEUE_LOW_SPACE_THRESHOLD).
 *
 * @file telemetry.h
 *
 * @brief Telemetry service public interface
 *
 * @}
 * @}
 *
 */

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

#include "es_cdef.h"
#include "telemetry_context_types.h"

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
/** @brief Initializes the telemetry service and prepares it for operation.
 *
 *  The method is responsible to initialize all telemetry instances and their corresponding
 *  contexts as well as to create their respective RTOS tasks and schedule them for operation.
 * */
void telemetry_init(void);

/** @brief Starts telemetry collection until next reboot or a call to @ref telemetry_stop
 *
 *  @param[in/out] p_tlm_rt_ctx telemetry instance context
 *  @param[in] hold_period_s period in seconds after which the telemetry gets stopped automatically
 *  (if set to 0, an explicit call to @ref telemetry_stop function is needed to stop the telemetry
 * */
void telemetry_start(tlm_runtime_context_t *const p_tlm_rt_ctx, const uint16_t hold_period_s);

/** @brief Stops telemetry collection until next reboot or a call to @ref telemetry_start
 *
 *  @param[in/out] p_tlm_rt_ctx telemetry instance context
 *  @param[in] hold_period_s period in seconds after which the telemetry gets started automatically
 *  (if set to 0, an explicit call to @ref telemetry_start function is needed to start the telemetry
 * */
void telemetry_stop(tlm_runtime_context_t *const p_tlm_rt_ctx, const uint16_t hold_period_s);

/** @brief Check if the telemetry collection and storage are started
 *
 *  @param[in] p_tlm_rt_ctx telemetry instance context
 *
 *  @retval true: telemetry is fully operational
 *  @retval false: telemetry may not be fully operational (e.g. collection in memory is active but
 *  storage is not)
 */
bool telemetry_is_started(tlm_runtime_context_t *const p_tlm_rt_ctx);

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus
#endif // #ifndef __TELEMETRY_H__
