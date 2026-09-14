/*!
********************************************************************************************
* @file FP_fdir_srvServerApp.c
* @brief ServerApp implementation template generator
********************************************************************************************
* @version           interface fdir_srv v0.2
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

#include "FP_fdir_srvProtocolServer.h"

// @START_USER@ USER_INCLUDES

#include "fdir_srv.h"

// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL
static void fdir_srv_get_system_fdir_levelRequestHandlerImpl(ReqContext_t* pReqCtx);

static void fdir_srv_get_agent_fdir_levelRequestHandlerImpl(ReqContext_t* pReqCtx,
            const fdir_srvget_agent_fdir_levelRequestData_t* pRequestData);

static void fdir_srv_get_detection_for_faultRequestHandlerImpl(ReqContext_t* pReqCtx,
            const fdir_srvget_detection_for_faultRequestData_t* pRequestData);

static void fdir_srv_set_detection_for_faultRequestHandlerImpl(ReqContext_t* pReqCtx,
            const fdir_srvset_detection_for_faultRequestData_t* pRequestData);

static void fdir_srv_set_detection_for_all_faultsRequestHandlerImpl(ReqContext_t* pReqCtx,
            const fdir_srvset_detection_for_all_faultsRequestData_t* pRequestData);

static void fdir_srv_get_min_active_fdirRequestHandlerImpl(ReqContext_t* pReqCtx);

static void fdir_srv_set_min_active_fdirRequestHandlerImpl(ReqContext_t* pReqCtx,
            const fdir_srvset_min_active_fdirRequestData_t* pRequestData);

static void fdir_srv_get_fault_user_clear_levelRequestHandlerImpl(ReqContext_t* pReqCtx);

static void fdir_srv_set_fault_user_clear_levelRequestHandlerImpl(ReqContext_t* pReqCtx,
            const fdir_srvset_fault_user_clear_levelRequestData_t* pRequestData);

static void fdir_srv_get_faultRequestHandlerImpl(ReqContext_t* pReqCtx,
            const fdir_srvget_faultRequestData_t* pRequestData);

static void fdir_srv_set_faultRequestHandlerImpl(ReqContext_t* pReqCtx,
            const fdir_srvset_faultRequestData_t* pRequestData);

static void fdir_srv_force_clear_faultRequestHandlerImpl(ReqContext_t* pReqCtx,
            const fdir_srvforce_clear_faultRequestData_t* pRequestData);

static void fdir_srv_force_clear_all_faultsRequestHandlerImpl(ReqContext_t* pReqCtx);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_VARS_DECL

static fdir_srv_ServerApi_t fdir_srvServerApiCtx =
{
  .fdir_srv_get_system_fdir_levelRequestHandler = fdir_srv_get_system_fdir_levelRequestHandlerImpl,
  .fdir_srv_get_agent_fdir_levelRequestHandler = fdir_srv_get_agent_fdir_levelRequestHandlerImpl,
  .fdir_srv_get_detection_for_faultRequestHandler = fdir_srv_get_detection_for_faultRequestHandlerImpl,
  .fdir_srv_set_detection_for_faultRequestHandler = fdir_srv_set_detection_for_faultRequestHandlerImpl,
  .fdir_srv_set_detection_for_all_faultsRequestHandler = fdir_srv_set_detection_for_all_faultsRequestHandlerImpl,
  .fdir_srv_get_min_active_fdirRequestHandler = fdir_srv_get_min_active_fdirRequestHandlerImpl,
  .fdir_srv_set_min_active_fdirRequestHandler = fdir_srv_set_min_active_fdirRequestHandlerImpl,
  .fdir_srv_get_fault_user_clear_levelRequestHandler = fdir_srv_get_fault_user_clear_levelRequestHandlerImpl,
  .fdir_srv_set_fault_user_clear_levelRequestHandler = fdir_srv_set_fault_user_clear_levelRequestHandlerImpl,
  .fdir_srv_get_faultRequestHandler = fdir_srv_get_faultRequestHandlerImpl,
  .fdir_srv_set_faultRequestHandler = fdir_srv_set_faultRequestHandlerImpl,
  .fdir_srv_force_clear_faultRequestHandler = fdir_srv_force_clear_faultRequestHandlerImpl,
  .fdir_srv_force_clear_all_faultsRequestHandler = fdir_srv_force_clear_all_faultsRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method fdir_srv::get_system_fdir_level (ID = 0x00000001)
static void fdir_srv_get_system_fdir_levelRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FDIR_SRV_return_status_t eStatus;
    uint8_t u8Fdir_level;

    // @USER_VAR_SECTION_START@fdir_srv::get_system_fdir_level@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@fdir_srv::get_system_fdir_level@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@fdir_srv::get_system_fdir_level@

        u8Fdir_level = fdir_srv_system_get_fdir_level();
        if (FDIR_LEVEL_MAX >= u8Fdir_level)
        {
            eStatus = FDIR_SRV_RETURN_STATUS_SUCCESS;
        }
        else
        {
            eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INTERNAL;
        }

        // @USER_CODE_SECTION_END@fdir_srv::get_system_fdir_level@

        respResult = fdir_srv_get_system_fdir_levelResp(
                        &respCtx,
                        eStatus,
                        u8Fdir_level
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV, FDIR_SRV_GET_SYSTEM_FDIR_LEVEL_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method fdir_srv::get_system_fdir_level (ID = 0x00000001)

// @START@ Request handler for method fdir_srv::get_agent_fdir_level (ID = 0x00000002)
static void fdir_srv_get_agent_fdir_levelRequestHandlerImpl(ReqContext_t *pReqCtx,
            const fdir_srvget_agent_fdir_levelRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FDIR_SRV_return_status_t eStatus;
    uint8_t u8Fdir_level;

    // @USER_VAR_SECTION_START@fdir_srv::get_agent_fdir_level@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@fdir_srv::get_agent_fdir_level@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@fdir_srv::get_agent_fdir_level@

        u8Fdir_level = FDIR_LEVEL_INVALID;
        if (FDIR_AGENT_COUNT > pRequestData->u16Agent_id)
        {
            u8Fdir_level = fdir_srv_agent_get_fdir_level(pRequestData->u16Agent_id);
            if (FDIR_LEVEL_MAX >= u8Fdir_level)
            {
                eStatus = FDIR_SRV_RETURN_STATUS_SUCCESS;
            }
            else
            {
                eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INTERNAL;
            }
        }
        else
        {
            eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INVALID_AGENT_ID;
        }

        // @USER_CODE_SECTION_END@fdir_srv::get_agent_fdir_level@

        respResult = fdir_srv_get_agent_fdir_levelResp(
                        &respCtx,
                        eStatus,
                        u8Fdir_level
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV, FDIR_SRV_GET_AGENT_FDIR_LEVEL_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method fdir_srv::get_agent_fdir_level (ID = 0x00000002)

// @START@ Request handler for method fdir_srv::get_detection_for_fault (ID = 0x00000003)
static void fdir_srv_get_detection_for_faultRequestHandlerImpl(ReqContext_t *pReqCtx,
            const fdir_srvget_detection_for_faultRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FDIR_SRV_return_status_t eStatus;
    bool bDetection_enabled;

    // @USER_VAR_SECTION_START@fdir_srv::get_detection_for_fault@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@fdir_srv::get_detection_for_fault@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@fdir_srv::get_detection_for_fault@

        bDetection_enabled = false;
        if (FDIR_FAULT_COUNT > pRequestData->u16Fault_id)
        {
            bDetection_enabled = fdir_srv_fault_is_detection_enabled(pRequestData->u16Fault_id);
            eStatus = FDIR_SRV_RETURN_STATUS_SUCCESS;
        }
        else
        {
            eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INVALID_FAULT_ID;
        }

        // @USER_CODE_SECTION_END@fdir_srv::get_detection_for_fault@

        respResult = fdir_srv_get_detection_for_faultResp(
                        &respCtx,
                        eStatus,
                        bDetection_enabled
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV, FDIR_SRV_GET_DETECTION_FOR_FAULT_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method fdir_srv::get_detection_for_fault (ID = 0x00000003)

// @START@ Request handler for method fdir_srv::set_detection_for_fault (ID = 0x00000004)
static void fdir_srv_set_detection_for_faultRequestHandlerImpl(ReqContext_t *pReqCtx,
            const fdir_srvset_detection_for_faultRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FDIR_SRV_return_status_t eStatus;
    bool bDetection_enabled;

    // @USER_VAR_SECTION_START@fdir_srv::set_detection_for_fault@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@fdir_srv::set_detection_for_fault@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@fdir_srv::set_detection_for_fault@

        bDetection_enabled = false;
        if (FDIR_FAULT_COUNT > pRequestData->u16Fault_id)
        {
            if (true == fdir_srv_fault_enable_detection(pRequestData->u16Fault_id, pRequestData->bSet_detection_enabled))
            {
                bDetection_enabled = fdir_srv_fault_is_detection_enabled(pRequestData->u16Fault_id);
                eStatus = FDIR_SRV_RETURN_STATUS_SUCCESS;
            }
            else
            {
                eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INTERNAL;
            }
        }
        else
        {
            eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INVALID_FAULT_ID;
        }

        // @USER_CODE_SECTION_END@fdir_srv::set_detection_for_fault@

        respResult = fdir_srv_set_detection_for_faultResp(
                        &respCtx,
                        eStatus,
                        bDetection_enabled
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV, FDIR_SRV_SET_DETECTION_FOR_FAULT_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method fdir_srv::set_detection_for_fault (ID = 0x00000004)

// @START@ Request handler for method fdir_srv::set_detection_for_all_faults (ID = 0x00000014)
static void fdir_srv_set_detection_for_all_faultsRequestHandlerImpl(ReqContext_t *pReqCtx,
            const fdir_srvset_detection_for_all_faultsRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FDIR_SRV_return_status_t eStatus;
    uint16_t u16Fault_id;

    // @USER_VAR_SECTION_START@fdir_srv::set_detection_for_all_faults@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@fdir_srv::set_detection_for_all_faults@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@fdir_srv::set_detection_for_all_faults@

        eStatus = FDIR_SRV_RETURN_STATUS_SUCCESS;
        u16Fault_id = FDIR_FAULT_INVALID;
        for (fdir_fault_id_t fault_id = 0 ; fault_id < FDIR_FAULT_COUNT ; fault_id++)
        {
            u16Fault_id = fault_id;
            if (false == fdir_srv_fault_enable_detection(fault_id, pRequestData->bSet_detection_enabled))
            {
                eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INTERNAL;
                break;
            }
        }

        // @USER_CODE_SECTION_END@fdir_srv::set_detection_for_all_faults@

        respResult = fdir_srv_set_detection_for_all_faultsResp(
                        &respCtx,
                        eStatus,
                        u16Fault_id
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV, FDIR_SRV_SET_DETECTION_FOR_ALL_FAULTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method fdir_srv::set_detection_for_all_faults (ID = 0x00000014)

// @START@ Request handler for method fdir_srv::get_min_active_fdir (ID = 0x00000015)
static void fdir_srv_get_min_active_fdirRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FDIR_SRV_return_status_t eStatus;
    uint8_t u8Fdir_level_set;

    // @USER_VAR_SECTION_START@fdir_srv::get_min_active_fdir@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@fdir_srv::get_min_active_fdir@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@fdir_srv::get_min_active_fdir@

        u8Fdir_level_set = fdir_srv_system_get_fdir_level_min();
        eStatus = FDIR_SRV_RETURN_STATUS_SUCCESS;

        // @USER_CODE_SECTION_END@fdir_srv::get_min_active_fdir@

        respResult = fdir_srv_get_min_active_fdirResp(
                        &respCtx,
                        eStatus,
                        u8Fdir_level_set
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV, FDIR_SRV_GET_MIN_ACTIVE_FDIR_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method fdir_srv::get_min_active_fdir (ID = 0x00000015)

// @START@ Request handler for method fdir_srv::set_min_active_fdir (ID = 0x00000005)
static void fdir_srv_set_min_active_fdirRequestHandlerImpl(ReqContext_t *pReqCtx,
            const fdir_srvset_min_active_fdirRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FDIR_SRV_return_status_t eStatus;
    uint8_t u8Fdir_level_set;

    // @USER_VAR_SECTION_START@fdir_srv::set_min_active_fdir@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@fdir_srv::set_min_active_fdir@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@fdir_srv::set_min_active_fdir@

        u8Fdir_level_set = FDIR_LEVEL_INVALID;
        if (FDIR_LEVEL_MAX >= pRequestData->u8Fdir_level)
        {
            if (true == fdir_srv_system_set_fdir_level_min(pRequestData->u8Fdir_level))
            {
                eStatus = FDIR_SRV_RETURN_STATUS_SUCCESS;
                u8Fdir_level_set = fdir_srv_system_get_fdir_level_min();
                if (FDIR_LEVEL_MAX < u8Fdir_level_set)
                {
                    eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INTERNAL;
                }
            }
            else
            {
                eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INTERNAL;
            }
        }
        else
        {
            eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INVALID_FDIR_LEVEL;
        }

        // @USER_CODE_SECTION_END@fdir_srv::set_min_active_fdir@

        respResult = fdir_srv_set_min_active_fdirResp(
                        &respCtx,
                        eStatus,
                        u8Fdir_level_set
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV, FDIR_SRV_SET_MIN_ACTIVE_FDIR_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method fdir_srv::set_min_active_fdir (ID = 0x00000005)

// @START@ Request handler for method fdir_srv::get_fault_user_clear_level (ID = 0x00000007)
static void fdir_srv_get_fault_user_clear_levelRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FDIR_SRV_return_status_t eStatus;
    uint8_t u8Fdir_level;

    // @USER_VAR_SECTION_START@fdir_srv::get_fault_user_clear_level@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@fdir_srv::get_fault_user_clear_level@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@fdir_srv::get_fault_user_clear_level@

        u8Fdir_level = fdir_srv_system_get_user_clear_level();
        if (FDIR_LEVEL_COUNT >= u8Fdir_level)
        {
            eStatus = FDIR_SRV_RETURN_STATUS_SUCCESS;
        }
        else
        {
            eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INTERNAL;
        }

        // @USER_CODE_SECTION_END@fdir_srv::get_fault_user_clear_level@

        respResult = fdir_srv_get_fault_user_clear_levelResp(
                        &respCtx,
                        eStatus,
                        u8Fdir_level
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV, FDIR_SRV_GET_FAULT_USER_CLEAR_LEVEL_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method fdir_srv::get_fault_user_clear_level (ID = 0x00000007)

// @START@ Request handler for method fdir_srv::set_fault_user_clear_level (ID = 0x00000006)
static void fdir_srv_set_fault_user_clear_levelRequestHandlerImpl(ReqContext_t *pReqCtx,
            const fdir_srvset_fault_user_clear_levelRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FDIR_SRV_return_status_t eStatus;
    uint8_t u8Fdir_level_set;

    // @USER_VAR_SECTION_START@fdir_srv::set_fault_user_clear_level@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@fdir_srv::set_fault_user_clear_level@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@fdir_srv::set_fault_user_clear_level@

        // user clear level may be above the max level
        if (FDIR_LEVEL_COUNT >= pRequestData->u8Fdir_level)
        {
            if (true == fdir_srv_system_set_user_clear_level(pRequestData->u8Fdir_level))
            {
                eStatus = FDIR_SRV_RETURN_STATUS_SUCCESS;
            }
            else
            {
                eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INTERNAL;
            }
        }
        else
        {
            eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INVALID_FDIR_LEVEL;
        }
        u8Fdir_level_set = fdir_srv_system_get_user_clear_level();
        if (FDIR_LEVEL_COUNT < u8Fdir_level_set)
        {
            eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INTERNAL;
        }

        // @USER_CODE_SECTION_END@fdir_srv::set_fault_user_clear_level@

        respResult = fdir_srv_set_fault_user_clear_levelResp(
                        &respCtx,
                        eStatus,
                        u8Fdir_level_set
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV, FDIR_SRV_SET_FAULT_USER_CLEAR_LEVEL_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method fdir_srv::set_fault_user_clear_level (ID = 0x00000006)

// @START@ Request handler for method fdir_srv::get_fault (ID = 0x00000008)
static void fdir_srv_get_faultRequestHandlerImpl(ReqContext_t *pReqCtx,
            const fdir_srvget_faultRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FDIR_SRV_return_status_t eStatus;
    bool bIs_active;
    uint8_t u8Fdir_level;

    // @USER_VAR_SECTION_START@fdir_srv::get_fault@
    // Put your local variables in this section to preserve during merge!
    fdir_fault_dyn_t fault;
    // @USER_VAR_SECTION_END@fdir_srv::get_fault@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@fdir_srv::get_fault@

        eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INTERNAL;
        bIs_active = false;
        u8Fdir_level = FDIR_LEVEL_INVALID;
        if (FDIR_FAULT_COUNT > pRequestData->u16Fault_id)
        {

            fault = fdir_srv_fault_get_state(pRequestData->u16Fault_id);
            bIs_active = fault.fault_active;
            if (bIs_active)
            {
                u8Fdir_level = fault.fdir_level_dyn;
            }
            else
            {
                u8Fdir_level = g_fdir_action[pRequestData->u16Fault_id].fdir_level;
            }
            if (FDIR_LEVEL_MAX >= u8Fdir_level)
            {
                eStatus = FDIR_SRV_RETURN_STATUS_SUCCESS;
            }
            else
            {
                eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INTERNAL;
            }
        }
        else
        {
            eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INVALID_FAULT_ID;
        }

        // @USER_CODE_SECTION_END@fdir_srv::get_fault@

        respResult = fdir_srv_get_faultResp(
                        &respCtx,
                        eStatus,
                        bIs_active,
                        u8Fdir_level
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV, FDIR_SRV_GET_FAULT_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method fdir_srv::get_fault (ID = 0x00000008)

// @START@ Request handler for method fdir_srv::set_fault (ID = 0x00000009)
static void fdir_srv_set_faultRequestHandlerImpl(ReqContext_t *pReqCtx,
            const fdir_srvset_faultRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FDIR_SRV_return_status_t eStatus;

    // @USER_VAR_SECTION_START@fdir_srv::set_fault@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@fdir_srv::set_fault@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@fdir_srv::set_fault@

        if (FDIR_FAULT_COUNT <= pRequestData->u16Fault_id)
        {
            eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INVALID_FAULT_ID;
        }
        else if (FDIR_AGENT_COUNT <= pRequestData->u16Agent_id)
        {
            eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INVALID_AGENT_ID;
        }
        else if ((true == pRequestData->bActive) &&
            (false == fdir_srv_fault_is_detection_enabled(pRequestData->u16Fault_id)))
        {
            eStatus = FDIR_SRV_RETURN_STATUS_ERROR_FAULT_DETECTION_DISABLED;
        }
        else if ((false == pRequestData->bActive) &&
            (fdir_srv_fault_get_state(pRequestData->u16Fault_id).fdir_level_dyn >= fdir_srv_system_get_user_clear_level()))
        {
            eStatus = FDIR_SRV_RETURN_STATUS_ERROR_FAULT_LEVEL_ABOVE_AUTOCLEAR;
        }
        else if (false == fdir_srv_fault_set_state(pRequestData->u16Fault_id, pRequestData->u16Agent_id, pRequestData->bActive, NULL))
        {
            eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INTERNAL;
        }
        else
        {
            eStatus = FDIR_SRV_RETURN_STATUS_SUCCESS;
        }

        // @USER_CODE_SECTION_END@fdir_srv::set_fault@

        respResult = fdir_srv_set_faultResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV, FDIR_SRV_SET_FAULT_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method fdir_srv::set_fault (ID = 0x00000009)

// @START@ Request handler for method fdir_srv::force_clear_fault (ID = 0x0000000A)
static void fdir_srv_force_clear_faultRequestHandlerImpl(ReqContext_t *pReqCtx,
            const fdir_srvforce_clear_faultRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FDIR_SRV_return_status_t eStatus;

    // @USER_VAR_SECTION_START@fdir_srv::force_clear_fault@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@fdir_srv::force_clear_fault@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@fdir_srv::force_clear_fault@

        if (FDIR_FAULT_COUNT > pRequestData->u16Fault_id)
        {
            if (true == fdir_srv_fault_set_state_force(pRequestData->u16Fault_id, FDIR_AGENT_OPERATOR, false, NULL))
            {
                eStatus = FDIR_SRV_RETURN_STATUS_SUCCESS;
            }
            else
            {
                eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INTERNAL;
            }
        }
        else
        {
            eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INVALID_FAULT_ID;
        }

        // @USER_CODE_SECTION_END@fdir_srv::force_clear_fault@

        respResult = fdir_srv_force_clear_faultResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV, FDIR_SRV_FORCE_CLEAR_FAULT_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method fdir_srv::force_clear_fault (ID = 0x0000000A)

// @START@ Request handler for method fdir_srv::force_clear_all_faults (ID = 0x0000000B)
static void fdir_srv_force_clear_all_faultsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FDIR_SRV_return_status_t eStatus;
    uint16_t u16Fault_id;

    // @USER_VAR_SECTION_START@fdir_srv::force_clear_all_faults@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@fdir_srv::force_clear_all_faults@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@fdir_srv::force_clear_all_faults@

        eStatus = FDIR_SRV_RETURN_STATUS_SUCCESS;
        for (fdir_fault_id_t fault_id = 0 ; fault_id < FDIR_FAULT_COUNT ; fault_id++)
        {
            u16Fault_id = fault_id;
            if (false == fdir_srv_fault_set_state_force(fault_id, FDIR_AGENT_OPERATOR, false, NULL))
            {
                eStatus = FDIR_SRV_RETURN_STATUS_ERROR_INTERNAL;
                break;
            }
        }

        // @USER_CODE_SECTION_END@fdir_srv::force_clear_all_faults@

        respResult = fdir_srv_force_clear_all_faultsResp(
                        &respCtx,
                        eStatus,
                        u16Fault_id
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FDIR_SRV, FDIR_SRV_FORCE_CLEAR_ALL_FAULTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method fdir_srv::force_clear_all_faults (ID = 0x0000000B)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void fdir_srvServerAppInit(void)
{
    fdir_srv_registerServerApi(&fdir_srvServerApiCtx);
}
