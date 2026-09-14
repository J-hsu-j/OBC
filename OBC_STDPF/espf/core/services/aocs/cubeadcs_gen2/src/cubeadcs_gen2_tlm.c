/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup cubeadcs_gen2
 * @{
 *
 * @file     cubeadcs_gen2_tlm.c
 * @brief    Cubeadcs Gen2 telemetry source.
 *
 * @}
 */

#include "cubeadcs_gen2_tlm.h"
#include "cubeadcs_gen2_gw.h"

#include "assertions.h"
#include "es_exeh.h"
#include "nvm.h"

#include "datacache.h"
#include "fdir_srv.h"

/** @brief Reaction wheel acceptable RPM limit */
#define CUBEADCS_GEN2_RWL_FDIR_LIMIT (10000)

/** @typedef p_tlm_api_handl_t
 *  @brief Function pointer to a telemetry frame API and handler
 */
typedef void (*p_tlm_api_handl_t)(void);

/**
 * @brief Helper function for FDIR logic for telemetry frame 205 - Wheel RPM
 */
STATIC void fs_cubeadcs_gen2_tlm_wheel_rpm_fdir(void);

STATIC void fs_cubeadcs_gen2_tlm_get_health_tlm_for_cubenode_pst3s(void);
STATIC void fs_cubeadcs_gen2_tlm_get_health_tlm_for_cubemag_magnetometer(void);
STATIC void fs_cubeadcs_gen2_tlm_get_health_tlm_for_cubesense_sun(void);
STATIC void fs_cubeadcs_gen2_tlm_get_torquer_current_measurements(void);
STATIC void fs_cubeadcs_gen2_tlm_get_raw_cubesense_sun_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_raw_external_sensor_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_controller_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_backup_estimator_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_models_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_calibrated_gnss_sensor_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_calibrated_hss_sensor_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_calibrated_mag_sensor_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_calibrated_fss_sensor_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_raw_cubesense_earth_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_raw_mag_sensor_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_raw_css_sensor_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_raw_gyr_sensor_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_raw_rwl_sensor_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_calibrated_css_sensor_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_calibrated_gyr_sensor_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_calibrated_str_sensor_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_calibrated_rwl_sensor_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_main_estimator_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_main_estimator_high_resolution_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_raw_gnss_sensor_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_raw_pst3s_star_tracker_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_acp_execution_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_cubecomputer_health(void);
STATIC void fs_cubeadcs_gen2_tlm_get_health_telemetry_for_cubesense_earth(void);
STATIC void fs_cubeadcs_gen2_tlm_get_health_telemetry_for_reaction_wheels(void);
STATIC void fs_cubeadcs_gen2_tlm_get_health_telemetry_for_cubenode_nssrwl(void);
STATIC void fs_cubeadcs_gen2_tlm_get_raw_nssrwl_sensor_telemetry(void);
STATIC void fs_cubeadcs_gen2_tlm_get_health_telemetry_for_cubestar(void);
STATIC void fs_cubeadcs_gen2_tlm_get_mag_sensing_config_telemtry(void);

