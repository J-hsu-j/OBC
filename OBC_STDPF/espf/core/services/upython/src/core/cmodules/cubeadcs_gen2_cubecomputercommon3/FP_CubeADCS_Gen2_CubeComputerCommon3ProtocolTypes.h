
#ifndef FP_CUBEADCS_GEN2_CUBECOMPUTERCOMMON3PROTOCOLTYPES_H
#define FP_CUBEADCS_GEN2_CUBECOMPUTERCOMMON3PROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_CUBEADCS_GEN2_CUBECOMPUTERCOMMON3 ((uint16_t) (0x00000131))

#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETPASSTHROUGH_FUNC_ID ((funcIdType_t) 0x00000000)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETPOWERSTATE_FUNC_ID ((funcIdType_t) 0x00000001)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETIMAGETRANSFERSETUP_FUNC_ID ((funcIdType_t) 0x00000002)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETIMAGEFILEINFORESET_FUNC_ID ((funcIdType_t) 0x00000003)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETPORTMAP_FUNC_ID ((funcIdType_t) 0x00000004)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETERASELOGDATA_FUNC_ID ((funcIdType_t) 0x00000005)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETEVENTLOGFILTERTRANSFERSETUP_FUNC_ID ((funcIdType_t) 0x00000006)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETTELEMETRYLOGTRANSFERSETUP_FUNC_ID ((funcIdType_t) 0x00000007)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETDUMMYEVENT_FUNC_ID ((funcIdType_t) 0x00000008)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETUNSOLICITEDEVENTSETUP_FUNC_ID ((funcIdType_t) 0x00000009)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETUNSOLICITEDTLMSETUP_FUNC_ID ((funcIdType_t) 0x0000000A)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETPASSTHROUGH_FUNC_ID ((funcIdType_t) 0x0000000B)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETPOWERSTATE_FUNC_ID ((funcIdType_t) 0x0000000C)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETPORTDIAGNOSTICS_FUNC_ID ((funcIdType_t) 0x0000000D)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETPORTMAP_FUNC_ID ((funcIdType_t) 0x0000000E)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETEXPECTEDNODES_FUNC_ID ((funcIdType_t) 0x0000000F)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETIMAGETRANSFERSTATUS_FUNC_ID ((funcIdType_t) 0x00000010)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETIMAGEFILEINFO_FUNC_ID ((funcIdType_t) 0x00000011)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETCOMPONENTERRORCODES_FUNC_ID ((funcIdType_t) 0x00000012)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETEVENTLOGSTATUS_FUNC_ID ((funcIdType_t) 0x00000013)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETTELEMTRYLOGSTATUS_FUNC_ID ((funcIdType_t) 0x00000014)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETUNSOLICITEDEVENTSETUP_FUNC_ID ((funcIdType_t) 0x00000015)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETUNSOLICITEDTLMSETUP_FUNC_ID ((funcIdType_t) 0x00000016)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETTELEMTRYLOGINCLUSIONMASKS_FUNC_ID ((funcIdType_t) 0x00000017)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETPASSTHROUGH_FUNCRESP_ID ((funcIdType_t) 0x00000000)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETPOWERSTATE_FUNCRESP_ID ((funcIdType_t) 0x00000001)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETIMAGETRANSFERSETUP_FUNCRESP_ID ((funcIdType_t) 0x00000002)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETIMAGEFILEINFORESET_FUNCRESP_ID ((funcIdType_t) 0x00000003)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETPORTMAP_FUNCRESP_ID ((funcIdType_t) 0x00000004)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETERASELOGDATA_FUNCRESP_ID ((funcIdType_t) 0x00000005)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETEVENTLOGFILTERTRANSFERSETUP_FUNCRESP_ID ((funcIdType_t) 0x00000006)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETTELEMETRYLOGTRANSFERSETUP_FUNCRESP_ID ((funcIdType_t) 0x00000007)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETDUMMYEVENT_FUNCRESP_ID ((funcIdType_t) 0x00000008)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETUNSOLICITEDEVENTSETUP_FUNCRESP_ID ((funcIdType_t) 0x00000009)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_SETUNSOLICITEDTLMSETUP_FUNCRESP_ID ((funcIdType_t) 0x0000000A)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETPASSTHROUGH_FUNCRESP_ID ((funcIdType_t) 0x0000000B)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETPOWERSTATE_FUNCRESP_ID ((funcIdType_t) 0x0000000C)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETPORTDIAGNOSTICS_FUNCRESP_ID ((funcIdType_t) 0x0000000D)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETPORTMAP_FUNCRESP_ID ((funcIdType_t) 0x0000000E)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETEXPECTEDNODES_FUNCRESP_ID ((funcIdType_t) 0x0000000F)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETIMAGETRANSFERSTATUS_FUNCRESP_ID ((funcIdType_t) 0x00000010)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETIMAGEFILEINFO_FUNCRESP_ID ((funcIdType_t) 0x00000011)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETCOMPONENTERRORCODES_FUNCRESP_ID ((funcIdType_t) 0x00000012)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETEVENTLOGSTATUS_FUNCRESP_ID ((funcIdType_t) 0x00000013)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETTELEMTRYLOGSTATUS_FUNCRESP_ID ((funcIdType_t) 0x00000014)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETUNSOLICITEDEVENTSETUP_FUNCRESP_ID ((funcIdType_t) 0x00000015)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETUNSOLICITEDTLMSETUP_FUNCRESP_ID ((funcIdType_t) 0x00000016)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_GETTELEMTRYLOGINCLUSIONMASKS_FUNCRESP_ID ((funcIdType_t) 0x00000017)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    No enumeration description provided by CubeSpace
*/
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_IMAGETRANSFEROPCODE_CaptureStore ((uint8_t) 0)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_IMAGETRANSFEROPCODE_CaptureDownload ((uint8_t) 1)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_IMAGETRANSFEROPCODE_Download ((uint8_t) 2)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_IMAGETRANSFEROPCODE_InfoReset ((uint8_t) 3)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_IMAGETRANSFEROPCODE_MAX_CNT  ((uint8_t) 4)
typedef uint8_t CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_ImageTransferOpCode_t;

