project(rng C)

include(${ROOT_BUILD_PATH}/espf.cmake)

add_library(${PROJECT_NAME} STATIC
    "src/rng.c"
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}/inc"
    "${PROJECT_SOURCE_DIR}/src"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} assertions)
