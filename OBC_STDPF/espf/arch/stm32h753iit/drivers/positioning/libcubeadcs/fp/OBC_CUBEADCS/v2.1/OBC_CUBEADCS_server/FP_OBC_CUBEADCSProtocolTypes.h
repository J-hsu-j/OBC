/*!
********************************************************************************************
* @file FP_OBC_CUBEADCSProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface OBC_CUBEADCS v2.1
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

#ifndef FP_OBC_CUBEADCSPROTOCOLTYPES_H
#define FP_OBC_CUBEADCSPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_OBC_CUBEADCS ((uint16_t) (0x00000011))

#define OBC_CUBEADCS_GETCOMMISSIONINGSTATUS_FUNC_ID ((funcIdType_t) 0x00000003)
#define OBC_CUBEADCS_SETCOMMISSIONINGSTATUS_FUNC_ID ((funcIdType_t) 0x00000004)
#define OBC_CUBEADCS_GETGENERICTLM_FUNC_ID ((funcIdType_t) 0x00000005)
#define OBC_CUBEADCS_SENDGENERICTC_FUNC_ID ((funcIdType_t) 0x00000006)
#define OBC_CUBEADCS_GETOPSTATUS_FUNC_ID ((funcIdType_t) 0x00000007)
#define OBC_CUBEADCS_RESET_FUNC_ID ((funcIdType_t) 0x00000008)
#define OBC_CUBEADCS_CLRERRFLAGS_FUNC_ID ((funcIdType_t) 0x00000009)
#define OBC_CUBEADCS_STARTFILETRANSFER_FUNC_ID ((funcIdType_t) 0x0000000A)
#define OBC_CUBEADCS_POLLFILETRANSFERSTATUS_FUNC_ID ((funcIdType_t) 0x0000000B)
#define OBC_CUBEADCS_CLEARRUNTIMELATCHEDERRS_FUNC_ID ((funcIdType_t) 0x00000011)
#define OBC_CUBEADCS_CLEARFAULTYNODESTATUS_FUNC_ID ((funcIdType_t) 0x00000013)
#define OBC_CUBEADCS_STARTFILELISTDOWNLOAD_FUNC_ID ((funcIdType_t) 0x00000014)
#define OBC_CUBEADCS_POLLFILELISTDOWNLOADSTATUS_FUNC_ID ((funcIdType_t) 0x00000015)
#define OBC_CUBEADCS_GETADCSSYSSTATE_FUNC_ID ((funcIdType_t) 0x00000016)
#define OBC_CUBEADCS_SETADCSSYSSTATE_FUNC_ID ((funcIdType_t) 0x00000017)
#define OBC_CUBEADCS_GETADCSUNIXTIME_FUNC_ID ((funcIdType_t) 0x00000018)
#define OBC_CUBEADCS_UPDATEADCSUNIXTIME_FUNC_ID ((funcIdType_t) 0x00000019)
#define OBC_CUBEADCS_SETENABLEERRHANDLLOGIC_FUNC_ID ((funcIdType_t) 0x0000001A)
#define OBC_CUBEADCS_GETENABLEERRHANDLLOGIC_FUNC_ID ((funcIdType_t) 0x0000001B)
#define OBC_CUBEADCS_SETSTABLEPOINTINGTHRESHOLDS_FUNC_ID ((funcIdType_t) 0x0000001C)
#define OBC_CUBEADCS_GETSTABLEPOINTINGTHRESHOLDS_FUNC_ID ((funcIdType_t) 0x0000001D)
#define OBC_CUBEADCS_SETSIMULATIONMODE_FUNC_ID ((funcIdType_t) 0x0000001E)
#define OBC_CUBEADCS_GETSIMULATIONMODEVALUE_FUNC_ID ((funcIdType_t) 0x0000001F)
#define OBC_CUBEADCS_GETOBCCOMMANDERRCOUNTERS_FUNC_ID ((funcIdType_t) 0x00000020)
#define OBC_CUBEADCS_CLROBCCOMMANDERRCOUNTERS_FUNC_ID ((funcIdType_t) 0x00000021)
#define OBC_CUBEADCS_GETFDIRCOUNERS_FUNC_ID ((funcIdType_t) 0x00000022)
#define OBC_CUBEADCS_CLRFDIRCOUNTERS_FUNC_ID ((funcIdType_t) 0x00000023)
#define OBC_CUBEADCS_STOPFILETRANSFER_FUNC_ID ((funcIdType_t) 0x00000024)
#define OBC_CUBEADCS_GETRUNTIMELATCHEDERRS_FUNC_ID ((funcIdType_t) 0x00000025)
#define OBC_CUBEADCS_GETFAULTYNODESTATUS_FUNC_ID ((funcIdType_t) 0x00000026)
#define OBC_CUBEADCS_SETSYSTEMSTATECFG_FUNC_ID ((funcIdType_t) 0x00000027)
#define OBC_CUBEADCS_GETSYSTEMSTATECFG_FUNC_ID ((funcIdType_t) 0x00000028)
#define OBC_CUBEADCS_GETCOMMISSIONINGSTATUS_FUNCRESP_ID ((funcIdType_t) 0x00000003)
#define OBC_CUBEADCS_SETCOMMISSIONINGSTATUS_FUNCRESP_ID ((funcIdType_t) 0x00000004)
#define OBC_CUBEADCS_GETGENERICTLM_FUNCRESP_ID ((funcIdType_t) 0x00000005)
#define OBC_CUBEADCS_SENDGENERICTC_FUNCRESP_ID ((funcIdType_t) 0x00000006)
#define OBC_CUBEADCS_GETOPSTATUS_FUNCRESP_ID ((funcIdType_t) 0x00000007)
#define OBC_CUBEADCS_RESET_FUNCRESP_ID ((funcIdType_t) 0x00000008)
#define OBC_CUBEADCS_CLRERRFLAGS_FUNCRESP_ID ((funcIdType_t) 0x00000009)
#define OBC_CUBEADCS_STARTFILETRANSFER_FUNCRESP_ID ((funcIdType_t) 0x0000000A)
#define OBC_CUBEADCS_POLLFILETRANSFERSTATUS_FUNCRESP_ID ((funcIdType_t) 0x0000000B)
#define OBC_CUBEADCS_CLEARRUNTIMELATCHEDERRS_FUNCRESP_ID ((funcIdType_t) 0x00000011)
#define OBC_CUBEADCS_CLEARFAULTYNODESTATUS_FUNCRESP_ID ((funcIdType_t) 0x00000013)
#define OBC_CUBEADCS_STARTFILELISTDOWNLOAD_FUNCRESP_ID ((funcIdType_t) 0x00000014)
#define OBC_CUBEADCS_POLLFILELISTDOWNLOADSTATUS_FUNCRESP_ID ((funcIdType_t) 0x00000015)
#define OBC_CUBEADCS_GETADCSSYSSTATE_FUNCRESP_ID ((funcIdType_t) 0x00000016)
#define OBC_CUBEADCS_SETADCSSYSSTATE_FUNCRESP_ID ((funcIdType_t) 0x00000017)
#define OBC_CUBEADCS_GETADCSUNIXTIME_FUNCRESP_ID ((funcIdType_t) 0x00000018)
#define OBC_CUBEADCS_UPDATEADCSUNIXTIME_FUNCRESP_ID ((funcIdType_t) 0x00000019)
#define OBC_CUBEADCS_SETENABLEERRHANDLLOGIC_FUNCRESP_ID ((funcIdType_t) 0x0000001A)
#define OBC_CUBEADCS_GETENABLEERRHANDLLOGIC_FUNCRESP_ID ((funcIdType_t) 0x0000001B)
#define OBC_CUBEADCS_SETSTABLEPOINTINGTHRESHOLDS_FUNCRESP_ID ((funcIdType_t) 0x0000001C)
#define OBC_CUBEADCS_GETSTABLEPOINTINGTHRESHOLDS_FUNCRESP_ID ((funcIdType_t) 0x0000001D)
#define OBC_CUBEADCS_SETSIMULATIONMODE_FUNCRESP_ID ((funcIdType_t) 0x0000001E)
#define OBC_CUBEADCS_GETSIMULATIONMODEVALUE_FUNCRESP_ID ((funcIdType_t) 0x0000001F)
#define OBC_CUBEADCS_GETOBCCOMMANDERRCOUNTERS_FUNCRESP_ID ((funcIdType_t) 0x00000020)
#define OBC_CUBEADCS_CLROBCCOMMANDERRCOUNTERS_FUNCRESP_ID ((funcIdType_t) 0x00000021)
#define OBC_CUBEADCS_GETFDIRCOUNERS_FUNCRESP_ID ((funcIdType_t) 0x00000022)
#define OBC_CUBEADCS_CLRFDIRCOUNTERS_FUNCRESP_ID ((funcIdType_t) 0x00000023)
#define OBC_CUBEADCS_STOPFILETRANSFER_FUNCRESP_ID ((funcIdType_t) 0x00000024)
#define OBC_CUBEADCS_GETRUNTIMELATCHEDERRS_FUNCRESP_ID ((funcIdType_t) 0x00000025)
#define OBC_CUBEADCS_GETFAULTYNODESTATUS_FUNCRESP_ID ((funcIdType_t) 0x00000026)
#define OBC_CUBEADCS_SETSYSTEMSTATECFG_FUNCRESP_ID ((funcIdType_t) 0x00000027)
#define OBC_CUBEADCS_GETSYSTEMSTATECFG_FUNCRESP_ID ((funcIdType_t) 0x00000028)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    Communication statuses between OBC and CubeADCS 
    		COMM_OK      		- Successful communication, no errors
    		COMM_ERR 	 		- Unsuccessful communication, unspecified error
    		COMM_CMD_ERR 		- Requested command ID not found in the list of known CubeADCS commands
    		COMM_LEN_WRT_ERR  	- Expected vs given TC command data size mismatch  
    		COMM_LEN_READ_ERR 	- Expected vs received TC/TLM command data size mismatch
    		COMM_RX_TIMEOUT		- Timeout while receiving command request response
    		COMM_TX_TOMEUT		- Command rquest timeout on the commmunication channel (UART, I2C or CAN)
    		COMM_COMM_ERR		- Error while receiving command request reply (wrong start/end sequence, etc.) 
    		COMM_INV_DATA		- Received correct number of bytes but command ID in header is mismatch
*/
#define OBC_CUBEADCS_COMMSTATUS_COMM_OK ((uint8_t) 0)
#define OBC_CUBEADCS_COMMSTATUS_COMM_ERR ((uint8_t) 1)
#define OBC_CUBEADCS_COMMSTATUS_COMM_CMD_ERR ((uint8_t) 2)
#define OBC_CUBEADCS_COMMSTATUS_COMM_LEN_WRT_ERR ((uint8_t) 3)
#define OBC_CUBEADCS_COMMSTATUS_COMM_LEN_READ_ERR ((uint8_t) 4)
#define OBC_CUBEADCS_COMMSTATUS_COMM_RX_TIMEOUT ((uint8_t) 5)
#define OBC_CUBEADCS_COMMSTATUS_COMM_TX_TIMEOUT ((uint8_t) 6)
#define OBC_CUBEADCS_COMMSTATUS_COMM_COMM_ERR ((uint8_t) 7)
#define OBC_CUBEADCS_COMMSTATUS_COMM_INV_DATA ((uint8_t) 8)
#define OBC_CUBEADCS_COMMSTATUS_MAX_CNT  ((uint8_t) 9)
typedef uint8_t OBC_CUBEADCS_CommStatus_t;

