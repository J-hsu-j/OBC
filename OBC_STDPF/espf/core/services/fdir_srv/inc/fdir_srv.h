/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef FDIR_SRV_H
#define FDIR_SRV_H

/**
 * @addtogroup Services
 * @{
 *
 * @defgroup fdir_srv FDIR
 * @{
 *
 * ## Introduction
 *
 * The Fault Detection, Isolation and Recovery (**FDIR**) framework is a system of SW components responsible for detecting
 * fault conditions, invoking specific logic for isolating faults and possibly recovering from them. This system consists
 * of an FDIR service component and multiple client components called **agents**.
 *
 * ## Components
 *
 * ### FDIR service
 *
 * The FDIR service provides interfaces for reporting faults and maintains a static mapping of faults to agents as well as
 * a hierarchical configuration of fault handlers. When a fault is reported the service invokes the pre-configured handler functions
 * determines two types of FDIR levels - individual agent level and system level. The system FDIR level is the maximum of the
 * individual agent levels.
 *
 * ### FDIR agents
 *
 * FDIR agents are responsible for detecting faults and reporting them to the FDIR service. Any SW component can be an FDIR agent
 * as long as it implements fault detection logic for at least one of the faults defined in the FDIR service. FDIR agents usually
 * implement at least the first level of isolation/recovery handler function.
 *
 * ## Configuration and integration
 *
 * ### FDIR service
 *
 * Configuration of the FDIR service is encapsulated in the following files:
 * - espf/config/fdir_srv/fdir_srv_cfg.h - compile-time configuration of the fault and agent IDs for the system
 * - espf/config/fdir_srv/fdir_srv_cfg.c - link-time configuration of the handler action hierarchies and mappings
 *                                         between faults and agents
 *
 * When adding a new fault to the FDIR configuration, the following steps must be taken:
 *
 * 1. Add an identifier of the fault to the enumeration in **fdir_srv_cfg.h**.
 * @code {.c}
 * typedef enum
 * {
 *      FDIR_FAULT_AOCS_BROKEN, // example fault
 *      FDIR_FAULT_EPS_BROKEN,  // example fault
 *      FDIR_FAULT_COUNT,       // fault count, must be the last fault defined, before the bit-width extender value
 *      FDIR_FAULT_TYPE_EXTENDER = FDIR_ENUM_BIT_EXTENDER // This is used to force the enum to a minimum bit size
 * }fdir_fault_id_t;
 * @endcode
 *
 * 2. Identify an appropriate component that shall detect the fault. This component shall become the **agent** of the fault.
 *      Although a fault may be implemented to be detected by multiple agents, only one agent shall be handling the fault at runtime.
 *      This may be configured at compile-time, runtime during initialization or dynamically during runtime,
 *      although the latter is not recommended, as additional synchronous between agents is required.
 *
 *     @emoji :heavy_exclamation_mark: During runtime an FDIR fault MUST be handled only by a single agent.
 *
 * 3. If not already done due to previous faults, add an identifier of the agent to the enumeration in **fdir_srv_cfg.h**.
 * @code {.c}
 * typedef enum
 * {
 *      FDIR_AGENT_AOCS,    // example agent
 *      FDIR_AGENT_EPS_I,   // example agent
 *      FDIR_AGENT_EPS_II,  // example agent
 *      FDIR_AGENT_COUNT    // agent count, must be the last element,  before the bit-width extender value
 *      FDIR_AGENT_TYPE_EXTENDER = FDIR_ENUM_BIT_EXTENDER, // This is used to force the enum to a minimum bit size
 * }fdir_agent_id_t;
 * @endcode
 *
 * 4. Fault FDIR levels for a fault are defined by the @ref fdir_action_t action structure.
 *      - **fdir_level** - The level of the fault. This level is applied to the corresponding agent and the system as a whole.
 *      - **p_action_func** - The function that shall be called when the fault is detected.
 *      - **p_escalated_action** - if p_action_func returns FDIR_ACTION_RESULT_ESCALATE this action will be invoked, setting the FDIR level to its level.
 *          The escalated action will set the FDIR level to its level, only if it is higher.
 *
 *      The possible FDIR levels currently are:
 *      - **FDIR_LEVEL_WARNING** - Faults at level 0 are only logged, no automatic action is to be taken.
 *      - **FDIR_LEVEL_MINOR** - Level 1 only occur in mission submodes and will deactivate the submode.
 *      - **FDIR_LEVEL_MAJOR** - Level 2 sets ConOps to SAFE mode with active ADCS. Can only be cleared from ground command.
 *      - **FDIR_LEVEL_CRITICAL** - Level 3 sets ConOps to SAFE mode, without ADCS. Can only be cleared from ground command.
 *
 * 5. The @ref g_fdir_action global array of @ref fdir_action_t defines the first level of actions for each fault inside @ref fdir_srv_cfg.c .
 *
 *     @emoji :heavy_exclamation_mark: Each fault MUST have at least its corresponding element in the g_fdir_action array defined. The .p_action_func and .p_escalated_action may be NULL, but the fdir_level MUST be a valid value.
 *
 *      Other actions can be defined separately and attached to the action chain via the .p_escalated_action pointer.
 * Example of a fault action definition:
 * @code {.c}
 * const fdir_action_t fdir_act_aocs = // this may be declared/defined in fdir_srv_cfg.c or in a separate file as an extern and included in fdir_srv_cfg.c
 * {
 *      .fdir_level = FDIR_LEVEL_MAJOR        // Actual level should come from the system definition
 *      .p_action_func = aocs_fdir_second_handler,   // This must be a function implemented somewhere in the system, usually the handler itself
 *      .p_escalated_action = NULL            // If there is only one fault action, no reference to higher-level handler is needed
 * };
 * ...
 * const fdir_action_t g_fdir_action[FDIR_FAULT_COUNT] = // this structure is defined as extern in fdir_srv_cfg.h and defined in fdir_srv_cfg.c. It is used by the FDIR service.
 * {
 * ...
 * [FDIR_FAULT_EPS_BROKEN] = {.fdir_level = FDIR_LEVEL_WARNING, .p_action_func = NULL, .p_escalated_action = NULL}, // minimal configuration
 * [FDIR_FAULT_AOCS_BROKEN] = {.fdir_level = FDIR_LEVEL_WARNING, .p_action_func = aocs_fdir_first_handler, .p_escalated_action = &fdir_act_aocs}, // two actions chain configuration
 * ...
 * };
 * @endcode
 *
 * Additional include files may be added in fdir_srv_cfg.c to configure the handler functions and/or actions and/or be declared/defined in fdir_srv_cfg.c itself.
 *
 * ### FDIR agents
 *
 * To be part of the FDIR framework, the agents need to:
 *
 * 1. Required. Implement fault detection logic for their assigned faults. Logic could be based on inputs from device drivers, communication services and other SW components.
 *
 * 2. Required. Call **fdir_srv_fault_set_state** in the fault detection logic with the correct fault ID and agent ID.
 *
 * 3. Optional. Implement the first level of isolation/recovery action for the fault.
 *
 * 4. Optional. Implement a layer of DataCache (DC) that reads the input data and sets it to the DC, then reads it back and makes the decision based on the data.
 *      The DC is used for two purposes - read the data by operators and also override the data by operators in order to test the FDIR system or in rare cases - force the fault in a specific state.
 *
 * 5. Optional. The FDIR API supports its own logging facility, which can be used to log details about the fault when it occured.
 *
 * A basic minimal example:
 * @code {.c}
 * #include "fdir_srv.h"
 * ...
 * some_function_inside_a_software_component()
 * {
 *      ...
 *      bool result = some_function();
 *      fdir_srv_fault_set_state(FDIR_FAULT_AOCS_BROKEN, FDIR_AGENT_AOCS, result, NULL);
 *      ...
 * }
 *
 * @endcode
 *
 * More complex example:
 * @code
 * #include "fdir_srv.h"
 * #include "datacache.h"
 * ...
 * some_function_inside_a_software_component()
 * {
 *    ...
 *      DATA_CACHE_FDIR_FOR_DUMMY_AGENT_t fdir_fault_data;
 *      bool set_fault_a;
 *      bool set_fault_b;
 *
 *      fdir_fault_data.var_a = some_function_for_a(); // for example var_a is an int but may be any DataCache type
 *      fdir_fault_data.var_b = some_function_for_b(); // same for var_b
 *
 *      dc_set_fdir_for_dummy_agent_data(&fdir_fault_data); // update the DC. Will be ignored, if the operator has set any values to the DC
 *      (void)dc_get_fdir_for_dummy_agent_data(&fdir_fault_data); // read the DC back, will be either the same values of the ones set by the operator
 *
 *      if (fdir_fault_data.var_a < lower_limit_for_a || fdir_fault_data.var_a > upper_limit_for_a) // lower/upper limit here are just examples
 *      {
 *          set_fault_a = true;
 *          fdir_srv_log_if_clear(FDIR_FAULT_DUMMY_A, FDIR_AGENT_DUMMY, "Variable A (%d) out of range", fdir_fault_data.var_a); // will log only if the fault is clear in order to avoid spamming the log
 *          // i.e. this will log only if the fault is cleared and is about to be raised. Of course, if the implementer decides, they may log always and/or use the trace log
 *      }
 *      else
 *      {
 *          set_fault_a = false;
 *          fdir_srv_log_if_raised(FDIR_FAULT_DUMMY_A, FDIR_AGENT_DUMMY, "Variable A (%d) within range", fdir_fault_data.var_a); // will log only if the fault is raised in order to avoid spamming the log
 *          // i.e. this will log only if the fault is raised and is about to be cleared. Of course, if the implementer decides, they may log always, and/or use the trace log
 *      }
 *      fdir_srv_fault_set_state(FDIR_FAULT_DUMMY_A, FDIR_AGENT_DUMMY, set_fault_a, NULL);
 *
 *      // do the similar for var_b
 * }
 *
 * @endcode
 * In this example one may be tempted to optimize the code and check if the operator has set any values to the DC and if not, skip the whole data collection and DC set and get operations.
 * This is not recommended, as the timings and the functions called may have internal implications that should not be affected by the operator override.
 *
 * The "EnduroSat On-Board Computer SDK Documentation" contains information about the DataCache.
 * Follow "Developer's Guide" from the header tabs then "Development recipes" from the menu on the left and then "DataCache" in the submenu.
 *
 * @file fdir_srv.h
 * @brief Interface of the FDIR service component
 *
 * @}
 * @}
 */
