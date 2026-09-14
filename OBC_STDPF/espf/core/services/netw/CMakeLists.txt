project(netw C)

include(${ROOT_BUILD_PATH}/espf.cmake)

add_library(${PROJECT_NAME} STATIC
    "src/netw.c"
)

list(
    APPEND module_includes
    "${PROJECT_SOURCE_DIR}/inc"
)

list(APPEND libs
    lwIP
)

if (ETHERNET_SUPPORT_ENABLED)
list(APPEND libs
	ethernetif
)
endif (ETHERNET_SUPPORT_ENABLED)

if (TFTPD_SUPPORT_ENABLED)
list(APPEND libs
    tftpd
)
endif (TFTPD_SUPPORT_ENABLED)

if (SLIP_SUPPORT_ENABLED)
    list(APPEND libs
         slipif
    )
endif (SLIP_SUPPORT_ENABLED)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} PUBLIC ${libs})
