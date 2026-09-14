/*!
********************************************************************************************
* @file FP_coordsysProtocolServer.c
* @brief ESSA Stack server-side implementation
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
#include "FP_common/FP_ProtocolServerCommon.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Local type definitions
 *
 **********************************************************************/
typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT coordsysget_statusProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    coordsysget_statusResponseData_t data;
} PACKED_STRUCT coordsysget_statusProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    coordsysset_gyroscope_frameRequestData_t data;
} PACKED_STRUCT coordsysset_gyroscope_frameProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    coordsysset_gyroscope_frameResponseData_t data;
} PACKED_STRUCT coordsysset_gyroscope_frameProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT coordsysget_gyroscope_frameProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    coordsysget_gyroscope_frameResponseData_t data;
} PACKED_STRUCT coordsysget_gyroscope_frameProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT coordsysget_gyroscope_frame_statusProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    coordsysget_gyroscope_frame_statusResponseData_t data;
} PACKED_STRUCT coordsysget_gyroscope_frame_statusProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    coordsysset_magnetometer_frameRequestData_t data;
} PACKED_STRUCT coordsysset_magnetometer_frameProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    coordsysset_magnetometer_frameResponseData_t data;
} PACKED_STRUCT coordsysset_magnetometer_frameProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT coordsysget_magnetometer_frameProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    coordsysget_magnetometer_frameResponseData_t data;
} PACKED_STRUCT coordsysget_magnetometer_frameProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT coordsysget_magnetometer_frame_statusProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    coordsysget_magnetometer_frame_statusResponseData_t data;
} PACKED_STRUCT coordsysget_magnetometer_frame_statusProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    coordsysset_coarse_sun_sensor_frameRequestData_t data;
} PACKED_STRUCT coordsysset_coarse_sun_sensor_frameProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    coordsysset_coarse_sun_sensor_frameResponseData_t data;
} PACKED_STRUCT coordsysset_coarse_sun_sensor_frameProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT coordsysget_coarse_sun_sensor_frameProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    coordsysget_coarse_sun_sensor_frameResponseData_t data;
} PACKED_STRUCT coordsysget_coarse_sun_sensor_frameProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT coordsysget_coarse_sun_sensor_frame_statusProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    coordsysget_coarse_sun_sensor_frame_statusResponseData_t data;
} PACKED_STRUCT coordsysget_coarse_sun_sensor_frame_statusProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    coordsysset_magnetorquer_frameRequestData_t data;
} PACKED_STRUCT coordsysset_magnetorquer_frameProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    coordsysset_magnetorquer_frameResponseData_t data;
} PACKED_STRUCT coordsysset_magnetorquer_frameProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT coordsysget_magnetorquer_frameProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    coordsysget_magnetorquer_frameResponseData_t data;
} PACKED_STRUCT coordsysget_magnetorquer_frameProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT coordsysget_magnetorquer_frame_statusProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    coordsysget_magnetorquer_frame_statusResponseData_t data;
} PACKED_STRUCT coordsysget_magnetorquer_frame_statusProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT coordsyssave_coordsys_configProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    coordsyssave_coordsys_configResponseData_t data;
} PACKED_STRUCT coordsyssave_coordsys_configProtocolResponseData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
} PACKED_STRUCT coordsysload_coordsys_configProtocolRequestData_t;

typedef struct {
    ESSA_Stack_FP_MsgHdr_t hdr;
    coordsysload_coordsys_configResponseData_t data;
} PACKED_STRUCT coordsysload_coordsys_configProtocolResponseData_t;


/**********************************************************************
 *
 *  Static methods declarations
 *
 **********************************************************************/
static bool fs_HandleData(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_statusReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_gyroscope_frameReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_gyroscope_frameReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_gyroscope_frame_statusReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_magnetometer_frameReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_magnetometer_frameReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_magnetometer_frame_statusReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_coarse_sun_sensor_frameReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_coarse_sun_sensor_frameReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_coarse_sun_sensor_frame_statusReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_set_magnetorquer_frameReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_magnetorquer_frameReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_get_magnetorquer_frame_statusReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_save_coordsys_configReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);
static void fs_load_coordsys_configReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo);

