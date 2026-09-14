cmake_path(SET fdepl_eps_ctrl_path "${PROJECT_SOURCE_DIR}/fp/config/eps_ctrl.fdepl")
cmake_path(SET eps_ctrl_fidl_path "${PROJECT_SOURCE_DIR}/fp/config/eps_ctrl.fidl")

list(APPEND fidl_dependencies_list
    ${eps_ctrl_fidl_path}
    ${fdepl_eps_ctrl_path}
)

list(APPEND fp_eps_ctrl_list
    ${PROJECT_SOURCE_DIR}/fp/eps_ctrl/v0.1/eps_ctrl_server/FP_eps_ctrlProtocolServer.c
    ${PROJECT_SOURCE_DIR}/fp/eps_ctrl/v0.1/eps_ctrl_server/FP_eps_ctrlProtocolServer.h
    ${PROJECT_SOURCE_DIR}/fp/eps_ctrl/v0.1/eps_ctrl_server/FP_eps_ctrlServerApp.c
    ${PROJECT_SOURCE_DIR}/fp/eps_ctrl/v0.1/eps_ctrl_server/FP_eps_ctrlServerApp.h
)

FP_GEN_AT_PATH(fp_eps_ctrl_list ${fdepl_eps_ctrl_path} fidl_dependencies_list "${PROJECT_SOURCE_DIR}/fp")

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/eps_ctrl/v0.1/eps_ctrl_server/FP_eps_ctrlProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_eps_ctrlProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/eps_ctrl/v0.1/eps_ctrl_server/FP_eps_ctrlServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "eps_ctrlServerAppInit()\;"
)

# Create a custom target that will always depend on the custom command
add_custom_target(
    gen_fp_eps_ctrl
    DEPENDS ${fp_eps_ctrl_list}
)

