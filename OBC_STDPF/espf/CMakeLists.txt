project(espf C)

list(APPEND OBC_includes
    "${CMAKE_CURRENT_SOURCE_DIR}/core/services/task_mon/inc"
)

list(
    APPEND OBC_sources
    "${CMAKE_CURRENT_SOURCE_DIR}/core/lib/tle/TleUpdate.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/core/lib/misc/CommandsApi.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/core/lib/module_id/src/module_id.c"
)

# ////////////////////////////////////////////////////
# 在你這個 CMakeLists.txt 裡，
# add_subdirectory(app), 
# add_subdirectory(arch/stm32h753iit/hal stm32_hal), 
# add_subdirectory(arch/stm32h753iit/drivers), 
# add_subdirectory(config), 
# add_subdirectory(core espf_core) 
# 這些就是在宣告「把 app / 底層 HAL / drivers / config / 
# core(含 services、middlewares、lib) 分別當成子模組納入」
# 。例如 add_subdirectory(arch/stm32h753iit/hal stm32_hal) 
# 這種兩參數寫法，第二個參數是在指定該子專案的 build 輸出目錄
# 名稱（放在 build tree 裡），讓不同子模組的產物/中間檔有更清
# 楚的分隔。
# /////////////////////////////////////////////////////

# Add the libraries and sources within the app folder
add_subdirectory(app)

#產出 stm32_hal library（純 HAL/LL + 硬體周邊驅動） (下層 CMakeLists.txt 會把驅動程式加入此 library)
add_subdirectory(arch/stm32h753iit/hal stm32_hal)
list(APPEND OBC_libraries stm32_hal)

# OBC_libraries is popyulated in the drivers CMakeLists
add_subdirectory(arch/stm32h753iit/drivers)

add_subdirectory(config)

#產出 espf_core（裡面再分成 lib/, middlewares/, services/） 
add_subdirectory(core espf_core)
list(APPEND OBC_libraries espf_core)

add_dependencies(espf_core eps_ctrl)

if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows" OR WIN32)
    set(NEWLINE_CHAR "\r\n")
    set(NEWLINE_STYLE_FOR_PLATFORM CRLF)
else()
    set(NEWLINE_CHAR "\n")
    set(NEWLINE_STYLE_FOR_PLATFORM UNIX)
endif()

# Generate ESSA_StackConfigServices.h with the configured services
get_property(TMP_LIST GLOBAL PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST)

set_property(GLOBAL PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST) # Unset global property
list(JOIN TMP_LIST ${NEWLINE_CHAR} FUNCTION_PROTOCOL_INCLUDE_LIST)
set(TMP_LIST) # Unset

set(FUNCTION_HANDLERS_LINE_ENDING ", \\${NEWLINE_CHAR}    ")

get_property(TMP_LIST GLOBAL PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST)
set_property(GLOBAL PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST) # Unset global property
list(JOIN TMP_LIST ", \\${NEWLINE_CHAR}    " FUNCTION_PROTOCOL_HANDLERS_LIST)
set(TMP_LIST) # Unset

configure_file(
    "${PROJECT_ROOT}/config/ESPLATFORM_NETWORK_STACK/inc/ESSA_StackConfigServices.h.tmpl"
    "${PROJECT_ROOT}/config/ESPLATFORM_NETWORK_STACK/inc/ESSA_StackConfigServices.h"
    NEWLINE_STYLE ${NEWLINE_STYLE_FOR_PLATFORM}
)

get_property(TMP_LIST GLOBAL PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST)
set_property(GLOBAL PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST) # Unset global property
list(JOIN TMP_LIST ${NEWLINE_CHAR} FUNCTION_PROTOCOL_APP_INCLUDE_LIST)
set(TMP_LIST) # Unset

get_property(TMP_LIST GLOBAL PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST)
set_property(GLOBAL PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST) # Unset global property
list(JOIN TMP_LIST "${NEWLINE_CHAR}    " FUNCTION_PROTOCOL_APP_INIT_LIST)
set(TMP_LIST) # Unset

configure_file(
    "${PROJECT_ROOT}/config/ESPLATFORM_NETWORK_STACK/inc/ESSA_StackConfigApps.h.tmpl"
    "${PROJECT_ROOT}/config/ESPLATFORM_NETWORK_STACK/inc/ESSA_StackConfigApps.h"
    NEWLINE_STYLE ${NEWLINE_STYLE_FOR_PLATFORM}
)

# Make the app sources visible to the parent scope
set(OBC_sources ${OBC_sources} PARENT_SCOPE)
set(OBC_includes ${OBC_includes} PARENT_SCOPE)
set(OBC_libraries ${OBC_libraries} PARENT_SCOPE)
