/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef TELEMETRY_QUEUE_H
#define TELEMETRY_QUEUE_H

/**
 * @addtogroup service_tlm
 * @{
 *
 * @file telemetry_queue.h
 *
 * @brief This is a basic telemetry buffers queue implementation
 *
 * The module provides functions to initialize the queue and push/pop telemetry
 * buffers to/from it. The queue is statically defined and its size can be
 * changed only at build time.
 * @note The queue is specifically designed for use by the telemetry
 * service implementation and is not meant to be shared with other components in
 * the system.
 *
 * @}
 */

#include "telemetry_context_types.h"
#include "es_cdef.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

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
/** @brief Prepares the telemetry queue for usage
 *
 *  @param[in/out] p_queue_inst pointer to the queue instance data
 * */
void telemetry_queue_init(tlm_queue_rt_t *const p_queue_inst);

/** @brief Pushes a new frame onto the queue
 *
 *  @param[in/out] p_queue_inst pointer to the queue instance data
 *  @param[in] p_data a pointer to the user data
 *  @param[in] data_size size of the data pointed to by p_data
 *
 *  @return true: frame successfully pushed to the queue;
 *  		false: could not add frame to queue due to lack of space
 */
bool telemetry_queue_push(tlm_queue_rt_t *const p_queue_inst, const uint8_t *const p_data, const uint16_t data_size);

/** @brief Pops a frame from the queue
 *
 *  @param[in/out] p_queue_inst pointer to the queue instance data
 *  @param[out] p_data_buf a pointer to a user buffer to receive the frame from the queue
 *  @param[in] buf_size size of the buffer pointed to by p_data_buf
 *
 *  @return number of bytes written to p_data_buf; 0 - if no frames are available in the queue
 */
uint16_t telemetry_queue_pop(tlm_queue_rt_t *const p_queue_inst, uint8_t *const p_data_buf, const uint16_t buf_size);

/** @brief Provides the length of the next message in the queue without affecting the queue state.
 *
 *  @param[in/out] p_queue_inst pointer to the queue instance data
 *
 *  @return size in bytes of the next message that @ref telemetry_queue_pop will fetch if called
 */
uint16_t telemetry_queue_peek(tlm_queue_rt_t *const p_queue_inst);

/** @brief Provides telemetry queue run-time statistics
 *
 *  @param[in/out] p_queue_inst pointer to the queue instance data
 *  @param[in] p_user_buf a pointer to a user buffer to receive a copy of the accummulated stats
 */
void telemetry_queue_get_stats(tlm_queue_rt_t *const p_queue_inst, tlm_queue_stats_t *const p_user_buf);

/** @brief Used to updates specific internal stat counters externally.
 *
 *  @param[in/out] p_queue_inst pointer to the queue instance data
 *  @param[in] stat_id identifier of the stats parameter to update
 *  @param[in] value specific value to use for the specified stat counter
 *
 *  @note The function is provided as a helper to enable storage of stats information related to the queue
 *        in one place for convenience.
 */
void telemetry_queue_update_stats(tlm_queue_rt_t *const p_queue_inst, const tlm_queue_stats_id_t stat_id, const uint32_t value);

/** @brief Reset the currently accumulated stats.
 *
 *  @param[in/out] p_queue_inst pointer to the queue instance data
 */
void telemetry_reset_stats(tlm_queue_rt_t *const p_queue_inst);

/** @brief Check if the telemetry queue buffer reached a certain threshold of used bytes.
 *
 *  @param[in/out] p_queue_inst pointer to the queue instance data
 *  @retval true: the queue reached the threshold
 *  @retval false: the queue is above the threshold
 *
 * @note The threshold is defined as a percentage of the total queue size. @ref TELEMETRY_QUEUE_LOW_SPACE_THRESHOLD
 */
bool telemetry_queue_reached_threshold(const tlm_queue_rt_t *const p_queue_inst);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif /* TELEMETRY_QUEUE_H */
