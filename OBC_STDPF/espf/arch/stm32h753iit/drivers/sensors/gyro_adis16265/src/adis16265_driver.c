/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup gyro_adis16265
 * @{
 *
 * @file     adis16265_driver.c
 * @brief    adis16265 driver file
 *
 * @}
 *
 */

#include "adis16265_driver.h"

#include <string.h>
#include <sys/_stdint.h>

#include "main.h"
#include "MCU_Init.h"
#include "nvm_app_block_ids.h"
#include "nvm_app_types.h"
#include "User_types.h"
#include "assertions.h"
#include "nvm.h"
#include "stm32h7xx_hal_def.h"
#include "stm32h7xx_hal_rcc.h"
#include "stm32h7xx_hal_spi.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
/* No Internal defines */

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/
/* No Internal types definitions */

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/
/* No External variables definitions */

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
/** @brief File static variables that hold active gyroscope information */
static gyroscope_t gyroscope_x;
static gyroscope_t gyroscope_y;
static gyroscope_t gyroscope_z;

/** @brief Bundle that holds the status of all gyroscopes; To be used when reading evaluating errors from SDS or through FP commands */
static gyroscope_status_bundle_t gyroscope_status;

/** @brief The loaded nvm configuration upon initialization */
static gyroscope_configs_t loaded_nvm_config;

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
/** @brief Reads the angles (angular position) from a single gyroscope axis
 *  @param[in]  gyroscope_t * const p_gyroscope - pointer to struct with selected gyroscope data
 *  @param[out] int16_t     * const p_gyro_data - pointer to variable for storing read data */
static void fs_adis16265_read_single_axis_angle(gyroscope_t *const p_gyroscope, int16_t *const p_gyro_data);

/** @brief Reads the rates (angular velocity) from a single gyroscope axis
 *  @param[in]  gyroscope_t * const p_gyroscope - pointer to struct with selected gyroscope data
 *  @param[out] int16_t     * const p_gyro_data - pointer to variable for storing read data */
static void fs_adis16265_read_single_axis_rate(gyroscope_t *const p_gyroscope, int16_t *const p_gyro_data);

/** @brief Reads the temperature from a single gyroscope
 *  @param[in]  gyroscope_t * const p_gyroscope - pointer to struct with selected gyroscope data
 *  @param[out] int16_t     * const p_gyro_data - pointer to variable for storing read data */
static void fs_adis16265_read_single_axis_temp(gyroscope_t *const p_gyroscope, int16_t *const p_gyro_data);

/** @brief Calculates the necessary empty processor loops in order to provide a minimum of 12usec delay
 *  @note See adis16265 gyroscope datasheet for more information */
static void fs_adis16265_stall_delay(void);

/** @brief SPI Chip select function to enable/disable proper PANEL pin according to given gyroscope struct
 *  @param[in]  const gyroscope_t * const p_gyroscope - pointer to struct with selected gyroscope data
 *  @param[out]       uint8_t             mode        - possible values are ADIS16265_CHIP_SELECT_ON or ADIS16265_CHIP_SELECT_OFF */
static void fs_adis16265_chip_select(const gyroscope_t *const p_gyroscope, uint8_t mode);

/** @brief Returns the panel id which corresponds to a given satellite axis
 *  @param[in]  const gyroscope_configs_t * const p_gyroscope_configs - pointer to struct with all NVM gyroscope configurations
 *  @param[out]       PanId_t                     satellite_axis      - the satellite axis configuration which is to be found
 *  @return           uint8_t                                         - the panel id that is connected to the given axis */
static uint8_t fs_adis16265_find_gyro_based_on_axis(const gyroscope_configs_t *const p_gyroscope_configs, PanId_t satellite_axis);

/** @brief Transfers the given configuration parameters to the local gyroscope parameters based on axis
 *  @param[in] const gyroscope_t * const p_gyroscope - pointer to struct with a gyroscope configuration */
static void fs_adis16265_save_gyro_config_change(const gyroscope_t *const p_gyroscope);

/** @brief Updates the gyroscope status bundle by extracting data from local variables for each gyroscope */
static void fs_adis16265_update_gyro_status_bundle(void);

/** @brief Stops a gyroscope by disabling the enabled_flag in the corresponding data struct based on axis
 *  @param[in] PanId_t satellite_axis - desired axis to be stopped */
