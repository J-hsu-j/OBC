/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef SDR_TYPES_H
#define SDR_TYPES_H

/**
 * @defgroup sdr
 * @{
 *
 * @file sdr_types.h
 * @brief Public interface for common SDR types
 *
 * @}
 */

#include "es_tftp_pkt_codes.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/
/**
 * @brief Generic structure representing an SDR operation type
 *
 * This is an extendable structure, differentiating between different sdr operations.
 * Currently, file transfer operations are internally supported.
 */
typedef enum
{
    OP_FILE_TRANSFER,
    OP_COMMAND,
    OP_MAX
} sdr_op_t;

/**
 * @brief Generic structure representing an SDR operation request/
 * It provides information on the requested operation type.
 */
typedef struct
{
    sdr_op_t op;
} sdr_op_req_t;

/**
 * @brief Structure representing an SDR file transfer operation type
 */
typedef enum
{
    UPLOAD,
    DOWNLOAD
} sdr_ft_op_t;

/**
 * @brief Structure representing an SDR file operation
 *
 * This structure holds information about an SDR file operation, including the file on the OBC
 * and the file on the SDR.
 *
 * The limitations associated with the file path lengths for both source and destination paths are as follows:
 *      - OBC: 47 characters
 *      - SDR: 197 characters (due to FP packet size limits)
 */
typedef struct
{
    sdr_ft_op_t ft_op;    /**< File transfer Operation type */
    const char *obc_file; /**< Absolute file path on the OBC */
    const char *sdr_file; /**< Absolute file path on the SDR */
} sdr_file_op_t;

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

#ifdef __cplusplus
}
#endif

#endif /* SDR_TYPES_H */
