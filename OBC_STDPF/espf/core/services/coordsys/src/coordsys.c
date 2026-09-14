/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup coordsys
 * @{
 *
 * @file   coordsys.c
 * @brief  Coordinate System Transformation service source file
 *
 * @}
 */

#include "coordsys.h"
#include <string.h>
#include "nvm.h"
#include "es_exeh.h"
#include "assertions.h"
#include "stdlib.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
/** @brief Module ID used for this file to report error events in EXEH */
#define EXEH_CURRENT_MODULE_ID (eEXEHModuleID_COORDSYS)

/** @brief Dimension of rotation/mapping matrices in the 3D case */
#define MATRIX_DIM_3D (3U)

/** @brief Dimension of rotation/mapping matrices in the 6D case */
#define MATRIX_DIM_6D (6U)

/** @brief Size of rotation/mapping matrices in the 3D case */
#define MATRIX_SIZE_3D (MATRIX_DIM_3D * MATRIX_DIM_3D)

/** @brief Size of rotation/mapping matrices in the 6D case */
#define MATRIX_SIZE_6D (MATRIX_DIM_6D * MATRIX_DIM_6D)

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
/* No External variables definition */

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
/** @brief All active frames are kept in this variable */
static coordsys_frames_t active_frames;

/** @brief All changes of frames are kept in this struct before the validation step */
static coordsys_frames_t shadow_frames;

/** @brief The coordsys service status variable */
static coordsys_status_t latest_status;

/** @brief The array for storing status of all the frames */
static coordsys_frame_status_t latest_status_frames[FRAME_COUNT];

/** @brief Gyroscope rotation matrix */
static int8_t gyr_rot_mat[MATRIX_SIZE_3D];

/** @brief Magnetometer rotation matrix */
static int8_t mag_rot_mat[MATRIX_SIZE_3D];

/** @brief Coarse sun sensor rotation matrix */
static int8_t css_rot_mat[MATRIX_SIZE_6D];

/** @brief Magnetorquer rotation matrix */
static int8_t mtq_rot_mat[MATRIX_SIZE_3D];

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
/** @brief Clear the status variables for all frames
 *  @param[in] const coordsys_frame_type_t frame_type - the frame type whose status is to be cleared */
static void fs_coordsys_clear_status(const coordsys_frame_type_t frame_type);

/** @brief Updates the general coordsys status based on the individual frame status variables */
static void fs_coordsys_update_status(void);

/** @brief Build a rotation/mapping matrix based on active_frames variable
 *  @param[in]  const coordsys_frame_type_t         frame_type - the frame type that is to be built
 *  @param[in]  const coordsys_frames_t     * const p_frames   - pointer to the array with frame configurations from which to build the rotation/mapping matrix
 *  @param[out] const int8_t                * const p_rot_mat  - pointer to the array which represents the rotation/mapping matrix to be built
 *  @return           bool                                     - 1(true) for success, 0(false) for fail */
static bool fs_coordsys_build_matrix(const coordsys_frame_type_t frame_type, const coordsys_frames_t *const p_frames, int8_t *const p_rot_mat);

/** @brief Build a column of a rotation/mapping matrix
 *  @param[in]  const coordsys_frame_type_t             frame_type  - the frame type that is to be built
 *  @param[in]  const coordsys_satellite_axis_t         axis_to_map - assigned sensor axis
 *  @param[in]  const uint8_t                           col_num     - column number of the rotation matrix to build
 *  @param[out]       int8_t                    * const p_rot_mat   - pointer to the array which represents the rotation/mapping matrix to be built
 *  @return           bool                                          - 1(true) for success, 0(false) for fail */
static bool fs_coordsys_build_matrix_col(const coordsys_frame_type_t frame_type, const coordsys_satellite_axis_t axis_to_map, const uint8_t col_num, int8_t *const p_rot_mat);

/** @brief Transpose the magnetorquer matrix to get the inverted matrix. This is required because data flow is inverted
 *         with magnetorquers compared to sensors */
static void fs_coordsys_transpose_mtq_matrix(void);

/** @brief Map an axis to a number for the rotation matrix
 *  @param[in] coordsys_satellite_axis_t axis_to_map - axis to be mapped into a value
 *  @return    int8_t                                - +1 for an axis that is "POSITIVE" or -1 for an axis that is "NEGATIVE" */
static int8_t fs_coordsys_map_axis_to_value(const coordsys_satellite_axis_t axis_to_map);

/** @brief Validates that all elements of a matrix are in the range [-1, 1]
 *  @param[in]        uint8_t         dimension - dimension of the matrix (matrix is assumed to be square)
 *  @param[out] const int8_t  * const p_rot_mat - pointer to the array which represents the rotation/mapping matrix to be validated
 *  @return           bool                      - 1(true) for success, 0(false) for fail */
