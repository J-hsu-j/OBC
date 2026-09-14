/*!
********************************************************************************************
* @file FP_eps_iii_pdm_aProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface eps_iii_pdm_a v2.0
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

#ifndef FP_EPS_III_PDM_APROTOCOLTYPES_H
#define FP_EPS_III_PDM_APROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_EPS_III_PDM_A ((uint16_t) (0x000000A4))

#define EPS_III_PDM_A_GET_TELEMETRY_FUNC_ID ((funcIdType_t) 0x00000000)
#define EPS_III_PDM_A_EXTERNAL_SYSTEM_BUS_CONTROL_FUNC_ID ((funcIdType_t) 0x00000020)
#define EPS_III_PDM_A_LOW_VOLT_CONTROL_FUNC_ID ((funcIdType_t) 0x00000030)
#define EPS_III_PDM_A_GET_TELEMETRY_FUNCRESP_ID ((funcIdType_t) 0x00000000)
#define EPS_III_PDM_A_EXTERNAL_SYSTEM_BUS_CONTROL_FUNCRESP_ID ((funcIdType_t) 0x00000020)
#define EPS_III_PDM_A_LOW_VOLT_CONTROL_FUNCRESP_ID ((funcIdType_t) 0x00000030)

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
} PACKED_STRUCT EPS_III_PDM_A_CommonMesurements_t;

/*
    Current status of the channel. OFF, ON or unknown
*/
#define EPS_III_PDM_A_ONOFFSTATUS_OFF ((uint8_t) 0)
#define EPS_III_PDM_A_ONOFFSTATUS_ON ((uint8_t) 1)
#define EPS_III_PDM_A_ONOFFSTATUS_UNKNOWN ((uint8_t) 2)
#define EPS_III_PDM_A_ONOFFSTATUS_MAX_CNT  ((uint8_t) 3)
typedef uint8_t EPS_III_PDM_A_OnOffStatus_t;

/*
    Read status
*/
#define EPS_III_PDM_A_READENDFTSTATUS_OFF ((uint8_t) 0)
#define EPS_III_PDM_A_READENDFTSTATUS_ON ((uint8_t) 1)
#define EPS_III_PDM_A_READENDFTSTATUS_OFF_FOR_TIME ((uint8_t) 2)
#define EPS_III_PDM_A_READENDFTSTATUS_ON_FOR_TIME ((uint8_t) 3)
#define EPS_III_PDM_A_READENDFTSTATUS_TOGGLE_BUSY_OFF_FOR_TIME ((uint8_t) 4)
#define EPS_III_PDM_A_READENDFTSTATUS_TOGGLE_BUSY_ON_FOR_TIME ((uint8_t) 5)
#define EPS_III_PDM_A_READENDFTSTATUS_DEFAULT_OFF ((uint8_t) 6)
#define EPS_III_PDM_A_READENDFTSTATUS_DEFAULT_ON ((uint8_t) 7)
#define EPS_III_PDM_A_READENDFTSTATUS_DEFAULT_KEEP_LAST ((uint8_t) 8)
#define EPS_III_PDM_A_READENDFTSTATUS_WRONG_INPUT ((uint8_t) 9)
#define EPS_III_PDM_A_READENDFTSTATUS_MAX_CNT  ((uint8_t) 10)
typedef uint8_t EPS_III_PDM_A_ReadEnDftStatus_t;

/*
    Voltage and Current measurements
*/
typedef struct {
    uint16_t u16Voltage;
    int16_t i16Current;
} PACKED_STRUCT EPS_III_PDM_A_VoltAmps_t;

/*
    Low Voltage Interconnection converter channel ID
*/
#define EPS_III_PDM_A_LOWVOLTAGECHANNELS_CHANNEL_3V3 ((uint8_t) 0)
#define EPS_III_PDM_A_LOWVOLTAGECHANNELS_CHANNEL_5V ((uint8_t) 1)
#define EPS_III_PDM_A_LOWVOLTAGECHANNELS_CHANNEL_12V ((uint8_t) 2)
#define EPS_III_PDM_A_LOWVOLTAGECHANNELS_MAX_CNT  ((uint8_t) 3)
typedef uint8_t EPS_III_PDM_A_LowVoltageChannels_t;

/*
    Command status
*/
#define EPS_III_PDM_A_COMMANDSTATUS_SUCCESS ((uint8_t) 0)
#define EPS_III_PDM_A_COMMANDSTATUS_FAIL ((uint8_t) 1)
#define EPS_III_PDM_A_COMMANDSTATUS_FAIL_GATHERING_DATA ((uint8_t) 2)
#define EPS_III_PDM_A_COMMANDSTATUS_MAX_CNT  ((uint8_t) 3)
typedef uint8_t EPS_III_PDM_A_CommandStatus_t;

/*
    Seconds converted into days, hours, minutes, and seconds
*/
typedef struct {
    uint16_t u16Days;
    uint8_t u8Hours;
    uint8_t u8Minutes;
    uint8_t u8Seconds;
} PACKED_STRUCT EPS_III_PDM_A_UptimeConverted_t;

/*
    Voltage and Current measurements
*/
typedef struct {
    uint16_t u16Ch_voltage;
    int16_t i16In_current;
    int16_t i16Out_current;
} PACKED_STRUCT EPS_III_PDM_A_VoltAllAmps_t;

