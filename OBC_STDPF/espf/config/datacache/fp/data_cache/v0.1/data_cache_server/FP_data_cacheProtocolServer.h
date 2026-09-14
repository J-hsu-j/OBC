/*!
********************************************************************************************
* @file FP_data_cacheProtocolServer.h
* @brief ESSA Stack server-side public API declaration
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

#ifndef FP_DATA_CACHEPROTOCOLSERVER_H
#define FP_DATA_CACHEPROTOCOLSERVER_H

#include "FP_data_cacheProtocolTypes.h"

/**********************************************************************
 *
 *  Public defines
 *
 **********************************************************************/
#define data_cache_PROTOCOL_VERSION_MAJOR   ((uint8_t) 0)
#define data_cache_PROTOCOL_VERSION_MINOR   ((uint8_t) 1)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
typedef void (*pfdata_cache_get_OBC_0_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_OBC_0_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_OBC_0_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_ADCS_0_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_ADCS_0_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_ADCS_0_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_ADCS_1_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_ADCS_1_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_ADCS_1_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_ADCS_2_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_ADCS_2_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_ADCS_2_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS_0_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS_0_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS_0_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_SSP_0_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_SSP_0_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_SSP_0_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_SSP_1_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_SSP_1_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_SSP_1_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_SSP_2_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_SSP_2_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_SSP_2_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_SSP_3_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_SSP_3_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_SSP_3_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_AOCS_CNTRL_TLM_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_AOCS_CNTRL_TLM_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_AOCS_CNTRL_TLM_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_AOCS_CNTRL_SYS_STATE_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_AOCS_CNTRL_SYS_STATE_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_AOCS_CNTRL_SYS_STATE_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_AOCS_CNTRL_REF_PARAMS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_AOCS_CNTRL_REF_PARAMS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_AOCS_CNTRL_REF_PARAMS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_SENSOR_GYRO_SENSOR_FRAME_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_SENSOR_GYRO_SENSOR_FRAME_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_SENSOR_GYRO_SENSOR_FRAME_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_SENSOR_GYRO_BODY_FRAME_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_SENSOR_GYRO_BODY_FRAME_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_SENSOR_GYRO_BODY_FRAME_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_SENSOR_MAG_PRIMARY_BODY_FRAME_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_SENSOR_MAG_PRIMARY_BODY_FRAME_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_SENSOR_MAG_PRIMARY_BODY_FRAME_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_SENSOR_MAG_SECONDARY_BODY_FRAME_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_SENSOR_MAG_SECONDARY_BODY_FRAME_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_SENSOR_MAG_SECONDARY_BODY_FRAME_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_SENSOR_COARSE_SUN_SENSOR_FRAME_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_SENSOR_COARSE_SUN_SENSOR_FRAME_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_SENSOR_COARSE_SUN_SENSOR_FRAME_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_SENSOR_COARSE_SUN_BODY_FRAME_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_SENSOR_COARSE_SUN_BODY_FRAME_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_SENSOR_COARSE_SUN_BODY_FRAME_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_SENSOR_PANEL_TEMP_BODY_FRAME_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_SENSOR_PANEL_TEMP_BODY_FRAME_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_SENSOR_PANEL_TEMP_BODY_FRAME_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_SENSOR_GYRO_TEMP_BODY_FRAME_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_SENSOR_GYRO_TEMP_BODY_FRAME_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_SENSOR_GYRO_TEMP_BODY_FRAME_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_ACTUATOR_MTQ_VALUES_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_ACTUATOR_MTQ_VALUES_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_ACTUATOR_MTQ_VALUES_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_ACTUATOR_TORQUE_VALUES_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_ACTUATOR_TORQUE_VALUES_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_ACTUATOR_TORQUE_VALUES_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_ADCS_3_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_ADCS_3_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_ADCS_3_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_ADCS_4_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_ADCS_4_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_ADCS_4_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS_9_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS_9_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS_9_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS_10_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS_10_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS_10_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS_14_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS_14_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS_14_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_OP_STATUS_COMMON_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_OP_STATUS_COMMON_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_OP_STATUS_COMMON_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_OP_STATUS_APP_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_OP_STATUS_APP_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_OP_STATUS_APP_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_166_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_166_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_166_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_167_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_167_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_167_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_168_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_168_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_168_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_169_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_169_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_169_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_170_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_170_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_170_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_171_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_171_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_171_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_172_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_172_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_172_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_173_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_173_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_173_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_174_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_174_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_174_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_175_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_175_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_175_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_176_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_176_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_176_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_177_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_177_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_177_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_178_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_178_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_178_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_179_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_179_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_179_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_180_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_180_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_180_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_203_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_203_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_203_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_204_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_204_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_204_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_205_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_205_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_205_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_206_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_206_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_206_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_207_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_207_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_207_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_208_1_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_208_1_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_208_1_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_208_2_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_208_2_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_208_2_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_209_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_209_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_209_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_210_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_210_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_210_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_211_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_211_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_211_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_212_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_212_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_212_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_213_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_213_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_213_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_214_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_214_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_214_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_216_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_216_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_216_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_217_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_217_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_217_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_218_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_218_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_218_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_225_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_225_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_225_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_226_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_226_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_226_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_165_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_165_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_165_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_221_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_221_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_CUBEADCS_GEN2_TLM_FRAME_221_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_GNSS_TIME_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_GNSS_TIME_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_GNSS_TIME_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_GNSS_BESTXYZ_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_GNSS_BESTXYZ_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_GNSS_BESTXYZ_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_FDIR_EPS_I_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_FDIR_EPS_I_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_FDIR_EPS_I_CMD_EXEC_STATUS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_FDIR_CUBEADCS_GEN2_EVENTS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_FDIR_CUBEADCS_GEN2_EVENTS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_FDIR_CUBEADCS_GEN2_EVENTS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_FDIR_UHF_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_FDIR_UHF_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_FDIR_UHF_CMD_EXEC_STATUS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_FDIR_GNSS_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_FDIR_GNSS_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_FDIR_GNSS_CMD_EXEC_STATUS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_FDIR_SDR_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_FDIR_SDR_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_FDIR_SDR_CMD_EXEC_STATUS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_FDIR_THRUSTER_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_FDIR_THRUSTER_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_FDIR_THRUSTER_CMD_EXEC_STATUS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_XBand_Fe_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_XBand_Fe_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_XBand_Fe_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EpsOverallBatteryInfo_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EpsOverallBatteryInfo_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EpsOverallBatteryInfo_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_PPS_Telemetry_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_PPS_Telemetry_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_PPS_Telemetry_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST0_BP_INFO_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST0_BP_INFO_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST0_BP_INFO_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST0_INA_SENSOR1_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST0_INA_SENSOR1_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST0_INA_SENSOR1_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST0_INA_SENSOR2_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST0_INA_SENSOR2_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST0_INA_SENSOR2_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST0_BALANCER_INFO_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST0_BALANCER_INFO_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST0_BALANCER_INFO_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST0_BALANCER_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST0_BALANCER_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST0_BALANCER_STATUS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST0_CHARGER_XP_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST0_CHARGER_XP_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST0_CHARGER_XP_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST0_CHARGER_XR_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST0_CHARGER_XR_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST0_CHARGER_XR_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST0_CHARGER_YP_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST0_CHARGER_YP_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST0_CHARGER_YP_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST0_CHARGER_YR_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST0_CHARGER_YR_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST0_CHARGER_YR_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST0_CHARGER_ZP_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST0_CHARGER_ZP_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST0_CHARGER_ZP_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST0_CHARGER_ZR_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST0_CHARGER_ZR_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST0_CHARGER_ZR_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST1_BP_INFO_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST1_BP_INFO_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST1_BP_INFO_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST1_INA_SENSOR1_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST1_INA_SENSOR1_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST1_INA_SENSOR1_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST1_INA_SENSOR2_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST1_INA_SENSOR2_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST1_INA_SENSOR2_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST1_BALANCER_INFO_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST1_BALANCER_INFO_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST1_BALANCER_INFO_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST1_BALANCER_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST1_BALANCER_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST1_BALANCER_STATUS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST1_CHARGER_XP_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST1_CHARGER_XP_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST1_CHARGER_XP_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST1_CHARGER_XR_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST1_CHARGER_XR_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST1_CHARGER_XR_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST1_CHARGER_YP_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST1_CHARGER_YP_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST1_CHARGER_YP_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST1_CHARGER_YR_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST1_CHARGER_YR_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST1_CHARGER_YR_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST1_CHARGER_ZP_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST1_CHARGER_ZP_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST1_CHARGER_ZP_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS2_BP_INST1_CHARGER_ZR_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS2_BP_INST1_CHARGER_ZR_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS2_BP_INST1_CHARGER_ZR_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_BP_INST0_uptime_in_secondsRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_BP_INST0_uptime_in_secondsRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_BP_INST0_uptime_in_secondsRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_BP_INST0commonRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_BP_INST0commonRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_BP_INST0commonRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_BP_INST0hib_mode_statusRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_BP_INST0hib_mode_statusRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_BP_INST0hib_mode_statusRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_BP_INST0measurementsRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_BP_INST0measurementsRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_BP_INST0measurementsRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_BP_INST0discharging_stateRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_BP_INST0discharging_stateRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_BP_INST0discharging_stateRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_BP_INST0charge_statusRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_BP_INST0charge_statusRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_BP_INST0charge_statusRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_BP_INST0balancers_statusRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_BP_INST0balancers_statusRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_BP_INST0balancers_statusRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_BP_INST0battery_cells_statusRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_BP_INST0battery_cells_statusRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_BP_INST0battery_cells_statusRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_BP_INST0heaters_statusRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_BP_INST0heaters_statusRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_BP_INST0heaters_statusRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_BP_INST0_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_BP_INST0_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_BP_INST0_CMD_EXEC_STATUS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_dumb_dataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_dumb_dataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_dumb_dataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_dumb_data1RequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_dumb_data1RequestHandler_t)(ReqContext_t *ctx, const data_cacheset_dumb_data1RequestData_t *pRequestData);
typedef void (*pfdata_cache_get_dumb_data3RequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_dumb_data3RequestHandler_t)(ReqContext_t *ctx, const data_cacheset_dumb_data3RequestData_t *pRequestData);
typedef void (*pfdata_cache_get_dumb_data4RequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_dumb_data4RequestHandler_t)(ReqContext_t *ctx, const data_cacheset_dumb_data4RequestData_t *pRequestData);
typedef void (*pfdata_cache_get_dumb_data5RequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_dumb_data5RequestHandler_t)(ReqContext_t *ctx, const data_cacheset_dumb_data5RequestData_t *pRequestData);
typedef void (*pfdata_cache_get_dumb_data6RequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_dumb_data6RequestHandler_t)(ReqContext_t *ctx, const data_cacheset_dumb_data6RequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_PDM_A_INST0_uptime_in_secondsRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_PDM_A_INST0_uptime_in_secondsRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_PDM_A_INST0_uptime_in_secondsRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_PDM_A_INST0_commonRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_PDM_A_INST0_commonRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_PDM_A_INST0_commonRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_PDM_A_INST0_hib_modeRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_PDM_A_INST0_hib_modeRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_PDM_A_INST0_hib_modeRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_PDM_A_INST0_general_outputsRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_PDM_A_INST0_general_outputsRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_PDM_A_INST0_general_outputsRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_PDM_A_INST0_general_faultsRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_PDM_A_INST0_general_faultsRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_PDM_A_INST0_general_faultsRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_PDM_A_INST0_all_measurementsRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_PDM_A_INST0_all_measurementsRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_PDM_A_INST0_all_measurementsRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_PDM_B_INST0_uptime_in_secondsRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_PDM_B_INST0_uptime_in_secondsRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_PDM_B_INST0_uptime_in_secondsRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_PDM_B_INST0_commonRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_PDM_B_INST0_commonRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_PDM_B_INST0_commonRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_PDM_B_INST0_hib_modeRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_PDM_B_INST0_hib_modeRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_PDM_B_INST0_hib_modeRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_PDM_B_INST0_general_outputsRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_PDM_B_INST0_general_outputsRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_PDM_B_INST0_general_outputsRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_PDM_B_INST0_channel_flag_stateRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_PDM_B_INST0_channel_flag_stateRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_PDM_B_INST0_channel_flag_stateRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_PDM_B_INST0_temperatureRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_PDM_B_INST0_temperatureRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_PDM_B_INST0_temperatureRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_PDM_B_INST0_all_measurementsRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_PDM_B_INST0_all_measurementsRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_PDM_B_INST0_all_measurementsRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_EXPANDER_INST0_uptime_in_secondsRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_EXPANDER_INST0_uptime_in_secondsRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_EXPANDER_INST0_uptime_in_secondsRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_EXPANDER_INST0_commonRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_EXPANDER_INST0_commonRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_EXPANDER_INST0_commonRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_EXPANDER_INST0_outputsRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_EXPANDER_INST0_outputsRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_EXPANDER_INST0_outputsRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_EXPANDER_INST0_general_inputsRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_EXPANDER_INST0_general_inputsRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_EXPANDER_INST0_general_inputsRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_EXPANDER_INST0_feedbacksRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_EXPANDER_INST0_feedbacksRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_EXPANDER_INST0_feedbacksRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_EXPANDER_INST0_volt_amp_measurementsRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_EXPANDER_INST0_volt_amp_measurementsRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_EXPANDER_INST0_volt_amp_measurementsRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_INPUT_STAGE_INST0_uptime_in_secondsRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_INPUT_STAGE_INST0_uptime_in_secondsRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_INPUT_STAGE_INST0_uptime_in_secondsRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_INPUT_STAGE_INST0commonRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_INPUT_STAGE_INST0commonRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_INPUT_STAGE_INST0commonRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_INPUT_STAGE_INST0hib_mode_statusRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_INPUT_STAGE_INST0hib_mode_statusRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_INPUT_STAGE_INST0hib_mode_statusRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_INPUT_STAGE_INST0selflock_onRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_INPUT_STAGE_INST0selflock_onRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_INPUT_STAGE_INST0selflock_onRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_INPUT_STAGE_INST0sp1RequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_INPUT_STAGE_INST0sp1RequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_INPUT_STAGE_INST0sp1RequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_INPUT_STAGE_INST0sp2RequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_INPUT_STAGE_INST0sp2RequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_INPUT_STAGE_INST0sp2RequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_INPUT_STAGE_INST0sp3RequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_INPUT_STAGE_INST0sp3RequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_INPUT_STAGE_INST0sp3RequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_INPUT_STAGE_INST0system_busRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_INPUT_STAGE_INST0system_busRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_INPUT_STAGE_INST0system_busRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_INPUT_STAGE_INST0bus_7v5RequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_INPUT_STAGE_INST0bus_7v5RequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_INPUT_STAGE_INST0bus_7v5RequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodRequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_INPUT_STAGE_INST0undervoltage_7V5RequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_INPUT_STAGE_INST0undervoltage_7V5RequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_INPUT_STAGE_INST0undervoltage_7V5RequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_INPUT_STAGE_INST0bus_3v3RequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_INPUT_STAGE_INST0bus_3v3RequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_INPUT_STAGE_INST0bus_3v3RequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_INPUT_STAGE_INST0undervoltage_3V3RequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_INPUT_STAGE_INST0undervoltage_3V3RequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_INPUT_STAGE_INST0undervoltage_3V3RequestData_t *pRequestData);
typedef void (*pfdata_cache_get_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx);
typedef void (*pfdata_cache_set_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataRequestHandler_t)(ReqContext_t *ctx, const data_cacheset_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataRequestData_t *pRequestData);

