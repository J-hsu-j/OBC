// default telemetry logging period in milliseconds
#define TLM_LOG_PERIOD_DEF_MS  (30000U)
// individual file size limit for telemetry logging
#define TLM_FILE_SIZE_LIMIT_KB  (50U)
// maximum number of files to allocate for telemetry data
#define TLM_MAX_FILES_CNT       (20)

NVM_BLOCK_DEFAULTS_START(reserved_dummy, reserved_dummy_t)
    0U
NVM_BLOCK_DEFAULTS_END(reserved_dummy, reserved_dummy_t)
NVM_BLOCK_DECL(reserved_dummy, reserved_dummy_t)

NVM_BLOCK_DEFAULTS_START(beacons_cfg, beacons_cfg_t)
    SAFE_TRUE,         // beacons_en
    SAFE_TRUE,         // chunk_based_transfer_en
    30000U,            // bcn_tx_period (in ms)
    500U               // bcn_inter_frame_period (in ms)
NVM_BLOCK_DEFAULTS_END(beacons_cfg, beacons_cfg_t)
NVM_BLOCK_DECL(beacons_cfg, beacons_cfg_t)

NVM_BLOCK_DEFAULTS_START(beacons_presets_cfg, beacons_presets_cfg_t)
    {
        // preset #0 defaults (SAFE mode)
        {
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            DC_ATTR_ID_OBC_0_DATA,
            DC_ATTR_ID_AOCS_CNTRL_TLM_DATA,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            DC_ATTR_ID_ADCS_2_DATA,
            DC_ATTR_ID_ADCS_1_DATA,
            DC_ATTR_ID_ADCS_0_DATA,
            DC_ATTR_ID_SSP_0_DATA,
            DC_ATTR_ID_SSP_1_DATA,
            DC_ATTR_ID_SSP_2_DATA,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT
        },
        // preset #1 defaults (IDLE mode)
        {
            DC_ATTR_ID_OBC_0_DATA,
            DC_ATTR_ID_ADCS_1_DATA,
            DC_ATTR_ID_ADCS_2_DATA,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            DC_ATTR_ID_ADCS_0_DATA,
            DC_ATTR_ID_AOCS_CNTRL_TLM_DATA,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            DC_ATTR_ID_SSP_0_DATA,
            DC_ATTR_ID_SSP_1_DATA,
            DC_ATTR_ID_SSP_2_DATA,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT
        },
        // preset #2 defaults (MISSION mode)
        {
            DC_ATTR_ID_OBC_0_DATA,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            DC_ATTR_ID_ADCS_0_DATA,
            DC_ATTR_ID_ADCS_2_DATA,
            DC_ATTR_ID_AOCS_CNTRL_TLM_DATA,
            DC_ATTR_ID_ADCS_1_DATA,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            DC_ATTR_ID_SSP_0_DATA,
            DC_ATTR_ID_SSP_1_DATA,
            DC_ATTR_ID_SSP_2_DATA,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT,
            INVALID_BEACON_SLOT_ASSIGNMENT
        },
    }   // beacons_presets_cfg[PRESETS_COUNT][MAX_BEACON_MSG_SLOTS]
NVM_BLOCK_DEFAULTS_END(beacons_presets_cfg, beacons_presets_cfg_t)
NVM_BLOCK_DECL(beacons_presets_cfg, beacons_presets_cfg_t)

NVM_BLOCK_DEFAULTS_START(conops_config, conops_config_t)
        { // conops_config.thresh
            8000,   // .i32V_batt_safe
            -20000, // .i32T_batt_safe_lower
            55000,  // .i32T_batt_safe_upper
            500,    // .i32AngVelMax
            43,     // .i32AngVelLow
            -32,    // .i32Ang_vel_y_thomson_high
            -37,    // .i32Ang_vel_y_thomson_low


        },
        {
            {
                AOCS_CNTRL_SYS_STATE_NORMAL_DETUMBLING,
                {0.0f, 0.0f, 0.0f}
            },                               // .def_control[ 0 ] - SAFE
            {
                AOCS_CNTRL_SYS_STATE_3AXIS,
                {0.0f, 0.0f, 0.0f}
            }                                // .def_control[ 1 ] - IDLE
        }
NVM_BLOCK_DEFAULTS_END(conops_config, conops_config_t)
NVM_BLOCK_DECL(conops_config, conops_config_t)

//
// Telemetry instance 0 configuration
//

NVM_BLOCK_DEFAULTS_START(telemetry_cfg_0, telemetry_cfg_t)
    .params.bTlm_auto_start_en = true
NVM_BLOCK_DEFAULTS_END(telemetry_cfg_0, telemetry_cfg_t)
NVM_BLOCK_DECL(telemetry_cfg_0, telemetry_cfg_t)