/**********************************************************************
 *
 *  Public variable definitions
 *
 **********************************************************************/
const ESSA_Stack_FunctionProtocolInfo_t FP_coordsysProtocolServerInfo = {
    .u16ProtocolId    = ES_SAT_FUNC_PROTOCOL_ID_COORDSYS,
        .pfDataHandlerCbk = &fs_HandleData
};

/**********************************************************************
 *
 *  Static variable definitions
 *
 **********************************************************************/
static coordsys_ServerApi_t *pSrvApiHnd = NULL;

static const ProtocolFuncArrayEntry_t fs_aFuncArray[] = {
    { COORDSYS_GET_STATUS_FUNC_ID, fs_get_statusReq },
    { COORDSYS_SET_GYROSCOPE_FRAME_FUNC_ID, fs_set_gyroscope_frameReq },
    { COORDSYS_GET_GYROSCOPE_FRAME_FUNC_ID, fs_get_gyroscope_frameReq },
    { COORDSYS_GET_GYROSCOPE_FRAME_STATUS_FUNC_ID, fs_get_gyroscope_frame_statusReq },
    { COORDSYS_SET_MAGNETOMETER_FRAME_FUNC_ID, fs_set_magnetometer_frameReq },
    { COORDSYS_GET_MAGNETOMETER_FRAME_FUNC_ID, fs_get_magnetometer_frameReq },
    { COORDSYS_GET_MAGNETOMETER_FRAME_STATUS_FUNC_ID, fs_get_magnetometer_frame_statusReq },
    { COORDSYS_SET_COARSE_SUN_SENSOR_FRAME_FUNC_ID, fs_set_coarse_sun_sensor_frameReq },
    { COORDSYS_GET_COARSE_SUN_SENSOR_FRAME_FUNC_ID, fs_get_coarse_sun_sensor_frameReq },
    { COORDSYS_GET_COARSE_SUN_SENSOR_FRAME_STATUS_FUNC_ID, fs_get_coarse_sun_sensor_frame_statusReq },
    { COORDSYS_SET_MAGNETORQUER_FRAME_FUNC_ID, fs_set_magnetorquer_frameReq },
    { COORDSYS_GET_MAGNETORQUER_FRAME_FUNC_ID, fs_get_magnetorquer_frameReq },
    { COORDSYS_GET_MAGNETORQUER_FRAME_STATUS_FUNC_ID, fs_get_magnetorquer_frame_statusReq },
    { COORDSYS_SAVE_COORDSYS_CONFIG_FUNC_ID, fs_save_coordsys_configReq },
    { COORDSYS_LOAD_COORDSYS_CONFIG_FUNC_ID, fs_load_coordsys_configReq }
};

/**********************************************************************
 *
 *  Static methods implementation
 *
 **********************************************************************/
static bool fs_HandleData(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    return FP_Helpers_HandleDataInternal(fp_DataInfo, &fs_aFuncArray[0], (const uint16_t) COUNT_OF(fs_aFuncArray));
}







static void fs_get_statusReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    coordsysget_statusProtocolRequestData_t *fullrequest = (coordsysget_statusProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(coordsysget_statusProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->coordsys_get_statusRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->coordsys_get_statusRequestHandler(&requestCtx);
    }
}

