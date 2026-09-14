/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup ACS
 * @{
 *
 * @file   acs.c
 * @brief  Actuator Control Service source file
 *
 * @}
 */

#include <string.h>
#include <stdlib.h>
#include "datacache.h"
#include "es_exeh.h"
#include "taskmon.h"
#include "taskmon_stat.h"
#include "panels.h"
#include "coordsys.h"
#include "acs.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
/** @brief Module ID used for this file to report error events in EXEH */
#define EXEH_CURRENT_MODULE_ID (eEXEHModuleID_ACS)

/** @brief Limit of MTQ influence [A.m^2] */
#define MTQ_SATURATION_LIMIT (+0.1311)

/** @brief Limit of MTQ control signal in % duty cycle */
#define MTQ_SATURATION_LIMIT_PWM (100U)

/** @brief Any difference between two floating point numbers that is less than this define is considered as 0 */
#define DOUBLE_ZERO_LIMIT (1e-15)

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/
/* No Internal types definitions */

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/
/* No External variables definitions */

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
/** @brief DataCache blocks */
/* Inputs */
static DATA_CACHE_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_t dc_mag_field_measurement_body_frame;
static DATA_CACHE_ACTUATOR_TORQUE_VALUES_t           dc_torque_values_body_frame;
/* Outputs */
static DATA_CACHE_ACTUATOR_MTQ_VALUES_t dc_mtq_pwm_signals;

/** @brief Store the control values and their direction in the body (satellite) and magnetorquer frame */
static int8_t mtq_control_values_body_frame[MAGNETORQUER_QUANTITY];
static int8_t mtq_control_values_mtq_frame[MAGNETORQUER_QUANTITY];
static int8_t mtq_control_values_mtq_frame_manual[MAGNETORQUER_QUANTITY] = { 0, 0, 0 };

/** @brief Actuator control service mode (state) */
static acs_state_t active_state = ACS_STATE_STOPPED;

/** @brief Holds the latest error found in the service execution */
static acs_error_t   last_error;
static acs_warning_t last_warning;

/** @brief Holds essential information about the actuator control service */
static acs_status_t status;

/** @brief Actuator control service FreeRTOS Task related variables */
static osThreadId_t         acs_task_task_handle;
static const osThreadAttr_t acs_task_attributes = {
    .name       = "acs_task",
    .priority   = (osPriority_t)osPriorityNormal,
    .stack_size = 128 * 8
};

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
/** @brief The FreeRTOS task responsible for actuator control service logic
 *  @param[in] void *arg - task arguments */
static void fs_acs_task(void *arg);

/** @brief Actuator control service update status function, responsible for updating the status variable */
static void fs_acs_update_status(void);

/** @brief Actuate magnetorquers */
static void fs_magnetorquers_actuate(void);

/** @brief Actuate magnetorquers with operator-fed values */
static void fs_magnetorquers_actuate_manual(void);

/** @brief Stop magnetorquers */
static void fs_magnetorquers_stop(void);

/** @brief Derive magnetorquer directions based on control values
 *  @param[in]  const int8_t  * const p_input_data        - pointer to array with the input magnetorquer control values transformed to actuator frame
 *  @param[out]       uint8_t * const p_output_directions - pointer to array with directions of magnetorquer action */
static void fs_get_magnetorquers_direction(const int8_t *p_input_data, uint8_t *p_output_directions);

/** @brief Saturate actuators based on input limits
 *  @param[in/out]       double  * const p_actuator_signal   - pointer to array with unsaturated values and saturated values after execution
 *  @param[in]     const double          actuator_limit      - variable that holds the limit to be applied to the input signal
 *  @param[in]     const uint8_t         number_of_actuators - variable that holds the number of actuators to saturate */
