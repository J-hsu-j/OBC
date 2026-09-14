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
// Global declarations for EPS INPUT_STAGE INSTANCE{{instance_id}}
//    
    <** @description: Number of seconds since last power up **>
    struct Eps3_INPUT_STAGE_Inst{{instance_id}}_UpTimeInSecondsType
    {
        <** @description: time in seconds **>
        UInt32 seconds
    }

    <** @description: Common measurements **>
    struct Eps3_INPUT_STAGE_Inst{{ instance_id }}CommonMeasurementType
    {
        <** @description: MCU Voltage **>
        UInt16 mcu_volt
        
        <** @description: MCU Temperature **>
        Int32 mcu_temp
        
        <** @description: BUS Voltage **>
        UInt16 sys_bus_volt
    }
    
    <** @description: Solar panel (SP1) input data **>
    struct Eps3_INPUT_STAGE_Inst{{ instance_id }}Sp1InputDataType
    {
        <** @description: Data from the MPPT for Solar Panel 1 **>
        VoltAllAmps sp_measurements
    
        <** @description: MPPT flag SRVO_INN for SP input
            0 - inactive
            1 - active
            2 - status is unknown  **>
        UInt8 input_current_state
        <** @description: MPPT flag SRVO_FBIN for SP input
            0 - inactive
            1 - active
            2 - status is unknown  **>
        UInt8 output_current_state
        <** @description: MPPT flag SRVO_FBOUT for SP input
            0 - inactive
            1 - active
            2 - status is unknown  **>
        UInt8 input_voltage_state
        <** @description: MPPT flag SRVO_IOUT for SP input
            0 - inactive
            1 - active
            2 - status is unknown  **>
        UInt8 output_voltage_state
        
        <** @description: Status of MPPT for SP input **>
        MpptState_str state_mppt
    }      

    <** @description: Solar panel (SP2) input data **>
    struct Eps3_INPUT_STAGE_Inst{{ instance_id }}Sp2InputDataType
    {
        <** @description: Data from the MPPT for Solar Panel 2 **>
        VoltAllAmps sp_measurements
    
        <** @description: MPPT flag SRVO_INN for SP input
            0 - inactive
            1 - active
            2 - status is unknown  **>
        UInt8 input_current_state
        <** @description: MPPT flag SRVO_FBIN for SP input
            0 - inactive
            1 - active
            2 - status is unknown  **>
        UInt8 output_current_state
        <** @description: MPPT flag SRVO_FBOUT for SP input
            0 - inactive
            1 - active
            2 - status is unknown  **>
        UInt8 input_voltage_state
        <** @description: MPPT flag SRVO_IOUT for SP input
            0 - inactive
            1 - active
            2 - status is unknown  **>
        UInt8 output_voltage_state
        
        <** @description: Status of MPPT for SP input **>
        MpptState_str state_mppt
    }      
    
    <** @description: Solar panel (SP3) input data **>
    struct Eps3_INPUT_STAGE_Inst{{ instance_id }}Sp3InputDataType
    {
        <** @description: Data from the MPPT for Solar Panel 2 **>
        VoltAllAmps sp_measurements
    
        <** @description: MPPT flag SRVO_INN for SP input
            0 - inactive
            1 - active
            2 - status is unknown  **>
        UInt8 input_current_state
        <** @description: MPPT flag SRVO_FBIN for SP input
            0 - inactive
            1 - active
            2 - status is unknown  **>
        UInt8 output_current_state
        <** @description: MPPT flag SRVO_FBOUT for SP input
            0 - inactive
            1 - active
            2 - status is unknown  **>
        UInt8 input_voltage_state
        <** @description: MPPT flag SRVO_IOUT for SP input
            0 - inactive
            1 - active
            2 - status is unknown  **>
        UInt8 output_voltage_state
        
        <** @description: Status of MPPT for SP input **>
        MpptState_str state_mppt
    }    
    
    <** @description: Voltage and Current measurements **>
    struct Eps3_INPUT_STAGE_Inst{{ instance_id }}SystemBusType
    {
        <** @description: Voltage in mV **>
        UInt16 voltage
        
        <** @description: Current in mA **>
        Int16 current
    }      

    <** @description: Voltage and Current measurements **>
    struct Eps3_INPUT_STAGE_Inst{{ instance_id }}Bus7v5Type
    {
        <** @description: Voltage in mV **>
        UInt16 voltage
        
        <** @description: Current in mA **>
        Int16 current
    }      

    <** @description: Voltage and Current measurements **>
    struct Eps3_INPUT_STAGE_Inst{{ instance_id }}Bbus3v3Type
    {
        <** @description: Voltage in mV **>
        UInt16 voltage
        
        <** @description: Current in mA **>
        Int16 current
    }  
    
    <** @description: Command execution statuses **>
    struct Eps3_INPUT_STAGE_Inst{{instance_id}}_FDIR_CMD_EXEC_STATUS_type
    {
        <** @description: Error code from execution of get_telemetry commmand **>
        UInt8 eps_iii_pdm_a_get_telemetry_ErrorCode
    }    
    
    <** @description: Current status of the channel. OFF, ON or unknown**>
    struct Eps3_INPUT_STAGE_Inst{{instance_id}}hib_mode_status_type
    {
        <** @description:  
            OFF - Current status is inactive
            ON  - Current status is active
            UNKONOWN - Current status is uknown **>
        UInt8 status
    }
    
    <** @description: Current status of the channel. OFF, ON or unknown**>
    struct Eps3_INPUT_STAGE_Inst{{instance_id}}selflock_on_type
    {
        <** @description:  
            OFF - Current status is inactive
            ON  - Current status is active
            UNKONOWN - Current status is uknown **>
        UInt8 status
    }
    
    <** @description: Current status of the channel. OFF, ON or unknown**>
    struct Eps3_INPUT_STAGE_Inst{{instance_id}}bus_7v5_power_good_type
    {
        <** @description:  
            OFF - Current status is inactive
            ON  - Current status is active
            UNKONOWN - Current status is uknown **>
        UInt8 status
    }
    
    <** @description: Current status of the channel. OFF, ON or unknown**>
    struct Eps3_INPUT_STAGE_Inst{{instance_id}}undervoltage_7V5_type
    {
        <** @description:  
            OFF - Current status is inactive
            ON  - Current status is active
            UNKONOWN - Current status is uknown **>
        UInt8 status
    }

    <** @description: Current status of the channel. OFF, ON or unknown**>
    struct Eps3_INPUT_STAGE_Inst{{instance_id}}undervoltage_3V3_type
    {
        <** @description:  
            OFF - Current status is inactive
            ON  - Current status is active
            UNKONOWN - Current status is uknown **>
        UInt8 status
    }
{%-     endfor %}    
"""

fdepl_template = """
{%      for instance_id in range(config.inst_count) %}
//
// Global declarations for EPS INPUT_STAGE INSTANCE{{instance_id}}
//    
    attribute EPS3_INPUT_STAGE_INST{{ instance_id }}_uptime_in_seconds { Status_timeout = 30000 }
    attribute EPS3_INPUT_STAGE_INST{{ instance_id }}common { Status_timeout = 30000 }
    attribute EPS3_INPUT_STAGE_INST{{ instance_id }}hib_mode_status { Status_timeout = 30000 }
    attribute EPS3_INPUT_STAGE_INST{{ instance_id }}selflock_on { Status_timeout = 30000 }
    attribute EPS3_INPUT_STAGE_INST{{ instance_id }}sp1 { Status_timeout = 30000 }
    attribute EPS3_INPUT_STAGE_INST{{ instance_id }}sp2 { Status_timeout = 30000 }
    attribute EPS3_INPUT_STAGE_INST{{ instance_id }}sp3 { Status_timeout = 30000 }
    attribute EPS3_INPUT_STAGE_INST{{ instance_id }}system_bus { Status_timeout = 30000 }
    attribute EPS3_INPUT_STAGE_INST{{ instance_id }}bus_7v5 { Status_timeout = 30000 }
    attribute EPS3_INPUT_STAGE_INST{{ instance_id }}bus_7v5_power_good { Status_timeout = 30000 }
    attribute EPS3_INPUT_STAGE_INST{{ instance_id }}undervoltage_7V5 { Status_timeout = 30000 }
    attribute EPS3_INPUT_STAGE_INST{{ instance_id }}bus_3v3 { Status_timeout = 30000 }
    attribute EPS3_INPUT_STAGE_INST{{ instance_id }}undervoltage_3V3 { Status_timeout = 30000 }
    attribute EPS3_INPUT_STAGE_INST{{ instance_id }}_CMD_EXEC_STATUS_Data { Status_timeout = 40000 }
{%-     endfor %}    
"""

datacache_fidl_template = """
{%      for instance_id in range(config.inst_count) %}
//
// Global declarations for EPS_III INPUT_STAGE INSTANCE{{instance_id}}
//

    <** @description: number of seconds since last power up 
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_INPUT_STAGE_Inst{{instance_id}}_UpTimeInSecondsType EPS3_INPUT_STAGE_INST{{ instance_id }}_uptime_in_seconds
    
    <** @description: MCU mesurments voltage and temprature
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_INPUT_STAGE_Inst{{ instance_id }}CommonMeasurementType EPS3_INPUT_STAGE_INST{{ instance_id }}common
    
    <** @description: HIB mode enabled 
            0 - OFF
            1 - ON
            2 - UNKOWN
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_INPUT_STAGE_Inst{{instance_id}}hib_mode_status_type EPS3_INPUT_STAGE_INST{{ instance_id }}hib_mode_status

    <** @description: State of Sefl lock output of the MCU 
            0 - OFF
            1 - ON
            2 - UNKOWN
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_INPUT_STAGE_Inst{{instance_id}}selflock_on_type EPS3_INPUT_STAGE_INST{{ instance_id }}selflock_on

    <** @description: Statuses related to Solar Panel 1
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_INPUT_STAGE_Inst{{ instance_id }}Sp1InputDataType EPS3_INPUT_STAGE_INST{{ instance_id }}sp1

    <** @description: Statuses related to Solar Panel 2
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_INPUT_STAGE_Inst{{ instance_id }}Sp2InputDataType EPS3_INPUT_STAGE_INST{{ instance_id }}sp2

    <** @description: Statuses related to Solar Panel 3
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_INPUT_STAGE_Inst{{ instance_id }}Sp3InputDataType EPS3_INPUT_STAGE_INST{{ instance_id }}sp3

    <** @description: External supply 7.5V 
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_INPUT_STAGE_Inst{{ instance_id }}SystemBusType EPS3_INPUT_STAGE_INST{{ instance_id }}system_bus
    
    <** @description: External supply 7.5V 
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_INPUT_STAGE_Inst{{ instance_id }}Bus7v5Type EPS3_INPUT_STAGE_INST{{ instance_id }}bus_7v5

   <** @description: External supply 7.5V signal for Power Good 
        0 - OFF
        1 - ON
        2 - UNKOWN 
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_INPUT_STAGE_Inst{{instance_id}}bus_7v5_power_good_type EPS3_INPUT_STAGE_INST{{ instance_id }}bus_7v5_power_good
    
    <** @description: Undervoltage flag for buss 7.5V 
            0 - OFF
            1 - ON
            2 - UNKOWN
        @details: id = {{ increment(datacache_data_id) }}
     **>    
    attribute Eps3_INPUT_STAGE_Inst{{instance_id}}undervoltage_7V5_type EPS3_INPUT_STAGE_INST{{ instance_id }}undervoltage_7V5

    <** @description: External supply 3.3V
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_INPUT_STAGE_Inst{{ instance_id }}Bbus3v3Type EPS3_INPUT_STAGE_INST{{ instance_id }}bus_3v3

    <** @description: Undervoltage flag for buss 3.3V 
            0 - OFF
            1 - ON
            2 - UNKOWN
        @details: id = {{ increment(datacache_data_id) }}
     **>    
    attribute Eps3_INPUT_STAGE_Inst{{instance_id}}undervoltage_3V3_type EPS3_INPUT_STAGE_INST{{ instance_id }}undervoltage_3V3
    
    <** @description: EPS III communication execution status
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_INPUT_STAGE_Inst{{instance_id}}_FDIR_CMD_EXEC_STATUS_type EPS3_INPUT_STAGE_INST{{ instance_id }}_CMD_EXEC_STATUS_Data
{%-     endfor %}    
"""

cfg_code_template = """
#define EPS_III_INPUT_STAGE_CFG                                                                                                     \\{% for instance_id in range(config.inst_count) %}
    {                                                                                                                               \\
        .base.eps_dev_info.p_dev_init            = &eps_dev_init,                                                                   \\
        .base.eps_dev_info.p_is_seq_expected     = &eps_dev_is_seq_expected,                                                        \\
        .base.eps_dev_info.esps_dev_info         = { {{ instance_id }}, 1, 0 },                                                                     \\
        .base.eps_dev_info.p_process_fdir_faults = &eps_iii_input_stage_process_fdir_faults,                                        \\
        .base.eps_dev_info.datacache_cmd_list    = input_stage_datacache_cmd_list[EPS_III_INPUT_STAGE_INST{{ instance_id }}],                       \\
        .base.eps_dev_info.cmd_list_cnt          = EPS_III_INPUT_STAGE_DATACACHE_CMD_COUNT,                                         \\
        .base.eps_dev_info.p_fdir_exec_status    = (fault_exec_status_t *)&input_stage_fdir_exec_status[EPS_III_INPUT_STAGE_INST{{ instance_id }}], \\
        .base.eps_dev_info.fault_exec_status_cnt = EPS_III_INPUT_STAGE_CMD_CNT,                                                     \\
        .base.eps_dev_info.fdir_fault_ids        = input_stage_fdir_fault_ids[EPS_III_INPUT_STAGE_INST{{ instance_id }}],                           \\
        .base.p_init                             = (p_init_t)&eps_iii_input_stage_init,                                             \\
        .tlm.p_device_info                       = (eps_dev_t *)eps_dev_base[EPS_III_DEV_INPUT_STAGE_INST{{ instance_id }}],                        \\
        .tlm.tlm_cfg                             = {                                                                                \\
                EPSIII_INPUT_STAGE_INST{{ instance_id }}_DELAY_BETWEEN_SENDING,                                                                     \\
                EPSIII_INPUT_STAGE_INST{{ instance_id }}_MAX_MESSAGES_TO_SEND                                                                       \\
        },                                                                                                                          \\
        .tlm.p_get_telemetry                     = &tlm_dev_get_telemetry,                                                          \\
        .tlm.p_tlm_req_cmds                      = &input_stage_tlm_req_cmds[0],                                                    \\
        .tlm.tlm_cmd_cnt                         = INPUT_STAGE_TLM_CMD_CNT                                                          \\
    }\
{% if not loop.last %}\
,                                                                                                                              \\\
{% endif %}
{%-     endfor %}

