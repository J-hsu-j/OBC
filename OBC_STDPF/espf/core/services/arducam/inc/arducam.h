/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef ARDUCAM_H
#define ARDUCAM_H

/**
 * @addtogroup Services
 * @{
 *
 * @defgroup service_arducam ArduCam OV5642
 * @{
 *
 * The service performs example communication and image taking with the ArduCam OV5642
 * when connected to the camera connector of the OBC.
 *
 * @file arducam.h
 *
 * @brief Public interface of the ArduCam service
 *
 * @}
 * @}
 */

/*
 *********************************************************************************************
 * INCLUDES
 *********************************************************************************************
 */

#include "if_sys_mod.h"
#include "arducam_comm.h"
#include "ov5642.h"

/*
 *********************************************************************************************
 * EXTERNAL DEFINES
 *********************************************************************************************
 */

#define IMG_NAME_LEN 25

/*
 *********************************************************************************************
 * EXTERNAL TYPES DECLARATIONS
 *********************************************************************************************
 */

typedef enum
{
    AC_ERROR                = 0x00,
    AC_SUCCESS              = 0x01,
    AC_CAPTURE_IN_PROGRESS  = 0x02,
    AC_DOWNLOAD_IN_PROGRESS = 0x03,
    AC_DISABLED             = 0xFF
} arducam_status_t;

typedef struct
{
    arducam_status_t                status;
    arducam_output_image_format_t   format;
    arducam_light_mode_t            light;
    arducam_param_levels_t          saturation;
    arducam_param_levels_t          brightness;
    arducam_param_levels_t          contrast;
    arducam_hue_t                   hue;
    arducam_special_effects_t       effect;
    arducam_exposure_level_t        exposure;
    arducam_sharpness_t             sharpness;
    arducam_jpeg_compress_quality_t quality;
    char                            last_img_name[IMG_NAME_LEN];
} arducam_state_ctx_t;

/*
 *********************************************************************************************
 * EXTERNAL VARIABLES DECLARATIONS
 *********************************************************************************************
 */
/*
 *********************************************************************************************
 * EXTERNAL ROUTINES DECLARATIONS
 *********************************************************************************************
 */

/**
 * @brief Initialize the Arducam service and drivers
 * @param level level of initialization (memory, hw and os)
 *
 * @return see @ref mod_op_status_id_t
 */
mod_op_status_id_t arducam_init(sys_init_level_id_t level);

/**
 * @brief Start the arducam service (NOT IMPLEMENTED)
 *
 * @return see @ref mod_op_status_id_t
 */
mod_op_status_id_t arducam_start(void);

/**
 * @brief Stop the arducam service (NOT IMPLEMENTED)
 *
 * @return see @ref mod_op_status_id_t
 */
mod_op_status_id_t arducam_stop(void);

/**
 * @brief Disable the arducam service and drivers
 *
 * @return see @ref mod_op_status_id_t
 */
mod_op_status_id_t arducam_deinit(void);

/**
 * @brief Prepare the sensor for a capture, udpate the registers for a given configuration.
 * @param image_fmt the image format (size) to be used
 * @param jpeg_quality the quality of the compression to be used
 *
 * @return see @ref arducam_status_t
 */
arducam_status_t arducam_prepare_capture(arducam_output_image_format_t   image_fmt,
                                         arducam_jpeg_compress_quality_t jpeg_quality);
/**
 * @brief Trigger a capture in the arducam, set the service to recolect the image data.
 *
 * @return see @ref arducam_status_t
 */
arducam_status_t arducam_begin_capture(void);

/**
 * @brief Force the arducam to be powered off
 */
void arducam_shut_down(void);

/**
 * @brief Create a test pattern image in the camera and store it in the OBC.
 * @param pattern the image pattern to be created.
 *
 * @note This method is not implemented, it only creates an empty image in the filesystem.
 *
 * @return see @ref arducam_status_t
 */
arducam_status_t arducam_test_pattern(arducam_test_pattern_t pattern);

/**
 * @brief Get the the current state of the camera and the arducam service.
 *
 * @return the whole arducam service context @ref arducam_state_ctx_t
 */
arducam_state_ctx_t arducam_get_state(void);

/**
 * @brief Set the arducam and the OV5642 sensor registers to a given configuration.
 * @param light new light mode to be set in the arducam sensor.
 * @param saturation new saturation level to be set in the arducam sensor.
 * @param brightness new brightness level to be set in the arducam sensor.
 * @param contrast new contrast level to be set in the arducam sensor.
 * @param hue new hue to be set in the arducam sensor.
 * @param effect new effect to be set in the arducam sensor.
 * @param exposure new exposure level to be set in the arducam sensor.
 * @param sharpness new sharpness to be set in the arducam sensor.
 *
 * @return the whole arducam service context @ref arducam_state_ctx_t
 */
arducam_status_t arducam_set_sensor_configuration(arducam_light_mode_t      light,
                                                  arducam_param_levels_t    saturation,
                                                  arducam_param_levels_t    brightness,
                                                  arducam_param_levels_t    contrast,
                                                  arducam_hue_t             hue,
                                                  arducam_special_effects_t effect,
                                                  arducam_exposure_level_t  exposure,
                                                  arducam_sharpness_t       sharpness);
#endif /* ARDUCAM_H */
