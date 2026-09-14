project(comm_gw C)

list(
    APPEND module_sources
    "${PROJECT_SOURCE_DIR}/src/comm_gw.c"
    "${PROJECT_SOURCE_DIR}/src/comm_gw_if.c"
)

list(APPEND libraries_list
     libtrace)

if (COMM_RS485_MAC_LAYER_ENABLED)
    list(APPEND module_sources
        "${PROJECT_SOURCE_DIR}/src/comm_gw_fp.c"
        "${PROJECT_SOURCE_DIR}/src/comm_gw_cp.c")

    list(APPEND libraries_list
        espsi_drv
        ESPSI)
endif (COMM_RS485_MAC_LAYER_ENABLED)

if (CSP_SUPPORT_ENABLED)
    list(APPEND module_sources
        "${PROJECT_SOURCE_DIR}/src/comm_gw_csp.c"
)
    list(APPEND libraries_list
         csp)
endif (CSP_SUPPORT_ENABLED)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}/inc"
)

add_library(${PROJECT_NAME} STATIC
            ${module_sources}
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})

if (NOT libraries_list)
    target_link_libraries(${PROJECT_NAME} PUBLIC ${libraries_list})
endif()
