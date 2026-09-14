#ifndef UPY_SD_H
#define UPY_SD_H

/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @defgroup upy_sd uPy SerDes helpers
 * @{
 *
 * This module provides general serialization/deserialization helper functions required by
 * the macchiato uPy generated code.
 *
 * @file upy_sd.h
 * @brief uPy SerDes helpers public interface
 *
 * @}
 */

#include <stdint.h>
#include <math.h>
#include "py/runtime.h"
#include "upy_cfg.h"
#include "datacache.h"
#include "assertions.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/

/** @brief Used to tag structs as packed */
#define PACKED_STRUCT __attribute__((__packed__))

/** @brief Declares a function to copy a uPy list to a FIDL scalar array
 *  @param[in] elem_type C name of the base type of the FIDL array
 * */
#define DECL_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_INT(elem_type)    \
    void upy_sd_copy_fidl_scalar_array_from_py_list_##elem_type( \
        elem_type *const p_arr, const uint32_t arr_max_sz, mp_obj_t list_obj);

/** @brief Declares a function to copy a uPy list of floats to a FIDL float array
 *  @param[in] func_suffix can be either `float` or `double`
 *  @param[in] elem_type C name of the base type of the FIDL array
 * */
#define DECL_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_FLOAT(func_suffix, elem_type) \
    void upy_sd_copy_fidl_scalar_array_from_py_list_##func_suffix(           \
        elem_type *const p_arr, const uint32_t arr_max_sz, mp_obj_t list_obj);

/** @brief Declares a function to copy a uPy list of struct objects to a FIDL-struct array
 *  @param[in] elem_type C name of the base type of the FIDL array
 * */
#define DECL_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(elem_type) \
    void upy_sd_copy_fidl_scalar_array_from_py_list_##elem_type( \
        elem_type *const p_arr, const uint32_t arr_max_sz, mp_obj_t list_obj);

/** @brief Declares a function to copy a scalar array to a uPy list of int objects
 *  @param[in] elem_type C name of the base type of the FIDL array
 * */
#define DECL_FUNC_COPY_SCALAR_ARRAY_TO_PY_LIST_INT(elem_type) \
    mp_obj_t upy_sd_copy_fidl_scalar_array_to_py_list_##elem_type(elem_type *const p_arr, const uint32_t arr_max_sz);

/** @brief Declares a function to copy a FIDL-generated float array to a uPy
 * list of floats
 *  @param[in] func_suffix can be either `float` or `double`
 *  @param[in] elem_type C name of the base type of the FIDL array
 * */
#define DECL_FUNC_COPY_SCALAR_ARRAY_TO_PY_LIST_FLOAT(func_suffix, elem_type) \
    mp_obj_t upy_sd_copy_fidl_scalar_array_to_py_list_##func_suffix(elem_type *const p_arr, const uint32_t arr_max_sz);

/** @brief Defines a function to copy a uPy list of structs to a FIDL struct array
 *  @param[in] elem_type C name of the base type of the FIDL array
 *  @param[in] upy_struct_type type of the uPy class data
 * */
#define DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(elem_type, upy_struct_type)      \
    static void upy_sd_copy_fidl_scalar_array_from_py_list_##elem_type(               \
        elem_type *const p_arr, const uint32_t arr_max_sz, mp_obj_t list_obj)         \
    {                                                                                 \
        if (NULL == p_arr)                                                            \
        {                                                                             \
            BREAK_ASSERT(false);                                                      \
            nlr_raise(                                                                \
                mp_obj_new_exception_msg(&mp_type_ValueError, "NULL pointer error")); \
        }                                                                             \
        if (!mp_obj_is_type(list_obj, &mp_type_list))                                 \
        {                                                                             \
            nlr_raise(                                                                \
                mp_obj_new_exception_msg(&mp_type_TypeError, "expected a list"));     \
        }                                                                             \
        (void)memset(p_arr, (int16_t)0, (size_t)arr_max_sz * sizeof(p_arr[0]));       \
        mp_obj_t *items     = (mp_obj_t *)NULL;                                       \
        size_t    items_cnt = 0U;                                                     \
        mp_obj_get_array(list_obj, &items_cnt, &items);                               \
        size_t min_sz = (arr_max_sz > items_cnt) ? items_cnt : arr_max_sz;            \
        for (size_t i = 0; i < min_sz; i++)                                           \
        {                                                                             \
            p_arr[i] = ((upy_struct_type *)MP_OBJ_TO_PTR(items[i]))->class_data;      \
        }                                                                             \
    }

