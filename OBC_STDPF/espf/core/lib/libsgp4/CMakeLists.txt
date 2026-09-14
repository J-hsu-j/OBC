project(SGP4 C)

add_library(${PROJECT_NAME} STATIC
    source/sgp4_other.c
    source/sgp4_propagator.c
    source/sgp4_two_line_element.c
)

list(
    APPEND module_includes
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/config
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
