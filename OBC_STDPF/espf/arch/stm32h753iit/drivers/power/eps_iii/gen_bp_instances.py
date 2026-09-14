from jinja2 import Template
import re
import sys

def print_and_increment(value):
    result = value[0] 
    value[0] += 1
    return hex(result)

fidl_template = """
{%      for instance_id in range(config.inst_count) %}
//
// Global declarations for EPS BP INSTANCE{{instance_id}}
//    
    <** @description: Number of seconds since last power up **>
    struct Eps3Inst{{instance_id}}_UpTimeInSecondsType
    {
        <** @description: time in seconds **>
        UInt32 seconds
    }

    <** @description: Common measurements **>
    struct Eps3Inst{{ instance_id }}CommonMeasurementType
    {
        <** @description: MCU Voltage **>
        UInt16 mcu_volt
        
        <** @description: MCU Temperature **>
        Int32 mcu_temp
        
        <** @description: BUS Voltage **>
        UInt16 sys_bus_volt
    }
    
    <** @description: all states concerning the algorithms of HIB mode **>
    struct Eps3Inst{{ instance_id }}HIBModeStatusType
    {
        <** @description: HIB mode enabled 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 hib_mode_en
        
        <** @description: Signal Battery is Dead. In this condition the battery is disconnected 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 battery_dead
        
        <** @description: Signal Battery is OK 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 battery_low
        
        <** @description: Signal Battery temperature too low
            0 - inactive
            1 - active
            2 - status is unknown  **>
        UInt8 battery_temp_low
    }

    <** @description: Exact measured values like voltages, currents, temperatures **>
    struct Eps3Inst{{ instance_id }}MeasurementsType
    {
        <** @description: Voltage of the battery [mV] **>
        UInt16 v_batt

        <** @description: Current flowing through the battery [mA] **>
        Int16 i_batt
        
        <** @description: Battery charge level [%] **>
        UInt8 soc_batt        
                    
        <** @description: Voltage of Cell 1 of the Battery Pack [mV] **>
        UInt16 v_batt_cell_1
                    
        <** @description: Voltage of Cell 2 of the Battery Pack [mV] **>
        UInt16 v_batt_cell_2
                    
        <** @description: Voltage of Cell 3 of the Battery Pack [mV] **>
        UInt16 v_batt_cell_3
                    
        <** @description: Voltage of Cell 4 of the Battery Pack [mV] **>
        UInt16 v_batt_cell_4
        
        <** @description: Battery temperature [mdegC] **>
        Int32 t_batt
        
        <** @description: Power of heater 1 [mW] **>
        Int32 p_heater_1
        
        <** @description: Power of heater 2 [mW] **>
        Int32 p_heater_2
        
        <** @description: Voltage on 7.5V buss [mV] **>
        UInt16 v_buss_7_5V
        
        <** @description: Voltage on 3.3V buss [mV] **>
        UInt16 v_buss_3_3V
    }

    <** @description: all states concerning the discharging algorithms **>
    struct Eps3Inst{{ instance_id }}DischargeStateType
    {
        <** @description: Discharge disabled
            0 - inactive
            1 - active
            2 - status is unknown  **>
        UInt8 discharge
        
        <** @description: Signal Battery is at Low voltage 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 battery_low
        
        <** @description: Signal Battery is Dead 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 battery_dead
    
        <** @description: Signal for Overcurrent protection on the charging line 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 battery_ocp_charge
        
        <** @description: Signal for Overcurrent protection on the discharging line  
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 battery_ocp_discharge
        
        <** @description: Signal for triggered overheat protection of the discharge switches 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 discharge_switch_over_heat_prot
        
        <** @description: Tempeture of the discharge switches **>
        Int32 discharge_switch_over_heat_temp
        
        <** @description: Signal for overheating battery 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 battery_overheat
        
        <** @description: Battery temperature [millidegree Celsius] **>
        Int32 t_batt
        
        <** @description: Signal The voltage level on 7.5V bus is out of the acceptable values
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 v_buss_7_5v_error_flag
        
        <** @description: Charging the battery 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 charge_mode_en
        
        <** @description: Signal detected current flowing to the battery
            0 - inactive
            1 - active
            2 - status is unknown  **>
        UInt8 charging_current_flow
        
        <** @description: Signal Charging voltage is good for charging
            0 - inactive
            1 - active
            2 - status is unknown  **>
        UInt8 charging_voltage_ok
    }


    <** @description: all states concerning the charging algorithms **>
    struct Eps3Inst{{ instance_id }}ChargeOnStatusType
    {
        <** @description: Charging of the battery is started 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 battery_charging_on
        
        <** @description: Signal Charging voltage is good for charging 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 charging_voltage_ok
        
        <** @description: Signal Battery is Dead 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 battery_dead
        
        <** @description: Signal Over voltage protection 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 battery_over_voltage_prot
        
        <** @description: Signal Charging is in slow mode 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 battery_slow_charging
        
        <** @description: Signal detected current flowing to the battery 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 charging_current_flow
        
        <** @description: Value of the current in [mA] **>
        UInt16 charge_current
        
        <** @description: Gives if the the voltage level is correct 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 valid_input_voltage
    }    
    
    <** @description: all states concerning the balancers **>
    struct Eps3Inst{{ instance_id }}BalancersStatusType
    {
        <** @description: Signal Balancer enabled
            0 - inactive
            1 - active
            2 - status is unknown  **>
        UInt8 balancer_on
        
        <** @description: Signal Balancer enabled 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 balancer_voltage_ok
        
        <** @description: Signal detected current flowing to the battery 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 charging_current_flow
    }
    
    <** @description: all states concerning the battery cells **>
    struct Eps3Inst{{ instance_id }}BatteryCellsStatusType
    {
        <** @description: Signal Balancing Cell 1 Enabled 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 balance_cell_1_en
        
        <** @description: Signal Balancing Cell 2 Enabled 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 balance_cell_2_en
        
        <** @description: Signal Balancing Cell 3 Enabled 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 balance_cell_3_en
        
        <** @description: Signal Balancing Cell 4 Enabled 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 balance_cell_4_en
    }
    
    <** @description: all states concerning the heaters **>
    struct Eps3Inst{{ instance_id }}HeatersStatusType
    {
        <** @description: Signal Battery heater enabled 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 heater_en
        
        <** @description: Signal Battery temperature is below 5 degC 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 heater_under_5_deg_c
        
        <** @description: Signal Battery is Dead 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 battery_dead
        
        <** @description: Alert signal for the battery (variouse events can be configured) 
            0 - inactive
            1 - active
            2 - status is unknown **>
        UInt8 battery_alert
    }    

    <** @description: Input determening the thruster command execution status **>
    struct Eps3Inst{{ instance_id }}_FDIR_CMD_EXEC_STATUS_type
    {
        <** @description: Error code from EPSII_BP_1_GetBatteryInfo command **>
        UInt8 eps_iii_batt_pack_get_telemetry_ErrorCode
    }
{%-     endfor %}    
"""

