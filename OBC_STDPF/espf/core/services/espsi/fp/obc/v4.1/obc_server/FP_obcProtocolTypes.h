/*!
********************************************************************************************
* @file FP_obcProtocolTypes.h
* @brief Protocol public type declarations
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

#ifndef FP_OBCPROTOCOLTYPES_H
#define FP_OBCPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_OBC ((uint16_t) (0x0000000E))

#define OBC_GET_ALL_GPO_VALUES_FUNC_ID ((funcIdType_t) 0x0000000E)
#define OBC_SET_ALL_GPO_VALUES_FUNC_ID ((funcIdType_t) 0x0000000F)
#define OBC_GET_I2C_PULL_UPS_STATE_FUNC_ID ((funcIdType_t) 0x00000012)
#define OBC_SET_I2C_PULL_UPS_STATE_FUNC_ID ((funcIdType_t) 0x00000013)
#define OBC_GET_UPTIME_FUNC_ID ((funcIdType_t) 0x00000018)
#define OBC_GET_RESET_COUNTERS_FUNC_ID ((funcIdType_t) 0x0000002A)
#define OBC_CLEAR_RESET_COUNTER_FUNC_ID ((funcIdType_t) 0x0000002B)
#define OBC_TRIGGER_RESET_IN_MODE_FUNC_ID ((funcIdType_t) 0x00000036)
#define OBC_SET_DEVICE_MAC_ADDRESS_FUNC_ID ((funcIdType_t) 0x00000040)
#define OBC_GET_DEVICE_MAC_ADDRESS_FUNC_ID ((funcIdType_t) 0x00000041)
#define OBC_GET_ALL_GPO_VALUES_FUNCRESP_ID ((funcIdType_t) 0x0000000E)
#define OBC_SET_ALL_GPO_VALUES_FUNCRESP_ID ((funcIdType_t) 0x0000000F)
#define OBC_GET_I2C_PULL_UPS_STATE_FUNCRESP_ID ((funcIdType_t) 0x00000012)
#define OBC_SET_I2C_PULL_UPS_STATE_FUNCRESP_ID ((funcIdType_t) 0x00000013)
#define OBC_GET_UPTIME_FUNCRESP_ID ((funcIdType_t) 0x00000018)
#define OBC_GET_RESET_COUNTERS_FUNCRESP_ID ((funcIdType_t) 0x0000002A)
#define OBC_CLEAR_RESET_COUNTER_FUNCRESP_ID ((funcIdType_t) 0x0000002B)
#define OBC_TRIGGER_RESET_IN_MODE_FUNCRESP_ID ((funcIdType_t) 0x00000036)
#define OBC_SET_DEVICE_MAC_ADDRESS_FUNCRESP_ID ((funcIdType_t) 0x00000040)
#define OBC_GET_DEVICE_MAC_ADDRESS_FUNCRESP_ID ((funcIdType_t) 0x00000041)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    Enumeration of the GPO setup states SET/RESET/DONT_TOUCH.
*/
#define OBC_GPOSETTYPES_DONT_TOUCH ((uint8_t) 0)
#define OBC_GPOSETTYPES_SET ((uint8_t) 1)
#define OBC_GPOSETTYPES_RESET ((uint8_t) 2)
#define OBC_GPOSETTYPES_MAX_CNT  ((uint8_t) 3)
typedef uint8_t OBC_GpoSetTypes_t;

/*
    This structure keeps information about the OBC reset counters.
                          Each counter represents the number of specific resets which took place since last
                          clear operation.
*/
typedef struct {
    uint32_t u32Wwd;
    uint32_t u32Iwd;
    uint32_t u32Lpr;
    uint32_t u32Por;
    uint32_t u32Rst_pin;
    uint32_t u32Bor;
    uint32_t u32Hard_fault;
    uint32_t u32Mem_fault;
    uint32_t u32Bus_fault;
    uint32_t u32Usage_fault;
} PACKED_STRUCT OBC_ResetCountersInfo_t;

/*
    This enumeration maps to the individual fields of the ResetCountersInfo structure
*/
#define OBC_RESETCNTRID_WWD ((uint8_t) 0)
#define OBC_RESETCNTRID_IWD ((uint8_t) 1)
#define OBC_RESETCNTRID_LPR ((uint8_t) 2)
#define OBC_RESETCNTRID_POR ((uint8_t) 3)
#define OBC_RESETCNTRID_RST_PIN ((uint8_t) 4)
#define OBC_RESETCNTRID_BOR ((uint8_t) 5)
#define OBC_RESETCNTRID_HARD_FAULT ((uint8_t) 6)
#define OBC_RESETCNTRID_MEM_FAULT ((uint8_t) 7)
#define OBC_RESETCNTRID_BUS_FAULT ((uint8_t) 8)
#define OBC_RESETCNTRID_USAGE_FAULT ((uint8_t) 9)
#define OBC_RESETCNTRID_ALL ((uint8_t) 10)
#define OBC_RESETCNTRID_MAX_CNT  ((uint8_t) 11)
typedef uint8_t OBC_ResetCntrId_t;