/*
    No enumeration description provided by CubeSpace
*/
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FilterNone ((uint8_t) 0)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FilterTimeSpan ((uint8_t) 1)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FilterTimeNextX ((uint8_t) 2)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FilterFirstX ((uint8_t) 3)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FilterLastX ((uint8_t) 4)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FilterCounterNextX ((uint8_t) 5)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_MAX_CNT  ((uint8_t) 6)
typedef uint8_t CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_LogReadFilterType_t;

/*
    Return status type of the CubeADCS Gen2 API operations. Possible values are:
                         0 - No error
                         1 - NULL pointer
                         2 - Size incorrect
                         3 - Size too low
                         4 - Size too high
                         5 - Overrun
                         6 - Parameter error (out of range)
                         7 - Timeout
                         8 - TCTLM comms Nack
                         9 - Busy
                         10 - Frame
                         11 - CRC
                         12 - Read
                         13 - Write
                         14 - CAN ID type error
                         15 - CAN frame error
                         16 - Unknown NACK
                         17 - Invalid node type
                         18 - CubeSpace file upload internal error
                         19 - Usage error
                         20 - Auto-Discovery error
                         21 - Image error
                         22 - Does not exist error
                         23 - User data error
                         24 - Commit error
                         25 - TCTLM protocol error
                         26 - General unexpected/unknown error
                         27 - Telemetry response size error
                         28 - TCTLM response ID does not match the request
    
                         50 - TCTLM Nack - invalid ID
                         51 - TCTLM Nack - invalid length
                         52 - TCTLM Nack - invalid parameter data
                         53 - TCTLM Nack - CRC failed
                         54 - TCTLM Nack - not implemented
                         55 - TCTLM Nack - busy
                         56 - TCTLM Nack - sequence
                         57 - TCTLM Nack - internal
                         58 - TCTLM Nack - pass-through timeout
                         59 - TCTLM Nack - pass-through target
    
                         70 - CSP - receive timeout
                         71 - CSP - failed to acquire a buffer
    
                         65535 - Not implemented / TODO
*/
typedef int32_t CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t;