fdepl_template = """
{%      for instance_id in range(config.inst_count) %}
//
// Global declarations for EPS BP INSTANCE{{instance_id}}
//  
    attribute EPS3_BP_INST{{ instance_id }}_uptime_in_seconds { Status_timeout = 30000 }  
    attribute EPS3_BP_INST{{ instance_id }}common { Status_timeout = 30000 }
    attribute EPS3_BP_INST{{ instance_id }}hib_mode_status { Status_timeout = 30000 }
    attribute EPS3_BP_INST{{ instance_id }}measurements { Status_timeout = 30000 }
    attribute EPS3_BP_INST{{ instance_id }}discharging_state { Status_timeout = 30000 }
    attribute EPS3_BP_INST{{ instance_id }}charge_status { Status_timeout = 30000 }
    attribute EPS3_BP_INST{{ instance_id }}balancers_status { Status_timeout = 30000 }
    attribute EPS3_BP_INST{{ instance_id }}battery_cells_status { Status_timeout = 30000 }
    attribute EPS3_BP_INST{{ instance_id }}heaters_status { Status_timeout = 30000 }
    attribute EPS3_BP_INST{{ instance_id }}_CMD_EXEC_STATUS_Data { Status_timeout = 40000 }
{%-     endfor %}    
"""

datacache_fidl_template = """
{%      for instance_id in range(config.inst_count) %}
//
// Global declarations for EPS_III BP INSTANCE{{instance_id}}
//
    <** @description: number of seconds since last power up  
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3Inst{{instance_id}}_UpTimeInSecondsType EPS3_BP_INST{{ instance_id }}_uptime_in_seconds


    <** @description: MCU mesurments voltage and temprature
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3Inst{{ instance_id }}CommonMeasurementType EPS3_BP_INST{{ instance_id }}common
    
    <** @description: Statuses related to HIB mode
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3Inst{{ instance_id }}HIBModeStatusType EPS3_BP_INST{{ instance_id }}hib_mode_status
    
    <** @description: Exact measured values on the device
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3Inst{{ instance_id }}MeasurementsType EPS3_BP_INST{{ instance_id }}measurements
    
    <** @description: Statuses related to the discharging process
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3Inst{{ instance_id }}DischargeStateType EPS3_BP_INST{{ instance_id }}discharging_state
    
    <** @description: Statuses related to the charging process
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3Inst{{ instance_id }}ChargeOnStatusType EPS3_BP_INST{{ instance_id }}charge_status
    
    <** @description: Statuses related to the balancers
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3Inst{{ instance_id }}BalancersStatusType EPS3_BP_INST{{ instance_id }}balancers_status
    
    <** @description: Statuses related to the battery cells
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3Inst{{ instance_id }}BatteryCellsStatusType EPS3_BP_INST{{ instance_id }}battery_cells_status
    
    <** @description: Statuese related to the heaters of the batteries
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3Inst{{ instance_id }}HeatersStatusType  EPS3_BP_INST{{ instance_id }}heaters_status
    
    <** @description: EPS III communication execution status
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3Inst{{ instance_id }}_FDIR_CMD_EXEC_STATUS_type EPS3_BP_INST{{ instance_id }}_CMD_EXEC_STATUS_Data
    
{%-     endfor %}    
"""

