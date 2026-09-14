# ********************************************************************************************
# * @file upy_conops.py
# * @brief uPy dummy Python module generator
# ********************************************************************************************
# * @version           interface conops v2.0
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
class ThresholdValueTypes(IntEnum):
    """
    Enumeration class definition for type 'ThresholdValueTypes'
    """
    # Default threshold multiplier
    THRESHOLDVALUETYPES_DEFAULT = 0
    # Limit for the battery bus voltage [V] to enter SAFE mode from IDLE or MISSION
    THRESHOLDVALUETYPES_VBATT_SAFE = 0
    # Lower limit for the battery temperature [˚C] to enter SAFE mode
    THRESHOLDVALUETYPES_TBATT_SAFE_LOWER = 0
    # Upper limit for the battery temperature [˚C] to enter SAFE mode
    THRESHOLDVALUETYPES_TBATT_SAFE_UPPER = 0
    # See ThresholdValues::ang_vel_max
    THRESHOLDVALUETYPES_ANGVEL_MAX = 0
    # See ThresholdValues::ang_vel_low
    THRESHOLDVALUETYPES_ANGVEL_MIN = 0
    # See ThresholdValues::ang_vel_range
    THRESHOLDVALUETYPES_ANGVEL_Y_THOMSON_HIGH = 0
    # See ThresholdValues::ang_vel_range
    THRESHOLDVALUETYPES_ANGVEL_Y_THOMSON_LOW = 0
class OpModes(IntEnum):
    """
    Enumeration class definition for type 'OpModes'
    """
    # Default mode of the OBC, which supports minimal communication capabilities
    OPMODES_MODE_SAFE = 0
    # Transient initial sub-mode of the Safe mode
    OPMODES_MODE_SAFE_ENTRY = 0
    # Sub-mode of the Safe mode in which ADCS control is possible
    OPMODES_MODE_SAFE_CONTROL = 0
    # Sub-mode of the Safe mode in which ADCS control is not possible
    OPMODES_MODE_SAFE_NO_CONTROL = 0
    # Mode in which the OBC is waiting for payload activation
    OPMODES_MODE_IDLE = 0
    # Mode in which payloads are executing commands
    OPMODES_MODE_MISSION = 0
class AocsState(IntEnum):
    """
    Enumeration class definition for type 'AocsState'
    """
    AOCSSTATE_AOCS_STATE_UNDEFINED = 0
    AOCSSTATE_AOCS_STATE_EXISTING_CONTROL = 0
    AOCSSTATE_AOCS_STATE_NO_CONTROL = 0
    AOCSSTATE_AOCS_STATE_NORMAL_DETUMBLING = 0
    AOCSSTATE_AOCS_STATE_Y_THOMSON = 0
    AOCSSTATE_AOCS_STATE_Y_THOMSON_MEMS_RATE = 0
    AOCSSTATE_AOCS_STATE_FAST_DETUMBLING = 0
    AOCSSTATE_AOCS_STATE_VERY_FAST_DETUMBLING = 0
    AOCSSTATE_AOCS_STATE_Y_MOMENTUM = 0
    AOCSSTATE_AOCS_STATE_Y_MOMENTUM_FULL_STATE_EKF = 0
    AOCSSTATE_AOCS_STATE_3AXIS = 0
    AOCSSTATE_AOCS_STATE_SUN_TRACKING = 0
    AOCSSTATE_AOCS_STATE_TARGET_TRACKING = 0
    AOCSSTATE_AOCS_STATE_USER1 = 0
    AOCSSTATE_AOCS_STATE_USER2 = 0
    AOCSSTATE_AOCS_STATE_USER3 = 0
class Events(IntEnum):
    """
    Enumeration class definition for type 'Events'
    """
    # Reset the ConOps state machine to its initial state
    EVENTS_RESET = 0
    # Standard periodic event
    EVENTS_PERIODIC = 0
    # Enter Idle event
    EVENTS_ENTER_IDLE = 0
    # Enter Safe event
    EVENTS_ENTER_SAFE = 0
    # Enter Mission event
    EVENTS_ENTER_MISSION = 0
class StandardResult(IntEnum):
    """
    Enumeration class definition for type 'StandardResult'
    """
    # The operation finished successfully
    STANDARDRESULT_SUCCESS = 0
    # The operation failed
    STANDARDRESULT_ERROR = 0
    # One or more input arguments of the method are invalid
    STANDARDRESULT_INVALID_ARGS = 0
    # The operation is not supported by the firmware implementation
    STANDARDRESULT_NOT_SUPPORTED = 0
