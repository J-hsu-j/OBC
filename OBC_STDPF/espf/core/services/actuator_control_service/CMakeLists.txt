project(acs C)

include(${ROOT_BUILD_PATH}/espf.cmake)

cmake_path(SET fp_gen_path "${PROJECT_SOURCE_DIR}/fp")
cmake_path(SET acs_fdepl_path "${PROJECT_SOURCE_DIR}/fp/config/acs.fdepl")
cmake_path(SET acs_fidl_path "${FIDL_ROOT_OBC}/acs.fidl")

list(APPEND fp_obc_acs_src_list
    ${PROJECT_SOURCE_DIR}/fp/acs/v1.2/acs_server/FP_acsProtocolServer.c
    ${PROJECT_SOURCE_DIR}/fp/acs/v1.2/acs_server/FP_acsProtocolServer.h
    ${PROJECT_SOURCE_DIR}/fp/acs/v1.2/acs_server/FP_acsProtocolTypes.h
    ${PROJECT_SOURCE_DIR}/fp/acs/v1.2/acs_server/FP_acsServerApp.c
    ${PROJECT_SOURCE_DIR}/fp/acs/v1.2/acs_server/FP_acsServerApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/acs/v1.2/acs_server/FP_acsProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_acsProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/acs/v1.2/acs_server/FP_acsServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "acsServerAppInit()\;"
)

list(APPEND acs_sources
    ${fp_obc_acs_src_list}
)

FP_GEN_AT_PATH(fp_obc_acs_src_list ${acs_fdepl_path} acs_fidl_path ${fp_gen_path})

list(APPEND module_includes
    "${PROJECT_SOURCE_DIR}/inc"
    "${PROJECT_SOURCE_DIR}"
    )

list(APPEND acs_sources
    "src/acs.c"
    )

add_library(${PROJECT_NAME} STATIC
    ${acs_sources}
)

list(APPEND acs_libs
     nvm
     assertions
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} ${acs_libs})