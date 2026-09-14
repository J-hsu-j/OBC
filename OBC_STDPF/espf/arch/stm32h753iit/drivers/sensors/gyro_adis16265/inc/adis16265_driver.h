/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef __ADIS16265_DRIVER__H
#define __ADIS16265_DRIVER__H

/**
 * @addtogroup Drivers
 * @{
 *
 * @defgroup gyro_adis16265 Gyroscope adis16265
 * @{
 * Driver for the 1-axis gyroscope adis16265
 *
 * ## Initialization and deinitialization
 * The function **adis16265_init()** loads a configuration from non-volatile memory (@ref Nvm) based on the specified axis (@ref PanId_t).
 * The parameter list includes an additional parameter for optional startup-delay, which is needed if the gyroscope is powering up from a fully unpowered state.
 * The initialization procedure includes a verification check, which goes through the whole configuration in the @ref Nvm and makes sure that all axes have a gyroscope attached to them.
 * If the verification check fails to find a gyroscope configuration for every axis, it will trigger an early exit of the initialization procedure, causing a function failure.
 * Once the verification check has passed successfully, the function will continue with the full startup and configuration of the gyroscope that is attached to the specified axis (@ref PanId_t).
 *
 * The function **adis16265_deinit()** will deinitialize a gyroscope based on the specified axis (@ref PanId_t). The function will clear the enable flag, disabling all other functionalities
 * of the driver for the gyroscope that corresponds to the specified axis (@ref PanId_t). This will also force a new loading of configurations for this gyroscope from the @ref Nvm upon the next call to the **adis16265_init()** function.
 *
 * ## Data acquisition
 * The driver enables reading of angular positions, angular velocities and temperature data from all attached and initialized gyroscopes.
 * The function **adis16265_get_axes_angle()** reads angular positions from the gyroscope that is linked to the specified axis (@ref PANEL_GYROS_AXIS) and outputs them to a buffer. The specified gyroscope can be per axis or all of them,
 * depending on an input parameter. The output buffer is given as a parameter to the function. The angular positions are returned in unit of degrees. If an error is detected, the function will return an error code and modify the
 * status variable of the gyroscope that is linked to the specified axis (@ref PANEL_GYROS_AXIS).
 *
 * The function **adis16265_get_axes_rate()** reads angular velocities from the gyroscope that is linked to the specified axis (@ref PANEL_GYROS_AXIS) and outputs them to a buffer. The specified gyroscope can be per axis or all of them,
 * depending on an input parameter. The output buffer is given as a parameter to the function. The angular velocities are returned in unit of degrees/second. If an error is detected, the function will return an error code and modify the
 * status variable of the gyroscope that is linked to the specified axis (@ref PANEL_GYROS_AXIS).
 *
 * The function **adis16265_get_temperature()** reads temperature measurements from all initialized gyroscopes and outputs them to a buffer. The output buffer is given as a parameter to the function.
 * The temperature measurements are returned in unit of degrees Celsius. If an error is detected, the function will return an error code and modify the status variable of the
 * specific gyroscope.
 *
 * ## Status and configuration
 * The function **adis16265_get_status()** returns a struct with the latest status of all gyroscopes. The status is of the type @ref gyroscope_status_bundle_t.
 *
 * The function **adis16265_set_panel()** will link the specified satellite axis (@ref PanId_t) to the specified physical connector on the OBC (@ref Panel_Number_t).
 *
 * The function **adis16265_get_panel()** will return the physical connector on the OBC (@ref Panel_Number_t) that is linked to the specified satellite axis (@ref PanId_t).
 *
 * The function **adis16265_save_config_to_nvm()** will save the current gyroscope configurations to the non-volatile memory (@ref Nvm). This will overwrite the previous configurations stored in the @ref Nvm
 * and will result in the new configurations being automatically loaded during subsequent initialization procedures.
 *
 * The function **adis16265_load_config_from_nvm()** will load the gyroscope configurations currently stored in the non-volatile memory (@ref Nvm) and overwrite the active configurations that are in use
 * by the driver. This will automatically deinitialize all gyroscopes to prevent automatic startup.
 *
 * The function **adis16265_get_full_gyro_info()** will return the full context of the currently active gyroscope configurations.
 *
 * ## Register operations
 * The function **adis16265_write_reg16()** writes data to a 16-bit register based on the specific gyroscope (@ref gyroscope_t) using SPI communication.
 *
 * The function **adis16265_read_reg16()** reads data from a 16-bit register based on the specific gyroscope (@ref gyroscope_t) using SPI communication.
 *
 * ## Example of usage
 * @par 1. Initialize the gyroscope driver for a specific axis. Each gyroscope will need its own initialization call.
 * @code {.c}
 * PanId_t desired_axis = PAN_X_P; // Example for initializing the gyro on the X positive axis
 * bool is_init_time_req = true; // Assume initialization time is required
 * gyroscope_status_t init_status = adis16265_init(desired_axis, is_init_time_req);
 * if (init_status != GYRO_SUCCESS) {
 *     // Handle error
 * }
 * @endcode
 *
 * @par 2. Get angular position or angular rate.
 * Depending on the application's requirements, you might need just one axis' data or all of them.
 *
 * Get angular position for all axes
 * @code {.c}
 * AxesRaw_t axes_data;
 * gyroscope_status_t angle_status = adis16265_get_axes_angle(PANEL_GYROS_AXIS_ALL, &axes_data);
 * if (angle_status == GYRO_SUCCESS) {
 *     // Use axes_data.AXIS_X, axes_data.AXIS_Y, and axes_data.AXIS_Z
 * } else {
 *     // Handle error
 * }
 * @endcode
 * Get angular rate for a single axis. Suppose you're only interested in the Y axis.
 * @code {.c}
 * AxesRaw_t axis_rate;
 * gyroscope_status_t rate_status = adis16265_get_axes_rate(PANEL_GYROS_AXIS_Y, &axis_rate);
 * if (rate_status == GYRO_SUCCESS) {
 *     // Use axis_rate.AXIS_Y for angular velocity
 * } else {
 *     // Handle error
 * }
 * @endcode
 *
 * @par 3. Get temperature readings.
 * @code {.c}
 * Temperature_t gyro_temp;
 * gyroscope_status_t temp_status = adis16265_get_temperature(&gyro_temp);
 * if (temp_status == GYRO_SUCCESS) {
 *     // Use gyro_temp.Temp_X, gyro_temp.Temp_Y, and gyro_temp.Temp_Z
 * } else {
 *     // Handle error
 * }
 * @endcode
 *
 * @par 4. Update configuration or shutdown.
 * If you need to change the physical interface or panel attached to a gyroscope based on some condition or configuration update.
 * @code {.c}
 * Panel_Number_t new_panel = PANEL_5;
 * adis16265_set_panel(PAN_Y_P, new_panel);
 * @endcode
 * If you want to ensure that changes persist across system restarts, save the current configuration.
 * @code {.c}
 * adis16265_save_config_to_nvm();
 * @endcode
 * If power conservation is necessary or the gyroscope is not needed temporarily.
 * @code {.c}
 * adis16265_deinit(PAN_Z_M); // Example: disabling the Z-axis gyro
 * @endcode
 *
 * @par 5. Fetch Status or Diagnostics.
 * For health monitoring or debugging, you might need to fetch the current status of the gyroscopes.
 * @code {.c}
 * gyroscope_status_bundle_t gyro_status = adis16265_get_status();
 * // Inspect `gyro_status` for the general status of each axis
 * @endcode
 *
 * @file     adis16265_driver.h
 * @brief    adis16265 driver header file
 *
 * @}
 * @}
 *
 */

