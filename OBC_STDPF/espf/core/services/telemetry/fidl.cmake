#
# Global declarations for "telemetry"
#
cmake_path(SET fdepl_path "${PROJECT_SOURCE_DIR}/config/telemetry.fdepl")
cmake_path(SET fp_gen_path "${PROJECT_SOURCE_DIR}/fp")
cmake_path(SET fidl_path "${FIDL_ROOT_OBC}/telemetry.fidl")
set(tlm_fidl_ver "2.0")

list(APPEND fidl_dep_list
    ${fdepl_path} 
    ${fidl_path}
)

set(APPEND tlm_mod_includes_list
	"${PROJECT_SOURCE_DIR}/fp/telemetry/v${tlm_fidl_ver}/telemetry_server"
)

list(APPEND tlm_src_list
        "${PROJECT_SOURCE_DIR}/fp/telemetry/v${tlm_fidl_ver}/telemetry_server/FP_telemetryProtocolServer.c"
        "${PROJECT_SOURCE_DIR}/fp/telemetry/v${tlm_fidl_ver}/telemetry_server/FP_telemetryServerApp.c"
        "${PROJECT_SOURCE_DIR}/fp/telemetry/v${tlm_fidl_ver}/telemetry_server/FP_telemetryProtocolTypes.h"
        "${PROJECT_SOURCE_DIR}/fp/telemetry/v${tlm_fidl_ver}/telemetry_server/FP_telemetryProtocolServer.h"
        "${PROJECT_SOURCE_DIR}/fp/telemetry/v${tlm_fidl_ver}/telemetry_server/FP_telemetryServerApp.h"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/telemetry/v${tlm_fidl_ver}/telemetry_server/FP_telemetryProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_telemetryProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/telemetry/v${tlm_fidl_ver}/telemetry_server/FP_telemetryServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "telemetryServerAppInit()\;"
)

FP_GEN_AT_PATH(tlm_src_list ${fdepl_path} fidl_dep_list ${fp_gen_path})

add_custom_target(tlm-fidl-gen DEPENDS ${tlm_src_list})
