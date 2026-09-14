/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef CSP_SERVICE_H_
#define CSP_SERVICE_H_

/**
 * @addtogroup Services
 * @{
 *
 * @defgroup csp_service
 * @{
 *
 * @file csp_service.h
 *
 * @brief Initialisation of the CSP stack (router task, ping handler, default route, etc.)
 *
 * @}
 * @}
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "FP_csp_serviceProtocolTypes.h"

/**
 * @brief Initialises the CSP stack.
 *
 * @retval true  Initialisation complete
 * @retval false Initialisation error
 */
bool csp_service_init(void);

/**
 * @brief Modify CSP trace levels according to the specified setting.
 *
 * @param  Trace levels select
 * @retval true  Set done
 *
 */
bool csp_service_set_trace_level(CSP_SERVICE_debug_levels_t trace_levels);

/**
 * @brief Return CSP trace levels.
 *
 * @param  None
 * @retval Returns trace levels.
 *
 */
CSP_SERVICE_debug_levels_t csp_service_get_trace_level(void);

#ifdef __cplusplus
}
#endif

#endif /* CSP_SERVICE_H_ */
