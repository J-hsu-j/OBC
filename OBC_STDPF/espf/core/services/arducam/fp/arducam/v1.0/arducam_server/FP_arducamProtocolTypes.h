/*!
********************************************************************************************
* @file FP_arducamProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface arducam v1.0
*
* @copyright         (C) Copyright EnduroSat
*
*                    Contents and presentations are protected world-wide.
*                    Any kind of using, copying etc. is prohibited without prior permission.
*                    All rights - incl. industrial property rights - are reserved.
*
*-------------------------------------------------------------------------------------------
* GENERATOR: org.endurosat.generators.macchiato.binders.Gen_C v2.12
*-------------------------------------------------------------------------------------------
* !!! Please note that this code is fully GENERATED and shall not be manually modified as
* all changes will be overwritten !!!
********************************************************************************************
*/

#ifndef __FP_ARDUCAMPROTOCOLTYPES_H__
#define __FP_ARDUCAMPROTOCOLTYPES_H__

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_ARDUCAM ((uint16_t) (0x0000012C))

#define ARDUCAM_CAPTURE_FUNC_ID ((funcIdType_t) 0x00000001)
#define ARDUCAM_SETTINGS_FUNC_ID ((funcIdType_t) 0x00000002)
#define ARDUCAM_SHUT_DOWN_FUNC_ID ((funcIdType_t) 0x00000003)
#define ARDUCAM_STATUS_FUNC_ID ((funcIdType_t) 0x00000004)
#define ARDUCAM_CAPTURE_FUNCRESP_ID ((funcIdType_t) 0x00000001)
#define ARDUCAM_SETTINGS_FUNCRESP_ID ((funcIdType_t) 0x00000002)
#define ARDUCAM_SHUT_DOWN_FUNCRESP_ID ((funcIdType_t) 0x00000003)
#define ARDUCAM_STATUS_FUNCRESP_ID ((funcIdType_t) 0x00000004)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    Response data status
*/
#define ARDUCAM_STANDARDRESULT_SUCCESS ((uint8_t) 0)
#define ARDUCAM_STANDARDRESULT_CONNECTION_FAILURE ((uint8_t) 1)
#define ARDUCAM_STANDARDRESULT_ERROR ((uint8_t) 2)
#define ARDUCAM_STANDARDRESULT_CAPTURE_IN_PROGRESS ((uint8_t) 3)
#define ARDUCAM_STANDARDRESULT_MAX_CNT  ((uint8_t) 4)
typedef uint8_t ARDUCAM_StandardResult_t;

/*
    Output size and format of the picture
*/
#define ARDUCAM_OUTPUTIMAGEFORMAT_JPEG_320x240 ((uint8_t) 0)
#define ARDUCAM_OUTPUTIMAGEFORMAT_JPEG_640x480 ((uint8_t) 1)
#define ARDUCAM_OUTPUTIMAGEFORMAT_JPEG_1024x768 ((uint8_t) 2)
#define ARDUCAM_OUTPUTIMAGEFORMAT_JPEG_1280x960 ((uint8_t) 3)
#define ARDUCAM_OUTPUTIMAGEFORMAT_JPEG_1600x1200 ((uint8_t) 4)
#define ARDUCAM_OUTPUTIMAGEFORMAT_JPEG_2048x1536 ((uint8_t) 5)
#define ARDUCAM_OUTPUTIMAGEFORMAT_JPEG_2592x1944 ((uint8_t) 6)
#define ARDUCAM_OUTPUTIMAGEFORMAT_MAX_CNT  ((uint8_t) 7)
typedef uint8_t ARDUCAM_OutputImageFormat_t;

/*
    White balance mode
*/
#define ARDUCAM_LIGHTMODE_AUTO_ADVANCED ((uint8_t) 0)
#define ARDUCAM_LIGHTMODE_AUTO_SIMPLE ((uint8_t) 1)
#define ARDUCAM_LIGHTMODE_MANUAL_DAY ((uint8_t) 2)
#define ARDUCAM_LIGHTMODE_MANUAL_A ((uint8_t) 3)
#define ARDUCAM_LIGHTMODE_MANUAL_CWF ((uint8_t) 4)
#define ARDUCAM_LIGHTMODE_MANUAL_CLOUDY ((uint8_t) 5)
#define ARDUCAM_LIGHTMODE_MAX_CNT  ((uint8_t) 6)
typedef uint8_t ARDUCAM_LightMode_t;

