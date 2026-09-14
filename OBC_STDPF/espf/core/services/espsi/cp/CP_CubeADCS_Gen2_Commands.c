/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup cp
 * @{
 *
 * @file    CP_CubeADCS_Gen2_Commands.c
 * @brief   Command Protocol commands for the Gen2 CubeADCS
 *
 * @}
 */

#include "FP_BaseProtocolTypes.h"
#include "CP_CubeADCS_Gen2_Commands.h"
#include "ESCP_CommandsLocalConf.h"
#include "cubeadcs_gen2.h"
#include "cubeadcs_gen2_gw.h"
#include "trace.h"
#include "if_sys_conf.h"

/** @brief Handle to the ID of a CubeADCS Gen2 node from the service context. */
#define NODE_ID pSrvCtx->pu8CmdData[0]

/** @brief Size of the node ID. */
#define NODE_ID_SIZE sizeof(TypesCommonFrameworkTypes1_AbstractNode)

/** @brief Handle to the status of a CubeADCS Gen2 API method in the CP response buffer. */
#define API_STATUS *(ErrorCode *)&pSrvCtx->pu8ResponseBuf[0]

/** @brief Size of the status of a CubeADCS Gen2 API method. */
#define API_STATUS_SIZE sizeof(ErrorCode)

/** @brief Handle to the request parameters of a CubeADCS Gen2 API method in the CP request buffer. */
#define API_DATA_ADDRESS &pSrvCtx->pu8CmdData[NODE_ID_SIZE]

/** @brief Handle to the response parameters of a CubeADCS Gen2 API method in the CP response buffer. */
#define API_DATA_RESP_ADDRESS &pSrvCtx->pu8ResponseBuf[API_STATUS_SIZE]

/** @brief Offset of the FP header in the request bytes of a CP command. */
#define FP_HDR_OFFSET 1

/** @brief Size of the FP header embedded in a CP command. */
#define FP_HDR_SIZE sizeof(ESSA_Stack_FP_MsgHdr_t)

/** @brief Offset of the request parameters of a CubeADCS Gen2 API method in the CP request buffer. */
#define CMD_PARAMS_OFFSET (FP_HDR_OFFSET + FP_HDR_SIZE)

/** @brief Default value of protocol ID used to indicate invalid ID read from the FIDL. */
#define PROTOCOL_ID_INVALID (uint16_t)(-1)

// CUBE_ADCS_GEN_SECTION_START::DEFINES
/** @brief Protocol ID of the first generated FIDL for the CubeADCS Gen2.Used for calculating index in a dispatch table. */
#define PROTOCOL_ID_OFFSET 300U
// CUBE_ADCS_GEN_SECTION_END::DEFINES

/** @typedef fs_param_sizes_t
 *  @brief Sizes of the request and response data of a CP command.
 */
typedef struct
{
    uint16_t req_size;  /**< number of request data bytes */
    uint16_t resp_size; /**< number of response data bytes */
} fs_param_sizes_t;

/** @typedef fs_iface_cmds_t
 *  @brief Descriptor of the request and response data sizes of the methods for an API interface module
 */
typedef struct
{
    const fs_param_sizes_t *const cmd_sizes;   /**< pointer to the array of sizes for the interface methods */
    uint32_t                      num_methods; /**< number of methods defined in the interface */
} fs_iface_cmds_t;

/** @typedef p_gen2_srv_api_t
 *  @brief Function pointer to a CP handler function for a specific CubeADCS Gen2 API method.
 */
typedef eCPDispatchResult_t (*p_gen2_srv_api_t)(sCubeAdcsGen2SrvCtx_t *const pSrvCtx);

/** @brief Converts the generated protocol ID to an index in a dispatch table.
 *  @param proto_id_raw  Protocol ID from the generated FIDL.
 *
 *  @return Index in the dispatch table on interface level.
 */
static uint16_t fs_get_protocol_id(const uint16_t proto_id_raw);

/** @brief Retrieves the sizes of request and response data for a given method.
 *  @param proto_id  Protocol ID based on the generated FIDL.
 *  @param func_id   Method ID from the generated FIDL.
 *
 *  @return Byte numbers for the request and response data of the specified interface method.
 */
static fs_param_sizes_t fs_get_cmd_sizes(const uint16_t proto_id, const funcIdType_t func_id);

/** @brief Checks validity of request and response data sizes.
 *  @param param_sizes     Structure holding the request and response data sizes of an interface method.
 *  @param cmd_data_size   Number of bytes in the request data of the CP command.
 *  @param resp_buf_size   Number of bytes in the response buffer of the CP command.
 *
 *  @return Byte numbers for the request and response data of the specified interface method.
 */
static bool fs_are_sizes_valid(const fs_param_sizes_t *const param_sizes,
                               const uint32_t                cmd_data_size,
                               const uint32_t                resp_buf_size);

/** @brief Checks if an interface is compatible with an actual physical node type. The AbstractNode ID is used
 *  to search in a dynamically maintained mapping data structure coming from the CubeComputer.
 *  @param protocol_id     ID of the FIDL which defines the checked interface.
 *  @param node_id         AbstractNode ID of the node.
 *
 *  @return True if the interface is compatible with the node, false otherwise.
 */
static bool fs_check_node_compatibility(const uint16_t                                protocol_id,
                                        const TypesCommonFrameworkTypes1_AbstractNode node_id);
// clang-format off
// CUBE_ADCS_GEN_SECTION_START::CONST_DATA
static const fs_param_sizes_t commonframework1_param_sizes[20] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCommonFramework1_Reset), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_setReset
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCommonFramework1_UnixTime), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_setUnixTime
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCommonFramework1_ErrorLogIndex), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_setErrorLogIndex
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCommonFramework1_ErrorLogEntry), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_setErrorLogEntry
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_setErrorLogClear
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCommonFramework1_ErrorLogSettings), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_setErrorLogSettings
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_setConfigPersist
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCommonFramework1_Identification) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_getIdentification
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCommonFramework1_SerialNumber) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_getSerialNumber
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCommonFramework1_ErrorLogIndex) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_getErrorLogIndex
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCommonFramework1_ErrorLogEntry) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_getErrorLogEntry
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCommonFramework1_ErrorLogSettings) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_getErrorLogSettings
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCommonFramework1_UnixTime) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_getUnixTime
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCommonFramework1_ConfigPersistDiagnostics) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_getConfigPersistDiagnostics
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCommonFramework1_CommsStatus) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_getCommsStatus
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCommonFramework1_Version) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_getVersion
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCommonFramework1_BootStatus) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_getBootStatus
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCommonFramework1_TelecommandAcknowledge) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_getTelecommandAcknowledge
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCommonFramework1_CommonErrorCodes) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_getCommonErrorCodes
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCommonFramework1_Identification2) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonFramework1_getIdentification2
};

static const fs_param_sizes_t commontransfer1_param_sizes[4] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCommonTransfer1_TransferFrame), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonTransfer1_setTransferFrame
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCommonTransfer1_Frame), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonTransfer1_setFrame
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCommonTransfer1_FrameInfo) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonTransfer1_getFrameInfo
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCommonTransfer1_Frame) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CommonTransfer1_getFrame
};

static const fs_param_sizes_t cubeaurigacontrolprogram1_param_sizes[14] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeAurigaControlProgram1_OhPowerStates), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeAurigaControlProgram1_setOhPowerStates
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeAurigaControlProgram1_setRtcSync
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeAurigaControlProgram1_Configuration), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeAurigaControlProgram1_setConfiguration
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeAurigaControlProgram1_AurigaSelfTest), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeAurigaControlProgram1_setAurigaSelfTest
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeAurigaControlProgram1_ExtMemTest), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeAurigaControlProgram1_setExtMemTest
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeAurigaControlProgram1_SpwTest), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeAurigaControlProgram1_setSpwTest
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeAurigaControlProgram1_OhPowerStates) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeAurigaControlProgram1_getOhPowerStates
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeAurigaControlProgram1_HealthTlm) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeAurigaControlProgram1_getHealthTlm
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeAurigaControlProgram1_AurigaStatus) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeAurigaControlProgram1_getAurigaStatus
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeAurigaControlProgram1_AurigaAttitudeData) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeAurigaControlProgram1_getAurigaAttitudeData
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeAurigaControlProgram1_Configuration) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeAurigaControlProgram1_getConfiguration
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeAurigaControlProgram1_AurigaSelfTestResults) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeAurigaControlProgram1_getAurigaSelfTestResults
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeAurigaControlProgram1_ExtMemTestResult) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeAurigaControlProgram1_getExtMemTestResult
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeAurigaControlProgram1_SpwTestResult) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeAurigaControlProgram1_getSpwTestResult
};

static const fs_param_sizes_t cubecommonbasebootloader6_param_sizes[30] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeCommonBaseBootloader6_EccSim), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader6_setEccSim
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeCommonBaseBootloader6_Warnings) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader6_getWarnings
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeCommonBaseBootloader5_Reset), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_setReset
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_setHalt
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeCommonBaseBootloader5_Config), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_setConfig
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeCommonBaseBootloader5_DefaultAppTarget), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_setDefaultAppTarget
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_setJumpToDefaultApp
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeCommonBaseBootloader5_JumpToApp), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_setJumpToApp
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeCommonBaseBootloader5_JumpToAddress), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_setJumpToAddress
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_setResetFileInfoIdx
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeCommonBaseBootloader5_WriteFileSetup), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_setWriteFileSetup
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeCommonBaseBootloader5_DeleteFileEntry), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_setDeleteFileEntry
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeCommonBaseBootloader5_WriteMemorySetup), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_setWriteMemorySetup
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeCommonBaseBootloader5_ReadMemorySetup), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_setReadMemorySetup
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeCommonBaseBootloader5_EraseMemorySetup), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_setEraseMemorySetup
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeCommonBaseBootloader5_OptionBytes), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_setOptionBytes
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeCommonBaseBootloader5_CommitOptionBytes), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_setCommitOptionBytes
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeCommonBaseBootloader5_OptionBytesF7), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_setOptionBytesF7
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeCommonBaseBootloader5_Identification) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_getIdentification
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeCommonBaseBootloader5_SerialNumber) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_getSerialNumber
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeCommonBaseBootloader5_Config) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_getConfig
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeCommonBaseBootloader5_State) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_getState
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeCommonBaseBootloader5_Errors) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_getErrors
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeCommonBaseBootloader5_FileInfo) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_getFileInfo
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeCommonBaseBootloader5_DefaultAppTarget) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_getDefaultAppTarget
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeCommonBaseBootloader5_OptionBytes) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_getOptionBytes
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeCommonBaseBootloader5_CommsStatus) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_getCommsStatus
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeCommonBaseBootloader5_MemMap) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_getMemMap
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeCommonBaseBootloader5_OptionBytesF7) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_getOptionBytesF7
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeCommonBaseBootloader5_TelecommandAcknowledge) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeCommonBaseBootloader5_getTelecommandAcknowledge
};

