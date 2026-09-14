/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup cubeadcs_gen2
 * @{
 *
 * @file     cubeadcs_gen2_events.c
 * @brief    Cubeadcs Gen2 Events handler
 *
 * @}
 */

#include "es_cdef.h"
#include "cmsis_os2.h"
#include "es_exeh.h"
#include "cubeadcs_gen2_events.h"
#include "cubeadcs_gen2_gw.h"
#include "cubeObc_cubeComputer.h"
#include "cubeadcs_gen2_events.h"
#include "cubeadcs_gen2_transfer.h"
#include "fdir_srv.h"

#include "fm_mng.h"
#include "assertions.h"
#include "datacache.h"
#include "es_cdef.h"

#include <stdlib.h>

/**
 * @brief The following defines are used to access the index of the error array for a specific node in the DataCache structure.
 */
#define CUBEADCS_GEN2_RWL_START                       0
#define CUBEADCS_GEN2_RWL_SIZE                        5
#define CUBEADCS_GEN2_RWL_AT_LEAST_FOR_FAULT          2
#define CUBEADCS_GEN2_MAG_START                       5
#define CUBEADCS_GEN2_MAG_SIZE                        2
#define CUBEADCS_GEN2_MAG_AT_LEAST_FOR_FAULT          2
#define CUBEADCS_GEN2_MAG_PRIMARY_SIZE                1
#define CUBEADCS_GEN2_MAG_PRIMARY_AT_LEAST_FOR_FAULT  1
#define CUBEADCS_GEN2_GYRO_START                      0
#define CUBEADCS_GEN2_GYRO_SIZE                       2
#define CUBEADCS_GEN2_GYRO_AT_LEAST_FOR_FAULT         2
#define CUBEADCS_GEN2_GYRO_PRIMARY_SIZE               1
#define CUBEADCS_GEN2_GYRO_PRIMARY_AT_LEAST_FOR_FAULT 1

typedef enum
{
    CUBEADCS_GEN2_FDIR_FAULT_TYPE_COMM_ERROR,
    CUBEADCS_GEN2_FDIR_FAULT_TYPE_FAILURE,
    CUBEADCS_GEN2_FDIR_FAULT_TYPE_SETUP_ERROR,
    CUBEADCS_GEN2_FDIR_FAULT_TYPE_DISCOVERY_ERROR,
    CUBEADCS_GEN2_FDIR_FAULT_TYPE_PORT_VALIDATION_ERROR,
    CUBEADCS_GEN2_FDIR_FAULT_TYPE_COUNT,
} cubeadcs_gen2_fdir_fault_type_t;

STATIC const fdir_fault_id_t node2fault_comm_error[7] = {
    FDIR_FAULT_ADCS_RWL_COMM_ERROR,
    FDIR_FAULT_ADCS_RWL_COMM_ERROR,
    FDIR_FAULT_ADCS_RWL_COMM_ERROR,
    FDIR_FAULT_ADCS_RWL_COMM_ERROR,
    FDIR_FAULT_ADCS_RWL_COMM_ERROR,
    FDIR_FAULT_ADCS_PRIM_MAGN_COMM_ERROR,
    FDIR_FAULT_ADCS_BOTH_MAGN_COMM_ERROR,
};

STATIC const fdir_fault_id_t node2fault_failure[7] = {
    FDIR_FAULT_ADCS_RWL_FAILURE,
    FDIR_FAULT_ADCS_RWL_FAILURE,
    FDIR_FAULT_ADCS_RWL_FAILURE,
    FDIR_FAULT_ADCS_RWL_FAILURE,
    FDIR_FAULT_ADCS_RWL_FAILURE,
    FDIR_FAULT_ADCS_PRIM_MAGN_FAILURE,
    FDIR_FAULT_ADCS_BOTH_MAGN_FAILURE,
};

STATIC const fdir_fault_id_t node2fault_setup_error[7] = {
    FDIR_FAULT_ADCS_RWL_SETUP_ERROR,
    FDIR_FAULT_ADCS_RWL_SETUP_ERROR,
    FDIR_FAULT_ADCS_RWL_SETUP_ERROR,
    FDIR_FAULT_ADCS_RWL_SETUP_ERROR,
    FDIR_FAULT_ADCS_RWL_SETUP_ERROR,
    FDIR_FAULT_ADCS_PRIM_MAGN_SETUP_ERROR,
    FDIR_FAULT_ADCS_BOTH_MAGN_SETUP_ERROR,
};

STATIC const fdir_fault_id_t node2fault_discovery_error[7] = {
    FDIR_FAULT_ADCS_RWL_DISCOVERY_ERROR,
    FDIR_FAULT_ADCS_RWL_DISCOVERY_ERROR,
    FDIR_FAULT_ADCS_RWL_DISCOVERY_ERROR,
    FDIR_FAULT_ADCS_RWL_DISCOVERY_ERROR,
    FDIR_FAULT_ADCS_RWL_DISCOVERY_ERROR,
    FDIR_FAULT_ADCS_PRIM_MAGN_DISCOVERY_ERROR,
    FDIR_FAULT_ADCS_BOTH_MAGN_DISCOVERY_ERROR,
};

STATIC const fdir_fault_id_t node2fault_port_validation_error[7] = {
    FDIR_FAULT_ADCS_RWL_PORT_VALIDATION_ERROR,
    FDIR_FAULT_ADCS_RWL_PORT_VALIDATION_ERROR,
    FDIR_FAULT_ADCS_RWL_PORT_VALIDATION_ERROR,
    FDIR_FAULT_ADCS_RWL_PORT_VALIDATION_ERROR,
    FDIR_FAULT_ADCS_RWL_PORT_VALIDATION_ERROR,
    FDIR_FAULT_ADCS_PRIM_MAGN_PORT_VALIDATION_ERROR,
    FDIR_FAULT_ADCS_BOTH_MAGN_PORT_VALIDATION_ERROR,
};

