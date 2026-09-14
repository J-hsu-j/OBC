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
// Global declarations for EPS PDM_B INSTANCE{{instance_id}}
//

    <** @description: Input determining the thruster command execution status **>
    struct Eps3_PDM_B_Inst{{instance_id}}_FDIR_CMD_EXEC_STATUS_type
    {
        <** @description: Error code from eps_iii_pdm_b_get_telemetry command **>
        UInt8 eps_iii_pdm_b_get_telemetry_ErrorCode
        <** @description: Error code from eps_iii_pdm_b_a_b_control command **>
        UInt8 eps_iii_pdm_b_a_b_control_ErrorCode
    }    
    
    <** @description: Number of seconds since last power up **>
    struct Eps3_PDM_B_Inst{{instance_id}}_UpTimeInSecondsType
    {
        <** @description: time in seconds **>
        UInt32 seconds
    }
    
    <** @description: Voltage and Current measurements **>
    struct Eps3_PDM_B_Inst{{instance_id}}_VoltAmpsMeasurements_type
    {
        <** @description: Voltage and Current mesurements for System BUS channel **>
        VoltAmps system_bus
        
        
        <** @description: Voltage and Current mesurements for BUS A channel **>
        VoltAllAmps bus_a
        
        <** @description: Voltage and Current mesurements for BUS B channel **>
        VoltAllAmps bus_b
    }
    
    <** @description: Temperature data **>
    struct Eps3_PDM_B_Inst{{instance_id}}_Temps_type
    {        
        <** @description: The temperature from BUS A sensor **>
        Int32 temp_bus_a
        
        <** @description: The temperature from BUS B sensor **>
        Int32 temp_bus_b
        
    }    

    <** @description: All Input and Output channel flag state **>
    struct Eps3_PDM_B_Inst{{instance_id}}_ChannelFlagState_type
    {
        <** @description: A Input Current flag state **>
        OnOffStatus A_input_current_state
        
        <** @description: A Output Current flag state **>
        OnOffStatus A_output_current_state
        
        <** @description: A Input Voltage flag state **>
        OnOffStatus A_input_voltage_state
        
        <** @description: A Output Voltage flag state **>
        OnOffStatus A_output_voltage_state   

        <** @description: B Input Current flag state **>
        OnOffStatus B_input_current_state
        
        <** @description: B Output Current flag state **>
        OnOffStatus B_output_current_state
        
        <** @description: B Input Voltage flag state  **>
        OnOffStatus B_input_voltage_state
        
        <** @description: B Output Voltage flag state **>
        OnOffStatus B_output_voltage_state         
    }    
    
    <** @description: Status of A and B Outputs **>
    struct Eps3_PDM_B_Inst{{instance_id}}_OutputsStatus_type
    {
        <** @description: Status of Bus A IN channel **>
        ReadEnDftStatus en_a_in_bus
        
        <** @description: Status of Bus A OUT channel **>
        ReadEnDftStatus en_a_out_bus
        
        <** @description: Status of Bus B IN channel **>
        ReadEnDftStatus en_b_in_bus
        
        <** @description: Status of Bus B OUT channel **>
        ReadEnDftStatus en_b_out_bus
    }    
    
    <** @description: Common measurements **>
    struct Eps3_PDM_B_Inst{{instance_id}}_CommonMeasurementType
    {
        <** @description: MCU Voltage **>
        UInt16 mcu_volt
        
        <** @description: MCU Temperature **>
        Int32 mcu_temp
        
        <** @description: BUS Voltage **>
        UInt16 sys_bus_volt
    }
    
    <** @description: HibMode status type**>
    struct Eps3_PDM_B_Inst{{instance_id}}_hib_mode_Type
    {
        <** @description: HibMode status **>
        OnOffStatus status
    } 
    