static const fs_param_sizes_t cubecomputercontrolprogram8_param_sizes[104] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_ConfigDefaultModes), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setConfigDefaultModes
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_ConfigMount), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMount
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_ConfigMag0OrbitCal), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMag0OrbitCal
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_ConfigMag1OrbitCal), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMag1OrbitCal
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_ConfigAdcsController), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAdcsController
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_ConfigAdcsEstimator), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAdcsEstimator
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_ConfigAdcsSatellite), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAdcsSatellite
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_ConfigOrbitSatParams), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setConfigOrbitSatParams
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_ConfigOrbitTargetParams), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setConfigOrbitTargetParams
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_ConfigNodeSelection), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setConfigNodeSelection
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_ConfigActuatorRwl), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setConfigActuatorRwl
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_ConfigActuatorMtq), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setConfigActuatorMtq
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_ConfigMagSensingElement), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMagSensingElement
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_ConfigAsgp4), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAsgp4
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_ConMode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setConMode
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_EstMode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setEstMode
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_OrbMode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setOrbMode
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_AdcsRunMode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setAdcsRunMode
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_AdcsOpState), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setAdcsOpState
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_SimSensorRaw), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setSimSensorRaw
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_OpenLoopCommandMtq), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setOpenLoopCommandMtq
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_OpenLoopCommandRwl), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setOpenLoopCommandRwl
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_OpenLoopCommandHxyzRW), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setOpenLoopCommandHxyzRW
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_ReferenceRpy), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceRpy
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_ReferenceTarget), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceTarget
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_ReferenceIrcVector), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceIrcVector
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_ReferenceFmcParam), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceFmcParam
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_DeployCommandMag), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setDeployCommandMag
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_GnssSensorCmd), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setGnssSensorCmd
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerControlProgram8_FileTransferSetup), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_setFileTransferSetup
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_ConfigDefaultModes) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getConfigDefaultModes
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_ConfigMount) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMount
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_ConfigMag0OrbitCal) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMag0OrbitCal
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_ConfigMag1OrbitCal) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMag1OrbitCal
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_ConfigAdcsController) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAdcsController
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_ConfigAdcsEstimator) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAdcsEstimator
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_ConfigAdcsSatellite) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAdcsSatellite
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_ConfigOrbitSatParams) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getConfigOrbitSatParams
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_ConfigOrbitTargetParams) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getConfigOrbitTargetParams
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_ConfigNodeSelection) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getConfigNodeSelection
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_ConfigActuatorRwl) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getConfigActuatorRwl
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_ConfigActuatorMtq) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getConfigActuatorMtq
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_ConfigMagSensingElement) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMagSensingElement
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_ConfigAsgp4) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAsgp4
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_ConMode) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getConMode
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_EstMode) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getEstMode
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_OrbMode) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getOrbMode
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_AdcsRunMode) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getAdcsRunMode
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_AdcsOpState) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getAdcsOpState
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_SimSensorRaw) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getSimSensorRaw
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_OpenLoopCommandMtq) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getOpenLoopCommandMtq
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_OpenLoopCommandRwl) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getOpenLoopCommandRwl
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_OpenLoopCommandHxyzRW) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getOpenLoopCommandHxyzRW
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_ReferenceRpy) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceRpy
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_ReferenceTarget) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceTarget
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_ReferenceIrcVector) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceIrcVector
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_ReferenceFmcParam) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceFmcParam
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_CubeNodePortMap) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getCubeNodePortMap
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmHil) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmHil
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmExecutionPoint) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmExecutionPoint
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmAsgp4) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmAsgp4
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmNodeInitState) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmNodeInitState
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmLitefuforsHealth) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmLitefuforsHealth
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_FileTransferSetup) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getFileTransferSetup
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_FileTransferStatus) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getFileTransferStatus
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_FileInfo) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getFileInfo
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmSensorRawCss) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawCss
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmSensorRawMag) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawMag
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmSensorRawGyro) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawGyro
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmSensorRawRwl) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawRwl
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmSensorCalFss) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalFss
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmSensorCalCss) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalCss
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmSensorCalMag) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalMag
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmSensorCalGyro) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalGyro
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmSensorCalHss) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalHss
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmSensorCalStr) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalStr
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmSensorCalGnss) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalGnss
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmSensorCalRwl) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalRwl
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmModels) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmModels
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmEstimatorMain) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmEstimatorMain
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmEstimatorBackup) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmEstimatorBackup
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmEstimatorMainHighRes) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmEstimatorMainHighRes
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmController) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmController
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmGnssRaw) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmGnssRaw
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmExtSensorRaw) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmExtSensorRaw
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmStrPst3sRaw) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrPst3sRaw
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmFssCubeSenseSunRaw) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmFssCubeSenseSunRaw
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmHssCubeSenseEarthRaw) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmHssCubeSenseEarthRaw
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmRwlNssRwlRaw) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmRwlNssRwlRaw
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmStrCubeStarRaw) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrCubeStarRaw
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmGyrLitefuforsRaw) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmGyrLitefuforsRaw
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmStrCubeAurigaRaw) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrCubeAurigaRaw
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmAcpExecution) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmAcpExecution
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmTorquerCurrents) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmTorquerCurrents
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmCubeComputerHealth) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmCubeComputerHealth
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmFssCubeSenseSunHealth) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmFssCubeSenseSunHealth
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmHssCubeSenseEarthHealth) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmHssCubeSenseEarthHealth
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmCubeMagHealth) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmCubeMagHealth
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmRwlHealth) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmRwlHealth
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmStrPst3sHealth) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrPst3sHealth
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmNssRwlHealth) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmNssRwlHealth
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmStrHealth) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrHealth
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmGnssUartStatus) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmGnssUartStatus
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerControlProgram8_TlmStrAurigaHealth) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrAurigaHealth
};

static const fs_param_sizes_t cubecomputercommon3_param_sizes[24] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerCommon3_PassThrough), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_setPassThrough
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerCommon3_PowerState), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_setPowerState
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerCommon3_ImageTransferSetup), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_setImageTransferSetup
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_setImageFileInfoReset
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerCommon3_PortMap), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_setPortMap
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerCommon3_EraseLogData), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_setEraseLogData
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerCommon3_EventLogFilterTransferSetup), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_setEventLogFilterTransferSetup
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerCommon3_TelemetryLogTransferSetup), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_setTelemetryLogTransferSetup
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerCommon3_DummyEvent), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_setDummyEvent
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerCommon3_UnsolicitedEventSetup), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_setUnsolicitedEventSetup
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeComputerCommon3_UnsolicitedTlmSetup), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_setUnsolicitedTlmSetup
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerCommon3_PassThrough) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_getPassThrough
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerCommon3_PowerState) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_getPowerState
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerCommon3_PortDiagnostics) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_getPortDiagnostics
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerCommon3_PortMap) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_getPortMap
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerCommon3_ExpectedNodes) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_getExpectedNodes
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerCommon3_ImageTransferStatus) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_getImageTransferStatus
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerCommon3_ImageFileInfo) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_getImageFileInfo
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerCommon3_ComponentErrorCodes) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_getComponentErrorCodes
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerCommon3_EventLogStatus) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_getEventLogStatus
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerCommon3_TelemtryLogStatus) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_getTelemtryLogStatus
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerCommon3_UnsolicitedEventSetup) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_getUnsolicitedEventSetup
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerCommon3_UnsolicitedTlmSetup) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_getUnsolicitedTlmSetup
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeComputerCommon3_TelemtryLogInclusionMasks) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeComputerCommon3_getTelemtryLogInclusionMasks
};

static const fs_param_sizes_t cubeircontrolprogram1_param_sizes[11] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeIrControlProgram1_Configuration), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeIrControlProgram1_setConfiguration
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeIrControlProgram1_ImageTransferSetup), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeIrControlProgram1_setImageTransferSetup
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeIrControlProgram1_DeadPixels), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeIrControlProgram1_setDeadPixels
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeIrControlProgram1_RequestDeadPixel), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeIrControlProgram1_setRequestDeadPixel
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeIrControlProgram1_MeasurementAndTrigger) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeIrControlProgram1_getMeasurementAndTrigger
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeIrControlProgram1_Measurement) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeIrControlProgram1_getMeasurement
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeIrControlProgram1_MeasurementMetadata) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeIrControlProgram1_getMeasurementMetadata
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeIrControlProgram1_HealthTlm) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeIrControlProgram1_getHealthTlm
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeIrControlProgram1_Configuration) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeIrControlProgram1_getConfiguration
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeIrControlProgram1_ProfileTiming) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeIrControlProgram1_getProfileTiming
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeIrControlProgram1_RequestedDeadPixel) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeIrControlProgram1_getRequestedDeadPixel
};

static const fs_param_sizes_t cubemagcontrolprogramcommon1_param_sizes[12] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeMagControlProgramCommon1_MmcConfig), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramCommon1_setMmcConfig
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramCommon1_setSamplePrimary
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeMagControlProgramCommon1_Config), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramCommon1_setConfig
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeMagControlProgramCommon1_MmcCalibration), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramCommon1_setMmcCalibration
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeMagControlProgramCommon1_MmcConfig) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramCommon1_getMmcConfig
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeMagControlProgramCommon1_State) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramCommon1_getState
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeMagControlProgramCommon1_PrimaryMagMeasurement) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagMeasurement
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeMagControlProgramCommon1_PrimaryMagMeasurementRaw) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagMeasurementRaw
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeMagControlProgramCommon1_PrimaryMagTemp) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagTemp
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeMagControlProgramCommon1_Config) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramCommon1_getConfig
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeMagControlProgramCommon1_PrimaryMagDiagnostics) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagDiagnostics
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeMagControlProgramCommon1_MmcCalibration) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramCommon1_getMmcCalibration
};

static const fs_param_sizes_t cubemagcontrolprogramcompact1_param_sizes[1] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeMagControlProgramCompact1_HealthTlm) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramCompact1_getHealthTlm
};

static const fs_param_sizes_t cubemagcontrolprogramdeploy1_param_sizes[13] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeMagControlProgramDeploy1_PniConfig), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramDeploy1_setPniConfig
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramDeploy1_setSampleRed
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeMagControlProgramDeploy1_Deploy), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramDeploy1_setDeploy
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeMagControlProgramDeploy1_DeployArm), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramDeploy1_setDeployArm
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeMagControlProgramDeploy1_PniCalibration), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramDeploy1_setPniCalibration
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeMagControlProgramDeploy1_HealthTlm) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramDeploy1_getHealthTlm
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeMagControlProgramDeploy1_PniConfig) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramDeploy1_getPniConfig
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeMagControlProgramDeploy1_RedMagMeasurement) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagMeasurement
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeMagControlProgramDeploy1_RedMagMeasurementRaw) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagMeasurementRaw
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeMagControlProgramDeploy1_RedMagTemp) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagTemp
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeMagControlProgramDeploy1_DeploymentStatus) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramDeploy1_getDeploymentStatus
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeMagControlProgramDeploy1_RedMagDiagnostics) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagDiagnostics
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeMagControlProgramDeploy1_PniCalibration) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeMagControlProgramDeploy1_getPniCalibration
};

static const fs_param_sizes_t cubenodecontrolprogramlitefufors1_param_sizes[12] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramLitefufors1_UforsPower), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_setUforsPower
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramLitefufors1_NodeSvcSettings), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_setNodeSvcSettings
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramLitefufors1_UforsSvcSettings), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_setUforsSvcSettings
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramLitefufors1_NodeSvcSettings) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getNodeSvcSettings
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramLitefufors1_UforsSvcSettings) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsSvcSettings
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramLitefufors1_NodeSvcStatus) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getNodeSvcStatus
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramLitefufors1_UforsSvcStatus) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsSvcStatus
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramLitefufors1_UforsTlm) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlm
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramLitefufors1_UforsTlmPort1) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort1
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramLitefufors1_UforsTlmPort2) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort2
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramLitefufors1_UforsTlmPort3) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort3
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramLitefufors1_UforsTlmPort4) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort4
};

static const fs_param_sizes_t cubenodecontrolprogramnssrwlcommon1_param_sizes[16] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NodeSvcSettings), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNodeSvcSettings
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlSvcSettings), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlSvcSettings
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlPower), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlPower
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlWheelSpeedRef), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlWheelSpeedRef
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlTorque), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlTorque
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlMotorCurrent), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlMotorCurrent
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlSoftwareReset), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlSoftwareReset
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NodeSvcSettings) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNodeSvcSettings
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NodeSvcStatus) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNodeSvcStatus
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlSvcSettings) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlSvcSettings
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlSvcStatus) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlSvcStatus
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlWheelSpeed1) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlWheelSpeed1
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlTlmStandard1) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlTlmStandard1
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlTlmExtended1) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlTlmExtended1
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlTlmSystem1) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlTlmSystem1
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlWheelSpeedAll) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlWheelSpeedAll
};

static const fs_param_sizes_t cubenodecontrolprogramnssrwlquad1_param_sizes[12] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlWheelSpeed2) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlWheelSpeed2
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlWheelSpeed3) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlWheelSpeed3
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlWheelSpeed4) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlWheelSpeed4
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmStandard2) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmStandard2
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmStandard3) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmStandard3
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmStandard4) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmStandard4
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmExtended2) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmExtended2
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmExtended3) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmExtended3
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmExtended4) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmExtended4
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmSystem2) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmSystem2
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmSystem3) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmSystem3
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmSystem4) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmSystem4
};

static const fs_param_sizes_t cubenodecontrolprogrampst3scommon1_param_sizes[23] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sNumberNavigationStars), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sNumberNavigationStars
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sExposure), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sExposure
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sFSST), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sFSST
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sSecondCalibration), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSecondCalibration
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sTrackingModeThreshold), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sTrackingModeThreshold
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sQuaternionFiltering), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sQuaternionFiltering
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sSystemReset), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSystemReset
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sPower), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sPower
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sImageFixedThreshold), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sImageFixedThreshold
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sSvcSettings), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSvcSettings
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_NodeSvcSettings), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setNodeSvcSettings
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sSaaMode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSaaMode
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sSaaThreshold), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSaaThreshold
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sDynamicMode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sDynamicMode
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sEdacOff), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sEdacOff
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sSvcStatus) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sSvcStatus
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sTlm1) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sTlm1
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sAttitude1) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sAttitude1
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sHousekeeping1) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sHousekeeping1
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sConfig1) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sConfig1
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sSvcSettings) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sSvcSettings
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sCommon1_NodeSvcStatus) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getNodeSvcStatus
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sCommon1_NodeSvcSettings) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getNodeSvcSettings
};

static const fs_param_sizes_t cubenodecontrolprogrampst3squad1_param_sizes[12] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sTlm2) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sTlm2
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sTlm3) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sTlm3
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sTlm4) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sTlm4
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sAttitude2) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sAttitude2
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sAttitude3) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sAttitude3
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sAttitude4) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sAttitude4
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sHousekeeping2) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sHousekeeping2
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sHousekeeping3) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sHousekeeping3
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sHousekeeping4) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sHousekeeping4
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sConfig2) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sConfig2
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sConfig3) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sConfig3
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sConfig4) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sConfig4
};

static const fs_param_sizes_t cubenodecommon1_param_sizes[4] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeNodeCommon1_PowerSwitchState), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeCommon1_setPowerSwitchState
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeCommon1_HealthTlm) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeCommon1_getHealthTlm
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeCommon1_PowerSwitchState) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeCommon1_getPowerSwitchState
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeNodeCommon1_NodeModel) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeNodeCommon1_getNodeModel
};

