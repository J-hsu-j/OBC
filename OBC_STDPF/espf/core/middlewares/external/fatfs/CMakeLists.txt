project(fatfs C)

add_library(fatfs STATIC
                 oofatfs/src/ff.c
                 oofatfs/src/ffunicode.c
                 option/syscall.c
                 fatfs.c
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/oofatfs/src"
)

target_include_directories(fatfs PUBLIC ${module_includes})