static void fs_adis16265_disable_gyro_based_on_axis(PanId_t satellite_axis);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
gyroscope_status_t adis16265_init(PanId_t satellite_axis, bool is_init_time_req)
{
    /* These variables hold the index of the panel that has a gyroscope connected */
    uint8_t gyro_config_index_positive = 0;
    uint8_t gyro_config_index_negative = 0;

    /* This variable holds the index of the panel that has to be initialized */
    uint8_t gyro_config_to_init_index = 0;

    gyroscope_t gyroscope_to_init;
    uint16_t    gyro_product_num = 0;

    /* This delay compensates for gyroscope initial start-up time, 165ms as per datasheet, page 4 */
    /* This can be significantly reduced if the gyroscopes are never shut off, but instead put into sleep mode - TBD */
    if (ADIS16265_INIT_TIME_REQ == is_init_time_req)
    {
        sysDelay(200);
    }

    /* Fetch base gyroscope configurations from nvm */
    Nvm_GetBlockById(NVM_BLOCK_GYROSCOPE_CONFIG, &loaded_nvm_config);

    /* If X axis gyroscope has not been initialized */
    if (ADIS16265_DISABLED == gyroscope_x.enabled_flag)
    {
        /* Find which one is for gyroscope on axis X */
        gyro_config_index_positive = fs_adis16265_find_gyro_based_on_axis(&loaded_nvm_config, PAN_X_P);
        gyro_config_index_negative = fs_adis16265_find_gyro_based_on_axis(&loaded_nvm_config, PAN_X_M);

        /* If the index positive did not return MAX_PAN, that means the positive axis was found in the configurations */
        if (gyro_config_index_positive < MAX_PAN)
        {
            gyroscope_x = loaded_nvm_config.gyroscope_array[gyro_config_index_positive];
        }
        /* If the index negative did not return MAX_PAN, that means the negative axis was found in the configurations */
        else if (gyro_config_index_negative < MAX_PAN)
        {
            gyroscope_x = loaded_nvm_config.gyroscope_array[gyro_config_index_negative];
        }
        /* If both axis directions were not found, that means the axis wasn't in the configurations - error */
        else
        {
            gyroscope_x.general_status = GYRO_INIT_X_NOT_FOUND;
            return GYRO_INIT_X_NOT_FOUND;
        }
    }

    /* If Y axis gyroscope has not been initialized */
    if (ADIS16265_DISABLED == gyroscope_y.enabled_flag)
    {
        /* Find which one is for gyroscope on axis Y */
        gyro_config_index_positive = fs_adis16265_find_gyro_based_on_axis(&loaded_nvm_config, PAN_Y_P);
        gyro_config_index_negative = fs_adis16265_find_gyro_based_on_axis(&loaded_nvm_config, PAN_Y_M);

        /* If the index positive did not return MAX_PAN, that means the positive axis was found in the configurations */
        if (gyro_config_index_positive < MAX_PAN)
        {
            gyroscope_y = loaded_nvm_config.gyroscope_array[gyro_config_index_positive];
        }
        /* If the index negative did not return MAX_PAN, that means the negative axis was found in the configurations */
        else if (gyro_config_index_negative < MAX_PAN)
        {
            gyroscope_y = loaded_nvm_config.gyroscope_array[gyro_config_index_negative];
        }
        /* If both axis directions were not found, that means the axis wasn't in the configurations - error */
        else
        {
            gyroscope_y.general_status = GYRO_INIT_Y_NOT_FOUND;
            return GYRO_INIT_Y_NOT_FOUND;
        }
    }

    /* If Z axis gyroscope has not been initialized */
    if (ADIS16265_DISABLED == gyroscope_z.enabled_flag)
    {
        /* Find which one is for gyroscope on axis Z */
        gyro_config_index_positive = fs_adis16265_find_gyro_based_on_axis(&loaded_nvm_config, PAN_Z_P);
        gyro_config_index_negative = fs_adis16265_find_gyro_based_on_axis(&loaded_nvm_config, PAN_Z_M);

        /* If the index positive did not return MAX_PAN, that means the positive axis was found in the configurations */
        if (gyro_config_index_positive < MAX_PAN)
        {
            gyroscope_z = loaded_nvm_config.gyroscope_array[gyro_config_index_positive];
        }
        /* If the index negative did not return MAX_PAN, that means the negative axis was found in the configurations */
        else if (gyro_config_index_negative < MAX_PAN)
        {
            gyroscope_z = loaded_nvm_config.gyroscope_array[gyro_config_index_negative];
        }
        /* If both axis directions were not found, that means the axis wasn't in the configurations - error */
        else
        {
            gyroscope_z.general_status = GYRO_INIT_Z_NOT_FOUND;
            return GYRO_INIT_Z_NOT_FOUND;
        }
    }

    /* Find the configuration which has desired axis */
    gyro_config_to_init_index = fs_adis16265_find_gyro_based_on_axis(&loaded_nvm_config, satellite_axis);
    if (gyro_config_to_init_index < MAX_PAN)
    {
        gyroscope_to_init = loaded_nvm_config.gyroscope_array[gyro_config_to_init_index];
    }
    else
    {
        return GYRO_INIT_AXIS_NOT_FOUND_IN_NVM;
    }

    /* Init sequence for the desired singular gyroscope */
    if (GYRO_SUCCESS != adis16265_read_reg16(&gyroscope_to_init, ADIS16265_PROD_ID, &gyro_product_num))
    {
        return GYRO_COMM_READ_FAIL;
    }

    if (ADIS16265_PROD_NUM != gyro_product_num)
    {
        return GYRO_PROD_ID_ERROR;
    }

    /* Change initial gyroscope sampling and filtering configurations */
    if (GYRO_SUCCESS != adis16265_write_reg16(&gyroscope_to_init, ADIS16265_SENS_AVG, ADIS16265_CONFIG))
    {
        return GYRO_COMM_WRITE_FAIL;
    }

    /* Enable the gyroscope as it is initialized */
    gyroscope_to_init.enabled_flag = ADIS16265_ENABLED;

    fs_adis16265_save_gyro_config_change(&gyroscope_to_init);

    return GYRO_SUCCESS;
}

