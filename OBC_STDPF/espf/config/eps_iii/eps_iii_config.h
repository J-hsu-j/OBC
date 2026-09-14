/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef ESPF_CONFIG_EPS_III_EPS_III_CONFIG_H_
#define ESPF_CONFIG_EPS_III_EPS_III_CONFIG_H_

/**
 * @addtogroup eps_iii
 * @{
 *
 * @file     EPS_III_config.h
 * @brief    EPS III drivers configuration
 *
 * @}
 */
#include "es_cdef.h"

// As the EPS devices have limited queues for receiving/transmitting messages(5 for RCV and 3 for TX)
// this delay need to be used after each 3 messages sent to the device.
#define EPS_III_NEEDED_DELAY_FOR_PROCESSING (3000) /**< Request for telemetry to EPS III device. Every 3s*/

/**
 * @brief Read the MAC EPS III BP addresses from the nvm MAC Address book.
 *
 * @param p_bp_address_book - pointer to an array which will be filled with all the EPS_III device addresses
 * @param dev_count - count of all EPS_III devices. This is needed, because the number of the devices is configurable.
 */
void eps_iii_cfg_get_eps_iii_mac_addresses(uint8_t *p_bp_address_book, uint8_t dev_count);

#endif /* ESPF_CONFIG_EPS_III_EPS_III_CONFIG_H_ */
