/*!
********************************************************************************************
* @file FP_eps_iii_pdm_bProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface eps_iii_pdm_b v2.0
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

#ifndef FP_EPS_III_PDM_BPROTOCOLTYPES_H
#define FP_EPS_III_PDM_BPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_EPS_III_PDM_B ((uint16_t) (0x000000A8))

#define EPS_III_PDM_B_GET_TELEMETRY_FUNC_ID ((funcIdType_t) 0x00000000)
#define EPS_III_PDM_B_A_B_CONTROL_FUNC_ID ((funcIdType_t) 0x00000020)
#define EPS_III_PDM_B_GET_TELEMETRY_FUNCRESP_ID ((funcIdType_t) 0x00000000)
#define EPS_III_PDM_B_A_B_CONTROL_FUNCRESP_ID ((funcIdType_t) 0x00000020)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    Current status of the channel. OFF, ON or unknown
*/
#define EPS_III_PDM_B_ONOFFSTATUS_OFF ((uint8_t) 0)
#define EPS_III_PDM_B_ONOFFSTATUS_ON ((uint8_t) 1)
#define EPS_III_PDM_B_ONOFFSTATUS_UNKNOWN ((uint8_t) 2)
#define EPS_III_PDM_B_ONOFFSTATUS_MAX_CNT  ((uint8_t) 3)
typedef uint8_t EPS_III_PDM_B_OnOffStatus_t;

/*
    Channel ID
*/
#define EPS_III_PDM_B_A_B_CHANNELS_BUS_A ((uint8_t) 0)
#define EPS_III_PDM_B_A_B_CHANNELS_BUS_B ((uint8_t) 1)
#define EPS_III_PDM_B_A_B_CHANNELS_BUS_A_B ((uint8_t) 2)
#define EPS_III_PDM_B_A_B_CHANNELS_MAX_CNT  ((uint8_t) 3)
typedef uint8_t EPS_III_PDM_B_A_B_Channels_t;

/*
    Voltage and Current measurements
*/
typedef struct {
    uint16_t u16Ch_voltage;
    int16_t i16In_current;
    int16_t i16Out_current;
} PACKED_STRUCT EPS_III_PDM_B_VoltAllAmps_t;

/*
    All Channel options available for control
*/
#define EPS_III_PDM_B_CHANNELOPT_READ_STATUS ((uint8_t) 0)
#define EPS_III_PDM_B_CHANNELOPT_SET_OFF ((uint8_t) 1)
#define EPS_III_PDM_B_CHANNELOPT_SET_ON ((uint8_t) 2)
#define EPS_III_PDM_B_CHANNELOPT_TOGGLE_FOR_TIME ((uint8_t) 3)
#define EPS_III_PDM_B_CHANNELOPT_READ_DEFAULT ((uint8_t) 4)
#define EPS_III_PDM_B_CHANNELOPT_SET_DEFAULT_OFF ((uint8_t) 5)
#define EPS_III_PDM_B_CHANNELOPT_SET_DEFAULT_ON ((uint8_t) 6)
#define EPS_III_PDM_B_CHANNELOPT_SET_DEFAULT_KEEP_LAST ((uint8_t) 7)
#define EPS_III_PDM_B_CHANNELOPT_MAX_CNT  ((uint8_t) 8)
typedef uint8_t EPS_III_PDM_B_ChannelOpt_t;

/*
    Temperature data
*/
typedef struct {
    int32_t i32Temp_bus_a;
    int32_t i32Temp_bus_b;
} PACKED_STRUCT EPS_III_PDM_B_Temps_t;

/*
    Common measurements
*/
typedef struct {
    uint16_t u16Mcu_volt;
    int32_t i32Mcu_temp;
    uint16_t u16Sys_bus_volt;
} PACKED_STRUCT EPS_III_PDM_B_CommonMesurements_t;

/*
    Read status
*/
#define EPS_III_PDM_B_READENDFTSTATUS_OFF ((uint8_t) 0)
#define EPS_III_PDM_B_READENDFTSTATUS_ON ((uint8_t) 1)
#define EPS_III_PDM_B_READENDFTSTATUS_OFF_FOR_TIME ((uint8_t) 2)
#define EPS_III_PDM_B_READENDFTSTATUS_ON_FOR_TIME ((uint8_t) 3)
#define EPS_III_PDM_B_READENDFTSTATUS_TOGGLE_BUSY_OFF_FOR_TIME ((uint8_t) 4)
#define EPS_III_PDM_B_READENDFTSTATUS_TOGGLE_BUSY_ON_FOR_TIME ((uint8_t) 5)
#define EPS_III_PDM_B_READENDFTSTATUS_DEFAULT_OFF ((uint8_t) 6)
#define EPS_III_PDM_B_READENDFTSTATUS_DEFAULT_ON ((uint8_t) 7)
#define EPS_III_PDM_B_READENDFTSTATUS_DEFAULT_KEEP_LAST ((uint8_t) 8)
#define EPS_III_PDM_B_READENDFTSTATUS_WRONG_INPUT ((uint8_t) 9)
#define EPS_III_PDM_B_READENDFTSTATUS_MAX_CNT  ((uint8_t) 10)
typedef uint8_t EPS_III_PDM_B_ReadEnDftStatus_t;