STATIC const fdir_fault_id_t *node2fault[CUBEADCS_GEN2_FDIR_FAULT_TYPE_COUNT] = {
    node2fault_comm_error,
    node2fault_failure,
    node2fault_setup_error,
    node2fault_discovery_error,
    node2fault_port_validation_error,
};

STATIC const char *node2fmt[CUBEADCS_GEN2_FDIR_FAULT_TYPE_COUNT] = {
    "Node %s communication error",
    "Node %s failure",
    "Node %s setup error",
    "Node %s discovery error",
    "Node %s port validation error",
};

STATIC const char *node2name[CUBEADCS_GEN2_ABSTRACT_NODE_MAX] = {
    [CUBEADCS_GEN2_ABSTRACT_NODE_INVALID]  = "Invalid",
    [CUBEADCS_GEN2_ABSTRACT_NODE_COMPUTER] = "Computer",
    [CUBEADCS_GEN2_ABSTRACT_NODE_STR_0]    = "Star Tracker 0",
    [CUBEADCS_GEN2_ABSTRACT_NODE_STR_1]    = "Star Tracker 1",
    [CUBEADCS_GEN2_ABSTRACT_NODE_FSS_0]    = "Fine Sun Sensor 0",
    [CUBEADCS_GEN2_ABSTRACT_NODE_FSS_1]    = "Fine Sun Sensor 1",
    [CUBEADCS_GEN2_ABSTRACT_NODE_FSS_2]    = "Fine Sun Sensor 2",
    [CUBEADCS_GEN2_ABSTRACT_NODE_FSS_3]    = "Fine Sun Sensor 3",
    [CUBEADCS_GEN2_ABSTRACT_NODE_HSS_0]    = "Horizon Sub Senson 0",
    [CUBEADCS_GEN2_ABSTRACT_NODE_HSS_1]    = "Horizon Sub Senson 1",
    [CUBEADCS_GEN2_ABSTRACT_NODE_MAG_0]    = "Magnetometer 0",
    [CUBEADCS_GEN2_ABSTRACT_NODE_MAG_1]    = "Magnetometer 1",
    [CUBEADCS_GEN2_ABSTRACT_NODE_EXT_0]    = "External Sensor 0",
    [CUBEADCS_GEN2_ABSTRACT_NODE_EXT_1]    = "External Sensor 1",
    [CUBEADCS_GEN2_ABSTRACT_NODE_RWL_0]    = "Reaction Wheel 0",
    [CUBEADCS_GEN2_ABSTRACT_NODE_RWL_1]    = "Reaction Wheel 1",
    [CUBEADCS_GEN2_ABSTRACT_NODE_RWL_2]    = "Reaction Wheel 2",
    [CUBEADCS_GEN2_ABSTRACT_NODE_RWL_3]    = "Reaction Wheel 3",
    [CUBEADCS_GEN2_ABSTRACT_NODE_RWL_4]    = "Reaction Wheel 4",
};

/** @brief Events handling logic context */
static cubeadcs_gen2_events_ctx_t events_ctx = { 0 };
/** @brief Events file name */
const char events_f_name[16] = "LAST_EVENTS.bin";
/** @brief CubeADCS Gen2 events cache lock */
static osMutexId_t cubeadcs_gen2_ev_lock;
/** @brief CubeADCS Gen2 events mutex attributes */
static const osMutexAttr_t cubeadcs_gen2_ev_lock_attr = {
    "cubeadcs_gen2_ev_lock_mutex",
    osMutexRecursive | osMutexPrioInherit,
    NULL,
    0U
};

STATIC bool fs_cubeadcs_gen2_events_parse_events_log(const char *const p_f_name, const uint32_t ev_cnt);
STATIC void fs_cubeadcs_gen2_events_update_events_cache(const cubeadcs_gen2_event_t *const p_ev, DATA_CACHE_FDIR_CUBEADCS_GEN2_EVENTS_t *p_dc_events);
STATIC bool fs_cubeadcs_gen2_events_lock_ev(void);
STATIC bool fs_cubeadcs_gen2_events_unlock_ev(void);
STATIC bool fs_cubeadcs_gen2_events_get_marker_start(void);
STATIC bool fs_cubeadcs_gen2_events_get_marker_poll(void);
STATIC bool fs_cubeadcs_gen2_events_dwn_new_crit_events_start(void);
STATIC bool fs_cubeadcs_gen2_events_dwn_new_crit_events_poll(void);

/**
 * @brief Update the data cache with the new event
 */
STATIC void fs_cubeadcs_gen2_events_update_dc_value_node(
    DATA_CACHE_FDIR_CUBEADCS_GEN2_EVENTS_t *p_dc_events,
    cubeadcs_gen2_fdir_fault_type_t         type,
    cubeadcs_gen2_abstract_node_t           node);
STATIC void          fs_cubeadcs_gen2_events_update_dc_error_gyro(bool *const error, const cubeadcs_gen2_gyro_type_t gyro_type);
STATIC inline size_t fs_cubeadcs_gen2_events_get_node_index(cubeadcs_gen2_abstract_node_t node);
inline STATIC bool  *fs_cubeadcs_gen2_events_get_dc_error_type(DATA_CACHE_FDIR_CUBEADCS_GEN2_EVENTS_t *p_dc_events, cubeadcs_gen2_fdir_fault_type_t type);

/**
 * @brief Check if the number events for specific node reaches the count to raise a fault
 *
 * @param p_errors - pointer to the array of errors
 * @param start - start index of the array for the specific node
 * @param size - size from `start` index of the array for the specific node
 * @param count - count of errors needed to raise a fault
 *
 * @retval true - raise the specific fault
 *         false - do not raise the specific fault
 */
STATIC bool fdir_agent_detect_cube_adcs_gen2_node_error(const bool *const p_errors, const size_t start, const size_t size, const size_t count);