class SafeBool(IntEnum):
    """
    Enumeration class definition for type 'SafeBool'
    """
    SAFEBOOL_FALSE = 0
    SAFEBOOL_TRUE = 0
class ModesWithDefCtrl(IntEnum):
    """
    Enumeration class definition for type 'ModesWithDefCtrl'
    """
    MODESWITHDEFCTRL_SAFE = 0
    MODESWITHDEFCTRL_IDLE = 0


# ********************************************************************************************
#
# Struct classes
#
# ********************************************************************************************
class ThresholdValues:
    """
    A Python class to represent struct objects of type 'ThresholdValues'
    
    Contains the threshold settings for the ConOps
    """

    def __init__(self, int32__v_batt_safe : int, int32__t_batt_safe_lower : int, int32__t_batt_safe_upper : int, int32__ang_vel_max : int, int32__ang_vel_low : int, int32__ang_vel_y_thom_high : int, int32__ang_vel_y_thom_low : int) -> None:
        """
        Struct 'ThresholdValues' constructor
        
        Attributes
        ---------
        int32__v_batt_safe [1] : int
            Battery voltage in [mV] below which the ConOps shall enter Safe mode
        int32__t_batt_safe_lower [1] : int
            Temperature in degrees Celsius below which the ConOps shall enter Safe mode
        int32__t_batt_safe_upper [1] : int
            Temperature in degrees Celsius above which the ConOps shall enter Safe mode
        int32__ang_vel_max [1] : int
            Angular velocity in [mrad/s] above which the OBC can start detumbling, ex. 1200 == 1.2 rad/s
        int32__ang_vel_low [1] : int
            Angular velocity in [mrad/s] after which the OBC can stop detumbling, ex. 1200 == 1.2 rad/s
        int32__ang_vel_y_thom_high [1] : int
            Upper threshold for angular velocity in [mrad/s] to determine stable Y-Thomson spin, ex. 1200 == 1.2 rad/s
        int32__ang_vel_y_thom_low [1] : int
            Lower threshold for angular velocity in [mrad/s] to determine stable Y-Thomson spin, ex. 1200 == 1.2 rad/s
        """
        
        pass
        
    def get_v_batt_safe(self) -> int:
        """
        A getter for the 'ThresholdValues::v_batt_safe' structure field
        
        Battery voltage in [mV] below which the ConOps shall enter Safe mode
        """
        
        pass
    
    def get_t_batt_safe_lower(self) -> int:
        """
        A getter for the 'ThresholdValues::t_batt_safe_lower' structure field
        
        Temperature in degrees Celsius below which the ConOps shall enter Safe mode
        """
        
        pass
    
    def get_t_batt_safe_upper(self) -> int:
        """
        A getter for the 'ThresholdValues::t_batt_safe_upper' structure field
        
        Temperature in degrees Celsius above which the ConOps shall enter Safe mode
        """
        
        pass
    
    def get_ang_vel_max(self) -> int:
        """
        A getter for the 'ThresholdValues::ang_vel_max' structure field
        
        Angular velocity in [mrad/s] above which the OBC can start detumbling, ex. 1200 == 1.2 rad/s
        """
        
        pass
    
    def get_ang_vel_low(self) -> int:
        """
        A getter for the 'ThresholdValues::ang_vel_low' structure field
        
        Angular velocity in [mrad/s] after which the OBC can stop detumbling, ex. 1200 == 1.2 rad/s
        """
        
        pass
    
    def get_ang_vel_y_thom_high(self) -> int:
        """
        A getter for the 'ThresholdValues::ang_vel_y_thom_high' structure field
        
        Upper threshold for angular velocity in [mrad/s] to determine stable Y-Thomson spin, ex. 1200 == 1.2 rad/s
        """
        
        pass
    
    def get_ang_vel_y_thom_low(self) -> int:
        """
        A getter for the 'ThresholdValues::ang_vel_y_thom_low' structure field
        
        Lower threshold for angular velocity in [mrad/s] to determine stable Y-Thomson spin, ex. 1200 == 1.2 rad/s
        """
        
        pass

