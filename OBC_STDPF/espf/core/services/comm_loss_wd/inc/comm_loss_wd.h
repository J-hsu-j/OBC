/*
 * Copyright (c) 2020-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef COMM_LOSS_WD_
#define COMM_LOSS_WD_

#include "nvm.h"
#include "fp/UHF/v0.5/UHF_client/FP_UHFProtocolClient.h"
#include "arch/stm32h753iit/drivers/radio/sband_tmtc/fp/SBAND_TMTC/v1.12/SBAND_TMTC_client/FP_SBAND_TMTCProtocolClient.h"
#include "arch/stm32h753iit/drivers/power/eps_ii/fp/EPSII_PDM_1/v1.0/EPSII_PDM_1_client/FP_EPSII_PDM_1ProtocolClient.h"
#include "config/beacons/beacons_cfg_user.h"

/**
 * @brief Initializes the COMM_LOSS_WD service.
 *
 * The function also takes care to initialize
 *
 * @param N/A
 *
 * @note Actual loading of data from the storage is not performed by this function.
 */
void comm_loss_wd_init(void);

/**
 * @brief Handling COMM_LOSS_WD service functionality.
 *
 * @param pointer to communication loss WD task
 *
 * @note To be called periodically to handle communication loss WatchDog in accordance with the timeout period.
 */
void comm_loss_wd_task(void *argument);

/**
 * @brief Set ground station communication loss WatchDog timeout period.
 *
 * @param timeout_period_min - unsigned int timeout period value in minutes
 *
 * @note Timeout period is in minutes, can be changed via fidl.
 */
bool comm_loss_wd_set_timeout(uint32_t timeout_period_min);

/**
 * @brief Set ground station communication loss WatchDog Enable/Disable flag.
 *
 * @param enable_flag - boolean type flag, that is used to enable or disable the WD
 *
 * @note Enable or Disable WD
 */
bool comm_loss_wd_set_enable(bool enable_flag);

/**
 * @brief Get current ground station communication loss WatchDog timeout period.
 *
 * @return Unsigned int type timeout period value in minutes
 *
 * @note Timeout period is in minutes, by default 72h, can be changed via fidl.
 */
uint32_t comm_loss_wd_get_timeout(void);

/**
 * @brief Get current ground station communication loss WatchDog enable flag.
 *
 * @retval return boolean status of the WD enable/disable flag
 *
 * @note Flag for enable/disable WD.
 */
bool comm_loss_wd_get_enable(void);

/**
 * @brief Check counter registers from the UHF radio module to perform WD reboot if needed.
 *
 * @param UHF_sCounters - pointer to UHF counter register containing GS handshakes.
 *
 * @note Pass the complete set of UHF_sCounters, however only GS_Handshake is currently required.
 */
void comm_loss_wd_check_uhf_counter_registers(const UHFReadCountersResponseData_t *const p_uhf_counters);

/**
 * @brief Check RX packet counter from the UHF radio module to perform WD reboot if needed.
 *
 * @param uhf_rx_packets - pointer to counter reg that contains number of RX packets
 *
 * @note Pass the  number of RX packets count.
 */
void comm_loss_wd_check_uhf_rx_packet_count(const UHFReadNumberOfRxPacketsResponseData_t *const p_uhf_rx_packets);

/**
 * @brief Check counter registers from the SBAND radio module to perform WD reboot if needed.
 *
 * @param SBAND_TMTC_sErrCounters - pointer to TMTC error counters structure containing multiple fields including GS_Handshake required.
 *
 * @note Pass the complete set of SBAND_TMTC_sErrCounters, however only GS_Handshake is currently required.
 */
void comm_loss_wd_check_sband_error_counters(const SBAND_TMTCReadErrorCountersResponseData_t *const p_tmtc_err_counters);

/**
 * @brief Check RX packet counter from the SBAND TMTC radio module to perform WD reboot if needed.
 *
 * @param SBAND_TMTC_sErrCounters - pointer to counters structure containing multiple fields including number of RX packets.
 *
 * @note Pass the  number of RX packets count.
 */
void comm_loss_wd_check_sband_packet_counters(const SBAND_TMTCGetPacketCountersResponseData_t *const p_sband_packets);

#endif /* COMM_LOSS_WD_ */
