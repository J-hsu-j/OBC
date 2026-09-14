project(crc C)

include(${ROOT_BUILD_PATH}/espf.cmake)

list(APPEND module_sources
	"src/crc16-ccitt.c"
	"src/es_crc32.c"
	"src/es_crc8.c"
	"src/MACCRC32_Classic_Impl.c"
)

add_library(${PROJECT_NAME} STATIC
    ${module_sources}
)

list(APPEND module_includes
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/inc"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME})
