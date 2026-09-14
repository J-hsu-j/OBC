/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef __IF_SENSOR_DATA_TYPES_H__
#define __IF_SENSOR_DATA_TYPES_H__

/**
 * @addtogroup sds
 * @{
 *
 * @file     sensor_data_types.h
 * @brief    Sensor data types
 *
 * @}
 */

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

#include "es_cdef.h"

/**********************************************************************
 *
 * Type definitions
 *
 **********************************************************************/
/** @typedef sds_mag_data_t
    @brief Magnetometer data for a 3-axis magnetomter sensor in own coordinate frame and converted in [T] */
typedef struct
{
    double mag_x_T;
    double mag_y_T;
    double mag_z_T;

} PACKED sds_mag_data_t;

/** @typedef sds_gyro_data_t
    @brief Rate sensors data for a three 1-axis sensors in own coordinate frame (per sensor) and converted in rad/s */
typedef struct
{
    double gyro_1_rads;
    double gyro_2_rads;
    double gyro_3_rads;

} PACKED sds_gyro_data_t;

/** @typedef sds_css_data_t
    @brief Coarse Sun Sensors data for six 1-axis sensors in own coordinate frame (per sensor) and converted in ADCS value */
typedef struct
{
    int32_t css_1_adc;
    int32_t css_2_adc;
    int32_t css_3_adc;
    int32_t css_4_adc;
    int32_t css_5_adc;
    int32_t css_6_adc;

} PACKED sds_css_data_t;

/** @typedef sds_gyro_temp_data_t
    @brief Rate sensors temperature data for a three 1-axis sensors in own coordinate frame (per sensor) and converted in degC */
typedef struct
{
    double gyro_1_deg_c;
    double gyro_2_deg_c;
    double gyro_3_deg_c;

} PACKED sds_gyro_temp_data_t;

/** @typedef sds_panel_temp_data_t
    @brief Panel temperature sensors data for six 1-axis sensors in own coordinate frame (per sensor) and converted in degC */
typedef struct
{
    double pan_temp_1_deg_c;
    double pan_temp_2_deg_c;
    double pan_temp_3_deg_c;
    double pan_temp_4_deg_c;
    double pan_temp_5_deg_c;
    double pan_temp_6_deg_c;

} PACKED sds_panel_temp_data_t;

/** @typedef sds_mag_data_sat_t
    @brief Magnetometer data for a 3-axis magnetomter sensor in satellite coordinate frame and converted in [T] */
typedef struct
{
    double mag_x_T;
    double mag_y_T;
    double mag_z_T;

} PACKED sds_mag_data_sat_t;

/** @typedef sds_gyro_data_sat_t
    @brief Rate sensors data for a three 1-axis sensors in satellite coordinate frame (per sensor) and converted in rad/s */
typedef struct
{
    double gyro_x_rads;
    double gyro_y_rads;
    double gyro_z_rads;

} PACKED sds_gyro_data_sat_t;

/** @typedef sds_css_data_sat_t
    @brief Coarse Sun Sensors data for six 1-axis sensors in satellite coordinate frame (per sensor) and converted in ADCS value */
typedef struct
{
    int32_t css_X_pos_adc;
    int32_t css_Y_pos_adc;
    int32_t css_Z_pos_adc;
    int32_t css_X_neg_adc;
    int32_t css_Y_neg_adc;
    int32_t css_Z_neg_adc;

} PACKED sds_css_data_sat_t;

/** @typedef sds_gyro_temp_data_sat_t
    @brief Rate sensors temperature data for a three 1-axis sensors in satellite coordinate frame (per sensor) and converted in degC */
typedef struct
{
    double gyro_x_deg_c;
    double gyro_y_deg_c;
    double gyro_z_deg_c;

} PACKED sds_gyro_temp_data_sat_t;

/** @typedef sds_panel_temp_data_sat_t
    @brief Panel temperature sensors data for six 1-axis sensors in satellite coordinate frame (per sensor) and converted in degC */
typedef struct
{
    double pan_temp_X_pos_deg_c;
    double pan_temp_Y_pos_deg_c;
    double pan_temp_Z_pos_deg_c;
    double pan_temp_X_neg_deg_c;
    double pan_temp_Y_neg_deg_c;
    double pan_temp_Z_neg_deg_c;

} PACKED sds_panel_temp_data_sat_t;

/** @typedef sds_mag_enum_t
    @brief Magnetomter enumeration used to distinguish between the two magnetometers */
typedef enum
{
    SDS_MAG_ENUM_PRIM,
    SDS_MAG_ENUM_SEC,
    SDS_MAG_NUM,

} sds_mag_enum_t;

/** @typedef sds_all_sens_data_t
    @brief All of the sensors data in own coordinate frame */
typedef struct
{
    sds_mag_data_t        mag_data_prim;
    sds_mag_data_t        mag_data_sec;
    sds_gyro_data_t       gyro_data;
    sds_css_data_t        css_data;
    sds_gyro_temp_data_t  gyro_temp_data;
    sds_panel_temp_data_t panel_temp_data;

} PACKED sds_all_sens_data_t;

/** @typedef sds_mag_data_sat_step_t
    @brief Two magnetometer data samples for a 3-axis magnetometer sensor in satellite
     coordinate frame and converted in [uT]. Samples time differences depends on configuration */
typedef struct
{
    sds_mag_data_sat_t mag_data_curr;
    sds_mag_data_sat_t mag_data_prev;

} PACKED sds_mag_data_sat_step_t;

/** @typedef sds_gyro_data_sat_step_t
    @brief Two rate sensors data samples for a three 1-axis sensors in satellite coordinate frame (per sensor)
     and converted in urad/s. Samples time differences depends on configuration */
typedef struct
{
    sds_gyro_data_sat_t gyro_data_curr;
    sds_gyro_data_sat_t gyro_data_prev;

} PACKED sds_gyro_data_sat_step_t;

/** @typedef sds_css_data_sat_t
    @brief Two Coarse Sun Sensors data samples for six 1-axis sensors in satellite coordinate frame (per sensor)
     and converted in ADCS value. Samples time differences depends on configuration */
typedef struct
{
    sds_css_data_sat_t css_data_curr;
    sds_css_data_sat_t css_data_prev;

} PACKED sds_css_data_sat_step_t;

/** @typedef sds_all_sens_data_t
    @brief All of the sensors data in satellite coordinate frame as two consecutive samples.
     Samples time differences depends on configuration */
typedef struct
{
    sds_mag_data_sat_step_t   mag_data_prim;
    sds_mag_data_sat_step_t   mag_data_sec;
    sds_gyro_data_sat_step_t  gyro_data;
    sds_css_data_sat_step_t   css_data;
    sds_gyro_temp_data_sat_t  gyro_temp_data;
    sds_panel_temp_data_sat_t panel_temp_data;

} PACKED sds_all_sens_data_sat_step_t;

/** @typedef sds_sens_axis_enum_t
    @brief Sensor axis enumeration for single axis sensors */
typedef enum
{
    SDS_SENS_AXIS_X,
    SDS_SENS_AXIS_Y,
    SDS_SENS_AXIS_Z,
    SDS_SENS_AXIS_NUM

} sds_axis_enum_t;

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #ifndef __IF_SENSOR_DATA_TYPES_H__
