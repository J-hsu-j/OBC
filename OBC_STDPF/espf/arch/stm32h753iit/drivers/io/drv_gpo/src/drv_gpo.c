/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup drv_gpo
 * @{
 *
 * @file     drv_gpo.c
 * @brief    Driver for controlling default values of the OBC general-purpose outputs.
 *
 * @}
 */

#include "drv_gpo.h"
#include "nvm.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

/**
 * Start of PC104 GPIO pin definitions
 */
#define OBC_OUT1_Pin         GPIO_PIN_15
#define OBC_OUT1_GPIO_Port   GPIOB
#define OBC_OUT2_Pin         GPIO_PIN_5
#define OBC_OUT2_GPIO_Port   GPIOD
#define OBC_OUT3_Pin         GPIO_PIN_4
#define OBC_OUT3_GPIO_Port   GPIOD
#define OBC_OUT5_Pin         GPIO_PIN_6
#define OBC_OUT5_GPIO_Port   GPIOG
#define OBC_OUT4_6_Pin       GPIO_PIN_0
#define OBC_OUT4_6_GPIO_Port GPIOD
#define OBC_OUT7_Pin         GPIO_PIN_5
#define OBC_OUT7_GPIO_Port   GPIOH
#define OBC_OUT8_Pin         GPIO_PIN_15
#define OBC_OUT8_GPIO_Port   GPIOH

/* @note: Please update this function in case any of the above ports changes !!! */
static void enable_gpio_port_clocks(void)
{
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
}

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

/** @brief: GPO definition */
typedef struct
{
    GPIO_TypeDef *out_port_addr;
    uint16_t      pin_mask;
    gpo_out_t     out_id; /* OBC output id */
} drv_gpo_write_handler;

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
/** @brief OBC output configuration */
static const drv_gpo_write_handler pin_cfg[OBC_OUT_MAX_COUNT] = {
    {.out_port_addr = OBC_OUT1_GPIO_Port,    .pin_mask = OBC_OUT1_Pin,   .out_id = OBC_OUT_1  },
    { .out_port_addr = OBC_OUT2_GPIO_Port,   .pin_mask = OBC_OUT2_Pin,   .out_id = OBC_OUT_2  },
    { .out_port_addr = OBC_OUT3_GPIO_Port,   .pin_mask = OBC_OUT3_Pin,   .out_id = OBC_OUT_3  },
    { .out_port_addr = OBC_OUT5_GPIO_Port,   .pin_mask = OBC_OUT5_Pin,   .out_id = OBC_OUT_5  },
    { .out_port_addr = OBC_OUT4_6_GPIO_Port, .pin_mask = OBC_OUT4_6_Pin, .out_id = OBC_OUT_4_6},
    { .out_port_addr = OBC_OUT7_GPIO_Port,   .pin_mask = OBC_OUT7_Pin,   .out_id = OBC_OUT_7  },
    { .out_port_addr = OBC_OUT8_GPIO_Port,   .pin_mask = OBC_OUT8_Pin,   .out_id = OBC_OUT_8  },
};

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
void drv_gpo_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };
    gpo_config_t     gpo_config;

    enable_gpio_port_clocks();

    /* Prepare common configuration for all ports */
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    Nvm_GetBlockById(NVM_BLOCK_GPO_CONFIG, &gpo_config);

    for (uint8_t idx = 0; idx < CDEF_ELEMENT_COUNT(pin_cfg); idx++)
    {
        GPIO_InitStruct.Pin = pin_cfg[idx].pin_mask;
        HAL_GPIO_Init(pin_cfg[idx].out_port_addr, &GPIO_InitStruct);

        if (gpo_config.pin_value[idx])
        {
            HAL_GPIO_WritePin(pin_cfg[idx].out_port_addr, pin_cfg[idx].pin_mask, GPIO_PIN_SET);
        }
        else
        {
            HAL_GPIO_WritePin(pin_cfg[idx].out_port_addr, pin_cfg[idx].pin_mask, GPIO_PIN_RESET);
        }
    }
}

