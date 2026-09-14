/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup service_arducam
 * @{
 *
 * @file arducam.c
 * @brief ArduCam service main implementation.
 *
 * @}
 */
#include <string.h>
#include "arducam.h"
#include "arducam_comm.h"
#include "trace.h"

#include "MX_I2C.h"
#include "taskmon.h"
#include "sys_time.h"
#include "fm_mng.h"
#include "debug.h"

/*
*********************************************************************************************
* INTERNAL DEFINES
*********************************************************************************************
*/
/** @brief How often does the sensor get polled to see if capture is done performing */
#define ARDUCAM_POLING_INTERVAL_MS (500U)

/** @brief How much time to wait before giving up on capture and restarting camera */
#define ARDUCAM_CAPTURE_TIMEOUT_MS  (10000U)
#define ARDUCAM_SHUTDOWN_TIMEOUT_MS (300000U)

/** @brief How many times to restart camera and try after capture timeout before giving up on the capture command */
#define ARDUCAM_CAPTURE_TIMEOUT_TRIES (3)

#define EN_CAM_HIGH HAL_GPIO_WritePin(EN_CAM_GPIO_Port, EN_CAM_Pin, GPIO_PIN_SET)
#define EN_CAM_LOW  HAL_GPIO_WritePin(EN_CAM_GPIO_Port, EN_CAM_Pin, GPIO_PIN_RESET)

#define BURST_DATA_LEN 512

/*
*********************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
*********************************************************************************************
*/

INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/** @brief OS task handle for the service */
static osThreadId_t h_arducam_task;

/** @brief OS task attributes structure for the service */
static const osThreadAttr_t arducam_task_attr = {
    .name       = "arducam_task",
    .priority   = (osPriority_t)osPriorityNormal,
    .stack_size = 5000
};

/** @brief Non-zero if camera is waiting for capturing */
static bool b_cam_is_capturing;

/** @brief True after camera and sensor initialization, false after a shutdown */
static bool b_is_cam_initialized;

/** @brief When did the last capture start, this is used for timeout-ing
 * if for some reason camera gets stuck */
static uint32_t last_capture_tick_start;
static uint32_t tick_inactive;
static uint8_t  failed_captures_nr;

static arducam_state_ctx_t ac_current_state;
static bool                b_update_format;
static bool                b_update_light;
static bool                b_update_saturation;
static bool                b_update_brightness;
static bool                b_update_contrast;
static bool                b_update_hue;
static bool                b_update_effect;
static bool                b_update_exposure;
static bool                b_update_sharpness;
static bool                b_update_quality;
static uint8_t             burst_buff[BURST_DATA_LEN];
static fm_file_obj_t       h_file;
static fm_result_t         fd_result;
extern uint8_t             comstat;

/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
*********************************************************************************************
*/
static mod_op_status_id_t      arducam_init_memory(void);
static mod_op_status_id_t      arducam_init_hw(void);
static mod_op_status_id_t      arducam_init_os(void);
static arducam_status_t        general_sensor_settings(void);
static void                    arducam_task(void *argument);
static inline arducam_status_t set_state_and_return(arducam_status_t status);
static arducam_status_t        turn_on_and_ready_camera(void);
static arducam_status_t        begin_capture_ex();
static bool                    is_arducam_done_capturing(void);
static void                    set_img_file_name(void);
static bool                    is_soi_in_chunk(uint8_t *buff, uint32_t len, uint32_t *pos);
static bool                    is_eoi_in_chunk(uint8_t *buff, uint32_t len, uint32_t *pos);

/*
*********************************************************************************************
* EXTERNAL (NONE STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/

/**
 * @name Implementation of init for the service.
 */
mod_op_status_id_t arducam_init(sys_init_level_id_t level)
{
    mod_op_status_id_t ret = STATUS_NOT_SUPPORTED;

    // Eventually, to split the initialisation into the different levels
    switch (level)
    {
        case INIT_MEM:
            arducam_init_memory();
            ret = STATUS_OK;
            break;
        case INIT_HW:
            arducam_init_hw();
            ret = STATUS_OK;
            break;
        case INIT_OS:
            arducam_init_os();
            ret = STATUS_OK;
            break;
        default:
            ret = STATUS_NOT_SUPPORTED;
            break;
    }
    return ret;
}