static void fs_actuators_saturate(double *const p_actuator_signal, const double actuator_limit, const uint8_t number_of_actuators);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
void acs_init(void)
{
    EXEH_INIT_MODULE_FILENAME();

    /* Make sure the task logic doesn't run until told to by the ADCS or external command */
    active_state = ACS_STATE_STOPPED;

    /* Spawn the task */
    acs_task_task_handle = osThreadNew(fs_acs_task, NULL, &acs_task_attributes);
    CRIT_ASSERT(acs_task_task_handle);
    task_mon_register_for_stats(TASK_ID_ACS, acs_task_task_handle);

    /* Notify task monitor that the actuator control service task is initialized */
    task_mon_task_initialized(TASK_ID_ACS);
    task_mon_set_task_policy(TASK_ID_ACS, TASK_MON_POLICY_MONITOR);
}

void acs_set_op_mode(acs_state_t desired_op_mode)
{
    acs_state_t current_op_mode = acs_get_op_mode();

    switch (desired_op_mode)
    {
        case ACS_STATE_RUN:
            {
                if (ACS_STATE_STOPPED == current_op_mode)
                {
                    /* Initialization is needed when coming from STOPPED */
                    /* Initialize physical magnetorquer hardware */
                    MCU_MagnetorqersInit();

                    /* Activate the task logic */
                    active_state = ACS_STATE_RUN;
                }
                else if (ACS_STATE_MANUAL == current_op_mode)
                {
                    /* Attempted MANUAL to RUN transition, no initialization needed, but zero out magnetorquer values */
                    fs_magnetorquers_stop();

                    /* Move to RUN mode */
                    active_state = ACS_STATE_RUN;
                }
                else
                {
                    /* Attempted RUN to RUN transition, do nothing */
                }
                break;
            }
        case ACS_STATE_MANUAL:
            {
                if (ACS_STATE_STOPPED == current_op_mode)
                {
                    /* Initialization is needed when coming from STOPPED */
                    /* Initialize physical magnetorquer hardware */
                    MCU_MagnetorqersInit();

                    /* Activate the task logic */
                    active_state = ACS_STATE_MANUAL;
                }
                else if (ACS_STATE_RUN == current_op_mode)
                {
                    /* Attempted RUN to MANUAL transition, no initialization needed, but zero out magnetorquer values */
                    fs_magnetorquers_stop();

                    /* Move to MANUAL mode */
                    active_state = ACS_STATE_MANUAL;
                }
                else
                {
                    /* Attempted MANUAL to MANUAL transition, do nothing */
                }
                break;
            }
        case ACS_STATE_STOPPED:
            {
                if ((ACS_STATE_RUN == current_op_mode) || (ACS_STATE_MANUAL == current_op_mode))
                {
                    /* Make the task dormant */
                    active_state = ACS_STATE_STOPPED;

                    /* Clear magnetorquer outputs */
                    fs_magnetorquers_stop();

                    /* Deinitialize physical magnetorquer hardware */
                    MCU_MagnetorqersDeInit();
                }
                break;
            }
        default:
            {
                /* Desired state out of bounds - report through es_exeh */
                EXEH_HANDLE(eEXEHSeverity_Error, EXEH_ACS_INVALID_STATE_SWITCH);
                break;
            }
    }
}

acs_state_t acs_get_op_mode(void)
{
    return active_state;
}

acs_status_t acs_get_status(void)
{
    return status;
}

void acs_set_manual_mtq_control_mtq_frame(const int8_t mtq_1, const int8_t mtq_2, const int8_t mtq_3)
{
    /* Create a temporary array of double for saturation processing */
    double temp_mtq_values[MAGNETORQUER_QUANTITY];

    /* Convert int8_t values to double */
    temp_mtq_values[0] = (double)mtq_1;
    temp_mtq_values[1] = (double)mtq_2;
    temp_mtq_values[2] = (double)mtq_3;

    /* Saturate to prevent user input that exceeds possible PWM range */
    fs_actuators_saturate(temp_mtq_values, (double)MTQ_SATURATION_LIMIT_PWM, (uint8_t)MAGNETORQUER_QUANTITY);

    /* Convert back to int8_t and assign the saturated values */
    for (uint8_t i = 0; i < MAGNETORQUER_QUANTITY; i++)
    {
        mtq_control_values_mtq_frame_manual[i] = (int8_t)temp_mtq_values[i];
    }
}

