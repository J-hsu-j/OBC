# FIDL FP generation cmake
cmake_path(SET gnss_fdepl_path "${PROJECT_SOURCE_DIR}/fp/config/gnss.fdepl")

# Global declarations for "gnss"
cmake_path(SET fp_gen_path "${PROJECT_SOURCE_DIR}/fp")
cmake_path(SET gnss_fidl_path "${FIDL_ROOT_OBC}/gnss.fidl")

list(APPEND fidl_dep_list
    ${gnss_fidl_path}
    ${gnss_fdepl_path}
)

list(APPEND fp_gnss_src_list
    ${PROJECT_SOURCE_DIR}/fp/gnss/v1.2/gnss_server/FP_gnssProtocolServer.c
    ${PROJECT_SOURCE_DIR}/fp/gnss/v1.2/gnss_server/FP_gnssServerApp.c
    # ${PROJECT_SOURCE_DIR}/fp/gnss/v1.2/gnss_server/FP_gnssProtocolTypes.h
    ${PROJECT_SOURCE_DIR}/fp/gnss/v1.2/gnss_server/FP_gnssProtocolServer.h
    ${PROJECT_SOURCE_DIR}/fp/gnss/v1.2/gnss_server/FP_gnssServerApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/gnss/v1.2/gnss_server/FP_gnssProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_gnssProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/gnss/v1.2/gnss_server/FP_gnssServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "gnssServerAppInit()\;"
)

FP_GEN_AT_PATH(fp_gnss_src_list ${gnss_fdepl_path} fidl_dep_list ${fp_gen_path})

add_custom_target(gnss-fidl-gen DEPENDS ${${fp_gnss_src_list}})
