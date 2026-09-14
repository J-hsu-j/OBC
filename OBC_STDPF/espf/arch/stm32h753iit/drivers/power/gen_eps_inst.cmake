project(eps_gen C)
message(STATUS "Processing eps_gen")
cmake_path(SET NVM_EPS_FIDL_FILE "${PROJECT_ROOT}/config/nvm/fp/config/nvm_eps.fidl")
cmake_path(SET NVM_APP_DEFS_FILE "${PROJECT_ROOT}/config/nvm_appcfg/inc/nvm_app_defs.inc")
cmake_path(SET FDIR_SRV_CFG_H_FILE "${PROJECT_ROOT}/config/fdir_srv/fdir_srv_cfg.h")
cmake_path(SET FDIR_SRV_CFG_C_FILE "${PROJECT_ROOT}/config/fdir_srv/fdir_srv_cfg.c")


# EPS II specific paths
cmake_path(SET EPS_II_BP_INSTANCE_GEN_PY "${PROJECT_SOURCE_DIR}/eps_ii/gen_bp_instances.py")
cmake_path(SET EPS_II_TELEMETRY_CFG_HDR_FILE "${PROJECT_SOURCE_DIR}/eps_ii/inc/eps_ii_telemetry_cfg.h")

# EPS III specific paths
cmake_path(SET EPS_III_BP_INSTANCE_GEN_PY "${PROJECT_SOURCE_DIR}/eps_iii/gen_bp_instances.py")
cmake_path(SET EPS_III_PDM_A_INSTANCE_GEN_PY "${PROJECT_SOURCE_DIR}/eps_iii/gen_pdm_a_instances.py")
cmake_path(SET EPS_III_PDM_B_INSTANCE_GEN_PY "${PROJECT_SOURCE_DIR}/eps_iii/gen_pdm_b_instances.py")
cmake_path(SET EPS_III_EXPANDER_INSTANCE_GEN_PY "${PROJECT_SOURCE_DIR}/eps_iii/gen_expander_instances.py")
cmake_path(SET EPS_III_INPUT_STAGE_INSTANCE_GEN_PY "${PROJECT_SOURCE_DIR}/eps_iii/gen_input_stage_instances.py")

cmake_path(SET EPS_III_BP_CFG_HDR_FILE "${PROJECT_SOURCE_DIR}/eps_iii/inc/eps_iii_bp_cfg.h")
cmake_path(SET EPS_III_PDM_A_CFG_HDR_FILE "${PROJECT_SOURCE_DIR}/eps_iii/inc/eps_iii_pdm_a_cfg.h")
cmake_path(SET EPS_III_PDM_B_CFG_HDR_FILE "${PROJECT_SOURCE_DIR}/eps_iii/inc/eps_iii_pdm_b_cfg.h")
cmake_path(SET EPS_III_EXPANDER_CFG_HDR_FILE "${PROJECT_SOURCE_DIR}/eps_iii/inc/eps_iii_expander_cfg.h")
cmake_path(SET EPS_III_INPUT_STAGE_CFG_HDR_FILE "${PROJECT_SOURCE_DIR}/eps_iii/inc/eps_iii_input_stage_cfg.h")

# Extract the source directory of the datacache library target
cmake_path(SET DATACACHE_DIR "${PROJECT_ROOT}/config/datacache")

cmake_path(APPEND DATACACHE_FIDL_FILES "${PROJECT_ROOT}/config/datacache/DataCache.fidl")
cmake_path(APPEND DATACACHE_FIDL_FILES "${PROJECT_ROOT}/config/datacache/datacache_io.fidl")
cmake_path(APPEND DATACACHE_FIDL_FILES "${PROJECT_ROOT}/config/datacache/DataCacheTypes.fidl")

list(APPEND generated_files_src_list
    ${EPS_II_TELEMETRY_CFG_HDR_FILE}
    ${EPS_III_TELEMETRY_CFG_HDR_FILE}
    ${NVM_EPS_FIDL_FILE}
    ${NVM_APP_DEFS_FILE}
    ${FDIR_SRV_CFG_H_FILE}
    ${FDIR_SRV_CFG_C_FILE} 
    ${DATACACHE_FIDL_FILES}
)

# This variable is used where we need to execute the eps bp instance generation tool
set(EPS_II_BP_INSTANCE_GENERATOR_CMD ${Python3_EXECUTABLE} 
                                  ${EPS_II_BP_INSTANCE_GEN_PY} 
                                  ${EPS_II_BP_COUNT} 
                                  ${DATACACHE_DIR} 
                                  ${EPS_II_TELEMETRY_CFG_HDR_FILE} 
                                  ${NVM_EPS_FIDL_FILE} 
                                  ${NVM_APP_DEFS_FILE} 
                                  ${FDIR_SRV_CFG_H_FILE}
                                  ${FDIR_SRV_CFG_C_FILE} )


