project(arm_fault_handler C)

list(APPEND module_sources
    "src/arm_fault_handler.c"
    "inc/arm_fault_handler.h"
)

add_library(${PROJECT_NAME} STATIC
    ${module_sources}
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}/inc"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} crc nvm_rc)