cfg_code_template = """
#define EPS_III_BP_CFG                                                                                            \\{% for instance_id in range(config.inst_count) %}
    {                                                                                                             \\
        .base.eps_dev_info.p_dev_init            = &eps_dev_init,                                                 \\
        .base.eps_dev_info.p_is_seq_expected     = &eps_dev_is_seq_expected,                                      \\
        .base.eps_dev_info.esps_dev_info         = { {{ instance_id }}, 1, 0 },                                                   \\
        .base.eps_dev_info.p_process_fdir_faults = &eps_iii_bp_process_fdir_faults,                               \\
        .base.eps_dev_info.datacache_cmd_list    = bp_datacache_cmd_list[EPS_III_BP_INST{{ instance_id }}],                       \\
        .base.eps_dev_info.cmd_list_cnt          = EPS_III_BP_DATACACHE_CMD_COUNT,                                \\
        .base.eps_dev_info.p_fdir_exec_status    = (fault_exec_status_t *)&bp_fdir_exec_status[EPS_III_BP_INST{{ instance_id }}], \\
        .base.eps_dev_info.fault_exec_status_cnt = EPS_III_BP_CMD_CNT,                                            \\
        .base.eps_dev_info.fdir_fault_ids        = bp_fdir_fault_ids[EPS_III_BP_INST{{ instance_id }}],                           \\
        .base.p_init                             = (p_init_t)&eps_iii_bp_init,                                    \\
        .tlm.p_device_info                       = (eps_dev_t *)eps_dev_base[EPS_III_DEV_BP_INST{{ instance_id }}],               \\
        .tlm.tlm_cfg                             = {                                                              \\
                EPSIII_BP_INST{{ instance_id }}_DELAY_BETWEEN_SENDING,                                                            \\
                EPSIII_BP_INST{{ instance_id }}_MAX_MESSAGES_TO_SEND                                                              \\
        },                                                                                                        \\
        .tlm.p_get_telemetry                     = &tlm_dev_get_telemetry,                                        \\
        .tlm.p_tlm_req_cmds                      = &bp_tlm_req_cmds[0],                                           \\
        .tlm.tlm_cmd_cnt                         = BP_TLM_CMD_CNT                                                 \\
    }\
{% if not loop.last %}\
,                                                                                                            \\\
{% endif %}
{%-     endfor %}

#define EPS_III_BP_DEV_INSTANCES_CFG                                     \\{% for instance_id in range(config.inst_count) %}
    (eps_dev_base_t *)&bp_modules[EPS_III_BP_INST{{ instance_id }}]{% if not loop.last %},    \\{% endif %}                      
{%-     endfor %}

#define EPS_III_BP_TLM_INST_CFG                                          \\{% for instance_id in range(config.inst_count) %}
    &bp_modules[EPS_III_BP_INST{{ instance_id }}].tlm{% if not loop.last %},                  \\{% endif %}                      
{%-     endfor %}
"""

