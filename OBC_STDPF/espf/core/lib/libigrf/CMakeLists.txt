project(igrf C)

add_library(${PROJECT_NAME} STATIC
    src/igrf.c
)

list(
    APPEND module_includes
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/config
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
