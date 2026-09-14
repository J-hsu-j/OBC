/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup onboard_sched
 * @{
 *
 * @file     onboard_sched_types.h
 * @brief    Internal definitions used across the sub-components of the service
 *
 * @}
 *
 */

#ifndef ONBOARD_SCHED_TYPES_H
#define ONBOARD_SCHED_TYPES_H

#include "es_cdef.h"
#include "onboard_sched_cfg.h"

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/

/** @brief Symbol definition for the ASCII null terminator. */
#define STRING_TERMINATOR '\0'

/** @brief Bit mask in the configuration byte for the option indicating script execution. */
#define SCHED_ENTRY_MASK_SCRIPT ((sched_entry_flags_t)0x01)

/** @brief File extension for the schedule files. */
#define SCHED_FILE_EXT ".sch"

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/** @brief Type for the configuration flags of each schedule entry. */
typedef uint8_t sched_entry_flags_t;

/** @brief Type for the CRC value calculated on each schedule entry. */
typedef uint16_t sched_entry_crc_t;

/** @brief Data common to all schedule slots. */
typedef struct
{
    uint32_t next; /**< Offset of the next entry in the schedule from the beginning of the schedule file. */
} PACKED sched_slot_hdr_t;

/** @brief Data common to all scheduled entries. */
typedef struct
{
    uint32_t                   timestamp; /**< UTC time at which the entry shall be released (scheduled). */
    uint32_t                   seq_id;    /**< Unique ID of the scheduled entry. */
    sched_entry_flags_t        flags;     /**< Configuration flags of the entry. */
    sched_entry_payload_size_t cmd_size;  /**< Number of bytes containing the actual command (or script) to be executed. */
} PACKED sched_entry_t;

/** @brief Service data common to all direct command types. */
typedef struct
{
    uint8_t  comm_if_type;                            /**< Protocol interface ID. */
    uint8_t  comm_params_size;                        /**< Size in bytes of the communication parameters data. */
    uint8_t  comm_params[SCHED_COMM_PARAMS_MAX_SIZE]; /**< Communication parameters of the command. */
    uint32_t timeout;                                 /**< Maximum time that the command is allowed to execute. */
} PACKED cmd_service_data_t;
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

#endif /* ONBOARD_SCHED_TYPES_H */
