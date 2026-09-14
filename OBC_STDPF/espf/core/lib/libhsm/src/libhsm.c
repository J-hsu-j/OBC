/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup libhsm
 * @{
 *
 * @file libhsm.c
 * @brief This is a hierarchical state machine engine library.
 *
 * @}
 */

#include "libhsm.h"
#include "libhsm_cfg.h"
#include <stddef.h>

static const char *const CC_NONAME = "unknown";

/**@brief Default instance to use for backward-compatible functions which do not
 * have the instance parameter
 * */
static const uint16_t DEFAULT_INSTANCE = 0U;

inline static const char *HSM_sf_STR(const char *str, const char *ifnull_str);
static inline bool        HSM_sf_IsStateComposite(const sState_t *const pState);
static inline void        HSM_sf_TraceEntryAction(const sState_t *const pState);
static inline void        HSM_sf_TraceExitAction(const sState_t *const pState);

static const sTransition_t *HSM_sf_getActiveTransition(const uint16_t                instance_id,
                                                       sState_t *const               pSMRoot,
                                                       const sState_t *const         pState,
                                                       const sHSM_EventType_t *const pEv);

static const sState_t *HSM_sf_TriggerStateEvent(const uint16_t                instance_id,
                                                sState_t *const               pSMRoot,
                                                const sState_t *const         pActiveState,
                                                const sHSM_EventType_t *const pEv,
                                                bool *const                   pSkipEntryExitActions);

static void HSM_sf_ExecuteExitActions(const uint16_t                instance_id,
                                      sState_t *const               pSMRoot,
                                      const sState_t *const         pActiveState,
                                      const sState_t *const         pTopState,
                                      const sHSM_EventType_t *const pEv);

static const sState_t *HSM_sf_ExecuteEntryActions(
    const uint16_t                instance_id,
    sState_t *const               pSMRoot,
    const sState_t *const         pTopState,
    const sState_t *const         pTargetState,
    const sHSM_EventType_t *const pEv);

static const sState_t *const HSM_sf_FindCommonParent(const sState_t *const pSourceState,
                                                     const sState_t *const pTargetState);

static void HSM_sf_AddToStackSafe(const sState_t **const pStateStack, const sState_t *const pState,
                                  uint8_t *const pSlotIndex);

static const sState_t *HSM_sf_GetInitialState(sState_t *const       pSMRoot,
                                              const sState_t *const pState);

static const sState_t *HSM_sf_GetDeepHistoryState(const uint16_t instance_id, sState_t *const pSMRoot, const sState_t *const pHistoryState);

static bool HSM_sf_IsInstanceValid(const uint16_t instance_id, sState_t *const pSMRoot);

bool HSM_TriggerEventForInstance_raw(const uint16_t instance_id, sState_t *const pSMRoot, const sHSM_EventType_t *const pEv)
{
    bool res = false;

    // to avoid some compiler warnings in case the trace macros are not defined and
    // the CC_NONAME becomes unused (currently used only by the trace macros)
    (void)CC_NONAME;

    if ((true == HSM_sf_IsInstanceValid(instance_id, pSMRoot)) && (pEv != NULL))
    {
        const sState_t *pTargetState            = NULL;
        const sState_t *pActiveStateForInstance = HSM_DOWNCAST_COMPOSITE(pSMRoot)->ppActiveState[instance_id];

        // this function accepts only the SM root state which must be configured as
        // composite
        HSM_ASSERT(HSM_sf_IsStateComposite(pSMRoot));
        HSM_ASSERT(HSM_DOWNCAST_COMPOSITE(pSMRoot)->pInitialState != NULL);

        if (eHSM_StdEvent_Reset == pEv->id)
        {
            // execute all exit actions up to root before going to intial state
            // (this aims to perform any kind of deinitialization on the existing
            // active hierarchy of states to ensure the the SM goes to Init state
            // clean)
            if (pActiveStateForInstance != NULL)
            {
                HSM_sf_ExecuteExitActions(
                    instance_id, pSMRoot, pActiveStateForInstance, pSMRoot, pEv);
            }

            pTargetState = HSM_sf_GetInitialState(pSMRoot, pSMRoot);

            // execute entry actions for the initial state
            (void)HSM_sf_ExecuteEntryActions(instance_id, pSMRoot, pSMRoot, pTargetState, pEv);
        }
        else
        {
            pTargetState = HSM_sf_TriggerStateEvent(instance_id,
                                                    pSMRoot, pActiveStateForInstance, pEv, NULL);
        }

        // switch to transition target state
        if (pTargetState != NULL)
        {
            if ((pEv->id != eHSM_StdEvent_Periodic) ||
                ((pEv->id == eHSM_StdEvent_Periodic) &&
                 (pActiveStateForInstance != pTargetState)))
            {
                HSM_TRACE_INFO(
                    "[%s:%u] %s -- %ld --> %s", HSM_sf_STR(pSMRoot->pName, "n/a"),
                    instance_id,
                    (pActiveStateForInstance != NULL)
                        ? HSM_sf_STR(pActiveStateForInstance->pName,
                                     CC_NONAME)
                        : ("()"),
                    pEv->id, HSM_sf_STR(pTargetState->pName, CC_NONAME));
            }

            (HSM_DOWNCAST_COMPOSITE(pSMRoot)->ppActiveState)[instance_id] = HSM_UPCAST_STATE(pTargetState);

            res = true;
        }
        else
        {
            HSM_TRACE_DEBUG("[%s:%u] Unhandled event: %ld",
                            HSM_sf_STR(pSMRoot->pName, CC_NONAME), instance_id, pEv->id);
        }
    }
    else
    {
        HSM_TRACE_DEBUG("Bad arguments passed to function [instance_id = %u, pSMRoot = 0x%p, pEv = 0x%p]", instance_id, pSMRoot, pEv);
    }

    return res;
}