static bool fs_coordsys_validate_matrix_elements(uint8_t dimension, const int8_t *const p_rot_mat);

/** @brief Validates that each row and each column of a square matrix contains exactly one non-zero element
 *  @param[in]        uint8_t         dimension - dimension of the matrix (matrix is assumed to be square)
 *  @param[out] const int8_t  * const p_rot_mat - pointer to the array which represents the rotation/mapping matrix to be validated
 *  @return           bool                      - 1(true) for success, 0(false) for fail */
static bool fs_coordsys_validate_rows_and_columns(uint8_t dimension, const int8_t *const p_rot_mat);

/** @brief Map an axis to a number for the rotation matrix
 *  @param[in]  const coordsys_frame_type_t         frame_type - the frame type that is to be validated
 *  @param[out] const int8_t                * const p_rot_mat  - pointer to the array which represents the rotation/mapping matrix to be validated
 *  @return           bool                                     - 1(true) for success, 0(false) for fail */
static bool fs_coordsys_validate_frame(const coordsys_frame_type_t frame_type, const int8_t *const p_rot_mat);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
bool coordsys_init(void)
{
    EXEH_INIT_MODULE_FILENAME();

    /* Load the active config from nvm */
    /* Load into shadow frames for the validation step before applying to active frames */
    Nvm_GetBlockById(NVM_BLOCK_COORDINATE_FRAMES, &shadow_frames);

    /* Build, verify and apply to active frames if the validation step is successful */
    if (false == coordsys_set_frame(FRAME_GYROSCOPE, &shadow_frames.gyroscope_frame))
    {
        latest_status.general_error = ERROR_NVM_CONFIG_CORRUPTED;
        EXEH_HANDLE(eEXEHSeverity_Error, EXEH_COORDSYS_NVM_CONFIG_CORRUPTED);
        return false;
    }

    if (false == coordsys_set_frame(FRAME_MAGNETOMETER, &shadow_frames.magnetometer_frame))
    {
        latest_status.general_error = ERROR_NVM_CONFIG_CORRUPTED;
        EXEH_HANDLE(eEXEHSeverity_Error, EXEH_COORDSYS_NVM_CONFIG_CORRUPTED);
        return false;
    }

    if (false == coordsys_set_frame(FRAME_COARSE_SUN_SENSOR, &shadow_frames.coarse_sun_sensor_frame))
    {
        latest_status.general_error = ERROR_NVM_CONFIG_CORRUPTED;
        EXEH_HANDLE(eEXEHSeverity_Error, EXEH_COORDSYS_NVM_CONFIG_CORRUPTED);
        return false;
    }

    if (false == coordsys_set_frame(FRAME_MAGNETORQUER, &shadow_frames.magnetorquer_frame))
    {
        latest_status.general_error = ERROR_NVM_CONFIG_CORRUPTED;
        EXEH_HANDLE(eEXEHSeverity_Error, EXEH_COORDSYS_NVM_CONFIG_CORRUPTED);
        return false;
    }

    /* All nvm entries were correct - reset the general error flag for the entire coordsys service */
    latest_status.general_error = ERROR_NONE;

    return true;
}

coordsys_status_t coordsys_get_status(void)
{
    fs_coordsys_update_status();
    return latest_status;
}

coordsys_frame_status_t coordsys_get_status_frame(const coordsys_frame_type_t frame_type)
{
    return latest_status_frames[frame_type];
}

void coordsys_transform_gyr(const double *const p_input_data, double *const p_output_data)
{
    BREAK_ASSERT(NULL != p_input_data);
    BREAK_ASSERT(NULL != p_output_data);

    /* Apply gyroscope rotation matrix. Data is only transformed between coordinate frames, not units. */

    /* Body frame X positive axis */
    p_output_data[0] = p_input_data[0] * gyr_rot_mat[0] + p_input_data[1] * gyr_rot_mat[1] + p_input_data[2] * gyr_rot_mat[2];

    /* Body frame Y positive axis */
    p_output_data[1] = p_input_data[0] * gyr_rot_mat[3] + p_input_data[1] * gyr_rot_mat[4] + p_input_data[2] * gyr_rot_mat[5];

    /* Body frame Z positive axis */
    p_output_data[2] = p_input_data[0] * gyr_rot_mat[6] + p_input_data[1] * gyr_rot_mat[7] + p_input_data[2] * gyr_rot_mat[8];
}