#define OBC_CUBEADCS_ADCSSYSSTATES_PWR_UP ((uint8_t) 0)
#define OBC_CUBEADCS_ADCSSYSSTATES_NORMAL_DETUMBLING ((uint8_t) 1)
#define OBC_CUBEADCS_ADCSSYSSTATES_Y_THOMSON ((uint8_t) 2)
#define OBC_CUBEADCS_ADCSSYSSTATES_Y_THOMSON_MEMS_RATE ((uint8_t) 3)
#define OBC_CUBEADCS_ADCSSYSSTATES_FAST_DETUMB ((uint8_t) 4)
#define OBC_CUBEADCS_ADCSSYSSTATES_VERY_FAST_DETUMB ((uint8_t) 5)
#define OBC_CUBEADCS_ADCSSYSSTATES_Y_MOMENTUM ((uint8_t) 6)
#define OBC_CUBEADCS_ADCSSYSSTATES_Y_MOMENTUM_FULL_STATE ((uint8_t) 7)
#define OBC_CUBEADCS_ADCSSYSSTATES_THREE_AXIS ((uint8_t) 8)
#define OBC_CUBEADCS_ADCSSYSSTATES_SUN_TRACKING ((uint8_t) 9)
#define OBC_CUBEADCS_ADCSSYSSTATES_TARGET_TRACKING ((uint8_t) 10)
#define OBC_CUBEADCS_ADCSSYSSTATES_NO_CONTROL ((uint8_t) 11)
#define OBC_CUBEADCS_ADCSSYSSTATES_ATTITUDE_CHANGE ((uint8_t) 12)
#define OBC_CUBEADCS_ADCSSYSSTATES_ORBITAL_CHANGE ((uint8_t) 13)
#define OBC_CUBEADCS_ADCSSYSSTATES_GEO_TARGET_TRACKING ((uint8_t) 14)
#define OBC_CUBEADCS_ADCSSYSSTATES_MAX_CNT  ((uint8_t) 15)
typedef uint8_t OBC_CUBEADCS_ADCSSysStates_t;

