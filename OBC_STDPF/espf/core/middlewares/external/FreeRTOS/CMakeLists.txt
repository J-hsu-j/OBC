project(freertos C)

add_library(${PROJECT_NAME} STATIC
    ${PROJECT_SOURCE_DIR}/Source/croutine.c
    ${PROJECT_SOURCE_DIR}/Source/event_groups.c
    ${PROJECT_SOURCE_DIR}/Source/list.c
    ${PROJECT_SOURCE_DIR}/Source/queue.c
    ${PROJECT_SOURCE_DIR}/Source/stream_buffer.c
    ${PROJECT_SOURCE_DIR}/Source/tasks.c
    ${PROJECT_SOURCE_DIR}/Source/timers.c
    ${PROJECT_SOURCE_DIR}/Source/CMSIS_RTOS_V2/cmsis_os2.c
    ${PROJECT_SOURCE_DIR}/Source/portable/GCC/ARM_CM7/r0p1/port.c
    ${PROJECT_SOURCE_DIR}/Source/portable/MemMang/heap_5.c
)

list(
    APPEND module_includes
    ${PROJECT_SOURCE_DIR}/Source/CMSIS_RTOS_V2
    ${PROJECT_SOURCE_DIR}/Source/include
    ${PROJECT_SOURCE_DIR}/Source/portable/GCC/ARM_CM7/r0p1
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