static const fs_param_sizes_t cubesensecontrolprogram5_param_sizes[18] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeSenseControlProgram5_CamLensDistortion), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseControlProgram5_setCamLensDistortion
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseControlProgram5_setCaptureDetect
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseControlProgram5_setDetect
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseControlProgram5_setClearOvercurrentFlags
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeSenseControlProgram5_ImageCapture), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseControlProgram5_setImageCapture
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeSenseControlProgram5_ImageTransferSetup), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseControlProgram5_setImageTransferSetup
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeSenseControlProgram5_CamBoresight), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseControlProgram5_setCamBoresight
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeSenseControlProgram5_CamMask), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseControlProgram5_setCamMask
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeSenseControlProgram5_CamThreshold), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseControlProgram5_setCamThreshold
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeSenseControlProgram5_DetectionAreaRowSelect), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseControlProgram5_setDetectionAreaRowSelect
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeSenseControlProgram5_SensorResultsTimestamp) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseControlProgram5_getSensorResultsTimestamp
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeSenseControlProgram5_CamLensDistortion) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseControlProgram5_getCamLensDistortion
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeSenseControlProgram5_CamMasks) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseControlProgram5_getCamMasks
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeSenseControlProgram5_SensorResults) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseControlProgram5_getSensorResults
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeSenseControlProgram5_SensorResultTrigger) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseControlProgram5_getSensorResultTrigger
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeSenseControlProgram5_AutoCamSensorRaw) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseControlProgram5_getAutoCamSensorRaw
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeSenseControlProgram5_DetectionAreaRow) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseControlProgram5_getDetectionAreaRow
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeSenseControlProgram5_CamBoresight) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseControlProgram5_getCamBoresight
};

static const fs_param_sizes_t cubesensecommon1_param_sizes[4] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeSenseCommon1_CamAutoAdjust), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseCommon1_setCamAutoAdjust
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeSenseCommon1_CamSettings), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseCommon1_setCamSettings
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeSenseCommon1_Config) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseCommon1_getConfig
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeSenseCommon1_HealthTlm) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeSenseCommon1_getHealthTlm
};

static const fs_param_sizes_t cubestarcontrolprogram6_param_sizes[20] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeStarControlProgram6_CaptureDetect), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_setCaptureDetect
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_setCaptureOnly
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_setDetectIdOnly
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeStarControlProgram6_LensDistortion), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_setLensDistortion
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeStarControlProgram6_DetectionSettings), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_setDetectionSettings
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeStarControlProgram6_SensorSettings), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_setSensorSettings
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeStarControlProgram6_ImageTransferSetup), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_setImageTransferSetup
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeStarControlProgram6_SensorRegisterRead), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_setSensorRegisterRead
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeStarControlProgram6_SensorRegisterWrite), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_setSensorRegisterWrite
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeStarControlProgram6_SubsystemPower), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_setSubsystemPower
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeStarControlProgram6_LensDistortion) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_getLensDistortion
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeStarControlProgram6_DetectionSettings) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_getDetectionSettings
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeStarControlProgram6_SensorSettings) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_getSensorSettings
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeStarControlProgram6_Status) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_getStatus
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeStarControlProgram6_DetectionMetaData) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_getDetectionMetaData
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeStarControlProgram6_DetectedStars) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_getDetectedStars
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeStarControlProgram6_HealthTlm) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_getHealthTlm
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeStarControlProgram6_SensorRegisterValue) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_getSensorRegisterValue
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeStarControlProgram6_BestStars) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_getBestStars
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeStarControlProgram6_Attitude) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeStarControlProgram6_getAttitude
};

static const fs_param_sizes_t cubewheelcontrolprogram3_param_sizes[28] = {
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeWheelControlProgram3_WheelSpeedRef), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_setWheelSpeedRef
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeWheelControlProgram3_WheelTorqueRef), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_setWheelTorqueRef
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeWheelControlProgram3_WheelTravelRef), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_setWheelTravelRef
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeWheelControlProgram3_WheelRefRampRateLimit), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_setWheelRefRampRateLimit
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeWheelControlProgram3_BackupWheelMode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_setBackupWheelMode
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_setClearErrors
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeWheelControlProgram3_MainGain), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_setMainGain
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeWheelControlProgram3_BackupGain), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_setBackupGain
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeWheelControlProgram3_PWMGain), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_setPWMGain
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode) + sizeof(TypesCubeWheelControlProgram3_MotorPower), sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_setMotorPower
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeWheelControlProgram3_WheelRefRampRateLimit) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_getWheelRefRampRateLimit
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeWheelControlProgram3_Stator) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_getStator
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeWheelControlProgram3_WheelTorque) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_getWheelTorque
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeWheelControlProgram3_BackupGain) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_getBackupGain
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeWheelControlProgram3_MainGain) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_getMainGain
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeWheelControlProgram3_PWMGain) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_getPWMGain
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeWheelControlProgram3_StatusErrorFlags) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_getStatusErrorFlags
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeWheelControlProgram3_WheelData) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_getWheelData
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeWheelControlProgram3_WheelDuty) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_getWheelDuty
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeWheelControlProgram3_HealthTlm) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_getHealthTlm
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeWheelControlProgram3_WheelSpeedRef) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_getWheelSpeedRef
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeWheelControlProgram3_WheelTorqueRef) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_getWheelTorqueRef
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeWheelControlProgram3_WheelSpeed) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_getWheelSpeed
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeWheelControlProgram3_MotorPower) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_getMotorPower
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeWheelControlProgram3_ControlMode) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_getControlMode
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeWheelControlProgram3_BackupWheelMode) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_getBackupWheelMode
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeWheelControlProgram3_WheelModel) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_getWheelModel
    {sizeof(TypesCommonFrameworkTypes1_AbstractNode), sizeof(TypesCubeWheelControlProgram3_WheelPosData) + sizeof(ErrorCode)}, //  CubeADCS_Gen2_CubeWheelControlProgram3_getWheelPosData
};

static const fs_iface_cmds_t fs_iface_commands[20] = {
    {commonframework1_param_sizes, 20},
    {commontransfer1_param_sizes, 4},
    {cubeaurigacontrolprogram1_param_sizes, 14},
    {cubecommonbasebootloader6_param_sizes, 30},
    {cubecomputercontrolprogram8_param_sizes, 104},
    {cubecomputercommon3_param_sizes, 24},
    {cubeircontrolprogram1_param_sizes, 11},
    {cubemagcontrolprogramcommon1_param_sizes, 12},
    {cubemagcontrolprogramcompact1_param_sizes, 1},
    {cubemagcontrolprogramdeploy1_param_sizes, 13},
    {cubenodecontrolprogramlitefufors1_param_sizes, 12},
    {cubenodecontrolprogramnssrwlcommon1_param_sizes, 16},
    {cubenodecontrolprogramnssrwlquad1_param_sizes, 12},
    {cubenodecontrolprogrampst3scommon1_param_sizes, 23},
    {cubenodecontrolprogrampst3squad1_param_sizes, 12},
    {cubenodecommon1_param_sizes, 4},
    {cubesensecontrolprogram5_param_sizes, 18},
    {cubesensecommon1_param_sizes, 4},
    {cubestarcontrolprogram6_param_sizes, 20},
    {cubewheelcontrolprogram3_param_sizes, 28},
};

static const p_gen2_srv_api_t fs_invoke_commonframework1_method[20] = {
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_setReset,
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_setUnixTime,
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_setErrorLogIndex,
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_setErrorLogEntry,
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_setErrorLogClear,
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_setErrorLogSettings,
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_setConfigPersist,
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getIdentification,
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getSerialNumber,
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getErrorLogIndex,
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getErrorLogEntry,
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getErrorLogSettings,
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getUnixTime,
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getConfigPersistDiagnostics,
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getCommsStatus,
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getVersion,
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getBootStatus,
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getTelecommandAcknowledge,
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getCommonErrorCodes,
    CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getIdentification2,
};

static const p_gen2_srv_api_t fs_invoke_commontransfer1_method[4] = {
    CPCmdHandler_CubeADCS_Gen2_CommonTransfer1_setTransferFrame,
    CPCmdHandler_CubeADCS_Gen2_CommonTransfer1_setFrame,
    CPCmdHandler_CubeADCS_Gen2_CommonTransfer1_getFrameInfo,
    CPCmdHandler_CubeADCS_Gen2_CommonTransfer1_getFrame,
};

static const p_gen2_srv_api_t fs_invoke_cubeaurigacontrolprogram1_method[14] = {
    CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_setOhPowerStates,
    CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_setRtcSync,
    CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_setConfiguration,
    CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_setAurigaSelfTest,
    CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_setExtMemTest,
    CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_setSpwTest,
    CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_getOhPowerStates,
    CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_getHealthTlm,
    CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_getAurigaStatus,
    CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_getAurigaAttitudeData,
    CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_getConfiguration,
    CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_getAurigaSelfTestResults,
    CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_getExtMemTestResult,
    CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_getSpwTestResult,
};

static const p_gen2_srv_api_t fs_invoke_cubecommonbasebootloader6_method[30] = {
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader6_setEccSim,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader6_getWarnings,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setReset,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setHalt,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setConfig,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setDefaultAppTarget,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setJumpToDefaultApp,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setJumpToApp,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setJumpToAddress,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setResetFileInfoIdx,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setWriteFileSetup,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setDeleteFileEntry,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setWriteMemorySetup,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setReadMemorySetup,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setEraseMemorySetup,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setOptionBytes,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setCommitOptionBytes,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setOptionBytesF7,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getIdentification,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getSerialNumber,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getConfig,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getState,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getErrors,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getFileInfo,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getDefaultAppTarget,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getOptionBytes,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getCommsStatus,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getMemMap,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getOptionBytesF7,
    CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getTelecommandAcknowledge,
};

static const p_gen2_srv_api_t fs_invoke_cubecomputercontrolprogram8_method[104] = {
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigDefaultModes,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMount,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMag0OrbitCal,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMag1OrbitCal,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAdcsController,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAdcsEstimator,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAdcsSatellite,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigOrbitSatParams,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigOrbitTargetParams,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigNodeSelection,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigActuatorRwl,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigActuatorMtq,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMagSensingElement,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAsgp4,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConMode,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setEstMode,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setOrbMode,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setAdcsRunMode,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setAdcsOpState,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setSimSensorRaw,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setOpenLoopCommandMtq,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setOpenLoopCommandRwl,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setOpenLoopCommandHxyzRW,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceRpy,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceTarget,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceIrcVector,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceFmcParam,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setDeployCommandMag,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setGnssSensorCmd,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setFileTransferSetup,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigDefaultModes,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMount,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMag0OrbitCal,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMag1OrbitCal,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAdcsController,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAdcsEstimator,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAdcsSatellite,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigOrbitSatParams,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigOrbitTargetParams,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigNodeSelection,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigActuatorRwl,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigActuatorMtq,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMagSensingElement,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAsgp4,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConMode,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getEstMode,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getOrbMode,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getAdcsRunMode,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getAdcsOpState,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getSimSensorRaw,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getOpenLoopCommandMtq,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getOpenLoopCommandRwl,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getOpenLoopCommandHxyzRW,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceRpy,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceTarget,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceIrcVector,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceFmcParam,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getCubeNodePortMap,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmHil,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmExecutionPoint,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmAsgp4,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmNodeInitState,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmLitefuforsHealth,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getFileTransferSetup,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getFileTransferStatus,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getFileInfo,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawCss,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawMag,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawGyro,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawRwl,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalFss,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalCss,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalMag,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalGyro,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalHss,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalStr,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalGnss,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalRwl,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmModels,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmEstimatorMain,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmEstimatorBackup,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmEstimatorMainHighRes,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmController,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmGnssRaw,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmExtSensorRaw,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrPst3sRaw,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmFssCubeSenseSunRaw,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmHssCubeSenseEarthRaw,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmRwlNssRwlRaw,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrCubeStarRaw,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmGyrLitefuforsRaw,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrCubeAurigaRaw,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmAcpExecution,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmTorquerCurrents,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmCubeComputerHealth,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmFssCubeSenseSunHealth,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmHssCubeSenseEarthHealth,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmCubeMagHealth,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmRwlHealth,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrPst3sHealth,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmNssRwlHealth,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrHealth,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmGnssUartStatus,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrAurigaHealth,
};

static const p_gen2_srv_api_t fs_invoke_cubecomputercommon3_method[24] = {
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setPassThrough,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setPowerState,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setImageTransferSetup,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setImageFileInfoReset,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setPortMap,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setEraseLogData,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setEventLogFilterTransferSetup,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setTelemetryLogTransferSetup,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setDummyEvent,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setUnsolicitedEventSetup,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setUnsolicitedTlmSetup,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getPassThrough,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getPowerState,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getPortDiagnostics,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getPortMap,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getExpectedNodes,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getImageTransferStatus,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getImageFileInfo,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getComponentErrorCodes,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getEventLogStatus,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getTelemtryLogStatus,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getUnsolicitedEventSetup,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getUnsolicitedTlmSetup,
    CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getTelemtryLogInclusionMasks,
};