bool HSM_TriggerEvent_raw(sState_t *const pSMRoot, const sHSM_EventType_t *const pEv)
{
    return HSM_TriggerEventForInstance_raw(DEFAULT_INSTANCE, pSMRoot, pEv);
}

bool HSM_TriggerEventForInstance(const uint16_t instance_id, sState_t *const pSMRoot, const uint32_t event_id)
{
    sHSM_EventType_t evt;

    evt.id = event_id;

    return HSM_TriggerEventForInstance_raw(instance_id, pSMRoot, &evt);
}

bool HSM_TriggerEvent(sState_t *const pSMRoot, const uint32_t event_id)
{
    return HSM_TriggerEventForInstance(DEFAULT_INSTANCE, pSMRoot, event_id);
}

const sState_t *HSM_GetActiveState(sState_t *const pSMRoot)
{
    return HSM_GetActiveStateForInstance(DEFAULT_INSTANCE, pSMRoot);
}

const sState_t *HSM_GetActiveStateForInstance(const uint16_t instance_id, sState_t *const pSMRoot)
{
    const sState_t *pActiveState = NULL;

    if (true == HSM_sf_IsInstanceValid(instance_id, pSMRoot))
    {
        if ((pSMRoot->eType == eHSM_StateType_Composite) && (NULL == pSMRoot->pParent))
        {
            pActiveState = HSM_DOWNCAST_COMPOSITE(pSMRoot)->ppActiveState[instance_id];
        }
        else
        {
            HSM_TRACE_ERROR("pSMRoot does not point to a valid root state");
        }
    }
    else
    {
        HSM_TRACE_ERROR("pSMRoot is NULL or instance is invalid [instance_id = %u, pSMRoot = 0x%p]", instance_id, pSMRoot);
    }

    return pActiveState;
}

static const sTransition_t *HSM_sf_getActiveTransition(const uint16_t                instance_id,
                                                       sState_t *const               pSMRoot,
                                                       const sState_t *const         pState,
                                                       const sHSM_EventType_t *const pEv)
{
    const sTransition_t *pActiveTrans = (sTransition_t *)NULL;

    HSM_ASSERT(pSMRoot != NULL);
    HSM_ASSERT(pState != (sState_t *)NULL);
    HSM_ASSERT(pEv != NULL);
    HSM_ASSERT(HSM_sf_IsInstanceValid(instance_id, pSMRoot));

    // finite state handling
    const sTransition_t *const *pTransIter       = pState->pTransitionList;
    const sTransition_t        *pTransitionEntry = (pTransIter != NULL) ? (*pTransIter) : (NULL);

    while (pTransitionEntry != NULL)
    {
        if ((pTransitionEntry->eventId == pEv->id) &&
            ((pTransitionEntry->guardFunc == NULL) ||
             (true == (*pTransitionEntry->guardFunc)(instance_id, pSMRoot, pEv))))
        {
            pActiveTrans = pTransitionEntry;
            break;
        }

        pTransIter += 1;
        pTransitionEntry = *(pTransIter);
    }

    return pActiveTrans;
}

