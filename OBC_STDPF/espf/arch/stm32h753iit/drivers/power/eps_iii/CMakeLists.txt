project(eps_iii C)

include(${ROOT_BUILD_PATH}/espf.cmake)

cmake_path(SET fdepl_path  "${PROJECT_SOURCE_DIR}/fp/config/deployment.fdepl")
cmake_path(SET fidl_path   "${FIDL_ROOT}/eps_iii/fp/eps_iii_batt_pack.fidl")
cmake_path(SET fidl_path_pdm_a "${FIDL_ROOT}/eps_iii/fp/eps_iii_pdm_a.fidl")
cmake_path(SET fidl_path_pdm_b "${FIDL_ROOT}/eps_iii/fp/eps_iii_pdm_b.fidl")
cmake_path(SET fidl_path_expander "${FIDL_ROOT}/eps_iii/fp/eps_iii_expander.fidl")
cmake_path(SET fidl_path_input_stage "${FIDL_ROOT}/eps_iii/fp/eps_iii_input_stage.fidl")

list(APPEND fidl_dependencies_list
    ${fdepl_path}
    ${fidl_path}
    ${fidl_path_pdm_a}
    ${fidl_path_pdm_b}
    ${fidl_path_expander}
    ${fidl_path_input_stage}
)

list(APPEND fp_list
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_batt_pack/v2.0/eps_iii_batt_pack_client/FP_eps_iii_batt_packProtocolClient.c
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_batt_pack/v2.0/eps_iii_batt_pack_client/FP_eps_iii_batt_packClientApp.c
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_batt_pack/v2.0/eps_iii_batt_pack_client/FP_eps_iii_batt_packProtocolTypes.h
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_batt_pack/v2.0/eps_iii_batt_pack_client/FP_eps_iii_batt_packProtocolClient.h
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_batt_pack/v2.0/eps_iii_batt_pack_client/FP_eps_iii_batt_packClientApp.h
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_pdm_a/v2.0/eps_iii_pdm_a_client/FP_eps_iii_pdm_aProtocolClient.c
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_pdm_a/v2.0/eps_iii_pdm_a_client/FP_eps_iii_pdm_aClientApp.c
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_pdm_a/v2.0/eps_iii_pdm_a_client/FP_eps_iii_pdm_aProtocolTypes.h
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_pdm_a/v2.0/eps_iii_pdm_a_client/FP_eps_iii_pdm_aProtocolClient.h
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_pdm_a/v2.0/eps_iii_pdm_a_client/FP_eps_iii_pdm_aClientApp.h
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_pdm_b/v2.0/eps_iii_pdm_b_client/FP_eps_iii_pdm_bProtocolClient.c
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_pdm_b/v2.0/eps_iii_pdm_b_client/FP_eps_iii_pdm_bClientApp.c
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_pdm_b/v2.0/eps_iii_pdm_b_client/FP_eps_iii_pdm_bProtocolTypes.h
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_pdm_b/v2.0/eps_iii_pdm_b_client/FP_eps_iii_pdm_bProtocolClient.h
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_pdm_b/v2.0/eps_iii_pdm_b_client/FP_eps_iii_pdm_bClientApp.h
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_expander/v2.0/eps_iii_expander_client/FP_eps_iii_expanderProtocolClient.c
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_expander/v2.0/eps_iii_expander_client/FP_eps_iii_expanderClientApp.c
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_expander/v2.0/eps_iii_expander_client/FP_eps_iii_expanderProtocolTypes.h
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_expander/v2.0/eps_iii_expander_client/FP_eps_iii_expanderProtocolClient.h
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_expander/v2.0/eps_iii_expander_client/FP_eps_iii_expanderClientApp.h
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_input_stage/v2.0/eps_iii_input_stage_client/FP_eps_iii_input_stageProtocolClient.c
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_input_stage/v2.0/eps_iii_input_stage_client/FP_eps_iii_input_stageClientApp.c
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_input_stage/v2.0/eps_iii_input_stage_client/FP_eps_iii_input_stageProtocolTypes.h
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_input_stage/v2.0/eps_iii_input_stage_client/FP_eps_iii_input_stageProtocolClient.h
        ${PROJECT_SOURCE_DIR}/fp/eps_iii_input_stage/v2.0/eps_iii_input_stage_client/FP_eps_iii_input_stageClientApp.h
)

