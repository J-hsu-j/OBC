
#ifndef FP_TELEMETRYPROTOCOLTYPES_H
#define FP_TELEMETRYPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY ((uint16_t) (0x00000102))

#define TELEMETRY_GETTELEMETRYGENERALCONFIG_FUNC_ID ((funcIdType_t) 0x00000000)
#define TELEMETRY_SETTELEMETRYGENERALCONFIG_FUNC_ID ((funcIdType_t) 0x00000001)
#define TELEMETRY_GETTELEMETRYPRESETCONFIG_FUNC_ID ((funcIdType_t) 0x00000002)
#define TELEMETRY_SETTELEMETRYPRESETCONFIG_FUNC_ID ((funcIdType_t) 0x00000003)
#define TELEMETRY_SETACTIVEPRESET_FUNC_ID ((funcIdType_t) 0x00000004)
#define TELEMETRY_GETACTIVEPRESET_FUNC_ID ((funcIdType_t) 0x00000005)
#define TELEMETRY_RESTOREACTIVEPRESET_FUNC_ID ((funcIdType_t) 0x00000006)
#define TELEMETRY_GETTELEMETRYFILESINKCONFIG_FUNC_ID ((funcIdType_t) 0x00000007)
#define TELEMETRY_SETTELEMETRYFILESZLIMITCONFIG_FUNC_ID ((funcIdType_t) 0x00000008)
#define TELEMETRY_CLEANTELEMETRYFILES_FUNC_ID ((funcIdType_t) 0x0000000B)
#define TELEMETRY_GETTELEMETRYOPERATIONSTATS_FUNC_ID ((funcIdType_t) 0x0000000C)
#define TELEMETRY_STARTTELEMETRY_FUNC_ID ((funcIdType_t) 0x0000000D)
#define TELEMETRY_STOPTELEMETRY_FUNC_ID ((funcIdType_t) 0x0000000E)
#define TELEMETRY_GETTELEMETRYGENERALCONFIG_FUNCRESP_ID ((funcIdType_t) 0x00000000)
#define TELEMETRY_SETTELEMETRYGENERALCONFIG_FUNCRESP_ID ((funcIdType_t) 0x00000001)
#define TELEMETRY_GETTELEMETRYPRESETCONFIG_FUNCRESP_ID ((funcIdType_t) 0x00000002)
#define TELEMETRY_SETTELEMETRYPRESETCONFIG_FUNCRESP_ID ((funcIdType_t) 0x00000003)
#define TELEMETRY_SETACTIVEPRESET_FUNCRESP_ID ((funcIdType_t) 0x00000004)
#define TELEMETRY_GETACTIVEPRESET_FUNCRESP_ID ((funcIdType_t) 0x00000005)
#define TELEMETRY_RESTOREACTIVEPRESET_FUNCRESP_ID ((funcIdType_t) 0x00000006)
#define TELEMETRY_GETTELEMETRYFILESINKCONFIG_FUNCRESP_ID ((funcIdType_t) 0x00000007)
#define TELEMETRY_SETTELEMETRYFILESZLIMITCONFIG_FUNCRESP_ID ((funcIdType_t) 0x00000008)
#define TELEMETRY_CLEANTELEMETRYFILES_FUNCRESP_ID ((funcIdType_t) 0x0000000B)
#define TELEMETRY_GETTELEMETRYOPERATIONSTATS_FUNCRESP_ID ((funcIdType_t) 0x0000000C)
#define TELEMETRY_STARTTELEMETRY_FUNCRESP_ID ((funcIdType_t) 0x0000000D)
#define TELEMETRY_STOPTELEMETRY_FUNCRESP_ID ((funcIdType_t) 0x0000000E)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    Settings for the telemetry service stored in the nvm
*/
typedef struct {
    uint16_t u16Data_id;
    bool bActive;
    uint16_t u16Acq_period_ms;
} PACKED_STRUCT TELEMETRY_tlm_preset_cfg_t;

