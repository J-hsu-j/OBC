project(hsm C)
add_library(${PROJECT_NAME} STATIC
    "src/libhsm.c"
)

target_include_directories(${PROJECT_NAME} PUBLIC PUBLIC inc)
target_link_libraries(${PROJECT_NAME} libhsm_trace)
