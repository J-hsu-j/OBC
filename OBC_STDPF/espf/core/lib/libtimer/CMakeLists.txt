project(timer C)

add_library(timer STATIC
    "src/timer.c"
)

target_include_directories(timer PUBLIC inc)
target_link_libraries(timer assertions)