#define EPS_III_INPUT_STAGE_DEV_INSTANCES_CFG                                     \\{% for instance_id in range(config.inst_count) %}
    (eps_dev_base_t *)&input_stage_modules[EPS_III_INPUT_STAGE_INST{{ instance_id }}]{% if not loop.last %},    \\{% endif %}                      
{%-     endfor %}

#define EPS_III_INPUT_STAGE_TLM_INST_CFG                                          \\{% for instance_id in range(config.inst_count) %}
    &input_stage_modules[EPS_III_INPUT_STAGE_INST{{ instance_id }}].tlm{% if not loop.last %},                  \\{% endif %}                      
{%-     endfor %}
"""

cfg_input_stage_inst_enum_code_template = """
#define EPS_III_INPUT_STAGE_INST_CFG                                 \\\
{% for instance_id in range(config.inst_count) %}
    EPS_III_INPUT_STAGE_INST{{ instance_id }}\
{% if not loop.last %}\
,                                       \\\
{% endif %}
{%-     endfor %}
"""

cfg_dev_inst_enum_code_template = """
#define EPS_III_DEV_INPUT_STAGE_INST_CFG                             \\\
{% for instance_id in range(config.inst_count) %}
    EPS_III_DEV_INPUT_STAGE_INST{{ instance_id }}\
{% if not loop.last %}\
,                                     \\\
{% endif %}
{%-     endfor %}
"""

cfg_datacache_lists_code_template = """
#define EPS_III_INPUT_STAGE_DATACACHE_LIST_CMD                       \\{% for instance_id in range(config.inst_count) %}
    {                                                                \\
        DC_DID_EPS3_INPUT_STAGE_INST{{ instance_id }}_UPTIME_IN_SECONDS,             \\
        DC_DID_EPS3_INPUT_STAGE_INST{{ instance_id }}COMMON,                         \\
        DC_DID_EPS3_INPUT_STAGE_INST{{ instance_id }}HIB_MODE_STATUS,                \\
        DC_DID_EPS3_INPUT_STAGE_INST{{ instance_id }}SELFLOCK_ON    ,                \\
        DC_DID_EPS3_INPUT_STAGE_INST{{ instance_id }}SP1,                            \\
        DC_DID_EPS3_INPUT_STAGE_INST{{ instance_id }}SP2,                            \\
        DC_DID_EPS3_INPUT_STAGE_INST{{ instance_id }}SP3,                            \\
        DC_DID_EPS3_INPUT_STAGE_INST{{ instance_id }}SYSTEM_BUS,                     \\
        DC_DID_EPS3_INPUT_STAGE_INST{{ instance_id }}BUS_7V5,                        \\
        DC_DID_EPS3_INPUT_STAGE_INST{{ instance_id }}BUS_7V5_POWER_GOOD,             \\
        DC_DID_EPS3_INPUT_STAGE_INST{{ instance_id }}UNDERVOLTAGE_7V5,               \\
        DC_DID_EPS3_INPUT_STAGE_INST{{ instance_id }}BUS_3V3,                        \\
        DC_DID_EPS3_INPUT_STAGE_INST{{ instance_id }}UNDERVOLTAGE_3V3,               \\
        DC_DID_EPS3_INPUT_STAGE_INST{{ instance_id }}_CMD_EXEC_STATUS_DATA           \\
    }{% if not loop.last %},                                                              \\{% endif %}
{%-     endfor %}
"""

cfg_fdir_faults_code_template = """
#define EPS_III_INPUT_STAGE_FDIR_FAULTS_IDS                          \\{% for instance_id in range(config.inst_count) %}
    {                                                                \\
        FDIR_FAULT_EPSIII_INPUT_STAGE_INST{{ instance_id }}_CMD_EXEC_FAILURE,        \\
    }{% if not loop.last %},                                                      \\{% endif %}
{%-     endfor %}
"""

obc_fidl_template =  """{%      for instance_id in range(config.inst_count) %}
        <** @description:  EPSIII INPUT_STAGE ID  **>
        EPSIII_INPUT_STAGE_{{ instance_id }}{% if not loop.last %},{% endif %}
{%-     endfor %}        
"""

nvm_app_defaults_template =  """{%for instance_id in range(config.inst_count)%}\
        {{increment(mac_address)}}, // MAC_ADDR_EPS INPUT_STAGE INST{{ instance_id }}{% if not loop.last %}{{"\n"}}{% endif %}
{%-     endfor %}
"""

fdir_srv_cfg_h_template = """{% for instance_id in range(config.inst_count) %}
    FDIR_FAULT_EPSIII_INPUT_STAGE_INST{{ instance_id }}_CMD_EXEC_FAILURE,
{%-     endfor %}
"""

fdir_srv_cfg_c_template = """{% for instance_id in range(config.inst_count) %}
    [FDIR_FAULT_EPSIII_INPUT_STAGE_INST{{ instance_id }}_CMD_EXEC_FAILURE]           = "FDIR_EPSIII_INPUT_STAGE_INST{{ instance_id }}_CMD_EXEC_FAILURE",
{%-     endfor %}
"""

fdir_srv_cfg_c_template2 = """{% for instance_id in range(config.inst_count) %}
    [FDIR_FAULT_EPSIII_INPUT_STAGE_INST{{ instance_id }}_CMD_EXEC_FAILURE]           = { .fdir_level = FDIR_EPSIII_INPUT_STAGE_INST{{ instance_id }}_CMD_EXEC_FAILURE_LEVEL,         .p_action_func = NULL,                         .p_escalated_action = NULL                   },
{%-     endfor %}
"""


nvm_app_FDIR_defaults_template =  """{% for instance_id in range(config.inst_count) %}
        [FDIR_FAULT_EPSIII_INPUT_STAGE_INST{{ instance_id }}_CMD_EXEC_FAILURE] = FDIR_EPSIII_INPUT_STAGE_INST{{ instance_id }}_CMD_EXEC_FAILURE_DETECTION_STATE,
{%-     endfor %}
"""


j2_fidl_template = Template(fidl_template)
j2_fdepl_template = Template(fdepl_template)
j2_datacache_fidl_template = Template(datacache_fidl_template)
j2_cfg_code_template = Template(cfg_code_template)
j2_cfg_input_stage_inst_enum_code_template = Template(cfg_input_stage_inst_enum_code_template)
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
    
    replace_section_in_file(fidl_file_path, j2_fidl_template.render(data),"// begin EPS_III INPUT_STAGE generated code","// end EPS_III INPUT_STAGE generated code")
    replace_section_in_file(fdepl_file_path, j2_fdepl_template.render(data),"// begin EPS_III INPUT_STAGE generated code","// end EPS_III INPUT_STAGE generated code")
    
    
    replace_section_in_file(datacache_fidl_file_path, "","// begin EPS_III INPUT_STAGE generated code","// end EPS_III INPUT_STAGE generated code")
    
    largest_data_id = find_largest_id(datacache_fidl_file_path)
        
    initial_value = [largest_data_id+1]
    
    replace_section_in_file(datacache_fidl_file_path, j2_datacache_fidl_template.render(data, datacache_data_id = initial_value, increment=print_and_increment),"// begin EPS_III INPUT_STAGE generated code","// end EPS_III INPUT_STAGE generated code")
    
    replace_section_in_file(cfg_code_file, j2_cfg_code_template.render(data),"// begin EPS_III INPUT_STAGE cfg generated code","// end EPS_III INPUT_STAGE cfg generated code")
    
    replace_section_in_file(cfg_code_file, j2_cfg_input_stage_inst_enum_code_template.render(data),"// begin EPS_III INPUT_STAGE instances generated code","// end EPS_III INPUT_STAGE instances generated code")

    replace_section_in_file(cfg_code_file, j2_cfg_dev_inst_enum_code_template.render(data),"// begin EPS_III INPUT_STAGE dev instances generated code","// end EPS_III INPUT_STAGE dev instances generated code")

    replace_section_in_file(cfg_code_file, j2_cfg_datacache_lists_code_template.render(data),"// begin EPS_III INPUT_STAGE datacache lists generated code","// end EPS_III INPUT_STAGE datacache lists generated code")

    replace_section_in_file(cfg_code_file, j2_cfg_fdir_faults_code_template.render(data),"// begin EPS_III INPUT_STAGE FDIR FAULTs generated code","// end EPS_III INPUT_STAGE FDIR FAULTs generated code")

    replace_section_in_file(nvm_eps_fidl_file, j2_obc_fidl_template.render(data),"// begin EPS_III INPUT_STAGE generated code","// end EPS_III INPUT_STAGE generated code")
    
    initial_mac_address = [0xA0]
    replace_section_in_file(nvm_app_defs_file, j2_nvm_app_defaults_template.render(data, mac_address = initial_mac_address, increment=print_and_increment),"// begin EPS_III INPUT_STAGE generated code","// end EPS_III INPUT_STAGE generated code")
    replace_section_in_file(nvm_app_defs_file, j2_nvm_app_FDIR_defaults_template.render(data),"// begin EPS_III INPUT_STAGE FDIR generated code","// end EPS_III INPUT_STAGE FDIR generated code")

    replace_section_in_file(fdir_srv_cfg_h_file, j2_fdir_srv_cfg_h_template.render(data),"// begin EPS_III INPUT_STAGE generated code","// end EPS_III INPUT_STAGE generated code")
    
    replace_section_in_file(fdir_srv_cfg_c_file, j2_fdir_srv_cfg_c_template.render(data),"// begin EPS_III INPUT_STAGE generated code","// end EPS_III INPUT_STAGE generated code")
    j2_fdir_srv_cfg_c_template = Template(fdir_srv_cfg_c_template2)
    replace_section_in_file(fdir_srv_cfg_c_file, j2_fdir_srv_cfg_c_template.render(data),"// begin EPS_III INPUT_STAGE generated configuration","// end EPS_III INPUT_STAGE generated configuration")

    
    
