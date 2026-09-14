project(xband_fe_comm C)

include(${PROJECT_SOURCE_DIR}/fidl.cmake)

add_library(${PROJECT_NAME} STATIC
    "${PROJECT_SOURCE_DIR}/src/xband_fe_comm.c"
    "${PROJECT_SOURCE_DIR}/inc/xband_fe_comm.h"
    "${PROJECT_SOURCE_DIR}/src/xband_fe_proto.c"
    "${PROJECT_SOURCE_DIR}/inc/xband_fe_proto.h"
    ${fp_xband_fe_src_list}
)

add_dependencies(${PROJECT_NAME} xband-fe-fidl-gen)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/inc"
    "${PROJECT_SOURCE_DIR}/fp/xband_fe/v0.1/xband_fe_server"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} comm_gw libtrace nvm payload_ctrl fdir_srv)
