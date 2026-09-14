# ********************************************************************************************
# * @file upy_obc_cubeadcs_gen2.py
# * @brief uPy dummy Python module generator
# ********************************************************************************************
# * @version           interface OBC_CUBEADCS_GEN2 v5.0
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
class sys_states(IntEnum):
    """
    Enumeration class definition for type 'sys_states'
    """
    SYS_STATES_NO_CONTROL = 0
    SYS_STATES_NORMAL_DETUMBLING = 0
    SYS_STATES_Y_THOMSON = 0
    SYS_STATES_Y_THOMSON_MEMS_RATE = 0
    SYS_STATES_FAST_DETUMBLING = 0
    SYS_STATES_VERY_FAST_DETUMBLING = 0
    SYS_STATES_Y_MOMENTUM = 0
    SYS_STATES_Y_MOMENTUM_FULL_STATE_EKF = 0
    SYS_STATES_THREE_AXIS = 0
    SYS_STATES_SUN_TRACKING = 0
    SYS_STATES_TARGET_TRACKING = 0
    SYS_STATES_USER1 = 0
    SYS_STATES_USER2 = 0
    SYS_STATES_USER3 = 0
class TctlmCommonFrameworkEnums_NodeType(IntEnum):
    """
    Enumeration class definition for type 'TctlmCommonFrameworkEnums_NodeType'
    """
    TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_INVALID = 0
    TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_COMPUTER = 0
    TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_SENSE = 0
    TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_WHEEL = 0
    TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_IR = 0
    TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_MAG_DEPLOY = 0
    TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_MAG_COMPACT = 0
    TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_STAR = 0
    TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_AURIGA = 0
    TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE = 0
    TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_SLT = 0
    TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_PST3S = 0
    TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_NSSRWL = 0
    TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_QUAD = 0
    TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_QUAD_PST3S = 0
    TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_QUAD_NSSRWL = 0
    TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_QUAD_LITEFUFORS = 0
class AbstractImagingNodeType(IntEnum):
    """
    Enumeration class definition for type 'AbstractImagingNodeType'
    """
    ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_STR_0 = 0
    ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_STR_1 = 0
    ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_FSS_0 = 0
    ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_FSS_1 = 0
    ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_FSS_2 = 0
    ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_FSS_3 = 0
    ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_HSS_0 = 0
    ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_HSS_1 = 0
class TctlmCubeComputerControlProgram8_FtpUpgradeState(IntEnum):
    """
    Enumeration class definition for type 'TctlmCubeComputerControlProgram8_FtpUpgradeState'
    """
    TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_IDLE = 0
    TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_INIT = 0
    TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_TRANS = 0
    TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_INIT_BIN = 0
    TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_INIT_CFG = 0
    TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_BUSY_BIN = 0
    TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_BUSY_CFG = 0
class AdcsRunMode(IntEnum):
    """
    Enumeration class definition for type 'AdcsRunMode'
    """
    # ADCS loop is inactive
    ADCSRUNMODE_ADCSOFF = 0
    # ADCS loop is active
    ADCSRUNMODE_ADCSENABLED = 0
    # ADCS loop executed on trigger
    ADCSRUNMODE_ADCSTRIGGERED = 0
    # ADCS is in simulation mode
    ADCSRUNMODE_ADCSSIMULATION = 0
class events_enum(IntEnum):
    """
    Enumeration class definition for type 'events_enum'
    """
    EVENTS_ENUM_NODE_COMMUNICATION_ERROR = 0
    EVENTS_ENUM_ADCS_CONFIG_VALIDATION_ERROR = 0
    EVENTS_ENUM_NODE_SETUP_ERROR = 0
    EVENTS_ENUM_NODE_JUMP_ERROR = 0
    EVENTS_ENUM_MAG_DEPLOY_ERROR = 0
    EVENTS_ENUM_CONTROL_LOOP_FAILURE = 0
    EVENTS_ENUM_NODE_FAILURE = 0
    EVENTS_ENUM_CONFIG_PERSIST_ERROR = 0
    EVENTS_ENUM_VIRTUAL_WATCHDOG_WARNING = 0
    EVENTS_ENUM_PORT_VALIDATION_ERROR = 0
    EVENTS_ENUM_AUTO_DISCOVERY_ERROR = 0
    EVENTS_ENUM_CONTROL_LOOP_CRITICAL = 0
    EVENTS_ENUM_GYRO_VOLTAGE_ERROR = 0
    EVENTS_ENUM_GYRO_CRITICAL = 0
    EVENTS_ENUM_VIRTUAL_WATCHDOG_ERROR = 0
class StandardResult(IntEnum):
    """
    Enumeration class definition for type 'StandardResult'
    """
    STANDARDRESULT_SUCCESS = 0
    STANDARDRESULT_ERROR = 0
    STANDARDRESULT_INVALID_ARGS = 0
    STANDARDRESULT_NOT_SUPPORTED = 0
class NodePowerState(IntEnum):
    """
    Enumeration class definition for type 'NodePowerState'
    """
    NODEPOWERSTATE_OFF = 0
    NODEPOWERSTATE_ON = 0
    NODEPOWERSTATE_NO_CHANGE = 0
    NODEPOWERSTATE_AUTO = 0
    NODEPOWERSTATE_POWER_ON_PASS = 0
class TctlmCubeComputerCommon3_EventReadQueueState(IntEnum):
    """
    Enumeration class definition for type 'TctlmCubeComputerCommon3_EventReadQueueState'
    """
    TCTLMCUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_TCTLM_CUBE_COMPUTER_COMMON_3__EVT_READ_QIDLE = 0
    TCTLMCUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_TCTLM_CUBE_COMPUTER_COMMON_3__EVT_READ_QDOWNLOAD = 0
    TCTLMCUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_TCTLM_CUBE_COMPUTER_COMMON_3__EVT_READ_QERASE = 0
class StateMachineEvents(IntEnum):
    """
    Enumeration class definition for type 'StateMachineEvents'
    """
    # Reset the state machine to its initial state. This event is always executed.
    STATEMACHINEEVENTS_RESET = 0
    # This event will complete the EVENT MARKER ACQUISITION state and transition the SM to CHECK.
    STATEMACHINEEVENTS_EVENT_MARKER_ACQUIRED = 0
    # Request the FDIR state. If an FDIR error is reported and there is relevant logic, it will be executed.
    STATEMACHINEEVENTS_REQUEST_FDIR = 0
    # Request the state change state. This event requires the control, estimation and power mode parameters defined in state_change_args.
    STATEMACHINEEVENTS_REQUEST_STATE_CHANGE = 0
    # This event will put the SM back to IDLE state in case we are in the CHECK state.
    STATEMACHINEEVENTS_CHECK_COMPLETED = 0
    # This event will put the SM back to IDLE state in case we are in the EVENT DOWNLOAD state.
    STATEMACHINEEVENTS_EVENT_DOWNLOAD_COMPLETED = 0
    # This event will put the SM back to IDLE state in case we are in the STATE CHANGE state.
    STATEMACHINEEVENTS_STATE_CHANGE_COMPLETED = 0
    # This event will put the SM back to IDLE state in case we are in the FDIR state.
    STATEMACHINEEVENTS_FDIR_COMPLETED = 0
    # This event will put the SM back to INIT state in case we are in the FDIR state.
    STATEMACHINEEVENTS_ADCS_RESETED = 0
class TctlmCubeComputerCommon3_ImageTransferState(IntEnum):
    """
    Enumeration class definition for type 'TctlmCubeComputerCommon3_ImageTransferState'
    """
    TCTLMCUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_TCTLM_CUBE_COMPUTER_COMMON_3__STATE_IDLE = 0
    TCTLMCUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_TCTLM_CUBE_COMPUTER_COMMON_3__STATE_BUSY_STORE = 0
    TCTLMCUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_TCTLM_CUBE_COMPUTER_COMMON_3__STATE_BUSY_DOWNLOAD = 0
class EstimationModes(IntEnum):
    """
    Enumeration class definition for type 'EstimationModes'
    """
    ESTIMATIONMODES_EST_NO_ESIMATOR = 0
    ESTIMATIONMODES_EST_GYRO_MEASURED_RATES = 0
    ESTIMATIONMODES_EST_MAG_EST_RATES = 0
    ESTIMATIONMODES_EST_MAG_EST_RATES_WITH_PITCH_EST = 0
    ESTIMATIONMODES_EST_TRIAD = 0
    ESTIMATIONMODES_EST_FULL_STATE_EKF = 0
    ESTIMATIONMODES_EST_GYRO_EKF = 0
    ESTIMATIONMODES_EST_USER = 0
class CommissioningStatus(IntEnum):
    """
    Enumeration class definition for type 'CommissioningStatus'
    """
    COMMISSIONINGSTATUS_CMS_STATUS_NOT_DONE = 0
    COMMISSIONINGSTATUS_CMS_STATUS_COMPLETE = 0
class BootState(IntEnum):
    """
    Enumeration class definition for type 'BootState'
    """
    # Bootloader is running in main()
    BOOTSTATE_BOOTLOADERRUNNING = 0
    # Bootloader is running and is in the timer backoff state
    BOOTSTATE_BOOTLOADERBACKOFF = 0
    # Bootloader is running and performing port validation of connected nodes. Only applicable to CubeComputer
    BOOTSTATE_BOOTLOADERPORTVALIDATION = 0
    # Bootloader is running and performing node auto discovery of connected nodes. Only applicable to CubeComputer
    BOOTSTATE_BOOTLOADERAUTODISCOVER = 0
    # Bootloader is running and is halted, awaiting instructions
    BOOTSTATE_BOOTLOADERHALT = 0
    # Bootloader is jumping to application
    BOOTSTATE_BOOTLOADERJUMP = 0
    # Bootloader is running and experienced an error attempting to run the control-program, see error flags
    BOOTSTATE_BOOTLOADEREXITERROR = 0
    # Application is running after successful bootloader execution
    BOOTSTATE_APPLICATIONRUNNING = 0
    # Bootloader is removing write-protection from its config region
    BOOTSTATE_BOOTLOADERCFGUNLOCK = 0
    # Bootloader is enabling boot pin
    BOOTSTATE_BOOTLOADERBOOTPINEN = 0
    # Bootloader is disabling boot pin
    BOOTSTATE_BOOTLOADERBOOTPINDIS = 0
    # Bootloader is clearing all write-protction
    BOOTSTATE_BOOTLOADERWRPCLEAR = 0
    # Bootloader failed to load option bytes after unlocking config
    BOOTSTATE_BOOTLOADERCFGUNLOCKERROR = 0
    # Bootloader failed to load option bytes after enabling boot pin
    BOOTSTATE_BOOTLOADERBOOTPINENERROR = 0
    # Bootloader failed to load option bytes after disabling boot pin
    BOOTSTATE_BOOTLOADERBOOTPINDISERROR = 0
    # Bootloader failed to load option bytes after clearing all write-protction
    BOOTSTATE_BOOTLOADERWRPCLEARERROR = 0
    # Auto-discovery failed
    BOOTSTATE_BOOTLOADERAUTODISCOVERERROR = 0
    # Boot bank could not be synchronized with flash option bytes
    BOOTSTATE_BOOTLOADERBANKSYNCERROR = 0
    # Application has been commanded to reset to the bootloader and halt immediately
    BOOTSTATE_BOOTLOADERHALTRESET = 0
    # Application has triggered an ASSERT and will immediately. This is transitory and is not expected to be read as the state. It will be reflected in the reset reason.
    BOOTSTATE_ASSERTERROR = 0
class TctlmCubeComputerCommon3_TlmLogReadQueueState(IntEnum):
    """
    Enumeration class definition for type 'TctlmCubeComputerCommon3_TlmLogReadQueueState'
    """
    TCTLMCUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TCTLM_CUBE_COMPUTER_COMMON_3__TLM_READ_QIDLE = 0
    TCTLMCUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TCTLM_CUBE_COMPUTER_COMMON_3__TLM_READ_QDOWNLOAD = 0
    TCTLMCUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TCTLM_CUBE_COMPUTER_COMMON_3__TLM_READ_QERASE = 0
class BootResetReason(IntEnum):
    """
    Enumeration class definition for type 'BootResetReason'
    """
    # Reset reason is unknown
    BOOTRESETREASON_RESETUNKNOWN = 0
    # Firewall (Unused)
    BOOTRESETREASON_RESETFIREWALL = 0
    # Option-byte reset. This will have a dedicated reset reason if commanded, otherwise, is signals that the bootloader reloaded option bytes automatically before exitting.
    BOOTRESETREASON_RESETOBL = 0
    # External Pin reset (Unused)
    BOOTRESETREASON_RESETEXTPIN = 0
    # Brown Out reset
    BOOTRESETREASON_RESETBROWNOUT = 0
    # Software reset
    BOOTRESETREASON_RESETSOFT = 0
    # WatchDog Reset
    BOOTRESETREASON_RESETWATCHDOG = 0
    # Low Power Reset
    BOOTRESETREASON_RESETLOWPOWER = 0
    # Soft reset commanded to halth bootloader immediately
    BOOTRESETREASON_RESETENTERBOOTLOADER = 0
    # Bootloader was commanded to unlock config - reset caused by removing write-protection
    BOOTRESETREASON_RESETCFGUNLOCK = 0
    # Bootloader was commanded to enable boot pin - reset caused by option bytes reload
    BOOTRESETREASON_RESETBOOTPINEN = 0
    # Bootloader was commanded to disable boot pin - reset caused by option bytes reload
    BOOTRESETREASON_RESETBOOTPINDIS = 0
    # Bootloader was commanded to clear all write-protection - reset caused by option bytes reload
    BOOTRESETREASON_RESETWRPCLEARALL = 0
    # Attempt to unlock config failed - reset called internally
    BOOTRESETREASON_RESETCFGUNLOCKERR = 0
    # Attempt to enable boot pin failed - reset called internally
    BOOTRESETREASON_RESETBOOTPINENERR = 0
    # Attempt to disable boot pin failed - reset called internally
    BOOTRESETREASON_RESETBOOTPINDISERR = 0
    # Attempt to clear all write-protection failed - reset called internally
    BOOTRESETREASON_RESETWRPCLEARALLERR = 0
    # Attempt to exit bootloader failed - reset called internally
    BOOTRESETREASON_RESETBOOTLOADEREXITERR = 0
    # Attempt to jump to new bootloader failed and bank synchronization also failed - reset called internally
    BOOTRESETREASON_RESETBOOTLOADERBANKSYNCERR = 0
    # The running application triggered an ASSERT and reset - check error log for error code
    BOOTRESETREASON_RESETASSERTERR = 0
