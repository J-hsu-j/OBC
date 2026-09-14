project(gnss C)

include(${PROJECT_SOURCE_DIR}/fidl.cmake)

add_library(${PROJECT_NAME} STATIC
	"src/gnss.c"
    "src/gnss_resp.c"
    "src/gnss_uart.c"
    "src/gnss_power.c"
    "src/gnss_critical.c"
    "src/gnss_cmd.c"
    "src/gnss_logs.c"
    ${fp_gnss_src_list}
)

# regenerate fp code
add_dependencies(${PROJECT_NAME} gnss-fidl-gen)

list(APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/inc"
    "${PROJECT_SOURCE_DIR}/fp/gnss/v1.2/gnss_server"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes} PRIVATE "${PROJECT_SOURCE_DIR}/src")
target_link_libraries(${PROJECT_NAME} PUBLIC libtrace assertions stm32_hal fdir_srv pps nvm)
