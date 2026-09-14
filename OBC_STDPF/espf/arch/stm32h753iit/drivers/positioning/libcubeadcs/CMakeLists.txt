project(cubeadcs C)

include(${ROOT_BUILD_PATH}/espf.cmake)

cmake_path(SET fp_gen_path "${PROJECT_SOURCE_DIR}/fp")

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/inc"
    "${PROJECT_SOURCE_DIR}/cfg"
)

list(APPEND cubeadcs_sources
        "src/cubeadcs.c"
	    "src/cubeadcs_crc.c"
        "src/cubeadcs_errhandl.c"
        "src/cubeadcs_ftransfer.c"
        "src/cubeadcs_usercmds.c"
        "src/cubeadcs_driver.c"
        "src/cubeadcs_persist.c"
        "cfg/cubeadcs_sysstate_cfg.c"
)

if (COMM_ESPS_ENABLED)
	#
	# Global declarations for "OBC_CUBEADCS"
	#
	cmake_path(SET obc_cubeadcs_fdepl_path "${PROJECT_SOURCE_DIR}/config/OBC_CUBEADCS.fdepl")
	cmake_path(SET obc_cubeadcs_fidl_path "${FIDL_ROOT_OBC}/OBC_CUBEADCS.fidl")

	list(APPEND fp_obc_cubeadcs_src_list
		${PROJECT_SOURCE_DIR}/fp/OBC_CUBEADCS/v2.1/OBC_CUBEADCS_server/FP_OBC_CUBEADCSProtocolServer.c
		${PROJECT_SOURCE_DIR}/fp/OBC_CUBEADCS/v2.1/OBC_CUBEADCS_server/FP_OBC_CUBEADCSProtocolServer.h
		${PROJECT_SOURCE_DIR}/fp/OBC_CUBEADCS/v2.1/OBC_CUBEADCS_server/FP_OBC_CUBEADCSProtocolTypes.h
		${PROJECT_SOURCE_DIR}/fp/OBC_CUBEADCS/v2.1/OBC_CUBEADCS_server/FP_OBC_CUBEADCSServerApp.c
		${PROJECT_SOURCE_DIR}/fp/OBC_CUBEADCS/v2.1/OBC_CUBEADCS_server/FP_OBC_CUBEADCSServerApp.h
	)

	set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
	    "#include \"fp/OBC_CUBEADCS/v2.1/OBC_CUBEADCS_server/FP_OBC_CUBEADCSProtocolServer.h\""
	)

	set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
	    "&FP_OBC_CUBEADCSProtocolServerInfo"
	)

	set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
	    "#include \"fp/OBC_CUBEADCS/v2.1/OBC_CUBEADCS_server/FP_OBC_CUBEADCSServerApp.h\""
	)

	set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
	    "OBC_CUBEADCSServerAppInit()\;"
	)

	list(APPEND cubeadcs_sources
	    ${fp_obc_cubeadcs_src_list}
	)

	FP_GEN_AT_PATH(fp_obc_cubeadcs_src_list ${obc_cubeadcs_fdepl_path} obc_cubeadcs_fidl_path ${fp_gen_path})
endif (COMM_ESPS_ENABLED)

add_library(${PROJECT_NAME} STATIC
        ${cubeadcs_sources}
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} datetime CBUFF datacache nvm fatfs libtrace assertions conops)
