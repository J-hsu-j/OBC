/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @file test.c
 * @brief libhsm unit test using unity framework
 */

#include <stdio.h>
#include "unity.h"
#include "test_sm_user.h"
#include "test_env.h"

TEST_FILE("test.c")

#define HSM_TRIGGER_EVENT(ev)  HSM_TriggerEventForInstance(env.test_instance_id, Test_SM_instance, (ev))
#define HSM_GET_ACTIVE_STATE() HSM_GetActiveStateForInstance(env.test_instance_id, Test_SM_instance)

static void trace(const char *msg, ...)
{
}

void setUp(void)
{
    test_env_init();

    // Reset the Initial state to avoid wrong exit actions invocation based on the last state from a previous test case.
    // NOTE:
    // Triggering the eHSM_StdEvent_Reset takes care to execute all necessary exit actions in order to reach the initial state but
    // it takes this action based on the currently active state which will differ every time a test case is finished. That is
    // why we reset the active state here to avoid differences in initial condition tests based on the order of the execution of the
    // test cases.
    for (uint16_t instance_id = 0; instance_id < HSM_DOWNCAST_COMPOSITE(Test_SM_instance)->instanceCnt; instance_id++)
    {
        (HSM_DOWNCAST_COMPOSITE(Test_SM_instance)->ppActiveState)[instance_id] = HSM_UPCAST_STATE(&state_Test_SM);
    }
}

void tearDown(void)
{
}

static void check_state(const char *p_state_name)
{
    const sState_t *p_active_state = HSM_GET_ACTIVE_STATE();

    TEST_ASSERT_MESSAGE(NULL != p_active_state, "Active state is NULL");

    if (NULL != p_active_state)
    {
        TEST_ASSERT_EQUAL_STRING_MESSAGE(p_state_name, p_active_state->pName, "Unexpected state entered");
    }
}

static void test_unhandled_invalid_events(void)
{
    TEST_MESSAGE("Test if an invalid event triggers an error");

    bool res = HSM_TRIGGER_EVENT(0xFFFF);
    TEST_ASSERT(false == res);
}

static void test_trans_inital(void)
{
    TEST_MESSAGE("Testing transition to initial state when a reset event is sent to SM");

    bool ev_res = HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

    TEST_ASSERT_MESSAGE(true == ev_res, "Reset event could not be handled");
    check_state("state_Initial");
    TEST_ASSERT_MESSAGE(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_Initial_Composite_cnt), "OnEntry for Initial_Composite state not called or called more than once on reset");
    TEST_ASSERT_MESSAGE(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_Initial_cnt), "OnEntry for Initial state not called or called more than once on reset");
    TEST_ASSERT_MESSAGE(0U == HSM_GET_TEST_INSTANCE_VAR(on_exit_Initial_Composite_cnt), "OnExit for Initial_Composite state called on reset when it shouldn't be");
    TEST_ASSERT_MESSAGE(0U == HSM_GET_TEST_INSTANCE_VAR(on_exit_Initial_cnt), "OnEntry for Initial state called on reset when it shouldn't be");

    TEST_MESSAGE("Testing subsequent reset after the first one to check whether all exit actions for inner states will be called accordingly");
    HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

    check_state("state_Initial");
    TEST_ASSERT_MESSAGE(2U == HSM_GET_TEST_INSTANCE_VAR(on_entry_Initial_Composite_cnt), "OnEntry for Initial_Composite state not called on second reset");
    TEST_ASSERT_MESSAGE(2U == HSM_GET_TEST_INSTANCE_VAR(on_entry_Initial_cnt), "OnEntry for Initial state not called on second reset");
    TEST_ASSERT_MESSAGE(1U == HSM_GET_TEST_INSTANCE_VAR(on_exit_Initial_Composite_cnt), "OnExit for Initial_Composite state not called on second reset when it should be");
    TEST_ASSERT_MESSAGE(1U == HSM_GET_TEST_INSTANCE_VAR(on_exit_Initial_cnt), "OnEntry for Initial state not called on second reset when it should be");
}

static void test_on_entry_action(void)
{
    TEST_MESSAGE("Testing whether state onEntry function gets executed upon successful transition");

    // ensure we start from the initial state...
    HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

    TEST_ASSERT_MESSAGE(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_Initial_cnt), "OnEntry for Initial state not called or called more than once");
}

