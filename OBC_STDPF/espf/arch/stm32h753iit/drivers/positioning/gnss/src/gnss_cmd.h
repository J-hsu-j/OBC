/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef GNSS_CMD_H
#define GNSS_CMD_H

/**
 * @addtogroup gnss
 * @{
 *
 * @file gnss_cmd.h
 * @brief gnss user command module public interface
 *
 * @}
 */

#include "sys_time.h"
#include "timer.h"
#include "es_cdef.h"
#include "sys_instancer_ct.h"
#include "gnss_types.h"
#include "gnss_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
/** @brief invalid command id */
#define INVALID_CMD_ID ((uint8_t)0xFFU)

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
 * @brief gnss user command module initialization
 * @return mod_op_status_id_t initialization status
 */
bool gnss_cmd_init(void);

/**
 * @brief gnss user command module de-initialization
 */
void gnss_cmd_deinit(void);

/**
 * @brief is the gnss user command thread initialized
 * @retval true  the gnss user command thread is initialized
 * @retval false the gnss user command thread is not initialized
 */
bool is_gnss_cmd_init(void);

/**
 * @brief execute gnss user command
 * @return mod_op_status_id_t command execution status
 */
gnss_cmd_status_t gnss_send_cmd(const char            *p_cmd_pld,
                                const uint8_t          cmd_pld_sz,
                                const uint32_t         timeout_ms,
                                pf_gnss_cmd_exec_cbk_t gnss_cmd_exec_cbk,
                                uint8_t *const         p_cmd_id);

/**
 * @brief register gnss command response
 */
void gnss_register_cmd_resp(void);

/**
 * @brief get gnss user command status based on command id
 * @param[in] cmd_id: command id
 * @param[in] p_cmd_data: pointer to command data
 * @return gnss_cmd_status_t command status
 */
gnss_cmd_status_t gnss_get_cmd_status(uint8_t cmd_id, gnss_cmd_data_t *const p_cmd_data);

/**
 * @brief set gnss user command status based on command id
 * @param[in] cmd_id: command id
 * @param[in] p_cmd_data: pointer to command data
 * @return gnss_cmd_status_t command status
 */
gnss_cmd_status_t gnss_set_cmd_status(uint8_t cmd_id, const gnss_cmd_data_t *const p_cmd_data);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // GNSS_CMD_H
