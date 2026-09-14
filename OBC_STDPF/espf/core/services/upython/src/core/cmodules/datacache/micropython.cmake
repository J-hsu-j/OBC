# Create an INTERFACE library for our C module.
add_library(usermod_datacache INTERFACE)

include(${ROOT_BUILD_PATH}/espf.cmake)

cmake_path(SET fdepl_io_path "${CMAKE_CURRENT_LIST_DIR}/deploy_dc_io_upy.fdepl")
cmake_path(SET fidl_io_path "${PROJECT_ROOT}/config/datacache/datacache_io.fidl")
cmake_path(SET fidl_dc_path "${PROJECT_ROOT}/config/datacache/DataCache.fidl")
cmake_path(SET fidl_dc_types_path "${PROJECT_ROOT}/config/datacache/DataCacheTypes.fidl")
cmake_path(SET upy_c_path "${CMAKE_CURRENT_LIST_DIR}/src-gen-upy/data_cache/v0.1/gen/upy_data_cache.c")

# Add our source files to the lib
target_sources(usermod_fmng INTERFACE
    ${upy_c_path}
)

# Add the current directory as an include directory.
target_include_directories(usermod_datacache INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

set(gen_dependencies
	${fidl_io_path}
	${fidl_dc_path}
	${fidl_dc_types_path}
)

add_custom_command(
        OUTPUT ${upy_c_path}
        COMMAND ${MACARON_CMD} -pt=--gen-upy -dc=${fdepl_io_path} VERBATIM
        DEPENDS ${gen_dependencies} VERBATIM
)

# Link our INTERFACE library to the usermod target.
target_link_libraries(usermod INTERFACE usermod_datacache)
add_dependencies(usermod_datacache datacache)
