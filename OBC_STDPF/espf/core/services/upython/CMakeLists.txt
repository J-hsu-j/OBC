project(upython C)

add_subdirectory("${PROJECT_SOURCE_DIR}/src/core" micropython)

list(
    APPEND module_sources
    ${PROJECT_SOURCE_DIR}/src/upy.c
    ${PROJECT_SOURCE_DIR}/src/upy_scr_mgr.c
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/inc"
    "${PROJECT_SOURCE_DIR}/fp/obc_micropython/v1.1/obc_micropython_server"
)

#
# Global declarations for "obc_micropython"
#
cmake_path(SET fp_gen_path "${PROJECT_SOURCE_DIR}/fp")
cmake_path(SET obc_micropython_fdepl_path "${PROJECT_SOURCE_DIR}/config/obc_micropython.fdepl")
cmake_path(SET obc_micropython_fidl_path "${FIDL_ROOT_OBC}/obc_micropython.fidl")


list(APPEND fp_obc_es_micropython_list
    ${PROJECT_SOURCE_DIR}/fp/obc_micropython/v1.1/obc_micropython_server/FP_obc_micropythonProtocolServer.c
    ${PROJECT_SOURCE_DIR}/fp/obc_micropython/v1.1/obc_micropython_server/FP_obc_micropythonProtocolServer.h
    ${PROJECT_SOURCE_DIR}/fp/obc_micropython/v1.1/obc_micropython_server/FP_obc_micropythonProtocolTypes.h
    ${PROJECT_SOURCE_DIR}/fp/obc_micropython/v1.1/obc_micropython_server/FP_obc_micropythonServerApp.c
    ${PROJECT_SOURCE_DIR}/fp/obc_micropython/v1.1/obc_micropython_server/FP_obc_micropythonServerApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/obc_micropython/v1.1/obc_micropython_server/FP_obc_micropythonProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_obc_micropythonProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/obc_micropython/v1.1/obc_micropython_server/FP_obc_micropythonServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "obc_micropythonServerAppInit()\;"
)

FP_GEN_AT_PATH(fp_obc_es_micropython_list ${obc_micropython_fdepl_path} obc_micropython_fidl_path ${fp_gen_path})


add_library(upython STATIC
                 ${module_sources}
                 ${fp_obc_es_micropython_list}
)


list(APPEND upy_libs fatfs micropython sys_time timer)

if (COMM_GW_ENABLED)
    list(APPEND upy_libs comm_gw)
endif()

target_include_directories(upython PUBLIC ${module_includes})
target_link_libraries(upython ${upy_libs})

# Remove the -pedantic flag from the compile options
get_target_property(target_options ${PROJECT_NAME} COMPILE_OPTIONS)
list(REMOVE_ITEM target_options "-pedantic")
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_OPTIONS "${target_options}")