#include <stdint.h>
#include <stdbool.h>
#include "panels.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
#define ADIS16265_FLASH_CNT            0x00  /* Flash memory write count */
#define ADIS16265_SUPPLY_OUT           0x02  /* Power supply measurement */
#define ADIS16265_GYRO_OUT             0x04  /* X-axis gyroscope output */
#define ADIS16265_AUX_ADC              0x0A  /* Analog input channel measurement */
#define ADIS16265_TEMP_OUT             0x0C  /* Internal temperature measurement */
#define ADIS16265_ANGL_OUT             0x0E  /* Angle displacement */
#define ADIS16265_GYRO_OFF             0x14  /* Calibration, offset/bias adjustment */
#define ADIS16265_GYRO_SCALE           0x16  /* Calibration, scale adjustment */
#define ADIS16265_ALM_MAG1             0x20  /* Alarm 1 magnitude/polarity setting */
#define ADIS16265_ALM_MAG2             0x22  /* Alarm 2 magnitude/polarity setting */
#define ADIS16265_ALM_SMPL1            0x24  /* Alarm 1 dynamic rate of change setting */
#define ADIS16265_ALM_SMPL2            0x26  /* Alarm 2 dynamic rate of change setting */
#define ADIS16265_ALM_CTRL             0x28  /* Alarm control */
#define ADIS16265_AUX_DAC              0x30  /* Auxiliary DAC data */
#define ADIS16265_GPIO_CTRL            0x32  /* Control, digital I/O line */
#define ADIS16265_MSC_CTRL             0x34  /* Control, data ready, self-test settings */
#define ADIS16265_SMPL_PRD             0x36  /* Control, internal sample rate */
#define ADIS16265_SENS_AVG             0x38  /* Control, dynamic range, filtering */
#define ADIS16265_SLP_CNT              0x3A  /* Control, sleep mode initiation */
#define ADIS16265_DIAG_STAT            0x3C  /* Diagnostic, error flags */
#define ADIS16265_GLOB_CMD             0x3E  /* Control, global commands */
#define ADIS16265_LOT_ID1              0x52  /* Lot Identification Code 1 */
#define ADIS16265_LOT_ID2              0x54  /* Lot Identification Code 2 */
#define ADIS16265_PROD_ID              0x56  /* Product identifier; should return 0x3F89 or 0x3F84 => converts to decimal = 16,265/16,260 */
#define ADIS16265_SERIAL_NUM           0x58  /* Serial number */
#define ADIS16265_PROD_NUM             16265 /* Expected Product Number */
#define ADIS16265_GYRO_OUT_POS_MAX_VAL ((int16_t)0x1110)
#define ADIS16265_GYRO_OUT_NEG_MAX_VAL ((int16_t)0x2EF0)
#define ADIS16265_GYRO_OUT_NEG_MIN_VAL ((int16_t)0x4000)
#define ADIS16265_GYRO_OUT_14BIT_MASK  ((int16_t)0x3FFF)
#define ADIS16265_ERROR_ACTIVE         (1 << 14)
#define ADIS16265_NEW_DATA             (1 << 15)
#define ADIS16265_MSC_CTRL_MEM_TEST    (1 << 11)
/* Internal self-test enable */
#define ADIS16265_MSC_CTRL_INT_SELF_TEST     (1 << 10)
#define ADIS16265_MSC_CTRL_NEG_SELF_TEST     (1 << 9)
#define ADIS16265_MSC_CTRL_POS_SELF_TEST     (1 << 8)
#define ADIS16265_MSC_CTRL_DATA_RDY_EN       (1 << 2)
#define ADIS16265_MSC_CTRL_DATA_RDY_POL_HIGH (1 << 1)
#define ADIS16265_MSC_CTRL_DATA_RDY_DIO2     (1 << 0)
/* SMPL_PRD */
/* Time base (tB): 0 = 1.953 ms, 1 = 60.54 ms */
#define ADIS16265_SMPL_PRD_TIME_BASE (1 << 7)
#define ADIS16265_SMPL_PRD_DIV_MASK  0x7F
/* SLP_CNT */
#define ADIS16265_SLP_CNT_POWER_OFF 0x80
/* DIAG_STAT */
#define ADIS16265_DIAG_STAT_ALARM2         (1 << 9)
#define ADIS16265_DIAG_STAT_ALARM1         (1 << 8)
#define ADIS16265_DIAG_STAT_FLASH_CHK_BIT  6
#define ADIS16265_DIAG_STAT_SELF_TEST_BIT  5
#define ADIS16265_DIAG_STAT_OVERFLOW_BIT   4
#define ADIS16265_DIAG_STAT_SPI_FAIL_BIT   3
#define ADIS16265_DIAG_STAT_FLASH_UPT_BIT  2
#define ADIS16265_DIAG_STAT_POWER_HIGH_BIT 1
#define ADIS16265_DIAG_STAT_POWER_LOW_BIT  0
/* GLOB_CMD */
#define ADIS16265_GLOB_CMD_SW_RESET      (1 << 7)
#define ADIS16265_GLOB_CMD_FLASH_UPD     (1 << 3)
#define ADIS16265_GLOB_CMD_DAC_LATCH     (1 << 2)
#define ADIS16265_GLOB_CMD_FAC_CALIB     (1 << 1)
#define ADIS16265_GLOB_CMD_AUTO_NULL     (1 << 0)
#define ADIS16265_ID                     ((uint16_t)16265)  /* ID of the gyroscope. This should match the value read from register ADIS16265_PROD_ID */
#define ADIS16265_SLEEP_ON               ((uint8_t)0xF0)    /* ~120 seconds sleep mode duration */
#define ADIS16265_SLEEP_OFF              ((uint8_t)0x00)    /* Exit sleep mode */
#define ADIS16265_CONFIG                 ((uint16_t)0x0104) /* Gyro configuration -> 80 deg/s range; 16 filter taps; 50Hz bandwidth */
#define ADIS16265_CONFIG_SAVE            ((uint16_t)0x08)   /* Save gyro configuration to flash  */
#define ADIS16265_GYRO_OFFSET            ((uint16_t)0x0D)   /* Gyro calibration offset */
#define ADIS16265_TEMP_12BIT_MASK        ((int32_t)0xFFF)   /* Mask for retrieving only 12 bits of the returned register value */
#define ADIS16265_TEMP_ZERO_READ         ((int32_t)0x000)   /* Ambient temperature reading of the gyroscope register */
#define ADIS16265_TEMP_FRAC              ((int32_t)0x5AD)   /* Fractional temperature as defined in the datasheet - 0.1453, but scaled by 1e4 */
#define ADIS16265_TEMP_DIV               ((int32_t)0x3E8)   /* Divide value to get the final temperature value in the format 245, meaning 24.5 degC*/
#define ADIS16265_TEMP_25                ((int32_t)0x3D090) /* Value corresponding to 25 degrees scaled by 1e4 */
#define ADIS16265_TEMP_MINUS_40          ((int32_t)0xE41)   /* Register value corresponding to -40 degrees  */
#define ADIS16265_INVALID_VALUE          ((int32_t)0x7FFF)  /* Invalid value  */
#define ADIS16265_CHIP_SELECT_ON         0x00
#define ADIS16265_CHIP_SELECT_OFF        0x60
#define ADIS16265_MAX_ATTEMPTS           3
#define ADIS16265_DISABLED               0
#define ADIS16265_ENABLED                1
#define ADIS16265_AXIS_NOT_FOUND_IN_INIT 0
#define ADIS16265_REPEATING_AXIS_IN_INIT 2

