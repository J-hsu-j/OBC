/*!
********************************************************************************************
* @file FP_eps_iii_expanderProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface eps_iii_expander v2.0
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

#ifndef FP_EPS_III_EXPANDERPROTOCOLTYPES_H
#define FP_EPS_III_EXPANDERPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_EPS_III_EXPANDER ((uint16_t) (0x000000AC))

#define EPS_III_EXPANDER_GET_TELEMETRY_FUNC_ID ((funcIdType_t) 0x00000000)
#define EPS_III_EXPANDER_H1_CHANNELS_CONTROL_FUNC_ID ((funcIdType_t) 0x00000020)
#define EPS_III_EXPANDER_GPIO_CONTROL_FUNC_ID ((funcIdType_t) 0x00000030)
#define EPS_III_EXPANDER_INTERCONNECT_CONTROL_FUNC_ID ((funcIdType_t) 0x00000040)
#define EPS_III_EXPANDER_RELEASE_5V_FUNC_ID ((funcIdType_t) 0x00000050)
#define EPS_III_EXPANDER_RELEASE_CONTROL_FUNC_ID ((funcIdType_t) 0x00000060)
#define EPS_III_EXPANDER_GET_TELEMETRY_FUNCRESP_ID ((funcIdType_t) 0x00000000)
#define EPS_III_EXPANDER_H1_CHANNELS_CONTROL_FUNCRESP_ID ((funcIdType_t) 0x00000020)
#define EPS_III_EXPANDER_GPIO_CONTROL_FUNCRESP_ID ((funcIdType_t) 0x00000030)
#define EPS_III_EXPANDER_INTERCONNECT_CONTROL_FUNCRESP_ID ((funcIdType_t) 0x00000040)
#define EPS_III_EXPANDER_RELEASE_5V_FUNCRESP_ID ((funcIdType_t) 0x00000050)
#define EPS_III_EXPANDER_RELEASE_CONTROL_FUNCRESP_ID ((funcIdType_t) 0x00000060)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    General Output Channel ID
*/
#define EPS_III_EXPANDER_GPIOCHANNELID_GPIO_1 ((uint8_t) 0)
#define EPS_III_EXPANDER_GPIOCHANNELID_GPIO_2 ((uint8_t) 1)
#define EPS_III_EXPANDER_GPIOCHANNELID_GPIO_3 ((uint8_t) 2)
#define EPS_III_EXPANDER_GPIOCHANNELID_GPIO_4 ((uint8_t) 3)
#define EPS_III_EXPANDER_GPIOCHANNELID_GPIO_5 ((uint8_t) 4)
#define EPS_III_EXPANDER_GPIOCHANNELID_GPIO_6 ((uint8_t) 5)
#define EPS_III_EXPANDER_GPIOCHANNELID_GPIO_7 ((uint8_t) 6)
#define EPS_III_EXPANDER_GPIOCHANNELID_GPIO_8 ((uint8_t) 7)
#define EPS_III_EXPANDER_GPIOCHANNELID_MAX_CNT  ((uint8_t) 8)
typedef uint8_t EPS_III_EXPANDER_GPIOChannelId_t;

/*
    Read status
*/
#define EPS_III_EXPANDER_READRLSTATUS_OFF ((uint8_t) 0)
#define EPS_III_EXPANDER_READRLSTATUS_ON_FOR_TIME ((uint8_t) 1)
#define EPS_III_EXPANDER_READRLSTATUS_WRONG_INPUT ((uint8_t) 2)
#define EPS_III_EXPANDER_READRLSTATUS_MAX_CNT  ((uint8_t) 3)
typedef uint8_t EPS_III_EXPANDER_ReadRlStatus_t;

/*
    Common measurement
*/
typedef struct {
    uint16_t u16Mcu_volt;
    int32_t i32Mcu_temp;
    uint16_t u16Sys_bus_volt;
} PACKED_STRUCT EPS_III_EXPANDER_CommonMesurments_t;

/*
    Channel option
*/
#define EPS_III_EXPANDER_CHANNELOPT_READ_STATUS ((uint8_t) 0)
#define EPS_III_EXPANDER_CHANNELOPT_SET_OFF ((uint8_t) 1)
#define EPS_III_EXPANDER_CHANNELOPT_SET_ON ((uint8_t) 2)
#define EPS_III_EXPANDER_CHANNELOPT_TOGGLE_FOR_TIME ((uint8_t) 3)
#define EPS_III_EXPANDER_CHANNELOPT_READ_DEFAULT ((uint8_t) 4)
#define EPS_III_EXPANDER_CHANNELOPT_SET_DEFAULT_OFF ((uint8_t) 5)
#define EPS_III_EXPANDER_CHANNELOPT_SET_DEFAULT_ON ((uint8_t) 6)
#define EPS_III_EXPANDER_CHANNELOPT_SET_DEFAULT_KEEP_LAST ((uint8_t) 7)
#define EPS_III_EXPANDER_CHANNELOPT_MAX_CNT  ((uint8_t) 8)
typedef uint8_t EPS_III_EXPANDER_ChannelOpt_t;