void adis16265_deinit(PanId_t satellite_axis)
{
    /* Disable the correct gyroscope based on the axis */
    fs_adis16265_disable_gyro_based_on_axis(satellite_axis);
}

gyroscope_status_t adis16265_get_axes_angle(PANEL_GYROS_AXIS axis, AxesRaw_t *const p_buff)
{
    CRIT_ASSERT(NULL != p_buff);

    /* Invalidate the data */
    p_buff->AXIS_X = p_buff->AXIS_Y = p_buff->AXIS_Z = ADIS16265_INVALID_VALUE;

    /* Axis X */
    if ((PANEL_GYROS_AXIS_ALL == axis) || (PANEL_GYROS_AXIS_X == axis))
    {
        /* Check if the gyroscope is enabled */
        if (ADIS16265_ENABLED == gyroscope_x.enabled_flag)
        {
            /* Read data from X axis gyroscope */
            fs_adis16265_read_single_axis_angle(&gyroscope_x, &p_buff->AXIS_X);
        }
        else
        {
            /* Gyroscope is not enabled */
            gyroscope_x.general_status = GYRO_DISABLED;
        }
    }

    /* Axis Y */
    if ((PANEL_GYROS_AXIS_ALL == axis) || (PANEL_GYROS_AXIS_Y == axis))
    {
        /* Check if the gyroscope is enabled */
        if (ADIS16265_ENABLED == gyroscope_y.enabled_flag)
        {
            /* Read data from Y axis gyroscope */
            fs_adis16265_read_single_axis_angle(&gyroscope_y, &p_buff->AXIS_Y);
        }
        else
        {
            /* Gyroscope is not enabled */
            gyroscope_y.general_status = GYRO_DISABLED;
        }
    }

    /* Axis Z */
    if ((PANEL_GYROS_AXIS_ALL == axis) || (PANEL_GYROS_AXIS_Z == axis))
    {
        /* Check if the gyroscope is enabled */
        if (ADIS16265_ENABLED == gyroscope_z.enabled_flag)
        {
            /* Read data from Z axis gyroscope */
            fs_adis16265_read_single_axis_angle(&gyroscope_z, &p_buff->AXIS_Z);
        }
        else
        {
            /* Gyroscope is not enabled */
            gyroscope_z.general_status = GYRO_DISABLED;
        }
    }

    /* Update any changes to gyroscopes' status */
    fs_adis16265_update_gyro_status_bundle();

    /* If all gyroscopes have failed to read any data */
    if ((GYRO_SUCCESS != gyroscope_x.general_status) &&
        (GYRO_SUCCESS != gyroscope_y.general_status) &&
        (GYRO_SUCCESS != gyroscope_z.general_status))
    {
        /* Signal a complete gyroscope failure */
        return GYRO_ERROR;
    }
    else
    {
        /* Partial or full gyroscope read was completed */
        return GYRO_SUCCESS;
    }
}

