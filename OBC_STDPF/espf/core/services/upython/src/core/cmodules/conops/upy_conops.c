/*!
********************************************************************************************
* @file upy_conops.c
* @brief uPy C bindings generator
********************************************************************************************
* @version           interface conops v2.0
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
 * @defgroup conops conops
 * @{
 *
 * Concept of Operations control and configuration interface
 *
 * @file upy_conops.c
 * @brief conops uPython C wrapper module implementation
 *
 * This module is fully generated from a FIDL file and represents a uPython C extension module which
 * registers specific classes related to the communication interfaces of the conops API. Users of
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
#include "FP_conopsProtocolTypes.h"

/**********************************************************************
 *
 *  uPy class definitions for struct types
 *
 **********************************************************************/

/**********************************************************************
 *
 *  uPy class definition for struct 'ThresholdValues'
 *
 **********************************************************************/
    
// class structure for type ThresholdValues
typedef struct 
{
    mp_obj_base_t base;
    CONOPS_ThresholdValues_t class_data;
} PACKED_STRUCT ThresholdValues_class_obj_t;

// ThresholdValues class constructor from field arguments
STATIC mp_obj_t ThresholdValues_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 7, 7, false);
    
    ThresholdValues_class_obj_t *p_self = m_new_obj(ThresholdValues_class_obj_t);
    p_self->base.type = type;
    
    // v_batt_safe
    p_self->class_data.i32V_batt_safe = (int32_t) mp_obj_get_int(p_args[0]);
    // t_batt_safe_lower
    p_self->class_data.i32T_batt_safe_lower = (int32_t) mp_obj_get_int(p_args[1]);
    // t_batt_safe_upper
    p_self->class_data.i32T_batt_safe_upper = (int32_t) mp_obj_get_int(p_args[2]);
    // ang_vel_max
    p_self->class_data.i32Ang_vel_max = (int32_t) mp_obj_get_int(p_args[3]);
    // ang_vel_low
    p_self->class_data.i32Ang_vel_low = (int32_t) mp_obj_get_int(p_args[4]);
    // ang_vel_y_thom_high
    p_self->class_data.i32Ang_vel_y_thom_high = (int32_t) mp_obj_get_int(p_args[5]);
    // ang_vel_y_thom_low
    p_self->class_data.i32Ang_vel_y_thom_low = (int32_t) mp_obj_get_int(p_args[6]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'ThresholdValues' getters
//

STATIC mp_obj_t ThresholdValues_get_v_batt_safe(mp_obj_t self_in) 
{
    const ThresholdValues_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.i32V_batt_safe);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ThresholdValues_get_v_batt_safe_obj, ThresholdValues_get_v_batt_safe);

STATIC mp_obj_t ThresholdValues_get_t_batt_safe_lower(mp_obj_t self_in) 
{
    const ThresholdValues_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.i32T_batt_safe_lower);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ThresholdValues_get_t_batt_safe_lower_obj, ThresholdValues_get_t_batt_safe_lower);

STATIC mp_obj_t ThresholdValues_get_t_batt_safe_upper(mp_obj_t self_in) 
{
    const ThresholdValues_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.i32T_batt_safe_upper);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ThresholdValues_get_t_batt_safe_upper_obj, ThresholdValues_get_t_batt_safe_upper);

STATIC mp_obj_t ThresholdValues_get_ang_vel_max(mp_obj_t self_in) 
{
    const ThresholdValues_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.i32Ang_vel_max);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ThresholdValues_get_ang_vel_max_obj, ThresholdValues_get_ang_vel_max);

STATIC mp_obj_t ThresholdValues_get_ang_vel_low(mp_obj_t self_in) 
{
    const ThresholdValues_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.i32Ang_vel_low);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ThresholdValues_get_ang_vel_low_obj, ThresholdValues_get_ang_vel_low);

STATIC mp_obj_t ThresholdValues_get_ang_vel_y_thom_high(mp_obj_t self_in) 
{
    const ThresholdValues_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.i32Ang_vel_y_thom_high);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ThresholdValues_get_ang_vel_y_thom_high_obj, ThresholdValues_get_ang_vel_y_thom_high);

STATIC mp_obj_t ThresholdValues_get_ang_vel_y_thom_low(mp_obj_t self_in) 
{
    const ThresholdValues_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.i32Ang_vel_y_thom_low);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ThresholdValues_get_ang_vel_y_thom_low_obj, ThresholdValues_get_ang_vel_y_thom_low);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t ThresholdValues_locals_dict_table[7] = {
    { MP_ROM_QSTR(MP_QSTR_get_v_batt_safe), MP_ROM_PTR(&ThresholdValues_get_v_batt_safe_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_t_batt_safe_lower), MP_ROM_PTR(&ThresholdValues_get_t_batt_safe_lower_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_t_batt_safe_upper), MP_ROM_PTR(&ThresholdValues_get_t_batt_safe_upper_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ang_vel_max), MP_ROM_PTR(&ThresholdValues_get_ang_vel_max_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ang_vel_low), MP_ROM_PTR(&ThresholdValues_get_ang_vel_low_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ang_vel_y_thom_high), MP_ROM_PTR(&ThresholdValues_get_ang_vel_y_thom_high_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ang_vel_y_thom_low), MP_ROM_PTR(&ThresholdValues_get_ang_vel_y_thom_low_obj) },
};

STATIC MP_DEFINE_CONST_DICT(ThresholdValues_locals_dict, ThresholdValues_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    ThresholdValues_type,
    MP_QSTR_ThresholdValues,
    MP_TYPE_FLAG_NONE,
    make_new, ThresholdValues_make_new,
    locals_dict, (mp_obj_dict_t*)&ThresholdValues_locals_dict
);

STATIC mp_obj_t ThresholdValues_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CONOPS_ThresholdValues_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    ThresholdValues_class_obj_t *p_self = m_new_obj(ThresholdValues_class_obj_t);
    p_self->base.type = &ThresholdValues_type;
    
    const CONOPS_ThresholdValues_t *p_data = (const CONOPS_ThresholdValues_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// ThresholdValues class constructor from a byte buffer
STATIC mp_obj_t ThresholdValues_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return ThresholdValues_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CONOPS_ThresholdValues_t, ThresholdValues_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CONOPS_ThresholdValues_t, ThresholdValues_class_obj_t, ThresholdValues)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ThresholdValues_make_from_buf_obj, ThresholdValues_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'AocsRefParams'
 *
 **********************************************************************/
    
// class structure for type AocsRefParams
typedef struct 
{
    mp_obj_base_t base;
    CONOPS_AocsRefParams_t class_data;
} PACKED_STRUCT AocsRefParams_class_obj_t;

