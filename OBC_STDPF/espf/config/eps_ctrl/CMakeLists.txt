project(eps_ctrl_cfg C)

include(${PROJECT_SOURCE_DIR}/gen_fp_eps_ctrl.cmake)

add_library(${PROJECT_NAME} STATIC
    "${PROJECT_SOURCE_DIR}/eps_ctrl_cfg.c"
    ${fp_eps_ctrl_list}
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/fp"
    "${PROJECT_SOURCE_DIR}/fp/eps_ctrl/v0.1/eps_ctrl_server/"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} PUBLIC nvm power_common eps_ctrl_if)

#Add provided interface library
add_library(eps_ctrl_cfg_if INTERFACE)

list(
    APPEND eps_ctrl_cfg_if_includes
    "${PROJECT_SOURCE_DIR}"
)

target_include_directories(eps_ctrl_cfg_if INTERFACE ${eps_ctrl_cfg_if_includes})
