project(trace_level_config C)

include(${ROOT_BUILD_PATH}/espf.cmake)

cmake_path(SET fdepl_path "${PROJECT_SOURCE_DIR}/fp/config/deployment.fdepl")
cmake_path(SET fidl_path "${FIDL_ROOT_OBC}/trace_level_config.fidl")

list(APPEND fidl_dependencies_list
    ${fidl_path}
)

list(APPEND fp_list
    ${PROJECT_SOURCE_DIR}/fp/trace_level_config/v0.1/trace_level_config_server/FP_trace_level_configProtocolServer.c
    ${PROJECT_SOURCE_DIR}/fp/trace_level_config/v0.1/trace_level_config_server/FP_trace_level_configServerApp.c
    ${PROJECT_SOURCE_DIR}/fp/trace_level_config/v0.1/trace_level_config_server/FP_trace_level_configProtocolTypes.h
    ${PROJECT_SOURCE_DIR}/fp/trace_level_config/v0.1/trace_level_config_server/FP_trace_level_configProtocolServer.h
    ${PROJECT_SOURCE_DIR}/fp/trace_level_config/v0.1/trace_level_config_server/FP_trace_level_configServerApp.h
)

FP_GEN_AT_PATH(fp_list ${fdepl_path} fidl_dependencies_list "${PROJECT_SOURCE_DIR}/fp")

list(APPEND module_sources
    ${fp_list}
)

add_library(${PROJECT_NAME} STATIC
    ${module_sources}
)

list(APPEND module_includes
    "${PROJECT_SOURCE_DIR}/fp"
    "${PROJECT_SOURCE_DIR}/inc"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"trace_level_config/v0.1/trace_level_config_server/FP_trace_level_configProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_trace_level_configProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"trace_level_config/v0.1/trace_level_config_server/FP_trace_level_configServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "trace_level_configServerAppInit()\;"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} libtrace)
