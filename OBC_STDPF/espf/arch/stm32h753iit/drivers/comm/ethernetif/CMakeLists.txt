project(ethernetif C)

add_library(ethernetif STATIC
    "src/ethernetif.c"
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}/inc"
    )

target_include_directories(ethernetif PUBLIC ${module_includes})
target_link_libraries(ethernetif PUBLIC nxp-tja11xx lwIP)