cfg_bp_inst_enum_code_template = """
#define EPS_III_BP_INST_CFG                                 \\\
{% for instance_id in range(config.inst_count) %}
    EPS_III_BP_INST{{ instance_id }}\
{% if not loop.last %}\
,                                       \\\
{% endif %}
{%-     endfor %}
"""

cfg_dev_inst_enum_code_template = """
#define EPS_III_DEV_BP_INST_CFG                             \\\
{% for instance_id in range(config.inst_count) %}
    EPS_III_DEV_BP_INST{{ instance_id }}\
{% if not loop.last %}\
,                                     \\\
{% endif %}
{%-     endfor %}
"""

cfg_datacache_lists_code_template = """
#define EPS_III_BP_DATACACHE_LIST_CMD                       \\{% for instance_id in range(config.inst_count) %}
    {                                                       \\
        DC_DID_EPS3_BP_INST{{ instance_id }}_UPTIME_IN_SECONDS,             \\
        DC_DID_EPS3_BP_INST{{ instance_id }}COMMON,                         \\
        DC_DID_EPS3_BP_INST{{ instance_id }}HIB_MODE_STATUS,                \\
        DC_DID_EPS3_BP_INST{{ instance_id }}MEASUREMENTS,                   \\
        DC_DID_EPS3_BP_INST{{ instance_id }}DISCHARGING_STATE,              \\
        DC_DID_EPS3_BP_INST{{ instance_id }}CHARGE_STATUS,                  \\
        DC_DID_EPS3_BP_INST{{ instance_id }}BALANCERS_STATUS,               \\
        DC_DID_EPS3_BP_INST{{ instance_id }}BATTERY_CELLS_STATUS,           \\
        DC_DID_EPS3_BP_INST{{ instance_id }}HEATERS_STATUS,                 \\
        DC_DID_EPS3_BP_INST{{ instance_id }}_CMD_EXEC_STATUS_DATA           \\
    }{% if not loop.last %},                                                      \\{% endif %}
{%-     endfor %}
"""

cfg_fdir_faults_code_template = """
#define EPS_III_BP_FDIR_FAULTS_IDS                          \\{% for instance_id in range(config.inst_count) %}
    {                                                       \\
        FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_CMD_EXEC_FAILURE,        \\
        FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_BATT_VOLTAGE_BELOW_SAFE, \\
        FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_BATT_TEMP_BELOW_SAFE,    \\
        FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_BATT_TEMP_ABOVE_SAFE     \\
    }{% if not loop.last %},                                                      \\{% endif %}
{%-     endfor %}
"""


obc_fidl_template =  """{%      for instance_id in range(config.inst_count) %}
        <** @description:  EPSIII BP ID  **>
        EPSIII_BP_{{ instance_id }}{% if not loop.last %},{% endif %}
{%-     endfor %}        
"""

nvm_app_defaults_template =  """{%for instance_id in range(config.inst_count)%}\
        {{increment(mac_address)}}, // MAC_ADDR_EPS BP INST{{ instance_id }}{% if not loop.last %}{{"\n"}}{% endif %}
{%-     endfor %}
"""

fdir_srv_cfg_h_template = """{% for instance_id in range(config.inst_count) %}
    FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_CMD_EXEC_FAILURE,
    FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_BATT_VOLTAGE_BELOW_SAFE,
    FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_BATT_TEMP_BELOW_SAFE,
    FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_BATT_TEMP_ABOVE_SAFE,
{%-     endfor %}
"""

fdir_srv_cfg_c_template = """{% for instance_id in range(config.inst_count) %}
    [FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_CMD_EXEC_FAILURE]           = "FDIR_EPSIII_BP_INST{{ instance_id }}_CMD_EXEC_FAILURE",
    [FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_BATT_VOLTAGE_BELOW_SAFE]    = "FDIR_EPSIII_BP_INST{{ instance_id }}_BATT_VOLTAGE_BELOW_SAFE",
    [FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_BATT_TEMP_BELOW_SAFE]       = "FDIR_EPSIII_BP_INST{{ instance_id }}_BATT_TEMP_BELOW_SAFE",
    [FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_BATT_TEMP_ABOVE_SAFE]       = "FDIR_EPSIII_BP_INST{{ instance_id }}_BATT_TEMP_ABOVE_SAFE",        
{%-     endfor %}
"""