gyroscope_status_t adis16265_get_axes_rate(PANEL_GYROS_AXIS axis, AxesRaw_t *const p_buff)
{
    CRIT_ASSERT(NULL != p_buff);

    /* Invalidate the data */
    p_buff->AXIS_X = p_buff->AXIS_Y = p_buff->AXIS_Z = ADIS16265_INVALID_VALUE;

    /* Axis X */
    if ((PANEL_GYROS_AXIS_ALL == axis) || (PANEL_GYROS_AXIS_X == axis))
    {
        /* Check if the gyroscope is enabled */
        if (ADIS16265_ENABLED == gyroscope_x.enabled_flag)
        {
            /* Read data from X axis gyroscope */
            fs_adis16265_read_single_axis_rate(&gyroscope_x, &p_buff->AXIS_X);
        }
        else
        {
            /* Gyroscope is not enabled */
            gyroscope_x.general_status = GYRO_DISABLED;
        }
    }

    /* Axis Y */
    if ((PANEL_GYROS_AXIS_ALL == axis) || (PANEL_GYROS_AXIS_Y == axis))
    {
        /* Check if the gyroscope is enabled */
        if (ADIS16265_ENABLED == gyroscope_y.enabled_flag)
        {
            /* Read data from Y axis gyroscope */
            fs_adis16265_read_single_axis_rate(&gyroscope_y, &p_buff->AXIS_Y);
        }
        else
        {
            /* Gyroscope is not enabled */
            gyroscope_y.general_status = GYRO_DISABLED;
        }
    }

    /* Axis Z */
    if ((PANEL_GYROS_AXIS_ALL == axis) || (PANEL_GYROS_AXIS_Z == axis))
    {
        /* Check if the gyroscope is enabled */
        if (ADIS16265_ENABLED == gyroscope_z.enabled_flag)
        {
            /* Read data from Z axis gyroscope */
            fs_adis16265_read_single_axis_rate(&gyroscope_z, &p_buff->AXIS_Z);
        }
        else
        {
            /* Gyroscope is not enabled */
            gyroscope_z.general_status = GYRO_DISABLED;
        }
    }

    /* Update any changes to gyroscopes' status */
    fs_adis16265_update_gyro_status_bundle();

    /* If all gyroscopes have failed to read any data */
    if ((GYRO_SUCCESS != gyroscope_x.general_status) &&
        (GYRO_SUCCESS != gyroscope_y.general_status) &&
        (GYRO_SUCCESS != gyroscope_z.general_status))
    {
        /* Signal a complete gyroscope failure */
        return GYRO_ERROR;
    }
    else
    {
        /* Partial or full gyroscope read was completed */
        return GYRO_SUCCESS;
    }
}

gyroscope_status_t adis16265_get_temperature(Temperature_t *const p_tmp)
{
    CRIT_ASSERT(NULL != p_tmp);

    /* Invalidate the data */
    p_tmp->Temp_X = p_tmp->Temp_Y = p_tmp->Temp_Z = ADIS16265_INVALID_VALUE;

    /* Axis X */
    /* Check if the gyroscope is enabled */
    if (ADIS16265_ENABLED == gyroscope_x.enabled_flag)
    {
        /* Read temperature data from X axis gyroscope */
        fs_adis16265_read_single_axis_temp(&gyroscope_x, &p_tmp->Temp_X);
    }
    else
    {
        /* Gyroscope is not enabled */
        gyroscope_x.general_status = GYRO_DISABLED;
    }

    /* Axis Y */
    /* Check if the gyroscope is enabled */
    if (ADIS16265_ENABLED == gyroscope_y.enabled_flag)
    {
        /* Read temperature data from Y axis gyroscope */
        fs_adis16265_read_single_axis_temp(&gyroscope_y, &p_tmp->Temp_Y);
    }
    else
    {
        /* Gyroscope is not enabled */
        gyroscope_y.general_status = GYRO_DISABLED;
    }

    /* Axis Z */
    /* Check if the gyroscope is enabled */
    if (ADIS16265_ENABLED == gyroscope_z.enabled_flag)
    {
        /* Read temperature data from Z axis gyroscope */
        fs_adis16265_read_single_axis_temp(&gyroscope_z, &p_tmp->Temp_Z);
    }
    else
    {
        /* Gyroscope is not enabled */
        gyroscope_z.general_status = GYRO_DISABLED;
    }

    /* Update any changes to gyroscopes' status */
    fs_adis16265_update_gyro_status_bundle();

    /* If all gyroscopes have failed to read any data */
    if ((GYRO_SUCCESS != gyroscope_x.general_status) &&
        (GYRO_SUCCESS != gyroscope_y.general_status) &&
        (GYRO_SUCCESS != gyroscope_z.general_status))
    {
        /* Signal a complete gyroscope failure */
        return GYRO_ERROR;
    }
    else
    {
        /* Partial or full gyroscope read was completed */
        return GYRO_SUCCESS;
    }
}