static void test_on_exit_action(void)
{
    TEST_MESSAGE("Testing whether state onExit function gets executed upon successful transition");

    // ensure we start from the initial state...
    HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

    // switch over to Composite state
    HSM_GET_TEST_INSTANCE_VAR(guard_start_conditions_met) = true;
    HSM_TRIGGER_EVENT(ev_Test_SM_start);

    check_state("state_Composite_Sub1");

    TEST_ASSERT_MESSAGE(1U == HSM_GET_TEST_INSTANCE_VAR(on_start_action_cnt), "Action function not called or called more than once");
}

static void test_transition_same_level(void)
{
    TEST_MESSAGE("Testing whether state transitions at the same hierarchy level are correctly executed");

    // ensure we start from the initial state...
    HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

    HSM_TRIGGER_EVENT(ev_Test_SM_switch_to_idle);

    check_state("state_Idle");
}

static void test_transition_substate(void)
{
    TEST_MESSAGE("Testing whether state transitions to composite substates are performed correctly");

    // ensure we start from the initial state...
    HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

    // switch over to Composite state
    HSM_GET_TEST_INSTANCE_VAR(guard_start_conditions_met) = true;
    HSM_TRIGGER_EVENT(ev_Test_SM_start);

    check_state("state_Composite_Sub1");
}

static void test_transition_higherlevel(void)
{
    TEST_MESSAGE("Testing whether state transitions to to higher levels in the hieararchy are performed correctly");

    // ensure we start from the initial state...
    HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

    // switch over to Composite_Sub2
    HSM_TRIGGER_EVENT(ev_Test_SM_go_sub2);
    check_state("state_Composite_Sub2");

    // now try to go back to Initial state which is at a higher level in the state hierarchy...
    HSM_TRIGGER_EVENT(ev_Test_SM_go_to_initial);
    check_state("state_Initial");
}

static void test_history_transition(void)
{
    TEST_MESSAGE("Check whether transitions to composite history states are performed correctly");

    // ensure we start from the initial state...
    HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

    check_state("state_Initial");

    // switch over to Composite state to update history state explicitly
    HSM_GET_TEST_INSTANCE_VAR(guard_start_conditions_met) = true;
    HSM_TRIGGER_EVENT(ev_Test_SM_start);
    check_state("state_Composite_Sub1");

    HSM_GET_TEST_INSTANCE_VAR(guard_entry_to_sub2_allowed) = true;
    HSM_TRIGGER_EVENT(eHSM_StdEvent_Periodic);
    check_state("state_Composite_Sub2");

    // exit composite state and...
    HSM_TRIGGER_EVENT(ev_Test_SM_go_to_initial);
    check_state("state_Initial");

    // ...return to history state which should be state_Composite_Sub2
    HSM_TRIGGER_EVENT(ev_Test_SM_go_composite_history);
    check_state("state_Composite_Sub2");
}

static void test_transition_action(void)
{
    TEST_MESSAGE("Check whether transition action functions get called");

    for (uint16_t i = 0; i < 20U; i++)
    {
        TEST_ASSERT_MESSAGE(i == HSM_GET_TEST_INSTANCE_VAR(on_start_action_cnt), "Transition action function not called as expected");

        HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

        check_state("state_Initial");

        HSM_GET_TEST_INSTANCE_VAR(guard_start_conditions_met) = true;
        HSM_TRIGGER_EVENT(ev_Test_SM_start);

        HSM_TRIGGER_EVENT(ev_Test_SM_go_to_initial);
    }
}

static void test_transition_guards(void)
{
    TEST_MESSAGE("Check whether transition guard functions get called and are evaluated when deciding on a transition");

    for (uint16_t i = 0; i < 20U; i++)
    {
        TEST_ASSERT_MESSAGE(i == HSM_GET_TEST_INSTANCE_VAR(on_start_action_cnt), "Transition action function not called as expected");

        HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

        check_state("state_Initial");

        HSM_GET_TEST_INSTANCE_VAR(guard_start_conditions_met) = false;
        HSM_TRIGGER_EVENT(ev_Test_SM_start);

        // state remained the same because guard condition was not met
        check_state("state_Initial");

        // try again... this time with enabled guard condition...
        HSM_GET_TEST_INSTANCE_VAR(guard_start_conditions_met) = true;
        HSM_TRIGGER_EVENT(ev_Test_SM_start);

        // state shall now be changed to the initial substate of the Composite state
        check_state("state_Composite_Sub1");
    }
}

