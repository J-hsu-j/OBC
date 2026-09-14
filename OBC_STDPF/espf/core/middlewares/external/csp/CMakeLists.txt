project(csp C)

add_library(${PROJECT_NAME} STATIC
    src/arch/csp_system.c
    src/arch/csp_time.c
    src/arch/freertos/csp_clock.c
    src/arch/freertos/csp_malloc.c
    src/arch/freertos/csp_queue.c
    src/arch/freertos/csp_semaphore.c
    src/arch/freertos/csp_system.c
    src/arch/freertos/csp_thread.c
    src/arch/freertos/csp_time.c
    src/crypto/csp_hmac.c
    src/crypto/csp_sha1.c
    src/crypto/csp_xtea.c
    src/csp_bridge.c
    src/csp_buffer.c
    src/csp_conn.c
    src/csp_crc32.c
    src/csp_debug.c
    src/csp_dedup.c
    src/csp_endian.c
    src/csp_hex_dump.c
    src/csp_iflist.c
    src/csp_init.c
    src/csp_io.c
    src/csp_port.c
    src/csp_promisc.c
    src/csp_qfifo.c
    src/csp_route.c
    src/csp_service_handler.c
    src/csp_services.c
    src/csp_sfp.c
    src/interfaces/csp_if_can.c
    src/interfaces/csp_if_can_pbuf.c
    src/interfaces/csp_if_i2c.c
    src/interfaces/csp_if_kiss.c
    src/interfaces/csp_if_lo.c
    src/rtable/csp_rtable.c
    src/rtable/csp_rtable_static.c
    src/transport/csp_rdp.c
    src/transport/csp_udp.c
)


target_include_directories(${PROJECT_NAME} PUBLIC ${OBC_includes} PUBLIC build/include include)

# Remove the -pedantic flag from the compile options
get_target_property(target_options ${PROJECT_NAME} COMPILE_OPTIONS)
list(REMOVE_ITEM target_options "-pedantic")
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_OPTIONS "${target_options}")
