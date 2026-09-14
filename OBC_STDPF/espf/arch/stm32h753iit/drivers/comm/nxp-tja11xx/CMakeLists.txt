project(nxp-tja11xx C)

add_library(nxp-tja11xx STATIC
    "src/nxp-tja11xx.c"
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}/inc"
    )

target_include_directories(nxp-tja11xx PUBLIC ${module_includes})