static const p_gen2_srv_api_t fs_invoke_cubeircontrolprogram1_method[11] = {
    CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_setConfiguration,
    CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_setImageTransferSetup,
    CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_setDeadPixels,
    CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_setRequestDeadPixel,
    CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_getMeasurementAndTrigger,
    CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_getMeasurement,
    CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_getMeasurementMetadata,
    CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_getHealthTlm,
    CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_getConfiguration,
    CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_getProfileTiming,
    CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_getRequestedDeadPixel,
};

static const p_gen2_srv_api_t fs_invoke_cubemagcontrolprogramcommon1_method[12] = {
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_setMmcConfig,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_setSamplePrimary,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_setConfig,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_setMmcCalibration,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_getMmcConfig,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_getState,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagMeasurement,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagMeasurementRaw,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagTemp,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_getConfig,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagDiagnostics,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_getMmcCalibration,
};

static const p_gen2_srv_api_t fs_invoke_cubemagcontrolprogramcompact1_method[1] = {
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCompact1_getHealthTlm,
};

static const p_gen2_srv_api_t fs_invoke_cubemagcontrolprogramdeploy1_method[13] = {
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_setPniConfig,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_setSampleRed,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_setDeploy,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_setDeployArm,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_setPniCalibration,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_getHealthTlm,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_getPniConfig,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagMeasurement,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagMeasurementRaw,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagTemp,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_getDeploymentStatus,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagDiagnostics,
    CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_getPniCalibration,
};

static const p_gen2_srv_api_t fs_invoke_cubenodecontrolprogramlitefufors1_method[12] = {
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_setUforsPower,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_setNodeSvcSettings,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_setUforsSvcSettings,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getNodeSvcSettings,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsSvcSettings,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getNodeSvcStatus,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsSvcStatus,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlm,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort1,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort2,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort3,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort4,
};

static const p_gen2_srv_api_t fs_invoke_cubenodecontrolprogramnssrwlcommon1_method[16] = {
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNodeSvcSettings,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlSvcSettings,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlPower,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlWheelSpeedRef,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlTorque,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlMotorCurrent,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlSoftwareReset,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNodeSvcSettings,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNodeSvcStatus,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlSvcSettings,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlSvcStatus,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlWheelSpeed1,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlTlmStandard1,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlTlmExtended1,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlTlmSystem1,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlWheelSpeedAll,
};

static const p_gen2_srv_api_t fs_invoke_cubenodecontrolprogramnssrwlquad1_method[12] = {
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlWheelSpeed2,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlWheelSpeed3,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlWheelSpeed4,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmStandard2,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmStandard3,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmStandard4,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmExtended2,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmExtended3,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmExtended4,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmSystem2,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmSystem3,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmSystem4,
};

static const p_gen2_srv_api_t fs_invoke_cubenodecontrolprogrampst3scommon1_method[23] = {
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sNumberNavigationStars,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sExposure,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sFSST,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSecondCalibration,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sTrackingModeThreshold,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sQuaternionFiltering,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSystemReset,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sPower,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sImageFixedThreshold,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSvcSettings,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setNodeSvcSettings,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSaaMode,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSaaThreshold,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sDynamicMode,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sEdacOff,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sSvcStatus,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sTlm1,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sAttitude1,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sHousekeeping1,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sConfig1,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sSvcSettings,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getNodeSvcStatus,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getNodeSvcSettings,
};

static const p_gen2_srv_api_t fs_invoke_cubenodecontrolprogrampst3squad1_method[12] = {
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sTlm2,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sTlm3,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sTlm4,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sAttitude2,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sAttitude3,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sAttitude4,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sHousekeeping2,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sHousekeeping3,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sHousekeeping4,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sConfig2,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sConfig3,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sConfig4,
};

static const p_gen2_srv_api_t fs_invoke_cubenodecommon1_method[4] = {
    CPCmdHandler_CubeADCS_Gen2_CubeNodeCommon1_setPowerSwitchState,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeCommon1_getHealthTlm,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeCommon1_getPowerSwitchState,
    CPCmdHandler_CubeADCS_Gen2_CubeNodeCommon1_getNodeModel,
};

static const p_gen2_srv_api_t fs_invoke_cubesensecontrolprogram5_method[18] = {
    CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setCamLensDistortion,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setCaptureDetect,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setDetect,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setClearOvercurrentFlags,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setImageCapture,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setImageTransferSetup,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setCamBoresight,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setCamMask,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setCamThreshold,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setDetectionAreaRowSelect,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_getSensorResultsTimestamp,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_getCamLensDistortion,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_getCamMasks,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_getSensorResults,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_getSensorResultTrigger,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_getAutoCamSensorRaw,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_getDetectionAreaRow,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_getCamBoresight,
};

static const p_gen2_srv_api_t fs_invoke_cubesensecommon1_method[4] = {
    CPCmdHandler_CubeADCS_Gen2_CubeSenseCommon1_setCamAutoAdjust,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseCommon1_setCamSettings,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseCommon1_getConfig,
    CPCmdHandler_CubeADCS_Gen2_CubeSenseCommon1_getHealthTlm,
};

static const p_gen2_srv_api_t fs_invoke_cubestarcontrolprogram6_method[20] = {
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setCaptureDetect,
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setCaptureOnly,
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setDetectIdOnly,
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setLensDistortion,
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setDetectionSettings,
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setSensorSettings,
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setImageTransferSetup,
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setSensorRegisterRead,
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setSensorRegisterWrite,
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setSubsystemPower,
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getLensDistortion,
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getDetectionSettings,
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getSensorSettings,
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getStatus,
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getDetectionMetaData,
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getDetectedStars,
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getHealthTlm,
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getSensorRegisterValue,
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getBestStars,
    CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getAttitude,
};

static const p_gen2_srv_api_t fs_invoke_cubewheelcontrolprogram3_method[28] = {
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setWheelSpeedRef,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setWheelTorqueRef,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setWheelTravelRef,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setWheelRefRampRateLimit,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setBackupWheelMode,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setClearErrors,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setMainGain,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setBackupGain,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setPWMGain,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setMotorPower,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getWheelRefRampRateLimit,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getStator,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getWheelTorque,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getBackupGain,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getMainGain,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getPWMGain,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getStatusErrorFlags,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getWheelData,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getWheelDuty,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getHealthTlm,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getWheelSpeedRef,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getWheelTorqueRef,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getWheelSpeed,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getMotorPower,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getControlMode,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getBackupWheelMode,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getWheelModel,
    CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getWheelPosData,
};

static const p_gen2_srv_api_t *fs_invoke_method[20] = {
    fs_invoke_commonframework1_method,
    fs_invoke_commontransfer1_method,
    fs_invoke_cubeaurigacontrolprogram1_method,
    fs_invoke_cubecommonbasebootloader6_method,
    fs_invoke_cubecomputercontrolprogram8_method,
    fs_invoke_cubecomputercommon3_method,
    fs_invoke_cubeircontrolprogram1_method,
    fs_invoke_cubemagcontrolprogramcommon1_method,
    fs_invoke_cubemagcontrolprogramcompact1_method,
    fs_invoke_cubemagcontrolprogramdeploy1_method,
    fs_invoke_cubenodecontrolprogramlitefufors1_method,
    fs_invoke_cubenodecontrolprogramnssrwlcommon1_method,
    fs_invoke_cubenodecontrolprogramnssrwlquad1_method,
    fs_invoke_cubenodecontrolprogrampst3scommon1_method,
    fs_invoke_cubenodecontrolprogrampst3squad1_method,
    fs_invoke_cubenodecommon1_method,
    fs_invoke_cubesensecontrolprogram5_method,
    fs_invoke_cubesensecommon1_method,
    fs_invoke_cubestarcontrolprogram6_method,
    fs_invoke_cubewheelcontrolprogram3_method,
};

static const bool fs_fidl_allowed_for_node_type[20][17] = {
    {true, true, true, true, true, true, true, true, true, false, false, true, true, false, true, true, true},    // CubeADCS_Gen2_CommonFramework1.fidl
    {true, true, true, false, true, false, false, true, false, false, false, false, false, false, false, false, false},    // CubeADCS_Gen2_CommonTransfer1.fidl
    {true, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false},    // CubeADCS_Gen2_CubeAurigaControlProgram1.fidl
    {true, true, true, true, true, true, true, true, true, false, false, true, true, false, true, true, true},    // CubeADCS_Gen2_CubeCommonBaseBootloader6.fidl
    {true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},    // CubeADCS_Gen2_CubeComputerControlProgram8.fidl
    {true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},    // CubeADCS_Gen2_CubeComputerCommon3.fidl
    {true, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false},    // CubeADCS_Gen2_CubeIrControlProgram1.fidl
    {true, false, false, false, false, true, true, false, false, false, false, false, false, false, false, false, false},    // CubeADCS_Gen2_CubeMagControlProgramCommon1.fidl
    {true, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false},    // CubeADCS_Gen2_CubeMagControlProgramCompact1.fidl
    {true, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false},    // CubeADCS_Gen2_CubeMagControlProgramDeploy1.fidl
    {true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true},    // CubeADCS_Gen2_CubeNodeControlProgramLitefufors1.fidl
    {true, false, false, false, false, false, false, false, false, false, false, false, true, false, false, true, false},    // CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1.fidl
    {true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false},    // CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1.fidl
    {true, false, false, false, false, false, false, false, false, false, false, true, false, false, true, false, false},    // CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1.fidl
    {true, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false},    // CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1.fidl
    {true, false, false, false, false, false, false, false, false, false, false, true, true, false, true, true, true},    // CubeADCS_Gen2_CubeNodeCommon1.fidl
    {true, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false},    // CubeADCS_Gen2_CubeSenseControlProgram5.fidl
    {true, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false},    // CubeADCS_Gen2_CubeSenseCommon1.fidl
    {true, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false},    // CubeADCS_Gen2_CubeStarControlProgram6.fidl
    {true, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false},    // CubeADCS_Gen2_CubeWheelControlProgram3.fidl
};

// CUBE_ADCS_GEN_SECTION_END::CONST_DATA
// clang-format on
static uint16_t fs_get_protocol_id(const uint16_t proto_id_raw)
{
    return proto_id_raw >= PROTOCOL_ID_OFFSET ? (uint16_t)(proto_id_raw - PROTOCOL_ID_OFFSET) : PROTOCOL_ID_INVALID;
}

static fs_param_sizes_t fs_get_cmd_sizes(const uint16_t proto_id, const funcIdType_t func_id)
{
    fs_param_sizes_t res = { 0, 0 };

    if ((proto_id <= sizeof(fs_iface_commands) / sizeof(fs_iface_commands[0])) && (func_id < fs_iface_commands[proto_id].num_methods))
    {
        res = fs_iface_commands[proto_id].cmd_sizes[func_id];
    }

    return res;
}

static bool fs_are_sizes_valid(const fs_param_sizes_t *const param_sizes,
                               const uint32_t                cmd_data_size,
                               const uint32_t                resp_buf_size)
{
    bool res = false;

    if ((param_sizes->req_size > 0) && (param_sizes->resp_size > 0) && (cmd_data_size > CMD_PARAMS_OFFSET) && (resp_buf_size > CMD_PARAMS_OFFSET) && (param_sizes->req_size <= cmd_data_size - CMD_PARAMS_OFFSET) && (param_sizes->resp_size <= resp_buf_size - CMD_PARAMS_OFFSET))
    {
        res = true;
    }

    return res;
}

static bool fs_check_node_compatibility(const uint16_t protocol_id, const TypesCommonFrameworkTypes1_AbstractNode node_id)
{
    bool result = false;

    if (protocol_id < CDEF_ELEMENT_COUNT(fs_fidl_allowed_for_node_type))
    {
        if (TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER == node_id)
        {
            // CubeComputer is not present in the expected nodes configuration, but is always present in the system
            result = fs_fidl_allowed_for_node_type[protocol_id][TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_TYPE_CUBE_COMPUTER];
        }
        else
        {
            const TypesCommonFrameworkTypes1_NodeType node_type = cubeadcs_gen2_get_node_type(node_id);
            result                                              = fs_fidl_allowed_for_node_type[protocol_id][node_type];
        }
    }

    return result;
}

eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_GwSendCmd(sCPDispatchContext_t *const psDispCtx)
{
    eCPDispatchResult_t res = ECPDISPATCHRESULT_ERROR;

    if ((false != sys_conf_is_module_active(SYS_MODULE_ID_CUBE_ADCS_GEN2)) && (false != CPCmdHandler_IsDispContextValid(psDispCtx, CP_CMD_CUBEADCS_GEN2_GWSEND)))
    {
        // Set default response status to error
        psDispCtx->u32ResponseActualSize = 0U;
        psDispCtx->u8TLError             = EESTL_SFERR_BAD_CMD_PARAMS;

        if (psDispCtx->u32CmdDataSize >= FP_HDR_SIZE)
        {
            const ESSA_Stack_FP_MsgHdr_t *const p_fp_hdr = (const ESSA_Stack_FP_MsgHdr_t *const)(&psDispCtx->pu8CmdData[FP_HDR_OFFSET]);
            // Check the size of the actual command
            const uint16_t         proto_id  = fs_get_protocol_id(p_fp_hdr->protoId);
            const fs_param_sizes_t cmd_sizes = fs_get_cmd_sizes(proto_id, p_fp_hdr->funcId);

            if (false != fs_are_sizes_valid(&cmd_sizes, psDispCtx->u32CmdDataSize, psDispCtx->u32ResponseBufSize))
            {
                sCubeAdcsGen2SrvCtx_t srv_ctx = {
                    .pu8CmdData            = &psDispCtx->pu8CmdData[CMD_PARAMS_OFFSET],
                    .pu8ResponseBuf        = &psDispCtx->pu8ResponseBuf[FP_HDR_SIZE],
                    .u32CmdDataSize        = cmd_sizes.req_size,
                    .u32ResponseActualSize = 0 // This will be set by the invoked service method
                };
                // Check if the actual physical type of the target node can execute methods of the FIDL interface
                if (false != fs_check_node_compatibility(proto_id, srv_ctx.pu8CmdData[0]))
                {
                    res = fs_invoke_method[proto_id][p_fp_hdr->funcId](&srv_ctx); // Range checks are already covered by fs_are_sizes_valid

                    // Pass response parameters from the service context to the dispatch context
                    psDispCtx->u32ResponseActualSize = FP_HDR_SIZE + srv_ctx.u32ResponseActualSize;
                }
                else
                {
                    psDispCtx->u32ResponseActualSize       = FP_HDR_SIZE + cmd_sizes.resp_size;
                    psDispCtx->pu8ResponseBuf[FP_HDR_SIZE] = CUBEOBC_ERROR_NODE_TYPE;
                    res                                    = ECPDISPATCHRESULT_RESULT_OK; // We need the result as OK so that we can return the node type error to GS.
                }
                psDispCtx->u8TLError = EESTL_SFERR_SUCCESS;

                // Construct the response FP header
                ESSA_Stack_FP_MsgHdr_t *const p_fp_resp_hdr = (ESSA_Stack_FP_MsgHdr_t *const)(psDispCtx->pu8ResponseBuf);
                p_fp_resp_hdr->protoId                      = p_fp_hdr->protoId;
                p_fp_resp_hdr->funcId                       = p_fp_hdr->funcId;
                SET_RESPONSE(*p_fp_resp_hdr);
                p_fp_resp_hdr->seqId   = p_fp_hdr->seqId;
                p_fp_resp_hdr->errCode = ESSA_FP_ERRCODE_NOERROR;
            }
        }
    }

    return res;
}