/** @brief According to datasheet, page 13, table 11, one LSB is equal to 0.03663 deg/s */
/* To avoid using floating numbers, we use integer scaling */
#define ADIS16265_BITS_TO_SCALED_DEG 3663   /* Converts to hundreds of thousands of deg/s */
#define ADIS16265_SCALED_DEG_TO_DEG  100000 /* Converts hundreds of thousands of deg/s to deg/s */

/** @brief A minimum delay of 12us is required as per datasheet, page 5 */
#define ADIS16265_STALL_DELAY_MINIMUM_S (double)0.000012

/** @brief Boolean used to indicate that the gyro initialisation must include the obligatory 200 ms wait time */
#define ADIS16265_INIT_TIME_REQ (true)
/** @brief Boolean used to indicate that the gyro initialisation does not require the 200 ms wait time */
#define ADIS16265_INIT_TIME_NREQ (false)

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/
/** @brief Gyroscope number */
typedef enum
{
    GYROSCOPE_1 = 1,
    GYROSCOPE_2,
    GYROSCOPE_3,
    GYROSCOPE_COUNT
} gyroscope_number_t;

/** @brief Gyroscope error codes */
typedef enum
{
    GYRO_SUCCESS,                    /**< Gyroscope operation passed successfully */
    GYRO_NOT_INIT,                   /**< Gyroscope has not been initialized */
    GYRO_INIT_X_NOT_FOUND,           /**< Gyroscope X axis was not found in NVM during initialization */
    GYRO_INIT_Y_NOT_FOUND,           /**< Gyroscope Y axis was not found in NVM during initialization */
    GYRO_INIT_Z_NOT_FOUND,           /**< Gyroscope Z axis was not found in NVM during initialization */
    GYRO_INIT_AXIS_NOT_FOUND_IN_NVM, /**< Desired gyroscope axis was not found in NVM configurations */
    GYRO_COMM_READ_FAIL,             /**< Reading from gyroscope registers failed */
    GYRO_COMM_WRITE_FAIL,            /**< Writing to gyroscope registers failed */
    GYRO_COMM_SPI_R_FAIL,            /**< SPI read from gyroscope failed */
    GYRO_COMM_SPI_W_FAIL,            /**< SPI write to gyroscope failed */
    GYRO_PROD_ID_ERROR,              /**< Incorrect product id of gyroscope */
    GYRO_MEASURE_OUT_OF_RANGE,       /**< Gyroscope measurement was out of expected range */
    GYRO_ATTEMPTS_EXPIRED,           /**< Gyroscope has failed to provide data within the defined attempt limit */
    GYRO_DISABLED,                   /**< Gyroscope is disabled (enabled_flag is 0) */
    GYRO_DISCONNECTED,               /**< Gyroscope has been disconnected (enabled_flag is 1, but invalid reading) */
    GYRO_ERROR                       /**< Gyroscope general error, returned when reading operation failed on all gyroscopes */
} gyroscope_status_t;

