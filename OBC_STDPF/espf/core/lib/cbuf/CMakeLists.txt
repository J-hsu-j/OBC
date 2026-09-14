project(cbuf C)

add_library(cbuf STATIC
    "src/cbuf.c"
)

target_include_directories(cbuf PUBLIC ${PROJECT_SOURCE_DIR}/inc)
target_link_libraries(cbuf assertions)
