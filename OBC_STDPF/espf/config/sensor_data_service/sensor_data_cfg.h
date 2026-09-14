/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef __SENSOR_DATA_CFG_H__
#define __SENSOR_DATA_CFG_H__

/**
 * @addtogroup sds
 * @{
 *
 * @file     sensor_data_cfg.h
 * @brief    Sensor Data user configuration header
 *
 * @}
 */

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

#include "../inc/sensor_data_cfg_types.h"
#include "fp/SDS/v1.0/SDS_server/FP_SDSProtocolTypes.h"

/** @brief Maximum sensor sampling frequency in [Hz] of the SDS */
#define SDS_MAX_SENSOR_FREQ_HZ (uint16_t)40

/**********************************************************************
 *
 * External type declarations
 *
 **********************************************************************/
extern const sensor_base_cfg_t            sensor_base_cfg[];
extern const sensor_mag_data_cfg_t        sensor_prim_mag_data_cfg;
extern const sensor_mag_data_cfg_t        sensor_sec_mag_data_cfg;
extern const sensor_gyro_data_cfg_t       sensor_gyro_data_cfg;
extern const sensor_css_data_cfg_t        sensor_css_data_cfg;
extern const sensor_panel_temp_data_cfg_t sensor_panel_temp_data_cfg;
extern const sensor_gyro_temp_data_cfg_t  sensor_gyro_temp_data_cfg;

/**********************************************************************
 *
 * Public functions
 *
 **********************************************************************/
/** @brief Get sensor data
 *  @param[in] SDS_AvailableSensors_t                                 sens_type - sensor type
 *  @param[in] sds_all_sens_data_t          * const                p_sens_data - data in own coordinate frame
 *  @param[in] sds_all_sens_data_sat_step_t * const            p_sens_data_sat - data in sat coordinate frame
 *  @param[in]                                const void     **p_sens_data_mem - pointer to pointer used for the DC update
 *  @param[in]                                const void **p_sens_data_sat_mem - pointer to pointer used for the DC update
 *  @return    sds_op_status_t
 *  @note This function makes the correct calls to get the sensor data in its own coordinate frame and updates it in
 *  the relevant data structure. It calls the data conversion to satellite coordinate frame and updates the current and
 *  old entries in the sat data structure */
sds_op_status_t sds_get_sensor_data(SDS_AvailableSensors_t sens_type, sds_all_sens_data_t *const sens_data,
                                    sds_all_sens_data_sat_step_t *const sens_data_sat, const void **p_sens_data_mem,
                                    const void **p_sens_data_sat_mem);

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #ifndef __SENSOR_DATA_CFG_H__
