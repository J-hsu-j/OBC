#ifndef __LIS3MDL_MAG_DRIVER__H
#define __LIS3MDL_MAG_DRIVER__H

/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup Drivers
 * @{
 *
 * @defgroup magn_lis3mdl Magnetorquer LIS3MDL
 * @{
 *
 * @file     LIS3MDL_MAG_driver.h
 * @brief    LIS3MDL driver header file
 *
 * @}
 * @}
 *
 */

#include <stdint.h>
#include "User_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
/************** I2C Address *****************/

#define LIS3MDL_MAG_I2C_ADDRESS_LOW  0x38 // SAD[1] = 0
#define LIS3MDL_MAG_I2C_ADDRESS_HIGH 0x3C // SAD[1] = 1

/************** Who am I  *******************/

#define LIS3MDL_MAG_WHO_AM_I 0x3D

/************** Device Register  *******************/
#define LIS3MDL_MAG_WHO_AM_I_REG 0X0F
#define LIS3MDL_MAG_CTRL_REG1    0X20
#define LIS3MDL_MAG_CTRL_REG2    0X21
#define LIS3MDL_MAG_CTRL_REG3    0X22
#define LIS3MDL_MAG_CTRL_REG4    0X23
#define LIS3MDL_MAG_CTRL_REG5    0X24
#define LIS3MDL_MAG_STATUS_REG   0X27
#define LIS3MDL_MAG_OUTX_L       0X28
#define LIS3MDL_MAG_OUTX_H       0X29
#define LIS3MDL_MAG_OUTY_L       0X2A
#define LIS3MDL_MAG_OUTY_H       0X2B
#define LIS3MDL_MAG_OUTZ_L       0X2C
#define LIS3MDL_MAG_OUTZ_H       0X2D
#define LIS3MDL_MAG_TEMP_OUT_L   0X2E
#define LIS3MDL_MAG_TEMP_OUT_H   0X2F
#define LIS3MDL_MAG_INT_CFG      0X30
#define LIS3MDL_MAG_INT_SRC      0X31
#define LIS3MDL_MAG_INT_THS_L    0X32
#define LIS3MDL_MAG_INT_THS_H    0X33

#define LIS3MDL_MAG_WHO_AM_I_BIT_MASK     0xFF
#define LIS3MDL_MAG_WHO_AM_I_BIT_POSITION 0

#define LIS3MDL_MAG_MD_MASK      0x03
#define LIS3MDL_MAG_BDU_MASK     0x40
#define LIS3MDL_MAG_FS_MASK      0x60
#define LIS3MDL_MAG_DO_MASK      0x1C
#define LIS3MDL_MAG_ST_MASK      0x01
#define LIS3MDL_MAG_OM_MASK      0x60
#define LIS3MDL_MAG_TEMP_EN_MASK 0x80

#define LIS3MDL_MAG_SOFT_RST_MASK 0x04
#define LIS3MDL_MAG_REBOOT_MASK   0x08
#define LIS3MDL_MAG_SIM_MASK      0x04
#define LIS3MDL_MAG_LP_MASK       0x20
#define LIS3MDL_MAG_BLE_MASK      0x02
#define LIS3MDL_MAG_OMZ_MASK      0x0C

#define LIS3MDL_MAG_XDA_MASK   0x01
#define LIS3MDL_MAG_YDA_MASK   0x02
#define LIS3MDL_MAG_ZDA_MASK   0x04
#define LIS3MDL_MAG_ZYXDA_MASK 0x08
#define LIS3MDL_MAG_XOR_MASK   0x10
#define LIS3MDL_MAG_YOR_MASK   0x20
#define LIS3MDL_MAG_ZOR_MASK   0x40
#define LIS3MDL_MAG_ZYXOR_MASK 0x80

#define LIS3MDL_MAG_IEN_MASK  0x01
#define LIS3MDL_MAG_LIR_MASK  0x02
#define LIS3MDL_MAG_IEA_MASK  0x04
#define LIS3MDL_MAG_ZIEN_MASK 0x20
#define LIS3MDL_MAG_YIEN_MASK 0x40
#define LIS3MDL_MAG_XIEN_MASK 0x80

