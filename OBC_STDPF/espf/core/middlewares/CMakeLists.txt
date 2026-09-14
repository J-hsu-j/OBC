project(espf_core_middleware C)

# Keep ESPSI in the top level build directory
add_subdirectory(ESPLATFORM_NETWORK_STACK ${CMAKE_BINARY_DIR}/ESPSI)
add_subdirectory(external/fatfs fatfs)
add_subdirectory(external/FreeRTOS freertos)
add_subdirectory(external/libcubeobc cubeobc)

list(APPEND ESPF_CORE_LIBS
    ESPSI
    fatfs
    freertos
    cubeobc
)

if (SDR_ENABLED)
    add_subdirectory(external/nanopb nanopb)
    list(APPEND ESPF_CORE_LIBS nanopb)
endif (SDR_ENABLED)

if (CSP_SUPPORT_ENABLED)
    add_subdirectory(external/csp csp)
    list(APPEND ESPF_CORE_LIBS csp)
endif (CSP_SUPPORT_ENABLED)

if (LWIP_SUPPORT_ENABLED)
    add_subdirectory(external/lwIP lwIP)
    list(APPEND ESPF_CORE_LIBS lwIP)
endif (LWIP_SUPPORT_ENABLED)

if (CRYPTO_SERVICE_ENABLED)
    add_subdirectory(external/ST/STM32_Cryptographic stm32_crypto)
    list(APPEND ESPF_CORE_LIBS stm32_crypto)
endif (CRYPTO_SERVICE_ENABLED)

# Make the libraries visible to the parent scope
set(ESPF_CORE_LIBS ${ESPF_CORE_LIBS} PARENT_SCOPE)
