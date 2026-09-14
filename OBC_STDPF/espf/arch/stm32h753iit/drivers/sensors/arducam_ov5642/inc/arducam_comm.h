/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef ARDUCAM_COMM_H
#define ARDUCAM_COMM_H
/**
 * @addtogroup Drivers
 * @{
 *
 * @defgroup arducam ArduCam OV5642
 * @{
 *
 * Communication drivers for the sensor OV5642 built in the Arducam 5MP Plus.
 * The SPI peripheral initialization and command is done in this drivers but it relies
 * in the I2C implementation from the OBC SDK for the I2C commands to the OV5642 sensor.
 *
 * @file arducam_comm.h
 *
 * @brief Public interface of the ArduCam OV5642 drivers
 *
 * @}
 * @}
 */

#include "User_types.h"
#include <stdint.h>

/*
*********************************************************************************************
* EXTERNAL DEFINES
*********************************************************************************************
*/

#define AC_INTER_SPI_OP_DELAY_MS 20   // Delay between two consecutive SPI operations.
#define AC_INTER_I2C_OP_DELAY_MS 1    // This should be 500 micro seconds (we lack better resolution)
#define AC_SENSOR_OP_DELAY_MS    50   // After changing big chunks of settings, OV5642 sensor needs time.
#define AC_SETTINGS_DELAY_MS     1000 // Delay after setting up the OV5642 sensor
#define AC_START_UP_DELAY        300  // Delay after start up
#define AC_SHUT_DOWN_DELAY       100  // Delay between sending shutdown signal and camera power off

// Enable camera pin
#define EN_CAM_Pin       GPIO_PIN_9
#define EN_CAM_GPIO_Port GPIOH

// SPI5 Init definitions
#define SPI5_SCK_Pin          GPIO_PIN_7
#define SPI5_SCK_GPIO_Port    GPIOF
#define SPI5_MISO_Pin         GPIO_PIN_8
#define SPI5_MISO_GPIO_Port   GPIOF
#define SPI5_MOSI_Pin         GPIO_PIN_9
#define SPI5_MOSI_GPIO_Port   GPIOF
#define SPI5_IRQ_Pin          GPIO_PIN_10
#define SPI5_IRQ_GPIO_Port    GPIOF
#define ARDU_CAM_CS_Pin       GPIO_PIN_6
#define ARDU_CAM_CS_GPIO_Port GPIOF
// End of SPI5 Init definitions

#define ARDUCAM_CS_HIGH HAL_GPIO_WritePin(ARDU_CAM_CS_GPIO_Port, ARDU_CAM_CS_Pin, GPIO_PIN_SET)
#define ARDUCAM_CS_LOW  HAL_GPIO_WritePin(ARDU_CAM_CS_GPIO_Port, ARDU_CAM_CS_Pin, GPIO_PIN_RESET)

/****************************************************/
/* Sensor related definition 						*/
/****************************************************/
#define ARDUCAM_ADDR (0x3C << 1)
/****************************************************/

/*
*********************************************************************************************
* EXTERNAL TYPES DECLARATIONS
*********************************************************************************************
*/
struct sensor_reg
{
    uint16_t reg;
    uint8_t  val;
};

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
/**
 * @brief Read an address over the i2c from the OV5642
 * @param addr Address in the sensor
 *
 * @return Value of the address
 */
uint8_t arducam_comm_read_ov5642(uint16_t addr);

/**
 * @brief Write an address over the i2c in the OV5642
 * @param addr Address in the sensor
 * @param val Value to be set at the address given
 *
 * @retval true successfully write the register value
 * @retval false failed to write with the HAL I2C
 */
bool arducam_comm_write_ov5642(uint16_t addr, uint8_t val);

/**
 * @brief Write a list of registers with its values in the OV5642
 * @param reglist An array of address and value pairs
 *
 * @retval true successfully write all the register values
 * @retval false at least one register failed to be written
 */
bool arducam_comm_write_regs_ov5642(const struct sensor_reg reglist[]);

/**
 * @brief Read the value of an address in the arducam with the SPI
 * @param addr Address whose value we want to read
 *
 * @return The value read from the Arducam
 */
uint8_t arducam_comm_read_addr_spi(uint8_t addr);

/**
 * @brief Set the Arducam chip in burst read mode.
 */
void arducam_set_fifo_burst(void);

/**
 * @brief Read a chunk of bytes from the Arducam FIFO queue.
 * @param buff pointer to the buffer to contain the data read.
 * @param sizes size of the buffer
 */
void arducam_comm_read_burst_spi(uint8_t *buff, uint16_t size);

/**
 * @brief Write the value of an address in the arducam chip via SPI
 * @param addr addres to be writen
 * @param data value to update the address with
 */
void arducam_write_addr_spi(uint8_t addr, uint8_t data);

/**
 * @brief Initialize the GPO that enables the arducam chip
 */
void arducam_pin_enable_init(void);

/**
 * @brief Disable the GPO that enables the arducam chip
 */
void arducam_pin_enable_deinit(void);

/**
 * @brief Initialize the SPI5 peripheral for the Arducam chip communication.
 */
void arducam_spi5_init(void);

/**
 * @brief Disable the SPI5 peripheral for the Arducam chip communication.
 */
void arducam_spi5_deinit(void);

#endif /* ARDUCAM_COMM_H */