/*
    Exposure level
*/
#define ARDUCAM_EXPOSURELEVELS_MINUS_17_EV ((uint8_t) 0)
#define ARDUCAM_EXPOSURELEVELS_MINUS_13_EV ((uint8_t) 1)
#define ARDUCAM_EXPOSURELEVELS_MINUS_10_EV ((uint8_t) 2)
#define ARDUCAM_EXPOSURELEVELS_MINUS_07_EV ((uint8_t) 3)
#define ARDUCAM_EXPOSURELEVELS_MINUS_03_EV ((uint8_t) 4)
#define ARDUCAM_EXPOSURELEVELS_DEFAULT ((uint8_t) 5)
#define ARDUCAM_EXPOSURELEVELS_PLUS_03_EV ((uint8_t) 6)
#define ARDUCAM_EXPOSURELEVELS_PLUS_07_EV ((uint8_t) 7)
#define ARDUCAM_EXPOSURELEVELS_PLUS_10_EV ((uint8_t) 8)
#define ARDUCAM_EXPOSURELEVELS_PLUS_13_EV ((uint8_t) 9)
#define ARDUCAM_EXPOSURELEVELS_PLUS_17_EV ((uint8_t) 10)
#define ARDUCAM_EXPOSURELEVELS_MAX_CNT  ((uint8_t) 11)
typedef uint8_t ARDUCAM_ExposureLevels_t;

/*
    Parameter levels for the saturation, brightness and contrast
*/
#define ARDUCAM_PARAMSLEVELS_PLUS_4 ((uint8_t) 0)
#define ARDUCAM_PARAMSLEVELS_PLUS_3 ((uint8_t) 1)
#define ARDUCAM_PARAMSLEVELS_PLUS_2 ((uint8_t) 2)
#define ARDUCAM_PARAMSLEVELS_PLUS_1 ((uint8_t) 3)
#define ARDUCAM_PARAMSLEVELS_ZERO ((uint8_t) 4)
#define ARDUCAM_PARAMSLEVELS_MINUS_1 ((uint8_t) 5)
#define ARDUCAM_PARAMSLEVELS_MINUS_2 ((uint8_t) 6)
#define ARDUCAM_PARAMSLEVELS_MINUS_3 ((uint8_t) 7)
#define ARDUCAM_PARAMSLEVELS_MINUS_4 ((uint8_t) 8)
#define ARDUCAM_PARAMSLEVELS_MAX_CNT  ((uint8_t) 9)
typedef uint8_t ARDUCAM_ParamsLevels_t;

/*
    Hue
*/
#define ARDUCAM_HUE_MINUS_180 ((uint8_t) 0)
#define ARDUCAM_HUE_MINUS_150 ((uint8_t) 1)
#define ARDUCAM_HUE_MINUS_120 ((uint8_t) 2)
#define ARDUCAM_HUE_MINUS_90 ((uint8_t) 3)
#define ARDUCAM_HUE_MINUS_60 ((uint8_t) 4)
#define ARDUCAM_HUE_MINUS_30 ((uint8_t) 5)
#define ARDUCAM_HUE_ZERO ((uint8_t) 6)
#define ARDUCAM_HUE_PLUS_30 ((uint8_t) 7)
#define ARDUCAM_HUE_PLUS_60 ((uint8_t) 8)
#define ARDUCAM_HUE_PLUS_90 ((uint8_t) 9)
#define ARDUCAM_HUE_PLUS_120 ((uint8_t) 10)
#define ARDUCAM_HUE_PLUS_150 ((uint8_t) 11)
#define ARDUCAM_HUE_MAX_CNT  ((uint8_t) 12)
typedef uint8_t ARDUCAM_Hue_t;

/*
    Effects
*/
#define ARDUCAM_EFFECTS_BLUISH ((uint8_t) 0)
#define ARDUCAM_EFFECTS_GREENISH ((uint8_t) 1)
#define ARDUCAM_EFFECTS_REDDISH ((uint8_t) 2)
#define ARDUCAM_EFFECTS_BW ((uint8_t) 3)
#define ARDUCAM_EFFECTS_NEGATIVE ((uint8_t) 4)
#define ARDUCAM_EFFECTS_SEPIA ((uint8_t) 5)
#define ARDUCAM_EFFECTS_NORMAL ((uint8_t) 6)
#define ARDUCAM_EFFECTS_MAX_CNT  ((uint8_t) 7)
typedef uint8_t ARDUCAM_Effects_t;

