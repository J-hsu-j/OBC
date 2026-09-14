project(assertions C)

add_library(assertions STATIC
    "src/assertions.c"
)

target_include_directories(assertions PUBLIC ${PROJECT_SOURCE_DIR}/inc)