#define LIS3MDL_MAG_INT_MASK   0x01
#define LIS3MDL_MAG_MROI_MASK  0x02
#define LIS3MDL_MAG_NTH_Z_MASK 0x04
#define LIS3MDL_MAG_NTH_Y_MASK 0x08
#define LIS3MDL_MAG_NTH_X_MASK 0x10
#define LIS3MDL_MAG_PTH_Z_MASK 0x20
#define LIS3MDL_MAG_PTH_Y_MASK 0x40
#define LIS3MDL_MAG_PTH_X_MASK 0x80

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

#ifndef __SHARED__TYPES
#define __SHARED__TYPES

typedef union
{
    int16_t i16bit[3];
    uint8_t u8bit[6];
} Type3Axis16bit_U;

typedef union
{
    int16_t i16bit;
    uint8_t u8bit[2];
} Type1Axis16bit_U;

typedef union
{
    uint32_t i32bit;
    uint8_t  u8bit[4];
} Type1Axis32bit_U;

#endif /*__SHARED__TYPES*/

typedef enum
{
    LIS3MDL_MAG_MD_CONTINUOUS      = 0x00,
    LIS3MDL_MAG_MD_SINGLE          = 0x01,
    LIS3MDL_MAG_MD_POWER_DOWN      = 0x02,
    LIS3MDL_MAG_MD_POWER_DOWN_AUTO = 0x03,
} LIS3MDL_MAG_MD_t;

typedef enum
{
    LIS3MDL_MAG_BDU_DISABLE = 0x00,
    LIS3MDL_MAG_BDU_ENABLE  = 0x40,
} LIS3MDL_MAG_BDU_t;

typedef enum
{
    LIS3MDL_MAG_FS_4Ga  = 0x00,
    LIS3MDL_MAG_FS_8Ga  = 0x20,
    LIS3MDL_MAG_FS_12Ga = 0x40,
    LIS3MDL_MAG_FS_16Ga = 0x60,
} LIS3MDL_MAG_FS_t;

typedef enum
{
    LIS3MDL_MAG_DO_0_625Hz = 0x00,
    LIS3MDL_MAG_DO_1_25Hz  = 0x04,
    LIS3MDL_MAG_DO_2_5Hz   = 0x08,
    LIS3MDL_MAG_DO_5Hz     = 0x0C,
    LIS3MDL_MAG_DO_10Hz    = 0x10,
    LIS3MDL_MAG_DO_20Hz    = 0x14,
    LIS3MDL_MAG_DO_40Hz    = 0x18,
    LIS3MDL_MAG_DO_80Hz    = 0x1C,
} LIS3MDL_MAG_DO_t;

typedef enum
{
    LIS3MDL_MAG_ST_DISABLE = 0x00,
    LIS3MDL_MAG_ST_ENABLE  = 0x01,
} LIS3MDL_MAG_ST_t;

typedef enum
{
    LIS3MDL_MAG_OM_LOW_POWER  = 0x00,
    LIS3MDL_MAG_OM_MEDIUM     = 0x20,
    LIS3MDL_MAG_OM_HIGH       = 0x40,
    LIS3MDL_MAG_OM_ULTRA_HIGH = 0x60,
} LIS3MDL_MAG_OM_t;

typedef enum
{
    LIS3MDL_MAG_TEMP_EN_DISABLE = 0x00,
    LIS3MDL_MAG_TEMP_EN_ENABLE  = 0x80,
} LIS3MDL_MAG_TEMP_EN_t;

typedef enum
{
    LIS3MDL_MAG_SOFT_RST_NO  = 0x00,
    LIS3MDL_MAG_SOFT_RST_YES = 0x04,
} LIS3MDL_MAG_SOFT_RST_t;

typedef enum
{
    LIS3MDL_MAG_REBOOT_NO  = 0x00,
    LIS3MDL_MAG_REBOOT_YES = 0x08,
} LIS3MDL_MAG_REBOOT_t;

typedef enum
{
    LIS3MDL_MAG_SIM_4_WIRE = 0x00,
    LIS3MDL_MAG_SIM_3_WIRE = 0x04,
} LIS3MDL_MAG_SIM_t;

