/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef LIBHSM_H_
#define LIBHSM_H_

/**
 * @addtogroup Libraries
 * @{
 *
 * @defgroup libhsm HSM
 * @{
 *
 * Hierarchical State Machine engine.
 *
 * @file libhsm.h
 * @brief HSM engine library public interface.
 *
 * @}
 * @}
 */

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

#include <stdbool.h>
#include <stdint.h>

#ifndef HSM_MAX_NEST_LEVEL
/* @brief Maximum nesting level for the HSM */
#define HSM_MAX_NEST_LEVEL (5U)
#endif // #ifndef HSM_MAX_NEST_LEVEL

/* @brief A macro to use in order to downcast a sState_t pointer to sCompositeState_t pointer */
#define HSM_DOWNCAST_COMPOSITE(pState) ((sCompositeState_t *)pState)

/* @brief A macro to use in order to upcast a sCompositeState_t pointer to sState_t pointer */
#define HSM_UPCAST_STATE(pState) ((sState_t *)pState)

/* @brief A macro to use when setting the id of an SM event */
#define HSM_SET_EVENT_ID(evt, ident) \
    do                               \
    {                                \
        evt.id = ident;              \
    } while (false)

/**
 * @brief The base type used to represent state machine events
 *
 * This can be used in user structures as a first field and extended with additional custom fields to
 * pass to the state machine instance.
 *
 *    typedef struct
 *    {
 *        sHSM_EventType_t baseEvent;
 *        uint32_t customField;
 *        uint8_t yetAnotherCustomField;
 *    } CustomEventType;
 *
 *    // use as shown below...
 *    CustomEventType myEvent;
 *
 *    myEvent.customField = 5;
 *    myEvent.yetAnotherCustomField = 10;
 *
 *    HSM_TriggerEvent(&SMRoot, &myEvent);
 *
 *    // then you can access your custom fields in the entry/exit/guard functions of your SM...
 */
typedef struct
{
    uint32_t id; /* !< event identifier */
} sHSM_EventType_t;

/**
 * @brief Enumerates all standard SM events supported by the engine.
 */
enum eHSM_StdEvent
{
    eHSM_StdEvent_Reset    = 0, /* !< SM initialization event */
    eHSM_StdEvent_Periodic = 1, /* !< regular event sent to the machine when it has to execute periodic activity in the active state */
    eHSM_StdEvent_UserEvStart
};

/**
 * @brief Transition types supported by the engine
 */
typedef enum
{
    eHSM_StateType_Simple,    /* !< this is a leaf state which doesn't contain any other states */
    eHSM_StateType_Composite, /* !< a state which acts as a parent to other states(may they be composite or simple) */
    eHSM_StateType_History,   /* !< history state(applies to composite states only) */
    eHSM_StateType_MAX
} eHSM_StateType_t;

struct sStateTag;
typedef struct sTransition_tag sTransition_t;
typedef struct sState_tag      sState_t;
typedef struct sComposite_tag  sCompositeState_t;

typedef void (*pfActionHandler_t)(const uint16_t instance_id, const sState_t *const pSMRoot, const sHSM_EventType_t *const pEvent);
typedef bool (*pfConditionEvaluator_t)(const uint16_t instance_id, const sState_t *const pSMRoot, const sHSM_EventType_t *const pEvent);

struct sState_tag
{
    const uint8_t               state_id;        /* !< Unique state identifier used for checking the active state */
    const char *const           pName;           /* !< Name of the state used for tracing purposes */
    const pfActionHandler_t     onEntryFunc;     /* !< Handler executed when an incoming state transition is performed */
    const pfActionHandler_t     onExitFunc;      /* !< Handler executed when an outgoing state transition is performed */
    const sTransition_t *const *pTransitionList; /* !< Linked list of all valid transitions from this state */
    const eHSM_StateType_t      eType;           /* !< Indicates the type of the state */
    const sState_t *const       pParent;         /* !< Parent state machine in case of hierarchical state machines */
};

