/*!
********************************************************************************************
* @file FP_nvm_epsProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface nvm_eps v0.1
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

#ifndef FP_NVM_EPSPROTOCOLTYPES_H
#define FP_NVM_EPSPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_NVM_EPS ((uint16_t) (0x0000001E))

#define NVM_EPS_SET_EPS2_BP_MAC_ADDRESS_FUNC_ID ((funcIdType_t) 0x00000001)
#define NVM_EPS_GET_EPS2_BP_MAC_ADDRESS_FUNC_ID ((funcIdType_t) 0x00000002)
#define NVM_EPS_SET_EPS3_BP_MAC_ADDRESSES_FUNC_ID ((funcIdType_t) 0x00000003)
#define NVM_EPS_GET_EPS3_BP_MAC_ADDRESSES_FUNC_ID ((funcIdType_t) 0x00000004)
#define NVM_EPS_SET_EPS3_PDM_A_MAC_ADDRESSES_FUNC_ID ((funcIdType_t) 0x00000005)
#define NVM_EPS_GET_EPS3_PDM_A_MAC_ADDRESSES_FUNC_ID ((funcIdType_t) 0x00000006)
#define NVM_EPS_SET_EPS3_PDM_B_MAC_ADDRESSES_FUNC_ID ((funcIdType_t) 0x00000007)
#define NVM_EPS_GET_EPS3_PDM_B_MAC_ADDRESSES_FUNC_ID ((funcIdType_t) 0x00000008)
#define NVM_EPS_SET_EPS3_EXPANDER_MAC_ADDRESSES_FUNC_ID ((funcIdType_t) 0x00000009)
#define NVM_EPS_GET_EPS3_EXPANDER_MAC_ADDRESSES_FUNC_ID ((funcIdType_t) 0x0000000A)
#define NVM_EPS_SET_EPS3_INPUT_STAGE_MAC_ADDRESSES_FUNC_ID ((funcIdType_t) 0x0000000B)
#define NVM_EPS_GET_EPS3_INPUT_STAGE_MAC_ADDRESSES_FUNC_ID ((funcIdType_t) 0x0000000C)
#define NVM_EPS_SET_EPS2_BP_MAC_ADDRESS_FUNCRESP_ID ((funcIdType_t) 0x00000001)
#define NVM_EPS_GET_EPS2_BP_MAC_ADDRESS_FUNCRESP_ID ((funcIdType_t) 0x00000002)
#define NVM_EPS_SET_EPS3_BP_MAC_ADDRESSES_FUNCRESP_ID ((funcIdType_t) 0x00000003)
#define NVM_EPS_GET_EPS3_BP_MAC_ADDRESSES_FUNCRESP_ID ((funcIdType_t) 0x00000004)
#define NVM_EPS_SET_EPS3_PDM_A_MAC_ADDRESSES_FUNCRESP_ID ((funcIdType_t) 0x00000005)
#define NVM_EPS_GET_EPS3_PDM_A_MAC_ADDRESSES_FUNCRESP_ID ((funcIdType_t) 0x00000006)
#define NVM_EPS_SET_EPS3_PDM_B_MAC_ADDRESSES_FUNCRESP_ID ((funcIdType_t) 0x00000007)
#define NVM_EPS_GET_EPS3_PDM_B_MAC_ADDRESSES_FUNCRESP_ID ((funcIdType_t) 0x00000008)
#define NVM_EPS_SET_EPS3_EXPANDER_MAC_ADDRESSES_FUNCRESP_ID ((funcIdType_t) 0x00000009)
#define NVM_EPS_GET_EPS3_EXPANDER_MAC_ADDRESSES_FUNCRESP_ID ((funcIdType_t) 0x0000000A)
#define NVM_EPS_SET_EPS3_INPUT_STAGE_MAC_ADDRESSES_FUNCRESP_ID ((funcIdType_t) 0x0000000B)
#define NVM_EPS_GET_EPS3_INPUT_STAGE_MAC_ADDRESSES_FUNCRESP_ID ((funcIdType_t) 0x0000000C)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    EPS Battery Pack IDs. Here is an extensive list of all possible IDs of the EPS_III BPs in a system. 
        Depending on count of the EPS EPS_III BPs in the specific configuration only the first N of those will be used.
*/
#define NVM_EPS_EPSIIIBPIDTYPE_EPSIII_BP_0 ((uint8_t) 0)
#define NVM_EPS_EPSIIIBPIDTYPE_MAX_CNT  ((uint8_t) 1)
typedef uint8_t NVM_EPS_EpsIIIBpIdType_t;