void cubeadcs_gen2_events_init_os(void)
{
    cubeadcs_gen2_ev_lock = osMutexNew(&cubeadcs_gen2_ev_lock_attr);

    if (NULL == cubeadcs_gen2_ev_lock)
    {
        EXEH_HANDLE_EX(eEXEHSeverity_Error, eEXEHModuleID_CUBEADCS_GEN2,
                       EXEH_CUBEADCS_GEN2_OS_OBJ_ERR);
    }
}

bool cubeadcs_gen2_events_get_marker(void)
{
    bool op_res = false;

    static cubeadcs_gen2_event_dwn_progress_t evt_dwn_progress = CUBEADCS_GEN2_EVENT_DWN_IDLE;

    if (true == fs_cubeadcs_gen2_events_lock_ev())
    {
        switch (evt_dwn_progress)
        {
            case CUBEADCS_GEN2_EVENT_DWN_IDLE:
                {
                    if (true == fs_cubeadcs_gen2_events_get_marker_start())
                    {
                        evt_dwn_progress = CUBEADCS_GEN2_EVENT_DWN_STARTED;
                    }
                }
                break;

            case CUBEADCS_GEN2_EVENT_DWN_STARTED:
                {
                    cubeadcs_gen2_transfer_evt_status_t get_marker_status;
                    const ErrorCode                     err = cubeadcs_gen2_transfer_evt_status(&get_marker_status);

                    if (CUBEOBC_ERROR_OK == err)
                    {
                        if (CUBEOBC_ERROR_OK == get_marker_status.err_code)
                        {
                            evt_dwn_progress = CUBEADCS_GEN2_EVENT_DWN_POLL;
                        }
                        else
                        {
                            evt_dwn_progress = CUBEADCS_GEN2_EVENT_DWN_IDLE;
                        }
                    }
                }
                break;

            case CUBEADCS_GEN2_EVENT_DWN_POLL:
                {
                    if (true == fs_cubeadcs_gen2_events_get_marker_poll())
                    {
                        evt_dwn_progress = CUBEADCS_GEN2_EVENT_DWN_FINISHED;
                    }
                    else
                    {
                        // Retry the event log download sequence
                        evt_dwn_progress = CUBEADCS_GEN2_EVENT_DWN_IDLE;
                    }
                }
                break;

            case CUBEADCS_GEN2_EVENT_DWN_FINISHED:
                {
                    op_res = true;

                    // Back to vanilla state
                    evt_dwn_progress = CUBEADCS_GEN2_EVENT_DWN_IDLE;
                }
                break;

            default:
                break;
        }

        (void)fs_cubeadcs_gen2_events_unlock_ev();
    }

    return op_res;
}

bool cubeadcs_gen2_events_check_for_new_crit_events(bool *const is_new_crit_events)
{
    CRIT_ASSERT(NULL != is_new_crit_events);

    bool op_res = false;

    TypesCubeComputerCommon3_EventLogStatus event_log_status;

    if ((true == fs_cubeadcs_gen2_events_lock_ev()) &&
        (CUBEOBC_ERROR_OK == CubeADCS_Gen2_CubeComputerCommon3_getEventLogStatusRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &event_log_status, CUBEADCS_GEN2_DEFAULT_CRIT_SECTION_TIMEOUT)))
    {
        // It is possible that the events log gets deleted by the user ...
        if ((events_ctx.last_major_events_num != event_log_status.numberOfMajorWarningEvents) ||
            (events_ctx.last_crit_events_num != event_log_status.numberOfCriticalEvents))
        {
            events_ctx.events_to_download = abs((event_log_status.numberOfMajorWarningEvents - events_ctx.last_major_events_num) +
                                                (event_log_status.numberOfCriticalEvents - events_ctx.last_crit_events_num));

            TODO("TEST how much time it takes to download events and modify the limit accordingly")
            if (events_ctx.events_to_download > CUBEADCS_GEN2_EVENTS_MAX_EVENTS_TO_DOWNLOAD)
            {
                events_ctx.events_to_download = CUBEADCS_GEN2_EVENTS_MAX_EVENTS_TO_DOWNLOAD;
            }

            events_ctx.last_major_events_num = event_log_status.numberOfMajorWarningEvents;
            events_ctx.last_crit_events_num  = event_log_status.numberOfCriticalEvents;

            *is_new_crit_events = true;
        }
        else
        {
            *is_new_crit_events = false;
        }

        (void)fs_cubeadcs_gen2_events_unlock_ev();

        op_res = true;
    }

    return op_res;
}

bool cubeadcs_gen2_events_dwn_new_crit_events(bool *const p_is_crit_evt)
{
    CRIT_ASSERT(NULL != p_is_crit_evt);

    bool op_res = false;

    static bool is_new_crit_event = false;

    static cubeadcs_gen2_event_crit_dwn_states_t dwn_state = CUBEADCS_GEN2_EVENT_CRIT_IDLE;

    if (true == fs_cubeadcs_gen2_events_lock_ev())
    {
        switch (dwn_state)
        {
            case CUBEADCS_GEN2_EVENT_CRIT_IDLE:
                if (true == cubeadcs_gen2_events_check_for_new_crit_events(&is_new_crit_event))
                {
                    dwn_state = CUBEADCS_GEN2_EVENT_CRIT_CHECK;
                }
                break;
            case CUBEADCS_GEN2_EVENT_CRIT_CHECK:
                if (true == is_new_crit_event)
                {
                    if (true == fs_cubeadcs_gen2_events_dwn_new_crit_events_start())
                    {
                        dwn_state = CUBEADCS_GEN2_EVENT_CRIT_START_DWN;
                    }
                }
                else
                {
                    dwn_state = CUBEADCS_GEN2_EVENT_CRIT_FINISHED;
                }
                break;
            case CUBEADCS_GEN2_EVENT_CRIT_START_DWN:
                if (true == fs_cubeadcs_gen2_events_dwn_new_crit_events_poll())
                {
                    dwn_state = CUBEADCS_GEN2_EVENT_CRIT_FINISHED;
                }
                break;
            case CUBEADCS_GEN2_EVENT_CRIT_FINISHED:

                *p_is_crit_evt = is_new_crit_event;

                op_res = true;

                // Return to vanilla state
                dwn_state         = CUBEADCS_GEN2_EVENT_CRIT_IDLE;
                is_new_crit_event = false;

                break;

            default:
                break;
        }

        (void)fs_cubeadcs_gen2_events_unlock_ev();
    }

    return op_res;
}

