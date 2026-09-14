/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef EPS_III_CFG_H_
#define EPS_III_CFG_H_

/**
 *
 * @addtogroup eps_iii
 * @{
 *
 * @file eps_iii_cfg.h
 * @brief Main configuration file for EPS III.
 *
 * @}
 */

#include "fp/nvm_eps/v0.1/nvm_eps_server/FP_nvm_epsProtocolTypes.h"

#include "if_tlm_dev.h"
#include "if_eps_ctrl.h"

#include "eps_iii_bp_cfg.h"
#include "eps_iii_pdm_a_cfg.h"
#include "eps_iii_pdm_b_cfg.h"
#include "eps_iii_expander_cfg.h"
#include "eps_iii_input_stage_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/

/*
 * PDM count taken from NVM_EPS fidl file based on generated file from the configuration
 */
#define PDM_COUNT (NVM_EPS_EPSIIIPDMAIDTYPE_MAX_CNT + NVM_EPS_EPSIIIPDMBIDTYPE_MAX_CNT + NVM_EPS_EPSIIIEXPANDERIDTYPE_MAX_CNT)

#define TLM_DEV_CNT ((uint8_t)(NVM_EPS_EPSIIIINPUTSTAGEIDTYPE_MAX_CNT + NVM_EPS_EPSIIIBPIDTYPE_MAX_CNT + PDM_COUNT))

#define EPS_DEV_CNT           (TLM_DEV_CNT)
#define EPS_III_TLM_DEV_COUNT (EPS_III_DEV_COUNT)

// clang-format off
#define EPS_III_CHANNEL_MAPPING_CFG                                                                                          \
        { eps_iii_ch1, eps_ctrl_devices[EPS_III_PDM_A_CTRL_INST0], EPS_III_PDM_A_CHANNEL_3V3 },                              \
        { eps_iii_ch2, eps_ctrl_devices[EPS_III_PDM_A_CTRL_INST0], EPS_III_PDM_A_CHANNEL_5V },                               \
        { eps_iii_ch3, eps_ctrl_devices[EPS_III_PDM_A_CTRL_INST0], EPS_III_PDM_A_CHANNEL_12V },                              \
        { eps_iii_ch4, eps_ctrl_devices[EPS_III_PDM_A_CTRL_INST0], EPS_III_PDM_A_GPIO_EXT_SYS_BUS },                         \
        { eps_iii_ch5, eps_ctrl_devices[EPS_III_PDM_B_CTRL_INST0], EPS_III_PDM_B_CHANNEL_A },                                \
        { eps_iii_ch6, eps_ctrl_devices[EPS_III_PDM_B_CTRL_INST0], EPS_III_PDM_B_CHANNEL_B },                                \
        { eps_iii_ch7, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_LV_H1_47_48 },                \
        { eps_iii_ch8, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_HV_H1_47_48 },                \
        { eps_iii_ch9, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_LV_H1_49_50 },                \
        { eps_iii_ch10, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_HV_H1_49_50 },               \
        { eps_iii_ch11, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_LV_H1_51_52 },               \
        { eps_iii_ch12, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_HV_H1_51_52 },               \
        { eps_iii_ch13, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_GPIO_1 },                    \
        { eps_iii_ch14, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_GPIO_2 },                    \
        { eps_iii_ch15, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_GPIO_3 },                    \
        { eps_iii_ch16, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_GPIO_4 },                    \
        { eps_iii_ch17, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_GPIO_5 },                    \
        { eps_iii_ch18, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_GPIO_6 },                    \
        { eps_iii_ch19, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_GPIO_7 },                    \
        { eps_iii_ch20, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_GPIO_8 },                    \
        { eps_iii_ch21, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_INTERCONNECT_3V3 },          \
        { eps_iii_ch22, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_INTERCONNECT_5V },           \
        { eps_iii_ch23, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_INTERCONNECT_12V },          \
        { eps_iii_ch24, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_INTERCONNECT_BATTERY },      \
        { eps_iii_ch25, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_1_5V },    \
        { eps_iii_ch26, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_2_5V },    \
        { eps_iii_ch27, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_3_5V },    \
        { eps_iii_ch28, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_4_5V },    \
        { eps_iii_ch29, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_1_A },     \
        { eps_iii_ch30, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_1_B },     \
        { eps_iii_ch31, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_2_A },     \
        { eps_iii_ch32, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_2_B },     \
        { eps_iii_ch33, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_3_A },     \
        { eps_iii_ch34, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_3_B },     \
        { eps_iii_ch35, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_4_A },     \
        { eps_iii_ch36, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_RELEASE_CONNECTOR_4_B },     \
        { eps_iii_ch37, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_1_Fb1 },\
        { eps_iii_ch38, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_1_Fb2 },\
        { eps_iii_ch39, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_2_Fb1 },\
        { eps_iii_ch40, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_2_Fb2 },\
        { eps_iii_ch41, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_3_Fb1 },\
        { eps_iii_ch42, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_3_Fb2 },\
        { eps_iii_ch43, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_4_Fb1 },\
        { eps_iii_ch44, eps_ctrl_devices[EPS_III_EXPANDER_CTRL_INST0], EPS_III_EXPANDER_CHANNEL_IN_RELEASE_CONNECTOR_4_Fb2 }

