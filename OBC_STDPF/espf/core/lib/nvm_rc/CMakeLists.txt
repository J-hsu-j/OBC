project(nvm_rc C)


add_library(${PROJECT_NAME} STATIC
    "src/nvm_rc.c"
)

target_include_directories(${PROJECT_NAME} PUBLIC inc)
target_link_libraries(${PROJECT_NAME} PUBLIC nvm)