/*
    Interconnection Channel ID
*/
#define EPS_III_EXPANDER_INTERCCHANNELID_INTERCONNECT_3V3 ((uint8_t) 0)
#define EPS_III_EXPANDER_INTERCCHANNELID_INTERCONNECT_5V ((uint8_t) 1)
#define EPS_III_EXPANDER_INTERCCHANNELID_INTERCONNECT_12V ((uint8_t) 2)
#define EPS_III_EXPANDER_INTERCCHANNELID_INTERCONNECT_BATTERY ((uint8_t) 3)
#define EPS_III_EXPANDER_INTERCCHANNELID_MAX_CNT  ((uint8_t) 4)
typedef uint8_t EPS_III_EXPANDER_IntercChannelId_t;

/*
    Release connector ID
*/
#define EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_1_A ((uint8_t) 0)
#define EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_1_B ((uint8_t) 1)
#define EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_1_AB ((uint8_t) 2)
#define EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_2_A ((uint8_t) 3)
#define EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_2_B ((uint8_t) 4)
#define EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_2_AB ((uint8_t) 5)
#define EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_3_A ((uint8_t) 6)
#define EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_3_B ((uint8_t) 7)
#define EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_3_AB ((uint8_t) 8)
#define EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_4_A ((uint8_t) 9)
#define EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_4_B ((uint8_t) 10)
#define EPS_III_EXPANDER_RCHANNELID_RELEASE_CONNECTOR_4_AB ((uint8_t) 11)
#define EPS_III_EXPANDER_RCHANNELID_MAX_CNT  ((uint8_t) 12)
typedef uint8_t EPS_III_EXPANDER_RChannelId_t;

/*
    Read enable status
*/
#define EPS_III_EXPANDER_READENDFTSTATUS_OFF ((uint8_t) 0)
#define EPS_III_EXPANDER_READENDFTSTATUS_ON ((uint8_t) 1)
#define EPS_III_EXPANDER_READENDFTSTATUS_OFF_FOR_TIME ((uint8_t) 2)
#define EPS_III_EXPANDER_READENDFTSTATUS_ON_FOR_TIME ((uint8_t) 3)
#define EPS_III_EXPANDER_READENDFTSTATUS_TOGGLE_BUSY_OFF_FOR_TIME ((uint8_t) 4)
#define EPS_III_EXPANDER_READENDFTSTATUS_TOGGLE_BUSY_ON_FOR_TIME ((uint8_t) 5)
#define EPS_III_EXPANDER_READENDFTSTATUS_DEFAULT_OFF ((uint8_t) 6)
#define EPS_III_EXPANDER_READENDFTSTATUS_DEFAULT_ON ((uint8_t) 7)
#define EPS_III_EXPANDER_READENDFTSTATUS_DEFAULT_KEEP_LAST ((uint8_t) 8)
#define EPS_III_EXPANDER_READENDFTSTATUS_WRONG_INPUT ((uint8_t) 9)
#define EPS_III_EXPANDER_READENDFTSTATUS_MAX_CNT  ((uint8_t) 10)
typedef uint8_t EPS_III_EXPANDER_ReadEnDftStatus_t;

/*
    Release connector ID
*/
#define EPS_III_EXPANDER_R5VCHANNELID_RELEASE_CONNECTOR_1_5V ((uint8_t) 0)
#define EPS_III_EXPANDER_R5VCHANNELID_RELEASE_CONNECTOR_2_5V ((uint8_t) 1)
#define EPS_III_EXPANDER_R5VCHANNELID_RELEASE_CONNECTOR_3_5V ((uint8_t) 2)
#define EPS_III_EXPANDER_R5VCHANNELID_RELEASE_CONNECTOR_4_5V ((uint8_t) 3)
#define EPS_III_EXPANDER_R5VCHANNELID_MAX_CNT  ((uint8_t) 4)
typedef uint8_t EPS_III_EXPANDER_R5VChannelId_t;

/*
    Voltage and Current measurement
*/
typedef struct {
    uint16_t u16Voltage;
    int16_t i16Current;
} PACKED_STRUCT EPS_III_EXPANDER_VoltAmps_t;