// clang-format on

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/
typedef enum
{
    eps_iii_ch1,
    eps_iii_ch2,
    eps_iii_ch3,
    eps_iii_ch4,
    eps_iii_ch5,
    eps_iii_ch6,
    eps_iii_ch7,
    eps_iii_ch8,
    eps_iii_ch9,
    eps_iii_ch10,
    eps_iii_ch11,
    eps_iii_ch12,
    eps_iii_ch13,
    eps_iii_ch14,
    eps_iii_ch15,
    eps_iii_ch16,
    eps_iii_ch17,
    eps_iii_ch18,
    eps_iii_ch19,
    eps_iii_ch20,
    eps_iii_ch21,
    eps_iii_ch22,
    eps_iii_ch23,
    eps_iii_ch24,
    eps_iii_ch25,
    eps_iii_ch26,
    eps_iii_ch27,
    eps_iii_ch28,
    eps_iii_ch29,
    eps_iii_ch30,
    eps_iii_ch31,
    eps_iii_ch32,
    eps_iii_ch33,
    eps_iii_ch34,
    eps_iii_ch35,
    eps_iii_ch36,
    eps_iii_ch37,
    eps_iii_ch38,
    eps_iii_ch39,
    eps_iii_ch40,
    eps_iii_ch41,
    eps_iii_ch42,
    eps_iii_ch43,
    eps_iii_ch44,
    eps_iii_CTRL_MAX
} eps_iii_ctrl_ch_t;

typedef enum
{
    EPS_III_PDM_A_CTRL_INST_CFG,
    EPS_III_PDM_B_CTRL_INST_CFG,
    EPS_III_EXPANDER_CTRL_INST_CFG,
    EPS_III_CTRL_DEV_INST_CNT
} eps_iii_ctl_dev_id_t;

typedef enum
{
    EPS_III_DEV_BP_INST_CFG,
    EPS_III_DEV_PDM_A_INST_CFG,
    EPS_III_DEV_PDM_B_INST_CFG,
    EPS_III_DEV_EXPANDER_INST_CFG,
    EPS_III_DEV_INPUT_STAGE_INST_CFG,
    EPS_III_DEV_COUNT
} eps_iii_dev_id_t;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/
extern const if_tlm_t *const      tlm_dev[EPS_III_TLM_DEV_COUNT];
extern const if_eps_ctrl_t *const eps_ctrl_devices[EPS_III_CTRL_DEV_INST_CNT];

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

#ifdef __cplusplus
}
#endif

#endif /* EPS_III_CFG_H_ */