/*
    No enumeration description provided by CubeSpace
*/
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval200ms ((uint8_t) 0)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval1s ((uint8_t) 1)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval2s ((uint8_t) 2)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval3s ((uint8_t) 3)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval4s ((uint8_t) 4)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval5s ((uint8_t) 5)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval10s ((uint8_t) 6)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval20s ((uint8_t) 7)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval50s ((uint8_t) 8)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval100s ((uint8_t) 9)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_MAX_CNT  ((uint8_t) 10)
typedef uint8_t CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_TlmLogReturnIntervalValues_t;

/*
    Parameter structure for interface PortDiagnostics
*/
typedef struct {
    uint32_t u32GlobalErrorCode;
    bool bNoneExpected;
    bool bNoneDiscoveredError;
    bool bExpectedMatchError;
    bool bAddrAssignError;
    bool bAbstractTypeError;
    bool bConfigPersistError;
    uint32_t u32Sensor1ErrorCode;
    bool bSensor1UnexpectedError;
    bool bSensor1CommsError;
    bool bSensor1NodeTypeMatchError;
    bool bSensor1SerialMatchError;
    bool bSensor1AddrAssignError;
    bool bSensor1AbstractTypeError;
    bool bSensor1SerialResolveError;
    uint32_t u32Sensor2ErrorCode;
    bool bSensor2UnexpectedError;
    bool bSensor2CommsError;
    bool bSensor2NodeTypeMatchError;
    bool bSensor2SerialMatchError;
    bool bSensor2AddrAssignError;
    bool bSensor2AbstractTypeError;
    bool bSensor2SerialResolveError;
    uint32_t u32Sensor3ErrorCode;
    bool bSensor3UnexpectedError;
    bool bSensor3CommsError;
    bool bSensor3NodeTypeMatchError;
    bool bSensor3SerialMatchError;
    bool bSensor3AddrAssignError;
    bool bSensor3AbstractTypeError;
    bool bSensor3SerialResolveError;
    uint32_t u32Sensor4ErrorCode;
    bool bSensor4UnexpectedError;
    bool bSensor4CommsError;
    bool bSensor4NodeTypeMatchError;
    bool bSensor4SerialMatchError;
    bool bSensor4AddrAssignError;
    bool bSensor4AbstractTypeError;
    bool bSensor4SerialResolveError;
    uint32_t u32Sensor5ErrorCode;
    bool bSensor5UnexpectedError;
    bool bSensor5CommsError;
    bool bSensor5NodeTypeMatchError;
    bool bSensor5SerialMatchError;
    bool bSensor5AddrAssignError;
    bool bSensor5AbstractTypeError;
    bool bSensor5SerialResolveError;
    uint32_t u32Sensor6ErrorCode;
    bool bSensor6UnexpectedError;
    bool bSensor6CommsError;
    bool bSensor6NodeTypeMatchError;
    bool bSensor6SerialMatchError;
    bool bSensor6AddrAssignError;
    bool bSensor6AbstractTypeError;
    bool bSensor6SerialResolveError;
    uint32_t u32Sensor7ErrorCode;
    bool bSensor7UnexpectedError;
    bool bSensor7CommsError;
    bool bSensor7NodeTypeMatchError;
    bool bSensor7SerialMatchError;
    bool bSensor7AddrAssignError;
    bool bSensor7AbstractTypeError;
    bool bSensor7SerialResolveError;
    uint32_t u32Sensor8ErrorCode;
    bool bSensor8UnexpectedError;
    bool bSensor8CommsError;
    bool bSensor8NodeTypeMatchError;
    bool bSensor8SerialMatchError;
    bool bSensor8AddrAssignError;
    bool bSensor8AbstractTypeError;
    bool bSensor8SerialResolveError;
    uint32_t u32Wheel1ErrorCode;
    bool bWheel1UnexpectedError;
    bool bWheel1CommsError;
    bool bWheel1NodeTypeMatchError;
    bool bWheel1SerialMatchError;
    bool bWheel1AddrAssignError;
    bool bWheel1AbstractTypeError;
    bool bWheel1SerialResolveError;
    uint32_t u32Wheel2ErrorCode;
    bool bWheel2UnexpectedError;
    bool bWheel2CommsError;
    bool bWheel2NodeTypeMatchError;
    bool bWheel2SerialMatchError;
    bool bWheel2AddrAssignError;
    bool bWheel2AbstractTypeError;
    bool bWheel2SerialResolveError;
    uint32_t u32Wheel3ErrorCode;
    bool bWheel3UnexpectedError;
    bool bWheel3CommsError;
    bool bWheel3NodeTypeMatchError;
    bool bWheel3SerialMatchError;
    bool bWheel3AddrAssignError;
    bool bWheel3AbstractTypeError;
    bool bWheel3SerialResolveError;
    uint32_t u32Wheel4ErrorCode;
    bool bWheel4UnexpectedError;
    bool bWheel4CommsError;
    bool bWheel4NodeTypeMatchError;
    bool bWheel4SerialMatchError;
    bool bWheel4AddrAssignError;
    bool bWheel4AbstractTypeError;
    bool bWheel4SerialResolveError;
} PACKED_STRUCT CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PortDiagnostics_t;

