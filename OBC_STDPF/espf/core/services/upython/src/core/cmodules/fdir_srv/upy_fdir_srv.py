# ********************************************************************************************
# * @file upy_fdir_srv.py
# * @brief uPy dummy Python module generator
# ********************************************************************************************
# * @version           interface fdir_srv v0.2
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
class return_status(IntEnum):
    """
    Enumeration class definition for type 'return_status'
    """
    # No fault detected
    RETURN_STATUS_SUCCESS = 0
    # Invalid fault id input
    RETURN_STATUS_ERROR_INVALID_FAULT_ID = 0
    # Invalid agent id input
    RETURN_STATUS_ERROR_INVALID_AGENT_ID = 0
    # Invalid fdir level input
    RETURN_STATUS_ERROR_INVALID_FDIR_LEVEL = 0
    # Attempting to raise a fault whose detection is not enabled
    RETURN_STATUS_ERROR_FAULT_DETECTION_DISABLED = 0
    # Attempting to (non-force) clear a fault whose level is above autoclear
    RETURN_STATUS_ERROR_FAULT_LEVEL_ABOVE_AUTOCLEAR = 0
    # Internal device error
    RETURN_STATUS_ERROR_INTERNAL = 0


# ********************************************************************************************
#
# Struct classes
#
# ********************************************************************************************

# ********************************************************************************************
#
# Request functions
#
# ********************************************************************************************
def req_get_system_fdir_level() -> bytes:
    """
    Request serialization function for method 'get_system_fdir_level'
    
    Retrieves the overall FDIR level of the system 
    
    """
    
    pass
    
def req_get_agent_fdir_level(uint16__agent_id : int) -> bytes:
    """
    Request serialization function for method 'get_agent_fdir_level'
    
    Retrieves the FDIR level of a given agent 
    
    Arguments
    ---------
    uint16__agent_id [1] : int
        Identifier of the checked agent
    """
    
    pass
    
def req_get_detection_for_fault(uint16__fault_id : int) -> bytes:
    """
    Request serialization function for method 'get_detection_for_fault'
    
    Retrieves whether detection is enabled for a given fault 
    
    Arguments
    ---------
    uint16__fault_id [1] : int
        Identifier of the checked fault
    """
    
    pass
    
def req_set_detection_for_fault(uint16__fault_id : int, bool__set_detection_enabled : int) -> bytes:
    """
    Request serialization function for method 'set_detection_for_fault'
    
    Sets whether detection is enabled for a given fault 
    
    Arguments
    ---------
    uint16__fault_id [1] : int
        Identifier of the fault the detection of which is being set
    bool__set_detection_enabled [1] : int
        True to enable detection, False to disable
    """
    
    pass
    
def req_set_detection_for_all_faults(bool__set_detection_enabled : int) -> bytes:
    """
    Request serialization function for method 'set_detection_for_all_faults'
    
    Sets whether detection is enabled for all faults.
                Fault detection is being set from lowest to highest id.
                The first fault that returns an error will stop the clearing process and its id will be returned.
                If result is SUCCESS, then all faults were modified and fault_id will be the last id modified. 
    
    Arguments
    ---------
    bool__set_detection_enabled [1] : int
        True to enable detection, False to disable
    """
    
    pass
    
def req_get_min_active_fdir() -> bytes:
    """
    Request serialization function for method 'get_min_active_fdir'
    
    Gets a threshold below which the system FDIR level cannot drop. 
    
    """
    
    pass
    
def req_set_min_active_fdir(uint8__fdir_level : int) -> bytes:
    """
    Request serialization function for method 'set_min_active_fdir'
    
    Sets a threshold below which the system FDIR level cannot drop. Used to test
                          users of FDIR level without having to trigger the agents' fault detection logic 
    
    Arguments
    ---------
    uint8__fdir_level [1] : int
        New value for the system FDIR level threshold
    """
    
    pass
    
def req_get_fault_user_clear_level() -> bytes:
    """
    Request serialization function for method 'get_fault_user_clear_level'
    
    Get the FDIR level at which the fault will no longer be cleared automatically by the system and only by the operator. 
    
    """
    
    pass
    
