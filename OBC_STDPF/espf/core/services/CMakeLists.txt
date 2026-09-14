project(espf_core_services C)

add_subdirectory(payload_ctrl)
add_subdirectory(eps_ctrl)
add_subdirectory(nvm)
add_subdirectory(sys_time)
add_subdirectory(fault_persistor)
add_subdirectory(trace_level_config)
add_subdirectory(file_tools)
add_subdirectory(fdir_srv)
add_subdirectory(onboard_sched)
add_subdirectory(solar_panels)
add_subdirectory(taskmon)
add_subdirectory(comm_loss_wd)

list(APPEND ESPF_CORE_LIBS
    payload_ctrl
    eps_ctrl
    nvm
    sys_time
    fault_persistor
    trace_level_config
    file_tools
    fdir_srv
    onboard_sched
    ssp
    taskmon
    comm_loss_wd
)

if (XBAND_FE_ENABLED)
    add_subdirectory(xband_fe_comm)
    list(APPEND ESPF_CORE_LIBS xband_fe_comm)
endif()

if (ARDUCAM_ENABLED)
    add_subdirectory(arducam)
    list(APPEND ESPF_CORE_LIBS arducam)
endif(ARDUCAM_ENABLED)

if (COMM_GW_ENABLED)
    add_subdirectory(comm_gw)
    list(APPEND ESPF_CORE_LIBS comm_gw)
endif (COMM_GW_ENABLED)

if (SDR_ENABLED)
    add_subdirectory(sdr)
    list(APPEND ESPF_CORE_LIBS sdr)
endif (SDR_ENABLED)

if (CSP_SUPPORT_ENABLED)
    add_subdirectory(csp csp_service)

    if (FP_CSP_BINDER_ENABLED AND COMM_GW_ENABLED)
        add_subdirectory(fp_csp_binder)
        list(APPEND ESPF_CORE_LIBS
            fp_csp_binder
        )
    endif(FP_CSP_BINDER_ENABLED AND COMM_GW_ENABLED)

    list(APPEND ESPF_CORE_LIBS
        csp_service
    )
endif (CSP_SUPPORT_ENABLED)

if (LWIP_SUPPORT_ENABLED)
    add_subdirectory(netw netw)
    list(APPEND ESPF_CORE_LIBS netw)

    if (TFTPD_SUPPORT_ENABLED)
        add_subdirectory(tftpd)
        list(APPEND ESPF_CORE_LIBS tftpd)
    endif (TFTPD_SUPPORT_ENABLED)

endif (LWIP_SUPPORT_ENABLED)

add_subdirectory(aocs/aocs_cntrl aocs_cntrl_service)
list(APPEND ESPF_CORE_LIBS aocs_cntrl_service)

if (CUBEADCS_GEN2_ENABLED)
    add_subdirectory(aocs/cubeadcs_gen2 cubeadcs_gen2_service)
    list(APPEND ESPF_CORE_LIBS cubeadcs_gen2_service)
endif (CUBEADCS_GEN2_ENABLED)

add_subdirectory(rng)
list(APPEND ESPF_CORE_LIBS rng)

if (TELEMETRY_SERVICE_ENABLED)
    add_subdirectory(telemetry)
    list(APPEND ESPF_CORE_LIBS telemetry)
endif (TELEMETRY_SERVICE_ENABLED)

if (BEACONS_ENABLED)
    add_subdirectory(beacons)
    list(APPEND ESPF_CORE_LIBS beacons)
endif (BEACONS_ENABLED)

if (SXBAND_SCHEDULER_ENABLED)
    add_subdirectory(sxband_sched)
    list(APPEND ESPF_CORE_LIBS sxband_sched)
endif (SXBAND_SCHEDULER_ENABLED)

if (CRYPTO_SERVICE_ENABLED)
    add_subdirectory(crypto)
    list(APPEND ESPF_CORE_LIBS crypto)
endif (CRYPTO_SERVICE_ENABLED)

add_subdirectory(sxband_pl_ctrl)
list(APPEND ESPF_CORE_LIBS sxband_pl_ctrl)

add_subdirectory(sensor_data_service)
list(APPEND ESPF_CORE_LIBS sensor_data_service)

add_subdirectory(coordsys)
list(APPEND ESPF_CORE_LIBS coordsys)

add_subdirectory(actuator_control_service acs)
list(APPEND ESPF_CORE_LIBS acs)

if (COMM_ESPS_ENABLED)
add_subdirectory(espsi espsi_srv)
list(APPEND ESPF_CORE_LIBS espsi_srv)
endif(COMM_ESPS_ENABLED)

if (MICROPYTHON_SERVICE_ENABLED)
    add_subdirectory(upython)
    list(APPEND ESPF_CORE_LIBS upython)
endif(MICROPYTHON_SERVICE_ENABLED)

# lib aocs_tlm
add_library(aocs_tlm STATIC aocs/adcs_tlm/adcs_tlm.c)
target_include_directories(aocs_tlm PUBLIC aocs/adcs_tlm)
target_link_libraries(aocs_tlm PRIVATE cubeadcs)

# lib exeh
add_library(exeh STATIC exeh/src/es_exeh.c)
target_include_directories(exeh PUBLIC exeh/inc)

list(APPEND ESPF_CORE_LIBS
    aocs_tlm
    exeh
)

# Make the libraries visible to the parent scope
set(ESPF_CORE_LIBS ${ESPF_CORE_LIBS} PARENT_SCOPE)
