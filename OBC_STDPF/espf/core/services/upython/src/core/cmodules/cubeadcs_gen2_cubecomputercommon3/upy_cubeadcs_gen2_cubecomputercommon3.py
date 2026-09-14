# ********************************************************************************************
# * @file upy_cubeadcs_gen2_cubecomputercommon3.py
# * @brief uPy dummy Python module generator
# ********************************************************************************************
# * @version           interface CubeADCS_Gen2_CubeComputerCommon3 v6.0
# *
# * @copyright         (C) Copyright EnduroSat
# *
# *                    Contents and presentations are protected world-wide.
# *                    Any kind of using, copying etc. is prohibited without prior permission.
# *                    All rights - incl. industrial property rights - are reserved.
# *
# *-------------------------------------------------------------------------------------------
# * GENERATOR: org.endurosat.generators.macchiato.binders.Gen_uPy v0.8
# *-------------------------------------------------------------------------------------------
# * !!! Please note that this code is fully GENERATED and shall not be manually modified as
# * all changes will be overwritten !!!
# ********************************************************************************************

from enum import IntEnum

# ********************************************************************************************
#
# Enumeration classes
#
# ********************************************************************************************
class CubeComputerCommon3_ImageTransferOpCode(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerCommon3_ImageTransferOpCode'
    """
    # Capture an image from the target node and store it on CubeComputer
    CUBECOMPUTERCOMMON3_IMAGETRANSFEROPCODE_CAPTURESTORE = 0
    # Capture an image from the target node and immediately download it without storing it on CubeComputer
    CUBECOMPUTERCOMMON3_IMAGETRANSFEROPCODE_CAPTUREDOWNLOAD = 0
    # Download an image stored on CubeComputer
    CUBECOMPUTERCOMMON3_IMAGETRANSFEROPCODE_DOWNLOAD = 0
    # Reset the file info request to start from the first image file
    CUBECOMPUTERCOMMON3_IMAGETRANSFEROPCODE_INFORESET = 0
class CubeComputerCommon3_LogReadFilterType(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerCommon3_LogReadFilterType'
    """
    # Include all entries
    CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FILTERNONE = 0
    # Filter/read entries logged between two timestamps
    CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FILTERTIMESPAN = 0
    # Filter/read the next x entries logged following the sepecifed start timestamp
    CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FILTERTIMENEXTX = 0
    # Filter/read the first x entries logged
    CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FILTERFIRSTX = 0
    # Filter/read the last x entries logged
    CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FILTERLASTX = 0
    # Filter/read the next x entries logged following the specified write counter
    CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FILTERCOUNTERNEXTX = 0
class CubeComputerCommon3_TlmLogReturnIntervalValues(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerCommon3_TlmLogReturnIntervalValues'
    """
    # Apply 200ms return interval
    CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL200MS = 0
    # Apply 1s return interval
    CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL1S = 0
    # Apply 2s return interval
    CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL2S = 0
    # Apply 3s return interval
    CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL3S = 0
    # Apply 4s return interval
    CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL4S = 0
    # Apply 5s return interval
    CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL5S = 0
    # Apply 10s return interval
    CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL10S = 0
    # Apply 20s return interval
    CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL20S = 0
    # Apply 50s return interval
    CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL50S = 0
    # Apply 100s return interval
    CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL100S = 0
class CubeComputerCommon3_EventClass(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerCommon3_EventClass'
    """
    # Event class info
    CUBECOMPUTERCOMMON3_EVENTCLASS_EVENTCLASSINFO = 0
    # Event class warning minor
    CUBECOMPUTERCOMMON3_EVENTCLASS_EVENTCLASSWARNINGMINOR = 0
    # Event class warning major
    CUBECOMPUTERCOMMON3_EVENTCLASS_EVENTCLASSWARNINGMAJOR = 0
    # Event class critical
    CUBECOMPUTERCOMMON3_EVENTCLASS_EVENTCLASSCRITICAL = 0
class CommonFrameworkTypes1_NodeType(IntEnum):
    """
    Enumeration class definition for type 'CommonFrameworkTypes1_NodeType'
    """
    # Invalid Node Type
    COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPEINVALID = 0
    # CubeComputer Type - version independant
    COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBECOMPUTER = 0
    # CubeSense Type - version independant
    COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBESENSE = 0
    # CubeWheel Type - version independant
    COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBEWHEEL = 0
    # CubeIR Type - version independant
    COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBEIR = 0
    # CubeMag Deploy Type - version independant
    COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBEMAGDEPLOY = 0
    # CubeMag Compact Type - version independant
    COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBEMAGCOMPACT = 0
    # CubeStar Type - version independant
    COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBESTAR = 0
    # CubeAuriga Type - version independant
    COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBEAURIGA = 0
    # CubeNode General Type - version independant
    COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBENODE = 0
    # CubeNode SLT Type - version independant
    COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBENODESLT = 0
    # CubeNode PST3S Type - version independant
    COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBENODEPST3S = 0
    # CubeNode NSSRWL Type - version independant
    COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBENODENSSRWL = 0
    # CubeNodeQuad General Type - version independant
    COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBENODEQUAD = 0
    # CubeNodeQuad PST3S Type - version independant
    COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBENODEQUADPST3S = 0
    # CubeNodeQuad NSSRWL Type - version independant
    COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBENODEQUADNSSRWL = 0
    # CubeNodeQuad LITEFUFORS Type - version independant
    COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBENODEQUADLITEFUFORS = 0
class CubeComputerCommon3_PowerSelect(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerCommon3_PowerSelect'
    """
    # Off
    CUBECOMPUTERCOMMON3_POWERSELECT_POWEROFF = 0
    # On
    CUBECOMPUTERCOMMON3_POWERSELECT_POWERON = 0
    # NoChange
    CUBECOMPUTERCOMMON3_POWERSELECT_POWERNOCHANGE = 0
    # Auto
    CUBECOMPUTERCOMMON3_POWERSELECT_POWERAUTO = 0
    # On - Passthrough Only (No ADCS operations)
    CUBECOMPUTERCOMMON3_POWERSELECT_POWERONPASS = 0
    # Power off for upgrade (internal use only)
    CUBECOMPUTERCOMMON3_POWERSELECT_POWEROFFUPGRADE = 0
class CubeComputerCommon3_EraseMagicNumbers(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerCommon3_EraseMagicNumbers'
    """
    # Erase the Telemetry log
    CUBECOMPUTERCOMMON3_ERASEMAGICNUMBERS_ERASETLMLOG = 0
    # Erase the Event log
    CUBECOMPUTERCOMMON3_ERASEMAGICNUMBERS_ERASEEVENTLOG = 0
    # Erase the Image log
    CUBECOMPUTERCOMMON3_ERASEMAGICNUMBERS_ERASEIMAGELOG = 0
class CubeComputerCommon3_TlmLogReadQueueState(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerCommon3_TlmLogReadQueueState'
    """
    # Idle
    CUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TLMREADQIDLE = 0
    # Telemetry log download in progress
    CUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TLMREADQDOWNLOAD = 0
    # Telemetry log erase is progress
    CUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TLMREADQERASE = 0
class CommonFrameworkTypes1_AbstractNode(IntEnum):
    """
    Enumeration class definition for type 'CommonFrameworkTypes1_AbstractNode'
    """
    # Invalid Abstract Node
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEINVALID = 0
    # CubeComputer
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODECOMPUTER = 0
    # Star tracker 0
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODESTR0 = 0
    # Star tracker 1
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODESTR1 = 0
    # Fine sun sensor 0
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEFSS0 = 0
    # Fine sun sensor 1
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEFSS1 = 0
    # Fine sun sensor 2
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEFSS2 = 0
    # Fine sun sensor 3
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEFSS3 = 0
    # Horizon sun sensor 0
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEHSS0 = 0
    # Horizon sun sensor 1
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEHSS1 = 0
    # Magnetometer sensor 0
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEMAG0 = 0
    # Magnetometer sensor 1
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEMAG1 = 0
    # External sensor 0
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEEXT0 = 0
    # External sensor 1
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEEXT1 = 0
    # Reaction wheel 0
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODERWL0 = 0
    # Reaction wheel 1
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODERWL1 = 0
    # Reaction wheel 2
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODERWL2 = 0
    # Reaction wheel 3
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODERWL3 = 0
    # Reaction wheel 4
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODERWL4 = 0
    # External gyro 0
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEEXTGYR0 = 0
    # External gyro 1
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEEXTGYR1 = 0
    # CubeNode-Quad 0 (internal/reporting use only)
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODECQ0 = 0
    # CubeNode-Quad 1 (internal/reporting use only)
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODECQ1 = 0
    # CubeNode-Quad 2 (internal/reporting use only)
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODECQ2 = 0
    # CubeNode-Quad 3 (internal/reporting use only)
    COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODECQ3 = 0
class CubeComputerCommon3_ImageTransferState(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerCommon3_ImageTransferState'
    """
    # Idle
    CUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_STATEIDLE = 0
    # Node image is being sttored internally on CubeComputer
    CUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_STATEBUSYSTORE = 0
    # Node image is being downloaded from CubeComputer. This state applies to both direct downloads and downloads from storage
    CUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_STATEBUSYDOWNLOAD = 0
class CmdTargetNode(IntEnum):
    """
    Enumeration class definition for type 'CmdTargetNode'
    """
    CMDTARGETNODE_NODEINVALID = 0
    CMDTARGETNODE_NODECOMPUTER = 0
class CubeComputerCommon3_EventReadQueueState(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerCommon3_EventReadQueueState'
    """
    # Idle
    CUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_EVTREADQIDLE = 0
    # Event log download in progress
    CUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_EVTREADQDOWNLOAD = 0
    # Event log erase is progress
    CUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_EVTREADQERASE = 0


# ********************************************************************************************
#
# Struct classes
#
# ********************************************************************************************
class PortDiagnostics:
    """
    A Python class to represent struct objects of type 'PortDiagnostics'
    
    Parameter structure for interface PortDiagnostics
    """

    def __init__(self, uint32__GlobalErrorCode : int, bool__NoneExpected : int, bool__NoneDiscoveredError : int, bool__ExpectedMatchError : int, bool__AddrAssignError : int, bool__AbstractTypeError : int, bool__ConfigPersistError : int, uint32__Sensor1ErrorCode : int, bool__Sensor1UnexpectedError : int, bool__Sensor1CommsError : int, bool__Sensor1NodeTypeMatchError : int, bool__Sensor1SerialMatchError : int, bool__Sensor1AddrAssignError : int, bool__Sensor1AbstractTypeError : int, bool__Sensor1SerialResolveError : int, uint32__Sensor2ErrorCode : int, bool__Sensor2UnexpectedError : int, bool__Sensor2CommsError : int, bool__Sensor2NodeTypeMatchError : int, bool__Sensor2SerialMatchError : int, bool__Sensor2AddrAssignError : int, bool__Sensor2AbstractTypeError : int, bool__Sensor2SerialResolveError : int, uint32__Sensor3ErrorCode : int, bool__Sensor3UnexpectedError : int, bool__Sensor3CommsError : int, bool__Sensor3NodeTypeMatchError : int, bool__Sensor3SerialMatchError : int, bool__Sensor3AddrAssignError : int, bool__Sensor3AbstractTypeError : int, bool__Sensor3SerialResolveError : int, uint32__Sensor4ErrorCode : int, bool__Sensor4UnexpectedError : int, bool__Sensor4CommsError : int, bool__Sensor4NodeTypeMatchError : int, bool__Sensor4SerialMatchError : int, bool__Sensor4AddrAssignError : int, bool__Sensor4AbstractTypeError : int, bool__Sensor4SerialResolveError : int, uint32__Sensor5ErrorCode : int, bool__Sensor5UnexpectedError : int, bool__Sensor5CommsError : int, bool__Sensor5NodeTypeMatchError : int, bool__Sensor5SerialMatchError : int, bool__Sensor5AddrAssignError : int, bool__Sensor5AbstractTypeError : int, bool__Sensor5SerialResolveError : int, uint32__Sensor6ErrorCode : int, bool__Sensor6UnexpectedError : int, bool__Sensor6CommsError : int, bool__Sensor6NodeTypeMatchError : int, bool__Sensor6SerialMatchError : int, bool__Sensor6AddrAssignError : int, bool__Sensor6AbstractTypeError : int, bool__Sensor6SerialResolveError : int, uint32__Sensor7ErrorCode : int, bool__Sensor7UnexpectedError : int, bool__Sensor7CommsError : int, bool__Sensor7NodeTypeMatchError : int, bool__Sensor7SerialMatchError : int, bool__Sensor7AddrAssignError : int, bool__Sensor7AbstractTypeError : int, bool__Sensor7SerialResolveError : int, uint32__Sensor8ErrorCode : int, bool__Sensor8UnexpectedError : int, bool__Sensor8CommsError : int, bool__Sensor8NodeTypeMatchError : int, bool__Sensor8SerialMatchError : int, bool__Sensor8AddrAssignError : int, bool__Sensor8AbstractTypeError : int, bool__Sensor8SerialResolveError : int, uint32__Wheel1ErrorCode : int, bool__Wheel1UnexpectedError : int, bool__Wheel1CommsError : int, bool__Wheel1NodeTypeMatchError : int, bool__Wheel1SerialMatchError : int, bool__Wheel1AddrAssignError : int, bool__Wheel1AbstractTypeError : int, bool__Wheel1SerialResolveError : int, uint32__Wheel2ErrorCode : int, bool__Wheel2UnexpectedError : int, bool__Wheel2CommsError : int, bool__Wheel2NodeTypeMatchError : int, bool__Wheel2SerialMatchError : int, bool__Wheel2AddrAssignError : int, bool__Wheel2AbstractTypeError : int, bool__Wheel2SerialResolveError : int, uint32__Wheel3ErrorCode : int, bool__Wheel3UnexpectedError : int, bool__Wheel3CommsError : int, bool__Wheel3NodeTypeMatchError : int, bool__Wheel3SerialMatchError : int, bool__Wheel3AddrAssignError : int, bool__Wheel3AbstractTypeError : int, bool__Wheel3SerialResolveError : int, uint32__Wheel4ErrorCode : int, bool__Wheel4UnexpectedError : int, bool__Wheel4CommsError : int, bool__Wheel4NodeTypeMatchError : int, bool__Wheel4SerialMatchError : int, bool__Wheel4AddrAssignError : int, bool__Wheel4AbstractTypeError : int, bool__Wheel4SerialResolveError : int) -> None:
        """
        Struct 'PortDiagnostics' constructor
        
        Attributes
        ---------
        uint32__GlobalErrorCode [1] : int
            Global Error Code for Port Interface Operations. Signaling an error with at least one of the ports.
        bool__NoneExpected [1] : int
            Set if the expected nodes configuration is empty.
        bool__NoneDiscoveredError [1] : int
            Set if no nodes have been discovered. Please ensure nodes are connected
        bool__ExpectedMatchError [1] : int
            Set if the nodes that have been discovered do not match the expected nodes. Please read all port parameters to diagnose.
        bool__AddrAssignError [1] : int
            Set if a CAN address could not be assigned to a node. Please read all port parameters to diagnose.
        bool__AbstractTypeError [1] : int
            Set if an abstract node type could not be resolved. Typically due to an unsupported number of a specific type of node being discovered. Please read all port parameters to diagnose.
        bool__ConfigPersistError [1] : int
            Set if the discovered nodes could not be written to flash.
        uint32__Sensor1ErrorCode [1] : int
            Sensor 1 port - Error Code for Port Interface Operations.
        bool__Sensor1UnexpectedError [1] : int
            Sensor 1 port - Set if the node discovered on this port is not listed as an expected node.
        bool__Sensor1CommsError [1] : int
            Sensor 1 port - Set if a communications error ocurred.
        bool__Sensor1NodeTypeMatchError [1] : int
            Sensor 1 port - Set if the previously discovered node type no longer matches the node connected to the port.
        bool__Sensor1SerialMatchError [1] : int
            Sensor 1 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        bool__Sensor1AddrAssignError [1] : int
            Sensor 1 port - Set if this port could not be assigned a CAN address.
        bool__Sensor1AbstractTypeError [1] : int
            Sensor 1 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        bool__Sensor1SerialResolveError [1] : int
            Sensor 1 port - Set if the serial number returned by the node could not be resolved to a node type.
        uint32__Sensor2ErrorCode [1] : int
            Sensor 2 port - Error Code for Port Interface Operations.
        bool__Sensor2UnexpectedError [1] : int
            Sensor 2 port - Set if the node discovered on this port is not listed as an expected node.
        bool__Sensor2CommsError [1] : int
            Sensor 2 port - Set if a communications error ocurred.
        bool__Sensor2NodeTypeMatchError [1] : int
            Sensor 2 port - Set if the previously discovered node type no longer matches the node connected to the port.
        bool__Sensor2SerialMatchError [1] : int
            Sensor 2 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        bool__Sensor2AddrAssignError [1] : int
            Sensor 2 port - Set if this port could not be assigned a CAN address.
        bool__Sensor2AbstractTypeError [1] : int
            Sensor 2 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        bool__Sensor2SerialResolveError [1] : int
            Sensor 2 port - Set if the serial number returned by the node could not be resolved to a node type.
        uint32__Sensor3ErrorCode [1] : int
            Sensor 3 port - Error Code for Port Interface Operations.
        bool__Sensor3UnexpectedError [1] : int
            Sensor 3 port - Set if the node discovered on this port is not listed as an expected node.
        bool__Sensor3CommsError [1] : int
            Sensor 3 port - Set if a communications error ocurred.
        bool__Sensor3NodeTypeMatchError [1] : int
            Sensor 3 port - Set if the previously discovered node type no longer matches the node connected to the port.
        bool__Sensor3SerialMatchError [1] : int
            Sensor 3 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        bool__Sensor3AddrAssignError [1] : int
            Sensor 3 port - Set if this port could not be assigned a CAN address.
        bool__Sensor3AbstractTypeError [1] : int
            Sensor 3 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        bool__Sensor3SerialResolveError [1] : int
            Sensor 3 port - Set if the serial number returned by the node could not be resolved to a node type.
        uint32__Sensor4ErrorCode [1] : int
            Sensor 4 port - Error Code for Port Interface Operations.
        bool__Sensor4UnexpectedError [1] : int
            Sensor 4 port - Set if the node discovered on this port is not listed as an expected node.
        bool__Sensor4CommsError [1] : int
            Sensor 4 port - Set if a communications error ocurred.
        bool__Sensor4NodeTypeMatchError [1] : int
            Sensor 4 port - Set if the previously discovered node type no longer matches the node connected to the port.
        bool__Sensor4SerialMatchError [1] : int
            Sensor 4 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        bool__Sensor4AddrAssignError [1] : int
            Sensor 4 port - Set if this port could not be assigned a CAN address.
        bool__Sensor4AbstractTypeError [1] : int
            Sensor 4 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        bool__Sensor4SerialResolveError [1] : int
            Sensor 4 port - Set if the serial number returned by the node could not be resolved to a node type.
        uint32__Sensor5ErrorCode [1] : int
            Sensor 5 port - Error Code for Port Interface Operations.
        bool__Sensor5UnexpectedError [1] : int
            Sensor 5 port - Set if the node discovered on this port is not listed as an expected node.
        bool__Sensor5CommsError [1] : int
            Sensor 5 port - Set if a communications error ocurred.
        bool__Sensor5NodeTypeMatchError [1] : int
            Sensor 5 port - Set if the previously discovered node type no longer matches the node connected to the port.
        bool__Sensor5SerialMatchError [1] : int
            Sensor 5 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        bool__Sensor5AddrAssignError [1] : int
            Sensor 5 port - Set if this port could not be assigned a CAN address.
        bool__Sensor5AbstractTypeError [1] : int
            Sensor 5 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        bool__Sensor5SerialResolveError [1] : int
            Sensor 5 port - Set if the serial number returned by the node could not be resolved to a node type.
        uint32__Sensor6ErrorCode [1] : int
            Sensor 6 port - Error Code for Port Interface Operations.
        bool__Sensor6UnexpectedError [1] : int
            Sensor 6 port - Set if the node discovered on this port is not listed as an expected node.
        bool__Sensor6CommsError [1] : int
            Sensor 6 port - Set if a communications error ocurred.
        bool__Sensor6NodeTypeMatchError [1] : int
            Sensor 6 port - Set if the previously discovered node type no longer matches the node connected to the port.
        bool__Sensor6SerialMatchError [1] : int
            Sensor 6 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        bool__Sensor6AddrAssignError [1] : int
            Sensor 6 port - Set if this port could not be assigned a CAN address.
        bool__Sensor6AbstractTypeError [1] : int
            Sensor 6 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        bool__Sensor6SerialResolveError [1] : int
            Sensor 6 port - Set if the serial number returned by the node could not be resolved to a node type.
        uint32__Sensor7ErrorCode [1] : int
            Sensor 7 port - Error Code for Port Interface Operations.
        bool__Sensor7UnexpectedError [1] : int
            Sensor 7 port - Set if the node discovered on this port is not listed as an expected node.
        bool__Sensor7CommsError [1] : int
            Sensor 7 port - Set if a communications error ocurred.
        bool__Sensor7NodeTypeMatchError [1] : int
            Sensor 7 port - Set if the previously discovered node type no longer matches the node connected to the port.
        bool__Sensor7SerialMatchError [1] : int
            Sensor 7 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        bool__Sensor7AddrAssignError [1] : int
            Sensor 7 port - Set if this port could not be assigned a CAN address.
        bool__Sensor7AbstractTypeError [1] : int
            Sensor 7 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        bool__Sensor7SerialResolveError [1] : int
            Sensor 7 port - Set if the serial number returned by the node could not be resolved to a node type.
        uint32__Sensor8ErrorCode [1] : int
            Sensor 8 port - Error Code for Port Interface Operations.
        bool__Sensor8UnexpectedError [1] : int
            Sensor 8 port - Set if the node discovered on this port is not listed as an expected node.
        bool__Sensor8CommsError [1] : int
            Sensor 8 port - Set if a communications error ocurred.
        bool__Sensor8NodeTypeMatchError [1] : int
            Sensor 8 port - Set if the previously discovered node type no longer matches the node connected to the port.
        bool__Sensor8SerialMatchError [1] : int
            Sensor 8 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        bool__Sensor8AddrAssignError [1] : int
            Sensor 8 port - Set if this port could not be assigned a CAN address.
        bool__Sensor8AbstractTypeError [1] : int
            Sensor 8 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        bool__Sensor8SerialResolveError [1] : int
            Sensor 8 port - Set if the serial number returned by the node could not be resolved to a node type.
        uint32__Wheel1ErrorCode [1] : int
            Wheel 1 port - Error Code for Port Interface Operations.
        bool__Wheel1UnexpectedError [1] : int
            Wheel 1 port - Set if the node discovered on this port is not listed as an expected node.
        bool__Wheel1CommsError [1] : int
            Wheel 1 port - Set if a communications error ocurred.
        bool__Wheel1NodeTypeMatchError [1] : int
            Wheel 1 port - Set if the previously discovered node type no longer matches the node connected to the port.
        bool__Wheel1SerialMatchError [1] : int
            Wheel 1 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        bool__Wheel1AddrAssignError [1] : int
            Wheel 1 port - Set if this port could not be assigned a CAN address.
        bool__Wheel1AbstractTypeError [1] : int
            Wheel 1 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        bool__Wheel1SerialResolveError [1] : int
            Wheel 1 port - Set if the serial number returned by the node could not be resolved to a node type.
        uint32__Wheel2ErrorCode [1] : int
            Wheel 2 port - Error Code for Port Interface Operations.
        bool__Wheel2UnexpectedError [1] : int
            Wheel 2 port - Set if the node discovered on this port is not listed as an expected node.
        bool__Wheel2CommsError [1] : int
            Wheel 2 port - Set if a communications error ocurred.
        bool__Wheel2NodeTypeMatchError [1] : int
            Wheel 2 port - Set if the previously discovered node type no longer matches the node connected to the port.
        bool__Wheel2SerialMatchError [1] : int
            Wheel 2 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        bool__Wheel2AddrAssignError [1] : int
            Wheel 2 port - Set if this port could not be assigned a CAN address.
        bool__Wheel2AbstractTypeError [1] : int
            Wheel 2 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        bool__Wheel2SerialResolveError [1] : int
            Wheel 2 port - Set if the serial number returned by the node could not be resolved to a node type.
        uint32__Wheel3ErrorCode [1] : int
            Wheel 3 port - Error Code for Port Interface Operations.
        bool__Wheel3UnexpectedError [1] : int
            Wheel 3 port - Set if the node discovered on this port is not listed as an expected node.
        bool__Wheel3CommsError [1] : int
            Wheel 3 port - Set if a communications error ocurred.
        bool__Wheel3NodeTypeMatchError [1] : int
            Wheel 3 port - Set if the previously discovered node type no longer matches the node connected to the port.
        bool__Wheel3SerialMatchError [1] : int
            Wheel 3 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        bool__Wheel3AddrAssignError [1] : int
            Wheel 3 port - Set if this port could not be assigned a CAN address.
        bool__Wheel3AbstractTypeError [1] : int
            Wheel 3 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        bool__Wheel3SerialResolveError [1] : int
            Wheel 3 port - Set if the serial number returned by the node could not be resolved to a node type.
        uint32__Wheel4ErrorCode [1] : int
            Wheel 4 port - Error Code for Port Interface Operations.
        bool__Wheel4UnexpectedError [1] : int
            Wheel 4 port - Set if the node discovered on this port is not listed as an expected node.
        bool__Wheel4CommsError [1] : int
            Wheel 4 port - Set if a communications error ocurred.
        bool__Wheel4NodeTypeMatchError [1] : int
            Wheel 4 port - Set if the previously discovered node type no longer matches the node connected to the port.
        bool__Wheel4SerialMatchError [1] : int
            Wheel 4 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        bool__Wheel4AddrAssignError [1] : int
            Wheel 4 port - Set if this port could not be assigned a CAN address.
        bool__Wheel4AbstractTypeError [1] : int
            Wheel 4 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        bool__Wheel4SerialResolveError [1] : int
            Wheel 4 port - Set if the serial number returned by the node could not be resolved to a node type.
        """
        
        pass
        
    def get_GlobalErrorCode(self) -> int:
        """
        A getter for the 'PortDiagnostics::GlobalErrorCode' structure field
        
        Global Error Code for Port Interface Operations. Signaling an error with at least one of the ports.
        """
        
        pass
    
    def get_NoneExpected(self) -> int:
        """
        A getter for the 'PortDiagnostics::NoneExpected' structure field
        
        Set if the expected nodes configuration is empty.
        """
        
        pass
    
    def get_NoneDiscoveredError(self) -> int:
        """
        A getter for the 'PortDiagnostics::NoneDiscoveredError' structure field
        
        Set if no nodes have been discovered. Please ensure nodes are connected
        """
        
        pass
    
    def get_ExpectedMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::ExpectedMatchError' structure field
        
        Set if the nodes that have been discovered do not match the expected nodes. Please read all port parameters to diagnose.
        """
        
        pass
    
    def get_AddrAssignError(self) -> int:
        """
        A getter for the 'PortDiagnostics::AddrAssignError' structure field
        
        Set if a CAN address could not be assigned to a node. Please read all port parameters to diagnose.
        """
        
        pass
    
    def get_AbstractTypeError(self) -> int:
        """
        A getter for the 'PortDiagnostics::AbstractTypeError' structure field
        
        Set if an abstract node type could not be resolved. Typically due to an unsupported number of a specific type of node being discovered. Please read all port parameters to diagnose.
        """
        
        pass
    
    def get_ConfigPersistError(self) -> int:
        """
        A getter for the 'PortDiagnostics::ConfigPersistError' structure field
        
        Set if the discovered nodes could not be written to flash.
        """
        
        pass
    
    def get_Sensor1ErrorCode(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor1ErrorCode' structure field
        
        Sensor 1 port - Error Code for Port Interface Operations.
        """
        
        pass
    
    def get_Sensor1UnexpectedError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor1UnexpectedError' structure field
        
        Sensor 1 port - Set if the node discovered on this port is not listed as an expected node.
        """
        
        pass
    
    def get_Sensor1CommsError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor1CommsError' structure field
        
        Sensor 1 port - Set if a communications error ocurred.
        """
        
        pass
    
    def get_Sensor1NodeTypeMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor1NodeTypeMatchError' structure field
        
        Sensor 1 port - Set if the previously discovered node type no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Sensor1SerialMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor1SerialMatchError' structure field
        
        Sensor 1 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Sensor1AddrAssignError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor1AddrAssignError' structure field
        
        Sensor 1 port - Set if this port could not be assigned a CAN address.
        """
        
        pass
    
    def get_Sensor1AbstractTypeError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor1AbstractTypeError' structure field
        
        Sensor 1 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        """
        
        pass
    
    def get_Sensor1SerialResolveError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor1SerialResolveError' structure field
        
        Sensor 1 port - Set if the serial number returned by the node could not be resolved to a node type.
        """
        
        pass
    
    def get_Sensor2ErrorCode(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor2ErrorCode' structure field
        
        Sensor 2 port - Error Code for Port Interface Operations.
        """
        
        pass
    
    def get_Sensor2UnexpectedError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor2UnexpectedError' structure field
        
        Sensor 2 port - Set if the node discovered on this port is not listed as an expected node.
        """
        
        pass
    
    def get_Sensor2CommsError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor2CommsError' structure field
        
        Sensor 2 port - Set if a communications error ocurred.
        """
        
        pass
    
    def get_Sensor2NodeTypeMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor2NodeTypeMatchError' structure field
        
        Sensor 2 port - Set if the previously discovered node type no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Sensor2SerialMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor2SerialMatchError' structure field
        
        Sensor 2 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Sensor2AddrAssignError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor2AddrAssignError' structure field
        
        Sensor 2 port - Set if this port could not be assigned a CAN address.
        """
        
        pass
    
    def get_Sensor2AbstractTypeError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor2AbstractTypeError' structure field
        
        Sensor 2 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        """
        
        pass
    
    def get_Sensor2SerialResolveError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor2SerialResolveError' structure field
        
        Sensor 2 port - Set if the serial number returned by the node could not be resolved to a node type.
        """
        
        pass
    
    def get_Sensor3ErrorCode(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor3ErrorCode' structure field
        
        Sensor 3 port - Error Code for Port Interface Operations.
        """
        
        pass
    
    def get_Sensor3UnexpectedError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor3UnexpectedError' structure field
        
        Sensor 3 port - Set if the node discovered on this port is not listed as an expected node.
        """
        
        pass
    
    def get_Sensor3CommsError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor3CommsError' structure field
        
        Sensor 3 port - Set if a communications error ocurred.
        """
        
        pass
    
    def get_Sensor3NodeTypeMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor3NodeTypeMatchError' structure field
        
        Sensor 3 port - Set if the previously discovered node type no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Sensor3SerialMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor3SerialMatchError' structure field
        
        Sensor 3 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Sensor3AddrAssignError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor3AddrAssignError' structure field
        
        Sensor 3 port - Set if this port could not be assigned a CAN address.
        """
        
        pass
    
    def get_Sensor3AbstractTypeError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor3AbstractTypeError' structure field
        
        Sensor 3 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        """
        
        pass
    
    def get_Sensor3SerialResolveError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor3SerialResolveError' structure field
        
        Sensor 3 port - Set if the serial number returned by the node could not be resolved to a node type.
        """
        
        pass
    
    def get_Sensor4ErrorCode(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor4ErrorCode' structure field
        
        Sensor 4 port - Error Code for Port Interface Operations.
        """
        
        pass
    
    def get_Sensor4UnexpectedError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor4UnexpectedError' structure field
        
        Sensor 4 port - Set if the node discovered on this port is not listed as an expected node.
        """
        
        pass
    
    def get_Sensor4CommsError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor4CommsError' structure field
        
        Sensor 4 port - Set if a communications error ocurred.
        """
        
        pass
    
    def get_Sensor4NodeTypeMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor4NodeTypeMatchError' structure field
        
        Sensor 4 port - Set if the previously discovered node type no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Sensor4SerialMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor4SerialMatchError' structure field
        
        Sensor 4 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Sensor4AddrAssignError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor4AddrAssignError' structure field
        
        Sensor 4 port - Set if this port could not be assigned a CAN address.
        """
        
        pass
    
    def get_Sensor4AbstractTypeError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor4AbstractTypeError' structure field
        
        Sensor 4 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        """
        
        pass
    
    def get_Sensor4SerialResolveError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor4SerialResolveError' structure field
        
        Sensor 4 port - Set if the serial number returned by the node could not be resolved to a node type.
        """
        
        pass
    
    def get_Sensor5ErrorCode(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor5ErrorCode' structure field
        
        Sensor 5 port - Error Code for Port Interface Operations.
        """
        
        pass
    
    def get_Sensor5UnexpectedError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor5UnexpectedError' structure field
        
        Sensor 5 port - Set if the node discovered on this port is not listed as an expected node.
        """
        
        pass
    
    def get_Sensor5CommsError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor5CommsError' structure field
        
        Sensor 5 port - Set if a communications error ocurred.
        """
        
        pass
    
    def get_Sensor5NodeTypeMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor5NodeTypeMatchError' structure field
        
        Sensor 5 port - Set if the previously discovered node type no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Sensor5SerialMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor5SerialMatchError' structure field
        
        Sensor 5 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Sensor5AddrAssignError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor5AddrAssignError' structure field
        
        Sensor 5 port - Set if this port could not be assigned a CAN address.
        """
        
        pass
    
    def get_Sensor5AbstractTypeError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor5AbstractTypeError' structure field
        
        Sensor 5 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        """
        
        pass
    
    def get_Sensor5SerialResolveError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor5SerialResolveError' structure field
        
        Sensor 5 port - Set if the serial number returned by the node could not be resolved to a node type.
        """
        
        pass
    
    def get_Sensor6ErrorCode(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor6ErrorCode' structure field
        
        Sensor 6 port - Error Code for Port Interface Operations.
        """
        
        pass
    
    def get_Sensor6UnexpectedError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor6UnexpectedError' structure field
        
        Sensor 6 port - Set if the node discovered on this port is not listed as an expected node.
        """
        
        pass
    
    def get_Sensor6CommsError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor6CommsError' structure field
        
        Sensor 6 port - Set if a communications error ocurred.
        """
        
        pass
    
    def get_Sensor6NodeTypeMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor6NodeTypeMatchError' structure field
        
        Sensor 6 port - Set if the previously discovered node type no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Sensor6SerialMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor6SerialMatchError' structure field
        
        Sensor 6 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Sensor6AddrAssignError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor6AddrAssignError' structure field
        
        Sensor 6 port - Set if this port could not be assigned a CAN address.
        """
        
        pass
    
    def get_Sensor6AbstractTypeError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor6AbstractTypeError' structure field
        
        Sensor 6 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        """
        
        pass
    
    def get_Sensor6SerialResolveError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor6SerialResolveError' structure field
        
        Sensor 6 port - Set if the serial number returned by the node could not be resolved to a node type.
        """
        
        pass
    
    def get_Sensor7ErrorCode(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor7ErrorCode' structure field
        
        Sensor 7 port - Error Code for Port Interface Operations.
        """
        
        pass
    
    def get_Sensor7UnexpectedError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor7UnexpectedError' structure field
        
        Sensor 7 port - Set if the node discovered on this port is not listed as an expected node.
        """
        
        pass
    
    def get_Sensor7CommsError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor7CommsError' structure field
        
        Sensor 7 port - Set if a communications error ocurred.
        """
        
        pass
    
    def get_Sensor7NodeTypeMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor7NodeTypeMatchError' structure field
        
        Sensor 7 port - Set if the previously discovered node type no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Sensor7SerialMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor7SerialMatchError' structure field
        
        Sensor 7 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Sensor7AddrAssignError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor7AddrAssignError' structure field
        
        Sensor 7 port - Set if this port could not be assigned a CAN address.
        """
        
        pass
    
    def get_Sensor7AbstractTypeError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor7AbstractTypeError' structure field
        
        Sensor 7 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        """
        
        pass
    
    def get_Sensor7SerialResolveError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor7SerialResolveError' structure field
        
        Sensor 7 port - Set if the serial number returned by the node could not be resolved to a node type.
        """
        
        pass
    
    def get_Sensor8ErrorCode(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor8ErrorCode' structure field
        
        Sensor 8 port - Error Code for Port Interface Operations.
        """
        
        pass
    
    def get_Sensor8UnexpectedError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor8UnexpectedError' structure field
        
        Sensor 8 port - Set if the node discovered on this port is not listed as an expected node.
        """
        
        pass
    
    def get_Sensor8CommsError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor8CommsError' structure field
        
        Sensor 8 port - Set if a communications error ocurred.
        """
        
        pass
    
    def get_Sensor8NodeTypeMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor8NodeTypeMatchError' structure field
        
        Sensor 8 port - Set if the previously discovered node type no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Sensor8SerialMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor8SerialMatchError' structure field
        
        Sensor 8 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Sensor8AddrAssignError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor8AddrAssignError' structure field
        
        Sensor 8 port - Set if this port could not be assigned a CAN address.
        """
        
        pass
    
    def get_Sensor8AbstractTypeError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor8AbstractTypeError' structure field
        
        Sensor 8 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        """
        
        pass
    
    def get_Sensor8SerialResolveError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Sensor8SerialResolveError' structure field
        
        Sensor 8 port - Set if the serial number returned by the node could not be resolved to a node type.
        """
        
        pass
    
    def get_Wheel1ErrorCode(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel1ErrorCode' structure field
        
        Wheel 1 port - Error Code for Port Interface Operations.
        """
        
        pass
    
    def get_Wheel1UnexpectedError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel1UnexpectedError' structure field
        
        Wheel 1 port - Set if the node discovered on this port is not listed as an expected node.
        """
        
        pass
    
    def get_Wheel1CommsError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel1CommsError' structure field
        
        Wheel 1 port - Set if a communications error ocurred.
        """
        
        pass
    
    def get_Wheel1NodeTypeMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel1NodeTypeMatchError' structure field
        
        Wheel 1 port - Set if the previously discovered node type no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Wheel1SerialMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel1SerialMatchError' structure field
        
        Wheel 1 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Wheel1AddrAssignError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel1AddrAssignError' structure field
        
        Wheel 1 port - Set if this port could not be assigned a CAN address.
        """
        
        pass
    
    def get_Wheel1AbstractTypeError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel1AbstractTypeError' structure field
        
        Wheel 1 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        """
        
        pass
    
    def get_Wheel1SerialResolveError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel1SerialResolveError' structure field
        
        Wheel 1 port - Set if the serial number returned by the node could not be resolved to a node type.
        """
        
        pass
    
    def get_Wheel2ErrorCode(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel2ErrorCode' structure field
        
        Wheel 2 port - Error Code for Port Interface Operations.
        """
        
        pass
    
    def get_Wheel2UnexpectedError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel2UnexpectedError' structure field
        
        Wheel 2 port - Set if the node discovered on this port is not listed as an expected node.
        """
        
        pass
    
    def get_Wheel2CommsError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel2CommsError' structure field
        
        Wheel 2 port - Set if a communications error ocurred.
        """
        
        pass
    
    def get_Wheel2NodeTypeMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel2NodeTypeMatchError' structure field
        
        Wheel 2 port - Set if the previously discovered node type no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Wheel2SerialMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel2SerialMatchError' structure field
        
        Wheel 2 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Wheel2AddrAssignError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel2AddrAssignError' structure field
        
        Wheel 2 port - Set if this port could not be assigned a CAN address.
        """
        
        pass
    
    def get_Wheel2AbstractTypeError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel2AbstractTypeError' structure field
        
        Wheel 2 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        """
        
        pass
    
    def get_Wheel2SerialResolveError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel2SerialResolveError' structure field
        
        Wheel 2 port - Set if the serial number returned by the node could not be resolved to a node type.
        """
        
        pass
    
    def get_Wheel3ErrorCode(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel3ErrorCode' structure field
        
        Wheel 3 port - Error Code for Port Interface Operations.
        """
        
        pass
    
    def get_Wheel3UnexpectedError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel3UnexpectedError' structure field
        
        Wheel 3 port - Set if the node discovered on this port is not listed as an expected node.
        """
        
        pass
    
    def get_Wheel3CommsError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel3CommsError' structure field
        
        Wheel 3 port - Set if a communications error ocurred.
        """
        
        pass
    
    def get_Wheel3NodeTypeMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel3NodeTypeMatchError' structure field
        
        Wheel 3 port - Set if the previously discovered node type no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Wheel3SerialMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel3SerialMatchError' structure field
        
        Wheel 3 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Wheel3AddrAssignError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel3AddrAssignError' structure field
        
        Wheel 3 port - Set if this port could not be assigned a CAN address.
        """
        
        pass
    
    def get_Wheel3AbstractTypeError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel3AbstractTypeError' structure field
        
        Wheel 3 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        """
        
        pass
    
    def get_Wheel3SerialResolveError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel3SerialResolveError' structure field
        
        Wheel 3 port - Set if the serial number returned by the node could not be resolved to a node type.
        """
        
        pass
    
    def get_Wheel4ErrorCode(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel4ErrorCode' structure field
        
        Wheel 4 port - Error Code for Port Interface Operations.
        """
        
        pass
    
    def get_Wheel4UnexpectedError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel4UnexpectedError' structure field
        
        Wheel 4 port - Set if the node discovered on this port is not listed as an expected node.
        """
        
        pass
    
    def get_Wheel4CommsError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel4CommsError' structure field
        
        Wheel 4 port - Set if a communications error ocurred.
        """
        
        pass
    
    def get_Wheel4NodeTypeMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel4NodeTypeMatchError' structure field
        
        Wheel 4 port - Set if the previously discovered node type no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Wheel4SerialMatchError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel4SerialMatchError' structure field
        
        Wheel 4 port - Set if the previously discovered node serial number no longer matches the node connected to the port.
        """
        
        pass
    
    def get_Wheel4AddrAssignError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel4AddrAssignError' structure field
        
        Wheel 4 port - Set if this port could not be assigned a CAN address.
        """
        
        pass
    
    def get_Wheel4AbstractTypeError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel4AbstractTypeError' structure field
        
        Wheel 4 port - Set if the abstract type for the node on this port could not be resolve or if there are an unsupported number of a spacific node type connected.
        """
        
        pass
    
    def get_Wheel4SerialResolveError(self) -> int:
        """
        A getter for the 'PortDiagnostics::Wheel4SerialResolveError' structure field
        
        Wheel 4 port - Set if the serial number returned by the node could not be resolved to a node type.
        """
        
        pass

def PortDiagnostics_make_from_buf(buf : bytes) -> PortDiagnostics:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ComponentErrorCodes:
    """
    A Python class to represent struct objects of type 'ComponentErrorCodes'
    
    Parameter structure for interface ComponentErrorCodes
    """

    def __init__(self, uint32__MasterSvc : int, uint32__FramFsSvc : int, uint32__EventLogSvc : int, uint32__ImgLogSvc : int, uint32__TlmLogSvc : int, uint32__ImuSvc : int) -> None:
        """
        Struct 'ComponentErrorCodes' constructor
        
        Attributes
        ---------
        uint32__MasterSvc [1] : int
            Tctlm comms master service error code (node comms)
        uint32__FramFsSvc [1] : int
            FRAM file system error code.
        uint32__EventLogSvc [1] : int
            Event log service error code.
        uint32__ImgLogSvc [1] : int
            Image log service error code.
        uint32__TlmLogSvc [1] : int
            Telemetry log service error code.
        uint32__ImuSvc [1] : int
            IMU/Gyro service error code.
        """
        
        pass
        
    def get_MasterSvc(self) -> int:
        """
        A getter for the 'ComponentErrorCodes::MasterSvc' structure field
        
        Tctlm comms master service error code (node comms)
        """
        
        pass
    
    def get_FramFsSvc(self) -> int:
        """
        A getter for the 'ComponentErrorCodes::FramFsSvc' structure field
        
        FRAM file system error code.
        """
        
        pass
    
    def get_EventLogSvc(self) -> int:
        """
        A getter for the 'ComponentErrorCodes::EventLogSvc' structure field
        
        Event log service error code.
        """
        
        pass
    
    def get_ImgLogSvc(self) -> int:
        """
        A getter for the 'ComponentErrorCodes::ImgLogSvc' structure field
        
        Image log service error code.
        """
        
        pass
    
    def get_TlmLogSvc(self) -> int:
        """
        A getter for the 'ComponentErrorCodes::TlmLogSvc' structure field
        
        Telemetry log service error code.
        """
        
        pass
    
    def get_ImuSvc(self) -> int:
        """
        A getter for the 'ComponentErrorCodes::ImuSvc' structure field
        
        IMU/Gyro service error code.
        """
        
        pass

def ComponentErrorCodes_make_from_buf(buf : bytes) -> ComponentErrorCodes:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TelemtryLogInclusionMasks:
    """
    A Python class to represent struct objects of type 'TelemtryLogInclusionMasks'
    
    Parameter structure for interface TelemtryLogInclusionMasks
    """

    def __init__(self, a__uint8__5__fastBitMask : list[int], a__uint8__5__slowBitMask : list[int]) -> None:
        """
        Struct 'TelemtryLogInclusionMasks' constructor
        
        Attributes
        ---------
        a__uint8__5__fastBitMask [5] : list[int]
            Log ID inclusion bitmask for telemetry logged every 200ms
        a__uint8__5__slowBitMask [5] : list[int]
            Log ID inclusion bitmask for telemetry logged every 1s
        """
        
        pass
        
    def get_fastBitMask(self) -> list[int]:
        """
        A getter for the 'TelemtryLogInclusionMasks::fastBitMask' structure field
        
        Log ID inclusion bitmask for telemetry logged every 200ms
        """
        
        pass
    
    def get_slowBitMask(self) -> list[int]:
        """
        A getter for the 'TelemtryLogInclusionMasks::slowBitMask' structure field
        
        Log ID inclusion bitmask for telemetry logged every 1s
        """
        
        pass

def TelemtryLogInclusionMasks_make_from_buf(buf : bytes) -> TelemtryLogInclusionMasks:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class UnsolicitedEventSetup:
    """
    A Python class to represent struct objects of type 'UnsolicitedEventSetup'
    
    Parameter structure for interface UnsolicitedEventSetup
    """

    def __init__(self, bool__uartInfo : int, bool__uartWarnMinor : int, bool__uartWarnMajor : int, bool__uartCritical : int, bool__uart2Info : int, bool__uart2WarnMinor : int, bool__uart2WarnMajor : int, bool__uart2Critical : int, bool__canInfo : int, bool__canWarnMinor : int, bool__canWarnMajor : int, bool__canCritical : int) -> None:
        """
        Struct 'UnsolicitedEventSetup' constructor
        
        Attributes
        ---------
        bool__uartInfo [1] : int
            Output Info class events to UART
        bool__uartWarnMinor [1] : int
            Output minor warning class events to UART
        bool__uartWarnMajor [1] : int
            Output major warning class events to UART
        bool__uartCritical [1] : int
            Output critical class events to UART2
        bool__uart2Info [1] : int
            Output Info class events to UART2
        bool__uart2WarnMinor [1] : int
            Output minor warning class events to UART2
        bool__uart2WarnMajor [1] : int
            Output major warning class events to UART2
        bool__uart2Critical [1] : int
            Output critical class events to UART2
        bool__canInfo [1] : int
            Output Info class events to CAN
        bool__canWarnMinor [1] : int
            Output minor warning class events to CAN
        bool__canWarnMajor [1] : int
            Output major warning class events to CAN
        bool__canCritical [1] : int
            Output critical class events to CAN
        """
        
        pass
        
    def get_uartInfo(self) -> int:
        """
        A getter for the 'UnsolicitedEventSetup::uartInfo' structure field
        
        Output Info class events to UART
        """
        
        pass
    
    def get_uartWarnMinor(self) -> int:
        """
        A getter for the 'UnsolicitedEventSetup::uartWarnMinor' structure field
        
        Output minor warning class events to UART
        """
        
        pass
    
    def get_uartWarnMajor(self) -> int:
        """
        A getter for the 'UnsolicitedEventSetup::uartWarnMajor' structure field
        
        Output major warning class events to UART
        """
        
        pass
    
    def get_uartCritical(self) -> int:
        """
        A getter for the 'UnsolicitedEventSetup::uartCritical' structure field
        
        Output critical class events to UART2
        """
        
        pass
    
    def get_uart2Info(self) -> int:
        """
        A getter for the 'UnsolicitedEventSetup::uart2Info' structure field
        
        Output Info class events to UART2
        """
        
        pass
    
    def get_uart2WarnMinor(self) -> int:
        """
        A getter for the 'UnsolicitedEventSetup::uart2WarnMinor' structure field
        
        Output minor warning class events to UART2
        """
        
        pass
    
    def get_uart2WarnMajor(self) -> int:
        """
        A getter for the 'UnsolicitedEventSetup::uart2WarnMajor' structure field
        
        Output major warning class events to UART2
        """
        
        pass
    
    def get_uart2Critical(self) -> int:
        """
        A getter for the 'UnsolicitedEventSetup::uart2Critical' structure field
        
        Output critical class events to UART2
        """
        
        pass
    
    def get_canInfo(self) -> int:
        """
        A getter for the 'UnsolicitedEventSetup::canInfo' structure field
        
        Output Info class events to CAN
        """
        
        pass
    
    def get_canWarnMinor(self) -> int:
        """
        A getter for the 'UnsolicitedEventSetup::canWarnMinor' structure field
        
        Output minor warning class events to CAN
        """
        
        pass
    
    def get_canWarnMajor(self) -> int:
        """
        A getter for the 'UnsolicitedEventSetup::canWarnMajor' structure field
        
        Output major warning class events to CAN
        """
        
        pass
    
    def get_canCritical(self) -> int:
        """
        A getter for the 'UnsolicitedEventSetup::canCritical' structure field
        
        Output critical class events to CAN
        """
        
        pass

def UnsolicitedEventSetup_make_from_buf(buf : bytes) -> UnsolicitedEventSetup:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class EventLogFilterTransferSetup:
    """
    A Python class to represent struct objects of type 'EventLogFilterTransferSetup'
    
    Parameter structure for interface EventLogFilterTransferSetup
    """

    def __init__(self, e__CubeComputerCommon3_LogReadFilterType__filterType : CubeComputerCommon3_LogReadFilterType, uint32__startTimeUnix : int, uint32__endTimeUnix : int, uint32__numEntries : int, uint32__writeCounter : int, bool__includeClassCritical : int, bool__includeClassMajorWarning : int, bool__includeClassMinorWarning : int, bool__includeClassInfo : int, bool__includeSourceCubeComputer : int, bool__includeSourceRwl0 : int, bool__includeSourceRwl1 : int, bool__includeSourceRwl2 : int, bool__includeSourceRwl3 : int, bool__includeSourceFss0 : int, bool__includeSourceFss1 : int, bool__includeSourceFss2 : int, bool__includeSourceFss3 : int, bool__includeSourceHss0 : int, bool__includeSourceHss1 : int, bool__includeSourceStr0 : int, bool__includeSourceStr1 : int, bool__includeSourceMag0 : int, bool__includeSourceMag1 : int, bool__includeSourceExt0 : int, bool__includeSourceExt1 : int) -> None:
        """
        Struct 'EventLogFilterTransferSetup' constructor
        
        Attributes
        ---------
        e__CubeComputerCommon3_LogReadFilterType__filterType [1] : CubeComputerCommon3_LogReadFilterType
            Filter type to use when reading event logs
        uint32__startTimeUnix [1] : int
            If using time span/next x filter - indicate the unix start time in seconds. All entries with a timestamp after this time will be included in the transfer.
        uint32__endTimeUnix [1] : int
            If using time span filter - indicate the unix end time in seconds. All entries with a timestamp before this time will be included in the transfer.
        uint32__numEntries [1] : int
            If using time next-x or first/last-x or counter next-x filter - indicate the number of entries to transfer.
        uint32__writeCounter [1] : int
            If using counter next-x filter - indicate the reference write counter value.
        bool__includeClassCritical [1] : int
            Include critical events in transfer Event Log
        bool__includeClassMajorWarning [1] : int
            Include major warning events in transfer Event Log
        bool__includeClassMinorWarning [1] : int
            Include minor warning events in transfer Event Log
        bool__includeClassInfo [1] : int
            Include info events in transfer Event Log
        bool__includeSourceCubeComputer [1] : int
            Include the CubeComputer as a source for events
        bool__includeSourceRwl0 [1] : int
            Include the RWL 0 as a source for events
        bool__includeSourceRwl1 [1] : int
            Include the RWL 1 as a source for events
        bool__includeSourceRwl2 [1] : int
            Include the RWL 2 as a source for events
        bool__includeSourceRwl3 [1] : int
            Include the RWL 3 as a source for events
        bool__includeSourceFss0 [1] : int
            Include the Fss 0 as a source for events
        bool__includeSourceFss1 [1] : int
            Include the Fss 1 as a source for events
        bool__includeSourceFss2 [1] : int
            Include the Fss 2 as a source for events
        bool__includeSourceFss3 [1] : int
            Include the Fss 3 as a source for events
        bool__includeSourceHss0 [1] : int
            Include the Hss 0 as a source for events
        bool__includeSourceHss1 [1] : int
            Include the Hss 1 as a source for events
        bool__includeSourceStr0 [1] : int
            Include the Str 0 as a source for events
        bool__includeSourceStr1 [1] : int
            Include the Str 1 as a source for events
        bool__includeSourceMag0 [1] : int
            Include the Mag 0 as a source for events
        bool__includeSourceMag1 [1] : int
            Include the Mag 1 as a source for events
        bool__includeSourceExt0 [1] : int
            Include the External 0 as a source for events
        bool__includeSourceExt1 [1] : int
            Include the External 1 as a source for events
        """
        
        pass
        
    def get_filterType(self) -> CubeComputerCommon3_LogReadFilterType:
        """
        A getter for the 'EventLogFilterTransferSetup::filterType' structure field
        
        Filter type to use when reading event logs
        """
        
        pass
    
    def get_startTimeUnix(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::startTimeUnix' structure field
        
        If using time span/next x filter - indicate the unix start time in seconds. All entries with a timestamp after this time will be included in the transfer.
        """
        
        pass
    
    def get_endTimeUnix(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::endTimeUnix' structure field
        
        If using time span filter - indicate the unix end time in seconds. All entries with a timestamp before this time will be included in the transfer.
        """
        
        pass
    
    def get_numEntries(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::numEntries' structure field
        
        If using time next-x or first/last-x or counter next-x filter - indicate the number of entries to transfer.
        """
        
        pass
    
    def get_writeCounter(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::writeCounter' structure field
        
        If using counter next-x filter - indicate the reference write counter value.
        """
        
        pass
    
    def get_includeClassCritical(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeClassCritical' structure field
        
        Include critical events in transfer Event Log
        """
        
        pass
    
    def get_includeClassMajorWarning(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeClassMajorWarning' structure field
        
        Include major warning events in transfer Event Log
        """
        
        pass
    
    def get_includeClassMinorWarning(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeClassMinorWarning' structure field
        
        Include minor warning events in transfer Event Log
        """
        
        pass
    
    def get_includeClassInfo(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeClassInfo' structure field
        
        Include info events in transfer Event Log
        """
        
        pass
    
    def get_includeSourceCubeComputer(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeSourceCubeComputer' structure field
        
        Include the CubeComputer as a source for events
        """
        
        pass
    
    def get_includeSourceRwl0(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeSourceRwl0' structure field
        
        Include the RWL 0 as a source for events
        """
        
        pass
    
    def get_includeSourceRwl1(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeSourceRwl1' structure field
        
        Include the RWL 1 as a source for events
        """
        
        pass
    
    def get_includeSourceRwl2(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeSourceRwl2' structure field
        
        Include the RWL 2 as a source for events
        """
        
        pass
    
    def get_includeSourceRwl3(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeSourceRwl3' structure field
        
        Include the RWL 3 as a source for events
        """
        
        pass
    
    def get_includeSourceFss0(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeSourceFss0' structure field
        
        Include the Fss 0 as a source for events
        """
        
        pass
    
    def get_includeSourceFss1(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeSourceFss1' structure field
        
        Include the Fss 1 as a source for events
        """
        
        pass
    
    def get_includeSourceFss2(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeSourceFss2' structure field
        
        Include the Fss 2 as a source for events
        """
        
        pass
    
    def get_includeSourceFss3(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeSourceFss3' structure field
        
        Include the Fss 3 as a source for events
        """
        
        pass
    
    def get_includeSourceHss0(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeSourceHss0' structure field
        
        Include the Hss 0 as a source for events
        """
        
        pass
    
    def get_includeSourceHss1(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeSourceHss1' structure field
        
        Include the Hss 1 as a source for events
        """
        
        pass
    
    def get_includeSourceStr0(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeSourceStr0' structure field
        
        Include the Str 0 as a source for events
        """
        
        pass
    
    def get_includeSourceStr1(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeSourceStr1' structure field
        
        Include the Str 1 as a source for events
        """
        
        pass
    
    def get_includeSourceMag0(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeSourceMag0' structure field
        
        Include the Mag 0 as a source for events
        """
        
        pass
    
    def get_includeSourceMag1(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeSourceMag1' structure field
        
        Include the Mag 1 as a source for events
        """
        
        pass
    
    def get_includeSourceExt0(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeSourceExt0' structure field
        
        Include the External 0 as a source for events
        """
        
        pass
    
    def get_includeSourceExt1(self) -> int:
        """
        A getter for the 'EventLogFilterTransferSetup::includeSourceExt1' structure field
        
        Include the External 1 as a source for events
        """
        
        pass

def EventLogFilterTransferSetup_make_from_buf(buf : bytes) -> EventLogFilterTransferSetup:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TelemetryLogTransferSetup:
    """
    A Python class to represent struct objects of type 'TelemetryLogTransferSetup'
    
    Parameter structure for interface TelemetryLogTransferSetup
    """

    def __init__(self, e__CubeComputerCommon3_LogReadFilterType__filterType : CubeComputerCommon3_LogReadFilterType, uint32__startTimeUnix : int, uint32__endTimeUnix : int, uint32__numEntries : int, uint32__writeCounter : int, e__CubeComputerCommon3_TlmLogReturnIntervalValues__tlmLogReturnInterval : CubeComputerCommon3_TlmLogReturnIntervalValues, a__uint8__5__logIdBitmask : list[int]) -> None:
        """
        Struct 'TelemetryLogTransferSetup' constructor
        
        Attributes
        ---------
        e__CubeComputerCommon3_LogReadFilterType__filterType [1] : CubeComputerCommon3_LogReadFilterType
            Filter type to use when reading tlm logs
        uint32__startTimeUnix [1] : int
            Indicate the unix start time in seconds. All entries with a timestamp after this time will be included in the transfer.
        uint32__endTimeUnix [1] : int
            Indicate the unix start end in seconds. All entries with a timestamp before this time will be included in the transfer.
        uint32__numEntries [1] : int
            If using time next-x or first/last-x or counter next-x filter - indicate the number of entries to transfer.
        uint32__writeCounter [1] : int
            If using counter next-x filter - indicate the reference write counter value.
        e__CubeComputerCommon3_TlmLogReturnIntervalValues__tlmLogReturnInterval [1] : CubeComputerCommon3_TlmLogReturnIntervalValues
            Indicate how many samples to exclude between transferred samples
        a__uint8__5__logIdBitmask [5] : list[int]
            Indicate which log IDs must be included in the transfered Telemetry Log
        """
        
        pass
        
    def get_filterType(self) -> CubeComputerCommon3_LogReadFilterType:
        """
        A getter for the 'TelemetryLogTransferSetup::filterType' structure field
        
        Filter type to use when reading tlm logs
        """
        
        pass
    
    def get_startTimeUnix(self) -> int:
        """
        A getter for the 'TelemetryLogTransferSetup::startTimeUnix' structure field
        
        Indicate the unix start time in seconds. All entries with a timestamp after this time will be included in the transfer.
        """
        
        pass
    
    def get_endTimeUnix(self) -> int:
        """
        A getter for the 'TelemetryLogTransferSetup::endTimeUnix' structure field
        
        Indicate the unix start end in seconds. All entries with a timestamp before this time will be included in the transfer.
        """
        
        pass
    
    def get_numEntries(self) -> int:
        """
        A getter for the 'TelemetryLogTransferSetup::numEntries' structure field
        
        If using time next-x or first/last-x or counter next-x filter - indicate the number of entries to transfer.
        """
        
        pass
    
    def get_writeCounter(self) -> int:
        """
        A getter for the 'TelemetryLogTransferSetup::writeCounter' structure field
        
        If using counter next-x filter - indicate the reference write counter value.
        """
        
        pass
    
    def get_tlmLogReturnInterval(self) -> CubeComputerCommon3_TlmLogReturnIntervalValues:
        """
        A getter for the 'TelemetryLogTransferSetup::tlmLogReturnInterval' structure field
        
        Indicate how many samples to exclude between transferred samples
        """
        
        pass
    
    def get_logIdBitmask(self) -> list[int]:
        """
        A getter for the 'TelemetryLogTransferSetup::logIdBitmask' structure field
        
        Indicate which log IDs must be included in the transfered Telemetry Log
        """
        
        pass

def TelemetryLogTransferSetup_make_from_buf(buf : bytes) -> TelemetryLogTransferSetup:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class UnsolicitedTlmSetup:
    """
    A Python class to represent struct objects of type 'UnsolicitedTlmSetup'
    
    Parameter structure for interface UnsolicitedTlmSetup
    """

    def __init__(self, e__CubeComputerCommon3_TlmLogReturnIntervalValues__uartTlmInterval : CubeComputerCommon3_TlmLogReturnIntervalValues, e__CubeComputerCommon3_TlmLogReturnIntervalValues__uart2TlmInterval : CubeComputerCommon3_TlmLogReturnIntervalValues, e__CubeComputerCommon3_TlmLogReturnIntervalValues__canTlmInterval : CubeComputerCommon3_TlmLogReturnIntervalValues, a__uint8__5__uartTlmIdBitmask : list[int], a__uint8__5__uart2TlmIdBitmask : list[int], a__uint8__5__canTlmIdBitmask : list[int]) -> None:
        """
        Struct 'UnsolicitedTlmSetup' constructor
        
        Attributes
        ---------
        e__CubeComputerCommon3_TlmLogReturnIntervalValues__uartTlmInterval [1] : CubeComputerCommon3_TlmLogReturnIntervalValues
            Indicate how frequently unsolicited telemetry is transmitted on the UART interface
        e__CubeComputerCommon3_TlmLogReturnIntervalValues__uart2TlmInterval [1] : CubeComputerCommon3_TlmLogReturnIntervalValues
            Indicate how frequently unsolicited telemetry is transmitted on the UART2 interface
        e__CubeComputerCommon3_TlmLogReturnIntervalValues__canTlmInterval [1] : CubeComputerCommon3_TlmLogReturnIntervalValues
            Indicate how frequently unsolicited telemetry is transmitted on the CAN interface
        a__uint8__5__uartTlmIdBitmask [5] : list[int]
            Indicate which TLM IDs must be included in the transfered Telemetry on the UART interface
        a__uint8__5__uart2TlmIdBitmask [5] : list[int]
            Indicate which TLM IDs must be included in the transfered Telemetry on the UART2 interface
        a__uint8__5__canTlmIdBitmask [5] : list[int]
            Indicate which TLM IDs must be included in the transfered Telemetry on the CAN interface
        """
        
        pass
        
    def get_uartTlmInterval(self) -> CubeComputerCommon3_TlmLogReturnIntervalValues:
        """
        A getter for the 'UnsolicitedTlmSetup::uartTlmInterval' structure field
        
        Indicate how frequently unsolicited telemetry is transmitted on the UART interface
        """
        
        pass
    
    def get_uart2TlmInterval(self) -> CubeComputerCommon3_TlmLogReturnIntervalValues:
        """
        A getter for the 'UnsolicitedTlmSetup::uart2TlmInterval' structure field
        
        Indicate how frequently unsolicited telemetry is transmitted on the UART2 interface
        """
        
        pass
    
    def get_canTlmInterval(self) -> CubeComputerCommon3_TlmLogReturnIntervalValues:
        """
        A getter for the 'UnsolicitedTlmSetup::canTlmInterval' structure field
        
        Indicate how frequently unsolicited telemetry is transmitted on the CAN interface
        """
        
        pass
    
    def get_uartTlmIdBitmask(self) -> list[int]:
        """
        A getter for the 'UnsolicitedTlmSetup::uartTlmIdBitmask' structure field
        
        Indicate which TLM IDs must be included in the transfered Telemetry on the UART interface
        """
        
        pass
    
    def get_uart2TlmIdBitmask(self) -> list[int]:
        """
        A getter for the 'UnsolicitedTlmSetup::uart2TlmIdBitmask' structure field
        
        Indicate which TLM IDs must be included in the transfered Telemetry on the UART2 interface
        """
        
        pass
    
    def get_canTlmIdBitmask(self) -> list[int]:
        """
        A getter for the 'UnsolicitedTlmSetup::canTlmIdBitmask' structure field
        
        Indicate which TLM IDs must be included in the transfered Telemetry on the CAN interface
        """
        
        pass

def UnsolicitedTlmSetup_make_from_buf(buf : bytes) -> UnsolicitedTlmSetup:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class PowerState:
    """
    A Python class to represent struct objects of type 'PowerState'
    
    Parameter structure for interface PowerState
    """

    def __init__(self, e__CubeComputerCommon3_PowerSelect__Rwl0Power : CubeComputerCommon3_PowerSelect, e__CubeComputerCommon3_PowerSelect__Rwl1Power : CubeComputerCommon3_PowerSelect, e__CubeComputerCommon3_PowerSelect__Rwl2Power : CubeComputerCommon3_PowerSelect, e__CubeComputerCommon3_PowerSelect__Rwl3Power : CubeComputerCommon3_PowerSelect, e__CubeComputerCommon3_PowerSelect__Mag0Power : CubeComputerCommon3_PowerSelect, e__CubeComputerCommon3_PowerSelect__Mag1Power : CubeComputerCommon3_PowerSelect, e__CubeComputerCommon3_PowerSelect__Gyro0Power : CubeComputerCommon3_PowerSelect, e__CubeComputerCommon3_PowerSelect__Gyro1Power : CubeComputerCommon3_PowerSelect, e__CubeComputerCommon3_PowerSelect__Fss0Power : CubeComputerCommon3_PowerSelect, e__CubeComputerCommon3_PowerSelect__Fss1Power : CubeComputerCommon3_PowerSelect, e__CubeComputerCommon3_PowerSelect__Fss2Power : CubeComputerCommon3_PowerSelect, e__CubeComputerCommon3_PowerSelect__Fss3Power : CubeComputerCommon3_PowerSelect, e__CubeComputerCommon3_PowerSelect__Hss0Power : CubeComputerCommon3_PowerSelect, e__CubeComputerCommon3_PowerSelect__Hss1Power : CubeComputerCommon3_PowerSelect, e__CubeComputerCommon3_PowerSelect__Str0Power : CubeComputerCommon3_PowerSelect, e__CubeComputerCommon3_PowerSelect__Str1Power : CubeComputerCommon3_PowerSelect, e__CubeComputerCommon3_PowerSelect__ExtSensor0Power : CubeComputerCommon3_PowerSelect, e__CubeComputerCommon3_PowerSelect__ExtSensor1Power : CubeComputerCommon3_PowerSelect, e__CubeComputerCommon3_PowerSelect__ExtGyro0Power : CubeComputerCommon3_PowerSelect, e__CubeComputerCommon3_PowerSelect__ExtGyro1Power : CubeComputerCommon3_PowerSelect) -> None:
        """
        Struct 'PowerState' constructor
        
        Attributes
        ---------
        e__CubeComputerCommon3_PowerSelect__Rwl0Power [1] : CubeComputerCommon3_PowerSelect
            RWL0 power state
        e__CubeComputerCommon3_PowerSelect__Rwl1Power [1] : CubeComputerCommon3_PowerSelect
            RWL1 power state
        e__CubeComputerCommon3_PowerSelect__Rwl2Power [1] : CubeComputerCommon3_PowerSelect
            RWL2 power state
        e__CubeComputerCommon3_PowerSelect__Rwl3Power [1] : CubeComputerCommon3_PowerSelect
            RWL3 power state
        e__CubeComputerCommon3_PowerSelect__Mag0Power [1] : CubeComputerCommon3_PowerSelect
            MAG0 power state
        e__CubeComputerCommon3_PowerSelect__Mag1Power [1] : CubeComputerCommon3_PowerSelect
            MAG1 power state
        e__CubeComputerCommon3_PowerSelect__Gyro0Power [1] : CubeComputerCommon3_PowerSelect
            GYR0 power state
        e__CubeComputerCommon3_PowerSelect__Gyro1Power [1] : CubeComputerCommon3_PowerSelect
            GYR1 power state
        e__CubeComputerCommon3_PowerSelect__Fss0Power [1] : CubeComputerCommon3_PowerSelect
            FSS0 power state
        e__CubeComputerCommon3_PowerSelect__Fss1Power [1] : CubeComputerCommon3_PowerSelect
            FSS1 power state
        e__CubeComputerCommon3_PowerSelect__Fss2Power [1] : CubeComputerCommon3_PowerSelect
            FSS2 power state
        e__CubeComputerCommon3_PowerSelect__Fss3Power [1] : CubeComputerCommon3_PowerSelect
            FSS3 power state
        e__CubeComputerCommon3_PowerSelect__Hss0Power [1] : CubeComputerCommon3_PowerSelect
            HSS0 power state
        e__CubeComputerCommon3_PowerSelect__Hss1Power [1] : CubeComputerCommon3_PowerSelect
            HSS1 power state
        e__CubeComputerCommon3_PowerSelect__Str0Power [1] : CubeComputerCommon3_PowerSelect
            STR0 power state
        e__CubeComputerCommon3_PowerSelect__Str1Power [1] : CubeComputerCommon3_PowerSelect
            STR1 power state
        e__CubeComputerCommon3_PowerSelect__ExtSensor0Power [1] : CubeComputerCommon3_PowerSelect
            ExtSensor0 power state
        e__CubeComputerCommon3_PowerSelect__ExtSensor1Power [1] : CubeComputerCommon3_PowerSelect
            ExtSensor1 power state
        e__CubeComputerCommon3_PowerSelect__ExtGyro0Power [1] : CubeComputerCommon3_PowerSelect
            EXTGYR0 power state
        e__CubeComputerCommon3_PowerSelect__ExtGyro1Power [1] : CubeComputerCommon3_PowerSelect
            EXTGYR1 power state
        """
        
        pass
        
    def get_Rwl0Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::Rwl0Power' structure field
        
        RWL0 power state
        """
        
        pass
    
    def get_Rwl1Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::Rwl1Power' structure field
        
        RWL1 power state
        """
        
        pass
    
    def get_Rwl2Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::Rwl2Power' structure field
        
        RWL2 power state
        """
        
        pass
    
    def get_Rwl3Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::Rwl3Power' structure field
        
        RWL3 power state
        """
        
        pass
    
    def get_Mag0Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::Mag0Power' structure field
        
        MAG0 power state
        """
        
        pass
    
    def get_Mag1Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::Mag1Power' structure field
        
        MAG1 power state
        """
        
        pass
    
    def get_Gyro0Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::Gyro0Power' structure field
        
        GYR0 power state
        """
        
        pass
    
    def get_Gyro1Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::Gyro1Power' structure field
        
        GYR1 power state
        """
        
        pass
    
    def get_Fss0Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::Fss0Power' structure field
        
        FSS0 power state
        """
        
        pass
    
    def get_Fss1Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::Fss1Power' structure field
        
        FSS1 power state
        """
        
        pass
    
    def get_Fss2Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::Fss2Power' structure field
        
        FSS2 power state
        """
        
        pass
    
    def get_Fss3Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::Fss3Power' structure field
        
        FSS3 power state
        """
        
        pass
    
    def get_Hss0Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::Hss0Power' structure field
        
        HSS0 power state
        """
        
        pass
    
    def get_Hss1Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::Hss1Power' structure field
        
        HSS1 power state
        """
        
        pass
    
    def get_Str0Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::Str0Power' structure field
        
        STR0 power state
        """
        
        pass
    
    def get_Str1Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::Str1Power' structure field
        
        STR1 power state
        """
        
        pass
    
    def get_ExtSensor0Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::ExtSensor0Power' structure field
        
        ExtSensor0 power state
        """
        
        pass
    
    def get_ExtSensor1Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::ExtSensor1Power' structure field
        
        ExtSensor1 power state
        """
        
        pass
    
    def get_ExtGyro0Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::ExtGyro0Power' structure field
        
        EXTGYR0 power state
        """
        
        pass
    
    def get_ExtGyro1Power(self) -> CubeComputerCommon3_PowerSelect:
        """
        A getter for the 'PowerState::ExtGyro1Power' structure field
        
        EXTGYR1 power state
        """
        
        pass

def PowerState_make_from_buf(buf : bytes) -> PowerState:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class EraseLogData:
    """
    A Python class to represent struct objects of type 'EraseLogData'
    
    Parameter structure for interface EraseLogData
    """

    def __init__(self, e__CubeComputerCommon3_EraseMagicNumbers__magicNumber : CubeComputerCommon3_EraseMagicNumbers) -> None:
        """
        Struct 'EraseLogData' constructor
        
        Attributes
        ---------
        e__CubeComputerCommon3_EraseMagicNumbers__magicNumber [1] : CubeComputerCommon3_EraseMagicNumbers
            Magic number to avoid erroneous formats
        """
        
        pass
        
    def get_magicNumber(self) -> CubeComputerCommon3_EraseMagicNumbers:
        """
        A getter for the 'EraseLogData::magicNumber' structure field
        
        Magic number to avoid erroneous formats
        """
        
        pass

def EraseLogData_make_from_buf(buf : bytes) -> EraseLogData:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TelemtryLogStatus:
    """
    A Python class to represent struct objects of type 'TelemtryLogStatus'
    
    Parameter structure for interface TelemtryLogStatus
    """

    def __init__(self, uint8__numberOfEntriesQueued : int, uint8__numberOfTlmIterations : int, uint32__numberOfEntries : int, uint32__oldestEntryUnix : int, uint32__latestEntryUnix : int, uint32__writeCounter : int, e__CubeComputerCommon3_TlmLogReadQueueState__readQueueState : CubeComputerCommon3_TlmLogReadQueueState) -> None:
        """
        Struct 'TelemtryLogStatus' constructor
        
        Attributes
        ---------
        uint8__numberOfEntriesQueued [1] : int
            The number of entries in the queue
        uint8__numberOfTlmIterations [1] : int
            The number of telemetry request iterations performed for the current log entry (0-4)
        uint32__numberOfEntries [1] : int
            The total number of entries contained in the telemetry log
        uint32__oldestEntryUnix [1] : int
            Timestamp of the oldest entry unix time in seconds
        uint32__latestEntryUnix [1] : int
            Timestamp of the latest entry unix time in seconds
        uint32__writeCounter [1] : int
            The current event write counter
        e__CubeComputerCommon3_TlmLogReadQueueState__readQueueState [1] : CubeComputerCommon3_TlmLogReadQueueState
            The state of the read queue
        """
        
        pass
        
    def get_numberOfEntriesQueued(self) -> int:
        """
        A getter for the 'TelemtryLogStatus::numberOfEntriesQueued' structure field
        
        The number of entries in the queue
        """
        
        pass
    
    def get_numberOfTlmIterations(self) -> int:
        """
        A getter for the 'TelemtryLogStatus::numberOfTlmIterations' structure field
        
        The number of telemetry request iterations performed for the current log entry (0-4)
        """
        
        pass
    
    def get_numberOfEntries(self) -> int:
        """
        A getter for the 'TelemtryLogStatus::numberOfEntries' structure field
        
        The total number of entries contained in the telemetry log
        """
        
        pass
    
    def get_oldestEntryUnix(self) -> int:
        """
        A getter for the 'TelemtryLogStatus::oldestEntryUnix' structure field
        
        Timestamp of the oldest entry unix time in seconds
        """
        
        pass
    
    def get_latestEntryUnix(self) -> int:
        """
        A getter for the 'TelemtryLogStatus::latestEntryUnix' structure field
        
        Timestamp of the latest entry unix time in seconds
        """
        
        pass
    
    def get_writeCounter(self) -> int:
        """
        A getter for the 'TelemtryLogStatus::writeCounter' structure field
        
        The current event write counter
        """
        
        pass
    
    def get_readQueueState(self) -> CubeComputerCommon3_TlmLogReadQueueState:
        """
        A getter for the 'TelemtryLogStatus::readQueueState' structure field
        
        The state of the read queue
        """
        
        pass

def TelemtryLogStatus_make_from_buf(buf : bytes) -> TelemtryLogStatus:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class PortMap:
    """
    A Python class to represent struct objects of type 'PortMap'
    
    Parameter structure for interface PortMap
    """

    def __init__(self, e__CommonFrameworkTypes1_NodeType__Sensor1NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Sensor1AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Sensor1SerialInt : int, uint32__Sensor1Address : int, e__CommonFrameworkTypes1_NodeType__Sensor2NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Sensor2AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Sensor2SerialInt : int, uint32__Sensor2Address : int, e__CommonFrameworkTypes1_NodeType__Sensor3NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Sensor3AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Sensor3SerialInt : int, uint32__Sensor3Address : int, e__CommonFrameworkTypes1_NodeType__Sensor4NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Sensor4AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Sensor4SerialInt : int, uint32__Sensor4Address : int, e__CommonFrameworkTypes1_NodeType__Sensor5NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Sensor5AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Sensor5SerialInt : int, uint32__Sensor5Address : int, e__CommonFrameworkTypes1_NodeType__Sensor6NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Sensor6AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Sensor6SerialInt : int, uint32__Sensor6Address : int, e__CommonFrameworkTypes1_NodeType__Sensor7NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Sensor7AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Sensor7SerialInt : int, uint32__Sensor7Address : int, e__CommonFrameworkTypes1_NodeType__Sensor8NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Sensor8AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Sensor8SerialInt : int, uint32__Sensor8Address : int, e__CommonFrameworkTypes1_NodeType__Wheel1NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Wheel1AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Wheel1SerialInt : int, uint32__Wheel1Address : int, e__CommonFrameworkTypes1_NodeType__Wheel2NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Wheel2AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Wheel2SerialInt : int, uint32__Wheel2Address : int, e__CommonFrameworkTypes1_NodeType__Wheel3NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Wheel3AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Wheel3SerialInt : int, uint32__Wheel3Address : int, e__CommonFrameworkTypes1_NodeType__Wheel4NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Wheel4AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Wheel4SerialInt : int, uint32__Wheel4Address : int) -> None:
        """
        Struct 'PortMap' constructor
        
        Attributes
        ---------
        e__CommonFrameworkTypes1_NodeType__Sensor1NodeType [1] : CommonFrameworkTypes1_NodeType
            Sensor 1 port - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Sensor1AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Sensor 1 port - Abstract Node type identifier
        uint32__Sensor1SerialInt [1] : int
            Sensor 1 port - Serial Number Integer Respresentation
        uint32__Sensor1Address [1] : int
            Sensor 1 port - CAN Address
        e__CommonFrameworkTypes1_NodeType__Sensor2NodeType [1] : CommonFrameworkTypes1_NodeType
            Sensor 2 port - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Sensor2AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Sensor 2 port - Abstract Node type identifier
        uint32__Sensor2SerialInt [1] : int
            Sensor 2 port - Serial Number Integer Respresentation
        uint32__Sensor2Address [1] : int
            Sensor 2 port - CAN Address
        e__CommonFrameworkTypes1_NodeType__Sensor3NodeType [1] : CommonFrameworkTypes1_NodeType
            Sensor 3 port - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Sensor3AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Sensor 3 port - Abstract Node type identifier
        uint32__Sensor3SerialInt [1] : int
            Sensor 3 port - Serial Number Integer Respresentation
        uint32__Sensor3Address [1] : int
            Sensor 3 port - CAN Address
        e__CommonFrameworkTypes1_NodeType__Sensor4NodeType [1] : CommonFrameworkTypes1_NodeType
            Sensor 4 port - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Sensor4AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Sensor 4 port - Abstract Node type identifier
        uint32__Sensor4SerialInt [1] : int
            Sensor 4 port - Serial Number Integer Respresentation
        uint32__Sensor4Address [1] : int
            Sensor 4 port - CAN Address
        e__CommonFrameworkTypes1_NodeType__Sensor5NodeType [1] : CommonFrameworkTypes1_NodeType
            Sensor 5 port - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Sensor5AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Sensor 5 port - Abstract Node type identifier
        uint32__Sensor5SerialInt [1] : int
            Sensor 5 port - Serial Number Integer Respresentation
        uint32__Sensor5Address [1] : int
            Sensor 5 port - CAN Address
        e__CommonFrameworkTypes1_NodeType__Sensor6NodeType [1] : CommonFrameworkTypes1_NodeType
            Sensor 6 port - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Sensor6AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Sensor 6 port - Abstract Node type identifier
        uint32__Sensor6SerialInt [1] : int
            Sensor 6 port - Serial Number Integer Respresentation
        uint32__Sensor6Address [1] : int
            Sensor 6 port - CAN Address
        e__CommonFrameworkTypes1_NodeType__Sensor7NodeType [1] : CommonFrameworkTypes1_NodeType
            Sensor 7 port - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Sensor7AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Sensor 7 port - Abstract Node type identifier
        uint32__Sensor7SerialInt [1] : int
            Sensor 7 port - Serial Number Integer Respresentation
        uint32__Sensor7Address [1] : int
            Sensor 7 port - CAN Address
        e__CommonFrameworkTypes1_NodeType__Sensor8NodeType [1] : CommonFrameworkTypes1_NodeType
            Sensor 8 port - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Sensor8AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Sensor 8 port - Abstract Node type identifier
        uint32__Sensor8SerialInt [1] : int
            Sensor 8 port - Serial Number Integer Respresentation
        uint32__Sensor8Address [1] : int
            Sensor 8 port - CAN Address
        e__CommonFrameworkTypes1_NodeType__Wheel1NodeType [1] : CommonFrameworkTypes1_NodeType
            Wheel 1 port - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Wheel1AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Wheel 1 port - Abstract Node type identifier
        uint32__Wheel1SerialInt [1] : int
            Wheel 1 port - Serial Number Integer Respresentation
        uint32__Wheel1Address [1] : int
            Wheel 1 port - CAN Address
        e__CommonFrameworkTypes1_NodeType__Wheel2NodeType [1] : CommonFrameworkTypes1_NodeType
            Wheel 2 port - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Wheel2AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Wheel 2 port - Abstract Node type identifier
        uint32__Wheel2SerialInt [1] : int
            Wheel 2 port - Serial Number Integer Respresentation
        uint32__Wheel2Address [1] : int
            Wheel 2 port - CAN Address
        e__CommonFrameworkTypes1_NodeType__Wheel3NodeType [1] : CommonFrameworkTypes1_NodeType
            Wheel 3 port - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Wheel3AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Wheel 3 port - Abstract Node type identifier
        uint32__Wheel3SerialInt [1] : int
            Wheel 3 port - Serial Number Integer Respresentation
        uint32__Wheel3Address [1] : int
            Wheel 3 port - CAN Address
        e__CommonFrameworkTypes1_NodeType__Wheel4NodeType [1] : CommonFrameworkTypes1_NodeType
            Wheel 4 port - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Wheel4AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Wheel 4 port - Abstract Node type identifier
        uint32__Wheel4SerialInt [1] : int
            Wheel 4 port - Serial Number Integer Respresentation
        uint32__Wheel4Address [1] : int
            Wheel 4 port - CAN Address
        """
        
        pass
        
    def get_Sensor1NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'PortMap::Sensor1NodeType' structure field
        
        Sensor 1 port - Node type identifier
        """
        
        pass
    
    def get_Sensor1AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'PortMap::Sensor1AbstractType' structure field
        
        Sensor 1 port - Abstract Node type identifier
        """
        
        pass
    
    def get_Sensor1SerialInt(self) -> int:
        """
        A getter for the 'PortMap::Sensor1SerialInt' structure field
        
        Sensor 1 port - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Sensor1Address(self) -> int:
        """
        A getter for the 'PortMap::Sensor1Address' structure field
        
        Sensor 1 port - CAN Address
        """
        
        pass
    
    def get_Sensor2NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'PortMap::Sensor2NodeType' structure field
        
        Sensor 2 port - Node type identifier
        """
        
        pass
    
    def get_Sensor2AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'PortMap::Sensor2AbstractType' structure field
        
        Sensor 2 port - Abstract Node type identifier
        """
        
        pass
    
    def get_Sensor2SerialInt(self) -> int:
        """
        A getter for the 'PortMap::Sensor2SerialInt' structure field
        
        Sensor 2 port - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Sensor2Address(self) -> int:
        """
        A getter for the 'PortMap::Sensor2Address' structure field
        
        Sensor 2 port - CAN Address
        """
        
        pass
    
    def get_Sensor3NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'PortMap::Sensor3NodeType' structure field
        
        Sensor 3 port - Node type identifier
        """
        
        pass
    
    def get_Sensor3AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'PortMap::Sensor3AbstractType' structure field
        
        Sensor 3 port - Abstract Node type identifier
        """
        
        pass
    
    def get_Sensor3SerialInt(self) -> int:
        """
        A getter for the 'PortMap::Sensor3SerialInt' structure field
        
        Sensor 3 port - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Sensor3Address(self) -> int:
        """
        A getter for the 'PortMap::Sensor3Address' structure field
        
        Sensor 3 port - CAN Address
        """
        
        pass
    
    def get_Sensor4NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'PortMap::Sensor4NodeType' structure field
        
        Sensor 4 port - Node type identifier
        """
        
        pass
    
    def get_Sensor4AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'PortMap::Sensor4AbstractType' structure field
        
        Sensor 4 port - Abstract Node type identifier
        """
        
        pass
    
    def get_Sensor4SerialInt(self) -> int:
        """
        A getter for the 'PortMap::Sensor4SerialInt' structure field
        
        Sensor 4 port - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Sensor4Address(self) -> int:
        """
        A getter for the 'PortMap::Sensor4Address' structure field
        
        Sensor 4 port - CAN Address
        """
        
        pass
    
    def get_Sensor5NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'PortMap::Sensor5NodeType' structure field
        
        Sensor 5 port - Node type identifier
        """
        
        pass
    
    def get_Sensor5AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'PortMap::Sensor5AbstractType' structure field
        
        Sensor 5 port - Abstract Node type identifier
        """
        
        pass
    
    def get_Sensor5SerialInt(self) -> int:
        """
        A getter for the 'PortMap::Sensor5SerialInt' structure field
        
        Sensor 5 port - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Sensor5Address(self) -> int:
        """
        A getter for the 'PortMap::Sensor5Address' structure field
        
        Sensor 5 port - CAN Address
        """
        
        pass
    
    def get_Sensor6NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'PortMap::Sensor6NodeType' structure field
        
        Sensor 6 port - Node type identifier
        """
        
        pass
    
    def get_Sensor6AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'PortMap::Sensor6AbstractType' structure field
        
        Sensor 6 port - Abstract Node type identifier
        """
        
        pass
    
    def get_Sensor6SerialInt(self) -> int:
        """
        A getter for the 'PortMap::Sensor6SerialInt' structure field
        
        Sensor 6 port - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Sensor6Address(self) -> int:
        """
        A getter for the 'PortMap::Sensor6Address' structure field
        
        Sensor 6 port - CAN Address
        """
        
        pass
    
    def get_Sensor7NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'PortMap::Sensor7NodeType' structure field
        
        Sensor 7 port - Node type identifier
        """
        
        pass
    
    def get_Sensor7AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'PortMap::Sensor7AbstractType' structure field
        
        Sensor 7 port - Abstract Node type identifier
        """
        
        pass
    
    def get_Sensor7SerialInt(self) -> int:
        """
        A getter for the 'PortMap::Sensor7SerialInt' structure field
        
        Sensor 7 port - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Sensor7Address(self) -> int:
        """
        A getter for the 'PortMap::Sensor7Address' structure field
        
        Sensor 7 port - CAN Address
        """
        
        pass
    
    def get_Sensor8NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'PortMap::Sensor8NodeType' structure field
        
        Sensor 8 port - Node type identifier
        """
        
        pass
    
    def get_Sensor8AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'PortMap::Sensor8AbstractType' structure field
        
        Sensor 8 port - Abstract Node type identifier
        """
        
        pass
    
    def get_Sensor8SerialInt(self) -> int:
        """
        A getter for the 'PortMap::Sensor8SerialInt' structure field
        
        Sensor 8 port - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Sensor8Address(self) -> int:
        """
        A getter for the 'PortMap::Sensor8Address' structure field
        
        Sensor 8 port - CAN Address
        """
        
        pass
    
    def get_Wheel1NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'PortMap::Wheel1NodeType' structure field
        
        Wheel 1 port - Node type identifier
        """
        
        pass
    
    def get_Wheel1AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'PortMap::Wheel1AbstractType' structure field
        
        Wheel 1 port - Abstract Node type identifier
        """
        
        pass
    
    def get_Wheel1SerialInt(self) -> int:
        """
        A getter for the 'PortMap::Wheel1SerialInt' structure field
        
        Wheel 1 port - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Wheel1Address(self) -> int:
        """
        A getter for the 'PortMap::Wheel1Address' structure field
        
        Wheel 1 port - CAN Address
        """
        
        pass
    
    def get_Wheel2NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'PortMap::Wheel2NodeType' structure field
        
        Wheel 2 port - Node type identifier
        """
        
        pass
    
    def get_Wheel2AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'PortMap::Wheel2AbstractType' structure field
        
        Wheel 2 port - Abstract Node type identifier
        """
        
        pass
    
    def get_Wheel2SerialInt(self) -> int:
        """
        A getter for the 'PortMap::Wheel2SerialInt' structure field
        
        Wheel 2 port - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Wheel2Address(self) -> int:
        """
        A getter for the 'PortMap::Wheel2Address' structure field
        
        Wheel 2 port - CAN Address
        """
        
        pass
    
    def get_Wheel3NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'PortMap::Wheel3NodeType' structure field
        
        Wheel 3 port - Node type identifier
        """
        
        pass
    
    def get_Wheel3AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'PortMap::Wheel3AbstractType' structure field
        
        Wheel 3 port - Abstract Node type identifier
        """
        
        pass
    
    def get_Wheel3SerialInt(self) -> int:
        """
        A getter for the 'PortMap::Wheel3SerialInt' structure field
        
        Wheel 3 port - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Wheel3Address(self) -> int:
        """
        A getter for the 'PortMap::Wheel3Address' structure field
        
        Wheel 3 port - CAN Address
        """
        
        pass
    
    def get_Wheel4NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'PortMap::Wheel4NodeType' structure field
        
        Wheel 4 port - Node type identifier
        """
        
        pass
    
    def get_Wheel4AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'PortMap::Wheel4AbstractType' structure field
        
        Wheel 4 port - Abstract Node type identifier
        """
        
        pass
    
    def get_Wheel4SerialInt(self) -> int:
        """
        A getter for the 'PortMap::Wheel4SerialInt' structure field
        
        Wheel 4 port - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Wheel4Address(self) -> int:
        """
        A getter for the 'PortMap::Wheel4Address' structure field
        
        Wheel 4 port - CAN Address
        """
        
        pass

def PortMap_make_from_buf(buf : bytes) -> PortMap:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ImageFileInfo:
    """
    A Python class to represent struct objects of type 'ImageFileInfo'
    
    Parameter structure for interface ImageFileInfo
    """

    def __init__(self, uint32__FileHandle : int, e__CommonFrameworkTypes1_AbstractNode__NodeType : CommonFrameworkTypes1_AbstractNode, uint32__Timestamp : int, uint32__Size : int, bool__First : int, bool__Last : int, bool__IsValid : int) -> None:
        """
        Struct 'ImageFileInfo' constructor
        
        Attributes
        ---------
        uint32__FileHandle [1] : int
            File handle of this file.
        e__CommonFrameworkTypes1_AbstractNode__NodeType [1] : CommonFrameworkTypes1_AbstractNode
            The node that this file was sourced from.
        uint32__Timestamp [1] : int
            Timestamp of when this file was stored.
        uint32__Size [1] : int
            Size of the file in bytes.
        bool__First [1] : int
            Set if this file is the first stored image.
        bool__Last [1] : int
            Set if this file is the last stored image. If set, subsequent requests will wrap to the first file.
        bool__IsValid [1] : int
            Set if this file's Meta data was CRC-validated.
        """
        
        pass
        
    def get_FileHandle(self) -> int:
        """
        A getter for the 'ImageFileInfo::FileHandle' structure field
        
        File handle of this file.
        """
        
        pass
    
    def get_NodeType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'ImageFileInfo::NodeType' structure field
        
        The node that this file was sourced from.
        """
        
        pass
    
    def get_Timestamp(self) -> int:
        """
        A getter for the 'ImageFileInfo::Timestamp' structure field
        
        Timestamp of when this file was stored.
        """
        
        pass
    
    def get_Size(self) -> int:
        """
        A getter for the 'ImageFileInfo::Size' structure field
        
        Size of the file in bytes.
        """
        
        pass
    
    def get_First(self) -> int:
        """
        A getter for the 'ImageFileInfo::First' structure field
        
        Set if this file is the first stored image.
        """
        
        pass
    
    def get_Last(self) -> int:
        """
        A getter for the 'ImageFileInfo::Last' structure field
        
        Set if this file is the last stored image. If set, subsequent requests will wrap to the first file.
        """
        
        pass
    
    def get_IsValid(self) -> int:
        """
        A getter for the 'ImageFileInfo::IsValid' structure field
        
        Set if this file's Meta data was CRC-validated.
        """
        
        pass

def ImageFileInfo_make_from_buf(buf : bytes) -> ImageFileInfo:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ImageTransferSetup:
    """
    A Python class to represent struct objects of type 'ImageTransferSetup'
    
    Parameter structure for interface ImageTransferSetup
    """

    def __init__(self, e__CubeComputerCommon3_ImageTransferOpCode__OpCode : CubeComputerCommon3_ImageTransferOpCode, e__CommonFrameworkTypes1_AbstractNode__NodeType : CommonFrameworkTypes1_AbstractNode, uint32__FileHandle : int) -> None:
        """
        Struct 'ImageTransferSetup' constructor
        
        Attributes
        ---------
        e__CubeComputerCommon3_ImageTransferOpCode__OpCode [1] : CubeComputerCommon3_ImageTransferOpCode
            Operation code.
        e__CommonFrameworkTypes1_AbstractNode__NodeType [1] : CommonFrameworkTypes1_AbstractNode
            Target node type for image storage and download direct operation codes.
        uint32__FileHandle [1] : int
            Target file for download and info operation codes.
        """
        
        pass
        
    def get_OpCode(self) -> CubeComputerCommon3_ImageTransferOpCode:
        """
        A getter for the 'ImageTransferSetup::OpCode' structure field
        
        Operation code.
        """
        
        pass
    
    def get_NodeType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'ImageTransferSetup::NodeType' structure field
        
        Target node type for image storage and download direct operation codes.
        """
        
        pass
    
    def get_FileHandle(self) -> int:
        """
        A getter for the 'ImageTransferSetup::FileHandle' structure field
        
        Target file for download and info operation codes.
        """
        
        pass

def ImageTransferSetup_make_from_buf(buf : bytes) -> ImageTransferSetup:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class PassThrough:
    """
    A Python class to represent struct objects of type 'PassThrough'
    
    Parameter structure for interface PassThrough
    """

    def __init__(self, e__CommonFrameworkTypes1_AbstractNode__TargetNode : CommonFrameworkTypes1_AbstractNode) -> None:
        """
        Struct 'PassThrough' constructor
        
        Attributes
        ---------
        e__CommonFrameworkTypes1_AbstractNode__TargetNode [1] : CommonFrameworkTypes1_AbstractNode
            Target Node
        """
        
        pass
        
    def get_TargetNode(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'PassThrough::TargetNode' structure field
        
        Target Node
        """
        
        pass

def PassThrough_make_from_buf(buf : bytes) -> PassThrough:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class DummyEvent:
    """
    A Python class to represent struct objects of type 'DummyEvent'
    
    Parameter structure for interface DummyEvent
    """

    def __init__(self, e__CubeComputerCommon3_EventClass__eventClass : CubeComputerCommon3_EventClass, e__CommonFrameworkTypes1_AbstractNode__eventSource : CommonFrameworkTypes1_AbstractNode, uint16__eventType : int, a__uint8__8__eventData : list[int]) -> None:
        """
        Struct 'DummyEvent' constructor
        
        Attributes
        ---------
        e__CubeComputerCommon3_EventClass__eventClass [1] : CubeComputerCommon3_EventClass
            This field contains the class of the event
        e__CommonFrameworkTypes1_AbstractNode__eventSource [1] : CommonFrameworkTypes1_AbstractNode
            This field contains the source of the event
        uint16__eventType [1] : int
            This field contains the type of the event
        a__uint8__8__eventData [8] : list[int]
            This field contains the data of the event
        """
        
        pass
        
    def get_eventClass(self) -> CubeComputerCommon3_EventClass:
        """
        A getter for the 'DummyEvent::eventClass' structure field
        
        This field contains the class of the event
        """
        
        pass
    
    def get_eventSource(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'DummyEvent::eventSource' structure field
        
        This field contains the source of the event
        """
        
        pass
    
    def get_eventType(self) -> int:
        """
        A getter for the 'DummyEvent::eventType' structure field
        
        This field contains the type of the event
        """
        
        pass
    
    def get_eventData(self) -> list[int]:
        """
        A getter for the 'DummyEvent::eventData' structure field
        
        This field contains the data of the event
        """
        
        pass

def DummyEvent_make_from_buf(buf : bytes) -> DummyEvent:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ExpectedNodes:
    """
    A Python class to represent struct objects of type 'ExpectedNodes'
    
    Parameter structure for interface ExpectedNodes
    """

    def __init__(self, e__CommonFrameworkTypes1_NodeType__Expected0NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Expected0AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Expected0SerialInt : int, e__CommonFrameworkTypes1_NodeType__Expected1NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Expected1AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Expected1SerialInt : int, e__CommonFrameworkTypes1_NodeType__Expected2NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Expected2AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Expected2SerialInt : int, e__CommonFrameworkTypes1_NodeType__Expected3NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Expected3AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Expected3SerialInt : int, e__CommonFrameworkTypes1_NodeType__Expected4NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Expected4AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Expected4SerialInt : int, e__CommonFrameworkTypes1_NodeType__Expected5NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Expected5AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Expected5SerialInt : int, e__CommonFrameworkTypes1_NodeType__Expected6NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Expected6AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Expected6SerialInt : int, e__CommonFrameworkTypes1_NodeType__Expected7NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Expected7AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Expected7SerialInt : int, e__CommonFrameworkTypes1_NodeType__Expected8NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Expected8AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Expected8SerialInt : int, e__CommonFrameworkTypes1_NodeType__Expected9NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Expected9AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Expected9SerialInt : int, e__CommonFrameworkTypes1_NodeType__Expected10NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Expected10AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Expected10SerialInt : int, e__CommonFrameworkTypes1_NodeType__Expected11NodeType : CommonFrameworkTypes1_NodeType, e__CommonFrameworkTypes1_AbstractNode__Expected11AbstractType : CommonFrameworkTypes1_AbstractNode, uint32__Expected11SerialInt : int) -> None:
        """
        Struct 'ExpectedNodes' constructor
        
        Attributes
        ---------
        e__CommonFrameworkTypes1_NodeType__Expected0NodeType [1] : CommonFrameworkTypes1_NodeType
            Slot 0 - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Expected0AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Slot 0 - Abstract Node type identifier
        uint32__Expected0SerialInt [1] : int
            Slot 0 - Serial Number Integer Respresentation
        e__CommonFrameworkTypes1_NodeType__Expected1NodeType [1] : CommonFrameworkTypes1_NodeType
            Slot 1 - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Expected1AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Slot 1 - Abstract Node type identifier
        uint32__Expected1SerialInt [1] : int
            Slot 1 - Serial Number Integer Respresentation
        e__CommonFrameworkTypes1_NodeType__Expected2NodeType [1] : CommonFrameworkTypes1_NodeType
            Slot 2 - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Expected2AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Slot 2 - Abstract Node type identifier
        uint32__Expected2SerialInt [1] : int
            Slot 2 - Serial Number Integer Respresentation
        e__CommonFrameworkTypes1_NodeType__Expected3NodeType [1] : CommonFrameworkTypes1_NodeType
            Slot 3 - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Expected3AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Slot 3 - Abstract Node type identifier
        uint32__Expected3SerialInt [1] : int
            Slot 3 - Serial Number Integer Respresentation
        e__CommonFrameworkTypes1_NodeType__Expected4NodeType [1] : CommonFrameworkTypes1_NodeType
            Slot 4 - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Expected4AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Slot 4 - Abstract Node type identifier
        uint32__Expected4SerialInt [1] : int
            Slot 4 - Serial Number Integer Respresentation
        e__CommonFrameworkTypes1_NodeType__Expected5NodeType [1] : CommonFrameworkTypes1_NodeType
            Slot 5 - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Expected5AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Slot 5 - Abstract Node type identifier
        uint32__Expected5SerialInt [1] : int
            Slot 5 - Serial Number Integer Respresentation
        e__CommonFrameworkTypes1_NodeType__Expected6NodeType [1] : CommonFrameworkTypes1_NodeType
            Slot 6 - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Expected6AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Slot 6 - Abstract Node type identifier
        uint32__Expected6SerialInt [1] : int
            Slot 6 - Serial Number Integer Respresentation
        e__CommonFrameworkTypes1_NodeType__Expected7NodeType [1] : CommonFrameworkTypes1_NodeType
            Slot 7 - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Expected7AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Slot 7 - Abstract Node type identifier
        uint32__Expected7SerialInt [1] : int
            Slot 7 - Serial Number Integer Respresentation
        e__CommonFrameworkTypes1_NodeType__Expected8NodeType [1] : CommonFrameworkTypes1_NodeType
            Slot 8 - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Expected8AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Slot 8 - Abstract Node type identifier
        uint32__Expected8SerialInt [1] : int
            Slot 8 - Serial Number Integer Respresentation
        e__CommonFrameworkTypes1_NodeType__Expected9NodeType [1] : CommonFrameworkTypes1_NodeType
            Slot 9 - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Expected9AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Slot 9 - Abstract Node type identifier
        uint32__Expected9SerialInt [1] : int
            Slot 9 - Serial Number Integer Respresentation
        e__CommonFrameworkTypes1_NodeType__Expected10NodeType [1] : CommonFrameworkTypes1_NodeType
            Slot 10 - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Expected10AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Slot 10 - Abstract Node type identifier
        uint32__Expected10SerialInt [1] : int
            Slot 10 - Serial Number Integer Respresentation
        e__CommonFrameworkTypes1_NodeType__Expected11NodeType [1] : CommonFrameworkTypes1_NodeType
            Slot 11 - Node type identifier
        e__CommonFrameworkTypes1_AbstractNode__Expected11AbstractType [1] : CommonFrameworkTypes1_AbstractNode
            Slot 11 - Abstract Node type identifier
        uint32__Expected11SerialInt [1] : int
            Slot 11 - Serial Number Integer Respresentation
        """
        
        pass
        
    def get_Expected0NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'ExpectedNodes::Expected0NodeType' structure field
        
        Slot 0 - Node type identifier
        """
        
        pass
    
    def get_Expected0AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'ExpectedNodes::Expected0AbstractType' structure field
        
        Slot 0 - Abstract Node type identifier
        """
        
        pass
    
    def get_Expected0SerialInt(self) -> int:
        """
        A getter for the 'ExpectedNodes::Expected0SerialInt' structure field
        
        Slot 0 - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Expected1NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'ExpectedNodes::Expected1NodeType' structure field
        
        Slot 1 - Node type identifier
        """
        
        pass
    
    def get_Expected1AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'ExpectedNodes::Expected1AbstractType' structure field
        
        Slot 1 - Abstract Node type identifier
        """
        
        pass
    
    def get_Expected1SerialInt(self) -> int:
        """
        A getter for the 'ExpectedNodes::Expected1SerialInt' structure field
        
        Slot 1 - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Expected2NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'ExpectedNodes::Expected2NodeType' structure field
        
        Slot 2 - Node type identifier
        """
        
        pass
    
    def get_Expected2AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'ExpectedNodes::Expected2AbstractType' structure field
        
        Slot 2 - Abstract Node type identifier
        """
        
        pass
    
    def get_Expected2SerialInt(self) -> int:
        """
        A getter for the 'ExpectedNodes::Expected2SerialInt' structure field
        
        Slot 2 - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Expected3NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'ExpectedNodes::Expected3NodeType' structure field
        
        Slot 3 - Node type identifier
        """
        
        pass
    
    def get_Expected3AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'ExpectedNodes::Expected3AbstractType' structure field
        
        Slot 3 - Abstract Node type identifier
        """
        
        pass
    
    def get_Expected3SerialInt(self) -> int:
        """
        A getter for the 'ExpectedNodes::Expected3SerialInt' structure field
        
        Slot 3 - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Expected4NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'ExpectedNodes::Expected4NodeType' structure field
        
        Slot 4 - Node type identifier
        """
        
        pass
    
    def get_Expected4AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'ExpectedNodes::Expected4AbstractType' structure field
        
        Slot 4 - Abstract Node type identifier
        """
        
        pass
    
    def get_Expected4SerialInt(self) -> int:
        """
        A getter for the 'ExpectedNodes::Expected4SerialInt' structure field
        
        Slot 4 - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Expected5NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'ExpectedNodes::Expected5NodeType' structure field
        
        Slot 5 - Node type identifier
        """
        
        pass
    
    def get_Expected5AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'ExpectedNodes::Expected5AbstractType' structure field
        
        Slot 5 - Abstract Node type identifier
        """
        
        pass
    
    def get_Expected5SerialInt(self) -> int:
        """
        A getter for the 'ExpectedNodes::Expected5SerialInt' structure field
        
        Slot 5 - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Expected6NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'ExpectedNodes::Expected6NodeType' structure field
        
        Slot 6 - Node type identifier
        """
        
        pass
    
    def get_Expected6AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'ExpectedNodes::Expected6AbstractType' structure field
        
        Slot 6 - Abstract Node type identifier
        """
        
        pass
    
    def get_Expected6SerialInt(self) -> int:
        """
        A getter for the 'ExpectedNodes::Expected6SerialInt' structure field
        
        Slot 6 - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Expected7NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'ExpectedNodes::Expected7NodeType' structure field
        
        Slot 7 - Node type identifier
        """
        
        pass
    
    def get_Expected7AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'ExpectedNodes::Expected7AbstractType' structure field
        
        Slot 7 - Abstract Node type identifier
        """
        
        pass
    
    def get_Expected7SerialInt(self) -> int:
        """
        A getter for the 'ExpectedNodes::Expected7SerialInt' structure field
        
        Slot 7 - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Expected8NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'ExpectedNodes::Expected8NodeType' structure field
        
        Slot 8 - Node type identifier
        """
        
        pass
    
    def get_Expected8AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'ExpectedNodes::Expected8AbstractType' structure field
        
        Slot 8 - Abstract Node type identifier
        """
        
        pass
    
    def get_Expected8SerialInt(self) -> int:
        """
        A getter for the 'ExpectedNodes::Expected8SerialInt' structure field
        
        Slot 8 - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Expected9NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'ExpectedNodes::Expected9NodeType' structure field
        
        Slot 9 - Node type identifier
        """
        
        pass
    
    def get_Expected9AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'ExpectedNodes::Expected9AbstractType' structure field
        
        Slot 9 - Abstract Node type identifier
        """
        
        pass
    
    def get_Expected9SerialInt(self) -> int:
        """
        A getter for the 'ExpectedNodes::Expected9SerialInt' structure field
        
        Slot 9 - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Expected10NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'ExpectedNodes::Expected10NodeType' structure field
        
        Slot 10 - Node type identifier
        """
        
        pass
    
    def get_Expected10AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'ExpectedNodes::Expected10AbstractType' structure field
        
        Slot 10 - Abstract Node type identifier
        """
        
        pass
    
    def get_Expected10SerialInt(self) -> int:
        """
        A getter for the 'ExpectedNodes::Expected10SerialInt' structure field
        
        Slot 10 - Serial Number Integer Respresentation
        """
        
        pass
    
    def get_Expected11NodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'ExpectedNodes::Expected11NodeType' structure field
        
        Slot 11 - Node type identifier
        """
        
        pass
    
    def get_Expected11AbstractType(self) -> CommonFrameworkTypes1_AbstractNode:
        """
        A getter for the 'ExpectedNodes::Expected11AbstractType' structure field
        
        Slot 11 - Abstract Node type identifier
        """
        
        pass
    
    def get_Expected11SerialInt(self) -> int:
        """
        A getter for the 'ExpectedNodes::Expected11SerialInt' structure field
        
        Slot 11 - Serial Number Integer Respresentation
        """
        
        pass

def ExpectedNodes_make_from_buf(buf : bytes) -> ExpectedNodes:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ImageTransferStatus:
    """
    A Python class to represent struct objects of type 'ImageTransferStatus'
    
    Parameter structure for interface ImageTransferStatus
    """

    def __init__(self, e__CubeComputerCommon3_ImageTransferState__State : CubeComputerCommon3_ImageTransferState, uint32__ErrorCode : int, uint32__TransferSize : int, uint32__DataRemain : int, bool__InvalidNodeError : int, bool__TimeoutError : int, bool__CaptureError : int, bool__SetupError : int, bool__FileOpenReadError : int, bool__FileOpenWriteError : int, bool__FileReadError : int, bool__FileWriteError : int, bool__BusyError : int) -> None:
        """
        Struct 'ImageTransferStatus' constructor
        
        Attributes
        ---------
        e__CubeComputerCommon3_ImageTransferState__State [1] : CubeComputerCommon3_ImageTransferState
            State
        uint32__ErrorCode [1] : int
            Operation Error Code. Non-Zero = ERROR
        uint32__TransferSize [1] : int
            Size of the transfer
        uint32__DataRemain [1] : int
            Amount of data still to be transfered
        bool__InvalidNodeError [1] : int
            Set if the target node is invalid
        bool__TimeoutError [1] : int
            Set if transfer timeout reached
        bool__CaptureError [1] : int
            Set if the target node failed to capture image invalid
        bool__SetupError [1] : int
            Set if the target node failed to set up image transfer
        bool__FileOpenReadError [1] : int
            Set if error occured when opening storage file for reading
        bool__FileOpenWriteError [1] : int
            Set if error occured when opening storage file for writing
        bool__FileReadError [1] : int
            Set if error occured while reading from storage file
        bool__FileWriteError [1] : int
            Set if error occured while writing to storage file
        bool__BusyError [1] : int
            Set if there is already an ongoing transfer when attempting to store an image.
        """
        
        pass
        
    def get_State(self) -> CubeComputerCommon3_ImageTransferState:
        """
        A getter for the 'ImageTransferStatus::State' structure field
        
        State
        """
        
        pass
    
    def get_ErrorCode(self) -> int:
        """
        A getter for the 'ImageTransferStatus::ErrorCode' structure field
        
        Operation Error Code. Non-Zero = ERROR
        """
        
        pass
    
    def get_TransferSize(self) -> int:
        """
        A getter for the 'ImageTransferStatus::TransferSize' structure field
        
        Size of the transfer
        """
        
        pass
    
    def get_DataRemain(self) -> int:
        """
        A getter for the 'ImageTransferStatus::DataRemain' structure field
        
        Amount of data still to be transfered
        """
        
        pass
    
    def get_InvalidNodeError(self) -> int:
        """
        A getter for the 'ImageTransferStatus::InvalidNodeError' structure field
        
        Set if the target node is invalid
        """
        
        pass
    
    def get_TimeoutError(self) -> int:
        """
        A getter for the 'ImageTransferStatus::TimeoutError' structure field
        
        Set if transfer timeout reached
        """
        
        pass
    
    def get_CaptureError(self) -> int:
        """
        A getter for the 'ImageTransferStatus::CaptureError' structure field
        
        Set if the target node failed to capture image invalid
        """
        
        pass
    
    def get_SetupError(self) -> int:
        """
        A getter for the 'ImageTransferStatus::SetupError' structure field
        
        Set if the target node failed to set up image transfer
        """
        
        pass
    
    def get_FileOpenReadError(self) -> int:
        """
        A getter for the 'ImageTransferStatus::FileOpenReadError' structure field
        
        Set if error occured when opening storage file for reading
        """
        
        pass
    
    def get_FileOpenWriteError(self) -> int:
        """
        A getter for the 'ImageTransferStatus::FileOpenWriteError' structure field
        
        Set if error occured when opening storage file for writing
        """
        
        pass
    
    def get_FileReadError(self) -> int:
        """
        A getter for the 'ImageTransferStatus::FileReadError' structure field
        
        Set if error occured while reading from storage file
        """
        
        pass
    
    def get_FileWriteError(self) -> int:
        """
        A getter for the 'ImageTransferStatus::FileWriteError' structure field
        
        Set if error occured while writing to storage file
        """
        
        pass
    
    def get_BusyError(self) -> int:
        """
        A getter for the 'ImageTransferStatus::BusyError' structure field
        
        Set if there is already an ongoing transfer when attempting to store an image.
        """
        
        pass

def ImageTransferStatus_make_from_buf(buf : bytes) -> ImageTransferStatus:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class EventLogStatus:
    """
    A Python class to represent struct objects of type 'EventLogStatus'
    
    Parameter structure for interface EventLogStatus
    """

    def __init__(self, uint16__numberOfEntriesQueued : int, uint16__numberOfEntriesBuffered : int, uint32__numberOfEntries : int, uint32__numberOfEmptyEntries : int, uint32__oldestEntryUnix : int, uint32__latestEntryUnix : int, uint32__numberOfCriticalEvents : int, uint32__numberOfMajorWarningEvents : int, uint32__numberOfMinorWarningEvents : int, uint32__numberOfInfoEvents : int, uint32__writeCounter : int, e__CubeComputerCommon3_EventReadQueueState__readQueueState : CubeComputerCommon3_EventReadQueueState) -> None:
        """
        Struct 'EventLogStatus' constructor
        
        Attributes
        ---------
        uint16__numberOfEntriesQueued [1] : int
            The number of entries in the queue
        uint16__numberOfEntriesBuffered [1] : int
            The number of buffered (unwritten) entries
        uint32__numberOfEntries [1] : int
            The total number of entries contained in the event log (buffered + written)
        uint32__numberOfEmptyEntries [1] : int
            The total number of empty entries contained in the event log (storage space with no data)
        uint32__oldestEntryUnix [1] : int
            Timestamp of the oldest entry unix time in seconds
        uint32__latestEntryUnix [1] : int
            Timestamp of the latest entry unix time in seconds
        uint32__numberOfCriticalEvents [1] : int
            The total number of critical events contained in the event log
        uint32__numberOfMajorWarningEvents [1] : int
            The total number of major warning events contained in the event log
        uint32__numberOfMinorWarningEvents [1] : int
            The total number of minor warning events contained in the event log
        uint32__numberOfInfoEvents [1] : int
            The total number of info events contained in the event log
        uint32__writeCounter [1] : int
            The current event write counter
        e__CubeComputerCommon3_EventReadQueueState__readQueueState [1] : CubeComputerCommon3_EventReadQueueState
            The state of the read queue
        """
        
        pass
        
    def get_numberOfEntriesQueued(self) -> int:
        """
        A getter for the 'EventLogStatus::numberOfEntriesQueued' structure field
        
        The number of entries in the queue
        """
        
        pass
    
    def get_numberOfEntriesBuffered(self) -> int:
        """
        A getter for the 'EventLogStatus::numberOfEntriesBuffered' structure field
        
        The number of buffered (unwritten) entries
        """
        
        pass
    
    def get_numberOfEntries(self) -> int:
        """
        A getter for the 'EventLogStatus::numberOfEntries' structure field
        
        The total number of entries contained in the event log (buffered + written)
        """
        
        pass
    
    def get_numberOfEmptyEntries(self) -> int:
        """
        A getter for the 'EventLogStatus::numberOfEmptyEntries' structure field
        
        The total number of empty entries contained in the event log (storage space with no data)
        """
        
        pass
    
    def get_oldestEntryUnix(self) -> int:
        """
        A getter for the 'EventLogStatus::oldestEntryUnix' structure field
        
        Timestamp of the oldest entry unix time in seconds
        """
        
        pass
    
    def get_latestEntryUnix(self) -> int:
        """
        A getter for the 'EventLogStatus::latestEntryUnix' structure field
        
        Timestamp of the latest entry unix time in seconds
        """
        
        pass
    
    def get_numberOfCriticalEvents(self) -> int:
        """
        A getter for the 'EventLogStatus::numberOfCriticalEvents' structure field
        
        The total number of critical events contained in the event log
        """
        
        pass
    
    def get_numberOfMajorWarningEvents(self) -> int:
        """
        A getter for the 'EventLogStatus::numberOfMajorWarningEvents' structure field
        
        The total number of major warning events contained in the event log
        """
        
        pass
    
    def get_numberOfMinorWarningEvents(self) -> int:
        """
        A getter for the 'EventLogStatus::numberOfMinorWarningEvents' structure field
        
        The total number of minor warning events contained in the event log
        """
        
        pass
    
    def get_numberOfInfoEvents(self) -> int:
        """
        A getter for the 'EventLogStatus::numberOfInfoEvents' structure field
        
        The total number of info events contained in the event log
        """
        
        pass
    
    def get_writeCounter(self) -> int:
        """
        A getter for the 'EventLogStatus::writeCounter' structure field
        
        The current event write counter
        """
        
        pass
    
    def get_readQueueState(self) -> CubeComputerCommon3_EventReadQueueState:
        """
        A getter for the 'EventLogStatus::readQueueState' structure field
        
        The state of the read queue
        """
        
        pass

def EventLogStatus_make_from_buf(buf : bytes) -> EventLogStatus:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        

# ********************************************************************************************
#
# Request functions
#
# ********************************************************************************************
def req_setPassThrough(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : PassThrough) -> bytes:
    """
    Request serialization function for method 'setPassThrough'
    
    TCTLM Passthrough settings 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : PassThrough
        See definition of type
    """
    
    pass
    
def req_setPowerState(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : PowerState) -> bytes:
    """
    Request serialization function for method 'setPowerState'
    
    Power state 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : PowerState
        See definition of type
    """
    
    pass
    
def req_setImageTransferSetup(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ImageTransferSetup) -> bytes:
    """
    Request serialization function for method 'setImageTransferSetup'
    
    Set request image log transfer setup 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ImageTransferSetup
        See definition of type
    """
    
    pass
    
def req_setImageFileInfoReset(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'setImageFileInfoReset'
    
    Resets image file info index 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_setPortMap(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : PortMap) -> bytes:
    """
    Request serialization function for method 'setPortMap'
    
    This telemetry describes the nodes that have been discovered i.e. connected to CubeConnect 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : PortMap
        See definition of type
    """
    
    pass
    
def req_setEraseLogData(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : EraseLogData) -> bytes:
    """
    Request serialization function for method 'setEraseLogData'
    
    Format all logs 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : EraseLogData
        See definition of type
    """
    
    pass
    
def req_setEventLogFilterTransferSetup(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : EventLogFilterTransferSetup) -> bytes:
    """
    Request serialization function for method 'setEventLogFilterTransferSetup'
    
    Initiate event log transfer by specifying time range and data filter 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : EventLogFilterTransferSetup
        See definition of type
    """
    
    pass
    
def req_setTelemetryLogTransferSetup(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : TelemetryLogTransferSetup) -> bytes:
    """
    Request serialization function for method 'setTelemetryLogTransferSetup'
    
    Set request telemetry log transfer setup 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : TelemetryLogTransferSetup
        See definition of type
    """
    
    pass
    
def req_setDummyEvent(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : DummyEvent) -> bytes:
    """
    Request serialization function for method 'setDummyEvent'
    
    Set a dummy event to be stored in the event log 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : DummyEvent
        See definition of type
    """
    
    pass
    
def req_setUnsolicitedEventSetup(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : UnsolicitedEventSetup) -> bytes:
    """
    Request serialization function for method 'setUnsolicitedEventSetup'
    
    Setup unsolicited event messages 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : UnsolicitedEventSetup
        See definition of type
    """
    
    pass
    
def req_setUnsolicitedTlmSetup(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : UnsolicitedTlmSetup) -> bytes:
    """
    Request serialization function for method 'setUnsolicitedTlmSetup'
    
    Inclusion bitmask for unsolicited telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : UnsolicitedTlmSetup
        See definition of type
    """
    
    pass
    
def req_getPassThrough(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getPassThrough'
    
    TCTLM Passthrough settings 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getPowerState(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getPowerState'
    
    Power state 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getPortDiagnostics(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getPortDiagnostics'
    
    Diagnostics relating to the inernal CubeConnect interface port 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getPortMap(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getPortMap'
    
    This telemetry describes the nodes that have been discovered i.e. connected to CubeConnect 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getExpectedNodes(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getExpectedNodes'
    
    Lists the expected nodes config item 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getImageTransferStatus(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getImageTransferStatus'
    
    Image Transfer Status 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getImageFileInfo(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getImageFileInfo'
    
    Stored image file information 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getComponentErrorCodes(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getComponentErrorCodes'
    
    Error codes common to CubeComputer bootloader and control-program 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getEventLogStatus(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getEventLogStatus'
    
    Get the Event log status response 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTelemtryLogStatus(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTelemtryLogStatus'
    
    Get the Telemtry log status response 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getUnsolicitedEventSetup(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getUnsolicitedEventSetup'
    
    Setup unsolicited event messages 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getUnsolicitedTlmSetup(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getUnsolicitedTlmSetup'
    
    Inclusion bitmask for unsolicited telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTelemtryLogInclusionMasks(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTelemtryLogInclusionMasks'
    
    Get the Telemtry log inclusion masks 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    

# ********************************************************************************************
#
# Response classes
#
# ********************************************************************************************
class resp_setPassThrough:
    """
    A class representing a parsed FIDL response for method 'setPassThrough'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setPassThrough' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setPassThrough::adcsErrorCode'
        """
        pass

class resp_setPowerState:
    """
    A class representing a parsed FIDL response for method 'setPowerState'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setPowerState' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setPowerState::adcsErrorCode'
        """
        pass

class resp_setImageTransferSetup:
    """
    A class representing a parsed FIDL response for method 'setImageTransferSetup'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setImageTransferSetup' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setImageTransferSetup::adcsErrorCode'
        """
        pass

class resp_setImageFileInfoReset:
    """
    A class representing a parsed FIDL response for method 'setImageFileInfoReset'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setImageFileInfoReset' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setImageFileInfoReset::adcsErrorCode'
        """
        pass

class resp_setPortMap:
    """
    A class representing a parsed FIDL response for method 'setPortMap'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setPortMap' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setPortMap::adcsErrorCode'
        """
        pass

class resp_setEraseLogData:
    """
    A class representing a parsed FIDL response for method 'setEraseLogData'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setEraseLogData' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setEraseLogData::adcsErrorCode'
        """
        pass

class resp_setEventLogFilterTransferSetup:
    """
    A class representing a parsed FIDL response for method 'setEventLogFilterTransferSetup'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setEventLogFilterTransferSetup' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setEventLogFilterTransferSetup::adcsErrorCode'
        """
        pass

class resp_setTelemetryLogTransferSetup:
    """
    A class representing a parsed FIDL response for method 'setTelemetryLogTransferSetup'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setTelemetryLogTransferSetup' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setTelemetryLogTransferSetup::adcsErrorCode'
        """
        pass

class resp_setDummyEvent:
    """
    A class representing a parsed FIDL response for method 'setDummyEvent'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setDummyEvent' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setDummyEvent::adcsErrorCode'
        """
        pass

class resp_setUnsolicitedEventSetup:
    """
    A class representing a parsed FIDL response for method 'setUnsolicitedEventSetup'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setUnsolicitedEventSetup' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setUnsolicitedEventSetup::adcsErrorCode'
        """
        pass

class resp_setUnsolicitedTlmSetup:
    """
    A class representing a parsed FIDL response for method 'setUnsolicitedTlmSetup'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setUnsolicitedTlmSetup' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setUnsolicitedTlmSetup::adcsErrorCode'
        """
        pass

class resp_getPassThrough:
    """
    A class representing a parsed FIDL response for method 'getPassThrough'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getPassThrough' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getPassThrough::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> PassThrough:
        """
        A getter for the output argument 'getPassThrough::returnVal'
        """
        pass

class resp_getPowerState:
    """
    A class representing a parsed FIDL response for method 'getPowerState'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getPowerState' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getPowerState::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> PowerState:
        """
        A getter for the output argument 'getPowerState::returnVal'
        """
        pass

class resp_getPortDiagnostics:
    """
    A class representing a parsed FIDL response for method 'getPortDiagnostics'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getPortDiagnostics' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getPortDiagnostics::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> PortDiagnostics:
        """
        A getter for the output argument 'getPortDiagnostics::returnVal'
        """
        pass

class resp_getPortMap:
    """
    A class representing a parsed FIDL response for method 'getPortMap'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getPortMap' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getPortMap::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> PortMap:
        """
        A getter for the output argument 'getPortMap::returnVal'
        """
        pass

class resp_getExpectedNodes:
    """
    A class representing a parsed FIDL response for method 'getExpectedNodes'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getExpectedNodes' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getExpectedNodes::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ExpectedNodes:
        """
        A getter for the output argument 'getExpectedNodes::returnVal'
        """
        pass

class resp_getImageTransferStatus:
    """
    A class representing a parsed FIDL response for method 'getImageTransferStatus'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getImageTransferStatus' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getImageTransferStatus::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ImageTransferStatus:
        """
        A getter for the output argument 'getImageTransferStatus::returnVal'
        """
        pass

class resp_getImageFileInfo:
    """
    A class representing a parsed FIDL response for method 'getImageFileInfo'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getImageFileInfo' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getImageFileInfo::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ImageFileInfo:
        """
        A getter for the output argument 'getImageFileInfo::returnVal'
        """
        pass

class resp_getComponentErrorCodes:
    """
    A class representing a parsed FIDL response for method 'getComponentErrorCodes'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getComponentErrorCodes' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getComponentErrorCodes::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ComponentErrorCodes:
        """
        A getter for the output argument 'getComponentErrorCodes::returnVal'
        """
        pass

class resp_getEventLogStatus:
    """
    A class representing a parsed FIDL response for method 'getEventLogStatus'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getEventLogStatus' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getEventLogStatus::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> EventLogStatus:
        """
        A getter for the output argument 'getEventLogStatus::returnVal'
        """
        pass

class resp_getTelemtryLogStatus:
    """
    A class representing a parsed FIDL response for method 'getTelemtryLogStatus'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTelemtryLogStatus' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTelemtryLogStatus::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TelemtryLogStatus:
        """
        A getter for the output argument 'getTelemtryLogStatus::returnVal'
        """
        pass

class resp_getUnsolicitedEventSetup:
    """
    A class representing a parsed FIDL response for method 'getUnsolicitedEventSetup'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getUnsolicitedEventSetup' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getUnsolicitedEventSetup::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> UnsolicitedEventSetup:
        """
        A getter for the output argument 'getUnsolicitedEventSetup::returnVal'
        """
        pass

class resp_getUnsolicitedTlmSetup:
    """
    A class representing a parsed FIDL response for method 'getUnsolicitedTlmSetup'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getUnsolicitedTlmSetup' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getUnsolicitedTlmSetup::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> UnsolicitedTlmSetup:
        """
        A getter for the output argument 'getUnsolicitedTlmSetup::returnVal'
        """
        pass

class resp_getTelemtryLogInclusionMasks:
    """
    A class representing a parsed FIDL response for method 'getTelemtryLogInclusionMasks'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTelemtryLogInclusionMasks' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTelemtryLogInclusionMasks::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TelemtryLogInclusionMasks:
        """
        A getter for the output argument 'getTelemtryLogInclusionMasks::returnVal'
        """
        pass