NVM_BLOCK_DEFAULTS_START(telemetry_preset_cfg_0, telemetry_preset_cfg_t)
    {
      // preset #0 defaults: SAFE mode
      {
          [0] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [1] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [2] =
          {
              .u16Data_id = DC_ATTR_ID_OBC_0_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [3] =
          {
              .u16Data_id = DC_ATTR_ID_AOCS_CNTRL_TLM_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [4] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [5] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [6] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [7] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [8] =
          {
              .u16Data_id = DC_ATTR_ID_ADCS_2_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [9] =
          {
              .u16Data_id = DC_ATTR_ID_ADCS_1_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          }
      },
      // preset #1 defaults: IDLE mode
      {
          [0] =
          {
              .u16Data_id = DC_ATTR_ID_OBC_0_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [1] =
          {
              .u16Data_id = DC_ATTR_ID_ADCS_1_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [2] =
          {
              .u16Data_id = DC_ATTR_ID_ADCS_2_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [3] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [4] =
          {
              .u16Data_id = DC_ATTR_ID_ADCS_0_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [5] =
          {
              .u16Data_id = DC_ATTR_ID_AOCS_CNTRL_TLM_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [6] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [7] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [8] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [9] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          }
      },
      // preset #2 defaults: MISSION mode
      {
          [0] =
          {
              .u16Data_id = DC_ATTR_ID_OBC_0_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [1] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [2] =
          {
              .u16Data_id = DC_ATTR_ID_ADCS_0_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [3] =
          {
              .u16Data_id = DC_ATTR_ID_ADCS_2_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [4] =
          {
              .u16Data_id = DC_ATTR_ID_AOCS_CNTRL_TLM_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [5] =
          {
              .u16Data_id = DC_ATTR_ID_ADCS_1_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [6] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [7] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [8] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [9] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          }
      },
    }                   // beacons_presets_cfg[PRESETS_COUNT][MAX_BEACON_MSG_SLOTS]
NVM_BLOCK_DEFAULTS_END(telemetry_preset_cfg_0, telemetry_preset_cfg_t)
NVM_BLOCK_DECL(telemetry_preset_cfg_0, telemetry_preset_cfg_t)

NVM_BLOCK_DEFAULTS_START(telemetry_file_cfg_0, telemetry_file_cfg_t)
    .cfg_type = TELEMETRY_TLM_FILE_LOGGING_TYPE_SIZE_LIMIT,
    .params.u32Size_limit_kb = (TLM_MAX_FILES_CNT * TLM_FILE_SIZE_LIMIT_KB),
    .params.u16Max_log_files_cnt = TLM_MAX_FILES_CNT
NVM_BLOCK_DEFAULTS_END(telemetry_file_cfg_0, telemetry_file_cfg_t)
NVM_BLOCK_DECL(telemetry_file_cfg_0, telemetry_file_cfg_t)

NVM_BLOCK_DEFAULTS_START(telemetry_persistent_data_0, telemetry_persistent_data_t)
    .last_file_slot_idx = 0
NVM_BLOCK_DEFAULTS_END(telemetry_persistent_data_0, telemetry_persistent_data_t)
NVM_BLOCK_DECL(telemetry_persistent_data_0, telemetry_persistent_data_t)

//
// Telemetry instance 1 configuration
//

NVM_BLOCK_DEFAULTS_START(telemetry_cfg_1, telemetry_cfg_t)
    .params.bTlm_auto_start_en = true
NVM_BLOCK_DEFAULTS_END(telemetry_cfg_1, telemetry_cfg_t)
NVM_BLOCK_DECL(telemetry_cfg_1, telemetry_cfg_t)

NVM_BLOCK_DEFAULTS_START(telemetry_preset_cfg_1, telemetry_preset_cfg_t)
    {
      // preset #0 defaults: SAFE mode
      {
          [0] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [1] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [2] =
          {
              .u16Data_id = DC_ATTR_ID_OBC_0_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [3] =
          {
              .u16Data_id = DC_ATTR_ID_AOCS_CNTRL_TLM_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [4] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [5] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [6] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [7] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [8] =
          {
              .u16Data_id = DC_ATTR_ID_ADCS_2_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [9] =
          {
              .u16Data_id = DC_ATTR_ID_ADCS_1_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          }
      },
      // preset #1 defaults: IDLE mode
      {
          [0] =
          {
              .u16Data_id = DC_ATTR_ID_OBC_0_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [1] =
          {
              .u16Data_id = DC_ATTR_ID_ADCS_1_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [2] =
          {
              .u16Data_id = DC_ATTR_ID_ADCS_2_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [3] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [4] =
          {
              .u16Data_id = DC_ATTR_ID_ADCS_0_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [5] =
          {
              .u16Data_id = DC_ATTR_ID_AOCS_CNTRL_TLM_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [6] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [7] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [8] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [9] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          }
      },
      // preset #2 defaults: MISSION mode
      {
          [0] =
          {
              .u16Data_id = DC_ATTR_ID_OBC_0_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [1] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [2] =
          {
              .u16Data_id = DC_ATTR_ID_ADCS_0_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [3] =
          {
              .u16Data_id = DC_ATTR_ID_ADCS_2_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [4] =
          {
              .u16Data_id = DC_ATTR_ID_AOCS_CNTRL_TLM_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [5] =
          {
              .u16Data_id = DC_ATTR_ID_ADCS_1_DATA,
              .bActive = true,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [6] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [7] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [8] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          },
          [9] =
          {
              .u16Data_id = INVALID_TLM_SLOT_ASSIGNMENT,
              .bActive = false,
              .u16Acq_period_ms = TLM_LOG_PERIOD_DEF_MS
          }
      },
    }                   // beacons_presets_cfg[PRESETS_COUNT][MAX_BEACON_MSG_SLOTS]
NVM_BLOCK_DEFAULTS_END(telemetry_preset_cfg_1, telemetry_preset_cfg_t)
NVM_BLOCK_DECL(telemetry_preset_cfg_1, telemetry_preset_cfg_t)

NVM_BLOCK_DEFAULTS_START(telemetry_file_cfg_1, telemetry_file_cfg_t)
    .cfg_type = TELEMETRY_TLM_FILE_LOGGING_TYPE_SIZE_LIMIT,
    .params.u32Size_limit_kb = (TLM_MAX_FILES_CNT * TLM_FILE_SIZE_LIMIT_KB),
    .params.u16Max_log_files_cnt = TLM_MAX_FILES_CNT
NVM_BLOCK_DEFAULTS_END(telemetry_file_cfg_1, telemetry_file_cfg_t)
NVM_BLOCK_DECL(telemetry_file_cfg_1, telemetry_file_cfg_t)

NVM_BLOCK_DEFAULTS_START(telemetry_persistent_data_1, telemetry_persistent_data_t)
    .last_file_slot_idx = 0
NVM_BLOCK_DEFAULTS_END(telemetry_persistent_data_1, telemetry_persistent_data_t)
NVM_BLOCK_DECL(telemetry_persistent_data_1, telemetry_persistent_data_t)

NVM_BLOCK_DEFAULTS_START(EPSM_Config, EPS_M_Config_t)
    .reserved1 = SAFE_TRUE,  // corresponds to 'enableRtcAutoAjust'
    .reserved2 = SAFE_TRUE,  // corresponds to 'onlyIfRtcIsLost'
    .reserved3 = SAFE_FALSE, // corresponds to 'reserved1'
    .reserved4 = SAFE_FALSE, // corresponds to 'enableCapacityCalculation'
    .reserved5 = SAFE_FALSE, // corresponds to 'enableUsingPduBoardTemperature'
    .reserved6 = SAFE_FALSE, // corresponds to 'usedExactTemperatureEnable'
    .reserved7 = 2000,       // corresponds to 'exactTemperature'
    .reserved8 = SAFE_FALSE, // corresponds to 'reserved2'
    .reserved9 = SAFE_FALSE  // corresponds to 'allowAutoEnableEpsOnPowerUP'
NVM_BLOCK_DEFAULTS_END(EPSM_Config, EPS_M_Config_t)
NVM_BLOCK_DECL(EPSM_Config, EPS_M_Config_t)

NVM_BLOCK_DEFAULTS_START(cubeadcs_err_handl_cfg, cubeadcs_err_handl_cfg_t)
       SAFE_TRUE // Enable error handling
NVM_BLOCK_DEFAULTS_END(cubeadcs_err_handl_cfg, cubeadcs_err_handl_cfg_t)
NVM_BLOCK_DECL(cubeadcs_err_handl_cfg, cubeadcs_err_handl_cfg_t)

NVM_BLOCK_DEFAULTS_START(cubeadcs_status, cubeadcs_status_t)
    0x00,                     // No commissioning
    0x00,                     // No faulty nodes detected
    0x0000                    // No errors
NVM_BLOCK_DEFAULTS_END(cubeadcs_status, cubeadcs_status_t)
NVM_BLOCK_DECL(cubeadcs_status, cubeadcs_status_t)

NVM_BLOCK_DEFAULTS_START(i2c_config, i2c_config_t)
    // I2C Pull-up configuration
    .i2c_pull_up_config =
    {
        // I2C_BUS_SYSTEM
        {
            .pull_up_4k7 = true,
            .pull_up_10k = false
        },
        // I2C_BUS_PAYLOAD
        {
            .pull_up_4k7 = true,
            .pull_up_10k = false
        }
    }
NVM_BLOCK_DEFAULTS_END(i2c_config, i2c_config_t)
NVM_BLOCK_DECL(i2c_config, i2c_config_t)

NVM_BLOCK_DEFAULTS_START(cubeadcs_angle_limits, cubeadcs_angle_limits_t)
    1000,                   // Angular position threshold (boundary) in millidegrees
     200                    // Angular velocity threshold (boundary) in millidegrees
NVM_BLOCK_DEFAULTS_END(cubeadcs_angle_limits, cubeadcs_angle_limits_t)
NVM_BLOCK_DECL(cubeadcs_angle_limits, cubeadcs_angle_limits_t)

NVM_BLOCK_DEFAULTS_START(aocs_pm_config, aocs_pm_config_t)
.parameters = {
	0x00000384,			// 480 seconds, duration of a pass
	0x04,				// 4 seconds is the default update interval
	0x00,				// EST_ATT_ANGL the default data type
	0x000A 				//samples to skip
}
NVM_BLOCK_DEFAULTS_END(aocs_pm_config, aocs_pm_config_t)
NVM_BLOCK_DECL(aocs_pm_config, aocs_pm_config_t)

NVM_BLOCK_DEFAULTS_START(aocs_pm_threshold, aocs_pm_thresholds_t)
.value[0] = {
	6.0,     //tolerance
	0.05     //safety factor of 50 in mili units
},
.value[1] = {
	6.0,     //tolerance
	0.05      //safety factor of 50 in mili units
},
.value[2] = {
	6.0,      //tolerance
	0.05       //safety factor of 50 in mili units
}
NVM_BLOCK_DEFAULTS_END(aocs_pm_threshold, aocs_pm_thresholds_t)
NVM_BLOCK_DECL(aocs_pm_threshold, aocs_pm_thresholds_t)

NVM_BLOCK_DEFAULTS_START(coordsys_frames, coordsys_frames_t)
.gyroscope_frame =
    {
        .frame_axis_1 = SAT_Z_AXIS_POSITIVE,
        .frame_axis_2 = SAT_Y_AXIS_POSITIVE,
        .frame_axis_3 = SAT_X_AXIS_POSITIVE
    },
.magnetometer_frame =
    {
        .frame_axis_1 = SAT_X_AXIS_POSITIVE,
        .frame_axis_2 = SAT_Y_AXIS_NEGATIVE,
        .frame_axis_3 = SAT_Z_AXIS_NEGATIVE
    },
.coarse_sun_sensor_frame =
    {
        .frame_axis_1 = SAT_Y_AXIS_NEGATIVE,
        .frame_axis_2 = SAT_X_AXIS_NEGATIVE,
        .frame_axis_3 = SAT_Z_AXIS_NEGATIVE,
        .frame_axis_4 = SAT_Z_AXIS_POSITIVE,
        .frame_axis_5 = SAT_Y_AXIS_POSITIVE,
        .frame_axis_6 = SAT_X_AXIS_POSITIVE
    },
.magnetorquer_frame =
    {
        .frame_axis_1 = SAT_Z_AXIS_POSITIVE,
        .frame_axis_2 = SAT_Y_AXIS_POSITIVE,
        .frame_axis_3 = SAT_X_AXIS_POSITIVE
    }
NVM_BLOCK_DEFAULTS_END(coordsys_frames, coordsys_frames_t)
NVM_BLOCK_DECL(coordsys_frames, coordsys_frames_t)

NVM_BLOCK_DEFAULTS_START(sds_sens_read_freq, sds_sens_read_freq_t)
	SAFE_FALSE,
	{
		{
				.freq_cfg = 10,	// Magnetometer sensor group read frequency in [Hz]
				.event_cfg = SDS_THREAD_FLAGS_MTM,
		},
		{
				.freq_cfg = 10,	// Rate sensor group read frequency in [Hz]
				.event_cfg = SDS_THREAD_FLAGS_GYRO,
		},
		{
				.freq_cfg = 10, // Coarse Sun sensor group read frequency in [Hz]
				.event_cfg = SDS_THREAD_FLAGS_CSS,
		},
		{
				.freq_cfg = 10, // Temperature (located on 1U panels) sensor group read frequency in [Hz]
				.event_cfg = SDS_THREAD_FLAGS_TEMP,
		},
		{
				.freq_cfg = 2, // Rate sensor group temperature sensors read frequency in [Hz]
				.event_cfg = SDS_THREAD_FLAGS_GYRO_TEMP,
		},
		{
				.freq_cfg = 0, // Reserved sensor group read frequency in [Hz]
				.event_cfg = SDS_THREAD_FLAGS_RES_1,
		},
		{
				.freq_cfg = 0, // Reserved sensor group read frequency in [Hz]
				.event_cfg = SDS_THREAD_FLAGS_RES_2,
		}
	}
NVM_BLOCK_DEFAULTS_END(sds_sens_read_freq, sds_sens_read_freq_t)
NVM_BLOCK_DECL(sds_sens_read_freq, sds_sens_read_freq_t)

NVM_BLOCK_DEFAULTS_START(crypto_cfg, crypto_cfg_t)
    // AES invalid encryption key
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    }
NVM_BLOCK_DEFAULTS_END(crypto_cfg, crypto_cfg_t)
NVM_BLOCK_DECL(crypto_cfg, crypto_cfg_t)

NVM_BLOCK_DEFAULTS_START(cubeadcs_sim_mode, cubeadcs_sim_mode_t)
    SAFE_FALSE                // Simulation mode
NVM_BLOCK_DEFAULTS_END(cubeadcs_sim_mode, cubeadcs_sim_mode_t)
NVM_BLOCK_DECL(cubeadcs_sim_mode, cubeadcs_sim_mode_t)

NVM_BLOCK_DEFAULTS_START(rtc_calib_data, rtc_calib_data_t)
    0,  // Calm default
    SYS_TIME_CALP_PULSES_RESET // Calp default
NVM_BLOCK_DEFAULTS_END(rtc_calib_data, rtc_calib_data_t)
NVM_BLOCK_DECL(rtc_calib_data, rtc_calib_data_t)

NVM_BLOCK_DEFAULTS_START(gyroscope_configs, gyroscope_configs_t)
.gyroscope_array[0] =
    {
        .gyro_id = GYROSCOPE_1,
        .general_status = GYRO_NOT_INIT,
        .attached_panel = PANEL_4,
        .satellite_axis = PAN_X_P,
        .enabled_flag = ADIS16265_DISABLED
    },
.gyroscope_array[1] =
    {
        .gyro_id = GYROSCOPE_2,
        .general_status = GYRO_NOT_INIT,
        .attached_panel = PANEL_5,
        .satellite_axis = PAN_Y_P,
        .enabled_flag = ADIS16265_DISABLED
    },
.gyroscope_array[2] =
    {
        .gyro_id = GYROSCOPE_3,
        .general_status = GYRO_NOT_INIT,
        .attached_panel = PANEL_6,
        .satellite_axis = PAN_Z_P,
        .enabled_flag = ADIS16265_DISABLED
    }
NVM_BLOCK_DEFAULTS_END(gyroscope_configs, gyroscope_configs_t)
NVM_BLOCK_DECL(gyroscope_configs, gyroscope_configs_t)

NVM_BLOCK_DEFAULTS_START(fm_stats, fm_stats_t)
    .api_err_counters =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    }
NVM_BLOCK_DEFAULTS_END(fm_stats, fm_stats_t)
NVM_BLOCK_DECL(fm_stats, fm_stats_t)

NVM_BLOCK_DEFAULTS_START(cubeADCS_sys_state_cfg, cubeADCS_sys_state_cfg_t)
{
			{eCUBEADCS_CFGTYPE_PWR_UP,
		        { .CubeControl_Signal = 1,
		    	  .CubeControl_Motor  = 1,
				  .CubeSense1 = 0,
		          .CubeSense2 = 0,
				  .CubeStar   = 0,
				  .CubeWheel1 = 0,
				  .CubeWheel2 = 0,
				  .CubeWheel3 = 0
		        },
		        eCUBE_ADCS_TC_13_CONTROLMODE_NO_CNTRL,
				eCUBE_ADCS_TC_14_ESTIMATIONMODE_MEMS_RATE_SENS,
			    eCUBE_ADCS_TC10_RUNMODE_ENABLED,
			    0,
		  },
		  {     eCUBEADCS_CFGTYPE_NORMAL_DETUMBLING,
		        { .CubeControl_Signal = 1,
		          .CubeControl_Motor  = 1,
		          .CubeSense1 = 0,
				  .CubeSense2 = 0,
				  .CubeStar   = 0,
		          .CubeWheel1 = 0,
				  .CubeWheel2 = 0,
				  .CubeWheel3 = 0
		        },
		        eCUBE_ADCS_TC_13_CONTROLMODE_DETUMB_CNTRL,
				eCUBE_ADCS_TC_14_ESTIMATIONMODE_MEMS_RATE_SENS,
			    eCUBE_ADCS_TC10_RUNMODE_ENABLED,
			    0,
		  },
		  {   	eCUBEADCS_CFGTYPE_Y_THOMSON,
		        { .CubeControl_Signal = 1,
		          .CubeControl_Motor  = 1,
		          .CubeSense1 = 0,
				  .CubeSense2 = 0,
				  .CubeStar   = 0,
		          .CubeWheel1 = 0,
				  .CubeWheel2 = 0,
				  .CubeWheel3 = 0
		        },
		        eCUBE_ADCS_TC_13_CONTROLMODE_Y_THOMPSON,
				eCUBE_ADCS_TC_14_ESTIMATIONMODE_MEMS_RATE_SENS,
		        eCUBE_ADCS_TC10_RUNMODE_ENABLED,
		        0,
		  },
		  {   	eCUBEADCS_CFGTYPE_Y_THOMSON_MEMS_RATE,
		        { .CubeControl_Signal = 1,
		          .CubeControl_Motor  = 1,
		          .CubeSense1 = 0,
				  .CubeSense2 = 0,
				  .CubeStar   = 0,
		          .CubeWheel1 = 0,
				  .CubeWheel2 = 0,
				  .CubeWheel3 = 0
		        },
		        eCUBE_ADCS_TC_13_CONTROLMODE_Y_THOMPSON,
				eCUBE_ADCS_TC_14_ESTIMATIONMODE_MEMS_RATE_SENS,
		        eCUBE_ADCS_TC10_RUNMODE_ENABLED,
		        0,
		  },
		  {   	eCUBEADCS_CFGTYPE_FAST_DETUMBLING,
		        { .CubeControl_Signal = 1,
		          .CubeControl_Motor  = 1,
		          .CubeSense1 = 0,
				  .CubeSense2 = 0,
				  .CubeStar   = 0,
		          .CubeWheel1 = 0,
				  .CubeWheel2 = 0,
				  .CubeWheel3 = 0
		        },
				eCUBE_ADCS_TC_13_CONTROLMODE_FAST_SPIN_DETUMB,
				eCUBE_ADCS_TC_14_ESTIMATIONMODE_MEMS_RATE_SENS,
		        eCUBE_ADCS_TC10_RUNMODE_ENABLED,
		        0,
		  },
		  {   	eCUBEADCS_CFGTYPE_VERY_FAST_DETUMBLING,
		        { .CubeControl_Signal = 1,
		          .CubeControl_Motor  = 1,
		          .CubeSense1 = 0,
				  .CubeSense2 = 0,
				  .CubeStar   = 0,
		          .CubeWheel1 = 0,
				  .CubeWheel2 = 0,
				  .CubeWheel3 = 0
		        },
				eCUBE_ADCS_TC_13_CONTROLMODE_VERY_FAST_SPIN_DETUMB,
				eCUBE_ADCS_TC_14_ESTIMATIONMODE_MEMS_RATE_SENS,
		        eCUBE_ADCS_TC10_RUNMODE_ENABLED,
		        0,
		  },
		  {   	eCUBEADCS_CFGTYPE_Y_MOMENTUM,
		        { .CubeControl_Signal = 1,
		          .CubeControl_Motor  = 1,
		          .CubeSense1 = 0,
				  .CubeSense2 = 0,
				  .CubeStar   = 0,
		          .CubeWheel1 = 0,
				  .CubeWheel2 = 1,
				  .CubeWheel3 = 0
		        },
				eCUBE_ADCS_TC_13_CONTROLMODE_Y_WHEEL_INITIAL,
				eCUBE_ADCS_TC_14_ESTIMATIONMODE_MEMS_GYRO_EKF,
		        eCUBE_ADCS_TC10_RUNMODE_ENABLED,
		        0,
		  },
		  {   	eCUBEADCS_CFGTYPE_Y_MOMENTUM_FULL_STATE_EKF,
		        { .CubeControl_Signal = 1,
		          .CubeControl_Motor  = 1,
		          .CubeSense1 = 1,
				  .CubeSense2 = 1,
				  .CubeStar   = 1,
		          .CubeWheel1 = 0,
				  .CubeWheel2 = 1,
				  .CubeWheel3 = 0
		        },
				eCUBE_ADCS_TC_13_CONTROLMODE_Y_WHEEL_STEADY,
				eCUBE_ADCS_TC_14_ESTIMATIONMODE_FULL_EKF,
		        eCUBE_ADCS_TC10_RUNMODE_ENABLED,
		        0,
		  },
		  {   	eCUBEADCS_CFGTYPE_3AXIS,
		        { .CubeControl_Signal = 1,
		          .CubeControl_Motor  = 1,
		          .CubeSense1 = 1,
				  .CubeSense2 = 1,
				  .CubeStar   = 1,
		          .CubeWheel1 = 1,
				  .CubeWheel2 = 1,
				  .CubeWheel3 = 1
		        },
				eCUBE_ADCS_TC_13_CONTROLMODE_XYZ_WHEEL_CNTRL,
				eCUBE_ADCS_TC_14_ESTIMATIONMODE_MEMS_GYRO_EKF,
		        eCUBE_ADCS_TC10_RUNMODE_ENABLED,
		        0,
		  },
		  {   	eCUBEADCS_CFGTYPE_SUN_TRACKING,
		        { .CubeControl_Signal = 1,
		          .CubeControl_Motor  = 1,
		          .CubeSense1 = 1,
				  .CubeSense2 = 1,
				  .CubeStar   = 1,
		          .CubeWheel1 = 1,
				  .CubeWheel2 = 1,
				  .CubeWheel3 = 1
		        },
				eCUBE_ADCS_TC_13_CONTROLMODE_RWHEEL_SUN_TRACKING,
				eCUBE_ADCS_TC_14_ESTIMATIONMODE_MEMS_GYRO_EKF,
		        eCUBE_ADCS_TC10_RUNMODE_ENABLED,
		        0,
		  },
		  {   	eCUBEADCS_CFGTYPE_TARGET_TRACKING,
		        { .CubeControl_Signal = 1,
		          .CubeControl_Motor  = 1,
		          .CubeSense1 = 1,
				  .CubeSense2 = 1,
				  .CubeStar   = 1,
		          .CubeWheel1 = 1,
				  .CubeWheel2 = 1,
				  .CubeWheel3 = 1
		        },
				eCUBE_ADCS_TC_13_CONTROLMODE_RWHEEL_TARGET_TRACKING,
				eCUBE_ADCS_TC_14_ESTIMATIONMODE_MEMS_GYRO_EKF,
		        eCUBE_ADCS_TC10_RUNMODE_ENABLED,
		        0,
		  },
          {     eCUBEADCS_CFGTYPE_NO_CONTROL,
                { .CubeControl_Signal = 1,
                  .CubeControl_Motor  = 1,
                  .CubeSense1 = 0,
                  .CubeSense2 = 0,
                  .CubeStar   = 0,
                  .CubeWheel1 = 0,
                  .CubeWheel2 = 0,
                  .CubeWheel3 = 0
                },
                eCUBE_ADCS_TC_13_CONTROLMODE_NO_CNTRL,
				eCUBE_ADCS_TC_14_ESTIMATIONMODE_MEMS_RATE_SENS,
                eCUBE_ADCS_TC10_RUNMODE_ENABLED,
                0,
          },
          {     eCUBEADCS_CFGTYPE_ATTITUDE_CHANGE,
                { .CubeControl_Signal = 1,
                  .CubeControl_Motor  = 1,
                  .CubeSense1 = 0,
                  .CubeSense2 = 0,
                  .CubeStar   = 0,
                  .CubeWheel1 = 0,
                  .CubeWheel2 = 0,
                  .CubeWheel3 = 0
                },
                eCUBE_ADCS_TC_13_CONTROLMODE_Y_THOMPSON,
				eCUBE_ADCS_TC_14_ESTIMATIONMODE_MEMS_GYRO_EKF,
                eCUBE_ADCS_TC10_RUNMODE_ENABLED,
                1,
          },
          {     eCUBEADCS_CFGTYPE_ORBITAL_CHANGE,
                { .CubeControl_Signal = 1,
                  .CubeControl_Motor  = 1,
                  .CubeSense1 = 1,
                  .CubeSense2 = 1,
                  .CubeStar   = 1,
                  .CubeWheel1 = 1,
                  .CubeWheel2 = 1,
                  .CubeWheel3 = 1
                },
                eCUBE_ADCS_TC_13_CONTROLMODE_XYZ_WHEEL_CNTRL,
                eCUBE_ADCS_TC_14_ESTIMATIONMODE_MEMS_GYRO_EKF,
                eCUBE_ADCS_TC10_RUNMODE_ENABLED,
                1,
          },
		  {     eCUBEADCS_CFGTYPE_GEO_TARGET_TRACKING,
				  { .CubeControl_Signal = 1,
					.CubeControl_Motor  = 1,
					.CubeSense1 = 1,
					.CubeSense2 = 1,
					.CubeStar   = 1,
					.CubeWheel1 = 1,
					.CubeWheel2 = 1,
					.CubeWheel3 = 1
				  },
				  eCUBE_ADCS_TC_13_CONTROLMODE_USER_MODE_1,
				  eCUBE_ADCS_TC_14_ESTIMATIONMODE_MEMS_GYRO_EKF,
				  eCUBE_ADCS_TC10_RUNMODE_ENABLED,
				  0,
		  }
}
NVM_BLOCK_DEFAULTS_END(cubeADCS_sys_state_cfg, cubeADCS_sys_state_cfg_t)
NVM_BLOCK_DECL(cubeADCS_sys_state_cfg, cubeADCS_sys_state_cfg_t)

// 0x00 is an invalid MAC Address
NVM_BLOCK_DEFAULTS_START(mac_address_book, mac_address_book_t)
    {
        0x99, // MAC_ADDR_EPS_I,
        0x00, // MAC_ADDR_RESERVED_5,
        0x77, // MAC_ADDR_EPS_II_PDM,
        0x11, // MAC_ADDR_UHF,
        0x44, // MAC_ADDR_SBAND_TMTC,
        0x51, // MAC_ADDR_SP1,
        0x52, // MAC_ADDR_SP2,
        0x53, // MAC_ADDR_SP3,
        0x54, // MAC_ADDR_SP4,
        0xC0, // MAC_ADDR_PAYLOAD_1,
        0xD0, // MAC_ADDR_PAYLOAD_2,
        0x00, // MAC_ADDR_RESERVED_1,
        0x00, // MAC_ADDR_RESERVED_2,
        0x00, // MAC_ADDR_RESERVED_3,
        0x00, // MAC_ADDR_RESERVED_4,
    },
    {
// begin EPS BP generated code
        0x66, // MAC_ADDR_EPS INST0
        0x67 // MAC_ADDR_EPS INST1
// end EPS BP generated code
    },
    {
// begin EPS_III BP generated code
        0xb0, // MAC_ADDR_EPS BP INST0
// end EPS_III BP generated code
// begin EPS_III PDM_A generated code
        0xa4, // MAC_ADDR_EPS PDM_A INST0
// end EPS_III PDM_A generated code
// begin EPS_III PDM_B generated code
        0xa8, // MAC_ADDR_EPS PDM_B INST0
// end EPS_III PDM_B generated code
// begin EPS_III EXPANDER generated code
        0xac, // MAC_ADDR_EPS EXPANDER INST0
// end EPS_III EXPANDER generated code
// begin EPS_III INPUT_STAGE generated code
        0xa0, // MAC_ADDR_EPS INPUT_STAGE INST0
// end EPS_III INPUT_STAGE generated code
    }
NVM_BLOCK_DEFAULTS_END(mac_address_book, mac_address_book_t)
NVM_BLOCK_DECL(mac_address_book, mac_address_book_t)



NVM_BLOCK_DEFAULTS_START(cubeadcs_gen2_sys_states_cfg, cubeadcs_gen2_sys_states_cfg_t)
// AOCS_CNTRL_SYS_STATE_NO_CONTROL
.sys_state_cfg[0] =
{
        .pwr_state = {
                .rwl0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .mag0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .mag1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .gyro0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .gyro1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .hss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .hss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .str0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .str1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
        },
        .cntrl_mode = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__CON_NONE,
        .est_mode_main = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_GYRO,
        .est_mode_backup = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_MAG_RKF,
},
// AOCS_CNTRL_SYS_STATE_NORMAL_DETUMBLING
.sys_state_cfg[1] =
{
        .pwr_state = {
                .rwl0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .mag0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .mag1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .gyro0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .gyro1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .hss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .hss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .str0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .str1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
        },
        .cntrl_mode = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__CON_BDOT,
        .est_mode_main = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_GYRO,
        .est_mode_backup = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_MAG_RKF,
},
// AOCS_CNTRL_SYS_STATE_Y_THOMSON
.sys_state_cfg[2] =
{
        .pwr_state = {
                .rwl0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .mag0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .mag1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .gyro0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .gyro1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .hss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .hss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .str0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .str1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
        },
        .cntrl_mode = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__CON_YSPIN,
        .est_mode_main = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_MAG_RKF,
        .est_mode_backup = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_GYRO,
},
// AOCS_CNTRL_SYS_STATE_Y_THOMSON_MEMS_RATE
.sys_state_cfg[3] =
{
        .pwr_state = {
                .rwl0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .mag0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .mag1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .gyro0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .gyro1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .hss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .hss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .str0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .str1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
        },
        .cntrl_mode = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__CON_YSPIN,
        .est_mode_main = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_GYRO,
        .est_mode_backup = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_MAG_RKF,
},
// AOCS_CNTRL_SYS_STATE_FAST_DETUMBLING
.sys_state_cfg[4] =
{
        .pwr_state = {
                .rwl0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .mag0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .mag1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .gyro0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .gyro1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .hss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .hss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .str0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .str1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
        },
        .cntrl_mode = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__CON_BDOT_3,
        .est_mode_main = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_GYRO,
        .est_mode_backup = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_MAG_RKF,
},
// AOCS_CNTRL_SYS_STATE_VERY_FAST_DETUMBLING
.sys_state_cfg[5] =
{
        .pwr_state = {
                .rwl0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .mag0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .mag1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .gyro0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .gyro1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .hss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .hss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .str0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .str1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
        },
        .cntrl_mode = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__CON_DETUMBLE,
        .est_mode_main = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_MAG_RKF,
        .est_mode_backup = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_GYRO,
},
// AOCS_CNTRL_SYS_STATE_Y_MOMENTUM
.sys_state_cfg[6] =
{
        .pwr_state = {
                .rwl0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .rwl1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .rwl2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .rwl3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .mag0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .mag1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .gyro0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .gyro1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .hss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .hss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .str0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .str1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .extSensor0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
        },
        .cntrl_mode = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__CON_YWHEEL_INIT,
        .est_mode_main = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_GYRO_EKF,
        .est_mode_backup = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_FULL_EKF,
},
// AOCS_CNTRL_SYS_STATE_Y_MOMENTUM_FULL_STATE_EKF
.sys_state_cfg[7] =
{
        .pwr_state = {
                .rwl0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .rwl1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .rwl2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .rwl3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .mag0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .mag1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .gyro0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .gyro1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .hss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .hss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .str0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .str1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .extSensor0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
        },
        .cntrl_mode = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__CON_YWHEEL_INIT,
        .est_mode_main = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_FULL_EKF,
        .est_mode_backup = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_GYRO_EKF,
},
// AOCS_CNTRL_SYS_STATE_3AXIS
.sys_state_cfg[8] =
{
        .pwr_state = {
                .rwl0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .rwl1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .rwl2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .rwl3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .mag0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .mag1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .gyro0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .gyro1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .hss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .hss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .str0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .str1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .extSensor0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
        },
        .cntrl_mode = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__CON_XYZWHEEL,
        .est_mode_main = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_GYRO_EKF,
        .est_mode_backup = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_FULL_EKF,
},
// AOCS_CNTRL_SYS_STATE_SUN_TRACKING
.sys_state_cfg[9] =
{
        .pwr_state = {
                .rwl0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .rwl1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .rwl2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .rwl3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .mag0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .mag1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .gyro0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .gyro1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .hss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .hss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .str0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .str1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .extSensor0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
        },
        .cntrl_mode = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__CON_SUN_TRACK,
        .est_mode_main = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_GYRO_EKF,
        .est_mode_backup = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_FULL_EKF,
},
// AOCS_CNTRL_SYS_STATE_TARGET_TRACKING
.sys_state_cfg[10] =
{
        .pwr_state = {
                .rwl0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .rwl1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .rwl2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .rwl3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .mag0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .mag1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .gyro0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .gyro1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .fss3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .hss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .hss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .str0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .str1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .extSensor0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
        },
        .cntrl_mode = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__CON_TGT_TRACK,
        .est_mode_main = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_GYRO_EKF,
        .est_mode_backup = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_FULL_EKF,
},
// AOCS_CNTRL_SYS_STATE_USER1
.sys_state_cfg[11] =
{
        .pwr_state = {
                .rwl0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .mag0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .mag1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .gyro0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .gyro1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .hss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .hss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .str0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .str1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
        },
        .cntrl_mode = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__CON_NONE,
        .est_mode_main = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_GYRO,
        .est_mode_backup = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_MAG_RKF,
},
// AOCS_CNTRL_SYS_STATE_USER2
.sys_state_cfg[12] =
{
        .pwr_state = {
                .rwl0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .mag0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .mag1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .gyro0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .gyro1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .hss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .hss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .str0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .str1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
        },
        .cntrl_mode = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__CON_NONE,
        .est_mode_main = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_GYRO,
        .est_mode_backup = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_MAG_RKF,
},
// AOCS_CNTRL_SYS_STATE_USER3
.sys_state_cfg[13] =
{
        .pwr_state = {
                .rwl0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .rwl3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .mag0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .mag1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .gyro0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_ON,
                .gyro1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss2Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .fss3Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .hss0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .hss1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .str0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .str1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor0Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
                .extSensor1Power = TYPES_CUBE_COMPUTER_COMMON_3__POWER_OFF,
        },
        .cntrl_mode = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__CON_NONE,
        .est_mode_main = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_GYRO,
        .est_mode_backup = TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__EST_MAG_RKF,
}
NVM_BLOCK_DEFAULTS_END(cubeadcs_gen2_sys_states_cfg, cubeadcs_gen2_sys_states_cfg_t)
NVM_BLOCK_DECL(cubeadcs_gen2_sys_states_cfg, cubeadcs_gen2_sys_states_cfg_t)

NVM_BLOCK_DEFAULTS_START(cubeadcs_gen2_tlm_cfg, cubeadcs_gen2_tlm_cfg_t)
    .mask[CUBEADCS_GEN2_TLM_MASK_0] = {false, false, false, false, false, false, false, false},
    .mask[CUBEADCS_GEN2_TLM_MASK_1] = {false, false, false, false, false, false, false, false},
    .mask[CUBEADCS_GEN2_TLM_MASK_2] = {false, false, false, false, false, false, false, false},
    .mask[CUBEADCS_GEN2_TLM_MASK_3] = {false, false, false, false, false, false, false, false},
    .mask[CUBEADCS_GEN2_TLM_MASK_4] = {false, false, false, false, false, false, false, false}
NVM_BLOCK_DEFAULTS_END(cubeadcs_gen2_tlm_cfg, cubeadcs_gen2_tlm_cfg_t)
NVM_BLOCK_DECL(cubeadcs_gen2_tlm_cfg, cubeadcs_gen2_tlm_cfg_t)

NVM_BLOCK_DEFAULTS_START(adcs_cms_status, adcs_cms_status_t)
    .cms_status = 0
NVM_BLOCK_DEFAULTS_END(adcs_cms_status, adcs_cms_status_t)
NVM_BLOCK_DECL(adcs_cms_status, adcs_cms_status_t)

NVM_BLOCK_DEFAULTS_START(fault_index, fault_index_t)
    0,                    // next_free_slot_index
    MAX_FAULT_BLOCKS_CNT  // free_slots (must match the number of fault_block_x blocks reserved for fault storage
NVM_BLOCK_DEFAULTS_END(fault_index, fault_index_t)
NVM_BLOCK_DECL(fault_index, fault_index_t)

NVM_BLOCK_DECL(fault_block_0, fault_block_t)
NVM_BLOCK_DECL(fault_block_1, fault_block_t)
NVM_BLOCK_DECL(fault_block_2, fault_block_t)
NVM_BLOCK_DECL(fault_block_3, fault_block_t)
NVM_BLOCK_DECL(fault_block_4, fault_block_t)


NVM_BLOCK_DEFAULTS_START(gpo_config, gpo_config_t)
.pin_value[0] = false, // OBC OUT 1
.pin_value[1] = false, // OBC OUT 2
.pin_value[2] = false, // OBC OUT 3
.pin_value[3] = false, // OBC OUT 5
.pin_value[4] = false, // OBC OUT 4 and 6
.pin_value[5] = false, // OBC OUT 7
.pin_value[6] = false  // OBC OUT 8
NVM_BLOCK_DEFAULTS_END(gpo_config, gpo_config_t)
NVM_BLOCK_DECL(gpo_config, gpo_config_t)

NVM_BLOCK_DEFAULTS_START(onboard_sched_nvm_data, onboard_sched_nvm_data_t)
    .active_slot_offset = 0,
    .sched_state = ONBOARD_SCHED_SCHEDSTATE_STOPPED,
    .last_schedule = {0}
NVM_BLOCK_DEFAULTS_END(onboard_sched_nvm_data, onboard_sched_nvm_data_t)
NVM_BLOCK_DECL(onboard_sched_nvm_data, onboard_sched_nvm_data_t)

NVM_BLOCK_DEFAULTS_START(fdir_srv_nvm_data, fdir_srv_nvm_data_t)
    .fault_automatic_clear_limit = FDIR_LEVEL_MAJOR,
    .fault_detection_active =
    {
        [FDIR_FAULT_S_BAND_TMTC_CMD_EXEC_FAILURE] = false,
        [FDIR_FAULT_UHF_CMD_EXEC_FAILURE] = false,
        [FDIR_FAULT_GNSS_CMD_EXEC_FAILURE] = false,
        [FDIR_FAULT_SDR_CMD_EXEC_FAILURE] = false,
        [FDIR_FAULT_S_X_BAND_CMD_EXEC_FAILURE] = false,
        [FDIR_FAULT_THRUSTER_CMD_EXEC_FAILURE] = false,
        [FDIR_FAULT_THRUSTER_FIRING_DENIAL] = false,
        [FDIR_FAULT_THRUSTER_GROUND_TEST_DENIAL] = false,
        [FDIR_FAULT_THRUSTER_PREPARING_DENIAL] = false,
        [FDIR_FAULT_THRUSTER_SELF_TEST_FAILURE] = false,
        [FDIR_FAULT_THRUSTER_GROUND_TEST_FAILURE] = false,
        [FDIR_FAULT_EPS_BATT_VOLTAGE_BELOW_SAFE] = false,
// begin EPS BP FDIR generated code

        [FDIR_FAULT_EPS_INST0_CMD_EXEC_FAILURE] = FDIR_EPS_INST0_CMD_EXEC_FAILURE_DETECTION_STATE,
        [FDIR_FAULT_EPS_INST0_BATT_VOLTAGE_BELOW_SAFE] = FDIR_EPS_INST0_BATT_VOLTAGE_BELOW_SAFE_DETECTION_STATE,
        [FDIR_FAULT_EPS_INST0_BATT_TEMP_BELOW_SAFE] = FDIR_EPS_INST0_BATT_TEMP_BELOW_SAFE_DETECTION_STATE,
        [FDIR_FAULT_EPS_INST0_BATT_TEMP_ABOVE_SAFE] = FDIR_EPS_INST0_BATT_TEMP_ABOVE_SAFE_DETECTION_STATE,
        [FDIR_FAULT_EPS_INST1_CMD_EXEC_FAILURE] = FDIR_EPS_INST1_CMD_EXEC_FAILURE_DETECTION_STATE,
        [FDIR_FAULT_EPS_INST1_BATT_VOLTAGE_BELOW_SAFE] = FDIR_EPS_INST1_BATT_VOLTAGE_BELOW_SAFE_DETECTION_STATE,
        [FDIR_FAULT_EPS_INST1_BATT_TEMP_BELOW_SAFE] = FDIR_EPS_INST1_BATT_TEMP_BELOW_SAFE_DETECTION_STATE,
        [FDIR_FAULT_EPS_INST1_BATT_TEMP_ABOVE_SAFE] = FDIR_EPS_INST1_BATT_TEMP_ABOVE_SAFE_DETECTION_STATE,
// end EPS BP FDIR generated code
// begin EPS_III BP FDIR generated code

        [FDIR_FAULT_EPSIII_BP_INST0_CMD_EXEC_FAILURE] = FDIR_EPSIII_BP_INST0_CMD_EXEC_FAILURE_DETECTION_STATE,
        [FDIR_FAULT_EPSIII_BP_INST0_BATT_VOLTAGE_BELOW_SAFE] = FDIR_EPSIII_BP_INST0_BATT_VOLTAGE_BELOW_SAFE_DETECTION_STATE,
        [FDIR_FAULT_EPSIII_BP_INST0_BATT_TEMP_BELOW_SAFE] = FDIR_EPSIII_BP_INST0_BATT_TEMP_BELOW_SAFE_DETECTION_STATE,
        [FDIR_FAULT_EPSIII_BP_INST0_BATT_TEMP_ABOVE_SAFE] = FDIR_EPSIII_BP_INST0_BATT_TEMP_ABOVE_SAFE_DETECTION_STATE,
// end EPS_III BP FDIR generated code
// begin EPS_III PDM_A FDIR generated code

        [FDIR_FAULT_EPSIII_PDM_A_INST0_CMD_EXEC_FAILURE] = FDIR_EPSIII_PDM_A_INST0_CMD_EXEC_FAILURE_DETECTION_STATE,
// end EPS_III PDM_A FDIR generated code
// begin EPS_III INPUT_STAGE FDIR generated code

        [FDIR_FAULT_EPSIII_INPUT_STAGE_INST0_CMD_EXEC_FAILURE] = FDIR_EPSIII_INPUT_STAGE_INST0_CMD_EXEC_FAILURE_DETECTION_STATE,
// end EPS_III INPUT_STAGE FDIR generated code
        [FDIR_FAULT_ADCS_CMD_EXEC_FAILURE] = false,
        [FDIR_FAULT_ADCS_RWL_NOT_IN_APPL_MODE] = false,
        [FDIR_FAULT_ADCS_RWL_COMM_ERROR] = false,
        [FDIR_FAULT_ADCS_RWL_FAILURE] = false,
        [FDIR_FAULT_ADCS_RWL_SETUP_ERROR] = false,
        [FDIR_FAULT_ADCS_RWL_DISCOVERY_ERROR] = false,
        [FDIR_FAULT_ADCS_RWL_PORT_VALIDATION_ERROR] = false,
        [FDIR_FAULT_ADCS_PRIM_MAGN_NOT_IN_APPL_MODE] = false,
        [FDIR_FAULT_ADCS_PRIM_MAGN_COMM_ERROR] = false,
        [FDIR_FAULT_ADCS_PRIM_MAGN_FAILURE] = false,
        [FDIR_FAULT_ADCS_PRIM_MAGN_SETUP_ERROR] = false,
        [FDIR_FAULT_ADCS_PRIM_MAGN_DISCOVERY_ERROR] = false,
        [FDIR_FAULT_ADCS_PRIM_MAGN_PORT_VALIDATION_ERROR] = false,
        [FDIR_FAULT_ADCS_BOTH_MAGN_NOT_IN_APPL_MODE] = false,
        [FDIR_FAULT_ADCS_BOTH_MAGN_COMM_ERROR] = false,
        [FDIR_FAULT_ADCS_BOTH_MAGN_FAILURE] = false,
        [FDIR_FAULT_ADCS_BOTH_MAGN_SETUP_ERROR] = false,
        [FDIR_FAULT_ADCS_BOTH_MAGN_DISCOVERY_ERROR] = false,
        [FDIR_FAULT_ADCS_BOTH_MAGN_PORT_VALIDATION_ERROR] = false,
        [FDIR_FAULT_ADCS_PRIM_GYRO_VOLTAGE_ERROR] = false,
        [FDIR_FAULT_ADCS_PRIM_GYRO_CRITICAL_ERROR] = false,
        [FDIR_FAULT_ADCS_BOTH_GYRO_VOLTAGE_ERROR] = false,
        [FDIR_FAULT_ADCS_BOTH_GYRO_CRITICAL_ERROR] = false,
        [FDIR_FAULT_ADCS_CONTROL_LOOP_FAILURE] = false,
        [FDIR_FAULT_ADCS_CONTROL_LOOP_CRITICAL_ERROR] = false,
        [FDIR_FAULT_ADCS_CONFIGURATION_VALIDATION_ERROR] = false,
        [FDIR_FAULT_ADCS_CONFIGURATION_PERSIST_ERROR] = false,
        [FDIR_FAULT_ADCS_VIRTUAL_WATCHDOG_ERROR] = false,
        [FDIR_FAULT_ADCS_REACTION_WHEEL_ABOVE_10000RPM] = false,
        [FDIR_FAULT_DUMMY] = false,
        [FDIR_FAULT_WARNING] = false,
        [FDIR_FAULT_MINOR] = false,
        [FDIR_FAULT_MAJOR] = false,
        [FDIR_FAULT_CRITICAL] = false,
    }
NVM_BLOCK_DEFAULTS_END(fdir_srv_nvm_data, fdir_srv_nvm_data_t)
NVM_BLOCK_DECL(fdir_srv_nvm_data, fdir_srv_nvm_data_t)

NVM_BLOCK_DEFAULTS_START(conops_nvm_data, conops_nvm_data_t)
    .force_enable_payload = SAFE_FALSE
NVM_BLOCK_DEFAULTS_END(conops_nvm_data, conops_nvm_data_t)
NVM_BLOCK_DECL(conops_nvm_data, conops_nvm_data_t)

NVM_BLOCK_DEFAULTS_START(xband_fe_cfg, xband_fe_config_t)
    .target_node_addr = 8,
    .port = 10,
    .prio = CSP_PRIO_NORM,
    .opts = CSP_O_NONE
NVM_BLOCK_DEFAULTS_END(xband_fe_cfg, xband_fe_config_t)
NVM_BLOCK_DECL(xband_fe_cfg, xband_fe_config_t)

NVM_BLOCK_DEFAULTS_START(nvm_block_gnss_comm_settings, nvm_block_gnss_comm_settings_t)
    .gnss_comm_uart_baudrate = GNSS_BAUDRATE_BAUD_460800_BPS
NVM_BLOCK_DEFAULTS_END(nvm_block_gnss_comm_settings, nvm_block_gnss_comm_settings_t)
NVM_BLOCK_DECL(nvm_block_gnss_comm_settings, nvm_block_gnss_comm_settings_t)

NVM_BLOCK_DEFAULTS_START(comm_loss_wd_nvm_data, comm_loss_wd_nvm_data_t)
    .comm_loss_wd_timeout_period_min = 4320, // Default timeout of 72h is 4320 minutes.
    .comm_loss_wd_enable = true          // Enable by default.
NVM_BLOCK_DEFAULTS_END(comm_loss_wd_nvm_data, comm_loss_wd_nvm_data_t)
NVM_BLOCK_DECL(comm_loss_wd_nvm_data, comm_loss_wd_nvm_data_t)

NVM_BLOCK_DEFAULTS_START(cubeadcs_gen2_fdir_counter, cubeadcs_gen2_fdir_counter_t)
    .cubeadcs_gen2_counter_for_power_cycles = 0,
    .cubeadcs_gen2_counter_for_resets = 0,
    .cubeadcs_gen2_reset_flag = true
NVM_BLOCK_DEFAULTS_END(cubeadcs_gen2_fdir_counter, cubeadcs_gen2_fdir_counter_t)
NVM_BLOCK_DECL(cubeadcs_gen2_fdir_counter, cubeadcs_gen2_fdir_counter_t)

NVM_BLOCK_DEFAULTS_START(task_stat_config_nvm, task_stat_config_nvm_t)
    .enabled = false,
    .logging = false,
    .priority = 8,
    .period = 1000,
    .id_table_file = "task_id_table.txt"
NVM_BLOCK_DEFAULTS_END(task_stat_config_nvm, task_stat_config_nvm_t)
NVM_BLOCK_DECL(task_stat_config_nvm, task_stat_config_nvm_t)

NVM_BLOCK_DEFAULTS_START(task_stat_config_specific_nvm, task_stat_config_specific_nvm_t)
    .enabled = {false},
    .logging = {false}
NVM_BLOCK_DEFAULTS_END(task_stat_config_specific_nvm, task_stat_config_specific_nvm_t)
NVM_BLOCK_DECL(task_stat_config_specific_nvm, task_stat_config_specific_nvm_t)


