project(sxband_sched C)

include(${ROOT_BUILD_PATH}/espf.cmake)

list(APPEND module_sources
    "src/sxband_sched.c"
    "src/sxband_sched_sm_config_user.c"
    "src/sxband_sched_sm_config.c"
    "src/sxband_cmd_iter_file.c"
    "src/sxband_cmd_iter_cmn.c"
    "src/sxband_sched_report.c"
)

add_library(${PROJECT_NAME} STATIC
    ${module_sources}
)

list(APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/inc"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} PUBLIC datetime crc hsm timer assertions file_tools)