/** @brief 2D array of function pointers to telemetry frames */
const p_tlm_api_handl_t tlm_api_handl[CUBEADCS_GEN2_TLM_MASK_MAX][CUBEADCS_GEN2_TLM_MASK_BYTES_MAX] = {
  // Mask Byte 0
    {
     fs_cubeadcs_gen2_tlm_get_health_tlm_for_cubenode_pst3s,
     fs_cubeadcs_gen2_tlm_get_health_tlm_for_cubemag_magnetometer,
     fs_cubeadcs_gen2_tlm_get_health_tlm_for_cubesense_sun,
     fs_cubeadcs_gen2_tlm_get_torquer_current_measurements,
     fs_cubeadcs_gen2_tlm_get_raw_cubesense_sun_telemetry,
     fs_cubeadcs_gen2_tlm_get_raw_external_sensor_telemetry,
     fs_cubeadcs_gen2_tlm_get_controller_telemetry,
     fs_cubeadcs_gen2_tlm_get_backup_estimator_telemetry,
     },
 // Mask Byte 1
    {
     fs_cubeadcs_gen2_tlm_get_models_telemetry,
     fs_cubeadcs_gen2_tlm_get_calibrated_gnss_sensor_telemetry,
     fs_cubeadcs_gen2_tlm_get_calibrated_hss_sensor_telemetry,
     fs_cubeadcs_gen2_tlm_get_calibrated_mag_sensor_telemetry,
     fs_cubeadcs_gen2_tlm_get_calibrated_fss_sensor_telemetry,
     fs_cubeadcs_gen2_tlm_get_raw_cubesense_earth_telemetry,
     fs_cubeadcs_gen2_tlm_get_raw_mag_sensor_telemetry,
     fs_cubeadcs_gen2_tlm_get_raw_css_sensor_telemetry,
     },
 // Mask Byte 2
    {
     fs_cubeadcs_gen2_tlm_get_raw_gyr_sensor_telemetry,
     fs_cubeadcs_gen2_tlm_get_raw_rwl_sensor_telemetry,
     fs_cubeadcs_gen2_tlm_get_calibrated_css_sensor_telemetry,
     fs_cubeadcs_gen2_tlm_get_calibrated_gyr_sensor_telemetry,
     fs_cubeadcs_gen2_tlm_get_calibrated_str_sensor_telemetry,
     fs_cubeadcs_gen2_tlm_get_calibrated_rwl_sensor_telemetry,
     fs_cubeadcs_gen2_tlm_get_main_estimator_telemetry,
     fs_cubeadcs_gen2_tlm_get_main_estimator_high_resolution_telemetry,
     },
 // Mask Byte 3
    {
     fs_cubeadcs_gen2_tlm_get_raw_gnss_sensor_telemetry,
     fs_cubeadcs_gen2_tlm_get_raw_pst3s_star_tracker_telemetry,
     fs_cubeadcs_gen2_tlm_get_acp_execution_telemetry,
     fs_cubeadcs_gen2_tlm_get_cubecomputer_health,
     fs_cubeadcs_gen2_tlm_get_health_telemetry_for_cubesense_earth,
     fs_cubeadcs_gen2_tlm_get_health_telemetry_for_reaction_wheels,
     fs_cubeadcs_gen2_tlm_get_health_telemetry_for_cubenode_nssrwl,
     fs_cubeadcs_gen2_tlm_get_raw_nssrwl_sensor_telemetry,
     },
 // Mask Byte 4
    {
     fs_cubeadcs_gen2_tlm_get_health_telemetry_for_cubestar,
     fs_cubeadcs_gen2_tlm_get_mag_sensing_config_telemtry,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     }
};

void cubeadcs_gen2_tlm_get_tlm(void)
{
    cubeadcs_gen2_tlm_cfg_t tlm_cfg;

    Nvm_GetBlockById(NVM_BLOCK_CUBEADCS_GEN2_TLM_CFG, (void *)&tlm_cfg);

    for (uint8_t byte = 0; byte < CUBEADCS_GEN2_TLM_MASK_MAX; byte++)
    {
        for (uint8_t mask = 0; mask < CUBEADCS_GEN2_TLM_MASK_BYTES_MAX; mask++)
        {
            if ((NULL != tlm_api_handl[byte][mask]) &&
                (true == tlm_cfg.mask[byte][mask]))
            {
                tlm_api_handl[byte][mask]();
            }
        }
    }
}

/** @brief Getter for telemetry frame 166 - Health telemetry for CubeNode PST3S */
STATIC void fs_cubeadcs_gen2_tlm_get_health_tlm_for_cubenode_pst3s(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmStrPst3sHealth) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_166_t));

    TypesCubeComputerControlProgram8_TlmStrPst3sHealth tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrPst3sHealthRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_166_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_166_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 167 - Health telemetry for CubeMag magnetometer */
STATIC void fs_cubeadcs_gen2_tlm_get_health_tlm_for_cubemag_magnetometer(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmCubeMagHealth) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_167_t));

    TypesCubeComputerControlProgram8_TlmCubeMagHealth tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmCubeMagHealthRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_167_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_167_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 168 - Health telemetry for CubeSense Sun */