{%-     endfor %}    
"""

fdepl_template = """
{%      for instance_id in range(config.inst_count) %}
//
// Global declarations for EPS PDM_B INSTANCE{{instance_id}}
//    
    attribute EPS3_PDM_B_INST{{ instance_id }}_uptime_in_seconds { Status_timeout = 30000 }
    attribute EPS3_PDM_B_INST{{instance_id}}_common { Status_timeout = 30000 }
    attribute EPS3_PDM_B_INST{{instance_id}}_hib_mode { Status_timeout = 30000 }
    attribute EPS3_PDM_B_INST{{instance_id}}_general_outputs { Status_timeout = 30000 }
    attribute EPS3_PDM_B_INST{{instance_id}}_channel_flag_state { Status_timeout = 30000 }
    attribute EPS3_PDM_B_INST{{instance_id}}_temperature { Status_timeout = 30000 }
    attribute EPS3_PDM_B_INST{{instance_id}}_all_measurements { Status_timeout = 30000 }
    attribute EPS3_PDM_B_INST{{ instance_id }}_CMD_EXEC_STATUS_Data { Status_timeout = 40000 }
{%-     endfor %}    
"""

datacache_fidl_template = """
{%      for instance_id in range(config.inst_count) %}
//
// Global declarations for EPS_III PDM_B INSTANCE{{instance_id}}
//
    <** @description: EPS III communication execution status
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_PDM_B_Inst{{instance_id}}_FDIR_CMD_EXEC_STATUS_type EPS3_PDM_B_INST{{instance_id}}_CMD_EXEC_STATUS_Data    

    <** @description:  number of seconds since last power up 
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_PDM_B_Inst{{instance_id}}_UpTimeInSecondsType EPS3_PDM_B_INST{{instance_id}}_uptime_in_seconds

    <** @description:  MCU measurements voltage and temperature
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_PDM_B_Inst{{instance_id}}_CommonMeasurementType EPS3_PDM_B_INST{{instance_id}}_common

    <** @description:  HIB mode status
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_PDM_B_Inst{{instance_id}}_hib_mode_Type EPS3_PDM_B_INST{{instance_id}}_hib_mode

    <** @description:  State of All Outputs
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_PDM_B_Inst{{instance_id}}_OutputsStatus_type EPS3_PDM_B_INST{{instance_id}}_general_outputs

    <** @description:  State of All Outputs
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_PDM_B_Inst{{instance_id}}_ChannelFlagState_type EPS3_PDM_B_INST{{instance_id}}_channel_flag_state

    <** @description:  Temperature sensor data
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_PDM_B_Inst{{instance_id}}_Temps_type EPS3_PDM_B_INST{{instance_id}}_temperature

    <** @description: Measurements of All Channels
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_PDM_B_Inst{{instance_id}}_VoltAmpsMeasurements_type EPS3_PDM_B_INST{{instance_id}}_all_measurements
    
