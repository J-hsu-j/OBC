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
// Global declarations for EPS EXPANDER INSTANCE{{instance_id}}
//

    <** @description: Input determining the thruster command execution status **>
    struct Eps3_EXPANDER_Inst{{instance_id}}_FDIR_CMD_EXEC_STATUS_type
    {
        <** @description: Error code from eps_iii_expander_get_telemetry command **>
        UInt8 eps_iii_expander_get_telemetry_ErrorCode
        <** @description: Error code from eps_iii_expander_h1_channels_control command **>
        UInt8 eps_iii_expander_h1_channels_control_ErrorCode
        <** @description: Error code from eps_iii_expander_gpio_control command **>
        UInt8 eps_iii_expander_gpio_control_ErrorCode
        <** @description: Error code from eps_iii_expander_interconnect_control command **>
        UInt8 eps_iii_expander_interconnect_control_ErrorCode
        <** @description: Error code from eps_iii_expander_release_control command **>
        UInt8 eps_iii_expander_release_control_ErrorCode
        <** @description: Error code from eps_iii_expander_release_control command **>
        UInt8 eps_iii_expander_release_5v_ErrorCode
    }    
    
    <** @description: Number of seconds since last power up **>
    struct Eps3_EXPANDER_Inst{{instance_id}}_UpTimeInSecondsType
    {
        <** @description: time in seconds **>
        UInt32 seconds
    }
    
    <** @description: Common measurements **>
    struct Eps3_EXPANDER_Inst{{instance_id}}_CommonMeasurementType
    {
        <** @description: MCU Voltage **>
        UInt16 mcu_volt
        
        <** @description: MCU Temperature **>
        Int32 mcu_temp
        
        <** @description: BUS Voltage **>
        UInt16 sys_bus_volt
    }
    
    <** @description: The status of All Feedback channels **>
    struct Eps3_EXPANDER_Inst{{instance_id}}_DigitalOutputsType
    {
        <** @description: Status of output Channel low voltage pins H1 47 and H1 48**>
        ReadEnDftStatus lv_h1_47_48
        
        <** @description: Status of output Channel High voltage pins H1 47 and H1 48**>
        ReadEnDftStatus hv_h1_47_48
        
        <** @description: Status of output Channel low voltage pins H1 49 and H1 50**>
        ReadEnDftStatus lv_h1_49_50
        
        <** @description: Status of output Channel High voltage pins H1 49 and H1 50**>
        ReadEnDftStatus hv_h1_49_50
        
        <** @description: Status of output Channel low voltage pins H1 51 and H1 52**>
        ReadEnDftStatus lv_h1_51_52
        
        <** @description: Status of output Channel High voltage pins H1 51 and H1 52**>
        ReadEnDftStatus hv_h1_51_52
        
        <** @description: Status of output Channel Battery**>
        ReadEnDftStatus interconnect_battery
        
        <** @description: Status of output Channel 3.3V Interconnect**>
        ReadEnDftStatus interconnect_3v3
        
        <** @description: Status of output Channel 5v Interconnect**>
        ReadEnDftStatus interconnect_5v
        
        <** @description: Status of output Channel 12v Interconnect**>
        ReadEnDftStatus interconnect_12v
        
        <** @description: Status of output Channel General output 1**>
        ReadEnDftStatus general_output_1
        
        <** @description: Status of output Channel General output 2**>
        ReadEnDftStatus general_output_2
        
        <** @description: Status of output Channel General output 3**>
        ReadEnDftStatus general_output_3
        
        <** @description: Status of output Channel General output 4**>
        ReadEnDftStatus general_output_4
        
        <** @description: Status of output Channel General output 5**>
        ReadEnDftStatus general_output_5
        
        <** @description: Status of output Channel General output 6**>
        ReadEnDftStatus general_output_6
        
        <** @description: Status of output Channel General output 7**>
        ReadEnDftStatus general_output_7
        
        <** @description: Status of output Channel General output 8**>
        ReadEnDftStatus general_output_8
        
        <** @description: Status of output Channel Release 1 **>
        ReadEnDftStatus release_1
        
        <** @description: Status of output Channel Release 2 **>
        ReadEnDftStatus release_2
        
        <** @description: Status of output Channel Release 3 **>
        ReadEnDftStatus release_3
        
        <** @description: Status of output Channel Release 4 **>
        ReadEnDftStatus release_4
        
        <** @description: Status of output Channel Release A1 **>
        ReadEnDftStatus release_a1
        
        <** @description: Status of output Channel Release B1 **>
        ReadEnDftStatus release_b1
        
        <** @description: Status of output Channel Release A2 **>
        ReadEnDftStatus release_a2
        
        <** @description: Status of output Channel Release B2 **>
        ReadEnDftStatus release_b2
        
        <** @description: Status of output Channel Release A3 **>
        ReadEnDftStatus release_a3
        
        <** @description: Status of output Channel Release B3 **>
        ReadEnDftStatus release_b3
        
        <** @description: Status of output Channel Release A4 **>
        ReadEnDftStatus release_a4
        
        <** @description: Status of output Channel Release B4 **>
        ReadEnDftStatus release_b4
    }
    
    <** @description: The level state of all General inputs **>
    struct Eps3_EXPANDER_Inst{{instance_id}}_GeneralInputType
    {
    
        <** @description: Returned status for General Output 1**>
        ReadLvlState general_input_1
            
        <** @description: Returned status for General Output 2**>
        ReadLvlState general_input_2
            
        <** @description: Returned status for General Output 3**>
        ReadLvlState general_input_3
            
        <** @description: Returned status for General Output 4**>
        ReadLvlState general_input_4
            
        <** @description: Returned status for General Output 5**>
        ReadLvlState general_input_5
            
        <** @description: Returned status for General Output 6**>
        ReadLvlState general_input_6
            
        <** @description: Returned status for General Output 7**>
        ReadLvlState general_input_7
            
        <** @description: Returned status for General Output 8**>
        ReadLvlState general_input_8
        
    }
    
    <** @description: The level state of all Feedbacks **>
    struct Eps3_EXPANDER_Inst{{instance_id}}_FeedbackType
    {
        <** @description: Returned status for Up feedback 1**>
        ReadLvlState feedback_1_1
            
        <** @description: Returned status for Low feedback 1**>
        ReadLvlState feedback_1_2
            
        <** @description: Returned status for Up feedback 2**>
        ReadLvlState feedback_2_1
            
        <** @description: Returned status for Low feedback 2**>
        ReadLvlState feedback_2_2
            
        <** @description: Returned status for Up feedback 3**>
        ReadLvlState feedback_3_1
            
        <** @description: Returned status for Low feedback 3**>
        ReadLvlState feedback_3_2
            
        <** @description: Returned status for Up feedback 4**>
        ReadLvlState feedback_4_1
            
        <** @description: Returned status for Low feedback 4**>
        ReadLvlState feedback_4_2
    }
    
    <** @description: Voltage and Current measurements **>
    struct Eps3_EXPANDER_Inst{{instance_id}}_CurrentLimitersType
    {
        <** @description: Voltage and Current measurements for Channel High voltage pins H1 47 and H1 48 **>
        VoltAmps h_h1_47_48
        
        <** @description: Voltage and Current measurements for Channel Low voltage pins H1 47 and H1 48  **>
        VoltAmps l_h1_47_48
        
        <** @description: Voltage and Current measurements for Channel High voltage pins H1 49 and H1 50 **>
        VoltAmps h_h1_49_50
        
        <** @description: Voltage and Current measurements for Channel Low voltage pins H1 49 and H1 50 **>
        VoltAmps l_h1_49_50
        
        <** @description: Voltage and Current measurements for Channel High voltage pins H1 51 and H1 52 **>
        VoltAmps h_h1_51_52
        
        <** @description: Voltage and Current measurements for Channel Low voltage pins H1 51 and H1 52 **>
        VoltAmps l_h1_51_52
        
        <** @description: Voltage and Current measurements for Release 1 **>
        VoltAmps release1
        
        <** @description: Voltage and Current measurements for Release 2 **>
        VoltAmps release2
        
        <** @description: Voltage and Current measurements for Release 3 **>
        VoltAmps release3
        
        <** @description: Voltage and Current measurements for Release 4 **>
        VoltAmps release4
        
        <** @description: Voltage and Current measurements for Channel 3.3V Interconnection **>
        VoltAmps interc_3v3
        
        <** @description: Voltage and Current measurements for Channel 5V Interconnection **>
        VoltAmps interc_5v
        
        <** @description: Voltage and Current measurements for Channel 12V Interconnection **>
        VoltAmps interc_12v
        
        <** @description: Voltage and Current measurements for Battery Bus **>
        VoltAmps interc_battery
    }
    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
    <** @description: Voltage and Current measurements **>
    struct Eps3_EXPANDER_Inst{{instance_id}}_VoltAmpsMeasurements_type
    {
        <** @description: Voltage and Current mesurements for System BUS channel **>
        VoltAmps system_bus
        
        
        <** @description: Voltage and Current mesurements for BUS A channel **>
        VoltAllAmps bus_a
        
        <** @description: Voltage and Current mesurements for BUS B channel **>
        VoltAllAmps bus_b
    }
    
    <** @description: Temperature data **>
    struct Eps3_EXPANDER_Inst{{instance_id}}_Temps_type
    {        
        <** @description: The temperature from BUS A sensor **>
        Int32 temp_bus_a
        
        <** @description: The temperature from BUS B sensor **>
        Int32 temp_bus_b
        
    }    

    <** @description: All Input and Output channel flag state **>
    struct Eps3_EXPANDER_Inst{{instance_id}}_ChannelFlagState_type
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
    struct Eps3_EXPANDER_Inst{{instance_id}}_OutputsStatus_type
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
    
