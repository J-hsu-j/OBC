# FIDL FP generation cmake
cmake_path(SET sdr_fdepl_path "${PROJECT_SOURCE_DIR}/config/sdr.fdepl")

# Global declarations for "xband_fe"
cmake_path(SET fp_gen_path "${PROJECT_SOURCE_DIR}/fp")
cmake_path(SET sdr_fidl_path "${FIDL_ROOT_OBC}/sdr.fidl")

list(APPEND fidl_dep_list
    ${sdr_fidl_path}
    ${sdr_fdepl_path}
)

list(APPEND fp_sdr_src_list
    ${PROJECT_SOURCE_DIR}/fp/sdr/v2.0/sdr_server/FP_sdrProtocolServer.c
    ${PROJECT_SOURCE_DIR}/fp/sdr/v2.0/sdr_server/FP_sdrServerApp.c
    ${PROJECT_SOURCE_DIR}/fp/sdr/v2.0/sdr_server/FP_sdrProtocolTypes.h
    ${PROJECT_SOURCE_DIR}/fp/sdr/v2.0/sdr_server/FP_sdrProtocolServer.h
    ${PROJECT_SOURCE_DIR}/fp/sdr/v2.0/sdr_server/FP_sdrServerApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/sdr/v2.0/sdr_server/FP_sdrProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_sdrProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/sdr/v2.0/sdr_server/FP_sdrServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "sdrServerAppInit()\;"
)

FP_GEN_AT_PATH(fp_sdr_src_list ${sdr_fdepl_path} fidl_dep_list ${fp_gen_path})

add_custom_target(sdr-fidl-gen DEPENDS ${${fp_sdr_src_list}})
