# ********************************************************************************************
# * @file upy_telemetry.py
# * @brief uPy dummy Python module generator
# ********************************************************************************************
# * @version           interface telemetry v2.0
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
class tlm_file_logging_type(IntEnum):
    """
    Enumeration class definition for type 'tlm_file_logging_type'
    """
    TLM_FILE_LOGGING_TYPE_SIZE_LIMIT = 0
class TelemetryInstance(IntEnum):
    """
    Enumeration class definition for type 'TelemetryInstance'
    """
    TELEMETRYINSTANCE_TLM_INST_0 = 0
    TELEMETRYINSTANCE_TLM_INST_1 = 0
class StandardResult(IntEnum):
    """
    Enumeration class definition for type 'StandardResult'
    """
    STANDARDRESULT_SUCCESS = 0
    STANDARDRESULT_ERROR = 0
    STANDARDRESULT_INVALID_ARGS = 0
    STANDARDRESULT_NOT_SUPPORTED = 0


# ********************************************************************************************
#
# Struct classes
#
# ********************************************************************************************
class tlm_preset_cfg:
    """
    A Python class to represent struct objects of type 'tlm_preset_cfg'
    
    Settings for the telemetry service stored in the nvm
    """

    def __init__(self, uint16__data_id : int, bool__active : int, uint16__acq_period_ms : int) -> None:
        """
        Struct 'tlm_preset_cfg' constructor
        
        Attributes
        ---------
        uint16__data_id [1] : int
            DataCache-specified identifier
        bool__active [1] : int
            A flag indicating whether the data_id is part of the telemtry collection for this preset
        uint16__acq_period_ms [1] : int
            data acquistion period from the DataCache in milliseconds
        """
        
        pass
        
    def get_data_id(self) -> int:
        """
        A getter for the 'tlm_preset_cfg::data_id' structure field
        
        DataCache-specified identifier
        """
        
        pass
    
    def get_active(self) -> int:
        """
        A getter for the 'tlm_preset_cfg::active' structure field
        
        A flag indicating whether the data_id is part of the telemtry collection for this preset
        """
        
        pass
    
    def get_acq_period_ms(self) -> int:
        """
        A getter for the 'tlm_preset_cfg::acq_period_ms' structure field
        
        data acquistion period from the DataCache in milliseconds
        """
        
        pass

def tlm_preset_cfg_make_from_buf(buf : bytes) -> tlm_preset_cfg:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class tlm_file_size_limit_cfg:
    """
    A Python class to represent struct objects of type 'tlm_file_size_limit_cfg'
    
    Structure containing the values for the telemetry size limits
    """

    def __init__(self, uint32__size_limit_kb : int, uint16__max_log_files_cnt : int) -> None:
        """
        Struct 'tlm_file_size_limit_cfg' constructor
        
        Attributes
        ---------
        uint32__size_limit_kb [1] : int
            Maximum size limit for all telemetry logged on the SD card
        uint16__max_log_files_cnt [1] : int
            Number of individual files to split the log to
        """
        
        pass
        
    def get_size_limit_kb(self) -> int:
        """
        A getter for the 'tlm_file_size_limit_cfg::size_limit_kb' structure field
        
        Maximum size limit for all telemetry logged on the SD card
        """
        
        pass
    
    def get_max_log_files_cnt(self) -> int:
        """
        A getter for the 'tlm_file_size_limit_cfg::max_log_files_cnt' structure field
        
        Number of individual files to split the log to
        """
        
        pass

def tlm_file_size_limit_cfg_make_from_buf(buf : bytes) -> tlm_file_size_limit_cfg:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class tlm_general_cfg:
    """
    A Python class to represent struct objects of type 'tlm_general_cfg'
    
    Active configuration for the telemetry service
    """

    def __init__(self, bool__tlm_auto_start_en : int) -> None:
        """
        Struct 'tlm_general_cfg' constructor
        
        Attributes
        ---------
        bool__tlm_auto_start_en [1] : int
            Controls whether the telemetry logging is active at start-up. Telemetry sink mechanisms are separately controlled but
                                      if this flag is set to false, all sinks will cease operation.
        """
        
        pass
        
    def get_tlm_auto_start_en(self) -> int:
        """
        A getter for the 'tlm_general_cfg::tlm_auto_start_en' structure field
        
        Controls whether the telemetry logging is active at start-up. Telemetry sink mechanisms are separately controlled but
                                  if this flag is set to false, all sinks will cease operation.
        """
        
        pass

