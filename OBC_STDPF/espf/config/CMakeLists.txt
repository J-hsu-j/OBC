# This cmake sources is only to add the required sources and includes to the OBC target.
#  It does not define the target itself.

list(APPEND OBC_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/aocs/adcs_tlm/adcs_tlm_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/aocs/aocs_cntrl/aocs_cntrl_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/aocs/aocs_cntrl/aocs_cntrl_cubeadcs_int.c
    ${CMAKE_CURRENT_SOURCE_DIR}/arch/stm32h753iit/MCU_Init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/arch/stm32h753iit/stm32h7xx_hal_msp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/arch/stm32h753iit/stm32h7xx_hal_timebase_tim.c
    ${CMAKE_CURRENT_SOURCE_DIR}/arch/stm32h753iit/sys_hook_dispatcher.c
    ${CMAKE_CURRENT_SOURCE_DIR}/arch/stm32h753iit/syscall_stubs.c
    ${CMAKE_CURRENT_SOURCE_DIR}/arch/stm32h753iit/system_stm32h7xx.c
    ${CMAKE_CURRENT_SOURCE_DIR}/arch/stm32h753iit/UnhandledISRs.c
    ${CMAKE_CURRENT_SOURCE_DIR}/assertions/assertions_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/beacons/beacons_cfg_user.c
    ${CMAKE_CURRENT_SOURCE_DIR}/datacache/datacache.c
    ${CMAKE_CURRENT_SOURCE_DIR}/datacache/datacache_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/eps_i/eps_i_config.c
    ${CMAKE_CURRENT_SOURCE_DIR}/eps_ii/eps_ii_config.c
    ${CMAKE_CURRENT_SOURCE_DIR}/eps_iii/eps_iii_config.c
    ${CMAKE_CURRENT_SOURCE_DIR}/es_sxband/es_sxband_config.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ESPLATFORM_NETWORK_STACK/src/ESSA_CommonUtils.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ESPLATFORM_NETWORK_STACK/src/ESSA_ServiceProtocol_Handler.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ESPLATFORM_NETWORK_STACK/src/ESSA_Stack_Facade.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ESPLATFORM_NETWORK_STACK/src/ESSA_StackConfig.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ESPLATFORM_NETWORK_STACK/src/FWUPD_Handler_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/exeh/src/es_exeh_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/fdir_srv/fdir_srv_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/freertos/freertos.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libdatetime/datetime_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/module_id/src/module_id_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/payload_ctrl/payload_ctrl_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sband_tmtc/sband_tmtc_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sensor_data_service/sensor_css_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sensor_data_service/sensor_data_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sensor_data_service/sensor_gyro_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sensor_data_service/sensor_mag_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sensor_data_service/sensor_temp_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sys_conf/sys_conf.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sys_conf/sys_mod.c
    ${CMAKE_CURRENT_SOURCE_DIR}/trace_config/src/trace_config.c
)


list(APPEND OBC_includes
    ${CMAKE_CURRENT_SOURCE_DIR}/aocs/adcs_tlm
    ${CMAKE_CURRENT_SOURCE_DIR}/aocs/aocs_cntrl
    ${CMAKE_CURRENT_SOURCE_DIR}/arch/stm32h753iit
    ${CMAKE_CURRENT_SOURCE_DIR}/arm_fault_handler
    ${CMAKE_CURRENT_SOURCE_DIR}/assertions
    ${CMAKE_CURRENT_SOURCE_DIR}/cbuf
    ${CMAKE_CURRENT_SOURCE_DIR}/comm_gw/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/conops
    ${CMAKE_CURRENT_SOURCE_DIR}/crypto
    ${CMAKE_CURRENT_SOURCE_DIR}/datacache
    ${CMAKE_CURRENT_SOURCE_DIR}/eps_ctrl
    ${CMAKE_CURRENT_SOURCE_DIR}/eps_i
    ${CMAKE_CURRENT_SOURCE_DIR}/eps_ii
    ${CMAKE_CURRENT_SOURCE_DIR}/eps_iii
    ${CMAKE_CURRENT_SOURCE_DIR}/es_sxband
    ${CMAKE_CURRENT_SOURCE_DIR}/ESPLATFORM_NETWORK_STACK/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/exeh/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/fatfs
    ${CMAKE_CURRENT_SOURCE_DIR}/fdir_srv
    ${CMAKE_CURRENT_SOURCE_DIR}/freertos
    ${CMAKE_CURRENT_SOURCE_DIR}/GlobalConfig
    ${CMAKE_CURRENT_SOURCE_DIR}/libdebug
    ${CMAKE_CURRENT_SOURCE_DIR}/libhsm/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/module_id/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/netw
    ${CMAKE_CURRENT_SOURCE_DIR}/nvm/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/nvm_appcfg/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/nvm_bootcfg/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/onboard_sched
    ${CMAKE_CURRENT_SOURCE_DIR}/payload_ctrl
    ${CMAKE_CURRENT_SOURCE_DIR}/sband_tmtc
    ${CMAKE_CURRENT_SOURCE_DIR}/sdr/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/sensor_data_service
    ${CMAKE_CURRENT_SOURCE_DIR}/sys_conf
    ${CMAKE_CURRENT_SOURCE_DIR}/sys_printf/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/taskmon
    ${CMAKE_CURRENT_SOURCE_DIR}/trace_config/inc
)

