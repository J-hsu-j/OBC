# CMakeList.txt : CMake project for the libhsm unit test, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.12)

project ("test_hsm")

find_package(Python COMPONENTS Interpreter)

if(Python_Interpreter_FOUND)
  message(STATUS "Python interpreter found: ${Python_EXECUTABLE}")
  message(STATUS "Python version: ${Python_VERSION_MAJOR}.${Python_VERSION_MINOR}.${Python_VERSION_PATCH}")
else()
  message(FATAL_ERROR "Python interpreter not found but it is required in order to build ${PROJECT_NAME}")
endif()

# include the actual libhsm project
add_subdirectory("${PROJECT_SOURCE_DIR}/.." hsm)

cmake_path(SET yaml_sm_model "${PROJECT_SOURCE_DIR}/test_sm.yaml")
cmake_path(SET hsmgen_root_path "${PROJECT_SOURCE_DIR}/../hsmgen")

list(APPEND hsm_generated_c_files
     "${PROJECT_SOURCE_DIR}/test_sm_config.c"
     "${PROJECT_SOURCE_DIR}/test_sm_config_user.c"
)

# add sources to this project's executable.
add_executable (${PROJECT_NAME}
                "test.c"
                "test_env.c"
                ${hsm_generated_c_files}
)

# link to unity test framework
add_subdirectory(${PROJECT_SOURCE_DIR}/unity ${PROJECT_SOURCE_DIR}/unity/lib)

target_compile_definitions(${PROJECT_NAME} PUBLIC -DUTEST)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/../inc)

# we need to tune a bit the 'hsm' target library in order to properly build and link without external dependencies in the unit
# test environment

# Check the C++ compiler being used
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    message(STATUS "Using GCC")
    # GCC-specific settings
    target_compile_options(hsm PRIVATE -Wall -Werror)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    message(STATUS "Using MSVC")
    # MSVC-specific settings
    target_compile_options(hsm PRIVATE /WX)
endif()

target_compile_definitions(hsm PRIVATE -DUTEST)
target_include_directories(hsm PUBLIC ${PROJECT_SOURCE_DIR}/../cfg)
set_target_properties(hsm PROPERTIES INTERFACE_LINK_LIBRARIES "")

target_link_libraries(${PROJECT_NAME} PUBLIC unity hsm)

list(APPEND hsm_generated_file_list
     "${PROJECT_SOURCE_DIR}/test_sm.puml"
     "${PROJECT_SOURCE_DIR}/test_sm_config_user.h"
     "${PROJECT_SOURCE_DIR}/test_sm_user.h"
     "${hsm_generated_c_files}"
)

add_custom_command(
        OUTPUT ${hsm_generated_file_list}
        COMMAND ${Python_EXECUTABLE} -m hsmgen --conf ${yaml_sm_model} --outpath ${PROJECT_SOURCE_DIR} --templatepath ${hsmgen_root_path} VERBATIM
        DEPENDS ${yaml_sm_model}
)

add_custom_target(hsm_gen DEPENDS ${${hsm_generated_file_list}})
add_dependencies(${PROJECT_NAME} hsm_gen)
