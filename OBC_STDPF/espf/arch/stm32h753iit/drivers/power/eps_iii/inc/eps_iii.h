/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef eps_iii_H_
#define eps_iii_H_
/**
 * @addtogroup Drivers
 * @{
 *
 * @defgroup eps_iii EPS III Driver
 * @{
 *
 * Interact with the Endurosat [EPS III
 * module](https://www.endurosat.com/products/eps-iii/).
 * This module is connected to the OBC using the RS-485 bus and the ESPS I protocol.
 *
 * ## Usage
 *
 * ### Channel control
 *
 * The OBC can send requests to the PDM (Power Distribution Module) by using `eps_iii_set_channel_output`
 *  or  `eps_iii_get_channel_output`.
 *
 * ```C
 * #include "eps_iii.h"
 *
 * void my_func_calling_eps_iii(){
 *
 *     eps_iii_ctrl_ch_t channel = eps_iii_CTRL_5V_Ch2_Master;
 *     bool state = true;
 *
 *     bool b_res = eps_iii_set_channel_output(channel, state);
 *
 *     if (b_res){
 *         // Set request was sent successfully
 *         b_res = eps_iii_get_channel_output()
 *     }
 *     if(b_res){
 *         // Get request was sent successfully
 *         // Do something
 *     }
 * }
 * ```
 * Whenever a response arrives, the callback from the ESPS FP is called (FP_EPSII_PDM_1ClientApp.c).
 *
 * These two functions are sending an ESPS I requests to the PDM EPS III module. You would need to
 * take care of processing the response in your application.
 *
 * ## EPS Control integration
 * The enumeration type `eps_iii_ctrl_ch_t` holds all the controllable values of the EPS III module.
 *  This type is used by the @ref eps_ctrl service to set and get the status from the EPS III instead of
 *  calling separately the GPIOs and the Power Outputs.
 *
 * @note The @ref eps_ctrl service takes care of setting the channels of any EPS modules,
 *  the drivers should not be called directly.
 *
 * @file     eps_iii.h
 *
 * @brief    Driver for EnduroSat Electric Power System III (EPS III)
 *
 * @}
 * @}
 *
 */
/*
********************************************************************************************
* INCLUDES
********************************************************************************************
*/
#include <if_sys_mod.h>
#include <sys_instancer_ct.h>

#include "fp/EPSII_BP_1/v3.0/EPSII_BP_1_client/FP_EPSII_BP_1ProtocolTypes.h"
#include "fp/EPSII_PDM_1/v1.0/EPSII_PDM_1_client/FP_EPSII_PDM_1ProtocolTypes.h"

#include "eps_iii_cfg.h"
#include "if_eps_ctrl.h"
#include "if_eps_base_dev.h"

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
 * @brief type used to map EPS III channels to the specific submodules(devices) in EPS III and there channel indexes.
 *
 */
typedef struct
{
    /** EPS III channel ID. This id is visible and used by the EPS Control Service to map the system channels to EPS III channels */
    eps_iii_ctrl_ch_t ch_id;
    /** pointer to EPS controller interface context. Using this interface EPS Control Service can request setting/getting channel info */
    const if_eps_ctrl_t *eps_ctrl_ctx;
    /** Identification number of the channel for the specific submodule */
    uint8_t eps_ctrl_dev_ch_id;
} eps_iii_ch_map_t;

/**
 * @brief This structure is used to describe the place and size of the data for a DataCache element in device response frame.
 *
 * Each element in the telemetry response for EPS III devices has a corresponding element
 * in the data cache with the same size and structure. This allows for direct copying
 * of data from the response to the data cache element without any checks.
 * To facilitate this process, we need to know the exact position and size of the data in the response. *
 */
typedef struct
{
    /** address of the element to copy*/
    const uint8_t *address_of_dc_value_in_response;
    /** size of the element to copy*/
    uint8_t size;
} bp_response_map_type;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/

/**
 * Configuration interface for the system instancer */
extern if_sys_mod_t eps_iii_module_configuration;

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

/** @brief system instancer init interface function
 *  @param level initialization level to initialize
 *
 *  @retval STATUS_FAILED: initialization went wrong
 *  @retval STATUS_OK: everything is initialized
 *  @retval STATUS_NOT_SUPPORTED: there is no such level of initialization for the module
 */
mod_op_status_id_t eps_iii_init(sys_init_level_id_t level);

/** @brief system instancer run interface function
 *
 *  @retval STATUS_FAILED: failed to start the module
 *  @retval STATUS_OK: the module is running
 *  @retval STATUS_NOT_SUPPORTED: not implemented for this module
 */
mod_op_status_id_t eps_iii_run(void);

/** @brief system instancer stop interface function
 *
 *  @retval STATUS_FAILED: failed to stop the module
 *  @retval STATUS_OK: module dependencies stopped
 *  @retval STATUS_NOT_SUPPORTED: not implemented for this module
 */
mod_op_status_id_t eps_iii_stop(void);

/** @brief system instancer deinit interface function
 *  @param level initialization level to initialize
 *
 *  @retval STATUS_FAILED: deinitialization went wrong
 *  @retval STATUS_OK: everything is deinitialized
 *  @retval STATUS_NOT_SUPPORTED: there is no such level of initialization for the module
 */
mod_op_status_id_t eps_iii_deinit(sys_init_level_id_t level);

/** @brief Send a request to set the channel outputs of the EPS III
 *  @param channel - channel to be set
 *  @param state new state of the channel
 *
 *  @retval false: failed to send the request
 *  @retval true: the request has been sent successfully
 */
bool eps_iii_set_channel_output(eps_iii_ctrl_ch_t channel, bool state);

/** @brief Request to get the status of a channel output
 *
 *  @channel EPS III id of the channel to be set. There is a list of channels available in EPS III which is based on configuration of the EPS III subsystem.
 *  @retval false: failed to send the request
 *  @retval true: the request has been sent successfully
 */
bool eps_iii_get_channel_output(eps_iii_ctrl_ch_t channel);

/**
 * @brief This function is a common handler of processing of telemetry notifications from different modules. In EPS III there is a possibility to have
 * common processing because the algorithm for filling the datacahce is exactly the same in all modules.
 *
 * @param pRespCtx
 * @param map_response_to_dc_element pointer to table with mapping between specific response and datacache element.
 * @param telemetry_dc_elements_cnt count of datacache elements to be processed.
 */
void telemetry_notif_process(const RespContext_t *const pRespCtx, const bp_response_map_type *const map_response_to_dc_element, uint8_t telemetry_dc_elements_cnt);

/**
 * @brief Function used to identify the device based on it's address
 *
 * @param addr Address to be searched in the device list.
 * @return pointer to eps device instance which have the needed address
 * @return NULL if the address is not found
 */
const eps_dev_base_t *eps_iii_get_eps_dev_by_addr(uint8_t addr);

/**
 * @brief Function used to identify the device based on it's address
 *
 * @param addr Address to be searched in the controller device list.
 * @return pointer to eps controller device instance which have the needed address
 * @return NULL if the address is not found
 */
const if_eps_ctrl_t *eps_iii_get_eps_ctrl_by_addr(uint8_t addr);

#ifdef __cplusplus
}
#endif

#endif /* eps_iii_H_ */
