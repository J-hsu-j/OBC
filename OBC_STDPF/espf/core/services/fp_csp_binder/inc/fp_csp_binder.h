#ifndef FP_CSP_BINDER_H
#define FP_CSP_BINDER_H

/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#include "ESPLATFORM_NETWORK_STACK/ES_SAT_API/include/ESSA_Stack.h"
#include "ESPLATFORM_NETWORK_STACK/ES_SAT_MAC/ES_SAT_MAC.h"

/** @brief Start the FP service
 *
 *  @retval true: ESPS-over-CSP successfully initialized
 *  @retval false: ESPS-over-CSP init failed
 * */
bool fp_csp_binder_start(void);

#endif /* FP_CSP_BINDER_H */
