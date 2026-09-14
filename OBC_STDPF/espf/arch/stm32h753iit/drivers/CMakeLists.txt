project(espf_drivers C)

add_subdirectory(arm_fault_handler)

if (COMM_ESPS_MAC_PHY_ENABLED)
    add_subdirectory(comm/espsi_drv)
    list(APPEND OBC_libraries espsi_drv)
endif (COMM_ESPS_MAC_PHY_ENABLED)

if (LWIP_SUPPORT_ENABLED)
    if (ETHERNET_SUPPORT_ENABLED)
        add_subdirectory(comm/nxp-tja11xx)
        add_subdirectory(comm/ethernetif)

        list(APPEND OBC_libraries
            nxp-tja11xx
            ethernetif
        )
    endif (ETHERNET_SUPPORT_ENABLED)
    
    if(SLIP_SUPPORT_ENABLED)
        add_subdirectory(comm/slipif)
        list(APPEND OBC_libraries slipif)
    endif(SLIP_SUPPORT_ENABLED)
endif (LWIP_SUPPORT_ENABLED)

add_subdirectory(io/drv_gpo)

if (CUBEADCS_GEN2_ENABLED)
    add_subdirectory(positioning/cubeobc)
    list(APPEND OBC_libraries drv_cubeobc)
endif (CUBEADCS_GEN2_ENABLED)

if (GNSS_ENABLED)
    add_subdirectory(positioning/gnss)
    list(APPEND OBC_libraries gnss)
endif (GNSS_ENABLED)

add_subdirectory(positioning/libcubeadcs)
add_subdirectory(power)

if (EXTMODULES_SBAND_TMTC_ENABLED)
    add_subdirectory(radio/sband_tmtc)
    list(APPEND OBC_libraries sband_tmtc)
endif (EXTMODULES_SBAND_TMTC_ENABLED)

if (ARDUCAM_ENABLED)
    add_subdirectory(sensors/arducam_ov5642)
    list(APPEND OBC_libraries arducam_ov5642)
endif(ARDUCAM_ENABLED)

add_subdirectory(sensors/gyro_adis16265)

list(APPEND OBC_libraries
    arm_fault_handler
    drv_gpo
    cubeadcs
    eps_i
    eps_ii
    eps_iii
    eps_m
    adis16265_gyro
)

# Include the sources that currently don't have a CMakelists.txt file

# can drivers
add_library(can STATIC can/src/can.c)
target_include_directories(can PUBLIC can/inc)
target_link_libraries(can PUBLIC stm32_hal)

# i2c drivers
add_library(i2c STATIC comm/i2c/MX_I2C.c)
target_include_directories(i2c PUBLIC comm/i2c)
target_link_libraries(i2c PUBLIC stm32_hal)

# drv_led
add_library(drv_led STATIC drv_led/src/drv_led.c)
target_include_directories(drv_led PUBLIC drv_led/inc)
target_link_libraries(drv_led PUBLIC stm32_hal)

# drv_mcu_temperature
add_library(drv_mcu_temperature STATIC drv_mcu_temperature/src/drv_mcu_temperature.c)
target_include_directories(drv_mcu_temperature PUBLIC drv_mcu_temperature/inc)
target_link_libraries(drv_mcu_temperature PUBLIC stm32_hal)

# drv_watchdog
add_library(drv_iwdg STATIC drv_watchdog/src/drv_iwdg.c)
target_include_directories(drv_iwdg PUBLIC drv_watchdog/inc)
target_link_libraries(drv_iwdg PUBLIC stm32_hal)

# io DAT inputs
add_library(dat_inputs STATIC io/dat_inputs/DAT_Inputs.c)
target_include_directories(dat_inputs PUBLIC io/dat_inputs)
target_link_libraries(dat_inputs PRIVATE magn_lis3mdl adis16265_gyro)

# pps
if (GNSS_ENABLED)
    add_library(pps STATIC pps/src/pps.c)
    target_include_directories(pps PUBLIC pps/inc)
    target_link_libraries(pps PUBLIC stm32_hal)
    list(APPEND OBC_libraries pps)
endif (GNSS_ENABLED)

# es_sxband
add_library(es_sxband STATIC radio/es_sxband/S_X_Band_Trnsm.c)
target_include_directories(es_sxband PUBLIC radio/es_sxband)
target_link_libraries(es_sxband PRIVATE crypto datasink eps_ctrl)

# panels
add_library(es_panels STATIC sensors/es_panels/panels.c)
target_include_directories(es_panels PUBLIC sensors/es_panels)
target_link_libraries(es_panels PUBLIC stm32_hal)

# magn_lis3mdl
add_library(magn_lis3mdl STATIC sensors/magn_lis3mdl/LIS3MDL_MAG_driver.c)
target_include_directories(magn_lis3mdl PUBLIC sensors/magn_lis3mdl)
target_link_libraries(magn_lis3mdl PUBLIC i2c stm32_hal)

# sds_events
add_library(sds_events STATIC sensors/sds_events_gen/sds_events.c)
target_include_directories(sds_events PUBLIC sensors/sds_events)
target_link_libraries(sds_events PRIVATE nvm sensor_data_service)

# drv_fram
add_library(drv_fram STATIC storage/drv_fram/src/drv_fram.c)
target_include_directories(drv_fram PUBLIC storage/drv_fram/inc)
target_link_libraries(drv_fram PUBLIC stm32_hal)

list(APPEND OBC_libraries
    can
    i2c
    drv_led
    drv_mcu_temperature
    drv_iwdg
    dat_inputs
    es_sxband
    es_panels
    magn_lis3mdl
    sds_events
    drv_fram
)

# Make the libraries visible to the parent scope
set(OBC_libraries ${OBC_libraries} PARENT_SCOPE)
