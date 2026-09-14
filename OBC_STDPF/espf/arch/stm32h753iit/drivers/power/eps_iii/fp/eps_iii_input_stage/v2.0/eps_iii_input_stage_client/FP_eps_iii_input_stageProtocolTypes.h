/*!
********************************************************************************************
* @file FP_eps_iii_input_stageProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface eps_iii_input_stage v2.0
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

#ifndef FP_EPS_III_INPUT_STAGEPROTOCOLTYPES_H
#define FP_EPS_III_INPUT_STAGEPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_EPS_III_INPUT_STAGE ((uint16_t) (0x000000A0))

#define EPS_III_INPUT_STAGE_GET_TELEMETRY_FUNC_ID ((funcIdType_t) 0x00000000)
#define EPS_III_INPUT_STAGE_GET_TELEMETRY_FUNCRESP_ID ((funcIdType_t) 0x00000000)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    Common measurements
*/
typedef struct {
    uint16_t u16Mcu_volt;
    int32_t i32Mcu_temp;
    uint16_t u16Sys_bus_volt;
} PACKED_STRUCT EPS_III_INPUT_STAGE_CommonMeasurement_t;

/*
    Current status of the channel. OFF, ON or unknown
*/
#define EPS_III_INPUT_STAGE_ONOFFSTATUS_OFF ((uint8_t) 0)
#define EPS_III_INPUT_STAGE_ONOFFSTATUS_ON ((uint8_t) 1)
#define EPS_III_INPUT_STAGE_ONOFFSTATUS_UNKNOWN ((uint8_t) 2)
#define EPS_III_INPUT_STAGE_ONOFFSTATUS_MAX_CNT  ((uint8_t) 3)
typedef uint8_t EPS_III_INPUT_STAGE_OnOffStatus_t;

/*
    Voltage and Current measurements
*/
typedef struct {
    uint16_t u16Voltage;
    int16_t i16Current;
} PACKED_STRUCT EPS_III_INPUT_STAGE_VoltAmps_t;

/*
    Command status
*/
#define EPS_III_INPUT_STAGE_COMMANDSTATUS_SUCCESS ((uint8_t) 0)
#define EPS_III_INPUT_STAGE_COMMANDSTATUS_FAIL ((uint8_t) 1)
#define EPS_III_INPUT_STAGE_COMMANDSTATUS_FAIL_GATHERING_DATA ((uint8_t) 2)
#define EPS_III_INPUT_STAGE_COMMANDSTATUS_MAX_CNT  ((uint8_t) 3)
typedef uint8_t EPS_III_INPUT_STAGE_CommandStatus_t;

/*
    Current mode - low power or normal. Off-line is returned if there is no communication from the chip
*/
#define EPS_III_INPUT_STAGE_MPPTLT8490_MODE_STATUS_NORMAL ((uint16_t) 0)
#define EPS_III_INPUT_STAGE_MPPTLT8490_MODE_STATUS_LOW_POWER ((uint16_t) 1)
#define EPS_III_INPUT_STAGE_MPPTLT8490_MODE_STATUS_OFFLINE ((uint16_t) 2)
#define EPS_III_INPUT_STAGE_MPPTLT8490_MODE_STATUS_MAX_CNT  ((uint16_t) 3)
typedef uint16_t EPS_III_INPUT_STAGE_mpptLT8490_mode_status_t;

/*
    Seconds converted into days, hours, minutes, and seconds
*/
typedef struct {
    uint16_t u16Days;
    uint8_t u8Hours;
    uint8_t u8Minutes;
    uint8_t u8Seconds;
} PACKED_STRUCT EPS_III_INPUT_STAGE_UptimeConverted_t;

/*
    Voltage and Current measurements
*/
typedef struct {
    uint16_t u16Ch_voltage;
    int16_t i16In_current;
    int16_t i16Out_current;
} PACKED_STRUCT EPS_III_INPUT_STAGE_VoltAllAmps_t;

