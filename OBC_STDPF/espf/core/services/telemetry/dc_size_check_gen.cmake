#
# This file ensures that the generated data cache structure sizes can fit at least individually in
# the configured telemetry queue. If that check is violated, the build will be interrupted. 
#

cmake_path(SET dc_h_file_path "${PROJECT_ROOT}/config/datacache/datacache.h")
cmake_path(SET gen_c_file_path "${PROJECT_SOURCE_DIR}/src/dc_check_sizes_gen.c")

find_package(Python COMPONENTS Interpreter)

add_custom_command(
        OUTPUT ${gen_c_file_path}
        COMMAND ${Python_EXECUTABLE} ${PROJECT_SOURCE_DIR}/scripts/tlm_static_check_gen.py ${dc_h_file_path} ${gen_c_file_path} VERBATIM
        DEPENDS ${dc_h_file_path}
)

add_custom_target(dc_size_check_gen DEPENDS ${gen_c_file_path})