/*
    No enumeration description provided by CubeSpace
*/
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_EVENTCLASS_EventClassInfo ((uint8_t) 0)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_EVENTCLASS_EventClassWarningMinor ((uint8_t) 1)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_EVENTCLASS_EventClassWarningMajor ((uint8_t) 2)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_EVENTCLASS_EventClassCritical ((uint8_t) 3)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_EVENTCLASS_MAX_CNT  ((uint8_t) 4)
typedef uint8_t CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_EventClass_t;

/*
    No enumeration description provided by CubeSpace
*/
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeInvalid ((uint8_t) 0)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeComputer ((uint8_t) 1)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeSense ((uint8_t) 2)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeWheel ((uint8_t) 3)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeIr ((uint8_t) 4)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeMagDeploy ((uint8_t) 5)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeMagCompact ((uint8_t) 6)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeStar ((uint8_t) 7)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeAuriga ((uint8_t) 8)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeNode ((uint8_t) 9)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeNodeSlt ((uint8_t) 10)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeNodePst3s ((uint8_t) 11)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeNodeNssrwl ((uint8_t) 12)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeNodeQuad ((uint8_t) 16)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeNodeQuadPst3s ((uint8_t) 17)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeNodeQuadNssrwl ((uint8_t) 18)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeNodeQuadLitefufors ((uint8_t) 19)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_MAX_CNT  ((uint8_t) 20)
typedef uint8_t CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t;

/*
    No enumeration description provided by CubeSpace
*/
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_POWERSELECT_PowerOff ((uint8_t) 0)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_POWERSELECT_PowerOn ((uint8_t) 1)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_POWERSELECT_PowerNoChange ((uint8_t) 2)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_POWERSELECT_PowerAuto ((uint8_t) 3)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_POWERSELECT_PowerOnPass ((uint8_t) 4)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_POWERSELECT_PowerOffUpgrade ((uint8_t) 5)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_POWERSELECT_MAX_CNT  ((uint8_t) 6)
typedef uint8_t CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t;

