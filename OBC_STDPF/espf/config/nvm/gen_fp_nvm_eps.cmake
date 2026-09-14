cmake_path(SET fdepl_nvm_eps_path "${PROJECT_SOURCE_DIR}/fp/config/nvm_eps.fdepl")
cmake_path(SET nvm_eps_fidl_path "${PROJECT_SOURCE_DIR}/fp/config/nvm_eps.fidl")

list(APPEND fidl_dependencies_list
    ${nvm_eps_fidl_path}
    ${fdepl_nvm_eps_path}
)

list(APPEND fp_nvm_eps_list
    ${PROJECT_SOURCE_DIR}/fp/nvm_eps/v0.1/nvm_eps_server/FP_nvm_epsProtocolServer.c
    ${PROJECT_SOURCE_DIR}/fp/nvm_eps/v0.1/nvm_eps_server/FP_nvm_epsProtocolServer.h
    ${PROJECT_SOURCE_DIR}/fp/nvm_eps/v0.1/nvm_eps_server/FP_nvm_epsServerApp.c
    ${PROJECT_SOURCE_DIR}/fp/nvm_eps/v0.1/nvm_eps_server/FP_nvm_epsServerApp.h
)

FP_GEN_AT_PATH(fp_nvm_eps_list ${fdepl_nvm_eps_path} fidl_dependencies_list "${PROJECT_SOURCE_DIR}/fp")

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/nvm_eps/v0.1/nvm_eps_server/FP_nvm_epsProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_nvm_epsProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/nvm_eps/v0.1/nvm_eps_server/FP_nvm_epsServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "nvm_epsServerAppInit()\;"
)

# Create a custom target that will always depend on the custom command
add_custom_target(
    gen_fp_nvm_eps
    DEPENDS ${fp_nvm_eps_list}
)

