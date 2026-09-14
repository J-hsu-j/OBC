project(espf_core C)

# To propagate the libraries from the subfolders to the parent scope
set(ESPF_CORE_LIBS "")

add_library(${PROJECT_NAME} INTERFACE)

add_subdirectory(lib)
add_subdirectory(middlewares)
add_subdirectory(services)

message(STATUS "ESPF_CORE_LIBS: ${ESPF_CORE_LIBS}")

target_link_libraries(${PROJECT_NAME} INTERFACE ${ESPF_CORE_LIBS})