{%-     endfor %}    
"""

fdepl_template = """
{%      for instance_id in range(config.inst_count) %}
//
// Global declarations for EPS EXPANDER INSTANCE{{instance_id}}
//  
    attribute EPS3_EXPANDER_INST{{instance_id}}_uptime_in_seconds { Status_timeout = 30000 }  
    attribute EPS3_EXPANDER_INST{{instance_id}}_common { Status_timeout = 30000 }
    attribute EPS3_EXPANDER_INST{{instance_id}}_outputs { Status_timeout = 30000 }
    attribute EPS3_EXPANDER_INST{{instance_id}}_general_inputs { Status_timeout = 30000 }
    attribute EPS3_EXPANDER_INST{{instance_id}}_feedbacks { Status_timeout = 30000 }
    attribute EPS3_EXPANDER_INST{{instance_id}}_volt_amp_measurements { Status_timeout = 30000 }
    attribute EPS3_EXPANDER_INST{{ instance_id }}_CMD_EXEC_STATUS_Data { Status_timeout = 40000 }
{%-     endfor %}    
"""

datacache_fidl_template = """
{%      for instance_id in range(config.inst_count) %}
//
// Global declarations for EPS_III EXPANDER INSTANCE{{instance_id}}
//
    <** @description: EPS III communication execution status
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_EXPANDER_Inst{{instance_id}}_FDIR_CMD_EXEC_STATUS_type EPS3_EXPANDER_INST{{instance_id}}_CMD_EXEC_STATUS_Data    

    <** @description:  number of seconds since last power up 
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_EXPANDER_Inst{{instance_id}}_UpTimeInSecondsType EPS3_EXPANDER_INST{{instance_id}}_uptime_in_seconds

    <** @description:  MCU measurements voltage and temperature
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_EXPANDER_Inst{{instance_id}}_CommonMeasurementType EPS3_EXPANDER_INST{{instance_id}}_common

    <** @description:  State of All output Channels
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_EXPANDER_Inst{{instance_id}}_DigitalOutputsType EPS3_EXPANDER_INST{{instance_id}}_outputs

    <** @description:  Status of All general inputs Channels
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_EXPANDER_Inst{{instance_id}}_GeneralInputType EPS3_EXPANDER_INST{{instance_id}}_general_inputs

    <** @description:  Status of All feedbacks
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_EXPANDER_Inst{{instance_id}}_FeedbackType EPS3_EXPANDER_INST{{instance_id}}_feedbacks

    <** @description:  Voltage and Current measurements from all Current limiters
        @details: id = {{ increment(datacache_data_id) }}
    **>
    attribute Eps3_EXPANDER_Inst{{instance_id}}_CurrentLimitersType EPS3_EXPANDER_INST{{instance_id}}_volt_amp_measurements
    
