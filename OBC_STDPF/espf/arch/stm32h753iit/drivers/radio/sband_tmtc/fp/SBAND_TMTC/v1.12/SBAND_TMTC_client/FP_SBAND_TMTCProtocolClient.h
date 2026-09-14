/*!
********************************************************************************************
* @file FP_SBAND_TMTCProtocolClient.h
* @brief ESSA Stack client-side public API declaration
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

#ifndef FP_SBAND_TMTCPROTOCOLCLIENT_H
#define FP_SBAND_TMTCPROTOCOLCLIENT_H

#include "FP_SBAND_TMTCProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define SBAND_TMTC_PROTOCOL_VERSION_MAJOR   ((uint8_t) 1)
#define SBAND_TMTC_PROTOCOL_VERSION_MINOR   ((uint8_t) 12)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfSBAND_TMTC_ReadUpTimeResponseHandler_t)(RespContext_t *pRespCtx,
              const SBAND_TMTCReadUpTimeResponseData_t *pResponseData);

typedef void (*pfSBAND_TMTC_ReadErrorCountersResponseHandler_t)(RespContext_t *pRespCtx,
              const SBAND_TMTCReadErrorCountersResponseData_t *pResponseData);

typedef void (*pfSBAND_TMTC_GetPacketCountersResponseHandler_t)(RespContext_t *pRespCtx,
              const SBAND_TMTCGetPacketCountersResponseData_t *pResponseData);


typedef struct {
    pfSBAND_TMTC_ReadUpTimeResponseHandler_t SBAND_TMTC_ReadUpTimeResponseHandler;
    pfSBAND_TMTC_ReadErrorCountersResponseHandler_t SBAND_TMTC_ReadErrorCountersResponseHandler;
    pfSBAND_TMTC_GetPacketCountersResponseHandler_t SBAND_TMTC_GetPacketCountersResponseHandler;
} SBAND_TMTC_ClientApi_t;

/**********************************************************************
 *
 *  Client protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_SBAND_TMTCProtocolClientInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void SBAND_TMTC_registerClientApi(SBAND_TMTC_ClientApi_t *pCliApiHandlers);

// @deprecated - will be removed in the future - use FP_SBAND_TMTCProtocolClientInfo directly
ESSA_pStack_FunctionProtocolInfo_t SBAND_TMTC_getClientProtocolDescriptor(void);

ESSATMAC_ErrCodes SBAND_TMTC_ReadUpTimeReq(
                ReqContext_t* ctx);

ESSATMAC_ErrCodes SBAND_TMTC_ReadErrorCountersReq(
                ReqContext_t* ctx);

ESSATMAC_ErrCodes SBAND_TMTC_GetPacketCountersReq(
                ReqContext_t* ctx);


#endif  // #ifndef FP_SBAND_TMTCPROTOCOLCLIENT_H