def ThresholdValues_make_from_buf(buf : bytes) -> ThresholdValues:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class AocsRefParams:
    """
    A Python class to represent struct objects of type 'AocsRefParams'
    
    Parameters of control modes of the AOCS service
    """

    def __init__(self, float__refParam1 : float, float__refParam2 : float, float__refParam3 : float) -> None:
        """
        Struct 'AocsRefParams' constructor
        
        Attributes
        ---------
        float__refParam1 [1] : float
        float__refParam2 [1] : float
        float__refParam3 [1] : float
        """
        
        pass
        
    def get_refParam1(self) -> float:
        """
        A getter for the 'AocsRefParams::refParam1' structure field
        
        """
        
        pass
    
    def get_refParam2(self) -> float:
        """
        A getter for the 'AocsRefParams::refParam2' structure field
        
        """
        
        pass
    
    def get_refParam3(self) -> float:
        """
        A getter for the 'AocsRefParams::refParam3' structure field
        
        """
        
        pass

def AocsRefParams_make_from_buf(buf : bytes) -> AocsRefParams:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ControlMode:
    """
    A Python class to represent struct objects of type 'ControlMode'
    
    Data used for default mode configuration
    """

    def __init__(self, e__AocsState__mode : AocsState, s__params : AocsRefParams) -> None:
        """
        Struct 'ControlMode' constructor
        
        Attributes
        ---------
        e__AocsState__mode [1] : AocsState
        s__params [1] : AocsRefParams
        """
        
        pass
        
    def get_mode(self) -> AocsState:
        """
        A getter for the 'ControlMode::mode' structure field
        
        """
        
        pass
    
    def get_params(self) -> AocsRefParams:
        """
        A getter for the 'ControlMode::params' structure field
        
        """
        
        pass

def ControlMode_make_from_buf(buf : bytes) -> ControlMode:
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
def req_send_new_event(e__Events__event_type : Events) -> bytes:
    """
    Request serialization function for method 'send_new_event'
    
    Send a new event to the ConOps State Machine 
    
    Arguments
    ---------
    e__Events__event_type [1] : Events
        The event to send
    """
    
    pass
    
def req_get_op_mode() -> bytes:
    """
    Request serialization function for method 'get_op_mode'
    
    Get the current operational mode number from the ConOps State Machine 
    
    """
    
    pass
    
def req_set_thresh_val(int32__thresh_value : int, e__ThresholdValueTypes__thresh_type : ThresholdValueTypes) -> bytes:
    """
    Request serialization function for method 'set_thresh_val'
    
    Set a new value for a threshold type 
    
    Arguments
    ---------
    int32__thresh_value [1] : int
        Value of the threshold to set
    e__ThresholdValueTypes__thresh_type [1] : ThresholdValueTypes
        Type of threshold to set
    """
    
    pass
    
def req_get_thresh_val(e__ThresholdValueTypes__thresh_type : ThresholdValueTypes) -> bytes:
    """
    Request serialization function for method 'get_thresh_val'
    
    Get the current value for a threshold type 
    
    Arguments
    ---------
    e__ThresholdValueTypes__thresh_type [1] : ThresholdValueTypes
        Type of threshold to get
    """
    
    pass
    
def req_set_all_thresh_val(s__thresh_vals : ThresholdValues) -> bytes:
    """
    Request serialization function for method 'set_all_thresh_val'
    
    Update all threshold values 
    
    Arguments
    ---------
    s__thresh_vals [1] : ThresholdValues
        Specifies threshold settings to update
    """
    
    pass
    
def req_get_all_thresh_val() -> bytes:
    """
    Request serialization function for method 'get_all_thresh_val'
    
    Get all threshold values 
    
    """
    
    pass
    
def req_request_mission_mode_enter(uint32__timeout : int) -> bytes:
    """
    Request serialization function for method 'request_mission_mode_enter'
    
    Request entry into mission mode of the satellite 
    
    Arguments
    ---------
    uint32__timeout [1] : int
        Maximum time in [ms] to spend in mission mode. On expiry, ConOps transitions to Idle mode.
                                      Note that the current implementation checks for elapsed time at the period of the main ConOps
                                      task (default is 1s). Therefore, timeout values with finer resolution than this period will be
                                      "rounded up" to the period.
    """
    
    pass
    
def req_request_mission_mode_exit() -> bytes:
    """
    Request serialization function for method 'request_mission_mode_exit'
    
    Request exit from mission mode of the satellite 
    
    """
    
    pass
    
def req_get_default_control_mode(e__ModesWithDefCtrl__conops_mode : ModesWithDefCtrl) -> bytes:
    """
    Request serialization function for method 'get_default_control_mode'
    
    Retrieve default AOCS control mode for a given ConOps mode 
    
    Arguments
    ---------
    e__ModesWithDefCtrl__conops_mode [1] : ModesWithDefCtrl
        ConOps mode for which the default control mode is requested
    """
    
    pass
    
