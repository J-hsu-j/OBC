#include "test_env.h"

test_env_t env;

void test_assert(bool cond)
{
    if (!cond)
    {
        env.instance_ctx[env.test_instance_id].assert_cnt++;
    }
}

void test_trace(const char *msg, ...)
{
}

void test_env_init(void)
{
    env.test_instance_id = 0U;

    for (uint16_t inst_id = 0; inst_id < TEST_SM_INSTANCE_CNT; inst_id++)
    {
        env.instance_ctx[inst_id].on_entry_Initial_cnt                      = 0U;
        env.instance_ctx[inst_id].on_entry_Initial_instance_id              = TEST_SM_INSTANCE_CNT;
        env.instance_ctx[inst_id].on_exit_Initial_instance_id               = TEST_SM_INSTANCE_CNT;
        env.instance_ctx[inst_id].on_guard_start_conditions_met_instance_id = TEST_SM_INSTANCE_CNT;
        env.instance_ctx[inst_id].on_action_start_instance_id               = TEST_SM_INSTANCE_CNT;
        env.instance_ctx[inst_id].on_entry_Initial_Composite_cnt            = 0U;
        env.instance_ctx[inst_id].on_exit_Initial_Composite_cnt             = 0U;
        env.instance_ctx[inst_id].on_exit_Initial_cnt                       = 0U;
        env.instance_ctx[inst_id].guard_start_conditions_met                = false;
        env.instance_ctx[inst_id].on_start_action_cnt                       = 0U;
        env.instance_ctx[inst_id].guard_entry_to_sub2_allowed               = false;
        env.instance_ctx[inst_id].on_entry_composite_cnt                    = 0U;
        env.instance_ctx[inst_id].on_exit_composite_cnt                     = 0U;
        env.instance_ctx[inst_id].on_entry_composite_sub1_cnt               = 0U;
        env.instance_ctx[inst_id].on_exit_composite_sub1_cnt                = 0U;
        env.instance_ctx[inst_id].on_entry_composite_sub2_cnt               = 0U;
        env.instance_ctx[inst_id].on_exit_composite_sub2_cnt                = 0U;
        env.instance_ctx[inst_id].on_entry_deep_sub3_cnt                    = 0U;
        env.instance_ctx[inst_id].on_exit_deep_sub3_cnt                     = 0U;
        env.instance_ctx[inst_id].on_entry_composite_sub3_cnt               = 0U;
        env.instance_ctx[inst_id].on_exit_composite_sub3_cnt                = 0U;
        env.instance_ctx[inst_id].assert_cnt                                = 0U;
        env.instance_ctx[inst_id].on_regular_safe_action_cnt                = 0U;
        env.instance_ctx[inst_id].on_safe_action_cnt                        = 0U;
        env.instance_ctx[inst_id].on_top_level_action_cnt                   = 0U;
        env.instance_ctx[inst_id].on_top_level_action1_cnt                  = 0U;
    }
}