class TctlmCubeComputerControlProgram8_FtpState(IntEnum):
    """
    Enumeration class definition for type 'TctlmCubeComputerControlProgram8_FtpState'
    """
    TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPSTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__IDLE = 0
    TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPSTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__INIT = 0
    TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPSTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__BUSY = 0
    TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPSTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__LOCKED = 0
class StateMachineStates(IntEnum):
    """
    Enumeration class definition for type 'StateMachineStates'
    """
    STATEMACHINESTATES_ROOT = 0
    STATEMACHINESTATES_INIT = 0
    STATEMACHINESTATES_FIRMWARE_UPDATE = 0
    STATEMACHINESTATES_EVENT_MARKER_ACQUISITION = 0
    STATEMACHINESTATES_IDLE = 0
    STATEMACHINESTATES_CHECK = 0
    STATEMACHINESTATES_EVENT_DOWNLOAD = 0
    STATEMACHINESTATES_STATE_CHANGE = 0
    STATEMACHINESTATES_FDIR = 0
class AdcsOpState(IntEnum):
    """
    Enumeration class definition for type 'AdcsOpState'
    """
    # Manual operational state
    ADCSOPSTATE_OPSTATEMANUAL = 0
    # Autonomous operational state
    ADCSOPSTATE_OPSTATEAUTO = 0
    # Safe operational state
    ADCSOPSTATE_OPSTATESAFE = 0
    # Fault operational state
    ADCSOPSTATE_OPSTATEFAULT = 0
class AdcsProgType(IntEnum):
    """
    Enumeration class definition for type 'AdcsProgType'
    """
    # Bootloader
    ADCSPROGTYPE_BOOTLOADER = 0
    # Application
    ADCSPROGTYPE_APPLICATION = 0
class TctlmCubeComputerCommon3_LogReadFilterType(IntEnum):
    """
    Enumeration class definition for type 'TctlmCubeComputerCommon3_LogReadFilterType'
    """
    TCTLMCUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_TCTLM_CUBE_COMPUTER_COMMON_3__FILTER_NONE = 0
    TCTLMCUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_TCTLM_CUBE_COMPUTER_COMMON_3__FILTER_TIME_SPAN = 0
    TCTLMCUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_TCTLM_CUBE_COMPUTER_COMMON_3__FILTER_TIME_NEXT_X = 0
    TCTLMCUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_TCTLM_CUBE_COMPUTER_COMMON_3__FILTER_FIRST_X = 0
    TCTLMCUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_TCTLM_CUBE_COMPUTER_COMMON_3__FILTER_LAST_X = 0
    TCTLMCUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_TCTLM_CUBE_COMPUTER_COMMON_3__FILTER_COUNTER_NEXT_X = 0
class TctlmCubeComputerCommon3_TlmLogReturnIntervalValues(IntEnum):
    """
    Enumeration class definition for type 'TctlmCubeComputerCommon3_TlmLogReturnIntervalValues'
    """
    TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL_200MS = 0
    TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL1S = 0
    TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL2S = 0
    TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL3S = 0
    TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL4S = 0
    TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL5S = 0
    TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL_10S = 0
    TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL_20S = 0
    TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL_50S = 0
    TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL_100S = 0
class ControlModes(IntEnum):
    """
    Enumeration class definition for type 'ControlModes'
    """
    CONTROLMODES_CNTRL_NO_CONTROL = 0
    CONTROLMODES_CNTRL_1_AXIS_BDOT = 0
    CONTROLMODES_CNTRL_Y_THOMSON = 0
    CONTROLMODES_CNTRL_3_AXIS_BDOT = 0
    CONTROLMODES_CNTRL_3_AXIS_LOW_POWER = 0
    CONTROLMODES_CNTRL_SUN_Y_AXIS_SPIN_DETUMB = 0
    CONTROLMODES_CNTRL_Z_THOMSON = 0
    CONTROLMODES_CNTRL_SUN_Z_AXIS_SPIN_DETUMB = 0
    CONTROLMODES_CNTRL_MAG_CNTRL_GG_BOOM_AND_YAW = 0
    CONTROLMODES_CNTRL_MAG_CNTRL_GG_BOOM_AND_Z = 0
    CONTROLMODES_CNTRL_INITIAL_Y_WHEEL_RAMP_UP = 0
    CONTROLMODES_CNTRL_INITIAL_Y_WHEEL_PITCH_CNTRL = 0
    CONTROLMODES_CNTRL_RW_3_AXIS = 0
    CONTROLMODES_CNTRL_RW_SUN_TRACKING = 0
    CONTROLMODES_CNTRL_RW_EO_TARGET_TRACKING = 0
    CONTROLMODES_CNTRL_RW_EARTH_TARGET_STEERING = 0
    CONTROLMODES_CNTRL_RW_GS_TARGET_TRACKING = 0
    CONTROLMODES_CNTRL_RW_INERTIAL_TARGET_TRACKING = 0
    CONTROLMODES_CNTRL_RW_MOON_TRACKING = 0
    CONTROLMODES_CNTRL_RW_SAT_TARGET_TRACKING = 0
    CONTROLMODES_CNTRL_NADIR_AND_YAW_TO_SUN = 0
    CONTROLMODES_CNTRL_NADIR_AND_YAW_TO_GROUND_TARGET = 0
    CONTROLMODES_CNTRL_VELOCITY_AND_ROLL_TO_SUN = 0
    CONTROLMODES_CNTRL_VELOCITY_AND_ROLL_TO_GROUND_TARGET = 0
    CONTROLMODES_CNTRL_NADIR_AND_YAW_BEST_TO_GS = 0
    CONTROLMODES_CNTRL_FMC_TARGET = 0
    CONTROLMODES_CNTRL_YAW_SUN_SPIN = 0
    CONTROLMODES_CNTRL_SUN_DETUMBLE = 0
    CONTROLMODES_CNTRL_STOP_RW_CONTROLLED = 0
    CONTROLMODES_CNTRL_OPEN_LOOP_RW = 0
    CONTROLMODES_CNTRL_USER = 0


# ********************************************************************************************
#
# Struct classes
#
# ********************************************************************************************
class FName:
    """
    A Python class to represent struct objects of type 'FName'
    
    """

    def __init__(self, a__uint8__47__name : list[int]) -> None:
        """
        Struct 'FName' constructor
        
        Attributes
        ---------
        a__uint8__47__name [47] : list[int]
        """
        
        pass
        
    def get_name(self) -> list[int]:
        """
        A getter for the 'FName::name' structure field
        
        """
        
        pass

def FName_make_from_buf(buf : bytes) -> FName:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class telemetry_mask_2:
    """
    A Python class to represent struct objects of type 'telemetry_mask_2'
    
    Telemetry mask 2 of loggable frames - Check CubeSpace documentation for further information
    """

    def __init__(self, bool__en_get_raw_gyr_sensor_telemetry : int, bool__en_get_raw_rwl_sensor_telemetry : int, bool__en_get_calibrated_css_sensor_telemetry : int, bool__en_get_calibrated_gyr_sensor_telemetry : int, bool__en_get_calibrated_str_sensor_telemetry : int, bool__en_get_calibrated_rwl_sensor_telemetry : int, bool__en_get_main_estimator_telemetry : int, bool__en_get_main_estimator_high_resolution_telemetry : int) -> None:
        """
        Struct 'telemetry_mask_2' constructor
        
        Attributes
        ---------
        bool__en_get_raw_gyr_sensor_telemetry [1] : int
        bool__en_get_raw_rwl_sensor_telemetry [1] : int
        bool__en_get_calibrated_css_sensor_telemetry [1] : int
        bool__en_get_calibrated_gyr_sensor_telemetry [1] : int
        bool__en_get_calibrated_str_sensor_telemetry [1] : int
        bool__en_get_calibrated_rwl_sensor_telemetry [1] : int
        bool__en_get_main_estimator_telemetry [1] : int
        bool__en_get_main_estimator_high_resolution_telemetry [1] : int
        """
        
        pass
        
    def get_en_get_raw_gyr_sensor_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_2::en_get_raw_gyr_sensor_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_raw_rwl_sensor_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_2::en_get_raw_rwl_sensor_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_calibrated_css_sensor_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_2::en_get_calibrated_css_sensor_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_calibrated_gyr_sensor_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_2::en_get_calibrated_gyr_sensor_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_calibrated_str_sensor_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_2::en_get_calibrated_str_sensor_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_calibrated_rwl_sensor_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_2::en_get_calibrated_rwl_sensor_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_main_estimator_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_2::en_get_main_estimator_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_main_estimator_high_resolution_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_2::en_get_main_estimator_high_resolution_telemetry' structure field
        
        """
        
        pass

def telemetry_mask_2_make_from_buf(buf : bytes) -> telemetry_mask_2:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class CompErrCodes:
    """
    A Python class to represent struct objects of type 'CompErrCodes'
    
    Component Error Codes
    """

    def __init__(self, uint32__MasterSvc : int, uint32__FramFsSvc : int, uint32__EventLogSvc : int, uint32__ImgLogSvc : int, uint32__TlmLogSvc : int, uint32__ImuSvc : int) -> None:
        """
        Struct 'CompErrCodes' constructor
        
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
        A getter for the 'CompErrCodes::MasterSvc' structure field
        
        Tctlm comms master service error code (node comms)
        """
        
        pass
    
    def get_FramFsSvc(self) -> int:
        """
        A getter for the 'CompErrCodes::FramFsSvc' structure field
        
        FRAM file system error code.
        """
        
        pass
    
    def get_EventLogSvc(self) -> int:
        """
        A getter for the 'CompErrCodes::EventLogSvc' structure field
        
        Event log service error code.
        """
        
        pass
    
    def get_ImgLogSvc(self) -> int:
        """
        A getter for the 'CompErrCodes::ImgLogSvc' structure field
        
        Image log service error code.
        """
        
        pass
    
    def get_TlmLogSvc(self) -> int:
        """
        A getter for the 'CompErrCodes::TlmLogSvc' structure field
        
        Telemetry log service error code.
        """
        
        pass
    
    def get_ImuSvc(self) -> int:
        """
        A getter for the 'CompErrCodes::ImuSvc' structure field
        
        IMU/Gyro service error code.
        """
        
        pass

def CompErrCodes_make_from_buf(buf : bytes) -> CompErrCodes:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class telemetry_mask_1:
    """
    A Python class to represent struct objects of type 'telemetry_mask_1'
    
    Telemetry mask 1 of loggable frames - Check CubeSpace documentation for further information
    """

    def __init__(self, bool__en_get_models_telemetry : int, bool__en_get_calibrated_gnss_sensor_telemetry : int, bool__en_get_calibrated_hss_sensor_telemetry : int, bool__en_get_calibrated_mag_sensor_telemetry : int, bool__en_get_calibrated_fss_sensor_telemetry : int, bool__en_get_raw_cubesense_earth_telemetry : int, bool__en_get_raw_mag_sensor_telemetry : int, bool__en_get_raw_css_sensor_telemetry : int) -> None:
        """
        Struct 'telemetry_mask_1' constructor
        
        Attributes
        ---------
        bool__en_get_models_telemetry [1] : int
        bool__en_get_calibrated_gnss_sensor_telemetry [1] : int
        bool__en_get_calibrated_hss_sensor_telemetry [1] : int
        bool__en_get_calibrated_mag_sensor_telemetry [1] : int
        bool__en_get_calibrated_fss_sensor_telemetry [1] : int
        bool__en_get_raw_cubesense_earth_telemetry [1] : int
        bool__en_get_raw_mag_sensor_telemetry [1] : int
        bool__en_get_raw_css_sensor_telemetry [1] : int
        """
        
        pass
        
    def get_en_get_models_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_1::en_get_models_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_calibrated_gnss_sensor_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_1::en_get_calibrated_gnss_sensor_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_calibrated_hss_sensor_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_1::en_get_calibrated_hss_sensor_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_calibrated_mag_sensor_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_1::en_get_calibrated_mag_sensor_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_calibrated_fss_sensor_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_1::en_get_calibrated_fss_sensor_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_raw_cubesense_earth_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_1::en_get_raw_cubesense_earth_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_raw_mag_sensor_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_1::en_get_raw_mag_sensor_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_raw_css_sensor_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_1::en_get_raw_css_sensor_telemetry' structure field
        
        """
        
        pass

def telemetry_mask_1_make_from_buf(buf : bytes) -> telemetry_mask_1:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class telemetry_mask_4:
    """
    A Python class to represent struct objects of type 'telemetry_mask_4'
    
    Telemetry mask 4 of loggable frames - Check CubeSpace documentation for further information
    """

    def __init__(self, bool__en_get_health_telemetry_for_cubestar : int, bool__reserved_0 : int, bool__reserved_1 : int, bool__reserved_2 : int, bool__reserved_3 : int, bool__reserved_4 : int, bool__reserved_5 : int, bool__reserved_6 : int) -> None:
        """
        Struct 'telemetry_mask_4' constructor
        
        Attributes
        ---------
        bool__en_get_health_telemetry_for_cubestar [1] : int
        bool__reserved_0 [1] : int
        bool__reserved_1 [1] : int
        bool__reserved_2 [1] : int
        bool__reserved_3 [1] : int
        bool__reserved_4 [1] : int
        bool__reserved_5 [1] : int
        bool__reserved_6 [1] : int
        """
        
        pass
        
    def get_en_get_health_telemetry_for_cubestar(self) -> int:
        """
        A getter for the 'telemetry_mask_4::en_get_health_telemetry_for_cubestar' structure field
        
        """
        
        pass
    
    def get_reserved_0(self) -> int:
        """
        A getter for the 'telemetry_mask_4::reserved_0' structure field
        
        """
        
        pass
    
    def get_reserved_1(self) -> int:
        """
        A getter for the 'telemetry_mask_4::reserved_1' structure field
        
        """
        
        pass
    
    def get_reserved_2(self) -> int:
        """
        A getter for the 'telemetry_mask_4::reserved_2' structure field
        
        """
        
        pass
    
    def get_reserved_3(self) -> int:
        """
        A getter for the 'telemetry_mask_4::reserved_3' structure field
        
        """
        
        pass
    
    def get_reserved_4(self) -> int:
        """
        A getter for the 'telemetry_mask_4::reserved_4' structure field
        
        """
        
        pass
    
    def get_reserved_5(self) -> int:
        """
        A getter for the 'telemetry_mask_4::reserved_5' structure field
        
        """
        
        pass
    
    def get_reserved_6(self) -> int:
        """
        A getter for the 'telemetry_mask_4::reserved_6' structure field
        
        """
        
        pass

