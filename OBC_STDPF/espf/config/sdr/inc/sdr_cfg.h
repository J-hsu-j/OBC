/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef SDR_CFG_H
#define SDR_CFG_H

/**
 * @addtogroup sdr
 * @{
 *
 * @file    sdr_cfg.h
 * @brief   SDR Library configuration header
 *
 * This file contains the configuration options for the SDR Library.
 * It defines various constants and macros related to the SDR CSP address,
 * communication, TFTP, and application ports.
 *
 * @}
 */

#include "eps_ctrl_cfg.h"
#include "csp_access.h"
#include "fm_def.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
/** Number of SDR instances supported by this module */
#define SDR_INST_CNT (1U)

/** @brief Default CSP address for the SDR Library */
#define SDR_CSP_ADDRESS (10U)

/** @brief Default CSP address to be used if SDR_CSP_ADDRESS is not specified */
#define SDR_CSP_DEFAULT_ADDRESS (10U)

/** @brief Timeout value (in milliseconds) for receiving data over CSP */
#define SDR_CSP_RECEIVE_TIMEOUT_MS (1000U)

/** @brief Timeout value (in milliseconds) for sending data over CSP */
#define SDR_CSP_SEND_TIMEOUT_MS (1000U)

/** @brief SDR service periodic cycle time */
#define SDR_SERVICE_DELAY_MS (200U)

/** @brief Number of connection retries for CSP communication */
#define SDR_CSP_CONNECTION_RETRIES (10U)

/** @brief Wait time (in milliseconds) between connection retries for CSP communication */
#define SDR_CSP_CONNECTION_RETRIES_WAIT (10U)

/** @brief CSP connection options */
#define SDR_CSP_CONNECTION_OPTIONS (CSP_O_NONE)

/** @brief Size of the client I/O buffer */
#define SDR_CSP_CLIENT_IO_BUFF_SIZE (256U)

/** @brief Block size for TFTP communication */
#define SDR_CSP_TFTP_BLOCK_SIZE (256U)

/** @brief Maximum size of the TFTP filename */
#define SDR_CSP_TFTP_FILENAME_MAX_SIZE (512U)

/** @brief Maximum size of the TFTP error message */
#define SDR_CSP_TFTP_ERR_MSG_MAX_SIZE (512U)

/** @brief Maximum value for the TFTP block number */
#define SDR_CSP_TFTP_BLOCK_N_MAX_VALUE (65535U)

/** @brief Port number for the SDR RPC application */
#define SDR_CSP_RPC_PORT (10U)

/** @brief Port number for the SDR TFTP application */
#define SDR_CSP_TFTP_PORT (11U)

/** @brief Timeout value (in milliseconds) for acquiring the sdr lock */
#define SDR_LOCK_TIMEOUT_MS ((uint32_t)10000UL)

/** @brief Timeout value (in milliseconds) for acquiring the sdr lock to read operation status */
#define SDR_LOCK_OP_STAT_TIMEOUT_MS osWaitForever

/** @brief SDR EPS II power on/off control */
#define POWER_OUT_SDR_EN (EPS_CTRL_CH_1)

/** @brief SDR Logging system enable - 1 enabled; 0 disabled */
#define SDR_LOG_SYS (0U)

/** @brief SDR boot procedure polling period */
#define SDR_BOOT_POLL_PERIOD_MS (1000U)

/** @brief SDR time sync procedure timeout */
#define SDR_SYNC_TIMEOUT_MS (30000U)

/** @brief SDR time sync date format */
#define DATE_FORMAT ("%04d-%02d-%02d")

/** @brief SDR time sync time format */
#define TIME_FORMAT ("%02d:%02d:%02d")

/** @brief SDR max filename length */
#define SDR_MAX_FILE_NAME_LEN (197U)

/** @brief OBC max filename length */
#define OBC_MAX_FILE_NAME_LEN (FM_MAX_PATH)

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
/* No External variables declarations */

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

#ifdef __cplusplus
}
#endif // __cplusplus
#endif /* SDR_CFG_H */