typedef struct {
    pfdata_cache_get_OBC_0_DataRequestHandler_t data_cache_get_OBC_0_DataRequestHandler;
    pfdata_cache_set_OBC_0_DataRequestHandler_t data_cache_set_OBC_0_DataRequestHandler;
    pfdata_cache_get_ADCS_0_DataRequestHandler_t data_cache_get_ADCS_0_DataRequestHandler;
    pfdata_cache_set_ADCS_0_DataRequestHandler_t data_cache_set_ADCS_0_DataRequestHandler;
    pfdata_cache_get_ADCS_1_DataRequestHandler_t data_cache_get_ADCS_1_DataRequestHandler;
    pfdata_cache_set_ADCS_1_DataRequestHandler_t data_cache_set_ADCS_1_DataRequestHandler;
    pfdata_cache_get_ADCS_2_DataRequestHandler_t data_cache_get_ADCS_2_DataRequestHandler;
    pfdata_cache_set_ADCS_2_DataRequestHandler_t data_cache_set_ADCS_2_DataRequestHandler;
    pfdata_cache_get_EPS_0_DataRequestHandler_t data_cache_get_EPS_0_DataRequestHandler;
    pfdata_cache_set_EPS_0_DataRequestHandler_t data_cache_set_EPS_0_DataRequestHandler;
    pfdata_cache_get_SSP_0_DataRequestHandler_t data_cache_get_SSP_0_DataRequestHandler;
    pfdata_cache_set_SSP_0_DataRequestHandler_t data_cache_set_SSP_0_DataRequestHandler;
    pfdata_cache_get_SSP_1_DataRequestHandler_t data_cache_get_SSP_1_DataRequestHandler;
    pfdata_cache_set_SSP_1_DataRequestHandler_t data_cache_set_SSP_1_DataRequestHandler;
    pfdata_cache_get_SSP_2_DataRequestHandler_t data_cache_get_SSP_2_DataRequestHandler;
    pfdata_cache_set_SSP_2_DataRequestHandler_t data_cache_set_SSP_2_DataRequestHandler;
    pfdata_cache_get_SSP_3_DataRequestHandler_t data_cache_get_SSP_3_DataRequestHandler;
    pfdata_cache_set_SSP_3_DataRequestHandler_t data_cache_set_SSP_3_DataRequestHandler;
    pfdata_cache_get_AOCS_CNTRL_TLM_DataRequestHandler_t data_cache_get_AOCS_CNTRL_TLM_DataRequestHandler;
    pfdata_cache_set_AOCS_CNTRL_TLM_DataRequestHandler_t data_cache_set_AOCS_CNTRL_TLM_DataRequestHandler;
    pfdata_cache_get_AOCS_CNTRL_SYS_STATE_DataRequestHandler_t data_cache_get_AOCS_CNTRL_SYS_STATE_DataRequestHandler;
    pfdata_cache_set_AOCS_CNTRL_SYS_STATE_DataRequestHandler_t data_cache_set_AOCS_CNTRL_SYS_STATE_DataRequestHandler;
    pfdata_cache_get_AOCS_CNTRL_REF_PARAMS_DataRequestHandler_t data_cache_get_AOCS_CNTRL_REF_PARAMS_DataRequestHandler;
    pfdata_cache_set_AOCS_CNTRL_REF_PARAMS_DataRequestHandler_t data_cache_set_AOCS_CNTRL_REF_PARAMS_DataRequestHandler;
    pfdata_cache_get_SENSOR_GYRO_SENSOR_FRAME_DataRequestHandler_t data_cache_get_SENSOR_GYRO_SENSOR_FRAME_DataRequestHandler;
    pfdata_cache_set_SENSOR_GYRO_SENSOR_FRAME_DataRequestHandler_t data_cache_set_SENSOR_GYRO_SENSOR_FRAME_DataRequestHandler;
    pfdata_cache_get_SENSOR_GYRO_BODY_FRAME_DataRequestHandler_t data_cache_get_SENSOR_GYRO_BODY_FRAME_DataRequestHandler;
    pfdata_cache_set_SENSOR_GYRO_BODY_FRAME_DataRequestHandler_t data_cache_set_SENSOR_GYRO_BODY_FRAME_DataRequestHandler;
    pfdata_cache_get_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataRequestHandler_t data_cache_get_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataRequestHandler;
    pfdata_cache_set_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataRequestHandler_t data_cache_set_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataRequestHandler;
    pfdata_cache_get_SENSOR_MAG_PRIMARY_BODY_FRAME_DataRequestHandler_t data_cache_get_SENSOR_MAG_PRIMARY_BODY_FRAME_DataRequestHandler;
    pfdata_cache_set_SENSOR_MAG_PRIMARY_BODY_FRAME_DataRequestHandler_t data_cache_set_SENSOR_MAG_PRIMARY_BODY_FRAME_DataRequestHandler;
    pfdata_cache_get_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataRequestHandler_t data_cache_get_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataRequestHandler;
    pfdata_cache_set_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataRequestHandler_t data_cache_set_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataRequestHandler;
    pfdata_cache_get_SENSOR_MAG_SECONDARY_BODY_FRAME_DataRequestHandler_t data_cache_get_SENSOR_MAG_SECONDARY_BODY_FRAME_DataRequestHandler;
    pfdata_cache_set_SENSOR_MAG_SECONDARY_BODY_FRAME_DataRequestHandler_t data_cache_set_SENSOR_MAG_SECONDARY_BODY_FRAME_DataRequestHandler;
    pfdata_cache_get_SENSOR_COARSE_SUN_SENSOR_FRAME_DataRequestHandler_t data_cache_get_SENSOR_COARSE_SUN_SENSOR_FRAME_DataRequestHandler;
    pfdata_cache_set_SENSOR_COARSE_SUN_SENSOR_FRAME_DataRequestHandler_t data_cache_set_SENSOR_COARSE_SUN_SENSOR_FRAME_DataRequestHandler;
    pfdata_cache_get_SENSOR_COARSE_SUN_BODY_FRAME_DataRequestHandler_t data_cache_get_SENSOR_COARSE_SUN_BODY_FRAME_DataRequestHandler;
    pfdata_cache_set_SENSOR_COARSE_SUN_BODY_FRAME_DataRequestHandler_t data_cache_set_SENSOR_COARSE_SUN_BODY_FRAME_DataRequestHandler;
    pfdata_cache_get_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataRequestHandler_t data_cache_get_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataRequestHandler;
    pfdata_cache_set_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataRequestHandler_t data_cache_set_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataRequestHandler;
    pfdata_cache_get_SENSOR_PANEL_TEMP_BODY_FRAME_DataRequestHandler_t data_cache_get_SENSOR_PANEL_TEMP_BODY_FRAME_DataRequestHandler;
    pfdata_cache_set_SENSOR_PANEL_TEMP_BODY_FRAME_DataRequestHandler_t data_cache_set_SENSOR_PANEL_TEMP_BODY_FRAME_DataRequestHandler;
    pfdata_cache_get_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataRequestHandler_t data_cache_get_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataRequestHandler;
    pfdata_cache_set_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataRequestHandler_t data_cache_set_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataRequestHandler;
    pfdata_cache_get_SENSOR_GYRO_TEMP_BODY_FRAME_DataRequestHandler_t data_cache_get_SENSOR_GYRO_TEMP_BODY_FRAME_DataRequestHandler;
    pfdata_cache_set_SENSOR_GYRO_TEMP_BODY_FRAME_DataRequestHandler_t data_cache_set_SENSOR_GYRO_TEMP_BODY_FRAME_DataRequestHandler;
    pfdata_cache_get_ACTUATOR_MTQ_VALUES_DataRequestHandler_t data_cache_get_ACTUATOR_MTQ_VALUES_DataRequestHandler;
    pfdata_cache_set_ACTUATOR_MTQ_VALUES_DataRequestHandler_t data_cache_set_ACTUATOR_MTQ_VALUES_DataRequestHandler;
    pfdata_cache_get_ACTUATOR_TORQUE_VALUES_DataRequestHandler_t data_cache_get_ACTUATOR_TORQUE_VALUES_DataRequestHandler;
    pfdata_cache_set_ACTUATOR_TORQUE_VALUES_DataRequestHandler_t data_cache_set_ACTUATOR_TORQUE_VALUES_DataRequestHandler;
    pfdata_cache_get_ADCS_3_DataRequestHandler_t data_cache_get_ADCS_3_DataRequestHandler;
    pfdata_cache_set_ADCS_3_DataRequestHandler_t data_cache_set_ADCS_3_DataRequestHandler;
    pfdata_cache_get_ADCS_4_DataRequestHandler_t data_cache_get_ADCS_4_DataRequestHandler;
    pfdata_cache_set_ADCS_4_DataRequestHandler_t data_cache_set_ADCS_4_DataRequestHandler;
    pfdata_cache_get_EPS_9_DataRequestHandler_t data_cache_get_EPS_9_DataRequestHandler;
    pfdata_cache_set_EPS_9_DataRequestHandler_t data_cache_set_EPS_9_DataRequestHandler;
    pfdata_cache_get_EPS_10_DataRequestHandler_t data_cache_get_EPS_10_DataRequestHandler;
    pfdata_cache_set_EPS_10_DataRequestHandler_t data_cache_set_EPS_10_DataRequestHandler;
    pfdata_cache_get_EPS_14_DataRequestHandler_t data_cache_get_EPS_14_DataRequestHandler;
    pfdata_cache_set_EPS_14_DataRequestHandler_t data_cache_set_EPS_14_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_OP_STATUS_COMMON_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_OP_STATUS_COMMON_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_OP_STATUS_COMMON_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_OP_STATUS_COMMON_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_OP_STATUS_APP_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_OP_STATUS_APP_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_OP_STATUS_APP_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_OP_STATUS_APP_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_166_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_166_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_166_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_166_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_167_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_167_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_167_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_167_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_168_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_168_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_168_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_168_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_169_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_169_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_169_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_169_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_170_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_170_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_170_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_170_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_171_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_171_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_171_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_171_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_172_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_172_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_172_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_172_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_173_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_173_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_173_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_173_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_174_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_174_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_174_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_174_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_175_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_175_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_175_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_175_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_176_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_176_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_176_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_176_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_177_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_177_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_177_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_177_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_178_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_178_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_178_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_178_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_179_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_179_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_179_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_179_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_180_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_180_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_180_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_180_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_203_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_203_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_203_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_203_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_204_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_204_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_204_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_204_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_205_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_205_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_205_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_205_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_206_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_206_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_206_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_206_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_207_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_207_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_207_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_207_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_208_1_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_208_1_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_208_1_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_208_1_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_208_2_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_208_2_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_208_2_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_208_2_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_209_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_209_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_209_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_209_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_210_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_210_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_210_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_210_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_211_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_211_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_211_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_211_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_212_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_212_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_212_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_212_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_213_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_213_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_213_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_213_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_214_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_214_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_214_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_214_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_216_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_216_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_216_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_216_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_217_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_217_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_217_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_217_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_218_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_218_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_218_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_218_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_225_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_225_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_225_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_225_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_226_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_226_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_226_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_226_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_165_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_165_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_165_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_165_DataRequestHandler;
    pfdata_cache_get_CUBEADCS_GEN2_TLM_FRAME_221_DataRequestHandler_t data_cache_get_CUBEADCS_GEN2_TLM_FRAME_221_DataRequestHandler;
    pfdata_cache_set_CUBEADCS_GEN2_TLM_FRAME_221_DataRequestHandler_t data_cache_set_CUBEADCS_GEN2_TLM_FRAME_221_DataRequestHandler;
    pfdata_cache_get_GNSS_TIME_DataRequestHandler_t data_cache_get_GNSS_TIME_DataRequestHandler;
    pfdata_cache_set_GNSS_TIME_DataRequestHandler_t data_cache_set_GNSS_TIME_DataRequestHandler;
    pfdata_cache_get_GNSS_BESTXYZ_DataRequestHandler_t data_cache_get_GNSS_BESTXYZ_DataRequestHandler;
    pfdata_cache_set_GNSS_BESTXYZ_DataRequestHandler_t data_cache_set_GNSS_BESTXYZ_DataRequestHandler;
    pfdata_cache_get_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataRequestHandler_t data_cache_get_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataRequestHandler;
    pfdata_cache_set_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataRequestHandler_t data_cache_set_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataRequestHandler;
    pfdata_cache_get_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataRequestHandler_t data_cache_get_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataRequestHandler;
    pfdata_cache_set_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataRequestHandler_t data_cache_set_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataRequestHandler;
    pfdata_cache_get_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataRequestHandler_t data_cache_get_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataRequestHandler;
    pfdata_cache_set_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataRequestHandler_t data_cache_set_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataRequestHandler;
    pfdata_cache_get_FDIR_EPS_I_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_get_FDIR_EPS_I_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_set_FDIR_EPS_I_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_set_FDIR_EPS_I_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_get_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_get_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_set_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_set_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_get_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_get_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_set_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_set_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_get_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_get_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_set_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_set_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_get_FDIR_CUBEADCS_GEN2_EVENTS_DataRequestHandler_t data_cache_get_FDIR_CUBEADCS_GEN2_EVENTS_DataRequestHandler;
    pfdata_cache_set_FDIR_CUBEADCS_GEN2_EVENTS_DataRequestHandler_t data_cache_set_FDIR_CUBEADCS_GEN2_EVENTS_DataRequestHandler;
    pfdata_cache_get_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_get_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_set_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_set_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_get_FDIR_UHF_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_get_FDIR_UHF_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_set_FDIR_UHF_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_set_FDIR_UHF_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_get_FDIR_GNSS_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_get_FDIR_GNSS_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_set_FDIR_GNSS_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_set_FDIR_GNSS_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_get_FDIR_SDR_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_get_FDIR_SDR_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_set_FDIR_SDR_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_set_FDIR_SDR_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_get_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_get_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_set_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_set_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_get_FDIR_THRUSTER_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_get_FDIR_THRUSTER_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_set_FDIR_THRUSTER_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_set_FDIR_THRUSTER_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_get_XBand_Fe_DataRequestHandler_t data_cache_get_XBand_Fe_DataRequestHandler;
    pfdata_cache_set_XBand_Fe_DataRequestHandler_t data_cache_set_XBand_Fe_DataRequestHandler;
    pfdata_cache_get_EpsOverallBatteryInfo_DataRequestHandler_t data_cache_get_EpsOverallBatteryInfo_DataRequestHandler;
    pfdata_cache_set_EpsOverallBatteryInfo_DataRequestHandler_t data_cache_set_EpsOverallBatteryInfo_DataRequestHandler;
    pfdata_cache_get_PPS_Telemetry_DataRequestHandler_t data_cache_get_PPS_Telemetry_DataRequestHandler;
    pfdata_cache_set_PPS_Telemetry_DataRequestHandler_t data_cache_set_PPS_Telemetry_DataRequestHandler;
    pfdata_cache_get_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_get_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_set_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_set_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST0_BP_INFO_DataRequestHandler_t data_cache_get_EPS2_BP_INST0_BP_INFO_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST0_BP_INFO_DataRequestHandler_t data_cache_set_EPS2_BP_INST0_BP_INFO_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataRequestHandler_t data_cache_get_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataRequestHandler_t data_cache_set_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST0_INA_SENSOR1_DataRequestHandler_t data_cache_get_EPS2_BP_INST0_INA_SENSOR1_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST0_INA_SENSOR1_DataRequestHandler_t data_cache_set_EPS2_BP_INST0_INA_SENSOR1_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST0_INA_SENSOR2_DataRequestHandler_t data_cache_get_EPS2_BP_INST0_INA_SENSOR2_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST0_INA_SENSOR2_DataRequestHandler_t data_cache_set_EPS2_BP_INST0_INA_SENSOR2_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST0_BALANCER_INFO_DataRequestHandler_t data_cache_get_EPS2_BP_INST0_BALANCER_INFO_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST0_BALANCER_INFO_DataRequestHandler_t data_cache_set_EPS2_BP_INST0_BALANCER_INFO_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST0_BALANCER_STATUS_DataRequestHandler_t data_cache_get_EPS2_BP_INST0_BALANCER_STATUS_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST0_BALANCER_STATUS_DataRequestHandler_t data_cache_set_EPS2_BP_INST0_BALANCER_STATUS_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataRequestHandler_t data_cache_get_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataRequestHandler_t data_cache_set_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST0_CHARGER_XP_DataRequestHandler_t data_cache_get_EPS2_BP_INST0_CHARGER_XP_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST0_CHARGER_XP_DataRequestHandler_t data_cache_set_EPS2_BP_INST0_CHARGER_XP_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST0_CHARGER_XR_DataRequestHandler_t data_cache_get_EPS2_BP_INST0_CHARGER_XR_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST0_CHARGER_XR_DataRequestHandler_t data_cache_set_EPS2_BP_INST0_CHARGER_XR_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST0_CHARGER_YP_DataRequestHandler_t data_cache_get_EPS2_BP_INST0_CHARGER_YP_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST0_CHARGER_YP_DataRequestHandler_t data_cache_set_EPS2_BP_INST0_CHARGER_YP_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST0_CHARGER_YR_DataRequestHandler_t data_cache_get_EPS2_BP_INST0_CHARGER_YR_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST0_CHARGER_YR_DataRequestHandler_t data_cache_set_EPS2_BP_INST0_CHARGER_YR_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST0_CHARGER_ZP_DataRequestHandler_t data_cache_get_EPS2_BP_INST0_CHARGER_ZP_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST0_CHARGER_ZP_DataRequestHandler_t data_cache_set_EPS2_BP_INST0_CHARGER_ZP_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST0_CHARGER_ZR_DataRequestHandler_t data_cache_get_EPS2_BP_INST0_CHARGER_ZR_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST0_CHARGER_ZR_DataRequestHandler_t data_cache_set_EPS2_BP_INST0_CHARGER_ZR_DataRequestHandler;
    pfdata_cache_get_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_get_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_set_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_set_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST1_BP_INFO_DataRequestHandler_t data_cache_get_EPS2_BP_INST1_BP_INFO_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST1_BP_INFO_DataRequestHandler_t data_cache_set_EPS2_BP_INST1_BP_INFO_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataRequestHandler_t data_cache_get_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataRequestHandler_t data_cache_set_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST1_INA_SENSOR1_DataRequestHandler_t data_cache_get_EPS2_BP_INST1_INA_SENSOR1_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST1_INA_SENSOR1_DataRequestHandler_t data_cache_set_EPS2_BP_INST1_INA_SENSOR1_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST1_INA_SENSOR2_DataRequestHandler_t data_cache_get_EPS2_BP_INST1_INA_SENSOR2_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST1_INA_SENSOR2_DataRequestHandler_t data_cache_set_EPS2_BP_INST1_INA_SENSOR2_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST1_BALANCER_INFO_DataRequestHandler_t data_cache_get_EPS2_BP_INST1_BALANCER_INFO_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST1_BALANCER_INFO_DataRequestHandler_t data_cache_set_EPS2_BP_INST1_BALANCER_INFO_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST1_BALANCER_STATUS_DataRequestHandler_t data_cache_get_EPS2_BP_INST1_BALANCER_STATUS_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST1_BALANCER_STATUS_DataRequestHandler_t data_cache_set_EPS2_BP_INST1_BALANCER_STATUS_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataRequestHandler_t data_cache_get_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataRequestHandler_t data_cache_set_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST1_CHARGER_XP_DataRequestHandler_t data_cache_get_EPS2_BP_INST1_CHARGER_XP_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST1_CHARGER_XP_DataRequestHandler_t data_cache_set_EPS2_BP_INST1_CHARGER_XP_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST1_CHARGER_XR_DataRequestHandler_t data_cache_get_EPS2_BP_INST1_CHARGER_XR_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST1_CHARGER_XR_DataRequestHandler_t data_cache_set_EPS2_BP_INST1_CHARGER_XR_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST1_CHARGER_YP_DataRequestHandler_t data_cache_get_EPS2_BP_INST1_CHARGER_YP_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST1_CHARGER_YP_DataRequestHandler_t data_cache_set_EPS2_BP_INST1_CHARGER_YP_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST1_CHARGER_YR_DataRequestHandler_t data_cache_get_EPS2_BP_INST1_CHARGER_YR_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST1_CHARGER_YR_DataRequestHandler_t data_cache_set_EPS2_BP_INST1_CHARGER_YR_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST1_CHARGER_ZP_DataRequestHandler_t data_cache_get_EPS2_BP_INST1_CHARGER_ZP_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST1_CHARGER_ZP_DataRequestHandler_t data_cache_set_EPS2_BP_INST1_CHARGER_ZP_DataRequestHandler;
    pfdata_cache_get_EPS2_BP_INST1_CHARGER_ZR_DataRequestHandler_t data_cache_get_EPS2_BP_INST1_CHARGER_ZR_DataRequestHandler;
    pfdata_cache_set_EPS2_BP_INST1_CHARGER_ZR_DataRequestHandler_t data_cache_set_EPS2_BP_INST1_CHARGER_ZR_DataRequestHandler;
    pfdata_cache_get_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_get_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_set_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_set_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_get_EPS3_BP_INST0_uptime_in_secondsRequestHandler_t data_cache_get_EPS3_BP_INST0_uptime_in_secondsRequestHandler;
    pfdata_cache_set_EPS3_BP_INST0_uptime_in_secondsRequestHandler_t data_cache_set_EPS3_BP_INST0_uptime_in_secondsRequestHandler;
    pfdata_cache_get_EPS3_BP_INST0commonRequestHandler_t data_cache_get_EPS3_BP_INST0commonRequestHandler;
    pfdata_cache_set_EPS3_BP_INST0commonRequestHandler_t data_cache_set_EPS3_BP_INST0commonRequestHandler;
    pfdata_cache_get_EPS3_BP_INST0hib_mode_statusRequestHandler_t data_cache_get_EPS3_BP_INST0hib_mode_statusRequestHandler;
    pfdata_cache_set_EPS3_BP_INST0hib_mode_statusRequestHandler_t data_cache_set_EPS3_BP_INST0hib_mode_statusRequestHandler;
    pfdata_cache_get_EPS3_BP_INST0measurementsRequestHandler_t data_cache_get_EPS3_BP_INST0measurementsRequestHandler;
    pfdata_cache_set_EPS3_BP_INST0measurementsRequestHandler_t data_cache_set_EPS3_BP_INST0measurementsRequestHandler;
    pfdata_cache_get_EPS3_BP_INST0discharging_stateRequestHandler_t data_cache_get_EPS3_BP_INST0discharging_stateRequestHandler;
    pfdata_cache_set_EPS3_BP_INST0discharging_stateRequestHandler_t data_cache_set_EPS3_BP_INST0discharging_stateRequestHandler;
    pfdata_cache_get_EPS3_BP_INST0charge_statusRequestHandler_t data_cache_get_EPS3_BP_INST0charge_statusRequestHandler;
    pfdata_cache_set_EPS3_BP_INST0charge_statusRequestHandler_t data_cache_set_EPS3_BP_INST0charge_statusRequestHandler;
    pfdata_cache_get_EPS3_BP_INST0balancers_statusRequestHandler_t data_cache_get_EPS3_BP_INST0balancers_statusRequestHandler;
    pfdata_cache_set_EPS3_BP_INST0balancers_statusRequestHandler_t data_cache_set_EPS3_BP_INST0balancers_statusRequestHandler;
    pfdata_cache_get_EPS3_BP_INST0battery_cells_statusRequestHandler_t data_cache_get_EPS3_BP_INST0battery_cells_statusRequestHandler;
    pfdata_cache_set_EPS3_BP_INST0battery_cells_statusRequestHandler_t data_cache_set_EPS3_BP_INST0battery_cells_statusRequestHandler;
    pfdata_cache_get_EPS3_BP_INST0heaters_statusRequestHandler_t data_cache_get_EPS3_BP_INST0heaters_statusRequestHandler;
    pfdata_cache_set_EPS3_BP_INST0heaters_statusRequestHandler_t data_cache_set_EPS3_BP_INST0heaters_statusRequestHandler;
    pfdata_cache_get_EPS3_BP_INST0_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_get_EPS3_BP_INST0_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_set_EPS3_BP_INST0_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_set_EPS3_BP_INST0_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_get_dumb_dataRequestHandler_t data_cache_get_dumb_dataRequestHandler;
    pfdata_cache_set_dumb_dataRequestHandler_t data_cache_set_dumb_dataRequestHandler;
    pfdata_cache_get_dumb_data1RequestHandler_t data_cache_get_dumb_data1RequestHandler;
    pfdata_cache_set_dumb_data1RequestHandler_t data_cache_set_dumb_data1RequestHandler;
    pfdata_cache_get_dumb_data3RequestHandler_t data_cache_get_dumb_data3RequestHandler;
    pfdata_cache_set_dumb_data3RequestHandler_t data_cache_set_dumb_data3RequestHandler;
    pfdata_cache_get_dumb_data4RequestHandler_t data_cache_get_dumb_data4RequestHandler;
    pfdata_cache_set_dumb_data4RequestHandler_t data_cache_set_dumb_data4RequestHandler;
    pfdata_cache_get_dumb_data5RequestHandler_t data_cache_get_dumb_data5RequestHandler;
    pfdata_cache_set_dumb_data5RequestHandler_t data_cache_set_dumb_data5RequestHandler;
    pfdata_cache_get_dumb_data6RequestHandler_t data_cache_get_dumb_data6RequestHandler;
    pfdata_cache_set_dumb_data6RequestHandler_t data_cache_set_dumb_data6RequestHandler;
    pfdata_cache_get_EPS3_PDM_A_INST0_uptime_in_secondsRequestHandler_t data_cache_get_EPS3_PDM_A_INST0_uptime_in_secondsRequestHandler;
    pfdata_cache_set_EPS3_PDM_A_INST0_uptime_in_secondsRequestHandler_t data_cache_set_EPS3_PDM_A_INST0_uptime_in_secondsRequestHandler;
    pfdata_cache_get_EPS3_PDM_A_INST0_commonRequestHandler_t data_cache_get_EPS3_PDM_A_INST0_commonRequestHandler;
    pfdata_cache_set_EPS3_PDM_A_INST0_commonRequestHandler_t data_cache_set_EPS3_PDM_A_INST0_commonRequestHandler;
    pfdata_cache_get_EPS3_PDM_A_INST0_hib_modeRequestHandler_t data_cache_get_EPS3_PDM_A_INST0_hib_modeRequestHandler;
    pfdata_cache_set_EPS3_PDM_A_INST0_hib_modeRequestHandler_t data_cache_set_EPS3_PDM_A_INST0_hib_modeRequestHandler;
    pfdata_cache_get_EPS3_PDM_A_INST0_general_outputsRequestHandler_t data_cache_get_EPS3_PDM_A_INST0_general_outputsRequestHandler;
    pfdata_cache_set_EPS3_PDM_A_INST0_general_outputsRequestHandler_t data_cache_set_EPS3_PDM_A_INST0_general_outputsRequestHandler;
    pfdata_cache_get_EPS3_PDM_A_INST0_general_faultsRequestHandler_t data_cache_get_EPS3_PDM_A_INST0_general_faultsRequestHandler;
    pfdata_cache_set_EPS3_PDM_A_INST0_general_faultsRequestHandler_t data_cache_set_EPS3_PDM_A_INST0_general_faultsRequestHandler;
    pfdata_cache_get_EPS3_PDM_A_INST0_all_measurementsRequestHandler_t data_cache_get_EPS3_PDM_A_INST0_all_measurementsRequestHandler;
    pfdata_cache_set_EPS3_PDM_A_INST0_all_measurementsRequestHandler_t data_cache_set_EPS3_PDM_A_INST0_all_measurementsRequestHandler;
    pfdata_cache_get_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_get_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_set_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_set_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_get_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_get_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_set_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_set_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_get_EPS3_PDM_B_INST0_uptime_in_secondsRequestHandler_t data_cache_get_EPS3_PDM_B_INST0_uptime_in_secondsRequestHandler;
    pfdata_cache_set_EPS3_PDM_B_INST0_uptime_in_secondsRequestHandler_t data_cache_set_EPS3_PDM_B_INST0_uptime_in_secondsRequestHandler;
    pfdata_cache_get_EPS3_PDM_B_INST0_commonRequestHandler_t data_cache_get_EPS3_PDM_B_INST0_commonRequestHandler;
    pfdata_cache_set_EPS3_PDM_B_INST0_commonRequestHandler_t data_cache_set_EPS3_PDM_B_INST0_commonRequestHandler;
    pfdata_cache_get_EPS3_PDM_B_INST0_hib_modeRequestHandler_t data_cache_get_EPS3_PDM_B_INST0_hib_modeRequestHandler;
    pfdata_cache_set_EPS3_PDM_B_INST0_hib_modeRequestHandler_t data_cache_set_EPS3_PDM_B_INST0_hib_modeRequestHandler;
    pfdata_cache_get_EPS3_PDM_B_INST0_general_outputsRequestHandler_t data_cache_get_EPS3_PDM_B_INST0_general_outputsRequestHandler;
    pfdata_cache_set_EPS3_PDM_B_INST0_general_outputsRequestHandler_t data_cache_set_EPS3_PDM_B_INST0_general_outputsRequestHandler;
    pfdata_cache_get_EPS3_PDM_B_INST0_channel_flag_stateRequestHandler_t data_cache_get_EPS3_PDM_B_INST0_channel_flag_stateRequestHandler;
    pfdata_cache_set_EPS3_PDM_B_INST0_channel_flag_stateRequestHandler_t data_cache_set_EPS3_PDM_B_INST0_channel_flag_stateRequestHandler;
    pfdata_cache_get_EPS3_PDM_B_INST0_temperatureRequestHandler_t data_cache_get_EPS3_PDM_B_INST0_temperatureRequestHandler;
    pfdata_cache_set_EPS3_PDM_B_INST0_temperatureRequestHandler_t data_cache_set_EPS3_PDM_B_INST0_temperatureRequestHandler;
    pfdata_cache_get_EPS3_PDM_B_INST0_all_measurementsRequestHandler_t data_cache_get_EPS3_PDM_B_INST0_all_measurementsRequestHandler;
    pfdata_cache_set_EPS3_PDM_B_INST0_all_measurementsRequestHandler_t data_cache_set_EPS3_PDM_B_INST0_all_measurementsRequestHandler;
    pfdata_cache_get_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_get_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_set_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_set_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_get_EPS3_EXPANDER_INST0_uptime_in_secondsRequestHandler_t data_cache_get_EPS3_EXPANDER_INST0_uptime_in_secondsRequestHandler;
    pfdata_cache_set_EPS3_EXPANDER_INST0_uptime_in_secondsRequestHandler_t data_cache_set_EPS3_EXPANDER_INST0_uptime_in_secondsRequestHandler;
    pfdata_cache_get_EPS3_EXPANDER_INST0_commonRequestHandler_t data_cache_get_EPS3_EXPANDER_INST0_commonRequestHandler;
    pfdata_cache_set_EPS3_EXPANDER_INST0_commonRequestHandler_t data_cache_set_EPS3_EXPANDER_INST0_commonRequestHandler;
    pfdata_cache_get_EPS3_EXPANDER_INST0_outputsRequestHandler_t data_cache_get_EPS3_EXPANDER_INST0_outputsRequestHandler;
    pfdata_cache_set_EPS3_EXPANDER_INST0_outputsRequestHandler_t data_cache_set_EPS3_EXPANDER_INST0_outputsRequestHandler;
    pfdata_cache_get_EPS3_EXPANDER_INST0_general_inputsRequestHandler_t data_cache_get_EPS3_EXPANDER_INST0_general_inputsRequestHandler;
    pfdata_cache_set_EPS3_EXPANDER_INST0_general_inputsRequestHandler_t data_cache_set_EPS3_EXPANDER_INST0_general_inputsRequestHandler;
    pfdata_cache_get_EPS3_EXPANDER_INST0_feedbacksRequestHandler_t data_cache_get_EPS3_EXPANDER_INST0_feedbacksRequestHandler;
    pfdata_cache_set_EPS3_EXPANDER_INST0_feedbacksRequestHandler_t data_cache_set_EPS3_EXPANDER_INST0_feedbacksRequestHandler;
    pfdata_cache_get_EPS3_EXPANDER_INST0_volt_amp_measurementsRequestHandler_t data_cache_get_EPS3_EXPANDER_INST0_volt_amp_measurementsRequestHandler;
    pfdata_cache_set_EPS3_EXPANDER_INST0_volt_amp_measurementsRequestHandler_t data_cache_set_EPS3_EXPANDER_INST0_volt_amp_measurementsRequestHandler;
    pfdata_cache_get_EPS3_INPUT_STAGE_INST0_uptime_in_secondsRequestHandler_t data_cache_get_EPS3_INPUT_STAGE_INST0_uptime_in_secondsRequestHandler;
    pfdata_cache_set_EPS3_INPUT_STAGE_INST0_uptime_in_secondsRequestHandler_t data_cache_set_EPS3_INPUT_STAGE_INST0_uptime_in_secondsRequestHandler;
    pfdata_cache_get_EPS3_INPUT_STAGE_INST0commonRequestHandler_t data_cache_get_EPS3_INPUT_STAGE_INST0commonRequestHandler;
    pfdata_cache_set_EPS3_INPUT_STAGE_INST0commonRequestHandler_t data_cache_set_EPS3_INPUT_STAGE_INST0commonRequestHandler;
    pfdata_cache_get_EPS3_INPUT_STAGE_INST0hib_mode_statusRequestHandler_t data_cache_get_EPS3_INPUT_STAGE_INST0hib_mode_statusRequestHandler;
    pfdata_cache_set_EPS3_INPUT_STAGE_INST0hib_mode_statusRequestHandler_t data_cache_set_EPS3_INPUT_STAGE_INST0hib_mode_statusRequestHandler;
    pfdata_cache_get_EPS3_INPUT_STAGE_INST0selflock_onRequestHandler_t data_cache_get_EPS3_INPUT_STAGE_INST0selflock_onRequestHandler;
    pfdata_cache_set_EPS3_INPUT_STAGE_INST0selflock_onRequestHandler_t data_cache_set_EPS3_INPUT_STAGE_INST0selflock_onRequestHandler;
    pfdata_cache_get_EPS3_INPUT_STAGE_INST0sp1RequestHandler_t data_cache_get_EPS3_INPUT_STAGE_INST0sp1RequestHandler;
    pfdata_cache_set_EPS3_INPUT_STAGE_INST0sp1RequestHandler_t data_cache_set_EPS3_INPUT_STAGE_INST0sp1RequestHandler;
    pfdata_cache_get_EPS3_INPUT_STAGE_INST0sp2RequestHandler_t data_cache_get_EPS3_INPUT_STAGE_INST0sp2RequestHandler;
    pfdata_cache_set_EPS3_INPUT_STAGE_INST0sp2RequestHandler_t data_cache_set_EPS3_INPUT_STAGE_INST0sp2RequestHandler;
    pfdata_cache_get_EPS3_INPUT_STAGE_INST0sp3RequestHandler_t data_cache_get_EPS3_INPUT_STAGE_INST0sp3RequestHandler;
    pfdata_cache_set_EPS3_INPUT_STAGE_INST0sp3RequestHandler_t data_cache_set_EPS3_INPUT_STAGE_INST0sp3RequestHandler;
    pfdata_cache_get_EPS3_INPUT_STAGE_INST0system_busRequestHandler_t data_cache_get_EPS3_INPUT_STAGE_INST0system_busRequestHandler;
    pfdata_cache_set_EPS3_INPUT_STAGE_INST0system_busRequestHandler_t data_cache_set_EPS3_INPUT_STAGE_INST0system_busRequestHandler;
    pfdata_cache_get_EPS3_INPUT_STAGE_INST0bus_7v5RequestHandler_t data_cache_get_EPS3_INPUT_STAGE_INST0bus_7v5RequestHandler;
    pfdata_cache_set_EPS3_INPUT_STAGE_INST0bus_7v5RequestHandler_t data_cache_set_EPS3_INPUT_STAGE_INST0bus_7v5RequestHandler;
    pfdata_cache_get_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodRequestHandler_t data_cache_get_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodRequestHandler;
    pfdata_cache_set_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodRequestHandler_t data_cache_set_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodRequestHandler;
    pfdata_cache_get_EPS3_INPUT_STAGE_INST0undervoltage_7V5RequestHandler_t data_cache_get_EPS3_INPUT_STAGE_INST0undervoltage_7V5RequestHandler;
    pfdata_cache_set_EPS3_INPUT_STAGE_INST0undervoltage_7V5RequestHandler_t data_cache_set_EPS3_INPUT_STAGE_INST0undervoltage_7V5RequestHandler;
    pfdata_cache_get_EPS3_INPUT_STAGE_INST0bus_3v3RequestHandler_t data_cache_get_EPS3_INPUT_STAGE_INST0bus_3v3RequestHandler;
    pfdata_cache_set_EPS3_INPUT_STAGE_INST0bus_3v3RequestHandler_t data_cache_set_EPS3_INPUT_STAGE_INST0bus_3v3RequestHandler;
    pfdata_cache_get_EPS3_INPUT_STAGE_INST0undervoltage_3V3RequestHandler_t data_cache_get_EPS3_INPUT_STAGE_INST0undervoltage_3V3RequestHandler;
    pfdata_cache_set_EPS3_INPUT_STAGE_INST0undervoltage_3V3RequestHandler_t data_cache_set_EPS3_INPUT_STAGE_INST0undervoltage_3V3RequestHandler;
    pfdata_cache_get_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_get_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataRequestHandler;
    pfdata_cache_set_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataRequestHandler_t data_cache_set_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataRequestHandler;
} data_cache_ServerApi_t;

