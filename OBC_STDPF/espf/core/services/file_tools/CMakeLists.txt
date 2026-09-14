# Copyright (c) 2023-2024 EnduroSat AD. All rights reserved.
#
# Contents and presentations are protected world-wide.
# Any kind of using, copying etc. is prohibited without prior permission.

project(file_tools C)

add_library(file_tools STATIC
    "src/sd_mng.c"
    "src/ff_mng.c"
    "src/fm_mng.c"
    "src/stack_file.c"
    "src/rlf.c"
    "src/file_helper.c"
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}/inc"
)

target_include_directories(file_tools PUBLIC ${module_includes})
target_link_libraries(file_tools nvm fatfs CBUFF)