typedef enum
{
    LIS3MDL_MAG_LP_DISABLE = 0x00,
    LIS3MDL_MAG_LP_ENABLE  = 0x20,
} LIS3MDL_MAG_LP_t;

typedef enum
{
    LIS3MDL_MAG_BLE_INVERT  = 0x00,
    LIS3MDL_MAG_BLE_DEFAULT = 0x02,
} LIS3MDL_MAG_BLE_t;

typedef enum
{
    LIS3MDL_MAG_OMZ_LOW_POWER  = 0x00,
    LIS3MDL_MAG_OMZ_MEDIUM     = 0x04,
    LIS3MDL_MAG_OMZ_HIGH       = 0x08,
    LIS3MDL_MAG_OMZ_ULTRA_HIGH = 0x0C,
} LIS3MDL_MAG_OMZ_t;

typedef enum
{
    LIS3MDL_MAG_XDA_NOT_AVAILABLE = 0x00,
    LIS3MDL_MAG_XDA_AVAILABLE     = 0x01,
} LIS3MDL_MAG_XDA_t;

typedef enum
{
    LIS3MDL_MAG_YDA_NOT_AVAILABLE = 0x00,
    LIS3MDL_MAG_YDA_AVAILABLE     = 0x02,
} LIS3MDL_MAG_YDA_t;

typedef enum
{
    LIS3MDL_MAG_ZDA_NOT_AVAILABLE = 0x00,
    LIS3MDL_MAG_ZDA_AVAILABLE     = 0x04,
} LIS3MDL_MAG_ZDA_t;

typedef enum
{
    LIS3MDL_MAG_ZYXDA_NOT_AVAILABLE = 0x00,
    LIS3MDL_MAG_ZYXDA_AVAILABLE     = 0x08,
} LIS3MDL_MAG_ZYXDA_t;

typedef enum
{
    LIS3MDL_MAG_XOR_NOT_OVERRUN = 0x00,
    LIS3MDL_MAG_XOR_OVERRUN     = 0x10,
} LIS3MDL_MAG_XOR_t;

typedef enum
{
    LIS3MDL_MAG_YOR_NOT_OVERRUN = 0x00,
    LIS3MDL_MAG_YOR_OVERRUN     = 0x20,
} LIS3MDL_MAG_YOR_t;

typedef enum
{
    LIS3MDL_MAG_ZOR_NOT_OVERRUN = 0x00,
    LIS3MDL_MAG_ZOR_OVERRUN     = 0x40,
} LIS3MDL_MAG_ZOR_t;

typedef enum
{
    LIS3MDL_MAG_ZYXOR_NOT_OVERRUN = 0x00,
    LIS3MDL_MAG_ZYXOR_OVERRUN     = 0x80,
} LIS3MDL_MAG_ZYXOR_t;

typedef enum
{
    LIS3MDL_MAG_IEN_DISABLE = 0x00,
    LIS3MDL_MAG_IEN_ENABLE  = 0x01,
} LIS3MDL_MAG_IEN_t;

typedef enum
{
    LIS3MDL_MAG_LIR_LATCHED     = 0x00,
    LIS3MDL_MAG_LIR_NOT_LATCHED = 0x02,
} LIS3MDL_MAG_LIR_t;

typedef enum
{
    LIS3MDL_MAG_IEA_LOW  = 0x00,
    LIS3MDL_MAG_IEA_HIGH = 0x04,
} LIS3MDL_MAG_IEA_t;

typedef enum
{
    LIS3MDL_MAG_ZIEN_DISABLE = 0x00,
    LIS3MDL_MAG_ZIEN_ENABLE  = 0x20,
} LIS3MDL_MAG_ZIEN_t;

typedef enum
{
    LIS3MDL_MAG_YIEN_DISABLE = 0x00,
    LIS3MDL_MAG_YIEN_ENABLE  = 0x40,
} LIS3MDL_MAG_YIEN_t;

typedef enum
{
    LIS3MDL_MAG_XIEN_DISABLE = 0x00,
    LIS3MDL_MAG_XIEN_ENABLE  = 0x80,
} LIS3MDL_MAG_XIEN_t;