/*
    The stage at which the MPPT is working. Off-line is returned if there is no communication from the chip
*/
#define EPS_III_INPUT_STAGE_MPPTLT8490_OPPERATION_STATUS_STAGE_0 ((uint16_t) 0)
#define EPS_III_INPUT_STAGE_MPPTLT8490_OPPERATION_STATUS_STAGE_1 ((uint16_t) 1)
#define EPS_III_INPUT_STAGE_MPPTLT8490_OPPERATION_STATUS_STAGE_2_OVER_C_5 ((uint16_t) 2)
#define EPS_III_INPUT_STAGE_MPPTLT8490_OPPERATION_STATUS_STAGE_2_UNDER_C_10 ((uint16_t) 3)
#define EPS_III_INPUT_STAGE_MPPTLT8490_OPPERATION_STATUS_STAGE_3 ((uint16_t) 4)
#define EPS_III_INPUT_STAGE_MPPTLT8490_OPPERATION_STATUS_DONE_CHARGING ((uint16_t) 5)
#define EPS_III_INPUT_STAGE_MPPTLT8490_OPPERATION_STATUS_UNKNOWN ((uint16_t) 6)
#define EPS_III_INPUT_STAGE_MPPTLT8490_OPPERATION_STATUS_OFFLINE ((uint16_t) 7)
#define EPS_III_INPUT_STAGE_MPPTLT8490_OPPERATION_STATUS_MAX_CNT  ((uint16_t) 8)
typedef uint16_t EPS_III_INPUT_STAGE_mpptLT8490_opperation_status_t;

/*
    Current active fault. Off-line is returned if there is no communication from the chip
*/
#define EPS_III_INPUT_STAGE_MPPTLT8490_FAULT_STATUS_NO_FAULT ((uint16_t) 0)
#define EPS_III_INPUT_STAGE_MPPTLT8490_FAULT_STATUS_BATT_DISCCONNECT ((uint16_t) 1)
#define EPS_III_INPUT_STAGE_MPPTLT8490_FAULT_STATUS_INVALID_TEMPERATURE ((uint16_t) 2)
#define EPS_III_INPUT_STAGE_MPPTLT8490_FAULT_STATUS_TIMER_FAUILT ((uint16_t) 3)
#define EPS_III_INPUT_STAGE_MPPTLT8490_FAULT_STATUS_BATT_UNDERVOLTAGE ((uint16_t) 4)
#define EPS_III_INPUT_STAGE_MPPTLT8490_FAULT_STATUS_OFFLINE ((uint16_t) 5)
#define EPS_III_INPUT_STAGE_MPPTLT8490_FAULT_STATUS_MAX_CNT  ((uint16_t) 6)
typedef uint16_t EPS_III_INPUT_STAGE_mpptLT8490_fault_status_t;

/*
    state of the MPPT
*/
typedef struct {
    EPS_III_INPUT_STAGE_mpptLT8490_opperation_status_t eStatus;
    EPS_III_INPUT_STAGE_mpptLT8490_fault_status_t eFaults;
    EPS_III_INPUT_STAGE_mpptLT8490_mode_status_t eMode;
} PACKED_STRUCT EPS_III_INPUT_STAGE_MpptState_str_t;

/*
    Solar panel (SP) input data
*/
typedef struct {
    EPS_III_INPUT_STAGE_VoltAllAmps_t sSp_measurements;
    EPS_III_INPUT_STAGE_OnOffStatus_t eInput_current_state;
    EPS_III_INPUT_STAGE_OnOffStatus_t eOutput_current_state;
    EPS_III_INPUT_STAGE_OnOffStatus_t eInput_voltage_state;
    EPS_III_INPUT_STAGE_OnOffStatus_t eOutput_voltage_state;
    EPS_III_INPUT_STAGE_MpptState_str_t sState_mppt;
} PACKED_STRUCT EPS_III_INPUT_STAGE_sp_input_data_t;



typedef struct {
    EPS_III_INPUT_STAGE_CommandStatus_t eCommand_status;
    uint32_t u32Uptime_in_seconds;
    EPS_III_INPUT_STAGE_UptimeConverted_t sUptime_converted;
    EPS_III_INPUT_STAGE_CommonMeasurement_t sCommon;
    EPS_III_INPUT_STAGE_OnOffStatus_t eHib_mode;
    EPS_III_INPUT_STAGE_OnOffStatus_t eSelflock_on;
    EPS_III_INPUT_STAGE_sp_input_data_t sSp1;
    EPS_III_INPUT_STAGE_sp_input_data_t sSp2;
    EPS_III_INPUT_STAGE_sp_input_data_t sSp3;
    EPS_III_INPUT_STAGE_VoltAmps_t sSystem_bus;
    EPS_III_INPUT_STAGE_VoltAmps_t sBus_7v5;
    EPS_III_INPUT_STAGE_OnOffStatus_t eBus_7v5_power_good;
    EPS_III_INPUT_STAGE_OnOffStatus_t eUndervoltage_7V5;
    EPS_III_INPUT_STAGE_VoltAmps_t sBus_3v3;
    EPS_III_INPUT_STAGE_OnOffStatus_t eUndervoltage_3V3;
} PACKED_STRUCT eps_iii_input_stageget_telemetryResponseData_t;


#endif  // #ifndef FP_EPS_III_INPUT_STAGEPROTOCOLTYPES_H

