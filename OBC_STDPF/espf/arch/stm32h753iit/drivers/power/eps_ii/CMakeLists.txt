project(eps_ii C)

include(${ROOT_BUILD_PATH}/espf.cmake)

cmake_path(SET fdepl_path  "${PROJECT_SOURCE_DIR}/fp/config/deployment.fdepl")
cmake_path(SET fidl_path   "${FIDL_ROOT}/eps_ii/fp/EPSII_BP_v1.fidl")
cmake_path(SET fidl_path_1 "${FIDL_ROOT}/eps_ii/fp/EPSII_PDM_v1.fidl")

list(APPEND fidl_dependencies_list
    ${fdepl_path}
    ${fidl_path}
    ${fidl_path_1}
)

list(APPEND fp_list
        ${PROJECT_SOURCE_DIR}/fp/EPSII_BP_1/v3.0/EPSII_BP_1_client/FP_EPSII_BP_1ProtocolClient.c
        ${PROJECT_SOURCE_DIR}/fp/EPSII_BP_1/v3.0/EPSII_BP_1_client/FP_EPSII_BP_1ClientApp.c
        ${PROJECT_SOURCE_DIR}/fp/EPSII_BP_1/v3.0/EPSII_BP_1_client/FP_EPSII_BP_1ProtocolTypes.h
        ${PROJECT_SOURCE_DIR}/fp/EPSII_BP_1/v3.0/EPSII_BP_1_client/FP_EPSII_BP_1ProtocolClient.h
        ${PROJECT_SOURCE_DIR}/fp/EPSII_BP_1/v3.0/EPSII_BP_1_client/FP_EPSII_BP_1ClientApp.h
        ${PROJECT_SOURCE_DIR}/fp/EPSII_PDM_1/v1.0/EPSII_PDM_1_client/FP_EPSII_PDM_1ProtocolClient.c
        ${PROJECT_SOURCE_DIR}/fp/EPSII_PDM_1/v1.0/EPSII_PDM_1_client/FP_EPSII_PDM_1ClientApp.c
        ${PROJECT_SOURCE_DIR}/fp/EPSII_PDM_1/v1.0/EPSII_PDM_1_client/FP_EPSII_PDM_1ProtocolTypes.h
        ${PROJECT_SOURCE_DIR}/fp/EPSII_PDM_1/v1.0/EPSII_PDM_1_client/FP_EPSII_PDM_1ProtocolClient.h
        ${PROJECT_SOURCE_DIR}/fp/EPSII_PDM_1/v1.0/EPSII_PDM_1_client/FP_EPSII_PDM_1ClientApp.h
)

list(APPEND eps_ii_sources
        "src/eps_ii.c"
        "src/eps_ii_telemetry.c"
        "fp/EPSII_BP_1/v3.0/EPSII_BP_1_client/FP_EPSII_BP_1ProtocolClient.c"
        "fp/EPSII_BP_1/v3.0/EPSII_BP_1_client/FP_EPSII_BP_1ClientApp.c"
        "fp/EPSII_PDM_1/v1.0/EPSII_PDM_1_client/FP_EPSII_PDM_1ProtocolClient.c"
        "fp/EPSII_PDM_1/v1.0/EPSII_PDM_1_client/FP_EPSII_PDM_1ClientApp.c"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/EPSII_BP_1/v3.0/EPSII_BP_1_client/FP_EPSII_BP_1ProtocolClient.h\""
    "#include \"fp/EPSII_PDM_1/v1.0/EPSII_PDM_1_client/FP_EPSII_PDM_1ProtocolClient.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_EPSII_BP_1ProtocolClientInfo"
    "&FP_EPSII_PDM_1ProtocolClientInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/EPSII_BP_1/v3.0/EPSII_BP_1_client/FP_EPSII_BP_1ClientApp.h\""
    "#include \"fp/EPSII_PDM_1/v1.0/EPSII_PDM_1_client/FP_EPSII_PDM_1ClientApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "EPSII_BP_1ClientAppInit()\;"
    "EPSII_PDM_1ClientAppInit()\;"
)

add_library(${PROJECT_NAME} STATIC
        ${eps_ii_sources}
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/inc"
)

FP_GEN_AT_PATH(fp_list ${fdepl_path} fidl_dependencies_list "${PROJECT_SOURCE_DIR}/fp")

add_dependencies(${PROJECT_NAME} eps_gen)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} datacache assertions fdir_srv power_common eps_ctrl_if config_if)

#Add provided interface library
add_library(eps_ii_if INTERFACE)

list(
    APPEND eps_ii_if_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/inc"
)

target_include_directories(eps_ii_if INTERFACE ${eps_ii_if_includes})