bool cubeadcs_gen2_events_get_events_stats(cubeadcs_gen2_events_cnts_t *const p_ev_dst)
{
    CRIT_ASSERT(NULL != p_ev_dst);

    bool op_res = false;

    if (true == fs_cubeadcs_gen2_events_lock_ev())
    {
        (void)memcpy(p_ev_dst, &events_ctx.read_events, sizeof(cubeadcs_gen2_events_cnts_t));

        (void)fs_cubeadcs_gen2_events_unlock_ev();

        op_res = true;
    }

    return op_res;
}

bool cubeadcs_gen2_events_clear_event_stats(bool clr_all)
{
    bool op_res = false;

    if (true == fs_cubeadcs_gen2_events_lock_ev())
    {
        if (true == clr_all)
        {
            (void)memset((void *)&events_ctx.read_events, 0U, sizeof(events_ctx.read_events));
        }
        else
        {
            (void)memset((void *)&events_ctx.read_events.last_read_events, 0U, sizeof(events_ctx.read_events.last_read_events));
        }

        (void)fs_cubeadcs_gen2_events_unlock_ev();

        op_res = true;
    }

    return op_res;
}

/**
 * @brief Check if the number events for specific node reaches the count to raise a fault
 *
 * @param p_errors - pointer to the array of errors
 * @param start - start index of the array for the specific node
 * @param size - size from `start` index of the array for the specific node
 * @param count - count of errors needed to raise a fault
 *
 * @retval true - raise the specific fault
 *         false - do not raise the specific fault
 */
static bool fdir_agent_detect_cube_adcs_gen2_node_error(const bool *const p_errors, const size_t start, const size_t size, const size_t count)
{
    bool   fault       = false;
    size_t error_count = 0;
    for (size_t i = start; i < start + size; i++)
    {
        if (true == p_errors[i])
        {
            ++error_count;
        }
    }
    if (count <= error_count)
    {
        fault = true;
    }
    return fault;
}

