/*!
********************************************************************************************
* @file FP_EPSII_PDM_1ProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface EPSII_PDM_1 v1.0
*
* @copyright         (C) Copyright EnduroSat
*
*                    Contents and presentations are protected world-wide.
*                    Any kind of using, copying etc. is prohibited without prior permission.
*                    All rights - incl. industrial property rights - are reserved.
*
*-------------------------------------------------------------------------------------------
* GENERATOR: org.endurosat.generators.macchiato.binders.Gen_C v2.15
*-------------------------------------------------------------------------------------------
* !!! Please note that this code is fully GENERATED and shall not be manually modified as
* all changes will be overwritten !!!
********************************************************************************************
*/

#ifndef FP_EPSII_PDM_1PROTOCOLTYPES_H
#define FP_EPSII_PDM_1PROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_EPSII_PDM_1 ((uint16_t) (0x00000014))

#define EPSII_PDM_1_GETPOWERDISTRIBUTIONINFO_FUNC_ID ((funcIdType_t) 0x00000002)
#define EPSII_PDM_1_GETDEVICEHEALTHINFO_FUNC_ID ((funcIdType_t) 0x00000003)
#define EPSII_PDM_1_SETPC104GPIO_FUNC_ID ((funcIdType_t) 0x00000004)
#define EPSII_PDM_1_GETPC104GPIO_FUNC_ID ((funcIdType_t) 0x00000005)
#define EPSII_PDM_1_GETRAWSENSORS_FUNC_ID ((funcIdType_t) 0x00000006)
#define EPSII_PDM_1_SETPOWEROUTPUTS_FUNC_ID ((funcIdType_t) 0x00000007)
#define EPSII_PDM_1_GETPOWEROUTPUTS_FUNC_ID ((funcIdType_t) 0x00000008)
#define EPSII_PDM_1_GETPOWERDISTRIBUTIONINFO_FUNCRESP_ID ((funcIdType_t) 0x00000002)
#define EPSII_PDM_1_GETDEVICEHEALTHINFO_FUNCRESP_ID ((funcIdType_t) 0x00000003)
#define EPSII_PDM_1_SETPC104GPIO_FUNCRESP_ID ((funcIdType_t) 0x00000004)
#define EPSII_PDM_1_GETPC104GPIO_FUNCRESP_ID ((funcIdType_t) 0x00000005)
#define EPSII_PDM_1_GETRAWSENSORS_FUNCRESP_ID ((funcIdType_t) 0x00000006)
#define EPSII_PDM_1_SETPOWEROUTPUTS_FUNCRESP_ID ((funcIdType_t) 0x00000007)
#define EPSII_PDM_1_GETPOWEROUTPUTS_FUNCRESP_ID ((funcIdType_t) 0x00000008)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    Set/Get GPIO mask, use as bitmask
*/
#define EPSII_PDM_1_SGGPIO_ONOFF_MASK_SGGPIOBM_DigOUT_OFF ((uint8_t) 0)
#define EPSII_PDM_1_SGGPIO_ONOFF_MASK_SGGPIOBM_DigOUT1 ((uint8_t) 1)
#define EPSII_PDM_1_SGGPIO_ONOFF_MASK_SGGPIOBM_DigOUT2 ((uint8_t) 2)
#define EPSII_PDM_1_SGGPIO_ONOFF_MASK_SGGPIOBM_DigOUT3 ((uint8_t) 4)
#define EPSII_PDM_1_SGGPIO_ONOFF_MASK_SGGPIOBM_DigOUT4 ((uint8_t) 8)
#define EPSII_PDM_1_SGGPIO_ONOFF_MASK_SGGPIOBM_DigOUT5 ((uint8_t) 16)
#define EPSII_PDM_1_SGGPIO_ONOFF_MASK_SGGPIOBM_DigOUT6 ((uint8_t) 32)
#define EPSII_PDM_1_SGGPIO_ONOFF_MASK_SGGPIOBM_DigOUT7 ((uint8_t) 64)
#define EPSII_PDM_1_SGGPIO_ONOFF_MASK_SGGPIOBM_DigOUT8 ((uint8_t) 128)
#define EPSII_PDM_1_SGGPIO_ONOFF_MASK_MAX_CNT  ((uint8_t) 129)
typedef uint8_t EPSII_PDM_1_SGGPIO_OnOff_mask_t;