def req_set_default_control_mode(e__ModesWithDefCtrl__conops_mode : ModesWithDefCtrl, s__control_mode : ControlMode) -> bytes:
    """
    Request serialization function for method 'set_default_control_mode'
    
    Retrieve default AOCS control mode for a given ConOps mode 
    
    Arguments
    ---------
    e__ModesWithDefCtrl__conops_mode [1] : ModesWithDefCtrl
        ConOps mode for which the default control mode is set
    s__control_mode [1] : ControlMode
        Default control mode to be set
    """
    
    pass
    
def req_set_force_allow_payloads(e__SafeBool__is_allowed : SafeBool) -> bytes:
    """
    Request serialization function for method 'set_force_allow_payloads'
    
    Set a flag to allow running payloads in any ConOps mode 
    
    Arguments
    ---------
    e__SafeBool__is_allowed [1] : SafeBool
        New value to set
    """
    
    pass
    
def req_get_force_allow_payloads() -> bytes:
    """
    Request serialization function for method 'get_force_allow_payloads'
    
    Retrieve the flag that allows running payloads in any ConOps mode 
    
    """
    
    pass
    

# ********************************************************************************************
#
# Response classes
#
# ********************************************************************************************
class resp_send_new_event:
    """
    A class representing a parsed FIDL response for method 'send_new_event'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'send_new_event' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'send_new_event::op_result'
        """
        pass

class resp_get_op_mode:
    """
    A class representing a parsed FIDL response for method 'get_op_mode'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'get_op_mode' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'get_op_mode::op_result'
        """
        pass
    
    def get_op_mode(self) -> OpModes:
        """
        A getter for the output argument 'get_op_mode::op_mode'
        """
        pass

class resp_set_thresh_val:
    """
    A class representing a parsed FIDL response for method 'set_thresh_val'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'set_thresh_val' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'set_thresh_val::op_result'
        """
        pass

class resp_get_thresh_val:
    """
    A class representing a parsed FIDL response for method 'get_thresh_val'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'get_thresh_val' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'get_thresh_val::op_result'
        """
        pass
    
    def get_thresh_value(self) -> int:
        """
        A getter for the output argument 'get_thresh_val::thresh_value'
        """
        pass

class resp_set_all_thresh_val:
    """
    A class representing a parsed FIDL response for method 'set_all_thresh_val'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'set_all_thresh_val' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'set_all_thresh_val::op_result'
        """
        pass

class resp_get_all_thresh_val:
    """
    A class representing a parsed FIDL response for method 'get_all_thresh_val'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'get_all_thresh_val' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'get_all_thresh_val::op_result'
        """
        pass
    
    def get_thresh_vals(self) -> ThresholdValues:
        """
        A getter for the output argument 'get_all_thresh_val::thresh_vals'
        """
        pass

class resp_request_mission_mode_enter:
    """
    A class representing a parsed FIDL response for method 'request_mission_mode_enter'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'request_mission_mode_enter' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'request_mission_mode_enter::op_result'
        """
        pass

class resp_request_mission_mode_exit:
    """
    A class representing a parsed FIDL response for method 'request_mission_mode_exit'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'request_mission_mode_exit' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'request_mission_mode_exit::op_result'
        """
        pass

class resp_get_default_control_mode:
    """
    A class representing a parsed FIDL response for method 'get_default_control_mode'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'get_default_control_mode' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'get_default_control_mode::op_result'
        """
        pass
    
    def get_control_mode(self) -> ControlMode:
        """
        A getter for the output argument 'get_default_control_mode::control_mode'
        """
        pass

class resp_set_default_control_mode:
    """
    A class representing a parsed FIDL response for method 'set_default_control_mode'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'set_default_control_mode' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'set_default_control_mode::op_result'
        """
        pass
    
    def get_set_control_mode(self) -> ControlMode:
        """
        A getter for the output argument 'set_default_control_mode::set_control_mode'
        """
        pass

class resp_set_force_allow_payloads:
    """
    A class representing a parsed FIDL response for method 'set_force_allow_payloads'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'set_force_allow_payloads' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'set_force_allow_payloads::op_result'
        """
        pass

class resp_get_force_allow_payloads:
    """
    A class representing a parsed FIDL response for method 'get_force_allow_payloads'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'get_force_allow_payloads' method (includes the received FP header)
        """
        pass

    def get_set_is_allowed(self) -> SafeBool:
        """
        A getter for the output argument 'get_force_allow_payloads::set_is_allowed'
        """
        pass

