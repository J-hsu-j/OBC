/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup upy_sd
 * @{
 *
 * @file upy_sd.c
 * @brief uPython SerDes helpers implementation
 *
 * This file implements functions which enable copying of different scalar and structure types to/from
 * uPython objects. All these functions are directly called by the generated code produced by the macchiato uPy
 * C generator so special care must be taken to ensure that the implementation here is properly aligned to the
 * implementation of the macchiato uPy code generator.
 *
 * @}
 *
 */

#include <string.h>
#include "upy_sd.h"
#include "py/runtime.h"
#include "upy_cfg.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
/** @breif Defines a function to copy a FIDL-generated array of scalars to a uPy list object
 *  @param[in] elem_type base type of the array elements
 */
#define DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_INT(elem_type)                                                           \
    mp_obj_t upy_sd_copy_fidl_scalar_array_to_py_list_##elem_type(elem_type *const p_arr, const uint32_t arr_max_sz) \
    {                                                                                                                \
        BREAK_ASSERT(p_arr);                                                                                         \
                                                                                                                     \
        mp_obj_list_t *p_list = MP_OBJ_TO_PTR(mp_obj_new_list(arr_max_sz, NULL));                                    \
                                                                                                                     \
        if (NULL == p_list)                                                                                          \
        {                                                                                                            \
            nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "Could not allocate list"));                    \
        }                                                                                                            \
                                                                                                                     \
        if (NULL == p_arr)                                                                                           \
        {                                                                                                            \
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Source array is NULL"));                        \
        }                                                                                                            \
                                                                                                                     \
        for (size_t i = 0; i < arr_max_sz; i++)                                                                      \
        {                                                                                                            \
            p_list->items[i] = mp_obj_new_int(p_arr[i]);                                                             \
        }                                                                                                            \
                                                                                                                     \
        return MP_OBJ_FROM_PTR(p_list);                                                                              \
    }

/** @brief Defines a function to copy a FIDL-generated float array to a uPy list of floats
 *  @param[in] func_suffix can be either `float` or `double`
 *  @param[in] elem_type base C type of the array elements (float or double)
 *  @param[in] unaligned_float_read_func function name to use for unaligned memory read of a float or double
 */
#define DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_FLOAT(func_suffix, elem_type, unaligned_float_read_func)                   \
    mp_obj_t upy_sd_copy_fidl_scalar_array_to_py_list_##func_suffix(elem_type *const p_arr, const uint32_t arr_max_sz) \
    {                                                                                                                  \
        BREAK_ASSERT(p_arr);                                                                                           \
                                                                                                                       \
        mp_obj_list_t *p_list = MP_OBJ_TO_PTR(mp_obj_new_list(arr_max_sz, NULL));                                      \
                                                                                                                       \
        if (NULL == p_list)                                                                                            \
        {                                                                                                              \
            nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "Could not allocate list"));                      \
        }                                                                                                              \
                                                                                                                       \
        if (NULL == p_arr)                                                                                             \
        {                                                                                                              \
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Source array is NULL"));                          \
        }                                                                                                              \
                                                                                                                       \
        for (size_t i = 0; i < arr_max_sz; i++)                                                                        \
        {                                                                                                              \
            p_list->items[i] = mp_obj_new_float(unaligned_float_read_func(&p_arr[i]));                                 \
        }                                                                                                              \
                                                                                                                       \
        return MP_OBJ_FROM_PTR(p_list);                                                                                \
    }

/** @brief Defines a function to copy a uPy list to a FIDL array of scalars
 *  @param[in] elem_type base C type of the array elements
 */
#define DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_INT(elem_type)                          \
    void upy_sd_copy_fidl_scalar_array_from_py_list_##elem_type(                      \
        elem_type *const p_arr, const uint32_t arr_max_sz, mp_obj_t list_obj)         \
    {                                                                                 \
        BREAK_ASSERT(NULL != p_arr);                                                  \
                                                                                      \
        if (NULL == p_arr)                                                            \
        {                                                                             \
            nlr_raise(                                                                \
                mp_obj_new_exception_msg(&mp_type_ValueError, "NULL pointer error")); \
        }                                                                             \
                                                                                      \
        if (!mp_obj_is_type(list_obj, &mp_type_list))                                 \
        {                                                                             \
            nlr_raise(                                                                \
                mp_obj_new_exception_msg(&mp_type_TypeError, "expected a list"));     \
        }                                                                             \
                                                                                      \
        (void)memset(p_arr, (int16_t)0, (size_t)arr_max_sz * sizeof(p_arr[0]));       \
                                                                                      \
        mp_obj_t *items     = (mp_obj_t *)NULL;                                       \
        size_t    items_cnt = 0U;                                                     \
                                                                                      \
        mp_obj_get_array(list_obj, &items_cnt, &items);                               \
                                                                                      \
        size_t min_sz = (arr_max_sz > items_cnt) ? items_cnt : arr_max_sz;            \
                                                                                      \
        for (size_t i = 0; i < min_sz; i++)                                           \
        {                                                                             \
            p_arr[i] = (elem_type)mp_obj_get_int(items[i]);                           \
        }                                                                             \
    }

/** @brief Defines a function to copy a uPy list of floats to a FIDL float array
 *  @param[in] func_suffix can be 'float' or 'double'
 *  @param[in] elem_type base C type of the array elements (float or double)
 *  @param[in] name of the function used to write the float to memory
 */