#define OBC_CUBEADCS_CUBE_ADCS_TC_13_CONTROL_MODE_CUBE_ADCS_TC_13_CONTROLMODE_NO_CNTRL ((uint8_t) 0)
#define OBC_CUBEADCS_CUBE_ADCS_TC_13_CONTROL_MODE_CUBE_ADCS_TC_13_CONTROLMODE_DETUMB_CNTRL ((uint8_t) 1)
#define OBC_CUBEADCS_CUBE_ADCS_TC_13_CONTROL_MODE_CUBE_ADCS_TC_13_CONTROLMODE_Y_THOMPSON ((uint8_t) 2)
#define OBC_CUBEADCS_CUBE_ADCS_TC_13_CONTROL_MODE_CUBE_ADCS_TC_13_CONTROLMODE_Y_WHEEL_INITIAL ((uint8_t) 3)
#define OBC_CUBEADCS_CUBE_ADCS_TC_13_CONTROL_MODE_CUBE_ADCS_TC_13_CONTROLMODE_Y_WHEEL_STEADY ((uint8_t) 4)
#define OBC_CUBEADCS_CUBE_ADCS_TC_13_CONTROL_MODE_CUBE_ADCS_TC_13_CONTROLMODE_XYZ_WHEEL_CNTRL ((uint8_t) 5)
#define OBC_CUBEADCS_CUBE_ADCS_TC_13_CONTROL_MODE_CUBE_ADCS_TC_13_CONTROLMODE_RWHEEL_SUN_TRACKING ((uint8_t) 6)
#define OBC_CUBEADCS_CUBE_ADCS_TC_13_CONTROL_MODE_CUBE_ADCS_TC_13_CONTROLMODE_RWHEEL_TARGET_TRACKING ((uint8_t) 7)
#define OBC_CUBEADCS_CUBE_ADCS_TC_13_CONTROL_MODE_CUBE_ADCS_TC_13_CONTROLMODE_VERY_FAST_SPIN_DETUMB ((uint8_t) 8)
#define OBC_CUBEADCS_CUBE_ADCS_TC_13_CONTROL_MODE_CUBE_ADCS_TC_13_CONTROLMODE_FAST_SPIN_DETUMB ((uint8_t) 9)
#define OBC_CUBEADCS_CUBE_ADCS_TC_13_CONTROL_MODE_CUBE_ADCS_TC_13_CONTROLMODE_USER_MODE_1 ((uint8_t) 10)
#define OBC_CUBEADCS_CUBE_ADCS_TC_13_CONTROL_MODE_CUBE_ADCS_TC_13_CONTROLMODE_USER_MODE_2 ((uint8_t) 11)
#define OBC_CUBEADCS_CUBE_ADCS_TC_13_CONTROL_MODE_CUBE_ADCS_TC_13_CONTROLMODE_STOP_R_WHEELS ((uint8_t) 12)
#define OBC_CUBEADCS_CUBE_ADCS_TC_13_CONTROL_MODE_CUBE_ADCS_TC_13_CONTROLMODE_USER_CODED_MODE ((uint8_t) 13)
#define OBC_CUBEADCS_CUBE_ADCS_TC_13_CONTROL_MODE_CUBE_ADCS_TC_13_CONTROLMODE_SUN_TRACKING_YAW_OR_ROLL_ONLY ((uint8_t) 14)
#define OBC_CUBEADCS_CUBE_ADCS_TC_13_CONTROL_MODE_CUBE_ADCS_TC_13_CONTROLMODE_TARGET_TRACKING_YAW_ONLY ((uint8_t) 15)
#define OBC_CUBEADCS_CUBE_ADCS_TC_13_CONTROL_MODE_MAX_CNT  ((uint8_t) 16)
typedef uint8_t OBC_CUBEADCS_CUBE_ADCS_TC_13_Control_Mode_t;

