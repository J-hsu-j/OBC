# ********************************************************************************************
# * @file upy_payload_ctrl.py
# * @brief uPy dummy Python module generator
# ********************************************************************************************
# * @version           interface payload_ctrl v2.0
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
class PayloadOpResult(IntEnum):
    """
    Enumeration class definition for type 'PayloadOpResult'
    """
    PAYLOADOPRESULT_NOT_INIT = 0
    PAYLOADOPRESULT_INVALID_PL_ID = 0
    PAYLOADOPRESULT_REFUSE_CMD = 0
    PAYLOADOPRESULT_FAILED = 0
    PAYLOADOPRESULT_OK = 0
class StopMode(IntEnum):
    """
    Enumeration class definition for type 'StopMode'
    """
    STOPMODE_NORMAL = 0
    STOPMODE_EMERGENCY = 0
class PayloadState(IntEnum):
    """
    Enumeration class definition for type 'PayloadState'
    """
    PAYLOADSTATE_NOT_INIT = 0
    PAYLOADSTATE_STOPPED = 0
    PAYLOADSTATE_STARTED = 0
    PAYLOADSTATE_STARTING = 0
    PAYLOADSTATE_STOPPING = 0
    PAYLOADSTATE_ERROR = 0


# ********************************************************************************************
#
# Struct classes
#
# ********************************************************************************************
class PayloadStartCfg:
    """
    A Python class to represent struct objects of type 'PayloadStartCfg'
    
    Configuration arguments for starting a payload
    """

    def __init__(self, uint8__flags : int, a__uint8__47__pl_args : list[int]) -> None:
        """
        Struct 'PayloadStartCfg' constructor
        
        Attributes
        ---------
        uint8__flags [1] : int
            A set of setup flags with payload-specific purpose
        a__uint8__47__pl_args [47] : list[int]
            Payload-specific arguments
        """
        
        pass
        
    def get_flags(self) -> int:
        """
        A getter for the 'PayloadStartCfg::flags' structure field
        
        A set of setup flags with payload-specific purpose
        """
        
        pass
    
    def get_pl_args(self) -> list[int]:
        """
        A getter for the 'PayloadStartCfg::pl_args' structure field
        
        Payload-specific arguments
        """
        
        pass

def PayloadStartCfg_make_from_buf(buf : bytes) -> PayloadStartCfg:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class PayloadInfo:
    """
    A Python class to represent struct objects of type 'PayloadInfo'
    
    Status information about a payload
    """

    def __init__(self, e__PayloadState__pl_state : PayloadState, uint32__last_error_code : int) -> None:
        """
        Struct 'PayloadInfo' constructor
        
        Attributes
        ---------
        e__PayloadState__pl_state [1] : PayloadState
            State of the payload
        uint32__last_error_code [1] : int
            Last regisered error of the payload
        """
        
        pass
        
    def get_pl_state(self) -> PayloadState:
        """
        A getter for the 'PayloadInfo::pl_state' structure field
        
        State of the payload
        """
        
        pass
    
    def get_last_error_code(self) -> int:
        """
        A getter for the 'PayloadInfo::last_error_code' structure field
        
        Last regisered error of the payload
        """
        
        pass

def PayloadInfo_make_from_buf(buf : bytes) -> PayloadInfo:
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
def req_start_payload(uint8__payload_id : int, s__start_cfg : PayloadStartCfg) -> bytes:
    """
    Request serialization function for method 'start_payload'
    
    Start payload 
    
    Arguments
    ---------
    uint8__payload_id [1] : int
        ID of the payload
    s__start_cfg [1] : PayloadStartCfg
        Configuration arguments of the start operation
    """
    
    pass
    
def req_stop_payload(uint8__payload_id : int, e__StopMode__req_stop_mode : StopMode) -> bytes:
    """
    Request serialization function for method 'stop_payload'
    
    Stop payload 
    
    Arguments
    ---------
    uint8__payload_id [1] : int
        ID of the payload
    e__StopMode__req_stop_mode [1] : StopMode
        Urgency of the stop operation
    """
    
    pass
    
def req_get_payload_info(uint8__payload_id : int) -> bytes:
    """
    Request serialization function for method 'get_payload_info'
    
    Get payload information 
    
    Arguments
    ---------
    uint8__payload_id [1] : int
        ID of the payload
    """
    
    pass
    

# ********************************************************************************************
#
# Response classes
#
# ********************************************************************************************
class resp_start_payload:
    """
    A class representing a parsed FIDL response for method 'start_payload'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'start_payload' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> PayloadOpResult:
        """
        A getter for the output argument 'start_payload::op_result'
        """
        pass

class resp_stop_payload:
    """
    A class representing a parsed FIDL response for method 'stop_payload'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'stop_payload' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> PayloadOpResult:
        """
        A getter for the output argument 'stop_payload::op_result'
        """
        pass

class resp_get_payload_info:
    """
    A class representing a parsed FIDL response for method 'get_payload_info'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'get_payload_info' method (includes the received FP header)
        """
        pass

    def get_info(self) -> PayloadInfo:
        """
        A getter for the output argument 'get_payload_info::info'
        """
        pass