static void cubeadcs_gen2_events_update_fdir(const DATA_CACHE_FDIR_CUBEADCS_GEN2_EVENTS_t *p_dc_events)
{
    static const fdir_agent_id_t             agent_id = FDIR_AGENT_CUBE_ADCS_GEN2;
    DATA_CACHE_CUBEADCS_GEN2_TLM_FRAME_221_t tlm;
    uint8_t                                  mag_primary = (uint8_t)-1;
    dc_data_status_t                         dc_status;
    (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_RWL_COMM_ERROR, agent_id, fdir_agent_detect_cube_adcs_gen2_node_error(p_dc_events->abNode_comm_error, CUBEADCS_GEN2_RWL_START, CUBEADCS_GEN2_RWL_SIZE, CUBEADCS_GEN2_RWL_AT_LEAST_FOR_FAULT), NULL);
    (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_RWL_FAILURE, agent_id, fdir_agent_detect_cube_adcs_gen2_node_error(p_dc_events->abNode_failure, CUBEADCS_GEN2_RWL_START, CUBEADCS_GEN2_RWL_SIZE, CUBEADCS_GEN2_RWL_AT_LEAST_FOR_FAULT), NULL);
    (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_RWL_SETUP_ERROR, agent_id, fdir_agent_detect_cube_adcs_gen2_node_error(p_dc_events->abNode_setup_error, CUBEADCS_GEN2_RWL_START, CUBEADCS_GEN2_RWL_SIZE, CUBEADCS_GEN2_RWL_AT_LEAST_FOR_FAULT), NULL);
    (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_RWL_DISCOVERY_ERROR, agent_id, fdir_agent_detect_cube_adcs_gen2_node_error(p_dc_events->abNode_discovery_error, CUBEADCS_GEN2_RWL_START, CUBEADCS_GEN2_RWL_SIZE, CUBEADCS_GEN2_RWL_AT_LEAST_FOR_FAULT), NULL);
    (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_RWL_PORT_VALIDATION_ERROR, agent_id, fdir_agent_detect_cube_adcs_gen2_node_error(p_dc_events->abNode_port_validation_error, CUBEADCS_GEN2_RWL_START, CUBEADCS_GEN2_RWL_SIZE, CUBEADCS_GEN2_RWL_AT_LEAST_FOR_FAULT), NULL);
    dc_status = dc_get_cubeadcs_gen2_tlm_frame_221_data(&tlm);
    if (DC_DATA_STATUS_OK == dc_status)
    {
        if (TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__MAG_PRIMARY == tlm.u8Mag0SensingElement)
        {
            mag_primary = 0;
        }
        else if (TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__MAG_PRIMARY == tlm.u8Mag1SensingElement)
        {
            mag_primary = 1;
        }
        else
        {
            // SonarQube warning suppression
        }
        if ((uint8_t)-1 != mag_primary)
        {
            (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_PRIM_MAGN_COMM_ERROR, agent_id, fdir_agent_detect_cube_adcs_gen2_node_error(p_dc_events->abNode_comm_error, CUBEADCS_GEN2_MAG_START + mag_primary, CUBEADCS_GEN2_MAG_PRIMARY_SIZE, CUBEADCS_GEN2_MAG_PRIMARY_AT_LEAST_FOR_FAULT), NULL);
            (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_PRIM_MAGN_FAILURE, agent_id, fdir_agent_detect_cube_adcs_gen2_node_error(p_dc_events->abNode_failure, CUBEADCS_GEN2_MAG_START + mag_primary, CUBEADCS_GEN2_MAG_PRIMARY_SIZE, CUBEADCS_GEN2_MAG_PRIMARY_AT_LEAST_FOR_FAULT), NULL);
            (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_PRIM_MAGN_SETUP_ERROR, agent_id, fdir_agent_detect_cube_adcs_gen2_node_error(p_dc_events->abNode_setup_error, CUBEADCS_GEN2_MAG_START + mag_primary, CUBEADCS_GEN2_MAG_PRIMARY_SIZE, CUBEADCS_GEN2_MAG_PRIMARY_AT_LEAST_FOR_FAULT), NULL);
            (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_PRIM_MAGN_DISCOVERY_ERROR, agent_id, fdir_agent_detect_cube_adcs_gen2_node_error(p_dc_events->abNode_discovery_error, CUBEADCS_GEN2_MAG_START + mag_primary, CUBEADCS_GEN2_MAG_PRIMARY_SIZE, CUBEADCS_GEN2_MAG_PRIMARY_AT_LEAST_FOR_FAULT), NULL);
            (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_PRIM_MAGN_PORT_VALIDATION_ERROR, agent_id, fdir_agent_detect_cube_adcs_gen2_node_error(p_dc_events->abNode_port_validation_error, CUBEADCS_GEN2_MAG_START + mag_primary, CUBEADCS_GEN2_MAG_PRIMARY_SIZE, CUBEADCS_GEN2_MAG_PRIMARY_AT_LEAST_FOR_FAULT), NULL);
        }
    }
    (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_BOTH_MAGN_COMM_ERROR, agent_id, fdir_agent_detect_cube_adcs_gen2_node_error(p_dc_events->abNode_comm_error, CUBEADCS_GEN2_MAG_START, CUBEADCS_GEN2_MAG_SIZE, CUBEADCS_GEN2_MAG_AT_LEAST_FOR_FAULT), NULL);
    (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_BOTH_MAGN_FAILURE, agent_id, fdir_agent_detect_cube_adcs_gen2_node_error(p_dc_events->abNode_failure, CUBEADCS_GEN2_MAG_START, CUBEADCS_GEN2_MAG_SIZE, CUBEADCS_GEN2_MAG_AT_LEAST_FOR_FAULT), NULL);
    (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_BOTH_MAGN_SETUP_ERROR, agent_id, fdir_agent_detect_cube_adcs_gen2_node_error(p_dc_events->abNode_setup_error, CUBEADCS_GEN2_MAG_START, CUBEADCS_GEN2_MAG_SIZE, CUBEADCS_GEN2_MAG_AT_LEAST_FOR_FAULT), NULL);
    (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_BOTH_MAGN_DISCOVERY_ERROR, agent_id, fdir_agent_detect_cube_adcs_gen2_node_error(p_dc_events->abNode_discovery_error, CUBEADCS_GEN2_MAG_START, CUBEADCS_GEN2_MAG_SIZE, CUBEADCS_GEN2_MAG_AT_LEAST_FOR_FAULT), NULL);
    (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_BOTH_MAGN_PORT_VALIDATION_ERROR, agent_id, fdir_agent_detect_cube_adcs_gen2_node_error(p_dc_events->abNode_port_validation_error, CUBEADCS_GEN2_MAG_START, CUBEADCS_GEN2_MAG_SIZE, CUBEADCS_GEN2_MAG_AT_LEAST_FOR_FAULT), NULL);
    (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_PRIM_GYRO_VOLTAGE_ERROR, agent_id, fdir_agent_detect_cube_adcs_gen2_node_error(p_dc_events->abGyro_voltage_error, CUBEADCS_GEN2_GYRO_START, CUBEADCS_GEN2_GYRO_PRIMARY_SIZE, CUBEADCS_GEN2_GYRO_PRIMARY_AT_LEAST_FOR_FAULT), NULL);
    (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_PRIM_GYRO_CRITICAL_ERROR, agent_id, fdir_agent_detect_cube_adcs_gen2_node_error(p_dc_events->abGyro_critical_error, CUBEADCS_GEN2_GYRO_START, CUBEADCS_GEN2_GYRO_PRIMARY_SIZE, CUBEADCS_GEN2_GYRO_PRIMARY_AT_LEAST_FOR_FAULT), NULL);
    (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_BOTH_GYRO_VOLTAGE_ERROR, agent_id, fdir_agent_detect_cube_adcs_gen2_node_error(p_dc_events->abGyro_voltage_error, CUBEADCS_GEN2_GYRO_START, CUBEADCS_GEN2_GYRO_SIZE, CUBEADCS_GEN2_GYRO_AT_LEAST_FOR_FAULT), NULL);
    (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_BOTH_GYRO_CRITICAL_ERROR, agent_id, fdir_agent_detect_cube_adcs_gen2_node_error(p_dc_events->abGyro_critical_error, CUBEADCS_GEN2_GYRO_START, CUBEADCS_GEN2_GYRO_SIZE, CUBEADCS_GEN2_GYRO_AT_LEAST_FOR_FAULT), NULL);
    (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_CONTROL_LOOP_FAILURE, agent_id, p_dc_events->bControl_loop_failure, NULL);
    (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_CONTROL_LOOP_CRITICAL_ERROR, agent_id, p_dc_events->bControl_loop_critical_error, NULL);
    (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_CONFIGURATION_VALIDATION_ERROR, agent_id, p_dc_events->bConfiguration_validation_error, NULL);
    (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_CONFIGURATION_PERSIST_ERROR, agent_id, p_dc_events->bConfiguration_persist_error, NULL);
    (void)fdir_srv_fault_set_state(FDIR_FAULT_ADCS_VIRTUAL_WATCHDOG_ERROR, agent_id, p_dc_events->bVirtual_watchdog_error, NULL);
}

/** @brief Parse the events log stored in the provided file name updating a file scoped cache and updating the last read event
 *
 *  @param[in] const char * const p_events_f_name - The name of the file containing the events log
 *
 *  @retval true     - on success
 *  @retval false    - on failure
 *
 */
