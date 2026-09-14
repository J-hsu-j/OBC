project(libcsq_algo C)

add_library(libcsq_algo STATIC
    "src/csq_algo.c"
)

target_include_directories(libcsq_algo PUBLIC ${PROJECT_SOURCE_DIR}/inc)
target_link_libraries(libcsq_algo assertions)