// clang-format off
// CUBE_ADCS_GEN_SECTION_START::HNDL_CODE
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_setReset(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_setResetRequestGw(NODE_ID, (TypesCommonFramework1_Reset *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_setUnixTime(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_setUnixTimeRequestGw(NODE_ID, (TypesCommonFramework1_UnixTime *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_setErrorLogIndex(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_setErrorLogIndexRequestGw(NODE_ID, (TypesCommonFramework1_ErrorLogIndex *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_setErrorLogEntry(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_setErrorLogEntryRequestGw(NODE_ID, (TypesCommonFramework1_ErrorLogEntry *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_setErrorLogClear(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_setErrorLogClearRequestGw(NODE_ID, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_setErrorLogSettings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_setErrorLogSettingsRequestGw(NODE_ID, (TypesCommonFramework1_ErrorLogSettings *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_setConfigPersist(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_setConfigPersistRequestGw(NODE_ID, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getIdentification(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_getIdentificationRequestGw(NODE_ID, (TypesCommonFramework1_Identification *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCommonFramework1_Identification);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getSerialNumber(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_getSerialNumberRequestGw(NODE_ID, (TypesCommonFramework1_SerialNumber *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCommonFramework1_SerialNumber);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getErrorLogIndex(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_getErrorLogIndexRequestGw(NODE_ID, (TypesCommonFramework1_ErrorLogIndex *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCommonFramework1_ErrorLogIndex);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getErrorLogEntry(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_getErrorLogEntryRequestGw(NODE_ID, (TypesCommonFramework1_ErrorLogEntry *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCommonFramework1_ErrorLogEntry);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getErrorLogSettings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_getErrorLogSettingsRequestGw(NODE_ID, (TypesCommonFramework1_ErrorLogSettings *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCommonFramework1_ErrorLogSettings);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getUnixTime(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_getUnixTimeRequestGw(NODE_ID, (TypesCommonFramework1_UnixTime *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCommonFramework1_UnixTime);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getConfigPersistDiagnostics(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_getConfigPersistDiagnosticsRequestGw(NODE_ID, (TypesCommonFramework1_ConfigPersistDiagnostics *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCommonFramework1_ConfigPersistDiagnostics);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getCommsStatus(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_getCommsStatusRequestGw(NODE_ID, (TypesCommonFramework1_CommsStatus *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCommonFramework1_CommsStatus);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getVersion(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_getVersionRequestGw(NODE_ID, (TypesCommonFramework1_Version *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCommonFramework1_Version);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getBootStatus(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_getBootStatusRequestGw(NODE_ID, (TypesCommonFramework1_BootStatus *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCommonFramework1_BootStatus);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getTelecommandAcknowledge(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_getTelecommandAcknowledgeRequestGw(NODE_ID, (TypesCommonFramework1_TelecommandAcknowledge *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCommonFramework1_TelecommandAcknowledge);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getCommonErrorCodes(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_getCommonErrorCodesRequestGw(NODE_ID, (TypesCommonFramework1_CommonErrorCodes *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCommonFramework1_CommonErrorCodes);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonFramework1_getIdentification2(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonFramework1_getIdentification2RequestGw(NODE_ID, (TypesCommonFramework1_Identification2 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCommonFramework1_Identification2);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonTransfer1_setTransferFrame(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonTransfer1_setTransferFrameRequestGw(NODE_ID, (TypesCommonTransfer1_TransferFrame *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonTransfer1_setFrame(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonTransfer1_setFrameRequestGw(NODE_ID, (TypesCommonTransfer1_Frame *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonTransfer1_getFrameInfo(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonTransfer1_getFrameInfoRequestGw(NODE_ID, (TypesCommonTransfer1_FrameInfo *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCommonTransfer1_FrameInfo);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CommonTransfer1_getFrame(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CommonTransfer1_getFrameRequestGw(NODE_ID, (TypesCommonTransfer1_Frame *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCommonTransfer1_Frame);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_setOhPowerStates(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeAurigaControlProgram1_setOhPowerStatesRequestGw(NODE_ID, (TypesCubeAurigaControlProgram1_OhPowerStates *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_setRtcSync(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeAurigaControlProgram1_setRtcSyncRequestGw(NODE_ID, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_setConfiguration(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeAurigaControlProgram1_setConfigurationRequestGw(NODE_ID, (TypesCubeAurigaControlProgram1_Configuration *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_setAurigaSelfTest(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeAurigaControlProgram1_setAurigaSelfTestRequestGw(NODE_ID, (TypesCubeAurigaControlProgram1_AurigaSelfTest *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_setExtMemTest(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeAurigaControlProgram1_setExtMemTestRequestGw(NODE_ID, (TypesCubeAurigaControlProgram1_ExtMemTest *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_setSpwTest(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeAurigaControlProgram1_setSpwTestRequestGw(NODE_ID, (TypesCubeAurigaControlProgram1_SpwTest *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_getOhPowerStates(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeAurigaControlProgram1_getOhPowerStatesRequestGw(NODE_ID, (TypesCubeAurigaControlProgram1_OhPowerStates *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeAurigaControlProgram1_OhPowerStates);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_getHealthTlm(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeAurigaControlProgram1_getHealthTlmRequestGw(NODE_ID, (TypesCubeAurigaControlProgram1_HealthTlm *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeAurigaControlProgram1_HealthTlm);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_getAurigaStatus(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeAurigaControlProgram1_getAurigaStatusRequestGw(NODE_ID, (TypesCubeAurigaControlProgram1_AurigaStatus *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeAurigaControlProgram1_AurigaStatus);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_getAurigaAttitudeData(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeAurigaControlProgram1_getAurigaAttitudeDataRequestGw(NODE_ID, (TypesCubeAurigaControlProgram1_AurigaAttitudeData *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeAurigaControlProgram1_AurigaAttitudeData);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_getConfiguration(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeAurigaControlProgram1_getConfigurationRequestGw(NODE_ID, (TypesCubeAurigaControlProgram1_Configuration *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeAurigaControlProgram1_Configuration);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_getAurigaSelfTestResults(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeAurigaControlProgram1_getAurigaSelfTestResultsRequestGw(NODE_ID, (TypesCubeAurigaControlProgram1_AurigaSelfTestResults *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeAurigaControlProgram1_AurigaSelfTestResults);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_getExtMemTestResult(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeAurigaControlProgram1_getExtMemTestResultRequestGw(NODE_ID, (TypesCubeAurigaControlProgram1_ExtMemTestResult *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeAurigaControlProgram1_ExtMemTestResult);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeAurigaControlProgram1_getSpwTestResult(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeAurigaControlProgram1_getSpwTestResultRequestGw(NODE_ID, (TypesCubeAurigaControlProgram1_SpwTestResult *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeAurigaControlProgram1_SpwTestResult);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader6_setEccSim(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader6_setEccSimRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader6_EccSim *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader6_getWarnings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader6_getWarningsRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader6_Warnings *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeCommonBaseBootloader6_Warnings);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setReset(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_setResetRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_Reset *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setHalt(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_setHaltRequestGw(NODE_ID, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setConfig(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_setConfigRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_Config *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setDefaultAppTarget(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_setDefaultAppTargetRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_DefaultAppTarget *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setJumpToDefaultApp(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_setJumpToDefaultAppRequestGw(NODE_ID, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setJumpToApp(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_setJumpToAppRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_JumpToApp *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setJumpToAddress(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_setJumpToAddressRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_JumpToAddress *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setResetFileInfoIdx(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_setResetFileInfoIdxRequestGw(NODE_ID, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setWriteFileSetup(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_setWriteFileSetupRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_WriteFileSetup *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setDeleteFileEntry(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_setDeleteFileEntryRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_DeleteFileEntry *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setWriteMemorySetup(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_setWriteMemorySetupRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_WriteMemorySetup *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setReadMemorySetup(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_setReadMemorySetupRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_ReadMemorySetup *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setEraseMemorySetup(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_setEraseMemorySetupRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_EraseMemorySetup *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setOptionBytes(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_setOptionBytesRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_OptionBytes *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setCommitOptionBytes(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_setCommitOptionBytesRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_CommitOptionBytes *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_setOptionBytesF7(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_setOptionBytesF7RequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_OptionBytesF7 *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getIdentification(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_getIdentificationRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_Identification *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeCommonBaseBootloader5_Identification);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getSerialNumber(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_getSerialNumberRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_SerialNumber *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeCommonBaseBootloader5_SerialNumber);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getConfig(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_getConfigRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_Config *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeCommonBaseBootloader5_Config);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getState(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_getStateRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_State *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeCommonBaseBootloader5_State);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getErrors(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_getErrorsRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_Errors *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeCommonBaseBootloader5_Errors);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getFileInfo(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_getFileInfoRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_FileInfo *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeCommonBaseBootloader5_FileInfo);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getDefaultAppTarget(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_getDefaultAppTargetRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_DefaultAppTarget *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeCommonBaseBootloader5_DefaultAppTarget);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getOptionBytes(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_getOptionBytesRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_OptionBytes *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeCommonBaseBootloader5_OptionBytes);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getCommsStatus(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_getCommsStatusRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_CommsStatus *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeCommonBaseBootloader5_CommsStatus);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getMemMap(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_getMemMapRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_MemMap *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeCommonBaseBootloader5_MemMap);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getOptionBytesF7(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_getOptionBytesF7RequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_OptionBytesF7 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeCommonBaseBootloader5_OptionBytesF7);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeCommonBaseBootloader5_getTelecommandAcknowledge(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeCommonBaseBootloader5_getTelecommandAcknowledgeRequestGw(NODE_ID, (TypesCubeCommonBaseBootloader5_TelecommandAcknowledge *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeCommonBaseBootloader5_TelecommandAcknowledge);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigDefaultModes(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setConfigDefaultModesRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigDefaultModes *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMount(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMountRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigMount *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMag0OrbitCal(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMag0OrbitCalRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigMag0OrbitCal *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMag1OrbitCal(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMag1OrbitCalRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigMag1OrbitCal *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAdcsController(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAdcsControllerRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigAdcsController *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAdcsEstimator(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAdcsEstimatorRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigAdcsEstimator *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAdcsSatellite(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAdcsSatelliteRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigAdcsSatellite *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigOrbitSatParams(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setConfigOrbitSatParamsRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigOrbitSatParams *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigOrbitTargetParams(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setConfigOrbitTargetParamsRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigOrbitTargetParams *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigNodeSelection(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setConfigNodeSelectionRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigNodeSelection *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigActuatorRwl(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setConfigActuatorRwlRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigActuatorRwl *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigActuatorMtq(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setConfigActuatorMtqRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigActuatorMtq *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMagSensingElement(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMagSensingElementRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigMagSensingElement *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAsgp4(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAsgp4RequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigAsgp4 *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setConMode(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setConModeRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConMode *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setEstMode(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setEstModeRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_EstMode *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setOrbMode(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setOrbModeRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_OrbMode *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setAdcsRunMode(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setAdcsRunModeRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_AdcsRunMode *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setAdcsOpState(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setAdcsOpStateRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_AdcsOpState *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setSimSensorRaw(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setSimSensorRawRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_SimSensorRaw *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setOpenLoopCommandMtq(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setOpenLoopCommandMtqRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_OpenLoopCommandMtq *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setOpenLoopCommandRwl(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setOpenLoopCommandRwlRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_OpenLoopCommandRwl *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setOpenLoopCommandHxyzRW(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setOpenLoopCommandHxyzRWRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_OpenLoopCommandHxyzRW *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceRpy(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceRpyRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ReferenceRpy *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceTarget(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceTargetRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ReferenceTarget *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceIrcVector(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceIrcVectorRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ReferenceIrcVector *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceFmcParam(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceFmcParamRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ReferenceFmcParam *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setDeployCommandMag(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setDeployCommandMagRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_DeployCommandMag *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setGnssSensorCmd(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setGnssSensorCmdRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_GnssSensorCmd *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_setFileTransferSetup(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_setFileTransferSetupRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_FileTransferSetup *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigDefaultModes(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getConfigDefaultModesRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigDefaultModes *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_ConfigDefaultModes);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMount(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMountRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigMount *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_ConfigMount);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMag0OrbitCal(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMag0OrbitCalRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigMag0OrbitCal *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_ConfigMag0OrbitCal);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMag1OrbitCal(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMag1OrbitCalRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigMag1OrbitCal *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_ConfigMag1OrbitCal);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAdcsController(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAdcsControllerRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigAdcsController *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_ConfigAdcsController);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAdcsEstimator(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAdcsEstimatorRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigAdcsEstimator *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_ConfigAdcsEstimator);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAdcsSatellite(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAdcsSatelliteRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigAdcsSatellite *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_ConfigAdcsSatellite);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigOrbitSatParams(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getConfigOrbitSatParamsRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigOrbitSatParams *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_ConfigOrbitSatParams);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigOrbitTargetParams(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getConfigOrbitTargetParamsRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigOrbitTargetParams *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_ConfigOrbitTargetParams);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigNodeSelection(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getConfigNodeSelectionRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigNodeSelection *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_ConfigNodeSelection);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigActuatorRwl(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getConfigActuatorRwlRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigActuatorRwl *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_ConfigActuatorRwl);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigActuatorMtq(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getConfigActuatorMtqRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigActuatorMtq *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_ConfigActuatorMtq);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMagSensingElement(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMagSensingElementRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigMagSensingElement *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_ConfigMagSensingElement);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAsgp4(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAsgp4RequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConfigAsgp4 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_ConfigAsgp4);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getConMode(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getConModeRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ConMode *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_ConMode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getEstMode(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getEstModeRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_EstMode *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_EstMode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getOrbMode(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getOrbModeRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_OrbMode *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_OrbMode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getAdcsRunMode(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getAdcsRunModeRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_AdcsRunMode *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_AdcsRunMode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getAdcsOpState(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getAdcsOpStateRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_AdcsOpState *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_AdcsOpState);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getSimSensorRaw(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getSimSensorRawRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_SimSensorRaw *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_SimSensorRaw);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getOpenLoopCommandMtq(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getOpenLoopCommandMtqRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_OpenLoopCommandMtq *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_OpenLoopCommandMtq);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getOpenLoopCommandRwl(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getOpenLoopCommandRwlRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_OpenLoopCommandRwl *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_OpenLoopCommandRwl);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getOpenLoopCommandHxyzRW(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getOpenLoopCommandHxyzRWRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_OpenLoopCommandHxyzRW *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_OpenLoopCommandHxyzRW);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceRpy(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceRpyRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ReferenceRpy *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_ReferenceRpy);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceTarget(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceTargetRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ReferenceTarget *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_ReferenceTarget);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceIrcVector(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceIrcVectorRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ReferenceIrcVector *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_ReferenceIrcVector);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceFmcParam(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceFmcParamRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_ReferenceFmcParam *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_ReferenceFmcParam);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getCubeNodePortMap(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getCubeNodePortMapRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_CubeNodePortMap *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_CubeNodePortMap);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmHil(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmHilRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmHil *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmHil);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmExecutionPoint(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmExecutionPointRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmExecutionPoint *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmExecutionPoint);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmAsgp4(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmAsgp4RequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmAsgp4 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmAsgp4);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmNodeInitState(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmNodeInitStateRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmNodeInitState *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmNodeInitState);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmLitefuforsHealth(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmLitefuforsHealthRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmLitefuforsHealth *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmLitefuforsHealth);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getFileTransferSetup(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getFileTransferSetupRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_FileTransferSetup *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_FileTransferSetup);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getFileTransferStatus(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getFileTransferStatusRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_FileTransferStatus *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_FileTransferStatus);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getFileInfo(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getFileInfoRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_FileInfo *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_FileInfo);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawCss(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawCssRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmSensorRawCss *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmSensorRawCss);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawMag(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawMagRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmSensorRawMag *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmSensorRawMag);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawGyro(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawGyroRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmSensorRawGyro *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmSensorRawGyro);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawRwl(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawRwlRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmSensorRawRwl *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmSensorRawRwl);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalFss(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalFssRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmSensorCalFss *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmSensorCalFss);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalCss(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalCssRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmSensorCalCss *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmSensorCalCss);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalMag(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalMagRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmSensorCalMag *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmSensorCalMag);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalGyro(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalGyroRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmSensorCalGyro *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmSensorCalGyro);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalHss(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalHssRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmSensorCalHss *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmSensorCalHss);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalStr(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalStrRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmSensorCalStr *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmSensorCalStr);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalGnss(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalGnssRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmSensorCalGnss *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmSensorCalGnss);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalRwl(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalRwlRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmSensorCalRwl *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmSensorCalRwl);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmModels(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmModelsRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmModels *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmModels);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmEstimatorMain(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmEstimatorMainRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmEstimatorMain *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmEstimatorMain);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmEstimatorBackup(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmEstimatorBackupRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmEstimatorBackup *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmEstimatorBackup);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmEstimatorMainHighRes(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmEstimatorMainHighResRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmEstimatorMainHighRes *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmEstimatorMainHighRes);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmController(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmControllerRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmController *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmController);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmGnssRaw(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmGnssRawRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmGnssRaw *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmGnssRaw);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmExtSensorRaw(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmExtSensorRawRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmExtSensorRaw *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmExtSensorRaw);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrPst3sRaw(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrPst3sRawRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmStrPst3sRaw *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmStrPst3sRaw);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmFssCubeSenseSunRaw(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmFssCubeSenseSunRawRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmFssCubeSenseSunRaw *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmFssCubeSenseSunRaw);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmHssCubeSenseEarthRaw(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmHssCubeSenseEarthRawRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmHssCubeSenseEarthRaw *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmHssCubeSenseEarthRaw);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmRwlNssRwlRaw(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmRwlNssRwlRawRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmRwlNssRwlRaw *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmRwlNssRwlRaw);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrCubeStarRaw(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrCubeStarRawRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmStrCubeStarRaw *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmStrCubeStarRaw);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmGyrLitefuforsRaw(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmGyrLitefuforsRawRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmGyrLitefuforsRaw *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmGyrLitefuforsRaw);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrCubeAurigaRaw(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrCubeAurigaRawRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmStrCubeAurigaRaw *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmStrCubeAurigaRaw);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmAcpExecution(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmAcpExecutionRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmAcpExecution *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmAcpExecution);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmTorquerCurrents(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmTorquerCurrentsRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmTorquerCurrents *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmTorquerCurrents);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmCubeComputerHealth(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmCubeComputerHealthRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmCubeComputerHealth *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmCubeComputerHealth);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmFssCubeSenseSunHealth(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmFssCubeSenseSunHealthRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmFssCubeSenseSunHealth *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmFssCubeSenseSunHealth);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmHssCubeSenseEarthHealth(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmHssCubeSenseEarthHealthRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmHssCubeSenseEarthHealth *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmHssCubeSenseEarthHealth);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmCubeMagHealth(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmCubeMagHealthRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmCubeMagHealth *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmCubeMagHealth);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmRwlHealth(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmRwlHealthRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmRwlHealth *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmRwlHealth);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrPst3sHealth(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrPst3sHealthRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmStrPst3sHealth *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmStrPst3sHealth);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmNssRwlHealth(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmNssRwlHealthRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmNssRwlHealth *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmNssRwlHealth);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrHealth(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrHealthRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmStrHealth *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmStrHealth);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmGnssUartStatus(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmGnssUartStatusRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmGnssUartStatus *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmGnssUartStatus);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrAurigaHealth(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrAurigaHealthRequestGw(NODE_ID, (TypesCubeComputerControlProgram8_TlmStrAurigaHealth *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerControlProgram8_TlmStrAurigaHealth);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setPassThrough(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_setPassThroughRequestGw(NODE_ID, (TypesCubeComputerCommon3_PassThrough *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setPowerState(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_setPowerStateRequestGw(NODE_ID, (TypesCubeComputerCommon3_PowerState *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setImageTransferSetup(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_setImageTransferSetupRequestGw(NODE_ID, (TypesCubeComputerCommon3_ImageTransferSetup *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setImageFileInfoReset(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_setImageFileInfoResetRequestGw(NODE_ID, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setPortMap(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_setPortMapRequestGw(NODE_ID, (TypesCubeComputerCommon3_PortMap *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setEraseLogData(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_setEraseLogDataRequestGw(NODE_ID, (TypesCubeComputerCommon3_EraseLogData *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setEventLogFilterTransferSetup(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_setEventLogFilterTransferSetupRequestGw(NODE_ID, (TypesCubeComputerCommon3_EventLogFilterTransferSetup *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setTelemetryLogTransferSetup(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_setTelemetryLogTransferSetupRequestGw(NODE_ID, (TypesCubeComputerCommon3_TelemetryLogTransferSetup *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setDummyEvent(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_setDummyEventRequestGw(NODE_ID, (TypesCubeComputerCommon3_DummyEvent *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setUnsolicitedEventSetup(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_setUnsolicitedEventSetupRequestGw(NODE_ID, (TypesCubeComputerCommon3_UnsolicitedEventSetup *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_setUnsolicitedTlmSetup(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_setUnsolicitedTlmSetupRequestGw(NODE_ID, (TypesCubeComputerCommon3_UnsolicitedTlmSetup *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getPassThrough(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_getPassThroughRequestGw(NODE_ID, (TypesCubeComputerCommon3_PassThrough *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerCommon3_PassThrough);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getPowerState(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_getPowerStateRequestGw(NODE_ID, (TypesCubeComputerCommon3_PowerState *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerCommon3_PowerState);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getPortDiagnostics(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_getPortDiagnosticsRequestGw(NODE_ID, (TypesCubeComputerCommon3_PortDiagnostics *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerCommon3_PortDiagnostics);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getPortMap(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_getPortMapRequestGw(NODE_ID, (TypesCubeComputerCommon3_PortMap *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerCommon3_PortMap);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getExpectedNodes(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_getExpectedNodesRequestGw(NODE_ID, (TypesCubeComputerCommon3_ExpectedNodes *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerCommon3_ExpectedNodes);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getImageTransferStatus(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_getImageTransferStatusRequestGw(NODE_ID, (TypesCubeComputerCommon3_ImageTransferStatus *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerCommon3_ImageTransferStatus);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getImageFileInfo(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_getImageFileInfoRequestGw(NODE_ID, (TypesCubeComputerCommon3_ImageFileInfo *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerCommon3_ImageFileInfo);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getComponentErrorCodes(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_getComponentErrorCodesRequestGw(NODE_ID, (TypesCubeComputerCommon3_ComponentErrorCodes *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerCommon3_ComponentErrorCodes);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getEventLogStatus(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_getEventLogStatusRequestGw(NODE_ID, (TypesCubeComputerCommon3_EventLogStatus *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerCommon3_EventLogStatus);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getTelemtryLogStatus(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_getTelemtryLogStatusRequestGw(NODE_ID, (TypesCubeComputerCommon3_TelemtryLogStatus *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerCommon3_TelemtryLogStatus);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getUnsolicitedEventSetup(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_getUnsolicitedEventSetupRequestGw(NODE_ID, (TypesCubeComputerCommon3_UnsolicitedEventSetup *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerCommon3_UnsolicitedEventSetup);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getUnsolicitedTlmSetup(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_getUnsolicitedTlmSetupRequestGw(NODE_ID, (TypesCubeComputerCommon3_UnsolicitedTlmSetup *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerCommon3_UnsolicitedTlmSetup);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeComputerCommon3_getTelemtryLogInclusionMasks(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeComputerCommon3_getTelemtryLogInclusionMasksRequestGw(NODE_ID, (TypesCubeComputerCommon3_TelemtryLogInclusionMasks *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeComputerCommon3_TelemtryLogInclusionMasks);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_setConfiguration(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeIrControlProgram1_setConfigurationRequestGw(NODE_ID, (TypesCubeIrControlProgram1_Configuration *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_setImageTransferSetup(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeIrControlProgram1_setImageTransferSetupRequestGw(NODE_ID, (TypesCubeIrControlProgram1_ImageTransferSetup *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_setDeadPixels(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeIrControlProgram1_setDeadPixelsRequestGw(NODE_ID, (TypesCubeIrControlProgram1_DeadPixels *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_setRequestDeadPixel(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeIrControlProgram1_setRequestDeadPixelRequestGw(NODE_ID, (TypesCubeIrControlProgram1_RequestDeadPixel *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_getMeasurementAndTrigger(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeIrControlProgram1_getMeasurementAndTriggerRequestGw(NODE_ID, (TypesCubeIrControlProgram1_MeasurementAndTrigger *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeIrControlProgram1_MeasurementAndTrigger);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_getMeasurement(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeIrControlProgram1_getMeasurementRequestGw(NODE_ID, (TypesCubeIrControlProgram1_Measurement *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeIrControlProgram1_Measurement);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_getMeasurementMetadata(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeIrControlProgram1_getMeasurementMetadataRequestGw(NODE_ID, (TypesCubeIrControlProgram1_MeasurementMetadata *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeIrControlProgram1_MeasurementMetadata);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_getHealthTlm(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeIrControlProgram1_getHealthTlmRequestGw(NODE_ID, (TypesCubeIrControlProgram1_HealthTlm *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeIrControlProgram1_HealthTlm);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_getConfiguration(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeIrControlProgram1_getConfigurationRequestGw(NODE_ID, (TypesCubeIrControlProgram1_Configuration *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeIrControlProgram1_Configuration);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_getProfileTiming(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeIrControlProgram1_getProfileTimingRequestGw(NODE_ID, (TypesCubeIrControlProgram1_ProfileTiming *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeIrControlProgram1_ProfileTiming);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeIrControlProgram1_getRequestedDeadPixel(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeIrControlProgram1_getRequestedDeadPixelRequestGw(NODE_ID, (TypesCubeIrControlProgram1_RequestedDeadPixel *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeIrControlProgram1_RequestedDeadPixel);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_setMmcConfig(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramCommon1_setMmcConfigRequestGw(NODE_ID, (TypesCubeMagControlProgramCommon1_MmcConfig *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_setSamplePrimary(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramCommon1_setSamplePrimaryRequestGw(NODE_ID, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_setConfig(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramCommon1_setConfigRequestGw(NODE_ID, (TypesCubeMagControlProgramCommon1_Config *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_setMmcCalibration(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramCommon1_setMmcCalibrationRequestGw(NODE_ID, (TypesCubeMagControlProgramCommon1_MmcCalibration *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_getMmcConfig(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramCommon1_getMmcConfigRequestGw(NODE_ID, (TypesCubeMagControlProgramCommon1_MmcConfig *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeMagControlProgramCommon1_MmcConfig);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_getState(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramCommon1_getStateRequestGw(NODE_ID, (TypesCubeMagControlProgramCommon1_State *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeMagControlProgramCommon1_State);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagMeasurement(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagMeasurementRequestGw(NODE_ID, (TypesCubeMagControlProgramCommon1_PrimaryMagMeasurement *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeMagControlProgramCommon1_PrimaryMagMeasurement);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagMeasurementRaw(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagMeasurementRawRequestGw(NODE_ID, (TypesCubeMagControlProgramCommon1_PrimaryMagMeasurementRaw *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeMagControlProgramCommon1_PrimaryMagMeasurementRaw);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagTemp(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagTempRequestGw(NODE_ID, (TypesCubeMagControlProgramCommon1_PrimaryMagTemp *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeMagControlProgramCommon1_PrimaryMagTemp);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_getConfig(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramCommon1_getConfigRequestGw(NODE_ID, (TypesCubeMagControlProgramCommon1_Config *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeMagControlProgramCommon1_Config);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagDiagnostics(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagDiagnosticsRequestGw(NODE_ID, (TypesCubeMagControlProgramCommon1_PrimaryMagDiagnostics *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeMagControlProgramCommon1_PrimaryMagDiagnostics);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCommon1_getMmcCalibration(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramCommon1_getMmcCalibrationRequestGw(NODE_ID, (TypesCubeMagControlProgramCommon1_MmcCalibration *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeMagControlProgramCommon1_MmcCalibration);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramCompact1_getHealthTlm(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramCompact1_getHealthTlmRequestGw(NODE_ID, (TypesCubeMagControlProgramCompact1_HealthTlm *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeMagControlProgramCompact1_HealthTlm);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_setPniConfig(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramDeploy1_setPniConfigRequestGw(NODE_ID, (TypesCubeMagControlProgramDeploy1_PniConfig *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_setSampleRed(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramDeploy1_setSampleRedRequestGw(NODE_ID, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_setDeploy(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramDeploy1_setDeployRequestGw(NODE_ID, (TypesCubeMagControlProgramDeploy1_Deploy *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_setDeployArm(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramDeploy1_setDeployArmRequestGw(NODE_ID, (TypesCubeMagControlProgramDeploy1_DeployArm *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_setPniCalibration(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramDeploy1_setPniCalibrationRequestGw(NODE_ID, (TypesCubeMagControlProgramDeploy1_PniCalibration *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_getHealthTlm(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramDeploy1_getHealthTlmRequestGw(NODE_ID, (TypesCubeMagControlProgramDeploy1_HealthTlm *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeMagControlProgramDeploy1_HealthTlm);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_getPniConfig(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramDeploy1_getPniConfigRequestGw(NODE_ID, (TypesCubeMagControlProgramDeploy1_PniConfig *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeMagControlProgramDeploy1_PniConfig);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagMeasurement(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagMeasurementRequestGw(NODE_ID, (TypesCubeMagControlProgramDeploy1_RedMagMeasurement *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeMagControlProgramDeploy1_RedMagMeasurement);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagMeasurementRaw(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagMeasurementRawRequestGw(NODE_ID, (TypesCubeMagControlProgramDeploy1_RedMagMeasurementRaw *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeMagControlProgramDeploy1_RedMagMeasurementRaw);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagTemp(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagTempRequestGw(NODE_ID, (TypesCubeMagControlProgramDeploy1_RedMagTemp *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeMagControlProgramDeploy1_RedMagTemp);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_getDeploymentStatus(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramDeploy1_getDeploymentStatusRequestGw(NODE_ID, (TypesCubeMagControlProgramDeploy1_DeploymentStatus *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeMagControlProgramDeploy1_DeploymentStatus);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagDiagnostics(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagDiagnosticsRequestGw(NODE_ID, (TypesCubeMagControlProgramDeploy1_RedMagDiagnostics *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeMagControlProgramDeploy1_RedMagDiagnostics);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeMagControlProgramDeploy1_getPniCalibration(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeMagControlProgramDeploy1_getPniCalibrationRequestGw(NODE_ID, (TypesCubeMagControlProgramDeploy1_PniCalibration *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeMagControlProgramDeploy1_PniCalibration);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_setUforsPower(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_setUforsPowerRequestGw(NODE_ID, (TypesCubeNodeControlProgramLitefufors1_UforsPower *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_setNodeSvcSettings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_setNodeSvcSettingsRequestGw(NODE_ID, (TypesCubeNodeControlProgramLitefufors1_NodeSvcSettings *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_setUforsSvcSettings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_setUforsSvcSettingsRequestGw(NODE_ID, (TypesCubeNodeControlProgramLitefufors1_UforsSvcSettings *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getNodeSvcSettings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getNodeSvcSettingsRequestGw(NODE_ID, (TypesCubeNodeControlProgramLitefufors1_NodeSvcSettings *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramLitefufors1_NodeSvcSettings);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsSvcSettings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsSvcSettingsRequestGw(NODE_ID, (TypesCubeNodeControlProgramLitefufors1_UforsSvcSettings *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramLitefufors1_UforsSvcSettings);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getNodeSvcStatus(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getNodeSvcStatusRequestGw(NODE_ID, (TypesCubeNodeControlProgramLitefufors1_NodeSvcStatus *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramLitefufors1_NodeSvcStatus);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsSvcStatus(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsSvcStatusRequestGw(NODE_ID, (TypesCubeNodeControlProgramLitefufors1_UforsSvcStatus *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramLitefufors1_UforsSvcStatus);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlm(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmRequestGw(NODE_ID, (TypesCubeNodeControlProgramLitefufors1_UforsTlm *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramLitefufors1_UforsTlm);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort1(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort1RequestGw(NODE_ID, (TypesCubeNodeControlProgramLitefufors1_UforsTlmPort1 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramLitefufors1_UforsTlmPort1);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort2(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort2RequestGw(NODE_ID, (TypesCubeNodeControlProgramLitefufors1_UforsTlmPort2 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramLitefufors1_UforsTlmPort2);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort3(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort3RequestGw(NODE_ID, (TypesCubeNodeControlProgramLitefufors1_UforsTlmPort3 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramLitefufors1_UforsTlmPort3);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort4(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort4RequestGw(NODE_ID, (TypesCubeNodeControlProgramLitefufors1_UforsTlmPort4 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramLitefufors1_UforsTlmPort4);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNodeSvcSettings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNodeSvcSettingsRequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlCommon1_NodeSvcSettings *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlSvcSettings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlSvcSettingsRequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlCommon1_NssRwlSvcSettings *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlPower(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlPowerRequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlCommon1_NssRwlPower *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlWheelSpeedRef(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlWheelSpeedRefRequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlCommon1_NssRwlWheelSpeedRef *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlTorque(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlTorqueRequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlCommon1_NssRwlTorque *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlMotorCurrent(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlMotorCurrentRequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlCommon1_NssRwlMotorCurrent *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlSoftwareReset(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlSoftwareResetRequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlCommon1_NssRwlSoftwareReset *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNodeSvcSettings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNodeSvcSettingsRequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlCommon1_NodeSvcSettings *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NodeSvcSettings);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNodeSvcStatus(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNodeSvcStatusRequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlCommon1_NodeSvcStatus *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NodeSvcStatus);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlSvcSettings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlSvcSettingsRequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlCommon1_NssRwlSvcSettings *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlSvcSettings);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlSvcStatus(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlSvcStatusRequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlCommon1_NssRwlSvcStatus *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlSvcStatus);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlWheelSpeed1(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlWheelSpeed1RequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlCommon1_NssRwlWheelSpeed1 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlWheelSpeed1);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlTlmStandard1(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlTlmStandard1RequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlCommon1_NssRwlTlmStandard1 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlTlmStandard1);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlTlmExtended1(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlTlmExtended1RequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlCommon1_NssRwlTlmExtended1 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlTlmExtended1);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlTlmSystem1(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlTlmSystem1RequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlCommon1_NssRwlTlmSystem1 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlTlmSystem1);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlWheelSpeedAll(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlWheelSpeedAllRequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlCommon1_NssRwlWheelSpeedAll *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlCommon1_NssRwlWheelSpeedAll);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlWheelSpeed2(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlWheelSpeed2RequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlQuad1_NssRwlWheelSpeed2 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlWheelSpeed2);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlWheelSpeed3(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlWheelSpeed3RequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlQuad1_NssRwlWheelSpeed3 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlWheelSpeed3);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlWheelSpeed4(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlWheelSpeed4RequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlQuad1_NssRwlWheelSpeed4 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlWheelSpeed4);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmStandard2(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmStandard2RequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmStandard2 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmStandard2);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmStandard3(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmStandard3RequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmStandard3 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmStandard3);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmStandard4(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmStandard4RequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmStandard4 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmStandard4);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmExtended2(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmExtended2RequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmExtended2 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmExtended2);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmExtended3(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmExtended3RequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmExtended3 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmExtended3);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmExtended4(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmExtended4RequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmExtended4 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmExtended4);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmSystem2(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmSystem2RequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmSystem2 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmSystem2);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmSystem3(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmSystem3RequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmSystem3 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmSystem3);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmSystem4(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmSystem4RequestGw(NODE_ID, (TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmSystem4 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmSystem4);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sNumberNavigationStars(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sNumberNavigationStarsRequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sNumberNavigationStars *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sExposure(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sExposureRequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sExposure *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sFSST(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sFSSTRequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sFSST *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSecondCalibration(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSecondCalibrationRequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sSecondCalibration *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sTrackingModeThreshold(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sTrackingModeThresholdRequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sTrackingModeThreshold *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sQuaternionFiltering(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sQuaternionFilteringRequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sQuaternionFiltering *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSystemReset(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSystemResetRequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sSystemReset *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sPower(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sPowerRequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sPower *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sImageFixedThreshold(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sImageFixedThresholdRequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sImageFixedThreshold *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSvcSettings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSvcSettingsRequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sSvcSettings *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setNodeSvcSettings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setNodeSvcSettingsRequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_NodeSvcSettings *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSaaMode(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSaaModeRequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sSaaMode *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSaaThreshold(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSaaThresholdRequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sSaaThreshold *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sDynamicMode(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sDynamicModeRequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sDynamicMode *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sEdacOff(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sEdacOffRequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sEdacOff *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sSvcStatus(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sSvcStatusRequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sSvcStatus *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sSvcStatus);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sTlm1(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sTlm1RequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sTlm1 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sTlm1);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sAttitude1(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sAttitude1RequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sAttitude1 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sAttitude1);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sHousekeeping1(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sHousekeeping1RequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sHousekeeping1 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sHousekeeping1);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sConfig1(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sConfig1RequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sConfig1 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sConfig1);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sSvcSettings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sSvcSettingsRequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_Pst3sSvcSettings *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_Pst3sSvcSettings);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getNodeSvcStatus(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getNodeSvcStatusRequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_NodeSvcStatus *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_NodeSvcStatus);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getNodeSvcSettings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getNodeSvcSettingsRequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sCommon1_NodeSvcSettings *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sCommon1_NodeSvcSettings);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sTlm2(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sTlm2RequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sQuad1_Pst3sTlm2 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sTlm2);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sTlm3(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sTlm3RequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sQuad1_Pst3sTlm3 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sTlm3);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sTlm4(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sTlm4RequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sQuad1_Pst3sTlm4 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sTlm4);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sAttitude2(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sAttitude2RequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sQuad1_Pst3sAttitude2 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sAttitude2);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sAttitude3(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sAttitude3RequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sQuad1_Pst3sAttitude3 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sAttitude3);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sAttitude4(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sAttitude4RequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sQuad1_Pst3sAttitude4 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sAttitude4);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sHousekeeping2(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sHousekeeping2RequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sQuad1_Pst3sHousekeeping2 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sHousekeeping2);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sHousekeeping3(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sHousekeeping3RequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sQuad1_Pst3sHousekeeping3 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sHousekeeping3);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sHousekeeping4(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sHousekeeping4RequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sQuad1_Pst3sHousekeeping4 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sHousekeeping4);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sConfig2(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sConfig2RequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sQuad1_Pst3sConfig2 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sConfig2);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sConfig3(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sConfig3RequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sQuad1_Pst3sConfig3 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sConfig3);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sConfig4(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sConfig4RequestGw(NODE_ID, (TypesCubeNodeControlProgramPst3sQuad1_Pst3sConfig4 *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeControlProgramPst3sQuad1_Pst3sConfig4);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeCommon1_setPowerSwitchState(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeCommon1_setPowerSwitchStateRequestGw(NODE_ID, (TypesCubeNodeCommon1_PowerSwitchState *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeCommon1_getHealthTlm(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeCommon1_getHealthTlmRequestGw(NODE_ID, (TypesCubeNodeCommon1_HealthTlm *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeCommon1_HealthTlm);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeCommon1_getPowerSwitchState(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeCommon1_getPowerSwitchStateRequestGw(NODE_ID, (TypesCubeNodeCommon1_PowerSwitchState *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeCommon1_PowerSwitchState);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeNodeCommon1_getNodeModel(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeNodeCommon1_getNodeModelRequestGw(NODE_ID, (TypesCubeNodeCommon1_NodeModel *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeNodeCommon1_NodeModel);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setCamLensDistortion(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseControlProgram5_setCamLensDistortionRequestGw(NODE_ID, (TypesCubeSenseControlProgram5_CamLensDistortion *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setCaptureDetect(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseControlProgram5_setCaptureDetectRequestGw(NODE_ID, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setDetect(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseControlProgram5_setDetectRequestGw(NODE_ID, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setClearOvercurrentFlags(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseControlProgram5_setClearOvercurrentFlagsRequestGw(NODE_ID, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setImageCapture(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseControlProgram5_setImageCaptureRequestGw(NODE_ID, (TypesCubeSenseControlProgram5_ImageCapture *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setImageTransferSetup(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseControlProgram5_setImageTransferSetupRequestGw(NODE_ID, (TypesCubeSenseControlProgram5_ImageTransferSetup *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setCamBoresight(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseControlProgram5_setCamBoresightRequestGw(NODE_ID, (TypesCubeSenseControlProgram5_CamBoresight *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setCamMask(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseControlProgram5_setCamMaskRequestGw(NODE_ID, (TypesCubeSenseControlProgram5_CamMask *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setCamThreshold(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseControlProgram5_setCamThresholdRequestGw(NODE_ID, (TypesCubeSenseControlProgram5_CamThreshold *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_setDetectionAreaRowSelect(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseControlProgram5_setDetectionAreaRowSelectRequestGw(NODE_ID, (TypesCubeSenseControlProgram5_DetectionAreaRowSelect *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_getSensorResultsTimestamp(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseControlProgram5_getSensorResultsTimestampRequestGw(NODE_ID, (TypesCubeSenseControlProgram5_SensorResultsTimestamp *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeSenseControlProgram5_SensorResultsTimestamp);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_getCamLensDistortion(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseControlProgram5_getCamLensDistortionRequestGw(NODE_ID, (TypesCubeSenseControlProgram5_CamLensDistortion *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeSenseControlProgram5_CamLensDistortion);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_getCamMasks(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseControlProgram5_getCamMasksRequestGw(NODE_ID, (TypesCubeSenseControlProgram5_CamMasks *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeSenseControlProgram5_CamMasks);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_getSensorResults(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseControlProgram5_getSensorResultsRequestGw(NODE_ID, (TypesCubeSenseControlProgram5_SensorResults *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeSenseControlProgram5_SensorResults);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_getSensorResultTrigger(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseControlProgram5_getSensorResultTriggerRequestGw(NODE_ID, (TypesCubeSenseControlProgram5_SensorResultTrigger *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeSenseControlProgram5_SensorResultTrigger);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_getAutoCamSensorRaw(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseControlProgram5_getAutoCamSensorRawRequestGw(NODE_ID, (TypesCubeSenseControlProgram5_AutoCamSensorRaw *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeSenseControlProgram5_AutoCamSensorRaw);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_getDetectionAreaRow(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseControlProgram5_getDetectionAreaRowRequestGw(NODE_ID, (TypesCubeSenseControlProgram5_DetectionAreaRow *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeSenseControlProgram5_DetectionAreaRow);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseControlProgram5_getCamBoresight(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseControlProgram5_getCamBoresightRequestGw(NODE_ID, (TypesCubeSenseControlProgram5_CamBoresight *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeSenseControlProgram5_CamBoresight);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseCommon1_setCamAutoAdjust(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseCommon1_setCamAutoAdjustRequestGw(NODE_ID, (TypesCubeSenseCommon1_CamAutoAdjust *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseCommon1_setCamSettings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseCommon1_setCamSettingsRequestGw(NODE_ID, (TypesCubeSenseCommon1_CamSettings *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseCommon1_getConfig(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseCommon1_getConfigRequestGw(NODE_ID, (TypesCubeSenseCommon1_Config *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeSenseCommon1_Config);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeSenseCommon1_getHealthTlm(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeSenseCommon1_getHealthTlmRequestGw(NODE_ID, (TypesCubeSenseCommon1_HealthTlm *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeSenseCommon1_HealthTlm);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setCaptureDetect(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_setCaptureDetectRequestGw(NODE_ID, (TypesCubeStarControlProgram6_CaptureDetect *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setCaptureOnly(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_setCaptureOnlyRequestGw(NODE_ID, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setDetectIdOnly(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_setDetectIdOnlyRequestGw(NODE_ID, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setLensDistortion(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_setLensDistortionRequestGw(NODE_ID, (TypesCubeStarControlProgram6_LensDistortion *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setDetectionSettings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_setDetectionSettingsRequestGw(NODE_ID, (TypesCubeStarControlProgram6_DetectionSettings *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setSensorSettings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_setSensorSettingsRequestGw(NODE_ID, (TypesCubeStarControlProgram6_SensorSettings *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setImageTransferSetup(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_setImageTransferSetupRequestGw(NODE_ID, (TypesCubeStarControlProgram6_ImageTransferSetup *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setSensorRegisterRead(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_setSensorRegisterReadRequestGw(NODE_ID, (TypesCubeStarControlProgram6_SensorRegisterRead *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setSensorRegisterWrite(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_setSensorRegisterWriteRequestGw(NODE_ID, (TypesCubeStarControlProgram6_SensorRegisterWrite *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_setSubsystemPower(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_setSubsystemPowerRequestGw(NODE_ID, (TypesCubeStarControlProgram6_SubsystemPower *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getLensDistortion(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_getLensDistortionRequestGw(NODE_ID, (TypesCubeStarControlProgram6_LensDistortion *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeStarControlProgram6_LensDistortion);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getDetectionSettings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_getDetectionSettingsRequestGw(NODE_ID, (TypesCubeStarControlProgram6_DetectionSettings *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeStarControlProgram6_DetectionSettings);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getSensorSettings(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_getSensorSettingsRequestGw(NODE_ID, (TypesCubeStarControlProgram6_SensorSettings *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeStarControlProgram6_SensorSettings);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getStatus(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_getStatusRequestGw(NODE_ID, (TypesCubeStarControlProgram6_Status *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeStarControlProgram6_Status);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getDetectionMetaData(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_getDetectionMetaDataRequestGw(NODE_ID, (TypesCubeStarControlProgram6_DetectionMetaData *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeStarControlProgram6_DetectionMetaData);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getDetectedStars(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_getDetectedStarsRequestGw(NODE_ID, (TypesCubeStarControlProgram6_DetectedStars *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeStarControlProgram6_DetectedStars);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getHealthTlm(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_getHealthTlmRequestGw(NODE_ID, (TypesCubeStarControlProgram6_HealthTlm *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeStarControlProgram6_HealthTlm);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getSensorRegisterValue(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_getSensorRegisterValueRequestGw(NODE_ID, (TypesCubeStarControlProgram6_SensorRegisterValue *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeStarControlProgram6_SensorRegisterValue);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getBestStars(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_getBestStarsRequestGw(NODE_ID, (TypesCubeStarControlProgram6_BestStars *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeStarControlProgram6_BestStars);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeStarControlProgram6_getAttitude(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeStarControlProgram6_getAttitudeRequestGw(NODE_ID, (TypesCubeStarControlProgram6_Attitude *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeStarControlProgram6_Attitude);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setWheelSpeedRef(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_setWheelSpeedRefRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_WheelSpeedRef *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setWheelTorqueRef(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_setWheelTorqueRefRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_WheelTorqueRef *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setWheelTravelRef(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_setWheelTravelRefRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_WheelTravelRef *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setWheelRefRampRateLimit(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_setWheelRefRampRateLimitRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_WheelRefRampRateLimit *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setBackupWheelMode(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_setBackupWheelModeRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_BackupWheelMode *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setClearErrors(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_setClearErrorsRequestGw(NODE_ID, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setMainGain(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_setMainGainRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_MainGain *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setBackupGain(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_setBackupGainRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_BackupGain *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setPWMGain(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_setPWMGainRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_PWMGain *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_setMotorPower(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_setMotorPowerRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_MotorPower *)API_DATA_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getWheelRefRampRateLimit(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_getWheelRefRampRateLimitRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_WheelRefRampRateLimit *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeWheelControlProgram3_WheelRefRampRateLimit);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getStator(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_getStatorRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_Stator *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeWheelControlProgram3_Stator);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getWheelTorque(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_getWheelTorqueRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_WheelTorque *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeWheelControlProgram3_WheelTorque);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getBackupGain(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_getBackupGainRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_BackupGain *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeWheelControlProgram3_BackupGain);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getMainGain(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_getMainGainRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_MainGain *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeWheelControlProgram3_MainGain);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getPWMGain(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_getPWMGainRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_PWMGain *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeWheelControlProgram3_PWMGain);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getStatusErrorFlags(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_getStatusErrorFlagsRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_StatusErrorFlags *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeWheelControlProgram3_StatusErrorFlags);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getWheelData(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_getWheelDataRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_WheelData *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeWheelControlProgram3_WheelData);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getWheelDuty(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_getWheelDutyRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_WheelDuty *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeWheelControlProgram3_WheelDuty);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getHealthTlm(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_getHealthTlmRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_HealthTlm *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeWheelControlProgram3_HealthTlm);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getWheelSpeedRef(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_getWheelSpeedRefRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_WheelSpeedRef *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeWheelControlProgram3_WheelSpeedRef);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getWheelTorqueRef(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_getWheelTorqueRefRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_WheelTorqueRef *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeWheelControlProgram3_WheelTorqueRef);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getWheelSpeed(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_getWheelSpeedRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_WheelSpeed *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeWheelControlProgram3_WheelSpeed);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getMotorPower(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_getMotorPowerRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_MotorPower *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeWheelControlProgram3_MotorPower);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getControlMode(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_getControlModeRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_ControlMode *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeWheelControlProgram3_ControlMode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getBackupWheelMode(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_getBackupWheelModeRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_BackupWheelMode *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeWheelControlProgram3_BackupWheelMode);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getWheelModel(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_getWheelModelRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_WheelModel *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeWheelControlProgram3_WheelModel);
    return ECPDISPATCHRESULT_RESULT_OK;
}
eCPDispatchResult_t CPCmdHandler_CubeADCS_Gen2_CubeWheelControlProgram3_getWheelPosData(sCubeAdcsGen2SrvCtx_t *const pSrvCtx)
{
    API_STATUS = CubeADCS_Gen2_CubeWheelControlProgram3_getWheelPosDataRequestGw(NODE_ID, (TypesCubeWheelControlProgram3_WheelPosData *)API_DATA_RESP_ADDRESS, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT);
    pSrvCtx->u32ResponseActualSize = sizeof(ErrorCode) + sizeof(TypesCubeWheelControlProgram3_WheelPosData);
    return ECPDISPATCHRESULT_RESULT_OK;
}
// CUBE_ADCS_GEN_SECTION_END::HNDL_CODE
// clang-format on
