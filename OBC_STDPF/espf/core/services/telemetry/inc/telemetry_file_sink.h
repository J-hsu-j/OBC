/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef TELEMETRY_FILE_SINK_H
#define TELEMETRY_FILE_SINK_H

/**
 * @addtogroup service_tlm
 * @{
 *
 * @file telemetry_file_sink.h
 *
 * @brief A description of the module’s purpose.
 *
 * @}
 *
 */

#include "es_cdef.h"
#include "if_telemetry_sink.h"

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

/** @brief Synchronized version of the clean operation which can be called outside the telemetry HSM safely
 *
 *  @param[in/out] p_tlm_filesink_rt_ctx file sink runtime context data pointer
 *
 * */
void telemetry_file_sink_syncd_clean(tlm_file_sink_rt_ctx_t *const p_tlm_filesink_rt_ctx);

/** @brief Unsynchornized version of the clean operation which can be called internally in the HSM only
 *
 *  @param[in/out] p_tlm_filesink_rt_ctx file sink runtime context data pointer
 *
 * */
void telemetry_file_sink_clean(const tlm_file_sink_rt_ctx_t *const p_tlm_filesink_rt_ctx);

/** @brief Used externally to inform about configuration changes which require a restart of the running
 *         telemetry.
 *
 *  @param[in/out] p_tlm_filesink_rt_ctx file sink runtime context data pointer
 *
 */
void telemetry_file_sink_config_update(tlm_file_sink_rt_ctx_t *const p_tlm_filesink_rt_ctx);

extern telemetry_sink_if_t telemetry_file_sink_if;

#ifdef __cplusplus
}
#endif // __cplusplus
#endif /* TELEMETRY_FILE_SINK_H */