void acs_get_manual_mtq_control_mtq_frame(int8_t *const manual_mtq_control_mtq_frame)
{
    BREAK_ASSERT(NULL != manual_mtq_control_mtq_frame);

    memcpy(manual_mtq_control_mtq_frame, mtq_control_values_mtq_frame_manual, sizeof(mtq_control_values_mtq_frame_manual));
}

void acs_get_last_mtq_control_body_frame(int8_t *const last_mtq_control_body_frame)
{
    BREAK_ASSERT(NULL != last_mtq_control_body_frame);

    memcpy(last_mtq_control_body_frame, mtq_control_values_body_frame, sizeof(mtq_control_values_body_frame));
}

void acs_get_last_mtq_control_mtq_frame(int8_t *const last_mtq_control_mtq_frame)
{
    BREAK_ASSERT(NULL != last_mtq_control_mtq_frame);

    memcpy(last_mtq_control_mtq_frame, mtq_control_values_mtq_frame, sizeof(mtq_control_values_mtq_frame));
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
static void fs_acs_task(void *arg)
{
    for (;;)
    {
        task_mon_i_am_alive(TASK_ID_ACS);

        switch (active_state)
        {
            case ACS_STATE_RUN:
                {
                    /* Actuate magnetorquers */
                    fs_magnetorquers_actuate();

                    /* Add any future actuators here */

                    break;
                }
            case ACS_STATE_MANUAL:
                {
                    /* Actuate magnetorquers with operator-fed values */
                    fs_magnetorquers_actuate_manual();

                    /* Add any future actuators here */

                    break;
                }
            case ACS_STATE_STOPPED:
                {
                    /* Remain dormant until changed by ADCS mode switch or satellite operator */
                    break;
                }
            default:
                {
                    /* State out of bounds - report through es_exeh */
                    EXEH_HANDLE(eEXEHSeverity_Error, EXEH_ACS_INVALID_STATE);
                    break;
                }
        }

        /* Update service-wide status variable */
        fs_acs_update_status();

        /* The task sleeps for the sampling period */
        task_mon_low_stack_check(TASK_ID_ACS);
        osDelay(ACS_SAMPLING_TIME_MS);
    }
}

static void fs_acs_update_status(void)
{
    status.state        = active_state;
    status.last_error   = last_error;
    status.last_warning = last_warning;
}

static void fs_magnetorquers_actuate(void)
{
    /* Outline
     * 1. Read DataCache entry for magnetometer measurement
     * 2. Read DataCache entry for required torque
     * 3. Calculate magnetic dipole
     * 4. Saturate magnetic dipole
     * 5. Convert to PWM
     * 6. Use coordinate transform
     * 7. Determine directions
     * 8. Scale (if necessary) to appropriate control units
     * 9. Send to actuator
     */

    last_error = ACS_ERROR_NONE;

    uint8_t mtq_control_values_directions[MAGNETORQUER_QUANTITY];
    double  mag_field[3];         /* Magnetic field measurement read from DataCache */
    double  control_torque[3];    /* Control torque read from DataCache */
    double  temp_vec[3];          /* Vector used for cross product calculation */
    double  mag_dipole_moment[3]; /* Resulting magnetic moment */

    double mag_field_norm;

    /* Dodge MISRA-C:2004 */
    double temp_control_values[3];

    /* Obtain the latest magnetometer measurements from DataCache */
    if (DC_DATA_STATUS_OK != dc_get_sat_mag_field_vector_from_sensor_data(&dc_mag_field_measurement_body_frame))
    {
        last_error = ACS_ERROR_DATA_CACHE_GET;
        EXEH_HANDLE(eEXEHSeverity_Error, EXEH_ACS_MTQ_DC_READ_FAIL);
        return;
    }

    mag_field[0] = dc_mag_field_measurement_body_frame.dMag_field_x_current;
    mag_field[1] = dc_mag_field_measurement_body_frame.dMag_field_y_current;
    mag_field[2] = dc_mag_field_measurement_body_frame.dMag_field_z_current;

    /* Obtain the latest calculated control values from DataCache */
    if (DC_DATA_STATUS_OK != dc_get_actuator_torque_values_data(&dc_torque_values_body_frame))
    {
        last_error = ACS_ERROR_DATA_CACHE_GET;
        EXEH_HANDLE(eEXEHSeverity_Error, EXEH_ACS_MTQ_DC_READ_FAIL);
        return;
    }

    /* Calculate the required magnetic dipole */
    if ((fabs(dc_torque_values_body_frame.dRequired_torque_x) >= DOUBLE_ZERO_LIMIT) ||
        (fabs(dc_torque_values_body_frame.dRequired_torque_y) >= DOUBLE_ZERO_LIMIT) ||
        (fabs(dc_torque_values_body_frame.dRequired_torque_z) >= DOUBLE_ZERO_LIMIT))
    {
        control_torque[0] = dc_torque_values_body_frame.dRequired_torque_x;
        control_torque[1] = dc_torque_values_body_frame.dRequired_torque_y;
        control_torque[2] = dc_torque_values_body_frame.dRequired_torque_z;

        /* Convert torque to magnetic dipole with the formula m = torque x B/Bnorm^2 */
        temp_vec[0] = mag_field[1] * control_torque[2] - mag_field[2] * control_torque[1];
        temp_vec[1] = mag_field[2] * control_torque[0] - mag_field[0] * control_torque[2];
        temp_vec[2] = mag_field[0] * control_torque[1] - mag_field[1] * control_torque[0];

        /* Find the norm of the magnetic field */
        mag_field_norm = sqrt(mag_field[0] * mag_field[0] + mag_field[1] * mag_field[1] + mag_field[2] * mag_field[2]);

        if (mag_field_norm >= DOUBLE_ZERO_LIMIT)
        {
            mag_dipole_moment[0] = temp_vec[0] / (mag_field_norm * mag_field_norm);
            mag_dipole_moment[1] = temp_vec[1] / (mag_field_norm * mag_field_norm);
            mag_dipole_moment[2] = temp_vec[2] / (mag_field_norm * mag_field_norm);
        }
        else
        {
            last_error = ACS_ERROR_DIVISION_BY_ZERO;
            return;
        }

        /* Call saturation function */
        fs_actuators_saturate(mag_dipole_moment, MTQ_SATURATION_LIMIT, (uint8_t)MAGNETORQUER_QUANTITY);

        /* Map saturated magnetic dipole to PWM */
        /* Dodge MISRA-C:2004 */
        temp_control_values[0]           = (mag_dipole_moment[0] / MTQ_SATURATION_LIMIT) * 100;
        temp_control_values[1]           = (mag_dipole_moment[1] / MTQ_SATURATION_LIMIT) * 100;
        temp_control_values[2]           = (mag_dipole_moment[2] / MTQ_SATURATION_LIMIT) * 100;
        mtq_control_values_body_frame[0] = (int8_t)temp_control_values[0];
        mtq_control_values_body_frame[1] = (int8_t)temp_control_values[1];
        mtq_control_values_body_frame[2] = (int8_t)temp_control_values[2];

        /* Send final magnetorquer signals to DataCache */
        dc_mtq_pwm_signals.i8Magnetorquer_value_x = mtq_control_values_body_frame[0];
        dc_mtq_pwm_signals.i8Magnetorquer_value_y = mtq_control_values_body_frame[1];
        dc_mtq_pwm_signals.i8Magnetorquer_value_z = mtq_control_values_body_frame[2];
        dc_set_actuator_mtq_values_data(&dc_mtq_pwm_signals);

        coordsys_transform_mtq(mtq_control_values_body_frame, mtq_control_values_mtq_frame);

        /* Determine direction of magnetorquer action */
        fs_get_magnetorquers_direction(mtq_control_values_mtq_frame, mtq_control_values_directions);

        /* Call driver function for magnetorquer */
        /* Accessing elements of the array like this is very ugly, but probably faster than a for loop */
        SetMagnetorque(PAN_X_M, (uint8_t)(abs(mtq_control_values_mtq_frame[0])), mtq_control_values_directions[0]); /* PAN4 */
        SetMagnetorque(PAN_Y_M, (uint8_t)(abs(mtq_control_values_mtq_frame[1])), mtq_control_values_directions[1]); /* PAN5 */
        SetMagnetorque(PAN_Z_M, (uint8_t)(abs(mtq_control_values_mtq_frame[2])), mtq_control_values_directions[2]); /* PAN6 */
    }
    else
    {
        /* Stop all magnetorquer action */
        fs_magnetorquers_stop();

        /* Attempted division by zero - report through es_exeh */
        EXEH_HANDLE(eEXEHSeverity_Error, EXEH_ACS_MTQ_DIVISION_BY_ZERO);
    }
}

static void fs_magnetorquers_actuate_manual(void)
{
    /* Outline
     * 1. Determine directions
     * 2. Send to actuator
     */

    uint8_t mtq_control_values_directions_manual[MAGNETORQUER_QUANTITY];

    /* Determine direction of magnetorquer action */
    fs_get_magnetorquers_direction(mtq_control_values_mtq_frame_manual, mtq_control_values_directions_manual);

    /* Call driver function for magnetorquer */
    /* Accessing elements of the array like this is very ugly, but probably faster than a for loop */
    SetMagnetorque(PAN_X_M, (uint8_t)(abs(mtq_control_values_mtq_frame_manual[0])), mtq_control_values_directions_manual[0]); /* PAN4 */
    SetMagnetorque(PAN_Y_M, (uint8_t)(abs(mtq_control_values_mtq_frame_manual[1])), mtq_control_values_directions_manual[1]); /* PAN5 */
    SetMagnetorque(PAN_Z_M, (uint8_t)(abs(mtq_control_values_mtq_frame_manual[2])), mtq_control_values_directions_manual[2]); /* PAN6 */
}

static void fs_magnetorquers_stop(void)
{
    /* Outline
     * 1. Zero out all control values (or whatever represents a turned off actuator)
     * 2. Send to actuator
     */

    for (uint8_t i = 0; i < MAGNETORQUER_QUANTITY; i++)
    {
        mtq_control_values_mtq_frame[i] = 0;
    }

    /* Accessing elements of the array like this is very ugly, but probably faster than a for loop */
    /* The direction parameter for a zero value actuation is irrelevant, therefore a 0 is passed */
    SetMagnetorque(PAN_X_M, (uint8_t)(abs(mtq_control_values_mtq_frame[0])), 0); /* PAN4 */
    SetMagnetorque(PAN_Y_M, (uint8_t)(abs(mtq_control_values_mtq_frame[1])), 0); /* PAN5 */
    SetMagnetorque(PAN_Z_M, (uint8_t)(abs(mtq_control_values_mtq_frame[2])), 0); /* PAN6 */
}

static void fs_get_magnetorquers_direction(const int8_t *const p_input_data, uint8_t *const p_output_directions)
{
    BREAK_ASSERT(NULL != p_input_data);
    BREAK_ASSERT(NULL != p_output_directions);

    /* 3 magnetorquers for now */
    for (uint8_t i = 0; i < MAGNETORQUER_QUANTITY; i++)
    {
        if (p_input_data[i] >= 0)
        {
            p_output_directions[i] = 1;
        }
        else
        {
            p_output_directions[i] = 0;
        }
    }
}

static void fs_actuators_saturate(double *const p_actuator_signal, const double actuator_limit, const uint8_t number_of_actuators)
{
    BREAK_ASSERT(NULL != p_actuator_signal);

    /* Saturate the signals */
    for (uint8_t i = 0; i < number_of_actuators; i++)
    {
        if (p_actuator_signal[i] > actuator_limit)
        {
            p_actuator_signal[i] = actuator_limit;
            last_warning         = ACS_WARN_SATURATION_UPPER;
        }
        if (p_actuator_signal[i] < -actuator_limit)
        {
            p_actuator_signal[i] = -actuator_limit;
            last_warning         = ACS_WARN_SATURATION_LOWER;
        }
    }
}