def tlm_general_cfg_make_from_buf(buf : bytes) -> tlm_general_cfg:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class tlm_stats:
    """
    A Python class to represent struct objects of type 'tlm_stats'
    
    Counters of relevant events from the telemetry service
    """

    def __init__(self, bool__is_started : int, uint32__msg_pushed_cnt : int, uint32__msg_popped_cnt : int, uint32__free_bytes_min : int, uint32__discarded_messages_cnt : int, uint32__max_number_of_batch_msg : int, uint32__active_slot_id : int) -> None:
        """
        Struct 'tlm_stats' constructor
        
        Attributes
        ---------
        bool__is_started [1] : int
            Shows whether the telemetry collection and storage is active
        uint32__msg_pushed_cnt [1] : int
            number of pushed messages since system boot
        uint32__msg_popped_cnt [1] : int
            number of popped messages since system boot
        uint32__free_bytes_min [1] : int
            minimum value reached for the free space in the queue
        uint32__discarded_messages_cnt [1] : int
            number of discarded messages due to lack of space in the queue
        uint32__max_number_of_batch_msg [1] : int
            maximum number of messages processed in a batch on a single run
        uint32__active_slot_id [1] : int
            identifier of the active slot where telemetry is currently stored
        """
        
        pass
        
    def get_is_started(self) -> int:
        """
        A getter for the 'tlm_stats::is_started' structure field
        
        Shows whether the telemetry collection and storage is active
        """
        
        pass
    
    def get_msg_pushed_cnt(self) -> int:
        """
        A getter for the 'tlm_stats::msg_pushed_cnt' structure field
        
        number of pushed messages since system boot
        """
        
        pass
    
    def get_msg_popped_cnt(self) -> int:
        """
        A getter for the 'tlm_stats::msg_popped_cnt' structure field
        
        number of popped messages since system boot
        """
        
        pass
    
    def get_free_bytes_min(self) -> int:
        """
        A getter for the 'tlm_stats::free_bytes_min' structure field
        
        minimum value reached for the free space in the queue
        """
        
        pass
    
    def get_discarded_messages_cnt(self) -> int:
        """
        A getter for the 'tlm_stats::discarded_messages_cnt' structure field
        
        number of discarded messages due to lack of space in the queue
        """
        
        pass
    
    def get_max_number_of_batch_msg(self) -> int:
        """
        A getter for the 'tlm_stats::max_number_of_batch_msg' structure field
        
        maximum number of messages processed in a batch on a single run
        """
        
        pass
    
    def get_active_slot_id(self) -> int:
        """
        A getter for the 'tlm_stats::active_slot_id' structure field
        
        identifier of the active slot where telemetry is currently stored
        """
        
        pass

def tlm_stats_make_from_buf(buf : bytes) -> tlm_stats:
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
def req_getTelemetryGeneralConfig(e__TelemetryInstance__tlm_instance_id : TelemetryInstance) -> bytes:
    """
    Request serialization function for method 'getTelemetryGeneralConfig'
    
    Obtains the general Telemetry configuration settings 
    
    Arguments
    ---------
    e__TelemetryInstance__tlm_instance_id [1] : TelemetryInstance
        Telemetry instance ID
    """
    
    pass
    
def req_setTelemetryGeneralConfig(e__TelemetryInstance__tlm_instance_id : TelemetryInstance, s__cfg : tlm_general_cfg) -> bytes:
    """
    Request serialization function for method 'setTelemetryGeneralConfig'
    
    Used to update the general Telemetry configuration settings 
    
    Arguments
    ---------
    e__TelemetryInstance__tlm_instance_id [1] : TelemetryInstance
        Telemetry instance ID
    s__cfg [1] : tlm_general_cfg
    """
    
    pass
    