typedef struct {
    uint8_t u8TLM_ID;
    uint8_t au8TLM_Data[173];
} PACKED_STRUCT OBC_CUBEADCS_TLMDataFormat_t;

#define OBC_CUBEADCS_COMMISSIONINGSTATUS_NOT_DONE ((uint8_t) 0)
#define OBC_CUBEADCS_COMMISSIONINGSTATUS_COMPLETE ((uint8_t) 1)
#define OBC_CUBEADCS_COMMISSIONINGSTATUS_MAX_CNT  ((uint8_t) 2)
typedef uint8_t OBC_CUBEADCS_CommissioningStatus_t;

#define OBC_CUBEADCS_SAFEBOOL_FALSE ((uint8_t) 0)
#define OBC_CUBEADCS_SAFEBOOL_TRUE ((uint8_t) 255)
#define OBC_CUBEADCS_SAFEBOOL_MAX_CNT  ((uint8_t) 256)
typedef uint8_t OBC_CUBEADCS_SafeBool_t;

typedef struct {
    uint8_t u8TC_ID;
    uint8_t u8TC_Err_flags;
} PACKED_STRUCT OBC_CUBEADCS_TCDataFormat_t;

typedef struct {
    uint8_t u8TC_ID;
    uint8_t au8TC_Data[173];
    uint16_t u16TC_Data_Len;
} PACKED_STRUCT OBC_CUBEADCS_TCReq_t;

#define OBC_CUBEADCS_FWMODE_APPLICATION ((uint8_t) 10)
#define OBC_CUBEADCS_FWMODE_BOOTLOADER ((uint8_t) 110)
#define OBC_CUBEADCS_FWMODE_MAX_CNT  ((uint8_t) 111)
typedef uint8_t OBC_CUBEADCS_FwMode_t;

typedef struct {
    uint8_t u8CmdID;
    uint8_t u8Byte0;
    uint8_t u8Byte1;
    uint8_t u8Byte2;
    uint8_t u8Byte3;
    uint8_t u8Byte4;
    uint8_t u8Byte5;
} PACKED_STRUCT OBC_CUBEADCS_TLM224_t;

#define OBC_CUBEADCS_POWER_SWITCH_OFF ((uint8_t) 0)
#define OBC_CUBEADCS_POWER_SWITCH_ON ((uint8_t) 1)
#define OBC_CUBEADCS_POWER_SWITCH_MAX_CNT  ((uint8_t) 2)
typedef uint8_t OBC_CUBEADCS_power_switch_t;

#define OBC_CUBEADCS_FILETYPES_TLM_LOG ((uint8_t) 2)
#define OBC_CUBEADCS_FILETYPES_JPG_IMG ((uint8_t) 3)
#define OBC_CUBEADCS_FILETYPES_BMP_IMG ((uint8_t) 4)
#define OBC_CUBEADCS_FILETYPES_INDEX ((uint8_t) 15)
#define OBC_CUBEADCS_FILETYPES_MAX_CNT  ((uint8_t) 16)
typedef uint8_t OBC_CUBEADCS_FileTypes_t;

#define OBC_CUBEADCS_CUBE_ADCS_TC_14_ESTIMATION_MODE_CUBE_ADCS_TC_14_ESTIMATIONMODE_NO_EST ((uint8_t) 0)
#define OBC_CUBEADCS_CUBE_ADCS_TC_14_ESTIMATION_MODE_CUBE_ADCS_TC_14_ESTIMATIONMODE_MEMS_RATE_SENS ((uint8_t) 1)
#define OBC_CUBEADCS_CUBE_ADCS_TC_14_ESTIMATION_MODE_CUBE_ADCS_TC_14_ESTIMATIONMODE_MTM_RATE_FILT ((uint8_t) 2)
#define OBC_CUBEADCS_CUBE_ADCS_TC_14_ESTIMATION_MODE_CUBE_ADCS_TC_14_ESTIMATIONMODE_MTM_RATE_FILT_WITH_PITCH ((uint8_t) 3)
#define OBC_CUBEADCS_CUBE_ADCS_TC_14_ESTIMATION_MODE_CUBE_ADCS_TC_14_ESTIMATIONMODE_MTM_FINE_SUN_TRIAD ((uint8_t) 4)
#define OBC_CUBEADCS_CUBE_ADCS_TC_14_ESTIMATION_MODE_CUBE_ADCS_TC_14_ESTIMATIONMODE_FULL_EKF ((uint8_t) 5)
#define OBC_CUBEADCS_CUBE_ADCS_TC_14_ESTIMATION_MODE_CUBE_ADCS_TC_14_ESTIMATIONMODE_MEMS_GYRO_EKF ((uint8_t) 6)
#define OBC_CUBEADCS_CUBE_ADCS_TC_14_ESTIMATION_MODE_CUBE_ADCS_TC_14_ESTIMATIONMODE_USR_CODED ((uint8_t) 7)
#define OBC_CUBEADCS_CUBE_ADCS_TC_14_ESTIMATION_MODE_MAX_CNT  ((uint8_t) 8)
typedef uint8_t OBC_CUBEADCS_CUBE_ADCS_TC_14_Estimation_Mode_t;

