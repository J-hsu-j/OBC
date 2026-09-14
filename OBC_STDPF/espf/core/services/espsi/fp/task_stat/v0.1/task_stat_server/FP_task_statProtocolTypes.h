/*!
********************************************************************************************
* @file FP_task_statProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface task_stat v0.1
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

#ifndef FP_TASK_STATPROTOCOLTYPES_H
#define FP_TASK_STATPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT ((uint16_t) (0x00000022))

#define TASK_STAT_GET_CONFIGURATION_FUNC_ID ((funcIdType_t) 0x00000001)
#define TASK_STAT_SET_CONFIGURATION_GLOBAL_ENABLE_FUNC_ID ((funcIdType_t) 0x00000010)
#define TASK_STAT_SET_CONFIGURATION_GLOBAL_LOGGING_FUNC_ID ((funcIdType_t) 0x00000011)
#define TASK_STAT_SET_CONFIGURATION_GLOBAL_PRIORITY_FUNC_ID ((funcIdType_t) 0x00000012)
#define TASK_STAT_SET_CONFIGURATION_GLOBAL_SAMPLING_PERIOD_FUNC_ID ((funcIdType_t) 0x00000014)
#define TASK_STAT_SET_CONFIGURATION_GLOBAL_ID_FILE_FUNC_ID ((funcIdType_t) 0x00000015)
#define TASK_STAT_SET_CONFIGURATION_GLOBAL_DEFAULTS_FUNC_ID ((funcIdType_t) 0x0000001F)
#define TASK_STAT_GET_CONFIGURATION_PER_TASK_ID_FUNC_ID ((funcIdType_t) 0x00000003)
#define TASK_STAT_SET_CONFIGURATION_PER_TASK_ID_FUNC_ID ((funcIdType_t) 0x00000004)
#define TASK_STAT_GET_FREE_HEAP_FUNC_ID ((funcIdType_t) 0x00000006)
#define TASK_STAT_GET_LATEST_TASK_STAT_FUNC_ID ((funcIdType_t) 0x00000005)
#define TASK_STAT_GET_CONFIGURATION_FUNCRESP_ID ((funcIdType_t) 0x00000001)
#define TASK_STAT_SET_CONFIGURATION_GLOBAL_ENABLE_FUNCRESP_ID ((funcIdType_t) 0x00000010)
#define TASK_STAT_SET_CONFIGURATION_GLOBAL_LOGGING_FUNCRESP_ID ((funcIdType_t) 0x00000011)
#define TASK_STAT_SET_CONFIGURATION_GLOBAL_PRIORITY_FUNCRESP_ID ((funcIdType_t) 0x00000012)
#define TASK_STAT_SET_CONFIGURATION_GLOBAL_SAMPLING_PERIOD_FUNCRESP_ID ((funcIdType_t) 0x00000014)
#define TASK_STAT_SET_CONFIGURATION_GLOBAL_ID_FILE_FUNCRESP_ID ((funcIdType_t) 0x00000015)
#define TASK_STAT_SET_CONFIGURATION_GLOBAL_DEFAULTS_FUNCRESP_ID ((funcIdType_t) 0x0000001F)
#define TASK_STAT_GET_CONFIGURATION_PER_TASK_ID_FUNCRESP_ID ((funcIdType_t) 0x00000003)
#define TASK_STAT_SET_CONFIGURATION_PER_TASK_ID_FUNCRESP_ID ((funcIdType_t) 0x00000004)
#define TASK_STAT_GET_FREE_HEAP_FUNCRESP_ID ((funcIdType_t) 0x00000006)
#define TASK_STAT_GET_LATEST_TASK_STAT_FUNCRESP_ID ((funcIdType_t) 0x00000005)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    Configuration for a specific task
*/
typedef struct {
    uint8_t u8Id;
    bool bEnabled;
    bool bLogging;
} PACKED_STRUCT TASK_STAT_TaskStatConfig_t;

