/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @defgroup I2C
 * @{
 *
 * The file defines the public interface of the I2C bus wrapper.
 *
 * @file MX_I2C.h
 * @brief I2C bus wrapper interface
 *
 * @}
 */

#ifndef MX_I2C_H
#define MX_I2C_H

/*
*********************************************************************************************
* INCLUDES
*********************************************************************************************
*/
#include <main.h>
#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
*********************************************************************************************
* EXTERNAL DEFINES
*********************************************************************************************
*/

/*
*********************************************************************************************
* EXTERNAL TYPES DECLARATIONS
*********************************************************************************************
*/
typedef enum
{
    MX_I2C_BUS_SYSTEM,
    MX_I2C_BUS_SENSORS,
    MX_I2C_BUS_PAYLOAD,
    MX_I2C_BUS_COUNT
} mx_i2c_bus_t;

/*
*********************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
*********************************************************************************************
*/

/*
*********************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
*********************************************************************************************
*/
/** @brief Initialize all configured I2C buses
 *
 */
void mx_i2c_init(void);

/** @brief De-initialize all configured I2C buses
 *
 */
void mx_i2c_deinit(void);

/** @brief Deinitialize a specified I2C bus
 *
 *  @param[in] bus I2C bus ID
 */
void mx_i2c_bus_deinit(const mx_i2c_bus_t bus);

/** @brief Take ownership of an I2C bus until a call to @ref mx_i2c_release is performed.
 *
 *	@param[in] bus ID of the I2C bus to reserve
 *	@param[in] max_ticks_to_wait number of ticks to wait before failing with an error if the bus is already occupied
 *
 *	@return status of the operation
 */
HAL_StatusTypeDef mx_i2c_take(const mx_i2c_bus_t bus, const TickType_t max_ticks_to_wait);

/** @brief Release an I2C bus which was previously reserved by a call to @ref mx_i2c_take
 *
 *	@param[in] bus ID of the I2C bus to reserve
 */
void mx_i2c_release(const mx_i2c_bus_t bus);

/** @brief Perform a blocking transmit operation in Master mode targeting a specific I2C node
 *
 *  @param[in] bus ID of the I2C bus to use
 *  @param[in] dev_addr I2C node address
 *  @param[in] p_data pointer to the data packet to send
 *  @param[in] size size of the data pointed to by @ref p_data
 *
 *  @return status of the operation
 */
HAL_StatusTypeDef mx_i2c_block_tx(const mx_i2c_bus_t bus, const uint16_t dev_addr, uint8_t *const p_data, const uint16_t size);

/** @brief Perform a blocking read operation in Master mode from a specific I2C node
 *
 *  @param[in] bus ID of the I2C bus to use
 *  @param[in] dev_addr I2C node address
 *  @param[in] p_data pointer to the buffer where the received data shall be stored
 *  @param[in] size size of the buffer pointed to by @ref p_data
 *
 *  @return status of the operation
 */
HAL_StatusTypeDef mx_i2c_block_rx(const mx_i2c_bus_t bus, const uint16_t dev_addr, uint8_t *const p_data, const uint16_t size);

/** @brief Perform a blocking memory write operation targeting a specific I2C node memory address
 *
 *  @param[in] bus ID of the I2C bus to use
 *  @param[in] dev_addr I2C node address
 *  @param[in] mem_addr Memory address to write to
 *  @param[in] addr_sz Size of the address
 *  @param[in] p_data pointer to the data packet to send
 *  @param[in] size size of the data pointed to by @ref p_data
 *
 *  @return status of the operation
 */
HAL_StatusTypeDef mx_i2c_block_mem_write(const mx_i2c_bus_t bus, const uint16_t dev_addr, const uint16_t mem_addr, const uint16_t addr_sz, uint8_t *const p_data, const uint16_t size);

/** @brief Perform a blocking memory read operation from a specific I2C node memory address
 *
 *  @param[in] bus ID of the I2C bus to use
 *  @param[in] dev_addr I2C node address
 *  @param[in] mem_addr Memory address to read from
 *  @param[in] addr_sz Size of the address
 *  @param[in] p_data pointer to the data packet to send
 *  @param[in] size size of the data pointed to by @ref p_data
 *
 *  @return status of the operation
 */
HAL_StatusTypeDef mx_i2c_block_mem_read(const mx_i2c_bus_t bus, const uint16_t dev_addr, const uint16_t mem_addr, const uint16_t addr_sz, uint8_t *const pData, const uint16_t size);

#ifdef __cplusplus
}
#endif

#endif /* MX_I2C_H */
/* ******************************************************************************************* */
