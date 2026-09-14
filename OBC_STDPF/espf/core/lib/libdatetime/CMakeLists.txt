project(datetime C)

add_library(datetime STATIC
    "src/datetime.c"
)

target_include_directories(datetime PUBLIC inc)
target_link_libraries(datetime assertions)
