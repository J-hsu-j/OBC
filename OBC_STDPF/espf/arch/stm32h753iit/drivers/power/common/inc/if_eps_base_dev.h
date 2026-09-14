/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_IF_EPS_BASE_DEV_H_
#define ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_IF_EPS_BASE_DEV_H_

/**
 * @addtogroup eps_iii
 * @{
 *
 * @brief The idea of this interface is to add an abstraction of EPS device module.
 *
 * @file if_eps_base_dev.h
 * @brief Interface for EPS device.
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
 * Type for a context of an EPS  device
 *
 */
typedef struct eps_dev_base_s eps_dev_base_t;

/**
 * @brief Prototype initialization function which need to be provided by each instance of EPS Base device class. It's responsible to initialize all the specific variables the instance have.
 *
 * @param self pointer to EPS device base context.
 * @param mac_address MAC address of the device.
 */
typedef void (*p_init_t)(eps_dev_base_t *const self, uint8_t mac_address);

/**
 * @brief Structure describing the context of an EPS base device.
 *
 * This structure contains all properties and operations provided by an EPS base device.
 *
 */
struct eps_dev_base_s
{
    /** instance of @ref eps_dev_t class which shall cover all the basic needs of EPS device*/
    eps_dev_t eps_dev_info;
    /** pointer to initialization function from prototype @ref p_init_t. This function shall cover initialization needs of
       different specifics for different instances.  */
    p_init_t const p_init;
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

#endif /* ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_IF_EPS_BASE_DEV_H_ */