/*
    Response error of SetPC104GPIO command
*/
#define EPSII_PDM_1_SGGPIO_SETERROR_SGGPIOE_SUCCESS ((uint8_t) 0)
#define EPSII_PDM_1_SGGPIO_SETERROR_SGGPIOE_BAD_STATE ((uint8_t) 1)
#define EPSII_PDM_1_SGGPIO_SETERROR_SGGPIOE_CHIP_ERR ((uint8_t) 2)
#define EPSII_PDM_1_SGGPIO_SETERROR_MAX_CNT  ((uint8_t) 3)
typedef uint8_t EPSII_PDM_1_SGGPIO_SetError_t;

/*
    Set power outputs error codes
*/
#define EPSII_PDM_1_SGPO_SETERROR_SGPOSE_SUCCESS ((uint8_t) 0)
#define EPSII_PDM_1_SGPO_SETERROR_SGPOSE_BAD_STATE ((uint8_t) 1)
#define EPSII_PDM_1_SGPO_SETERROR_SGPOSE_CHIP_ERR ((uint8_t) 2)
#define EPSII_PDM_1_SGPO_SETERROR_MAX_CNT  ((uint8_t) 3)
typedef uint8_t EPSII_PDM_1_SGPO_SetError_t;

/*
    Set/Get GPIO mask, use as bitmask
*/
#define EPSII_PDM_1_SGGPIO_BITMASK_SGGPIOBM_DigOUT1 ((uint8_t) 1)
#define EPSII_PDM_1_SGGPIO_BITMASK_SGGPIOBM_DigOUT2 ((uint8_t) 2)
#define EPSII_PDM_1_SGGPIO_BITMASK_SGGPIOBM_DigOUT3 ((uint8_t) 4)
#define EPSII_PDM_1_SGGPIO_BITMASK_SGGPIOBM_DigOUT4 ((uint8_t) 8)
#define EPSII_PDM_1_SGGPIO_BITMASK_SGGPIOBM_DigOUT5 ((uint8_t) 16)
#define EPSII_PDM_1_SGGPIO_BITMASK_SGGPIOBM_DigOUT6 ((uint8_t) 32)
#define EPSII_PDM_1_SGGPIO_BITMASK_SGGPIOBM_DigOUT7 ((uint8_t) 64)
#define EPSII_PDM_1_SGGPIO_BITMASK_SGGPIOBM_DigOUT8 ((uint8_t) 128)
#define EPSII_PDM_1_SGGPIO_BITMASK_MAX_CNT  ((uint8_t) 129)
typedef uint8_t EPSII_PDM_1_SGGPIO_Bitmask_t;

/*
    Status of chips as seen by CPU
*/
#define EPSII_PDM_1_EDHI_CHIPSTATUS_EDHICS_EMDCS_UNKNOWN ((uint8_t) 0)
#define EPSII_PDM_1_EDHI_CHIPSTATUS_EDHICS_EMDCS_ONLINE ((uint8_t) 1)
#define EPSII_PDM_1_EDHI_CHIPSTATUS_EDHICS_EMDCS_COM_ERR ((uint8_t) 2)
#define EPSII_PDM_1_EDHI_CHIPSTATUS_EDHICS_EMDCS_COM_TIMEOUT ((uint8_t) 3)
#define EPSII_PDM_1_EDHI_CHIPSTATUS_EDHICS_EMDCS_DRV_DISABLED ((uint8_t) 4)
#define EPSII_PDM_1_EDHI_CHIPSTATUS_MAX_CNT  ((uint8_t) 5)
typedef uint8_t EPSII_PDM_1_EDHI_ChipStatus_t;

