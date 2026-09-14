/*!
********************************************************************************************
* @file FP_coordsysServerApp.c
* @brief ServerApp implementation template generator
********************************************************************************************
* @version           interface coordsys v2.0
*
* @copyright         (C) Copyright EnduroSat
*
*                    Contents and presentations are protected world-wide.
*                    Any kind of using, copying etc. is prohibited without prior permission.
*                    All rights - incl. industrial property rights - are reserved.
*
*-------------------------------------------------------------------------------------------
* GENERATOR: org.endurosat.generators.macchiato.binders.Gen_C v2.15
*-------------------------------------------------------------------------------------------
* !!! Please note that this code is fully GENERATED and shall not be manually modified as
* all changes will be overwritten !!!
********************************************************************************************
*/

#include "FP_coordsysProtocolServer.h"

// @START_USER@ USER_INCLUDES
#include "coordsys.h"
#include <assert.h>
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL
static void coordsys_get_statusRequestHandlerImpl(ReqContext_t* pReqCtx);

static void coordsys_set_gyroscope_frameRequestHandlerImpl(ReqContext_t* pReqCtx,
            const coordsysset_gyroscope_frameRequestData_t* pRequestData);

static void coordsys_get_gyroscope_frameRequestHandlerImpl(ReqContext_t* pReqCtx);

static void coordsys_get_gyroscope_frame_statusRequestHandlerImpl(ReqContext_t* pReqCtx);

static void coordsys_set_magnetometer_frameRequestHandlerImpl(ReqContext_t* pReqCtx,
            const coordsysset_magnetometer_frameRequestData_t* pRequestData);

static void coordsys_get_magnetometer_frameRequestHandlerImpl(ReqContext_t* pReqCtx);

static void coordsys_get_magnetometer_frame_statusRequestHandlerImpl(ReqContext_t* pReqCtx);

static void coordsys_set_coarse_sun_sensor_frameRequestHandlerImpl(ReqContext_t* pReqCtx,
            const coordsysset_coarse_sun_sensor_frameRequestData_t* pRequestData);

static void coordsys_get_coarse_sun_sensor_frameRequestHandlerImpl(ReqContext_t* pReqCtx);

static void coordsys_get_coarse_sun_sensor_frame_statusRequestHandlerImpl(ReqContext_t* pReqCtx);

static void coordsys_set_magnetorquer_frameRequestHandlerImpl(ReqContext_t* pReqCtx,
            const coordsysset_magnetorquer_frameRequestData_t* pRequestData);

static void coordsys_get_magnetorquer_frameRequestHandlerImpl(ReqContext_t* pReqCtx);

static void coordsys_get_magnetorquer_frame_statusRequestHandlerImpl(ReqContext_t* pReqCtx);

static void coordsys_save_coordsys_configRequestHandlerImpl(ReqContext_t* pReqCtx);

static void coordsys_load_coordsys_configRequestHandlerImpl(ReqContext_t* pReqCtx);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)
// @END_USER@ USER_LOCAL_VARS_DECL