/*
    Sharpness
*/
#define ARDUCAM_SHARPNESS_AUTO_SHARPNESS_DEFAULT ((uint8_t) 0)
#define ARDUCAM_SHARPNESS_AUTO_SHARPNESS_1 ((uint8_t) 1)
#define ARDUCAM_SHARPNESS_AUTO_SHARPNESS_2 ((uint8_t) 2)
#define ARDUCAM_SHARPNESS_MANUAL_SHARPNESS_OFF ((uint8_t) 3)
#define ARDUCAM_SHARPNESS_MANUAL_SHARPNESS_1 ((uint8_t) 4)
#define ARDUCAM_SHARPNESS_MANUAL_SHARPNESS_2 ((uint8_t) 5)
#define ARDUCAM_SHARPNESS_MANUAL_SHARPNESS_3 ((uint8_t) 6)
#define ARDUCAM_SHARPNESS_MANUAL_SHARPNESS_4 ((uint8_t) 7)
#define ARDUCAM_SHARPNESS_MANUAL_SHARPNESS_5 ((uint8_t) 8)
#define ARDUCAM_SHARPNESS_MAX_CNT  ((uint8_t) 9)
typedef uint8_t ARDUCAM_Sharpness_t;

/*
    Mirror Flip
*/
#define ARDUCAM_MIRRORFLIP_MIRROR ((uint8_t) 0)
#define ARDUCAM_MIRRORFLIP_FLIP ((uint8_t) 1)
#define ARDUCAM_MIRRORFLIP_MIRROR_FLIP ((uint8_t) 2)
#define ARDUCAM_MIRRORFLIP_NORMAL ((uint8_t) 3)
#define ARDUCAM_MIRRORFLIP_MAX_CNT  ((uint8_t) 4)
typedef uint8_t ARDUCAM_MirrorFlip_t;

/*
    JPEG Compress Quality
*/
#define ARDUCAM_JPEGCOMPRESSQUALITY_HIGH_QUALITY ((uint8_t) 0)
#define ARDUCAM_JPEGCOMPRESSQUALITY_DEFAULT_QUALITY ((uint8_t) 1)
#define ARDUCAM_JPEGCOMPRESSQUALITY_LOW_QUALITY ((uint8_t) 2)
#define ARDUCAM_JPEGCOMPRESSQUALITY_MAX_CNT  ((uint8_t) 3)
typedef uint8_t ARDUCAM_JpegCompressQuality_t;

#define ARDUCAM_ARDUCAMSTATE_ERROR ((uint8_t) 0)
#define ARDUCAM_ARDUCAMSTATE_SUCCESS ((uint8_t) 1)
#define ARDUCAM_ARDUCAMSTATE_CAPTURE_IN_PROGRESS ((uint8_t) 2)
#define ARDUCAM_ARDUCAMSTATE_DOWNLOAD_IN_PROGRESS ((uint8_t) 3)
#define ARDUCAM_ARDUCAMSTATE_DISABLED ((uint8_t) 255)
#define ARDUCAM_ARDUCAMSTATE_MAX_CNT  ((uint8_t) 256)
typedef uint8_t ARDUCAM_ArducamState_t;


typedef struct {
    ARDUCAM_OutputImageFormat_t eImage_format;
    ARDUCAM_JpegCompressQuality_t eJpeg_compress_quality;
} PACKED_STRUCT arducamcaptureRequestData_t;

typedef struct {
    ARDUCAM_LightMode_t eLight_mode;
    ARDUCAM_ParamsLevels_t eSaturation;
    ARDUCAM_ParamsLevels_t eBrightness;
    ARDUCAM_ParamsLevels_t eContrast;
    ARDUCAM_Hue_t eHue;
    ARDUCAM_Effects_t eEffect;
    ARDUCAM_ExposureLevels_t eExposure;
    ARDUCAM_Sharpness_t eSharpness;
} PACKED_STRUCT arducamsettingsRequestData_t;


typedef struct {
    ARDUCAM_StandardResult_t eOp_result;
} PACKED_STRUCT arducamcaptureResponseData_t;

typedef struct {
    ARDUCAM_StandardResult_t eOp_result;
} PACKED_STRUCT arducamsettingsResponseData_t;

typedef struct {
    ARDUCAM_StandardResult_t eOp_result;
} PACKED_STRUCT arducamshut_downResponseData_t;

typedef struct {
    ARDUCAM_StandardResult_t eOp_result;
    ARDUCAM_ArducamState_t eCamera_state;
    uint8_t u8Last_image_nameSize;
    char strLast_image_name[25];
    ARDUCAM_OutputImageFormat_t eImage_format;
    ARDUCAM_JpegCompressQuality_t eJpeg_compress_quality;
    ARDUCAM_LightMode_t eLight_mode;
    ARDUCAM_ParamsLevels_t eSaturation;
    ARDUCAM_ParamsLevels_t eBrightness;
    ARDUCAM_ParamsLevels_t eContrast;
    ARDUCAM_Hue_t eHue;
    ARDUCAM_Effects_t eEffect;
    ARDUCAM_ExposureLevels_t eExposure;
    ARDUCAM_Sharpness_t eSharpness;
} PACKED_STRUCT arducamstatusResponseData_t;


#endif  // #ifndef __FP_ARDUCAMPROTOCOLTYPES_H__