STATIC void fs_cubeadcs_gen2_tlm_get_health_tlm_for_cubesense_sun(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmFssCubeSenseSunHealth) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_168_t));

    TypesCubeComputerControlProgram8_TlmFssCubeSenseSunHealth tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmFssCubeSenseSunHealthRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_168_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_168_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 169 - Torquer Current measurements */
STATIC void fs_cubeadcs_gen2_tlm_get_torquer_current_measurements(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmTorquerCurrents) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_169_t));

    TypesCubeComputerControlProgram8_TlmTorquerCurrents tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmTorquerCurrentsRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_169_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_169_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 170 - Raw CubeSense Sun telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_raw_cubesense_sun_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmFssCubeSenseSunRaw) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_170_t));

    TypesCubeComputerControlProgram8_TlmFssCubeSenseSunRaw tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmFssCubeSenseSunRawRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_170_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_170_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 171 - Raw external sensor telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_raw_external_sensor_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmExtSensorRaw) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_171_t));

    TypesCubeComputerControlProgram8_TlmExtSensorRaw tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmExtSensorRawRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_171_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_171_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 172 - Controller telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_controller_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmController) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_172_t));

    TypesCubeComputerControlProgram8_TlmController tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmControllerRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_172_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_172_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 173 - Backup estimator telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_backup_estimator_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmEstimatorBackup) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_173_t));

    TypesCubeComputerControlProgram8_TlmEstimatorBackup tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmEstimatorBackupRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_173_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_173_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 174 - Models telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_models_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmModels) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_174_t));

    TypesCubeComputerControlProgram8_TlmModels tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmModelsRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_174_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_174_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 175 - Calibrated GNSS sensor telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_calibrated_gnss_sensor_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmSensorCalGnss) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_175_t));

    TypesCubeComputerControlProgram8_TlmSensorCalGnss tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalGnssRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_175_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_175_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 176 - Calibrated HSS sensor telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_calibrated_hss_sensor_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmSensorCalHss) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_176_t));

    TypesCubeComputerControlProgram8_TlmSensorCalHss tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalHssRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_176_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_176_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 177 - Calibrated MAG sensor telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_calibrated_mag_sensor_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmSensorCalMag) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_177_t));

    TypesCubeComputerControlProgram8_TlmSensorCalMag tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalMagRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_177_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_177_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 178 - Calibrated FSS sensor telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_calibrated_fss_sensor_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmSensorCalFss) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_178_t));

    TypesCubeComputerControlProgram8_TlmSensorCalFss tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalFssRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_178_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_178_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 179 - Raw CubeSense Earth telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_raw_cubesense_earth_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmHssCubeSenseEarthRaw) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_179_t));

    TypesCubeComputerControlProgram8_TlmHssCubeSenseEarthRaw tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmHssCubeSenseEarthRawRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_179_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_179_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 180 - Raw MAG sensor telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_raw_mag_sensor_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmSensorRawMag) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_180_t));

    TypesCubeComputerControlProgram8_TlmSensorRawMag tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawMagRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_180_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_180_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 203 - Raw CSS sensor telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_raw_css_sensor_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmSensorRawCss) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_203_t));

    TypesCubeComputerControlProgram8_TlmSensorRawCss tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawCssRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_203_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_203_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 204 - Raw GYR sensor telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_raw_gyr_sensor_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmSensorRawGyro) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_204_t));

    TypesCubeComputerControlProgram8_TlmSensorRawGyro tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawGyroRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_204_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_204_t *)&tlm);
    }
}

