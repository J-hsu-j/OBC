# ********************************************************************************************
# * @file datacache.py
# * @brief Data Cache Deserializer Routines generation
# ********************************************************************************************
# * @version           interface data_cache v0.1
# *
# * @copyright         (C) Copyright EnduroSat
# *
# *                    Contents and presentations are protected world-wide.
# *                    Any kind of using, copying etc. is prohibited without prior permission.
# *                    All rights - incl. industrial property rights - are reserved.
# *
# *-------------------------------------------------------------------------------------------
# * GENERATOR: org.endurosat.generators.macchiato.binders.Gen_DC v0.9
# *-------------------------------------------------------------------------------------------
# * !!! Please note that this code is fully GENERATED and shall not be manually modified as
# * all changes will be overwritten !!!
# ********************************************************************************************

from SerDesHelpers import SerDesHelpers

class dc_parser:
    def __init__(self):
        self.dc_entries_dict = {}

        self.dc_entries_dict[0x00000001] = dc_parser.struct_OBC_0
        self.dc_entries_dict[0x00000002] = dc_parser.struct_ADCS_0
        self.dc_entries_dict[0x00000003] = dc_parser.struct_ADCS_1
        self.dc_entries_dict[0x00000004] = dc_parser.struct_ADCS_2
        self.dc_entries_dict[0x00000005] = dc_parser.struct_EPS_0
        self.dc_entries_dict[0x00000006] = dc_parser.struct_SSP_0_Telemetry
        self.dc_entries_dict[0x00000007] = dc_parser.struct_SSP_1_Telemetry
        self.dc_entries_dict[0x00000008] = dc_parser.struct_SSP_2_Telemetry
        self.dc_entries_dict[0x00000009] = dc_parser.struct_SSP_3_Telemetry
        self.dc_entries_dict[0x0000000A] = dc_parser.struct_AOCS_CNTRL_TLM
        self.dc_entries_dict[0x0000000B] = dc_parser.struct_AOCS_CNTRL_SYS_STATE
        self.dc_entries_dict[0x0000000C] = dc_parser.struct_AOCS_CNTRL_REF_PARAMS
        self.dc_entries_dict[0x0000000D] = dc_parser.struct_SENSOR_GYRO_SENSOR_FRAME
        self.dc_entries_dict[0x0000000E] = dc_parser.struct_SENSOR_GYRO_BODY_FRAME
        self.dc_entries_dict[0x0000000F] = dc_parser.struct_SENSOR_MAG_PRIMARY_SENSOR_FRAME
        self.dc_entries_dict[0x00000010] = dc_parser.struct_SENSOR_MAG_PRIMARY_BODY_FRAME
        self.dc_entries_dict[0x00000011] = dc_parser.struct_SENSOR_MAG_SECONDARY_SENSOR_FRAME
        self.dc_entries_dict[0x00000012] = dc_parser.struct_SENSOR_MAG_SECONDARY_BODY_FRAME
        self.dc_entries_dict[0x00000013] = dc_parser.struct_SENSOR_COARSE_SUN_SENSOR_FRAME
        self.dc_entries_dict[0x00000014] = dc_parser.struct_SENSOR_COARSE_SUN_BODY_FRAME
        self.dc_entries_dict[0x00000015] = dc_parser.struct_SENSOR_PANEL_TEMP_SENSOR_FRAME
        self.dc_entries_dict[0x00000016] = dc_parser.struct_SENSOR_PANEL_TEMP_BODY_FRAME
        self.dc_entries_dict[0x00000017] = dc_parser.struct_SENSOR_GYRO_TEMP_SENSOR_FRAME
        self.dc_entries_dict[0x00000018] = dc_parser.struct_SENSOR_GYRO_TEMP_BODY_FRAME
        self.dc_entries_dict[0x00000019] = dc_parser.struct_ACTUATOR_MTQ_VALUES
        self.dc_entries_dict[0x0000001A] = dc_parser.struct_ACTUATOR_TORQUE_VALUES
        self.dc_entries_dict[0x0000001B] = dc_parser.struct_ADCS_3
        self.dc_entries_dict[0x0000001C] = dc_parser.struct_ADCS_4
        self.dc_entries_dict[0x0000001D] = dc_parser.struct_EPS_9
        self.dc_entries_dict[0x0000001E] = dc_parser.struct_EPS_10
        self.dc_entries_dict[0x0000001F] = dc_parser.struct_EPS_14
        self.dc_entries_dict[0x00000020] = dc_parser.struct_CUBEADCS_GEN2_OP_STATUS_COMMON
        self.dc_entries_dict[0x00000021] = dc_parser.struct_CUBEADCS_GEN2_OP_STATUS_APP
        self.dc_entries_dict[0x00000022] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_166
        self.dc_entries_dict[0x00000023] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_167
        self.dc_entries_dict[0x00000024] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_168
        self.dc_entries_dict[0x00000025] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_169
        self.dc_entries_dict[0x00000026] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_170
        self.dc_entries_dict[0x00000027] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_171
        self.dc_entries_dict[0x00000028] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_172
        self.dc_entries_dict[0x00000029] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_173
        self.dc_entries_dict[0x0000002A] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_174
        self.dc_entries_dict[0x0000002B] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_175
        self.dc_entries_dict[0x0000002C] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_176
        self.dc_entries_dict[0x0000002D] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_177
        self.dc_entries_dict[0x0000002E] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_178
        self.dc_entries_dict[0x0000002F] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_179
        self.dc_entries_dict[0x00000030] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_180
        self.dc_entries_dict[0x00000031] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_203
        self.dc_entries_dict[0x00000032] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_204
        self.dc_entries_dict[0x00000033] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_205
        self.dc_entries_dict[0x00000034] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_206
        self.dc_entries_dict[0x00000035] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_207
        self.dc_entries_dict[0x00000036] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_208_1
        self.dc_entries_dict[0x00000037] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_208_2
        self.dc_entries_dict[0x00000038] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_209
        self.dc_entries_dict[0x00000039] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_210
        self.dc_entries_dict[0x0000003A] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_211
        self.dc_entries_dict[0x0000003B] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_212
        self.dc_entries_dict[0x0000003C] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_213
        self.dc_entries_dict[0x0000003D] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_214
        self.dc_entries_dict[0x0000003E] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_216
        self.dc_entries_dict[0x0000003F] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_217
        self.dc_entries_dict[0x00000040] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_218
        self.dc_entries_dict[0x00000041] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_225
        self.dc_entries_dict[0x00000042] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_226
        self.dc_entries_dict[0x00000043] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_165
        self.dc_entries_dict[0x00000044] = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_221
        self.dc_entries_dict[0x00000045] = dc_parser.struct_GNSS_TIME
        self.dc_entries_dict[0x00000046] = dc_parser.struct_GNSS_BESTXYZ
        self.dc_entries_dict[0x00000047] = dc_parser.struct_SAT_STATE_VECTOR_FROM_PROPAGATOR
        self.dc_entries_dict[0x00000048] = dc_parser.struct_SAT_MAG_FIELD_VECTOR_FROM_MODEL
        self.dc_entries_dict[0x00000049] = dc_parser.struct_SAT_MAG_FIELD_VECTOR_FROM_SENSOR
        self.dc_entries_dict[0x0000004A] = dc_parser.struct_FDIR_EPS_I_CMD_EXEC_STATUS
        self.dc_entries_dict[0x0000004B] = dc_parser.struct_FDIR_EPS_II_PDM_CMD_EXEC_STATUS
        self.dc_entries_dict[0x0000004C] = dc_parser.struct_FDIR_CUBEADCS_CMD_EXEC_STATUS
        self.dc_entries_dict[0x0000004D] = dc_parser.struct_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS
        self.dc_entries_dict[0x0000004E] = dc_parser.struct_FDIR_CUBEADCS_GEN2_EVENTS
        self.dc_entries_dict[0x0000004F] = dc_parser.struct_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS
        self.dc_entries_dict[0x00000050] = dc_parser.struct_FDIR_UHF_CMD_EXEC_STATUS
        self.dc_entries_dict[0x00000051] = dc_parser.struct_FDIR_GNSS_CMD_EXEC_STATUS
        self.dc_entries_dict[0x00000052] = dc_parser.struct_FDIR_SDR_CMD_EXEC_STATUS
        self.dc_entries_dict[0x00000053] = dc_parser.struct_FDIR_S_X_BAND_CMD_EXEC_STATUS
        self.dc_entries_dict[0x00000054] = dc_parser.struct_FDIR_THRUSTER_CMD_EXEC_STATUS
        self.dc_entries_dict[0x00000055] = dc_parser.struct_XBandFeTelemetry
        self.dc_entries_dict[0x00000056] = dc_parser.struct_EpsOverallBatteryInfoType
        self.dc_entries_dict[0x00000057] = dc_parser.struct_PPS_Telemetry
        self.dc_entries_dict[0x00000058] = dc_parser.struct_FDIR_EPS_III_PDM_CMD_EXEC_STATUS
        self.dc_entries_dict[0x00000059] = dc_parser.struct_Eps2Inst0BatteryInfoType
        self.dc_entries_dict[0x0000005A] = dc_parser.struct_Eps2Inst0DeviceHealthInfoType
        self.dc_entries_dict[0x0000005B] = dc_parser.struct_Eps2Inst0InaSensors1Type
        self.dc_entries_dict[0x0000005C] = dc_parser.struct_Eps2Inst0InaSensors2Type
        self.dc_entries_dict[0x0000005D] = dc_parser.struct_Eps2Inst0BalancerInfoType
        self.dc_entries_dict[0x0000005E] = dc_parser.struct_Eps2Inst0BalancerStatusType
        self.dc_entries_dict[0x0000005F] = dc_parser.struct_Eps2Inst0BalancerCellsInfoType
        self.dc_entries_dict[0x00000060] = dc_parser.struct_Eps2Inst0ChargerXpType
        self.dc_entries_dict[0x00000061] = dc_parser.struct_Eps2Inst0ChargerXrType
        self.dc_entries_dict[0x00000062] = dc_parser.struct_Eps2Inst0ChargerYpType
        self.dc_entries_dict[0x00000063] = dc_parser.struct_Eps2Inst0ChargerYrType
        self.dc_entries_dict[0x00000064] = dc_parser.struct_Eps2Inst0ChargerZpType
        self.dc_entries_dict[0x00000065] = dc_parser.struct_Eps2Inst0ChargerZrType
        self.dc_entries_dict[0x00000066] = dc_parser.struct_Eps2Inst0_FDIR_CMD_EXEC_STATUS_type
        self.dc_entries_dict[0x00000067] = dc_parser.struct_Eps2Inst1BatteryInfoType
        self.dc_entries_dict[0x00000068] = dc_parser.struct_Eps2Inst1DeviceHealthInfoType
        self.dc_entries_dict[0x00000069] = dc_parser.struct_Eps2Inst1InaSensors1Type
        self.dc_entries_dict[0x0000006A] = dc_parser.struct_Eps2Inst1InaSensors2Type
        self.dc_entries_dict[0x0000006B] = dc_parser.struct_Eps2Inst1BalancerInfoType
        self.dc_entries_dict[0x0000006C] = dc_parser.struct_Eps2Inst1BalancerStatusType
        self.dc_entries_dict[0x0000006D] = dc_parser.struct_Eps2Inst1BalancerCellsInfoType
        self.dc_entries_dict[0x0000006E] = dc_parser.struct_Eps2Inst1ChargerXpType
        self.dc_entries_dict[0x0000006F] = dc_parser.struct_Eps2Inst1ChargerXrType
        self.dc_entries_dict[0x00000070] = dc_parser.struct_Eps2Inst1ChargerYpType
        self.dc_entries_dict[0x00000071] = dc_parser.struct_Eps2Inst1ChargerYrType
        self.dc_entries_dict[0x00000072] = dc_parser.struct_Eps2Inst1ChargerZpType
        self.dc_entries_dict[0x00000073] = dc_parser.struct_Eps2Inst1ChargerZrType
        self.dc_entries_dict[0x00000074] = dc_parser.struct_Eps2Inst1_FDIR_CMD_EXEC_STATUS_type
        self.dc_entries_dict[0x00000075] = dc_parser.struct_Eps3Inst0_UpTimeInSecondsType
        self.dc_entries_dict[0x00000076] = dc_parser.struct_Eps3Inst0CommonMeasurementType
        self.dc_entries_dict[0x00000077] = dc_parser.struct_Eps3Inst0HIBModeStatusType
        self.dc_entries_dict[0x00000078] = dc_parser.struct_Eps3Inst0MeasurementsType
        self.dc_entries_dict[0x00000079] = dc_parser.struct_Eps3Inst0DischargeStateType
        self.dc_entries_dict[0x0000007A] = dc_parser.struct_Eps3Inst0ChargeOnStatusType
        self.dc_entries_dict[0x0000007B] = dc_parser.struct_Eps3Inst0BalancersStatusType
        self.dc_entries_dict[0x0000007C] = dc_parser.struct_Eps3Inst0BatteryCellsStatusType
        self.dc_entries_dict[0x0000007D] = dc_parser.struct_Eps3Inst0HeatersStatusType
        self.dc_entries_dict[0x0000007E] = dc_parser.struct_Eps3Inst0_FDIR_CMD_EXEC_STATUS_type
        self.dc_entries_dict[0x0000007F] = dc_parser.struct_VoltAmps
        self.dc_entries_dict[0x00000080] = dc_parser.struct_VoltAllAmps
        self.dc_entries_dict[0x00000081] = dc_parser.struct_MpptState_str
        self.dc_entries_dict[0x00000082] = dc_parser.struct_ReadEnDftStatus
        self.dc_entries_dict[0x00000083] = dc_parser.struct_OnOffStatus
        self.dc_entries_dict[0x00000084] = dc_parser.struct_ReadLvlState
        self.dc_entries_dict[0x00000085] = dc_parser.struct_Eps3_PDM_A_Inst0_UpTimeInSecondsType
        self.dc_entries_dict[0x00000086] = dc_parser.struct_Eps3_PDM_A_Inst0_CommonMesurementsType
        self.dc_entries_dict[0x00000087] = dc_parser.struct_Eps3_PDM_A_Inst0_HibModeType
        self.dc_entries_dict[0x00000088] = dc_parser.struct_Eps3_PDM_A_Inst0_OutputsStatusType
        self.dc_entries_dict[0x00000089] = dc_parser.struct_Eps3_PDM_A_Inst0_FaultsStatusType
        self.dc_entries_dict[0x0000008A] = dc_parser.struct_Eps3_PDM_A_Inst0_VoltAmpsMeasurementsType
        self.dc_entries_dict[0x0000008B] = dc_parser.struct_Eps3_PDM_A_Inst0_FDIR_CMD_EXEC_STATUS_type
        self.dc_entries_dict[0x0000008C] = dc_parser.struct_Eps3_PDM_B_Inst0_FDIR_CMD_EXEC_STATUS_type
        self.dc_entries_dict[0x0000008D] = dc_parser.struct_Eps3_PDM_B_Inst0_UpTimeInSecondsType
        self.dc_entries_dict[0x0000008E] = dc_parser.struct_Eps3_PDM_B_Inst0_CommonMeasurementType
        self.dc_entries_dict[0x0000008F] = dc_parser.struct_Eps3_PDM_B_Inst0_hib_mode_Type
        self.dc_entries_dict[0x00000090] = dc_parser.struct_Eps3_PDM_B_Inst0_OutputsStatus_type
        self.dc_entries_dict[0x00000091] = dc_parser.struct_Eps3_PDM_B_Inst0_ChannelFlagState_type
        self.dc_entries_dict[0x00000092] = dc_parser.struct_Eps3_PDM_B_Inst0_Temps_type
        self.dc_entries_dict[0x00000093] = dc_parser.struct_Eps3_PDM_B_Inst0_VoltAmpsMeasurements_type
        self.dc_entries_dict[0x00000094] = dc_parser.struct_Eps3_EXPANDER_Inst0_FDIR_CMD_EXEC_STATUS_type
        self.dc_entries_dict[0x00000095] = dc_parser.struct_Eps3_EXPANDER_Inst0_UpTimeInSecondsType
        self.dc_entries_dict[0x00000096] = dc_parser.struct_Eps3_EXPANDER_Inst0_CommonMeasurementType
        self.dc_entries_dict[0x00000097] = dc_parser.struct_Eps3_EXPANDER_Inst0_DigitalOutputsType
        self.dc_entries_dict[0x00000098] = dc_parser.struct_Eps3_EXPANDER_Inst0_GeneralInputType
        self.dc_entries_dict[0x00000099] = dc_parser.struct_Eps3_EXPANDER_Inst0_FeedbackType
        self.dc_entries_dict[0x0000009A] = dc_parser.struct_Eps3_EXPANDER_Inst0_CurrentLimitersType
        self.dc_entries_dict[0x0000009B] = dc_parser.struct_Eps3_INPUT_STAGE_Inst0_UpTimeInSecondsType
        self.dc_entries_dict[0x0000009C] = dc_parser.struct_Eps3_INPUT_STAGE_Inst0CommonMeasurementType
        self.dc_entries_dict[0x0000009D] = dc_parser.struct_Eps3_INPUT_STAGE_Inst0hib_mode_status_type
        self.dc_entries_dict[0x0000009E] = dc_parser.struct_Eps3_INPUT_STAGE_Inst0selflock_on_type
        self.dc_entries_dict[0x0000009F] = dc_parser.struct_Eps3_INPUT_STAGE_Inst0Sp1InputDataType
        self.dc_entries_dict[0x000000A0] = dc_parser.struct_Eps3_INPUT_STAGE_Inst0Sp2InputDataType
        self.dc_entries_dict[0x000000A1] = dc_parser.struct_Eps3_INPUT_STAGE_Inst0Sp3InputDataType
        self.dc_entries_dict[0x000000A2] = dc_parser.struct_Eps3_INPUT_STAGE_Inst0SystemBusType
        self.dc_entries_dict[0x000000A3] = dc_parser.struct_Eps3_INPUT_STAGE_Inst0Bus7v5Type
        self.dc_entries_dict[0x000000A4] = dc_parser.struct_Eps3_INPUT_STAGE_Inst0bus_7v5_power_good_type
        self.dc_entries_dict[0x000000A5] = dc_parser.struct_Eps3_INPUT_STAGE_Inst0undervoltage_7V5_type
        self.dc_entries_dict[0x000000A6] = dc_parser.struct_Eps3_INPUT_STAGE_Inst0Bbus3v3Type
        self.dc_entries_dict[0x000000A7] = dc_parser.struct_Eps3_INPUT_STAGE_Inst0undervoltage_3V3_type
        self.dc_entries_dict[0x000000A8] = dc_parser.struct_Eps3_INPUT_STAGE_Inst0_FDIR_CMD_EXEC_STATUS_type

    def parse_by_id(self, id : int, data : bytes) -> any:
        if id in self.dc_entries_dict:
            return self.dc_entries_dict[id].deserialize(data, 0)
        else:
            return None
    
    class struct_OBC_0:
        def __init__(self, uint8__opMode = 0, uint32__upTime = 0, uint16__totalResetCount = 0, uint16__resetReasonBitField = 0, uint16__payloadModesStatus = 0):
            self.uint8__opMode = uint8__opMode
            self.uint32__upTime = uint32__upTime
            self.uint16__totalResetCount = uint16__totalResetCount
            self.uint16__resetReasonBitField = uint16__resetReasonBitField
            self.uint16__payloadModesStatus = uint16__payloadModesStatus
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__opMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__upTime)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__totalResetCount)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__resetReasonBitField)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__payloadModesStatus)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_OBC_0()
    
            currentPos = pos
            (resultInstance.uint8__opMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__upTime, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__totalResetCount, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__resetReasonBitField, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__payloadModesStatus, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 11
    
    class struct_ADCS_0:
        def __init__(self, a__int16__magFieldVec = [], a__int16__coarseSunVec = [], a__int16__fineSunVec = [], a__int16__nadirVec = [], a__int16__angRateVec = [], a__int16__wheelSpeedArr = []):
            self.a__int16__magFieldVec = a__int16__magFieldVec
            self.a__int16__coarseSunVec = a__int16__coarseSunVec
            self.a__int16__fineSunVec = a__int16__fineSunVec
            self.a__int16__nadirVec = a__int16__nadirVec
            self.a__int16__angRateVec = a__int16__angRateVec
            self.a__int16__wheelSpeedArr = a__int16__wheelSpeedArr
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basicArray.serialize("int16", self.a__int16__magFieldVec)
            result += SerDesHelpers.serdesType_basicArray.serialize("int16", self.a__int16__coarseSunVec)
            result += SerDesHelpers.serdesType_basicArray.serialize("int16", self.a__int16__fineSunVec)
            result += SerDesHelpers.serdesType_basicArray.serialize("int16", self.a__int16__nadirVec)
            result += SerDesHelpers.serdesType_basicArray.serialize("int16", self.a__int16__angRateVec)
            result += SerDesHelpers.serdesType_basicArray.serialize("int16", self.a__int16__wheelSpeedArr)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_ADCS_0()
    
            currentPos = pos
            (resultInstance.a__int16__magFieldVec, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("int16", data, currentPos, 3)
            currentPos += bytesProcessed
            (resultInstance.a__int16__coarseSunVec, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("int16", data, currentPos, 3)
            currentPos += bytesProcessed
            (resultInstance.a__int16__fineSunVec, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("int16", data, currentPos, 3)
            currentPos += bytesProcessed
            (resultInstance.a__int16__nadirVec, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("int16", data, currentPos, 3)
            currentPos += bytesProcessed
            (resultInstance.a__int16__angRateVec, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("int16", data, currentPos, 3)
            currentPos += bytesProcessed
            (resultInstance.a__int16__wheelSpeedArr, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("int16", data, currentPos, 3)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 36
    
    class struct_ADCS_1:
        def __init__(self, a__int16__estQSet = [], a__int16__estAngRateVec = [], a__int16__controlledAngles = [], a__int16__rawGyroRates = []):
            self.a__int16__estQSet = a__int16__estQSet
            self.a__int16__estAngRateVec = a__int16__estAngRateVec
            self.a__int16__controlledAngles = a__int16__controlledAngles
            self.a__int16__rawGyroRates = a__int16__rawGyroRates
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basicArray.serialize("int16", self.a__int16__estQSet)
            result += SerDesHelpers.serdesType_basicArray.serialize("int16", self.a__int16__estAngRateVec)
            result += SerDesHelpers.serdesType_basicArray.serialize("int16", self.a__int16__controlledAngles)
            result += SerDesHelpers.serdesType_basicArray.serialize("int16", self.a__int16__rawGyroRates)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_ADCS_1()
    
            currentPos = pos
            (resultInstance.a__int16__estQSet, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("int16", data, currentPos, 3)
            currentPos += bytesProcessed
            (resultInstance.a__int16__estAngRateVec, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("int16", data, currentPos, 3)
            currentPos += bytesProcessed
            (resultInstance.a__int16__controlledAngles, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("int16", data, currentPos, 3)
            currentPos += bytesProcessed
            (resultInstance.a__int16__rawGyroRates, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("int16", data, currentPos, 3)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 24
    
    class struct_ADCS_2:
        def __init__(self, a__uint8__adcsState = []):
            self.a__uint8__adcsState = a__uint8__adcsState
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basicArray.serialize("uint8", self.a__uint8__adcsState)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_ADCS_2()
    
            currentPos = pos
            (resultInstance.a__uint8__adcsState, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("uint8", data, currentPos, 6)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 6
    
    class struct_EPS_0:
        def __init__(self, int64__battEnergy = 0, int64__battCharge = 0, int64__battChargeCapacity = 0, int64__battPercent = 0, int32__battVoltage = 0, int32__battCurrent = 0, int32__battTemperature = 0):
            self.int64__battEnergy = int64__battEnergy
            self.int64__battCharge = int64__battCharge
            self.int64__battChargeCapacity = int64__battChargeCapacity
            self.int64__battPercent = int64__battPercent
            self.int32__battVoltage = int32__battVoltage
            self.int32__battCurrent = int32__battCurrent
            self.int32__battTemperature = int32__battTemperature
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("int64", self.int64__battEnergy)
            result += SerDesHelpers.serdesType_basic.serialize("int64", self.int64__battCharge)
            result += SerDesHelpers.serdesType_basic.serialize("int64", self.int64__battChargeCapacity)
            result += SerDesHelpers.serdesType_basic.serialize("int64", self.int64__battPercent)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__battVoltage)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__battCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__battTemperature)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_EPS_0()
    
            currentPos = pos
            (resultInstance.int64__battEnergy, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int64", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int64__battCharge, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int64", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int64__battChargeCapacity, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int64", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int64__battPercent, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int64", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__battVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__battCurrent, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__battTemperature, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 44
    
    class struct_SSP_0_Telemetry:
        def __init__(self, uint32__uptime = 0, uint16__sun_data_main = 0, uint8__sun_data_main_valid = 0, uint16__sun_data_ext = 0, uint8__sun_data_ext_valid = 0, int16__temp_data_main = 0, uint8__temp_data_main_valid = 0, int16__temp_data_ext1 = 0, uint8__temp_data_ext1_valid = 0, int16__temp_data_ext2 = 0, uint8__temp_data_ext2_valid = 0, int16__temp_data_mcu = 0, uint8__temp_data_mcu_valid = 0):
            self.uint32__uptime = uint32__uptime
            self.uint16__sun_data_main = uint16__sun_data_main
            self.uint8__sun_data_main_valid = uint8__sun_data_main_valid
            self.uint16__sun_data_ext = uint16__sun_data_ext
            self.uint8__sun_data_ext_valid = uint8__sun_data_ext_valid
            self.int16__temp_data_main = int16__temp_data_main
            self.uint8__temp_data_main_valid = uint8__temp_data_main_valid
            self.int16__temp_data_ext1 = int16__temp_data_ext1
            self.uint8__temp_data_ext1_valid = uint8__temp_data_ext1_valid
            self.int16__temp_data_ext2 = int16__temp_data_ext2
            self.uint8__temp_data_ext2_valid = uint8__temp_data_ext2_valid
            self.int16__temp_data_mcu = int16__temp_data_mcu
            self.uint8__temp_data_mcu_valid = uint8__temp_data_mcu_valid
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__uptime)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__sun_data_main)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__sun_data_main_valid)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__sun_data_ext)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__sun_data_ext_valid)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__temp_data_main)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__temp_data_main_valid)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__temp_data_ext1)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__temp_data_ext1_valid)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__temp_data_ext2)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__temp_data_ext2_valid)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__temp_data_mcu)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__temp_data_mcu_valid)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_SSP_0_Telemetry()
    
            currentPos = pos
            (resultInstance.uint32__uptime, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__sun_data_main, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__sun_data_main_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__sun_data_ext, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__sun_data_ext_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__temp_data_main, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__temp_data_main_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__temp_data_ext1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__temp_data_ext1_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__temp_data_ext2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__temp_data_ext2_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__temp_data_mcu, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__temp_data_mcu_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 22
    
    class struct_SSP_1_Telemetry:
        def __init__(self, uint32__uptime = 0, uint16__sun_data_main = 0, uint8__sun_data_main_valid = 0, uint16__sun_data_ext = 0, uint8__sun_data_ext_valid = 0, int16__temp_data_main = 0, uint8__temp_data_main_valid = 0, int16__temp_data_ext1 = 0, uint8__temp_data_ext1_valid = 0, int16__temp_data_ext2 = 0, uint8__temp_data_ext2_valid = 0, int16__temp_data_mcu = 0, uint8__temp_data_mcu_valid = 0):
            self.uint32__uptime = uint32__uptime
            self.uint16__sun_data_main = uint16__sun_data_main
            self.uint8__sun_data_main_valid = uint8__sun_data_main_valid
            self.uint16__sun_data_ext = uint16__sun_data_ext
            self.uint8__sun_data_ext_valid = uint8__sun_data_ext_valid
            self.int16__temp_data_main = int16__temp_data_main
            self.uint8__temp_data_main_valid = uint8__temp_data_main_valid
            self.int16__temp_data_ext1 = int16__temp_data_ext1
            self.uint8__temp_data_ext1_valid = uint8__temp_data_ext1_valid
            self.int16__temp_data_ext2 = int16__temp_data_ext2
            self.uint8__temp_data_ext2_valid = uint8__temp_data_ext2_valid
            self.int16__temp_data_mcu = int16__temp_data_mcu
            self.uint8__temp_data_mcu_valid = uint8__temp_data_mcu_valid
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__uptime)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__sun_data_main)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__sun_data_main_valid)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__sun_data_ext)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__sun_data_ext_valid)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__temp_data_main)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__temp_data_main_valid)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__temp_data_ext1)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__temp_data_ext1_valid)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__temp_data_ext2)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__temp_data_ext2_valid)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__temp_data_mcu)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__temp_data_mcu_valid)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_SSP_1_Telemetry()
    
            currentPos = pos
            (resultInstance.uint32__uptime, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__sun_data_main, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__sun_data_main_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__sun_data_ext, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__sun_data_ext_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__temp_data_main, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__temp_data_main_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__temp_data_ext1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__temp_data_ext1_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__temp_data_ext2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__temp_data_ext2_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__temp_data_mcu, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__temp_data_mcu_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 22
    
    class struct_SSP_2_Telemetry:
        def __init__(self, uint32__uptime = 0, uint16__sun_data_main = 0, uint8__sun_data_main_valid = 0, uint16__sun_data_ext = 0, uint8__sun_data_ext_valid = 0, int16__temp_data_main = 0, uint8__temp_data_main_valid = 0, int16__temp_data_ext1 = 0, uint8__temp_data_ext1_valid = 0, int16__temp_data_ext2 = 0, uint8__temp_data_ext2_valid = 0, int16__temp_data_mcu = 0, uint8__temp_data_mcu_valid = 0):
            self.uint32__uptime = uint32__uptime
            self.uint16__sun_data_main = uint16__sun_data_main
            self.uint8__sun_data_main_valid = uint8__sun_data_main_valid
            self.uint16__sun_data_ext = uint16__sun_data_ext
            self.uint8__sun_data_ext_valid = uint8__sun_data_ext_valid
            self.int16__temp_data_main = int16__temp_data_main
            self.uint8__temp_data_main_valid = uint8__temp_data_main_valid
            self.int16__temp_data_ext1 = int16__temp_data_ext1
            self.uint8__temp_data_ext1_valid = uint8__temp_data_ext1_valid
            self.int16__temp_data_ext2 = int16__temp_data_ext2
            self.uint8__temp_data_ext2_valid = uint8__temp_data_ext2_valid
            self.int16__temp_data_mcu = int16__temp_data_mcu
            self.uint8__temp_data_mcu_valid = uint8__temp_data_mcu_valid
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__uptime)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__sun_data_main)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__sun_data_main_valid)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__sun_data_ext)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__sun_data_ext_valid)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__temp_data_main)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__temp_data_main_valid)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__temp_data_ext1)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__temp_data_ext1_valid)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__temp_data_ext2)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__temp_data_ext2_valid)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__temp_data_mcu)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__temp_data_mcu_valid)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_SSP_2_Telemetry()
    
            currentPos = pos
            (resultInstance.uint32__uptime, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__sun_data_main, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__sun_data_main_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__sun_data_ext, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__sun_data_ext_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__temp_data_main, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__temp_data_main_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__temp_data_ext1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__temp_data_ext1_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__temp_data_ext2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__temp_data_ext2_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__temp_data_mcu, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__temp_data_mcu_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 22
    
    class struct_SSP_3_Telemetry:
        def __init__(self, uint32__uptime = 0, uint16__sun_data_main = 0, uint8__sun_data_main_valid = 0, uint16__sun_data_ext = 0, uint8__sun_data_ext_valid = 0, int16__temp_data_main = 0, uint8__temp_data_main_valid = 0, int16__temp_data_ext1 = 0, uint8__temp_data_ext1_valid = 0, int16__temp_data_ext2 = 0, uint8__temp_data_ext2_valid = 0, int16__temp_data_mcu = 0, uint8__temp_data_mcu_valid = 0):
            self.uint32__uptime = uint32__uptime
            self.uint16__sun_data_main = uint16__sun_data_main
            self.uint8__sun_data_main_valid = uint8__sun_data_main_valid
            self.uint16__sun_data_ext = uint16__sun_data_ext
            self.uint8__sun_data_ext_valid = uint8__sun_data_ext_valid
            self.int16__temp_data_main = int16__temp_data_main
            self.uint8__temp_data_main_valid = uint8__temp_data_main_valid
            self.int16__temp_data_ext1 = int16__temp_data_ext1
            self.uint8__temp_data_ext1_valid = uint8__temp_data_ext1_valid
            self.int16__temp_data_ext2 = int16__temp_data_ext2
            self.uint8__temp_data_ext2_valid = uint8__temp_data_ext2_valid
            self.int16__temp_data_mcu = int16__temp_data_mcu
            self.uint8__temp_data_mcu_valid = uint8__temp_data_mcu_valid
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__uptime)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__sun_data_main)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__sun_data_main_valid)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__sun_data_ext)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__sun_data_ext_valid)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__temp_data_main)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__temp_data_main_valid)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__temp_data_ext1)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__temp_data_ext1_valid)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__temp_data_ext2)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__temp_data_ext2_valid)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__temp_data_mcu)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__temp_data_mcu_valid)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_SSP_3_Telemetry()
    
            currentPos = pos
            (resultInstance.uint32__uptime, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__sun_data_main, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__sun_data_main_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__sun_data_ext, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__sun_data_ext_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__temp_data_main, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__temp_data_main_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__temp_data_ext1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__temp_data_ext1_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__temp_data_ext2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__temp_data_ext2_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__temp_data_mcu, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__temp_data_mcu_valid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 22
    
    class struct_AOCS_CNTRL_TLM:
        def __init__(self, uint32__adcsErrFlags = 0, int32__estAngRateNorm = 0, a__int32__estAngRateVec = [], a__int32__estAttAngles = [], a__int16__measWheelSpeed = []):
            self.uint32__adcsErrFlags = uint32__adcsErrFlags
            self.int32__estAngRateNorm = int32__estAngRateNorm
            self.a__int32__estAngRateVec = a__int32__estAngRateVec
            self.a__int32__estAttAngles = a__int32__estAttAngles
            self.a__int16__measWheelSpeed = a__int16__measWheelSpeed
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__adcsErrFlags)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__estAngRateNorm)
            result += SerDesHelpers.serdesType_basicArray.serialize("int32", self.a__int32__estAngRateVec)
            result += SerDesHelpers.serdesType_basicArray.serialize("int32", self.a__int32__estAttAngles)
            result += SerDesHelpers.serdesType_basicArray.serialize("int16", self.a__int16__measWheelSpeed)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_AOCS_CNTRL_TLM()
    
            currentPos = pos
            (resultInstance.uint32__adcsErrFlags, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__estAngRateNorm, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.a__int32__estAngRateVec, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("int32", data, currentPos, 3)
            currentPos += bytesProcessed
            (resultInstance.a__int32__estAttAngles, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("int32", data, currentPos, 3)
            currentPos += bytesProcessed
            (resultInstance.a__int16__measWheelSpeed, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("int16", data, currentPos, 4)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 40
    
    class struct_AOCS_CNTRL_SYS_STATE:
        def __init__(self, uint8__adcsSysState = 0, uint8__adcsSysStateStatus = 0):
            self.uint8__adcsSysState = uint8__adcsSysState
            self.uint8__adcsSysStateStatus = uint8__adcsSysStateStatus
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__adcsSysState)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__adcsSysStateStatus)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_AOCS_CNTRL_SYS_STATE()
    
            currentPos = pos
            (resultInstance.uint8__adcsSysState, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__adcsSysStateStatus, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 2
    
    class struct_AOCS_CNTRL_REF_PARAMS:
        def __init__(self, float__refParam1 = 0.0, float__refParam2 = 0.0, float__refParam3 = 0.0):
            self.float__refParam1 = float__refParam1
            self.float__refParam2 = float__refParam2
            self.float__refParam3 = float__refParam3
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_float.serialize(self.float__refParam1)
            result += SerDesHelpers.serdesType_float.serialize(self.float__refParam2)
            result += SerDesHelpers.serdesType_float.serialize(self.float__refParam3)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_AOCS_CNTRL_REF_PARAMS()
    
            currentPos = pos
            (resultInstance.float__refParam1, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__refParam2, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__refParam3, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 12
    
    class struct_SENSOR_GYRO_SENSOR_FRAME:
        def __init__(self, double__gyro_1 = 0.0, double__gyro_2 = 0.0, double__gyro_3 = 0.0):
            self.double__gyro_1 = double__gyro_1
            self.double__gyro_2 = double__gyro_2
            self.double__gyro_3 = double__gyro_3
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__gyro_1)
            result += SerDesHelpers.serdesType_double.serialize(self.double__gyro_2)
            result += SerDesHelpers.serdesType_double.serialize(self.double__gyro_3)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_SENSOR_GYRO_SENSOR_FRAME()
    
            currentPos = pos
            (resultInstance.double__gyro_1, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__gyro_2, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__gyro_3, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 24
    
    class struct_SENSOR_GYRO_BODY_FRAME:
        def __init__(self, double__gyro_x = 0.0, double__gyro_y = 0.0, double__gyro_z = 0.0):
            self.double__gyro_x = double__gyro_x
            self.double__gyro_y = double__gyro_y
            self.double__gyro_z = double__gyro_z
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__gyro_x)
            result += SerDesHelpers.serdesType_double.serialize(self.double__gyro_y)
            result += SerDesHelpers.serdesType_double.serialize(self.double__gyro_z)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_SENSOR_GYRO_BODY_FRAME()
    
            currentPos = pos
            (resultInstance.double__gyro_x, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__gyro_y, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__gyro_z, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 24
    
    class struct_SENSOR_MAG_PRIMARY_SENSOR_FRAME:
        def __init__(self, double__mag_x = 0.0, double__mag_y = 0.0, double__mag_z = 0.0):
            self.double__mag_x = double__mag_x
            self.double__mag_y = double__mag_y
            self.double__mag_z = double__mag_z
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_x)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_y)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_z)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_SENSOR_MAG_PRIMARY_SENSOR_FRAME()
    
            currentPos = pos
            (resultInstance.double__mag_x, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_y, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_z, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 24
    
    class struct_SENSOR_MAG_PRIMARY_BODY_FRAME:
        def __init__(self, double__mag_x_current = 0.0, double__mag_y_current = 0.0, double__mag_z_current = 0.0, double__mag_x_previous = 0.0, double__mag_y_previous = 0.0, double__mag_z_previous = 0.0):
            self.double__mag_x_current = double__mag_x_current
            self.double__mag_y_current = double__mag_y_current
            self.double__mag_z_current = double__mag_z_current
            self.double__mag_x_previous = double__mag_x_previous
            self.double__mag_y_previous = double__mag_y_previous
            self.double__mag_z_previous = double__mag_z_previous
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_x_current)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_y_current)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_z_current)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_x_previous)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_y_previous)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_z_previous)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_SENSOR_MAG_PRIMARY_BODY_FRAME()
    
            currentPos = pos
            (resultInstance.double__mag_x_current, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_y_current, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_z_current, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_x_previous, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_y_previous, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_z_previous, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 48
    
    class struct_SENSOR_MAG_SECONDARY_SENSOR_FRAME:
        def __init__(self, double__mag_x = 0.0, double__mag_y = 0.0, double__mag_z = 0.0):
            self.double__mag_x = double__mag_x
            self.double__mag_y = double__mag_y
            self.double__mag_z = double__mag_z
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_x)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_y)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_z)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_SENSOR_MAG_SECONDARY_SENSOR_FRAME()
    
            currentPos = pos
            (resultInstance.double__mag_x, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_y, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_z, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 24
    
    class struct_SENSOR_MAG_SECONDARY_BODY_FRAME:
        def __init__(self, double__mag_x_current = 0.0, double__mag_y_current = 0.0, double__mag_z_current = 0.0, double__mag_x_previous = 0.0, double__mag_y_previous = 0.0, double__mag_z_previous = 0.0):
            self.double__mag_x_current = double__mag_x_current
            self.double__mag_y_current = double__mag_y_current
            self.double__mag_z_current = double__mag_z_current
            self.double__mag_x_previous = double__mag_x_previous
            self.double__mag_y_previous = double__mag_y_previous
            self.double__mag_z_previous = double__mag_z_previous
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_x_current)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_y_current)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_z_current)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_x_previous)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_y_previous)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_z_previous)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_SENSOR_MAG_SECONDARY_BODY_FRAME()
    
            currentPos = pos
            (resultInstance.double__mag_x_current, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_y_current, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_z_current, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_x_previous, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_y_previous, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_z_previous, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 48
    
    class struct_SENSOR_COARSE_SUN_SENSOR_FRAME:
        def __init__(self, int32__css_panel_1 = 0, int32__css_panel_2 = 0, int32__css_panel_3 = 0, int32__css_panel_4 = 0, int32__css_panel_5 = 0, int32__css_panel_6 = 0):
            self.int32__css_panel_1 = int32__css_panel_1
            self.int32__css_panel_2 = int32__css_panel_2
            self.int32__css_panel_3 = int32__css_panel_3
            self.int32__css_panel_4 = int32__css_panel_4
            self.int32__css_panel_5 = int32__css_panel_5
            self.int32__css_panel_6 = int32__css_panel_6
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__css_panel_1)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__css_panel_2)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__css_panel_3)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__css_panel_4)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__css_panel_5)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__css_panel_6)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_SENSOR_COARSE_SUN_SENSOR_FRAME()
    
            currentPos = pos
            (resultInstance.int32__css_panel_1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__css_panel_2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__css_panel_3, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__css_panel_4, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__css_panel_5, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__css_panel_6, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 24
    
    class struct_SENSOR_COARSE_SUN_BODY_FRAME:
        def __init__(self, int32__css_axis_x_plus = 0, int32__css_axis_y_plus = 0, int32__css_axis_z_plus = 0, int32__css_axis_x_minus = 0, int32__css_axis_y_minus = 0, int32__css_axis_z_minus = 0):
            self.int32__css_axis_x_plus = int32__css_axis_x_plus
            self.int32__css_axis_y_plus = int32__css_axis_y_plus
            self.int32__css_axis_z_plus = int32__css_axis_z_plus
            self.int32__css_axis_x_minus = int32__css_axis_x_minus
            self.int32__css_axis_y_minus = int32__css_axis_y_minus
            self.int32__css_axis_z_minus = int32__css_axis_z_minus
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__css_axis_x_plus)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__css_axis_y_plus)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__css_axis_z_plus)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__css_axis_x_minus)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__css_axis_y_minus)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__css_axis_z_minus)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_SENSOR_COARSE_SUN_BODY_FRAME()
    
            currentPos = pos
            (resultInstance.int32__css_axis_x_plus, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__css_axis_y_plus, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__css_axis_z_plus, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__css_axis_x_minus, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__css_axis_y_minus, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__css_axis_z_minus, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 24
    
    class struct_SENSOR_PANEL_TEMP_SENSOR_FRAME:
        def __init__(self, double__PAN_1_TEMP = 0.0, double__PAN_2_TEMP = 0.0, double__PAN_3_TEMP = 0.0, double__PAN_4_TEMP = 0.0, double__PAN_5_TEMP = 0.0, double__PAN_6_TEMP = 0.0):
            self.double__PAN_1_TEMP = double__PAN_1_TEMP
            self.double__PAN_2_TEMP = double__PAN_2_TEMP
            self.double__PAN_3_TEMP = double__PAN_3_TEMP
            self.double__PAN_4_TEMP = double__PAN_4_TEMP
            self.double__PAN_5_TEMP = double__PAN_5_TEMP
            self.double__PAN_6_TEMP = double__PAN_6_TEMP
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__PAN_1_TEMP)
            result += SerDesHelpers.serdesType_double.serialize(self.double__PAN_2_TEMP)
            result += SerDesHelpers.serdesType_double.serialize(self.double__PAN_3_TEMP)
            result += SerDesHelpers.serdesType_double.serialize(self.double__PAN_4_TEMP)
            result += SerDesHelpers.serdesType_double.serialize(self.double__PAN_5_TEMP)
            result += SerDesHelpers.serdesType_double.serialize(self.double__PAN_6_TEMP)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_SENSOR_PANEL_TEMP_SENSOR_FRAME()
    
            currentPos = pos
            (resultInstance.double__PAN_1_TEMP, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__PAN_2_TEMP, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__PAN_3_TEMP, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__PAN_4_TEMP, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__PAN_5_TEMP, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__PAN_6_TEMP, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 48
    
    class struct_SENSOR_PANEL_TEMP_BODY_FRAME:
        def __init__(self, double__PAN_X_PLUS_TEMP = 0.0, double__PAN_Y_PLUS_TEMP = 0.0, double__PAN_Z_PLUS_TEMP = 0.0, double__PAN_X_MINUS_TEMP = 0.0, double__PAN_Y_MINUS_TEMP = 0.0, double__PAN_Z_MINUS_TEMP = 0.0):
            self.double__PAN_X_PLUS_TEMP = double__PAN_X_PLUS_TEMP
            self.double__PAN_Y_PLUS_TEMP = double__PAN_Y_PLUS_TEMP
            self.double__PAN_Z_PLUS_TEMP = double__PAN_Z_PLUS_TEMP
            self.double__PAN_X_MINUS_TEMP = double__PAN_X_MINUS_TEMP
            self.double__PAN_Y_MINUS_TEMP = double__PAN_Y_MINUS_TEMP
            self.double__PAN_Z_MINUS_TEMP = double__PAN_Z_MINUS_TEMP
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__PAN_X_PLUS_TEMP)
            result += SerDesHelpers.serdesType_double.serialize(self.double__PAN_Y_PLUS_TEMP)
            result += SerDesHelpers.serdesType_double.serialize(self.double__PAN_Z_PLUS_TEMP)
            result += SerDesHelpers.serdesType_double.serialize(self.double__PAN_X_MINUS_TEMP)
            result += SerDesHelpers.serdesType_double.serialize(self.double__PAN_Y_MINUS_TEMP)
            result += SerDesHelpers.serdesType_double.serialize(self.double__PAN_Z_MINUS_TEMP)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_SENSOR_PANEL_TEMP_BODY_FRAME()
    
            currentPos = pos
            (resultInstance.double__PAN_X_PLUS_TEMP, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__PAN_Y_PLUS_TEMP, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__PAN_Z_PLUS_TEMP, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__PAN_X_MINUS_TEMP, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__PAN_Y_MINUS_TEMP, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__PAN_Z_MINUS_TEMP, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 48
    
    class struct_SENSOR_GYRO_TEMP_SENSOR_FRAME:
        def __init__(self, double__GYRO_1_TEMP = 0.0, double__GYRO_2_TEMP = 0.0, double__GYRO_3_TEMP = 0.0):
            self.double__GYRO_1_TEMP = double__GYRO_1_TEMP
            self.double__GYRO_2_TEMP = double__GYRO_2_TEMP
            self.double__GYRO_3_TEMP = double__GYRO_3_TEMP
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__GYRO_1_TEMP)
            result += SerDesHelpers.serdesType_double.serialize(self.double__GYRO_2_TEMP)
            result += SerDesHelpers.serdesType_double.serialize(self.double__GYRO_3_TEMP)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_SENSOR_GYRO_TEMP_SENSOR_FRAME()
    
            currentPos = pos
            (resultInstance.double__GYRO_1_TEMP, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__GYRO_2_TEMP, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__GYRO_3_TEMP, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 24
    
    class struct_SENSOR_GYRO_TEMP_BODY_FRAME:
        def __init__(self, double__GYRO_X_TEMP = 0.0, double__GYRO_Y_TEMP = 0.0, double__GYRO_Z_TEMP = 0.0):
            self.double__GYRO_X_TEMP = double__GYRO_X_TEMP
            self.double__GYRO_Y_TEMP = double__GYRO_Y_TEMP
            self.double__GYRO_Z_TEMP = double__GYRO_Z_TEMP
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__GYRO_X_TEMP)
            result += SerDesHelpers.serdesType_double.serialize(self.double__GYRO_Y_TEMP)
            result += SerDesHelpers.serdesType_double.serialize(self.double__GYRO_Z_TEMP)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_SENSOR_GYRO_TEMP_BODY_FRAME()
    
            currentPos = pos
            (resultInstance.double__GYRO_X_TEMP, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__GYRO_Y_TEMP, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__GYRO_Z_TEMP, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 24
    
    class struct_ACTUATOR_MTQ_VALUES:
        def __init__(self, int8__Magnetorquer_value_x = 0, int8__Magnetorquer_value_y = 0, int8__Magnetorquer_value_z = 0):
            self.int8__Magnetorquer_value_x = int8__Magnetorquer_value_x
            self.int8__Magnetorquer_value_y = int8__Magnetorquer_value_y
            self.int8__Magnetorquer_value_z = int8__Magnetorquer_value_z
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("int8", self.int8__Magnetorquer_value_x)
            result += SerDesHelpers.serdesType_basic.serialize("int8", self.int8__Magnetorquer_value_y)
            result += SerDesHelpers.serdesType_basic.serialize("int8", self.int8__Magnetorquer_value_z)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_ACTUATOR_MTQ_VALUES()
    
            currentPos = pos
            (resultInstance.int8__Magnetorquer_value_x, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int8__Magnetorquer_value_y, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int8__Magnetorquer_value_z, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 3
    
    class struct_ACTUATOR_TORQUE_VALUES:
        def __init__(self, double__Required_torque_x = 0.0, double__Required_torque_y = 0.0, double__Required_torque_z = 0.0):
            self.double__Required_torque_x = double__Required_torque_x
            self.double__Required_torque_y = double__Required_torque_y
            self.double__Required_torque_z = double__Required_torque_z
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__Required_torque_x)
            result += SerDesHelpers.serdesType_double.serialize(self.double__Required_torque_y)
            result += SerDesHelpers.serdesType_double.serialize(self.double__Required_torque_z)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_ACTUATOR_TORQUE_VALUES()
    
            currentPos = pos
            (resultInstance.double__Required_torque_x, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__Required_torque_y, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__Required_torque_z, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 24
    
    class struct_ADCS_3:
        def __init__(self, int16__est_roll_angle = 0, int16__est_pitch_angle = 0, int16__est_yaw_angle = 0, int16__IGRF_MagField_X = 0, int16__IGRF_MagField_Y = 0, int16__IGRF_MagField_Z = 0, int16__Modelled_Sun_V_X = 0, int16__Modelled_Sun_V_Y = 0, int16__Modelled_Sun_V_Z = 0, int16__EstGyroBias_X = 0, int16__EstGyroBias_Y = 0, int16__EstGyroBias_Z = 0, int16__Innovation_Vec_X = 0, int16__Innovation_Vec_Y = 0, int16__Innovation_Vec_Z = 0, int16__Err_Q1 = 0, int16__Err_Q2 = 0, int16__Err_Q3 = 0, int16__RMS_Q1 = 0, int16__RMS_Q2 = 0, int16__RMS_Q3 = 0, int16__X_AngRate_Cov = 0, int16__Y_AngRate_Cov = 0, int16__Z_AngRate_Cov = 0, int16__X_Rate = 0, int16__Y_Rate = 0, int16__Z_Rate = 0, int16__Q0 = 0, int16__Q1 = 0, int16__Q2 = 0):
            self.int16__est_roll_angle = int16__est_roll_angle
            self.int16__est_pitch_angle = int16__est_pitch_angle
            self.int16__est_yaw_angle = int16__est_yaw_angle
            self.int16__IGRF_MagField_X = int16__IGRF_MagField_X
            self.int16__IGRF_MagField_Y = int16__IGRF_MagField_Y
            self.int16__IGRF_MagField_Z = int16__IGRF_MagField_Z
            self.int16__Modelled_Sun_V_X = int16__Modelled_Sun_V_X
            self.int16__Modelled_Sun_V_Y = int16__Modelled_Sun_V_Y
            self.int16__Modelled_Sun_V_Z = int16__Modelled_Sun_V_Z
            self.int16__EstGyroBias_X = int16__EstGyroBias_X
            self.int16__EstGyroBias_Y = int16__EstGyroBias_Y
            self.int16__EstGyroBias_Z = int16__EstGyroBias_Z
            self.int16__Innovation_Vec_X = int16__Innovation_Vec_X
            self.int16__Innovation_Vec_Y = int16__Innovation_Vec_Y
            self.int16__Innovation_Vec_Z = int16__Innovation_Vec_Z
            self.int16__Err_Q1 = int16__Err_Q1
            self.int16__Err_Q2 = int16__Err_Q2
            self.int16__Err_Q3 = int16__Err_Q3
            self.int16__RMS_Q1 = int16__RMS_Q1
            self.int16__RMS_Q2 = int16__RMS_Q2
            self.int16__RMS_Q3 = int16__RMS_Q3
            self.int16__X_AngRate_Cov = int16__X_AngRate_Cov
            self.int16__Y_AngRate_Cov = int16__Y_AngRate_Cov
            self.int16__Z_AngRate_Cov = int16__Z_AngRate_Cov
            self.int16__X_Rate = int16__X_Rate
            self.int16__Y_Rate = int16__Y_Rate
            self.int16__Z_Rate = int16__Z_Rate
            self.int16__Q0 = int16__Q0
            self.int16__Q1 = int16__Q1
            self.int16__Q2 = int16__Q2
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__est_roll_angle)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__est_pitch_angle)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__est_yaw_angle)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__IGRF_MagField_X)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__IGRF_MagField_Y)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__IGRF_MagField_Z)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Modelled_Sun_V_X)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Modelled_Sun_V_Y)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Modelled_Sun_V_Z)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__EstGyroBias_X)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__EstGyroBias_Y)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__EstGyroBias_Z)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Innovation_Vec_X)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Innovation_Vec_Y)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Innovation_Vec_Z)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Err_Q1)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Err_Q2)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Err_Q3)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__RMS_Q1)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__RMS_Q2)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__RMS_Q3)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__X_AngRate_Cov)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Y_AngRate_Cov)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Z_AngRate_Cov)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__X_Rate)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Y_Rate)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Z_Rate)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Q0)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Q1)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Q2)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_ADCS_3()
    
            currentPos = pos
            (resultInstance.int16__est_roll_angle, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__est_pitch_angle, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__est_yaw_angle, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__IGRF_MagField_X, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__IGRF_MagField_Y, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__IGRF_MagField_Z, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Modelled_Sun_V_X, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Modelled_Sun_V_Y, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Modelled_Sun_V_Z, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__EstGyroBias_X, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__EstGyroBias_Y, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__EstGyroBias_Z, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Innovation_Vec_X, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Innovation_Vec_Y, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Innovation_Vec_Z, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Err_Q1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Err_Q2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Err_Q3, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__RMS_Q1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__RMS_Q2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__RMS_Q3, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__X_AngRate_Cov, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Y_AngRate_Cov, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Z_AngRate_Cov, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__X_Rate, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Y_Rate, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Z_Rate, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Q0, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Q1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Q2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 60
    
    class struct_ADCS_4:
        def __init__(self, uint16__Cubesense1_3V3_Current = 0, uint16__Cubesense1_SRAM_Current = 0, uint16__Cubesense2_3V3_Current = 0, uint16__Cubesense2_SRAM_Current = 0, uint16__CubeControl_3V3_Current = 0, uint16__CubeControl_5V_Current = 0, uint16__CubeControl_Vbat_Current = 0, uint16__Wheel_1_Current = 0, uint16__Wheel_2_Current = 0, uint16__Wheel_3_Current = 0, uint16__CubeStar_Current = 0, uint16__MTQ_Current = 0, int16__CubeStar_MCU_Temp = 0, int16__ADCS_MCU_Temp = 0, int16__MTM_Temp = 0, int16__RMTM_Temp = 0, int16__X_Rate_Sensor_Temp = 0, int16__Y_Rate_Sensor_Temp = 0, int16__Z_Rate_Sensor_Temp = 0):
            self.uint16__Cubesense1_3V3_Current = uint16__Cubesense1_3V3_Current
            self.uint16__Cubesense1_SRAM_Current = uint16__Cubesense1_SRAM_Current
            self.uint16__Cubesense2_3V3_Current = uint16__Cubesense2_3V3_Current
            self.uint16__Cubesense2_SRAM_Current = uint16__Cubesense2_SRAM_Current
            self.uint16__CubeControl_3V3_Current = uint16__CubeControl_3V3_Current
            self.uint16__CubeControl_5V_Current = uint16__CubeControl_5V_Current
            self.uint16__CubeControl_Vbat_Current = uint16__CubeControl_Vbat_Current
            self.uint16__Wheel_1_Current = uint16__Wheel_1_Current
            self.uint16__Wheel_2_Current = uint16__Wheel_2_Current
            self.uint16__Wheel_3_Current = uint16__Wheel_3_Current
            self.uint16__CubeStar_Current = uint16__CubeStar_Current
            self.uint16__MTQ_Current = uint16__MTQ_Current
            self.int16__CubeStar_MCU_Temp = int16__CubeStar_MCU_Temp
            self.int16__ADCS_MCU_Temp = int16__ADCS_MCU_Temp
            self.int16__MTM_Temp = int16__MTM_Temp
            self.int16__RMTM_Temp = int16__RMTM_Temp
            self.int16__X_Rate_Sensor_Temp = int16__X_Rate_Sensor_Temp
            self.int16__Y_Rate_Sensor_Temp = int16__Y_Rate_Sensor_Temp
            self.int16__Z_Rate_Sensor_Temp = int16__Z_Rate_Sensor_Temp
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cubesense1_3V3_Current)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cubesense1_SRAM_Current)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cubesense2_3V3_Current)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cubesense2_SRAM_Current)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__CubeControl_3V3_Current)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__CubeControl_5V_Current)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__CubeControl_Vbat_Current)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Wheel_1_Current)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Wheel_2_Current)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Wheel_3_Current)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__CubeStar_Current)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__MTQ_Current)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__CubeStar_MCU_Temp)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__ADCS_MCU_Temp)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__MTM_Temp)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__RMTM_Temp)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__X_Rate_Sensor_Temp)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Y_Rate_Sensor_Temp)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Z_Rate_Sensor_Temp)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_ADCS_4()
    
            currentPos = pos
            (resultInstance.uint16__Cubesense1_3V3_Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Cubesense1_SRAM_Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Cubesense2_3V3_Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Cubesense2_SRAM_Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__CubeControl_3V3_Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__CubeControl_5V_Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__CubeControl_Vbat_Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Wheel_1_Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Wheel_2_Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Wheel_3_Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__CubeStar_Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__MTQ_Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__CubeStar_MCU_Temp, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__ADCS_MCU_Temp, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__MTM_Temp, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__RMTM_Temp, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__X_Rate_Sensor_Temp, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Y_Rate_Sensor_Temp, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Z_Rate_Sensor_Temp, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 38
    
    class struct_EPS_9:
        def __init__(self, int32__In_SysBUS_Voltage = 0, int32__Out_BatRAW_Output_Sense_U = 0, int32__Out_BatRAW_Output_Sense_I = 0, int32__Out_BatRAW_Output_Sense_P = 0, int32__Out_12V_Output_Sense_U = 0, int32__Out_12V_Output_Sense_I = 0, int32__Out_12V_Output_Sense_P = 0, int32__Out_12V_Output_ILimit = 0, int32__Out_5V_Output1_Sense_U = 0, int32__Out_5V_Output1_Sense_I = 0, int32__Out_5V_Output1_Sense_P = 0, int32__Out_5V_Output1_ILimit = 0, int32__Out_5V_Output2_Sense_U = 0, int32__Out_5V_Output2_Sense_I = 0, int32__Out_5V_Output2_Sense_P = 0, int32__Out_5V_Output2_ILimit = 0, int32__Out_3V3_Output1_Sense_U = 0, int32__Out_3V3_Output1_Sense_I = 0, int32__Out_3V3_Output1_Sense_P = 0, int32__Out_3V3_Output1_ILimit = 0, int32__Out_3V3_Output2_Sense_U = 0, int32__Out_3V3_Output2_Sense_I = 0, int32__Out_3V3_Output2_Sense_P = 0, int32__Out_3V3_Output2_ILimit = 0):
            self.int32__In_SysBUS_Voltage = int32__In_SysBUS_Voltage
            self.int32__Out_BatRAW_Output_Sense_U = int32__Out_BatRAW_Output_Sense_U
            self.int32__Out_BatRAW_Output_Sense_I = int32__Out_BatRAW_Output_Sense_I
            self.int32__Out_BatRAW_Output_Sense_P = int32__Out_BatRAW_Output_Sense_P
            self.int32__Out_12V_Output_Sense_U = int32__Out_12V_Output_Sense_U
            self.int32__Out_12V_Output_Sense_I = int32__Out_12V_Output_Sense_I
            self.int32__Out_12V_Output_Sense_P = int32__Out_12V_Output_Sense_P
            self.int32__Out_12V_Output_ILimit = int32__Out_12V_Output_ILimit
            self.int32__Out_5V_Output1_Sense_U = int32__Out_5V_Output1_Sense_U
            self.int32__Out_5V_Output1_Sense_I = int32__Out_5V_Output1_Sense_I
            self.int32__Out_5V_Output1_Sense_P = int32__Out_5V_Output1_Sense_P
            self.int32__Out_5V_Output1_ILimit = int32__Out_5V_Output1_ILimit
            self.int32__Out_5V_Output2_Sense_U = int32__Out_5V_Output2_Sense_U
            self.int32__Out_5V_Output2_Sense_I = int32__Out_5V_Output2_Sense_I
            self.int32__Out_5V_Output2_Sense_P = int32__Out_5V_Output2_Sense_P
            self.int32__Out_5V_Output2_ILimit = int32__Out_5V_Output2_ILimit
            self.int32__Out_3V3_Output1_Sense_U = int32__Out_3V3_Output1_Sense_U
            self.int32__Out_3V3_Output1_Sense_I = int32__Out_3V3_Output1_Sense_I
            self.int32__Out_3V3_Output1_Sense_P = int32__Out_3V3_Output1_Sense_P
            self.int32__Out_3V3_Output1_ILimit = int32__Out_3V3_Output1_ILimit
            self.int32__Out_3V3_Output2_Sense_U = int32__Out_3V3_Output2_Sense_U
            self.int32__Out_3V3_Output2_Sense_I = int32__Out_3V3_Output2_Sense_I
            self.int32__Out_3V3_Output2_Sense_P = int32__Out_3V3_Output2_Sense_P
            self.int32__Out_3V3_Output2_ILimit = int32__Out_3V3_Output2_ILimit
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__In_SysBUS_Voltage)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_BatRAW_Output_Sense_U)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_BatRAW_Output_Sense_I)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_BatRAW_Output_Sense_P)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_12V_Output_Sense_U)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_12V_Output_Sense_I)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_12V_Output_Sense_P)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_12V_Output_ILimit)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_5V_Output1_Sense_U)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_5V_Output1_Sense_I)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_5V_Output1_Sense_P)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_5V_Output1_ILimit)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_5V_Output2_Sense_U)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_5V_Output2_Sense_I)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_5V_Output2_Sense_P)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_5V_Output2_ILimit)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_3V3_Output1_Sense_U)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_3V3_Output1_Sense_I)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_3V3_Output1_Sense_P)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_3V3_Output1_ILimit)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_3V3_Output2_Sense_U)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_3V3_Output2_Sense_I)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_3V3_Output2_Sense_P)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Out_3V3_Output2_ILimit)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_EPS_9()
    
            currentPos = pos
            (resultInstance.int32__In_SysBUS_Voltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_BatRAW_Output_Sense_U, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_BatRAW_Output_Sense_I, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_BatRAW_Output_Sense_P, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_12V_Output_Sense_U, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_12V_Output_Sense_I, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_12V_Output_Sense_P, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_12V_Output_ILimit, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_5V_Output1_Sense_U, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_5V_Output1_Sense_I, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_5V_Output1_Sense_P, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_5V_Output1_ILimit, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_5V_Output2_Sense_U, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_5V_Output2_Sense_I, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_5V_Output2_Sense_P, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_5V_Output2_ILimit, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_3V3_Output1_Sense_U, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_3V3_Output1_Sense_I, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_3V3_Output1_Sense_P, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_3V3_Output1_ILimit, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_3V3_Output2_Sense_U, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_3V3_Output2_Sense_I, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_3V3_Output2_Sense_P, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Out_3V3_Output2_ILimit, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 96
    
    class struct_EPS_10:
        def __init__(self, int32__ActiveCPU_RunningTime = 0, int32__ActiveCPU_Voltage = 0, int32__ActiveCPU_Temperature = 0, int32__PCB_Temperature_1 = 0, int32__PCB_Temperature_2 = 0, int32__NVM_AllocatedSize = 0, int32__NVM_UsedSize = 0, int32__Stack_AllocatedSize = 0, int32__Stack_UsedSize = 0, uint8__DPOT_MCP4562_LUP_3V3_1P = 0, uint8__DPOT_MCP4562_LUP_3V3_1R = 0, uint8__DPOT_MCP4562_LUP_3V3_2P = 0, uint8__DPOT_MCP4562_LUP_3V3_2R = 0, uint8__DPOT_MCP4562_LUP_5V_1P = 0, uint8__DPOT_MCP4562_LUP_5V_1R = 0, uint8__DPOT_MCP4562_LUP_5V_2P = 0, uint8__DPOT_MCP4562_LUP_5V_2R = 0, uint8__DPOT_MCP4562_LUP_12V_P = 0, uint8__DPOT_MCP4562_LUP_12V_R = 0, uint8__DPOT_MCP4562_OUTU_12V_P = 0, uint8__DPOT_MCP4562_OUTU_12V_R = 0, uint8__GPIO_PCA9538_U1001 = 0, uint8__GPIO_PCA9538_U1000 = 0, uint8__GPIO_PCA9538_U1004 = 0, uint8__GPIO_PCA9538_U1011 = 0, uint8__INA_LUP_IN_3V3_1P = 0, uint8__INA_LUP_IN_3V3_1R = 0, uint8__INA_LUP_IN_3V3_2P = 0, uint8__INA_LUP_IN_3V3_2R = 0, uint8__INA_LUP_IN_5V_1P = 0, uint8__INA_LUP_IN_5V_1R = 0, uint8__INA_LUP_IN_5V_2P = 0, uint8__INA_LUP_IN_5V_2R = 0, uint8__INA_LUP_IN_12V_P = 0, uint8__INA_LUP_IN_12V_R = 0, uint8__TMP117_U1014 = 0, uint8__TMP117_U1031 = 0):
            self.int32__ActiveCPU_RunningTime = int32__ActiveCPU_RunningTime
            self.int32__ActiveCPU_Voltage = int32__ActiveCPU_Voltage
            self.int32__ActiveCPU_Temperature = int32__ActiveCPU_Temperature
            self.int32__PCB_Temperature_1 = int32__PCB_Temperature_1
            self.int32__PCB_Temperature_2 = int32__PCB_Temperature_2
            self.int32__NVM_AllocatedSize = int32__NVM_AllocatedSize
            self.int32__NVM_UsedSize = int32__NVM_UsedSize
            self.int32__Stack_AllocatedSize = int32__Stack_AllocatedSize
            self.int32__Stack_UsedSize = int32__Stack_UsedSize
            self.uint8__DPOT_MCP4562_LUP_3V3_1P = uint8__DPOT_MCP4562_LUP_3V3_1P
            self.uint8__DPOT_MCP4562_LUP_3V3_1R = uint8__DPOT_MCP4562_LUP_3V3_1R
            self.uint8__DPOT_MCP4562_LUP_3V3_2P = uint8__DPOT_MCP4562_LUP_3V3_2P
            self.uint8__DPOT_MCP4562_LUP_3V3_2R = uint8__DPOT_MCP4562_LUP_3V3_2R
            self.uint8__DPOT_MCP4562_LUP_5V_1P = uint8__DPOT_MCP4562_LUP_5V_1P
            self.uint8__DPOT_MCP4562_LUP_5V_1R = uint8__DPOT_MCP4562_LUP_5V_1R
            self.uint8__DPOT_MCP4562_LUP_5V_2P = uint8__DPOT_MCP4562_LUP_5V_2P
            self.uint8__DPOT_MCP4562_LUP_5V_2R = uint8__DPOT_MCP4562_LUP_5V_2R
            self.uint8__DPOT_MCP4562_LUP_12V_P = uint8__DPOT_MCP4562_LUP_12V_P
            self.uint8__DPOT_MCP4562_LUP_12V_R = uint8__DPOT_MCP4562_LUP_12V_R
            self.uint8__DPOT_MCP4562_OUTU_12V_P = uint8__DPOT_MCP4562_OUTU_12V_P
            self.uint8__DPOT_MCP4562_OUTU_12V_R = uint8__DPOT_MCP4562_OUTU_12V_R
            self.uint8__GPIO_PCA9538_U1001 = uint8__GPIO_PCA9538_U1001
            self.uint8__GPIO_PCA9538_U1000 = uint8__GPIO_PCA9538_U1000
            self.uint8__GPIO_PCA9538_U1004 = uint8__GPIO_PCA9538_U1004
            self.uint8__GPIO_PCA9538_U1011 = uint8__GPIO_PCA9538_U1011
            self.uint8__INA_LUP_IN_3V3_1P = uint8__INA_LUP_IN_3V3_1P
            self.uint8__INA_LUP_IN_3V3_1R = uint8__INA_LUP_IN_3V3_1R
            self.uint8__INA_LUP_IN_3V3_2P = uint8__INA_LUP_IN_3V3_2P
            self.uint8__INA_LUP_IN_3V3_2R = uint8__INA_LUP_IN_3V3_2R
            self.uint8__INA_LUP_IN_5V_1P = uint8__INA_LUP_IN_5V_1P
            self.uint8__INA_LUP_IN_5V_1R = uint8__INA_LUP_IN_5V_1R
            self.uint8__INA_LUP_IN_5V_2P = uint8__INA_LUP_IN_5V_2P
            self.uint8__INA_LUP_IN_5V_2R = uint8__INA_LUP_IN_5V_2R
            self.uint8__INA_LUP_IN_12V_P = uint8__INA_LUP_IN_12V_P
            self.uint8__INA_LUP_IN_12V_R = uint8__INA_LUP_IN_12V_R
            self.uint8__TMP117_U1014 = uint8__TMP117_U1014
            self.uint8__TMP117_U1031 = uint8__TMP117_U1031
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__ActiveCPU_RunningTime)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__ActiveCPU_Voltage)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__ActiveCPU_Temperature)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__PCB_Temperature_1)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__PCB_Temperature_2)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__NVM_AllocatedSize)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__NVM_UsedSize)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Stack_AllocatedSize)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Stack_UsedSize)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__DPOT_MCP4562_LUP_3V3_1P)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__DPOT_MCP4562_LUP_3V3_1R)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__DPOT_MCP4562_LUP_3V3_2P)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__DPOT_MCP4562_LUP_3V3_2R)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__DPOT_MCP4562_LUP_5V_1P)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__DPOT_MCP4562_LUP_5V_1R)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__DPOT_MCP4562_LUP_5V_2P)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__DPOT_MCP4562_LUP_5V_2R)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__DPOT_MCP4562_LUP_12V_P)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__DPOT_MCP4562_LUP_12V_R)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__DPOT_MCP4562_OUTU_12V_P)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__DPOT_MCP4562_OUTU_12V_R)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__GPIO_PCA9538_U1001)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__GPIO_PCA9538_U1000)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__GPIO_PCA9538_U1004)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__GPIO_PCA9538_U1011)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__INA_LUP_IN_3V3_1P)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__INA_LUP_IN_3V3_1R)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__INA_LUP_IN_3V3_2P)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__INA_LUP_IN_3V3_2R)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__INA_LUP_IN_5V_1P)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__INA_LUP_IN_5V_1R)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__INA_LUP_IN_5V_2P)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__INA_LUP_IN_5V_2R)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__INA_LUP_IN_12V_P)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__INA_LUP_IN_12V_R)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__TMP117_U1014)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__TMP117_U1031)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_EPS_10()
    
            currentPos = pos
            (resultInstance.int32__ActiveCPU_RunningTime, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__ActiveCPU_Voltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__ActiveCPU_Temperature, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__PCB_Temperature_1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__PCB_Temperature_2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__NVM_AllocatedSize, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__NVM_UsedSize, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Stack_AllocatedSize, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Stack_UsedSize, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__DPOT_MCP4562_LUP_3V3_1P, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__DPOT_MCP4562_LUP_3V3_1R, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__DPOT_MCP4562_LUP_3V3_2P, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__DPOT_MCP4562_LUP_3V3_2R, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__DPOT_MCP4562_LUP_5V_1P, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__DPOT_MCP4562_LUP_5V_1R, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__DPOT_MCP4562_LUP_5V_2P, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__DPOT_MCP4562_LUP_5V_2R, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__DPOT_MCP4562_LUP_12V_P, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__DPOT_MCP4562_LUP_12V_R, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__DPOT_MCP4562_OUTU_12V_P, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__DPOT_MCP4562_OUTU_12V_R, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__GPIO_PCA9538_U1001, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__GPIO_PCA9538_U1000, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__GPIO_PCA9538_U1004, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__GPIO_PCA9538_U1011, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__INA_LUP_IN_3V3_1P, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__INA_LUP_IN_3V3_1R, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__INA_LUP_IN_3V3_2P, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__INA_LUP_IN_3V3_2R, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__INA_LUP_IN_5V_1P, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__INA_LUP_IN_5V_1R, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__INA_LUP_IN_5V_2P, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__INA_LUP_IN_5V_2R, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__INA_LUP_IN_12V_P, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__INA_LUP_IN_12V_R, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__TMP117_U1014, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__TMP117_U1031, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 64
    
    class struct_EPS_14:
        def __init__(self, a__int32__pdm_1_54_values = []):
            self.a__int32__pdm_1_54_values = a__int32__pdm_1_54_values
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basicArray.serialize("int32", self.a__int32__pdm_1_54_values)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_EPS_14()
    
            currentPos = pos
            (resultInstance.a__int32__pdm_1_54_values, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("int32", data, currentPos, 54)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 216
    
    class struct_CUBEADCS_GEN2_OP_STATUS_COMMON:
        def __init__(self, uint8__State = 0, uint8__ResetReason = 0, bool__DualBankBoot = False, bool__AppReadError = False, bool__AppEmptyError = False, bool__AppTypeError = False, bool__AppVectTblError = False, bool__ConfigReadError = False, bool__ConfigEmptyError = False, bool__ConfigTypeError = False, bool__ConfigMismatchError = False, bool__SharedParamsError = False, bool__PortValidationError = False, bool__PortDiscoveryError = False, bool__OtpSerialError = False, bool__CfgSerialError = False, bool__SerialMismatchError = False, bool__ConfigUnlockError = False, bool__ConfigInvalidError = False, uint8__rwl0 = 0, uint8__rwl1 = 0, uint8__rwl2 = 0, uint8__rwl3 = 0, uint8__mag0 = 0, uint8__mag1 = 0, uint8__gyro0 = 0, uint8__gyro1 = 0, uint8__fss0 = 0, uint8__fss1 = 0, uint8__fss2 = 0, uint8__fss3 = 0, uint8__hss0 = 0, uint8__hss1 = 0, uint8__str0 = 0, uint8__str1 = 0, uint8__extSensor0 = 0, uint8__extSensor1 = 0, uint32__MasterSvc = 0, uint32__FramFsSvc = 0, uint32__EventLogSvc = 0, uint32__ImgLogSvc = 0, uint32__TlmLogSvc = 0, uint32__ImuSvc = 0):
            self.uint8__State = uint8__State
            self.uint8__ResetReason = uint8__ResetReason
            self.bool__DualBankBoot = bool__DualBankBoot
            self.bool__AppReadError = bool__AppReadError
            self.bool__AppEmptyError = bool__AppEmptyError
            self.bool__AppTypeError = bool__AppTypeError
            self.bool__AppVectTblError = bool__AppVectTblError
            self.bool__ConfigReadError = bool__ConfigReadError
            self.bool__ConfigEmptyError = bool__ConfigEmptyError
            self.bool__ConfigTypeError = bool__ConfigTypeError
            self.bool__ConfigMismatchError = bool__ConfigMismatchError
            self.bool__SharedParamsError = bool__SharedParamsError
            self.bool__PortValidationError = bool__PortValidationError
            self.bool__PortDiscoveryError = bool__PortDiscoveryError
            self.bool__OtpSerialError = bool__OtpSerialError
            self.bool__CfgSerialError = bool__CfgSerialError
            self.bool__SerialMismatchError = bool__SerialMismatchError
            self.bool__ConfigUnlockError = bool__ConfigUnlockError
            self.bool__ConfigInvalidError = bool__ConfigInvalidError
            self.uint8__rwl0 = uint8__rwl0
            self.uint8__rwl1 = uint8__rwl1
            self.uint8__rwl2 = uint8__rwl2
            self.uint8__rwl3 = uint8__rwl3
            self.uint8__mag0 = uint8__mag0
            self.uint8__mag1 = uint8__mag1
            self.uint8__gyro0 = uint8__gyro0
            self.uint8__gyro1 = uint8__gyro1
            self.uint8__fss0 = uint8__fss0
            self.uint8__fss1 = uint8__fss1
            self.uint8__fss2 = uint8__fss2
            self.uint8__fss3 = uint8__fss3
            self.uint8__hss0 = uint8__hss0
            self.uint8__hss1 = uint8__hss1
            self.uint8__str0 = uint8__str0
            self.uint8__str1 = uint8__str1
            self.uint8__extSensor0 = uint8__extSensor0
            self.uint8__extSensor1 = uint8__extSensor1
            self.uint32__MasterSvc = uint32__MasterSvc
            self.uint32__FramFsSvc = uint32__FramFsSvc
            self.uint32__EventLogSvc = uint32__EventLogSvc
            self.uint32__ImgLogSvc = uint32__ImgLogSvc
            self.uint32__TlmLogSvc = uint32__TlmLogSvc
            self.uint32__ImuSvc = uint32__ImuSvc
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__State)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__ResetReason)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__DualBankBoot)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__AppReadError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__AppEmptyError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__AppTypeError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__AppVectTblError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__ConfigReadError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__ConfigEmptyError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__ConfigTypeError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__ConfigMismatchError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__SharedParamsError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__PortValidationError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__PortDiscoveryError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__OtpSerialError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__CfgSerialError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__SerialMismatchError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__ConfigUnlockError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__ConfigInvalidError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__rwl0)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__rwl1)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__rwl2)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__rwl3)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__mag0)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__mag1)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__gyro0)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__gyro1)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__fss0)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__fss1)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__fss2)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__fss3)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__hss0)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__hss1)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__extSensor0)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__extSensor1)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__MasterSvc)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__FramFsSvc)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__EventLogSvc)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__ImgLogSvc)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__TlmLogSvc)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__ImuSvc)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_OP_STATUS_COMMON()
    
            currentPos = pos
            (resultInstance.uint8__State, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__ResetReason, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__DualBankBoot, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__AppReadError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__AppEmptyError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__AppTypeError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__AppVectTblError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__ConfigReadError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__ConfigEmptyError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__ConfigTypeError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__ConfigMismatchError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__SharedParamsError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__PortValidationError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__PortDiscoveryError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__OtpSerialError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__CfgSerialError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__SerialMismatchError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__ConfigUnlockError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__ConfigInvalidError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__rwl0, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__rwl1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__rwl2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__rwl3, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__mag0, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__mag1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__gyro0, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__gyro1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__fss0, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__fss1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__fss2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__fss3, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__hss0, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__hss1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__extSensor0, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__extSensor1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__MasterSvc, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__FramFsSvc, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__EventLogSvc, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__ImgLogSvc, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__TlmLogSvc, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__ImuSvc, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 61
    
    class struct_CUBEADCS_GEN2_OP_STATUS_APP:
        def __init__(self, uint8__run_mode = 0, uint8__control_mode = 0, uint16__magnetic_control_timeout = 0, uint8__estimator_main = 0, uint8__estimator_backup = 0, uint8__adcs_op_state = 0):
            self.uint8__run_mode = uint8__run_mode
            self.uint8__control_mode = uint8__control_mode
            self.uint16__magnetic_control_timeout = uint16__magnetic_control_timeout
            self.uint8__estimator_main = uint8__estimator_main
            self.uint8__estimator_backup = uint8__estimator_backup
            self.uint8__adcs_op_state = uint8__adcs_op_state
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__run_mode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__control_mode)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__magnetic_control_timeout)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__estimator_main)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__estimator_backup)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__adcs_op_state)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_OP_STATUS_APP()
    
            currentPos = pos
            (resultInstance.uint8__run_mode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__control_mode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__magnetic_control_timeout, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__estimator_main, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__estimator_backup, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__adcs_op_state, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 7
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_166:
        def __init__(self, double__str0McuTemp = 0.0, double__str0McuCurrent = 0.0, uint16__str0McuVoltage = 0, double__str0Pst3sCurrent = 0.0, bool__str0Pst3sOvercurrent = False, double__str1McuTemp = 0.0, double__str1McuCurrent = 0.0, uint16__str1McuVoltage = 0, double__str1Pst3sCurrent = 0.0, bool__str1Pst3sOvercurrent = False):
            self.double__str0McuTemp = double__str0McuTemp
            self.double__str0McuCurrent = double__str0McuCurrent
            self.uint16__str0McuVoltage = uint16__str0McuVoltage
            self.double__str0Pst3sCurrent = double__str0Pst3sCurrent
            self.bool__str0Pst3sOvercurrent = bool__str0Pst3sOvercurrent
            self.double__str1McuTemp = double__str1McuTemp
            self.double__str1McuCurrent = double__str1McuCurrent
            self.uint16__str1McuVoltage = uint16__str1McuVoltage
            self.double__str1Pst3sCurrent = double__str1Pst3sCurrent
            self.bool__str1Pst3sOvercurrent = bool__str1Pst3sOvercurrent
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__str0McuVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0Pst3sCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__str0Pst3sOvercurrent)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__str1McuVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1Pst3sCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__str1Pst3sOvercurrent)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_166()
    
            currentPos = pos
            (resultInstance.double__str0McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__str0McuVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0Pst3sCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__str0Pst3sOvercurrent, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__str1McuVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1Pst3sCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__str1Pst3sOvercurrent, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 54
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_167:
        def __init__(self, double__mag0McuTemp = 0.0, double__mag0McuCurrent = 0.0, uint16__mag0McuVoltage = 0, double__mag0PrimaryTemp = 0.0, double__mag0RedTemp = 0.0, uint32__mag0BurnCurrent = 0, bool__mag0DeployPinState = False, bool__mag0BurnPinState = False, bool__mag0BurnUnderCurrent = False, bool__mag0BurnOverCurrent = False, bool__mag0DeployTimeout = False, double__mag1McuTemp = 0.0, double__mag1McuCurrent = 0.0, uint16__mag1McuVoltage = 0, double__mag1PrimaryTemp = 0.0, double__mag1RedTemp = 0.0, uint32__mag1BurnCurrent = 0, bool__mag1DeployPinState = False, bool__mag1BurnPinState = False, bool__mag1BurnUnderCurrent = False, bool__mag1BurnOverCurrent = False, bool__mag1DeployTimeout = False):
            self.double__mag0McuTemp = double__mag0McuTemp
            self.double__mag0McuCurrent = double__mag0McuCurrent
            self.uint16__mag0McuVoltage = uint16__mag0McuVoltage
            self.double__mag0PrimaryTemp = double__mag0PrimaryTemp
            self.double__mag0RedTemp = double__mag0RedTemp
            self.uint32__mag0BurnCurrent = uint32__mag0BurnCurrent
            self.bool__mag0DeployPinState = bool__mag0DeployPinState
            self.bool__mag0BurnPinState = bool__mag0BurnPinState
            self.bool__mag0BurnUnderCurrent = bool__mag0BurnUnderCurrent
            self.bool__mag0BurnOverCurrent = bool__mag0BurnOverCurrent
            self.bool__mag0DeployTimeout = bool__mag0DeployTimeout
            self.double__mag1McuTemp = double__mag1McuTemp
            self.double__mag1McuCurrent = double__mag1McuCurrent
            self.uint16__mag1McuVoltage = uint16__mag1McuVoltage
            self.double__mag1PrimaryTemp = double__mag1PrimaryTemp
            self.double__mag1RedTemp = double__mag1RedTemp
            self.uint32__mag1BurnCurrent = uint32__mag1BurnCurrent
            self.bool__mag1DeployPinState = bool__mag1DeployPinState
            self.bool__mag1BurnPinState = bool__mag1BurnPinState
            self.bool__mag1BurnUnderCurrent = bool__mag1BurnUnderCurrent
            self.bool__mag1BurnOverCurrent = bool__mag1BurnOverCurrent
            self.bool__mag1DeployTimeout = bool__mag1DeployTimeout
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag0McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag0McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__mag0McuVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag0PrimaryTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag0RedTemp)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__mag0BurnCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__mag0DeployPinState)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__mag0BurnPinState)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__mag0BurnUnderCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__mag0BurnOverCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__mag0DeployTimeout)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag1McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag1McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__mag1McuVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag1PrimaryTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag1RedTemp)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__mag1BurnCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__mag1DeployPinState)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__mag1BurnPinState)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__mag1BurnUnderCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__mag1BurnOverCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__mag1DeployTimeout)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_167()
    
            currentPos = pos
            (resultInstance.double__mag0McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag0McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__mag0McuVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag0PrimaryTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag0RedTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__mag0BurnCurrent, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__mag0DeployPinState, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__mag0BurnPinState, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__mag0BurnUnderCurrent, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__mag0BurnOverCurrent, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__mag0DeployTimeout, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag1McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag1McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__mag1McuVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag1PrimaryTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag1RedTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__mag1BurnCurrent, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__mag1DeployPinState, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__mag1BurnPinState, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__mag1BurnUnderCurrent, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__mag1BurnOverCurrent, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__mag1DeployTimeout, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 86
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_168:
        def __init__(self, double__fss0McuTemp = 0.0, double__fss0McuCurrent = 0.0, uint16__fss0McuVoltage = 0, double__fss0CurrentCam = 0.0, double__fss0CurrentSram = 0.0, bool__fss0OvercurrentCam = False, bool__fss0OvercurrentSram = False, double__fss1McuTemp = 0.0, double__fss1McuCurrent = 0.0, uint16__fss1McuVoltage = 0, double__fss1CurrentCam = 0.0, double__fss1CurrentSram = 0.0, bool__fss1OvercurrentCam = False, bool__fss1OvercurrentSram = False, double__fss2McuTemp = 0.0, double__fss2McuCurrent = 0.0, uint16__fss2McuVoltage = 0, double__fss2CurrentCam = 0.0, double__fss2CurrentSram = 0.0, bool__fss2OvercurrentCam = False, bool__fss2OvercurrentSram = False, double__fss3McuTemp = 0.0, double__fss3McuCurrent = 0.0, uint16__fss3McuVoltage = 0, double__fss3CurrentCam = 0.0, double__fss3CurrentSram = 0.0, bool__fss3OvercurrentCam = False, bool__fss3OvercurrentSram = False):
            self.double__fss0McuTemp = double__fss0McuTemp
            self.double__fss0McuCurrent = double__fss0McuCurrent
            self.uint16__fss0McuVoltage = uint16__fss0McuVoltage
            self.double__fss0CurrentCam = double__fss0CurrentCam
            self.double__fss0CurrentSram = double__fss0CurrentSram
            self.bool__fss0OvercurrentCam = bool__fss0OvercurrentCam
            self.bool__fss0OvercurrentSram = bool__fss0OvercurrentSram
            self.double__fss1McuTemp = double__fss1McuTemp
            self.double__fss1McuCurrent = double__fss1McuCurrent
            self.uint16__fss1McuVoltage = uint16__fss1McuVoltage
            self.double__fss1CurrentCam = double__fss1CurrentCam
            self.double__fss1CurrentSram = double__fss1CurrentSram
            self.bool__fss1OvercurrentCam = bool__fss1OvercurrentCam
            self.bool__fss1OvercurrentSram = bool__fss1OvercurrentSram
            self.double__fss2McuTemp = double__fss2McuTemp
            self.double__fss2McuCurrent = double__fss2McuCurrent
            self.uint16__fss2McuVoltage = uint16__fss2McuVoltage
            self.double__fss2CurrentCam = double__fss2CurrentCam
            self.double__fss2CurrentSram = double__fss2CurrentSram
            self.bool__fss2OvercurrentCam = bool__fss2OvercurrentCam
            self.bool__fss2OvercurrentSram = bool__fss2OvercurrentSram
            self.double__fss3McuTemp = double__fss3McuTemp
            self.double__fss3McuCurrent = double__fss3McuCurrent
            self.uint16__fss3McuVoltage = uint16__fss3McuVoltage
            self.double__fss3CurrentCam = double__fss3CurrentCam
            self.double__fss3CurrentSram = double__fss3CurrentSram
            self.bool__fss3OvercurrentCam = bool__fss3OvercurrentCam
            self.bool__fss3OvercurrentSram = bool__fss3OvercurrentSram
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss0McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss0McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__fss0McuVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss0CurrentCam)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss0CurrentSram)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss0OvercurrentCam)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss0OvercurrentSram)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss1McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss1McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__fss1McuVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss1CurrentCam)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss1CurrentSram)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss1OvercurrentCam)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss1OvercurrentSram)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss2McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss2McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__fss2McuVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss2CurrentCam)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss2CurrentSram)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss2OvercurrentCam)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss2OvercurrentSram)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss3McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss3McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__fss3McuVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss3CurrentCam)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss3CurrentSram)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss3OvercurrentCam)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss3OvercurrentSram)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_168()
    
            currentPos = pos
            (resultInstance.double__fss0McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss0McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__fss0McuVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss0CurrentCam, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss0CurrentSram, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss0OvercurrentCam, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss0OvercurrentSram, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss1McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss1McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__fss1McuVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss1CurrentCam, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss1CurrentSram, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss1OvercurrentCam, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss1OvercurrentSram, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss2McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss2McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__fss2McuVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss2CurrentCam, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss2CurrentSram, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss2OvercurrentCam, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss2OvercurrentSram, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss3McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss3McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__fss3McuVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss3CurrentCam, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss3CurrentSram, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss3OvercurrentCam, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss3OvercurrentSram, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 144
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_169:
        def __init__(self, float__mtq1TotalCurrentPeakPos = 0.0, float__mtq1TotalCurrentAveragePos = 0.0, float__mtq1TotalCurrentPeakNeg = 0.0, float__mtq1TotalCurrentAverageNeg = 0.0, float__mtq2TotalCurrentPeakPos = 0.0, float__mtq2TotalCurrentAveragePos = 0.0, float__mtq2TotalCurrentPeakNeg = 0.0, float__mtq2TotalCurrentAverageNeg = 0.0, float__mtq3TotalCurrentPeakPos = 0.0, float__mtq3TotalCurrentAveragePos = 0.0, float__mtq3TotalCurrentPeakNeg = 0.0, float__mtq3TotalCurrentAverageNeg = 0.0, uint8__mtq1Polarity = 0, uint8__mtq2Polarity = 0, uint8__mtq3Polarity = 0):
            self.float__mtq1TotalCurrentPeakPos = float__mtq1TotalCurrentPeakPos
            self.float__mtq1TotalCurrentAveragePos = float__mtq1TotalCurrentAveragePos
            self.float__mtq1TotalCurrentPeakNeg = float__mtq1TotalCurrentPeakNeg
            self.float__mtq1TotalCurrentAverageNeg = float__mtq1TotalCurrentAverageNeg
            self.float__mtq2TotalCurrentPeakPos = float__mtq2TotalCurrentPeakPos
            self.float__mtq2TotalCurrentAveragePos = float__mtq2TotalCurrentAveragePos
            self.float__mtq2TotalCurrentPeakNeg = float__mtq2TotalCurrentPeakNeg
            self.float__mtq2TotalCurrentAverageNeg = float__mtq2TotalCurrentAverageNeg
            self.float__mtq3TotalCurrentPeakPos = float__mtq3TotalCurrentPeakPos
            self.float__mtq3TotalCurrentAveragePos = float__mtq3TotalCurrentAveragePos
            self.float__mtq3TotalCurrentPeakNeg = float__mtq3TotalCurrentPeakNeg
            self.float__mtq3TotalCurrentAverageNeg = float__mtq3TotalCurrentAverageNeg
            self.uint8__mtq1Polarity = uint8__mtq1Polarity
            self.uint8__mtq2Polarity = uint8__mtq2Polarity
            self.uint8__mtq3Polarity = uint8__mtq3Polarity
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_float.serialize(self.float__mtq1TotalCurrentPeakPos)
            result += SerDesHelpers.serdesType_float.serialize(self.float__mtq1TotalCurrentAveragePos)
            result += SerDesHelpers.serdesType_float.serialize(self.float__mtq1TotalCurrentPeakNeg)
            result += SerDesHelpers.serdesType_float.serialize(self.float__mtq1TotalCurrentAverageNeg)
            result += SerDesHelpers.serdesType_float.serialize(self.float__mtq2TotalCurrentPeakPos)
            result += SerDesHelpers.serdesType_float.serialize(self.float__mtq2TotalCurrentAveragePos)
            result += SerDesHelpers.serdesType_float.serialize(self.float__mtq2TotalCurrentPeakNeg)
            result += SerDesHelpers.serdesType_float.serialize(self.float__mtq2TotalCurrentAverageNeg)
            result += SerDesHelpers.serdesType_float.serialize(self.float__mtq3TotalCurrentPeakPos)
            result += SerDesHelpers.serdesType_float.serialize(self.float__mtq3TotalCurrentAveragePos)
            result += SerDesHelpers.serdesType_float.serialize(self.float__mtq3TotalCurrentPeakNeg)
            result += SerDesHelpers.serdesType_float.serialize(self.float__mtq3TotalCurrentAverageNeg)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__mtq1Polarity)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__mtq2Polarity)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__mtq3Polarity)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_169()
    
            currentPos = pos
            (resultInstance.float__mtq1TotalCurrentPeakPos, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__mtq1TotalCurrentAveragePos, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__mtq1TotalCurrentPeakNeg, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__mtq1TotalCurrentAverageNeg, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__mtq2TotalCurrentPeakPos, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__mtq2TotalCurrentAveragePos, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__mtq2TotalCurrentPeakNeg, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__mtq2TotalCurrentAverageNeg, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__mtq3TotalCurrentPeakPos, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__mtq3TotalCurrentAveragePos, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__mtq3TotalCurrentPeakNeg, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__mtq3TotalCurrentAverageNeg, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__mtq1Polarity, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__mtq2Polarity, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__mtq3Polarity, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 51
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_170:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, double__fss0Alpha = 0.0, double__fss0Beta = 0.0, uint8__fss0CaptureResult = 0, uint8__fss0DetectionResult = 0, double__fss1Alpha = 0.0, double__fss1Beta = 0.0, uint8__fss1CaptureResult = 0, uint8__fss1DetectionResult = 0, double__fss2Alpha = 0.0, double__fss2Beta = 0.0, uint8__fss2CaptureResult = 0, uint8__fss2DetectionResult = 0, double__fss3Alpha = 0.0, double__fss3Beta = 0.0, uint8__fss3CaptureResult = 0, uint8__fss3DetectionResult = 0, bool__fss0IsValid = False, bool__fss1IsValid = False, bool__fss2IsValid = False, bool__fss3IsValid = False):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.double__fss0Alpha = double__fss0Alpha
            self.double__fss0Beta = double__fss0Beta
            self.uint8__fss0CaptureResult = uint8__fss0CaptureResult
            self.uint8__fss0DetectionResult = uint8__fss0DetectionResult
            self.double__fss1Alpha = double__fss1Alpha
            self.double__fss1Beta = double__fss1Beta
            self.uint8__fss1CaptureResult = uint8__fss1CaptureResult
            self.uint8__fss1DetectionResult = uint8__fss1DetectionResult
            self.double__fss2Alpha = double__fss2Alpha
            self.double__fss2Beta = double__fss2Beta
            self.uint8__fss2CaptureResult = uint8__fss2CaptureResult
            self.uint8__fss2DetectionResult = uint8__fss2DetectionResult
            self.double__fss3Alpha = double__fss3Alpha
            self.double__fss3Beta = double__fss3Beta
            self.uint8__fss3CaptureResult = uint8__fss3CaptureResult
            self.uint8__fss3DetectionResult = uint8__fss3DetectionResult
            self.bool__fss0IsValid = bool__fss0IsValid
            self.bool__fss1IsValid = bool__fss1IsValid
            self.bool__fss2IsValid = bool__fss2IsValid
            self.bool__fss3IsValid = bool__fss3IsValid
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss0Alpha)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss0Beta)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__fss0CaptureResult)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__fss0DetectionResult)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss1Alpha)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss1Beta)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__fss1CaptureResult)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__fss1DetectionResult)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss2Alpha)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss2Beta)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__fss2CaptureResult)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__fss2DetectionResult)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss3Alpha)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss3Beta)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__fss3CaptureResult)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__fss3DetectionResult)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss0IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss1IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss2IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss3IsValid)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_170()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss0Alpha, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss0Beta, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__fss0CaptureResult, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__fss0DetectionResult, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss1Alpha, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss1Beta, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__fss1CaptureResult, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__fss1DetectionResult, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss2Alpha, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss2Beta, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__fss2CaptureResult, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__fss2DetectionResult, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss3Alpha, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss3Beta, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__fss3CaptureResult, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__fss3DetectionResult, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss0IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss1IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss2IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss3IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 84
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_171:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, float__extSensor0Float0 = 0.0, float__extSensor0Float1 = 0.0, float__extSensor0Float2 = 0.0, float__extSensor0Float3 = 0.0, float__extSensor0Float4 = 0.0, float__extSensor0Float5 = 0.0, float__extSensor1Float0 = 0.0, float__extSensor1Float1 = 0.0, float__extSensor1Float2 = 0.0, float__extSensor1Float3 = 0.0, float__extSensor1Float4 = 0.0, float__extSensor1Float5 = 0.0, bool__extSensor0IsValid = False, bool__extSensor1IsValid = False):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.float__extSensor0Float0 = float__extSensor0Float0
            self.float__extSensor0Float1 = float__extSensor0Float1
            self.float__extSensor0Float2 = float__extSensor0Float2
            self.float__extSensor0Float3 = float__extSensor0Float3
            self.float__extSensor0Float4 = float__extSensor0Float4
            self.float__extSensor0Float5 = float__extSensor0Float5
            self.float__extSensor1Float0 = float__extSensor1Float0
            self.float__extSensor1Float1 = float__extSensor1Float1
            self.float__extSensor1Float2 = float__extSensor1Float2
            self.float__extSensor1Float3 = float__extSensor1Float3
            self.float__extSensor1Float4 = float__extSensor1Float4
            self.float__extSensor1Float5 = float__extSensor1Float5
            self.bool__extSensor0IsValid = bool__extSensor0IsValid
            self.bool__extSensor1IsValid = bool__extSensor1IsValid
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_float.serialize(self.float__extSensor0Float0)
            result += SerDesHelpers.serdesType_float.serialize(self.float__extSensor0Float1)
            result += SerDesHelpers.serdesType_float.serialize(self.float__extSensor0Float2)
            result += SerDesHelpers.serdesType_float.serialize(self.float__extSensor0Float3)
            result += SerDesHelpers.serdesType_float.serialize(self.float__extSensor0Float4)
            result += SerDesHelpers.serdesType_float.serialize(self.float__extSensor0Float5)
            result += SerDesHelpers.serdesType_float.serialize(self.float__extSensor1Float0)
            result += SerDesHelpers.serdesType_float.serialize(self.float__extSensor1Float1)
            result += SerDesHelpers.serdesType_float.serialize(self.float__extSensor1Float2)
            result += SerDesHelpers.serdesType_float.serialize(self.float__extSensor1Float3)
            result += SerDesHelpers.serdesType_float.serialize(self.float__extSensor1Float4)
            result += SerDesHelpers.serdesType_float.serialize(self.float__extSensor1Float5)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__extSensor0IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__extSensor1IsValid)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_171()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__extSensor0Float0, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__extSensor0Float1, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__extSensor0Float2, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__extSensor0Float3, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__extSensor0Float4, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__extSensor0Float5, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__extSensor1Float0, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__extSensor1Float1, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__extSensor1Float2, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__extSensor1Float3, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__extSensor1Float4, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__extSensor1Float5, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__extSensor0IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__extSensor1IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 58
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_172:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, double__rpyCmdRoll = 0.0, double__rpyCmdPitch = 0.0, double__rpyCmdYaw = 0.0, double__rpyErrRoll = 0.0, double__rpyErrPitch = 0.0, double__rpyErrYaw = 0.0, float__tgtRefLat = 0.0, float__tgtRefLon = 0.0, float__tgtRefAlt = 0.0, double__quatErrQ0 = 0.0, double__quatErrQ1 = 0.0, double__quatErrQ2 = 0.0, float__rwl0CmdSpeed = 0.0, float__rwl1CmdSpeed = 0.0, float__rwl2CmdSpeed = 0.0, float__rwl3CmdSpeed = 0.0, float__rwl0CmdMom = 0.0, float__rwl1CmdMom = 0.0, float__rwl2CmdMom = 0.0, float__rwl3CmdMom = 0.0, float__rwl0CmdTorque = 0.0, float__rwl1CmdTorque = 0.0, float__rwl2CmdTorque = 0.0, float__rwl3CmdTorque = 0.0, double__mtq0CmdDip = 0.0, double__mtq1CmdDip = 0.0, double__mtq2CmdDip = 0.0, float__mtq0CmdTorque = 0.0, float__mtq1CmdTorque = 0.0, float__mtq2CmdTorque = 0.0, int16__mtq0CmdOnTime = 0, int16__mtq1CmdOnTime = 0, int16__mtq2CmdOnTime = 0, uint16__magConTimeout = 0, uint8__conModeActive = 0, bool__rwl0ErrorFlag = False, bool__rwl1ErrorFlag = False, bool__rwl2ErrorFlag = False, bool__rwl3ErrorFlag = False, bool__rwl0ActiveFlag = False, bool__rwl1ActiveFlag = False, bool__rwl2ActiveFlag = False, bool__rwl3ActiveFlag = False, uint8__fmcStage = 0):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.double__rpyCmdRoll = double__rpyCmdRoll
            self.double__rpyCmdPitch = double__rpyCmdPitch
            self.double__rpyCmdYaw = double__rpyCmdYaw
            self.double__rpyErrRoll = double__rpyErrRoll
            self.double__rpyErrPitch = double__rpyErrPitch
            self.double__rpyErrYaw = double__rpyErrYaw
            self.float__tgtRefLat = float__tgtRefLat
            self.float__tgtRefLon = float__tgtRefLon
            self.float__tgtRefAlt = float__tgtRefAlt
            self.double__quatErrQ0 = double__quatErrQ0
            self.double__quatErrQ1 = double__quatErrQ1
            self.double__quatErrQ2 = double__quatErrQ2
            self.float__rwl0CmdSpeed = float__rwl0CmdSpeed
            self.float__rwl1CmdSpeed = float__rwl1CmdSpeed
            self.float__rwl2CmdSpeed = float__rwl2CmdSpeed
            self.float__rwl3CmdSpeed = float__rwl3CmdSpeed
            self.float__rwl0CmdMom = float__rwl0CmdMom
            self.float__rwl1CmdMom = float__rwl1CmdMom
            self.float__rwl2CmdMom = float__rwl2CmdMom
            self.float__rwl3CmdMom = float__rwl3CmdMom
            self.float__rwl0CmdTorque = float__rwl0CmdTorque
            self.float__rwl1CmdTorque = float__rwl1CmdTorque
            self.float__rwl2CmdTorque = float__rwl2CmdTorque
            self.float__rwl3CmdTorque = float__rwl3CmdTorque
            self.double__mtq0CmdDip = double__mtq0CmdDip
            self.double__mtq1CmdDip = double__mtq1CmdDip
            self.double__mtq2CmdDip = double__mtq2CmdDip
            self.float__mtq0CmdTorque = float__mtq0CmdTorque
            self.float__mtq1CmdTorque = float__mtq1CmdTorque
            self.float__mtq2CmdTorque = float__mtq2CmdTorque
            self.int16__mtq0CmdOnTime = int16__mtq0CmdOnTime
            self.int16__mtq1CmdOnTime = int16__mtq1CmdOnTime
            self.int16__mtq2CmdOnTime = int16__mtq2CmdOnTime
            self.uint16__magConTimeout = uint16__magConTimeout
            self.uint8__conModeActive = uint8__conModeActive
            self.bool__rwl0ErrorFlag = bool__rwl0ErrorFlag
            self.bool__rwl1ErrorFlag = bool__rwl1ErrorFlag
            self.bool__rwl2ErrorFlag = bool__rwl2ErrorFlag
            self.bool__rwl3ErrorFlag = bool__rwl3ErrorFlag
            self.bool__rwl0ActiveFlag = bool__rwl0ActiveFlag
            self.bool__rwl1ActiveFlag = bool__rwl1ActiveFlag
            self.bool__rwl2ActiveFlag = bool__rwl2ActiveFlag
            self.bool__rwl3ActiveFlag = bool__rwl3ActiveFlag
            self.uint8__fmcStage = uint8__fmcStage
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rpyCmdRoll)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rpyCmdPitch)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rpyCmdYaw)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rpyErrRoll)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rpyErrPitch)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rpyErrYaw)
            result += SerDesHelpers.serdesType_float.serialize(self.float__tgtRefLat)
            result += SerDesHelpers.serdesType_float.serialize(self.float__tgtRefLon)
            result += SerDesHelpers.serdesType_float.serialize(self.float__tgtRefAlt)
            result += SerDesHelpers.serdesType_double.serialize(self.double__quatErrQ0)
            result += SerDesHelpers.serdesType_double.serialize(self.double__quatErrQ1)
            result += SerDesHelpers.serdesType_double.serialize(self.double__quatErrQ2)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl0CmdSpeed)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl1CmdSpeed)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl2CmdSpeed)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl3CmdSpeed)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl0CmdMom)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl1CmdMom)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl2CmdMom)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl3CmdMom)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl0CmdTorque)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl1CmdTorque)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl2CmdTorque)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl3CmdTorque)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mtq0CmdDip)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mtq1CmdDip)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mtq2CmdDip)
            result += SerDesHelpers.serdesType_float.serialize(self.float__mtq0CmdTorque)
            result += SerDesHelpers.serdesType_float.serialize(self.float__mtq1CmdTorque)
            result += SerDesHelpers.serdesType_float.serialize(self.float__mtq2CmdTorque)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__mtq0CmdOnTime)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__mtq1CmdOnTime)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__mtq2CmdOnTime)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__magConTimeout)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__conModeActive)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl0ErrorFlag)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl1ErrorFlag)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl2ErrorFlag)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl3ErrorFlag)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl0ActiveFlag)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl1ActiveFlag)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl2ActiveFlag)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl3ActiveFlag)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__fmcStage)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_172()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rpyCmdRoll, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rpyCmdPitch, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rpyCmdYaw, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rpyErrRoll, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rpyErrPitch, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rpyErrYaw, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__tgtRefLat, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__tgtRefLon, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__tgtRefAlt, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__quatErrQ0, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__quatErrQ1, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__quatErrQ2, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl0CmdSpeed, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl1CmdSpeed, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl2CmdSpeed, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl3CmdSpeed, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl0CmdMom, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl1CmdMom, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl2CmdMom, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl3CmdMom, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl0CmdTorque, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl1CmdTorque, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl2CmdTorque, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl3CmdTorque, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mtq0CmdDip, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mtq1CmdDip, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mtq2CmdDip, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__mtq0CmdTorque, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__mtq1CmdTorque, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__mtq2CmdTorque, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__mtq0CmdOnTime, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__mtq1CmdOnTime, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__mtq2CmdOnTime, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__magConTimeout, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__conModeActive, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl0ErrorFlag, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl1ErrorFlag, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl2ErrorFlag, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl3ErrorFlag, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl0ActiveFlag, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl1ActiveFlag, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl2ActiveFlag, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl3ActiveFlag, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__fmcStage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 194
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_173:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, double__estRpyRoll = 0.0, double__estRpyPitch = 0.0, double__estRpyYaw = 0.0, double__estQuatQ0 = 0.0, double__estQuatQ1 = 0.0, double__estQuatQ2 = 0.0, double__estQuatQ3 = 0.0, double__estGyroBiasX = 0.0, double__estGyroBiasY = 0.0, double__estGyroBiasZ = 0.0, double__estRateOrcX = 0.0, double__estRateOrcY = 0.0, double__estRateOrcZ = 0.0, double__estRateIrcX = 0.0, double__estRateIrcY = 0.0, double__estRateIrcZ = 0.0, float__estGyrTorqueX = 0.0, float__estGyrTorqueY = 0.0, float__estGyrTorqueZ = 0.0, double__estInnovX = 0.0, double__estInnovY = 0.0, double__estInnovZ = 0.0, double__estStdDevRateX = 0.0, double__estStdDevRateY = 0.0, double__estStdDevRateZ = 0.0, double__estStdDevQ0 = 0.0, double__estStdDevQ1 = 0.0, double__estStdDevQ2 = 0.0, uint8__estModeActive = 0):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.double__estRpyRoll = double__estRpyRoll
            self.double__estRpyPitch = double__estRpyPitch
            self.double__estRpyYaw = double__estRpyYaw
            self.double__estQuatQ0 = double__estQuatQ0
            self.double__estQuatQ1 = double__estQuatQ1
            self.double__estQuatQ2 = double__estQuatQ2
            self.double__estQuatQ3 = double__estQuatQ3
            self.double__estGyroBiasX = double__estGyroBiasX
            self.double__estGyroBiasY = double__estGyroBiasY
            self.double__estGyroBiasZ = double__estGyroBiasZ
            self.double__estRateOrcX = double__estRateOrcX
            self.double__estRateOrcY = double__estRateOrcY
            self.double__estRateOrcZ = double__estRateOrcZ
            self.double__estRateIrcX = double__estRateIrcX
            self.double__estRateIrcY = double__estRateIrcY
            self.double__estRateIrcZ = double__estRateIrcZ
            self.float__estGyrTorqueX = float__estGyrTorqueX
            self.float__estGyrTorqueY = float__estGyrTorqueY
            self.float__estGyrTorqueZ = float__estGyrTorqueZ
            self.double__estInnovX = double__estInnovX
            self.double__estInnovY = double__estInnovY
            self.double__estInnovZ = double__estInnovZ
            self.double__estStdDevRateX = double__estStdDevRateX
            self.double__estStdDevRateY = double__estStdDevRateY
            self.double__estStdDevRateZ = double__estStdDevRateZ
            self.double__estStdDevQ0 = double__estStdDevQ0
            self.double__estStdDevQ1 = double__estStdDevQ1
            self.double__estStdDevQ2 = double__estStdDevQ2
            self.uint8__estModeActive = uint8__estModeActive
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estRpyRoll)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estRpyPitch)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estRpyYaw)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estQuatQ0)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estQuatQ1)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estQuatQ2)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estQuatQ3)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estGyroBiasX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estGyroBiasY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estGyroBiasZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estRateOrcX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estRateOrcY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estRateOrcZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estRateIrcX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estRateIrcY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estRateIrcZ)
            result += SerDesHelpers.serdesType_float.serialize(self.float__estGyrTorqueX)
            result += SerDesHelpers.serdesType_float.serialize(self.float__estGyrTorqueY)
            result += SerDesHelpers.serdesType_float.serialize(self.float__estGyrTorqueZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estInnovX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estInnovY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estInnovZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estStdDevRateX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estStdDevRateY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estStdDevRateZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estStdDevQ0)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estStdDevQ1)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estStdDevQ2)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__estModeActive)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_173()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estRpyRoll, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estRpyPitch, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estRpyYaw, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estQuatQ0, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estQuatQ1, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estQuatQ2, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estQuatQ3, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estGyroBiasX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estGyroBiasY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estGyroBiasZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estRateOrcX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estRateOrcY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estRateOrcZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estRateIrcX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estRateIrcY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estRateIrcZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__estGyrTorqueX, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__estGyrTorqueY, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__estGyrTorqueZ, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estInnovX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estInnovY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estInnovZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estStdDevRateX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estStdDevRateY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estStdDevRateZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estStdDevQ0, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estStdDevQ1, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estStdDevQ2, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__estModeActive, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 221
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_174:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, int32__satPosEciX = 0, int32__satPosEciY = 0, int32__satPosEciZ = 0, int16__satVelEciX = 0, int16__satVelEciY = 0, int16__satVelEciZ = 0, double__satLatGeod = 0.0, double__satLatGeoc = 0.0, double__satLon = 0.0, double__satAlt = 0.0, int32__tgtPosEciX = 0, int32__tgtPosEciY = 0, int32__tgtPosEciZ = 0, double__modelMagOrcX = 0.0, double__modelMagOrcY = 0.0, double__modelMagOrcZ = 0.0, double__modelSunOrcX = 0.0, double__modelSunOrcY = 0.0, double__modelSunOrcZ = 0.0, double__modelSunBetaAngle = 0.0, double__modelHorRhoAngle = 0.0, double__modelHorXoEastAngle = 0.0, double__modelHorYiEastAngle = 0.0, int32__sat2TgtGndOrcX = 0, int32__sat2TgtGndOrcY = 0, int32__sat2TgtGndOrcZ = 0, uint16__asgp4BatchCtr = 0, uint16__asgp4PosDelta = 0, uint8__orbModeActive = 0, bool__asgp4Error = False, bool__eclipse = False, uint8__navSource = 0):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.int32__satPosEciX = int32__satPosEciX
            self.int32__satPosEciY = int32__satPosEciY
            self.int32__satPosEciZ = int32__satPosEciZ
            self.int16__satVelEciX = int16__satVelEciX
            self.int16__satVelEciY = int16__satVelEciY
            self.int16__satVelEciZ = int16__satVelEciZ
            self.double__satLatGeod = double__satLatGeod
            self.double__satLatGeoc = double__satLatGeoc
            self.double__satLon = double__satLon
            self.double__satAlt = double__satAlt
            self.int32__tgtPosEciX = int32__tgtPosEciX
            self.int32__tgtPosEciY = int32__tgtPosEciY
            self.int32__tgtPosEciZ = int32__tgtPosEciZ
            self.double__modelMagOrcX = double__modelMagOrcX
            self.double__modelMagOrcY = double__modelMagOrcY
            self.double__modelMagOrcZ = double__modelMagOrcZ
            self.double__modelSunOrcX = double__modelSunOrcX
            self.double__modelSunOrcY = double__modelSunOrcY
            self.double__modelSunOrcZ = double__modelSunOrcZ
            self.double__modelSunBetaAngle = double__modelSunBetaAngle
            self.double__modelHorRhoAngle = double__modelHorRhoAngle
            self.double__modelHorXoEastAngle = double__modelHorXoEastAngle
            self.double__modelHorYiEastAngle = double__modelHorYiEastAngle
            self.int32__sat2TgtGndOrcX = int32__sat2TgtGndOrcX
            self.int32__sat2TgtGndOrcY = int32__sat2TgtGndOrcY
            self.int32__sat2TgtGndOrcZ = int32__sat2TgtGndOrcZ
            self.uint16__asgp4BatchCtr = uint16__asgp4BatchCtr
            self.uint16__asgp4PosDelta = uint16__asgp4PosDelta
            self.uint8__orbModeActive = uint8__orbModeActive
            self.bool__asgp4Error = bool__asgp4Error
            self.bool__eclipse = bool__eclipse
            self.uint8__navSource = uint8__navSource
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__satPosEciX)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__satPosEciY)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__satPosEciZ)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__satVelEciX)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__satVelEciY)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__satVelEciZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__satLatGeod)
            result += SerDesHelpers.serdesType_double.serialize(self.double__satLatGeoc)
            result += SerDesHelpers.serdesType_double.serialize(self.double__satLon)
            result += SerDesHelpers.serdesType_double.serialize(self.double__satAlt)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__tgtPosEciX)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__tgtPosEciY)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__tgtPosEciZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__modelMagOrcX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__modelMagOrcY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__modelMagOrcZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__modelSunOrcX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__modelSunOrcY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__modelSunOrcZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__modelSunBetaAngle)
            result += SerDesHelpers.serdesType_double.serialize(self.double__modelHorRhoAngle)
            result += SerDesHelpers.serdesType_double.serialize(self.double__modelHorXoEastAngle)
            result += SerDesHelpers.serdesType_double.serialize(self.double__modelHorYiEastAngle)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__sat2TgtGndOrcX)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__sat2TgtGndOrcY)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__sat2TgtGndOrcZ)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__asgp4BatchCtr)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__asgp4PosDelta)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__orbModeActive)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__asgp4Error)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__eclipse)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__navSource)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_174()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__satPosEciX, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__satPosEciY, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__satPosEciZ, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__satVelEciX, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__satVelEciY, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__satVelEciZ, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__satLatGeod, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__satLatGeoc, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__satLon, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__satAlt, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__tgtPosEciX, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__tgtPosEciY, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__tgtPosEciZ, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__modelMagOrcX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__modelMagOrcY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__modelMagOrcZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__modelSunOrcX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__modelSunOrcY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__modelSunOrcZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__modelSunBetaAngle, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__modelHorRhoAngle, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__modelHorXoEastAngle, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__modelHorYiEastAngle, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__sat2TgtGndOrcX, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__sat2TgtGndOrcY, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__sat2TgtGndOrcZ, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__asgp4BatchCtr, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__asgp4PosDelta, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__orbModeActive, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__asgp4Error, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__eclipse, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__navSource, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 170
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_175:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, float__gnssSatPosEcefX = 0.0, float__gnssSatPosEcefY = 0.0, float__gnssSatPosEcefZ = 0.0, float__gnssSatVelEcefX = 0.0, float__gnssSatVelEcefY = 0.0, float__gnssSatVelEcefZ = 0.0, uint32__gnssTimeSeconds = 0, uint32__gnssTimeNs = 0, bool__gnssIsValid = False):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.float__gnssSatPosEcefX = float__gnssSatPosEcefX
            self.float__gnssSatPosEcefY = float__gnssSatPosEcefY
            self.float__gnssSatPosEcefZ = float__gnssSatPosEcefZ
            self.float__gnssSatVelEcefX = float__gnssSatVelEcefX
            self.float__gnssSatVelEcefY = float__gnssSatVelEcefY
            self.float__gnssSatVelEcefZ = float__gnssSatVelEcefZ
            self.uint32__gnssTimeSeconds = uint32__gnssTimeSeconds
            self.uint32__gnssTimeNs = uint32__gnssTimeNs
            self.bool__gnssIsValid = bool__gnssIsValid
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gnssSatPosEcefX)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gnssSatPosEcefY)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gnssSatPosEcefZ)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gnssSatVelEcefX)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gnssSatVelEcefY)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gnssSatVelEcefZ)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__gnssTimeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__gnssTimeNs)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__gnssIsValid)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_175()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gnssSatPosEcefX, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gnssSatPosEcefY, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gnssSatPosEcefZ, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gnssSatVelEcefX, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gnssSatVelEcefY, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gnssSatVelEcefZ, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__gnssTimeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__gnssTimeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__gnssIsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 41
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_176:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, double__hss0CalVecX = 0.0, double__hss0CalVecY = 0.0, double__hss0CalVecZ = 0.0, double__hss1CalVecX = 0.0, double__hss1CalVecY = 0.0, double__hss1CalVecZ = 0.0, bool__hss0IsValid = False, bool__hss1IsValid = False):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.double__hss0CalVecX = double__hss0CalVecX
            self.double__hss0CalVecY = double__hss0CalVecY
            self.double__hss0CalVecZ = double__hss0CalVecZ
            self.double__hss1CalVecX = double__hss1CalVecX
            self.double__hss1CalVecY = double__hss1CalVecY
            self.double__hss1CalVecZ = double__hss1CalVecZ
            self.bool__hss0IsValid = bool__hss0IsValid
            self.bool__hss1IsValid = bool__hss1IsValid
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_double.serialize(self.double__hss0CalVecX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__hss0CalVecY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__hss0CalVecZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__hss1CalVecX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__hss1CalVecY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__hss1CalVecZ)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__hss0IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__hss1IsValid)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_176()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__hss0CalVecX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__hss0CalVecY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__hss0CalVecZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__hss1CalVecX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__hss1CalVecY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__hss1CalVecZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__hss0IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__hss1IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 58
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_177:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, double__mag0CalVecX = 0.0, double__mag0CalVecY = 0.0, double__mag0CalVecZ = 0.0, double__mag1CalVecX = 0.0, double__mag1CalVecY = 0.0, double__mag1CalVecZ = 0.0, bool__mag0IsValid = False, bool__mag1IsValid = False, bool__mag0IsBest = False, bool__mag1IsBest = False):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.double__mag0CalVecX = double__mag0CalVecX
            self.double__mag0CalVecY = double__mag0CalVecY
            self.double__mag0CalVecZ = double__mag0CalVecZ
            self.double__mag1CalVecX = double__mag1CalVecX
            self.double__mag1CalVecY = double__mag1CalVecY
            self.double__mag1CalVecZ = double__mag1CalVecZ
            self.bool__mag0IsValid = bool__mag0IsValid
            self.bool__mag1IsValid = bool__mag1IsValid
            self.bool__mag0IsBest = bool__mag0IsBest
            self.bool__mag1IsBest = bool__mag1IsBest
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag0CalVecX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag0CalVecY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag0CalVecZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag1CalVecX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag1CalVecY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag1CalVecZ)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__mag0IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__mag1IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__mag0IsBest)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__mag1IsBest)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_177()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag0CalVecX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag0CalVecY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag0CalVecZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag1CalVecX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag1CalVecY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag1CalVecZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__mag0IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__mag1IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__mag0IsBest, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__mag1IsBest, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 60
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_178:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, double__fss0CalVecX = 0.0, double__fss0CalVecY = 0.0, double__fss0CalVecZ = 0.0, double__fss1CalVecX = 0.0, double__fss1CalVecY = 0.0, double__fss1CalVecZ = 0.0, double__fss2CalVecX = 0.0, double__fss2CalVecY = 0.0, double__fss2CalVecZ = 0.0, double__fss3CalVecX = 0.0, double__fss3CalVecY = 0.0, double__fss3CalVecZ = 0.0, bool__fss0IsValid = False, bool__fss1IsValid = False, bool__fss2IsValid = False, bool__fss3IsValid = False, bool__fss0IsBest = False, bool__fss1IsBest = False, bool__fss2IsBest = False, bool__fss3IsBest = False):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.double__fss0CalVecX = double__fss0CalVecX
            self.double__fss0CalVecY = double__fss0CalVecY
            self.double__fss0CalVecZ = double__fss0CalVecZ
            self.double__fss1CalVecX = double__fss1CalVecX
            self.double__fss1CalVecY = double__fss1CalVecY
            self.double__fss1CalVecZ = double__fss1CalVecZ
            self.double__fss2CalVecX = double__fss2CalVecX
            self.double__fss2CalVecY = double__fss2CalVecY
            self.double__fss2CalVecZ = double__fss2CalVecZ
            self.double__fss3CalVecX = double__fss3CalVecX
            self.double__fss3CalVecY = double__fss3CalVecY
            self.double__fss3CalVecZ = double__fss3CalVecZ
            self.bool__fss0IsValid = bool__fss0IsValid
            self.bool__fss1IsValid = bool__fss1IsValid
            self.bool__fss2IsValid = bool__fss2IsValid
            self.bool__fss3IsValid = bool__fss3IsValid
            self.bool__fss0IsBest = bool__fss0IsBest
            self.bool__fss1IsBest = bool__fss1IsBest
            self.bool__fss2IsBest = bool__fss2IsBest
            self.bool__fss3IsBest = bool__fss3IsBest
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss0CalVecX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss0CalVecY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss0CalVecZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss1CalVecX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss1CalVecY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss1CalVecZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss2CalVecX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss2CalVecY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss2CalVecZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss3CalVecX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss3CalVecY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fss3CalVecZ)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss0IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss1IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss2IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss3IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss0IsBest)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss1IsBest)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss2IsBest)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__fss3IsBest)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_178()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss0CalVecX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss0CalVecY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss0CalVecZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss1CalVecX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss1CalVecY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss1CalVecZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss2CalVecX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss2CalVecY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss2CalVecZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss3CalVecX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss3CalVecY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fss3CalVecZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss0IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss1IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss2IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss3IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss0IsBest, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss1IsBest, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss2IsBest, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__fss3IsBest, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 112
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_179:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, double__hss0RawElev = 0.0, double__hss0RawRot = 0.0, uint8__hss0CaptureResult = 0, uint8__hss0DetectionResult = 0, double__hss1RawElev = 0.0, double__hss1RawRot = 0.0, uint8__hss1CaptureResult = 0, uint8__hss1DetectionResult = 0, bool__hss0IsValid = False, bool__hss1IsValid = False):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.double__hss0RawElev = double__hss0RawElev
            self.double__hss0RawRot = double__hss0RawRot
            self.uint8__hss0CaptureResult = uint8__hss0CaptureResult
            self.uint8__hss0DetectionResult = uint8__hss0DetectionResult
            self.double__hss1RawElev = double__hss1RawElev
            self.double__hss1RawRot = double__hss1RawRot
            self.uint8__hss1CaptureResult = uint8__hss1CaptureResult
            self.uint8__hss1DetectionResult = uint8__hss1DetectionResult
            self.bool__hss0IsValid = bool__hss0IsValid
            self.bool__hss1IsValid = bool__hss1IsValid
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_double.serialize(self.double__hss0RawElev)
            result += SerDesHelpers.serdesType_double.serialize(self.double__hss0RawRot)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__hss0CaptureResult)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__hss0DetectionResult)
            result += SerDesHelpers.serdesType_double.serialize(self.double__hss1RawElev)
            result += SerDesHelpers.serdesType_double.serialize(self.double__hss1RawRot)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__hss1CaptureResult)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__hss1DetectionResult)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__hss0IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__hss1IsValid)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_179()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__hss0RawElev, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__hss0RawRot, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__hss0CaptureResult, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__hss0DetectionResult, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__hss1RawElev, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__hss1RawRot, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__hss1CaptureResult, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__hss1DetectionResult, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__hss0IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__hss1IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 46
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_180:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, double__mag0RawVecX = 0.0, double__mag0RawVecY = 0.0, double__mag0RawVecZ = 0.0, double__mag1RawVecX = 0.0, double__mag1RawVecY = 0.0, double__mag1RawVecZ = 0.0, bool__mag0IsValid = False, bool__mag1IsValid = False):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.double__mag0RawVecX = double__mag0RawVecX
            self.double__mag0RawVecY = double__mag0RawVecY
            self.double__mag0RawVecZ = double__mag0RawVecZ
            self.double__mag1RawVecX = double__mag1RawVecX
            self.double__mag1RawVecY = double__mag1RawVecY
            self.double__mag1RawVecZ = double__mag1RawVecZ
            self.bool__mag0IsValid = bool__mag0IsValid
            self.bool__mag1IsValid = bool__mag1IsValid
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag0RawVecX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag0RawVecY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag0RawVecZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag1RawVecX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag1RawVecY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag1RawVecZ)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__mag0IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__mag1IsValid)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_180()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag0RawVecX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag0RawVecY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag0RawVecZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag1RawVecX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag1RawVecY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag1RawVecZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__mag0IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__mag1IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 58
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_203:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, uint8__css0Raw = 0, uint8__css1Raw = 0, uint8__css2Raw = 0, uint8__css3Raw = 0, uint8__css4Raw = 0, uint8__css5Raw = 0, uint8__css6Raw = 0, uint8__css7Raw = 0, uint8__csInt8Raw = 0, uint8__css9Raw = 0, bool__cssIsValid = False):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.uint8__css0Raw = uint8__css0Raw
            self.uint8__css1Raw = uint8__css1Raw
            self.uint8__css2Raw = uint8__css2Raw
            self.uint8__css3Raw = uint8__css3Raw
            self.uint8__css4Raw = uint8__css4Raw
            self.uint8__css5Raw = uint8__css5Raw
            self.uint8__css6Raw = uint8__css6Raw
            self.uint8__css7Raw = uint8__css7Raw
            self.uint8__csInt8Raw = uint8__csInt8Raw
            self.uint8__css9Raw = uint8__css9Raw
            self.bool__cssIsValid = bool__cssIsValid
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__css0Raw)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__css1Raw)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__css2Raw)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__css3Raw)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__css4Raw)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__css5Raw)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__css6Raw)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__css7Raw)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__csInt8Raw)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__css9Raw)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__cssIsValid)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_203()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__css0Raw, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__css1Raw, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__css2Raw, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__css3Raw, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__css4Raw, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__css5Raw, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__css6Raw, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__css7Raw, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__csInt8Raw, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__css9Raw, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__cssIsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 19
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_204:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, float__gyro0RawRateX = 0.0, float__gyro0RawRateY = 0.0, float__gyro0RawRateZ = 0.0, float__gyro1RawRateX = 0.0, float__gyro1RawRateY = 0.0, float__gyro1RawRateZ = 0.0, bool__gyro0IsValid = False, bool__gyro1IsValid = False):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.float__gyro0RawRateX = float__gyro0RawRateX
            self.float__gyro0RawRateY = float__gyro0RawRateY
            self.float__gyro0RawRateZ = float__gyro0RawRateZ
            self.float__gyro1RawRateX = float__gyro1RawRateX
            self.float__gyro1RawRateY = float__gyro1RawRateY
            self.float__gyro1RawRateZ = float__gyro1RawRateZ
            self.bool__gyro0IsValid = bool__gyro0IsValid
            self.bool__gyro1IsValid = bool__gyro1IsValid
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gyro0RawRateX)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gyro0RawRateY)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gyro0RawRateZ)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gyro1RawRateX)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gyro1RawRateY)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gyro1RawRateZ)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__gyro0IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__gyro1IsValid)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_204()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gyro0RawRateX, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gyro0RawRateY, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gyro0RawRateZ, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gyro1RawRateX, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gyro1RawRateY, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gyro1RawRateZ, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__gyro0IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__gyro1IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 34
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_205:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, float__rwl0MeasSpeed = 0.0, float__rwl1MeasSpeed = 0.0, float__rwl2MeasSpeed = 0.0, float__rwl3MeasSpeed = 0.0, bool__rwl0IsValid = False, bool__rwl1IsValid = False, bool__rwl2IsValid = False, bool__rwl3IsValid = False):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.float__rwl0MeasSpeed = float__rwl0MeasSpeed
            self.float__rwl1MeasSpeed = float__rwl1MeasSpeed
            self.float__rwl2MeasSpeed = float__rwl2MeasSpeed
            self.float__rwl3MeasSpeed = float__rwl3MeasSpeed
            self.bool__rwl0IsValid = bool__rwl0IsValid
            self.bool__rwl1IsValid = bool__rwl1IsValid
            self.bool__rwl2IsValid = bool__rwl2IsValid
            self.bool__rwl3IsValid = bool__rwl3IsValid
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl0MeasSpeed)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl1MeasSpeed)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl2MeasSpeed)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl3MeasSpeed)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl0IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl1IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl2IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl3IsValid)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_205()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl0MeasSpeed, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl1MeasSpeed, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl2MeasSpeed, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl3MeasSpeed, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl0IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl1IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl2IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl3IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 28
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_206:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, double__cssCalVecX = 0.0, double__cssCalVecY = 0.0, double__cssCalVecZ = 0.0, bool__cssIsValid = False):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.double__cssCalVecX = double__cssCalVecX
            self.double__cssCalVecY = double__cssCalVecY
            self.double__cssCalVecZ = double__cssCalVecZ
            self.bool__cssIsValid = bool__cssIsValid
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_double.serialize(self.double__cssCalVecX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__cssCalVecY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__cssCalVecZ)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__cssIsValid)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_206()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__cssCalVecX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__cssCalVecY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__cssCalVecZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__cssIsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 33
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_207:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, float__gyro0CalRateX = 0.0, float__gyro0CalRateY = 0.0, float__gyro0CalRateZ = 0.0, float__gyro1CalRateX = 0.0, float__gyro1CalRateY = 0.0, float__gyro1CalRateZ = 0.0, float__extGyro0CalRateX = 0.0, float__extGyro0CalRateY = 0.0, float__extGyro0CalRateZ = 0.0, float__extGyro1CalRateX = 0.0, float__extGyro1CalRateY = 0.0, float__extGyro1CalRateZ = 0.0, bool__gyro0IsValid = False, bool__gyro1IsValid = False, bool__extGyro0IsValid = False, bool__extGyro1IsValid = False):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.float__gyro0CalRateX = float__gyro0CalRateX
            self.float__gyro0CalRateY = float__gyro0CalRateY
            self.float__gyro0CalRateZ = float__gyro0CalRateZ
            self.float__gyro1CalRateX = float__gyro1CalRateX
            self.float__gyro1CalRateY = float__gyro1CalRateY
            self.float__gyro1CalRateZ = float__gyro1CalRateZ
            self.float__extGyro0CalRateX = float__extGyro0CalRateX
            self.float__extGyro0CalRateY = float__extGyro0CalRateY
            self.float__extGyro0CalRateZ = float__extGyro0CalRateZ
            self.float__extGyro1CalRateX = float__extGyro1CalRateX
            self.float__extGyro1CalRateY = float__extGyro1CalRateY
            self.float__extGyro1CalRateZ = float__extGyro1CalRateZ
            self.bool__gyro0IsValid = bool__gyro0IsValid
            self.bool__gyro1IsValid = bool__gyro1IsValid
            self.bool__extGyro0IsValid = bool__extGyro0IsValid
            self.bool__extGyro1IsValid = bool__extGyro1IsValid
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gyro0CalRateX)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gyro0CalRateY)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gyro0CalRateZ)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gyro1CalRateX)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gyro1CalRateY)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gyro1CalRateZ)
            result += SerDesHelpers.serdesType_float.serialize(self.float__extGyro0CalRateX)
            result += SerDesHelpers.serdesType_float.serialize(self.float__extGyro0CalRateY)
            result += SerDesHelpers.serdesType_float.serialize(self.float__extGyro0CalRateZ)
            result += SerDesHelpers.serdesType_float.serialize(self.float__extGyro1CalRateX)
            result += SerDesHelpers.serdesType_float.serialize(self.float__extGyro1CalRateY)
            result += SerDesHelpers.serdesType_float.serialize(self.float__extGyro1CalRateZ)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__gyro0IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__gyro1IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__extGyro0IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__extGyro1IsValid)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_207()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gyro0CalRateX, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gyro0CalRateY, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gyro0CalRateZ, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gyro1CalRateX, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gyro1CalRateY, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gyro1CalRateZ, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__extGyro0CalRateX, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__extGyro0CalRateY, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__extGyro0CalRateZ, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__extGyro1CalRateX, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__extGyro1CalRateY, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__extGyro1CalRateZ, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__gyro0IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__gyro1IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__extGyro0IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__extGyro1IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 60
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_208_1:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, double__str0MeasBodyVec0X = 0.0, double__str0MeasBodyVec0Y = 0.0, double__str0MeasBodyVec0Z = 0.0, double__str0MeasBodyVec1X = 0.0, double__str0MeasBodyVec1Y = 0.0, double__str0MeasBodyVec1Z = 0.0, double__str0MeasBodyVec2X = 0.0, double__str0MeasBodyVec2Y = 0.0, double__str0MeasBodyVec2Z = 0.0, double__str0ModelOrbitVec0X = 0.0, double__str0ModelOrbitVec0Y = 0.0, double__str0ModelOrbitVec0Z = 0.0, double__str0ModelOrbitVec1X = 0.0, double__str0ModelOrbitVec1Y = 0.0, double__str0ModelOrbitVec1Z = 0.0, double__str0ModelOrbitVec2X = 0.0, double__str0ModelOrbitVec2Y = 0.0, double__str0ModelOrbitVec2Z = 0.0):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.double__str0MeasBodyVec0X = double__str0MeasBodyVec0X
            self.double__str0MeasBodyVec0Y = double__str0MeasBodyVec0Y
            self.double__str0MeasBodyVec0Z = double__str0MeasBodyVec0Z
            self.double__str0MeasBodyVec1X = double__str0MeasBodyVec1X
            self.double__str0MeasBodyVec1Y = double__str0MeasBodyVec1Y
            self.double__str0MeasBodyVec1Z = double__str0MeasBodyVec1Z
            self.double__str0MeasBodyVec2X = double__str0MeasBodyVec2X
            self.double__str0MeasBodyVec2Y = double__str0MeasBodyVec2Y
            self.double__str0MeasBodyVec2Z = double__str0MeasBodyVec2Z
            self.double__str0ModelOrbitVec0X = double__str0ModelOrbitVec0X
            self.double__str0ModelOrbitVec0Y = double__str0ModelOrbitVec0Y
            self.double__str0ModelOrbitVec0Z = double__str0ModelOrbitVec0Z
            self.double__str0ModelOrbitVec1X = double__str0ModelOrbitVec1X
            self.double__str0ModelOrbitVec1Y = double__str0ModelOrbitVec1Y
            self.double__str0ModelOrbitVec1Z = double__str0ModelOrbitVec1Z
            self.double__str0ModelOrbitVec2X = double__str0ModelOrbitVec2X
            self.double__str0ModelOrbitVec2Y = double__str0ModelOrbitVec2Y
            self.double__str0ModelOrbitVec2Z = double__str0ModelOrbitVec2Z
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0MeasBodyVec0X)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0MeasBodyVec0Y)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0MeasBodyVec0Z)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0MeasBodyVec1X)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0MeasBodyVec1Y)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0MeasBodyVec1Z)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0MeasBodyVec2X)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0MeasBodyVec2Y)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0MeasBodyVec2Z)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0ModelOrbitVec0X)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0ModelOrbitVec0Y)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0ModelOrbitVec0Z)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0ModelOrbitVec1X)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0ModelOrbitVec1Y)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0ModelOrbitVec1Z)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0ModelOrbitVec2X)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0ModelOrbitVec2Y)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0ModelOrbitVec2Z)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_208_1()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0MeasBodyVec0X, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0MeasBodyVec0Y, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0MeasBodyVec0Z, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0MeasBodyVec1X, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0MeasBodyVec1Y, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0MeasBodyVec1Z, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0MeasBodyVec2X, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0MeasBodyVec2Y, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0MeasBodyVec2Z, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0ModelOrbitVec0X, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0ModelOrbitVec0Y, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0ModelOrbitVec0Z, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0ModelOrbitVec1X, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0ModelOrbitVec1Y, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0ModelOrbitVec1Z, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0ModelOrbitVec2X, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0ModelOrbitVec2Y, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0ModelOrbitVec2Z, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 152
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_208_2:
        def __init__(self, double__str1MeasBodyVec0X = 0.0, double__str1MeasBodyVec0Y = 0.0, double__str1MeasBodyVec0Z = 0.0, double__str1MeasBodyVec1X = 0.0, double__str1MeasBodyVec1Y = 0.0, double__str1MeasBodyVec1Z = 0.0, double__str1MeasBodyVec2X = 0.0, double__str1MeasBodyVec2Y = 0.0, double__str1MeasBodyVec2Z = 0.0, double__str1ModelOrbitVec0X = 0.0, double__str1ModelOrbitVec0Y = 0.0, double__str1ModelOrbitVec0Z = 0.0, double__str1ModelOrbitVec1X = 0.0, double__str1ModelOrbitVec1Y = 0.0, double__str1ModelOrbitVec1Z = 0.0, double__str1ModelOrbitVec2X = 0.0, double__str1ModelOrbitVec2Y = 0.0, double__str1ModelOrbitVec2Z = 0.0, bool__str0IsValid = False, bool__str1IsValid = False):
            self.double__str1MeasBodyVec0X = double__str1MeasBodyVec0X
            self.double__str1MeasBodyVec0Y = double__str1MeasBodyVec0Y
            self.double__str1MeasBodyVec0Z = double__str1MeasBodyVec0Z
            self.double__str1MeasBodyVec1X = double__str1MeasBodyVec1X
            self.double__str1MeasBodyVec1Y = double__str1MeasBodyVec1Y
            self.double__str1MeasBodyVec1Z = double__str1MeasBodyVec1Z
            self.double__str1MeasBodyVec2X = double__str1MeasBodyVec2X
            self.double__str1MeasBodyVec2Y = double__str1MeasBodyVec2Y
            self.double__str1MeasBodyVec2Z = double__str1MeasBodyVec2Z
            self.double__str1ModelOrbitVec0X = double__str1ModelOrbitVec0X
            self.double__str1ModelOrbitVec0Y = double__str1ModelOrbitVec0Y
            self.double__str1ModelOrbitVec0Z = double__str1ModelOrbitVec0Z
            self.double__str1ModelOrbitVec1X = double__str1ModelOrbitVec1X
            self.double__str1ModelOrbitVec1Y = double__str1ModelOrbitVec1Y
            self.double__str1ModelOrbitVec1Z = double__str1ModelOrbitVec1Z
            self.double__str1ModelOrbitVec2X = double__str1ModelOrbitVec2X
            self.double__str1ModelOrbitVec2Y = double__str1ModelOrbitVec2Y
            self.double__str1ModelOrbitVec2Z = double__str1ModelOrbitVec2Z
            self.bool__str0IsValid = bool__str0IsValid
            self.bool__str1IsValid = bool__str1IsValid
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1MeasBodyVec0X)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1MeasBodyVec0Y)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1MeasBodyVec0Z)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1MeasBodyVec1X)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1MeasBodyVec1Y)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1MeasBodyVec1Z)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1MeasBodyVec2X)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1MeasBodyVec2Y)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1MeasBodyVec2Z)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1ModelOrbitVec0X)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1ModelOrbitVec0Y)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1ModelOrbitVec0Z)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1ModelOrbitVec1X)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1ModelOrbitVec1Y)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1ModelOrbitVec1Z)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1ModelOrbitVec2X)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1ModelOrbitVec2Y)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1ModelOrbitVec2Z)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__str0IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__str1IsValid)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_208_2()
    
            currentPos = pos
            (resultInstance.double__str1MeasBodyVec0X, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1MeasBodyVec0Y, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1MeasBodyVec0Z, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1MeasBodyVec1X, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1MeasBodyVec1Y, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1MeasBodyVec1Z, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1MeasBodyVec2X, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1MeasBodyVec2Y, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1MeasBodyVec2Z, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1ModelOrbitVec0X, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1ModelOrbitVec0Y, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1ModelOrbitVec0Z, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1ModelOrbitVec1X, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1ModelOrbitVec1Y, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1ModelOrbitVec1Z, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1ModelOrbitVec2X, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1ModelOrbitVec2Y, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1ModelOrbitVec2Z, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__str0IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__str1IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 146
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_209:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, float__rwlTorqueVecX = 0.0, float__rwlTorqueVecY = 0.0, float__rwlTorqueVecZ = 0.0, float__rwlMomVecX = 0.0, float__rwlMomVecY = 0.0, float__rwlMomVecZ = 0.0, bool__rwlIsValid = False):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.float__rwlTorqueVecX = float__rwlTorqueVecX
            self.float__rwlTorqueVecY = float__rwlTorqueVecY
            self.float__rwlTorqueVecZ = float__rwlTorqueVecZ
            self.float__rwlMomVecX = float__rwlMomVecX
            self.float__rwlMomVecY = float__rwlMomVecY
            self.float__rwlMomVecZ = float__rwlMomVecZ
            self.bool__rwlIsValid = bool__rwlIsValid
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwlTorqueVecX)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwlTorqueVecY)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwlTorqueVecZ)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwlMomVecX)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwlMomVecY)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwlMomVecZ)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwlIsValid)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_209()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwlTorqueVecX, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwlTorqueVecY, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwlTorqueVecZ, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwlMomVecX, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwlMomVecY, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwlMomVecZ, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwlIsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 33
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_210:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, double__estRpyRoll = 0.0, double__estRpyPitch = 0.0, double__estRpyYaw = 0.0, double__estQuatQ0 = 0.0, double__estQuatQ1 = 0.0, double__estQuatQ2 = 0.0, double__estQuatQ3 = 0.0, double__estGyroBiasX = 0.0, double__estGyroBiasY = 0.0, double__estGyroBiasZ = 0.0, double__estRateOrcX = 0.0, double__estRateOrcY = 0.0, double__estRateOrcZ = 0.0, double__estRateIrcX = 0.0, double__estRateIrcY = 0.0, double__estRateIrcZ = 0.0, float__estGyrTorqueX = 0.0, float__estGyrTorqueY = 0.0, float__estGyrTorqueZ = 0.0, double__estInnovX = 0.0, double__estInnovY = 0.0, double__estInnovZ = 0.0, double__estStdDevRateX = 0.0, double__estStdDevRateY = 0.0, double__estStdDevRateZ = 0.0, double__estStdDevQ0 = 0.0, double__estStdDevQ1 = 0.0, double__estStdDevQ2 = 0.0, uint8__estModeActive = 0):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.double__estRpyRoll = double__estRpyRoll
            self.double__estRpyPitch = double__estRpyPitch
            self.double__estRpyYaw = double__estRpyYaw
            self.double__estQuatQ0 = double__estQuatQ0
            self.double__estQuatQ1 = double__estQuatQ1
            self.double__estQuatQ2 = double__estQuatQ2
            self.double__estQuatQ3 = double__estQuatQ3
            self.double__estGyroBiasX = double__estGyroBiasX
            self.double__estGyroBiasY = double__estGyroBiasY
            self.double__estGyroBiasZ = double__estGyroBiasZ
            self.double__estRateOrcX = double__estRateOrcX
            self.double__estRateOrcY = double__estRateOrcY
            self.double__estRateOrcZ = double__estRateOrcZ
            self.double__estRateIrcX = double__estRateIrcX
            self.double__estRateIrcY = double__estRateIrcY
            self.double__estRateIrcZ = double__estRateIrcZ
            self.float__estGyrTorqueX = float__estGyrTorqueX
            self.float__estGyrTorqueY = float__estGyrTorqueY
            self.float__estGyrTorqueZ = float__estGyrTorqueZ
            self.double__estInnovX = double__estInnovX
            self.double__estInnovY = double__estInnovY
            self.double__estInnovZ = double__estInnovZ
            self.double__estStdDevRateX = double__estStdDevRateX
            self.double__estStdDevRateY = double__estStdDevRateY
            self.double__estStdDevRateZ = double__estStdDevRateZ
            self.double__estStdDevQ0 = double__estStdDevQ0
            self.double__estStdDevQ1 = double__estStdDevQ1
            self.double__estStdDevQ2 = double__estStdDevQ2
            self.uint8__estModeActive = uint8__estModeActive
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estRpyRoll)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estRpyPitch)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estRpyYaw)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estQuatQ0)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estQuatQ1)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estQuatQ2)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estQuatQ3)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estGyroBiasX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estGyroBiasY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estGyroBiasZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estRateOrcX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estRateOrcY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estRateOrcZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estRateIrcX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estRateIrcY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estRateIrcZ)
            result += SerDesHelpers.serdesType_float.serialize(self.float__estGyrTorqueX)
            result += SerDesHelpers.serdesType_float.serialize(self.float__estGyrTorqueY)
            result += SerDesHelpers.serdesType_float.serialize(self.float__estGyrTorqueZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estInnovX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estInnovY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estInnovZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estStdDevRateX)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estStdDevRateY)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estStdDevRateZ)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estStdDevQ0)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estStdDevQ1)
            result += SerDesHelpers.serdesType_double.serialize(self.double__estStdDevQ2)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__estModeActive)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_210()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estRpyRoll, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estRpyPitch, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estRpyYaw, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estQuatQ0, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estQuatQ1, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estQuatQ2, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estQuatQ3, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estGyroBiasX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estGyroBiasY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estGyroBiasZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estRateOrcX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estRateOrcY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estRateOrcZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estRateIrcX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estRateIrcY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estRateIrcZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__estGyrTorqueX, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__estGyrTorqueY, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__estGyrTorqueZ, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estInnovX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estInnovY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estInnovZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estStdDevRateX, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estStdDevRateY, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estStdDevRateZ, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estStdDevQ0, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estStdDevQ1, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__estStdDevQ2, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__estModeActive, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 221
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_211:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, float__estQuatQ0 = 0.0, float__estQuatQ1 = 0.0, float__estQuatQ2 = 0.0, float__estQuatQ3 = 0.0, float__estRateOrcX = 0.0, float__estRateOrcY = 0.0, float__estRateOrcZ = 0.0):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.float__estQuatQ0 = float__estQuatQ0
            self.float__estQuatQ1 = float__estQuatQ1
            self.float__estQuatQ2 = float__estQuatQ2
            self.float__estQuatQ3 = float__estQuatQ3
            self.float__estRateOrcX = float__estRateOrcX
            self.float__estRateOrcY = float__estRateOrcY
            self.float__estRateOrcZ = float__estRateOrcZ
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_float.serialize(self.float__estQuatQ0)
            result += SerDesHelpers.serdesType_float.serialize(self.float__estQuatQ1)
            result += SerDesHelpers.serdesType_float.serialize(self.float__estQuatQ2)
            result += SerDesHelpers.serdesType_float.serialize(self.float__estQuatQ3)
            result += SerDesHelpers.serdesType_float.serialize(self.float__estRateOrcX)
            result += SerDesHelpers.serdesType_float.serialize(self.float__estRateOrcY)
            result += SerDesHelpers.serdesType_float.serialize(self.float__estRateOrcZ)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_211()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__estQuatQ0, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__estQuatQ1, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__estQuatQ2, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__estQuatQ3, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__estRateOrcX, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__estRateOrcY, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__estRateOrcZ, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 36
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_212:
        def __init__(self, uint32__rtcTimeSeconds = 0, uint32__rtcTimeNs = 0, int32__rtcDriftNs = 0, float__gnssSatPosEcefX = 0.0, float__gnssSatPosEcefY = 0.0, float__gnssSatPosEcefZ = 0.0, float__gnssSatVelEcefX = 0.0, float__gnssSatVelEcefY = 0.0, float__gnssSatVelEcefZ = 0.0, uint32__gnssTimeSeconds = 0, uint32__gnssTimeNs = 0, uint16__gpsWeek = 0, uint32__tow = 0, int8__utcOffset = 0, bool__gnssValidData = False, bool__gnssLock = False, bool__gnssPPSDetected = False):
            self.uint32__rtcTimeSeconds = uint32__rtcTimeSeconds
            self.uint32__rtcTimeNs = uint32__rtcTimeNs
            self.int32__rtcDriftNs = int32__rtcDriftNs
            self.float__gnssSatPosEcefX = float__gnssSatPosEcefX
            self.float__gnssSatPosEcefY = float__gnssSatPosEcefY
            self.float__gnssSatPosEcefZ = float__gnssSatPosEcefZ
            self.float__gnssSatVelEcefX = float__gnssSatVelEcefX
            self.float__gnssSatVelEcefY = float__gnssSatVelEcefY
            self.float__gnssSatVelEcefZ = float__gnssSatVelEcefZ
            self.uint32__gnssTimeSeconds = uint32__gnssTimeSeconds
            self.uint32__gnssTimeNs = uint32__gnssTimeNs
            self.uint16__gpsWeek = uint16__gpsWeek
            self.uint32__tow = uint32__tow
            self.int8__utcOffset = int8__utcOffset
            self.bool__gnssValidData = bool__gnssValidData
            self.bool__gnssLock = bool__gnssLock
            self.bool__gnssPPSDetected = bool__gnssPPSDetected
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__rtcTimeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__rtcTimeNs)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__rtcDriftNs)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gnssSatPosEcefX)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gnssSatPosEcefY)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gnssSatPosEcefZ)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gnssSatVelEcefX)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gnssSatVelEcefY)
            result += SerDesHelpers.serdesType_float.serialize(self.float__gnssSatVelEcefZ)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__gnssTimeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__gnssTimeNs)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__gpsWeek)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__tow)
            result += SerDesHelpers.serdesType_basic.serialize("int8", self.int8__utcOffset)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__gnssValidData)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__gnssLock)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__gnssPPSDetected)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_212()
    
            currentPos = pos
            (resultInstance.uint32__rtcTimeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__rtcTimeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__rtcDriftNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gnssSatPosEcefX, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gnssSatPosEcefY, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gnssSatPosEcefZ, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gnssSatVelEcefX, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gnssSatVelEcefY, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__gnssSatVelEcefZ, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__gnssTimeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__gnssTimeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__gpsWeek, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__tow, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int8__utcOffset, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__gnssValidData, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__gnssLock, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__gnssPPSDetected, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 54
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_213:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, uint8__str0Pst3sVersion = 0, float__str0Quat1 = 0.0, float__str0Quat2 = 0.0, float__str0Quat3 = 0.0, float__str0Quat4 = 0.0, float__str0AngVelX = 0.0, float__str0AngVelY = 0.0, float__str0AngVelZ = 0.0, uint8__str0RateQuality = 0, uint32__str0UnixSeconds = 0, float__str0UnixSecondsDecimal = 0.0, int8__str0Temperature = 0, uint8__str0ImageExposure = 0, uint8__str0ImageThreshold = 0, uint8__str0BackGroundValues = 0, uint8__str0InternalProcessCode = 0, uint8__str0CmosChipIdResult = 0, uint8__str0FpgaMRamResult = 0, uint8__str0NumberOfExtractedStars = 0, uint8__str0OperatingMode = 0, uint8__str0ImagingGain = 0, uint8__str0MinNavigationStars = 0, uint8__str0DataValid = 0, uint8__str0ExtImageState = 0, uint8__str0IdentifiedStars = 0, uint8__str0DeviceNumber = 0, uint8__str0SoftwareVersion = 0, uint8__str0EdacErrorCount = 0, uint32__str0ImageFrameNumber = 0, uint8__str0DynamicMode = 0, uint8__str0SaaMode = 0, uint8__str0SaaThreshold = 0, uint8__str0QuaternionFilteringState = 0, uint8__str0FourStarCaptureThreshold = 0, uint8__str0TrackingThreshold = 0, bool__str0EdacSwitch = False, uint8__str1Pst3sVersion = 0, float__str1Quat1 = 0.0, float__str1Quat2 = 0.0, float__str1Quat3 = 0.0, float__str1Quat4 = 0.0, float__str1AngVelX = 0.0, float__str1AngVelY = 0.0, float__str1AngVelZ = 0.0, uint8__str1RateQuality = 0, uint32__str1UnixSeconds = 0, float__str1UnixSecondsDecimal = 0.0, int8__str1Temperature = 0, uint8__str1ImageExposure = 0, uint8__str1ImageThreshold = 0, uint8__str1BackGroundValues = 0, uint8__str1InternalProcessCode = 0, uint8__str1CmosChipIdResult = 0, uint8__str1FpgaMRamResult = 0, uint8__str1NumberOfExtractedStars = 0, uint8__str1OperatingMode = 0, uint8__str1ImagingGain = 0, uint8__str1MinNavigationStars = 0, uint8__str1DataValid = 0, uint8__str1ExtImageState = 0, uint8__str1IdentifiedStars = 0, uint8__str1DeviceNumber = 0, uint8__str1SoftwareVersion = 0, uint8__str1EdacErrorCount = 0, uint32__str1ImageFrameNumber = 0, uint8__str1DynamicMode = 0, uint8__str1SaaMode = 0, uint8__str1SaaThreshold = 0, uint8__str1QuaternionFilteringState = 0, uint8__str1FourStarCaptureThreshold = 0, uint8__str1TrackingThreshold = 0, bool__str1EdacSwitch = False):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.uint8__str0Pst3sVersion = uint8__str0Pst3sVersion
            self.float__str0Quat1 = float__str0Quat1
            self.float__str0Quat2 = float__str0Quat2
            self.float__str0Quat3 = float__str0Quat3
            self.float__str0Quat4 = float__str0Quat4
            self.float__str0AngVelX = float__str0AngVelX
            self.float__str0AngVelY = float__str0AngVelY
            self.float__str0AngVelZ = float__str0AngVelZ
            self.uint8__str0RateQuality = uint8__str0RateQuality
            self.uint32__str0UnixSeconds = uint32__str0UnixSeconds
            self.float__str0UnixSecondsDecimal = float__str0UnixSecondsDecimal
            self.int8__str0Temperature = int8__str0Temperature
            self.uint8__str0ImageExposure = uint8__str0ImageExposure
            self.uint8__str0ImageThreshold = uint8__str0ImageThreshold
            self.uint8__str0BackGroundValues = uint8__str0BackGroundValues
            self.uint8__str0InternalProcessCode = uint8__str0InternalProcessCode
            self.uint8__str0CmosChipIdResult = uint8__str0CmosChipIdResult
            self.uint8__str0FpgaMRamResult = uint8__str0FpgaMRamResult
            self.uint8__str0NumberOfExtractedStars = uint8__str0NumberOfExtractedStars
            self.uint8__str0OperatingMode = uint8__str0OperatingMode
            self.uint8__str0ImagingGain = uint8__str0ImagingGain
            self.uint8__str0MinNavigationStars = uint8__str0MinNavigationStars
            self.uint8__str0DataValid = uint8__str0DataValid
            self.uint8__str0ExtImageState = uint8__str0ExtImageState
            self.uint8__str0IdentifiedStars = uint8__str0IdentifiedStars
            self.uint8__str0DeviceNumber = uint8__str0DeviceNumber
            self.uint8__str0SoftwareVersion = uint8__str0SoftwareVersion
            self.uint8__str0EdacErrorCount = uint8__str0EdacErrorCount
            self.uint32__str0ImageFrameNumber = uint32__str0ImageFrameNumber
            self.uint8__str0DynamicMode = uint8__str0DynamicMode
            self.uint8__str0SaaMode = uint8__str0SaaMode
            self.uint8__str0SaaThreshold = uint8__str0SaaThreshold
            self.uint8__str0QuaternionFilteringState = uint8__str0QuaternionFilteringState
            self.uint8__str0FourStarCaptureThreshold = uint8__str0FourStarCaptureThreshold
            self.uint8__str0TrackingThreshold = uint8__str0TrackingThreshold
            self.bool__str0EdacSwitch = bool__str0EdacSwitch
            self.uint8__str1Pst3sVersion = uint8__str1Pst3sVersion
            self.float__str1Quat1 = float__str1Quat1
            self.float__str1Quat2 = float__str1Quat2
            self.float__str1Quat3 = float__str1Quat3
            self.float__str1Quat4 = float__str1Quat4
            self.float__str1AngVelX = float__str1AngVelX
            self.float__str1AngVelY = float__str1AngVelY
            self.float__str1AngVelZ = float__str1AngVelZ
            self.uint8__str1RateQuality = uint8__str1RateQuality
            self.uint32__str1UnixSeconds = uint32__str1UnixSeconds
            self.float__str1UnixSecondsDecimal = float__str1UnixSecondsDecimal
            self.int8__str1Temperature = int8__str1Temperature
            self.uint8__str1ImageExposure = uint8__str1ImageExposure
            self.uint8__str1ImageThreshold = uint8__str1ImageThreshold
            self.uint8__str1BackGroundValues = uint8__str1BackGroundValues
            self.uint8__str1InternalProcessCode = uint8__str1InternalProcessCode
            self.uint8__str1CmosChipIdResult = uint8__str1CmosChipIdResult
            self.uint8__str1FpgaMRamResult = uint8__str1FpgaMRamResult
            self.uint8__str1NumberOfExtractedStars = uint8__str1NumberOfExtractedStars
            self.uint8__str1OperatingMode = uint8__str1OperatingMode
            self.uint8__str1ImagingGain = uint8__str1ImagingGain
            self.uint8__str1MinNavigationStars = uint8__str1MinNavigationStars
            self.uint8__str1DataValid = uint8__str1DataValid
            self.uint8__str1ExtImageState = uint8__str1ExtImageState
            self.uint8__str1IdentifiedStars = uint8__str1IdentifiedStars
            self.uint8__str1DeviceNumber = uint8__str1DeviceNumber
            self.uint8__str1SoftwareVersion = uint8__str1SoftwareVersion
            self.uint8__str1EdacErrorCount = uint8__str1EdacErrorCount
            self.uint32__str1ImageFrameNumber = uint32__str1ImageFrameNumber
            self.uint8__str1DynamicMode = uint8__str1DynamicMode
            self.uint8__str1SaaMode = uint8__str1SaaMode
            self.uint8__str1SaaThreshold = uint8__str1SaaThreshold
            self.uint8__str1QuaternionFilteringState = uint8__str1QuaternionFilteringState
            self.uint8__str1FourStarCaptureThreshold = uint8__str1FourStarCaptureThreshold
            self.uint8__str1TrackingThreshold = uint8__str1TrackingThreshold
            self.bool__str1EdacSwitch = bool__str1EdacSwitch
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0Pst3sVersion)
            result += SerDesHelpers.serdesType_float.serialize(self.float__str0Quat1)
            result += SerDesHelpers.serdesType_float.serialize(self.float__str0Quat2)
            result += SerDesHelpers.serdesType_float.serialize(self.float__str0Quat3)
            result += SerDesHelpers.serdesType_float.serialize(self.float__str0Quat4)
            result += SerDesHelpers.serdesType_float.serialize(self.float__str0AngVelX)
            result += SerDesHelpers.serdesType_float.serialize(self.float__str0AngVelY)
            result += SerDesHelpers.serdesType_float.serialize(self.float__str0AngVelZ)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0RateQuality)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__str0UnixSeconds)
            result += SerDesHelpers.serdesType_float.serialize(self.float__str0UnixSecondsDecimal)
            result += SerDesHelpers.serdesType_basic.serialize("int8", self.int8__str0Temperature)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0ImageExposure)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0ImageThreshold)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0BackGroundValues)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0InternalProcessCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0CmosChipIdResult)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0FpgaMRamResult)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0NumberOfExtractedStars)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0OperatingMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0ImagingGain)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0MinNavigationStars)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0DataValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0ExtImageState)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0IdentifiedStars)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0DeviceNumber)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0SoftwareVersion)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0EdacErrorCount)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__str0ImageFrameNumber)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0DynamicMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0SaaMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0SaaThreshold)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0QuaternionFilteringState)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0FourStarCaptureThreshold)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str0TrackingThreshold)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__str0EdacSwitch)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1Pst3sVersion)
            result += SerDesHelpers.serdesType_float.serialize(self.float__str1Quat1)
            result += SerDesHelpers.serdesType_float.serialize(self.float__str1Quat2)
            result += SerDesHelpers.serdesType_float.serialize(self.float__str1Quat3)
            result += SerDesHelpers.serdesType_float.serialize(self.float__str1Quat4)
            result += SerDesHelpers.serdesType_float.serialize(self.float__str1AngVelX)
            result += SerDesHelpers.serdesType_float.serialize(self.float__str1AngVelY)
            result += SerDesHelpers.serdesType_float.serialize(self.float__str1AngVelZ)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1RateQuality)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__str1UnixSeconds)
            result += SerDesHelpers.serdesType_float.serialize(self.float__str1UnixSecondsDecimal)
            result += SerDesHelpers.serdesType_basic.serialize("int8", self.int8__str1Temperature)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1ImageExposure)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1ImageThreshold)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1BackGroundValues)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1InternalProcessCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1CmosChipIdResult)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1FpgaMRamResult)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1NumberOfExtractedStars)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1OperatingMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1ImagingGain)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1MinNavigationStars)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1DataValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1ExtImageState)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1IdentifiedStars)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1DeviceNumber)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1SoftwareVersion)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1EdacErrorCount)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__str1ImageFrameNumber)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1DynamicMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1SaaMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1SaaThreshold)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1QuaternionFilteringState)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1FourStarCaptureThreshold)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__str1TrackingThreshold)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__str1EdacSwitch)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_213()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0Pst3sVersion, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__str0Quat1, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__str0Quat2, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__str0Quat3, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__str0Quat4, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__str0AngVelX, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__str0AngVelY, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__str0AngVelZ, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0RateQuality, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__str0UnixSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__str0UnixSecondsDecimal, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int8__str0Temperature, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0ImageExposure, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0ImageThreshold, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0BackGroundValues, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0InternalProcessCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0CmosChipIdResult, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0FpgaMRamResult, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0NumberOfExtractedStars, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0OperatingMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0ImagingGain, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0MinNavigationStars, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0DataValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0ExtImageState, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0IdentifiedStars, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0DeviceNumber, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0SoftwareVersion, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0EdacErrorCount, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__str0ImageFrameNumber, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0DynamicMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0SaaMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0SaaThreshold, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0QuaternionFilteringState, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0FourStarCaptureThreshold, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str0TrackingThreshold, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__str0EdacSwitch, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1Pst3sVersion, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__str1Quat1, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__str1Quat2, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__str1Quat3, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__str1Quat4, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__str1AngVelX, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__str1AngVelY, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__str1AngVelZ, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1RateQuality, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__str1UnixSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__str1UnixSecondsDecimal, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int8__str1Temperature, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1ImageExposure, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1ImageThreshold, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1BackGroundValues, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1InternalProcessCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1CmosChipIdResult, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1FpgaMRamResult, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1NumberOfExtractedStars, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1OperatingMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1ImagingGain, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1MinNavigationStars, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1DataValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1ExtImageState, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1IdentifiedStars, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1DeviceNumber, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1SoftwareVersion, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1EdacErrorCount, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__str1ImageFrameNumber, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1DynamicMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1SaaMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1SaaThreshold, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1QuaternionFilteringState, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1FourStarCaptureThreshold, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__str1TrackingThreshold, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__str1EdacSwitch, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 140
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_214:
        def __init__(self, uint16__timeSinceLoopStart = 0, uint8__currentExecutionPoint = 0, uint16__execTimeNodeSync = 0, uint16__execTimeSensorComms = 0, uint16__execTimeSensorCal = 0, uint16__execTimeEstimators = 0, uint16__execTimeControllers = 0, uint16__execTimeWheelComms = 0, uint16__execTimeModels = 0, uint16__execTimeLoopSync = 0, uint16__execTimeHealth = 0, uint16__execTimeTlmLog = 0, int16__loopRtcOffset = 0, bool__loopHasStarted = False, bool__hilSyncOk = False):
            self.uint16__timeSinceLoopStart = uint16__timeSinceLoopStart
            self.uint8__currentExecutionPoint = uint8__currentExecutionPoint
            self.uint16__execTimeNodeSync = uint16__execTimeNodeSync
            self.uint16__execTimeSensorComms = uint16__execTimeSensorComms
            self.uint16__execTimeSensorCal = uint16__execTimeSensorCal
            self.uint16__execTimeEstimators = uint16__execTimeEstimators
            self.uint16__execTimeControllers = uint16__execTimeControllers
            self.uint16__execTimeWheelComms = uint16__execTimeWheelComms
            self.uint16__execTimeModels = uint16__execTimeModels
            self.uint16__execTimeLoopSync = uint16__execTimeLoopSync
            self.uint16__execTimeHealth = uint16__execTimeHealth
            self.uint16__execTimeTlmLog = uint16__execTimeTlmLog
            self.int16__loopRtcOffset = int16__loopRtcOffset
            self.bool__loopHasStarted = bool__loopHasStarted
            self.bool__hilSyncOk = bool__hilSyncOk
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__timeSinceLoopStart)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__currentExecutionPoint)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__execTimeNodeSync)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__execTimeSensorComms)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__execTimeSensorCal)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__execTimeEstimators)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__execTimeControllers)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__execTimeWheelComms)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__execTimeModels)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__execTimeLoopSync)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__execTimeHealth)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__execTimeTlmLog)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__loopRtcOffset)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__loopHasStarted)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__hilSyncOk)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_214()
    
            currentPos = pos
            (resultInstance.uint16__timeSinceLoopStart, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__currentExecutionPoint, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__execTimeNodeSync, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__execTimeSensorComms, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__execTimeSensorCal, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__execTimeEstimators, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__execTimeControllers, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__execTimeWheelComms, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__execTimeModels, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__execTimeLoopSync, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__execTimeHealth, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__execTimeTlmLog, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__loopRtcOffset, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__loopHasStarted, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__hilSyncOk, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 27
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_216:
        def __init__(self, double__mcuTemp = 0.0, double__mcuCurrent = 0.0, uint16__mcuVoltage = 0, uint16__supplyVoltage = 0, uint16__v5Sense = 0, uint16__batteryVoltage = 0, uint16__versionVoltage = 0, double__sram1Current = 0.0, double__sram2Current = 0.0, double__fpgaCurrent1v5 = 0.0, double__framCurrent = 0.0, double__adcCurrent = 0.0, double__flashCurrent = 0.0, double__rs485Current = 0.0, double__canCurrent = 0.0, double__gyroCurrent = 0.0, double__redGyroCurrent = 0.0, bool__gyroOverVoltage = False, bool__gyroUnderVoltage = False, bool__redGyroOverVoltage = False, bool__redGyroUnderVoltage = False, a__uint8__watchdogCount = []):
            self.double__mcuTemp = double__mcuTemp
            self.double__mcuCurrent = double__mcuCurrent
            self.uint16__mcuVoltage = uint16__mcuVoltage
            self.uint16__supplyVoltage = uint16__supplyVoltage
            self.uint16__v5Sense = uint16__v5Sense
            self.uint16__batteryVoltage = uint16__batteryVoltage
            self.uint16__versionVoltage = uint16__versionVoltage
            self.double__sram1Current = double__sram1Current
            self.double__sram2Current = double__sram2Current
            self.double__fpgaCurrent1v5 = double__fpgaCurrent1v5
            self.double__framCurrent = double__framCurrent
            self.double__adcCurrent = double__adcCurrent
            self.double__flashCurrent = double__flashCurrent
            self.double__rs485Current = double__rs485Current
            self.double__canCurrent = double__canCurrent
            self.double__gyroCurrent = double__gyroCurrent
            self.double__redGyroCurrent = double__redGyroCurrent
            self.bool__gyroOverVoltage = bool__gyroOverVoltage
            self.bool__gyroUnderVoltage = bool__gyroUnderVoltage
            self.bool__redGyroOverVoltage = bool__redGyroOverVoltage
            self.bool__redGyroUnderVoltage = bool__redGyroUnderVoltage
            self.a__uint8__watchdogCount = a__uint8__watchdogCount
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__mcuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mcuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__mcuVoltage)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__supplyVoltage)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__v5Sense)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__batteryVoltage)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__versionVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__sram1Current)
            result += SerDesHelpers.serdesType_double.serialize(self.double__sram2Current)
            result += SerDesHelpers.serdesType_double.serialize(self.double__fpgaCurrent1v5)
            result += SerDesHelpers.serdesType_double.serialize(self.double__framCurrent)
            result += SerDesHelpers.serdesType_double.serialize(self.double__adcCurrent)
            result += SerDesHelpers.serdesType_double.serialize(self.double__flashCurrent)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rs485Current)
            result += SerDesHelpers.serdesType_double.serialize(self.double__canCurrent)
            result += SerDesHelpers.serdesType_double.serialize(self.double__gyroCurrent)
            result += SerDesHelpers.serdesType_double.serialize(self.double__redGyroCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__gyroOverVoltage)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__gyroUnderVoltage)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__redGyroOverVoltage)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__redGyroUnderVoltage)
            result += SerDesHelpers.serdesType_basicArray.serialize("uint8", self.a__uint8__watchdogCount)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_216()
    
            currentPos = pos
            (resultInstance.double__mcuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mcuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__mcuVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__supplyVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__v5Sense, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__batteryVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__versionVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__sram1Current, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__sram2Current, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__fpgaCurrent1v5, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__framCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__adcCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__flashCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rs485Current, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__canCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__gyroCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__redGyroCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__gyroOverVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__gyroUnderVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__redGyroOverVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__redGyroUnderVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.a__uint8__watchdogCount, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("uint8", data, currentPos, 5)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 115
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_217:
        def __init__(self, double__hss0McuTemp = 0.0, double__hss0McuCurrent = 0.0, uint16__hss0McuVoltage = 0, double__hss0DetectorTemp = 0.0, double__hss0DetectorCurrent = 0.0, double__hss1McuTemp = 0.0, double__hss1McuCurrent = 0.0, uint16__hss1McuVoltage = 0, double__hss1DetectorTemp = 0.0, double__hss1DetectorCurrent = 0.0):
            self.double__hss0McuTemp = double__hss0McuTemp
            self.double__hss0McuCurrent = double__hss0McuCurrent
            self.uint16__hss0McuVoltage = uint16__hss0McuVoltage
            self.double__hss0DetectorTemp = double__hss0DetectorTemp
            self.double__hss0DetectorCurrent = double__hss0DetectorCurrent
            self.double__hss1McuTemp = double__hss1McuTemp
            self.double__hss1McuCurrent = double__hss1McuCurrent
            self.uint16__hss1McuVoltage = uint16__hss1McuVoltage
            self.double__hss1DetectorTemp = double__hss1DetectorTemp
            self.double__hss1DetectorCurrent = double__hss1DetectorCurrent
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__hss0McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__hss0McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__hss0McuVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__hss0DetectorTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__hss0DetectorCurrent)
            result += SerDesHelpers.serdesType_double.serialize(self.double__hss1McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__hss1McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__hss1McuVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__hss1DetectorTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__hss1DetectorCurrent)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_217()
    
            currentPos = pos
            (resultInstance.double__hss0McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__hss0McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__hss0McuVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__hss0DetectorTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__hss0DetectorCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__hss1McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__hss1McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__hss1McuVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__hss1DetectorTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__hss1DetectorCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 68
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_218:
        def __init__(self, double__rwl0McuTemp = 0.0, double__rwl0McuCurrent = 0.0, uint16__rwl0BatVoltage = 0, double__rwl0BatCurrent = 0.0, double__rwl1McuTemp = 0.0, double__rwl1McuCurrent = 0.0, uint16__rwl1BatVoltage = 0, double__rwl1BatCurrent = 0.0, double__rwl2McuTemp = 0.0, double__rwl2McuCurrent = 0.0, uint16__rwl2BatVoltage = 0, double__rwl2BatCurrent = 0.0, double__rwl3McuTemp = 0.0, double__rwl3McuCurrent = 0.0, uint16__rwl3BatVoltage = 0, double__rwl3BatCurrent = 0.0):
            self.double__rwl0McuTemp = double__rwl0McuTemp
            self.double__rwl0McuCurrent = double__rwl0McuCurrent
            self.uint16__rwl0BatVoltage = uint16__rwl0BatVoltage
            self.double__rwl0BatCurrent = double__rwl0BatCurrent
            self.double__rwl1McuTemp = double__rwl1McuTemp
            self.double__rwl1McuCurrent = double__rwl1McuCurrent
            self.uint16__rwl1BatVoltage = uint16__rwl1BatVoltage
            self.double__rwl1BatCurrent = double__rwl1BatCurrent
            self.double__rwl2McuTemp = double__rwl2McuTemp
            self.double__rwl2McuCurrent = double__rwl2McuCurrent
            self.uint16__rwl2BatVoltage = uint16__rwl2BatVoltage
            self.double__rwl2BatCurrent = double__rwl2BatCurrent
            self.double__rwl3McuTemp = double__rwl3McuTemp
            self.double__rwl3McuCurrent = double__rwl3McuCurrent
            self.uint16__rwl3BatVoltage = uint16__rwl3BatVoltage
            self.double__rwl3BatCurrent = double__rwl3BatCurrent
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl0McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl0McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__rwl0BatVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl0BatCurrent)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl1McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl1McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__rwl1BatVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl1BatCurrent)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl2McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl2McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__rwl2BatVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl2BatCurrent)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl3McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl3McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__rwl3BatVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl3BatCurrent)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_218()
    
            currentPos = pos
            (resultInstance.double__rwl0McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl0McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__rwl0BatVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl0BatCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl1McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl1McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__rwl1BatVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl1BatCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl2McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl2McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__rwl2BatVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl2BatCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl3McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl3McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__rwl3BatVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl3BatCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 104
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_225:
        def __init__(self, double__rwl0McuTemp = 0.0, double__rwl0McuCurrent = 0.0, uint16__rwl0McuVoltage = 0, double__rwl0Current5v = 0.0, uint16__rwl0PmuCurrent = 0, bool__rwl0Overcurrent5v = False, bool__rwl0PowerGood = False, bool__rwl0PmuCurrentValid = False, double__rwl1McuTemp = 0.0, double__rwl1McuCurrent = 0.0, uint16__rwl1McuVoltage = 0, double__rwl1Current5v = 0.0, uint16__rwl1PmuCurrent = 0, bool__rwl1Overcurrent5v = False, bool__rwl1PowerGood = False, bool__rwl1PmuCurrentValid = False, double__rwl2McuTemp = 0.0, double__rwl2McuCurrent = 0.0, uint16__rwl2McuVoltage = 0, double__rwl2Current5v = 0.0, uint16__rwl2PmuCurrent = 0, bool__rwl2Overcurrent5v = False, bool__rwl2PowerGood = False, bool__rwl2PmuCurrentValid = False, double__rwl3McuTemp = 0.0, double__rwl3McuCurrent = 0.0, uint16__rwl3McuVoltage = 0, double__rwl3Current5v = 0.0, uint16__rwl3PmuCurrent = 0, bool__rwl3Overcurrent5v = False, bool__rwl3PowerGood = False, bool__rwl3PmuCurrentValid = False):
            self.double__rwl0McuTemp = double__rwl0McuTemp
            self.double__rwl0McuCurrent = double__rwl0McuCurrent
            self.uint16__rwl0McuVoltage = uint16__rwl0McuVoltage
            self.double__rwl0Current5v = double__rwl0Current5v
            self.uint16__rwl0PmuCurrent = uint16__rwl0PmuCurrent
            self.bool__rwl0Overcurrent5v = bool__rwl0Overcurrent5v
            self.bool__rwl0PowerGood = bool__rwl0PowerGood
            self.bool__rwl0PmuCurrentValid = bool__rwl0PmuCurrentValid
            self.double__rwl1McuTemp = double__rwl1McuTemp
            self.double__rwl1McuCurrent = double__rwl1McuCurrent
            self.uint16__rwl1McuVoltage = uint16__rwl1McuVoltage
            self.double__rwl1Current5v = double__rwl1Current5v
            self.uint16__rwl1PmuCurrent = uint16__rwl1PmuCurrent
            self.bool__rwl1Overcurrent5v = bool__rwl1Overcurrent5v
            self.bool__rwl1PowerGood = bool__rwl1PowerGood
            self.bool__rwl1PmuCurrentValid = bool__rwl1PmuCurrentValid
            self.double__rwl2McuTemp = double__rwl2McuTemp
            self.double__rwl2McuCurrent = double__rwl2McuCurrent
            self.uint16__rwl2McuVoltage = uint16__rwl2McuVoltage
            self.double__rwl2Current5v = double__rwl2Current5v
            self.uint16__rwl2PmuCurrent = uint16__rwl2PmuCurrent
            self.bool__rwl2Overcurrent5v = bool__rwl2Overcurrent5v
            self.bool__rwl2PowerGood = bool__rwl2PowerGood
            self.bool__rwl2PmuCurrentValid = bool__rwl2PmuCurrentValid
            self.double__rwl3McuTemp = double__rwl3McuTemp
            self.double__rwl3McuCurrent = double__rwl3McuCurrent
            self.uint16__rwl3McuVoltage = uint16__rwl3McuVoltage
            self.double__rwl3Current5v = double__rwl3Current5v
            self.uint16__rwl3PmuCurrent = uint16__rwl3PmuCurrent
            self.bool__rwl3Overcurrent5v = bool__rwl3Overcurrent5v
            self.bool__rwl3PowerGood = bool__rwl3PowerGood
            self.bool__rwl3PmuCurrentValid = bool__rwl3PmuCurrentValid
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl0McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl0McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__rwl0McuVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl0Current5v)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__rwl0PmuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl0Overcurrent5v)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl0PowerGood)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl0PmuCurrentValid)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl1McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl1McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__rwl1McuVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl1Current5v)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__rwl1PmuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl1Overcurrent5v)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl1PowerGood)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl1PmuCurrentValid)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl2McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl2McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__rwl2McuVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl2Current5v)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__rwl2PmuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl2Overcurrent5v)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl2PowerGood)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl2PmuCurrentValid)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl3McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl3McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__rwl3McuVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__rwl3Current5v)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__rwl3PmuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl3Overcurrent5v)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl3PowerGood)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl3PmuCurrentValid)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_225()
    
            currentPos = pos
            (resultInstance.double__rwl0McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl0McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__rwl0McuVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl0Current5v, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__rwl0PmuCurrent, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl0Overcurrent5v, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl0PowerGood, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl0PmuCurrentValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl1McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl1McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__rwl1McuVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl1Current5v, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__rwl1PmuCurrent, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl1Overcurrent5v, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl1PowerGood, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl1PmuCurrentValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl2McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl2McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__rwl2McuVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl2Current5v, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__rwl2PmuCurrent, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl2Overcurrent5v, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl2PowerGood, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl2PmuCurrentValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl3McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl3McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__rwl3McuVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__rwl3Current5v, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__rwl3PmuCurrent, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl3Overcurrent5v, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl3PowerGood, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl3PmuCurrentValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 124
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_226:
        def __init__(self, uint32__timeSeconds = 0, uint32__timeNs = 0, int16__rwl0TargetValue = 0, float__rwl0MeasSpeed = 0.0, int16__rwl0MeasCurrent = 0, int16__rwl0Temp = 0, int16__rwl1TargetValue = 0, float__rwl1MeasSpeed = 0.0, int16__rwl1MeasCurrent = 0, int16__rwl1Temp = 0, int16__rwl2TargetValue = 0, float__rwl2MeasSpeed = 0.0, int16__rwl2MeasCurrent = 0, int16__rwl2Temp = 0, int16__rwl3TargetValue = 0, float__rwl3MeasSpeed = 0.0, int16__rwl3MeasCurrent = 0, int16__rwl3Temp = 0, bool__rwl0IsValid = False, bool__rwl0WheelMode = False, bool__rwl0CurentCtrlMode = False, bool__rwl0SpeedCtrlMode = False, bool__rwl0TorqueCtrlMode = False, bool__rwl0CrcError = False, bool__rwl0WrongLlCmd = False, bool__rwl0WrongHlCmd = False, bool__rwl0ToutSci1Main = False, bool__rwl1IsValid = False, bool__rwl1WheelMode = False, bool__rwl1CurentCtrlMode = False, bool__rwl1SpeedCtrlMode = False, bool__rwl1TorqueCtrlMode = False, bool__rwl1CrcError = False, bool__rwl1WrongLlCmd = False, bool__rwl1WrongHlCmd = False, bool__rwl1ToutSci1Main = False, bool__rwl2IsValid = False, bool__rwl2WheelMode = False, bool__rwl2CurentCtrlMode = False, bool__rwl2SpeedCtrlMode = False, bool__rwl2TorqueCtrlMode = False, bool__rwl2CrcError = False, bool__rwl2WrongLlCmd = False, bool__rwl2WrongHlCmd = False, bool__rwl2ToutSci1Main = False, bool__rwl3IsValid = False, bool__rwl3WheelMode = False, bool__rwl3CurentCtrlMode = False, bool__rwl3SpeedCtrlMode = False, bool__rwl3TorqueCtrlMode = False, bool__rwl3CrcError = False, bool__rwl3WrongLlCmd = False, bool__rwl3WrongHlCmd = False, bool__rwl3ToutSci1Main = False):
            self.uint32__timeSeconds = uint32__timeSeconds
            self.uint32__timeNs = uint32__timeNs
            self.int16__rwl0TargetValue = int16__rwl0TargetValue
            self.float__rwl0MeasSpeed = float__rwl0MeasSpeed
            self.int16__rwl0MeasCurrent = int16__rwl0MeasCurrent
            self.int16__rwl0Temp = int16__rwl0Temp
            self.int16__rwl1TargetValue = int16__rwl1TargetValue
            self.float__rwl1MeasSpeed = float__rwl1MeasSpeed
            self.int16__rwl1MeasCurrent = int16__rwl1MeasCurrent
            self.int16__rwl1Temp = int16__rwl1Temp
            self.int16__rwl2TargetValue = int16__rwl2TargetValue
            self.float__rwl2MeasSpeed = float__rwl2MeasSpeed
            self.int16__rwl2MeasCurrent = int16__rwl2MeasCurrent
            self.int16__rwl2Temp = int16__rwl2Temp
            self.int16__rwl3TargetValue = int16__rwl3TargetValue
            self.float__rwl3MeasSpeed = float__rwl3MeasSpeed
            self.int16__rwl3MeasCurrent = int16__rwl3MeasCurrent
            self.int16__rwl3Temp = int16__rwl3Temp
            self.bool__rwl0IsValid = bool__rwl0IsValid
            self.bool__rwl0WheelMode = bool__rwl0WheelMode
            self.bool__rwl0CurentCtrlMode = bool__rwl0CurentCtrlMode
            self.bool__rwl0SpeedCtrlMode = bool__rwl0SpeedCtrlMode
            self.bool__rwl0TorqueCtrlMode = bool__rwl0TorqueCtrlMode
            self.bool__rwl0CrcError = bool__rwl0CrcError
            self.bool__rwl0WrongLlCmd = bool__rwl0WrongLlCmd
            self.bool__rwl0WrongHlCmd = bool__rwl0WrongHlCmd
            self.bool__rwl0ToutSci1Main = bool__rwl0ToutSci1Main
            self.bool__rwl1IsValid = bool__rwl1IsValid
            self.bool__rwl1WheelMode = bool__rwl1WheelMode
            self.bool__rwl1CurentCtrlMode = bool__rwl1CurentCtrlMode
            self.bool__rwl1SpeedCtrlMode = bool__rwl1SpeedCtrlMode
            self.bool__rwl1TorqueCtrlMode = bool__rwl1TorqueCtrlMode
            self.bool__rwl1CrcError = bool__rwl1CrcError
            self.bool__rwl1WrongLlCmd = bool__rwl1WrongLlCmd
            self.bool__rwl1WrongHlCmd = bool__rwl1WrongHlCmd
            self.bool__rwl1ToutSci1Main = bool__rwl1ToutSci1Main
            self.bool__rwl2IsValid = bool__rwl2IsValid
            self.bool__rwl2WheelMode = bool__rwl2WheelMode
            self.bool__rwl2CurentCtrlMode = bool__rwl2CurentCtrlMode
            self.bool__rwl2SpeedCtrlMode = bool__rwl2SpeedCtrlMode
            self.bool__rwl2TorqueCtrlMode = bool__rwl2TorqueCtrlMode
            self.bool__rwl2CrcError = bool__rwl2CrcError
            self.bool__rwl2WrongLlCmd = bool__rwl2WrongLlCmd
            self.bool__rwl2WrongHlCmd = bool__rwl2WrongHlCmd
            self.bool__rwl2ToutSci1Main = bool__rwl2ToutSci1Main
            self.bool__rwl3IsValid = bool__rwl3IsValid
            self.bool__rwl3WheelMode = bool__rwl3WheelMode
            self.bool__rwl3CurentCtrlMode = bool__rwl3CurentCtrlMode
            self.bool__rwl3SpeedCtrlMode = bool__rwl3SpeedCtrlMode
            self.bool__rwl3TorqueCtrlMode = bool__rwl3TorqueCtrlMode
            self.bool__rwl3CrcError = bool__rwl3CrcError
            self.bool__rwl3WrongLlCmd = bool__rwl3WrongLlCmd
            self.bool__rwl3WrongHlCmd = bool__rwl3WrongHlCmd
            self.bool__rwl3ToutSci1Main = bool__rwl3ToutSci1Main
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeSeconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__timeNs)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__rwl0TargetValue)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl0MeasSpeed)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__rwl0MeasCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__rwl0Temp)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__rwl1TargetValue)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl1MeasSpeed)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__rwl1MeasCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__rwl1Temp)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__rwl2TargetValue)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl2MeasSpeed)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__rwl2MeasCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__rwl2Temp)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__rwl3TargetValue)
            result += SerDesHelpers.serdesType_float.serialize(self.float__rwl3MeasSpeed)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__rwl3MeasCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__rwl3Temp)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl0IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl0WheelMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl0CurentCtrlMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl0SpeedCtrlMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl0TorqueCtrlMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl0CrcError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl0WrongLlCmd)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl0WrongHlCmd)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl0ToutSci1Main)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl1IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl1WheelMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl1CurentCtrlMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl1SpeedCtrlMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl1TorqueCtrlMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl1CrcError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl1WrongLlCmd)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl1WrongHlCmd)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl1ToutSci1Main)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl2IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl2WheelMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl2CurentCtrlMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl2SpeedCtrlMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl2TorqueCtrlMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl2CrcError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl2WrongLlCmd)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl2WrongHlCmd)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl2ToutSci1Main)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl3IsValid)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl3WheelMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl3CurentCtrlMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl3SpeedCtrlMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl3TorqueCtrlMode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl3CrcError)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl3WrongLlCmd)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl3WrongHlCmd)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__rwl3ToutSci1Main)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_226()
    
            currentPos = pos
            (resultInstance.uint32__timeSeconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__timeNs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__rwl0TargetValue, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl0MeasSpeed, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__rwl0MeasCurrent, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__rwl0Temp, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__rwl1TargetValue, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl1MeasSpeed, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__rwl1MeasCurrent, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__rwl1Temp, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__rwl2TargetValue, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl2MeasSpeed, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__rwl2MeasCurrent, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__rwl2Temp, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__rwl3TargetValue, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__rwl3MeasSpeed, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__rwl3MeasCurrent, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__rwl3Temp, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl0IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl0WheelMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl0CurentCtrlMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl0SpeedCtrlMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl0TorqueCtrlMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl0CrcError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl0WrongLlCmd, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl0WrongHlCmd, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl0ToutSci1Main, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl1IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl1WheelMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl1CurentCtrlMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl1SpeedCtrlMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl1TorqueCtrlMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl1CrcError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl1WrongLlCmd, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl1WrongHlCmd, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl1ToutSci1Main, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl2IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl2WheelMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl2CurentCtrlMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl2SpeedCtrlMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl2TorqueCtrlMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl2CrcError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl2WrongLlCmd, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl2WrongHlCmd, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl2ToutSci1Main, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl3IsValid, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl3WheelMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl3CurentCtrlMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl3SpeedCtrlMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl3TorqueCtrlMode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl3CrcError, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl3WrongLlCmd, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl3WrongHlCmd, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__rwl3ToutSci1Main, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 84
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_165:
        def __init__(self, double__str0McuTemp = 0.0, double__str0McuCurrent = 0.0, uint16__str0McuVoltage = 0, double__str0Current = 0.0, double__str0CurrentPk = 0.0, double__str0DetectorPcbTemp = 0.0, bool__str0SensorInitOk = False, bool__str0SensorConfigOk = False, uint32__str0ErrorCode = 0, double__str1McuTemp = 0.0, double__str1McuCurrent = 0.0, uint16__str1McuVoltage = 0, double__str1Current = 0.0, double__str1CurrentPk = 0.0, double__str1DetectorPcbTemp = 0.0, bool__str1SensorInitOk = False, bool__str1SensorConfigOk = False, uint32__str1ErrorCode = 0):
            self.double__str0McuTemp = double__str0McuTemp
            self.double__str0McuCurrent = double__str0McuCurrent
            self.uint16__str0McuVoltage = uint16__str0McuVoltage
            self.double__str0Current = double__str0Current
            self.double__str0CurrentPk = double__str0CurrentPk
            self.double__str0DetectorPcbTemp = double__str0DetectorPcbTemp
            self.bool__str0SensorInitOk = bool__str0SensorInitOk
            self.bool__str0SensorConfigOk = bool__str0SensorConfigOk
            self.uint32__str0ErrorCode = uint32__str0ErrorCode
            self.double__str1McuTemp = double__str1McuTemp
            self.double__str1McuCurrent = double__str1McuCurrent
            self.uint16__str1McuVoltage = uint16__str1McuVoltage
            self.double__str1Current = double__str1Current
            self.double__str1CurrentPk = double__str1CurrentPk
            self.double__str1DetectorPcbTemp = double__str1DetectorPcbTemp
            self.bool__str1SensorInitOk = bool__str1SensorInitOk
            self.bool__str1SensorConfigOk = bool__str1SensorConfigOk
            self.uint32__str1ErrorCode = uint32__str1ErrorCode
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__str0McuVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0Current)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0CurrentPk)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str0DetectorPcbTemp)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__str0SensorInitOk)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__str0SensorConfigOk)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__str0ErrorCode)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1McuTemp)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1McuCurrent)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__str1McuVoltage)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1Current)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1CurrentPk)
            result += SerDesHelpers.serdesType_double.serialize(self.double__str1DetectorPcbTemp)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__str1SensorInitOk)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__str1SensorConfigOk)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__str1ErrorCode)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_165()
    
            currentPos = pos
            (resultInstance.double__str0McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__str0McuVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0Current, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0CurrentPk, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str0DetectorPcbTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__str0SensorInitOk, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__str0SensorConfigOk, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__str0ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1McuTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1McuCurrent, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__str1McuVoltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1Current, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1CurrentPk, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__str1DetectorPcbTemp, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__str1SensorInitOk, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__str1SensorConfigOk, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__str1ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 96
    
    class struct_CUBEADCS_GEN2_TLM_FRAME_221:
        def __init__(self, uint8__mag0SensingElement = 0, uint8__mag1SensingElement = 0):
            self.uint8__mag0SensingElement = uint8__mag0SensingElement
            self.uint8__mag1SensingElement = uint8__mag1SensingElement
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__mag0SensingElement)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__mag1SensingElement)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_CUBEADCS_GEN2_TLM_FRAME_221()
    
            currentPos = pos
            (resultInstance.uint8__mag0SensingElement, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__mag1SensingElement, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 2
    
    class struct_GNSS_TIME:
        def __init__(self, uint8__sync = 0, a__uint8__message = [], a__uint8__port = [], int32__sequence = 0, float__idle_time = 0.0, uint32__time_status = 0, uint32__week = 0, float__seconds = 0.0, uint32__receiver_status = 0, uint32__reserved = 0, uint32__receiver_sw_version = 0, uint8__end1 = 0, uint32__clock_status = 0, double__offset = 0.0, double__offset_std = 0.0, double__utc_offset = 0.0, uint32__utc_year = 0, uint8__utc_month = 0, uint8__utc_day = 0, uint8__utc_hour = 0, uint8__utc_min = 0, uint32__utc_ms = 0, uint32__utc_status = 0, uint32__crc32 = 0, a__uint8__end2 = []):
            self.uint8__sync = uint8__sync
            self.a__uint8__message = a__uint8__message
            self.a__uint8__port = a__uint8__port
            self.int32__sequence = int32__sequence
            self.float__idle_time = float__idle_time
            self.uint32__time_status = uint32__time_status
            self.uint32__week = uint32__week
            self.float__seconds = float__seconds
            self.uint32__receiver_status = uint32__receiver_status
            self.uint32__reserved = uint32__reserved
            self.uint32__receiver_sw_version = uint32__receiver_sw_version
            self.uint8__end1 = uint8__end1
            self.uint32__clock_status = uint32__clock_status
            self.double__offset = double__offset
            self.double__offset_std = double__offset_std
            self.double__utc_offset = double__utc_offset
            self.uint32__utc_year = uint32__utc_year
            self.uint8__utc_month = uint8__utc_month
            self.uint8__utc_day = uint8__utc_day
            self.uint8__utc_hour = uint8__utc_hour
            self.uint8__utc_min = uint8__utc_min
            self.uint32__utc_ms = uint32__utc_ms
            self.uint32__utc_status = uint32__utc_status
            self.uint32__crc32 = uint32__crc32
            self.a__uint8__end2 = a__uint8__end2
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__sync)
            result += SerDesHelpers.serdesType_basicArray.serialize("uint8", self.a__uint8__message)
            result += SerDesHelpers.serdesType_basicArray.serialize("uint8", self.a__uint8__port)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__sequence)
            result += SerDesHelpers.serdesType_float.serialize(self.float__idle_time)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__time_status)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__week)
            result += SerDesHelpers.serdesType_float.serialize(self.float__seconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__receiver_status)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__reserved)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__receiver_sw_version)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__end1)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__clock_status)
            result += SerDesHelpers.serdesType_double.serialize(self.double__offset)
            result += SerDesHelpers.serdesType_double.serialize(self.double__offset_std)
            result += SerDesHelpers.serdesType_double.serialize(self.double__utc_offset)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__utc_year)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__utc_month)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__utc_day)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__utc_hour)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__utc_min)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__utc_ms)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__utc_status)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__crc32)
            result += SerDesHelpers.serdesType_basicArray.serialize("uint8", self.a__uint8__end2)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_GNSS_TIME()
    
            currentPos = pos
            (resultInstance.uint8__sync, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.a__uint8__message, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("uint8", data, currentPos, 25)
            currentPos += bytesProcessed
            (resultInstance.a__uint8__port, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("uint8", data, currentPos, 8)
            currentPos += bytesProcessed
            (resultInstance.int32__sequence, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__idle_time, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__time_status, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__week, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__seconds, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__receiver_status, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__reserved, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__receiver_sw_version, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__end1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__clock_status, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__offset, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__offset_std, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__utc_offset, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__utc_year, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__utc_month, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__utc_day, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__utc_hour, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__utc_min, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__utc_ms, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__utc_status, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__crc32, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.a__uint8__end2, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("uint8", data, currentPos, 2)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 117
    
    class struct_GNSS_BESTXYZ:
        def __init__(self, uint8__sync = 0, a__uint8__message = [], a__uint8__port = [], int32__sequence = 0, float__idle_time = 0.0, uint32__time_status = 0, uint32__week = 0, float__seconds = 0.0, uint32__receiver_status = 0, uint32__reserved1 = 0, uint32__receiver_sw_version = 0, uint8__end1 = 0, uint32__p_sol_status = 0, uint32__pos_type = 0, double__px = 0.0, double__py = 0.0, double__pz = 0.0, float__pxo = 0.0, float__pyo = 0.0, float__pzo = 0.0, uint32__v_sol_status = 0, uint32__vel_type = 0, double__vx = 0.0, double__vy = 0.0, double__vz = 0.0, float__vxo = 0.0, float__vyo = 0.0, float__vzo = 0.0, a__uint8__stn_id = [], float__v_latency = 0.0, float__diff_age = 0.0, float__sol_age = 0.0, uint8__svs = 0, uint8__solnsvs = 0, uint8__ggl1 = 0, uint8__solnmultisvs = 0, uint8__reserved2 = 0, uint8__ext_sol_stat = 0, uint8__galileo_and_beidou_sig_mask = 0, uint8__gps_and_glonass_sig_mask = 0, uint32__crc32 = 0, a__uint8__end2 = []):
            self.uint8__sync = uint8__sync
            self.a__uint8__message = a__uint8__message
            self.a__uint8__port = a__uint8__port
            self.int32__sequence = int32__sequence
            self.float__idle_time = float__idle_time
            self.uint32__time_status = uint32__time_status
            self.uint32__week = uint32__week
            self.float__seconds = float__seconds
            self.uint32__receiver_status = uint32__receiver_status
            self.uint32__reserved1 = uint32__reserved1
            self.uint32__receiver_sw_version = uint32__receiver_sw_version
            self.uint8__end1 = uint8__end1
            self.uint32__p_sol_status = uint32__p_sol_status
            self.uint32__pos_type = uint32__pos_type
            self.double__px = double__px
            self.double__py = double__py
            self.double__pz = double__pz
            self.float__pxo = float__pxo
            self.float__pyo = float__pyo
            self.float__pzo = float__pzo
            self.uint32__v_sol_status = uint32__v_sol_status
            self.uint32__vel_type = uint32__vel_type
            self.double__vx = double__vx
            self.double__vy = double__vy
            self.double__vz = double__vz
            self.float__vxo = float__vxo
            self.float__vyo = float__vyo
            self.float__vzo = float__vzo
            self.a__uint8__stn_id = a__uint8__stn_id
            self.float__v_latency = float__v_latency
            self.float__diff_age = float__diff_age
            self.float__sol_age = float__sol_age
            self.uint8__svs = uint8__svs
            self.uint8__solnsvs = uint8__solnsvs
            self.uint8__ggl1 = uint8__ggl1
            self.uint8__solnmultisvs = uint8__solnmultisvs
            self.uint8__reserved2 = uint8__reserved2
            self.uint8__ext_sol_stat = uint8__ext_sol_stat
            self.uint8__galileo_and_beidou_sig_mask = uint8__galileo_and_beidou_sig_mask
            self.uint8__gps_and_glonass_sig_mask = uint8__gps_and_glonass_sig_mask
            self.uint32__crc32 = uint32__crc32
            self.a__uint8__end2 = a__uint8__end2
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__sync)
            result += SerDesHelpers.serdesType_basicArray.serialize("uint8", self.a__uint8__message)
            result += SerDesHelpers.serdesType_basicArray.serialize("uint8", self.a__uint8__port)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__sequence)
            result += SerDesHelpers.serdesType_float.serialize(self.float__idle_time)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__time_status)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__week)
            result += SerDesHelpers.serdesType_float.serialize(self.float__seconds)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__receiver_status)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__reserved1)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__receiver_sw_version)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__end1)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__p_sol_status)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__pos_type)
            result += SerDesHelpers.serdesType_double.serialize(self.double__px)
            result += SerDesHelpers.serdesType_double.serialize(self.double__py)
            result += SerDesHelpers.serdesType_double.serialize(self.double__pz)
            result += SerDesHelpers.serdesType_float.serialize(self.float__pxo)
            result += SerDesHelpers.serdesType_float.serialize(self.float__pyo)
            result += SerDesHelpers.serdesType_float.serialize(self.float__pzo)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__v_sol_status)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__vel_type)
            result += SerDesHelpers.serdesType_double.serialize(self.double__vx)
            result += SerDesHelpers.serdesType_double.serialize(self.double__vy)
            result += SerDesHelpers.serdesType_double.serialize(self.double__vz)
            result += SerDesHelpers.serdesType_float.serialize(self.float__vxo)
            result += SerDesHelpers.serdesType_float.serialize(self.float__vyo)
            result += SerDesHelpers.serdesType_float.serialize(self.float__vzo)
            result += SerDesHelpers.serdesType_basicArray.serialize("uint8", self.a__uint8__stn_id)
            result += SerDesHelpers.serdesType_float.serialize(self.float__v_latency)
            result += SerDesHelpers.serdesType_float.serialize(self.float__diff_age)
            result += SerDesHelpers.serdesType_float.serialize(self.float__sol_age)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__svs)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__solnsvs)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__ggl1)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__solnmultisvs)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__reserved2)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__ext_sol_stat)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__galileo_and_beidou_sig_mask)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__gps_and_glonass_sig_mask)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__crc32)
            result += SerDesHelpers.serdesType_basicArray.serialize("uint8", self.a__uint8__end2)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_GNSS_BESTXYZ()
    
            currentPos = pos
            (resultInstance.uint8__sync, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.a__uint8__message, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("uint8", data, currentPos, 25)
            currentPos += bytesProcessed
            (resultInstance.a__uint8__port, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("uint8", data, currentPos, 8)
            currentPos += bytesProcessed
            (resultInstance.int32__sequence, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__idle_time, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__time_status, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__week, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__seconds, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__receiver_status, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__reserved1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__receiver_sw_version, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__end1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__p_sol_status, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__pos_type, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__px, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__py, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__pz, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__pxo, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__pyo, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__pzo, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__v_sol_status, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__vel_type, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__vx, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__vy, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__vz, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__vxo, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__vyo, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__vzo, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.a__uint8__stn_id, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("uint8", data, currentPos, 4)
            currentPos += bytesProcessed
            (resultInstance.float__v_latency, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__diff_age, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.float__sol_age, bytesProcessed) = SerDesHelpers.serdesType_float.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__svs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__solnsvs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__ggl1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__solnmultisvs, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__reserved2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__ext_sol_stat, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__galileo_and_beidou_sig_mask, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__gps_and_glonass_sig_mask, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__crc32, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.a__uint8__end2, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("uint8", data, currentPos, 2)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 185
    
    class struct_SAT_STATE_VECTOR_FROM_PROPAGATOR:
        def __init__(self, double__px = 0.0, double__py = 0.0, double__pz = 0.0, double__vx = 0.0, double__vy = 0.0, double__vz = 0.0):
            self.double__px = double__px
            self.double__py = double__py
            self.double__pz = double__pz
            self.double__vx = double__vx
            self.double__vy = double__vy
            self.double__vz = double__vz
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__px)
            result += SerDesHelpers.serdesType_double.serialize(self.double__py)
            result += SerDesHelpers.serdesType_double.serialize(self.double__pz)
            result += SerDesHelpers.serdesType_double.serialize(self.double__vx)
            result += SerDesHelpers.serdesType_double.serialize(self.double__vy)
            result += SerDesHelpers.serdesType_double.serialize(self.double__vz)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_SAT_STATE_VECTOR_FROM_PROPAGATOR()
    
            currentPos = pos
            (resultInstance.double__px, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__py, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__pz, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__vx, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__vy, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__vz, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 48
    
    class struct_SAT_MAG_FIELD_VECTOR_FROM_MODEL:
        def __init__(self, double__mag_field_x = 0.0, double__mag_field_y = 0.0, double__mag_field_z = 0.0):
            self.double__mag_field_x = double__mag_field_x
            self.double__mag_field_y = double__mag_field_y
            self.double__mag_field_z = double__mag_field_z
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_field_x)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_field_y)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_field_z)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_SAT_MAG_FIELD_VECTOR_FROM_MODEL()
    
            currentPos = pos
            (resultInstance.double__mag_field_x, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_field_y, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_field_z, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 24
    
    class struct_SAT_MAG_FIELD_VECTOR_FROM_SENSOR:
        def __init__(self, double__mag_field_x_current = 0.0, double__mag_field_y_current = 0.0, double__mag_field_z_current = 0.0, double__mag_field_x_previous = 0.0, double__mag_field_y_previous = 0.0, double__mag_field_z_previous = 0.0):
            self.double__mag_field_x_current = double__mag_field_x_current
            self.double__mag_field_y_current = double__mag_field_y_current
            self.double__mag_field_z_current = double__mag_field_z_current
            self.double__mag_field_x_previous = double__mag_field_x_previous
            self.double__mag_field_y_previous = double__mag_field_y_previous
            self.double__mag_field_z_previous = double__mag_field_z_previous
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_field_x_current)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_field_y_current)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_field_z_current)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_field_x_previous)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_field_y_previous)
            result += SerDesHelpers.serdesType_double.serialize(self.double__mag_field_z_previous)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_SAT_MAG_FIELD_VECTOR_FROM_SENSOR()
    
            currentPos = pos
            (resultInstance.double__mag_field_x_current, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_field_y_current, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_field_z_current, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_field_x_previous, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_field_y_previous, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.double__mag_field_z_previous, bytesProcessed) = SerDesHelpers.serdesType_double.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 48
    
    class struct_FDIR_EPS_I_CMD_EXEC_STATUS:
        def __init__(self, bool__error_occured = False):
            self.bool__error_occured = bool__error_occured
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__error_occured)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_FDIR_EPS_I_CMD_EXEC_STATUS()
    
            currentPos = pos
            (resultInstance.bool__error_occured, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_FDIR_EPS_II_PDM_CMD_EXEC_STATUS:
        def __init__(self, uint8__EPSII_PDM_1_GetPowerDistributionInfo_ErrorCode = 0, uint8__EPSII_PDM_1_GetDeviceHealthInfo_ErrorCode = 0, uint8__EPSII_PDM_1_GetRAWSensors_PDM1_ErrorCode = 0, uint8__EPSII_PDM_1_GetRAWSensors_PDM2_ErrorCode = 0):
            self.uint8__EPSII_PDM_1_GetPowerDistributionInfo_ErrorCode = uint8__EPSII_PDM_1_GetPowerDistributionInfo_ErrorCode
            self.uint8__EPSII_PDM_1_GetDeviceHealthInfo_ErrorCode = uint8__EPSII_PDM_1_GetDeviceHealthInfo_ErrorCode
            self.uint8__EPSII_PDM_1_GetRAWSensors_PDM1_ErrorCode = uint8__EPSII_PDM_1_GetRAWSensors_PDM1_ErrorCode
            self.uint8__EPSII_PDM_1_GetRAWSensors_PDM2_ErrorCode = uint8__EPSII_PDM_1_GetRAWSensors_PDM2_ErrorCode
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__EPSII_PDM_1_GetPowerDistributionInfo_ErrorCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__EPSII_PDM_1_GetDeviceHealthInfo_ErrorCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__EPSII_PDM_1_GetRAWSensors_PDM1_ErrorCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__EPSII_PDM_1_GetRAWSensors_PDM2_ErrorCode)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_FDIR_EPS_II_PDM_CMD_EXEC_STATUS()
    
            currentPos = pos
            (resultInstance.uint8__EPSII_PDM_1_GetPowerDistributionInfo_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__EPSII_PDM_1_GetDeviceHealthInfo_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__EPSII_PDM_1_GetRAWSensors_PDM1_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__EPSII_PDM_1_GetRAWSensors_PDM2_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 4
    
    class struct_FDIR_CUBEADCS_CMD_EXEC_STATUS:
        def __init__(self, uint8__error_code = 0):
            self.uint8__error_code = uint8__error_code
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__error_code)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_FDIR_CUBEADCS_CMD_EXEC_STATUS()
    
            currentPos = pos
            (resultInstance.uint8__error_code, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS:
        def __init__(self, bool__error_occured = False):
            self.bool__error_occured = bool__error_occured
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__error_occured)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS()
    
            currentPos = pos
            (resultInstance.bool__error_occured, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_FDIR_CUBEADCS_GEN2_EVENTS:
        def __init__(self, a__bool__node_comm_error = [], a__bool__node_failure = [], a__bool__node_setup_error = [], a__bool__node_discovery_error = [], a__bool__node_port_validation_error = [], a__bool__gyro_voltage_error = [], a__bool__gyro_critical_error = [], bool__control_loop_failure = False, bool__control_loop_critical_error = False, bool__configuration_validation_error = False, bool__configuration_persist_error = False, bool__virtual_watchdog_error = False):
            self.a__bool__node_comm_error = a__bool__node_comm_error
            self.a__bool__node_failure = a__bool__node_failure
            self.a__bool__node_setup_error = a__bool__node_setup_error
            self.a__bool__node_discovery_error = a__bool__node_discovery_error
            self.a__bool__node_port_validation_error = a__bool__node_port_validation_error
            self.a__bool__gyro_voltage_error = a__bool__gyro_voltage_error
            self.a__bool__gyro_critical_error = a__bool__gyro_critical_error
            self.bool__control_loop_failure = bool__control_loop_failure
            self.bool__control_loop_critical_error = bool__control_loop_critical_error
            self.bool__configuration_validation_error = bool__configuration_validation_error
            self.bool__configuration_persist_error = bool__configuration_persist_error
            self.bool__virtual_watchdog_error = bool__virtual_watchdog_error
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basicArray.serialize("uint8", self.a__bool__node_comm_error)
            result += SerDesHelpers.serdesType_basicArray.serialize("uint8", self.a__bool__node_failure)
            result += SerDesHelpers.serdesType_basicArray.serialize("uint8", self.a__bool__node_setup_error)
            result += SerDesHelpers.serdesType_basicArray.serialize("uint8", self.a__bool__node_discovery_error)
            result += SerDesHelpers.serdesType_basicArray.serialize("uint8", self.a__bool__node_port_validation_error)
            result += SerDesHelpers.serdesType_basicArray.serialize("uint8", self.a__bool__gyro_voltage_error)
            result += SerDesHelpers.serdesType_basicArray.serialize("uint8", self.a__bool__gyro_critical_error)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__control_loop_failure)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__control_loop_critical_error)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__configuration_validation_error)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__configuration_persist_error)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__virtual_watchdog_error)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_FDIR_CUBEADCS_GEN2_EVENTS()
    
            currentPos = pos
            (resultInstance.a__bool__node_comm_error, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("uint8", data, currentPos, 7)
            currentPos += bytesProcessed
            (resultInstance.a__bool__node_failure, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("uint8", data, currentPos, 7)
            currentPos += bytesProcessed
            (resultInstance.a__bool__node_setup_error, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("uint8", data, currentPos, 7)
            currentPos += bytesProcessed
            (resultInstance.a__bool__node_discovery_error, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("uint8", data, currentPos, 7)
            currentPos += bytesProcessed
            (resultInstance.a__bool__node_port_validation_error, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("uint8", data, currentPos, 7)
            currentPos += bytesProcessed
            (resultInstance.a__bool__gyro_voltage_error, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("uint8", data, currentPos, 2)
            currentPos += bytesProcessed
            (resultInstance.a__bool__gyro_critical_error, bytesProcessed) = SerDesHelpers.serdesType_basicArray.deserialize("uint8", data, currentPos, 2)
            currentPos += bytesProcessed
            (resultInstance.bool__control_loop_failure, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__control_loop_critical_error, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__configuration_validation_error, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__configuration_persist_error, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.bool__virtual_watchdog_error, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 44
    
    class struct_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS:
        def __init__(self, uint8__error_code = 0):
            self.uint8__error_code = uint8__error_code
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__error_code)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS()
    
            currentPos = pos
            (resultInstance.uint8__error_code, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_FDIR_UHF_CMD_EXEC_STATUS:
        def __init__(self, bool__error_occured = False):
            self.bool__error_occured = bool__error_occured
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__error_occured)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_FDIR_UHF_CMD_EXEC_STATUS()
    
            currentPos = pos
            (resultInstance.bool__error_occured, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_FDIR_GNSS_CMD_EXEC_STATUS:
        def __init__(self, bool__error_occured = False):
            self.bool__error_occured = bool__error_occured
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__error_occured)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_FDIR_GNSS_CMD_EXEC_STATUS()
    
            currentPos = pos
            (resultInstance.bool__error_occured, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_FDIR_SDR_CMD_EXEC_STATUS:
        def __init__(self, bool__error_occured = False):
            self.bool__error_occured = bool__error_occured
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__error_occured)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_FDIR_SDR_CMD_EXEC_STATUS()
    
            currentPos = pos
            (resultInstance.bool__error_occured, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_FDIR_S_X_BAND_CMD_EXEC_STATUS:
        def __init__(self, uint16__error_code = 0):
            self.uint16__error_code = uint16__error_code
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__error_code)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_FDIR_S_X_BAND_CMD_EXEC_STATUS()
    
            currentPos = pos
            (resultInstance.uint16__error_code, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 2
    
    class struct_FDIR_THRUSTER_CMD_EXEC_STATUS:
        def __init__(self, bool__error_occured = False):
            self.bool__error_occured = bool__error_occured
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.bool__error_occured)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_FDIR_THRUSTER_CMD_EXEC_STATUS()
    
            currentPos = pos
            (resultInstance.bool__error_occured, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_XBandFeTelemetry:
        def __init__(self, uint8__system_state = 0, uint8__status_flags = 0, int16__pa_temperature = 0, int16__pa_pwr_det = 0, uint16__powsup_5v_rf_drv = 0, uint16__pa_idd = 0, uint16__pa_vdd = 0, uint16__powsup_5v_vco_drv = 0, uint16__powsup_3v3_pll = 0, uint16__powsup_5v_if_amp = 0, uint16__powsup_5v_att = 0, int16__pa_vgg = 0, uint16__cpu_vdd = 0, int16__cpu_temperature = 0, uint16__adc_vref_internal = 0):
            self.uint8__system_state = uint8__system_state
            self.uint8__status_flags = uint8__status_flags
            self.int16__pa_temperature = int16__pa_temperature
            self.int16__pa_pwr_det = int16__pa_pwr_det
            self.uint16__powsup_5v_rf_drv = uint16__powsup_5v_rf_drv
            self.uint16__pa_idd = uint16__pa_idd
            self.uint16__pa_vdd = uint16__pa_vdd
            self.uint16__powsup_5v_vco_drv = uint16__powsup_5v_vco_drv
            self.uint16__powsup_3v3_pll = uint16__powsup_3v3_pll
            self.uint16__powsup_5v_if_amp = uint16__powsup_5v_if_amp
            self.uint16__powsup_5v_att = uint16__powsup_5v_att
            self.int16__pa_vgg = int16__pa_vgg
            self.uint16__cpu_vdd = uint16__cpu_vdd
            self.int16__cpu_temperature = int16__cpu_temperature
            self.uint16__adc_vref_internal = uint16__adc_vref_internal
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__system_state)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__status_flags)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__pa_temperature)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__pa_pwr_det)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__powsup_5v_rf_drv)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__pa_idd)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__pa_vdd)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__powsup_5v_vco_drv)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__powsup_3v3_pll)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__powsup_5v_if_amp)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__powsup_5v_att)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__pa_vgg)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__cpu_vdd)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__cpu_temperature)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__adc_vref_internal)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_XBandFeTelemetry()
    
            currentPos = pos
            (resultInstance.uint8__system_state, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__status_flags, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__pa_temperature, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__pa_pwr_det, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__powsup_5v_rf_drv, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__pa_idd, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__pa_vdd, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__powsup_5v_vco_drv, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__powsup_3v3_pll, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__powsup_5v_if_amp, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__powsup_5v_att, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__pa_vgg, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__cpu_vdd, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__cpu_temperature, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__adc_vref_internal, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 28
    
    class struct_EpsOverallBatteryInfoType:
        def __init__(self, uint32__Capacity = 0, uint16__Voltage = 0):
            self.uint32__Capacity = uint32__Capacity
            self.uint16__Voltage = uint16__Voltage
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__Capacity)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Voltage)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_EpsOverallBatteryInfoType()
    
            currentPos = pos
            (resultInstance.uint32__Capacity, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Voltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 6
    
    class struct_PPS_Telemetry:
        def __init__(self, uint32__pps_detect_cnt = 0, uint32__last_pps_uptime = 0, uint8__current_drv_status = 0, uint8__latest_rtc_sync_status = 0, uint32__rtc_sync_success_cnt = 0, uint32__rtc_sync_fail_cnt = 0, uint32__pps_timeout_cnt = 0):
            self.uint32__pps_detect_cnt = uint32__pps_detect_cnt
            self.uint32__last_pps_uptime = uint32__last_pps_uptime
            self.uint8__current_drv_status = uint8__current_drv_status
            self.uint8__latest_rtc_sync_status = uint8__latest_rtc_sync_status
            self.uint32__rtc_sync_success_cnt = uint32__rtc_sync_success_cnt
            self.uint32__rtc_sync_fail_cnt = uint32__rtc_sync_fail_cnt
            self.uint32__pps_timeout_cnt = uint32__pps_timeout_cnt
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__pps_detect_cnt)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__last_pps_uptime)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__current_drv_status)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__latest_rtc_sync_status)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__rtc_sync_success_cnt)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__rtc_sync_fail_cnt)
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__pps_timeout_cnt)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_PPS_Telemetry()
    
            currentPos = pos
            (resultInstance.uint32__pps_detect_cnt, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__last_pps_uptime, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__current_drv_status, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__latest_rtc_sync_status, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__rtc_sync_success_cnt, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__rtc_sync_fail_cnt, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint32__pps_timeout_cnt, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 22
    
    class struct_FDIR_EPS_III_PDM_CMD_EXEC_STATUS:
        def __init__(self, uint8__eps_iii_pdm_a_get_telemetry_ErrorCode = 0):
            self.uint8__eps_iii_pdm_a_get_telemetry_ErrorCode = uint8__eps_iii_pdm_a_get_telemetry_ErrorCode
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__eps_iii_pdm_a_get_telemetry_ErrorCode)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_FDIR_EPS_III_PDM_CMD_EXEC_STATUS()
    
            currentPos = pos
            (resultInstance.uint8__eps_iii_pdm_a_get_telemetry_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_Eps2Inst0BatteryInfoType:
        def __init__(self, uint32__Capacity = 0, uint16__Voltage = 0, int16__Current = 0, int32__Temperature = 0, uint8__bp_mode = 0):
            self.uint32__Capacity = uint32__Capacity
            self.uint16__Voltage = uint16__Voltage
            self.int16__Current = int16__Current
            self.int32__Temperature = int32__Temperature
            self.uint8__bp_mode = uint8__bp_mode
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__Capacity)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Voltage)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Current)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Temperature)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__bp_mode)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst0BatteryInfoType()
    
            currentPos = pos
            (resultInstance.uint32__Capacity, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Voltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Temperature, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__bp_mode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 13
    
    class struct_Eps2Inst0DeviceHealthInfoType:
        def __init__(self, int32__ActiveCPU_RunningTime = 0, int32__ActiveCPU_Voltage = 0, int32__ActiveCPU_Temperature = 0, int32__PCB_Temperature_1 = 0, int32__PCB_Temperature_2 = 0, uint8__BALANCER_CHIP_1 = 0, uint8__LT8491_IC_XP = 0, uint8__LT8491_IC_XR = 0, uint8__LT8491_IC_YP = 0, uint8__LT8491_IC_YR = 0, uint8__LT8491_IC_ZP = 0, uint8__LT8491_IC_ZR = 0, uint8__INA_BAT_OUT_1 = 0, uint8__INA_BAT_OUT_2 = 0, uint8__TMP117_U810 = 0, uint8__TMP117_U811 = 0, uint8__GPIO_PCA9538_U2001 = 0, uint8__GPIO_PCA9538_U2002 = 0):
            self.int32__ActiveCPU_RunningTime = int32__ActiveCPU_RunningTime
            self.int32__ActiveCPU_Voltage = int32__ActiveCPU_Voltage
            self.int32__ActiveCPU_Temperature = int32__ActiveCPU_Temperature
            self.int32__PCB_Temperature_1 = int32__PCB_Temperature_1
            self.int32__PCB_Temperature_2 = int32__PCB_Temperature_2
            self.uint8__BALANCER_CHIP_1 = uint8__BALANCER_CHIP_1
            self.uint8__LT8491_IC_XP = uint8__LT8491_IC_XP
            self.uint8__LT8491_IC_XR = uint8__LT8491_IC_XR
            self.uint8__LT8491_IC_YP = uint8__LT8491_IC_YP
            self.uint8__LT8491_IC_YR = uint8__LT8491_IC_YR
            self.uint8__LT8491_IC_ZP = uint8__LT8491_IC_ZP
            self.uint8__LT8491_IC_ZR = uint8__LT8491_IC_ZR
            self.uint8__INA_BAT_OUT_1 = uint8__INA_BAT_OUT_1
            self.uint8__INA_BAT_OUT_2 = uint8__INA_BAT_OUT_2
            self.uint8__TMP117_U810 = uint8__TMP117_U810
            self.uint8__TMP117_U811 = uint8__TMP117_U811
            self.uint8__GPIO_PCA9538_U2001 = uint8__GPIO_PCA9538_U2001
            self.uint8__GPIO_PCA9538_U2002 = uint8__GPIO_PCA9538_U2002
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__ActiveCPU_RunningTime)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__ActiveCPU_Voltage)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__ActiveCPU_Temperature)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__PCB_Temperature_1)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__PCB_Temperature_2)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__BALANCER_CHIP_1)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__LT8491_IC_XP)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__LT8491_IC_XR)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__LT8491_IC_YP)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__LT8491_IC_YR)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__LT8491_IC_ZP)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__LT8491_IC_ZR)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__INA_BAT_OUT_1)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__INA_BAT_OUT_2)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__TMP117_U810)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__TMP117_U811)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__GPIO_PCA9538_U2001)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__GPIO_PCA9538_U2002)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst0DeviceHealthInfoType()
    
            currentPos = pos
            (resultInstance.int32__ActiveCPU_RunningTime, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__ActiveCPU_Voltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__ActiveCPU_Temperature, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__PCB_Temperature_1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__PCB_Temperature_2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__BALANCER_CHIP_1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__LT8491_IC_XP, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__LT8491_IC_XR, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__LT8491_IC_YP, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__LT8491_IC_YR, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__LT8491_IC_ZP, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__LT8491_IC_ZR, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__INA_BAT_OUT_1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__INA_BAT_OUT_2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__TMP117_U810, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__TMP117_U811, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__GPIO_PCA9538_U2001, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__GPIO_PCA9538_U2002, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 33
    
    class struct_Eps2Inst0InaSensors1Type:
        def __init__(self, uint16__Voltage = 0, int16__Current = 0, int16__Energy = 0, int16__Temperature = 0):
            self.uint16__Voltage = uint16__Voltage
            self.int16__Current = int16__Current
            self.int16__Energy = int16__Energy
            self.int16__Temperature = int16__Temperature
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Voltage)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Current)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Energy)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Temperature)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst0InaSensors1Type()
    
            currentPos = pos
            (resultInstance.uint16__Voltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Energy, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Temperature, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 8
    
    class struct_Eps2Inst0InaSensors2Type:
        def __init__(self, uint16__Voltage = 0, int16__Current = 0, int16__Energy = 0, int16__Temperature = 0):
            self.uint16__Voltage = uint16__Voltage
            self.int16__Current = int16__Current
            self.int16__Energy = int16__Energy
            self.int16__Temperature = int16__Temperature
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Voltage)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Current)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Energy)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Temperature)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst0InaSensors2Type()
    
            currentPos = pos
            (resultInstance.uint16__Voltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Energy, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Temperature, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 8
    
    class struct_Eps2Inst0BalancerInfoType:
        def __init__(self, uint16__Voltage = 0, int16__Current = 0, int16__Internal_Temperature = 0):
            self.uint16__Voltage = uint16__Voltage
            self.int16__Current = int16__Current
            self.int16__Internal_Temperature = int16__Internal_Temperature
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Voltage)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Current)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Internal_Temperature)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst0BalancerInfoType()
    
            currentPos = pos
            (resultInstance.uint16__Voltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Internal_Temperature, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 6
    
    class struct_Eps2Inst0BalancerStatusType:
        def __init__(self, uint8__COM_STATE = 0, uint8__status_register_0 = 0, uint8__status_register_1 = 0, uint8__status_register_2 = 0, uint8__status_register_3 = 0):
            self.uint8__COM_STATE = uint8__COM_STATE
            self.uint8__status_register_0 = uint8__status_register_0
            self.uint8__status_register_1 = uint8__status_register_1
            self.uint8__status_register_2 = uint8__status_register_2
            self.uint8__status_register_3 = uint8__status_register_3
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__COM_STATE)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__status_register_0)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__status_register_1)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__status_register_2)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__status_register_3)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst0BalancerStatusType()
    
            currentPos = pos
            (resultInstance.uint8__COM_STATE, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__status_register_0, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__status_register_1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__status_register_2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__status_register_3, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 5
    
    class struct_Eps2Inst0BalancerCellsInfoType:
        def __init__(self, uint16__Cell_1 = 0, uint16__Cell_2 = 0, uint16__Cell_3 = 0, uint16__Cell_4 = 0, uint16__Cell_5 = 0, uint16__Cell_6 = 0, uint16__Cell_7 = 0, uint16__Cell_8 = 0):
            self.uint16__Cell_1 = uint16__Cell_1
            self.uint16__Cell_2 = uint16__Cell_2
            self.uint16__Cell_3 = uint16__Cell_3
            self.uint16__Cell_4 = uint16__Cell_4
            self.uint16__Cell_5 = uint16__Cell_5
            self.uint16__Cell_6 = uint16__Cell_6
            self.uint16__Cell_7 = uint16__Cell_7
            self.uint16__Cell_8 = uint16__Cell_8
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cell_1)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cell_2)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cell_3)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cell_4)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cell_5)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cell_6)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cell_7)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cell_8)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst0BalancerCellsInfoType()
    
            currentPos = pos
            (resultInstance.uint16__Cell_1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Cell_2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Cell_3, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Cell_4, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Cell_5, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Cell_6, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Cell_7, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Cell_8, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 16
    
    class struct_Eps2Inst0ChargerXpType:
        def __init__(self, uint8__COM_STATE = 0, uint16__STAT_SUPPLY = 0, uint16__TELE_POUT = 0, uint16__TELE_PIN = 0, uint16__TELE_IOUT = 0, uint16__TELE_IIN = 0, uint16__TELE_VBAT = 0, uint16__TELE_VINR = 0):
            self.uint8__COM_STATE = uint8__COM_STATE
            self.uint16__STAT_SUPPLY = uint16__STAT_SUPPLY
            self.uint16__TELE_POUT = uint16__TELE_POUT
            self.uint16__TELE_PIN = uint16__TELE_PIN
            self.uint16__TELE_IOUT = uint16__TELE_IOUT
            self.uint16__TELE_IIN = uint16__TELE_IIN
            self.uint16__TELE_VBAT = uint16__TELE_VBAT
            self.uint16__TELE_VINR = uint16__TELE_VINR
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__COM_STATE)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__STAT_SUPPLY)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_POUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_PIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IOUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VBAT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VINR)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst0ChargerXpType()
    
            currentPos = pos
            (resultInstance.uint8__COM_STATE, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__STAT_SUPPLY, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_POUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_PIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IOUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VBAT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VINR, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 15
    
    class struct_Eps2Inst0ChargerXrType:
        def __init__(self, uint8__COM_STATE = 0, uint16__STAT_SUPPLY = 0, uint16__TELE_POUT = 0, uint16__TELE_PIN = 0, uint16__TELE_IOUT = 0, uint16__TELE_IIN = 0, uint16__TELE_VBAT = 0, uint16__TELE_VINR = 0):
            self.uint8__COM_STATE = uint8__COM_STATE
            self.uint16__STAT_SUPPLY = uint16__STAT_SUPPLY
            self.uint16__TELE_POUT = uint16__TELE_POUT
            self.uint16__TELE_PIN = uint16__TELE_PIN
            self.uint16__TELE_IOUT = uint16__TELE_IOUT
            self.uint16__TELE_IIN = uint16__TELE_IIN
            self.uint16__TELE_VBAT = uint16__TELE_VBAT
            self.uint16__TELE_VINR = uint16__TELE_VINR
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__COM_STATE)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__STAT_SUPPLY)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_POUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_PIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IOUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VBAT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VINR)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst0ChargerXrType()
    
            currentPos = pos
            (resultInstance.uint8__COM_STATE, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__STAT_SUPPLY, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_POUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_PIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IOUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VBAT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VINR, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 15
    
    class struct_Eps2Inst0ChargerYpType:
        def __init__(self, uint8__COM_STATE = 0, uint16__STAT_SUPPLY = 0, uint16__TELE_POUT = 0, uint16__TELE_PIN = 0, uint16__TELE_IOUT = 0, uint16__TELE_IIN = 0, uint16__TELE_VBAT = 0, uint16__TELE_VINR = 0):
            self.uint8__COM_STATE = uint8__COM_STATE
            self.uint16__STAT_SUPPLY = uint16__STAT_SUPPLY
            self.uint16__TELE_POUT = uint16__TELE_POUT
            self.uint16__TELE_PIN = uint16__TELE_PIN
            self.uint16__TELE_IOUT = uint16__TELE_IOUT
            self.uint16__TELE_IIN = uint16__TELE_IIN
            self.uint16__TELE_VBAT = uint16__TELE_VBAT
            self.uint16__TELE_VINR = uint16__TELE_VINR
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__COM_STATE)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__STAT_SUPPLY)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_POUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_PIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IOUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VBAT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VINR)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst0ChargerYpType()
    
            currentPos = pos
            (resultInstance.uint8__COM_STATE, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__STAT_SUPPLY, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_POUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_PIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IOUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VBAT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VINR, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 15
    
    class struct_Eps2Inst0ChargerYrType:
        def __init__(self, uint8__COM_STATE = 0, uint16__STAT_SUPPLY = 0, uint16__TELE_POUT = 0, uint16__TELE_PIN = 0, uint16__TELE_IOUT = 0, uint16__TELE_IIN = 0, uint16__TELE_VBAT = 0, uint16__TELE_VINR = 0):
            self.uint8__COM_STATE = uint8__COM_STATE
            self.uint16__STAT_SUPPLY = uint16__STAT_SUPPLY
            self.uint16__TELE_POUT = uint16__TELE_POUT
            self.uint16__TELE_PIN = uint16__TELE_PIN
            self.uint16__TELE_IOUT = uint16__TELE_IOUT
            self.uint16__TELE_IIN = uint16__TELE_IIN
            self.uint16__TELE_VBAT = uint16__TELE_VBAT
            self.uint16__TELE_VINR = uint16__TELE_VINR
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__COM_STATE)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__STAT_SUPPLY)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_POUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_PIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IOUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VBAT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VINR)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst0ChargerYrType()
    
            currentPos = pos
            (resultInstance.uint8__COM_STATE, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__STAT_SUPPLY, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_POUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_PIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IOUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VBAT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VINR, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 15
    
    class struct_Eps2Inst0ChargerZpType:
        def __init__(self, uint8__COM_STATE = 0, uint16__STAT_SUPPLY = 0, uint16__TELE_POUT = 0, uint16__TELE_PIN = 0, uint16__TELE_IOUT = 0, uint16__TELE_IIN = 0, uint16__TELE_VBAT = 0, uint16__TELE_VINR = 0):
            self.uint8__COM_STATE = uint8__COM_STATE
            self.uint16__STAT_SUPPLY = uint16__STAT_SUPPLY
            self.uint16__TELE_POUT = uint16__TELE_POUT
            self.uint16__TELE_PIN = uint16__TELE_PIN
            self.uint16__TELE_IOUT = uint16__TELE_IOUT
            self.uint16__TELE_IIN = uint16__TELE_IIN
            self.uint16__TELE_VBAT = uint16__TELE_VBAT
            self.uint16__TELE_VINR = uint16__TELE_VINR
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__COM_STATE)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__STAT_SUPPLY)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_POUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_PIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IOUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VBAT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VINR)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst0ChargerZpType()
    
            currentPos = pos
            (resultInstance.uint8__COM_STATE, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__STAT_SUPPLY, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_POUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_PIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IOUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VBAT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VINR, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 15
    
    class struct_Eps2Inst0ChargerZrType:
        def __init__(self, uint8__COM_STATE = 0, uint16__STAT_SUPPLY = 0, uint16__TELE_POUT = 0, uint16__TELE_PIN = 0, uint16__TELE_IOUT = 0, uint16__TELE_IIN = 0, uint16__TELE_VBAT = 0, uint16__TELE_VINR = 0):
            self.uint8__COM_STATE = uint8__COM_STATE
            self.uint16__STAT_SUPPLY = uint16__STAT_SUPPLY
            self.uint16__TELE_POUT = uint16__TELE_POUT
            self.uint16__TELE_PIN = uint16__TELE_PIN
            self.uint16__TELE_IOUT = uint16__TELE_IOUT
            self.uint16__TELE_IIN = uint16__TELE_IIN
            self.uint16__TELE_VBAT = uint16__TELE_VBAT
            self.uint16__TELE_VINR = uint16__TELE_VINR
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__COM_STATE)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__STAT_SUPPLY)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_POUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_PIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IOUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VBAT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VINR)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst0ChargerZrType()
    
            currentPos = pos
            (resultInstance.uint8__COM_STATE, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__STAT_SUPPLY, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_POUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_PIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IOUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VBAT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VINR, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 15
    
    class struct_Eps2Inst0_FDIR_CMD_EXEC_STATUS_type:
        def __init__(self, uint8__EPSII_BP_1_GetBatteryInfo_ErrorCode = 0, uint8__EPSII_BP_1_GetDeviceHealthInfo_ErrorCode = 0, uint8__EPSII_BP_1_GetRAWSensors_1_ErrorCode = 0, uint8__EPSII_BP_1_GetRAWSensors_2_ErrorCode = 0, uint8__EPSII_BP_1_GetRAWSensors_3_ErrorCode = 0):
            self.uint8__EPSII_BP_1_GetBatteryInfo_ErrorCode = uint8__EPSII_BP_1_GetBatteryInfo_ErrorCode
            self.uint8__EPSII_BP_1_GetDeviceHealthInfo_ErrorCode = uint8__EPSII_BP_1_GetDeviceHealthInfo_ErrorCode
            self.uint8__EPSII_BP_1_GetRAWSensors_1_ErrorCode = uint8__EPSII_BP_1_GetRAWSensors_1_ErrorCode
            self.uint8__EPSII_BP_1_GetRAWSensors_2_ErrorCode = uint8__EPSII_BP_1_GetRAWSensors_2_ErrorCode
            self.uint8__EPSII_BP_1_GetRAWSensors_3_ErrorCode = uint8__EPSII_BP_1_GetRAWSensors_3_ErrorCode
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__EPSII_BP_1_GetBatteryInfo_ErrorCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__EPSII_BP_1_GetDeviceHealthInfo_ErrorCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__EPSII_BP_1_GetRAWSensors_1_ErrorCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__EPSII_BP_1_GetRAWSensors_2_ErrorCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__EPSII_BP_1_GetRAWSensors_3_ErrorCode)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst0_FDIR_CMD_EXEC_STATUS_type()
    
            currentPos = pos
            (resultInstance.uint8__EPSII_BP_1_GetBatteryInfo_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__EPSII_BP_1_GetDeviceHealthInfo_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__EPSII_BP_1_GetRAWSensors_1_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__EPSII_BP_1_GetRAWSensors_2_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__EPSII_BP_1_GetRAWSensors_3_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 5
    
    class struct_Eps2Inst1BatteryInfoType:
        def __init__(self, uint32__Capacity = 0, uint16__Voltage = 0, int16__Current = 0, int32__Temperature = 0, uint8__bp_mode = 0):
            self.uint32__Capacity = uint32__Capacity
            self.uint16__Voltage = uint16__Voltage
            self.int16__Current = int16__Current
            self.int32__Temperature = int32__Temperature
            self.uint8__bp_mode = uint8__bp_mode
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__Capacity)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Voltage)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Current)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__Temperature)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__bp_mode)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst1BatteryInfoType()
    
            currentPos = pos
            (resultInstance.uint32__Capacity, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Voltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__Temperature, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__bp_mode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 13
    
    class struct_Eps2Inst1DeviceHealthInfoType:
        def __init__(self, int32__ActiveCPU_RunningTime = 0, int32__ActiveCPU_Voltage = 0, int32__ActiveCPU_Temperature = 0, int32__PCB_Temperature_1 = 0, int32__PCB_Temperature_2 = 0, uint8__BALANCER_CHIP_1 = 0, uint8__LT8491_IC_XP = 0, uint8__LT8491_IC_XR = 0, uint8__LT8491_IC_YP = 0, uint8__LT8491_IC_YR = 0, uint8__LT8491_IC_ZP = 0, uint8__LT8491_IC_ZR = 0, uint8__INA_BAT_OUT_1 = 0, uint8__INA_BAT_OUT_2 = 0, uint8__TMP117_U810 = 0, uint8__TMP117_U811 = 0, uint8__GPIO_PCA9538_U2001 = 0, uint8__GPIO_PCA9538_U2002 = 0):
            self.int32__ActiveCPU_RunningTime = int32__ActiveCPU_RunningTime
            self.int32__ActiveCPU_Voltage = int32__ActiveCPU_Voltage
            self.int32__ActiveCPU_Temperature = int32__ActiveCPU_Temperature
            self.int32__PCB_Temperature_1 = int32__PCB_Temperature_1
            self.int32__PCB_Temperature_2 = int32__PCB_Temperature_2
            self.uint8__BALANCER_CHIP_1 = uint8__BALANCER_CHIP_1
            self.uint8__LT8491_IC_XP = uint8__LT8491_IC_XP
            self.uint8__LT8491_IC_XR = uint8__LT8491_IC_XR
            self.uint8__LT8491_IC_YP = uint8__LT8491_IC_YP
            self.uint8__LT8491_IC_YR = uint8__LT8491_IC_YR
            self.uint8__LT8491_IC_ZP = uint8__LT8491_IC_ZP
            self.uint8__LT8491_IC_ZR = uint8__LT8491_IC_ZR
            self.uint8__INA_BAT_OUT_1 = uint8__INA_BAT_OUT_1
            self.uint8__INA_BAT_OUT_2 = uint8__INA_BAT_OUT_2
            self.uint8__TMP117_U810 = uint8__TMP117_U810
            self.uint8__TMP117_U811 = uint8__TMP117_U811
            self.uint8__GPIO_PCA9538_U2001 = uint8__GPIO_PCA9538_U2001
            self.uint8__GPIO_PCA9538_U2002 = uint8__GPIO_PCA9538_U2002
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__ActiveCPU_RunningTime)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__ActiveCPU_Voltage)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__ActiveCPU_Temperature)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__PCB_Temperature_1)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__PCB_Temperature_2)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__BALANCER_CHIP_1)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__LT8491_IC_XP)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__LT8491_IC_XR)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__LT8491_IC_YP)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__LT8491_IC_YR)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__LT8491_IC_ZP)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__LT8491_IC_ZR)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__INA_BAT_OUT_1)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__INA_BAT_OUT_2)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__TMP117_U810)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__TMP117_U811)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__GPIO_PCA9538_U2001)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__GPIO_PCA9538_U2002)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst1DeviceHealthInfoType()
    
            currentPos = pos
            (resultInstance.int32__ActiveCPU_RunningTime, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__ActiveCPU_Voltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__ActiveCPU_Temperature, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__PCB_Temperature_1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__PCB_Temperature_2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__BALANCER_CHIP_1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__LT8491_IC_XP, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__LT8491_IC_XR, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__LT8491_IC_YP, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__LT8491_IC_YR, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__LT8491_IC_ZP, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__LT8491_IC_ZR, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__INA_BAT_OUT_1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__INA_BAT_OUT_2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__TMP117_U810, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__TMP117_U811, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__GPIO_PCA9538_U2001, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__GPIO_PCA9538_U2002, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 33
    
    class struct_Eps2Inst1InaSensors1Type:
        def __init__(self, uint16__Voltage = 0, int16__Current = 0, int16__Energy = 0, int16__Temperature = 0):
            self.uint16__Voltage = uint16__Voltage
            self.int16__Current = int16__Current
            self.int16__Energy = int16__Energy
            self.int16__Temperature = int16__Temperature
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Voltage)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Current)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Energy)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Temperature)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst1InaSensors1Type()
    
            currentPos = pos
            (resultInstance.uint16__Voltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Energy, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Temperature, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 8
    
    class struct_Eps2Inst1InaSensors2Type:
        def __init__(self, uint16__Voltage = 0, int16__Current = 0, int16__Energy = 0, int16__Temperature = 0):
            self.uint16__Voltage = uint16__Voltage
            self.int16__Current = int16__Current
            self.int16__Energy = int16__Energy
            self.int16__Temperature = int16__Temperature
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Voltage)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Current)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Energy)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Temperature)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst1InaSensors2Type()
    
            currentPos = pos
            (resultInstance.uint16__Voltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Energy, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Temperature, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 8
    
    class struct_Eps2Inst1BalancerInfoType:
        def __init__(self, uint16__Voltage = 0, int16__Current = 0, int16__Internal_Temperature = 0):
            self.uint16__Voltage = uint16__Voltage
            self.int16__Current = int16__Current
            self.int16__Internal_Temperature = int16__Internal_Temperature
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Voltage)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Current)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__Internal_Temperature)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst1BalancerInfoType()
    
            currentPos = pos
            (resultInstance.uint16__Voltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__Internal_Temperature, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 6
    
    class struct_Eps2Inst1BalancerStatusType:
        def __init__(self, uint8__COM_STATE = 0, uint8__status_register_0 = 0, uint8__status_register_1 = 0, uint8__status_register_2 = 0, uint8__status_register_3 = 0):
            self.uint8__COM_STATE = uint8__COM_STATE
            self.uint8__status_register_0 = uint8__status_register_0
            self.uint8__status_register_1 = uint8__status_register_1
            self.uint8__status_register_2 = uint8__status_register_2
            self.uint8__status_register_3 = uint8__status_register_3
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__COM_STATE)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__status_register_0)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__status_register_1)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__status_register_2)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__status_register_3)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst1BalancerStatusType()
    
            currentPos = pos
            (resultInstance.uint8__COM_STATE, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__status_register_0, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__status_register_1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__status_register_2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__status_register_3, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 5
    
    class struct_Eps2Inst1BalancerCellsInfoType:
        def __init__(self, uint16__Cell_1 = 0, uint16__Cell_2 = 0, uint16__Cell_3 = 0, uint16__Cell_4 = 0, uint16__Cell_5 = 0, uint16__Cell_6 = 0, uint16__Cell_7 = 0, uint16__Cell_8 = 0):
            self.uint16__Cell_1 = uint16__Cell_1
            self.uint16__Cell_2 = uint16__Cell_2
            self.uint16__Cell_3 = uint16__Cell_3
            self.uint16__Cell_4 = uint16__Cell_4
            self.uint16__Cell_5 = uint16__Cell_5
            self.uint16__Cell_6 = uint16__Cell_6
            self.uint16__Cell_7 = uint16__Cell_7
            self.uint16__Cell_8 = uint16__Cell_8
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cell_1)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cell_2)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cell_3)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cell_4)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cell_5)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cell_6)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cell_7)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__Cell_8)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst1BalancerCellsInfoType()
    
            currentPos = pos
            (resultInstance.uint16__Cell_1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Cell_2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Cell_3, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Cell_4, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Cell_5, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Cell_6, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Cell_7, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__Cell_8, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 16
    
    class struct_Eps2Inst1ChargerXpType:
        def __init__(self, uint8__COM_STATE = 0, uint16__STAT_SUPPLY = 0, uint16__TELE_POUT = 0, uint16__TELE_PIN = 0, uint16__TELE_IOUT = 0, uint16__TELE_IIN = 0, uint16__TELE_VBAT = 0, uint16__TELE_VINR = 0):
            self.uint8__COM_STATE = uint8__COM_STATE
            self.uint16__STAT_SUPPLY = uint16__STAT_SUPPLY
            self.uint16__TELE_POUT = uint16__TELE_POUT
            self.uint16__TELE_PIN = uint16__TELE_PIN
            self.uint16__TELE_IOUT = uint16__TELE_IOUT
            self.uint16__TELE_IIN = uint16__TELE_IIN
            self.uint16__TELE_VBAT = uint16__TELE_VBAT
            self.uint16__TELE_VINR = uint16__TELE_VINR
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__COM_STATE)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__STAT_SUPPLY)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_POUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_PIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IOUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VBAT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VINR)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst1ChargerXpType()
    
            currentPos = pos
            (resultInstance.uint8__COM_STATE, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__STAT_SUPPLY, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_POUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_PIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IOUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VBAT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VINR, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 15
    
    class struct_Eps2Inst1ChargerXrType:
        def __init__(self, uint8__COM_STATE = 0, uint16__STAT_SUPPLY = 0, uint16__TELE_POUT = 0, uint16__TELE_PIN = 0, uint16__TELE_IOUT = 0, uint16__TELE_IIN = 0, uint16__TELE_VBAT = 0, uint16__TELE_VINR = 0):
            self.uint8__COM_STATE = uint8__COM_STATE
            self.uint16__STAT_SUPPLY = uint16__STAT_SUPPLY
            self.uint16__TELE_POUT = uint16__TELE_POUT
            self.uint16__TELE_PIN = uint16__TELE_PIN
            self.uint16__TELE_IOUT = uint16__TELE_IOUT
            self.uint16__TELE_IIN = uint16__TELE_IIN
            self.uint16__TELE_VBAT = uint16__TELE_VBAT
            self.uint16__TELE_VINR = uint16__TELE_VINR
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__COM_STATE)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__STAT_SUPPLY)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_POUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_PIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IOUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VBAT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VINR)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst1ChargerXrType()
    
            currentPos = pos
            (resultInstance.uint8__COM_STATE, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__STAT_SUPPLY, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_POUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_PIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IOUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VBAT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VINR, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 15
    
    class struct_Eps2Inst1ChargerYpType:
        def __init__(self, uint8__COM_STATE = 0, uint16__STAT_SUPPLY = 0, uint16__TELE_POUT = 0, uint16__TELE_PIN = 0, uint16__TELE_IOUT = 0, uint16__TELE_IIN = 0, uint16__TELE_VBAT = 0, uint16__TELE_VINR = 0):
            self.uint8__COM_STATE = uint8__COM_STATE
            self.uint16__STAT_SUPPLY = uint16__STAT_SUPPLY
            self.uint16__TELE_POUT = uint16__TELE_POUT
            self.uint16__TELE_PIN = uint16__TELE_PIN
            self.uint16__TELE_IOUT = uint16__TELE_IOUT
            self.uint16__TELE_IIN = uint16__TELE_IIN
            self.uint16__TELE_VBAT = uint16__TELE_VBAT
            self.uint16__TELE_VINR = uint16__TELE_VINR
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__COM_STATE)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__STAT_SUPPLY)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_POUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_PIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IOUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VBAT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VINR)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst1ChargerYpType()
    
            currentPos = pos
            (resultInstance.uint8__COM_STATE, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__STAT_SUPPLY, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_POUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_PIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IOUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VBAT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VINR, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 15
    
    class struct_Eps2Inst1ChargerYrType:
        def __init__(self, uint8__COM_STATE = 0, uint16__STAT_SUPPLY = 0, uint16__TELE_POUT = 0, uint16__TELE_PIN = 0, uint16__TELE_IOUT = 0, uint16__TELE_IIN = 0, uint16__TELE_VBAT = 0, uint16__TELE_VINR = 0):
            self.uint8__COM_STATE = uint8__COM_STATE
            self.uint16__STAT_SUPPLY = uint16__STAT_SUPPLY
            self.uint16__TELE_POUT = uint16__TELE_POUT
            self.uint16__TELE_PIN = uint16__TELE_PIN
            self.uint16__TELE_IOUT = uint16__TELE_IOUT
            self.uint16__TELE_IIN = uint16__TELE_IIN
            self.uint16__TELE_VBAT = uint16__TELE_VBAT
            self.uint16__TELE_VINR = uint16__TELE_VINR
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__COM_STATE)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__STAT_SUPPLY)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_POUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_PIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IOUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VBAT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VINR)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst1ChargerYrType()
    
            currentPos = pos
            (resultInstance.uint8__COM_STATE, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__STAT_SUPPLY, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_POUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_PIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IOUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VBAT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VINR, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 15
    
    class struct_Eps2Inst1ChargerZpType:
        def __init__(self, uint8__COM_STATE = 0, uint16__STAT_SUPPLY = 0, uint16__TELE_POUT = 0, uint16__TELE_PIN = 0, uint16__TELE_IOUT = 0, uint16__TELE_IIN = 0, uint16__TELE_VBAT = 0, uint16__TELE_VINR = 0):
            self.uint8__COM_STATE = uint8__COM_STATE
            self.uint16__STAT_SUPPLY = uint16__STAT_SUPPLY
            self.uint16__TELE_POUT = uint16__TELE_POUT
            self.uint16__TELE_PIN = uint16__TELE_PIN
            self.uint16__TELE_IOUT = uint16__TELE_IOUT
            self.uint16__TELE_IIN = uint16__TELE_IIN
            self.uint16__TELE_VBAT = uint16__TELE_VBAT
            self.uint16__TELE_VINR = uint16__TELE_VINR
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__COM_STATE)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__STAT_SUPPLY)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_POUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_PIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IOUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VBAT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VINR)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst1ChargerZpType()
    
            currentPos = pos
            (resultInstance.uint8__COM_STATE, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__STAT_SUPPLY, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_POUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_PIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IOUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VBAT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VINR, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 15
    
    class struct_Eps2Inst1ChargerZrType:
        def __init__(self, uint8__COM_STATE = 0, uint16__STAT_SUPPLY = 0, uint16__TELE_POUT = 0, uint16__TELE_PIN = 0, uint16__TELE_IOUT = 0, uint16__TELE_IIN = 0, uint16__TELE_VBAT = 0, uint16__TELE_VINR = 0):
            self.uint8__COM_STATE = uint8__COM_STATE
            self.uint16__STAT_SUPPLY = uint16__STAT_SUPPLY
            self.uint16__TELE_POUT = uint16__TELE_POUT
            self.uint16__TELE_PIN = uint16__TELE_PIN
            self.uint16__TELE_IOUT = uint16__TELE_IOUT
            self.uint16__TELE_IIN = uint16__TELE_IIN
            self.uint16__TELE_VBAT = uint16__TELE_VBAT
            self.uint16__TELE_VINR = uint16__TELE_VINR
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__COM_STATE)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__STAT_SUPPLY)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_POUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_PIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IOUT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_IIN)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VBAT)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__TELE_VINR)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst1ChargerZrType()
    
            currentPos = pos
            (resultInstance.uint8__COM_STATE, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__STAT_SUPPLY, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_POUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_PIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IOUT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_IIN, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VBAT, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__TELE_VINR, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 15
    
    class struct_Eps2Inst1_FDIR_CMD_EXEC_STATUS_type:
        def __init__(self, uint8__EPSII_BP_1_GetBatteryInfo_ErrorCode = 0, uint8__EPSII_BP_1_GetDeviceHealthInfo_ErrorCode = 0, uint8__EPSII_BP_1_GetRAWSensors_1_ErrorCode = 0, uint8__EPSII_BP_1_GetRAWSensors_2_ErrorCode = 0, uint8__EPSII_BP_1_GetRAWSensors_3_ErrorCode = 0):
            self.uint8__EPSII_BP_1_GetBatteryInfo_ErrorCode = uint8__EPSII_BP_1_GetBatteryInfo_ErrorCode
            self.uint8__EPSII_BP_1_GetDeviceHealthInfo_ErrorCode = uint8__EPSII_BP_1_GetDeviceHealthInfo_ErrorCode
            self.uint8__EPSII_BP_1_GetRAWSensors_1_ErrorCode = uint8__EPSII_BP_1_GetRAWSensors_1_ErrorCode
            self.uint8__EPSII_BP_1_GetRAWSensors_2_ErrorCode = uint8__EPSII_BP_1_GetRAWSensors_2_ErrorCode
            self.uint8__EPSII_BP_1_GetRAWSensors_3_ErrorCode = uint8__EPSII_BP_1_GetRAWSensors_3_ErrorCode
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__EPSII_BP_1_GetBatteryInfo_ErrorCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__EPSII_BP_1_GetDeviceHealthInfo_ErrorCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__EPSII_BP_1_GetRAWSensors_1_ErrorCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__EPSII_BP_1_GetRAWSensors_2_ErrorCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__EPSII_BP_1_GetRAWSensors_3_ErrorCode)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps2Inst1_FDIR_CMD_EXEC_STATUS_type()
    
            currentPos = pos
            (resultInstance.uint8__EPSII_BP_1_GetBatteryInfo_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__EPSII_BP_1_GetDeviceHealthInfo_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__EPSII_BP_1_GetRAWSensors_1_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__EPSII_BP_1_GetRAWSensors_2_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__EPSII_BP_1_GetRAWSensors_3_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 5
    
    class struct_Eps3Inst0_UpTimeInSecondsType:
        def __init__(self, uint32__seconds = 0):
            self.uint32__seconds = uint32__seconds
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__seconds)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3Inst0_UpTimeInSecondsType()
    
            currentPos = pos
            (resultInstance.uint32__seconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 4
    
    class struct_Eps3Inst0CommonMeasurementType:
        def __init__(self, uint16__mcu_volt = 0, int32__mcu_temp = 0, uint16__sys_bus_volt = 0):
            self.uint16__mcu_volt = uint16__mcu_volt
            self.int32__mcu_temp = int32__mcu_temp
            self.uint16__sys_bus_volt = uint16__sys_bus_volt
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__mcu_volt)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__mcu_temp)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__sys_bus_volt)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3Inst0CommonMeasurementType()
    
            currentPos = pos
            (resultInstance.uint16__mcu_volt, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__mcu_temp, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__sys_bus_volt, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 8
    
    class struct_Eps3Inst0HIBModeStatusType:
        def __init__(self, uint8__hib_mode_en = 0, uint8__battery_dead = 0, uint8__battery_low = 0, uint8__battery_temp_low = 0):
            self.uint8__hib_mode_en = uint8__hib_mode_en
            self.uint8__battery_dead = uint8__battery_dead
            self.uint8__battery_low = uint8__battery_low
            self.uint8__battery_temp_low = uint8__battery_temp_low
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__hib_mode_en)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__battery_dead)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__battery_low)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__battery_temp_low)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3Inst0HIBModeStatusType()
    
            currentPos = pos
            (resultInstance.uint8__hib_mode_en, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__battery_dead, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__battery_low, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__battery_temp_low, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 4
    
    class struct_Eps3Inst0MeasurementsType:
        def __init__(self, uint16__v_batt = 0, int16__i_batt = 0, uint8__soc_batt = 0, uint16__v_batt_cell_1 = 0, uint16__v_batt_cell_2 = 0, uint16__v_batt_cell_3 = 0, uint16__v_batt_cell_4 = 0, int32__t_batt = 0, int32__p_heater_1 = 0, int32__p_heater_2 = 0, uint16__v_buss_7_5V = 0, uint16__v_buss_3_3V = 0):
            self.uint16__v_batt = uint16__v_batt
            self.int16__i_batt = int16__i_batt
            self.uint8__soc_batt = uint8__soc_batt
            self.uint16__v_batt_cell_1 = uint16__v_batt_cell_1
            self.uint16__v_batt_cell_2 = uint16__v_batt_cell_2
            self.uint16__v_batt_cell_3 = uint16__v_batt_cell_3
            self.uint16__v_batt_cell_4 = uint16__v_batt_cell_4
            self.int32__t_batt = int32__t_batt
            self.int32__p_heater_1 = int32__p_heater_1
            self.int32__p_heater_2 = int32__p_heater_2
            self.uint16__v_buss_7_5V = uint16__v_buss_7_5V
            self.uint16__v_buss_3_3V = uint16__v_buss_3_3V
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__v_batt)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__i_batt)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__soc_batt)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__v_batt_cell_1)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__v_batt_cell_2)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__v_batt_cell_3)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__v_batt_cell_4)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__t_batt)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__p_heater_1)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__p_heater_2)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__v_buss_7_5V)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__v_buss_3_3V)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3Inst0MeasurementsType()
    
            currentPos = pos
            (resultInstance.uint16__v_batt, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__i_batt, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__soc_batt, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__v_batt_cell_1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__v_batt_cell_2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__v_batt_cell_3, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__v_batt_cell_4, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__t_batt, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__p_heater_1, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__p_heater_2, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__v_buss_7_5V, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__v_buss_3_3V, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 29
    
    class struct_Eps3Inst0DischargeStateType:
        def __init__(self, uint8__discharge = 0, uint8__battery_low = 0, uint8__battery_dead = 0, uint8__battery_ocp_charge = 0, uint8__battery_ocp_discharge = 0, uint8__discharge_switch_over_heat_prot = 0, int32__discharge_switch_over_heat_temp = 0, uint8__battery_overheat = 0, int32__t_batt = 0, uint8__v_buss_7_5v_error_flag = 0, uint8__charge_mode_en = 0, uint8__charging_current_flow = 0, uint8__charging_voltage_ok = 0):
            self.uint8__discharge = uint8__discharge
            self.uint8__battery_low = uint8__battery_low
            self.uint8__battery_dead = uint8__battery_dead
            self.uint8__battery_ocp_charge = uint8__battery_ocp_charge
            self.uint8__battery_ocp_discharge = uint8__battery_ocp_discharge
            self.uint8__discharge_switch_over_heat_prot = uint8__discharge_switch_over_heat_prot
            self.int32__discharge_switch_over_heat_temp = int32__discharge_switch_over_heat_temp
            self.uint8__battery_overheat = uint8__battery_overheat
            self.int32__t_batt = int32__t_batt
            self.uint8__v_buss_7_5v_error_flag = uint8__v_buss_7_5v_error_flag
            self.uint8__charge_mode_en = uint8__charge_mode_en
            self.uint8__charging_current_flow = uint8__charging_current_flow
            self.uint8__charging_voltage_ok = uint8__charging_voltage_ok
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__discharge)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__battery_low)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__battery_dead)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__battery_ocp_charge)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__battery_ocp_discharge)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__discharge_switch_over_heat_prot)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__discharge_switch_over_heat_temp)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__battery_overheat)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__t_batt)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__v_buss_7_5v_error_flag)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__charge_mode_en)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__charging_current_flow)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__charging_voltage_ok)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3Inst0DischargeStateType()
    
            currentPos = pos
            (resultInstance.uint8__discharge, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__battery_low, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__battery_dead, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__battery_ocp_charge, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__battery_ocp_discharge, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__discharge_switch_over_heat_prot, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__discharge_switch_over_heat_temp, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__battery_overheat, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__t_batt, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__v_buss_7_5v_error_flag, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__charge_mode_en, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__charging_current_flow, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__charging_voltage_ok, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 19
    
    class struct_Eps3Inst0ChargeOnStatusType:
        def __init__(self, uint8__battery_charging_on = 0, uint8__charging_voltage_ok = 0, uint8__battery_dead = 0, uint8__battery_over_voltage_prot = 0, uint8__battery_slow_charging = 0, uint8__charging_current_flow = 0, uint16__charge_current = 0, uint8__valid_input_voltage = 0):
            self.uint8__battery_charging_on = uint8__battery_charging_on
            self.uint8__charging_voltage_ok = uint8__charging_voltage_ok
            self.uint8__battery_dead = uint8__battery_dead
            self.uint8__battery_over_voltage_prot = uint8__battery_over_voltage_prot
            self.uint8__battery_slow_charging = uint8__battery_slow_charging
            self.uint8__charging_current_flow = uint8__charging_current_flow
            self.uint16__charge_current = uint16__charge_current
            self.uint8__valid_input_voltage = uint8__valid_input_voltage
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__battery_charging_on)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__charging_voltage_ok)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__battery_dead)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__battery_over_voltage_prot)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__battery_slow_charging)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__charging_current_flow)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__charge_current)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__valid_input_voltage)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3Inst0ChargeOnStatusType()
    
            currentPos = pos
            (resultInstance.uint8__battery_charging_on, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__charging_voltage_ok, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__battery_dead, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__battery_over_voltage_prot, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__battery_slow_charging, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__charging_current_flow, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__charge_current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__valid_input_voltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 9
    
    class struct_Eps3Inst0BalancersStatusType:
        def __init__(self, uint8__balancer_on = 0, uint8__balancer_voltage_ok = 0, uint8__charging_current_flow = 0):
            self.uint8__balancer_on = uint8__balancer_on
            self.uint8__balancer_voltage_ok = uint8__balancer_voltage_ok
            self.uint8__charging_current_flow = uint8__charging_current_flow
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__balancer_on)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__balancer_voltage_ok)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__charging_current_flow)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3Inst0BalancersStatusType()
    
            currentPos = pos
            (resultInstance.uint8__balancer_on, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__balancer_voltage_ok, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__charging_current_flow, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 3
    
    class struct_Eps3Inst0BatteryCellsStatusType:
        def __init__(self, uint8__balance_cell_1_en = 0, uint8__balance_cell_2_en = 0, uint8__balance_cell_3_en = 0, uint8__balance_cell_4_en = 0):
            self.uint8__balance_cell_1_en = uint8__balance_cell_1_en
            self.uint8__balance_cell_2_en = uint8__balance_cell_2_en
            self.uint8__balance_cell_3_en = uint8__balance_cell_3_en
            self.uint8__balance_cell_4_en = uint8__balance_cell_4_en
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__balance_cell_1_en)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__balance_cell_2_en)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__balance_cell_3_en)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__balance_cell_4_en)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3Inst0BatteryCellsStatusType()
    
            currentPos = pos
            (resultInstance.uint8__balance_cell_1_en, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__balance_cell_2_en, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__balance_cell_3_en, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__balance_cell_4_en, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 4
    
    class struct_Eps3Inst0HeatersStatusType:
        def __init__(self, uint8__heater_en = 0, uint8__heater_under_5_deg_c = 0, uint8__battery_dead = 0, uint8__battery_alert = 0):
            self.uint8__heater_en = uint8__heater_en
            self.uint8__heater_under_5_deg_c = uint8__heater_under_5_deg_c
            self.uint8__battery_dead = uint8__battery_dead
            self.uint8__battery_alert = uint8__battery_alert
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__heater_en)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__heater_under_5_deg_c)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__battery_dead)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__battery_alert)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3Inst0HeatersStatusType()
    
            currentPos = pos
            (resultInstance.uint8__heater_en, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__heater_under_5_deg_c, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__battery_dead, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__battery_alert, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 4
    
    class struct_Eps3Inst0_FDIR_CMD_EXEC_STATUS_type:
        def __init__(self, uint8__eps_iii_batt_pack_get_telemetry_ErrorCode = 0):
            self.uint8__eps_iii_batt_pack_get_telemetry_ErrorCode = uint8__eps_iii_batt_pack_get_telemetry_ErrorCode
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__eps_iii_batt_pack_get_telemetry_ErrorCode)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3Inst0_FDIR_CMD_EXEC_STATUS_type()
    
            currentPos = pos
            (resultInstance.uint8__eps_iii_batt_pack_get_telemetry_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_VoltAmps:
        def __init__(self, uint16__voltage = 0, int16__current = 0):
            self.uint16__voltage = uint16__voltage
            self.int16__current = int16__current
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__voltage)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__current)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_VoltAmps()
    
            currentPos = pos
            (resultInstance.uint16__voltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 4
    
    class struct_VoltAllAmps:
        def __init__(self, uint16__ch_voltage = 0, int16__in_current = 0, int16__out_current = 0):
            self.uint16__ch_voltage = uint16__ch_voltage
            self.int16__in_current = int16__in_current
            self.int16__out_current = int16__out_current
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__ch_voltage)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__in_current)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__out_current)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_VoltAllAmps()
    
            currentPos = pos
            (resultInstance.uint16__ch_voltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__in_current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__out_current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 6
    
    class struct_MpptState_str:
        def __init__(self, uint16__status = 0, uint16__faults = 0, uint16__mode = 0):
            self.uint16__status = uint16__status
            self.uint16__faults = uint16__faults
            self.uint16__mode = uint16__mode
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__status)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__faults)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__mode)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_MpptState_str()
    
            currentPos = pos
            (resultInstance.uint16__status, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__faults, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__mode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 6
    
    class struct_ReadEnDftStatus:
        def __init__(self, uint8__status = 0):
            self.uint8__status = uint8__status
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__status)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_ReadEnDftStatus()
    
            currentPos = pos
            (resultInstance.uint8__status, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_OnOffStatus:
        def __init__(self, uint8__status = 0):
            self.uint8__status = uint8__status
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__status)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_OnOffStatus()
    
            currentPos = pos
            (resultInstance.uint8__status, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_ReadLvlState:
        def __init__(self, uint8__status = 0):
            self.uint8__status = uint8__status
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__status)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_ReadLvlState()
    
            currentPos = pos
            (resultInstance.uint8__status, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_Eps3_PDM_A_Inst0_UpTimeInSecondsType:
        def __init__(self, uint32__seconds = 0):
            self.uint32__seconds = uint32__seconds
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__seconds)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_PDM_A_Inst0_UpTimeInSecondsType()
    
            currentPos = pos
            (resultInstance.uint32__seconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 4
    
    class struct_Eps3_PDM_A_Inst0_CommonMesurementsType:
        def __init__(self, uint16__mcu_volt = 0, int32__mcu_temp = 0, uint16__sys_bus_volt = 0):
            self.uint16__mcu_volt = uint16__mcu_volt
            self.int32__mcu_temp = int32__mcu_temp
            self.uint16__sys_bus_volt = uint16__sys_bus_volt
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__mcu_volt)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__mcu_temp)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__sys_bus_volt)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_PDM_A_Inst0_CommonMesurementsType()
    
            currentPos = pos
            (resultInstance.uint16__mcu_volt, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__mcu_temp, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__sys_bus_volt, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 8
    
    class struct_Eps3_PDM_A_Inst0_HibModeType:
        def __init__(self, s__status = None):
            self.s__status = s__status
    
        def serialize(self):
            result = bytearray()
    
            result += self.s__status.serialize()
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_PDM_A_Inst0_HibModeType()
    
            currentPos = pos
            (resultInstance.s__status, bytesProcessed) = dc_parser.struct_OnOffStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_Eps3_PDM_A_Inst0_OutputsStatusType:
        def __init__(self, s__en_ext_sys_bus = None, s__en_3v3_bus_in = None, s__en_3v3_bus_out = None, s__en_5v_bus_in = None, s__en_5v_bus_out = None, s__en_12v_bus_in = None, s__en_12v_bus_out = None):
            self.s__en_ext_sys_bus = s__en_ext_sys_bus
            self.s__en_3v3_bus_in = s__en_3v3_bus_in
            self.s__en_3v3_bus_out = s__en_3v3_bus_out
            self.s__en_5v_bus_in = s__en_5v_bus_in
            self.s__en_5v_bus_out = s__en_5v_bus_out
            self.s__en_12v_bus_in = s__en_12v_bus_in
            self.s__en_12v_bus_out = s__en_12v_bus_out
    
        def serialize(self):
            result = bytearray()
    
            result += self.s__en_ext_sys_bus.serialize()
            result += self.s__en_3v3_bus_in.serialize()
            result += self.s__en_3v3_bus_out.serialize()
            result += self.s__en_5v_bus_in.serialize()
            result += self.s__en_5v_bus_out.serialize()
            result += self.s__en_12v_bus_in.serialize()
            result += self.s__en_12v_bus_out.serialize()
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_PDM_A_Inst0_OutputsStatusType()
    
            currentPos = pos
            (resultInstance.s__en_ext_sys_bus, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__en_3v3_bus_in, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__en_3v3_bus_out, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__en_5v_bus_in, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__en_5v_bus_out, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__en_12v_bus_in, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__en_12v_bus_out, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 7
    
    class struct_Eps3_PDM_A_Inst0_FaultsStatusType:
        def __init__(self, s__flt_ext_sys_bus = None, s__flt_in_3v3_bus = None, s__flt_out_3v3_bus = None, s__flt_in_5v_bus = None, s__flt_out_5v_bus = None, s__flt_in_12v_bus = None, s__flt_out_12v_bus = None):
            self.s__flt_ext_sys_bus = s__flt_ext_sys_bus
            self.s__flt_in_3v3_bus = s__flt_in_3v3_bus
            self.s__flt_out_3v3_bus = s__flt_out_3v3_bus
            self.s__flt_in_5v_bus = s__flt_in_5v_bus
            self.s__flt_out_5v_bus = s__flt_out_5v_bus
            self.s__flt_in_12v_bus = s__flt_in_12v_bus
            self.s__flt_out_12v_bus = s__flt_out_12v_bus
    
        def serialize(self):
            result = bytearray()
    
            result += self.s__flt_ext_sys_bus.serialize()
            result += self.s__flt_in_3v3_bus.serialize()
            result += self.s__flt_out_3v3_bus.serialize()
            result += self.s__flt_in_5v_bus.serialize()
            result += self.s__flt_out_5v_bus.serialize()
            result += self.s__flt_in_12v_bus.serialize()
            result += self.s__flt_out_12v_bus.serialize()
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_PDM_A_Inst0_FaultsStatusType()
    
            currentPos = pos
            (resultInstance.s__flt_ext_sys_bus, bytesProcessed) = dc_parser.struct_OnOffStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__flt_in_3v3_bus, bytesProcessed) = dc_parser.struct_OnOffStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__flt_out_3v3_bus, bytesProcessed) = dc_parser.struct_OnOffStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__flt_in_5v_bus, bytesProcessed) = dc_parser.struct_OnOffStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__flt_out_5v_bus, bytesProcessed) = dc_parser.struct_OnOffStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__flt_in_12v_bus, bytesProcessed) = dc_parser.struct_OnOffStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__flt_out_12v_bus, bytesProcessed) = dc_parser.struct_OnOffStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 7
    
    class struct_Eps3_PDM_A_Inst0_VoltAmpsMeasurementsType:
        def __init__(self, s__system_bus = None, s__ext_sys_bus = None, s__bus_3v3 = None, s__bus_5v = None, s__bus_12v = None):
            self.s__system_bus = s__system_bus
            self.s__ext_sys_bus = s__ext_sys_bus
            self.s__bus_3v3 = s__bus_3v3
            self.s__bus_5v = s__bus_5v
            self.s__bus_12v = s__bus_12v
    
        def serialize(self):
            result = bytearray()
    
            result += self.s__system_bus.serialize()
            result += self.s__ext_sys_bus.serialize()
            result += self.s__bus_3v3.serialize()
            result += self.s__bus_5v.serialize()
            result += self.s__bus_12v.serialize()
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_PDM_A_Inst0_VoltAmpsMeasurementsType()
    
            currentPos = pos
            (resultInstance.s__system_bus, bytesProcessed) = dc_parser.struct_VoltAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__ext_sys_bus, bytesProcessed) = dc_parser.struct_VoltAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__bus_3v3, bytesProcessed) = dc_parser.struct_VoltAllAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__bus_5v, bytesProcessed) = dc_parser.struct_VoltAllAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__bus_12v, bytesProcessed) = dc_parser.struct_VoltAllAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 26
    
    class struct_Eps3_PDM_A_Inst0_FDIR_CMD_EXEC_STATUS_type:
        def __init__(self, uint8__eps_iii_pdm_a_get_telemetry_ErrorCode = 0, uint8__eps_iii_pdm_a_low_volt_control_ErrorCode = 0, uint8__eps_iii_pdm_a_external_system_bus_control_ErrorCode = 0):
            self.uint8__eps_iii_pdm_a_get_telemetry_ErrorCode = uint8__eps_iii_pdm_a_get_telemetry_ErrorCode
            self.uint8__eps_iii_pdm_a_low_volt_control_ErrorCode = uint8__eps_iii_pdm_a_low_volt_control_ErrorCode
            self.uint8__eps_iii_pdm_a_external_system_bus_control_ErrorCode = uint8__eps_iii_pdm_a_external_system_bus_control_ErrorCode
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__eps_iii_pdm_a_get_telemetry_ErrorCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__eps_iii_pdm_a_low_volt_control_ErrorCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__eps_iii_pdm_a_external_system_bus_control_ErrorCode)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_PDM_A_Inst0_FDIR_CMD_EXEC_STATUS_type()
    
            currentPos = pos
            (resultInstance.uint8__eps_iii_pdm_a_get_telemetry_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__eps_iii_pdm_a_low_volt_control_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__eps_iii_pdm_a_external_system_bus_control_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 3
    
    class struct_Eps3_PDM_B_Inst0_FDIR_CMD_EXEC_STATUS_type:
        def __init__(self, uint8__eps_iii_pdm_b_get_telemetry_ErrorCode = 0, uint8__eps_iii_pdm_b_a_b_control_ErrorCode = 0):
            self.uint8__eps_iii_pdm_b_get_telemetry_ErrorCode = uint8__eps_iii_pdm_b_get_telemetry_ErrorCode
            self.uint8__eps_iii_pdm_b_a_b_control_ErrorCode = uint8__eps_iii_pdm_b_a_b_control_ErrorCode
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__eps_iii_pdm_b_get_telemetry_ErrorCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__eps_iii_pdm_b_a_b_control_ErrorCode)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_PDM_B_Inst0_FDIR_CMD_EXEC_STATUS_type()
    
            currentPos = pos
            (resultInstance.uint8__eps_iii_pdm_b_get_telemetry_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__eps_iii_pdm_b_a_b_control_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 2
    
    class struct_Eps3_PDM_B_Inst0_UpTimeInSecondsType:
        def __init__(self, uint32__seconds = 0):
            self.uint32__seconds = uint32__seconds
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__seconds)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_PDM_B_Inst0_UpTimeInSecondsType()
    
            currentPos = pos
            (resultInstance.uint32__seconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 4
    
    class struct_Eps3_PDM_B_Inst0_CommonMeasurementType:
        def __init__(self, uint16__mcu_volt = 0, int32__mcu_temp = 0, uint16__sys_bus_volt = 0):
            self.uint16__mcu_volt = uint16__mcu_volt
            self.int32__mcu_temp = int32__mcu_temp
            self.uint16__sys_bus_volt = uint16__sys_bus_volt
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__mcu_volt)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__mcu_temp)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__sys_bus_volt)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_PDM_B_Inst0_CommonMeasurementType()
    
            currentPos = pos
            (resultInstance.uint16__mcu_volt, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__mcu_temp, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__sys_bus_volt, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 8
    
    class struct_Eps3_PDM_B_Inst0_hib_mode_Type:
        def __init__(self, s__status = None):
            self.s__status = s__status
    
        def serialize(self):
            result = bytearray()
    
            result += self.s__status.serialize()
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_PDM_B_Inst0_hib_mode_Type()
    
            currentPos = pos
            (resultInstance.s__status, bytesProcessed) = dc_parser.struct_OnOffStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_Eps3_PDM_B_Inst0_OutputsStatus_type:
        def __init__(self, s__en_a_in_bus = None, s__en_a_out_bus = None, s__en_b_in_bus = None, s__en_b_out_bus = None):
            self.s__en_a_in_bus = s__en_a_in_bus
            self.s__en_a_out_bus = s__en_a_out_bus
            self.s__en_b_in_bus = s__en_b_in_bus
            self.s__en_b_out_bus = s__en_b_out_bus
    
        def serialize(self):
            result = bytearray()
    
            result += self.s__en_a_in_bus.serialize()
            result += self.s__en_a_out_bus.serialize()
            result += self.s__en_b_in_bus.serialize()
            result += self.s__en_b_out_bus.serialize()
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_PDM_B_Inst0_OutputsStatus_type()
    
            currentPos = pos
            (resultInstance.s__en_a_in_bus, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__en_a_out_bus, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__en_b_in_bus, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__en_b_out_bus, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 4
    
    class struct_Eps3_PDM_B_Inst0_ChannelFlagState_type:
        def __init__(self, s__A_input_current_state = None, s__A_output_current_state = None, s__A_input_voltage_state = None, s__A_output_voltage_state = None, s__B_input_current_state = None, s__B_output_current_state = None, s__B_input_voltage_state = None, s__B_output_voltage_state = None):
            self.s__A_input_current_state = s__A_input_current_state
            self.s__A_output_current_state = s__A_output_current_state
            self.s__A_input_voltage_state = s__A_input_voltage_state
            self.s__A_output_voltage_state = s__A_output_voltage_state
            self.s__B_input_current_state = s__B_input_current_state
            self.s__B_output_current_state = s__B_output_current_state
            self.s__B_input_voltage_state = s__B_input_voltage_state
            self.s__B_output_voltage_state = s__B_output_voltage_state
    
        def serialize(self):
            result = bytearray()
    
            result += self.s__A_input_current_state.serialize()
            result += self.s__A_output_current_state.serialize()
            result += self.s__A_input_voltage_state.serialize()
            result += self.s__A_output_voltage_state.serialize()
            result += self.s__B_input_current_state.serialize()
            result += self.s__B_output_current_state.serialize()
            result += self.s__B_input_voltage_state.serialize()
            result += self.s__B_output_voltage_state.serialize()
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_PDM_B_Inst0_ChannelFlagState_type()
    
            currentPos = pos
            (resultInstance.s__A_input_current_state, bytesProcessed) = dc_parser.struct_OnOffStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__A_output_current_state, bytesProcessed) = dc_parser.struct_OnOffStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__A_input_voltage_state, bytesProcessed) = dc_parser.struct_OnOffStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__A_output_voltage_state, bytesProcessed) = dc_parser.struct_OnOffStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__B_input_current_state, bytesProcessed) = dc_parser.struct_OnOffStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__B_output_current_state, bytesProcessed) = dc_parser.struct_OnOffStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__B_input_voltage_state, bytesProcessed) = dc_parser.struct_OnOffStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__B_output_voltage_state, bytesProcessed) = dc_parser.struct_OnOffStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 8
    
    class struct_Eps3_PDM_B_Inst0_Temps_type:
        def __init__(self, int32__temp_bus_a = 0, int32__temp_bus_b = 0):
            self.int32__temp_bus_a = int32__temp_bus_a
            self.int32__temp_bus_b = int32__temp_bus_b
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__temp_bus_a)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__temp_bus_b)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_PDM_B_Inst0_Temps_type()
    
            currentPos = pos
            (resultInstance.int32__temp_bus_a, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__temp_bus_b, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 8
    
    class struct_Eps3_PDM_B_Inst0_VoltAmpsMeasurements_type:
        def __init__(self, s__system_bus = None, s__bus_a = None, s__bus_b = None):
            self.s__system_bus = s__system_bus
            self.s__bus_a = s__bus_a
            self.s__bus_b = s__bus_b
    
        def serialize(self):
            result = bytearray()
    
            result += self.s__system_bus.serialize()
            result += self.s__bus_a.serialize()
            result += self.s__bus_b.serialize()
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_PDM_B_Inst0_VoltAmpsMeasurements_type()
    
            currentPos = pos
            (resultInstance.s__system_bus, bytesProcessed) = dc_parser.struct_VoltAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__bus_a, bytesProcessed) = dc_parser.struct_VoltAllAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__bus_b, bytesProcessed) = dc_parser.struct_VoltAllAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 16
    
    class struct_Eps3_EXPANDER_Inst0_FDIR_CMD_EXEC_STATUS_type:
        def __init__(self, uint8__eps_iii_expander_get_telemetry_ErrorCode = 0, uint8__eps_iii_expander_h1_channels_control_ErrorCode = 0, uint8__eps_iii_expander_gpio_control_ErrorCode = 0, uint8__eps_iii_expander_interconnect_control_ErrorCode = 0, uint8__eps_iii_expander_release_control_ErrorCode = 0, uint8__eps_iii_expander_release_5v_ErrorCode = 0):
            self.uint8__eps_iii_expander_get_telemetry_ErrorCode = uint8__eps_iii_expander_get_telemetry_ErrorCode
            self.uint8__eps_iii_expander_h1_channels_control_ErrorCode = uint8__eps_iii_expander_h1_channels_control_ErrorCode
            self.uint8__eps_iii_expander_gpio_control_ErrorCode = uint8__eps_iii_expander_gpio_control_ErrorCode
            self.uint8__eps_iii_expander_interconnect_control_ErrorCode = uint8__eps_iii_expander_interconnect_control_ErrorCode
            self.uint8__eps_iii_expander_release_control_ErrorCode = uint8__eps_iii_expander_release_control_ErrorCode
            self.uint8__eps_iii_expander_release_5v_ErrorCode = uint8__eps_iii_expander_release_5v_ErrorCode
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__eps_iii_expander_get_telemetry_ErrorCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__eps_iii_expander_h1_channels_control_ErrorCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__eps_iii_expander_gpio_control_ErrorCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__eps_iii_expander_interconnect_control_ErrorCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__eps_iii_expander_release_control_ErrorCode)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__eps_iii_expander_release_5v_ErrorCode)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_EXPANDER_Inst0_FDIR_CMD_EXEC_STATUS_type()
    
            currentPos = pos
            (resultInstance.uint8__eps_iii_expander_get_telemetry_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__eps_iii_expander_h1_channels_control_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__eps_iii_expander_gpio_control_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__eps_iii_expander_interconnect_control_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__eps_iii_expander_release_control_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__eps_iii_expander_release_5v_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 6
    
    class struct_Eps3_EXPANDER_Inst0_UpTimeInSecondsType:
        def __init__(self, uint32__seconds = 0):
            self.uint32__seconds = uint32__seconds
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__seconds)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_EXPANDER_Inst0_UpTimeInSecondsType()
    
            currentPos = pos
            (resultInstance.uint32__seconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 4
    
    class struct_Eps3_EXPANDER_Inst0_CommonMeasurementType:
        def __init__(self, uint16__mcu_volt = 0, int32__mcu_temp = 0, uint16__sys_bus_volt = 0):
            self.uint16__mcu_volt = uint16__mcu_volt
            self.int32__mcu_temp = int32__mcu_temp
            self.uint16__sys_bus_volt = uint16__sys_bus_volt
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__mcu_volt)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__mcu_temp)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__sys_bus_volt)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_EXPANDER_Inst0_CommonMeasurementType()
    
            currentPos = pos
            (resultInstance.uint16__mcu_volt, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__mcu_temp, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__sys_bus_volt, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 8
    
    class struct_Eps3_EXPANDER_Inst0_DigitalOutputsType:
        def __init__(self, s__lv_h1_47_48 = None, s__hv_h1_47_48 = None, s__lv_h1_49_50 = None, s__hv_h1_49_50 = None, s__lv_h1_51_52 = None, s__hv_h1_51_52 = None, s__interconnect_battery = None, s__interconnect_3v3 = None, s__interconnect_5v = None, s__interconnect_12v = None, s__general_output_1 = None, s__general_output_2 = None, s__general_output_3 = None, s__general_output_4 = None, s__general_output_5 = None, s__general_output_6 = None, s__general_output_7 = None, s__general_output_8 = None, s__release_1 = None, s__release_2 = None, s__release_3 = None, s__release_4 = None, s__release_a1 = None, s__release_b1 = None, s__release_a2 = None, s__release_b2 = None, s__release_a3 = None, s__release_b3 = None, s__release_a4 = None, s__release_b4 = None):
            self.s__lv_h1_47_48 = s__lv_h1_47_48
            self.s__hv_h1_47_48 = s__hv_h1_47_48
            self.s__lv_h1_49_50 = s__lv_h1_49_50
            self.s__hv_h1_49_50 = s__hv_h1_49_50
            self.s__lv_h1_51_52 = s__lv_h1_51_52
            self.s__hv_h1_51_52 = s__hv_h1_51_52
            self.s__interconnect_battery = s__interconnect_battery
            self.s__interconnect_3v3 = s__interconnect_3v3
            self.s__interconnect_5v = s__interconnect_5v
            self.s__interconnect_12v = s__interconnect_12v
            self.s__general_output_1 = s__general_output_1
            self.s__general_output_2 = s__general_output_2
            self.s__general_output_3 = s__general_output_3
            self.s__general_output_4 = s__general_output_4
            self.s__general_output_5 = s__general_output_5
            self.s__general_output_6 = s__general_output_6
            self.s__general_output_7 = s__general_output_7
            self.s__general_output_8 = s__general_output_8
            self.s__release_1 = s__release_1
            self.s__release_2 = s__release_2
            self.s__release_3 = s__release_3
            self.s__release_4 = s__release_4
            self.s__release_a1 = s__release_a1
            self.s__release_b1 = s__release_b1
            self.s__release_a2 = s__release_a2
            self.s__release_b2 = s__release_b2
            self.s__release_a3 = s__release_a3
            self.s__release_b3 = s__release_b3
            self.s__release_a4 = s__release_a4
            self.s__release_b4 = s__release_b4
    
        def serialize(self):
            result = bytearray()
    
            result += self.s__lv_h1_47_48.serialize()
            result += self.s__hv_h1_47_48.serialize()
            result += self.s__lv_h1_49_50.serialize()
            result += self.s__hv_h1_49_50.serialize()
            result += self.s__lv_h1_51_52.serialize()
            result += self.s__hv_h1_51_52.serialize()
            result += self.s__interconnect_battery.serialize()
            result += self.s__interconnect_3v3.serialize()
            result += self.s__interconnect_5v.serialize()
            result += self.s__interconnect_12v.serialize()
            result += self.s__general_output_1.serialize()
            result += self.s__general_output_2.serialize()
            result += self.s__general_output_3.serialize()
            result += self.s__general_output_4.serialize()
            result += self.s__general_output_5.serialize()
            result += self.s__general_output_6.serialize()
            result += self.s__general_output_7.serialize()
            result += self.s__general_output_8.serialize()
            result += self.s__release_1.serialize()
            result += self.s__release_2.serialize()
            result += self.s__release_3.serialize()
            result += self.s__release_4.serialize()
            result += self.s__release_a1.serialize()
            result += self.s__release_b1.serialize()
            result += self.s__release_a2.serialize()
            result += self.s__release_b2.serialize()
            result += self.s__release_a3.serialize()
            result += self.s__release_b3.serialize()
            result += self.s__release_a4.serialize()
            result += self.s__release_b4.serialize()
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_EXPANDER_Inst0_DigitalOutputsType()
    
            currentPos = pos
            (resultInstance.s__lv_h1_47_48, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__hv_h1_47_48, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__lv_h1_49_50, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__hv_h1_49_50, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__lv_h1_51_52, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__hv_h1_51_52, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__interconnect_battery, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__interconnect_3v3, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__interconnect_5v, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__interconnect_12v, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__general_output_1, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__general_output_2, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__general_output_3, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__general_output_4, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__general_output_5, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__general_output_6, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__general_output_7, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__general_output_8, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__release_1, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__release_2, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__release_3, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__release_4, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__release_a1, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__release_b1, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__release_a2, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__release_b2, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__release_a3, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__release_b3, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__release_a4, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__release_b4, bytesProcessed) = dc_parser.struct_ReadEnDftStatus.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 30
    
    class struct_Eps3_EXPANDER_Inst0_GeneralInputType:
        def __init__(self, s__general_input_1 = None, s__general_input_2 = None, s__general_input_3 = None, s__general_input_4 = None, s__general_input_5 = None, s__general_input_6 = None, s__general_input_7 = None, s__general_input_8 = None):
            self.s__general_input_1 = s__general_input_1
            self.s__general_input_2 = s__general_input_2
            self.s__general_input_3 = s__general_input_3
            self.s__general_input_4 = s__general_input_4
            self.s__general_input_5 = s__general_input_5
            self.s__general_input_6 = s__general_input_6
            self.s__general_input_7 = s__general_input_7
            self.s__general_input_8 = s__general_input_8
    
        def serialize(self):
            result = bytearray()
    
            result += self.s__general_input_1.serialize()
            result += self.s__general_input_2.serialize()
            result += self.s__general_input_3.serialize()
            result += self.s__general_input_4.serialize()
            result += self.s__general_input_5.serialize()
            result += self.s__general_input_6.serialize()
            result += self.s__general_input_7.serialize()
            result += self.s__general_input_8.serialize()
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_EXPANDER_Inst0_GeneralInputType()
    
            currentPos = pos
            (resultInstance.s__general_input_1, bytesProcessed) = dc_parser.struct_ReadLvlState.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__general_input_2, bytesProcessed) = dc_parser.struct_ReadLvlState.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__general_input_3, bytesProcessed) = dc_parser.struct_ReadLvlState.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__general_input_4, bytesProcessed) = dc_parser.struct_ReadLvlState.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__general_input_5, bytesProcessed) = dc_parser.struct_ReadLvlState.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__general_input_6, bytesProcessed) = dc_parser.struct_ReadLvlState.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__general_input_7, bytesProcessed) = dc_parser.struct_ReadLvlState.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__general_input_8, bytesProcessed) = dc_parser.struct_ReadLvlState.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 8
    
    class struct_Eps3_EXPANDER_Inst0_FeedbackType:
        def __init__(self, s__feedback_1_1 = None, s__feedback_1_2 = None, s__feedback_2_1 = None, s__feedback_2_2 = None, s__feedback_3_1 = None, s__feedback_3_2 = None, s__feedback_4_1 = None, s__feedback_4_2 = None):
            self.s__feedback_1_1 = s__feedback_1_1
            self.s__feedback_1_2 = s__feedback_1_2
            self.s__feedback_2_1 = s__feedback_2_1
            self.s__feedback_2_2 = s__feedback_2_2
            self.s__feedback_3_1 = s__feedback_3_1
            self.s__feedback_3_2 = s__feedback_3_2
            self.s__feedback_4_1 = s__feedback_4_1
            self.s__feedback_4_2 = s__feedback_4_2
    
        def serialize(self):
            result = bytearray()
    
            result += self.s__feedback_1_1.serialize()
            result += self.s__feedback_1_2.serialize()
            result += self.s__feedback_2_1.serialize()
            result += self.s__feedback_2_2.serialize()
            result += self.s__feedback_3_1.serialize()
            result += self.s__feedback_3_2.serialize()
            result += self.s__feedback_4_1.serialize()
            result += self.s__feedback_4_2.serialize()
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_EXPANDER_Inst0_FeedbackType()
    
            currentPos = pos
            (resultInstance.s__feedback_1_1, bytesProcessed) = dc_parser.struct_ReadLvlState.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__feedback_1_2, bytesProcessed) = dc_parser.struct_ReadLvlState.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__feedback_2_1, bytesProcessed) = dc_parser.struct_ReadLvlState.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__feedback_2_2, bytesProcessed) = dc_parser.struct_ReadLvlState.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__feedback_3_1, bytesProcessed) = dc_parser.struct_ReadLvlState.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__feedback_3_2, bytesProcessed) = dc_parser.struct_ReadLvlState.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__feedback_4_1, bytesProcessed) = dc_parser.struct_ReadLvlState.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__feedback_4_2, bytesProcessed) = dc_parser.struct_ReadLvlState.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 8
    
    class struct_Eps3_EXPANDER_Inst0_CurrentLimitersType:
        def __init__(self, s__h_h1_47_48 = None, s__l_h1_47_48 = None, s__h_h1_49_50 = None, s__l_h1_49_50 = None, s__h_h1_51_52 = None, s__l_h1_51_52 = None, s__release1 = None, s__release2 = None, s__release3 = None, s__release4 = None, s__interc_3v3 = None, s__interc_5v = None, s__interc_12v = None, s__interc_battery = None):
            self.s__h_h1_47_48 = s__h_h1_47_48
            self.s__l_h1_47_48 = s__l_h1_47_48
            self.s__h_h1_49_50 = s__h_h1_49_50
            self.s__l_h1_49_50 = s__l_h1_49_50
            self.s__h_h1_51_52 = s__h_h1_51_52
            self.s__l_h1_51_52 = s__l_h1_51_52
            self.s__release1 = s__release1
            self.s__release2 = s__release2
            self.s__release3 = s__release3
            self.s__release4 = s__release4
            self.s__interc_3v3 = s__interc_3v3
            self.s__interc_5v = s__interc_5v
            self.s__interc_12v = s__interc_12v
            self.s__interc_battery = s__interc_battery
    
        def serialize(self):
            result = bytearray()
    
            result += self.s__h_h1_47_48.serialize()
            result += self.s__l_h1_47_48.serialize()
            result += self.s__h_h1_49_50.serialize()
            result += self.s__l_h1_49_50.serialize()
            result += self.s__h_h1_51_52.serialize()
            result += self.s__l_h1_51_52.serialize()
            result += self.s__release1.serialize()
            result += self.s__release2.serialize()
            result += self.s__release3.serialize()
            result += self.s__release4.serialize()
            result += self.s__interc_3v3.serialize()
            result += self.s__interc_5v.serialize()
            result += self.s__interc_12v.serialize()
            result += self.s__interc_battery.serialize()
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_EXPANDER_Inst0_CurrentLimitersType()
    
            currentPos = pos
            (resultInstance.s__h_h1_47_48, bytesProcessed) = dc_parser.struct_VoltAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__l_h1_47_48, bytesProcessed) = dc_parser.struct_VoltAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__h_h1_49_50, bytesProcessed) = dc_parser.struct_VoltAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__l_h1_49_50, bytesProcessed) = dc_parser.struct_VoltAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__h_h1_51_52, bytesProcessed) = dc_parser.struct_VoltAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__l_h1_51_52, bytesProcessed) = dc_parser.struct_VoltAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__release1, bytesProcessed) = dc_parser.struct_VoltAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__release2, bytesProcessed) = dc_parser.struct_VoltAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__release3, bytesProcessed) = dc_parser.struct_VoltAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__release4, bytesProcessed) = dc_parser.struct_VoltAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__interc_3v3, bytesProcessed) = dc_parser.struct_VoltAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__interc_5v, bytesProcessed) = dc_parser.struct_VoltAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__interc_12v, bytesProcessed) = dc_parser.struct_VoltAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__interc_battery, bytesProcessed) = dc_parser.struct_VoltAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 56
    
    class struct_Eps3_INPUT_STAGE_Inst0_UpTimeInSecondsType:
        def __init__(self, uint32__seconds = 0):
            self.uint32__seconds = uint32__seconds
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint32", self.uint32__seconds)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_INPUT_STAGE_Inst0_UpTimeInSecondsType()
    
            currentPos = pos
            (resultInstance.uint32__seconds, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint32", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 4
    
    class struct_Eps3_INPUT_STAGE_Inst0CommonMeasurementType:
        def __init__(self, uint16__mcu_volt = 0, int32__mcu_temp = 0, uint16__sys_bus_volt = 0):
            self.uint16__mcu_volt = uint16__mcu_volt
            self.int32__mcu_temp = int32__mcu_temp
            self.uint16__sys_bus_volt = uint16__sys_bus_volt
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__mcu_volt)
            result += SerDesHelpers.serdesType_basic.serialize("int32", self.int32__mcu_temp)
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__sys_bus_volt)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_INPUT_STAGE_Inst0CommonMeasurementType()
    
            currentPos = pos
            (resultInstance.uint16__mcu_volt, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int32__mcu_temp, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int32", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint16__sys_bus_volt, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 8
    
    class struct_Eps3_INPUT_STAGE_Inst0hib_mode_status_type:
        def __init__(self, uint8__status = 0):
            self.uint8__status = uint8__status
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__status)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_INPUT_STAGE_Inst0hib_mode_status_type()
    
            currentPos = pos
            (resultInstance.uint8__status, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_Eps3_INPUT_STAGE_Inst0selflock_on_type:
        def __init__(self, uint8__status = 0):
            self.uint8__status = uint8__status
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__status)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_INPUT_STAGE_Inst0selflock_on_type()
    
            currentPos = pos
            (resultInstance.uint8__status, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_Eps3_INPUT_STAGE_Inst0Sp1InputDataType:
        def __init__(self, s__sp_measurements = None, uint8__input_current_state = 0, uint8__output_current_state = 0, uint8__input_voltage_state = 0, uint8__output_voltage_state = 0, s__state_mppt = None):
            self.s__sp_measurements = s__sp_measurements
            self.uint8__input_current_state = uint8__input_current_state
            self.uint8__output_current_state = uint8__output_current_state
            self.uint8__input_voltage_state = uint8__input_voltage_state
            self.uint8__output_voltage_state = uint8__output_voltage_state
            self.s__state_mppt = s__state_mppt
    
        def serialize(self):
            result = bytearray()
    
            result += self.s__sp_measurements.serialize()
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__input_current_state)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__output_current_state)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__input_voltage_state)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__output_voltage_state)
            result += self.s__state_mppt.serialize()
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_INPUT_STAGE_Inst0Sp1InputDataType()
    
            currentPos = pos
            (resultInstance.s__sp_measurements, bytesProcessed) = dc_parser.struct_VoltAllAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__input_current_state, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__output_current_state, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__input_voltage_state, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__output_voltage_state, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__state_mppt, bytesProcessed) = dc_parser.struct_MpptState_str.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 16
    
    class struct_Eps3_INPUT_STAGE_Inst0Sp2InputDataType:
        def __init__(self, s__sp_measurements = None, uint8__input_current_state = 0, uint8__output_current_state = 0, uint8__input_voltage_state = 0, uint8__output_voltage_state = 0, s__state_mppt = None):
            self.s__sp_measurements = s__sp_measurements
            self.uint8__input_current_state = uint8__input_current_state
            self.uint8__output_current_state = uint8__output_current_state
            self.uint8__input_voltage_state = uint8__input_voltage_state
            self.uint8__output_voltage_state = uint8__output_voltage_state
            self.s__state_mppt = s__state_mppt
    
        def serialize(self):
            result = bytearray()
    
            result += self.s__sp_measurements.serialize()
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__input_current_state)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__output_current_state)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__input_voltage_state)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__output_voltage_state)
            result += self.s__state_mppt.serialize()
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_INPUT_STAGE_Inst0Sp2InputDataType()
    
            currentPos = pos
            (resultInstance.s__sp_measurements, bytesProcessed) = dc_parser.struct_VoltAllAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__input_current_state, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__output_current_state, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__input_voltage_state, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__output_voltage_state, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__state_mppt, bytesProcessed) = dc_parser.struct_MpptState_str.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 16
    
    class struct_Eps3_INPUT_STAGE_Inst0Sp3InputDataType:
        def __init__(self, s__sp_measurements = None, uint8__input_current_state = 0, uint8__output_current_state = 0, uint8__input_voltage_state = 0, uint8__output_voltage_state = 0, s__state_mppt = None):
            self.s__sp_measurements = s__sp_measurements
            self.uint8__input_current_state = uint8__input_current_state
            self.uint8__output_current_state = uint8__output_current_state
            self.uint8__input_voltage_state = uint8__input_voltage_state
            self.uint8__output_voltage_state = uint8__output_voltage_state
            self.s__state_mppt = s__state_mppt
    
        def serialize(self):
            result = bytearray()
    
            result += self.s__sp_measurements.serialize()
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__input_current_state)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__output_current_state)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__input_voltage_state)
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__output_voltage_state)
            result += self.s__state_mppt.serialize()
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_INPUT_STAGE_Inst0Sp3InputDataType()
    
            currentPos = pos
            (resultInstance.s__sp_measurements, bytesProcessed) = dc_parser.struct_VoltAllAmps.deserialize(data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__input_current_state, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__output_current_state, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__input_voltage_state, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.uint8__output_voltage_state, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.s__state_mppt, bytesProcessed) = dc_parser.struct_MpptState_str.deserialize(data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 16
    
    class struct_Eps3_INPUT_STAGE_Inst0SystemBusType:
        def __init__(self, uint16__voltage = 0, int16__current = 0):
            self.uint16__voltage = uint16__voltage
            self.int16__current = int16__current
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__voltage)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__current)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_INPUT_STAGE_Inst0SystemBusType()
    
            currentPos = pos
            (resultInstance.uint16__voltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 4
    
    class struct_Eps3_INPUT_STAGE_Inst0Bus7v5Type:
        def __init__(self, uint16__voltage = 0, int16__current = 0):
            self.uint16__voltage = uint16__voltage
            self.int16__current = int16__current
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__voltage)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__current)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_INPUT_STAGE_Inst0Bus7v5Type()
    
            currentPos = pos
            (resultInstance.uint16__voltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 4
    
    class struct_Eps3_INPUT_STAGE_Inst0bus_7v5_power_good_type:
        def __init__(self, uint8__status = 0):
            self.uint8__status = uint8__status
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__status)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_INPUT_STAGE_Inst0bus_7v5_power_good_type()
    
            currentPos = pos
            (resultInstance.uint8__status, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_Eps3_INPUT_STAGE_Inst0undervoltage_7V5_type:
        def __init__(self, uint8__status = 0):
            self.uint8__status = uint8__status
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__status)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_INPUT_STAGE_Inst0undervoltage_7V5_type()
    
            currentPos = pos
            (resultInstance.uint8__status, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_Eps3_INPUT_STAGE_Inst0Bbus3v3Type:
        def __init__(self, uint16__voltage = 0, int16__current = 0):
            self.uint16__voltage = uint16__voltage
            self.int16__current = int16__current
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint16", self.uint16__voltage)
            result += SerDesHelpers.serdesType_basic.serialize("int16", self.int16__current)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_INPUT_STAGE_Inst0Bbus3v3Type()
    
            currentPos = pos
            (resultInstance.uint16__voltage, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint16", data, currentPos)
            currentPos += bytesProcessed
            (resultInstance.int16__current, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("int16", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 4
    
    class struct_Eps3_INPUT_STAGE_Inst0undervoltage_3V3_type:
        def __init__(self, uint8__status = 0):
            self.uint8__status = uint8__status
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__status)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_INPUT_STAGE_Inst0undervoltage_3V3_type()
    
            currentPos = pos
            (resultInstance.uint8__status, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
    class struct_Eps3_INPUT_STAGE_Inst0_FDIR_CMD_EXEC_STATUS_type:
        def __init__(self, uint8__eps_iii_pdm_a_get_telemetry_ErrorCode = 0):
            self.uint8__eps_iii_pdm_a_get_telemetry_ErrorCode = uint8__eps_iii_pdm_a_get_telemetry_ErrorCode
    
        def serialize(self):
            result = bytearray()
    
            result += SerDesHelpers.serdesType_basic.serialize("uint8", self.uint8__eps_iii_pdm_a_get_telemetry_ErrorCode)
    
            return result
    
        @staticmethod
        def deserialize(data, pos):
            resultInstance = dc_parser.struct_Eps3_INPUT_STAGE_Inst0_FDIR_CMD_EXEC_STATUS_type()
    
            currentPos = pos
            (resultInstance.uint8__eps_iii_pdm_a_get_telemetry_ErrorCode, bytesProcessed) = SerDesHelpers.serdesType_basic.deserialize("uint8", data, currentPos)
            currentPos += bytesProcessed
    
            # tuple[1] shall contain the total number of bytes processed by the function
            return (resultInstance, currentPos - pos)
    
        @staticmethod
        def getSize():
            return 1
    
