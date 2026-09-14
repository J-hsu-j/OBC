cmake_minimum_required(VERSION 3.20)
project(sdr-api)

set(CMAKE_VERBOSE_MAKEFILE ON)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.c)

add_library(sdr-api STATIC ${SRC_FILES})
target_link_libraries(sdr-api sdr-api-pb csp file_tools)

target_include_directories(sdr-api-pb
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)