def telemetry_mask_4_make_from_buf(buf : bytes) -> telemetry_mask_4:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class telemetry_mask_3:
    """
    A Python class to represent struct objects of type 'telemetry_mask_3'
    
    Telemetry mask 3 of loggable frames - Check CubeSpace documentation for further information
    """

    def __init__(self, bool__en_get_raw_gnss_sensor_telemetry : int, bool__en_get_raw_pst3s_star_tracker_telemetry : int, bool__en_get_acp_execution_telemetry : int, bool__en_get_cubecomputer_health : int, bool__en_get_health_telemetry_for_cubesense_earth : int, bool__en_get_health_telemetry_for_reaction_wheels : int, bool__en_get_health_telemetry_for_cubenode_nssrwl : int, bool__en_get_raw_nssrwl_sensor_telemetry : int) -> None:
        """
        Struct 'telemetry_mask_3' constructor
        
        Attributes
        ---------
        bool__en_get_raw_gnss_sensor_telemetry [1] : int
        bool__en_get_raw_pst3s_star_tracker_telemetry [1] : int
        bool__en_get_acp_execution_telemetry [1] : int
        bool__en_get_cubecomputer_health [1] : int
        bool__en_get_health_telemetry_for_cubesense_earth [1] : int
        bool__en_get_health_telemetry_for_reaction_wheels [1] : int
        bool__en_get_health_telemetry_for_cubenode_nssrwl [1] : int
        bool__en_get_raw_nssrwl_sensor_telemetry [1] : int
        """
        
        pass
        
    def get_en_get_raw_gnss_sensor_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_3::en_get_raw_gnss_sensor_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_raw_pst3s_star_tracker_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_3::en_get_raw_pst3s_star_tracker_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_acp_execution_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_3::en_get_acp_execution_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_cubecomputer_health(self) -> int:
        """
        A getter for the 'telemetry_mask_3::en_get_cubecomputer_health' structure field
        
        """
        
        pass
    
    def get_en_get_health_telemetry_for_cubesense_earth(self) -> int:
        """
        A getter for the 'telemetry_mask_3::en_get_health_telemetry_for_cubesense_earth' structure field
        
        """
        
        pass
    
    def get_en_get_health_telemetry_for_reaction_wheels(self) -> int:
        """
        A getter for the 'telemetry_mask_3::en_get_health_telemetry_for_reaction_wheels' structure field
        
        """
        
        pass
    
    def get_en_get_health_telemetry_for_cubenode_nssrwl(self) -> int:
        """
        A getter for the 'telemetry_mask_3::en_get_health_telemetry_for_cubenode_nssrwl' structure field
        
        """
        
        pass
    
    def get_en_get_raw_nssrwl_sensor_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_3::en_get_raw_nssrwl_sensor_telemetry' structure field
        
        """
        
        pass

def telemetry_mask_3_make_from_buf(buf : bytes) -> telemetry_mask_3:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class telemetry_mask_0:
    """
    A Python class to represent struct objects of type 'telemetry_mask_0'
    
    Telemetry mask 0 of loggable frames - Check CubeSpace documentation for further information
    """

    def __init__(self, bool__en_get_health_tlm_for_cubenode_pst3s : int, bool__en_get_health_tlm_for_cubemag_magnetometer : int, bool__en_get_health_tlm_for_cubesense_sun : int, bool__en_get_torquer_current_measurements : int, bool__en_get_raw_cubesense_sun_telemetry : int, bool__en_get_raw_external_sensor_telemetry : int, bool__en_get_controller_telemetry : int, bool__en_get_backup_estimator_telemetry : int) -> None:
        """
        Struct 'telemetry_mask_0' constructor
        
        Attributes
        ---------
        bool__en_get_health_tlm_for_cubenode_pst3s [1] : int
        bool__en_get_health_tlm_for_cubemag_magnetometer [1] : int
        bool__en_get_health_tlm_for_cubesense_sun [1] : int
        bool__en_get_torquer_current_measurements [1] : int
        bool__en_get_raw_cubesense_sun_telemetry [1] : int
        bool__en_get_raw_external_sensor_telemetry [1] : int
        bool__en_get_controller_telemetry [1] : int
        bool__en_get_backup_estimator_telemetry [1] : int
        """
        
        pass
        
    def get_en_get_health_tlm_for_cubenode_pst3s(self) -> int:
        """
        A getter for the 'telemetry_mask_0::en_get_health_tlm_for_cubenode_pst3s' structure field
        
        """
        
        pass
    
    def get_en_get_health_tlm_for_cubemag_magnetometer(self) -> int:
        """
        A getter for the 'telemetry_mask_0::en_get_health_tlm_for_cubemag_magnetometer' structure field
        
        """
        
        pass
    
    def get_en_get_health_tlm_for_cubesense_sun(self) -> int:
        """
        A getter for the 'telemetry_mask_0::en_get_health_tlm_for_cubesense_sun' structure field
        
        """
        
        pass
    
    def get_en_get_torquer_current_measurements(self) -> int:
        """
        A getter for the 'telemetry_mask_0::en_get_torquer_current_measurements' structure field
        
        """
        
        pass
    
    def get_en_get_raw_cubesense_sun_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_0::en_get_raw_cubesense_sun_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_raw_external_sensor_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_0::en_get_raw_external_sensor_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_controller_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_0::en_get_controller_telemetry' structure field
        
        """
        
        pass
    
    def get_en_get_backup_estimator_telemetry(self) -> int:
        """
        A getter for the 'telemetry_mask_0::en_get_backup_estimator_telemetry' structure field
        
        """
        
        pass

def telemetry_mask_0_make_from_buf(buf : bytes) -> telemetry_mask_0:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class events:
    """
    A Python class to represent struct objects of type 'events'
    
    Events counters for major and critical events.
    """

    def __init__(self, uint16__node_comm_error : int, uint16__adcs_config_validation_error : int, uint16__node_setup_error : int, uint16__node_jump_error : int, uint16__mag_deploy_error : int, uint16__control_loop_failure : int, uint16__node_failure : int, uint16__config_persist_error : int, uint16__virtual_watchdog_warning : int, uint16__port_validation_error : int, uint16__auto_discovery_error : int, uint16__control_loop_critical : int, uint16__gyro_voltage_error : int, uint16__gyro_critical : int, uint16__virtual_watchdog_error : int) -> None:
        """
        Struct 'events' constructor
        
        Attributes
        ---------
        uint16__node_comm_error [1] : int
        uint16__adcs_config_validation_error [1] : int
        uint16__node_setup_error [1] : int
        uint16__node_jump_error [1] : int
        uint16__mag_deploy_error [1] : int
        uint16__control_loop_failure [1] : int
        uint16__node_failure [1] : int
        uint16__config_persist_error [1] : int
        uint16__virtual_watchdog_warning [1] : int
        uint16__port_validation_error [1] : int
        uint16__auto_discovery_error [1] : int
        uint16__control_loop_critical [1] : int
        uint16__gyro_voltage_error [1] : int
        uint16__gyro_critical [1] : int
        uint16__virtual_watchdog_error [1] : int
        """
        
        pass
        
    def get_node_comm_error(self) -> int:
        """
        A getter for the 'events::node_comm_error' structure field
        
        """
        
        pass
    
    def get_adcs_config_validation_error(self) -> int:
        """
        A getter for the 'events::adcs_config_validation_error' structure field
        
        """
        
        pass
    
    def get_node_setup_error(self) -> int:
        """
        A getter for the 'events::node_setup_error' structure field
        
        """
        
        pass
    
    def get_node_jump_error(self) -> int:
        """
        A getter for the 'events::node_jump_error' structure field
        
        """
        
        pass
    
    def get_mag_deploy_error(self) -> int:
        """
        A getter for the 'events::mag_deploy_error' structure field
        
        """
        
        pass
    
    def get_control_loop_failure(self) -> int:
        """
        A getter for the 'events::control_loop_failure' structure field
        
        """
        
        pass
    
    def get_node_failure(self) -> int:
        """
        A getter for the 'events::node_failure' structure field
        
        """
        
        pass
    
    def get_config_persist_error(self) -> int:
        """
        A getter for the 'events::config_persist_error' structure field
        
        """
        
        pass
    
    def get_virtual_watchdog_warning(self) -> int:
        """
        A getter for the 'events::virtual_watchdog_warning' structure field
        
        """
        
        pass
    
    def get_port_validation_error(self) -> int:
        """
        A getter for the 'events::port_validation_error' structure field
        
        """
        
        pass
    
    def get_auto_discovery_error(self) -> int:
        """
        A getter for the 'events::auto_discovery_error' structure field
        
        """
        
        pass
    
    def get_control_loop_critical(self) -> int:
        """
        A getter for the 'events::control_loop_critical' structure field
        
        """
        
        pass
    
    def get_gyro_voltage_error(self) -> int:
        """
        A getter for the 'events::gyro_voltage_error' structure field
        
        """
        
        pass
    
    def get_gyro_critical(self) -> int:
        """
        A getter for the 'events::gyro_critical' structure field
        
        """
        
        pass
    
    def get_virtual_watchdog_error(self) -> int:
        """
        A getter for the 'events::virtual_watchdog_error' structure field
        
        """
        
        pass

def events_make_from_buf(buf : bytes) -> events:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TctlmCubeCommonBaseBootloader5_Errors:
    """
    A Python class to represent struct objects of type 'TctlmCubeCommonBaseBootloader5_Errors'
    
    Errors message structure. Error information of the application
    """

    def __init__(self, uint32__result : int, uint32__halInit : int, uint32__flashInit : int, uint32__uart1Init : int, uint32__uart2Init : int, uint32__can1Init : int, uint32__can2Init : int, uint32__i2cInit : int, bool__configInit : int, bool__timeout : int, bool__overrun : int, bool__erasePage : int, bool__write : int, bool__fileCrc : int, bool__commitFileTable : int, bool__commitConfigTable : int, bool__jumpTarget : int) -> None:
        """
        Struct 'TctlmCubeCommonBaseBootloader5_Errors' constructor
        
        Attributes
        ---------
        uint32__result [1] : int
            Error code for the last operation - gets reset to 0 at start of new operation
        uint32__halInit [1] : int
            Error code for HAL initialization (0 = OK)
        uint32__flashInit [1] : int
            Error code for Flash initialization (0 = OK)
        uint32__uart1Init [1] : int
            Error code for UART1 initialization (0 = OK)
        uint32__uart2Init [1] : int
            Error code for UART2 initialization (0 = OK)
        uint32__can1Init [1] : int
            Error code for CAN1 initialization (0 = OK)
        uint32__can2Init [1] : int
            Error code for CAN2 initialization (0 = OK)
        uint32__i2cInit [1] : int
            Error code for I2C initialization (0 = OK)
        bool__configInit [1] : int
            Config error flag set if configuration CRC failed and default config is being used
        bool__timeout [1] : int
            Timeout error flag on last operation
        bool__overrun [1] : int
            Data overrun error flag on last operation
        bool__erasePage [1] : int
            Page erase error flag on last operation
        bool__write [1] : int
            Write error flag on last operation
        bool__fileCrc [1] : int
            File CRC error flag on upload complete
        bool__commitFileTable [1] : int
            Set if failure to write file table to flash
        bool__commitConfigTable [1] : int
            Set if failure to write config table to flash
        bool__jumpTarget [1] : int
            Set if the jump target is invalid
        """
        
        pass
        
    def get_result(self) -> int:
        """
        A getter for the 'TctlmCubeCommonBaseBootloader5_Errors::result' structure field
        
        Error code for the last operation - gets reset to 0 at start of new operation
        """
        
        pass
    
    def get_halInit(self) -> int:
        """
        A getter for the 'TctlmCubeCommonBaseBootloader5_Errors::halInit' structure field
        
        Error code for HAL initialization (0 = OK)
        """
        
        pass
    
    def get_flashInit(self) -> int:
        """
        A getter for the 'TctlmCubeCommonBaseBootloader5_Errors::flashInit' structure field
        
        Error code for Flash initialization (0 = OK)
        """
        
        pass
    
    def get_uart1Init(self) -> int:
        """
        A getter for the 'TctlmCubeCommonBaseBootloader5_Errors::uart1Init' structure field
        
        Error code for UART1 initialization (0 = OK)
        """
        
        pass
    
    def get_uart2Init(self) -> int:
        """
        A getter for the 'TctlmCubeCommonBaseBootloader5_Errors::uart2Init' structure field
        
        Error code for UART2 initialization (0 = OK)
        """
        
        pass
    
    def get_can1Init(self) -> int:
        """
        A getter for the 'TctlmCubeCommonBaseBootloader5_Errors::can1Init' structure field
        
        Error code for CAN1 initialization (0 = OK)
        """
        
        pass
    
    def get_can2Init(self) -> int:
        """
        A getter for the 'TctlmCubeCommonBaseBootloader5_Errors::can2Init' structure field
        
        Error code for CAN2 initialization (0 = OK)
        """
        
        pass
    
    def get_i2cInit(self) -> int:
        """
        A getter for the 'TctlmCubeCommonBaseBootloader5_Errors::i2cInit' structure field
        
        Error code for I2C initialization (0 = OK)
        """
        
        pass
    
    def get_configInit(self) -> int:
        """
        A getter for the 'TctlmCubeCommonBaseBootloader5_Errors::configInit' structure field
        
        Config error flag set if configuration CRC failed and default config is being used
        """
        
        pass
    
    def get_timeout(self) -> int:
        """
        A getter for the 'TctlmCubeCommonBaseBootloader5_Errors::timeout' structure field
        
        Timeout error flag on last operation
        """
        
        pass
    
    def get_overrun(self) -> int:
        """
        A getter for the 'TctlmCubeCommonBaseBootloader5_Errors::overrun' structure field
        
        Data overrun error flag on last operation
        """
        
        pass
    
    def get_erasePage(self) -> int:
        """
        A getter for the 'TctlmCubeCommonBaseBootloader5_Errors::erasePage' structure field
        
        Page erase error flag on last operation
        """
        
        pass
    
    def get_write(self) -> int:
        """
        A getter for the 'TctlmCubeCommonBaseBootloader5_Errors::write' structure field
        
        Write error flag on last operation
        """
        
        pass
    
    def get_fileCrc(self) -> int:
        """
        A getter for the 'TctlmCubeCommonBaseBootloader5_Errors::fileCrc' structure field
        
        File CRC error flag on upload complete
        """
        
        pass
    
    def get_commitFileTable(self) -> int:
        """
        A getter for the 'TctlmCubeCommonBaseBootloader5_Errors::commitFileTable' structure field
        
        Set if failure to write file table to flash
        """
        
        pass
    
    def get_commitConfigTable(self) -> int:
        """
        A getter for the 'TctlmCubeCommonBaseBootloader5_Errors::commitConfigTable' structure field
        
        Set if failure to write config table to flash
        """
        
        pass
    
    def get_jumpTarget(self) -> int:
        """
        A getter for the 'TctlmCubeCommonBaseBootloader5_Errors::jumpTarget' structure field
        
        Set if the jump target is invalid
        """
        
        pass

