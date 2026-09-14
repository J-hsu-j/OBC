project(telemetry C)

include(${ROOT_BUILD_PATH}/espf.cmake)

include(${PROJECT_SOURCE_DIR}/fidl.cmake)
include(${PROJECT_SOURCE_DIR}/dc_size_check_gen.cmake)
include(${PROJECT_SOURCE_DIR}/dc_script_copy.cmake)

add_subdirectory(${PROJECT_SOURCE_DIR}/fp tlm_fp_types)

list(APPEND telemetry_sources
    "src/telemetry.c"
    "src/telemetry_sm_config_user.c"
    "src/telemetry_sm_config.c"
    "src/telemetry_file_sink_sm_config_user.c"
    "src/telemetry_file_sink_sm_config.c"
    "src/telemetry_queue.c"
    "src/telemetry_file_sink.c"
    ${tlm_src_list}
    ${gen_c_file_path}
)

add_library(${PROJECT_NAME} STATIC
    ${telemetry_sources}
)

add_dependencies(${PROJECT_NAME} 
    tlm-fidl-gen 
    dc_size_check_gen
    dc_script_copy
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/inc"
    "${PROJECT_SOURCE_DIR}/src"
    "${tlm_mod_includes_list}"

)

target_compile_options(${PROJECT_NAME} PRIVATE "-Wno-error=format-truncation")
target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} timer hsm datetime COBS datacache nvm crc fatfs assertions conops tlm_fp_types)