static void test_unhandled_valid_events(void)
{
    TEST_MESSAGE("Check that unhandled events do not change state");

    bool res = HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

    check_state("state_Initial");
    TEST_ASSERT_MESSAGE(true == res, "Reset event not handled by the hsm lib");

    for (uint16_t i = 0; i < 20U; i++)
    {
        // periodic event is not supported in this state so we do not expect a state change
        res = HSM_TRIGGER_EVENT(eHSM_StdEvent_Periodic);

        check_state("state_Initial");
        TEST_ASSERT_MESSAGE(false == res, "Periodic event should not be supported in the Initial state");

        res = HSM_TRIGGER_EVENT(ev_Test_SM_go_sub2);
        check_state("state_Composite_Sub2");
        TEST_ASSERT_MESSAGE(true == res, "go_sub2 event should be supported in the Initial state");

        // periodic event is not supported in this state so we do not expect a state change
        res = HSM_TRIGGER_EVENT(eHSM_StdEvent_Periodic);

        check_state("state_Composite_Sub2");
        TEST_ASSERT_MESSAGE(false == res, "Periodic event should not be supported in the Composite_Sub2 state");

        res = HSM_TRIGGER_EVENT(ev_Test_SM_go_to_initial);
        TEST_ASSERT_MESSAGE(true == res, "go_to_initial event should be supported in the Composite_Sub2 state");
    }
}

static void test_composite_on_entry_exit(void)
{
    TEST_MESSAGE("Check whether onEntry/onExit actions are called on parent composite states when a substate is transitioned to");

    bool res = HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);
    TEST_ASSERT(true == res);

    // enter a substate of Composite state
    res = HSM_TRIGGER_EVENT(ev_Test_SM_go_sub2);
    check_state("state_Composite_Sub2");
    TEST_ASSERT_MESSAGE(true == res, "go_sub2 event should be supported in the Initial state");

    // check if both parent and substate on_entry function was called
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_composite_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_composite_sub2_cnt));

    res = HSM_TRIGGER_EVENT(ev_Test_SM_go_to_initial);
    check_state("state_Initial");

    // check if both parent and substate on_exit function was called
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_exit_composite_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_exit_composite_sub2_cnt));
}

static void test_composite_on_entry_exit_samelevel(void)
{
    TEST_MESSAGE("Check whether onEntry/onExit actions are called only on composite substates if transition is internal to the composite state");

    bool res = HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);
    TEST_ASSERT(true == res);

    check_state("state_Initial");

    // switch over to Composite state
    HSM_GET_TEST_INSTANCE_VAR(guard_start_conditions_met) = true;
    HSM_TRIGGER_EVENT(ev_Test_SM_start);

    check_state("state_Composite_Sub1");

    // check if both parent and substate on_entry function was called
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_composite_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_composite_sub1_cnt));

    // enter another substate in the same Composite state
    HSM_GET_TEST_INSTANCE_VAR(guard_entry_to_sub2_allowed) = true;
    res                                                    = HSM_TRIGGER_EVENT(eHSM_StdEvent_Periodic);
    check_state("state_Composite_Sub2");
    TEST_ASSERT(true == res);

    // check if Composite on_entry was not called (e.g. remained the same) and only
    // new substate on_entry was called
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_composite_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_composite_sub1_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_composite_sub2_cnt));
}

static void test_hierarchical_event_handling(void)
{
    TEST_MESSAGE("Check whether transitions from substates to outside their parent state are possible if a transition is specified for the parent state only");

    bool res = HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);
    TEST_ASSERT(true == res);

    check_state("state_Initial");

    HSM_TRIGGER_EVENT(ev_Test_SM_go_sub3);

    check_state("state_Deep_Sub3");

    TEST_ASSERT(0U == HSM_GET_TEST_INSTANCE_VAR(on_exit_deep_sub3_cnt));
    TEST_ASSERT(0U == HSM_GET_TEST_INSTANCE_VAR(on_exit_composite_sub3_cnt));

    // go_sub2 event is not supported by the Deep_Sub3 state but is supported by its parent
    // Composite_Sub3 and shall trigger a transition Composite_Sub2
    HSM_TRIGGER_EVENT(ev_Test_SM_go_to_sub2_direct);

    check_state("state_Composite_Sub2");
    // check if on_exit functions in the hieararchy get called
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_exit_deep_sub3_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_exit_composite_sub3_cnt));
}

