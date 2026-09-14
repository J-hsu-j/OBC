/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef CUBEADCS_GEN2_H
#define CUBEADCS_GEN2_H

/**
 * @addtogroup Services
 * @{
 * @defgroup cubeadcs_gen2
 * @{
 *
 * @file     cubeadcs_gen2.h
 * @brief    Cubeadcs Generation 2 main service header
 *
 * @}
 * @}
 */

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

#include "cmsis_os2.h"
#include "libhsm.h"

#include "cubeadcs_gen2_types.h"
#include "nvm_app_types.h"

/** @brief State machine related task period in milliseconds. Base time used for periodic SM transition checks. */
#define CUBEADCS_GEN2_SM_TASK_BASE_PERIOD_MS (500U)
/** @brief State machine related task period in milliseconds. FAST time used when handling a SM state. */
#define CUBEADCS_GEN2_SM_TASK_FAST_PERIOD_MS (100U)

/** @brief Max number of attempts to reset the CUBEADCS to recover from bootloader */
#define CUBEADCS_GEN2_FDIR_MAX_RESET_TRY (3U)

/** @brief Max number of power cycle attempts to recover from bootloader */
#define CUBEADCS_GEN2_FDIR_MAX_POWER_CYCLE_TRY (1U)

/** @brief Cubeadcs gen2 service context */
typedef struct
{
    cubeadcs_gen2_sys_state_t               current_system_state;
    osThreadId_t                            cubeadcs_gen2_task_handle;
    cubeadcs_gen2_sys_state_change_status_t state_change_status;
} cubeadcs_gen2_service_ctx_t;

/** @brief Event context */
typedef struct
{
    cubeadcs_gen2_sys_state_t sys_state;
} sm_event_ctx_t;

/** @brief Custom event for triggering a state change */
typedef struct
{
    sHSM_EventType_t base_event;
    sm_event_ctx_t   event_ctx;

} sm_event_t;

/** @brief Operational Status of the ADCS - common telemetry between control programs */
typedef struct
{
    TypesCommonFramework1_BootStatus             boot_status;
    TypesCubeComputerCommon3_PowerState          power_state;
    TypesCubeComputerCommon3_ComponentErrorCodes comp_err_codes;
    bool                                         is_valid;

} PACKED op_status_common_t;

/** @brief Operational Status of the ADCS - application control program telemetry */
typedef struct
{
    TypesCubeComputerControlProgram8_AdcsRunMode run_mode;
    TypesCubeComputerControlProgram8_ConMode     control_mode;
    TypesCubeComputerControlProgram8_EstMode     est_mode;
    TypesCubeComputerControlProgram8_AdcsOpState op_state;
    bool                                         is_valid;

} PACKED op_status_app_t;

/** @brief Operational Status of the ADCS */
typedef struct
{
    op_status_common_t common_tlm;
    op_status_app_t    app_tlm;

} PACKED op_status_t;

/** @brief Initialise the cubeadcs gen2 main service task */
void cubeadcs_gen2_os_init(void);
/** @brief De-initialise the cubeadcs gen2 main service task */
void cubeadcs_gen2_os_deinit(void);
/** @brief Trigger the gen2 state machine
 *
 *  @param[in] const uint32_t event_id - the event to trigger the SM with
 *  @param[in] const sm_event_ctx_t * const event_ctx - the event context
 *
 *  @note The SM is locked during the transitions so no new events can be triggered until the current
 *  transition is completed
 *
 * */
bool cubeadcs_gen2_trigger_sm(const uint32_t event_id, const sm_event_ctx_t *const event_ctx);

/** @brief Get the gen2 sm state
 *
 *  @return sState_t * - pointer to the current state of the SM
 */
const sState_t *cubeadcs_gen2_get_sm_state(void);

/** @brief State change init
 *
 *  @note Called to clear the state change last retry counters
 *
 */
void cubeadcs_gen2_state_change_init(void);

/** @brief Get the last read operational status of the ADCS
 *
 * @param[in] op_status_t * const p_op_status - pointer to op status dst
 *
 */
void cubeadcs_gen2_get_op_status(op_status_t *const p_op_status);

/** @brief Set the service system state
 *
 * @param[in] const cubeadcs_gen2_sys_state_t * const p_new_sys_state - pointer to the system state
 *
 * @return bool - True on Success, False on Failure
 *
 */
bool cubeadcs_gen2_set_sys_state(const cubeadcs_gen2_sys_state_t *const p_new_sys_state);

/** @brief Get the service context
 *
 * @param[out] cubeadcs_gen2_service_ctx_t * const p_ctx - pointer to the cotext copy location
 *
 * @return bool - True on Success, False on Failure
 *
 */