/** @brief Gyroscope status struct for compact output to FP commands */
typedef struct
{
    gyroscope_status_t gyroscope_x_status; /**< Gyroscope X status variable */
    gyroscope_status_t gyroscope_y_status; /**< Gyroscope Y status variable */
    gyroscope_status_t gyroscope_z_status; /**< Gyroscope Z status variable */
} gyroscope_status_bundle_t;

/** @brief The basic gyroscope struct */
typedef struct
{
    gyroscope_number_t gyro_id;        /**< Gyroscope number */
    gyroscope_status_t general_status; /**< Gyroscope status */
    Panel_Number_t     attached_panel; /**< Physical panel that this gyroscope is attached to */
    PanId_t            satellite_axis; /**< Software defined coordinate frame axis that this gyroscope is connected to */
    uint8_t            enabled_flag;   /**< Flag that determines whether the gyroscope is enabled (used) or disabled (unused) */
} gyroscope_t;

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
/** @brief Initialization routine for gyroscopes
 *  @param[in] PanId_t            satellite_axis   - the desired axis to be initialized
 *  @param[in] bool               is_init_time_req - boolean flag that determines if the initial startup time delay is needed
 *  @return    gyroscope_status_t                  - status of the initialization routine */
gyroscope_status_t adis16265_init(PanId_t satellite_axis, bool is_init_time_req);