/*
    A sample staticstics for a specific task id
*/
typedef struct {
    uint8_t u8Id;
    uint16_t u16Free_stack;
    uint32_t u32Run_time;
} PACKED_STRUCT TASK_STAT_TaskStatSample_t;

/*
    General configurations for the task statistics
*/
typedef struct {
    bool bEnable;
    bool bLogging;
    uint8_t u8Priority;
    uint32_t u32Period;
    uint8_t u8Task_id_table_fileSize;
    char strTask_id_table_file[47];
} PACKED_STRUCT TASK_STAT_StatsConfig_t;

/*
    operation status
*/
#define TASK_STAT_OPSTATUS_SUCCESS ((uint8_t) 0)
#define TASK_STAT_OPSTATUS_ERROR ((uint8_t) 1)
#define TASK_STAT_OPSTATUS_MAX_CNT  ((uint8_t) 2)
typedef uint8_t TASK_STAT_OpStatus_t;


typedef struct {
    bool bEnable;
} PACKED_STRUCT task_statset_configuration_global_enableRequestData_t;

typedef struct {
    bool bLogging;
} PACKED_STRUCT task_statset_configuration_global_loggingRequestData_t;

typedef struct {
    uint8_t u8Priority;
} PACKED_STRUCT task_statset_configuration_global_priorityRequestData_t;

typedef struct {
    uint32_t u32Sampling_period;
} PACKED_STRUCT task_statset_configuration_global_sampling_periodRequestData_t;

typedef struct {
    uint8_t u8Task_id_table_fileSize;
    char strTask_id_table_file[47];
} PACKED_STRUCT task_statset_configuration_global_id_fileRequestData_t;

typedef struct {
    uint8_t u8Id;
} PACKED_STRUCT task_statget_configuration_per_task_idRequestData_t;

typedef struct {
    TASK_STAT_TaskStatConfig_t sTask_cfg;
} PACKED_STRUCT task_statset_configuration_per_task_idRequestData_t;

typedef struct {
    uint8_t u8Id;
} PACKED_STRUCT task_statget_latest_task_statRequestData_t;


typedef struct {
    TASK_STAT_OpStatus_t eStatus;
    TASK_STAT_StatsConfig_t sConfig;
} PACKED_STRUCT task_statget_configurationResponseData_t;

typedef struct {
    bool bStatus;
} PACKED_STRUCT task_statset_configuration_global_enableResponseData_t;

typedef struct {
    bool bStatus;
} PACKED_STRUCT task_statset_configuration_global_loggingResponseData_t;

typedef struct {
    bool bStatus;
} PACKED_STRUCT task_statset_configuration_global_priorityResponseData_t;

typedef struct {
    bool bStatus;
} PACKED_STRUCT task_statset_configuration_global_sampling_periodResponseData_t;

typedef struct {
    bool bStatus;
} PACKED_STRUCT task_statset_configuration_global_id_fileResponseData_t;

typedef struct {
    bool bStatus;
} PACKED_STRUCT task_statset_configuration_global_defaultsResponseData_t;

typedef struct {
    TASK_STAT_OpStatus_t eStatus;
    TASK_STAT_TaskStatConfig_t sTask_cfg;
} PACKED_STRUCT task_statget_configuration_per_task_idResponseData_t;

typedef struct {
    TASK_STAT_OpStatus_t eStatus;
} PACKED_STRUCT task_statset_configuration_per_task_idResponseData_t;

typedef struct {
    TASK_STAT_OpStatus_t eStatus;
    uint32_t u32Free_heap;
} PACKED_STRUCT task_statget_free_heapResponseData_t;

typedef struct {
    TASK_STAT_OpStatus_t eStatus;
    TASK_STAT_TaskStatSample_t sStat;
} PACKED_STRUCT task_statget_latest_task_statResponseData_t;


#endif  // #ifndef FP_TASK_STATPROTOCOLTYPES_H

