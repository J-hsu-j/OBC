project(payload_ctrl C)

include(${ROOT_BUILD_PATH}/espf.cmake)

cmake_path(SET fp_gen_path "${PROJECT_SOURCE_DIR}/fp")

#
# Global declarations for "Payload_Control"
#
cmake_path(SET payload_ctrl_fdepl_path "${PROJECT_SOURCE_DIR}/fp/config/payload_ctrl.fdepl")
cmake_path(SET payload_ctrl_fidl_path "${FIDL_ROOT_OBC}/payload_ctrl.fidl")

list(APPEND fp_payload_control_src_list
    ${PROJECT_SOURCE_DIR}/fp/payload_ctrl/v2.0/payload_ctrl_server/FP_payload_ctrlProtocolServer.c
    ${PROJECT_SOURCE_DIR}/fp/payload_ctrl/v2.0/payload_ctrl_server/FP_payload_ctrlProtocolServer.h
    ${PROJECT_SOURCE_DIR}/fp/payload_ctrl/v2.0/payload_ctrl_server/FP_payload_ctrlProtocolTypes.h
    ${PROJECT_SOURCE_DIR}/fp/payload_ctrl/v2.0/payload_ctrl_server/FP_payload_ctrlServerApp.c
    ${PROJECT_SOURCE_DIR}/fp/payload_ctrl/v2.0/payload_ctrl_server/FP_payload_ctrlServerApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/payload_ctrl/v2.0/payload_ctrl_server/FP_payload_ctrlProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_payload_ctrlProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/payload_ctrl/v2.0/payload_ctrl_server/FP_payload_ctrlServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "payload_ctrlServerAppInit()\;"
)

FP_GEN_AT_PATH(fp_payload_control_src_list ${payload_ctrl_fdepl_path} payload_ctrl_fidl_path ${fp_gen_path})

add_library(${PROJECT_NAME} STATIC
    "src/payload_ctrl.c"
    "src/payload_dummy.c"
    ${fp_payload_control_src_list}
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/inc"
    "${PROJECT_SOURCE_DIR}/src"
)

list(APPEND pl_ctrl_libs
    timer
    hsm
    assertions
)

list(APPEND pl_ctrl_libs
    aocs_cntrl_service
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} ${pl_ctrl_libs})
