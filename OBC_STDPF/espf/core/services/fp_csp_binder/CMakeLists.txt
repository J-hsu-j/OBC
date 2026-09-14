project(fp_csp_binder C)

list(APPEND module_sources
    "${PROJECT_SOURCE_DIR}/src/fp_csp_binder.c"
    "${PROJECT_SOURCE_DIR}/inc/fp_csp_binder.h"
)

add_library(${PROJECT_NAME} STATIC
    ${module_sources}
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}/inc"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} csp csp_service comm_gw)
