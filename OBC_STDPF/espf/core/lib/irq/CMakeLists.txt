project(irq C)

add_library(irq STATIC
    "src/irq.c"
)

target_include_directories(irq PUBLIC ${PROJECT_SOURCE_DIR}/inc)
target_link_libraries(irq PRIVATE stm32_hal)