/*
    General status type used for SW-related communication and/or settings.
*/
#define OBC_STANDARDRESULT_SUCCESS ((uint8_t) 0)
#define OBC_STANDARDRESULT_ERROR ((uint8_t) 1)
#define OBC_STANDARDRESULT_INVALID_ARGS ((uint8_t) 2)
#define OBC_STANDARDRESULT_NOT_SUPPORTED ((uint8_t) 3)
#define OBC_STANDARDRESULT_MAX_CNT  ((uint8_t) 4)
typedef uint8_t OBC_StandardResult_t;

/*
    Onboard Computer Application mode
*/
#define OBC_APPLICATIONMODE_APPLICATION ((uint8_t) 0)
#define OBC_APPLICATIONMODE_BOOTLOADER ((uint8_t) 1)
#define OBC_APPLICATIONMODE_MAX_CNT  ((uint8_t) 2)
typedef uint8_t OBC_ApplicationMode_t;

/*
    Structure for the I2C Pull-Up Resistors.
*/
typedef struct {
    bool bSystem_bus_4K7;
    bool bSystem_bus_10K;
    bool bPayload_bus_4K7;
    bool bPayload_bus_10K;
} PACKED_STRUCT OBC_I2CPullUpsState_t;

/*
    Structure for getting GPO ports current configuration values SET/RESET.
*/
typedef struct {
    bool bGpo_port_nvm;
    bool bGpo_port_active;
} PACKED_STRUCT OBC_GpoGetPortsType_t;

/*
    Possible output set ports options, both nvm stored and temporary set.
*/
typedef struct {
    OBC_GpoSetTypes_t eGpo_port_nvm;
    OBC_GpoSetTypes_t eGpo_port_active;
} PACKED_STRUCT OBC_GpoSetPortsType_t;

/*
    Structure for getting all output ports, both nvm(default) and current(active).
*/
typedef struct {
    OBC_GpoGetPortsType_t sGpo_1;
    OBC_GpoGetPortsType_t sGpo_2;
    OBC_GpoGetPortsType_t sGpo_3;
    OBC_GpoGetPortsType_t sGpo_5;
    OBC_GpoGetPortsType_t sGpo_4_6;
    OBC_GpoGetPortsType_t sGpo_7;
    OBC_GpoGetPortsType_t sGpo_8;
} PACKED_STRUCT OBC_GpoPortsGetStruct_t;

/*
    Structure for setting all output ports, both nvm (default) and current(active).
*/
typedef struct {
    OBC_GpoSetPortsType_t sGpo_1;
    OBC_GpoSetPortsType_t sGpo_2;
    OBC_GpoSetPortsType_t sGpo_3;
    OBC_GpoSetPortsType_t sGpo_5;
    OBC_GpoSetPortsType_t sGpo_4_6;
    OBC_GpoSetPortsType_t sGpo_7;
    OBC_GpoSetPortsType_t sGpo_8;
} PACKED_STRUCT OBC_GpoPortsSetStruct_t;


typedef struct {
    OBC_GpoPortsSetStruct_t sGpo;
} PACKED_STRUCT obcset_all_gpo_valuesRequestData_t;

typedef struct {
    OBC_I2CPullUpsState_t sPull_up_state;
} PACKED_STRUCT obcset_i2c_pull_ups_stateRequestData_t;

typedef struct {
    OBC_ResetCntrId_t eId;
} PACKED_STRUCT obcclear_reset_counterRequestData_t;

typedef struct {
    OBC_ApplicationMode_t eStart_mode;
} PACKED_STRUCT obctrigger_reset_in_modeRequestData_t;

typedef struct {
    uint8_t u8New_mac_address;
    uint8_t u8Device_id;
} PACKED_STRUCT obcset_device_mac_addressRequestData_t;

typedef struct {
    uint8_t u8Device_id;
} PACKED_STRUCT obcget_device_mac_addressRequestData_t;


typedef struct {
    OBC_GpoPortsGetStruct_t sGpo;
    OBC_StandardResult_t eResult;
} PACKED_STRUCT obcget_all_gpo_valuesResponseData_t;

typedef struct {
    OBC_StandardResult_t eResult;
} PACKED_STRUCT obcset_all_gpo_valuesResponseData_t;

typedef struct {
    OBC_I2CPullUpsState_t sNvm_pull_ups_state;
    OBC_I2CPullUpsState_t sIo_pull_ups_state;
} PACKED_STRUCT obcget_i2c_pull_ups_stateResponseData_t;

typedef struct {
    OBC_I2CPullUpsState_t sPull_ups_io_state;
} PACKED_STRUCT obcset_i2c_pull_ups_stateResponseData_t;

typedef struct {
    uint32_t u32Uptime;
} PACKED_STRUCT obcget_uptimeResponseData_t;

typedef struct {
    OBC_ResetCountersInfo_t sStatus;
} PACKED_STRUCT obcget_reset_countersResponseData_t;

typedef struct {
    OBC_StandardResult_t eOp_result;
} PACKED_STRUCT obcclear_reset_counterResponseData_t;

typedef struct {
    OBC_StandardResult_t eOp_result;
} PACKED_STRUCT obctrigger_reset_in_modeResponseData_t;

typedef struct {
    OBC_StandardResult_t eOp_result;
} PACKED_STRUCT obcset_device_mac_addressResponseData_t;

typedef struct {
    uint8_t u8Mac_address;
    OBC_StandardResult_t eOp_result;
} PACKED_STRUCT obcget_device_mac_addressResponseData_t;


#endif  // #ifndef FP_OBCPROTOCOLTYPES_H