/*
    Voltage and Current measurements
*/
typedef struct {
    uint16_t u16Voltage;
    int16_t i16Current;
} PACKED_STRUCT EPS_III_PDM_B_VoltAmps_t;

/*
    Command status
*/
#define EPS_III_PDM_B_COMMANDSTATUS_SUCCESS ((uint8_t) 0)
#define EPS_III_PDM_B_COMMANDSTATUS_FAIL ((uint8_t) 1)
#define EPS_III_PDM_B_COMMANDSTATUS_FAIL_GATHERING_DATA ((uint8_t) 2)
#define EPS_III_PDM_B_COMMANDSTATUS_MAX_CNT  ((uint8_t) 3)
typedef uint8_t EPS_III_PDM_B_CommandStatus_t;

/*
    Seconds converted into days, hours, minutes, and seconds
*/
typedef struct {
    uint16_t u16Days;
    uint8_t u8Hours;
    uint8_t u8Minutes;
    uint8_t u8Seconds;
} PACKED_STRUCT EPS_III_PDM_B_UptimeConverted_t;

/*
    All Input and Output channel flag state
*/
typedef struct {
    EPS_III_PDM_B_OnOffStatus_t eA_input_current_state;
    EPS_III_PDM_B_OnOffStatus_t eA_output_current_state;
    EPS_III_PDM_B_OnOffStatus_t eA_input_voltage_state;
    EPS_III_PDM_B_OnOffStatus_t eA_output_voltage_state;
    EPS_III_PDM_B_OnOffStatus_t eB_input_current_state;
    EPS_III_PDM_B_OnOffStatus_t eB_output_current_state;
    EPS_III_PDM_B_OnOffStatus_t eB_input_voltage_state;
    EPS_III_PDM_B_OnOffStatus_t eB_output_voltage_state;
} PACKED_STRUCT EPS_III_PDM_B_ChannelFlagState_t;

/*
    Status of A and B Outputs
*/
typedef struct {
    EPS_III_PDM_B_ReadEnDftStatus_t eEn_a_in_bus;
    EPS_III_PDM_B_ReadEnDftStatus_t eEn_a_out_bus;
    EPS_III_PDM_B_ReadEnDftStatus_t eEn_b_in_bus;
    EPS_III_PDM_B_ReadEnDftStatus_t eEn_b_out_bus;
} PACKED_STRUCT EPS_III_PDM_B_OutputsStatus_t;

/*
    Channel A or B data
*/
typedef struct {
    EPS_III_PDM_B_ReadEnDftStatus_t eChannel_status;
    uint16_t u16Timer;
    EPS_III_PDM_B_OnOffStatus_t eInput_current_state;
    EPS_III_PDM_B_OnOffStatus_t eOutput_current_state;
    EPS_III_PDM_B_OnOffStatus_t eInput_voltage_state;
    EPS_III_PDM_B_OnOffStatus_t eOutput_voltage_state;
    uint16_t u16Ch_voltage;
    int16_t i16In_current;
    int16_t i16Out_current;
} PACKED_STRUCT EPS_III_PDM_B_ChannelData_t;

/*
    Voltage and Current measurements
*/
typedef struct {
    EPS_III_PDM_B_VoltAmps_t sSystem_bus;
    EPS_III_PDM_B_VoltAllAmps_t sBus_a;
    EPS_III_PDM_B_VoltAllAmps_t sBus_b;
} PACKED_STRUCT EPS_III_PDM_B_VoltAmpsMeasurements_t;


typedef struct {
    EPS_III_PDM_B_A_B_Channels_t eChannel_id;
    EPS_III_PDM_B_ChannelOpt_t eChannel_opt;
    uint16_t u16Channel_opt_time;
} PACKED_STRUCT eps_iii_pdm_bA_B_controlRequestData_t;


typedef struct {
    EPS_III_PDM_B_CommandStatus_t eCommand_status;
    uint32_t u32Uptime_in_seconds;
    EPS_III_PDM_B_UptimeConverted_t sUptime_converted;
    EPS_III_PDM_B_CommonMesurements_t sCommon;
    EPS_III_PDM_B_OnOffStatus_t eHib_mode;
    EPS_III_PDM_B_OutputsStatus_t sGeneral_outputs;
    EPS_III_PDM_B_ChannelFlagState_t sChannel_flag_state;
    EPS_III_PDM_B_Temps_t sTemperature;
    EPS_III_PDM_B_VoltAmpsMeasurements_t sAll_measurments;
} PACKED_STRUCT eps_iii_pdm_bget_telemetryResponseData_t;

typedef struct {
    EPS_III_PDM_B_CommandStatus_t eCommand_status;
    EPS_III_PDM_B_ChannelData_t sData_a_channel;
    EPS_III_PDM_B_ChannelData_t sData_b_channel;
} PACKED_STRUCT eps_iii_pdm_bA_B_controlResponseData_t;


#endif  // #ifndef FP_EPS_III_PDM_BPROTOCOLTYPES_H