/*
    No enumeration description provided by CubeSpace
*/
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_ERASEMAGICNUMBERS_EraseTlmLog ((uint8_t) 57)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_ERASEMAGICNUMBERS_EraseEventLog ((uint8_t) 117)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_ERASEMAGICNUMBERS_EraseImageLog ((uint8_t) 195)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_ERASEMAGICNUMBERS_MAX_CNT  ((uint8_t) 196)
typedef uint8_t CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_EraseMagicNumbers_t;

/*
    Parameter structure for interface ComponentErrorCodes
*/
typedef struct {
    uint32_t u32MasterSvc;
    uint32_t u32FramFsSvc;
    uint32_t u32EventLogSvc;
    uint32_t u32ImgLogSvc;
    uint32_t u32TlmLogSvc;
    uint32_t u32ImuSvc;
} PACKED_STRUCT CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ComponentErrorCodes_t;

/*
    No enumeration description provided by CubeSpace
*/
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TlmReadQIdle ((uint8_t) 0)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TlmReadQDownload ((uint8_t) 1)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TlmReadQErase ((uint8_t) 2)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_MAX_CNT  ((uint8_t) 3)
typedef uint8_t CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_TlmLogReadQueueState_t;

/*
    Parameter structure for interface TelemtryLogInclusionMasks
*/
typedef struct {
    uint8_t au8FastBitMask[5];
    uint8_t au8SlowBitMask[5];
} PACKED_STRUCT CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemtryLogInclusionMasks_t;

/*
    No enumeration description provided by CubeSpace
*/
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeInvalid ((uint8_t) 0)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeComputer ((uint8_t) 1)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeStr0 ((uint8_t) 2)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeStr1 ((uint8_t) 3)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeFss0 ((uint8_t) 4)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeFss1 ((uint8_t) 5)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeFss2 ((uint8_t) 6)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeFss3 ((uint8_t) 7)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeHss0 ((uint8_t) 8)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeHss1 ((uint8_t) 9)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeMag0 ((uint8_t) 10)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeMag1 ((uint8_t) 11)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeExt0 ((uint8_t) 12)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeExt1 ((uint8_t) 13)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeRwl0 ((uint8_t) 14)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeRwl1 ((uint8_t) 15)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeRwl2 ((uint8_t) 16)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeRwl3 ((uint8_t) 17)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeRwl4 ((uint8_t) 18)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeExtGyr0 ((uint8_t) 19)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeExtGyr1 ((uint8_t) 20)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeCq0 ((uint8_t) 21)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeCq1 ((uint8_t) 22)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeCq2 ((uint8_t) 23)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeCq3 ((uint8_t) 24)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_MAX_CNT  ((uint8_t) 25)
typedef uint8_t CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t;

/*
    No enumeration description provided by CubeSpace
*/
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_StateIdle ((uint8_t) 0)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_StateBusyStore ((uint8_t) 1)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_StateBusyDownload ((uint8_t) 2)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_MAX_CNT  ((uint8_t) 3)
typedef uint8_t CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_ImageTransferState_t;

/*
    This enumeration holds the IDs of CubeADCS Gen2 nodes for which this interface is applicable.
*/
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CMDTARGETNODE_NodeInvalid ((uint8_t) 0)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CMDTARGETNODE_NodeComputer ((uint8_t) 1)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CMDTARGETNODE_MAX_CNT  ((uint8_t) 2)
typedef uint8_t CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t;

/*
    Parameter structure for interface UnsolicitedEventSetup
*/
typedef struct {
    bool bUartInfo;
    bool bUartWarnMinor;
    bool bUartWarnMajor;
    bool bUartCritical;
    bool bUart2Info;
    bool bUart2WarnMinor;
    bool bUart2WarnMajor;
    bool bUart2Critical;
    bool bCanInfo;
    bool bCanWarnMinor;
    bool bCanWarnMajor;
    bool bCanCritical;
} PACKED_STRUCT CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedEventSetup_t;

/*
    No enumeration description provided by CubeSpace
*/
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_EvtReadQIdle ((uint8_t) 0)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_EvtReadQDownload ((uint8_t) 1)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_EvtReadQErase ((uint8_t) 2)
#define CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_MAX_CNT  ((uint8_t) 3)
typedef uint8_t CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_EventReadQueueState_t;

