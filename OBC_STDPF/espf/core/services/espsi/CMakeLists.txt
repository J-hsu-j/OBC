project(espsi_srv C)

include(${ROOT_BUILD_PATH}/espf.cmake)

cmake_path(SET fp_gen_path "${PROJECT_SOURCE_DIR}/fp")

#
# Global declarations for "MacServices"
#
cmake_path(SET macservices_fdepl_path "${PROJECT_SOURCE_DIR}/config/MacServices.fdepl")
cmake_path(SET macservices_fidl_path "${FIDL_ROOT}/common/fp/MacServices.fidl")

list(APPEND fp_macservices_src_list
    ${PROJECT_SOURCE_DIR}/fp/MacServices/v0.1/MacServices_server/FP_MacServicesProtocolServer.c
    ${PROJECT_SOURCE_DIR}/fp/MacServices/v0.1/MacServices_server/FP_MacServicesProtocolServer.h
    ${PROJECT_SOURCE_DIR}/fp/MacServices/v0.1/MacServices_server/FP_MacServicesProtocolTypes.h
    ${PROJECT_SOURCE_DIR}/fp/MacServices/v0.1/MacServices_server/FP_MacServicesServerApp.c
    ${PROJECT_SOURCE_DIR}/fp/MacServices/v0.1/MacServices_server/FP_MacServicesServerApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/MacServices/v0.1/MacServices_server/FP_MacServicesProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_MacServicesProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/MacServices/v0.1/MacServices_server/FP_MacServicesServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "MacServicesServerAppInit()\;"
)

#
# Global declarations for "ModuleId"
#
cmake_path(SET moduleid_fdepl_path "${PROJECT_SOURCE_DIR}/config/ModuleId.fdepl")
cmake_path(SET moduleid_fidl_path "${FIDL_ROOT}/common/fp/ModuleId.fidl")

list(APPEND fp_moduleid_src_list
    ${PROJECT_SOURCE_DIR}/fp/ModuleId/v0.1/ModuleId_server/FP_ModuleIdProtocolServer.c
    ${PROJECT_SOURCE_DIR}/fp/ModuleId/v0.1/ModuleId_server/FP_ModuleIdProtocolServer.h
    ${PROJECT_SOURCE_DIR}/fp/ModuleId/v0.1/ModuleId_server/FP_ModuleIdProtocolTypes.h
    ${PROJECT_SOURCE_DIR}/fp/ModuleId/v0.1/ModuleId_server/FP_ModuleIdServerApp.c
    ${PROJECT_SOURCE_DIR}/fp/ModuleId/v0.1/ModuleId_server/FP_ModuleIdServerApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/ModuleId/v0.1/ModuleId_server/FP_ModuleIdProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_ModuleIdProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/ModuleId/v0.1/ModuleId_server/FP_ModuleIdServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "ModuleIdServerAppInit()\;"
)

#
# Global declarations for "FileManager"
#
cmake_path(SET filemanager_fdepl_path "${PROJECT_SOURCE_DIR}/config/FileManager.fdepl")
cmake_path(SET filemanager_fidl_path "${FIDL_ROOT_OBC}/FileManager.fidl")

list(APPEND fp_filemanager_src_list
    ${PROJECT_SOURCE_DIR}/fp/FileManager/v1.2/FileManager_server/FP_FileManagerProtocolServer.c
    ${PROJECT_SOURCE_DIR}/fp/FileManager/v1.2/FileManager_server/FP_FileManagerProtocolServer.h
    ${PROJECT_SOURCE_DIR}/fp/FileManager/v1.2/FileManager_server/FP_FileManagerProtocolTypes.h
    ${PROJECT_SOURCE_DIR}/fp/FileManager/v1.2/FileManager_server/FP_FileManagerServerApp.c
    ${PROJECT_SOURCE_DIR}/fp/FileManager/v1.2/FileManager_server/FP_FileManagerServerApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/FileManager/v1.2/FileManager_server/FP_FileManagerProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_FileManagerProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/FileManager/v1.2/FileManager_server/FP_FileManagerServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "FileManagerServerAppInit()\;"
)

