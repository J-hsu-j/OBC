/*!
********************************************************************************************
* @file FP_UHFClientApp.c
* @brief ClientApp implementation template generator
********************************************************************************************
* @version           interface UHF v0.5
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

#include "FP_UHFProtocolClient.h"

// @START_USER@ USER_INCLUDES
#if defined(BEACONS_ENABLED)
#include "beacons_sink_uhf.h"
#endif

#include "comm_loss_wd.h"
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL

static void UHF_ReadNumberOfRxPacketsResponseHandlerImpl(RespContext_t* pRespCtx,
            const UHFReadNumberOfRxPacketsResponseData_t* pResponseData);

static void UHF_ExBeaconSetSendResponseHandlerImpl(RespContext_t* pRespCtx,
            const UHFExBeaconSetSendResponseData_t* pResponseData);

static void UHF_ReadCountersResponseHandlerImpl(RespContext_t* pRespCtx,
            const UHFReadCountersResponseData_t* pResponseData);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)
// @END_USER@ USER_LOCAL_VARS_DECL

static UHF_ClientApi_t UHFClientApiCtx =
{
  .UHF_ReadNumberOfRxPacketsResponseHandler = (pfUHF_ReadNumberOfRxPacketsResponseHandler_t) UHF_ReadNumberOfRxPacketsResponseHandlerImpl,
  .UHF_ExBeaconSetSendResponseHandler = (pfUHF_ExBeaconSetSendResponseHandler_t) UHF_ExBeaconSetSendResponseHandlerImpl,
  .UHF_ReadCountersResponseHandler = (pfUHF_ReadCountersResponseHandler_t) UHF_ReadCountersResponseHandlerImpl,
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Response handler for method UHF::ReadNumberOfRxPackets (ID = 0x00000007)
static void UHF_ReadNumberOfRxPacketsResponseHandlerImpl(RespContext_t* pRespCtx,
            const UHFReadNumberOfRxPacketsResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@UHF::ReadNumberOfRxPackets@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@UHF::ReadNumberOfRxPackets@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@UHF::ReadNumberOfRxPackets@

        // TODO: Put your implementation to handle the
        // received server response here!

    	// Communication Loss WatchDog handler section start:

    	comm_loss_wd_check_uhf_rx_packet_count(pResponseData);

    	// Communication Loss WatchDog handler section end.

        // @USER_CODE_SECTION_END@UHF::ReadNumberOfRxPackets@
    }
}
// @END@ Response handler for method UHF::ReadNumberOfRxPackets (ID = 0x00000007)

// @START@ Response handler for method UHF::ExBeaconSetSend (ID = 0x00000029)
static void UHF_ExBeaconSetSendResponseHandlerImpl(RespContext_t* pRespCtx,
            const UHFExBeaconSetSendResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@UHF::ExBeaconSetSend@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@UHF::ExBeaconSetSend@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@UHF::ExBeaconSetSend@

#if defined(BEACONS_ENABLED)
        beacons_sink_uhf_send_status_cbk(pRespCtx, pResponseData);
#endif

        // @USER_CODE_SECTION_END@UHF::ExBeaconSetSend@
    }
}
// @END@ Response handler for method UHF::ExBeaconSetSend (ID = 0x00000029)

// @START@ Response handler for method UHF::ReadCounters (ID = 0x00000040)
static void UHF_ReadCountersResponseHandlerImpl(RespContext_t* pRespCtx,
            const UHFReadCountersResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@UHF::ReadCounters@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@UHF::ReadCounters@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@UHF::ReadCounters@

        // TODO: Put your implementation to handle the
        // received server response here!

    	// Communication Loss WatchDog handler section start:

    	comm_loss_wd_check_uhf_counter_registers(pResponseData);

    	// Communication Loss WatchDog handler section end.

        // @USER_CODE_SECTION_END@UHF::ReadCounters@
    }
}
// @END@ Response handler for method UHF::ReadCounters (ID = 0x00000040)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void UHFClientAppInit(void)
{
    UHF_registerClientApi(&UHFClientApiCtx);
}