{%-     endfor %}    
"""

cfg_code_template = """
#define EPS_III_PDM_B_CFG                                                                                               \\{% for instance_id in range(config.inst_count) %}
    {                                                                                                                   \\
        .base.eps_dev_info.p_dev_init            = &eps_dev_init,                                                       \\
        .base.eps_dev_info.p_is_seq_expected     = &eps_dev_is_seq_expected,                                            \\
        .base.eps_dev_info.esps_dev_info         = { {{ instance_id }}, 1, 0 },                                                         \\
        .base.eps_dev_info.p_process_fdir_faults = &eps_iii_pdm_b_process_fdir_faults,                                  \\
        .base.eps_dev_info.datacache_cmd_list    = pdm_b_datacache_cmd_list[EPS_III_PDM_B_INST{{ instance_id }}],                       \\
        .base.eps_dev_info.cmd_list_cnt          = EPS_III_PDM_B_DATACACHE_CMD_COUNT,                                   \\
        .base.eps_dev_info.p_fdir_exec_status    = (fault_exec_status_t *)&pdm_b_fdir_exec_status[EPS_III_PDM_B_INST{{ instance_id }}], \\
        .base.eps_dev_info.fault_exec_status_cnt = EPS_III_PDM_B_CMD_CNT,                                               \\
        .base.eps_dev_info.fdir_fault_ids        = pdm_b_fdir_fault_ids[EPS_III_PDM_B_INST{{ instance_id }}],                           \\
        .base.p_init                             = (p_init_t)&eps_iii_pdm_b_init,                                       \\
        .tlm.p_device_info                       = (eps_dev_t *)eps_dev_base[EPS_III_DEV_PDM_B_INST{{ instance_id }}],                  \\
        .tlm.tlm_cfg                             = {                                                                    \\
                EPSIII_PDM_B_INST{{ instance_id }}_DELAY_BETWEEN_SENDING,                                                               \\
                EPSIII_PDM_B_INST{{ instance_id }}_MAX_MESSAGES_TO_SEND                                                                 \\
        },                                                                                                              \\
        .tlm.p_get_telemetry                     = &tlm_dev_get_telemetry,                                              \\
        .tlm.p_tlm_req_cmds                      = &pdm_b_tlm_req_cmds[0],                                              \\
        .tlm.tlm_cmd_cnt                         = PDM_B_TLM_CMD_CNT,                                                   \\
        .ctrl.p_device_info                      = (eps_dev_t *)eps_dev_base[EPS_III_DEV_PDM_B_INST{{ instance_id }}],                  \\
        .ctrl.p_set_output                       = &eps_iii_pdm_b_set_channel_output,                                   \\
        .ctrl.p_get_output                       = &eps_iii_pdm_b_get_channel_output,                                   \\
        .ctrl.p_on_set_output_response_received  = &eps_iii_on_set_output_response_received,                            \\
        .ctrl.p_on_get_output_response_received  = &eps_iii_on_get_output_response_received                             \\
    }\
{% if not loop.last %}\
,                                                                                                                  \\\
{% endif %}
{%-     endfor %}

#define EPS_III_PDM_B_DEV_INSTANCES_CFG                       \\{% for instance_id in range(config.inst_count) %}
    (eps_dev_base_t *)&pdm_b_modules[EPS_III_PDM_B_INST{{ instance_id }}]{% if not loop.last %},    \\{% endif %}                      
{%-     endfor %}

#define EPS_III_PDM_B_TLM_INST_CFG                            \\{% for instance_id in range(config.inst_count) %}
    &pdm_b_modules[EPS_III_PDM_B_INST{{ instance_id }}].tlm{% if not loop.last %},                  \\{% endif %}                      
{%-     endfor %}

