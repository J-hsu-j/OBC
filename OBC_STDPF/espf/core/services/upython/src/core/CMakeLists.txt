# Top-level cmake file for building the MicroPython library for the EnduroSat OBC board

cmake_minimum_required(VERSION 3.12)

project(micropython C)

add_library(micropython STATIC)

# This is the default value for the uPython allocated heap region in KB
if (NOT UPY_HEAP_SIZE_KB)
    set(UPY_HEAP_SIZE_KB "120")
endif()

# Set the location of this port's directory
cmake_path(SET MICROPY_PORT_DIR "${PROJECT_SOURCE_DIR}")

# Set the location of the MicroPython repository
cmake_path(APPEND MICROPY_DIR "${EXT_MODS_ROOT_DIR}" "micropython")

# set environment variable for mpy-cross compiler tool
if(CMAKE_HOST_WIN32)
    set(SED_TOOL "${PROJECT_TOOLS_ROOT}/sed.exe ")
    set(MICROPY_MPYCROSS "${PROJECT_TOOLS_ROOT}/mpy_cross_compiler/win/mpy-cross.exe")
elseif(CMAKE_HOST_UNIX AND NOT CMAKE_HOST_APPLE)
    set(MICROPY_MPYCROSS "${PROJECT_TOOLS_ROOT}/mpy_cross_compiler/linux/mpy-cross")
endif()

set(MICROPY_TARGET micropython)
set(USER_C_MODULES      ${MICROPY_PORT_DIR}/cmodules/micropython.cmake)

include(${MICROPY_DIR}/py/py.cmake)
include(${MICROPY_DIR}/py/usermod.cmake)
include(${MICROPY_DIR}/extmod/extmod.cmake)

list(
    APPEND module_includes
    ${MICROPY_DIR}
    ${MICROPY_PORT_DIR}
    ${CMAKE_BINARY_DIR}
)

list(APPEND MICROPY_CPP_INC_EXTRA
    ${MICROPY_DIR}
    ${MICROPY_PORT_DIR}
    ${CMAKE_BINARY_DIR}
)

# message(FATAL_ERROR "MICROPY_CPP_INC: ${MICROPY_CPP_INC}")

set(MICROPY_SOURCE_PORT
    main.c
    uart_core.c
    modtime.c
    freertos_mphal.c
    upy_sd.c
)
list(TRANSFORM MICROPY_SOURCE_PORT PREPEND ${MICROPY_PORT_DIR}/)

set(MICROPY_SOURCE_SHARED
    libc/printf.c
    readline/readline.c
    runtime/pyexec.c
    runtime/stdout_helpers.c
    runtime/sys_stdio_mphal.c
    runtime/gchelper_generic.c
    timeutils/timeutils.c
)
list(TRANSFORM MICROPY_SOURCE_SHARED PREPEND ${MICROPY_DIR}/shared/)


set(MICROPY_SOURCE_LIB
)
list(TRANSFORM MICROPY_SOURCE_LIB PREPEND ${MICROPY_DIR}/lib/)

# this must be after including py.cmake
set(MICROPY_SOURCE_QSTR
    ${MICROPY_SOURCE_USERMOD}
    ${MICROPY_SOURCE_PY}
    ${MICROPY_SOURCE_EXTMOD}
    ${MICROPY_SOURCE_SHARED}
    ${MICROPY_SOURCE_LIB}
    ${MICROPY_SOURCE_PORT}
)

list(
    APPEND module_sources
    ${MICROPY_SOURCE_PY}
    ${MICROPY_SOURCE_EXTMOD}
    ${MICROPY_SOURCE_SHARED}
    ${MICROPY_SOURCE_PORT}
    ${MICROPY_SOURCE_LIB}
)

# Save the manifest file set from the cmake command line.
set(MICROPY_USER_FROZEN_MANIFEST ${MICROPY_FROZEN_MANIFEST})

# Define mpy-cross flags, for use with frozen code.
# Note: If the cross compilation fails with the configured heap size, it means your frozen modules
# require more heap and cannot be put in the system.
set(MICROPY_CROSS_FLAGS "-march=armv7emsp -X heapsize=${UPY_HEAP_SIZE_KB}k")

#  The mpz is used as configuration, becaue in such way we can compile all
#  python files generated for fidles. The reason "none" cannot be used
#  is because in the generated files there are already variables which are
#  using 32 bits.
set(MPY_TOOL_FLAGS -mlongint-impl=mpz)


