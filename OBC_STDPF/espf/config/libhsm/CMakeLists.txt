project(libhsm_trace C)

add_library(libhsm_trace STATIC
    "src/libhsm_trace.c"
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}/inc"
)

target_include_directories(libhsm_trace PUBLIC ${module_includes})
target_link_libraries(libhsm_trace PUBLIC libtrace assertions)
