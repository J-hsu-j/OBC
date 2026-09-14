/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef ESPS_DRV_EXTERNAL_H
#define ESPS_DRV_EXTERNAL_H

/**
 * @addtogroup Drivers
 * @{
 *
 * @defgroup espsi_drv ESPS I MAC Driver
 * @{
 *
 * External ESPS driver interfaces declaration. Shall be provided by the host system where the
 * driver is integrated.
 *
 * @file     esps_drv_external.h
 *
 * @brief    ESPS I MAC Driver interface
 *
 * @}
 * @}
 *
 */

// External imports
#include "esps_drv_esps_stack.h"

#include "esps_drv_cdef.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * Public Types
 *****************************************************************************/

/******************************************************************************
 * Public Functions Declarations
 *****************************************************************************/

#if defined(USE_CUSTOM_ESPS_MSG_DISPATCH_HANDLER)
/** @brief Implemented by the user to perform special handling of any received ESPS frame.
 *
 *  Can be used to skip standard processing for certain frames.
 *
 *  @param[in] pMACContext contextual information about the received frame
 *  @param[in] pMsgData pointer to the frame data bytes
 *  @param[in] nMsgDataSize size of the received frame
 */
void custom_esps_data_dispatch(ESSATMAC_Context *pMACContext, const uint8_t *pMsgData, uint8_t nMsgDataSize);
#endif  // defined(USE_CUSTOM_ESPS_MSG_DISPATCH_HANDLER)

/** @brief Performs an address match against a list of system configured addresses from which frames
 *  shall be accepted.
 *
 *  The function actually controls whether reception shall continue for the given frame. Accepting all
 *  frames may lead to increased CPU load because the ESPS driver relies on byte interrupts for the frame
 *  reception. This function enables first-level filtration of frames when only a few bytes have been received (i.e.
 *  the ESPS frame header).
 *
 *  @param[in] addr MAC address received on the bus
 *  @param[in] mac_if MAC physical interface on which addr was received
 *
 *  @retval true: The received frame with the corresponding address shall be accepted.
 *  @retval false: The received frame with the corresponding address shall be dropped.
 */
bool MacCfg_Match_Target_Addr(const uint8_t addr, const eMACInterface_t mac_if);

#ifdef __cplusplus
}
#endif

#endif //ESPS_DRV_EXTERNAL_H