/**********************************************************************
 *
 *  Server protocol ESSA descriptor
 *
 **********************************************************************/
extern const ESSA_Stack_FunctionProtocolInfo_t FP_data_cacheProtocolServerInfo;

/**********************************************************************
 *
 *  Public methods
 *
 **********************************************************************/
void data_cache_registerServerApi(data_cache_ServerApi_t *pSrvApiHandlers);

// @deprecated - will be removed in the future - use FP_data_cacheProtocolServerInfo directly
ESSA_pStack_FunctionProtocolInfo_t data_cache_getServerProtocolDescriptor(void);

ESSATMAC_ErrCodes data_cache_get_OBC_0_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_OBC_0_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_OBC_0_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_ADCS_0_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_ADCS_0_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_ADCS_0_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_ADCS_1_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_ADCS_1_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_ADCS_1_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_ADCS_2_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_ADCS_2_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_ADCS_2_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS_0_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_EPS_0_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS_0_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_SSP_0_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_SSP_0_Telemetry_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_SSP_0_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_SSP_1_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_SSP_1_Telemetry_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_SSP_1_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_SSP_2_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_SSP_2_Telemetry_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_SSP_2_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_SSP_3_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_SSP_3_Telemetry_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_SSP_3_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_AOCS_CNTRL_TLM_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_AOCS_CNTRL_TLM_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_AOCS_CNTRL_TLM_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_AOCS_CNTRL_SYS_STATE_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_AOCS_CNTRL_SYS_STATE_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_AOCS_CNTRL_SYS_STATE_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_AOCS_CNTRL_REF_PARAMS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_AOCS_CNTRL_REF_PARAMS_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_AOCS_CNTRL_REF_PARAMS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_SENSOR_GYRO_SENSOR_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_SENSOR_GYRO_SENSOR_FRAME_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_SENSOR_GYRO_SENSOR_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_SENSOR_GYRO_BODY_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_SENSOR_GYRO_BODY_FRAME_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_SENSOR_GYRO_BODY_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_SENSOR_MAG_PRIMARY_SENSOR_FRAME_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_SENSOR_MAG_PRIMARY_SENSOR_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_SENSOR_MAG_PRIMARY_BODY_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_SENSOR_MAG_PRIMARY_BODY_FRAME_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_SENSOR_MAG_PRIMARY_BODY_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_SENSOR_MAG_SECONDARY_SENSOR_FRAME_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_SENSOR_MAG_SECONDARY_SENSOR_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_SENSOR_MAG_SECONDARY_BODY_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_SENSOR_MAG_SECONDARY_BODY_FRAME_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_SENSOR_MAG_SECONDARY_BODY_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_SENSOR_COARSE_SUN_SENSOR_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_SENSOR_COARSE_SUN_SENSOR_FRAME_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_SENSOR_COARSE_SUN_SENSOR_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_SENSOR_COARSE_SUN_BODY_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_SENSOR_COARSE_SUN_BODY_FRAME_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_SENSOR_COARSE_SUN_BODY_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_SENSOR_PANEL_TEMP_SENSOR_FRAME_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_SENSOR_PANEL_TEMP_SENSOR_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_SENSOR_PANEL_TEMP_BODY_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_SENSOR_PANEL_TEMP_BODY_FRAME_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_SENSOR_PANEL_TEMP_BODY_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_SENSOR_GYRO_TEMP_SENSOR_FRAME_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_SENSOR_GYRO_TEMP_SENSOR_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_SENSOR_GYRO_TEMP_BODY_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_SENSOR_GYRO_TEMP_BODY_FRAME_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_SENSOR_GYRO_TEMP_BODY_FRAME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_ACTUATOR_MTQ_VALUES_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_ACTUATOR_MTQ_VALUES_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_ACTUATOR_MTQ_VALUES_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_ACTUATOR_TORQUE_VALUES_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_ACTUATOR_TORQUE_VALUES_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_ACTUATOR_TORQUE_VALUES_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_ADCS_3_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_ADCS_3_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_ADCS_3_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_ADCS_4_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_ADCS_4_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_ADCS_4_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS_9_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_EPS_9_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS_9_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS_10_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_EPS_10_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS_10_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS_14_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_EPS_14_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS_14_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_OP_STATUS_COMMON_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_OP_STATUS_COMMON_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_OP_STATUS_COMMON_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_OP_STATUS_APP_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_OP_STATUS_APP_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_OP_STATUS_APP_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_166_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_166_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_166_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_167_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_167_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_167_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_168_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_168_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_168_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_169_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_169_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_169_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_170_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_170_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_170_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_171_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_171_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_171_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_172_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_172_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_172_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_173_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_173_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_173_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_174_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_174_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_174_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_175_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_175_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_175_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_176_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_176_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_176_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_177_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_177_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_177_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_178_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_178_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_178_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_179_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_179_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_179_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_180_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_180_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_180_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_203_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_203_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_203_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_204_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_204_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_204_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_205_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_205_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_205_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_206_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_206_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_206_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_207_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_207_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_207_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_208_1_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_208_1_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_208_1_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_208_2_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_208_2_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_208_2_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_209_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_209_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_209_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_210_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_210_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_210_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_211_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_211_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_211_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_212_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_212_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_212_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_213_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_213_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_213_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_214_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_214_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_214_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_216_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_216_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_216_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_217_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_217_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_217_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_218_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_218_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_218_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_225_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_225_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_225_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_226_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_226_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_226_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_165_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_165_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_165_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_CUBEADCS_GEN2_TLM_FRAME_221_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_221_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_CUBEADCS_GEN2_TLM_FRAME_221_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_GNSS_TIME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_GNSS_TIME_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_GNSS_TIME_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_GNSS_BESTXYZ_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_GNSS_BESTXYZ_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_GNSS_BESTXYZ_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_SAT_STATE_VECTOR_FROM_PROPAGATOR_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_SAT_STATE_VECTOR_FROM_PROPAGATOR_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_SAT_MAG_FIELD_VECTOR_FROM_MODEL_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_SAT_MAG_FIELD_VECTOR_FROM_MODEL_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_SAT_MAG_FIELD_VECTOR_FROM_SENSOR_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_FDIR_EPS_I_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_FDIR_EPS_I_CMD_EXEC_STATUS_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_FDIR_EPS_I_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_FDIR_CUBEADCS_CMD_EXEC_STATUS_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_FDIR_CUBEADCS_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_FDIR_CUBEADCS_GEN2_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_FDIR_CUBEADCS_GEN2_EVENTS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_FDIR_CUBEADCS_GEN2_EVENTS_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_FDIR_CUBEADCS_GEN2_EVENTS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_FDIR_S_BAND_TMTC_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_FDIR_UHF_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_FDIR_UHF_CMD_EXEC_STATUS_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_FDIR_UHF_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_FDIR_GNSS_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_FDIR_GNSS_CMD_EXEC_STATUS_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_FDIR_GNSS_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_FDIR_SDR_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_FDIR_SDR_CMD_EXEC_STATUS_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_FDIR_SDR_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_FDIR_S_X_BAND_CMD_EXEC_STATUS_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_FDIR_S_X_BAND_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_FDIR_THRUSTER_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_FDIR_THRUSTER_CMD_EXEC_STATUS_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_FDIR_THRUSTER_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_XBand_Fe_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_XBandFeTelemetry_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_XBand_Fe_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EpsOverallBatteryInfo_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_EpsOverallBatteryInfoType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EpsOverallBatteryInfo_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_PPS_Telemetry_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_PPS_Telemetry_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_PPS_Telemetry_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_FDIR_EPS_III_PDM_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST0_BP_INFO_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst0BatteryInfoType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST0_BP_INFO_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst0DeviceHealthInfoType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST0_DEVICE_HEALTH_INFO_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST0_INA_SENSOR1_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst0InaSensors1Type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST0_INA_SENSOR1_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST0_INA_SENSOR2_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst0InaSensors2Type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST0_INA_SENSOR2_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST0_BALANCER_INFO_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst0BalancerInfoType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST0_BALANCER_INFO_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST0_BALANCER_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst0BalancerStatusType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST0_BALANCER_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst0BalancerCellsInfoType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST0_BALANCER_CELLS_INFO_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST0_CHARGER_XP_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst0ChargerXpType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST0_CHARGER_XP_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST0_CHARGER_XR_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst0ChargerXrType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST0_CHARGER_XR_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST0_CHARGER_YP_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst0ChargerYpType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST0_CHARGER_YP_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST0_CHARGER_YR_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst0ChargerYrType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST0_CHARGER_YR_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST0_CHARGER_ZP_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst0ChargerZpType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST0_CHARGER_ZP_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST0_CHARGER_ZR_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst0ChargerZrType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST0_CHARGER_ZR_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst0_FDIR_CMD_EXEC_STATUS_type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_FDIR_EPS_II_BP_INST0_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST1_BP_INFO_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst1BatteryInfoType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST1_BP_INFO_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst1DeviceHealthInfoType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST1_DEVICE_HEALTH_INFO_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST1_INA_SENSOR1_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst1InaSensors1Type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST1_INA_SENSOR1_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST1_INA_SENSOR2_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst1InaSensors2Type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST1_INA_SENSOR2_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST1_BALANCER_INFO_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst1BalancerInfoType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST1_BALANCER_INFO_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST1_BALANCER_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst1BalancerStatusType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST1_BALANCER_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst1BalancerCellsInfoType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST1_BALANCER_CELLS_INFO_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST1_CHARGER_XP_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst1ChargerXpType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST1_CHARGER_XP_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST1_CHARGER_XR_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst1ChargerXrType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST1_CHARGER_XR_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST1_CHARGER_YP_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst1ChargerYpType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST1_CHARGER_YP_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST1_CHARGER_YR_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst1ChargerYrType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST1_CHARGER_YR_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST1_CHARGER_ZP_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst1ChargerZpType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST1_CHARGER_ZP_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS2_BP_INST1_CHARGER_ZR_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst1ChargerZrType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS2_BP_INST1_CHARGER_ZR_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps2Inst1_FDIR_CMD_EXEC_STATUS_type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_FDIR_EPS_II_BP_INST1_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_BP_INST0_uptime_in_secondsResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3Inst0_UpTimeInSecondsType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_BP_INST0_uptime_in_secondsResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_BP_INST0commonResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3Inst0CommonMeasurementType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_BP_INST0commonResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_BP_INST0hib_mode_statusResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3Inst0HIBModeStatusType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_BP_INST0hib_mode_statusResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_BP_INST0measurementsResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3Inst0MeasurementsType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_BP_INST0measurementsResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_BP_INST0discharging_stateResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3Inst0DischargeStateType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_BP_INST0discharging_stateResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_BP_INST0charge_statusResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3Inst0ChargeOnStatusType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_BP_INST0charge_statusResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_BP_INST0balancers_statusResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3Inst0BalancersStatusType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_BP_INST0balancers_statusResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_BP_INST0battery_cells_statusResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3Inst0BatteryCellsStatusType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_BP_INST0battery_cells_statusResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_BP_INST0heaters_statusResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3Inst0HeatersStatusType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_BP_INST0heaters_statusResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_BP_INST0_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3Inst0_FDIR_CMD_EXEC_STATUS_type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_BP_INST0_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_dumb_dataResp(
                RespContext_t* ctx,
                const DATA_CACHE_VoltAmps_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_dumb_dataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_dumb_data1Resp(
                RespContext_t* ctx,
                const DATA_CACHE_VoltAllAmps_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_dumb_data1Resp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_dumb_data3Resp(
                RespContext_t* ctx,
                const DATA_CACHE_MpptState_str_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_dumb_data3Resp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_dumb_data4Resp(
                RespContext_t* ctx,
                const DATA_CACHE_ReadEnDftStatus_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_dumb_data4Resp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_dumb_data5Resp(
                RespContext_t* ctx,
                const DATA_CACHE_OnOffStatus_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_dumb_data5Resp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_dumb_data6Resp(
                RespContext_t* ctx,
                const DATA_CACHE_ReadLvlState_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_dumb_data6Resp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_PDM_A_INST0_uptime_in_secondsResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_PDM_A_Inst0_UpTimeInSecondsType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_PDM_A_INST0_uptime_in_secondsResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_PDM_A_INST0_commonResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_PDM_A_Inst0_CommonMesurementsType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_PDM_A_INST0_commonResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_PDM_A_INST0_hib_modeResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_PDM_A_Inst0_HibModeType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_PDM_A_INST0_hib_modeResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_PDM_A_INST0_general_outputsResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_PDM_A_Inst0_OutputsStatusType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_PDM_A_INST0_general_outputsResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_PDM_A_INST0_general_faultsResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_PDM_A_Inst0_FaultsStatusType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_PDM_A_INST0_general_faultsResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_PDM_A_INST0_all_measurementsResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_PDM_A_Inst0_VoltAmpsMeasurementsType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_PDM_A_INST0_all_measurementsResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_PDM_A_Inst0_FDIR_CMD_EXEC_STATUS_type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_PDM_A_INST0_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_PDM_B_Inst0_FDIR_CMD_EXEC_STATUS_type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_PDM_B_INST0_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_PDM_B_INST0_uptime_in_secondsResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_PDM_B_Inst0_UpTimeInSecondsType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_PDM_B_INST0_uptime_in_secondsResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_PDM_B_INST0_commonResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_PDM_B_Inst0_CommonMeasurementType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_PDM_B_INST0_commonResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_PDM_B_INST0_hib_modeResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_PDM_B_Inst0_hib_mode_Type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_PDM_B_INST0_hib_modeResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_PDM_B_INST0_general_outputsResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_PDM_B_Inst0_OutputsStatus_type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_PDM_B_INST0_general_outputsResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_PDM_B_INST0_channel_flag_stateResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_PDM_B_Inst0_ChannelFlagState_type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_PDM_B_INST0_channel_flag_stateResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_PDM_B_INST0_temperatureResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_PDM_B_Inst0_Temps_type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_PDM_B_INST0_temperatureResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_PDM_B_INST0_all_measurementsResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_PDM_B_Inst0_VoltAmpsMeasurements_type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_PDM_B_INST0_all_measurementsResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_EXPANDER_Inst0_FDIR_CMD_EXEC_STATUS_type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_EXPANDER_INST0_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_EXPANDER_INST0_uptime_in_secondsResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_EXPANDER_Inst0_UpTimeInSecondsType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_EXPANDER_INST0_uptime_in_secondsResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_EXPANDER_INST0_commonResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_EXPANDER_Inst0_CommonMeasurementType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_EXPANDER_INST0_commonResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_EXPANDER_INST0_outputsResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_EXPANDER_Inst0_DigitalOutputsType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_EXPANDER_INST0_outputsResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_EXPANDER_INST0_general_inputsResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_EXPANDER_Inst0_GeneralInputType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_EXPANDER_INST0_general_inputsResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_EXPANDER_INST0_feedbacksResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_EXPANDER_Inst0_FeedbackType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_EXPANDER_INST0_feedbacksResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_EXPANDER_INST0_volt_amp_measurementsResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_EXPANDER_Inst0_CurrentLimitersType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_EXPANDER_INST0_volt_amp_measurementsResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_INPUT_STAGE_INST0_uptime_in_secondsResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_INPUT_STAGE_Inst0_UpTimeInSecondsType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_INPUT_STAGE_INST0_uptime_in_secondsResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_INPUT_STAGE_INST0commonResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_INPUT_STAGE_Inst0CommonMeasurementType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_INPUT_STAGE_INST0commonResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_INPUT_STAGE_INST0hib_mode_statusResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_INPUT_STAGE_Inst0hib_mode_status_type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_INPUT_STAGE_INST0hib_mode_statusResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_INPUT_STAGE_INST0selflock_onResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_INPUT_STAGE_Inst0selflock_on_type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_INPUT_STAGE_INST0selflock_onResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_INPUT_STAGE_INST0sp1Resp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_INPUT_STAGE_Inst0Sp1InputDataType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_INPUT_STAGE_INST0sp1Resp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_INPUT_STAGE_INST0sp2Resp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_INPUT_STAGE_Inst0Sp2InputDataType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_INPUT_STAGE_INST0sp2Resp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_INPUT_STAGE_INST0sp3Resp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_INPUT_STAGE_Inst0Sp3InputDataType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_INPUT_STAGE_INST0sp3Resp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_INPUT_STAGE_INST0system_busResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_INPUT_STAGE_Inst0SystemBusType_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_INPUT_STAGE_INST0system_busResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_INPUT_STAGE_INST0bus_7v5Resp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_INPUT_STAGE_Inst0Bus7v5Type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_INPUT_STAGE_INST0bus_7v5Resp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_INPUT_STAGE_Inst0bus_7v5_power_good_type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_INPUT_STAGE_INST0bus_7v5_power_goodResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_INPUT_STAGE_INST0undervoltage_7V5Resp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_INPUT_STAGE_Inst0undervoltage_7V5_type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_INPUT_STAGE_INST0undervoltage_7V5Resp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_INPUT_STAGE_INST0bus_3v3Resp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_INPUT_STAGE_Inst0Bbus3v3Type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_INPUT_STAGE_INST0bus_3v3Resp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_INPUT_STAGE_INST0undervoltage_3V3Resp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_INPUT_STAGE_Inst0undervoltage_3V3_type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_INPUT_STAGE_INST0undervoltage_3V3Resp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_get_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_Eps3_INPUT_STAGE_Inst0_FDIR_CMD_EXEC_STATUS_type_t * const sOutput_data,
                const DATA_CACHE_DCDataStatus_t eStatus
);

ESSATMAC_ErrCodes data_cache_set_EPS3_INPUT_STAGE_INST0_CMD_EXEC_STATUS_DataResp(
                RespContext_t* ctx,
                const DATA_CACHE_DCDataUpdateStatus_t eStatus
);


#endif  // #ifndef FP_DATA_CACHEPROTOCOLSERVER_H
