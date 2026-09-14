project(drv_cubeobc C)

add_library(${PROJECT_NAME} OBJECT
    ${PROJECT_SOURCE_DIR}/src/cubeobc_critical.c
    ${PROJECT_SOURCE_DIR}/src/cubeobc_time.c
    ${PROJECT_SOURCE_DIR}/src/cubeobc_can.c
    ${PROJECT_SOURCE_DIR}/src/cubeobc_uart.c
    ${PROJECT_SOURCE_DIR}/src/cubeobc_file.c
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_ROOT}/inc)
target_link_libraries(${PROJECT_NAME} PUBLIC stm32_hal)