/* Set all or only selected GPOs be stored in NVM as defaults or temporary runtime configured without NVM update. */
bool set_all_gpo_values(OBC_GpoPortsSetStruct_t gpo_pins_conf)
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };
    gpo_config_t     gpo_nvm_config;

    enable_gpio_port_clocks();

    /* Prepare common configuration for all ports */
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    uint8_t gpo_pins_conf_active[OBC_OUT_MAX_COUNT];
    uint8_t gpo_pins_conf_nvm[OBC_OUT_MAX_COUNT];

    Nvm_GetBlockById(NVM_BLOCK_GPO_CONFIG, &gpo_nvm_config);

    gpo_pins_conf_active[0] = gpo_pins_conf.sGpo_1.eGpo_port_active;
    gpo_pins_conf_active[1] = gpo_pins_conf.sGpo_2.eGpo_port_active;
    gpo_pins_conf_active[2] = gpo_pins_conf.sGpo_3.eGpo_port_active;
    gpo_pins_conf_active[3] = gpo_pins_conf.sGpo_5.eGpo_port_active;
    gpo_pins_conf_active[4] = gpo_pins_conf.sGpo_4_6.eGpo_port_active;
    gpo_pins_conf_active[5] = gpo_pins_conf.sGpo_7.eGpo_port_active;
    gpo_pins_conf_active[6] = gpo_pins_conf.sGpo_8.eGpo_port_active;
    gpo_pins_conf_nvm[0]    = gpo_pins_conf.sGpo_1.eGpo_port_nvm;
    gpo_pins_conf_nvm[1]    = gpo_pins_conf.sGpo_2.eGpo_port_nvm;
    gpo_pins_conf_nvm[2]    = gpo_pins_conf.sGpo_3.eGpo_port_nvm;
    gpo_pins_conf_nvm[3]    = gpo_pins_conf.sGpo_5.eGpo_port_nvm;
    gpo_pins_conf_nvm[4]    = gpo_pins_conf.sGpo_4_6.eGpo_port_nvm;
    gpo_pins_conf_nvm[5]    = gpo_pins_conf.sGpo_7.eGpo_port_nvm;
    gpo_pins_conf_nvm[6]    = gpo_pins_conf.sGpo_8.eGpo_port_nvm;

    for (uint8_t idx = 0; idx < OBC_OUT_MAX_COUNT; idx++)
    {
        GPIO_InitStruct.Pin = pin_cfg[idx].pin_mask;
        HAL_GPIO_Init(pin_cfg[idx].out_port_addr, &GPIO_InitStruct);

        /* Check for SET/RESET config value from fp command. The DONT_TOUCH is excluded as default keeping the same state of the pin. */
        if (OBC_GPOSETTYPES_SET == gpo_pins_conf_active[idx])
        {
            HAL_GPIO_WritePin(pin_cfg[idx].out_port_addr, pin_cfg[idx].pin_mask, GPIO_PIN_SET);
        }
        else if (OBC_GPOSETTYPES_RESET == gpo_pins_conf_active[idx])
        {
            HAL_GPIO_WritePin(pin_cfg[idx].out_port_addr, pin_cfg[idx].pin_mask, GPIO_PIN_RESET);
        }

        /* Check for SET/RESET NVM persist config value from fp command. The DONT_TOUCH is excluded as default keeping the same state of the pin. */
        if (OBC_GPOSETTYPES_SET == gpo_pins_conf_nvm[idx])
        {
            gpo_nvm_config.pin_value[idx] = true;
        }
        else if (OBC_GPOSETTYPES_RESET == gpo_pins_conf_nvm[idx])
        {
            gpo_nvm_config.pin_value[idx] = false;
        }
    }

    Nvm_SetBlockById(NVM_BLOCK_GPO_CONFIG, &gpo_nvm_config, NVMSETBLOCK_STORE_IMMEDIATELY);

    return true;
}

/* Get all GPOs states from both NVM(default) and current runtime(active) state. */
bool get_all_gpo_values(OBC_GpoPortsGetStruct_t *p_gpo_pins_conf)
{
    gpo_config_t gpo_nvm_config;

    Nvm_GetBlockById(NVM_BLOCK_GPO_CONFIG, &gpo_nvm_config);

    p_gpo_pins_conf->sGpo_1.bGpo_port_active   = pin_cfg[0].out_port_addr->ODR & pin_cfg[0].pin_mask;
    p_gpo_pins_conf->sGpo_2.bGpo_port_active   = pin_cfg[1].out_port_addr->ODR & pin_cfg[1].pin_mask;
    p_gpo_pins_conf->sGpo_3.bGpo_port_active   = pin_cfg[2].out_port_addr->ODR & pin_cfg[2].pin_mask;
    p_gpo_pins_conf->sGpo_5.bGpo_port_active   = pin_cfg[3].out_port_addr->ODR & pin_cfg[3].pin_mask;
    p_gpo_pins_conf->sGpo_4_6.bGpo_port_active = pin_cfg[4].out_port_addr->ODR & pin_cfg[4].pin_mask;
    p_gpo_pins_conf->sGpo_7.bGpo_port_active   = pin_cfg[5].out_port_addr->ODR & pin_cfg[5].pin_mask;
    p_gpo_pins_conf->sGpo_8.bGpo_port_active   = pin_cfg[6].out_port_addr->ODR & pin_cfg[6].pin_mask;

    p_gpo_pins_conf->sGpo_1.bGpo_port_nvm   = gpo_nvm_config.pin_value[0];
    p_gpo_pins_conf->sGpo_2.bGpo_port_nvm   = gpo_nvm_config.pin_value[1];
    p_gpo_pins_conf->sGpo_3.bGpo_port_nvm   = gpo_nvm_config.pin_value[2];
    p_gpo_pins_conf->sGpo_5.bGpo_port_nvm   = gpo_nvm_config.pin_value[3];
    p_gpo_pins_conf->sGpo_4_6.bGpo_port_nvm = gpo_nvm_config.pin_value[4];
    p_gpo_pins_conf->sGpo_7.bGpo_port_nvm   = gpo_nvm_config.pin_value[5];
    p_gpo_pins_conf->sGpo_8.bGpo_port_nvm   = gpo_nvm_config.pin_value[6];

    return true;
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
