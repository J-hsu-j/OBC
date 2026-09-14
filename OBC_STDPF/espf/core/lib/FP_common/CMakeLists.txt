project(espsi_common C)

add_library(espsi_common STATIC
    "FP_BaseProtocolTypes.h"
    "FP_Helpers.c"
    "FP_Helpers.h"
    "FP_ProtocolServerCommon.c"
    "FP_ProtocolServerCommon.h"
    "fp_trace.c"
)

target_include_directories(espsi_common PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(espsi_common PRIVATE ESPSI libtrace)