/** @brief Deinitialization routine for gyroscopes
 *  @param[in] PanId_t satellite_axis - the desired axis to be deinitialized */
void adis16265_deinit(PanId_t satellite_axis);

/** @brief Reads angles (angular position) from a given gyroscope axis (or all)
 *  @param[in]  PANEL_GYROS_AXIS           axis   - the desired axis to be read; can read all axes in one call
 *  @param[out] AxesRaw_t          * const p_buff - pointer to struct for storing the read values
 *  @return     gyroscope_status_t                - status of the angle reading routine */
gyroscope_status_t adis16265_get_axes_angle(PANEL_GYROS_AXIS axis, AxesRaw_t *const p_buff);

/** @brief Reads rates (angular velocities) from a given gyroscope axis (or all)
 *  @param[in]  PANEL_GYROS_AXIS           axis   - the desired axis to be read; can read all axes in one call
 *  @param[out] AxesRaw_t          * const p_buff - pointer to struct for storing the read values
 *  @return     gyroscope_status_t                - status of the rates reading routine */
gyroscope_status_t adis16265_get_axes_rate(PANEL_GYROS_AXIS axis, AxesRaw_t *const p_buff);

/** @brief Reads temperature from all enabled gyroscopes
 *  @param[out] Temperature_t      * const p_tmp - pointer to struct for storing the read values
 *  @return     gyroscope_status_t               - status of the temperature reading routine */