/*
    Structure containing the values for the telemetry size limits
*/
typedef struct {
    uint32_t u32Size_limit_kb;
    uint16_t u16Max_log_files_cnt;
} PACKED_STRUCT TELEMETRY_tlm_file_size_limit_cfg_t;

/*
    How to keep the logging files, time based or size based
*/
#define TELEMETRY_TLM_FILE_LOGGING_TYPE_SIZE_LIMIT ((uint8_t) 0)
#define TELEMETRY_TLM_FILE_LOGGING_TYPE_MAX_CNT  ((uint8_t) 1)
typedef uint8_t TELEMETRY_tlm_file_logging_type_t;

/*
    The list of telemetry instances configured in the system
*/
#define TELEMETRY_TELEMETRYINSTANCE_TLM_INST_0 ((uint8_t) 0)
#define TELEMETRY_TELEMETRYINSTANCE_TLM_INST_1 ((uint8_t) 1)
#define TELEMETRY_TELEMETRYINSTANCE_MAX_CNT  ((uint8_t) 2)
typedef uint8_t TELEMETRY_TelemetryInstance_t;

/*
    Active configuration for the telemetry service
*/
typedef struct {
    bool bTlm_auto_start_en;
} PACKED_STRUCT TELEMETRY_tlm_general_cfg_t;

/*
    Counters of relevant events from the telemetry service
*/
typedef struct {
    bool bIs_started;
    uint32_t u32Msg_pushed_cnt;
    uint32_t u32Msg_popped_cnt;
    uint32_t u32Free_bytes_min;
    uint32_t u32Discarded_messages_cnt;
    uint32_t u32Max_number_of_batch_msg;
    uint32_t u32Active_slot_id;
} PACKED_STRUCT TELEMETRY_tlm_stats_t;

/*
    Standard result enumeration which can be used in most situations as a return code
*/
#define TELEMETRY_STANDARDRESULT_SUCCESS ((uint8_t) 0)
#define TELEMETRY_STANDARDRESULT_ERROR ((uint8_t) 1)
#define TELEMETRY_STANDARDRESULT_INVALID_ARGS ((uint8_t) 2)
#define TELEMETRY_STANDARDRESULT_NOT_SUPPORTED ((uint8_t) 3)
#define TELEMETRY_STANDARDRESULT_MAX_CNT  ((uint8_t) 4)
typedef uint8_t TELEMETRY_StandardResult_t;


typedef struct {
    TELEMETRY_TelemetryInstance_t eTlm_instance_id;
} PACKED_STRUCT telemetrygetTelemetryGeneralConfigRequestData_t;

typedef struct {
    TELEMETRY_TelemetryInstance_t eTlm_instance_id;
    TELEMETRY_tlm_general_cfg_t sCfg;
} PACKED_STRUCT telemetrysetTelemetryGeneralConfigRequestData_t;

typedef struct {
    TELEMETRY_TelemetryInstance_t eTlm_instance_id;
} PACKED_STRUCT telemetrygetTelemetryPresetConfigRequestData_t;

typedef struct {
    TELEMETRY_TelemetryInstance_t eTlm_instance_id;
    TELEMETRY_tlm_preset_cfg_t asTelemetry_preset_cfg[30];
} PACKED_STRUCT telemetrysetTelemetryPresetConfigRequestData_t;

typedef struct {
    TELEMETRY_TelemetryInstance_t eTlm_instance_id;
    uint8_t u8Req_active_preset;
} PACKED_STRUCT telemetrysetActivePresetRequestData_t;

typedef struct {
    TELEMETRY_TelemetryInstance_t eTlm_instance_id;
} PACKED_STRUCT telemetrygetActivePresetRequestData_t;

typedef struct {
    TELEMETRY_TelemetryInstance_t eTlm_instance_id;
} PACKED_STRUCT telemetryrestoreActivePresetRequestData_t;

