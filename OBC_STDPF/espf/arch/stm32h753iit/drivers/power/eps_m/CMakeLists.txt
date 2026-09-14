project(eps_m C)

add_library(${PROJECT_NAME} STATIC
    "src/eps_m.c"
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}/inc"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} datacache nvm power_common eps_ctrl_if)

#Add provided interface library
add_library(eps_m_if INTERFACE)

list(
    APPEND eps_m_if_includes
    "${PROJECT_SOURCE_DIR}/inc"
)

target_include_directories(eps_m_if INTERFACE ${eps_m_if_includes})