/*
    Set/Get masks, use as bitmask
*/
#define EPSII_PDM_1_SGPO_BITMASK_SGPOBM_BBUS_RAWOutputEnable ((uint32_t) 1)
#define EPSII_PDM_1_SGPO_BITMASK_SGPOBM_12V_MasterEnable ((uint32_t) 2)
#define EPSII_PDM_1_SGPO_BITMASK_SGPOBM_12V_SP1_3_Enable ((uint32_t) 4)
#define EPSII_PDM_1_SGPO_BITMASK_SGPOBM_12V_SP1_4_Enable ((uint32_t) 8)
#define EPSII_PDM_1_SGPO_BITMASK_SGPOBM_12V_SP1_5_Enable ((uint32_t) 16)
#define EPSII_PDM_1_SGPO_BITMASK_SGPOBM_5V_Ch1_MasterEnable ((uint32_t) 32)
#define EPSII_PDM_1_SGPO_BITMASK_SGPOBM_5V_Ch1_SP2_3_Enable ((uint32_t) 64)
#define EPSII_PDM_1_SGPO_BITMASK_SGPOBM_5V_Ch1_SP2_4_Enable ((uint32_t) 128)
#define EPSII_PDM_1_SGPO_BITMASK_SGPOBM_5V_Ch2_MasterEnable ((uint32_t) 256)
#define EPSII_PDM_1_SGPO_BITMASK_SGPOBM_5V_Ch2_SP1_6_Enable ((uint32_t) 512)
#define EPSII_PDM_1_SGPO_BITMASK_SGPOBM_5V_Ch2_SP1_7_Enable ((uint32_t) 1024)
#define EPSII_PDM_1_SGPO_BITMASK_SGPOBM_3V3_Ch1_MasterEnable ((uint32_t) 2048)
#define EPSII_PDM_1_SGPO_BITMASK_SGPOBM_3V3_Ch1_SP2_5_Enable ((uint32_t) 4096)
#define EPSII_PDM_1_SGPO_BITMASK_SGPOBM_3V3_Ch1_SP2_6_Enable ((uint32_t) 8192)
#define EPSII_PDM_1_SGPO_BITMASK_SGPOBM_3V3_Ch1_SP2_7_Enable ((uint32_t) 16384)
#define EPSII_PDM_1_SGPO_BITMASK_SGPOBM_3V3_Ch2_MasterEnable ((uint32_t) 32768)
#define EPSII_PDM_1_SGPO_BITMASK_MAX_CNT  ((uint32_t) 32769)
typedef uint32_t EPSII_PDM_1_SGPO_Bitmask_t;

/*
    Structure for Voltage, Current, Power
*/
typedef struct {
    int32_t i32U;
    int32_t i32I;
    int32_t i32P;
} PACKED_STRUCT EPSII_PDM_1_ESEPSII_UIP_t;

