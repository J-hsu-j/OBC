project(slipif C)

add_library(slipif STATIC
    "src/sio.c"
    "src/slipif.c"
)

target_link_libraries(slipif PUBLIC lwIP CBUFF libtrace assertions)