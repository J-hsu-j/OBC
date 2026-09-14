/*!
********************************************************************************************
* @file upy_telemetry.c
* @brief uPy C bindings generator
********************************************************************************************
* @version           interface telemetry v2.0
*
* @copyright         (C) Copyright EnduroSat
*
*                    Contents and presentations are protected world-wide.
*                    Any kind of using, copying etc. is prohibited without prior permission.
*                    All rights - incl. industrial property rights - are reserved.
*
*-------------------------------------------------------------------------------------------
* GENERATOR: org.endurosat.generators.macchiato.binders.Gen_uPy v0.8
*-------------------------------------------------------------------------------------------
* !!! Please note that this code is fully GENERATED and shall not be manually modified as
* all changes will be overwritten !!!
********************************************************************************************
*/

/**
 * @defgroup telemetry telemetry
 * @{
 *
 * OBC telemetry service control and configuration interface
 *
 * @file upy_telemetry.c
 * @brief telemetry uPython C wrapper module implementation
 *
 * This module is fully generated from a FIDL file and represents a uPython C extension module which
 * registers specific classes related to the communication interfaces of the telemetry API. Users of
 * this module can import it in a uPython script and serialize/deserialize FP requests and responses
 * via the provided services here.
 *
 * @}
 */         

// Note: The 'const' qualifiers get discarded because all generated uPy types must be placed in FLASH ROM
//       to conserve RAM and the APIs always assume that the data is placed in RAM although these structures
//       are not actually modified by the code 
#pragma GCC diagnostic ignored "-Wdiscarded-qualifiers"

// Note: This warning occurs for variables of type float and double which are defined inside packed structures.
//       Accessing those variables by the FPU may cause an unaligned memory access MCU exception if they are not 
//       aligned to a 4-byte boundary and since we require packed structures as a shortcut for straightforward type 
//       serialization/deserialization, all such accesses are performed by the code generator in a byte-wise manner, 
//       hence the error is actually handled and can be suppressed.
#pragma GCC diagnostic ignored "-Waddress-of-packed-member"

// Note: The current version of the uPy C generator takes the easy path of providing all flavors of copy functions
//       without tracking dependencies and thus the compiler emits an "unused-function" warning when those are not
//       used in any other part of the generated code. Since the overhead of having the functions is not big and the 
//       unused functions are finally removed from the final image by the linker, the warnings are suppressed here.
#pragma GCC diagnostic ignored "-Wunused-function"

#include "upy_cfg.h"
#include "py/runtime.h"
#include "py/obj.h"
#include "upy_sd.h"
#include "FP_telemetryProtocolTypes.h"

/**********************************************************************
 *
 *  uPy class definitions for struct types
 *
 **********************************************************************/

/**********************************************************************
 *
 *  uPy class definition for struct 'tlm_preset_cfg'
 *
 **********************************************************************/
    
// class structure for type tlm_preset_cfg
typedef struct 
{
    mp_obj_base_t base;
    TELEMETRY_tlm_preset_cfg_t class_data;
} PACKED_STRUCT tlm_preset_cfg_class_obj_t;