def req_set_fault_user_clear_level(uint8__fdir_level : int) -> bytes:
    """
    Request serialization function for method 'set_fault_user_clear_level'
    
    Set the FDIR level at which the fault will no longer be cleared automatically by the system and only by the operator.
                It is used usually changed for testing purposes. 
    
    Arguments
    ---------
    uint8__fdir_level [1] : int
        The level or higher at which automatic clearing of faults by the system is not possible.
                        Faults at this level or higher can only be cleared through a an operator command.
                        Possible values are 0-4, where at 0 no fault is cleared automatically, and at 4 every fault may be cleared automatically.
                        By automatic clearing is meants that if the conditions of the fault are normal, the fault will no longer be active.
    """
    
    pass
    
def req_get_fault(uint16__fault_id : int) -> bytes:
    """
    Request serialization function for method 'get_fault'
    
    Gets the status of a given fault 
    
    Arguments
    ---------
    uint16__fault_id [1] : int
        Identifier of the fault the detection of which is being set
    """
    
    pass
    
def req_set_fault(uint16__fault_id : int, uint16__agent_id : int, bool__active : int) -> bytes:
    """
    Request serialization function for method 'set_fault'
    
    Set a fault to active(raised) or inactive(cleared). This method is for testing purposes only.
            Raising a fault, that is already active and clearing a fault that is already inactive, is idempotent, i.e. it will not cause any changes in the system.
            Also raising a fault whose detection is disabled will be ignored. A fault will be cleared even if the detection is disabled.
            A fault will NOT be cleared if the fault level is equal to the autoclear level.
            Otherwise setting a fault will initiate the fault isolation and recovery (I&R) actions if such are implemented for given fault.
            This function does not bypass the fault detection logic and may be quickly set to a new state, depending on conditions and FDIR level of the fault.
            If an operator wishes to have a fault in a certain state irrespective of the detection logic, he should use the DataCache data layer for the particular fault. 
    
    Arguments
    ---------
    uint16__fault_id [1] : int
        Identifier of the fault the detection of which is being set
    uint16__agent_id [1] : int
        Identifier of the agent
    bool__active [1] : int
        True if fault is active, False otherwise
    """
    
    pass
    
def req_force_clear_fault(uint16__fault_id : int) -> bytes:
    """
    Request serialization function for method 'force_clear_fault'
    
    This function does not bypass the fault detection logic and may be quickly set to active, depending on conditions and FDIR level of the fault.
            This method is to be used by an operator to clear a fault that does not automatically recover,
            but the conditions must be met, otherwise the fault will be reactivated, with the I&R actions being executed again.
            If the fault is already inactive, i.e. clear, then nothing will happen.
            This function bypasses the autoclear level set by set_fault_autoclear_level and will clear any fault selected.
            It also bypasses the detection logic and will clear any fault selected even if fault detection is disabled.
            If an operator wishes suppress a fault, he may disable detection and then use this method to clear the fault. 
    
    Arguments
    ---------
    uint16__fault_id [1] : int
        Identifier of the fault the detection of which is being set
    """
    
    pass
    
def req_force_clear_all_faults() -> bytes:
    """
    Request serialization function for method 'force_clear_all_faults'
    
    Same as force_clear_fault, but clears all faults.
                Faults are cleared from lowest to highest id.
                The first fault that returns an error will stop the clearing process and its id will be returned.
                If result is SUCCESS, then all faults were cleared and fault_id will be the last id cleared. 
    
    """
    
    pass
    

# ********************************************************************************************
#
# Response classes
#
# ********************************************************************************************
class resp_get_system_fdir_level:
    """
    A class representing a parsed FIDL response for method 'get_system_fdir_level'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'get_system_fdir_level' method (includes the received FP header)
        """
        pass

    def get_status(self) -> return_status:
        """
        A getter for the output argument 'get_system_fdir_level::status'
        """
        pass
    
    def get_fdir_level(self) -> int:
        """
        A getter for the output argument 'get_system_fdir_level::fdir_level'
        """
        pass

class resp_get_agent_fdir_level:
    """
    A class representing a parsed FIDL response for method 'get_agent_fdir_level'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'get_agent_fdir_level' method (includes the received FP header)
        """
        pass

    def get_status(self) -> return_status:
        """
        A getter for the output argument 'get_agent_fdir_level::status'
        """
        pass
    
    def get_fdir_level(self) -> int:
        """
        A getter for the output argument 'get_agent_fdir_level::fdir_level'
        """
        pass

class resp_get_detection_for_fault:
    """
    A class representing a parsed FIDL response for method 'get_detection_for_fault'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'get_detection_for_fault' method (includes the received FP header)
        """
        pass

    def get_status(self) -> return_status:
        """
        A getter for the output argument 'get_detection_for_fault::status'
        """
        pass
    
    def get_detection_enabled(self) -> int:
        """
        A getter for the output argument 'get_detection_for_fault::detection_enabled'
        """
        pass