STATIC void fs_cubeadcs_gen2_tlm_wheel_rpm_fdir(void)
{
    TypesCubeComputerControlProgram8_TlmSensorRawRwl tlm;
    // FDIR Agent
    (void)dc_get_cubeadcs_gen2_tlm_frame_205_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_205_t *)&tlm);
    bool fdir_fault_set = false;
    if ((true == tlm.rwl0IsValid) && ((tlm.rwl0MeasSpeed > CUBEADCS_GEN2_RWL_FDIR_LIMIT) || (tlm.rwl0MeasSpeed < -CUBEADCS_GEN2_RWL_FDIR_LIMIT)))
    {
        fdir_fault_set = true;
        fdir_srv_log_if_clear(FDIR_FAULT_ADCS_REACTION_WHEEL_ABOVE_10000RPM, FDIR_AGENT_CUBE_ADCS_GEN2, "Reaction Wheel 0 speed: %d", tlm.rwl0MeasSpeed);
    }
    if ((true == tlm.rwl1IsValid) && ((tlm.rwl1MeasSpeed > CUBEADCS_GEN2_RWL_FDIR_LIMIT) || (tlm.rwl1MeasSpeed < -CUBEADCS_GEN2_RWL_FDIR_LIMIT)))
    {
        fdir_fault_set = true;
        fdir_srv_log_if_clear(FDIR_FAULT_ADCS_REACTION_WHEEL_ABOVE_10000RPM, FDIR_AGENT_CUBE_ADCS_GEN2, "Reaction Wheel 1 speed: %d", tlm.rwl1MeasSpeed);
    }
    if ((true == tlm.rwl2IsValid) && ((tlm.rwl2MeasSpeed > CUBEADCS_GEN2_RWL_FDIR_LIMIT) || (tlm.rwl2MeasSpeed < -CUBEADCS_GEN2_RWL_FDIR_LIMIT)))
    {
        fdir_fault_set = true;
        fdir_srv_log_if_clear(FDIR_FAULT_ADCS_REACTION_WHEEL_ABOVE_10000RPM, FDIR_AGENT_CUBE_ADCS_GEN2, "Reaction Wheel 2 speed: %d", tlm.rwl2MeasSpeed);
    }
    if ((true == tlm.rwl3IsValid) && ((tlm.rwl3MeasSpeed > CUBEADCS_GEN2_RWL_FDIR_LIMIT) || (tlm.rwl3MeasSpeed < -CUBEADCS_GEN2_RWL_FDIR_LIMIT)))
    {
        fdir_fault_set = true;
        fdir_srv_log_if_clear(FDIR_FAULT_ADCS_REACTION_WHEEL_ABOVE_10000RPM, FDIR_AGENT_CUBE_ADCS_GEN2, "Reaction Wheel 3 speed: %d", tlm.rwl3MeasSpeed);
    }
    fdir_srv_fault_set_state(FDIR_FAULT_ADCS_REACTION_WHEEL_ABOVE_10000RPM, FDIR_AGENT_CUBE_ADCS_GEN2, fdir_fault_set, NULL);
}

/** @brief Getter for telemetry frame 205 - Raw RWL sensor telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_raw_rwl_sensor_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmSensorRawRwl) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_205_t));

    TypesCubeComputerControlProgram8_TlmSensorRawRwl tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawRwlRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_205_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_205_t *)&tlm);

        fs_cubeadcs_gen2_tlm_wheel_rpm_fdir();
    }
}

/** @brief Getter for telemetry frame 206 - Calibrated CSS sensor telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_calibrated_css_sensor_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmSensorCalCss) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_206_t));

    TypesCubeComputerControlProgram8_TlmSensorCalCss tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalCssRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_206_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_206_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 207 - Calibrated GYR sensor telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_calibrated_gyr_sensor_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmSensorCalGyro) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_207_t));

    TypesCubeComputerControlProgram8_TlmSensorCalGyro tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalGyroRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_207_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_207_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 208 - Calibrated STR sensor telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_calibrated_str_sensor_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmSensorCalStr) == (sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_208_1_t) + sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_208_2_t)));

    TypesCubeComputerControlProgram8_TlmSensorCalStr tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalStrRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_208_1_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_208_1_t *)&tlm);

        dc_set_cubeadcs_gen2_tlm_frame_208_2_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_208_2_t *)&tlm.str1MeasBodyVec0X);
    }
}

/** @brief Getter for telemetry frame 209 - Calibrated RWL sensor telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_calibrated_rwl_sensor_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmSensorCalRwl) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_209_t));

    TypesCubeComputerControlProgram8_TlmSensorCalRwl tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalRwlRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_209_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_209_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 210 - Main estimator telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_main_estimator_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmEstimatorMain) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_210_t));

    TypesCubeComputerControlProgram8_TlmEstimatorMain tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmEstimatorMainRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_210_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_210_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 211 - Main estimator high-resolution telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_main_estimator_high_resolution_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmEstimatorMainHighRes) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_211_t));

    TypesCubeComputerControlProgram8_TlmEstimatorMainHighRes tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmEstimatorMainHighResRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_211_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_211_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 212 - Raw GNSS sensor telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_raw_gnss_sensor_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmGnssRaw) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_212_t));

    TypesCubeComputerControlProgram8_TlmGnssRaw tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmGnssRawRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_212_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_212_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 213 - Raw PST3S star tracker telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_raw_pst3s_star_tracker_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmStrPst3sRaw) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_213_t));

    TypesCubeComputerControlProgram8_TlmStrPst3sRaw tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrPst3sRawRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_213_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_213_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 214 - ACP execution telemetry */