add_subdirectory(nvm nvm_cfg)
add_subdirectory(eps_ctrl eps_ctrl_cfg)
add_subdirectory(datacache)
add_subdirectory(libhsm libhsm_trace)

list(APPEND OBC_libraries
    datacache
    nvm_cfg
    libhsm_trace
    eps_gen
    eps_ctrl_cfg
)

if (XBAND_FE_ENABLED)
    list(APPEND OBC_libraries
        xband_fe_comm
    )    
endif (XBAND_FE_ENABLED)

if ((SLIP_SUPPORT_ENABLED) AND (LWIP_SUPPORT_ENABLED))
    list(APPEND OBC_sources
        ${CMAKE_CURRENT_SOURCE_DIR}/slipif/slipif_cfg.c
    )
    list(APPEND OBC_includes
        ${CMAKE_CURRENT_SOURCE_DIR}/slipif
    )
endif ((SLIP_SUPPORT_ENABLED) AND (LWIP_SUPPORT_ENABLED))

if (LWIP_SUPPORT_ENABLED)
    list(APPEND OBC_includes
        ${CMAKE_CURRENT_SOURCE_DIR}/lwIP
    )
    list(APPEND OBC_sources
        ${CMAKE_CURRENT_SOURCE_DIR}/lwIP/sys_hal.c
        ${CMAKE_CURRENT_SOURCE_DIR}/lwIP/lwip_tracer.c       
    )
endif (LWIP_SUPPORT_ENABLED)

if (CRYPTO_SERVICE_ENABLED)
    list(APPEND OBC_sources
        ${CMAKE_CURRENT_SOURCE_DIR}/STM32_Cryptographic/cmox_low_level.c
    )
endif (CRYPTO_SERVICE_ENABLED)

if (CSP_SUPPORT_ENABLED)
    list(APPEND OBC_includes
        ${CMAKE_CURRENT_SOURCE_DIR}/csp/inc
    )
endif (CSP_SUPPORT_ENABLED)

if (SXBAND_SCHEDULER_ENABLED)
    list(APPEND OBC_includes
        ${CMAKE_CURRENT_SOURCE_DIR}/sxband_sched
    )
endif (SXBAND_SCHEDULER_ENABLED)

if (COMM_ESPS_MAC_PHY_ENABLED)
    list(APPEND esps_mac_phy_includes
        ${CMAKE_CURRENT_SOURCE_DIR}/espsi_drv/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/arch/stm32h753iit/drivers/comm/espsi_drv/inc
    )

    list(APPEND esps_mac_phy_sources
        ${CMAKE_CURRENT_SOURCE_DIR}/espsi_drv/src/esps_drv_config.c
        ${CMAKE_CURRENT_SOURCE_DIR}/espsi_drv/src/esps_drv_dispatcher_thread.c
        ${CMAKE_CURRENT_SOURCE_DIR}/espsi_drv/src/esps_drv_rng_config.c
        ${CMAKE_CURRENT_SOURCE_DIR}/espsi_drv/src/esps_drv_tim_config.c
        ${CMAKE_CURRENT_SOURCE_DIR}/espsi_drv/src/es_mac_notif.c
    )

    list(APPEND OBC_includes ${esps_mac_phy_includes})
    list(APPEND OBC_sources ${esps_mac_phy_sources})
endif (COMM_ESPS_MAC_PHY_ENABLED)

if (GNSS_ENABLED)
    list(APPEND OBC_sources ${CMAKE_CURRENT_SOURCE_DIR}/gnss/gnss_cfg.c)
    list(APPEND OBC_includes 
        ${CMAKE_CURRENT_SOURCE_DIR}/pps
        ${CMAKE_CURRENT_SOURCE_DIR}/gnss
    )
endif (GNSS_ENABLED)

if (CUBEADCS_GEN2_ENABLED)
    list(APPEND OBC_sources
        ${CMAKE_CURRENT_SOURCE_DIR}/libcubeobc/cubeObc_config.c
        ${CMAKE_CURRENT_SOURCE_DIR}/aocs/aocs_cntrl/aocs_cntrl_cubeadcs_gen2_int.c
    )
endif (CUBEADCS_GEN2_ENABLED)

if (TELEMETRY_SERVICE_ENABLED)
    list(APPEND OBC_sources
        "${CMAKE_CURRENT_SOURCE_DIR}/telemetry/src/telemetry_cfg_user.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/telemetry/inc/telemetry_context_types.h"
    )
    
    list(APPEND OBC_includes
        "${CMAKE_CURRENT_SOURCE_DIR}/telemetry"
        "${CMAKE_CURRENT_SOURCE_DIR}/telemetry/inc"
    )
endif (TELEMETRY_SERVICE_ENABLED)


# Make the app sources visible to the parent scope
set(OBC_sources ${OBC_sources} PARENT_SCOPE)
set(OBC_includes ${OBC_includes} PARENT_SCOPE)
set(OBC_libraries ${OBC_libraries} PARENT_SCOPE)

#Add provided interface library
add_library(config_if INTERFACE)

list(
    APPEND config_if_includes
    ${CMAKE_CURRENT_SOURCE_DIR}/eps_i
    ${CMAKE_CURRENT_SOURCE_DIR}/eps_ii
    ${CMAKE_CURRENT_SOURCE_DIR}/eps_iii
)

target_include_directories(config_if INTERFACE ${config_if_includes})
