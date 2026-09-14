cmake_path(SET xband_fe_fdepl_path "${PROJECT_SOURCE_DIR}/config/xband_fe.fdepl")

#
# Global declarations for "xband_fe"
#
cmake_path(SET fp_gen_path "${PROJECT_SOURCE_DIR}/fp")
cmake_path(SET xband_fe_fidl_path "${FIDL_ROOT}/xband_fe/fp/xband_fe.fidl")

list(APPEND fidl_dep_list
    ${xband_fe_fdepl_path} 
    ${xband_fe_fidl_path}
)

list(APPEND fp_xband_fe_src_list
    ${PROJECT_SOURCE_DIR}/fp/xband_fe/v0.1/xband_fe_server/FP_xband_feProtocolServer.c
    ${PROJECT_SOURCE_DIR}/fp/xband_fe/v0.1/xband_fe_server/FP_xband_feProtocolServer.h
    ${PROJECT_SOURCE_DIR}/fp/xband_fe/v0.1/xband_fe_server/FP_xband_feProtocolTypes.h
    ${PROJECT_SOURCE_DIR}/fp/xband_fe/v0.1/xband_fe_server/FP_xband_feServerApp.c
    ${PROJECT_SOURCE_DIR}/fp/xband_fe/v0.1/xband_fe_server/FP_xband_feServerApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/xband_fe/v0.1/xband_fe_server/FP_xband_feProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_xband_feProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/xband_fe/v0.1/xband_fe_server/FP_xband_feServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "xband_feServerAppInit()\;"
)

FP_GEN_AT_PATH(fp_xband_fe_src_list ${xband_fe_fdepl_path} fidl_dep_list ${fp_gen_path})

add_custom_target(xband-fe-fidl-gen DEPENDS ${${fp_xband_fe_src_list}})
