cmake_minimum_required(VERSION 3.20)
project(nanopb)

set(CMAKE_VERBOSE_MAKEFILE ON)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.c)

add_library(nanopb STATIC ${SRC_FILES})

target_include_directories(nanopb
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)