mod_op_status_id_t arducam_start(void)
{
    // This is to be implemented
    return STATUS_NOT_SUPPORTED;
}

mod_op_status_id_t arducam_stop(void)
{
    // This is to be implemented
    return STATUS_NOT_SUPPORTED;
}

mod_op_status_id_t arducam_deinit(void)
{
    task_mon_set_task_policy(TASK_ID_ARDUCAM, TASK_MON_POLICY_DONT_CARE);

    arducam_pin_enable_deinit();
    arducam_spi5_deinit();

    ES_TRACE_INFO("Arducam deinitialized.\n");

    return STATUS_OK;
}

/**
 * @brief Turns on the camera and handles settings, needs to run before capturing photos.
 * If you pass all 0s it will be the default settings which are a good start.
 */
arducam_status_t arducam_prepare_capture(arducam_output_image_format_t   image_fmt,
                                         arducam_jpeg_compress_quality_t jpeg_quality)
{
    if (b_cam_is_capturing)
    {
        return set_state_and_return(AC_CAPTURE_IN_PROGRESS);
    }

    ES_TRACE_INFO("Prepare for capture.\n");
    ES_TRACE_DEBUG("fmt %d, comp %d.\n", image_fmt, jpeg_quality);

    if (AC_FORMAT_COUNT > image_fmt)
    {
        b_update_format         = ac_current_state.format != image_fmt;
        ac_current_state.format = image_fmt;
    }
    else
    {
        ac_current_state.format = AC_JPEG_320x240;
    }

    if (AC_JPEG_QUALITY_COUNT > jpeg_quality)
    {
        b_update_quality         = ac_current_state.quality != jpeg_quality;
        ac_current_state.quality = jpeg_quality;
    }
    else
    {
        ac_current_state.quality = AC_JPEG_DEFAULT_QUALITY;
    }

    ac_current_state.status = turn_on_and_ready_camera();
    if (ac_current_state.status != AC_SUCCESS)
    {
        ES_TRACE_WARN("Failed to ready the camera %d.\n", ac_current_state.status);
        return set_state_and_return(AC_ERROR);
    }

    // Set up the sensor
    if (b_update_format)
    {
        ov5642_set_output_image_format(ac_current_state.format);
    }
    if (b_update_light)
    {
        ov5642_set_light_mode(ac_current_state.light);
    }
    if (b_update_saturation)
    {
        ov5642_set_color_saturation(ac_current_state.saturation);
    }
    if (b_update_brightness)
    {
        ov5642_set_brightness(ac_current_state.brightness);
    }
    if (b_update_contrast)
    {
        ov5642_set_contrast(ac_current_state.contrast);
    }
    if (b_update_hue)
    {
        ov5642_set_hue(ac_current_state.hue);
    }
    if (b_update_effect)
    {
        ov5642_set_effects(ac_current_state.effect);
    }
    if (b_update_exposure)
    {
        ov5642_set_exposure_level(ac_current_state.exposure);
    }
    if (b_update_sharpness)
    {
        ov5642_set_sharpness(ac_current_state.sharpness);
    }
    if (b_update_sharpness)
    {
        ov5642_set_jpeg_compress_quality(ac_current_state.quality);
    }

    arducam_status_t ret = general_sensor_settings();
    // Let auto exposure do it's thing after changing image settings
    osDelay(AC_SETTINGS_DELAY_MS);

    return set_state_and_return(ret);
}

/**
 * @brief Tries to take one photo.
 */
arducam_status_t arducam_begin_capture()
{
    if (b_cam_is_capturing)
    {
        return set_state_and_return(AC_CAPTURE_IN_PROGRESS);
    }

    ES_TRACE_INFO("Start capture.\n");

    failed_captures_nr = 0;
    return begin_capture_ex();
}

/**
 * @brief Creates a dummy 0 byte file on the SD card to verify that the service is working.
 */
