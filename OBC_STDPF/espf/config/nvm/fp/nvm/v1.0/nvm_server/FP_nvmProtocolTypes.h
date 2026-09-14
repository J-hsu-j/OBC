/*!
********************************************************************************************
* @file FP_nvmProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface nvm v1.0
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

#ifndef FP_NVMPROTOCOLTYPES_H
#define FP_NVMPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_NVM ((uint16_t) (0x00000103))

#define NVM_RESTORE_DEFAULTS_FUNC_ID ((funcIdType_t) 0x00000000)
#define NVM_RESTORE_DEFAULTS_FUNCRESP_ID ((funcIdType_t) 0x00000000)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
#define NVM_BLOCKID_BOOTLAYOUTVERSION ((uint8_t) 0)
#define NVM_BLOCKID_BOOTDATA ((uint8_t) 1)
#define NVM_BLOCKID_MODULEID ((uint8_t) 2)
#define NVM_BLOCKID_MACCONFIG ((uint8_t) 3)
#define NVM_BLOCKID_NVM_RESERVED ((uint8_t) 4)
#define NVM_BLOCKID_BEACONS_GENERAL ((uint8_t) 5)
#define NVM_BLOCKID_BEACONS_PRESETS ((uint8_t) 6)
#define NVM_BLOCKID_NVM_APP_BLOCK_CONOPS_CONFIG ((uint8_t) 7)
#define NVM_BLOCKID_TELEMETRY_GENERAL_0 ((uint8_t) 8)
#define NVM_BLOCKID_TELEMETRY_PRESETS_0 ((uint8_t) 9)
#define NVM_BLOCKID_TELEMETRY_FILE_CFG_0 ((uint8_t) 10)
#define NVM_BLOCKID_TELEMETRY_PERSISTENT_DATA_0 ((uint8_t) 11)
#define NVM_BLOCKID_TELEMETRY_GENERAL_1 ((uint8_t) 12)
#define NVM_BLOCKID_TELEMETRY_PRESETS_1 ((uint8_t) 13)
#define NVM_BLOCKID_TELEMETRY_FILE_CFG_1 ((uint8_t) 14)
#define NVM_BLOCKID_TELEMETRY_PERSISTENT_DATA_1 ((uint8_t) 15)
#define NVM_BLOCKID_EPS_M_CONFIG ((uint8_t) 16)
#define NVM_BLOCKID_CUBEADCS_ERR_HANDL_CONFIG ((uint8_t) 17)
#define NVM_BLOCKID_CUBEADCS_STATUS ((uint8_t) 18)
#define NVM_BLOCKID_I2C_CONFIG ((uint8_t) 19)
#define NVM_BLOCKID_CUBEADCS_ANGLE_LIMITS ((uint8_t) 20)
#define NVM_BLOCKID_AOCS_PM_CONFIG ((uint8_t) 21)
#define NVM_BLOCKID_AOCS_PM_THRESHOLDS ((uint8_t) 22)
#define NVM_BLOCKID_COORDINATE_FRAMES ((uint8_t) 23)
#define NVM_BLOCKID_SDS_SENS_READ_FREQ_CFG ((uint8_t) 24)
#define NVM_BLOCKID_CRYPTO_CFG ((uint8_t) 25)
#define NVM_BLOCKID_CUBEADCS_SIMULATION_MODE ((uint8_t) 26)
#define NVM_BLOCKID_RTC_CALIB_DATA ((uint8_t) 27)
#define NVM_BLOCKID_GYROSCOPE_CONFIG ((uint8_t) 28)
#define NVM_BLOCKID_NVM_FM_STATS ((uint8_t) 29)
#define NVM_BLOCKID_CUBEADCS_SYS_STATE_CFG ((uint8_t) 30)
#define NVM_BLOCKID_NVM_MAC_ADDRESS_BOOK ((uint8_t) 31)
#define NVM_BLOCKID_CUBEADCS_GEN2_SYS_STATE_CFG ((uint8_t) 32)
#define NVM_BLOCKID_CUBEADCS_GEN2_TLM_CFG ((uint8_t) 33)
#define NVM_BLOCKID_ADCS_CMS_STATUS ((uint8_t) 34)
#define NVM_BLOCKID_FAULT_INDEX ((uint8_t) 35)
#define NVM_BLOCKID_FAULT_DATA0 ((uint8_t) 36)
#define NVM_BLOCKID_FAULT_DATA1 ((uint8_t) 37)
#define NVM_BLOCKID_FAULT_DATA2 ((uint8_t) 38)
#define NVM_BLOCKID_FAULT_DATA3 ((uint8_t) 39)
#define NVM_BLOCKID_FAULT_DATA4 ((uint8_t) 40)
#define NVM_BLOCKID_GPO_CONFIG ((uint8_t) 41)
#define NVM_BLOCKID_SCHEDULER_DATA ((uint8_t) 42)
#define NVM_BLOCKID_FDIR_SRV_DATA ((uint8_t) 43)
#define NVM_BLOCKID_CONOPS_DATA ((uint8_t) 44)
#define NVM_BLOCKID_XBAND_FE_CFG ((uint8_t) 45)
#define NVM_BLOCKID_GNSS_COMM_SETTINGS ((uint8_t) 46)
#define NVM_BLOCKID_COMM_LOSS_WD ((uint8_t) 47)
#define NVM_BLOCKID_CUBEADCS_GEN2_FDIR_CNT ((uint8_t) 48)
#define NVM_BLOCKID_TASK_STATS_CONFIG ((uint8_t) 49)
#define NVM_BLOCKID_TASK_STATS_CONFIG_PER_TASK ((uint8_t) 50)
#define NVM_BLOCKID_MAX_CNT  ((uint8_t) 51)
typedef uint8_t NVM_BlockId_t;

#define NVM_STANDARDRESULT_SUCCESS ((uint8_t) 0)
#define NVM_STANDARDRESULT_ERROR ((uint8_t) 1)
#define NVM_STANDARDRESULT_INVALID_ARGS ((uint8_t) 2)
#define NVM_STANDARDRESULT_NOT_SUPPORTED ((uint8_t) 3)
#define NVM_STANDARDRESULT_MAX_CNT  ((uint8_t) 4)
typedef uint8_t NVM_StandardResult_t;


typedef struct {
    NVM_BlockId_t eBlock_id;
} PACKED_STRUCT nvmrestore_defaultsRequestData_t;


typedef struct {
    NVM_StandardResult_t eOp_result;
} PACKED_STRUCT nvmrestore_defaultsResponseData_t;


#endif  // #ifndef FP_NVMPROTOCOLTYPES_H

