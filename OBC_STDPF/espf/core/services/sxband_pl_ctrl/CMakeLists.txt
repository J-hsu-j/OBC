project(sxband_pl_ctrl C)

include(${ROOT_BUILD_PATH}/espf.cmake)

list(APPEND module_sources
	"src/sxband_pl_ctrl.c"
)

add_library(${PROJECT_NAME} STATIC
    ${module_sources}
)

list(APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/inc"
)

if (SXBAND_SCHEDULER_ENABLED)
list(APPEND sxband_libs sxband_sched)
target_link_libraries(${PROJECT_NAME} ${sxband_libs} eps_ctrl)
endif (SXBAND_SCHEDULER_ENABLED)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