/*
    High and low H1 Channel ID
*/
#define EPS_III_EXPANDER_HLVCHANNELID_LV_H1_47_48 ((uint8_t) 0)
#define EPS_III_EXPANDER_HLVCHANNELID_HV_H1_47_48 ((uint8_t) 1)
#define EPS_III_EXPANDER_HLVCHANNELID_LV_H1_49_50 ((uint8_t) 2)
#define EPS_III_EXPANDER_HLVCHANNELID_HV_H1_49_50 ((uint8_t) 3)
#define EPS_III_EXPANDER_HLVCHANNELID_LV_H1_51_52 ((uint8_t) 4)
#define EPS_III_EXPANDER_HLVCHANNELID_HV_H1_51_52 ((uint8_t) 5)
#define EPS_III_EXPANDER_HLVCHANNELID_MAX_CNT  ((uint8_t) 6)
typedef uint8_t EPS_III_EXPANDER_HLVChannelId_t;

/*
    Read level state
*/
#define EPS_III_EXPANDER_READLVLSTATE_LOW ((uint8_t) 0)
#define EPS_III_EXPANDER_READLVLSTATE_HIGH ((uint8_t) 1)
#define EPS_III_EXPANDER_READLVLSTATE_UNKNOWN ((uint8_t) 2)
#define EPS_III_EXPANDER_READLVLSTATE_MAX_CNT  ((uint8_t) 3)
typedef uint8_t EPS_III_EXPANDER_ReadLvlState_t;

/*
    Command status
*/
#define EPS_III_EXPANDER_COMMANDSTATUS_SUCCESS ((uint8_t) 0)
#define EPS_III_EXPANDER_COMMANDSTATUS_FAIL ((uint8_t) 1)
#define EPS_III_EXPANDER_COMMANDSTATUS_FAIL_GATHERING_DATA ((uint8_t) 2)
#define EPS_III_EXPANDER_COMMANDSTATUS_MAX_CNT  ((uint8_t) 3)
typedef uint8_t EPS_III_EXPANDER_CommandStatus_t;

/*
    Seconds converted into days, hours, minutes, and seconds
*/
typedef struct {
    uint16_t u16Days;
    uint8_t u8Hours;
    uint8_t u8Minutes;
    uint8_t u8Seconds;
} PACKED_STRUCT EPS_III_EXPANDER_UptimeConverted_t;

/*
    Release Channel ID
*/
#define EPS_III_EXPANDER_RCHANNELOPT_READ_STATUS ((uint8_t) 0)
#define EPS_III_EXPANDER_RCHANNELOPT_SET_OFF ((uint8_t) 1)
#define EPS_III_EXPANDER_RCHANNELOPT_SET_ON_FOR_TIME ((uint8_t) 2)
#define EPS_III_EXPANDER_RCHANNELOPT_SET_ON_FOR_TIME_MAX ((uint8_t) 3)
#define EPS_III_EXPANDER_RCHANNELOPT_MAX_CNT  ((uint8_t) 4)
typedef uint8_t EPS_III_EXPANDER_RChannelOpt_t;

/*
    Release A or B connector status
*/
typedef struct {
    EPS_III_EXPANDER_ReadRlStatus_t eRl_a_b_status;
    uint16_t u16Rl_timer;
} PACKED_STRUCT EPS_III_EXPANDER_ReleaseSts_t;

