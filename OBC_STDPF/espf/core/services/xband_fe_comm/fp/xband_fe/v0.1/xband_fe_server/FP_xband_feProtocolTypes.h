/*!
********************************************************************************************
* @file FP_xband_feProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface xband_fe v0.1
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

#ifndef FP_XBAND_FEPROTOCOLTYPES_H
#define FP_XBAND_FEPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_XBAND_FE ((uint16_t) (0x00000023))

#define XBAND_FE_GET_OBC_XBAND_FE_NVM_CFG_FUNC_ID ((funcIdType_t) 0x00000000)
#define XBAND_FE_SET_OBC_XBAND_FE_NVM_CFG_FUNC_ID ((funcIdType_t) 0x00000001)
#define XBAND_FE_GET_STATUS_REPORT_FUNC_ID ((funcIdType_t) 0x0000004B)
#define XBAND_FE_SET_SYS_MNGR_RUN_MODE_FUNC_ID ((funcIdType_t) 0x000000B2)
#define XBAND_FE_SET_SYS_MNGR_STANDBY_MODE_FUNC_ID ((funcIdType_t) 0x000000B3)
#define XBAND_FE_SET_MOD_ALL_PARAMS_FUNC_ID ((funcIdType_t) 0x000000BA)
#define XBAND_FE_GET_MOD_ALL_PARAMS_FUNC_ID ((funcIdType_t) 0x000000BB)
#define XBAND_FE_SET_TX_POWER_FUNC_ID ((funcIdType_t) 0x000000BD)
#define XBAND_FE_GET_TX_POWER_FUNC_ID ((funcIdType_t) 0x000000BE)
#define XBAND_FE_GET_OBC_XBAND_FE_NVM_CFG_FUNCRESP_ID ((funcIdType_t) 0x00000000)
#define XBAND_FE_SET_OBC_XBAND_FE_NVM_CFG_FUNCRESP_ID ((funcIdType_t) 0x00000001)
#define XBAND_FE_GET_STATUS_REPORT_FUNCRESP_ID ((funcIdType_t) 0x0000004B)
#define XBAND_FE_SET_SYS_MNGR_RUN_MODE_FUNCRESP_ID ((funcIdType_t) 0x000000B2)
#define XBAND_FE_SET_SYS_MNGR_STANDBY_MODE_FUNCRESP_ID ((funcIdType_t) 0x000000B3)
#define XBAND_FE_SET_MOD_ALL_PARAMS_FUNCRESP_ID ((funcIdType_t) 0x000000BA)
#define XBAND_FE_GET_MOD_ALL_PARAMS_FUNCRESP_ID ((funcIdType_t) 0x000000BB)
#define XBAND_FE_SET_TX_POWER_FUNCRESP_ID ((funcIdType_t) 0x000000BD)
#define XBAND_FE_GET_TX_POWER_FUNCRESP_ID ((funcIdType_t) 0x000000BE)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    XBand FE configuration parameters
*/
typedef struct {
    uint8_t u8Target_output_power;
    uint8_t u8Pll_output_mux;
    uint8_t u8Pll_channel_divider_on_off;
    uint8_t u8Pll_channel_divider;
    uint32_t u32Pll_divider;
} PACKED_STRUCT XBAND_FE_ModCfgParams_t;

/*
    XBand FE NVM configuration parameters used by the OBC for the communication
*/
typedef struct {
    uint8_t u8Target_node_addr;
    uint8_t u8Port;
    uint8_t u8Prio;
    uint32_t u32Opts;
} PACKED_STRUCT XBAND_FE_ObcXBandFeNvmCfg_t;

/*
    Comm GW result code
*/
#define XBAND_FE_COMMRES_OK ((uint8_t) 0)
#define XBAND_FE_COMMRES_OK_PARTIAL ((uint8_t) 1)
#define XBAND_FE_COMMRES_ERR ((uint8_t) 2)
#define XBAND_FE_COMMRES_INVALID_ARGS ((uint8_t) 3)
#define XBAND_FE_COMMRES_SEND_ERR ((uint8_t) 4)
#define XBAND_FE_COMMRES_SND_TIMEOUT ((uint8_t) 5)
#define XBAND_FE_COMMRES_RCV_TIMEOUT ((uint8_t) 6)
#define XBAND_FE_COMMRES_MAX_CNT  ((uint8_t) 7)
typedef uint8_t XBAND_FE_CommRes_t;

/*
    XBand FE system state
*/
#define XBAND_FE_SYSSTATE_AFTER_RESET ((uint8_t) 1)
#define XBAND_FE_SYSSTATE_LOAD_MODE ((uint8_t) 2)
#define XBAND_FE_SYSSTATE_TX_MODE ((uint8_t) 3)
#define XBAND_FE_SYSSTATE_MAX_CNT  ((uint8_t) 4)
typedef uint8_t XBAND_FE_SysState_t;

