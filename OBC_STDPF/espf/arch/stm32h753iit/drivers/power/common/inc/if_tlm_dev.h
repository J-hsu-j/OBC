/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_IF_TLM_DEV_H_
#define ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_IF_TLM_DEV_H_

/**
 * @addtogroup eps_iii
 * @{
 *
 * @brief This is common interface for devices which provide telemetry using ESPS protocol.
 *
 * @file if_tlm_dev.h
 * @brief Interface for ESPS device which can gather telemetry.
 *
 * Provides abstraction of a device which ESPS protocol for gathering telemetry.
 *
 * @}
 */

#include "if_esps_dev.h"
#include "if_eps_dev.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
/* No External defines*/

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/
/**
 * @brief Configuration structure for a telemetry device
 *
 */
typedef struct
{
    /**  * Telemetry requests are sent in batches, with several commands grouped together.
     * This parameter specifies the wait time between sending two such groups.
     * Using this parameter helps manage and control the network load. */
    uint8_t delay_between_sending;
    /** Parameter to change the messages which can be sent at once for one and the same device. Some devices have smaller buffers and can handle less messages, so this has to be aligned with the specific device. */
    /**  * Telemetry requests are sent in batches, with several commands grouped together.
     * This parameter specifies how many commands will be grouped together */
    uint8_t max_msg_to_send;
} tlm_cfg_t;

/**
 * Type for a context of an EPS control device
 *
 */
typedef struct if_tlm_s if_tlm_t;

/*
 * Prototype of Get telemetry function. This function is used to process all commands for getting the telemetry from a device.
 */
typedef void (*get_telemetry_t)(const if_tlm_t *const self);

/** Prototype of command which can send a command for requesting a telemetry info. Most of the time this can directly pointing a FP request command, but it could be also customized if required. */
typedef ESSATMAC_ErrCodes (*get_telemetry_req_t)(ReqContext_t *ctx);

/**
 * @brief Structure describing the context of an EPS Telemetry device.
 *
 * This structure contains all the properties and operations of EPS Telemetry device.
 *
 */
struct if_tlm_s
{
    /** base context of EPS device */
    eps_dev_t *const p_device_info;
    /** pointer to configuration structure */
    const tlm_cfg_t tlm_cfg;
    /** pointer to Get telemetry function which request all telemetry info with going through all telemetry request functions configured*/
    const get_telemetry_t p_get_telemetry;
    /** pointer to Table of pointers to get telemetry request functions to be used when telemetry is requests */
    const get_telemetry_req_t *const p_tlm_req_cmds;
    /** Count of the get telemetry request functions for this device */
    const uint8_t tlm_cmd_cnt;
};

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
/**
 * @brief This function goes trough all configured telemetry requests and sends each of them one by one according to the configuration
 * which is part of the @ref tlm_cfg_t structure contained in the instance.
 *
 * @param self The "self" argument is a convention used to pass a pointer to the instance of the structure
 * to which this function belongs.
 */
void tlm_dev_get_telemetry(const if_tlm_t *const self);

#ifdef __cplusplus
}
#endif

#endif /* ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_IF_TLM_DEV_H_ */