class resp_set_detection_for_fault:
    """
    A class representing a parsed FIDL response for method 'set_detection_for_fault'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'set_detection_for_fault' method (includes the received FP header)
        """
        pass

    def get_status(self) -> return_status:
        """
        A getter for the output argument 'set_detection_for_fault::status'
        """
        pass
    
    def get_detection_enabled(self) -> int:
        """
        A getter for the output argument 'set_detection_for_fault::detection_enabled'
        """
        pass

class resp_set_detection_for_all_faults:
    """
    A class representing a parsed FIDL response for method 'set_detection_for_all_faults'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'set_detection_for_all_faults' method (includes the received FP header)
        """
        pass

    def get_status(self) -> return_status:
        """
        A getter for the output argument 'set_detection_for_all_faults::status'
        """
        pass
    
    def get_fault_id(self) -> int:
        """
        A getter for the output argument 'set_detection_for_all_faults::fault_id'
        """
        pass

class resp_get_min_active_fdir:
    """
    A class representing a parsed FIDL response for method 'get_min_active_fdir'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'get_min_active_fdir' method (includes the received FP header)
        """
        pass

    def get_status(self) -> return_status:
        """
        A getter for the output argument 'get_min_active_fdir::status'
        """
        pass
    
    def get_fdir_level_set(self) -> int:
        """
        A getter for the output argument 'get_min_active_fdir::fdir_level_set'
        """
        pass

class resp_set_min_active_fdir:
    """
    A class representing a parsed FIDL response for method 'set_min_active_fdir'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'set_min_active_fdir' method (includes the received FP header)
        """
        pass

    def get_status(self) -> return_status:
        """
        A getter for the output argument 'set_min_active_fdir::status'
        """
        pass
    
    def get_fdir_level_set(self) -> int:
        """
        A getter for the output argument 'set_min_active_fdir::fdir_level_set'
        """
        pass

class resp_get_fault_user_clear_level:
    """
    A class representing a parsed FIDL response for method 'get_fault_user_clear_level'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'get_fault_user_clear_level' method (includes the received FP header)
        """
        pass

    def get_status(self) -> return_status:
        """
        A getter for the output argument 'get_fault_user_clear_level::status'
        """
        pass
    
    def get_fdir_level(self) -> int:
        """
        A getter for the output argument 'get_fault_user_clear_level::fdir_level'
        """
        pass

class resp_set_fault_user_clear_level:
    """
    A class representing a parsed FIDL response for method 'set_fault_user_clear_level'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'set_fault_user_clear_level' method (includes the received FP header)
        """
        pass

    def get_status(self) -> return_status:
        """
        A getter for the output argument 'set_fault_user_clear_level::status'
        """
        pass
    
    def get_fdir_level_set(self) -> int:
        """
        A getter for the output argument 'set_fault_user_clear_level::fdir_level_set'
        """
        pass

class resp_get_fault:
    """
    A class representing a parsed FIDL response for method 'get_fault'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'get_fault' method (includes the received FP header)
        """
        pass

    def get_status(self) -> return_status:
        """
        A getter for the output argument 'get_fault::status'
        """
        pass
    
    def get_is_active(self) -> int:
        """
        A getter for the output argument 'get_fault::is_active'
        """
        pass
    
    def get_fdir_level(self) -> int:
        """
        A getter for the output argument 'get_fault::fdir_level'
        """
        pass

class resp_set_fault:
    """
    A class representing a parsed FIDL response for method 'set_fault'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'set_fault' method (includes the received FP header)
        """
        pass

    def get_status(self) -> return_status:
        """
        A getter for the output argument 'set_fault::status'
        """
        pass

class resp_force_clear_fault:
    """
    A class representing a parsed FIDL response for method 'force_clear_fault'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'force_clear_fault' method (includes the received FP header)
        """
        pass

    def get_status(self) -> return_status:
        """
        A getter for the output argument 'force_clear_fault::status'
        """
        pass

class resp_force_clear_all_faults:
    """
    A class representing a parsed FIDL response for method 'force_clear_all_faults'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'force_clear_all_faults' method (includes the received FP header)
        """
        pass

    def get_status(self) -> return_status:
        """
        A getter for the output argument 'force_clear_all_faults::status'
        """
        pass
    
    def get_fault_id(self) -> int:
        """
        A getter for the output argument 'force_clear_all_faults::fault_id'
        """
        pass

