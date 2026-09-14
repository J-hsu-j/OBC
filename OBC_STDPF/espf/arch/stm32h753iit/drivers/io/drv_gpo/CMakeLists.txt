project(drv_gpo C)

add_library(${PROJECT_NAME} STATIC
    "src/drv_gpo.c"
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}/inc"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} nvm)
