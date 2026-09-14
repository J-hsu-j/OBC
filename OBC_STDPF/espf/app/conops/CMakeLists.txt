project(conops C)

include(${ROOT_BUILD_PATH}/espf.cmake)

cmake_path(SET fp_gen_path "${PROJECT_SOURCE_DIR}/fp")
cmake_path(SET conops_fdepl_path "${PROJECT_SOURCE_DIR}/fp/config/conops.fdepl")
cmake_path(SET conops_fidl_path "${FIDL_ROOT_OBC}/conops.fidl")

list(APPEND fp_conops_src_list
	${PROJECT_SOURCE_DIR}/fp/conops/v2.0/conops_server/FP_conopsProtocolServer.c
	${PROJECT_SOURCE_DIR}/fp/conops/v2.0/conops_server/FP_conopsProtocolServer.h
	#${PROJECT_SOURCE_DIR}/fp/conops/v2.0/conops_server/FP_conopsProtocolTypes.h
	${PROJECT_SOURCE_DIR}/fp/conops/v2.0/conops_server/FP_conopsServerApp.c
	${PROJECT_SOURCE_DIR}/fp/conops/v2.0/conops_server/FP_conopsServerApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
	"#include \"fp/conops/v2.0/conops_server/FP_conopsProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
	"&FP_conopsProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
	"#include \"fp/conops/v2.0/conops_server/FP_conopsServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
	"conopsServerAppInit()\;"
)

list(APPEND conops_sources
	${fp_conops_src_list}
)

FP_GEN_AT_PATH(fp_conops_src_list ${conops_fdepl_path} conops_fidl_path ${fp_gen_path})

list(APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/inc"
    "${PROJECT_SOURCE_DIR}/src"
    "${PROJECT_SOURCE_DIR}/fp"
    "${PROJECT_SOURCE_DIR}/gen"
)

list (APPEND conops_sources
	"src/conops.c"
    "gen/conops_sm_config.c"
	"gen/conops_sm_config_user.c"
)

add_library(${PROJECT_NAME} STATIC
    ${conops_sources}
)

list(APPEND conops_libs
    stm32_hal
    file_tools
    fdir_srv
    nvm
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} ${conops_libs})
