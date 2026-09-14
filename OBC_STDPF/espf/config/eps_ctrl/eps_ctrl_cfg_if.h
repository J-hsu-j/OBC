/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef EPS_CTRL_IF_CFG_H
#define EPS_CTRL_IF_CFG_H

/**
 * @addtogroup eps_ctrl
 * @{
 *
 * This file is used to configure the EPS Control service based on the attached hardware.
 * It should be the sole location for configuring mission-dependent settings.
 *
 * @file eps_ctrl_cfg_if.h
 * @brief File used to modify interfaces of EPS controller service to match the HW installed.
 *
 * @}
 */

#include "es_cdef.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
/**
 * @def EPS_CTRL_CHANNEL_IDS
 * @brief Enumerator specific to each mission, ensuring EPS_CONTROL service uses intuitive channel names.
 *
 * This enumerator matches the real channels available in a specific mission, simplifying the use of the EPS_CONTROL service.
 * By aligning the enumerator names with the actual hardware, clients do not need to check specific mappings.
 *
 * @note The current configuration is designed for platform hardware, mapping all available channels. Consequently, the channel names
 * may not be very intuitive, as they represent all possible channels for testing purposes.
 */
#define EPS_CTRL_CHANNEL_IDS \
    EPS_CTRL_CH_1,           \
        EPS_CTRL_CH_2,       \
        EPS_CTRL_CH_3,       \
        EPS_CTRL_CH_4,       \
        EPS_CTRL_CH_5,       \
        EPS_CTRL_CH_6,       \
        EPS_CTRL_CH_7,       \
        EPS_CTRL_CH_8,       \
        EPS_CTRL_CH_9,       \
        EPS_CTRL_CH_10,      \
        EPS_CTRL_CH_11,      \
        EPS_CTRL_CH_12,      \
        EPS_CTRL_CH_13,      \
        EPS_CTRL_CH_14,      \
        EPS_CTRL_CH_15,      \
        EPS_CTRL_CH_16,      \
        EPS_CTRL_CH_17,      \
        EPS_CTRL_CH_18,      \
        EPS_CTRL_CH_19,      \
        EPS_CTRL_CH_20,      \
        EPS_CTRL_CH_21,      \
        EPS_CTRL_CH_22,      \
        EPS_CTRL_CH_23,      \
        EPS_CTRL_CH_24,      \
        EPS_CTRL_CH_25,      \
        EPS_CTRL_CH_26,      \
        EPS_CTRL_CH_27,      \
        EPS_CTRL_CH_28,      \
        EPS_CTRL_CH_29,      \
        EPS_CTRL_CH_30,      \
        EPS_CTRL_CH_31,      \
        EPS_CTRL_CH_32,      \
        EPS_CTRL_CH_33,      \
        EPS_CTRL_CH_34,      \
        EPS_CTRL_CH_35,      \
        EPS_CTRL_CH_36,      \
        EPS_CTRL_CH_37,      \
        EPS_CTRL_CH_38,      \
        EPS_CTRL_CH_39,      \
        EPS_CTRL_CH_40,      \
        EPS_CTRL_CH_41,      \
        EPS_CTRL_CH_42,      \
        EPS_CTRL_CH_43,      \
        EPS_CTRL_CH_44

// EPS I only has 8 GPIO to control the channel outputs.
// EPS II only has 8 GPIO and 16 power outputs to control.
// EPS M has 16 channels which are not only GPIO, they are power outputs
/**
 * @def CHANNEL_OUTPUTS_LIST
 * @brief Maps each channel to specific mission hardware.
 *
 * This mapping is tailored to each mission, ensuring accurate correspondence between channels and their respective hardware.
 *
 * @note The current configuration is done for the platform hardware, mapping all available channels. This is not mandatory
 * for missions where certain channels may not be used.
 */