/*
    EPS Battery Pack IDs. Here is an extensive list of all possible IDs of the EPS_III PDM_As in a system. 
        Depending on count of the EPS EPS_III PDM_As in the specific configuration only the first N of those will be used.
*/
#define NVM_EPS_EPSIIIPDMAIDTYPE_EPSIII_PDM_A_0 ((uint8_t) 0)
#define NVM_EPS_EPSIIIPDMAIDTYPE_MAX_CNT  ((uint8_t) 1)
typedef uint8_t NVM_EPS_EpsIIIPdmAIdType_t;

/*
    General status type used for SW-related communication and/or settings.
*/
#define NVM_EPS_STANDARDRESULT_SUCCESS ((uint8_t) 0)
#define NVM_EPS_STANDARDRESULT_ERROR ((uint8_t) 1)
#define NVM_EPS_STANDARDRESULT_INVALID_ARGS ((uint8_t) 2)
#define NVM_EPS_STANDARDRESULT_NOT_SUPPORTED ((uint8_t) 3)
#define NVM_EPS_STANDARDRESULT_MAX_CNT  ((uint8_t) 4)
typedef uint8_t NVM_EPS_StandardResult_t;

/*
    EPS Battery Pack IDs. Here is an extensive list of all possible IDs of the EPS_III EXPANDERs in a system. 
        Depending on count of the EPS_III EXPANDERs in the specific configuration only the first N of those will be used.
*/
#define NVM_EPS_EPSIIIEXPANDERIDTYPE_EPSIII_EXPANDER_0 ((uint8_t) 0)
#define NVM_EPS_EPSIIIEXPANDERIDTYPE_MAX_CNT  ((uint8_t) 1)
typedef uint8_t NVM_EPS_EpsIIIExpanderIdType_t;

/*
    EPS Battery Pack IDs. Here is an extensive list of all possible IDs of the EPS_III INPUT_STAGE in a system. 
        Depending on count of the EPS EPS_III INPUT_STAGEs in the specific configuration only the first N of those will be used.
*/
#define NVM_EPS_EPSIIIINPUTSTAGEIDTYPE_EPSIII_INPUT_STAGE_0 ((uint8_t) 0)
#define NVM_EPS_EPSIIIINPUTSTAGEIDTYPE_MAX_CNT  ((uint8_t) 1)
typedef uint8_t NVM_EPS_EpsIIIInputStageIdType_t;

/*
    EPS Battery Pack IDs. Here is an extensive list of all possible IDs of the BPs in a system. 
        Depending on count of the EPS BPs in the specific configuration only the first N of those will be used.
*/
#define NVM_EPS_EPSBPIDTYPE_EPS_BP_0 ((uint8_t) 0)
#define NVM_EPS_EPSBPIDTYPE_EPS_BP_1 ((uint8_t) 1)
#define NVM_EPS_EPSBPIDTYPE_MAX_CNT  ((uint8_t) 2)
typedef uint8_t NVM_EPS_EpsBpIdType_t;

/*
    EPS Battery Pack IDs. Here is an extensive list of all possible IDs of the EPS_III PDM_Bs in a system. 
        Depending on count of the EPS_III PDM_Bs in the specific configuration only the first N of those will be used.
*/
#define NVM_EPS_EPSIIIPDMBIDTYPE_EPSIII_PDM_B_0 ((uint8_t) 0)
#define NVM_EPS_EPSIIIPDMBIDTYPE_MAX_CNT  ((uint8_t) 1)
typedef uint8_t NVM_EPS_EpsIIIPdmBIdType_t;


typedef struct {
    uint8_t u8New_mac_address;
    NVM_EPS_EpsBpIdType_t eDevice_id;
} PACKED_STRUCT nvm_epsset_eps2_bp_mac_addressRequestData_t;

typedef struct {
    NVM_EPS_EpsBpIdType_t eDevice_id;
} PACKED_STRUCT nvm_epsget_eps2_bp_mac_addressRequestData_t;

typedef struct {
    uint8_t u8New_mac_address;
    NVM_EPS_EpsIIIBpIdType_t eDevice_id;
} PACKED_STRUCT nvm_epsset_eps3_bp_mac_addressesRequestData_t;

