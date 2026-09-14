/*!
********************************************************************************************
* @file FP_adis16265_gyroProtocolServer.h
* @brief ESSA Stack server-side public API declaration
********************************************************************************************
* @version           interface adis16265_gyro v1.0
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

#ifndef FP_ADIS16265_GYROPROTOCOLSERVER_H
#define FP_ADIS16265_GYROPROTOCOLSERVER_H

#include "FP_adis16265_gyroProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define adis16265_gyro_PROTOCOL_VERSION_MAJOR   ((uint8_t) 1)
#define adis16265_gyro_PROTOCOL_VERSION_MINOR   ((uint8_t) 0)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfadis16265_gyro_set_gyroscope_configRequestHandler_t)(ReqContext_t *ctx, const adis16265_gyroset_gyroscope_configRequestData_t *pRequestData);
typedef void (*pfadis16265_gyro_get_gyroscope_configRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfadis16265_gyro_save_gyroscope_configRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfadis16265_gyro_load_gyroscope_configRequestHandler_t)(ReqContext_t *ctx);

typedef struct {
    pfadis16265_gyro_set_gyroscope_configRequestHandler_t adis16265_gyro_set_gyroscope_configRequestHandler;
    pfadis16265_gyro_get_gyroscope_configRequestHandler_t adis16265_gyro_get_gyroscope_configRequestHandler;
    pfadis16265_gyro_save_gyroscope_configRequestHandler_t adis16265_gyro_save_gyroscope_configRequestHandler;
    pfadis16265_gyro_load_gyroscope_configRequestHandler_t adis16265_gyro_load_gyroscope_configRequestHandler;
} adis16265_gyro_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_adis16265_gyroProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void adis16265_gyro_registerServerApi(adis16265_gyro_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_adis16265_gyroProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t adis16265_gyro_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes adis16265_gyro_set_gyroscope_configResp(
                RespContext_t* ctx,
                const ADIS16265_GYRO_Result_t eOp_result
);

ESSATMAC_ErrCodes adis16265_gyro_get_gyroscope_configResp(
                RespContext_t* ctx,
                const ADIS16265_GYRO_Panel_t eGyroscope_1,
                const ADIS16265_GYRO_Panel_t eGyroscope_2,
                const ADIS16265_GYRO_Panel_t eGyroscope_3,
                const ADIS16265_GYRO_Result_t eOp_result
);

ESSATMAC_ErrCodes adis16265_gyro_save_gyroscope_configResp(
                RespContext_t* ctx,
                const ADIS16265_GYRO_Result_t eOp_result
);

ESSATMAC_ErrCodes adis16265_gyro_load_gyroscope_configResp(
                RespContext_t* ctx,
                const ADIS16265_GYRO_Result_t eOp_result
);


#endif  // #ifndef FP_ADIS16265_GYROPROTOCOLSERVER_H
