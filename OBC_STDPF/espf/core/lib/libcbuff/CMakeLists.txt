project(CBUFF C)

add_library(CBUFF STATIC
                 libqueue.c
)

target_include_directories(CBUFF PUBLIC ${PROJECT_SOURCE_DIR})
