project(stm32_crypto C)

list(APPEND module_includes
    "${PROJECT_SOURCE_DIR}/include"
)

list(APPEND stm32_crypto_sources
    "${PROJECT_SOURCE_DIR}/src/dummy.c"
)

add_library(${PROJECT_NAME} STATIC
    ${stm32_crypto_sources}
)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes})
target_link_libraries(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/lib/libSTM32Cryptographic_CM7.a")

# Remove the -pedantic flag from the compile options
get_target_property(target_options ${PROJECT_NAME} COMPILE_OPTIONS)
list(REMOVE_ITEM target_options "-pedantic")
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_OPTIONS "${target_options}")