list(APPEND eps_iii_sources
        "src/eps_iii.c"
        "src/eps_iii_bp.c"
        "src/eps_iii_pdm_a.c"
        "src/eps_iii_pdm_b.c"
        "src/eps_iii_expander.c"
        "src/eps_iii_input_stage.c"
        "fp/eps_iii_batt_pack/v2.0/eps_iii_batt_pack_client/FP_eps_iii_batt_packProtocolClient.c"
        "fp/eps_iii_batt_pack/v2.0/eps_iii_batt_pack_client/FP_eps_iii_batt_packClientApp.c"
        "fp/eps_iii_pdm_a/v2.0/eps_iii_pdm_a_client/FP_eps_iii_pdm_aProtocolClient.c"
        "fp/eps_iii_pdm_a/v2.0/eps_iii_pdm_a_client/FP_eps_iii_pdm_aClientApp.c"
        "fp/eps_iii_pdm_b/v2.0/eps_iii_pdm_b_client/FP_eps_iii_pdm_bProtocolClient.c"
        "fp/eps_iii_pdm_b/v2.0/eps_iii_pdm_b_client/FP_eps_iii_pdm_bClientApp.c"
        "fp/eps_iii_expander/v2.0/eps_iii_expander_client/FP_eps_iii_expanderProtocolClient.c"
        "fp/eps_iii_expander/v2.0/eps_iii_expander_client/FP_eps_iii_expanderClientApp.c"
        "fp/eps_iii_input_stage/v2.0/eps_iii_input_stage_client/FP_eps_iii_input_stageProtocolClient.c"
        "fp/eps_iii_input_stage/v2.0/eps_iii_input_stage_client/FP_eps_iii_input_stageClientApp.c"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/eps_iii_batt_pack/v2.0/eps_iii_batt_pack_client/FP_eps_iii_batt_packProtocolClient.h\""
    "#include \"fp/eps_iii_pdm_a/v2.0/eps_iii_pdm_a_client/FP_eps_iii_pdm_aProtocolClient.h\""
    "#include \"fp/eps_iii_pdm_b/v2.0/eps_iii_pdm_b_client/FP_eps_iii_pdm_bProtocolClient.h\""
    "#include \"fp/eps_iii_expander/v2.0/eps_iii_expander_client/FP_eps_iii_expanderProtocolClient.h\""
    "#include \"fp/eps_iii_input_stage/v2.0/eps_iii_input_stage_client/FP_eps_iii_input_stageProtocolClient.h\""    
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_eps_iii_batt_packProtocolClientInfo"
    "&FP_eps_iii_pdm_aProtocolClientInfo"
    "&FP_eps_iii_pdm_bProtocolClientInfo"
    "&FP_eps_iii_expanderProtocolClientInfo"
    "&FP_eps_iii_input_stageProtocolClientInfo"        
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/eps_iii_batt_pack/v2.0/eps_iii_batt_pack_client/FP_eps_iii_batt_packClientApp.h\""
    "#include \"fp/eps_iii_pdm_a/v2.0/eps_iii_pdm_a_client/FP_eps_iii_pdm_aClientApp.h\""
    "#include \"fp/eps_iii_pdm_b/v2.0/eps_iii_pdm_b_client/FP_eps_iii_pdm_bClientApp.h\""
    "#include \"fp/eps_iii_expander/v2.0/eps_iii_expander_client/FP_eps_iii_expanderClientApp.h\""
    "#include \"fp/eps_iii_input_stage/v2.0/eps_iii_input_stage_client/FP_eps_iii_input_stageClientApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "eps_iii_batt_packClientAppInit()\;"
    "eps_iii_pdm_aClientAppInit()\;"
    "eps_iii_pdm_bClientAppInit()\;"
    "eps_iii_expanderClientAppInit()\;"
    "eps_iii_input_stageClientAppInit()\;"
)

add_library(${PROJECT_NAME} STATIC
        ${eps_iii_sources}
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/inc"
)

FP_GEN_AT_PATH(fp_list ${fdepl_path} fidl_dependencies_list "${PROJECT_SOURCE_DIR}/fp")

add_dependencies(${PROJECT_NAME} eps_gen)
target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} datacache assertions fdir_srv nvm_cfg power_common eps_ctrl)

#Add provided interface library
add_library(eps_iii_if INTERFACE)

list(
    APPEND eps_iii_if_includes
    "${PROJECT_SOURCE_DIR}/inc"
)

target_include_directories(eps_iii_if INTERFACE ${eps_iii_if_includes})
