# This top-level micropython.cmake is responsible for listing
# the individual modules we want to include.
# Paths are absolute, and ${CMAKE_CURRENT_LIST_DIR} can be
# used to prefix subdirectories.

if (COMM_GW_ENABLED)
include(${CMAKE_CURRENT_LIST_DIR}/obc_comm_gw/micropython.cmake)
endif()

if (XBAND_FE_ENABLED)
include(${CMAKE_CURRENT_LIST_DIR}/xband_fe/micropython.cmake)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/fmng/micropython.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/cubeadcs_gen2_cubecomputercontrolprogram8/micropython.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/obc_cubeadcs_gen2/micropython.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/cubeadcs_gen2_cubecomputercommon3/micropython.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/telemetry/micropython.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/conops/micropython.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/fdir_srv/micropython.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/sdr/micropython.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/payload_ctrl/micropython.cmake)