gyroscope_status_t adis16265_write_reg16(gyroscope_t *const p_gyroscope, uint8_t address, uint16_t data)
{
    CRIT_ASSERT(NULL != p_gyroscope);

    uint16_t          tx_data;
    HAL_StatusTypeDef res = HAL_OK;

    /* Flip 15th bit to high (0x8000) to signal that it's a write operation */
    /* Put high byte of destination register address plus 1 in high 8-bits as per datasheet, page 12 */
    /* Put high byte of 16-bit data sequence in low 8-bits */
    tx_data = ((uint16_t)0x8000 | ((uint16_t)((address + 1U) << 8)) | ((uint16_t)(data >> 8)));

    /* SPI Chip select on */
    fs_adis16265_chip_select(p_gyroscope, ADIS16265_CHIP_SELECT_ON);

    /* Panel SPI is configured as 16 bit data sequence, therefore it sends 16 bits at once */
    /* Cast of 2nd parameter to uint8_t pointer is due to the way SPI_Transmit function is written from ST HAL */
    res = HAL_SPI_Transmit(&PANEL_SPI_HANDLER, (uint8_t *)&tx_data, 1, 10);

    /* Catch communication error */
    if (HAL_OK != res)
    {
        p_gyroscope->general_status = GYRO_COMM_SPI_W_FAIL;
        return GYRO_COMM_SPI_W_FAIL;
    }

    /* Stall delay between the 2 writes that make up the 16 bit sequence as per datasheet, page 5 */
    fs_adis16265_stall_delay();

    /* Flip 15th bit to high (0x8000) to signal that it's a write operation */
    /* Put low byte of destination register address in high 8-bits as per datasheet, page 12 */
    /* Put low byte of 16-bit data sequence in low 8-bits */
    tx_data = ((uint16_t)0x8000 | ((uint16_t)((uint16_t)address << 8)) | (data & 0xFF));

    /* Panel SPI is configured as 16 bit data sequence, therefore it sends 16 bits at once */
    /* Cast of 2nd parameter to uint8_t pointer is due to the way SPI_Transmit function is written from ST HAL */
    res = HAL_SPI_Transmit(&PANEL_SPI_HANDLER, (uint8_t *)&tx_data, 1, 10);

    /* SPI Chip select off */
    fs_adis16265_chip_select(p_gyroscope, ADIS16265_CHIP_SELECT_OFF);

    /* Catch communication error */
    if (HAL_OK != res)
    {
        p_gyroscope->general_status = GYRO_COMM_SPI_W_FAIL;
        return GYRO_COMM_SPI_W_FAIL;
    }

    return GYRO_SUCCESS;
}

gyroscope_status_t adis16265_read_reg16(gyroscope_t *const p_gyroscope, uint8_t address, uint16_t *const p_data)
{
    CRIT_ASSERT(NULL != p_gyroscope);
    CRIT_ASSERT(NULL != p_data);

    uint16_t          tx_data;
    HAL_StatusTypeDef res = HAL_OK;

    /* Put low byte of destination register address in high 8-bits as per datasheet, page 12 */
    tx_data = (uint16_t)((uint16_t)address << 8);

    /* SPI Chip select on */
    fs_adis16265_chip_select(p_gyroscope, ADIS16265_CHIP_SELECT_ON);

    /* Panel SPI is configured as 16 bit data sequence, therefore it sends 16 bits at once */
    /* Cast of 2nd parameter to uint8_t pointer is due to the way SPI_Transmit function is written from ST HAL */
    res = HAL_SPI_Transmit(&PANEL_SPI_HANDLER, (uint8_t *)&tx_data, 1, 10);

    /* Catch communication error */
    if (HAL_OK != res)
    {
        p_gyroscope->general_status = GYRO_COMM_SPI_W_FAIL;
        return GYRO_COMM_SPI_W_FAIL;
    }

    /* Stall delay between the 2 operations that make up the 16 bit sequence as per datasheet, page 5 */
    fs_adis16265_stall_delay();

    /* Clear variable in preparation for reading */
    *p_data = 0U;

    /* Panel SPI is configured as 16 bit data sequence, therefore it receives 16 bits at once */
    /* Cast of 2nd parameter to uint8_t pointer is due to the way SPI_Transmit function is written from ST HAL */
    res = HAL_SPI_Receive(&PANEL_SPI_HANDLER, (uint8_t *)p_data, 1, 10);

    /* SPI Chip select off */
    fs_adis16265_chip_select(p_gyroscope, ADIS16265_CHIP_SELECT_OFF);

    /* Catch communication error */
    if (HAL_OK != res)
    {
        p_gyroscope->general_status = GYRO_COMM_SPI_R_FAIL;
        return GYRO_COMM_SPI_R_FAIL;
    }

    return GYRO_SUCCESS;
}

gyroscope_status_bundle_t adis16265_get_status(void)
{
    return gyroscope_status;
}