/*
    Parameter structure for interface EventLogFilterTransferSetup
*/
typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_LogReadFilterType_t eFilterType;
    uint32_t u32StartTimeUnix;
    uint32_t u32EndTimeUnix;
    uint32_t u32NumEntries;
    uint32_t u32WriteCounter;
    bool bIncludeClassCritical;
    bool bIncludeClassMajorWarning;
    bool bIncludeClassMinorWarning;
    bool bIncludeClassInfo;
    bool bIncludeSourceCubeComputer;
    bool bIncludeSourceRwl0;
    bool bIncludeSourceRwl1;
    bool bIncludeSourceRwl2;
    bool bIncludeSourceRwl3;
    bool bIncludeSourceFss0;
    bool bIncludeSourceFss1;
    bool bIncludeSourceFss2;
    bool bIncludeSourceFss3;
    bool bIncludeSourceHss0;
    bool bIncludeSourceHss1;
    bool bIncludeSourceStr0;
    bool bIncludeSourceStr1;
    bool bIncludeSourceMag0;
    bool bIncludeSourceMag1;
    bool bIncludeSourceExt0;
    bool bIncludeSourceExt1;
} PACKED_STRUCT CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EventLogFilterTransferSetup_t;

/*
    Parameter structure for interface TelemetryLogTransferSetup
*/
typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_LogReadFilterType_t eFilterType;
    uint32_t u32StartTimeUnix;
    uint32_t u32EndTimeUnix;
    uint32_t u32NumEntries;
    uint32_t u32WriteCounter;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_TlmLogReturnIntervalValues_t eTlmLogReturnInterval;
    uint8_t au8LogIdBitmask[5];
} PACKED_STRUCT CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemetryLogTransferSetup_t;

/*
    Parameter structure for interface UnsolicitedTlmSetup
*/
typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_TlmLogReturnIntervalValues_t eUartTlmInterval;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_TlmLogReturnIntervalValues_t eUart2TlmInterval;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_TlmLogReturnIntervalValues_t eCanTlmInterval;
    uint8_t au8UartTlmIdBitmask[5];
    uint8_t au8Uart2TlmIdBitmask[5];
    uint8_t au8CanTlmIdBitmask[5];
} PACKED_STRUCT CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedTlmSetup_t;

/*
    Parameter structure for interface PowerState
*/
typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eRwl0Power;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eRwl1Power;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eRwl2Power;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eRwl3Power;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eMag0Power;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eMag1Power;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eGyro0Power;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eGyro1Power;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eFss0Power;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eFss1Power;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eFss2Power;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eFss3Power;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eHss0Power;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eHss1Power;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eStr0Power;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eStr1Power;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eExtSensor0Power;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eExtSensor1Power;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eExtGyro0Power;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_PowerSelect_t eExtGyro1Power;
} PACKED_STRUCT CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PowerState_t;

/*
    Parameter structure for interface EraseLogData
*/
typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_EraseMagicNumbers_t eMagicNumber;
} PACKED_STRUCT CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EraseLogData_t;

/*
    Parameter structure for interface TelemtryLogStatus
*/
typedef struct {
    uint8_t u8NumberOfEntriesQueued;
    uint8_t u8NumberOfTlmIterations;
    uint32_t u32NumberOfEntries;
    uint32_t u32OldestEntryUnix;
    uint32_t u32LatestEntryUnix;
    uint32_t u32WriteCounter;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_TlmLogReadQueueState_t eReadQueueState;
} PACKED_STRUCT CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemtryLogStatus_t;

