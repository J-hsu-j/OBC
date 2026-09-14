project(nvm C)

add_library(${PROJECT_NAME} STATIC
    ${PROJECT_SOURCE_DIR}/src/nvm.c
    ${PROJECT_SOURCE_DIR}/src/nvm_task.c
)

list(
    APPEND module_includes
    ${PROJECT_SOURCE_DIR}/inc
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} PUBLIC nvm_cfg assertions file_tools)
