#ifndef TEST_ENV_H
#define TEST_ENV_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "test_sm_user.h"

typedef struct
{
    uint16_t on_entry_Initial_cnt;
    uint16_t on_entry_Initial_instance_id;
    uint16_t on_entry_Initial_Composite_cnt;
    uint16_t on_exit_Initial_Composite_cnt;
    uint16_t on_exit_Initial_cnt;
    uint16_t on_exit_Initial_instance_id;
    bool     guard_start_conditions_met;
    bool     guard_entry_to_sub2_allowed;
    uint16_t on_start_action_cnt;
    uint16_t on_entry_composite_cnt;
    uint16_t on_exit_composite_cnt;
    uint16_t on_entry_composite_sub1_cnt;
    uint16_t on_exit_composite_sub1_cnt;
    uint16_t on_entry_composite_sub2_cnt;
    uint16_t on_exit_composite_sub2_cnt;
    uint16_t on_entry_deep_sub3_cnt;
    uint16_t on_exit_deep_sub3_cnt;
    uint16_t on_entry_composite_sub3_cnt;
    uint16_t on_exit_composite_sub3_cnt;
    uint16_t on_safe_action_cnt;
    uint16_t on_regular_safe_action_cnt;
    uint16_t on_top_level_action_cnt;
    uint16_t on_top_level_action1_cnt;
    uint16_t assert_cnt;
    uint16_t on_guard_start_conditions_met_instance_id;
    uint16_t on_action_start_instance_id;
} test_env_sm_instance_runtime_t;

typedef struct
{
    uint16_t                       test_instance_id;
    test_env_sm_instance_runtime_t instance_ctx[TEST_SM_INSTANCE_CNT]; // runtime context for each instance
} test_env_t;

extern test_env_t env;

#define HSM_GET_TEST_INSTANCE_VAR(varname) env.instance_ctx[env.test_instance_id].varname
#define HSM_SET_ACTIVE_TEST_INSTANCE(inst_id) \
    do                                        \
    {                                         \
        env.test_instance_id = (inst_id);     \
    } while (false);
#define HSM_GET_ACTIVE_TEST_INSTANCE()  (env.test_instance_id)

#ifdef __cplusplus
};
#endif

void test_env_init(void);

#endif // #ifndef TEST_ENV_H