{%-     endfor %}    
"""

cfg_code_template = """
#define EPS_III_EXPANDER_CFG                                                                                                  \\{% for instance_id in range(config.inst_count) %}
    {                                                                                                                         \\
        .base.eps_dev_info.p_dev_init            = &eps_dev_init,                                                             \\
        .base.eps_dev_info.p_is_seq_expected     = &eps_dev_is_seq_expected,                                                  \\
        .base.eps_dev_info.esps_dev_info         = { {{ instance_id }}, 1, 0 },                                                               \\
        .base.eps_dev_info.p_process_fdir_faults = &eps_iii_expander_process_fdir_faults,                                     \\
        .base.eps_dev_info.datacache_cmd_list    = expander_datacache_cmd_list[EPS_III_EXPANDER_INST{{ instance_id }}],                       \\
        .base.eps_dev_info.cmd_list_cnt          = EPS_III_EXPANDER_DATACACHE_CMD_COUNT,                                      \\
        .base.eps_dev_info.p_fdir_exec_status    = (fault_exec_status_t *)&expander_fdir_exec_status[EPS_III_EXPANDER_INST{{ instance_id }}], \\
        .base.eps_dev_info.fault_exec_status_cnt = EPS_III_EXPANDER_CMD_CNT,                                                  \\
        .base.eps_dev_info.fdir_fault_ids        = expander_fdir_fault_ids[EPS_III_EXPANDER_INST{{ instance_id }}],                           \\
        .base.p_init                             = (p_init_t)&eps_iii_expander_init,                                          \\
        .tlm.p_device_info                       = (eps_dev_t *)eps_dev_base[EPS_III_DEV_EXPANDER_INST{{ instance_id }}],                     \\
        .tlm.tlm_cfg                             = {                                                                          \\
                EPSIII_EXPANDER_INST{{ instance_id }}_DELAY_BETWEEN_SENDING,                                                                  \\
                EPSIII_EXPANDER_INST{{ instance_id }}_MAX_MESSAGES_TO_SEND                                                                    \\
        },                                                                                                                    \\
        .tlm.p_get_telemetry                     = &tlm_dev_get_telemetry,                                                    \\
        .tlm.p_tlm_req_cmds                      = &expander_tlm_req_cmds[0],                                                 \\
        .tlm.tlm_cmd_cnt                         = EXPANDER_TLM_CMD_CNT,                                                      \\
        .ctrl.p_device_info                      = (eps_dev_t *)eps_dev_base[EPS_III_DEV_EXPANDER_INST{{ instance_id }}],                     \\
        .ctrl.p_set_output                       = &eps_iii_expander_set_channel_output,                                      \\
        .ctrl.p_get_output                       = &eps_iii_expander_get_channel_output,                                      \\
        .ctrl.p_on_set_output_response_received  = &eps_iii_on_set_output_response_received,                                  \\
        .ctrl.p_on_get_output_response_received  = &eps_iii_on_get_output_response_received                                   \\
    }\
{% if not loop.last %}\
,                                                                                                                        \\\
{% endif %}
{%-     endfor %}

