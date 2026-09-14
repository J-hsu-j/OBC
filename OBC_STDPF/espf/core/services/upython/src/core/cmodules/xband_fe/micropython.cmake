#
# INTERFACE library for the xband_fe uPy FIDL API
#

set(libname usermod_xband_fe)

add_library(${libname} INTERFACE)

cmake_path(SET fdepl_path "${CMAKE_CURRENT_LIST_DIR}/xband_fe_upy.fdepl")
cmake_path(SET fidl_path "${CMAKE_CURRENT_LIST_DIR}/../../../../../../fidl/xband_fe/fp/xband_fe.fidl")
cmake_path(SET c_mod_gen_root_path "${CMAKE_CURRENT_LIST_DIR}/src-gen-upy")
cmake_path(SET c_mod_gen_path "${c_mod_gen_root_path}/xband_fe/v0.1/gen")
cmake_path(SET upy_c_path "${CMAKE_CURRENT_LIST_DIR}/upy_xband_fe.c")

list(APPEND src_dep_list
    ${upy_c_path}
)

# Add our source files to the lib
target_sources(${libname} INTERFACE
    ${upy_c_path}
)

# Add the current directory as an include directory
target_include_directories(${libname} INTERFACE
    "${CMAKE_CURRENT_LIST_DIR}"
)

set(gen_dependencies
    ${fdepl_path}
    ${fidl_path}
)

add_custom_command(
    OUTPUT ${upy_c_path}
    COMMAND ${MACARON_CMD} -pt=--gen-upy -dc=${fdepl_path} VERBATIM
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${c_mod_gen_path} ${CMAKE_CURRENT_LIST_DIR}
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_LIST_DIR}/../delete_folder.py ${c_mod_gen_root_path}
    DEPENDS ${gen_dependencies}
)

# Link our INTERFACE library to the usermod target.
target_link_libraries(usermod INTERFACE ${libname})

add_custom_target(gen-xband_fe-upy DEPENDS ${upy_c_path})

add_dependencies(${libname} gen-xband_fe-upy)