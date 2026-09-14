/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup eps_iii
 * @{
 *
 * @file     eps_iii_config.c
 * @brief    EPS III drivers configuration
 *
 * @}
 */

#include "eps_iii_config.h"
#include "nvm.h"
#include <string.h>

void eps_iii_cfg_get_eps_iii_mac_addresses(uint8_t *p_eps_iii_bp_address_book, uint8_t dev_count)
{

    mac_address_book_t addresses = { 0 };

    BREAK_ASSERT(dev_count == sizeof(addresses.a_eps_iii_addresses));

    // Read the NVM
    Nvm_GetBlockById(NVM_MAC_ADDRESS_BOOK, &addresses);

    memcpy(p_eps_iii_bp_address_book, addresses.a_eps_iii_addresses, dev_count);
}