#define EPS_III_EXPANDER_DEV_INSTANCES_CFG                                      \\{% for instance_id in range(config.inst_count) %}
    (eps_dev_base_t *)&expander_modules[EPS_III_EXPANDER_INST{{ instance_id }}]{% if not loop.last %},    \\{% endif %}                      
{%-     endfor %}

#define EPS_III_EXPANDER_TLM_INST_CFG                                           \\{% for instance_id in range(config.inst_count) %}
    &expander_modules[EPS_III_EXPANDER_INST{{ instance_id }}].tlm{% if not loop.last %},                  \\{% endif %}                      
{%-     endfor %}

#define EPS_III_EXPANDER_CTRL_INSTANCES_CFG                                     \\{% for instance_id in range(config.inst_count) %}
    &expander_modules[EPS_III_EXPANDER_INST{{ instance_id }}].ctrl{% if not loop.last %},                 \\{% endif %}                      
{%-     endfor %}
"""

cfg_expander_inst_enum_code_template = """
#define EPS_III_EXPANDER_INST_CFG                                   \\\
{% for instance_id in range(config.inst_count) %}
    EPS_III_EXPANDER_INST{{ instance_id }}\
{% if not loop.last %}\
,                                       \\\
{% endif %}
{%-     endfor %}
"""

cfg_dev_inst_enum_code_template = """
#define EPS_III_DEV_EXPANDER_INST_CFG                               \\\
{% for instance_id in range(config.inst_count) %}
    EPS_III_DEV_EXPANDER_INST{{ instance_id }}\
{% if not loop.last %}\
,                                     \\\
{% endif %}
{%-     endfor %}
"""

cfg_expander_ctrl_inst_enum_code_template = """
#define EPS_III_EXPANDER_CTRL_INST_CFG                              \\\
{% for instance_id in range(config.inst_count) %}
    EPS_III_EXPANDER_CTRL_INST{{ instance_id }}\
{% if not loop.last %}\
,                                   \\\
{% endif %}
{%-     endfor %}
"""

cfg_expander_datacache_lists_code_template = """
#define EPS_III_EXPANDER_DATACACHE_LIST_CMD                         \\{% for instance_id in range(config.inst_count) %}
    {                                                               \\
        DC_DID_EPS3_EXPANDER_INST{{ instance_id }}_UPTIME_IN_SECONDS,               \\
        DC_DID_EPS3_EXPANDER_INST{{ instance_id }}_COMMON,                          \\
        DC_DID_EPS3_EXPANDER_INST{{ instance_id }}_OUTPUTS,                         \\
        DC_DID_EPS3_EXPANDER_INST{{ instance_id }}_GENERAL_INPUTS,                  \\
        DC_DID_EPS3_EXPANDER_INST{{ instance_id }}_FEEDBACKS,                       \\
        DC_DID_EPS3_EXPANDER_INST{{ instance_id }}_VOLT_AMP_MEASUREMENTS,           \\
        DC_DID_EPS3_EXPANDER_INST{{ instance_id }}_CMD_EXEC_STATUS_DATA             \\
    }{% if not loop.last %},                                                           \\{% endif %}
{%-     endfor %}
"""

cfg_fdir_faults_code_template = """
#define EPS_III_EXPANDER_FDIR_FAULTS_IDS                          \\{% for instance_id in range(config.inst_count) %}
    {                                                             \\
        FDIR_FAULT_EPSIII_EXPANDER_INST{{ instance_id }}_CMD_EXEC_FAILURE,        \\
    }{% if not loop.last %},                                                      \\{% endif %}
{%-     endfor %}
"""

obc_fidl_template =  """{%      for instance_id in range(config.inst_count) %}
        <** @description:  EPSIII EXPANDER ID  **>
        EPSIII_EXPANDER_{{ instance_id }}{% if not loop.last %},{% endif %}
{%-     endfor %}        
"""

nvm_app_defaults_template =  """{%for instance_id in range(config.inst_count)%}\
        {{increment(mac_address)}}, // MAC_ADDR_EPS EXPANDER INST{{ instance_id }}{% if not loop.last %}{{"\n"}}{% endif %}
{%-     endfor %}
"""

fdir_srv_cfg_h_template = """{% for instance_id in range(config.inst_count) %}
    FDIR_FAULT_EPSIII_EXPANDER_INST{{ instance_id }}_CMD_EXEC_FAILURE,
{%-     endfor %}
"""

fdir_srv_cfg_c_template = """{% for instance_id in range(config.inst_count) %}
    [FDIR_FAULT_EPSIII_EXPANDER_INST{{ instance_id }}_CMD_EXEC_FAILURE]        = "FDIR_EPSIII_EXPANDER_INST{{ instance_id }}_CMD_EXEC_FAILURE",
{%-     endfor %}
"""

fdir_srv_cfg_c_template2 = """{% for instance_id in range(config.inst_count) %}
    [FDIR_FAULT_EPSIII_EXPANDER_INST{{ instance_id }}_CMD_EXEC_FAILURE]        = { .fdir_level = FDIR_EPSIII_EXPANDER_INST{{ instance_id }}_CMD_EXEC_FAILURE_LEVEL,        .p_action_func = NULL,                         .p_escalated_action = NULL                   },
{%-     endfor %}
"""


nvm_app_FDIR_defaults_template =  """{% for instance_id in range(config.inst_count) %}
        [FDIR_FAULT_EPSIII_EXPANDER_INST{{ instance_id }}_CMD_EXEC_FAILURE] = FDIR_EPSIII_EXPANDER_INST{{ instance_id }}_CMD_EXEC_FAILURE_DETECTION_STATE,
{%-     endfor %}
"""


j2_fidl_template = Template(fidl_template)
j2_fdepl_template = Template(fdepl_template)
j2_datacache_fidl_template = Template(datacache_fidl_template)
j2_cfg_code_template = Template(cfg_code_template)
j2_cfg_expander_inst_enum_code_template = Template(cfg_expander_inst_enum_code_template)
j2_cfg_dev_inst_enum_code_template = Template(cfg_dev_inst_enum_code_template)
j2_cfg_expander_ctrl_inst_enum_code_template = Template(cfg_expander_ctrl_inst_enum_code_template)
j2_cfg_expander_datacache_lists_code_template = Template(cfg_expander_datacache_lists_code_template)
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
    
    replace_section_in_file(fidl_file_path, j2_fidl_template.render(data),"// begin EPS_III EXPANDER generated code","// end EPS_III EXPANDER generated code")
    replace_section_in_file(fdepl_file_path, j2_fdepl_template.render(data),"// begin EPS_III EXPANDER generated code","// end EPS_III EXPANDER generated code")
    
    
    replace_section_in_file(datacache_fidl_file_path, "","// begin EPS_III EXPANDER generated code","// end EPS_III EXPANDER generated code")
    
    largest_data_id = find_largest_id(datacache_fidl_file_path)
        
    initial_value = [largest_data_id+1]
    
    replace_section_in_file(datacache_fidl_file_path, j2_datacache_fidl_template.render(data, datacache_data_id = initial_value, increment=print_and_increment),"// begin EPS_III EXPANDER generated code","// end EPS_III EXPANDER generated code")
    
    replace_section_in_file(cfg_code_file, j2_cfg_code_template.render(data),"// begin EPS_III EXPANDER cfg generated code","// end EPS_III EXPANDER cfg generated code")
    
    replace_section_in_file(cfg_code_file, j2_cfg_expander_inst_enum_code_template.render(data),"// begin EPS_III EXPANDER instances generated code","// end EPS_III EXPANDER instances generated code")

    replace_section_in_file(cfg_code_file, j2_cfg_dev_inst_enum_code_template.render(data),"// begin EPS_III EXPANDER dev instances generated code","// end EPS_III EXPANDER dev instances generated code")

    replace_section_in_file(cfg_code_file, j2_cfg_expander_ctrl_inst_enum_code_template.render(data),"// begin EPS_III EXPANDER ctrl instances generated code","// end EPS_III EXPANDER ctrl instances generated code")

    replace_section_in_file(cfg_code_file, j2_cfg_expander_datacache_lists_code_template.render(data),"// begin EPS_III EXPANDER datacache lists generated code","// end EPS_III EXPANDER datacache lists generated code")

    replace_section_in_file(cfg_code_file, j2_cfg_fdir_faults_code_template.render(data),"// begin EPS_III EXPANDER FDIR FAULTs generated code","// end EPS_III EXPANDER FDIR FAULTs generated code")

    replace_section_in_file(nvm_eps_fidl_file, j2_obc_fidl_template.render(data),"// begin EPS_III EXPANDER generated code","// end EPS_III EXPANDER generated code")
    
    initial_mac_address = [0xAC]
    replace_section_in_file(nvm_app_defs_file, j2_nvm_app_defaults_template.render(data, mac_address = initial_mac_address, increment=print_and_increment),"// begin EPS_III EXPANDER generated code","// end EPS_III EXPANDER generated code")
    replace_section_in_file(nvm_app_defs_file, j2_nvm_app_FDIR_defaults_template.render(data),"// begin EPS_III EXPANDER FDIR generated code","// end EPS_III EXPANDER FDIR generated code")

    replace_section_in_file(fdir_srv_cfg_h_file, j2_fdir_srv_cfg_h_template.render(data),"// begin EPS_III EXPANDER generated code","// end EPS_III EXPANDER generated code")
    
    replace_section_in_file(fdir_srv_cfg_c_file, j2_fdir_srv_cfg_c_template.render(data),"// begin EPS_III EXPANDER generated code","// end EPS_III EXPANDER generated code")
    j2_fdir_srv_cfg_c_template = Template(fdir_srv_cfg_c_template2)
    replace_section_in_file(fdir_srv_cfg_c_file, j2_fdir_srv_cfg_c_template.render(data),"// begin EPS_III EXPANDER generated configuration","// end EPS_III EXPANDER generated configuration")

    
    
