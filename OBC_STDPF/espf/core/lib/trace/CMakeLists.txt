project(libtrace C)

add_library(libtrace STATIC
    "src/trace.c"
)

target_include_directories(libtrace PUBLIC ${PROJECT_SOURCE_DIR}/inc)
target_link_libraries(libtrace PUBLIC cbuf PRIVATE file_tools cobs_inplace irq datetime crc sys_printf)