arducam_status_t arducam_test_pattern(arducam_test_pattern_t pattern)
{
    if (b_cam_is_capturing)
    {
        return set_state_and_return(AC_CAPTURE_IN_PROGRESS);
    }

    ES_TRACE_INFO("Trigger test pattern: %d\n", pattern);

    strncpy(ac_current_state.last_img_name, "test_pattern.jpg", IMG_NAME_LEN);

    // Test patterns not implemented
    (void)pattern;

    if (fm_is_open(&h_file))
    {
        (void)fm_close(&h_file);
    }

    fd_result = fm_open(&h_file, ac_current_state.last_img_name, FM_MODE_WRITE | FM_MODE_CREATE_ALWAYS);

    if (fd_result == FM_RES_OK)
    {
        uint8_t  data = 0x55;
        uint32_t cnt  = 1;

        fd_result = fm_write(&h_file, &data, cnt, &cnt);
        (void)fm_close(&h_file);
    }
    if (fd_result == FM_RES_OK)
    {
        ES_TRACE_INFO("Saved file as %s\n", ac_current_state.last_img_name);
        return set_state_and_return(AC_SUCCESS);
    }
    else
    {
        ES_TRACE_ERROR("Test file failed with FS error %d.\n", fd_result);
        return set_state_and_return(AC_ERROR);
    }
}

/**
 * @brief Forcefully turns off the camera in case there is suspicion that it's stuck.
 */
void arducam_shut_down(void)
{
    arducam_write_addr_spi(ARDUCHIP_FIFO, FIFO_CLEAR_MASK | FIFO_RDPTR_RST_MASK | FIFO_WRPTR_RST_MASK);
    osDelay(AC_SHUT_DOWN_DELAY);
    EN_CAM_LOW;

    // Reset state variables
    ac_current_state.status = AC_DISABLED;
    b_cam_is_capturing      = false;
    b_is_cam_initialized    = false;
    last_capture_tick_start = 0;
    tick_inactive           = 0;
    failed_captures_nr      = 0;
}

arducam_state_ctx_t arducam_get_state(void)
{
    return ac_current_state;
}

arducam_status_t arducam_set_sensor_configuration(arducam_light_mode_t      light,
                                                  arducam_param_levels_t    saturation,
                                                  arducam_param_levels_t    brightness,
                                                  arducam_param_levels_t    contrast,
                                                  arducam_hue_t             hue,
                                                  arducam_special_effects_t effect,
                                                  arducam_exposure_level_t  exposure,
                                                  arducam_sharpness_t       sharpness)
{
    if (AC_LIGHT_COUNT > light)
    {
        b_update_light         = ac_current_state.light != light;
        ac_current_state.light = light;
    }
    else
    {
        ac_current_state.light = AC_LIGHT_AUTO_SIMPLE;
    }

    if (AC_LEVELS_COUNT > saturation)
    {
        b_update_saturation         = ac_current_state.saturation != saturation;
        ac_current_state.saturation = saturation;
    }
    else
    {
        ac_current_state.saturation = AC_LEVELS_ZERO;
    }

    if (AC_LEVELS_COUNT > brightness)
    {
        b_update_brightness         = ac_current_state.brightness != brightness;
        ac_current_state.brightness = brightness;
    }
    else
    {
        ac_current_state.brightness = AC_LEVELS_ZERO;
    }

    if (AC_LEVELS_COUNT > contrast)
    {
        b_update_contrast         = ac_current_state.contrast != contrast;
        ac_current_state.contrast = contrast;
    }
    else
    {
        ac_current_state.contrast = AC_LEVELS_ZERO;
    }

    if (AC_HUE_COUNT > hue)
    {
        b_update_hue         = ac_current_state.hue != hue;
        ac_current_state.hue = hue;
    }
    else
    {
        ac_current_state.hue = AC_HUE_ZERO;
    }

    if (AC_EFFECTS_COUNT > effect)
    {
        b_update_effect         = ac_current_state.effect != effect;
        ac_current_state.effect = effect;
    }
    else
    {
        ac_current_state.effect = AC_EFFECTS_NORMAL;
    }

    if (AC_EXPOSURE_COUNT > exposure)
    {
        b_update_exposure         = ac_current_state.exposure != exposure;
        ac_current_state.exposure = exposure;
    }
    else
    {
        ac_current_state.exposure = AC_EXPOSURE_DEFAULT;
    }

    if (AC_SHARPNESS_COUNT > sharpness)
    {
        b_update_sharpness         = ac_current_state.sharpness != sharpness;
        ac_current_state.sharpness = sharpness;
    }
    else
    {
        ac_current_state.sharpness = AC_AUTO_SHARPNESS_DEFAULT;
    }

    return AC_SUCCESS;
}

