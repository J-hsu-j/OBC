/*
 * Copyright (c) 2023-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#ifndef UPY_OBC_PORT_H
#define UPY_OBC_PORT_H

/**
 * @defgroup uPy
 * @{
 *
 * This groups contains files related to the uPy OBC-specific port.
 *
 * @file upy_obc_port.h
 * @brief Public interface of the OBC-specific uPy port.
 *
 * You need this if you want to execute uPy scripts from files on the SD
 * card.
 *
 * @}
 */

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/
/**
 * @enum
 * @brief enumerator used for return type of most of the interfaces provided by
 * OBC port of Micropython
 *
 */
typedef enum
{
    UPY_OK,               /**< UPY_OK */
    UPY_ERROR,            /**< UPY_ERROR */
    UPY_QUEUE_FULL,       /**< UPY_QUEUE_FULL */
    UPY_WRONG_PARAMS,     /**< UPY_WRONG_PARAMS */
    UPY_PROCESSING,       /**< UPY_PROCESSING */
    UPY_PENDING,          /**< UPY_PENDING */
    UPY_SCRIPT_NOT_FOUND, /**< UPY_SCRIPT_NOT_FOUND */
    UPY_SCRIPT_TIMED_OUT, /**< UPY_SCRIPT_TIMED_OUT */
    UPY_CNT               /**< UPY_CNT */
} eObcPortResult_t;

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/
/**
 * @brief Interface providing a way to run script in Micropython from C code
 *
 * @param fp_pScriptName - The script file name. It shall be a null terminated
 * string.
 * @param fp_u8NameLen
 * @return
 */
eObcPortResult_t upy_run(const char *const fp_pScriptName, uint8_t fp_u8NameLen);

#endif // UPY_OBC_PORT_PORT_H_
