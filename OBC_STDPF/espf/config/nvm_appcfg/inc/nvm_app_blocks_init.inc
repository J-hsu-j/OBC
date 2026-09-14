    // reserved block to make sure app blocks always start from a fixed index in NVM block list
    [NVM_RESERVED] =
    {
            .u32Size = sizeof(reserved_dummy_t),
            .eBlockType = EBLOCKTYPE_SINGLE,
            .pRamMirrorBuf = (uint8_t * const) &reserved_dummy,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(reserved_dummy),
            .u16ConfigBitfield = 0U,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_BEACONS_GENERAL] =
    {
            .u32Size = sizeof(beacons_cfg_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &beacons_cfg,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(beacons_cfg),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_BEACONS_PRESETS] =
    {
            .u32Size = sizeof(beacons_presets_cfg_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &beacons_presets_cfg,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(beacons_presets_cfg),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_APP_BLOCK_CONOPS_CONFIG] =
    {
            .u32Size = sizeof(conops_config_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &conops_config,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(conops_config),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_TELEMETRY_GENERAL_0] =
    {
            .u32Size = sizeof(telemetry_cfg_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &telemetry_cfg_0,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(telemetry_cfg_0),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_TELEMETRY_PRESETS_0] =
    {
            .u32Size = sizeof(telemetry_preset_cfg_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &telemetry_preset_cfg_0,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(telemetry_preset_cfg_0),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_TELEMETRY_FILE_CFG_0] =
    {
            .u32Size = sizeof(telemetry_file_cfg_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &telemetry_file_cfg_0,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(telemetry_file_cfg_0),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_TELEMETRY_PERSISTENT_DATA_0] =
    {
            .u32Size = sizeof(telemetry_persistent_data_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &telemetry_persistent_data_0,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(telemetry_persistent_data_0),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_TELEMETRY_GENERAL_1] =
    {
            .u32Size = sizeof(telemetry_cfg_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &telemetry_cfg_1,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(telemetry_cfg_1),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_TELEMETRY_PRESETS_1] =
    {
            .u32Size = sizeof(telemetry_preset_cfg_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &telemetry_preset_cfg_1,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(telemetry_preset_cfg_1),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_TELEMETRY_FILE_CFG_1] =
    {
            .u32Size = sizeof(telemetry_file_cfg_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &telemetry_file_cfg_1,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(telemetry_file_cfg_1),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_TELEMETRY_PERSISTENT_DATA_1] =
    {
            .u32Size = sizeof(telemetry_persistent_data_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &telemetry_persistent_data_1,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(telemetry_persistent_data_1),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_EPS_M_CONFIG] =
    {
            .u32Size = sizeof(EPS_M_Config_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &EPSM_Config,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(EPSM_Config),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_CUBEADCS_ERR_HANDL_CONFIG] =
    {
            .u32Size = sizeof(cubeadcs_err_handl_cfg_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &cubeadcs_err_handl_cfg,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(cubeadcs_err_handl_cfg),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_CUBEADCS_STATUS] =
    {
            .u32Size = sizeof(cubeadcs_status_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &cubeadcs_status,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(cubeadcs_status),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_I2C_CONFIG] =
    {
            .u32Size = sizeof(i2c_config_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &i2c_config,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(i2c_config),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_CUBEADCS_ANGLE_LIMITS] =
    {
            .u32Size = sizeof(cubeadcs_angle_limits_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &cubeadcs_angle_limits,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(cubeadcs_angle_limits),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_AOCS_PM_CONFIG] =
    {
            .u32Size = sizeof(aocs_pm_config_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &aocs_pm_config,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(aocs_pm_config),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_AOCS_PM_THRESHOLDS] =
    {
            .u32Size = sizeof(aocs_pm_thresholds_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &aocs_pm_threshold,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(aocs_pm_threshold),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_COORDINATE_FRAMES] =
    {
            .u32Size = sizeof(coordsys_frames_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &coordsys_frames,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(coordsys_frames),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_SDS_SENS_READ_FREQ_CFG] =
    {
            .u32Size = sizeof(sds_sens_read_freq_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &sds_sens_read_freq,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(sds_sens_read_freq),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_CRYPTO_CFG] =
    {
            .u32Size = sizeof(crypto_cfg_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &crypto_cfg,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(crypto_cfg),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_CUBEADCS_SIMULATION_MODE] =
    {
            .u32Size = sizeof(cubeadcs_sim_mode_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &cubeadcs_sim_mode,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(cubeadcs_sim_mode),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_RTC_CALIB_DATA] =
    {
            .u32Size = sizeof(rtc_calib_data_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &rtc_calib_data,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(rtc_calib_data),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_GYROSCOPE_CONFIG] =
    {
            .u32Size = sizeof(gyroscope_configs_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &gyroscope_configs,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(gyroscope_configs),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_FM_STATS] =
    {
            .u32Size = sizeof(fm_stats_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &fm_stats,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(fm_stats),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_CUBEADCS_SYS_STATE_CFG] =
    {
            .u32Size = sizeof(cubeADCS_sys_state_cfg_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &cubeADCS_sys_state_cfg,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(cubeADCS_sys_state_cfg),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_MAC_ADDRESS_BOOK] =
    {
            .u32Size = sizeof(mac_address_book_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &mac_address_book,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(mac_address_book),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_CUBEADCS_GEN2_SYS_STATE_CFG] =
    {
            .u32Size = sizeof(cubeadcs_gen2_sys_states_cfg_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &cubeadcs_gen2_sys_states_cfg,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(cubeadcs_gen2_sys_states_cfg),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_CUBEADCS_GEN2_TLM_CFG] =
    {
            .u32Size = sizeof(cubeadcs_gen2_tlm_cfg_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &cubeadcs_gen2_tlm_cfg,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(cubeadcs_gen2_tlm_cfg),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_ADCS_CMS_STATUS] =
    {
            .u32Size = sizeof(adcs_cms_status_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &adcs_cms_status,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(adcs_cms_status),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_FAULT_INDEX] =
    {
            .u32Size = sizeof(fault_index_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &fault_index,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(fault_index),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_FAULT_DATA0] =
    {
            .u32Size = sizeof(fault_block_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &fault_block_0,
            .pBufDefaults = (const uint8_t * const) NULL,
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_FAULT_DATA1] =
    {
            .u32Size = sizeof(fault_block_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &fault_block_1,
            .pBufDefaults = (const uint8_t * const) NULL,
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_FAULT_DATA2] =
    {
            .u32Size = sizeof(fault_block_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &fault_block_2,
            .pBufDefaults = (const uint8_t * const) NULL,
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_FAULT_DATA3] =
    {
            .u32Size = sizeof(fault_block_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &fault_block_3,
            .pBufDefaults = (const uint8_t * const) NULL,
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_FAULT_DATA4] =
    {
            .u32Size = sizeof(fault_block_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &fault_block_4,
            .pBufDefaults = (const uint8_t * const) NULL,
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_GPO_CONFIG] =
    {
            .u32Size = sizeof(gpo_config_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &gpo_config,
            .pBufDefaults = (const uint8_t * const) &NVM_BLOCK_DEFAULTS(gpo_config),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_SCHEDULER_DATA] =
    {
            .u32Size = sizeof(onboard_sched_nvm_data_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &onboard_sched_nvm_data,
            .pBufDefaults = (const uint8_t * const)&NVM_BLOCK_DEFAULTS(onboard_sched_nvm_data),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_FDIR_SRV_DATA] =
    {
            .u32Size = sizeof(fdir_srv_nvm_data_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &fdir_srv_nvm_data,
            .pBufDefaults = (const uint8_t * const)&NVM_BLOCK_DEFAULTS(fdir_srv_nvm_data),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_CONOPS_DATA] =
    {
            .u32Size = sizeof(conops_nvm_data_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &conops_nvm_data,
            .pBufDefaults = (const uint8_t * const)&NVM_BLOCK_DEFAULTS(conops_nvm_data),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_XBAND_FE_CFG] =
    {
            .u32Size = sizeof(xband_fe_config_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &xband_fe_cfg,
            .pBufDefaults = (const uint8_t * const)&NVM_BLOCK_DEFAULTS(xband_fe_cfg),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_GNSS_COMM_SETTINGS] =
    {
            .u32Size = sizeof(nvm_block_gnss_comm_settings_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &nvm_block_gnss_comm_settings,
            .pBufDefaults = (const uint8_t * const)&NVM_BLOCK_DEFAULTS(nvm_block_gnss_comm_settings),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_COMM_LOSS_WD] =
    {
            .u32Size = sizeof(comm_loss_wd_nvm_data_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &comm_loss_wd_nvm_data,
            .pBufDefaults = (const uint8_t * const)&NVM_BLOCK_DEFAULTS(comm_loss_wd_nvm_data),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_CUBEADCS_GEN2_FDIR_CNT] =
    {
            .u32Size = sizeof(cubeadcs_gen2_fdir_counter_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &cubeadcs_gen2_fdir_counter,
            .pBufDefaults = (const uint8_t * const)&NVM_BLOCK_DEFAULTS(cubeadcs_gen2_fdir_counter),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_TASK_STATS_CONFIG] =
    {
            .u32Size = sizeof(task_stat_config_nvm_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &task_stat_config_nvm,
            .pBufDefaults = (const uint8_t * const)&NVM_BLOCK_DEFAULTS(task_stat_config_nvm),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    },
    [NVM_BLOCK_TASK_STATS_CONFIG_PER_TASK] =
    {
            .u32Size = sizeof(task_stat_config_specific_nvm_t),
            .eBlockType = EBLOCKTYPE_REDUNDANT,
            .pRamMirrorBuf = (uint8_t * const) &task_stat_config_specific_nvm,
            .pBufDefaults = (const uint8_t * const)&NVM_BLOCK_DEFAULTS(task_stat_config_specific_nvm),
            .u16ConfigBitfield = BLKCFG_CRC_PROTECTED,
            .u32FixedAddress = 0x00000000
    }