void adis16265_set_panel(PanId_t satellite_axis, Panel_Number_t attached_panel)
{
    /* If the configuration is for X axis gyroscope - change the panel */
    if ((PAN_X_P == satellite_axis) || (PAN_X_M == satellite_axis))
    {
        gyroscope_x.attached_panel = attached_panel;
    }
    /* If the configuration is for Y axis gyroscope - change the panel */
    else if ((PAN_Y_P == satellite_axis) || (PAN_Y_M == satellite_axis))
    {
        gyroscope_y.attached_panel = attached_panel;
    }
    /* The configuration is for Z axis gyroscope - change the panel */
    else
    {
        gyroscope_z.attached_panel = attached_panel;
    }

    adis16265_save_config_to_nvm();
}

Panel_Number_t adis16265_get_panel(PanId_t satellite_axis)
{
    /* If the configuration is for X axis gyroscope - change the panel */
    if ((PAN_X_P == satellite_axis) || (PAN_X_M == satellite_axis))
    {
        return gyroscope_x.attached_panel;
    }
    /* If the configuration is for Y axis gyroscope - change the panel */
    else if ((PAN_Y_P == satellite_axis) || (PAN_Y_M == satellite_axis))
    {
        return gyroscope_y.attached_panel;
    }
    /* The configuration is for Z axis gyroscope - change the panel */
    else
    {
        return gyroscope_z.attached_panel;
    }
}

void adis16265_save_config_to_nvm(void)
{
    gyroscope_configs_t gyro_config;

    /* Make sure the gyroscope configurations are set to disabled before being written
     * to nvm to prevent automatic startup of gyroscopes upon restart */
    gyro_config.gyroscope_array[0]                = gyroscope_x;
    gyro_config.gyroscope_array[0].general_status = GYRO_DISABLED;
    gyro_config.gyroscope_array[0].enabled_flag   = ADIS16265_DISABLED;

    gyro_config.gyroscope_array[1]                = gyroscope_y;
    gyro_config.gyroscope_array[1].general_status = GYRO_DISABLED;
    gyro_config.gyroscope_array[1].enabled_flag   = ADIS16265_DISABLED;

    gyro_config.gyroscope_array[2]                = gyroscope_z;
    gyro_config.gyroscope_array[2].general_status = GYRO_DISABLED;
    gyro_config.gyroscope_array[2].enabled_flag   = ADIS16265_DISABLED;

    Nvm_SetBlockById(NVM_BLOCK_GYROSCOPE_CONFIG, &gyro_config, NVMSETBLOCK_STORE_IMMEDIATELY);
}

void adis16265_load_config_from_nvm(void)
{
    gyroscope_configs_t gyro_config;

    Nvm_GetBlockById(NVM_BLOCK_GYROSCOPE_CONFIG, &gyro_config);

    gyroscope_x = gyro_config.gyroscope_array[0];
    gyroscope_y = gyro_config.gyroscope_array[1];
    gyroscope_z = gyro_config.gyroscope_array[2];
}