/*
    The status of All Feedback channels
*/
typedef struct {
    EPS_III_EXPANDER_ReadEnDftStatus_t eLv_h1_47_48;
    EPS_III_EXPANDER_ReadEnDftStatus_t eHv_h1_47_48;
    EPS_III_EXPANDER_ReadEnDftStatus_t eLv_h1_49_50;
    EPS_III_EXPANDER_ReadEnDftStatus_t eHv_h1_49_50;
    EPS_III_EXPANDER_ReadEnDftStatus_t eLv_h1_51_52;
    EPS_III_EXPANDER_ReadEnDftStatus_t eHv_h1_51_52;
    EPS_III_EXPANDER_ReadEnDftStatus_t eInterconnect_battery;
    EPS_III_EXPANDER_ReadEnDftStatus_t eInterconnect_3v3;
    EPS_III_EXPANDER_ReadEnDftStatus_t eInterconnect_5v;
    EPS_III_EXPANDER_ReadEnDftStatus_t eInterconnect_12v;
    EPS_III_EXPANDER_ReadEnDftStatus_t eGeneral_output_1;
    EPS_III_EXPANDER_ReadEnDftStatus_t eGeneral_output_2;
    EPS_III_EXPANDER_ReadEnDftStatus_t eGeneral_output_3;
    EPS_III_EXPANDER_ReadEnDftStatus_t eGeneral_output_4;
    EPS_III_EXPANDER_ReadEnDftStatus_t eGeneral_output_5;
    EPS_III_EXPANDER_ReadEnDftStatus_t eGeneral_output_6;
    EPS_III_EXPANDER_ReadEnDftStatus_t eGeneral_output_7;
    EPS_III_EXPANDER_ReadEnDftStatus_t eGeneral_output_8;
    EPS_III_EXPANDER_ReadEnDftStatus_t eRelease_1;
    EPS_III_EXPANDER_ReadEnDftStatus_t eRelease_2;
    EPS_III_EXPANDER_ReadEnDftStatus_t eRelease_3;
    EPS_III_EXPANDER_ReadEnDftStatus_t eRelease_4;
    EPS_III_EXPANDER_ReadEnDftStatus_t eRelease_a1;
    EPS_III_EXPANDER_ReadEnDftStatus_t eRelease_b1;
    EPS_III_EXPANDER_ReadEnDftStatus_t eRelease_a2;
    EPS_III_EXPANDER_ReadEnDftStatus_t eRelease_b2;
    EPS_III_EXPANDER_ReadEnDftStatus_t eRelease_a3;
    EPS_III_EXPANDER_ReadEnDftStatus_t eRelease_b3;
    EPS_III_EXPANDER_ReadEnDftStatus_t eRelease_a4;
    EPS_III_EXPANDER_ReadEnDftStatus_t eRelease_b4;
} PACKED_STRUCT EPS_III_EXPANDER_DigitalOutputs_t;

/*
    Release 5V status and measurements
*/
typedef struct {
    EPS_III_EXPANDER_ReadEnDftStatus_t eRl_5v_status;
    uint16_t u16Rl_5v_timer;
    uint16_t u16Rl_voltage;
    int16_t i16Rl_current;
} PACKED_STRUCT EPS_III_EXPANDER_Release5vSts_t;

/*
    Voltage and Current measurements
*/
typedef struct {
    EPS_III_EXPANDER_VoltAmps_t sL_h1_47_48;
    EPS_III_EXPANDER_VoltAmps_t sH_h1_47_48;
    EPS_III_EXPANDER_VoltAmps_t sL_h1_49_50;
    EPS_III_EXPANDER_VoltAmps_t sH_h1_49_50;
    EPS_III_EXPANDER_VoltAmps_t sL_h1_51_52;
    EPS_III_EXPANDER_VoltAmps_t sH_h1_51_52;
    EPS_III_EXPANDER_VoltAmps_t sRelease1;
    EPS_III_EXPANDER_VoltAmps_t sRelease2;
    EPS_III_EXPANDER_VoltAmps_t sRelease3;
    EPS_III_EXPANDER_VoltAmps_t sRelease4;
    EPS_III_EXPANDER_VoltAmps_t sInterc_3v3;
    EPS_III_EXPANDER_VoltAmps_t sInterc_5v;
    EPS_III_EXPANDER_VoltAmps_t sInterc_12v;
    EPS_III_EXPANDER_VoltAmps_t sInterc_battery;
} PACKED_STRUCT EPS_III_EXPANDER_CurrentLimiters_t;

/*
    The level state of all Feedbacks
*/
typedef struct {
    EPS_III_EXPANDER_ReadLvlState_t eFeedback_1_1;
    EPS_III_EXPANDER_ReadLvlState_t eFeedback_1_2;
    EPS_III_EXPANDER_ReadLvlState_t eFeedback_2_1;
    EPS_III_EXPANDER_ReadLvlState_t eFeedback_2_2;
    EPS_III_EXPANDER_ReadLvlState_t eFeedback_3_1;
    EPS_III_EXPANDER_ReadLvlState_t eFeedback_3_2;
    EPS_III_EXPANDER_ReadLvlState_t eFeedback_4_1;
    EPS_III_EXPANDER_ReadLvlState_t eFeedback_4_2;
} PACKED_STRUCT EPS_III_EXPANDER_Feedback_t;

/*
    The level state of all General inputs
*/
typedef struct {
    EPS_III_EXPANDER_ReadLvlState_t eGeneral_input_1;
    EPS_III_EXPANDER_ReadLvlState_t eGeneral_input_2;
    EPS_III_EXPANDER_ReadLvlState_t eGeneral_input_3;
    EPS_III_EXPANDER_ReadLvlState_t eGeneral_input_4;
    EPS_III_EXPANDER_ReadLvlState_t eGeneral_input_5;
    EPS_III_EXPANDER_ReadLvlState_t eGeneral_input_6;
    EPS_III_EXPANDER_ReadLvlState_t eGeneral_input_7;
    EPS_III_EXPANDER_ReadLvlState_t eGeneral_input_8;
} PACKED_STRUCT EPS_III_EXPANDER_GeneralInput_t;