def req_getTelemetryPresetConfig(e__TelemetryInstance__tlm_instance_id : TelemetryInstance) -> bytes:
    """
    Request serialization function for method 'getTelemetryPresetConfig'
    
    Obtains the Telemetry service slot assignment configuration 
    
    Arguments
    ---------
    e__TelemetryInstance__tlm_instance_id [1] : TelemetryInstance
        Telemetry instance ID
    """
    
    pass
    
def req_setTelemetryPresetConfig(e__TelemetryInstance__tlm_instance_id : TelemetryInstance, a__s__30__Telemetry_preset_cfg : list[tlm_preset_cfg]) -> bytes:
    """
    Request serialization function for method 'setTelemetryPresetConfig'
    
    Used to update the Telemetry service slot assignment configuration 
    
    Arguments
    ---------
    e__TelemetryInstance__tlm_instance_id [1] : TelemetryInstance
        Telemetry instance ID
    a__s__30__Telemetry_preset_cfg [30] : list[tlm_preset_cfg]
        Specifies the different slot preset assignments of telemetry identifiers.
                                      Presets can be changed at run-time depending on different conditions.
                                      The size below is specified by calculating the number of slot presets slot_preset_cnt times
                                      the maximum number of Telemetry messages max_bcn_msg_cnt in a single Telemetry sequence. This number
                                      must match the number configured in the device firmware where this interface is
                                      implemented. In this case, this is 4 presets consisting of 20 messages each.
                                      The array is encoded as a 1D representation of a matrix where each row specifies all max_bcn_msg_cnt
                                      message IDs for a single preset.
    """
    
    pass
    
def req_setActivePreset(e__TelemetryInstance__tlm_instance_id : TelemetryInstance, uint8__req_active_preset : int) -> bytes:
    """
    Request serialization function for method 'setActivePreset'
    
    Request a change in the Telemetry active preset 
    
    Arguments
    ---------
    e__TelemetryInstance__tlm_instance_id [1] : TelemetryInstance
        Telemetry instance ID
    uint8__req_active_preset [1] : int
        Preset ID to use for Telemetry transmission. It will be active until next reboot or until a call
                                      to restoreActivePreset method is performed.
    """
    
    pass
    
def req_getActivePreset(e__TelemetryInstance__tlm_instance_id : TelemetryInstance) -> bytes:
    """
    Request serialization function for method 'getActivePreset'
    
    Provides the currently active preset id used for Telemetry transmission 
    
    Arguments
    ---------
    e__TelemetryInstance__tlm_instance_id [1] : TelemetryInstance
        Telemetry instance ID
    """
    
    pass
    
def req_restoreActivePreset(e__TelemetryInstance__tlm_instance_id : TelemetryInstance) -> bytes:
    """
    Request serialization function for method 'restoreActivePreset'
    
    Restores the active preset autonomous mode, e.g. calculated by ConOps. 
    
    Arguments
    ---------
    e__TelemetryInstance__tlm_instance_id [1] : TelemetryInstance
        Telemetry instance ID
    """
    
    pass
    
def req_getTelemetryFileSinkConfig(e__TelemetryInstance__tlm_instance_id : TelemetryInstance) -> bytes:
    """
    Request serialization function for method 'getTelemetryFileSinkConfig'
    
    Provides all file-based telemetry configuration settings 
    
    Arguments
    ---------
    e__TelemetryInstance__tlm_instance_id [1] : TelemetryInstance
        Telemetry instance ID
    """
    
    pass
    
def req_setTelemetryFileSzLimitConfig(e__TelemetryInstance__tlm_instance_id : TelemetryInstance, s__size_limit_cfg : tlm_file_size_limit_cfg) -> bytes:
    """
    Request serialization function for method 'setTelemetryFileSzLimitConfig'
    
    Used to update the size-limit file telemetry configuration settings.
                          The configuration becomes active as soon as it is set unless an error is
                          returned. 
    
    Arguments
    ---------
    e__TelemetryInstance__tlm_instance_id [1] : TelemetryInstance
        Telemetry instance ID
    s__size_limit_cfg [1] : tlm_file_size_limit_cfg
    """
    
    pass
    