static const sState_t *const HSM_sf_FindCommonParent(const sState_t *const pSourceState,
                                                     const sState_t *const pTargetState)
{
    const sState_t *pStatePath[HSM_MAX_NEST_LEVEL] = { NULL };
    uint8_t         u8StateIndex                   = 0U;

    const sState_t *pCommonRoot = (sState_t *)NULL;
    const sState_t *pStateIter  = pSourceState;

    HSM_ASSERT(pSourceState != NULL);
    HSM_ASSERT(pTargetState != NULL);

    // build the reverse path from the source state to the root and store it for
    // future reference
    while (pStateIter->pParent != NULL)
    {
        HSM_sf_AddToStackSafe(pStatePath, pStateIter->pParent, &u8StateIndex);

        pStateIter = pStateIter->pParent;
    }

    // now scan the reverse path from the second target state and check if it is
    // present in the source state path to determine the LCA
    pStateIter = pTargetState;

    bool bLcaFound = false;

    while ((pStateIter->pParent != NULL) && (!bLcaFound))
    {
        for (uint8_t src_idx = 0; src_idx < u8StateIndex; src_idx++)
        {
            if (pStateIter->pParent == pStatePath[src_idx])
            {
                // we are at the top of the hiearchy, just drop off the search...
                pCommonRoot = pStateIter->pParent;
                bLcaFound   = true;
                break;
            }
        }

        pStateIter = pStateIter->pParent;
    }

    return pCommonRoot;
}

static void HSM_sf_ExecuteExitActions(const uint16_t                instance_id,
                                      sState_t *const               pSMRoot,
                                      const sState_t *const         pActiveState,
                                      const sState_t *const         pTopState,
                                      const sHSM_EventType_t *const pEv)
{
    const sState_t *pStateIter = (sState_t *)NULL;

    HSM_ASSERT(pSMRoot != NULL);
    HSM_ASSERT(pActiveState != NULL);
    HSM_ASSERT(pTopState != NULL);
    HSM_ASSERT(HSM_sf_IsInstanceValid(instance_id, pSMRoot));

    // trigger current state exit function if such exists
    if (pActiveState->onExitFunc != NULL)
    {
        HSM_sf_TraceExitAction(pActiveState);
        (*pActiveState->onExitFunc)(instance_id, pSMRoot, pEv);
    }

    // ...now go up the hierarchy and execute all parent exit actions
    pStateIter = pActiveState->pParent;

    while ((pStateIter != NULL) && (pStateIter != pTopState))
    {
        if (pStateIter->onExitFunc != NULL)
        {
            HSM_sf_TraceExitAction(pStateIter);
            (*pStateIter->onExitFunc)(instance_id, pSMRoot, pEv);
        }

        pStateIter = pStateIter->pParent;
    }
}

static const sState_t *HSM_sf_ExecuteEntryActions(const uint16_t                instance_id,
                                                  sState_t *const               pSMRoot,
                                                  const sState_t *const         pTopState,
                                                  const sState_t *const         pTargetState,
                                                  const sHSM_EventType_t *const pEv)
{
    const sState_t *pStateIter                      = (sState_t *)NULL;
    const sState_t *pStateStack[HSM_MAX_NEST_LEVEL] = { NULL };
    const sState_t *pFinalState                     = (sState_t *)NULL;
    uint8_t         u8StateStackIndex               = 0U;

    HSM_ASSERT(pSMRoot != NULL);
    HSM_ASSERT(pTopState != NULL);
    HSM_ASSERT(pTargetState != NULL);
    HSM_ASSERT(HSM_sf_IsInstanceValid(instance_id, pSMRoot));

    // locate the initial state of the target state (the initial state could be different from
    // pTargetState in case pTargetState is a composite state
    pFinalState = HSM_sf_GetInitialState(pSMRoot, pTargetState);

    // start preparation of the entry actions stack...
    HSM_sf_AddToStackSafe(pStateStack, pFinalState, &u8StateStackIndex);

    const sState_t *pChildState = pFinalState;

    // ...now go up the hierarchy and build the entry functions stack
    pStateIter = pFinalState->pParent;

    while (pStateIter != NULL)
    {
        // preserve deep history state
        (HSM_DOWNCAST_COMPOSITE(pStateIter)->ppHistoryState)[instance_id] = HSM_UPCAST_STATE(pChildState);
        pChildState                                                       = pStateIter;

        // top state will not be added to the stack because it is not actually entered, hence
        // its entry actions must not be executed
        if (pStateIter != pTopState)
        {
            HSM_sf_AddToStackSafe(pStateStack, pStateIter, &u8StateStackIndex);
        }

        pStateIter = pStateIter->pParent;
    }

    // ...unwind the stack and execute the nested state entry functions in the
    // correct order
    while (u8StateStackIndex > 0U)
    {
        u8StateStackIndex--;
        pStateIter = pStateStack[u8StateStackIndex];

        if ((pStateIter != NULL) && (pStateIter->onEntryFunc != NULL))
        {
            HSM_sf_TraceEntryAction((sState_t *)pStateIter);
            (*pStateIter->onEntryFunc)(instance_id, pSMRoot, pEv);
        }
    }

    return pFinalState;
}