#define OBC_CUBEADCS_PROGRAM_INDEX_INT_FLASH_PROG ((uint8_t) 1)
#define OBC_CUBEADCS_PROGRAM_INDEX_BOOTLOADER ((uint8_t) 2)
#define OBC_CUBEADCS_PROGRAM_INDEX_MAX_CNT  ((uint8_t) 3)
typedef uint8_t OBC_CUBEADCS_PROGRAM_Index_t;

typedef struct {
    uint16_t u16COMM_OK;
    uint16_t u16COMM_ERR;
    uint16_t u16COMM_CMD_ERR;
    uint16_t u16COMM_LEN_WRT_ERR;
    uint16_t u16COMM_LEN_READ_ERR;
    uint16_t u16COMM_RX_TIMEOUT;
    uint16_t u16COMM_TX_TIMEOUT;
    uint16_t u16COMM_COMM_ERR;
    uint16_t u16COMM_INV_DATA;
    uint16_t u16CUBESENSE1_COMM_ERR;
    uint16_t u16CUBESENSE2_COMM_ERR;
    uint16_t u16CUBECONTROL_SIGNAL_COMM_ERR;
    uint16_t u16CUBECONTROL_MOTOR_COMM_ERR;
    uint16_t u16CUBEWHEEL1_COMM_ERR;
    uint16_t u16CUBEWHEEL2_COMM_ERR;
    uint16_t u16CUBEWHEEL3_COMM_ERR;
    uint16_t u16CUBESTAR_COMM_ERR;
    uint16_t u16MAGMETER_RANGE_ERR;
    uint16_t u16CAM1_SRAM_OVERCURRENT_DET;
    uint16_t u16CAM1_3V3_OVERCURRENT_DET;
    uint16_t u16CAM1_SENSOR_BUSY_ERR;
    uint16_t u16CAM1_SENSOR_DET_ERR;
    uint16_t u16SUN_SENSOR_RANGE_ERR;
    uint16_t u16CAM2_SRAM_OVERCURRENT_DET;
    uint16_t u16CAM2_3V3_OVERCURRENT_DET;
    uint16_t u16CAM2_SENSOR_BUSY_ERR;
    uint16_t u16CAM2_SENSOR_DET_ERR;
    uint16_t u16NADIR_SENSOR_RANGE_ERR;
    uint16_t u16RATE_SENSOR_RANGE_ERR;
    uint16_t u16WHEEL_SPEED_RANGE_ERR;
    uint16_t u16CSS_ERR;
    uint16_t u16STARTRACKER_MATCH_ERR;
    uint16_t u16STARTRACKER_OVERCURRENT_DET;
    uint16_t u16SRAM_LUP_ERR;
    uint16_t u16SRAM_LUP_ERR_REC;
    uint16_t u16SD_CARD_INIT_ERR;
    uint16_t u16SD_CARD_READ_ERR;
    uint16_t u16SD_CARD_WRT_ERR;
    uint16_t u16EXT_FLASH_ERR;
    uint16_t u16INT_FLASH_ERR;
    uint16_t u16EEPROM_ERR;
    uint16_t u16BOOT_REG_ERR;
    uint16_t u16COMM_RADIO_ERR;
    uint16_t u16ADCS_CONFIG_LOAD_ERR;
    uint16_t u16ORBIT_PARAM_LOAD_ERR;
    uint16_t u16SYS_CONFIG_LOAD_ERR;
    uint16_t u16ORBIT_PARAM_INVALID_ERR;
    uint16_t u16CONFIG_INVALID_ERR;
    uint16_t u16CNTRL_MODE_CHG_INV_ERR;
    uint16_t u16EST_CHG_INV_ERR;
    uint16_t u16MAGNETIC_FIELD_DIFF_ERR;
    uint16_t u16NODE_RECOVERY_ERR;
    uint16_t u16CUBESENSE1_RUNTIME_ERR;
    uint16_t u16CUBESENSE2_RUNTIME_ERR;
    uint16_t u16CUBECONTROL_SIGNAL_RUNTIME_ERR;
    uint16_t u16CUBECONTROL_MOTOR_RUNTIME_ERR;
    uint16_t u16CUBEWHEEL1_RUNTIME_ERR;
    uint16_t u16CUBEWHEEL2_RUNTIME_ERR;
    uint16_t u16CUBEWHEEL3_RUNTIME_ERR;
    uint16_t u16CUBESTAR_RUNTIME_ERR;
    uint16_t u16MAGNETOMETER_ERR;
    uint16_t u16RATE_SENSOR_FAILURE_ERR;
} PACKED_STRUCT OBC_CUBEADCS_ErrCounters_t;

