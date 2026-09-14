project(nvm_cfg C)

include(${PROJECT_SOURCE_DIR}/gen_fp_nvm_eps.cmake)
include(${PROJECT_SOURCE_DIR}/gen_fp_nvm.cmake)

add_library(${PROJECT_NAME} STATIC
    "${PROJECT_SOURCE_DIR}/src/nvm_cfg.c"
    ${fp_nvm_eps_list}
    ${fp_nvm_src_list}
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/inc"
    "${PROJECT_SOURCE_DIR}/../nvm_appcfg/inc"
    "${PROJECT_SOURCE_DIR}/../nvm_bootcfg/inc"
    "${PROJECT_ROOT}/core/services/nvm/inc"
    "${PROJECT_SOURCE_DIR}/fp"
    "${PROJECT_SOURCE_DIR}/fp/nvm_eps/v0.1/nvm_eps_server/"
    "${PROJECT_ROOT}/core/services/fdir_srv/inc"
)

add_dependencies(${PROJECT_NAME} gen_fp_nvm)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} PUBLIC sys_time cubeobc SGP4 conops drv_fram eps_gen gnss sensor_data_service)