static const sState_t *HSM_sf_GetDeepHistoryState(const uint16_t instance_id, sState_t *const pSMRoot, const sState_t *const pHistoryState)
{
    HSM_ASSERT(NULL != pSMRoot);
    HSM_ASSERT(NULL != pHistoryState);
    HSM_ASSERT(pHistoryState->eType == eHSM_StateType_History);
    HSM_ASSERT(HSM_sf_IsInstanceValid(instance_id, pSMRoot));

    // for history pseudo states, the parent is a pointer to the state for which the history state relates to and
    // this is guaranteed by the hsmgen script
    const sState_t *pStateIter = pHistoryState->pParent;

    while (pStateIter != NULL)
    {
        if (true == HSM_sf_IsStateComposite(pStateIter))
        {
            pStateIter = HSM_DOWNCAST_COMPOSITE(pStateIter)->ppHistoryState[instance_id];
        }
        else
        {
            // non-composite state found -> this shall be the deep history state we are looking for;
            // no more elephants on the way down as there is no way down... :)
            break;
        }
    }

    return pStateIter;
}

static const sState_t *HSM_sf_TriggerStateEvent(const uint16_t                instance_id,
                                                sState_t *const               pSMRoot,
                                                const sState_t *const         pActiveState,
                                                const sHSM_EventType_t *const pEv,
                                                bool *const                   pSkipEntryExitActions)
{
    const sState_t *pTargetStateReached = pActiveState;

    HSM_ASSERT(pSMRoot != NULL);
    HSM_ASSERT(pEv != NULL);
    HSM_ASSERT(HSM_sf_IsInstanceValid(instance_id, pSMRoot));

    bool SkipEntryExitActions = false; // indicates whether entry/exit actions shall be skipped upon successful transition

    if (pActiveState != NULL)
    {
        HSM_TRACE_DEBUG(">> %ld >> %s", pEv->id, HSM_sf_STR(pActiveState->pName, CC_NONAME));

        const sTransition_t *pActiveTrans = HSM_sf_getActiveTransition(instance_id, pSMRoot, pActiveState, pEv);

        if (pActiveTrans != NULL)
        {
            const sState_t *pLCA         = NULL;
            const sState_t *pTargetState = pActiveTrans->pTargetState;

            if (pTargetState != NULL)
            {
                // if this is a history state, then redirect the target...
                if (pTargetState->eType == eHSM_StateType_History)
                {
                    HSM_ASSERT(pTargetState->pParent != NULL);
                    pTargetState = HSM_sf_GetDeepHistoryState(instance_id, pSMRoot, pTargetState);

                    SkipEntryExitActions = (pTargetState == HSM_DOWNCAST_COMPOSITE(pSMRoot)->ppActiveState[instance_id]);
                }

                // if we end up in the same state, no exit/entry actions will be performed -> just the transition action function
                if (!SkipEntryExitActions)
                {
                    pLCA = HSM_sf_FindCommonParent(pActiveState, pTargetState);

                    if ((pEv->id != eHSM_StdEvent_Periodic) ||
                        (pActiveState != pTargetState))
                    {
                        HSM_TRACE_DEBUG("trans start: %s -- %ld --> %s",
                                        HSM_sf_STR(pActiveState->pName, CC_NONAME), pEv->id,
                                        HSM_sf_STR(pTargetState->pName, CC_NONAME));
                    }

                    HSM_sf_ExecuteExitActions(instance_id, pSMRoot, pActiveState, pLCA, pEv);
                }
            }
            else
            {
                if (pEv->id != eHSM_StdEvent_Periodic)
                {
                    HSM_TRACE_INFO("internal trans: %s -- %ld --> %s",
                                   HSM_sf_STR(pActiveState->pName, CC_NONAME), pEv->id,
                                   HSM_sf_STR(pActiveState->pName, CC_NONAME));
                }
            }

            // trigger transition action function if it exists
            if (pActiveTrans->onTransitionActionFunc != NULL)
            {
                pActiveTrans->onTransitionActionFunc(instance_id, pSMRoot, pEv);
            }

            if ((pTargetState != NULL) && (!SkipEntryExitActions))
            {
                pTargetStateReached = HSM_sf_ExecuteEntryActions(instance_id, pSMRoot, pLCA, pTargetState, pEv);
            }
            else
            {
                pTargetStateReached = pTargetState;
            }
        }
        else
        {
            // if this is not the top state, go up the hierarchy to find a handler at
            // upper level...
            if (NULL != pActiveState->pParent)
            {
                pTargetStateReached = HSM_sf_TriggerStateEvent(instance_id, pSMRoot, pActiveState->pParent, pEv, &SkipEntryExitActions);

                if ((NULL != pTargetStateReached) && (!SkipEntryExitActions))
                {
                    // transition was handled at upper level so we need to execute exit
                    // actions for this state only
                    HSM_sf_ExecuteExitActions(instance_id, pSMRoot, pActiveState, pActiveState->pParent, pEv);
                }
            }
            else
            {
                pTargetStateReached = NULL;
            }
        }
    }
    else
    {
        HSM_TRACE_ERROR("[%s] error: pActiveState is NULL", __func__);
    }

    if (NULL != pSkipEntryExitActions)
    {
        *pSkipEntryExitActions = SkipEntryExitActions;
    }

    return pTargetStateReached;
}

