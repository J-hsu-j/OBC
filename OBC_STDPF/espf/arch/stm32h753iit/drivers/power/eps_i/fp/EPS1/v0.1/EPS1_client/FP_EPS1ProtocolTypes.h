/*!
********************************************************************************************
* @file FP_EPS1ProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface EPS1 v0.1
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

#ifndef FP_EPS1PROTOCOLTYPES_H
#define FP_EPS1PROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_EPS1 ((uint16_t) (0x0000000A))

#define EPS1_GETBATTERYINFO_FUNC_ID ((funcIdType_t) 0x00000001)
#define EPS1_GETCONFIGURATIONINFO_FUNC_ID ((funcIdType_t) 0x00000006)
#define EPS1_QUERYCONTROLS_FUNC_ID ((funcIdType_t) 0x00000007)
#define EPS1_TOGGLEOUTPUT_FUNC_ID ((funcIdType_t) 0x00000014)
#define EPS1_GETBATTERYINFO_FUNCRESP_ID ((funcIdType_t) 0x00000001)
#define EPS1_GETCONFIGURATIONINFO_FUNCRESP_ID ((funcIdType_t) 0x00000006)
#define EPS1_QUERYCONTROLS_FUNCRESP_ID ((funcIdType_t) 0x00000007)
#define EPS1_TOGGLEOUTPUT_FUNCRESP_ID ((funcIdType_t) 0x00000014)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    Helper enum for accessing "queryControls" elements by named index
*/
#define EPS1_QUERYCONTROLSINDEX_SWSelfLock ((uint8_t) 0)
#define EPS1_QUERYCONTROLSINDEX_VBattEn ((uint8_t) 1)
#define EPS1_QUERYCONTROLSINDEX_BCROutEn ((uint8_t) 2)
#define EPS1_QUERYCONTROLSINDEX_SHD_3v3 ((uint8_t) 3)
#define EPS1_QUERYCONTROLSINDEX_SHD_5v ((uint8_t) 4)
#define EPS1_QUERYCONTROLSINDEX_LUP3v3 ((uint8_t) 5)
#define EPS1_QUERYCONTROLSINDEX_LUP5v ((uint8_t) 6)
#define EPS1_QUERYCONTROLSINDEX_SHDChrg ((uint8_t) 7)
#define EPS1_QUERYCONTROLSINDEX_Chrg_I1 ((uint8_t) 8)
#define EPS1_QUERYCONTROLSINDEX_Chrg_I2 ((uint8_t) 9)
#define EPS1_QUERYCONTROLSINDEX_OUT1 ((uint8_t) 10)
#define EPS1_QUERYCONTROLSINDEX_OUT2 ((uint8_t) 11)
#define EPS1_QUERYCONTROLSINDEX_OUT3 ((uint8_t) 12)
#define EPS1_QUERYCONTROLSINDEX_OUT4_OBC ((uint8_t) 13)
#define EPS1_QUERYCONTROLSINDEX_OUT5 ((uint8_t) 14)
#define EPS1_QUERYCONTROLSINDEX_OUT6 ((uint8_t) 15)
#define EPS1_QUERYCONTROLSINDEX_Heater_1 ((uint8_t) 16)
#define EPS1_QUERYCONTROLSINDEX_Heater_2 ((uint8_t) 17)
#define EPS1_QUERYCONTROLSINDEX_Heater_3 ((uint8_t) 18)
#define EPS1_QUERYCONTROLSINDEX_I2C_10k_pu ((uint8_t) 19)
#define EPS1_QUERYCONTROLSINDEX_I2C_4k7_pu ((uint8_t) 20)
#define EPS1_QUERYCONTROLSINDEX_RS485_120R ((uint8_t) 21)
#define EPS1_QUERYCONTROLSINDEX_Reserved ((uint8_t) 22)
#define EPS1_QUERYCONTROLSINDEX_OUT7 ((uint8_t) 23)
#define EPS1_QUERYCONTROLSINDEX_OUT8 ((uint8_t) 24)
#define EPS1_QUERYCONTROLSINDEX_RESET_MPPT ((uint8_t) 25)
#define EPS1_QUERYCONTROLSINDEX_MAX_CNT  ((uint8_t) 26)
typedef uint8_t EPS1_QueryControlsIndex_t;

/*
    Helper description from "queryControls" and "queryDefaults"
*/
#define EPS1_QUERYSTATE_Ignored ((uint8_t) 0)
#define EPS1_QUERYSTATE_Off ((uint8_t) 1)
#define EPS1_QUERYSTATE_On ((uint8_t) 2)
#define EPS1_QUERYSTATE_Default ((uint8_t) 3)
#define EPS1_QUERYSTATE_ForceOff ((uint8_t) 5)
#define EPS1_QUERYSTATE_ForceOn ((uint8_t) 6)
#define EPS1_QUERYSTATE_ValueMask ((uint8_t) 15)
#define EPS1_QUERYSTATE_FlagsMask ((uint8_t) 192)
#define EPS1_QUERYSTATE_Reserved ((uint8_t) 64)
#define EPS1_QUERYSTATE_Mismatch ((uint8_t) 128)
#define EPS1_QUERYSTATE_MAX_CNT  ((uint8_t) 193)
typedef uint8_t EPS1_QueryState_t;

/*
    Helper structure to hold pair voltage/current. The returned values correspond to raw values and shall be calibrated by the user through the following calibration coefficients and formulas (when applicable).
*/
typedef struct {
    uint16_t u16Volt;
    uint16_t u16Curr;
} PACKED_STRUCT EPS1_VA_Pair_t;

/*
    The EPS1 Response structure for Configuration Info Request
*/
typedef struct {
    uint16_t u16InputConditions;
    uint16_t au16OutputConditions[2];
    uint16_t au16DefaultOutputs[2];
} PACKED_STRUCT EPS1_ConfigurationInfo_t;

/*
    The EPS1 Response structure for Battery Info Request
*/
typedef struct {
    EPS1_VA_Pair_t sBatt;
    EPS1_VA_Pair_t sBcr;
    uint16_t u16Reserved;
} PACKED_STRUCT EPS1_BatteryInfo_t;


typedef struct {
    EPS1_QueryState_t aeRequested[26];
} PACKED_STRUCT EPS1queryControlsRequestData_t;

typedef struct {
    EPS1_QueryControlsIndex_t eToggleOutput;
    uint8_t u8TimeAtToggledState;
} PACKED_STRUCT EPS1ToggleOutPutRequestData_t;


typedef struct {
    EPS1_BatteryInfo_t sBattery;
} PACKED_STRUCT EPS1getBatteryInfoResponseData_t;

typedef struct {
    EPS1_ConfigurationInfo_t sConfig;
} PACKED_STRUCT EPS1getConfigurationInfoResponseData_t;

typedef struct {
    EPS1_QueryState_t aeReported[26];
} PACKED_STRUCT EPS1queryControlsResponseData_t;

typedef struct {
    bool bRequestStatus;
    uint8_t u8ActualTimeAtToggledState;
} PACKED_STRUCT EPS1ToggleOutPutResponseData_t;


#endif  // #ifndef FP_EPS1PROTOCOLTYPES_H

