project(csp_service C)

include(${ROOT_BUILD_PATH}/espf.cmake)


cmake_path(SET fp_gen_path "${PROJECT_SOURCE_DIR}/fp")


#
# Global declarations for "csp_service"
#
cmake_path(SET csp_service_fdepl_path "${PROJECT_SOURCE_DIR}/fp/config/csp_service.fdepl")
cmake_path(SET csp_service_fidl_path "${FIDL_ROOT_OBC}/csp_service.fidl")

list(APPEND fp_csp_service_src_list
        ${PROJECT_SOURCE_DIR}/fp/csp_service/v0.1/csp_service_server/FP_csp_serviceProtocolServer.c
        ${PROJECT_SOURCE_DIR}/fp/csp_service/v0.1/csp_service_server/FP_csp_serviceProtocolServer.h
        ${PROJECT_SOURCE_DIR}/fp/csp_service/v0.1/csp_service_server/FP_csp_serviceProtocolTypes.h
        ${PROJECT_SOURCE_DIR}/fp/csp_service/v0.1/csp_service_server/FP_csp_serviceServerApp.c
        ${PROJECT_SOURCE_DIR}/fp/csp_service/v0.1/csp_service_server/FP_csp_serviceServerApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/csp_service/v0.1/csp_service_server/FP_csp_serviceProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_csp_serviceProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/csp_service/v0.1/csp_service_server/FP_csp_serviceServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "csp_serviceServerAppInit()\;"
)


FP_GEN_AT_PATH(fp_csp_service_src_list ${csp_service_fdepl_path} csp_service_fidl_path ${fp_gen_path})

add_library(${PROJECT_NAME} STATIC
    "src/csp_service.c"
    ${fp_csp_service_src_list}
)


target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/inc ${PROJECT_SOURCE_DIR}/fp/csp_service/v0.1/csp_service_server)
target_link_libraries(${PROJECT_NAME} PRIVATE csp libtrace assertions)