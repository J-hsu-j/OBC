/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_IF_EPS_CTRL_H_
#define ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_IF_EPS_CTRL_H_

/**
 * @addtogroup eps_iii
 * @{
 *
 * @brief This is common interface used by EPS devices which have some input/output channels to control.
 *
 * @file if_eps_ctrl.h
 * @brief Interface for EPS controller device.
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

/** type for a context of an EPS control device
 */
typedef struct if_eps_ctrl_s if_eps_ctrl_t;

/**
 * @brief Prototype of notification function used when a set channel command response is received
 *
 * it is not important which exactly was the command because only one command at a time is supported,
 * so always it will be the response from the last sent command
 *
 * @param is_successful whether or not the command for setting an output was sent successfully.
 *
 */
typedef void (*p_on_set_output_response_received_t)(bool is_successful);

/**
 * @brief Prototype of notification function used when a get channel command response is received
 *
 * It is not important which exactly was the command because only one command at a time is supported,
 * so always it will be the response from the last sent command
 *
 * @param is_successful - whether or not the command for setting an output was sent successfully.
 * @param status - the status of the read channel.
 *          true if the channel is ON
 *          false if the channel is OFF
 */
typedef void (*p_on_get_output_response_received_t)(bool is_successful, bool status);

/**
 * @brief Prototype of a set output function. Different implementation of this function shall be provided for different
 * EPS devices.
 *
 * @param self - pointer to the EPS controller context.
 * @param chn_id - id of the channel to be set
 * @param new_state - the new state of the channel to be set
 *                          - true - if we want to Turn On the channel
 *                          - false - if we want to Turn Off the channel
 *
 * @retval true in case the command is successfully sent
 * @retval false if there is an issue with sending the command.
 */
typedef bool (*set_output_t)(const if_eps_ctrl_t *const self, uint8_t chn_id, bool new_state);

/**
 * @brief Prototype of a get output function. Different implementation of this function shall be provided for different
 * EPS devices.
 *
 * @param self pointer to the EPS controller context.
 * @param chn_id id of the channel to be set
 * @param new_state the new state of the channel to be set
 *                          - true - if we want to Turn On the channel
 *                          - false - if we want to Turn Off the channel
 *
 * @retval true in case the command is successfully sent
 * @retval false if there is an issue with sending the command.
 */
typedef bool (*get_output_t)(const if_eps_ctrl_t *const self, uint8_t chn_id);

/**
 * @brief this structure is used to store a context for EPS controller device. Each EPS controller device has to have an instance of this structure.
 *
 */
struct if_eps_ctrl_s
{
    eps_dev_t *const                          p_device_info;
    const set_output_t                        p_set_output;
    const get_output_t                        p_get_output;
    const p_on_set_output_response_received_t p_on_set_output_response_received;
    const p_on_get_output_response_received_t p_on_get_output_response_received;
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

#ifdef __cplusplus
}
#endif

#endif /* ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_IF_EPS_CTRL_H_ */