/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/
static mod_op_status_id_t arducam_init_memory(void)
{
    b_cam_is_capturing          = false;
    b_is_cam_initialized        = false;
    last_capture_tick_start     = 0;
    tick_inactive               = 0;
    failed_captures_nr          = 0;
    ac_current_state.status     = AC_DISABLED;
    ac_current_state.format     = AC_FORMAT_COUNT;
    ac_current_state.light      = AC_LIGHT_AUTO_SIMPLE;
    ac_current_state.saturation = AC_LEVELS_ZERO;
    ac_current_state.brightness = AC_LEVELS_ZERO;
    ac_current_state.contrast   = AC_LEVELS_ZERO;
    ac_current_state.hue        = AC_HUE_ZERO;
    ac_current_state.effect     = AC_EFFECTS_NORMAL;
    ac_current_state.exposure   = AC_EXPOSURE_DEFAULT;
    ac_current_state.sharpness  = AC_AUTO_SHARPNESS_DEFAULT;
    ac_current_state.quality    = AC_JPEG_QUALITY_COUNT;

    memset(ac_current_state.last_img_name, 0x00, IMG_NAME_LEN);

    b_update_format     = true;
    b_update_light      = true;
    b_update_saturation = true;
    b_update_brightness = true;
    b_update_contrast   = true;
    b_update_hue        = true;
    b_update_effect     = true;
    b_update_exposure   = true;
    b_update_sharpness  = true;
    b_update_quality    = true;

    return STATUS_OK;
}

static mod_op_status_id_t arducam_init_hw(void)
{
    // Init GPIO and SPI. I2C should be initialized in its drivers.
    arducam_pin_enable_init();
    arducam_spi5_init();

    // Set the chip select high
    ARDUCAM_CS_HIGH;

    return STATUS_OK;
}

static mod_op_status_id_t arducam_init_os(void)
{
    h_arducam_task = osThreadNew(arducam_task, NULL, &arducam_task_attr);
    configASSERT(h_arducam_task);

    // Set the task monitor policy
    task_mon_set_task_policy(TASK_ID_ARDUCAM, TASK_MON_POLICY_MONITOR);

    return STATUS_OK;
}

static arducam_status_t general_sensor_settings(void)
{
    HAL_StatusTypeDef I2C_retStat = HAL_ERROR;
    arducam_status_t  ret         = AC_SUCCESS;
    I2C_retStat                   = mx_i2c_take(MX_I2C_BUS_SYSTEM, 50);
    if (I2C_retStat == HAL_OK)
    {
        // Some necessary sensor settings (reference in the OV5642 docs)
        arducam_comm_write_ov5642(0x3818, 0xa8); // b1010 1000 (??, vertical flip, compression)
        arducam_comm_write_ov5642(0x3621, 0x10); // b0001 0000 (mirror function)
        arducam_comm_write_ov5642(0x3801, 0xb0); // HREF: horizontal start point (low byte)
        arducam_comm_write_ov5642(0x4407, 0x08); // Compression control (Quantization scale)
        arducam_comm_write_ov5642(0x5888, 0x00); // LENC BRV SCALE
        arducam_comm_write_ov5642(0x5000, 0xFF); // ISP Control (all enable)

        // Set VSYNC active
        arducam_write_addr_spi(ARDUCHIP_TIM, VSYNC_LEVEL_MASK);
        mx_i2c_release(MX_I2C_BUS_SYSTEM);
    }
    else
    {
        ES_TRACE_ERROR("MX_I2C_Take HAL error: %d\n", I2C_retStat);
        ret = AC_ERROR;
    }

    return ret;
}