fdir_srv_cfg_c_template2 = """{% for instance_id in range(config.inst_count) %}
    [FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_CMD_EXEC_FAILURE]           = { .fdir_level = FDIR_EPSIII_BP_INST{{ instance_id }}_CMD_EXEC_FAILURE_LEVEL,         .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_BATT_VOLTAGE_BELOW_SAFE]    = { .fdir_level = FDIR_EPSIII_BP_INST{{ instance_id }}_BATT_VOLTAGE_BELOW_SAFE_LEVEL,  .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_BATT_TEMP_BELOW_SAFE]       = { .fdir_level = FDIR_EPSIII_BP_INST{{ instance_id }}_BATT_TEMP_BELOW_SAFE_LEVEL,     .p_action_func = NULL,                         .p_escalated_action = NULL                   },
    [FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_BATT_TEMP_ABOVE_SAFE]       = { .fdir_level = FDIR_EPSIII_BP_INST{{ instance_id }}_BATT_TEMP_ABOVE_SAFE_LEVEL,     .p_action_func = NULL,                         .p_escalated_action = NULL                   },
{%-     endfor %}
"""


nvm_app_FDIR_defaults_template =  """{% for instance_id in range(config.inst_count) %}
        [FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_CMD_EXEC_FAILURE] = FDIR_EPSIII_BP_INST{{ instance_id }}_CMD_EXEC_FAILURE_DETECTION_STATE,
        [FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_BATT_VOLTAGE_BELOW_SAFE] = FDIR_EPSIII_BP_INST{{ instance_id }}_BATT_VOLTAGE_BELOW_SAFE_DETECTION_STATE,
        [FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_BATT_TEMP_BELOW_SAFE] = FDIR_EPSIII_BP_INST{{ instance_id }}_BATT_TEMP_BELOW_SAFE_DETECTION_STATE,
        [FDIR_FAULT_EPSIII_BP_INST{{ instance_id }}_BATT_TEMP_ABOVE_SAFE] = FDIR_EPSIII_BP_INST{{ instance_id }}_BATT_TEMP_ABOVE_SAFE_DETECTION_STATE,
{%-     endfor %}
"""


j2_fidl_template = Template(fidl_template)
j2_fdepl_template = Template(fdepl_template)
j2_datacache_fidl_template = Template(datacache_fidl_template)
j2_cfg_code_template = Template(cfg_code_template)
j2_cfg_bp_inst_enum_code_template = Template(cfg_bp_inst_enum_code_template)
j2_cfg_dev_inst_enum_code_template = Template(cfg_dev_inst_enum_code_template)
j2_cfg_datacache_lists_code_template = Template(cfg_datacache_lists_code_template)
j2_cfg_fdir_faults_code_template = Template(cfg_fdir_faults_code_template)
j2_obc_fidl_template = Template(obc_fidl_template)
j2_nvm_app_defaults_template = Template(nvm_app_defaults_template)
j2_nvm_app_FDIR_defaults_template = Template(nvm_app_FDIR_defaults_template)
j2_fdir_srv_cfg_h_template = Template(fdir_srv_cfg_h_template)
j2_fdir_srv_cfg_c_template = Template(fdir_srv_cfg_c_template)

import re

def replace_section_in_file(file_path, new_content, begin_marker, end_marker):
    # Read the content of the file
    with open(file_path, 'r') as file:
        content = file.read()

    # Create the regex pattern to match the section
    pattern = re.compile(f"{begin_marker}.*?{end_marker}", re.DOTALL)

    # Replace the matched section with the new content
    new_section = f"{begin_marker}\n{new_content}\n{end_marker}"
    modified_content = pattern.sub(new_section, content)

    # Write the modified content back to the file
    with open(file_path, 'w') as file:
        file.write(modified_content)

def find_largest_id(filename):
    # Regular expression pattern to find lines with @details: id = 0x...
    pattern = re.compile(r'@details:\s+id\s+=\s+0x([0-9A-Fa-f]+)')

    max_id = None

    with open(filename, 'r') as file:
        for line in file:
            match = re.search(pattern, line)
            if match:
                current_id = int(match.group(1), 16)  # Convert hex string to integer
                if max_id is None or current_id > max_id:
                    max_id = current_id

    if max_id is not None:
        return max_id
    else:
        return None