#
# Global declarations for "obc"
#
cmake_path(SET obc_fdepl_path "${PROJECT_SOURCE_DIR}/config/obc.fdepl")
cmake_path(SET obc_fidl_path "${FIDL_ROOT_OBC}/obc.fidl")

list(APPEND fp_obc_src_list
    ${PROJECT_SOURCE_DIR}/fp/obc/v4.1/obc_server/FP_obcProtocolServer.c
    ${PROJECT_SOURCE_DIR}/fp/obc/v4.1/obc_server/FP_obcProtocolServer.h
    ${PROJECT_SOURCE_DIR}/fp/obc/v4.1/obc_server/FP_obcProtocolTypes.h
    ${PROJECT_SOURCE_DIR}/fp/obc/v4.1/obc_server/FP_obcServerApp.c
    ${PROJECT_SOURCE_DIR}/fp/obc/v4.1/obc_server/FP_obcServerApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/obc/v4.1/obc_server/FP_obcProtocolServer.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_obcProtocolServerInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/obc/v4.1/obc_server/FP_obcServerApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "obcServerAppInit()\;"
)

#
# Global declarations for "UHF"
#
cmake_path(SET uhf_fdepl_path "${PROJECT_SOURCE_DIR}/config/UHF.fdepl")
cmake_path(SET uhf_fidl_path "${FIDL_ROOT}/uhf/fp/UHF2.fidl")

list(APPEND fp_uhf_src_list
    ${PROJECT_SOURCE_DIR}/fp/UHF/v0.5/UHF_client/FP_UHFProtocolClient.c
    #${PROJECT_SOURCE_DIR}/fp/UHF/v0.5/UHF_client/FP_UHFProtocolClient.h
    #${PROJECT_SOURCE_DIR}/fp/UHF/v0.5/UHF_client/FP_UHFProtocolTypes.h
    ${PROJECT_SOURCE_DIR}/fp/UHF/v0.5/UHF_client/FP_UHFClientApp.c
    #${PROJECT_SOURCE_DIR}/fp/UHF/v0.5/UHF_client/FP_UHFClientApp.h
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
    "#include \"fp/UHF/v0.5/UHF_client/FP_UHFProtocolClient.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
    "&FP_UHFProtocolClientInfo"
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
    "#include \"fp/UHF/v0.5/UHF_client/FP_UHFClientApp.h\""
)

set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
    "UHFClientAppInit()\;"
)

if (ES_TASK_STATS_ENABLED)
#
# Global declarations for "task_stat"
#
    cmake_path(SET task_stat_fdepl_path "${PROJECT_SOURCE_DIR}/config/task_stat.fdepl")
    cmake_path(SET task_stat_fidl_path "${FIDL_ROOT_OBC}/task_stat.fidl")

    list(APPEND fp_task_stat_src_list
        ${PROJECT_SOURCE_DIR}/fp/task_stat/v0.1/task_stat_server/FP_task_statProtocolServer.c
        ${PROJECT_SOURCE_DIR}/fp/task_stat/v0.1/task_stat_server/FP_task_statProtocolServer.h
        ${PROJECT_SOURCE_DIR}/fp/task_stat/v0.1/task_stat_server/FP_task_statProtocolTypes.h
        ${PROJECT_SOURCE_DIR}/fp/task_stat/v0.1/task_stat_server/FP_task_statServerApp.c
        ${PROJECT_SOURCE_DIR}/fp/task_stat/v0.1/task_stat_server/FP_task_statServerApp.h
    )

    set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_INCLUDE_LIST
        "#include \"fp/task_stat/v0.1/task_stat_server/FP_task_statProtocolServer.h\""
    )

    set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_HANDLERS_LIST
        "&FP_task_statProtocolServerInfo"
    )

    set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INCLUDE_LIST
        "#include \"fp/task_stat/v0.1/task_stat_server/FP_task_statServerApp.h\""
    )

    set_property(GLOBAL APPEND PROPERTY FUNCTION_PROTOCOL_APP_INIT_LIST
        "task_statServerAppInit()\;"
    )

    list(APPEND espsi_fp_sources ${fp_task_stat_src_list})
    FP_GEN_AT_PATH(fp_task_stat_src_list ${task_stat_fdepl_path} task_stat_fidl_path ${fp_gen_path})
