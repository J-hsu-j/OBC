/*!
********************************************************************************************
* @file FP_gnssProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface gnss v1.2
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

#ifndef FP_GNSSPROTOCOLTYPES_H
#define FP_GNSSPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_GNSS ((uint16_t) (0x00000017))

#define GNSS_SET_POWER_FUNC_ID ((funcIdType_t) 0x00000001)
#define GNSS_GET_POWER_FUNC_ID ((funcIdType_t) 0x00000002)
#define GNSS_REQUEST_COMMAND_EXECUTION_FUNC_ID ((funcIdType_t) 0x00000003)
#define GNSS_GET_COMMAND_EXECUTION_STATUS_FUNC_ID ((funcIdType_t) 0x00000004)
#define GNSS_SET_GNSS_UART_BAUDRATE_FUNC_ID ((funcIdType_t) 0x00000005)
#define GNSS_GET_GNSS_UART_BAUDRATE_FUNC_ID ((funcIdType_t) 0x00000006)
#define GNSS_SET_POWER_FUNCRESP_ID ((funcIdType_t) 0x00000001)
#define GNSS_GET_POWER_FUNCRESP_ID ((funcIdType_t) 0x00000002)
#define GNSS_REQUEST_COMMAND_EXECUTION_FUNCRESP_ID ((funcIdType_t) 0x00000003)
#define GNSS_GET_COMMAND_EXECUTION_STATUS_FUNCRESP_ID ((funcIdType_t) 0x00000004)
#define GNSS_SET_GNSS_UART_BAUDRATE_FUNCRESP_ID ((funcIdType_t) 0x00000005)
#define GNSS_GET_GNSS_UART_BAUDRATE_FUNCRESP_ID ((funcIdType_t) 0x00000006)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    GNSS UART baud rates
            The baud rate options are taken directly from the OEM7 Commands and Logs Reference Manual
*/
#define GNSS_BAUDRATE_BAUD_9600_BPS ((uint8_t) 0)
#define GNSS_BAUDRATE_BAUD_19200_BPS ((uint8_t) 1)
#define GNSS_BAUDRATE_BAUD_38400_BPS ((uint8_t) 2)
#define GNSS_BAUDRATE_BAUD_57600_BPS ((uint8_t) 3)
#define GNSS_BAUDRATE_BAUD_115200_BPS ((uint8_t) 4)
#define GNSS_BAUDRATE_BAUD_230400_BPS ((uint8_t) 5)
#define GNSS_BAUDRATE_BAUD_460800_BPS ((uint8_t) 6)
#define GNSS_BAUDRATE_MAX_CNT  ((uint8_t) 7)
typedef uint8_t GNSS_BaudRate_t;

/*
    Time as returned by the OBC
*/
typedef struct {
    uint8_t u8Hour;
    uint8_t u8Min;
    uint8_t u8Sec;
    uint16_t u16Ms;
    uint16_t u16Us;
} PACKED_STRUCT GNSS_TimeStruct_t;

/*
    gnss user command execution status
*/
#define GNSS_COMMANDSTATUS_OK ((uint8_t) 0)
#define GNSS_COMMANDSTATUS_ERROR ((uint8_t) 1)
#define GNSS_COMMANDSTATUS_QUEUE_FULL ((uint8_t) 2)
#define GNSS_COMMANDSTATUS_WRONG_PARAMS ((uint8_t) 3)
#define GNSS_COMMANDSTATUS_PROCESSING ((uint8_t) 4)
#define GNSS_COMMANDSTATUS_PENDING ((uint8_t) 5)
#define GNSS_COMMANDSTATUS_NOT_FOUND ((uint8_t) 6)
#define GNSS_COMMANDSTATUS_TIMED_OUT ((uint8_t) 7)
#define GNSS_COMMANDSTATUS_MUTEX_FAIL ((uint8_t) 8)
#define GNSS_COMMANDSTATUS_MAX_CNT  ((uint8_t) 9)
typedef uint8_t GNSS_CommandStatus_t;

/*
    operation status
*/
#define GNSS_OPERATION_ERROR ((uint8_t) 0)
#define GNSS_OPERATION_OK ((uint8_t) 1)
#define GNSS_OPERATION_MAX_CNT  ((uint8_t) 2)
typedef uint8_t GNSS_Operation_t;

/*
    gnss power status
*/
#define GNSS_POWER_OFF ((uint8_t) 0)
#define GNSS_POWER_ON ((uint8_t) 1)
#define GNSS_POWER_MAX_CNT  ((uint8_t) 2)
typedef uint8_t GNSS_Power_t;


typedef struct {
    GNSS_Power_t ePwr_status;
} PACKED_STRUCT gnssset_powerRequestData_t;

typedef struct {
    uint8_t u8CmdSize;
    char strCmd[240];
    uint32_t u32Timeout_ms;
} PACKED_STRUCT gnssrequest_command_executionRequestData_t;

typedef struct {
    uint8_t u8Cmd_id;
} PACKED_STRUCT gnssget_command_execution_statusRequestData_t;

typedef struct {
    GNSS_BaudRate_t eBaud_rate;
} PACKED_STRUCT gnssset_gnss_uart_baudrateRequestData_t;


typedef struct {
    GNSS_Operation_t eOp_status;
} PACKED_STRUCT gnssset_powerResponseData_t;

typedef struct {
    GNSS_Power_t ePwr_status;
    GNSS_Operation_t eOp_status;
} PACKED_STRUCT gnssget_powerResponseData_t;

typedef struct {
    uint8_t u8Cmd_id;
    GNSS_CommandStatus_t eCommand_status;
} PACKED_STRUCT gnssrequest_command_executionResponseData_t;

typedef struct {
    GNSS_CommandStatus_t eCommand_status;
    uint32_t u32Duration_ms;
    GNSS_TimeStruct_t sRequested_time;
    GNSS_TimeStruct_t sTime_started;
} PACKED_STRUCT gnssget_command_execution_statusResponseData_t;

typedef struct {
    GNSS_Operation_t eOp_status;
} PACKED_STRUCT gnssset_gnss_uart_baudrateResponseData_t;

typedef struct {
    GNSS_BaudRate_t eGnss_uart_baudrate_nvm;
    GNSS_BaudRate_t eGnss_uart_baudrate_current;
    GNSS_Operation_t eOp_status;
} PACKED_STRUCT gnssget_gnss_uart_baudrateResponseData_t;


#endif  // #ifndef FP_GNSSPROTOCOLTYPES_H

