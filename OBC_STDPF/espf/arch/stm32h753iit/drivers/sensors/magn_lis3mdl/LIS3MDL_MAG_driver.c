/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup magn_lis3mdl
 * @{
 *
 * @file     LIS3MDL_MAG_driver.c
 * @brief    LIS3MDL driver file
 *
 * @}
 *
 */

#include "LIS3MDL_MAG_driver.h"
#include "stm32h7xx_hal.h"
#include "MCU_Init.h"
#include "MX_I2C.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL (NON-STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

status_t LIS3MDL_MAG_WriteReg(uint8_t deviceAddress, uint8_t WriteAddr, uint8_t Data)
{
    HAL_StatusTypeDef I2C_retStat;
    I2C_retStat = mx_i2c_take(MX_I2C_BUS_SENSORS, 50);

    if (I2C_retStat == HAL_OK)
    {
        I2C_retStat = mx_i2c_block_mem_write(MX_I2C_BUS_SENSORS, deviceAddress >> 1, WriteAddr, sizeof(uint8_t), &Data, sizeof(uint8_t));

        mx_i2c_release(MX_I2C_BUS_SENSORS);
    }
    if (I2C_retStat != HAL_OK)
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_ReadReg(uint8_t deviceAddr, uint8_t Reg, uint8_t *Data)
{
    HAL_StatusTypeDef I2C_retStat;

    I2C_retStat = mx_i2c_take(MX_I2C_BUS_SENSORS, 50);
    if (I2C_retStat == HAL_OK)
    {
        I2C_retStat = mx_i2c_block_mem_read(MX_I2C_BUS_SENSORS, deviceAddr >> 1, Reg, sizeof(uint8_t), Data, sizeof(uint8_t));

        mx_i2c_release(MX_I2C_BUS_SENSORS);
    }
    if (I2C_retStat != HAL_OK)
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_WHO_AM_I_(uint8_t id, uint8_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_WHO_AM_I_REG, value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_WHO_AM_I_BIT_MASK; // coerce
    *value = *value >> LIS3MDL_MAG_WHO_AM_I_BIT_POSITION;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_SystemOperatingMode(uint8_t id, LIS3MDL_MAG_MD_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG3, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_MD_MASK;
    value |= newValue;
    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_CTRL_REG3, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_SystemOperatingMode(uint8_t id, LIS3MDL_MAG_MD_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG3, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_MD_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_BlockDataUpdate(uint8_t id, LIS3MDL_MAG_BDU_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG5, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_BDU_MASK;
    value |= newValue;
    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_CTRL_REG5, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_BlockDataUpdate(uint8_t id, LIS3MDL_MAG_BDU_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG5, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_BDU_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_FullScale(uint8_t id, LIS3MDL_MAG_FS_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG2, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_FS_MASK;
    value |= newValue;
    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_CTRL_REG2, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_FullScale(uint8_t id, LIS3MDL_MAG_FS_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG2, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_FS_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_OutputDataRate(uint8_t id, LIS3MDL_MAG_DO_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG1, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_DO_MASK;
    value |= newValue;
    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_CTRL_REG1, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_OutputDataRate(uint8_t id, LIS3MDL_MAG_DO_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG1, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_DO_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_Get_Magnetic(uint8_t id, uint8_t *buff)
{
    uint8_t i, j, k;
    uint8_t numberOfByteForDimension;

    numberOfByteForDimension = 6 / 3;

    k = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < numberOfByteForDimension; j++)
        {
            if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_OUTX_L + k, &buff[k]))
            {
                return SEN_ERROR;
            }
            k++;
        }
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_SelfTest(uint8_t id, LIS3MDL_MAG_ST_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG1, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_ST_MASK;
    value |= newValue;
    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_CTRL_REG1, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_SelfTest(uint8_t id, LIS3MDL_MAG_ST_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG1, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_ST_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_OperatingModeXY(uint8_t id, LIS3MDL_MAG_OM_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG1, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_OM_MASK;
    value |= newValue;
    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_CTRL_REG1, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_OperatingModeXY(uint8_t id, LIS3MDL_MAG_OM_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG1, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_OM_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_TemperatureSensor(uint8_t id, LIS3MDL_MAG_TEMP_EN_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG1, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_TEMP_EN_MASK;
    value |= newValue;
    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_CTRL_REG1, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_TemperatureSensor(uint8_t id, LIS3MDL_MAG_TEMP_EN_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG1, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_TEMP_EN_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_SoftRST(uint8_t id, LIS3MDL_MAG_SOFT_RST_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG2, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_SOFT_RST_MASK;
    value |= newValue;
    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_CTRL_REG2, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_SoftRST(uint8_t id, LIS3MDL_MAG_SOFT_RST_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG2, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_SOFT_RST_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_Reboot(uint8_t id, LIS3MDL_MAG_REBOOT_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG2, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_REBOOT_MASK;
    value |= newValue;
    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_CTRL_REG2, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_Reboot(uint8_t id, LIS3MDL_MAG_REBOOT_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG2, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_REBOOT_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_SerialInterfaceMode(uint8_t id, LIS3MDL_MAG_SIM_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG3, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_SIM_MASK;
    value |= newValue;
    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_CTRL_REG3, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_SerialInterfaceMode(uint8_t id, LIS3MDL_MAG_SIM_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG3, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_SIM_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_FastLowPowerXYZ(uint8_t id, LIS3MDL_MAG_LP_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG3, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_LP_MASK;
    value |= newValue;
    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_CTRL_REG3, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_FastLowPowerXYZ(uint8_t id, LIS3MDL_MAG_LP_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG3, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_LP_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_LittleBigEndianInversion(uint8_t id, LIS3MDL_MAG_BLE_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG4, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_BLE_MASK;
    value |= newValue;
    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_CTRL_REG4, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_LittleBigEndianInversion(uint8_t id, LIS3MDL_MAG_BLE_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG4, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_BLE_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_OperatingModeZ(uint8_t id, LIS3MDL_MAG_OMZ_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG4, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_OMZ_MASK;
    value |= newValue;
    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_CTRL_REG4, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_OperatingModeZ(uint8_t id, LIS3MDL_MAG_OMZ_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_CTRL_REG4, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_OMZ_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_NewXData(uint8_t id, LIS3MDL_MAG_XDA_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_STATUS_REG, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_XDA_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_NewYData(uint8_t id, LIS3MDL_MAG_YDA_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_STATUS_REG, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_YDA_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_NewZData(uint8_t id, LIS3MDL_MAG_ZDA_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_STATUS_REG, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_ZDA_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_NewXYZData(uint8_t id, LIS3MDL_MAG_ZYXDA_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_STATUS_REG, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_ZYXDA_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_DataXOverrun(uint8_t id, LIS3MDL_MAG_XOR_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_STATUS_REG, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_XOR_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_DataYOverrun(uint8_t id, LIS3MDL_MAG_YOR_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_STATUS_REG, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_YOR_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_DataZOverrun(uint8_t id, LIS3MDL_MAG_ZOR_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_STATUS_REG, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_ZOR_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_DataXYZOverrun(uint8_t id, LIS3MDL_MAG_ZYXOR_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_STATUS_REG, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_ZYXOR_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_InterruptEnable(uint8_t id, LIS3MDL_MAG_IEN_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_CFG, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_IEN_MASK;
    value |= newValue;

    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_INT_CFG, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_InterruptEnable(uint8_t id, LIS3MDL_MAG_IEN_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_CFG, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_IEN_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_LatchInterruptRq(uint8_t id, LIS3MDL_MAG_LIR_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_CFG, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_LIR_MASK;
    value |= newValue;

    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_INT_CFG, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_LatchInterruptRq(uint8_t id, LIS3MDL_MAG_LIR_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_CFG, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_LIR_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_InterruptActive(uint8_t id, LIS3MDL_MAG_IEA_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_CFG, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_IEA_MASK;
    value |= newValue;
    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_INT_CFG, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_InterruptActive(uint8_t id, LIS3MDL_MAG_IEA_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_CFG, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_IEA_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_InterruptOnZ(uint8_t id, LIS3MDL_MAG_ZIEN_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_CFG, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_ZIEN_MASK;
    value |= newValue;

    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_INT_CFG, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_InterruptOnZ(uint8_t id, LIS3MDL_MAG_ZIEN_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_CFG, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_ZIEN_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_InterruptOnY(uint8_t id, LIS3MDL_MAG_YIEN_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_CFG, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_YIEN_MASK;
    value |= newValue;

    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_INT_CFG, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_InterruptOnY(uint8_t id, LIS3MDL_MAG_YIEN_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_CFG, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_YIEN_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_InterruptOnX(uint8_t id, LIS3MDL_MAG_XIEN_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_CFG, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_XIEN_MASK;
    value |= newValue;

    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_INT_CFG, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_InterruptOnX(uint8_t id, LIS3MDL_MAG_XIEN_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_CFG, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_XIEN_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_InterruptFlag(uint8_t id, LIS3MDL_MAG_INT_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_SRC, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_INT_MASK;
    value |= newValue;

    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_INT_SRC, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_InterruptFlag(uint8_t id, LIS3MDL_MAG_INT_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_SRC, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_INT_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_MagneticFieldOverflow(uint8_t id, LIS3MDL_MAG_MROI_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_SRC, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_MROI_MASK;
    value |= newValue;

    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_INT_SRC, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_MagneticFieldOverflow(uint8_t id, LIS3MDL_MAG_MROI_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_SRC, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_MROI_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_NegativeThresholdFlagZ(uint8_t id, LIS3MDL_MAG_NTH_Z_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_SRC, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_NTH_Z_MASK;
    value |= newValue;

    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_INT_SRC, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_NegativeThresholdFlagZ(uint8_t id, LIS3MDL_MAG_NTH_Z_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_SRC, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_NTH_Z_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_NegativeThresholdFlagY(uint8_t id, LIS3MDL_MAG_NTH_Y_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_SRC, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_NTH_Y_MASK;
    value |= newValue;

    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_INT_SRC, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_NegativeThresholdFlagY(uint8_t id, LIS3MDL_MAG_NTH_Y_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_SRC, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_NTH_Y_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_NegativeThresholdFlagX(uint8_t id, LIS3MDL_MAG_NTH_X_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_SRC, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_NTH_X_MASK;
    value |= newValue;

    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_INT_SRC, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_NegativeThresholdFlagX(uint8_t id, LIS3MDL_MAG_NTH_X_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_SRC, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_NTH_X_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_PositiveThresholdFlagZ(uint8_t id, LIS3MDL_MAG_PTH_Z_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_SRC, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_PTH_Z_MASK;
    value |= newValue;

    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_INT_SRC, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_PositiveThresholdFlagZ(uint8_t id, LIS3MDL_MAG_PTH_Z_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_SRC, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_PTH_Z_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_PositiveThresholdFlagY(uint8_t id, LIS3MDL_MAG_PTH_Y_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_SRC, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_PTH_Y_MASK;
    value |= newValue;

    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_INT_SRC, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_PositiveThresholdFlagY(uint8_t id, LIS3MDL_MAG_PTH_Y_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_SRC, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_PTH_Y_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_W_PositiveThresholdFlagX(uint8_t id, LIS3MDL_MAG_PTH_X_t newValue)
{
    uint8_t value;
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_SRC, &value))
    {
        return SEN_ERROR;
    }

    value &= ~LIS3MDL_MAG_PTH_X_MASK;
    value |= newValue;

    if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_INT_SRC, value))
    {
        return SEN_ERROR;
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_R_PositiveThresholdFlagX(uint8_t id, LIS3MDL_MAG_PTH_X_t *value)
{
    if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_INT_SRC, (uint8_t *)value))
    {
        return SEN_ERROR;
    }

    *value &= LIS3MDL_MAG_PTH_X_MASK;

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_Get_Temperature(uint8_t id, uint8_t *buff)
{
    uint8_t i, j, k;
    uint8_t numberOfByteForDimension;

    numberOfByteForDimension = 2 / 1;

    k = 0;
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < numberOfByteForDimension; j++)
        {
            if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_TEMP_OUT_L + k, &buff[k]))
            {
                return SEN_ERROR;
            }
            k++;
        }
    }

    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_Set_MagneticThreshold(uint8_t id, uint8_t *buff)
{
    uint8_t i;

    for (i = 0; i < 2; i++)
    {
        if (!LIS3MDL_MAG_WriteReg(id, LIS3MDL_MAG_INT_THS_L + i, buff[i]))
        {
            return SEN_ERROR;
        }
    }
    return SEN_SUCCESS;
}

status_t LIS3MDL_MAG_Get_MagneticThreshold(uint8_t id, uint8_t *buff)
{
    uint8_t i, j, k;
    uint8_t numberOfByteForDimension;

    numberOfByteForDimension = 2 / 1;

    k = 0;
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < numberOfByteForDimension; j++)
        {
            if (!LIS3MDL_MAG_ReadReg(id, LIS3MDL_MAG_TEMP_OUT_L + k, &buff[k]))
            {
                return SEN_ERROR;
            }
            k++;
        }
    }

    return SEN_SUCCESS;
}