endif (ES_TASK_STATS_ENABLED)


list(APPEND espsi_fp_sources
    ${fp_macservices_src_list}
    ${fp_moduleid_src_list}
    ${fp_filemanager_src_list}
    ${fp_obc_src_list}
    ${fp_uhf_src_list}
)

FP_GEN_AT_PATH(fp_macservices_src_list ${macservices_fdepl_path} macservices_fidl_path ${fp_gen_path})
FP_GEN_AT_PATH(fp_moduleid_src_list ${moduleid_fdepl_path} moduleid_fidl_path ${fp_gen_path})
FP_GEN_AT_PATH(fp_filemanager_src_list ${filemanager_fdepl_path} filemanager_fidl_path ${fp_gen_path})
FP_GEN_AT_PATH(fp_obc_src_list ${obc_fdepl_path} obc_fidl_path ${fp_gen_path})
FP_GEN_AT_PATH(fp_uhf_src_list ${uhf_fdepl_path} uhf_fidl_path ${fp_gen_path})

# The rest of the ESPS sources that are not FP
if (COMM_ESPS_ENABLED)
    list(APPEND esps_srv_sources
        ${CMAKE_CURRENT_SOURCE_DIR}/cp/CP_Handler.c
        ${CMAKE_CURRENT_SOURCE_DIR}/cp/cp_cmd_handler.c
        ${CMAKE_CURRENT_SOURCE_DIR}/cp/CP_Fault_Commands.c
        ${CMAKE_CURRENT_SOURCE_DIR}/cp/CP_SX_Band_Commands.c
        ${CMAKE_CURRENT_SOURCE_DIR}/fwupd/FWUPD_Handler.c
        ${CMAKE_CURRENT_SOURCE_DIR}/fwupd/FWUPD_Persistor.c
        ${CMAKE_CURRENT_SOURCE_DIR}/tp/ESSA_Stack_TP_Layer.c
    )

    if(SXBAND_SCHEDULER_ENABLED)
        list(APPEND libraries_list
            sxband_sched
        )
    endif(SXBAND_SCHEDULER_ENABLED)

    list(APPEND libraries_list
        fault_persistor
        sxband_pl_ctrl
        CFB
    )

    if (CUBEADCS_GEN2_ENABLED)
        list(APPEND esps_srv_sources
            ${CMAKE_CURRENT_SOURCE_DIR}/cp/CP_CubeADCS_Gen2_Commands.c
        )
        list(APPEND libraries_list
            cubeadcs
        )
    endif (CUBEADCS_GEN2_ENABLED)

endif (COMM_ESPS_ENABLED)

add_library(${PROJECT_NAME} STATIC
    ${espsi_fp_sources}
    ${esps_srv_sources}
)

list(APPEND module_includes
    ${PROJECT_SOURCE_DIR}
)

list(APPEND libraries_list
    eps_i
    file_tools
    nvm_rc
)

if (COMM_GW_ENABLED)
    list(APPEND libraries_list
        comm_gw)
endif (COMM_GW_ENABLED)

if (BEACONS_ENABLED)
    list(APPEND libraries_list
        beacons)
endif (BEACONS_ENABLED)

list(APPEND libraries_list comm_loss_wd)

target_include_directories(${PROJECT_NAME} PUBLIC ${module_includes} ${PROJECT_SOURCE_DIR}/fp/obc/v4.1/obc_server)
target_link_libraries(${PROJECT_NAME} ${libraries_list})