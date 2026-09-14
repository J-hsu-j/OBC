project(coordsys C)

include(${ROOT_BUILD_PATH}/espf.cmake)

cmake_path(SET fp_gen_path "${PROJECT_SOURCE_DIR}/fp")
cmake_path(SET coordsys_fdepl_path "${PROJECT_SOURCE_DIR}/fp/config/coordsys.fdepl")
cmake_path(SET coordsys_fidl_path "${FIDL_ROOT_OBC}/coordsys.fidl")

list(APPEND fp_coordsys_src_list
    ${PROJECT_SOURCE_DIR}/fp/coordsys/v2.0/coordsys_server/FP_coordsysProtocolServer.c
    ${PROJECT_SOURCE_DIR}/fp/coordsys/v2.0/coordsys_server/FP_coordsysProtocolServer.h
    ${PROJECT_SOURCE_DIR}/fp/coordsys/v2.0/coordsys_server/FP_coordsysProtocolTypes.h
    ${PROJECT_SOURCE_DIR}/fp/coordsys/v2.0/coordsys_server/FP_coordsysServerApp.c
    ${PROJECT_SOURCE_DIR}/fp/coordsys/v2.0/coordsys_server/FP_coordsysServerApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/coordsys/v2.0/coordsys_server/FP_coordsysProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_coordsysProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/coordsys/v2.0/coordsys_server/FP_coordsysServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "coordsysServerAppInit()\;"
)

list(APPEND coordsys_sources
    ${fp_coordsys_src_list}
)

FP_GEN_AT_PATH(fp_coordsys_src_list ${coordsys_fdepl_path} coordsys_fidl_path ${fp_gen_path})

list(APPEND module_includes
    "${PROJECT_SOURCE_DIR}/inc"
    "${PROJECT_SOURCE_DIR}"
    )

list (APPEND coordsys_sources
    "src/coordsys.c"
    )

add_library(${PROJECT_NAME} STATIC
    ${coordsys_sources}
)

list(APPEND coordsys_libs
     nvm
     assertions
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} ${coordsys_libs})