/*
    Parameter structure for interface PortMap
*/
typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eSensor1NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eSensor1AbstractType;
    uint32_t u32Sensor1SerialInt;
    uint32_t u32Sensor1Address;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eSensor2NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eSensor2AbstractType;
    uint32_t u32Sensor2SerialInt;
    uint32_t u32Sensor2Address;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eSensor3NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eSensor3AbstractType;
    uint32_t u32Sensor3SerialInt;
    uint32_t u32Sensor3Address;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eSensor4NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eSensor4AbstractType;
    uint32_t u32Sensor4SerialInt;
    uint32_t u32Sensor4Address;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eSensor5NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eSensor5AbstractType;
    uint32_t u32Sensor5SerialInt;
    uint32_t u32Sensor5Address;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eSensor6NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eSensor6AbstractType;
    uint32_t u32Sensor6SerialInt;
    uint32_t u32Sensor6Address;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eSensor7NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eSensor7AbstractType;
    uint32_t u32Sensor7SerialInt;
    uint32_t u32Sensor7Address;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eSensor8NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eSensor8AbstractType;
    uint32_t u32Sensor8SerialInt;
    uint32_t u32Sensor8Address;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eWheel1NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eWheel1AbstractType;
    uint32_t u32Wheel1SerialInt;
    uint32_t u32Wheel1Address;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eWheel2NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eWheel2AbstractType;
    uint32_t u32Wheel2SerialInt;
    uint32_t u32Wheel2Address;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eWheel3NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eWheel3AbstractType;
    uint32_t u32Wheel3SerialInt;
    uint32_t u32Wheel3Address;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eWheel4NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eWheel4AbstractType;
    uint32_t u32Wheel4SerialInt;
    uint32_t u32Wheel4Address;
} PACKED_STRUCT CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PortMap_t;

/*
    Parameter structure for interface ImageFileInfo
*/
typedef struct {
    uint32_t u32FileHandle;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eNodeType;
    uint32_t u32Timestamp;
    uint32_t u32Size;
    bool bFirst;
    bool bLast;
    bool bIsValid;
} PACKED_STRUCT CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageFileInfo_t;

/*
    Parameter structure for interface ImageTransferSetup
*/
typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_ImageTransferOpCode_t eOpCode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eNodeType;
    uint32_t u32FileHandle;
} PACKED_STRUCT CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageTransferSetup_t;

/*
    Parameter structure for interface PassThrough
*/
typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eTargetNode;
} PACKED_STRUCT CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PassThrough_t;

/*
    Parameter structure for interface DummyEvent
*/
typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_EventClass_t eEventClass;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eEventSource;
    uint16_t u16EventType;
    uint8_t au8EventData[8];
} PACKED_STRUCT CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_DummyEvent_t;

/*
    Parameter structure for interface ExpectedNodes
*/
typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eExpected0NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eExpected0AbstractType;
    uint32_t u32Expected0SerialInt;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eExpected1NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eExpected1AbstractType;
    uint32_t u32Expected1SerialInt;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eExpected2NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eExpected2AbstractType;
    uint32_t u32Expected2SerialInt;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eExpected3NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eExpected3AbstractType;
    uint32_t u32Expected3SerialInt;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eExpected4NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eExpected4AbstractType;
    uint32_t u32Expected4SerialInt;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eExpected5NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eExpected5AbstractType;
    uint32_t u32Expected5SerialInt;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eExpected6NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eExpected6AbstractType;
    uint32_t u32Expected6SerialInt;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eExpected7NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eExpected7AbstractType;
    uint32_t u32Expected7SerialInt;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eExpected8NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eExpected8AbstractType;
    uint32_t u32Expected8SerialInt;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eExpected9NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eExpected9AbstractType;
    uint32_t u32Expected9SerialInt;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eExpected10NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eExpected10AbstractType;
    uint32_t u32Expected10SerialInt;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_NodeType_t eExpected11NodeType;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CommonFrameworkTypes1_AbstractNode_t eExpected11AbstractType;
    uint32_t u32Expected11SerialInt;
} PACKED_STRUCT CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ExpectedNodes_t;