if __name__ == "__main__":
    import sys
    if len(sys.argv) != 8:
        print(f"Usage: {sys.argv[0]} <inst_count> <datacache_folder> <cfg_code_file> <nvm_eps_fidl_file_path>")
        sys.exit(1)
 
    inst_count = int(sys.argv[1])
    fidl_file_path = sys.argv[2]+"/DataCacheTypes.fidl"
    fdepl_file_path = sys.argv[2]+"/deploy_dc.fdepl"
    datacache_fidl_file_path = sys.argv[2] + "/DataCache.fidl"  
    cfg_code_file = sys.argv[3]
    nvm_eps_fidl_file = sys.argv[4]
    nvm_app_defs_file = sys.argv[5]
    fdir_srv_cfg_h_file = sys.argv[6]
    fdir_srv_cfg_c_file = sys.argv[7]
    
    data = {
        "config": {"inst_count": inst_count, 
                   "charger_ids" : ["Xp", "Xr", "Yp", "Yr", "Zp", "Zr"]}
        
    }
    
    replace_section_in_file(fidl_file_path, j2_fidl_template.render(data),"// begin EPS_III BP generated code","// end EPS_III BP generated code")
    replace_section_in_file(fdepl_file_path, j2_fdepl_template.render(data),"// begin EPS_III BP generated code","// end EPS_III BP generated code")
    
    
    replace_section_in_file(datacache_fidl_file_path, "","// begin EPS_III BP generated code","// end EPS_III BP generated code")
    
    largest_data_id = find_largest_id(datacache_fidl_file_path)
        
    initial_value = [largest_data_id+1]
    
    replace_section_in_file(datacache_fidl_file_path, j2_datacache_fidl_template.render(data, datacache_data_id = initial_value, increment=print_and_increment),"// begin EPS_III BP generated code","// end EPS_III BP generated code")
    
    replace_section_in_file(cfg_code_file, j2_cfg_code_template.render(data),"// begin EPS_III BP cfg generated code","// end EPS_III BP cfg generated code")
    
    replace_section_in_file(cfg_code_file, j2_cfg_bp_inst_enum_code_template.render(data),"// begin EPS_III BP instances generated code","// end EPS_III BP instances generated code")

    replace_section_in_file(cfg_code_file, j2_cfg_dev_inst_enum_code_template.render(data),"// begin EPS_III BP dev instances generated code","// end EPS_III BP dev instances generated code")

    replace_section_in_file(cfg_code_file, j2_cfg_datacache_lists_code_template.render(data),"// begin EPS_III BP datacache lists generated code","// end EPS_III BP datacache lists generated code")

    replace_section_in_file(cfg_code_file, j2_cfg_fdir_faults_code_template.render(data),"// begin EPS_III BP FDIR FAULTs generated code","// end EPS_III BP FDIR FAULTs generated code")

    replace_section_in_file(nvm_eps_fidl_file, j2_obc_fidl_template.render(data),"// begin EPS_III BP generated code","// end EPS_III BP generated code")
    
    initial_mac_address = [0xB0]
    replace_section_in_file(nvm_app_defs_file, j2_nvm_app_defaults_template.render(data, mac_address = initial_mac_address, increment=print_and_increment),"// begin EPS_III BP generated code","// end EPS_III BP generated code")
    replace_section_in_file(nvm_app_defs_file, j2_nvm_app_FDIR_defaults_template.render(data),"// begin EPS_III BP FDIR generated code","// end EPS_III BP FDIR generated code")

    replace_section_in_file(fdir_srv_cfg_h_file, j2_fdir_srv_cfg_h_template.render(data),"// begin EPS_III BP generated code","// end EPS_III BP generated code")
    
    replace_section_in_file(fdir_srv_cfg_c_file, j2_fdir_srv_cfg_c_template.render(data),"// begin EPS_III BP generated code","// end EPS_III BP generated code")
    j2_fdir_srv_cfg_c_template = Template(fdir_srv_cfg_c_template2)
    replace_section_in_file(fdir_srv_cfg_c_file, j2_fdir_srv_cfg_c_template.render(data),"// begin EPS_III BP generated configuration","// end EPS_III BP generated configuration")

    
    
