project(ssp C)

include(${PROJECT_SOURCE_DIR}/fidl.cmake)

add_library(${PROJECT_NAME} STATIC
	"src/sp_service.c"
    ${fp_ssp_src_list}
)

# regenerate fp code
add_dependencies(${PROJECT_NAME} ssp-fidl-gen)

list(APPEND module_includes
    "${PROJECT_SOURCE_DIR}/"
    "${PROJECT_SOURCE_DIR}/inc"
    "${PROJECT_SOURCE_DIR}/fp/sp_uhf_ant/v2.1/sp_uhf_ant_client"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} PRIVATE nvm assertions)