static coordsys_ServerApi_t coordsysServerApiCtx =
{
  .coordsys_get_statusRequestHandler = coordsys_get_statusRequestHandlerImpl,
  .coordsys_set_gyroscope_frameRequestHandler = coordsys_set_gyroscope_frameRequestHandlerImpl,
  .coordsys_get_gyroscope_frameRequestHandler = coordsys_get_gyroscope_frameRequestHandlerImpl,
  .coordsys_get_gyroscope_frame_statusRequestHandler = coordsys_get_gyroscope_frame_statusRequestHandlerImpl,
  .coordsys_set_magnetometer_frameRequestHandler = coordsys_set_magnetometer_frameRequestHandlerImpl,
  .coordsys_get_magnetometer_frameRequestHandler = coordsys_get_magnetometer_frameRequestHandlerImpl,
  .coordsys_get_magnetometer_frame_statusRequestHandler = coordsys_get_magnetometer_frame_statusRequestHandlerImpl,
  .coordsys_set_coarse_sun_sensor_frameRequestHandler = coordsys_set_coarse_sun_sensor_frameRequestHandlerImpl,
  .coordsys_get_coarse_sun_sensor_frameRequestHandler = coordsys_get_coarse_sun_sensor_frameRequestHandlerImpl,
  .coordsys_get_coarse_sun_sensor_frame_statusRequestHandler = coordsys_get_coarse_sun_sensor_frame_statusRequestHandlerImpl,
  .coordsys_set_magnetorquer_frameRequestHandler = coordsys_set_magnetorquer_frameRequestHandlerImpl,
  .coordsys_get_magnetorquer_frameRequestHandler = coordsys_get_magnetorquer_frameRequestHandlerImpl,
  .coordsys_get_magnetorquer_frame_statusRequestHandler = coordsys_get_magnetorquer_frame_statusRequestHandlerImpl,
  .coordsys_save_coordsys_configRequestHandler = coordsys_save_coordsys_configRequestHandlerImpl,
  .coordsys_load_coordsys_configRequestHandler = coordsys_load_coordsys_configRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method coordsys::get_status (ID = 0x00000001)
static void coordsys_get_statusRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    COORDSYS_Status_t sService_status;
    COORDSYS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@coordsys::get_status@
    coordsys_status_t latest_status;
    // @USER_VAR_SECTION_END@coordsys::get_status@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@coordsys::get_status@

        static_assert(COORDSYS_RESULT_OK == COORDSYS_RESULT_ES_OK, "Coordsys result enum mismatch");
        static_assert(COORDSYS_RESULT_FAIL == COORDSYS_RESULT_ES_FAIL, "Coordsys result enum mismatch");
        static_assert((COORDSYS_RESULT_FAIL + 1) == COORDSYS_RESULT_MAX_CNT, "Coordsys result enum mismatch");
        static_assert(ERROR_NONE == COORDSYS_ERROR_NONE, "Coordsys error enum mismatch");
        static_assert(ERROR_NVM_CONFIG_CORRUPTED == COORDSYS_ERROR_NVM_CONFIG_CORRUPTED, "Coordsys error enum mismatch");
        static_assert(ERROR_FRAME_TYPE_INVALID == COORDSYS_ERROR_FRAME_TYPE_INVALID, "Coordsys error enum mismatch");
        static_assert(ERROR_SATELLITE_AXIS_INVALID == COORDSYS_ERROR_SATELLITE_AXIS_INVALID, "Coordsys error enum mismatch");
        static_assert(ERROR_ELEMENT_OUT_OF_RANGE == COORDSYS_ERROR_ELEMENT_OUT_OF_RANGE, "Coordsys error enum mismatch");
        static_assert(ERROR_INVALID_ROW_OR_COLUMN == COORDSYS_ERROR_INVALID_ROW_OR_COLUMN, "Coordsys error enum mismatch");
        static_assert(ERROR_COUNT == COORDSYS_ERROR_MAX_CNT, "Coordsys error enum mismatch");

        /* Retrieve the status information */
        latest_status = coordsys_get_status();

        /* Align with expected data type for FP function */
        sService_status.eGyroscope_frame = (COORDSYS_Result_t)latest_status.gyroscope_frame;
        sService_status.eMagnetometer_frame = (COORDSYS_Result_t)latest_status.magnetometer_frame;
        sService_status.eCoarse_sun_sensor_frame = (COORDSYS_Result_t)latest_status.coarse_sun_sensor_frame;
        sService_status.eMagnetorquer_frame = (COORDSYS_Result_t)latest_status.magnetorquer_frame;
        sService_status.eGeneral_error = (COORDSYS_Error_t)latest_status.general_error;

        eOp_result = COORDSYS_RESULT_ES_OK;

        // @USER_CODE_SECTION_END@coordsys::get_status@

        respResult = coordsys_get_statusResp(
                        &respCtx,
                        &sService_status,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_COORDSYS, COORDSYS_GET_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method coordsys::get_status (ID = 0x00000001)

// @START@ Request handler for method coordsys::set_gyroscope_frame (ID = 0x00000002)
static void coordsys_set_gyroscope_frameRequestHandlerImpl(ReqContext_t *pReqCtx,
            const coordsysset_gyroscope_frameRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    COORDSYS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@coordsys::set_gyroscope_frame@
    coordsys_frame_t desired_frame;
    // @USER_VAR_SECTION_END@coordsys::set_gyroscope_frame@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@coordsys::set_gyroscope_frame@

        /* Unpack the information */
        desired_frame.frame_axis_1 = pRequestData->sDesired_gyr_frame.eGyroscope_1;
        desired_frame.frame_axis_2 = pRequestData->sDesired_gyr_frame.eGyroscope_2;
        desired_frame.frame_axis_3 = pRequestData->sDesired_gyr_frame.eGyroscope_3;

        /* Apply the desired gyroscope frame */
        if (true == coordsys_set_frame(FRAME_GYROSCOPE, &desired_frame))
        {
            eOp_result = COORDSYS_RESULT_ES_OK;
        }
        else
        {
            eOp_result = COORDSYS_RESULT_ES_FAIL;
        }

        // @USER_CODE_SECTION_END@coordsys::set_gyroscope_frame@

        respResult = coordsys_set_gyroscope_frameResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_COORDSYS, COORDSYS_SET_GYROSCOPE_FRAME_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method coordsys::set_gyroscope_frame (ID = 0x00000002)

// @START@ Request handler for method coordsys::get_gyroscope_frame (ID = 0x00000003)
static void coordsys_get_gyroscope_frameRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    COORDSYS_GyroscopeFrame_t sActive_gyr_frame;
    COORDSYS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@coordsys::get_gyroscope_frame@
    coordsys_frame_t active_frame;
    // @USER_VAR_SECTION_END@coordsys::get_gyroscope_frame@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@coordsys::get_gyroscope_frame@

        static_assert(SAT_X_AXIS_POSITIVE == COORDSYS_SATELLITEAXIS_X_POSITIVE, "Coordsys satellite axis enum mismatch");
        static_assert(SAT_Y_AXIS_POSITIVE == COORDSYS_SATELLITEAXIS_Y_POSITIVE, "Coordsys satellite axis enum mismatch");
        static_assert(SAT_Z_AXIS_POSITIVE == COORDSYS_SATELLITEAXIS_Z_POSITIVE, "Coordsys satellite axis enum mismatch");
        static_assert(SAT_X_AXIS_NEGATIVE == COORDSYS_SATELLITEAXIS_X_NEGATIVE, "Coordsys satellite axis enum mismatch");
        static_assert(SAT_Y_AXIS_NEGATIVE == COORDSYS_SATELLITEAXIS_Y_NEGATIVE, "Coordsys satellite axis enum mismatch");
        static_assert(SAT_Z_AXIS_NEGATIVE == COORDSYS_SATELLITEAXIS_Z_NEGATIVE, "Coordsys satellite axis enum mismatch");
        static_assert((SAT_Z_AXIS_NEGATIVE + 1) == COORDSYS_SATELLITEAXIS_MAX_CNT, "Coordsys satellite axis enum mismatch");

        /* Retrieve the currently active gyroscope frame */
        coordsys_get_frame(FRAME_GYROSCOPE, &active_frame);

        /* Unpack the information */
        sActive_gyr_frame.eGyroscope_1 = (COORDSYS_SatelliteAxis_t)active_frame.frame_axis_1;
        sActive_gyr_frame.eGyroscope_2 = (COORDSYS_SatelliteAxis_t)active_frame.frame_axis_2;
        sActive_gyr_frame.eGyroscope_3 = (COORDSYS_SatelliteAxis_t)active_frame.frame_axis_3;

        eOp_result = COORDSYS_RESULT_ES_OK;

        // @USER_CODE_SECTION_END@coordsys::get_gyroscope_frame@

        respResult = coordsys_get_gyroscope_frameResp(
                        &respCtx,
                        &sActive_gyr_frame,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_COORDSYS, COORDSYS_GET_GYROSCOPE_FRAME_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method coordsys::get_gyroscope_frame (ID = 0x00000003)

// @START@ Request handler for method coordsys::get_gyroscope_frame_status (ID = 0x00000004)
static void coordsys_get_gyroscope_frame_statusRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    COORDSYS_FrameStatus_t sGyr_frame_status;
    COORDSYS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@coordsys::get_gyroscope_frame_status@
    coordsys_frame_status_t frame_status;
    // @USER_VAR_SECTION_END@coordsys::get_gyroscope_frame_status@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@coordsys::get_gyroscope_frame_status@

        /* Retrieve gyroscope frame status information */
        frame_status = coordsys_get_status_frame(FRAME_GYROSCOPE);

        /* Transfer to the expected FP function data variable */
        sGyr_frame_status.eStatus_1 = (COORDSYS_Error_t)frame_status.status_1;
        sGyr_frame_status.eStatus_2 = (COORDSYS_Error_t)frame_status.status_2;

        eOp_result = COORDSYS_RESULT_ES_OK;

        // @USER_CODE_SECTION_END@coordsys::get_gyroscope_frame_status@

        respResult = coordsys_get_gyroscope_frame_statusResp(
                        &respCtx,
                        &sGyr_frame_status,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_COORDSYS, COORDSYS_GET_GYROSCOPE_FRAME_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method coordsys::get_gyroscope_frame_status (ID = 0x00000004)

// @START@ Request handler for method coordsys::set_magnetometer_frame (ID = 0x00000005)
static void coordsys_set_magnetometer_frameRequestHandlerImpl(ReqContext_t *pReqCtx,
            const coordsysset_magnetometer_frameRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    COORDSYS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@coordsys::set_magnetometer_frame@
    coordsys_frame_t desired_frame;
    // @USER_VAR_SECTION_END@coordsys::set_magnetometer_frame@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@coordsys::set_magnetometer_frame@

        /* Unpack the information */
        desired_frame.frame_axis_1 = pRequestData->sDesired_mag_frame.eMagnetometer_x;
        desired_frame.frame_axis_2 = pRequestData->sDesired_mag_frame.eMagnetometer_y;
        desired_frame.frame_axis_3 = pRequestData->sDesired_mag_frame.eMagnetometer_z;

        /* Apply the desired magnetometer frame */
        if (true == coordsys_set_frame(FRAME_MAGNETOMETER, &desired_frame))
        {
            eOp_result = COORDSYS_RESULT_ES_OK;
        }
        else
        {
            eOp_result = COORDSYS_RESULT_ES_FAIL;
        }

        // @USER_CODE_SECTION_END@coordsys::set_magnetometer_frame@

        respResult = coordsys_set_magnetometer_frameResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_COORDSYS, COORDSYS_SET_MAGNETOMETER_FRAME_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method coordsys::set_magnetometer_frame (ID = 0x00000005)

// @START@ Request handler for method coordsys::get_magnetometer_frame (ID = 0x00000006)
static void coordsys_get_magnetometer_frameRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    COORDSYS_MagnetometerFrame_t sActive_mag_frame;
    COORDSYS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@coordsys::get_magnetometer_frame@
    coordsys_frame_t active_frame;
    // @USER_VAR_SECTION_END@coordsys::get_magnetometer_frame@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@coordsys::get_magnetometer_frame@

        /* Retrieve the currently active magnetometer frame */
        coordsys_get_frame(FRAME_MAGNETOMETER, &active_frame);

        /* Unpack the information */
        sActive_mag_frame.eMagnetometer_x = (COORDSYS_SatelliteAxis_t)active_frame.frame_axis_1;
        sActive_mag_frame.eMagnetometer_y = (COORDSYS_SatelliteAxis_t)active_frame.frame_axis_2;
        sActive_mag_frame.eMagnetometer_z = (COORDSYS_SatelliteAxis_t)active_frame.frame_axis_3;

        eOp_result = COORDSYS_RESULT_ES_OK;

        // @USER_CODE_SECTION_END@coordsys::get_magnetometer_frame@

        respResult = coordsys_get_magnetometer_frameResp(
                        &respCtx,
                        &sActive_mag_frame,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_COORDSYS, COORDSYS_GET_MAGNETOMETER_FRAME_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method coordsys::get_magnetometer_frame (ID = 0x00000006)

// @START@ Request handler for method coordsys::get_magnetometer_frame_status (ID = 0x00000007)
static void coordsys_get_magnetometer_frame_statusRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    COORDSYS_FrameStatus_t sMag_frame_status;
    COORDSYS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@coordsys::get_magnetometer_frame_status@
    coordsys_frame_status_t frame_status;
    // @USER_VAR_SECTION_END@coordsys::get_magnetometer_frame_status@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@coordsys::get_magnetometer_frame_status@

        /* Retrieve magnetometer frame status information */
        frame_status = coordsys_get_status_frame(FRAME_MAGNETOMETER);

        /* Transfer to the expected FP function data variable */
        sMag_frame_status.eStatus_1 = (COORDSYS_Error_t)frame_status.status_1;
        sMag_frame_status.eStatus_2 = (COORDSYS_Error_t)frame_status.status_2;

        eOp_result = COORDSYS_RESULT_ES_OK;

        // @USER_CODE_SECTION_END@coordsys::get_magnetometer_frame_status@

        respResult = coordsys_get_magnetometer_frame_statusResp(
                        &respCtx,
                        &sMag_frame_status,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_COORDSYS, COORDSYS_GET_MAGNETOMETER_FRAME_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method coordsys::get_magnetometer_frame_status (ID = 0x00000007)

// @START@ Request handler for method coordsys::set_coarse_sun_sensor_frame (ID = 0x00000008)
static void coordsys_set_coarse_sun_sensor_frameRequestHandlerImpl(ReqContext_t *pReqCtx,
            const coordsysset_coarse_sun_sensor_frameRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    COORDSYS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@coordsys::set_coarse_sun_sensor_frame@
    coordsys_frame_t desired_frame;
    // @USER_VAR_SECTION_END@coordsys::set_coarse_sun_sensor_frame@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@coordsys::set_coarse_sun_sensor_frame@

        /* Unpack the information */
        desired_frame.frame_axis_1 = pRequestData->sDesired_css_frame.eCoarse_sun_sensor_1;
        desired_frame.frame_axis_2 = pRequestData->sDesired_css_frame.eCoarse_sun_sensor_2;
        desired_frame.frame_axis_3 = pRequestData->sDesired_css_frame.eCoarse_sun_sensor_3;
        desired_frame.frame_axis_4 = pRequestData->sDesired_css_frame.eCoarse_sun_sensor_4;
        desired_frame.frame_axis_5 = pRequestData->sDesired_css_frame.eCoarse_sun_sensor_5;
        desired_frame.frame_axis_6 = pRequestData->sDesired_css_frame.eCoarse_sun_sensor_6;

        /* Apply the desired coarse sun sensor frame */
        if (true == coordsys_set_frame(FRAME_COARSE_SUN_SENSOR, &desired_frame))
        {
            eOp_result = COORDSYS_RESULT_ES_OK;
        }
        else
        {
            eOp_result = COORDSYS_RESULT_ES_FAIL;
        }

        // @USER_CODE_SECTION_END@coordsys::set_coarse_sun_sensor_frame@

        respResult = coordsys_set_coarse_sun_sensor_frameResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_COORDSYS, COORDSYS_SET_COARSE_SUN_SENSOR_FRAME_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method coordsys::set_coarse_sun_sensor_frame (ID = 0x00000008)

// @START@ Request handler for method coordsys::get_coarse_sun_sensor_frame (ID = 0x00000009)
static void coordsys_get_coarse_sun_sensor_frameRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    COORDSYS_CoarseSunSensorFrame_t sActive_css_frame;
    COORDSYS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@coordsys::get_coarse_sun_sensor_frame@
    coordsys_frame_t active_frame;
    // @USER_VAR_SECTION_END@coordsys::get_coarse_sun_sensor_frame@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@coordsys::get_coarse_sun_sensor_frame@

        /* Retrieve the currently active coarse sun sensor frame */
        coordsys_get_frame(FRAME_COARSE_SUN_SENSOR, &active_frame);

        /* Unpack the information */
        sActive_css_frame.eCoarse_sun_sensor_1 = (COORDSYS_SatelliteAxis_t)active_frame.frame_axis_1;
        sActive_css_frame.eCoarse_sun_sensor_2 = (COORDSYS_SatelliteAxis_t)active_frame.frame_axis_2;
        sActive_css_frame.eCoarse_sun_sensor_3 = (COORDSYS_SatelliteAxis_t)active_frame.frame_axis_3;
        sActive_css_frame.eCoarse_sun_sensor_4 = (COORDSYS_SatelliteAxis_t)active_frame.frame_axis_4;
        sActive_css_frame.eCoarse_sun_sensor_5 = (COORDSYS_SatelliteAxis_t)active_frame.frame_axis_5;
        sActive_css_frame.eCoarse_sun_sensor_6 = (COORDSYS_SatelliteAxis_t)active_frame.frame_axis_6;

        eOp_result = COORDSYS_RESULT_ES_OK;

        // @USER_CODE_SECTION_END@coordsys::get_coarse_sun_sensor_frame@

        respResult = coordsys_get_coarse_sun_sensor_frameResp(
                        &respCtx,
                        &sActive_css_frame,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_COORDSYS, COORDSYS_GET_COARSE_SUN_SENSOR_FRAME_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method coordsys::get_coarse_sun_sensor_frame (ID = 0x00000009)

// @START@ Request handler for method coordsys::get_coarse_sun_sensor_frame_status (ID = 0x0000000A)
static void coordsys_get_coarse_sun_sensor_frame_statusRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    COORDSYS_FrameStatus_t sCss_frame_status;
    COORDSYS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@coordsys::get_coarse_sun_sensor_frame_status@
    coordsys_frame_status_t frame_status;
    // @USER_VAR_SECTION_END@coordsys::get_coarse_sun_sensor_frame_status@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@coordsys::get_coarse_sun_sensor_frame_status@

        /* Retrieve coarse sun sensor frame status information */
        frame_status = coordsys_get_status_frame(FRAME_COARSE_SUN_SENSOR);

        /* Transfer to the expected FP function data variable */
        sCss_frame_status.eStatus_1 = (COORDSYS_Error_t)frame_status.status_1;
        sCss_frame_status.eStatus_2 = (COORDSYS_Error_t)frame_status.status_2;

        eOp_result = COORDSYS_RESULT_ES_OK;

        // @USER_CODE_SECTION_END@coordsys::get_coarse_sun_sensor_frame_status@

        respResult = coordsys_get_coarse_sun_sensor_frame_statusResp(
                        &respCtx,
                        &sCss_frame_status,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_COORDSYS, COORDSYS_GET_COARSE_SUN_SENSOR_FRAME_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method coordsys::get_coarse_sun_sensor_frame_status (ID = 0x0000000A)

// @START@ Request handler for method coordsys::set_magnetorquer_frame (ID = 0x0000000E)
static void coordsys_set_magnetorquer_frameRequestHandlerImpl(ReqContext_t *pReqCtx,
            const coordsysset_magnetorquer_frameRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    COORDSYS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@coordsys::set_magnetorquer_frame@
    coordsys_frame_t desired_frame;
    // @USER_VAR_SECTION_END@coordsys::set_magnetorquer_frame@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@coordsys::set_magnetorquer_frame@

        /* Unpack the information */
        desired_frame.frame_axis_1 = pRequestData->sDesired_mtq_frame.eMagnetorquer_1;
        desired_frame.frame_axis_2 = pRequestData->sDesired_mtq_frame.eMagnetorquer_2;
        desired_frame.frame_axis_3 = pRequestData->sDesired_mtq_frame.eMagnetorquer_3;

        /* Apply the desired magnetorquer frame */
        if (true == coordsys_set_frame(FRAME_MAGNETORQUER, &desired_frame))
        {
            eOp_result = COORDSYS_RESULT_ES_OK;
        }
        else
        {
            eOp_result = COORDSYS_RESULT_ES_FAIL;
        }

        // @USER_CODE_SECTION_END@coordsys::set_magnetorquer_frame@

        respResult = coordsys_set_magnetorquer_frameResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_COORDSYS, COORDSYS_SET_MAGNETORQUER_FRAME_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method coordsys::set_magnetorquer_frame (ID = 0x0000000E)

// @START@ Request handler for method coordsys::get_magnetorquer_frame (ID = 0x0000000F)
static void coordsys_get_magnetorquer_frameRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    COORDSYS_MagnetorquerFrame_t sActive_mtq_frame;
    COORDSYS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@coordsys::get_magnetorquer_frame@
    coordsys_frame_t active_frame;
    // @USER_VAR_SECTION_END@coordsys::get_magnetorquer_frame@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@coordsys::get_magnetorquer_frame@

        /* Retrieve the currently active magnetorquer frame */
        coordsys_get_frame(FRAME_MAGNETORQUER, &active_frame);

        /* Unpack the information */
        sActive_mtq_frame.eMagnetorquer_1 = (COORDSYS_SatelliteAxis_t)active_frame.frame_axis_1;
        sActive_mtq_frame.eMagnetorquer_2 = (COORDSYS_SatelliteAxis_t)active_frame.frame_axis_2;
        sActive_mtq_frame.eMagnetorquer_3 = (COORDSYS_SatelliteAxis_t)active_frame.frame_axis_3;

        eOp_result = COORDSYS_RESULT_ES_OK;

        // @USER_CODE_SECTION_END@coordsys::get_magnetorquer_frame@

        respResult = coordsys_get_magnetorquer_frameResp(
                        &respCtx,
                        &sActive_mtq_frame,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_COORDSYS, COORDSYS_GET_MAGNETORQUER_FRAME_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method coordsys::get_magnetorquer_frame (ID = 0x0000000F)

// @START@ Request handler for method coordsys::get_magnetorquer_frame_status (ID = 0x00000010)
static void coordsys_get_magnetorquer_frame_statusRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    COORDSYS_FrameStatus_t sMtq_frame_status;
    COORDSYS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@coordsys::get_magnetorquer_frame_status@
    coordsys_frame_status_t frame_status;
    // @USER_VAR_SECTION_END@coordsys::get_magnetorquer_frame_status@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@coordsys::get_magnetorquer_frame_status@

        /* Retrieve magnetorquer frame status information */
        frame_status = coordsys_get_status_frame(FRAME_MAGNETORQUER);

        /* Transfer to the expected FP function data variable */
        sMtq_frame_status.eStatus_1 = (COORDSYS_Error_t)frame_status.status_1;
        sMtq_frame_status.eStatus_2 = (COORDSYS_Error_t)frame_status.status_2;

        eOp_result = COORDSYS_RESULT_ES_OK;

        // @USER_CODE_SECTION_END@coordsys::get_magnetorquer_frame_status@

        respResult = coordsys_get_magnetorquer_frame_statusResp(
                        &respCtx,
                        &sMtq_frame_status,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_COORDSYS, COORDSYS_GET_MAGNETORQUER_FRAME_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method coordsys::get_magnetorquer_frame_status (ID = 0x00000010)

// @START@ Request handler for method coordsys::save_coordsys_config (ID = 0x00000011)
static void coordsys_save_coordsys_configRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    COORDSYS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@coordsys::save_coordsys_config@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@coordsys::save_coordsys_config@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@coordsys::save_coordsys_config@

        coordsys_save_config_to_nvm();

        eOp_result = COORDSYS_RESULT_ES_OK;

        // @USER_CODE_SECTION_END@coordsys::save_coordsys_config@

        respResult = coordsys_save_coordsys_configResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_COORDSYS, COORDSYS_SAVE_COORDSYS_CONFIG_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method coordsys::save_coordsys_config (ID = 0x00000011)

// @START@ Request handler for method coordsys::load_coordsys_config (ID = 0x00000012)
static void coordsys_load_coordsys_configRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    COORDSYS_Result_t eOp_result;

    // @USER_VAR_SECTION_START@coordsys::load_coordsys_config@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@coordsys::load_coordsys_config@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@coordsys::load_coordsys_config@

        coordsys_load_config_from_nvm();

        eOp_result = COORDSYS_RESULT_ES_OK;

        // @USER_CODE_SECTION_END@coordsys::load_coordsys_config@

        respResult = coordsys_load_coordsys_configResp(
                        &respCtx,
                        eOp_result
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_COORDSYS, COORDSYS_LOAD_COORDSYS_CONFIG_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method coordsys::load_coordsys_config (ID = 0x00000012)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void coordsysServerAppInit(void)
{
    coordsys_registerServerApi(&coordsysServerApiCtx);
}
