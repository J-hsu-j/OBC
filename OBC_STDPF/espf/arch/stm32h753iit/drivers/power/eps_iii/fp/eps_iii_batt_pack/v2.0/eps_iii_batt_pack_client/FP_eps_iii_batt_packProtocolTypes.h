/*!
********************************************************************************************
* @file FP_eps_iii_batt_packProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface eps_iii_batt_pack v2.0
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

#ifndef FP_EPS_III_BATT_PACKPROTOCOLTYPES_H
#define FP_EPS_III_BATT_PACKPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_EPS_III_BATT_PACK ((uint16_t) (0x000000B0))

#define EPS_III_BATT_PACK_GET_TELEMETRY_FUNC_ID ((funcIdType_t) 0x00000000)
#define EPS_III_BATT_PACK_GET_TELEMETRY_FUNCRESP_ID ((funcIdType_t) 0x00000000)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    Common measurements
*/
typedef struct {
    uint16_t u16Mcu_volt;
    int32_t i32Mcu_temp;
    uint16_t u16Sys_bus_volt;
} PACKED_STRUCT EPS_III_BATT_PACK_CommonMeasurement_t;

/*
    Current status of the channel. OFF, ON or unknown
*/
#define EPS_III_BATT_PACK_ONOFFSTATUS_OFF ((uint8_t) 0)
#define EPS_III_BATT_PACK_ONOFFSTATUS_ON ((uint8_t) 1)
#define EPS_III_BATT_PACK_ONOFFSTATUS_UNKNOWN ((uint8_t) 2)
#define EPS_III_BATT_PACK_ONOFFSTATUS_MAX_CNT  ((uint8_t) 3)
typedef uint8_t EPS_III_BATT_PACK_OnOffStatus_t;

/*
    Exact measured values like voltages, currents, temperatures
*/
typedef struct {
    uint16_t u16V_batt;
    int16_t i16I_batt;
    uint8_t u8Soc_batt;
    uint16_t u16V_batt_cell_1;
    uint16_t u16V_batt_cell_2;
    uint16_t u16V_batt_cell_3;
    uint16_t u16V_batt_cell_4;
    int32_t i32T_batt;
    int32_t i32P_heater_1;
    int32_t i32P_heater_2;
    uint16_t u16V_buss_7_5V;
    uint16_t u16V_buss_3_3V;
} PACKED_STRUCT EPS_III_BATT_PACK_Measurements_t;

/*
    Command status
*/
#define EPS_III_BATT_PACK_COMMANDSTATUS_SUCCESS ((uint8_t) 0)
#define EPS_III_BATT_PACK_COMMANDSTATUS_FAIL ((uint8_t) 1)
#define EPS_III_BATT_PACK_COMMANDSTATUS_FAIL_GATHERING_DATA ((uint8_t) 2)
#define EPS_III_BATT_PACK_COMMANDSTATUS_MAX_CNT  ((uint8_t) 3)
typedef uint8_t EPS_III_BATT_PACK_CommandStatus_t;

/*
    Seconds converted into days, hours, minutes, and seconds
*/
typedef struct {
    uint16_t u16Days;
    uint8_t u8Hours;
    uint8_t u8Minutes;
    uint8_t u8Seconds;
} PACKED_STRUCT EPS_III_BATT_PACK_UptimeConverted_t;

/*
    all states concerning the charging algorithms
*/
typedef struct {
    EPS_III_BATT_PACK_OnOffStatus_t eCharge;
    EPS_III_BATT_PACK_OnOffStatus_t eCharging_voltage_ok;
    EPS_III_BATT_PACK_OnOffStatus_t eBattery_dead;
    EPS_III_BATT_PACK_OnOffStatus_t eBattery_over_voltage_prot;
    EPS_III_BATT_PACK_OnOffStatus_t eBattery_slow_charging;
    EPS_III_BATT_PACK_OnOffStatus_t eCharging_current_flow;
    uint16_t u16Charge_current;
    EPS_III_BATT_PACK_OnOffStatus_t eValid_input_voltage;
} PACKED_STRUCT EPS_III_BATT_PACK_ChargeOnStatus_t;