def TctlmCubeCommonBaseBootloader5_Errors_make_from_buf(buf : bytes) -> TctlmCubeCommonBaseBootloader5_Errors:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class RefParams:
    """
    A Python class to represent struct objects of type 'RefParams'
    
    Reference parameters for some control modes
    """

    def __init__(self, float__ref_param1 : float, float__ref_param2 : float, float__ref_param3 : float) -> None:
        """
        Struct 'RefParams' constructor
        
        Attributes
        ---------
        float__ref_param1 [1] : float
            Roll, Latitude or X component of an ECI pointing vector
        float__ref_param2 [1] : float
            Pitch, Longitude or Y component of an ECI pointing vector
        float__ref_param3 [1] : float
            Yaw, Altitude or Z component of an ECI pointing vector
        """
        
        pass
        
    def get_ref_param1(self) -> float:
        """
        A getter for the 'RefParams::ref_param1' structure field
        
        Roll, Latitude or X component of an ECI pointing vector
        """
        
        pass
    
    def get_ref_param2(self) -> float:
        """
        A getter for the 'RefParams::ref_param2' structure field
        
        Pitch, Longitude or Y component of an ECI pointing vector
        """
        
        pass
    
    def get_ref_param3(self) -> float:
        """
        A getter for the 'RefParams::ref_param3' structure field
        
        Yaw, Altitude or Z component of an ECI pointing vector
        """
        
        pass

def RefParams_make_from_buf(buf : bytes) -> RefParams:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class fdir_stat:
    """
    A Python class to represent struct objects of type 'fdir_stat'
    
    FDIR stats
    """

    def __init__(self, e__events_enum__event_type : events_enum, uint8__event_fdir_execution_num : int, a__bool__1__event_fdir_execution_res : list[int]) -> None:
        """
        Struct 'fdir_stat' constructor
        
        Attributes
        ---------
        e__events_enum__event_type [1] : events_enum
            Event type that triggers the FDIR logic
        uint8__event_fdir_execution_num [1] : int
            Number of executions of the specific FDIR logic.
        a__bool__1__event_fdir_execution_res [1] : list[int]
            An array indicating the Success/Failure to recover from the error.
                        Each entry corresponds to one of the exectuins.
                        For example, if event_fdir_execution_num == 2, the array will have two entries indicating the result of the first and second executions respectively.
        """
        
        pass
        
    def get_event_type(self) -> events_enum:
        """
        A getter for the 'fdir_stat::event_type' structure field
        
        Event type that triggers the FDIR logic
        """
        
        pass
    
    def get_event_fdir_execution_num(self) -> int:
        """
        A getter for the 'fdir_stat::event_fdir_execution_num' structure field
        
        Number of executions of the specific FDIR logic.
        """
        
        pass
    
    def get_event_fdir_execution_res(self) -> list[int]:
        """
        A getter for the 'fdir_stat::event_fdir_execution_res' structure field
        
        An array indicating the Success/Failure to recover from the error.
                    Each entry corresponds to one of the exectuins.
                    For example, if event_fdir_execution_num == 2, the array will have two entries indicating the result of the first and second executions respectively.
        """
        
        pass

def fdir_stat_make_from_buf(buf : bytes) -> fdir_stat:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class PowerState:
    """
    A Python class to represent struct objects of type 'PowerState'
    
    Power state of all nodes
    """

    def __init__(self, e__NodePowerState__rwl0 : NodePowerState, e__NodePowerState__rwl1 : NodePowerState, e__NodePowerState__rwl2 : NodePowerState, e__NodePowerState__rwl3 : NodePowerState, e__NodePowerState__mag0 : NodePowerState, e__NodePowerState__mag1 : NodePowerState, e__NodePowerState__gyro0 : NodePowerState, e__NodePowerState__gyro1 : NodePowerState, e__NodePowerState__fss0 : NodePowerState, e__NodePowerState__fss1 : NodePowerState, e__NodePowerState__fss2 : NodePowerState, e__NodePowerState__fss3 : NodePowerState, e__NodePowerState__hss0 : NodePowerState, e__NodePowerState__hss1 : NodePowerState, e__NodePowerState__str0 : NodePowerState, e__NodePowerState__str1 : NodePowerState, e__NodePowerState__extSensor0 : NodePowerState, e__NodePowerState__extSensor1 : NodePowerState, e__NodePowerState__extGyro0 : NodePowerState, e__NodePowerState__extGyro1 : NodePowerState) -> None:
        """
        Struct 'PowerState' constructor
        
        Attributes
        ---------
        e__NodePowerState__rwl0 [1] : NodePowerState
            RWheel 0
        e__NodePowerState__rwl1 [1] : NodePowerState
            RWheel 1
        e__NodePowerState__rwl2 [1] : NodePowerState
            RWheel 2
        e__NodePowerState__rwl3 [1] : NodePowerState
            RWheel 3
        e__NodePowerState__mag0 [1] : NodePowerState
            Magnetometer 0
        e__NodePowerState__mag1 [1] : NodePowerState
            Magnetometer 1
        e__NodePowerState__gyro0 [1] : NodePowerState
            Gyro 0
        e__NodePowerState__gyro1 [1] : NodePowerState
            Gyro 1
        e__NodePowerState__fss0 [1] : NodePowerState
            Fine Sun Sensor 0
        e__NodePowerState__fss1 [1] : NodePowerState
            Fine Sun Sensor 1
        e__NodePowerState__fss2 [1] : NodePowerState
            Fine Sun Sensor 2
        e__NodePowerState__fss3 [1] : NodePowerState
            Fine Sun Sensor 3
        e__NodePowerState__hss0 [1] : NodePowerState
            Horizon Sensor 0
        e__NodePowerState__hss1 [1] : NodePowerState
            Horizon Sensor 1
        e__NodePowerState__str0 [1] : NodePowerState
            Star Tracker 0
        e__NodePowerState__str1 [1] : NodePowerState
            Star Tracker 1
        e__NodePowerState__extSensor0 [1] : NodePowerState
            External Sensor 0
        e__NodePowerState__extSensor1 [1] : NodePowerState
            External Sensor 1
        e__NodePowerState__extGyro0 [1] : NodePowerState
            EXTGYR0 power state
        e__NodePowerState__extGyro1 [1] : NodePowerState
            EXTGYR1 power state
        """
        
        pass
        
    def get_rwl0(self) -> NodePowerState:
        """
        A getter for the 'PowerState::rwl0' structure field
        
        RWheel 0
        """
        
        pass
    
    def get_rwl1(self) -> NodePowerState:
        """
        A getter for the 'PowerState::rwl1' structure field
        
        RWheel 1
        """
        
        pass
    
    def get_rwl2(self) -> NodePowerState:
        """
        A getter for the 'PowerState::rwl2' structure field
        
        RWheel 2
        """
        
        pass
    
    def get_rwl3(self) -> NodePowerState:
        """
        A getter for the 'PowerState::rwl3' structure field
        
        RWheel 3
        """
        
        pass
    
    def get_mag0(self) -> NodePowerState:
        """
        A getter for the 'PowerState::mag0' structure field
        
        Magnetometer 0
        """
        
        pass
    
    def get_mag1(self) -> NodePowerState:
        """
        A getter for the 'PowerState::mag1' structure field
        
        Magnetometer 1
        """
        
        pass
    
    def get_gyro0(self) -> NodePowerState:
        """
        A getter for the 'PowerState::gyro0' structure field
        
        Gyro 0
        """
        
        pass
    
    def get_gyro1(self) -> NodePowerState:
        """
        A getter for the 'PowerState::gyro1' structure field
        
        Gyro 1
        """
        
        pass
    
    def get_fss0(self) -> NodePowerState:
        """
        A getter for the 'PowerState::fss0' structure field
        
        Fine Sun Sensor 0
        """
        
        pass
    
    def get_fss1(self) -> NodePowerState:
        """
        A getter for the 'PowerState::fss1' structure field
        
        Fine Sun Sensor 1
        """
        
        pass
    
    def get_fss2(self) -> NodePowerState:
        """
        A getter for the 'PowerState::fss2' structure field
        
        Fine Sun Sensor 2
        """
        
        pass
    
    def get_fss3(self) -> NodePowerState:
        """
        A getter for the 'PowerState::fss3' structure field
        
        Fine Sun Sensor 3
        """
        
        pass
    
    def get_hss0(self) -> NodePowerState:
        """
        A getter for the 'PowerState::hss0' structure field
        
        Horizon Sensor 0
        """
        
        pass
    
    def get_hss1(self) -> NodePowerState:
        """
        A getter for the 'PowerState::hss1' structure field
        
        Horizon Sensor 1
        """
        
        pass
    
    def get_str0(self) -> NodePowerState:
        """
        A getter for the 'PowerState::str0' structure field
        
        Star Tracker 0
        """
        
        pass
    
    def get_str1(self) -> NodePowerState:
        """
        A getter for the 'PowerState::str1' structure field
        
        Star Tracker 1
        """
        
        pass
    
    def get_extSensor0(self) -> NodePowerState:
        """
        A getter for the 'PowerState::extSensor0' structure field
        
        External Sensor 0
        """
        
        pass
    
    def get_extSensor1(self) -> NodePowerState:
        """
        A getter for the 'PowerState::extSensor1' structure field
        
        External Sensor 1
        """
        
        pass
    
    def get_extGyro0(self) -> NodePowerState:
        """
        A getter for the 'PowerState::extGyro0' structure field
        
        EXTGYR0 power state
        """
        
        pass
    
    def get_extGyro1(self) -> NodePowerState:
        """
        A getter for the 'PowerState::extGyro1' structure field
        
        EXTGYR1 power state
        """
        
        pass

