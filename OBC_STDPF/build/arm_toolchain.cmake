set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# If the compiler is not in the PATH and you need to set the COMPILER_PATH variable there is a
#   chance that the path is not found without the specific .exe extension in windows.
if(CMAKE_HOST_WIN32)
    set(EXE_EXTENSION ".exe")
endif()

# Some default GCC settings
# Uncomment to set a specific path to the compiler
# set(COMPILER_PATH                  "C:/ST/STM32CubeIDE_1.14.1/STM32CubeIDE/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.11.3.rel1.win32_1.1.100.202309141235/tools/bin/")
set(TOOLCHAIN_PREFIX                ${COMPILER_PATH}arm-none-eabi-)

set(CMAKE_C_COMPILER                ${TOOLCHAIN_PREFIX}gcc${EXE_EXTENSION})
set(CMAKE_ASM_COMPILER              ${CMAKE_C_COMPILER})
set(CMAKE_CXX_COMPILER              ${TOOLCHAIN_PREFIX}g++${EXE_EXTENSION})
set(CMAKE_LINKER                    ${TOOLCHAIN_PREFIX}gcc${EXE_EXTENSION})
set(CMAKE_OBJCOPY                   ${TOOLCHAIN_PREFIX}objcopy${EXE_EXTENSION})
set(CMAKE_OBJDUMP                   ${TOOLCHAIN_PREFIX}objdump${EXE_EXTENSION})
set(CMAKE_SIZE                      ${TOOLCHAIN_PREFIX}size${EXE_EXTENSION})

set(CMAKE_EXECUTABLE_SUFFIX_ASM     ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_C       ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_CXX     ".elf")

# MCU specific flags
set(TARGET_FLAGS "-mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${TARGET_FLAGS}")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} ${TARGET_FLAGS} -g3 -c -x assembler-with-cpp -MMD -MP")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TARGET_FLAGS}")
set(CMAKE_C_LINK_FLAGS "${CMAKE_C_LINK_FLAGS} ${TARGET_FLAGS}")

set(CMAKE_EXE_LINKER_FLAGS "--specs=nosys.specs" CACHE INTERNAL "")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