STATIC bool fs_cubeadcs_gen2_events_parse_events_log(const char *const p_f_name, const uint32_t ev_cnt)
{
    CRIT_ASSERT(NULL != p_f_name);

    fm_file_obj_t f_handle;

    bool op_res = false;

    cubeadcs_gen2_event_t event;
    uint32_t              read_bytes;

    if ((FM_RES_OK == fm_open(&f_handle, p_f_name, FM_MODE_READ)) && (FM_RES_OK == fm_seek(&f_handle, 0)) && (true == fs_cubeadcs_gen2_events_lock_ev()))
    {
        DATA_CACHE_FDIR_CUBEADCS_GEN2_EVENTS_t dc_events;
        dc_data_status_t                       dc_status;
        dc_status = dc_get_fdir_cubeadcs_gen2_events_data(&dc_events);
        if ((dc_status == DC_NOT_INITIALIZED) ||
            (dc_status == DC_DATA_STATUS_INIT))
        {
            memset(&dc_events, 0, sizeof(dc_events));
        }

        for (uint32_t ev = 0; ev < ev_cnt;)
        {
            if ((FM_RES_OK == fm_read(&f_handle, (void *)&event, sizeof(cubeadcs_gen2_event_t), &read_bytes)) && (read_bytes == sizeof(cubeadcs_gen2_event_t)))
            {
                fs_cubeadcs_gen2_events_update_events_cache(&event, &dc_events);
            }
            else
            {
                // We want to get all events and FDIR on them, otherwise just break and try again
                break;
            }

            if (++ev == ev_cnt)
            {
                events_ctx.last_read_counter = event.counter;

                for (uint8_t ev_indx = 0; ev_indx < CUBEADCS_GEN2_EVENTS_MAX; ev_indx++)
                {
                    events_ctx.read_events.all_read_events[ev_indx] += events_ctx.read_events.last_read_events[ev_indx];
                }

                op_res = true;
            }
        }

        (void)fm_close(&f_handle);

        dc_set_fdir_cubeadcs_gen2_events_data(&dc_events);
        (void)dc_get_fdir_cubeadcs_gen2_events_data(&dc_events);
        cubeadcs_gen2_events_update_fdir(&dc_events);

        (void)fs_cubeadcs_gen2_events_unlock_ev();
    }

    return op_res;
}

STATIC inline size_t fs_cubeadcs_gen2_events_get_node_index(cubeadcs_gen2_abstract_node_t node)
{
    switch (node)
    {
        case CUBEADCS_GEN2_ABSTRACT_NODE_RWL_0:
            return 0;
        case CUBEADCS_GEN2_ABSTRACT_NODE_RWL_1:
            return 1;
        case CUBEADCS_GEN2_ABSTRACT_NODE_RWL_2:
            return 2;
        case CUBEADCS_GEN2_ABSTRACT_NODE_RWL_3:
            return 3;
        case CUBEADCS_GEN2_ABSTRACT_NODE_RWL_4:
            return 4;
        case CUBEADCS_GEN2_ABSTRACT_NODE_MAG_0:
            return 5;
        case CUBEADCS_GEN2_ABSTRACT_NODE_MAG_1:
            return 6;
        default:
            return (size_t)-1;
    }
}

inline STATIC bool *fs_cubeadcs_gen2_events_get_dc_error_type(DATA_CACHE_FDIR_CUBEADCS_GEN2_EVENTS_t *p_dc_events, cubeadcs_gen2_fdir_fault_type_t type)
{
    switch (type)
    {
        case CUBEADCS_GEN2_FDIR_FAULT_TYPE_COMM_ERROR:
            return p_dc_events->abNode_comm_error;
        case CUBEADCS_GEN2_FDIR_FAULT_TYPE_FAILURE:
            return p_dc_events->abNode_failure;
        case CUBEADCS_GEN2_FDIR_FAULT_TYPE_SETUP_ERROR:
            return p_dc_events->abNode_setup_error;
        case CUBEADCS_GEN2_FDIR_FAULT_TYPE_DISCOVERY_ERROR:
            return p_dc_events->abNode_discovery_error;
        case CUBEADCS_GEN2_FDIR_FAULT_TYPE_PORT_VALIDATION_ERROR:
            return p_dc_events->abNode_port_validation_error;
        default:
            return NULL;
    }
}

STATIC void fs_cubeadcs_gen2_events_update_dc_value_node(
    DATA_CACHE_FDIR_CUBEADCS_GEN2_EVENTS_t *p_dc_events,
    cubeadcs_gen2_fdir_fault_type_t         type,
    cubeadcs_gen2_abstract_node_t           node)
{
    BREAK_ASSERT(NULL != p_dc_events);
    bool *error;
    error = fs_cubeadcs_gen2_events_get_dc_error_type(p_dc_events, type);
    BREAK_ASSERT(NULL != error);
    size_t node_index = fs_cubeadcs_gen2_events_get_node_index(node);
    if ((node_index != (size_t)-1) &&
        (NULL != error))
    {
        error[node_index] = true;
        fdir_srv_log(node2fault[type][node_index], FDIR_AGENT_CUBE_ADCS_GEN2, node2fmt[type], node2name[node]);
    }
}

STATIC void fs_cubeadcs_gen2_events_update_dc_error_gyro(bool *const error, const cubeadcs_gen2_gyro_type_t gyro_type)
{
    if (CUBEADCS_GEN2_GYRO_TYPE_PRIMARY == gyro_type)
    {
        error[0] = true;
    }
    else
    {
        error[1] = true;
    }
}

/** @brief Update the events cache with the provided event
 *
 *  @note Context lock is NOT performed within the function
 *
 *  @param[in] const cubeadcs_gen2_event_t * const p_ev - the event
 */
