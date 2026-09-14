/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef SDR_H
#define SDR_H

/**
 * @addtogroup Services
 * @{
 *
 * @defgroup sdr sdr
 * @{
 *
 * The sdr component is responsible for initializing sdr resources
 * and their usage in sdr user operation requests, such as file transfers or commanding.
 *
 * @attention
 * @{
 *  Assumption: CSP has been initialized and configured with a valid physical interface!
 * @}
 *
 * @file sdr.h
 * @brief sdr service public interface
 *
 * @}
 * @}
 *
 */

#include "es_cdef.h"
#include "trace.h"
#include "timer.h"
#include "assertions.h"
#include "taskmon_stat.h"
#include "libhsm.h"

/* sdr configuration */
#include "sdr_cfg.h"

/* sdr types */
#include "sdr_types.h"

/* es sdr command protocols */
#include "es_common_types.pb.h"
#include "es_adrv9009.pb.h"
#include "es_board_info.pb.h"
#include "es_board_mgr.pb.h"
#include "es_iprium_dvb_s2.pb.h"
#include "es_rce.pb.h"
#include "es_test.pb.h"

/* es sdr api */
#include "essdr.h"

/* cmsis api */
#include "cmsis_os2.h"

/* csp configuration */
#include "csp_service_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

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

/**
 * @brief sdr service thread initialisation routine
 */
void sdr_thread_init(void);

/**
 * @brief sdr service state machine event trigger
 *
 * @param event_id event identifier
 *
 * @return true if the event was successfully triggered, false otherwise
 */
bool sdr_trigger_hsm(const uint32_t event_id);

/**
 * @brief sdr service register csp transport layer
 */
void sdr_tl_init(void);

/**
 * @brief sdr service deinitialization routine
 */
void sdr_comm_deinit(void);

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus
#endif /* SDR_H */