/*
    Check A.4 ACP Interface Version 7 from the Commissioning Manual for more information
*/
typedef struct {
    uint8_t u8NODE_RECOVERY_ERR;
    uint8_t u8MAGMETER_RANGE_ERR;
    uint8_t u8CAM1_SRAM_OVERCURRENT_DET;
    uint8_t u8CAM1_3V3_OVERCURRENT_DET;
    uint8_t u8CAM2_SRAM_OVERCURRENT_DET;
    uint8_t u8CAM2_3V3_OVERCURRENT_DET;
    uint8_t u8STARTRACKER_OVERCURRENT_DET;
    uint8_t u8MAGNETOMETER_ERR;
    uint8_t u8CAM1_SENSOR_BUSY_ERR;
    uint8_t u8CAM2_SENSOR_BUSY_ERR;
    uint8_t u8RATE_SENSOR_RANGE_ERR;
    uint8_t u8WHEEL_SPEED_RANGE_ERR;
    uint8_t u8RATE_SENSOR_FAILURE_ERR;
    uint8_t u8ORBIT_PARAM_INVALID_ERR;
    uint8_t u8CONFIG_INVALID_ERR;
    uint8_t u8CNTRL_MODE_CHG_INV_ERR;
    uint8_t u8EST_CHG_INV_ERR;
} PACKED_STRUCT OBC_CUBEADCS_FDIRCounters_t;

#define OBC_CUBEADCS_CUBE_ADCS_TC_10_RUN_MODE_CUBE_ADCS_TC10_RUNMODE_OFF ((uint8_t) 0)
#define OBC_CUBEADCS_CUBE_ADCS_TC_10_RUN_MODE_CUBE_ADCS_TC10_RUNMODE_ENABLED ((uint8_t) 1)
#define OBC_CUBEADCS_CUBE_ADCS_TC_10_RUN_MODE_CUBE_ADCS_TC10_RUNMODE_TRIGGERED ((uint8_t) 2)
#define OBC_CUBEADCS_CUBE_ADCS_TC_10_RUN_MODE_CUBE_ADCS_TC10_RUNMODE_SIMULATION ((uint8_t) 3)
#define OBC_CUBEADCS_CUBE_ADCS_TC_10_RUN_MODE_MAX_CNT  ((uint8_t) 4)
typedef uint8_t OBC_CUBEADCS_CUBE_ADCS_TC_10_Run_Mode_t;

/*
    CubeADCS TLM129 as per the Firmware Reference Manual
*/
typedef struct {
    uint8_t u8CmdID;
    uint8_t u8ResetAndBoot;
    uint16_t u16BootCnt;
    uint8_t u8BootProgIndx;
    uint8_t u8FWVersionMajor;
    uint8_t u8FWVersionMinor;
} PACKED_STRUCT OBC_CUBEADCS_TLM129_t;

#define OBC_CUBEADCS_FTRANSFSTATUS_DONE ((uint8_t) 0)
#define OBC_CUBEADCS_FTRANSFSTATUS_ERR ((uint8_t) 1)
#define OBC_CUBEADCS_FTRANSFSTATUS_ERR_CRC ((uint8_t) 2)
#define OBC_CUBEADCS_FTRANSFSTATUS_ERR_SDCARD ((uint8_t) 3)
#define OBC_CUBEADCS_FTRANSFSTATUS_BUSY ((uint8_t) 4)
#define OBC_CUBEADCS_FTRANSFSTATUS_STOPPED ((uint8_t) 5)
#define OBC_CUBEADCS_FTRANSFSTATUS_MAX_CNT  ((uint8_t) 6)
typedef uint8_t OBC_CUBEADCS_FTransfStatus_t;

typedef struct {
    uint8_t u8CmdID;
    uint8_t u8Byte0;
    uint8_t u8Byte1;
    uint8_t u8Byte2;
    uint8_t u8Byte3;
    uint8_t u8Byte4;
    uint8_t u8Byte5;
} PACKED_STRUCT OBC_CUBEADCS_TLM132_App_t;

typedef struct {
    uint32_t u32CurrentUnixTime;
    uint16_t u16Milliseconds;
} PACKED_STRUCT OBC_CUBEADCS_UnixTime_t;

typedef struct {
    uint8_t u8CmdID;
    uint8_t u8ACPState;
} PACKED_STRUCT OBC_CUBEADCS_TLM135_t;

typedef struct {
    uint8_t u8BaseCntr;
    uint8_t u8TopCntr;
} PACKED_STRUCT OBC_CUBEADCS_cntrsRange_t;

#define OBC_CUBEADCS_STANDARDRESULT_SUCCESS ((uint8_t) 0)
#define OBC_CUBEADCS_STANDARDRESULT_ERROR ((uint8_t) 1)
#define OBC_CUBEADCS_STANDARDRESULT_INVALID_ARGS ((uint8_t) 2)
#define OBC_CUBEADCS_STANDARDRESULT_NOT_SUPPORTED ((uint8_t) 3)
#define OBC_CUBEADCS_STANDARDRESULT_MAX_CNT  ((uint8_t) 4)
typedef uint8_t OBC_CUBEADCS_StandardResult_t;

#define OBC_CUBEADCS_BOOT_STATUS_NEW_SELECTION ((uint8_t) 0)
#define OBC_CUBEADCS_BOOT_STATUS_BOOT_SUCCESS ((uint8_t) 1)
#define OBC_CUBEADCS_BOOT_STATUS_FAILED_BOOT_1 ((uint8_t) 2)
#define OBC_CUBEADCS_BOOT_STATUS_FAILED_BOOT_2 ((uint8_t) 3)
#define OBC_CUBEADCS_BOOT_STATUS_FAILED_BOOT_3 ((uint8_t) 4)
#define OBC_CUBEADCS_BOOT_STATUS_MAX_CNT  ((uint8_t) 5)
typedef uint8_t OBC_CUBEADCS_BOOT_Status_t;