static void HSM_sf_AddToStackSafe(const sState_t **const pStateStack, const sState_t *const pState,
                                  uint8_t *const pSlotIndex)
{
    HSM_ASSERT(pStateStack != NULL);
    HSM_ASSERT(pState != NULL);
    HSM_ASSERT(pSlotIndex != NULL);

    if ((*pSlotIndex) < HSM_MAX_NEST_LEVEL)
    {
        pStateStack[(*pSlotIndex)++] = pState;
    }
    else
    {
        HSM_TRACE_ERROR("HSM_MAX_NEST_LEVEL (%ld) shall be increased!", HSM_MAX_NEST_LEVEL);
        HSM_ASSERT(false);
    }
}

static const sState_t *HSM_sf_GetInitialState(sState_t *const       pSMRoot,
                                              const sState_t *const pState)
{
    const sState_t *pStateIter  = (sState_t *)NULL;
    const sState_t *pFinalState = pState;

    (void) pSMRoot;

    if ((true == HSM_sf_IsStateComposite(pState)) && (HSM_DOWNCAST_COMPOSITE(pState)->pInitialState != NULL))
    {
        // oops, this is a composite state, hence drill down to its initial state (if any)
        pStateIter = HSM_DOWNCAST_COMPOSITE(pState)->pInitialState;

        // initial state is also a composite, don't quit drilling...
        while (true == HSM_sf_IsStateComposite(pStateIter))
        {
            pStateIter = HSM_DOWNCAST_COMPOSITE(pStateIter)->pInitialState;
        }

        // this would be the last leaf state in the hierarchy
        pFinalState = pStateIter;
    }

    return pFinalState;
}

inline static const char *HSM_sf_STR(const char *str, const char *ifnull_str)
{
  return ((str != NULL) ? str : ifnull_str);
}

static inline bool HSM_sf_IsStateComposite(const sState_t *const pState)
{
    return (((HSM_UPCAST_STATE(pState))->eType) == eHSM_StateType_Composite);
}

static inline void HSM_sf_TraceEntryAction(const sState_t *const pState)
{
    HSM_TRACE_DEBUG("-- entry --> %s",
                    HSM_sf_STR(((const sState_t *)(pState))->pName, CC_NONAME));
}

static inline void HSM_sf_TraceExitAction(const sState_t *const pState)
{
    HSM_TRACE_DEBUG("%s -- exit -->", HSM_sf_STR(((sState_t *)(pState))->pName, CC_NONAME));
}

static bool HSM_sf_IsInstanceValid(const uint16_t instance_id, sState_t *const pSMRoot)
{
    return (NULL != pSMRoot) && (instance_id < HSM_DOWNCAST_COMPOSITE(pSMRoot)->instanceCnt);
}