/*
    Telemetry sensors IDs
*/
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_NULL_ID ((uint16_t) 0)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_3V3_1P_I_ID ((uint16_t) 1)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_3V3_1P_U_ID ((uint16_t) 2)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_3V3_1P_P_ID ((uint16_t) 3)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_3V3_1P_T_ID ((uint16_t) 4)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_3V3_1R_I_ID ((uint16_t) 5)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_3V3_1R_U_ID ((uint16_t) 6)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_3V3_1R_P_ID ((uint16_t) 7)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_3V3_1R_T_ID ((uint16_t) 8)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_3V3_2P_I_ID ((uint16_t) 9)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_3V3_2P_U_ID ((uint16_t) 10)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_3V3_2P_P_ID ((uint16_t) 11)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_3V3_2P_T_ID ((uint16_t) 12)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_3V3_2R_I_ID ((uint16_t) 13)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_3V3_2R_U_ID ((uint16_t) 14)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_3V3_2R_P_ID ((uint16_t) 15)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_3V3_2R_T_ID ((uint16_t) 16)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_5V_1P_I_ID ((uint16_t) 17)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_5V_1P_U_ID ((uint16_t) 18)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_5V_1P_P_ID ((uint16_t) 19)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_5V_1P_T_ID ((uint16_t) 20)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_5V_1R_I_ID ((uint16_t) 21)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_5V_1R_U_ID ((uint16_t) 22)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_5V_1R_P_ID ((uint16_t) 23)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_5V_1R_T_ID ((uint16_t) 24)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_5V_2P_I_ID ((uint16_t) 25)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_5V_2P_U_ID ((uint16_t) 26)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_5V_2P_P_ID ((uint16_t) 27)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_5V_2P_T_ID ((uint16_t) 28)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_5V_2R_I_ID ((uint16_t) 29)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_5V_2R_U_ID ((uint16_t) 30)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_5V_2R_P_ID ((uint16_t) 31)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_5V_2R_T_ID ((uint16_t) 32)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_12V_P_I_ID ((uint16_t) 33)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_12V_P_U_ID ((uint16_t) 34)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_12V_P_P_ID ((uint16_t) 35)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_12V_P_T_ID ((uint16_t) 36)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_12V_R_I_ID ((uint16_t) 37)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_12V_R_U_ID ((uint16_t) 38)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_12V_R_P_ID ((uint16_t) 39)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_INA_LUP_IN_12V_R_T_ID ((uint16_t) 40)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_TEMPERATURE_PCB_1_ID ((uint16_t) 41)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_TEMPERATURE_PCB_2_ID ((uint16_t) 42)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_ADC_CPU_T_ID ((uint16_t) 43)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_ADC_CPU_AVCC_U_ID ((uint16_t) 44)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_ADC_SYS_BUS_V_IN_MON ((uint16_t) 45)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_ADC_BAT_RAW_V_OUT_MON ((uint16_t) 46)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_ADC_BAT_RAW_I_1_OUT_MON ((uint16_t) 47)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_ADC_BAT_RAW_I_2_OUT_MON ((uint16_t) 48)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_ADC_12V_OUT_MON ((uint16_t) 49)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_ADC_5V_OUT_MON_1 ((uint16_t) 50)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_ADC_5V_OUT_MON_2 ((uint16_t) 51)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_ADC_3V3_OUT_MON_1 ((uint16_t) 52)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_ESEPSIISSVPDM_ADC_3V3_OUT_MON_2 ((uint16_t) 53)
#define EPSII_PDM_1_ESEPSII_PDM_SENSORIDS_MAX_CNT  ((uint16_t) 54)
typedef uint16_t EPSII_PDM_1_ESEPSII_PDM_SensorIDs_t;

/*
    Set/Get masks, use as bitmask
*/
#define EPSII_PDM_1_SGPO_ON_OFF_BITMASK_SGPOBM_Switch_OFF ((uint32_t) 0)
#define EPSII_PDM_1_SGPO_ON_OFF_BITMASK_SGPOBM_BBUS_RAWOutputEnable ((uint32_t) 1)
#define EPSII_PDM_1_SGPO_ON_OFF_BITMASK_SGPOBM_12V_MasterEnable ((uint32_t) 2)
#define EPSII_PDM_1_SGPO_ON_OFF_BITMASK_SGPOBM_12V_SP1_3_Enable ((uint32_t) 4)
#define EPSII_PDM_1_SGPO_ON_OFF_BITMASK_SGPOBM_12V_SP1_4_Enable ((uint32_t) 8)
#define EPSII_PDM_1_SGPO_ON_OFF_BITMASK_SGPOBM_12V_SP1_5_Enable ((uint32_t) 16)
#define EPSII_PDM_1_SGPO_ON_OFF_BITMASK_SGPOBM_5V_Ch1_MasterEnable ((uint32_t) 32)
#define EPSII_PDM_1_SGPO_ON_OFF_BITMASK_SGPOBM_5V_Ch1_SP2_3_Enable ((uint32_t) 64)
#define EPSII_PDM_1_SGPO_ON_OFF_BITMASK_SGPOBM_5V_Ch1_SP2_4_Enable ((uint32_t) 128)
#define EPSII_PDM_1_SGPO_ON_OFF_BITMASK_SGPOBM_5V_Ch2_MasterEnable ((uint32_t) 256)
#define EPSII_PDM_1_SGPO_ON_OFF_BITMASK_SGPOBM_5V_Ch2_SP1_6_Enable ((uint32_t) 512)
#define EPSII_PDM_1_SGPO_ON_OFF_BITMASK_SGPOBM_5V_Ch2_SP1_7_Enable ((uint32_t) 1024)
#define EPSII_PDM_1_SGPO_ON_OFF_BITMASK_SGPOBM_3V3_Ch1_MasterEnable ((uint32_t) 2048)
#define EPSII_PDM_1_SGPO_ON_OFF_BITMASK_SGPOBM_3V3_Ch1_SP2_5_Enable ((uint32_t) 4096)
#define EPSII_PDM_1_SGPO_ON_OFF_BITMASK_SGPOBM_3V3_Ch1_SP2_6_Enable ((uint32_t) 8192)
#define EPSII_PDM_1_SGPO_ON_OFF_BITMASK_SGPOBM_3V3_Ch1_SP2_7_Enable ((uint32_t) 16384)
#define EPSII_PDM_1_SGPO_ON_OFF_BITMASK_SGPOBM_3V3_Ch2_MasterEnable ((uint32_t) 32768)
#define EPSII_PDM_1_SGPO_ON_OFF_BITMASK_MAX_CNT  ((uint32_t) 32769)
typedef uint32_t EPSII_PDM_1_SGPO_ON_Off_Bitmask_t;