typedef struct {
    TELEMETRY_TelemetryInstance_t eTlm_instance_id;
} PACKED_STRUCT telemetrygetTelemetryFileSinkConfigRequestData_t;

typedef struct {
    TELEMETRY_TelemetryInstance_t eTlm_instance_id;
    TELEMETRY_tlm_file_size_limit_cfg_t sSize_limit_cfg;
} PACKED_STRUCT telemetrysetTelemetryFileSzLimitConfigRequestData_t;

typedef struct {
    TELEMETRY_TelemetryInstance_t eTlm_instance_id;
} PACKED_STRUCT telemetrycleanTelemetryFilesRequestData_t;

typedef struct {
    TELEMETRY_TelemetryInstance_t eTlm_instance_id;
} PACKED_STRUCT telemetrygetTelemetryOperationStatsRequestData_t;

typedef struct {
    TELEMETRY_TelemetryInstance_t eTlm_instance_id;
    uint16_t u16Hold_time_sec;
} PACKED_STRUCT telemetrystartTelemetryRequestData_t;

typedef struct {
    TELEMETRY_TelemetryInstance_t eTlm_instance_id;
    uint16_t u16Hold_time_sec;
} PACKED_STRUCT telemetrystopTelemetryRequestData_t;


typedef struct {
    TELEMETRY_StandardResult_t eRes;
    TELEMETRY_tlm_general_cfg_t sCfg;
} PACKED_STRUCT telemetrygetTelemetryGeneralConfigResponseData_t;

typedef struct {
    TELEMETRY_StandardResult_t eRes;
} PACKED_STRUCT telemetrysetTelemetryGeneralConfigResponseData_t;

typedef struct {
    TELEMETRY_StandardResult_t eRes;
    uint8_t u8Slot_preset_cnt;
    uint8_t u8Max_tlm_msg_cnt;
    TELEMETRY_tlm_preset_cfg_t asTelemetry_preset_cfg[30];
} PACKED_STRUCT telemetrygetTelemetryPresetConfigResponseData_t;

typedef struct {
    TELEMETRY_StandardResult_t eRes;
} PACKED_STRUCT telemetrysetTelemetryPresetConfigResponseData_t;

typedef struct {
    TELEMETRY_StandardResult_t eRes;
    uint8_t u8Avail_presets_cnt;
} PACKED_STRUCT telemetrysetActivePresetResponseData_t;

typedef struct {
    TELEMETRY_StandardResult_t eRes;
    uint8_t u8Active_preset_id;
} PACKED_STRUCT telemetrygetActivePresetResponseData_t;

typedef struct {
    TELEMETRY_StandardResult_t eRes;
} PACKED_STRUCT telemetryrestoreActivePresetResponseData_t;

typedef struct {
    TELEMETRY_StandardResult_t eRes;
    TELEMETRY_tlm_file_logging_type_t eActive_file_cfg_type;
    TELEMETRY_tlm_file_size_limit_cfg_t sSize_limit_cfg;
} PACKED_STRUCT telemetrygetTelemetryFileSinkConfigResponseData_t;

typedef struct {
    TELEMETRY_StandardResult_t eRes;
} PACKED_STRUCT telemetrysetTelemetryFileSzLimitConfigResponseData_t;

typedef struct {
    TELEMETRY_StandardResult_t eRes;
} PACKED_STRUCT telemetrycleanTelemetryFilesResponseData_t;

typedef struct {
    TELEMETRY_StandardResult_t eRes;
    TELEMETRY_tlm_stats_t sTelemetry_stats;
} PACKED_STRUCT telemetrygetTelemetryOperationStatsResponseData_t;

typedef struct {
    TELEMETRY_StandardResult_t eRes;
} PACKED_STRUCT telemetrystartTelemetryResponseData_t;

typedef struct {
    TELEMETRY_StandardResult_t eRes;
} PACKED_STRUCT telemetrystopTelemetryResponseData_t;


#endif  // #ifndef FP_TELEMETRYPROTOCOLTYPES_H

