project(power_common C)

include(${ROOT_BUILD_PATH}/espf.cmake)

list(APPEND power_common_sources
        "src/if_eps_dev.c"
        "src/if_tlm_dev.c"
)

add_library(${PROJECT_NAME} STATIC
        ${power_common_sources}
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/inc"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} datacache assertions nvm_cfg)