typedef enum
{
    LIS3MDL_MAG_INT_DOWN = 0x00,
    LIS3MDL_MAG_INT_UP   = 0x01,
} LIS3MDL_MAG_INT_t;

typedef enum
{
    LIS3MDL_MAG_MROI_IN_RANGE = 0x00,
    LIS3MDL_MAG_MROI_OVERFLOW = 0x02,
} LIS3MDL_MAG_MROI_t;

typedef enum
{
    LIS3MDL_MAG_NTH_Z_DOWN = 0x00,
    LIS3MDL_MAG_NTH_Z_UP   = 0x04,
} LIS3MDL_MAG_NTH_Z_t;

typedef enum
{
    LIS3MDL_MAG_NTH_Y_DOWN = 0x00,
    LIS3MDL_MAG_NTH_Y_UP   = 0x08,
} LIS3MDL_MAG_NTH_Y_t;

typedef enum
{
    LIS3MDL_MAG_NTH_X_DOWN = 0x00,
    LIS3MDL_MAG_NTH_X_UP   = 0x10,
} LIS3MDL_MAG_NTH_X_t;

typedef enum
{
    LIS3MDL_MAG_PTH_Z_DOWN = 0x00,
    LIS3MDL_MAG_PTH_Z_UP   = 0x20,
} LIS3MDL_MAG_PTH_Z_t;

typedef enum
{
    LIS3MDL_MAG_PTH_Y_DOWN = 0x00,
    LIS3MDL_MAG_PTH_Y_UP   = 0x40,
} LIS3MDL_MAG_PTH_Y_t;

typedef enum
{
    LIS3MDL_MAG_PTH_X_DOWN = 0x00,
    LIS3MDL_MAG_PTH_X_UP   = 0x80,
} LIS3MDL_MAG_PTH_X_t;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

/**
 * @brief Generic Writing function. It must be fullfilled with either I2C or SPI writing function
 * @param[in] deviceAddr I2C address
 * @param[in] WriteAddr register address to write to
 * @param[in] Data register value
 */
status_t LIS3MDL_MAG_WriteReg(uint8_t deviceAddress, uint8_t WriteAddr, uint8_t Data);

/**
 * @brief Generic Reading function. It must be fullfilled with either I2C or SPI reading functions
 * @param[in] deviceAddr I2C address
 * @param[in] Reg register address to write to
 * @param[out] Data buffer to receive the register value
 */
status_t LIS3MDL_MAG_ReadReg(uint8_t deviceAddr, uint8_t Reg, uint8_t *Data);

