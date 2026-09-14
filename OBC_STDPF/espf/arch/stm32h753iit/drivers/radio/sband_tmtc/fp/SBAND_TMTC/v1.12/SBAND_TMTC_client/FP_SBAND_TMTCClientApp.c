/*!
********************************************************************************************
* @file FP_SBAND_TMTCClientApp.c
* @brief ClientApp implementation template generator
********************************************************************************************
* @version           interface SBAND_TMTC v1.12
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

#include "FP_SBAND_TMTCProtocolClient.h"

// @START_USER@ USER_INCLUDES
// Place user includes here to preserve them during merge!!!
#include "sband_tmtc.h"
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

static void SBAND_TMTC_ReadUpTimeResponseHandlerImpl(RespContext_t* pRespCtx,
            const SBAND_TMTCReadUpTimeResponseData_t* pResponseData);

static void SBAND_TMTC_ReadErrorCountersResponseHandlerImpl(RespContext_t* pRespCtx,
            const SBAND_TMTCReadErrorCountersResponseData_t* pResponseData);

static void SBAND_TMTC_GetPacketCountersResponseHandlerImpl(RespContext_t* pRespCtx,
            const SBAND_TMTCGetPacketCountersResponseData_t* pResponseData);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)
// @END_USER@ USER_LOCAL_VARS_DECL

static SBAND_TMTC_ClientApi_t SBAND_TMTCClientApiCtx =
{
  .SBAND_TMTC_ReadUpTimeResponseHandler = (pfSBAND_TMTC_ReadUpTimeResponseHandler_t) SBAND_TMTC_ReadUpTimeResponseHandlerImpl,
  .SBAND_TMTC_ReadErrorCountersResponseHandler = (pfSBAND_TMTC_ReadErrorCountersResponseHandler_t) SBAND_TMTC_ReadErrorCountersResponseHandlerImpl,
  .SBAND_TMTC_GetPacketCountersResponseHandler = (pfSBAND_TMTC_GetPacketCountersResponseHandler_t) SBAND_TMTC_GetPacketCountersResponseHandlerImpl,
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Response handler for method SBAND_TMTC::ReadUpTime (ID = 0x00000002)
static void SBAND_TMTC_ReadUpTimeResponseHandlerImpl(RespContext_t* pRespCtx,
            const SBAND_TMTCReadUpTimeResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@SBAND_TMTC::ReadUpTime@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@SBAND_TMTC::ReadUpTime@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@SBAND_TMTC::ReadUpTime@
        
    	sband_tmtc_uptime_response_handler(pRespCtx, pResponseData);

        // @USER_CODE_SECTION_END@SBAND_TMTC::ReadUpTime@
    }
}
// @END@ Response handler for method SBAND_TMTC::ReadUpTime (ID = 0x00000002)

// @START@ Response handler for method SBAND_TMTC::ReadErrorCounters (ID = 0x00000008)
static void SBAND_TMTC_ReadErrorCountersResponseHandlerImpl(RespContext_t* pRespCtx,
            const SBAND_TMTCReadErrorCountersResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@SBAND_TMTC::ReadErrorCounters@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@SBAND_TMTC::ReadErrorCounters@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@SBAND_TMTC::ReadErrorCounters@
        
        // TODO: Put your implementation to handle the
        // received server response here!
        
       	///// To get GS_handshake register read Error Counter Response.
    	comm_loss_wd_check_sband_error_counters(pResponseData);

        // @USER_CODE_SECTION_END@SBAND_TMTC::ReadErrorCounters@
    }
}
// @END@ Response handler for method SBAND_TMTC::ReadErrorCounters (ID = 0x00000008)

// @START@ Response handler for method SBAND_TMTC::GetPacketCounters (ID = 0x0000002C)
static void SBAND_TMTC_GetPacketCountersResponseHandlerImpl(RespContext_t* pRespCtx,
            const SBAND_TMTCGetPacketCountersResponseData_t* pResponseData)
{
    // @USER_VAR_SECTION_START@SBAND_TMTC::GetPacketCounters@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@SBAND_TMTC::GetPacketCounters@

    if ((pRespCtx != NULL) && (pResponseData != NULL))
    {
        // @USER_CODE_SECTION_START@SBAND_TMTC::GetPacketCounters@
        
        // TODO: Put your implementation to handle the
        // received server response here!

    	comm_loss_wd_check_sband_packet_counters(pResponseData);

        // @USER_CODE_SECTION_END@SBAND_TMTC::GetPacketCounters@
    }
}
// @END@ Response handler for method SBAND_TMTC::GetPacketCounters (ID = 0x0000002C)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void SBAND_TMTCClientAppInit(void)
{
    SBAND_TMTC_registerClientApi(&SBAND_TMTCClientApiCtx);
}