static void test_on_entry_exit_for_self_transition(void)
{
    TEST_MESSAGE("Testing whether state onEntry/onExit functions do not get executed upon successful transition to the same state via a 'self' transition");

    // ensure we start from the initial state...
    HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

    check_state("state_Initial");

    uint16_t on_entry_prev = HSM_GET_TEST_INSTANCE_VAR(on_entry_Initial_cnt);
    uint16_t on_exit_prev  = HSM_GET_TEST_INSTANCE_VAR(on_exit_Initial_cnt);

    HSM_TRIGGER_EVENT(ev_Test_SM_trigger_self_trans);

    // the entry/exit count shall remain unchanged after triggering a transition to self
    TEST_ASSERT(on_entry_prev == HSM_GET_TEST_INSTANCE_VAR(on_entry_Initial_cnt));
    TEST_ASSERT(on_exit_prev == HSM_GET_TEST_INSTANCE_VAR(on_exit_Initial_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_safe_action_cnt));
}

static void test_on_entry_exit_same_state_transitions(void)
{
    TEST_MESSAGE("Testing whether state onEntry/onExit functions get executed upon successful transition to the same state (not a 'self' transition)");

    // ensure we start from the initial state...
    HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

    check_state("state_Initial");

    uint16_t on_entry_prev = HSM_GET_TEST_INSTANCE_VAR(on_entry_Initial_cnt);
    uint16_t on_exit_prev  = HSM_GET_TEST_INSTANCE_VAR(on_exit_Initial_cnt);

    HSM_TRIGGER_EVENT(ev_Test_SM_trigger_regular_self_trans);

    // the entry/exit count shall remain unchanged after triggering a transition to self
    TEST_ASSERT((on_entry_prev + 1U) == HSM_GET_TEST_INSTANCE_VAR(on_entry_Initial_cnt));
    TEST_ASSERT((on_exit_prev + 1U) == HSM_GET_TEST_INSTANCE_VAR(on_exit_Initial_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_regular_safe_action_cnt));
}

static void test_on_exit_calls_for_more_than_1_nesting_levels(void)
{
    TEST_MESSAGE("DH-46: Exit actions not properly called for HSMs with more than 1 nesting level");

    // ensure we start from the initial state...
    HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

    check_state("state_Initial");

    TEST_ASSERT(0U == HSM_GET_TEST_INSTANCE_VAR(on_exit_composite_cnt));

    HSM_TRIGGER_EVENT(ev_Test_SM_go_sub3);

    check_state("state_Deep_Sub3");

    TEST_ASSERT(0U == HSM_GET_TEST_INSTANCE_VAR(on_exit_composite_cnt));

    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_composite_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_composite_sub3_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_deep_sub3_cnt));

    HSM_TRIGGER_EVENT(ev_Test_SM_go_to_sub2_direct);

    check_state("state_Composite_Sub2");

    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_exit_composite_sub3_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_exit_deep_sub3_cnt));

    // this is actually the issue found in the defect => the exit handler for the parent state of the target state gets called when it shouldn't
    TEST_ASSERT(0U == HSM_GET_TEST_INSTANCE_VAR(on_exit_composite_cnt));
}