gyroscope_status_t adis16265_get_temperature(Temperature_t *const p_tmp);

/** @brief Writes to a 16 bit register on adis16265 gyroscope
 *  @param[in] gyroscope_t        * const p_gyroscope - pointer to struct with gyroscope data
 *  @param[in] uint8_t                    address     - register address to write to
 *  @param[in] uint16_t                   data        - data to be written to the register
 *  @return    gyroscope_status_t                     - status of the register write routine */
gyroscope_status_t adis16265_write_reg16(gyroscope_t *const p_gyroscope, uint8_t address, uint16_t data);

/** @brief Reads from a 16 bit register on adis16265 gyroscope
 *  @param[in]  gyroscope_t        * const p_gyroscope - pointer to struct with gyroscope data
 *  @param[in]  uint8_t                    address     - register address to read
 *  @param[out] uint16_t           * const p_data      - pointer to variable that will hold the read data
 *  @return     gyroscope_status_t                     - status of the register write routine */
gyroscope_status_t adis16265_read_reg16(gyroscope_t *const p_gyroscope, uint8_t address, uint16_t *const p_data);

/** @brief Return the status of all gyroscopes
 *  @return gyroscope_status_bundle_t - struct with status codes of all gyroscopes */
gyroscope_status_bundle_t adis16265_get_status(void);

/** @brief Set the attached panel for a given satellite axis
 *  @param[in] PanId_t        satellite_axis - satellite axis to be changed
 *  @param[in] Panel_Number_t attached_panel - the new panel for the given satellite axis */
void adis16265_set_panel(PanId_t satellite_axis, Panel_Number_t attached_panel);

/** @brief Get the attached panel for a given satellite axis
 *  @param[in] PanId_t        satellite_axis - satellite axis
 *  @return    Panel_Number_t                - the panel id that is attached to the given axis */
Panel_Number_t adis16265_get_panel(PanId_t satellite_axis);

/** @brief Save the current gyroscope configurations to NVM */
void adis16265_save_config_to_nvm(void);

/** @brief Load the current gyroscope configurations from NVM */
void adis16265_load_config_from_nvm(void);

/** @brief Get the full gyroscope configuration/information for all axis
 *  @param[out] gyroscope_t * const p_gyro_x - pointer to storage location for the read gyroscope axis configuration
 *	@param[out] gyroscope_t * const p_gyro_y - pointer to storage location for the read gyroscope axis configuration
 *	@param[out] gyroscope_t * const p_gyro_z - pointer to storage location for the read gyroscope axis configuration */
void adis16265_get_full_gyro_info(gyroscope_t *const p_gyro_x, gyroscope_t *const p_gyro_y, gyroscope_t *const p_gyro_z);

#ifdef __cplusplus
}
#endif

#endif /*__ADIS16265_DRIVER__H */
