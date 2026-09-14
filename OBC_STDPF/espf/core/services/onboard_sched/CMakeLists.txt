project(onboard_sched C)

include(${ROOT_BUILD_PATH}/espf.cmake)

cmake_path(SET fp_gen_path "${PROJECT_SOURCE_DIR}/fp")

#
# Global declarations for "onboard_sched"
#
cmake_path(SET onboard_sched_fdepl_path "${PROJECT_SOURCE_DIR}/config/onboard_sched.fdepl")
cmake_path(SET onboard_sched_fidl_path "${FIDL_ROOT_OBC}/onboard_sched.fidl")

list(APPEND fp_onboard_sched_src_list
    ${PROJECT_SOURCE_DIR}/fp/onboard_sched/v0.1/onboard_sched_server/FP_onboard_schedProtocolServer.c
    ${PROJECT_SOURCE_DIR}/fp/onboard_sched/v0.1/onboard_sched_server/FP_onboard_schedProtocolServer.h
    #${PROJECT_SOURCE_DIR}/fp/onboard_sched/v0.1/onboard_sched_server/FP_onboard_schedProtocolTypes.h
    ${PROJECT_SOURCE_DIR}/fp/onboard_sched/v0.1/onboard_sched_server/FP_onboard_schedServerApp.c
    ${PROJECT_SOURCE_DIR}/fp/onboard_sched/v0.1/onboard_sched_server/FP_onboard_schedServerApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/onboard_sched/v0.1/onboard_sched_server/FP_onboard_schedProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_onboard_schedProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/onboard_sched/v0.1/onboard_sched_server/FP_onboard_schedServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "onboard_schedServerAppInit()\;"
)

FP_GEN_AT_PATH(fp_onboard_sched_src_list ${onboard_sched_fdepl_path} onboard_sched_fidl_path ${fp_gen_path})

add_library(${PROJECT_NAME} STATIC
    "src/onboard_sched.c"
    "src/onboard_sched_scripting.c"
    "src/onboard_sched_logging.c"
    "src/onboard_sched_commands.c"
    ${fp_onboard_sched_src_list}
)

list(APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/inc"
    "${PROJECT_SOURCE_DIR}/src"
    "${PROJECT_SOURCE_DIR}/fp/onboard_sched/v0.1/onboard_sched_server"
)

list(APPEND onboard_sched_libs
    file_tools
    assertions
    crc
    COBS
)

if (MICROPYTHON_SERVICE_ENABLED)
list(APPEND onboard_sched_libs
    upython
    micropython
)
endif (MICROPYTHON_SERVICE_ENABLED)

if (COMM_GW_ENABLED)
list (APPEND onboard_sched_libs
    comm_gw
)
endif (COMM_GW_ENABLED)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} ${onboard_sched_libs})