typedef struct {
    int32_t i32ActiveCPU_RunningTime;
    int32_t i32ActiveCPU_Voltage;
    int32_t i32ActiveCPU_Temperature;
    int32_t i32PCB_Temperature_1;
    int32_t i32PCB_Temperature_2;
    int32_t i32NVM_AllocatedSize;
    int32_t i32NVM_UsedSize;
    int32_t i32Stack_AllocatedSize;
    int32_t i32Stack_UsedSize;
    EPSII_PDM_1_EDHI_ChipStatus_t eDPOT_MCP4562_LUP_3V3_1P;
    EPSII_PDM_1_EDHI_ChipStatus_t eDPOT_MCP4562_LUP_3V3_1R;
    EPSII_PDM_1_EDHI_ChipStatus_t eDPOT_MCP4562_LUP_3V3_2P;
    EPSII_PDM_1_EDHI_ChipStatus_t eDPOT_MCP4562_LUP_3V3_2R;
    EPSII_PDM_1_EDHI_ChipStatus_t eDPOT_MCP4562_LUP_5V_1P;
    EPSII_PDM_1_EDHI_ChipStatus_t eDPOT_MCP4562_LUP_5V_1R;
    EPSII_PDM_1_EDHI_ChipStatus_t eDPOT_MCP4562_LUP_5V_2P;
    EPSII_PDM_1_EDHI_ChipStatus_t eDPOT_MCP4562_LUP_5V_2R;
    EPSII_PDM_1_EDHI_ChipStatus_t eDPOT_MCP4562_LUP_12V_P;
    EPSII_PDM_1_EDHI_ChipStatus_t eDPOT_MCP4562_LUP_12V_R;
    EPSII_PDM_1_EDHI_ChipStatus_t eDPOT_MCP4562_OUTU_12V_P;
    EPSII_PDM_1_EDHI_ChipStatus_t eDPOT_MCP4562_OUTU_12V_R;
    EPSII_PDM_1_EDHI_ChipStatus_t eGPIO_PCA9538_U1001;
    EPSII_PDM_1_EDHI_ChipStatus_t eGPIO_PCA9538_U1000;
    EPSII_PDM_1_EDHI_ChipStatus_t eGPIO_PCA9538_U1004;
    EPSII_PDM_1_EDHI_ChipStatus_t eGPIO_PCA9538_U1011;
    EPSII_PDM_1_EDHI_ChipStatus_t eINA_LUP_IN_3V3_1P;
    EPSII_PDM_1_EDHI_ChipStatus_t eINA_LUP_IN_3V3_1R;
    EPSII_PDM_1_EDHI_ChipStatus_t eINA_LUP_IN_3V3_2P;
    EPSII_PDM_1_EDHI_ChipStatus_t eINA_LUP_IN_3V3_2R;
    EPSII_PDM_1_EDHI_ChipStatus_t eINA_LUP_IN_5V_1P;
    EPSII_PDM_1_EDHI_ChipStatus_t eINA_LUP_IN_5V_1R;
    EPSII_PDM_1_EDHI_ChipStatus_t eINA_LUP_IN_5V_2P;
    EPSII_PDM_1_EDHI_ChipStatus_t eINA_LUP_IN_5V_2R;
    EPSII_PDM_1_EDHI_ChipStatus_t eINA_LUP_IN_12V_P;
    EPSII_PDM_1_EDHI_ChipStatus_t eINA_LUP_IN_12V_R;
    EPSII_PDM_1_EDHI_ChipStatus_t eTMP117_U1014;
    EPSII_PDM_1_EDHI_ChipStatus_t eTMP117_U1031;
} PACKED_STRUCT EPSII_PDM_1_SGetDeviceHealthInfo_t;