static arducam_status_t turn_on_and_ready_camera(void)
{
    if (b_is_cam_initialized)
    {
        return AC_SUCCESS;
    }

    // Kick the inactive tick
    tick_inactive = HAL_GetTick();

    EN_CAM_HIGH;

    osDelay(AC_START_UP_DELAY);

    // Write and read the test register
    arducam_write_addr_spi(ARDUCHIP_TEST1, 0x55);
    uint8_t reg = arducam_comm_read_addr_spi(ARDUCHIP_TEST1);
    if (reg != 0x55)
    {
        ES_TRACE_ERROR("SPI write/read test failed.\n");
        return set_state_and_return(AC_ERROR);
    }

    // Set the arducam MCU mode
    arducam_write_addr_spi(ARDUCHIP_MODE, MCU2LCD_MODE);
    ES_TRACE_INFO("Arducam chip initialized.\n");

    HAL_StatusTypeDef I2C_retStat = HAL_ERROR;
    I2C_retStat                   = mx_i2c_take(MX_I2C_BUS_SYSTEM, 50);
    if (I2C_retStat == HAL_OK)
    {
        // Send some I2C dummy data
        arducam_comm_write_ov5642(0xff, 0x01);

        // It should match the sensor number (OV5642)
        uint8_t b1 = arducam_comm_read_ov5642(OV5642_I2C_CHIPID_HIGH);
        uint8_t b2 = arducam_comm_read_ov5642(OV5642_I2C_CHIPID_LOW);
        if (b1 != 0x56 || b2 != 0x42)
        {
            ES_TRACE_ERROR("Unexpected Camera ID: %x %x.\n", b1, b2);
            return set_state_and_return(AC_ERROR);
        }
        else
        {
            ES_TRACE_INFO("OV5642 Camera detected: %x %x.\n", b1, b2);
        }

        // Base settings for the sensor
        arducam_comm_write_ov5642(0x3008, 0x80); // Software reset.
        arducam_comm_write_regs_ov5642(ov5642_QVGA_Preview);
        arducam_comm_write_regs_ov5642(ov5642_JPEG_Capture_QSXGA); // QSXGA is 2560x2048

        mx_i2c_release(MX_I2C_BUS_SYSTEM);

        b_is_cam_initialized = true;
    }
    else
    {
        ES_TRACE_ERROR("Failed to take I2C: %d.\n", I2C_retStat);
        return set_state_and_return(AC_ERROR);
    }

    return set_state_and_return(AC_SUCCESS);
}

static arducam_status_t begin_capture_ex()
{
    if (ac_current_state.status != AC_SUCCESS)
    {
        ES_TRACE_ERROR("Camera is not ready for capture.\n");
        return set_state_and_return(AC_ERROR);
    }

    // Kick the inactive tick
    tick_inactive = HAL_GetTick();

    arducam_write_addr_spi(ARDUCHIP_TIM, VSYNC_LEVEL_MASK); // VSYNC is active HIGH
    arducam_write_addr_spi(ARDUCHIP_FIFO, FIFO_CLEAR_MASK); // Flush the FIFO
    arducam_write_addr_spi(ARDUCHIP_FIFO, FIFO_CLEAR_MASK); // clear FIFO flag (same command apparently)
    arducam_write_addr_spi(ARDUCHIP_TRIG, 0);               // Clear the capture done flag
    arducam_write_addr_spi(ARDUCHIP_FIFO, FIFO_START_MASK); // Start capture

    b_cam_is_capturing = true;

    // The service will now check for capture done flag in the loop in  arducam_task

    last_capture_tick_start = HAL_GetTick();

    return set_state_and_return(AC_CAPTURE_IN_PROGRESS);
}

static uint32_t read_arducam_fifo_len(void)
{
    uint32_t len1   = arducam_comm_read_addr_spi(FIFO_SIZE1);
    uint32_t len2   = arducam_comm_read_addr_spi(FIFO_SIZE2);
    uint32_t len3   = arducam_comm_read_addr_spi(FIFO_SIZE3);
    uint32_t length = ((len3 << 16) | (len2 << 8) | len1) & FIFO_AC_MAX_SIZE;

    return length;
}

