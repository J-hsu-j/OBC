project(datacache C)

include(${ROOT_BUILD_PATH}/espf.cmake)

message(STATUS "Processing Datacache")

cmake_path(SET fdepl_path "${PROJECT_SOURCE_DIR}/deploy_dc.fdepl")
cmake_path(SET fdepl_io_path "${PROJECT_SOURCE_DIR}/deploy_dc_io.fdepl")
cmake_path(SET dc_fidl_path "${PROJECT_SOURCE_DIR}/DataCache.fidl")
cmake_path(SET dc_types_fidl_path "${PROJECT_SOURCE_DIR}/DataCacheTypes.fidl")
cmake_path(SET fidl_io_path "${PROJECT_SOURCE_DIR}/datacache_io.fidl")
cmake_path(SET dc_py_path "${PROJECT_SOURCE_DIR}/datacache.py")

cmake_path(SET reindex_dc_py_path "${PROJECT_SOURCE_DIR}/reindex_dc_ids.py")

list(APPEND dc_fidls_list
    ${fdepl_path}
    ${dc_fidl_path}
    ${dc_types_fidl_path}
)

list(APPEND dc_files_list
    ${PROJECT_SOURCE_DIR}/datacache.c
    ${PROJECT_SOURCE_DIR}/datacache.h
)

list(APPEND fp_dc_io_list
    ${PROJECT_SOURCE_DIR}/fp/data_cache/v0.1/data_cache_server/FP_data_cacheProtocolServer.c
    ${PROJECT_SOURCE_DIR}/fp/data_cache/v0.1/data_cache_server/FP_data_cacheProtocolServer.h
    ${PROJECT_SOURCE_DIR}/fp/data_cache/v0.1/data_cache_server/FP_data_cacheProtocolTypes.h
    ${PROJECT_SOURCE_DIR}/fp/data_cache/v0.1/data_cache_server/FP_data_cacheServerApp.c
    ${PROJECT_SOURCE_DIR}/fp/data_cache/v0.1/data_cache_server/FP_data_cacheServerApp.h
)

list(APPEND datacache_sources
    ${dc_files_list}
)

add_library(${PROJECT_NAME} STATIC
    ${datacache_sources}
    ${fp_dc_io_list}
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/fp"
)

# the following custom command is responsible to build the datacache sources and datacache_io.fidl;
# this is the first stage code generation
add_custom_command(
        OUTPUT ${dc_files_list} ${fidl_io_path} ${dc_py_path}
        COMMAND ${Python3_EXECUTABLE} ${reindex_dc_py_path} ${dc_fidl_path} #this command is added just to make sure all the indexes are sequential after each generation
        COMMAND ${DC_GEN_CMD} -dc ${fdepl_path} VERBATIM
        DEPENDS ${dc_fidls_list} VERBATIM
        COMMENT "DataCache generation..."
        COMMENT "files to gen ${dc_files_list} ${fidl_io_path} ${dc_py_path} depends on: ${dc_fidls_list}"
)

# the following custom command is responsible to build the source code for the datacache_io.fidl generated
# in the previous step
add_custom_command(
        OUTPUT ${fp_dc_io_list}
        COMMAND ${FP_GEN_CMD} -dc ${fdepl_io_path} -fmr ${PROJECT_SOURCE_DIR}/fp VERBATIM
        DEPENDS ${fidl_io_path} VERBATIM
        COMMENT "DataCache io generation..."
        COMMENT "files to gen ${fp_dc_io_list}"
)

# Create a custom target that will always depend on the custom command
add_custom_target(
    run_datacache_gen
    DEPENDS ${dc_files_list} ${fidl_io_path} ${dc_py_path} ${fp_dc_io_list}
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/data_cache/v0.1/data_cache_server/FP_data_cacheProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_data_cacheProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/data_cache/v0.1/data_cache_server/FP_data_cacheServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "data_cacheServerAppInit()\;"
)

add_dependencies(${PROJECT_NAME} run_datacache_gen)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} timer )