void coordsys_transform_mag(const double *const p_input_data, double *const p_output_data)
{
    BREAK_ASSERT(NULL != p_input_data);
    BREAK_ASSERT(NULL != p_output_data);

    /* Apply magnetometer rotation matrix. Data is only transformed between coordinate frames, not units. */

    /* Body frame X positive axis */
    p_output_data[0] = p_input_data[0] * mag_rot_mat[0] + p_input_data[1] * mag_rot_mat[1] + p_input_data[2] * mag_rot_mat[2];

    /* Body frame Y positive axis */
    p_output_data[1] = p_input_data[0] * mag_rot_mat[3] + p_input_data[1] * mag_rot_mat[4] + p_input_data[2] * mag_rot_mat[5];

    /* Body frame Z positive axis */
    p_output_data[2] = p_input_data[0] * mag_rot_mat[6] + p_input_data[1] * mag_rot_mat[7] + p_input_data[2] * mag_rot_mat[8];
}

void coordsys_transform_css(const int32_t *const p_input_data, int32_t *const p_output_data)
{
    BREAK_ASSERT(NULL != p_input_data);
    BREAK_ASSERT(NULL != p_output_data);

    /* Apply coarse sun sensor rotation matrix. Data is only transformed between coordinate frames, not units. */

    /* Body frame X positive axis */
    p_output_data[0] = p_input_data[0] * css_rot_mat[0] + p_input_data[1] * css_rot_mat[1] + p_input_data[2] * css_rot_mat[2] + p_input_data[3] * css_rot_mat[3] + p_input_data[4] * css_rot_mat[4] + p_input_data[5] * css_rot_mat[5];

    /* Body frame Y positive axis */
    p_output_data[1] = p_input_data[0] * css_rot_mat[6] + p_input_data[1] * css_rot_mat[7] + p_input_data[2] * css_rot_mat[8] + p_input_data[3] * css_rot_mat[9] + p_input_data[4] * css_rot_mat[10] + p_input_data[5] * css_rot_mat[11];

    /* Body frame Z positive axis */
    p_output_data[2] = p_input_data[0] * css_rot_mat[12] + p_input_data[1] * css_rot_mat[13] + p_input_data[2] * css_rot_mat[14] + p_input_data[3] * css_rot_mat[15] + p_input_data[4] * css_rot_mat[16] + p_input_data[5] * css_rot_mat[17];

    /* Body frame X negative axis */
    p_output_data[3] = p_input_data[0] * css_rot_mat[18] + p_input_data[1] * css_rot_mat[19] + p_input_data[2] * css_rot_mat[20] + p_input_data[3] * css_rot_mat[21] + p_input_data[4] * css_rot_mat[22] + p_input_data[5] * css_rot_mat[23];

    /* Body frame Y negative axis */
    p_output_data[4] = p_input_data[0] * css_rot_mat[24] + p_input_data[1] * css_rot_mat[25] + p_input_data[2] * css_rot_mat[26] + p_input_data[3] * css_rot_mat[27] + p_input_data[4] * css_rot_mat[28] + p_input_data[5] * css_rot_mat[29];

    /* Body frame Z negative axis */
    p_output_data[5] = p_input_data[0] * css_rot_mat[30] + p_input_data[1] * css_rot_mat[31] + p_input_data[2] * css_rot_mat[32] + p_input_data[3] * css_rot_mat[33] + p_input_data[4] * css_rot_mat[34] + p_input_data[5] * css_rot_mat[35];
}

void coordsys_transform_mtq(const int8_t *const p_input_data, int8_t *const p_output_data)
{
    BREAK_ASSERT(NULL != p_input_data);
    BREAK_ASSERT(NULL != p_output_data);

    /* Apply magnetorquer rotation matrix. Data is only transformed between coordinate frames, not units. */

    /* Body frame X positive axis */
    p_output_data[0] = p_input_data[0] * mtq_rot_mat[0] + p_input_data[1] * mtq_rot_mat[1] + p_input_data[2] * mtq_rot_mat[2];

    /* Body frame Y positive axis */
    p_output_data[1] = p_input_data[0] * mtq_rot_mat[3] + p_input_data[1] * mtq_rot_mat[4] + p_input_data[2] * mtq_rot_mat[5];

    /* Body frame Z positive axis */
    p_output_data[2] = p_input_data[0] * mtq_rot_mat[6] + p_input_data[1] * mtq_rot_mat[7] + p_input_data[2] * mtq_rot_mat[8];
}