def req_cleanTelemetryFiles(e__TelemetryInstance__tlm_instance_id : TelemetryInstance) -> bytes:
    """
    Request serialization function for method 'cleanTelemetryFiles'
    
    Cleans-up all accumulated telemetry files on the storage. Please use with care because the files cannot be restored
                          after this operation. 
    
    Arguments
    ---------
    e__TelemetryInstance__tlm_instance_id [1] : TelemetryInstance
        Telemetry instance ID
    """
    
    pass
    
def req_getTelemetryOperationStats(e__TelemetryInstance__tlm_instance_id : TelemetryInstance) -> bytes:
    """
    Request serialization function for method 'getTelemetryOperationStats'
    
    Provides the accummulated run-time statistics for the telemetry operation 
    
    Arguments
    ---------
    e__TelemetryInstance__tlm_instance_id [1] : TelemetryInstance
        Telemetry instance ID
    """
    
    pass
    
def req_startTelemetry(e__TelemetryInstance__tlm_instance_id : TelemetryInstance, uint16__hold_time_sec : int) -> bytes:
    """
    Request serialization function for method 'startTelemetry'
    
    Start the telemetry collection and storage 
    
    Arguments
    ---------
    e__TelemetryInstance__tlm_instance_id [1] : TelemetryInstance
        Telemetry instance ID
    uint16__hold_time_sec [1] : int
        Number of seconds before automatically stopping the telemetry after it has been started. 
                                      If 0, the stopTelemetry method shall be called to stop the telemetry again.
    """
    
    pass
    
def req_stopTelemetry(e__TelemetryInstance__tlm_instance_id : TelemetryInstance, uint16__hold_time_sec : int) -> bytes:
    """
    Request serialization function for method 'stopTelemetry'
    
    Stop the telemetry collection and storage 
    
    Arguments
    ---------
    e__TelemetryInstance__tlm_instance_id [1] : TelemetryInstance
        Telemetry instance ID
    uint16__hold_time_sec [1] : int
        Number of seconds before automatically starting the telemetry after it has been stopped. 
                                      If 0, the startTelemetry method shall be called to start the telemetry again.
    """
    
    pass
    

# ********************************************************************************************
#
# Response classes
#
# ********************************************************************************************
class resp_getTelemetryGeneralConfig:
    """
    A class representing a parsed FIDL response for method 'getTelemetryGeneralConfig'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTelemetryGeneralConfig' method (includes the received FP header)
        """
        pass

    def get_res(self) -> StandardResult:
        """
        A getter for the output argument 'getTelemetryGeneralConfig::res'
        """
        pass
    
    def get_cfg(self) -> tlm_general_cfg:
        """
        A getter for the output argument 'getTelemetryGeneralConfig::cfg'
        """
        pass

class resp_setTelemetryGeneralConfig:
    """
    A class representing a parsed FIDL response for method 'setTelemetryGeneralConfig'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setTelemetryGeneralConfig' method (includes the received FP header)
        """
        pass

    def get_res(self) -> StandardResult:
        """
        A getter for the output argument 'setTelemetryGeneralConfig::res'
        """
        pass

class resp_getTelemetryPresetConfig:
    """
    A class representing a parsed FIDL response for method 'getTelemetryPresetConfig'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTelemetryPresetConfig' method (includes the received FP header)
        """
        pass

    def get_res(self) -> StandardResult:
        """
        A getter for the output argument 'getTelemetryPresetConfig::res'
        """
        pass
    
    def get_slot_preset_cnt(self) -> int:
        """
        A getter for the output argument 'getTelemetryPresetConfig::slot_preset_cnt'
        """
        pass
    
    def get_max_tlm_msg_cnt(self) -> int:
        """
        A getter for the output argument 'getTelemetryPresetConfig::max_tlm_msg_cnt'
        """
        pass
    
    def get_Telemetry_preset_cfg(self) -> list[tlm_preset_cfg]:
        """
        A getter for the output argument 'getTelemetryPresetConfig::Telemetry_preset_cfg'
        """
        pass