void adis16265_get_full_gyro_info(gyroscope_t *const p_gyro_x, gyroscope_t *const p_gyro_y, gyroscope_t *const p_gyro_z)
{
    CRIT_ASSERT(NULL != p_gyro_x);
    CRIT_ASSERT(NULL != p_gyro_y);
    CRIT_ASSERT(NULL != p_gyro_z);

    memcpy(p_gyro_x, &gyroscope_x, sizeof(gyroscope_t));
    memcpy(p_gyro_y, &gyroscope_y, sizeof(gyroscope_t));
    memcpy(p_gyro_z, &gyroscope_z, sizeof(gyroscope_t));
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
static void fs_adis16265_read_single_axis_angle(gyroscope_t *const p_gyroscope, int16_t *const p_gyro_data)
{
    CRIT_ASSERT(NULL != p_gyroscope);
    CRIT_ASSERT(NULL != p_gyro_data);

    uint32_t           temp_data = 0U;
    gyroscope_status_t status;

    /* Several attempts to read the gyroscope data */
    for (uint8_t attempt_counter = 0; attempt_counter < ADIS16265_MAX_ATTEMPTS; attempt_counter++)
    {
        status = adis16265_read_reg16(p_gyroscope, ADIS16265_ANGL_OUT, (uint16_t *)&temp_data);

        /* Disconnected gyroscope */
        if (0xFFFF == (uint16_t)temp_data)
        {
            status = GYRO_DISCONNECTED;
        }

        if (GYRO_SUCCESS == status)
        {
            /* Reading successful, stop attempts */
            p_gyroscope->general_status = status;
            break;
        }
        else
        {
            /* Reading failed, update gyroscope status variable */
            p_gyroscope->general_status = status;
        }
    }
    if (GYRO_SUCCESS == status)
    {
        /* Transform ADC readings into actual angle value */
        /* Only retrieve first 14 bits of reading */
        temp_data &= ADIS16265_GYRO_OUT_14BIT_MASK;
        /* Use integer scaling to convert to hundreds of thousands of degrees */
        temp_data *= ADIS16265_BITS_TO_SCALED_DEG;
        /* Scale back down to degrees */
        temp_data /= ADIS16265_SCALED_DEG_TO_DEG;
        /* Transfer to output buffer */
        *p_gyro_data = (int16_t)temp_data;
    }
}

static void fs_adis16265_read_single_axis_rate(gyroscope_t *const p_gyroscope, int16_t *const p_gyro_data)
{
    CRIT_ASSERT(NULL != p_gyroscope);
    CRIT_ASSERT(NULL != p_gyro_data);

    /* AA TODO: This driver needs a lookover if the int16 type is even needed or its only legacy code
     * that has somehow made its way to the new stuff. Jira issue AOCS-325 */
    gyroscope_status_t status;

    /* Several attempts to read the gyroscope data */
    for (uint8_t attempt_counter = 0; attempt_counter < ADIS16265_MAX_ATTEMPTS; attempt_counter++)
    {
        status = adis16265_read_reg16(p_gyroscope, ADIS16265_GYRO_OUT, (uint16_t *)(p_gyro_data));

        /* Disconnected gyroscope */
        if (0xFFFF == (uint16_t)*p_gyro_data)
        {
            status = GYRO_DISCONNECTED;
        }

        if (GYRO_SUCCESS == status)
        {
            /* If the measurement is outside expected range - invalidate it */
            /* The output data from the gyroscope is 14 bits, hence the ADIS16265_GYRO_OUT_14BIT_MASK */
            if ((((uint16_t)*p_gyro_data & ADIS16265_GYRO_OUT_14BIT_MASK) > ADIS16265_GYRO_OUT_POS_MAX_VAL) &&
                (((uint16_t)*p_gyro_data & ADIS16265_GYRO_OUT_14BIT_MASK) < ADIS16265_GYRO_OUT_NEG_MAX_VAL))
            {
                p_gyroscope->general_status = GYRO_MEASURE_OUT_OF_RANGE;
            }
            else
            {
                /* Reading successful, stop attempts */
                p_gyroscope->general_status = status;
                break;
            }
        }
        else
        {
            /* Reading failed, update gyroscope status variable */
            p_gyroscope->general_status = status;
        }
    }
    if ((GYRO_SUCCESS == status) && (GYRO_MEASURE_OUT_OF_RANGE != p_gyroscope->general_status))
    {
        /* Only retrieve first 14 bits of reading */
        *p_gyro_data = (uint16_t)*p_gyro_data & ADIS16265_GYRO_OUT_14BIT_MASK;
    }
}

static void fs_adis16265_read_single_axis_temp(gyroscope_t *const p_gyroscope, int16_t *const p_gyro_data)
{
    CRIT_ASSERT(NULL != p_gyroscope);
    CRIT_ASSERT(NULL != p_gyro_data);

    uint32_t           temp_data = 0;
    gyroscope_status_t status;

    /* Several attempts to read the gyroscope data */
    for (uint8_t attempt_counter = 0; attempt_counter < ADIS16265_MAX_ATTEMPTS; attempt_counter++)
    {
        status = adis16265_read_reg16(p_gyroscope, ADIS16265_TEMP_OUT, (uint16_t *const)&temp_data);

        /* Disconnected gyroscope */
        if (0xFFFF == (uint16_t)temp_data)
        {
            status = GYRO_DISCONNECTED;
        }

        if (GYRO_SUCCESS == status)
        {
            /* Reading successful, stop attempts */
            p_gyroscope->general_status = status;
            break;
        }
        else
        {
            /* Reading failed, update gyroscope status variable */
            p_gyroscope->general_status = status;
        }
    }
    if (GYRO_SUCCESS == status)
    {
        /* Transform ADC readings into actual temperature value */
        /* Only retrieve first 12 bits of reading */
        temp_data &= ADIS16265_TEMP_12BIT_MASK;
        /* Data conversion as per datasheet, page 13, table 12 */
        if (temp_data >= ADIS16265_TEMP_MINUS_40)
        {
            temp_data = ADIS16265_TEMP_12BIT_MASK - temp_data;
            /* Multiply by scaling factor to get tens of thousands of degrees (integer scaling) */
            temp_data *= ADIS16265_TEMP_FRAC;
            /* Subtract from scaled ambient temperature (25 deg C) */
            temp_data = ADIS16265_TEMP_25 - temp_data;
        }
        else
        {
            /* Multiply by scaling factor to get tens of thousands of degrees (integer scaling) */
            temp_data *= ADIS16265_TEMP_FRAC;
            /* Add to scaled ambient temperature (25 deg Celsius) */
            temp_data = ADIS16265_TEMP_25 + temp_data;
        }

        /* Scale down from tens of thousands of degrees to degrees */
        temp_data /= ADIS16265_TEMP_DIV;

        /* Transfer to output buffer */
        *p_gyro_data = (int16_t)temp_data;
    }
}

static void fs_adis16265_stall_delay(void)
{
    /* System clock tick speed */
    double sys_clock_speed = 1.0 / (double)HAL_RCC_GetSysClockFreq();

    /* How many ticks are needed to fulfill adis16265 stall delay requirement */
    /* Dodge MISRA-C:2004 */
    double   temp_needed_loops  = ADIS16265_STALL_DELAY_MINIMUM_S / sys_clock_speed;
    uint32_t needed_empty_loops = (uint32_t)temp_needed_loops;

    for (volatile uint32_t i = 0; i < needed_empty_loops; i++)
    {
        __asm volatile("nop");
    }
}

static void fs_adis16265_chip_select(const gyroscope_t *const p_gyroscope, uint8_t mode)
{
    CRIT_ASSERT(NULL != p_gyroscope);

    /* The SPI_SlaveSelect function works with 0 base enum, so you need to subtract 1 from the given panel in the gyroscope struct */
    uint8_t panel = (uint8_t)p_gyroscope->attached_panel;
    /* MISRA C++:2008, 4-5-2 */
    panel -= 1;

    /* Chip select on */
    if (ADIS16265_CHIP_SELECT_ON == mode)
    {
        SPI_SlaveSelect(ADIS16265_CHIP_SELECT_ON | panel);
    }
    else
    {
        SPI_SlaveSelect(ADIS16265_CHIP_SELECT_OFF | panel);
    }
}

static uint8_t fs_adis16265_find_gyro_based_on_axis(const gyroscope_configs_t *const p_gyroscope_configs, PanId_t satellite_axis)
{
    CRIT_ASSERT(NULL != p_gyroscope_configs);

    uint8_t res = MAX_PAN;
    uint8_t i   = 0;

    /* Go through all gyroscope configs */
    for (i = 0; i < (GYROSCOPE_COUNT - 1); i++)
    {
        /* Find the one that is for the desired axis */
        if (satellite_axis == p_gyroscope_configs->gyroscope_array[i].satellite_axis)
        {
            res = i;
        }
    }

    return res;
}

static void fs_adis16265_save_gyro_config_change(const gyroscope_t *const p_gyroscope)
{
    CRIT_ASSERT(NULL != p_gyroscope);

    /* If the configuration is for X axis gyroscope - update that local variable */
    if ((PAN_X_P == p_gyroscope->satellite_axis) || (PAN_X_M == p_gyroscope->satellite_axis))
    {
        memcpy(&gyroscope_x, p_gyroscope, sizeof(gyroscope_t));
    }
    /* If the configuration is for Y axis gyroscope - update that local variable */
    else if ((PAN_Y_P == p_gyroscope->satellite_axis) || (PAN_Y_M == p_gyroscope->satellite_axis))
    {
        memcpy(&gyroscope_y, p_gyroscope, sizeof(gyroscope_t));
    }
    /* The configuration is for Z axis gyroscope - update that local variable */
    else
    {
        memcpy(&gyroscope_z, p_gyroscope, sizeof(gyroscope_t));
    }
}

static void fs_adis16265_update_gyro_status_bundle(void)
{
    gyroscope_status.gyroscope_x_status = gyroscope_x.general_status;
    gyroscope_status.gyroscope_y_status = gyroscope_y.general_status;
    gyroscope_status.gyroscope_z_status = gyroscope_z.general_status;
}

static void fs_adis16265_disable_gyro_based_on_axis(PanId_t satellite_axis)
{
    /* If the configuration is for X axis gyroscope - disable that gyroscope */
    if ((PAN_X_P == satellite_axis) || (PAN_X_M == satellite_axis))
    {
        gyroscope_x.enabled_flag = ADIS16265_DISABLED;
    }
    /* If the configuration is for Y axis gyroscope - disable that gyroscope */
    else if ((PAN_Y_P == satellite_axis) || (PAN_Y_M == satellite_axis))
    {
        gyroscope_y.enabled_flag = ADIS16265_DISABLED;
    }
    /* The configuration is for Z axis gyroscope - disable that gyroscope */
    else
    {
        gyroscope_z.enabled_flag = ADIS16265_DISABLED;
    }
}