// AocsRefParams class constructor from field arguments
STATIC mp_obj_t AocsRefParams_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 3, 3, false);
    
    AocsRefParams_class_obj_t *p_self = m_new_obj(AocsRefParams_class_obj_t);
    p_self->base.type = type;
    
    // refParam1
    upy_sd_float_to_unaligned_addr((uint8_t *) &p_self->class_data.fRefParam1, mp_obj_get_float(p_args[0]));
    // refParam2
    upy_sd_float_to_unaligned_addr((uint8_t *) &p_self->class_data.fRefParam2, mp_obj_get_float(p_args[1]));
    // refParam3
    upy_sd_float_to_unaligned_addr((uint8_t *) &p_self->class_data.fRefParam3, mp_obj_get_float(p_args[2]));
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'AocsRefParams' getters
//

STATIC mp_obj_t AocsRefParams_get_refParam1(mp_obj_t self_in) 
{
    const AocsRefParams_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_float(upy_sd_float_from_unaligned_addr((uint8_t *) &p_self->class_data.fRefParam1));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(AocsRefParams_get_refParam1_obj, AocsRefParams_get_refParam1);

STATIC mp_obj_t AocsRefParams_get_refParam2(mp_obj_t self_in) 
{
    const AocsRefParams_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_float(upy_sd_float_from_unaligned_addr((uint8_t *) &p_self->class_data.fRefParam2));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(AocsRefParams_get_refParam2_obj, AocsRefParams_get_refParam2);

STATIC mp_obj_t AocsRefParams_get_refParam3(mp_obj_t self_in) 
{
    const AocsRefParams_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_float(upy_sd_float_from_unaligned_addr((uint8_t *) &p_self->class_data.fRefParam3));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(AocsRefParams_get_refParam3_obj, AocsRefParams_get_refParam3);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t AocsRefParams_locals_dict_table[3] = {
    { MP_ROM_QSTR(MP_QSTR_get_refParam1), MP_ROM_PTR(&AocsRefParams_get_refParam1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_refParam2), MP_ROM_PTR(&AocsRefParams_get_refParam2_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_refParam3), MP_ROM_PTR(&AocsRefParams_get_refParam3_obj) },
};

STATIC MP_DEFINE_CONST_DICT(AocsRefParams_locals_dict, AocsRefParams_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    AocsRefParams_type,
    MP_QSTR_AocsRefParams,
    MP_TYPE_FLAG_NONE,
    make_new, AocsRefParams_make_new,
    locals_dict, (mp_obj_dict_t*)&AocsRefParams_locals_dict
);

STATIC mp_obj_t AocsRefParams_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CONOPS_AocsRefParams_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    AocsRefParams_class_obj_t *p_self = m_new_obj(AocsRefParams_class_obj_t);
    p_self->base.type = &AocsRefParams_type;
    
    const CONOPS_AocsRefParams_t *p_data = (const CONOPS_AocsRefParams_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// AocsRefParams class constructor from a byte buffer
STATIC mp_obj_t AocsRefParams_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return AocsRefParams_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CONOPS_AocsRefParams_t, AocsRefParams_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CONOPS_AocsRefParams_t, AocsRefParams_class_obj_t, AocsRefParams)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(AocsRefParams_make_from_buf_obj, AocsRefParams_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'ControlMode'
 *
 **********************************************************************/
    
// class structure for type ControlMode
typedef struct 
{
    mp_obj_base_t base;
    CONOPS_ControlMode_t class_data;
} PACKED_STRUCT ControlMode_class_obj_t;

// ControlMode class constructor from field arguments
STATIC mp_obj_t ControlMode_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 2, 2, false);
    
    ControlMode_class_obj_t *p_self = m_new_obj(ControlMode_class_obj_t);
    p_self->base.type = type;
    
    // mode
    p_self->class_data.eMode = (uint8_t) mp_obj_get_int(p_args[0]);
    // params
    p_self->class_data.sParams = ((AocsRefParams_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'ControlMode' getters
//

STATIC mp_obj_t ControlMode_get_mode(mp_obj_t self_in) 
{
    const ControlMode_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eMode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ControlMode_get_mode_obj, ControlMode_get_mode);

STATIC mp_obj_t ControlMode_get_params(mp_obj_t self_in) 
{
    const ControlMode_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return AocsRefParams_make_from_buf(mp_obj_new_bytearray(sizeof(CONOPS_AocsRefParams_t), (const uint8_t *) &p_self->class_data.sParams));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ControlMode_get_params_obj, ControlMode_get_params);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t ControlMode_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_mode), MP_ROM_PTR(&ControlMode_get_mode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_params), MP_ROM_PTR(&ControlMode_get_params_obj) },
};

STATIC MP_DEFINE_CONST_DICT(ControlMode_locals_dict, ControlMode_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    ControlMode_type,
    MP_QSTR_ControlMode,
    MP_TYPE_FLAG_NONE,
    make_new, ControlMode_make_new,
    locals_dict, (mp_obj_dict_t*)&ControlMode_locals_dict
);

STATIC mp_obj_t ControlMode_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CONOPS_ControlMode_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    ControlMode_class_obj_t *p_self = m_new_obj(ControlMode_class_obj_t);
    p_self->base.type = &ControlMode_type;
    
    const CONOPS_ControlMode_t *p_data = (const CONOPS_ControlMode_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// ControlMode class constructor from a byte buffer
STATIC mp_obj_t ControlMode_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return ControlMode_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CONOPS_ControlMode_t, ControlMode_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CONOPS_ControlMode_t, ControlMode_class_obj_t, ControlMode)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ControlMode_make_from_buf_obj, ControlMode_make_from_buf);

/**********************************************************************
 *
 *  Enumeration classes
 *
 **********************************************************************/
//
// Enumeration classes for type 'ThresholdValueTypes'
//
STATIC const mp_rom_map_elem_t thresholdvaluetypes_locals_dict_table[8] = 
{
    { MP_ROM_QSTR(MP_QSTR_THRESHOLDVALUETYPES_DEFAULT), MP_ROM_INT(CONOPS_THRESHOLDVALUETYPES_DEFAULT)},
    { MP_ROM_QSTR(MP_QSTR_THRESHOLDVALUETYPES_VBATT_SAFE), MP_ROM_INT(CONOPS_THRESHOLDVALUETYPES_VBATT_SAFE)},
    { MP_ROM_QSTR(MP_QSTR_THRESHOLDVALUETYPES_TBATT_SAFE_LOWER), MP_ROM_INT(CONOPS_THRESHOLDVALUETYPES_TBATT_SAFE_LOWER)},
    { MP_ROM_QSTR(MP_QSTR_THRESHOLDVALUETYPES_TBATT_SAFE_UPPER), MP_ROM_INT(CONOPS_THRESHOLDVALUETYPES_TBATT_SAFE_UPPER)},
    { MP_ROM_QSTR(MP_QSTR_THRESHOLDVALUETYPES_ANGVEL_MAX), MP_ROM_INT(CONOPS_THRESHOLDVALUETYPES_ANGVEL_MAX)},
    { MP_ROM_QSTR(MP_QSTR_THRESHOLDVALUETYPES_ANGVEL_MIN), MP_ROM_INT(CONOPS_THRESHOLDVALUETYPES_ANGVEL_MIN)},
    { MP_ROM_QSTR(MP_QSTR_THRESHOLDVALUETYPES_ANGVEL_Y_THOMSON_HIGH), MP_ROM_INT(CONOPS_THRESHOLDVALUETYPES_ANGVEL_Y_THOMSON_HIGH)},
    { MP_ROM_QSTR(MP_QSTR_THRESHOLDVALUETYPES_ANGVEL_Y_THOMSON_LOW), MP_ROM_INT(CONOPS_THRESHOLDVALUETYPES_ANGVEL_Y_THOMSON_LOW)},
};

STATIC MP_DEFINE_CONST_DICT(thresholdvaluetypes_class_locals_dict, thresholdvaluetypes_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    thresholdvaluetypes_class_type,
    MP_QSTR_ThresholdValueTypes,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&thresholdvaluetypes_class_locals_dict
);
//
// Enumeration classes for type 'OpModes'
//
STATIC const mp_rom_map_elem_t opmodes_locals_dict_table[6] = 
{
    { MP_ROM_QSTR(MP_QSTR_OPMODES_MODE_SAFE), MP_ROM_INT(CONOPS_OPMODES_MODE_SAFE)},
    { MP_ROM_QSTR(MP_QSTR_OPMODES_MODE_SAFE_ENTRY), MP_ROM_INT(CONOPS_OPMODES_MODE_SAFE_ENTRY)},
    { MP_ROM_QSTR(MP_QSTR_OPMODES_MODE_SAFE_CONTROL), MP_ROM_INT(CONOPS_OPMODES_MODE_SAFE_CONTROL)},
    { MP_ROM_QSTR(MP_QSTR_OPMODES_MODE_SAFE_NO_CONTROL), MP_ROM_INT(CONOPS_OPMODES_MODE_SAFE_NO_CONTROL)},
    { MP_ROM_QSTR(MP_QSTR_OPMODES_MODE_IDLE), MP_ROM_INT(CONOPS_OPMODES_MODE_IDLE)},
    { MP_ROM_QSTR(MP_QSTR_OPMODES_MODE_MISSION), MP_ROM_INT(CONOPS_OPMODES_MODE_MISSION)},
};

STATIC MP_DEFINE_CONST_DICT(opmodes_class_locals_dict, opmodes_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    opmodes_class_type,
    MP_QSTR_OpModes,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&opmodes_class_locals_dict
);
//
// Enumeration classes for type 'AocsState'
//
STATIC const mp_rom_map_elem_t aocsstate_locals_dict_table[16] = 
{
    { MP_ROM_QSTR(MP_QSTR_AOCSSTATE_AOCS_STATE_UNDEFINED), MP_ROM_INT(CONOPS_AOCSSTATE_AOCS_STATE_UNDEFINED)},
    { MP_ROM_QSTR(MP_QSTR_AOCSSTATE_AOCS_STATE_EXISTING_CONTROL), MP_ROM_INT(CONOPS_AOCSSTATE_AOCS_STATE_EXISTING_CONTROL)},
    { MP_ROM_QSTR(MP_QSTR_AOCSSTATE_AOCS_STATE_NO_CONTROL), MP_ROM_INT(CONOPS_AOCSSTATE_AOCS_STATE_NO_CONTROL)},
    { MP_ROM_QSTR(MP_QSTR_AOCSSTATE_AOCS_STATE_NORMAL_DETUMBLING), MP_ROM_INT(CONOPS_AOCSSTATE_AOCS_STATE_NORMAL_DETUMBLING)},
    { MP_ROM_QSTR(MP_QSTR_AOCSSTATE_AOCS_STATE_Y_THOMSON), MP_ROM_INT(CONOPS_AOCSSTATE_AOCS_STATE_Y_THOMSON)},
    { MP_ROM_QSTR(MP_QSTR_AOCSSTATE_AOCS_STATE_Y_THOMSON_MEMS_RATE), MP_ROM_INT(CONOPS_AOCSSTATE_AOCS_STATE_Y_THOMSON_MEMS_RATE)},
    { MP_ROM_QSTR(MP_QSTR_AOCSSTATE_AOCS_STATE_FAST_DETUMBLING), MP_ROM_INT(CONOPS_AOCSSTATE_AOCS_STATE_FAST_DETUMBLING)},
    { MP_ROM_QSTR(MP_QSTR_AOCSSTATE_AOCS_STATE_VERY_FAST_DETUMBLING), MP_ROM_INT(CONOPS_AOCSSTATE_AOCS_STATE_VERY_FAST_DETUMBLING)},
    { MP_ROM_QSTR(MP_QSTR_AOCSSTATE_AOCS_STATE_Y_MOMENTUM), MP_ROM_INT(CONOPS_AOCSSTATE_AOCS_STATE_Y_MOMENTUM)},
    { MP_ROM_QSTR(MP_QSTR_AOCSSTATE_AOCS_STATE_Y_MOMENTUM_FULL_STATE_EKF), MP_ROM_INT(CONOPS_AOCSSTATE_AOCS_STATE_Y_MOMENTUM_FULL_STATE_EKF)},
    { MP_ROM_QSTR(MP_QSTR_AOCSSTATE_AOCS_STATE_3AXIS), MP_ROM_INT(CONOPS_AOCSSTATE_AOCS_STATE_3AXIS)},
    { MP_ROM_QSTR(MP_QSTR_AOCSSTATE_AOCS_STATE_SUN_TRACKING), MP_ROM_INT(CONOPS_AOCSSTATE_AOCS_STATE_SUN_TRACKING)},
    { MP_ROM_QSTR(MP_QSTR_AOCSSTATE_AOCS_STATE_TARGET_TRACKING), MP_ROM_INT(CONOPS_AOCSSTATE_AOCS_STATE_TARGET_TRACKING)},
    { MP_ROM_QSTR(MP_QSTR_AOCSSTATE_AOCS_STATE_USER1), MP_ROM_INT(CONOPS_AOCSSTATE_AOCS_STATE_USER1)},
    { MP_ROM_QSTR(MP_QSTR_AOCSSTATE_AOCS_STATE_USER2), MP_ROM_INT(CONOPS_AOCSSTATE_AOCS_STATE_USER2)},
    { MP_ROM_QSTR(MP_QSTR_AOCSSTATE_AOCS_STATE_USER3), MP_ROM_INT(CONOPS_AOCSSTATE_AOCS_STATE_USER3)},
};

STATIC MP_DEFINE_CONST_DICT(aocsstate_class_locals_dict, aocsstate_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    aocsstate_class_type,
    MP_QSTR_AocsState,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&aocsstate_class_locals_dict
);
//
// Enumeration classes for type 'Events'
//
STATIC const mp_rom_map_elem_t events_locals_dict_table[5] = 
{
    { MP_ROM_QSTR(MP_QSTR_EVENTS_RESET), MP_ROM_INT(CONOPS_EVENTS_RESET)},
    { MP_ROM_QSTR(MP_QSTR_EVENTS_PERIODIC), MP_ROM_INT(CONOPS_EVENTS_PERIODIC)},
    { MP_ROM_QSTR(MP_QSTR_EVENTS_ENTER_IDLE), MP_ROM_INT(CONOPS_EVENTS_ENTER_IDLE)},
    { MP_ROM_QSTR(MP_QSTR_EVENTS_ENTER_SAFE), MP_ROM_INT(CONOPS_EVENTS_ENTER_SAFE)},
    { MP_ROM_QSTR(MP_QSTR_EVENTS_ENTER_MISSION), MP_ROM_INT(CONOPS_EVENTS_ENTER_MISSION)},
};

STATIC MP_DEFINE_CONST_DICT(events_class_locals_dict, events_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    events_class_type,
    MP_QSTR_Events,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&events_class_locals_dict
);
//
// Enumeration classes for type 'StandardResult'
//
STATIC const mp_rom_map_elem_t standardresult_locals_dict_table[4] = 
{
    { MP_ROM_QSTR(MP_QSTR_STANDARDRESULT_SUCCESS), MP_ROM_INT(CONOPS_STANDARDRESULT_SUCCESS)},
    { MP_ROM_QSTR(MP_QSTR_STANDARDRESULT_ERROR), MP_ROM_INT(CONOPS_STANDARDRESULT_ERROR)},
    { MP_ROM_QSTR(MP_QSTR_STANDARDRESULT_INVALID_ARGS), MP_ROM_INT(CONOPS_STANDARDRESULT_INVALID_ARGS)},
    { MP_ROM_QSTR(MP_QSTR_STANDARDRESULT_NOT_SUPPORTED), MP_ROM_INT(CONOPS_STANDARDRESULT_NOT_SUPPORTED)},
};

STATIC MP_DEFINE_CONST_DICT(standardresult_class_locals_dict, standardresult_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    standardresult_class_type,
    MP_QSTR_StandardResult,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&standardresult_class_locals_dict
);
//
// Enumeration classes for type 'SafeBool'
//
STATIC const mp_rom_map_elem_t safebool_locals_dict_table[2] = 
{
    { MP_ROM_QSTR(MP_QSTR_SAFEBOOL_FALSE), MP_ROM_INT(CONOPS_SAFEBOOL_FALSE)},
    { MP_ROM_QSTR(MP_QSTR_SAFEBOOL_TRUE), MP_ROM_INT(CONOPS_SAFEBOOL_TRUE)},
};

STATIC MP_DEFINE_CONST_DICT(safebool_class_locals_dict, safebool_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    safebool_class_type,
    MP_QSTR_SafeBool,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&safebool_class_locals_dict
);
//
// Enumeration classes for type 'ModesWithDefCtrl'
//
STATIC const mp_rom_map_elem_t modeswithdefctrl_locals_dict_table[2] = 
{
    { MP_ROM_QSTR(MP_QSTR_MODESWITHDEFCTRL_SAFE), MP_ROM_INT(CONOPS_MODESWITHDEFCTRL_SAFE)},
    { MP_ROM_QSTR(MP_QSTR_MODESWITHDEFCTRL_IDLE), MP_ROM_INT(CONOPS_MODESWITHDEFCTRL_IDLE)},
};

STATIC MP_DEFINE_CONST_DICT(modeswithdefctrl_class_locals_dict, modeswithdefctrl_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    modeswithdefctrl_class_type,
    MP_QSTR_ModesWithDefCtrl,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&modeswithdefctrl_class_locals_dict
);

/**********************************************************************
 *
 *  Static function definitions
 *
 **********************************************************************/
// uPy request function for method 'send_new_event'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopssend_new_eventRequestData_t data;
} req_send_new_event_fp_t;