/*
    TX power information returned by the XBand FE module
*/
typedef struct {
    uint8_t u8Tx_power;
} PACKED_STRUCT XBAND_FE_XBandFeTxPowerInfo_t;

/*
    XBand FE standard response codes
*/
#define XBAND_FE_STDRESPONSE_OK ((uint8_t) 0)
#define XBAND_FE_STDRESPONSE_SYS_ERR ((uint8_t) 1)
#define XBAND_FE_STDRESPONSE_MAX_CNT  ((uint8_t) 2)
typedef uint8_t XBAND_FE_StdResponse_t;

/*
    Response wrapper structure required for use by OBC manual code
*/
typedef struct {
    XBAND_FE_ModCfgParams_t sMod_params;
} PACKED_STRUCT XBAND_FE_ModCfgParamsWrapper_t;

/*
    XBand FE module status report parameters
*/
typedef struct {
    XBAND_FE_SysState_t eSystem_state;
    uint8_t u8Status_flags;
    int16_t i16Pa_temperature;
    int16_t i16Pa_pwr_det;
    uint16_t u16Powsup_5v_rf_drv;
    uint16_t u16Pa_idd;
    uint16_t u16Pa_vdd;
    uint16_t u16Powsup_5v_vco_drv;
    uint16_t u16Powsup_3v3_pll;
    uint16_t u16Powsup_5v_if_amp;
    uint16_t u16Powsup_5v_att;
    int16_t i16Pa_vgg;
    uint16_t u16Cpu_vdd;
    int16_t i16Cpu_temperature;
    uint16_t u16Adc_vref_internal;
    uint32_t u32Fw_version;
} PACKED_STRUCT XBAND_FE_ModStatusReportParams_t;

/*
    Response wrapper structure required for use by OBC manual code
*/
typedef struct {
    XBAND_FE_XBandFeTxPowerInfo_t sPwr_info;
} PACKED_STRUCT XBAND_FE_XBandFeTxPowerInfoWrapper_t;

/*
    Response wrapper structure required for use by OBC manual code
*/
typedef struct {
    XBAND_FE_StdResponse_t eStd_resp;
} PACKED_STRUCT XBAND_FE_StdResponseWrapper_t;

/*
    Response wrapper structure required for use by OBC manual code
*/
typedef struct {
    XBAND_FE_ModStatusReportParams_t sStatus_report;
} PACKED_STRUCT XBAND_FE_ModStatusReportParamsWrapper_t;


typedef struct {
    XBAND_FE_ObcXBandFeNvmCfg_t sNvm_params_in;
} PACKED_STRUCT xband_feset_obc_xband_fe_nvm_cfgRequestData_t;

typedef struct {
    XBAND_FE_ModCfgParams_t sCfg_params;
} PACKED_STRUCT xband_feset_mod_all_paramsRequestData_t;

typedef struct {
    uint8_t u8Tx_power;
} PACKED_STRUCT xband_feset_tx_powerRequestData_t;


typedef struct {
    XBAND_FE_ObcXBandFeNvmCfg_t sNvm_params;
} PACKED_STRUCT xband_feget_obc_xband_fe_nvm_cfgResponseData_t;

typedef struct {
    bool bSuccess;
} PACKED_STRUCT xband_feset_obc_xband_fe_nvm_cfgResponseData_t;

typedef struct {
    XBAND_FE_CommRes_t eComm_res;
    XBAND_FE_ModStatusReportParamsWrapper_t sStatus_params;
} PACKED_STRUCT xband_feget_status_reportResponseData_t;

typedef struct {
    XBAND_FE_CommRes_t eComm_res;
    XBAND_FE_StdResponseWrapper_t sCmd_resp;
} PACKED_STRUCT xband_feset_sys_mngr_run_modeResponseData_t;

typedef struct {
    XBAND_FE_CommRes_t eComm_res;
    XBAND_FE_StdResponseWrapper_t sCmd_resp;
} PACKED_STRUCT xband_feset_sys_mngr_standby_modeResponseData_t;

typedef struct {
    XBAND_FE_CommRes_t eComm_res;
    XBAND_FE_StdResponseWrapper_t sCmd_resp;
} PACKED_STRUCT xband_feset_mod_all_paramsResponseData_t;

typedef struct {
    XBAND_FE_CommRes_t eComm_res;
    XBAND_FE_ModCfgParamsWrapper_t sCfg_params;
} PACKED_STRUCT xband_feget_mod_all_paramsResponseData_t;

typedef struct {
    XBAND_FE_CommRes_t eComm_res;
    XBAND_FE_StdResponseWrapper_t sCmd_resp;
} PACKED_STRUCT xband_feset_tx_powerResponseData_t;

typedef struct {
    XBAND_FE_CommRes_t eComm_res;
    XBAND_FE_XBandFeTxPowerInfoWrapper_t sTx_power_info;
} PACKED_STRUCT xband_feget_tx_powerResponseData_t;


#endif  // #ifndef FP_XBAND_FEPROTOCOLTYPES_H