static void test_on_top_level_history_action(void)
{
    TEST_MESSAGE("SPE-1112: Composite states: Not correct behaviour when going from parent state into __history state of the same parent state");

    // ensure we start from the initial state...
    HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

    check_state("state_Initial");

    TEST_ASSERT(0U == HSM_GET_TEST_INSTANCE_VAR(on_exit_composite_cnt));

    HSM_TRIGGER_EVENT(ev_Test_SM_go_sub3);

    check_state("state_Deep_Sub3");

    TEST_ASSERT(0U == HSM_GET_TEST_INSTANCE_VAR(on_top_level_action_cnt));

    // trigger top level event which is handled two states above in the state hierarchy (@ Composite state)...
    HSM_TRIGGER_EVENT(ev_Test_SM_exec_top_level_action);

    // ...the expectations are:
    // - the event is not handled in the currently active Deep_Sub3 state and will be propagated to parent states
    // - there is no guard configured which implies an unconditional action execution
    // - since this is a transition from a parent state to its own history state - no internal entry/exit actions are executed
    // - the action gets executed once and the SM state remains unchanged @ Deep_Sub3

    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_top_level_action_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_deep_sub3_cnt));
    TEST_ASSERT(0U == HSM_GET_TEST_INSTANCE_VAR(on_exit_deep_sub3_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_composite_sub3_cnt));
    TEST_ASSERT(0U == HSM_GET_TEST_INSTANCE_VAR(on_exit_composite_sub3_cnt));

    check_state("state_Deep_Sub3");

    // this is actually the issue found in the defect => the exit handler for the parent state of the target state gets called when it shouldn't
    TEST_ASSERT(0U == HSM_GET_TEST_INSTANCE_VAR(on_exit_composite_cnt));
}

static void test_invalid_instance(void)
{
    TEST_MESSAGE("Testing whether a reset event is possible to be sent to an invalid instance of the SM");

    HSM_SET_ACTIVE_TEST_INSTANCE(HSM_DOWNCAST_COMPOSITE(Test_SM_instance)->instanceCnt);

    bool ev_res = HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

    TEST_ASSERT(false == ev_res);
}

static void test_multi_instance_crossover(void)
{
    TEST_MESSAGE("Testing if multiple instances working together influence each other in some way");

    HSM_SET_ACTIVE_TEST_INSTANCE(0);

    bool ev_res = HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

    TEST_ASSERT(true == ev_res);

    check_state("state_Initial");

    TEST_ASSERT(0U == HSM_GET_TEST_INSTANCE_VAR(on_exit_composite_cnt));

    HSM_TRIGGER_EVENT(ev_Test_SM_go_sub3);

    check_state("state_Deep_Sub3");

    TEST_ASSERT(0U == HSM_GET_TEST_INSTANCE_VAR(on_exit_composite_cnt));

    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_composite_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_composite_sub3_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_deep_sub3_cnt));

    // switch to the second instance and push some events...
    HSM_SET_ACTIVE_TEST_INSTANCE(1);

    ev_res = HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

    check_state("state_Initial");

    // switch over to Composite state
    HSM_GET_TEST_INSTANCE_VAR(guard_start_conditions_met) = true;
    HSM_TRIGGER_EVENT(ev_Test_SM_start);

    check_state("state_Composite_Sub1");

    // check if both parent and substate on_entry function was called
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_composite_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_composite_sub1_cnt));

    // enter another substate in the same Composite state
    HSM_GET_TEST_INSTANCE_VAR(guard_entry_to_sub2_allowed) = true;
    ev_res                                                 = HSM_TRIGGER_EVENT(eHSM_StdEvent_Periodic);
    check_state("state_Composite_Sub2");
    TEST_ASSERT(true == ev_res);

    // check if Composite on_entry was not called (e.g. remained the same) and only
    // new substate on_entry was called
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_composite_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_composite_sub1_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_composite_sub2_cnt));

    // go back to previous instance and check if last state was modified after stimulating the second SM instance
    HSM_SET_ACTIVE_TEST_INSTANCE(0);

    check_state("state_Deep_Sub3");

    TEST_ASSERT(0U == HSM_GET_TEST_INSTANCE_VAR(on_exit_composite_cnt));

    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_composite_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_composite_sub3_cnt));
    TEST_ASSERT(1U == HSM_GET_TEST_INSTANCE_VAR(on_entry_deep_sub3_cnt));
}