/** @brief Defines a function to copy a FIDL struct array to a uPy list of struct objects
 *  @param[in] elem_type C name of the base type of the FIDL array
 *  @param[in] upy_struct_type type of the uPy class data
 *  @param[in] simple_type uPy class constructor prefix indicating the class name
 * */
#define DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(elem_type, upy_struct_type, simple_type)                                 \
    static mp_obj_t upy_sd_copy_fidl_scalar_array_to_py_list_##elem_type(                                                   \
        elem_type *const p_arr, const uint32_t arr_max_sz)                                                                  \
    {                                                                                                                       \
        BREAK_ASSERT(p_arr);                                                                                                \
        mp_obj_list_t *list = MP_OBJ_TO_PTR(mp_obj_new_list(0, NULL));                                                      \
        if (NULL != p_arr)                                                                                                  \
        {                                                                                                                   \
            for (size_t i = 0; i < arr_max_sz; i++)                                                                         \
            {                                                                                                               \
                mp_obj_list_append((mp_obj_t)list, simple_type##_make_from_c_buf((uint8_t *)&p_arr[i], sizeof(elem_type))); \
            }                                                                                                               \
        }                                                                                                                   \
        return MP_OBJ_FROM_PTR(list);                                                                                       \
    }

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/** @brief FP header structure */
typedef struct
{
    uint16_t proto_id; /**< FP protocol ID */
    uint32_t func_id;  /**< FP Function ID */
    uint16_t seq_id;   /**< FP sequence ID */
    uint8_t  err_code; /**< FP error code */
} PACKED_STRUCT upy_serdes_helpers_fp_hdr_t;

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/
/**
 * @brief Performs an buffer copy to a FIDL-generated ByteBuffer/String variable
 * from a uPy buffer object
 *
 * @param[out] p_buf pointer to the generated FIDL buffer
 * @param[in] buf_max_size maximum size of the region pointed to by p_buf
 * @param[out] p_actual_len receives the actual number of bytes written to p_buf
 * @param[in] py_buf_obj uPy buffer object reference
 */
void upy_sd_copy_fidl_buf_from_py_buf(uint8_t *const p_buf,
                                      const uint32_t buf_max_size,
                                      uint8_t *const p_actual_len,
                                      mp_obj_t       py_buf_obj);

DECL_FUNC_COPY_SCALAR_ARRAY_TO_PY_LIST_INT(uint8_t)
DECL_FUNC_COPY_SCALAR_ARRAY_TO_PY_LIST_INT(uint16_t)
DECL_FUNC_COPY_SCALAR_ARRAY_TO_PY_LIST_INT(uint32_t)
DECL_FUNC_COPY_SCALAR_ARRAY_TO_PY_LIST_INT(int8_t)
DECL_FUNC_COPY_SCALAR_ARRAY_TO_PY_LIST_INT(int16_t)
DECL_FUNC_COPY_SCALAR_ARRAY_TO_PY_LIST_INT(int32_t)
DECL_FUNC_COPY_SCALAR_ARRAY_TO_PY_LIST_INT(bool)
DECL_FUNC_COPY_SCALAR_ARRAY_TO_PY_LIST_FLOAT(float, float_t)
DECL_FUNC_COPY_SCALAR_ARRAY_TO_PY_LIST_FLOAT(double, double_t)

DECL_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_INT(uint8_t)
DECL_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_INT(uint16_t)
DECL_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_INT(uint32_t)
DECL_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_INT(int8_t)
DECL_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_INT(int16_t)
DECL_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_INT(int32_t)
DECL_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_INT(bool)
DECL_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_FLOAT(float, float_t)
DECL_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_FLOAT(double, double_t)

/**
 * Reads a float from an unaligned memory address.
 *
 * @param[in] p_address The unaligned memory address from which to read the float.
 * @return The float value read from the unaligned address.
 */
float_t upy_sd_float_from_unaligned_addr(const void *p_address);

/**
 * Writes a float to an unaligned memory address
 *
 * @param[in/out] p_address The unaligned memory address to which to write the float value
 * @param[in] value float value to write
 */
void upy_sd_float_to_unaligned_addr(volatile uint8_t *const p_address, const float_t value);

/**
 * Reads a double from an unaligned memory address.
 *
 * @param[in] p_address The unaligned memory address from which to read
 * @return The value read from the unaligned address
 */
double_t upy_sd_double_from_unaligned_addr(const void *p_address);

/**
 * Writes a double to an unaligned memory address
 *
 * @param[in/out] p_address The unaligned memory address to which to write the value
 * @param[in] value value to write
 */
void upy_sd_double_to_unaligned_addr(volatile uint8_t *const p_address, const double_t value);

#ifdef __cplusplus
}
#endif

#endif // UPY_SD_H
