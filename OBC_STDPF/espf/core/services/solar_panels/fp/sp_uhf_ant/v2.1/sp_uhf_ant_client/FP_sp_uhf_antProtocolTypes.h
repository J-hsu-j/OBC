/*!
********************************************************************************************
* @file FP_sp_uhf_antProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface sp_uhf_ant v2.1
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

#ifndef FP_SP_UHF_ANTPROTOCOLTYPES_H
#define FP_SP_UHF_ANTPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_SP_UHF_ANT ((uint16_t) (0x00000012))

#define SP_UHF_ANT_TELEMETRY_FUNC_ID ((funcIdType_t) 0x00000500)
#define SP_UHF_ANT_TELEMETRY_FUNCRESP_ID ((funcIdType_t) 0x00000500)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    List of feedbacks regarding validation of the data
*/
#define SP_UHF_ANT_DATAVLD_SUCCESS ((uint8_t) 0)
#define SP_UHF_ANT_DATAVLD_NO_RESPONCE ((uint8_t) 1)
#define SP_UHF_ANT_DATAVLD_NOT_SUPPORTED ((uint8_t) 2)
#define SP_UHF_ANT_DATAVLD_MAX_CNT  ((uint8_t) 3)
typedef uint8_t SP_UHF_ANT_DataVld_t;

/*
    Structure that provides the data from all Sun sensors.
*/
typedef struct {
    uint16_t u16Sun_data_main;
    SP_UHF_ANT_DataVld_t eSun_vld_main;
    uint16_t u16Sun_data_ext;
    SP_UHF_ANT_DataVld_t eSun_vld_ext;
} PACKED_STRUCT SP_UHF_ANT_SunSensors_t;

/*
    Structure that provides the data from all Temperature sensors.
*/
typedef struct {
    int16_t i16Temp_data_main;
    SP_UHF_ANT_DataVld_t eTemp_vld_main;
    int16_t i16Temp_data_ext1;
    SP_UHF_ANT_DataVld_t eTemp_vld_ext1;
    int16_t i16Temp_data_ext2;
    SP_UHF_ANT_DataVld_t eTemp_vld_ext2;
    int16_t i16Temp_data_mcu;
    SP_UHF_ANT_DataVld_t eTemp_vld_mcu;
} PACKED_STRUCT SP_UHF_ANT_TempSensors_t;

/*
    Structure that provides the data from Sun and Temperature data.
*/
typedef struct {
    uint32_t u32Uptime;
    SP_UHF_ANT_SunSensors_t sSun_data;
    SP_UHF_ANT_TempSensors_t sTemp_data;
} PACKED_STRUCT SP_UHF_ANT_AllTelemetry_t;



typedef struct {
    SP_UHF_ANT_AllTelemetry_t sData;
} PACKED_STRUCT sp_uhf_anttelemetryResponseData_t;


#endif  // #ifndef FP_SP_UHF_ANTPROTOCOLTYPES_H

