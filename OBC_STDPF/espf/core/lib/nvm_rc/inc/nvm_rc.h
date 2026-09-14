/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef NVM_RESETCOUNTERS_H_
#define NVM_RESETCOUNTERS_H_

/**
 * @addtogroup Libraries
 * @{
 *
 * @defgroup nvm_rc NVM Reset Counters
 * @{
 *
 * Library providing tools to keep track of the reset reasons and to save them or read them
 * from the NVM. Please keep in mind that the library contains HW-specific implementation.
 *
 *
 * @file nvm_rc.h
 * @brief Public interface for the reset counters library
 *
 * @}
 * @}
 */

#include "es_cdef.h"

/**
 * @brief Defines the different reset reasons which can be used with the ClearResetCounter
 * ESPS FP command
 *
 */
typedef enum
{
    RSTCOUNTERID_WWD,        /**< Window Watchdog*/
    RSTCOUNTERID_IWD,        /**< Independent Watchdog */
    RSTCOUNTERID_LPR,        /**< Low-power mode security reset */
    RSTCOUNTERID_POR,        /**< Reset pin and/or Flash memory digital block reset */
    RSTCOUNTERID_RSTPIN,     /**< Reset pin */
    RSTCOUNTERID_BOR,        /**< Brown-out reset (power voltage under a specific limit) */
    RSTCOUNTERID_HARDFAULT,  /**< Hard-fault reset */
    RSTCOUNTERID_MEMFAULT,   /**< Memory-fault reset */
    RSTCOUNTERID_BUSFAULT,   /**< Bus-fault reset */
    RSTCOUNTERID_USAGEFAULT, /**< Usage-fault reset */
    RSTCOUNTERID_ALL,        /**< Used to clear all counters at once */
    RSTCOUNTERID_MAX
} nvm_rc_cntr_id_t;

/**
 * @brief Defines the different bit-masks for use with NVM storage of reset reasons.
 *
 */
typedef enum
{
    RST_REASON_WWD        = 0x01,
    RST_REASON_IWD        = 0x02,
    RST_REASON_LPR        = 0x04,
    RST_REASON_POR        = 0x08,
    RST_REASON_RSTPIN     = 0x10,
    RST_REASON_BOR        = 0x20,
    RST_REASON_HARDFAULT  = 0x40,
    RST_REASON_MEMFAULT   = 0x80,
    RST_REASON_BUSFAULT   = 0x100,
    RST_REASON_USAGEFAULT = 0x200,
} rst_reason_bits_t;

/** @brief Defines the different Hard fault MCU types supported */
typedef enum
{
    NVM_RC_HARD_FLT_TYPE_MEM,
    NVM_RC_HARD_FLT_TYPE_BUS,
    NVM_RC_HARD_FLT_TYPE_USAGE,
    NVM_RC_HARD_FLT_TYPE_HARD,
    NVM_RC_HARD_FLT_TYPE_MAX
} nvm_rc_hard_flt_type_t;

// defines to be used with NvmResetCounters_Update bClearResetReason argument
#define NVMUPDATE_CLEAR_RESET_REASON (true)
#define NVMUPDATE_KEEP_RESET_REASON  (false)

/**
 * @brief Used to clears the MCU reset reason register after reading its values.
 *
 */
void nvm_rc_clear_reset_reason(void);

/**
 * @brief Clears one or more reset reason counters
 *
 * @param cntrId ID of the reset counter to clear
 * @return
 */
bool nvm_rc_clear(nvm_rc_cntr_id_t cntrId);

/**
 * @brief Checks the MCU-specific reset reason register and increments any
 * reset reason counters available.
 *
 * @param bClearResetReason `true` - MCU-specific reset reason
 * register is cleared after the increment; `false` - register value is preserved
 * after incrementing the reset counters
 */
void nvm_rc_update(const bool bClearResetReason);

/**
 * @brief Returns the status of all reset counters as a bit field.
 *
 * @param[out] rst_reason_bits User-provided bit-field to be set according to the
 * reset reason status.
 * @return The sum of all reset counters stored in the system
 */
uint32_t nvm_rc_get_total(uint16_t *const rst_reason_bits);

/**
 * @brief Update the respective hard fault counter in NVM depending on the type of fault passed
 *
 * @param[in] flt_type type of hard fault which occurred
 */
void nvm_rc_hard_fault_cntr_update(const nvm_rc_hard_flt_type_t flt_type);

#endif /* NVM_RESETCOUNTERS_H_ */