/*
    Parameter structure for interface ImageTransferStatus
*/
typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_ImageTransferState_t eState;
    uint32_t u32ErrorCode;
    uint32_t u32TransferSize;
    uint32_t u32DataRemain;
    bool bInvalidNodeError;
    bool bTimeoutError;
    bool bCaptureError;
    bool bSetupError;
    bool bFileOpenReadError;
    bool bFileOpenWriteError;
    bool bFileReadError;
    bool bFileWriteError;
    bool bBusyError;
} PACKED_STRUCT CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageTransferStatus_t;

/*
    Parameter structure for interface EventLogStatus
*/
typedef struct {
    uint16_t u16NumberOfEntriesQueued;
    uint16_t u16NumberOfEntriesBuffered;
    uint32_t u32NumberOfEntries;
    uint32_t u32NumberOfEmptyEntries;
    uint32_t u32OldestEntryUnix;
    uint32_t u32LatestEntryUnix;
    uint32_t u32NumberOfCriticalEvents;
    uint32_t u32NumberOfMajorWarningEvents;
    uint32_t u32NumberOfMinorWarningEvents;
    uint32_t u32NumberOfInfoEvents;
    uint32_t u32WriteCounter;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CubeComputerCommon3_EventReadQueueState_t eReadQueueState;
} PACKED_STRUCT CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EventLogStatus_t;


typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PassThrough_t sSetVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setPassThroughRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PowerState_t sSetVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setPowerStateRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageTransferSetup_t sSetVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setImageTransferSetupRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setImageFileInfoResetRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PortMap_t sSetVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setPortMapRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EraseLogData_t sSetVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setEraseLogDataRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EventLogFilterTransferSetup_t sSetVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setEventLogFilterTransferSetupRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemetryLogTransferSetup_t sSetVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setTelemetryLogTransferSetupRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_DummyEvent_t sSetVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setDummyEventRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedEventSetup_t sSetVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setUnsolicitedEventSetupRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedTlmSetup_t sSetVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setUnsolicitedTlmSetupRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getPassThroughRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getPowerStateRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getPortDiagnosticsRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getPortMapRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getExpectedNodesRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getImageTransferStatusRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getImageFileInfoRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getComponentErrorCodesRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getEventLogStatusRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getTelemtryLogStatusRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getUnsolicitedEventSetupRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getUnsolicitedTlmSetupRequestData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CmdTargetNode_t eCmdTargetNode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getTelemtryLogInclusionMasksRequestData_t;


typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setPassThroughResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setPowerStateResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setImageTransferSetupResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setImageFileInfoResetResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setPortMapResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setEraseLogDataResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setEventLogFilterTransferSetupResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setTelemetryLogTransferSetupResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setDummyEventResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setUnsolicitedEventSetupResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3setUnsolicitedTlmSetupResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PassThrough_t sReturnVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getPassThroughResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PowerState_t sReturnVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getPowerStateResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PortDiagnostics_t sReturnVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getPortDiagnosticsResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PortMap_t sReturnVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getPortMapResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ExpectedNodes_t sReturnVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getExpectedNodesResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageTransferStatus_t sReturnVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getImageTransferStatusResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageFileInfo_t sReturnVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getImageFileInfoResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ComponentErrorCodes_t sReturnVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getComponentErrorCodesResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EventLogStatus_t sReturnVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getEventLogStatusResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemtryLogStatus_t sReturnVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getTelemtryLogStatusResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedEventSetup_t sReturnVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getUnsolicitedEventSetupResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedTlmSetup_t sReturnVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getUnsolicitedTlmSetupResponseData_t;

typedef struct {
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_AdcsErrorCode_t tAdcsErrorCode;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemtryLogInclusionMasks_t sReturnVal;
} PACKED_STRUCT CubeADCS_Gen2_CubeComputerCommon3getTelemtryLogInclusionMasksResponseData_t;


#endif  // #ifndef FP_CUBEADCS_GEN2_CUBECOMPUTERCOMMON3PROTOCOLTYPES_H

