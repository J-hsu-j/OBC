project(adis16265_gyro C)

include(${ROOT_BUILD_PATH}/espf.cmake)

cmake_path(SET fp_gen_path "${PROJECT_SOURCE_DIR}/fp")
cmake_path(SET adis16265_gyro_fdepl_path "${PROJECT_SOURCE_DIR}/fp/config/adis16265_gyro.fdepl")
cmake_path(SET adis16265_gyro_fidl_path "${FIDL_ROOT_OBC}/adis16265_gyro.fidl")

list(APPEND fp_adis16265_gyro_src_list
    ${PROJECT_SOURCE_DIR}/fp/adis16265_gyro/v1.0/adis16265_gyro_server/FP_adis16265_gyroProtocolServer.c
    ${PROJECT_SOURCE_DIR}/fp/adis16265_gyro/v1.0/adis16265_gyro_server/FP_adis16265_gyroProtocolServer.h
    ${PROJECT_SOURCE_DIR}/fp/adis16265_gyro/v1.0/adis16265_gyro_server/FP_adis16265_gyroProtocolTypes.h
    ${PROJECT_SOURCE_DIR}/fp/adis16265_gyro/v1.0/adis16265_gyro_server/FP_adis16265_gyroServerApp.c
    ${PROJECT_SOURCE_DIR}/fp/adis16265_gyro/v1.0/adis16265_gyro_server/FP_adis16265_gyroServerApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/adis16265_gyro/v1.0/adis16265_gyro_server/FP_adis16265_gyroProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_adis16265_gyroProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/adis16265_gyro/v1.0/adis16265_gyro_server/FP_adis16265_gyroServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "adis16265_gyroServerAppInit()\;"
)

list(APPEND adis16265_gyro_sources
    ${fp_adis16265_gyro_src_list}
)

FP_GEN_AT_PATH(fp_adis16265_gyro_src_list ${adis16265_gyro_fdepl_path} adis16265_gyro_fidl_path ${fp_gen_path})

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}/inc"
    "%{PROJECT_SOURCE_DIR}/fp"
    "${PROJECT_SOURCE_DIR}"
    )

list (APPEND adis16265_gyro_sources
    "src/adis16265_driver.c"
    )

add_library(${PROJECT_NAME} STATIC
    ${adis16265_gyro_sources}
)

list(APPEND adis16265_gyro_libs
    nvm
    assertions
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} ${adis16265_gyro_libs})
