/*!
********************************************************************************************
* @file FP_telemetryServerApp.c
* @brief ServerApp implementation template generator
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

#include "FP_telemetryProtocolServer.h"

// @START_USER@ USER_INCLUDES
#include "nvm/inc/nvm.h"
#include "telemetry.h"
#include "telemetry_cfg_user.h"
#include "telemetry_file_sink.h"
#include "telemetry_queue.h"
#include "debug.h"
#include "telemetry_file_sink.h"
#include "telemetry_types.h"
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL
static void telemetry_getTelemetryGeneralConfigRequestHandlerImpl(ReqContext_t* pReqCtx,
            const telemetrygetTelemetryGeneralConfigRequestData_t* pRequestData);

static void telemetry_setTelemetryGeneralConfigRequestHandlerImpl(ReqContext_t* pReqCtx,
            const telemetrysetTelemetryGeneralConfigRequestData_t* pRequestData);

static void telemetry_getTelemetryPresetConfigRequestHandlerImpl(ReqContext_t* pReqCtx,
            const telemetrygetTelemetryPresetConfigRequestData_t* pRequestData);

static void telemetry_setTelemetryPresetConfigRequestHandlerImpl(ReqContext_t* pReqCtx,
            const telemetrysetTelemetryPresetConfigRequestData_t* pRequestData);

static void telemetry_setActivePresetRequestHandlerImpl(ReqContext_t* pReqCtx,
            const telemetrysetActivePresetRequestData_t* pRequestData);

static void telemetry_getActivePresetRequestHandlerImpl(ReqContext_t* pReqCtx,
            const telemetrygetActivePresetRequestData_t* pRequestData);

static void telemetry_restoreActivePresetRequestHandlerImpl(ReqContext_t* pReqCtx,
            const telemetryrestoreActivePresetRequestData_t* pRequestData);

static void telemetry_getTelemetryFileSinkConfigRequestHandlerImpl(ReqContext_t* pReqCtx,
            const telemetrygetTelemetryFileSinkConfigRequestData_t* pRequestData);

static void telemetry_setTelemetryFileSzLimitConfigRequestHandlerImpl(ReqContext_t* pReqCtx,
            const telemetrysetTelemetryFileSzLimitConfigRequestData_t* pRequestData);

static void telemetry_cleanTelemetryFilesRequestHandlerImpl(ReqContext_t* pReqCtx,
            const telemetrycleanTelemetryFilesRequestData_t* pRequestData);

static void telemetry_getTelemetryOperationStatsRequestHandlerImpl(ReqContext_t* pReqCtx,
            const telemetrygetTelemetryOperationStatsRequestData_t* pRequestData);

static void telemetry_startTelemetryRequestHandlerImpl(ReqContext_t* pReqCtx,
            const telemetrystartTelemetryRequestData_t* pRequestData);

static void telemetry_stopTelemetryRequestHandlerImpl(ReqContext_t* pReqCtx,
            const telemetrystopTelemetryRequestData_t* pRequestData);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)
// @END_USER@ USER_LOCAL_VARS_DECL

static telemetry_ServerApi_t telemetryServerApiCtx =
{
  .telemetry_getTelemetryGeneralConfigRequestHandler = telemetry_getTelemetryGeneralConfigRequestHandlerImpl,
  .telemetry_setTelemetryGeneralConfigRequestHandler = telemetry_setTelemetryGeneralConfigRequestHandlerImpl,
  .telemetry_getTelemetryPresetConfigRequestHandler = telemetry_getTelemetryPresetConfigRequestHandlerImpl,
  .telemetry_setTelemetryPresetConfigRequestHandler = telemetry_setTelemetryPresetConfigRequestHandlerImpl,
  .telemetry_setActivePresetRequestHandler = telemetry_setActivePresetRequestHandlerImpl,
  .telemetry_getActivePresetRequestHandler = telemetry_getActivePresetRequestHandlerImpl,
  .telemetry_restoreActivePresetRequestHandler = telemetry_restoreActivePresetRequestHandlerImpl,
  .telemetry_getTelemetryFileSinkConfigRequestHandler = telemetry_getTelemetryFileSinkConfigRequestHandlerImpl,
  .telemetry_setTelemetryFileSzLimitConfigRequestHandler = telemetry_setTelemetryFileSzLimitConfigRequestHandlerImpl,
  .telemetry_cleanTelemetryFilesRequestHandler = telemetry_cleanTelemetryFilesRequestHandlerImpl,
  .telemetry_getTelemetryOperationStatsRequestHandler = telemetry_getTelemetryOperationStatsRequestHandlerImpl,
  .telemetry_startTelemetryRequestHandler = telemetry_startTelemetryRequestHandlerImpl,
  .telemetry_stopTelemetryRequestHandler = telemetry_stopTelemetryRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method telemetry::getTelemetryGeneralConfig (ID = 0x00000000)
static void telemetry_getTelemetryGeneralConfigRequestHandlerImpl(ReqContext_t *pReqCtx,
            const telemetrygetTelemetryGeneralConfigRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TELEMETRY_StandardResult_t eRes;
    TELEMETRY_tlm_general_cfg_t sCfg;

    // @USER_VAR_SECTION_START@telemetry::getTelemetryGeneralConfig@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@telemetry::getTelemetryGeneralConfig@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@telemetry::getTelemetryGeneralConfig@
        sCfg.bTlm_auto_start_en      = false;

        if (pRequestData->eTlm_instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT)
        {
            telemetry_cfg_t tlm_config;

            telemetry_cfg_get_tlm_config(pRequestData->eTlm_instance_id, (void *const)&tlm_config);

            sCfg.bTlm_auto_start_en      = tlm_config.params.bTlm_auto_start_en;

            eRes = TELEMETRY_STANDARDRESULT_SUCCESS;
        }
        else
        {
            eRes = TELEMETRY_STANDARDRESULT_INVALID_ARGS;
        }
        // @USER_CODE_SECTION_END@telemetry::getTelemetryGeneralConfig@

        respResult = telemetry_getTelemetryGeneralConfigResp(
                        &respCtx,
                        eRes,
                        &sCfg
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY, TELEMETRY_GETTELEMETRYGENERALCONFIG_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method telemetry::getTelemetryGeneralConfig (ID = 0x00000000)

// @START@ Request handler for method telemetry::setTelemetryGeneralConfig (ID = 0x00000001)
static void telemetry_setTelemetryGeneralConfigRequestHandlerImpl(ReqContext_t *pReqCtx,
            const telemetrysetTelemetryGeneralConfigRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TELEMETRY_StandardResult_t eRes;

    // @USER_VAR_SECTION_START@telemetry::setTelemetryGeneralConfig@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@telemetry::setTelemetryGeneralConfig@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@telemetry::setTelemetryGeneralConfig@
        if (pRequestData->eTlm_instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT)
        {
            telemetry_cfg_t tlm_config;

            telemetry_cfg_get_tlm_config(pRequestData->eTlm_instance_id, (void *const)&tlm_config);

            tlm_config.params.bTlm_auto_start_en      = pRequestData->sCfg.bTlm_auto_start_en;

            telemetry_cfg_set_tlm_config(pRequestData->eTlm_instance_id, (void *const)&tlm_config);

            eRes = TELEMETRY_STANDARDRESULT_SUCCESS;
        }
        else
        {
            eRes = TELEMETRY_STANDARDRESULT_INVALID_ARGS;
        }
        // @USER_CODE_SECTION_END@telemetry::setTelemetryGeneralConfig@

        respResult = telemetry_setTelemetryGeneralConfigResp(
                        &respCtx,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY, TELEMETRY_SETTELEMETRYGENERALCONFIG_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method telemetry::setTelemetryGeneralConfig (ID = 0x00000001)

// @START@ Request handler for method telemetry::getTelemetryPresetConfig (ID = 0x00000002)
static void telemetry_getTelemetryPresetConfigRequestHandlerImpl(ReqContext_t *pReqCtx,
            const telemetrygetTelemetryPresetConfigRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TELEMETRY_StandardResult_t eRes;
    uint8_t u8Slot_preset_cnt;
    uint8_t u8Max_tlm_msg_cnt;
    TELEMETRY_tlm_preset_cfg_t asTelemetry_preset_cfg[30];

    // @USER_VAR_SECTION_START@telemetry::getTelemetryPresetConfig@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@telemetry::getTelemetryPresetConfig@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@telemetry::getTelemetryPresetConfig@
        u8Slot_preset_cnt = TELEMETRY_PRESETS_COUNT;
        u8Max_tlm_msg_cnt = TELEMETRY_MAX_CONFIGURABLE_ENTRIES;
        (void)memset(asTelemetry_preset_cfg, INVALID_TLM_SLOT_ASSIGNMENT, sizeof(asTelemetry_preset_cfg));

        if (pRequestData->eTlm_instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT)
        {
            telemetry_preset_cfg_t tlm_preset_cfg;

            telemetry_cfg_get_preset_config(pRequestData->eTlm_instance_id, (void *const)&tlm_preset_cfg);

            (void)memcpy(asTelemetry_preset_cfg,
                         tlm_preset_cfg.tlm_slots_setting,
                         MIN(sizeof(asTelemetry_preset_cfg), sizeof(tlm_preset_cfg.tlm_slots_setting)));

            eRes = TELEMETRY_STANDARDRESULT_SUCCESS;
        }
        else
        {
            eRes = TELEMETRY_STANDARDRESULT_INVALID_ARGS;
        }
        // @USER_CODE_SECTION_END@telemetry::getTelemetryPresetConfig@

        respResult = telemetry_getTelemetryPresetConfigResp(
                        &respCtx,
                        eRes,
                        u8Slot_preset_cnt,
                        u8Max_tlm_msg_cnt,
                        asTelemetry_preset_cfg
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY, TELEMETRY_GETTELEMETRYPRESETCONFIG_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method telemetry::getTelemetryPresetConfig (ID = 0x00000002)

// @START@ Request handler for method telemetry::setTelemetryPresetConfig (ID = 0x00000003)
static void telemetry_setTelemetryPresetConfigRequestHandlerImpl(ReqContext_t *pReqCtx,
            const telemetrysetTelemetryPresetConfigRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TELEMETRY_StandardResult_t eRes;

    // @USER_VAR_SECTION_START@telemetry::setTelemetryPresetConfig@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@telemetry::setTelemetryPresetConfig@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@telemetry::setTelemetryPresetConfig@
        if (pRequestData->eTlm_instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT)
        {
            telemetry_preset_cfg_t tlm_preset_cfg;

            (void)memcpy((void *volatile)tlm_preset_cfg.tlm_slots_setting,
                         (const void *volatile)pRequestData->asTelemetry_preset_cfg,
                         sizeof(tlm_preset_cfg.tlm_slots_setting));

            eRes = (true == telemetry_cfg_set_preset_config(pRequestData->eTlm_instance_id, &tlm_preset_cfg)) ? TELEMETRY_STANDARDRESULT_SUCCESS : TELEMETRY_STANDARDRESULT_INVALID_ARGS;
        }
        else
        {
            eRes = TELEMETRY_STANDARDRESULT_INVALID_ARGS;
        }
        // @USER_CODE_SECTION_END@telemetry::setTelemetryPresetConfig@

        respResult = telemetry_setTelemetryPresetConfigResp(
                        &respCtx,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY, TELEMETRY_SETTELEMETRYPRESETCONFIG_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method telemetry::setTelemetryPresetConfig (ID = 0x00000003)

// @START@ Request handler for method telemetry::setActivePreset (ID = 0x00000004)
static void telemetry_setActivePresetRequestHandlerImpl(ReqContext_t *pReqCtx,
            const telemetrysetActivePresetRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TELEMETRY_StandardResult_t eRes;
    uint8_t u8Avail_presets_cnt;

    // @USER_VAR_SECTION_START@telemetry::setActivePreset@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@telemetry::setActivePreset@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@telemetry::setActivePreset@
        u8Avail_presets_cnt = TELEMETRY_PRESETS_COUNT;

        if (pRequestData->eTlm_instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT)
        {
            bool valid_cfg = telemetry_cfg_set_active_preset(pRequestData->eTlm_instance_id, pRequestData->u8Req_active_preset);

            eRes = valid_cfg ? TELEMETRY_STANDARDRESULT_SUCCESS : TELEMETRY_STANDARDRESULT_INVALID_ARGS;
        }
        else
        {
            eRes = TELEMETRY_STANDARDRESULT_INVALID_ARGS;
        }
        // @USER_CODE_SECTION_END@telemetry::setActivePreset@

        respResult = telemetry_setActivePresetResp(
                        &respCtx,
                        eRes,
                        u8Avail_presets_cnt
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY, TELEMETRY_SETACTIVEPRESET_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method telemetry::setActivePreset (ID = 0x00000004)

// @START@ Request handler for method telemetry::getActivePreset (ID = 0x00000005)
static void telemetry_getActivePresetRequestHandlerImpl(ReqContext_t *pReqCtx,
            const telemetrygetActivePresetRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TELEMETRY_StandardResult_t eRes;
    uint8_t u8Active_preset_id;

    // @USER_VAR_SECTION_START@telemetry::getActivePreset@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@telemetry::getActivePreset@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@telemetry::getActivePreset@
        u8Active_preset_id = 0;

        if (pRequestData->eTlm_instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT)
        {
            u8Active_preset_id = telemetry_cfg_get_active_preset(pRequestData->eTlm_instance_id);

            eRes = TELEMETRY_STANDARDRESULT_SUCCESS;
        }
        else
        {
            eRes = TELEMETRY_STANDARDRESULT_INVALID_ARGS;
        }
        // @USER_CODE_SECTION_END@telemetry::getActivePreset@

        respResult = telemetry_getActivePresetResp(
                        &respCtx,
                        eRes,
                        u8Active_preset_id
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY, TELEMETRY_GETACTIVEPRESET_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method telemetry::getActivePreset (ID = 0x00000005)

// @START@ Request handler for method telemetry::restoreActivePreset (ID = 0x00000006)
static void telemetry_restoreActivePresetRequestHandlerImpl(ReqContext_t *pReqCtx,
            const telemetryrestoreActivePresetRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TELEMETRY_StandardResult_t eRes;

    // @USER_VAR_SECTION_START@telemetry::restoreActivePreset@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@telemetry::restoreActivePreset@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@telemetry::restoreActivePreset@
        if (pRequestData->eTlm_instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT)
        {
            telemetry_cfg_restore_active_preset(pRequestData->eTlm_instance_id);

            eRes = TELEMETRY_STANDARDRESULT_SUCCESS;
        }
        else
        {
            eRes = TELEMETRY_STANDARDRESULT_INVALID_ARGS;
        }
        // @USER_CODE_SECTION_END@telemetry::restoreActivePreset@

        respResult = telemetry_restoreActivePresetResp(
                        &respCtx,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY, TELEMETRY_RESTOREACTIVEPRESET_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method telemetry::restoreActivePreset (ID = 0x00000006)

// @START@ Request handler for method telemetry::getTelemetryFileSinkConfig (ID = 0x00000007)
static void telemetry_getTelemetryFileSinkConfigRequestHandlerImpl(ReqContext_t *pReqCtx,
            const telemetrygetTelemetryFileSinkConfigRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TELEMETRY_StandardResult_t eRes;
    TELEMETRY_tlm_file_logging_type_t eActive_file_cfg_type;
    TELEMETRY_tlm_file_size_limit_cfg_t sSize_limit_cfg;

    // @USER_VAR_SECTION_START@telemetry::getTelemetryFileSinkConfig@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@telemetry::getTelemetryFileSinkConfig@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@telemetry::getTelemetryFileSinkConfig@
        // only one type supported currently
        eActive_file_cfg_type                = TELEMETRY_TLM_FILE_LOGGING_TYPE_SIZE_LIMIT;
        sSize_limit_cfg.u32Size_limit_kb     = 0;
        sSize_limit_cfg.u16Max_log_files_cnt = 0;

        if (pRequestData->eTlm_instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT)
        {
            telemetry_file_cfg_t tlm_file_cfg;

            telemetry_cfg_get_file_config(pRequestData->eTlm_instance_id, (void *const)&tlm_file_cfg);

            sSize_limit_cfg.u32Size_limit_kb     = tlm_file_cfg.params.u32Size_limit_kb;
            sSize_limit_cfg.u16Max_log_files_cnt = tlm_file_cfg.params.u16Max_log_files_cnt;

            BREAK_ASSERT(TELEMETRY_TLM_FILE_LOGGING_TYPE_SIZE_LIMIT == tlm_file_cfg.cfg_type);

            eRes = TELEMETRY_STANDARDRESULT_SUCCESS;
        }
        else
        {
            eRes = TELEMETRY_STANDARDRESULT_INVALID_ARGS;
        }
        // @USER_CODE_SECTION_END@telemetry::getTelemetryFileSinkConfig@

        respResult = telemetry_getTelemetryFileSinkConfigResp(
                        &respCtx,
                        eRes,
                        eActive_file_cfg_type,
                        &sSize_limit_cfg
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY, TELEMETRY_GETTELEMETRYFILESINKCONFIG_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method telemetry::getTelemetryFileSinkConfig (ID = 0x00000007)

// @START@ Request handler for method telemetry::setTelemetryFileSzLimitConfig (ID = 0x00000008)
static void telemetry_setTelemetryFileSzLimitConfigRequestHandlerImpl(ReqContext_t *pReqCtx,
            const telemetrysetTelemetryFileSzLimitConfigRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TELEMETRY_StandardResult_t eRes;

    // @USER_VAR_SECTION_START@telemetry::setTelemetryFileSzLimitConfig@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@telemetry::setTelemetryFileSzLimitConfig@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@telemetry::setTelemetryFileSzLimitConfig@
        eRes = TELEMETRY_STANDARDRESULT_INVALID_ARGS;

        if ((pRequestData->eTlm_instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT) &&
            (pRequestData->sSize_limit_cfg.u16Max_log_files_cnt <= MAX_TLM_FILES_COUNT))
        {
            telemetry_file_cfg_t tlm_file_cfg;

            telemetry_cfg_get_file_config(pRequestData->eTlm_instance_id, (void *const)&tlm_file_cfg);

            if ((tlm_file_cfg.params.u16Max_log_files_cnt != pRequestData->sSize_limit_cfg.u16Max_log_files_cnt) ||
                (tlm_file_cfg.params.u32Size_limit_kb != pRequestData->sSize_limit_cfg.u32Size_limit_kb))
            {
                uint32_t rounded_file_sz = 0;

                if (pRequestData->sSize_limit_cfg.u16Max_log_files_cnt > 0)
                {
                    // the individual file size for the given configuration shall be non-zero after performing a rounding division, e.g. at least 1KB
                    rounded_file_sz = (pRequestData->sSize_limit_cfg.u32Size_limit_kb * 1024U) / pRequestData->sSize_limit_cfg.u16Max_log_files_cnt;
                }

                if (rounded_file_sz >= TLM_MSG_SIZE_BYTES_LEAST)
                {
                    tlm_file_cfg.params.u32Size_limit_kb     = pRequestData->sSize_limit_cfg.u32Size_limit_kb;
                    tlm_file_cfg.params.u16Max_log_files_cnt = pRequestData->sSize_limit_cfg.u16Max_log_files_cnt;
                    // set updated configuration as active
                    tlm_file_cfg.cfg_type = TELEMETRY_TLM_FILE_LOGGING_TYPE_SIZE_LIMIT;

                    telemetry_cfg_set_file_config(pRequestData->eTlm_instance_id, &tlm_file_cfg);

                    telemetry_file_sink_config_update(&telemetry_cfg_get_ctx(pRequestData->eTlm_instance_id)->tlm_file_sink_rt);
                    eRes = TELEMETRY_STANDARDRESULT_SUCCESS;
                }
            }
            else
            {
                // no change in configuration, hence the setting is just confirmed without any action
                eRes = TELEMETRY_STANDARDRESULT_SUCCESS;
            }
        }
        // @USER_CODE_SECTION_END@telemetry::setTelemetryFileSzLimitConfig@

        respResult = telemetry_setTelemetryFileSzLimitConfigResp(
                        &respCtx,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY, TELEMETRY_SETTELEMETRYFILESZLIMITCONFIG_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method telemetry::setTelemetryFileSzLimitConfig (ID = 0x00000008)

// @START@ Request handler for method telemetry::cleanTelemetryFiles (ID = 0x0000000B)
static void telemetry_cleanTelemetryFilesRequestHandlerImpl(ReqContext_t *pReqCtx,
            const telemetrycleanTelemetryFilesRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TELEMETRY_StandardResult_t eRes;

    // @USER_VAR_SECTION_START@telemetry::cleanTelemetryFiles@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@telemetry::cleanTelemetryFiles@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@telemetry::cleanTelemetryFiles@
        if (pRequestData->eTlm_instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT)
        {
            tlm_file_sink_rt_ctx_t *const p_tlm_filesink_rt_ctx = &telemetry_cfg_get_ctx(pRequestData->eTlm_instance_id)->tlm_file_sink_rt;

            telemetry_file_sink_syncd_clean(p_tlm_filesink_rt_ctx);

            eRes = TELEMETRY_STANDARDRESULT_SUCCESS;
        }
        else
        {
            eRes = TELEMETRY_STANDARDRESULT_INVALID_ARGS;
        }
        // @USER_CODE_SECTION_END@telemetry::cleanTelemetryFiles@

        respResult = telemetry_cleanTelemetryFilesResp(
                        &respCtx,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY, TELEMETRY_CLEANTELEMETRYFILES_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method telemetry::cleanTelemetryFiles (ID = 0x0000000B)

// @START@ Request handler for method telemetry::getTelemetryOperationStats (ID = 0x0000000C)
static void telemetry_getTelemetryOperationStatsRequestHandlerImpl(ReqContext_t *pReqCtx,
            const telemetrygetTelemetryOperationStatsRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TELEMETRY_StandardResult_t eRes;
    TELEMETRY_tlm_stats_t sTelemetry_stats;

    // @USER_VAR_SECTION_START@telemetry::getTelemetryOperationStats@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@telemetry::getTelemetryOperationStats@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@telemetry::getTelemetryOperationStats@
        if (pRequestData->eTlm_instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT)
        {
            tlm_queue_stats_t queue_stats;

            telemetry_queue_get_stats(&telemetry_cfg_get_ctx(pRequestData->eTlm_instance_id)->tlm_queue, &queue_stats);

            sTelemetry_stats.u32Discarded_messages_cnt  = queue_stats.discarded_messages_cnt;
            sTelemetry_stats.u32Free_bytes_min          = queue_stats.free_bytes_min;
            sTelemetry_stats.u32Max_number_of_batch_msg = queue_stats.max_number_of_batch_msg;
            sTelemetry_stats.u32Msg_popped_cnt          = queue_stats.msg_popped_cnt;
            sTelemetry_stats.u32Msg_pushed_cnt          = queue_stats.msg_pushed_cnt;
            sTelemetry_stats.u32Active_slot_id          = queue_stats.active_slot_id;
            sTelemetry_stats.bIs_started                = telemetry_is_started(telemetry_cfg_get_ctx(pRequestData->eTlm_instance_id));

            eRes = TELEMETRY_STANDARDRESULT_SUCCESS;
        }
        else
        {
            (void)memset(&sTelemetry_stats, 0U, sizeof(sTelemetry_stats));
            eRes = TELEMETRY_STANDARDRESULT_INVALID_ARGS;
        }
        // @USER_CODE_SECTION_END@telemetry::getTelemetryOperationStats@

        respResult = telemetry_getTelemetryOperationStatsResp(
                        &respCtx,
                        eRes,
                        &sTelemetry_stats
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY, TELEMETRY_GETTELEMETRYOPERATIONSTATS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method telemetry::getTelemetryOperationStats (ID = 0x0000000C)

// @START@ Request handler for method telemetry::startTelemetry (ID = 0x0000000D)
static void telemetry_startTelemetryRequestHandlerImpl(ReqContext_t *pReqCtx,
            const telemetrystartTelemetryRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TELEMETRY_StandardResult_t eRes;

    // @USER_VAR_SECTION_START@telemetry::startTelemetry@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@telemetry::startTelemetry@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@telemetry::startTelemetry@
        if (pRequestData->eTlm_instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT)
        {
            telemetry_start(telemetry_cfg_get_ctx(pRequestData->eTlm_instance_id), pRequestData->u16Hold_time_sec);
            eRes = TELEMETRY_STANDARDRESULT_SUCCESS;
        }
        else
        {
            eRes = TELEMETRY_STANDARDRESULT_INVALID_ARGS;
        }
        // @USER_CODE_SECTION_END@telemetry::startTelemetry@

        respResult = telemetry_startTelemetryResp(
                        &respCtx,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY, TELEMETRY_STARTTELEMETRY_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method telemetry::startTelemetry (ID = 0x0000000D)

// @START@ Request handler for method telemetry::stopTelemetry (ID = 0x0000000E)
static void telemetry_stopTelemetryRequestHandlerImpl(ReqContext_t *pReqCtx,
            const telemetrystopTelemetryRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TELEMETRY_StandardResult_t eRes;

    // @USER_VAR_SECTION_START@telemetry::stopTelemetry@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@telemetry::stopTelemetry@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@telemetry::stopTelemetry@
        if (pRequestData->eTlm_instance_id < TELEMETRY_TELEMETRYINSTANCE_MAX_CNT)
        {
            telemetry_stop(telemetry_cfg_get_ctx(pRequestData->eTlm_instance_id), pRequestData->u16Hold_time_sec);
            eRes = TELEMETRY_STANDARDRESULT_SUCCESS;
        }
        else
        {
            eRes = TELEMETRY_STANDARDRESULT_INVALID_ARGS;
        }
        // @USER_CODE_SECTION_END@telemetry::stopTelemetry@

        respResult = telemetry_stopTelemetryResp(
                        &respCtx,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TELEMETRY, TELEMETRY_STOPTELEMETRY_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method telemetry::stopTelemetry (ID = 0x0000000E)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void telemetryServerAppInit(void)
{
    telemetry_registerServerApi(&telemetryServerApiCtx);
}