/*
    all states concerning the battery cells
*/
typedef struct {
    EPS_III_BATT_PACK_OnOffStatus_t eBalance_cell_1;
    EPS_III_BATT_PACK_OnOffStatus_t eBalance_cell_2;
    EPS_III_BATT_PACK_OnOffStatus_t eBalance_cell_3;
    EPS_III_BATT_PACK_OnOffStatus_t eBalance_cell_4;
} PACKED_STRUCT EPS_III_BATT_PACK_BatteryCellsStatus_t;

/*
    all states concerning the heaters
*/
typedef struct {
    EPS_III_BATT_PACK_OnOffStatus_t eHeater;
    EPS_III_BATT_PACK_OnOffStatus_t eHeater_under_5_deg_c;
    EPS_III_BATT_PACK_OnOffStatus_t eBattery_dead;
    EPS_III_BATT_PACK_OnOffStatus_t eBattery_alert;
} PACKED_STRUCT EPS_III_BATT_PACK_HeatersStatus_t;

/*
    all states concerning the discharging algorithms
*/
typedef struct {
    EPS_III_BATT_PACK_OnOffStatus_t eDischarge;
    EPS_III_BATT_PACK_OnOffStatus_t eBattery_Overdischarge;
    EPS_III_BATT_PACK_OnOffStatus_t eBattery_dead;
    EPS_III_BATT_PACK_OnOffStatus_t eBattery_ocp_charge;
    EPS_III_BATT_PACK_OnOffStatus_t eBattery_ocp_discharge;
    EPS_III_BATT_PACK_OnOffStatus_t eDischarge_switch_over_heat_prot;
    int32_t i32Discharge_switch_over_heat_temp;
    EPS_III_BATT_PACK_OnOffStatus_t eBattery_overheat;
    int32_t i32T_batt;
    EPS_III_BATT_PACK_OnOffStatus_t eV_buss_7_5v_error_flag;
    EPS_III_BATT_PACK_OnOffStatus_t eCharge;
    EPS_III_BATT_PACK_OnOffStatus_t eCharging_current_flow;
    EPS_III_BATT_PACK_OnOffStatus_t eCharging_voltage_ok;
} PACKED_STRUCT EPS_III_BATT_PACK_DischargeState_t;

/*
    all states concerning the algorithms of HIB mode
*/
typedef struct {
    EPS_III_BATT_PACK_OnOffStatus_t eHib_mode_en;
    EPS_III_BATT_PACK_OnOffStatus_t eBattery_dead;
    EPS_III_BATT_PACK_OnOffStatus_t eBattery_low;
    EPS_III_BATT_PACK_OnOffStatus_t eBattery_temp_low;
} PACKED_STRUCT EPS_III_BATT_PACK_HIBModeStatus_t;

/*
    all states concerning the balancers
*/
typedef struct {
    EPS_III_BATT_PACK_OnOffStatus_t eBalancer;
    EPS_III_BATT_PACK_OnOffStatus_t eBalancer_voltage_ok;
    EPS_III_BATT_PACK_OnOffStatus_t eCharging_current_flow;
} PACKED_STRUCT EPS_III_BATT_PACK_BalancersStatus_t;



typedef struct {
    EPS_III_BATT_PACK_CommandStatus_t eCommand_status;
    uint32_t u32Uptime_in_seconds;
    EPS_III_BATT_PACK_UptimeConverted_t sUptime_converted;
    EPS_III_BATT_PACK_CommonMeasurement_t sCommon;
    EPS_III_BATT_PACK_HIBModeStatus_t sHib_mode_status;
    EPS_III_BATT_PACK_Measurements_t sMeasurements;
    EPS_III_BATT_PACK_DischargeState_t sDischarging_state;
    EPS_III_BATT_PACK_ChargeOnStatus_t sCharge_status;
    EPS_III_BATT_PACK_BalancersStatus_t sBalancers_status;
    EPS_III_BATT_PACK_BatteryCellsStatus_t sBattery_cells_status;
    EPS_III_BATT_PACK_HeatersStatus_t sHeaters_status;
} PACKED_STRUCT eps_iii_batt_packget_telemetryResponseData_t;


#endif  // #ifndef FP_EPS_III_BATT_PACKPROTOCOLTYPES_H