/*
    All Channel options available for control
*/
#define EPS_III_PDM_A_CHANNELOPT_READ_STATUS ((uint8_t) 0)
#define EPS_III_PDM_A_CHANNELOPT_SET_OFF ((uint8_t) 1)
#define EPS_III_PDM_A_CHANNELOPT_SET_ON ((uint8_t) 2)
#define EPS_III_PDM_A_CHANNELOPT_TOGGLE_FOR_TIME ((uint8_t) 3)
#define EPS_III_PDM_A_CHANNELOPT_READ_DEFAULT ((uint8_t) 4)
#define EPS_III_PDM_A_CHANNELOPT_SET_DEFAULT_OFF ((uint8_t) 5)
#define EPS_III_PDM_A_CHANNELOPT_SET_DEFAULT_ON ((uint8_t) 6)
#define EPS_III_PDM_A_CHANNELOPT_SET_DEFAULT_KEEP_LAST ((uint8_t) 7)
#define EPS_III_PDM_A_CHANNELOPT_MAX_CNT  ((uint8_t) 8)
typedef uint8_t EPS_III_PDM_A_ChannelOpt_t;

/*
    All IN and OUT Faults status
*/
typedef struct {
    EPS_III_PDM_A_OnOffStatus_t eFlt_ext_sys_bus;
    EPS_III_PDM_A_OnOffStatus_t eFlt_in_3v3_bus;
    EPS_III_PDM_A_OnOffStatus_t eFlt_out_3v3_bus;
    EPS_III_PDM_A_OnOffStatus_t eFlt_in_5v_bus;
    EPS_III_PDM_A_OnOffStatus_t eFlt_out_5v_bus;
    EPS_III_PDM_A_OnOffStatus_t eFlt_in_12v_bus;
    EPS_III_PDM_A_OnOffStatus_t eFlt_out_12v_bus;
} PACKED_STRUCT EPS_III_PDM_A_FaultsStatus_t;

/*
    Outputs status for 3.3V 5V 12V and external system bus channels
*/
typedef struct {
    EPS_III_PDM_A_ReadEnDftStatus_t eEn_ext_sys_bus;
    EPS_III_PDM_A_ReadEnDftStatus_t eEn_3v3_bus_in;
    EPS_III_PDM_A_ReadEnDftStatus_t eEn_3v3_bus_out;
    EPS_III_PDM_A_ReadEnDftStatus_t eEn_5v_bus_in;
    EPS_III_PDM_A_ReadEnDftStatus_t eEn_5v_bus_out;
    EPS_III_PDM_A_ReadEnDftStatus_t eEn_12v_bus_in;
    EPS_III_PDM_A_ReadEnDftStatus_t eEn_12v_bus_out;
} PACKED_STRUCT EPS_III_PDM_A_OutputsStatus_t;

/*
    Voltage and Current measurements
*/
typedef struct {
    EPS_III_PDM_A_VoltAmps_t sSystem_bus;
    EPS_III_PDM_A_VoltAmps_t sExt_sys_bus;
    EPS_III_PDM_A_VoltAllAmps_t sBus_3v3;
    EPS_III_PDM_A_VoltAllAmps_t sBus_5v;
    EPS_III_PDM_A_VoltAllAmps_t sBus_12v;
} PACKED_STRUCT EPS_III_PDM_A_VoltAmpsMeasurements_t;


typedef struct {
    EPS_III_PDM_A_ChannelOpt_t eExt_sys_bus_option;
    uint16_t u16Ext_sys_bus_time;
} PACKED_STRUCT eps_iii_pdm_aexternal_system_bus_controlRequestData_t;

typedef struct {
    EPS_III_PDM_A_LowVoltageChannels_t eLow_volt_ch;
    EPS_III_PDM_A_ChannelOpt_t eLow_volt_option;
    uint16_t u16Low_volt_time;
} PACKED_STRUCT eps_iii_pdm_alow_volt_controlRequestData_t;


typedef struct {
    EPS_III_PDM_A_CommandStatus_t eCommand_status;
    uint32_t u32Uptime_in_seconds;
    EPS_III_PDM_A_UptimeConverted_t sUptime_converted;
    EPS_III_PDM_A_CommonMesurements_t sCommon;
    EPS_III_PDM_A_OnOffStatus_t eHib_mode;
    EPS_III_PDM_A_OutputsStatus_t sGeneral_outputs;
    EPS_III_PDM_A_FaultsStatus_t sGeneral_faults;
    EPS_III_PDM_A_VoltAmpsMeasurements_t sAll_measurments;
} PACKED_STRUCT eps_iii_pdm_aget_telemetryResponseData_t;

typedef struct {
    EPS_III_PDM_A_CommandStatus_t eCommand_status;
    EPS_III_PDM_A_ReadEnDftStatus_t eExt_sys_bus_status;
    uint16_t u16Timer;
    EPS_III_PDM_A_OnOffStatus_t eExt_sys_bus_fault;
    EPS_III_PDM_A_VoltAmps_t sExt_sys_bus_measurements;
} PACKED_STRUCT eps_iii_pdm_aexternal_system_bus_controlResponseData_t;

typedef struct {
    EPS_III_PDM_A_CommandStatus_t eCommand_status;
    EPS_III_PDM_A_ReadEnDftStatus_t eLow_volt_status;
    uint16_t u16Timer;
    EPS_III_PDM_A_OnOffStatus_t eIn_fault_status;
    EPS_III_PDM_A_OnOffStatus_t eOut_fault_status;
    EPS_III_PDM_A_VoltAllAmps_t sLow_volt_measurements;
} PACKED_STRUCT eps_iii_pdm_alow_volt_controlResponseData_t;


#endif  // #ifndef FP_EPS_III_PDM_APROTOCOLTYPES_H

