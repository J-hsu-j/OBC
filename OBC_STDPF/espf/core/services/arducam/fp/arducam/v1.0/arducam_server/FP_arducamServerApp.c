/*!
********************************************************************************************
* @file FP_arducamServerApp.c
* @brief ServerApp implementation template generator
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

#include "FP_arducamProtocolServer.h"

// @START_USER@ USER_INCLUDES
#include "User_types.h"
#include "arducam.h"
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL
static void arducam_captureRequestHandlerImpl(ReqContext_t* pReqCtx,
            const arducamcaptureRequestData_t* pRequestData);

static void arducam_settingsRequestHandlerImpl(ReqContext_t* pReqCtx,
            const arducamsettingsRequestData_t* pRequestData);

static void arducam_shut_downRequestHandlerImpl(ReqContext_t* pReqCtx);

static void arducam_statusRequestHandlerImpl(ReqContext_t* pReqCtx);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_VARS_DECL

static arducam_ServerApi_t arducamServerApiCtx =
{
  .arducam_captureRequestHandler = (pfarducam_captureRequestHandler_t) arducam_captureRequestHandlerImpl,
  .arducam_settingsRequestHandler = (pfarducam_settingsRequestHandler_t) arducam_settingsRequestHandlerImpl,
  .arducam_shut_downRequestHandler = (pfarducam_shut_downRequestHandler_t) arducam_shut_downRequestHandlerImpl,
  .arducam_statusRequestHandler = (pfarducam_statusRequestHandler_t) arducam_statusRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method arducam::capture (ID = 0x00000001)
static void arducam_captureRequestHandlerImpl(ReqContext_t *pReqCtx,
            const arducamcaptureRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    ARDUCAM_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@arducam::capture@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@arducam::capture@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@arducam::capture@

        eOp_result = ARDUCAM_STANDARDRESULT_SUCCESS;

        arducam_status_t pr = arducam_prepare_capture(
            pRequestData->eImage_format,
            pRequestData->eJpeg_compress_quality);
        if (pr != AC_SUCCESS)
        {
            if (pr == AC_ERROR)
                eOp_result = ARDUCAM_STANDARDRESULT_CONNECTION_FAILURE;
            else if (pr == AC_CAPTURE_IN_PROGRESS)
                eOp_result = ARDUCAM_STANDARDRESULT_CAPTURE_IN_PROGRESS;
            else
                eOp_result = ARDUCAM_STANDARDRESULT_ERROR;
        }
        else
        {
            pr = arducam_begin_capture();
            if (AC_CAPTURE_IN_PROGRESS == pr)
                eOp_result = ARDUCAM_STANDARDRESULT_CAPTURE_IN_PROGRESS;
            else if (AC_SUCCESS == pr)
                eOp_result = ARDUCAM_STANDARDRESULT_SUCCESS;
            else
                eOp_result = ARDUCAM_STANDARDRESULT_ERROR;
        }

        // @USER_CODE_SECTION_END@arducam::capture@

        respResult = arducam_captureResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_ARDUCAM, ARDUCAM_CAPTURE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method arducam::capture (ID = 0x00000001)

// @START@ Request handler for method arducam::settings (ID = 0x00000002)
static void arducam_settingsRequestHandlerImpl(ReqContext_t *pReqCtx,
            const arducamsettingsRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    ARDUCAM_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@arducam::settings@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@arducam::settings@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@arducam::settings@

        arducam_status_t res = arducam_set_sensor_configuration(
            pRequestData->eLight_mode,
            pRequestData->eSaturation,
            pRequestData->eBrightness,
            pRequestData->eContrast,
            pRequestData->eHue,
            pRequestData->eEffect,
            pRequestData->eExposure,
            pRequestData->eSharpness);

        if (AC_SUCCESS == res)
        {
            eOp_result = ARDUCAM_STANDARDRESULT_SUCCESS;
        }
        else
        {
            eOp_result = ARDUCAM_STANDARDRESULT_ERROR;
        }

        // @USER_CODE_SECTION_END@arducam::settings@

        respResult = arducam_settingsResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_ARDUCAM, ARDUCAM_SETTINGS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method arducam::settings (ID = 0x00000002)

// @START@ Request handler for method arducam::shut_down (ID = 0x00000003)
static void arducam_shut_downRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    ARDUCAM_StandardResult_t eOp_result;

    // @USER_VAR_SECTION_START@arducam::shut_down@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@arducam::shut_down@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@arducam::shut_down@

        arducam_shut_down();
        eOp_result = ARDUCAM_STANDARDRESULT_SUCCESS;

        // @USER_CODE_SECTION_END@arducam::shut_down@

        respResult = arducam_shut_downResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_ARDUCAM, ARDUCAM_SHUT_DOWN_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method arducam::shut_down (ID = 0x00000003)

// @START@ Request handler for method arducam::status (ID = 0x00000004)
static void arducam_statusRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    ARDUCAM_StandardResult_t eOp_result;
    ARDUCAM_ArducamState_t eCamera_state;
    char strLast_image_name[25];
    uint8_t u8Last_image_nameSize;
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

    // @USER_VAR_SECTION_START@arducam::status@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@arducam::status@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@arducam::status@

        arducam_state_ctx_t cam_ctx = arducam_get_state();
        eCamera_state               = (ARDUCAM_ArducamState_t)cam_ctx.status;
        eImage_format               = (ARDUCAM_OutputImageFormat_t)cam_ctx.format;
        eJpeg_compress_quality      = (ARDUCAM_JpegCompressQuality_t)cam_ctx.quality;
        eLight_mode                 = (ARDUCAM_LightMode_t)cam_ctx.light;
        eSaturation                 = (ARDUCAM_ParamsLevels_t)cam_ctx.saturation;
        eBrightness                 = (ARDUCAM_ParamsLevels_t)cam_ctx.brightness;
        eContrast                   = (ARDUCAM_ParamsLevels_t)cam_ctx.contrast;
        eHue                        = (ARDUCAM_Hue_t)cam_ctx.hue;
        eEffect                     = (ARDUCAM_Effects_t)cam_ctx.effect;
        eExposure                   = (ARDUCAM_ExposureLevels_t)cam_ctx.exposure;
        eSharpness                  = (ARDUCAM_Sharpness_t)cam_ctx.sharpness;
        u8Last_image_nameSize       = 25;
        strncpy(strLast_image_name, cam_ctx.last_img_name, u8Last_image_nameSize);
        eOp_result = ARDUCAM_STANDARDRESULT_SUCCESS;

        // @USER_CODE_SECTION_END@arducam::status@

        respResult = arducam_statusResp(
                        &respCtx,
                        eOp_result,
                        eCamera_state,
                        strLast_image_name,
                        u8Last_image_nameSize,
                        eImage_format,
                        eJpeg_compress_quality,
                        eLight_mode,
                        eSaturation,
                        eBrightness,
                        eContrast,
                        eHue,
                        eEffect,
                        eExposure,
                        eSharpness
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_ARDUCAM, ARDUCAM_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method arducam::status (ID = 0x00000004)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void arducamServerAppInit(void)
{
    arducam_registerServerApi(&arducamServerApiCtx);
}
