# ********************************************************************************************
# * @file upy_cubeadcs_gen2_cubecomputercontrolprogram8.py
# * @brief uPy dummy Python module generator
# ********************************************************************************************
# * @version           interface CubeADCS_Gen2_CubeComputerControlProgram8 v6.0
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
class CubeComputerControlProgram8_Pst3sOperatingModes(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_Pst3sOperatingModes'
    """
    # Invalid Mode
    CUBECOMPUTERCONTROLPROGRAM8_PST3SOPERATINGMODES_MODEINVALID = 0
    # Normal Mode
    CUBECOMPUTERCONTROLPROGRAM8_PST3SOPERATINGMODES_NORMALMODE = 0
    # Fixed Threshold
    CUBECOMPUTERCONTROLPROGRAM8_PST3SOPERATINGMODES_FIXEDTHRESHOLD = 0
    # Self-Test Mode
    CUBECOMPUTERCONTROLPROGRAM8_PST3SOPERATINGMODES_SELFTEST = 0
class CubeComputerControlProgram8_NodePort(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_NodePort'
    """
    # No port. Use the value if the Node Port is not relevent
    CUBECOMPUTERCONTROLPROGRAM8_NODEPORT_PORTNONE = 0
    # Wheel 1 Port
    CUBECOMPUTERCONTROLPROGRAM8_NODEPORT_PORTWHEEL1 = 0
    # Wheel 2 Port
    CUBECOMPUTERCONTROLPROGRAM8_NODEPORT_PORTWHEEL2 = 0
    # Wheel 3 Port
    CUBECOMPUTERCONTROLPROGRAM8_NODEPORT_PORTWHEEL3 = 0
    # Wheel 4 Port
    CUBECOMPUTERCONTROLPROGRAM8_NODEPORT_PORTWHEEL4 = 0
    # Sensor 1 Port
    CUBECOMPUTERCONTROLPROGRAM8_NODEPORT_PORTSENSOR1 = 0
    # Sensor 2 Port
    CUBECOMPUTERCONTROLPROGRAM8_NODEPORT_PORTSENSOR2 = 0
    # Sensor 3 Port
    CUBECOMPUTERCONTROLPROGRAM8_NODEPORT_PORTSENSOR3 = 0
    # Sensor 4 Port
    CUBECOMPUTERCONTROLPROGRAM8_NODEPORT_PORTSENSOR4 = 0
    # Sensor 5 Port
    CUBECOMPUTERCONTROLPROGRAM8_NODEPORT_PORTSENSOR5 = 0
    # Sensor 6 Port
    CUBECOMPUTERCONTROLPROGRAM8_NODEPORT_PORTSENSOR6 = 0
    # Sensor 7 Port
    CUBECOMPUTERCONTROLPROGRAM8_NODEPORT_PORTSENSOR7 = 0
    # Sensor 8 Port
    CUBECOMPUTERCONTROLPROGRAM8_NODEPORT_PORTSENSOR8 = 0
class CubeComputerControlProgram8_AdcsRunModeSelect(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_AdcsRunModeSelect'
    """
    # ADCS loop is inactive
    CUBECOMPUTERCONTROLPROGRAM8_ADCSRUNMODESELECT_ADCSOFF = 0
    # ADCS loop is active
    CUBECOMPUTERCONTROLPROGRAM8_ADCSRUNMODESELECT_ADCSENABLED = 0
    # ADCS loop executed on trigger
    CUBECOMPUTERCONTROLPROGRAM8_ADCSRUNMODESELECT_ADCSTRIGGERED = 0
    # ADCS is in simulation mode
    CUBECOMPUTERCONTROLPROGRAM8_ADCSRUNMODESELECT_ADCSSIMULATION = 0
class CubeComputerControlProgram8_StarDetectStatus(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_StarDetectStatus'
    """
    # Initialised
    CUBECOMPUTERCONTROLPROGRAM8_STARDETECTSTATUS_STARDETECTSTARTUP = 0
    # Detection scheduled
    CUBECOMPUTERCONTROLPROGRAM8_STARDETECTSTATUS_STARDETECTPENDING = 0
    # Detection in progress
    CUBECOMPUTERCONTROLPROGRAM8_STARDETECTSTATUS_STARDETECTBUSY = 0
    # Detection stopped because process took too long
    CUBECOMPUTERCONTROLPROGRAM8_STARDETECTSTATUS_STARDETECTABORT = 0
    # Detection completed
    CUBECOMPUTERCONTROLPROGRAM8_STARDETECTSTATUS_STARDETECTDONE = 0
class CubeComputerControlProgram8_CqAssign(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_CqAssign'
    """
    # Nothing assigned to CubeNode-Quad port
    CUBECOMPUTERCONTROLPROGRAM8_CQASSIGN_ASSIGNNONE = 0
    # Assign STR0 to CubeNode-Quad port
    CUBECOMPUTERCONTROLPROGRAM8_CQASSIGN_ASSIGNSTR0 = 0
    # Assign STR1 to CubeNode-Quad port
    CUBECOMPUTERCONTROLPROGRAM8_CQASSIGN_ASSIGNSTR1 = 0
    # Assign RWL0 to CubeNode-Quad port
    CUBECOMPUTERCONTROLPROGRAM8_CQASSIGN_ASSIGNRWL0 = 0
    # Assign RWL1 to CubeNode-Quad port
    CUBECOMPUTERCONTROLPROGRAM8_CQASSIGN_ASSIGNRWL1 = 0
    # Assign RWL2 to CubeNode-Quad port
    CUBECOMPUTERCONTROLPROGRAM8_CQASSIGN_ASSIGNRWL2 = 0
    # Assign RWL3 to CubeNode-Quad port
    CUBECOMPUTERCONTROLPROGRAM8_CQASSIGN_ASSIGNRWL3 = 0
    # Assign External GYR X-axis to CubeNode-Quad port
    CUBECOMPUTERCONTROLPROGRAM8_CQASSIGN_ASSIGNGYRX = 0
    # Assign External GYR X-axis to CubeNode-Quad port
    CUBECOMPUTERCONTROLPROGRAM8_CQASSIGN_ASSIGNGYRY = 0
    # Assign External GYR X-axis to CubeNode-Quad port
    CUBECOMPUTERCONTROLPROGRAM8_CQASSIGN_ASSIGNGYRZ = 0
class CubeComputerControlProgram8_Pst3sRateQuality(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_Pst3sRateQuality'
    """
    # Invalid - no velocity information
    CUBECOMPUTERCONTROLPROGRAM8_PST3SRATEQUALITY_RATEINVALID = 0
    # Velocity is estimated from previous calculations
    CUBECOMPUTERCONTROLPROGRAM8_PST3SRATEQUALITY_ESTIMATED = 0
    # Velocity is precise and calculated from attitude data
    CUBECOMPUTERCONTROLPROGRAM8_PST3SRATEQUALITY_PRECISE = 0
class CubeComputerControlProgram8_OhStateVal(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_OhStateVal'
    """
    # Optical head switched off
    CUBECOMPUTERCONTROLPROGRAM8_OHSTATEVAL_OHSTATEOFF = 0
    # Wait On
    CUBECOMPUTERCONTROLPROGRAM8_OHSTATEVAL_OHSTATEWAITON = 0
    # Init Tempo
    CUBECOMPUTERCONTROLPROGRAM8_OHSTATEVAL_OHSTATEINITTEMPO = 0
    # Check
    CUBECOMPUTERCONTROLPROGRAM8_OHSTATEVAL_OHSTATECHECK = 0
    # Config
    CUBECOMPUTERCONTROLPROGRAM8_OHSTATEVAL_OHSTATECONFIG = 0
    # Standby
    CUBECOMPUTERCONTROLPROGRAM8_OHSTATEVAL_OHSTATESTANDBY = 0
    # Acquire FF
    CUBECOMPUTERCONTROLPROGRAM8_OHSTATEVAL_OHSTATEACQFF = 0
    # Acquire HW
    CUBECOMPUTERCONTROLPROGRAM8_OHSTATEVAL_OHSTATEACQHW = 0
    # First Track
    CUBECOMPUTERCONTROLPROGRAM8_OHSTATEVAL_OHSTATEFIRSTTRACK = 0
    # Tracking
    CUBECOMPUTERCONTROLPROGRAM8_OHSTATEVAL_OHSTATETRACKING = 0
class CubeComputerControlProgram8_RwlFailId(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_RwlFailId'
    """
    # RwlFailNone
    CUBECOMPUTERCONTROLPROGRAM8_RWLFAILID_RWLFAILNONE = 0
    # RwlFail0
    CUBECOMPUTERCONTROLPROGRAM8_RWLFAILID_RWLFAIL0 = 0
    # RwlFail1
    CUBECOMPUTERCONTROLPROGRAM8_RWLFAILID_RWLFAIL1 = 0
    # RwlFail2
    CUBECOMPUTERCONTROLPROGRAM8_RWLFAILID_RWLFAIL2 = 0
    # RwlFail3
    CUBECOMPUTERCONTROLPROGRAM8_RWLFAILID_RWLFAIL3 = 0
class CubeComputerControlProgram8_Pst3sExtImageState(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_Pst3sExtImageState'
    """
    # External Image State Invalid for API version
    CUBECOMPUTERCONTROLPROGRAM8_PST3SEXTIMAGESTATE_IMAGEINVALID = 0
    # External Image State Off
    CUBECOMPUTERCONTROLPROGRAM8_PST3SEXTIMAGESTATE_IMAGEOFF = 0
    # External Image State On
    CUBECOMPUTERCONTROLPROGRAM8_PST3SEXTIMAGESTATE_IMAGEON = 0
class CubeComputerControlProgram8_FtpFiles(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_FtpFiles'
    """
    # Invalid File
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_FILEINVALID = 0
    # Base Bootloader for CubeComputer Image Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_BASEBLCCBIN = 0
    # Base Bootloader for R5 nodes - single bank Image Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_BASEBLR5SBBIN = 0
    # Base Bootloader for 52 nodes Image Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_BASEBL52BIN = 0
    # CubeWheel Image Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBEWHEELBIN = 0
    # CubeStar Image Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBESTARBIN = 0
    # CubeSense Image Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBESENSEBIN = 0
    # CubeMag Deploy Image Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBEMAGDEPLOYBIN = 0
    # CubeMag Deploy Image Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBEMAGCOMPACTBIN = 0
    # CubeAuriga Image Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBEAURIGABIN = 0
    # CubeIR Image Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBEIRBIN = 0
    # CubeNode-SLT Image Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBENODESLTBIN = 0
    # CubeNode-PST3S Image Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBENODEPST3SBIN = 0
    # CubeNode-NSSRWL Image Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBENODENSSRWLBIN = 0
    # CubeWheel-0 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBEWHEELCFG0 = 0
    # CubeWheel-1 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBEWHEELCFG1 = 0
    # CubeWheel-2 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBEWHEELCFG2 = 0
    # CubeWheel-3 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBEWHEELCFG3 = 0
    # CubeWheel-4 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBEWHEELCFG4 = 0
    # CubeStar-0 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBESTARCFG0 = 0
    # CubeStar-1 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBESTARCFG1 = 0
    # CubeStar-2 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBESTARCFG2 = 0
    # CubeStar-3 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBESTARCFG3 = 0
    # CubeSense-0 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBESENSECFG0 = 0
    # CubeSense-1 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBESENSECFG1 = 0
    # CubeSense-2 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBESENSECFG2 = 0
    # CubeSense-3 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBESENSECFG3 = 0
    # CubeMag-0 Deploy Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBEMAGDEPLOYCFG0 = 0
    # CubeMag-1 Deploy Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBEMAGDEPLOYCFG1 = 0
    # CubeMag-0 Compact Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBEMAGCOMPACTCFG0 = 0
    # CubeMag-1 Compact Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBEMAGCOMPACTCFG1 = 0
    # CubeAuriga-0 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBEAURIGACFG0 = 0
    # CubeAuriga-1 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBEAURIGACFG1 = 0
    # CubeIr-0 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBEIRCFG0 = 0
    # CubeIr-1 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBEIRCFG1 = 0
    # CubeNode-SLT-0 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBENODESLTCFG0 = 0
    # CubeNode-PST3S-0 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBENODEPST3SCFG0 = 0
    # CubeNode-PST3S-1 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBENODEPST3SCFG1 = 0
    # CubeNode-NSSRWL-0 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBENODENSSRWLCFG0 = 0
    # CubeNode-NSSRWL-1 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBENODENSSRWLCFG1 = 0
    # CubeNode-NSSRWL-2 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBENODENSSRWLCFG2 = 0
    # CubeNode-NSSRWL-3 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBENODENSSRWLCFG3 = 0
    # CubeNode-PST3S Image Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBENODEQUADPST3SBIN = 0
    # CubeNodeQuad-PST3S-0 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBENODEQUADPST3SCFG0 = 0
    # CubeNodeQuad-NSSRWL Image Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBENODEQUADNSSRWLBIN = 0
    # CubeNodeQuad-NSSRWL-0 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBENODEQUADNSSRWLCFG0 = 0
    # CubeNodeQuad-LITEFUFORS Image Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBENODEQUADLITEFUFORSBIN = 0
    # CubeNode-LITEFUFORS-0 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBENODEQUADLITEFUFORSCFG0 = 0
    # CubeNode-LITEFUFORS-1 Config Binary
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILES_CUBENODEQUADLITEFUFORSCFG1 = 0
class CubeComputerControlProgram8_OrbModeSelect(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_OrbModeSelect'
    """
    # Orbit calculated from SGP4 TLEs only
    CUBECOMPUTERCONTROLPROGRAM8_ORBMODESELECT_ORBTLE = 0
    # Orbit calculated from SGP4 TLE but replaced with GNSS measurements if available
    CUBECOMPUTERCONTROLPROGRAM8_ORBMODESELECT_ORBTLEGNSS = 0
    # Orbit calculated from Augmented SGP4 TLE
    CUBECOMPUTERCONTROLPROGRAM8_ORBMODESELECT_ORBASGP4 = 0
    # Orbit calculated from Augmented SGP4 TLE but replaced with GNSS measurements if available
    CUBECOMPUTERCONTROLPROGRAM8_ORBMODESELECT_ORBASGP4GNSS = 0
class CubeComputerControlProgram8_FtpUpgradeState(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_FtpUpgradeState'
    """
    # No Upgrade in Progress
    CUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_UPGRADEIDLE = 0
    # Initializing upgrade operation - first state immediately following transfer setup
    CUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_UPGRADEINIT = 0
    # Upgrade transitioning from image binary to config binary uupgrade
    CUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_UPGRADETRANS = 0
    # Initializing image binary upgrade
    CUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_UPGRADEINITBIN = 0
    # Initializing config binary upgrade
    CUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_UPGRADEINITCFG = 0
    # Image binary upgrade in progress
    CUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_UPGRADEBUSYBIN = 0
    # Config binary upgrade in progress
    CUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_UPGRADEBUSYCFG = 0
class CubeComputerControlProgram8_FmcStage(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_FmcStage'
    """
    # FMC control mode is not selected
    CUBECOMPUTERCONTROLPROGRAM8_FMCSTAGE_FMCINACTIVE = 0
    # Waiting for FMC scan to start. (defaults to same control as ConXYZwheel)
    CUBECOMPUTERCONTROLPROGRAM8_FMCSTAGE_FMCWAITING = 0
    # Control to FMC roll offset, and zero pitch and yaw
    CUBECOMPUTERCONTROLPROGRAM8_FMCSTAGE_FMCPREPARE = 0
    # Control initial FMC pitch angle for scan start
    CUBECOMPUTERCONTROLPROGRAM8_FMCSTAGE_FMCINITIALPITCH = 0
    # RW ramp for 10 sec towards FMC rate
    CUBECOMPUTERCONTROLPROGRAM8_FMCSTAGE_FMCRWRAMPUP = 0
    # FMC scan for 60s
    CUBECOMPUTERCONTROLPROGRAM8_FMCSTAGE_FMCSCAN = 0
    # Ramp Pitch RW for 10 sec back to FMC1
    CUBECOMPUTERCONTROLPROGRAM8_FMCSTAGE_FMCRWRAMPDOWN = 0
    # Stop FMC control
    CUBECOMPUTERCONTROLPROGRAM8_FMCSTAGE_FMCSTOPPING = 0
    # FMC scan ended. (defaults to same control as ConXYZwheel)
    CUBECOMPUTERCONTROLPROGRAM8_FMCSTAGE_FMCENDED = 0
class CubeComputerControlProgram8_Pst3sQuaternionFilteringGetState(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_Pst3sQuaternionFilteringGetState'
    """
    # Filtering Invalid. Depends on PST3S version.
    CUBECOMPUTERCONTROLPROGRAM8_PST3SQUATERNIONFILTERINGGETSTATE_QFILTERINGGETINVALID = 0
    # Filtering Off
    CUBECOMPUTERCONTROLPROGRAM8_PST3SQUATERNIONFILTERINGGETSTATE_QFILTERINGGETOFF = 0
    # Filtering On
    CUBECOMPUTERCONTROLPROGRAM8_PST3SQUATERNIONFILTERINGGETSTATE_QFILTERINGGETON = 0
class CubeComputerControlProgram8_NavSource(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_NavSource'
    """
    # Reported position and velocity (in TlmModels) comes from direct (latest) GNSS measurement
    CUBECOMPUTERCONTROLPROGRAM8_NAVSOURCE_NAVGNSSNOW = 0
    # Reported position and velocity (in TlmModels) comes from GNSS measurement up to 800ms old, propagated using linear velocity
    CUBECOMPUTERCONTROLPROGRAM8_NAVSOURCE_NAVGNSSPROPAGATED = 0
    # Reported position and velocity (in TlmModels) comes from SGP4 with orbital elements set via ConfigOrbitSatParams (from TLEs)
    CUBECOMPUTERCONTROLPROGRAM8_NAVSOURCE_NAVTLE = 0
    # Reported position and velocity (in TlmModels) comes from ASGP4 with orbital elements that were adjusted from GNSS measurements
    CUBECOMPUTERCONTROLPROGRAM8_NAVSOURCE_NAVASGP4TLE = 0
class CubeComputerControlProgram8_FmcFactor(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_FmcFactor'
    """
    # Forward Motion Compensation Factor 2
    CUBECOMPUTERCONTROLPROGRAM8_FMCFACTOR_FMC2 = 0
    # Forward Motion Compensation Factor 4
    CUBECOMPUTERCONTROLPROGRAM8_FMCFACTOR_FMC4 = 0
    # Forward Motion Compensation Factor 8
    CUBECOMPUTERCONTROLPROGRAM8_FMCFACTOR_FMC8 = 0
class CubeComputerControlProgram8_EarthCaptureResult(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_EarthCaptureResult'
    """
    # Initialized
    CUBECOMPUTERCONTROLPROGRAM8_EARTHCAPTURERESULT_EARTHCAPSTARTUP = 0
    # Issued but not complete
    CUBECOMPUTERCONTROLPROGRAM8_EARTHCAPTURERESULT_EARTHCAPPENDING = 0
    # Successful capture
    CUBECOMPUTERCONTROLPROGRAM8_EARTHCAPTURERESULT_EARTHCAPSUCCESS = 0
    # Response Timeout
    CUBECOMPUTERCONTROLPROGRAM8_EARTHCAPTURERESULT_EARTHCAPTIMEOUT = 0
    # Capture driver error
    CUBECOMPUTERCONTROLPROGRAM8_EARTHCAPTURERESULT_EARTHCAPERROR = 0
class CubeComputerControlProgram8_AurigaLibStateVal(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_AurigaLibStateVal'
    """
    # Initialization
    CUBECOMPUTERCONTROLPROGRAM8_AURIGALIBSTATEVAL_INITIALIZATION = 0
    # Standby Mode
    CUBECOMPUTERCONTROLPROGRAM8_AURIGALIBSTATEVAL_STANDBY = 0
    # Self-test Mode
    CUBECOMPUTERCONTROLPROGRAM8_AURIGALIBSTATEVAL_SELFTEST = 0
    # Photo Mode
    CUBECOMPUTERCONTROLPROGRAM8_AURIGALIBSTATEVAL_PHOTOMODE = 0
    # Tracking
    CUBECOMPUTERCONTROLPROGRAM8_AURIGALIBSTATEVAL_TRACKING = 0
    # Angular Rate Mode
    CUBECOMPUTERCONTROLPROGRAM8_AURIGALIBSTATEVAL_ARMMODE = 0
    # Attitude Acquisition Mode
    CUBECOMPUTERCONTROLPROGRAM8_AURIGALIBSTATEVAL_AAMMODE = 0
    # Attitude Tracking Mode
    CUBECOMPUTERCONTROLPROGRAM8_AURIGALIBSTATEVAL_ATMMODE = 0
class CubeComputerControlProgram8_Pst3sSelfTestResult(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_Pst3sSelfTestResult'
    """
    # Selt-test OK
    CUBECOMPUTERCONTROLPROGRAM8_PST3SSELFTESTRESULT_CORRECT = 0
    # Selt-test Error
    CUBECOMPUTERCONTROLPROGRAM8_PST3SSELFTESTRESULT_ERROR = 0
class CubeComputerControlProgram8_Pst3sDataValid(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_Pst3sDataValid'
    """
    # Gesture Data Valid
    CUBECOMPUTERCONTROLPROGRAM8_PST3SDATAVALID_GESTUREVALID = 0
    # Attitude Data Valid
    CUBECOMPUTERCONTROLPROGRAM8_PST3SDATAVALID_ATTITUDEVALID = 0
class CubeComputerControlProgram8_Pst3sSaaWorkingMode(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_Pst3sSaaWorkingMode'
    """
    # SAA Invalid. Depends on PST3S version.
    CUBECOMPUTERCONTROLPROGRAM8_PST3SSAAWORKINGMODE_SAAINVALID = 0
    # SAA Off
    CUBECOMPUTERCONTROLPROGRAM8_PST3SSAAWORKINGMODE_SAAOFF = 0
    # SAA On when Tracking
    CUBECOMPUTERCONTROLPROGRAM8_PST3SSAAWORKINGMODE_SAATRACKING = 0
    # SAA on when Capture
    CUBECOMPUTERCONTROLPROGRAM8_PST3SSAAWORKINGMODE_SAACAPTURE = 0
    # SAA on when Tracking and Capture
    CUBECOMPUTERCONTROLPROGRAM8_PST3SSAAWORKINGMODE_SAAALL = 0
class CubeComputerControlProgram8_AcpExecutionPoint(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_AcpExecutionPoint'
    """
    # Initialisation
    CUBECOMPUTERCONTROLPROGRAM8_ACPEXECUTIONPOINT_EXECPOINTINIT = 0
    # Idle
    CUBECOMPUTERCONTROLPROGRAM8_ACPEXECUTIONPOINT_EXECPOINTIDLE = 0
    # Sensor communication
    CUBECOMPUTERCONTROLPROGRAM8_ACPEXECUTIONPOINT_EXECPOINTSENSORCOMMS = 0
    # ADCS estimation update
    CUBECOMPUTERCONTROLPROGRAM8_ACPEXECUTIONPOINT_EXECPOINTADCSESTIMATION = 0
    # ADCS controller update
    CUBECOMPUTERCONTROLPROGRAM8_ACPEXECUTIONPOINT_EXECPOINTADCSCONTROLLER = 0
    # Reaction wheel communication
    CUBECOMPUTERCONTROLPROGRAM8_ACPEXECUTIONPOINT_EXECPOINTWHEELCOMMS = 0
    # ADCS models update
    CUBECOMPUTERCONTROLPROGRAM8_ACPEXECUTIONPOINT_EXECPOINTADCSMODELS = 0
    # Housekeeping
    CUBECOMPUTERCONTROLPROGRAM8_ACPEXECUTIONPOINT_EXECPOINTHOUSEKEEPING = 0
    # Telemetry logging
    CUBECOMPUTERCONTROLPROGRAM8_ACPEXECUTIONPOINT_EXECPOINTTLMLOG = 0
class CubeComputerControlProgram8_AdcsOpStateSelect(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_AdcsOpStateSelect'
    """
    # Manual operational state
    CUBECOMPUTERCONTROLPROGRAM8_ADCSOPSTATESELECT_OPSTATEMANUAL = 0
    # Autonomous operational state
    CUBECOMPUTERCONTROLPROGRAM8_ADCSOPSTATESELECT_OPSTATEAUTO = 0
    # Safe operational state
    CUBECOMPUTERCONTROLPROGRAM8_ADCSOPSTATESELECT_OPSTATESAFE = 0
    # Fault operational state
    CUBECOMPUTERCONTROLPROGRAM8_ADCSOPSTATESELECT_OPSTATEFAULT = 0
class CubeComputerControlProgram8_EstModeSelect(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_EstModeSelect'
    """
    # No estimator
    CUBECOMPUTERCONTROLPROGRAM8_ESTMODESELECT_ESTNONE = 0
    # Gyro measured rates
    CUBECOMPUTERCONTROLPROGRAM8_ESTMODESELECT_ESTGYRO = 0
    # Magnetometer estimated rates
    CUBECOMPUTERCONTROLPROGRAM8_ESTMODESELECT_ESTMAGRKF = 0
    # Magnetometer estimated rates with pitch estimation
    CUBECOMPUTERCONTROLPROGRAM8_ESTMODESELECT_ESTPITCHRKF = 0
    # Triad attitude estimation plus gyro rates
    CUBECOMPUTERCONTROLPROGRAM8_ESTMODESELECT_ESTTRIAD = 0
    # Full state EKF
    CUBECOMPUTERCONTROLPROGRAM8_ESTMODESELECT_ESTFULLEKF = 0
    # Gyro EKF for attitude and gyro bias estimation
    CUBECOMPUTERCONTROLPROGRAM8_ESTMODESELECT_ESTGYROEKF = 0
    # User coded estimator
    CUBECOMPUTERCONTROLPROGRAM8_ESTMODESELECT_ESTUSER = 0
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
class CubeComputerControlProgram8_Pst3sDynamicMode(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_Pst3sDynamicMode'
    """
    # Invalid Dynamic Mode. Depends on PST3S version.
    CUBECOMPUTERCONTROLPROGRAM8_PST3SDYNAMICMODE_DYNAMICMODEINVALID = 0
    # High Dynamic Mode
    CUBECOMPUTERCONTROLPROGRAM8_PST3SDYNAMICMODE_DYNAMICMODEHIGH = 0
    # Low Dynamic Mode
    CUBECOMPUTERCONTROLPROGRAM8_PST3SDYNAMICMODE_DYNAMICMODELOW = 0
class CubeComputerControlProgram8_FtpState(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_FtpState'
    """
    # No File Transfer in Progress
    CUBECOMPUTERCONTROLPROGRAM8_FTPSTATE_IDLE = 0
    # Initializing File Operation
    CUBECOMPUTERCONTROLPROGRAM8_FTPSTATE_INIT = 0
    # File Transfer is in Progress
    CUBECOMPUTERCONTROLPROGRAM8_FTPSTATE_BUSY = 0
    # File Transfer service is locked
    CUBECOMPUTERCONTROLPROGRAM8_FTPSTATE_LOCKED = 0
class CubeComputerControlProgram8_SunCaptureResult(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_SunCaptureResult'
    """
    # Initialized
    CUBECOMPUTERCONTROLPROGRAM8_SUNCAPTURERESULT_SUNCAPSTARTUP = 0
    # Issued but not complete
    CUBECOMPUTERCONTROLPROGRAM8_SUNCAPTURERESULT_SUNCAPPENDING = 0
    # Successful capture
    CUBECOMPUTERCONTROLPROGRAM8_SUNCAPTURERESULT_SUNCAPTURESUCCESSNORMAL = 0
    # Response Timeout
    CUBECOMPUTERCONTROLPROGRAM8_SUNCAPTURERESULT_SUNTIMEOUT = 0
    # Overcurrent Detected
    CUBECOMPUTERCONTROLPROGRAM8_SUNCAPTURERESULT_SUNSRAMERR = 0
    # Successful capture but result flipped
    CUBECOMPUTERCONTROLPROGRAM8_SUNCAPTURERESULT_SUNCAPTURESUCCESSFLIPPED = 0
class CubeComputerControlProgram8_FtpFileType(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_FtpFileType'
    """
    # Binary image file
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILETYPE_BIN = 0
    # Binary config file
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILETYPE_CFG = 0
    # Log file
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILETYPE_LOG = 0
    # Bitmap photo
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILETYPE_PHOTO = 0
    # General/internal-use
    CUBECOMPUTERCONTROLPROGRAM8_FTPFILETYPE_GENERAL = 0
class CubeComputerControlProgram8_SunDetectResult(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_SunDetectResult'
    """
    # Initialized
    CUBECOMPUTERCONTROLPROGRAM8_SUNDETECTRESULT_SUNDETSTARTUP = 0
    # Nothing Detected
    CUBECOMPUTERCONTROLPROGRAM8_SUNDETECTRESULT_SUNNODETECT = 0
    # Pending a result
    CUBECOMPUTERCONTROLPROGRAM8_SUNDETECTRESULT_SUNDETPENDING = 0
    # No Sun found
    CUBECOMPUTERCONTROLPROGRAM8_SUNDETECTRESULT_SUNNOTFOUND = 0
    # Sun detected
    CUBECOMPUTERCONTROLPROGRAM8_SUNDETECTRESULT_SUNSUCCESS = 0
class CubeComputerControlProgram8_StarIdStatus(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_StarIdStatus'
    """
    # Initialised
    CUBECOMPUTERCONTROLPROGRAM8_STARIDSTATUS_STARIDSTARTUP = 0
    # Identification scheduled
    CUBECOMPUTERCONTROLPROGRAM8_STARIDSTATUS_STARIDPENDING = 0
    # Identification in progress
    CUBECOMPUTERCONTROLPROGRAM8_STARIDSTATUS_STARIDBUSY = 0
    # Identification stopped because process took too long
    CUBECOMPUTERCONTROLPROGRAM8_STARIDSTATUS_STARIDABORT = 0
    # Identification stopped because there is not enough memory for match tables
    CUBECOMPUTERCONTROLPROGRAM8_STARIDSTATUS_STARIDOUTOFMEM = 0
    # Identification was not attempted because there are not enough detected stars
    CUBECOMPUTERCONTROLPROGRAM8_STARIDSTATUS_STARIDTOOFEW = 0
    # Identification failed because previously tracked stars could not be located
    CUBECOMPUTERCONTROLPROGRAM8_STARIDSTATUS_STARIDTRACKERR = 0
    # Identification completed
    CUBECOMPUTERCONTROLPROGRAM8_STARIDSTATUS_STARIDDONE = 0
class CubeComputerControlProgram8_RwlScheme(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_RwlScheme'
    """
    # RwlSchemeNoWheels
    CUBECOMPUTERCONTROLPROGRAM8_RWLSCHEME_RWLSCHEMENOWHEELS = 0
    # RwlSchemeYMomentum
    CUBECOMPUTERCONTROLPROGRAM8_RWLSCHEME_RWLSCHEMEYMOMENTUM = 0
    # RwlSchemeXYZ
    CUBECOMPUTERCONTROLPROGRAM8_RWLSCHEME_RWLSCHEMEXYZ = 0
    # RwlSchemePyramid
    CUBECOMPUTERCONTROLPROGRAM8_RWLSCHEME_RWLSCHEMEPYRAMID = 0
    # RwlSchemeTetrahedral
    CUBECOMPUTERCONTROLPROGRAM8_RWLSCHEME_RWLSCHEMETETRAHEDRAL = 0
class CubeComputerControlProgram8_InitState(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_InitState'
    """
    # Node is powered off
    CUBECOMPUTERCONTROLPROGRAM8_INITSTATE_INITOFF = 0
    # Node is being commanded to jump to its control-program
    CUBECOMPUTERCONTROLPROGRAM8_INITSTATE_INITJUMP = 0
    # Node control-program setup in progress
    CUBECOMPUTERCONTROLPROGRAM8_INITSTATE_INITSETUP = 0
    # Node initialization is complete. The control-program is running and ready for control
    CUBECOMPUTERCONTROLPROGRAM8_INITSTATE_INITDONE = 0
    # Node is powered on for passthrough and is not performing any tasks
    CUBECOMPUTERCONTROLPROGRAM8_INITSTATE_INITPASS = 0
    # Node is being used for upgrade - note that is any node bootloader is being upgraded, all nodes will be used since the whole bus is needed
    CUBECOMPUTERCONTROLPROGRAM8_INITSTATE_INITUPGRADE = 0
    # Enumeration max value (invalid)
    CUBECOMPUTERCONTROLPROGRAM8_INITSTATE_INITMAX = 0
class CubeComputerControlProgram8_MtqPolarity(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_MtqPolarity'
    """
    # Magnetorquer is off
    CUBECOMPUTERCONTROLPROGRAM8_MTQPOLARITY_MTQOFF = 0
    # Magnetorquer is on with positive polarity
    CUBECOMPUTERCONTROLPROGRAM8_MTQPOLARITY_MTQPOSITIVE = 0
    # Magnetorquer is on with negative polarity
    CUBECOMPUTERCONTROLPROGRAM8_MTQPOLARITY_MTQNEGATIVE = 0
class CubeComputerControlProgram8_VecSelect(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_VecSelect'
    """
    # Select magnetometer vector
    CUBECOMPUTERCONTROLPROGRAM8_VECSELECT_VECMAG = 0
    # Select fine sun sensor vector
    CUBECOMPUTERCONTROLPROGRAM8_VECSELECT_VECFSS = 0
    # Select coarse sun sensor vector
    CUBECOMPUTERCONTROLPROGRAM8_VECSELECT_VECCSS = 0
    # Select horizon (nadir) vector
    CUBECOMPUTERCONTROLPROGRAM8_VECSELECT_VECHSS = 0
class CubeComputerControlProgram8_MagSensingElementSelect(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_MagSensingElementSelect'
    """
    # Use the primary magnetometer sensing element on the CubeMag
    CUBECOMPUTERCONTROLPROGRAM8_MAGSENSINGELEMENTSELECT_MAGPRIMARY = 0
    # Use the redundant magnetometer sensing element on the CubeMag
    CUBECOMPUTERCONTROLPROGRAM8_MAGSENSINGELEMENTSELECT_MAGREDUNDANT = 0
class CubeComputerControlProgram8_AxisSelect(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_AxisSelect'
    """
    # Not Used
    CUBECOMPUTERCONTROLPROGRAM8_AXISSELECT_AXISNOTUSED = 0
    # Positive X
    CUBECOMPUTERCONTROLPROGRAM8_AXISSELECT_AXISPOSX = 0
    # Negative X
    CUBECOMPUTERCONTROLPROGRAM8_AXISSELECT_AXISNEGX = 0
    # Positive Y
    CUBECOMPUTERCONTROLPROGRAM8_AXISSELECT_AXISPOSY = 0
    # Negative Y
    CUBECOMPUTERCONTROLPROGRAM8_AXISSELECT_AXISNEGY = 0
    # Positive Z
    CUBECOMPUTERCONTROLPROGRAM8_AXISSELECT_AXISPOSZ = 0
    # Negative Z
    CUBECOMPUTERCONTROLPROGRAM8_AXISSELECT_AXISNEGZ = 0
    # Tetrahedral A
    CUBECOMPUTERCONTROLPROGRAM8_AXISSELECT_AXISTHDA = 0
    # Tetrahedral B
    CUBECOMPUTERCONTROLPROGRAM8_AXISSELECT_AXISTHDB = 0
    # Tetrahedral C
    CUBECOMPUTERCONTROLPROGRAM8_AXISSELECT_AXISTHDC = 0
    # Tetrahedral D
    CUBECOMPUTERCONTROLPROGRAM8_AXISSELECT_AXISTHDD = 0
    # Pyramid A
    CUBECOMPUTERCONTROLPROGRAM8_AXISSELECT_AXISPMDA = 0
    # Pyramid B
    CUBECOMPUTERCONTROLPROGRAM8_AXISSELECT_AXISPMDB = 0
    # Pyramid C
    CUBECOMPUTERCONTROLPROGRAM8_AXISSELECT_AXISPMDC = 0
    # Pyramid D
    CUBECOMPUTERCONTROLPROGRAM8_AXISSELECT_AXISPMDD = 0
    # Skewed 4th wheel at PosXYZ
    CUBECOMPUTERCONTROLPROGRAM8_AXISSELECT_AXISSKEW = 0
class CubeComputerControlProgram8_StarCaptureStatus(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_StarCaptureStatus'
    """
    # Initialised
    CUBECOMPUTERCONTROLPROGRAM8_STARCAPTURESTATUS_STARCAPTURESTARTUP = 0
    # Image capture scheduled
    CUBECOMPUTERCONTROLPROGRAM8_STARCAPTURESTATUS_STARCAPTUREPENDING = 0
    # Image capture in progress
    CUBECOMPUTERCONTROLPROGRAM8_STARCAPTURESTATUS_STARCAPTUREBUSY = 0
    # Successful capture
    CUBECOMPUTERCONTROLPROGRAM8_STARCAPTURESTATUS_STARCAPTUREDONE = 0
    # Camera error occurred
    CUBECOMPUTERCONTROLPROGRAM8_STARCAPTURESTATUS_STARCAPTUREERROR = 0
class CommonFrameworkTypes1_ProgramType(IntEnum):
    """
    Enumeration class definition for type 'CommonFrameworkTypes1_ProgramType'
    """
    # Invalid Program Type
    COMMONFRAMEWORKTYPES1_PROGRAMTYPE_PROGRAMTYPEINVALID = 0
    # control-program primary product application
    COMMONFRAMEWORKTYPES1_PROGRAMTYPE_PROGRAMTYPECONTROL = 0
    # cube-computer flash-bootloader Bootloader application
    COMMONFRAMEWORKTYPES1_PROGRAMTYPE_PROGRAMTYPEBOOTLOADER = 0
    # health-check Health Check application
    COMMONFRAMEWORKTYPES1_PROGRAMTYPE_PROGRAMTYPEHEALTHCHECK = 0
class CubeComputerControlProgram8_ConModeSelect(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_ConModeSelect'
    """
    # No control
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONNONE = 0
    # Single axis Bdot for detumbling
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONBDOT = 0
    # Y-Thomson spin
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONYSPIN = 0
    # 3-axis Bdot detumbling
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONBDOT3 = 0
    # 3-axis low power detumbling
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONDETUMBLE = 0
    # Sun Y-axis spin detumbling
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONSUNYSPIN = 0
    # Z-Thomson spin
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONZSPIN = 0
    # Sun Z-axis spin detumbling
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONSUNZSPIN = 0
    # Mag control of GG boom and yaw zero control
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONGGBOOM = 0
    # Mag control of GG boom and Z-RW yaw sun pointing
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONGGSUN = 0
    # Initial Y-wheel ramp to Y-Wheel control
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONYWHEELINIT = 0
    # Y-wheel pitch control
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONYWHEEL = 0
    # 3-axis reaction wheel control
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONXYZWHEEL = 0
    # RW sun tracking control
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONSUNTRACK = 0
    # RW EO target tracking control
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONTGTTRACK = 0
    # RW Earth target steering control
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONTGTSTEER = 0
    # RW G/S target tracking control
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONGNDTRACK = 0
    # RW Inertial target tracking control
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONIRCTRACK = 0
    # RW moon tracking control
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONMOONTRACK = 0
    # RW satellite target tracking control
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONSATTRACK = 0
    # Nadir pointing and yaw towards the sun
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONYAWSUN = 0
    # Nadir pointing and yaw towards ground target
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONYAWTARGET = 0
    # Velocity pointing and roll towards the sun
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONROLLSUN = 0
    # Velocity pointing and roll towards ground target
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONROLLTARGET = 0
    # Nadir pointing and yaw best +/-Y body axis to G/S
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONYAWTARGETBEST = 0
    # Forward Motion Compensation to scan target using +Z body axis
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONFMCTARGET = 0
    # RW sun yaw-spin control
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONYAWSUNSPIN = 0
    # RW detumbling to sun-pointing control
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONSUNDETUMBLE = 0
    # RW astronomical target tracking/steering with Zenith axis
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONASTROSTEER = 0
    # RW sun tracking and rotation for payload pointing to Zenith
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONSUNPAYLOAD = 0
    # Controlled stop of RWs
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONSTOPRW = 0
    # Open loop XYZ RW momentum command control
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONHXYZRW = 0
    # User coded control mode
    CUBECOMPUTERCONTROLPROGRAM8_CONMODESELECT_CONUSER = 0
class CubeComputerControlProgram8_EarthDetectResult(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_EarthDetectResult'
    """
    # Initialized
    CUBECOMPUTERCONTROLPROGRAM8_EARTHDETECTRESULT_EARTHDETSTARTUP = 0
    # Pending a result
    CUBECOMPUTERCONTROLPROGRAM8_EARTHDETECTRESULT_EARTHDETPENDING = 0
    # No horizon detected in field of view
    CUBECOMPUTERCONTROLPROGRAM8_EARTHDETECTRESULT_EARTHNOHORIZON = 0
    # Not enough edge points detected
    CUBECOMPUTERCONTROLPROGRAM8_EARTHDETECTRESULT_EARTHTOOFEWEDGES = 0
    # Failed to fit shape on horizon
    CUBECOMPUTERCONTROLPROGRAM8_EARTHDETECTRESULT_EARTHBADFIT = 0
    # Horizon detected
    CUBECOMPUTERCONTROLPROGRAM8_EARTHDETECTRESULT_EARTHSUCCESS = 0
class CubeComputerControlProgram8_Pst3sVersion(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_Pst3sVersion'
    """
    # PSST3S Version G2
    CUBECOMPUTERCONTROLPROGRAM8_PST3SVERSION_PST3SVERSIONG2 = 0
    # PSST3S Version H3
    CUBECOMPUTERCONTROLPROGRAM8_PST3SVERSION_PST3SVERSIONH3 = 0
class CubeComputerControlProgram8_FtpOpCode(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_FtpOpCode'
    """
    # No operation
    CUBECOMPUTERCONTROLPROGRAM8_FTPOPCODE_FTPNONE = 0
    # Cancel the Current Transfer
    CUBECOMPUTERCONTROLPROGRAM8_FTPOPCODE_FTPCANCEL = 0
    # Upload a File
    CUBECOMPUTERCONTROLPROGRAM8_FTPOPCODE_FTPUPLOAD = 0
    # Perform Upgrade with file
    CUBECOMPUTERCONTROLPROGRAM8_FTPOPCODE_FTPUPGRADE = 0
    # Erase the file
    CUBECOMPUTERCONTROLPROGRAM8_FTPOPCODE_FTPERASE = 0
    # Retrieve file information and cache it without other operations
    CUBECOMPUTERCONTROLPROGRAM8_FTPOPCODE_FTPINFO = 0
    # Format the filesystem. Effectively erase all files.
    CUBECOMPUTERCONTROLPROGRAM8_FTPOPCODE_FTPFORMAT = 0
class CubeComputerControlProgram8_FtpBackend(IntEnum):
    """
    Enumeration class definition for type 'CubeComputerControlProgram8_FtpBackend'
    """
    # FRAM Storage Medium
    CUBECOMPUTERCONTROLPROGRAM8_FTPBACKEND_BACKENDFRAM = 0
    # Node connected on internal bus
    CUBECOMPUTERCONTROLPROGRAM8_FTPBACKEND_BACKENDNODE = 0
class CmdTargetNode(IntEnum):
    """
    Enumeration class definition for type 'CmdTargetNode'
    """
    CMDTARGETNODE_NODEINVALID = 0
    CMDTARGETNODE_NODECOMPUTER = 0


# ********************************************************************************************
#
# Struct classes
#
# ********************************************************************************************
class TlmHssCubeSenseEarthHealth:
    """
    A Python class to represent struct objects of type 'TlmHssCubeSenseEarthHealth'
    
    Parameter structure for interface TlmHssCubeSenseEarthHealth
    """

    def __init__(self, double__Hss0McuTemp : float, double__Hss0McuCurrent : float, uint16__Hss0McuVoltage : int, double__Hss0DetectorTemp : float, double__Hss0DetectorCurrent : float, double__Hss1McuTemp : float, double__Hss1McuCurrent : float, uint16__Hss1McuVoltage : int, double__Hss1DetectorTemp : float, double__Hss1DetectorCurrent : float) -> None:
        """
        Struct 'TlmHssCubeSenseEarthHealth' constructor
        
        Attributes
        ---------
        double__Hss0McuTemp [1] : float
            HSS0 MCU Temperature
        double__Hss0McuCurrent [1] : float
            HSS0 MCU current
        uint16__Hss0McuVoltage [1] : int
            HSS0 MCU supply voltage
        double__Hss0DetectorTemp [1] : float
            HSS0 Detector Temperature
        double__Hss0DetectorCurrent [1] : float
            HSS0 Detector Current
        double__Hss1McuTemp [1] : float
            HSS1 MCU Temperature
        double__Hss1McuCurrent [1] : float
            HSS1 MCU current
        uint16__Hss1McuVoltage [1] : int
            HSS1 MCU supply voltage
        double__Hss1DetectorTemp [1] : float
            HSS1 Detector Temperature
        double__Hss1DetectorCurrent [1] : float
            HSS1 Detector Current
        """
        
        pass
        
    def get_Hss0McuTemp(self) -> float:
        """
        A getter for the 'TlmHssCubeSenseEarthHealth::Hss0McuTemp' structure field
        
        HSS0 MCU Temperature
        """
        
        pass
    
    def get_Hss0McuCurrent(self) -> float:
        """
        A getter for the 'TlmHssCubeSenseEarthHealth::Hss0McuCurrent' structure field
        
        HSS0 MCU current
        """
        
        pass
    
    def get_Hss0McuVoltage(self) -> int:
        """
        A getter for the 'TlmHssCubeSenseEarthHealth::Hss0McuVoltage' structure field
        
        HSS0 MCU supply voltage
        """
        
        pass
    
    def get_Hss0DetectorTemp(self) -> float:
        """
        A getter for the 'TlmHssCubeSenseEarthHealth::Hss0DetectorTemp' structure field
        
        HSS0 Detector Temperature
        """
        
        pass
    
    def get_Hss0DetectorCurrent(self) -> float:
        """
        A getter for the 'TlmHssCubeSenseEarthHealth::Hss0DetectorCurrent' structure field
        
        HSS0 Detector Current
        """
        
        pass
    
    def get_Hss1McuTemp(self) -> float:
        """
        A getter for the 'TlmHssCubeSenseEarthHealth::Hss1McuTemp' structure field
        
        HSS1 MCU Temperature
        """
        
        pass
    
    def get_Hss1McuCurrent(self) -> float:
        """
        A getter for the 'TlmHssCubeSenseEarthHealth::Hss1McuCurrent' structure field
        
        HSS1 MCU current
        """
        
        pass
    
    def get_Hss1McuVoltage(self) -> int:
        """
        A getter for the 'TlmHssCubeSenseEarthHealth::Hss1McuVoltage' structure field
        
        HSS1 MCU supply voltage
        """
        
        pass
    
    def get_Hss1DetectorTemp(self) -> float:
        """
        A getter for the 'TlmHssCubeSenseEarthHealth::Hss1DetectorTemp' structure field
        
        HSS1 Detector Temperature
        """
        
        pass
    
    def get_Hss1DetectorCurrent(self) -> float:
        """
        A getter for the 'TlmHssCubeSenseEarthHealth::Hss1DetectorCurrent' structure field
        
        HSS1 Detector Current
        """
        
        pass

def TlmHssCubeSenseEarthHealth_make_from_buf(buf : bytes) -> TlmHssCubeSenseEarthHealth:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmCubeMagHealth:
    """
    A Python class to represent struct objects of type 'TlmCubeMagHealth'
    
    Parameter structure for interface TlmCubeMagHealth
    """

    def __init__(self, double__Mag0McuTemp : float, double__Mag0McuCurrent : float, uint16__Mag0McuVoltage : int, double__Mag0PrimaryTemp : float, double__Mag0RedTemp : float, uint32__Mag0BurnCurrent : int, bool__Mag0DeployPinState : int, bool__Mag0BurnPinState : int, bool__Mag0BurnUnderCurrent : int, bool__Mag0BurnOverCurrent : int, bool__Mag0DeployTimeout : int, double__Mag1McuTemp : float, double__Mag1McuCurrent : float, uint16__Mag1McuVoltage : int, double__Mag1PrimaryTemp : float, double__Mag1RedTemp : float, uint32__Mag1BurnCurrent : int, bool__Mag1DeployPinState : int, bool__Mag1BurnPinState : int, bool__Mag1BurnUnderCurrent : int, bool__Mag1BurnOverCurrent : int, bool__Mag1DeployTimeout : int) -> None:
        """
        Struct 'TlmCubeMagHealth' constructor
        
        Attributes
        ---------
        double__Mag0McuTemp [1] : float
            MAG0 MCU Temperature
        double__Mag0McuCurrent [1] : float
            MAG0 MCU current
        uint16__Mag0McuVoltage [1] : int
            MAG0 MCU supply voltage
        double__Mag0PrimaryTemp [1] : float
            MAG0 Detector Temperature
        double__Mag0RedTemp [1] : float
            MAG0 Detector Current
        uint32__Mag0BurnCurrent [1] : int
            MAG0 Deploy Burn Current
        bool__Mag0DeployPinState [1] : int
            MAG0 Deploy Pin State
        bool__Mag0BurnPinState [1] : int
            MAG0 Burn Pin State
        bool__Mag0BurnUnderCurrent [1] : int
            MAG0 Burn Under Current Flag
        bool__Mag0BurnOverCurrent [1] : int
            MAG0 Burn Over Current Flag
        bool__Mag0DeployTimeout [1] : int
            MAG0 Deployment timeout Flag
        double__Mag1McuTemp [1] : float
            MAG1 MCU Temperature
        double__Mag1McuCurrent [1] : float
            MAG1 MCU current
        uint16__Mag1McuVoltage [1] : int
            MAG1 MCU supply voltage
        double__Mag1PrimaryTemp [1] : float
            MAG1 Detector Temperature
        double__Mag1RedTemp [1] : float
            MAG1 Detector Current
        uint32__Mag1BurnCurrent [1] : int
            MAG1 Deploy Burn Current
        bool__Mag1DeployPinState [1] : int
            MAG1 Deploy Pin State
        bool__Mag1BurnPinState [1] : int
            MAG1 Burn Pin State
        bool__Mag1BurnUnderCurrent [1] : int
            MAG1 Burn Under Current Flag
        bool__Mag1BurnOverCurrent [1] : int
            MAG1 Burn Over Current Flag
        bool__Mag1DeployTimeout [1] : int
            MAG1 Deployment timeout Flag
        """
        
        pass
        
    def get_Mag0McuTemp(self) -> float:
        """
        A getter for the 'TlmCubeMagHealth::Mag0McuTemp' structure field
        
        MAG0 MCU Temperature
        """
        
        pass
    
    def get_Mag0McuCurrent(self) -> float:
        """
        A getter for the 'TlmCubeMagHealth::Mag0McuCurrent' structure field
        
        MAG0 MCU current
        """
        
        pass
    
    def get_Mag0McuVoltage(self) -> int:
        """
        A getter for the 'TlmCubeMagHealth::Mag0McuVoltage' structure field
        
        MAG0 MCU supply voltage
        """
        
        pass
    
    def get_Mag0PrimaryTemp(self) -> float:
        """
        A getter for the 'TlmCubeMagHealth::Mag0PrimaryTemp' structure field
        
        MAG0 Detector Temperature
        """
        
        pass
    
    def get_Mag0RedTemp(self) -> float:
        """
        A getter for the 'TlmCubeMagHealth::Mag0RedTemp' structure field
        
        MAG0 Detector Current
        """
        
        pass
    
    def get_Mag0BurnCurrent(self) -> int:
        """
        A getter for the 'TlmCubeMagHealth::Mag0BurnCurrent' structure field
        
        MAG0 Deploy Burn Current
        """
        
        pass
    
    def get_Mag0DeployPinState(self) -> int:
        """
        A getter for the 'TlmCubeMagHealth::Mag0DeployPinState' structure field
        
        MAG0 Deploy Pin State
        """
        
        pass
    
    def get_Mag0BurnPinState(self) -> int:
        """
        A getter for the 'TlmCubeMagHealth::Mag0BurnPinState' structure field
        
        MAG0 Burn Pin State
        """
        
        pass
    
    def get_Mag0BurnUnderCurrent(self) -> int:
        """
        A getter for the 'TlmCubeMagHealth::Mag0BurnUnderCurrent' structure field
        
        MAG0 Burn Under Current Flag
        """
        
        pass
    
    def get_Mag0BurnOverCurrent(self) -> int:
        """
        A getter for the 'TlmCubeMagHealth::Mag0BurnOverCurrent' structure field
        
        MAG0 Burn Over Current Flag
        """
        
        pass
    
    def get_Mag0DeployTimeout(self) -> int:
        """
        A getter for the 'TlmCubeMagHealth::Mag0DeployTimeout' structure field
        
        MAG0 Deployment timeout Flag
        """
        
        pass
    
    def get_Mag1McuTemp(self) -> float:
        """
        A getter for the 'TlmCubeMagHealth::Mag1McuTemp' structure field
        
        MAG1 MCU Temperature
        """
        
        pass
    
    def get_Mag1McuCurrent(self) -> float:
        """
        A getter for the 'TlmCubeMagHealth::Mag1McuCurrent' structure field
        
        MAG1 MCU current
        """
        
        pass
    
    def get_Mag1McuVoltage(self) -> int:
        """
        A getter for the 'TlmCubeMagHealth::Mag1McuVoltage' structure field
        
        MAG1 MCU supply voltage
        """
        
        pass
    
    def get_Mag1PrimaryTemp(self) -> float:
        """
        A getter for the 'TlmCubeMagHealth::Mag1PrimaryTemp' structure field
        
        MAG1 Detector Temperature
        """
        
        pass
    
    def get_Mag1RedTemp(self) -> float:
        """
        A getter for the 'TlmCubeMagHealth::Mag1RedTemp' structure field
        
        MAG1 Detector Current
        """
        
        pass
    
    def get_Mag1BurnCurrent(self) -> int:
        """
        A getter for the 'TlmCubeMagHealth::Mag1BurnCurrent' structure field
        
        MAG1 Deploy Burn Current
        """
        
        pass
    
    def get_Mag1DeployPinState(self) -> int:
        """
        A getter for the 'TlmCubeMagHealth::Mag1DeployPinState' structure field
        
        MAG1 Deploy Pin State
        """
        
        pass
    
    def get_Mag1BurnPinState(self) -> int:
        """
        A getter for the 'TlmCubeMagHealth::Mag1BurnPinState' structure field
        
        MAG1 Burn Pin State
        """
        
        pass
    
    def get_Mag1BurnUnderCurrent(self) -> int:
        """
        A getter for the 'TlmCubeMagHealth::Mag1BurnUnderCurrent' structure field
        
        MAG1 Burn Under Current Flag
        """
        
        pass
    
    def get_Mag1BurnOverCurrent(self) -> int:
        """
        A getter for the 'TlmCubeMagHealth::Mag1BurnOverCurrent' structure field
        
        MAG1 Burn Over Current Flag
        """
        
        pass
    
    def get_Mag1DeployTimeout(self) -> int:
        """
        A getter for the 'TlmCubeMagHealth::Mag1DeployTimeout' structure field
        
        MAG1 Deployment timeout Flag
        """
        
        pass

def TlmCubeMagHealth_make_from_buf(buf : bytes) -> TlmCubeMagHealth:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ReferenceRpy:
    """
    A Python class to represent struct objects of type 'ReferenceRpy'
    
    Parameter structure for interface ReferenceRpy
    """

    def __init__(self, float__CmdRpyRoll : float, float__CmdRpyPitch : float, float__CmdRpyYaw : float) -> None:
        """
        Struct 'ReferenceRpy' constructor
        
        Attributes
        ---------
        float__CmdRpyRoll [1] : float
            RPY Roll command
        float__CmdRpyPitch [1] : float
            RPY Pitch command
        float__CmdRpyYaw [1] : float
            RPY Yaw command
        """
        
        pass
        
    def get_CmdRpyRoll(self) -> float:
        """
        A getter for the 'ReferenceRpy::CmdRpyRoll' structure field
        
        RPY Roll command
        """
        
        pass
    
    def get_CmdRpyPitch(self) -> float:
        """
        A getter for the 'ReferenceRpy::CmdRpyPitch' structure field
        
        RPY Pitch command
        """
        
        pass
    
    def get_CmdRpyYaw(self) -> float:
        """
        A getter for the 'ReferenceRpy::CmdRpyYaw' structure field
        
        RPY Yaw command
        """
        
        pass

def ReferenceRpy_make_from_buf(buf : bytes) -> ReferenceRpy:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmSensorCalFss:
    """
    A Python class to represent struct objects of type 'TlmSensorCalFss'
    
    Parameter structure for interface TlmSensorCalFss
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, double__Fss0CalVecX : float, double__Fss0CalVecY : float, double__Fss0CalVecZ : float, double__Fss1CalVecX : float, double__Fss1CalVecY : float, double__Fss1CalVecZ : float, double__Fss2CalVecX : float, double__Fss2CalVecY : float, double__Fss2CalVecZ : float, double__Fss3CalVecX : float, double__Fss3CalVecY : float, double__Fss3CalVecZ : float, bool__Fss0IsValid : int, bool__Fss1IsValid : int, bool__Fss2IsValid : int, bool__Fss3IsValid : int, bool__Fss0IsBest : int, bool__Fss1IsBest : int, bool__Fss2IsBest : int, bool__Fss3IsBest : int) -> None:
        """
        Struct 'TlmSensorCalFss' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        double__Fss0CalVecX [1] : float
            FSS0 calibrated unit vector X component
        double__Fss0CalVecY [1] : float
            FSS0 calibrated unit vector Y component
        double__Fss0CalVecZ [1] : float
            FSS0 calibrated unit vector Z component
        double__Fss1CalVecX [1] : float
            FSS1 calibrated unit vector X component
        double__Fss1CalVecY [1] : float
            FSS1 calibrated unit vector Y component
        double__Fss1CalVecZ [1] : float
            FSS1 calibrated unit vector Z component
        double__Fss2CalVecX [1] : float
            FSS2 calibrated unit vector X component
        double__Fss2CalVecY [1] : float
            FSS2 calibrated unit vector Y component
        double__Fss2CalVecZ [1] : float
            FSS2 calibrated unit vector Z component
        double__Fss3CalVecX [1] : float
            FSS3 calibrated unit vector X component
        double__Fss3CalVecY [1] : float
            FSS3 calibrated unit vector Y component
        double__Fss3CalVecZ [1] : float
            FSS3 calibrated unit vector Z component
        bool__Fss0IsValid [1] : int
            FSS0 valid flag
        bool__Fss1IsValid [1] : int
            FSS1 valid flag
        bool__Fss2IsValid [1] : int
            FSS2 valid flag
        bool__Fss3IsValid [1] : int
            FSS3 valid flag
        bool__Fss0IsBest [1] : int
            FSS0 best for estimators flag
        bool__Fss1IsBest [1] : int
            FSS1 best for estimators flag
        bool__Fss2IsBest [1] : int
            FSS2 best for estimators flag
        bool__Fss3IsBest [1] : int
            FSS3 best for estimators flag
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmSensorCalFss::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmSensorCalFss::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_Fss0CalVecX(self) -> float:
        """
        A getter for the 'TlmSensorCalFss::Fss0CalVecX' structure field
        
        FSS0 calibrated unit vector X component
        """
        
        pass
    
    def get_Fss0CalVecY(self) -> float:
        """
        A getter for the 'TlmSensorCalFss::Fss0CalVecY' structure field
        
        FSS0 calibrated unit vector Y component
        """
        
        pass
    
    def get_Fss0CalVecZ(self) -> float:
        """
        A getter for the 'TlmSensorCalFss::Fss0CalVecZ' structure field
        
        FSS0 calibrated unit vector Z component
        """
        
        pass
    
    def get_Fss1CalVecX(self) -> float:
        """
        A getter for the 'TlmSensorCalFss::Fss1CalVecX' structure field
        
        FSS1 calibrated unit vector X component
        """
        
        pass
    
    def get_Fss1CalVecY(self) -> float:
        """
        A getter for the 'TlmSensorCalFss::Fss1CalVecY' structure field
        
        FSS1 calibrated unit vector Y component
        """
        
        pass
    
    def get_Fss1CalVecZ(self) -> float:
        """
        A getter for the 'TlmSensorCalFss::Fss1CalVecZ' structure field
        
        FSS1 calibrated unit vector Z component
        """
        
        pass
    
    def get_Fss2CalVecX(self) -> float:
        """
        A getter for the 'TlmSensorCalFss::Fss2CalVecX' structure field
        
        FSS2 calibrated unit vector X component
        """
        
        pass
    
    def get_Fss2CalVecY(self) -> float:
        """
        A getter for the 'TlmSensorCalFss::Fss2CalVecY' structure field
        
        FSS2 calibrated unit vector Y component
        """
        
        pass
    
    def get_Fss2CalVecZ(self) -> float:
        """
        A getter for the 'TlmSensorCalFss::Fss2CalVecZ' structure field
        
        FSS2 calibrated unit vector Z component
        """
        
        pass
    
    def get_Fss3CalVecX(self) -> float:
        """
        A getter for the 'TlmSensorCalFss::Fss3CalVecX' structure field
        
        FSS3 calibrated unit vector X component
        """
        
        pass
    
    def get_Fss3CalVecY(self) -> float:
        """
        A getter for the 'TlmSensorCalFss::Fss3CalVecY' structure field
        
        FSS3 calibrated unit vector Y component
        """
        
        pass
    
    def get_Fss3CalVecZ(self) -> float:
        """
        A getter for the 'TlmSensorCalFss::Fss3CalVecZ' structure field
        
        FSS3 calibrated unit vector Z component
        """
        
        pass
    
    def get_Fss0IsValid(self) -> int:
        """
        A getter for the 'TlmSensorCalFss::Fss0IsValid' structure field
        
        FSS0 valid flag
        """
        
        pass
    
    def get_Fss1IsValid(self) -> int:
        """
        A getter for the 'TlmSensorCalFss::Fss1IsValid' structure field
        
        FSS1 valid flag
        """
        
        pass
    
    def get_Fss2IsValid(self) -> int:
        """
        A getter for the 'TlmSensorCalFss::Fss2IsValid' structure field
        
        FSS2 valid flag
        """
        
        pass
    
    def get_Fss3IsValid(self) -> int:
        """
        A getter for the 'TlmSensorCalFss::Fss3IsValid' structure field
        
        FSS3 valid flag
        """
        
        pass
    
    def get_Fss0IsBest(self) -> int:
        """
        A getter for the 'TlmSensorCalFss::Fss0IsBest' structure field
        
        FSS0 best for estimators flag
        """
        
        pass
    
    def get_Fss1IsBest(self) -> int:
        """
        A getter for the 'TlmSensorCalFss::Fss1IsBest' structure field
        
        FSS1 best for estimators flag
        """
        
        pass
    
    def get_Fss2IsBest(self) -> int:
        """
        A getter for the 'TlmSensorCalFss::Fss2IsBest' structure field
        
        FSS2 best for estimators flag
        """
        
        pass
    
    def get_Fss3IsBest(self) -> int:
        """
        A getter for the 'TlmSensorCalFss::Fss3IsBest' structure field
        
        FSS3 best for estimators flag
        """
        
        pass

def TlmSensorCalFss_make_from_buf(buf : bytes) -> TlmSensorCalFss:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class DeployCommandMag:
    """
    A Python class to represent struct objects of type 'DeployCommandMag'
    
    Parameter structure for interface DeployCommandMag
    """

    def __init__(self, bool__DeployMag0 : int, bool__DeployMag1 : int) -> None:
        """
        Struct 'DeployCommandMag' constructor
        
        Attributes
        ---------
        bool__DeployMag0 [1] : int
            Deploy MAG0
        bool__DeployMag1 [1] : int
            Deploy MAG1
        """
        
        pass
        
    def get_DeployMag0(self) -> int:
        """
        A getter for the 'DeployCommandMag::DeployMag0' structure field
        
        Deploy MAG0
        """
        
        pass
    
    def get_DeployMag1(self) -> int:
        """
        A getter for the 'DeployCommandMag::DeployMag1' structure field
        
        Deploy MAG1
        """
        
        pass

def DeployCommandMag_make_from_buf(buf : bytes) -> DeployCommandMag:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class SimSensorRaw:
    """
    A Python class to represent struct objects of type 'SimSensorRaw'
    
    Parameter structure for interface SimSensorRaw
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, double__Fss0RawCenX : float, double__Fss0RawCenY : float, double__Fss1RawCenX : float, double__Fss1RawCenY : float, double__Fss2RawCenX : float, double__Fss2RawCenY : float, double__Fss3RawCenX : float, double__Fss3RawCenY : float, uint16__Css0Raw : int, uint16__Css1Raw : int, uint16__Css2Raw : int, uint16__Css3Raw : int, uint16__Css4Raw : int, uint16__Css5Raw : int, uint16__Css6Raw : int, uint16__Css7Raw : int, uint16__Css8Raw : int, uint16__Css9Raw : int, double__Mag0RawVecX : float, double__Mag0RawVecY : float, double__Mag0RawVecZ : float, double__Mag1RawVecX : float, double__Mag1RawVecY : float, double__Mag1RawVecZ : float, float__Gyro0RawRateX : float, float__Gyro0RawRateY : float, float__Gyro0RawRateZ : float, float__Gyro1RawRateX : float, float__Gyro1RawRateY : float, float__Gyro1RawRateZ : float, double__Hss0RawElev : float, double__Hss0RawRot : float, double__Hss1RawElev : float, double__Hss1RawRot : float, double__Str0MeasVec0X : float, double__Str0MeasVec0Y : float, double__Str0MeasVec0Z : float, double__Str0MeasVec1X : float, double__Str0MeasVec1Y : float, double__Str0MeasVec1Z : float, double__Str0MeasVec2X : float, double__Str0MeasVec2Y : float, double__Str0MeasVec2Z : float, double__Str0ModelVec0X : float, double__Str0ModelVec0Y : float, double__Str0ModelVec0Z : float, double__Str0ModelVec1X : float, double__Str0ModelVec1Y : float, double__Str0ModelVec1Z : float, double__Str0ModelVec2X : float, double__Str0ModelVec2Y : float, double__Str0ModelVec2Z : float, double__Str0MeasQ0 : float, double__Str0MeasQ1 : float, double__Str0MeasQ2 : float, double__Str0MeasQ3 : float, uint8__Str0StarIdCount : int, double__Str1MeasVec0X : float, double__Str1MeasVec0Y : float, double__Str1MeasVec0Z : float, double__Str1MeasVec1X : float, double__Str1MeasVec1Y : float, double__Str1MeasVec1Z : float, double__Str1MeasVec2X : float, double__Str1MeasVec2Y : float, double__Str1MeasVec2Z : float, double__Str1ModelVec0X : float, double__Str1ModelVec0Y : float, double__Str1ModelVec0Z : float, double__Str1ModelVec1X : float, double__Str1ModelVec1Y : float, double__Str1ModelVec1Z : float, double__Str1ModelVec2X : float, double__Str1ModelVec2Y : float, double__Str1ModelVec2Z : float, double__Str1MeasQ0 : float, double__Str1MeasQ1 : float, double__Str1MeasQ2 : float, double__Str1MeasQ3 : float, uint8__Str1StarIdCount : int, uint32__GnssTimeSeconds : int, uint32__GnssTimeNs : int, int32__GnssSatPosX : int, int32__GnssSatPosY : int, int32__GnssSatPosZ : int, int32__GnssSatVelX : int, int32__GnssSatVelY : int, int32__GnssSatVelZ : int, float__ExtSensor0Float0 : float, float__ExtSensor0Float1 : float, float__ExtSensor0Float2 : float, float__ExtSensor0Float3 : float, float__ExtSensor0Float4 : float, float__ExtSensor0Float5 : float, float__ExtSensor1Float0 : float, float__ExtSensor1Float1 : float, float__ExtSensor1Float2 : float, float__ExtSensor1Float3 : float, float__ExtSensor1Float4 : float, float__ExtSensor1Float5 : float, float__Rwl0SpeedMeas : float, float__Rwl1SpeedMeas : float, float__Rwl2SpeedMeas : float, float__Rwl3SpeedMeas : float, bool__Fss0IsValid : int, bool__Fss1IsValid : int, bool__Fss2IsValid : int, bool__Fss3IsValid : int, bool__CssIsValid : int, bool__Mag0IsValid : int, bool__Mag1IsValid : int, bool__Gyro0IsValid : int, bool__Gyro1IsValid : int, bool__Hss0IsValid : int, bool__Hss1IsValid : int, bool__Str0IsValid : int, bool__Str1IsValid : int, bool__GnssIsValid : int, bool__GnssIsNew : int, bool__ExtSensor0IsValid : int, bool__ExtSensor1IsValid : int, bool__Rwl0IsValid : int, bool__Rwl1IsValid : int, bool__Rwl2IsValid : int, bool__Rwl3IsValid : int) -> None:
        """
        Struct 'SimSensorRaw' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        double__Fss0RawCenX [1] : float
            FSS0 raw centroid X
        double__Fss0RawCenY [1] : float
            FSS0 raw centroid Y
        double__Fss1RawCenX [1] : float
            FSS1 raw centroid X
        double__Fss1RawCenY [1] : float
            FSS1 raw centroid Y
        double__Fss2RawCenX [1] : float
            FSS2 raw centroid X
        double__Fss2RawCenY [1] : float
            FSS2 raw centroid Y
        double__Fss3RawCenX [1] : float
            FSS3 raw centroid X
        double__Fss3RawCenY [1] : float
            FSS3 raw centroid Y
        uint16__Css0Raw [1] : int
            CSS0 raw measurement
        uint16__Css1Raw [1] : int
            CSS1 raw measurement
        uint16__Css2Raw [1] : int
            CSS2 raw measurement
        uint16__Css3Raw [1] : int
            CSS3 raw measurement
        uint16__Css4Raw [1] : int
            CSS4 raw measurement
        uint16__Css5Raw [1] : int
            CSS5 raw measurement
        uint16__Css6Raw [1] : int
            CSS6 raw measurement
        uint16__Css7Raw [1] : int
            CSS7 raw measurement
        uint16__Css8Raw [1] : int
            CSS8 raw measurement
        uint16__Css9Raw [1] : int
            CSS9 raw measurement
        double__Mag0RawVecX [1] : float
            MAG0 raw vector X component
        double__Mag0RawVecY [1] : float
            MAG0 raw vector Y component
        double__Mag0RawVecZ [1] : float
            MAG0 raw vector Z component
        double__Mag1RawVecX [1] : float
            MAG1 raw vector X component
        double__Mag1RawVecY [1] : float
            MAG1 raw vector Y component
        double__Mag1RawVecZ [1] : float
            MAG1 raw vector Z component
        float__Gyro0RawRateX [1] : float
            GYR0 raw rate X component
        float__Gyro0RawRateY [1] : float
            GYR0 raw rate Y component
        float__Gyro0RawRateZ [1] : float
            GYR0 raw rate Z component
        float__Gyro1RawRateX [1] : float
            GYR1 raw rate X component
        float__Gyro1RawRateY [1] : float
            GYR1 raw rate Y component
        float__Gyro1RawRateZ [1] : float
            GYR1 raw rate Z component
        double__Hss0RawElev [1] : float
            HSS0 raw elevation angle
        double__Hss0RawRot [1] : float
            HSS0 raw rotation angle
        double__Hss1RawElev [1] : float
            HSS1 raw elevation angle
        double__Hss1RawRot [1] : float
            HSS1 raw rotation angle
        double__Str0MeasVec0X [1] : float
            STR0 measured vector 0 X component (sensor frame)
        double__Str0MeasVec0Y [1] : float
            STR0 measured vector 0 Y component (sensor frame)
        double__Str0MeasVec0Z [1] : float
            STR0 measured vector 0 Z component (sensor frame)
        double__Str0MeasVec1X [1] : float
            STR0 measured vector 1 X component (sensor frame)
        double__Str0MeasVec1Y [1] : float
            STR0 measured vector 1 Y component (sensor frame)
        double__Str0MeasVec1Z [1] : float
            STR0 measured vector 1 Z component (sensor frame)
        double__Str0MeasVec2X [1] : float
            STR0 measured vector 2 X component (sensor frame)
        double__Str0MeasVec2Y [1] : float
            STR0 measured vector 2 Y component (sensor frame)
        double__Str0MeasVec2Z [1] : float
            STR0 measured vector 2 Z component (sensor frame)
        double__Str0ModelVec0X [1] : float
            STR0 modelled vector 0 X component (IRC frame)
        double__Str0ModelVec0Y [1] : float
            STR0 modelled vector 0 Y component (IRC frame)
        double__Str0ModelVec0Z [1] : float
            STR0 modelled vector 0 Z component (IRC frame)
        double__Str0ModelVec1X [1] : float
            STR0 modelled vector 1 X component (IRC frame)
        double__Str0ModelVec1Y [1] : float
            STR0 modelled vector 1 Y component (IRC frame)
        double__Str0ModelVec1Z [1] : float
            STR0 modelled vector 1 Z component (IRC frame)
        double__Str0ModelVec2X [1] : float
            STR0 modelled vector 2 X component (IRC frame)
        double__Str0ModelVec2Y [1] : float
            STR0 modelled vector 2 Y component (IRC frame)
        double__Str0ModelVec2Z [1] : float
            STR0 modelled vector 2 Z component (IRC frame)
        double__Str0MeasQ0 [1] : float
            STR0 measured quaternion Q0 (sensor to IRC frame)
        double__Str0MeasQ1 [1] : float
            STR0 measured quaternion Q1 (sensor to IRC frame)
        double__Str0MeasQ2 [1] : float
            STR0 measured quaternion Q2 (sensor to IRC frame)
        double__Str0MeasQ3 [1] : float
            STR0 measured quaternion Q3 (sensor to IRC frame)
        uint8__Str0StarIdCount [1] : int
            STR0 number of identified stars
        double__Str1MeasVec0X [1] : float
            STR1 measured vector 0 X component (sensor frame)
        double__Str1MeasVec0Y [1] : float
            STR1 measured vector 0 Y component (sensor frame)
        double__Str1MeasVec0Z [1] : float
            STR1 measured vector 0 Z component (sensor frame)
        double__Str1MeasVec1X [1] : float
            STR1 measured vector 1 X component (sensor frame)
        double__Str1MeasVec1Y [1] : float
            STR1 measured vector 1 Y component (sensor frame)
        double__Str1MeasVec1Z [1] : float
            STR1 measured vector 1 Z component (sensor frame)
        double__Str1MeasVec2X [1] : float
            STR1 measured vector 2 X component (sensor frame)
        double__Str1MeasVec2Y [1] : float
            STR1 measured vector 2 Y component (sensor frame)
        double__Str1MeasVec2Z [1] : float
            STR1 measured vector 2 Z component (sensor frame)
        double__Str1ModelVec0X [1] : float
            STR1 modelled vector 0 X component (IRC frame)
        double__Str1ModelVec0Y [1] : float
            STR1 modelled vector 0 Y component (IRC frame)
        double__Str1ModelVec0Z [1] : float
            STR1 modelled vector 0 Z component (IRC frame)
        double__Str1ModelVec1X [1] : float
            STR1 modelled vector 1 X component (IRC frame)
        double__Str1ModelVec1Y [1] : float
            STR1 modelled vector 1 Y component (IRC frame)
        double__Str1ModelVec1Z [1] : float
            STR1 modelled vector 1 Z component (IRC frame)
        double__Str1ModelVec2X [1] : float
            STR1 modelled vector 2 X component (IRC frame)
        double__Str1ModelVec2Y [1] : float
            STR1 modelled vector 2 Y component (IRC frame)
        double__Str1ModelVec2Z [1] : float
            STR1 modelled vector 2 Z component (IRC frame)
        double__Str1MeasQ0 [1] : float
            STR1 measured quaternion Q0 (sensor to IRC frame)
        double__Str1MeasQ1 [1] : float
            STR1 measured quaternion Q1 (sensor to IRC frame)
        double__Str1MeasQ2 [1] : float
            STR1 measured quaternion Q2 (sensor to IRC frame)
        double__Str1MeasQ3 [1] : float
            STR1 measured quaternion Q3 (sensor to IRC frame)
        uint8__Str1StarIdCount [1] : int
            STR1 number of identified stars
        uint32__GnssTimeSeconds [1] : int
            GNSS Unix time integer seconds
        uint32__GnssTimeNs [1] : int
            GNSS Unix time fraction nanoseconds
        int32__GnssSatPosX [1] : int
            Satellite position vector X component (GNSS frame)
        int32__GnssSatPosY [1] : int
            Satellite position vector Y component (GNSS frame)
        int32__GnssSatPosZ [1] : int
            Satellite position vector Z component (GNSS frame)
        int32__GnssSatVelX [1] : int
            Satellite velocity vector X component (GNSS frame)
        int32__GnssSatVelY [1] : int
            Satellite velocity vector Y component (GNSS frame)
        int32__GnssSatVelZ [1] : int
            Satellite velocity vector Z component (GNSS frame)
        float__ExtSensor0Float0 [1] : float
            ExtSensor0 raw measurement float 0
        float__ExtSensor0Float1 [1] : float
            ExtSensor0 raw measurement float 1
        float__ExtSensor0Float2 [1] : float
            ExtSensor0 raw measurement float 2
        float__ExtSensor0Float3 [1] : float
            ExtSensor0 raw measurement float 3
        float__ExtSensor0Float4 [1] : float
            ExtSensor0 raw measurement float 4
        float__ExtSensor0Float5 [1] : float
            ExtSensor0 raw measurement float 5
        float__ExtSensor1Float0 [1] : float
            ExtSensor1 raw measurement float 0
        float__ExtSensor1Float1 [1] : float
            ExtSensor1 raw measurement float 1
        float__ExtSensor1Float2 [1] : float
            ExtSensor1 raw measurement float 2
        float__ExtSensor1Float3 [1] : float
            ExtSensor1 raw measurement float 3
        float__ExtSensor1Float4 [1] : float
            ExtSensor1 raw measurement float 4
        float__ExtSensor1Float5 [1] : float
            ExtSensor1 raw measurement float 5
        float__Rwl0SpeedMeas [1] : float
            RWL0 raw speed measurement
        float__Rwl1SpeedMeas [1] : float
            RWL1 raw speed measurement
        float__Rwl2SpeedMeas [1] : float
            RWL2 raw speed measurement
        float__Rwl3SpeedMeas [1] : float
            RWL3 raw speed measurement
        bool__Fss0IsValid [1] : int
            FSS0 valid flag
        bool__Fss1IsValid [1] : int
            FSS1 valid flag
        bool__Fss2IsValid [1] : int
            FSS2 valid flag
        bool__Fss3IsValid [1] : int
            FSS3 valid flag
        bool__CssIsValid [1] : int
            CSS valid flag
        bool__Mag0IsValid [1] : int
            MAG0 valid flag
        bool__Mag1IsValid [1] : int
            MAG1 valid flag
        bool__Gyro0IsValid [1] : int
            GYR0 valid flag
        bool__Gyro1IsValid [1] : int
            GYR1 valid flag
        bool__Hss0IsValid [1] : int
            HSS0 valid flag
        bool__Hss1IsValid [1] : int
            HSS1 valid flag
        bool__Str0IsValid [1] : int
            STR0 valid flag
        bool__Str1IsValid [1] : int
            STR1 valid flag
        bool__GnssIsValid [1] : int
            GNSS valid flag
        bool__GnssIsNew [1] : int
            GNSS new flag
        bool__ExtSensor0IsValid [1] : int
            ExtSensor0 valid flag
        bool__ExtSensor1IsValid [1] : int
            ExtSensor1 valid flag
        bool__Rwl0IsValid [1] : int
            RWL0 valid flag
        bool__Rwl1IsValid [1] : int
            RWL1 valid flag
        bool__Rwl2IsValid [1] : int
            RWL2 valid flag
        bool__Rwl3IsValid [1] : int
            RWL3 valid flag
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'SimSensorRaw::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'SimSensorRaw::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_Fss0RawCenX(self) -> float:
        """
        A getter for the 'SimSensorRaw::Fss0RawCenX' structure field
        
        FSS0 raw centroid X
        """
        
        pass
    
    def get_Fss0RawCenY(self) -> float:
        """
        A getter for the 'SimSensorRaw::Fss0RawCenY' structure field
        
        FSS0 raw centroid Y
        """
        
        pass
    
    def get_Fss1RawCenX(self) -> float:
        """
        A getter for the 'SimSensorRaw::Fss1RawCenX' structure field
        
        FSS1 raw centroid X
        """
        
        pass
    
    def get_Fss1RawCenY(self) -> float:
        """
        A getter for the 'SimSensorRaw::Fss1RawCenY' structure field
        
        FSS1 raw centroid Y
        """
        
        pass
    
    def get_Fss2RawCenX(self) -> float:
        """
        A getter for the 'SimSensorRaw::Fss2RawCenX' structure field
        
        FSS2 raw centroid X
        """
        
        pass
    
    def get_Fss2RawCenY(self) -> float:
        """
        A getter for the 'SimSensorRaw::Fss2RawCenY' structure field
        
        FSS2 raw centroid Y
        """
        
        pass
    
    def get_Fss3RawCenX(self) -> float:
        """
        A getter for the 'SimSensorRaw::Fss3RawCenX' structure field
        
        FSS3 raw centroid X
        """
        
        pass
    
    def get_Fss3RawCenY(self) -> float:
        """
        A getter for the 'SimSensorRaw::Fss3RawCenY' structure field
        
        FSS3 raw centroid Y
        """
        
        pass
    
    def get_Css0Raw(self) -> int:
        """
        A getter for the 'SimSensorRaw::Css0Raw' structure field
        
        CSS0 raw measurement
        """
        
        pass
    
    def get_Css1Raw(self) -> int:
        """
        A getter for the 'SimSensorRaw::Css1Raw' structure field
        
        CSS1 raw measurement
        """
        
        pass
    
    def get_Css2Raw(self) -> int:
        """
        A getter for the 'SimSensorRaw::Css2Raw' structure field
        
        CSS2 raw measurement
        """
        
        pass
    
    def get_Css3Raw(self) -> int:
        """
        A getter for the 'SimSensorRaw::Css3Raw' structure field
        
        CSS3 raw measurement
        """
        
        pass
    
    def get_Css4Raw(self) -> int:
        """
        A getter for the 'SimSensorRaw::Css4Raw' structure field
        
        CSS4 raw measurement
        """
        
        pass
    
    def get_Css5Raw(self) -> int:
        """
        A getter for the 'SimSensorRaw::Css5Raw' structure field
        
        CSS5 raw measurement
        """
        
        pass
    
    def get_Css6Raw(self) -> int:
        """
        A getter for the 'SimSensorRaw::Css6Raw' structure field
        
        CSS6 raw measurement
        """
        
        pass
    
    def get_Css7Raw(self) -> int:
        """
        A getter for the 'SimSensorRaw::Css7Raw' structure field
        
        CSS7 raw measurement
        """
        
        pass
    
    def get_Css8Raw(self) -> int:
        """
        A getter for the 'SimSensorRaw::Css8Raw' structure field
        
        CSS8 raw measurement
        """
        
        pass
    
    def get_Css9Raw(self) -> int:
        """
        A getter for the 'SimSensorRaw::Css9Raw' structure field
        
        CSS9 raw measurement
        """
        
        pass
    
    def get_Mag0RawVecX(self) -> float:
        """
        A getter for the 'SimSensorRaw::Mag0RawVecX' structure field
        
        MAG0 raw vector X component
        """
        
        pass
    
    def get_Mag0RawVecY(self) -> float:
        """
        A getter for the 'SimSensorRaw::Mag0RawVecY' structure field
        
        MAG0 raw vector Y component
        """
        
        pass
    
    def get_Mag0RawVecZ(self) -> float:
        """
        A getter for the 'SimSensorRaw::Mag0RawVecZ' structure field
        
        MAG0 raw vector Z component
        """
        
        pass
    
    def get_Mag1RawVecX(self) -> float:
        """
        A getter for the 'SimSensorRaw::Mag1RawVecX' structure field
        
        MAG1 raw vector X component
        """
        
        pass
    
    def get_Mag1RawVecY(self) -> float:
        """
        A getter for the 'SimSensorRaw::Mag1RawVecY' structure field
        
        MAG1 raw vector Y component
        """
        
        pass
    
    def get_Mag1RawVecZ(self) -> float:
        """
        A getter for the 'SimSensorRaw::Mag1RawVecZ' structure field
        
        MAG1 raw vector Z component
        """
        
        pass
    
    def get_Gyro0RawRateX(self) -> float:
        """
        A getter for the 'SimSensorRaw::Gyro0RawRateX' structure field
        
        GYR0 raw rate X component
        """
        
        pass
    
    def get_Gyro0RawRateY(self) -> float:
        """
        A getter for the 'SimSensorRaw::Gyro0RawRateY' structure field
        
        GYR0 raw rate Y component
        """
        
        pass
    
    def get_Gyro0RawRateZ(self) -> float:
        """
        A getter for the 'SimSensorRaw::Gyro0RawRateZ' structure field
        
        GYR0 raw rate Z component
        """
        
        pass
    
    def get_Gyro1RawRateX(self) -> float:
        """
        A getter for the 'SimSensorRaw::Gyro1RawRateX' structure field
        
        GYR1 raw rate X component
        """
        
        pass
    
    def get_Gyro1RawRateY(self) -> float:
        """
        A getter for the 'SimSensorRaw::Gyro1RawRateY' structure field
        
        GYR1 raw rate Y component
        """
        
        pass
    
    def get_Gyro1RawRateZ(self) -> float:
        """
        A getter for the 'SimSensorRaw::Gyro1RawRateZ' structure field
        
        GYR1 raw rate Z component
        """
        
        pass
    
    def get_Hss0RawElev(self) -> float:
        """
        A getter for the 'SimSensorRaw::Hss0RawElev' structure field
        
        HSS0 raw elevation angle
        """
        
        pass
    
    def get_Hss0RawRot(self) -> float:
        """
        A getter for the 'SimSensorRaw::Hss0RawRot' structure field
        
        HSS0 raw rotation angle
        """
        
        pass
    
    def get_Hss1RawElev(self) -> float:
        """
        A getter for the 'SimSensorRaw::Hss1RawElev' structure field
        
        HSS1 raw elevation angle
        """
        
        pass
    
    def get_Hss1RawRot(self) -> float:
        """
        A getter for the 'SimSensorRaw::Hss1RawRot' structure field
        
        HSS1 raw rotation angle
        """
        
        pass
    
    def get_Str0MeasVec0X(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0MeasVec0X' structure field
        
        STR0 measured vector 0 X component (sensor frame)
        """
        
        pass
    
    def get_Str0MeasVec0Y(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0MeasVec0Y' structure field
        
        STR0 measured vector 0 Y component (sensor frame)
        """
        
        pass
    
    def get_Str0MeasVec0Z(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0MeasVec0Z' structure field
        
        STR0 measured vector 0 Z component (sensor frame)
        """
        
        pass
    
    def get_Str0MeasVec1X(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0MeasVec1X' structure field
        
        STR0 measured vector 1 X component (sensor frame)
        """
        
        pass
    
    def get_Str0MeasVec1Y(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0MeasVec1Y' structure field
        
        STR0 measured vector 1 Y component (sensor frame)
        """
        
        pass
    
    def get_Str0MeasVec1Z(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0MeasVec1Z' structure field
        
        STR0 measured vector 1 Z component (sensor frame)
        """
        
        pass
    
    def get_Str0MeasVec2X(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0MeasVec2X' structure field
        
        STR0 measured vector 2 X component (sensor frame)
        """
        
        pass
    
    def get_Str0MeasVec2Y(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0MeasVec2Y' structure field
        
        STR0 measured vector 2 Y component (sensor frame)
        """
        
        pass
    
    def get_Str0MeasVec2Z(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0MeasVec2Z' structure field
        
        STR0 measured vector 2 Z component (sensor frame)
        """
        
        pass
    
    def get_Str0ModelVec0X(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0ModelVec0X' structure field
        
        STR0 modelled vector 0 X component (IRC frame)
        """
        
        pass
    
    def get_Str0ModelVec0Y(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0ModelVec0Y' structure field
        
        STR0 modelled vector 0 Y component (IRC frame)
        """
        
        pass
    
    def get_Str0ModelVec0Z(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0ModelVec0Z' structure field
        
        STR0 modelled vector 0 Z component (IRC frame)
        """
        
        pass
    
    def get_Str0ModelVec1X(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0ModelVec1X' structure field
        
        STR0 modelled vector 1 X component (IRC frame)
        """
        
        pass
    
    def get_Str0ModelVec1Y(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0ModelVec1Y' structure field
        
        STR0 modelled vector 1 Y component (IRC frame)
        """
        
        pass
    
    def get_Str0ModelVec1Z(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0ModelVec1Z' structure field
        
        STR0 modelled vector 1 Z component (IRC frame)
        """
        
        pass
    
    def get_Str0ModelVec2X(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0ModelVec2X' structure field
        
        STR0 modelled vector 2 X component (IRC frame)
        """
        
        pass
    
    def get_Str0ModelVec2Y(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0ModelVec2Y' structure field
        
        STR0 modelled vector 2 Y component (IRC frame)
        """
        
        pass
    
    def get_Str0ModelVec2Z(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0ModelVec2Z' structure field
        
        STR0 modelled vector 2 Z component (IRC frame)
        """
        
        pass
    
    def get_Str0MeasQ0(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0MeasQ0' structure field
        
        STR0 measured quaternion Q0 (sensor to IRC frame)
        """
        
        pass
    
    def get_Str0MeasQ1(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0MeasQ1' structure field
        
        STR0 measured quaternion Q1 (sensor to IRC frame)
        """
        
        pass
    
    def get_Str0MeasQ2(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0MeasQ2' structure field
        
        STR0 measured quaternion Q2 (sensor to IRC frame)
        """
        
        pass
    
    def get_Str0MeasQ3(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str0MeasQ3' structure field
        
        STR0 measured quaternion Q3 (sensor to IRC frame)
        """
        
        pass
    
    def get_Str0StarIdCount(self) -> int:
        """
        A getter for the 'SimSensorRaw::Str0StarIdCount' structure field
        
        STR0 number of identified stars
        """
        
        pass
    
    def get_Str1MeasVec0X(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1MeasVec0X' structure field
        
        STR1 measured vector 0 X component (sensor frame)
        """
        
        pass
    
    def get_Str1MeasVec0Y(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1MeasVec0Y' structure field
        
        STR1 measured vector 0 Y component (sensor frame)
        """
        
        pass
    
    def get_Str1MeasVec0Z(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1MeasVec0Z' structure field
        
        STR1 measured vector 0 Z component (sensor frame)
        """
        
        pass
    
    def get_Str1MeasVec1X(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1MeasVec1X' structure field
        
        STR1 measured vector 1 X component (sensor frame)
        """
        
        pass
    
    def get_Str1MeasVec1Y(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1MeasVec1Y' structure field
        
        STR1 measured vector 1 Y component (sensor frame)
        """
        
        pass
    
    def get_Str1MeasVec1Z(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1MeasVec1Z' structure field
        
        STR1 measured vector 1 Z component (sensor frame)
        """
        
        pass
    
    def get_Str1MeasVec2X(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1MeasVec2X' structure field
        
        STR1 measured vector 2 X component (sensor frame)
        """
        
        pass
    
    def get_Str1MeasVec2Y(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1MeasVec2Y' structure field
        
        STR1 measured vector 2 Y component (sensor frame)
        """
        
        pass
    
    def get_Str1MeasVec2Z(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1MeasVec2Z' structure field
        
        STR1 measured vector 2 Z component (sensor frame)
        """
        
        pass
    
    def get_Str1ModelVec0X(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1ModelVec0X' structure field
        
        STR1 modelled vector 0 X component (IRC frame)
        """
        
        pass
    
    def get_Str1ModelVec0Y(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1ModelVec0Y' structure field
        
        STR1 modelled vector 0 Y component (IRC frame)
        """
        
        pass
    
    def get_Str1ModelVec0Z(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1ModelVec0Z' structure field
        
        STR1 modelled vector 0 Z component (IRC frame)
        """
        
        pass
    
    def get_Str1ModelVec1X(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1ModelVec1X' structure field
        
        STR1 modelled vector 1 X component (IRC frame)
        """
        
        pass
    
    def get_Str1ModelVec1Y(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1ModelVec1Y' structure field
        
        STR1 modelled vector 1 Y component (IRC frame)
        """
        
        pass
    
    def get_Str1ModelVec1Z(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1ModelVec1Z' structure field
        
        STR1 modelled vector 1 Z component (IRC frame)
        """
        
        pass
    
    def get_Str1ModelVec2X(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1ModelVec2X' structure field
        
        STR1 modelled vector 2 X component (IRC frame)
        """
        
        pass
    
    def get_Str1ModelVec2Y(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1ModelVec2Y' structure field
        
        STR1 modelled vector 2 Y component (IRC frame)
        """
        
        pass
    
    def get_Str1ModelVec2Z(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1ModelVec2Z' structure field
        
        STR1 modelled vector 2 Z component (IRC frame)
        """
        
        pass
    
    def get_Str1MeasQ0(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1MeasQ0' structure field
        
        STR1 measured quaternion Q0 (sensor to IRC frame)
        """
        
        pass
    
    def get_Str1MeasQ1(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1MeasQ1' structure field
        
        STR1 measured quaternion Q1 (sensor to IRC frame)
        """
        
        pass
    
    def get_Str1MeasQ2(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1MeasQ2' structure field
        
        STR1 measured quaternion Q2 (sensor to IRC frame)
        """
        
        pass
    
    def get_Str1MeasQ3(self) -> float:
        """
        A getter for the 'SimSensorRaw::Str1MeasQ3' structure field
        
        STR1 measured quaternion Q3 (sensor to IRC frame)
        """
        
        pass
    
    def get_Str1StarIdCount(self) -> int:
        """
        A getter for the 'SimSensorRaw::Str1StarIdCount' structure field
        
        STR1 number of identified stars
        """
        
        pass
    
    def get_GnssTimeSeconds(self) -> int:
        """
        A getter for the 'SimSensorRaw::GnssTimeSeconds' structure field
        
        GNSS Unix time integer seconds
        """
        
        pass
    
    def get_GnssTimeNs(self) -> int:
        """
        A getter for the 'SimSensorRaw::GnssTimeNs' structure field
        
        GNSS Unix time fraction nanoseconds
        """
        
        pass
    
    def get_GnssSatPosX(self) -> int:
        """
        A getter for the 'SimSensorRaw::GnssSatPosX' structure field
        
        Satellite position vector X component (GNSS frame)
        """
        
        pass
    
    def get_GnssSatPosY(self) -> int:
        """
        A getter for the 'SimSensorRaw::GnssSatPosY' structure field
        
        Satellite position vector Y component (GNSS frame)
        """
        
        pass
    
    def get_GnssSatPosZ(self) -> int:
        """
        A getter for the 'SimSensorRaw::GnssSatPosZ' structure field
        
        Satellite position vector Z component (GNSS frame)
        """
        
        pass
    
    def get_GnssSatVelX(self) -> int:
        """
        A getter for the 'SimSensorRaw::GnssSatVelX' structure field
        
        Satellite velocity vector X component (GNSS frame)
        """
        
        pass
    
    def get_GnssSatVelY(self) -> int:
        """
        A getter for the 'SimSensorRaw::GnssSatVelY' structure field
        
        Satellite velocity vector Y component (GNSS frame)
        """
        
        pass
    
    def get_GnssSatVelZ(self) -> int:
        """
        A getter for the 'SimSensorRaw::GnssSatVelZ' structure field
        
        Satellite velocity vector Z component (GNSS frame)
        """
        
        pass
    
    def get_ExtSensor0Float0(self) -> float:
        """
        A getter for the 'SimSensorRaw::ExtSensor0Float0' structure field
        
        ExtSensor0 raw measurement float 0
        """
        
        pass
    
    def get_ExtSensor0Float1(self) -> float:
        """
        A getter for the 'SimSensorRaw::ExtSensor0Float1' structure field
        
        ExtSensor0 raw measurement float 1
        """
        
        pass
    
    def get_ExtSensor0Float2(self) -> float:
        """
        A getter for the 'SimSensorRaw::ExtSensor0Float2' structure field
        
        ExtSensor0 raw measurement float 2
        """
        
        pass
    
    def get_ExtSensor0Float3(self) -> float:
        """
        A getter for the 'SimSensorRaw::ExtSensor0Float3' structure field
        
        ExtSensor0 raw measurement float 3
        """
        
        pass
    
    def get_ExtSensor0Float4(self) -> float:
        """
        A getter for the 'SimSensorRaw::ExtSensor0Float4' structure field
        
        ExtSensor0 raw measurement float 4
        """
        
        pass
    
    def get_ExtSensor0Float5(self) -> float:
        """
        A getter for the 'SimSensorRaw::ExtSensor0Float5' structure field
        
        ExtSensor0 raw measurement float 5
        """
        
        pass
    
    def get_ExtSensor1Float0(self) -> float:
        """
        A getter for the 'SimSensorRaw::ExtSensor1Float0' structure field
        
        ExtSensor1 raw measurement float 0
        """
        
        pass
    
    def get_ExtSensor1Float1(self) -> float:
        """
        A getter for the 'SimSensorRaw::ExtSensor1Float1' structure field
        
        ExtSensor1 raw measurement float 1
        """
        
        pass
    
    def get_ExtSensor1Float2(self) -> float:
        """
        A getter for the 'SimSensorRaw::ExtSensor1Float2' structure field
        
        ExtSensor1 raw measurement float 2
        """
        
        pass
    
    def get_ExtSensor1Float3(self) -> float:
        """
        A getter for the 'SimSensorRaw::ExtSensor1Float3' structure field
        
        ExtSensor1 raw measurement float 3
        """
        
        pass
    
    def get_ExtSensor1Float4(self) -> float:
        """
        A getter for the 'SimSensorRaw::ExtSensor1Float4' structure field
        
        ExtSensor1 raw measurement float 4
        """
        
        pass
    
    def get_ExtSensor1Float5(self) -> float:
        """
        A getter for the 'SimSensorRaw::ExtSensor1Float5' structure field
        
        ExtSensor1 raw measurement float 5
        """
        
        pass
    
    def get_Rwl0SpeedMeas(self) -> float:
        """
        A getter for the 'SimSensorRaw::Rwl0SpeedMeas' structure field
        
        RWL0 raw speed measurement
        """
        
        pass
    
    def get_Rwl1SpeedMeas(self) -> float:
        """
        A getter for the 'SimSensorRaw::Rwl1SpeedMeas' structure field
        
        RWL1 raw speed measurement
        """
        
        pass
    
    def get_Rwl2SpeedMeas(self) -> float:
        """
        A getter for the 'SimSensorRaw::Rwl2SpeedMeas' structure field
        
        RWL2 raw speed measurement
        """
        
        pass
    
    def get_Rwl3SpeedMeas(self) -> float:
        """
        A getter for the 'SimSensorRaw::Rwl3SpeedMeas' structure field
        
        RWL3 raw speed measurement
        """
        
        pass
    
    def get_Fss0IsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::Fss0IsValid' structure field
        
        FSS0 valid flag
        """
        
        pass
    
    def get_Fss1IsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::Fss1IsValid' structure field
        
        FSS1 valid flag
        """
        
        pass
    
    def get_Fss2IsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::Fss2IsValid' structure field
        
        FSS2 valid flag
        """
        
        pass
    
    def get_Fss3IsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::Fss3IsValid' structure field
        
        FSS3 valid flag
        """
        
        pass
    
    def get_CssIsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::CssIsValid' structure field
        
        CSS valid flag
        """
        
        pass
    
    def get_Mag0IsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::Mag0IsValid' structure field
        
        MAG0 valid flag
        """
        
        pass
    
    def get_Mag1IsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::Mag1IsValid' structure field
        
        MAG1 valid flag
        """
        
        pass
    
    def get_Gyro0IsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::Gyro0IsValid' structure field
        
        GYR0 valid flag
        """
        
        pass
    
    def get_Gyro1IsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::Gyro1IsValid' structure field
        
        GYR1 valid flag
        """
        
        pass
    
    def get_Hss0IsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::Hss0IsValid' structure field
        
        HSS0 valid flag
        """
        
        pass
    
    def get_Hss1IsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::Hss1IsValid' structure field
        
        HSS1 valid flag
        """
        
        pass
    
    def get_Str0IsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::Str0IsValid' structure field
        
        STR0 valid flag
        """
        
        pass
    
    def get_Str1IsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::Str1IsValid' structure field
        
        STR1 valid flag
        """
        
        pass
    
    def get_GnssIsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::GnssIsValid' structure field
        
        GNSS valid flag
        """
        
        pass
    
    def get_GnssIsNew(self) -> int:
        """
        A getter for the 'SimSensorRaw::GnssIsNew' structure field
        
        GNSS new flag
        """
        
        pass
    
    def get_ExtSensor0IsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::ExtSensor0IsValid' structure field
        
        ExtSensor0 valid flag
        """
        
        pass
    
    def get_ExtSensor1IsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::ExtSensor1IsValid' structure field
        
        ExtSensor1 valid flag
        """
        
        pass
    
    def get_Rwl0IsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::Rwl0IsValid' structure field
        
        RWL0 valid flag
        """
        
        pass
    
    def get_Rwl1IsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::Rwl1IsValid' structure field
        
        RWL1 valid flag
        """
        
        pass
    
    def get_Rwl2IsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::Rwl2IsValid' structure field
        
        RWL2 valid flag
        """
        
        pass
    
    def get_Rwl3IsValid(self) -> int:
        """
        A getter for the 'SimSensorRaw::Rwl3IsValid' structure field
        
        RWL3 valid flag
        """
        
        pass

def SimSensorRaw_make_from_buf(buf : bytes) -> SimSensorRaw:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class OpenLoopCommandRwl:
    """
    A Python class to represent struct objects of type 'OpenLoopCommandRwl'
    
    Parameter structure for interface OpenLoopCommandRwl
    """

    def __init__(self, float__Rwl0SpeedCmd : float, float__Rwl1SpeedCmd : float, float__Rwl2SpeedCmd : float, float__Rwl3SpeedCmd : float) -> None:
        """
        Struct 'OpenLoopCommandRwl' constructor
        
        Attributes
        ---------
        float__Rwl0SpeedCmd [1] : float
            RWL0 open-loop speed command
        float__Rwl1SpeedCmd [1] : float
            RWL1 open-loop speed command
        float__Rwl2SpeedCmd [1] : float
            RWL2 open-loop speed command
        float__Rwl3SpeedCmd [1] : float
            RWL3 open-loop speed command
        """
        
        pass
        
    def get_Rwl0SpeedCmd(self) -> float:
        """
        A getter for the 'OpenLoopCommandRwl::Rwl0SpeedCmd' structure field
        
        RWL0 open-loop speed command
        """
        
        pass
    
    def get_Rwl1SpeedCmd(self) -> float:
        """
        A getter for the 'OpenLoopCommandRwl::Rwl1SpeedCmd' structure field
        
        RWL1 open-loop speed command
        """
        
        pass
    
    def get_Rwl2SpeedCmd(self) -> float:
        """
        A getter for the 'OpenLoopCommandRwl::Rwl2SpeedCmd' structure field
        
        RWL2 open-loop speed command
        """
        
        pass
    
    def get_Rwl3SpeedCmd(self) -> float:
        """
        A getter for the 'OpenLoopCommandRwl::Rwl3SpeedCmd' structure field
        
        RWL3 open-loop speed command
        """
        
        pass

def OpenLoopCommandRwl_make_from_buf(buf : bytes) -> OpenLoopCommandRwl:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ConfigOrbitTargetParams:
    """
    A Python class to represent struct objects of type 'ConfigOrbitTargetParams'
    
    Parameter structure for interface ConfigOrbitTargetParams
    """

    def __init__(self, double__OrbitEpoch : float, double__OrbitIncl : float, double__OrbitRaan : float, double__OrbitEccen : float, double__OrbitAP : float, double__OrbitMA : float, double__OrbitMM : float, double__OrbitBstar : float) -> None:
        """
        Struct 'ConfigOrbitTargetParams' constructor
        
        Attributes
        ---------
        double__OrbitEpoch [1] : float
            Orbit epoch
        double__OrbitIncl [1] : float
            Orbit inclination
        double__OrbitRaan [1] : float
            Orbit RAAN
        double__OrbitEccen [1] : float
            Orbit eccentricity
        double__OrbitAP [1] : float
            Orbit argument of perigee
        double__OrbitMA [1] : float
            Orbit mean anomaly
        double__OrbitMM [1] : float
            Orbit mean motion
        double__OrbitBstar [1] : float
            Orbit B-star drag term
        """
        
        pass
        
    def get_OrbitEpoch(self) -> float:
        """
        A getter for the 'ConfigOrbitTargetParams::OrbitEpoch' structure field
        
        Orbit epoch
        """
        
        pass
    
    def get_OrbitIncl(self) -> float:
        """
        A getter for the 'ConfigOrbitTargetParams::OrbitIncl' structure field
        
        Orbit inclination
        """
        
        pass
    
    def get_OrbitRaan(self) -> float:
        """
        A getter for the 'ConfigOrbitTargetParams::OrbitRaan' structure field
        
        Orbit RAAN
        """
        
        pass
    
    def get_OrbitEccen(self) -> float:
        """
        A getter for the 'ConfigOrbitTargetParams::OrbitEccen' structure field
        
        Orbit eccentricity
        """
        
        pass
    
    def get_OrbitAP(self) -> float:
        """
        A getter for the 'ConfigOrbitTargetParams::OrbitAP' structure field
        
        Orbit argument of perigee
        """
        
        pass
    
    def get_OrbitMA(self) -> float:
        """
        A getter for the 'ConfigOrbitTargetParams::OrbitMA' structure field
        
        Orbit mean anomaly
        """
        
        pass
    
    def get_OrbitMM(self) -> float:
        """
        A getter for the 'ConfigOrbitTargetParams::OrbitMM' structure field
        
        Orbit mean motion
        """
        
        pass
    
    def get_OrbitBstar(self) -> float:
        """
        A getter for the 'ConfigOrbitTargetParams::OrbitBstar' structure field
        
        Orbit B-star drag term
        """
        
        pass

def ConfigOrbitTargetParams_make_from_buf(buf : bytes) -> ConfigOrbitTargetParams:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmStrPst3sHealth:
    """
    A Python class to represent struct objects of type 'TlmStrPst3sHealth'
    
    Parameter structure for interface TlmStrPst3sHealth
    """

    def __init__(self, double__Str0McuTemp : float, double__Str0McuCurrent : float, uint16__Str0McuVoltage : int, double__Str0Pst3sCurrent : float, bool__Str0Pst3sOvercurrent : int, double__Str1McuTemp : float, double__Str1McuCurrent : float, uint16__Str1McuVoltage : int, double__Str1Pst3sCurrent : float, bool__Str1Pst3sOvercurrent : int) -> None:
        """
        Struct 'TlmStrPst3sHealth' constructor
        
        Attributes
        ---------
        double__Str0McuTemp [1] : float
            STR0 MCU Temperature
        double__Str0McuCurrent [1] : float
            STR0 MCU current
        uint16__Str0McuVoltage [1] : int
            STR0 MCU supply voltage
        double__Str0Pst3sCurrent [1] : float
            STR0 PST3S current
        bool__Str0Pst3sOvercurrent [1] : int
            STR0 PST3S CAM overcurrent
        double__Str1McuTemp [1] : float
            STR1 MCU Temperature
        double__Str1McuCurrent [1] : float
            STR1 MCU current
        uint16__Str1McuVoltage [1] : int
            STR1 MCU supply voltage
        double__Str1Pst3sCurrent [1] : float
            STR1 PST3S current
        bool__Str1Pst3sOvercurrent [1] : int
            STR1 PST3S CAM overcurrent
        """
        
        pass
        
    def get_Str0McuTemp(self) -> float:
        """
        A getter for the 'TlmStrPst3sHealth::Str0McuTemp' structure field
        
        STR0 MCU Temperature
        """
        
        pass
    
    def get_Str0McuCurrent(self) -> float:
        """
        A getter for the 'TlmStrPst3sHealth::Str0McuCurrent' structure field
        
        STR0 MCU current
        """
        
        pass
    
    def get_Str0McuVoltage(self) -> int:
        """
        A getter for the 'TlmStrPst3sHealth::Str0McuVoltage' structure field
        
        STR0 MCU supply voltage
        """
        
        pass
    
    def get_Str0Pst3sCurrent(self) -> float:
        """
        A getter for the 'TlmStrPst3sHealth::Str0Pst3sCurrent' structure field
        
        STR0 PST3S current
        """
        
        pass
    
    def get_Str0Pst3sOvercurrent(self) -> int:
        """
        A getter for the 'TlmStrPst3sHealth::Str0Pst3sOvercurrent' structure field
        
        STR0 PST3S CAM overcurrent
        """
        
        pass
    
    def get_Str1McuTemp(self) -> float:
        """
        A getter for the 'TlmStrPst3sHealth::Str1McuTemp' structure field
        
        STR1 MCU Temperature
        """
        
        pass
    
    def get_Str1McuCurrent(self) -> float:
        """
        A getter for the 'TlmStrPst3sHealth::Str1McuCurrent' structure field
        
        STR1 MCU current
        """
        
        pass
    
    def get_Str1McuVoltage(self) -> int:
        """
        A getter for the 'TlmStrPst3sHealth::Str1McuVoltage' structure field
        
        STR1 MCU supply voltage
        """
        
        pass
    
    def get_Str1Pst3sCurrent(self) -> float:
        """
        A getter for the 'TlmStrPst3sHealth::Str1Pst3sCurrent' structure field
        
        STR1 PST3S current
        """
        
        pass
    
    def get_Str1Pst3sOvercurrent(self) -> int:
        """
        A getter for the 'TlmStrPst3sHealth::Str1Pst3sOvercurrent' structure field
        
        STR1 PST3S CAM overcurrent
        """
        
        pass

def TlmStrPst3sHealth_make_from_buf(buf : bytes) -> TlmStrPst3sHealth:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmNssRwlHealth:
    """
    A Python class to represent struct objects of type 'TlmNssRwlHealth'
    
    Parameter structure for interface TlmNssRwlHealth
    """

    def __init__(self, double__Rwl0McuTemp : float, double__Rwl0McuCurrent : float, uint16__Rwl0McuVoltage : int, double__Rwl0Current5v : float, uint16__Rwl0PmuCurrent : int, bool__Rwl0Overcurrent5v : int, bool__Rwl0PowerGood : int, bool__Rwl0PmuCurrentValid : int, double__Rwl1McuTemp : float, double__Rwl1McuCurrent : float, uint16__Rwl1McuVoltage : int, double__Rwl1Current5v : float, uint16__Rwl1PmuCurrent : int, bool__Rwl1Overcurrent5v : int, bool__Rwl1PowerGood : int, bool__Rwl1PmuCurrentValid : int, double__Rwl2McuTemp : float, double__Rwl2McuCurrent : float, uint16__Rwl2McuVoltage : int, double__Rwl2Current5v : float, uint16__Rwl2PmuCurrent : int, bool__Rwl2Overcurrent5v : int, bool__Rwl2PowerGood : int, bool__Rwl2PmuCurrentValid : int, double__Rwl3McuTemp : float, double__Rwl3McuCurrent : float, uint16__Rwl3McuVoltage : int, double__Rwl3Current5v : float, uint16__Rwl3PmuCurrent : int, bool__Rwl3Overcurrent5v : int, bool__Rwl3PowerGood : int, bool__Rwl3PmuCurrentValid : int) -> None:
        """
        Struct 'TlmNssRwlHealth' constructor
        
        Attributes
        ---------
        double__Rwl0McuTemp [1] : float
            RWL0 MCU Temperature
        double__Rwl0McuCurrent [1] : float
            RWL0 MCU current
        uint16__Rwl0McuVoltage [1] : int
            RWL0 MCU supply voltage
        double__Rwl0Current5v [1] : float
            RWL0 5V current
        uint16__Rwl0PmuCurrent [1] : int
            RWL0 PMU Current
        bool__Rwl0Overcurrent5v [1] : int
            RWL0 5V overcurrent
        bool__Rwl0PowerGood [1] : int
            RWL0 PowerGood signal
        bool__Rwl0PmuCurrentValid [1] : int
            RWL0 Set if measurement was successful
        double__Rwl1McuTemp [1] : float
            RWL1 MCU Temperature
        double__Rwl1McuCurrent [1] : float
            RWL1 MCU current
        uint16__Rwl1McuVoltage [1] : int
            RWL1 MCU supply voltage
        double__Rwl1Current5v [1] : float
            RWL1 5V current
        uint16__Rwl1PmuCurrent [1] : int
            RWL1 PMU Current
        bool__Rwl1Overcurrent5v [1] : int
            Rwl1 5V overcurrent
        bool__Rwl1PowerGood [1] : int
            Rwl1 PowerGood signal
        bool__Rwl1PmuCurrentValid [1] : int
            RWL1 Set if measurement was successful
        double__Rwl2McuTemp [1] : float
            RWL2 MCU Temperature
        double__Rwl2McuCurrent [1] : float
            RWL2 MCU current
        uint16__Rwl2McuVoltage [1] : int
            RWL2 MCU supply voltage
        double__Rwl2Current5v [1] : float
            RWL2 5V current
        uint16__Rwl2PmuCurrent [1] : int
            RWL2 PMU Current
        bool__Rwl2Overcurrent5v [1] : int
            Rwl2 5V overcurrent
        bool__Rwl2PowerGood [1] : int
            Rwl2 PowerGood signal
        bool__Rwl2PmuCurrentValid [1] : int
            RWL2 Set if measurement was successful
        double__Rwl3McuTemp [1] : float
            RWL3 MCU Temperature
        double__Rwl3McuCurrent [1] : float
            RWL3 MCU current
        uint16__Rwl3McuVoltage [1] : int
            RWL3 MCU supply voltage
        double__Rwl3Current5v [1] : float
            RWL3 5V current
        uint16__Rwl3PmuCurrent [1] : int
            RWL3 PMU Current
        bool__Rwl3Overcurrent5v [1] : int
            Rwl3 5V overcurrent
        bool__Rwl3PowerGood [1] : int
            Rwl3 PowerGood signal
        bool__Rwl3PmuCurrentValid [1] : int
            RWL3 Set if measurement was successful
        """
        
        pass
        
    def get_Rwl0McuTemp(self) -> float:
        """
        A getter for the 'TlmNssRwlHealth::Rwl0McuTemp' structure field
        
        RWL0 MCU Temperature
        """
        
        pass
    
    def get_Rwl0McuCurrent(self) -> float:
        """
        A getter for the 'TlmNssRwlHealth::Rwl0McuCurrent' structure field
        
        RWL0 MCU current
        """
        
        pass
    
    def get_Rwl0McuVoltage(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl0McuVoltage' structure field
        
        RWL0 MCU supply voltage
        """
        
        pass
    
    def get_Rwl0Current5v(self) -> float:
        """
        A getter for the 'TlmNssRwlHealth::Rwl0Current5v' structure field
        
        RWL0 5V current
        """
        
        pass
    
    def get_Rwl0PmuCurrent(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl0PmuCurrent' structure field
        
        RWL0 PMU Current
        """
        
        pass
    
    def get_Rwl0Overcurrent5v(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl0Overcurrent5v' structure field
        
        RWL0 5V overcurrent
        """
        
        pass
    
    def get_Rwl0PowerGood(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl0PowerGood' structure field
        
        RWL0 PowerGood signal
        """
        
        pass
    
    def get_Rwl0PmuCurrentValid(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl0PmuCurrentValid' structure field
        
        RWL0 Set if measurement was successful
        """
        
        pass
    
    def get_Rwl1McuTemp(self) -> float:
        """
        A getter for the 'TlmNssRwlHealth::Rwl1McuTemp' structure field
        
        RWL1 MCU Temperature
        """
        
        pass
    
    def get_Rwl1McuCurrent(self) -> float:
        """
        A getter for the 'TlmNssRwlHealth::Rwl1McuCurrent' structure field
        
        RWL1 MCU current
        """
        
        pass
    
    def get_Rwl1McuVoltage(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl1McuVoltage' structure field
        
        RWL1 MCU supply voltage
        """
        
        pass
    
    def get_Rwl1Current5v(self) -> float:
        """
        A getter for the 'TlmNssRwlHealth::Rwl1Current5v' structure field
        
        RWL1 5V current
        """
        
        pass
    
    def get_Rwl1PmuCurrent(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl1PmuCurrent' structure field
        
        RWL1 PMU Current
        """
        
        pass
    
    def get_Rwl1Overcurrent5v(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl1Overcurrent5v' structure field
        
        Rwl1 5V overcurrent
        """
        
        pass
    
    def get_Rwl1PowerGood(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl1PowerGood' structure field
        
        Rwl1 PowerGood signal
        """
        
        pass
    
    def get_Rwl1PmuCurrentValid(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl1PmuCurrentValid' structure field
        
        RWL1 Set if measurement was successful
        """
        
        pass
    
    def get_Rwl2McuTemp(self) -> float:
        """
        A getter for the 'TlmNssRwlHealth::Rwl2McuTemp' structure field
        
        RWL2 MCU Temperature
        """
        
        pass
    
    def get_Rwl2McuCurrent(self) -> float:
        """
        A getter for the 'TlmNssRwlHealth::Rwl2McuCurrent' structure field
        
        RWL2 MCU current
        """
        
        pass
    
    def get_Rwl2McuVoltage(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl2McuVoltage' structure field
        
        RWL2 MCU supply voltage
        """
        
        pass
    
    def get_Rwl2Current5v(self) -> float:
        """
        A getter for the 'TlmNssRwlHealth::Rwl2Current5v' structure field
        
        RWL2 5V current
        """
        
        pass
    
    def get_Rwl2PmuCurrent(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl2PmuCurrent' structure field
        
        RWL2 PMU Current
        """
        
        pass
    
    def get_Rwl2Overcurrent5v(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl2Overcurrent5v' structure field
        
        Rwl2 5V overcurrent
        """
        
        pass
    
    def get_Rwl2PowerGood(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl2PowerGood' structure field
        
        Rwl2 PowerGood signal
        """
        
        pass
    
    def get_Rwl2PmuCurrentValid(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl2PmuCurrentValid' structure field
        
        RWL2 Set if measurement was successful
        """
        
        pass
    
    def get_Rwl3McuTemp(self) -> float:
        """
        A getter for the 'TlmNssRwlHealth::Rwl3McuTemp' structure field
        
        RWL3 MCU Temperature
        """
        
        pass
    
    def get_Rwl3McuCurrent(self) -> float:
        """
        A getter for the 'TlmNssRwlHealth::Rwl3McuCurrent' structure field
        
        RWL3 MCU current
        """
        
        pass
    
    def get_Rwl3McuVoltage(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl3McuVoltage' structure field
        
        RWL3 MCU supply voltage
        """
        
        pass
    
    def get_Rwl3Current5v(self) -> float:
        """
        A getter for the 'TlmNssRwlHealth::Rwl3Current5v' structure field
        
        RWL3 5V current
        """
        
        pass
    
    def get_Rwl3PmuCurrent(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl3PmuCurrent' structure field
        
        RWL3 PMU Current
        """
        
        pass
    
    def get_Rwl3Overcurrent5v(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl3Overcurrent5v' structure field
        
        Rwl3 5V overcurrent
        """
        
        pass
    
    def get_Rwl3PowerGood(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl3PowerGood' structure field
        
        Rwl3 PowerGood signal
        """
        
        pass
    
    def get_Rwl3PmuCurrentValid(self) -> int:
        """
        A getter for the 'TlmNssRwlHealth::Rwl3PmuCurrentValid' structure field
        
        RWL3 Set if measurement was successful
        """
        
        pass

def TlmNssRwlHealth_make_from_buf(buf : bytes) -> TlmNssRwlHealth:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ConfigMag0OrbitCal:
    """
    A Python class to represent struct objects of type 'ConfigMag0OrbitCal'
    
    Parameter structure for interface ConfigMag0OrbitCal
    """

    def __init__(self, double__Offset1 : float, double__Offset2 : float, double__Offset3 : float, double__SensMatrix11 : float, double__SensMatrix22 : float, double__SensMatrix33 : float, double__SensMatrix12 : float, double__SensMatrix13 : float, double__SensMatrix21 : float, double__SensMatrix23 : float, double__SensMatrix31 : float, double__SensMatrix32 : float) -> None:
        """
        Struct 'ConfigMag0OrbitCal' constructor
        
        Attributes
        ---------
        double__Offset1 [1] : float
            Magnetometer channel 1 offset
        double__Offset2 [1] : float
            Magnetometer channel 2 offset
        double__Offset3 [1] : float
            Magnetometer channel 3 offset
        double__SensMatrix11 [1] : float
            Magnetometer sensitivity matrix S11
        double__SensMatrix22 [1] : float
            Magnetometer sensitivity matrix S22
        double__SensMatrix33 [1] : float
            Magnetometer sensitivity matrix S33
        double__SensMatrix12 [1] : float
            Magnetometer sensitivity matrix S12
        double__SensMatrix13 [1] : float
            Magnetometer sensitivity matrix S13
        double__SensMatrix21 [1] : float
            Magnetometer sensitivity matrix S21
        double__SensMatrix23 [1] : float
            Magnetometer sensitivity matrix S23
        double__SensMatrix31 [1] : float
            Magnetometer sensitivity matrix S31
        double__SensMatrix32 [1] : float
            Magnetometer sensitivity matrix S32
        """
        
        pass
        
    def get_Offset1(self) -> float:
        """
        A getter for the 'ConfigMag0OrbitCal::Offset1' structure field
        
        Magnetometer channel 1 offset
        """
        
        pass
    
    def get_Offset2(self) -> float:
        """
        A getter for the 'ConfigMag0OrbitCal::Offset2' structure field
        
        Magnetometer channel 2 offset
        """
        
        pass
    
    def get_Offset3(self) -> float:
        """
        A getter for the 'ConfigMag0OrbitCal::Offset3' structure field
        
        Magnetometer channel 3 offset
        """
        
        pass
    
    def get_SensMatrix11(self) -> float:
        """
        A getter for the 'ConfigMag0OrbitCal::SensMatrix11' structure field
        
        Magnetometer sensitivity matrix S11
        """
        
        pass
    
    def get_SensMatrix22(self) -> float:
        """
        A getter for the 'ConfigMag0OrbitCal::SensMatrix22' structure field
        
        Magnetometer sensitivity matrix S22
        """
        
        pass
    
    def get_SensMatrix33(self) -> float:
        """
        A getter for the 'ConfigMag0OrbitCal::SensMatrix33' structure field
        
        Magnetometer sensitivity matrix S33
        """
        
        pass
    
    def get_SensMatrix12(self) -> float:
        """
        A getter for the 'ConfigMag0OrbitCal::SensMatrix12' structure field
        
        Magnetometer sensitivity matrix S12
        """
        
        pass
    
    def get_SensMatrix13(self) -> float:
        """
        A getter for the 'ConfigMag0OrbitCal::SensMatrix13' structure field
        
        Magnetometer sensitivity matrix S13
        """
        
        pass
    
    def get_SensMatrix21(self) -> float:
        """
        A getter for the 'ConfigMag0OrbitCal::SensMatrix21' structure field
        
        Magnetometer sensitivity matrix S21
        """
        
        pass
    
    def get_SensMatrix23(self) -> float:
        """
        A getter for the 'ConfigMag0OrbitCal::SensMatrix23' structure field
        
        Magnetometer sensitivity matrix S23
        """
        
        pass
    
    def get_SensMatrix31(self) -> float:
        """
        A getter for the 'ConfigMag0OrbitCal::SensMatrix31' structure field
        
        Magnetometer sensitivity matrix S31
        """
        
        pass
    
    def get_SensMatrix32(self) -> float:
        """
        A getter for the 'ConfigMag0OrbitCal::SensMatrix32' structure field
        
        Magnetometer sensitivity matrix S32
        """
        
        pass

def ConfigMag0OrbitCal_make_from_buf(buf : bytes) -> ConfigMag0OrbitCal:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmSensorRawRwl:
    """
    A Python class to represent struct objects of type 'TlmSensorRawRwl'
    
    Parameter structure for interface TlmSensorRawRwl
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, float__Rwl0MeasSpeed : float, float__Rwl1MeasSpeed : float, float__Rwl2MeasSpeed : float, float__Rwl3MeasSpeed : float, bool__Rwl0IsValid : int, bool__Rwl1IsValid : int, bool__Rwl2IsValid : int, bool__Rwl3IsValid : int) -> None:
        """
        Struct 'TlmSensorRawRwl' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        float__Rwl0MeasSpeed [1] : float
            RWL0 measured speed
        float__Rwl1MeasSpeed [1] : float
            RWL1 measured speed
        float__Rwl2MeasSpeed [1] : float
            RWL2 measured speed
        float__Rwl3MeasSpeed [1] : float
            RWL3 measured speed
        bool__Rwl0IsValid [1] : int
            RWL0 valid flag
        bool__Rwl1IsValid [1] : int
            RWL1 valid flag
        bool__Rwl2IsValid [1] : int
            RWL2 valid flag
        bool__Rwl3IsValid [1] : int
            RWL3 valid flag
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmSensorRawRwl::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmSensorRawRwl::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_Rwl0MeasSpeed(self) -> float:
        """
        A getter for the 'TlmSensorRawRwl::Rwl0MeasSpeed' structure field
        
        RWL0 measured speed
        """
        
        pass
    
    def get_Rwl1MeasSpeed(self) -> float:
        """
        A getter for the 'TlmSensorRawRwl::Rwl1MeasSpeed' structure field
        
        RWL1 measured speed
        """
        
        pass
    
    def get_Rwl2MeasSpeed(self) -> float:
        """
        A getter for the 'TlmSensorRawRwl::Rwl2MeasSpeed' structure field
        
        RWL2 measured speed
        """
        
        pass
    
    def get_Rwl3MeasSpeed(self) -> float:
        """
        A getter for the 'TlmSensorRawRwl::Rwl3MeasSpeed' structure field
        
        RWL3 measured speed
        """
        
        pass
    
    def get_Rwl0IsValid(self) -> int:
        """
        A getter for the 'TlmSensorRawRwl::Rwl0IsValid' structure field
        
        RWL0 valid flag
        """
        
        pass
    
    def get_Rwl1IsValid(self) -> int:
        """
        A getter for the 'TlmSensorRawRwl::Rwl1IsValid' structure field
        
        RWL1 valid flag
        """
        
        pass
    
    def get_Rwl2IsValid(self) -> int:
        """
        A getter for the 'TlmSensorRawRwl::Rwl2IsValid' structure field
        
        RWL2 valid flag
        """
        
        pass
    
    def get_Rwl3IsValid(self) -> int:
        """
        A getter for the 'TlmSensorRawRwl::Rwl3IsValid' structure field
        
        RWL3 valid flag
        """
        
        pass

def TlmSensorRawRwl_make_from_buf(buf : bytes) -> TlmSensorRawRwl:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmGnssUartStatus:
    """
    A Python class to represent struct objects of type 'TlmGnssUartStatus'
    
    Parameter structure for interface TlmGnssUartStatus
    """

    def __init__(self, uint32__BytesReceived : int, uint32__ErrorFlags : int) -> None:
        """
        Struct 'TlmGnssUartStatus' constructor
        
        Attributes
        ---------
        uint32__BytesReceived [1] : int
            Number of bytes received from GNSS UART
        uint32__ErrorFlags [1] : int
            Number of bytes received from GNSS UART
        """
        
        pass
        
    def get_BytesReceived(self) -> int:
        """
        A getter for the 'TlmGnssUartStatus::BytesReceived' structure field
        
        Number of bytes received from GNSS UART
        """
        
        pass
    
    def get_ErrorFlags(self) -> int:
        """
        A getter for the 'TlmGnssUartStatus::ErrorFlags' structure field
        
        Number of bytes received from GNSS UART
        """
        
        pass

def TlmGnssUartStatus_make_from_buf(buf : bytes) -> TlmGnssUartStatus:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class OpenLoopCommandMtq:
    """
    A Python class to represent struct objects of type 'OpenLoopCommandMtq'
    
    Parameter structure for interface OpenLoopCommandMtq
    """

    def __init__(self, int16__Mtq0OnTimeCmd : int, int16__Mtq1OnTimeCmd : int, int16__Mtq2OnTimeCmd : int) -> None:
        """
        Struct 'OpenLoopCommandMtq' constructor
        
        Attributes
        ---------
        int16__Mtq0OnTimeCmd [1] : int
            MTQ0 open-loop on-time command
        int16__Mtq1OnTimeCmd [1] : int
            MTQ1 open-loop on-time command
        int16__Mtq2OnTimeCmd [1] : int
            MTQ2 open-loop on-time command
        """
        
        pass
        
    def get_Mtq0OnTimeCmd(self) -> int:
        """
        A getter for the 'OpenLoopCommandMtq::Mtq0OnTimeCmd' structure field
        
        MTQ0 open-loop on-time command
        """
        
        pass
    
    def get_Mtq1OnTimeCmd(self) -> int:
        """
        A getter for the 'OpenLoopCommandMtq::Mtq1OnTimeCmd' structure field
        
        MTQ1 open-loop on-time command
        """
        
        pass
    
    def get_Mtq2OnTimeCmd(self) -> int:
        """
        A getter for the 'OpenLoopCommandMtq::Mtq2OnTimeCmd' structure field
        
        MTQ2 open-loop on-time command
        """
        
        pass

def OpenLoopCommandMtq_make_from_buf(buf : bytes) -> OpenLoopCommandMtq:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ConfigActuatorMtq:
    """
    A Python class to represent struct objects of type 'ConfigActuatorMtq'
    
    Parameter structure for interface ConfigActuatorMtq
    """

    def __init__(self, float__Mtq0Mmax : float, float__Mtq1Mmax : float, float__Mtq2Mmax : float, uint16__OnTimeMax : int, uint16__OnTimeMin : int, float__MtqFfac : float) -> None:
        """
        Struct 'ConfigActuatorMtq' constructor
        
        Attributes
        ---------
        float__Mtq0Mmax [1] : float
            MTQ0 maximum dipole moment
        float__Mtq1Mmax [1] : float
            MTQ1 maximum dipole moment
        float__Mtq2Mmax [1] : float
            MTQ2 maximum dipole moment
        uint16__OnTimeMax [1] : int
            Maximum magnetorquer on-time
        uint16__OnTimeMin [1] : int
            Minimum magnetorquer on-time
        float__MtqFfac [1] : float
            LPF factor for magnetorquer commands. Set to zero for no filtering
        """
        
        pass
        
    def get_Mtq0Mmax(self) -> float:
        """
        A getter for the 'ConfigActuatorMtq::Mtq0Mmax' structure field
        
        MTQ0 maximum dipole moment
        """
        
        pass
    
    def get_Mtq1Mmax(self) -> float:
        """
        A getter for the 'ConfigActuatorMtq::Mtq1Mmax' structure field
        
        MTQ1 maximum dipole moment
        """
        
        pass
    
    def get_Mtq2Mmax(self) -> float:
        """
        A getter for the 'ConfigActuatorMtq::Mtq2Mmax' structure field
        
        MTQ2 maximum dipole moment
        """
        
        pass
    
    def get_OnTimeMax(self) -> int:
        """
        A getter for the 'ConfigActuatorMtq::OnTimeMax' structure field
        
        Maximum magnetorquer on-time
        """
        
        pass
    
    def get_OnTimeMin(self) -> int:
        """
        A getter for the 'ConfigActuatorMtq::OnTimeMin' structure field
        
        Minimum magnetorquer on-time
        """
        
        pass
    
    def get_MtqFfac(self) -> float:
        """
        A getter for the 'ConfigActuatorMtq::MtqFfac' structure field
        
        LPF factor for magnetorquer commands. Set to zero for no filtering
        """
        
        pass

def ConfigActuatorMtq_make_from_buf(buf : bytes) -> ConfigActuatorMtq:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmSensorCalCss:
    """
    A Python class to represent struct objects of type 'TlmSensorCalCss'
    
    Parameter structure for interface TlmSensorCalCss
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, double__CssCalVecX : float, double__CssCalVecY : float, double__CssCalVecZ : float, bool__CssIsValid : int) -> None:
        """
        Struct 'TlmSensorCalCss' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        double__CssCalVecX [1] : float
            CSS calibrated unit vector X component
        double__CssCalVecY [1] : float
            CSS calibrated unit vector Y component
        double__CssCalVecZ [1] : float
            CSS calibrated unit vector Z component
        bool__CssIsValid [1] : int
            CSS valid flag
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmSensorCalCss::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmSensorCalCss::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_CssCalVecX(self) -> float:
        """
        A getter for the 'TlmSensorCalCss::CssCalVecX' structure field
        
        CSS calibrated unit vector X component
        """
        
        pass
    
    def get_CssCalVecY(self) -> float:
        """
        A getter for the 'TlmSensorCalCss::CssCalVecY' structure field
        
        CSS calibrated unit vector Y component
        """
        
        pass
    
    def get_CssCalVecZ(self) -> float:
        """
        A getter for the 'TlmSensorCalCss::CssCalVecZ' structure field
        
        CSS calibrated unit vector Z component
        """
        
        pass
    
    def get_CssIsValid(self) -> int:
        """
        A getter for the 'TlmSensorCalCss::CssIsValid' structure field
        
        CSS valid flag
        """
        
        pass

def TlmSensorCalCss_make_from_buf(buf : bytes) -> TlmSensorCalCss:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmExtSensorRaw:
    """
    A Python class to represent struct objects of type 'TlmExtSensorRaw'
    
    Parameter structure for interface TlmExtSensorRaw
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, float__ExtSensor0Float0 : float, float__ExtSensor0Float1 : float, float__ExtSensor0Float2 : float, float__ExtSensor0Float3 : float, float__ExtSensor0Float4 : float, float__ExtSensor0Float5 : float, float__ExtSensor1Float0 : float, float__ExtSensor1Float1 : float, float__ExtSensor1Float2 : float, float__ExtSensor1Float3 : float, float__ExtSensor1Float4 : float, float__ExtSensor1Float5 : float, bool__ExtSensor0IsValid : int, bool__ExtSensor1IsValid : int) -> None:
        """
        Struct 'TlmExtSensorRaw' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        float__ExtSensor0Float0 [1] : float
            ExtSensor0 raw float 0
        float__ExtSensor0Float1 [1] : float
            ExtSensor0 raw float 1
        float__ExtSensor0Float2 [1] : float
            ExtSensor0 raw float 2
        float__ExtSensor0Float3 [1] : float
            ExtSensor0 raw float 3
        float__ExtSensor0Float4 [1] : float
            ExtSensor0 raw float 4
        float__ExtSensor0Float5 [1] : float
            ExtSensor0 raw float 5
        float__ExtSensor1Float0 [1] : float
            ExtSensor1 raw float 0
        float__ExtSensor1Float1 [1] : float
            ExtSensor1 raw float 1
        float__ExtSensor1Float2 [1] : float
            ExtSensor1 raw float 2
        float__ExtSensor1Float3 [1] : float
            ExtSensor1 raw float 3
        float__ExtSensor1Float4 [1] : float
            ExtSensor1 raw float 4
        float__ExtSensor1Float5 [1] : float
            ExtSensor1 raw float 5
        bool__ExtSensor0IsValid [1] : int
            ExtSensor0 valid flag
        bool__ExtSensor1IsValid [1] : int
            ExtSensor1 valid flag
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmExtSensorRaw::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmExtSensorRaw::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_ExtSensor0Float0(self) -> float:
        """
        A getter for the 'TlmExtSensorRaw::ExtSensor0Float0' structure field
        
        ExtSensor0 raw float 0
        """
        
        pass
    
    def get_ExtSensor0Float1(self) -> float:
        """
        A getter for the 'TlmExtSensorRaw::ExtSensor0Float1' structure field
        
        ExtSensor0 raw float 1
        """
        
        pass
    
    def get_ExtSensor0Float2(self) -> float:
        """
        A getter for the 'TlmExtSensorRaw::ExtSensor0Float2' structure field
        
        ExtSensor0 raw float 2
        """
        
        pass
    
    def get_ExtSensor0Float3(self) -> float:
        """
        A getter for the 'TlmExtSensorRaw::ExtSensor0Float3' structure field
        
        ExtSensor0 raw float 3
        """
        
        pass
    
    def get_ExtSensor0Float4(self) -> float:
        """
        A getter for the 'TlmExtSensorRaw::ExtSensor0Float4' structure field
        
        ExtSensor0 raw float 4
        """
        
        pass
    
    def get_ExtSensor0Float5(self) -> float:
        """
        A getter for the 'TlmExtSensorRaw::ExtSensor0Float5' structure field
        
        ExtSensor0 raw float 5
        """
        
        pass
    
    def get_ExtSensor1Float0(self) -> float:
        """
        A getter for the 'TlmExtSensorRaw::ExtSensor1Float0' structure field
        
        ExtSensor1 raw float 0
        """
        
        pass
    
    def get_ExtSensor1Float1(self) -> float:
        """
        A getter for the 'TlmExtSensorRaw::ExtSensor1Float1' structure field
        
        ExtSensor1 raw float 1
        """
        
        pass
    
    def get_ExtSensor1Float2(self) -> float:
        """
        A getter for the 'TlmExtSensorRaw::ExtSensor1Float2' structure field
        
        ExtSensor1 raw float 2
        """
        
        pass
    
    def get_ExtSensor1Float3(self) -> float:
        """
        A getter for the 'TlmExtSensorRaw::ExtSensor1Float3' structure field
        
        ExtSensor1 raw float 3
        """
        
        pass
    
    def get_ExtSensor1Float4(self) -> float:
        """
        A getter for the 'TlmExtSensorRaw::ExtSensor1Float4' structure field
        
        ExtSensor1 raw float 4
        """
        
        pass
    
    def get_ExtSensor1Float5(self) -> float:
        """
        A getter for the 'TlmExtSensorRaw::ExtSensor1Float5' structure field
        
        ExtSensor1 raw float 5
        """
        
        pass
    
    def get_ExtSensor0IsValid(self) -> int:
        """
        A getter for the 'TlmExtSensorRaw::ExtSensor0IsValid' structure field
        
        ExtSensor0 valid flag
        """
        
        pass
    
    def get_ExtSensor1IsValid(self) -> int:
        """
        A getter for the 'TlmExtSensorRaw::ExtSensor1IsValid' structure field
        
        ExtSensor1 valid flag
        """
        
        pass

def TlmExtSensorRaw_make_from_buf(buf : bytes) -> TlmExtSensorRaw:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmSensorCalRwl:
    """
    A Python class to represent struct objects of type 'TlmSensorCalRwl'
    
    Parameter structure for interface TlmSensorCalRwl
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, float__RwlTorqueVecX : float, float__RwlTorqueVecY : float, float__RwlTorqueVecZ : float, float__RwlMomVecX : float, float__RwlMomVecY : float, float__RwlMomVecZ : float, bool__RwlIsValid : int) -> None:
        """
        Struct 'TlmSensorCalRwl' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        float__RwlTorqueVecX [1] : float
            Wheel SBC torque vector X component
        float__RwlTorqueVecY [1] : float
            Wheel SBC torque vector Y component
        float__RwlTorqueVecZ [1] : float
            Wheel SBC torque vector Z component
        float__RwlMomVecX [1] : float
            Wheel SBC momentum vector X component
        float__RwlMomVecY [1] : float
            Wheel SBC momentum vector Y component
        float__RwlMomVecZ [1] : float
            Wheel SBC momentum vector Z component
        bool__RwlIsValid [1] : int
            RWL valid flag
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmSensorCalRwl::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmSensorCalRwl::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_RwlTorqueVecX(self) -> float:
        """
        A getter for the 'TlmSensorCalRwl::RwlTorqueVecX' structure field
        
        Wheel SBC torque vector X component
        """
        
        pass
    
    def get_RwlTorqueVecY(self) -> float:
        """
        A getter for the 'TlmSensorCalRwl::RwlTorqueVecY' structure field
        
        Wheel SBC torque vector Y component
        """
        
        pass
    
    def get_RwlTorqueVecZ(self) -> float:
        """
        A getter for the 'TlmSensorCalRwl::RwlTorqueVecZ' structure field
        
        Wheel SBC torque vector Z component
        """
        
        pass
    
    def get_RwlMomVecX(self) -> float:
        """
        A getter for the 'TlmSensorCalRwl::RwlMomVecX' structure field
        
        Wheel SBC momentum vector X component
        """
        
        pass
    
    def get_RwlMomVecY(self) -> float:
        """
        A getter for the 'TlmSensorCalRwl::RwlMomVecY' structure field
        
        Wheel SBC momentum vector Y component
        """
        
        pass
    
    def get_RwlMomVecZ(self) -> float:
        """
        A getter for the 'TlmSensorCalRwl::RwlMomVecZ' structure field
        
        Wheel SBC momentum vector Z component
        """
        
        pass
    
    def get_RwlIsValid(self) -> int:
        """
        A getter for the 'TlmSensorCalRwl::RwlIsValid' structure field
        
        RWL valid flag
        """
        
        pass

def TlmSensorCalRwl_make_from_buf(buf : bytes) -> TlmSensorCalRwl:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ConfigAsgp4:
    """
    A Python class to represent struct objects of type 'ConfigAsgp4'
    
    Parameter structure for interface ConfigAsgp4
    """

    def __init__(self, uint16__BatchSize : int, uint32__MaxTimeBetween : int, uint16__MaxPosErr : int, float__TimeGain : float, bool__UpdateRaanIncl : int, bool__UpdateEccen : int, bool__UpdateApMa : int, bool__UpdateTime : int) -> None:
        """
        Struct 'ConfigAsgp4' constructor
        
        Attributes
        ---------
        uint16__BatchSize [1] : int
            Number of GNSS measurements before computing updates TLEs
        uint32__MaxTimeBetween [1] : int
            Maximum time between GNSS measurements before resetting filters
        uint16__MaxPosErr [1] : int
            Maximum position error for asgp4 to continue working
        float__TimeGain [1] : float
            Time offset compensation gain
        bool__UpdateRaanIncl [1] : int
            Update SGP4 RAAN and Inclination angles from GNSS
        bool__UpdateEccen [1] : int
            Update SGP4 Eccentricity from GNSS
        bool__UpdateApMa [1] : int
            Update SGP4 Arg. Perigee and Mean Anomaly from GNSS
        bool__UpdateTime [1] : int
            Update SGP4 Epoch from GNSS
        """
        
        pass
        
    def get_BatchSize(self) -> int:
        """
        A getter for the 'ConfigAsgp4::BatchSize' structure field
        
        Number of GNSS measurements before computing updates TLEs
        """
        
        pass
    
    def get_MaxTimeBetween(self) -> int:
        """
        A getter for the 'ConfigAsgp4::MaxTimeBetween' structure field
        
        Maximum time between GNSS measurements before resetting filters
        """
        
        pass
    
    def get_MaxPosErr(self) -> int:
        """
        A getter for the 'ConfigAsgp4::MaxPosErr' structure field
        
        Maximum position error for asgp4 to continue working
        """
        
        pass
    
    def get_TimeGain(self) -> float:
        """
        A getter for the 'ConfigAsgp4::TimeGain' structure field
        
        Time offset compensation gain
        """
        
        pass
    
    def get_UpdateRaanIncl(self) -> int:
        """
        A getter for the 'ConfigAsgp4::UpdateRaanIncl' structure field
        
        Update SGP4 RAAN and Inclination angles from GNSS
        """
        
        pass
    
    def get_UpdateEccen(self) -> int:
        """
        A getter for the 'ConfigAsgp4::UpdateEccen' structure field
        
        Update SGP4 Eccentricity from GNSS
        """
        
        pass
    
    def get_UpdateApMa(self) -> int:
        """
        A getter for the 'ConfigAsgp4::UpdateApMa' structure field
        
        Update SGP4 Arg. Perigee and Mean Anomaly from GNSS
        """
        
        pass
    
    def get_UpdateTime(self) -> int:
        """
        A getter for the 'ConfigAsgp4::UpdateTime' structure field
        
        Update SGP4 Epoch from GNSS
        """
        
        pass

def ConfigAsgp4_make_from_buf(buf : bytes) -> ConfigAsgp4:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmGnssRaw:
    """
    A Python class to represent struct objects of type 'TlmGnssRaw'
    
    Parameter structure for interface TlmGnssRaw
    """

    def __init__(self, uint32__RtcTimeSeconds : int, uint32__RtcTimeNs : int, int32__RtcDriftNs : int, float__GnssSatPosEcefX : float, float__GnssSatPosEcefY : float, float__GnssSatPosEcefZ : float, float__GnssSatVelEcefX : float, float__GnssSatVelEcefY : float, float__GnssSatVelEcefZ : float, uint32__GnssTimeSeconds : int, uint32__GnssTimeNs : int, uint16__GpsWeek : int, uint32__Tow : int, int8__UtcOffset : int, bool__GnssValidData : int, bool__GnssLock : int, bool__GnssPPSDetected : int) -> None:
        """
        Struct 'TlmGnssRaw' constructor
        
        Attributes
        ---------
        uint32__RtcTimeSeconds [1] : int
            Unix time integer seconds
        uint32__RtcTimeNs [1] : int
            Unix time fraction nanoseconds
        int32__RtcDriftNs [1] : int
            Drift per second
        float__GnssSatPosEcefX [1] : float
            Satellite ECEF position vector X component
        float__GnssSatPosEcefY [1] : float
            Satellite ECEF position vector Y component
        float__GnssSatPosEcefZ [1] : float
            Satellite ECEF position vector Z component
        float__GnssSatVelEcefX [1] : float
            Satellite ECEF velocity vector X component
        float__GnssSatVelEcefY [1] : float
            Satellite ECEF velocity vector Y component
        float__GnssSatVelEcefZ [1] : float
            Satellite ECEF velocity vector Z component
        uint32__GnssTimeSeconds [1] : int
            GNSS-supplied unix time integer seconds
        uint32__GnssTimeNs [1] : int
            GNSS-supplied unix time nanoseconds
        uint16__GpsWeek [1] : int
            GPS week number
        uint32__Tow [1] : int
            GNSS Time of Week
        int8__UtcOffset [1] : int
            Offset between GNSS time and UTC
        bool__GnssValidData [1] : int
            GNSS data is valid, but may be outdated
        bool__GnssLock [1] : int
            GNSS has lock, data most recent
        bool__GnssPPSDetected [1] : int
            GNSS PPS Detected by ADCS HW
        """
        
        pass
        
    def get_RtcTimeSeconds(self) -> int:
        """
        A getter for the 'TlmGnssRaw::RtcTimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_RtcTimeNs(self) -> int:
        """
        A getter for the 'TlmGnssRaw::RtcTimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_RtcDriftNs(self) -> int:
        """
        A getter for the 'TlmGnssRaw::RtcDriftNs' structure field
        
        Drift per second
        """
        
        pass
    
    def get_GnssSatPosEcefX(self) -> float:
        """
        A getter for the 'TlmGnssRaw::GnssSatPosEcefX' structure field
        
        Satellite ECEF position vector X component
        """
        
        pass
    
    def get_GnssSatPosEcefY(self) -> float:
        """
        A getter for the 'TlmGnssRaw::GnssSatPosEcefY' structure field
        
        Satellite ECEF position vector Y component
        """
        
        pass
    
    def get_GnssSatPosEcefZ(self) -> float:
        """
        A getter for the 'TlmGnssRaw::GnssSatPosEcefZ' structure field
        
        Satellite ECEF position vector Z component
        """
        
        pass
    
    def get_GnssSatVelEcefX(self) -> float:
        """
        A getter for the 'TlmGnssRaw::GnssSatVelEcefX' structure field
        
        Satellite ECEF velocity vector X component
        """
        
        pass
    
    def get_GnssSatVelEcefY(self) -> float:
        """
        A getter for the 'TlmGnssRaw::GnssSatVelEcefY' structure field
        
        Satellite ECEF velocity vector Y component
        """
        
        pass
    
    def get_GnssSatVelEcefZ(self) -> float:
        """
        A getter for the 'TlmGnssRaw::GnssSatVelEcefZ' structure field
        
        Satellite ECEF velocity vector Z component
        """
        
        pass
    
    def get_GnssTimeSeconds(self) -> int:
        """
        A getter for the 'TlmGnssRaw::GnssTimeSeconds' structure field
        
        GNSS-supplied unix time integer seconds
        """
        
        pass
    
    def get_GnssTimeNs(self) -> int:
        """
        A getter for the 'TlmGnssRaw::GnssTimeNs' structure field
        
        GNSS-supplied unix time nanoseconds
        """
        
        pass
    
    def get_GpsWeek(self) -> int:
        """
        A getter for the 'TlmGnssRaw::GpsWeek' structure field
        
        GPS week number
        """
        
        pass
    
    def get_Tow(self) -> int:
        """
        A getter for the 'TlmGnssRaw::Tow' structure field
        
        GNSS Time of Week
        """
        
        pass
    
    def get_UtcOffset(self) -> int:
        """
        A getter for the 'TlmGnssRaw::UtcOffset' structure field
        
        Offset between GNSS time and UTC
        """
        
        pass
    
    def get_GnssValidData(self) -> int:
        """
        A getter for the 'TlmGnssRaw::GnssValidData' structure field
        
        GNSS data is valid, but may be outdated
        """
        
        pass
    
    def get_GnssLock(self) -> int:
        """
        A getter for the 'TlmGnssRaw::GnssLock' structure field
        
        GNSS has lock, data most recent
        """
        
        pass
    
    def get_GnssPPSDetected(self) -> int:
        """
        A getter for the 'TlmGnssRaw::GnssPPSDetected' structure field
        
        GNSS PPS Detected by ADCS HW
        """
        
        pass

def TlmGnssRaw_make_from_buf(buf : bytes) -> TlmGnssRaw:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ReferenceTarget:
    """
    A Python class to represent struct objects of type 'ReferenceTarget'
    
    Parameter structure for interface ReferenceTarget
    """

    def __init__(self, float__CmdTargetLatitude : float, float__CmdTargetLongitude : float, float__CmdTargetAltitude : float) -> None:
        """
        Struct 'ReferenceTarget' constructor
        
        Attributes
        ---------
        float__CmdTargetLatitude [1] : float
            Target latitude command
        float__CmdTargetLongitude [1] : float
            Target longitude command
        float__CmdTargetAltitude [1] : float
            Target altitude command
        """
        
        pass
        
    def get_CmdTargetLatitude(self) -> float:
        """
        A getter for the 'ReferenceTarget::CmdTargetLatitude' structure field
        
        Target latitude command
        """
        
        pass
    
    def get_CmdTargetLongitude(self) -> float:
        """
        A getter for the 'ReferenceTarget::CmdTargetLongitude' structure field
        
        Target longitude command
        """
        
        pass
    
    def get_CmdTargetAltitude(self) -> float:
        """
        A getter for the 'ReferenceTarget::CmdTargetAltitude' structure field
        
        Target altitude command
        """
        
        pass

def ReferenceTarget_make_from_buf(buf : bytes) -> ReferenceTarget:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmFssCubeSenseSunHealth:
    """
    A Python class to represent struct objects of type 'TlmFssCubeSenseSunHealth'
    
    Parameter structure for interface TlmFssCubeSenseSunHealth
    """

    def __init__(self, double__Fss0McuTemp : float, double__Fss0McuCurrent : float, uint16__Fss0McuVoltage : int, double__Fss0CurrentCam : float, double__Fss0CurrentSram : float, bool__Fss0OvercurrentCam : int, bool__Fss0OvercurrentSram : int, double__Fss1McuTemp : float, double__Fss1McuCurrent : float, uint16__Fss1McuVoltage : int, double__Fss1CurrentCam : float, double__Fss1CurrentSram : float, bool__Fss1OvercurrentCam : int, bool__Fss1OvercurrentSram : int, double__Fss2McuTemp : float, double__Fss2McuCurrent : float, uint16__Fss2McuVoltage : int, double__Fss2CurrentCam : float, double__Fss2CurrentSram : float, bool__Fss2OvercurrentCam : int, bool__Fss2OvercurrentSram : int, double__Fss3McuTemp : float, double__Fss3McuCurrent : float, uint16__Fss3McuVoltage : int, double__Fss3CurrentCam : float, double__Fss3CurrentSram : float, bool__Fss3OvercurrentCam : int, bool__Fss3OvercurrentSram : int) -> None:
        """
        Struct 'TlmFssCubeSenseSunHealth' constructor
        
        Attributes
        ---------
        double__Fss0McuTemp [1] : float
            FSS0 MCU Temperature
        double__Fss0McuCurrent [1] : float
            FSS0 MCU current
        uint16__Fss0McuVoltage [1] : int
            FSS0 MCU supply voltage
        double__Fss0CurrentCam [1] : float
            FSS0 Camera current
        double__Fss0CurrentSram [1] : float
            FSS0 SRAM current
        bool__Fss0OvercurrentCam [1] : int
            FSS0 CAM overcurrent detected
        bool__Fss0OvercurrentSram [1] : int
            FSS0 SRAM overcurrent detected
        double__Fss1McuTemp [1] : float
            FSS1 MCU Temperature
        double__Fss1McuCurrent [1] : float
            FSS1 MCU current
        uint16__Fss1McuVoltage [1] : int
            FSS1 MCU supply voltage
        double__Fss1CurrentCam [1] : float
            FSS1 Camera current
        double__Fss1CurrentSram [1] : float
            FSS1 SRAM current
        bool__Fss1OvercurrentCam [1] : int
            FSS1 CAM overcurrent detected
        bool__Fss1OvercurrentSram [1] : int
            FSS1 SRAM overcurrent detected
        double__Fss2McuTemp [1] : float
            FSS2 MCU Temperature
        double__Fss2McuCurrent [1] : float
            FSS2 MCU current
        uint16__Fss2McuVoltage [1] : int
            FSS2 MCU supply voltage
        double__Fss2CurrentCam [1] : float
            FSS2 Camera current
        double__Fss2CurrentSram [1] : float
            FSS2 SRAM current
        bool__Fss2OvercurrentCam [1] : int
            FSS2 CAM overcurrent detected
        bool__Fss2OvercurrentSram [1] : int
            FSS2 SRAM overcurrent detected
        double__Fss3McuTemp [1] : float
            FSS3 MCU Temperature
        double__Fss3McuCurrent [1] : float
            FSS3 MCU current
        uint16__Fss3McuVoltage [1] : int
            FSS3 MCU supply voltage
        double__Fss3CurrentCam [1] : float
            FSS3 Camera current
        double__Fss3CurrentSram [1] : float
            FSS3 SRAM current
        bool__Fss3OvercurrentCam [1] : int
            FSS3 CAM overcurrent detected
        bool__Fss3OvercurrentSram [1] : int
            FSS3 SRAM overcurrent detected
        """
        
        pass
        
    def get_Fss0McuTemp(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss0McuTemp' structure field
        
        FSS0 MCU Temperature
        """
        
        pass
    
    def get_Fss0McuCurrent(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss0McuCurrent' structure field
        
        FSS0 MCU current
        """
        
        pass
    
    def get_Fss0McuVoltage(self) -> int:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss0McuVoltage' structure field
        
        FSS0 MCU supply voltage
        """
        
        pass
    
    def get_Fss0CurrentCam(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss0CurrentCam' structure field
        
        FSS0 Camera current
        """
        
        pass
    
    def get_Fss0CurrentSram(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss0CurrentSram' structure field
        
        FSS0 SRAM current
        """
        
        pass
    
    def get_Fss0OvercurrentCam(self) -> int:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss0OvercurrentCam' structure field
        
        FSS0 CAM overcurrent detected
        """
        
        pass
    
    def get_Fss0OvercurrentSram(self) -> int:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss0OvercurrentSram' structure field
        
        FSS0 SRAM overcurrent detected
        """
        
        pass
    
    def get_Fss1McuTemp(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss1McuTemp' structure field
        
        FSS1 MCU Temperature
        """
        
        pass
    
    def get_Fss1McuCurrent(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss1McuCurrent' structure field
        
        FSS1 MCU current
        """
        
        pass
    
    def get_Fss1McuVoltage(self) -> int:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss1McuVoltage' structure field
        
        FSS1 MCU supply voltage
        """
        
        pass
    
    def get_Fss1CurrentCam(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss1CurrentCam' structure field
        
        FSS1 Camera current
        """
        
        pass
    
    def get_Fss1CurrentSram(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss1CurrentSram' structure field
        
        FSS1 SRAM current
        """
        
        pass
    
    def get_Fss1OvercurrentCam(self) -> int:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss1OvercurrentCam' structure field
        
        FSS1 CAM overcurrent detected
        """
        
        pass
    
    def get_Fss1OvercurrentSram(self) -> int:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss1OvercurrentSram' structure field
        
        FSS1 SRAM overcurrent detected
        """
        
        pass
    
    def get_Fss2McuTemp(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss2McuTemp' structure field
        
        FSS2 MCU Temperature
        """
        
        pass
    
    def get_Fss2McuCurrent(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss2McuCurrent' structure field
        
        FSS2 MCU current
        """
        
        pass
    
    def get_Fss2McuVoltage(self) -> int:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss2McuVoltage' structure field
        
        FSS2 MCU supply voltage
        """
        
        pass
    
    def get_Fss2CurrentCam(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss2CurrentCam' structure field
        
        FSS2 Camera current
        """
        
        pass
    
    def get_Fss2CurrentSram(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss2CurrentSram' structure field
        
        FSS2 SRAM current
        """
        
        pass
    
    def get_Fss2OvercurrentCam(self) -> int:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss2OvercurrentCam' structure field
        
        FSS2 CAM overcurrent detected
        """
        
        pass
    
    def get_Fss2OvercurrentSram(self) -> int:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss2OvercurrentSram' structure field
        
        FSS2 SRAM overcurrent detected
        """
        
        pass
    
    def get_Fss3McuTemp(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss3McuTemp' structure field
        
        FSS3 MCU Temperature
        """
        
        pass
    
    def get_Fss3McuCurrent(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss3McuCurrent' structure field
        
        FSS3 MCU current
        """
        
        pass
    
    def get_Fss3McuVoltage(self) -> int:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss3McuVoltage' structure field
        
        FSS3 MCU supply voltage
        """
        
        pass
    
    def get_Fss3CurrentCam(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss3CurrentCam' structure field
        
        FSS3 Camera current
        """
        
        pass
    
    def get_Fss3CurrentSram(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss3CurrentSram' structure field
        
        FSS3 SRAM current
        """
        
        pass
    
    def get_Fss3OvercurrentCam(self) -> int:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss3OvercurrentCam' structure field
        
        FSS3 CAM overcurrent detected
        """
        
        pass
    
    def get_Fss3OvercurrentSram(self) -> int:
        """
        A getter for the 'TlmFssCubeSenseSunHealth::Fss3OvercurrentSram' structure field
        
        FSS3 SRAM overcurrent detected
        """
        
        pass

def TlmFssCubeSenseSunHealth_make_from_buf(buf : bytes) -> TlmFssCubeSenseSunHealth:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ConfigMag1OrbitCal:
    """
    A Python class to represent struct objects of type 'ConfigMag1OrbitCal'
    
    Parameter structure for interface ConfigMag1OrbitCal
    """

    def __init__(self, double__Offset1 : float, double__Offset2 : float, double__Offset3 : float, double__SensMatrix11 : float, double__SensMatrix22 : float, double__SensMatrix33 : float, double__SensMatrix12 : float, double__SensMatrix13 : float, double__SensMatrix21 : float, double__SensMatrix23 : float, double__SensMatrix31 : float, double__SensMatrix32 : float) -> None:
        """
        Struct 'ConfigMag1OrbitCal' constructor
        
        Attributes
        ---------
        double__Offset1 [1] : float
            Magnetometer channel 1 offset
        double__Offset2 [1] : float
            Magnetometer channel 2 offset
        double__Offset3 [1] : float
            Magnetometer channel 3 offset
        double__SensMatrix11 [1] : float
            Magnetometer sensitivity matrix S11
        double__SensMatrix22 [1] : float
            Magnetometer sensitivity matrix S22
        double__SensMatrix33 [1] : float
            Magnetometer sensitivity matrix S33
        double__SensMatrix12 [1] : float
            Magnetometer sensitivity matrix S12
        double__SensMatrix13 [1] : float
            Magnetometer sensitivity matrix S13
        double__SensMatrix21 [1] : float
            Magnetometer sensitivity matrix S21
        double__SensMatrix23 [1] : float
            Magnetometer sensitivity matrix S23
        double__SensMatrix31 [1] : float
            Magnetometer sensitivity matrix S31
        double__SensMatrix32 [1] : float
            Magnetometer sensitivity matrix S32
        """
        
        pass
        
    def get_Offset1(self) -> float:
        """
        A getter for the 'ConfigMag1OrbitCal::Offset1' structure field
        
        Magnetometer channel 1 offset
        """
        
        pass
    
    def get_Offset2(self) -> float:
        """
        A getter for the 'ConfigMag1OrbitCal::Offset2' structure field
        
        Magnetometer channel 2 offset
        """
        
        pass
    
    def get_Offset3(self) -> float:
        """
        A getter for the 'ConfigMag1OrbitCal::Offset3' structure field
        
        Magnetometer channel 3 offset
        """
        
        pass
    
    def get_SensMatrix11(self) -> float:
        """
        A getter for the 'ConfigMag1OrbitCal::SensMatrix11' structure field
        
        Magnetometer sensitivity matrix S11
        """
        
        pass
    
    def get_SensMatrix22(self) -> float:
        """
        A getter for the 'ConfigMag1OrbitCal::SensMatrix22' structure field
        
        Magnetometer sensitivity matrix S22
        """
        
        pass
    
    def get_SensMatrix33(self) -> float:
        """
        A getter for the 'ConfigMag1OrbitCal::SensMatrix33' structure field
        
        Magnetometer sensitivity matrix S33
        """
        
        pass
    
    def get_SensMatrix12(self) -> float:
        """
        A getter for the 'ConfigMag1OrbitCal::SensMatrix12' structure field
        
        Magnetometer sensitivity matrix S12
        """
        
        pass
    
    def get_SensMatrix13(self) -> float:
        """
        A getter for the 'ConfigMag1OrbitCal::SensMatrix13' structure field
        
        Magnetometer sensitivity matrix S13
        """
        
        pass
    
    def get_SensMatrix21(self) -> float:
        """
        A getter for the 'ConfigMag1OrbitCal::SensMatrix21' structure field
        
        Magnetometer sensitivity matrix S21
        """
        
        pass
    
    def get_SensMatrix23(self) -> float:
        """
        A getter for the 'ConfigMag1OrbitCal::SensMatrix23' structure field
        
        Magnetometer sensitivity matrix S23
        """
        
        pass
    
    def get_SensMatrix31(self) -> float:
        """
        A getter for the 'ConfigMag1OrbitCal::SensMatrix31' structure field
        
        Magnetometer sensitivity matrix S31
        """
        
        pass
    
    def get_SensMatrix32(self) -> float:
        """
        A getter for the 'ConfigMag1OrbitCal::SensMatrix32' structure field
        
        Magnetometer sensitivity matrix S32
        """
        
        pass

def ConfigMag1OrbitCal_make_from_buf(buf : bytes) -> ConfigMag1OrbitCal:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmSensorCalHss:
    """
    A Python class to represent struct objects of type 'TlmSensorCalHss'
    
    Parameter structure for interface TlmSensorCalHss
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, double__Hss0CalVecX : float, double__Hss0CalVecY : float, double__Hss0CalVecZ : float, double__Hss1CalVecX : float, double__Hss1CalVecY : float, double__Hss1CalVecZ : float, bool__Hss0IsValid : int, bool__Hss1IsValid : int) -> None:
        """
        Struct 'TlmSensorCalHss' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        double__Hss0CalVecX [1] : float
            HSS0 calibrated unit vector X component
        double__Hss0CalVecY [1] : float
            HSS0 calibrated unit vector Y component
        double__Hss0CalVecZ [1] : float
            HSS0 calibrated unit vector Z component
        double__Hss1CalVecX [1] : float
            HSS1 calibrated unit vector X component
        double__Hss1CalVecY [1] : float
            HSS1 calibrated unit vector Y component
        double__Hss1CalVecZ [1] : float
            HSS1 calibrated unit vector Z component
        bool__Hss0IsValid [1] : int
            HSS0 valid flag
        bool__Hss1IsValid [1] : int
            HSS1 valid flag
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmSensorCalHss::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmSensorCalHss::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_Hss0CalVecX(self) -> float:
        """
        A getter for the 'TlmSensorCalHss::Hss0CalVecX' structure field
        
        HSS0 calibrated unit vector X component
        """
        
        pass
    
    def get_Hss0CalVecY(self) -> float:
        """
        A getter for the 'TlmSensorCalHss::Hss0CalVecY' structure field
        
        HSS0 calibrated unit vector Y component
        """
        
        pass
    
    def get_Hss0CalVecZ(self) -> float:
        """
        A getter for the 'TlmSensorCalHss::Hss0CalVecZ' structure field
        
        HSS0 calibrated unit vector Z component
        """
        
        pass
    
    def get_Hss1CalVecX(self) -> float:
        """
        A getter for the 'TlmSensorCalHss::Hss1CalVecX' structure field
        
        HSS1 calibrated unit vector X component
        """
        
        pass
    
    def get_Hss1CalVecY(self) -> float:
        """
        A getter for the 'TlmSensorCalHss::Hss1CalVecY' structure field
        
        HSS1 calibrated unit vector Y component
        """
        
        pass
    
    def get_Hss1CalVecZ(self) -> float:
        """
        A getter for the 'TlmSensorCalHss::Hss1CalVecZ' structure field
        
        HSS1 calibrated unit vector Z component
        """
        
        pass
    
    def get_Hss0IsValid(self) -> int:
        """
        A getter for the 'TlmSensorCalHss::Hss0IsValid' structure field
        
        HSS0 valid flag
        """
        
        pass
    
    def get_Hss1IsValid(self) -> int:
        """
        A getter for the 'TlmSensorCalHss::Hss1IsValid' structure field
        
        HSS1 valid flag
        """
        
        pass

def TlmSensorCalHss_make_from_buf(buf : bytes) -> TlmSensorCalHss:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmSensorRawCss:
    """
    A Python class to represent struct objects of type 'TlmSensorRawCss'
    
    Parameter structure for interface TlmSensorRawCss
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, uint8__Css0Raw : int, uint8__Css1Raw : int, uint8__Css2Raw : int, uint8__Css3Raw : int, uint8__Css4Raw : int, uint8__Css5Raw : int, uint8__Css6Raw : int, uint8__Css7Raw : int, uint8__Css8Raw : int, uint8__Css9Raw : int, bool__CssIsValid : int) -> None:
        """
        Struct 'TlmSensorRawCss' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        uint8__Css0Raw [1] : int
            CSS0 raw measurement
        uint8__Css1Raw [1] : int
            CSS1 raw measurement
        uint8__Css2Raw [1] : int
            CSS2 raw measurement
        uint8__Css3Raw [1] : int
            CSS3 raw measurement
        uint8__Css4Raw [1] : int
            CSS4 raw measurement
        uint8__Css5Raw [1] : int
            CSS5 raw measurement
        uint8__Css6Raw [1] : int
            CSS6 raw measurement
        uint8__Css7Raw [1] : int
            CSS7 raw measurement
        uint8__Css8Raw [1] : int
            CSS8 raw measurement
        uint8__Css9Raw [1] : int
            CSS9 raw measurement
        bool__CssIsValid [1] : int
            CSS valid flag
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmSensorRawCss::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmSensorRawCss::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_Css0Raw(self) -> int:
        """
        A getter for the 'TlmSensorRawCss::Css0Raw' structure field
        
        CSS0 raw measurement
        """
        
        pass
    
    def get_Css1Raw(self) -> int:
        """
        A getter for the 'TlmSensorRawCss::Css1Raw' structure field
        
        CSS1 raw measurement
        """
        
        pass
    
    def get_Css2Raw(self) -> int:
        """
        A getter for the 'TlmSensorRawCss::Css2Raw' structure field
        
        CSS2 raw measurement
        """
        
        pass
    
    def get_Css3Raw(self) -> int:
        """
        A getter for the 'TlmSensorRawCss::Css3Raw' structure field
        
        CSS3 raw measurement
        """
        
        pass
    
    def get_Css4Raw(self) -> int:
        """
        A getter for the 'TlmSensorRawCss::Css4Raw' structure field
        
        CSS4 raw measurement
        """
        
        pass
    
    def get_Css5Raw(self) -> int:
        """
        A getter for the 'TlmSensorRawCss::Css5Raw' structure field
        
        CSS5 raw measurement
        """
        
        pass
    
    def get_Css6Raw(self) -> int:
        """
        A getter for the 'TlmSensorRawCss::Css6Raw' structure field
        
        CSS6 raw measurement
        """
        
        pass
    
    def get_Css7Raw(self) -> int:
        """
        A getter for the 'TlmSensorRawCss::Css7Raw' structure field
        
        CSS7 raw measurement
        """
        
        pass
    
    def get_Css8Raw(self) -> int:
        """
        A getter for the 'TlmSensorRawCss::Css8Raw' structure field
        
        CSS8 raw measurement
        """
        
        pass
    
    def get_Css9Raw(self) -> int:
        """
        A getter for the 'TlmSensorRawCss::Css9Raw' structure field
        
        CSS9 raw measurement
        """
        
        pass
    
    def get_CssIsValid(self) -> int:
        """
        A getter for the 'TlmSensorRawCss::CssIsValid' structure field
        
        CSS valid flag
        """
        
        pass

def TlmSensorRawCss_make_from_buf(buf : bytes) -> TlmSensorRawCss:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmGyrLitefuforsRaw:
    """
    A Python class to represent struct objects of type 'TlmGyrLitefuforsRaw'
    
    Parameter structure for interface TlmGyrLitefuforsRaw
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, float__Gyr0RateUfors1 : float, float__Gyr0RateUfors2 : float, float__Gyr0RateUfors3 : float, bool__Gyr0NogoUfors1 : int, bool__Gyr0RstAckUfors1 : int, bool__Gyr0TempWarnUfors1 : int, bool__Gyr0AuxControlLoopErrUfors1 : int, bool__Gyr0HardBitErrUfors1 : int, bool__Gyr0MeasRangeErrUfors1 : int, bool__Gyr0UnknwnCmdUfors1 : int, bool__Gyr0NogoUfors2 : int, bool__Gyr0RstAckUfors2 : int, bool__Gyr0TempWarnUfors2 : int, bool__Gyr0AuxControlLoopErrUfors2 : int, bool__Gyr0HardBitErrUfors2 : int, bool__Gyr0MeasRangeErrUfors2 : int, bool__Gyr0UnknwnCmdUfors2 : int, bool__Gyr0NogoUfors3 : int, bool__Gyr0RstAckUfors3 : int, bool__Gyr0TempWarnUfors3 : int, bool__Gyr0AuxControlLoopErrUfors3 : int, bool__Gyr0HardBitErrUfors3 : int, bool__Gyr0MeasRangeErrUfors3 : int, bool__Gyr0UnknwnCmdUfors3 : int, float__Gyr1RateUfors1 : float, float__Gyr1RateUfors2 : float, float__Gyr1RateUfors3 : float, bool__Gyr1NogoUfors1 : int, bool__Gyr1RstAckUfors1 : int, bool__Gyr1TempWarnUfors1 : int, bool__Gyr1AuxControlLoopErrUfors1 : int, bool__Gyr1HardBitErrUfors1 : int, bool__Gyr1MeasRangeErrUfors1 : int, bool__Gyr1UnknwnCmdUfors1 : int, bool__Gyr1NogoUfors2 : int, bool__Gyr1RstAckUfors2 : int, bool__Gyr1TempWarnUfors2 : int, bool__Gyr1AuxControlLoopErrUfors2 : int, bool__Gyr1HardBitErrUfors2 : int, bool__Gyr1MeasRangeErrUfors2 : int, bool__Gyr1UnknwnCmdUfors2 : int, bool__Gyr1NogoUfors3 : int, bool__Gyr1RstAckUfors3 : int, bool__Gyr1TempWarnUfors3 : int, bool__Gyr1AuxControlLoopErrUfors3 : int, bool__Gyr1HardBitErrUfors3 : int, bool__Gyr1MeasRangeErrUfors3 : int, bool__Gyr1UnknwnCmdUfors3 : int) -> None:
        """
        Struct 'TlmGyrLitefuforsRaw' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        float__Gyr0RateUfors1 [1] : float
            EXTGYR0 axis-1 Angular rate
        float__Gyr0RateUfors2 [1] : float
            EXTGYR0 axis-2  Angular rate
        float__Gyr0RateUfors3 [1] : float
            EXTGYR0 axis-3  Angular rate
        bool__Gyr0NogoUfors1 [1] : int
            EXTGYR0 axis-1 Status - NOGO bit
        bool__Gyr0RstAckUfors1 [1] : int
            EXTGYR0 axis-1 Status - Reset acknowledge bit
        bool__Gyr0TempWarnUfors1 [1] : int
            EXTGYR0 axis-1 Status - temperature warning bit
        bool__Gyr0AuxControlLoopErrUfors1 [1] : int
            EXTGYR0 axis-1 Status - auxillary control loop error bit
        bool__Gyr0HardBitErrUfors1 [1] : int
            EXTGYR0 axis-1 Status - Hardware BIT error bit
        bool__Gyr0MeasRangeErrUfors1 [1] : int
            EXTGYR0 axis-1 Status - Measurement range exceeded bit
        bool__Gyr0UnknwnCmdUfors1 [1] : int
            EXTGYR0 axis-1 Status - unknown command bit
        bool__Gyr0NogoUfors2 [1] : int
            EXTGYR0 axis-2  Status - NOGO bit
        bool__Gyr0RstAckUfors2 [1] : int
            EXTGYR0 axis-2  Status - Reset acknowledge bit
        bool__Gyr0TempWarnUfors2 [1] : int
            EXTGYR0 axis-2  Status - temperature warning bit
        bool__Gyr0AuxControlLoopErrUfors2 [1] : int
            EXTGYR0 axis-2  Status - auxillary control loop error bit
        bool__Gyr0HardBitErrUfors2 [1] : int
            EXTGYR0 axis-2  Status - Hardware BIT error bit
        bool__Gyr0MeasRangeErrUfors2 [1] : int
            EXTGYR0 axis-2  Status - Measurement range exceeded bit
        bool__Gyr0UnknwnCmdUfors2 [1] : int
            EXTGYR0 axis-2  Status - unknown command bit
        bool__Gyr0NogoUfors3 [1] : int
            EXTGYR0 axis-3  Status - NOGO bit
        bool__Gyr0RstAckUfors3 [1] : int
            EXTGYR0 axis-3  Status - Reset acknowledge bit
        bool__Gyr0TempWarnUfors3 [1] : int
            EXTGYR0 axis-3  Status - temperature warning bit
        bool__Gyr0AuxControlLoopErrUfors3 [1] : int
            EXTGYR0 axis-3  Status - auxillary control loop error bit
        bool__Gyr0HardBitErrUfors3 [1] : int
            EXTGYR0 axis-3  Status - Hardware BIT error bit
        bool__Gyr0MeasRangeErrUfors3 [1] : int
            EXTGYR0 axis-3  Status - Measurement range exceeded bit
        bool__Gyr0UnknwnCmdUfors3 [1] : int
            EXTGYR0 axis-3  Status - unknown command bit
        float__Gyr1RateUfors1 [1] : float
            EXTGYR1 axis-1 Angular rate
        float__Gyr1RateUfors2 [1] : float
            EXTGYR1 axis-2  Angular rate
        float__Gyr1RateUfors3 [1] : float
            EXTGYR1 axis-3  Angular rate
        bool__Gyr1NogoUfors1 [1] : int
            EXTGYR1 axis-1Status - NOGO bit
        bool__Gyr1RstAckUfors1 [1] : int
            EXTGYR1 axis-1 Status - Reset acknowledge bit
        bool__Gyr1TempWarnUfors1 [1] : int
            EXTGYR1 axis-1 Status - temperature warning bit
        bool__Gyr1AuxControlLoopErrUfors1 [1] : int
            EXTGYR1 axis-1 Status - auxillary control loop error bit
        bool__Gyr1HardBitErrUfors1 [1] : int
            EXTGYR1 axis-1 Status - Hardware BIT error bit
        bool__Gyr1MeasRangeErrUfors1 [1] : int
            EXTGYR1 axis-1 Status - Measurement range exceeded bit
        bool__Gyr1UnknwnCmdUfors1 [1] : int
            EXTGYR1 axis-1 Status - unknown command bit
        bool__Gyr1NogoUfors2 [1] : int
            EXTGYR1 axis-2  Status - NOGO bit
        bool__Gyr1RstAckUfors2 [1] : int
            EXTGYR1 axis-2  Status - Reset acknowledge bit
        bool__Gyr1TempWarnUfors2 [1] : int
            EXTGYR1 axis-2  Status - temperature warning bit
        bool__Gyr1AuxControlLoopErrUfors2 [1] : int
            EXTGYR1 axis-2  Status - auxillary control loop error bit
        bool__Gyr1HardBitErrUfors2 [1] : int
            EXTGYR1 axis-2  Status - Hardware BIT error bit
        bool__Gyr1MeasRangeErrUfors2 [1] : int
            EXTGYR1 axis-2  Status - Measurement range exceeded bit
        bool__Gyr1UnknwnCmdUfors2 [1] : int
            EXTGYR1 axis-2  Status - unknown command bit
        bool__Gyr1NogoUfors3 [1] : int
            EXTGYR1 axis-3  Status - NOGO bit
        bool__Gyr1RstAckUfors3 [1] : int
            EXTGYR1 axis-3  Status - Reset acknowledge bit
        bool__Gyr1TempWarnUfors3 [1] : int
            EXTGYR1 axis-3  Status - temperature warning bit
        bool__Gyr1AuxControlLoopErrUfors3 [1] : int
            EXTGYR1 axis-3  Status - auxillary control loop error bit
        bool__Gyr1HardBitErrUfors3 [1] : int
            EXTGYR1 axis-3  Status - Hardware BIT error bit
        bool__Gyr1MeasRangeErrUfors3 [1] : int
            EXTGYR1 axis-3  Status - Measurement range exceeded bit
        bool__Gyr1UnknwnCmdUfors3 [1] : int
            EXTGYR1 axis-3  Status - unknown command bit
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_Gyr0RateUfors1(self) -> float:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0RateUfors1' structure field
        
        EXTGYR0 axis-1 Angular rate
        """
        
        pass
    
    def get_Gyr0RateUfors2(self) -> float:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0RateUfors2' structure field
        
        EXTGYR0 axis-2  Angular rate
        """
        
        pass
    
    def get_Gyr0RateUfors3(self) -> float:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0RateUfors3' structure field
        
        EXTGYR0 axis-3  Angular rate
        """
        
        pass
    
    def get_Gyr0NogoUfors1(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0NogoUfors1' structure field
        
        EXTGYR0 axis-1 Status - NOGO bit
        """
        
        pass
    
    def get_Gyr0RstAckUfors1(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0RstAckUfors1' structure field
        
        EXTGYR0 axis-1 Status - Reset acknowledge bit
        """
        
        pass
    
    def get_Gyr0TempWarnUfors1(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0TempWarnUfors1' structure field
        
        EXTGYR0 axis-1 Status - temperature warning bit
        """
        
        pass
    
    def get_Gyr0AuxControlLoopErrUfors1(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0AuxControlLoopErrUfors1' structure field
        
        EXTGYR0 axis-1 Status - auxillary control loop error bit
        """
        
        pass
    
    def get_Gyr0HardBitErrUfors1(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0HardBitErrUfors1' structure field
        
        EXTGYR0 axis-1 Status - Hardware BIT error bit
        """
        
        pass
    
    def get_Gyr0MeasRangeErrUfors1(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0MeasRangeErrUfors1' structure field
        
        EXTGYR0 axis-1 Status - Measurement range exceeded bit
        """
        
        pass
    
    def get_Gyr0UnknwnCmdUfors1(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0UnknwnCmdUfors1' structure field
        
        EXTGYR0 axis-1 Status - unknown command bit
        """
        
        pass
    
    def get_Gyr0NogoUfors2(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0NogoUfors2' structure field
        
        EXTGYR0 axis-2  Status - NOGO bit
        """
        
        pass
    
    def get_Gyr0RstAckUfors2(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0RstAckUfors2' structure field
        
        EXTGYR0 axis-2  Status - Reset acknowledge bit
        """
        
        pass
    
    def get_Gyr0TempWarnUfors2(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0TempWarnUfors2' structure field
        
        EXTGYR0 axis-2  Status - temperature warning bit
        """
        
        pass
    
    def get_Gyr0AuxControlLoopErrUfors2(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0AuxControlLoopErrUfors2' structure field
        
        EXTGYR0 axis-2  Status - auxillary control loop error bit
        """
        
        pass
    
    def get_Gyr0HardBitErrUfors2(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0HardBitErrUfors2' structure field
        
        EXTGYR0 axis-2  Status - Hardware BIT error bit
        """
        
        pass
    
    def get_Gyr0MeasRangeErrUfors2(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0MeasRangeErrUfors2' structure field
        
        EXTGYR0 axis-2  Status - Measurement range exceeded bit
        """
        
        pass
    
    def get_Gyr0UnknwnCmdUfors2(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0UnknwnCmdUfors2' structure field
        
        EXTGYR0 axis-2  Status - unknown command bit
        """
        
        pass
    
    def get_Gyr0NogoUfors3(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0NogoUfors3' structure field
        
        EXTGYR0 axis-3  Status - NOGO bit
        """
        
        pass
    
    def get_Gyr0RstAckUfors3(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0RstAckUfors3' structure field
        
        EXTGYR0 axis-3  Status - Reset acknowledge bit
        """
        
        pass
    
    def get_Gyr0TempWarnUfors3(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0TempWarnUfors3' structure field
        
        EXTGYR0 axis-3  Status - temperature warning bit
        """
        
        pass
    
    def get_Gyr0AuxControlLoopErrUfors3(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0AuxControlLoopErrUfors3' structure field
        
        EXTGYR0 axis-3  Status - auxillary control loop error bit
        """
        
        pass
    
    def get_Gyr0HardBitErrUfors3(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0HardBitErrUfors3' structure field
        
        EXTGYR0 axis-3  Status - Hardware BIT error bit
        """
        
        pass
    
    def get_Gyr0MeasRangeErrUfors3(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0MeasRangeErrUfors3' structure field
        
        EXTGYR0 axis-3  Status - Measurement range exceeded bit
        """
        
        pass
    
    def get_Gyr0UnknwnCmdUfors3(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr0UnknwnCmdUfors3' structure field
        
        EXTGYR0 axis-3  Status - unknown command bit
        """
        
        pass
    
    def get_Gyr1RateUfors1(self) -> float:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1RateUfors1' structure field
        
        EXTGYR1 axis-1 Angular rate
        """
        
        pass
    
    def get_Gyr1RateUfors2(self) -> float:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1RateUfors2' structure field
        
        EXTGYR1 axis-2  Angular rate
        """
        
        pass
    
    def get_Gyr1RateUfors3(self) -> float:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1RateUfors3' structure field
        
        EXTGYR1 axis-3  Angular rate
        """
        
        pass
    
    def get_Gyr1NogoUfors1(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1NogoUfors1' structure field
        
        EXTGYR1 axis-1Status - NOGO bit
        """
        
        pass
    
    def get_Gyr1RstAckUfors1(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1RstAckUfors1' structure field
        
        EXTGYR1 axis-1 Status - Reset acknowledge bit
        """
        
        pass
    
    def get_Gyr1TempWarnUfors1(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1TempWarnUfors1' structure field
        
        EXTGYR1 axis-1 Status - temperature warning bit
        """
        
        pass
    
    def get_Gyr1AuxControlLoopErrUfors1(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1AuxControlLoopErrUfors1' structure field
        
        EXTGYR1 axis-1 Status - auxillary control loop error bit
        """
        
        pass
    
    def get_Gyr1HardBitErrUfors1(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1HardBitErrUfors1' structure field
        
        EXTGYR1 axis-1 Status - Hardware BIT error bit
        """
        
        pass
    
    def get_Gyr1MeasRangeErrUfors1(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1MeasRangeErrUfors1' structure field
        
        EXTGYR1 axis-1 Status - Measurement range exceeded bit
        """
        
        pass
    
    def get_Gyr1UnknwnCmdUfors1(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1UnknwnCmdUfors1' structure field
        
        EXTGYR1 axis-1 Status - unknown command bit
        """
        
        pass
    
    def get_Gyr1NogoUfors2(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1NogoUfors2' structure field
        
        EXTGYR1 axis-2  Status - NOGO bit
        """
        
        pass
    
    def get_Gyr1RstAckUfors2(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1RstAckUfors2' structure field
        
        EXTGYR1 axis-2  Status - Reset acknowledge bit
        """
        
        pass
    
    def get_Gyr1TempWarnUfors2(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1TempWarnUfors2' structure field
        
        EXTGYR1 axis-2  Status - temperature warning bit
        """
        
        pass
    
    def get_Gyr1AuxControlLoopErrUfors2(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1AuxControlLoopErrUfors2' structure field
        
        EXTGYR1 axis-2  Status - auxillary control loop error bit
        """
        
        pass
    
    def get_Gyr1HardBitErrUfors2(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1HardBitErrUfors2' structure field
        
        EXTGYR1 axis-2  Status - Hardware BIT error bit
        """
        
        pass
    
    def get_Gyr1MeasRangeErrUfors2(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1MeasRangeErrUfors2' structure field
        
        EXTGYR1 axis-2  Status - Measurement range exceeded bit
        """
        
        pass
    
    def get_Gyr1UnknwnCmdUfors2(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1UnknwnCmdUfors2' structure field
        
        EXTGYR1 axis-2  Status - unknown command bit
        """
        
        pass
    
    def get_Gyr1NogoUfors3(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1NogoUfors3' structure field
        
        EXTGYR1 axis-3  Status - NOGO bit
        """
        
        pass
    
    def get_Gyr1RstAckUfors3(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1RstAckUfors3' structure field
        
        EXTGYR1 axis-3  Status - Reset acknowledge bit
        """
        
        pass
    
    def get_Gyr1TempWarnUfors3(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1TempWarnUfors3' structure field
        
        EXTGYR1 axis-3  Status - temperature warning bit
        """
        
        pass
    
    def get_Gyr1AuxControlLoopErrUfors3(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1AuxControlLoopErrUfors3' structure field
        
        EXTGYR1 axis-3  Status - auxillary control loop error bit
        """
        
        pass
    
    def get_Gyr1HardBitErrUfors3(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1HardBitErrUfors3' structure field
        
        EXTGYR1 axis-3  Status - Hardware BIT error bit
        """
        
        pass
    
    def get_Gyr1MeasRangeErrUfors3(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1MeasRangeErrUfors3' structure field
        
        EXTGYR1 axis-3  Status - Measurement range exceeded bit
        """
        
        pass
    
    def get_Gyr1UnknwnCmdUfors3(self) -> int:
        """
        A getter for the 'TlmGyrLitefuforsRaw::Gyr1UnknwnCmdUfors3' structure field
        
        EXTGYR1 axis-3  Status - unknown command bit
        """
        
        pass

def TlmGyrLitefuforsRaw_make_from_buf(buf : bytes) -> TlmGyrLitefuforsRaw:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmRwlNssRwlRaw:
    """
    A Python class to represent struct objects of type 'TlmRwlNssRwlRaw'
    
    Parameter structure for interface TlmRwlNssRwlRaw
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, int16__Rwl0TargetValue : int, float__Rwl0MeasSpeed : float, int16__Rwl0MeasCurrent : int, int16__Rwl0Temp : int, int16__Rwl1TargetValue : int, float__Rwl1MeasSpeed : float, int16__Rwl1MeasCurrent : int, int16__Rwl1Temp : int, int16__Rwl2TargetValue : int, float__Rwl2MeasSpeed : float, int16__Rwl2MeasCurrent : int, int16__Rwl2Temp : int, int16__Rwl3TargetValue : int, float__Rwl3MeasSpeed : float, int16__Rwl3MeasCurrent : int, int16__Rwl3Temp : int, bool__Rwl0IsValid : int, bool__Rwl0WheelMode : int, bool__Rwl0CurentCtrlMode : int, bool__Rwl0SpeedCtrlMode : int, bool__Rwl0TorqueCtrlMode : int, bool__Rwl0CrcError : int, bool__Rwl0WrongLlCmd : int, bool__Rwl0WrongHlCmd : int, bool__Rwl0ToutSci1Main : int, bool__Rwl1IsValid : int, bool__Rwl1WheelMode : int, bool__Rwl1CurentCtrlMode : int, bool__Rwl1SpeedCtrlMode : int, bool__Rwl1TorqueCtrlMode : int, bool__Rwl1CrcError : int, bool__Rwl1WrongLlCmd : int, bool__Rwl1WrongHlCmd : int, bool__Rwl1ToutSci1Main : int, bool__Rwl2IsValid : int, bool__Rwl2WheelMode : int, bool__Rwl2CurentCtrlMode : int, bool__Rwl2SpeedCtrlMode : int, bool__Rwl2TorqueCtrlMode : int, bool__Rwl2CrcError : int, bool__Rwl2WrongLlCmd : int, bool__Rwl2WrongHlCmd : int, bool__Rwl2ToutSci1Main : int, bool__Rwl3IsValid : int, bool__Rwl3WheelMode : int, bool__Rwl3CurentCtrlMode : int, bool__Rwl3SpeedCtrlMode : int, bool__Rwl3TorqueCtrlMode : int, bool__Rwl3CrcError : int, bool__Rwl3WrongLlCmd : int, bool__Rwl3WrongHlCmd : int, bool__Rwl3ToutSci1Main : int) -> None:
        """
        Struct 'TlmRwlNssRwlRaw' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        int16__Rwl0TargetValue [1] : int
            RWL0 target value
        float__Rwl0MeasSpeed [1] : float
            RWL0 measured speed
        int16__Rwl0MeasCurrent [1] : int
            RWL0 measured current
        int16__Rwl0Temp [1] : int
            RWL0 NSSRWL temperature (not CubeNode)
        int16__Rwl1TargetValue [1] : int
            RWL1 target value
        float__Rwl1MeasSpeed [1] : float
            RWL1 measured speed
        int16__Rwl1MeasCurrent [1] : int
            RWL1 measured current
        int16__Rwl1Temp [1] : int
            RWL1 NSSRWL temperature (not CubeNode)
        int16__Rwl2TargetValue [1] : int
            RWL2 target value
        float__Rwl2MeasSpeed [1] : float
            RWL2 measured speed
        int16__Rwl2MeasCurrent [1] : int
            RWL2 measured current
        int16__Rwl2Temp [1] : int
            RWL2 NSSRWL temperature (not CubeNode)
        int16__Rwl3TargetValue [1] : int
            RWL3 target value
        float__Rwl3MeasSpeed [1] : float
            RWL3 measured speed
        int16__Rwl3MeasCurrent [1] : int
            RWL3 measured current
        int16__Rwl3Temp [1] : int
            RWL3 NSSRWL temperature (not CubeNode)
        bool__Rwl0IsValid [1] : int
            RWL0 valid flag
        bool__Rwl0WheelMode [1] : int
            RWL0 Set if in reaction wheel mode
        bool__Rwl0CurentCtrlMode [1] : int
            RWL0 Set if in current-control mode
        bool__Rwl0SpeedCtrlMode [1] : int
            RWL0 Set if in speed-control mode
        bool__Rwl0TorqueCtrlMode [1] : int
            RWL0 Set if in torque-control mode
        bool__Rwl0CrcError [1] : int
            RWL0 Set if CRC error on protected area
        bool__Rwl0WrongLlCmd [1] : int
            RWL0 wrong low-level command
        bool__Rwl0WrongHlCmd [1] : int
            RWL0 wrong high-level command
        bool__Rwl0ToutSci1Main [1] : int
            RWL0 Timeout on SCI1 main interface
        bool__Rwl1IsValid [1] : int
            RWL1 valid flag
        bool__Rwl1WheelMode [1] : int
            RWL1 Set if in reaction wheel mode
        bool__Rwl1CurentCtrlMode [1] : int
            RWL1 Set if in current-control mode
        bool__Rwl1SpeedCtrlMode [1] : int
            RWL1 Set if in speed-control mode
        bool__Rwl1TorqueCtrlMode [1] : int
            RWL1 Set if in torque-control mode
        bool__Rwl1CrcError [1] : int
            RWL1 Set if CRC error on protected area
        bool__Rwl1WrongLlCmd [1] : int
            RWL1 wrong low-level command
        bool__Rwl1WrongHlCmd [1] : int
            RWL1 wrong high-level command
        bool__Rwl1ToutSci1Main [1] : int
            RWL1 Timeout on SCI1 main interface
        bool__Rwl2IsValid [1] : int
            RWL2 valid flag
        bool__Rwl2WheelMode [1] : int
            RWL2 Set if in reaction wheel mode
        bool__Rwl2CurentCtrlMode [1] : int
            RWL2 Set if in current-control mode
        bool__Rwl2SpeedCtrlMode [1] : int
            RWL2 Set if in speed-control mode
        bool__Rwl2TorqueCtrlMode [1] : int
            RWL2 Set if in torque-control mode
        bool__Rwl2CrcError [1] : int
            RWL2 Set if CRC error on protected area
        bool__Rwl2WrongLlCmd [1] : int
            RWL2 wrong low-level command
        bool__Rwl2WrongHlCmd [1] : int
            RWL2 wrong high-level command
        bool__Rwl2ToutSci1Main [1] : int
            RWL2 Timeout on SCI1 main interface
        bool__Rwl3IsValid [1] : int
            RWL3 valid flag
        bool__Rwl3WheelMode [1] : int
            RWL3 Set if in reaction wheel mode
        bool__Rwl3CurentCtrlMode [1] : int
            RWL3 Set if in current-control mode
        bool__Rwl3SpeedCtrlMode [1] : int
            RWL3 Set if in speed-control mode
        bool__Rwl3TorqueCtrlMode [1] : int
            RWL3 Set if in torque-control mode
        bool__Rwl3CrcError [1] : int
            RWL3 Set if CRC error on protected area
        bool__Rwl3WrongLlCmd [1] : int
            RWL3 wrong low-level command
        bool__Rwl3WrongHlCmd [1] : int
            RWL3 wrong high-level command
        bool__Rwl3ToutSci1Main [1] : int
            RWL3 Timeout on SCI1 main interface
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_Rwl0TargetValue(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl0TargetValue' structure field
        
        RWL0 target value
        """
        
        pass
    
    def get_Rwl0MeasSpeed(self) -> float:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl0MeasSpeed' structure field
        
        RWL0 measured speed
        """
        
        pass
    
    def get_Rwl0MeasCurrent(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl0MeasCurrent' structure field
        
        RWL0 measured current
        """
        
        pass
    
    def get_Rwl0Temp(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl0Temp' structure field
        
        RWL0 NSSRWL temperature (not CubeNode)
        """
        
        pass
    
    def get_Rwl1TargetValue(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl1TargetValue' structure field
        
        RWL1 target value
        """
        
        pass
    
    def get_Rwl1MeasSpeed(self) -> float:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl1MeasSpeed' structure field
        
        RWL1 measured speed
        """
        
        pass
    
    def get_Rwl1MeasCurrent(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl1MeasCurrent' structure field
        
        RWL1 measured current
        """
        
        pass
    
    def get_Rwl1Temp(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl1Temp' structure field
        
        RWL1 NSSRWL temperature (not CubeNode)
        """
        
        pass
    
    def get_Rwl2TargetValue(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl2TargetValue' structure field
        
        RWL2 target value
        """
        
        pass
    
    def get_Rwl2MeasSpeed(self) -> float:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl2MeasSpeed' structure field
        
        RWL2 measured speed
        """
        
        pass
    
    def get_Rwl2MeasCurrent(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl2MeasCurrent' structure field
        
        RWL2 measured current
        """
        
        pass
    
    def get_Rwl2Temp(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl2Temp' structure field
        
        RWL2 NSSRWL temperature (not CubeNode)
        """
        
        pass
    
    def get_Rwl3TargetValue(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl3TargetValue' structure field
        
        RWL3 target value
        """
        
        pass
    
    def get_Rwl3MeasSpeed(self) -> float:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl3MeasSpeed' structure field
        
        RWL3 measured speed
        """
        
        pass
    
    def get_Rwl3MeasCurrent(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl3MeasCurrent' structure field
        
        RWL3 measured current
        """
        
        pass
    
    def get_Rwl3Temp(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl3Temp' structure field
        
        RWL3 NSSRWL temperature (not CubeNode)
        """
        
        pass
    
    def get_Rwl0IsValid(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl0IsValid' structure field
        
        RWL0 valid flag
        """
        
        pass
    
    def get_Rwl0WheelMode(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl0WheelMode' structure field
        
        RWL0 Set if in reaction wheel mode
        """
        
        pass
    
    def get_Rwl0CurentCtrlMode(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl0CurentCtrlMode' structure field
        
        RWL0 Set if in current-control mode
        """
        
        pass
    
    def get_Rwl0SpeedCtrlMode(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl0SpeedCtrlMode' structure field
        
        RWL0 Set if in speed-control mode
        """
        
        pass
    
    def get_Rwl0TorqueCtrlMode(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl0TorqueCtrlMode' structure field
        
        RWL0 Set if in torque-control mode
        """
        
        pass
    
    def get_Rwl0CrcError(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl0CrcError' structure field
        
        RWL0 Set if CRC error on protected area
        """
        
        pass
    
    def get_Rwl0WrongLlCmd(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl0WrongLlCmd' structure field
        
        RWL0 wrong low-level command
        """
        
        pass
    
    def get_Rwl0WrongHlCmd(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl0WrongHlCmd' structure field
        
        RWL0 wrong high-level command
        """
        
        pass
    
    def get_Rwl0ToutSci1Main(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl0ToutSci1Main' structure field
        
        RWL0 Timeout on SCI1 main interface
        """
        
        pass
    
    def get_Rwl1IsValid(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl1IsValid' structure field
        
        RWL1 valid flag
        """
        
        pass
    
    def get_Rwl1WheelMode(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl1WheelMode' structure field
        
        RWL1 Set if in reaction wheel mode
        """
        
        pass
    
    def get_Rwl1CurentCtrlMode(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl1CurentCtrlMode' structure field
        
        RWL1 Set if in current-control mode
        """
        
        pass
    
    def get_Rwl1SpeedCtrlMode(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl1SpeedCtrlMode' structure field
        
        RWL1 Set if in speed-control mode
        """
        
        pass
    
    def get_Rwl1TorqueCtrlMode(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl1TorqueCtrlMode' structure field
        
        RWL1 Set if in torque-control mode
        """
        
        pass
    
    def get_Rwl1CrcError(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl1CrcError' structure field
        
        RWL1 Set if CRC error on protected area
        """
        
        pass
    
    def get_Rwl1WrongLlCmd(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl1WrongLlCmd' structure field
        
        RWL1 wrong low-level command
        """
        
        pass
    
    def get_Rwl1WrongHlCmd(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl1WrongHlCmd' structure field
        
        RWL1 wrong high-level command
        """
        
        pass
    
    def get_Rwl1ToutSci1Main(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl1ToutSci1Main' structure field
        
        RWL1 Timeout on SCI1 main interface
        """
        
        pass
    
    def get_Rwl2IsValid(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl2IsValid' structure field
        
        RWL2 valid flag
        """
        
        pass
    
    def get_Rwl2WheelMode(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl2WheelMode' structure field
        
        RWL2 Set if in reaction wheel mode
        """
        
        pass
    
    def get_Rwl2CurentCtrlMode(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl2CurentCtrlMode' structure field
        
        RWL2 Set if in current-control mode
        """
        
        pass
    
    def get_Rwl2SpeedCtrlMode(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl2SpeedCtrlMode' structure field
        
        RWL2 Set if in speed-control mode
        """
        
        pass
    
    def get_Rwl2TorqueCtrlMode(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl2TorqueCtrlMode' structure field
        
        RWL2 Set if in torque-control mode
        """
        
        pass
    
    def get_Rwl2CrcError(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl2CrcError' structure field
        
        RWL2 Set if CRC error on protected area
        """
        
        pass
    
    def get_Rwl2WrongLlCmd(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl2WrongLlCmd' structure field
        
        RWL2 wrong low-level command
        """
        
        pass
    
    def get_Rwl2WrongHlCmd(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl2WrongHlCmd' structure field
        
        RWL2 wrong high-level command
        """
        
        pass
    
    def get_Rwl2ToutSci1Main(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl2ToutSci1Main' structure field
        
        RWL2 Timeout on SCI1 main interface
        """
        
        pass
    
    def get_Rwl3IsValid(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl3IsValid' structure field
        
        RWL3 valid flag
        """
        
        pass
    
    def get_Rwl3WheelMode(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl3WheelMode' structure field
        
        RWL3 Set if in reaction wheel mode
        """
        
        pass
    
    def get_Rwl3CurentCtrlMode(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl3CurentCtrlMode' structure field
        
        RWL3 Set if in current-control mode
        """
        
        pass
    
    def get_Rwl3SpeedCtrlMode(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl3SpeedCtrlMode' structure field
        
        RWL3 Set if in speed-control mode
        """
        
        pass
    
    def get_Rwl3TorqueCtrlMode(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl3TorqueCtrlMode' structure field
        
        RWL3 Set if in torque-control mode
        """
        
        pass
    
    def get_Rwl3CrcError(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl3CrcError' structure field
        
        RWL3 Set if CRC error on protected area
        """
        
        pass
    
    def get_Rwl3WrongLlCmd(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl3WrongLlCmd' structure field
        
        RWL3 wrong low-level command
        """
        
        pass
    
    def get_Rwl3WrongHlCmd(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl3WrongHlCmd' structure field
        
        RWL3 wrong high-level command
        """
        
        pass
    
    def get_Rwl3ToutSci1Main(self) -> int:
        """
        A getter for the 'TlmRwlNssRwlRaw::Rwl3ToutSci1Main' structure field
        
        RWL3 Timeout on SCI1 main interface
        """
        
        pass

def TlmRwlNssRwlRaw_make_from_buf(buf : bytes) -> TlmRwlNssRwlRaw:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ConfigOrbitSatParams:
    """
    A Python class to represent struct objects of type 'ConfigOrbitSatParams'
    
    Parameter structure for interface ConfigOrbitSatParams
    """

    def __init__(self, double__OrbitEpoch : float, double__OrbitIncl : float, double__OrbitRaan : float, double__OrbitEccen : float, double__OrbitAP : float, double__OrbitMA : float, double__OrbitMM : float, double__OrbitBstar : float) -> None:
        """
        Struct 'ConfigOrbitSatParams' constructor
        
        Attributes
        ---------
        double__OrbitEpoch [1] : float
            Orbit epoch
        double__OrbitIncl [1] : float
            Orbit inclination
        double__OrbitRaan [1] : float
            Orbit RAAN
        double__OrbitEccen [1] : float
            Orbit eccentricity
        double__OrbitAP [1] : float
            Orbit argument of perigee
        double__OrbitMA [1] : float
            Orbit mean anomaly
        double__OrbitMM [1] : float
            Orbit mean motion
        double__OrbitBstar [1] : float
            Orbit B-star drag term
        """
        
        pass
        
    def get_OrbitEpoch(self) -> float:
        """
        A getter for the 'ConfigOrbitSatParams::OrbitEpoch' structure field
        
        Orbit epoch
        """
        
        pass
    
    def get_OrbitIncl(self) -> float:
        """
        A getter for the 'ConfigOrbitSatParams::OrbitIncl' structure field
        
        Orbit inclination
        """
        
        pass
    
    def get_OrbitRaan(self) -> float:
        """
        A getter for the 'ConfigOrbitSatParams::OrbitRaan' structure field
        
        Orbit RAAN
        """
        
        pass
    
    def get_OrbitEccen(self) -> float:
        """
        A getter for the 'ConfigOrbitSatParams::OrbitEccen' structure field
        
        Orbit eccentricity
        """
        
        pass
    
    def get_OrbitAP(self) -> float:
        """
        A getter for the 'ConfigOrbitSatParams::OrbitAP' structure field
        
        Orbit argument of perigee
        """
        
        pass
    
    def get_OrbitMA(self) -> float:
        """
        A getter for the 'ConfigOrbitSatParams::OrbitMA' structure field
        
        Orbit mean anomaly
        """
        
        pass
    
    def get_OrbitMM(self) -> float:
        """
        A getter for the 'ConfigOrbitSatParams::OrbitMM' structure field
        
        Orbit mean motion
        """
        
        pass
    
    def get_OrbitBstar(self) -> float:
        """
        A getter for the 'ConfigOrbitSatParams::OrbitBstar' structure field
        
        Orbit B-star drag term
        """
        
        pass

def ConfigOrbitSatParams_make_from_buf(buf : bytes) -> ConfigOrbitSatParams:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmSensorRawGyro:
    """
    A Python class to represent struct objects of type 'TlmSensorRawGyro'
    
    Parameter structure for interface TlmSensorRawGyro
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, float__Gyro0RawRateX : float, float__Gyro0RawRateY : float, float__Gyro0RawRateZ : float, float__Gyro1RawRateX : float, float__Gyro1RawRateY : float, float__Gyro1RawRateZ : float, bool__Gyro0IsValid : int, bool__Gyro1IsValid : int) -> None:
        """
        Struct 'TlmSensorRawGyro' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        float__Gyro0RawRateX [1] : float
            GYR0 raw rate X component
        float__Gyro0RawRateY [1] : float
            GYR0 raw rate Y component
        float__Gyro0RawRateZ [1] : float
            GYR0 raw rate Z component
        float__Gyro1RawRateX [1] : float
            GYR1 raw rate X component
        float__Gyro1RawRateY [1] : float
            GYR1 raw rate Y component
        float__Gyro1RawRateZ [1] : float
            GYR1 raw rate Z component
        bool__Gyro0IsValid [1] : int
            GYR0 valid flag
        bool__Gyro1IsValid [1] : int
            GYR1 valid flag
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmSensorRawGyro::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmSensorRawGyro::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_Gyro0RawRateX(self) -> float:
        """
        A getter for the 'TlmSensorRawGyro::Gyro0RawRateX' structure field
        
        GYR0 raw rate X component
        """
        
        pass
    
    def get_Gyro0RawRateY(self) -> float:
        """
        A getter for the 'TlmSensorRawGyro::Gyro0RawRateY' structure field
        
        GYR0 raw rate Y component
        """
        
        pass
    
    def get_Gyro0RawRateZ(self) -> float:
        """
        A getter for the 'TlmSensorRawGyro::Gyro0RawRateZ' structure field
        
        GYR0 raw rate Z component
        """
        
        pass
    
    def get_Gyro1RawRateX(self) -> float:
        """
        A getter for the 'TlmSensorRawGyro::Gyro1RawRateX' structure field
        
        GYR1 raw rate X component
        """
        
        pass
    
    def get_Gyro1RawRateY(self) -> float:
        """
        A getter for the 'TlmSensorRawGyro::Gyro1RawRateY' structure field
        
        GYR1 raw rate Y component
        """
        
        pass
    
    def get_Gyro1RawRateZ(self) -> float:
        """
        A getter for the 'TlmSensorRawGyro::Gyro1RawRateZ' structure field
        
        GYR1 raw rate Z component
        """
        
        pass
    
    def get_Gyro0IsValid(self) -> int:
        """
        A getter for the 'TlmSensorRawGyro::Gyro0IsValid' structure field
        
        GYR0 valid flag
        """
        
        pass
    
    def get_Gyro1IsValid(self) -> int:
        """
        A getter for the 'TlmSensorRawGyro::Gyro1IsValid' structure field
        
        GYR1 valid flag
        """
        
        pass

def TlmSensorRawGyro_make_from_buf(buf : bytes) -> TlmSensorRawGyro:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ReferenceIrcVector:
    """
    A Python class to represent struct objects of type 'ReferenceIrcVector'
    
    Parameter structure for interface ReferenceIrcVector
    """

    def __init__(self, float__CmdEciVecX : float, float__CmdEciVecY : float, float__CmdEciVecZ : float) -> None:
        """
        Struct 'ReferenceIrcVector' constructor
        
        Attributes
        ---------
        float__CmdEciVecX [1] : float
            Commanded ECI pointing vector X component
        float__CmdEciVecY [1] : float
            Commanded ECI pointing vector Y component
        float__CmdEciVecZ [1] : float
            Commanded ECI pointing vector Z component
        """
        
        pass
        
    def get_CmdEciVecX(self) -> float:
        """
        A getter for the 'ReferenceIrcVector::CmdEciVecX' structure field
        
        Commanded ECI pointing vector X component
        """
        
        pass
    
    def get_CmdEciVecY(self) -> float:
        """
        A getter for the 'ReferenceIrcVector::CmdEciVecY' structure field
        
        Commanded ECI pointing vector Y component
        """
        
        pass
    
    def get_CmdEciVecZ(self) -> float:
        """
        A getter for the 'ReferenceIrcVector::CmdEciVecZ' structure field
        
        Commanded ECI pointing vector Z component
        """
        
        pass

def ReferenceIrcVector_make_from_buf(buf : bytes) -> ReferenceIrcVector:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmLitefuforsHealth:
    """
    A Python class to represent struct objects of type 'TlmLitefuforsHealth'
    
    Parameter structure for interface TlmLitefuforsHealth
    """

    def __init__(self, double__Gyr0McuTemp : float, double__Gyr0McuCurrent : float, uint16__Gyr0McuVoltage : int, double__Gyr0Current1 : float, double__Gyr0Current2 : float, double__Gyr0Current3 : float, bool__Gyr0Overcurrent1 : int, bool__Gyr0Overcurrent2 : int, bool__Gyr0Overcurrent3 : int, double__Gyr1McuTemp : float, double__Gyr1McuCurrent : float, uint16__Gyr1McuVoltage : int, double__Gyr1Current1 : float, double__Gyr1Current2 : float, double__Gyr1Current3 : float, bool__Gyr1Overcurrent1 : int, bool__Gyr1Overcurrent2 : int, bool__Gyr1Overcurrent3 : int) -> None:
        """
        Struct 'TlmLitefuforsHealth' constructor
        
        Attributes
        ---------
        double__Gyr0McuTemp [1] : float
            EXTGYR0 MCU Temperature
        double__Gyr0McuCurrent [1] : float
            EXTGYR0 MCU current
        uint16__Gyr0McuVoltage [1] : int
            EXTGYR0 MCU supply voltage
        double__Gyr0Current1 [1] : float
            EXTGYR0 axis-1 current
        double__Gyr0Current2 [1] : float
            EXTGYR0 axis-2 current
        double__Gyr0Current3 [1] : float
            EXTGYR0 axis-3 current
        bool__Gyr0Overcurrent1 [1] : int
            EXTGYR0 axis-1 overcurrent
        bool__Gyr0Overcurrent2 [1] : int
            EXTGYR0 axis-2 overcurrent
        bool__Gyr0Overcurrent3 [1] : int
            EXTGYR0 axis-3 overcurrent
        double__Gyr1McuTemp [1] : float
            EXTGYR1 MCU Temperature
        double__Gyr1McuCurrent [1] : float
            EXTGYR1 MCU current
        uint16__Gyr1McuVoltage [1] : int
            EXTGYR1 MCU supply voltage
        double__Gyr1Current1 [1] : float
            EXTGYR1 axis-1 current
        double__Gyr1Current2 [1] : float
            EXTGYR1 axis-2 current
        double__Gyr1Current3 [1] : float
            EXTGYR1 axis-3 current
        bool__Gyr1Overcurrent1 [1] : int
            EXTGYR1 axis-1 overcurrent
        bool__Gyr1Overcurrent2 [1] : int
            EXTGYR1 axis-2 overcurrent
        bool__Gyr1Overcurrent3 [1] : int
            EXTGYR1 axis-3 overcurrent
        """
        
        pass
        
    def get_Gyr0McuTemp(self) -> float:
        """
        A getter for the 'TlmLitefuforsHealth::Gyr0McuTemp' structure field
        
        EXTGYR0 MCU Temperature
        """
        
        pass
    
    def get_Gyr0McuCurrent(self) -> float:
        """
        A getter for the 'TlmLitefuforsHealth::Gyr0McuCurrent' structure field
        
        EXTGYR0 MCU current
        """
        
        pass
    
    def get_Gyr0McuVoltage(self) -> int:
        """
        A getter for the 'TlmLitefuforsHealth::Gyr0McuVoltage' structure field
        
        EXTGYR0 MCU supply voltage
        """
        
        pass
    
    def get_Gyr0Current1(self) -> float:
        """
        A getter for the 'TlmLitefuforsHealth::Gyr0Current1' structure field
        
        EXTGYR0 axis-1 current
        """
        
        pass
    
    def get_Gyr0Current2(self) -> float:
        """
        A getter for the 'TlmLitefuforsHealth::Gyr0Current2' structure field
        
        EXTGYR0 axis-2 current
        """
        
        pass
    
    def get_Gyr0Current3(self) -> float:
        """
        A getter for the 'TlmLitefuforsHealth::Gyr0Current3' structure field
        
        EXTGYR0 axis-3 current
        """
        
        pass
    
    def get_Gyr0Overcurrent1(self) -> int:
        """
        A getter for the 'TlmLitefuforsHealth::Gyr0Overcurrent1' structure field
        
        EXTGYR0 axis-1 overcurrent
        """
        
        pass
    
    def get_Gyr0Overcurrent2(self) -> int:
        """
        A getter for the 'TlmLitefuforsHealth::Gyr0Overcurrent2' structure field
        
        EXTGYR0 axis-2 overcurrent
        """
        
        pass
    
    def get_Gyr0Overcurrent3(self) -> int:
        """
        A getter for the 'TlmLitefuforsHealth::Gyr0Overcurrent3' structure field
        
        EXTGYR0 axis-3 overcurrent
        """
        
        pass
    
    def get_Gyr1McuTemp(self) -> float:
        """
        A getter for the 'TlmLitefuforsHealth::Gyr1McuTemp' structure field
        
        EXTGYR1 MCU Temperature
        """
        
        pass
    
    def get_Gyr1McuCurrent(self) -> float:
        """
        A getter for the 'TlmLitefuforsHealth::Gyr1McuCurrent' structure field
        
        EXTGYR1 MCU current
        """
        
        pass
    
    def get_Gyr1McuVoltage(self) -> int:
        """
        A getter for the 'TlmLitefuforsHealth::Gyr1McuVoltage' structure field
        
        EXTGYR1 MCU supply voltage
        """
        
        pass
    
    def get_Gyr1Current1(self) -> float:
        """
        A getter for the 'TlmLitefuforsHealth::Gyr1Current1' structure field
        
        EXTGYR1 axis-1 current
        """
        
        pass
    
    def get_Gyr1Current2(self) -> float:
        """
        A getter for the 'TlmLitefuforsHealth::Gyr1Current2' structure field
        
        EXTGYR1 axis-2 current
        """
        
        pass
    
    def get_Gyr1Current3(self) -> float:
        """
        A getter for the 'TlmLitefuforsHealth::Gyr1Current3' structure field
        
        EXTGYR1 axis-3 current
        """
        
        pass
    
    def get_Gyr1Overcurrent1(self) -> int:
        """
        A getter for the 'TlmLitefuforsHealth::Gyr1Overcurrent1' structure field
        
        EXTGYR1 axis-1 overcurrent
        """
        
        pass
    
    def get_Gyr1Overcurrent2(self) -> int:
        """
        A getter for the 'TlmLitefuforsHealth::Gyr1Overcurrent2' structure field
        
        EXTGYR1 axis-2 overcurrent
        """
        
        pass
    
    def get_Gyr1Overcurrent3(self) -> int:
        """
        A getter for the 'TlmLitefuforsHealth::Gyr1Overcurrent3' structure field
        
        EXTGYR1 axis-3 overcurrent
        """
        
        pass

def TlmLitefuforsHealth_make_from_buf(buf : bytes) -> TlmLitefuforsHealth:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmSensorRawMag:
    """
    A Python class to represent struct objects of type 'TlmSensorRawMag'
    
    Parameter structure for interface TlmSensorRawMag
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, double__Mag0RawVecX : float, double__Mag0RawVecY : float, double__Mag0RawVecZ : float, double__Mag1RawVecX : float, double__Mag1RawVecY : float, double__Mag1RawVecZ : float, bool__Mag0IsValid : int, bool__Mag1IsValid : int) -> None:
        """
        Struct 'TlmSensorRawMag' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        double__Mag0RawVecX [1] : float
            MAG0 raw vector X component
        double__Mag0RawVecY [1] : float
            MAG0 raw vector Y component
        double__Mag0RawVecZ [1] : float
            MAG0 raw vector Z component
        double__Mag1RawVecX [1] : float
            MAG1 raw vector X component
        double__Mag1RawVecY [1] : float
            MAG1 raw vector Y component
        double__Mag1RawVecZ [1] : float
            MAG1 raw vector Z component
        bool__Mag0IsValid [1] : int
            MAG0 valid flag
        bool__Mag1IsValid [1] : int
            MAG1 valid flag
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmSensorRawMag::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmSensorRawMag::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_Mag0RawVecX(self) -> float:
        """
        A getter for the 'TlmSensorRawMag::Mag0RawVecX' structure field
        
        MAG0 raw vector X component
        """
        
        pass
    
    def get_Mag0RawVecY(self) -> float:
        """
        A getter for the 'TlmSensorRawMag::Mag0RawVecY' structure field
        
        MAG0 raw vector Y component
        """
        
        pass
    
    def get_Mag0RawVecZ(self) -> float:
        """
        A getter for the 'TlmSensorRawMag::Mag0RawVecZ' structure field
        
        MAG0 raw vector Z component
        """
        
        pass
    
    def get_Mag1RawVecX(self) -> float:
        """
        A getter for the 'TlmSensorRawMag::Mag1RawVecX' structure field
        
        MAG1 raw vector X component
        """
        
        pass
    
    def get_Mag1RawVecY(self) -> float:
        """
        A getter for the 'TlmSensorRawMag::Mag1RawVecY' structure field
        
        MAG1 raw vector Y component
        """
        
        pass
    
    def get_Mag1RawVecZ(self) -> float:
        """
        A getter for the 'TlmSensorRawMag::Mag1RawVecZ' structure field
        
        MAG1 raw vector Z component
        """
        
        pass
    
    def get_Mag0IsValid(self) -> int:
        """
        A getter for the 'TlmSensorRawMag::Mag0IsValid' structure field
        
        MAG0 valid flag
        """
        
        pass
    
    def get_Mag1IsValid(self) -> int:
        """
        A getter for the 'TlmSensorRawMag::Mag1IsValid' structure field
        
        MAG1 valid flag
        """
        
        pass

def TlmSensorRawMag_make_from_buf(buf : bytes) -> TlmSensorRawMag:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmSensorCalGyro:
    """
    A Python class to represent struct objects of type 'TlmSensorCalGyro'
    
    Parameter structure for interface TlmSensorCalGyro
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, float__Gyro0CalRateX : float, float__Gyro0CalRateY : float, float__Gyro0CalRateZ : float, float__Gyro1CalRateX : float, float__Gyro1CalRateY : float, float__Gyro1CalRateZ : float, float__ExtGyro0CalRateX : float, float__ExtGyro0CalRateY : float, float__ExtGyro0CalRateZ : float, float__ExtGyro1CalRateX : float, float__ExtGyro1CalRateY : float, float__ExtGyro1CalRateZ : float, bool__Gyro0IsValid : int, bool__Gyro1IsValid : int, bool__ExtGyro0IsValid : int, bool__ExtGyro1IsValid : int) -> None:
        """
        Struct 'TlmSensorCalGyro' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        float__Gyro0CalRateX [1] : float
            GYR0 calibrated rate X component
        float__Gyro0CalRateY [1] : float
            GYR0 calibrated rate Y component
        float__Gyro0CalRateZ [1] : float
            GYR0 calibrated rate Z component
        float__Gyro1CalRateX [1] : float
            GYR1 calibrated rate X component
        float__Gyro1CalRateY [1] : float
            GYR1 calibrated rate Y component
        float__Gyro1CalRateZ [1] : float
            GYR1 calibrated rate Z component
        float__ExtGyro0CalRateX [1] : float
            EXTGYR0 calibrated rate X component
        float__ExtGyro0CalRateY [1] : float
            EXTGYR0 calibrated rate Y component
        float__ExtGyro0CalRateZ [1] : float
            EXTGYR0 calibrated rate Z component
        float__ExtGyro1CalRateX [1] : float
            EXTGYR1 calibrated rate X component
        float__ExtGyro1CalRateY [1] : float
            EXTGYR1 calibrated rate Y component
        float__ExtGyro1CalRateZ [1] : float
            EXTGYR1 calibrated rate Z component
        bool__Gyro0IsValid [1] : int
            GYR0 valid flag
        bool__Gyro1IsValid [1] : int
            GYR1 valid flag
        bool__ExtGyro0IsValid [1] : int
            EXTGYR0 valid flag
        bool__ExtGyro1IsValid [1] : int
            EXTGYR1 valid flag
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmSensorCalGyro::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmSensorCalGyro::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_Gyro0CalRateX(self) -> float:
        """
        A getter for the 'TlmSensorCalGyro::Gyro0CalRateX' structure field
        
        GYR0 calibrated rate X component
        """
        
        pass
    
    def get_Gyro0CalRateY(self) -> float:
        """
        A getter for the 'TlmSensorCalGyro::Gyro0CalRateY' structure field
        
        GYR0 calibrated rate Y component
        """
        
        pass
    
    def get_Gyro0CalRateZ(self) -> float:
        """
        A getter for the 'TlmSensorCalGyro::Gyro0CalRateZ' structure field
        
        GYR0 calibrated rate Z component
        """
        
        pass
    
    def get_Gyro1CalRateX(self) -> float:
        """
        A getter for the 'TlmSensorCalGyro::Gyro1CalRateX' structure field
        
        GYR1 calibrated rate X component
        """
        
        pass
    
    def get_Gyro1CalRateY(self) -> float:
        """
        A getter for the 'TlmSensorCalGyro::Gyro1CalRateY' structure field
        
        GYR1 calibrated rate Y component
        """
        
        pass
    
    def get_Gyro1CalRateZ(self) -> float:
        """
        A getter for the 'TlmSensorCalGyro::Gyro1CalRateZ' structure field
        
        GYR1 calibrated rate Z component
        """
        
        pass
    
    def get_ExtGyro0CalRateX(self) -> float:
        """
        A getter for the 'TlmSensorCalGyro::ExtGyro0CalRateX' structure field
        
        EXTGYR0 calibrated rate X component
        """
        
        pass
    
    def get_ExtGyro0CalRateY(self) -> float:
        """
        A getter for the 'TlmSensorCalGyro::ExtGyro0CalRateY' structure field
        
        EXTGYR0 calibrated rate Y component
        """
        
        pass
    
    def get_ExtGyro0CalRateZ(self) -> float:
        """
        A getter for the 'TlmSensorCalGyro::ExtGyro0CalRateZ' structure field
        
        EXTGYR0 calibrated rate Z component
        """
        
        pass
    
    def get_ExtGyro1CalRateX(self) -> float:
        """
        A getter for the 'TlmSensorCalGyro::ExtGyro1CalRateX' structure field
        
        EXTGYR1 calibrated rate X component
        """
        
        pass
    
    def get_ExtGyro1CalRateY(self) -> float:
        """
        A getter for the 'TlmSensorCalGyro::ExtGyro1CalRateY' structure field
        
        EXTGYR1 calibrated rate Y component
        """
        
        pass
    
    def get_ExtGyro1CalRateZ(self) -> float:
        """
        A getter for the 'TlmSensorCalGyro::ExtGyro1CalRateZ' structure field
        
        EXTGYR1 calibrated rate Z component
        """
        
        pass
    
    def get_Gyro0IsValid(self) -> int:
        """
        A getter for the 'TlmSensorCalGyro::Gyro0IsValid' structure field
        
        GYR0 valid flag
        """
        
        pass
    
    def get_Gyro1IsValid(self) -> int:
        """
        A getter for the 'TlmSensorCalGyro::Gyro1IsValid' structure field
        
        GYR1 valid flag
        """
        
        pass
    
    def get_ExtGyro0IsValid(self) -> int:
        """
        A getter for the 'TlmSensorCalGyro::ExtGyro0IsValid' structure field
        
        EXTGYR0 valid flag
        """
        
        pass
    
    def get_ExtGyro1IsValid(self) -> int:
        """
        A getter for the 'TlmSensorCalGyro::ExtGyro1IsValid' structure field
        
        EXTGYR1 valid flag
        """
        
        pass

def TlmSensorCalGyro_make_from_buf(buf : bytes) -> TlmSensorCalGyro:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class GnssSensorCmd:
    """
    A Python class to represent struct objects of type 'GnssSensorCmd'
    
    Parameter structure for interface GnssSensorCmd
    """

    def __init__(self, uint32__GnssTimeSeconds : int, uint32__GnssTimeNs : int, int32__GnssSatPosX : int, int32__GnssSatPosY : int, int32__GnssSatPosZ : int, int32__GnssSatVelX : int, int32__GnssSatVelY : int, int32__GnssSatVelZ : int, bool__SyncTime : int) -> None:
        """
        Struct 'GnssSensorCmd' constructor
        
        Attributes
        ---------
        uint32__GnssTimeSeconds [1] : int
            GNSS Unix time integer seconds
        uint32__GnssTimeNs [1] : int
            GNSS Unix time fraction nanoseconds
        int32__GnssSatPosX [1] : int
            Satellite position vector X component (GNSS frame)
        int32__GnssSatPosY [1] : int
            Satellite position vector Y component (GNSS frame)
        int32__GnssSatPosZ [1] : int
            Satellite position vector Z component (GNSS frame)
        int32__GnssSatVelX [1] : int
            Satellite velocity vector X component (GNSS frame)
        int32__GnssSatVelY [1] : int
            Satellite velocity vector Y component (GNSS frame)
        int32__GnssSatVelZ [1] : int
            Satellite velocity vector Z component (GNSS frame)
        bool__SyncTime [1] : int
            Flag to indicate if RTC should sync with unix time
        """
        
        pass
        
    def get_GnssTimeSeconds(self) -> int:
        """
        A getter for the 'GnssSensorCmd::GnssTimeSeconds' structure field
        
        GNSS Unix time integer seconds
        """
        
        pass
    
    def get_GnssTimeNs(self) -> int:
        """
        A getter for the 'GnssSensorCmd::GnssTimeNs' structure field
        
        GNSS Unix time fraction nanoseconds
        """
        
        pass
    
    def get_GnssSatPosX(self) -> int:
        """
        A getter for the 'GnssSensorCmd::GnssSatPosX' structure field
        
        Satellite position vector X component (GNSS frame)
        """
        
        pass
    
    def get_GnssSatPosY(self) -> int:
        """
        A getter for the 'GnssSensorCmd::GnssSatPosY' structure field
        
        Satellite position vector Y component (GNSS frame)
        """
        
        pass
    
    def get_GnssSatPosZ(self) -> int:
        """
        A getter for the 'GnssSensorCmd::GnssSatPosZ' structure field
        
        Satellite position vector Z component (GNSS frame)
        """
        
        pass
    
    def get_GnssSatVelX(self) -> int:
        """
        A getter for the 'GnssSensorCmd::GnssSatVelX' structure field
        
        Satellite velocity vector X component (GNSS frame)
        """
        
        pass
    
    def get_GnssSatVelY(self) -> int:
        """
        A getter for the 'GnssSensorCmd::GnssSatVelY' structure field
        
        Satellite velocity vector Y component (GNSS frame)
        """
        
        pass
    
    def get_GnssSatVelZ(self) -> int:
        """
        A getter for the 'GnssSensorCmd::GnssSatVelZ' structure field
        
        Satellite velocity vector Z component (GNSS frame)
        """
        
        pass
    
    def get_SyncTime(self) -> int:
        """
        A getter for the 'GnssSensorCmd::SyncTime' structure field
        
        Flag to indicate if RTC should sync with unix time
        """
        
        pass

def GnssSensorCmd_make_from_buf(buf : bytes) -> GnssSensorCmd:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmSensorCalStr:
    """
    A Python class to represent struct objects of type 'TlmSensorCalStr'
    
    Parameter structure for interface TlmSensorCalStr
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, double__Str0MeasBodyVec0X : float, double__Str0MeasBodyVec0Y : float, double__Str0MeasBodyVec0Z : float, double__Str0MeasBodyVec1X : float, double__Str0MeasBodyVec1Y : float, double__Str0MeasBodyVec1Z : float, double__Str0MeasBodyVec2X : float, double__Str0MeasBodyVec2Y : float, double__Str0MeasBodyVec2Z : float, double__Str0ModelOrbitVec0X : float, double__Str0ModelOrbitVec0Y : float, double__Str0ModelOrbitVec0Z : float, double__Str0ModelOrbitVec1X : float, double__Str0ModelOrbitVec1Y : float, double__Str0ModelOrbitVec1Z : float, double__Str0ModelOrbitVec2X : float, double__Str0ModelOrbitVec2Y : float, double__Str0ModelOrbitVec2Z : float, double__Str1MeasBodyVec0X : float, double__Str1MeasBodyVec0Y : float, double__Str1MeasBodyVec0Z : float, double__Str1MeasBodyVec1X : float, double__Str1MeasBodyVec1Y : float, double__Str1MeasBodyVec1Z : float, double__Str1MeasBodyVec2X : float, double__Str1MeasBodyVec2Y : float, double__Str1MeasBodyVec2Z : float, double__Str1ModelOrbitVec0X : float, double__Str1ModelOrbitVec0Y : float, double__Str1ModelOrbitVec0Z : float, double__Str1ModelOrbitVec1X : float, double__Str1ModelOrbitVec1Y : float, double__Str1ModelOrbitVec1Z : float, double__Str1ModelOrbitVec2X : float, double__Str1ModelOrbitVec2Y : float, double__Str1ModelOrbitVec2Z : float, bool__Str0IsValid : int, bool__Str1IsValid : int) -> None:
        """
        Struct 'TlmSensorCalStr' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        double__Str0MeasBodyVec0X [1] : float
            STR0 measured body vector 0 X component
        double__Str0MeasBodyVec0Y [1] : float
            STR0 measured body vector 0 Y component
        double__Str0MeasBodyVec0Z [1] : float
            STR0 measured body vector 0 Z component
        double__Str0MeasBodyVec1X [1] : float
            STR0 measured body vector 1 X component
        double__Str0MeasBodyVec1Y [1] : float
            STR0 measured body vector 1 Y component
        double__Str0MeasBodyVec1Z [1] : float
            STR0 measured body vector 1 Z component
        double__Str0MeasBodyVec2X [1] : float
            STR0 measured body vector 2 X component
        double__Str0MeasBodyVec2Y [1] : float
            STR0 measured body vector 2 Y component
        double__Str0MeasBodyVec2Z [1] : float
            STR0 measured body vector 2 Z component
        double__Str0ModelOrbitVec0X [1] : float
            STR0 modelled ORC vector 0 X component
        double__Str0ModelOrbitVec0Y [1] : float
            STR0 modelled ORC vector 0 Y component
        double__Str0ModelOrbitVec0Z [1] : float
            STR0 modelled ORC vector 0 Z component
        double__Str0ModelOrbitVec1X [1] : float
            STR0 modelled ORC vector 1 X component
        double__Str0ModelOrbitVec1Y [1] : float
            STR0 modelled ORC vector 1 Y component
        double__Str0ModelOrbitVec1Z [1] : float
            STR0 modelled ORC vector 1 Z component
        double__Str0ModelOrbitVec2X [1] : float
            STR0 modelled ORC vector 2 X component
        double__Str0ModelOrbitVec2Y [1] : float
            STR0 modelled ORC vector 2 Y component
        double__Str0ModelOrbitVec2Z [1] : float
            STR0 modelled ORC vector 2 Z component
        double__Str1MeasBodyVec0X [1] : float
            STR1 measured body vector 0 X component
        double__Str1MeasBodyVec0Y [1] : float
            STR1 measured body vector 0 Y component
        double__Str1MeasBodyVec0Z [1] : float
            STR1 measured body vector 0 Z component
        double__Str1MeasBodyVec1X [1] : float
            STR1 measured body vector 1 X component
        double__Str1MeasBodyVec1Y [1] : float
            STR1 measured body vector 1 Y component
        double__Str1MeasBodyVec1Z [1] : float
            STR1 measured body vector 1 Z component
        double__Str1MeasBodyVec2X [1] : float
            STR1 measured body vector 2 X component
        double__Str1MeasBodyVec2Y [1] : float
            STR1 measured body vector 2 Y component
        double__Str1MeasBodyVec2Z [1] : float
            STR1 measured body vector 2 Z component
        double__Str1ModelOrbitVec0X [1] : float
            STR1 modelled ORC vector 0 X component
        double__Str1ModelOrbitVec0Y [1] : float
            STR1 modelled ORC vector 0 Y component
        double__Str1ModelOrbitVec0Z [1] : float
            STR1 modelled ORC vector 0 Z component
        double__Str1ModelOrbitVec1X [1] : float
            STR1 modelled ORC vector 1 X component
        double__Str1ModelOrbitVec1Y [1] : float
            STR1 modelled ORC vector 1 Y component
        double__Str1ModelOrbitVec1Z [1] : float
            STR1 modelled ORC vector 1 Z component
        double__Str1ModelOrbitVec2X [1] : float
            STR1 modelled ORC vector 2 X component
        double__Str1ModelOrbitVec2Y [1] : float
            STR1 modelled ORC vector 2 Y component
        double__Str1ModelOrbitVec2Z [1] : float
            STR1 modelled ORC vector 2 Z component
        bool__Str0IsValid [1] : int
            STR0 valid flag
        bool__Str1IsValid [1] : int
            STR1 valid flag
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmSensorCalStr::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmSensorCalStr::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_Str0MeasBodyVec0X(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str0MeasBodyVec0X' structure field
        
        STR0 measured body vector 0 X component
        """
        
        pass
    
    def get_Str0MeasBodyVec0Y(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str0MeasBodyVec0Y' structure field
        
        STR0 measured body vector 0 Y component
        """
        
        pass
    
    def get_Str0MeasBodyVec0Z(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str0MeasBodyVec0Z' structure field
        
        STR0 measured body vector 0 Z component
        """
        
        pass
    
    def get_Str0MeasBodyVec1X(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str0MeasBodyVec1X' structure field
        
        STR0 measured body vector 1 X component
        """
        
        pass
    
    def get_Str0MeasBodyVec1Y(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str0MeasBodyVec1Y' structure field
        
        STR0 measured body vector 1 Y component
        """
        
        pass
    
    def get_Str0MeasBodyVec1Z(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str0MeasBodyVec1Z' structure field
        
        STR0 measured body vector 1 Z component
        """
        
        pass
    
    def get_Str0MeasBodyVec2X(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str0MeasBodyVec2X' structure field
        
        STR0 measured body vector 2 X component
        """
        
        pass
    
    def get_Str0MeasBodyVec2Y(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str0MeasBodyVec2Y' structure field
        
        STR0 measured body vector 2 Y component
        """
        
        pass
    
    def get_Str0MeasBodyVec2Z(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str0MeasBodyVec2Z' structure field
        
        STR0 measured body vector 2 Z component
        """
        
        pass
    
    def get_Str0ModelOrbitVec0X(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str0ModelOrbitVec0X' structure field
        
        STR0 modelled ORC vector 0 X component
        """
        
        pass
    
    def get_Str0ModelOrbitVec0Y(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str0ModelOrbitVec0Y' structure field
        
        STR0 modelled ORC vector 0 Y component
        """
        
        pass
    
    def get_Str0ModelOrbitVec0Z(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str0ModelOrbitVec0Z' structure field
        
        STR0 modelled ORC vector 0 Z component
        """
        
        pass
    
    def get_Str0ModelOrbitVec1X(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str0ModelOrbitVec1X' structure field
        
        STR0 modelled ORC vector 1 X component
        """
        
        pass
    
    def get_Str0ModelOrbitVec1Y(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str0ModelOrbitVec1Y' structure field
        
        STR0 modelled ORC vector 1 Y component
        """
        
        pass
    
    def get_Str0ModelOrbitVec1Z(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str0ModelOrbitVec1Z' structure field
        
        STR0 modelled ORC vector 1 Z component
        """
        
        pass
    
    def get_Str0ModelOrbitVec2X(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str0ModelOrbitVec2X' structure field
        
        STR0 modelled ORC vector 2 X component
        """
        
        pass
    
    def get_Str0ModelOrbitVec2Y(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str0ModelOrbitVec2Y' structure field
        
        STR0 modelled ORC vector 2 Y component
        """
        
        pass
    
    def get_Str0ModelOrbitVec2Z(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str0ModelOrbitVec2Z' structure field
        
        STR0 modelled ORC vector 2 Z component
        """
        
        pass
    
    def get_Str1MeasBodyVec0X(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str1MeasBodyVec0X' structure field
        
        STR1 measured body vector 0 X component
        """
        
        pass
    
    def get_Str1MeasBodyVec0Y(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str1MeasBodyVec0Y' structure field
        
        STR1 measured body vector 0 Y component
        """
        
        pass
    
    def get_Str1MeasBodyVec0Z(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str1MeasBodyVec0Z' structure field
        
        STR1 measured body vector 0 Z component
        """
        
        pass
    
    def get_Str1MeasBodyVec1X(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str1MeasBodyVec1X' structure field
        
        STR1 measured body vector 1 X component
        """
        
        pass
    
    def get_Str1MeasBodyVec1Y(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str1MeasBodyVec1Y' structure field
        
        STR1 measured body vector 1 Y component
        """
        
        pass
    
    def get_Str1MeasBodyVec1Z(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str1MeasBodyVec1Z' structure field
        
        STR1 measured body vector 1 Z component
        """
        
        pass
    
    def get_Str1MeasBodyVec2X(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str1MeasBodyVec2X' structure field
        
        STR1 measured body vector 2 X component
        """
        
        pass
    
    def get_Str1MeasBodyVec2Y(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str1MeasBodyVec2Y' structure field
        
        STR1 measured body vector 2 Y component
        """
        
        pass
    
    def get_Str1MeasBodyVec2Z(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str1MeasBodyVec2Z' structure field
        
        STR1 measured body vector 2 Z component
        """
        
        pass
    
    def get_Str1ModelOrbitVec0X(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str1ModelOrbitVec0X' structure field
        
        STR1 modelled ORC vector 0 X component
        """
        
        pass
    
    def get_Str1ModelOrbitVec0Y(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str1ModelOrbitVec0Y' structure field
        
        STR1 modelled ORC vector 0 Y component
        """
        
        pass
    
    def get_Str1ModelOrbitVec0Z(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str1ModelOrbitVec0Z' structure field
        
        STR1 modelled ORC vector 0 Z component
        """
        
        pass
    
    def get_Str1ModelOrbitVec1X(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str1ModelOrbitVec1X' structure field
        
        STR1 modelled ORC vector 1 X component
        """
        
        pass
    
    def get_Str1ModelOrbitVec1Y(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str1ModelOrbitVec1Y' structure field
        
        STR1 modelled ORC vector 1 Y component
        """
        
        pass
    
    def get_Str1ModelOrbitVec1Z(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str1ModelOrbitVec1Z' structure field
        
        STR1 modelled ORC vector 1 Z component
        """
        
        pass
    
    def get_Str1ModelOrbitVec2X(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str1ModelOrbitVec2X' structure field
        
        STR1 modelled ORC vector 2 X component
        """
        
        pass
    
    def get_Str1ModelOrbitVec2Y(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str1ModelOrbitVec2Y' structure field
        
        STR1 modelled ORC vector 2 Y component
        """
        
        pass
    
    def get_Str1ModelOrbitVec2Z(self) -> float:
        """
        A getter for the 'TlmSensorCalStr::Str1ModelOrbitVec2Z' structure field
        
        STR1 modelled ORC vector 2 Z component
        """
        
        pass
    
    def get_Str0IsValid(self) -> int:
        """
        A getter for the 'TlmSensorCalStr::Str0IsValid' structure field
        
        STR0 valid flag
        """
        
        pass
    
    def get_Str1IsValid(self) -> int:
        """
        A getter for the 'TlmSensorCalStr::Str1IsValid' structure field
        
        STR1 valid flag
        """
        
        pass

def TlmSensorCalStr_make_from_buf(buf : bytes) -> TlmSensorCalStr:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class OpenLoopCommandHxyzRW:
    """
    A Python class to represent struct objects of type 'OpenLoopCommandHxyzRW'
    
    Parameter structure for interface OpenLoopCommandHxyzRW
    """

    def __init__(self, float__Hx : float, float__Hy : float, float__Hz : float) -> None:
        """
        Struct 'OpenLoopCommandHxyzRW' constructor
        
        Attributes
        ---------
        float__Hx [1] : float
            X-momentum open-loop speed command
        float__Hy [1] : float
            Y-momentum open-loop speed command
        float__Hz [1] : float
            Z-momentum open-loop speed command
        """
        
        pass
        
    def get_Hx(self) -> float:
        """
        A getter for the 'OpenLoopCommandHxyzRW::Hx' structure field
        
        X-momentum open-loop speed command
        """
        
        pass
    
    def get_Hy(self) -> float:
        """
        A getter for the 'OpenLoopCommandHxyzRW::Hy' structure field
        
        Y-momentum open-loop speed command
        """
        
        pass
    
    def get_Hz(self) -> float:
        """
        A getter for the 'OpenLoopCommandHxyzRW::Hz' structure field
        
        Z-momentum open-loop speed command
        """
        
        pass

def OpenLoopCommandHxyzRW_make_from_buf(buf : bytes) -> OpenLoopCommandHxyzRW:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmEstimatorMainHighRes:
    """
    A Python class to represent struct objects of type 'TlmEstimatorMainHighRes'
    
    Parameter structure for interface TlmEstimatorMainHighRes
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, float__EstQuatQ0 : float, float__EstQuatQ1 : float, float__EstQuatQ2 : float, float__EstQuatQ3 : float, float__EstRateOrcX : float, float__EstRateOrcY : float, float__EstRateOrcZ : float) -> None:
        """
        Struct 'TlmEstimatorMainHighRes' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        float__EstQuatQ0 [1] : float
            Estimated ORC quaternion Q0
        float__EstQuatQ1 [1] : float
            Estimated ORC quaternion Q1
        float__EstQuatQ2 [1] : float
            Estimated ORC quaternion Q2
        float__EstQuatQ3 [1] : float
            Estimated ORC quaternion Q3
        float__EstRateOrcX [1] : float
            Estimated body rate (ORC) X component
        float__EstRateOrcY [1] : float
            Estimated body rate (ORC) Y component
        float__EstRateOrcZ [1] : float
            Estimated body rate (ORC) Z component
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmEstimatorMainHighRes::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmEstimatorMainHighRes::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_EstQuatQ0(self) -> float:
        """
        A getter for the 'TlmEstimatorMainHighRes::EstQuatQ0' structure field
        
        Estimated ORC quaternion Q0
        """
        
        pass
    
    def get_EstQuatQ1(self) -> float:
        """
        A getter for the 'TlmEstimatorMainHighRes::EstQuatQ1' structure field
        
        Estimated ORC quaternion Q1
        """
        
        pass
    
    def get_EstQuatQ2(self) -> float:
        """
        A getter for the 'TlmEstimatorMainHighRes::EstQuatQ2' structure field
        
        Estimated ORC quaternion Q2
        """
        
        pass
    
    def get_EstQuatQ3(self) -> float:
        """
        A getter for the 'TlmEstimatorMainHighRes::EstQuatQ3' structure field
        
        Estimated ORC quaternion Q3
        """
        
        pass
    
    def get_EstRateOrcX(self) -> float:
        """
        A getter for the 'TlmEstimatorMainHighRes::EstRateOrcX' structure field
        
        Estimated body rate (ORC) X component
        """
        
        pass
    
    def get_EstRateOrcY(self) -> float:
        """
        A getter for the 'TlmEstimatorMainHighRes::EstRateOrcY' structure field
        
        Estimated body rate (ORC) Y component
        """
        
        pass
    
    def get_EstRateOrcZ(self) -> float:
        """
        A getter for the 'TlmEstimatorMainHighRes::EstRateOrcZ' structure field
        
        Estimated body rate (ORC) Z component
        """
        
        pass

def TlmEstimatorMainHighRes_make_from_buf(buf : bytes) -> TlmEstimatorMainHighRes:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmAsgp4:
    """
    A Python class to represent struct objects of type 'TlmAsgp4'
    
    Parameter structure for interface TlmAsgp4
    """

    def __init__(self, double__Asgp4Epoch : float, double__Asgp4Incl : float, double__Asgp4Raan : float, double__Asgp4Eccen : float, double__Asgp4AP : float, double__Asgp4MA : float, double__Asgp4MM : float, double__Asgp4Bstar : float) -> None:
        """
        Struct 'TlmAsgp4' constructor
        
        Attributes
        ---------
        double__Asgp4Epoch [1] : float
            ASGP4 epoch
        double__Asgp4Incl [1] : float
            ASGP4 inclination
        double__Asgp4Raan [1] : float
            ASGP4 RAAN
        double__Asgp4Eccen [1] : float
            ASGP4 eccentricity
        double__Asgp4AP [1] : float
            ASGP4 argument of perigee
        double__Asgp4MA [1] : float
            ASGP4 mean anomaly
        double__Asgp4MM [1] : float
            ASGP4 mean motion
        double__Asgp4Bstar [1] : float
            ASGP4 B-star drag term
        """
        
        pass
        
    def get_Asgp4Epoch(self) -> float:
        """
        A getter for the 'TlmAsgp4::Asgp4Epoch' structure field
        
        ASGP4 epoch
        """
        
        pass
    
    def get_Asgp4Incl(self) -> float:
        """
        A getter for the 'TlmAsgp4::Asgp4Incl' structure field
        
        ASGP4 inclination
        """
        
        pass
    
    def get_Asgp4Raan(self) -> float:
        """
        A getter for the 'TlmAsgp4::Asgp4Raan' structure field
        
        ASGP4 RAAN
        """
        
        pass
    
    def get_Asgp4Eccen(self) -> float:
        """
        A getter for the 'TlmAsgp4::Asgp4Eccen' structure field
        
        ASGP4 eccentricity
        """
        
        pass
    
    def get_Asgp4AP(self) -> float:
        """
        A getter for the 'TlmAsgp4::Asgp4AP' structure field
        
        ASGP4 argument of perigee
        """
        
        pass
    
    def get_Asgp4MA(self) -> float:
        """
        A getter for the 'TlmAsgp4::Asgp4MA' structure field
        
        ASGP4 mean anomaly
        """
        
        pass
    
    def get_Asgp4MM(self) -> float:
        """
        A getter for the 'TlmAsgp4::Asgp4MM' structure field
        
        ASGP4 mean motion
        """
        
        pass
    
    def get_Asgp4Bstar(self) -> float:
        """
        A getter for the 'TlmAsgp4::Asgp4Bstar' structure field
        
        ASGP4 B-star drag term
        """
        
        pass

def TlmAsgp4_make_from_buf(buf : bytes) -> TlmAsgp4:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ConfigNodeSelection:
    """
    A Python class to represent struct objects of type 'ConfigNodeSelection'
    
    Parameter structure for interface ConfigNodeSelection
    """

    def __init__(self, uint8__SelectRwl : int, uint8__SelectMag : int, uint8__SelectFss : int, uint8__SelectHss : int, uint8__SelectGyro : int, uint8__SelectStr : int, uint8__SelectGnss : int, uint8__SelectExt : int) -> None:
        """
        Struct 'ConfigNodeSelection' constructor
        
        Attributes
        ---------
        uint8__SelectRwl [1] : int
            RWL selection flags
        uint8__SelectMag [1] : int
            MAG selection flags
        uint8__SelectFss [1] : int
            FSS selection flags
        uint8__SelectHss [1] : int
            HSS selection flags
        uint8__SelectGyro [1] : int
            GYR selection flags
        uint8__SelectStr [1] : int
            STR selection flags
        uint8__SelectGnss [1] : int
            GNSS selection flags
        uint8__SelectExt [1] : int
            External sensor selection flags
        """
        
        pass
        
    def get_SelectRwl(self) -> int:
        """
        A getter for the 'ConfigNodeSelection::SelectRwl' structure field
        
        RWL selection flags
        """
        
        pass
    
    def get_SelectMag(self) -> int:
        """
        A getter for the 'ConfigNodeSelection::SelectMag' structure field
        
        MAG selection flags
        """
        
        pass
    
    def get_SelectFss(self) -> int:
        """
        A getter for the 'ConfigNodeSelection::SelectFss' structure field
        
        FSS selection flags
        """
        
        pass
    
    def get_SelectHss(self) -> int:
        """
        A getter for the 'ConfigNodeSelection::SelectHss' structure field
        
        HSS selection flags
        """
        
        pass
    
    def get_SelectGyro(self) -> int:
        """
        A getter for the 'ConfigNodeSelection::SelectGyro' structure field
        
        GYR selection flags
        """
        
        pass
    
    def get_SelectStr(self) -> int:
        """
        A getter for the 'ConfigNodeSelection::SelectStr' structure field
        
        STR selection flags
        """
        
        pass
    
    def get_SelectGnss(self) -> int:
        """
        A getter for the 'ConfigNodeSelection::SelectGnss' structure field
        
        GNSS selection flags
        """
        
        pass
    
    def get_SelectExt(self) -> int:
        """
        A getter for the 'ConfigNodeSelection::SelectExt' structure field
        
        External sensor selection flags
        """
        
        pass

def ConfigNodeSelection_make_from_buf(buf : bytes) -> ConfigNodeSelection:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmCubeComputerHealth:
    """
    A Python class to represent struct objects of type 'TlmCubeComputerHealth'
    
    Parameter structure for interface TlmCubeComputerHealth
    """

    def __init__(self, double__McuTemp : float, double__McuCurrent : float, uint16__McuVoltage : int, uint16__SupplyVoltage : int, uint16__v5Sense : int, uint16__BatteryVoltage : int, uint16__VersionVoltage : int, double__Sram1Current : float, double__Sram2Current : float, double__FpgaCurrent1v5 : float, double__FramCurrent : float, double__AdcCurrent : float, double__FlashCurrent : float, double__Rs485Current : float, double__CanCurrent : float, double__GyroCurrent : float, double__RedGyroCurrent : float, bool__GyroOverVoltage : int, bool__GyroUnderVoltage : int, bool__RedGyroOverVoltage : int, bool__RedGyroUnderVoltage : int, a__uint8__5__WatchdogCount : list[int]) -> None:
        """
        Struct 'TlmCubeComputerHealth' constructor
        
        Attributes
        ---------
        double__McuTemp [1] : float
            MCU Temperature
        double__McuCurrent [1] : float
            MCU current
        uint16__McuVoltage [1] : int
            MCU internal reference voltage
        uint16__SupplyVoltage [1] : int
            MCU supply voltage
        uint16__v5Sense [1] : int
            5V supply voltage
        uint16__BatteryVoltage [1] : int
            Battery voltage
        uint16__VersionVoltage [1] : int
            Hardware Version voltage
        double__Sram1Current [1] : float
            SRAM1 current
        double__Sram2Current [1] : float
            SRAM2 current
        double__FpgaCurrent1v5 [1] : float
            FPGA current on 1v5 rail
        double__FramCurrent [1] : float
            FRAM current
        double__AdcCurrent [1] : float
            ADC current
        double__FlashCurrent [1] : float
            Flash memory current
        double__Rs485Current [1] : float
            RS485 driver current
        double__CanCurrent [1] : float
            CAN driver current
        double__GyroCurrent [1] : float
            Gyro current
        double__RedGyroCurrent [1] : float
            Redundant gyro current
        bool__GyroOverVoltage [1] : int
            Set if the primary gyro supply voltage has exceeded the maximum limit
        bool__GyroUnderVoltage [1] : int
            Set if the primary gyro supply voltage has exceeded the minimum limit
        bool__RedGyroOverVoltage [1] : int
            Set if the redundant gyro supply voltage has exceeded the maximum limit
        bool__RedGyroUnderVoltage [1] : int
            Set if the redundant gyro supply voltage has exceeded the minimum limit
        a__uint8__5__WatchdogCount [5] : list[int]
            Bitmask representing virtual watchdog region warning counters.
        """
        
        pass
        
    def get_McuTemp(self) -> float:
        """
        A getter for the 'TlmCubeComputerHealth::McuTemp' structure field
        
        MCU Temperature
        """
        
        pass
    
    def get_McuCurrent(self) -> float:
        """
        A getter for the 'TlmCubeComputerHealth::McuCurrent' structure field
        
        MCU current
        """
        
        pass
    
    def get_McuVoltage(self) -> int:
        """
        A getter for the 'TlmCubeComputerHealth::McuVoltage' structure field
        
        MCU internal reference voltage
        """
        
        pass
    
    def get_SupplyVoltage(self) -> int:
        """
        A getter for the 'TlmCubeComputerHealth::SupplyVoltage' structure field
        
        MCU supply voltage
        """
        
        pass
    
    def get_v5Sense(self) -> int:
        """
        A getter for the 'TlmCubeComputerHealth::v5Sense' structure field
        
        5V supply voltage
        """
        
        pass
    
    def get_BatteryVoltage(self) -> int:
        """
        A getter for the 'TlmCubeComputerHealth::BatteryVoltage' structure field
        
        Battery voltage
        """
        
        pass
    
    def get_VersionVoltage(self) -> int:
        """
        A getter for the 'TlmCubeComputerHealth::VersionVoltage' structure field
        
        Hardware Version voltage
        """
        
        pass
    
    def get_Sram1Current(self) -> float:
        """
        A getter for the 'TlmCubeComputerHealth::Sram1Current' structure field
        
        SRAM1 current
        """
        
        pass
    
    def get_Sram2Current(self) -> float:
        """
        A getter for the 'TlmCubeComputerHealth::Sram2Current' structure field
        
        SRAM2 current
        """
        
        pass
    
    def get_FpgaCurrent1v5(self) -> float:
        """
        A getter for the 'TlmCubeComputerHealth::FpgaCurrent1v5' structure field
        
        FPGA current on 1v5 rail
        """
        
        pass
    
    def get_FramCurrent(self) -> float:
        """
        A getter for the 'TlmCubeComputerHealth::FramCurrent' structure field
        
        FRAM current
        """
        
        pass
    
    def get_AdcCurrent(self) -> float:
        """
        A getter for the 'TlmCubeComputerHealth::AdcCurrent' structure field
        
        ADC current
        """
        
        pass
    
    def get_FlashCurrent(self) -> float:
        """
        A getter for the 'TlmCubeComputerHealth::FlashCurrent' structure field
        
        Flash memory current
        """
        
        pass
    
    def get_Rs485Current(self) -> float:
        """
        A getter for the 'TlmCubeComputerHealth::Rs485Current' structure field
        
        RS485 driver current
        """
        
        pass
    
    def get_CanCurrent(self) -> float:
        """
        A getter for the 'TlmCubeComputerHealth::CanCurrent' structure field
        
        CAN driver current
        """
        
        pass
    
    def get_GyroCurrent(self) -> float:
        """
        A getter for the 'TlmCubeComputerHealth::GyroCurrent' structure field
        
        Gyro current
        """
        
        pass
    
    def get_RedGyroCurrent(self) -> float:
        """
        A getter for the 'TlmCubeComputerHealth::RedGyroCurrent' structure field
        
        Redundant gyro current
        """
        
        pass
    
    def get_GyroOverVoltage(self) -> int:
        """
        A getter for the 'TlmCubeComputerHealth::GyroOverVoltage' structure field
        
        Set if the primary gyro supply voltage has exceeded the maximum limit
        """
        
        pass
    
    def get_GyroUnderVoltage(self) -> int:
        """
        A getter for the 'TlmCubeComputerHealth::GyroUnderVoltage' structure field
        
        Set if the primary gyro supply voltage has exceeded the minimum limit
        """
        
        pass
    
    def get_RedGyroOverVoltage(self) -> int:
        """
        A getter for the 'TlmCubeComputerHealth::RedGyroOverVoltage' structure field
        
        Set if the redundant gyro supply voltage has exceeded the maximum limit
        """
        
        pass
    
    def get_RedGyroUnderVoltage(self) -> int:
        """
        A getter for the 'TlmCubeComputerHealth::RedGyroUnderVoltage' structure field
        
        Set if the redundant gyro supply voltage has exceeded the minimum limit
        """
        
        pass
    
    def get_WatchdogCount(self) -> list[int]:
        """
        A getter for the 'TlmCubeComputerHealth::WatchdogCount' structure field
        
        Bitmask representing virtual watchdog region warning counters.
        """
        
        pass

def TlmCubeComputerHealth_make_from_buf(buf : bytes) -> TlmCubeComputerHealth:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmRwlHealth:
    """
    A Python class to represent struct objects of type 'TlmRwlHealth'
    
    Parameter structure for interface TlmRwlHealth
    """

    def __init__(self, double__Rwl0McuTemp : float, double__Rwl0McuCurrent : float, uint16__Rwl0BatVoltage : int, double__Rwl0BatCurrent : float, double__Rwl1McuTemp : float, double__Rwl1McuCurrent : float, uint16__Rwl1BatVoltage : int, double__Rwl1BatCurrent : float, double__Rwl2McuTemp : float, double__Rwl2McuCurrent : float, uint16__Rwl2BatVoltage : int, double__Rwl2BatCurrent : float, double__Rwl3McuTemp : float, double__Rwl3McuCurrent : float, uint16__Rwl3BatVoltage : int, double__Rwl3BatCurrent : float) -> None:
        """
        Struct 'TlmRwlHealth' constructor
        
        Attributes
        ---------
        double__Rwl0McuTemp [1] : float
            RWL0 MCU Temperature
        double__Rwl0McuCurrent [1] : float
            RWL0 MCU current
        uint16__Rwl0BatVoltage [1] : int
            RWL0 Battery supply voltage
        double__Rwl0BatCurrent [1] : float
            RWL0 Battery current
        double__Rwl1McuTemp [1] : float
            RWL1 MCU Temperature
        double__Rwl1McuCurrent [1] : float
            RWL1 MCU current
        uint16__Rwl1BatVoltage [1] : int
            RWL1 Battery supply voltage
        double__Rwl1BatCurrent [1] : float
            RWL1 Battery current
        double__Rwl2McuTemp [1] : float
            RWL2 MCU Temperature
        double__Rwl2McuCurrent [1] : float
            RWL2 MCU current
        uint16__Rwl2BatVoltage [1] : int
            RWL2 Battery supply voltage
        double__Rwl2BatCurrent [1] : float
            RWL2 Battery current
        double__Rwl3McuTemp [1] : float
            RWL3 MCU Temperature
        double__Rwl3McuCurrent [1] : float
            RWL3 MCU current
        uint16__Rwl3BatVoltage [1] : int
            RWL3 Battery supply voltage
        double__Rwl3BatCurrent [1] : float
            RWL3 Battery current
        """
        
        pass
        
    def get_Rwl0McuTemp(self) -> float:
        """
        A getter for the 'TlmRwlHealth::Rwl0McuTemp' structure field
        
        RWL0 MCU Temperature
        """
        
        pass
    
    def get_Rwl0McuCurrent(self) -> float:
        """
        A getter for the 'TlmRwlHealth::Rwl0McuCurrent' structure field
        
        RWL0 MCU current
        """
        
        pass
    
    def get_Rwl0BatVoltage(self) -> int:
        """
        A getter for the 'TlmRwlHealth::Rwl0BatVoltage' structure field
        
        RWL0 Battery supply voltage
        """
        
        pass
    
    def get_Rwl0BatCurrent(self) -> float:
        """
        A getter for the 'TlmRwlHealth::Rwl0BatCurrent' structure field
        
        RWL0 Battery current
        """
        
        pass
    
    def get_Rwl1McuTemp(self) -> float:
        """
        A getter for the 'TlmRwlHealth::Rwl1McuTemp' structure field
        
        RWL1 MCU Temperature
        """
        
        pass
    
    def get_Rwl1McuCurrent(self) -> float:
        """
        A getter for the 'TlmRwlHealth::Rwl1McuCurrent' structure field
        
        RWL1 MCU current
        """
        
        pass
    
    def get_Rwl1BatVoltage(self) -> int:
        """
        A getter for the 'TlmRwlHealth::Rwl1BatVoltage' structure field
        
        RWL1 Battery supply voltage
        """
        
        pass
    
    def get_Rwl1BatCurrent(self) -> float:
        """
        A getter for the 'TlmRwlHealth::Rwl1BatCurrent' structure field
        
        RWL1 Battery current
        """
        
        pass
    
    def get_Rwl2McuTemp(self) -> float:
        """
        A getter for the 'TlmRwlHealth::Rwl2McuTemp' structure field
        
        RWL2 MCU Temperature
        """
        
        pass
    
    def get_Rwl2McuCurrent(self) -> float:
        """
        A getter for the 'TlmRwlHealth::Rwl2McuCurrent' structure field
        
        RWL2 MCU current
        """
        
        pass
    
    def get_Rwl2BatVoltage(self) -> int:
        """
        A getter for the 'TlmRwlHealth::Rwl2BatVoltage' structure field
        
        RWL2 Battery supply voltage
        """
        
        pass
    
    def get_Rwl2BatCurrent(self) -> float:
        """
        A getter for the 'TlmRwlHealth::Rwl2BatCurrent' structure field
        
        RWL2 Battery current
        """
        
        pass
    
    def get_Rwl3McuTemp(self) -> float:
        """
        A getter for the 'TlmRwlHealth::Rwl3McuTemp' structure field
        
        RWL3 MCU Temperature
        """
        
        pass
    
    def get_Rwl3McuCurrent(self) -> float:
        """
        A getter for the 'TlmRwlHealth::Rwl3McuCurrent' structure field
        
        RWL3 MCU current
        """
        
        pass
    
    def get_Rwl3BatVoltage(self) -> int:
        """
        A getter for the 'TlmRwlHealth::Rwl3BatVoltage' structure field
        
        RWL3 Battery supply voltage
        """
        
        pass
    
    def get_Rwl3BatCurrent(self) -> float:
        """
        A getter for the 'TlmRwlHealth::Rwl3BatCurrent' structure field
        
        RWL3 Battery current
        """
        
        pass

def TlmRwlHealth_make_from_buf(buf : bytes) -> TlmRwlHealth:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmSensorCalMag:
    """
    A Python class to represent struct objects of type 'TlmSensorCalMag'
    
    Parameter structure for interface TlmSensorCalMag
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, double__Mag0CalVecX : float, double__Mag0CalVecY : float, double__Mag0CalVecZ : float, double__Mag1CalVecX : float, double__Mag1CalVecY : float, double__Mag1CalVecZ : float, bool__Mag0IsValid : int, bool__Mag1IsValid : int, bool__Mag0IsBest : int, bool__Mag1IsBest : int) -> None:
        """
        Struct 'TlmSensorCalMag' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        double__Mag0CalVecX [1] : float
            MAG0 calibrated vector X component
        double__Mag0CalVecY [1] : float
            MAG0 calibrated vector Y component
        double__Mag0CalVecZ [1] : float
            MAG0 calibrated vector Z component
        double__Mag1CalVecX [1] : float
            MAG1 calibrated vector X component
        double__Mag1CalVecY [1] : float
            MAG1 calibrated vector Y component
        double__Mag1CalVecZ [1] : float
            MAG1 calibrated vector Z component
        bool__Mag0IsValid [1] : int
            MAG0 valid flag
        bool__Mag1IsValid [1] : int
            MAG1 valid flag
        bool__Mag0IsBest [1] : int
            MAG0 best for estimators flag
        bool__Mag1IsBest [1] : int
            MAG1 best for estimators flag
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmSensorCalMag::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmSensorCalMag::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_Mag0CalVecX(self) -> float:
        """
        A getter for the 'TlmSensorCalMag::Mag0CalVecX' structure field
        
        MAG0 calibrated vector X component
        """
        
        pass
    
    def get_Mag0CalVecY(self) -> float:
        """
        A getter for the 'TlmSensorCalMag::Mag0CalVecY' structure field
        
        MAG0 calibrated vector Y component
        """
        
        pass
    
    def get_Mag0CalVecZ(self) -> float:
        """
        A getter for the 'TlmSensorCalMag::Mag0CalVecZ' structure field
        
        MAG0 calibrated vector Z component
        """
        
        pass
    
    def get_Mag1CalVecX(self) -> float:
        """
        A getter for the 'TlmSensorCalMag::Mag1CalVecX' structure field
        
        MAG1 calibrated vector X component
        """
        
        pass
    
    def get_Mag1CalVecY(self) -> float:
        """
        A getter for the 'TlmSensorCalMag::Mag1CalVecY' structure field
        
        MAG1 calibrated vector Y component
        """
        
        pass
    
    def get_Mag1CalVecZ(self) -> float:
        """
        A getter for the 'TlmSensorCalMag::Mag1CalVecZ' structure field
        
        MAG1 calibrated vector Z component
        """
        
        pass
    
    def get_Mag0IsValid(self) -> int:
        """
        A getter for the 'TlmSensorCalMag::Mag0IsValid' structure field
        
        MAG0 valid flag
        """
        
        pass
    
    def get_Mag1IsValid(self) -> int:
        """
        A getter for the 'TlmSensorCalMag::Mag1IsValid' structure field
        
        MAG1 valid flag
        """
        
        pass
    
    def get_Mag0IsBest(self) -> int:
        """
        A getter for the 'TlmSensorCalMag::Mag0IsBest' structure field
        
        MAG0 best for estimators flag
        """
        
        pass
    
    def get_Mag1IsBest(self) -> int:
        """
        A getter for the 'TlmSensorCalMag::Mag1IsBest' structure field
        
        MAG1 best for estimators flag
        """
        
        pass

def TlmSensorCalMag_make_from_buf(buf : bytes) -> TlmSensorCalMag:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmSensorCalGnss:
    """
    A Python class to represent struct objects of type 'TlmSensorCalGnss'
    
    Parameter structure for interface TlmSensorCalGnss
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, float__GnssSatPosEcefX : float, float__GnssSatPosEcefY : float, float__GnssSatPosEcefZ : float, float__GnssSatVelEcefX : float, float__GnssSatVelEcefY : float, float__GnssSatVelEcefZ : float, uint32__GnssTimeSeconds : int, uint32__GnssTimeNs : int, bool__GnssIsValid : int) -> None:
        """
        Struct 'TlmSensorCalGnss' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        float__GnssSatPosEcefX [1] : float
            Satellite ECEF position vector X component
        float__GnssSatPosEcefY [1] : float
            Satellite ECEF position vector Y component
        float__GnssSatPosEcefZ [1] : float
            Satellite ECEF position vector Z component
        float__GnssSatVelEcefX [1] : float
            Satellite ECEF velocity vector X component
        float__GnssSatVelEcefY [1] : float
            Satellite ECEF velocity vector Y component
        float__GnssSatVelEcefZ [1] : float
            Satellite ECEF velocity vector Z component
        uint32__GnssTimeSeconds [1] : int
            GNSS-supplied unix time integer seconds
        uint32__GnssTimeNs [1] : int
            GNSS-supplied unix time nanoseconds
        bool__GnssIsValid [1] : int
            GNSS valid flag
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmSensorCalGnss::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmSensorCalGnss::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_GnssSatPosEcefX(self) -> float:
        """
        A getter for the 'TlmSensorCalGnss::GnssSatPosEcefX' structure field
        
        Satellite ECEF position vector X component
        """
        
        pass
    
    def get_GnssSatPosEcefY(self) -> float:
        """
        A getter for the 'TlmSensorCalGnss::GnssSatPosEcefY' structure field
        
        Satellite ECEF position vector Y component
        """
        
        pass
    
    def get_GnssSatPosEcefZ(self) -> float:
        """
        A getter for the 'TlmSensorCalGnss::GnssSatPosEcefZ' structure field
        
        Satellite ECEF position vector Z component
        """
        
        pass
    
    def get_GnssSatVelEcefX(self) -> float:
        """
        A getter for the 'TlmSensorCalGnss::GnssSatVelEcefX' structure field
        
        Satellite ECEF velocity vector X component
        """
        
        pass
    
    def get_GnssSatVelEcefY(self) -> float:
        """
        A getter for the 'TlmSensorCalGnss::GnssSatVelEcefY' structure field
        
        Satellite ECEF velocity vector Y component
        """
        
        pass
    
    def get_GnssSatVelEcefZ(self) -> float:
        """
        A getter for the 'TlmSensorCalGnss::GnssSatVelEcefZ' structure field
        
        Satellite ECEF velocity vector Z component
        """
        
        pass
    
    def get_GnssTimeSeconds(self) -> int:
        """
        A getter for the 'TlmSensorCalGnss::GnssTimeSeconds' structure field
        
        GNSS-supplied unix time integer seconds
        """
        
        pass
    
    def get_GnssTimeNs(self) -> int:
        """
        A getter for the 'TlmSensorCalGnss::GnssTimeNs' structure field
        
        GNSS-supplied unix time nanoseconds
        """
        
        pass
    
    def get_GnssIsValid(self) -> int:
        """
        A getter for the 'TlmSensorCalGnss::GnssIsValid' structure field
        
        GNSS valid flag
        """
        
        pass

def TlmSensorCalGnss_make_from_buf(buf : bytes) -> TlmSensorCalGnss:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmStrHealth:
    """
    A Python class to represent struct objects of type 'TlmStrHealth'
    
    Parameter structure for interface TlmStrHealth
    """

    def __init__(self, double__Str0McuTemp : float, double__Str0McuCurrent : float, uint16__Str0McuVoltage : int, double__Str0Current : float, double__Str0CurrentPk : float, double__Str0DetectorPcbTemp : float, bool__Str0SensorInitOk : int, bool__Str0SensorConfigOk : int, uint32__Str0ErrorCode : int, double__Str1McuTemp : float, double__Str1McuCurrent : float, uint16__Str1McuVoltage : int, double__Str1Current : float, double__Str1CurrentPk : float, double__Str1DetectorPcbTemp : float, bool__Str1SensorInitOk : int, bool__Str1SensorConfigOk : int, uint32__Str1ErrorCode : int) -> None:
        """
        Struct 'TlmStrHealth' constructor
        
        Attributes
        ---------
        double__Str0McuTemp [1] : float
            STR0 MCU Temperature
        double__Str0McuCurrent [1] : float
            STR0 MCU current
        uint16__Str0McuVoltage [1] : int
            STR0 MCU supply voltage
        double__Str0Current [1] : float
            STR0 current
        double__Str0CurrentPk [1] : float
            STR0 peak current
        double__Str0DetectorPcbTemp [1] : float
            STR0 detector PCB temperature
        bool__Str0SensorInitOk [1] : int
            STR0 sensor initialised without error
        bool__Str0SensorConfigOk [1] : int
            STR0 sensor configured without error
        uint32__Str0ErrorCode [1] : int
            STR0 Error Code
        double__Str1McuTemp [1] : float
            STR1 MCU Temperature
        double__Str1McuCurrent [1] : float
            STR1 MCU current
        uint16__Str1McuVoltage [1] : int
            STR1 MCU supply voltage
        double__Str1Current [1] : float
            STR1 current
        double__Str1CurrentPk [1] : float
            STR1 peak current
        double__Str1DetectorPcbTemp [1] : float
            STR1 detector PCB temperature
        bool__Str1SensorInitOk [1] : int
            STR1 sensor initialised without error
        bool__Str1SensorConfigOk [1] : int
            STR1 sensor configured without error
        uint32__Str1ErrorCode [1] : int
            STR1 Error Code
        """
        
        pass
        
    def get_Str0McuTemp(self) -> float:
        """
        A getter for the 'TlmStrHealth::Str0McuTemp' structure field
        
        STR0 MCU Temperature
        """
        
        pass
    
    def get_Str0McuCurrent(self) -> float:
        """
        A getter for the 'TlmStrHealth::Str0McuCurrent' structure field
        
        STR0 MCU current
        """
        
        pass
    
    def get_Str0McuVoltage(self) -> int:
        """
        A getter for the 'TlmStrHealth::Str0McuVoltage' structure field
        
        STR0 MCU supply voltage
        """
        
        pass
    
    def get_Str0Current(self) -> float:
        """
        A getter for the 'TlmStrHealth::Str0Current' structure field
        
        STR0 current
        """
        
        pass
    
    def get_Str0CurrentPk(self) -> float:
        """
        A getter for the 'TlmStrHealth::Str0CurrentPk' structure field
        
        STR0 peak current
        """
        
        pass
    
    def get_Str0DetectorPcbTemp(self) -> float:
        """
        A getter for the 'TlmStrHealth::Str0DetectorPcbTemp' structure field
        
        STR0 detector PCB temperature
        """
        
        pass
    
    def get_Str0SensorInitOk(self) -> int:
        """
        A getter for the 'TlmStrHealth::Str0SensorInitOk' structure field
        
        STR0 sensor initialised without error
        """
        
        pass
    
    def get_Str0SensorConfigOk(self) -> int:
        """
        A getter for the 'TlmStrHealth::Str0SensorConfigOk' structure field
        
        STR0 sensor configured without error
        """
        
        pass
    
    def get_Str0ErrorCode(self) -> int:
        """
        A getter for the 'TlmStrHealth::Str0ErrorCode' structure field
        
        STR0 Error Code
        """
        
        pass
    
    def get_Str1McuTemp(self) -> float:
        """
        A getter for the 'TlmStrHealth::Str1McuTemp' structure field
        
        STR1 MCU Temperature
        """
        
        pass
    
    def get_Str1McuCurrent(self) -> float:
        """
        A getter for the 'TlmStrHealth::Str1McuCurrent' structure field
        
        STR1 MCU current
        """
        
        pass
    
    def get_Str1McuVoltage(self) -> int:
        """
        A getter for the 'TlmStrHealth::Str1McuVoltage' structure field
        
        STR1 MCU supply voltage
        """
        
        pass
    
    def get_Str1Current(self) -> float:
        """
        A getter for the 'TlmStrHealth::Str1Current' structure field
        
        STR1 current
        """
        
        pass
    
    def get_Str1CurrentPk(self) -> float:
        """
        A getter for the 'TlmStrHealth::Str1CurrentPk' structure field
        
        STR1 peak current
        """
        
        pass
    
    def get_Str1DetectorPcbTemp(self) -> float:
        """
        A getter for the 'TlmStrHealth::Str1DetectorPcbTemp' structure field
        
        STR1 detector PCB temperature
        """
        
        pass
    
    def get_Str1SensorInitOk(self) -> int:
        """
        A getter for the 'TlmStrHealth::Str1SensorInitOk' structure field
        
        STR1 sensor initialised without error
        """
        
        pass
    
    def get_Str1SensorConfigOk(self) -> int:
        """
        A getter for the 'TlmStrHealth::Str1SensorConfigOk' structure field
        
        STR1 sensor configured without error
        """
        
        pass
    
    def get_Str1ErrorCode(self) -> int:
        """
        A getter for the 'TlmStrHealth::Str1ErrorCode' structure field
        
        STR1 Error Code
        """
        
        pass

def TlmStrHealth_make_from_buf(buf : bytes) -> TlmStrHealth:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ConfigAdcsSatellite:
    """
    A Python class to represent struct objects of type 'ConfigAdcsSatellite'
    
    Parameter structure for interface ConfigAdcsSatellite
    """

    def __init__(self, float__Ixx : float, float__Iyy : float, float__Izz : float, float__Ixy : float, float__Ixz : float, float__Iyz : float, double__SunPointBodyVecX : float, double__SunPointBodyVecY : float, double__SunPointBodyVecZ : float, double__TgtTrackBodyVecX : float, double__TgtTrackBodyVecY : float, double__TgtTrackBodyVecZ : float, double__SatTrackBodyVecX : float, double__SatTrackBodyVecY : float, double__SatTrackBodyVecZ : float) -> None:
        """
        Struct 'ConfigAdcsSatellite' constructor
        
        Attributes
        ---------
        float__Ixx [1] : float
            Moment of inertia Ixx
        float__Iyy [1] : float
            Moment of inertia Iyy
        float__Izz [1] : float
            Moment of inertia Izz
        float__Ixy [1] : float
            Product of inertia Ixy
        float__Ixz [1] : float
            Product of inertia Ixz
        float__Iyz [1] : float
            Product of inertia Iyz
        double__SunPointBodyVecX [1] : float
            Sun-pointing body vector X component
        double__SunPointBodyVecY [1] : float
            Sun-pointing body vector Y component
        double__SunPointBodyVecZ [1] : float
            Sun-pointing body vector Z component
        double__TgtTrackBodyVecX [1] : float
            Target-tracking body vector X component
        double__TgtTrackBodyVecY [1] : float
            Target-tracking body vector Y component
        double__TgtTrackBodyVecZ [1] : float
            Target-tracking body vector Z component
        double__SatTrackBodyVecX [1] : float
            Satellite-tracking body vector X component
        double__SatTrackBodyVecY [1] : float
            Satellite-tracking body vector Y component
        double__SatTrackBodyVecZ [1] : float
            Satellite-tracking body vector Z component
        """
        
        pass
        
    def get_Ixx(self) -> float:
        """
        A getter for the 'ConfigAdcsSatellite::Ixx' structure field
        
        Moment of inertia Ixx
        """
        
        pass
    
    def get_Iyy(self) -> float:
        """
        A getter for the 'ConfigAdcsSatellite::Iyy' structure field
        
        Moment of inertia Iyy
        """
        
        pass
    
    def get_Izz(self) -> float:
        """
        A getter for the 'ConfigAdcsSatellite::Izz' structure field
        
        Moment of inertia Izz
        """
        
        pass
    
    def get_Ixy(self) -> float:
        """
        A getter for the 'ConfigAdcsSatellite::Ixy' structure field
        
        Product of inertia Ixy
        """
        
        pass
    
    def get_Ixz(self) -> float:
        """
        A getter for the 'ConfigAdcsSatellite::Ixz' structure field
        
        Product of inertia Ixz
        """
        
        pass
    
    def get_Iyz(self) -> float:
        """
        A getter for the 'ConfigAdcsSatellite::Iyz' structure field
        
        Product of inertia Iyz
        """
        
        pass
    
    def get_SunPointBodyVecX(self) -> float:
        """
        A getter for the 'ConfigAdcsSatellite::SunPointBodyVecX' structure field
        
        Sun-pointing body vector X component
        """
        
        pass
    
    def get_SunPointBodyVecY(self) -> float:
        """
        A getter for the 'ConfigAdcsSatellite::SunPointBodyVecY' structure field
        
        Sun-pointing body vector Y component
        """
        
        pass
    
    def get_SunPointBodyVecZ(self) -> float:
        """
        A getter for the 'ConfigAdcsSatellite::SunPointBodyVecZ' structure field
        
        Sun-pointing body vector Z component
        """
        
        pass
    
    def get_TgtTrackBodyVecX(self) -> float:
        """
        A getter for the 'ConfigAdcsSatellite::TgtTrackBodyVecX' structure field
        
        Target-tracking body vector X component
        """
        
        pass
    
    def get_TgtTrackBodyVecY(self) -> float:
        """
        A getter for the 'ConfigAdcsSatellite::TgtTrackBodyVecY' structure field
        
        Target-tracking body vector Y component
        """
        
        pass
    
    def get_TgtTrackBodyVecZ(self) -> float:
        """
        A getter for the 'ConfigAdcsSatellite::TgtTrackBodyVecZ' structure field
        
        Target-tracking body vector Z component
        """
        
        pass
    
    def get_SatTrackBodyVecX(self) -> float:
        """
        A getter for the 'ConfigAdcsSatellite::SatTrackBodyVecX' structure field
        
        Satellite-tracking body vector X component
        """
        
        pass
    
    def get_SatTrackBodyVecY(self) -> float:
        """
        A getter for the 'ConfigAdcsSatellite::SatTrackBodyVecY' structure field
        
        Satellite-tracking body vector Y component
        """
        
        pass
    
    def get_SatTrackBodyVecZ(self) -> float:
        """
        A getter for the 'ConfigAdcsSatellite::SatTrackBodyVecZ' structure field
        
        Satellite-tracking body vector Z component
        """
        
        pass

def ConfigAdcsSatellite_make_from_buf(buf : bytes) -> ConfigAdcsSatellite:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class AdcsRunMode:
    """
    A Python class to represent struct objects of type 'AdcsRunMode'
    
    Parameter structure for interface AdcsRunMode
    """

    def __init__(self, e__CubeComputerControlProgram8_AdcsRunModeSelect__RunMode : CubeComputerControlProgram8_AdcsRunModeSelect) -> None:
        """
        Struct 'AdcsRunMode' constructor
        
        Attributes
        ---------
        e__CubeComputerControlProgram8_AdcsRunModeSelect__RunMode [1] : CubeComputerControlProgram8_AdcsRunModeSelect
            ADCS run mode
        """
        
        pass
        
    def get_RunMode(self) -> CubeComputerControlProgram8_AdcsRunModeSelect:
        """
        A getter for the 'AdcsRunMode::RunMode' structure field
        
        ADCS run mode
        """
        
        pass

def AdcsRunMode_make_from_buf(buf : bytes) -> AdcsRunMode:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmStrCubeAurigaRaw:
    """
    A Python class to represent struct objects of type 'TlmStrCubeAurigaRaw'
    
    Parameter structure for interface TlmStrCubeAurigaRaw
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, uint16__Str0FrameCnt : int, uint16__Str0IDSATM : int, uint16__Str0SpecTC : int, uint16__Str0SyntDefATM : int, uint16__Str0SyntFusion : int, uint16__Str0SyntFil : int, uint32__Str0DateMesFil : int, double__Str0QRsFil1 : float, double__Str0QRsFil2 : float, double__Str0QRsFil3 : float, double__Str0QRsFil4 : float, uint16__Str0IQFilXRs : int, uint16__Str0IQFilYRs : int, uint16__Str0IQFilZRs : int, uint16__Str0NbEtoAtt : int, uint16__Str0NbEtoAttOH : int, uint16__Str0NbEtoCoh : int, uint16__Str0NbEtoCohOH : int, float__Str0WRsFil1 : float, float__Str0WRsFil2 : float, float__Str0WRsFil3 : float, uint16__Str0NLPMoyOH1 : int, uint16__Str0NLPMoyOH2 : int, uint16__Str0SyntFilOH1 : int, uint16__Str0SyntFilOH2 : int, uint16__Str0SyntFDIROH1 : int, uint16__Str0SyntFDIROH2 : int, uint16__Str0SyntDesOH1 : int, uint16__Str0SyntDesOH2 : int, e__CubeComputerControlProgram8_OhStateVal__Str0OH1State : CubeComputerControlProgram8_OhStateVal, e__CubeComputerControlProgram8_OhStateVal__Str0OH2State : CubeComputerControlProgram8_OhStateVal, bool__Str0DataValid : int, uint16__Str1FrameCnt : int, uint16__Str1IDSATM : int, uint16__Str1SpecTC : int, uint16__Str1SyntDefATM : int, uint16__Str1SyntFusion : int, uint16__Str1SyntFil : int, uint32__Str1DateMesFil : int, double__Str1QRsFil1 : float, double__Str1QRsFil2 : float, double__Str1QRsFil3 : float, double__Str1QRsFil4 : float, uint16__Str1IQFilXRs : int, uint16__Str1IQFilYRs : int, uint16__Str1IQFilZRs : int, uint16__Str1NbEtoAtt : int, uint16__Str1NbEtoAttOH : int, uint16__Str1NbEtoCoh : int, uint16__Str1NbEtoCohOH : int, float__Str1WRsFil1 : float, float__Str1WRsFil2 : float, float__Str1WRsFil3 : float, uint16__Str1NLPMoyOH1 : int, uint16__Str1NLPMoyOH2 : int, uint16__Str1SyntFilOH1 : int, uint16__Str1SyntFilOH2 : int, uint16__Str1SyntFDIROH1 : int, uint16__Str1SyntFDIROH2 : int, uint16__Str1SyntDesOH1 : int, uint16__Str1SyntDesOH2 : int, e__CubeComputerControlProgram8_OhStateVal__Str1OH1State : CubeComputerControlProgram8_OhStateVal, e__CubeComputerControlProgram8_OhStateVal__Str1OH2State : CubeComputerControlProgram8_OhStateVal, bool__Str1DataValid : int) -> None:
        """
        Struct 'TlmStrCubeAurigaRaw' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        uint16__Str0FrameCnt [1] : int
            Frame count number
        uint16__Str0IDSATM [1] : int
            Sub-Address Identifier
        uint16__Str0SpecTC [1] : int
            Options of Telecommand
        uint16__Str0SyntDefATM [1] : int
            Synthesis of coherence tests results
        uint16__Str0SyntFusion [1] : int
            Synthesis of fused quaternion status
        uint16__Str0SyntFil [1] : int
            Synthesis of available quaternions for averaging of fused quaternion
        uint32__Str0DateMesFil [1] : int
            QRsFil measurement time
        double__Str0QRsFil1 [1] : float
            Filtered fused attitude quaternion1 Rs/Rc
        double__Str0QRsFil2 [1] : float
            Filtered fused attitude quaternion2 Rs/Rc
        double__Str0QRsFil3 [1] : float
            Filtered fused attitude quaternion3 Rs/Rc
        double__Str0QRsFil4 [1] : float
            Filtered fused attitude quaternion4 Rs/Rc
        uint16__Str0IQFilXRs [1] : int
            Quality index of the filtered attitude about XRs STR axis
        uint16__Str0IQFilYRs [1] : int
            Quality index of the filtered attitude about YRs STR axis
        uint16__Str0IQFilZRs [1] : int
            Quality index of the filtered attitude about ZRs STR axis
        uint16__Str0NbEtoAtt [1] : int
            Number of expected stars inside STR FOV
        uint16__Str0NbEtoAttOH [1] : int
            Number of expected stars per OH
        uint16__Str0NbEtoCoh [1] : int
            Number of used stars for fused attitude
        uint16__Str0NbEtoCohOH [1] : int
            Number of coherent stars per OH
        float__Str0WRsFil1 [1] : float
            Filtered angular rate1 in Rs
        float__Str0WRsFil2 [1] : float
            Filtered angular rate2 in Rs
        float__Str0WRsFil3 [1] : float
            Filtered angular rate3 in Rs
        uint16__Str0NLPMoyOH1 [1] : int
            Mean level of stray-light for OH1
        uint16__Str0NLPMoyOH2 [1] : int
            Mean level of stray-light for OH2
        uint16__Str0SyntFilOH1 [1] : int
            Synthesis of available quaternions for averaging of OH1 quaternion
        uint16__Str0SyntFilOH2 [1] : int
            Synthesis of available quaternions for averaging of OH2 quaternion
        uint16__Str0SyntFDIROH1 [1] : int
            Synthesis of FDIR actions for OH1
        uint16__Str0SyntFDIROH2 [1] : int
            Synthesis of FDIR actions for OH2
        uint16__Str0SyntDesOH1 [1] : int
            Synthesis of OH1 designation
        uint16__Str0SyntDesOH2 [1] : int
            Synthesis of OH2 designation
        e__CubeComputerControlProgram8_OhStateVal__Str0OH1State [1] : CubeComputerControlProgram8_OhStateVal
            First Optical Head State
        e__CubeComputerControlProgram8_OhStateVal__Str0OH2State [1] : CubeComputerControlProgram8_OhStateVal
            Second Optical Head State
        bool__Str0DataValid [1] : int
            Data is valid
        uint16__Str1FrameCnt [1] : int
            Frame count number
        uint16__Str1IDSATM [1] : int
            Sub-Address Identifier
        uint16__Str1SpecTC [1] : int
            Options of Telecommand
        uint16__Str1SyntDefATM [1] : int
            Synthesis of coherence tests results
        uint16__Str1SyntFusion [1] : int
            Synthesis of fused quaternion status
        uint16__Str1SyntFil [1] : int
            Synthesis of available quaternions for averaging of fused quaternion
        uint32__Str1DateMesFil [1] : int
            QRsFil measurement time
        double__Str1QRsFil1 [1] : float
            Filtered fused attitude quaternion1 Rs/Rc
        double__Str1QRsFil2 [1] : float
            Filtered fused attitude quaternion2 Rs/Rc
        double__Str1QRsFil3 [1] : float
            Filtered fused attitude quaternion3 Rs/Rc
        double__Str1QRsFil4 [1] : float
            Filtered fused attitude quaternion4 Rs/Rc
        uint16__Str1IQFilXRs [1] : int
            Quality index of the filtered attitude about XRs STR axis
        uint16__Str1IQFilYRs [1] : int
            Quality index of the filtered attitude about YRs STR axis
        uint16__Str1IQFilZRs [1] : int
            Quality index of the filtered attitude about ZRs STR axis
        uint16__Str1NbEtoAtt [1] : int
            Number of expected stars inside STR FOV
        uint16__Str1NbEtoAttOH [1] : int
            Number of expected stars per OH
        uint16__Str1NbEtoCoh [1] : int
            Number of used stars for fused attitude
        uint16__Str1NbEtoCohOH [1] : int
            Number of coherent stars per OH
        float__Str1WRsFil1 [1] : float
            Filtered angular rate1 in Rs
        float__Str1WRsFil2 [1] : float
            Filtered angular rate2 in Rs
        float__Str1WRsFil3 [1] : float
            Filtered angular rate3 in Rs
        uint16__Str1NLPMoyOH1 [1] : int
            Mean level of stray-light for OH1
        uint16__Str1NLPMoyOH2 [1] : int
            Mean level of stray-light for OH2
        uint16__Str1SyntFilOH1 [1] : int
            Synthesis of available quaternions for averaging of OH1 quaternion
        uint16__Str1SyntFilOH2 [1] : int
            Synthesis of available quaternions for averaging of OH2 quaternion
        uint16__Str1SyntFDIROH1 [1] : int
            Synthesis of FDIR actions for OH1
        uint16__Str1SyntFDIROH2 [1] : int
            Synthesis of FDIR actions for OH2
        uint16__Str1SyntDesOH1 [1] : int
            Synthesis of OH1 designation
        uint16__Str1SyntDesOH2 [1] : int
            Synthesis of OH2 designation
        e__CubeComputerControlProgram8_OhStateVal__Str1OH1State [1] : CubeComputerControlProgram8_OhStateVal
            First Optical Head State
        e__CubeComputerControlProgram8_OhStateVal__Str1OH2State [1] : CubeComputerControlProgram8_OhStateVal
            Second Optical Head State
        bool__Str1DataValid [1] : int
            Data is valid
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_Str0FrameCnt(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0FrameCnt' structure field
        
        Frame count number
        """
        
        pass
    
    def get_Str0IDSATM(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0IDSATM' structure field
        
        Sub-Address Identifier
        """
        
        pass
    
    def get_Str0SpecTC(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0SpecTC' structure field
        
        Options of Telecommand
        """
        
        pass
    
    def get_Str0SyntDefATM(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0SyntDefATM' structure field
        
        Synthesis of coherence tests results
        """
        
        pass
    
    def get_Str0SyntFusion(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0SyntFusion' structure field
        
        Synthesis of fused quaternion status
        """
        
        pass
    
    def get_Str0SyntFil(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0SyntFil' structure field
        
        Synthesis of available quaternions for averaging of fused quaternion
        """
        
        pass
    
    def get_Str0DateMesFil(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0DateMesFil' structure field
        
        QRsFil measurement time
        """
        
        pass
    
    def get_Str0QRsFil1(self) -> float:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0QRsFil1' structure field
        
        Filtered fused attitude quaternion1 Rs/Rc
        """
        
        pass
    
    def get_Str0QRsFil2(self) -> float:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0QRsFil2' structure field
        
        Filtered fused attitude quaternion2 Rs/Rc
        """
        
        pass
    
    def get_Str0QRsFil3(self) -> float:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0QRsFil3' structure field
        
        Filtered fused attitude quaternion3 Rs/Rc
        """
        
        pass
    
    def get_Str0QRsFil4(self) -> float:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0QRsFil4' structure field
        
        Filtered fused attitude quaternion4 Rs/Rc
        """
        
        pass
    
    def get_Str0IQFilXRs(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0IQFilXRs' structure field
        
        Quality index of the filtered attitude about XRs STR axis
        """
        
        pass
    
    def get_Str0IQFilYRs(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0IQFilYRs' structure field
        
        Quality index of the filtered attitude about YRs STR axis
        """
        
        pass
    
    def get_Str0IQFilZRs(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0IQFilZRs' structure field
        
        Quality index of the filtered attitude about ZRs STR axis
        """
        
        pass
    
    def get_Str0NbEtoAtt(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0NbEtoAtt' structure field
        
        Number of expected stars inside STR FOV
        """
        
        pass
    
    def get_Str0NbEtoAttOH(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0NbEtoAttOH' structure field
        
        Number of expected stars per OH
        """
        
        pass
    
    def get_Str0NbEtoCoh(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0NbEtoCoh' structure field
        
        Number of used stars for fused attitude
        """
        
        pass
    
    def get_Str0NbEtoCohOH(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0NbEtoCohOH' structure field
        
        Number of coherent stars per OH
        """
        
        pass
    
    def get_Str0WRsFil1(self) -> float:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0WRsFil1' structure field
        
        Filtered angular rate1 in Rs
        """
        
        pass
    
    def get_Str0WRsFil2(self) -> float:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0WRsFil2' structure field
        
        Filtered angular rate2 in Rs
        """
        
        pass
    
    def get_Str0WRsFil3(self) -> float:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0WRsFil3' structure field
        
        Filtered angular rate3 in Rs
        """
        
        pass
    
    def get_Str0NLPMoyOH1(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0NLPMoyOH1' structure field
        
        Mean level of stray-light for OH1
        """
        
        pass
    
    def get_Str0NLPMoyOH2(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0NLPMoyOH2' structure field
        
        Mean level of stray-light for OH2
        """
        
        pass
    
    def get_Str0SyntFilOH1(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0SyntFilOH1' structure field
        
        Synthesis of available quaternions for averaging of OH1 quaternion
        """
        
        pass
    
    def get_Str0SyntFilOH2(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0SyntFilOH2' structure field
        
        Synthesis of available quaternions for averaging of OH2 quaternion
        """
        
        pass
    
    def get_Str0SyntFDIROH1(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0SyntFDIROH1' structure field
        
        Synthesis of FDIR actions for OH1
        """
        
        pass
    
    def get_Str0SyntFDIROH2(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0SyntFDIROH2' structure field
        
        Synthesis of FDIR actions for OH2
        """
        
        pass
    
    def get_Str0SyntDesOH1(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0SyntDesOH1' structure field
        
        Synthesis of OH1 designation
        """
        
        pass
    
    def get_Str0SyntDesOH2(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0SyntDesOH2' structure field
        
        Synthesis of OH2 designation
        """
        
        pass
    
    def get_Str0OH1State(self) -> CubeComputerControlProgram8_OhStateVal:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0OH1State' structure field
        
        First Optical Head State
        """
        
        pass
    
    def get_Str0OH2State(self) -> CubeComputerControlProgram8_OhStateVal:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0OH2State' structure field
        
        Second Optical Head State
        """
        
        pass
    
    def get_Str0DataValid(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str0DataValid' structure field
        
        Data is valid
        """
        
        pass
    
    def get_Str1FrameCnt(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1FrameCnt' structure field
        
        Frame count number
        """
        
        pass
    
    def get_Str1IDSATM(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1IDSATM' structure field
        
        Sub-Address Identifier
        """
        
        pass
    
    def get_Str1SpecTC(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1SpecTC' structure field
        
        Options of Telecommand
        """
        
        pass
    
    def get_Str1SyntDefATM(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1SyntDefATM' structure field
        
        Synthesis of coherence tests results
        """
        
        pass
    
    def get_Str1SyntFusion(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1SyntFusion' structure field
        
        Synthesis of fused quaternion status
        """
        
        pass
    
    def get_Str1SyntFil(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1SyntFil' structure field
        
        Synthesis of available quaternions for averaging of fused quaternion
        """
        
        pass
    
    def get_Str1DateMesFil(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1DateMesFil' structure field
        
        QRsFil measurement time
        """
        
        pass
    
    def get_Str1QRsFil1(self) -> float:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1QRsFil1' structure field
        
        Filtered fused attitude quaternion1 Rs/Rc
        """
        
        pass
    
    def get_Str1QRsFil2(self) -> float:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1QRsFil2' structure field
        
        Filtered fused attitude quaternion2 Rs/Rc
        """
        
        pass
    
    def get_Str1QRsFil3(self) -> float:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1QRsFil3' structure field
        
        Filtered fused attitude quaternion3 Rs/Rc
        """
        
        pass
    
    def get_Str1QRsFil4(self) -> float:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1QRsFil4' structure field
        
        Filtered fused attitude quaternion4 Rs/Rc
        """
        
        pass
    
    def get_Str1IQFilXRs(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1IQFilXRs' structure field
        
        Quality index of the filtered attitude about XRs STR axis
        """
        
        pass
    
    def get_Str1IQFilYRs(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1IQFilYRs' structure field
        
        Quality index of the filtered attitude about YRs STR axis
        """
        
        pass
    
    def get_Str1IQFilZRs(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1IQFilZRs' structure field
        
        Quality index of the filtered attitude about ZRs STR axis
        """
        
        pass
    
    def get_Str1NbEtoAtt(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1NbEtoAtt' structure field
        
        Number of expected stars inside STR FOV
        """
        
        pass
    
    def get_Str1NbEtoAttOH(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1NbEtoAttOH' structure field
        
        Number of expected stars per OH
        """
        
        pass
    
    def get_Str1NbEtoCoh(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1NbEtoCoh' structure field
        
        Number of used stars for fused attitude
        """
        
        pass
    
    def get_Str1NbEtoCohOH(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1NbEtoCohOH' structure field
        
        Number of coherent stars per OH
        """
        
        pass
    
    def get_Str1WRsFil1(self) -> float:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1WRsFil1' structure field
        
        Filtered angular rate1 in Rs
        """
        
        pass
    
    def get_Str1WRsFil2(self) -> float:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1WRsFil2' structure field
        
        Filtered angular rate2 in Rs
        """
        
        pass
    
    def get_Str1WRsFil3(self) -> float:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1WRsFil3' structure field
        
        Filtered angular rate3 in Rs
        """
        
        pass
    
    def get_Str1NLPMoyOH1(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1NLPMoyOH1' structure field
        
        Mean level of stray-light for OH1
        """
        
        pass
    
    def get_Str1NLPMoyOH2(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1NLPMoyOH2' structure field
        
        Mean level of stray-light for OH2
        """
        
        pass
    
    def get_Str1SyntFilOH1(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1SyntFilOH1' structure field
        
        Synthesis of available quaternions for averaging of OH1 quaternion
        """
        
        pass
    
    def get_Str1SyntFilOH2(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1SyntFilOH2' structure field
        
        Synthesis of available quaternions for averaging of OH2 quaternion
        """
        
        pass
    
    def get_Str1SyntFDIROH1(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1SyntFDIROH1' structure field
        
        Synthesis of FDIR actions for OH1
        """
        
        pass
    
    def get_Str1SyntFDIROH2(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1SyntFDIROH2' structure field
        
        Synthesis of FDIR actions for OH2
        """
        
        pass
    
    def get_Str1SyntDesOH1(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1SyntDesOH1' structure field
        
        Synthesis of OH1 designation
        """
        
        pass
    
    def get_Str1SyntDesOH2(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1SyntDesOH2' structure field
        
        Synthesis of OH2 designation
        """
        
        pass
    
    def get_Str1OH1State(self) -> CubeComputerControlProgram8_OhStateVal:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1OH1State' structure field
        
        First Optical Head State
        """
        
        pass
    
    def get_Str1OH2State(self) -> CubeComputerControlProgram8_OhStateVal:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1OH2State' structure field
        
        Second Optical Head State
        """
        
        pass
    
    def get_Str1DataValid(self) -> int:
        """
        A getter for the 'TlmStrCubeAurigaRaw::Str1DataValid' structure field
        
        Data is valid
        """
        
        pass

def TlmStrCubeAurigaRaw_make_from_buf(buf : bytes) -> TlmStrCubeAurigaRaw:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class OrbMode:
    """
    A Python class to represent struct objects of type 'OrbMode'
    
    Parameter structure for interface OrbMode
    """

    def __init__(self, e__CubeComputerControlProgram8_OrbModeSelect__OrbitMode : CubeComputerControlProgram8_OrbModeSelect) -> None:
        """
        Struct 'OrbMode' constructor
        
        Attributes
        ---------
        e__CubeComputerControlProgram8_OrbModeSelect__OrbitMode [1] : CubeComputerControlProgram8_OrbModeSelect
            Orbit calculation mode
        """
        
        pass
        
    def get_OrbitMode(self) -> CubeComputerControlProgram8_OrbModeSelect:
        """
        A getter for the 'OrbMode::OrbitMode' structure field
        
        Orbit calculation mode
        """
        
        pass

def OrbMode_make_from_buf(buf : bytes) -> OrbMode:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmModels:
    """
    A Python class to represent struct objects of type 'TlmModels'
    
    Parameter structure for interface TlmModels
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, int32__SatPosEciX : int, int32__SatPosEciY : int, int32__SatPosEciZ : int, int16__SatVelEciX : int, int16__SatVelEciY : int, int16__SatVelEciZ : int, double__SatLatGeod : float, double__SatLatGeoc : float, double__SatLon : float, double__SatAlt : float, int32__TgtPosEciX : int, int32__TgtPosEciY : int, int32__TgtPosEciZ : int, double__ModelMagOrcX : float, double__ModelMagOrcY : float, double__ModelMagOrcZ : float, double__ModelSunOrcX : float, double__ModelSunOrcY : float, double__ModelSunOrcZ : float, double__ModelSunBetaAngle : float, double__ModelHorRhoAngle : float, double__ModelHorXoEastAngle : float, double__ModelHorYiEastAngle : float, int32__Sat2TgtGndOrcX : int, int32__Sat2TgtGndOrcY : int, int32__Sat2TgtGndOrcZ : int, uint16__Asgp4BatchCtr : int, uint16__Asgp4PosDelta : int, e__CubeComputerControlProgram8_OrbModeSelect__OrbModeActive : CubeComputerControlProgram8_OrbModeSelect, bool__Asgp4Error : int, bool__Eclipse : int, e__CubeComputerControlProgram8_NavSource__NavSource : CubeComputerControlProgram8_NavSource) -> None:
        """
        Struct 'TlmModels' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        int32__SatPosEciX [1] : int
            Satellite ECI position vector X component
        int32__SatPosEciY [1] : int
            Satellite ECI position vector Y component
        int32__SatPosEciZ [1] : int
            Satellite ECI position vector Z component
        int16__SatVelEciX [1] : int
            Satellite ECI velocity vector X component
        int16__SatVelEciY [1] : int
            Satellite ECI velocity vector Y component
        int16__SatVelEciZ [1] : int
            Satellite ECI velocity vector Z component
        double__SatLatGeod [1] : float
            Satellite geodetic latitude
        double__SatLatGeoc [1] : float
            Satellite geocentric latitude
        double__SatLon [1] : float
            Satellite longitude
        double__SatAlt [1] : float
            Satellite altitude
        int32__TgtPosEciX [1] : int
            Target satellite ECI position vector X component
        int32__TgtPosEciY [1] : int
            Target satellite ECI position vector Y component
        int32__TgtPosEciZ [1] : int
            Target satellite ECI position vector Z component
        double__ModelMagOrcX [1] : float
            IGRF ORC model X component
        double__ModelMagOrcY [1] : float
            IGRF ORC model Y component
        double__ModelMagOrcZ [1] : float
            IGRF ORC model Z component
        double__ModelSunOrcX [1] : float
            Sun ORC model X component
        double__ModelSunOrcY [1] : float
            Sun ORC model Y component
        double__ModelSunOrcZ [1] : float
            Sun ORC model Z component
        double__ModelSunBetaAngle [1] : float
            Sun beta angle with orbit plane
        double__ModelHorRhoAngle [1] : float
            Horizon angle in XoYo plane
        double__ModelHorXoEastAngle [1] : float
            Horizon East angle from Xo direction
        double__ModelHorYiEastAngle [1] : float
            Horizon East angle from Yi direction
        int32__Sat2TgtGndOrcX [1] : int
            Satellite to ground ORC target vector X component
        int32__Sat2TgtGndOrcY [1] : int
            Satellite to ground ORC target vector Y component
        int32__Sat2TgtGndOrcZ [1] : int
            Satellite to ground ORC target vector Z component
        uint16__Asgp4BatchCtr [1] : int
            ASGP4 batch counter
        uint16__Asgp4PosDelta [1] : int
            Average position error between GNSS and ASGP4
        e__CubeComputerControlProgram8_OrbModeSelect__OrbModeActive [1] : CubeComputerControlProgram8_OrbModeSelect
            Active orbit mode
        bool__Asgp4Error [1] : int
            GNSS and ASGP4 position error differs too much
        bool__Eclipse [1] : int
            Eclipse flag
        e__CubeComputerControlProgram8_NavSource__NavSource [1] : CubeComputerControlProgram8_NavSource
            Source of current orbit position and velocity
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmModels::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmModels::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_SatPosEciX(self) -> int:
        """
        A getter for the 'TlmModels::SatPosEciX' structure field
        
        Satellite ECI position vector X component
        """
        
        pass
    
    def get_SatPosEciY(self) -> int:
        """
        A getter for the 'TlmModels::SatPosEciY' structure field
        
        Satellite ECI position vector Y component
        """
        
        pass
    
    def get_SatPosEciZ(self) -> int:
        """
        A getter for the 'TlmModels::SatPosEciZ' structure field
        
        Satellite ECI position vector Z component
        """
        
        pass
    
    def get_SatVelEciX(self) -> int:
        """
        A getter for the 'TlmModels::SatVelEciX' structure field
        
        Satellite ECI velocity vector X component
        """
        
        pass
    
    def get_SatVelEciY(self) -> int:
        """
        A getter for the 'TlmModels::SatVelEciY' structure field
        
        Satellite ECI velocity vector Y component
        """
        
        pass
    
    def get_SatVelEciZ(self) -> int:
        """
        A getter for the 'TlmModels::SatVelEciZ' structure field
        
        Satellite ECI velocity vector Z component
        """
        
        pass
    
    def get_SatLatGeod(self) -> float:
        """
        A getter for the 'TlmModels::SatLatGeod' structure field
        
        Satellite geodetic latitude
        """
        
        pass
    
    def get_SatLatGeoc(self) -> float:
        """
        A getter for the 'TlmModels::SatLatGeoc' structure field
        
        Satellite geocentric latitude
        """
        
        pass
    
    def get_SatLon(self) -> float:
        """
        A getter for the 'TlmModels::SatLon' structure field
        
        Satellite longitude
        """
        
        pass
    
    def get_SatAlt(self) -> float:
        """
        A getter for the 'TlmModels::SatAlt' structure field
        
        Satellite altitude
        """
        
        pass
    
    def get_TgtPosEciX(self) -> int:
        """
        A getter for the 'TlmModels::TgtPosEciX' structure field
        
        Target satellite ECI position vector X component
        """
        
        pass
    
    def get_TgtPosEciY(self) -> int:
        """
        A getter for the 'TlmModels::TgtPosEciY' structure field
        
        Target satellite ECI position vector Y component
        """
        
        pass
    
    def get_TgtPosEciZ(self) -> int:
        """
        A getter for the 'TlmModels::TgtPosEciZ' structure field
        
        Target satellite ECI position vector Z component
        """
        
        pass
    
    def get_ModelMagOrcX(self) -> float:
        """
        A getter for the 'TlmModels::ModelMagOrcX' structure field
        
        IGRF ORC model X component
        """
        
        pass
    
    def get_ModelMagOrcY(self) -> float:
        """
        A getter for the 'TlmModels::ModelMagOrcY' structure field
        
        IGRF ORC model Y component
        """
        
        pass
    
    def get_ModelMagOrcZ(self) -> float:
        """
        A getter for the 'TlmModels::ModelMagOrcZ' structure field
        
        IGRF ORC model Z component
        """
        
        pass
    
    def get_ModelSunOrcX(self) -> float:
        """
        A getter for the 'TlmModels::ModelSunOrcX' structure field
        
        Sun ORC model X component
        """
        
        pass
    
    def get_ModelSunOrcY(self) -> float:
        """
        A getter for the 'TlmModels::ModelSunOrcY' structure field
        
        Sun ORC model Y component
        """
        
        pass
    
    def get_ModelSunOrcZ(self) -> float:
        """
        A getter for the 'TlmModels::ModelSunOrcZ' structure field
        
        Sun ORC model Z component
        """
        
        pass
    
    def get_ModelSunBetaAngle(self) -> float:
        """
        A getter for the 'TlmModels::ModelSunBetaAngle' structure field
        
        Sun beta angle with orbit plane
        """
        
        pass
    
    def get_ModelHorRhoAngle(self) -> float:
        """
        A getter for the 'TlmModels::ModelHorRhoAngle' structure field
        
        Horizon angle in XoYo plane
        """
        
        pass
    
    def get_ModelHorXoEastAngle(self) -> float:
        """
        A getter for the 'TlmModels::ModelHorXoEastAngle' structure field
        
        Horizon East angle from Xo direction
        """
        
        pass
    
    def get_ModelHorYiEastAngle(self) -> float:
        """
        A getter for the 'TlmModels::ModelHorYiEastAngle' structure field
        
        Horizon East angle from Yi direction
        """
        
        pass
    
    def get_Sat2TgtGndOrcX(self) -> int:
        """
        A getter for the 'TlmModels::Sat2TgtGndOrcX' structure field
        
        Satellite to ground ORC target vector X component
        """
        
        pass
    
    def get_Sat2TgtGndOrcY(self) -> int:
        """
        A getter for the 'TlmModels::Sat2TgtGndOrcY' structure field
        
        Satellite to ground ORC target vector Y component
        """
        
        pass
    
    def get_Sat2TgtGndOrcZ(self) -> int:
        """
        A getter for the 'TlmModels::Sat2TgtGndOrcZ' structure field
        
        Satellite to ground ORC target vector Z component
        """
        
        pass
    
    def get_Asgp4BatchCtr(self) -> int:
        """
        A getter for the 'TlmModels::Asgp4BatchCtr' structure field
        
        ASGP4 batch counter
        """
        
        pass
    
    def get_Asgp4PosDelta(self) -> int:
        """
        A getter for the 'TlmModels::Asgp4PosDelta' structure field
        
        Average position error between GNSS and ASGP4
        """
        
        pass
    
    def get_OrbModeActive(self) -> CubeComputerControlProgram8_OrbModeSelect:
        """
        A getter for the 'TlmModels::OrbModeActive' structure field
        
        Active orbit mode
        """
        
        pass
    
    def get_Asgp4Error(self) -> int:
        """
        A getter for the 'TlmModels::Asgp4Error' structure field
        
        GNSS and ASGP4 position error differs too much
        """
        
        pass
    
    def get_Eclipse(self) -> int:
        """
        A getter for the 'TlmModels::Eclipse' structure field
        
        Eclipse flag
        """
        
        pass
    
    def get_NavSource(self) -> CubeComputerControlProgram8_NavSource:
        """
        A getter for the 'TlmModels::NavSource' structure field
        
        Source of current orbit position and velocity
        """
        
        pass

def TlmModels_make_from_buf(buf : bytes) -> TlmModels:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ReferenceFmcParam:
    """
    A Python class to represent struct objects of type 'ReferenceFmcParam'
    
    Parameter structure for interface ReferenceFmcParam
    """

    def __init__(self, e__CubeComputerControlProgram8_FmcFactor__CmdFmcFactor : CubeComputerControlProgram8_FmcFactor, float__CmdFmcRoll : float, uint32__CmdFmcUnixSeconds : int, uint32__CmdFmcUnixNs : int) -> None:
        """
        Struct 'ReferenceFmcParam' constructor
        
        Attributes
        ---------
        e__CubeComputerControlProgram8_FmcFactor__CmdFmcFactor [1] : CubeComputerControlProgram8_FmcFactor
            FMC Scanning Factor
        float__CmdFmcRoll [1] : float
            RPY Roll command
        uint32__CmdFmcUnixSeconds [1] : int
            Unix time seconds at FMC target centre
        uint32__CmdFmcUnixNs [1] : int
            Unix time nanoseconds at FMC target centre
        """
        
        pass
        
    def get_CmdFmcFactor(self) -> CubeComputerControlProgram8_FmcFactor:
        """
        A getter for the 'ReferenceFmcParam::CmdFmcFactor' structure field
        
        FMC Scanning Factor
        """
        
        pass
    
    def get_CmdFmcRoll(self) -> float:
        """
        A getter for the 'ReferenceFmcParam::CmdFmcRoll' structure field
        
        RPY Roll command
        """
        
        pass
    
    def get_CmdFmcUnixSeconds(self) -> int:
        """
        A getter for the 'ReferenceFmcParam::CmdFmcUnixSeconds' structure field
        
        Unix time seconds at FMC target centre
        """
        
        pass
    
    def get_CmdFmcUnixNs(self) -> int:
        """
        A getter for the 'ReferenceFmcParam::CmdFmcUnixNs' structure field
        
        Unix time nanoseconds at FMC target centre
        """
        
        pass

def ReferenceFmcParam_make_from_buf(buf : bytes) -> ReferenceFmcParam:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmStrAurigaHealth:
    """
    A Python class to represent struct objects of type 'TlmStrAurigaHealth'
    
    Parameter structure for interface TlmStrAurigaHealth
    """

    def __init__(self, uint16__Str0McuVoltage : int, int16__Str0McuTemp : int, double__Str0McuCurrent : float, double__Str0SramCurrent : float, double__Str0Oh1Current : float, double__Str0Oh2Current : float, double__Str0Fpga1Current : float, double__Str0Fpga2Current : float, uint16__Str0Fpga1Voltage : int, uint16__Str0Fpga2Voltage : int, uint16__Str0ProcessIdleTiming : int, uint16__Str0AcqSynthFlags : int, e__CubeComputerControlProgram8_AurigaLibStateVal__Str0STRMode : CubeComputerControlProgram8_AurigaLibStateVal, int16__Str0OH1Temp : int, int16__Str0OH2Temp : int, uint16__Str0BlocksValidity : int, uint8__Str0ResetCnt : int, uint8__Str0LastTCSeqNum : int, uint8__Str0TCCnt : int, uint8__Str0ErrorInfo : int, uint32__Str0LastErrorParam : int, uint8__Str0LastErrorId : int, uint8__Str0TRKLossCnt : int, uint16__Str1McuVoltage : int, int16__Str1McuTemp : int, double__Str1McuCurrent : float, double__Str1SramCurrent : float, double__Str1Oh1Current : float, double__Str1Oh2Current : float, double__Str1Fpga1Current : float, double__Str1Fpga2Current : float, uint16__Str1Fpga1Voltage : int, uint16__Str1Fpga2Voltage : int, uint16__Str1ProcessIdleTiming : int, uint16__Str1AcqSynthFlags : int, e__CubeComputerControlProgram8_AurigaLibStateVal__Str1STRMode : CubeComputerControlProgram8_AurigaLibStateVal, int16__Str1OH1Temp : int, int16__Str1OH2Temp : int, uint16__Str1BlocksValidity : int, uint8__Str1ResetCnt : int, uint8__Str1LastTCSeqNum : int, uint8__Str1TCCnt : int, uint8__Str1ErrorInfo : int, uint32__Str1LastErrorParam : int, uint8__Str1LastErrorId : int, uint8__Str1TRKLossCnt : int) -> None:
        """
        Struct 'TlmStrAurigaHealth' constructor
        
        Attributes
        ---------
        uint16__Str0McuVoltage [1] : int
            MCU supply voltage
        int16__Str0McuTemp [1] : int
            MCU Temperature
        double__Str0McuCurrent [1] : float
            MCU current
        double__Str0SramCurrent [1] : float
            SRAM current
        double__Str0Oh1Current [1] : float
            OH1 Current
        double__Str0Oh2Current [1] : float
            OH2 Current
        double__Str0Fpga1Current [1] : float
            FPGA1 Current
        double__Str0Fpga2Current [1] : float
            FPGA2 Current
        uint16__Str0Fpga1Voltage [1] : int
            FPGA1 Voltage
        uint16__Str0Fpga2Voltage [1] : int
            FPGA2 Voltage
        uint16__Str0ProcessIdleTiming [1] : int
            Process idle delay (idle time between consecutive processing cycles)
        uint16__Str0AcqSynthFlags [1] : int
            STR Synthesis flags for analog acquisition
        e__CubeComputerControlProgram8_AurigaLibStateVal__Str0STRMode [1] : CubeComputerControlProgram8_AurigaLibStateVal
            Star Tracker Mode
        int16__Str0OH1Temp [1] : int
            OH1 Temperature
        int16__Str0OH2Temp [1] : int
            OH2 Temperature
        uint16__Str0BlocksValidity [1] : int
            Blocks Validity at library initialization
        uint8__Str0ResetCnt [1] : int
            STR hot reset counters
        uint8__Str0LastTCSeqNum [1] : int
            Sequence number (8 low bits) of the last STR TC processed
        uint8__Str0TCCnt [1] : int
            STR TC counters
        uint8__Str0ErrorInfo [1] : int
            Number of errors since last STR cold reset and various error indicator
        uint32__Str0LastErrorParam [1] : int
            Last Error Parameter
        uint8__Str0LastErrorId [1] : int
            Last Error Identifier
        uint8__Str0TRKLossCnt [1] : int
            Number of loss of tracking since last STR reset
        uint16__Str1McuVoltage [1] : int
            MCU supply voltage
        int16__Str1McuTemp [1] : int
            MCU Temperature
        double__Str1McuCurrent [1] : float
            MCU current
        double__Str1SramCurrent [1] : float
            SRAM current
        double__Str1Oh1Current [1] : float
            OH1 Current
        double__Str1Oh2Current [1] : float
            OH2 Current
        double__Str1Fpga1Current [1] : float
            FPGA1 Current
        double__Str1Fpga2Current [1] : float
            FPGA2 Current
        uint16__Str1Fpga1Voltage [1] : int
            FPGA1 Voltage
        uint16__Str1Fpga2Voltage [1] : int
            FPGA2 Voltage
        uint16__Str1ProcessIdleTiming [1] : int
            Process idle delay (idle time between consecutive processing cycles)
        uint16__Str1AcqSynthFlags [1] : int
            STR Synthesis flags for analog acquisition
        e__CubeComputerControlProgram8_AurigaLibStateVal__Str1STRMode [1] : CubeComputerControlProgram8_AurigaLibStateVal
            Star Tracker Mode
        int16__Str1OH1Temp [1] : int
            OH1 Temperature
        int16__Str1OH2Temp [1] : int
            OH2 Temperature
        uint16__Str1BlocksValidity [1] : int
            Blocks Validity at library initialization
        uint8__Str1ResetCnt [1] : int
            STR hot reset counters
        uint8__Str1LastTCSeqNum [1] : int
            Sequence number (8 low bits) of the last STR TC processed
        uint8__Str1TCCnt [1] : int
            STR TC counters
        uint8__Str1ErrorInfo [1] : int
            Number of errors since last STR cold reset and various error indicator
        uint32__Str1LastErrorParam [1] : int
            Last Error Parameter
        uint8__Str1LastErrorId [1] : int
            Last Error Identifier
        uint8__Str1TRKLossCnt [1] : int
            Number of loss of tracking since last STR reset
        """
        
        pass
        
    def get_Str0McuVoltage(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str0McuVoltage' structure field
        
        MCU supply voltage
        """
        
        pass
    
    def get_Str0McuTemp(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str0McuTemp' structure field
        
        MCU Temperature
        """
        
        pass
    
    def get_Str0McuCurrent(self) -> float:
        """
        A getter for the 'TlmStrAurigaHealth::Str0McuCurrent' structure field
        
        MCU current
        """
        
        pass
    
    def get_Str0SramCurrent(self) -> float:
        """
        A getter for the 'TlmStrAurigaHealth::Str0SramCurrent' structure field
        
        SRAM current
        """
        
        pass
    
    def get_Str0Oh1Current(self) -> float:
        """
        A getter for the 'TlmStrAurigaHealth::Str0Oh1Current' structure field
        
        OH1 Current
        """
        
        pass
    
    def get_Str0Oh2Current(self) -> float:
        """
        A getter for the 'TlmStrAurigaHealth::Str0Oh2Current' structure field
        
        OH2 Current
        """
        
        pass
    
    def get_Str0Fpga1Current(self) -> float:
        """
        A getter for the 'TlmStrAurigaHealth::Str0Fpga1Current' structure field
        
        FPGA1 Current
        """
        
        pass
    
    def get_Str0Fpga2Current(self) -> float:
        """
        A getter for the 'TlmStrAurigaHealth::Str0Fpga2Current' structure field
        
        FPGA2 Current
        """
        
        pass
    
    def get_Str0Fpga1Voltage(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str0Fpga1Voltage' structure field
        
        FPGA1 Voltage
        """
        
        pass
    
    def get_Str0Fpga2Voltage(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str0Fpga2Voltage' structure field
        
        FPGA2 Voltage
        """
        
        pass
    
    def get_Str0ProcessIdleTiming(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str0ProcessIdleTiming' structure field
        
        Process idle delay (idle time between consecutive processing cycles)
        """
        
        pass
    
    def get_Str0AcqSynthFlags(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str0AcqSynthFlags' structure field
        
        STR Synthesis flags for analog acquisition
        """
        
        pass
    
    def get_Str0STRMode(self) -> CubeComputerControlProgram8_AurigaLibStateVal:
        """
        A getter for the 'TlmStrAurigaHealth::Str0STRMode' structure field
        
        Star Tracker Mode
        """
        
        pass
    
    def get_Str0OH1Temp(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str0OH1Temp' structure field
        
        OH1 Temperature
        """
        
        pass
    
    def get_Str0OH2Temp(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str0OH2Temp' structure field
        
        OH2 Temperature
        """
        
        pass
    
    def get_Str0BlocksValidity(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str0BlocksValidity' structure field
        
        Blocks Validity at library initialization
        """
        
        pass
    
    def get_Str0ResetCnt(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str0ResetCnt' structure field
        
        STR hot reset counters
        """
        
        pass
    
    def get_Str0LastTCSeqNum(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str0LastTCSeqNum' structure field
        
        Sequence number (8 low bits) of the last STR TC processed
        """
        
        pass
    
    def get_Str0TCCnt(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str0TCCnt' structure field
        
        STR TC counters
        """
        
        pass
    
    def get_Str0ErrorInfo(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str0ErrorInfo' structure field
        
        Number of errors since last STR cold reset and various error indicator
        """
        
        pass
    
    def get_Str0LastErrorParam(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str0LastErrorParam' structure field
        
        Last Error Parameter
        """
        
        pass
    
    def get_Str0LastErrorId(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str0LastErrorId' structure field
        
        Last Error Identifier
        """
        
        pass
    
    def get_Str0TRKLossCnt(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str0TRKLossCnt' structure field
        
        Number of loss of tracking since last STR reset
        """
        
        pass
    
    def get_Str1McuVoltage(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str1McuVoltage' structure field
        
        MCU supply voltage
        """
        
        pass
    
    def get_Str1McuTemp(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str1McuTemp' structure field
        
        MCU Temperature
        """
        
        pass
    
    def get_Str1McuCurrent(self) -> float:
        """
        A getter for the 'TlmStrAurigaHealth::Str1McuCurrent' structure field
        
        MCU current
        """
        
        pass
    
    def get_Str1SramCurrent(self) -> float:
        """
        A getter for the 'TlmStrAurigaHealth::Str1SramCurrent' structure field
        
        SRAM current
        """
        
        pass
    
    def get_Str1Oh1Current(self) -> float:
        """
        A getter for the 'TlmStrAurigaHealth::Str1Oh1Current' structure field
        
        OH1 Current
        """
        
        pass
    
    def get_Str1Oh2Current(self) -> float:
        """
        A getter for the 'TlmStrAurigaHealth::Str1Oh2Current' structure field
        
        OH2 Current
        """
        
        pass
    
    def get_Str1Fpga1Current(self) -> float:
        """
        A getter for the 'TlmStrAurigaHealth::Str1Fpga1Current' structure field
        
        FPGA1 Current
        """
        
        pass
    
    def get_Str1Fpga2Current(self) -> float:
        """
        A getter for the 'TlmStrAurigaHealth::Str1Fpga2Current' structure field
        
        FPGA2 Current
        """
        
        pass
    
    def get_Str1Fpga1Voltage(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str1Fpga1Voltage' structure field
        
        FPGA1 Voltage
        """
        
        pass
    
    def get_Str1Fpga2Voltage(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str1Fpga2Voltage' structure field
        
        FPGA2 Voltage
        """
        
        pass
    
    def get_Str1ProcessIdleTiming(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str1ProcessIdleTiming' structure field
        
        Process idle delay (idle time between consecutive processing cycles)
        """
        
        pass
    
    def get_Str1AcqSynthFlags(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str1AcqSynthFlags' structure field
        
        STR Synthesis flags for analog acquisition
        """
        
        pass
    
    def get_Str1STRMode(self) -> CubeComputerControlProgram8_AurigaLibStateVal:
        """
        A getter for the 'TlmStrAurigaHealth::Str1STRMode' structure field
        
        Star Tracker Mode
        """
        
        pass
    
    def get_Str1OH1Temp(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str1OH1Temp' structure field
        
        OH1 Temperature
        """
        
        pass
    
    def get_Str1OH2Temp(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str1OH2Temp' structure field
        
        OH2 Temperature
        """
        
        pass
    
    def get_Str1BlocksValidity(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str1BlocksValidity' structure field
        
        Blocks Validity at library initialization
        """
        
        pass
    
    def get_Str1ResetCnt(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str1ResetCnt' structure field
        
        STR hot reset counters
        """
        
        pass
    
    def get_Str1LastTCSeqNum(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str1LastTCSeqNum' structure field
        
        Sequence number (8 low bits) of the last STR TC processed
        """
        
        pass
    
    def get_Str1TCCnt(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str1TCCnt' structure field
        
        STR TC counters
        """
        
        pass
    
    def get_Str1ErrorInfo(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str1ErrorInfo' structure field
        
        Number of errors since last STR cold reset and various error indicator
        """
        
        pass
    
    def get_Str1LastErrorParam(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str1LastErrorParam' structure field
        
        Last Error Parameter
        """
        
        pass
    
    def get_Str1LastErrorId(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str1LastErrorId' structure field
        
        Last Error Identifier
        """
        
        pass
    
    def get_Str1TRKLossCnt(self) -> int:
        """
        A getter for the 'TlmStrAurigaHealth::Str1TRKLossCnt' structure field
        
        Number of loss of tracking since last STR reset
        """
        
        pass

def TlmStrAurigaHealth_make_from_buf(buf : bytes) -> TlmStrAurigaHealth:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmExecutionPoint:
    """
    A Python class to represent struct objects of type 'TlmExecutionPoint'
    
    Parameter structure for interface TlmExecutionPoint
    """

    def __init__(self, e__CubeComputerControlProgram8_AcpExecutionPoint__CurrentExecutionPoint : CubeComputerControlProgram8_AcpExecutionPoint) -> None:
        """
        Struct 'TlmExecutionPoint' constructor
        
        Attributes
        ---------
        e__CubeComputerControlProgram8_AcpExecutionPoint__CurrentExecutionPoint [1] : CubeComputerControlProgram8_AcpExecutionPoint
            Indicates which part of the loop is currently executing
        """
        
        pass
        
    def get_CurrentExecutionPoint(self) -> CubeComputerControlProgram8_AcpExecutionPoint:
        """
        A getter for the 'TlmExecutionPoint::CurrentExecutionPoint' structure field
        
        Indicates which part of the loop is currently executing
        """
        
        pass

def TlmExecutionPoint_make_from_buf(buf : bytes) -> TlmExecutionPoint:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmAcpExecution:
    """
    A Python class to represent struct objects of type 'TlmAcpExecution'
    
    Parameter structure for interface TlmAcpExecution
    """

    def __init__(self, uint16__TimeSinceLoopStart : int, e__CubeComputerControlProgram8_AcpExecutionPoint__CurrentExecutionPoint : CubeComputerControlProgram8_AcpExecutionPoint, uint16__ExecTimeNodeSync : int, uint16__ExecTimeSensorComms : int, uint16__ExecTimeSensorCal : int, uint16__ExecTimeEstimators : int, uint16__ExecTimeControllers : int, uint16__ExecTimeWheelComms : int, uint16__ExecTimeModels : int, uint16__ExecTimeLoopSync : int, uint16__ExecTimeHealth : int, uint16__ExecTimeTlmLog : int, int16__LoopRtcOffset : int, bool__LoopHasStarted : int, bool__HilSyncOk : int) -> None:
        """
        Struct 'TlmAcpExecution' constructor
        
        Attributes
        ---------
        uint16__TimeSinceLoopStart [1] : int
            Time since the start of the current loop iteration
        e__CubeComputerControlProgram8_AcpExecutionPoint__CurrentExecutionPoint [1] : CubeComputerControlProgram8_AcpExecutionPoint
            Indicates which part of the loop is currently executing
        uint16__ExecTimeNodeSync [1] : int
            Execution time of node sync
        uint16__ExecTimeSensorComms [1] : int
            Execution time of sensor comms
        uint16__ExecTimeSensorCal [1] : int
            Execution time of sensor calibration
        uint16__ExecTimeEstimators [1] : int
            Execution time of ADCS estimators
        uint16__ExecTimeControllers [1] : int
            Execution time of ADCS controllers
        uint16__ExecTimeWheelComms [1] : int
            Execution time of wheel comms
        uint16__ExecTimeModels [1] : int
            Execution time of ADCS models
        uint16__ExecTimeLoopSync [1] : int
            Execution time of ADCS loop sync
        uint16__ExecTimeHealth [1] : int
            Execution time of health service
        uint16__ExecTimeTlmLog [1] : int
            Execution time of telemetry logging
        int16__LoopRtcOffset [1] : int
            Time offset between the ADCS loop and RTC control pulse
        bool__LoopHasStarted [1] : int
            ADCS loop has started flag
        bool__HilSyncOk [1] : int
            HIL is currently synchronised
        """
        
        pass
        
    def get_TimeSinceLoopStart(self) -> int:
        """
        A getter for the 'TlmAcpExecution::TimeSinceLoopStart' structure field
        
        Time since the start of the current loop iteration
        """
        
        pass
    
    def get_CurrentExecutionPoint(self) -> CubeComputerControlProgram8_AcpExecutionPoint:
        """
        A getter for the 'TlmAcpExecution::CurrentExecutionPoint' structure field
        
        Indicates which part of the loop is currently executing
        """
        
        pass
    
    def get_ExecTimeNodeSync(self) -> int:
        """
        A getter for the 'TlmAcpExecution::ExecTimeNodeSync' structure field
        
        Execution time of node sync
        """
        
        pass
    
    def get_ExecTimeSensorComms(self) -> int:
        """
        A getter for the 'TlmAcpExecution::ExecTimeSensorComms' structure field
        
        Execution time of sensor comms
        """
        
        pass
    
    def get_ExecTimeSensorCal(self) -> int:
        """
        A getter for the 'TlmAcpExecution::ExecTimeSensorCal' structure field
        
        Execution time of sensor calibration
        """
        
        pass
    
    def get_ExecTimeEstimators(self) -> int:
        """
        A getter for the 'TlmAcpExecution::ExecTimeEstimators' structure field
        
        Execution time of ADCS estimators
        """
        
        pass
    
    def get_ExecTimeControllers(self) -> int:
        """
        A getter for the 'TlmAcpExecution::ExecTimeControllers' structure field
        
        Execution time of ADCS controllers
        """
        
        pass
    
    def get_ExecTimeWheelComms(self) -> int:
        """
        A getter for the 'TlmAcpExecution::ExecTimeWheelComms' structure field
        
        Execution time of wheel comms
        """
        
        pass
    
    def get_ExecTimeModels(self) -> int:
        """
        A getter for the 'TlmAcpExecution::ExecTimeModels' structure field
        
        Execution time of ADCS models
        """
        
        pass
    
    def get_ExecTimeLoopSync(self) -> int:
        """
        A getter for the 'TlmAcpExecution::ExecTimeLoopSync' structure field
        
        Execution time of ADCS loop sync
        """
        
        pass
    
    def get_ExecTimeHealth(self) -> int:
        """
        A getter for the 'TlmAcpExecution::ExecTimeHealth' structure field
        
        Execution time of health service
        """
        
        pass
    
    def get_ExecTimeTlmLog(self) -> int:
        """
        A getter for the 'TlmAcpExecution::ExecTimeTlmLog' structure field
        
        Execution time of telemetry logging
        """
        
        pass
    
    def get_LoopRtcOffset(self) -> int:
        """
        A getter for the 'TlmAcpExecution::LoopRtcOffset' structure field
        
        Time offset between the ADCS loop and RTC control pulse
        """
        
        pass
    
    def get_LoopHasStarted(self) -> int:
        """
        A getter for the 'TlmAcpExecution::LoopHasStarted' structure field
        
        ADCS loop has started flag
        """
        
        pass
    
    def get_HilSyncOk(self) -> int:
        """
        A getter for the 'TlmAcpExecution::HilSyncOk' structure field
        
        HIL is currently synchronised
        """
        
        pass

def TlmAcpExecution_make_from_buf(buf : bytes) -> TlmAcpExecution:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class AdcsOpState:
    """
    A Python class to represent struct objects of type 'AdcsOpState'
    
    Parameter structure for interface AdcsOpState
    """

    def __init__(self, e__CubeComputerControlProgram8_AdcsOpStateSelect__OpState : CubeComputerControlProgram8_AdcsOpStateSelect) -> None:
        """
        Struct 'AdcsOpState' constructor
        
        Attributes
        ---------
        e__CubeComputerControlProgram8_AdcsOpStateSelect__OpState [1] : CubeComputerControlProgram8_AdcsOpStateSelect
            ADCS operational state
        """
        
        pass
        
    def get_OpState(self) -> CubeComputerControlProgram8_AdcsOpStateSelect:
        """
        A getter for the 'AdcsOpState::OpState' structure field
        
        ADCS operational state
        """
        
        pass

def AdcsOpState_make_from_buf(buf : bytes) -> AdcsOpState:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmEstimatorMain:
    """
    A Python class to represent struct objects of type 'TlmEstimatorMain'
    
    Parameter structure for interface TlmEstimatorMain
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, double__EstRpyRoll : float, double__EstRpyPitch : float, double__EstRpyYaw : float, double__EstQuatQ0 : float, double__EstQuatQ1 : float, double__EstQuatQ2 : float, double__EstQuatQ3 : float, double__EstGyroBiasX : float, double__EstGyroBiasY : float, double__EstGyroBiasZ : float, double__EstRateOrcX : float, double__EstRateOrcY : float, double__EstRateOrcZ : float, double__EstRateIrcX : float, double__EstRateIrcY : float, double__EstRateIrcZ : float, float__EstGyrTorqueX : float, float__EstGyrTorqueY : float, float__EstGyrTorqueZ : float, double__EstInnovX : float, double__EstInnovY : float, double__EstInnovZ : float, double__EstStdDevRateX : float, double__EstStdDevRateY : float, double__EstStdDevRateZ : float, double__EstStdDevQ0 : float, double__EstStdDevQ1 : float, double__EstStdDevQ2 : float, e__CubeComputerControlProgram8_EstModeSelect__EstModeActive : CubeComputerControlProgram8_EstModeSelect) -> None:
        """
        Struct 'TlmEstimatorMain' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        double__EstRpyRoll [1] : float
            Estimated roll angle
        double__EstRpyPitch [1] : float
            Estimated pitch angle
        double__EstRpyYaw [1] : float
            Estimated yaw angle
        double__EstQuatQ0 [1] : float
            Estimated ORC quaternion Q0
        double__EstQuatQ1 [1] : float
            Estimated ORC quaternion Q1
        double__EstQuatQ2 [1] : float
            Estimated ORC quaternion Q2
        double__EstQuatQ3 [1] : float
            Estimated ORC quaternion Q3
        double__EstGyroBiasX [1] : float
            Estimated gyro bias X component
        double__EstGyroBiasY [1] : float
            Estimated gyro bias Y component
        double__EstGyroBiasZ [1] : float
            Estimated gyro bias Z component
        double__EstRateOrcX [1] : float
            Estimated body rate (ORC) X component
        double__EstRateOrcY [1] : float
            Estimated body rate (ORC) Y component
        double__EstRateOrcZ [1] : float
            Estimated body rate (ORC) Z component
        double__EstRateIrcX [1] : float
            Estimated body rate (IRC) X component
        double__EstRateIrcY [1] : float
            Estimated body rate (IRC) Y component
        double__EstRateIrcZ [1] : float
            Estimated body rate (IRC) Z component
        float__EstGyrTorqueX [1] : float
            Estimated gyroscopic torque X component
        float__EstGyrTorqueY [1] : float
            Estimated gyroscopic torque Y component
        float__EstGyrTorqueZ [1] : float
            Estimated gyroscopic torque Z component
        double__EstInnovX [1] : float
            Innovation vector X component
        double__EstInnovY [1] : float
            Innovation vector Y component
        double__EstInnovZ [1] : float
            Innovation vector Z component
        double__EstStdDevRateX [1] : float
            StdDev of estimated rate X component
        double__EstStdDevRateY [1] : float
            StdDev of estimated rate Y component
        double__EstStdDevRateZ [1] : float
            StdDev of estimated rate Z component
        double__EstStdDevQ0 [1] : float
            StdDev of estimated quaternion Q0 component
        double__EstStdDevQ1 [1] : float
            StdDev of estimated quaternion Q1 component
        double__EstStdDevQ2 [1] : float
            StdDev of estimated quaternion Q2 component
        e__CubeComputerControlProgram8_EstModeSelect__EstModeActive [1] : CubeComputerControlProgram8_EstModeSelect
            Active estimator mode
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmEstimatorMain::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmEstimatorMain::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_EstRpyRoll(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstRpyRoll' structure field
        
        Estimated roll angle
        """
        
        pass
    
    def get_EstRpyPitch(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstRpyPitch' structure field
        
        Estimated pitch angle
        """
        
        pass
    
    def get_EstRpyYaw(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstRpyYaw' structure field
        
        Estimated yaw angle
        """
        
        pass
    
    def get_EstQuatQ0(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstQuatQ0' structure field
        
        Estimated ORC quaternion Q0
        """
        
        pass
    
    def get_EstQuatQ1(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstQuatQ1' structure field
        
        Estimated ORC quaternion Q1
        """
        
        pass
    
    def get_EstQuatQ2(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstQuatQ2' structure field
        
        Estimated ORC quaternion Q2
        """
        
        pass
    
    def get_EstQuatQ3(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstQuatQ3' structure field
        
        Estimated ORC quaternion Q3
        """
        
        pass
    
    def get_EstGyroBiasX(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstGyroBiasX' structure field
        
        Estimated gyro bias X component
        """
        
        pass
    
    def get_EstGyroBiasY(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstGyroBiasY' structure field
        
        Estimated gyro bias Y component
        """
        
        pass
    
    def get_EstGyroBiasZ(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstGyroBiasZ' structure field
        
        Estimated gyro bias Z component
        """
        
        pass
    
    def get_EstRateOrcX(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstRateOrcX' structure field
        
        Estimated body rate (ORC) X component
        """
        
        pass
    
    def get_EstRateOrcY(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstRateOrcY' structure field
        
        Estimated body rate (ORC) Y component
        """
        
        pass
    
    def get_EstRateOrcZ(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstRateOrcZ' structure field
        
        Estimated body rate (ORC) Z component
        """
        
        pass
    
    def get_EstRateIrcX(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstRateIrcX' structure field
        
        Estimated body rate (IRC) X component
        """
        
        pass
    
    def get_EstRateIrcY(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstRateIrcY' structure field
        
        Estimated body rate (IRC) Y component
        """
        
        pass
    
    def get_EstRateIrcZ(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstRateIrcZ' structure field
        
        Estimated body rate (IRC) Z component
        """
        
        pass
    
    def get_EstGyrTorqueX(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstGyrTorqueX' structure field
        
        Estimated gyroscopic torque X component
        """
        
        pass
    
    def get_EstGyrTorqueY(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstGyrTorqueY' structure field
        
        Estimated gyroscopic torque Y component
        """
        
        pass
    
    def get_EstGyrTorqueZ(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstGyrTorqueZ' structure field
        
        Estimated gyroscopic torque Z component
        """
        
        pass
    
    def get_EstInnovX(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstInnovX' structure field
        
        Innovation vector X component
        """
        
        pass
    
    def get_EstInnovY(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstInnovY' structure field
        
        Innovation vector Y component
        """
        
        pass
    
    def get_EstInnovZ(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstInnovZ' structure field
        
        Innovation vector Z component
        """
        
        pass
    
    def get_EstStdDevRateX(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstStdDevRateX' structure field
        
        StdDev of estimated rate X component
        """
        
        pass
    
    def get_EstStdDevRateY(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstStdDevRateY' structure field
        
        StdDev of estimated rate Y component
        """
        
        pass
    
    def get_EstStdDevRateZ(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstStdDevRateZ' structure field
        
        StdDev of estimated rate Z component
        """
        
        pass
    
    def get_EstStdDevQ0(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstStdDevQ0' structure field
        
        StdDev of estimated quaternion Q0 component
        """
        
        pass
    
    def get_EstStdDevQ1(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstStdDevQ1' structure field
        
        StdDev of estimated quaternion Q1 component
        """
        
        pass
    
    def get_EstStdDevQ2(self) -> float:
        """
        A getter for the 'TlmEstimatorMain::EstStdDevQ2' structure field
        
        StdDev of estimated quaternion Q2 component
        """
        
        pass
    
    def get_EstModeActive(self) -> CubeComputerControlProgram8_EstModeSelect:
        """
        A getter for the 'TlmEstimatorMain::EstModeActive' structure field
        
        Active estimator mode
        """
        
        pass

def TlmEstimatorMain_make_from_buf(buf : bytes) -> TlmEstimatorMain:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmEstimatorBackup:
    """
    A Python class to represent struct objects of type 'TlmEstimatorBackup'
    
    Parameter structure for interface TlmEstimatorBackup
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, double__EstRpyRoll : float, double__EstRpyPitch : float, double__EstRpyYaw : float, double__EstQuatQ0 : float, double__EstQuatQ1 : float, double__EstQuatQ2 : float, double__EstQuatQ3 : float, double__EstGyroBiasX : float, double__EstGyroBiasY : float, double__EstGyroBiasZ : float, double__EstRateOrcX : float, double__EstRateOrcY : float, double__EstRateOrcZ : float, double__EstRateIrcX : float, double__EstRateIrcY : float, double__EstRateIrcZ : float, float__EstGyrTorqueX : float, float__EstGyrTorqueY : float, float__EstGyrTorqueZ : float, double__EstInnovX : float, double__EstInnovY : float, double__EstInnovZ : float, double__EstStdDevRateX : float, double__EstStdDevRateY : float, double__EstStdDevRateZ : float, double__EstStdDevQ0 : float, double__EstStdDevQ1 : float, double__EstStdDevQ2 : float, e__CubeComputerControlProgram8_EstModeSelect__EstModeActive : CubeComputerControlProgram8_EstModeSelect) -> None:
        """
        Struct 'TlmEstimatorBackup' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        double__EstRpyRoll [1] : float
            Estimated roll angle
        double__EstRpyPitch [1] : float
            Estimated pitch angle
        double__EstRpyYaw [1] : float
            Estimated yaw angle
        double__EstQuatQ0 [1] : float
            Estimated ORC quaternion Q0
        double__EstQuatQ1 [1] : float
            Estimated ORC quaternion Q1
        double__EstQuatQ2 [1] : float
            Estimated ORC quaternion Q2
        double__EstQuatQ3 [1] : float
            Estimated ORC quaternion Q3
        double__EstGyroBiasX [1] : float
            Estimated gyro bias X component
        double__EstGyroBiasY [1] : float
            Estimated gyro bias Y component
        double__EstGyroBiasZ [1] : float
            Estimated gyro bias Z component
        double__EstRateOrcX [1] : float
            Estimated body rate (ORC) X component
        double__EstRateOrcY [1] : float
            Estimated body rate (ORC) Y component
        double__EstRateOrcZ [1] : float
            Estimated body rate (ORC) Z component
        double__EstRateIrcX [1] : float
            Estimated body rate (IRC) X component
        double__EstRateIrcY [1] : float
            Estimated body rate (IRC) Y component
        double__EstRateIrcZ [1] : float
            Estimated body rate (IRC) Z component
        float__EstGyrTorqueX [1] : float
            Estimated gyroscopic torque X component
        float__EstGyrTorqueY [1] : float
            Estimated gyroscopic torque Y component
        float__EstGyrTorqueZ [1] : float
            Estimated gyroscopic torque Z component
        double__EstInnovX [1] : float
            Innovation vector X component
        double__EstInnovY [1] : float
            Innovation vector Y component
        double__EstInnovZ [1] : float
            Innovation vector Z component
        double__EstStdDevRateX [1] : float
            StdDev of estimated rate X component
        double__EstStdDevRateY [1] : float
            StdDev of estimated rate Y component
        double__EstStdDevRateZ [1] : float
            StdDev of estimated rate Z component
        double__EstStdDevQ0 [1] : float
            StdDev of estimated quaternion Q0 component
        double__EstStdDevQ1 [1] : float
            StdDev of estimated quaternion Q1 component
        double__EstStdDevQ2 [1] : float
            StdDev of estimated quaternion Q2 component
        e__CubeComputerControlProgram8_EstModeSelect__EstModeActive [1] : CubeComputerControlProgram8_EstModeSelect
            Active estimator mode
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmEstimatorBackup::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmEstimatorBackup::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_EstRpyRoll(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstRpyRoll' structure field
        
        Estimated roll angle
        """
        
        pass
    
    def get_EstRpyPitch(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstRpyPitch' structure field
        
        Estimated pitch angle
        """
        
        pass
    
    def get_EstRpyYaw(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstRpyYaw' structure field
        
        Estimated yaw angle
        """
        
        pass
    
    def get_EstQuatQ0(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstQuatQ0' structure field
        
        Estimated ORC quaternion Q0
        """
        
        pass
    
    def get_EstQuatQ1(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstQuatQ1' structure field
        
        Estimated ORC quaternion Q1
        """
        
        pass
    
    def get_EstQuatQ2(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstQuatQ2' structure field
        
        Estimated ORC quaternion Q2
        """
        
        pass
    
    def get_EstQuatQ3(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstQuatQ3' structure field
        
        Estimated ORC quaternion Q3
        """
        
        pass
    
    def get_EstGyroBiasX(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstGyroBiasX' structure field
        
        Estimated gyro bias X component
        """
        
        pass
    
    def get_EstGyroBiasY(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstGyroBiasY' structure field
        
        Estimated gyro bias Y component
        """
        
        pass
    
    def get_EstGyroBiasZ(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstGyroBiasZ' structure field
        
        Estimated gyro bias Z component
        """
        
        pass
    
    def get_EstRateOrcX(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstRateOrcX' structure field
        
        Estimated body rate (ORC) X component
        """
        
        pass
    
    def get_EstRateOrcY(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstRateOrcY' structure field
        
        Estimated body rate (ORC) Y component
        """
        
        pass
    
    def get_EstRateOrcZ(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstRateOrcZ' structure field
        
        Estimated body rate (ORC) Z component
        """
        
        pass
    
    def get_EstRateIrcX(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstRateIrcX' structure field
        
        Estimated body rate (IRC) X component
        """
        
        pass
    
    def get_EstRateIrcY(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstRateIrcY' structure field
        
        Estimated body rate (IRC) Y component
        """
        
        pass
    
    def get_EstRateIrcZ(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstRateIrcZ' structure field
        
        Estimated body rate (IRC) Z component
        """
        
        pass
    
    def get_EstGyrTorqueX(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstGyrTorqueX' structure field
        
        Estimated gyroscopic torque X component
        """
        
        pass
    
    def get_EstGyrTorqueY(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstGyrTorqueY' structure field
        
        Estimated gyroscopic torque Y component
        """
        
        pass
    
    def get_EstGyrTorqueZ(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstGyrTorqueZ' structure field
        
        Estimated gyroscopic torque Z component
        """
        
        pass
    
    def get_EstInnovX(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstInnovX' structure field
        
        Innovation vector X component
        """
        
        pass
    
    def get_EstInnovY(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstInnovY' structure field
        
        Innovation vector Y component
        """
        
        pass
    
    def get_EstInnovZ(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstInnovZ' structure field
        
        Innovation vector Z component
        """
        
        pass
    
    def get_EstStdDevRateX(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstStdDevRateX' structure field
        
        StdDev of estimated rate X component
        """
        
        pass
    
    def get_EstStdDevRateY(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstStdDevRateY' structure field
        
        StdDev of estimated rate Y component
        """
        
        pass
    
    def get_EstStdDevRateZ(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstStdDevRateZ' structure field
        
        StdDev of estimated rate Z component
        """
        
        pass
    
    def get_EstStdDevQ0(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstStdDevQ0' structure field
        
        StdDev of estimated quaternion Q0 component
        """
        
        pass
    
    def get_EstStdDevQ1(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstStdDevQ1' structure field
        
        StdDev of estimated quaternion Q1 component
        """
        
        pass
    
    def get_EstStdDevQ2(self) -> float:
        """
        A getter for the 'TlmEstimatorBackup::EstStdDevQ2' structure field
        
        StdDev of estimated quaternion Q2 component
        """
        
        pass
    
    def get_EstModeActive(self) -> CubeComputerControlProgram8_EstModeSelect:
        """
        A getter for the 'TlmEstimatorBackup::EstModeActive' structure field
        
        Active estimator mode
        """
        
        pass

def TlmEstimatorBackup_make_from_buf(buf : bytes) -> TlmEstimatorBackup:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class EstMode:
    """
    A Python class to represent struct objects of type 'EstMode'
    
    Parameter structure for interface EstMode
    """

    def __init__(self, e__CubeComputerControlProgram8_EstModeSelect__EstModeMain : CubeComputerControlProgram8_EstModeSelect, e__CubeComputerControlProgram8_EstModeSelect__EstModeBackup : CubeComputerControlProgram8_EstModeSelect) -> None:
        """
        Struct 'EstMode' constructor
        
        Attributes
        ---------
        e__CubeComputerControlProgram8_EstModeSelect__EstModeMain [1] : CubeComputerControlProgram8_EstModeSelect
            Main estimator mode
        e__CubeComputerControlProgram8_EstModeSelect__EstModeBackup [1] : CubeComputerControlProgram8_EstModeSelect
            Backup estimator mode
        """
        
        pass
        
    def get_EstModeMain(self) -> CubeComputerControlProgram8_EstModeSelect:
        """
        A getter for the 'EstMode::EstModeMain' structure field
        
        Main estimator mode
        """
        
        pass
    
    def get_EstModeBackup(self) -> CubeComputerControlProgram8_EstModeSelect:
        """
        A getter for the 'EstMode::EstModeBackup' structure field
        
        Backup estimator mode
        """
        
        pass

def EstMode_make_from_buf(buf : bytes) -> EstMode:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class CubeNodePortMap:
    """
    A Python class to represent struct objects of type 'CubeNodePortMap'
    
    Parameter structure for interface CubeNodePortMap
    """

    def __init__(self, e__CommonFrameworkTypes1_NodeType__NodeTypeSlot0 : CommonFrameworkTypes1_NodeType, uint32__SerialIntSlot0 : int, e__CubeComputerControlProgram8_CqAssign__Port1Slot0 : CubeComputerControlProgram8_CqAssign, e__CubeComputerControlProgram8_CqAssign__Port2Slot0 : CubeComputerControlProgram8_CqAssign, e__CubeComputerControlProgram8_CqAssign__Port3Slot0 : CubeComputerControlProgram8_CqAssign, e__CubeComputerControlProgram8_CqAssign__Port4Slot0 : CubeComputerControlProgram8_CqAssign, e__CommonFrameworkTypes1_NodeType__NodeTypeSlot1 : CommonFrameworkTypes1_NodeType, uint32__SerialIntSlot1 : int, e__CubeComputerControlProgram8_CqAssign__Port1Slot1 : CubeComputerControlProgram8_CqAssign, e__CubeComputerControlProgram8_CqAssign__Port2Slot1 : CubeComputerControlProgram8_CqAssign, e__CubeComputerControlProgram8_CqAssign__Port3Slot1 : CubeComputerControlProgram8_CqAssign, e__CubeComputerControlProgram8_CqAssign__Port4Slot1 : CubeComputerControlProgram8_CqAssign, e__CommonFrameworkTypes1_NodeType__NodeTypeSlot2 : CommonFrameworkTypes1_NodeType, uint32__SerialIntSlot2 : int, e__CubeComputerControlProgram8_CqAssign__Port1Slot2 : CubeComputerControlProgram8_CqAssign, e__CubeComputerControlProgram8_CqAssign__Port2Slot2 : CubeComputerControlProgram8_CqAssign, e__CubeComputerControlProgram8_CqAssign__Port3Slot2 : CubeComputerControlProgram8_CqAssign, e__CubeComputerControlProgram8_CqAssign__Port4Slot2 : CubeComputerControlProgram8_CqAssign, e__CommonFrameworkTypes1_NodeType__NodeTypeSlot3 : CommonFrameworkTypes1_NodeType, uint32__SerialIntSlot3 : int, e__CubeComputerControlProgram8_CqAssign__Port1Slot3 : CubeComputerControlProgram8_CqAssign, e__CubeComputerControlProgram8_CqAssign__Port2Slot3 : CubeComputerControlProgram8_CqAssign, e__CubeComputerControlProgram8_CqAssign__Port3Slot3 : CubeComputerControlProgram8_CqAssign, e__CubeComputerControlProgram8_CqAssign__Port4Slot3 : CubeComputerControlProgram8_CqAssign) -> None:
        """
        Struct 'CubeNodePortMap' constructor
        
        Attributes
        ---------
        e__CommonFrameworkTypes1_NodeType__NodeTypeSlot0 [1] : CommonFrameworkTypes1_NodeType
            CubeNode-Quad node type for this port map (CQ0)
        uint32__SerialIntSlot0 [1] : int
            CubeNode-Quad serial number integer for this port map (CQ0)
        e__CubeComputerControlProgram8_CqAssign__Port1Slot0 [1] : CubeComputerControlProgram8_CqAssign
            Abstract type assignment on port 1 of this CubeNode-Quad (CQ0)
        e__CubeComputerControlProgram8_CqAssign__Port2Slot0 [1] : CubeComputerControlProgram8_CqAssign
            Abstract type assignment on port 2 of this CubeNode-Quad (CQ0)
        e__CubeComputerControlProgram8_CqAssign__Port3Slot0 [1] : CubeComputerControlProgram8_CqAssign
            Abstract type assignment on port 3 of this CubeNode-Quad (CQ0)
        e__CubeComputerControlProgram8_CqAssign__Port4Slot0 [1] : CubeComputerControlProgram8_CqAssign
            Abstract type assignment on port 4 of this CubeNode-Quad (CQ0)
        e__CommonFrameworkTypes1_NodeType__NodeTypeSlot1 [1] : CommonFrameworkTypes1_NodeType
            CubeNode-Quad node type for this port map (CQ1)
        uint32__SerialIntSlot1 [1] : int
            CubeNode-Quad serial number integer for this port map (CQ1)
        e__CubeComputerControlProgram8_CqAssign__Port1Slot1 [1] : CubeComputerControlProgram8_CqAssign
            Abstract type assignment on port 1 of this CubeNode-Quad (CQ1)
        e__CubeComputerControlProgram8_CqAssign__Port2Slot1 [1] : CubeComputerControlProgram8_CqAssign
            Abstract type assignment on port 2 of this CubeNode-Quad (CQ1)
        e__CubeComputerControlProgram8_CqAssign__Port3Slot1 [1] : CubeComputerControlProgram8_CqAssign
            Abstract type assignment on port 3 of this CubeNode-Quad (CQ1)
        e__CubeComputerControlProgram8_CqAssign__Port4Slot1 [1] : CubeComputerControlProgram8_CqAssign
            Abstract type assignment on port 4 of this CubeNode-Quad (CQ1)
        e__CommonFrameworkTypes1_NodeType__NodeTypeSlot2 [1] : CommonFrameworkTypes1_NodeType
            CubeNode-Quad node type for this port map (CQ2)
        uint32__SerialIntSlot2 [1] : int
            CubeNode-Quad serial number integer for this port map (CQ2)
        e__CubeComputerControlProgram8_CqAssign__Port1Slot2 [1] : CubeComputerControlProgram8_CqAssign
            Abstract type assignment on port 1 of this CubeNode-Quad (CQ2)
        e__CubeComputerControlProgram8_CqAssign__Port2Slot2 [1] : CubeComputerControlProgram8_CqAssign
            Abstract type assignment on port 2 of this CubeNode-Quad (CQ2)
        e__CubeComputerControlProgram8_CqAssign__Port3Slot2 [1] : CubeComputerControlProgram8_CqAssign
            Abstract type assignment on port 3 of this CubeNode-Quad (CQ2)
        e__CubeComputerControlProgram8_CqAssign__Port4Slot2 [1] : CubeComputerControlProgram8_CqAssign
            Abstract type assignment on port 4 of this CubeNode-Quad (CQ2)
        e__CommonFrameworkTypes1_NodeType__NodeTypeSlot3 [1] : CommonFrameworkTypes1_NodeType
            CubeNode-Quad node type for this port map (CQ3)
        uint32__SerialIntSlot3 [1] : int
            CubeNode-Quad serial number integer for this port map (CQ3)
        e__CubeComputerControlProgram8_CqAssign__Port1Slot3 [1] : CubeComputerControlProgram8_CqAssign
            Abstract type assignment on port 1 of this CubeNode-Quad (CQ3)
        e__CubeComputerControlProgram8_CqAssign__Port2Slot3 [1] : CubeComputerControlProgram8_CqAssign
            Abstract type assignment on port 2 of this CubeNode-Quad (CQ3)
        e__CubeComputerControlProgram8_CqAssign__Port3Slot3 [1] : CubeComputerControlProgram8_CqAssign
            Abstract type assignment on port 3 of this CubeNode-Quad (CQ3)
        e__CubeComputerControlProgram8_CqAssign__Port4Slot3 [1] : CubeComputerControlProgram8_CqAssign
            Abstract type assignment on port 4 of this CubeNode-Quad (CQ3)
        """
        
        pass
        
    def get_NodeTypeSlot0(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'CubeNodePortMap::NodeTypeSlot0' structure field
        
        CubeNode-Quad node type for this port map (CQ0)
        """
        
        pass
    
    def get_SerialIntSlot0(self) -> int:
        """
        A getter for the 'CubeNodePortMap::SerialIntSlot0' structure field
        
        CubeNode-Quad serial number integer for this port map (CQ0)
        """
        
        pass
    
    def get_Port1Slot0(self) -> CubeComputerControlProgram8_CqAssign:
        """
        A getter for the 'CubeNodePortMap::Port1Slot0' structure field
        
        Abstract type assignment on port 1 of this CubeNode-Quad (CQ0)
        """
        
        pass
    
    def get_Port2Slot0(self) -> CubeComputerControlProgram8_CqAssign:
        """
        A getter for the 'CubeNodePortMap::Port2Slot0' structure field
        
        Abstract type assignment on port 2 of this CubeNode-Quad (CQ0)
        """
        
        pass
    
    def get_Port3Slot0(self) -> CubeComputerControlProgram8_CqAssign:
        """
        A getter for the 'CubeNodePortMap::Port3Slot0' structure field
        
        Abstract type assignment on port 3 of this CubeNode-Quad (CQ0)
        """
        
        pass
    
    def get_Port4Slot0(self) -> CubeComputerControlProgram8_CqAssign:
        """
        A getter for the 'CubeNodePortMap::Port4Slot0' structure field
        
        Abstract type assignment on port 4 of this CubeNode-Quad (CQ0)
        """
        
        pass
    
    def get_NodeTypeSlot1(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'CubeNodePortMap::NodeTypeSlot1' structure field
        
        CubeNode-Quad node type for this port map (CQ1)
        """
        
        pass
    
    def get_SerialIntSlot1(self) -> int:
        """
        A getter for the 'CubeNodePortMap::SerialIntSlot1' structure field
        
        CubeNode-Quad serial number integer for this port map (CQ1)
        """
        
        pass
    
    def get_Port1Slot1(self) -> CubeComputerControlProgram8_CqAssign:
        """
        A getter for the 'CubeNodePortMap::Port1Slot1' structure field
        
        Abstract type assignment on port 1 of this CubeNode-Quad (CQ1)
        """
        
        pass
    
    def get_Port2Slot1(self) -> CubeComputerControlProgram8_CqAssign:
        """
        A getter for the 'CubeNodePortMap::Port2Slot1' structure field
        
        Abstract type assignment on port 2 of this CubeNode-Quad (CQ1)
        """
        
        pass
    
    def get_Port3Slot1(self) -> CubeComputerControlProgram8_CqAssign:
        """
        A getter for the 'CubeNodePortMap::Port3Slot1' structure field
        
        Abstract type assignment on port 3 of this CubeNode-Quad (CQ1)
        """
        
        pass
    
    def get_Port4Slot1(self) -> CubeComputerControlProgram8_CqAssign:
        """
        A getter for the 'CubeNodePortMap::Port4Slot1' structure field
        
        Abstract type assignment on port 4 of this CubeNode-Quad (CQ1)
        """
        
        pass
    
    def get_NodeTypeSlot2(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'CubeNodePortMap::NodeTypeSlot2' structure field
        
        CubeNode-Quad node type for this port map (CQ2)
        """
        
        pass
    
    def get_SerialIntSlot2(self) -> int:
        """
        A getter for the 'CubeNodePortMap::SerialIntSlot2' structure field
        
        CubeNode-Quad serial number integer for this port map (CQ2)
        """
        
        pass
    
    def get_Port1Slot2(self) -> CubeComputerControlProgram8_CqAssign:
        """
        A getter for the 'CubeNodePortMap::Port1Slot2' structure field
        
        Abstract type assignment on port 1 of this CubeNode-Quad (CQ2)
        """
        
        pass
    
    def get_Port2Slot2(self) -> CubeComputerControlProgram8_CqAssign:
        """
        A getter for the 'CubeNodePortMap::Port2Slot2' structure field
        
        Abstract type assignment on port 2 of this CubeNode-Quad (CQ2)
        """
        
        pass
    
    def get_Port3Slot2(self) -> CubeComputerControlProgram8_CqAssign:
        """
        A getter for the 'CubeNodePortMap::Port3Slot2' structure field
        
        Abstract type assignment on port 3 of this CubeNode-Quad (CQ2)
        """
        
        pass
    
    def get_Port4Slot2(self) -> CubeComputerControlProgram8_CqAssign:
        """
        A getter for the 'CubeNodePortMap::Port4Slot2' structure field
        
        Abstract type assignment on port 4 of this CubeNode-Quad (CQ2)
        """
        
        pass
    
    def get_NodeTypeSlot3(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'CubeNodePortMap::NodeTypeSlot3' structure field
        
        CubeNode-Quad node type for this port map (CQ3)
        """
        
        pass
    
    def get_SerialIntSlot3(self) -> int:
        """
        A getter for the 'CubeNodePortMap::SerialIntSlot3' structure field
        
        CubeNode-Quad serial number integer for this port map (CQ3)
        """
        
        pass
    
    def get_Port1Slot3(self) -> CubeComputerControlProgram8_CqAssign:
        """
        A getter for the 'CubeNodePortMap::Port1Slot3' structure field
        
        Abstract type assignment on port 1 of this CubeNode-Quad (CQ3)
        """
        
        pass
    
    def get_Port2Slot3(self) -> CubeComputerControlProgram8_CqAssign:
        """
        A getter for the 'CubeNodePortMap::Port2Slot3' structure field
        
        Abstract type assignment on port 2 of this CubeNode-Quad (CQ3)
        """
        
        pass
    
    def get_Port3Slot3(self) -> CubeComputerControlProgram8_CqAssign:
        """
        A getter for the 'CubeNodePortMap::Port3Slot3' structure field
        
        Abstract type assignment on port 3 of this CubeNode-Quad (CQ3)
        """
        
        pass
    
    def get_Port4Slot3(self) -> CubeComputerControlProgram8_CqAssign:
        """
        A getter for the 'CubeNodePortMap::Port4Slot3' structure field
        
        Abstract type assignment on port 4 of this CubeNode-Quad (CQ3)
        """
        
        pass

def CubeNodePortMap_make_from_buf(buf : bytes) -> CubeNodePortMap:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class FileTransferStatus:
    """
    A Python class to represent struct objects of type 'FileTransferStatus'
    
    Parameter structure for interface FileTransferStatus
    """

    def __init__(self, e__CubeComputerControlProgram8_FtpState__State : CubeComputerControlProgram8_FtpState, e__CubeComputerControlProgram8_FtpUpgradeState__UpgradeState : CubeComputerControlProgram8_FtpUpgradeState, uint32__DataRemain : int, uint32__ErrorCode : int, bool__BusyError : int, bool__FileMetaError : int, bool__VersionError : int, bool__NodeExistError : int, bool__NodeExpectError : int, bool__FileCrcError : int, bool__FileSizeError : int, bool__FileError : int, bool__FileInvalidError : int, bool__FileFullError : int, bool__FileEmptyError : int, bool__ReadError : int, bool__WriteError : int, bool__EraseError : int, bool__FrameSizeError : int, bool__TimeoutError : int, bool__NodeCommsError : int, bool__NodeUsedError : int) -> None:
        """
        Struct 'FileTransferStatus' constructor
        
        Attributes
        ---------
        e__CubeComputerControlProgram8_FtpState__State [1] : CubeComputerControlProgram8_FtpState
            FTP Global State
        e__CubeComputerControlProgram8_FtpUpgradeState__UpgradeState [1] : CubeComputerControlProgram8_FtpUpgradeState
            FTP Internal Upgrade State
        uint32__DataRemain [1] : int
            Amount of remaining data to transfer
        uint32__ErrorCode [1] : int
            Operation Error Code. Non-Zero = ERROR
        bool__BusyError [1] : int
            Bootloader is busy
        bool__FileMetaError [1] : int
            File Metadata received is invalid
        bool__VersionError [1] : int
            File version is incompatible
        bool__NodeExistError [1] : int
            Target node does not exist
        bool__NodeExpectError [1] : int
            Target node is not expected
        bool__FileCrcError [1] : int
            File CRC Error Flag
        bool__FileSizeError [1] : int
            File is too large
        bool__FileError [1] : int
            File Error Flag (open/close)
        bool__FileInvalidError [1] : int
            File Invalid Error Flag
        bool__FileFullError [1] : int
            File Full Error Flag
        bool__FileEmptyError [1] : int
            File Empty Error Flag
        bool__ReadError [1] : int
            Read Error Flag
        bool__WriteError [1] : int
            Write Error Flag
        bool__EraseError [1] : int
            Erase Error Flag
        bool__FrameSizeError [1] : int
            Frame Size Error Flag
        bool__TimeoutError [1] : int
            Timeout Error Flag
        bool__NodeCommsError [1] : int
            Node comms fails during upgrade
        bool__NodeUsedError [1] : int
            Node is required for control
        """
        
        pass
        
    def get_State(self) -> CubeComputerControlProgram8_FtpState:
        """
        A getter for the 'FileTransferStatus::State' structure field
        
        FTP Global State
        """
        
        pass
    
    def get_UpgradeState(self) -> CubeComputerControlProgram8_FtpUpgradeState:
        """
        A getter for the 'FileTransferStatus::UpgradeState' structure field
        
        FTP Internal Upgrade State
        """
        
        pass
    
    def get_DataRemain(self) -> int:
        """
        A getter for the 'FileTransferStatus::DataRemain' structure field
        
        Amount of remaining data to transfer
        """
        
        pass
    
    def get_ErrorCode(self) -> int:
        """
        A getter for the 'FileTransferStatus::ErrorCode' structure field
        
        Operation Error Code. Non-Zero = ERROR
        """
        
        pass
    
    def get_BusyError(self) -> int:
        """
        A getter for the 'FileTransferStatus::BusyError' structure field
        
        Bootloader is busy
        """
        
        pass
    
    def get_FileMetaError(self) -> int:
        """
        A getter for the 'FileTransferStatus::FileMetaError' structure field
        
        File Metadata received is invalid
        """
        
        pass
    
    def get_VersionError(self) -> int:
        """
        A getter for the 'FileTransferStatus::VersionError' structure field
        
        File version is incompatible
        """
        
        pass
    
    def get_NodeExistError(self) -> int:
        """
        A getter for the 'FileTransferStatus::NodeExistError' structure field
        
        Target node does not exist
        """
        
        pass
    
    def get_NodeExpectError(self) -> int:
        """
        A getter for the 'FileTransferStatus::NodeExpectError' structure field
        
        Target node is not expected
        """
        
        pass
    
    def get_FileCrcError(self) -> int:
        """
        A getter for the 'FileTransferStatus::FileCrcError' structure field
        
        File CRC Error Flag
        """
        
        pass
    
    def get_FileSizeError(self) -> int:
        """
        A getter for the 'FileTransferStatus::FileSizeError' structure field
        
        File is too large
        """
        
        pass
    
    def get_FileError(self) -> int:
        """
        A getter for the 'FileTransferStatus::FileError' structure field
        
        File Error Flag (open/close)
        """
        
        pass
    
    def get_FileInvalidError(self) -> int:
        """
        A getter for the 'FileTransferStatus::FileInvalidError' structure field
        
        File Invalid Error Flag
        """
        
        pass
    
    def get_FileFullError(self) -> int:
        """
        A getter for the 'FileTransferStatus::FileFullError' structure field
        
        File Full Error Flag
        """
        
        pass
    
    def get_FileEmptyError(self) -> int:
        """
        A getter for the 'FileTransferStatus::FileEmptyError' structure field
        
        File Empty Error Flag
        """
        
        pass
    
    def get_ReadError(self) -> int:
        """
        A getter for the 'FileTransferStatus::ReadError' structure field
        
        Read Error Flag
        """
        
        pass
    
    def get_WriteError(self) -> int:
        """
        A getter for the 'FileTransferStatus::WriteError' structure field
        
        Write Error Flag
        """
        
        pass
    
    def get_EraseError(self) -> int:
        """
        A getter for the 'FileTransferStatus::EraseError' structure field
        
        Erase Error Flag
        """
        
        pass
    
    def get_FrameSizeError(self) -> int:
        """
        A getter for the 'FileTransferStatus::FrameSizeError' structure field
        
        Frame Size Error Flag
        """
        
        pass
    
    def get_TimeoutError(self) -> int:
        """
        A getter for the 'FileTransferStatus::TimeoutError' structure field
        
        Timeout Error Flag
        """
        
        pass
    
    def get_NodeCommsError(self) -> int:
        """
        A getter for the 'FileTransferStatus::NodeCommsError' structure field
        
        Node comms fails during upgrade
        """
        
        pass
    
    def get_NodeUsedError(self) -> int:
        """
        A getter for the 'FileTransferStatus::NodeUsedError' structure field
        
        Node is required for control
        """
        
        pass

def FileTransferStatus_make_from_buf(buf : bytes) -> FileTransferStatus:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmFssCubeSenseSunRaw:
    """
    A Python class to represent struct objects of type 'TlmFssCubeSenseSunRaw'
    
    Parameter structure for interface TlmFssCubeSenseSunRaw
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, double__Fss0Alpha : float, double__Fss0Beta : float, e__CubeComputerControlProgram8_SunCaptureResult__Fss0CaptureResult : CubeComputerControlProgram8_SunCaptureResult, e__CubeComputerControlProgram8_SunDetectResult__Fss0DetectionResult : CubeComputerControlProgram8_SunDetectResult, double__Fss1Alpha : float, double__Fss1Beta : float, e__CubeComputerControlProgram8_SunCaptureResult__Fss1CaptureResult : CubeComputerControlProgram8_SunCaptureResult, e__CubeComputerControlProgram8_SunDetectResult__Fss1DetectionResult : CubeComputerControlProgram8_SunDetectResult, double__Fss2Alpha : float, double__Fss2Beta : float, e__CubeComputerControlProgram8_SunCaptureResult__Fss2CaptureResult : CubeComputerControlProgram8_SunCaptureResult, e__CubeComputerControlProgram8_SunDetectResult__Fss2DetectionResult : CubeComputerControlProgram8_SunDetectResult, double__Fss3Alpha : float, double__Fss3Beta : float, e__CubeComputerControlProgram8_SunCaptureResult__Fss3CaptureResult : CubeComputerControlProgram8_SunCaptureResult, e__CubeComputerControlProgram8_SunDetectResult__Fss3DetectionResult : CubeComputerControlProgram8_SunDetectResult, bool__Fss0IsValid : int, bool__Fss1IsValid : int, bool__Fss2IsValid : int, bool__Fss3IsValid : int) -> None:
        """
        Struct 'TlmFssCubeSenseSunRaw' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        double__Fss0Alpha [1] : float
            FSS0 alpha Angle
        double__Fss0Beta [1] : float
            FSS0 beta Angle
        e__CubeComputerControlProgram8_SunCaptureResult__Fss0CaptureResult [1] : CubeComputerControlProgram8_SunCaptureResult
            FSS0 capture result
        e__CubeComputerControlProgram8_SunDetectResult__Fss0DetectionResult [1] : CubeComputerControlProgram8_SunDetectResult
            FSS0 detection result
        double__Fss1Alpha [1] : float
            FSS1 alpha Angle
        double__Fss1Beta [1] : float
            FSS1 beta Angle
        e__CubeComputerControlProgram8_SunCaptureResult__Fss1CaptureResult [1] : CubeComputerControlProgram8_SunCaptureResult
            FSS1 capture result
        e__CubeComputerControlProgram8_SunDetectResult__Fss1DetectionResult [1] : CubeComputerControlProgram8_SunDetectResult
            FSS1 detection result
        double__Fss2Alpha [1] : float
            FSS2 alpha Angle
        double__Fss2Beta [1] : float
            FSS2 beta Angle
        e__CubeComputerControlProgram8_SunCaptureResult__Fss2CaptureResult [1] : CubeComputerControlProgram8_SunCaptureResult
            FSS2 capture result
        e__CubeComputerControlProgram8_SunDetectResult__Fss2DetectionResult [1] : CubeComputerControlProgram8_SunDetectResult
            FSS2 detection result
        double__Fss3Alpha [1] : float
            FSS3 alpha Angle
        double__Fss3Beta [1] : float
            FSS3 beta Angle
        e__CubeComputerControlProgram8_SunCaptureResult__Fss3CaptureResult [1] : CubeComputerControlProgram8_SunCaptureResult
            FSS3 capture result
        e__CubeComputerControlProgram8_SunDetectResult__Fss3DetectionResult [1] : CubeComputerControlProgram8_SunDetectResult
            FSS3 detection result
        bool__Fss0IsValid [1] : int
            FSS0 valid flag
        bool__Fss1IsValid [1] : int
            FSS1 valid flag
        bool__Fss2IsValid [1] : int
            FSS2 valid flag
        bool__Fss3IsValid [1] : int
            FSS3 valid flag
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_Fss0Alpha(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss0Alpha' structure field
        
        FSS0 alpha Angle
        """
        
        pass
    
    def get_Fss0Beta(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss0Beta' structure field
        
        FSS0 beta Angle
        """
        
        pass
    
    def get_Fss0CaptureResult(self) -> CubeComputerControlProgram8_SunCaptureResult:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss0CaptureResult' structure field
        
        FSS0 capture result
        """
        
        pass
    
    def get_Fss0DetectionResult(self) -> CubeComputerControlProgram8_SunDetectResult:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss0DetectionResult' structure field
        
        FSS0 detection result
        """
        
        pass
    
    def get_Fss1Alpha(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss1Alpha' structure field
        
        FSS1 alpha Angle
        """
        
        pass
    
    def get_Fss1Beta(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss1Beta' structure field
        
        FSS1 beta Angle
        """
        
        pass
    
    def get_Fss1CaptureResult(self) -> CubeComputerControlProgram8_SunCaptureResult:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss1CaptureResult' structure field
        
        FSS1 capture result
        """
        
        pass
    
    def get_Fss1DetectionResult(self) -> CubeComputerControlProgram8_SunDetectResult:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss1DetectionResult' structure field
        
        FSS1 detection result
        """
        
        pass
    
    def get_Fss2Alpha(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss2Alpha' structure field
        
        FSS2 alpha Angle
        """
        
        pass
    
    def get_Fss2Beta(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss2Beta' structure field
        
        FSS2 beta Angle
        """
        
        pass
    
    def get_Fss2CaptureResult(self) -> CubeComputerControlProgram8_SunCaptureResult:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss2CaptureResult' structure field
        
        FSS2 capture result
        """
        
        pass
    
    def get_Fss2DetectionResult(self) -> CubeComputerControlProgram8_SunDetectResult:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss2DetectionResult' structure field
        
        FSS2 detection result
        """
        
        pass
    
    def get_Fss3Alpha(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss3Alpha' structure field
        
        FSS3 alpha Angle
        """
        
        pass
    
    def get_Fss3Beta(self) -> float:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss3Beta' structure field
        
        FSS3 beta Angle
        """
        
        pass
    
    def get_Fss3CaptureResult(self) -> CubeComputerControlProgram8_SunCaptureResult:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss3CaptureResult' structure field
        
        FSS3 capture result
        """
        
        pass
    
    def get_Fss3DetectionResult(self) -> CubeComputerControlProgram8_SunDetectResult:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss3DetectionResult' structure field
        
        FSS3 detection result
        """
        
        pass
    
    def get_Fss0IsValid(self) -> int:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss0IsValid' structure field
        
        FSS0 valid flag
        """
        
        pass
    
    def get_Fss1IsValid(self) -> int:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss1IsValid' structure field
        
        FSS1 valid flag
        """
        
        pass
    
    def get_Fss2IsValid(self) -> int:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss2IsValid' structure field
        
        FSS2 valid flag
        """
        
        pass
    
    def get_Fss3IsValid(self) -> int:
        """
        A getter for the 'TlmFssCubeSenseSunRaw::Fss3IsValid' structure field
        
        FSS3 valid flag
        """
        
        pass

def TlmFssCubeSenseSunRaw_make_from_buf(buf : bytes) -> TlmFssCubeSenseSunRaw:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ConfigActuatorRwl:
    """
    A Python class to represent struct objects of type 'ConfigActuatorRwl'
    
    Parameter structure for interface ConfigActuatorRwl
    """

    def __init__(self, float__Rwl0Iw : float, float__Rwl0Hmax : float, float__Rwl0Nmax : float, float__Rwl1Iw : float, float__Rwl1Hmax : float, float__Rwl1Nmax : float, float__Rwl2Iw : float, float__Rwl2Hmax : float, float__Rwl2Nmax : float, float__Rwl3Iw : float, float__Rwl3Hmax : float, float__Rwl3Nmax : float, float__NDel : float, e__CubeComputerControlProgram8_RwlScheme__RwlScheme : CubeComputerControlProgram8_RwlScheme, e__CubeComputerControlProgram8_RwlFailId__RwlFailId : CubeComputerControlProgram8_RwlFailId, float__PyrHnom : float, float__PyrTiltAngle : float) -> None:
        """
        Struct 'ConfigActuatorRwl' constructor
        
        Attributes
        ---------
        float__Rwl0Iw [1] : float
            RWL0 inertia
        float__Rwl0Hmax [1] : float
            RWL0 maximum momentum
        float__Rwl0Nmax [1] : float
            RWL0 maximum torque
        float__Rwl1Iw [1] : float
            RWL1 inertia
        float__Rwl1Hmax [1] : float
            RWL1 maximum momentum
        float__Rwl1Nmax [1] : float
            RWL1 maximum torque
        float__Rwl2Iw [1] : float
            RWL2 inertia
        float__Rwl2Hmax [1] : float
            RWL2 maximum momentum
        float__Rwl2Nmax [1] : float
            RWL2 maximum torque
        float__Rwl3Iw [1] : float
            RWL3 inertia
        float__Rwl3Hmax [1] : float
            RWL3 maximum momentum
        float__Rwl3Nmax [1] : float
            RWL3 maximum torque
        float__NDel [1] : float
            Wheel ramp torque
        e__CubeComputerControlProgram8_RwlScheme__RwlScheme [1] : CubeComputerControlProgram8_RwlScheme
            Wheel scheme
        e__CubeComputerControlProgram8_RwlFailId__RwlFailId [1] : CubeComputerControlProgram8_RwlFailId
            Failed wheel ID
        float__PyrHnom [1] : float
            Pyramid nominal momentum
        float__PyrTiltAngle [1] : float
            Pyramid tilt angle
        """
        
        pass
        
    def get_Rwl0Iw(self) -> float:
        """
        A getter for the 'ConfigActuatorRwl::Rwl0Iw' structure field
        
        RWL0 inertia
        """
        
        pass
    
    def get_Rwl0Hmax(self) -> float:
        """
        A getter for the 'ConfigActuatorRwl::Rwl0Hmax' structure field
        
        RWL0 maximum momentum
        """
        
        pass
    
    def get_Rwl0Nmax(self) -> float:
        """
        A getter for the 'ConfigActuatorRwl::Rwl0Nmax' structure field
        
        RWL0 maximum torque
        """
        
        pass
    
    def get_Rwl1Iw(self) -> float:
        """
        A getter for the 'ConfigActuatorRwl::Rwl1Iw' structure field
        
        RWL1 inertia
        """
        
        pass
    
    def get_Rwl1Hmax(self) -> float:
        """
        A getter for the 'ConfigActuatorRwl::Rwl1Hmax' structure field
        
        RWL1 maximum momentum
        """
        
        pass
    
    def get_Rwl1Nmax(self) -> float:
        """
        A getter for the 'ConfigActuatorRwl::Rwl1Nmax' structure field
        
        RWL1 maximum torque
        """
        
        pass
    
    def get_Rwl2Iw(self) -> float:
        """
        A getter for the 'ConfigActuatorRwl::Rwl2Iw' structure field
        
        RWL2 inertia
        """
        
        pass
    
    def get_Rwl2Hmax(self) -> float:
        """
        A getter for the 'ConfigActuatorRwl::Rwl2Hmax' structure field
        
        RWL2 maximum momentum
        """
        
        pass
    
    def get_Rwl2Nmax(self) -> float:
        """
        A getter for the 'ConfigActuatorRwl::Rwl2Nmax' structure field
        
        RWL2 maximum torque
        """
        
        pass
    
    def get_Rwl3Iw(self) -> float:
        """
        A getter for the 'ConfigActuatorRwl::Rwl3Iw' structure field
        
        RWL3 inertia
        """
        
        pass
    
    def get_Rwl3Hmax(self) -> float:
        """
        A getter for the 'ConfigActuatorRwl::Rwl3Hmax' structure field
        
        RWL3 maximum momentum
        """
        
        pass
    
    def get_Rwl3Nmax(self) -> float:
        """
        A getter for the 'ConfigActuatorRwl::Rwl3Nmax' structure field
        
        RWL3 maximum torque
        """
        
        pass
    
    def get_NDel(self) -> float:
        """
        A getter for the 'ConfigActuatorRwl::NDel' structure field
        
        Wheel ramp torque
        """
        
        pass
    
    def get_RwlScheme(self) -> CubeComputerControlProgram8_RwlScheme:
        """
        A getter for the 'ConfigActuatorRwl::RwlScheme' structure field
        
        Wheel scheme
        """
        
        pass
    
    def get_RwlFailId(self) -> CubeComputerControlProgram8_RwlFailId:
        """
        A getter for the 'ConfigActuatorRwl::RwlFailId' structure field
        
        Failed wheel ID
        """
        
        pass
    
    def get_PyrHnom(self) -> float:
        """
        A getter for the 'ConfigActuatorRwl::PyrHnom' structure field
        
        Pyramid nominal momentum
        """
        
        pass
    
    def get_PyrTiltAngle(self) -> float:
        """
        A getter for the 'ConfigActuatorRwl::PyrTiltAngle' structure field
        
        Pyramid tilt angle
        """
        
        pass

def ConfigActuatorRwl_make_from_buf(buf : bytes) -> ConfigActuatorRwl:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmNodeInitState:
    """
    A Python class to represent struct objects of type 'TlmNodeInitState'
    
    Parameter structure for interface TlmNodeInitState
    """

    def __init__(self, e__CubeComputerControlProgram8_InitState__Rwl0State : CubeComputerControlProgram8_InitState, e__CubeComputerControlProgram8_InitState__Rwl1State : CubeComputerControlProgram8_InitState, e__CubeComputerControlProgram8_InitState__Rwl2State : CubeComputerControlProgram8_InitState, e__CubeComputerControlProgram8_InitState__Rwl3State : CubeComputerControlProgram8_InitState, e__CubeComputerControlProgram8_InitState__Mag0State : CubeComputerControlProgram8_InitState, e__CubeComputerControlProgram8_InitState__Mag1State : CubeComputerControlProgram8_InitState, e__CubeComputerControlProgram8_InitState__Gyro0State : CubeComputerControlProgram8_InitState, e__CubeComputerControlProgram8_InitState__Gyro1State : CubeComputerControlProgram8_InitState, e__CubeComputerControlProgram8_InitState__Fss0State : CubeComputerControlProgram8_InitState, e__CubeComputerControlProgram8_InitState__Fss1State : CubeComputerControlProgram8_InitState, e__CubeComputerControlProgram8_InitState__Fss2State : CubeComputerControlProgram8_InitState, e__CubeComputerControlProgram8_InitState__Fss3State : CubeComputerControlProgram8_InitState, e__CubeComputerControlProgram8_InitState__Hss0State : CubeComputerControlProgram8_InitState, e__CubeComputerControlProgram8_InitState__Hss1State : CubeComputerControlProgram8_InitState, e__CubeComputerControlProgram8_InitState__Str0State : CubeComputerControlProgram8_InitState, e__CubeComputerControlProgram8_InitState__Str1State : CubeComputerControlProgram8_InitState, e__CubeComputerControlProgram8_InitState__ExtSensor0State : CubeComputerControlProgram8_InitState, e__CubeComputerControlProgram8_InitState__ExtSensor1State : CubeComputerControlProgram8_InitState, e__CubeComputerControlProgram8_InitState__ExtGyro0State : CubeComputerControlProgram8_InitState, e__CubeComputerControlProgram8_InitState__ExtGyro1State : CubeComputerControlProgram8_InitState) -> None:
        """
        Struct 'TlmNodeInitState' constructor
        
        Attributes
        ---------
        e__CubeComputerControlProgram8_InitState__Rwl0State [1] : CubeComputerControlProgram8_InitState
            RWL0 init state
        e__CubeComputerControlProgram8_InitState__Rwl1State [1] : CubeComputerControlProgram8_InitState
            RWL1 init state
        e__CubeComputerControlProgram8_InitState__Rwl2State [1] : CubeComputerControlProgram8_InitState
            RWL2 init state
        e__CubeComputerControlProgram8_InitState__Rwl3State [1] : CubeComputerControlProgram8_InitState
            RWL3 init state
        e__CubeComputerControlProgram8_InitState__Mag0State [1] : CubeComputerControlProgram8_InitState
            MAG0 init state
        e__CubeComputerControlProgram8_InitState__Mag1State [1] : CubeComputerControlProgram8_InitState
            MAG1 init state
        e__CubeComputerControlProgram8_InitState__Gyro0State [1] : CubeComputerControlProgram8_InitState
            GYR0 init state
        e__CubeComputerControlProgram8_InitState__Gyro1State [1] : CubeComputerControlProgram8_InitState
            GYR1 init state
        e__CubeComputerControlProgram8_InitState__Fss0State [1] : CubeComputerControlProgram8_InitState
            FSS0 init state
        e__CubeComputerControlProgram8_InitState__Fss1State [1] : CubeComputerControlProgram8_InitState
            FSS1 init state
        e__CubeComputerControlProgram8_InitState__Fss2State [1] : CubeComputerControlProgram8_InitState
            FSS2 init state
        e__CubeComputerControlProgram8_InitState__Fss3State [1] : CubeComputerControlProgram8_InitState
            FSS3 init state
        e__CubeComputerControlProgram8_InitState__Hss0State [1] : CubeComputerControlProgram8_InitState
            HSS0 init state
        e__CubeComputerControlProgram8_InitState__Hss1State [1] : CubeComputerControlProgram8_InitState
            HSS1 init state
        e__CubeComputerControlProgram8_InitState__Str0State [1] : CubeComputerControlProgram8_InitState
            STR0 init state
        e__CubeComputerControlProgram8_InitState__Str1State [1] : CubeComputerControlProgram8_InitState
            STR1 init state
        e__CubeComputerControlProgram8_InitState__ExtSensor0State [1] : CubeComputerControlProgram8_InitState
            ExtSensor0 init state
        e__CubeComputerControlProgram8_InitState__ExtSensor1State [1] : CubeComputerControlProgram8_InitState
            ExtSensor1 init state
        e__CubeComputerControlProgram8_InitState__ExtGyro0State [1] : CubeComputerControlProgram8_InitState
            EXTGYR0 init state
        e__CubeComputerControlProgram8_InitState__ExtGyro1State [1] : CubeComputerControlProgram8_InitState
            EXTGYR1 init state
        """
        
        pass
        
    def get_Rwl0State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::Rwl0State' structure field
        
        RWL0 init state
        """
        
        pass
    
    def get_Rwl1State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::Rwl1State' structure field
        
        RWL1 init state
        """
        
        pass
    
    def get_Rwl2State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::Rwl2State' structure field
        
        RWL2 init state
        """
        
        pass
    
    def get_Rwl3State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::Rwl3State' structure field
        
        RWL3 init state
        """
        
        pass
    
    def get_Mag0State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::Mag0State' structure field
        
        MAG0 init state
        """
        
        pass
    
    def get_Mag1State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::Mag1State' structure field
        
        MAG1 init state
        """
        
        pass
    
    def get_Gyro0State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::Gyro0State' structure field
        
        GYR0 init state
        """
        
        pass
    
    def get_Gyro1State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::Gyro1State' structure field
        
        GYR1 init state
        """
        
        pass
    
    def get_Fss0State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::Fss0State' structure field
        
        FSS0 init state
        """
        
        pass
    
    def get_Fss1State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::Fss1State' structure field
        
        FSS1 init state
        """
        
        pass
    
    def get_Fss2State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::Fss2State' structure field
        
        FSS2 init state
        """
        
        pass
    
    def get_Fss3State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::Fss3State' structure field
        
        FSS3 init state
        """
        
        pass
    
    def get_Hss0State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::Hss0State' structure field
        
        HSS0 init state
        """
        
        pass
    
    def get_Hss1State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::Hss1State' structure field
        
        HSS1 init state
        """
        
        pass
    
    def get_Str0State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::Str0State' structure field
        
        STR0 init state
        """
        
        pass
    
    def get_Str1State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::Str1State' structure field
        
        STR1 init state
        """
        
        pass
    
    def get_ExtSensor0State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::ExtSensor0State' structure field
        
        ExtSensor0 init state
        """
        
        pass
    
    def get_ExtSensor1State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::ExtSensor1State' structure field
        
        ExtSensor1 init state
        """
        
        pass
    
    def get_ExtGyro0State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::ExtGyro0State' structure field
        
        EXTGYR0 init state
        """
        
        pass
    
    def get_ExtGyro1State(self) -> CubeComputerControlProgram8_InitState:
        """
        A getter for the 'TlmNodeInitState::ExtGyro1State' structure field
        
        EXTGYR1 init state
        """
        
        pass

def TlmNodeInitState_make_from_buf(buf : bytes) -> TlmNodeInitState:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmTorquerCurrents:
    """
    A Python class to represent struct objects of type 'TlmTorquerCurrents'
    
    Parameter structure for interface TlmTorquerCurrents
    """

    def __init__(self, float__Mtq1TotalCurrentPeakPos : float, float__Mtq1TotalCurrentAveragePos : float, float__Mtq1TotalCurrentPeakNeg : float, float__Mtq1TotalCurrentAverageNeg : float, float__Mtq2TotalCurrentPeakPos : float, float__Mtq2TotalCurrentAveragePos : float, float__Mtq2TotalCurrentPeakNeg : float, float__Mtq2TotalCurrentAverageNeg : float, float__Mtq3TotalCurrentPeakPos : float, float__Mtq3TotalCurrentAveragePos : float, float__Mtq3TotalCurrentPeakNeg : float, float__Mtq3TotalCurrentAverageNeg : float, e__CubeComputerControlProgram8_MtqPolarity__Mtq1Polarity : CubeComputerControlProgram8_MtqPolarity, e__CubeComputerControlProgram8_MtqPolarity__Mtq2Polarity : CubeComputerControlProgram8_MtqPolarity, e__CubeComputerControlProgram8_MtqPolarity__Mtq3Polarity : CubeComputerControlProgram8_MtqPolarity) -> None:
        """
        Struct 'TlmTorquerCurrents' constructor
        
        Attributes
        ---------
        float__Mtq1TotalCurrentPeakPos [1] : float
            Total magnetorquer 1 positive current peak (mA)
        float__Mtq1TotalCurrentAveragePos [1] : float
            Total magnetorquer 1 positive current average (mA)
        float__Mtq1TotalCurrentPeakNeg [1] : float
            Total magnetorquer 1 negative current peak (mA)
        float__Mtq1TotalCurrentAverageNeg [1] : float
            Total magnetorquer 1 negative current average (mA)
        float__Mtq2TotalCurrentPeakPos [1] : float
            Total magnetorquer 2 positive current peak (mA)
        float__Mtq2TotalCurrentAveragePos [1] : float
            Total magnetorquer 2 positive current average (mA)
        float__Mtq2TotalCurrentPeakNeg [1] : float
            Total magnetorquer 2 negative current peak (mA)
        float__Mtq2TotalCurrentAverageNeg [1] : float
            Total magnetorquer 2 negative current average (mA)
        float__Mtq3TotalCurrentPeakPos [1] : float
            Total magnetorquer 3 positive current peak (mA)
        float__Mtq3TotalCurrentAveragePos [1] : float
            Total magnetorquer 3 positive current average (mA)
        float__Mtq3TotalCurrentPeakNeg [1] : float
            Total magnetorquer 3 negative current peak (mA)
        float__Mtq3TotalCurrentAverageNeg [1] : float
            Total magnetorquer 3 negative current average (mA)
        e__CubeComputerControlProgram8_MtqPolarity__Mtq1Polarity [1] : CubeComputerControlProgram8_MtqPolarity
            The polarity of magnetorquer 1 on the last iteration
        e__CubeComputerControlProgram8_MtqPolarity__Mtq2Polarity [1] : CubeComputerControlProgram8_MtqPolarity
            The polarity of magnetorquer 2 on the last iteration
        e__CubeComputerControlProgram8_MtqPolarity__Mtq3Polarity [1] : CubeComputerControlProgram8_MtqPolarity
            The polarity of magnetorquer 3 on the last iteration
        """
        
        pass
        
    def get_Mtq1TotalCurrentPeakPos(self) -> float:
        """
        A getter for the 'TlmTorquerCurrents::Mtq1TotalCurrentPeakPos' structure field
        
        Total magnetorquer 1 positive current peak (mA)
        """
        
        pass
    
    def get_Mtq1TotalCurrentAveragePos(self) -> float:
        """
        A getter for the 'TlmTorquerCurrents::Mtq1TotalCurrentAveragePos' structure field
        
        Total magnetorquer 1 positive current average (mA)
        """
        
        pass
    
    def get_Mtq1TotalCurrentPeakNeg(self) -> float:
        """
        A getter for the 'TlmTorquerCurrents::Mtq1TotalCurrentPeakNeg' structure field
        
        Total magnetorquer 1 negative current peak (mA)
        """
        
        pass
    
    def get_Mtq1TotalCurrentAverageNeg(self) -> float:
        """
        A getter for the 'TlmTorquerCurrents::Mtq1TotalCurrentAverageNeg' structure field
        
        Total magnetorquer 1 negative current average (mA)
        """
        
        pass
    
    def get_Mtq2TotalCurrentPeakPos(self) -> float:
        """
        A getter for the 'TlmTorquerCurrents::Mtq2TotalCurrentPeakPos' structure field
        
        Total magnetorquer 2 positive current peak (mA)
        """
        
        pass
    
    def get_Mtq2TotalCurrentAveragePos(self) -> float:
        """
        A getter for the 'TlmTorquerCurrents::Mtq2TotalCurrentAveragePos' structure field
        
        Total magnetorquer 2 positive current average (mA)
        """
        
        pass
    
    def get_Mtq2TotalCurrentPeakNeg(self) -> float:
        """
        A getter for the 'TlmTorquerCurrents::Mtq2TotalCurrentPeakNeg' structure field
        
        Total magnetorquer 2 negative current peak (mA)
        """
        
        pass
    
    def get_Mtq2TotalCurrentAverageNeg(self) -> float:
        """
        A getter for the 'TlmTorquerCurrents::Mtq2TotalCurrentAverageNeg' structure field
        
        Total magnetorquer 2 negative current average (mA)
        """
        
        pass
    
    def get_Mtq3TotalCurrentPeakPos(self) -> float:
        """
        A getter for the 'TlmTorquerCurrents::Mtq3TotalCurrentPeakPos' structure field
        
        Total magnetorquer 3 positive current peak (mA)
        """
        
        pass
    
    def get_Mtq3TotalCurrentAveragePos(self) -> float:
        """
        A getter for the 'TlmTorquerCurrents::Mtq3TotalCurrentAveragePos' structure field
        
        Total magnetorquer 3 positive current average (mA)
        """
        
        pass
    
    def get_Mtq3TotalCurrentPeakNeg(self) -> float:
        """
        A getter for the 'TlmTorquerCurrents::Mtq3TotalCurrentPeakNeg' structure field
        
        Total magnetorquer 3 negative current peak (mA)
        """
        
        pass
    
    def get_Mtq3TotalCurrentAverageNeg(self) -> float:
        """
        A getter for the 'TlmTorquerCurrents::Mtq3TotalCurrentAverageNeg' structure field
        
        Total magnetorquer 3 negative current average (mA)
        """
        
        pass
    
    def get_Mtq1Polarity(self) -> CubeComputerControlProgram8_MtqPolarity:
        """
        A getter for the 'TlmTorquerCurrents::Mtq1Polarity' structure field
        
        The polarity of magnetorquer 1 on the last iteration
        """
        
        pass
    
    def get_Mtq2Polarity(self) -> CubeComputerControlProgram8_MtqPolarity:
        """
        A getter for the 'TlmTorquerCurrents::Mtq2Polarity' structure field
        
        The polarity of magnetorquer 2 on the last iteration
        """
        
        pass
    
    def get_Mtq3Polarity(self) -> CubeComputerControlProgram8_MtqPolarity:
        """
        A getter for the 'TlmTorquerCurrents::Mtq3Polarity' structure field
        
        The polarity of magnetorquer 3 on the last iteration
        """
        
        pass

def TlmTorquerCurrents_make_from_buf(buf : bytes) -> TlmTorquerCurrents:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ConfigAdcsEstimator:
    """
    A Python class to represent struct objects of type 'ConfigAdcsEstimator'
    
    Parameter structure for interface ConfigAdcsEstimator
    """

    def __init__(self, e__CubeComputerControlProgram8_EstModeSelect__EstModeMainDefault : CubeComputerControlProgram8_EstModeSelect, e__CubeComputerControlProgram8_EstModeSelect__EstModeBackupDefault : CubeComputerControlProgram8_EstModeSelect, float__MagR : float, float__CssR : float, float__FssR : float, float__HssR : float, float__StrR : float, float__RkfQ : float, float__EkfQ : float, float__NutDeps : float, float__NutDpsi : float, bool__EkfUseFss : int, bool__EkfUseCss : int, bool__EkfUseHss : int, bool__EkfUseStr : int, e__CubeComputerControlProgram8_VecSelect__TVec1 : CubeComputerControlProgram8_VecSelect, e__CubeComputerControlProgram8_VecSelect__TVec2 : CubeComputerControlProgram8_VecSelect) -> None:
        """
        Struct 'ConfigAdcsEstimator' constructor
        
        Attributes
        ---------
        e__CubeComputerControlProgram8_EstModeSelect__EstModeMainDefault [1] : CubeComputerControlProgram8_EstModeSelect
            Default main estimator mode
        e__CubeComputerControlProgram8_EstModeSelect__EstModeBackupDefault [1] : CubeComputerControlProgram8_EstModeSelect
            Default backup estimator mode
        float__MagR [1] : float
            Magnetometer measurement noise
        float__CssR [1] : float
            Coarse sun sensor measurement noise
        float__FssR [1] : float
            Fine sun sensor measurement noise
        float__HssR [1] : float
            Horizon sensor measurement noise
        float__StrR [1] : float
            Star tracker measurement noise
        float__RkfQ [1] : float
            Magnetometer RKF system noise
        float__EkfQ [1] : float
            EKF system noise
        float__NutDeps [1] : float
            Polar nutation Epsilon correction
        float__NutDpsi [1] : float
            Polar nutation Psi correction
        bool__EkfUseFss [1] : int
            Use fine sun sensor measurements in EKF
        bool__EkfUseCss [1] : int
            Use coarse sun sensor measurements in EKF
        bool__EkfUseHss [1] : int
            Use horizon sensor measurements in EKF
        bool__EkfUseStr [1] : int
            Use star tracker measurements in EKF
        e__CubeComputerControlProgram8_VecSelect__TVec1 [1] : CubeComputerControlProgram8_VecSelect
            Vector 1 selection for Triad
        e__CubeComputerControlProgram8_VecSelect__TVec2 [1] : CubeComputerControlProgram8_VecSelect
            Vector 2 selection for Triad
        """
        
        pass
        
    def get_EstModeMainDefault(self) -> CubeComputerControlProgram8_EstModeSelect:
        """
        A getter for the 'ConfigAdcsEstimator::EstModeMainDefault' structure field
        
        Default main estimator mode
        """
        
        pass
    
    def get_EstModeBackupDefault(self) -> CubeComputerControlProgram8_EstModeSelect:
        """
        A getter for the 'ConfigAdcsEstimator::EstModeBackupDefault' structure field
        
        Default backup estimator mode
        """
        
        pass
    
    def get_MagR(self) -> float:
        """
        A getter for the 'ConfigAdcsEstimator::MagR' structure field
        
        Magnetometer measurement noise
        """
        
        pass
    
    def get_CssR(self) -> float:
        """
        A getter for the 'ConfigAdcsEstimator::CssR' structure field
        
        Coarse sun sensor measurement noise
        """
        
        pass
    
    def get_FssR(self) -> float:
        """
        A getter for the 'ConfigAdcsEstimator::FssR' structure field
        
        Fine sun sensor measurement noise
        """
        
        pass
    
    def get_HssR(self) -> float:
        """
        A getter for the 'ConfigAdcsEstimator::HssR' structure field
        
        Horizon sensor measurement noise
        """
        
        pass
    
    def get_StrR(self) -> float:
        """
        A getter for the 'ConfigAdcsEstimator::StrR' structure field
        
        Star tracker measurement noise
        """
        
        pass
    
    def get_RkfQ(self) -> float:
        """
        A getter for the 'ConfigAdcsEstimator::RkfQ' structure field
        
        Magnetometer RKF system noise
        """
        
        pass
    
    def get_EkfQ(self) -> float:
        """
        A getter for the 'ConfigAdcsEstimator::EkfQ' structure field
        
        EKF system noise
        """
        
        pass
    
    def get_NutDeps(self) -> float:
        """
        A getter for the 'ConfigAdcsEstimator::NutDeps' structure field
        
        Polar nutation Epsilon correction
        """
        
        pass
    
    def get_NutDpsi(self) -> float:
        """
        A getter for the 'ConfigAdcsEstimator::NutDpsi' structure field
        
        Polar nutation Psi correction
        """
        
        pass
    
    def get_EkfUseFss(self) -> int:
        """
        A getter for the 'ConfigAdcsEstimator::EkfUseFss' structure field
        
        Use fine sun sensor measurements in EKF
        """
        
        pass
    
    def get_EkfUseCss(self) -> int:
        """
        A getter for the 'ConfigAdcsEstimator::EkfUseCss' structure field
        
        Use coarse sun sensor measurements in EKF
        """
        
        pass
    
    def get_EkfUseHss(self) -> int:
        """
        A getter for the 'ConfigAdcsEstimator::EkfUseHss' structure field
        
        Use horizon sensor measurements in EKF
        """
        
        pass
    
    def get_EkfUseStr(self) -> int:
        """
        A getter for the 'ConfigAdcsEstimator::EkfUseStr' structure field
        
        Use star tracker measurements in EKF
        """
        
        pass
    
    def get_TVec1(self) -> CubeComputerControlProgram8_VecSelect:
        """
        A getter for the 'ConfigAdcsEstimator::TVec1' structure field
        
        Vector 1 selection for Triad
        """
        
        pass
    
    def get_TVec2(self) -> CubeComputerControlProgram8_VecSelect:
        """
        A getter for the 'ConfigAdcsEstimator::TVec2' structure field
        
        Vector 2 selection for Triad
        """
        
        pass

def ConfigAdcsEstimator_make_from_buf(buf : bytes) -> ConfigAdcsEstimator:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ConfigMagSensingElement:
    """
    A Python class to represent struct objects of type 'ConfigMagSensingElement'
    
    Parameter structure for interface ConfigMagSensingElement
    """

    def __init__(self, e__CubeComputerControlProgram8_MagSensingElementSelect__Mag0SensingElement : CubeComputerControlProgram8_MagSensingElementSelect, e__CubeComputerControlProgram8_MagSensingElementSelect__Mag1SensingElement : CubeComputerControlProgram8_MagSensingElementSelect) -> None:
        """
        Struct 'ConfigMagSensingElement' constructor
        
        Attributes
        ---------
        e__CubeComputerControlProgram8_MagSensingElementSelect__Mag0SensingElement [1] : CubeComputerControlProgram8_MagSensingElementSelect
            MAG0 sensing element (primary/redundant)
        e__CubeComputerControlProgram8_MagSensingElementSelect__Mag1SensingElement [1] : CubeComputerControlProgram8_MagSensingElementSelect
            MAG1 sensing element (primary/redundant)
        """
        
        pass
        
    def get_Mag0SensingElement(self) -> CubeComputerControlProgram8_MagSensingElementSelect:
        """
        A getter for the 'ConfigMagSensingElement::Mag0SensingElement' structure field
        
        MAG0 sensing element (primary/redundant)
        """
        
        pass
    
    def get_Mag1SensingElement(self) -> CubeComputerControlProgram8_MagSensingElementSelect:
        """
        A getter for the 'ConfigMagSensingElement::Mag1SensingElement' structure field
        
        MAG1 sensing element (primary/redundant)
        """
        
        pass

def ConfigMagSensingElement_make_from_buf(buf : bytes) -> ConfigMagSensingElement:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ConfigMount:
    """
    A Python class to represent struct objects of type 'ConfigMount'
    
    Parameter structure for interface ConfigMount
    """

    def __init__(self, e__CubeComputerControlProgram8_AxisSelect__MountStackX : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountStackY : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountStackZ : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountMtq0 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountMtq1 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountMtq2 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountRwl0 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountRwl1 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountRwl2 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountRwl3 : CubeComputerControlProgram8_AxisSelect, double__MountRwlPyrAlpha : float, double__MountRwlPyrBeta : float, double__MountRwlPyrGamma : float, e__CubeComputerControlProgram8_AxisSelect__MountCss0 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountCss1 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountCss2 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountCss3 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountCss4 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountCss5 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountCss6 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountCss7 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountCss8 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountCss9 : CubeComputerControlProgram8_AxisSelect, double__MountFss0Alpha : float, double__MountFss0Beta : float, double__MountFss0Gamma : float, double__MountFss1Alpha : float, double__MountFss1Beta : float, double__MountFss1Gamma : float, double__MountFss2Alpha : float, double__MountFss2Beta : float, double__MountFss2Gamma : float, double__MountFss3Alpha : float, double__MountFss3Beta : float, double__MountFss3Gamma : float, double__MountHss0Alpha : float, double__MountHss0Beta : float, double__MountHss0Gamma : float, double__MountHss1Alpha : float, double__MountHss1Beta : float, double__MountHss1Gamma : float, double__MountMag0Alpha : float, double__MountMag0Beta : float, double__MountMag0Gamma : float, double__MountMag1Alpha : float, double__MountMag1Beta : float, double__MountMag1Gamma : float, double__MountStr0Alpha : float, double__MountStr0Beta : float, double__MountStr0Gamma : float, double__MountStr1Alpha : float, double__MountStr1Beta : float, double__MountStr1Gamma : float, double__MountExtSensor0Alpha : float, double__MountExtSensor0Beta : float, double__MountExtSensor0Gamma : float, double__MountExtSensor1Alpha : float, double__MountExtSensor1Beta : float, double__MountExtSensor1Gamma : float, e__CubeComputerControlProgram8_AxisSelect__MountExtGyr0Axis1 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountExtGyr0Axis2 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountExtGyr0Axis3 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountExtGyr1Axis1 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountExtGyr1Axis2 : CubeComputerControlProgram8_AxisSelect, e__CubeComputerControlProgram8_AxisSelect__MountExtGyr1Axis3 : CubeComputerControlProgram8_AxisSelect) -> None:
        """
        Struct 'ConfigMount' constructor
        
        Attributes
        ---------
        e__CubeComputerControlProgram8_AxisSelect__MountStackX [1] : CubeComputerControlProgram8_AxisSelect
            StackX mounting
        e__CubeComputerControlProgram8_AxisSelect__MountStackY [1] : CubeComputerControlProgram8_AxisSelect
            StackY mounting
        e__CubeComputerControlProgram8_AxisSelect__MountStackZ [1] : CubeComputerControlProgram8_AxisSelect
            StackZ mounting
        e__CubeComputerControlProgram8_AxisSelect__MountMtq0 [1] : CubeComputerControlProgram8_AxisSelect
            MTQ0 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountMtq1 [1] : CubeComputerControlProgram8_AxisSelect
            MTQ1 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountMtq2 [1] : CubeComputerControlProgram8_AxisSelect
            MTQ2 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountRwl0 [1] : CubeComputerControlProgram8_AxisSelect
            Wheel0 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountRwl1 [1] : CubeComputerControlProgram8_AxisSelect
            Wheel1 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountRwl2 [1] : CubeComputerControlProgram8_AxisSelect
            Wheel2 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountRwl3 [1] : CubeComputerControlProgram8_AxisSelect
            Wheel3 mounting
        double__MountRwlPyrAlpha [1] : float
            Pyramid RWL mounting alpha angle
        double__MountRwlPyrBeta [1] : float
            Pyramid RWL mounting beta angle
        double__MountRwlPyrGamma [1] : float
            Pyramid RWL mounting gamma angle
        e__CubeComputerControlProgram8_AxisSelect__MountCss0 [1] : CubeComputerControlProgram8_AxisSelect
            CSS0 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountCss1 [1] : CubeComputerControlProgram8_AxisSelect
            CSS1 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountCss2 [1] : CubeComputerControlProgram8_AxisSelect
            CSS2 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountCss3 [1] : CubeComputerControlProgram8_AxisSelect
            CSS3 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountCss4 [1] : CubeComputerControlProgram8_AxisSelect
            CSS4 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountCss5 [1] : CubeComputerControlProgram8_AxisSelect
            CSS5 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountCss6 [1] : CubeComputerControlProgram8_AxisSelect
            CSS6 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountCss7 [1] : CubeComputerControlProgram8_AxisSelect
            CSS7 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountCss8 [1] : CubeComputerControlProgram8_AxisSelect
            CSS8 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountCss9 [1] : CubeComputerControlProgram8_AxisSelect
            CSS9 mounting
        double__MountFss0Alpha [1] : float
            FSS0 mounting alpha angle
        double__MountFss0Beta [1] : float
            FSS0 mounting beta angle
        double__MountFss0Gamma [1] : float
            FSS0 mounting gamma angle
        double__MountFss1Alpha [1] : float
            FSS1 mounting alpha angle
        double__MountFss1Beta [1] : float
            FSS1 mounting beta angle
        double__MountFss1Gamma [1] : float
            FSS1 mounting gamma angle
        double__MountFss2Alpha [1] : float
            FSS2 mounting alpha angle
        double__MountFss2Beta [1] : float
            FSS2 mounting beta angle
        double__MountFss2Gamma [1] : float
            FSS2 mounting gamma angle
        double__MountFss3Alpha [1] : float
            FSS3 mounting alpha angle
        double__MountFss3Beta [1] : float
            FSS3 mounting beta angle
        double__MountFss3Gamma [1] : float
            FSS3 mounting gamma angle
        double__MountHss0Alpha [1] : float
            HSS0 mounting alpha angle
        double__MountHss0Beta [1] : float
            HSS0 mounting beta angle
        double__MountHss0Gamma [1] : float
            HSS0 mounting gamma angle
        double__MountHss1Alpha [1] : float
            HSS1 mounting alpha angle
        double__MountHss1Beta [1] : float
            HSS1 mounting beta angle
        double__MountHss1Gamma [1] : float
            HSS1 mounting gamma angle
        double__MountMag0Alpha [1] : float
            MAG0 mounting alpha angle
        double__MountMag0Beta [1] : float
            MAG0 mounting beta angle
        double__MountMag0Gamma [1] : float
            MAG0 mounting gamma angle
        double__MountMag1Alpha [1] : float
            MAG1 mounting alpha angle
        double__MountMag1Beta [1] : float
            MAG1 mounting beta angle
        double__MountMag1Gamma [1] : float
            MAG1 mounting gamma angle
        double__MountStr0Alpha [1] : float
            STR0 mounting alpha angle
        double__MountStr0Beta [1] : float
            STR0 mounting beta angle
        double__MountStr0Gamma [1] : float
            STR0 mounting gamma angle
        double__MountStr1Alpha [1] : float
            STR1 mounting alpha angle
        double__MountStr1Beta [1] : float
            STR1 mounting beta angle
        double__MountStr1Gamma [1] : float
            STR1 mounting gamma angle
        double__MountExtSensor0Alpha [1] : float
            ExtSensor0 mounting alpha angle
        double__MountExtSensor0Beta [1] : float
            ExtSensor0 mounting beta angle
        double__MountExtSensor0Gamma [1] : float
            ExtSensor0 mounting gamma angle
        double__MountExtSensor1Alpha [1] : float
            ExtSensor1 mounting alpha angle
        double__MountExtSensor1Beta [1] : float
            ExtSensor1 mounting beta angle
        double__MountExtSensor1Gamma [1] : float
            ExtSensor1 mounting gamma angle
        e__CubeComputerControlProgram8_AxisSelect__MountExtGyr0Axis1 [1] : CubeComputerControlProgram8_AxisSelect
            ExtGyro0 axis1 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountExtGyr0Axis2 [1] : CubeComputerControlProgram8_AxisSelect
            ExtGyro0 axis2 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountExtGyr0Axis3 [1] : CubeComputerControlProgram8_AxisSelect
            ExtGyro0 axis3 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountExtGyr1Axis1 [1] : CubeComputerControlProgram8_AxisSelect
            ExtGyro1 axis1 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountExtGyr1Axis2 [1] : CubeComputerControlProgram8_AxisSelect
            ExtGyro1 axis2 mounting
        e__CubeComputerControlProgram8_AxisSelect__MountExtGyr1Axis3 [1] : CubeComputerControlProgram8_AxisSelect
            ExtGyro1 axis3 mounting
        """
        
        pass
        
    def get_MountStackX(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountStackX' structure field
        
        StackX mounting
        """
        
        pass
    
    def get_MountStackY(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountStackY' structure field
        
        StackY mounting
        """
        
        pass
    
    def get_MountStackZ(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountStackZ' structure field
        
        StackZ mounting
        """
        
        pass
    
    def get_MountMtq0(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountMtq0' structure field
        
        MTQ0 mounting
        """
        
        pass
    
    def get_MountMtq1(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountMtq1' structure field
        
        MTQ1 mounting
        """
        
        pass
    
    def get_MountMtq2(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountMtq2' structure field
        
        MTQ2 mounting
        """
        
        pass
    
    def get_MountRwl0(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountRwl0' structure field
        
        Wheel0 mounting
        """
        
        pass
    
    def get_MountRwl1(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountRwl1' structure field
        
        Wheel1 mounting
        """
        
        pass
    
    def get_MountRwl2(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountRwl2' structure field
        
        Wheel2 mounting
        """
        
        pass
    
    def get_MountRwl3(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountRwl3' structure field
        
        Wheel3 mounting
        """
        
        pass
    
    def get_MountRwlPyrAlpha(self) -> float:
        """
        A getter for the 'ConfigMount::MountRwlPyrAlpha' structure field
        
        Pyramid RWL mounting alpha angle
        """
        
        pass
    
    def get_MountRwlPyrBeta(self) -> float:
        """
        A getter for the 'ConfigMount::MountRwlPyrBeta' structure field
        
        Pyramid RWL mounting beta angle
        """
        
        pass
    
    def get_MountRwlPyrGamma(self) -> float:
        """
        A getter for the 'ConfigMount::MountRwlPyrGamma' structure field
        
        Pyramid RWL mounting gamma angle
        """
        
        pass
    
    def get_MountCss0(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountCss0' structure field
        
        CSS0 mounting
        """
        
        pass
    
    def get_MountCss1(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountCss1' structure field
        
        CSS1 mounting
        """
        
        pass
    
    def get_MountCss2(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountCss2' structure field
        
        CSS2 mounting
        """
        
        pass
    
    def get_MountCss3(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountCss3' structure field
        
        CSS3 mounting
        """
        
        pass
    
    def get_MountCss4(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountCss4' structure field
        
        CSS4 mounting
        """
        
        pass
    
    def get_MountCss5(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountCss5' structure field
        
        CSS5 mounting
        """
        
        pass
    
    def get_MountCss6(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountCss6' structure field
        
        CSS6 mounting
        """
        
        pass
    
    def get_MountCss7(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountCss7' structure field
        
        CSS7 mounting
        """
        
        pass
    
    def get_MountCss8(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountCss8' structure field
        
        CSS8 mounting
        """
        
        pass
    
    def get_MountCss9(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountCss9' structure field
        
        CSS9 mounting
        """
        
        pass
    
    def get_MountFss0Alpha(self) -> float:
        """
        A getter for the 'ConfigMount::MountFss0Alpha' structure field
        
        FSS0 mounting alpha angle
        """
        
        pass
    
    def get_MountFss0Beta(self) -> float:
        """
        A getter for the 'ConfigMount::MountFss0Beta' structure field
        
        FSS0 mounting beta angle
        """
        
        pass
    
    def get_MountFss0Gamma(self) -> float:
        """
        A getter for the 'ConfigMount::MountFss0Gamma' structure field
        
        FSS0 mounting gamma angle
        """
        
        pass
    
    def get_MountFss1Alpha(self) -> float:
        """
        A getter for the 'ConfigMount::MountFss1Alpha' structure field
        
        FSS1 mounting alpha angle
        """
        
        pass
    
    def get_MountFss1Beta(self) -> float:
        """
        A getter for the 'ConfigMount::MountFss1Beta' structure field
        
        FSS1 mounting beta angle
        """
        
        pass
    
    def get_MountFss1Gamma(self) -> float:
        """
        A getter for the 'ConfigMount::MountFss1Gamma' structure field
        
        FSS1 mounting gamma angle
        """
        
        pass
    
    def get_MountFss2Alpha(self) -> float:
        """
        A getter for the 'ConfigMount::MountFss2Alpha' structure field
        
        FSS2 mounting alpha angle
        """
        
        pass
    
    def get_MountFss2Beta(self) -> float:
        """
        A getter for the 'ConfigMount::MountFss2Beta' structure field
        
        FSS2 mounting beta angle
        """
        
        pass
    
    def get_MountFss2Gamma(self) -> float:
        """
        A getter for the 'ConfigMount::MountFss2Gamma' structure field
        
        FSS2 mounting gamma angle
        """
        
        pass
    
    def get_MountFss3Alpha(self) -> float:
        """
        A getter for the 'ConfigMount::MountFss3Alpha' structure field
        
        FSS3 mounting alpha angle
        """
        
        pass
    
    def get_MountFss3Beta(self) -> float:
        """
        A getter for the 'ConfigMount::MountFss3Beta' structure field
        
        FSS3 mounting beta angle
        """
        
        pass
    
    def get_MountFss3Gamma(self) -> float:
        """
        A getter for the 'ConfigMount::MountFss3Gamma' structure field
        
        FSS3 mounting gamma angle
        """
        
        pass
    
    def get_MountHss0Alpha(self) -> float:
        """
        A getter for the 'ConfigMount::MountHss0Alpha' structure field
        
        HSS0 mounting alpha angle
        """
        
        pass
    
    def get_MountHss0Beta(self) -> float:
        """
        A getter for the 'ConfigMount::MountHss0Beta' structure field
        
        HSS0 mounting beta angle
        """
        
        pass
    
    def get_MountHss0Gamma(self) -> float:
        """
        A getter for the 'ConfigMount::MountHss0Gamma' structure field
        
        HSS0 mounting gamma angle
        """
        
        pass
    
    def get_MountHss1Alpha(self) -> float:
        """
        A getter for the 'ConfigMount::MountHss1Alpha' structure field
        
        HSS1 mounting alpha angle
        """
        
        pass
    
    def get_MountHss1Beta(self) -> float:
        """
        A getter for the 'ConfigMount::MountHss1Beta' structure field
        
        HSS1 mounting beta angle
        """
        
        pass
    
    def get_MountHss1Gamma(self) -> float:
        """
        A getter for the 'ConfigMount::MountHss1Gamma' structure field
        
        HSS1 mounting gamma angle
        """
        
        pass
    
    def get_MountMag0Alpha(self) -> float:
        """
        A getter for the 'ConfigMount::MountMag0Alpha' structure field
        
        MAG0 mounting alpha angle
        """
        
        pass
    
    def get_MountMag0Beta(self) -> float:
        """
        A getter for the 'ConfigMount::MountMag0Beta' structure field
        
        MAG0 mounting beta angle
        """
        
        pass
    
    def get_MountMag0Gamma(self) -> float:
        """
        A getter for the 'ConfigMount::MountMag0Gamma' structure field
        
        MAG0 mounting gamma angle
        """
        
        pass
    
    def get_MountMag1Alpha(self) -> float:
        """
        A getter for the 'ConfigMount::MountMag1Alpha' structure field
        
        MAG1 mounting alpha angle
        """
        
        pass
    
    def get_MountMag1Beta(self) -> float:
        """
        A getter for the 'ConfigMount::MountMag1Beta' structure field
        
        MAG1 mounting beta angle
        """
        
        pass
    
    def get_MountMag1Gamma(self) -> float:
        """
        A getter for the 'ConfigMount::MountMag1Gamma' structure field
        
        MAG1 mounting gamma angle
        """
        
        pass
    
    def get_MountStr0Alpha(self) -> float:
        """
        A getter for the 'ConfigMount::MountStr0Alpha' structure field
        
        STR0 mounting alpha angle
        """
        
        pass
    
    def get_MountStr0Beta(self) -> float:
        """
        A getter for the 'ConfigMount::MountStr0Beta' structure field
        
        STR0 mounting beta angle
        """
        
        pass
    
    def get_MountStr0Gamma(self) -> float:
        """
        A getter for the 'ConfigMount::MountStr0Gamma' structure field
        
        STR0 mounting gamma angle
        """
        
        pass
    
    def get_MountStr1Alpha(self) -> float:
        """
        A getter for the 'ConfigMount::MountStr1Alpha' structure field
        
        STR1 mounting alpha angle
        """
        
        pass
    
    def get_MountStr1Beta(self) -> float:
        """
        A getter for the 'ConfigMount::MountStr1Beta' structure field
        
        STR1 mounting beta angle
        """
        
        pass
    
    def get_MountStr1Gamma(self) -> float:
        """
        A getter for the 'ConfigMount::MountStr1Gamma' structure field
        
        STR1 mounting gamma angle
        """
        
        pass
    
    def get_MountExtSensor0Alpha(self) -> float:
        """
        A getter for the 'ConfigMount::MountExtSensor0Alpha' structure field
        
        ExtSensor0 mounting alpha angle
        """
        
        pass
    
    def get_MountExtSensor0Beta(self) -> float:
        """
        A getter for the 'ConfigMount::MountExtSensor0Beta' structure field
        
        ExtSensor0 mounting beta angle
        """
        
        pass
    
    def get_MountExtSensor0Gamma(self) -> float:
        """
        A getter for the 'ConfigMount::MountExtSensor0Gamma' structure field
        
        ExtSensor0 mounting gamma angle
        """
        
        pass
    
    def get_MountExtSensor1Alpha(self) -> float:
        """
        A getter for the 'ConfigMount::MountExtSensor1Alpha' structure field
        
        ExtSensor1 mounting alpha angle
        """
        
        pass
    
    def get_MountExtSensor1Beta(self) -> float:
        """
        A getter for the 'ConfigMount::MountExtSensor1Beta' structure field
        
        ExtSensor1 mounting beta angle
        """
        
        pass
    
    def get_MountExtSensor1Gamma(self) -> float:
        """
        A getter for the 'ConfigMount::MountExtSensor1Gamma' structure field
        
        ExtSensor1 mounting gamma angle
        """
        
        pass
    
    def get_MountExtGyr0Axis1(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountExtGyr0Axis1' structure field
        
        ExtGyro0 axis1 mounting
        """
        
        pass
    
    def get_MountExtGyr0Axis2(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountExtGyr0Axis2' structure field
        
        ExtGyro0 axis2 mounting
        """
        
        pass
    
    def get_MountExtGyr0Axis3(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountExtGyr0Axis3' structure field
        
        ExtGyro0 axis3 mounting
        """
        
        pass
    
    def get_MountExtGyr1Axis1(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountExtGyr1Axis1' structure field
        
        ExtGyro1 axis1 mounting
        """
        
        pass
    
    def get_MountExtGyr1Axis2(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountExtGyr1Axis2' structure field
        
        ExtGyro1 axis2 mounting
        """
        
        pass
    
    def get_MountExtGyr1Axis3(self) -> CubeComputerControlProgram8_AxisSelect:
        """
        A getter for the 'ConfigMount::MountExtGyr1Axis3' structure field
        
        ExtGyro1 axis3 mounting
        """
        
        pass

def ConfigMount_make_from_buf(buf : bytes) -> ConfigMount:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmStrCubeStarRaw:
    """
    A Python class to represent struct objects of type 'TlmStrCubeStarRaw'
    
    Parameter structure for interface TlmStrCubeStarRaw
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, e__CubeComputerControlProgram8_StarCaptureStatus__Str0CaptureStatus : CubeComputerControlProgram8_StarCaptureStatus, e__CubeComputerControlProgram8_StarDetectStatus__Str0DetectStatus : CubeComputerControlProgram8_StarDetectStatus, e__CubeComputerControlProgram8_StarIdStatus__Str0IdentStatus : CubeComputerControlProgram8_StarIdStatus, bool__Str0Idle : int, bool__Str0Tracking : int, bool__Str0IsValid : int, uint8__Str0NumDetected : int, uint8__Str0NumIdentified : int, double__Str0RateX : float, double__Str0RateY : float, double__Str0RateZ : float, e__CubeComputerControlProgram8_StarCaptureStatus__Str1CaptureStatus : CubeComputerControlProgram8_StarCaptureStatus, e__CubeComputerControlProgram8_StarDetectStatus__Str1DetectStatus : CubeComputerControlProgram8_StarDetectStatus, e__CubeComputerControlProgram8_StarIdStatus__Str1IdentStatus : CubeComputerControlProgram8_StarIdStatus, bool__Str1Idle : int, bool__Str1Tracking : int, bool__Str1IsValid : int, uint8__Str1NumDetected : int, uint8__Str1NumIdentified : int, double__Str1RateX : float, double__Str1RateY : float, double__Str1RateZ : float) -> None:
        """
        Struct 'TlmStrCubeStarRaw' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        e__CubeComputerControlProgram8_StarCaptureStatus__Str0CaptureStatus [1] : CubeComputerControlProgram8_StarCaptureStatus
            Status of image capture operation
        e__CubeComputerControlProgram8_StarDetectStatus__Str0DetectStatus [1] : CubeComputerControlProgram8_StarDetectStatus
            Status of star detection operation
        e__CubeComputerControlProgram8_StarIdStatus__Str0IdentStatus [1] : CubeComputerControlProgram8_StarIdStatus
            Status of star identification operation
        bool__Str0Idle [1] : int
            CubeStar is idle and can accept new command
        bool__Str0Tracking [1] : int
            CubeStar is in tracking mode
        bool__Str0IsValid [1] : int
            CubeStar raw telemetry valid flag
        uint8__Str0NumDetected [1] : int
            Number of detected stars
        uint8__Str0NumIdentified [1] : int
            Number of identified stars
        double__Str0RateX [1] : float
            Estimated angular rate around CubeStar X-axis
        double__Str0RateY [1] : float
            Estimated angular rate around CubeStar Y-axis
        double__Str0RateZ [1] : float
            Estimated angular rate around CubeStar Z-axis
        e__CubeComputerControlProgram8_StarCaptureStatus__Str1CaptureStatus [1] : CubeComputerControlProgram8_StarCaptureStatus
            Status of image capture operation
        e__CubeComputerControlProgram8_StarDetectStatus__Str1DetectStatus [1] : CubeComputerControlProgram8_StarDetectStatus
            Status of star detection operation
        e__CubeComputerControlProgram8_StarIdStatus__Str1IdentStatus [1] : CubeComputerControlProgram8_StarIdStatus
            Status of star identification operation
        bool__Str1Idle [1] : int
            CubeStar is idle and can accept new command
        bool__Str1Tracking [1] : int
            CubeStar is in tracking mode
        bool__Str1IsValid [1] : int
            CubeStar raw telemetry valid flag
        uint8__Str1NumDetected [1] : int
            Number of detected stars
        uint8__Str1NumIdentified [1] : int
            Number of identified stars
        double__Str1RateX [1] : float
            Estimated angular rate around CubeStar X-axis
        double__Str1RateY [1] : float
            Estimated angular rate around CubeStar Y-axis
        double__Str1RateZ [1] : float
            Estimated angular rate around CubeStar Z-axis
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmStrCubeStarRaw::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmStrCubeStarRaw::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_Str0CaptureStatus(self) -> CubeComputerControlProgram8_StarCaptureStatus:
        """
        A getter for the 'TlmStrCubeStarRaw::Str0CaptureStatus' structure field
        
        Status of image capture operation
        """
        
        pass
    
    def get_Str0DetectStatus(self) -> CubeComputerControlProgram8_StarDetectStatus:
        """
        A getter for the 'TlmStrCubeStarRaw::Str0DetectStatus' structure field
        
        Status of star detection operation
        """
        
        pass
    
    def get_Str0IdentStatus(self) -> CubeComputerControlProgram8_StarIdStatus:
        """
        A getter for the 'TlmStrCubeStarRaw::Str0IdentStatus' structure field
        
        Status of star identification operation
        """
        
        pass
    
    def get_Str0Idle(self) -> int:
        """
        A getter for the 'TlmStrCubeStarRaw::Str0Idle' structure field
        
        CubeStar is idle and can accept new command
        """
        
        pass
    
    def get_Str0Tracking(self) -> int:
        """
        A getter for the 'TlmStrCubeStarRaw::Str0Tracking' structure field
        
        CubeStar is in tracking mode
        """
        
        pass
    
    def get_Str0IsValid(self) -> int:
        """
        A getter for the 'TlmStrCubeStarRaw::Str0IsValid' structure field
        
        CubeStar raw telemetry valid flag
        """
        
        pass
    
    def get_Str0NumDetected(self) -> int:
        """
        A getter for the 'TlmStrCubeStarRaw::Str0NumDetected' structure field
        
        Number of detected stars
        """
        
        pass
    
    def get_Str0NumIdentified(self) -> int:
        """
        A getter for the 'TlmStrCubeStarRaw::Str0NumIdentified' structure field
        
        Number of identified stars
        """
        
        pass
    
    def get_Str0RateX(self) -> float:
        """
        A getter for the 'TlmStrCubeStarRaw::Str0RateX' structure field
        
        Estimated angular rate around CubeStar X-axis
        """
        
        pass
    
    def get_Str0RateY(self) -> float:
        """
        A getter for the 'TlmStrCubeStarRaw::Str0RateY' structure field
        
        Estimated angular rate around CubeStar Y-axis
        """
        
        pass
    
    def get_Str0RateZ(self) -> float:
        """
        A getter for the 'TlmStrCubeStarRaw::Str0RateZ' structure field
        
        Estimated angular rate around CubeStar Z-axis
        """
        
        pass
    
    def get_Str1CaptureStatus(self) -> CubeComputerControlProgram8_StarCaptureStatus:
        """
        A getter for the 'TlmStrCubeStarRaw::Str1CaptureStatus' structure field
        
        Status of image capture operation
        """
        
        pass
    
    def get_Str1DetectStatus(self) -> CubeComputerControlProgram8_StarDetectStatus:
        """
        A getter for the 'TlmStrCubeStarRaw::Str1DetectStatus' structure field
        
        Status of star detection operation
        """
        
        pass
    
    def get_Str1IdentStatus(self) -> CubeComputerControlProgram8_StarIdStatus:
        """
        A getter for the 'TlmStrCubeStarRaw::Str1IdentStatus' structure field
        
        Status of star identification operation
        """
        
        pass
    
    def get_Str1Idle(self) -> int:
        """
        A getter for the 'TlmStrCubeStarRaw::Str1Idle' structure field
        
        CubeStar is idle and can accept new command
        """
        
        pass
    
    def get_Str1Tracking(self) -> int:
        """
        A getter for the 'TlmStrCubeStarRaw::Str1Tracking' structure field
        
        CubeStar is in tracking mode
        """
        
        pass
    
    def get_Str1IsValid(self) -> int:
        """
        A getter for the 'TlmStrCubeStarRaw::Str1IsValid' structure field
        
        CubeStar raw telemetry valid flag
        """
        
        pass
    
    def get_Str1NumDetected(self) -> int:
        """
        A getter for the 'TlmStrCubeStarRaw::Str1NumDetected' structure field
        
        Number of detected stars
        """
        
        pass
    
    def get_Str1NumIdentified(self) -> int:
        """
        A getter for the 'TlmStrCubeStarRaw::Str1NumIdentified' structure field
        
        Number of identified stars
        """
        
        pass
    
    def get_Str1RateX(self) -> float:
        """
        A getter for the 'TlmStrCubeStarRaw::Str1RateX' structure field
        
        Estimated angular rate around CubeStar X-axis
        """
        
        pass
    
    def get_Str1RateY(self) -> float:
        """
        A getter for the 'TlmStrCubeStarRaw::Str1RateY' structure field
        
        Estimated angular rate around CubeStar Y-axis
        """
        
        pass
    
    def get_Str1RateZ(self) -> float:
        """
        A getter for the 'TlmStrCubeStarRaw::Str1RateZ' structure field
        
        Estimated angular rate around CubeStar Z-axis
        """
        
        pass

def TlmStrCubeStarRaw_make_from_buf(buf : bytes) -> TlmStrCubeStarRaw:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmController:
    """
    A Python class to represent struct objects of type 'TlmController'
    
    Parameter structure for interface TlmController
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, double__RpyCmdRoll : float, double__RpyCmdPitch : float, double__RpyCmdYaw : float, double__RpyErrRoll : float, double__RpyErrPitch : float, double__RpyErrYaw : float, float__TgtRefLat : float, float__TgtRefLon : float, float__TgtRefAlt : float, double__QuatErrQ0 : float, double__QuatErrQ1 : float, double__QuatErrQ2 : float, float__Rwl0CmdSpeed : float, float__Rwl1CmdSpeed : float, float__Rwl2CmdSpeed : float, float__Rwl3CmdSpeed : float, float__Rwl0CmdMom : float, float__Rwl1CmdMom : float, float__Rwl2CmdMom : float, float__Rwl3CmdMom : float, float__Rwl0CmdTorque : float, float__Rwl1CmdTorque : float, float__Rwl2CmdTorque : float, float__Rwl3CmdTorque : float, double__Mtq0CmdDip : float, double__Mtq1CmdDip : float, double__Mtq2CmdDip : float, float__Mtq0CmdTorque : float, float__Mtq1CmdTorque : float, float__Mtq2CmdTorque : float, int16__Mtq0CmdOnTime : int, int16__Mtq1CmdOnTime : int, int16__Mtq2CmdOnTime : int, uint16__MagConTimeout : int, e__CubeComputerControlProgram8_ConModeSelect__ConModeActive : CubeComputerControlProgram8_ConModeSelect, bool__Rwl0ErrorFlag : int, bool__Rwl1ErrorFlag : int, bool__Rwl2ErrorFlag : int, bool__Rwl3ErrorFlag : int, bool__Rwl0ActiveFlag : int, bool__Rwl1ActiveFlag : int, bool__Rwl2ActiveFlag : int, bool__Rwl3ActiveFlag : int, e__CubeComputerControlProgram8_FmcStage__FmcStage : CubeComputerControlProgram8_FmcStage) -> None:
        """
        Struct 'TlmController' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        double__RpyCmdRoll [1] : float
            Commanded roll angle
        double__RpyCmdPitch [1] : float
            Commanded pitch angle
        double__RpyCmdYaw [1] : float
            Commanded yaw angle
        double__RpyErrRoll [1] : float
            Error roll angle (steering)
        double__RpyErrPitch [1] : float
            Error pitch angle (steering)
        double__RpyErrYaw [1] : float
            Error yaw angle (steering)
        float__TgtRefLat [1] : float
            Reference ground/GEO target latitude
        float__TgtRefLon [1] : float
            Reference ground/GEO target longitude
        float__TgtRefAlt [1] : float
            Reference ground/GEO target altitude
        double__QuatErrQ0 [1] : float
            Control error quaternion vector Q0
        double__QuatErrQ1 [1] : float
            Control error quaternion vector Q1
        double__QuatErrQ2 [1] : float
            Control error quaternion vector Q2
        float__Rwl0CmdSpeed [1] : float
            RWL0 speed command
        float__Rwl1CmdSpeed [1] : float
            RWL1 speed command
        float__Rwl2CmdSpeed [1] : float
            RWL2 speed command
        float__Rwl3CmdSpeed [1] : float
            RWL3 speed command
        float__Rwl0CmdMom [1] : float
            RWL0 momentum command
        float__Rwl1CmdMom [1] : float
            RWL1 momentum command
        float__Rwl2CmdMom [1] : float
            RWL2 momentum command
        float__Rwl3CmdMom [1] : float
            RWL3 momentum command
        float__Rwl0CmdTorque [1] : float
            RWL0 torque command
        float__Rwl1CmdTorque [1] : float
            RWL1 torque command
        float__Rwl2CmdTorque [1] : float
            RWL2 torque command
        float__Rwl3CmdTorque [1] : float
            RWL3 torque command
        double__Mtq0CmdDip [1] : float
            MTQ0 dipole moment command
        double__Mtq1CmdDip [1] : float
            MTQ1 dipole moment command
        double__Mtq2CmdDip [1] : float
            MTQ2 dipole moment command
        float__Mtq0CmdTorque [1] : float
            MTQ0 torque command
        float__Mtq1CmdTorque [1] : float
            MTQ1 torque command
        float__Mtq2CmdTorque [1] : float
            MTQ2 torque command
        int16__Mtq0CmdOnTime [1] : int
            MTQ0 on-time command
        int16__Mtq1CmdOnTime [1] : int
            MTQ1 on-time command
        int16__Mtq2CmdOnTime [1] : int
            MTQ2 on-time command
        uint16__MagConTimeout [1] : int
            Magnetic control timeout
        e__CubeComputerControlProgram8_ConModeSelect__ConModeActive [1] : CubeComputerControlProgram8_ConModeSelect
            Active control mode
        bool__Rwl0ErrorFlag [1] : int
            RWL0 error flag
        bool__Rwl1ErrorFlag [1] : int
            RWL1 error flag
        bool__Rwl2ErrorFlag [1] : int
            RWL2 error flag
        bool__Rwl3ErrorFlag [1] : int
            RWL3 error flag
        bool__Rwl0ActiveFlag [1] : int
            RWL0 active flag
        bool__Rwl1ActiveFlag [1] : int
            RWL1 active flag
        bool__Rwl2ActiveFlag [1] : int
            RWL2 active flag
        bool__Rwl3ActiveFlag [1] : int
            RWL3 active flag
        e__CubeComputerControlProgram8_FmcStage__FmcStage [1] : CubeComputerControlProgram8_FmcStage
            Current FMC Stage
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmController::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmController::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_RpyCmdRoll(self) -> float:
        """
        A getter for the 'TlmController::RpyCmdRoll' structure field
        
        Commanded roll angle
        """
        
        pass
    
    def get_RpyCmdPitch(self) -> float:
        """
        A getter for the 'TlmController::RpyCmdPitch' structure field
        
        Commanded pitch angle
        """
        
        pass
    
    def get_RpyCmdYaw(self) -> float:
        """
        A getter for the 'TlmController::RpyCmdYaw' structure field
        
        Commanded yaw angle
        """
        
        pass
    
    def get_RpyErrRoll(self) -> float:
        """
        A getter for the 'TlmController::RpyErrRoll' structure field
        
        Error roll angle (steering)
        """
        
        pass
    
    def get_RpyErrPitch(self) -> float:
        """
        A getter for the 'TlmController::RpyErrPitch' structure field
        
        Error pitch angle (steering)
        """
        
        pass
    
    def get_RpyErrYaw(self) -> float:
        """
        A getter for the 'TlmController::RpyErrYaw' structure field
        
        Error yaw angle (steering)
        """
        
        pass
    
    def get_TgtRefLat(self) -> float:
        """
        A getter for the 'TlmController::TgtRefLat' structure field
        
        Reference ground/GEO target latitude
        """
        
        pass
    
    def get_TgtRefLon(self) -> float:
        """
        A getter for the 'TlmController::TgtRefLon' structure field
        
        Reference ground/GEO target longitude
        """
        
        pass
    
    def get_TgtRefAlt(self) -> float:
        """
        A getter for the 'TlmController::TgtRefAlt' structure field
        
        Reference ground/GEO target altitude
        """
        
        pass
    
    def get_QuatErrQ0(self) -> float:
        """
        A getter for the 'TlmController::QuatErrQ0' structure field
        
        Control error quaternion vector Q0
        """
        
        pass
    
    def get_QuatErrQ1(self) -> float:
        """
        A getter for the 'TlmController::QuatErrQ1' structure field
        
        Control error quaternion vector Q1
        """
        
        pass
    
    def get_QuatErrQ2(self) -> float:
        """
        A getter for the 'TlmController::QuatErrQ2' structure field
        
        Control error quaternion vector Q2
        """
        
        pass
    
    def get_Rwl0CmdSpeed(self) -> float:
        """
        A getter for the 'TlmController::Rwl0CmdSpeed' structure field
        
        RWL0 speed command
        """
        
        pass
    
    def get_Rwl1CmdSpeed(self) -> float:
        """
        A getter for the 'TlmController::Rwl1CmdSpeed' structure field
        
        RWL1 speed command
        """
        
        pass
    
    def get_Rwl2CmdSpeed(self) -> float:
        """
        A getter for the 'TlmController::Rwl2CmdSpeed' structure field
        
        RWL2 speed command
        """
        
        pass
    
    def get_Rwl3CmdSpeed(self) -> float:
        """
        A getter for the 'TlmController::Rwl3CmdSpeed' structure field
        
        RWL3 speed command
        """
        
        pass
    
    def get_Rwl0CmdMom(self) -> float:
        """
        A getter for the 'TlmController::Rwl0CmdMom' structure field
        
        RWL0 momentum command
        """
        
        pass
    
    def get_Rwl1CmdMom(self) -> float:
        """
        A getter for the 'TlmController::Rwl1CmdMom' structure field
        
        RWL1 momentum command
        """
        
        pass
    
    def get_Rwl2CmdMom(self) -> float:
        """
        A getter for the 'TlmController::Rwl2CmdMom' structure field
        
        RWL2 momentum command
        """
        
        pass
    
    def get_Rwl3CmdMom(self) -> float:
        """
        A getter for the 'TlmController::Rwl3CmdMom' structure field
        
        RWL3 momentum command
        """
        
        pass
    
    def get_Rwl0CmdTorque(self) -> float:
        """
        A getter for the 'TlmController::Rwl0CmdTorque' structure field
        
        RWL0 torque command
        """
        
        pass
    
    def get_Rwl1CmdTorque(self) -> float:
        """
        A getter for the 'TlmController::Rwl1CmdTorque' structure field
        
        RWL1 torque command
        """
        
        pass
    
    def get_Rwl2CmdTorque(self) -> float:
        """
        A getter for the 'TlmController::Rwl2CmdTorque' structure field
        
        RWL2 torque command
        """
        
        pass
    
    def get_Rwl3CmdTorque(self) -> float:
        """
        A getter for the 'TlmController::Rwl3CmdTorque' structure field
        
        RWL3 torque command
        """
        
        pass
    
    def get_Mtq0CmdDip(self) -> float:
        """
        A getter for the 'TlmController::Mtq0CmdDip' structure field
        
        MTQ0 dipole moment command
        """
        
        pass
    
    def get_Mtq1CmdDip(self) -> float:
        """
        A getter for the 'TlmController::Mtq1CmdDip' structure field
        
        MTQ1 dipole moment command
        """
        
        pass
    
    def get_Mtq2CmdDip(self) -> float:
        """
        A getter for the 'TlmController::Mtq2CmdDip' structure field
        
        MTQ2 dipole moment command
        """
        
        pass
    
    def get_Mtq0CmdTorque(self) -> float:
        """
        A getter for the 'TlmController::Mtq0CmdTorque' structure field
        
        MTQ0 torque command
        """
        
        pass
    
    def get_Mtq1CmdTorque(self) -> float:
        """
        A getter for the 'TlmController::Mtq1CmdTorque' structure field
        
        MTQ1 torque command
        """
        
        pass
    
    def get_Mtq2CmdTorque(self) -> float:
        """
        A getter for the 'TlmController::Mtq2CmdTorque' structure field
        
        MTQ2 torque command
        """
        
        pass
    
    def get_Mtq0CmdOnTime(self) -> int:
        """
        A getter for the 'TlmController::Mtq0CmdOnTime' structure field
        
        MTQ0 on-time command
        """
        
        pass
    
    def get_Mtq1CmdOnTime(self) -> int:
        """
        A getter for the 'TlmController::Mtq1CmdOnTime' structure field
        
        MTQ1 on-time command
        """
        
        pass
    
    def get_Mtq2CmdOnTime(self) -> int:
        """
        A getter for the 'TlmController::Mtq2CmdOnTime' structure field
        
        MTQ2 on-time command
        """
        
        pass
    
    def get_MagConTimeout(self) -> int:
        """
        A getter for the 'TlmController::MagConTimeout' structure field
        
        Magnetic control timeout
        """
        
        pass
    
    def get_ConModeActive(self) -> CubeComputerControlProgram8_ConModeSelect:
        """
        A getter for the 'TlmController::ConModeActive' structure field
        
        Active control mode
        """
        
        pass
    
    def get_Rwl0ErrorFlag(self) -> int:
        """
        A getter for the 'TlmController::Rwl0ErrorFlag' structure field
        
        RWL0 error flag
        """
        
        pass
    
    def get_Rwl1ErrorFlag(self) -> int:
        """
        A getter for the 'TlmController::Rwl1ErrorFlag' structure field
        
        RWL1 error flag
        """
        
        pass
    
    def get_Rwl2ErrorFlag(self) -> int:
        """
        A getter for the 'TlmController::Rwl2ErrorFlag' structure field
        
        RWL2 error flag
        """
        
        pass
    
    def get_Rwl3ErrorFlag(self) -> int:
        """
        A getter for the 'TlmController::Rwl3ErrorFlag' structure field
        
        RWL3 error flag
        """
        
        pass
    
    def get_Rwl0ActiveFlag(self) -> int:
        """
        A getter for the 'TlmController::Rwl0ActiveFlag' structure field
        
        RWL0 active flag
        """
        
        pass
    
    def get_Rwl1ActiveFlag(self) -> int:
        """
        A getter for the 'TlmController::Rwl1ActiveFlag' structure field
        
        RWL1 active flag
        """
        
        pass
    
    def get_Rwl2ActiveFlag(self) -> int:
        """
        A getter for the 'TlmController::Rwl2ActiveFlag' structure field
        
        RWL2 active flag
        """
        
        pass
    
    def get_Rwl3ActiveFlag(self) -> int:
        """
        A getter for the 'TlmController::Rwl3ActiveFlag' structure field
        
        RWL3 active flag
        """
        
        pass
    
    def get_FmcStage(self) -> CubeComputerControlProgram8_FmcStage:
        """
        A getter for the 'TlmController::FmcStage' structure field
        
        Current FMC Stage
        """
        
        pass

def TlmController_make_from_buf(buf : bytes) -> TlmController:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ConfigAdcsController:
    """
    A Python class to represent struct objects of type 'ConfigAdcsController'
    
    Parameter structure for interface ConfigAdcsController
    """

    def __init__(self, e__CubeComputerControlProgram8_ConModeSelect__ConModeDefault : CubeComputerControlProgram8_ConModeSelect, float__Kd : float, float__Kdsun : float, float__Kdecl : float, float__Ks : float, float__Kdf : float, float__Kn : float, float__Kq : float, float__Kqx : float, float__Kqy : float, float__Kqz : float, float__Kh : float, float__Kp1 : float, float__Kd1 : float, float__Kp2 : float, float__Kd2 : float, float__Kp3 : float, float__Kd3 : float, float__Ki3 : float, float__wy_ref : float, float__H_ref : float, float__Hy_bias : float, float__wSunYawRef : float, float__SunKeepoutAng : float, float__RollLimit : float, bool__YawCompensate : int, bool__SunTrackEclEn : int, bool__SunAvoidEn : int) -> None:
        """
        Struct 'ConfigAdcsController' constructor
        
        Attributes
        ---------
        e__CubeComputerControlProgram8_ConModeSelect__ConModeDefault [1] : CubeComputerControlProgram8_ConModeSelect
            Default control mode
        float__Kd [1] : float
            Detumbling damping gain (Kd)
        float__Kdsun [1] : float
            Sun-spin control gain (KDsun)
        float__Kdecl [1] : float
            Sun-spin control gain (KDecl)
        float__Ks [1] : float
            Detumbling spin gain (Ks)
        float__Kdf [1] : float
            Fast B-dot detumbling gain (Kdf)
        float__Kn [1] : float
            Y-momentum nutation damping gain (Kn)
        float__Kq [1] : float
            Y-momentum nutation damping quaternion gain (Kq)
        float__Kqx [1] : float
            X-axis GG nutation damping quaternion gain (Kqx)
        float__Kqy [1] : float
            Y-axis GG nutation damping quaternion gain (Kqy)
        float__Kqz [1] : float
            Z-axis GG nutation damping quaternion gain (Kqz)
        float__Kh [1] : float
            Wheel momentum dumping magnetic control gain (Kh)
        float__Kp1 [1] : float
            Y-momentum proportional gain (Kp1)
        float__Kd1 [1] : float
            Y-momentum derivative gain (Kd1)
        float__Kp2 [1] : float
            RWheel proportional gain (Kp2)
        float__Kd2 [1] : float
            RWheel derivative gain (Kd2)
        float__Kp3 [1] : float
            Tracking proportional gain (Kp3)
        float__Kd3 [1] : float
            Tracking derivative gain (Kd3)
        float__Ki3 [1] : float
            Tracking integral gain (Ki3)
        float__wy_ref [1] : float
            Reference spin rate (wy-ref)
        float__H_ref [1] : float
            Reference wheel momentum (H-ref). Must always be smaller than 0
        float__Hy_bias [1] : float
            Y-wheel bias momentum during XYZ-control (Hy-bias)
        float__wSunYawRef [1] : float
            Reference spin rate for ConSunYawSpin RW control
        float__SunKeepoutAng [1] : float
            Sun keep-out angle
        float__RollLimit [1] : float
            Limit roll angle in ConRollSun and ConRollTarget
        bool__YawCompensate [1] : int
            Perform yaw compensation for earth rotation in 3-axis RPY control
        bool__SunTrackEclEn [1] : int
            Enable sun tracking during eclipse when using ConSunTrack
        bool__SunAvoidEn [1] : int
            Enable sun avoidance
        """
        
        pass
        
    def get_ConModeDefault(self) -> CubeComputerControlProgram8_ConModeSelect:
        """
        A getter for the 'ConfigAdcsController::ConModeDefault' structure field
        
        Default control mode
        """
        
        pass
    
    def get_Kd(self) -> float:
        """
        A getter for the 'ConfigAdcsController::Kd' structure field
        
        Detumbling damping gain (Kd)
        """
        
        pass
    
    def get_Kdsun(self) -> float:
        """
        A getter for the 'ConfigAdcsController::Kdsun' structure field
        
        Sun-spin control gain (KDsun)
        """
        
        pass
    
    def get_Kdecl(self) -> float:
        """
        A getter for the 'ConfigAdcsController::Kdecl' structure field
        
        Sun-spin control gain (KDecl)
        """
        
        pass
    
    def get_Ks(self) -> float:
        """
        A getter for the 'ConfigAdcsController::Ks' structure field
        
        Detumbling spin gain (Ks)
        """
        
        pass
    
    def get_Kdf(self) -> float:
        """
        A getter for the 'ConfigAdcsController::Kdf' structure field
        
        Fast B-dot detumbling gain (Kdf)
        """
        
        pass
    
    def get_Kn(self) -> float:
        """
        A getter for the 'ConfigAdcsController::Kn' structure field
        
        Y-momentum nutation damping gain (Kn)
        """
        
        pass
    
    def get_Kq(self) -> float:
        """
        A getter for the 'ConfigAdcsController::Kq' structure field
        
        Y-momentum nutation damping quaternion gain (Kq)
        """
        
        pass
    
    def get_Kqx(self) -> float:
        """
        A getter for the 'ConfigAdcsController::Kqx' structure field
        
        X-axis GG nutation damping quaternion gain (Kqx)
        """
        
        pass
    
    def get_Kqy(self) -> float:
        """
        A getter for the 'ConfigAdcsController::Kqy' structure field
        
        Y-axis GG nutation damping quaternion gain (Kqy)
        """
        
        pass
    
    def get_Kqz(self) -> float:
        """
        A getter for the 'ConfigAdcsController::Kqz' structure field
        
        Z-axis GG nutation damping quaternion gain (Kqz)
        """
        
        pass
    
    def get_Kh(self) -> float:
        """
        A getter for the 'ConfigAdcsController::Kh' structure field
        
        Wheel momentum dumping magnetic control gain (Kh)
        """
        
        pass
    
    def get_Kp1(self) -> float:
        """
        A getter for the 'ConfigAdcsController::Kp1' structure field
        
        Y-momentum proportional gain (Kp1)
        """
        
        pass
    
    def get_Kd1(self) -> float:
        """
        A getter for the 'ConfigAdcsController::Kd1' structure field
        
        Y-momentum derivative gain (Kd1)
        """
        
        pass
    
    def get_Kp2(self) -> float:
        """
        A getter for the 'ConfigAdcsController::Kp2' structure field
        
        RWheel proportional gain (Kp2)
        """
        
        pass
    
    def get_Kd2(self) -> float:
        """
        A getter for the 'ConfigAdcsController::Kd2' structure field
        
        RWheel derivative gain (Kd2)
        """
        
        pass
    
    def get_Kp3(self) -> float:
        """
        A getter for the 'ConfigAdcsController::Kp3' structure field
        
        Tracking proportional gain (Kp3)
        """
        
        pass
    
    def get_Kd3(self) -> float:
        """
        A getter for the 'ConfigAdcsController::Kd3' structure field
        
        Tracking derivative gain (Kd3)
        """
        
        pass
    
    def get_Ki3(self) -> float:
        """
        A getter for the 'ConfigAdcsController::Ki3' structure field
        
        Tracking integral gain (Ki3)
        """
        
        pass
    
    def get_wy_ref(self) -> float:
        """
        A getter for the 'ConfigAdcsController::wy_ref' structure field
        
        Reference spin rate (wy-ref)
        """
        
        pass
    
    def get_H_ref(self) -> float:
        """
        A getter for the 'ConfigAdcsController::H_ref' structure field
        
        Reference wheel momentum (H-ref). Must always be smaller than 0
        """
        
        pass
    
    def get_Hy_bias(self) -> float:
        """
        A getter for the 'ConfigAdcsController::Hy_bias' structure field
        
        Y-wheel bias momentum during XYZ-control (Hy-bias)
        """
        
        pass
    
    def get_wSunYawRef(self) -> float:
        """
        A getter for the 'ConfigAdcsController::wSunYawRef' structure field
        
        Reference spin rate for ConSunYawSpin RW control
        """
        
        pass
    
    def get_SunKeepoutAng(self) -> float:
        """
        A getter for the 'ConfigAdcsController::SunKeepoutAng' structure field
        
        Sun keep-out angle
        """
        
        pass
    
    def get_RollLimit(self) -> float:
        """
        A getter for the 'ConfigAdcsController::RollLimit' structure field
        
        Limit roll angle in ConRollSun and ConRollTarget
        """
        
        pass
    
    def get_YawCompensate(self) -> int:
        """
        A getter for the 'ConfigAdcsController::YawCompensate' structure field
        
        Perform yaw compensation for earth rotation in 3-axis RPY control
        """
        
        pass
    
    def get_SunTrackEclEn(self) -> int:
        """
        A getter for the 'ConfigAdcsController::SunTrackEclEn' structure field
        
        Enable sun tracking during eclipse when using ConSunTrack
        """
        
        pass
    
    def get_SunAvoidEn(self) -> int:
        """
        A getter for the 'ConfigAdcsController::SunAvoidEn' structure field
        
        Enable sun avoidance
        """
        
        pass

def ConfigAdcsController_make_from_buf(buf : bytes) -> ConfigAdcsController:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ConfigDefaultModes:
    """
    A Python class to represent struct objects of type 'ConfigDefaultModes'
    
    Parameter structure for interface ConfigDefaultModes
    """

    def __init__(self, e__CubeComputerControlProgram8_AdcsRunModeSelect__RunModeDefault : CubeComputerControlProgram8_AdcsRunModeSelect, e__CubeComputerControlProgram8_AdcsOpStateSelect__OpStateDefault : CubeComputerControlProgram8_AdcsOpStateSelect, e__CubeComputerControlProgram8_ConModeSelect__ConModeSafe : CubeComputerControlProgram8_ConModeSelect, e__CubeComputerControlProgram8_ConModeSelect__ConModeAuto : CubeComputerControlProgram8_ConModeSelect) -> None:
        """
        Struct 'ConfigDefaultModes' constructor
        
        Attributes
        ---------
        e__CubeComputerControlProgram8_AdcsRunModeSelect__RunModeDefault [1] : CubeComputerControlProgram8_AdcsRunModeSelect
            Default ADCS run mode
        e__CubeComputerControlProgram8_AdcsOpStateSelect__OpStateDefault [1] : CubeComputerControlProgram8_AdcsOpStateSelect
            Default ADCS operational state
        e__CubeComputerControlProgram8_ConModeSelect__ConModeSafe [1] : CubeComputerControlProgram8_ConModeSelect
            Default control mode in OpStateSafe
        e__CubeComputerControlProgram8_ConModeSelect__ConModeAuto [1] : CubeComputerControlProgram8_ConModeSelect
            Default control mode in OpStateAuto
        """
        
        pass
        
    def get_RunModeDefault(self) -> CubeComputerControlProgram8_AdcsRunModeSelect:
        """
        A getter for the 'ConfigDefaultModes::RunModeDefault' structure field
        
        Default ADCS run mode
        """
        
        pass
    
    def get_OpStateDefault(self) -> CubeComputerControlProgram8_AdcsOpStateSelect:
        """
        A getter for the 'ConfigDefaultModes::OpStateDefault' structure field
        
        Default ADCS operational state
        """
        
        pass
    
    def get_ConModeSafe(self) -> CubeComputerControlProgram8_ConModeSelect:
        """
        A getter for the 'ConfigDefaultModes::ConModeSafe' structure field
        
        Default control mode in OpStateSafe
        """
        
        pass
    
    def get_ConModeAuto(self) -> CubeComputerControlProgram8_ConModeSelect:
        """
        A getter for the 'ConfigDefaultModes::ConModeAuto' structure field
        
        Default control mode in OpStateAuto
        """
        
        pass

def ConfigDefaultModes_make_from_buf(buf : bytes) -> ConfigDefaultModes:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class ConMode:
    """
    A Python class to represent struct objects of type 'ConMode'
    
    Parameter structure for interface ConMode
    """

    def __init__(self, e__CubeComputerControlProgram8_ConModeSelect__ControlMode : CubeComputerControlProgram8_ConModeSelect, uint16__MagConTimeout : int) -> None:
        """
        Struct 'ConMode' constructor
        
        Attributes
        ---------
        e__CubeComputerControlProgram8_ConModeSelect__ControlMode [1] : CubeComputerControlProgram8_ConModeSelect
            Control mode
        uint16__MagConTimeout [1] : int
            Magnetic control timeout
        """
        
        pass
        
    def get_ControlMode(self) -> CubeComputerControlProgram8_ConModeSelect:
        """
        A getter for the 'ConMode::ControlMode' structure field
        
        Control mode
        """
        
        pass
    
    def get_MagConTimeout(self) -> int:
        """
        A getter for the 'ConMode::MagConTimeout' structure field
        
        Magnetic control timeout
        """
        
        pass

def ConMode_make_from_buf(buf : bytes) -> ConMode:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmHil:
    """
    A Python class to represent struct objects of type 'TlmHil'
    
    Parameter structure for interface TlmHil
    """

    def __init__(self, e__CubeComputerControlProgram8_ConModeSelect__ConModeActive : CubeComputerControlProgram8_ConModeSelect, e__CubeComputerControlProgram8_EstModeSelect__EstModeActive : CubeComputerControlProgram8_EstModeSelect, e__CubeComputerControlProgram8_OrbModeSelect__OrbModeActive : CubeComputerControlProgram8_OrbModeSelect, e__CubeComputerControlProgram8_NavSource__NavSource : CubeComputerControlProgram8_NavSource, bool__Asgp4Error : int, bool__HilSyncOk : int, float__Rwl0CmdSpeed : float, float__Rwl1CmdSpeed : float, float__Rwl2CmdSpeed : float, float__Rwl3CmdSpeed : float, int16__Mtq0CmdOnTime : int, int16__Mtq1CmdOnTime : int, int16__Mtq2CmdOnTime : int, uint16__MagConTimeout : int, bool__Rwl0ErrorFlag : int, bool__Rwl1ErrorFlag : int, bool__Rwl2ErrorFlag : int, bool__Rwl3ErrorFlag : int, bool__Rwl0ActiveFlag : int, bool__Rwl1ActiveFlag : int, bool__Rwl2ActiveFlag : int, bool__Rwl3ActiveFlag : int, float__EstQuatQ0 : float, float__EstQuatQ1 : float, float__EstQuatQ2 : float, float__EstQuatQ3 : float, float__EstRateOrcX : float, float__EstRateOrcY : float, float__EstRateOrcZ : float, int32__SatPosEciX : int, int32__SatPosEciY : int, int32__SatPosEciZ : int, int16__SatVelEciX : int, int16__SatVelEciY : int, int16__SatVelEciZ : int, float__RpyCmdRoll : float, float__RpyCmdPitch : float, float__RpyCmdYaw : float, uint16__Asgp4BatchCtr : int, uint16__Asgp4PosDelta : int, float__Rwl0MeasSpeed : float, float__Rwl1MeasSpeed : float, float__Rwl2MeasSpeed : float, float__Rwl3MeasSpeed : float, bool__Rwl0MeasValid : int, bool__Rwl1MeasValid : int, bool__Rwl2MeasValid : int, bool__Rwl3MeasValid : int, e__CubeComputerControlProgram8_FmcStage__FmcStage : CubeComputerControlProgram8_FmcStage) -> None:
        """
        Struct 'TlmHil' constructor
        
        Attributes
        ---------
        e__CubeComputerControlProgram8_ConModeSelect__ConModeActive [1] : CubeComputerControlProgram8_ConModeSelect
            Active control mode
        e__CubeComputerControlProgram8_EstModeSelect__EstModeActive [1] : CubeComputerControlProgram8_EstModeSelect
            Active estimator mode
        e__CubeComputerControlProgram8_OrbModeSelect__OrbModeActive [1] : CubeComputerControlProgram8_OrbModeSelect
            Active orbit mode
        e__CubeComputerControlProgram8_NavSource__NavSource [1] : CubeComputerControlProgram8_NavSource
            Source of current orbit position and velocity
        bool__Asgp4Error [1] : int
            GNSS and ASGP4 position error differs too much
        bool__HilSyncOk [1] : int
            HIL is currently synchronised
        float__Rwl0CmdSpeed [1] : float
            RWL0 speed command
        float__Rwl1CmdSpeed [1] : float
            RWL1 speed command
        float__Rwl2CmdSpeed [1] : float
            RWL2 speed command
        float__Rwl3CmdSpeed [1] : float
            RWL3 speed command
        int16__Mtq0CmdOnTime [1] : int
            MTQ0 on-time command
        int16__Mtq1CmdOnTime [1] : int
            MTQ1 on-time command
        int16__Mtq2CmdOnTime [1] : int
            MTQ2 on-time command
        uint16__MagConTimeout [1] : int
            Magnetic control timeout
        bool__Rwl0ErrorFlag [1] : int
            RWL0 error flag
        bool__Rwl1ErrorFlag [1] : int
            RWL1 error flag
        bool__Rwl2ErrorFlag [1] : int
            RWL2 error flag
        bool__Rwl3ErrorFlag [1] : int
            RWL3 error flag
        bool__Rwl0ActiveFlag [1] : int
            RWL0 active flag
        bool__Rwl1ActiveFlag [1] : int
            RWL1 active flag
        bool__Rwl2ActiveFlag [1] : int
            RWL2 active flag
        bool__Rwl3ActiveFlag [1] : int
            RWL3 active flag
        float__EstQuatQ0 [1] : float
            Estimated ORC quaternion Q0
        float__EstQuatQ1 [1] : float
            Estimated ORC quaternion Q1
        float__EstQuatQ2 [1] : float
            Estimated ORC quaternion Q2
        float__EstQuatQ3 [1] : float
            Estimated ORC quaternion Q3
        float__EstRateOrcX [1] : float
            Estimated body rate (ORC) X component
        float__EstRateOrcY [1] : float
            Estimated body rate (ORC) Y component
        float__EstRateOrcZ [1] : float
            Estimated body rate (ORC) Z component
        int32__SatPosEciX [1] : int
            Satellite ECI position vector X component
        int32__SatPosEciY [1] : int
            Satellite ECI position vector Y component
        int32__SatPosEciZ [1] : int
            Satellite ECI position vector Z component
        int16__SatVelEciX [1] : int
            Satellite ECI velocity vector X component
        int16__SatVelEciY [1] : int
            Satellite ECI velocity vector Y component
        int16__SatVelEciZ [1] : int
            Satellite ECI velocity vector Z component
        float__RpyCmdRoll [1] : float
            Commanded roll angle
        float__RpyCmdPitch [1] : float
            Commanded pitch angle
        float__RpyCmdYaw [1] : float
            Commanded yaw angle
        uint16__Asgp4BatchCtr [1] : int
            ASGP4 batch counter
        uint16__Asgp4PosDelta [1] : int
            Average position error between GNSS and ASGP4
        float__Rwl0MeasSpeed [1] : float
            RWL0 speed measurement
        float__Rwl1MeasSpeed [1] : float
            RWL1 speed measurement
        float__Rwl2MeasSpeed [1] : float
            RWL2 speed measurement
        float__Rwl3MeasSpeed [1] : float
            RWL3 speed measurement
        bool__Rwl0MeasValid [1] : int
            RWL0 measurement valid flag
        bool__Rwl1MeasValid [1] : int
            RWL1 measurement valid flag
        bool__Rwl2MeasValid [1] : int
            RWL2 measurement valid flag
        bool__Rwl3MeasValid [1] : int
            RWL3 measurement valid flag
        e__CubeComputerControlProgram8_FmcStage__FmcStage [1] : CubeComputerControlProgram8_FmcStage
            Current FMC Stage
        """
        
        pass
        
    def get_ConModeActive(self) -> CubeComputerControlProgram8_ConModeSelect:
        """
        A getter for the 'TlmHil::ConModeActive' structure field
        
        Active control mode
        """
        
        pass
    
    def get_EstModeActive(self) -> CubeComputerControlProgram8_EstModeSelect:
        """
        A getter for the 'TlmHil::EstModeActive' structure field
        
        Active estimator mode
        """
        
        pass
    
    def get_OrbModeActive(self) -> CubeComputerControlProgram8_OrbModeSelect:
        """
        A getter for the 'TlmHil::OrbModeActive' structure field
        
        Active orbit mode
        """
        
        pass
    
    def get_NavSource(self) -> CubeComputerControlProgram8_NavSource:
        """
        A getter for the 'TlmHil::NavSource' structure field
        
        Source of current orbit position and velocity
        """
        
        pass
    
    def get_Asgp4Error(self) -> int:
        """
        A getter for the 'TlmHil::Asgp4Error' structure field
        
        GNSS and ASGP4 position error differs too much
        """
        
        pass
    
    def get_HilSyncOk(self) -> int:
        """
        A getter for the 'TlmHil::HilSyncOk' structure field
        
        HIL is currently synchronised
        """
        
        pass
    
    def get_Rwl0CmdSpeed(self) -> float:
        """
        A getter for the 'TlmHil::Rwl0CmdSpeed' structure field
        
        RWL0 speed command
        """
        
        pass
    
    def get_Rwl1CmdSpeed(self) -> float:
        """
        A getter for the 'TlmHil::Rwl1CmdSpeed' structure field
        
        RWL1 speed command
        """
        
        pass
    
    def get_Rwl2CmdSpeed(self) -> float:
        """
        A getter for the 'TlmHil::Rwl2CmdSpeed' structure field
        
        RWL2 speed command
        """
        
        pass
    
    def get_Rwl3CmdSpeed(self) -> float:
        """
        A getter for the 'TlmHil::Rwl3CmdSpeed' structure field
        
        RWL3 speed command
        """
        
        pass
    
    def get_Mtq0CmdOnTime(self) -> int:
        """
        A getter for the 'TlmHil::Mtq0CmdOnTime' structure field
        
        MTQ0 on-time command
        """
        
        pass
    
    def get_Mtq1CmdOnTime(self) -> int:
        """
        A getter for the 'TlmHil::Mtq1CmdOnTime' structure field
        
        MTQ1 on-time command
        """
        
        pass
    
    def get_Mtq2CmdOnTime(self) -> int:
        """
        A getter for the 'TlmHil::Mtq2CmdOnTime' structure field
        
        MTQ2 on-time command
        """
        
        pass
    
    def get_MagConTimeout(self) -> int:
        """
        A getter for the 'TlmHil::MagConTimeout' structure field
        
        Magnetic control timeout
        """
        
        pass
    
    def get_Rwl0ErrorFlag(self) -> int:
        """
        A getter for the 'TlmHil::Rwl0ErrorFlag' structure field
        
        RWL0 error flag
        """
        
        pass
    
    def get_Rwl1ErrorFlag(self) -> int:
        """
        A getter for the 'TlmHil::Rwl1ErrorFlag' structure field
        
        RWL1 error flag
        """
        
        pass
    
    def get_Rwl2ErrorFlag(self) -> int:
        """
        A getter for the 'TlmHil::Rwl2ErrorFlag' structure field
        
        RWL2 error flag
        """
        
        pass
    
    def get_Rwl3ErrorFlag(self) -> int:
        """
        A getter for the 'TlmHil::Rwl3ErrorFlag' structure field
        
        RWL3 error flag
        """
        
        pass
    
    def get_Rwl0ActiveFlag(self) -> int:
        """
        A getter for the 'TlmHil::Rwl0ActiveFlag' structure field
        
        RWL0 active flag
        """
        
        pass
    
    def get_Rwl1ActiveFlag(self) -> int:
        """
        A getter for the 'TlmHil::Rwl1ActiveFlag' structure field
        
        RWL1 active flag
        """
        
        pass
    
    def get_Rwl2ActiveFlag(self) -> int:
        """
        A getter for the 'TlmHil::Rwl2ActiveFlag' structure field
        
        RWL2 active flag
        """
        
        pass
    
    def get_Rwl3ActiveFlag(self) -> int:
        """
        A getter for the 'TlmHil::Rwl3ActiveFlag' structure field
        
        RWL3 active flag
        """
        
        pass
    
    def get_EstQuatQ0(self) -> float:
        """
        A getter for the 'TlmHil::EstQuatQ0' structure field
        
        Estimated ORC quaternion Q0
        """
        
        pass
    
    def get_EstQuatQ1(self) -> float:
        """
        A getter for the 'TlmHil::EstQuatQ1' structure field
        
        Estimated ORC quaternion Q1
        """
        
        pass
    
    def get_EstQuatQ2(self) -> float:
        """
        A getter for the 'TlmHil::EstQuatQ2' structure field
        
        Estimated ORC quaternion Q2
        """
        
        pass
    
    def get_EstQuatQ3(self) -> float:
        """
        A getter for the 'TlmHil::EstQuatQ3' structure field
        
        Estimated ORC quaternion Q3
        """
        
        pass
    
    def get_EstRateOrcX(self) -> float:
        """
        A getter for the 'TlmHil::EstRateOrcX' structure field
        
        Estimated body rate (ORC) X component
        """
        
        pass
    
    def get_EstRateOrcY(self) -> float:
        """
        A getter for the 'TlmHil::EstRateOrcY' structure field
        
        Estimated body rate (ORC) Y component
        """
        
        pass
    
    def get_EstRateOrcZ(self) -> float:
        """
        A getter for the 'TlmHil::EstRateOrcZ' structure field
        
        Estimated body rate (ORC) Z component
        """
        
        pass
    
    def get_SatPosEciX(self) -> int:
        """
        A getter for the 'TlmHil::SatPosEciX' structure field
        
        Satellite ECI position vector X component
        """
        
        pass
    
    def get_SatPosEciY(self) -> int:
        """
        A getter for the 'TlmHil::SatPosEciY' structure field
        
        Satellite ECI position vector Y component
        """
        
        pass
    
    def get_SatPosEciZ(self) -> int:
        """
        A getter for the 'TlmHil::SatPosEciZ' structure field
        
        Satellite ECI position vector Z component
        """
        
        pass
    
    def get_SatVelEciX(self) -> int:
        """
        A getter for the 'TlmHil::SatVelEciX' structure field
        
        Satellite ECI velocity vector X component
        """
        
        pass
    
    def get_SatVelEciY(self) -> int:
        """
        A getter for the 'TlmHil::SatVelEciY' structure field
        
        Satellite ECI velocity vector Y component
        """
        
        pass
    
    def get_SatVelEciZ(self) -> int:
        """
        A getter for the 'TlmHil::SatVelEciZ' structure field
        
        Satellite ECI velocity vector Z component
        """
        
        pass
    
    def get_RpyCmdRoll(self) -> float:
        """
        A getter for the 'TlmHil::RpyCmdRoll' structure field
        
        Commanded roll angle
        """
        
        pass
    
    def get_RpyCmdPitch(self) -> float:
        """
        A getter for the 'TlmHil::RpyCmdPitch' structure field
        
        Commanded pitch angle
        """
        
        pass
    
    def get_RpyCmdYaw(self) -> float:
        """
        A getter for the 'TlmHil::RpyCmdYaw' structure field
        
        Commanded yaw angle
        """
        
        pass
    
    def get_Asgp4BatchCtr(self) -> int:
        """
        A getter for the 'TlmHil::Asgp4BatchCtr' structure field
        
        ASGP4 batch counter
        """
        
        pass
    
    def get_Asgp4PosDelta(self) -> int:
        """
        A getter for the 'TlmHil::Asgp4PosDelta' structure field
        
        Average position error between GNSS and ASGP4
        """
        
        pass
    
    def get_Rwl0MeasSpeed(self) -> float:
        """
        A getter for the 'TlmHil::Rwl0MeasSpeed' structure field
        
        RWL0 speed measurement
        """
        
        pass
    
    def get_Rwl1MeasSpeed(self) -> float:
        """
        A getter for the 'TlmHil::Rwl1MeasSpeed' structure field
        
        RWL1 speed measurement
        """
        
        pass
    
    def get_Rwl2MeasSpeed(self) -> float:
        """
        A getter for the 'TlmHil::Rwl2MeasSpeed' structure field
        
        RWL2 speed measurement
        """
        
        pass
    
    def get_Rwl3MeasSpeed(self) -> float:
        """
        A getter for the 'TlmHil::Rwl3MeasSpeed' structure field
        
        RWL3 speed measurement
        """
        
        pass
    
    def get_Rwl0MeasValid(self) -> int:
        """
        A getter for the 'TlmHil::Rwl0MeasValid' structure field
        
        RWL0 measurement valid flag
        """
        
        pass
    
    def get_Rwl1MeasValid(self) -> int:
        """
        A getter for the 'TlmHil::Rwl1MeasValid' structure field
        
        RWL1 measurement valid flag
        """
        
        pass
    
    def get_Rwl2MeasValid(self) -> int:
        """
        A getter for the 'TlmHil::Rwl2MeasValid' structure field
        
        RWL2 measurement valid flag
        """
        
        pass
    
    def get_Rwl3MeasValid(self) -> int:
        """
        A getter for the 'TlmHil::Rwl3MeasValid' structure field
        
        RWL3 measurement valid flag
        """
        
        pass
    
    def get_FmcStage(self) -> CubeComputerControlProgram8_FmcStage:
        """
        A getter for the 'TlmHil::FmcStage' structure field
        
        Current FMC Stage
        """
        
        pass

def TlmHil_make_from_buf(buf : bytes) -> TlmHil:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmHssCubeSenseEarthRaw:
    """
    A Python class to represent struct objects of type 'TlmHssCubeSenseEarthRaw'
    
    Parameter structure for interface TlmHssCubeSenseEarthRaw
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, double__Hss0RawElev : float, double__Hss0RawRot : float, e__CubeComputerControlProgram8_EarthCaptureResult__Hss0CaptureResult : CubeComputerControlProgram8_EarthCaptureResult, e__CubeComputerControlProgram8_EarthDetectResult__Hss0DetectionResult : CubeComputerControlProgram8_EarthDetectResult, double__Hss1RawElev : float, double__Hss1RawRot : float, e__CubeComputerControlProgram8_EarthCaptureResult__Hss1CaptureResult : CubeComputerControlProgram8_EarthCaptureResult, e__CubeComputerControlProgram8_EarthDetectResult__Hss1DetectionResult : CubeComputerControlProgram8_EarthDetectResult, bool__Hss0IsValid : int, bool__Hss1IsValid : int) -> None:
        """
        Struct 'TlmHssCubeSenseEarthRaw' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        double__Hss0RawElev [1] : float
            HSS0 raw elevation angle
        double__Hss0RawRot [1] : float
            HSS0 raw rotation angle
        e__CubeComputerControlProgram8_EarthCaptureResult__Hss0CaptureResult [1] : CubeComputerControlProgram8_EarthCaptureResult
            HSS0 capture result
        e__CubeComputerControlProgram8_EarthDetectResult__Hss0DetectionResult [1] : CubeComputerControlProgram8_EarthDetectResult
            HSS0 detection result
        double__Hss1RawElev [1] : float
            HSS1 raw elevation angle
        double__Hss1RawRot [1] : float
            HSS1 raw rotation angle
        e__CubeComputerControlProgram8_EarthCaptureResult__Hss1CaptureResult [1] : CubeComputerControlProgram8_EarthCaptureResult
            HSS1 capture result
        e__CubeComputerControlProgram8_EarthDetectResult__Hss1DetectionResult [1] : CubeComputerControlProgram8_EarthDetectResult
            HSS1 detection result
        bool__Hss0IsValid [1] : int
            HSS0 valid flag
        bool__Hss1IsValid [1] : int
            HSS1 valid flag
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmHssCubeSenseEarthRaw::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmHssCubeSenseEarthRaw::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_Hss0RawElev(self) -> float:
        """
        A getter for the 'TlmHssCubeSenseEarthRaw::Hss0RawElev' structure field
        
        HSS0 raw elevation angle
        """
        
        pass
    
    def get_Hss0RawRot(self) -> float:
        """
        A getter for the 'TlmHssCubeSenseEarthRaw::Hss0RawRot' structure field
        
        HSS0 raw rotation angle
        """
        
        pass
    
    def get_Hss0CaptureResult(self) -> CubeComputerControlProgram8_EarthCaptureResult:
        """
        A getter for the 'TlmHssCubeSenseEarthRaw::Hss0CaptureResult' structure field
        
        HSS0 capture result
        """
        
        pass
    
    def get_Hss0DetectionResult(self) -> CubeComputerControlProgram8_EarthDetectResult:
        """
        A getter for the 'TlmHssCubeSenseEarthRaw::Hss0DetectionResult' structure field
        
        HSS0 detection result
        """
        
        pass
    
    def get_Hss1RawElev(self) -> float:
        """
        A getter for the 'TlmHssCubeSenseEarthRaw::Hss1RawElev' structure field
        
        HSS1 raw elevation angle
        """
        
        pass
    
    def get_Hss1RawRot(self) -> float:
        """
        A getter for the 'TlmHssCubeSenseEarthRaw::Hss1RawRot' structure field
        
        HSS1 raw rotation angle
        """
        
        pass
    
    def get_Hss1CaptureResult(self) -> CubeComputerControlProgram8_EarthCaptureResult:
        """
        A getter for the 'TlmHssCubeSenseEarthRaw::Hss1CaptureResult' structure field
        
        HSS1 capture result
        """
        
        pass
    
    def get_Hss1DetectionResult(self) -> CubeComputerControlProgram8_EarthDetectResult:
        """
        A getter for the 'TlmHssCubeSenseEarthRaw::Hss1DetectionResult' structure field
        
        HSS1 detection result
        """
        
        pass
    
    def get_Hss0IsValid(self) -> int:
        """
        A getter for the 'TlmHssCubeSenseEarthRaw::Hss0IsValid' structure field
        
        HSS0 valid flag
        """
        
        pass
    
    def get_Hss1IsValid(self) -> int:
        """
        A getter for the 'TlmHssCubeSenseEarthRaw::Hss1IsValid' structure field
        
        HSS1 valid flag
        """
        
        pass

def TlmHssCubeSenseEarthRaw_make_from_buf(buf : bytes) -> TlmHssCubeSenseEarthRaw:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class TlmStrPst3sRaw:
    """
    A Python class to represent struct objects of type 'TlmStrPst3sRaw'
    
    Parameter structure for interface TlmStrPst3sRaw
    """

    def __init__(self, uint32__TimeSeconds : int, uint32__TimeNs : int, e__CubeComputerControlProgram8_Pst3sVersion__Str0Pst3sVersion : CubeComputerControlProgram8_Pst3sVersion, float__Str0Quat1 : float, float__Str0Quat2 : float, float__Str0Quat3 : float, float__Str0Quat4 : float, float__Str0AngVelX : float, float__Str0AngVelY : float, float__Str0AngVelZ : float, e__CubeComputerControlProgram8_Pst3sRateQuality__Str0RateQuality : CubeComputerControlProgram8_Pst3sRateQuality, uint32__Str0UnixSeconds : int, float__Str0UnixSecondsDecimal : float, int8__Str0Temperature : int, uint8__Str0ImageExposure : int, uint8__Str0ImageThreshold : int, uint8__Str0BackGroundValues : int, uint8__Str0InternalProcessCode : int, e__CubeComputerControlProgram8_Pst3sSelfTestResult__Str0CmosChipIdResult : CubeComputerControlProgram8_Pst3sSelfTestResult, e__CubeComputerControlProgram8_Pst3sSelfTestResult__Str0FpgaMRamResult : CubeComputerControlProgram8_Pst3sSelfTestResult, uint8__Str0NumberOfExtractedStars : int, e__CubeComputerControlProgram8_Pst3sOperatingModes__Str0OperatingMode : CubeComputerControlProgram8_Pst3sOperatingModes, uint8__Str0ImagingGain : int, uint8__Str0MinNavigationStars : int, e__CubeComputerControlProgram8_Pst3sDataValid__Str0DataValid : CubeComputerControlProgram8_Pst3sDataValid, e__CubeComputerControlProgram8_Pst3sExtImageState__Str0ExtImageState : CubeComputerControlProgram8_Pst3sExtImageState, uint8__Str0IdentifiedStars : int, uint8__Str0DeviceNumber : int, uint8__Str0SoftwareVersion : int, uint8__Str0EdacErrorCount : int, uint32__Str0ImageFrameNumber : int, e__CubeComputerControlProgram8_Pst3sDynamicMode__Str0DynamicMode : CubeComputerControlProgram8_Pst3sDynamicMode, e__CubeComputerControlProgram8_Pst3sSaaWorkingMode__Str0SaaMode : CubeComputerControlProgram8_Pst3sSaaWorkingMode, uint8__Str0SaaThreshold : int, e__CubeComputerControlProgram8_Pst3sQuaternionFilteringGetState__Str0QuaternionFilteringState : CubeComputerControlProgram8_Pst3sQuaternionFilteringGetState, uint8__Str0FourStarCaptureThreshold : int, uint8__Str0TrackingThreshold : int, bool__Str0EdacSwitch : int, e__CubeComputerControlProgram8_Pst3sVersion__Str1Pst3sVersion : CubeComputerControlProgram8_Pst3sVersion, float__Str1Quat1 : float, float__Str1Quat2 : float, float__Str1Quat3 : float, float__Str1Quat4 : float, float__Str1AngVelX : float, float__Str1AngVelY : float, float__Str1AngVelZ : float, e__CubeComputerControlProgram8_Pst3sRateQuality__Str1RateQuality : CubeComputerControlProgram8_Pst3sRateQuality, uint32__Str1UnixSeconds : int, float__Str1UnixSecondsDecimal : float, int8__Str1Temperature : int, uint8__Str1ImageExposure : int, uint8__Str1ImageThreshold : int, uint8__Str1BackGroundValues : int, uint8__Str1InternalProcessCode : int, e__CubeComputerControlProgram8_Pst3sSelfTestResult__Str1CmosChipIdResult : CubeComputerControlProgram8_Pst3sSelfTestResult, e__CubeComputerControlProgram8_Pst3sSelfTestResult__Str1FpgaMRamResult : CubeComputerControlProgram8_Pst3sSelfTestResult, uint8__Str1NumberOfExtractedStars : int, e__CubeComputerControlProgram8_Pst3sOperatingModes__Str1OperatingMode : CubeComputerControlProgram8_Pst3sOperatingModes, uint8__Str1ImagingGain : int, uint8__Str1MinNavigationStars : int, e__CubeComputerControlProgram8_Pst3sDataValid__Str1DataValid : CubeComputerControlProgram8_Pst3sDataValid, e__CubeComputerControlProgram8_Pst3sExtImageState__Str1ExtImageState : CubeComputerControlProgram8_Pst3sExtImageState, uint8__Str1IdentifiedStars : int, uint8__Str1DeviceNumber : int, uint8__Str1SoftwareVersion : int, uint8__Str1EdacErrorCount : int, uint32__Str1ImageFrameNumber : int, e__CubeComputerControlProgram8_Pst3sDynamicMode__Str1DynamicMode : CubeComputerControlProgram8_Pst3sDynamicMode, e__CubeComputerControlProgram8_Pst3sSaaWorkingMode__Str1SaaMode : CubeComputerControlProgram8_Pst3sSaaWorkingMode, uint8__Str1SaaThreshold : int, e__CubeComputerControlProgram8_Pst3sQuaternionFilteringGetState__Str1QuaternionFilteringState : CubeComputerControlProgram8_Pst3sQuaternionFilteringGetState, uint8__Str1FourStarCaptureThreshold : int, uint8__Str1TrackingThreshold : int, bool__Str1EdacSwitch : int) -> None:
        """
        Struct 'TlmStrPst3sRaw' constructor
        
        Attributes
        ---------
        uint32__TimeSeconds [1] : int
            Unix time integer seconds
        uint32__TimeNs [1] : int
            Unix time fraction nanoseconds
        e__CubeComputerControlProgram8_Pst3sVersion__Str0Pst3sVersion [1] : CubeComputerControlProgram8_Pst3sVersion
            STR0 PST3S Version
        float__Str0Quat1 [1] : float
            PST3S Quaternion 1
        float__Str0Quat2 [1] : float
            PST3S Quaternion 2
        float__Str0Quat3 [1] : float
            PST3S Quaternion 3
        float__Str0Quat4 [1] : float
            PST3S Quaternion 4
        float__Str0AngVelX [1] : float
            PST3S Angular Valocity X
        float__Str0AngVelY [1] : float
            PST3S Angular Valocity Y
        float__Str0AngVelZ [1] : float
            PST3S Angular Valocity Z
        e__CubeComputerControlProgram8_Pst3sRateQuality__Str0RateQuality [1] : CubeComputerControlProgram8_Pst3sRateQuality
            PST3S Rate Quality
        uint32__Str0UnixSeconds [1] : int
            PST3S Unix Seconds
        float__Str0UnixSecondsDecimal [1] : float
            PST3S Unix Seconds Decimal
        int8__Str0Temperature [1] : int
            PST3S Temperature
        uint8__Str0ImageExposure [1] : int
            PST3S Image Exposure
        uint8__Str0ImageThreshold [1] : int
            PST3S Image Threshold
        uint8__Str0BackGroundValues [1] : int
            PST3S BackGround Values
        uint8__Str0InternalProcessCode [1] : int
            PST3S Internal Process Code
        e__CubeComputerControlProgram8_Pst3sSelfTestResult__Str0CmosChipIdResult [1] : CubeComputerControlProgram8_Pst3sSelfTestResult
            PST3S CMOS Chip ID Self-test Result
        e__CubeComputerControlProgram8_Pst3sSelfTestResult__Str0FpgaMRamResult [1] : CubeComputerControlProgram8_Pst3sSelfTestResult
            PST3S FPGA MRAM Self-test Result
        uint8__Str0NumberOfExtractedStars [1] : int
            PST3S Number of Extracted Stars
        e__CubeComputerControlProgram8_Pst3sOperatingModes__Str0OperatingMode [1] : CubeComputerControlProgram8_Pst3sOperatingModes
            PST3S Operating Mode
        uint8__Str0ImagingGain [1] : int
            PST3S Imaging Gain
        uint8__Str0MinNavigationStars [1] : int
            PST3S Minimum Navigation Stars When Quaternion is Valid
        e__CubeComputerControlProgram8_Pst3sDataValid__Str0DataValid [1] : CubeComputerControlProgram8_Pst3sDataValid
            PST3S Data Valid
        e__CubeComputerControlProgram8_Pst3sExtImageState__Str0ExtImageState [1] : CubeComputerControlProgram8_Pst3sExtImageState
            PST3S External Image State
        uint8__Str0IdentifiedStars [1] : int
            PST3S Number of Identified Stars
        uint8__Str0DeviceNumber [1] : int
            PST3S Device Number
        uint8__Str0SoftwareVersion [1] : int
            PST3S Software Version
        uint8__Str0EdacErrorCount [1] : int
            PST3S EDAC Error Count
        uint32__Str0ImageFrameNumber [1] : int
            PST3S Image Frame Number
        e__CubeComputerControlProgram8_Pst3sDynamicMode__Str0DynamicMode [1] : CubeComputerControlProgram8_Pst3sDynamicMode
            PST3S Dynamic Mode
        e__CubeComputerControlProgram8_Pst3sSaaWorkingMode__Str0SaaMode [1] : CubeComputerControlProgram8_Pst3sSaaWorkingMode
            PST3S SAA Mode
        uint8__Str0SaaThreshold [1] : int
            PST3S SAA Threshold
        e__CubeComputerControlProgram8_Pst3sQuaternionFilteringGetState__Str0QuaternionFilteringState [1] : CubeComputerControlProgram8_Pst3sQuaternionFilteringGetState
            PST3S Quaternion Filtering State
        uint8__Str0FourStarCaptureThreshold [1] : int
            PST3S Four Star Capture Threshold
        uint8__Str0TrackingThreshold [1] : int
            PST3S Tracking Threshold
        bool__Str0EdacSwitch [1] : int
            PST3S EDAC Enabled/Disabled
        e__CubeComputerControlProgram8_Pst3sVersion__Str1Pst3sVersion [1] : CubeComputerControlProgram8_Pst3sVersion
            STR1 PST3S Version
        float__Str1Quat1 [1] : float
            PST3S Quaternion 1
        float__Str1Quat2 [1] : float
            PST3S Quaternion 2
        float__Str1Quat3 [1] : float
            PST3S Quaternion 3
        float__Str1Quat4 [1] : float
            PST3S Quaternion 4
        float__Str1AngVelX [1] : float
            PST3S Angular Valocity X
        float__Str1AngVelY [1] : float
            PST3S Angular Valocity Y
        float__Str1AngVelZ [1] : float
            PST3S Angular Valocity Z
        e__CubeComputerControlProgram8_Pst3sRateQuality__Str1RateQuality [1] : CubeComputerControlProgram8_Pst3sRateQuality
            PST3S Rate Quality
        uint32__Str1UnixSeconds [1] : int
            PST3S Unix Seconds
        float__Str1UnixSecondsDecimal [1] : float
            PST3S Unix Seconds Decimal
        int8__Str1Temperature [1] : int
            PST3S Temperature
        uint8__Str1ImageExposure [1] : int
            PST3S Image Exposure
        uint8__Str1ImageThreshold [1] : int
            PST3S Image Threshold
        uint8__Str1BackGroundValues [1] : int
            PST3S BackGround Values
        uint8__Str1InternalProcessCode [1] : int
            PST3S Internal Process Code
        e__CubeComputerControlProgram8_Pst3sSelfTestResult__Str1CmosChipIdResult [1] : CubeComputerControlProgram8_Pst3sSelfTestResult
            PST3S CMOS Chip ID Self-test Result
        e__CubeComputerControlProgram8_Pst3sSelfTestResult__Str1FpgaMRamResult [1] : CubeComputerControlProgram8_Pst3sSelfTestResult
            PST3S FPGA MRAM Self-test Result
        uint8__Str1NumberOfExtractedStars [1] : int
            PST3S Number of Extracted Stars
        e__CubeComputerControlProgram8_Pst3sOperatingModes__Str1OperatingMode [1] : CubeComputerControlProgram8_Pst3sOperatingModes
            PST3S Operating Mode
        uint8__Str1ImagingGain [1] : int
            PST3S Imaging Gain
        uint8__Str1MinNavigationStars [1] : int
            PST3S Minimum Navigation Stars When Quaternion is Valid
        e__CubeComputerControlProgram8_Pst3sDataValid__Str1DataValid [1] : CubeComputerControlProgram8_Pst3sDataValid
            PST3S Data Valid
        e__CubeComputerControlProgram8_Pst3sExtImageState__Str1ExtImageState [1] : CubeComputerControlProgram8_Pst3sExtImageState
            PST3S External Image State
        uint8__Str1IdentifiedStars [1] : int
            PST3S Number of Identified Stars
        uint8__Str1DeviceNumber [1] : int
            PST3S Device Number
        uint8__Str1SoftwareVersion [1] : int
            PST3S Software Version
        uint8__Str1EdacErrorCount [1] : int
            PST3S EDAC Error Count
        uint32__Str1ImageFrameNumber [1] : int
            PST3S Image Frame Number
        e__CubeComputerControlProgram8_Pst3sDynamicMode__Str1DynamicMode [1] : CubeComputerControlProgram8_Pst3sDynamicMode
            PST3S Dynamic Mode
        e__CubeComputerControlProgram8_Pst3sSaaWorkingMode__Str1SaaMode [1] : CubeComputerControlProgram8_Pst3sSaaWorkingMode
            PST3S SAA Mode
        uint8__Str1SaaThreshold [1] : int
            PST3S SAA Threshold
        e__CubeComputerControlProgram8_Pst3sQuaternionFilteringGetState__Str1QuaternionFilteringState [1] : CubeComputerControlProgram8_Pst3sQuaternionFilteringGetState
            PST3S Quaternion Filtering State
        uint8__Str1FourStarCaptureThreshold [1] : int
            PST3S Four Star Capture Threshold
        uint8__Str1TrackingThreshold [1] : int
            PST3S Tracking Threshold
        bool__Str1EdacSwitch [1] : int
            PST3S EDAC Enabled/Disabled
        """
        
        pass
        
    def get_TimeSeconds(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::TimeSeconds' structure field
        
        Unix time integer seconds
        """
        
        pass
    
    def get_TimeNs(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::TimeNs' structure field
        
        Unix time fraction nanoseconds
        """
        
        pass
    
    def get_Str0Pst3sVersion(self) -> CubeComputerControlProgram8_Pst3sVersion:
        """
        A getter for the 'TlmStrPst3sRaw::Str0Pst3sVersion' structure field
        
        STR0 PST3S Version
        """
        
        pass
    
    def get_Str0Quat1(self) -> float:
        """
        A getter for the 'TlmStrPst3sRaw::Str0Quat1' structure field
        
        PST3S Quaternion 1
        """
        
        pass
    
    def get_Str0Quat2(self) -> float:
        """
        A getter for the 'TlmStrPst3sRaw::Str0Quat2' structure field
        
        PST3S Quaternion 2
        """
        
        pass
    
    def get_Str0Quat3(self) -> float:
        """
        A getter for the 'TlmStrPst3sRaw::Str0Quat3' structure field
        
        PST3S Quaternion 3
        """
        
        pass
    
    def get_Str0Quat4(self) -> float:
        """
        A getter for the 'TlmStrPst3sRaw::Str0Quat4' structure field
        
        PST3S Quaternion 4
        """
        
        pass
    
    def get_Str0AngVelX(self) -> float:
        """
        A getter for the 'TlmStrPst3sRaw::Str0AngVelX' structure field
        
        PST3S Angular Valocity X
        """
        
        pass
    
    def get_Str0AngVelY(self) -> float:
        """
        A getter for the 'TlmStrPst3sRaw::Str0AngVelY' structure field
        
        PST3S Angular Valocity Y
        """
        
        pass
    
    def get_Str0AngVelZ(self) -> float:
        """
        A getter for the 'TlmStrPst3sRaw::Str0AngVelZ' structure field
        
        PST3S Angular Valocity Z
        """
        
        pass
    
    def get_Str0RateQuality(self) -> CubeComputerControlProgram8_Pst3sRateQuality:
        """
        A getter for the 'TlmStrPst3sRaw::Str0RateQuality' structure field
        
        PST3S Rate Quality
        """
        
        pass
    
    def get_Str0UnixSeconds(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str0UnixSeconds' structure field
        
        PST3S Unix Seconds
        """
        
        pass
    
    def get_Str0UnixSecondsDecimal(self) -> float:
        """
        A getter for the 'TlmStrPst3sRaw::Str0UnixSecondsDecimal' structure field
        
        PST3S Unix Seconds Decimal
        """
        
        pass
    
    def get_Str0Temperature(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str0Temperature' structure field
        
        PST3S Temperature
        """
        
        pass
    
    def get_Str0ImageExposure(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str0ImageExposure' structure field
        
        PST3S Image Exposure
        """
        
        pass
    
    def get_Str0ImageThreshold(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str0ImageThreshold' structure field
        
        PST3S Image Threshold
        """
        
        pass
    
    def get_Str0BackGroundValues(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str0BackGroundValues' structure field
        
        PST3S BackGround Values
        """
        
        pass
    
    def get_Str0InternalProcessCode(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str0InternalProcessCode' structure field
        
        PST3S Internal Process Code
        """
        
        pass
    
    def get_Str0CmosChipIdResult(self) -> CubeComputerControlProgram8_Pst3sSelfTestResult:
        """
        A getter for the 'TlmStrPst3sRaw::Str0CmosChipIdResult' structure field
        
        PST3S CMOS Chip ID Self-test Result
        """
        
        pass
    
    def get_Str0FpgaMRamResult(self) -> CubeComputerControlProgram8_Pst3sSelfTestResult:
        """
        A getter for the 'TlmStrPst3sRaw::Str0FpgaMRamResult' structure field
        
        PST3S FPGA MRAM Self-test Result
        """
        
        pass
    
    def get_Str0NumberOfExtractedStars(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str0NumberOfExtractedStars' structure field
        
        PST3S Number of Extracted Stars
        """
        
        pass
    
    def get_Str0OperatingMode(self) -> CubeComputerControlProgram8_Pst3sOperatingModes:
        """
        A getter for the 'TlmStrPst3sRaw::Str0OperatingMode' structure field
        
        PST3S Operating Mode
        """
        
        pass
    
    def get_Str0ImagingGain(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str0ImagingGain' structure field
        
        PST3S Imaging Gain
        """
        
        pass
    
    def get_Str0MinNavigationStars(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str0MinNavigationStars' structure field
        
        PST3S Minimum Navigation Stars When Quaternion is Valid
        """
        
        pass
    
    def get_Str0DataValid(self) -> CubeComputerControlProgram8_Pst3sDataValid:
        """
        A getter for the 'TlmStrPst3sRaw::Str0DataValid' structure field
        
        PST3S Data Valid
        """
        
        pass
    
    def get_Str0ExtImageState(self) -> CubeComputerControlProgram8_Pst3sExtImageState:
        """
        A getter for the 'TlmStrPst3sRaw::Str0ExtImageState' structure field
        
        PST3S External Image State
        """
        
        pass
    
    def get_Str0IdentifiedStars(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str0IdentifiedStars' structure field
        
        PST3S Number of Identified Stars
        """
        
        pass
    
    def get_Str0DeviceNumber(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str0DeviceNumber' structure field
        
        PST3S Device Number
        """
        
        pass
    
    def get_Str0SoftwareVersion(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str0SoftwareVersion' structure field
        
        PST3S Software Version
        """
        
        pass
    
    def get_Str0EdacErrorCount(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str0EdacErrorCount' structure field
        
        PST3S EDAC Error Count
        """
        
        pass
    
    def get_Str0ImageFrameNumber(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str0ImageFrameNumber' structure field
        
        PST3S Image Frame Number
        """
        
        pass
    
    def get_Str0DynamicMode(self) -> CubeComputerControlProgram8_Pst3sDynamicMode:
        """
        A getter for the 'TlmStrPst3sRaw::Str0DynamicMode' structure field
        
        PST3S Dynamic Mode
        """
        
        pass
    
    def get_Str0SaaMode(self) -> CubeComputerControlProgram8_Pst3sSaaWorkingMode:
        """
        A getter for the 'TlmStrPst3sRaw::Str0SaaMode' structure field
        
        PST3S SAA Mode
        """
        
        pass
    
    def get_Str0SaaThreshold(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str0SaaThreshold' structure field
        
        PST3S SAA Threshold
        """
        
        pass
    
    def get_Str0QuaternionFilteringState(self) -> CubeComputerControlProgram8_Pst3sQuaternionFilteringGetState:
        """
        A getter for the 'TlmStrPst3sRaw::Str0QuaternionFilteringState' structure field
        
        PST3S Quaternion Filtering State
        """
        
        pass
    
    def get_Str0FourStarCaptureThreshold(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str0FourStarCaptureThreshold' structure field
        
        PST3S Four Star Capture Threshold
        """
        
        pass
    
    def get_Str0TrackingThreshold(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str0TrackingThreshold' structure field
        
        PST3S Tracking Threshold
        """
        
        pass
    
    def get_Str0EdacSwitch(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str0EdacSwitch' structure field
        
        PST3S EDAC Enabled/Disabled
        """
        
        pass
    
    def get_Str1Pst3sVersion(self) -> CubeComputerControlProgram8_Pst3sVersion:
        """
        A getter for the 'TlmStrPst3sRaw::Str1Pst3sVersion' structure field
        
        STR1 PST3S Version
        """
        
        pass
    
    def get_Str1Quat1(self) -> float:
        """
        A getter for the 'TlmStrPst3sRaw::Str1Quat1' structure field
        
        PST3S Quaternion 1
        """
        
        pass
    
    def get_Str1Quat2(self) -> float:
        """
        A getter for the 'TlmStrPst3sRaw::Str1Quat2' structure field
        
        PST3S Quaternion 2
        """
        
        pass
    
    def get_Str1Quat3(self) -> float:
        """
        A getter for the 'TlmStrPst3sRaw::Str1Quat3' structure field
        
        PST3S Quaternion 3
        """
        
        pass
    
    def get_Str1Quat4(self) -> float:
        """
        A getter for the 'TlmStrPst3sRaw::Str1Quat4' structure field
        
        PST3S Quaternion 4
        """
        
        pass
    
    def get_Str1AngVelX(self) -> float:
        """
        A getter for the 'TlmStrPst3sRaw::Str1AngVelX' structure field
        
        PST3S Angular Valocity X
        """
        
        pass
    
    def get_Str1AngVelY(self) -> float:
        """
        A getter for the 'TlmStrPst3sRaw::Str1AngVelY' structure field
        
        PST3S Angular Valocity Y
        """
        
        pass
    
    def get_Str1AngVelZ(self) -> float:
        """
        A getter for the 'TlmStrPst3sRaw::Str1AngVelZ' structure field
        
        PST3S Angular Valocity Z
        """
        
        pass
    
    def get_Str1RateQuality(self) -> CubeComputerControlProgram8_Pst3sRateQuality:
        """
        A getter for the 'TlmStrPst3sRaw::Str1RateQuality' structure field
        
        PST3S Rate Quality
        """
        
        pass
    
    def get_Str1UnixSeconds(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str1UnixSeconds' structure field
        
        PST3S Unix Seconds
        """
        
        pass
    
    def get_Str1UnixSecondsDecimal(self) -> float:
        """
        A getter for the 'TlmStrPst3sRaw::Str1UnixSecondsDecimal' structure field
        
        PST3S Unix Seconds Decimal
        """
        
        pass
    
    def get_Str1Temperature(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str1Temperature' structure field
        
        PST3S Temperature
        """
        
        pass
    
    def get_Str1ImageExposure(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str1ImageExposure' structure field
        
        PST3S Image Exposure
        """
        
        pass
    
    def get_Str1ImageThreshold(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str1ImageThreshold' structure field
        
        PST3S Image Threshold
        """
        
        pass
    
    def get_Str1BackGroundValues(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str1BackGroundValues' structure field
        
        PST3S BackGround Values
        """
        
        pass
    
    def get_Str1InternalProcessCode(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str1InternalProcessCode' structure field
        
        PST3S Internal Process Code
        """
        
        pass
    
    def get_Str1CmosChipIdResult(self) -> CubeComputerControlProgram8_Pst3sSelfTestResult:
        """
        A getter for the 'TlmStrPst3sRaw::Str1CmosChipIdResult' structure field
        
        PST3S CMOS Chip ID Self-test Result
        """
        
        pass
    
    def get_Str1FpgaMRamResult(self) -> CubeComputerControlProgram8_Pst3sSelfTestResult:
        """
        A getter for the 'TlmStrPst3sRaw::Str1FpgaMRamResult' structure field
        
        PST3S FPGA MRAM Self-test Result
        """
        
        pass
    
    def get_Str1NumberOfExtractedStars(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str1NumberOfExtractedStars' structure field
        
        PST3S Number of Extracted Stars
        """
        
        pass
    
    def get_Str1OperatingMode(self) -> CubeComputerControlProgram8_Pst3sOperatingModes:
        """
        A getter for the 'TlmStrPst3sRaw::Str1OperatingMode' structure field
        
        PST3S Operating Mode
        """
        
        pass
    
    def get_Str1ImagingGain(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str1ImagingGain' structure field
        
        PST3S Imaging Gain
        """
        
        pass
    
    def get_Str1MinNavigationStars(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str1MinNavigationStars' structure field
        
        PST3S Minimum Navigation Stars When Quaternion is Valid
        """
        
        pass
    
    def get_Str1DataValid(self) -> CubeComputerControlProgram8_Pst3sDataValid:
        """
        A getter for the 'TlmStrPst3sRaw::Str1DataValid' structure field
        
        PST3S Data Valid
        """
        
        pass
    
    def get_Str1ExtImageState(self) -> CubeComputerControlProgram8_Pst3sExtImageState:
        """
        A getter for the 'TlmStrPst3sRaw::Str1ExtImageState' structure field
        
        PST3S External Image State
        """
        
        pass
    
    def get_Str1IdentifiedStars(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str1IdentifiedStars' structure field
        
        PST3S Number of Identified Stars
        """
        
        pass
    
    def get_Str1DeviceNumber(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str1DeviceNumber' structure field
        
        PST3S Device Number
        """
        
        pass
    
    def get_Str1SoftwareVersion(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str1SoftwareVersion' structure field
        
        PST3S Software Version
        """
        
        pass
    
    def get_Str1EdacErrorCount(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str1EdacErrorCount' structure field
        
        PST3S EDAC Error Count
        """
        
        pass
    
    def get_Str1ImageFrameNumber(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str1ImageFrameNumber' structure field
        
        PST3S Image Frame Number
        """
        
        pass
    
    def get_Str1DynamicMode(self) -> CubeComputerControlProgram8_Pst3sDynamicMode:
        """
        A getter for the 'TlmStrPst3sRaw::Str1DynamicMode' structure field
        
        PST3S Dynamic Mode
        """
        
        pass
    
    def get_Str1SaaMode(self) -> CubeComputerControlProgram8_Pst3sSaaWorkingMode:
        """
        A getter for the 'TlmStrPst3sRaw::Str1SaaMode' structure field
        
        PST3S SAA Mode
        """
        
        pass
    
    def get_Str1SaaThreshold(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str1SaaThreshold' structure field
        
        PST3S SAA Threshold
        """
        
        pass
    
    def get_Str1QuaternionFilteringState(self) -> CubeComputerControlProgram8_Pst3sQuaternionFilteringGetState:
        """
        A getter for the 'TlmStrPst3sRaw::Str1QuaternionFilteringState' structure field
        
        PST3S Quaternion Filtering State
        """
        
        pass
    
    def get_Str1FourStarCaptureThreshold(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str1FourStarCaptureThreshold' structure field
        
        PST3S Four Star Capture Threshold
        """
        
        pass
    
    def get_Str1TrackingThreshold(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str1TrackingThreshold' structure field
        
        PST3S Tracking Threshold
        """
        
        pass
    
    def get_Str1EdacSwitch(self) -> int:
        """
        A getter for the 'TlmStrPst3sRaw::Str1EdacSwitch' structure field
        
        PST3S EDAC Enabled/Disabled
        """
        
        pass

def TlmStrPst3sRaw_make_from_buf(buf : bytes) -> TlmStrPst3sRaw:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class FileTransferSetup:
    """
    A Python class to represent struct objects of type 'FileTransferSetup'
    
    Parameter structure for interface FileTransferSetup
    """

    def __init__(self, e__CubeComputerControlProgram8_FtpOpCode__OpCode : CubeComputerControlProgram8_FtpOpCode, e__CubeComputerControlProgram8_FtpFiles__File : CubeComputerControlProgram8_FtpFiles, e__CommonFrameworkTypes1_NodeType__Node : CommonFrameworkTypes1_NodeType, uint32__SerialInt : int, e__CommonFrameworkTypes1_ProgramType__Program : CommonFrameworkTypes1_ProgramType, uint32__FileSize : int, e__CubeComputerControlProgram8_NodePort__ForcePort : CubeComputerControlProgram8_NodePort, a__uint8__128__MetaData : list[int]) -> None:
        """
        Struct 'FileTransferSetup' constructor
        
        Attributes
        ---------
        e__CubeComputerControlProgram8_FtpOpCode__OpCode [1] : CubeComputerControlProgram8_FtpOpCode
            Operation to perform
        e__CubeComputerControlProgram8_FtpFiles__File [1] : CubeComputerControlProgram8_FtpFiles
            File to target
        e__CommonFrameworkTypes1_NodeType__Node [1] : CommonFrameworkTypes1_NodeType
            OpCode = Upgrade: Node to upgrade in conjunction with SerialInt
        uint32__SerialInt [1] : int
            OpCode = Upgrade: Serial Number Integer of node to upgrade in conjunction with Node
        e__CommonFrameworkTypes1_ProgramType__Program [1] : CommonFrameworkTypes1_ProgramType
            OpCode = Upgrade: The Program Type to upgrade with
        uint32__FileSize [1] : int
            Size of target file: Only used to confirm setup.
        e__CubeComputerControlProgram8_NodePort__ForcePort [1] : CubeComputerControlProgram8_NodePort
            OpCode = Upgrade: Force that the node on this port is upgraded In the event that the node is not discoverable.
        a__uint8__128__MetaData [128] : list[int]
            CubeSpace File Meta Data. May be less than allocated size (padding required)
        """
        
        pass
        
    def get_OpCode(self) -> CubeComputerControlProgram8_FtpOpCode:
        """
        A getter for the 'FileTransferSetup::OpCode' structure field
        
        Operation to perform
        """
        
        pass
    
    def get_File(self) -> CubeComputerControlProgram8_FtpFiles:
        """
        A getter for the 'FileTransferSetup::File' structure field
        
        File to target
        """
        
        pass
    
    def get_Node(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'FileTransferSetup::Node' structure field
        
        OpCode = Upgrade: Node to upgrade in conjunction with SerialInt
        """
        
        pass
    
    def get_SerialInt(self) -> int:
        """
        A getter for the 'FileTransferSetup::SerialInt' structure field
        
        OpCode = Upgrade: Serial Number Integer of node to upgrade in conjunction with Node
        """
        
        pass
    
    def get_Program(self) -> CommonFrameworkTypes1_ProgramType:
        """
        A getter for the 'FileTransferSetup::Program' structure field
        
        OpCode = Upgrade: The Program Type to upgrade with
        """
        
        pass
    
    def get_FileSize(self) -> int:
        """
        A getter for the 'FileTransferSetup::FileSize' structure field
        
        Size of target file: Only used to confirm setup.
        """
        
        pass
    
    def get_ForcePort(self) -> CubeComputerControlProgram8_NodePort:
        """
        A getter for the 'FileTransferSetup::ForcePort' structure field
        
        OpCode = Upgrade: Force that the node on this port is upgraded In the event that the node is not discoverable.
        """
        
        pass
    
    def get_MetaData(self) -> list[int]:
        """
        A getter for the 'FileTransferSetup::MetaData' structure field
        
        CubeSpace File Meta Data. May be less than allocated size (padding required)
        """
        
        pass

def FileTransferSetup_make_from_buf(buf : bytes) -> FileTransferSetup:
    """
    Struct object constructor function which accepts a bytes object and can be used to create a structure instance
    directly out of raw bytes
    """
    
    pass
        
class FileInfo:
    """
    A Python class to represent struct objects of type 'FileInfo'
    
    Parameter structure for interface FileInfo
    """

    def __init__(self, e__CubeComputerControlProgram8_FtpFiles__File : CubeComputerControlProgram8_FtpFiles, e__CubeComputerControlProgram8_FtpBackend__Backend : CubeComputerControlProgram8_FtpBackend, e__CubeComputerControlProgram8_FtpFileType__Type : CubeComputerControlProgram8_FtpFileType, uint32__Size : int, uint32__AllocSize : int, uint32__VectTblOffset : int, uint32__UnixTimeSeconds : int, uint32__UnixTimeNanoSeconds : int, uint32__Crc : int, a__uint8__32__Component : list[int], a__uint8__32__Program : list[int], uint8__FirmwareMajorVersion : int, uint8__FirmwareMinorVersion : int, uint16__FirmwarePatchVersion : int, uint8__SystemMajorVersion : int, uint8__SystemMinorVersion : int, uint16__SystemPatchVersion : int, e__CommonFrameworkTypes1_NodeType__OwnerNodeType : CommonFrameworkTypes1_NodeType, uint32__OwnerSerialInt : int, e__CommonFrameworkTypes1_ProgramType__OwnerProgram : CommonFrameworkTypes1_ProgramType) -> None:
        """
        Struct 'FileInfo' constructor
        
        Attributes
        ---------
        e__CubeComputerControlProgram8_FtpFiles__File [1] : CubeComputerControlProgram8_FtpFiles
            File this info represents
        e__CubeComputerControlProgram8_FtpBackend__Backend [1] : CubeComputerControlProgram8_FtpBackend
            Which storage medmium is the file in
        e__CubeComputerControlProgram8_FtpFileType__Type [1] : CubeComputerControlProgram8_FtpFileType
            File Type
        uint32__Size [1] : int
            File Size (actual data written)
        uint32__AllocSize [1] : int
            Size of memory allocated to file
        uint32__VectTblOffset [1] : int
            Vector Table Offset: Onling applicable to application binary files
        uint32__UnixTimeSeconds [1] : int
            Modification Unix time s
        uint32__UnixTimeNanoSeconds [1] : int
            Modification Unix time ns
        uint32__Crc [1] : int
            File CRC
        a__uint8__32__Component [32] : list[int]
            ASCII string of chars denoting the CubeSpace Component this file is for/from
        a__uint8__32__Program [32] : list[int]
            ASCII string of chars denoting the Component Application this file is for/from
        uint8__FirmwareMajorVersion [1] : int
            Firmware version (Major) that this file is for/from
        uint8__FirmwareMinorVersion [1] : int
            Firmware version (Minor) that this file is for/from
        uint16__FirmwarePatchVersion [1] : int
            Firmware version (Patch) that this file is for/from
        uint8__SystemMajorVersion [1] : int
            System version (Major) that this file is for/from
        uint8__SystemMinorVersion [1] : int
            System version (Minor) that this file is for/from
        uint16__SystemPatchVersion [1] : int
            System version (Patch) that this file is for/from
        e__CommonFrameworkTypes1_NodeType__OwnerNodeType [1] : CommonFrameworkTypes1_NodeType
            The Node Type that owns the file
        uint32__OwnerSerialInt [1] : int
            The Serial Number integer of the node that owns the file
        e__CommonFrameworkTypes1_ProgramType__OwnerProgram [1] : CommonFrameworkTypes1_ProgramType
            The Program Type that owns the file
        """
        
        pass
        
    def get_File(self) -> CubeComputerControlProgram8_FtpFiles:
        """
        A getter for the 'FileInfo::File' structure field
        
        File this info represents
        """
        
        pass
    
    def get_Backend(self) -> CubeComputerControlProgram8_FtpBackend:
        """
        A getter for the 'FileInfo::Backend' structure field
        
        Which storage medmium is the file in
        """
        
        pass
    
    def get_Type(self) -> CubeComputerControlProgram8_FtpFileType:
        """
        A getter for the 'FileInfo::Type' structure field
        
        File Type
        """
        
        pass
    
    def get_Size(self) -> int:
        """
        A getter for the 'FileInfo::Size' structure field
        
        File Size (actual data written)
        """
        
        pass
    
    def get_AllocSize(self) -> int:
        """
        A getter for the 'FileInfo::AllocSize' structure field
        
        Size of memory allocated to file
        """
        
        pass
    
    def get_VectTblOffset(self) -> int:
        """
        A getter for the 'FileInfo::VectTblOffset' structure field
        
        Vector Table Offset: Onling applicable to application binary files
        """
        
        pass
    
    def get_UnixTimeSeconds(self) -> int:
        """
        A getter for the 'FileInfo::UnixTimeSeconds' structure field
        
        Modification Unix time s
        """
        
        pass
    
    def get_UnixTimeNanoSeconds(self) -> int:
        """
        A getter for the 'FileInfo::UnixTimeNanoSeconds' structure field
        
        Modification Unix time ns
        """
        
        pass
    
    def get_Crc(self) -> int:
        """
        A getter for the 'FileInfo::Crc' structure field
        
        File CRC
        """
        
        pass
    
    def get_Component(self) -> list[int]:
        """
        A getter for the 'FileInfo::Component' structure field
        
        ASCII string of chars denoting the CubeSpace Component this file is for/from
        """
        
        pass
    
    def get_Program(self) -> list[int]:
        """
        A getter for the 'FileInfo::Program' structure field
        
        ASCII string of chars denoting the Component Application this file is for/from
        """
        
        pass
    
    def get_FirmwareMajorVersion(self) -> int:
        """
        A getter for the 'FileInfo::FirmwareMajorVersion' structure field
        
        Firmware version (Major) that this file is for/from
        """
        
        pass
    
    def get_FirmwareMinorVersion(self) -> int:
        """
        A getter for the 'FileInfo::FirmwareMinorVersion' structure field
        
        Firmware version (Minor) that this file is for/from
        """
        
        pass
    
    def get_FirmwarePatchVersion(self) -> int:
        """
        A getter for the 'FileInfo::FirmwarePatchVersion' structure field
        
        Firmware version (Patch) that this file is for/from
        """
        
        pass
    
    def get_SystemMajorVersion(self) -> int:
        """
        A getter for the 'FileInfo::SystemMajorVersion' structure field
        
        System version (Major) that this file is for/from
        """
        
        pass
    
    def get_SystemMinorVersion(self) -> int:
        """
        A getter for the 'FileInfo::SystemMinorVersion' structure field
        
        System version (Minor) that this file is for/from
        """
        
        pass
    
    def get_SystemPatchVersion(self) -> int:
        """
        A getter for the 'FileInfo::SystemPatchVersion' structure field
        
        System version (Patch) that this file is for/from
        """
        
        pass
    
    def get_OwnerNodeType(self) -> CommonFrameworkTypes1_NodeType:
        """
        A getter for the 'FileInfo::OwnerNodeType' structure field
        
        The Node Type that owns the file
        """
        
        pass
    
    def get_OwnerSerialInt(self) -> int:
        """
        A getter for the 'FileInfo::OwnerSerialInt' structure field
        
        The Serial Number integer of the node that owns the file
        """
        
        pass
    
    def get_OwnerProgram(self) -> CommonFrameworkTypes1_ProgramType:
        """
        A getter for the 'FileInfo::OwnerProgram' structure field
        
        The Program Type that owns the file
        """
        
        pass

def FileInfo_make_from_buf(buf : bytes) -> FileInfo:
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
def req_setConfigDefaultModes(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ConfigDefaultModes) -> bytes:
    """
    Request serialization function for method 'setConfigDefaultModes'
    
    Default mode configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ConfigDefaultModes
        See definition of type
    """
    
    pass
    
def req_setConfigMount(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ConfigMount) -> bytes:
    """
    Request serialization function for method 'setConfigMount'
    
    Mounting configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ConfigMount
        See definition of type
    """
    
    pass
    
def req_setConfigMag0OrbitCal(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ConfigMag0OrbitCal) -> bytes:
    """
    Request serialization function for method 'setConfigMag0OrbitCal'
    
    Mag0 magnetometer in-orbit calibration configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ConfigMag0OrbitCal
        See definition of type
    """
    
    pass
    
def req_setConfigMag1OrbitCal(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ConfigMag1OrbitCal) -> bytes:
    """
    Request serialization function for method 'setConfigMag1OrbitCal'
    
    Mag1 magnetometer in-orbit calibration configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ConfigMag1OrbitCal
        See definition of type
    """
    
    pass
    
def req_setConfigAdcsController(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ConfigAdcsController) -> bytes:
    """
    Request serialization function for method 'setConfigAdcsController'
    
    ADCS controller configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ConfigAdcsController
        See definition of type
    """
    
    pass
    
def req_setConfigAdcsEstimator(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ConfigAdcsEstimator) -> bytes:
    """
    Request serialization function for method 'setConfigAdcsEstimator'
    
    ADCS estimator configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ConfigAdcsEstimator
        See definition of type
    """
    
    pass
    
def req_setConfigAdcsSatellite(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ConfigAdcsSatellite) -> bytes:
    """
    Request serialization function for method 'setConfigAdcsSatellite'
    
    ADCS satellite configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ConfigAdcsSatellite
        See definition of type
    """
    
    pass
    
def req_setConfigOrbitSatParams(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ConfigOrbitSatParams) -> bytes:
    """
    Request serialization function for method 'setConfigOrbitSatParams'
    
    Satellite orbit parameter configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ConfigOrbitSatParams
        See definition of type
    """
    
    pass
    
def req_setConfigOrbitTargetParams(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ConfigOrbitTargetParams) -> bytes:
    """
    Request serialization function for method 'setConfigOrbitTargetParams'
    
    Satellite orbit parameter configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ConfigOrbitTargetParams
        See definition of type
    """
    
    pass
    
def req_setConfigNodeSelection(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ConfigNodeSelection) -> bytes:
    """
    Request serialization function for method 'setConfigNodeSelection'
    
    Node selection configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ConfigNodeSelection
        See definition of type
    """
    
    pass
    
def req_setConfigActuatorRwl(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ConfigActuatorRwl) -> bytes:
    """
    Request serialization function for method 'setConfigActuatorRwl'
    
    Wheel configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ConfigActuatorRwl
        See definition of type
    """
    
    pass
    
def req_setConfigActuatorMtq(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ConfigActuatorMtq) -> bytes:
    """
    Request serialization function for method 'setConfigActuatorMtq'
    
    Magnetorquer configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ConfigActuatorMtq
        See definition of type
    """
    
    pass
    
def req_setConfigMagSensingElement(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ConfigMagSensingElement) -> bytes:
    """
    Request serialization function for method 'setConfigMagSensingElement'
    
    Mag sensing element (primary/redundant) configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ConfigMagSensingElement
        See definition of type
    """
    
    pass
    
def req_setConfigAsgp4(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ConfigAsgp4) -> bytes:
    """
    Request serialization function for method 'setConfigAsgp4'
    
    Augmented SGP4 configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ConfigAsgp4
        See definition of type
    """
    
    pass
    
def req_setConMode(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ConMode) -> bytes:
    """
    Request serialization function for method 'setConMode'
    
    Control mode 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ConMode
        See definition of type
    """
    
    pass
    
def req_setEstMode(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : EstMode) -> bytes:
    """
    Request serialization function for method 'setEstMode'
    
    Estimation mode 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : EstMode
        See definition of type
    """
    
    pass
    
def req_setOrbMode(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : OrbMode) -> bytes:
    """
    Request serialization function for method 'setOrbMode'
    
    Orbit mode 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : OrbMode
        See definition of type
    """
    
    pass
    
def req_setAdcsRunMode(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : AdcsRunMode) -> bytes:
    """
    Request serialization function for method 'setAdcsRunMode'
    
    ADCS run mode 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : AdcsRunMode
        See definition of type
    """
    
    pass
    
def req_setAdcsOpState(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : AdcsOpState) -> bytes:
    """
    Request serialization function for method 'setAdcsOpState'
    
    ADCS operational state 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : AdcsOpState
        See definition of type
    """
    
    pass
    
def req_setSimSensorRaw(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : SimSensorRaw) -> bytes:
    """
    Request serialization function for method 'setSimSensorRaw'
    
    Simulation raw sensor telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : SimSensorRaw
        See definition of type
    """
    
    pass
    
def req_setOpenLoopCommandMtq(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : OpenLoopCommandMtq) -> bytes:
    """
    Request serialization function for method 'setOpenLoopCommandMtq'
    
    OpenLoopCommandMtq 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : OpenLoopCommandMtq
        See definition of type
    """
    
    pass
    
def req_setOpenLoopCommandRwl(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : OpenLoopCommandRwl) -> bytes:
    """
    Request serialization function for method 'setOpenLoopCommandRwl'
    
    OpenLoopCommandRwl 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : OpenLoopCommandRwl
        See definition of type
    """
    
    pass
    
def req_setOpenLoopCommandHxyzRW(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : OpenLoopCommandHxyzRW) -> bytes:
    """
    Request serialization function for method 'setOpenLoopCommandHxyzRW'
    
    OpenLoopCommandHxyzRW 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : OpenLoopCommandHxyzRW
        See definition of type
    """
    
    pass
    
def req_setReferenceRpy(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ReferenceRpy) -> bytes:
    """
    Request serialization function for method 'setReferenceRpy'
    
    Reference roll, pitch and yaw values for 3-axis wheel control 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ReferenceRpy
        See definition of type
    """
    
    pass
    
def req_setReferenceTarget(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ReferenceTarget) -> bytes:
    """
    Request serialization function for method 'setReferenceTarget'
    
    Reference target location for ground and target tracking controller 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ReferenceTarget
        See definition of type
    """
    
    pass
    
def req_setReferenceIrcVector(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ReferenceIrcVector) -> bytes:
    """
    Request serialization function for method 'setReferenceIrcVector'
    
    Reference IRC vector for inertial target tracking controller 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ReferenceIrcVector
        See definition of type
    """
    
    pass
    
def req_setReferenceFmcParam(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : ReferenceFmcParam) -> bytes:
    """
    Request serialization function for method 'setReferenceFmcParam'
    
    Reference parameters for FMC scan 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : ReferenceFmcParam
        See definition of type
    """
    
    pass
    
def req_setDeployCommandMag(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : DeployCommandMag) -> bytes:
    """
    Request serialization function for method 'setDeployCommandMag'
    
    Deploy Magnetometer 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : DeployCommandMag
        See definition of type
    """
    
    pass
    
def req_setGnssSensorCmd(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : GnssSensorCmd) -> bytes:
    """
    Request serialization function for method 'setGnssSensorCmd'
    
    GNSS sensor measurements as command to the ADCS 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : GnssSensorCmd
        See definition of type
    """
    
    pass
    
def req_setFileTransferSetup(e__CmdTargetNode__cmdTargetNode : CmdTargetNode, s__setVal : FileTransferSetup) -> bytes:
    """
    Request serialization function for method 'setFileTransferSetup'
    
    Setup a file transfer 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    s__setVal [1] : FileTransferSetup
        See definition of type
    """
    
    pass
    
def req_getConfigDefaultModes(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getConfigDefaultModes'
    
    Default mode configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getConfigMount(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getConfigMount'
    
    Mounting configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getConfigMag0OrbitCal(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getConfigMag0OrbitCal'
    
    Mag0 magnetometer in-orbit calibration configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getConfigMag1OrbitCal(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getConfigMag1OrbitCal'
    
    Mag1 magnetometer in-orbit calibration configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getConfigAdcsController(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getConfigAdcsController'
    
    ADCS controller configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getConfigAdcsEstimator(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getConfigAdcsEstimator'
    
    ADCS estimator configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getConfigAdcsSatellite(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getConfigAdcsSatellite'
    
    ADCS satellite configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getConfigOrbitSatParams(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getConfigOrbitSatParams'
    
    Satellite orbit parameter configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getConfigOrbitTargetParams(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getConfigOrbitTargetParams'
    
    Satellite orbit parameter configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getConfigNodeSelection(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getConfigNodeSelection'
    
    Node selection configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getConfigActuatorRwl(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getConfigActuatorRwl'
    
    Wheel configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getConfigActuatorMtq(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getConfigActuatorMtq'
    
    Magnetorquer configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getConfigMagSensingElement(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getConfigMagSensingElement'
    
    Mag sensing element (primary/redundant) configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getConfigAsgp4(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getConfigAsgp4'
    
    Augmented SGP4 configuration 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getConMode(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getConMode'
    
    Control mode 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getEstMode(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getEstMode'
    
    Estimation mode 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getOrbMode(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getOrbMode'
    
    Orbit mode 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getAdcsRunMode(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getAdcsRunMode'
    
    ADCS run mode 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getAdcsOpState(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getAdcsOpState'
    
    ADCS operational state 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getSimSensorRaw(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getSimSensorRaw'
    
    Simulation raw sensor telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getOpenLoopCommandMtq(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getOpenLoopCommandMtq'
    
    OpenLoopCommandMtq 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getOpenLoopCommandRwl(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getOpenLoopCommandRwl'
    
    OpenLoopCommandRwl 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getOpenLoopCommandHxyzRW(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getOpenLoopCommandHxyzRW'
    
    OpenLoopCommandHxyzRW 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getReferenceRpy(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getReferenceRpy'
    
    Reference roll, pitch and yaw values for 3-axis wheel control 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getReferenceTarget(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getReferenceTarget'
    
    Reference target location for ground and target tracking controller 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getReferenceIrcVector(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getReferenceIrcVector'
    
    Reference IRC vector for inertial target tracking controller 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getReferenceFmcParam(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getReferenceFmcParam'
    
    Reference parameters for FMC scan 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getCubeNodePortMap(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getCubeNodePortMap'
    
    The configured port map of all CubeNode-Quads 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmHil(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmHil'
    
    HIL telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmExecutionPoint(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmExecutionPoint'
    
    Current execution point 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmAsgp4(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmAsgp4'
    
    Augmented orbital parameters 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmNodeInitState(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmNodeInitState'
    
    Current initialization state of each node 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmLitefuforsHealth(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmLitefuforsHealth'
    
    Health telemetry for CubeNode LITEFUFORS 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getFileTransferSetup(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getFileTransferSetup'
    
    Setup a file transfer 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getFileTransferStatus(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getFileTransferStatus'
    
    File Transfer Status 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getFileInfo(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getFileInfo'
    
    Cached file information after calling FileTransferSetup 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmSensorRawCss(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmSensorRawCss'
    
    Raw CSS sensor telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmSensorRawMag(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmSensorRawMag'
    
    Raw MAG sensor telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmSensorRawGyro(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmSensorRawGyro'
    
    Raw GYRO sensor telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmSensorRawRwl(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmSensorRawRwl'
    
    Raw RWL sensor telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmSensorCalFss(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmSensorCalFss'
    
    Calibrated FSS sensor telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmSensorCalCss(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmSensorCalCss'
    
    Calibrated CSS sensor telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmSensorCalMag(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmSensorCalMag'
    
    Calibrated MAG sensor telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmSensorCalGyro(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmSensorCalGyro'
    
    Calibrated GYRO sensor telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmSensorCalHss(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmSensorCalHss'
    
    Calibrated HSS sensor telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmSensorCalStr(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmSensorCalStr'
    
    Calibrated STR sensor telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmSensorCalGnss(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmSensorCalGnss'
    
    Calibrated GNSS sensor telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmSensorCalRwl(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmSensorCalRwl'
    
    Calibrated RWL sensor telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmModels(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmModels'
    
    Models telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmEstimatorMain(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmEstimatorMain'
    
    Main estimator telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmEstimatorBackup(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmEstimatorBackup'
    
    Backup estimator telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmEstimatorMainHighRes(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmEstimatorMainHighRes'
    
    Main estimator high-resolution telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmController(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmController'
    
    Controller telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmGnssRaw(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmGnssRaw'
    
    Raw GNSS sensor telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmExtSensorRaw(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmExtSensorRaw'
    
    Raw external sensor telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmStrPst3sRaw(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmStrPst3sRaw'
    
    Raw PST3S star tracker telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmFssCubeSenseSunRaw(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmFssCubeSenseSunRaw'
    
    Raw CubeSense Sun telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmHssCubeSenseEarthRaw(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmHssCubeSenseEarthRaw'
    
    Raw CubeSense Earth telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmRwlNssRwlRaw(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmRwlNssRwlRaw'
    
    Raw NSSRWL sensor telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmStrCubeStarRaw(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmStrCubeStarRaw'
    
    Raw CubeStar telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmGyrLitefuforsRaw(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmGyrLitefuforsRaw'
    
    Raw LITEF uFORS sensor telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmStrCubeAurigaRaw(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmStrCubeAurigaRaw'
    
    Raw CubeStar telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmAcpExecution(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmAcpExecution'
    
    ACP execution telemetry 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmTorquerCurrents(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmTorquerCurrents'
    
    Current measurements 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmCubeComputerHealth(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmCubeComputerHealth'
    
    Health telemetry for ADCS CubeComputer 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmFssCubeSenseSunHealth(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmFssCubeSenseSunHealth'
    
    Health telemetry for CubeSense Sun 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmHssCubeSenseEarthHealth(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmHssCubeSenseEarthHealth'
    
    Health telemetry for CubeSense Earth 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmCubeMagHealth(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmCubeMagHealth'
    
    Health telemetry for CubeMag magnetometer 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmRwlHealth(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmRwlHealth'
    
    Health telemetry for reaction wheels 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmStrPst3sHealth(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmStrPst3sHealth'
    
    Health telemetry for CubeNode PST3S 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmNssRwlHealth(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmNssRwlHealth'
    
    Health telemetry for CubeNode NSSRWL 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmStrHealth(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmStrHealth'
    
    Health telemetry for CubeStar star camera 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmGnssUartStatus(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmGnssUartStatus'
    
    Status telemetry for GNSS UART 
    
    Arguments
    ---------
    e__CmdTargetNode__cmdTargetNode [1] : CmdTargetNode
        CubeADCS Gen2 node to receive the request.
    """
    
    pass
    
def req_getTlmStrAurigaHealth(e__CmdTargetNode__cmdTargetNode : CmdTargetNode) -> bytes:
    """
    Request serialization function for method 'getTlmStrAurigaHealth'
    
    Health telemetry for CubeAuriga star camera 
    
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
class resp_setConfigDefaultModes:
    """
    A class representing a parsed FIDL response for method 'setConfigDefaultModes'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setConfigDefaultModes' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setConfigDefaultModes::adcsErrorCode'
        """
        pass

class resp_setConfigMount:
    """
    A class representing a parsed FIDL response for method 'setConfigMount'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setConfigMount' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setConfigMount::adcsErrorCode'
        """
        pass

class resp_setConfigMag0OrbitCal:
    """
    A class representing a parsed FIDL response for method 'setConfigMag0OrbitCal'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setConfigMag0OrbitCal' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setConfigMag0OrbitCal::adcsErrorCode'
        """
        pass

class resp_setConfigMag1OrbitCal:
    """
    A class representing a parsed FIDL response for method 'setConfigMag1OrbitCal'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setConfigMag1OrbitCal' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setConfigMag1OrbitCal::adcsErrorCode'
        """
        pass

class resp_setConfigAdcsController:
    """
    A class representing a parsed FIDL response for method 'setConfigAdcsController'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setConfigAdcsController' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setConfigAdcsController::adcsErrorCode'
        """
        pass

class resp_setConfigAdcsEstimator:
    """
    A class representing a parsed FIDL response for method 'setConfigAdcsEstimator'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setConfigAdcsEstimator' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setConfigAdcsEstimator::adcsErrorCode'
        """
        pass

class resp_setConfigAdcsSatellite:
    """
    A class representing a parsed FIDL response for method 'setConfigAdcsSatellite'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setConfigAdcsSatellite' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setConfigAdcsSatellite::adcsErrorCode'
        """
        pass

class resp_setConfigOrbitSatParams:
    """
    A class representing a parsed FIDL response for method 'setConfigOrbitSatParams'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setConfigOrbitSatParams' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setConfigOrbitSatParams::adcsErrorCode'
        """
        pass

class resp_setConfigOrbitTargetParams:
    """
    A class representing a parsed FIDL response for method 'setConfigOrbitTargetParams'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setConfigOrbitTargetParams' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setConfigOrbitTargetParams::adcsErrorCode'
        """
        pass

class resp_setConfigNodeSelection:
    """
    A class representing a parsed FIDL response for method 'setConfigNodeSelection'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setConfigNodeSelection' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setConfigNodeSelection::adcsErrorCode'
        """
        pass

class resp_setConfigActuatorRwl:
    """
    A class representing a parsed FIDL response for method 'setConfigActuatorRwl'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setConfigActuatorRwl' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setConfigActuatorRwl::adcsErrorCode'
        """
        pass

class resp_setConfigActuatorMtq:
    """
    A class representing a parsed FIDL response for method 'setConfigActuatorMtq'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setConfigActuatorMtq' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setConfigActuatorMtq::adcsErrorCode'
        """
        pass

class resp_setConfigMagSensingElement:
    """
    A class representing a parsed FIDL response for method 'setConfigMagSensingElement'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setConfigMagSensingElement' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setConfigMagSensingElement::adcsErrorCode'
        """
        pass

class resp_setConfigAsgp4:
    """
    A class representing a parsed FIDL response for method 'setConfigAsgp4'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setConfigAsgp4' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setConfigAsgp4::adcsErrorCode'
        """
        pass

class resp_setConMode:
    """
    A class representing a parsed FIDL response for method 'setConMode'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setConMode' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setConMode::adcsErrorCode'
        """
        pass

class resp_setEstMode:
    """
    A class representing a parsed FIDL response for method 'setEstMode'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setEstMode' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setEstMode::adcsErrorCode'
        """
        pass

class resp_setOrbMode:
    """
    A class representing a parsed FIDL response for method 'setOrbMode'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setOrbMode' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setOrbMode::adcsErrorCode'
        """
        pass

class resp_setAdcsRunMode:
    """
    A class representing a parsed FIDL response for method 'setAdcsRunMode'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setAdcsRunMode' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setAdcsRunMode::adcsErrorCode'
        """
        pass

class resp_setAdcsOpState:
    """
    A class representing a parsed FIDL response for method 'setAdcsOpState'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setAdcsOpState' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setAdcsOpState::adcsErrorCode'
        """
        pass

class resp_setSimSensorRaw:
    """
    A class representing a parsed FIDL response for method 'setSimSensorRaw'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setSimSensorRaw' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setSimSensorRaw::adcsErrorCode'
        """
        pass

class resp_setOpenLoopCommandMtq:
    """
    A class representing a parsed FIDL response for method 'setOpenLoopCommandMtq'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setOpenLoopCommandMtq' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setOpenLoopCommandMtq::adcsErrorCode'
        """
        pass

class resp_setOpenLoopCommandRwl:
    """
    A class representing a parsed FIDL response for method 'setOpenLoopCommandRwl'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setOpenLoopCommandRwl' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setOpenLoopCommandRwl::adcsErrorCode'
        """
        pass

class resp_setOpenLoopCommandHxyzRW:
    """
    A class representing a parsed FIDL response for method 'setOpenLoopCommandHxyzRW'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setOpenLoopCommandHxyzRW' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setOpenLoopCommandHxyzRW::adcsErrorCode'
        """
        pass

class resp_setReferenceRpy:
    """
    A class representing a parsed FIDL response for method 'setReferenceRpy'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setReferenceRpy' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setReferenceRpy::adcsErrorCode'
        """
        pass

class resp_setReferenceTarget:
    """
    A class representing a parsed FIDL response for method 'setReferenceTarget'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setReferenceTarget' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setReferenceTarget::adcsErrorCode'
        """
        pass

class resp_setReferenceIrcVector:
    """
    A class representing a parsed FIDL response for method 'setReferenceIrcVector'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setReferenceIrcVector' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setReferenceIrcVector::adcsErrorCode'
        """
        pass

class resp_setReferenceFmcParam:
    """
    A class representing a parsed FIDL response for method 'setReferenceFmcParam'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setReferenceFmcParam' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setReferenceFmcParam::adcsErrorCode'
        """
        pass

class resp_setDeployCommandMag:
    """
    A class representing a parsed FIDL response for method 'setDeployCommandMag'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setDeployCommandMag' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setDeployCommandMag::adcsErrorCode'
        """
        pass

class resp_setGnssSensorCmd:
    """
    A class representing a parsed FIDL response for method 'setGnssSensorCmd'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setGnssSensorCmd' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setGnssSensorCmd::adcsErrorCode'
        """
        pass

class resp_setFileTransferSetup:
    """
    A class representing a parsed FIDL response for method 'setFileTransferSetup'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'setFileTransferSetup' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'setFileTransferSetup::adcsErrorCode'
        """
        pass

class resp_getConfigDefaultModes:
    """
    A class representing a parsed FIDL response for method 'getConfigDefaultModes'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getConfigDefaultModes' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getConfigDefaultModes::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ConfigDefaultModes:
        """
        A getter for the output argument 'getConfigDefaultModes::returnVal'
        """
        pass

class resp_getConfigMount:
    """
    A class representing a parsed FIDL response for method 'getConfigMount'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getConfigMount' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getConfigMount::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ConfigMount:
        """
        A getter for the output argument 'getConfigMount::returnVal'
        """
        pass

class resp_getConfigMag0OrbitCal:
    """
    A class representing a parsed FIDL response for method 'getConfigMag0OrbitCal'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getConfigMag0OrbitCal' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getConfigMag0OrbitCal::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ConfigMag0OrbitCal:
        """
        A getter for the output argument 'getConfigMag0OrbitCal::returnVal'
        """
        pass

class resp_getConfigMag1OrbitCal:
    """
    A class representing a parsed FIDL response for method 'getConfigMag1OrbitCal'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getConfigMag1OrbitCal' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getConfigMag1OrbitCal::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ConfigMag1OrbitCal:
        """
        A getter for the output argument 'getConfigMag1OrbitCal::returnVal'
        """
        pass

class resp_getConfigAdcsController:
    """
    A class representing a parsed FIDL response for method 'getConfigAdcsController'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getConfigAdcsController' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getConfigAdcsController::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ConfigAdcsController:
        """
        A getter for the output argument 'getConfigAdcsController::returnVal'
        """
        pass

class resp_getConfigAdcsEstimator:
    """
    A class representing a parsed FIDL response for method 'getConfigAdcsEstimator'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getConfigAdcsEstimator' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getConfigAdcsEstimator::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ConfigAdcsEstimator:
        """
        A getter for the output argument 'getConfigAdcsEstimator::returnVal'
        """
        pass

class resp_getConfigAdcsSatellite:
    """
    A class representing a parsed FIDL response for method 'getConfigAdcsSatellite'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getConfigAdcsSatellite' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getConfigAdcsSatellite::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ConfigAdcsSatellite:
        """
        A getter for the output argument 'getConfigAdcsSatellite::returnVal'
        """
        pass

class resp_getConfigOrbitSatParams:
    """
    A class representing a parsed FIDL response for method 'getConfigOrbitSatParams'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getConfigOrbitSatParams' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getConfigOrbitSatParams::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ConfigOrbitSatParams:
        """
        A getter for the output argument 'getConfigOrbitSatParams::returnVal'
        """
        pass

class resp_getConfigOrbitTargetParams:
    """
    A class representing a parsed FIDL response for method 'getConfigOrbitTargetParams'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getConfigOrbitTargetParams' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getConfigOrbitTargetParams::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ConfigOrbitTargetParams:
        """
        A getter for the output argument 'getConfigOrbitTargetParams::returnVal'
        """
        pass

class resp_getConfigNodeSelection:
    """
    A class representing a parsed FIDL response for method 'getConfigNodeSelection'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getConfigNodeSelection' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getConfigNodeSelection::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ConfigNodeSelection:
        """
        A getter for the output argument 'getConfigNodeSelection::returnVal'
        """
        pass

class resp_getConfigActuatorRwl:
    """
    A class representing a parsed FIDL response for method 'getConfigActuatorRwl'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getConfigActuatorRwl' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getConfigActuatorRwl::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ConfigActuatorRwl:
        """
        A getter for the output argument 'getConfigActuatorRwl::returnVal'
        """
        pass

class resp_getConfigActuatorMtq:
    """
    A class representing a parsed FIDL response for method 'getConfigActuatorMtq'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getConfigActuatorMtq' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getConfigActuatorMtq::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ConfigActuatorMtq:
        """
        A getter for the output argument 'getConfigActuatorMtq::returnVal'
        """
        pass

class resp_getConfigMagSensingElement:
    """
    A class representing a parsed FIDL response for method 'getConfigMagSensingElement'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getConfigMagSensingElement' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getConfigMagSensingElement::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ConfigMagSensingElement:
        """
        A getter for the output argument 'getConfigMagSensingElement::returnVal'
        """
        pass

class resp_getConfigAsgp4:
    """
    A class representing a parsed FIDL response for method 'getConfigAsgp4'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getConfigAsgp4' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getConfigAsgp4::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ConfigAsgp4:
        """
        A getter for the output argument 'getConfigAsgp4::returnVal'
        """
        pass

class resp_getConMode:
    """
    A class representing a parsed FIDL response for method 'getConMode'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getConMode' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getConMode::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ConMode:
        """
        A getter for the output argument 'getConMode::returnVal'
        """
        pass

class resp_getEstMode:
    """
    A class representing a parsed FIDL response for method 'getEstMode'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getEstMode' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getEstMode::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> EstMode:
        """
        A getter for the output argument 'getEstMode::returnVal'
        """
        pass

class resp_getOrbMode:
    """
    A class representing a parsed FIDL response for method 'getOrbMode'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getOrbMode' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getOrbMode::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> OrbMode:
        """
        A getter for the output argument 'getOrbMode::returnVal'
        """
        pass

class resp_getAdcsRunMode:
    """
    A class representing a parsed FIDL response for method 'getAdcsRunMode'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getAdcsRunMode' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getAdcsRunMode::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> AdcsRunMode:
        """
        A getter for the output argument 'getAdcsRunMode::returnVal'
        """
        pass

class resp_getAdcsOpState:
    """
    A class representing a parsed FIDL response for method 'getAdcsOpState'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getAdcsOpState' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getAdcsOpState::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> AdcsOpState:
        """
        A getter for the output argument 'getAdcsOpState::returnVal'
        """
        pass

class resp_getSimSensorRaw:
    """
    A class representing a parsed FIDL response for method 'getSimSensorRaw'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getSimSensorRaw' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getSimSensorRaw::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> SimSensorRaw:
        """
        A getter for the output argument 'getSimSensorRaw::returnVal'
        """
        pass

class resp_getOpenLoopCommandMtq:
    """
    A class representing a parsed FIDL response for method 'getOpenLoopCommandMtq'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getOpenLoopCommandMtq' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getOpenLoopCommandMtq::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> OpenLoopCommandMtq:
        """
        A getter for the output argument 'getOpenLoopCommandMtq::returnVal'
        """
        pass

class resp_getOpenLoopCommandRwl:
    """
    A class representing a parsed FIDL response for method 'getOpenLoopCommandRwl'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getOpenLoopCommandRwl' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getOpenLoopCommandRwl::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> OpenLoopCommandRwl:
        """
        A getter for the output argument 'getOpenLoopCommandRwl::returnVal'
        """
        pass

class resp_getOpenLoopCommandHxyzRW:
    """
    A class representing a parsed FIDL response for method 'getOpenLoopCommandHxyzRW'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getOpenLoopCommandHxyzRW' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getOpenLoopCommandHxyzRW::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> OpenLoopCommandHxyzRW:
        """
        A getter for the output argument 'getOpenLoopCommandHxyzRW::returnVal'
        """
        pass

class resp_getReferenceRpy:
    """
    A class representing a parsed FIDL response for method 'getReferenceRpy'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getReferenceRpy' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getReferenceRpy::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ReferenceRpy:
        """
        A getter for the output argument 'getReferenceRpy::returnVal'
        """
        pass

class resp_getReferenceTarget:
    """
    A class representing a parsed FIDL response for method 'getReferenceTarget'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getReferenceTarget' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getReferenceTarget::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ReferenceTarget:
        """
        A getter for the output argument 'getReferenceTarget::returnVal'
        """
        pass

class resp_getReferenceIrcVector:
    """
    A class representing a parsed FIDL response for method 'getReferenceIrcVector'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getReferenceIrcVector' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getReferenceIrcVector::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ReferenceIrcVector:
        """
        A getter for the output argument 'getReferenceIrcVector::returnVal'
        """
        pass

class resp_getReferenceFmcParam:
    """
    A class representing a parsed FIDL response for method 'getReferenceFmcParam'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getReferenceFmcParam' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getReferenceFmcParam::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> ReferenceFmcParam:
        """
        A getter for the output argument 'getReferenceFmcParam::returnVal'
        """
        pass

class resp_getCubeNodePortMap:
    """
    A class representing a parsed FIDL response for method 'getCubeNodePortMap'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getCubeNodePortMap' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getCubeNodePortMap::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> CubeNodePortMap:
        """
        A getter for the output argument 'getCubeNodePortMap::returnVal'
        """
        pass

class resp_getTlmHil:
    """
    A class representing a parsed FIDL response for method 'getTlmHil'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmHil' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmHil::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmHil:
        """
        A getter for the output argument 'getTlmHil::returnVal'
        """
        pass

class resp_getTlmExecutionPoint:
    """
    A class representing a parsed FIDL response for method 'getTlmExecutionPoint'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmExecutionPoint' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmExecutionPoint::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmExecutionPoint:
        """
        A getter for the output argument 'getTlmExecutionPoint::returnVal'
        """
        pass

class resp_getTlmAsgp4:
    """
    A class representing a parsed FIDL response for method 'getTlmAsgp4'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmAsgp4' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmAsgp4::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmAsgp4:
        """
        A getter for the output argument 'getTlmAsgp4::returnVal'
        """
        pass

class resp_getTlmNodeInitState:
    """
    A class representing a parsed FIDL response for method 'getTlmNodeInitState'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmNodeInitState' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmNodeInitState::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmNodeInitState:
        """
        A getter for the output argument 'getTlmNodeInitState::returnVal'
        """
        pass

class resp_getTlmLitefuforsHealth:
    """
    A class representing a parsed FIDL response for method 'getTlmLitefuforsHealth'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmLitefuforsHealth' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmLitefuforsHealth::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmLitefuforsHealth:
        """
        A getter for the output argument 'getTlmLitefuforsHealth::returnVal'
        """
        pass

class resp_getFileTransferSetup:
    """
    A class representing a parsed FIDL response for method 'getFileTransferSetup'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getFileTransferSetup' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getFileTransferSetup::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> FileTransferSetup:
        """
        A getter for the output argument 'getFileTransferSetup::returnVal'
        """
        pass

class resp_getFileTransferStatus:
    """
    A class representing a parsed FIDL response for method 'getFileTransferStatus'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getFileTransferStatus' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getFileTransferStatus::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> FileTransferStatus:
        """
        A getter for the output argument 'getFileTransferStatus::returnVal'
        """
        pass

class resp_getFileInfo:
    """
    A class representing a parsed FIDL response for method 'getFileInfo'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getFileInfo' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getFileInfo::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> FileInfo:
        """
        A getter for the output argument 'getFileInfo::returnVal'
        """
        pass

class resp_getTlmSensorRawCss:
    """
    A class representing a parsed FIDL response for method 'getTlmSensorRawCss'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmSensorRawCss' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmSensorRawCss::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmSensorRawCss:
        """
        A getter for the output argument 'getTlmSensorRawCss::returnVal'
        """
        pass

class resp_getTlmSensorRawMag:
    """
    A class representing a parsed FIDL response for method 'getTlmSensorRawMag'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmSensorRawMag' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmSensorRawMag::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmSensorRawMag:
        """
        A getter for the output argument 'getTlmSensorRawMag::returnVal'
        """
        pass

class resp_getTlmSensorRawGyro:
    """
    A class representing a parsed FIDL response for method 'getTlmSensorRawGyro'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmSensorRawGyro' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmSensorRawGyro::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmSensorRawGyro:
        """
        A getter for the output argument 'getTlmSensorRawGyro::returnVal'
        """
        pass

class resp_getTlmSensorRawRwl:
    """
    A class representing a parsed FIDL response for method 'getTlmSensorRawRwl'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmSensorRawRwl' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmSensorRawRwl::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmSensorRawRwl:
        """
        A getter for the output argument 'getTlmSensorRawRwl::returnVal'
        """
        pass

class resp_getTlmSensorCalFss:
    """
    A class representing a parsed FIDL response for method 'getTlmSensorCalFss'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmSensorCalFss' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmSensorCalFss::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmSensorCalFss:
        """
        A getter for the output argument 'getTlmSensorCalFss::returnVal'
        """
        pass

class resp_getTlmSensorCalCss:
    """
    A class representing a parsed FIDL response for method 'getTlmSensorCalCss'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmSensorCalCss' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmSensorCalCss::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmSensorCalCss:
        """
        A getter for the output argument 'getTlmSensorCalCss::returnVal'
        """
        pass

class resp_getTlmSensorCalMag:
    """
    A class representing a parsed FIDL response for method 'getTlmSensorCalMag'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmSensorCalMag' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmSensorCalMag::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmSensorCalMag:
        """
        A getter for the output argument 'getTlmSensorCalMag::returnVal'
        """
        pass

class resp_getTlmSensorCalGyro:
    """
    A class representing a parsed FIDL response for method 'getTlmSensorCalGyro'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmSensorCalGyro' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmSensorCalGyro::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmSensorCalGyro:
        """
        A getter for the output argument 'getTlmSensorCalGyro::returnVal'
        """
        pass

class resp_getTlmSensorCalHss:
    """
    A class representing a parsed FIDL response for method 'getTlmSensorCalHss'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmSensorCalHss' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmSensorCalHss::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmSensorCalHss:
        """
        A getter for the output argument 'getTlmSensorCalHss::returnVal'
        """
        pass

class resp_getTlmSensorCalStr:
    """
    A class representing a parsed FIDL response for method 'getTlmSensorCalStr'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmSensorCalStr' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmSensorCalStr::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmSensorCalStr:
        """
        A getter for the output argument 'getTlmSensorCalStr::returnVal'
        """
        pass

class resp_getTlmSensorCalGnss:
    """
    A class representing a parsed FIDL response for method 'getTlmSensorCalGnss'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmSensorCalGnss' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmSensorCalGnss::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmSensorCalGnss:
        """
        A getter for the output argument 'getTlmSensorCalGnss::returnVal'
        """
        pass

class resp_getTlmSensorCalRwl:
    """
    A class representing a parsed FIDL response for method 'getTlmSensorCalRwl'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmSensorCalRwl' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmSensorCalRwl::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmSensorCalRwl:
        """
        A getter for the output argument 'getTlmSensorCalRwl::returnVal'
        """
        pass

class resp_getTlmModels:
    """
    A class representing a parsed FIDL response for method 'getTlmModels'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmModels' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmModels::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmModels:
        """
        A getter for the output argument 'getTlmModels::returnVal'
        """
        pass

class resp_getTlmEstimatorMain:
    """
    A class representing a parsed FIDL response for method 'getTlmEstimatorMain'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmEstimatorMain' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmEstimatorMain::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmEstimatorMain:
        """
        A getter for the output argument 'getTlmEstimatorMain::returnVal'
        """
        pass

class resp_getTlmEstimatorBackup:
    """
    A class representing a parsed FIDL response for method 'getTlmEstimatorBackup'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmEstimatorBackup' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmEstimatorBackup::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmEstimatorBackup:
        """
        A getter for the output argument 'getTlmEstimatorBackup::returnVal'
        """
        pass

class resp_getTlmEstimatorMainHighRes:
    """
    A class representing a parsed FIDL response for method 'getTlmEstimatorMainHighRes'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmEstimatorMainHighRes' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmEstimatorMainHighRes::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmEstimatorMainHighRes:
        """
        A getter for the output argument 'getTlmEstimatorMainHighRes::returnVal'
        """
        pass

class resp_getTlmController:
    """
    A class representing a parsed FIDL response for method 'getTlmController'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmController' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmController::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmController:
        """
        A getter for the output argument 'getTlmController::returnVal'
        """
        pass

class resp_getTlmGnssRaw:
    """
    A class representing a parsed FIDL response for method 'getTlmGnssRaw'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmGnssRaw' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmGnssRaw::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmGnssRaw:
        """
        A getter for the output argument 'getTlmGnssRaw::returnVal'
        """
        pass

class resp_getTlmExtSensorRaw:
    """
    A class representing a parsed FIDL response for method 'getTlmExtSensorRaw'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmExtSensorRaw' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmExtSensorRaw::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmExtSensorRaw:
        """
        A getter for the output argument 'getTlmExtSensorRaw::returnVal'
        """
        pass

class resp_getTlmStrPst3sRaw:
    """
    A class representing a parsed FIDL response for method 'getTlmStrPst3sRaw'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmStrPst3sRaw' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmStrPst3sRaw::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmStrPst3sRaw:
        """
        A getter for the output argument 'getTlmStrPst3sRaw::returnVal'
        """
        pass

class resp_getTlmFssCubeSenseSunRaw:
    """
    A class representing a parsed FIDL response for method 'getTlmFssCubeSenseSunRaw'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmFssCubeSenseSunRaw' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmFssCubeSenseSunRaw::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmFssCubeSenseSunRaw:
        """
        A getter for the output argument 'getTlmFssCubeSenseSunRaw::returnVal'
        """
        pass

class resp_getTlmHssCubeSenseEarthRaw:
    """
    A class representing a parsed FIDL response for method 'getTlmHssCubeSenseEarthRaw'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmHssCubeSenseEarthRaw' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmHssCubeSenseEarthRaw::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmHssCubeSenseEarthRaw:
        """
        A getter for the output argument 'getTlmHssCubeSenseEarthRaw::returnVal'
        """
        pass

class resp_getTlmRwlNssRwlRaw:
    """
    A class representing a parsed FIDL response for method 'getTlmRwlNssRwlRaw'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmRwlNssRwlRaw' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmRwlNssRwlRaw::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmRwlNssRwlRaw:
        """
        A getter for the output argument 'getTlmRwlNssRwlRaw::returnVal'
        """
        pass

class resp_getTlmStrCubeStarRaw:
    """
    A class representing a parsed FIDL response for method 'getTlmStrCubeStarRaw'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmStrCubeStarRaw' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmStrCubeStarRaw::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmStrCubeStarRaw:
        """
        A getter for the output argument 'getTlmStrCubeStarRaw::returnVal'
        """
        pass

class resp_getTlmGyrLitefuforsRaw:
    """
    A class representing a parsed FIDL response for method 'getTlmGyrLitefuforsRaw'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmGyrLitefuforsRaw' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmGyrLitefuforsRaw::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmGyrLitefuforsRaw:
        """
        A getter for the output argument 'getTlmGyrLitefuforsRaw::returnVal'
        """
        pass

class resp_getTlmStrCubeAurigaRaw:
    """
    A class representing a parsed FIDL response for method 'getTlmStrCubeAurigaRaw'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmStrCubeAurigaRaw' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmStrCubeAurigaRaw::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmStrCubeAurigaRaw:
        """
        A getter for the output argument 'getTlmStrCubeAurigaRaw::returnVal'
        """
        pass

class resp_getTlmAcpExecution:
    """
    A class representing a parsed FIDL response for method 'getTlmAcpExecution'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmAcpExecution' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmAcpExecution::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmAcpExecution:
        """
        A getter for the output argument 'getTlmAcpExecution::returnVal'
        """
        pass

class resp_getTlmTorquerCurrents:
    """
    A class representing a parsed FIDL response for method 'getTlmTorquerCurrents'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmTorquerCurrents' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmTorquerCurrents::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmTorquerCurrents:
        """
        A getter for the output argument 'getTlmTorquerCurrents::returnVal'
        """
        pass

class resp_getTlmCubeComputerHealth:
    """
    A class representing a parsed FIDL response for method 'getTlmCubeComputerHealth'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmCubeComputerHealth' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmCubeComputerHealth::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmCubeComputerHealth:
        """
        A getter for the output argument 'getTlmCubeComputerHealth::returnVal'
        """
        pass

class resp_getTlmFssCubeSenseSunHealth:
    """
    A class representing a parsed FIDL response for method 'getTlmFssCubeSenseSunHealth'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmFssCubeSenseSunHealth' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmFssCubeSenseSunHealth::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmFssCubeSenseSunHealth:
        """
        A getter for the output argument 'getTlmFssCubeSenseSunHealth::returnVal'
        """
        pass

class resp_getTlmHssCubeSenseEarthHealth:
    """
    A class representing a parsed FIDL response for method 'getTlmHssCubeSenseEarthHealth'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmHssCubeSenseEarthHealth' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmHssCubeSenseEarthHealth::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmHssCubeSenseEarthHealth:
        """
        A getter for the output argument 'getTlmHssCubeSenseEarthHealth::returnVal'
        """
        pass

class resp_getTlmCubeMagHealth:
    """
    A class representing a parsed FIDL response for method 'getTlmCubeMagHealth'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmCubeMagHealth' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmCubeMagHealth::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmCubeMagHealth:
        """
        A getter for the output argument 'getTlmCubeMagHealth::returnVal'
        """
        pass

class resp_getTlmRwlHealth:
    """
    A class representing a parsed FIDL response for method 'getTlmRwlHealth'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmRwlHealth' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmRwlHealth::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmRwlHealth:
        """
        A getter for the output argument 'getTlmRwlHealth::returnVal'
        """
        pass

class resp_getTlmStrPst3sHealth:
    """
    A class representing a parsed FIDL response for method 'getTlmStrPst3sHealth'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmStrPst3sHealth' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmStrPst3sHealth::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmStrPst3sHealth:
        """
        A getter for the output argument 'getTlmStrPst3sHealth::returnVal'
        """
        pass

class resp_getTlmNssRwlHealth:
    """
    A class representing a parsed FIDL response for method 'getTlmNssRwlHealth'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmNssRwlHealth' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmNssRwlHealth::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmNssRwlHealth:
        """
        A getter for the output argument 'getTlmNssRwlHealth::returnVal'
        """
        pass

class resp_getTlmStrHealth:
    """
    A class representing a parsed FIDL response for method 'getTlmStrHealth'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmStrHealth' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmStrHealth::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmStrHealth:
        """
        A getter for the output argument 'getTlmStrHealth::returnVal'
        """
        pass

class resp_getTlmGnssUartStatus:
    """
    A class representing a parsed FIDL response for method 'getTlmGnssUartStatus'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmGnssUartStatus' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmGnssUartStatus::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmGnssUartStatus:
        """
        A getter for the output argument 'getTlmGnssUartStatus::returnVal'
        """
        pass

class resp_getTlmStrAurigaHealth:
    """
    A class representing a parsed FIDL response for method 'getTlmStrAurigaHealth'
    """
    
    def __init__(self, resp_data : bytes) -> None:
        """
        Response class constructor which accepts a bytes object and deserializes it into individual fields which can be
        accessed by dedicated getter functions.
        
        Arguments
        ---------
        resp_data : bytes
            Raw bytes object which contains a valid response to the 'getTlmStrAurigaHealth' method (includes the received FP header)
        """
        pass

    def get_adcsErrorCode(self) -> int:
        """
        A getter for the output argument 'getTlmStrAurigaHealth::adcsErrorCode'
        """
        pass
    
    def get_returnVal(self) -> TlmStrAurigaHealth:
        """
        A getter for the output argument 'getTlmStrAurigaHealth::returnVal'
        """
        pass