static bool is_arducam_done_capturing()
{
    if (!b_cam_is_capturing)
    {
        return false;
    }
    return CAP_DONE_MASK == (arducam_comm_read_addr_spi(ARDUCHIP_TRIG) & CAP_DONE_MASK);
}

static void read_and_save_image(void)
{

    ES_TRACE_INFO("Read and save the image.\n");
    ac_current_state.status = AC_DOWNLOAD_IN_PROGRESS;

    // Kick the inactive tick
    tick_inactive = HAL_GetTick();

    set_img_file_name();

    if (fm_is_open(&h_file))
    {
        fm_close(&h_file);
    }

    if (FM_RES_OK == fm_open(&h_file, ac_current_state.last_img_name, FM_MODE_WRITE | FM_MODE_CREATE_ALWAYS))
    {
        ES_TRACE_DEBUG("Open file %s\n", ac_current_state.last_img_name);

        uint32_t fifo_len = read_arducam_fifo_len();
        ES_TRACE_DEBUG("Size of the arducam fifo buffer: %d\n", fifo_len);

        // Variables to contorl the loop flow
        uint32_t bw                 = 0; // Bytes to write into the file
        uint16_t btr                = 0; // Bytes of data to read form the SPI
        uint32_t pos                = 0; // Index of the SOI or EOI markers
        uint32_t total_bw           = 0;
        bool     b_soi_marker_found = false; // SOI marker (Start of Image): 0xFFD8
        bool     b_eoi_marker_found = false; // EOI marker (End of Image) 0xFFD9
        uint8_t  last_byte          = 0;     // Last byte of the previous burst
        uint8_t *p_img_data         = NULL;  // Pointer to where the img data

        while ((fifo_len > 0) && (false == b_eoi_marker_found))
        {
            // Read the next chunk
            btr = (fifo_len > BURST_DATA_LEN) ? BURST_DATA_LEN : (uint16_t)fifo_len;
            memset(burst_buff, 0x00, BURST_DATA_LEN);
            arducam_comm_read_burst_spi(burst_buff, btr);
            fifo_len -= btr;
            ES_TRACE_DEBUG("Left in FIFO %d bytes.\n", fifo_len);

            // By default, we write all the data in the burst_buff
            p_img_data = burst_buff;
            bw         = BURST_DATA_LEN;

            // Still looking for the beggining of the file
            if (false == b_soi_marker_found)
            {
                // Check if we received the SOI marker (Start of Image) 0xFFD8
                if (is_soi_in_chunk(burst_buff, BURST_DATA_LEN, &pos))
                {
                    // Set the data and the bytes to write
                    bw                 = BURST_DATA_LEN - pos;
                    p_img_data         = burst_buff + pos;
                    b_soi_marker_found = true;
                }
                // Check if the SOI marker is between two chunks
                else if (0xFF == last_byte && 0xD8 == burst_buff[0])
                {
                    // Write the last byte of the prvious burst
                    fm_write(&h_file, &last_byte, 1, &bw);
                    total_bw += 1;

                    bw                 = BURST_DATA_LEN;
                    p_img_data         = burst_buff;
                    b_soi_marker_found = true;
                }
            }

            // Check if we received the EOI marker (End of Image) 0xFFD9
            if (is_eoi_in_chunk(p_img_data, BURST_DATA_LEN, &pos))
            {
                // Bytes to write will be what it was minus the
                bw                 = bw - (BURST_DATA_LEN - pos);
                b_eoi_marker_found = true;
            }
            // Check if the EOI Marker is between the two chunks.
            else if (0xFF == last_byte && 0xD9 == burst_buff[0])
            {
                bw                 = 1;
                b_eoi_marker_found = true;
            }

            // We are receiving image data
            if (b_soi_marker_found)
            {
                // Write the data to the file
                fm_write(&h_file, p_img_data, bw, &bw);
                total_bw += bw;
            }

            // Update the last byte to the last byte of the current data burst
            last_byte = p_img_data[bw];
        }

        fm_close(&h_file);
        ES_TRACE_DEBUG("File saved %s [%d bytes].\n", ac_current_state.last_img_name, total_bw);

        if (0 == total_bw || false == b_eoi_marker_found)
        {
            ES_TRACE_ERROR("Image is either empty or incomplete.\n");
            ac_current_state.status = AC_ERROR;
        }
        else
        {
            ac_current_state.status = AC_SUCCESS;
        }
    }

    arducam_write_addr_spi(ARDUCHIP_FIFO, FIFO_CLEAR_MASK | FIFO_RDPTR_RST_MASK | FIFO_WRPTR_RST_MASK);

    b_cam_is_capturing = false;
}

