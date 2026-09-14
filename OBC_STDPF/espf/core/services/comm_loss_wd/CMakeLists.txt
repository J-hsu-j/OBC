project(comm_loss_wd C)
set(make_target ${PROJECT_NAME})

include(${ROOT_BUILD_PATH}/espf.cmake)


cmake_path(SET fp_gen_path "${PROJECT_SOURCE_DIR}/fp")


#
# Global declarations for "comm_loss_wd"
#
cmake_path(SET comm_loss_wd_fdepl_path "${PROJECT_SOURCE_DIR}/fp/config/comm_loss_wd.fdepl")
cmake_path(SET comm_loss_wd_fidl_path "${FIDL_ROOT_OBC}/comm_loss_wd.fidl")

list(APPEND fp_comm_loss_wd_src_list
        ${PROJECT_SOURCE_DIR}/fp/comm_loss_wd/v0.3/comm_loss_wd_server/FP_comm_loss_wdProtocolServer.c
        ${PROJECT_SOURCE_DIR}/fp/comm_loss_wd/v0.3/comm_loss_wd_server/FP_comm_loss_wdProtocolServer.h
        ${PROJECT_SOURCE_DIR}/fp/comm_loss_wd/v0.3/comm_loss_wd_server/FP_comm_loss_wdProtocolTypes.h
        ${PROJECT_SOURCE_DIR}/fp/comm_loss_wd/v0.3/comm_loss_wd_server/FP_comm_loss_wdServerApp.c
        ${PROJECT_SOURCE_DIR}/fp/comm_loss_wd/v0.3/comm_loss_wd_server/FP_comm_loss_wdServerApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/comm_loss_wd/v0.3/comm_loss_wd_server/FP_comm_loss_wdProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_comm_loss_wdProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/comm_loss_wd/v0.3/comm_loss_wd_server/FP_comm_loss_wdServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "comm_loss_wdServerAppInit()\;"
)


FP_GEN_AT_PATH(fp_comm_loss_wd_src_list ${comm_loss_wd_fdepl_path} comm_loss_wd_fidl_path ${fp_gen_path})


add_library(${make_target} STATIC
    "src/comm_loss_wd.c"
    ${fp_comm_loss_wd_src_list}
)



target_include_directories(${make_target} PRIVATE ${ROOT_INCLUDES} PUBLIC ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/inc ${PROJECT_SOURCE_DIR}/fp/comm_loss_wd/v0.1/comm_loss_wd_server)
target_compile_definitions(${make_target} PUBLIC ${ROOT_COMPILE_DEFS})
target_compile_options(${make_target} PRIVATE ${ROOT_COMPILE_OPTIONS})
target_link_options(${make_target} PRIVATE ${ROOT_LINK_OPTIONS})
target_link_libraries(${make_target} PRIVATE libtrace assertions nvm eps_ctrl)