// tlm_preset_cfg class constructor from field arguments
STATIC mp_obj_t tlm_preset_cfg_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 3, 3, false);
    
    tlm_preset_cfg_class_obj_t *p_self = m_new_obj(tlm_preset_cfg_class_obj_t);
    p_self->base.type = type;
    
    // data_id
    p_self->class_data.u16Data_id = (uint16_t) mp_obj_get_int(p_args[0]);
    // active
    p_self->class_data.bActive = (bool) mp_obj_get_int(p_args[1]);
    // acq_period_ms
    p_self->class_data.u16Acq_period_ms = (uint16_t) mp_obj_get_int(p_args[2]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'tlm_preset_cfg' getters
//

STATIC mp_obj_t tlm_preset_cfg_get_data_id(mp_obj_t self_in) 
{
    const tlm_preset_cfg_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16Data_id);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(tlm_preset_cfg_get_data_id_obj, tlm_preset_cfg_get_data_id);

STATIC mp_obj_t tlm_preset_cfg_get_active(mp_obj_t self_in) 
{
    const tlm_preset_cfg_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bActive);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(tlm_preset_cfg_get_active_obj, tlm_preset_cfg_get_active);

STATIC mp_obj_t tlm_preset_cfg_get_acq_period_ms(mp_obj_t self_in) 
{
    const tlm_preset_cfg_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16Acq_period_ms);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(tlm_preset_cfg_get_acq_period_ms_obj, tlm_preset_cfg_get_acq_period_ms);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t tlm_preset_cfg_locals_dict_table[3] = {
    { MP_ROM_QSTR(MP_QSTR_get_data_id), MP_ROM_PTR(&tlm_preset_cfg_get_data_id_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_active), MP_ROM_PTR(&tlm_preset_cfg_get_active_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_acq_period_ms), MP_ROM_PTR(&tlm_preset_cfg_get_acq_period_ms_obj) },
};

STATIC MP_DEFINE_CONST_DICT(tlm_preset_cfg_locals_dict, tlm_preset_cfg_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    tlm_preset_cfg_type,
    MP_QSTR_tlm_preset_cfg,
    MP_TYPE_FLAG_NONE,
    make_new, tlm_preset_cfg_make_new,
    locals_dict, (mp_obj_dict_t*)&tlm_preset_cfg_locals_dict
);

STATIC mp_obj_t tlm_preset_cfg_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(TELEMETRY_tlm_preset_cfg_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    tlm_preset_cfg_class_obj_t *p_self = m_new_obj(tlm_preset_cfg_class_obj_t);
    p_self->base.type = &tlm_preset_cfg_type;
    
    const TELEMETRY_tlm_preset_cfg_t *p_data = (const TELEMETRY_tlm_preset_cfg_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// tlm_preset_cfg class constructor from a byte buffer
STATIC mp_obj_t tlm_preset_cfg_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return tlm_preset_cfg_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(TELEMETRY_tlm_preset_cfg_t, tlm_preset_cfg_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(TELEMETRY_tlm_preset_cfg_t, tlm_preset_cfg_class_obj_t, tlm_preset_cfg)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(tlm_preset_cfg_make_from_buf_obj, tlm_preset_cfg_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'tlm_file_size_limit_cfg'
 *
 **********************************************************************/
    
// class structure for type tlm_file_size_limit_cfg
typedef struct 
{
    mp_obj_base_t base;
    TELEMETRY_tlm_file_size_limit_cfg_t class_data;
} PACKED_STRUCT tlm_file_size_limit_cfg_class_obj_t;

// tlm_file_size_limit_cfg class constructor from field arguments
STATIC mp_obj_t tlm_file_size_limit_cfg_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 2, 2, false);
    
    tlm_file_size_limit_cfg_class_obj_t *p_self = m_new_obj(tlm_file_size_limit_cfg_class_obj_t);
    p_self->base.type = type;
    
    // size_limit_kb
    p_self->class_data.u32Size_limit_kb = (uint32_t) mp_obj_get_int(p_args[0]);
    // max_log_files_cnt
    p_self->class_data.u16Max_log_files_cnt = (uint16_t) mp_obj_get_int(p_args[1]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'tlm_file_size_limit_cfg' getters
//

STATIC mp_obj_t tlm_file_size_limit_cfg_get_size_limit_kb(mp_obj_t self_in) 
{
    const tlm_file_size_limit_cfg_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Size_limit_kb);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(tlm_file_size_limit_cfg_get_size_limit_kb_obj, tlm_file_size_limit_cfg_get_size_limit_kb);

STATIC mp_obj_t tlm_file_size_limit_cfg_get_max_log_files_cnt(mp_obj_t self_in) 
{
    const tlm_file_size_limit_cfg_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16Max_log_files_cnt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(tlm_file_size_limit_cfg_get_max_log_files_cnt_obj, tlm_file_size_limit_cfg_get_max_log_files_cnt);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t tlm_file_size_limit_cfg_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_size_limit_kb), MP_ROM_PTR(&tlm_file_size_limit_cfg_get_size_limit_kb_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_max_log_files_cnt), MP_ROM_PTR(&tlm_file_size_limit_cfg_get_max_log_files_cnt_obj) },
};

STATIC MP_DEFINE_CONST_DICT(tlm_file_size_limit_cfg_locals_dict, tlm_file_size_limit_cfg_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    tlm_file_size_limit_cfg_type,
    MP_QSTR_tlm_file_size_limit_cfg,
    MP_TYPE_FLAG_NONE,
    make_new, tlm_file_size_limit_cfg_make_new,
    locals_dict, (mp_obj_dict_t*)&tlm_file_size_limit_cfg_locals_dict
);

STATIC mp_obj_t tlm_file_size_limit_cfg_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(TELEMETRY_tlm_file_size_limit_cfg_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    tlm_file_size_limit_cfg_class_obj_t *p_self = m_new_obj(tlm_file_size_limit_cfg_class_obj_t);
    p_self->base.type = &tlm_file_size_limit_cfg_type;
    
    const TELEMETRY_tlm_file_size_limit_cfg_t *p_data = (const TELEMETRY_tlm_file_size_limit_cfg_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// tlm_file_size_limit_cfg class constructor from a byte buffer
STATIC mp_obj_t tlm_file_size_limit_cfg_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return tlm_file_size_limit_cfg_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(TELEMETRY_tlm_file_size_limit_cfg_t, tlm_file_size_limit_cfg_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(TELEMETRY_tlm_file_size_limit_cfg_t, tlm_file_size_limit_cfg_class_obj_t, tlm_file_size_limit_cfg)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(tlm_file_size_limit_cfg_make_from_buf_obj, tlm_file_size_limit_cfg_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'tlm_general_cfg'
 *
 **********************************************************************/
    
// class structure for type tlm_general_cfg
typedef struct 
{
    mp_obj_base_t base;
    TELEMETRY_tlm_general_cfg_t class_data;
} PACKED_STRUCT tlm_general_cfg_class_obj_t;

// tlm_general_cfg class constructor from field arguments
STATIC mp_obj_t tlm_general_cfg_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    tlm_general_cfg_class_obj_t *p_self = m_new_obj(tlm_general_cfg_class_obj_t);
    p_self->base.type = type;
    
    // tlm_auto_start_en
    p_self->class_data.bTlm_auto_start_en = (bool) mp_obj_get_int(p_args[0]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'tlm_general_cfg' getters
//

STATIC mp_obj_t tlm_general_cfg_get_tlm_auto_start_en(mp_obj_t self_in) 
{
    const tlm_general_cfg_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bTlm_auto_start_en);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(tlm_general_cfg_get_tlm_auto_start_en_obj, tlm_general_cfg_get_tlm_auto_start_en);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t tlm_general_cfg_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_tlm_auto_start_en), MP_ROM_PTR(&tlm_general_cfg_get_tlm_auto_start_en_obj) },
};

STATIC MP_DEFINE_CONST_DICT(tlm_general_cfg_locals_dict, tlm_general_cfg_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    tlm_general_cfg_type,
    MP_QSTR_tlm_general_cfg,
    MP_TYPE_FLAG_NONE,
    make_new, tlm_general_cfg_make_new,
    locals_dict, (mp_obj_dict_t*)&tlm_general_cfg_locals_dict
);

STATIC mp_obj_t tlm_general_cfg_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(TELEMETRY_tlm_general_cfg_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    tlm_general_cfg_class_obj_t *p_self = m_new_obj(tlm_general_cfg_class_obj_t);
    p_self->base.type = &tlm_general_cfg_type;
    
    const TELEMETRY_tlm_general_cfg_t *p_data = (const TELEMETRY_tlm_general_cfg_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// tlm_general_cfg class constructor from a byte buffer
STATIC mp_obj_t tlm_general_cfg_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return tlm_general_cfg_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(TELEMETRY_tlm_general_cfg_t, tlm_general_cfg_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(TELEMETRY_tlm_general_cfg_t, tlm_general_cfg_class_obj_t, tlm_general_cfg)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(tlm_general_cfg_make_from_buf_obj, tlm_general_cfg_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'tlm_stats'
 *
 **********************************************************************/
    
// class structure for type tlm_stats
typedef struct 
{
    mp_obj_base_t base;
    TELEMETRY_tlm_stats_t class_data;
} PACKED_STRUCT tlm_stats_class_obj_t;

// tlm_stats class constructor from field arguments
STATIC mp_obj_t tlm_stats_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 7, 7, false);
    
    tlm_stats_class_obj_t *p_self = m_new_obj(tlm_stats_class_obj_t);
    p_self->base.type = type;
    
    // is_started
    p_self->class_data.bIs_started = (bool) mp_obj_get_int(p_args[0]);
    // msg_pushed_cnt
    p_self->class_data.u32Msg_pushed_cnt = (uint32_t) mp_obj_get_int(p_args[1]);
    // msg_popped_cnt
    p_self->class_data.u32Msg_popped_cnt = (uint32_t) mp_obj_get_int(p_args[2]);
    // free_bytes_min
    p_self->class_data.u32Free_bytes_min = (uint32_t) mp_obj_get_int(p_args[3]);
    // discarded_messages_cnt
    p_self->class_data.u32Discarded_messages_cnt = (uint32_t) mp_obj_get_int(p_args[4]);
    // max_number_of_batch_msg
    p_self->class_data.u32Max_number_of_batch_msg = (uint32_t) mp_obj_get_int(p_args[5]);
    // active_slot_id
    p_self->class_data.u32Active_slot_id = (uint32_t) mp_obj_get_int(p_args[6]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'tlm_stats' getters
//

STATIC mp_obj_t tlm_stats_get_is_started(mp_obj_t self_in) 
{
    const tlm_stats_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIs_started);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(tlm_stats_get_is_started_obj, tlm_stats_get_is_started);

STATIC mp_obj_t tlm_stats_get_msg_pushed_cnt(mp_obj_t self_in) 
{
    const tlm_stats_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Msg_pushed_cnt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(tlm_stats_get_msg_pushed_cnt_obj, tlm_stats_get_msg_pushed_cnt);

STATIC mp_obj_t tlm_stats_get_msg_popped_cnt(mp_obj_t self_in) 
{
    const tlm_stats_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Msg_popped_cnt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(tlm_stats_get_msg_popped_cnt_obj, tlm_stats_get_msg_popped_cnt);

STATIC mp_obj_t tlm_stats_get_free_bytes_min(mp_obj_t self_in) 
{
    const tlm_stats_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Free_bytes_min);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(tlm_stats_get_free_bytes_min_obj, tlm_stats_get_free_bytes_min);

STATIC mp_obj_t tlm_stats_get_discarded_messages_cnt(mp_obj_t self_in) 
{
    const tlm_stats_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Discarded_messages_cnt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(tlm_stats_get_discarded_messages_cnt_obj, tlm_stats_get_discarded_messages_cnt);

STATIC mp_obj_t tlm_stats_get_max_number_of_batch_msg(mp_obj_t self_in) 
{
    const tlm_stats_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Max_number_of_batch_msg);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(tlm_stats_get_max_number_of_batch_msg_obj, tlm_stats_get_max_number_of_batch_msg);

STATIC mp_obj_t tlm_stats_get_active_slot_id(mp_obj_t self_in) 
{
    const tlm_stats_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Active_slot_id);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(tlm_stats_get_active_slot_id_obj, tlm_stats_get_active_slot_id);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t tlm_stats_locals_dict_table[7] = {
    { MP_ROM_QSTR(MP_QSTR_get_is_started), MP_ROM_PTR(&tlm_stats_get_is_started_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_msg_pushed_cnt), MP_ROM_PTR(&tlm_stats_get_msg_pushed_cnt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_msg_popped_cnt), MP_ROM_PTR(&tlm_stats_get_msg_popped_cnt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_free_bytes_min), MP_ROM_PTR(&tlm_stats_get_free_bytes_min_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_discarded_messages_cnt), MP_ROM_PTR(&tlm_stats_get_discarded_messages_cnt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_max_number_of_batch_msg), MP_ROM_PTR(&tlm_stats_get_max_number_of_batch_msg_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_active_slot_id), MP_ROM_PTR(&tlm_stats_get_active_slot_id_obj) },
};

STATIC MP_DEFINE_CONST_DICT(tlm_stats_locals_dict, tlm_stats_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    tlm_stats_type,
    MP_QSTR_tlm_stats,
    MP_TYPE_FLAG_NONE,
    make_new, tlm_stats_make_new,
    locals_dict, (mp_obj_dict_t*)&tlm_stats_locals_dict
);

STATIC mp_obj_t tlm_stats_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(TELEMETRY_tlm_stats_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    tlm_stats_class_obj_t *p_self = m_new_obj(tlm_stats_class_obj_t);
    p_self->base.type = &tlm_stats_type;
    
    const TELEMETRY_tlm_stats_t *p_data = (const TELEMETRY_tlm_stats_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// tlm_stats class constructor from a byte buffer
STATIC mp_obj_t tlm_stats_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return tlm_stats_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(TELEMETRY_tlm_stats_t, tlm_stats_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(TELEMETRY_tlm_stats_t, tlm_stats_class_obj_t, tlm_stats)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(tlm_stats_make_from_buf_obj, tlm_stats_make_from_buf);

/**********************************************************************
 *
 *  Enumeration classes
 *
 **********************************************************************/
//
// Enumeration classes for type 'tlm_file_logging_type'
//
STATIC const mp_rom_map_elem_t tlm_file_logging_type_locals_dict_table[1] = 
{
    { MP_ROM_QSTR(MP_QSTR_TLM_FILE_LOGGING_TYPE_SIZE_LIMIT), MP_ROM_INT(TELEMETRY_TLM_FILE_LOGGING_TYPE_SIZE_LIMIT)},
};

STATIC MP_DEFINE_CONST_DICT(tlm_file_logging_type_class_locals_dict, tlm_file_logging_type_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    tlm_file_logging_type_class_type,
    MP_QSTR_tlm_file_logging_type,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&tlm_file_logging_type_class_locals_dict
);
//
// Enumeration classes for type 'TelemetryInstance'
//
STATIC const mp_rom_map_elem_t telemetryinstance_locals_dict_table[2] = 
{
    { MP_ROM_QSTR(MP_QSTR_TELEMETRYINSTANCE_TLM_INST_0), MP_ROM_INT(TELEMETRY_TELEMETRYINSTANCE_TLM_INST_0)},
    { MP_ROM_QSTR(MP_QSTR_TELEMETRYINSTANCE_TLM_INST_1), MP_ROM_INT(TELEMETRY_TELEMETRYINSTANCE_TLM_INST_1)},
};

STATIC MP_DEFINE_CONST_DICT(telemetryinstance_class_locals_dict, telemetryinstance_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    telemetryinstance_class_type,
    MP_QSTR_TelemetryInstance,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&telemetryinstance_class_locals_dict
);
//
// Enumeration classes for type 'StandardResult'
//
STATIC const mp_rom_map_elem_t standardresult_locals_dict_table[4] = 
{
    { MP_ROM_QSTR(MP_QSTR_STANDARDRESULT_SUCCESS), MP_ROM_INT(TELEMETRY_STANDARDRESULT_SUCCESS)},
    { MP_ROM_QSTR(MP_QSTR_STANDARDRESULT_ERROR), MP_ROM_INT(TELEMETRY_STANDARDRESULT_ERROR)},
    { MP_ROM_QSTR(MP_QSTR_STANDARDRESULT_INVALID_ARGS), MP_ROM_INT(TELEMETRY_STANDARDRESULT_INVALID_ARGS)},
    { MP_ROM_QSTR(MP_QSTR_STANDARDRESULT_NOT_SUPPORTED), MP_ROM_INT(TELEMETRY_STANDARDRESULT_NOT_SUPPORTED)},
};

STATIC MP_DEFINE_CONST_DICT(standardresult_class_locals_dict, standardresult_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    standardresult_class_type,
    MP_QSTR_StandardResult,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&standardresult_class_locals_dict
);

/**********************************************************************
 *
 *  Static function definitions
 *
 **********************************************************************/
// uPy request function for method 'getTelemetryGeneralConfig'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrygetTelemetryGeneralConfigRequestData_t data;
} req_getTelemetryGeneralConfig_fp_t;

STATIC mp_obj_t req_getTelemetryGeneralConfig(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_getTelemetryGeneralConfig_fp_t * p_req_data = m_malloc(sizeof(req_getTelemetryGeneralConfig_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getTelemetryGeneralConfig' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 258;
    p_req_data->fp_hdr.func_id = 0;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eTlm_instance_id = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getTelemetryGeneralConfig_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getTelemetryGeneralConfig'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrygetTelemetryGeneralConfigResponseData_t data;
} resp_getTelemetryGeneralConfig_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getTelemetryGeneralConfig_fp_t class_data;
} resp_getTelemetryGeneralConfig_class_obj_t;

STATIC mp_obj_t resp_getTelemetryGeneralConfig_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getTelemetryGeneralConfig_class_obj_t *p_self = m_new_obj(resp_getTelemetryGeneralConfig_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getTelemetryGeneralConfig_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getTelemetryGeneralConfig_fp_t *p_data = (resp_getTelemetryGeneralConfig_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "getTelemetryGeneralConfig" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getTelemetryGeneralConfig_get_res(mp_obj_t self_in) 
{
    const resp_getTelemetryGeneralConfig_class_obj_t *p_resp_data = ((resp_getTelemetryGeneralConfig_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eRes);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getTelemetryGeneralConfig_get_res_obj, resp_getTelemetryGeneralConfig_get_res);

STATIC mp_obj_t resp_getTelemetryGeneralConfig_get_cfg(mp_obj_t self_in) 
{
    const resp_getTelemetryGeneralConfig_class_obj_t *p_resp_data = ((resp_getTelemetryGeneralConfig_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return tlm_general_cfg_make_from_buf(mp_obj_new_bytearray(sizeof(TELEMETRY_tlm_general_cfg_t), (const uint8_t *) &p_resp_data->class_data.data.sCfg));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getTelemetryGeneralConfig_get_cfg_obj, resp_getTelemetryGeneralConfig_get_cfg);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getTelemetryGeneralConfig_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_res), MP_ROM_PTR(&resp_getTelemetryGeneralConfig_get_res_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_cfg), MP_ROM_PTR(&resp_getTelemetryGeneralConfig_get_cfg_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getTelemetryGeneralConfig_locals_dict, resp_getTelemetryGeneralConfig_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_telemetrygetTelemetryGeneralConfigResponseData,
    MP_QSTR_resp_getTelemetryGeneralConfig,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getTelemetryGeneralConfig_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getTelemetryGeneralConfig_locals_dict    
);

// uPy request function for method 'setTelemetryGeneralConfig'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrysetTelemetryGeneralConfigRequestData_t data;
} req_setTelemetryGeneralConfig_fp_t;

STATIC mp_obj_t req_setTelemetryGeneralConfig(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_setTelemetryGeneralConfig_fp_t * p_req_data = m_malloc(sizeof(req_setTelemetryGeneralConfig_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'setTelemetryGeneralConfig' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 258;
    p_req_data->fp_hdr.func_id = 1;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eTlm_instance_id = (uint8_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.sCfg = ((tlm_general_cfg_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_setTelemetryGeneralConfig_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'setTelemetryGeneralConfig'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrysetTelemetryGeneralConfigResponseData_t data;
} resp_setTelemetryGeneralConfig_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_setTelemetryGeneralConfig_fp_t class_data;
} resp_setTelemetryGeneralConfig_class_obj_t;

STATIC mp_obj_t resp_setTelemetryGeneralConfig_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_setTelemetryGeneralConfig_class_obj_t *p_self = m_new_obj(resp_setTelemetryGeneralConfig_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_setTelemetryGeneralConfig_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_setTelemetryGeneralConfig_fp_t *p_data = (resp_setTelemetryGeneralConfig_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "setTelemetryGeneralConfig" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_setTelemetryGeneralConfig_get_res(mp_obj_t self_in) 
{
    const resp_setTelemetryGeneralConfig_class_obj_t *p_resp_data = ((resp_setTelemetryGeneralConfig_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eRes);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_setTelemetryGeneralConfig_get_res_obj, resp_setTelemetryGeneralConfig_get_res);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_setTelemetryGeneralConfig_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_res), MP_ROM_PTR(&resp_setTelemetryGeneralConfig_get_res_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_setTelemetryGeneralConfig_locals_dict, resp_setTelemetryGeneralConfig_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_telemetrysetTelemetryGeneralConfigResponseData,
    MP_QSTR_resp_setTelemetryGeneralConfig,
    MP_TYPE_FLAG_NONE,
    make_new, resp_setTelemetryGeneralConfig_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_setTelemetryGeneralConfig_locals_dict    
);

// uPy request function for method 'getTelemetryPresetConfig'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrygetTelemetryPresetConfigRequestData_t data;
} req_getTelemetryPresetConfig_fp_t;

STATIC mp_obj_t req_getTelemetryPresetConfig(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_getTelemetryPresetConfig_fp_t * p_req_data = m_malloc(sizeof(req_getTelemetryPresetConfig_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getTelemetryPresetConfig' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 258;
    p_req_data->fp_hdr.func_id = 2;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eTlm_instance_id = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getTelemetryPresetConfig_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getTelemetryPresetConfig'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrygetTelemetryPresetConfigResponseData_t data;
} resp_getTelemetryPresetConfig_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getTelemetryPresetConfig_fp_t class_data;
} resp_getTelemetryPresetConfig_class_obj_t;

STATIC mp_obj_t resp_getTelemetryPresetConfig_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getTelemetryPresetConfig_class_obj_t *p_self = m_new_obj(resp_getTelemetryPresetConfig_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getTelemetryPresetConfig_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getTelemetryPresetConfig_fp_t *p_data = (resp_getTelemetryPresetConfig_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "getTelemetryPresetConfig" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getTelemetryPresetConfig_get_res(mp_obj_t self_in) 
{
    const resp_getTelemetryPresetConfig_class_obj_t *p_resp_data = ((resp_getTelemetryPresetConfig_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eRes);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getTelemetryPresetConfig_get_res_obj, resp_getTelemetryPresetConfig_get_res);

STATIC mp_obj_t resp_getTelemetryPresetConfig_get_slot_preset_cnt(mp_obj_t self_in) 
{
    const resp_getTelemetryPresetConfig_class_obj_t *p_resp_data = ((resp_getTelemetryPresetConfig_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.u8Slot_preset_cnt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getTelemetryPresetConfig_get_slot_preset_cnt_obj, resp_getTelemetryPresetConfig_get_slot_preset_cnt);

STATIC mp_obj_t resp_getTelemetryPresetConfig_get_max_tlm_msg_cnt(mp_obj_t self_in) 
{
    const resp_getTelemetryPresetConfig_class_obj_t *p_resp_data = ((resp_getTelemetryPresetConfig_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.u8Max_tlm_msg_cnt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getTelemetryPresetConfig_get_max_tlm_msg_cnt_obj, resp_getTelemetryPresetConfig_get_max_tlm_msg_cnt);

STATIC mp_obj_t resp_getTelemetryPresetConfig_get_Telemetry_preset_cfg(mp_obj_t self_in) 
{
    const resp_getTelemetryPresetConfig_class_obj_t *p_resp_data = ((resp_getTelemetryPresetConfig_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return upy_sd_copy_fidl_scalar_array_to_py_list_TELEMETRY_tlm_preset_cfg_t(p_resp_data->class_data.data.asTelemetry_preset_cfg, 30);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getTelemetryPresetConfig_get_Telemetry_preset_cfg_obj, resp_getTelemetryPresetConfig_get_Telemetry_preset_cfg);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getTelemetryPresetConfig_locals_dict_table[4] = {
    { MP_ROM_QSTR(MP_QSTR_get_res), MP_ROM_PTR(&resp_getTelemetryPresetConfig_get_res_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_slot_preset_cnt), MP_ROM_PTR(&resp_getTelemetryPresetConfig_get_slot_preset_cnt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_max_tlm_msg_cnt), MP_ROM_PTR(&resp_getTelemetryPresetConfig_get_max_tlm_msg_cnt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Telemetry_preset_cfg), MP_ROM_PTR(&resp_getTelemetryPresetConfig_get_Telemetry_preset_cfg_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getTelemetryPresetConfig_locals_dict, resp_getTelemetryPresetConfig_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_telemetrygetTelemetryPresetConfigResponseData,
    MP_QSTR_resp_getTelemetryPresetConfig,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getTelemetryPresetConfig_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getTelemetryPresetConfig_locals_dict    
);

// uPy request function for method 'setTelemetryPresetConfig'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrysetTelemetryPresetConfigRequestData_t data;
} req_setTelemetryPresetConfig_fp_t;

STATIC mp_obj_t req_setTelemetryPresetConfig(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_setTelemetryPresetConfig_fp_t * p_req_data = m_malloc(sizeof(req_setTelemetryPresetConfig_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'setTelemetryPresetConfig' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 258;
    p_req_data->fp_hdr.func_id = 3;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eTlm_instance_id = (uint8_t) mp_obj_get_int(p_args[0]);
    upy_sd_copy_fidl_scalar_array_from_py_list_TELEMETRY_tlm_preset_cfg_t(p_req_data->data.asTelemetry_preset_cfg, 30, p_args[1]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_setTelemetryPresetConfig_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'setTelemetryPresetConfig'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrysetTelemetryPresetConfigResponseData_t data;
} resp_setTelemetryPresetConfig_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_setTelemetryPresetConfig_fp_t class_data;
} resp_setTelemetryPresetConfig_class_obj_t;

STATIC mp_obj_t resp_setTelemetryPresetConfig_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_setTelemetryPresetConfig_class_obj_t *p_self = m_new_obj(resp_setTelemetryPresetConfig_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_setTelemetryPresetConfig_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_setTelemetryPresetConfig_fp_t *p_data = (resp_setTelemetryPresetConfig_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "setTelemetryPresetConfig" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_setTelemetryPresetConfig_get_res(mp_obj_t self_in) 
{
    const resp_setTelemetryPresetConfig_class_obj_t *p_resp_data = ((resp_setTelemetryPresetConfig_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eRes);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_setTelemetryPresetConfig_get_res_obj, resp_setTelemetryPresetConfig_get_res);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_setTelemetryPresetConfig_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_res), MP_ROM_PTR(&resp_setTelemetryPresetConfig_get_res_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_setTelemetryPresetConfig_locals_dict, resp_setTelemetryPresetConfig_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_telemetrysetTelemetryPresetConfigResponseData,
    MP_QSTR_resp_setTelemetryPresetConfig,
    MP_TYPE_FLAG_NONE,
    make_new, resp_setTelemetryPresetConfig_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_setTelemetryPresetConfig_locals_dict    
);

// uPy request function for method 'setActivePreset'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrysetActivePresetRequestData_t data;
} req_setActivePreset_fp_t;

STATIC mp_obj_t req_setActivePreset(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_setActivePreset_fp_t * p_req_data = m_malloc(sizeof(req_setActivePreset_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'setActivePreset' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 258;
    p_req_data->fp_hdr.func_id = 4;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eTlm_instance_id = (uint8_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.u8Req_active_preset = (uint8_t) mp_obj_get_int(p_args[1]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_setActivePreset_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'setActivePreset'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrysetActivePresetResponseData_t data;
} resp_setActivePreset_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_setActivePreset_fp_t class_data;
} resp_setActivePreset_class_obj_t;

STATIC mp_obj_t resp_setActivePreset_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_setActivePreset_class_obj_t *p_self = m_new_obj(resp_setActivePreset_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_setActivePreset_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_setActivePreset_fp_t *p_data = (resp_setActivePreset_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "setActivePreset" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_setActivePreset_get_res(mp_obj_t self_in) 
{
    const resp_setActivePreset_class_obj_t *p_resp_data = ((resp_setActivePreset_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eRes);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_setActivePreset_get_res_obj, resp_setActivePreset_get_res);

STATIC mp_obj_t resp_setActivePreset_get_avail_presets_cnt(mp_obj_t self_in) 
{
    const resp_setActivePreset_class_obj_t *p_resp_data = ((resp_setActivePreset_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.u8Avail_presets_cnt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_setActivePreset_get_avail_presets_cnt_obj, resp_setActivePreset_get_avail_presets_cnt);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_setActivePreset_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_res), MP_ROM_PTR(&resp_setActivePreset_get_res_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_avail_presets_cnt), MP_ROM_PTR(&resp_setActivePreset_get_avail_presets_cnt_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_setActivePreset_locals_dict, resp_setActivePreset_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_telemetrysetActivePresetResponseData,
    MP_QSTR_resp_setActivePreset,
    MP_TYPE_FLAG_NONE,
    make_new, resp_setActivePreset_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_setActivePreset_locals_dict    
);

// uPy request function for method 'getActivePreset'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrygetActivePresetRequestData_t data;
} req_getActivePreset_fp_t;

STATIC mp_obj_t req_getActivePreset(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_getActivePreset_fp_t * p_req_data = m_malloc(sizeof(req_getActivePreset_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getActivePreset' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 258;
    p_req_data->fp_hdr.func_id = 5;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eTlm_instance_id = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getActivePreset_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getActivePreset'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrygetActivePresetResponseData_t data;
} resp_getActivePreset_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getActivePreset_fp_t class_data;
} resp_getActivePreset_class_obj_t;

STATIC mp_obj_t resp_getActivePreset_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getActivePreset_class_obj_t *p_self = m_new_obj(resp_getActivePreset_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getActivePreset_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getActivePreset_fp_t *p_data = (resp_getActivePreset_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "getActivePreset" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getActivePreset_get_res(mp_obj_t self_in) 
{
    const resp_getActivePreset_class_obj_t *p_resp_data = ((resp_getActivePreset_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eRes);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getActivePreset_get_res_obj, resp_getActivePreset_get_res);

STATIC mp_obj_t resp_getActivePreset_get_active_preset_id(mp_obj_t self_in) 
{
    const resp_getActivePreset_class_obj_t *p_resp_data = ((resp_getActivePreset_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.u8Active_preset_id);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getActivePreset_get_active_preset_id_obj, resp_getActivePreset_get_active_preset_id);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getActivePreset_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_res), MP_ROM_PTR(&resp_getActivePreset_get_res_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_active_preset_id), MP_ROM_PTR(&resp_getActivePreset_get_active_preset_id_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getActivePreset_locals_dict, resp_getActivePreset_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_telemetrygetActivePresetResponseData,
    MP_QSTR_resp_getActivePreset,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getActivePreset_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getActivePreset_locals_dict    
);

// uPy request function for method 'restoreActivePreset'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetryrestoreActivePresetRequestData_t data;
} req_restoreActivePreset_fp_t;

STATIC mp_obj_t req_restoreActivePreset(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_restoreActivePreset_fp_t * p_req_data = m_malloc(sizeof(req_restoreActivePreset_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'restoreActivePreset' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 258;
    p_req_data->fp_hdr.func_id = 6;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eTlm_instance_id = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_restoreActivePreset_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'restoreActivePreset'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetryrestoreActivePresetResponseData_t data;
} resp_restoreActivePreset_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_restoreActivePreset_fp_t class_data;
} resp_restoreActivePreset_class_obj_t;

STATIC mp_obj_t resp_restoreActivePreset_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_restoreActivePreset_class_obj_t *p_self = m_new_obj(resp_restoreActivePreset_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_restoreActivePreset_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_restoreActivePreset_fp_t *p_data = (resp_restoreActivePreset_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "restoreActivePreset" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_restoreActivePreset_get_res(mp_obj_t self_in) 
{
    const resp_restoreActivePreset_class_obj_t *p_resp_data = ((resp_restoreActivePreset_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eRes);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_restoreActivePreset_get_res_obj, resp_restoreActivePreset_get_res);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_restoreActivePreset_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_res), MP_ROM_PTR(&resp_restoreActivePreset_get_res_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_restoreActivePreset_locals_dict, resp_restoreActivePreset_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_telemetryrestoreActivePresetResponseData,
    MP_QSTR_resp_restoreActivePreset,
    MP_TYPE_FLAG_NONE,
    make_new, resp_restoreActivePreset_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_restoreActivePreset_locals_dict    
);

// uPy request function for method 'getTelemetryFileSinkConfig'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrygetTelemetryFileSinkConfigRequestData_t data;
} req_getTelemetryFileSinkConfig_fp_t;

STATIC mp_obj_t req_getTelemetryFileSinkConfig(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_getTelemetryFileSinkConfig_fp_t * p_req_data = m_malloc(sizeof(req_getTelemetryFileSinkConfig_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getTelemetryFileSinkConfig' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 258;
    p_req_data->fp_hdr.func_id = 7;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eTlm_instance_id = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getTelemetryFileSinkConfig_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getTelemetryFileSinkConfig'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrygetTelemetryFileSinkConfigResponseData_t data;
} resp_getTelemetryFileSinkConfig_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getTelemetryFileSinkConfig_fp_t class_data;
} resp_getTelemetryFileSinkConfig_class_obj_t;

STATIC mp_obj_t resp_getTelemetryFileSinkConfig_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getTelemetryFileSinkConfig_class_obj_t *p_self = m_new_obj(resp_getTelemetryFileSinkConfig_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getTelemetryFileSinkConfig_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getTelemetryFileSinkConfig_fp_t *p_data = (resp_getTelemetryFileSinkConfig_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "getTelemetryFileSinkConfig" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getTelemetryFileSinkConfig_get_res(mp_obj_t self_in) 
{
    const resp_getTelemetryFileSinkConfig_class_obj_t *p_resp_data = ((resp_getTelemetryFileSinkConfig_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eRes);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getTelemetryFileSinkConfig_get_res_obj, resp_getTelemetryFileSinkConfig_get_res);

STATIC mp_obj_t resp_getTelemetryFileSinkConfig_get_active_file_cfg_type(mp_obj_t self_in) 
{
    const resp_getTelemetryFileSinkConfig_class_obj_t *p_resp_data = ((resp_getTelemetryFileSinkConfig_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eActive_file_cfg_type);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getTelemetryFileSinkConfig_get_active_file_cfg_type_obj, resp_getTelemetryFileSinkConfig_get_active_file_cfg_type);

STATIC mp_obj_t resp_getTelemetryFileSinkConfig_get_size_limit_cfg(mp_obj_t self_in) 
{
    const resp_getTelemetryFileSinkConfig_class_obj_t *p_resp_data = ((resp_getTelemetryFileSinkConfig_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return tlm_file_size_limit_cfg_make_from_buf(mp_obj_new_bytearray(sizeof(TELEMETRY_tlm_file_size_limit_cfg_t), (const uint8_t *) &p_resp_data->class_data.data.sSize_limit_cfg));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getTelemetryFileSinkConfig_get_size_limit_cfg_obj, resp_getTelemetryFileSinkConfig_get_size_limit_cfg);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getTelemetryFileSinkConfig_locals_dict_table[3] = {
    { MP_ROM_QSTR(MP_QSTR_get_res), MP_ROM_PTR(&resp_getTelemetryFileSinkConfig_get_res_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_active_file_cfg_type), MP_ROM_PTR(&resp_getTelemetryFileSinkConfig_get_active_file_cfg_type_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_size_limit_cfg), MP_ROM_PTR(&resp_getTelemetryFileSinkConfig_get_size_limit_cfg_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getTelemetryFileSinkConfig_locals_dict, resp_getTelemetryFileSinkConfig_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_telemetrygetTelemetryFileSinkConfigResponseData,
    MP_QSTR_resp_getTelemetryFileSinkConfig,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getTelemetryFileSinkConfig_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getTelemetryFileSinkConfig_locals_dict    
);

// uPy request function for method 'setTelemetryFileSzLimitConfig'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrysetTelemetryFileSzLimitConfigRequestData_t data;
} req_setTelemetryFileSzLimitConfig_fp_t;

STATIC mp_obj_t req_setTelemetryFileSzLimitConfig(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_setTelemetryFileSzLimitConfig_fp_t * p_req_data = m_malloc(sizeof(req_setTelemetryFileSzLimitConfig_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'setTelemetryFileSzLimitConfig' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 258;
    p_req_data->fp_hdr.func_id = 8;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eTlm_instance_id = (uint8_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.sSize_limit_cfg = ((tlm_file_size_limit_cfg_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_setTelemetryFileSzLimitConfig_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'setTelemetryFileSzLimitConfig'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrysetTelemetryFileSzLimitConfigResponseData_t data;
} resp_setTelemetryFileSzLimitConfig_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_setTelemetryFileSzLimitConfig_fp_t class_data;
} resp_setTelemetryFileSzLimitConfig_class_obj_t;

STATIC mp_obj_t resp_setTelemetryFileSzLimitConfig_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_setTelemetryFileSzLimitConfig_class_obj_t *p_self = m_new_obj(resp_setTelemetryFileSzLimitConfig_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_setTelemetryFileSzLimitConfig_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_setTelemetryFileSzLimitConfig_fp_t *p_data = (resp_setTelemetryFileSzLimitConfig_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "setTelemetryFileSzLimitConfig" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_setTelemetryFileSzLimitConfig_get_res(mp_obj_t self_in) 
{
    const resp_setTelemetryFileSzLimitConfig_class_obj_t *p_resp_data = ((resp_setTelemetryFileSzLimitConfig_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eRes);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_setTelemetryFileSzLimitConfig_get_res_obj, resp_setTelemetryFileSzLimitConfig_get_res);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_setTelemetryFileSzLimitConfig_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_res), MP_ROM_PTR(&resp_setTelemetryFileSzLimitConfig_get_res_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_setTelemetryFileSzLimitConfig_locals_dict, resp_setTelemetryFileSzLimitConfig_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_telemetrysetTelemetryFileSzLimitConfigResponseData,
    MP_QSTR_resp_setTelemetryFileSzLimitConfig,
    MP_TYPE_FLAG_NONE,
    make_new, resp_setTelemetryFileSzLimitConfig_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_setTelemetryFileSzLimitConfig_locals_dict    
);

// uPy request function for method 'cleanTelemetryFiles'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrycleanTelemetryFilesRequestData_t data;
} req_cleanTelemetryFiles_fp_t;

STATIC mp_obj_t req_cleanTelemetryFiles(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_cleanTelemetryFiles_fp_t * p_req_data = m_malloc(sizeof(req_cleanTelemetryFiles_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'cleanTelemetryFiles' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 258;
    p_req_data->fp_hdr.func_id = 11;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eTlm_instance_id = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_cleanTelemetryFiles_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'cleanTelemetryFiles'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrycleanTelemetryFilesResponseData_t data;
} resp_cleanTelemetryFiles_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_cleanTelemetryFiles_fp_t class_data;
} resp_cleanTelemetryFiles_class_obj_t;

STATIC mp_obj_t resp_cleanTelemetryFiles_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_cleanTelemetryFiles_class_obj_t *p_self = m_new_obj(resp_cleanTelemetryFiles_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_cleanTelemetryFiles_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_cleanTelemetryFiles_fp_t *p_data = (resp_cleanTelemetryFiles_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "cleanTelemetryFiles" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_cleanTelemetryFiles_get_res(mp_obj_t self_in) 
{
    const resp_cleanTelemetryFiles_class_obj_t *p_resp_data = ((resp_cleanTelemetryFiles_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eRes);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_cleanTelemetryFiles_get_res_obj, resp_cleanTelemetryFiles_get_res);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_cleanTelemetryFiles_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_res), MP_ROM_PTR(&resp_cleanTelemetryFiles_get_res_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_cleanTelemetryFiles_locals_dict, resp_cleanTelemetryFiles_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_telemetrycleanTelemetryFilesResponseData,
    MP_QSTR_resp_cleanTelemetryFiles,
    MP_TYPE_FLAG_NONE,
    make_new, resp_cleanTelemetryFiles_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_cleanTelemetryFiles_locals_dict    
);

// uPy request function for method 'getTelemetryOperationStats'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrygetTelemetryOperationStatsRequestData_t data;
} req_getTelemetryOperationStats_fp_t;

STATIC mp_obj_t req_getTelemetryOperationStats(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_getTelemetryOperationStats_fp_t * p_req_data = m_malloc(sizeof(req_getTelemetryOperationStats_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getTelemetryOperationStats' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 258;
    p_req_data->fp_hdr.func_id = 12;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eTlm_instance_id = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getTelemetryOperationStats_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getTelemetryOperationStats'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrygetTelemetryOperationStatsResponseData_t data;
} resp_getTelemetryOperationStats_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getTelemetryOperationStats_fp_t class_data;
} resp_getTelemetryOperationStats_class_obj_t;

STATIC mp_obj_t resp_getTelemetryOperationStats_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getTelemetryOperationStats_class_obj_t *p_self = m_new_obj(resp_getTelemetryOperationStats_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getTelemetryOperationStats_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getTelemetryOperationStats_fp_t *p_data = (resp_getTelemetryOperationStats_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "getTelemetryOperationStats" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getTelemetryOperationStats_get_res(mp_obj_t self_in) 
{
    const resp_getTelemetryOperationStats_class_obj_t *p_resp_data = ((resp_getTelemetryOperationStats_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eRes);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getTelemetryOperationStats_get_res_obj, resp_getTelemetryOperationStats_get_res);

STATIC mp_obj_t resp_getTelemetryOperationStats_get_telemetry_stats(mp_obj_t self_in) 
{
    const resp_getTelemetryOperationStats_class_obj_t *p_resp_data = ((resp_getTelemetryOperationStats_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return tlm_stats_make_from_buf(mp_obj_new_bytearray(sizeof(TELEMETRY_tlm_stats_t), (const uint8_t *) &p_resp_data->class_data.data.sTelemetry_stats));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getTelemetryOperationStats_get_telemetry_stats_obj, resp_getTelemetryOperationStats_get_telemetry_stats);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getTelemetryOperationStats_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_res), MP_ROM_PTR(&resp_getTelemetryOperationStats_get_res_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_telemetry_stats), MP_ROM_PTR(&resp_getTelemetryOperationStats_get_telemetry_stats_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getTelemetryOperationStats_locals_dict, resp_getTelemetryOperationStats_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_telemetrygetTelemetryOperationStatsResponseData,
    MP_QSTR_resp_getTelemetryOperationStats,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getTelemetryOperationStats_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getTelemetryOperationStats_locals_dict    
);

// uPy request function for method 'startTelemetry'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrystartTelemetryRequestData_t data;
} req_startTelemetry_fp_t;

STATIC mp_obj_t req_startTelemetry(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_startTelemetry_fp_t * p_req_data = m_malloc(sizeof(req_startTelemetry_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'startTelemetry' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 258;
    p_req_data->fp_hdr.func_id = 13;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eTlm_instance_id = (uint8_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.u16Hold_time_sec = (uint16_t) mp_obj_get_int(p_args[1]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_startTelemetry_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'startTelemetry'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrystartTelemetryResponseData_t data;
} resp_startTelemetry_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_startTelemetry_fp_t class_data;
} resp_startTelemetry_class_obj_t;

STATIC mp_obj_t resp_startTelemetry_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_startTelemetry_class_obj_t *p_self = m_new_obj(resp_startTelemetry_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_startTelemetry_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_startTelemetry_fp_t *p_data = (resp_startTelemetry_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "startTelemetry" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_startTelemetry_get_res(mp_obj_t self_in) 
{
    const resp_startTelemetry_class_obj_t *p_resp_data = ((resp_startTelemetry_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eRes);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_startTelemetry_get_res_obj, resp_startTelemetry_get_res);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_startTelemetry_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_res), MP_ROM_PTR(&resp_startTelemetry_get_res_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_startTelemetry_locals_dict, resp_startTelemetry_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_telemetrystartTelemetryResponseData,
    MP_QSTR_resp_startTelemetry,
    MP_TYPE_FLAG_NONE,
    make_new, resp_startTelemetry_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_startTelemetry_locals_dict    
);

// uPy request function for method 'stopTelemetry'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrystopTelemetryRequestData_t data;
} req_stopTelemetry_fp_t;

STATIC mp_obj_t req_stopTelemetry(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_stopTelemetry_fp_t * p_req_data = m_malloc(sizeof(req_stopTelemetry_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'stopTelemetry' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 258;
    p_req_data->fp_hdr.func_id = 14;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eTlm_instance_id = (uint8_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.u16Hold_time_sec = (uint16_t) mp_obj_get_int(p_args[1]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_stopTelemetry_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'stopTelemetry'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    telemetrystopTelemetryResponseData_t data;
} resp_stopTelemetry_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_stopTelemetry_fp_t class_data;
} resp_stopTelemetry_class_obj_t;

STATIC mp_obj_t resp_stopTelemetry_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_stopTelemetry_class_obj_t *p_self = m_new_obj(resp_stopTelemetry_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_stopTelemetry_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_stopTelemetry_fp_t *p_data = (resp_stopTelemetry_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "stopTelemetry" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_stopTelemetry_get_res(mp_obj_t self_in) 
{
    const resp_stopTelemetry_class_obj_t *p_resp_data = ((resp_stopTelemetry_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eRes);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_stopTelemetry_get_res_obj, resp_stopTelemetry_get_res);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_stopTelemetry_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_res), MP_ROM_PTR(&resp_stopTelemetry_get_res_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_stopTelemetry_locals_dict, resp_stopTelemetry_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_telemetrystopTelemetryResponseData,
    MP_QSTR_resp_stopTelemetry,
    MP_TYPE_FLAG_NONE,
    make_new, resp_stopTelemetry_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_stopTelemetry_locals_dict    
);


/**********************************************************************
 *
 *  uPy function reference definitions
 *
 **********************************************************************/
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_getTelemetryGeneralConfig_obj, 1, req_getTelemetryGeneralConfig);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_setTelemetryGeneralConfig_obj, 2, req_setTelemetryGeneralConfig);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_getTelemetryPresetConfig_obj, 1, req_getTelemetryPresetConfig);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_setTelemetryPresetConfig_obj, 2, req_setTelemetryPresetConfig);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_setActivePreset_obj, 2, req_setActivePreset);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_getActivePreset_obj, 1, req_getActivePreset);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_restoreActivePreset_obj, 1, req_restoreActivePreset);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_getTelemetryFileSinkConfig_obj, 1, req_getTelemetryFileSinkConfig);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_setTelemetryFileSzLimitConfig_obj, 2, req_setTelemetryFileSzLimitConfig);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_cleanTelemetryFiles_obj, 1, req_cleanTelemetryFiles);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_getTelemetryOperationStats_obj, 1, req_getTelemetryOperationStats);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_startTelemetry_obj, 2, req_startTelemetry);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_stopTelemetry_obj, 2, req_stopTelemetry);

STATIC const mp_rom_map_elem_t upy_telemetry_module_globals_table[38] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_upy_telemetry) },
    // export FIDL methods
    // export request serializer function for method 'getTelemetryGeneralConfig'
    { MP_ROM_QSTR(MP_QSTR_req_getTelemetryGeneralConfig), MP_ROM_PTR(&req_getTelemetryGeneralConfig_obj) },
    // export class for method 'getTelemetryGeneralConfig' response
    { MP_ROM_QSTR(MP_QSTR_resp_getTelemetryGeneralConfig), MP_ROM_PTR(&mp_type_telemetrygetTelemetryGeneralConfigResponseData) },
    // export request serializer function for method 'setTelemetryGeneralConfig'
    { MP_ROM_QSTR(MP_QSTR_req_setTelemetryGeneralConfig), MP_ROM_PTR(&req_setTelemetryGeneralConfig_obj) },
    // export class for method 'setTelemetryGeneralConfig' response
    { MP_ROM_QSTR(MP_QSTR_resp_setTelemetryGeneralConfig), MP_ROM_PTR(&mp_type_telemetrysetTelemetryGeneralConfigResponseData) },
    // export request serializer function for method 'getTelemetryPresetConfig'
    { MP_ROM_QSTR(MP_QSTR_req_getTelemetryPresetConfig), MP_ROM_PTR(&req_getTelemetryPresetConfig_obj) },
    // export class for method 'getTelemetryPresetConfig' response
    { MP_ROM_QSTR(MP_QSTR_resp_getTelemetryPresetConfig), MP_ROM_PTR(&mp_type_telemetrygetTelemetryPresetConfigResponseData) },
    // export request serializer function for method 'setTelemetryPresetConfig'
    { MP_ROM_QSTR(MP_QSTR_req_setTelemetryPresetConfig), MP_ROM_PTR(&req_setTelemetryPresetConfig_obj) },
    // export class for method 'setTelemetryPresetConfig' response
    { MP_ROM_QSTR(MP_QSTR_resp_setTelemetryPresetConfig), MP_ROM_PTR(&mp_type_telemetrysetTelemetryPresetConfigResponseData) },
    // export request serializer function for method 'setActivePreset'
    { MP_ROM_QSTR(MP_QSTR_req_setActivePreset), MP_ROM_PTR(&req_setActivePreset_obj) },
    // export class for method 'setActivePreset' response
    { MP_ROM_QSTR(MP_QSTR_resp_setActivePreset), MP_ROM_PTR(&mp_type_telemetrysetActivePresetResponseData) },
    // export request serializer function for method 'getActivePreset'
    { MP_ROM_QSTR(MP_QSTR_req_getActivePreset), MP_ROM_PTR(&req_getActivePreset_obj) },
    // export class for method 'getActivePreset' response
    { MP_ROM_QSTR(MP_QSTR_resp_getActivePreset), MP_ROM_PTR(&mp_type_telemetrygetActivePresetResponseData) },
    // export request serializer function for method 'restoreActivePreset'
    { MP_ROM_QSTR(MP_QSTR_req_restoreActivePreset), MP_ROM_PTR(&req_restoreActivePreset_obj) },
    // export class for method 'restoreActivePreset' response
    { MP_ROM_QSTR(MP_QSTR_resp_restoreActivePreset), MP_ROM_PTR(&mp_type_telemetryrestoreActivePresetResponseData) },
    // export request serializer function for method 'getTelemetryFileSinkConfig'
    { MP_ROM_QSTR(MP_QSTR_req_getTelemetryFileSinkConfig), MP_ROM_PTR(&req_getTelemetryFileSinkConfig_obj) },
    // export class for method 'getTelemetryFileSinkConfig' response
    { MP_ROM_QSTR(MP_QSTR_resp_getTelemetryFileSinkConfig), MP_ROM_PTR(&mp_type_telemetrygetTelemetryFileSinkConfigResponseData) },
    // export request serializer function for method 'setTelemetryFileSzLimitConfig'
    { MP_ROM_QSTR(MP_QSTR_req_setTelemetryFileSzLimitConfig), MP_ROM_PTR(&req_setTelemetryFileSzLimitConfig_obj) },
    // export class for method 'setTelemetryFileSzLimitConfig' response
    { MP_ROM_QSTR(MP_QSTR_resp_setTelemetryFileSzLimitConfig), MP_ROM_PTR(&mp_type_telemetrysetTelemetryFileSzLimitConfigResponseData) },
    // export request serializer function for method 'cleanTelemetryFiles'
    { MP_ROM_QSTR(MP_QSTR_req_cleanTelemetryFiles), MP_ROM_PTR(&req_cleanTelemetryFiles_obj) },
    // export class for method 'cleanTelemetryFiles' response
    { MP_ROM_QSTR(MP_QSTR_resp_cleanTelemetryFiles), MP_ROM_PTR(&mp_type_telemetrycleanTelemetryFilesResponseData) },
    // export request serializer function for method 'getTelemetryOperationStats'
    { MP_ROM_QSTR(MP_QSTR_req_getTelemetryOperationStats), MP_ROM_PTR(&req_getTelemetryOperationStats_obj) },
    // export class for method 'getTelemetryOperationStats' response
    { MP_ROM_QSTR(MP_QSTR_resp_getTelemetryOperationStats), MP_ROM_PTR(&mp_type_telemetrygetTelemetryOperationStatsResponseData) },
    // export request serializer function for method 'startTelemetry'
    { MP_ROM_QSTR(MP_QSTR_req_startTelemetry), MP_ROM_PTR(&req_startTelemetry_obj) },
    // export class for method 'startTelemetry' response
    { MP_ROM_QSTR(MP_QSTR_resp_startTelemetry), MP_ROM_PTR(&mp_type_telemetrystartTelemetryResponseData) },
    // export request serializer function for method 'stopTelemetry'
    { MP_ROM_QSTR(MP_QSTR_req_stopTelemetry), MP_ROM_PTR(&req_stopTelemetry_obj) },
    // export class for method 'stopTelemetry' response
    { MP_ROM_QSTR(MP_QSTR_resp_stopTelemetry), MP_ROM_PTR(&mp_type_telemetrystopTelemetryResponseData) },
    // export enumeration class for type 'tlm_file_logging_type'
    { MP_ROM_QSTR(MP_QSTR_tlm_file_logging_type), MP_ROM_PTR(&tlm_file_logging_type_class_type) },                        
    // export enumeration class for type 'TelemetryInstance'
    { MP_ROM_QSTR(MP_QSTR_TelemetryInstance), MP_ROM_PTR(&telemetryinstance_class_type) },                        
    // export enumeration class for type 'StandardResult'
    { MP_ROM_QSTR(MP_QSTR_StandardResult), MP_ROM_PTR(&standardresult_class_type) },                        
    // export struct class objects for type 'tlm_preset_cfg'
    { MP_ROM_QSTR(MP_QSTR_tlm_preset_cfg_make_from_buf), MP_ROM_PTR(&tlm_preset_cfg_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_tlm_preset_cfg), MP_ROM_PTR(&tlm_preset_cfg_type)},
    // export struct class objects for type 'tlm_file_size_limit_cfg'
    { MP_ROM_QSTR(MP_QSTR_tlm_file_size_limit_cfg_make_from_buf), MP_ROM_PTR(&tlm_file_size_limit_cfg_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_tlm_file_size_limit_cfg), MP_ROM_PTR(&tlm_file_size_limit_cfg_type)},
    // export struct class objects for type 'tlm_general_cfg'
    { MP_ROM_QSTR(MP_QSTR_tlm_general_cfg_make_from_buf), MP_ROM_PTR(&tlm_general_cfg_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_tlm_general_cfg), MP_ROM_PTR(&tlm_general_cfg_type)},
    // export struct class objects for type 'tlm_stats'
    { MP_ROM_QSTR(MP_QSTR_tlm_stats_make_from_buf), MP_ROM_PTR(&tlm_stats_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_tlm_stats), MP_ROM_PTR(&tlm_stats_type)},
};

/**********************************************************************
 *
 *  uPy C module registration
 *
 **********************************************************************/
STATIC MP_DEFINE_CONST_DICT(upy_telemetry_module_globals,
                            upy_telemetry_module_globals_table);

const mp_obj_module_t upy_telemetry_user_cmodule = {
    .base    = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&upy_telemetry_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_upy_telemetry, upy_telemetry_user_cmodule);
