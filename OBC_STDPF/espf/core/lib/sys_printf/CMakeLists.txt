project(sys_printf C)

add_library(sys_printf STATIC
    "src/sys_printf.c"
)

target_include_directories(sys_printf PUBLIC ${PROJECT_SOURCE_DIR}/inc)