/**
 * @brief Read WHO_AM_I_BIT
 * @param[in] id I2C device address
 * @param[out] value WHO_AM_I register value
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_WHO_AM_I_(uint8_t id, uint8_t *value);

/**
 * @brief Write MD
 * @param[in] id I2C device address
 * @param[in] newValue operating mode value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_SystemOperatingMode(uint8_t id, LIS3MDL_MAG_MD_t newValue);

/**
 * @brief Read MD
 * @param[in] id I2C device address
 * @param[out] value Status of MD (see LIS3MDL_MAG_MD_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_SystemOperatingMode(uint8_t id, LIS3MDL_MAG_MD_t *value);

/**
 * @brief Write BDU
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_BlockDataUpdate(uint8_t id, LIS3MDL_MAG_BDU_t newValue);

/**
 * @brief Read BDU
 * @param[in] id I2C device address
 * @param[out] value Status of BDU (see LIS3MDL_MAG_BDU_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_BlockDataUpdate(uint8_t id, LIS3MDL_MAG_BDU_t *value);

/**
 * @brief Write FS
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_FullScale(uint8_t id, LIS3MDL_MAG_FS_t newValue);

/**
 * @brief Read FS
 * @param[in] id I2C device address
 * @param[out] value register value from the device
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_FullScale(uint8_t id, LIS3MDL_MAG_FS_t *value);

/**
 * @brief Write DO
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_OutputDataRate(uint8_t id, LIS3MDL_MAG_DO_t newValue);

/**
 * @brief Read DO
 * @param[in] id I2C device address
 * @param[out] value data rate value read from the device
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_OutputDataRate(uint8_t id, LIS3MDL_MAG_DO_t *value);

/**
 * @brief Read Magnetic output register
 * @param[in] id I2C device address
 * @param[out] buff Magnetic buffer values
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_Get_Magnetic(uint8_t id, uint8_t *buff);

/**
 * @brief Write ST
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_SelfTest(uint8_t id, LIS3MDL_MAG_ST_t newValue);

/**
 * @brief Read ST
 * @param[in] id I2C device address
 * @param[out] value Status of ST (see LIS3MDL_MAG_ST_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_SelfTest(uint8_t id, LIS3MDL_MAG_ST_t *value);

/**
 * @brief Write OM
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_OperatingModeXY(uint8_t id, LIS3MDL_MAG_OM_t newValue);

/**
 * @brief Read OM
 * @param[in] id I2C device address
 * @param[out] value Status of OM see (LIS3MDL_MAG_OM_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_OperatingModeXY(uint8_t id, LIS3MDL_MAG_OM_t *value);

/**
 * @brief Write TEMP_EN
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_TemperatureSensor(uint8_t id, LIS3MDL_MAG_TEMP_EN_t newValue);

/**
 * @brief Read TEMP_EN
 * @param[in] id I2C device address
 * @param[out] value Status of TEMP_EN (see LIS3MDL_MAG_TEMP_EN_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_TemperatureSensor(uint8_t id, LIS3MDL_MAG_TEMP_EN_t *value);

/**
 * @brief Write SOFT_RST
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_SoftRST(uint8_t id, LIS3MDL_MAG_SOFT_RST_t newValue);

/**
 * @brief Read SOFT_RST
 * @param[in] id I2C device address
 * @param[out] value Status of SOFT_RST (see LIS3MDL_MAG_SOFT_RST_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_SoftRST(uint8_t id, LIS3MDL_MAG_SOFT_RST_t *value);

/**
 * @brief Write REBOOT
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_Reboot(uint8_t id, LIS3MDL_MAG_REBOOT_t newValue);

/**
 * @brief Read REBOOT
 * @param[in] id I2C device address
 * @param[out] value Status of REBOOT (see LIS3MDL_MAG_REBOOT_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_Reboot(uint8_t id, LIS3MDL_MAG_REBOOT_t *value);

/**
 * @brief Write SIM
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_SerialInterfaceMode(uint8_t id, LIS3MDL_MAG_SIM_t newValue);

/**
 * @brief Read SIM
 * @param[in] id I2C device address
 * @param[out] value Status of SIM (see LIS3MDL_MAG_SIM_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_SerialInterfaceMode(uint8_t id, LIS3MDL_MAG_SIM_t *value);

/**
 * @brief Write LP
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_FastLowPowerXYZ(uint8_t id, LIS3MDL_MAG_LP_t newValue);

/**
 * @brief Read LP
 * @param[in] id I2C device address
 * @param[out] value Status of LP (see LIS3MDL_MAG_LP_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_FastLowPowerXYZ(uint8_t id, LIS3MDL_MAG_LP_t *value);

/**
 * @brief Write BLE
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_LittleBigEndianInversion(uint8_t id, LIS3MDL_MAG_BLE_t newValue);

/**
 * @brief Read BLE
 * @param[in] id I2C device address
 * @param[out] value Status of BLE (see LIS3MDL_MAG_BLE_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_LittleBigEndianInversion(uint8_t id, LIS3MDL_MAG_BLE_t *value);

/**
 * @brief Write OMZ
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_OperatingModeZ(uint8_t id, LIS3MDL_MAG_OMZ_t newValue);

/**
 * @brief Read OMZ
 * @param[in] id I2C device address
 * @param[out] value Status of OMZ (see LIS3MDL_MAG_OMZ_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_OperatingModeZ(uint8_t id, LIS3MDL_MAG_OMZ_t *value);

/**
 * @brief Read XDA
 * @param[in] id I2C device address
 * @param[out] value Status of XDA (see LIS3MDL_MAG_XDA_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_NewXData(uint8_t id, LIS3MDL_MAG_XDA_t *value);

/**
 * @brief Read YDA
 * @param[in] id I2C device address
 * @param[out] value Status of YDA (see LIS3MDL_MAG_YDA_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_NewYData(uint8_t id, LIS3MDL_MAG_YDA_t *value);

/**
 * @brief Read ZDA
 * @param[in] id I2C device address
 * @param[out] value Status of ZDA (see LIS3MDL_MAG_ZDA_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_NewZData(uint8_t id, LIS3MDL_MAG_ZDA_t *value);

/**
 * @brief Read ZYXDA
 * @param[in] id I2C device address
 * @param[out] value Status of ZYXDA (see LIS3MDL_MAG_ZYXDA_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_NewXYZData(uint8_t id, LIS3MDL_MAG_ZYXDA_t *value);

/**
 * @brief Read XOR
 * @param[in] id I2C device address
 * @param[out] value Status of XOR (see LIS3MDL_MAG_XOR_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_DataXOverrun(uint8_t id, LIS3MDL_MAG_XOR_t *value);

/**
 * @brief Read YOR
 * @param[in] id I2C device address
 * @param[out] value Status of YOR (see LIS3MDL_MAG_YOR_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_DataYOverrun(uint8_t id, LIS3MDL_MAG_YOR_t *value);

/**
 * @brief Read ZOR
 * @param[in] id I2C device address
 * @param[out] value Status of ZOR (see LIS3MDL_MAG_ZOR_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_DataZOverrun(uint8_t id, LIS3MDL_MAG_ZOR_t *value);

/**
 * @brief Read ZYXOR
 * @param[in] id I2C device address
 * @param[out] value Status of ZYXOR (see LIS3MDL_MAG_ZYXOR_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_DataXYZOverrun(uint8_t id, LIS3MDL_MAG_ZYXOR_t *value);

/**
 * @brief Write IEN
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_InterruptEnable(uint8_t id, LIS3MDL_MAG_IEN_t newValue);

/**
 * @brief Read IEN
 * @param[in] id I2C device address
 * @param[out] value Status of IEN (see LIS3MDL_MAG_IEN_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_InterruptEnable(uint8_t id, LIS3MDL_MAG_IEN_t *value);

/**
 * @brief Write LIR
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_LatchInterruptRq(uint8_t id, LIS3MDL_MAG_LIR_t newValue);

/**
 * @brief Read LIR
 * @param[in] id I2C device address
 * @param[out] value Status of LIR (see LIS3MDL_MAG_LIR_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_LatchInterruptRq(uint8_t id, LIS3MDL_MAG_LIR_t *value);

/**
 * @brief Write IEA
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_InterruptActive(uint8_t id, LIS3MDL_MAG_IEA_t newValue);

/**
 * @brief Read IEA
 * @param[in] id I2C device address
 * @param[out] value Status of IEA (see LIS3MDL_MAG_IEA_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_InterruptActive(uint8_t id, LIS3MDL_MAG_IEA_t *value);

/**
 * @brief Write ZIEN
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_InterruptOnZ(uint8_t id, LIS3MDL_MAG_ZIEN_t newValue);

/**
 * @brief Read ZIEN
 * @param[in] id I2C device address
 * @param[out] value Status of ZIEN (see LIS3MDL_MAG_ZIEN_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_InterruptOnZ(uint8_t id, LIS3MDL_MAG_ZIEN_t *value);

/**
 * @brief Write YIEN
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_InterruptOnY(uint8_t id, LIS3MDL_MAG_YIEN_t newValue);

/**
 * @brief Read YIEN
 * @param[in] id I2C device address
 * @param[out] value Status of YIEN (see LIS3MDL_MAG_YIEN_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_InterruptOnY(uint8_t id, LIS3MDL_MAG_YIEN_t *value);

/**
 * @brief Write XIEN
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_InterruptOnX(uint8_t id, LIS3MDL_MAG_XIEN_t newValue);

/**
 * @brief Read XIEN
 * @param[in] id I2C device address
 * @param[out] value Status of XIEN (see LIS3MDL_MAG_XIEN_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_InterruptOnX(uint8_t id, LIS3MDL_MAG_XIEN_t *value);

/**
 * @brief Write INT
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_InterruptFlag(uint8_t id, LIS3MDL_MAG_INT_t newValue);

/**
 * @brief Read INT
 * @param[in] id I2C device address
 * @param[out] value Status of INT (see LIS3MDL_MAG_INT_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_InterruptFlag(uint8_t id, LIS3MDL_MAG_INT_t *value);

/**
 * @brief Write MROI
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_MagneticFieldOverflow(uint8_t id, LIS3MDL_MAG_MROI_t newValue);

/**
 * @brief Read MROI
 * @param[in] id I2C device address
 * @param[out] value Status of MROI (see LIS3MDL_MAG_MROI_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_MagneticFieldOverflow(uint8_t id, LIS3MDL_MAG_MROI_t *value);

/**
 * @brief Write NTH_Z
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_NegativeThresholdFlagZ(uint8_t id, LIS3MDL_MAG_NTH_Z_t newValue);

/**
 * @brief Read NTH_Z
 * @param[in] id I2C device address
 * @param[out] value Status of NTH_Z (see LIS3MDL_MAG_NTH_Z_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_NegativeThresholdFlagZ(uint8_t id, LIS3MDL_MAG_NTH_Z_t *value);

/**
 * @brief Write NTH_Y
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_NegativeThresholdFlagY(uint8_t id, LIS3MDL_MAG_NTH_Y_t newValue);

/**
 * @brief Read NTH_Y
 * @param[in] id I2C device address
 * @param[out] value Status of NTH_Y (see LIS3MDL_MAG_NTH_Y_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_NegativeThresholdFlagY(uint8_t id, LIS3MDL_MAG_NTH_Y_t *value);

/**
 * @brief Write NTH_X
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_NegativeThresholdFlagX(uint8_t id, LIS3MDL_MAG_NTH_X_t newValue);

/**
 * @brief Read NTH_X
 * @param[in] id I2C device address
 * @param[out] value Status of NTH_X (see LIS3MDL_MAG_NTH_X_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_NegativeThresholdFlagX(uint8_t id, LIS3MDL_MAG_NTH_X_t *value);

/**
 * @brief Write PTH_Z
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_PositiveThresholdFlagZ(uint8_t id, LIS3MDL_MAG_PTH_Z_t newValue);

/**
 * @brief Read PTH_Z
 * @param[in] id I2C device address
 * @param[out] value Status of PTH_Z (see LIS3MDL_MAG_PTH_Z_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_PositiveThresholdFlagZ(uint8_t id, LIS3MDL_MAG_PTH_Z_t *value);

/**
 * @brief Write PTH_Y
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_PositiveThresholdFlagY(uint8_t id, LIS3MDL_MAG_PTH_Y_t newValue);

/**
 * @brief Read PTH_Y
 * @param[in] id I2C device address
 * @param[out] value Status of PTH_Y (see LIS3MDL_MAG_PTH_Y_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_PositiveThresholdFlagY(uint8_t id, LIS3MDL_MAG_PTH_Y_t *value);

/**
 * @brief Write PTH_X
 * @param[in] id I2C device address
 * @param[in] newValue value to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_W_PositiveThresholdFlagX(uint8_t id, LIS3MDL_MAG_PTH_X_t newValue);

/**
 * @brief Read PTH_X
 * @param[in] id I2C device address
 * @param[out] value Status of PTH_X (see LIS3MDL_MAG_PTH_X_t)
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_R_PositiveThresholdFlagX(uint8_t id, LIS3MDL_MAG_PTH_X_t *value);

/**
 * @brief Read Temperature output register
 * @param[in] id I2C device address
 * @param[out] buff Temperature buffer to receive the read value
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_Get_Temperature(uint8_t id, uint8_t *buff);

/**
 * @brief Set MagneticThreshold data row
 * @param[in] id I2C device address
 * @param[in] buff buffer containing the magnetic threshold values to set
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_Set_MagneticThreshold(uint8_t id, uint8_t *buff);

/**
 * @brief Read MagneticThreshold output register
 * @param[in] id I2C device address
 * @param[out] buff MagneticThreshold buffer to hold the received value
 * @return Status [SEN_ERROR, SEN_SUCCESS]
 */
status_t LIS3MDL_MAG_Get_MagneticThreshold(uint8_t id, uint8_t *buff);

#ifdef __cplusplus
}
#endif

#endif