void coordsys_transform_panel_temp(const double *const p_input_data, double *const p_output_data)
{
    BREAK_ASSERT(NULL != p_input_data);
    BREAK_ASSERT(NULL != p_output_data);

    /* Apply coarse sun sensor rotation matrix. Data is only transformed between coordinate frames, not units. */
    /* The temperature sensors are on the same panels as the coarse sun sensors, therefore their rotation matrices are identical. */

    /* Body frame X positive axis */
    p_output_data[0] = p_input_data[0] * css_rot_mat[0] + p_input_data[1] * css_rot_mat[1] + p_input_data[2] * css_rot_mat[2] + p_input_data[3] * css_rot_mat[3] + p_input_data[4] * css_rot_mat[4] + p_input_data[5] * css_rot_mat[5];

    /* Body frame Y positive axis */
    p_output_data[1] = p_input_data[0] * css_rot_mat[6] + p_input_data[1] * css_rot_mat[7] + p_input_data[2] * css_rot_mat[8] + p_input_data[3] * css_rot_mat[9] + p_input_data[4] * css_rot_mat[10] + p_input_data[5] * css_rot_mat[11];

    /* Body frame Z positive axis */
    p_output_data[2] = p_input_data[0] * css_rot_mat[12] + p_input_data[1] * css_rot_mat[13] + p_input_data[2] * css_rot_mat[14] + p_input_data[3] * css_rot_mat[15] + p_input_data[4] * css_rot_mat[16] + p_input_data[5] * css_rot_mat[17];

    /* Body frame X negative axis */
    p_output_data[3] = p_input_data[0] * css_rot_mat[18] + p_input_data[1] * css_rot_mat[19] + p_input_data[2] * css_rot_mat[20] + p_input_data[3] * css_rot_mat[21] + p_input_data[4] * css_rot_mat[22] + p_input_data[5] * css_rot_mat[23];

    /* Body frame Y negative axis */
    p_output_data[4] = p_input_data[0] * css_rot_mat[24] + p_input_data[1] * css_rot_mat[25] + p_input_data[2] * css_rot_mat[26] + p_input_data[3] * css_rot_mat[27] + p_input_data[4] * css_rot_mat[28] + p_input_data[5] * css_rot_mat[29];

    /* Body frame Z negative axis */
    p_output_data[5] = p_input_data[0] * css_rot_mat[30] + p_input_data[1] * css_rot_mat[31] + p_input_data[2] * css_rot_mat[32] + p_input_data[3] * css_rot_mat[33] + p_input_data[4] * css_rot_mat[34] + p_input_data[5] * css_rot_mat[35];
}

void coordsys_transform_gyro_temp(const double *const p_input_data, double *const p_output_data)
{
    BREAK_ASSERT(NULL != p_input_data);
    BREAK_ASSERT(NULL != p_output_data);

    /* Apply gyroscope rotation matrix. Data is only transformed between coordinate frames, not units. */
    /* The gyroscope temperature is transformed without using the directional part of the gyroscope transformation matrix, therefore
     * the abs() method is utilized. */

    /* Body frame X positive axis */
    p_output_data[0] = p_input_data[0] * abs(gyr_rot_mat[0]) + p_input_data[1] * abs(gyr_rot_mat[1]) + p_input_data[2] * abs(gyr_rot_mat[2]);

    /* Body frame Y positive axis */
    p_output_data[1] = p_input_data[0] * abs(gyr_rot_mat[3]) + p_input_data[1] * abs(gyr_rot_mat[4]) + p_input_data[2] * abs(gyr_rot_mat[5]);

    /* Body frame Z positive axis */
    p_output_data[2] = p_input_data[0] * abs(gyr_rot_mat[6]) + p_input_data[1] * abs(gyr_rot_mat[7]) + p_input_data[2] * abs(gyr_rot_mat[8]);
}