#define DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_FLOAT(func_suffix, elem_type, unaligned_float_write_func) \
    void upy_sd_copy_fidl_scalar_array_from_py_list_##func_suffix(                                      \
        elem_type *const p_arr, const uint32_t arr_max_sz, mp_obj_t list_obj)                           \
    {                                                                                                   \
        BREAK_ASSERT(NULL != p_arr);                                                                    \
                                                                                                        \
        if (NULL == p_arr)                                                                              \
        {                                                                                               \
            nlr_raise(                                                                                  \
                mp_obj_new_exception_msg(&mp_type_ValueError, "NULL pointer error"));                   \
        }                                                                                               \
                                                                                                        \
        if (!mp_obj_is_type(list_obj, &mp_type_list))                                                   \
        {                                                                                               \
            nlr_raise(                                                                                  \
                mp_obj_new_exception_msg(&mp_type_TypeError, "expected a list"));                       \
        }                                                                                               \
                                                                                                        \
        (void)memset(p_arr, (int16_t)0, (size_t)arr_max_sz * sizeof(p_arr[0]));                         \
                                                                                                        \
        mp_obj_t *items     = (mp_obj_t *)NULL;                                                         \
        size_t    items_cnt = 0U;                                                                       \
                                                                                                        \
        mp_obj_get_array(list_obj, &items_cnt, &items);                                                 \
                                                                                                        \
        size_t min_sz = (arr_max_sz > items_cnt) ? items_cnt : arr_max_sz;                              \
                                                                                                        \
        for (size_t i = 0; i < min_sz; i++)                                                             \
        {                                                                                               \
            elem_type tmp_val = mp_obj_get_float(items[i]);                                             \
                                                                                                        \
            unaligned_float_write_func((uint8_t *)&p_arr[i], tmp_val);                                  \
        }                                                                                               \
    }

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

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
void upy_sd_copy_fidl_buf_from_py_buf(uint8_t *const p_buf,
                                      const uint32_t buf_max_size,
                                      uint8_t *const p_actual_len,
                                      mp_obj_t       py_buf_obj)
{
    mp_buffer_info_t buf_info = { .buf = NULL, .len = 0U, .typecode = 0 };
    mp_get_buffer_raise(py_buf_obj, &buf_info, MP_BUFFER_READ);
    uint32_t actual_len = (buf_max_size >= buf_info.len) ? buf_info.len : buf_max_size;

    (void)memcpy(p_buf, buf_info.buf, actual_len);

    // zero remaining bytes
    (void)memset(&p_buf[actual_len], 0U, buf_max_size - actual_len);

    // existing macchiato generation doesn't support bigger arrays than 255 bytes
    BREAK_ASSERT(buf_max_size <= 0xFF);

    if (NULL != p_actual_len)
    {
        *p_actual_len = (uint8_t)actual_len;
    }
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_INT(uint8_t)
DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_INT(uint16_t)
DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_INT(uint32_t)
DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_INT(int8_t)
DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_INT(int16_t)
DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_INT(int32_t)
DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_INT(bool)
DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_FLOAT(float, float_t, upy_sd_float_to_unaligned_addr)
DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_FLOAT(double, double_t, upy_sd_double_to_unaligned_addr)

DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_INT(uint8_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_INT(uint16_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_INT(uint32_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_INT(int8_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_INT(int16_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_INT(int32_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_INT(bool)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_FLOAT(float, float_t, upy_sd_float_from_unaligned_addr)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_FLOAT(double, double_t, upy_sd_double_from_unaligned_addr)

float_t upy_sd_float_from_unaligned_addr(const void *p_address)
{
    float_t result;

    // Use memcpy to safely copy the float value from the unaligned address
    // memcpy ensures that we don't perform an unaligned memory access,
    // which could lead to a UsageFault exception on some ARM processors.
    (void)memcpy(&result, p_address, sizeof(float_t));

    return result;
}

void upy_sd_float_to_unaligned_addr(volatile uint8_t *const p_address, const float_t value)
{
    // ensure p_address is of type uint8_t* for byte-wise access

    // temporarily store the float value in a union to facilitate easy byte-wise access
    union
    {
        float_t f_value;
        uint8_t bytes[sizeof(float_t)];
    } float_union;

    float_union.f_value = value;

    // copy the float value byte-by-byte to the target address to avoid unaligned memory access exception
    for (size_t i = 0; i < sizeof(float_t); ++i)
    {
        p_address[i] = float_union.bytes[i];
    }
}

double_t upy_sd_double_from_unaligned_addr(const void *p_address)
{
    double_t result;

    // Use memcpy to safely copy the float value from the unaligned address
    // memcpy ensures that we don't perform an unaligned memory access,
    // which could lead to a UsageFault exception on some ARM processors.
    (void)memcpy(&result, p_address, sizeof(double_t));

    return result;
}

void upy_sd_double_to_unaligned_addr(volatile uint8_t *const p_address, const double_t value)
{
    // ensure p_address is of type uint8_t* for byte-wise access

    // temporarily store the float value in a union to facilitate easy byte-wise access
    union
    {
        double_t d_value;
        uint8_t  bytes[sizeof(double_t)];
    } double_union;

    double_union.d_value = value;

    // copy the float value byte-by-byte to the target address to avoid unaligned memory access exception
    for (size_t i = 0; i < sizeof(double_t); ++i)
    {
        p_address[i] = double_union.bytes[i];
    }
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