STATIC void fs_cubeadcs_gen2_events_update_events_cache(const cubeadcs_gen2_event_t *const p_ev, DATA_CACHE_FDIR_CUBEADCS_GEN2_EVENTS_t *p_dc_events)
{
    CRIT_ASSERT(NULL != p_ev);

    if (CUBEADCS_GEN2_EVENT_CLASS_MINOR == p_ev->identifier.event_class)
    {
        switch (p_ev->identifier.event_type)
        {
            case CUBEADCS_GEN2_EVENTS_NODE_COMMUNICATION_ERROR_ID:
                events_ctx.read_events.last_read_events[CUBEADCS_GEN2_EVENTS_NODE_COMMUNICATION_ERROR] += 1;
                fs_cubeadcs_gen2_events_update_dc_value_node(p_dc_events, CUBEADCS_GEN2_FDIR_FAULT_TYPE_COMM_ERROR, p_ev->identifier.abstract_node);
                break;
            default:
                break;
        }
    }
    else if (CUBEADCS_GEN2_EVENT_CLASS_MAJOR == p_ev->identifier.event_class)
    {
        switch (p_ev->identifier.event_type)
        {
            case CUBEADCS_GEN2_EVENTS_ADCS_CONFIG_VALIDATION_ERROR_ID:
                events_ctx.read_events.last_read_events[CUBEADCS_GEN2_EVENTS_ADCS_CONFIG_VALIDATION_ERROR] += 1;
                p_dc_events->bConfiguration_validation_error = true;
                break;
            case CUBEADCS_GEN2_EVENTS_NODE_SETUP_ERROR_ID:
                events_ctx.read_events.last_read_events[CUBEADCS_GEN2_EVENTS_NODE_SETUP_ERROR] += 1;
                fs_cubeadcs_gen2_events_update_dc_value_node(p_dc_events, CUBEADCS_GEN2_FDIR_FAULT_TYPE_SETUP_ERROR, p_ev->identifier.abstract_node);
                break;
            case CUBEADCS_GEN2_EVENTS_NODE_JUMP_ERROR_ID:
                events_ctx.read_events.last_read_events[CUBEADCS_GEN2_EVENTS_NODE_JUMP_ERROR] += 1;
                break;
            case CUBEADCS_GEN2_EVENTS_MAG_DEPLOY_ERROR_ID:
                events_ctx.read_events.last_read_events[CUBEADCS_GEN2_EVENTS_MAG_DEPLOY_ERROR] += 1;
                break;
            case CUBEADCS_GEN2_EVENTS_CONTROL_LOOP_FAILURE_ID:
                events_ctx.read_events.last_read_events[CUBEADCS_GEN2_EVENTS_CONTROL_LOOP_FAILURE] += 1;
                p_dc_events->bControl_loop_failure = true;
                break;
            case CUBEADCS_GEN2_EVENTS_NODE_FAILURE_ID:
                events_ctx.read_events.last_read_events[CUBEADCS_GEN2_EVENTS_NODE_FAILURE] += 1;
                fs_cubeadcs_gen2_events_update_dc_value_node(p_dc_events, CUBEADCS_GEN2_FDIR_FAULT_TYPE_FAILURE, p_ev->identifier.abstract_node);
                break;
            case CUBEADCS_GEN2_EVENTS_CONFIG_PERSIST_ERROR_ID:
                events_ctx.read_events.last_read_events[CUBEADCS_GEN2_EVENTS_CONFIG_PERSIST_ERROR] += 1;
                p_dc_events->bConfiguration_persist_error = true;
                break;
            case CUBEADCS_GEN2_EVENTS_VIRTUAL_WATCHDOG_WARNING_ID:
                events_ctx.read_events.last_read_events[CUBEADCS_GEN2_EVENTS_VIRTUAL_WATCHDOG_WARNING] += 1;
                break;
            case CUBEADCS_GEN2_EVENTS_PORT_VALIDATION_ERROR_ID:
                events_ctx.read_events.last_read_events[CUBEADCS_GEN2_EVENTS_PORT_VALIDATION_ERROR] += 1;
                fs_cubeadcs_gen2_events_update_dc_value_node(p_dc_events, CUBEADCS_GEN2_FDIR_FAULT_TYPE_PORT_VALIDATION_ERROR, p_ev->identifier.abstract_node);
                break;
            case CUBEADCS_GEN2_EVENTS_AUTO_DISCOVERY_ERROR_ID:
                events_ctx.read_events.last_read_events[CUBEADCS_GEN2_EVENTS_AUTO_DISCOVERY_ERROR] += 1;
                fs_cubeadcs_gen2_events_update_dc_value_node(p_dc_events, CUBEADCS_GEN2_FDIR_FAULT_TYPE_DISCOVERY_ERROR, p_ev->identifier.abstract_node);
                break;
            default:
                break;
        }
    }
    else if (CUBEADCS_GEN2_EVENT_CLASS_CRITICAL == p_ev->identifier.event_class)
    {
        switch (p_ev->identifier.event_type)
        {
            case CUBEADCS_GEN2_EVENTS_CONTROL_LOOP_CRITICAL_ID:
                events_ctx.read_events.last_read_events[CUBEADCS_GEN2_EVENTS_CONTROL_LOOP_CRITICAL] += 1;
                p_dc_events->bControl_loop_critical_error = true;
                break;
            case CUBEADCS_GEN2_EVENTS_GYRO_VOLTAGE_ERROR_ID:
                events_ctx.read_events.last_read_events[CUBEADCS_GEN2_EVENTS_GYRO_VOLTAGE_ERROR] += 1;
                fs_cubeadcs_gen2_events_update_dc_error_gyro(p_dc_events->abGyro_voltage_error, ((const cubeadcs_gen2_event_gyro_voltage_error_data_t *)p_ev->event_data)->gyro);
                break;
            case CUBEADCS_GEN2_EVENTS_GYRO_CRITICAL_ID:
                events_ctx.read_events.last_read_events[CUBEADCS_GEN2_EVENTS_GYRO_CRITICAL] += 1;
                fs_cubeadcs_gen2_events_update_dc_error_gyro(p_dc_events->abGyro_critical_error, ((const cubeadcs_gen2_event_gyro_critical_error_data_t *)p_ev->event_data)->gyro);
                break;
            case CUBEADCS_GEN2_EVENTS_VIRTUAL_WATCHDOG_ERROR_ID:
                events_ctx.read_events.last_read_events[CUBEADCS_GEN2_EVENTS_VIRTUAL_WATCHDOG_ERROR] += 1;
                p_dc_events->bVirtual_watchdog_error = true;
                break;
            default:
                break;
        }
    }
    else
    {
        // SonarQube complaints if this is missing
    }
}

