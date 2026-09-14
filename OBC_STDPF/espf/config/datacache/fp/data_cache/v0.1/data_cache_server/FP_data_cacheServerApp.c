/*!
********************************************************************************************
* @file FP_data_cacheServerApp.c
* @brief ServerApp implementation template generator
********************************************************************************************
* @version           interface data_cache v0.1
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

#include "FP_data_cacheProtocolServer.h"

// @START_USER@ USER_INCLUDES
// Place user includes here to preserve them during merge!!!
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL
static void data_cache_get_OBC_0_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_OBC_0_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_OBC_0_DataRequestData_t* pRequestData);

static void data_cache_get_ADCS_0_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_ADCS_0_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_ADCS_0_DataRequestData_t* pRequestData);

static void data_cache_get_ADCS_1_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_ADCS_1_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_ADCS_1_DataRequestData_t* pRequestData);

static void data_cache_get_ADCS_2_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_ADCS_2_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_ADCS_2_DataRequestData_t* pRequestData);

static void data_cache_get_EPS_0_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS_0_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS_0_DataRequestData_t* pRequestData);

static void data_cache_get_SSP_0_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_SSP_0_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_SSP_0_DataRequestData_t* pRequestData);

static void data_cache_get_SSP_1_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_SSP_1_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_SSP_1_DataRequestData_t* pRequestData);

static void data_cache_get_SSP_2_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_SSP_2_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_SSP_2_DataRequestData_t* pRequestData);

static void data_cache_get_SSP_3_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_SSP_3_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_SSP_3_DataRequestData_t* pRequestData);

static void data_cache_get_AOCS_CNTRL_TLM_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_AOCS_CNTRL_TLM_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_AOCS_CNTRL_TLM_DataRequestData_t* pRequestData);

static void data_cache_get_AOCS_CNTRL_SYS_STATE_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_AOCS_CNTRL_SYS_STATE_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_AOCS_CNTRL_SYS_STATE_DataRequestData_t* pRequestData);

static void data_cache_get_AOCS_CNTRL_REF_PARAMS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_AOCS_CNTRL_REF_PARAMS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_AOCS_CNTRL_REF_PARAMS_DataRequestData_t* pRequestData);

static void data_cache_get_SENSOR_GYRO_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_SENSOR_GYRO_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_SENSOR_GYRO_SENSOR_FRAME_DataRequestData_t* pRequestData);

static void data_cache_get_SENSOR_GYRO_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_SENSOR_GYRO_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_SENSOR_GYRO_BODY_FRAME_DataRequestData_t* pRequestData);

static void data_cache_get_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataRequestData_t* pRequestData);

static void data_cache_get_SENSOR_MAG_PRIMARY_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_SENSOR_MAG_PRIMARY_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_SENSOR_MAG_PRIMARY_BODY_FRAME_DataRequestData_t* pRequestData);

static void data_cache_get_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataRequestData_t* pRequestData);

static void data_cache_get_SENSOR_MAG_SECONDARY_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_SENSOR_MAG_SECONDARY_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_SENSOR_MAG_SECONDARY_BODY_FRAME_DataRequestData_t* pRequestData);

static void data_cache_get_SENSOR_COARSE_SUN_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_SENSOR_COARSE_SUN_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_SENSOR_COARSE_SUN_SENSOR_FRAME_DataRequestData_t* pRequestData);

static void data_cache_get_SENSOR_COARSE_SUN_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_SENSOR_COARSE_SUN_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_SENSOR_COARSE_SUN_BODY_FRAME_DataRequestData_t* pRequestData);

static void data_cache_get_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataRequestData_t* pRequestData);

static void data_cache_get_SENSOR_PANEL_TEMP_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_SENSOR_PANEL_TEMP_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_SENSOR_PANEL_TEMP_BODY_FRAME_DataRequestData_t* pRequestData);

static void data_cache_get_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataRequestData_t* pRequestData);

static void data_cache_get_SENSOR_GYRO_TEMP_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_SENSOR_GYRO_TEMP_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_SENSOR_GYRO_TEMP_BODY_FRAME_DataRequestData_t* pRequestData);

static void data_cache_get_ACTUATOR_MTQ_VALUES_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_ACTUATOR_MTQ_VALUES_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_ACTUATOR_MTQ_VALUES_DataRequestData_t* pRequestData);

static void data_cache_get_ACTUATOR_TORQUE_VALUES_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_ACTUATOR_TORQUE_VALUES_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_ACTUATOR_TORQUE_VALUES_DataRequestData_t* pRequestData);

static void data_cache_get_ADCS_3_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_ADCS_3_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_ADCS_3_DataRequestData_t* pRequestData);

static void data_cache_get_ADCS_4_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_ADCS_4_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_ADCS_4_DataRequestData_t* pRequestData);

static void data_cache_get_EPS_9_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS_9_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS_9_DataRequestData_t* pRequestData);

static void data_cache_get_EPS_10_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS_10_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS_10_DataRequestData_t* pRequestData);

static void data_cache_get_EPS_14_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS_14_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS_14_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_OP_STATUS_COMMON_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_OP_STATUS_COMMON_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_OP_STATUS_COMMON_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_OP_STATUS_APP_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_OP_STATUS_APP_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_OP_STATUS_APP_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_166_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_166_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_166_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_167_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_167_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_167_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_168_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_168_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_168_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_169_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_169_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_169_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_170_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_170_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_170_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_171_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_171_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_171_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_172_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_172_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_172_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_173_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_173_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_173_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_174_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_174_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_174_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_175_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_175_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_175_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_176_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_176_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_176_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_177_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_177_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_177_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_178_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_178_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_178_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_179_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_179_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_179_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_180_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_180_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_180_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_203_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_203_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_203_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_204_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_204_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_204_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_205_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_205_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_205_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_206_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_206_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_206_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_207_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_207_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_207_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_208_1_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_208_1_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_208_1_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_208_2_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_208_2_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_208_2_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_209_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_209_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_209_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_210_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_210_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_210_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_211_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_211_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_211_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_212_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_212_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_212_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_213_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_213_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_213_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_214_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_214_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_214_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_216_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_216_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_216_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_217_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_217_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_217_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_218_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_218_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_218_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_225_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_225_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_225_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_226_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_226_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_226_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_165_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_165_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_165_DataRequestData_t* pRequestData);

static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_221_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_221_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_221_DataRequestData_t* pRequestData);

static void data_cache_get_GNSS_TIME_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_GNSS_TIME_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_GNSS_TIME_DataRequestData_t* pRequestData);

static void data_cache_get_GNSS_BESTXYZ_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_GNSS_BESTXYZ_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_GNSS_BESTXYZ_DataRequestData_t* pRequestData);

static void data_cache_get_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataRequestData_t* pRequestData);

static void data_cache_get_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataRequestData_t* pRequestData);

static void data_cache_get_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataRequestData_t* pRequestData);

static void data_cache_get_FDIR_EPS_I_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_FDIR_EPS_I_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_FDIR_EPS_I_CMD_EXEC_STATUS_DataRequestData_t* pRequestData);

static void data_cache_get_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataRequestData_t* pRequestData);

static void data_cache_get_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataRequestData_t* pRequestData);

static void data_cache_get_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataRequestData_t* pRequestData);

static void data_cache_get_FDIR_CUBEADCS_GEN2_EVENTS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_FDIR_CUBEADCS_GEN2_EVENTS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_FDIR_CUBEADCS_GEN2_EVENTS_DataRequestData_t* pRequestData);

static void data_cache_get_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataRequestData_t* pRequestData);

static void data_cache_get_FDIR_UHF_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_FDIR_UHF_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_FDIR_UHF_CMD_EXEC_STATUS_DataRequestData_t* pRequestData);

static void data_cache_get_FDIR_GNSS_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_FDIR_GNSS_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_FDIR_GNSS_CMD_EXEC_STATUS_DataRequestData_t* pRequestData);

static void data_cache_get_FDIR_SDR_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_FDIR_SDR_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_FDIR_SDR_CMD_EXEC_STATUS_DataRequestData_t* pRequestData);

static void data_cache_get_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataRequestData_t* pRequestData);

static void data_cache_get_FDIR_THRUSTER_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_FDIR_THRUSTER_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_FDIR_THRUSTER_CMD_EXEC_STATUS_DataRequestData_t* pRequestData);

static void data_cache_get_XBand_Fe_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_XBand_Fe_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_XBand_Fe_DataRequestData_t* pRequestData);

static void data_cache_get_EpsOverallBatteryInfo_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EpsOverallBatteryInfo_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EpsOverallBatteryInfo_DataRequestData_t* pRequestData);

static void data_cache_get_PPS_Telemetry_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_PPS_Telemetry_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_PPS_Telemetry_DataRequestData_t* pRequestData);

static void data_cache_get_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST0_BP_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST0_BP_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST0_BP_INFO_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST0_INA_SENSOR1_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST0_INA_SENSOR1_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST0_INA_SENSOR1_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST0_INA_SENSOR2_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST0_INA_SENSOR2_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST0_INA_SENSOR2_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST0_BALANCER_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST0_BALANCER_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST0_BALANCER_INFO_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST0_BALANCER_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST0_BALANCER_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST0_BALANCER_STATUS_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST0_CHARGER_XP_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST0_CHARGER_XP_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST0_CHARGER_XP_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST0_CHARGER_XR_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST0_CHARGER_XR_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST0_CHARGER_XR_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST0_CHARGER_YP_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST0_CHARGER_YP_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST0_CHARGER_YP_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST0_CHARGER_YR_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST0_CHARGER_YR_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST0_CHARGER_YR_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST0_CHARGER_ZP_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST0_CHARGER_ZP_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST0_CHARGER_ZP_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST0_CHARGER_ZR_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST0_CHARGER_ZR_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST0_CHARGER_ZR_DataRequestData_t* pRequestData);

static void data_cache_get_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST1_BP_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST1_BP_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST1_BP_INFO_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST1_INA_SENSOR1_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST1_INA_SENSOR1_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST1_INA_SENSOR1_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST1_INA_SENSOR2_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST1_INA_SENSOR2_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST1_INA_SENSOR2_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST1_BALANCER_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST1_BALANCER_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST1_BALANCER_INFO_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST1_BALANCER_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST1_BALANCER_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST1_BALANCER_STATUS_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST1_CHARGER_XP_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST1_CHARGER_XP_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST1_CHARGER_XP_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST1_CHARGER_XR_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST1_CHARGER_XR_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST1_CHARGER_XR_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST1_CHARGER_YP_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST1_CHARGER_YP_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST1_CHARGER_YP_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST1_CHARGER_YR_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST1_CHARGER_YR_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST1_CHARGER_YR_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST1_CHARGER_ZP_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST1_CHARGER_ZP_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST1_CHARGER_ZP_DataRequestData_t* pRequestData);

static void data_cache_get_EPS2_BP_INST1_CHARGER_ZR_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS2_BP_INST1_CHARGER_ZR_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS2_BP_INST1_CHARGER_ZR_DataRequestData_t* pRequestData);

static void data_cache_get_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataRequestData_t* pRequestData);

static void data_cache_get_EPS3_BP_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_BP_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_BP_INST0_uptime_in_secondsRequestData_t* pRequestData);

static void data_cache_get_EPS3_BP_INST0commonRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_BP_INST0commonRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_BP_INST0commonRequestData_t* pRequestData);

static void data_cache_get_EPS3_BP_INST0hib_mode_statusRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_BP_INST0hib_mode_statusRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_BP_INST0hib_mode_statusRequestData_t* pRequestData);

static void data_cache_get_EPS3_BP_INST0measurementsRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_BP_INST0measurementsRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_BP_INST0measurementsRequestData_t* pRequestData);

static void data_cache_get_EPS3_BP_INST0discharging_stateRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_BP_INST0discharging_stateRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_BP_INST0discharging_stateRequestData_t* pRequestData);

static void data_cache_get_EPS3_BP_INST0charge_statusRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_BP_INST0charge_statusRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_BP_INST0charge_statusRequestData_t* pRequestData);

static void data_cache_get_EPS3_BP_INST0balancers_statusRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_BP_INST0balancers_statusRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_BP_INST0balancers_statusRequestData_t* pRequestData);

static void data_cache_get_EPS3_BP_INST0battery_cells_statusRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_BP_INST0battery_cells_statusRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_BP_INST0battery_cells_statusRequestData_t* pRequestData);

static void data_cache_get_EPS3_BP_INST0heaters_statusRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_BP_INST0heaters_statusRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_BP_INST0heaters_statusRequestData_t* pRequestData);

static void data_cache_get_EPS3_BP_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_BP_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_BP_INST0_CMD_EXEC_STATUS_DataRequestData_t* pRequestData);

static void data_cache_get_dumb_dataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_dumb_dataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_dumb_dataRequestData_t* pRequestData);

static void data_cache_get_dumb_data1RequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_dumb_data1RequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_dumb_data1RequestData_t* pRequestData);

static void data_cache_get_dumb_data3RequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_dumb_data3RequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_dumb_data3RequestData_t* pRequestData);

static void data_cache_get_dumb_data4RequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_dumb_data4RequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_dumb_data4RequestData_t* pRequestData);

static void data_cache_get_dumb_data5RequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_dumb_data5RequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_dumb_data5RequestData_t* pRequestData);

static void data_cache_get_dumb_data6RequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_dumb_data6RequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_dumb_data6RequestData_t* pRequestData);

static void data_cache_get_EPS3_PDM_A_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_PDM_A_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_PDM_A_INST0_uptime_in_secondsRequestData_t* pRequestData);

static void data_cache_get_EPS3_PDM_A_INST0_commonRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_PDM_A_INST0_commonRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_PDM_A_INST0_commonRequestData_t* pRequestData);

static void data_cache_get_EPS3_PDM_A_INST0_hib_modeRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_PDM_A_INST0_hib_modeRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_PDM_A_INST0_hib_modeRequestData_t* pRequestData);

static void data_cache_get_EPS3_PDM_A_INST0_general_outputsRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_PDM_A_INST0_general_outputsRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_PDM_A_INST0_general_outputsRequestData_t* pRequestData);

static void data_cache_get_EPS3_PDM_A_INST0_general_faultsRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_PDM_A_INST0_general_faultsRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_PDM_A_INST0_general_faultsRequestData_t* pRequestData);

static void data_cache_get_EPS3_PDM_A_INST0_all_measurementsRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_PDM_A_INST0_all_measurementsRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_PDM_A_INST0_all_measurementsRequestData_t* pRequestData);

static void data_cache_get_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataRequestData_t* pRequestData);

static void data_cache_get_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataRequestData_t* pRequestData);

static void data_cache_get_EPS3_PDM_B_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_PDM_B_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_PDM_B_INST0_uptime_in_secondsRequestData_t* pRequestData);

static void data_cache_get_EPS3_PDM_B_INST0_commonRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_PDM_B_INST0_commonRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_PDM_B_INST0_commonRequestData_t* pRequestData);

static void data_cache_get_EPS3_PDM_B_INST0_hib_modeRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_PDM_B_INST0_hib_modeRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_PDM_B_INST0_hib_modeRequestData_t* pRequestData);

static void data_cache_get_EPS3_PDM_B_INST0_general_outputsRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_PDM_B_INST0_general_outputsRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_PDM_B_INST0_general_outputsRequestData_t* pRequestData);

static void data_cache_get_EPS3_PDM_B_INST0_channel_flag_stateRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_PDM_B_INST0_channel_flag_stateRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_PDM_B_INST0_channel_flag_stateRequestData_t* pRequestData);

static void data_cache_get_EPS3_PDM_B_INST0_temperatureRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_PDM_B_INST0_temperatureRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_PDM_B_INST0_temperatureRequestData_t* pRequestData);

static void data_cache_get_EPS3_PDM_B_INST0_all_measurementsRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_PDM_B_INST0_all_measurementsRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_PDM_B_INST0_all_measurementsRequestData_t* pRequestData);

static void data_cache_get_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataRequestData_t* pRequestData);

static void data_cache_get_EPS3_EXPANDER_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_EXPANDER_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_EXPANDER_INST0_uptime_in_secondsRequestData_t* pRequestData);

static void data_cache_get_EPS3_EXPANDER_INST0_commonRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_EXPANDER_INST0_commonRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_EXPANDER_INST0_commonRequestData_t* pRequestData);

static void data_cache_get_EPS3_EXPANDER_INST0_outputsRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_EXPANDER_INST0_outputsRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_EXPANDER_INST0_outputsRequestData_t* pRequestData);

static void data_cache_get_EPS3_EXPANDER_INST0_general_inputsRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_EXPANDER_INST0_general_inputsRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_EXPANDER_INST0_general_inputsRequestData_t* pRequestData);

static void data_cache_get_EPS3_EXPANDER_INST0_feedbacksRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_EXPANDER_INST0_feedbacksRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_EXPANDER_INST0_feedbacksRequestData_t* pRequestData);

static void data_cache_get_EPS3_EXPANDER_INST0_volt_amp_measurementsRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_EXPANDER_INST0_volt_amp_measurementsRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_EXPANDER_INST0_volt_amp_measurementsRequestData_t* pRequestData);

static void data_cache_get_EPS3_INPUT_STAGE_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_INPUT_STAGE_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0_uptime_in_secondsRequestData_t* pRequestData);

static void data_cache_get_EPS3_INPUT_STAGE_INST0commonRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_INPUT_STAGE_INST0commonRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0commonRequestData_t* pRequestData);

static void data_cache_get_EPS3_INPUT_STAGE_INST0hib_mode_statusRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_INPUT_STAGE_INST0hib_mode_statusRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0hib_mode_statusRequestData_t* pRequestData);

static void data_cache_get_EPS3_INPUT_STAGE_INST0selflock_onRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_INPUT_STAGE_INST0selflock_onRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0selflock_onRequestData_t* pRequestData);

static void data_cache_get_EPS3_INPUT_STAGE_INST0sp1RequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_INPUT_STAGE_INST0sp1RequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0sp1RequestData_t* pRequestData);

static void data_cache_get_EPS3_INPUT_STAGE_INST0sp2RequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_INPUT_STAGE_INST0sp2RequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0sp2RequestData_t* pRequestData);

static void data_cache_get_EPS3_INPUT_STAGE_INST0sp3RequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_INPUT_STAGE_INST0sp3RequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0sp3RequestData_t* pRequestData);

static void data_cache_get_EPS3_INPUT_STAGE_INST0system_busRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_INPUT_STAGE_INST0system_busRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0system_busRequestData_t* pRequestData);

static void data_cache_get_EPS3_INPUT_STAGE_INST0bus_7v5RequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_INPUT_STAGE_INST0bus_7v5RequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0bus_7v5RequestData_t* pRequestData);

static void data_cache_get_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodRequestData_t* pRequestData);

static void data_cache_get_EPS3_INPUT_STAGE_INST0undervoltage_7V5RequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_INPUT_STAGE_INST0undervoltage_7V5RequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0undervoltage_7V5RequestData_t* pRequestData);

static void data_cache_get_EPS3_INPUT_STAGE_INST0bus_3v3RequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_INPUT_STAGE_INST0bus_3v3RequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0bus_3v3RequestData_t* pRequestData);

static void data_cache_get_EPS3_INPUT_STAGE_INST0undervoltage_3V3RequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_INPUT_STAGE_INST0undervoltage_3V3RequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0undervoltage_3V3RequestData_t* pRequestData);

static void data_cache_get_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx);

static void data_cache_set_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataRequestData_t* pRequestData);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)
// @END_USER@ USER_LOCAL_VARS_DECL

static data_cache_ServerApi_t data_cacheServerApiCtx =
{
  .data_cache_get_OBC_0_DataRequestHandler = data_cache_get_OBC_0_DataRequestHandlerImpl,
  .data_cache_set_OBC_0_DataRequestHandler = data_cache_set_OBC_0_DataRequestHandlerImpl,
  .data_cache_get_ADCS_0_DataRequestHandler = data_cache_get_ADCS_0_DataRequestHandlerImpl,
  .data_cache_set_ADCS_0_DataRequestHandler = data_cache_set_ADCS_0_DataRequestHandlerImpl,
  .data_cache_get_ADCS_1_DataRequestHandler = data_cache_get_ADCS_1_DataRequestHandlerImpl,
  .data_cache_set_ADCS_1_DataRequestHandler = data_cache_set_ADCS_1_DataRequestHandlerImpl,
  .data_cache_get_ADCS_2_DataRequestHandler = data_cache_get_ADCS_2_DataRequestHandlerImpl,
  .data_cache_set_ADCS_2_DataRequestHandler = data_cache_set_ADCS_2_DataRequestHandlerImpl,
  .data_cache_get_EPS_0_DataRequestHandler = data_cache_get_EPS_0_DataRequestHandlerImpl,
  .data_cache_set_EPS_0_DataRequestHandler = data_cache_set_EPS_0_DataRequestHandlerImpl,
  .data_cache_get_SSP_0_DataRequestHandler = data_cache_get_SSP_0_DataRequestHandlerImpl,
  .data_cache_set_SSP_0_DataRequestHandler = data_cache_set_SSP_0_DataRequestHandlerImpl,
  .data_cache_get_SSP_1_DataRequestHandler = data_cache_get_SSP_1_DataRequestHandlerImpl,
  .data_cache_set_SSP_1_DataRequestHandler = data_cache_set_SSP_1_DataRequestHandlerImpl,
  .data_cache_get_SSP_2_DataRequestHandler = data_cache_get_SSP_2_DataRequestHandlerImpl,
  .data_cache_set_SSP_2_DataRequestHandler = data_cache_set_SSP_2_DataRequestHandlerImpl,
  .data_cache_get_SSP_3_DataRequestHandler = data_cache_get_SSP_3_DataRequestHandlerImpl,
  .data_cache_set_SSP_3_DataRequestHandler = data_cache_set_SSP_3_DataRequestHandlerImpl,
  .data_cache_get_AOCS_CNTRL_TLM_DataRequestHandler = data_cache_get_AOCS_CNTRL_TLM_DataRequestHandlerImpl,
  .data_cache_set_AOCS_CNTRL_TLM_DataRequestHandler = data_cache_set_AOCS_CNTRL_TLM_DataRequestHandlerImpl,
  .data_cache_get_AOCS_CNTRL_SYS_STATE_DataRequestHandler = data_cache_get_AOCS_CNTRL_SYS_STATE_DataRequestHandlerImpl,
  .data_cache_set_AOCS_CNTRL_SYS_STATE_DataRequestHandler = data_cache_set_AOCS_CNTRL_SYS_STATE_DataRequestHandlerImpl,
  .data_cache_get_AOCS_CNTRL_REF_PARAMS_DataRequestHandler = data_cache_get_AOCS_CNTRL_REF_PARAMS_DataRequestHandlerImpl,
  .data_cache_set_AOCS_CNTRL_REF_PARAMS_DataRequestHandler = data_cache_set_AOCS_CNTRL_REF_PARAMS_DataRequestHandlerImpl,
  .data_cache_get_SENSOR_GYRO_SENSOR_FRAME_DataRequestHandler = data_cache_get_SENSOR_GYRO_SENSOR_FRAME_DataRequestHandlerImpl,
  .data_cache_set_SENSOR_GYRO_SENSOR_FRAME_DataRequestHandler = data_cache_set_SENSOR_GYRO_SENSOR_FRAME_DataRequestHandlerImpl,
  .data_cache_get_SENSOR_GYRO_BODY_FRAME_DataRequestHandler = data_cache_get_SENSOR_GYRO_BODY_FRAME_DataRequestHandlerImpl,
  .data_cache_set_SENSOR_GYRO_BODY_FRAME_DataRequestHandler = data_cache_set_SENSOR_GYRO_BODY_FRAME_DataRequestHandlerImpl,
  .data_cache_get_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataRequestHandler = data_cache_get_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataRequestHandlerImpl,
  .data_cache_set_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataRequestHandler = data_cache_set_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataRequestHandlerImpl,
  .data_cache_get_SENSOR_MAG_PRIMARY_BODY_FRAME_DataRequestHandler = data_cache_get_SENSOR_MAG_PRIMARY_BODY_FRAME_DataRequestHandlerImpl,
  .data_cache_set_SENSOR_MAG_PRIMARY_BODY_FRAME_DataRequestHandler = data_cache_set_SENSOR_MAG_PRIMARY_BODY_FRAME_DataRequestHandlerImpl,
  .data_cache_get_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataRequestHandler = data_cache_get_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataRequestHandlerImpl,
  .data_cache_set_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataRequestHandler = data_cache_set_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataRequestHandlerImpl,
  .data_cache_get_SENSOR_MAG_SECONDARY_BODY_FRAME_DataRequestHandler = data_cache_get_SENSOR_MAG_SECONDARY_BODY_FRAME_DataRequestHandlerImpl,
  .data_cache_set_SENSOR_MAG_SECONDARY_BODY_FRAME_DataRequestHandler = data_cache_set_SENSOR_MAG_SECONDARY_BODY_FRAME_DataRequestHandlerImpl,
  .data_cache_get_SENSOR_COARSE_SUN_SENSOR_FRAME_DataRequestHandler = data_cache_get_SENSOR_COARSE_SUN_SENSOR_FRAME_DataRequestHandlerImpl,
  .data_cache_set_SENSOR_COARSE_SUN_SENSOR_FRAME_DataRequestHandler = data_cache_set_SENSOR_COARSE_SUN_SENSOR_FRAME_DataRequestHandlerImpl,
  .data_cache_get_SENSOR_COARSE_SUN_BODY_FRAME_DataRequestHandler = data_cache_get_SENSOR_COARSE_SUN_BODY_FRAME_DataRequestHandlerImpl,
  .data_cache_set_SENSOR_COARSE_SUN_BODY_FRAME_DataRequestHandler = data_cache_set_SENSOR_COARSE_SUN_BODY_FRAME_DataRequestHandlerImpl,
  .data_cache_get_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataRequestHandler = data_cache_get_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataRequestHandlerImpl,
  .data_cache_set_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataRequestHandler = data_cache_set_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataRequestHandlerImpl,
  .data_cache_get_SENSOR_PANEL_TEMP_BODY_FRAME_DataRequestHandler = data_cache_get_SENSOR_PANEL_TEMP_BODY_FRAME_DataRequestHandlerImpl,
  .data_cache_set_SENSOR_PANEL_TEMP_BODY_FRAME_DataRequestHandler = data_cache_set_SENSOR_PANEL_TEMP_BODY_FRAME_DataRequestHandlerImpl,
  .data_cache_get_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataRequestHandler = data_cache_get_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataRequestHandlerImpl,
  .data_cache_set_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataRequestHandler = data_cache_set_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataRequestHandlerImpl,
  .data_cache_get_SENSOR_GYRO_TEMP_BODY_FRAME_DataRequestHandler = data_cache_get_SENSOR_GYRO_TEMP_BODY_FRAME_DataRequestHandlerImpl,
  .data_cache_set_SENSOR_GYRO_TEMP_BODY_FRAME_DataRequestHandler = data_cache_set_SENSOR_GYRO_TEMP_BODY_FRAME_DataRequestHandlerImpl,
  .data_cache_get_ACTUATOR_MTQ_VALUES_DataRequestHandler = data_cache_get_ACTUATOR_MTQ_VALUES_DataRequestHandlerImpl,
  .data_cache_set_ACTUATOR_MTQ_VALUES_DataRequestHandler = data_cache_set_ACTUATOR_MTQ_VALUES_DataRequestHandlerImpl,
  .data_cache_get_ACTUATOR_TORQUE_VALUES_DataRequestHandler = data_cache_get_ACTUATOR_TORQUE_VALUES_DataRequestHandlerImpl,
  .data_cache_set_ACTUATOR_TORQUE_VALUES_DataRequestHandler = data_cache_set_ACTUATOR_TORQUE_VALUES_DataRequestHandlerImpl,
  .data_cache_get_ADCS_3_DataRequestHandler = data_cache_get_ADCS_3_DataRequestHandlerImpl,
  .data_cache_set_ADCS_3_DataRequestHandler = data_cache_set_ADCS_3_DataRequestHandlerImpl,
  .data_cache_get_ADCS_4_DataRequestHandler = data_cache_get_ADCS_4_DataRequestHandlerImpl,
  .data_cache_set_ADCS_4_DataRequestHandler = data_cache_set_ADCS_4_DataRequestHandlerImpl,
  .data_cache_get_EPS_9_DataRequestHandler = data_cache_get_EPS_9_DataRequestHandlerImpl,
  .data_cache_set_EPS_9_DataRequestHandler = data_cache_set_EPS_9_DataRequestHandlerImpl,
  .data_cache_get_EPS_10_DataRequestHandler = data_cache_get_EPS_10_DataRequestHandlerImpl,
  .data_cache_set_EPS_10_DataRequestHandler = data_cache_set_EPS_10_DataRequestHandlerImpl,
  .data_cache_get_EPS_14_DataRequestHandler = data_cache_get_EPS_14_DataRequestHandlerImpl,
  .data_cache_set_EPS_14_DataRequestHandler = data_cache_set_EPS_14_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_OP_STATUS_COMMON_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_OP_STATUS_COMMON_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_OP_STATUS_COMMON_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_OP_STATUS_COMMON_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_OP_STATUS_APP_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_OP_STATUS_APP_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_OP_STATUS_APP_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_OP_STATUS_APP_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_166_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_166_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_166_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_166_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_167_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_167_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_167_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_167_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_168_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_168_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_168_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_168_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_169_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_169_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_169_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_169_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_170_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_170_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_170_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_170_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_171_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_171_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_171_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_171_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_172_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_172_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_172_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_172_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_173_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_173_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_173_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_173_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_174_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_174_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_174_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_174_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_175_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_175_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_175_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_175_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_176_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_176_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_176_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_176_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_177_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_177_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_177_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_177_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_178_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_178_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_178_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_178_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_179_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_179_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_179_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_179_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_180_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_180_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_180_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_180_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_203_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_203_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_203_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_203_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_204_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_204_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_204_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_204_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_205_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_205_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_205_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_205_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_206_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_206_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_206_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_206_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_207_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_207_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_207_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_207_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_208_1_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_208_1_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_208_1_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_208_1_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_208_2_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_208_2_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_208_2_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_208_2_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_209_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_209_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_209_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_209_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_210_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_210_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_210_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_210_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_211_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_211_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_211_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_211_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_212_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_212_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_212_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_212_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_213_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_213_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_213_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_213_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_214_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_214_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_214_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_214_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_216_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_216_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_216_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_216_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_217_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_217_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_217_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_217_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_218_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_218_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_218_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_218_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_225_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_225_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_225_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_225_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_226_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_226_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_226_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_226_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_165_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_165_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_165_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_165_DataRequestHandlerImpl,
  .data_cache_get_CUBEADCS_GEN2_TLM_FRAME_221_DataRequestHandler = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_221_DataRequestHandlerImpl,
  .data_cache_set_CUBEADCS_GEN2_TLM_FRAME_221_DataRequestHandler = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_221_DataRequestHandlerImpl,
  .data_cache_get_GNSS_TIME_DataRequestHandler = data_cache_get_GNSS_TIME_DataRequestHandlerImpl,
  .data_cache_set_GNSS_TIME_DataRequestHandler = data_cache_set_GNSS_TIME_DataRequestHandlerImpl,
  .data_cache_get_GNSS_BESTXYZ_DataRequestHandler = data_cache_get_GNSS_BESTXYZ_DataRequestHandlerImpl,
  .data_cache_set_GNSS_BESTXYZ_DataRequestHandler = data_cache_set_GNSS_BESTXYZ_DataRequestHandlerImpl,
  .data_cache_get_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataRequestHandler = data_cache_get_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataRequestHandlerImpl,
  .data_cache_set_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataRequestHandler = data_cache_set_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataRequestHandlerImpl,
  .data_cache_get_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataRequestHandler = data_cache_get_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataRequestHandlerImpl,
  .data_cache_set_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataRequestHandler = data_cache_set_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataRequestHandlerImpl,
  .data_cache_get_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataRequestHandler = data_cache_get_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataRequestHandlerImpl,
  .data_cache_set_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataRequestHandler = data_cache_set_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataRequestHandlerImpl,
  .data_cache_get_FDIR_EPS_I_CMD_EXEC_STATUS_DataRequestHandler = data_cache_get_FDIR_EPS_I_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_set_FDIR_EPS_I_CMD_EXEC_STATUS_DataRequestHandler = data_cache_set_FDIR_EPS_I_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_get_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataRequestHandler = data_cache_get_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_set_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataRequestHandler = data_cache_set_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_get_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataRequestHandler = data_cache_get_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_set_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataRequestHandler = data_cache_set_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_get_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataRequestHandler = data_cache_get_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_set_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataRequestHandler = data_cache_set_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_get_FDIR_CUBEADCS_GEN2_EVENTS_DataRequestHandler = data_cache_get_FDIR_CUBEADCS_GEN2_EVENTS_DataRequestHandlerImpl,
  .data_cache_set_FDIR_CUBEADCS_GEN2_EVENTS_DataRequestHandler = data_cache_set_FDIR_CUBEADCS_GEN2_EVENTS_DataRequestHandlerImpl,
  .data_cache_get_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataRequestHandler = data_cache_get_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_set_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataRequestHandler = data_cache_set_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_get_FDIR_UHF_CMD_EXEC_STATUS_DataRequestHandler = data_cache_get_FDIR_UHF_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_set_FDIR_UHF_CMD_EXEC_STATUS_DataRequestHandler = data_cache_set_FDIR_UHF_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_get_FDIR_GNSS_CMD_EXEC_STATUS_DataRequestHandler = data_cache_get_FDIR_GNSS_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_set_FDIR_GNSS_CMD_EXEC_STATUS_DataRequestHandler = data_cache_set_FDIR_GNSS_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_get_FDIR_SDR_CMD_EXEC_STATUS_DataRequestHandler = data_cache_get_FDIR_SDR_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_set_FDIR_SDR_CMD_EXEC_STATUS_DataRequestHandler = data_cache_set_FDIR_SDR_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_get_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataRequestHandler = data_cache_get_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_set_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataRequestHandler = data_cache_set_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_get_FDIR_THRUSTER_CMD_EXEC_STATUS_DataRequestHandler = data_cache_get_FDIR_THRUSTER_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_set_FDIR_THRUSTER_CMD_EXEC_STATUS_DataRequestHandler = data_cache_set_FDIR_THRUSTER_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_get_XBand_Fe_DataRequestHandler = data_cache_get_XBand_Fe_DataRequestHandlerImpl,
  .data_cache_set_XBand_Fe_DataRequestHandler = data_cache_set_XBand_Fe_DataRequestHandlerImpl,
  .data_cache_get_EpsOverallBatteryInfo_DataRequestHandler = data_cache_get_EpsOverallBatteryInfo_DataRequestHandlerImpl,
  .data_cache_set_EpsOverallBatteryInfo_DataRequestHandler = data_cache_set_EpsOverallBatteryInfo_DataRequestHandlerImpl,
  .data_cache_get_PPS_Telemetry_DataRequestHandler = data_cache_get_PPS_Telemetry_DataRequestHandlerImpl,
  .data_cache_set_PPS_Telemetry_DataRequestHandler = data_cache_set_PPS_Telemetry_DataRequestHandlerImpl,
  .data_cache_get_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataRequestHandler = data_cache_get_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_set_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataRequestHandler = data_cache_set_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST0_BP_INFO_DataRequestHandler = data_cache_get_EPS2_BP_INST0_BP_INFO_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST0_BP_INFO_DataRequestHandler = data_cache_set_EPS2_BP_INST0_BP_INFO_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataRequestHandler = data_cache_get_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataRequestHandler = data_cache_set_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST0_INA_SENSOR1_DataRequestHandler = data_cache_get_EPS2_BP_INST0_INA_SENSOR1_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST0_INA_SENSOR1_DataRequestHandler = data_cache_set_EPS2_BP_INST0_INA_SENSOR1_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST0_INA_SENSOR2_DataRequestHandler = data_cache_get_EPS2_BP_INST0_INA_SENSOR2_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST0_INA_SENSOR2_DataRequestHandler = data_cache_set_EPS2_BP_INST0_INA_SENSOR2_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST0_BALANCER_INFO_DataRequestHandler = data_cache_get_EPS2_BP_INST0_BALANCER_INFO_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST0_BALANCER_INFO_DataRequestHandler = data_cache_set_EPS2_BP_INST0_BALANCER_INFO_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST0_BALANCER_STATUS_DataRequestHandler = data_cache_get_EPS2_BP_INST0_BALANCER_STATUS_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST0_BALANCER_STATUS_DataRequestHandler = data_cache_set_EPS2_BP_INST0_BALANCER_STATUS_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataRequestHandler = data_cache_get_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataRequestHandler = data_cache_set_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST0_CHARGER_XP_DataRequestHandler = data_cache_get_EPS2_BP_INST0_CHARGER_XP_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST0_CHARGER_XP_DataRequestHandler = data_cache_set_EPS2_BP_INST0_CHARGER_XP_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST0_CHARGER_XR_DataRequestHandler = data_cache_get_EPS2_BP_INST0_CHARGER_XR_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST0_CHARGER_XR_DataRequestHandler = data_cache_set_EPS2_BP_INST0_CHARGER_XR_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST0_CHARGER_YP_DataRequestHandler = data_cache_get_EPS2_BP_INST0_CHARGER_YP_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST0_CHARGER_YP_DataRequestHandler = data_cache_set_EPS2_BP_INST0_CHARGER_YP_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST0_CHARGER_YR_DataRequestHandler = data_cache_get_EPS2_BP_INST0_CHARGER_YR_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST0_CHARGER_YR_DataRequestHandler = data_cache_set_EPS2_BP_INST0_CHARGER_YR_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST0_CHARGER_ZP_DataRequestHandler = data_cache_get_EPS2_BP_INST0_CHARGER_ZP_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST0_CHARGER_ZP_DataRequestHandler = data_cache_set_EPS2_BP_INST0_CHARGER_ZP_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST0_CHARGER_ZR_DataRequestHandler = data_cache_get_EPS2_BP_INST0_CHARGER_ZR_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST0_CHARGER_ZR_DataRequestHandler = data_cache_set_EPS2_BP_INST0_CHARGER_ZR_DataRequestHandlerImpl,
  .data_cache_get_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataRequestHandler = data_cache_get_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_set_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataRequestHandler = data_cache_set_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST1_BP_INFO_DataRequestHandler = data_cache_get_EPS2_BP_INST1_BP_INFO_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST1_BP_INFO_DataRequestHandler = data_cache_set_EPS2_BP_INST1_BP_INFO_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataRequestHandler = data_cache_get_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataRequestHandler = data_cache_set_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST1_INA_SENSOR1_DataRequestHandler = data_cache_get_EPS2_BP_INST1_INA_SENSOR1_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST1_INA_SENSOR1_DataRequestHandler = data_cache_set_EPS2_BP_INST1_INA_SENSOR1_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST1_INA_SENSOR2_DataRequestHandler = data_cache_get_EPS2_BP_INST1_INA_SENSOR2_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST1_INA_SENSOR2_DataRequestHandler = data_cache_set_EPS2_BP_INST1_INA_SENSOR2_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST1_BALANCER_INFO_DataRequestHandler = data_cache_get_EPS2_BP_INST1_BALANCER_INFO_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST1_BALANCER_INFO_DataRequestHandler = data_cache_set_EPS2_BP_INST1_BALANCER_INFO_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST1_BALANCER_STATUS_DataRequestHandler = data_cache_get_EPS2_BP_INST1_BALANCER_STATUS_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST1_BALANCER_STATUS_DataRequestHandler = data_cache_set_EPS2_BP_INST1_BALANCER_STATUS_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataRequestHandler = data_cache_get_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataRequestHandler = data_cache_set_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST1_CHARGER_XP_DataRequestHandler = data_cache_get_EPS2_BP_INST1_CHARGER_XP_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST1_CHARGER_XP_DataRequestHandler = data_cache_set_EPS2_BP_INST1_CHARGER_XP_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST1_CHARGER_XR_DataRequestHandler = data_cache_get_EPS2_BP_INST1_CHARGER_XR_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST1_CHARGER_XR_DataRequestHandler = data_cache_set_EPS2_BP_INST1_CHARGER_XR_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST1_CHARGER_YP_DataRequestHandler = data_cache_get_EPS2_BP_INST1_CHARGER_YP_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST1_CHARGER_YP_DataRequestHandler = data_cache_set_EPS2_BP_INST1_CHARGER_YP_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST1_CHARGER_YR_DataRequestHandler = data_cache_get_EPS2_BP_INST1_CHARGER_YR_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST1_CHARGER_YR_DataRequestHandler = data_cache_set_EPS2_BP_INST1_CHARGER_YR_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST1_CHARGER_ZP_DataRequestHandler = data_cache_get_EPS2_BP_INST1_CHARGER_ZP_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST1_CHARGER_ZP_DataRequestHandler = data_cache_set_EPS2_BP_INST1_CHARGER_ZP_DataRequestHandlerImpl,
  .data_cache_get_EPS2_BP_INST1_CHARGER_ZR_DataRequestHandler = data_cache_get_EPS2_BP_INST1_CHARGER_ZR_DataRequestHandlerImpl,
  .data_cache_set_EPS2_BP_INST1_CHARGER_ZR_DataRequestHandler = data_cache_set_EPS2_BP_INST1_CHARGER_ZR_DataRequestHandlerImpl,
  .data_cache_get_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataRequestHandler = data_cache_get_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_set_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataRequestHandler = data_cache_set_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_get_EPS3_BP_INST0_uptime_in_secondsRequestHandler = data_cache_get_EPS3_BP_INST0_uptime_in_secondsRequestHandlerImpl,
  .data_cache_set_EPS3_BP_INST0_uptime_in_secondsRequestHandler = data_cache_set_EPS3_BP_INST0_uptime_in_secondsRequestHandlerImpl,
  .data_cache_get_EPS3_BP_INST0commonRequestHandler = data_cache_get_EPS3_BP_INST0commonRequestHandlerImpl,
  .data_cache_set_EPS3_BP_INST0commonRequestHandler = data_cache_set_EPS3_BP_INST0commonRequestHandlerImpl,
  .data_cache_get_EPS3_BP_INST0hib_mode_statusRequestHandler = data_cache_get_EPS3_BP_INST0hib_mode_statusRequestHandlerImpl,
  .data_cache_set_EPS3_BP_INST0hib_mode_statusRequestHandler = data_cache_set_EPS3_BP_INST0hib_mode_statusRequestHandlerImpl,
  .data_cache_get_EPS3_BP_INST0measurementsRequestHandler = data_cache_get_EPS3_BP_INST0measurementsRequestHandlerImpl,
  .data_cache_set_EPS3_BP_INST0measurementsRequestHandler = data_cache_set_EPS3_BP_INST0measurementsRequestHandlerImpl,
  .data_cache_get_EPS3_BP_INST0discharging_stateRequestHandler = data_cache_get_EPS3_BP_INST0discharging_stateRequestHandlerImpl,
  .data_cache_set_EPS3_BP_INST0discharging_stateRequestHandler = data_cache_set_EPS3_BP_INST0discharging_stateRequestHandlerImpl,
  .data_cache_get_EPS3_BP_INST0charge_statusRequestHandler = data_cache_get_EPS3_BP_INST0charge_statusRequestHandlerImpl,
  .data_cache_set_EPS3_BP_INST0charge_statusRequestHandler = data_cache_set_EPS3_BP_INST0charge_statusRequestHandlerImpl,
  .data_cache_get_EPS3_BP_INST0balancers_statusRequestHandler = data_cache_get_EPS3_BP_INST0balancers_statusRequestHandlerImpl,
  .data_cache_set_EPS3_BP_INST0balancers_statusRequestHandler = data_cache_set_EPS3_BP_INST0balancers_statusRequestHandlerImpl,
  .data_cache_get_EPS3_BP_INST0battery_cells_statusRequestHandler = data_cache_get_EPS3_BP_INST0battery_cells_statusRequestHandlerImpl,
  .data_cache_set_EPS3_BP_INST0battery_cells_statusRequestHandler = data_cache_set_EPS3_BP_INST0battery_cells_statusRequestHandlerImpl,
  .data_cache_get_EPS3_BP_INST0heaters_statusRequestHandler = data_cache_get_EPS3_BP_INST0heaters_statusRequestHandlerImpl,
  .data_cache_set_EPS3_BP_INST0heaters_statusRequestHandler = data_cache_set_EPS3_BP_INST0heaters_statusRequestHandlerImpl,
  .data_cache_get_EPS3_BP_INST0_CMD_EXEC_STATUS_DataRequestHandler = data_cache_get_EPS3_BP_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_set_EPS3_BP_INST0_CMD_EXEC_STATUS_DataRequestHandler = data_cache_set_EPS3_BP_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_get_dumb_dataRequestHandler = data_cache_get_dumb_dataRequestHandlerImpl,
  .data_cache_set_dumb_dataRequestHandler = data_cache_set_dumb_dataRequestHandlerImpl,
  .data_cache_get_dumb_data1RequestHandler = data_cache_get_dumb_data1RequestHandlerImpl,
  .data_cache_set_dumb_data1RequestHandler = data_cache_set_dumb_data1RequestHandlerImpl,
  .data_cache_get_dumb_data3RequestHandler = data_cache_get_dumb_data3RequestHandlerImpl,
  .data_cache_set_dumb_data3RequestHandler = data_cache_set_dumb_data3RequestHandlerImpl,
  .data_cache_get_dumb_data4RequestHandler = data_cache_get_dumb_data4RequestHandlerImpl,
  .data_cache_set_dumb_data4RequestHandler = data_cache_set_dumb_data4RequestHandlerImpl,
  .data_cache_get_dumb_data5RequestHandler = data_cache_get_dumb_data5RequestHandlerImpl,
  .data_cache_set_dumb_data5RequestHandler = data_cache_set_dumb_data5RequestHandlerImpl,
  .data_cache_get_dumb_data6RequestHandler = data_cache_get_dumb_data6RequestHandlerImpl,
  .data_cache_set_dumb_data6RequestHandler = data_cache_set_dumb_data6RequestHandlerImpl,
  .data_cache_get_EPS3_PDM_A_INST0_uptime_in_secondsRequestHandler = data_cache_get_EPS3_PDM_A_INST0_uptime_in_secondsRequestHandlerImpl,
  .data_cache_set_EPS3_PDM_A_INST0_uptime_in_secondsRequestHandler = data_cache_set_EPS3_PDM_A_INST0_uptime_in_secondsRequestHandlerImpl,
  .data_cache_get_EPS3_PDM_A_INST0_commonRequestHandler = data_cache_get_EPS3_PDM_A_INST0_commonRequestHandlerImpl,
  .data_cache_set_EPS3_PDM_A_INST0_commonRequestHandler = data_cache_set_EPS3_PDM_A_INST0_commonRequestHandlerImpl,
  .data_cache_get_EPS3_PDM_A_INST0_hib_modeRequestHandler = data_cache_get_EPS3_PDM_A_INST0_hib_modeRequestHandlerImpl,
  .data_cache_set_EPS3_PDM_A_INST0_hib_modeRequestHandler = data_cache_set_EPS3_PDM_A_INST0_hib_modeRequestHandlerImpl,
  .data_cache_get_EPS3_PDM_A_INST0_general_outputsRequestHandler = data_cache_get_EPS3_PDM_A_INST0_general_outputsRequestHandlerImpl,
  .data_cache_set_EPS3_PDM_A_INST0_general_outputsRequestHandler = data_cache_set_EPS3_PDM_A_INST0_general_outputsRequestHandlerImpl,
  .data_cache_get_EPS3_PDM_A_INST0_general_faultsRequestHandler = data_cache_get_EPS3_PDM_A_INST0_general_faultsRequestHandlerImpl,
  .data_cache_set_EPS3_PDM_A_INST0_general_faultsRequestHandler = data_cache_set_EPS3_PDM_A_INST0_general_faultsRequestHandlerImpl,
  .data_cache_get_EPS3_PDM_A_INST0_all_measurementsRequestHandler = data_cache_get_EPS3_PDM_A_INST0_all_measurementsRequestHandlerImpl,
  .data_cache_set_EPS3_PDM_A_INST0_all_measurementsRequestHandler = data_cache_set_EPS3_PDM_A_INST0_all_measurementsRequestHandlerImpl,
  .data_cache_get_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataRequestHandler = data_cache_get_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_set_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataRequestHandler = data_cache_set_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_get_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataRequestHandler = data_cache_get_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_set_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataRequestHandler = data_cache_set_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_get_EPS3_PDM_B_INST0_uptime_in_secondsRequestHandler = data_cache_get_EPS3_PDM_B_INST0_uptime_in_secondsRequestHandlerImpl,
  .data_cache_set_EPS3_PDM_B_INST0_uptime_in_secondsRequestHandler = data_cache_set_EPS3_PDM_B_INST0_uptime_in_secondsRequestHandlerImpl,
  .data_cache_get_EPS3_PDM_B_INST0_commonRequestHandler = data_cache_get_EPS3_PDM_B_INST0_commonRequestHandlerImpl,
  .data_cache_set_EPS3_PDM_B_INST0_commonRequestHandler = data_cache_set_EPS3_PDM_B_INST0_commonRequestHandlerImpl,
  .data_cache_get_EPS3_PDM_B_INST0_hib_modeRequestHandler = data_cache_get_EPS3_PDM_B_INST0_hib_modeRequestHandlerImpl,
  .data_cache_set_EPS3_PDM_B_INST0_hib_modeRequestHandler = data_cache_set_EPS3_PDM_B_INST0_hib_modeRequestHandlerImpl,
  .data_cache_get_EPS3_PDM_B_INST0_general_outputsRequestHandler = data_cache_get_EPS3_PDM_B_INST0_general_outputsRequestHandlerImpl,
  .data_cache_set_EPS3_PDM_B_INST0_general_outputsRequestHandler = data_cache_set_EPS3_PDM_B_INST0_general_outputsRequestHandlerImpl,
  .data_cache_get_EPS3_PDM_B_INST0_channel_flag_stateRequestHandler = data_cache_get_EPS3_PDM_B_INST0_channel_flag_stateRequestHandlerImpl,
  .data_cache_set_EPS3_PDM_B_INST0_channel_flag_stateRequestHandler = data_cache_set_EPS3_PDM_B_INST0_channel_flag_stateRequestHandlerImpl,
  .data_cache_get_EPS3_PDM_B_INST0_temperatureRequestHandler = data_cache_get_EPS3_PDM_B_INST0_temperatureRequestHandlerImpl,
  .data_cache_set_EPS3_PDM_B_INST0_temperatureRequestHandler = data_cache_set_EPS3_PDM_B_INST0_temperatureRequestHandlerImpl,
  .data_cache_get_EPS3_PDM_B_INST0_all_measurementsRequestHandler = data_cache_get_EPS3_PDM_B_INST0_all_measurementsRequestHandlerImpl,
  .data_cache_set_EPS3_PDM_B_INST0_all_measurementsRequestHandler = data_cache_set_EPS3_PDM_B_INST0_all_measurementsRequestHandlerImpl,
  .data_cache_get_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataRequestHandler = data_cache_get_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_set_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataRequestHandler = data_cache_set_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_get_EPS3_EXPANDER_INST0_uptime_in_secondsRequestHandler = data_cache_get_EPS3_EXPANDER_INST0_uptime_in_secondsRequestHandlerImpl,
  .data_cache_set_EPS3_EXPANDER_INST0_uptime_in_secondsRequestHandler = data_cache_set_EPS3_EXPANDER_INST0_uptime_in_secondsRequestHandlerImpl,
  .data_cache_get_EPS3_EXPANDER_INST0_commonRequestHandler = data_cache_get_EPS3_EXPANDER_INST0_commonRequestHandlerImpl,
  .data_cache_set_EPS3_EXPANDER_INST0_commonRequestHandler = data_cache_set_EPS3_EXPANDER_INST0_commonRequestHandlerImpl,
  .data_cache_get_EPS3_EXPANDER_INST0_outputsRequestHandler = data_cache_get_EPS3_EXPANDER_INST0_outputsRequestHandlerImpl,
  .data_cache_set_EPS3_EXPANDER_INST0_outputsRequestHandler = data_cache_set_EPS3_EXPANDER_INST0_outputsRequestHandlerImpl,
  .data_cache_get_EPS3_EXPANDER_INST0_general_inputsRequestHandler = data_cache_get_EPS3_EXPANDER_INST0_general_inputsRequestHandlerImpl,
  .data_cache_set_EPS3_EXPANDER_INST0_general_inputsRequestHandler = data_cache_set_EPS3_EXPANDER_INST0_general_inputsRequestHandlerImpl,
  .data_cache_get_EPS3_EXPANDER_INST0_feedbacksRequestHandler = data_cache_get_EPS3_EXPANDER_INST0_feedbacksRequestHandlerImpl,
  .data_cache_set_EPS3_EXPANDER_INST0_feedbacksRequestHandler = data_cache_set_EPS3_EXPANDER_INST0_feedbacksRequestHandlerImpl,
  .data_cache_get_EPS3_EXPANDER_INST0_volt_amp_measurementsRequestHandler = data_cache_get_EPS3_EXPANDER_INST0_volt_amp_measurementsRequestHandlerImpl,
  .data_cache_set_EPS3_EXPANDER_INST0_volt_amp_measurementsRequestHandler = data_cache_set_EPS3_EXPANDER_INST0_volt_amp_measurementsRequestHandlerImpl,
  .data_cache_get_EPS3_INPUT_STAGE_INST0_uptime_in_secondsRequestHandler = data_cache_get_EPS3_INPUT_STAGE_INST0_uptime_in_secondsRequestHandlerImpl,
  .data_cache_set_EPS3_INPUT_STAGE_INST0_uptime_in_secondsRequestHandler = data_cache_set_EPS3_INPUT_STAGE_INST0_uptime_in_secondsRequestHandlerImpl,
  .data_cache_get_EPS3_INPUT_STAGE_INST0commonRequestHandler = data_cache_get_EPS3_INPUT_STAGE_INST0commonRequestHandlerImpl,
  .data_cache_set_EPS3_INPUT_STAGE_INST0commonRequestHandler = data_cache_set_EPS3_INPUT_STAGE_INST0commonRequestHandlerImpl,
  .data_cache_get_EPS3_INPUT_STAGE_INST0hib_mode_statusRequestHandler = data_cache_get_EPS3_INPUT_STAGE_INST0hib_mode_statusRequestHandlerImpl,
  .data_cache_set_EPS3_INPUT_STAGE_INST0hib_mode_statusRequestHandler = data_cache_set_EPS3_INPUT_STAGE_INST0hib_mode_statusRequestHandlerImpl,
  .data_cache_get_EPS3_INPUT_STAGE_INST0selflock_onRequestHandler = data_cache_get_EPS3_INPUT_STAGE_INST0selflock_onRequestHandlerImpl,
  .data_cache_set_EPS3_INPUT_STAGE_INST0selflock_onRequestHandler = data_cache_set_EPS3_INPUT_STAGE_INST0selflock_onRequestHandlerImpl,
  .data_cache_get_EPS3_INPUT_STAGE_INST0sp1RequestHandler = data_cache_get_EPS3_INPUT_STAGE_INST0sp1RequestHandlerImpl,
  .data_cache_set_EPS3_INPUT_STAGE_INST0sp1RequestHandler = data_cache_set_EPS3_INPUT_STAGE_INST0sp1RequestHandlerImpl,
  .data_cache_get_EPS3_INPUT_STAGE_INST0sp2RequestHandler = data_cache_get_EPS3_INPUT_STAGE_INST0sp2RequestHandlerImpl,
  .data_cache_set_EPS3_INPUT_STAGE_INST0sp2RequestHandler = data_cache_set_EPS3_INPUT_STAGE_INST0sp2RequestHandlerImpl,
  .data_cache_get_EPS3_INPUT_STAGE_INST0sp3RequestHandler = data_cache_get_EPS3_INPUT_STAGE_INST0sp3RequestHandlerImpl,
  .data_cache_set_EPS3_INPUT_STAGE_INST0sp3RequestHandler = data_cache_set_EPS3_INPUT_STAGE_INST0sp3RequestHandlerImpl,
  .data_cache_get_EPS3_INPUT_STAGE_INST0system_busRequestHandler = data_cache_get_EPS3_INPUT_STAGE_INST0system_busRequestHandlerImpl,
  .data_cache_set_EPS3_INPUT_STAGE_INST0system_busRequestHandler = data_cache_set_EPS3_INPUT_STAGE_INST0system_busRequestHandlerImpl,
  .data_cache_get_EPS3_INPUT_STAGE_INST0bus_7v5RequestHandler = data_cache_get_EPS3_INPUT_STAGE_INST0bus_7v5RequestHandlerImpl,
  .data_cache_set_EPS3_INPUT_STAGE_INST0bus_7v5RequestHandler = data_cache_set_EPS3_INPUT_STAGE_INST0bus_7v5RequestHandlerImpl,
  .data_cache_get_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodRequestHandler = data_cache_get_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodRequestHandlerImpl,
  .data_cache_set_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodRequestHandler = data_cache_set_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodRequestHandlerImpl,
  .data_cache_get_EPS3_INPUT_STAGE_INST0undervoltage_7V5RequestHandler = data_cache_get_EPS3_INPUT_STAGE_INST0undervoltage_7V5RequestHandlerImpl,
  .data_cache_set_EPS3_INPUT_STAGE_INST0undervoltage_7V5RequestHandler = data_cache_set_EPS3_INPUT_STAGE_INST0undervoltage_7V5RequestHandlerImpl,
  .data_cache_get_EPS3_INPUT_STAGE_INST0bus_3v3RequestHandler = data_cache_get_EPS3_INPUT_STAGE_INST0bus_3v3RequestHandlerImpl,
  .data_cache_set_EPS3_INPUT_STAGE_INST0bus_3v3RequestHandler = data_cache_set_EPS3_INPUT_STAGE_INST0bus_3v3RequestHandlerImpl,
  .data_cache_get_EPS3_INPUT_STAGE_INST0undervoltage_3V3RequestHandler = data_cache_get_EPS3_INPUT_STAGE_INST0undervoltage_3V3RequestHandlerImpl,
  .data_cache_set_EPS3_INPUT_STAGE_INST0undervoltage_3V3RequestHandler = data_cache_set_EPS3_INPUT_STAGE_INST0undervoltage_3V3RequestHandlerImpl,
  .data_cache_get_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataRequestHandler = data_cache_get_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl,
  .data_cache_set_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataRequestHandler = data_cache_set_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method data_cache::get_OBC_0_Data (ID = 0x00000000)
static void data_cache_get_OBC_0_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_OBC_0_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_OBC_0_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_OBC_0_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_obc_0_data(&sOutput_data);

        respResult = data_cache_get_OBC_0_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_OBC_0_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_OBC_0_Data (ID = 0x00000000)

// @START@ Request handler for method data_cache::set_OBC_0_Data (ID = 0x00000001)
static void data_cache_set_OBC_0_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_OBC_0_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_OBC_0_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_OBC_0_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_OBC_0_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_OBC_0_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_OBC_0_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_OBC_0_Data (ID = 0x00000001)

// @START@ Request handler for method data_cache::get_ADCS_0_Data (ID = 0x00000002)
static void data_cache_get_ADCS_0_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_ADCS_0_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_ADCS_0_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_ADCS_0_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_adcs_0_data(&sOutput_data);

        respResult = data_cache_get_ADCS_0_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_ADCS_0_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_ADCS_0_Data (ID = 0x00000002)

// @START@ Request handler for method data_cache::set_ADCS_0_Data (ID = 0x00000003)
static void data_cache_set_ADCS_0_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_ADCS_0_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_ADCS_0_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_ADCS_0_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_ADCS_0_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_ADCS_0_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_ADCS_0_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_ADCS_0_Data (ID = 0x00000003)

// @START@ Request handler for method data_cache::get_ADCS_1_Data (ID = 0x00000004)
static void data_cache_get_ADCS_1_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_ADCS_1_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_ADCS_1_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_ADCS_1_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_adcs_1_data(&sOutput_data);

        respResult = data_cache_get_ADCS_1_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_ADCS_1_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_ADCS_1_Data (ID = 0x00000004)

// @START@ Request handler for method data_cache::set_ADCS_1_Data (ID = 0x00000005)
static void data_cache_set_ADCS_1_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_ADCS_1_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_ADCS_1_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_ADCS_1_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_ADCS_1_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_ADCS_1_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_ADCS_1_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_ADCS_1_Data (ID = 0x00000005)

// @START@ Request handler for method data_cache::get_ADCS_2_Data (ID = 0x00000006)
static void data_cache_get_ADCS_2_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_ADCS_2_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_ADCS_2_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_ADCS_2_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_adcs_2_data(&sOutput_data);

        respResult = data_cache_get_ADCS_2_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_ADCS_2_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_ADCS_2_Data (ID = 0x00000006)

// @START@ Request handler for method data_cache::set_ADCS_2_Data (ID = 0x00000007)
static void data_cache_set_ADCS_2_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_ADCS_2_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_ADCS_2_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_ADCS_2_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_ADCS_2_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_ADCS_2_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_ADCS_2_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_ADCS_2_Data (ID = 0x00000007)

// @START@ Request handler for method data_cache::get_EPS_0_Data (ID = 0x00000008)
static void data_cache_get_EPS_0_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_EPS_0_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS_0_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS_0_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps_0_data(&sOutput_data);

        respResult = data_cache_get_EPS_0_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS_0_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS_0_Data (ID = 0x00000008)

// @START@ Request handler for method data_cache::set_EPS_0_Data (ID = 0x00000009)
static void data_cache_set_EPS_0_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS_0_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS_0_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS_0_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS_0_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS_0_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS_0_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS_0_Data (ID = 0x00000009)

// @START@ Request handler for method data_cache::get_SSP_0_Data (ID = 0x0000000A)
static void data_cache_get_SSP_0_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_SSP_0_Telemetry_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_SSP_0_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_SSP_0_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_ssp_0_data(&sOutput_data);

        respResult = data_cache_get_SSP_0_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_SSP_0_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_SSP_0_Data (ID = 0x0000000A)

// @START@ Request handler for method data_cache::set_SSP_0_Data (ID = 0x0000000B)
static void data_cache_set_SSP_0_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_SSP_0_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_SSP_0_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_SSP_0_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_SSP_0_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_SSP_0_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_SSP_0_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_SSP_0_Data (ID = 0x0000000B)

// @START@ Request handler for method data_cache::get_SSP_1_Data (ID = 0x0000000C)
static void data_cache_get_SSP_1_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_SSP_1_Telemetry_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_SSP_1_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_SSP_1_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_ssp_1_data(&sOutput_data);

        respResult = data_cache_get_SSP_1_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_SSP_1_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_SSP_1_Data (ID = 0x0000000C)

// @START@ Request handler for method data_cache::set_SSP_1_Data (ID = 0x0000000D)
static void data_cache_set_SSP_1_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_SSP_1_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_SSP_1_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_SSP_1_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_SSP_1_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_SSP_1_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_SSP_1_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_SSP_1_Data (ID = 0x0000000D)

// @START@ Request handler for method data_cache::get_SSP_2_Data (ID = 0x0000000E)
static void data_cache_get_SSP_2_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_SSP_2_Telemetry_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_SSP_2_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_SSP_2_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_ssp_2_data(&sOutput_data);

        respResult = data_cache_get_SSP_2_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_SSP_2_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_SSP_2_Data (ID = 0x0000000E)

// @START@ Request handler for method data_cache::set_SSP_2_Data (ID = 0x0000000F)
static void data_cache_set_SSP_2_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_SSP_2_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_SSP_2_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_SSP_2_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_SSP_2_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_SSP_2_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_SSP_2_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_SSP_2_Data (ID = 0x0000000F)

// @START@ Request handler for method data_cache::get_SSP_3_Data (ID = 0x00000010)
static void data_cache_get_SSP_3_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_SSP_3_Telemetry_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_SSP_3_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_SSP_3_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_ssp_3_data(&sOutput_data);

        respResult = data_cache_get_SSP_3_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_SSP_3_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_SSP_3_Data (ID = 0x00000010)

// @START@ Request handler for method data_cache::set_SSP_3_Data (ID = 0x00000011)
static void data_cache_set_SSP_3_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_SSP_3_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_SSP_3_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_SSP_3_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_SSP_3_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_SSP_3_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_SSP_3_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_SSP_3_Data (ID = 0x00000011)

// @START@ Request handler for method data_cache::get_AOCS_CNTRL_TLM_Data (ID = 0x00000012)
static void data_cache_get_AOCS_CNTRL_TLM_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_AOCS_CNTRL_TLM_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_AOCS_CNTRL_TLM_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_AOCS_CNTRL_TLM_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_aocs_cntrl_tlm_data(&sOutput_data);

        respResult = data_cache_get_AOCS_CNTRL_TLM_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_AOCS_CNTRL_TLM_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_AOCS_CNTRL_TLM_Data (ID = 0x00000012)

// @START@ Request handler for method data_cache::set_AOCS_CNTRL_TLM_Data (ID = 0x00000013)
static void data_cache_set_AOCS_CNTRL_TLM_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_AOCS_CNTRL_TLM_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_AOCS_CNTRL_TLM_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_AOCS_CNTRL_TLM_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_AOCS_CNTRL_TLM_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_AOCS_CNTRL_TLM_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_AOCS_CNTRL_TLM_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_AOCS_CNTRL_TLM_Data (ID = 0x00000013)

// @START@ Request handler for method data_cache::get_AOCS_CNTRL_SYS_STATE_Data (ID = 0x00000014)
static void data_cache_get_AOCS_CNTRL_SYS_STATE_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_AOCS_CNTRL_SYS_STATE_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_AOCS_CNTRL_SYS_STATE_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_AOCS_CNTRL_SYS_STATE_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_aocs_cntrl_sys_state_data(&sOutput_data);

        respResult = data_cache_get_AOCS_CNTRL_SYS_STATE_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_AOCS_CNTRL_SYS_STATE_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_AOCS_CNTRL_SYS_STATE_Data (ID = 0x00000014)

// @START@ Request handler for method data_cache::set_AOCS_CNTRL_SYS_STATE_Data (ID = 0x00000015)
static void data_cache_set_AOCS_CNTRL_SYS_STATE_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_AOCS_CNTRL_SYS_STATE_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_AOCS_CNTRL_SYS_STATE_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_AOCS_CNTRL_SYS_STATE_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_AOCS_CNTRL_SYS_STATE_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_AOCS_CNTRL_SYS_STATE_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_AOCS_CNTRL_SYS_STATE_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_AOCS_CNTRL_SYS_STATE_Data (ID = 0x00000015)

// @START@ Request handler for method data_cache::get_AOCS_CNTRL_REF_PARAMS_Data (ID = 0x00000016)
static void data_cache_get_AOCS_CNTRL_REF_PARAMS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_AOCS_CNTRL_REF_PARAMS_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_AOCS_CNTRL_REF_PARAMS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_AOCS_CNTRL_REF_PARAMS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_aocs_cntrl_ref_params_data(&sOutput_data);

        respResult = data_cache_get_AOCS_CNTRL_REF_PARAMS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_AOCS_CNTRL_REF_PARAMS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_AOCS_CNTRL_REF_PARAMS_Data (ID = 0x00000016)

// @START@ Request handler for method data_cache::set_AOCS_CNTRL_REF_PARAMS_Data (ID = 0x00000017)
static void data_cache_set_AOCS_CNTRL_REF_PARAMS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_AOCS_CNTRL_REF_PARAMS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_AOCS_CNTRL_REF_PARAMS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_AOCS_CNTRL_REF_PARAMS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_AOCS_CNTRL_REF_PARAMS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_AOCS_CNTRL_REF_PARAMS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_AOCS_CNTRL_REF_PARAMS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_AOCS_CNTRL_REF_PARAMS_Data (ID = 0x00000017)

// @START@ Request handler for method data_cache::get_SENSOR_GYRO_SENSOR_FRAME_Data (ID = 0x00000018)
static void data_cache_get_SENSOR_GYRO_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_SENSOR_GYRO_SENSOR_FRAME_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_SENSOR_GYRO_SENSOR_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_SENSOR_GYRO_SENSOR_FRAME_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_sensor_gyro_sensor_frame_data(&sOutput_data);

        respResult = data_cache_get_SENSOR_GYRO_SENSOR_FRAME_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_SENSOR_GYRO_SENSOR_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_SENSOR_GYRO_SENSOR_FRAME_Data (ID = 0x00000018)

// @START@ Request handler for method data_cache::set_SENSOR_GYRO_SENSOR_FRAME_Data (ID = 0x00000019)
static void data_cache_set_SENSOR_GYRO_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_SENSOR_GYRO_SENSOR_FRAME_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_SENSOR_GYRO_SENSOR_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_SENSOR_GYRO_SENSOR_FRAME_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_SENSOR_GYRO_SENSOR_FRAME_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_SENSOR_GYRO_SENSOR_FRAME_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_SENSOR_GYRO_SENSOR_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_SENSOR_GYRO_SENSOR_FRAME_Data (ID = 0x00000019)

// @START@ Request handler for method data_cache::get_SENSOR_GYRO_BODY_FRAME_Data (ID = 0x0000001A)
static void data_cache_get_SENSOR_GYRO_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_SENSOR_GYRO_BODY_FRAME_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_SENSOR_GYRO_BODY_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_SENSOR_GYRO_BODY_FRAME_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_sensor_gyro_body_frame_data(&sOutput_data);

        respResult = data_cache_get_SENSOR_GYRO_BODY_FRAME_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_SENSOR_GYRO_BODY_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_SENSOR_GYRO_BODY_FRAME_Data (ID = 0x0000001A)

// @START@ Request handler for method data_cache::set_SENSOR_GYRO_BODY_FRAME_Data (ID = 0x0000001B)
static void data_cache_set_SENSOR_GYRO_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_SENSOR_GYRO_BODY_FRAME_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_SENSOR_GYRO_BODY_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_SENSOR_GYRO_BODY_FRAME_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_SENSOR_GYRO_BODY_FRAME_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_SENSOR_GYRO_BODY_FRAME_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_SENSOR_GYRO_BODY_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_SENSOR_GYRO_BODY_FRAME_Data (ID = 0x0000001B)

// @START@ Request handler for method data_cache::get_SENSOR_MAG_PRIMARY_SENSOR_FRAME_Data (ID = 0x0000001C)
static void data_cache_get_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_SENSOR_MAG_PRIMARY_SENSOR_FRAME_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_SENSOR_MAG_PRIMARY_SENSOR_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_SENSOR_MAG_PRIMARY_SENSOR_FRAME_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_sensor_mag_primary_sensor_frame_data(&sOutput_data);

        respResult = data_cache_get_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_SENSOR_MAG_PRIMARY_SENSOR_FRAME_Data (ID = 0x0000001C)

// @START@ Request handler for method data_cache::set_SENSOR_MAG_PRIMARY_SENSOR_FRAME_Data (ID = 0x0000001D)
static void data_cache_set_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_SENSOR_MAG_PRIMARY_SENSOR_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_SENSOR_MAG_PRIMARY_SENSOR_FRAME_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_SENSOR_MAG_PRIMARY_SENSOR_FRAME_Data (ID = 0x0000001D)

// @START@ Request handler for method data_cache::get_SENSOR_MAG_PRIMARY_BODY_FRAME_Data (ID = 0x0000001E)
static void data_cache_get_SENSOR_MAG_PRIMARY_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_SENSOR_MAG_PRIMARY_BODY_FRAME_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_SENSOR_MAG_PRIMARY_BODY_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_SENSOR_MAG_PRIMARY_BODY_FRAME_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_sensor_mag_primary_body_frame_data(&sOutput_data);

        respResult = data_cache_get_SENSOR_MAG_PRIMARY_BODY_FRAME_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_SENSOR_MAG_PRIMARY_BODY_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_SENSOR_MAG_PRIMARY_BODY_FRAME_Data (ID = 0x0000001E)

// @START@ Request handler for method data_cache::set_SENSOR_MAG_PRIMARY_BODY_FRAME_Data (ID = 0x0000001F)
static void data_cache_set_SENSOR_MAG_PRIMARY_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_SENSOR_MAG_PRIMARY_BODY_FRAME_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_SENSOR_MAG_PRIMARY_BODY_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_SENSOR_MAG_PRIMARY_BODY_FRAME_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_SENSOR_MAG_PRIMARY_BODY_FRAME_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_SENSOR_MAG_PRIMARY_BODY_FRAME_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_SENSOR_MAG_PRIMARY_BODY_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_SENSOR_MAG_PRIMARY_BODY_FRAME_Data (ID = 0x0000001F)

// @START@ Request handler for method data_cache::get_SENSOR_MAG_SECONDARY_SENSOR_FRAME_Data (ID = 0x00000020)
static void data_cache_get_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_SENSOR_MAG_SECONDARY_SENSOR_FRAME_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_SENSOR_MAG_SECONDARY_SENSOR_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_SENSOR_MAG_SECONDARY_SENSOR_FRAME_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_sensor_mag_secondary_sensor_frame_data(&sOutput_data);

        respResult = data_cache_get_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_SENSOR_MAG_SECONDARY_SENSOR_FRAME_Data (ID = 0x00000020)

// @START@ Request handler for method data_cache::set_SENSOR_MAG_SECONDARY_SENSOR_FRAME_Data (ID = 0x00000021)
static void data_cache_set_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_SENSOR_MAG_SECONDARY_SENSOR_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_SENSOR_MAG_SECONDARY_SENSOR_FRAME_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_SENSOR_MAG_SECONDARY_SENSOR_FRAME_Data (ID = 0x00000021)

// @START@ Request handler for method data_cache::get_SENSOR_MAG_SECONDARY_BODY_FRAME_Data (ID = 0x00000022)
static void data_cache_get_SENSOR_MAG_SECONDARY_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_SENSOR_MAG_SECONDARY_BODY_FRAME_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_SENSOR_MAG_SECONDARY_BODY_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_SENSOR_MAG_SECONDARY_BODY_FRAME_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_sensor_mag_secondary_body_frame_data(&sOutput_data);

        respResult = data_cache_get_SENSOR_MAG_SECONDARY_BODY_FRAME_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_SENSOR_MAG_SECONDARY_BODY_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_SENSOR_MAG_SECONDARY_BODY_FRAME_Data (ID = 0x00000022)

// @START@ Request handler for method data_cache::set_SENSOR_MAG_SECONDARY_BODY_FRAME_Data (ID = 0x00000023)
static void data_cache_set_SENSOR_MAG_SECONDARY_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_SENSOR_MAG_SECONDARY_BODY_FRAME_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_SENSOR_MAG_SECONDARY_BODY_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_SENSOR_MAG_SECONDARY_BODY_FRAME_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_SENSOR_MAG_SECONDARY_BODY_FRAME_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_SENSOR_MAG_SECONDARY_BODY_FRAME_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_SENSOR_MAG_SECONDARY_BODY_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_SENSOR_MAG_SECONDARY_BODY_FRAME_Data (ID = 0x00000023)

// @START@ Request handler for method data_cache::get_SENSOR_COARSE_SUN_SENSOR_FRAME_Data (ID = 0x00000024)
static void data_cache_get_SENSOR_COARSE_SUN_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_SENSOR_COARSE_SUN_SENSOR_FRAME_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_SENSOR_COARSE_SUN_SENSOR_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_SENSOR_COARSE_SUN_SENSOR_FRAME_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_sensor_coarse_sun_sensor_frame_data(&sOutput_data);

        respResult = data_cache_get_SENSOR_COARSE_SUN_SENSOR_FRAME_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_SENSOR_COARSE_SUN_SENSOR_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_SENSOR_COARSE_SUN_SENSOR_FRAME_Data (ID = 0x00000024)

// @START@ Request handler for method data_cache::set_SENSOR_COARSE_SUN_SENSOR_FRAME_Data (ID = 0x00000025)
static void data_cache_set_SENSOR_COARSE_SUN_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_SENSOR_COARSE_SUN_SENSOR_FRAME_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_SENSOR_COARSE_SUN_SENSOR_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_SENSOR_COARSE_SUN_SENSOR_FRAME_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_SENSOR_COARSE_SUN_SENSOR_FRAME_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_SENSOR_COARSE_SUN_SENSOR_FRAME_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_SENSOR_COARSE_SUN_SENSOR_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_SENSOR_COARSE_SUN_SENSOR_FRAME_Data (ID = 0x00000025)

// @START@ Request handler for method data_cache::get_SENSOR_COARSE_SUN_BODY_FRAME_Data (ID = 0x00000026)
static void data_cache_get_SENSOR_COARSE_SUN_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_SENSOR_COARSE_SUN_BODY_FRAME_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_SENSOR_COARSE_SUN_BODY_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_SENSOR_COARSE_SUN_BODY_FRAME_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_sensor_coarse_sun_body_frame_data(&sOutput_data);

        respResult = data_cache_get_SENSOR_COARSE_SUN_BODY_FRAME_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_SENSOR_COARSE_SUN_BODY_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_SENSOR_COARSE_SUN_BODY_FRAME_Data (ID = 0x00000026)

// @START@ Request handler for method data_cache::set_SENSOR_COARSE_SUN_BODY_FRAME_Data (ID = 0x00000027)
static void data_cache_set_SENSOR_COARSE_SUN_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_SENSOR_COARSE_SUN_BODY_FRAME_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_SENSOR_COARSE_SUN_BODY_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_SENSOR_COARSE_SUN_BODY_FRAME_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_SENSOR_COARSE_SUN_BODY_FRAME_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_SENSOR_COARSE_SUN_BODY_FRAME_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_SENSOR_COARSE_SUN_BODY_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_SENSOR_COARSE_SUN_BODY_FRAME_Data (ID = 0x00000027)

// @START@ Request handler for method data_cache::get_SENSOR_PANEL_TEMP_SENSOR_FRAME_Data (ID = 0x00000028)
static void data_cache_get_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_SENSOR_PANEL_TEMP_SENSOR_FRAME_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_SENSOR_PANEL_TEMP_SENSOR_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_SENSOR_PANEL_TEMP_SENSOR_FRAME_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_sensor_panel_temp_sensor_frame_data(&sOutput_data);

        respResult = data_cache_get_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_SENSOR_PANEL_TEMP_SENSOR_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_SENSOR_PANEL_TEMP_SENSOR_FRAME_Data (ID = 0x00000028)

// @START@ Request handler for method data_cache::set_SENSOR_PANEL_TEMP_SENSOR_FRAME_Data (ID = 0x00000029)
static void data_cache_set_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_SENSOR_PANEL_TEMP_SENSOR_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_SENSOR_PANEL_TEMP_SENSOR_FRAME_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_SENSOR_PANEL_TEMP_SENSOR_FRAME_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_SENSOR_PANEL_TEMP_SENSOR_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_SENSOR_PANEL_TEMP_SENSOR_FRAME_Data (ID = 0x00000029)

// @START@ Request handler for method data_cache::get_SENSOR_PANEL_TEMP_BODY_FRAME_Data (ID = 0x0000002A)
static void data_cache_get_SENSOR_PANEL_TEMP_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_SENSOR_PANEL_TEMP_BODY_FRAME_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_SENSOR_PANEL_TEMP_BODY_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_SENSOR_PANEL_TEMP_BODY_FRAME_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_sensor_panel_temp_body_frame_data(&sOutput_data);

        respResult = data_cache_get_SENSOR_PANEL_TEMP_BODY_FRAME_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_SENSOR_PANEL_TEMP_BODY_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_SENSOR_PANEL_TEMP_BODY_FRAME_Data (ID = 0x0000002A)

// @START@ Request handler for method data_cache::set_SENSOR_PANEL_TEMP_BODY_FRAME_Data (ID = 0x0000002B)
static void data_cache_set_SENSOR_PANEL_TEMP_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_SENSOR_PANEL_TEMP_BODY_FRAME_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_SENSOR_PANEL_TEMP_BODY_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_SENSOR_PANEL_TEMP_BODY_FRAME_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_SENSOR_PANEL_TEMP_BODY_FRAME_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_SENSOR_PANEL_TEMP_BODY_FRAME_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_SENSOR_PANEL_TEMP_BODY_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_SENSOR_PANEL_TEMP_BODY_FRAME_Data (ID = 0x0000002B)

// @START@ Request handler for method data_cache::get_SENSOR_GYRO_TEMP_SENSOR_FRAME_Data (ID = 0x0000002C)
static void data_cache_get_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_SENSOR_GYRO_TEMP_SENSOR_FRAME_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_SENSOR_GYRO_TEMP_SENSOR_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_SENSOR_GYRO_TEMP_SENSOR_FRAME_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_sensor_gyro_temp_sensor_frame_data(&sOutput_data);

        respResult = data_cache_get_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_SENSOR_GYRO_TEMP_SENSOR_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_SENSOR_GYRO_TEMP_SENSOR_FRAME_Data (ID = 0x0000002C)

// @START@ Request handler for method data_cache::set_SENSOR_GYRO_TEMP_SENSOR_FRAME_Data (ID = 0x0000002D)
static void data_cache_set_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_SENSOR_GYRO_TEMP_SENSOR_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_SENSOR_GYRO_TEMP_SENSOR_FRAME_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_SENSOR_GYRO_TEMP_SENSOR_FRAME_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_SENSOR_GYRO_TEMP_SENSOR_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_SENSOR_GYRO_TEMP_SENSOR_FRAME_Data (ID = 0x0000002D)

// @START@ Request handler for method data_cache::get_SENSOR_GYRO_TEMP_BODY_FRAME_Data (ID = 0x0000002E)
static void data_cache_get_SENSOR_GYRO_TEMP_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_SENSOR_GYRO_TEMP_BODY_FRAME_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_SENSOR_GYRO_TEMP_BODY_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_SENSOR_GYRO_TEMP_BODY_FRAME_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_sensor_gyro_temp_body_frame_data(&sOutput_data);

        respResult = data_cache_get_SENSOR_GYRO_TEMP_BODY_FRAME_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_SENSOR_GYRO_TEMP_BODY_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_SENSOR_GYRO_TEMP_BODY_FRAME_Data (ID = 0x0000002E)

// @START@ Request handler for method data_cache::set_SENSOR_GYRO_TEMP_BODY_FRAME_Data (ID = 0x0000002F)
static void data_cache_set_SENSOR_GYRO_TEMP_BODY_FRAME_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_SENSOR_GYRO_TEMP_BODY_FRAME_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_SENSOR_GYRO_TEMP_BODY_FRAME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_SENSOR_GYRO_TEMP_BODY_FRAME_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_SENSOR_GYRO_TEMP_BODY_FRAME_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_SENSOR_GYRO_TEMP_BODY_FRAME_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_SENSOR_GYRO_TEMP_BODY_FRAME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_SENSOR_GYRO_TEMP_BODY_FRAME_Data (ID = 0x0000002F)

// @START@ Request handler for method data_cache::get_ACTUATOR_MTQ_VALUES_Data (ID = 0x00000030)
static void data_cache_get_ACTUATOR_MTQ_VALUES_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_ACTUATOR_MTQ_VALUES_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_ACTUATOR_MTQ_VALUES_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_ACTUATOR_MTQ_VALUES_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_actuator_mtq_values_data(&sOutput_data);

        respResult = data_cache_get_ACTUATOR_MTQ_VALUES_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_ACTUATOR_MTQ_VALUES_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_ACTUATOR_MTQ_VALUES_Data (ID = 0x00000030)

// @START@ Request handler for method data_cache::set_ACTUATOR_MTQ_VALUES_Data (ID = 0x00000031)
static void data_cache_set_ACTUATOR_MTQ_VALUES_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_ACTUATOR_MTQ_VALUES_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_ACTUATOR_MTQ_VALUES_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_ACTUATOR_MTQ_VALUES_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_ACTUATOR_MTQ_VALUES_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_ACTUATOR_MTQ_VALUES_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_ACTUATOR_MTQ_VALUES_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_ACTUATOR_MTQ_VALUES_Data (ID = 0x00000031)

// @START@ Request handler for method data_cache::get_ACTUATOR_TORQUE_VALUES_Data (ID = 0x00000032)
static void data_cache_get_ACTUATOR_TORQUE_VALUES_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_ACTUATOR_TORQUE_VALUES_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_ACTUATOR_TORQUE_VALUES_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_ACTUATOR_TORQUE_VALUES_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_actuator_torque_values_data(&sOutput_data);

        respResult = data_cache_get_ACTUATOR_TORQUE_VALUES_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_ACTUATOR_TORQUE_VALUES_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_ACTUATOR_TORQUE_VALUES_Data (ID = 0x00000032)

// @START@ Request handler for method data_cache::set_ACTUATOR_TORQUE_VALUES_Data (ID = 0x00000033)
static void data_cache_set_ACTUATOR_TORQUE_VALUES_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_ACTUATOR_TORQUE_VALUES_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_ACTUATOR_TORQUE_VALUES_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_ACTUATOR_TORQUE_VALUES_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_ACTUATOR_TORQUE_VALUES_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_ACTUATOR_TORQUE_VALUES_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_ACTUATOR_TORQUE_VALUES_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_ACTUATOR_TORQUE_VALUES_Data (ID = 0x00000033)

// @START@ Request handler for method data_cache::get_ADCS_3_Data (ID = 0x00000034)
static void data_cache_get_ADCS_3_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_ADCS_3_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_ADCS_3_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_ADCS_3_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_adcs_3_data(&sOutput_data);

        respResult = data_cache_get_ADCS_3_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_ADCS_3_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_ADCS_3_Data (ID = 0x00000034)

// @START@ Request handler for method data_cache::set_ADCS_3_Data (ID = 0x00000035)
static void data_cache_set_ADCS_3_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_ADCS_3_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_ADCS_3_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_ADCS_3_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_ADCS_3_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_ADCS_3_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_ADCS_3_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_ADCS_3_Data (ID = 0x00000035)

// @START@ Request handler for method data_cache::get_ADCS_4_Data (ID = 0x00000036)
static void data_cache_get_ADCS_4_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_ADCS_4_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_ADCS_4_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_ADCS_4_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_adcs_4_data(&sOutput_data);

        respResult = data_cache_get_ADCS_4_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_ADCS_4_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_ADCS_4_Data (ID = 0x00000036)

// @START@ Request handler for method data_cache::set_ADCS_4_Data (ID = 0x00000037)
static void data_cache_set_ADCS_4_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_ADCS_4_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_ADCS_4_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_ADCS_4_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_ADCS_4_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_ADCS_4_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_ADCS_4_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_ADCS_4_Data (ID = 0x00000037)

// @START@ Request handler for method data_cache::get_EPS_9_Data (ID = 0x00000038)
static void data_cache_get_EPS_9_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_EPS_9_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS_9_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS_9_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps_9_data(&sOutput_data);

        respResult = data_cache_get_EPS_9_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS_9_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS_9_Data (ID = 0x00000038)

// @START@ Request handler for method data_cache::set_EPS_9_Data (ID = 0x00000039)
static void data_cache_set_EPS_9_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS_9_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS_9_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS_9_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS_9_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS_9_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS_9_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS_9_Data (ID = 0x00000039)

// @START@ Request handler for method data_cache::get_EPS_10_Data (ID = 0x0000003A)
static void data_cache_get_EPS_10_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_EPS_10_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS_10_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS_10_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps_10_data(&sOutput_data);

        respResult = data_cache_get_EPS_10_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS_10_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS_10_Data (ID = 0x0000003A)

// @START@ Request handler for method data_cache::set_EPS_10_Data (ID = 0x0000003B)
static void data_cache_set_EPS_10_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS_10_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS_10_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS_10_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS_10_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS_10_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS_10_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS_10_Data (ID = 0x0000003B)

// @START@ Request handler for method data_cache::get_EPS_14_Data (ID = 0x0000003C)
static void data_cache_get_EPS_14_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_EPS_14_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS_14_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS_14_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps_14_data(&sOutput_data);

        respResult = data_cache_get_EPS_14_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS_14_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS_14_Data (ID = 0x0000003C)

// @START@ Request handler for method data_cache::set_EPS_14_Data (ID = 0x0000003D)
static void data_cache_set_EPS_14_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS_14_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS_14_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS_14_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS_14_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS_14_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS_14_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS_14_Data (ID = 0x0000003D)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_OP_STATUS_COMMON_Data (ID = 0x0000003E)
static void data_cache_get_CUBEADCS_GEN2_OP_STATUS_COMMON_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_OP_STATUS_COMMON_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_OP_STATUS_COMMON_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_OP_STATUS_COMMON_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_op_status_common_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_OP_STATUS_COMMON_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_OP_STATUS_COMMON_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_OP_STATUS_COMMON_Data (ID = 0x0000003E)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_OP_STATUS_COMMON_Data (ID = 0x0000003F)
static void data_cache_set_CUBEADCS_GEN2_OP_STATUS_COMMON_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_OP_STATUS_COMMON_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_OP_STATUS_COMMON_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_OP_STATUS_COMMON_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_OP_STATUS_COMMON_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_OP_STATUS_COMMON_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_OP_STATUS_COMMON_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_OP_STATUS_COMMON_Data (ID = 0x0000003F)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_OP_STATUS_APP_Data (ID = 0x00000040)
static void data_cache_get_CUBEADCS_GEN2_OP_STATUS_APP_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_OP_STATUS_APP_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_OP_STATUS_APP_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_OP_STATUS_APP_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_op_status_app_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_OP_STATUS_APP_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_OP_STATUS_APP_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_OP_STATUS_APP_Data (ID = 0x00000040)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_OP_STATUS_APP_Data (ID = 0x00000041)
static void data_cache_set_CUBEADCS_GEN2_OP_STATUS_APP_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_OP_STATUS_APP_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_OP_STATUS_APP_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_OP_STATUS_APP_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_OP_STATUS_APP_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_OP_STATUS_APP_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_OP_STATUS_APP_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_OP_STATUS_APP_Data (ID = 0x00000041)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_166_Data (ID = 0x00000042)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_166_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_166_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_166_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_166_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_166_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_166_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_166_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_166_Data (ID = 0x00000042)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_166_Data (ID = 0x00000043)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_166_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_166_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_166_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_166_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_166_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_166_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_166_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_166_Data (ID = 0x00000043)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_167_Data (ID = 0x00000044)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_167_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_167_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_167_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_167_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_167_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_167_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_167_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_167_Data (ID = 0x00000044)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_167_Data (ID = 0x00000045)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_167_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_167_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_167_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_167_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_167_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_167_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_167_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_167_Data (ID = 0x00000045)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_168_Data (ID = 0x00000046)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_168_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_168_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_168_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_168_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_168_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_168_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_168_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_168_Data (ID = 0x00000046)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_168_Data (ID = 0x00000047)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_168_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_168_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_168_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_168_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_168_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_168_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_168_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_168_Data (ID = 0x00000047)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_169_Data (ID = 0x00000048)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_169_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_169_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_169_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_169_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_169_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_169_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_169_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_169_Data (ID = 0x00000048)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_169_Data (ID = 0x00000049)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_169_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_169_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_169_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_169_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_169_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_169_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_169_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_169_Data (ID = 0x00000049)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_170_Data (ID = 0x0000004A)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_170_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_170_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_170_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_170_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_170_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_170_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_170_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_170_Data (ID = 0x0000004A)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_170_Data (ID = 0x0000004B)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_170_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_170_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_170_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_170_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_170_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_170_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_170_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_170_Data (ID = 0x0000004B)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_171_Data (ID = 0x0000004C)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_171_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_171_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_171_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_171_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_171_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_171_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_171_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_171_Data (ID = 0x0000004C)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_171_Data (ID = 0x0000004D)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_171_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_171_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_171_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_171_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_171_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_171_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_171_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_171_Data (ID = 0x0000004D)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_172_Data (ID = 0x0000004E)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_172_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_172_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_172_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_172_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_172_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_172_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_172_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_172_Data (ID = 0x0000004E)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_172_Data (ID = 0x0000004F)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_172_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_172_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_172_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_172_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_172_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_172_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_172_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_172_Data (ID = 0x0000004F)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_173_Data (ID = 0x00000050)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_173_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_173_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_173_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_173_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_173_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_173_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_173_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_173_Data (ID = 0x00000050)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_173_Data (ID = 0x00000051)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_173_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_173_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_173_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_173_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_173_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_173_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_173_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_173_Data (ID = 0x00000051)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_174_Data (ID = 0x00000052)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_174_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_174_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_174_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_174_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_174_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_174_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_174_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_174_Data (ID = 0x00000052)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_174_Data (ID = 0x00000053)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_174_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_174_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_174_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_174_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_174_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_174_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_174_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_174_Data (ID = 0x00000053)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_175_Data (ID = 0x00000054)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_175_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_175_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_175_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_175_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_175_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_175_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_175_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_175_Data (ID = 0x00000054)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_175_Data (ID = 0x00000055)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_175_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_175_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_175_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_175_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_175_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_175_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_175_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_175_Data (ID = 0x00000055)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_176_Data (ID = 0x00000056)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_176_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_176_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_176_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_176_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_176_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_176_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_176_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_176_Data (ID = 0x00000056)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_176_Data (ID = 0x00000057)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_176_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_176_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_176_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_176_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_176_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_176_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_176_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_176_Data (ID = 0x00000057)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_177_Data (ID = 0x00000058)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_177_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_177_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_177_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_177_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_177_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_177_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_177_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_177_Data (ID = 0x00000058)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_177_Data (ID = 0x00000059)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_177_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_177_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_177_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_177_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_177_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_177_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_177_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_177_Data (ID = 0x00000059)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_178_Data (ID = 0x0000005A)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_178_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_178_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_178_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_178_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_178_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_178_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_178_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_178_Data (ID = 0x0000005A)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_178_Data (ID = 0x0000005B)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_178_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_178_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_178_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_178_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_178_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_178_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_178_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_178_Data (ID = 0x0000005B)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_179_Data (ID = 0x0000005C)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_179_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_179_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_179_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_179_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_179_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_179_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_179_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_179_Data (ID = 0x0000005C)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_179_Data (ID = 0x0000005D)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_179_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_179_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_179_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_179_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_179_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_179_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_179_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_179_Data (ID = 0x0000005D)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_180_Data (ID = 0x0000005E)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_180_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_180_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_180_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_180_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_180_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_180_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_180_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_180_Data (ID = 0x0000005E)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_180_Data (ID = 0x0000005F)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_180_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_180_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_180_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_180_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_180_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_180_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_180_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_180_Data (ID = 0x0000005F)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_203_Data (ID = 0x00000060)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_203_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_203_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_203_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_203_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_203_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_203_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_203_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_203_Data (ID = 0x00000060)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_203_Data (ID = 0x00000061)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_203_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_203_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_203_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_203_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_203_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_203_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_203_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_203_Data (ID = 0x00000061)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_204_Data (ID = 0x00000062)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_204_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_204_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_204_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_204_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_204_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_204_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_204_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_204_Data (ID = 0x00000062)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_204_Data (ID = 0x00000063)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_204_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_204_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_204_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_204_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_204_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_204_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_204_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_204_Data (ID = 0x00000063)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_205_Data (ID = 0x00000064)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_205_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_205_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_205_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_205_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_205_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_205_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_205_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_205_Data (ID = 0x00000064)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_205_Data (ID = 0x00000065)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_205_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_205_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_205_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_205_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_205_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_205_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_205_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_205_Data (ID = 0x00000065)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_206_Data (ID = 0x00000066)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_206_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_206_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_206_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_206_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_206_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_206_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_206_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_206_Data (ID = 0x00000066)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_206_Data (ID = 0x00000067)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_206_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_206_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_206_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_206_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_206_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_206_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_206_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_206_Data (ID = 0x00000067)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_207_Data (ID = 0x00000068)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_207_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_207_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_207_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_207_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_207_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_207_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_207_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_207_Data (ID = 0x00000068)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_207_Data (ID = 0x00000069)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_207_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_207_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_207_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_207_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_207_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_207_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_207_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_207_Data (ID = 0x00000069)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_208_1_Data (ID = 0x0000006A)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_208_1_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_208_1_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_208_1_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_208_1_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_208_1_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_208_1_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_208_1_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_208_1_Data (ID = 0x0000006A)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_208_1_Data (ID = 0x0000006B)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_208_1_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_208_1_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_208_1_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_208_1_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_208_1_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_208_1_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_208_1_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_208_1_Data (ID = 0x0000006B)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_208_2_Data (ID = 0x0000006C)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_208_2_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_208_2_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_208_2_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_208_2_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_208_2_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_208_2_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_208_2_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_208_2_Data (ID = 0x0000006C)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_208_2_Data (ID = 0x0000006D)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_208_2_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_208_2_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_208_2_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_208_2_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_208_2_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_208_2_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_208_2_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_208_2_Data (ID = 0x0000006D)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_209_Data (ID = 0x0000006E)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_209_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_209_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_209_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_209_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_209_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_209_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_209_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_209_Data (ID = 0x0000006E)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_209_Data (ID = 0x0000006F)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_209_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_209_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_209_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_209_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_209_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_209_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_209_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_209_Data (ID = 0x0000006F)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_210_Data (ID = 0x00000070)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_210_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_210_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_210_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_210_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_210_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_210_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_210_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_210_Data (ID = 0x00000070)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_210_Data (ID = 0x00000071)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_210_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_210_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_210_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_210_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_210_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_210_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_210_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_210_Data (ID = 0x00000071)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_211_Data (ID = 0x00000072)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_211_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_211_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_211_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_211_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_211_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_211_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_211_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_211_Data (ID = 0x00000072)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_211_Data (ID = 0x00000073)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_211_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_211_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_211_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_211_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_211_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_211_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_211_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_211_Data (ID = 0x00000073)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_212_Data (ID = 0x00000074)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_212_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_212_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_212_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_212_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_212_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_212_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_212_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_212_Data (ID = 0x00000074)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_212_Data (ID = 0x00000075)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_212_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_212_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_212_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_212_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_212_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_212_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_212_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_212_Data (ID = 0x00000075)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_213_Data (ID = 0x00000076)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_213_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_213_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_213_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_213_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_213_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_213_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_213_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_213_Data (ID = 0x00000076)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_213_Data (ID = 0x00000077)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_213_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_213_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_213_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_213_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_213_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_213_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_213_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_213_Data (ID = 0x00000077)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_214_Data (ID = 0x00000078)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_214_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_214_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_214_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_214_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_214_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_214_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_214_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_214_Data (ID = 0x00000078)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_214_Data (ID = 0x00000079)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_214_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_214_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_214_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_214_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_214_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_214_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_214_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_214_Data (ID = 0x00000079)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_216_Data (ID = 0x0000007A)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_216_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_216_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_216_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_216_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_216_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_216_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_216_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_216_Data (ID = 0x0000007A)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_216_Data (ID = 0x0000007B)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_216_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_216_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_216_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_216_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_216_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_216_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_216_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_216_Data (ID = 0x0000007B)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_217_Data (ID = 0x0000007C)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_217_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_217_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_217_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_217_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_217_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_217_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_217_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_217_Data (ID = 0x0000007C)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_217_Data (ID = 0x0000007D)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_217_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_217_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_217_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_217_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_217_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_217_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_217_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_217_Data (ID = 0x0000007D)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_218_Data (ID = 0x0000007E)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_218_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_218_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_218_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_218_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_218_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_218_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_218_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_218_Data (ID = 0x0000007E)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_218_Data (ID = 0x0000007F)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_218_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_218_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_218_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_218_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_218_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_218_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_218_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_218_Data (ID = 0x0000007F)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_225_Data (ID = 0x00000080)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_225_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_225_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_225_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_225_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_225_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_225_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_225_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_225_Data (ID = 0x00000080)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_225_Data (ID = 0x00000081)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_225_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_225_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_225_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_225_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_225_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_225_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_225_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_225_Data (ID = 0x00000081)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_226_Data (ID = 0x00000082)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_226_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_226_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_226_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_226_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_226_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_226_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_226_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_226_Data (ID = 0x00000082)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_226_Data (ID = 0x00000083)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_226_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_226_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_226_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_226_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_226_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_226_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_226_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_226_Data (ID = 0x00000083)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_165_Data (ID = 0x00000084)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_165_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_165_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_165_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_165_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_165_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_165_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_165_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_165_Data (ID = 0x00000084)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_165_Data (ID = 0x00000085)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_165_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_165_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_165_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_165_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_165_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_165_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_165_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_165_Data (ID = 0x00000085)

// @START@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_221_Data (ID = 0x00000086)
static void data_cache_get_CUBEADCS_GEN2_TLM_FRAME_221_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_221_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_221_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_CUBEADCS_GEN2_TLM_FRAME_221_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_cubeadcs_gen2_tlm_frame_221_data(&sOutput_data);

        respResult = data_cache_get_CUBEADCS_GEN2_TLM_FRAME_221_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_CUBEADCS_GEN2_TLM_FRAME_221_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_CUBEADCS_GEN2_TLM_FRAME_221_Data (ID = 0x00000086)

// @START@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_221_Data (ID = 0x00000087)
static void data_cache_set_CUBEADCS_GEN2_TLM_FRAME_221_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_221_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_221_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_CUBEADCS_GEN2_TLM_FRAME_221_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_CUBEADCS_GEN2_TLM_FRAME_221_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_CUBEADCS_GEN2_TLM_FRAME_221_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_CUBEADCS_GEN2_TLM_FRAME_221_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_CUBEADCS_GEN2_TLM_FRAME_221_Data (ID = 0x00000087)

// @START@ Request handler for method data_cache::get_GNSS_TIME_Data (ID = 0x00000088)
static void data_cache_get_GNSS_TIME_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_GNSS_TIME_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_GNSS_TIME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_GNSS_TIME_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_gnss_time_data(&sOutput_data);

        respResult = data_cache_get_GNSS_TIME_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_GNSS_TIME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_GNSS_TIME_Data (ID = 0x00000088)

// @START@ Request handler for method data_cache::set_GNSS_TIME_Data (ID = 0x00000089)
static void data_cache_set_GNSS_TIME_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_GNSS_TIME_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_GNSS_TIME_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_GNSS_TIME_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_GNSS_TIME_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_GNSS_TIME_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_GNSS_TIME_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_GNSS_TIME_Data (ID = 0x00000089)

// @START@ Request handler for method data_cache::get_GNSS_BESTXYZ_Data (ID = 0x0000008A)
static void data_cache_get_GNSS_BESTXYZ_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_GNSS_BESTXYZ_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_GNSS_BESTXYZ_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_GNSS_BESTXYZ_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_gnss_bestxyz_data(&sOutput_data);

        respResult = data_cache_get_GNSS_BESTXYZ_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_GNSS_BESTXYZ_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_GNSS_BESTXYZ_Data (ID = 0x0000008A)

// @START@ Request handler for method data_cache::set_GNSS_BESTXYZ_Data (ID = 0x0000008B)
static void data_cache_set_GNSS_BESTXYZ_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_GNSS_BESTXYZ_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_GNSS_BESTXYZ_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_GNSS_BESTXYZ_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_GNSS_BESTXYZ_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_GNSS_BESTXYZ_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_GNSS_BESTXYZ_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_GNSS_BESTXYZ_Data (ID = 0x0000008B)

// @START@ Request handler for method data_cache::get_SAT_STATE_VECTOR_FROM_PROPAGATOR_Data (ID = 0x0000008C)
static void data_cache_get_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_SAT_STATE_VECTOR_FROM_PROPAGATOR_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_SAT_STATE_VECTOR_FROM_PROPAGATOR_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_SAT_STATE_VECTOR_FROM_PROPAGATOR_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_sat_state_vector_from_propagator_data(&sOutput_data);

        respResult = data_cache_get_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_SAT_STATE_VECTOR_FROM_PROPAGATOR_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_SAT_STATE_VECTOR_FROM_PROPAGATOR_Data (ID = 0x0000008C)

// @START@ Request handler for method data_cache::set_SAT_STATE_VECTOR_FROM_PROPAGATOR_Data (ID = 0x0000008D)
static void data_cache_set_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_SAT_STATE_VECTOR_FROM_PROPAGATOR_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_SAT_STATE_VECTOR_FROM_PROPAGATOR_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_SAT_STATE_VECTOR_FROM_PROPAGATOR_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_SAT_STATE_VECTOR_FROM_PROPAGATOR_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_SAT_STATE_VECTOR_FROM_PROPAGATOR_Data (ID = 0x0000008D)

// @START@ Request handler for method data_cache::get_SAT_MAG_FIELD_VECTOR_FROM_MODEL_Data (ID = 0x0000008E)
static void data_cache_get_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_SAT_MAG_FIELD_VECTOR_FROM_MODEL_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_SAT_MAG_FIELD_VECTOR_FROM_MODEL_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_SAT_MAG_FIELD_VECTOR_FROM_MODEL_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_sat_mag_field_vector_from_model_data(&sOutput_data);

        respResult = data_cache_get_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_SAT_MAG_FIELD_VECTOR_FROM_MODEL_Data (ID = 0x0000008E)

// @START@ Request handler for method data_cache::set_SAT_MAG_FIELD_VECTOR_FROM_MODEL_Data (ID = 0x0000008F)
static void data_cache_set_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_SAT_MAG_FIELD_VECTOR_FROM_MODEL_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_SAT_MAG_FIELD_VECTOR_FROM_MODEL_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_SAT_MAG_FIELD_VECTOR_FROM_MODEL_Data (ID = 0x0000008F)

// @START@ Request handler for method data_cache::get_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_Data (ID = 0x00000090)
static void data_cache_get_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_sat_mag_field_vector_from_sensor_data(&sOutput_data);

        respResult = data_cache_get_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_Data (ID = 0x00000090)

// @START@ Request handler for method data_cache::set_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_Data (ID = 0x00000091)
static void data_cache_set_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_Data (ID = 0x00000091)

// @START@ Request handler for method data_cache::get_FDIR_EPS_I_CMD_EXEC_STATUS_Data (ID = 0x00000092)
static void data_cache_get_FDIR_EPS_I_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_FDIR_EPS_I_CMD_EXEC_STATUS_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_FDIR_EPS_I_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_FDIR_EPS_I_CMD_EXEC_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_fdir_eps_i_cmd_exec_status_data(&sOutput_data);

        respResult = data_cache_get_FDIR_EPS_I_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_FDIR_EPS_I_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_FDIR_EPS_I_CMD_EXEC_STATUS_Data (ID = 0x00000092)

// @START@ Request handler for method data_cache::set_FDIR_EPS_I_CMD_EXEC_STATUS_Data (ID = 0x00000093)
static void data_cache_set_FDIR_EPS_I_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_FDIR_EPS_I_CMD_EXEC_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_FDIR_EPS_I_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_FDIR_EPS_I_CMD_EXEC_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_FDIR_EPS_I_CMD_EXEC_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_FDIR_EPS_I_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_FDIR_EPS_I_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_FDIR_EPS_I_CMD_EXEC_STATUS_Data (ID = 0x00000093)

// @START@ Request handler for method data_cache::get_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_Data (ID = 0x00000094)
static void data_cache_get_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_fdir_eps_ii_pdm_cmd_exec_status_data(&sOutput_data);

        respResult = data_cache_get_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_Data (ID = 0x00000094)

// @START@ Request handler for method data_cache::set_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_Data (ID = 0x00000095)
static void data_cache_set_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_Data (ID = 0x00000095)

// @START@ Request handler for method data_cache::get_FDIR_CUBEADCS_CMD_EXEC_STATUS_Data (ID = 0x00000096)
static void data_cache_get_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_FDIR_CUBEADCS_CMD_EXEC_STATUS_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_FDIR_CUBEADCS_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_FDIR_CUBEADCS_CMD_EXEC_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_fdir_cubeadcs_cmd_exec_status_data(&sOutput_data);

        respResult = data_cache_get_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_FDIR_CUBEADCS_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_FDIR_CUBEADCS_CMD_EXEC_STATUS_Data (ID = 0x00000096)

// @START@ Request handler for method data_cache::set_FDIR_CUBEADCS_CMD_EXEC_STATUS_Data (ID = 0x00000097)
static void data_cache_set_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_FDIR_CUBEADCS_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_FDIR_CUBEADCS_CMD_EXEC_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_FDIR_CUBEADCS_CMD_EXEC_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_FDIR_CUBEADCS_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_FDIR_CUBEADCS_CMD_EXEC_STATUS_Data (ID = 0x00000097)

// @START@ Request handler for method data_cache::get_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_Data (ID = 0x00000098)
static void data_cache_get_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_fdir_cubeadcs_gen2_cmd_exec_status_data(&sOutput_data);

        respResult = data_cache_get_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_Data (ID = 0x00000098)

// @START@ Request handler for method data_cache::set_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_Data (ID = 0x00000099)
static void data_cache_set_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_Data (ID = 0x00000099)

// @START@ Request handler for method data_cache::get_FDIR_CUBEADCS_GEN2_EVENTS_Data (ID = 0x0000009A)
static void data_cache_get_FDIR_CUBEADCS_GEN2_EVENTS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_FDIR_CUBEADCS_GEN2_EVENTS_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_FDIR_CUBEADCS_GEN2_EVENTS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_FDIR_CUBEADCS_GEN2_EVENTS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_fdir_cubeadcs_gen2_events_data(&sOutput_data);

        respResult = data_cache_get_FDIR_CUBEADCS_GEN2_EVENTS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_FDIR_CUBEADCS_GEN2_EVENTS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_FDIR_CUBEADCS_GEN2_EVENTS_Data (ID = 0x0000009A)

// @START@ Request handler for method data_cache::set_FDIR_CUBEADCS_GEN2_EVENTS_Data (ID = 0x0000009B)
static void data_cache_set_FDIR_CUBEADCS_GEN2_EVENTS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_FDIR_CUBEADCS_GEN2_EVENTS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_FDIR_CUBEADCS_GEN2_EVENTS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_FDIR_CUBEADCS_GEN2_EVENTS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_FDIR_CUBEADCS_GEN2_EVENTS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_FDIR_CUBEADCS_GEN2_EVENTS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_FDIR_CUBEADCS_GEN2_EVENTS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_FDIR_CUBEADCS_GEN2_EVENTS_Data (ID = 0x0000009B)

// @START@ Request handler for method data_cache::get_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_Data (ID = 0x0000009C)
static void data_cache_get_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_fdir_s_band_tmtc_cmd_exec_status_data(&sOutput_data);

        respResult = data_cache_get_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_Data (ID = 0x0000009C)

// @START@ Request handler for method data_cache::set_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_Data (ID = 0x0000009D)
static void data_cache_set_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_Data (ID = 0x0000009D)

// @START@ Request handler for method data_cache::get_FDIR_UHF_CMD_EXEC_STATUS_Data (ID = 0x0000009E)
static void data_cache_get_FDIR_UHF_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_FDIR_UHF_CMD_EXEC_STATUS_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_FDIR_UHF_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_FDIR_UHF_CMD_EXEC_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_fdir_uhf_cmd_exec_status_data(&sOutput_data);

        respResult = data_cache_get_FDIR_UHF_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_FDIR_UHF_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_FDIR_UHF_CMD_EXEC_STATUS_Data (ID = 0x0000009E)

// @START@ Request handler for method data_cache::set_FDIR_UHF_CMD_EXEC_STATUS_Data (ID = 0x0000009F)
static void data_cache_set_FDIR_UHF_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_FDIR_UHF_CMD_EXEC_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_FDIR_UHF_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_FDIR_UHF_CMD_EXEC_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_FDIR_UHF_CMD_EXEC_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_FDIR_UHF_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_FDIR_UHF_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_FDIR_UHF_CMD_EXEC_STATUS_Data (ID = 0x0000009F)

// @START@ Request handler for method data_cache::get_FDIR_GNSS_CMD_EXEC_STATUS_Data (ID = 0x000000A0)
static void data_cache_get_FDIR_GNSS_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_FDIR_GNSS_CMD_EXEC_STATUS_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_FDIR_GNSS_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_FDIR_GNSS_CMD_EXEC_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_fdir_gnss_cmd_exec_status_data(&sOutput_data);

        respResult = data_cache_get_FDIR_GNSS_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_FDIR_GNSS_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_FDIR_GNSS_CMD_EXEC_STATUS_Data (ID = 0x000000A0)

// @START@ Request handler for method data_cache::set_FDIR_GNSS_CMD_EXEC_STATUS_Data (ID = 0x000000A1)
static void data_cache_set_FDIR_GNSS_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_FDIR_GNSS_CMD_EXEC_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_FDIR_GNSS_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_FDIR_GNSS_CMD_EXEC_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_FDIR_GNSS_CMD_EXEC_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_FDIR_GNSS_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_FDIR_GNSS_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_FDIR_GNSS_CMD_EXEC_STATUS_Data (ID = 0x000000A1)

// @START@ Request handler for method data_cache::get_FDIR_SDR_CMD_EXEC_STATUS_Data (ID = 0x000000A2)
static void data_cache_get_FDIR_SDR_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_FDIR_SDR_CMD_EXEC_STATUS_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_FDIR_SDR_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_FDIR_SDR_CMD_EXEC_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_fdir_sdr_cmd_exec_status_data(&sOutput_data);

        respResult = data_cache_get_FDIR_SDR_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_FDIR_SDR_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_FDIR_SDR_CMD_EXEC_STATUS_Data (ID = 0x000000A2)

// @START@ Request handler for method data_cache::set_FDIR_SDR_CMD_EXEC_STATUS_Data (ID = 0x000000A3)
static void data_cache_set_FDIR_SDR_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_FDIR_SDR_CMD_EXEC_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_FDIR_SDR_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_FDIR_SDR_CMD_EXEC_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_FDIR_SDR_CMD_EXEC_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_FDIR_SDR_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_FDIR_SDR_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_FDIR_SDR_CMD_EXEC_STATUS_Data (ID = 0x000000A3)

// @START@ Request handler for method data_cache::get_FDIR_S_X_BAND_CMD_EXEC_STATUS_Data (ID = 0x000000A4)
static void data_cache_get_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_FDIR_S_X_BAND_CMD_EXEC_STATUS_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_FDIR_S_X_BAND_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_FDIR_S_X_BAND_CMD_EXEC_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_fdir_s_x_band_cmd_exec_status_data(&sOutput_data);

        respResult = data_cache_get_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_FDIR_S_X_BAND_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_FDIR_S_X_BAND_CMD_EXEC_STATUS_Data (ID = 0x000000A4)

// @START@ Request handler for method data_cache::set_FDIR_S_X_BAND_CMD_EXEC_STATUS_Data (ID = 0x000000A5)
static void data_cache_set_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_FDIR_S_X_BAND_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_FDIR_S_X_BAND_CMD_EXEC_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_FDIR_S_X_BAND_CMD_EXEC_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_FDIR_S_X_BAND_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_FDIR_S_X_BAND_CMD_EXEC_STATUS_Data (ID = 0x000000A5)

// @START@ Request handler for method data_cache::get_FDIR_THRUSTER_CMD_EXEC_STATUS_Data (ID = 0x000000A6)
static void data_cache_get_FDIR_THRUSTER_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_FDIR_THRUSTER_CMD_EXEC_STATUS_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_FDIR_THRUSTER_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_FDIR_THRUSTER_CMD_EXEC_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_fdir_thruster_cmd_exec_status_data(&sOutput_data);

        respResult = data_cache_get_FDIR_THRUSTER_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_FDIR_THRUSTER_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_FDIR_THRUSTER_CMD_EXEC_STATUS_Data (ID = 0x000000A6)

// @START@ Request handler for method data_cache::set_FDIR_THRUSTER_CMD_EXEC_STATUS_Data (ID = 0x000000A7)
static void data_cache_set_FDIR_THRUSTER_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_FDIR_THRUSTER_CMD_EXEC_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_FDIR_THRUSTER_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_FDIR_THRUSTER_CMD_EXEC_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_FDIR_THRUSTER_CMD_EXEC_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_FDIR_THRUSTER_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_FDIR_THRUSTER_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_FDIR_THRUSTER_CMD_EXEC_STATUS_Data (ID = 0x000000A7)

// @START@ Request handler for method data_cache::get_XBand_Fe_Data (ID = 0x000000A8)
static void data_cache_get_XBand_Fe_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_XBandFeTelemetry_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_XBand_Fe_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_XBand_Fe_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_xband_fe_data(&sOutput_data);

        respResult = data_cache_get_XBand_Fe_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_XBAND_FE_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_XBand_Fe_Data (ID = 0x000000A8)

// @START@ Request handler for method data_cache::set_XBand_Fe_Data (ID = 0x000000A9)
static void data_cache_set_XBand_Fe_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_XBand_Fe_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_XBand_Fe_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_XBand_Fe_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_XBAND_FE_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_XBand_Fe_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_XBAND_FE_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_XBand_Fe_Data (ID = 0x000000A9)

// @START@ Request handler for method data_cache::get_EpsOverallBatteryInfo_Data (ID = 0x000000AA)
static void data_cache_get_EpsOverallBatteryInfo_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_EpsOverallBatteryInfoType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EpsOverallBatteryInfo_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EpsOverallBatteryInfo_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_epsoverallbatteryinfo_data(&sOutput_data);

        respResult = data_cache_get_EpsOverallBatteryInfo_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPSOVERALLBATTERYINFO_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EpsOverallBatteryInfo_Data (ID = 0x000000AA)

// @START@ Request handler for method data_cache::set_EpsOverallBatteryInfo_Data (ID = 0x000000AB)
static void data_cache_set_EpsOverallBatteryInfo_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EpsOverallBatteryInfo_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EpsOverallBatteryInfo_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EpsOverallBatteryInfo_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPSOVERALLBATTERYINFO_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EpsOverallBatteryInfo_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPSOVERALLBATTERYINFO_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EpsOverallBatteryInfo_Data (ID = 0x000000AB)

// @START@ Request handler for method data_cache::get_PPS_Telemetry_Data (ID = 0x000000AC)
static void data_cache_get_PPS_Telemetry_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_PPS_Telemetry_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_PPS_Telemetry_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_PPS_Telemetry_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_pps_telemetry_data(&sOutput_data);

        respResult = data_cache_get_PPS_Telemetry_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_PPS_TELEMETRY_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_PPS_Telemetry_Data (ID = 0x000000AC)

// @START@ Request handler for method data_cache::set_PPS_Telemetry_Data (ID = 0x000000AD)
static void data_cache_set_PPS_Telemetry_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_PPS_Telemetry_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_PPS_Telemetry_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_PPS_Telemetry_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_PPS_TELEMETRY_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_PPS_Telemetry_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_PPS_TELEMETRY_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_PPS_Telemetry_Data (ID = 0x000000AD)

// @START@ Request handler for method data_cache::get_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_Data (ID = 0x000000AE)
static void data_cache_get_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_fdir_eps_iii_pdm_cmd_exec_status_data(&sOutput_data);

        respResult = data_cache_get_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_Data (ID = 0x000000AE)

// @START@ Request handler for method data_cache::set_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_Data (ID = 0x000000AF)
static void data_cache_set_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_Data (ID = 0x000000AF)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST0_BP_INFO_Data (ID = 0x000000B0)
static void data_cache_get_EPS2_BP_INST0_BP_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst0BatteryInfoType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST0_BP_INFO_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST0_BP_INFO_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst0_bp_info_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST0_BP_INFO_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST0_BP_INFO_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST0_BP_INFO_Data (ID = 0x000000B0)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST0_BP_INFO_Data (ID = 0x000000B1)
static void data_cache_set_EPS2_BP_INST0_BP_INFO_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST0_BP_INFO_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST0_BP_INFO_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST0_BP_INFO_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST0_BP_INFO_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST0_BP_INFO_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST0_BP_INFO_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST0_BP_INFO_Data (ID = 0x000000B1)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST0_DEVICE_HEALTH_INFO_Data (ID = 0x000000B2)
static void data_cache_get_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst0DeviceHealthInfoType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST0_DEVICE_HEALTH_INFO_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST0_DEVICE_HEALTH_INFO_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst0_device_health_info_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST0_DEVICE_HEALTH_INFO_Data (ID = 0x000000B2)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST0_DEVICE_HEALTH_INFO_Data (ID = 0x000000B3)
static void data_cache_set_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST0_DEVICE_HEALTH_INFO_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST0_DEVICE_HEALTH_INFO_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST0_DEVICE_HEALTH_INFO_Data (ID = 0x000000B3)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST0_INA_SENSOR1_Data (ID = 0x000000B4)
static void data_cache_get_EPS2_BP_INST0_INA_SENSOR1_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst0InaSensors1Type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST0_INA_SENSOR1_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST0_INA_SENSOR1_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst0_ina_sensor1_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST0_INA_SENSOR1_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST0_INA_SENSOR1_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST0_INA_SENSOR1_Data (ID = 0x000000B4)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST0_INA_SENSOR1_Data (ID = 0x000000B5)
static void data_cache_set_EPS2_BP_INST0_INA_SENSOR1_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST0_INA_SENSOR1_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST0_INA_SENSOR1_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST0_INA_SENSOR1_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST0_INA_SENSOR1_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST0_INA_SENSOR1_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST0_INA_SENSOR1_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST0_INA_SENSOR1_Data (ID = 0x000000B5)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST0_INA_SENSOR2_Data (ID = 0x000000B6)
static void data_cache_get_EPS2_BP_INST0_INA_SENSOR2_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst0InaSensors2Type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST0_INA_SENSOR2_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST0_INA_SENSOR2_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst0_ina_sensor2_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST0_INA_SENSOR2_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST0_INA_SENSOR2_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST0_INA_SENSOR2_Data (ID = 0x000000B6)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST0_INA_SENSOR2_Data (ID = 0x000000B7)
static void data_cache_set_EPS2_BP_INST0_INA_SENSOR2_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST0_INA_SENSOR2_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST0_INA_SENSOR2_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST0_INA_SENSOR2_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST0_INA_SENSOR2_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST0_INA_SENSOR2_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST0_INA_SENSOR2_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST0_INA_SENSOR2_Data (ID = 0x000000B7)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST0_BALANCER_INFO_Data (ID = 0x000000B8)
static void data_cache_get_EPS2_BP_INST0_BALANCER_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst0BalancerInfoType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST0_BALANCER_INFO_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST0_BALANCER_INFO_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst0_balancer_info_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST0_BALANCER_INFO_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST0_BALANCER_INFO_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST0_BALANCER_INFO_Data (ID = 0x000000B8)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST0_BALANCER_INFO_Data (ID = 0x000000B9)
static void data_cache_set_EPS2_BP_INST0_BALANCER_INFO_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST0_BALANCER_INFO_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST0_BALANCER_INFO_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST0_BALANCER_INFO_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST0_BALANCER_INFO_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST0_BALANCER_INFO_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST0_BALANCER_INFO_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST0_BALANCER_INFO_Data (ID = 0x000000B9)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST0_BALANCER_STATUS_Data (ID = 0x000000BA)
static void data_cache_get_EPS2_BP_INST0_BALANCER_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst0BalancerStatusType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST0_BALANCER_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST0_BALANCER_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst0_balancer_status_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST0_BALANCER_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST0_BALANCER_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST0_BALANCER_STATUS_Data (ID = 0x000000BA)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST0_BALANCER_STATUS_Data (ID = 0x000000BB)
static void data_cache_set_EPS2_BP_INST0_BALANCER_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST0_BALANCER_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST0_BALANCER_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST0_BALANCER_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST0_BALANCER_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST0_BALANCER_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST0_BALANCER_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST0_BALANCER_STATUS_Data (ID = 0x000000BB)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST0_BALANCER_CELLS_INFO_Data (ID = 0x000000BC)
static void data_cache_get_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst0BalancerCellsInfoType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST0_BALANCER_CELLS_INFO_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST0_BALANCER_CELLS_INFO_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst0_balancer_cells_info_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST0_BALANCER_CELLS_INFO_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST0_BALANCER_CELLS_INFO_Data (ID = 0x000000BC)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST0_BALANCER_CELLS_INFO_Data (ID = 0x000000BD)
static void data_cache_set_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST0_BALANCER_CELLS_INFO_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST0_BALANCER_CELLS_INFO_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST0_BALANCER_CELLS_INFO_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST0_BALANCER_CELLS_INFO_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST0_BALANCER_CELLS_INFO_Data (ID = 0x000000BD)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST0_CHARGER_XP_Data (ID = 0x000000BE)
static void data_cache_get_EPS2_BP_INST0_CHARGER_XP_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst0ChargerXpType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST0_CHARGER_XP_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST0_CHARGER_XP_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst0_charger_xp_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST0_CHARGER_XP_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST0_CHARGER_XP_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST0_CHARGER_XP_Data (ID = 0x000000BE)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST0_CHARGER_XP_Data (ID = 0x000000BF)
static void data_cache_set_EPS2_BP_INST0_CHARGER_XP_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST0_CHARGER_XP_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST0_CHARGER_XP_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST0_CHARGER_XP_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST0_CHARGER_XP_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST0_CHARGER_XP_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST0_CHARGER_XP_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST0_CHARGER_XP_Data (ID = 0x000000BF)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST0_CHARGER_XR_Data (ID = 0x000000C0)
static void data_cache_get_EPS2_BP_INST0_CHARGER_XR_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst0ChargerXrType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST0_CHARGER_XR_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST0_CHARGER_XR_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst0_charger_xr_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST0_CHARGER_XR_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST0_CHARGER_XR_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST0_CHARGER_XR_Data (ID = 0x000000C0)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST0_CHARGER_XR_Data (ID = 0x000000C1)
static void data_cache_set_EPS2_BP_INST0_CHARGER_XR_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST0_CHARGER_XR_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST0_CHARGER_XR_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST0_CHARGER_XR_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST0_CHARGER_XR_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST0_CHARGER_XR_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST0_CHARGER_XR_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST0_CHARGER_XR_Data (ID = 0x000000C1)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST0_CHARGER_YP_Data (ID = 0x000000C2)
static void data_cache_get_EPS2_BP_INST0_CHARGER_YP_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst0ChargerYpType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST0_CHARGER_YP_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST0_CHARGER_YP_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst0_charger_yp_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST0_CHARGER_YP_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST0_CHARGER_YP_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST0_CHARGER_YP_Data (ID = 0x000000C2)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST0_CHARGER_YP_Data (ID = 0x000000C3)
static void data_cache_set_EPS2_BP_INST0_CHARGER_YP_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST0_CHARGER_YP_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST0_CHARGER_YP_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST0_CHARGER_YP_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST0_CHARGER_YP_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST0_CHARGER_YP_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST0_CHARGER_YP_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST0_CHARGER_YP_Data (ID = 0x000000C3)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST0_CHARGER_YR_Data (ID = 0x000000C4)
static void data_cache_get_EPS2_BP_INST0_CHARGER_YR_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst0ChargerYrType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST0_CHARGER_YR_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST0_CHARGER_YR_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst0_charger_yr_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST0_CHARGER_YR_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST0_CHARGER_YR_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST0_CHARGER_YR_Data (ID = 0x000000C4)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST0_CHARGER_YR_Data (ID = 0x000000C5)
static void data_cache_set_EPS2_BP_INST0_CHARGER_YR_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST0_CHARGER_YR_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST0_CHARGER_YR_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST0_CHARGER_YR_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST0_CHARGER_YR_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST0_CHARGER_YR_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST0_CHARGER_YR_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST0_CHARGER_YR_Data (ID = 0x000000C5)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST0_CHARGER_ZP_Data (ID = 0x000000C6)
static void data_cache_get_EPS2_BP_INST0_CHARGER_ZP_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst0ChargerZpType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST0_CHARGER_ZP_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST0_CHARGER_ZP_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst0_charger_zp_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST0_CHARGER_ZP_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST0_CHARGER_ZP_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST0_CHARGER_ZP_Data (ID = 0x000000C6)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST0_CHARGER_ZP_Data (ID = 0x000000C7)
static void data_cache_set_EPS2_BP_INST0_CHARGER_ZP_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST0_CHARGER_ZP_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST0_CHARGER_ZP_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST0_CHARGER_ZP_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST0_CHARGER_ZP_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST0_CHARGER_ZP_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST0_CHARGER_ZP_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST0_CHARGER_ZP_Data (ID = 0x000000C7)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST0_CHARGER_ZR_Data (ID = 0x000000C8)
static void data_cache_get_EPS2_BP_INST0_CHARGER_ZR_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst0ChargerZrType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST0_CHARGER_ZR_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST0_CHARGER_ZR_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst0_charger_zr_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST0_CHARGER_ZR_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST0_CHARGER_ZR_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST0_CHARGER_ZR_Data (ID = 0x000000C8)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST0_CHARGER_ZR_Data (ID = 0x000000C9)
static void data_cache_set_EPS2_BP_INST0_CHARGER_ZR_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST0_CHARGER_ZR_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST0_CHARGER_ZR_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST0_CHARGER_ZR_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST0_CHARGER_ZR_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST0_CHARGER_ZR_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST0_CHARGER_ZR_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST0_CHARGER_ZR_Data (ID = 0x000000C9)

// @START@ Request handler for method data_cache::get_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_Data (ID = 0x000000CA)
static void data_cache_get_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst0_FDIR_CMD_EXEC_STATUS_type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_fdir_eps_ii_bp_inst0_cmd_exec_status_data(&sOutput_data);

        respResult = data_cache_get_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_Data (ID = 0x000000CA)

// @START@ Request handler for method data_cache::set_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_Data (ID = 0x000000CB)
static void data_cache_set_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_Data (ID = 0x000000CB)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST1_BP_INFO_Data (ID = 0x000000CC)
static void data_cache_get_EPS2_BP_INST1_BP_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst1BatteryInfoType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST1_BP_INFO_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST1_BP_INFO_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst1_bp_info_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST1_BP_INFO_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST1_BP_INFO_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST1_BP_INFO_Data (ID = 0x000000CC)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST1_BP_INFO_Data (ID = 0x000000CD)
static void data_cache_set_EPS2_BP_INST1_BP_INFO_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST1_BP_INFO_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST1_BP_INFO_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST1_BP_INFO_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST1_BP_INFO_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST1_BP_INFO_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST1_BP_INFO_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST1_BP_INFO_Data (ID = 0x000000CD)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST1_DEVICE_HEALTH_INFO_Data (ID = 0x000000CE)
static void data_cache_get_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst1DeviceHealthInfoType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST1_DEVICE_HEALTH_INFO_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST1_DEVICE_HEALTH_INFO_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst1_device_health_info_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST1_DEVICE_HEALTH_INFO_Data (ID = 0x000000CE)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST1_DEVICE_HEALTH_INFO_Data (ID = 0x000000CF)
static void data_cache_set_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST1_DEVICE_HEALTH_INFO_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST1_DEVICE_HEALTH_INFO_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST1_DEVICE_HEALTH_INFO_Data (ID = 0x000000CF)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST1_INA_SENSOR1_Data (ID = 0x000000D0)
static void data_cache_get_EPS2_BP_INST1_INA_SENSOR1_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst1InaSensors1Type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST1_INA_SENSOR1_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST1_INA_SENSOR1_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst1_ina_sensor1_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST1_INA_SENSOR1_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST1_INA_SENSOR1_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST1_INA_SENSOR1_Data (ID = 0x000000D0)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST1_INA_SENSOR1_Data (ID = 0x000000D1)
static void data_cache_set_EPS2_BP_INST1_INA_SENSOR1_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST1_INA_SENSOR1_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST1_INA_SENSOR1_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST1_INA_SENSOR1_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST1_INA_SENSOR1_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST1_INA_SENSOR1_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST1_INA_SENSOR1_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST1_INA_SENSOR1_Data (ID = 0x000000D1)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST1_INA_SENSOR2_Data (ID = 0x000000D2)
static void data_cache_get_EPS2_BP_INST1_INA_SENSOR2_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst1InaSensors2Type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST1_INA_SENSOR2_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST1_INA_SENSOR2_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst1_ina_sensor2_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST1_INA_SENSOR2_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST1_INA_SENSOR2_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST1_INA_SENSOR2_Data (ID = 0x000000D2)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST1_INA_SENSOR2_Data (ID = 0x000000D3)
static void data_cache_set_EPS2_BP_INST1_INA_SENSOR2_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST1_INA_SENSOR2_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST1_INA_SENSOR2_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST1_INA_SENSOR2_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST1_INA_SENSOR2_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST1_INA_SENSOR2_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST1_INA_SENSOR2_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST1_INA_SENSOR2_Data (ID = 0x000000D3)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST1_BALANCER_INFO_Data (ID = 0x000000D4)
static void data_cache_get_EPS2_BP_INST1_BALANCER_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst1BalancerInfoType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST1_BALANCER_INFO_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST1_BALANCER_INFO_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst1_balancer_info_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST1_BALANCER_INFO_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST1_BALANCER_INFO_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST1_BALANCER_INFO_Data (ID = 0x000000D4)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST1_BALANCER_INFO_Data (ID = 0x000000D5)
static void data_cache_set_EPS2_BP_INST1_BALANCER_INFO_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST1_BALANCER_INFO_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST1_BALANCER_INFO_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST1_BALANCER_INFO_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST1_BALANCER_INFO_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST1_BALANCER_INFO_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST1_BALANCER_INFO_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST1_BALANCER_INFO_Data (ID = 0x000000D5)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST1_BALANCER_STATUS_Data (ID = 0x000000D6)
static void data_cache_get_EPS2_BP_INST1_BALANCER_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst1BalancerStatusType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST1_BALANCER_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST1_BALANCER_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst1_balancer_status_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST1_BALANCER_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST1_BALANCER_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST1_BALANCER_STATUS_Data (ID = 0x000000D6)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST1_BALANCER_STATUS_Data (ID = 0x000000D7)
static void data_cache_set_EPS2_BP_INST1_BALANCER_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST1_BALANCER_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST1_BALANCER_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST1_BALANCER_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST1_BALANCER_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST1_BALANCER_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST1_BALANCER_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST1_BALANCER_STATUS_Data (ID = 0x000000D7)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST1_BALANCER_CELLS_INFO_Data (ID = 0x000000D8)
static void data_cache_get_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst1BalancerCellsInfoType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST1_BALANCER_CELLS_INFO_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST1_BALANCER_CELLS_INFO_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst1_balancer_cells_info_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST1_BALANCER_CELLS_INFO_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST1_BALANCER_CELLS_INFO_Data (ID = 0x000000D8)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST1_BALANCER_CELLS_INFO_Data (ID = 0x000000D9)
static void data_cache_set_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST1_BALANCER_CELLS_INFO_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST1_BALANCER_CELLS_INFO_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST1_BALANCER_CELLS_INFO_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST1_BALANCER_CELLS_INFO_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST1_BALANCER_CELLS_INFO_Data (ID = 0x000000D9)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST1_CHARGER_XP_Data (ID = 0x000000DA)
static void data_cache_get_EPS2_BP_INST1_CHARGER_XP_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst1ChargerXpType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST1_CHARGER_XP_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST1_CHARGER_XP_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst1_charger_xp_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST1_CHARGER_XP_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST1_CHARGER_XP_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST1_CHARGER_XP_Data (ID = 0x000000DA)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST1_CHARGER_XP_Data (ID = 0x000000DB)
static void data_cache_set_EPS2_BP_INST1_CHARGER_XP_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST1_CHARGER_XP_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST1_CHARGER_XP_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST1_CHARGER_XP_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST1_CHARGER_XP_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST1_CHARGER_XP_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST1_CHARGER_XP_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST1_CHARGER_XP_Data (ID = 0x000000DB)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST1_CHARGER_XR_Data (ID = 0x000000DC)
static void data_cache_get_EPS2_BP_INST1_CHARGER_XR_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst1ChargerXrType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST1_CHARGER_XR_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST1_CHARGER_XR_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst1_charger_xr_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST1_CHARGER_XR_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST1_CHARGER_XR_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST1_CHARGER_XR_Data (ID = 0x000000DC)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST1_CHARGER_XR_Data (ID = 0x000000DD)
static void data_cache_set_EPS2_BP_INST1_CHARGER_XR_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST1_CHARGER_XR_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST1_CHARGER_XR_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST1_CHARGER_XR_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST1_CHARGER_XR_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST1_CHARGER_XR_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST1_CHARGER_XR_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST1_CHARGER_XR_Data (ID = 0x000000DD)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST1_CHARGER_YP_Data (ID = 0x000000DE)
static void data_cache_get_EPS2_BP_INST1_CHARGER_YP_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst1ChargerYpType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST1_CHARGER_YP_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST1_CHARGER_YP_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst1_charger_yp_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST1_CHARGER_YP_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST1_CHARGER_YP_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST1_CHARGER_YP_Data (ID = 0x000000DE)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST1_CHARGER_YP_Data (ID = 0x000000DF)
static void data_cache_set_EPS2_BP_INST1_CHARGER_YP_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST1_CHARGER_YP_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST1_CHARGER_YP_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST1_CHARGER_YP_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST1_CHARGER_YP_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST1_CHARGER_YP_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST1_CHARGER_YP_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST1_CHARGER_YP_Data (ID = 0x000000DF)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST1_CHARGER_YR_Data (ID = 0x000000E0)
static void data_cache_get_EPS2_BP_INST1_CHARGER_YR_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst1ChargerYrType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST1_CHARGER_YR_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST1_CHARGER_YR_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst1_charger_yr_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST1_CHARGER_YR_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST1_CHARGER_YR_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST1_CHARGER_YR_Data (ID = 0x000000E0)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST1_CHARGER_YR_Data (ID = 0x000000E1)
static void data_cache_set_EPS2_BP_INST1_CHARGER_YR_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST1_CHARGER_YR_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST1_CHARGER_YR_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST1_CHARGER_YR_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST1_CHARGER_YR_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST1_CHARGER_YR_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST1_CHARGER_YR_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST1_CHARGER_YR_Data (ID = 0x000000E1)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST1_CHARGER_ZP_Data (ID = 0x000000E2)
static void data_cache_get_EPS2_BP_INST1_CHARGER_ZP_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst1ChargerZpType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST1_CHARGER_ZP_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST1_CHARGER_ZP_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst1_charger_zp_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST1_CHARGER_ZP_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST1_CHARGER_ZP_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST1_CHARGER_ZP_Data (ID = 0x000000E2)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST1_CHARGER_ZP_Data (ID = 0x000000E3)
static void data_cache_set_EPS2_BP_INST1_CHARGER_ZP_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST1_CHARGER_ZP_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST1_CHARGER_ZP_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST1_CHARGER_ZP_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST1_CHARGER_ZP_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST1_CHARGER_ZP_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST1_CHARGER_ZP_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST1_CHARGER_ZP_Data (ID = 0x000000E3)

// @START@ Request handler for method data_cache::get_EPS2_BP_INST1_CHARGER_ZR_Data (ID = 0x000000E4)
static void data_cache_get_EPS2_BP_INST1_CHARGER_ZR_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst1ChargerZrType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS2_BP_INST1_CHARGER_ZR_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS2_BP_INST1_CHARGER_ZR_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps2_bp_inst1_charger_zr_data(&sOutput_data);

        respResult = data_cache_get_EPS2_BP_INST1_CHARGER_ZR_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS2_BP_INST1_CHARGER_ZR_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS2_BP_INST1_CHARGER_ZR_Data (ID = 0x000000E4)

// @START@ Request handler for method data_cache::set_EPS2_BP_INST1_CHARGER_ZR_Data (ID = 0x000000E5)
static void data_cache_set_EPS2_BP_INST1_CHARGER_ZR_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS2_BP_INST1_CHARGER_ZR_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS2_BP_INST1_CHARGER_ZR_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS2_BP_INST1_CHARGER_ZR_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS2_BP_INST1_CHARGER_ZR_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS2_BP_INST1_CHARGER_ZR_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS2_BP_INST1_CHARGER_ZR_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS2_BP_INST1_CHARGER_ZR_Data (ID = 0x000000E5)

// @START@ Request handler for method data_cache::get_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_Data (ID = 0x000000E6)
static void data_cache_get_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps2Inst1_FDIR_CMD_EXEC_STATUS_type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_fdir_eps_ii_bp_inst1_cmd_exec_status_data(&sOutput_data);

        respResult = data_cache_get_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_Data (ID = 0x000000E6)

// @START@ Request handler for method data_cache::set_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_Data (ID = 0x000000E7)
static void data_cache_set_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_Data (ID = 0x000000E7)

// @START@ Request handler for method data_cache::get_EPS3_BP_INST0_uptime_in_seconds (ID = 0x000000E8)
static void data_cache_get_EPS3_BP_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3Inst0_UpTimeInSecondsType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_BP_INST0_uptime_in_seconds@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_BP_INST0_uptime_in_seconds@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_bp_inst0_uptime_in_seconds(&sOutput_data);

        respResult = data_cache_get_EPS3_BP_INST0_uptime_in_secondsResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_BP_INST0_UPTIME_IN_SECONDS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_BP_INST0_uptime_in_seconds (ID = 0x000000E8)

// @START@ Request handler for method data_cache::set_EPS3_BP_INST0_uptime_in_seconds (ID = 0x000000E9)
static void data_cache_set_EPS3_BP_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_BP_INST0_uptime_in_secondsRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_BP_INST0_uptime_in_seconds@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_BP_INST0_uptime_in_seconds@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_BP_INST0_UPTIME_IN_SECONDS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_BP_INST0_uptime_in_secondsResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_BP_INST0_UPTIME_IN_SECONDS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_BP_INST0_uptime_in_seconds (ID = 0x000000E9)

// @START@ Request handler for method data_cache::get_EPS3_BP_INST0common (ID = 0x000000EA)
static void data_cache_get_EPS3_BP_INST0commonRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3Inst0CommonMeasurementType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_BP_INST0common@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_BP_INST0common@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_bp_inst0common(&sOutput_data);

        respResult = data_cache_get_EPS3_BP_INST0commonResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_BP_INST0COMMON_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_BP_INST0common (ID = 0x000000EA)

// @START@ Request handler for method data_cache::set_EPS3_BP_INST0common (ID = 0x000000EB)
static void data_cache_set_EPS3_BP_INST0commonRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_BP_INST0commonRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_BP_INST0common@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_BP_INST0common@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_BP_INST0COMMON, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_BP_INST0commonResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_BP_INST0COMMON_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_BP_INST0common (ID = 0x000000EB)

// @START@ Request handler for method data_cache::get_EPS3_BP_INST0hib_mode_status (ID = 0x000000EC)
static void data_cache_get_EPS3_BP_INST0hib_mode_statusRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3Inst0HIBModeStatusType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_BP_INST0hib_mode_status@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_BP_INST0hib_mode_status@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_bp_inst0hib_mode_status(&sOutput_data);

        respResult = data_cache_get_EPS3_BP_INST0hib_mode_statusResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_BP_INST0HIB_MODE_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_BP_INST0hib_mode_status (ID = 0x000000EC)

// @START@ Request handler for method data_cache::set_EPS3_BP_INST0hib_mode_status (ID = 0x000000ED)
static void data_cache_set_EPS3_BP_INST0hib_mode_statusRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_BP_INST0hib_mode_statusRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_BP_INST0hib_mode_status@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_BP_INST0hib_mode_status@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_BP_INST0HIB_MODE_STATUS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_BP_INST0hib_mode_statusResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_BP_INST0HIB_MODE_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_BP_INST0hib_mode_status (ID = 0x000000ED)

// @START@ Request handler for method data_cache::get_EPS3_BP_INST0measurements (ID = 0x000000EE)
static void data_cache_get_EPS3_BP_INST0measurementsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3Inst0MeasurementsType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_BP_INST0measurements@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_BP_INST0measurements@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_bp_inst0measurements(&sOutput_data);

        respResult = data_cache_get_EPS3_BP_INST0measurementsResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_BP_INST0MEASUREMENTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_BP_INST0measurements (ID = 0x000000EE)

// @START@ Request handler for method data_cache::set_EPS3_BP_INST0measurements (ID = 0x000000EF)
static void data_cache_set_EPS3_BP_INST0measurementsRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_BP_INST0measurementsRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_BP_INST0measurements@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_BP_INST0measurements@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_BP_INST0MEASUREMENTS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_BP_INST0measurementsResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_BP_INST0MEASUREMENTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_BP_INST0measurements (ID = 0x000000EF)

// @START@ Request handler for method data_cache::get_EPS3_BP_INST0discharging_state (ID = 0x000000F0)
static void data_cache_get_EPS3_BP_INST0discharging_stateRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3Inst0DischargeStateType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_BP_INST0discharging_state@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_BP_INST0discharging_state@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_bp_inst0discharging_state(&sOutput_data);

        respResult = data_cache_get_EPS3_BP_INST0discharging_stateResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_BP_INST0DISCHARGING_STATE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_BP_INST0discharging_state (ID = 0x000000F0)

// @START@ Request handler for method data_cache::set_EPS3_BP_INST0discharging_state (ID = 0x000000F1)
static void data_cache_set_EPS3_BP_INST0discharging_stateRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_BP_INST0discharging_stateRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_BP_INST0discharging_state@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_BP_INST0discharging_state@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_BP_INST0DISCHARGING_STATE, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_BP_INST0discharging_stateResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_BP_INST0DISCHARGING_STATE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_BP_INST0discharging_state (ID = 0x000000F1)

// @START@ Request handler for method data_cache::get_EPS3_BP_INST0charge_status (ID = 0x000000F2)
static void data_cache_get_EPS3_BP_INST0charge_statusRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3Inst0ChargeOnStatusType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_BP_INST0charge_status@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_BP_INST0charge_status@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_bp_inst0charge_status(&sOutput_data);

        respResult = data_cache_get_EPS3_BP_INST0charge_statusResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_BP_INST0CHARGE_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_BP_INST0charge_status (ID = 0x000000F2)

// @START@ Request handler for method data_cache::set_EPS3_BP_INST0charge_status (ID = 0x000000F3)
static void data_cache_set_EPS3_BP_INST0charge_statusRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_BP_INST0charge_statusRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_BP_INST0charge_status@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_BP_INST0charge_status@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_BP_INST0CHARGE_STATUS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_BP_INST0charge_statusResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_BP_INST0CHARGE_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_BP_INST0charge_status (ID = 0x000000F3)

// @START@ Request handler for method data_cache::get_EPS3_BP_INST0balancers_status (ID = 0x000000F4)
static void data_cache_get_EPS3_BP_INST0balancers_statusRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3Inst0BalancersStatusType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_BP_INST0balancers_status@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_BP_INST0balancers_status@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_bp_inst0balancers_status(&sOutput_data);

        respResult = data_cache_get_EPS3_BP_INST0balancers_statusResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_BP_INST0BALANCERS_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_BP_INST0balancers_status (ID = 0x000000F4)

// @START@ Request handler for method data_cache::set_EPS3_BP_INST0balancers_status (ID = 0x000000F5)
static void data_cache_set_EPS3_BP_INST0balancers_statusRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_BP_INST0balancers_statusRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_BP_INST0balancers_status@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_BP_INST0balancers_status@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_BP_INST0BALANCERS_STATUS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_BP_INST0balancers_statusResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_BP_INST0BALANCERS_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_BP_INST0balancers_status (ID = 0x000000F5)

// @START@ Request handler for method data_cache::get_EPS3_BP_INST0battery_cells_status (ID = 0x000000F6)
static void data_cache_get_EPS3_BP_INST0battery_cells_statusRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3Inst0BatteryCellsStatusType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_BP_INST0battery_cells_status@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_BP_INST0battery_cells_status@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_bp_inst0battery_cells_status(&sOutput_data);

        respResult = data_cache_get_EPS3_BP_INST0battery_cells_statusResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_BP_INST0BATTERY_CELLS_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_BP_INST0battery_cells_status (ID = 0x000000F6)

// @START@ Request handler for method data_cache::set_EPS3_BP_INST0battery_cells_status (ID = 0x000000F7)
static void data_cache_set_EPS3_BP_INST0battery_cells_statusRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_BP_INST0battery_cells_statusRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_BP_INST0battery_cells_status@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_BP_INST0battery_cells_status@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_BP_INST0BATTERY_CELLS_STATUS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_BP_INST0battery_cells_statusResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_BP_INST0BATTERY_CELLS_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_BP_INST0battery_cells_status (ID = 0x000000F7)

// @START@ Request handler for method data_cache::get_EPS3_BP_INST0heaters_status (ID = 0x000000F8)
static void data_cache_get_EPS3_BP_INST0heaters_statusRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3Inst0HeatersStatusType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_BP_INST0heaters_status@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_BP_INST0heaters_status@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_bp_inst0heaters_status(&sOutput_data);

        respResult = data_cache_get_EPS3_BP_INST0heaters_statusResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_BP_INST0HEATERS_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_BP_INST0heaters_status (ID = 0x000000F8)

// @START@ Request handler for method data_cache::set_EPS3_BP_INST0heaters_status (ID = 0x000000F9)
static void data_cache_set_EPS3_BP_INST0heaters_statusRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_BP_INST0heaters_statusRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_BP_INST0heaters_status@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_BP_INST0heaters_status@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_BP_INST0HEATERS_STATUS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_BP_INST0heaters_statusResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_BP_INST0HEATERS_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_BP_INST0heaters_status (ID = 0x000000F9)

// @START@ Request handler for method data_cache::get_EPS3_BP_INST0_CMD_EXEC_STATUS_Data (ID = 0x000000FA)
static void data_cache_get_EPS3_BP_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3Inst0_FDIR_CMD_EXEC_STATUS_type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_BP_INST0_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_BP_INST0_CMD_EXEC_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_bp_inst0_cmd_exec_status_data(&sOutput_data);

        respResult = data_cache_get_EPS3_BP_INST0_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_BP_INST0_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_BP_INST0_CMD_EXEC_STATUS_Data (ID = 0x000000FA)

// @START@ Request handler for method data_cache::set_EPS3_BP_INST0_CMD_EXEC_STATUS_Data (ID = 0x000000FB)
static void data_cache_set_EPS3_BP_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_BP_INST0_CMD_EXEC_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_BP_INST0_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_BP_INST0_CMD_EXEC_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_BP_INST0_CMD_EXEC_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_BP_INST0_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_BP_INST0_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_BP_INST0_CMD_EXEC_STATUS_Data (ID = 0x000000FB)

// @START@ Request handler for method data_cache::get_dumb_data (ID = 0x000000FC)
static void data_cache_get_dumb_dataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_VoltAmps_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_dumb_data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_dumb_data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_dumb_data(&sOutput_data);

        respResult = data_cache_get_dumb_dataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_DUMB_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_dumb_data (ID = 0x000000FC)

// @START@ Request handler for method data_cache::set_dumb_data (ID = 0x000000FD)
static void data_cache_set_dumb_dataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_dumb_dataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_dumb_data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_dumb_data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_DUMB_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_dumb_dataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_DUMB_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_dumb_data (ID = 0x000000FD)

// @START@ Request handler for method data_cache::get_dumb_data1 (ID = 0x000000FE)
static void data_cache_get_dumb_data1RequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_VoltAllAmps_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_dumb_data1@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_dumb_data1@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_dumb_data1(&sOutput_data);

        respResult = data_cache_get_dumb_data1Resp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_DUMB_DATA1_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_dumb_data1 (ID = 0x000000FE)

// @START@ Request handler for method data_cache::set_dumb_data1 (ID = 0x000000FF)
static void data_cache_set_dumb_data1RequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_dumb_data1RequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_dumb_data1@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_dumb_data1@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_DUMB_DATA1, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_dumb_data1Resp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_DUMB_DATA1_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_dumb_data1 (ID = 0x000000FF)

// @START@ Request handler for method data_cache::get_dumb_data3 (ID = 0x00000100)
static void data_cache_get_dumb_data3RequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_MpptState_str_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_dumb_data3@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_dumb_data3@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_dumb_data3(&sOutput_data);

        respResult = data_cache_get_dumb_data3Resp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_DUMB_DATA3_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_dumb_data3 (ID = 0x00000100)

// @START@ Request handler for method data_cache::set_dumb_data3 (ID = 0x00000101)
static void data_cache_set_dumb_data3RequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_dumb_data3RequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_dumb_data3@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_dumb_data3@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_DUMB_DATA3, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_dumb_data3Resp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_DUMB_DATA3_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_dumb_data3 (ID = 0x00000101)

// @START@ Request handler for method data_cache::get_dumb_data4 (ID = 0x00000102)
static void data_cache_get_dumb_data4RequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_ReadEnDftStatus_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_dumb_data4@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_dumb_data4@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_dumb_data4(&sOutput_data);

        respResult = data_cache_get_dumb_data4Resp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_DUMB_DATA4_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_dumb_data4 (ID = 0x00000102)

// @START@ Request handler for method data_cache::set_dumb_data4 (ID = 0x00000103)
static void data_cache_set_dumb_data4RequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_dumb_data4RequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_dumb_data4@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_dumb_data4@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_DUMB_DATA4, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_dumb_data4Resp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_DUMB_DATA4_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_dumb_data4 (ID = 0x00000103)

// @START@ Request handler for method data_cache::get_dumb_data5 (ID = 0x00000104)
static void data_cache_get_dumb_data5RequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_OnOffStatus_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_dumb_data5@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_dumb_data5@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_dumb_data5(&sOutput_data);

        respResult = data_cache_get_dumb_data5Resp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_DUMB_DATA5_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_dumb_data5 (ID = 0x00000104)

// @START@ Request handler for method data_cache::set_dumb_data5 (ID = 0x00000105)
static void data_cache_set_dumb_data5RequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_dumb_data5RequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_dumb_data5@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_dumb_data5@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_DUMB_DATA5, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_dumb_data5Resp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_DUMB_DATA5_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_dumb_data5 (ID = 0x00000105)

// @START@ Request handler for method data_cache::get_dumb_data6 (ID = 0x00000106)
static void data_cache_get_dumb_data6RequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_ReadLvlState_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_dumb_data6@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_dumb_data6@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_dumb_data6(&sOutput_data);

        respResult = data_cache_get_dumb_data6Resp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_DUMB_DATA6_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_dumb_data6 (ID = 0x00000106)

// @START@ Request handler for method data_cache::set_dumb_data6 (ID = 0x00000107)
static void data_cache_set_dumb_data6RequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_dumb_data6RequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_dumb_data6@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_dumb_data6@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_DUMB_DATA6, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_dumb_data6Resp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_DUMB_DATA6_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_dumb_data6 (ID = 0x00000107)

// @START@ Request handler for method data_cache::get_EPS3_PDM_A_INST0_uptime_in_seconds (ID = 0x00000108)
static void data_cache_get_EPS3_PDM_A_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_PDM_A_Inst0_UpTimeInSecondsType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_PDM_A_INST0_uptime_in_seconds@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_PDM_A_INST0_uptime_in_seconds@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_pdm_a_inst0_uptime_in_seconds(&sOutput_data);

        respResult = data_cache_get_EPS3_PDM_A_INST0_uptime_in_secondsResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_PDM_A_INST0_UPTIME_IN_SECONDS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_PDM_A_INST0_uptime_in_seconds (ID = 0x00000108)

// @START@ Request handler for method data_cache::set_EPS3_PDM_A_INST0_uptime_in_seconds (ID = 0x00000109)
static void data_cache_set_EPS3_PDM_A_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_PDM_A_INST0_uptime_in_secondsRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_PDM_A_INST0_uptime_in_seconds@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_PDM_A_INST0_uptime_in_seconds@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_PDM_A_INST0_UPTIME_IN_SECONDS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_PDM_A_INST0_uptime_in_secondsResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_PDM_A_INST0_UPTIME_IN_SECONDS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_PDM_A_INST0_uptime_in_seconds (ID = 0x00000109)

// @START@ Request handler for method data_cache::get_EPS3_PDM_A_INST0_common (ID = 0x0000010A)
static void data_cache_get_EPS3_PDM_A_INST0_commonRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_PDM_A_Inst0_CommonMesurementsType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_PDM_A_INST0_common@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_PDM_A_INST0_common@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_pdm_a_inst0_common(&sOutput_data);

        respResult = data_cache_get_EPS3_PDM_A_INST0_commonResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_PDM_A_INST0_COMMON_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_PDM_A_INST0_common (ID = 0x0000010A)

// @START@ Request handler for method data_cache::set_EPS3_PDM_A_INST0_common (ID = 0x0000010B)
static void data_cache_set_EPS3_PDM_A_INST0_commonRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_PDM_A_INST0_commonRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_PDM_A_INST0_common@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_PDM_A_INST0_common@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_PDM_A_INST0_COMMON, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_PDM_A_INST0_commonResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_PDM_A_INST0_COMMON_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_PDM_A_INST0_common (ID = 0x0000010B)

// @START@ Request handler for method data_cache::get_EPS3_PDM_A_INST0_hib_mode (ID = 0x0000010C)
static void data_cache_get_EPS3_PDM_A_INST0_hib_modeRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_PDM_A_Inst0_HibModeType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_PDM_A_INST0_hib_mode@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_PDM_A_INST0_hib_mode@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_pdm_a_inst0_hib_mode(&sOutput_data);

        respResult = data_cache_get_EPS3_PDM_A_INST0_hib_modeResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_PDM_A_INST0_HIB_MODE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_PDM_A_INST0_hib_mode (ID = 0x0000010C)

// @START@ Request handler for method data_cache::set_EPS3_PDM_A_INST0_hib_mode (ID = 0x0000010D)
static void data_cache_set_EPS3_PDM_A_INST0_hib_modeRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_PDM_A_INST0_hib_modeRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_PDM_A_INST0_hib_mode@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_PDM_A_INST0_hib_mode@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_PDM_A_INST0_HIB_MODE, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_PDM_A_INST0_hib_modeResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_PDM_A_INST0_HIB_MODE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_PDM_A_INST0_hib_mode (ID = 0x0000010D)

// @START@ Request handler for method data_cache::get_EPS3_PDM_A_INST0_general_outputs (ID = 0x0000010E)
static void data_cache_get_EPS3_PDM_A_INST0_general_outputsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_PDM_A_Inst0_OutputsStatusType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_PDM_A_INST0_general_outputs@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_PDM_A_INST0_general_outputs@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_pdm_a_inst0_general_outputs(&sOutput_data);

        respResult = data_cache_get_EPS3_PDM_A_INST0_general_outputsResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_PDM_A_INST0_GENERAL_OUTPUTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_PDM_A_INST0_general_outputs (ID = 0x0000010E)

// @START@ Request handler for method data_cache::set_EPS3_PDM_A_INST0_general_outputs (ID = 0x0000010F)
static void data_cache_set_EPS3_PDM_A_INST0_general_outputsRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_PDM_A_INST0_general_outputsRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_PDM_A_INST0_general_outputs@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_PDM_A_INST0_general_outputs@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_PDM_A_INST0_GENERAL_OUTPUTS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_PDM_A_INST0_general_outputsResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_PDM_A_INST0_GENERAL_OUTPUTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_PDM_A_INST0_general_outputs (ID = 0x0000010F)

// @START@ Request handler for method data_cache::get_EPS3_PDM_A_INST0_general_faults (ID = 0x00000110)
static void data_cache_get_EPS3_PDM_A_INST0_general_faultsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_PDM_A_Inst0_FaultsStatusType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_PDM_A_INST0_general_faults@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_PDM_A_INST0_general_faults@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_pdm_a_inst0_general_faults(&sOutput_data);

        respResult = data_cache_get_EPS3_PDM_A_INST0_general_faultsResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_PDM_A_INST0_GENERAL_FAULTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_PDM_A_INST0_general_faults (ID = 0x00000110)

// @START@ Request handler for method data_cache::set_EPS3_PDM_A_INST0_general_faults (ID = 0x00000111)
static void data_cache_set_EPS3_PDM_A_INST0_general_faultsRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_PDM_A_INST0_general_faultsRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_PDM_A_INST0_general_faults@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_PDM_A_INST0_general_faults@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_PDM_A_INST0_GENERAL_FAULTS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_PDM_A_INST0_general_faultsResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_PDM_A_INST0_GENERAL_FAULTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_PDM_A_INST0_general_faults (ID = 0x00000111)

// @START@ Request handler for method data_cache::get_EPS3_PDM_A_INST0_all_measurements (ID = 0x00000112)
static void data_cache_get_EPS3_PDM_A_INST0_all_measurementsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_PDM_A_Inst0_VoltAmpsMeasurementsType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_PDM_A_INST0_all_measurements@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_PDM_A_INST0_all_measurements@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_pdm_a_inst0_all_measurements(&sOutput_data);

        respResult = data_cache_get_EPS3_PDM_A_INST0_all_measurementsResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_PDM_A_INST0_ALL_MEASUREMENTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_PDM_A_INST0_all_measurements (ID = 0x00000112)

// @START@ Request handler for method data_cache::set_EPS3_PDM_A_INST0_all_measurements (ID = 0x00000113)
static void data_cache_set_EPS3_PDM_A_INST0_all_measurementsRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_PDM_A_INST0_all_measurementsRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_PDM_A_INST0_all_measurements@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_PDM_A_INST0_all_measurements@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_PDM_A_INST0_ALL_MEASUREMENTS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_PDM_A_INST0_all_measurementsResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_PDM_A_INST0_ALL_MEASUREMENTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_PDM_A_INST0_all_measurements (ID = 0x00000113)

// @START@ Request handler for method data_cache::get_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_Data (ID = 0x00000114)
static void data_cache_get_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_PDM_A_Inst0_FDIR_CMD_EXEC_STATUS_type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_pdm_a_inst0_cmd_exec_status_data(&sOutput_data);

        respResult = data_cache_get_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_Data (ID = 0x00000114)

// @START@ Request handler for method data_cache::set_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_Data (ID = 0x00000115)
static void data_cache_set_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_Data (ID = 0x00000115)

// @START@ Request handler for method data_cache::get_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_Data (ID = 0x00000116)
static void data_cache_get_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_PDM_B_Inst0_FDIR_CMD_EXEC_STATUS_type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_pdm_b_inst0_cmd_exec_status_data(&sOutput_data);

        respResult = data_cache_get_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_Data (ID = 0x00000116)

// @START@ Request handler for method data_cache::set_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_Data (ID = 0x00000117)
static void data_cache_set_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_Data (ID = 0x00000117)

// @START@ Request handler for method data_cache::get_EPS3_PDM_B_INST0_uptime_in_seconds (ID = 0x00000118)
static void data_cache_get_EPS3_PDM_B_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_PDM_B_Inst0_UpTimeInSecondsType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_PDM_B_INST0_uptime_in_seconds@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_PDM_B_INST0_uptime_in_seconds@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_pdm_b_inst0_uptime_in_seconds(&sOutput_data);

        respResult = data_cache_get_EPS3_PDM_B_INST0_uptime_in_secondsResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_PDM_B_INST0_UPTIME_IN_SECONDS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_PDM_B_INST0_uptime_in_seconds (ID = 0x00000118)

// @START@ Request handler for method data_cache::set_EPS3_PDM_B_INST0_uptime_in_seconds (ID = 0x00000119)
static void data_cache_set_EPS3_PDM_B_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_PDM_B_INST0_uptime_in_secondsRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_PDM_B_INST0_uptime_in_seconds@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_PDM_B_INST0_uptime_in_seconds@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_PDM_B_INST0_UPTIME_IN_SECONDS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_PDM_B_INST0_uptime_in_secondsResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_PDM_B_INST0_UPTIME_IN_SECONDS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_PDM_B_INST0_uptime_in_seconds (ID = 0x00000119)

// @START@ Request handler for method data_cache::get_EPS3_PDM_B_INST0_common (ID = 0x0000011A)
static void data_cache_get_EPS3_PDM_B_INST0_commonRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_PDM_B_Inst0_CommonMeasurementType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_PDM_B_INST0_common@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_PDM_B_INST0_common@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_pdm_b_inst0_common(&sOutput_data);

        respResult = data_cache_get_EPS3_PDM_B_INST0_commonResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_PDM_B_INST0_COMMON_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_PDM_B_INST0_common (ID = 0x0000011A)

// @START@ Request handler for method data_cache::set_EPS3_PDM_B_INST0_common (ID = 0x0000011B)
static void data_cache_set_EPS3_PDM_B_INST0_commonRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_PDM_B_INST0_commonRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_PDM_B_INST0_common@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_PDM_B_INST0_common@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_PDM_B_INST0_COMMON, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_PDM_B_INST0_commonResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_PDM_B_INST0_COMMON_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_PDM_B_INST0_common (ID = 0x0000011B)

// @START@ Request handler for method data_cache::get_EPS3_PDM_B_INST0_hib_mode (ID = 0x0000011C)
static void data_cache_get_EPS3_PDM_B_INST0_hib_modeRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_PDM_B_Inst0_hib_mode_Type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_PDM_B_INST0_hib_mode@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_PDM_B_INST0_hib_mode@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_pdm_b_inst0_hib_mode(&sOutput_data);

        respResult = data_cache_get_EPS3_PDM_B_INST0_hib_modeResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_PDM_B_INST0_HIB_MODE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_PDM_B_INST0_hib_mode (ID = 0x0000011C)

// @START@ Request handler for method data_cache::set_EPS3_PDM_B_INST0_hib_mode (ID = 0x0000011D)
static void data_cache_set_EPS3_PDM_B_INST0_hib_modeRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_PDM_B_INST0_hib_modeRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_PDM_B_INST0_hib_mode@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_PDM_B_INST0_hib_mode@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_PDM_B_INST0_HIB_MODE, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_PDM_B_INST0_hib_modeResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_PDM_B_INST0_HIB_MODE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_PDM_B_INST0_hib_mode (ID = 0x0000011D)

// @START@ Request handler for method data_cache::get_EPS3_PDM_B_INST0_general_outputs (ID = 0x0000011E)
static void data_cache_get_EPS3_PDM_B_INST0_general_outputsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_PDM_B_Inst0_OutputsStatus_type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_PDM_B_INST0_general_outputs@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_PDM_B_INST0_general_outputs@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_pdm_b_inst0_general_outputs(&sOutput_data);

        respResult = data_cache_get_EPS3_PDM_B_INST0_general_outputsResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_PDM_B_INST0_GENERAL_OUTPUTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_PDM_B_INST0_general_outputs (ID = 0x0000011E)

// @START@ Request handler for method data_cache::set_EPS3_PDM_B_INST0_general_outputs (ID = 0x0000011F)
static void data_cache_set_EPS3_PDM_B_INST0_general_outputsRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_PDM_B_INST0_general_outputsRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_PDM_B_INST0_general_outputs@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_PDM_B_INST0_general_outputs@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_PDM_B_INST0_GENERAL_OUTPUTS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_PDM_B_INST0_general_outputsResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_PDM_B_INST0_GENERAL_OUTPUTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_PDM_B_INST0_general_outputs (ID = 0x0000011F)

// @START@ Request handler for method data_cache::get_EPS3_PDM_B_INST0_channel_flag_state (ID = 0x00000120)
static void data_cache_get_EPS3_PDM_B_INST0_channel_flag_stateRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_PDM_B_Inst0_ChannelFlagState_type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_PDM_B_INST0_channel_flag_state@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_PDM_B_INST0_channel_flag_state@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_pdm_b_inst0_channel_flag_state(&sOutput_data);

        respResult = data_cache_get_EPS3_PDM_B_INST0_channel_flag_stateResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_PDM_B_INST0_CHANNEL_FLAG_STATE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_PDM_B_INST0_channel_flag_state (ID = 0x00000120)

// @START@ Request handler for method data_cache::set_EPS3_PDM_B_INST0_channel_flag_state (ID = 0x00000121)
static void data_cache_set_EPS3_PDM_B_INST0_channel_flag_stateRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_PDM_B_INST0_channel_flag_stateRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_PDM_B_INST0_channel_flag_state@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_PDM_B_INST0_channel_flag_state@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_PDM_B_INST0_CHANNEL_FLAG_STATE, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_PDM_B_INST0_channel_flag_stateResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_PDM_B_INST0_CHANNEL_FLAG_STATE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_PDM_B_INST0_channel_flag_state (ID = 0x00000121)

// @START@ Request handler for method data_cache::get_EPS3_PDM_B_INST0_temperature (ID = 0x00000122)
static void data_cache_get_EPS3_PDM_B_INST0_temperatureRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_PDM_B_Inst0_Temps_type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_PDM_B_INST0_temperature@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_PDM_B_INST0_temperature@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_pdm_b_inst0_temperature(&sOutput_data);

        respResult = data_cache_get_EPS3_PDM_B_INST0_temperatureResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_PDM_B_INST0_TEMPERATURE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_PDM_B_INST0_temperature (ID = 0x00000122)

// @START@ Request handler for method data_cache::set_EPS3_PDM_B_INST0_temperature (ID = 0x00000123)
static void data_cache_set_EPS3_PDM_B_INST0_temperatureRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_PDM_B_INST0_temperatureRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_PDM_B_INST0_temperature@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_PDM_B_INST0_temperature@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_PDM_B_INST0_TEMPERATURE, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_PDM_B_INST0_temperatureResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_PDM_B_INST0_TEMPERATURE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_PDM_B_INST0_temperature (ID = 0x00000123)

// @START@ Request handler for method data_cache::get_EPS3_PDM_B_INST0_all_measurements (ID = 0x00000124)
static void data_cache_get_EPS3_PDM_B_INST0_all_measurementsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_PDM_B_Inst0_VoltAmpsMeasurements_type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_PDM_B_INST0_all_measurements@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_PDM_B_INST0_all_measurements@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_pdm_b_inst0_all_measurements(&sOutput_data);

        respResult = data_cache_get_EPS3_PDM_B_INST0_all_measurementsResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_PDM_B_INST0_ALL_MEASUREMENTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_PDM_B_INST0_all_measurements (ID = 0x00000124)

// @START@ Request handler for method data_cache::set_EPS3_PDM_B_INST0_all_measurements (ID = 0x00000125)
static void data_cache_set_EPS3_PDM_B_INST0_all_measurementsRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_PDM_B_INST0_all_measurementsRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_PDM_B_INST0_all_measurements@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_PDM_B_INST0_all_measurements@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_PDM_B_INST0_ALL_MEASUREMENTS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_PDM_B_INST0_all_measurementsResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_PDM_B_INST0_ALL_MEASUREMENTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_PDM_B_INST0_all_measurements (ID = 0x00000125)

// @START@ Request handler for method data_cache::get_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_Data (ID = 0x00000126)
static void data_cache_get_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_EXPANDER_Inst0_FDIR_CMD_EXEC_STATUS_type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_expander_inst0_cmd_exec_status_data(&sOutput_data);

        respResult = data_cache_get_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_Data (ID = 0x00000126)

// @START@ Request handler for method data_cache::set_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_Data (ID = 0x00000127)
static void data_cache_set_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_Data (ID = 0x00000127)

// @START@ Request handler for method data_cache::get_EPS3_EXPANDER_INST0_uptime_in_seconds (ID = 0x00000128)
static void data_cache_get_EPS3_EXPANDER_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_EXPANDER_Inst0_UpTimeInSecondsType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_EXPANDER_INST0_uptime_in_seconds@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_EXPANDER_INST0_uptime_in_seconds@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_expander_inst0_uptime_in_seconds(&sOutput_data);

        respResult = data_cache_get_EPS3_EXPANDER_INST0_uptime_in_secondsResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_EXPANDER_INST0_UPTIME_IN_SECONDS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_EXPANDER_INST0_uptime_in_seconds (ID = 0x00000128)

// @START@ Request handler for method data_cache::set_EPS3_EXPANDER_INST0_uptime_in_seconds (ID = 0x00000129)
static void data_cache_set_EPS3_EXPANDER_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_EXPANDER_INST0_uptime_in_secondsRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_EXPANDER_INST0_uptime_in_seconds@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_EXPANDER_INST0_uptime_in_seconds@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_EXPANDER_INST0_UPTIME_IN_SECONDS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_EXPANDER_INST0_uptime_in_secondsResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_EXPANDER_INST0_UPTIME_IN_SECONDS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_EXPANDER_INST0_uptime_in_seconds (ID = 0x00000129)

// @START@ Request handler for method data_cache::get_EPS3_EXPANDER_INST0_common (ID = 0x0000012A)
static void data_cache_get_EPS3_EXPANDER_INST0_commonRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_EXPANDER_Inst0_CommonMeasurementType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_EXPANDER_INST0_common@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_EXPANDER_INST0_common@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_expander_inst0_common(&sOutput_data);

        respResult = data_cache_get_EPS3_EXPANDER_INST0_commonResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_EXPANDER_INST0_COMMON_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_EXPANDER_INST0_common (ID = 0x0000012A)

// @START@ Request handler for method data_cache::set_EPS3_EXPANDER_INST0_common (ID = 0x0000012B)
static void data_cache_set_EPS3_EXPANDER_INST0_commonRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_EXPANDER_INST0_commonRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_EXPANDER_INST0_common@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_EXPANDER_INST0_common@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_EXPANDER_INST0_COMMON, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_EXPANDER_INST0_commonResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_EXPANDER_INST0_COMMON_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_EXPANDER_INST0_common (ID = 0x0000012B)

// @START@ Request handler for method data_cache::get_EPS3_EXPANDER_INST0_outputs (ID = 0x0000012C)
static void data_cache_get_EPS3_EXPANDER_INST0_outputsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_EXPANDER_Inst0_DigitalOutputsType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_EXPANDER_INST0_outputs@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_EXPANDER_INST0_outputs@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_expander_inst0_outputs(&sOutput_data);

        respResult = data_cache_get_EPS3_EXPANDER_INST0_outputsResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_EXPANDER_INST0_OUTPUTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_EXPANDER_INST0_outputs (ID = 0x0000012C)

// @START@ Request handler for method data_cache::set_EPS3_EXPANDER_INST0_outputs (ID = 0x0000012D)
static void data_cache_set_EPS3_EXPANDER_INST0_outputsRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_EXPANDER_INST0_outputsRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_EXPANDER_INST0_outputs@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_EXPANDER_INST0_outputs@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_EXPANDER_INST0_OUTPUTS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_EXPANDER_INST0_outputsResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_EXPANDER_INST0_OUTPUTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_EXPANDER_INST0_outputs (ID = 0x0000012D)

// @START@ Request handler for method data_cache::get_EPS3_EXPANDER_INST0_general_inputs (ID = 0x0000012E)
static void data_cache_get_EPS3_EXPANDER_INST0_general_inputsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_EXPANDER_Inst0_GeneralInputType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_EXPANDER_INST0_general_inputs@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_EXPANDER_INST0_general_inputs@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_expander_inst0_general_inputs(&sOutput_data);

        respResult = data_cache_get_EPS3_EXPANDER_INST0_general_inputsResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_EXPANDER_INST0_GENERAL_INPUTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_EXPANDER_INST0_general_inputs (ID = 0x0000012E)

// @START@ Request handler for method data_cache::set_EPS3_EXPANDER_INST0_general_inputs (ID = 0x0000012F)
static void data_cache_set_EPS3_EXPANDER_INST0_general_inputsRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_EXPANDER_INST0_general_inputsRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_EXPANDER_INST0_general_inputs@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_EXPANDER_INST0_general_inputs@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_EXPANDER_INST0_GENERAL_INPUTS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_EXPANDER_INST0_general_inputsResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_EXPANDER_INST0_GENERAL_INPUTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_EXPANDER_INST0_general_inputs (ID = 0x0000012F)

// @START@ Request handler for method data_cache::get_EPS3_EXPANDER_INST0_feedbacks (ID = 0x00000130)
static void data_cache_get_EPS3_EXPANDER_INST0_feedbacksRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_EXPANDER_Inst0_FeedbackType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_EXPANDER_INST0_feedbacks@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_EXPANDER_INST0_feedbacks@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_expander_inst0_feedbacks(&sOutput_data);

        respResult = data_cache_get_EPS3_EXPANDER_INST0_feedbacksResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_EXPANDER_INST0_FEEDBACKS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_EXPANDER_INST0_feedbacks (ID = 0x00000130)

// @START@ Request handler for method data_cache::set_EPS3_EXPANDER_INST0_feedbacks (ID = 0x00000131)
static void data_cache_set_EPS3_EXPANDER_INST0_feedbacksRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_EXPANDER_INST0_feedbacksRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_EXPANDER_INST0_feedbacks@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_EXPANDER_INST0_feedbacks@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_EXPANDER_INST0_FEEDBACKS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_EXPANDER_INST0_feedbacksResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_EXPANDER_INST0_FEEDBACKS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_EXPANDER_INST0_feedbacks (ID = 0x00000131)

// @START@ Request handler for method data_cache::get_EPS3_EXPANDER_INST0_volt_amp_measurements (ID = 0x00000132)
static void data_cache_get_EPS3_EXPANDER_INST0_volt_amp_measurementsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_EXPANDER_Inst0_CurrentLimitersType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_EXPANDER_INST0_volt_amp_measurements@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_EXPANDER_INST0_volt_amp_measurements@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_expander_inst0_volt_amp_measurements(&sOutput_data);

        respResult = data_cache_get_EPS3_EXPANDER_INST0_volt_amp_measurementsResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_EXPANDER_INST0_VOLT_AMP_MEASUREMENTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_EXPANDER_INST0_volt_amp_measurements (ID = 0x00000132)

// @START@ Request handler for method data_cache::set_EPS3_EXPANDER_INST0_volt_amp_measurements (ID = 0x00000133)
static void data_cache_set_EPS3_EXPANDER_INST0_volt_amp_measurementsRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_EXPANDER_INST0_volt_amp_measurementsRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_EXPANDER_INST0_volt_amp_measurements@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_EXPANDER_INST0_volt_amp_measurements@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_EXPANDER_INST0_VOLT_AMP_MEASUREMENTS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_EXPANDER_INST0_volt_amp_measurementsResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_EXPANDER_INST0_VOLT_AMP_MEASUREMENTS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_EXPANDER_INST0_volt_amp_measurements (ID = 0x00000133)

// @START@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0_uptime_in_seconds (ID = 0x00000134)
static void data_cache_get_EPS3_INPUT_STAGE_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_INPUT_STAGE_Inst0_UpTimeInSecondsType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_INPUT_STAGE_INST0_uptime_in_seconds@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_INPUT_STAGE_INST0_uptime_in_seconds@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_input_stage_inst0_uptime_in_seconds(&sOutput_data);

        respResult = data_cache_get_EPS3_INPUT_STAGE_INST0_uptime_in_secondsResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_INPUT_STAGE_INST0_UPTIME_IN_SECONDS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0_uptime_in_seconds (ID = 0x00000134)

// @START@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0_uptime_in_seconds (ID = 0x00000135)
static void data_cache_set_EPS3_INPUT_STAGE_INST0_uptime_in_secondsRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0_uptime_in_secondsRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_INPUT_STAGE_INST0_uptime_in_seconds@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_INPUT_STAGE_INST0_uptime_in_seconds@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_INPUT_STAGE_INST0_UPTIME_IN_SECONDS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_INPUT_STAGE_INST0_uptime_in_secondsResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_INPUT_STAGE_INST0_UPTIME_IN_SECONDS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0_uptime_in_seconds (ID = 0x00000135)

// @START@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0common (ID = 0x00000136)
static void data_cache_get_EPS3_INPUT_STAGE_INST0commonRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_INPUT_STAGE_Inst0CommonMeasurementType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_INPUT_STAGE_INST0common@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_INPUT_STAGE_INST0common@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_input_stage_inst0common(&sOutput_data);

        respResult = data_cache_get_EPS3_INPUT_STAGE_INST0commonResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_INPUT_STAGE_INST0COMMON_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0common (ID = 0x00000136)

// @START@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0common (ID = 0x00000137)
static void data_cache_set_EPS3_INPUT_STAGE_INST0commonRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0commonRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_INPUT_STAGE_INST0common@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_INPUT_STAGE_INST0common@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_INPUT_STAGE_INST0COMMON, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_INPUT_STAGE_INST0commonResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_INPUT_STAGE_INST0COMMON_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0common (ID = 0x00000137)

// @START@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0hib_mode_status (ID = 0x00000138)
static void data_cache_get_EPS3_INPUT_STAGE_INST0hib_mode_statusRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_INPUT_STAGE_Inst0hib_mode_status_type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_INPUT_STAGE_INST0hib_mode_status@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_INPUT_STAGE_INST0hib_mode_status@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_input_stage_inst0hib_mode_status(&sOutput_data);

        respResult = data_cache_get_EPS3_INPUT_STAGE_INST0hib_mode_statusResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_INPUT_STAGE_INST0HIB_MODE_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0hib_mode_status (ID = 0x00000138)

// @START@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0hib_mode_status (ID = 0x00000139)
static void data_cache_set_EPS3_INPUT_STAGE_INST0hib_mode_statusRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0hib_mode_statusRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_INPUT_STAGE_INST0hib_mode_status@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_INPUT_STAGE_INST0hib_mode_status@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_INPUT_STAGE_INST0HIB_MODE_STATUS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_INPUT_STAGE_INST0hib_mode_statusResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_INPUT_STAGE_INST0HIB_MODE_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0hib_mode_status (ID = 0x00000139)

// @START@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0selflock_on (ID = 0x0000013A)
static void data_cache_get_EPS3_INPUT_STAGE_INST0selflock_onRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_INPUT_STAGE_Inst0selflock_on_type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_INPUT_STAGE_INST0selflock_on@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_INPUT_STAGE_INST0selflock_on@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_input_stage_inst0selflock_on(&sOutput_data);

        respResult = data_cache_get_EPS3_INPUT_STAGE_INST0selflock_onResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_INPUT_STAGE_INST0SELFLOCK_ON_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0selflock_on (ID = 0x0000013A)

// @START@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0selflock_on (ID = 0x0000013B)
static void data_cache_set_EPS3_INPUT_STAGE_INST0selflock_onRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0selflock_onRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_INPUT_STAGE_INST0selflock_on@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_INPUT_STAGE_INST0selflock_on@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_INPUT_STAGE_INST0SELFLOCK_ON, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_INPUT_STAGE_INST0selflock_onResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_INPUT_STAGE_INST0SELFLOCK_ON_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0selflock_on (ID = 0x0000013B)

// @START@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0sp1 (ID = 0x0000013C)
static void data_cache_get_EPS3_INPUT_STAGE_INST0sp1RequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_INPUT_STAGE_Inst0Sp1InputDataType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_INPUT_STAGE_INST0sp1@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_INPUT_STAGE_INST0sp1@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_input_stage_inst0sp1(&sOutput_data);

        respResult = data_cache_get_EPS3_INPUT_STAGE_INST0sp1Resp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_INPUT_STAGE_INST0SP1_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0sp1 (ID = 0x0000013C)

// @START@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0sp1 (ID = 0x0000013D)
static void data_cache_set_EPS3_INPUT_STAGE_INST0sp1RequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0sp1RequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_INPUT_STAGE_INST0sp1@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_INPUT_STAGE_INST0sp1@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_INPUT_STAGE_INST0SP1, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_INPUT_STAGE_INST0sp1Resp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_INPUT_STAGE_INST0SP1_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0sp1 (ID = 0x0000013D)

// @START@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0sp2 (ID = 0x0000013E)
static void data_cache_get_EPS3_INPUT_STAGE_INST0sp2RequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_INPUT_STAGE_Inst0Sp2InputDataType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_INPUT_STAGE_INST0sp2@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_INPUT_STAGE_INST0sp2@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_input_stage_inst0sp2(&sOutput_data);

        respResult = data_cache_get_EPS3_INPUT_STAGE_INST0sp2Resp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_INPUT_STAGE_INST0SP2_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0sp2 (ID = 0x0000013E)

// @START@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0sp2 (ID = 0x0000013F)
static void data_cache_set_EPS3_INPUT_STAGE_INST0sp2RequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0sp2RequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_INPUT_STAGE_INST0sp2@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_INPUT_STAGE_INST0sp2@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_INPUT_STAGE_INST0SP2, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_INPUT_STAGE_INST0sp2Resp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_INPUT_STAGE_INST0SP2_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0sp2 (ID = 0x0000013F)

// @START@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0sp3 (ID = 0x00000140)
static void data_cache_get_EPS3_INPUT_STAGE_INST0sp3RequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_INPUT_STAGE_Inst0Sp3InputDataType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_INPUT_STAGE_INST0sp3@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_INPUT_STAGE_INST0sp3@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_input_stage_inst0sp3(&sOutput_data);

        respResult = data_cache_get_EPS3_INPUT_STAGE_INST0sp3Resp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_INPUT_STAGE_INST0SP3_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0sp3 (ID = 0x00000140)

// @START@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0sp3 (ID = 0x00000141)
static void data_cache_set_EPS3_INPUT_STAGE_INST0sp3RequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0sp3RequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_INPUT_STAGE_INST0sp3@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_INPUT_STAGE_INST0sp3@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_INPUT_STAGE_INST0SP3, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_INPUT_STAGE_INST0sp3Resp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_INPUT_STAGE_INST0SP3_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0sp3 (ID = 0x00000141)

// @START@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0system_bus (ID = 0x00000142)
static void data_cache_get_EPS3_INPUT_STAGE_INST0system_busRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_INPUT_STAGE_Inst0SystemBusType_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_INPUT_STAGE_INST0system_bus@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_INPUT_STAGE_INST0system_bus@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_input_stage_inst0system_bus(&sOutput_data);

        respResult = data_cache_get_EPS3_INPUT_STAGE_INST0system_busResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_INPUT_STAGE_INST0SYSTEM_BUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0system_bus (ID = 0x00000142)

// @START@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0system_bus (ID = 0x00000143)
static void data_cache_set_EPS3_INPUT_STAGE_INST0system_busRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0system_busRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_INPUT_STAGE_INST0system_bus@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_INPUT_STAGE_INST0system_bus@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_INPUT_STAGE_INST0SYSTEM_BUS, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_INPUT_STAGE_INST0system_busResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_INPUT_STAGE_INST0SYSTEM_BUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0system_bus (ID = 0x00000143)

// @START@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0bus_7v5 (ID = 0x00000144)
static void data_cache_get_EPS3_INPUT_STAGE_INST0bus_7v5RequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_INPUT_STAGE_Inst0Bus7v5Type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_INPUT_STAGE_INST0bus_7v5@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_INPUT_STAGE_INST0bus_7v5@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_input_stage_inst0bus_7v5(&sOutput_data);

        respResult = data_cache_get_EPS3_INPUT_STAGE_INST0bus_7v5Resp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_INPUT_STAGE_INST0BUS_7V5_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0bus_7v5 (ID = 0x00000144)

// @START@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0bus_7v5 (ID = 0x00000145)
static void data_cache_set_EPS3_INPUT_STAGE_INST0bus_7v5RequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0bus_7v5RequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_INPUT_STAGE_INST0bus_7v5@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_INPUT_STAGE_INST0bus_7v5@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_INPUT_STAGE_INST0BUS_7V5, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_INPUT_STAGE_INST0bus_7v5Resp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_INPUT_STAGE_INST0BUS_7V5_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0bus_7v5 (ID = 0x00000145)

// @START@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0bus_7v5_power_good (ID = 0x00000146)
static void data_cache_get_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_INPUT_STAGE_Inst0bus_7v5_power_good_type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_INPUT_STAGE_INST0bus_7v5_power_good@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_INPUT_STAGE_INST0bus_7v5_power_good@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_input_stage_inst0bus_7v5_power_good(&sOutput_data);

        respResult = data_cache_get_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_INPUT_STAGE_INST0BUS_7V5_POWER_GOOD_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0bus_7v5_power_good (ID = 0x00000146)

// @START@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0bus_7v5_power_good (ID = 0x00000147)
static void data_cache_set_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_INPUT_STAGE_INST0bus_7v5_power_good@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_INPUT_STAGE_INST0bus_7v5_power_good@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_INPUT_STAGE_INST0BUS_7V5_POWER_GOOD, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_INPUT_STAGE_INST0BUS_7V5_POWER_GOOD_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0bus_7v5_power_good (ID = 0x00000147)

// @START@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0undervoltage_7V5 (ID = 0x00000148)
static void data_cache_get_EPS3_INPUT_STAGE_INST0undervoltage_7V5RequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_INPUT_STAGE_Inst0undervoltage_7V5_type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_INPUT_STAGE_INST0undervoltage_7V5@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_INPUT_STAGE_INST0undervoltage_7V5@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_input_stage_inst0undervoltage_7v5(&sOutput_data);

        respResult = data_cache_get_EPS3_INPUT_STAGE_INST0undervoltage_7V5Resp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_INPUT_STAGE_INST0UNDERVOLTAGE_7V5_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0undervoltage_7V5 (ID = 0x00000148)

// @START@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0undervoltage_7V5 (ID = 0x00000149)
static void data_cache_set_EPS3_INPUT_STAGE_INST0undervoltage_7V5RequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0undervoltage_7V5RequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_INPUT_STAGE_INST0undervoltage_7V5@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_INPUT_STAGE_INST0undervoltage_7V5@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_INPUT_STAGE_INST0UNDERVOLTAGE_7V5, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_INPUT_STAGE_INST0undervoltage_7V5Resp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_INPUT_STAGE_INST0UNDERVOLTAGE_7V5_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0undervoltage_7V5 (ID = 0x00000149)

// @START@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0bus_3v3 (ID = 0x0000014A)
static void data_cache_get_EPS3_INPUT_STAGE_INST0bus_3v3RequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_INPUT_STAGE_Inst0Bbus3v3Type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_INPUT_STAGE_INST0bus_3v3@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_INPUT_STAGE_INST0bus_3v3@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_input_stage_inst0bus_3v3(&sOutput_data);

        respResult = data_cache_get_EPS3_INPUT_STAGE_INST0bus_3v3Resp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_INPUT_STAGE_INST0BUS_3V3_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0bus_3v3 (ID = 0x0000014A)

// @START@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0bus_3v3 (ID = 0x0000014B)
static void data_cache_set_EPS3_INPUT_STAGE_INST0bus_3v3RequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0bus_3v3RequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_INPUT_STAGE_INST0bus_3v3@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_INPUT_STAGE_INST0bus_3v3@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_INPUT_STAGE_INST0BUS_3V3, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_INPUT_STAGE_INST0bus_3v3Resp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_INPUT_STAGE_INST0BUS_3V3_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0bus_3v3 (ID = 0x0000014B)

// @START@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0undervoltage_3V3 (ID = 0x0000014C)
static void data_cache_get_EPS3_INPUT_STAGE_INST0undervoltage_3V3RequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_INPUT_STAGE_Inst0undervoltage_3V3_type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_INPUT_STAGE_INST0undervoltage_3V3@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_INPUT_STAGE_INST0undervoltage_3V3@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_input_stage_inst0undervoltage_3v3(&sOutput_data);

        respResult = data_cache_get_EPS3_INPUT_STAGE_INST0undervoltage_3V3Resp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_INPUT_STAGE_INST0UNDERVOLTAGE_3V3_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0undervoltage_3V3 (ID = 0x0000014C)

// @START@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0undervoltage_3V3 (ID = 0x0000014D)
static void data_cache_set_EPS3_INPUT_STAGE_INST0undervoltage_3V3RequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0undervoltage_3V3RequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_INPUT_STAGE_INST0undervoltage_3V3@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_INPUT_STAGE_INST0undervoltage_3V3@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_INPUT_STAGE_INST0UNDERVOLTAGE_3V3, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_INPUT_STAGE_INST0undervoltage_3V3Resp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_INPUT_STAGE_INST0UNDERVOLTAGE_3V3_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0undervoltage_3V3 (ID = 0x0000014D)

// @START@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_Data (ID = 0x0000014E)
static void data_cache_get_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_Eps3_INPUT_STAGE_Inst0_FDIR_CMD_EXEC_STATUS_type_t sOutput_data;
    DATA_CACHE_DCDataStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::get_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::get_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_Data@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        eStatus = dc_get_eps3_input_stage_inst0_cmd_exec_status_data(&sOutput_data);

        respResult = data_cache_get_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        &sOutput_data,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_GET_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::get_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_Data (ID = 0x0000014E)

// @START@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_Data (ID = 0x0000014F)
static void data_cache_set_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataRequestHandlerImpl(ReqContext_t *pReqCtx,
            const data_cacheset_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    DATA_CACHE_DCDataUpdateStatus_t eStatus;

    // @USER_VAR_SECTION_START@data_cache::set_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_Data@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@data_cache::set_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_Data@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        dc_set_raw_data(DC_DATA_INPUT_EXTERNAL, DC_DID_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DATA, &pRequestData->sInput_data, sizeof(pRequestData->sInput_data));

        eStatus = DCDATA_UPDATE_STATUS_OK;

        respResult = data_cache_set_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_DATA_CACHE, DATA_CACHE_SET_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DATA_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method data_cache::set_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_Data (ID = 0x0000014F)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void data_cacheServerAppInit(void)
{
    data_cache_registerServerApi(&data_cacheServerApiCtx);
}
