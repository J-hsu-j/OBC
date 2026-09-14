add_library(tlm_fp_types INTERFACE)

list(
    APPEND module_includes
    "${CMAKE_CURRENT_SOURCE_DIR}/telemetry/v2.0/telemetry_server"
)

target_include_directories(tlm_fp_types INTERFACE ${module_includes})

add_dependencies(tlm_fp_types tlm-fidl-gen)