typedef struct {
    OBC_CUBEADCS_CommStatus_t eTLM128;
    OBC_CUBEADCS_CommStatus_t eTLM130;
    OBC_CUBEADCS_CommStatus_t eTLM132;
    OBC_CUBEADCS_CommStatus_t eTLM135;
    OBC_CUBEADCS_CommStatus_t eTLM224;
    OBC_CUBEADCS_CommStatus_t eTLM197;
} PACKED_STRUCT OBC_CUBEADCS_HCheckCommStatus_t;

typedef struct {
    OBC_CUBEADCS_TLMDataFormat_t sTLM_Rply_Data;
    uint16_t u16TLM_Rply_Len;
} PACKED_STRUCT OBC_CUBEADCS_TLMReqReply_t;

typedef struct {
    OBC_CUBEADCS_TCDataFormat_t sTCData;
    uint16_t u16TC_Rply_Len;
} PACKED_STRUCT OBC_CUBEADCS_TCReqReply_t;

typedef struct {
    OBC_CUBEADCS_power_switch_t eCubeControl_Signal;
    OBC_CUBEADCS_power_switch_t eCubeControl_Motor;
    OBC_CUBEADCS_power_switch_t eCubeSense1;
    OBC_CUBEADCS_power_switch_t eCubeSense2;
    OBC_CUBEADCS_power_switch_t eCubeStar;
    OBC_CUBEADCS_power_switch_t eCubeWheel1;
    OBC_CUBEADCS_power_switch_t eCubeWheel2;
    OBC_CUBEADCS_power_switch_t eCubeWheel3;
    OBC_CUBEADCS_power_switch_t eMotorPwr;
    OBC_CUBEADCS_power_switch_t eGPSPwr;
} PACKED_STRUCT OBC_CUBEADCS_CUBE_ADCS_CfgNodePwr_t;

typedef struct {
    OBC_CUBEADCS_FileTypes_t eFType;
    uint8_t u8Counter;
    uint16_t u16Crc16;
    uint32_t u32FileSize;
} PACKED_STRUCT OBC_CUBEADCS_FTransfer_FInfo_t;

/*
    CubeADCS TLM130 as per the Firmware Reference Manual
*/
typedef struct {
    uint8_t u8CmdID;
    OBC_CUBEADCS_PROGRAM_Index_t eProgramIndex;
    OBC_CUBEADCS_BOOT_Status_t eBootStatus;
} PACKED_STRUCT OBC_CUBEADCS_TLM130_t;

/*
    Holds the status of the CubeADCS as stored in the OBC
*/
typedef struct {
    OBC_CUBEADCS_CommissioningStatus_t eCommissioning;
    uint8_t u8NodeStatus;
    uint16_t u16RunTimeLatchedErrors;
    OBC_CUBEADCS_HCheckCommStatus_t sHCheclComm;
} PACKED_STRUCT OBC_CUBEADCS_Status_t;

typedef struct {
    OBC_CUBEADCS_ADCSSysStates_t eCfgType;
    OBC_CUBEADCS_CUBE_ADCS_CfgNodePwr_t sNodePwrMask;
    OBC_CUBEADCS_CUBE_ADCS_TC_13_Control_Mode_t eCntrlMask;
    OBC_CUBEADCS_CUBE_ADCS_TC_14_Estimation_Mode_t eEstMode;
    OBC_CUBEADCS_CUBE_ADCS_TC_10_Run_Mode_t eRunMask;
    uint8_t u8AdditionalLogic;
} PACKED_STRUCT OBC_CUBEADCS_CubeADCS_Cfg_t;

/*
    Holds ACP state and ADCS state telemetry frames
*/
typedef struct {
    OBC_CUBEADCS_TLM135_t sACPState;
    OBC_CUBEADCS_TLM132_App_t sADCSState;
    OBC_CUBEADCS_TLM224_t sADCSState2;
    OBC_CUBEADCS_TLM129_t sBootStatus;
    OBC_CUBEADCS_TLM130_t sProgStatus;
} PACKED_STRUCT OBC_CUBEADCS_State_t;

/*
    Holds the operational status of the CubeADCS
*/
typedef struct {
    OBC_CUBEADCS_FwMode_t eMode;
    OBC_CUBEADCS_State_t sState;
    OBC_CUBEADCS_Status_t sStatus;
    OBC_CUBEADCS_CommStatus_t eComm;
} PACKED_STRUCT OBC_CUBEADCS_OpStatus_t;


typedef struct {
    OBC_CUBEADCS_CommissioningStatus_t eStatus;
} PACKED_STRUCT OBC_CUBEADCSsetCommissioningStatusRequestData_t;

typedef struct {
    uint8_t u8TLMID;
} PACKED_STRUCT OBC_CUBEADCSgetGenericTLMRequestData_t;

typedef struct {
    OBC_CUBEADCS_TCReq_t sTCReq_Data;
} PACKED_STRUCT OBC_CUBEADCSsendGenericTCRequestData_t;

typedef struct {
    OBC_CUBEADCS_FwMode_t eMode;
} PACKED_STRUCT OBC_CUBEADCSresetRequestData_t;

typedef struct {
    OBC_CUBEADCS_FTransfer_FInfo_t sFileInfo;
} PACKED_STRUCT OBC_CUBEADCSstartFileTransferRequestData_t;

