# FIDL FP generation cmake
cmake_path(SET ssp_fdepl_path "${PROJECT_SOURCE_DIR}/config/deployment.fdepl")

# Global declarations for "sp_or_uhf_ant"
cmake_path(SET fp_gen_path "${PROJECT_SOURCE_DIR}/fp")
cmake_path(SET ssp_fidl_path "${FIDL_ROOT}/sp_and_uhf_ant_unified/fp/sp_or_uhf_ant.fidl")

list(APPEND fidl_dep_list
    ${ssp_fidl_path}
    ${ssp_fdepl_path}
)

list(APPEND fp_ssp_src_list
    ${PROJECT_SOURCE_DIR}/fp/sp_uhf_ant/v2.1/sp_uhf_ant_client/FP_sp_uhf_antClientApp.c
    ${PROJECT_SOURCE_DIR}/fp/sp_uhf_ant/v2.1/sp_uhf_ant_client/FP_sp_uhf_antClientApp.h
    ${PROJECT_SOURCE_DIR}/fp/sp_uhf_ant/v2.1/sp_uhf_ant_client/FP_sp_uhf_antProtocolClient.c
    ${PROJECT_SOURCE_DIR}/fp/sp_uhf_ant/v2.1/sp_uhf_ant_client/FP_sp_uhf_antProtocolClient.h
    ${PROJECT_SOURCE_DIR}/fp/sp_uhf_ant/v2.1/sp_uhf_ant_client/FP_sp_uhf_antProtocolTypes.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/sp_uhf_ant/v2.1/sp_uhf_ant_client/FP_sp_uhf_antProtocolClient.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_sp_uhf_antProtocolClientInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/sp_uhf_ant/v2.1/sp_uhf_ant_client/FP_sp_uhf_antClientApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "sp_uhf_antClientAppInit()\;"
)

FP_GEN_AT_PATH(fp_ssp_src_list ${ssp_fdepl_path} fidl_dep_list ${fp_gen_path})

add_custom_target(ssp-fidl-gen DEPENDS ${fp_ssp_src_list})

