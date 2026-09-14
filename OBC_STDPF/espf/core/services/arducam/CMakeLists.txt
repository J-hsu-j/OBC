project(arducam C)

include(${ROOT_BUILD_PATH}/espf.cmake)
cmake_path(SET fp_gen_path "${PROJECT_SOURCE_DIR}/fp")

cmake_path(SET camera_fdepl_path "${PROJECT_SOURCE_DIR}/fp/config/arducam.fdepl")
cmake_path(SET camera_fidl_path "${FIDL_ROOT_OBC}/arducam.fidl")

set(fidl_version "1.0")

list(APPEND fp_camera_src_list
        ${PROJECT_SOURCE_DIR}/fp/arducam/v${fidl_version}/arducam_server/FP_arducamProtocolServer.c
        ${PROJECT_SOURCE_DIR}/fp/arducam/v${fidl_version}/arducam_server/FP_arducamProtocolServer.h
        ${PROJECT_SOURCE_DIR}/fp/arducam/v${fidl_version}/arducam_server/FP_arducamProtocolTypes.h
        ${PROJECT_SOURCE_DIR}/fp/arducam/v${fidl_version}/arducam_server/FP_arducamServerApp.c
        ${PROJECT_SOURCE_DIR}/fp/arducam/v${fidl_version}/arducam_server/FP_arducamServerApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/arducam/v${fidl_version}/arducam_server/FP_arducamProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_arducamProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/arducam/v${fidl_version}/arducam_server/FP_arducamServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "arducamServerAppInit()\;"
)


list(APPEND espsi_fp_sources
    ${fp_camera_src_list}
)

FP_GEN_AT_PATH(fp_camera_src_list ${camera_fdepl_path} camera_fidl_path ${fp_gen_path})

list(APPEND arducam_sources
    "src/arducam.c"
    ${fp_camera_src_list}
)

add_library(${PROJECT_NAME} STATIC
    ${arducam_sources}
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/inc"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} PRIVATE sys_time arducam_ov5642 libtrace file_tools)