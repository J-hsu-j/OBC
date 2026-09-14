project(taskmon C)

list(APPEND sources
    src/taskmon.c
)

if (ES_TASK_STATS_ENABLED)
    list(APPEND sources src/taskmon_stat.c)
endif()

add_library(${PROJECT_NAME} STATIC
    ${sources}
)

list(APPEND module_includes
    ${PROJECT_SOURCE_DIR}/inc
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} arm_fault_handler datacache)
