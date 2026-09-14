# ********************************************************************************************
# * @file upy_sdr.py
# * @brief uPy dummy Python module generator
# ********************************************************************************************
# * @version           interface sdr v2.0
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
class FileStatus(IntEnum):
    """
    Enumeration class definition for type 'FileStatus'
    """
    # Some unspecified error has occurred
    FILESTATUS_ES_TFTP_ERR_NOT_DEFINED = 0
    """ Client receives this error when the requested
            file does not exist """
    FILESTATUS_ES_TFTP_ERR_FILE_NOT_FOUND = 0
    """ This error occurs when read or write is attempted
            without sufficient privileges (file rights) """
    FILESTATUS_ES_TFTP_ERR_ACESS_VIOLATION = 0
    # Server storage area error - storage is limited
    FILESTATUS_ES_TFTP_ERR_DISK_FULL_OR_ALLOCATION_EXCEEDED = 0
    """ Any TFTP packet that does not follow the RFC is called illegal.
            A packet with a unknown opcode, a packet with a malformed payload, or a packet that is out of
            sequence with the normal flow of commands/responses would all be considered "illegal" """
    FILESTATUS_ES_TFTP_ERR_ILLEGAL_TFTP_OPERATION = 0
    """ When a TFTP client sends a duplicate read request
            (typically this happens when the first read request times out) - the requests
            may create an unexpected situation on the server """
    FILESTATUS_ES_TFTP_ERR_UNKNOWN_TRANSFER_ID = 0
    # There is already a file on the server with the same name
    FILESTATUS_ES_TFTP_ERR_FILE_ALREADY_EXISTS = 0
    # Unused
    FILESTATUS_ES_TFTP_ERR_NO_SUCH_USER = 0
    # No error
    FILESTATUS_ES_TFTP_STATUS_OK = 0
    # Transport layer not initialized
    FILESTATUS_ES_TFTP_TL_NOT_INIT = 0
    # Cannot open destination file for write
    FILESTATUS_ES_TFTP_CANNOT_OPEN_DEST_FILE_FOR_WRITE = 0
    # Failed to write to destination file
    FILESTATUS_ES_TFTP_FAILED_TO_WRITE_TO_DEST_FILE = 0
    # Failed to close destination file
    FILESTATUS_ES_TFTP_FAILED_TO_CLOSE_DEST_FILE = 0
    # Cannot open source file for read
    FILESTATUS_ES_TFTP_CANNOT_OPEN_SOURCE_FILE_FOR_READ = 0
    # File not found on source
    FILESTATUS_ES_TFTP_FILE_NOT_FOUND_ON_SOURCE = 0
    # Failed to read from source file
    FILESTATUS_ES_TFTP_FAILED_TO_READ_FROM_SOURCE_FILE = 0
    # Failed to close source file
    FILESTATUS_ES_TFTP_FAILED_TO_CLOSE_SOURCE_FILE = 0
    # Connection to server failed
    FILESTATUS_ES_TFTP_CONNECTION_TO_SERVER_FAILED = 0
    # Failed to disconnect from server
    FILESTATUS_ES_TFTP_FAILED_TO_DISCONNECT_FROM_SERVER = 0
    # Receive failed
    FILESTATUS_ES_TFTP_RECV_FAILED = 0
    # Send failed
    FILESTATUS_ES_TFTP_SEND_FAILED = 0
    # TFTP block number mismatch
    FILESTATUS_ES_TFTP_BLOCK_NUMBER_MISMATCH = 0
    # Successfully downloaded file, but it has zero size
    FILESTATUS_ES_TFTP_DOWNLOADED_FILE_EMPTY = 0
    # A file transfer is pending for execution
    FILESTATUS_ES_TFTP_TRANSFER_PENDING = 0
    # File transfer is in progress
    FILESTATUS_ES_TFTP_BUSY = 0
class StateMachineState(IntEnum):
    """
    Enumeration class definition for type 'StateMachineState'
    """
    STATEMACHINESTATE_ROOT = 0
    STATEMACHINESTATE_INACTIVE = 0
    STATEMACHINESTATE_BOOTING = 0
    STATEMACHINESTATE_SYNCING = 0
    STATEMACHINESTATE_READY = 0
    STATEMACHINESTATE_BUSY = 0


# ********************************************************************************************
#
# Struct classes
#
# ********************************************************************************************
class FileOp:
    """
    A Python class to represent struct objects of type 'FileOp'
    
    File operation type
    """

    def __init__(self, string__obc_file : str, string__sdr_file : str) -> None:
        """
        Struct 'FileOp' constructor
        
        Attributes
        ---------
        string__obc_file [47] : str
            Absolute file path on the OBC
        string__sdr_file [197] : str
            Absolute file path on the SDR
        """
        
        pass
        
    def get_obc_file(self) -> str:
        """
        A getter for the 'FileOp::obc_file' structure field
        
        Absolute file path on the OBC
        """
        
        pass
    
    def get_sdr_file(self) -> str:
        """
        A getter for the 'FileOp::sdr_file' structure field
        
        Absolute file path on the SDR
        """
        
        pass

def FileOp_make_from_buf(buf : bytes) -> FileOp:
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
def req_sdr_upload(s__file : FileOp) -> bytes:
    """
    Request serialization function for method 'sdr_upload'
    
    Uploads file from the OBC to the SDR 
    
    Arguments
    ---------
    s__file [1] : FileOp
        Full paths of the source file to upload and the upload destination
    """
    
    pass
    
def req_sdr_download(s__file : FileOp) -> bytes:
    """
    Request serialization function for method 'sdr_download'
    
    Downloads file from the SDR to the OBC 
    
    Arguments
    ---------
    s__file [1] : FileOp
        Full paths of the source file to download and the download destination
    """
    
    pass
    
def req_sdr_poll_latest_ft_status() -> bytes:
    """
    Request serialization function for method 'sdr_poll_latest_ft_status'
    
    Reads the latest sdr file transfer operation status 
    
    """
    
    pass
    
def req_sdr_get_state() -> bytes:
    """
    Request serialization function for method 'sdr_get_state'
    
    Returns the current sdr SM state
            Note: If this method returns an invalid state value (e.g MAX_CNT), it means that the current SM state cannot be read.
            This could be due to the fact that the sdr service is handling some kind of operation. 
    
    """
    
    pass
    

# ********************************************************************************************
#
# Response classes
#
# ********************************************************************************************
class resp_sdr_upload:
    """
    A class representing a parsed FIDL response for method 'sdr_upload'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'sdr_upload' method (includes the received FP header)
        """
        pass

    def get_status(self) -> FileStatus:
        """
        A getter for the output argument 'sdr_upload::status'
        """
        pass

class resp_sdr_download:
    """
    A class representing a parsed FIDL response for method 'sdr_download'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'sdr_download' method (includes the received FP header)
        """
        pass

    def get_status(self) -> FileStatus:
        """
        A getter for the output argument 'sdr_download::status'
        """
        pass

class resp_sdr_poll_latest_ft_status:
    """
    A class representing a parsed FIDL response for method 'sdr_poll_latest_ft_status'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'sdr_poll_latest_ft_status' method (includes the received FP header)
        """
        pass

    def get_status(self) -> FileStatus:
        """
        A getter for the output argument 'sdr_poll_latest_ft_status::status'
        """
        pass

class resp_sdr_get_state:
    """
    A class representing a parsed FIDL response for method 'sdr_get_state'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'sdr_get_state' method (includes the received FP header)
        """
        pass

    def get_sm_state(self) -> StateMachineState:
        """
        A getter for the output argument 'sdr_get_state::sm_state'
        """
        pass

