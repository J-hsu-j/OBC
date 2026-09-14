/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_IF_ESPS_DEV_H_
#define ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_IF_ESPS_DEV_H_

/**
 * @addtogroup eps_iii
 * @{
 *
 * @brief This is common interface which can be used by ESPS devices.
 *
 * @file if_esps_dev.h
 * @brief Interface for ESPS device.
 *
 * Provides abstraction of a device which uses the ESPS protocol for communication.
 *
 * @}
 */

#include "FP_common/FP_BaseProtocolTypes.h"

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
 * @brief Structure which is used to store a context of one ESPS device.
 *
 */
typedef struct
{
    /**
     * MAC communication address of the deivce
     */
    uint8_t mac_addr;
    /**
     * as each device attached to the network can provide some FDIR faults here we have also the FDIR ID of the device.
     */
    uint8_t fdir_id;
    /**
     * Sequence ID - this field can be used to check if response of a device is for specific request.
     */
    SeqId_t seq_id;
} esps_dev_t;

/**
 * @brief This type is kind of extension to the  ESSATMAC_ErrCodes type as there are some errors
 * additional errors which can be detected for Communication failure.
 *
 */
typedef enum
{
    FDIR_CMD_EXEC_OK                   = ESSATMAC_EC_OK,
    FDIR_CMD_EXEC_ERROR                = ESSATMAC_EC_ERROR,
    FDIR_CMD_EXEC_NULL                 = ESSATMAC_EC_NULL,
    FDIR_CMD_EXEC_BUSY                 = ESSATMAC_EC_BUSY,
    FDIR_CMD_EXEC_NO_MEM               = ESSATMAC_EC_NO_MEM,
    FDIR_CMD_EXEC_Q_FULL               = ESSATMAC_EC_Q_FULL,
    FDIR_CMD_EXEC_Q_NOT_EMPTY          = ESSATMAC_EC_Q_NOT_EMPTY,
    FDIR_CMD_EXEC_RETRY_COUNT_LIMIT    = ESSATMAC_EC_RETRY_COUNT_LIMIT,
    FDIR_CMD_EXEC_TX_COLLISION         = ESSATMAC_EC_TX_COLLISION,
    FDIR_CMD_EXEC_UNSUPPORTED_NET_TYPE = ESSATMAC_EC_UNSUPPORTED_NET_TYPE,
    FDIR_CMD_EXEC_INVALID_PARAMS       = ESSATMAC_EC_INVALID_PARAMS,
    FDIR_CMD_EXEC_BUS_BUSY             = ESSATMAC_EC_BUS_BUSSY,
    FDIR_CMD_EXEC_TIMEOUT
} FDIR_CMD_EXEC_ErrCodes;

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

#endif /* ESPF_ARCH_STM32H753IIT_DRIVERS_POWER_IF_ESPS_DEV_H_ */
