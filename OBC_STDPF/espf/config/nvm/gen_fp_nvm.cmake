message(STATUS "Processing NVM FIDL generation")

cmake_path(SET nvm_fdepl_path ${PROJECT_SOURCE_DIR}/fp/config/nvm.fdepl)
cmake_path(SET nvm_boot_cfg_path ${PROJECT_SOURCE_DIR}/../nvm_bootcfg/inc/nvm_boot_block_ids.h)
cmake_path(SET nvm_app_cfg_path ${PROJECT_SOURCE_DIR}/../nvm_appcfg/inc/nvm_app_block_ids.h)
cmake_path(SET nvm_fidl_path ${PROJECT_SOURCE_DIR}/fp/config/nvm.fidl)
cmake_path(SET nvm_fidl_template_path ${PROJECT_SOURCE_DIR}/fp/config/nvm.fidl.tmpl)

list(APPEND nvm_fidl_deps_list 
     ${nvm_app_cfg_path} 
     ${nvm_boot_cfg_path}
)

list(APPEND fp_nvm_src_list
    ${PROJECT_SOURCE_DIR}/fp/nvm/v1.0/nvm_server/FP_nvmProtocolServer.c
    ${PROJECT_SOURCE_DIR}/fp/nvm/v1.0/nvm_server/FP_nvmProtocolServer.h
    ${PROJECT_SOURCE_DIR}/fp/nvm/v1.0/nvm_server/FP_nvmProtocolTypes.h
    ${PROJECT_SOURCE_DIR}/fp/nvm/v1.0/nvm_server/FP_nvmServerApp.c
    ${PROJECT_SOURCE_DIR}/fp/nvm/v1.0/nvm_server/FP_nvmServerApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/nvm/v1.0/nvm_server/FP_nvmProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_nvmProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/nvm/v1.0/nvm_server/FP_nvmServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "nvmServerAppInit()\;"
)

FP_GEN_AT_PATH(fp_nvm_src_list ${nvm_fdepl_path} nvm_fidl_path "${PROJECT_SOURCE_DIR}/fp")

add_custom_command(
    OUTPUT ${nvm_fidl_path}
    COMMAND ${CMAKE_COMMAND} -E echo "=> generating nvm.fidl..."
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_LIST_DIR}/scripts/nvm_gen.py ${nvm_fidl_template_path} ${nvm_fidl_path} ${nvm_boot_cfg_path} ${nvm_app_cfg_path} "// @@BLOCK_ID_LIST@@"
    DEPENDS ${nvm_fidl_deps_list}
    VERBATIM
)

add_custom_target(
    gen_fp_nvm
    ALL DEPENDS ${nvm_fidl_path}
)