class resp_setTelemetryPresetConfig:
    """
    A class representing a parsed FIDL response for method 'setTelemetryPresetConfig'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setTelemetryPresetConfig' method (includes the received FP header)
        """
        pass

    def get_res(self) -> StandardResult:
        """
        A getter for the output argument 'setTelemetryPresetConfig::res'
        """
        pass

class resp_setActivePreset:
    """
    A class representing a parsed FIDL response for method 'setActivePreset'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setActivePreset' method (includes the received FP header)
        """
        pass

    def get_res(self) -> StandardResult:
        """
        A getter for the output argument 'setActivePreset::res'
        """
        pass
    
    def get_avail_presets_cnt(self) -> int:
        """
        A getter for the output argument 'setActivePreset::avail_presets_cnt'
        """
        pass

class resp_getActivePreset:
    """
    A class representing a parsed FIDL response for method 'getActivePreset'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getActivePreset' method (includes the received FP header)
        """
        pass

    def get_res(self) -> StandardResult:
        """
        A getter for the output argument 'getActivePreset::res'
        """
        pass
    
    def get_active_preset_id(self) -> int:
        """
        A getter for the output argument 'getActivePreset::active_preset_id'
        """
        pass

class resp_restoreActivePreset:
    """
    A class representing a parsed FIDL response for method 'restoreActivePreset'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'restoreActivePreset' method (includes the received FP header)
        """
        pass

    def get_res(self) -> StandardResult:
        """
        A getter for the output argument 'restoreActivePreset::res'
        """
        pass

class resp_getTelemetryFileSinkConfig:
    """
    A class representing a parsed FIDL response for method 'getTelemetryFileSinkConfig'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTelemetryFileSinkConfig' method (includes the received FP header)
        """
        pass

    def get_res(self) -> StandardResult:
        """
        A getter for the output argument 'getTelemetryFileSinkConfig::res'
        """
        pass
    
    def get_active_file_cfg_type(self) -> tlm_file_logging_type:
        """
        A getter for the output argument 'getTelemetryFileSinkConfig::active_file_cfg_type'
        """
        pass
    
    def get_size_limit_cfg(self) -> tlm_file_size_limit_cfg:
        """
        A getter for the output argument 'getTelemetryFileSinkConfig::size_limit_cfg'
        """
        pass

class resp_setTelemetryFileSzLimitConfig:
    """
    A class representing a parsed FIDL response for method 'setTelemetryFileSzLimitConfig'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setTelemetryFileSzLimitConfig' method (includes the received FP header)
        """
        pass

    def get_res(self) -> StandardResult:
        """
        A getter for the output argument 'setTelemetryFileSzLimitConfig::res'
        """
        pass

class resp_cleanTelemetryFiles:
    """
    A class representing a parsed FIDL response for method 'cleanTelemetryFiles'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'cleanTelemetryFiles' method (includes the received FP header)
        """
        pass

    def get_res(self) -> StandardResult:
        """
        A getter for the output argument 'cleanTelemetryFiles::res'
        """
        pass

class resp_getTelemetryOperationStats:
    """
    A class representing a parsed FIDL response for method 'getTelemetryOperationStats'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTelemetryOperationStats' method (includes the received FP header)
        """
        pass

    def get_res(self) -> StandardResult:
        """
        A getter for the output argument 'getTelemetryOperationStats::res'
        """
        pass
    
    def get_telemetry_stats(self) -> tlm_stats:
        """
        A getter for the output argument 'getTelemetryOperationStats::telemetry_stats'
        """
        pass

class resp_startTelemetry:
    """
    A class representing a parsed FIDL response for method 'startTelemetry'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'startTelemetry' method (includes the received FP header)
        """
        pass

    def get_res(self) -> StandardResult:
        """
        A getter for the output argument 'startTelemetry::res'
        """
        pass

class resp_stopTelemetry:
    """
    A class representing a parsed FIDL response for method 'stopTelemetry'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'stopTelemetry' method (includes the received FP header)
        """
        pass

    def get_res(self) -> StandardResult:
        """
        A getter for the output argument 'stopTelemetry::res'
        """
        pass