typedef struct {
    int32_t i32In_SysBUS_Voltage;
    EPSII_PDM_1_ESEPSII_UIP_t sOut_BatRAW_Output_Sense;
    EPSII_PDM_1_ESEPSII_UIP_t sOut_12V_Output_Sense;
    int32_t i32Out_12V_Output_ILimit;
    EPSII_PDM_1_ESEPSII_UIP_t sOut_5V_Output1_Sense;
    int32_t i32Out_5V_Output1_ILimit;
    EPSII_PDM_1_ESEPSII_UIP_t sOut_5V_Output2_Sense;
    int32_t i32Out_5V_Output2_ILimit;
    EPSII_PDM_1_ESEPSII_UIP_t sOut_3V3_Output1_Sense;
    int32_t i32Out_3V3_Output1_ILimit;
    EPSII_PDM_1_ESEPSII_UIP_t sOut_3V3_Output2_Sense;
    int32_t i32Out_3V3_Output2_ILimit;
} PACKED_STRUCT EPSII_PDM_1_SPowerDistributionInfo_t;


typedef struct {
    EPSII_PDM_1_SGGPIO_Bitmask_t eFilterMask;
    EPSII_PDM_1_SGGPIO_OnOff_mask_t eValuesMaskReq;
} PACKED_STRUCT EPSII_PDM_1SetPC104GPIORequestData_t;

typedef struct {
    uint32_t u32PktIDReq;
    EPSII_PDM_1_ESEPSII_PDM_SensorIDs_t aeSensorsIDs[50];
} PACKED_STRUCT EPSII_PDM_1GetRAWSensorsRequestData_t;

typedef struct {
    EPSII_PDM_1_SGPO_Bitmask_t eFilterMask;
    EPSII_PDM_1_SGPO_ON_Off_Bitmask_t eValuesMask;
} PACKED_STRUCT EPSII_PDM_1SetPowerOutputsRequestData_t;


typedef struct {
    EPSII_PDM_1_SPowerDistributionInfo_t sPowerDistributionInfo;
} PACKED_STRUCT EPSII_PDM_1GetPowerDistributionInfoResponseData_t;

typedef struct {
    EPSII_PDM_1_SGetDeviceHealthInfo_t sGetDeviceHealthInfo;
} PACKED_STRUCT EPSII_PDM_1GetDeviceHealthInfoResponseData_t;

typedef struct {
    EPSII_PDM_1_SGGPIO_SetError_t eErr;
} PACKED_STRUCT EPSII_PDM_1SetPC104GPIOResponseData_t;

typedef struct {
    uint8_t u8CurrentValues;
} PACKED_STRUCT EPSII_PDM_1GetPC104GPIOResponseData_t;

typedef struct {
    uint32_t u32PktID;
    int32_t ai32SensorValues[50];
} PACKED_STRUCT EPSII_PDM_1GetRAWSensorsResponseData_t;

typedef struct {
    EPSII_PDM_1_SGPO_SetError_t eErr;
} PACKED_STRUCT EPSII_PDM_1SetPowerOutputsResponseData_t;

typedef struct {
    uint32_t u32ValuesMask;
} PACKED_STRUCT EPSII_PDM_1GetPowerOutputsResponseData_t;


#endif  // #ifndef FP_EPSII_PDM_1PROTOCOLTYPES_H