typedef struct {
    NVM_EPS_EpsIIIBpIdType_t eDevice_id;
} PACKED_STRUCT nvm_epsget_eps3_bp_mac_addressesRequestData_t;

typedef struct {
    uint8_t u8New_mac_address;
    NVM_EPS_EpsIIIPdmAIdType_t eDevice_id;
} PACKED_STRUCT nvm_epsset_eps3_pdm_a_mac_addressesRequestData_t;

typedef struct {
    NVM_EPS_EpsIIIPdmAIdType_t eDevice_id;
} PACKED_STRUCT nvm_epsget_eps3_pdm_a_mac_addressesRequestData_t;

typedef struct {
    uint8_t u8New_mac_address;
    NVM_EPS_EpsIIIPdmBIdType_t eDevice_id;
} PACKED_STRUCT nvm_epsset_eps3_pdm_b_mac_addressesRequestData_t;

typedef struct {
    NVM_EPS_EpsIIIPdmBIdType_t eDevice_id;
} PACKED_STRUCT nvm_epsget_eps3_pdm_b_mac_addressesRequestData_t;

typedef struct {
    uint8_t u8New_mac_address;
    NVM_EPS_EpsIIIExpanderIdType_t eDevice_id;
} PACKED_STRUCT nvm_epsset_eps3_expander_mac_addressesRequestData_t;

typedef struct {
    NVM_EPS_EpsIIIExpanderIdType_t eDevice_id;
} PACKED_STRUCT nvm_epsget_eps3_expander_mac_addressesRequestData_t;

typedef struct {
    uint8_t u8New_mac_address;
    NVM_EPS_EpsIIIInputStageIdType_t eDevice_id;
} PACKED_STRUCT nvm_epsset_eps3_input_stage_mac_addressesRequestData_t;

typedef struct {
    NVM_EPS_EpsIIIInputStageIdType_t eDevice_id;
} PACKED_STRUCT nvm_epsget_eps3_input_stage_mac_addressesRequestData_t;


typedef struct {
    NVM_EPS_StandardResult_t eOp_result;
} PACKED_STRUCT nvm_epsset_eps2_bp_mac_addressResponseData_t;

typedef struct {
    uint8_t u8Mac_address;
    NVM_EPS_StandardResult_t eOp_result;
} PACKED_STRUCT nvm_epsget_eps2_bp_mac_addressResponseData_t;

typedef struct {
    NVM_EPS_StandardResult_t eOp_result;
} PACKED_STRUCT nvm_epsset_eps3_bp_mac_addressesResponseData_t;

typedef struct {
    uint8_t u8Mac_address;
    NVM_EPS_StandardResult_t eOp_result;
} PACKED_STRUCT nvm_epsget_eps3_bp_mac_addressesResponseData_t;

typedef struct {
    NVM_EPS_StandardResult_t eOp_result;
} PACKED_STRUCT nvm_epsset_eps3_pdm_a_mac_addressesResponseData_t;

typedef struct {
    uint8_t u8Mac_address;
    NVM_EPS_StandardResult_t eOp_result;
} PACKED_STRUCT nvm_epsget_eps3_pdm_a_mac_addressesResponseData_t;

typedef struct {
    NVM_EPS_StandardResult_t eOp_result;
} PACKED_STRUCT nvm_epsset_eps3_pdm_b_mac_addressesResponseData_t;

typedef struct {
    uint8_t u8Mac_address;
    NVM_EPS_StandardResult_t eOp_result;
} PACKED_STRUCT nvm_epsget_eps3_pdm_b_mac_addressesResponseData_t;

typedef struct {
    NVM_EPS_StandardResult_t eOp_result;
} PACKED_STRUCT nvm_epsset_eps3_expander_mac_addressesResponseData_t;

typedef struct {
    uint8_t u8Mac_address;
    NVM_EPS_StandardResult_t eOp_result;
} PACKED_STRUCT nvm_epsget_eps3_expander_mac_addressesResponseData_t;

typedef struct {
    NVM_EPS_StandardResult_t eOp_result;
} PACKED_STRUCT nvm_epsset_eps3_input_stage_mac_addressesResponseData_t;

typedef struct {
    uint8_t u8Mac_address;
    NVM_EPS_StandardResult_t eOp_result;
} PACKED_STRUCT nvm_epsget_eps3_input_stage_mac_addressesResponseData_t;


#endif  // #ifndef FP_NVM_EPSPROTOCOLTYPES_H