bool coordsys_set_frame(const coordsys_frame_type_t frame_type, const coordsys_frame_t *const p_new_frame)
{
    BREAK_ASSERT(NULL != p_new_frame);

    switch (frame_type)
    {
        case FRAME_GYROSCOPE:
            (void)memcpy(&shadow_frames.gyroscope_frame, p_new_frame, sizeof(coordsys_frame_t));
            /* Build the rotation/mapping matrix based on the unvalidated frame */
            if (false == fs_coordsys_build_matrix(frame_type, &shadow_frames, gyr_rot_mat))
            {
                return false;
            }
            /* Validate the built matrix */
            if (true == fs_coordsys_validate_frame(frame_type, gyr_rot_mat))
            {
                /* Transfer the now validated frames to the active frames */
                (void)memcpy(&active_frames.gyroscope_frame, &shadow_frames.gyroscope_frame, sizeof(coordsys_frame_t));
                /* Clear status flags for this frame */
                fs_coordsys_clear_status(frame_type);
            }
            else
            {
                /* Rebuild the rotation/mapping matrix based on the previous valid (active) frames */
                (void)fs_coordsys_build_matrix(frame_type, &active_frames, gyr_rot_mat);
                return false;
            }
            break;

        case FRAME_MAGNETOMETER:
            (void)memcpy(&shadow_frames.magnetometer_frame, p_new_frame, sizeof(coordsys_frame_t));
            /* Build the rotation/mapping matrix based on the unvalidated frame */
            if (false == fs_coordsys_build_matrix(frame_type, &shadow_frames, mag_rot_mat))
            {
                return false;
            }
            /* Validate the built matrix */
            if (true == fs_coordsys_validate_frame(frame_type, mag_rot_mat))
            {
                /* Transfer the now validated frames to the active frames */
                (void)memcpy(&active_frames.magnetometer_frame, &shadow_frames.magnetometer_frame, sizeof(coordsys_frame_t));
                /* Clear status flags for this frame */
                fs_coordsys_clear_status(frame_type);
            }
            else
            {
                /* Rebuild the rotation/mapping matrix based on the previous valid (active) frames */
                (void)fs_coordsys_build_matrix(frame_type, &active_frames, mag_rot_mat);
                return false;
            }
            break;

        case FRAME_COARSE_SUN_SENSOR:
            (void)memcpy(&shadow_frames.coarse_sun_sensor_frame, p_new_frame, sizeof(coordsys_frame_t));
            /* Build the rotation/mapping matrix based on the unvalidated frame */
            if (false == fs_coordsys_build_matrix(frame_type, &shadow_frames, css_rot_mat))
            {
                return false;
            }
            /* Validate the built matrix */
            if (true == fs_coordsys_validate_frame(frame_type, css_rot_mat))
            {
                /* Transfer the now validated frames to the active frames */
                (void)memcpy(&active_frames.coarse_sun_sensor_frame, &shadow_frames.coarse_sun_sensor_frame, sizeof(coordsys_frame_t));
                /* Clear status flags for this frame */
                fs_coordsys_clear_status(frame_type);
            }
            else
            {
                /* Rebuild the rotation/mapping matrix based on the previous valid (active) frames */
                (void)fs_coordsys_build_matrix(frame_type, &active_frames, css_rot_mat);
                return false;
            }
            break;

        case FRAME_MAGNETORQUER:
            (void)memcpy(&shadow_frames.magnetorquer_frame, p_new_frame, sizeof(coordsys_frame_t));
            /* Build the rotation/mapping matrix based on the unvalidated frame */
            if (false == fs_coordsys_build_matrix(frame_type, &shadow_frames, mtq_rot_mat))
            {
                return false;
            }
            /* Validate the built matrix */
            if (true == fs_coordsys_validate_frame(frame_type, mtq_rot_mat))
            {
                /* Transfer the now validated frames to the active frames */
                (void)memcpy(&active_frames.magnetorquer_frame, &shadow_frames.magnetorquer_frame, sizeof(coordsys_frame_t));
                /* Clear status flags for this frame */
                fs_coordsys_clear_status(frame_type);
            }
            else
            {
                /* Rebuild the rotation/mapping matrix based on the previous valid (active) frames */
                (void)fs_coordsys_build_matrix(frame_type, &active_frames, mtq_rot_mat);
                return false;
            }
            break;

        default:
            latest_status.general_error = ERROR_FRAME_TYPE_INVALID;
            EXEH_HANDLE(eEXEHSeverity_Error, EXEH_COORDSYS_FRAME_TYPE_INVALID);
            break;
    }

    fs_coordsys_update_status();
    return true;
}

void coordsys_get_frame(const coordsys_frame_type_t frame_type, coordsys_frame_t *const p_active_frame)
{
    BREAK_ASSERT(NULL != p_active_frame);

    switch (frame_type)
    {
        case FRAME_GYROSCOPE:
            (void)memcpy(p_active_frame, &active_frames.gyroscope_frame, sizeof(coordsys_frame_t));
            break;

        case FRAME_MAGNETOMETER:
            (void)memcpy(p_active_frame, &active_frames.magnetometer_frame, sizeof(coordsys_frame_t));
            break;

        case FRAME_COARSE_SUN_SENSOR:
            (void)memcpy(p_active_frame, &active_frames.coarse_sun_sensor_frame, sizeof(coordsys_frame_t));
            break;

        case FRAME_MAGNETORQUER:
            (void)memcpy(p_active_frame, &active_frames.magnetorquer_frame, sizeof(coordsys_frame_t));
            break;

        default:
            latest_status.general_error = ERROR_FRAME_TYPE_INVALID;
            EXEH_HANDLE(eEXEHSeverity_Error, EXEH_COORDSYS_FRAME_TYPE_INVALID);
            break;
    }

    fs_coordsys_update_status();
}

