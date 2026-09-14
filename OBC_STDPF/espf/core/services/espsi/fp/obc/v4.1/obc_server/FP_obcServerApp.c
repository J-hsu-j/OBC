/*!
********************************************************************************************
* @file FP_obcServerApp.c
* @brief ServerApp implementation template generator
********************************************************************************************
* @version           interface obc v4.1
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

#include "FP_obcProtocolServer.h"

// @START_USER@ USER_INCLUDES
// Place user includes here to preserve them during merge!!!
#include "CommandsApi.h"
#include "module_id.h"
#include "debug.h"
#include "FWUPD_Persistor.h"
#include "AppTasks.h"
#include "nvm_rc.h"
#include "nvm.h"

// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL
static void obc_get_all_gpo_valuesRequestHandlerImpl(ReqContext_t* pReqCtx);

static void obc_set_all_gpo_valuesRequestHandlerImpl(ReqContext_t* pReqCtx,
            const obcset_all_gpo_valuesRequestData_t* pRequestData);

static void obc_get_i2c_pull_ups_stateRequestHandlerImpl(ReqContext_t* pReqCtx);

static void obc_set_i2c_pull_ups_stateRequestHandlerImpl(ReqContext_t* pReqCtx,
            const obcset_i2c_pull_ups_stateRequestData_t* pRequestData);

static void obc_get_uptimeRequestHandlerImpl(ReqContext_t* pReqCtx);

static void obc_get_reset_countersRequestHandlerImpl(ReqContext_t* pReqCtx);

static void obc_clear_reset_counterRequestHandlerImpl(ReqContext_t* pReqCtx,
            const obcclear_reset_counterRequestData_t* pRequestData);

static void obc_trigger_reset_in_modeRequestHandlerImpl(ReqContext_t* pReqCtx,
            const obctrigger_reset_in_modeRequestData_t* pRequestData);

static void obc_set_device_mac_addressRequestHandlerImpl(ReqContext_t* pReqCtx,
            const obcset_device_mac_addressRequestData_t* pRequestData);

static void obc_get_device_mac_addressRequestHandlerImpl(ReqContext_t* pReqCtx,
            const obcget_device_mac_addressRequestData_t* pRequestData);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)
static inline OBC_StandardResult_t getStdResFor(StdResult_t res)
{
    OBC_StandardResult_t stdRes;

    switch (res)
    {
        case STDRESULT_SUCCESS :
            stdRes = OBC_STANDARDRESULT_SUCCESS;
        break;

        case STDRESULT_ERROR :
            stdRes = OBC_STANDARDRESULT_ERROR;
        break;

        case STDRESULT_INVALID_ARGS :
            stdRes = OBC_STANDARDRESULT_INVALID_ARGS;
        break;

        default:
            stdRes = OBC_STANDARDRESULT_ERROR;
        break;
    }

    return stdRes;
}
// @END_USER@ USER_LOCAL_VARS_DECL

static obc_ServerApi_t obcServerApiCtx =
{
  .obc_get_all_gpo_valuesRequestHandler = obc_get_all_gpo_valuesRequestHandlerImpl,
  .obc_set_all_gpo_valuesRequestHandler = obc_set_all_gpo_valuesRequestHandlerImpl,
  .obc_get_i2c_pull_ups_stateRequestHandler = obc_get_i2c_pull_ups_stateRequestHandlerImpl,
  .obc_set_i2c_pull_ups_stateRequestHandler = obc_set_i2c_pull_ups_stateRequestHandlerImpl,
  .obc_get_uptimeRequestHandler = obc_get_uptimeRequestHandlerImpl,
  .obc_get_reset_countersRequestHandler = obc_get_reset_countersRequestHandlerImpl,
  .obc_clear_reset_counterRequestHandler = obc_clear_reset_counterRequestHandlerImpl,
  .obc_trigger_reset_in_modeRequestHandler = obc_trigger_reset_in_modeRequestHandlerImpl,
  .obc_set_device_mac_addressRequestHandler = obc_set_device_mac_addressRequestHandlerImpl,
  .obc_get_device_mac_addressRequestHandler = obc_get_device_mac_addressRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method obc::get_all_gpo_values (ID = 0x0000000E)
static void obc_get_all_gpo_valuesRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    OBC_GpoPortsGetStruct_t sGpo;
    OBC_StandardResult_t eResult;

    // @USER_VAR_SECTION_START@obc::get_all_gpo_values@
    // Put your local variables in this section to preserve during merge!
    bool op_result = false;
    // @USER_VAR_SECTION_END@obc::get_all_gpo_values@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@obc::get_all_gpo_values@
        op_result = get_all_gpo_values((OBC_GpoPortsGetStruct_t *)&sGpo);
        if (op_result == true)
        {
            eResult = OBC_STANDARDRESULT_SUCCESS;
        }
        else
        {
            eResult = OBC_STANDARDRESULT_INVALID_ARGS;
        }
        // @USER_CODE_SECTION_END@obc::get_all_gpo_values@

        respResult = obc_get_all_gpo_valuesResp(
                        &respCtx,
                        &sGpo,
                        eResult
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_OBC, OBC_GET_ALL_GPO_VALUES_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method obc::get_all_gpo_values (ID = 0x0000000E)

// @START@ Request handler for method obc::set_all_gpo_values (ID = 0x0000000F)
static void obc_set_all_gpo_valuesRequestHandlerImpl(ReqContext_t *pReqCtx,
            const obcset_all_gpo_valuesRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    OBC_StandardResult_t eResult;

    // @USER_VAR_SECTION_START@obc::set_all_gpo_values@
    // Put your local variables in this section to preserve during merge!
    bool op_result = false;
    // @USER_VAR_SECTION_END@obc::set_all_gpo_values@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@obc::set_all_gpo_values@
        op_result = set_all_gpo_values(pRequestData->sGpo);
        if (op_result == true)
        {
            eResult = OBC_STANDARDRESULT_SUCCESS;
        }
        else
        {
            eResult = OBC_STANDARDRESULT_INVALID_ARGS;
        }
        // @USER_CODE_SECTION_END@obc::set_all_gpo_values@

        respResult = obc_set_all_gpo_valuesResp(
                        &respCtx,
                        eResult
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_OBC, OBC_SET_ALL_GPO_VALUES_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method obc::set_all_gpo_values (ID = 0x0000000F)

// @START@ Request handler for method obc::get_i2c_pull_ups_state (ID = 0x00000012)
static void obc_get_i2c_pull_ups_stateRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    OBC_I2CPullUpsState_t sNvm_pull_ups_state;
    OBC_I2CPullUpsState_t sIo_pull_ups_state;

    // @USER_VAR_SECTION_START@obc::get_i2c_pull_ups_state@
    // Put your local variables in this section to preserve during merge!
    i2c_config_t i2c_config;
    // @USER_VAR_SECTION_END@obc::get_i2c_pull_ups_state@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@obc::get_i2c_pull_ups_state@

        Nvm_GetBlockById(NVM_BLOCK_I2C_CONFIG, &i2c_config);

        sNvm_pull_ups_state.bSystem_bus_4K7 = (i2c_config.i2c_pull_up_config[I2C_BUS_SYSTEM].pull_up_4k7);
        sNvm_pull_ups_state.bSystem_bus_10K = (i2c_config.i2c_pull_up_config[I2C_BUS_SYSTEM].pull_up_10k);
        sNvm_pull_ups_state.bPayload_bus_4K7 = (i2c_config.i2c_pull_up_config[I2C_BUS_PAYLOAD].pull_up_4k7);
        sNvm_pull_ups_state.bPayload_bus_10K = (i2c_config.i2c_pull_up_config[I2C_BUS_PAYLOAD].pull_up_10k);

        I2CPullUpsState_t i2c_io_cfg = MCU_Init_I2cPullUps_Get();

        sIo_pull_ups_state.bSystem_bus_4K7 = i2c_io_cfg.pins.sys_bus_4K7;
        sIo_pull_ups_state.bSystem_bus_10K = i2c_io_cfg.pins.sys_bus_10K;
        sIo_pull_ups_state.bPayload_bus_4K7 = i2c_io_cfg.pins.pay_bus_4K7;
        sIo_pull_ups_state.bPayload_bus_10K = i2c_io_cfg.pins.pay_bus_10K;

        // @USER_CODE_SECTION_END@obc::get_i2c_pull_ups_state@

        respResult = obc_get_i2c_pull_ups_stateResp(
                        &respCtx,
                        &sNvm_pull_ups_state,
                        &sIo_pull_ups_state
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_OBC, OBC_GET_I2C_PULL_UPS_STATE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method obc::get_i2c_pull_ups_state (ID = 0x00000012)

// @START@ Request handler for method obc::set_i2c_pull_ups_state (ID = 0x00000013)
static void obc_set_i2c_pull_ups_stateRequestHandlerImpl(ReqContext_t *pReqCtx,
            const obcset_i2c_pull_ups_stateRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    OBC_I2CPullUpsState_t sPull_ups_io_state;

    // @USER_VAR_SECTION_START@obc::set_i2c_pull_ups_state@
    // Put your local variables in this section to preserve during merge!
    i2c_config_t i2c_config;
    // @USER_VAR_SECTION_END@obc::set_i2c_pull_ups_state@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@obc::set_i2c_pull_ups_state@

        (void) memset(&i2c_config, 0U, sizeof(i2c_config));

        i2c_config.i2c_pull_up_config[I2C_BUS_SYSTEM].pull_up_4k7 = pRequestData->sPull_up_state.bSystem_bus_4K7;
        i2c_config.i2c_pull_up_config[I2C_BUS_SYSTEM].pull_up_10k = pRequestData->sPull_up_state.bSystem_bus_10K;
        i2c_config.i2c_pull_up_config[I2C_BUS_PAYLOAD].pull_up_4k7 = pRequestData->sPull_up_state.bPayload_bus_4K7;
        i2c_config.i2c_pull_up_config[I2C_BUS_PAYLOAD].pull_up_10k = pRequestData->sPull_up_state.bPayload_bus_10K;

        Nvm_SetBlockById(NVM_BLOCK_I2C_CONFIG, &i2c_config, NVMSETBLOCK_STORE_IMMEDIATELY);

        // apply the new NVM settings to the GPIOs...
        MCU_Init_I2cPullUps_Nvm();

        // read back GPIO status directly...
        I2CPullUpsState_t i2c_io_state;
        i2c_io_state = MCU_Init_I2cPullUps_Get();

        sPull_ups_io_state.bSystem_bus_4K7 = i2c_io_state.pins.sys_bus_4K7;
        sPull_ups_io_state.bSystem_bus_10K = i2c_io_state.pins.sys_bus_10K;
        sPull_ups_io_state.bPayload_bus_4K7 = i2c_io_state.pins.pay_bus_4K7;
        sPull_ups_io_state.bPayload_bus_10K = i2c_io_state.pins.pay_bus_10K;


        // @USER_CODE_SECTION_END@obc::set_i2c_pull_ups_state@

        respResult = obc_set_i2c_pull_ups_stateResp(
                        &respCtx,
                        &sPull_ups_io_state
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_OBC, OBC_SET_I2C_PULL_UPS_STATE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method obc::set_i2c_pull_ups_state (ID = 0x00000013)

// @START@ Request handler for method obc::get_uptime (ID = 0x00000018)
static void obc_get_uptimeRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    uint32_t u32Uptime;

    // @USER_VAR_SECTION_START@obc::get_uptime@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@obc::get_uptime@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@obc::get_uptime@
        // TODO: Put your implementation to handle the
        // received server response here!
        u32Uptime = get_uptime_seconds();
        // @USER_CODE_SECTION_END@obc::get_uptime@

        respResult = obc_get_uptimeResp(
                        &respCtx,
                        u32Uptime
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_OBC, OBC_GET_UPTIME_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method obc::get_uptime (ID = 0x00000018)

// @START@ Request handler for method obc::get_reset_counters (ID = 0x0000002A)
static void obc_get_reset_countersRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    OBC_ResetCountersInfo_t sStatus;

    // @USER_VAR_SECTION_START@obc::get_reset_counters@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@obc::get_reset_counters@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@obc::get_reset_counters@
        boot_struct boot_data;
        Nvm_GetBlockById(NVM_BLOCK_BOOTDATA, &boot_data);

        sStatus.u32Wwd = boot_data.RST_WWD;
        sStatus.u32Iwd = boot_data.RST_IWD;
        sStatus.u32Lpr = boot_data.RST_LPR;
        sStatus.u32Por = boot_data.RST_POR;
        sStatus.u32Rst_pin = boot_data.RST_RstPin;
        sStatus.u32Bor = boot_data.RST_BOR;
        sStatus.u32Hard_fault = boot_data.RST_HardFault;
        sStatus.u32Mem_fault = boot_data.RST_MemFault;
        sStatus.u32Bus_fault = boot_data.RST_BusFault;
        sStatus.u32Usage_fault = boot_data.RST_UsageFault;

        // @USER_CODE_SECTION_END@obc::get_reset_counters@

        respResult = obc_get_reset_countersResp(
                        &respCtx,
                        &sStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_OBC, OBC_GET_RESET_COUNTERS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method obc::get_reset_counters (ID = 0x0000002A)

// @START@ Request handler for method obc::clear_reset_counter (ID = 0x0000002B)
static void obc_clear_reset_counterRequestHandlerImpl(ReqContext_t *pReqCtx,
            const obcclear_reset_counterRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    OBC_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@obc::clear_reset_counter@
    // Put your local variables in this section to preserve during merge!
    nvm_rc_cntr_id_t rst_cntr_id;
    // @USER_VAR_SECTION_END@obc::clear_reset_counter@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@obc::clear_reset_counter@
        switch (pRequestData->eId)
        {
            case OBC_RESETCNTRID_WWD:
                rst_cntr_id = RSTCOUNTERID_WWD;
            break;

            case OBC_RESETCNTRID_IWD:
                rst_cntr_id = RSTCOUNTERID_IWD;
            break;

            case OBC_RESETCNTRID_LPR:
                rst_cntr_id = RSTCOUNTERID_LPR;
            break;

            case OBC_RESETCNTRID_POR:
                rst_cntr_id = RSTCOUNTERID_POR;
            break;

            case OBC_RESETCNTRID_RST_PIN:
                rst_cntr_id = RSTCOUNTERID_RSTPIN;
            break;

            case OBC_RESETCNTRID_BOR:
                rst_cntr_id = RSTCOUNTERID_BOR;
            break;

            case OBC_RESETCNTRID_HARD_FAULT:
                rst_cntr_id = RSTCOUNTERID_HARDFAULT;
            break;

            case OBC_RESETCNTRID_MEM_FAULT:
                rst_cntr_id = RSTCOUNTERID_MEMFAULT;
            break;

            case OBC_RESETCNTRID_BUS_FAULT:
                rst_cntr_id = RSTCOUNTERID_BUSFAULT;
            break;

            case OBC_RESETCNTRID_USAGE_FAULT:
                rst_cntr_id = RSTCOUNTERID_USAGEFAULT;
            break;

            case OBC_RESETCNTRID_ALL:
                rst_cntr_id = RSTCOUNTERID_ALL;
            break;

            default:
                rst_cntr_id = RSTCOUNTERID_MAX;
            break;
        }

        eOp_result = (nvm_rc_clear(rst_cntr_id)) ?
                    (OBC_STANDARDRESULT_SUCCESS) :
                    (OBC_STANDARDRESULT_INVALID_ARGS);

        // @USER_CODE_SECTION_END@obc::clear_reset_counter@

        respResult = obc_clear_reset_counterResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_OBC, OBC_CLEAR_RESET_COUNTER_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method obc::clear_reset_counter (ID = 0x0000002B)

// @START@ Request handler for method obc::trigger_reset_in_mode (ID = 0x00000036)
static void obc_trigger_reset_in_modeRequestHandlerImpl(ReqContext_t *pReqCtx,
            const obctrigger_reset_in_modeRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    OBC_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@obc::trigger_reset_in_mode@
    // Put your local variables in this section to preserve during merge!
    AppMode_t new_app_mode;
    StdResult_t res;
    // @USER_VAR_SECTION_END@obc::trigger_reset_in_mode@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@obc::trigger_reset_in_mode@
        switch (pRequestData->eStart_mode)
        {
            case OBC_APPLICATIONMODE_APPLICATION:
                new_app_mode = APPMODE_APPLICATION;
            break;

            case OBC_APPLICATIONMODE_BOOTLOADER:
                new_app_mode = APPMODE_BOOTLOADER;
            break;

            default:
                new_app_mode = APPMODE_MAX;
            break;
        }

        res = WriteHandler_ResetInBootOrAppMode(new_app_mode);

        eOp_result = getStdResFor(res);

        // @USER_CODE_SECTION_END@obc::trigger_reset_in_mode@

        respResult = obc_trigger_reset_in_modeResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_OBC, OBC_TRIGGER_RESET_IN_MODE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method obc::trigger_reset_in_mode (ID = 0x00000036)

// @START@ Request handler for method obc::set_device_mac_address (ID = 0x00000040)
static void obc_set_device_mac_addressRequestHandlerImpl(ReqContext_t *pReqCtx,
            const obcset_device_mac_addressRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    OBC_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@obc::set_device_mac_address@
    // Put your local variables in this section to preserve during merge!
    mac_address_book_t addresses = {0};
    // @USER_VAR_SECTION_END@obc::set_device_mac_address@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@obc::set_device_mac_address@
        if (MAC_ADDR_BOOK_MAX <= pRequestData->u8Device_id){
            eOp_result = OBC_STANDARDRESULT_INVALID_ARGS;
        }
        // Check for invalid MAC ADDRESSES
        else if(0x00 == pRequestData->u8New_mac_address
             || ESSATMAC_ADDR_BROADCAST == pRequestData->u8New_mac_address
             || ESSATMAC_ADDR_GATEWAY_DEV == pRequestData->u8New_mac_address
             || ESSATMAC_ADDR_UNINITIALIZED_DEV == pRequestData->u8New_mac_address
             || ESSATMAC_ADDR_GATEWAY_EPSIIBP == pRequestData->u8New_mac_address
             || ESSATMAC_ADDR_GATEWAY_EPSIIPDM == pRequestData->u8New_mac_address
             || ESSATMAC_ADDR_EXTERNAL_MAC_DONGLE == pRequestData->u8New_mac_address)
        {
            eOp_result = OBC_STANDARDRESULT_INVALID_ARGS;
        }
        else {
            eOp_result = OBC_STANDARDRESULT_ERROR;
            // Read the NVM
            Nvm_GetBlockById(NVM_MAC_ADDRESS_BOOK, &addresses);

            // Verify if the nvm was read
            addresses.a_mac_address[pRequestData->u8Device_id] = pRequestData->u8New_mac_address;
            Nvm_SetBlockById(NVM_MAC_ADDRESS_BOOK, &addresses, true);
            eOp_result = OBC_STANDARDRESULT_SUCCESS;
        }


        // @USER_CODE_SECTION_END@obc::set_device_mac_address@

        respResult = obc_set_device_mac_addressResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_OBC, OBC_SET_DEVICE_MAC_ADDRESS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method obc::set_device_mac_address (ID = 0x00000040)

// @START@ Request handler for method obc::get_device_mac_address (ID = 0x00000041)
static void obc_get_device_mac_addressRequestHandlerImpl(ReqContext_t *pReqCtx,
            const obcget_device_mac_addressRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    uint8_t u8Mac_address;
    OBC_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@obc::get_device_mac_address@
    // Put your local variables in this section to preserve during merge!
    mac_address_book_t addresses = {0};
    // @USER_VAR_SECTION_END@obc::get_device_mac_address@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@obc::get_device_mac_address@
        // TODO: Put your implementation to handle the
        // received server response here!
        u8Mac_address = 0;

        if (MAC_ADDR_BOOK_MAX <= pRequestData->u8Device_id)
        {
            eOp_result = OBC_STANDARDRESULT_INVALID_ARGS;
        }
        else
        {
            eOp_result = OBC_STANDARDRESULT_ERROR;
            // Read the NVM
            Nvm_GetBlockById(NVM_MAC_ADDRESS_BOOK, &addresses);
            u8Mac_address = addresses.a_mac_address[pRequestData->u8Device_id];
            eOp_result = OBC_STANDARDRESULT_SUCCESS;
        }
        // @USER_CODE_SECTION_END@obc::get_device_mac_address@

        respResult = obc_get_device_mac_addressResp(
                        &respCtx,
                        u8Mac_address,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_OBC, OBC_GET_DEVICE_MAC_ADDRESS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method obc::get_device_mac_address (ID = 0x00000041)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void obcServerAppInit(void)
{
    obc_registerServerApi(&obcServerApiCtx);
}