# Set the frozen manifest file. Note if MICROPY_FROZEN_MANIFEST is set from the cmake
# command line, then it will override the default and any manifest set by the board.
if (MICROPY_USER_FROZEN_MANIFEST)
    set(MICROPY_FROZEN_MANIFEST ${MICROPY_USER_FROZEN_MANIFEST})
elseif (NOT MICROPY_FROZEN_MANIFEST)
    set(MICROPY_FROZEN_MANIFEST ${MICROPY_PORT_DIR}/manifest.py)
endif()

add_custom_command(
    OUTPUT always_build_micropy_modules
    COMMENT "Building external MPY modules"
    COMMAND ${Python3_EXECUTABLE} ${MICROPY_DIR}/tools/mpy_cross_all.py -o ${MICROPY_PORT_DIR}/mpy_output ${MICROPY_PORT_DIR}/pymodules
)

target_sources(micropython PRIVATE ${module_sources})
target_include_directories(micropython PUBLIC ${module_includes})
target_include_directories(micropython PRIVATE
    "${PROJECT_ROOT}/config/datacache/fp/data_cache/v0.1/data_cache_server"
    "${PROJECT_ROOT}/core/services/xband_fe_comm/fp/xband_fe/v0.1/xband_fe_server"
    "${PROJECT_ROOT}/core/services/sdr/fp/sdr/v1.2/sdr_server"
    "${PROJECT_ROOT}/core/lib"
)

# Normally you should not need to add explicitely the ROOT_COMPILE_DEFS but currently the micropython target does not see them otherwise.
target_compile_definitions(micropython PRIVATE ${ROOT_COMPILE_DEFS})

# Remove -pedantic compiler option for micropython, there are too many warnings from the implementation of micropython itself.
get_target_property(target_options micropython COMPILE_OPTIONS)
list(REMOVE_ITEM target_options "-pedantic")
list(APPEND target_options "-DUPY_HEAP_SIZE_KB=${UPY_HEAP_SIZE_KB}")
set_target_properties(micropython PROPERTIES COMPILE_OPTIONS "${target_options}")

list(APPEND upy_libs
     file_tools
     usermod
     sys_time
     libtrace
     assertions
     espsi_common)

if (COMM_GW_ENABLED)
list (APPEND upy_libs comm_gw)
endif()

target_link_libraries(micropython PRIVATE ${upy_libs})

#
# function GET_TARGET_INCLUDES:
# The function collects specific includes for any additional modules configured
#
# Example:
#   GET_TARGET_INCLUDES( sys_time
#                    MICROPY_CPP_INC_EXTRA)
#
#    This call adds to the MICROPY_CPP_INC_EXTRA all specific includes for the sys_time target.
#
function(GET_TARGET_INCLUDES TARGET_NAME TARGET_SPECIFIC_INCLUDES)
    set(target_inc_dirs "")
    set(target_source_dir "")
    get_target_property (target_inc_dirs ${TARGET_NAME} INCLUDE_DIRECTORIES)
    get_target_property (target_source_dir ${TARGET_NAME} SOURCE_DIR)

    foreach(_arg ${target_inc_dirs})
        string(COMPARE LESS_EQUAL ${target_source_dir} ${_arg} result)
        if(${result})
            list(APPEND "${TARGET_SPECIFIC_INCLUDES}" ${_arg} )
        endif()
    endforeach()

    set(${TARGET_SPECIFIC_INCLUDES} ${${TARGET_SPECIFIC_INCLUDES}} PARENT_SCOPE)
endfunction()

#   In many cases it is needed for compilation of MPY_CROSS modules to have
#   access to include paths from the TOP Level project. As
#   "target_link_libraries" does not work for MPY_CROSS build step we need
#   to add the needed Include folders manually to MICROPY_CPP_INC_EXTRA variable.

GET_TARGET_INCLUDES( sys_time
                    MICROPY_CPP_INC_EXTRA)

GET_TARGET_INCLUDES( ESPSI
                     MICROPY_CPP_INC_EXTRA)

GET_TARGET_INCLUDES( file_tools
                    MICROPY_CPP_INC_EXTRA)

include(${MICROPY_DIR}/py/mkrules.cmake)

target_include_directories(micropython PRIVATE ${MICROPY_GENHDR_DIR} ${MICROPY_DIR}/mpy-cross/build/genhdr)
