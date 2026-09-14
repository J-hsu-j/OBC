project(cobs_inplace C)

add_library(cobs_inplace STATIC
    "src/cobs_inplace.c"
)

target_include_directories(cobs_inplace PUBLIC ${PROJECT_SOURCE_DIR}/inc)
