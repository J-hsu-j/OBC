/*!
********************************************************************************************
* @file FP_coordsysProtocolServer.h
* @brief ESSA Stack server-side public API declaration
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

#ifndef FP_COORDSYSPROTOCOLSERVER_H
#define FP_COORDSYSPROTOCOLSERVER_H

#include "FP_coordsysProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define coordsys_PROTOCOL_VERSION_MAJOR   ((uint8_t) 2)
#define coordsys_PROTOCOL_VERSION_MINOR   ((uint8_t) 0)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfcoordsys_get_statusRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfcoordsys_set_gyroscope_frameRequestHandler_t)(ReqContext_t *ctx, const coordsysset_gyroscope_frameRequestData_t *pRequestData);
typedef void (*pfcoordsys_get_gyroscope_frameRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfcoordsys_get_gyroscope_frame_statusRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfcoordsys_set_magnetometer_frameRequestHandler_t)(ReqContext_t *ctx, const coordsysset_magnetometer_frameRequestData_t *pRequestData);
typedef void (*pfcoordsys_get_magnetometer_frameRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfcoordsys_get_magnetometer_frame_statusRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfcoordsys_set_coarse_sun_sensor_frameRequestHandler_t)(ReqContext_t *ctx, const coordsysset_coarse_sun_sensor_frameRequestData_t *pRequestData);
typedef void (*pfcoordsys_get_coarse_sun_sensor_frameRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfcoordsys_get_coarse_sun_sensor_frame_statusRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfcoordsys_set_magnetorquer_frameRequestHandler_t)(ReqContext_t *ctx, const coordsysset_magnetorquer_frameRequestData_t *pRequestData);
typedef void (*pfcoordsys_get_magnetorquer_frameRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfcoordsys_get_magnetorquer_frame_statusRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfcoordsys_save_coordsys_configRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfcoordsys_load_coordsys_configRequestHandler_t)(ReqContext_t *ctx);

typedef struct {
    pfcoordsys_get_statusRequestHandler_t coordsys_get_statusRequestHandler;
    pfcoordsys_set_gyroscope_frameRequestHandler_t coordsys_set_gyroscope_frameRequestHandler;
    pfcoordsys_get_gyroscope_frameRequestHandler_t coordsys_get_gyroscope_frameRequestHandler;
    pfcoordsys_get_gyroscope_frame_statusRequestHandler_t coordsys_get_gyroscope_frame_statusRequestHandler;
    pfcoordsys_set_magnetometer_frameRequestHandler_t coordsys_set_magnetometer_frameRequestHandler;
    pfcoordsys_get_magnetometer_frameRequestHandler_t coordsys_get_magnetometer_frameRequestHandler;
    pfcoordsys_get_magnetometer_frame_statusRequestHandler_t coordsys_get_magnetometer_frame_statusRequestHandler;
    pfcoordsys_set_coarse_sun_sensor_frameRequestHandler_t coordsys_set_coarse_sun_sensor_frameRequestHandler;
    pfcoordsys_get_coarse_sun_sensor_frameRequestHandler_t coordsys_get_coarse_sun_sensor_frameRequestHandler;
    pfcoordsys_get_coarse_sun_sensor_frame_statusRequestHandler_t coordsys_get_coarse_sun_sensor_frame_statusRequestHandler;
    pfcoordsys_set_magnetorquer_frameRequestHandler_t coordsys_set_magnetorquer_frameRequestHandler;
    pfcoordsys_get_magnetorquer_frameRequestHandler_t coordsys_get_magnetorquer_frameRequestHandler;
    pfcoordsys_get_magnetorquer_frame_statusRequestHandler_t coordsys_get_magnetorquer_frame_statusRequestHandler;
    pfcoordsys_save_coordsys_configRequestHandler_t coordsys_save_coordsys_configRequestHandler;
    pfcoordsys_load_coordsys_configRequestHandler_t coordsys_load_coordsys_configRequestHandler;
} coordsys_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_coordsysProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void coordsys_registerServerApi(coordsys_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_coordsysProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t coordsys_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes coordsys_get_statusResp(
                RespContext_t* ctx,
                const COORDSYS_Status_t * const sService_status,
                const COORDSYS_Result_t eOp_result
);

ESSATMAC_ErrCodes coordsys_set_gyroscope_frameResp(
                RespContext_t* ctx,
                const COORDSYS_Result_t eOp_result
);

ESSATMAC_ErrCodes coordsys_get_gyroscope_frameResp(
                RespContext_t* ctx,
                const COORDSYS_GyroscopeFrame_t * const sActive_gyr_frame,
                const COORDSYS_Result_t eOp_result
);

ESSATMAC_ErrCodes coordsys_get_gyroscope_frame_statusResp(
                RespContext_t* ctx,
                const COORDSYS_FrameStatus_t * const sGyr_frame_status,
                const COORDSYS_Result_t eOp_result
);

ESSATMAC_ErrCodes coordsys_set_magnetometer_frameResp(
                RespContext_t* ctx,
                const COORDSYS_Result_t eOp_result
);

ESSATMAC_ErrCodes coordsys_get_magnetometer_frameResp(
                RespContext_t* ctx,
                const COORDSYS_MagnetometerFrame_t * const sActive_mag_frame,
                const COORDSYS_Result_t eOp_result
);

ESSATMAC_ErrCodes coordsys_get_magnetometer_frame_statusResp(
                RespContext_t* ctx,
                const COORDSYS_FrameStatus_t * const sMag_frame_status,
                const COORDSYS_Result_t eOp_result
);

ESSATMAC_ErrCodes coordsys_set_coarse_sun_sensor_frameResp(
                RespContext_t* ctx,
                const COORDSYS_Result_t eOp_result
);

ESSATMAC_ErrCodes coordsys_get_coarse_sun_sensor_frameResp(
                RespContext_t* ctx,
                const COORDSYS_CoarseSunSensorFrame_t * const sActive_css_frame,
                const COORDSYS_Result_t eOp_result
);

ESSATMAC_ErrCodes coordsys_get_coarse_sun_sensor_frame_statusResp(
                RespContext_t* ctx,
                const COORDSYS_FrameStatus_t * const sCss_frame_status,
                const COORDSYS_Result_t eOp_result
);

ESSATMAC_ErrCodes coordsys_set_magnetorquer_frameResp(
                RespContext_t* ctx,
                const COORDSYS_Result_t eOp_result
);

ESSATMAC_ErrCodes coordsys_get_magnetorquer_frameResp(
                RespContext_t* ctx,
                const COORDSYS_MagnetorquerFrame_t * const sActive_mtq_frame,
                const COORDSYS_Result_t eOp_result
);

ESSATMAC_ErrCodes coordsys_get_magnetorquer_frame_statusResp(
                RespContext_t* ctx,
                const COORDSYS_FrameStatus_t * const sMtq_frame_status,
                const COORDSYS_Result_t eOp_result
);

ESSATMAC_ErrCodes coordsys_save_coordsys_configResp(
                RespContext_t* ctx,
                const COORDSYS_Result_t eOp_result
);

ESSATMAC_ErrCodes coordsys_load_coordsys_configResp(
                RespContext_t* ctx,
                const COORDSYS_Result_t eOp_result
);


#endif  // #ifndef FP_COORDSYSPROTOCOLSERVER_H
