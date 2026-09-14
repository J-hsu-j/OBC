/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef OV5642_H
#define OV5642_H
/**
 * @addtogroup arducam
 * @{
 *
 * @file ov5642.h
 *
 * @brief OV5642 drivers definitions. Registers for controlling the sensor.
 *
 * @}
 */

#include "arducam_comm.h"

/*
*********************************************************************************************
* EXTERNAL DEFINES
*********************************************************************************************
*/
// Spec says there's a 8 MB First in First out buffer
// from which we get the images through SPI.
#define FIFO_AC_MAX_SIZE 0x7fffff

/****************************************************/
/* ArduChip related definition                         */
/****************************************************/
#define RWBIT 0x80 // READ AND WRITE BIT IS BIT[7]

#define ARDUCHIP_TEST1 0x00 // Test register

#define ARDUCHIP_FRAMES 0x01 // Frame control register, Bit[2:0] = Number of frames to be captured
                             // Bit[2:0] = 7 means continuous capture until frame buffer is full

#define ARDUCHIP_MODE 0x02 // Mode register
#define MCU2LCD_MODE  0x00
#define CAM2LCD_MODE  0x01
#define LCD2MCU_MODE  0x02

#define ARDUCHIP_TIM     0x03 // Timing control
#define HREF_LEVEL_MASK  0x01 // 0 = High active,    1 = Low active
#define VSYNC_LEVEL_MASK 0x02 // 0 = High active,    1 = Low active
#define LCD_BKEN_MASK    0x04 // 0 = Enable,         1 = Disable
#define PCLK_DELAY_MASK  0x08 // 0 = data no delay,  1 = data delayed one PCLK

#define ARDUCHIP_FIFO       0x04 // FIFO and I2C control
#define FIFO_CLEAR_MASK     0x01
#define FIFO_START_MASK     0x02
#define FIFO_RDPTR_RST_MASK 0x10
#define FIFO_WRPTR_RST_MASK 0x20

#define ARDUCHIP_GPIO   0x06 // GPIO Write Register
#define GPIO_RESET_MASK 0x01 // 0 = Sensor reset,              1 = Sensor normal operation
#define GPIO_PWDN_MASK  0x02 // 0 = Sensor normal operation,   1 = Sensor standby
#define GPIO_PWREN_MASK 0x04 // 0 = Sensor LDO disable,        1 = sensor LDO enable

#define BURST_FIFO_READ  0x3C // Burst FIFO read operation
#define SINGLE_FIFO_READ 0x3D // Single FIFO read operation

#define ARDUCHIP_REV  0x40 // ArduCHIP revision
#define VER_LOW_MASK  0x3F // Version
#define VER_HIGH_MASK 0xC0 // Version

#define ARDUCHIP_TRIG 0x41 // Trigger source
#define VSYNC_MASK    0x01
#define SHUTTER_MASK  0x02
#define CAP_DONE_MASK 0x08

#define FIFO_SIZE1 0x42 // Camera write FIFO size[7:0] for burst to read
#define FIFO_SIZE2 0x43 // Camera write FIFO size[15:8]
#define FIFO_SIZE3 0x44 // Camera write FIFO size[18:16]

/****************************************************/

/*
*********************************************************************************************
* EXTERNAL TYPES DECLARATIONS
*********************************************************************************************
*/

typedef enum arducam_output_image_format_
{
    AC_JPEG_320x240,
    AC_JPEG_640x480,
    AC_JPEG_1024x768,
    AC_JPEG_1280x960,
    AC_JPEG_1600x1200,
    AC_JPEG_2048x1536,
    AC_JPEG_2592x1944,
    AC_RAW_640x480,
    AC_RAW_1280x960,
    AC_RAW_1920x1080,
    AC_RAW_2592x1944,
    AC_FORMAT_COUNT
} arducam_output_image_format_t;

typedef enum arducam_light_mode_
{
    AC_LIGHT_AUTO_ADVANCED,
    AC_LIGHT_AUTO_SIMPLE,
    AC_LIGHT_MANUAL_DAY,
    AC_LIGHT_MANUAL_A,
    AC_LIGHT_MANUAL_COOL_WHITE_FLUORESCENT,
    AC_LIGHT_MANUAL_CLOUDY,
    AC_LIGHT_COUNT
} arducam_light_mode_t;

// Parameter levels for sturation, brightness and contrast
typedef enum arducam_param_levels_
{
    AC_LEVELS_PLUS_4,
    AC_LEVELS_PLUS_3,
    AC_LEVELS_PLUS_2,
    AC_LEVELS_PLUS_1,
    AC_LEVELS_ZERO,
    AC_LEVELS_MINUS_1,
    AC_LEVELS_MINUS_2,
    AC_LEVELS_MINUS_3,
    AC_LEVELS_MINUS_4,
    AC_LEVELS_COUNT
} arducam_param_levels_t;

typedef enum arducam_hue_
{
    AC_HUE_MINUS_180,
    AC_HUE_MINUS_150,
    AC_HUE_MINUS_120,
    AC_HUE_MINUS_90,
    AC_HUE_MINUS_60,
    AC_HUE_MINUS_30,
    AC_HUE_ZERO,
    AC_HUE_PLUS_30,
    AC_HUE_PLUS_60,
    AC_HUE_PLUS_90,
    AC_HUE_PLUS_120,
    AC_HUE_PLUS_150,
    AC_HUE_COUNT
} arducam_hue_t;

