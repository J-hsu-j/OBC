project(arducam_ov5642 C)

add_library(${PROJECT_NAME} STATIC
    "src/ov5642.c"
    "src/arducam_comm.c"
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/src
    PUBLIC
    ${PROJECT_SOURCE_DIR}/inc
)

target_link_libraries(${PROJECT_NAME} PUBLIC stm32_hal assertions libtrace)
