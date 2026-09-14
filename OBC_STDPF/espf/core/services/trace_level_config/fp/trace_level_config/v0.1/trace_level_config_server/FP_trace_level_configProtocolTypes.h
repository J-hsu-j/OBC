/*!
********************************************************************************************
* @file FP_trace_level_configProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface trace_level_config v0.1
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

#ifndef FP_TRACE_LEVEL_CONFIGPROTOCOLTYPES_H
#define FP_TRACE_LEVEL_CONFIGPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_TRACE_LEVEL_CONFIG ((uint16_t) (0x00000105))

#define TRACE_LEVEL_CONFIG_SET_CHANNEL_TRACE_LEVEL_FUNC_ID ((funcIdType_t) 0x00000000)
#define TRACE_LEVEL_CONFIG_GET_CHANNEL_INFO_FUNC_ID ((funcIdType_t) 0x00000001)
#define TRACE_LEVEL_CONFIG_SET_CHANNEL_ACTIVE_STATUS_FUNC_ID ((funcIdType_t) 0x00000002)
#define TRACE_LEVEL_CONFIG_SET_MODULE_ACTIVE_STATUS_FUNC_ID ((funcIdType_t) 0x00000003)
#define TRACE_LEVEL_CONFIG_SET_MODULE_TRACE_LEVEL_FUNC_ID ((funcIdType_t) 0x00000004)
#define TRACE_LEVEL_CONFIG_GET_MODULE_INFO_FUNC_ID ((funcIdType_t) 0x00000005)
#define TRACE_LEVEL_CONFIG_SET_CHANNEL_TRACE_LEVEL_FUNCRESP_ID ((funcIdType_t) 0x00000000)
#define TRACE_LEVEL_CONFIG_GET_CHANNEL_INFO_FUNCRESP_ID ((funcIdType_t) 0x00000001)
#define TRACE_LEVEL_CONFIG_SET_CHANNEL_ACTIVE_STATUS_FUNCRESP_ID ((funcIdType_t) 0x00000002)
#define TRACE_LEVEL_CONFIG_SET_MODULE_ACTIVE_STATUS_FUNCRESP_ID ((funcIdType_t) 0x00000003)
#define TRACE_LEVEL_CONFIG_SET_MODULE_TRACE_LEVEL_FUNCRESP_ID ((funcIdType_t) 0x00000004)
#define TRACE_LEVEL_CONFIG_GET_MODULE_INFO_FUNCRESP_ID ((funcIdType_t) 0x00000005)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    Enumeration containing the list of all trace levels
*/
#define TRACE_LEVEL_CONFIG_TRACELEVELS_DEBUG ((uint8_t) 0)
#define TRACE_LEVEL_CONFIG_TRACELEVELS_INFO ((uint8_t) 1)
#define TRACE_LEVEL_CONFIG_TRACELEVELS_WARN ((uint8_t) 2)
#define TRACE_LEVEL_CONFIG_TRACELEVELS_ERROR ((uint8_t) 3)
#define TRACE_LEVEL_CONFIG_TRACELEVELS_FATAL ((uint8_t) 4)
#define TRACE_LEVEL_CONFIG_TRACELEVELS_MAX_CNT  ((uint8_t) 5)
typedef uint8_t TRACE_LEVEL_CONFIG_TraceLevels_t;

/*
    Enumeration containing the list of all trace channels
*/
#define TRACE_LEVEL_CONFIG_CHANNELS_UART ((uint8_t) 0)
#define TRACE_LEVEL_CONFIG_CHANNELS_FILE ((uint8_t) 1)
#define TRACE_LEVEL_CONFIG_CHANNELS_SWV ((uint8_t) 2)
#define TRACE_LEVEL_CONFIG_CHANNELS_ALL ((uint8_t) 3)
#define TRACE_LEVEL_CONFIG_CHANNELS_MAX_CNT  ((uint8_t) 4)
typedef uint8_t TRACE_LEVEL_CONFIG_Channels_t;

/*
    Result status enumeration
*/
#define TRACE_LEVEL_CONFIG_RESULT_SUCCESS ((uint8_t) 0)
#define TRACE_LEVEL_CONFIG_RESULT_FAILED ((uint8_t) 1)
#define TRACE_LEVEL_CONFIG_RESULT_MAX_CNT  ((uint8_t) 2)
typedef uint8_t TRACE_LEVEL_CONFIG_Result_t;

/*
    Struct containing information about a particular system module
*/
typedef struct {
    uint8_t u8Module_nameSize;
    char strModule_name[100];
    TRACE_LEVEL_CONFIG_TraceLevels_t eLevel;
    bool bActive;
} PACKED_STRUCT TRACE_LEVEL_CONFIG_ModuleInfo_t;

/*
    Struct containing information about a particular trace channel
*/
typedef struct {
    TRACE_LEVEL_CONFIG_Channels_t eChannel;
    TRACE_LEVEL_CONFIG_TraceLevels_t eLevel;
    bool bActive;
} PACKED_STRUCT TRACE_LEVEL_CONFIG_ChannelInfo_t;


typedef struct {
    TRACE_LEVEL_CONFIG_Channels_t eChannel;
    TRACE_LEVEL_CONFIG_TraceLevels_t eLevel;
} PACKED_STRUCT trace_level_configset_channel_trace_levelRequestData_t;

typedef struct {
    TRACE_LEVEL_CONFIG_Channels_t eChannel;
    bool bIs_active;
} PACKED_STRUCT trace_level_configset_channel_active_statusRequestData_t;

typedef struct {
    uint8_t u8ModuleSize;
    char strModule[100];
    bool bIs_active;
} PACKED_STRUCT trace_level_configset_module_active_statusRequestData_t;

typedef struct {
    uint8_t u8ModuleSize;
    char strModule[100];
    TRACE_LEVEL_CONFIG_TraceLevels_t eLevel;
} PACKED_STRUCT trace_level_configset_module_trace_levelRequestData_t;

typedef struct {
    uint8_t u8Module_name_inputSize;
    char strModule_name_input[100];
} PACKED_STRUCT trace_level_configget_module_infoRequestData_t;


typedef struct {
    TRACE_LEVEL_CONFIG_Result_t eRes;
} PACKED_STRUCT trace_level_configset_channel_trace_levelResponseData_t;

typedef struct {
    TRACE_LEVEL_CONFIG_ChannelInfo_t asChannels[3];
    TRACE_LEVEL_CONFIG_Result_t eRes;
} PACKED_STRUCT trace_level_configget_channel_infoResponseData_t;

typedef struct {
    TRACE_LEVEL_CONFIG_Result_t eRes;
} PACKED_STRUCT trace_level_configset_channel_active_statusResponseData_t;

typedef struct {
    TRACE_LEVEL_CONFIG_Result_t eRes;
} PACKED_STRUCT trace_level_configset_module_active_statusResponseData_t;

typedef struct {
    TRACE_LEVEL_CONFIG_Result_t eRes;
} PACKED_STRUCT trace_level_configset_module_trace_levelResponseData_t;

typedef struct {
    TRACE_LEVEL_CONFIG_ModuleInfo_t sModule_output;
    TRACE_LEVEL_CONFIG_Result_t eRes;
} PACKED_STRUCT trace_level_configget_module_infoResponseData_t;


#endif  // #ifndef FP_TRACE_LEVEL_CONFIGPROTOCOLTYPES_H