#include "fdir_srv_cfg.h"
#include "fdir_srv_log.h"

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

/**
 *  @brief Performs initialization of OS objects used by the service
 *
 *  @retval true:  Initialization was successful
 *  @retval false: Initialization has failed. The FDIR service shall not be started or invoked
 */
bool fdir_srv_init(void);

/**
 *  @brief Retrieves the fault detection active flag for a given fault
 *
 *  @param fault_id[in]: ID of the checked fault
 *
 *  @retval true  Fault detection is active for this fault
 *  @retval false Fault detection is not active for this fault
 */
bool fdir_srv_fault_is_detection_enabled(const fdir_fault_id_t fault_id);

/**
 *  @brief Enables/disables detection of a specified fault
 *
 *  @param fault_id[in]: ID of the fault with the setting to be updated
 *  @param detect[in]:   true if detection is to be enabled, false otherwise
 *
 *  @retval true:  Fault detection setting successfully updated
 *  @retval false: Fault detection setting is not updated due to some internal failure of the operation
 *
 *  @note Faults with disabled detection will not have their actions invoked, even if the fault detection
 *        conditions are present
 */
bool fdir_srv_fault_enable_detection(const fdir_fault_id_t fault_id, const bool detect);

/**
 *  @brief Reports to the FDIR service that a fault has occurred in or disappeared from the system
 *
 *  @param fault_id[in]:  ID of the fault that is reported by the invoking agent
 *  @param agent[in]:     ID of the agent determining the state of the fault
 *  @param p_ctx[in,out]: Context information to be passed to the handler. Could also be modified in the handler function
 *  @param active[in]:    true if the fault is active, false if the fault has disappeared
 *
 *  @retval true:  Fault status set successfully
 *  @retval false: Setting of the fault status has failed
 */