typedef enum arducam_special_effects_
{
    AC_EFFECTS_BLUISH,
    AC_EFFECTS_GREENISH,
    AC_EFFECTS_REDDISH,
    AC_EFFECTS_BW,
    AC_EFFECTS_NEGATIVE,
    AC_EFFECTS_SEPIA,
    AC_EFFECTS_NORMAL,
    AC_EFFECTS_COUNT
} arducam_special_effects_t;

typedef enum arducam_exposure_level_
{
    AC_EXPOSURE_MINUS_17_EV,
    AC_EXPOSURE_MINUS_13_EV,
    AC_EXPOSURE_MINUS_10_EV,
    AC_EXPOSURE_MINUS_07_EV,
    AC_EXPOSURE_MINUS_03_EV,
    AC_EXPOSURE_DEFAULT,
    AC_EXPOSURE_PLUS_03_EV,
    AC_EXPOSURE_PLUS_07_EV,
    AC_EXPOSURE_PLUS_10_EV,
    AC_EXPOSURE_PLUS_13_EV,
    AC_EXPOSURE_PLUS_17_EV,
    AC_EXPOSURE_COUNT
} arducam_exposure_level_t;

typedef enum arducam_sharpness_
{
    AC_AUTO_SHARPNESS_DEFAULT,
    AC_AUTO_SHARPNESS_1,
    AC_AUTO_SHARPNESS_2,
    AC_MANUAL_SHARPNESS_OFF,
    AC_MANUAL_SHARPNESS_1,
    AC_MANUAL_SHARPNESS_2,
    AC_MANUAL_SHARPNESS_3,
    AC_MANUAL_SHARPNESS_4,
    AC_MANUAL_SHARPNESS_5,
    AC_SHARPNESS_COUNT
} arducam_sharpness_t;

typedef enum arducam_jpeg_compress_quality_
{
    AC_JPEG_HIGH_QUALITY,
    AC_JPEG_DEFAULT_QUALITY,
    AC_JPEG_LOW_QUALITY,
    AC_JPEG_QUALITY_COUNT
} arducam_jpeg_compress_quality_t;

typedef enum arducam_test_pattern_
{
    AC_PATTERN_COLOR_BAR,
    AC_PATTERN_COLOR_SQUARE,
    AC_PATTERN_BW_SQUARE,
    AC_PATTERN_DLI,
    AC_PATTERN_COUNT
} arducam_test_pattern_t;

/* TBD: Camera also supports these settings, but are not implemented.


*/

/*
*********************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
*********************************************************************************************
*/
#define OV5642_I2C_CHIPID_HIGH 0x300a
#define OV5642_I2C_CHIPID_LOW  0x300b

extern const struct sensor_reg ov5642_RAW[];
extern const struct sensor_reg ov5642_640x480_RAW[];
extern const struct sensor_reg ov5642_1280x960_RAW[];
extern const struct sensor_reg ov5642_1920x1080_RAW[];
extern const struct sensor_reg ov5642_320x240[];
extern const struct sensor_reg ov5642_640x480[];
extern const struct sensor_reg ov5642_1024x768[];
extern const struct sensor_reg ov5642_1280x960[];
extern const struct sensor_reg ov5642_1600x1200[];
extern const struct sensor_reg ov5642_2048x1536[];
extern const struct sensor_reg ov5642_2592x1944[];
extern const struct sensor_reg ov5642_dvp_zoom8[];
extern const struct sensor_reg ov5642_QVGA_Preview[];
extern const struct sensor_reg ov5642_JPEG_Capture_QSXGA[];
extern const struct sensor_reg ov5642_1080P_Video_setting[];
extern const struct sensor_reg ov5642_720P_Video_setting[];

/*
*********************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
*********************************************************************************************
*/

/**
 * @brief Update the registers according the selected format.
 * @param format New format to be set
 */
void ov5642_set_output_image_format(arducam_output_image_format_t format);

/**
 * @brief Update the registers according the selected light mode.
 * @param mode New light mode to be set
 */
void ov5642_set_light_mode(arducam_light_mode_t mode);

/**
 * @brief Update the registers according the selected saturation level.
 * @param saturation New saturation level to be set
 */
void ov5642_set_color_saturation(arducam_param_levels_t saturation);

/**
 * @brief Update the registers according the selected brightness level.
 * @param brightness New brightness level to be set
 */
void ov5642_set_brightness(arducam_param_levels_t brightness);

/**
 * @brief Update the registers according the selected contrast level.
 * @param contrast New contrast level to be set
 */
void ov5642_set_contrast(arducam_param_levels_t contrast);

/**
 * @brief Update the registers according the selected hue value.
 * @param hue New hue value to be set
 */
void ov5642_set_hue(arducam_hue_t hue);

/**
 * @brief Update the registers according the selected effect.
 * @param effect New effect to be set
 */
void ov5642_set_effects(arducam_special_effects_t effect);

/**
 * @brief Update the registers according the exposure level.
 * @param exposure New exposure level to be set
 */
void ov5642_set_exposure_level(arducam_exposure_level_t exposure);

/**
 * @brief Update the registers according the sharpness level.
 * @param sharpness New sharpness level to be set
 */
void ov5642_set_sharpness(arducam_sharpness_t sharpness);

/**
 * @brief Update the registers according the quality of compression.
 * @param quality New compression quality to be set
 */
void ov5642_set_jpeg_compress_quality(arducam_jpeg_compress_quality_t quality);

#endif /* OV5642_H */