def PowerState_make_from_buf(buf : bytes) -> PowerState:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TctlmCubeComputerCommon3_EventLogStatus:
    """
    A Python class to represent struct objects of type 'TctlmCubeComputerCommon3_EventLogStatus'
    
    """

    def __init__(self, uint16__numberOfEntriesQueued : int, uint16__numberOfEntriesBuffered : int, uint32__numberOfEntries : int, uint32__numberOfEmptyEntries : int, uint32__oldestEntryUnix : int, uint32__latestEntryUnix : int, uint32__numberOfCriticalEvents : int, uint32__numberOfMajorWarningEvents : int, uint32__numberOfMinorWarningEvents : int, uint32__numberOfInfoEvents : int, uint32__writeCounter : int, e__TctlmCubeComputerCommon3_EventReadQueueState__readQueueState : TctlmCubeComputerCommon3_EventReadQueueState) -> None:
        """
        Struct 'TctlmCubeComputerCommon3_EventLogStatus' constructor
        
        Attributes
        ---------
        uint16__numberOfEntriesQueued [1] : int
        uint16__numberOfEntriesBuffered [1] : int
        uint32__numberOfEntries [1] : int
        uint32__numberOfEmptyEntries [1] : int
        uint32__oldestEntryUnix [1] : int
        uint32__latestEntryUnix [1] : int
        uint32__numberOfCriticalEvents [1] : int
        uint32__numberOfMajorWarningEvents [1] : int
        uint32__numberOfMinorWarningEvents [1] : int
        uint32__numberOfInfoEvents [1] : int
        uint32__writeCounter [1] : int
        e__TctlmCubeComputerCommon3_EventReadQueueState__readQueueState [1] : TctlmCubeComputerCommon3_EventReadQueueState
        """
        
        pass
        
    def get_numberOfEntriesQueued(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogStatus::numberOfEntriesQueued' structure field
        
        """
        
        pass
    
    def get_numberOfEntriesBuffered(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogStatus::numberOfEntriesBuffered' structure field
        
        """
        
        pass
    
    def get_numberOfEntries(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogStatus::numberOfEntries' structure field
        
        """
        
        pass
    
    def get_numberOfEmptyEntries(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogStatus::numberOfEmptyEntries' structure field
        
        """
        
        pass
    
    def get_oldestEntryUnix(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogStatus::oldestEntryUnix' structure field
        
        """
        
        pass
    
    def get_latestEntryUnix(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogStatus::latestEntryUnix' structure field
        
        """
        
        pass
    
    def get_numberOfCriticalEvents(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogStatus::numberOfCriticalEvents' structure field
        
        """
        
        pass
    
    def get_numberOfMajorWarningEvents(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogStatus::numberOfMajorWarningEvents' structure field
        
        """
        
        pass
    
    def get_numberOfMinorWarningEvents(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogStatus::numberOfMinorWarningEvents' structure field
        
        """
        
        pass
    
    def get_numberOfInfoEvents(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogStatus::numberOfInfoEvents' structure field
        
        """
        
        pass
    
    def get_writeCounter(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogStatus::writeCounter' structure field
        
        """
        
        pass
    
    def get_readQueueState(self) -> TctlmCubeComputerCommon3_EventReadQueueState:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogStatus::readQueueState' structure field
        
        """
        
        pass

def TctlmCubeComputerCommon3_EventLogStatus_make_from_buf(buf : bytes) -> TctlmCubeComputerCommon3_EventLogStatus:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TctlmCubeComputerCommon3_ImageTransferStatus:
    """
    A Python class to represent struct objects of type 'TctlmCubeComputerCommon3_ImageTransferStatus'
    
    """

    def __init__(self, e__TctlmCubeComputerCommon3_ImageTransferState__transfer_state : TctlmCubeComputerCommon3_ImageTransferState, uint32__errorCode : int, uint32__transferSize : int, uint32__dataRemain : int, bool__invalidNodeError : int, bool__timeoutError : int, bool__captureError : int, bool__setupError : int, bool__fileOpenReadError : int, bool__fileOpenWriteError : int, bool__fileReadError : int, bool__fileWriteError : int, bool__busyError : int) -> None:
        """
        Struct 'TctlmCubeComputerCommon3_ImageTransferStatus' constructor
        
        Attributes
        ---------
        e__TctlmCubeComputerCommon3_ImageTransferState__transfer_state [1] : TctlmCubeComputerCommon3_ImageTransferState
        uint32__errorCode [1] : int
        uint32__transferSize [1] : int
        uint32__dataRemain [1] : int
        bool__invalidNodeError [1] : int
        bool__timeoutError [1] : int
        bool__captureError [1] : int
        bool__setupError [1] : int
        bool__fileOpenReadError [1] : int
        bool__fileOpenWriteError [1] : int
        bool__fileReadError [1] : int
        bool__fileWriteError [1] : int
        bool__busyError [1] : int
        """
        
        pass
        
    def get_transfer_state(self) -> TctlmCubeComputerCommon3_ImageTransferState:
        """
        A getter for the 'TctlmCubeComputerCommon3_ImageTransferStatus::transfer_state' structure field
        
        """
        
        pass
    
    def get_errorCode(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_ImageTransferStatus::errorCode' structure field
        
        """
        
        pass
    
    def get_transferSize(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_ImageTransferStatus::transferSize' structure field
        
        """
        
        pass
    
    def get_dataRemain(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_ImageTransferStatus::dataRemain' structure field
        
        """
        
        pass
    
    def get_invalidNodeError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_ImageTransferStatus::invalidNodeError' structure field
        
        """
        
        pass
    
    def get_timeoutError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_ImageTransferStatus::timeoutError' structure field
        
        """
        
        pass
    
    def get_captureError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_ImageTransferStatus::captureError' structure field
        
        """
        
        pass
    
    def get_setupError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_ImageTransferStatus::setupError' structure field
        
        """
        
        pass
    
    def get_fileOpenReadError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_ImageTransferStatus::fileOpenReadError' structure field
        
        """
        
        pass
    
    def get_fileOpenWriteError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_ImageTransferStatus::fileOpenWriteError' structure field
        
        """
        
        pass
    
    def get_fileReadError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_ImageTransferStatus::fileReadError' structure field
        
        """
        
        pass
    
    def get_fileWriteError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_ImageTransferStatus::fileWriteError' structure field
        
        """
        
        pass
    
    def get_busyError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_ImageTransferStatus::busyError' structure field
        
        """
        
        pass

def TctlmCubeComputerCommon3_ImageTransferStatus_make_from_buf(buf : bytes) -> TctlmCubeComputerCommon3_ImageTransferStatus:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class EstModeConfig:
    """
    A Python class to represent struct objects of type 'EstModeConfig'
    
    Estimation mode configuration
    """

    def __init__(self, e__EstimationModes__main : EstimationModes, e__EstimationModes__backup : EstimationModes) -> None:
        """
        Struct 'EstModeConfig' constructor
        
        Attributes
        ---------
        e__EstimationModes__main [1] : EstimationModes
            Main estimation mode
        e__EstimationModes__backup [1] : EstimationModes
            Backup estimation mode
        """
        
        pass
        
    def get_main(self) -> EstimationModes:
        """
        A getter for the 'EstModeConfig::main' structure field
        
        Main estimation mode
        """
        
        pass
    
    def get_backup(self) -> EstimationModes:
        """
        A getter for the 'EstModeConfig::backup' structure field
        
        Backup estimation mode
        """
        
        pass

def EstModeConfig_make_from_buf(buf : bytes) -> EstModeConfig:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class cube_computer_fw_update_status:
    """
    A Python class to represent struct objects of type 'cube_computer_fw_update_status'
    
    cube computer control program update status
    """

    def __init__(self, t__int32__err_code : int, bool__force : int, s__status : TctlmCubeCommonBaseBootloader5_Errors, s__control_program_file_name : FName, s__configuration_file_name : FName) -> None:
        """
        Struct 'cube_computer_fw_update_status' constructor
        
        Attributes
        ---------
        t__int32__err_code [1] : int
        bool__force [1] : int
        s__status [1] : TctlmCubeCommonBaseBootloader5_Errors
        s__control_program_file_name [1] : FName
        s__configuration_file_name [1] : FName
        """
        
        pass
        
    def get_err_code(self) -> int:
        """
        A getter for the 'cube_computer_fw_update_status::err_code' structure field
        
        """
        
        pass
    
    def get_force(self) -> int:
        """
        A getter for the 'cube_computer_fw_update_status::force' structure field
        
        """
        
        pass
    
    def get_status(self) -> TctlmCubeCommonBaseBootloader5_Errors:
        """
        A getter for the 'cube_computer_fw_update_status::status' structure field
        
        """
        
        pass
    
    def get_control_program_file_name(self) -> FName:
        """
        A getter for the 'cube_computer_fw_update_status::control_program_file_name' structure field
        
        """
        
        pass
    
    def get_configuration_file_name(self) -> FName:
        """
        A getter for the 'cube_computer_fw_update_status::configuration_file_name' structure field
        
        """
        
        pass

def cube_computer_fw_update_status_make_from_buf(buf : bytes) -> cube_computer_fw_update_status:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TctlmCubeComputerCommon3_TelemtryLogStatus:
    """
    A Python class to represent struct objects of type 'TctlmCubeComputerCommon3_TelemtryLogStatus'
    
    """

    def __init__(self, uint8__numberOfEntriesQueued : int, uint8__numberOfTlmIterations : int, uint32__numberOfEntries : int, uint32__oldestEntryUnix : int, uint32__latestEntryUnix : int, uint32__writeCounter : int, e__TctlmCubeComputerCommon3_TlmLogReadQueueState__readQueueState : TctlmCubeComputerCommon3_TlmLogReadQueueState) -> None:
        """
        Struct 'TctlmCubeComputerCommon3_TelemtryLogStatus' constructor
        
        Attributes
        ---------
        uint8__numberOfEntriesQueued [1] : int
        uint8__numberOfTlmIterations [1] : int
        uint32__numberOfEntries [1] : int
        uint32__oldestEntryUnix [1] : int
        uint32__latestEntryUnix [1] : int
        uint32__writeCounter [1] : int
        e__TctlmCubeComputerCommon3_TlmLogReadQueueState__readQueueState [1] : TctlmCubeComputerCommon3_TlmLogReadQueueState
        """
        
        pass
        
    def get_numberOfEntriesQueued(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_TelemtryLogStatus::numberOfEntriesQueued' structure field
        
        """
        
        pass
    
    def get_numberOfTlmIterations(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_TelemtryLogStatus::numberOfTlmIterations' structure field
        
        """
        
        pass
    
    def get_numberOfEntries(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_TelemtryLogStatus::numberOfEntries' structure field
        
        """
        
        pass
    
    def get_oldestEntryUnix(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_TelemtryLogStatus::oldestEntryUnix' structure field
        
        """
        
        pass
    
    def get_latestEntryUnix(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_TelemtryLogStatus::latestEntryUnix' structure field
        
        """
        
        pass
    
    def get_writeCounter(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_TelemtryLogStatus::writeCounter' structure field
        
        """
        
        pass
    
    def get_readQueueState(self) -> TctlmCubeComputerCommon3_TlmLogReadQueueState:
        """
        A getter for the 'TctlmCubeComputerCommon3_TelemtryLogStatus::readQueueState' structure field
        
        """
        
        pass

def TctlmCubeComputerCommon3_TelemtryLogStatus_make_from_buf(buf : bytes) -> TctlmCubeComputerCommon3_TelemtryLogStatus:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class BootStatus:
    """
    A Python class to represent struct objects of type 'BootStatus'
    
    Boot status
    """

    def __init__(self, e__BootState__State : BootState, e__BootResetReason__ResetReason : BootResetReason, bool__SharedParamsError : int, bool__PortValidationError : int, bool__PortDiscoveryError : int, bool__OtpSerialError : int, bool__CfgSerialError : int, bool__SerialMismatchError : int, bool__ConfigInvalidError : int) -> None:
        """
        Struct 'BootStatus' constructor
        
        Attributes
        ---------
        e__BootState__State [1] : BootState
            Boot State
        e__BootResetReason__ResetReason [1] : BootResetReason
            Cause of the last reset
        bool__SharedParamsError [1] : int
            CRC check of shared parameters from bootloader failed - app will use its own config values
        bool__PortValidationError [1] : int
            Port validation failed. Only applicable to CubeComputer.
        bool__PortDiscoveryError [1] : int
            Auto-Discovery failed. Only applicable to CubeComputer.
        bool__OtpSerialError [1] : int
            OTP serial number is invalid
        bool__CfgSerialError [1] : int
            Config serial number is invalid
        bool__SerialMismatchError [1] : int
            OTP/Config serial numbers do not match
        bool__ConfigInvalidError [1] : int
            Set if the applications config is invalid and the default configuration is being used (if available).
        """
        
        pass
        
    def get_State(self) -> BootState:
        """
        A getter for the 'BootStatus::State' structure field
        
        Boot State
        """
        
        pass
    
    def get_ResetReason(self) -> BootResetReason:
        """
        A getter for the 'BootStatus::ResetReason' structure field
        
        Cause of the last reset
        """
        
        pass
    
    def get_SharedParamsError(self) -> int:
        """
        A getter for the 'BootStatus::SharedParamsError' structure field
        
        CRC check of shared parameters from bootloader failed - app will use its own config values
        """
        
        pass
    
    def get_PortValidationError(self) -> int:
        """
        A getter for the 'BootStatus::PortValidationError' structure field
        
        Port validation failed. Only applicable to CubeComputer.
        """
        
        pass
    
    def get_PortDiscoveryError(self) -> int:
        """
        A getter for the 'BootStatus::PortDiscoveryError' structure field
        
        Auto-Discovery failed. Only applicable to CubeComputer.
        """
        
        pass
    
    def get_OtpSerialError(self) -> int:
        """
        A getter for the 'BootStatus::OtpSerialError' structure field
        
        OTP serial number is invalid
        """
        
        pass
    
    def get_CfgSerialError(self) -> int:
        """
        A getter for the 'BootStatus::CfgSerialError' structure field
        
        Config serial number is invalid
        """
        
        pass
    
    def get_SerialMismatchError(self) -> int:
        """
        A getter for the 'BootStatus::SerialMismatchError' structure field
        
        OTP/Config serial numbers do not match
        """
        
        pass
    
    def get_ConfigInvalidError(self) -> int:
        """
        A getter for the 'BootStatus::ConfigInvalidError' structure field
        
        Set if the applications config is invalid and the default configuration is being used (if available).
        """
        
        pass

def BootStatus_make_from_buf(buf : bytes) -> BootStatus:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TctlmCubeComputerControlProgram8_FileTransferStatus:
    """
    A Python class to represent struct objects of type 'TctlmCubeComputerControlProgram8_FileTransferStatus'
    
    File Transfer Status message structure. File Transfer Status
    """

    def __init__(self, e__TctlmCubeComputerControlProgram8_FtpState__ftp_state : TctlmCubeComputerControlProgram8_FtpState, e__TctlmCubeComputerControlProgram8_FtpUpgradeState__upgradeState : TctlmCubeComputerControlProgram8_FtpUpgradeState, uint32__dataRemain : int, uint32__errorCode : int, bool__busyError : int, bool__fileMetaError : int, bool__versionError : int, bool__nodeExistError : int, bool__nodeExpectError : int, bool__fileCrcError : int, bool__fileSizeError : int, bool__fileError : int, bool__fileInvalidError : int, bool__fileFullError : int, bool__fileEmptyError : int, bool__readError : int, bool__writeError : int, bool__eraseError : int, bool__frameSizeError : int, bool__timeoutError : int, bool__nodeCommsError : int, bool__nodeUsedError : int) -> None:
        """
        Struct 'TctlmCubeComputerControlProgram8_FileTransferStatus' constructor
        
        Attributes
        ---------
        e__TctlmCubeComputerControlProgram8_FtpState__ftp_state [1] : TctlmCubeComputerControlProgram8_FtpState
            FTP Global State
        e__TctlmCubeComputerControlProgram8_FtpUpgradeState__upgradeState [1] : TctlmCubeComputerControlProgram8_FtpUpgradeState
            FTP Internal Upgrade State
        uint32__dataRemain [1] : int
            Amount of remaining data to transfer  (measurment unit is [Bytes])
        uint32__errorCode [1] : int
            Operation Error Code. Non-Zero = ERROR
        bool__busyError [1] : int
            Bootloader is busy
        bool__fileMetaError [1] : int
            File Metadata received is invalid
        bool__versionError [1] : int
            File version is incompatible
        bool__nodeExistError [1] : int
            Target node does not exist
        bool__nodeExpectError [1] : int
            Target node is not expected
        bool__fileCrcError [1] : int
            File CRC Error Flag
        bool__fileSizeError [1] : int
            File is too large
        bool__fileError [1] : int
            File Error Flag (open/close)
        bool__fileInvalidError [1] : int
            File Invalid Error Flag
        bool__fileFullError [1] : int
            File Full Error Flag
        bool__fileEmptyError [1] : int
            File Empty Error Flag
        bool__readError [1] : int
            Read Error Flag
        bool__writeError [1] : int
            Write Error Flag
        bool__eraseError [1] : int
            Erase Error Flag
        bool__frameSizeError [1] : int
            Frame Size Error Flag
        bool__timeoutError [1] : int
            Timeout Error Flag
        bool__nodeCommsError [1] : int
            Node comms fails during upgrade
        bool__nodeUsedError [1] : int
            Node is required for control
        """
        
        pass
        
    def get_ftp_state(self) -> TctlmCubeComputerControlProgram8_FtpState:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::ftp_state' structure field
        
        FTP Global State
        """
        
        pass
    
    def get_upgradeState(self) -> TctlmCubeComputerControlProgram8_FtpUpgradeState:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::upgradeState' structure field
        
        FTP Internal Upgrade State
        """
        
        pass
    
    def get_dataRemain(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::dataRemain' structure field
        
        Amount of remaining data to transfer  (measurment unit is [Bytes])
        """
        
        pass
    
    def get_errorCode(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::errorCode' structure field
        
        Operation Error Code. Non-Zero = ERROR
        """
        
        pass
    
    def get_busyError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::busyError' structure field
        
        Bootloader is busy
        """
        
        pass
    
    def get_fileMetaError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::fileMetaError' structure field
        
        File Metadata received is invalid
        """
        
        pass
    
    def get_versionError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::versionError' structure field
        
        File version is incompatible
        """
        
        pass
    
    def get_nodeExistError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::nodeExistError' structure field
        
        Target node does not exist
        """
        
        pass
    
    def get_nodeExpectError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::nodeExpectError' structure field
        
        Target node is not expected
        """
        
        pass
    
    def get_fileCrcError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::fileCrcError' structure field
        
        File CRC Error Flag
        """
        
        pass
    
    def get_fileSizeError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::fileSizeError' structure field
        
        File is too large
        """
        
        pass
    
    def get_fileError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::fileError' structure field
        
        File Error Flag (open/close)
        """
        
        pass
    
    def get_fileInvalidError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::fileInvalidError' structure field
        
        File Invalid Error Flag
        """
        
        pass
    
    def get_fileFullError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::fileFullError' structure field
        
        File Full Error Flag
        """
        
        pass
    
    def get_fileEmptyError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::fileEmptyError' structure field
        
        File Empty Error Flag
        """
        
        pass
    
    def get_readError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::readError' structure field
        
        Read Error Flag
        """
        
        pass
    
    def get_writeError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::writeError' structure field
        
        Write Error Flag
        """
        
        pass
    
    def get_eraseError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::eraseError' structure field
        
        Erase Error Flag
        """
        
        pass
    
    def get_frameSizeError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::frameSizeError' structure field
        
        Frame Size Error Flag
        """
        
        pass
    
    def get_timeoutError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::timeoutError' structure field
        
        Timeout Error Flag
        """
        
        pass
    
    def get_nodeCommsError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::nodeCommsError' structure field
        
        Node comms fails during upgrade
        """
        
        pass
    
    def get_nodeUsedError(self) -> int:
        """
        A getter for the 'TctlmCubeComputerControlProgram8_FileTransferStatus::nodeUsedError' structure field
        
        Node is required for control
        """
        
        pass

def TctlmCubeComputerControlProgram8_FileTransferStatus_make_from_buf(buf : bytes) -> TctlmCubeComputerControlProgram8_FileTransferStatus:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TctlmCubeComputerCommon3_EventLogFilterTransferSetup:
    """
    A Python class to represent struct objects of type 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup'
    
    """

    def __init__(self, e__TctlmCubeComputerCommon3_LogReadFilterType__filterType : TctlmCubeComputerCommon3_LogReadFilterType, uint32__startTimeUnix : int, uint32__endTimeUnix : int, uint32__numEntries : int, uint32__writeCounter : int, bool__includeClassCritical : int, bool__includeClassMajorWarning : int, bool__includeClassMinorWarning : int, bool__includeClassInfo : int, bool__includeSourceCubeComputer : int, bool__includeSourceRwl0 : int, bool__includeSourceRwl1 : int, bool__includeSourceRwl2 : int, bool__includeSourceRwl3 : int, bool__includeSourceFss0 : int, bool__includeSourceFss1 : int, bool__includeSourceFss2 : int, bool__includeSourceFss3 : int, bool__includeSourceHss0 : int, bool__includeSourceHss1 : int, bool__includeSourceStr0 : int, bool__includeSourceStr1 : int, bool__includeSourceMag0 : int, bool__includeSourceMag1 : int, bool__includeSourceExt0 : int, bool__includeSourceExt1 : int) -> None:
        """
        Struct 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup' constructor
        
        Attributes
        ---------
        e__TctlmCubeComputerCommon3_LogReadFilterType__filterType [1] : TctlmCubeComputerCommon3_LogReadFilterType
        uint32__startTimeUnix [1] : int
        uint32__endTimeUnix [1] : int
        uint32__numEntries [1] : int
        uint32__writeCounter [1] : int
        bool__includeClassCritical [1] : int
        bool__includeClassMajorWarning [1] : int
        bool__includeClassMinorWarning [1] : int
        bool__includeClassInfo [1] : int
        bool__includeSourceCubeComputer [1] : int
        bool__includeSourceRwl0 [1] : int
        bool__includeSourceRwl1 [1] : int
        bool__includeSourceRwl2 [1] : int
        bool__includeSourceRwl3 [1] : int
        bool__includeSourceFss0 [1] : int
        bool__includeSourceFss1 [1] : int
        bool__includeSourceFss2 [1] : int
        bool__includeSourceFss3 [1] : int
        bool__includeSourceHss0 [1] : int
        bool__includeSourceHss1 [1] : int
        bool__includeSourceStr0 [1] : int
        bool__includeSourceStr1 [1] : int
        bool__includeSourceMag0 [1] : int
        bool__includeSourceMag1 [1] : int
        bool__includeSourceExt0 [1] : int
        bool__includeSourceExt1 [1] : int
        """
        
        pass
        
    def get_filterType(self) -> TctlmCubeComputerCommon3_LogReadFilterType:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::filterType' structure field
        
        """
        
        pass
    
    def get_startTimeUnix(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::startTimeUnix' structure field
        
        """
        
        pass
    
    def get_endTimeUnix(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::endTimeUnix' structure field
        
        """
        
        pass
    
    def get_numEntries(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::numEntries' structure field
        
        """
        
        pass
    
    def get_writeCounter(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::writeCounter' structure field
        
        """
        
        pass
    
    def get_includeClassCritical(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeClassCritical' structure field
        
        """
        
        pass
    
    def get_includeClassMajorWarning(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeClassMajorWarning' structure field
        
        """
        
        pass
    
    def get_includeClassMinorWarning(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeClassMinorWarning' structure field
        
        """
        
        pass
    
    def get_includeClassInfo(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeClassInfo' structure field
        
        """
        
        pass
    
    def get_includeSourceCubeComputer(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeSourceCubeComputer' structure field
        
        """
        
        pass
    
    def get_includeSourceRwl0(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeSourceRwl0' structure field
        
        """
        
        pass
    
    def get_includeSourceRwl1(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeSourceRwl1' structure field
        
        """
        
        pass
    
    def get_includeSourceRwl2(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeSourceRwl2' structure field
        
        """
        
        pass
    
    def get_includeSourceRwl3(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeSourceRwl3' structure field
        
        """
        
        pass
    
    def get_includeSourceFss0(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeSourceFss0' structure field
        
        """
        
        pass
    
    def get_includeSourceFss1(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeSourceFss1' structure field
        
        """
        
        pass
    
    def get_includeSourceFss2(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeSourceFss2' structure field
        
        """
        
        pass
    
    def get_includeSourceFss3(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeSourceFss3' structure field
        
        """
        
        pass
    
    def get_includeSourceHss0(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeSourceHss0' structure field
        
        """
        
        pass
    
    def get_includeSourceHss1(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeSourceHss1' structure field
        
        """
        
        pass
    
    def get_includeSourceStr0(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeSourceStr0' structure field
        
        """
        
        pass
    
    def get_includeSourceStr1(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeSourceStr1' structure field
        
        """
        
        pass
    
    def get_includeSourceMag0(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeSourceMag0' structure field
        
        """
        
        pass
    
    def get_includeSourceMag1(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeSourceMag1' structure field
        
        """
        
        pass
    
    def get_includeSourceExt0(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeSourceExt0' structure field
        
        """
        
        pass
    
    def get_includeSourceExt1(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup::includeSourceExt1' structure field
        
        """
        
        pass

def TctlmCubeComputerCommon3_EventLogFilterTransferSetup_make_from_buf(buf : bytes) -> TctlmCubeComputerCommon3_EventLogFilterTransferSetup:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TctlmCubeComputerCommon3_TelemetryLogTransferSetup:
    """
    A Python class to represent struct objects of type 'TctlmCubeComputerCommon3_TelemetryLogTransferSetup'
    
    """

    def __init__(self, e__TctlmCubeComputerCommon3_LogReadFilterType__filterType : TctlmCubeComputerCommon3_LogReadFilterType, uint32__startTimeUnix : int, uint32__endTimeUnix : int, uint32__numEntries : int, uint32__writeCounter : int, e__TctlmCubeComputerCommon3_TlmLogReturnIntervalValues__tlmLogReturnInterval : TctlmCubeComputerCommon3_TlmLogReturnIntervalValues, a__uint8__5__logIdBitmask : list[int]) -> None:
        """
        Struct 'TctlmCubeComputerCommon3_TelemetryLogTransferSetup' constructor
        
        Attributes
        ---------
        e__TctlmCubeComputerCommon3_LogReadFilterType__filterType [1] : TctlmCubeComputerCommon3_LogReadFilterType
        uint32__startTimeUnix [1] : int
        uint32__endTimeUnix [1] : int
        uint32__numEntries [1] : int
        uint32__writeCounter [1] : int
        e__TctlmCubeComputerCommon3_TlmLogReturnIntervalValues__tlmLogReturnInterval [1] : TctlmCubeComputerCommon3_TlmLogReturnIntervalValues
        a__uint8__5__logIdBitmask [5] : list[int]
        """
        
        pass
        
    def get_filterType(self) -> TctlmCubeComputerCommon3_LogReadFilterType:
        """
        A getter for the 'TctlmCubeComputerCommon3_TelemetryLogTransferSetup::filterType' structure field
        
        """
        
        pass
    
    def get_startTimeUnix(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_TelemetryLogTransferSetup::startTimeUnix' structure field
        
        """
        
        pass
    
    def get_endTimeUnix(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_TelemetryLogTransferSetup::endTimeUnix' structure field
        
        """
        
        pass
    
    def get_numEntries(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_TelemetryLogTransferSetup::numEntries' structure field
        
        """
        
        pass
    
    def get_writeCounter(self) -> int:
        """
        A getter for the 'TctlmCubeComputerCommon3_TelemetryLogTransferSetup::writeCounter' structure field
        
        """
        
        pass
    
    def get_tlmLogReturnInterval(self) -> TctlmCubeComputerCommon3_TlmLogReturnIntervalValues:
        """
        A getter for the 'TctlmCubeComputerCommon3_TelemetryLogTransferSetup::tlmLogReturnInterval' structure field
        
        """
        
        pass
    
    def get_logIdBitmask(self) -> list[int]:
        """
        A getter for the 'TctlmCubeComputerCommon3_TelemetryLogTransferSetup::logIdBitmask' structure field
        
        """
        
        pass

def TctlmCubeComputerCommon3_TelemetryLogTransferSetup_make_from_buf(buf : bytes) -> TctlmCubeComputerCommon3_TelemetryLogTransferSetup:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ControlModeConfig:
    """
    A Python class to represent struct objects of type 'ControlModeConfig'
    
    Control mode configuration
    """

    def __init__(self, e__ControlModes__control_mode : ControlModes, uint16__timeout : int) -> None:
        """
        Struct 'ControlModeConfig' constructor
        
        Attributes
        ---------
        e__ControlModes__control_mode [1] : ControlModes
            Used control mode type
        uint16__timeout [1] : int
            Magnetic controller timeout
        """
        
        pass
        
    def get_control_mode(self) -> ControlModes:
        """
        A getter for the 'ControlModeConfig::control_mode' structure field
        
        Used control mode type
        """
        
        pass
    
    def get_timeout(self) -> int:
        """
        A getter for the 'ControlModeConfig::timeout' structure field
        
        Magnetic controller timeout
        """
        
        pass

def ControlModeConfig_make_from_buf(buf : bytes) -> ControlModeConfig:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class state_change_core_args:
    """
    A Python class to represent struct objects of type 'state_change_core_args'
    
    State change core arguments
    """

    def __init__(self, e__ControlModes__control_mode : ControlModes, e__EstimationModes__estimation_mode_main : EstimationModes, e__EstimationModes__estimation_mode_backup : EstimationModes, s__nodes_pwr_states : PowerState) -> None:
        """
        Struct 'state_change_core_args' constructor
        
        Attributes
        ---------
        e__ControlModes__control_mode [1] : ControlModes
            Requested control mode
        e__EstimationModes__estimation_mode_main [1] : EstimationModes
            Requested estimation mode for the main estimator
        e__EstimationModes__estimation_mode_backup [1] : EstimationModes
            Requested estimation mode for the backup estimator
        s__nodes_pwr_states [1] : PowerState
            Requested power state for the peripheral nodes
        """
        
        pass
        
    def get_control_mode(self) -> ControlModes:
        """
        A getter for the 'state_change_core_args::control_mode' structure field
        
        Requested control mode
        """
        
        pass
    
    def get_estimation_mode_main(self) -> EstimationModes:
        """
        A getter for the 'state_change_core_args::estimation_mode_main' structure field
        
        Requested estimation mode for the main estimator
        """
        
        pass
    
    def get_estimation_mode_backup(self) -> EstimationModes:
        """
        A getter for the 'state_change_core_args::estimation_mode_backup' structure field
        
        Requested estimation mode for the backup estimator
        """
        
        pass
    
    def get_nodes_pwr_states(self) -> PowerState:
        """
        A getter for the 'state_change_core_args::nodes_pwr_states' structure field
        
        Requested power state for the peripheral nodes
        """
        
        pass

def state_change_core_args_make_from_buf(buf : bytes) -> state_change_core_args:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class OpStatusCommon:
    """
    A Python class to represent struct objects of type 'OpStatusCommon'
    
    Common operational status telemetry for the ADCS
    """

    def __init__(self, s__boot_status : BootStatus, s__power_state : PowerState, s__comp_err_codes : CompErrCodes, bool__is_valid : int) -> None:
        """
        Struct 'OpStatusCommon' constructor
        
        Attributes
        ---------
        s__boot_status [1] : BootStatus
            TLM_137 Boot Status
        s__power_state [1] : PowerState
            TLM_183 Power State
        s__comp_err_codes [1] : CompErrCodes
            TLM_230 Component Error Codes
        bool__is_valid [1] : int
            Is data valid
        """
        
        pass
        
    def get_boot_status(self) -> BootStatus:
        """
        A getter for the 'OpStatusCommon::boot_status' structure field
        
        TLM_137 Boot Status
        """
        
        pass
    
    def get_power_state(self) -> PowerState:
        """
        A getter for the 'OpStatusCommon::power_state' structure field
        
        TLM_183 Power State
        """
        
        pass
    
    def get_comp_err_codes(self) -> CompErrCodes:
        """
        A getter for the 'OpStatusCommon::comp_err_codes' structure field
        
        TLM_230 Component Error Codes
        """
        
        pass
    
    def get_is_valid(self) -> int:
        """
        A getter for the 'OpStatusCommon::is_valid' structure field
        
        Is data valid
        """
        
        pass

def OpStatusCommon_make_from_buf(buf : bytes) -> OpStatusCommon:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class cube_node_fw_update_status:
    """
    A Python class to represent struct objects of type 'cube_node_fw_update_status'
    
    cube node control program update status
    """

    def __init__(self, t__int32__err_code : int, bool__force : int, e__TctlmCommonFrameworkEnums_NodeType__node_type : TctlmCommonFrameworkEnums_NodeType, uint32__serial_int : int, s__status : TctlmCubeComputerControlProgram8_FileTransferStatus, s__control_program_file_name : FName, s__configuration_file_name : FName) -> None:
        """
        Struct 'cube_node_fw_update_status' constructor
        
        Attributes
        ---------
        t__int32__err_code [1] : int
        bool__force [1] : int
        e__TctlmCommonFrameworkEnums_NodeType__node_type [1] : TctlmCommonFrameworkEnums_NodeType
        uint32__serial_int [1] : int
        s__status [1] : TctlmCubeComputerControlProgram8_FileTransferStatus
        s__control_program_file_name [1] : FName
        s__configuration_file_name [1] : FName
        """
        
        pass
        
    def get_err_code(self) -> int:
        """
        A getter for the 'cube_node_fw_update_status::err_code' structure field
        
        """
        
        pass
    
    def get_force(self) -> int:
        """
        A getter for the 'cube_node_fw_update_status::force' structure field
        
        """
        
        pass
    
    def get_node_type(self) -> TctlmCommonFrameworkEnums_NodeType:
        """
        A getter for the 'cube_node_fw_update_status::node_type' structure field
        
        """
        
        pass
    
    def get_serial_int(self) -> int:
        """
        A getter for the 'cube_node_fw_update_status::serial_int' structure field
        
        """
        
        pass
    
    def get_status(self) -> TctlmCubeComputerControlProgram8_FileTransferStatus:
        """
        A getter for the 'cube_node_fw_update_status::status' structure field
        
        """
        
        pass
    
    def get_control_program_file_name(self) -> FName:
        """
        A getter for the 'cube_node_fw_update_status::control_program_file_name' structure field
        
        """
        
        pass
    
    def get_configuration_file_name(self) -> FName:
        """
        A getter for the 'cube_node_fw_update_status::configuration_file_name' structure field
        
        """
        
        pass

def cube_node_fw_update_status_make_from_buf(buf : bytes) -> cube_node_fw_update_status:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class download_event_status:
    """
    A Python class to represent struct objects of type 'download_event_status'
    
    event download status
    """

    def __init__(self, t__int32__err : int, s__setup : TctlmCubeComputerCommon3_EventLogFilterTransferSetup, s__status : TctlmCubeComputerCommon3_EventLogStatus, s__file_name : FName) -> None:
        """
        Struct 'download_event_status' constructor
        
        Attributes
        ---------
        t__int32__err [1] : int
        s__setup [1] : TctlmCubeComputerCommon3_EventLogFilterTransferSetup
        s__status [1] : TctlmCubeComputerCommon3_EventLogStatus
        s__file_name [1] : FName
        """
        
        pass
        
    def get_err(self) -> int:
        """
        A getter for the 'download_event_status::err' structure field
        
        """
        
        pass
    
    def get_setup(self) -> TctlmCubeComputerCommon3_EventLogFilterTransferSetup:
        """
        A getter for the 'download_event_status::setup' structure field
        
        """
        
        pass
    
    def get_status(self) -> TctlmCubeComputerCommon3_EventLogStatus:
        """
        A getter for the 'download_event_status::status' structure field
        
        """
        
        pass
    
    def get_file_name(self) -> FName:
        """
        A getter for the 'download_event_status::file_name' structure field
        
        """
        
        pass

def download_event_status_make_from_buf(buf : bytes) -> download_event_status:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class download_telemetry_status:
    """
    A Python class to represent struct objects of type 'download_telemetry_status'
    
    telemetry download status
    """

    def __init__(self, t__int32__err : int, s__setup : TctlmCubeComputerCommon3_TelemetryLogTransferSetup, s__status : TctlmCubeComputerCommon3_TelemtryLogStatus, s__file_name : FName) -> None:
        """
        Struct 'download_telemetry_status' constructor
        
        Attributes
        ---------
        t__int32__err [1] : int
        s__setup [1] : TctlmCubeComputerCommon3_TelemetryLogTransferSetup
        s__status [1] : TctlmCubeComputerCommon3_TelemtryLogStatus
        s__file_name [1] : FName
        """
        
        pass
        
    def get_err(self) -> int:
        """
        A getter for the 'download_telemetry_status::err' structure field
        
        """
        
        pass
    
    def get_setup(self) -> TctlmCubeComputerCommon3_TelemetryLogTransferSetup:
        """
        A getter for the 'download_telemetry_status::setup' structure field
        
        """
        
        pass
    
    def get_status(self) -> TctlmCubeComputerCommon3_TelemtryLogStatus:
        """
        A getter for the 'download_telemetry_status::status' structure field
        
        """
        
        pass
    
    def get_file_name(self) -> FName:
        """
        A getter for the 'download_telemetry_status::file_name' structure field
        
        """
        
        pass

def download_telemetry_status_make_from_buf(buf : bytes) -> download_telemetry_status:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class OpStatusApp:
    """
    A Python class to represent struct objects of type 'OpStatusApp'
    
    Application operational status telemetry for the ADCS
    """

    def __init__(self, e__AdcsRunMode__run_mode : AdcsRunMode, s__control_mode : ControlModeConfig, s__estimation_mode : EstModeConfig, e__AdcsOpState__op_state : AdcsOpState, bool__is_valid : int) -> None:
        """
        Struct 'OpStatusApp' constructor
        
        Attributes
        ---------
        e__AdcsRunMode__run_mode [1] : AdcsRunMode
            TLM_184 Run Mode
        s__control_mode [1] : ControlModeConfig
            TLM_185 Control Mode
        s__estimation_mode [1] : EstModeConfig
            TLM_199 Estimation Mode
        e__AdcsOpState__op_state [1] : AdcsOpState
            TLM_200 Operational State
        bool__is_valid [1] : int
            Is data valid
        """
        
        pass
        
    def get_run_mode(self) -> AdcsRunMode:
        """
        A getter for the 'OpStatusApp::run_mode' structure field
        
        TLM_184 Run Mode
        """
        
        pass
    
    def get_control_mode(self) -> ControlModeConfig:
        """
        A getter for the 'OpStatusApp::control_mode' structure field
        
        TLM_185 Control Mode
        """
        
        pass
    
    def get_estimation_mode(self) -> EstModeConfig:
        """
        A getter for the 'OpStatusApp::estimation_mode' structure field
        
        TLM_199 Estimation Mode
        """
        
        pass
    
    def get_op_state(self) -> AdcsOpState:
        """
        A getter for the 'OpStatusApp::op_state' structure field
        
        TLM_200 Operational State
        """
        
        pass
    
    def get_is_valid(self) -> int:
        """
        A getter for the 'OpStatusApp::is_valid' structure field
        
        Is data valid
        """
        
        pass

def OpStatusApp_make_from_buf(buf : bytes) -> OpStatusApp:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class state_change_args:
    """
    A Python class to represent struct objects of type 'state_change_args'
    
    State change arguments associated to the state change event type
    """

    def __init__(self, s__core_args : state_change_core_args, s__ref_params : RefParams, uint8__req_state_id : int) -> None:
        """
        Struct 'state_change_args' constructor
        
        Attributes
        ---------
        s__core_args [1] : state_change_core_args
            State change core arguments
        s__ref_params [1] : RefParams
            Reference parameters (angles, coordinates, etc.) for some control modes
        uint8__req_state_id [1] : int
            ID of the requested AOCS state
        """
        
        pass
        
    def get_core_args(self) -> state_change_core_args:
        """
        A getter for the 'state_change_args::core_args' structure field
        
        State change core arguments
        """
        
        pass
    
    def get_ref_params(self) -> RefParams:
        """
        A getter for the 'state_change_args::ref_params' structure field
        
        Reference parameters (angles, coordinates, etc.) for some control modes
        """
        
        pass
    
    def get_req_state_id(self) -> int:
        """
        A getter for the 'state_change_args::req_state_id' structure field
        
        ID of the requested AOCS state
        """
        
        pass

def state_change_args_make_from_buf(buf : bytes) -> state_change_args:
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
def req_reqStateMachineStateChange(e__StateMachineEvents__sm_event : StateMachineEvents, s__state_change_event_args : state_change_args) -> bytes:
    """
    Request serialization function for method 'reqStateMachineStateChange'
    
    Request a change of the state machine state which hanles the ADCS health and behaviour. 
    
    Arguments
    ---------
    e__StateMachineEvents__sm_event [1] : StateMachineEvents
        Gen2 state machine which will be triggered
    s__state_change_event_args [1] : state_change_args
        State change event args
    """
    
    pass
    
def req_getStateMachineState() -> bytes:
    """
    Request serialization function for method 'getStateMachineState'
    
    Get state machine current state. Refer to the SDK documentation for further information on the state machine and ADCS services. 
    
    """
    
    pass
    
def req_getOpStatus() -> bytes:
    """
    Request serialization function for method 'getOpStatus'
    
    Get the last operational status of the ADCS. The status is updated every 10 seconds. 
    
    """
    
    pass
    
def req_reqSoftResetAndMode(e__AdcsProgType__prog_type : AdcsProgType) -> bytes:
    """
    Request serialization function for method 'reqSoftResetAndMode'
    
    Request a soft reset of the ADCS and if the ADCS should remain in bootloader or application. The reset executes immeditely changing the state machine to the backoff state. 
    
    Arguments
    ---------
    e__AdcsProgType__prog_type [1] : AdcsProgType
        Mode in which to put the ADCS into
    """
    
    pass
    
def req_get_events_since_last_power_up() -> bytes:
    """
    Request serialization function for method 'get_events_since_last_power_up'
    
    Gets the major and critical events detected since last power-up 
    
    """
    
    pass
    
def req_clear_events_since_last_power_up() -> bytes:
    """
    Request serialization function for method 'clear_events_since_last_power_up'
    
    Clear the events statistics cached in the OBC 
    
    """
    
    pass
    
def req_download_evt(s__file_name : FName, s__setup : TctlmCubeComputerCommon3_EventLogFilterTransferSetup) -> bytes:
    """
    Request serialization function for method 'download_evt'
    
    Download CubeObc events 
    
    Arguments
    ---------
    s__file_name [1] : FName
        file to be created on Endurosat OBC
    s__setup [1] : TctlmCubeComputerCommon3_EventLogFilterTransferSetup
        event download specific parameters
    """
    
    pass
    
def req_download_evt_status() -> bytes:
    """
    Request serialization function for method 'download_evt_status'
    
    
    """
    
    pass
    
def req_download_tlm(s__file_name : FName, s__setup : TctlmCubeComputerCommon3_TelemetryLogTransferSetup) -> bytes:
    """
    Request serialization function for method 'download_tlm'
    
    
    Arguments
    ---------
    s__file_name [1] : FName
        file to be created on Endurosat OBC
    s__setup [1] : TctlmCubeComputerCommon3_TelemetryLogTransferSetup
    """
    
    pass
    
def req_download_tlm_status() -> bytes:
    """
    Request serialization function for method 'download_tlm_status'
    
    
    """
    
    pass
    
def req_download_img_direct(s__file_name : FName, e__AbstractImagingNodeType__node : AbstractImagingNodeType, uint32__file_handle : int) -> bytes:
    """
    Request serialization function for method 'download_img_direct'
    
    
    Arguments
    ---------
    s__file_name [1] : FName
        file to be created on Endurosat OBC
    e__AbstractImagingNodeType__node [1] : AbstractImagingNodeType
        node to download image from
    uint32__file_handle [1] : int
        File handle on OBC side
    """
    
    pass
    
def req_download_img_direct_status() -> bytes:
    """
    Request serialization function for method 'download_img_direct_status'
    
    
    """
    
    pass
    
def req_get_fdir_persistent_errors() -> bytes:
    """
    Request serialization function for method 'get_fdir_persistent_errors'
    
    Read out the errors which the FDIR logic was unable to recover from. These error are stored in RAM. 
    
    """
    
    pass
    
def req_clear_fdir_persistent_errors() -> bytes:
    """
    Request serialization function for method 'clear_fdir_persistent_errors'
    
    Clears the persistent errors 
    
    """
    
    pass
    
def req_get_fdir_stats() -> bytes:
    """
    Request serialization function for method 'get_fdir_stats'
    
    Get FDIR statistics 
    
    """
    
    pass
    
def req_clear_fdir_stats() -> bytes:
    """
    Request serialization function for method 'clear_fdir_stats'
    
    Clear FDIR statistics 
    
    """
    
    pass
    
def req_get_commissioning_status() -> bytes:
    """
    Request serialization function for method 'get_commissioning_status'
    
    Obtains the Gen2 CubeADCS commissioning status 
    
    """
    
    pass
    
def req_set_commissioning_status(e__CommissioningStatus__status : CommissioningStatus) -> bytes:
    """
    Request serialization function for method 'set_commissioning_status'
    
    Sets the Gen2 CubeADCS commissioning status to a new value 
    
    Arguments
    ---------
    e__CommissioningStatus__status [1] : CommissioningStatus
    """
    
    pass
    
def req_get_tlm_cfg() -> bytes:
    """
    Request serialization function for method 'get_tlm_cfg'
    
    Get telemetry configuration - returns the persistent configuration of the loggable telemetry updated in the Data Cache.
            Loggable telemetry follows CubeSpace's description in API. The following configuration concerns only the valid masks as per the documentation. 
    
    """
    
    pass
    
def req_set_tlm_cfg(s__mask_0 : telemetry_mask_0, s__mask_1 : telemetry_mask_1, s__mask_2 : telemetry_mask_2, s__mask_3 : telemetry_mask_3, s__mask_4 : telemetry_mask_4) -> bytes:
    """
    Request serialization function for method 'set_tlm_cfg'
    
    Set telemetry configuration - set the persistent configuration of the loggable telemetry updated in the Data Cache.
            Loggable telemetry follows CubeSpace's description in API. The following configuration concerns only the valid masks as per the documentation. 
    
    Arguments
    ---------
    s__mask_0 [1] : telemetry_mask_0
        Loggable telemetry mask - column 0
    s__mask_1 [1] : telemetry_mask_1
        Loggable telemetry mask - column 1
    s__mask_2 [1] : telemetry_mask_2
        Loggable telemetry mask - column 2
    s__mask_3 [1] : telemetry_mask_3
        Loggable telemetry mask - column 3
    s__mask_4 [1] : telemetry_mask_4
        Loggable telemetry mask - column 4
    """
    
    pass
    
def req_get_nvm_system_states_cfg(e__sys_states__sys_state_to_get : sys_states) -> bytes:
    """
    Request serialization function for method 'get_nvm_system_states_cfg'
    
    Gets a single Gen2 CubeADCS system states configuration. 
    
    Arguments
    ---------
    e__sys_states__sys_state_to_get [1] : sys_states
        The system to get
    """
    
    pass
    
def req_set_nvm_system_states_cfg(s__sys_states_cfg : state_change_core_args, e__sys_states__sys_state_to_set : sys_states) -> bytes:
    """
    Request serialization function for method 'set_nvm_system_states_cfg'
    
    Sets a single Gen2 CubeADCS system state configuration 
    
    Arguments
    ---------
    s__sys_states_cfg [1] : state_change_core_args
        NVM system state configuration
    e__sys_states__sys_state_to_set [1] : sys_states
        The system to be set
    """
    
    pass
    
def req_fw_update_cube_computer(s__control_program_file_name : FName, s__configuration_file_name : FName, bool__force : int) -> bytes:
    """
    Request serialization function for method 'fw_update_cube_computer'
    
    performs cube computer control program update 
    
    Arguments
    ---------
    s__control_program_file_name [1] : FName
        control program file name (must exist in Endurosat's OBC file storage)
    s__configuration_file_name [1] : FName
        configuration file name (must exist in Endurosat's OBC file storage)
    bool__force [1] : int
        If parameter is set to true - force cube computer to booloader (if in control program)
                                      otherwise the upload fails if device is not already in booloader
    """
    
    pass
    
def req_fw_update_cube_computer_status() -> bytes:
    """
    Request serialization function for method 'fw_update_cube_computer_status'
    
    gets the status of the last executed cube computer control program update 
    
    """
    
    pass
    
def req_fw_update_cube_node(s__control_program_file_name : FName, s__configuration_file_name : FName, bool__force : int, e__TctlmCommonFrameworkEnums_NodeType__node_type : TctlmCommonFrameworkEnums_NodeType, uint32__serial_int : int) -> bytes:
    """
    Request serialization function for method 'fw_update_cube_node'
    
    performs cube node control program update 
    
    Arguments
    ---------
    s__control_program_file_name [1] : FName
        control program file name (must exist in Endurosat's OBC file storage)
    s__configuration_file_name [1] : FName
        configuration file name (must exist in Endurosat's OBC file storage)
    bool__force [1] : int
        If parameter is set to true - force cube computer to control program (if in boot)
                                      otherwise the upload fails if device is not already in app
    e__TctlmCommonFrameworkEnums_NodeType__node_type [1] : TctlmCommonFrameworkEnums_NodeType
        node type to be updated
    uint32__serial_int [1] : int
        node serial number
    """
    
    pass
    
def req_fw_update_cube_node_status() -> bytes:
    """
    Request serialization function for method 'fw_update_cube_node_status'
    
    gets the status of the last executed cube node control program update 
    
    """
    
    pass
    

# ********************************************************************************************
#
# Response classes
#
# ********************************************************************************************
class resp_reqStateMachineStateChange:
    """
    A class representing a parsed FIDL response for method 'reqStateMachineStateChange'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'reqStateMachineStateChange' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'reqStateMachineStateChange::op_result'
        """
        pass

class resp_getStateMachineState:
    """
    A class representing a parsed FIDL response for method 'getStateMachineState'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getStateMachineState' method (includes the received FP header)
        """
        pass

    def get_sm_state(self) -> StateMachineStates:
        """
        A getter for the output argument 'getStateMachineState::sm_state'
        """
        pass
    
    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'getStateMachineState::op_result'
        """
        pass

class resp_getOpStatus:
    """
    A class representing a parsed FIDL response for method 'getOpStatus'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getOpStatus' method (includes the received FP header)
        """
        pass

    def get_op_status_common(self) -> OpStatusCommon:
        """
        A getter for the output argument 'getOpStatus::op_status_common'
        """
        pass
    
    def get_op_status_app(self) -> OpStatusApp:
        """
        A getter for the output argument 'getOpStatus::op_status_app'
        """
        pass
    
    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'getOpStatus::op_result'
        """
        pass

class resp_reqSoftResetAndMode:
    """
    A class representing a parsed FIDL response for method 'reqSoftResetAndMode'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'reqSoftResetAndMode' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'reqSoftResetAndMode::op_result'
        """
        pass

class resp_get_events_since_last_power_up:
    """
    A class representing a parsed FIDL response for method 'get_events_since_last_power_up'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'get_events_since_last_power_up' method (includes the received FP header)
        """
        pass

    def get_all_events(self) -> events:
        """
        A getter for the output argument 'get_events_since_last_power_up::all_events'
        """
        pass
    
    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'get_events_since_last_power_up::op_result'
        """
        pass

class resp_clear_events_since_last_power_up:
    """
    A class representing a parsed FIDL response for method 'clear_events_since_last_power_up'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'clear_events_since_last_power_up' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'clear_events_since_last_power_up::op_result'
        """
        pass

class resp_download_evt:
    """
    A class representing a parsed FIDL response for method 'download_evt'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'download_evt' method (includes the received FP header)
        """
        pass

    def get_err(self) -> int:
        """
        A getter for the output argument 'download_evt::err'
        """
        pass

class resp_download_evt_status:
    """
    A class representing a parsed FIDL response for method 'download_evt_status'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'download_evt_status' method (includes the received FP header)
        """
        pass

    def get_err(self) -> int:
        """
        A getter for the output argument 'download_evt_status::err'
        """
        pass
    
    def get_status(self) -> download_event_status:
        """
        A getter for the output argument 'download_evt_status::status'
        """
        pass

class resp_download_tlm:
    """
    A class representing a parsed FIDL response for method 'download_tlm'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'download_tlm' method (includes the received FP header)
        """
        pass

    def get_err(self) -> int:
        """
        A getter for the output argument 'download_tlm::err'
        """
        pass

class resp_download_tlm_status:
    """
    A class representing a parsed FIDL response for method 'download_tlm_status'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'download_tlm_status' method (includes the received FP header)
        """
        pass

    def get_err(self) -> int:
        """
        A getter for the output argument 'download_tlm_status::err'
        """
        pass
    
    def get_status(self) -> download_telemetry_status:
        """
        A getter for the output argument 'download_tlm_status::status'
        """
        pass

class resp_download_img_direct:
    """
    A class representing a parsed FIDL response for method 'download_img_direct'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'download_img_direct' method (includes the received FP header)
        """
        pass

    def get_err(self) -> int:
        """
        A getter for the output argument 'download_img_direct::err'
        """
        pass

class resp_download_img_direct_status:
    """
    A class representing a parsed FIDL response for method 'download_img_direct_status'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'download_img_direct_status' method (includes the received FP header)
        """
        pass

    def get_err(self) -> int:
        """
        A getter for the output argument 'download_img_direct_status::err'
        """
        pass
    
    def get_file_name(self) -> FName:
        """
        A getter for the output argument 'download_img_direct_status::file_name'
        """
        pass
    
    def get_status(self) -> TctlmCubeComputerCommon3_ImageTransferStatus:
        """
        A getter for the output argument 'download_img_direct_status::status'
        """
        pass

class resp_get_fdir_persistent_errors:
    """
    A class representing a parsed FIDL response for method 'get_fdir_persistent_errors'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'get_fdir_persistent_errors' method (includes the received FP header)
        """
        pass

    def get_errors(self) -> int:
        """
        A getter for the output argument 'get_fdir_persistent_errors::errors'
        """
        pass
    
    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'get_fdir_persistent_errors::op_result'
        """
        pass

class resp_clear_fdir_persistent_errors:
    """
    A class representing a parsed FIDL response for method 'clear_fdir_persistent_errors'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'clear_fdir_persistent_errors' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'clear_fdir_persistent_errors::op_result'
        """
        pass

class resp_get_fdir_stats:
    """
    A class representing a parsed FIDL response for method 'get_fdir_stats'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'get_fdir_stats' method (includes the received FP header)
        """
        pass

    def get_fdir_logic(self) -> list[fdir_stat]:
        """
        A getter for the output argument 'get_fdir_stats::fdir_logic'
        """
        pass
    
    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'get_fdir_stats::op_result'
        """
        pass

class resp_clear_fdir_stats:
    """
    A class representing a parsed FIDL response for method 'clear_fdir_stats'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'clear_fdir_stats' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'clear_fdir_stats::op_result'
        """
        pass

class resp_get_commissioning_status:
    """
    A class representing a parsed FIDL response for method 'get_commissioning_status'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'get_commissioning_status' method (includes the received FP header)
        """
        pass

    def get_status(self) -> CommissioningStatus:
        """
        A getter for the output argument 'get_commissioning_status::status'
        """
        pass
    
    def get_opResult(self) -> StandardResult:
        """
        A getter for the output argument 'get_commissioning_status::opResult'
        """
        pass

class resp_set_commissioning_status:
    """
    A class representing a parsed FIDL response for method 'set_commissioning_status'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'set_commissioning_status' method (includes the received FP header)
        """
        pass

    def get_opResult(self) -> StandardResult:
        """
        A getter for the output argument 'set_commissioning_status::opResult'
        """
        pass

class resp_get_tlm_cfg:
    """
    A class representing a parsed FIDL response for method 'get_tlm_cfg'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'get_tlm_cfg' method (includes the received FP header)
        """
        pass

    def get_mask_0(self) -> telemetry_mask_0:
        """
        A getter for the output argument 'get_tlm_cfg::mask_0'
        """
        pass
    
    def get_mask_1(self) -> telemetry_mask_1:
        """
        A getter for the output argument 'get_tlm_cfg::mask_1'
        """
        pass
    
    def get_mask_2(self) -> telemetry_mask_2:
        """
        A getter for the output argument 'get_tlm_cfg::mask_2'
        """
        pass
    
    def get_mask_3(self) -> telemetry_mask_3:
        """
        A getter for the output argument 'get_tlm_cfg::mask_3'
        """
        pass
    
    def get_mask_4(self) -> telemetry_mask_4:
        """
        A getter for the output argument 'get_tlm_cfg::mask_4'
        """
        pass
    
    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'get_tlm_cfg::op_result'
        """
        pass

class resp_set_tlm_cfg:
    """
    A class representing a parsed FIDL response for method 'set_tlm_cfg'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'set_tlm_cfg' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'set_tlm_cfg::op_result'
        """
        pass

class resp_get_nvm_system_states_cfg:
    """
    A class representing a parsed FIDL response for method 'get_nvm_system_states_cfg'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'get_nvm_system_states_cfg' method (includes the received FP header)
        """
        pass

    def get_sys_states_cfg(self) -> state_change_core_args:
        """
        A getter for the output argument 'get_nvm_system_states_cfg::sys_states_cfg'
        """
        pass
    
    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'get_nvm_system_states_cfg::op_result'
        """
        pass

class resp_set_nvm_system_states_cfg:
    """
    A class representing a parsed FIDL response for method 'set_nvm_system_states_cfg'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'set_nvm_system_states_cfg' method (includes the received FP header)
        """
        pass

    def get_op_result(self) -> StandardResult:
        """
        A getter for the output argument 'set_nvm_system_states_cfg::op_result'
        """
        pass

class resp_fw_update_cube_computer:
    """
    A class representing a parsed FIDL response for method 'fw_update_cube_computer'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'fw_update_cube_computer' method (includes the received FP header)
        """
        pass

    def get_err(self) -> int:
        """
        A getter for the output argument 'fw_update_cube_computer::err'
        """
        pass

class resp_fw_update_cube_computer_status:
    """
    A class representing a parsed FIDL response for method 'fw_update_cube_computer_status'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'fw_update_cube_computer_status' method (includes the received FP header)
        """
        pass

    def get_err(self) -> int:
        """
        A getter for the output argument 'fw_update_cube_computer_status::err'
        """
        pass
    
    def get_status(self) -> cube_computer_fw_update_status:
        """
        A getter for the output argument 'fw_update_cube_computer_status::status'
        """
        pass

class resp_fw_update_cube_node:
    """
    A class representing a parsed FIDL response for method 'fw_update_cube_node'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'fw_update_cube_node' method (includes the received FP header)
        """
        pass

    def get_err(self) -> int:
        """
        A getter for the output argument 'fw_update_cube_node::err'
        """
        pass

class resp_fw_update_cube_node_status:
    """
    A class representing a parsed FIDL response for method 'fw_update_cube_node_status'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'fw_update_cube_node_status' method (includes the received FP header)
        """
        pass

    def get_err(self) -> int:
        """
        A getter for the output argument 'fw_update_cube_node_status::err'
        """
        pass
    
    def get_status(self) -> cube_node_fw_update_status:
        """
        A getter for the output argument 'fw_update_cube_node_status::status'
        """
        pass