bool fdir_srv_fault_set_state(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent, bool active, void *p_ctx);

/**
 *  @brief Same as @ref fdir_srv_fault_set_state() but ignores the autoclear limit
 *  @note This function is intended for use by the operator commands and not by the FDIR agents.
 *
 *  @param fault_id[in]:  ID of the fault that is reported by the invoking agent
 *  @param agent[in]:     ID of the agent determining the state of the fault
 *  @param p_ctx[in,out]: Context information to be passed to the handler. Could also be modified in the handler function
 *  @param active[in]:    true if the fault is active, false if the fault has disappeared
 *
 *  @retval true:  Fault status set successfully
 *  @retval false: Setting of the fault status has failed
 */
bool fdir_srv_fault_set_state_force(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent, bool active, void *ctx);

/**
 *  @brief Return the state (active/inactive) and level of a given FDIR fault
 *
 *  @param fault_id[in]:  ID of the fault that is to be read
 *
 *  @return See @ref fdir_fault_dyn_t.
 */
fdir_fault_dyn_t fdir_srv_fault_get_state(const fdir_fault_id_t fault_id);

/**
 *  @brief Retrieves the current FDIR level of a specific agent
 *
 *  @param agent_id[in]: ID of the agent whose FDIR level is retrieved
 *
 *  @return FDIR level of the agent
 */
uint8_t fdir_srv_agent_get_fdir_level(const fdir_agent_id_t agent_id);

/**
 *  @brief Retrieves the overall FDIR level of the system. This is the highest FDIR level of an agent
 *
 *  @return Highest FDIR level among all agents
 */
uint8_t fdir_srv_system_get_fdir_level(void);

/**
 *  @brief Gets the active FDIR level for the system which cannot be
 *         reduced by recovery via the regular service logic.
 *
 *  @return The minimum system FDIR level to be set
 *
 */
uint8_t fdir_srv_system_get_fdir_level_min(void);

/**
 *  @brief Sets an active FDIR level for the system which cannot be
 *         reduced by recovery via the regular service logic. This is used
 *         to simulate FDIR conditions with system impact (e.g. on ConOps mode transitions)
 *
 *  @param level[in]: The minimum system FDIR level to be set
 *
 */
bool fdir_srv_system_set_fdir_level_min(const uint8_t level);

/**
 *  @brief Gets the currently set minimum FDIR level at which no automatic clear will occur by the FDIR service
 *
 *  @param level[in]: Minimum FDIR level at which no automatic clear will occur
 */
uint8_t fdir_srv_system_get_user_clear_level(void);

/**
 *  @brief Sets the minimum FDIR level at which no automatic clear will occur by the FDIR service
 *
 *  @param level[in]: Minimum FDIR level at which no automatic clear will occur
 */
bool fdir_srv_system_set_user_clear_level(const uint8_t level);

#endif /* FDIR_SRV_H */