# This variable is used where we need to execute the eps bp instance generation tool
set(EPS_III_BP_INSTANCE_GENERATOR_CMD ${Python3_EXECUTABLE} 
                                  ${EPS_III_BP_INSTANCE_GEN_PY} 
                                  ${EPS_III_BP_COUNT} 
                                  ${DATACACHE_DIR} 
                                  ${EPS_III_BP_CFG_HDR_FILE} 
                                  ${NVM_EPS_FIDL_FILE} 
                                  ${NVM_APP_DEFS_FILE} 
                                  ${FDIR_SRV_CFG_H_FILE}
                                  ${FDIR_SRV_CFG_C_FILE} )

# This variable is used where we need to execute the eps bp instance generation tool
set(EPS_III_INPUT_STAGE_INSTANCE_GENERATOR_CMD ${Python3_EXECUTABLE} 
                                  ${EPS_III_INPUT_STAGE_INSTANCE_GEN_PY} 
                                  ${EPS_III_INPUT_STAGE_COUNT} 
                                  ${DATACACHE_DIR} 
                                  ${EPS_III_INPUT_STAGE_CFG_HDR_FILE} 
                                  ${NVM_EPS_FIDL_FILE} 
                                  ${NVM_APP_DEFS_FILE} 
                                  ${FDIR_SRV_CFG_H_FILE}
                                  ${FDIR_SRV_CFG_C_FILE} )

# This variable is used where we need to execute the eps pdm_a instance generation tool
set(EPS_III_PDM_A_INSTANCE_GENERATOR_CMD ${Python3_EXECUTABLE} 
                                  ${EPS_III_PDM_A_INSTANCE_GEN_PY} 
                                  ${EPS_III_PDM_A_COUNT} 
                                  ${DATACACHE_DIR} 
                                  ${EPS_III_PDM_A_CFG_HDR_FILE} 
                                  ${NVM_EPS_FIDL_FILE} 
                                  ${NVM_APP_DEFS_FILE} 
                                  ${FDIR_SRV_CFG_H_FILE}
                                  ${FDIR_SRV_CFG_C_FILE} )
                              
# This variable is used where we need to execute the eps pdm_b instance generation tool
set(EPS_III_PDM_B_INSTANCE_GENERATOR_CMD ${Python3_EXECUTABLE} 
                                  ${EPS_III_PDM_B_INSTANCE_GEN_PY} 
                                  ${EPS_III_PDM_B_COUNT} 
                                  ${DATACACHE_DIR} 
                                  ${EPS_III_PDM_B_CFG_HDR_FILE} 
                                  ${NVM_EPS_FIDL_FILE} 
                                  ${NVM_APP_DEFS_FILE} 
                                  ${FDIR_SRV_CFG_H_FILE}
                                  ${FDIR_SRV_CFG_C_FILE} )

# This variable is used where we need to execute the eps expander instance generation tool
set(EPS_III_EXPANDER_INSTANCE_GENERATOR_CMD ${Python3_EXECUTABLE} 
                                  ${EPS_III_EXPANDER_INSTANCE_GEN_PY} 
                                  ${EPS_III_EXPANDER_COUNT} 
                                  ${DATACACHE_DIR} 
                                  ${EPS_III_EXPANDER_CFG_HDR_FILE} 
                                  ${NVM_EPS_FIDL_FILE} 
                                  ${NVM_APP_DEFS_FILE} 
                                  ${FDIR_SRV_CFG_H_FILE}
                                  ${FDIR_SRV_CFG_C_FILE} )

# Custom command to run the eps battery pack instance generator if there are changes
add_custom_command(
    OUTPUT ${generated_files_src_list}
    COMMAND ${EPS_II_BP_INSTANCE_GENERATOR_CMD}           # Execute the generation script
    COMMAND ${EPS_III_BP_INSTANCE_GENERATOR_CMD}           # Execute the generation script
    COMMAND ${EPS_III_PDM_A_INSTANCE_GENERATOR_CMD}
    COMMAND ${EPS_III_PDM_B_INSTANCE_GENERATOR_CMD}    
    COMMAND ${EPS_III_EXPANDER_INSTANCE_GENERATOR_CMD}
    COMMAND ${EPS_III_INPUT_STAGE_INSTANCE_GENERATOR_CMD}
    DEPENDS ${EPS_II_BP_INSTANCE_GEN_PY} ${EPS_III_PDM_A_INSTANCE_GEN_PY} ${EPS_III_PDM_B_INSTANCE_GEN_PY} ${EPS_III_EXPANDER_INSTANCE_GEN_PY} ${EPS_III_BP_INSTANCE_GEN_PY} ${EPS_III_INPUT_STAGE_INSTANCE_GEN_PY}                  # Depend on the python script itself
    COMMENT "EPS Battery Pack configuration changed. Running script for generation... Output: ${generated_files_src_list}"
)

# Create a custom target that will always depend on the custom command
add_custom_target(
     run_eps_gen DEPENDS ${generated_files_src_list}
)

add_library(${PROJECT_NAME} INTERFACE )

add_dependencies(${PROJECT_NAME} run_eps_gen)

target_link_libraries(${PROJECT_NAME} INTERFACE eps_ii_if eps_iii_if)
