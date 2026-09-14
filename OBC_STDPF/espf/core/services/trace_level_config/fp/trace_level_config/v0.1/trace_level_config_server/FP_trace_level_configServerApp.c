/*!
********************************************************************************************
* @file FP_trace_level_configServerApp.c
* @brief ServerApp implementation template generator
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

#include "FP_trace_level_configProtocolServer.h"

// @START_USER@ USER_INCLUDES
// Place user includes here to preserve them during merge!!!
#include "trace.h"
#include "assertions.h"

#include <string.h>
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
static void trace_copy_string_add_null_terminator(const char *const p_input_data, const uint32_t input_size, char *const p_output_data, const uint32_t output_size);
// @END_USER@ USER_LOCAL_FUNC_DECL
static void trace_level_config_set_channel_trace_levelRequestHandlerImpl(ReqContext_t* pReqCtx,
            const trace_level_configset_channel_trace_levelRequestData_t* pRequestData);

static void trace_level_config_get_channel_infoRequestHandlerImpl(ReqContext_t* pReqCtx);

static void trace_level_config_set_channel_active_statusRequestHandlerImpl(ReqContext_t* pReqCtx,
            const trace_level_configset_channel_active_statusRequestData_t* pRequestData);

static void trace_level_config_set_module_active_statusRequestHandlerImpl(ReqContext_t* pReqCtx,
            const trace_level_configset_module_active_statusRequestData_t* pRequestData);

static void trace_level_config_set_module_trace_levelRequestHandlerImpl(ReqContext_t* pReqCtx,
            const trace_level_configset_module_trace_levelRequestData_t* pRequestData);

static void trace_level_config_get_module_infoRequestHandlerImpl(ReqContext_t* pReqCtx,
            const trace_level_configget_module_infoRequestData_t* pRequestData);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)
// @END_USER@ USER_LOCAL_VARS_DECL

static trace_level_config_ServerApi_t trace_level_configServerApiCtx =
{
  .trace_level_config_set_channel_trace_levelRequestHandler = trace_level_config_set_channel_trace_levelRequestHandlerImpl,
  .trace_level_config_get_channel_infoRequestHandler = trace_level_config_get_channel_infoRequestHandlerImpl,
  .trace_level_config_set_channel_active_statusRequestHandler = trace_level_config_set_channel_active_statusRequestHandlerImpl,
  .trace_level_config_set_module_active_statusRequestHandler = trace_level_config_set_module_active_statusRequestHandlerImpl,
  .trace_level_config_set_module_trace_levelRequestHandler = trace_level_config_set_module_trace_levelRequestHandlerImpl,
  .trace_level_config_get_module_infoRequestHandler = trace_level_config_get_module_infoRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
static void trace_copy_string_add_null_terminator(const char *const p_input_data, const uint32_t input_size, char *const p_output_data, const uint32_t output_size)
{
    CRIT_ASSERT(NULL != p_input_data);
    CRIT_ASSERT(NULL != p_output_data);

    if ((input_size > 0) && (output_size > 0))
    {
        strncpy(p_output_data, p_input_data, output_size);

        p_output_data[output_size - 1] = '\0';
    }
}
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method trace_level_config::set_channel_trace_level (ID = 0x00000000)
static void trace_level_config_set_channel_trace_levelRequestHandlerImpl(ReqContext_t *pReqCtx,
            const trace_level_configset_channel_trace_levelRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TRACE_LEVEL_CONFIG_Result_t eRes;

    // @USER_VAR_SECTION_START@trace_level_config::set_channel_trace_level@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@trace_level_config::set_channel_trace_level@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@trace_level_config::set_channel_trace_level@

        eRes = TRACE_LEVEL_CONFIG_RESULT_FAILED;
        if (TRACE_LEVEL_CONFIG_CHANNELS_ALL == pRequestData->eChannel)
        {
            if(false != trace_set_all_channels_level(pRequestData->eLevel))
            {
                eRes = TRACE_LEVEL_CONFIG_RESULT_SUCCESS;
            }
        }
        else
        {
            if (false != trace_set_channel_level(pRequestData->eChannel, pRequestData->eLevel))
            {
                eRes = TRACE_LEVEL_CONFIG_RESULT_SUCCESS;
            }
        }

        // @USER_CODE_SECTION_END@trace_level_config::set_channel_trace_level@

        respResult = trace_level_config_set_channel_trace_levelResp(
                        &respCtx,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TRACE_LEVEL_CONFIG, TRACE_LEVEL_CONFIG_SET_CHANNEL_TRACE_LEVEL_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method trace_level_config::set_channel_trace_level (ID = 0x00000000)

// @START@ Request handler for method trace_level_config::get_channel_info (ID = 0x00000001)
static void trace_level_config_get_channel_infoRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TRACE_LEVEL_CONFIG_ChannelInfo_t asChannels[3];
    TRACE_LEVEL_CONFIG_Result_t eRes;

    // @USER_VAR_SECTION_START@trace_level_config::get_channel_info@
    // Put your local variables in this section to preserve during merge!
    trace_channel_info_t channel_info;
    // @USER_VAR_SECTION_END@trace_level_config::get_channel_info@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@trace_level_config::get_channel_info@

        eRes = TRACE_LEVEL_CONFIG_RESULT_SUCCESS;
        for (uint8_t channel = TRACE_LEVEL_CONFIG_CHANNELS_UART; channel < TRACE_LEVEL_CONFIG_CHANNELS_ALL; channel++)
        {
            if (false == trace_get_channel_info(channel, &channel_info))
            {
                eRes = TRACE_LEVEL_CONFIG_RESULT_FAILED;
                break;
            }
            asChannels[channel].eChannel = channel;
            asChannels[channel].bActive = channel_info.active;
            asChannels[channel].eLevel = (uint8_t)channel_info.level;
        }
        // @USER_CODE_SECTION_END@trace_level_config::get_channel_info@

        respResult = trace_level_config_get_channel_infoResp(
                        &respCtx,
                        asChannels,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TRACE_LEVEL_CONFIG, TRACE_LEVEL_CONFIG_GET_CHANNEL_INFO_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method trace_level_config::get_channel_info (ID = 0x00000001)

// @START@ Request handler for method trace_level_config::set_channel_active_status (ID = 0x00000002)
static void trace_level_config_set_channel_active_statusRequestHandlerImpl(ReqContext_t *pReqCtx,
            const trace_level_configset_channel_active_statusRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TRACE_LEVEL_CONFIG_Result_t eRes;

    // @USER_VAR_SECTION_START@trace_level_config::set_channel_active_status@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@trace_level_config::set_channel_active_status@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@trace_level_config::set_channel_active_status@

        eRes = TRACE_LEVEL_CONFIG_RESULT_FAILED;
        if (TRACE_LEVEL_CONFIG_CHANNELS_ALL == pRequestData->eChannel)
        {
            if(false != trace_set_all_channels_active(pRequestData->bIs_active))
            {
                eRes = TRACE_LEVEL_CONFIG_RESULT_SUCCESS;
            }
        }
        else
        {
            if (false != trace_set_channel_active(pRequestData->eChannel, pRequestData->bIs_active))
            {
                eRes = TRACE_LEVEL_CONFIG_RESULT_SUCCESS;
            }
        }

        // @USER_CODE_SECTION_END@trace_level_config::set_channel_active_status@

        respResult = trace_level_config_set_channel_active_statusResp(
                        &respCtx,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TRACE_LEVEL_CONFIG, TRACE_LEVEL_CONFIG_SET_CHANNEL_ACTIVE_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method trace_level_config::set_channel_active_status (ID = 0x00000002)

// @START@ Request handler for method trace_level_config::set_module_active_status (ID = 0x00000003)
static void trace_level_config_set_module_active_statusRequestHandlerImpl(ReqContext_t *pReqCtx,
            const trace_level_configset_module_active_statusRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TRACE_LEVEL_CONFIG_Result_t eRes;

    // @USER_VAR_SECTION_START@trace_level_config::set_module_active_status@
    // Put your local variables in this section to preserve during merge!
    char module_wild_card[sizeof(pRequestData->strModule)] = {'\0'};
    // @USER_VAR_SECTION_END@trace_level_config::set_module_active_status@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@trace_level_config::set_module_active_status@

        eRes = TRACE_LEVEL_CONFIG_RESULT_FAILED;

        trace_copy_string_add_null_terminator(pRequestData->strModule, sizeof(pRequestData->strModule), module_wild_card, sizeof(module_wild_card));

        if (true == trace_perform_module_op(module_wild_card, &trace_op_set_active_flag, (void * const)&pRequestData->bIs_active))
        {
            eRes = TRACE_LEVEL_CONFIG_RESULT_SUCCESS;
        }

        // @USER_CODE_SECTION_END@trace_level_config::set_module_active_status@

        respResult = trace_level_config_set_module_active_statusResp(
                        &respCtx,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TRACE_LEVEL_CONFIG, TRACE_LEVEL_CONFIG_SET_MODULE_ACTIVE_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method trace_level_config::set_module_active_status (ID = 0x00000003)

// @START@ Request handler for method trace_level_config::set_module_trace_level (ID = 0x00000004)
static void trace_level_config_set_module_trace_levelRequestHandlerImpl(ReqContext_t *pReqCtx,
            const trace_level_configset_module_trace_levelRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TRACE_LEVEL_CONFIG_Result_t eRes;

    // @USER_VAR_SECTION_START@trace_level_config::set_module_trace_level@
    // Put your local variables in this section to preserve during merge!
    char module_wild_card[sizeof(pRequestData->strModule)] = {'\0'};
    // @USER_VAR_SECTION_END@trace_level_config::set_module_trace_level@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@trace_level_config::set_module_trace_level@

        eRes = TRACE_LEVEL_CONFIG_RESULT_FAILED;

        trace_copy_string_add_null_terminator(pRequestData->strModule, sizeof(pRequestData->strModule), module_wild_card, sizeof(module_wild_card));

        if (true == trace_perform_module_op(module_wild_card, &trace_op_set_level, (void * const)&pRequestData->eLevel))
        {
            eRes = TRACE_LEVEL_CONFIG_RESULT_SUCCESS;
        }

        // @USER_CODE_SECTION_END@trace_level_config::set_module_trace_level@

        respResult = trace_level_config_set_module_trace_levelResp(
                        &respCtx,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TRACE_LEVEL_CONFIG, TRACE_LEVEL_CONFIG_SET_MODULE_TRACE_LEVEL_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method trace_level_config::set_module_trace_level (ID = 0x00000004)

// @START@ Request handler for method trace_level_config::get_module_info (ID = 0x00000005)
static void trace_level_config_get_module_infoRequestHandlerImpl(ReqContext_t *pReqCtx,
            const trace_level_configget_module_infoRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TRACE_LEVEL_CONFIG_ModuleInfo_t sModule_output;
    TRACE_LEVEL_CONFIG_Result_t eRes;

    // @USER_VAR_SECTION_START@trace_level_config::get_module_info@
    // Put your local variables in this section to preserve during merge!
    trace_module_info_t trace_module;
    char input_module_name[sizeof(pRequestData->strModule_name_input)] = {'\0'};
    // @USER_VAR_SECTION_END@trace_level_config::get_module_info@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@trace_level_config::get_module_info@

        eRes = TRACE_LEVEL_CONFIG_RESULT_FAILED;

        trace_copy_string_add_null_terminator(pRequestData->strModule_name_input, sizeof(pRequestData->strModule_name_input), input_module_name, sizeof(input_module_name));

        memset((void *)sModule_output.strModule_name, '\0', sizeof(sModule_output.strModule_name));

        if (true == trace_perform_module_op(input_module_name, &trace_op_get_module_info, (void*)&trace_module))
        {
            sModule_output.bActive = trace_module.is_active;
            sModule_output.eLevel = (TRACE_LEVEL_CONFIG_TraceLevels_t)trace_module.level;
            eRes = TRACE_LEVEL_CONFIG_RESULT_SUCCESS;
            trace_copy_string_add_null_terminator(input_module_name, sizeof(input_module_name), (char *)sModule_output.strModule_name, sizeof(sModule_output.strModule_name));
        }

        // @USER_CODE_SECTION_END@trace_level_config::get_module_info@

        respResult = trace_level_config_get_module_infoResp(
                        &respCtx,
                        &sModule_output,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TRACE_LEVEL_CONFIG, TRACE_LEVEL_CONFIG_GET_MODULE_INFO_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method trace_level_config::get_module_info (ID = 0x00000005)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void trace_level_configServerAppInit(void)
{
    trace_level_config_registerServerApi(&trace_level_configServerApiCtx);
}