STATIC mp_obj_t req_send_new_event(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_send_new_event_fp_t * p_req_data = m_malloc(sizeof(req_send_new_event_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'send_new_event' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 16;
    p_req_data->fp_hdr.func_id = 0;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eEvent_type = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_send_new_event_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'send_new_event'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopssend_new_eventResponseData_t data;
} resp_send_new_event_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_send_new_event_fp_t class_data;
} resp_send_new_event_class_obj_t;

STATIC mp_obj_t resp_send_new_event_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_send_new_event_class_obj_t *p_self = m_new_obj(resp_send_new_event_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_send_new_event_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_send_new_event_fp_t *p_data = (resp_send_new_event_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "send_new_event" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_send_new_event_get_op_result(mp_obj_t self_in) 
{
    const resp_send_new_event_class_obj_t *p_resp_data = ((resp_send_new_event_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_send_new_event_get_op_result_obj, resp_send_new_event_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_send_new_event_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_send_new_event_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_send_new_event_locals_dict, resp_send_new_event_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_conopssend_new_eventResponseData,
    MP_QSTR_resp_send_new_event,
    MP_TYPE_FLAG_NONE,
    make_new, resp_send_new_event_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_send_new_event_locals_dict    
);

// uPy request function for method 'get_op_mode'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_get_op_mode_fp_t;

STATIC mp_obj_t req_get_op_mode(void)
{

    // allocate memory on the MicroPython heap
    req_get_op_mode_fp_t * p_req_data = m_malloc(sizeof(req_get_op_mode_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'get_op_mode' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 16;
    p_req_data->fp_hdr.func_id = 1;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_get_op_mode_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'get_op_mode'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopsget_op_modeResponseData_t data;
} resp_get_op_mode_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_get_op_mode_fp_t class_data;
} resp_get_op_mode_class_obj_t;

STATIC mp_obj_t resp_get_op_mode_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_get_op_mode_class_obj_t *p_self = m_new_obj(resp_get_op_mode_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_get_op_mode_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_get_op_mode_fp_t *p_data = (resp_get_op_mode_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "get_op_mode" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_get_op_mode_get_op_result(mp_obj_t self_in) 
{
    const resp_get_op_mode_class_obj_t *p_resp_data = ((resp_get_op_mode_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_op_mode_get_op_result_obj, resp_get_op_mode_get_op_result);

STATIC mp_obj_t resp_get_op_mode_get_op_mode(mp_obj_t self_in) 
{
    const resp_get_op_mode_class_obj_t *p_resp_data = ((resp_get_op_mode_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_mode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_op_mode_get_op_mode_obj, resp_get_op_mode_get_op_mode);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_get_op_mode_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_get_op_mode_get_op_result_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_op_mode), MP_ROM_PTR(&resp_get_op_mode_get_op_mode_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_get_op_mode_locals_dict, resp_get_op_mode_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_conopsget_op_modeResponseData,
    MP_QSTR_resp_get_op_mode,
    MP_TYPE_FLAG_NONE,
    make_new, resp_get_op_mode_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_get_op_mode_locals_dict    
);

// uPy request function for method 'set_thresh_val'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopsset_thresh_valRequestData_t data;
} req_set_thresh_val_fp_t;

STATIC mp_obj_t req_set_thresh_val(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_set_thresh_val_fp_t * p_req_data = m_malloc(sizeof(req_set_thresh_val_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'set_thresh_val' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 16;
    p_req_data->fp_hdr.func_id = 2;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.i32Thresh_value = (int32_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.eThresh_type = (uint8_t) mp_obj_get_int(p_args[1]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_set_thresh_val_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'set_thresh_val'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopsset_thresh_valResponseData_t data;
} resp_set_thresh_val_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_set_thresh_val_fp_t class_data;
} resp_set_thresh_val_class_obj_t;

STATIC mp_obj_t resp_set_thresh_val_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_set_thresh_val_class_obj_t *p_self = m_new_obj(resp_set_thresh_val_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_set_thresh_val_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_set_thresh_val_fp_t *p_data = (resp_set_thresh_val_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "set_thresh_val" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_set_thresh_val_get_op_result(mp_obj_t self_in) 
{
    const resp_set_thresh_val_class_obj_t *p_resp_data = ((resp_set_thresh_val_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_set_thresh_val_get_op_result_obj, resp_set_thresh_val_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_set_thresh_val_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_set_thresh_val_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_set_thresh_val_locals_dict, resp_set_thresh_val_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_conopsset_thresh_valResponseData,
    MP_QSTR_resp_set_thresh_val,
    MP_TYPE_FLAG_NONE,
    make_new, resp_set_thresh_val_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_set_thresh_val_locals_dict    
);

// uPy request function for method 'get_thresh_val'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopsget_thresh_valRequestData_t data;
} req_get_thresh_val_fp_t;

STATIC mp_obj_t req_get_thresh_val(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_get_thresh_val_fp_t * p_req_data = m_malloc(sizeof(req_get_thresh_val_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'get_thresh_val' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 16;
    p_req_data->fp_hdr.func_id = 3;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eThresh_type = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_get_thresh_val_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'get_thresh_val'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopsget_thresh_valResponseData_t data;
} resp_get_thresh_val_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_get_thresh_val_fp_t class_data;
} resp_get_thresh_val_class_obj_t;

STATIC mp_obj_t resp_get_thresh_val_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_get_thresh_val_class_obj_t *p_self = m_new_obj(resp_get_thresh_val_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_get_thresh_val_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_get_thresh_val_fp_t *p_data = (resp_get_thresh_val_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "get_thresh_val" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_get_thresh_val_get_op_result(mp_obj_t self_in) 
{
    const resp_get_thresh_val_class_obj_t *p_resp_data = ((resp_get_thresh_val_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_thresh_val_get_op_result_obj, resp_get_thresh_val_get_op_result);

STATIC mp_obj_t resp_get_thresh_val_get_thresh_value(mp_obj_t self_in) 
{
    const resp_get_thresh_val_class_obj_t *p_resp_data = ((resp_get_thresh_val_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.i32Thresh_value);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_thresh_val_get_thresh_value_obj, resp_get_thresh_val_get_thresh_value);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_get_thresh_val_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_get_thresh_val_get_op_result_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_thresh_value), MP_ROM_PTR(&resp_get_thresh_val_get_thresh_value_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_get_thresh_val_locals_dict, resp_get_thresh_val_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_conopsget_thresh_valResponseData,
    MP_QSTR_resp_get_thresh_val,
    MP_TYPE_FLAG_NONE,
    make_new, resp_get_thresh_val_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_get_thresh_val_locals_dict    
);

// uPy request function for method 'set_all_thresh_val'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopsset_all_thresh_valRequestData_t data;
} req_set_all_thresh_val_fp_t;

STATIC mp_obj_t req_set_all_thresh_val(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_set_all_thresh_val_fp_t * p_req_data = m_malloc(sizeof(req_set_all_thresh_val_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'set_all_thresh_val' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 16;
    p_req_data->fp_hdr.func_id = 4;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.sThresh_vals = ((ThresholdValues_class_obj_t *) MP_OBJ_TO_PTR(p_args[0]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_set_all_thresh_val_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'set_all_thresh_val'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopsset_all_thresh_valResponseData_t data;
} resp_set_all_thresh_val_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_set_all_thresh_val_fp_t class_data;
} resp_set_all_thresh_val_class_obj_t;

STATIC mp_obj_t resp_set_all_thresh_val_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_set_all_thresh_val_class_obj_t *p_self = m_new_obj(resp_set_all_thresh_val_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_set_all_thresh_val_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_set_all_thresh_val_fp_t *p_data = (resp_set_all_thresh_val_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "set_all_thresh_val" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_set_all_thresh_val_get_op_result(mp_obj_t self_in) 
{
    const resp_set_all_thresh_val_class_obj_t *p_resp_data = ((resp_set_all_thresh_val_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_set_all_thresh_val_get_op_result_obj, resp_set_all_thresh_val_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_set_all_thresh_val_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_set_all_thresh_val_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_set_all_thresh_val_locals_dict, resp_set_all_thresh_val_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_conopsset_all_thresh_valResponseData,
    MP_QSTR_resp_set_all_thresh_val,
    MP_TYPE_FLAG_NONE,
    make_new, resp_set_all_thresh_val_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_set_all_thresh_val_locals_dict    
);

// uPy request function for method 'get_all_thresh_val'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_get_all_thresh_val_fp_t;

STATIC mp_obj_t req_get_all_thresh_val(void)
{

    // allocate memory on the MicroPython heap
    req_get_all_thresh_val_fp_t * p_req_data = m_malloc(sizeof(req_get_all_thresh_val_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'get_all_thresh_val' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 16;
    p_req_data->fp_hdr.func_id = 5;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_get_all_thresh_val_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'get_all_thresh_val'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopsget_all_thresh_valResponseData_t data;
} resp_get_all_thresh_val_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_get_all_thresh_val_fp_t class_data;
} resp_get_all_thresh_val_class_obj_t;

STATIC mp_obj_t resp_get_all_thresh_val_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_get_all_thresh_val_class_obj_t *p_self = m_new_obj(resp_get_all_thresh_val_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_get_all_thresh_val_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_get_all_thresh_val_fp_t *p_data = (resp_get_all_thresh_val_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "get_all_thresh_val" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_get_all_thresh_val_get_op_result(mp_obj_t self_in) 
{
    const resp_get_all_thresh_val_class_obj_t *p_resp_data = ((resp_get_all_thresh_val_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_all_thresh_val_get_op_result_obj, resp_get_all_thresh_val_get_op_result);

STATIC mp_obj_t resp_get_all_thresh_val_get_thresh_vals(mp_obj_t self_in) 
{
    const resp_get_all_thresh_val_class_obj_t *p_resp_data = ((resp_get_all_thresh_val_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return ThresholdValues_make_from_buf(mp_obj_new_bytearray(sizeof(CONOPS_ThresholdValues_t), (const uint8_t *) &p_resp_data->class_data.data.sThresh_vals));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_all_thresh_val_get_thresh_vals_obj, resp_get_all_thresh_val_get_thresh_vals);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_get_all_thresh_val_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_get_all_thresh_val_get_op_result_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_thresh_vals), MP_ROM_PTR(&resp_get_all_thresh_val_get_thresh_vals_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_get_all_thresh_val_locals_dict, resp_get_all_thresh_val_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_conopsget_all_thresh_valResponseData,
    MP_QSTR_resp_get_all_thresh_val,
    MP_TYPE_FLAG_NONE,
    make_new, resp_get_all_thresh_val_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_get_all_thresh_val_locals_dict    
);

// uPy request function for method 'request_mission_mode_enter'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopsrequest_mission_mode_enterRequestData_t data;
} req_request_mission_mode_enter_fp_t;

STATIC mp_obj_t req_request_mission_mode_enter(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_request_mission_mode_enter_fp_t * p_req_data = m_malloc(sizeof(req_request_mission_mode_enter_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'request_mission_mode_enter' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 16;
    p_req_data->fp_hdr.func_id = 6;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.u32Timeout = (uint32_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_request_mission_mode_enter_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'request_mission_mode_enter'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopsrequest_mission_mode_enterResponseData_t data;
} resp_request_mission_mode_enter_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_request_mission_mode_enter_fp_t class_data;
} resp_request_mission_mode_enter_class_obj_t;

STATIC mp_obj_t resp_request_mission_mode_enter_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_request_mission_mode_enter_class_obj_t *p_self = m_new_obj(resp_request_mission_mode_enter_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_request_mission_mode_enter_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_request_mission_mode_enter_fp_t *p_data = (resp_request_mission_mode_enter_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "request_mission_mode_enter" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_request_mission_mode_enter_get_op_result(mp_obj_t self_in) 
{
    const resp_request_mission_mode_enter_class_obj_t *p_resp_data = ((resp_request_mission_mode_enter_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_request_mission_mode_enter_get_op_result_obj, resp_request_mission_mode_enter_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_request_mission_mode_enter_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_request_mission_mode_enter_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_request_mission_mode_enter_locals_dict, resp_request_mission_mode_enter_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_conopsrequest_mission_mode_enterResponseData,
    MP_QSTR_resp_request_mission_mode_enter,
    MP_TYPE_FLAG_NONE,
    make_new, resp_request_mission_mode_enter_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_request_mission_mode_enter_locals_dict    
);

// uPy request function for method 'request_mission_mode_exit'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_request_mission_mode_exit_fp_t;

STATIC mp_obj_t req_request_mission_mode_exit(void)
{

    // allocate memory on the MicroPython heap
    req_request_mission_mode_exit_fp_t * p_req_data = m_malloc(sizeof(req_request_mission_mode_exit_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'request_mission_mode_exit' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 16;
    p_req_data->fp_hdr.func_id = 7;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_request_mission_mode_exit_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'request_mission_mode_exit'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopsrequest_mission_mode_exitResponseData_t data;
} resp_request_mission_mode_exit_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_request_mission_mode_exit_fp_t class_data;
} resp_request_mission_mode_exit_class_obj_t;

STATIC mp_obj_t resp_request_mission_mode_exit_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_request_mission_mode_exit_class_obj_t *p_self = m_new_obj(resp_request_mission_mode_exit_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_request_mission_mode_exit_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_request_mission_mode_exit_fp_t *p_data = (resp_request_mission_mode_exit_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "request_mission_mode_exit" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_request_mission_mode_exit_get_op_result(mp_obj_t self_in) 
{
    const resp_request_mission_mode_exit_class_obj_t *p_resp_data = ((resp_request_mission_mode_exit_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_request_mission_mode_exit_get_op_result_obj, resp_request_mission_mode_exit_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_request_mission_mode_exit_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_request_mission_mode_exit_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_request_mission_mode_exit_locals_dict, resp_request_mission_mode_exit_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_conopsrequest_mission_mode_exitResponseData,
    MP_QSTR_resp_request_mission_mode_exit,
    MP_TYPE_FLAG_NONE,
    make_new, resp_request_mission_mode_exit_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_request_mission_mode_exit_locals_dict    
);

// uPy request function for method 'get_default_control_mode'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopsget_default_control_modeRequestData_t data;
} req_get_default_control_mode_fp_t;

STATIC mp_obj_t req_get_default_control_mode(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_get_default_control_mode_fp_t * p_req_data = m_malloc(sizeof(req_get_default_control_mode_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'get_default_control_mode' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 16;
    p_req_data->fp_hdr.func_id = 8;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eConops_mode = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_get_default_control_mode_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'get_default_control_mode'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopsget_default_control_modeResponseData_t data;
} resp_get_default_control_mode_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_get_default_control_mode_fp_t class_data;
} resp_get_default_control_mode_class_obj_t;

STATIC mp_obj_t resp_get_default_control_mode_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_get_default_control_mode_class_obj_t *p_self = m_new_obj(resp_get_default_control_mode_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_get_default_control_mode_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_get_default_control_mode_fp_t *p_data = (resp_get_default_control_mode_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "get_default_control_mode" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_get_default_control_mode_get_op_result(mp_obj_t self_in) 
{
    const resp_get_default_control_mode_class_obj_t *p_resp_data = ((resp_get_default_control_mode_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_default_control_mode_get_op_result_obj, resp_get_default_control_mode_get_op_result);

STATIC mp_obj_t resp_get_default_control_mode_get_control_mode(mp_obj_t self_in) 
{
    const resp_get_default_control_mode_class_obj_t *p_resp_data = ((resp_get_default_control_mode_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return ControlMode_make_from_buf(mp_obj_new_bytearray(sizeof(CONOPS_ControlMode_t), (const uint8_t *) &p_resp_data->class_data.data.sControl_mode));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_default_control_mode_get_control_mode_obj, resp_get_default_control_mode_get_control_mode);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_get_default_control_mode_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_get_default_control_mode_get_op_result_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_control_mode), MP_ROM_PTR(&resp_get_default_control_mode_get_control_mode_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_get_default_control_mode_locals_dict, resp_get_default_control_mode_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_conopsget_default_control_modeResponseData,
    MP_QSTR_resp_get_default_control_mode,
    MP_TYPE_FLAG_NONE,
    make_new, resp_get_default_control_mode_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_get_default_control_mode_locals_dict    
);

// uPy request function for method 'set_default_control_mode'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopsset_default_control_modeRequestData_t data;
} req_set_default_control_mode_fp_t;

STATIC mp_obj_t req_set_default_control_mode(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_set_default_control_mode_fp_t * p_req_data = m_malloc(sizeof(req_set_default_control_mode_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'set_default_control_mode' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 16;
    p_req_data->fp_hdr.func_id = 9;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eConops_mode = (uint8_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.sControl_mode = ((ControlMode_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_set_default_control_mode_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'set_default_control_mode'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopsset_default_control_modeResponseData_t data;
} resp_set_default_control_mode_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_set_default_control_mode_fp_t class_data;
} resp_set_default_control_mode_class_obj_t;

STATIC mp_obj_t resp_set_default_control_mode_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_set_default_control_mode_class_obj_t *p_self = m_new_obj(resp_set_default_control_mode_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_set_default_control_mode_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_set_default_control_mode_fp_t *p_data = (resp_set_default_control_mode_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "set_default_control_mode" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_set_default_control_mode_get_op_result(mp_obj_t self_in) 
{
    const resp_set_default_control_mode_class_obj_t *p_resp_data = ((resp_set_default_control_mode_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_set_default_control_mode_get_op_result_obj, resp_set_default_control_mode_get_op_result);

STATIC mp_obj_t resp_set_default_control_mode_get_set_control_mode(mp_obj_t self_in) 
{
    const resp_set_default_control_mode_class_obj_t *p_resp_data = ((resp_set_default_control_mode_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return ControlMode_make_from_buf(mp_obj_new_bytearray(sizeof(CONOPS_ControlMode_t), (const uint8_t *) &p_resp_data->class_data.data.sSet_control_mode));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_set_default_control_mode_get_set_control_mode_obj, resp_set_default_control_mode_get_set_control_mode);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_set_default_control_mode_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_set_default_control_mode_get_op_result_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_set_control_mode), MP_ROM_PTR(&resp_set_default_control_mode_get_set_control_mode_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_set_default_control_mode_locals_dict, resp_set_default_control_mode_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_conopsset_default_control_modeResponseData,
    MP_QSTR_resp_set_default_control_mode,
    MP_TYPE_FLAG_NONE,
    make_new, resp_set_default_control_mode_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_set_default_control_mode_locals_dict    
);

// uPy request function for method 'set_force_allow_payloads'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopsset_force_allow_payloadsRequestData_t data;
} req_set_force_allow_payloads_fp_t;

STATIC mp_obj_t req_set_force_allow_payloads(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_set_force_allow_payloads_fp_t * p_req_data = m_malloc(sizeof(req_set_force_allow_payloads_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'set_force_allow_payloads' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 16;
    p_req_data->fp_hdr.func_id = 10;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eIs_allowed = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_set_force_allow_payloads_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'set_force_allow_payloads'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopsset_force_allow_payloadsResponseData_t data;
} resp_set_force_allow_payloads_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_set_force_allow_payloads_fp_t class_data;
} resp_set_force_allow_payloads_class_obj_t;

STATIC mp_obj_t resp_set_force_allow_payloads_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_set_force_allow_payloads_class_obj_t *p_self = m_new_obj(resp_set_force_allow_payloads_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_set_force_allow_payloads_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_set_force_allow_payloads_fp_t *p_data = (resp_set_force_allow_payloads_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "set_force_allow_payloads" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_set_force_allow_payloads_get_op_result(mp_obj_t self_in) 
{
    const resp_set_force_allow_payloads_class_obj_t *p_resp_data = ((resp_set_force_allow_payloads_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_set_force_allow_payloads_get_op_result_obj, resp_set_force_allow_payloads_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_set_force_allow_payloads_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_set_force_allow_payloads_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_set_force_allow_payloads_locals_dict, resp_set_force_allow_payloads_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_conopsset_force_allow_payloadsResponseData,
    MP_QSTR_resp_set_force_allow_payloads,
    MP_TYPE_FLAG_NONE,
    make_new, resp_set_force_allow_payloads_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_set_force_allow_payloads_locals_dict    
);

// uPy request function for method 'get_force_allow_payloads'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_get_force_allow_payloads_fp_t;

STATIC mp_obj_t req_get_force_allow_payloads(void)
{

    // allocate memory on the MicroPython heap
    req_get_force_allow_payloads_fp_t * p_req_data = m_malloc(sizeof(req_get_force_allow_payloads_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'get_force_allow_payloads' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 16;
    p_req_data->fp_hdr.func_id = 11;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_get_force_allow_payloads_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'get_force_allow_payloads'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    conopsget_force_allow_payloadsResponseData_t data;
} resp_get_force_allow_payloads_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_get_force_allow_payloads_fp_t class_data;
} resp_get_force_allow_payloads_class_obj_t;

STATIC mp_obj_t resp_get_force_allow_payloads_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_get_force_allow_payloads_class_obj_t *p_self = m_new_obj(resp_get_force_allow_payloads_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_get_force_allow_payloads_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_get_force_allow_payloads_fp_t *p_data = (resp_get_force_allow_payloads_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "get_force_allow_payloads" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_get_force_allow_payloads_get_set_is_allowed(mp_obj_t self_in) 
{
    const resp_get_force_allow_payloads_class_obj_t *p_resp_data = ((resp_get_force_allow_payloads_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eSet_is_allowed);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_force_allow_payloads_get_set_is_allowed_obj, resp_get_force_allow_payloads_get_set_is_allowed);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_get_force_allow_payloads_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_set_is_allowed), MP_ROM_PTR(&resp_get_force_allow_payloads_get_set_is_allowed_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_get_force_allow_payloads_locals_dict, resp_get_force_allow_payloads_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_conopsget_force_allow_payloadsResponseData,
    MP_QSTR_resp_get_force_allow_payloads,
    MP_TYPE_FLAG_NONE,
    make_new, resp_get_force_allow_payloads_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_get_force_allow_payloads_locals_dict    
);


/**********************************************************************
 *
 *  uPy function reference definitions
 *
 **********************************************************************/
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_send_new_event_obj, 1, req_send_new_event);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_get_op_mode_obj, req_get_op_mode);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_set_thresh_val_obj, 2, req_set_thresh_val);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_get_thresh_val_obj, 1, req_get_thresh_val);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_set_all_thresh_val_obj, 1, req_set_all_thresh_val);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_get_all_thresh_val_obj, req_get_all_thresh_val);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_request_mission_mode_enter_obj, 1, req_request_mission_mode_enter);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_request_mission_mode_exit_obj, req_request_mission_mode_exit);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_get_default_control_mode_obj, 1, req_get_default_control_mode);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_set_default_control_mode_obj, 2, req_set_default_control_mode);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_set_force_allow_payloads_obj, 1, req_set_force_allow_payloads);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_get_force_allow_payloads_obj, req_get_force_allow_payloads);

STATIC const mp_rom_map_elem_t upy_conops_module_globals_table[38] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_upy_conops) },
    // export FIDL methods
    // export request serializer function for method 'send_new_event'
    { MP_ROM_QSTR(MP_QSTR_req_send_new_event), MP_ROM_PTR(&req_send_new_event_obj) },
    // export class for method 'send_new_event' response
    { MP_ROM_QSTR(MP_QSTR_resp_send_new_event), MP_ROM_PTR(&mp_type_conopssend_new_eventResponseData) },
    // export request serializer function for method 'get_op_mode'
    { MP_ROM_QSTR(MP_QSTR_req_get_op_mode), MP_ROM_PTR(&req_get_op_mode_obj) },
    // export class for method 'get_op_mode' response
    { MP_ROM_QSTR(MP_QSTR_resp_get_op_mode), MP_ROM_PTR(&mp_type_conopsget_op_modeResponseData) },
    // export request serializer function for method 'set_thresh_val'
    { MP_ROM_QSTR(MP_QSTR_req_set_thresh_val), MP_ROM_PTR(&req_set_thresh_val_obj) },
    // export class for method 'set_thresh_val' response
    { MP_ROM_QSTR(MP_QSTR_resp_set_thresh_val), MP_ROM_PTR(&mp_type_conopsset_thresh_valResponseData) },
    // export request serializer function for method 'get_thresh_val'
    { MP_ROM_QSTR(MP_QSTR_req_get_thresh_val), MP_ROM_PTR(&req_get_thresh_val_obj) },
    // export class for method 'get_thresh_val' response
    { MP_ROM_QSTR(MP_QSTR_resp_get_thresh_val), MP_ROM_PTR(&mp_type_conopsget_thresh_valResponseData) },
    // export request serializer function for method 'set_all_thresh_val'
    { MP_ROM_QSTR(MP_QSTR_req_set_all_thresh_val), MP_ROM_PTR(&req_set_all_thresh_val_obj) },
    // export class for method 'set_all_thresh_val' response
    { MP_ROM_QSTR(MP_QSTR_resp_set_all_thresh_val), MP_ROM_PTR(&mp_type_conopsset_all_thresh_valResponseData) },
    // export request serializer function for method 'get_all_thresh_val'
    { MP_ROM_QSTR(MP_QSTR_req_get_all_thresh_val), MP_ROM_PTR(&req_get_all_thresh_val_obj) },
    // export class for method 'get_all_thresh_val' response
    { MP_ROM_QSTR(MP_QSTR_resp_get_all_thresh_val), MP_ROM_PTR(&mp_type_conopsget_all_thresh_valResponseData) },
    // export request serializer function for method 'request_mission_mode_enter'
    { MP_ROM_QSTR(MP_QSTR_req_request_mission_mode_enter), MP_ROM_PTR(&req_request_mission_mode_enter_obj) },
    // export class for method 'request_mission_mode_enter' response
    { MP_ROM_QSTR(MP_QSTR_resp_request_mission_mode_enter), MP_ROM_PTR(&mp_type_conopsrequest_mission_mode_enterResponseData) },
    // export request serializer function for method 'request_mission_mode_exit'
    { MP_ROM_QSTR(MP_QSTR_req_request_mission_mode_exit), MP_ROM_PTR(&req_request_mission_mode_exit_obj) },
    // export class for method 'request_mission_mode_exit' response
    { MP_ROM_QSTR(MP_QSTR_resp_request_mission_mode_exit), MP_ROM_PTR(&mp_type_conopsrequest_mission_mode_exitResponseData) },
    // export request serializer function for method 'get_default_control_mode'
    { MP_ROM_QSTR(MP_QSTR_req_get_default_control_mode), MP_ROM_PTR(&req_get_default_control_mode_obj) },
    // export class for method 'get_default_control_mode' response
    { MP_ROM_QSTR(MP_QSTR_resp_get_default_control_mode), MP_ROM_PTR(&mp_type_conopsget_default_control_modeResponseData) },
    // export request serializer function for method 'set_default_control_mode'
    { MP_ROM_QSTR(MP_QSTR_req_set_default_control_mode), MP_ROM_PTR(&req_set_default_control_mode_obj) },
    // export class for method 'set_default_control_mode' response
    { MP_ROM_QSTR(MP_QSTR_resp_set_default_control_mode), MP_ROM_PTR(&mp_type_conopsset_default_control_modeResponseData) },
    // export request serializer function for method 'set_force_allow_payloads'
    { MP_ROM_QSTR(MP_QSTR_req_set_force_allow_payloads), MP_ROM_PTR(&req_set_force_allow_payloads_obj) },
    // export class for method 'set_force_allow_payloads' response
    { MP_ROM_QSTR(MP_QSTR_resp_set_force_allow_payloads), MP_ROM_PTR(&mp_type_conopsset_force_allow_payloadsResponseData) },
    // export request serializer function for method 'get_force_allow_payloads'
    { MP_ROM_QSTR(MP_QSTR_req_get_force_allow_payloads), MP_ROM_PTR(&req_get_force_allow_payloads_obj) },
    // export class for method 'get_force_allow_payloads' response
    { MP_ROM_QSTR(MP_QSTR_resp_get_force_allow_payloads), MP_ROM_PTR(&mp_type_conopsget_force_allow_payloadsResponseData) },
    // export enumeration class for type 'ThresholdValueTypes'
    { MP_ROM_QSTR(MP_QSTR_ThresholdValueTypes), MP_ROM_PTR(&thresholdvaluetypes_class_type) },                        
    // export enumeration class for type 'OpModes'
    { MP_ROM_QSTR(MP_QSTR_OpModes), MP_ROM_PTR(&opmodes_class_type) },                        
    // export enumeration class for type 'AocsState'
    { MP_ROM_QSTR(MP_QSTR_AocsState), MP_ROM_PTR(&aocsstate_class_type) },                        
    // export enumeration class for type 'Events'
    { MP_ROM_QSTR(MP_QSTR_Events), MP_ROM_PTR(&events_class_type) },                        
    // export enumeration class for type 'StandardResult'
    { MP_ROM_QSTR(MP_QSTR_StandardResult), MP_ROM_PTR(&standardresult_class_type) },                        
    // export enumeration class for type 'SafeBool'
    { MP_ROM_QSTR(MP_QSTR_SafeBool), MP_ROM_PTR(&safebool_class_type) },                        
    // export enumeration class for type 'ModesWithDefCtrl'
    { MP_ROM_QSTR(MP_QSTR_ModesWithDefCtrl), MP_ROM_PTR(&modeswithdefctrl_class_type) },                        
    // export struct class objects for type 'ThresholdValues'
    { MP_ROM_QSTR(MP_QSTR_ThresholdValues_make_from_buf), MP_ROM_PTR(&ThresholdValues_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_ThresholdValues), MP_ROM_PTR(&ThresholdValues_type)},
    // export struct class objects for type 'AocsRefParams'
    { MP_ROM_QSTR(MP_QSTR_AocsRefParams_make_from_buf), MP_ROM_PTR(&AocsRefParams_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_AocsRefParams), MP_ROM_PTR(&AocsRefParams_type)},
    // export struct class objects for type 'ControlMode'
    { MP_ROM_QSTR(MP_QSTR_ControlMode_make_from_buf), MP_ROM_PTR(&ControlMode_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_ControlMode), MP_ROM_PTR(&ControlMode_type)},
};

/**********************************************************************
 *
 *  uPy C module registration
 *
 **********************************************************************/
STATIC MP_DEFINE_CONST_DICT(upy_conops_module_globals,
                            upy_conops_module_globals_table);

const mp_obj_module_t upy_conops_user_cmodule = {
    .base    = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&upy_conops_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_upy_conops, upy_conops_user_cmodule);