void coordsys_save_config_to_nvm(void)
{
    Nvm_SetBlockById(NVM_BLOCK_COORDINATE_FRAMES, &active_frames, NVMSETBLOCK_STORE_IMMEDIATELY);
}

void coordsys_load_config_from_nvm(void)
{
    /* The init routine actually does both the read from nvm and the following rebuild of the rotation/mapping matrices */
    (void)coordsys_init();
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
static void fs_coordsys_clear_status(const coordsys_frame_type_t frame_type)
{
    latest_status_frames[frame_type].status_1 = ERROR_NONE;
    latest_status_frames[frame_type].status_2 = ERROR_NONE;
}

static void fs_coordsys_update_status(void)
{
    uint8_t frame_index = 0;

    /* Gyroscope frame update */
    if ((ERROR_NONE == latest_status_frames[frame_index].status_1) &&
        (ERROR_NONE == latest_status_frames[frame_index].status_2))
    {
        latest_status.gyroscope_frame = COORDSYS_RESULT_OK;
    }
    else
    {
        latest_status.gyroscope_frame = COORDSYS_RESULT_FAIL;
    }
    frame_index++;

    /* Magnetometer frame update */
    if ((ERROR_NONE == latest_status_frames[frame_index].status_1) &&
        (ERROR_NONE == latest_status_frames[frame_index].status_2))
    {
        latest_status.magnetometer_frame = COORDSYS_RESULT_OK;
    }
    else
    {
        latest_status.magnetometer_frame = COORDSYS_RESULT_FAIL;
    }
    frame_index++;

    /* Coarse sun sensor frame update */
    if ((ERROR_NONE == latest_status_frames[frame_index].status_1) &&
        (ERROR_NONE == latest_status_frames[frame_index].status_2))
    {
        latest_status.coarse_sun_sensor_frame = COORDSYS_RESULT_OK;
    }
    else
    {
        latest_status.coarse_sun_sensor_frame = COORDSYS_RESULT_FAIL;
    }
    frame_index++;

    /* Magnetorquer frame update */
    if ((ERROR_NONE == latest_status_frames[frame_index].status_1) &&
        (ERROR_NONE == latest_status_frames[frame_index].status_2))
    {
        latest_status.magnetorquer_frame = COORDSYS_RESULT_OK;
    }
    else
    {
        latest_status.magnetorquer_frame = COORDSYS_RESULT_FAIL;
    }
}

static bool fs_coordsys_build_matrix(const coordsys_frame_type_t frame_type, const coordsys_frames_t *const p_frames, int8_t *const p_rot_mat)
{
    BREAK_ASSERT(NULL != p_frames);
    BREAK_ASSERT(NULL != p_rot_mat);

    /* Function status */
    bool ret_val = false;

    (void)memset(p_rot_mat, 0x00, sizeof(int8_t) * MATRIX_SIZE_3D);

    switch (frame_type)
    {
        case FRAME_GYROSCOPE:
            if ((true == fs_coordsys_build_matrix_col(frame_type, p_frames->gyroscope_frame.frame_axis_1, 1, p_rot_mat)) &&
                (true == fs_coordsys_build_matrix_col(frame_type, p_frames->gyroscope_frame.frame_axis_2, 2, p_rot_mat)) &&
                (true == fs_coordsys_build_matrix_col(frame_type, p_frames->gyroscope_frame.frame_axis_3, 3, p_rot_mat)))
            {
                ret_val = true;
            }
            break;

        case FRAME_MAGNETOMETER:
            if ((true == fs_coordsys_build_matrix_col(frame_type, p_frames->magnetometer_frame.frame_axis_1, 1, p_rot_mat)) &&
                (true == fs_coordsys_build_matrix_col(frame_type, p_frames->magnetometer_frame.frame_axis_2, 2, p_rot_mat)) &&
                (true == fs_coordsys_build_matrix_col(frame_type, p_frames->magnetometer_frame.frame_axis_3, 3, p_rot_mat)))
            {
                ret_val = true;
            }
            break;

        case FRAME_COARSE_SUN_SENSOR:
            /* Coarse sun sensor matrix is much larger than the others, therefore make sure to clean out the remaining bytes */
            (void)memset(p_rot_mat, 0x00, sizeof(int8_t) * MATRIX_SIZE_6D);
            if ((true == fs_coordsys_build_matrix_col(frame_type, p_frames->coarse_sun_sensor_frame.frame_axis_1, 1, p_rot_mat)) &&
                (true == fs_coordsys_build_matrix_col(frame_type, p_frames->coarse_sun_sensor_frame.frame_axis_2, 2, p_rot_mat)) &&
                (true == fs_coordsys_build_matrix_col(frame_type, p_frames->coarse_sun_sensor_frame.frame_axis_3, 3, p_rot_mat)) &&
                (true == fs_coordsys_build_matrix_col(frame_type, p_frames->coarse_sun_sensor_frame.frame_axis_4, 4, p_rot_mat)) &&
                (true == fs_coordsys_build_matrix_col(frame_type, p_frames->coarse_sun_sensor_frame.frame_axis_5, 5, p_rot_mat)) &&
                (true == fs_coordsys_build_matrix_col(frame_type, p_frames->coarse_sun_sensor_frame.frame_axis_6, 6, p_rot_mat)))
            {
                ret_val = true;
            }
            break;

        case FRAME_MAGNETORQUER:
            if ((true == fs_coordsys_build_matrix_col(frame_type, p_frames->magnetorquer_frame.frame_axis_1, 1, p_rot_mat)) &&
                (true == fs_coordsys_build_matrix_col(frame_type, p_frames->magnetorquer_frame.frame_axis_2, 2, p_rot_mat)) &&
                (true == fs_coordsys_build_matrix_col(frame_type, p_frames->magnetorquer_frame.frame_axis_3, 3, p_rot_mat)))
            {
                /* Transpose the resulting matrix in order to compute the correct transformations from body to actuator frame */
                fs_coordsys_transpose_mtq_matrix();
                ret_val = true;
            }
            break;

        default:
            latest_status.general_error = ERROR_FRAME_TYPE_INVALID;
            EXEH_HANDLE(eEXEHSeverity_Error, EXEH_COORDSYS_FRAME_TYPE_INVALID);
            break;
    }
    return ret_val;
}

static bool fs_coordsys_build_matrix_col(const coordsys_frame_type_t frame_type, const coordsys_satellite_axis_t axis_to_map, const uint8_t col_num, int8_t *const p_rot_mat)
{
    BREAK_ASSERT(NULL != p_rot_mat);

    /* Function status */
    bool ret_val = false;
    /* Correct for proper array indexing */
    uint8_t idx          = col_num - 1;
    int8_t  mapped_value = 1; /* Default value, assuming positive direction */
    uint8_t offset       = 0; /* Holds the calculated offset for the rotation matrix */

    /* Determine the offset and modify the value based on the axis mapping and frame type */
    switch (frame_type)
    {
        case FRAME_GYROSCOPE:
        case FRAME_MAGNETOMETER:
        case FRAME_MAGNETORQUER:
            /* Logic that handles 3-dimensional mapping */
            if ((SAT_X_AXIS_POSITIVE == axis_to_map) || (SAT_X_AXIS_NEGATIVE == axis_to_map))
            {
                offset = 0;
            }
            else if ((SAT_Y_AXIS_POSITIVE == axis_to_map) || (SAT_Y_AXIS_NEGATIVE == axis_to_map))
            {
                offset = 3;
            }
            else
            {
                offset = 6;
            }
            mapped_value = fs_coordsys_map_axis_to_value(axis_to_map);
            ret_val      = true;
            break;

        case FRAME_COARSE_SUN_SENSOR:
            /* Logic that handles 6-dimensional mapping, mapped value can only be 1 (set by default) */
            switch (axis_to_map)
            {
                case SAT_X_AXIS_POSITIVE:
                    offset  = 0;
                    ret_val = true;
                    break;

                case SAT_Y_AXIS_POSITIVE:
                    offset  = 6;
                    ret_val = true;
                    break;

                case SAT_Z_AXIS_POSITIVE:
                    offset  = 12;
                    ret_val = true;
                    break;

                case SAT_X_AXIS_NEGATIVE:
                    offset  = 18;
                    ret_val = true;
                    break;

                case SAT_Y_AXIS_NEGATIVE:
                    offset  = 24;
                    ret_val = true;
                    break;

                case SAT_Z_AXIS_NEGATIVE:
                    offset  = 30;
                    ret_val = true;
                    break;

                default:
                    latest_status_frames[frame_type].status_1 = ERROR_SATELLITE_AXIS_INVALID;
                    EXEH_HANDLE(eEXEHSeverity_Error, EXEH_COORDSYS_SATELLITE_AXIS_INVALID);
                    break;
            }
            break;

        default:
            latest_status.general_error = ERROR_FRAME_TYPE_INVALID;
            EXEH_HANDLE(eEXEHSeverity_Error, EXEH_COORDSYS_FRAME_TYPE_INVALID);
            break;
    }

    /* Set the value in the rotation matrix based on calculated offset */
    p_rot_mat[idx + offset] = mapped_value;
    return ret_val;
}

static void fs_coordsys_transpose_mtq_matrix(void)
{
    int8_t temp[MATRIX_SIZE_3D];

    for (uint8_t i = 0; i < MATRIX_DIM_3D; i++)
    {
        for (uint8_t j = 0; j < MATRIX_DIM_3D; j++)
        {
            temp[i * MATRIX_DIM_3D + j] = mtq_rot_mat[j * MATRIX_DIM_3D + i];
        }
    }

    for (uint8_t k = 0; k < MATRIX_SIZE_3D; k++)
    {
        mtq_rot_mat[k] = temp[k];
    }
}

static int8_t fs_coordsys_map_axis_to_value(const coordsys_satellite_axis_t axis_to_map)
{
    return (SAT_Z_AXIS_POSITIVE >= axis_to_map) ? 1 : -1;
}

static bool fs_coordsys_validate_matrix_elements(uint8_t dimension, const int8_t *const p_rot_mat)
{
    BREAK_ASSERT(NULL != p_rot_mat);

    for (uint8_t i = 0; i < (dimension * dimension); i++)
    {
        if ((p_rot_mat[i] < -1) || (p_rot_mat[i] > 1))
        {
            return false; /* There is an element out of allowed range */
        }
    }
    return true;
}

static bool fs_coordsys_validate_rows_and_columns(uint8_t dimension, const int8_t *const p_rot_mat)
{
    BREAK_ASSERT(NULL != p_rot_mat);

    for (uint8_t i = 0; i < dimension; i++) /* Check columns */
    {
        uint8_t non_zero_count = 0;
        for (uint8_t j = 0; j < dimension; j++)
        {
            if (0 != p_rot_mat[j * dimension + i])
            {
                non_zero_count++;
            }
        }
        if (1 != non_zero_count)
        {
            return false; /* Column does not have exactly one non-zero element */
        }
    }

    for (uint8_t i = 0; i < dimension; i++) /* Check rows */
    {
        uint8_t non_zero_count = 0;
        for (uint8_t j = 0; j < dimension; j++)
        {
            if (0 != p_rot_mat[i * dimension + j])
            {
                non_zero_count++;
            }
        }
        if (1 != non_zero_count)
        {
            return false; /* Row does not have exactly one non-zero element */
        }
    }
    return true;
}

static bool fs_coordsys_validate_frame(const coordsys_frame_type_t frame_type, const int8_t *const p_rot_mat)
{
    switch (frame_type)
    {
        case FRAME_GYROSCOPE:
        case FRAME_MAGNETOMETER:
        case FRAME_MAGNETORQUER:
            if (false == fs_coordsys_validate_matrix_elements(MATRIX_DIM_3D, p_rot_mat))
            {
                latest_status_frames[frame_type].status_2 = ERROR_ELEMENT_OUT_OF_RANGE;
                EXEH_HANDLE(eEXEHSeverity_Error, EXEH_COORDSYS_ELEMENT_OUT_OF_RANGE);
                return false; /* There is an element out of range, no point in proceeding further */
            }
            if (false == fs_coordsys_validate_rows_and_columns(MATRIX_DIM_3D, p_rot_mat))
            {
                latest_status_frames[frame_type].status_2 = ERROR_INVALID_ROW_OR_COLUMN;
                EXEH_HANDLE(eEXEHSeverity_Error, EXEH_COORDSYS_INVALID_ROW_OR_COLUMN);
                return false; /* Row or column fails the requirement of having exactly one non-zero element */
            }
            break;

        case FRAME_COARSE_SUN_SENSOR:
            if (false == fs_coordsys_validate_matrix_elements(MATRIX_DIM_6D, p_rot_mat))
            {
                latest_status_frames[frame_type].status_2 = ERROR_ELEMENT_OUT_OF_RANGE;
                EXEH_HANDLE(eEXEHSeverity_Error, EXEH_COORDSYS_ELEMENT_OUT_OF_RANGE);
                return false; /* There is an element out of range, no point in proceeding further */
            }
            if (false == fs_coordsys_validate_rows_and_columns(MATRIX_DIM_6D, p_rot_mat))
            {
                latest_status_frames[frame_type].status_2 = ERROR_INVALID_ROW_OR_COLUMN;
                EXEH_HANDLE(eEXEHSeverity_Error, EXEH_COORDSYS_INVALID_ROW_OR_COLUMN);
                return false; /* Row or column fails the requirement of having exactly one non-zero element */
            }
            break;

        default:
            latest_status.general_error = ERROR_FRAME_TYPE_INVALID;
            EXEH_HANDLE(eEXEHSeverity_Error, EXEH_COORDSYS_FRAME_TYPE_INVALID);
            return false; /* Unsupported frame type */
    }

    return true;
}
