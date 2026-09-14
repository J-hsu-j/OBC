/*!
********************************************************************************************
* @file FP_UHFProtocolTypes.h
* @brief Protocol public type declarations
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

#ifndef FP_UHFPROTOCOLTYPES_H
#define FP_UHFPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_UHF ((uint16_t) (0x00000005))

#define UHF_READNUMBEROFRXPACKETS_FUNC_ID ((funcIdType_t) 0x00000007)
#define UHF_EXBEACONSETSEND_FUNC_ID ((funcIdType_t) 0x00000029)
#define UHF_READCOUNTERS_FUNC_ID ((funcIdType_t) 0x00000040)
#define UHF_READNUMBEROFRXPACKETS_FUNCRESP_ID ((funcIdType_t) 0x00000007)
#define UHF_EXBEACONSETSEND_FUNCRESP_ID ((funcIdType_t) 0x00000029)
#define UHF_READCOUNTERS_FUNCRESP_ID ((funcIdType_t) 0x00000040)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    Structure for statistical counters
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
} PACKED_STRUCT UHF_sCounters_t;

/*
    General status returned for FP commands
*/
#define UHF_EESSA_UHFSTATUS_OK ((uint8_t) 0)
#define UHF_EESSA_UHFSTATUS_ERROR ((uint8_t) 1)
#define UHF_EESSA_UHFSTATUS_ERROR_BAD_DATA ((uint8_t) 2)
#define UHF_EESSA_UHFSTATUS_ERROR_NOT_IMPLEMENTED ((uint8_t) 3)
#define UHF_EESSA_UHFSTATUS_ERROR_I2C_NACK ((uint8_t) 4)
#define UHF_EESSA_UHFSTATUS_UHF_ERR_BUSY ((uint8_t) 5)
#define UHF_EESSA_UHFSTATUS_MAX_CNT  ((uint8_t) 6)
typedef uint8_t UHF_eESSA_UhfStatus_t;

/*
    Structure for Beacon transmission request operation
*/
typedef struct {
    uint8_t u8Size;
    uint8_t au8Data[73];
} PACKED_STRUCT UHF_sExBeacon_t;


typedef struct {
    UHF_sExBeacon_t sData;
} PACKED_STRUCT UHFExBeaconSetSendRequestData_t;


typedef struct {
    uint32_t u32Packets;
} PACKED_STRUCT UHFReadNumberOfRxPacketsResponseData_t;

typedef struct {
    UHF_eESSA_UhfStatus_t eOpResult;
} PACKED_STRUCT UHFExBeaconSetSendResponseData_t;

typedef struct {
    UHF_sCounters_t sCfg;
} PACKED_STRUCT UHFReadCountersResponseData_t;


#endif  // #ifndef FP_UHFPROTOCOLTYPES_H

