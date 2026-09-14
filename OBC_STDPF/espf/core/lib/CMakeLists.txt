project(espf_core_lib C)

# Core libraries
add_subdirectory(assertions assertions)
add_subdirectory(cbuf cbuf)
add_subdirectory(cobs_inplace cobs_inplace)
add_subdirectory(crc crc)
add_subdirectory(irq irq)
add_subdirectory(libcbuff CBUFF)
add_subdirectory(libcobs COBS)
add_subdirectory(libcsq_algo libcsq_algo)
add_subdirectory(libdatetime datetime)
add_subdirectory(libhsm hsm)
add_subdirectory(libigrf igrf)
add_subdirectory(libsgp4 SGP4)
add_subdirectory(libtimer timer)
add_subdirectory(nvm_rc nvm_rc)
add_subdirectory(sys_printf sys_printf)
add_subdirectory(trace libtrace)

if (SDR_ENABLED)
    add_subdirectory(sdr-api-pb sdr-api-pb)
    add_subdirectory(sdr-api sdr-api)
    list(APPEND ESPF_CORE_LIBS
        sdr-api-pb
        sdr-api
    )
endif (SDR_ENABLED)

if (COMM_ESPS_ENABLED)
    add_subdirectory(FP_common espsi_common)
    list(APPEND ESPF_CORE_LIBS espsi_common)
endif (COMM_ESPS_ENABLED)

list(APPEND ESPF_CORE_LIBS
    assertions
    cbuf
    cobs_inplace
    crc
    irq
    CBUFF
    COBS
    libcsq_algo
    datetime
    hsm
    igrf
    SGP4
    timer
    nvm_rc
    sys_printf
    libtrace
)

# Build the libraries that don't have CMakeLists.txt on it
add_library(debug STATIC debug/src/debug.c)
target_include_directories(debug PUBLIC debug/inc)
target_link_libraries(debug PRIVATE stm32_hal)

# lib DataSink
add_library(datasink STATIC
    libDataSink/DataSink.c
    libDataSink/FileSink.c
)
target_include_directories(datasink PUBLIC libDataSink)

add_library(cdef INTERFACE)
target_include_directories(cdef INTERFACE cdef)

# lib CFB
add_library(CFB STATIC libCFB/CircularFlatBuffer.c)
target_include_directories(CFB PUBLIC libCFB)

# lib lz77
add_library(lz77 STATIC liblz77/es_lz77.c)
target_include_directories(lz77 PUBLIC liblz77)

# lib sys_instancer
add_library(sys_instancer STATIC sys_instancer/sys_instancer.c)
target_include_directories(sys_instancer PUBLIC sys_instancer)

list(APPEND ESPF_CORE_LIBS
    debug
    datasink
    cdef
    CFB
    lz77
    sys_instancer
)

# Make the libraries visible to the parent scope
set(ESPF_CORE_LIBS ${ESPF_CORE_LIBS} PARENT_SCOPE)