typedef struct {
    OBC_CUBEADCS_ADCSSysStates_t eSysState;
} PACKED_STRUCT OBC_CUBEADCSsetADCSSysStateRequestData_t;

typedef struct {
    OBC_CUBEADCS_SafeBool_t eEnFlag;
} PACKED_STRUCT OBC_CUBEADCSsetEnableErrHandlLogicRequestData_t;

typedef struct {
    double dStablePointingThresholdAngle;
    double dStablePointingThresholdAngleRate;
} PACKED_STRUCT OBC_CUBEADCSsetStablePointingThresholdsRequestData_t;

typedef struct {
    OBC_CUBEADCS_SafeBool_t eEn_sim_mode;
} PACKED_STRUCT OBC_CUBEADCSsetSimulationModeRequestData_t;

typedef struct {
    OBC_CUBEADCS_cntrsRange_t sRange;
} PACKED_STRUCT OBC_CUBEADCSclrOBCCommAndErrCountersRequestData_t;

typedef struct {
    OBC_CUBEADCS_cntrsRange_t sRange;
} PACKED_STRUCT OBC_CUBEADCSclrFDIRCountersRequestData_t;

typedef struct {
    OBC_CUBEADCS_CubeADCS_Cfg_t asCubeADCS_sys_state_cfg[15];
} PACKED_STRUCT OBC_CUBEADCSsetSystemStateCfgRequestData_t;


typedef struct {
    OBC_CUBEADCS_CommissioningStatus_t eStatus;
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSgetCommissioningStatusResponseData_t;

typedef struct {
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSsetCommissioningStatusResponseData_t;

typedef struct {
    OBC_CUBEADCS_TLMReqReply_t sTLMReq_Reply;
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSgetGenericTLMResponseData_t;

typedef struct {
    OBC_CUBEADCS_TCReqReply_t sTCReq_Reply;
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSsendGenericTCResponseData_t;

typedef struct {
    OBC_CUBEADCS_OpStatus_t sOpStatus;
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSgetOpStatusResponseData_t;

typedef struct {
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSresetResponseData_t;

typedef struct {
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSclrErrFlagsResponseData_t;

typedef struct {
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSstartFileTransferResponseData_t;

typedef struct {
    OBC_CUBEADCS_FTransfStatus_t eStatus;
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSpollFileTransferStatusResponseData_t;

typedef struct {
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSclearRunTimeLatchedErrsResponseData_t;

typedef struct {
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSclearFaultyNodeStatusResponseData_t;

typedef struct {
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSstartFileListDownloadResponseData_t;

typedef struct {
    OBC_CUBEADCS_FTransfStatus_t eStatus;
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSpollFileListDownloadStatusResponseData_t;

typedef struct {
    OBC_CUBEADCS_ADCSSysStates_t eSysState;
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSgetADCSSysStateResponseData_t;

typedef struct {
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSsetADCSSysStateResponseData_t;

typedef struct {
    OBC_CUBEADCS_UnixTime_t sUnixTime;
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSgetADCSUnixTimeResponseData_t;

typedef struct {
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSupdateADCSUnixTimeResponseData_t;

typedef struct {
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSsetEnableErrHandlLogicResponseData_t;

typedef struct {
    OBC_CUBEADCS_SafeBool_t eEnFlag;
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSgetEnableErrHandlLogicResponseData_t;

typedef struct {
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSsetStablePointingThresholdsResponseData_t;

typedef struct {
    double dStablePointingThresholdAngle;
    double dStablePointingThresholdAngleRate;
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSgetStablePointingThresholdsResponseData_t;

typedef struct {
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSsetSimulationModeResponseData_t;

typedef struct {
    OBC_CUBEADCS_SafeBool_t eEn_sim_mode;
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSgetSimulationModeValueResponseData_t;

typedef struct {
    OBC_CUBEADCS_ErrCounters_t sCounters;
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSgetOBCCommAndErrCountersResponseData_t;

typedef struct {
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSclrOBCCommAndErrCountersResponseData_t;

typedef struct {
    OBC_CUBEADCS_FDIRCounters_t sCounters;
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSgetFDIRCounersResponseData_t;

typedef struct {
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSclrFDIRCountersResponseData_t;

typedef struct {
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSstopFileTransferResponseData_t;

typedef struct {
    bool bNodeRecoveryErr;
    bool bRangeErr;
    bool bRateSensFailure;
    bool bMagnetometerErr;
    bool bOrbitParamsErr;
    bool bConfigInvalid;
    bool bCntrlModeChgErr;
    bool bEstModeChgErr;
    bool bSysStateChgErr;
    uint8_t u8Reserved;
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSgetRunTimeLatchedErrsResponseData_t;

typedef struct {
    bool bSignalMCU;
    bool bMotorMCU;
    bool bCubeSense1;
    bool bCubeSense2;
    bool bCubeStar;
    bool bRWheel1;
    bool bRWheel2;
    bool bRWheel3;
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSgetFaultyNodeStatusResponseData_t;

typedef struct {
    OBC_CUBEADCS_StandardResult_t eOpResult;
} PACKED_STRUCT OBC_CUBEADCSsetSystemStateCfgResponseData_t;

typedef struct {
    OBC_CUBEADCS_CubeADCS_Cfg_t asCubeADCS_sys_state_cfg[15];
} PACKED_STRUCT OBC_CUBEADCSgetSystemStateCfgResponseData_t;


#endif  // #ifndef FP_OBC_CUBEADCSPROTOCOLTYPES_H

