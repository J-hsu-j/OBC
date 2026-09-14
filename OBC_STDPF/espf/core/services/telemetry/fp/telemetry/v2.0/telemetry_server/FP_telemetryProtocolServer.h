/*!
********************************************************************************************
* @file FP_telemetryProtocolServer.h
* @brief ESSA Stack server-side public API declaration
********************************************************************************************
* @version           interface telemetry v2.0
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

#ifndef FP_TELEMETRYPROTOCOLSERVER_H
#define FP_TELEMETRYPROTOCOLSERVER_H

#include "FP_telemetryProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define telemetry_PROTOCOL_VERSION_MAJOR   ((uint8_t) 2)
#define telemetry_PROTOCOL_VERSION_MINOR   ((uint8_t) 0)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pftelemetry_getTelemetryGeneralConfigRequestHandler_t)(ReqContext_t *ctx, const telemetrygetTelemetryGeneralConfigRequestData_t *pRequestData);
typedef void (*pftelemetry_setTelemetryGeneralConfigRequestHandler_t)(ReqContext_t *ctx, const telemetrysetTelemetryGeneralConfigRequestData_t *pRequestData);
typedef void (*pftelemetry_getTelemetryPresetConfigRequestHandler_t)(ReqContext_t *ctx, const telemetrygetTelemetryPresetConfigRequestData_t *pRequestData);
typedef void (*pftelemetry_setTelemetryPresetConfigRequestHandler_t)(ReqContext_t *ctx, const telemetrysetTelemetryPresetConfigRequestData_t *pRequestData);
typedef void (*pftelemetry_setActivePresetRequestHandler_t)(ReqContext_t *ctx, const telemetrysetActivePresetRequestData_t *pRequestData);
typedef void (*pftelemetry_getActivePresetRequestHandler_t)(ReqContext_t *ctx, const telemetrygetActivePresetRequestData_t *pRequestData);
typedef void (*pftelemetry_restoreActivePresetRequestHandler_t)(ReqContext_t *ctx, const telemetryrestoreActivePresetRequestData_t *pRequestData);
typedef void (*pftelemetry_getTelemetryFileSinkConfigRequestHandler_t)(ReqContext_t *ctx, const telemetrygetTelemetryFileSinkConfigRequestData_t *pRequestData);
typedef void (*pftelemetry_setTelemetryFileSzLimitConfigRequestHandler_t)(ReqContext_t *ctx, const telemetrysetTelemetryFileSzLimitConfigRequestData_t *pRequestData);
typedef void (*pftelemetry_cleanTelemetryFilesRequestHandler_t)(ReqContext_t *ctx, const telemetrycleanTelemetryFilesRequestData_t *pRequestData);
typedef void (*pftelemetry_getTelemetryOperationStatsRequestHandler_t)(ReqContext_t *ctx, const telemetrygetTelemetryOperationStatsRequestData_t *pRequestData);
typedef void (*pftelemetry_startTelemetryRequestHandler_t)(ReqContext_t *ctx, const telemetrystartTelemetryRequestData_t *pRequestData);
typedef void (*pftelemetry_stopTelemetryRequestHandler_t)(ReqContext_t *ctx, const telemetrystopTelemetryRequestData_t *pRequestData);

typedef struct {
    pftelemetry_getTelemetryGeneralConfigRequestHandler_t telemetry_getTelemetryGeneralConfigRequestHandler;
    pftelemetry_setTelemetryGeneralConfigRequestHandler_t telemetry_setTelemetryGeneralConfigRequestHandler;
    pftelemetry_getTelemetryPresetConfigRequestHandler_t telemetry_getTelemetryPresetConfigRequestHandler;
    pftelemetry_setTelemetryPresetConfigRequestHandler_t telemetry_setTelemetryPresetConfigRequestHandler;
    pftelemetry_setActivePresetRequestHandler_t telemetry_setActivePresetRequestHandler;
    pftelemetry_getActivePresetRequestHandler_t telemetry_getActivePresetRequestHandler;
    pftelemetry_restoreActivePresetRequestHandler_t telemetry_restoreActivePresetRequestHandler;
    pftelemetry_getTelemetryFileSinkConfigRequestHandler_t telemetry_getTelemetryFileSinkConfigRequestHandler;
    pftelemetry_setTelemetryFileSzLimitConfigRequestHandler_t telemetry_setTelemetryFileSzLimitConfigRequestHandler;
    pftelemetry_cleanTelemetryFilesRequestHandler_t telemetry_cleanTelemetryFilesRequestHandler;
    pftelemetry_getTelemetryOperationStatsRequestHandler_t telemetry_getTelemetryOperationStatsRequestHandler;
    pftelemetry_startTelemetryRequestHandler_t telemetry_startTelemetryRequestHandler;
    pftelemetry_stopTelemetryRequestHandler_t telemetry_stopTelemetryRequestHandler;
} telemetry_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_telemetryProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void telemetry_registerServerApi(telemetry_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_telemetryProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t telemetry_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes telemetry_getTelemetryGeneralConfigResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes,
                const TELEMETRY_tlm_general_cfg_t * const sCfg
);

ESSATMAC_ErrCodes telemetry_setTelemetryGeneralConfigResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes
);

ESSATMAC_ErrCodes telemetry_getTelemetryPresetConfigResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes,
                const uint8_t u8Slot_preset_cnt,
                const uint8_t u8Max_tlm_msg_cnt,
                const TELEMETRY_tlm_preset_cfg_t * const asTelemetry_preset_cfg
);

ESSATMAC_ErrCodes telemetry_setTelemetryPresetConfigResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes
);

ESSATMAC_ErrCodes telemetry_setActivePresetResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes,
                const uint8_t u8Avail_presets_cnt
);

ESSATMAC_ErrCodes telemetry_getActivePresetResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes,
                const uint8_t u8Active_preset_id
);

ESSATMAC_ErrCodes telemetry_restoreActivePresetResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes
);

ESSATMAC_ErrCodes telemetry_getTelemetryFileSinkConfigResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes,
                const TELEMETRY_tlm_file_logging_type_t eActive_file_cfg_type,
                const TELEMETRY_tlm_file_size_limit_cfg_t * const sSize_limit_cfg
);

ESSATMAC_ErrCodes telemetry_setTelemetryFileSzLimitConfigResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes
);

ESSATMAC_ErrCodes telemetry_cleanTelemetryFilesResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes
);

ESSATMAC_ErrCodes telemetry_getTelemetryOperationStatsResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes,
                const TELEMETRY_tlm_stats_t * const sTelemetry_stats
);

ESSATMAC_ErrCodes telemetry_startTelemetryResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes
);

ESSATMAC_ErrCodes telemetry_stopTelemetryResp(
                RespContext_t* ctx,
                const TELEMETRY_StandardResult_t eRes
);


#endif  // #ifndef FP_TELEMETRYPROTOCOLSERVER_H
