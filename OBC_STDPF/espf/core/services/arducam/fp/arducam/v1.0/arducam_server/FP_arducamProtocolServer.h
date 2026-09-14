/*!
********************************************************************************************
* @file FP_arducamProtocolServer.h
* @brief ESSA Stack server-side public API declaration
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

#ifndef __FP_ARDUCAMPROTOCOLSERVER_H__
#define __FP_ARDUCAMPROTOCOLSERVER_H__

#include "FP_arducamProtocolTypes.h"

typedef void (*pfarducam_captureRequestHandler_t)(ReqContext_t *ctx, arducamcaptureRequestData_t *pRequestData);
typedef void (*pfarducam_settingsRequestHandler_t)(ReqContext_t *ctx, arducamsettingsRequestData_t *pRequestData);
typedef void (*pfarducam_shut_downRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfarducam_statusRequestHandler_t)(ReqContext_t *ctx);

typedef struct {
    pfarducam_captureRequestHandler_t arducam_captureRequestHandler;
    pfarducam_settingsRequestHandler_t arducam_settingsRequestHandler;
    pfarducam_shut_downRequestHandler_t arducam_shut_downRequestHandler;
    pfarducam_statusRequestHandler_t arducam_statusRequestHandler;
} arducam_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_arducamProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void arducam_registerServerApi(arducam_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_arducamProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t arducam_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes arducam_captureResp(
                RespContext_t* ctx,
                const ARDUCAM_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes arducam_settingsResp(
                RespContext_t* ctx,
                const ARDUCAM_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes arducam_shut_downResp(
                RespContext_t* ctx,
                const ARDUCAM_StandardResult_t eOp_result
);

ESSATMAC_ErrCodes arducam_statusResp(
                RespContext_t* ctx,
                const ARDUCAM_StandardResult_t eOp_result,
                const ARDUCAM_ArducamState_t eCamera_state,
                char * const strLast_image_name,
                const uint8_t u8Last_image_nameSize,
                const ARDUCAM_OutputImageFormat_t eImage_format,
                const ARDUCAM_JpegCompressQuality_t eJpeg_compress_quality,
                const ARDUCAM_LightMode_t eLight_mode,
                const ARDUCAM_ParamsLevels_t eSaturation,
                const ARDUCAM_ParamsLevels_t eBrightness,
                const ARDUCAM_ParamsLevels_t eContrast,
                const ARDUCAM_Hue_t eHue,
                const ARDUCAM_Effects_t eEffect,
                const ARDUCAM_ExposureLevels_t eExposure,
                const ARDUCAM_Sharpness_t eSharpness
);


#endif  // #ifndef __FP_ARDUCAMPROTOCOLSERVER_H__