/**
 * @brief Main ArduCam OS task routine
 * Checks if camera is currently in capturing mode, and polls
 * the sensor to see when it's done capturing, after that it saves
 * the image. If the sensor isn't done capturing in certain amount
 * of time, it restarts the camera and tries again, up to 5 times.
 *
 * @param[in] argument reserved for future argument passing to the OS task
 *
 */
static void arducam_task(void *argument)
{
    task_mon_task_initialized(TASK_ID_ARDUCAM);

    // Kick the inactive tick
    tick_inactive = HAL_GetTick();

    while (1)
    {
        task_mon_i_am_alive(TASK_ID_ARDUCAM);

        if (is_arducam_done_capturing())
        {
            ac_current_state.status = AC_SUCCESS;
            read_and_save_image();
        }

        if (b_cam_is_capturing && last_capture_tick_start != 0)
        {
            if ((HAL_GetTick() - last_capture_tick_start) >= ARDUCAM_CAPTURE_TIMEOUT_MS)
            {
                arducam_shut_down();

                ES_TRACE_WARN("Timeout since last capture.\n");

                // Reset camera in hopes of fixing the problem and try again
                // Only try again a maximum number of times
                if (failed_captures_nr < ARDUCAM_CAPTURE_TIMEOUT_TRIES)
                {
                    arducam_prepare_capture(ac_current_state.format,
                                            ac_current_state.quality);

                    if (AC_SUCCESS != begin_capture_ex())
                    {
                        failed_captures_nr++;
                    }
                }
            }
        }

        // If we are not taking pictures currently
        if (AC_ERROR == ac_current_state.status || AC_SUCCESS == ac_current_state.status)
        {
            // Switch off the Arducam after 2 mins
            if ((HAL_GetTick() - tick_inactive) >= ARDUCAM_SHUTDOWN_TIMEOUT_MS)
            {
                arducam_shut_down();
            }
        }

        osDelay(ARDUCAM_POLING_INTERVAL_MS);

        task_mon_low_stack_check(TASK_ID_ARDUCAM);
    }
}

static inline arducam_status_t set_state_and_return(arducam_status_t status)
{
    ac_current_state.status = status;
    return status;
}

static void set_img_file_name(void)
{
    strncpy(ac_current_state.last_img_name, "arducam_capture.raw", IMG_NAME_LEN);

    sys_date_t date;
    sys_time_t time;
    if (sys_time_get_date(&date) && sys_time_get(&time))
    {
        snprintf(ac_current_state.last_img_name, IMG_NAME_LEN, "%02d_%02dh%02dm%02ds.jpg", date.day, time.hour, time.min, time.sec);
    }
    else
    {
        ES_TRACE_WARN("Failed to get system date and time. Using default file name.\n");
    }
}

// Find the SOI marker (FFD8) in a data buffer and return its position
static bool is_soi_in_chunk(uint8_t *buff, uint32_t len, uint32_t *pos)
{
    for (int i = 0; i < len; i++)
    {
        if (0xFF == buff[i] && 0xD8 == buff[i + 1])
        {
            *pos = i; // Position of FF
            return true;
        }
    }

    *pos = len;
    return false;
}

// Find the EOI marker (FFD9) in a data buffer and return the position of the first byte after it
static bool is_eoi_in_chunk(uint8_t *buff, uint32_t len, uint32_t *pos)
{
    for (int i = 0; i < len; i++)
    {
        if (0xFF == buff[i] && 0xD9 == buff[i + 1])
        {
            *pos = i + 2; // Position after D9.
            return true;
        }
    }

    *pos = len;
    return false;
}