#define CHANNEL_OUTPUTS_LIST                                                                                  \
    {                                                                                                         \
        { EPS_CTRL_CH_1, EPS1_QUERYCONTROLSINDEX_OUT1, EPS_II_CTRL_DigOUT1, eps_iii_ch1, 1 },                 \
            { EPS_CTRL_CH_2, EPS1_QUERYCONTROLSINDEX_OUT2, EPS_II_CTRL_DigOUT2, eps_iii_ch2, 2 },             \
            { EPS_CTRL_CH_3, EPS1_QUERYCONTROLSINDEX_OUT3, EPS_II_CTRL_DigOUT3, eps_iii_ch3, 3 },             \
            { EPS_CTRL_CH_4, EPS1_QUERYCONTROLSINDEX_OUT4_OBC, EPS_II_CTRL_DigOUT4, eps_iii_ch4, 4 },         \
            { EPS_CTRL_CH_5, EPS1_QUERYCONTROLSINDEX_OUT5, EPS_II_CTRL_DigOUT5, eps_iii_ch5, 5 },             \
            { EPS_CTRL_CH_6, EPS1_QUERYCONTROLSINDEX_OUT6, EPS_II_CTRL_DigOUT6, eps_iii_ch6, 6 },             \
            { EPS_CTRL_CH_7, EPS1_QUERYCONTROLSINDEX_OUT7, EPS_II_CTRL_DigOUT7, eps_iii_ch7, 7 },             \
            { EPS_CTRL_CH_8, EPS1_QUERYCONTROLSINDEX_OUT8, EPS_II_CTRL_DigOUT8, eps_iii_ch8, 8 },             \
            { EPS_CTRL_CH_9, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_BBUS_RAWOutput, eps_iii_ch9, 9 },   \
            { EPS_CTRL_CH_10, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_12V_Master, eps_iii_ch10, 10 },    \
            { EPS_CTRL_CH_11, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_12V_SP1_3, eps_iii_ch11, 11 },     \
            { EPS_CTRL_CH_12, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_12V_SP1_4, eps_iii_ch12, 12 },     \
            { EPS_CTRL_CH_13, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_12V_SP1_5, eps_iii_ch13, 13 },     \
            { EPS_CTRL_CH_14, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_5V_Ch1_Master, eps_iii_ch14, 14 }, \
            { EPS_CTRL_CH_15, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_5V_Ch1_SP2_3, eps_iii_ch15, 15 },  \
            { EPS_CTRL_CH_16, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_5V_Ch1_SP2_4, eps_iii_ch16, 16 },  \
            { EPS_CTRL_CH_17, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_5V_Ch2_Master, eps_iii_ch17, 0 },  \
            { EPS_CTRL_CH_18, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_5V_Ch2_SP1_6, eps_iii_ch18, 0 },   \
            { EPS_CTRL_CH_19, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_5V_Ch2_SP1_7, eps_iii_ch19, 0 },   \
            { EPS_CTRL_CH_20, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch20, 0 }, \
            { EPS_CTRL_CH_21, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch21, 0 }, \
            { EPS_CTRL_CH_22, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch22, 0 }, \
            { EPS_CTRL_CH_23, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch23, 0 }, \
            { EPS_CTRL_CH_24, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch24, 0 }, \
            { EPS_CTRL_CH_25, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch25, 0 }, \
            { EPS_CTRL_CH_26, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch26, 0 }, \
            { EPS_CTRL_CH_27, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch27, 0 }, \
            { EPS_CTRL_CH_28, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch28, 0 }, \
            { EPS_CTRL_CH_29, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch29, 0 }, \
            { EPS_CTRL_CH_30, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch30, 0 }, \
            { EPS_CTRL_CH_31, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch31, 0 }, \
            { EPS_CTRL_CH_32, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch32, 0 }, \
            { EPS_CTRL_CH_33, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch33, 0 }, \
            { EPS_CTRL_CH_34, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch34, 0 }, \
            { EPS_CTRL_CH_35, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch35, 0 }, \
            { EPS_CTRL_CH_36, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch36, 0 }, \
            { EPS_CTRL_CH_37, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch37, 0 }, \
            { EPS_CTRL_CH_38, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch38, 0 }, \
            { EPS_CTRL_CH_39, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch39, 0 }, \
            { EPS_CTRL_CH_40, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch40, 0 }, \
            { EPS_CTRL_CH_41, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch41, 0 }, \
            { EPS_CTRL_CH_42, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch42, 0 }, \
            { EPS_CTRL_CH_43, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch43, 0 }, \
        {                                                                                                     \
            EPS_CTRL_CH_44, EPS1_QUERYCONTROLSINDEX_MAX_CNT, EPS_II_CTRL_3V3_Ch1_Master, eps_iii_ch44, 0      \
        }                                                                                                     \
    }

TODO(NOTICE !Different missions can have different EPS configuration this mapping has to match to the mission requirements)

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
/* No External variables declarations */

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

#ifdef __cplusplus
}
#endif

#endif /* EPS_CTRL_IF_CFG_H */
