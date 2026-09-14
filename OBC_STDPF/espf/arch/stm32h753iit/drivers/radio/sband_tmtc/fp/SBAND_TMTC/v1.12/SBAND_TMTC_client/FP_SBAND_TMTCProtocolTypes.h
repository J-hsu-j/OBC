/*!
********************************************************************************************
* @file FP_SBAND_TMTCProtocolTypes.h
* @brief Protocol public type declarations
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

#ifndef FP_SBAND_TMTCPROTOCOLTYPES_H
#define FP_SBAND_TMTCPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_SBAND_TMTC ((uint16_t) (0x00000020))

#define SBAND_TMTC_READUPTIME_FUNC_ID ((funcIdType_t) 0x00000002)
#define SBAND_TMTC_READERRORCOUNTERS_FUNC_ID ((funcIdType_t) 0x00000008)
#define SBAND_TMTC_GETPACKETCOUNTERS_FUNC_ID ((funcIdType_t) 0x0000002C)
#define SBAND_TMTC_READUPTIME_FUNCRESP_ID ((funcIdType_t) 0x00000002)
#define SBAND_TMTC_READERRORCOUNTERS_FUNCRESP_ID ((funcIdType_t) 0x00000008)
#define SBAND_TMTC_GETPACKETCOUNTERS_FUNCRESP_ID ((funcIdType_t) 0x0000002C)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    Up-time in seconds [s]
*/
typedef struct {
    uint32_t u32U32UpTime;
} PACKED_STRUCT SBAND_TMTC_sUpTime_t;

/*
    Statistical Counters
*/
typedef struct {
    uint32_t u32POR;
    uint32_t u32MAC_Collisions;
    uint32_t u32MAC_fails;
    uint32_t u32GS_Handshakes;
    uint32_t u32NvMWriteFails;
    uint32_t u32NvMReadFails;
    uint32_t u32NvMDefaultEntry;
    uint32_t u32IntFRAM_corruptions;
    uint32_t u32ExtFRAM_corruptions;
    uint32_t u32ExtFRAM_gone;
    uint32_t u32PA1LUP;
    uint32_t u32PA2LUP;
    uint32_t u32AuthFailures;
} PACKED_STRUCT SBAND_TMTC_sErrCounters_t;

/*
    Counters for the transmitted packets, received packets and crc errors
*/
typedef struct {
    uint32_t u32TransmittedPackets;
    uint32_t u32ReceivedPackets;
    uint32_t u32CRCError;
} PACKED_STRUCT SBAND_TMTC_sRFPacketCounters_t;



typedef struct {
    SBAND_TMTC_sUpTime_t sUpTime;
} PACKED_STRUCT SBAND_TMTCReadUpTimeResponseData_t;

typedef struct {
    SBAND_TMTC_sErrCounters_t sErrCounters;
} PACKED_STRUCT SBAND_TMTCReadErrorCountersResponseData_t;

typedef struct {
    SBAND_TMTC_sRFPacketCounters_t sCounters;
} PACKED_STRUCT SBAND_TMTCGetPacketCountersResponseData_t;


#endif  // #ifndef FP_SBAND_TMTCPROTOCOLTYPES_H

