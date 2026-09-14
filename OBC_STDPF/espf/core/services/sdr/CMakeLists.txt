project(sdr C)

include(${PROJECT_SOURCE_DIR}/fidl.cmake)

add_library(${PROJECT_NAME} STATIC
    "${PROJECT_SOURCE_DIR}/src/sdr.c"
    "${PROJECT_SOURCE_DIR}/src/sdr_op.c"
    "${PROJECT_SOURCE_DIR}/src/sdr_pl_ctrl.c"
    "${PROJECT_SOURCE_DIR}/src/sdr_critical.c"
    "${PROJECT_SOURCE_DIR}/src/sm/sdr_sm_config_user.c"
    "${PROJECT_SOURCE_DIR}/src/sm/sdr_sm_config.c"
    ${fp_sdr_src_list}
)

# regenerate fp code
add_dependencies(${PROJECT_NAME} sdr-fidl-gen)

list(APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/inc"
    "${PROJECT_SOURCE_DIR}/fp/sdr/v2.0/sdr_server"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes} PRIVATE "${PROJECT_SOURCE_DIR}/src/sm" "${PROJECT_SOURCE_DIR}/src")
target_link_libraries(${PROJECT_NAME} sdr-api sdr-api-pb nanopb fatfs assertions fdir_srv hsm libhsm_trace)