/** @brief Lock events caches
 *
 *  @note Mutex lock is set to wait forever
 *
 *  @retval true - On success
 *  @retval false - On failure
 */
STATIC bool fs_cubeadcs_gen2_events_lock_ev(void)
{
    bool op_res = true;

    if (osOK != osMutexAcquire(cubeadcs_gen2_ev_lock, osWaitForever))
    {
        op_res = false;

        EXEH_HANDLE_EX(eEXEHSeverity_Warning, eEXEHModuleID_CUBEADCS_GEN2,
                       EXEH_CUBEADCS_GEN2_OS_OBJ_ERR)
    }

    return op_res;
}

/** @brief Unlock events cache
 *
 *  @retval true - On success
 *  @retval false - On failure
 */
STATIC bool fs_cubeadcs_gen2_events_unlock_ev(void)
{
    bool op_res = true;

    if (osOK != osMutexRelease(cubeadcs_gen2_ev_lock))
    {
        op_res = false;

        EXEH_HANDLE_EX(eEXEHSeverity_Warning, eEXEHModuleID_CUBEADCS_GEN2,
                       EXEH_CUBEADCS_GEN2_OS_OBJ_ERR)
    }

    return op_res;
}

/** @brief Start event download in the context of getting the initial marker
 *
 *  @retval true - On success
 *  @retval false - On failure
 */
STATIC bool fs_cubeadcs_gen2_events_get_marker_start(void)
{
    bool op_res = false;

    TypesCubeComputerCommon3_EventLogFilterTransferSetup filter;

    // First include all classes and all sources and then modify to include only the last entry
    (void)memset((uint8_t *)&filter, 0xFF, sizeof(filter));
    filter.filterType = TYPES_CUBE_COMPUTER_COMMON_3__FILTER_LAST_X;
    filter.numEntries = 1;

    if (CUBEOBC_ERROR_OK == cubeadcs_gen2_transfer_evt((const char *)&events_f_name, &filter))
    {
        op_res = true;
    }

    return op_res;
}

/** @brief Poll event download in the context of getting the initial marker
 *
 *  @retval true - On success
 *  @retval false - On failure
 */
STATIC bool fs_cubeadcs_gen2_events_get_marker_poll(void)
{
    bool      op_res = false;
    ErrorCode err_code;

    cubeadcs_gen2_transfer_evt_status_t event_dwn_status;

    err_code = cubeadcs_gen2_transfer_evt_status(&event_dwn_status);

    if ((CUBEOBC_ERROR_OK == err_code) &&
        (CUBEOBC_ERROR_OK == event_dwn_status.err_code) &&
        (true == fs_cubeadcs_gen2_events_parse_events_log((const char *const)&events_f_name, 1)) &&
        (true == cubeadcs_gen2_events_clear_event_stats(CUBEADCS_GEN2_EVENTS_CLEAR_ALL_EVENTS)) &&
        (true == fs_cubeadcs_gen2_events_lock_ev()))
    {
        events_ctx.last_major_events_num = event_dwn_status.status.numberOfMajorWarningEvents;
        events_ctx.last_crit_events_num  = event_dwn_status.status.numberOfCriticalEvents;

        (void)fs_cubeadcs_gen2_events_unlock_ev();

        op_res = true;
    }

    return op_res;
}

/** @brief Start event download in the context of getting new critical events
 *
 *  @retval true - On success
 *  @retval false - On failure
 */
STATIC bool fs_cubeadcs_gen2_events_dwn_new_crit_events_start(void)
{
    bool op_res = false;

    TypesCubeComputerCommon3_EventLogFilterTransferSetup filter;

    if (true == fs_cubeadcs_gen2_events_lock_ev())
    {
        (void)memset((uint8_t *)&filter, 0xFF, sizeof(filter)); // Include all classes and all sources

        // Get only the last entries of classes critical and major
        filter.filterType               = TYPES_CUBE_COMPUTER_COMMON_3__FILTER_LAST_X;
        filter.numEntries               = events_ctx.events_to_download;
        filter.includeClassInfo         = false;
        filter.includeClassMinorWarning = false;

        if (CUBEOBC_ERROR_OK == cubeadcs_gen2_transfer_evt((const char *)&events_f_name, &filter))
        {
            op_res = true;
        }

        (void)fs_cubeadcs_gen2_events_unlock_ev();
    }

    return op_res;
}

/** @brief Poll event download in the context of getting the new critical events
 *
 *  @retval true - On success
 *  @retval false - On failure
 */
STATIC bool fs_cubeadcs_gen2_events_dwn_new_crit_events_poll(void)
{
    bool      op_res = false;
    ErrorCode err_code;

    cubeadcs_gen2_transfer_evt_status_t event_dwn_status;

    err_code = cubeadcs_gen2_transfer_evt_status(&event_dwn_status);

    if ((CUBEOBC_ERROR_OK == err_code) &&
        (true == fs_cubeadcs_gen2_events_lock_ev()) &&
        (true == fs_cubeadcs_gen2_events_parse_events_log((const char *const)&events_f_name, events_ctx.events_to_download)))
    {
        op_res = true;

        (void)fs_cubeadcs_gen2_events_unlock_ev();
    }

    return op_res;
}