struct sTransition_tag
{
    const uint32_t               eventId;                /* !< Event identifier */
    const pfConditionEvaluator_t guardFunc;              /* !< Trigger conditional guard function; if true - the transition is executed, otherwise - not */
    const sState_t *const        pTargetState;           /* !< Target state to jump to if the transition succeeds; if NULL, the transition is internal and the state remains unchanged  */
    const pfActionHandler_t      onTransitionActionFunc; /* !< Transition side action handler; executed if the transition succeeds */
};

struct sComposite_tag
{
    const sState_t        state;          /* !< Finite state definition (common for finite and composite states) */
    const sState_t *const pInitialState;  /* !< A pointer to the SM initial state set on the HSM_Init() call */
    const uint16_t        instanceCnt;    /* !< Number of instances for pHistoryState and pActiveState lists */
    sState_t            **ppHistoryState; /* !< A list of last active child states before switching to parent state */
    sState_t            **ppActiveState;  /* !< A list of pointers to the currently active states in the composite for each instance */
};

/**
 * @brief The function is used to trigger an SM event using the raw event type which enables
 *          users to pass events arguments as well.
 *
 * @param pSMRoot a pointer to the SM root state
 * @param pEv a pointer to an user event
 *
 * @returns true - event handled; false - event not handled in the current state
 */
bool HSM_TriggerEvent_raw(sState_t *const pSMRoot, const sHSM_EventType_t *const pEv);

/**
 * @brief The function is used to trigger an SM event using the raw event type which enables
 *        users to pass events arguments as well. The function allows you to specify an
 *        instance identifier.
 *
 * @param instance_id SM instance id (must be 0 in case of single instance)
 * @param pSMRoot a pointer to the SM root state
 * @param pEv a pointer to an user event
 *
 * @returns true - event handled; false - event not handled in the current state
 */
bool HSM_TriggerEventForInstance_raw(const uint16_t instance_id, sState_t *const pSMRoot, const sHSM_EventType_t *const pEv);

/**
 * @brief The function is used to trigger an SM event using a simple identifier without event
 *          parameters.
 *
 * @param pSMRoot a pointer to the SM root state
 * @param event_id SM event identifier
 *
 * @note For multi-instance configurations, this function always works with instance 0 and is
 * kept for backward compatibility.
 *
 * @returns see @ref HSM_TriggerEvent_raw() return value description (this function is just a wrapper around it)
 */
bool HSM_TriggerEvent(sState_t *const pSMRoot, const uint32_t event_id);

/**
 * @brief The function is used to trigger an SM event to a specified SM instance using a simple identifier without event
 *          parameters.
 *
 * @param instance_id SM instance id (must be 0 in case of single instance)
 * @param pSMRoot a pointer to the SM root state
 * @param event_id SM event identifier
 *
 * @returns see @ref HSM_TriggerEvent_raw() return value description (this function is just a wrapper around it)
 */
bool HSM_TriggerEventForInstance(const uint16_t instance_id, sState_t *const pSMRoot, const uint32_t event_id);

/**
 * @brief The function provides the currently active leaf state.
 *
 * @param pSMRoot a pointer to the SM root state
 *
 * @note For multi-instance configurations, this function always works with instance 0 and is
 * kept for backward compatibility.
 *
 * @return A pointer to the leaf state which is currently active (e.g. if a composite is active, this
 * function returns the substate in which the composite is at its lowest nesting level.
 */
const sState_t *HSM_GetActiveState(sState_t *const pSMRoot);

/**
 * @brief The function provides the currently active leaf state for a specified HSM instance.
 *
 * @param instance_id SM instance id (must be 0 in case of single instance)
 * @param pSMRoot a pointer to the SM root state
 * @return A pointer to the leaf state which is currently active (e.g. if a composite is active, this
 * function returns the substate in which the composite is at its lowest nesting level.
 */
const sState_t *HSM_GetActiveStateForInstance(const uint16_t instance_id, sState_t *const pSMRoot);

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #ifndef LIBHSM_H_