static void fs_set_gyroscope_frameReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    coordsysset_gyroscope_frameProtocolRequestData_t *fullrequest = (coordsysset_gyroscope_frameProtocolRequestData_t *) fp_DataInfo->pu8Data;
    coordsysset_gyroscope_frameRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(coordsysset_gyroscope_frameProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (coordsysset_gyroscope_frameRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->coordsys_set_gyroscope_frameRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->coordsys_set_gyroscope_frameRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_gyroscope_frameReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    coordsysget_gyroscope_frameProtocolRequestData_t *fullrequest = (coordsysget_gyroscope_frameProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(coordsysget_gyroscope_frameProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->coordsys_get_gyroscope_frameRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->coordsys_get_gyroscope_frameRequestHandler(&requestCtx);
    }
}

static void fs_get_gyroscope_frame_statusReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    coordsysget_gyroscope_frame_statusProtocolRequestData_t *fullrequest = (coordsysget_gyroscope_frame_statusProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(coordsysget_gyroscope_frame_statusProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->coordsys_get_gyroscope_frame_statusRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->coordsys_get_gyroscope_frame_statusRequestHandler(&requestCtx);
    }
}

static void fs_set_magnetometer_frameReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    coordsysset_magnetometer_frameProtocolRequestData_t *fullrequest = (coordsysset_magnetometer_frameProtocolRequestData_t *) fp_DataInfo->pu8Data;
    coordsysset_magnetometer_frameRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(coordsysset_magnetometer_frameProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (coordsysset_magnetometer_frameRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->coordsys_set_magnetometer_frameRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->coordsys_set_magnetometer_frameRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_magnetometer_frameReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    coordsysget_magnetometer_frameProtocolRequestData_t *fullrequest = (coordsysget_magnetometer_frameProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(coordsysget_magnetometer_frameProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->coordsys_get_magnetometer_frameRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->coordsys_get_magnetometer_frameRequestHandler(&requestCtx);
    }
}

static void fs_get_magnetometer_frame_statusReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    coordsysget_magnetometer_frame_statusProtocolRequestData_t *fullrequest = (coordsysget_magnetometer_frame_statusProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(coordsysget_magnetometer_frame_statusProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->coordsys_get_magnetometer_frame_statusRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->coordsys_get_magnetometer_frame_statusRequestHandler(&requestCtx);
    }
}

static void fs_set_coarse_sun_sensor_frameReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    coordsysset_coarse_sun_sensor_frameProtocolRequestData_t *fullrequest = (coordsysset_coarse_sun_sensor_frameProtocolRequestData_t *) fp_DataInfo->pu8Data;
    coordsysset_coarse_sun_sensor_frameRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(coordsysset_coarse_sun_sensor_frameProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (coordsysset_coarse_sun_sensor_frameRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->coordsys_set_coarse_sun_sensor_frameRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->coordsys_set_coarse_sun_sensor_frameRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_coarse_sun_sensor_frameReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    coordsysget_coarse_sun_sensor_frameProtocolRequestData_t *fullrequest = (coordsysget_coarse_sun_sensor_frameProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(coordsysget_coarse_sun_sensor_frameProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->coordsys_get_coarse_sun_sensor_frameRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->coordsys_get_coarse_sun_sensor_frameRequestHandler(&requestCtx);
    }
}

static void fs_get_coarse_sun_sensor_frame_statusReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    coordsysget_coarse_sun_sensor_frame_statusProtocolRequestData_t *fullrequest = (coordsysget_coarse_sun_sensor_frame_statusProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(coordsysget_coarse_sun_sensor_frame_statusProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->coordsys_get_coarse_sun_sensor_frame_statusRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->coordsys_get_coarse_sun_sensor_frame_statusRequestHandler(&requestCtx);
    }
}

static void fs_set_magnetorquer_frameReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    coordsysset_magnetorquer_frameProtocolRequestData_t *fullrequest = (coordsysset_magnetorquer_frameProtocolRequestData_t *) fp_DataInfo->pu8Data;
    coordsysset_magnetorquer_frameRequestData_t *requestPayload = NULL;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(coordsysset_magnetorquer_frameProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    requestPayload = (coordsysset_magnetorquer_frameRequestData_t *) &fullrequest->data;
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->coordsys_set_magnetorquer_frameRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->coordsys_set_magnetorquer_frameRequestHandler(&requestCtx,
                                        requestPayload);
    }
}

static void fs_get_magnetorquer_frameReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    coordsysget_magnetorquer_frameProtocolRequestData_t *fullrequest = (coordsysget_magnetorquer_frameProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(coordsysget_magnetorquer_frameProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->coordsys_get_magnetorquer_frameRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->coordsys_get_magnetorquer_frameRequestHandler(&requestCtx);
    }
}

static void fs_get_magnetorquer_frame_statusReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    coordsysget_magnetorquer_frame_statusProtocolRequestData_t *fullrequest = (coordsysget_magnetorquer_frame_statusProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(coordsysget_magnetorquer_frame_statusProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->coordsys_get_magnetorquer_frame_statusRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->coordsys_get_magnetorquer_frame_statusRequestHandler(&requestCtx);
    }
}

static void fs_save_coordsys_configReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    coordsyssave_coordsys_configProtocolRequestData_t *fullrequest = (coordsyssave_coordsys_configProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(coordsyssave_coordsys_configProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->coordsys_save_coordsys_configRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->coordsys_save_coordsys_configRequestHandler(&requestCtx);
    }
}

static void fs_load_coordsys_configReq(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo)
{
    coordsysload_coordsys_configProtocolRequestData_t *fullrequest = (coordsysload_coordsys_configProtocolRequestData_t *) fp_DataInfo->pu8Data;
    ReqContext_t requestCtx;

    STATIC_ASSERT_SIZE_CHECK(coordsysload_coordsys_configProtocolRequestData_t);

    if ((fullrequest == NULL) || (pSrvApiHnd == NULL) || (fp_DataInfo->u16DataSize != sizeof(*fullrequest)))
    {
        return;
    }
#ifndef BIG_ENDIAN_PLATFORM
    // no out-arguments specified for response - simple acknowledge call
#else   // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Deserialize response fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    if (pSrvApiHnd->coordsys_load_coordsys_configRequestHandler != NULL)
    {
        requestCtx.nInterfaceNumber = fp_DataInfo->pMACContext->nInterfaceNumber;
        requestCtx.netType = fp_DataInfo->pMACContext->netType;
        requestCtx.nAddr = fp_DataInfo->pMACContext->nSourceAddr;
        requestCtx.seqId = fullrequest->hdr.seqId;

        pSrvApiHnd->coordsys_load_coordsys_configRequestHandler(&requestCtx);
    }
}


/**********************************************************************
 *
 *  Public methods implementation
 *
 **********************************************************************/
void coordsys_registerServerApi(coordsys_ServerApi_t *pSrvApiHandlers)
{
    pSrvApiHnd = pSrvApiHandlers;
}

ESSA_pStack_FunctionProtocolInfo_t coordsys_getServerProtocolDescriptor(void)
{
    return (ESSA_pStack_FunctionProtocolInfo_t) &FP_coordsysProtocolServerInfo;
}

ESSATMAC_ErrCodes coordsys_get_statusResp(
                RespContext_t* ctx,
                const COORDSYS_Status_t * const sService_status,
                const COORDSYS_Result_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    coordsysget_statusProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(coordsysget_statusProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(coordsysget_statusProtocolResponseData_t);

    if ((ctx != NULL) && (sService_status != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_COORDSYS;
        responseParams.hdr.funcId  = COORDSYS_GET_STATUS_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        if (sService_status != NULL)
        {
            responseParams.data.sService_status = *(sService_status);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sService_status,
                          0U,
                          sizeof(responseParams.data.sService_status));
        }
        responseParams.data.eOp_result = eOp_result;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(coordsysget_statusProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes coordsys_set_gyroscope_frameResp(
                RespContext_t* ctx,
                const COORDSYS_Result_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    coordsysset_gyroscope_frameProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(coordsysset_gyroscope_frameProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(coordsysset_gyroscope_frameProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_COORDSYS;
        responseParams.hdr.funcId  = COORDSYS_SET_GYROSCOPE_FRAME_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eOp_result = eOp_result;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(coordsysset_gyroscope_frameProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes coordsys_get_gyroscope_frameResp(
                RespContext_t* ctx,
                const COORDSYS_GyroscopeFrame_t * const sActive_gyr_frame,
                const COORDSYS_Result_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    coordsysget_gyroscope_frameProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(coordsysget_gyroscope_frameProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(coordsysget_gyroscope_frameProtocolResponseData_t);

    if ((ctx != NULL) && (sActive_gyr_frame != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_COORDSYS;
        responseParams.hdr.funcId  = COORDSYS_GET_GYROSCOPE_FRAME_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        if (sActive_gyr_frame != NULL)
        {
            responseParams.data.sActive_gyr_frame = *(sActive_gyr_frame);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sActive_gyr_frame,
                          0U,
                          sizeof(responseParams.data.sActive_gyr_frame));
        }
        responseParams.data.eOp_result = eOp_result;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(coordsysget_gyroscope_frameProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes coordsys_get_gyroscope_frame_statusResp(
                RespContext_t* ctx,
                const COORDSYS_FrameStatus_t * const sGyr_frame_status,
                const COORDSYS_Result_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    coordsysget_gyroscope_frame_statusProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(coordsysget_gyroscope_frame_statusProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(coordsysget_gyroscope_frame_statusProtocolResponseData_t);

    if ((ctx != NULL) && (sGyr_frame_status != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_COORDSYS;
        responseParams.hdr.funcId  = COORDSYS_GET_GYROSCOPE_FRAME_STATUS_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        if (sGyr_frame_status != NULL)
        {
            responseParams.data.sGyr_frame_status = *(sGyr_frame_status);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sGyr_frame_status,
                          0U,
                          sizeof(responseParams.data.sGyr_frame_status));
        }
        responseParams.data.eOp_result = eOp_result;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(coordsysget_gyroscope_frame_statusProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes coordsys_set_magnetometer_frameResp(
                RespContext_t* ctx,
                const COORDSYS_Result_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    coordsysset_magnetometer_frameProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(coordsysset_magnetometer_frameProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(coordsysset_magnetometer_frameProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_COORDSYS;
        responseParams.hdr.funcId  = COORDSYS_SET_MAGNETOMETER_FRAME_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eOp_result = eOp_result;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(coordsysset_magnetometer_frameProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes coordsys_get_magnetometer_frameResp(
                RespContext_t* ctx,
                const COORDSYS_MagnetometerFrame_t * const sActive_mag_frame,
                const COORDSYS_Result_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    coordsysget_magnetometer_frameProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(coordsysget_magnetometer_frameProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(coordsysget_magnetometer_frameProtocolResponseData_t);

    if ((ctx != NULL) && (sActive_mag_frame != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_COORDSYS;
        responseParams.hdr.funcId  = COORDSYS_GET_MAGNETOMETER_FRAME_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        if (sActive_mag_frame != NULL)
        {
            responseParams.data.sActive_mag_frame = *(sActive_mag_frame);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sActive_mag_frame,
                          0U,
                          sizeof(responseParams.data.sActive_mag_frame));
        }
        responseParams.data.eOp_result = eOp_result;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(coordsysget_magnetometer_frameProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes coordsys_get_magnetometer_frame_statusResp(
                RespContext_t* ctx,
                const COORDSYS_FrameStatus_t * const sMag_frame_status,
                const COORDSYS_Result_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    coordsysget_magnetometer_frame_statusProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(coordsysget_magnetometer_frame_statusProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(coordsysget_magnetometer_frame_statusProtocolResponseData_t);

    if ((ctx != NULL) && (sMag_frame_status != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_COORDSYS;
        responseParams.hdr.funcId  = COORDSYS_GET_MAGNETOMETER_FRAME_STATUS_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        if (sMag_frame_status != NULL)
        {
            responseParams.data.sMag_frame_status = *(sMag_frame_status);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sMag_frame_status,
                          0U,
                          sizeof(responseParams.data.sMag_frame_status));
        }
        responseParams.data.eOp_result = eOp_result;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(coordsysget_magnetometer_frame_statusProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes coordsys_set_coarse_sun_sensor_frameResp(
                RespContext_t* ctx,
                const COORDSYS_Result_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    coordsysset_coarse_sun_sensor_frameProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(coordsysset_coarse_sun_sensor_frameProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(coordsysset_coarse_sun_sensor_frameProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_COORDSYS;
        responseParams.hdr.funcId  = COORDSYS_SET_COARSE_SUN_SENSOR_FRAME_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eOp_result = eOp_result;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(coordsysset_coarse_sun_sensor_frameProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes coordsys_get_coarse_sun_sensor_frameResp(
                RespContext_t* ctx,
                const COORDSYS_CoarseSunSensorFrame_t * const sActive_css_frame,
                const COORDSYS_Result_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    coordsysget_coarse_sun_sensor_frameProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(coordsysget_coarse_sun_sensor_frameProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(coordsysget_coarse_sun_sensor_frameProtocolResponseData_t);

    if ((ctx != NULL) && (sActive_css_frame != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_COORDSYS;
        responseParams.hdr.funcId  = COORDSYS_GET_COARSE_SUN_SENSOR_FRAME_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        if (sActive_css_frame != NULL)
        {
            responseParams.data.sActive_css_frame = *(sActive_css_frame);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sActive_css_frame,
                          0U,
                          sizeof(responseParams.data.sActive_css_frame));
        }
        responseParams.data.eOp_result = eOp_result;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(coordsysget_coarse_sun_sensor_frameProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes coordsys_get_coarse_sun_sensor_frame_statusResp(
                RespContext_t* ctx,
                const COORDSYS_FrameStatus_t * const sCss_frame_status,
                const COORDSYS_Result_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    coordsysget_coarse_sun_sensor_frame_statusProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(coordsysget_coarse_sun_sensor_frame_statusProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(coordsysget_coarse_sun_sensor_frame_statusProtocolResponseData_t);

    if ((ctx != NULL) && (sCss_frame_status != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_COORDSYS;
        responseParams.hdr.funcId  = COORDSYS_GET_COARSE_SUN_SENSOR_FRAME_STATUS_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        if (sCss_frame_status != NULL)
        {
            responseParams.data.sCss_frame_status = *(sCss_frame_status);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sCss_frame_status,
                          0U,
                          sizeof(responseParams.data.sCss_frame_status));
        }
        responseParams.data.eOp_result = eOp_result;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(coordsysget_coarse_sun_sensor_frame_statusProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes coordsys_set_magnetorquer_frameResp(
                RespContext_t* ctx,
                const COORDSYS_Result_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    coordsysset_magnetorquer_frameProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(coordsysset_magnetorquer_frameProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(coordsysset_magnetorquer_frameProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_COORDSYS;
        responseParams.hdr.funcId  = COORDSYS_SET_MAGNETORQUER_FRAME_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eOp_result = eOp_result;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(coordsysset_magnetorquer_frameProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes coordsys_get_magnetorquer_frameResp(
                RespContext_t* ctx,
                const COORDSYS_MagnetorquerFrame_t * const sActive_mtq_frame,
                const COORDSYS_Result_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    coordsysget_magnetorquer_frameProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(coordsysget_magnetorquer_frameProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(coordsysget_magnetorquer_frameProtocolResponseData_t);

    if ((ctx != NULL) && (sActive_mtq_frame != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_COORDSYS;
        responseParams.hdr.funcId  = COORDSYS_GET_MAGNETORQUER_FRAME_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        if (sActive_mtq_frame != NULL)
        {
            responseParams.data.sActive_mtq_frame = *(sActive_mtq_frame);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sActive_mtq_frame,
                          0U,
                          sizeof(responseParams.data.sActive_mtq_frame));
        }
        responseParams.data.eOp_result = eOp_result;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(coordsysget_magnetorquer_frameProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes coordsys_get_magnetorquer_frame_statusResp(
                RespContext_t* ctx,
                const COORDSYS_FrameStatus_t * const sMtq_frame_status,
                const COORDSYS_Result_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    coordsysget_magnetorquer_frame_statusProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(coordsysget_magnetorquer_frame_statusProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(coordsysget_magnetorquer_frame_statusProtocolResponseData_t);

    if ((ctx != NULL) && (sMtq_frame_status != NULL))
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_COORDSYS;
        responseParams.hdr.funcId  = COORDSYS_GET_MAGNETORQUER_FRAME_STATUS_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        if (sMtq_frame_status != NULL)
        {
            responseParams.data.sMtq_frame_status = *(sMtq_frame_status);
        }
        else
        {
            (void) memset((void *) &responseParams.data.sMtq_frame_status,
                          0U,
                          sizeof(responseParams.data.sMtq_frame_status));
        }
        responseParams.data.eOp_result = eOp_result;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(coordsysget_magnetorquer_frame_statusProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes coordsys_save_coordsys_configResp(
                RespContext_t* ctx,
                const COORDSYS_Result_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    coordsyssave_coordsys_configProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(coordsyssave_coordsys_configProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(coordsyssave_coordsys_configProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_COORDSYS;
        responseParams.hdr.funcId  = COORDSYS_SAVE_COORDSYS_CONFIG_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eOp_result = eOp_result;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(coordsyssave_coordsys_configProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}

ESSATMAC_ErrCodes coordsys_load_coordsys_configResp(
                RespContext_t* ctx,
                const COORDSYS_Result_t eOp_result
)
{
#ifndef BIG_ENDIAN_PLATFORM
    coordsysload_coordsys_configProtocolResponseData_t responseParams;
#else  // #ifndef BIG_ENDIAN_PLATFORM
    uint8_t responseParams[sizeof(coordsysload_coordsys_configProtocolResponseData_t)] = { 0 };
#endif  // #ifndef BIG_ENDIAN_PLATFORM

    ESSATMAC_ErrCodes sendResult = ESSATMAC_EC_NULL;

    STATIC_ASSERT_SIZE_CHECK(coordsysload_coordsys_configProtocolResponseData_t);

    if (ctx != NULL)
    {
#ifndef BIG_ENDIAN_PLATFORM
        // fill message header
        // RS485 wire protocol also uses LE byte order -> serialization of params is not needed
        responseParams.hdr.protoId = ES_SAT_FUNC_PROTOCOL_ID_COORDSYS;
        responseParams.hdr.funcId  = COORDSYS_LOAD_COORDSYS_CONFIG_FUNCRESP_ID;
        responseParams.hdr.seqId   = ctx->seqId;
        responseParams.hdr.errCode = ESSA_FP_ERRCODE_NOERROR;
        SET_RESPONSE(responseParams.hdr);

        // fill message data
        responseParams.data.eOp_result = eOp_result;
#else // #ifndef BIG_ENDIAN_PLATFORM
    // TBD: Serialize request fields
#endif  // #ifndef BIG_ENDIAN_PLATFORM

        sendResult = ESSA_Stack_SendFrameEx((ESSASNetInterface) ctx->nInterfaceNumber,
                                            ctx->netType,
                                            ctx->nAddr,
                                            ES_SAT_MAC_PROTOCOL_ID_FP_LAYER,
#ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) &responseParams,
#else // #ifndef BIG_ENDIAN_PLATFORM
                                            (uint8_t *) responseParams,
#endif // #ifndef BIG_ENDIAN_PLATFORM
                                            sizeof(coordsysload_coordsys_configProtocolResponseData_t),
                                            STACK_SENDFRAME_DEFAULT_PRIO,
                                            (ESSATMAC_DrvResult_Cbk_t) NULL,
                                            (uint32_t *) NULL);
    }

    return sendResult;
}


