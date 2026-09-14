/*!
********************************************************************************************
* @file FP_sdrProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface sdr v2.0
*
* @copyright         (C) Copyright EnduroSat
*
*                    Contents and presentations are protected world-wide.
*                    Any kind of using, copying etc. is prohibited without prior permission.
*                    All rights - incl. industrial property rights - are reserved.
*
*-------------------------------------------------------------------------------------------
* GENERATOR: org.endurosat.generators.macchiato.binders.Gen_C v2.14
*-------------------------------------------------------------------------------------------
* !!! Please note that this code is fully GENERATED and shall not be manually modified as
* all changes will be overwritten !!!
********************************************************************************************
*/

#ifndef FP_SDRPROTOCOLTYPES_H
#define FP_SDRPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_SDR ((uint16_t) (0x00000063))

#define SDR_SDR_UPLOAD_FUNC_ID ((funcIdType_t) 0x00000000)
#define SDR_SDR_DOWNLOAD_FUNC_ID ((funcIdType_t) 0x00000001)
#define SDR_SDR_POLL_LATEST_FT_STATUS_FUNC_ID ((funcIdType_t) 0x00000002)
#define SDR_SDR_GET_STATE_FUNC_ID ((funcIdType_t) 0x00000003)
#define SDR_SDR_UPLOAD_FUNCRESP_ID ((funcIdType_t) 0x00000000)
#define SDR_SDR_DOWNLOAD_FUNCRESP_ID ((funcIdType_t) 0x00000001)
#define SDR_SDR_POLL_LATEST_FT_STATUS_FUNCRESP_ID ((funcIdType_t) 0x00000002)
#define SDR_SDR_GET_STATE_FUNCRESP_ID ((funcIdType_t) 0x00000003)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    File operation status
*/
#define SDR_FILESTATUS_ES_TFTP_ERR_NOT_DEFINED ((uint8_t) 0)
#define SDR_FILESTATUS_ES_TFTP_ERR_FILE_NOT_FOUND ((uint8_t) 1)
#define SDR_FILESTATUS_ES_TFTP_ERR_ACESS_VIOLATION ((uint8_t) 2)
#define SDR_FILESTATUS_ES_TFTP_ERR_DISK_FULL_OR_ALLOCATION_EXCEEDED ((uint8_t) 3)
#define SDR_FILESTATUS_ES_TFTP_ERR_ILLEGAL_TFTP_OPERATION ((uint8_t) 4)
#define SDR_FILESTATUS_ES_TFTP_ERR_UNKNOWN_TRANSFER_ID ((uint8_t) 5)
#define SDR_FILESTATUS_ES_TFTP_ERR_FILE_ALREADY_EXISTS ((uint8_t) 6)
#define SDR_FILESTATUS_ES_TFTP_ERR_NO_SUCH_USER ((uint8_t) 7)
#define SDR_FILESTATUS_ES_TFTP_STATUS_OK ((uint8_t) 8)
#define SDR_FILESTATUS_ES_TFTP_TL_NOT_INIT ((uint8_t) 9)
#define SDR_FILESTATUS_ES_TFTP_CANNOT_OPEN_DEST_FILE_FOR_WRITE ((uint8_t) 10)
#define SDR_FILESTATUS_ES_TFTP_FAILED_TO_WRITE_TO_DEST_FILE ((uint8_t) 11)
#define SDR_FILESTATUS_ES_TFTP_FAILED_TO_CLOSE_DEST_FILE ((uint8_t) 12)
#define SDR_FILESTATUS_ES_TFTP_CANNOT_OPEN_SOURCE_FILE_FOR_READ ((uint8_t) 13)
#define SDR_FILESTATUS_ES_TFTP_FILE_NOT_FOUND_ON_SOURCE ((uint8_t) 14)
#define SDR_FILESTATUS_ES_TFTP_FAILED_TO_READ_FROM_SOURCE_FILE ((uint8_t) 15)
#define SDR_FILESTATUS_ES_TFTP_FAILED_TO_CLOSE_SOURCE_FILE ((uint8_t) 16)
#define SDR_FILESTATUS_ES_TFTP_CONNECTION_TO_SERVER_FAILED ((uint8_t) 17)
#define SDR_FILESTATUS_ES_TFTP_FAILED_TO_DISCONNECT_FROM_SERVER ((uint8_t) 18)
#define SDR_FILESTATUS_ES_TFTP_RECV_FAILED ((uint8_t) 19)
#define SDR_FILESTATUS_ES_TFTP_SEND_FAILED ((uint8_t) 20)
#define SDR_FILESTATUS_ES_TFTP_BLOCK_NUMBER_MISMATCH ((uint8_t) 21)
#define SDR_FILESTATUS_ES_TFTP_DOWNLOADED_FILE_EMPTY ((uint8_t) 22)
#define SDR_FILESTATUS_ES_TFTP_TRANSFER_PENDING ((uint8_t) 23)
#define SDR_FILESTATUS_ES_TFTP_BUSY ((uint8_t) 24)
#define SDR_FILESTATUS_MAX_CNT  ((uint8_t) 25)
typedef uint8_t SDR_FileStatus_t;

/*
    State machine states.
*/
#define SDR_STATEMACHINESTATE_ROOT ((uint8_t) 0)
#define SDR_STATEMACHINESTATE_INACTIVE ((uint8_t) 1)
#define SDR_STATEMACHINESTATE_BOOTING ((uint8_t) 2)
#define SDR_STATEMACHINESTATE_SYNCING ((uint8_t) 3)
#define SDR_STATEMACHINESTATE_READY ((uint8_t) 4)
#define SDR_STATEMACHINESTATE_BUSY ((uint8_t) 5)
#define SDR_STATEMACHINESTATE_MAX_CNT  ((uint8_t) 6)
typedef uint8_t SDR_StateMachineState_t;

/*
    File operation type
*/
typedef struct {
    uint8_t u8Obc_fileSize;
    char strObc_file[47];
    uint8_t u8Sdr_fileSize;
    char strSdr_file[197];
} PACKED_STRUCT SDR_FileOp_t;


typedef struct {
    SDR_FileOp_t sFile;
} PACKED_STRUCT sdrsdr_uploadRequestData_t;

typedef struct {
    SDR_FileOp_t sFile;
} PACKED_STRUCT sdrsdr_downloadRequestData_t;


typedef struct {
    SDR_FileStatus_t eStatus;
} PACKED_STRUCT sdrsdr_uploadResponseData_t;

typedef struct {
    SDR_FileStatus_t eStatus;
} PACKED_STRUCT sdrsdr_downloadResponseData_t;

typedef struct {
    SDR_FileStatus_t eStatus;
} PACKED_STRUCT sdrsdr_poll_latest_ft_statusResponseData_t;

typedef struct {
    SDR_StateMachineState_t eSm_state;
} PACKED_STRUCT sdrsdr_get_stateResponseData_t;


#endif  // #ifndef FP_SDRPROTOCOLTYPES_H