typedef struct {
    EPS_III_EXPANDER_HLVChannelId_t eH1_channel;
    EPS_III_EXPANDER_ChannelOpt_t eH1_option;
    uint16_t u16H1_time;
} PACKED_STRUCT eps_iii_expanderh1_channels_controlRequestData_t;

typedef struct {
    EPS_III_EXPANDER_GPIOChannelId_t eGo_channel;
    EPS_III_EXPANDER_ChannelOpt_t eGo_option;
    uint16_t u16Go_time;
} PACKED_STRUCT eps_iii_expandergpio_controlRequestData_t;

typedef struct {
    EPS_III_EXPANDER_IntercChannelId_t eIc_channel;
    EPS_III_EXPANDER_ChannelOpt_t eIc_option;
    uint16_t u16Ic_time;
} PACKED_STRUCT eps_iii_expanderinterconnect_controlRequestData_t;

typedef struct {
    EPS_III_EXPANDER_R5VChannelId_t eRl_5v_channel;
    EPS_III_EXPANDER_ChannelOpt_t eRl_5v_option;
    uint16_t u16Rl_5v_time;
} PACKED_STRUCT eps_iii_expanderrelease_5vRequestData_t;

typedef struct {
    EPS_III_EXPANDER_RChannelId_t eRl_channel;
    EPS_III_EXPANDER_RChannelOpt_t eRl_option;
    uint16_t u16Rl_time;
} PACKED_STRUCT eps_iii_expanderrelease_controlRequestData_t;


typedef struct {
    EPS_III_EXPANDER_CommandStatus_t eCommand_status;
    uint32_t u32Uptime_in_seconds;
    EPS_III_EXPANDER_UptimeConverted_t sUptime_converted;
    EPS_III_EXPANDER_CommonMesurments_t sCommon;
    EPS_III_EXPANDER_DigitalOutputs_t sOutputs;
    EPS_III_EXPANDER_GeneralInput_t sGeneral_inputs;
    EPS_III_EXPANDER_Feedback_t sFeedbacks;
    EPS_III_EXPANDER_CurrentLimiters_t sVolt_amp_mesurments;
} PACKED_STRUCT eps_iii_expanderget_telemetryResponseData_t;

typedef struct {
    EPS_III_EXPANDER_CommandStatus_t eCommand_status;
    EPS_III_EXPANDER_ReadEnDftStatus_t eH1_status;
    uint16_t u16H1_timer;
    EPS_III_EXPANDER_VoltAmps_t sH1_mesurment;
} PACKED_STRUCT eps_iii_expanderh1_channels_controlResponseData_t;

typedef struct {
    EPS_III_EXPANDER_CommandStatus_t eCommand_status;
    EPS_III_EXPANDER_ReadEnDftStatus_t eGpio_input_state;
    uint16_t u16Go_timer;
    EPS_III_EXPANDER_ReadLvlState_t eGpio_output_state;
} PACKED_STRUCT eps_iii_expandergpio_controlResponseData_t;

typedef struct {
    EPS_III_EXPANDER_CommandStatus_t eCommand_status;
    EPS_III_EXPANDER_ReadEnDftStatus_t eInterc_status;
    uint16_t u16Timer;
    EPS_III_EXPANDER_VoltAmps_t sInterc_mesurment;
} PACKED_STRUCT eps_iii_expanderinterconnect_controlResponseData_t;

typedef struct {
    EPS_III_EXPANDER_CommandStatus_t eCommand_status;
    EPS_III_EXPANDER_Release5vSts_t sRl_5v_data;
} PACKED_STRUCT eps_iii_expanderrelease_5vResponseData_t;

typedef struct {
    EPS_III_EXPANDER_CommandStatus_t eCommand_status;
    EPS_III_EXPANDER_ReleaseSts_t sA_status;
    EPS_III_EXPANDER_ReleaseSts_t sB_status;
    EPS_III_EXPANDER_ReadLvlState_t eFb_1_state;
    EPS_III_EXPANDER_ReadLvlState_t eFb_2_state;
    EPS_III_EXPANDER_Release5vSts_t sRl_5v_data;
} PACKED_STRUCT eps_iii_expanderrelease_controlResponseData_t;


#endif  // #ifndef FP_EPS_III_EXPANDERPROTOCOLTYPES_H