STATIC void fs_cubeadcs_gen2_tlm_get_acp_execution_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmAcpExecution) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_214_t));

    TypesCubeComputerControlProgram8_TlmAcpExecution tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmAcpExecutionRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_214_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_214_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 216 - CubeComputer Health */
STATIC void fs_cubeadcs_gen2_tlm_get_cubecomputer_health(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmCubeComputerHealth) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_216_t));

    TypesCubeComputerControlProgram8_TlmCubeComputerHealth tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmCubeComputerHealthRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_216_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_216_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 217 - Health telemetry for CubeSense Earth */
STATIC void fs_cubeadcs_gen2_tlm_get_health_telemetry_for_cubesense_earth(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmHssCubeSenseEarthHealth) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_217_t));

    TypesCubeComputerControlProgram8_TlmHssCubeSenseEarthHealth tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmHssCubeSenseEarthHealthRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_217_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_217_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 218 - Health telemetry for Reaction Wheels */
STATIC void fs_cubeadcs_gen2_tlm_get_health_telemetry_for_reaction_wheels(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmRwlHealth) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_218_t));

    TypesCubeComputerControlProgram8_TlmRwlHealth tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmRwlHealthRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_218_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_218_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 225 - Health telemetry for CubeNode NSSRWL*/
STATIC void fs_cubeadcs_gen2_tlm_get_health_telemetry_for_cubenode_nssrwl(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmNssRwlHealth) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_225_t));

    TypesCubeComputerControlProgram8_TlmNssRwlHealth tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmNssRwlHealthRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_225_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_225_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 226 - Raw NSSRWL sensor telemetry*/
STATIC void fs_cubeadcs_gen2_tlm_get_raw_nssrwl_sensor_telemetry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmRwlNssRwlRaw) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_226_t));

    TypesCubeComputerControlProgram8_TlmRwlNssRwlRaw tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmRwlNssRwlRawRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_226_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_226_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 165 - Health telemetry for CubeStar*/
STATIC void fs_cubeadcs_gen2_tlm_get_health_telemetry_for_cubestar(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_TlmStrHealth) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_165_t));

    TypesCubeComputerControlProgram8_TlmStrHealth tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrHealthRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_165_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_165_t *)&tlm);
    }
}

/** @brief Getter for telemetry frame 221 - Mag sensing element configuration*/
STATIC void fs_cubeadcs_gen2_tlm_get_mag_sensing_config_telemtry(void)
{
    static_assert(sizeof(TypesCubeComputerControlProgram8_ConfigMagSensingElement) == sizeof(DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_221_t));

    TypesCubeComputerControlProgram8_ConfigMagSensingElement tlm;

    if (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMagSensingElementRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &tlm, CUBEADCS_GEN2_TLM_TIMEOUT))
    {
        dc_set_cubeadcs_gen2_tlm_frame_221_data((DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_221_t *)&tlm);
    }
}
