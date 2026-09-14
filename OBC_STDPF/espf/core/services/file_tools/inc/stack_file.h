/*
 * Copyright (c) 2023-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup service_file_tools
 * @{
 *
 * @file stack_file.h
 *
 * @brief Due to memory limitations of embedded applications,
 *  this tool has been implemented to simulate a stack memory container
 *  on a file storage device.
 *  It copies fixed-size elements to and from the stack file.
 *  Size can be defined at run-time in context structure below.
 *
 * @}
 *
 */

#ifndef STACK_FILE_H
#define STACK_FILE_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "fm_mng.h"

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/**
 * @struct stack_file_ctx_t
 * @brief File stack library user context.
 *
 * This structure is used to manage the context of a file stack.
 */
typedef struct
{
    uint32_t    elem_size;                /**< @brief Size in bytes of a single element on the stack. */
    uint32_t    count;                    /**< @brief Number of elements on the stack. */
    char        filename[FM_MAX_PATH];    /**< @brief Name of the stack file to create. */
    fm_handle_t handle;                   /**< @brief Handle to the file file object. It may be left uninialized if use_internal_file_object = true. */
    bool        use_internal_file_object; /**< @brief Flag to indicate whether the file handle allocated internally or by the caller. */
    bool        is_open;                  /**< @brief Flag to indicate whether the file is open. */
} stack_file_ctx_t;

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

/**
 * @brief Creates an empty file and initializes its header.
 *
 * This function is responsible for creating an empty file and initializing its header.
 *
 * @param[in,out] p_ctx User-provided context to manage the stack. It will be
 * initialized by the function.
 *
 * @return see @ref fm_result_t for details on possible error codes.
 */
fm_result_t stack_file_open(stack_file_ctx_t *const p_ctx);

/**
 * @brief Pushes an element on top of the stack.
 *
 * This function is responsible for pushing an element on top of the stack.
 *
 * @param[in] p_ctx User-provided context to manage the stack. It must have been
 * initialized by the @ref stack_file_open function before use.
 * @param[in] p_elem A pointer to the user element to copy on the file stack. It must be
 * of the size, specified in @ref file_stack_file_ctx_t::stack_elem_size.
 *
 * @return see @ref fm_result_t for details on possible error codes.
 */
fm_result_t stack_file_push(stack_file_ctx_t *const p_ctx, const void *const p_elem);

/**
 * @brief Pops an element off the stack.
 *
 * This function is responsible for popping an element off the stack.
 *
 * @param[in]  p_ctx User-provided context to manage the stack. It must have been
 * initialized by the @ref stack_file_open function before use.
 * @param[out] p_elem A pointer to the user buffer which will receive a copy of the element
 * on top of the stack.
 *
 * @return see @ref fm_result_t for details on possible error codes.
 */
fm_result_t stack_file_pop(stack_file_ctx_t *const p_ctx, void *const p_elem);

/**
 * @brief Provides the number of elements on the stack.
 *
 * This function returns the number of elements currently on the stack.
 *
 * @param[in] p_ctx User-provided context to manage the stack. It must have been
 * initialized by the @ref stack_file_open function before use.
 *
 * @return The number of elements on the stack.
 */
uint32_t stack_file_count(const stack_file_ctx_t *const p_ctx);

/**
 * @brief Frees all resources taken by the file stack operations and deletes the created stack file.
 *
 * This function is responsible for freeing all resources taken by the file stack operations and optionally deleting the created stack file.
 *
 * @param[out] p_ctx User-provided context to manage the stack. It must have been
 * initialized by the stack_file_open() function.
 * @param[in]  delete If true, the stack file will be deleted once closed.
 *
 * @return see @ref fm_result_t for details on possible error codes.
 */
fm_result_t stack_file_close(stack_file_ctx_t *const p_ctx, const bool delete);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif /* STACK_FILE_H */
