project(eps_ctrl C)

list(APPEND eps_ctrl_sources
    "src/eps_ctrl.c"
    "src/eps_ctrl_sm_config_user.c"
    "src/eps_ctrl_sm_config.c"
    "src/eps_ctrl_queue.c"
)

add_library(${PROJECT_NAME} STATIC
    ${eps_ctrl_sources}
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}/inc"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} PUBLIC timer hsm nvm_cfg power_common eps_ctrl_cfg_if eps_m eps_i eps_ii eps_iii)

#Add provided interface library
add_library(eps_ctrl_if INTERFACE)

list(
    APPEND eps_ctrl_if_includes
    "${PROJECT_SOURCE_DIR}/inc"
)

target_include_directories(eps_ctrl_if INTERFACE ${eps_ctrl_if_includes})
target_link_libraries(eps_ctrl_if INTERFACE eps_ctrl_cfg_if eps_m_if eps_i_if eps_ii_if)