bool cubeadcs_gen2_get_service_ctx(cubeadcs_gen2_service_ctx_t *const p_ctx);

/** @brief Reset request handler
 *
 *  @note This function takes care of a reset request from the user. The user provides the program type and the handler
 *  performs the reset and all necessary setup to put the ADCS in this program
 *
 * @param[in] cubeadcs_gen2_control_program_type_t prog_type_req - program type after reset
 *
 * @return bool - True on Success, False on Failure
 *
 */
bool cubeadcs_gen2_reset_handler(cubeadcs_gen2_control_program_type_t prog_type_req);

/** @brief Set the service system state change status
 *
 * @param[in] const cubeadcs_gen2_sys_state_change_status_t new_sys_state_change_status - the new system state
 *
 * @return bool - True on Success, False on Failure
 *
 */
bool cubeadcs_gen2_set_sys_state_change_status(const cubeadcs_gen2_sys_state_change_status_t new_sys_state_change_status);

/**
 * @brief Get the commissioning status of the Gen2 CubeADCS
 *
 * @param[out]:  uint8_t * p_status - Storage location for the read status
 *
 * @retval true: Commissioning status successfully read
 * @retval false: Error reading commissioning status
 */
bool cubeadcs_gen2_get_cms_status(uint8_t *const p_status);

/** @brief Set the commissioning status of the Gen2 CubeADCS
 *
 * @param[in] const uint8_t new_status - the new commissioning status
 *
 * @retval true: Commissioning status successfully set
 * @retval false: Error setting commissioning status
 *
 *@note This method shall be invoked only via FP by the mission control
 *
 */
bool cubeadcs_gen2_set_cms_status(const uint8_t new_status);

/**
 * @brief Reads configuration parameters of the CubeComputer needed by the Gen2 service
 *
 * @note This function should be called once on initialization of the Gen2 service
 *       In future, it could be used as part of a procedure to restart the service
 *
 * @retval true: Configuration data is successfully read from the CubeComputer
 * @retval false: An error has occurred while reading configuration data from the CubeComputer
 *                It could be either a CubeSpace API error or internal error during mutex acquisition
 */
bool cubeadcs_gen2_init_adcs_cfg_cache(void);

/**
 * @brief Determines the CubeADCS peripheral node type from a given abstract node type.
 *
 * @param[in] abstract_node_type Abstract node type of the node for which we want to determine
 *            the node type (see Gen2 CubeADCS documentation)
 *
 * @return Node type of the abstract node
 */
TypesCommonFrameworkTypes1_NodeType cubeadcs_gen2_get_node_type(const TypesCommonFrameworkTypes1_AbstractNode abstract_node_type);

/**
 * @brief Get function for flag that indicates that the user wants the ADCS to stay in bootloader
 *
 * @return stay in bootloader flag
 */
bool cubeadcs_gen2_get_stay_in_bootloader(void);

/**
 * @brief Set function for flag that indicates that the user wants the ADCS to stay in bootloader
 *
 * @param[in] bool stay_in_btl - Stay in bootloader flag
 */
void cubeadcs_gen2_set_stay_in_bootloader(const bool stay_in_btl);

/**
 * @brief Get function for flag that indicates that fw update is in progress
 *
 * @return Fw update in progress flag
 */
bool cubeadcs_gen2_get_fw_upd_flag(void);

/**
 * @brief Set function for flag that indicates that firmware update is in progress
 *
 * @param[in] bool fw_upd_flag - firmware update flag
 */
void cubeadcs_gen2_set_fw_upd_flag(const bool fw_upd_flag);

/**
 * @brief Set function for FDIR reset counters in NVM
 *
 * @param[in] cubeadcs_gen2_fdir_counter_t *const p_counters - structure to be stored in the nvm
 */
void cubeadcs_gen2_set_fdir_cnt_to_nvm(cubeadcs_gen2_fdir_counter_t *const p_counters);

/**
 * @brief Get function for FDIR reset counters in NVM
 *
 * @param[out] cubeadcs_gen2_fdir_counter_t *const p_counters - structure to be loaded from the nvm
 */
void cubeadcs_gen2_get_fdir_cnt_from_nvm(cubeadcs_gen2_fdir_counter_t *const p_counters);

/** @brief Increase the counter for detecting bootloader
 *
 * @note This function is called in the check state and it increases the counter for detecting bootloader.
 *  It is a separate function for the purpose of clarity of the code.
 */
void cubeadcs_gen2_increase_btl_detected_cnt(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif /* CUBEADCS_GEN2_H */

/* ******************************************************************************************* */
