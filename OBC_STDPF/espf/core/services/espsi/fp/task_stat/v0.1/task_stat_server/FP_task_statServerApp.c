/*!
********************************************************************************************
* @file FP_task_statServerApp.c
* @brief ServerApp implementation template generator
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

#include "FP_task_statProtocolServer.h"

// @START_USER@ USER_INCLUDES
// Place user includes here to preserve them during merge!!!
#include "taskmon_stat.h"
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL
static void task_stat_get_configurationRequestHandlerImpl(ReqContext_t* pReqCtx);

static void task_stat_set_configuration_global_enableRequestHandlerImpl(ReqContext_t* pReqCtx,
            const task_statset_configuration_global_enableRequestData_t* pRequestData);

static void task_stat_set_configuration_global_loggingRequestHandlerImpl(ReqContext_t* pReqCtx,
            const task_statset_configuration_global_loggingRequestData_t* pRequestData);

static void task_stat_set_configuration_global_priorityRequestHandlerImpl(ReqContext_t* pReqCtx,
            const task_statset_configuration_global_priorityRequestData_t* pRequestData);

static void task_stat_set_configuration_global_sampling_periodRequestHandlerImpl(ReqContext_t* pReqCtx,
            const task_statset_configuration_global_sampling_periodRequestData_t* pRequestData);

static void task_stat_set_configuration_global_id_fileRequestHandlerImpl(ReqContext_t* pReqCtx,
            const task_statset_configuration_global_id_fileRequestData_t* pRequestData);

static void task_stat_set_configuration_global_defaultsRequestHandlerImpl(ReqContext_t* pReqCtx);

static void task_stat_get_configuration_per_task_idRequestHandlerImpl(ReqContext_t* pReqCtx,
            const task_statget_configuration_per_task_idRequestData_t* pRequestData);

static void task_stat_set_configuration_per_task_idRequestHandlerImpl(ReqContext_t* pReqCtx,
            const task_statset_configuration_per_task_idRequestData_t* pRequestData);

static void task_stat_get_free_heapRequestHandlerImpl(ReqContext_t* pReqCtx);

static void task_stat_get_latest_task_statRequestHandlerImpl(ReqContext_t* pReqCtx,
            const task_statget_latest_task_statRequestData_t* pRequestData);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)
// @END_USER@ USER_LOCAL_VARS_DECL

static task_stat_ServerApi_t task_statServerApiCtx =
{
  .task_stat_get_configurationRequestHandler = task_stat_get_configurationRequestHandlerImpl,
  .task_stat_set_configuration_global_enableRequestHandler = task_stat_set_configuration_global_enableRequestHandlerImpl,
  .task_stat_set_configuration_global_loggingRequestHandler = task_stat_set_configuration_global_loggingRequestHandlerImpl,
  .task_stat_set_configuration_global_priorityRequestHandler = task_stat_set_configuration_global_priorityRequestHandlerImpl,
  .task_stat_set_configuration_global_sampling_periodRequestHandler = task_stat_set_configuration_global_sampling_periodRequestHandlerImpl,
  .task_stat_set_configuration_global_id_fileRequestHandler = task_stat_set_configuration_global_id_fileRequestHandlerImpl,
  .task_stat_set_configuration_global_defaultsRequestHandler = task_stat_set_configuration_global_defaultsRequestHandlerImpl,
  .task_stat_get_configuration_per_task_idRequestHandler = task_stat_get_configuration_per_task_idRequestHandlerImpl,
  .task_stat_set_configuration_per_task_idRequestHandler = task_stat_set_configuration_per_task_idRequestHandlerImpl,
  .task_stat_get_free_heapRequestHandler = task_stat_get_free_heapRequestHandlerImpl,
  .task_stat_get_latest_task_statRequestHandler = task_stat_get_latest_task_statRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method task_stat::get_configuration (ID = 0x00000001)
static void task_stat_get_configurationRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TASK_STAT_OpStatus_t eStatus;
    TASK_STAT_StatsConfig_t sConfig;

    // @USER_VAR_SECTION_START@task_stat::get_configuration@
    // Put your local variables in this section to preserve during merge!
    task_mon_stat_config_t task_cfg;
    // @USER_VAR_SECTION_END@task_stat::get_configuration@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@task_stat::get_configuration@

        task_cfg = task_mon_stat_get_configuration();
        sConfig.bEnable = task_cfg.enabled;
        sConfig.bLogging = task_cfg.logging;
        sConfig.u8Priority = (uint8_t)task_cfg.priority;
        sConfig.u32Period = task_cfg.period;
        memset(sConfig.strTask_id_table_file, 0, sizeof(sConfig.strTask_id_table_file));
        strncpy(sConfig.strTask_id_table_file, task_cfg.id_table_file, sizeof(sConfig.strTask_id_table_file) - 1);
        if (sConfig.strTask_id_table_file[sizeof(sConfig.strTask_id_table_file) - 1] != 0)
        {
            eStatus = TASK_STAT_OPSTATUS_ERROR;
            sConfig.strTask_id_table_file[0] = 0;
            sConfig.u8Task_id_table_fileSize = 0;
        }
        else
        {
            sConfig.u8Task_id_table_fileSize = (uint8_t)strnlen(sConfig.strTask_id_table_file, sizeof(sConfig.strTask_id_table_file) - 1);
            eStatus = TASK_STAT_OPSTATUS_SUCCESS;
        }

        // @USER_CODE_SECTION_END@task_stat::get_configuration@

        respResult = task_stat_get_configurationResp(
                        &respCtx,
                        eStatus,
                        &sConfig
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT, TASK_STAT_GET_CONFIGURATION_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method task_stat::get_configuration (ID = 0x00000001)

// @START@ Request handler for method task_stat::set_configuration_global_enable (ID = 0x00000010)
static void task_stat_set_configuration_global_enableRequestHandlerImpl(ReqContext_t *pReqCtx,
            const task_statset_configuration_global_enableRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    bool bStatus;

    // @USER_VAR_SECTION_START@task_stat::set_configuration_global_enable@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@task_stat::set_configuration_global_enable@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@task_stat::set_configuration_global_enable@

        bStatus = task_mon_stat_set_configuration(TASK_STAT_UPDATE_ENABLE, pRequestData->bEnable, 0, 0, 0, NULL);

        // @USER_CODE_SECTION_END@task_stat::set_configuration_global_enable@

        respResult = task_stat_set_configuration_global_enableResp(
                        &respCtx,
                        bStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT, TASK_STAT_SET_CONFIGURATION_GLOBAL_ENABLE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method task_stat::set_configuration_global_enable (ID = 0x00000010)

// @START@ Request handler for method task_stat::set_configuration_global_logging (ID = 0x00000011)
static void task_stat_set_configuration_global_loggingRequestHandlerImpl(ReqContext_t *pReqCtx,
            const task_statset_configuration_global_loggingRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    bool bStatus;

    // @USER_VAR_SECTION_START@task_stat::set_configuration_global_logging@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@task_stat::set_configuration_global_logging@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@task_stat::set_configuration_global_logging@

        bStatus = task_mon_stat_set_configuration(TASK_STAT_UPDATE_LOGGING, 0, pRequestData->bLogging, 0, 0, NULL);

        // @USER_CODE_SECTION_END@task_stat::set_configuration_global_logging@

        respResult = task_stat_set_configuration_global_loggingResp(
                        &respCtx,
                        bStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT, TASK_STAT_SET_CONFIGURATION_GLOBAL_LOGGING_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method task_stat::set_configuration_global_logging (ID = 0x00000011)

// @START@ Request handler for method task_stat::set_configuration_global_priority (ID = 0x00000012)
static void task_stat_set_configuration_global_priorityRequestHandlerImpl(ReqContext_t *pReqCtx,
            const task_statset_configuration_global_priorityRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    bool bStatus;

    // @USER_VAR_SECTION_START@task_stat::set_configuration_global_priority@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@task_stat::set_configuration_global_priority@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@task_stat::set_configuration_global_priority@

        bStatus = task_mon_stat_set_configuration(TASK_STAT_UPDATE_PRIORITY, 0, 0, pRequestData->u8Priority, 0, NULL);

        // @USER_CODE_SECTION_END@task_stat::set_configuration_global_priority@

        respResult = task_stat_set_configuration_global_priorityResp(
                        &respCtx,
                        bStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT, TASK_STAT_SET_CONFIGURATION_GLOBAL_PRIORITY_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method task_stat::set_configuration_global_priority (ID = 0x00000012)

// @START@ Request handler for method task_stat::set_configuration_global_sampling_period (ID = 0x00000014)
static void task_stat_set_configuration_global_sampling_periodRequestHandlerImpl(ReqContext_t *pReqCtx,
            const task_statset_configuration_global_sampling_periodRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    bool bStatus;

    // @USER_VAR_SECTION_START@task_stat::set_configuration_global_sampling_period@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@task_stat::set_configuration_global_sampling_period@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@task_stat::set_configuration_global_sampling_period@

        bStatus = task_mon_stat_set_configuration(TASK_STAT_UPDATE_PERIOD, 0, 0, 0, pRequestData->u32Sampling_period, NULL);

        // @USER_CODE_SECTION_END@task_stat::set_configuration_global_sampling_period@

        respResult = task_stat_set_configuration_global_sampling_periodResp(
                        &respCtx,
                        bStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT, TASK_STAT_SET_CONFIGURATION_GLOBAL_SAMPLING_PERIOD_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method task_stat::set_configuration_global_sampling_period (ID = 0x00000014)

// @START@ Request handler for method task_stat::set_configuration_global_id_file (ID = 0x00000015)
static void task_stat_set_configuration_global_id_fileRequestHandlerImpl(ReqContext_t *pReqCtx,
            const task_statset_configuration_global_id_fileRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    bool bStatus;

    // @USER_VAR_SECTION_START@task_stat::set_configuration_global_id_file@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@task_stat::set_configuration_global_id_file@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@task_stat::set_configuration_global_id_file@

        bStatus = task_mon_stat_set_configuration(TASK_STAT_UPDATE_ID_TABLE, 0, 0, 0, 0, pRequestData->strTask_id_table_file);

        // @USER_CODE_SECTION_END@task_stat::set_configuration_global_id_file@

        respResult = task_stat_set_configuration_global_id_fileResp(
                        &respCtx,
                        bStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT, TASK_STAT_SET_CONFIGURATION_GLOBAL_ID_FILE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method task_stat::set_configuration_global_id_file (ID = 0x00000015)

// @START@ Request handler for method task_stat::set_configuration_global_defaults (ID = 0x0000001F)
static void task_stat_set_configuration_global_defaultsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    bool bStatus;

    // @USER_VAR_SECTION_START@task_stat::set_configuration_global_defaults@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@task_stat::set_configuration_global_defaults@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@task_stat::set_configuration_global_defaults@

        bStatus = task_mon_stat_set_configuration(TASK_STAT_UPDATE_DEFAULT, 0, 0, 0, 0, NULL);

        // @USER_CODE_SECTION_END@task_stat::set_configuration_global_defaults@

        respResult = task_stat_set_configuration_global_defaultsResp(
                        &respCtx,
                        bStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT, TASK_STAT_SET_CONFIGURATION_GLOBAL_DEFAULTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method task_stat::set_configuration_global_defaults (ID = 0x0000001F)

// @START@ Request handler for method task_stat::get_configuration_per_task_id (ID = 0x00000003)
static void task_stat_get_configuration_per_task_idRequestHandlerImpl(ReqContext_t *pReqCtx,
            const task_statget_configuration_per_task_idRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TASK_STAT_OpStatus_t eStatus;
    TASK_STAT_TaskStatConfig_t sTask_cfg;

    // @USER_VAR_SECTION_START@task_stat::get_configuration_per_task_id@
    // Put your local variables in this section to preserve during merge!
    task_stat_t task_stat;
    // @USER_VAR_SECTION_END@task_stat::get_configuration_per_task_id@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@task_stat::get_configuration_per_task_id@

        eStatus = TASK_STAT_OPSTATUS_ERROR;
        if (pRequestData->u8Id < TASK_ID_MAX)
        {
            task_stat = task_mon_stat_get_configuration_per_id(pRequestData->u8Id);
            sTask_cfg.u8Id = pRequestData->u8Id;
            sTask_cfg.bEnabled = task_stat.enabled;
            sTask_cfg.bLogging = task_stat.logging;
            eStatus = TASK_STAT_OPSTATUS_SUCCESS;
        }

        // @USER_CODE_SECTION_END@task_stat::get_configuration_per_task_id@

        respResult = task_stat_get_configuration_per_task_idResp(
                        &respCtx,
                        eStatus,
                        &sTask_cfg
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT, TASK_STAT_GET_CONFIGURATION_PER_TASK_ID_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method task_stat::get_configuration_per_task_id (ID = 0x00000003)

// @START@ Request handler for method task_stat::set_configuration_per_task_id (ID = 0x00000004)
static void task_stat_set_configuration_per_task_idRequestHandlerImpl(ReqContext_t *pReqCtx,
            const task_statset_configuration_per_task_idRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TASK_STAT_OpStatus_t eStatus;

    // @USER_VAR_SECTION_START@task_stat::set_configuration_per_task_id@
    // Put your local variables in this section to preserve during merge!
    bool ret;
    // @USER_VAR_SECTION_END@task_stat::set_configuration_per_task_id@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@task_stat::set_configuration_per_task_id@

        ret = task_mon_stat_set_configuration_per_id(pRequestData->sTask_cfg.u8Id, pRequestData->sTask_cfg.bEnabled, pRequestData->sTask_cfg.bLogging);
        eStatus = (ret == true) ? TASK_STAT_OPSTATUS_SUCCESS : TASK_STAT_OPSTATUS_ERROR; 

        // @USER_CODE_SECTION_END@task_stat::set_configuration_per_task_id@

        respResult = task_stat_set_configuration_per_task_idResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT, TASK_STAT_SET_CONFIGURATION_PER_TASK_ID_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method task_stat::set_configuration_per_task_id (ID = 0x00000004)

// @START@ Request handler for method task_stat::get_free_heap (ID = 0x00000006)
static void task_stat_get_free_heapRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TASK_STAT_OpStatus_t eStatus;
    uint32_t u32Free_heap;

    // @USER_VAR_SECTION_START@task_stat::get_free_heap@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@task_stat::get_free_heap@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@task_stat::get_free_heap@

        u32Free_heap = xPortGetFreeHeapSize();
        eStatus = TASK_STAT_OPSTATUS_SUCCESS;

        // @USER_CODE_SECTION_END@task_stat::get_free_heap@

        respResult = task_stat_get_free_heapResp(
                        &respCtx,
                        eStatus,
                        u32Free_heap
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT, TASK_STAT_GET_FREE_HEAP_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method task_stat::get_free_heap (ID = 0x00000006)

// @START@ Request handler for method task_stat::get_latest_task_stat (ID = 0x00000005)
static void task_stat_get_latest_task_statRequestHandlerImpl(ReqContext_t *pReqCtx,
            const task_statget_latest_task_statRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    TASK_STAT_OpStatus_t eStatus;
    TASK_STAT_TaskStatSample_t sStat;

    // @USER_VAR_SECTION_START@task_stat::get_latest_task_stat@
    // Put your local variables in this section to preserve during merge!
    task_stat_t task_stat;
    // @USER_VAR_SECTION_END@task_stat::get_latest_task_stat@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@task_stat::get_latest_task_stat@

        task_stat = task_mon_stat_get_configuration_per_id(pRequestData->u8Id);
        eStatus = (NULL == task_stat.task_handle) ? TASK_STAT_OPSTATUS_ERROR : TASK_STAT_OPSTATUS_SUCCESS;
        sStat.u8Id = pRequestData->u8Id;
        sStat.u32Run_time = task_stat.runtime;
        sStat.u16Free_stack = task_stat.stack_unused_bytes;

        // @USER_CODE_SECTION_END@task_stat::get_latest_task_stat@

        respResult = task_stat_get_latest_task_statResp(
                        &respCtx,
                        eStatus,
                        &sStat
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_TASK_STAT, TASK_STAT_GET_LATEST_TASK_STAT_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method task_stat::get_latest_task_stat (ID = 0x00000005)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void task_statServerAppInit(void)
{
    task_stat_registerServerApi(&task_statServerApiCtx);
}