static void test_instance_reporting(void)
{
    TEST_MESSAGE("Test whether the correct SM instance ID is passed to entry/exit/guard and action SM functions");

    for (uint8_t inst_id = 0; inst_id < TEST_SM_INSTANCE_CNT; inst_id++)
    {
        HSM_SET_ACTIVE_TEST_INSTANCE(inst_id);

        // set instance id to an invalid value and expect that it will be changed after...
        HSM_GET_TEST_INSTANCE_VAR(on_entry_Initial_instance_id)              = TEST_SM_INSTANCE_CNT;
        HSM_GET_TEST_INSTANCE_VAR(on_exit_Initial_instance_id)               = TEST_SM_INSTANCE_CNT;
        HSM_GET_TEST_INSTANCE_VAR(on_guard_start_conditions_met_instance_id) = TEST_SM_INSTANCE_CNT;
        HSM_GET_TEST_INSTANCE_VAR(on_action_start_instance_id)               = TEST_SM_INSTANCE_CNT;

        // ensure we start from the initial state...
        HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

        check_state("state_Initial");

        // switch over to Composite state
        HSM_GET_TEST_INSTANCE_VAR(guard_start_conditions_met) = true;
        HSM_TRIGGER_EVENT(ev_Test_SM_start);

        check_state("state_Composite_Sub1");

        // check if the instance was correctly passed to all of the called SM hooks
        TEST_ASSERT(HSM_GET_TEST_INSTANCE_VAR(on_entry_Initial_instance_id) == HSM_GET_ACTIVE_TEST_INSTANCE());
        TEST_ASSERT(HSM_GET_TEST_INSTANCE_VAR(on_exit_Initial_instance_id) == HSM_GET_ACTIVE_TEST_INSTANCE());
        TEST_ASSERT(HSM_GET_TEST_INSTANCE_VAR(on_guard_start_conditions_met_instance_id) == HSM_GET_ACTIVE_TEST_INSTANCE());
        TEST_ASSERT(HSM_GET_TEST_INSTANCE_VAR(on_action_start_instance_id) == HSM_GET_ACTIVE_TEST_INSTANCE());
    }
}

static void test_multi_history_transition(void)
{
    TEST_MESSAGE("Check whether transitions to history states are performed correctly when there are multiple transitions to the same history state");

    // ensure we start from the initial state...
    HSM_TRIGGER_EVENT(eHSM_StdEvent_Reset);

    check_state("state_Initial");

    // switch over to Composite state
    HSM_GET_TEST_INSTANCE_VAR(guard_start_conditions_met) = true;
    HSM_TRIGGER_EVENT(ev_Test_SM_start);

    check_state("state_Composite_Sub1");

    // trigger first transition to Composite History state
    HSM_TRIGGER_EVENT(ev_Test_SM_exec_top_level_action);

    TEST_ASSERT(HSM_GET_TEST_INSTANCE_VAR(on_top_level_action_cnt) == 1);

    check_state("state_Composite_Sub1");

    HSM_GET_TEST_INSTANCE_VAR(on_top_level_action_cnt) = 0;

    // trigger second transition to Composite History state
    HSM_TRIGGER_EVENT(ev_Test_SM_exec_top_level_action1);

    TEST_ASSERT(HSM_GET_TEST_INSTANCE_VAR(on_top_level_action1_cnt) == 1);

    check_state("state_Composite_Sub1");
}

int main()
{
    UNITY_BEGIN();

    // execute the test suite for all configured instances
    for (uint16_t instance_id = 0; instance_id < HSM_DOWNCAST_COMPOSITE(Test_SM_instance)->instanceCnt; instance_id++)
    {
        HSM_SET_ACTIVE_TEST_INSTANCE(instance_id);

        RUN_TEST(test_unhandled_invalid_events);
        RUN_TEST(test_trans_inital);
        RUN_TEST(test_on_entry_action);
        RUN_TEST(test_on_exit_action);
        RUN_TEST(test_transition_same_level);
        RUN_TEST(test_transition_substate);
        RUN_TEST(test_transition_higherlevel);
        RUN_TEST(test_history_transition);
        RUN_TEST(test_transition_action);
        RUN_TEST(test_transition_guards);
        RUN_TEST(test_unhandled_valid_events);
        RUN_TEST(test_composite_on_entry_exit);
        RUN_TEST(test_composite_on_entry_exit_samelevel);
        RUN_TEST(test_hierarchical_event_handling);
        RUN_TEST(test_on_entry_exit_for_self_transition);
        RUN_TEST(test_on_entry_exit_same_state_transitions);
        RUN_TEST(test_on_exit_calls_for_more_than_1_nesting_levels);
        RUN_TEST(test_on_top_level_history_action);
        RUN_TEST(test_invalid_instance);
        RUN_TEST(test_multi_instance_crossover);
        RUN_TEST(test_instance_reporting);
        RUN_TEST(test_multi_history_transition);
    }

    return UNITY_END();
}