#define EPS_III_PDM_B_CTRL_INSTANCES_CFG                      \\{% for instance_id in range(config.inst_count) %}
    &pdm_b_modules[EPS_III_PDM_B_INST{{ instance_id }}].ctrl{% if not loop.last %},                 \\{% endif %}                      
{%-     endfor %}
"""

cfg_pdm_b_inst_enum_code_template = """
#define EPS_III_PDM_B_INST_CFG                                   \\\
{% for instance_id in range(config.inst_count) %}
    EPS_III_PDM_B_INST{{ instance_id }}\
{% if not loop.last %}\
,                                       \\\
{% endif %}
{%-     endfor %}
"""

cfg_dev_inst_enum_code_template = """
#define EPS_III_DEV_PDM_B_INST_CFG                               \\\
{% for instance_id in range(config.inst_count) %}
    EPS_III_DEV_PDM_B_INST{{ instance_id }}\
{% if not loop.last %}\
,                                     \\\
{% endif %}
{%-     endfor %}
"""

cfg_pdm_b_ctrl_inst_enum_code_template = """
#define EPS_III_PDM_B_CTRL_INST_CFG                              \\\
{% for instance_id in range(config.inst_count) %}
    EPS_III_PDM_B_CTRL_INST{{ instance_id }}\
{% if not loop.last %}\
,                                   \\\
{% endif %}
{%-     endfor %}
"""

cfg_pdm_b_datacache_lists_code_template = """
#define EPS_III_PDM_B_DATACACHE_LIST_CMD                         \\{% for instance_id in range(config.inst_count) %}
    {                                                            \\
        DC_DID_EPS3_PDM_B_INST{{ instance_id }}_UPTIME_IN_SECONDS,               \\
        DC_DID_EPS3_PDM_B_INST{{ instance_id }}_COMMON,                          \\
        DC_DID_EPS3_PDM_B_INST{{ instance_id }}_HIB_MODE,                        \\
        DC_DID_EPS3_PDM_B_INST{{ instance_id }}_GENERAL_OUTPUTS,                 \\
        DC_DID_EPS3_PDM_B_INST{{ instance_id }}_CHANNEL_FLAG_STATE,              \\
        DC_DID_EPS3_PDM_B_INST{{ instance_id }}_TEMPERATURE,                     \\
        DC_DID_EPS3_PDM_B_INST{{ instance_id }}_ALL_MEASUREMENTS,                 \\
        DC_DID_EPS3_PDM_B_INST{{ instance_id }}_CMD_EXEC_STATUS_DATA             \\
    }{% if not loop.last %},                                                           \\{% endif %}
{%-     endfor %}
"""

cfg_fdir_faults_code_template = """
#define EPS_III_PDM_B_FDIR_FAULTS_IDS                       \\{% for instance_id in range(config.inst_count) %}
    {                                                       \\
        FDIR_FAULT_EPSIII_PDM_B_INST{{ instance_id }}_CMD_EXEC_FAILURE,     \\
    }{% if not loop.last %},                                                      \\{% endif %}
{%-     endfor %}
"""

obc_fidl_template =  """{%      for instance_id in range(config.inst_count) %}
        <** @description:  EPSIII PDM_B ID  **>
        EPSIII_PDM_B_{{ instance_id }}{% if not loop.last %},{% endif %}
{%-     endfor %}        
"""

nvm_app_defaults_template =  """{%for instance_id in range(config.inst_count)%}\
        {{increment(mac_address)}}, // MAC_ADDR_EPS PDM_B INST{{ instance_id }}{% if not loop.last %}{{"\n"}}{% endif %}
{%-     endfor %}
"""

fdir_srv_cfg_h_template = """{% for instance_id in range(config.inst_count) %}
    FDIR_FAULT_EPSIII_PDM_B_INST{{ instance_id }}_CMD_EXEC_FAILURE,
{%-     endfor %}
"""

fdir_srv_cfg_c_template = """{% for instance_id in range(config.inst_count) %}
    [FDIR_FAULT_EPSIII_PDM_B_INST{{ instance_id }}_CMD_EXEC_FAILURE]        = "FDIR_EPSIII_PDM_B_INST{{ instance_id }}_CMD_EXEC_FAILURE",
{%-     endfor %}
"""

fdir_srv_cfg_c_template2 = """{% for instance_id in range(config.inst_count) %}
    [FDIR_FAULT_EPSIII_PDM_B_INST{{ instance_id }}_CMD_EXEC_FAILURE]        = { .fdir_level = FDIR_EPSIII_PDM_B_INST{{ instance_id }}_CMD_EXEC_FAILURE_LEVEL,        .p_action_func = NULL,                         .p_escalated_action = NULL                   },
{%-     endfor %}
"""


nvm_app_FDIR_defaults_template =  """{% for instance_id in range(config.inst_count) %}
        [FDIR_FAULT_EPSIII_PDM_B_INST{{ instance_id }}_CMD_EXEC_FAILURE] = FDIR_EPSIII_PDM_B_INST{{ instance_id }}_CMD_EXEC_FAILURE_DETECTION_STATE,
{%-     endfor %}
"""


j2_fidl_template = Template(fidl_template)
j2_fdepl_template = Template(fdepl_template)
j2_datacache_fidl_template = Template(datacache_fidl_template)
j2_cfg_code_template = Template(cfg_code_template)
j2_cfg_pdm_b_inst_enum_code_template = Template(cfg_pdm_b_inst_enum_code_template)
j2_cfg_dev_inst_enum_code_template = Template(cfg_dev_inst_enum_code_template)
j2_cfg_pdm_b_ctrl_inst_enum_code_template = Template(cfg_pdm_b_ctrl_inst_enum_code_template)
j2_cfg_pdm_b_datacache_lists_code_template = Template(cfg_pdm_b_datacache_lists_code_template)
j2_cfg_fdir_faults_code_template= Template(cfg_fdir_faults_code_template)
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
    
    replace_section_in_file(fidl_file_path, j2_fidl_template.render(data),"// begin EPS_III PDM_B generated code","// end EPS_III PDM_B generated code")
    replace_section_in_file(fdepl_file_path, j2_fdepl_template.render(data),"// begin EPS_III PDM_B generated code","// end EPS_III PDM_B generated code")
    
    
    replace_section_in_file(datacache_fidl_file_path, "","// begin EPS_III PDM_B generated code","// end EPS_III PDM_B generated code")
    
    largest_data_id = find_largest_id(datacache_fidl_file_path)
        
    initial_value = [largest_data_id+1]
    
    replace_section_in_file(datacache_fidl_file_path, j2_datacache_fidl_template.render(data, datacache_data_id = initial_value, increment=print_and_increment),"// begin EPS_III PDM_B generated code","// end EPS_III PDM_B generated code")
    
    replace_section_in_file(cfg_code_file, j2_cfg_code_template.render(data),"// begin EPS_III PDM_B cfg generated code","// end EPS_III PDM_B cfg generated code")
    
    replace_section_in_file(cfg_code_file, j2_cfg_pdm_b_inst_enum_code_template.render(data),"// begin EPS_III PDM_B instances generated code","// end EPS_III PDM_B instances generated code")

    replace_section_in_file(cfg_code_file, j2_cfg_dev_inst_enum_code_template.render(data),"// begin EPS_III PDM_B dev instances generated code","// end EPS_III PDM_B dev instances generated code")

    replace_section_in_file(cfg_code_file, j2_cfg_pdm_b_ctrl_inst_enum_code_template.render(data),"// begin EPS_III PDM_B ctrl instances generated code","// end EPS_III PDM_B ctrl instances generated code")

    replace_section_in_file(cfg_code_file, j2_cfg_pdm_b_datacache_lists_code_template.render(data),"// begin EPS_III PDM_B datacache lists generated code","// end EPS_III PDM_B datacache lists generated code")

    replace_section_in_file(cfg_code_file, j2_cfg_fdir_faults_code_template.render(data),"// begin EPS_III PDM_B FDIR FAULTs generated code","// end EPS_III PDM_B FDIR FAULTs generated code")

    replace_section_in_file(nvm_eps_fidl_file, j2_obc_fidl_template.render(data),"// begin EPS_III PDM_B generated code","// end EPS_III PDM_B generated code")
    
    initial_mac_address = [0xA8]
    replace_section_in_file(nvm_app_defs_file, j2_nvm_app_defaults_template.render(data, mac_address = initial_mac_address, increment=print_and_increment),"// begin EPS_III PDM_B generated code","// end EPS_III PDM_B generated code")
    replace_section_in_file(nvm_app_defs_file, j2_nvm_app_FDIR_defaults_template.render(data),"// begin EPS_III PDM_B FDIR generated code","// end EPS_III PDM_B FDIR generated code")

    replace_section_in_file(fdir_srv_cfg_h_file, j2_fdir_srv_cfg_h_template.render(data),"// begin EPS_III PDM_B generated code","// end EPS_III PDM_B generated code")
    
    replace_section_in_file(fdir_srv_cfg_c_file, j2_fdir_srv_cfg_c_template.render(data),"// begin EPS_III PDM_B generated code","// end EPS_III PDM_B generated code")
    j2_fdir_srv_cfg_c_template = Template(fdir_srv_cfg_c_template2)
    replace_section_in_file(fdir_srv_cfg_c_file, j2_fdir_srv_cfg_c_template.render(data),"// begin EPS_III PDM_B generated configuration","// end EPS_III PDM_B generated configuration")

    
    
