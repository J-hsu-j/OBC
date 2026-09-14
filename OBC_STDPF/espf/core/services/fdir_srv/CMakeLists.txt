project(fdir_srv C)

cmake_path(SET fp_gen_path "${PROJECT_SOURCE_DIR}/fp")

cmake_path(SET fdir_srv_fdepl_path "${PROJECT_SOURCE_DIR}/fp/config/fdir_srv.fdepl")
cmake_path(SET fdir_srv_fidl_path "${FIDL_ROOT_OBC}/fdir_srv.fidl")

list(APPEND fp_fdir_srv_src_list
        ${PROJECT_SOURCE_DIR}/fp/fdir_srv/v0.2/fdir_srv_server/FP_fdir_srvProtocolServer.c
        ${PROJECT_SOURCE_DIR}/fp/fdir_srv/v0.2/fdir_srv_server/FP_fdir_srvProtocolServer.h
        ${PROJECT_SOURCE_DIR}/fp/fdir_srv/v0.2/fdir_srv_server/FP_fdir_srvProtocolTypes.h
        ${PROJECT_SOURCE_DIR}/fp/fdir_srv/v0.2/fdir_srv_server/FP_fdir_srvServerApp.c
        ${PROJECT_SOURCE_DIR}/fp/fdir_srv/v0.2/fdir_srv_server/FP_fdir_srvServerApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/fdir_srv/v0.2/fdir_srv_server/FP_fdir_srvProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_fdir_srvProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/fdir_srv/v0.2/fdir_srv_server/FP_fdir_srvServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "fdir_srvServerAppInit()\;"
)

FP_GEN_AT_PATH(fp_fdir_srv_src_list ${fdir_srv_fdepl_path} fdir_srv_fidl_path ${fp_gen_path})

list(APPEND fdir_srv_sources
    "src/fdir_srv.c"
    "src/fdir_srv_log.c"
    ${fp_fdir_srv_src_list}
)

add_library(${PROJECT_NAME} STATIC
    ${fdir_srv_sources}
)

add_dependencies(${PROJECT_NAME} gen_fp_nvm_eps)

list(APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/inc"
    "${PROJECT_SOURCE_DIR}/fp/fdir_srv/v0.2/fdir_srv_server/"
)

list(APPEND fdir_srv_libs
    nvm
    assertions
    file_tools
    cobs_inplace
    eps_gen
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} ${fdir_srv_libs})
