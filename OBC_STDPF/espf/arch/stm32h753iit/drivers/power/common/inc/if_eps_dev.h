/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_IF_EPS_DEV_H_
#define ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_IF_EPS_DEV_H_

/**
 * @addtogroup eps_iii
 * @{
 *
 * @brief The idea of this interface is to add an abstraction of EPS device module.
 *
 * @file if_eps_dev.h
 * @brief Interface for EPS device.
 *
 * @}
 */
#include "if_esps_dev.h"
#include "datacache.h"
#include "fdir_srv_cfg.h"

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
 * @brief Type for a context of an EPS control device
 *
 */
typedef struct eps_dev_s eps_dev_t;

/**
 * @brief  Initialization function prototype for EPS devices. Each EPS device requires a MAC address, which is typically
 * not constant and is obtained from a configuration source. This function is used to configure MAC address for each EPS device.
 * In addition, all internal variables for each device instance must be initialized with appropriate initial values.
 *
 * @param self pointer to EPS device context.
 * @param mac_address MAC address of the device.
 */
typedef void (*eps_dev_init_t)(eps_dev_t *const self, uint8_t mac_address);

/**
 * @brief Prototype of EPS device process FDIR fault function.
 *
 * As each device may have different FDIR faults this interface is left for handling those differences.
 *
 * @param self pointer to EPS device context.
 */
typedef void (*process_fdir_faults_t)(const eps_dev_t *const self);

/**
 * @brief Prototype of function which has to check if a sequence id with value equal to the second argument of the function is expected by the EPS device.
 * This sequence id can be used to find out if a message received by the device is in fact expected by the device.
 *
 * @param self pointer to EPS device context.
 * @param seq_id sequence id to be checked
 * @retval true in case the sequence ID is really expected
 * @retval false when no such sequence ID is expected.
 *
 */
typedef bool (*p_is_seq_expected_t)(const eps_dev_t *const self, SeqId_t seq_id);

/**
 * @brief Type to be used for returned error codes of the FDIR faults
 */
typedef FDIR_CMD_EXEC_ErrCodes fault_exec_status_t;

/**
 * @brief Implementation of the @ref *p_is_seq_expected_t prototype
 *
 */
bool eps_dev_is_seq_expected(const eps_dev_t *const self, SeqId_t seq_id);

/**
 * @brief Structure describing the context of an EPS device.
 *
 * This structure contains all properties and operations provided by an EPS device driver
 *
 */
struct eps_dev_s
{
    /** this element contains EPS device info for the ESPS  */
    esps_dev_t esps_dev_info;
    /** pointer to the initialization function of the EPS device. */
    eps_dev_init_t p_dev_init;
    /** pointer to the FDIR processing function for the EPS device */
    process_fdir_faults_t p_process_fdir_faults;
    /** table with IDs of all supported datacache elements for this EPS device. Those elements are filled by the EPS device based on the telemetry received */
    const dc_did_id *const datacache_cmd_list;
    /** count of the supported datacache elements */
    uint8_t cmd_list_cnt;
    /** table which contains execution statuses for all FDIR faults supported by the device*/
    fault_exec_status_t *const p_fdir_exec_status;
    /** count of fdir faults supported by the device */
    uint8_t fault_exec_status_cnt;
    /** pointer to function for checking if sequence number received is the expected one */
    p_is_seq_expected_t p_is_seq_expected;
    /** table of fault IDs that the device support.*/
    const fdir_fault_id_t *const fdir_fault_ids;
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
 * @brief Common initialization function for all EPS devices. It follows the prototype described here : @ref  eps_dev_init_t
 */
void eps_dev_init(eps_dev_t *const self, uint8_t mac_address);

#ifdef __cplusplus
}
#endif

#endif /* ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_IF_EPS_DEV_H_ */
