/*!
********************************************************************************************
* @file upy_obc_cubeadcs_gen2.c
* @brief uPy C bindings generator
********************************************************************************************
* @version           interface OBC_CUBEADCS_GEN2 v5.0
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
 * @defgroup OBC_CUBEADCS_GEN2 OBC_CUBEADCS_GEN2
 * @{
 *
 * CubeADCS Gen 2 protocol as part of the Onboard Computer. Refer to the SDK documentation for further information on the GEN2.
 *
 * @file upy_obc_cubeadcs_gen2.c
 * @brief OBC_CUBEADCS_GEN2 uPython C wrapper module implementation
 *
 * This module is fully generated from a FIDL file and represents a uPython C extension module which
 * registers specific classes related to the communication interfaces of the OBC_CUBEADCS_GEN2 API. Users of
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
#include "FP_OBC_CUBEADCS_GEN2ProtocolTypes.h"

/**********************************************************************
 *
 *  uPy class definitions for struct types
 *
 **********************************************************************/

/**********************************************************************
 *
 *  uPy class definition for struct 'FName'
 *
 **********************************************************************/
    
// class structure for type FName
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_FName_t class_data;
} PACKED_STRUCT FName_class_obj_t;

// FName class constructor from field arguments
STATIC mp_obj_t FName_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    FName_class_obj_t *p_self = m_new_obj(FName_class_obj_t);
    p_self->base.type = type;
    
    // name
    upy_sd_copy_fidl_scalar_array_from_py_list_uint8_t(p_self->class_data.au8Name, 47, p_args[0]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'FName' getters
//

STATIC mp_obj_t FName_get_name(mp_obj_t self_in) 
{
    const FName_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return upy_sd_copy_fidl_scalar_array_to_py_list_uint8_t(p_self->class_data.au8Name, 47);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(FName_get_name_obj, FName_get_name);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t FName_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_name), MP_ROM_PTR(&FName_get_name_obj) },
};

STATIC MP_DEFINE_CONST_DICT(FName_locals_dict, FName_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    FName_type,
    MP_QSTR_FName,
    MP_TYPE_FLAG_NONE,
    make_new, FName_make_new,
    locals_dict, (mp_obj_dict_t*)&FName_locals_dict
);

STATIC mp_obj_t FName_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_FName_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    FName_class_obj_t *p_self = m_new_obj(FName_class_obj_t);
    p_self->base.type = &FName_type;
    
    const OBC_CUBEADCS_GEN2_FName_t *p_data = (const OBC_CUBEADCS_GEN2_FName_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// FName class constructor from a byte buffer
STATIC mp_obj_t FName_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return FName_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_FName_t, FName_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_FName_t, FName_class_obj_t, FName)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(FName_make_from_buf_obj, FName_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'telemetry_mask_2'
 *
 **********************************************************************/
    
// class structure for type telemetry_mask_2
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_telemetry_mask_2_t class_data;
} PACKED_STRUCT telemetry_mask_2_class_obj_t;

// telemetry_mask_2 class constructor from field arguments
STATIC mp_obj_t telemetry_mask_2_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 8, 8, false);
    
    telemetry_mask_2_class_obj_t *p_self = m_new_obj(telemetry_mask_2_class_obj_t);
    p_self->base.type = type;
    
    // en_get_raw_gyr_sensor_telemetry
    p_self->class_data.bEn_get_raw_gyr_sensor_telemetry = (bool) mp_obj_get_int(p_args[0]);
    // en_get_raw_rwl_sensor_telemetry
    p_self->class_data.bEn_get_raw_rwl_sensor_telemetry = (bool) mp_obj_get_int(p_args[1]);
    // en_get_calibrated_css_sensor_telemetry
    p_self->class_data.bEn_get_calibrated_css_sensor_telemetry = (bool) mp_obj_get_int(p_args[2]);
    // en_get_calibrated_gyr_sensor_telemetry
    p_self->class_data.bEn_get_calibrated_gyr_sensor_telemetry = (bool) mp_obj_get_int(p_args[3]);
    // en_get_calibrated_str_sensor_telemetry
    p_self->class_data.bEn_get_calibrated_str_sensor_telemetry = (bool) mp_obj_get_int(p_args[4]);
    // en_get_calibrated_rwl_sensor_telemetry
    p_self->class_data.bEn_get_calibrated_rwl_sensor_telemetry = (bool) mp_obj_get_int(p_args[5]);
    // en_get_main_estimator_telemetry
    p_self->class_data.bEn_get_main_estimator_telemetry = (bool) mp_obj_get_int(p_args[6]);
    // en_get_main_estimator_high_resolution_telemetry
    p_self->class_data.bEn_get_main_estimator_high_resolution_telemetry = (bool) mp_obj_get_int(p_args[7]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'telemetry_mask_2' getters
//

STATIC mp_obj_t telemetry_mask_2_get_en_get_raw_gyr_sensor_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_2_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_raw_gyr_sensor_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_2_get_en_get_raw_gyr_sensor_telemetry_obj, telemetry_mask_2_get_en_get_raw_gyr_sensor_telemetry);

STATIC mp_obj_t telemetry_mask_2_get_en_get_raw_rwl_sensor_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_2_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_raw_rwl_sensor_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_2_get_en_get_raw_rwl_sensor_telemetry_obj, telemetry_mask_2_get_en_get_raw_rwl_sensor_telemetry);

STATIC mp_obj_t telemetry_mask_2_get_en_get_calibrated_css_sensor_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_2_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_calibrated_css_sensor_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_2_get_en_get_calibrated_css_sensor_telemetry_obj, telemetry_mask_2_get_en_get_calibrated_css_sensor_telemetry);

STATIC mp_obj_t telemetry_mask_2_get_en_get_calibrated_gyr_sensor_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_2_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_calibrated_gyr_sensor_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_2_get_en_get_calibrated_gyr_sensor_telemetry_obj, telemetry_mask_2_get_en_get_calibrated_gyr_sensor_telemetry);

STATIC mp_obj_t telemetry_mask_2_get_en_get_calibrated_str_sensor_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_2_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_calibrated_str_sensor_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_2_get_en_get_calibrated_str_sensor_telemetry_obj, telemetry_mask_2_get_en_get_calibrated_str_sensor_telemetry);

STATIC mp_obj_t telemetry_mask_2_get_en_get_calibrated_rwl_sensor_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_2_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_calibrated_rwl_sensor_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_2_get_en_get_calibrated_rwl_sensor_telemetry_obj, telemetry_mask_2_get_en_get_calibrated_rwl_sensor_telemetry);

STATIC mp_obj_t telemetry_mask_2_get_en_get_main_estimator_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_2_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_main_estimator_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_2_get_en_get_main_estimator_telemetry_obj, telemetry_mask_2_get_en_get_main_estimator_telemetry);

STATIC mp_obj_t telemetry_mask_2_get_en_get_main_estimator_high_resolution_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_2_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_main_estimator_high_resolution_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_2_get_en_get_main_estimator_high_resolution_telemetry_obj, telemetry_mask_2_get_en_get_main_estimator_high_resolution_telemetry);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t telemetry_mask_2_locals_dict_table[8] = {
    { MP_ROM_QSTR(MP_QSTR_get_en_get_raw_gyr_sensor_telemetry), MP_ROM_PTR(&telemetry_mask_2_get_en_get_raw_gyr_sensor_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_raw_rwl_sensor_telemetry), MP_ROM_PTR(&telemetry_mask_2_get_en_get_raw_rwl_sensor_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_calibrated_css_sensor_telemetry), MP_ROM_PTR(&telemetry_mask_2_get_en_get_calibrated_css_sensor_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_calibrated_gyr_sensor_telemetry), MP_ROM_PTR(&telemetry_mask_2_get_en_get_calibrated_gyr_sensor_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_calibrated_str_sensor_telemetry), MP_ROM_PTR(&telemetry_mask_2_get_en_get_calibrated_str_sensor_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_calibrated_rwl_sensor_telemetry), MP_ROM_PTR(&telemetry_mask_2_get_en_get_calibrated_rwl_sensor_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_main_estimator_telemetry), MP_ROM_PTR(&telemetry_mask_2_get_en_get_main_estimator_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_main_estimator_high_resolution_telemetry), MP_ROM_PTR(&telemetry_mask_2_get_en_get_main_estimator_high_resolution_telemetry_obj) },
};

STATIC MP_DEFINE_CONST_DICT(telemetry_mask_2_locals_dict, telemetry_mask_2_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    telemetry_mask_2_type,
    MP_QSTR_telemetry_mask_2,
    MP_TYPE_FLAG_NONE,
    make_new, telemetry_mask_2_make_new,
    locals_dict, (mp_obj_dict_t*)&telemetry_mask_2_locals_dict
);

STATIC mp_obj_t telemetry_mask_2_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_telemetry_mask_2_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    telemetry_mask_2_class_obj_t *p_self = m_new_obj(telemetry_mask_2_class_obj_t);
    p_self->base.type = &telemetry_mask_2_type;
    
    const OBC_CUBEADCS_GEN2_telemetry_mask_2_t *p_data = (const OBC_CUBEADCS_GEN2_telemetry_mask_2_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// telemetry_mask_2 class constructor from a byte buffer
STATIC mp_obj_t telemetry_mask_2_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return telemetry_mask_2_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_telemetry_mask_2_t, telemetry_mask_2_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_telemetry_mask_2_t, telemetry_mask_2_class_obj_t, telemetry_mask_2)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_2_make_from_buf_obj, telemetry_mask_2_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'CompErrCodes'
 *
 **********************************************************************/
    
// class structure for type CompErrCodes
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_CompErrCodes_t class_data;
} PACKED_STRUCT CompErrCodes_class_obj_t;

// CompErrCodes class constructor from field arguments
STATIC mp_obj_t CompErrCodes_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 6, 6, false);
    
    CompErrCodes_class_obj_t *p_self = m_new_obj(CompErrCodes_class_obj_t);
    p_self->base.type = type;
    
    // MasterSvc
    p_self->class_data.u32MasterSvc = (uint32_t) mp_obj_get_int(p_args[0]);
    // FramFsSvc
    p_self->class_data.u32FramFsSvc = (uint32_t) mp_obj_get_int(p_args[1]);
    // EventLogSvc
    p_self->class_data.u32EventLogSvc = (uint32_t) mp_obj_get_int(p_args[2]);
    // ImgLogSvc
    p_self->class_data.u32ImgLogSvc = (uint32_t) mp_obj_get_int(p_args[3]);
    // TlmLogSvc
    p_self->class_data.u32TlmLogSvc = (uint32_t) mp_obj_get_int(p_args[4]);
    // ImuSvc
    p_self->class_data.u32ImuSvc = (uint32_t) mp_obj_get_int(p_args[5]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'CompErrCodes' getters
//

STATIC mp_obj_t CompErrCodes_get_MasterSvc(mp_obj_t self_in) 
{
    const CompErrCodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32MasterSvc);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(CompErrCodes_get_MasterSvc_obj, CompErrCodes_get_MasterSvc);

STATIC mp_obj_t CompErrCodes_get_FramFsSvc(mp_obj_t self_in) 
{
    const CompErrCodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32FramFsSvc);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(CompErrCodes_get_FramFsSvc_obj, CompErrCodes_get_FramFsSvc);

STATIC mp_obj_t CompErrCodes_get_EventLogSvc(mp_obj_t self_in) 
{
    const CompErrCodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32EventLogSvc);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(CompErrCodes_get_EventLogSvc_obj, CompErrCodes_get_EventLogSvc);

STATIC mp_obj_t CompErrCodes_get_ImgLogSvc(mp_obj_t self_in) 
{
    const CompErrCodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32ImgLogSvc);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(CompErrCodes_get_ImgLogSvc_obj, CompErrCodes_get_ImgLogSvc);

STATIC mp_obj_t CompErrCodes_get_TlmLogSvc(mp_obj_t self_in) 
{
    const CompErrCodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32TlmLogSvc);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(CompErrCodes_get_TlmLogSvc_obj, CompErrCodes_get_TlmLogSvc);

STATIC mp_obj_t CompErrCodes_get_ImuSvc(mp_obj_t self_in) 
{
    const CompErrCodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32ImuSvc);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(CompErrCodes_get_ImuSvc_obj, CompErrCodes_get_ImuSvc);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t CompErrCodes_locals_dict_table[6] = {
    { MP_ROM_QSTR(MP_QSTR_get_MasterSvc), MP_ROM_PTR(&CompErrCodes_get_MasterSvc_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_FramFsSvc), MP_ROM_PTR(&CompErrCodes_get_FramFsSvc_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_EventLogSvc), MP_ROM_PTR(&CompErrCodes_get_EventLogSvc_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ImgLogSvc), MP_ROM_PTR(&CompErrCodes_get_ImgLogSvc_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_TlmLogSvc), MP_ROM_PTR(&CompErrCodes_get_TlmLogSvc_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ImuSvc), MP_ROM_PTR(&CompErrCodes_get_ImuSvc_obj) },
};

STATIC MP_DEFINE_CONST_DICT(CompErrCodes_locals_dict, CompErrCodes_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    CompErrCodes_type,
    MP_QSTR_CompErrCodes,
    MP_TYPE_FLAG_NONE,
    make_new, CompErrCodes_make_new,
    locals_dict, (mp_obj_dict_t*)&CompErrCodes_locals_dict
);

STATIC mp_obj_t CompErrCodes_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_CompErrCodes_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    CompErrCodes_class_obj_t *p_self = m_new_obj(CompErrCodes_class_obj_t);
    p_self->base.type = &CompErrCodes_type;
    
    const OBC_CUBEADCS_GEN2_CompErrCodes_t *p_data = (const OBC_CUBEADCS_GEN2_CompErrCodes_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// CompErrCodes class constructor from a byte buffer
STATIC mp_obj_t CompErrCodes_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return CompErrCodes_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_CompErrCodes_t, CompErrCodes_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_CompErrCodes_t, CompErrCodes_class_obj_t, CompErrCodes)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(CompErrCodes_make_from_buf_obj, CompErrCodes_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'telemetry_mask_1'
 *
 **********************************************************************/
    
// class structure for type telemetry_mask_1
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_telemetry_mask_1_t class_data;
} PACKED_STRUCT telemetry_mask_1_class_obj_t;

// telemetry_mask_1 class constructor from field arguments
STATIC mp_obj_t telemetry_mask_1_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 8, 8, false);
    
    telemetry_mask_1_class_obj_t *p_self = m_new_obj(telemetry_mask_1_class_obj_t);
    p_self->base.type = type;
    
    // en_get_models_telemetry
    p_self->class_data.bEn_get_models_telemetry = (bool) mp_obj_get_int(p_args[0]);
    // en_get_calibrated_gnss_sensor_telemetry
    p_self->class_data.bEn_get_calibrated_gnss_sensor_telemetry = (bool) mp_obj_get_int(p_args[1]);
    // en_get_calibrated_hss_sensor_telemetry
    p_self->class_data.bEn_get_calibrated_hss_sensor_telemetry = (bool) mp_obj_get_int(p_args[2]);
    // en_get_calibrated_mag_sensor_telemetry
    p_self->class_data.bEn_get_calibrated_mag_sensor_telemetry = (bool) mp_obj_get_int(p_args[3]);
    // en_get_calibrated_fss_sensor_telemetry
    p_self->class_data.bEn_get_calibrated_fss_sensor_telemetry = (bool) mp_obj_get_int(p_args[4]);
    // en_get_raw_cubesense_earth_telemetry
    p_self->class_data.bEn_get_raw_cubesense_earth_telemetry = (bool) mp_obj_get_int(p_args[5]);
    // en_get_raw_mag_sensor_telemetry
    p_self->class_data.bEn_get_raw_mag_sensor_telemetry = (bool) mp_obj_get_int(p_args[6]);
    // en_get_raw_css_sensor_telemetry
    p_self->class_data.bEn_get_raw_css_sensor_telemetry = (bool) mp_obj_get_int(p_args[7]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'telemetry_mask_1' getters
//

STATIC mp_obj_t telemetry_mask_1_get_en_get_models_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_1_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_models_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_1_get_en_get_models_telemetry_obj, telemetry_mask_1_get_en_get_models_telemetry);

STATIC mp_obj_t telemetry_mask_1_get_en_get_calibrated_gnss_sensor_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_1_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_calibrated_gnss_sensor_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_1_get_en_get_calibrated_gnss_sensor_telemetry_obj, telemetry_mask_1_get_en_get_calibrated_gnss_sensor_telemetry);

STATIC mp_obj_t telemetry_mask_1_get_en_get_calibrated_hss_sensor_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_1_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_calibrated_hss_sensor_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_1_get_en_get_calibrated_hss_sensor_telemetry_obj, telemetry_mask_1_get_en_get_calibrated_hss_sensor_telemetry);

STATIC mp_obj_t telemetry_mask_1_get_en_get_calibrated_mag_sensor_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_1_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_calibrated_mag_sensor_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_1_get_en_get_calibrated_mag_sensor_telemetry_obj, telemetry_mask_1_get_en_get_calibrated_mag_sensor_telemetry);

STATIC mp_obj_t telemetry_mask_1_get_en_get_calibrated_fss_sensor_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_1_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_calibrated_fss_sensor_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_1_get_en_get_calibrated_fss_sensor_telemetry_obj, telemetry_mask_1_get_en_get_calibrated_fss_sensor_telemetry);

STATIC mp_obj_t telemetry_mask_1_get_en_get_raw_cubesense_earth_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_1_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_raw_cubesense_earth_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_1_get_en_get_raw_cubesense_earth_telemetry_obj, telemetry_mask_1_get_en_get_raw_cubesense_earth_telemetry);

STATIC mp_obj_t telemetry_mask_1_get_en_get_raw_mag_sensor_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_1_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_raw_mag_sensor_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_1_get_en_get_raw_mag_sensor_telemetry_obj, telemetry_mask_1_get_en_get_raw_mag_sensor_telemetry);

STATIC mp_obj_t telemetry_mask_1_get_en_get_raw_css_sensor_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_1_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_raw_css_sensor_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_1_get_en_get_raw_css_sensor_telemetry_obj, telemetry_mask_1_get_en_get_raw_css_sensor_telemetry);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t telemetry_mask_1_locals_dict_table[8] = {
    { MP_ROM_QSTR(MP_QSTR_get_en_get_models_telemetry), MP_ROM_PTR(&telemetry_mask_1_get_en_get_models_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_calibrated_gnss_sensor_telemetry), MP_ROM_PTR(&telemetry_mask_1_get_en_get_calibrated_gnss_sensor_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_calibrated_hss_sensor_telemetry), MP_ROM_PTR(&telemetry_mask_1_get_en_get_calibrated_hss_sensor_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_calibrated_mag_sensor_telemetry), MP_ROM_PTR(&telemetry_mask_1_get_en_get_calibrated_mag_sensor_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_calibrated_fss_sensor_telemetry), MP_ROM_PTR(&telemetry_mask_1_get_en_get_calibrated_fss_sensor_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_raw_cubesense_earth_telemetry), MP_ROM_PTR(&telemetry_mask_1_get_en_get_raw_cubesense_earth_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_raw_mag_sensor_telemetry), MP_ROM_PTR(&telemetry_mask_1_get_en_get_raw_mag_sensor_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_raw_css_sensor_telemetry), MP_ROM_PTR(&telemetry_mask_1_get_en_get_raw_css_sensor_telemetry_obj) },
};

STATIC MP_DEFINE_CONST_DICT(telemetry_mask_1_locals_dict, telemetry_mask_1_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    telemetry_mask_1_type,
    MP_QSTR_telemetry_mask_1,
    MP_TYPE_FLAG_NONE,
    make_new, telemetry_mask_1_make_new,
    locals_dict, (mp_obj_dict_t*)&telemetry_mask_1_locals_dict
);

STATIC mp_obj_t telemetry_mask_1_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_telemetry_mask_1_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    telemetry_mask_1_class_obj_t *p_self = m_new_obj(telemetry_mask_1_class_obj_t);
    p_self->base.type = &telemetry_mask_1_type;
    
    const OBC_CUBEADCS_GEN2_telemetry_mask_1_t *p_data = (const OBC_CUBEADCS_GEN2_telemetry_mask_1_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// telemetry_mask_1 class constructor from a byte buffer
STATIC mp_obj_t telemetry_mask_1_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return telemetry_mask_1_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_telemetry_mask_1_t, telemetry_mask_1_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_telemetry_mask_1_t, telemetry_mask_1_class_obj_t, telemetry_mask_1)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_1_make_from_buf_obj, telemetry_mask_1_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'telemetry_mask_4'
 *
 **********************************************************************/
    
// class structure for type telemetry_mask_4
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_telemetry_mask_4_t class_data;
} PACKED_STRUCT telemetry_mask_4_class_obj_t;

// telemetry_mask_4 class constructor from field arguments
STATIC mp_obj_t telemetry_mask_4_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 8, 8, false);
    
    telemetry_mask_4_class_obj_t *p_self = m_new_obj(telemetry_mask_4_class_obj_t);
    p_self->base.type = type;
    
    // en_get_health_telemetry_for_cubestar
    p_self->class_data.bEn_get_health_telemetry_for_cubestar = (bool) mp_obj_get_int(p_args[0]);
    // reserved_0
    p_self->class_data.bReserved_0 = (bool) mp_obj_get_int(p_args[1]);
    // reserved_1
    p_self->class_data.bReserved_1 = (bool) mp_obj_get_int(p_args[2]);
    // reserved_2
    p_self->class_data.bReserved_2 = (bool) mp_obj_get_int(p_args[3]);
    // reserved_3
    p_self->class_data.bReserved_3 = (bool) mp_obj_get_int(p_args[4]);
    // reserved_4
    p_self->class_data.bReserved_4 = (bool) mp_obj_get_int(p_args[5]);
    // reserved_5
    p_self->class_data.bReserved_5 = (bool) mp_obj_get_int(p_args[6]);
    // reserved_6
    p_self->class_data.bReserved_6 = (bool) mp_obj_get_int(p_args[7]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'telemetry_mask_4' getters
//

STATIC mp_obj_t telemetry_mask_4_get_en_get_health_telemetry_for_cubestar(mp_obj_t self_in) 
{
    const telemetry_mask_4_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_health_telemetry_for_cubestar);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_4_get_en_get_health_telemetry_for_cubestar_obj, telemetry_mask_4_get_en_get_health_telemetry_for_cubestar);

STATIC mp_obj_t telemetry_mask_4_get_reserved_0(mp_obj_t self_in) 
{
    const telemetry_mask_4_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bReserved_0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_4_get_reserved_0_obj, telemetry_mask_4_get_reserved_0);

STATIC mp_obj_t telemetry_mask_4_get_reserved_1(mp_obj_t self_in) 
{
    const telemetry_mask_4_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bReserved_1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_4_get_reserved_1_obj, telemetry_mask_4_get_reserved_1);

STATIC mp_obj_t telemetry_mask_4_get_reserved_2(mp_obj_t self_in) 
{
    const telemetry_mask_4_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bReserved_2);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_4_get_reserved_2_obj, telemetry_mask_4_get_reserved_2);

STATIC mp_obj_t telemetry_mask_4_get_reserved_3(mp_obj_t self_in) 
{
    const telemetry_mask_4_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bReserved_3);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_4_get_reserved_3_obj, telemetry_mask_4_get_reserved_3);

STATIC mp_obj_t telemetry_mask_4_get_reserved_4(mp_obj_t self_in) 
{
    const telemetry_mask_4_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bReserved_4);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_4_get_reserved_4_obj, telemetry_mask_4_get_reserved_4);

STATIC mp_obj_t telemetry_mask_4_get_reserved_5(mp_obj_t self_in) 
{
    const telemetry_mask_4_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bReserved_5);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_4_get_reserved_5_obj, telemetry_mask_4_get_reserved_5);

STATIC mp_obj_t telemetry_mask_4_get_reserved_6(mp_obj_t self_in) 
{
    const telemetry_mask_4_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bReserved_6);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_4_get_reserved_6_obj, telemetry_mask_4_get_reserved_6);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t telemetry_mask_4_locals_dict_table[8] = {
    { MP_ROM_QSTR(MP_QSTR_get_en_get_health_telemetry_for_cubestar), MP_ROM_PTR(&telemetry_mask_4_get_en_get_health_telemetry_for_cubestar_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_reserved_0), MP_ROM_PTR(&telemetry_mask_4_get_reserved_0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_reserved_1), MP_ROM_PTR(&telemetry_mask_4_get_reserved_1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_reserved_2), MP_ROM_PTR(&telemetry_mask_4_get_reserved_2_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_reserved_3), MP_ROM_PTR(&telemetry_mask_4_get_reserved_3_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_reserved_4), MP_ROM_PTR(&telemetry_mask_4_get_reserved_4_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_reserved_5), MP_ROM_PTR(&telemetry_mask_4_get_reserved_5_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_reserved_6), MP_ROM_PTR(&telemetry_mask_4_get_reserved_6_obj) },
};

STATIC MP_DEFINE_CONST_DICT(telemetry_mask_4_locals_dict, telemetry_mask_4_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    telemetry_mask_4_type,
    MP_QSTR_telemetry_mask_4,
    MP_TYPE_FLAG_NONE,
    make_new, telemetry_mask_4_make_new,
    locals_dict, (mp_obj_dict_t*)&telemetry_mask_4_locals_dict
);

STATIC mp_obj_t telemetry_mask_4_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_telemetry_mask_4_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    telemetry_mask_4_class_obj_t *p_self = m_new_obj(telemetry_mask_4_class_obj_t);
    p_self->base.type = &telemetry_mask_4_type;
    
    const OBC_CUBEADCS_GEN2_telemetry_mask_4_t *p_data = (const OBC_CUBEADCS_GEN2_telemetry_mask_4_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// telemetry_mask_4 class constructor from a byte buffer
STATIC mp_obj_t telemetry_mask_4_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return telemetry_mask_4_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_telemetry_mask_4_t, telemetry_mask_4_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_telemetry_mask_4_t, telemetry_mask_4_class_obj_t, telemetry_mask_4)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_4_make_from_buf_obj, telemetry_mask_4_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'telemetry_mask_3'
 *
 **********************************************************************/
    
// class structure for type telemetry_mask_3
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_telemetry_mask_3_t class_data;
} PACKED_STRUCT telemetry_mask_3_class_obj_t;

// telemetry_mask_3 class constructor from field arguments
STATIC mp_obj_t telemetry_mask_3_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 8, 8, false);
    
    telemetry_mask_3_class_obj_t *p_self = m_new_obj(telemetry_mask_3_class_obj_t);
    p_self->base.type = type;
    
    // en_get_raw_gnss_sensor_telemetry
    p_self->class_data.bEn_get_raw_gnss_sensor_telemetry = (bool) mp_obj_get_int(p_args[0]);
    // en_get_raw_pst3s_star_tracker_telemetry
    p_self->class_data.bEn_get_raw_pst3s_star_tracker_telemetry = (bool) mp_obj_get_int(p_args[1]);
    // en_get_acp_execution_telemetry
    p_self->class_data.bEn_get_acp_execution_telemetry = (bool) mp_obj_get_int(p_args[2]);
    // en_get_cubecomputer_health
    p_self->class_data.bEn_get_cubecomputer_health = (bool) mp_obj_get_int(p_args[3]);
    // en_get_health_telemetry_for_cubesense_earth
    p_self->class_data.bEn_get_health_telemetry_for_cubesense_earth = (bool) mp_obj_get_int(p_args[4]);
    // en_get_health_telemetry_for_reaction_wheels
    p_self->class_data.bEn_get_health_telemetry_for_reaction_wheels = (bool) mp_obj_get_int(p_args[5]);
    // en_get_health_telemetry_for_cubenode_nssrwl
    p_self->class_data.bEn_get_health_telemetry_for_cubenode_nssrwl = (bool) mp_obj_get_int(p_args[6]);
    // en_get_raw_nssrwl_sensor_telemetry
    p_self->class_data.bEn_get_raw_nssrwl_sensor_telemetry = (bool) mp_obj_get_int(p_args[7]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'telemetry_mask_3' getters
//

STATIC mp_obj_t telemetry_mask_3_get_en_get_raw_gnss_sensor_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_3_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_raw_gnss_sensor_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_3_get_en_get_raw_gnss_sensor_telemetry_obj, telemetry_mask_3_get_en_get_raw_gnss_sensor_telemetry);

STATIC mp_obj_t telemetry_mask_3_get_en_get_raw_pst3s_star_tracker_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_3_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_raw_pst3s_star_tracker_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_3_get_en_get_raw_pst3s_star_tracker_telemetry_obj, telemetry_mask_3_get_en_get_raw_pst3s_star_tracker_telemetry);

STATIC mp_obj_t telemetry_mask_3_get_en_get_acp_execution_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_3_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_acp_execution_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_3_get_en_get_acp_execution_telemetry_obj, telemetry_mask_3_get_en_get_acp_execution_telemetry);

STATIC mp_obj_t telemetry_mask_3_get_en_get_cubecomputer_health(mp_obj_t self_in) 
{
    const telemetry_mask_3_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_cubecomputer_health);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_3_get_en_get_cubecomputer_health_obj, telemetry_mask_3_get_en_get_cubecomputer_health);

STATIC mp_obj_t telemetry_mask_3_get_en_get_health_telemetry_for_cubesense_earth(mp_obj_t self_in) 
{
    const telemetry_mask_3_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_health_telemetry_for_cubesense_earth);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_3_get_en_get_health_telemetry_for_cubesense_earth_obj, telemetry_mask_3_get_en_get_health_telemetry_for_cubesense_earth);

STATIC mp_obj_t telemetry_mask_3_get_en_get_health_telemetry_for_reaction_wheels(mp_obj_t self_in) 
{
    const telemetry_mask_3_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_health_telemetry_for_reaction_wheels);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_3_get_en_get_health_telemetry_for_reaction_wheels_obj, telemetry_mask_3_get_en_get_health_telemetry_for_reaction_wheels);

STATIC mp_obj_t telemetry_mask_3_get_en_get_health_telemetry_for_cubenode_nssrwl(mp_obj_t self_in) 
{
    const telemetry_mask_3_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_health_telemetry_for_cubenode_nssrwl);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_3_get_en_get_health_telemetry_for_cubenode_nssrwl_obj, telemetry_mask_3_get_en_get_health_telemetry_for_cubenode_nssrwl);

STATIC mp_obj_t telemetry_mask_3_get_en_get_raw_nssrwl_sensor_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_3_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_raw_nssrwl_sensor_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_3_get_en_get_raw_nssrwl_sensor_telemetry_obj, telemetry_mask_3_get_en_get_raw_nssrwl_sensor_telemetry);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t telemetry_mask_3_locals_dict_table[8] = {
    { MP_ROM_QSTR(MP_QSTR_get_en_get_raw_gnss_sensor_telemetry), MP_ROM_PTR(&telemetry_mask_3_get_en_get_raw_gnss_sensor_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_raw_pst3s_star_tracker_telemetry), MP_ROM_PTR(&telemetry_mask_3_get_en_get_raw_pst3s_star_tracker_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_acp_execution_telemetry), MP_ROM_PTR(&telemetry_mask_3_get_en_get_acp_execution_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_cubecomputer_health), MP_ROM_PTR(&telemetry_mask_3_get_en_get_cubecomputer_health_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_health_telemetry_for_cubesense_earth), MP_ROM_PTR(&telemetry_mask_3_get_en_get_health_telemetry_for_cubesense_earth_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_health_telemetry_for_reaction_wheels), MP_ROM_PTR(&telemetry_mask_3_get_en_get_health_telemetry_for_reaction_wheels_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_health_telemetry_for_cubenode_nssrwl), MP_ROM_PTR(&telemetry_mask_3_get_en_get_health_telemetry_for_cubenode_nssrwl_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_raw_nssrwl_sensor_telemetry), MP_ROM_PTR(&telemetry_mask_3_get_en_get_raw_nssrwl_sensor_telemetry_obj) },
};

STATIC MP_DEFINE_CONST_DICT(telemetry_mask_3_locals_dict, telemetry_mask_3_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    telemetry_mask_3_type,
    MP_QSTR_telemetry_mask_3,
    MP_TYPE_FLAG_NONE,
    make_new, telemetry_mask_3_make_new,
    locals_dict, (mp_obj_dict_t*)&telemetry_mask_3_locals_dict
);

STATIC mp_obj_t telemetry_mask_3_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_telemetry_mask_3_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    telemetry_mask_3_class_obj_t *p_self = m_new_obj(telemetry_mask_3_class_obj_t);
    p_self->base.type = &telemetry_mask_3_type;
    
    const OBC_CUBEADCS_GEN2_telemetry_mask_3_t *p_data = (const OBC_CUBEADCS_GEN2_telemetry_mask_3_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// telemetry_mask_3 class constructor from a byte buffer
STATIC mp_obj_t telemetry_mask_3_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return telemetry_mask_3_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_telemetry_mask_3_t, telemetry_mask_3_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_telemetry_mask_3_t, telemetry_mask_3_class_obj_t, telemetry_mask_3)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_3_make_from_buf_obj, telemetry_mask_3_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'telemetry_mask_0'
 *
 **********************************************************************/
    
// class structure for type telemetry_mask_0
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_telemetry_mask_0_t class_data;
} PACKED_STRUCT telemetry_mask_0_class_obj_t;

// telemetry_mask_0 class constructor from field arguments
STATIC mp_obj_t telemetry_mask_0_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 8, 8, false);
    
    telemetry_mask_0_class_obj_t *p_self = m_new_obj(telemetry_mask_0_class_obj_t);
    p_self->base.type = type;
    
    // en_get_health_tlm_for_cubenode_pst3s
    p_self->class_data.bEn_get_health_tlm_for_cubenode_pst3s = (bool) mp_obj_get_int(p_args[0]);
    // en_get_health_tlm_for_cubemag_magnetometer
    p_self->class_data.bEn_get_health_tlm_for_cubemag_magnetometer = (bool) mp_obj_get_int(p_args[1]);
    // en_get_health_tlm_for_cubesense_sun
    p_self->class_data.bEn_get_health_tlm_for_cubesense_sun = (bool) mp_obj_get_int(p_args[2]);
    // en_get_torquer_current_measurements
    p_self->class_data.bEn_get_torquer_current_measurements = (bool) mp_obj_get_int(p_args[3]);
    // en_get_raw_cubesense_sun_telemetry
    p_self->class_data.bEn_get_raw_cubesense_sun_telemetry = (bool) mp_obj_get_int(p_args[4]);
    // en_get_raw_external_sensor_telemetry
    p_self->class_data.bEn_get_raw_external_sensor_telemetry = (bool) mp_obj_get_int(p_args[5]);
    // en_get_controller_telemetry
    p_self->class_data.bEn_get_controller_telemetry = (bool) mp_obj_get_int(p_args[6]);
    // en_get_backup_estimator_telemetry
    p_self->class_data.bEn_get_backup_estimator_telemetry = (bool) mp_obj_get_int(p_args[7]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'telemetry_mask_0' getters
//

STATIC mp_obj_t telemetry_mask_0_get_en_get_health_tlm_for_cubenode_pst3s(mp_obj_t self_in) 
{
    const telemetry_mask_0_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_health_tlm_for_cubenode_pst3s);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_0_get_en_get_health_tlm_for_cubenode_pst3s_obj, telemetry_mask_0_get_en_get_health_tlm_for_cubenode_pst3s);

STATIC mp_obj_t telemetry_mask_0_get_en_get_health_tlm_for_cubemag_magnetometer(mp_obj_t self_in) 
{
    const telemetry_mask_0_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_health_tlm_for_cubemag_magnetometer);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_0_get_en_get_health_tlm_for_cubemag_magnetometer_obj, telemetry_mask_0_get_en_get_health_tlm_for_cubemag_magnetometer);

STATIC mp_obj_t telemetry_mask_0_get_en_get_health_tlm_for_cubesense_sun(mp_obj_t self_in) 
{
    const telemetry_mask_0_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_health_tlm_for_cubesense_sun);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_0_get_en_get_health_tlm_for_cubesense_sun_obj, telemetry_mask_0_get_en_get_health_tlm_for_cubesense_sun);

STATIC mp_obj_t telemetry_mask_0_get_en_get_torquer_current_measurements(mp_obj_t self_in) 
{
    const telemetry_mask_0_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_torquer_current_measurements);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_0_get_en_get_torquer_current_measurements_obj, telemetry_mask_0_get_en_get_torquer_current_measurements);

STATIC mp_obj_t telemetry_mask_0_get_en_get_raw_cubesense_sun_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_0_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_raw_cubesense_sun_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_0_get_en_get_raw_cubesense_sun_telemetry_obj, telemetry_mask_0_get_en_get_raw_cubesense_sun_telemetry);

STATIC mp_obj_t telemetry_mask_0_get_en_get_raw_external_sensor_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_0_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_raw_external_sensor_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_0_get_en_get_raw_external_sensor_telemetry_obj, telemetry_mask_0_get_en_get_raw_external_sensor_telemetry);

STATIC mp_obj_t telemetry_mask_0_get_en_get_controller_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_0_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_controller_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_0_get_en_get_controller_telemetry_obj, telemetry_mask_0_get_en_get_controller_telemetry);

STATIC mp_obj_t telemetry_mask_0_get_en_get_backup_estimator_telemetry(mp_obj_t self_in) 
{
    const telemetry_mask_0_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEn_get_backup_estimator_telemetry);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_0_get_en_get_backup_estimator_telemetry_obj, telemetry_mask_0_get_en_get_backup_estimator_telemetry);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t telemetry_mask_0_locals_dict_table[8] = {
    { MP_ROM_QSTR(MP_QSTR_get_en_get_health_tlm_for_cubenode_pst3s), MP_ROM_PTR(&telemetry_mask_0_get_en_get_health_tlm_for_cubenode_pst3s_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_health_tlm_for_cubemag_magnetometer), MP_ROM_PTR(&telemetry_mask_0_get_en_get_health_tlm_for_cubemag_magnetometer_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_health_tlm_for_cubesense_sun), MP_ROM_PTR(&telemetry_mask_0_get_en_get_health_tlm_for_cubesense_sun_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_torquer_current_measurements), MP_ROM_PTR(&telemetry_mask_0_get_en_get_torquer_current_measurements_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_raw_cubesense_sun_telemetry), MP_ROM_PTR(&telemetry_mask_0_get_en_get_raw_cubesense_sun_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_raw_external_sensor_telemetry), MP_ROM_PTR(&telemetry_mask_0_get_en_get_raw_external_sensor_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_controller_telemetry), MP_ROM_PTR(&telemetry_mask_0_get_en_get_controller_telemetry_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_en_get_backup_estimator_telemetry), MP_ROM_PTR(&telemetry_mask_0_get_en_get_backup_estimator_telemetry_obj) },
};

STATIC MP_DEFINE_CONST_DICT(telemetry_mask_0_locals_dict, telemetry_mask_0_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    telemetry_mask_0_type,
    MP_QSTR_telemetry_mask_0,
    MP_TYPE_FLAG_NONE,
    make_new, telemetry_mask_0_make_new,
    locals_dict, (mp_obj_dict_t*)&telemetry_mask_0_locals_dict
);

STATIC mp_obj_t telemetry_mask_0_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_telemetry_mask_0_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    telemetry_mask_0_class_obj_t *p_self = m_new_obj(telemetry_mask_0_class_obj_t);
    p_self->base.type = &telemetry_mask_0_type;
    
    const OBC_CUBEADCS_GEN2_telemetry_mask_0_t *p_data = (const OBC_CUBEADCS_GEN2_telemetry_mask_0_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// telemetry_mask_0 class constructor from a byte buffer
STATIC mp_obj_t telemetry_mask_0_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return telemetry_mask_0_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_telemetry_mask_0_t, telemetry_mask_0_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_telemetry_mask_0_t, telemetry_mask_0_class_obj_t, telemetry_mask_0)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(telemetry_mask_0_make_from_buf_obj, telemetry_mask_0_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'events'
 *
 **********************************************************************/
    
// class structure for type events
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_events_t class_data;
} PACKED_STRUCT events_class_obj_t;

// events class constructor from field arguments
STATIC mp_obj_t events_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 15, 15, false);
    
    events_class_obj_t *p_self = m_new_obj(events_class_obj_t);
    p_self->base.type = type;
    
    // node_comm_error
    p_self->class_data.u16Node_comm_error = (uint16_t) mp_obj_get_int(p_args[0]);
    // adcs_config_validation_error
    p_self->class_data.u16Adcs_config_validation_error = (uint16_t) mp_obj_get_int(p_args[1]);
    // node_setup_error
    p_self->class_data.u16Node_setup_error = (uint16_t) mp_obj_get_int(p_args[2]);
    // node_jump_error
    p_self->class_data.u16Node_jump_error = (uint16_t) mp_obj_get_int(p_args[3]);
    // mag_deploy_error
    p_self->class_data.u16Mag_deploy_error = (uint16_t) mp_obj_get_int(p_args[4]);
    // control_loop_failure
    p_self->class_data.u16Control_loop_failure = (uint16_t) mp_obj_get_int(p_args[5]);
    // node_failure
    p_self->class_data.u16Node_failure = (uint16_t) mp_obj_get_int(p_args[6]);
    // config_persist_error
    p_self->class_data.u16Config_persist_error = (uint16_t) mp_obj_get_int(p_args[7]);
    // virtual_watchdog_warning
    p_self->class_data.u16Virtual_watchdog_warning = (uint16_t) mp_obj_get_int(p_args[8]);
    // port_validation_error
    p_self->class_data.u16Port_validation_error = (uint16_t) mp_obj_get_int(p_args[9]);
    // auto_discovery_error
    p_self->class_data.u16Auto_discovery_error = (uint16_t) mp_obj_get_int(p_args[10]);
    // control_loop_critical
    p_self->class_data.u16Control_loop_critical = (uint16_t) mp_obj_get_int(p_args[11]);
    // gyro_voltage_error
    p_self->class_data.u16Gyro_voltage_error = (uint16_t) mp_obj_get_int(p_args[12]);
    // gyro_critical
    p_self->class_data.u16Gyro_critical = (uint16_t) mp_obj_get_int(p_args[13]);
    // virtual_watchdog_error
    p_self->class_data.u16Virtual_watchdog_error = (uint16_t) mp_obj_get_int(p_args[14]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'events' getters
//

STATIC mp_obj_t events_get_node_comm_error(mp_obj_t self_in) 
{
    const events_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16Node_comm_error);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(events_get_node_comm_error_obj, events_get_node_comm_error);

STATIC mp_obj_t events_get_adcs_config_validation_error(mp_obj_t self_in) 
{
    const events_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16Adcs_config_validation_error);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(events_get_adcs_config_validation_error_obj, events_get_adcs_config_validation_error);

STATIC mp_obj_t events_get_node_setup_error(mp_obj_t self_in) 
{
    const events_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16Node_setup_error);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(events_get_node_setup_error_obj, events_get_node_setup_error);

STATIC mp_obj_t events_get_node_jump_error(mp_obj_t self_in) 
{
    const events_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16Node_jump_error);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(events_get_node_jump_error_obj, events_get_node_jump_error);

STATIC mp_obj_t events_get_mag_deploy_error(mp_obj_t self_in) 
{
    const events_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16Mag_deploy_error);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(events_get_mag_deploy_error_obj, events_get_mag_deploy_error);

STATIC mp_obj_t events_get_control_loop_failure(mp_obj_t self_in) 
{
    const events_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16Control_loop_failure);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(events_get_control_loop_failure_obj, events_get_control_loop_failure);

STATIC mp_obj_t events_get_node_failure(mp_obj_t self_in) 
{
    const events_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16Node_failure);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(events_get_node_failure_obj, events_get_node_failure);

STATIC mp_obj_t events_get_config_persist_error(mp_obj_t self_in) 
{
    const events_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16Config_persist_error);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(events_get_config_persist_error_obj, events_get_config_persist_error);

STATIC mp_obj_t events_get_virtual_watchdog_warning(mp_obj_t self_in) 
{
    const events_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16Virtual_watchdog_warning);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(events_get_virtual_watchdog_warning_obj, events_get_virtual_watchdog_warning);

STATIC mp_obj_t events_get_port_validation_error(mp_obj_t self_in) 
{
    const events_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16Port_validation_error);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(events_get_port_validation_error_obj, events_get_port_validation_error);

STATIC mp_obj_t events_get_auto_discovery_error(mp_obj_t self_in) 
{
    const events_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16Auto_discovery_error);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(events_get_auto_discovery_error_obj, events_get_auto_discovery_error);

STATIC mp_obj_t events_get_control_loop_critical(mp_obj_t self_in) 
{
    const events_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16Control_loop_critical);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(events_get_control_loop_critical_obj, events_get_control_loop_critical);

STATIC mp_obj_t events_get_gyro_voltage_error(mp_obj_t self_in) 
{
    const events_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16Gyro_voltage_error);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(events_get_gyro_voltage_error_obj, events_get_gyro_voltage_error);

STATIC mp_obj_t events_get_gyro_critical(mp_obj_t self_in) 
{
    const events_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16Gyro_critical);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(events_get_gyro_critical_obj, events_get_gyro_critical);

STATIC mp_obj_t events_get_virtual_watchdog_error(mp_obj_t self_in) 
{
    const events_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16Virtual_watchdog_error);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(events_get_virtual_watchdog_error_obj, events_get_virtual_watchdog_error);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t events_locals_dict_table[15] = {
    { MP_ROM_QSTR(MP_QSTR_get_node_comm_error), MP_ROM_PTR(&events_get_node_comm_error_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_adcs_config_validation_error), MP_ROM_PTR(&events_get_adcs_config_validation_error_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_node_setup_error), MP_ROM_PTR(&events_get_node_setup_error_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_node_jump_error), MP_ROM_PTR(&events_get_node_jump_error_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_mag_deploy_error), MP_ROM_PTR(&events_get_mag_deploy_error_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_control_loop_failure), MP_ROM_PTR(&events_get_control_loop_failure_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_node_failure), MP_ROM_PTR(&events_get_node_failure_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_config_persist_error), MP_ROM_PTR(&events_get_config_persist_error_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_virtual_watchdog_warning), MP_ROM_PTR(&events_get_virtual_watchdog_warning_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_port_validation_error), MP_ROM_PTR(&events_get_port_validation_error_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_auto_discovery_error), MP_ROM_PTR(&events_get_auto_discovery_error_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_control_loop_critical), MP_ROM_PTR(&events_get_control_loop_critical_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_gyro_voltage_error), MP_ROM_PTR(&events_get_gyro_voltage_error_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_gyro_critical), MP_ROM_PTR(&events_get_gyro_critical_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_virtual_watchdog_error), MP_ROM_PTR(&events_get_virtual_watchdog_error_obj) },
};

STATIC MP_DEFINE_CONST_DICT(events_locals_dict, events_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    events_type,
    MP_QSTR_events,
    MP_TYPE_FLAG_NONE,
    make_new, events_make_new,
    locals_dict, (mp_obj_dict_t*)&events_locals_dict
);

STATIC mp_obj_t events_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_events_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    events_class_obj_t *p_self = m_new_obj(events_class_obj_t);
    p_self->base.type = &events_type;
    
    const OBC_CUBEADCS_GEN2_events_t *p_data = (const OBC_CUBEADCS_GEN2_events_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// events class constructor from a byte buffer
STATIC mp_obj_t events_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return events_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_events_t, events_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_events_t, events_class_obj_t, events)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(events_make_from_buf_obj, events_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'TctlmCubeCommonBaseBootloader5_Errors'
 *
 **********************************************************************/
    
// class structure for type TctlmCubeCommonBaseBootloader5_Errors
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_TctlmCubeCommonBaseBootloader5_Errors_t class_data;
} PACKED_STRUCT TctlmCubeCommonBaseBootloader5_Errors_class_obj_t;

// TctlmCubeCommonBaseBootloader5_Errors class constructor from field arguments
STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 17, 17, false);
    
    TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *p_self = m_new_obj(TctlmCubeCommonBaseBootloader5_Errors_class_obj_t);
    p_self->base.type = type;
    
    // result
    p_self->class_data.u32Result = (uint32_t) mp_obj_get_int(p_args[0]);
    // halInit
    p_self->class_data.u32HalInit = (uint32_t) mp_obj_get_int(p_args[1]);
    // flashInit
    p_self->class_data.u32FlashInit = (uint32_t) mp_obj_get_int(p_args[2]);
    // uart1Init
    p_self->class_data.u32Uart1Init = (uint32_t) mp_obj_get_int(p_args[3]);
    // uart2Init
    p_self->class_data.u32Uart2Init = (uint32_t) mp_obj_get_int(p_args[4]);
    // can1Init
    p_self->class_data.u32Can1Init = (uint32_t) mp_obj_get_int(p_args[5]);
    // can2Init
    p_self->class_data.u32Can2Init = (uint32_t) mp_obj_get_int(p_args[6]);
    // i2cInit
    p_self->class_data.u32I2cInit = (uint32_t) mp_obj_get_int(p_args[7]);
    // configInit
    p_self->class_data.bConfigInit = (bool) mp_obj_get_int(p_args[8]);
    // timeout
    p_self->class_data.bTimeout = (bool) mp_obj_get_int(p_args[9]);
    // overrun
    p_self->class_data.bOverrun = (bool) mp_obj_get_int(p_args[10]);
    // erasePage
    p_self->class_data.bErasePage = (bool) mp_obj_get_int(p_args[11]);
    // write
    p_self->class_data.bWrite = (bool) mp_obj_get_int(p_args[12]);
    // fileCrc
    p_self->class_data.bFileCrc = (bool) mp_obj_get_int(p_args[13]);
    // commitFileTable
    p_self->class_data.bCommitFileTable = (bool) mp_obj_get_int(p_args[14]);
    // commitConfigTable
    p_self->class_data.bCommitConfigTable = (bool) mp_obj_get_int(p_args[15]);
    // jumpTarget
    p_self->class_data.bJumpTarget = (bool) mp_obj_get_int(p_args[16]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'TctlmCubeCommonBaseBootloader5_Errors' getters
//

STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_get_result(mp_obj_t self_in) 
{
    const TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeCommonBaseBootloader5_Errors_get_result_obj, TctlmCubeCommonBaseBootloader5_Errors_get_result);

STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_get_halInit(mp_obj_t self_in) 
{
    const TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32HalInit);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeCommonBaseBootloader5_Errors_get_halInit_obj, TctlmCubeCommonBaseBootloader5_Errors_get_halInit);

STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_get_flashInit(mp_obj_t self_in) 
{
    const TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32FlashInit);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeCommonBaseBootloader5_Errors_get_flashInit_obj, TctlmCubeCommonBaseBootloader5_Errors_get_flashInit);

STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_get_uart1Init(mp_obj_t self_in) 
{
    const TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Uart1Init);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeCommonBaseBootloader5_Errors_get_uart1Init_obj, TctlmCubeCommonBaseBootloader5_Errors_get_uart1Init);

STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_get_uart2Init(mp_obj_t self_in) 
{
    const TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Uart2Init);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeCommonBaseBootloader5_Errors_get_uart2Init_obj, TctlmCubeCommonBaseBootloader5_Errors_get_uart2Init);

STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_get_can1Init(mp_obj_t self_in) 
{
    const TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Can1Init);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeCommonBaseBootloader5_Errors_get_can1Init_obj, TctlmCubeCommonBaseBootloader5_Errors_get_can1Init);

STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_get_can2Init(mp_obj_t self_in) 
{
    const TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Can2Init);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeCommonBaseBootloader5_Errors_get_can2Init_obj, TctlmCubeCommonBaseBootloader5_Errors_get_can2Init);

STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_get_i2cInit(mp_obj_t self_in) 
{
    const TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32I2cInit);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeCommonBaseBootloader5_Errors_get_i2cInit_obj, TctlmCubeCommonBaseBootloader5_Errors_get_i2cInit);

STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_get_configInit(mp_obj_t self_in) 
{
    const TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bConfigInit);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeCommonBaseBootloader5_Errors_get_configInit_obj, TctlmCubeCommonBaseBootloader5_Errors_get_configInit);

STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_get_timeout(mp_obj_t self_in) 
{
    const TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bTimeout);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeCommonBaseBootloader5_Errors_get_timeout_obj, TctlmCubeCommonBaseBootloader5_Errors_get_timeout);

STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_get_overrun(mp_obj_t self_in) 
{
    const TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bOverrun);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeCommonBaseBootloader5_Errors_get_overrun_obj, TctlmCubeCommonBaseBootloader5_Errors_get_overrun);

STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_get_erasePage(mp_obj_t self_in) 
{
    const TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bErasePage);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeCommonBaseBootloader5_Errors_get_erasePage_obj, TctlmCubeCommonBaseBootloader5_Errors_get_erasePage);

STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_get_write(mp_obj_t self_in) 
{
    const TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWrite);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeCommonBaseBootloader5_Errors_get_write_obj, TctlmCubeCommonBaseBootloader5_Errors_get_write);

STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_get_fileCrc(mp_obj_t self_in) 
{
    const TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bFileCrc);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeCommonBaseBootloader5_Errors_get_fileCrc_obj, TctlmCubeCommonBaseBootloader5_Errors_get_fileCrc);

STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_get_commitFileTable(mp_obj_t self_in) 
{
    const TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bCommitFileTable);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeCommonBaseBootloader5_Errors_get_commitFileTable_obj, TctlmCubeCommonBaseBootloader5_Errors_get_commitFileTable);

STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_get_commitConfigTable(mp_obj_t self_in) 
{
    const TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bCommitConfigTable);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeCommonBaseBootloader5_Errors_get_commitConfigTable_obj, TctlmCubeCommonBaseBootloader5_Errors_get_commitConfigTable);

STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_get_jumpTarget(mp_obj_t self_in) 
{
    const TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bJumpTarget);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeCommonBaseBootloader5_Errors_get_jumpTarget_obj, TctlmCubeCommonBaseBootloader5_Errors_get_jumpTarget);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t TctlmCubeCommonBaseBootloader5_Errors_locals_dict_table[17] = {
    { MP_ROM_QSTR(MP_QSTR_get_result), MP_ROM_PTR(&TctlmCubeCommonBaseBootloader5_Errors_get_result_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_halInit), MP_ROM_PTR(&TctlmCubeCommonBaseBootloader5_Errors_get_halInit_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_flashInit), MP_ROM_PTR(&TctlmCubeCommonBaseBootloader5_Errors_get_flashInit_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_uart1Init), MP_ROM_PTR(&TctlmCubeCommonBaseBootloader5_Errors_get_uart1Init_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_uart2Init), MP_ROM_PTR(&TctlmCubeCommonBaseBootloader5_Errors_get_uart2Init_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_can1Init), MP_ROM_PTR(&TctlmCubeCommonBaseBootloader5_Errors_get_can1Init_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_can2Init), MP_ROM_PTR(&TctlmCubeCommonBaseBootloader5_Errors_get_can2Init_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_i2cInit), MP_ROM_PTR(&TctlmCubeCommonBaseBootloader5_Errors_get_i2cInit_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_configInit), MP_ROM_PTR(&TctlmCubeCommonBaseBootloader5_Errors_get_configInit_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_timeout), MP_ROM_PTR(&TctlmCubeCommonBaseBootloader5_Errors_get_timeout_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_overrun), MP_ROM_PTR(&TctlmCubeCommonBaseBootloader5_Errors_get_overrun_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_erasePage), MP_ROM_PTR(&TctlmCubeCommonBaseBootloader5_Errors_get_erasePage_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_write), MP_ROM_PTR(&TctlmCubeCommonBaseBootloader5_Errors_get_write_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fileCrc), MP_ROM_PTR(&TctlmCubeCommonBaseBootloader5_Errors_get_fileCrc_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_commitFileTable), MP_ROM_PTR(&TctlmCubeCommonBaseBootloader5_Errors_get_commitFileTable_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_commitConfigTable), MP_ROM_PTR(&TctlmCubeCommonBaseBootloader5_Errors_get_commitConfigTable_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_jumpTarget), MP_ROM_PTR(&TctlmCubeCommonBaseBootloader5_Errors_get_jumpTarget_obj) },
};

STATIC MP_DEFINE_CONST_DICT(TctlmCubeCommonBaseBootloader5_Errors_locals_dict, TctlmCubeCommonBaseBootloader5_Errors_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    TctlmCubeCommonBaseBootloader5_Errors_type,
    MP_QSTR_TctlmCubeCommonBaseBootloader5_Errors,
    MP_TYPE_FLAG_NONE,
    make_new, TctlmCubeCommonBaseBootloader5_Errors_make_new,
    locals_dict, (mp_obj_dict_t*)&TctlmCubeCommonBaseBootloader5_Errors_locals_dict
);

STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_TctlmCubeCommonBaseBootloader5_Errors_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *p_self = m_new_obj(TctlmCubeCommonBaseBootloader5_Errors_class_obj_t);
    p_self->base.type = &TctlmCubeCommonBaseBootloader5_Errors_type;
    
    const OBC_CUBEADCS_GEN2_TctlmCubeCommonBaseBootloader5_Errors_t *p_data = (const OBC_CUBEADCS_GEN2_TctlmCubeCommonBaseBootloader5_Errors_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// TctlmCubeCommonBaseBootloader5_Errors class constructor from a byte buffer
STATIC mp_obj_t TctlmCubeCommonBaseBootloader5_Errors_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return TctlmCubeCommonBaseBootloader5_Errors_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_TctlmCubeCommonBaseBootloader5_Errors_t, TctlmCubeCommonBaseBootloader5_Errors_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_TctlmCubeCommonBaseBootloader5_Errors_t, TctlmCubeCommonBaseBootloader5_Errors_class_obj_t, TctlmCubeCommonBaseBootloader5_Errors)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeCommonBaseBootloader5_Errors_make_from_buf_obj, TctlmCubeCommonBaseBootloader5_Errors_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'RefParams'
 *
 **********************************************************************/
    
// class structure for type RefParams
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_RefParams_t class_data;
} PACKED_STRUCT RefParams_class_obj_t;

// RefParams class constructor from field arguments
STATIC mp_obj_t RefParams_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 3, 3, false);
    
    RefParams_class_obj_t *p_self = m_new_obj(RefParams_class_obj_t);
    p_self->base.type = type;
    
    // ref_param1
    upy_sd_float_to_unaligned_addr((uint8_t *) &p_self->class_data.fRef_param1, mp_obj_get_float(p_args[0]));
    // ref_param2
    upy_sd_float_to_unaligned_addr((uint8_t *) &p_self->class_data.fRef_param2, mp_obj_get_float(p_args[1]));
    // ref_param3
    upy_sd_float_to_unaligned_addr((uint8_t *) &p_self->class_data.fRef_param3, mp_obj_get_float(p_args[2]));
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'RefParams' getters
//

STATIC mp_obj_t RefParams_get_ref_param1(mp_obj_t self_in) 
{
    const RefParams_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_float(upy_sd_float_from_unaligned_addr((uint8_t *) &p_self->class_data.fRef_param1));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(RefParams_get_ref_param1_obj, RefParams_get_ref_param1);

STATIC mp_obj_t RefParams_get_ref_param2(mp_obj_t self_in) 
{
    const RefParams_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_float(upy_sd_float_from_unaligned_addr((uint8_t *) &p_self->class_data.fRef_param2));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(RefParams_get_ref_param2_obj, RefParams_get_ref_param2);

STATIC mp_obj_t RefParams_get_ref_param3(mp_obj_t self_in) 
{
    const RefParams_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_float(upy_sd_float_from_unaligned_addr((uint8_t *) &p_self->class_data.fRef_param3));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(RefParams_get_ref_param3_obj, RefParams_get_ref_param3);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t RefParams_locals_dict_table[3] = {
    { MP_ROM_QSTR(MP_QSTR_get_ref_param1), MP_ROM_PTR(&RefParams_get_ref_param1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ref_param2), MP_ROM_PTR(&RefParams_get_ref_param2_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ref_param3), MP_ROM_PTR(&RefParams_get_ref_param3_obj) },
};

STATIC MP_DEFINE_CONST_DICT(RefParams_locals_dict, RefParams_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    RefParams_type,
    MP_QSTR_RefParams,
    MP_TYPE_FLAG_NONE,
    make_new, RefParams_make_new,
    locals_dict, (mp_obj_dict_t*)&RefParams_locals_dict
);

STATIC mp_obj_t RefParams_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_RefParams_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    RefParams_class_obj_t *p_self = m_new_obj(RefParams_class_obj_t);
    p_self->base.type = &RefParams_type;
    
    const OBC_CUBEADCS_GEN2_RefParams_t *p_data = (const OBC_CUBEADCS_GEN2_RefParams_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// RefParams class constructor from a byte buffer
STATIC mp_obj_t RefParams_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return RefParams_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_RefParams_t, RefParams_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_RefParams_t, RefParams_class_obj_t, RefParams)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(RefParams_make_from_buf_obj, RefParams_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'fdir_stat'
 *
 **********************************************************************/
    
// class structure for type fdir_stat
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_fdir_stat_t class_data;
} PACKED_STRUCT fdir_stat_class_obj_t;

// fdir_stat class constructor from field arguments
STATIC mp_obj_t fdir_stat_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 3, 3, false);
    
    fdir_stat_class_obj_t *p_self = m_new_obj(fdir_stat_class_obj_t);
    p_self->base.type = type;
    
    // event_type
    p_self->class_data.eEvent_type = (uint8_t) mp_obj_get_int(p_args[0]);
    // event_fdir_execution_num
    p_self->class_data.u8Event_fdir_execution_num = (uint8_t) mp_obj_get_int(p_args[1]);
    // event_fdir_execution_res
    upy_sd_copy_fidl_scalar_array_from_py_list_bool(p_self->class_data.abEvent_fdir_execution_res, 1, p_args[2]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'fdir_stat' getters
//

STATIC mp_obj_t fdir_stat_get_event_type(mp_obj_t self_in) 
{
    const fdir_stat_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eEvent_type);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(fdir_stat_get_event_type_obj, fdir_stat_get_event_type);

STATIC mp_obj_t fdir_stat_get_event_fdir_execution_num(mp_obj_t self_in) 
{
    const fdir_stat_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u8Event_fdir_execution_num);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(fdir_stat_get_event_fdir_execution_num_obj, fdir_stat_get_event_fdir_execution_num);

STATIC mp_obj_t fdir_stat_get_event_fdir_execution_res(mp_obj_t self_in) 
{
    const fdir_stat_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return upy_sd_copy_fidl_scalar_array_to_py_list_bool(p_self->class_data.abEvent_fdir_execution_res, 1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(fdir_stat_get_event_fdir_execution_res_obj, fdir_stat_get_event_fdir_execution_res);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t fdir_stat_locals_dict_table[3] = {
    { MP_ROM_QSTR(MP_QSTR_get_event_type), MP_ROM_PTR(&fdir_stat_get_event_type_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_event_fdir_execution_num), MP_ROM_PTR(&fdir_stat_get_event_fdir_execution_num_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_event_fdir_execution_res), MP_ROM_PTR(&fdir_stat_get_event_fdir_execution_res_obj) },
};

STATIC MP_DEFINE_CONST_DICT(fdir_stat_locals_dict, fdir_stat_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    fdir_stat_type,
    MP_QSTR_fdir_stat,
    MP_TYPE_FLAG_NONE,
    make_new, fdir_stat_make_new,
    locals_dict, (mp_obj_dict_t*)&fdir_stat_locals_dict
);

STATIC mp_obj_t fdir_stat_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_fdir_stat_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    fdir_stat_class_obj_t *p_self = m_new_obj(fdir_stat_class_obj_t);
    p_self->base.type = &fdir_stat_type;
    
    const OBC_CUBEADCS_GEN2_fdir_stat_t *p_data = (const OBC_CUBEADCS_GEN2_fdir_stat_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// fdir_stat class constructor from a byte buffer
STATIC mp_obj_t fdir_stat_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return fdir_stat_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_fdir_stat_t, fdir_stat_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_fdir_stat_t, fdir_stat_class_obj_t, fdir_stat)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(fdir_stat_make_from_buf_obj, fdir_stat_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'PowerState'
 *
 **********************************************************************/
    
// class structure for type PowerState
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_PowerState_t class_data;
} PACKED_STRUCT PowerState_class_obj_t;

// PowerState class constructor from field arguments
STATIC mp_obj_t PowerState_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 20, 20, false);
    
    PowerState_class_obj_t *p_self = m_new_obj(PowerState_class_obj_t);
    p_self->base.type = type;
    
    // rwl0
    p_self->class_data.eRwl0 = (uint8_t) mp_obj_get_int(p_args[0]);
    // rwl1
    p_self->class_data.eRwl1 = (uint8_t) mp_obj_get_int(p_args[1]);
    // rwl2
    p_self->class_data.eRwl2 = (uint8_t) mp_obj_get_int(p_args[2]);
    // rwl3
    p_self->class_data.eRwl3 = (uint8_t) mp_obj_get_int(p_args[3]);
    // mag0
    p_self->class_data.eMag0 = (uint8_t) mp_obj_get_int(p_args[4]);
    // mag1
    p_self->class_data.eMag1 = (uint8_t) mp_obj_get_int(p_args[5]);
    // gyro0
    p_self->class_data.eGyro0 = (uint8_t) mp_obj_get_int(p_args[6]);
    // gyro1
    p_self->class_data.eGyro1 = (uint8_t) mp_obj_get_int(p_args[7]);
    // fss0
    p_self->class_data.eFss0 = (uint8_t) mp_obj_get_int(p_args[8]);
    // fss1
    p_self->class_data.eFss1 = (uint8_t) mp_obj_get_int(p_args[9]);
    // fss2
    p_self->class_data.eFss2 = (uint8_t) mp_obj_get_int(p_args[10]);
    // fss3
    p_self->class_data.eFss3 = (uint8_t) mp_obj_get_int(p_args[11]);
    // hss0
    p_self->class_data.eHss0 = (uint8_t) mp_obj_get_int(p_args[12]);
    // hss1
    p_self->class_data.eHss1 = (uint8_t) mp_obj_get_int(p_args[13]);
    // str0
    p_self->class_data.eStr0 = (uint8_t) mp_obj_get_int(p_args[14]);
    // str1
    p_self->class_data.eStr1 = (uint8_t) mp_obj_get_int(p_args[15]);
    // extSensor0
    p_self->class_data.eExtSensor0 = (uint8_t) mp_obj_get_int(p_args[16]);
    // extSensor1
    p_self->class_data.eExtSensor1 = (uint8_t) mp_obj_get_int(p_args[17]);
    // extGyro0
    p_self->class_data.eExtGyro0 = (uint8_t) mp_obj_get_int(p_args[18]);
    // extGyro1
    p_self->class_data.eExtGyro1 = (uint8_t) mp_obj_get_int(p_args[19]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'PowerState' getters
//

STATIC mp_obj_t PowerState_get_rwl0(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eRwl0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_rwl0_obj, PowerState_get_rwl0);

STATIC mp_obj_t PowerState_get_rwl1(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eRwl1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_rwl1_obj, PowerState_get_rwl1);

STATIC mp_obj_t PowerState_get_rwl2(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eRwl2);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_rwl2_obj, PowerState_get_rwl2);

STATIC mp_obj_t PowerState_get_rwl3(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eRwl3);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_rwl3_obj, PowerState_get_rwl3);

STATIC mp_obj_t PowerState_get_mag0(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eMag0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_mag0_obj, PowerState_get_mag0);

STATIC mp_obj_t PowerState_get_mag1(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eMag1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_mag1_obj, PowerState_get_mag1);

STATIC mp_obj_t PowerState_get_gyro0(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eGyro0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_gyro0_obj, PowerState_get_gyro0);

STATIC mp_obj_t PowerState_get_gyro1(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eGyro1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_gyro1_obj, PowerState_get_gyro1);

STATIC mp_obj_t PowerState_get_fss0(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eFss0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_fss0_obj, PowerState_get_fss0);

STATIC mp_obj_t PowerState_get_fss1(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eFss1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_fss1_obj, PowerState_get_fss1);

STATIC mp_obj_t PowerState_get_fss2(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eFss2);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_fss2_obj, PowerState_get_fss2);

STATIC mp_obj_t PowerState_get_fss3(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eFss3);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_fss3_obj, PowerState_get_fss3);

STATIC mp_obj_t PowerState_get_hss0(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eHss0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_hss0_obj, PowerState_get_hss0);

STATIC mp_obj_t PowerState_get_hss1(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eHss1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_hss1_obj, PowerState_get_hss1);

STATIC mp_obj_t PowerState_get_str0(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eStr0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_str0_obj, PowerState_get_str0);

STATIC mp_obj_t PowerState_get_str1(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eStr1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_str1_obj, PowerState_get_str1);

STATIC mp_obj_t PowerState_get_extSensor0(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExtSensor0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_extSensor0_obj, PowerState_get_extSensor0);

STATIC mp_obj_t PowerState_get_extSensor1(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExtSensor1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_extSensor1_obj, PowerState_get_extSensor1);

STATIC mp_obj_t PowerState_get_extGyro0(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExtGyro0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_extGyro0_obj, PowerState_get_extGyro0);

STATIC mp_obj_t PowerState_get_extGyro1(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExtGyro1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_extGyro1_obj, PowerState_get_extGyro1);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t PowerState_locals_dict_table[20] = {
    { MP_ROM_QSTR(MP_QSTR_get_rwl0), MP_ROM_PTR(&PowerState_get_rwl0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_rwl1), MP_ROM_PTR(&PowerState_get_rwl1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_rwl2), MP_ROM_PTR(&PowerState_get_rwl2_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_rwl3), MP_ROM_PTR(&PowerState_get_rwl3_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_mag0), MP_ROM_PTR(&PowerState_get_mag0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_mag1), MP_ROM_PTR(&PowerState_get_mag1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_gyro0), MP_ROM_PTR(&PowerState_get_gyro0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_gyro1), MP_ROM_PTR(&PowerState_get_gyro1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fss0), MP_ROM_PTR(&PowerState_get_fss0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fss1), MP_ROM_PTR(&PowerState_get_fss1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fss2), MP_ROM_PTR(&PowerState_get_fss2_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fss3), MP_ROM_PTR(&PowerState_get_fss3_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_hss0), MP_ROM_PTR(&PowerState_get_hss0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_hss1), MP_ROM_PTR(&PowerState_get_hss1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_str0), MP_ROM_PTR(&PowerState_get_str0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_str1), MP_ROM_PTR(&PowerState_get_str1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_extSensor0), MP_ROM_PTR(&PowerState_get_extSensor0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_extSensor1), MP_ROM_PTR(&PowerState_get_extSensor1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_extGyro0), MP_ROM_PTR(&PowerState_get_extGyro0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_extGyro1), MP_ROM_PTR(&PowerState_get_extGyro1_obj) },
};

STATIC MP_DEFINE_CONST_DICT(PowerState_locals_dict, PowerState_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    PowerState_type,
    MP_QSTR_PowerState,
    MP_TYPE_FLAG_NONE,
    make_new, PowerState_make_new,
    locals_dict, (mp_obj_dict_t*)&PowerState_locals_dict
);

STATIC mp_obj_t PowerState_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_PowerState_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    PowerState_class_obj_t *p_self = m_new_obj(PowerState_class_obj_t);
    p_self->base.type = &PowerState_type;
    
    const OBC_CUBEADCS_GEN2_PowerState_t *p_data = (const OBC_CUBEADCS_GEN2_PowerState_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// PowerState class constructor from a byte buffer
STATIC mp_obj_t PowerState_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return PowerState_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_PowerState_t, PowerState_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_PowerState_t, PowerState_class_obj_t, PowerState)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_make_from_buf_obj, PowerState_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'TctlmCubeComputerCommon3_EventLogStatus'
 *
 **********************************************************************/
    
// class structure for type TctlmCubeComputerCommon3_EventLogStatus
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_EventLogStatus_t class_data;
} PACKED_STRUCT TctlmCubeComputerCommon3_EventLogStatus_class_obj_t;

// TctlmCubeComputerCommon3_EventLogStatus class constructor from field arguments
STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogStatus_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 12, 12, false);
    
    TctlmCubeComputerCommon3_EventLogStatus_class_obj_t *p_self = m_new_obj(TctlmCubeComputerCommon3_EventLogStatus_class_obj_t);
    p_self->base.type = type;
    
    // numberOfEntriesQueued
    p_self->class_data.u16NumberOfEntriesQueued = (uint16_t) mp_obj_get_int(p_args[0]);
    // numberOfEntriesBuffered
    p_self->class_data.u16NumberOfEntriesBuffered = (uint16_t) mp_obj_get_int(p_args[1]);
    // numberOfEntries
    p_self->class_data.u32NumberOfEntries = (uint32_t) mp_obj_get_int(p_args[2]);
    // numberOfEmptyEntries
    p_self->class_data.u32NumberOfEmptyEntries = (uint32_t) mp_obj_get_int(p_args[3]);
    // oldestEntryUnix
    p_self->class_data.u32OldestEntryUnix = (uint32_t) mp_obj_get_int(p_args[4]);
    // latestEntryUnix
    p_self->class_data.u32LatestEntryUnix = (uint32_t) mp_obj_get_int(p_args[5]);
    // numberOfCriticalEvents
    p_self->class_data.u32NumberOfCriticalEvents = (uint32_t) mp_obj_get_int(p_args[6]);
    // numberOfMajorWarningEvents
    p_self->class_data.u32NumberOfMajorWarningEvents = (uint32_t) mp_obj_get_int(p_args[7]);
    // numberOfMinorWarningEvents
    p_self->class_data.u32NumberOfMinorWarningEvents = (uint32_t) mp_obj_get_int(p_args[8]);
    // numberOfInfoEvents
    p_self->class_data.u32NumberOfInfoEvents = (uint32_t) mp_obj_get_int(p_args[9]);
    // writeCounter
    p_self->class_data.u32WriteCounter = (uint32_t) mp_obj_get_int(p_args[10]);
    // readQueueState
    p_self->class_data.eReadQueueState = (uint8_t) mp_obj_get_int(p_args[11]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'TctlmCubeComputerCommon3_EventLogStatus' getters
//

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogStatus_get_numberOfEntriesQueued(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16NumberOfEntriesQueued);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogStatus_get_numberOfEntriesQueued_obj, TctlmCubeComputerCommon3_EventLogStatus_get_numberOfEntriesQueued);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogStatus_get_numberOfEntriesBuffered(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16NumberOfEntriesBuffered);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogStatus_get_numberOfEntriesBuffered_obj, TctlmCubeComputerCommon3_EventLogStatus_get_numberOfEntriesBuffered);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogStatus_get_numberOfEntries(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32NumberOfEntries);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogStatus_get_numberOfEntries_obj, TctlmCubeComputerCommon3_EventLogStatus_get_numberOfEntries);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogStatus_get_numberOfEmptyEntries(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32NumberOfEmptyEntries);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogStatus_get_numberOfEmptyEntries_obj, TctlmCubeComputerCommon3_EventLogStatus_get_numberOfEmptyEntries);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogStatus_get_oldestEntryUnix(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32OldestEntryUnix);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogStatus_get_oldestEntryUnix_obj, TctlmCubeComputerCommon3_EventLogStatus_get_oldestEntryUnix);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogStatus_get_latestEntryUnix(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32LatestEntryUnix);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogStatus_get_latestEntryUnix_obj, TctlmCubeComputerCommon3_EventLogStatus_get_latestEntryUnix);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogStatus_get_numberOfCriticalEvents(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32NumberOfCriticalEvents);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogStatus_get_numberOfCriticalEvents_obj, TctlmCubeComputerCommon3_EventLogStatus_get_numberOfCriticalEvents);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogStatus_get_numberOfMajorWarningEvents(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32NumberOfMajorWarningEvents);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogStatus_get_numberOfMajorWarningEvents_obj, TctlmCubeComputerCommon3_EventLogStatus_get_numberOfMajorWarningEvents);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogStatus_get_numberOfMinorWarningEvents(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32NumberOfMinorWarningEvents);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogStatus_get_numberOfMinorWarningEvents_obj, TctlmCubeComputerCommon3_EventLogStatus_get_numberOfMinorWarningEvents);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogStatus_get_numberOfInfoEvents(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32NumberOfInfoEvents);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogStatus_get_numberOfInfoEvents_obj, TctlmCubeComputerCommon3_EventLogStatus_get_numberOfInfoEvents);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogStatus_get_writeCounter(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32WriteCounter);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogStatus_get_writeCounter_obj, TctlmCubeComputerCommon3_EventLogStatus_get_writeCounter);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogStatus_get_readQueueState(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eReadQueueState);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogStatus_get_readQueueState_obj, TctlmCubeComputerCommon3_EventLogStatus_get_readQueueState);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t TctlmCubeComputerCommon3_EventLogStatus_locals_dict_table[12] = {
    { MP_ROM_QSTR(MP_QSTR_get_numberOfEntriesQueued), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogStatus_get_numberOfEntriesQueued_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numberOfEntriesBuffered), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogStatus_get_numberOfEntriesBuffered_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numberOfEntries), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogStatus_get_numberOfEntries_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numberOfEmptyEntries), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogStatus_get_numberOfEmptyEntries_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_oldestEntryUnix), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogStatus_get_oldestEntryUnix_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_latestEntryUnix), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogStatus_get_latestEntryUnix_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numberOfCriticalEvents), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogStatus_get_numberOfCriticalEvents_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numberOfMajorWarningEvents), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogStatus_get_numberOfMajorWarningEvents_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numberOfMinorWarningEvents), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogStatus_get_numberOfMinorWarningEvents_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numberOfInfoEvents), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogStatus_get_numberOfInfoEvents_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_writeCounter), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogStatus_get_writeCounter_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_readQueueState), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogStatus_get_readQueueState_obj) },
};

STATIC MP_DEFINE_CONST_DICT(TctlmCubeComputerCommon3_EventLogStatus_locals_dict, TctlmCubeComputerCommon3_EventLogStatus_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    TctlmCubeComputerCommon3_EventLogStatus_type,
    MP_QSTR_TctlmCubeComputerCommon3_EventLogStatus,
    MP_TYPE_FLAG_NONE,
    make_new, TctlmCubeComputerCommon3_EventLogStatus_make_new,
    locals_dict, (mp_obj_dict_t*)&TctlmCubeComputerCommon3_EventLogStatus_locals_dict
);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogStatus_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_EventLogStatus_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    TctlmCubeComputerCommon3_EventLogStatus_class_obj_t *p_self = m_new_obj(TctlmCubeComputerCommon3_EventLogStatus_class_obj_t);
    p_self->base.type = &TctlmCubeComputerCommon3_EventLogStatus_type;
    
    const OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_EventLogStatus_t *p_data = (const OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_EventLogStatus_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// TctlmCubeComputerCommon3_EventLogStatus class constructor from a byte buffer
STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogStatus_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return TctlmCubeComputerCommon3_EventLogStatus_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_EventLogStatus_t, TctlmCubeComputerCommon3_EventLogStatus_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_EventLogStatus_t, TctlmCubeComputerCommon3_EventLogStatus_class_obj_t, TctlmCubeComputerCommon3_EventLogStatus)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogStatus_make_from_buf_obj, TctlmCubeComputerCommon3_EventLogStatus_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'TctlmCubeComputerCommon3_ImageTransferStatus'
 *
 **********************************************************************/
    
// class structure for type TctlmCubeComputerCommon3_ImageTransferStatus
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_ImageTransferStatus_t class_data;
} PACKED_STRUCT TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t;

// TctlmCubeComputerCommon3_ImageTransferStatus class constructor from field arguments
STATIC mp_obj_t TctlmCubeComputerCommon3_ImageTransferStatus_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 13, 13, false);
    
    TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t *p_self = m_new_obj(TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t);
    p_self->base.type = type;
    
    // transfer_state
    p_self->class_data.eTransfer_state = (uint8_t) mp_obj_get_int(p_args[0]);
    // errorCode
    p_self->class_data.u32ErrorCode = (uint32_t) mp_obj_get_int(p_args[1]);
    // transferSize
    p_self->class_data.u32TransferSize = (uint32_t) mp_obj_get_int(p_args[2]);
    // dataRemain
    p_self->class_data.u32DataRemain = (uint32_t) mp_obj_get_int(p_args[3]);
    // invalidNodeError
    p_self->class_data.bInvalidNodeError = (bool) mp_obj_get_int(p_args[4]);
    // timeoutError
    p_self->class_data.bTimeoutError = (bool) mp_obj_get_int(p_args[5]);
    // captureError
    p_self->class_data.bCaptureError = (bool) mp_obj_get_int(p_args[6]);
    // setupError
    p_self->class_data.bSetupError = (bool) mp_obj_get_int(p_args[7]);
    // fileOpenReadError
    p_self->class_data.bFileOpenReadError = (bool) mp_obj_get_int(p_args[8]);
    // fileOpenWriteError
    p_self->class_data.bFileOpenWriteError = (bool) mp_obj_get_int(p_args[9]);
    // fileReadError
    p_self->class_data.bFileReadError = (bool) mp_obj_get_int(p_args[10]);
    // fileWriteError
    p_self->class_data.bFileWriteError = (bool) mp_obj_get_int(p_args[11]);
    // busyError
    p_self->class_data.bBusyError = (bool) mp_obj_get_int(p_args[12]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'TctlmCubeComputerCommon3_ImageTransferStatus' getters
//

STATIC mp_obj_t TctlmCubeComputerCommon3_ImageTransferStatus_get_transfer_state(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eTransfer_state);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_ImageTransferStatus_get_transfer_state_obj, TctlmCubeComputerCommon3_ImageTransferStatus_get_transfer_state);

STATIC mp_obj_t TctlmCubeComputerCommon3_ImageTransferStatus_get_errorCode(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32ErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_ImageTransferStatus_get_errorCode_obj, TctlmCubeComputerCommon3_ImageTransferStatus_get_errorCode);

STATIC mp_obj_t TctlmCubeComputerCommon3_ImageTransferStatus_get_transferSize(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32TransferSize);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_ImageTransferStatus_get_transferSize_obj, TctlmCubeComputerCommon3_ImageTransferStatus_get_transferSize);

STATIC mp_obj_t TctlmCubeComputerCommon3_ImageTransferStatus_get_dataRemain(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32DataRemain);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_ImageTransferStatus_get_dataRemain_obj, TctlmCubeComputerCommon3_ImageTransferStatus_get_dataRemain);

STATIC mp_obj_t TctlmCubeComputerCommon3_ImageTransferStatus_get_invalidNodeError(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bInvalidNodeError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_ImageTransferStatus_get_invalidNodeError_obj, TctlmCubeComputerCommon3_ImageTransferStatus_get_invalidNodeError);

STATIC mp_obj_t TctlmCubeComputerCommon3_ImageTransferStatus_get_timeoutError(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bTimeoutError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_ImageTransferStatus_get_timeoutError_obj, TctlmCubeComputerCommon3_ImageTransferStatus_get_timeoutError);

STATIC mp_obj_t TctlmCubeComputerCommon3_ImageTransferStatus_get_captureError(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bCaptureError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_ImageTransferStatus_get_captureError_obj, TctlmCubeComputerCommon3_ImageTransferStatus_get_captureError);

STATIC mp_obj_t TctlmCubeComputerCommon3_ImageTransferStatus_get_setupError(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSetupError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_ImageTransferStatus_get_setupError_obj, TctlmCubeComputerCommon3_ImageTransferStatus_get_setupError);

STATIC mp_obj_t TctlmCubeComputerCommon3_ImageTransferStatus_get_fileOpenReadError(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bFileOpenReadError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_ImageTransferStatus_get_fileOpenReadError_obj, TctlmCubeComputerCommon3_ImageTransferStatus_get_fileOpenReadError);

STATIC mp_obj_t TctlmCubeComputerCommon3_ImageTransferStatus_get_fileOpenWriteError(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bFileOpenWriteError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_ImageTransferStatus_get_fileOpenWriteError_obj, TctlmCubeComputerCommon3_ImageTransferStatus_get_fileOpenWriteError);

STATIC mp_obj_t TctlmCubeComputerCommon3_ImageTransferStatus_get_fileReadError(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bFileReadError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_ImageTransferStatus_get_fileReadError_obj, TctlmCubeComputerCommon3_ImageTransferStatus_get_fileReadError);

STATIC mp_obj_t TctlmCubeComputerCommon3_ImageTransferStatus_get_fileWriteError(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bFileWriteError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_ImageTransferStatus_get_fileWriteError_obj, TctlmCubeComputerCommon3_ImageTransferStatus_get_fileWriteError);

STATIC mp_obj_t TctlmCubeComputerCommon3_ImageTransferStatus_get_busyError(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bBusyError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_ImageTransferStatus_get_busyError_obj, TctlmCubeComputerCommon3_ImageTransferStatus_get_busyError);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t TctlmCubeComputerCommon3_ImageTransferStatus_locals_dict_table[13] = {
    { MP_ROM_QSTR(MP_QSTR_get_transfer_state), MP_ROM_PTR(&TctlmCubeComputerCommon3_ImageTransferStatus_get_transfer_state_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_errorCode), MP_ROM_PTR(&TctlmCubeComputerCommon3_ImageTransferStatus_get_errorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_transferSize), MP_ROM_PTR(&TctlmCubeComputerCommon3_ImageTransferStatus_get_transferSize_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_dataRemain), MP_ROM_PTR(&TctlmCubeComputerCommon3_ImageTransferStatus_get_dataRemain_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_invalidNodeError), MP_ROM_PTR(&TctlmCubeComputerCommon3_ImageTransferStatus_get_invalidNodeError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_timeoutError), MP_ROM_PTR(&TctlmCubeComputerCommon3_ImageTransferStatus_get_timeoutError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_captureError), MP_ROM_PTR(&TctlmCubeComputerCommon3_ImageTransferStatus_get_captureError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_setupError), MP_ROM_PTR(&TctlmCubeComputerCommon3_ImageTransferStatus_get_setupError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fileOpenReadError), MP_ROM_PTR(&TctlmCubeComputerCommon3_ImageTransferStatus_get_fileOpenReadError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fileOpenWriteError), MP_ROM_PTR(&TctlmCubeComputerCommon3_ImageTransferStatus_get_fileOpenWriteError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fileReadError), MP_ROM_PTR(&TctlmCubeComputerCommon3_ImageTransferStatus_get_fileReadError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fileWriteError), MP_ROM_PTR(&TctlmCubeComputerCommon3_ImageTransferStatus_get_fileWriteError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_busyError), MP_ROM_PTR(&TctlmCubeComputerCommon3_ImageTransferStatus_get_busyError_obj) },
};

STATIC MP_DEFINE_CONST_DICT(TctlmCubeComputerCommon3_ImageTransferStatus_locals_dict, TctlmCubeComputerCommon3_ImageTransferStatus_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    TctlmCubeComputerCommon3_ImageTransferStatus_type,
    MP_QSTR_TctlmCubeComputerCommon3_ImageTransferStatus,
    MP_TYPE_FLAG_NONE,
    make_new, TctlmCubeComputerCommon3_ImageTransferStatus_make_new,
    locals_dict, (mp_obj_dict_t*)&TctlmCubeComputerCommon3_ImageTransferStatus_locals_dict
);

STATIC mp_obj_t TctlmCubeComputerCommon3_ImageTransferStatus_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_ImageTransferStatus_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t *p_self = m_new_obj(TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t);
    p_self->base.type = &TctlmCubeComputerCommon3_ImageTransferStatus_type;
    
    const OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_ImageTransferStatus_t *p_data = (const OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_ImageTransferStatus_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// TctlmCubeComputerCommon3_ImageTransferStatus class constructor from a byte buffer
STATIC mp_obj_t TctlmCubeComputerCommon3_ImageTransferStatus_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return TctlmCubeComputerCommon3_ImageTransferStatus_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_ImageTransferStatus_t, TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_ImageTransferStatus_t, TctlmCubeComputerCommon3_ImageTransferStatus_class_obj_t, TctlmCubeComputerCommon3_ImageTransferStatus)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_ImageTransferStatus_make_from_buf_obj, TctlmCubeComputerCommon3_ImageTransferStatus_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'EstModeConfig'
 *
 **********************************************************************/
    
// class structure for type EstModeConfig
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_EstModeConfig_t class_data;
} PACKED_STRUCT EstModeConfig_class_obj_t;

// EstModeConfig class constructor from field arguments
STATIC mp_obj_t EstModeConfig_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 2, 2, false);
    
    EstModeConfig_class_obj_t *p_self = m_new_obj(EstModeConfig_class_obj_t);
    p_self->base.type = type;
    
    // main
    p_self->class_data.eMain = (uint8_t) mp_obj_get_int(p_args[0]);
    // backup
    p_self->class_data.eBackup = (uint8_t) mp_obj_get_int(p_args[1]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'EstModeConfig' getters
//

STATIC mp_obj_t EstModeConfig_get_main(mp_obj_t self_in) 
{
    const EstModeConfig_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eMain);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EstModeConfig_get_main_obj, EstModeConfig_get_main);

STATIC mp_obj_t EstModeConfig_get_backup(mp_obj_t self_in) 
{
    const EstModeConfig_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eBackup);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EstModeConfig_get_backup_obj, EstModeConfig_get_backup);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t EstModeConfig_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_main), MP_ROM_PTR(&EstModeConfig_get_main_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_backup), MP_ROM_PTR(&EstModeConfig_get_backup_obj) },
};

STATIC MP_DEFINE_CONST_DICT(EstModeConfig_locals_dict, EstModeConfig_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    EstModeConfig_type,
    MP_QSTR_EstModeConfig,
    MP_TYPE_FLAG_NONE,
    make_new, EstModeConfig_make_new,
    locals_dict, (mp_obj_dict_t*)&EstModeConfig_locals_dict
);

STATIC mp_obj_t EstModeConfig_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_EstModeConfig_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    EstModeConfig_class_obj_t *p_self = m_new_obj(EstModeConfig_class_obj_t);
    p_self->base.type = &EstModeConfig_type;
    
    const OBC_CUBEADCS_GEN2_EstModeConfig_t *p_data = (const OBC_CUBEADCS_GEN2_EstModeConfig_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// EstModeConfig class constructor from a byte buffer
STATIC mp_obj_t EstModeConfig_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return EstModeConfig_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_EstModeConfig_t, EstModeConfig_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_EstModeConfig_t, EstModeConfig_class_obj_t, EstModeConfig)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EstModeConfig_make_from_buf_obj, EstModeConfig_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'cube_computer_fw_update_status'
 *
 **********************************************************************/
    
// class structure for type cube_computer_fw_update_status
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_cube_computer_fw_update_status_t class_data;
} PACKED_STRUCT cube_computer_fw_update_status_class_obj_t;

// cube_computer_fw_update_status class constructor from field arguments
STATIC mp_obj_t cube_computer_fw_update_status_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 5, 5, false);
    
    cube_computer_fw_update_status_class_obj_t *p_self = m_new_obj(cube_computer_fw_update_status_class_obj_t);
    p_self->base.type = type;
    
    // err_code
    p_self->class_data.tErr_code = (int32_t) mp_obj_get_int(p_args[0]);
    // force
    p_self->class_data.bForce = (bool) mp_obj_get_int(p_args[1]);
    // status
    p_self->class_data.sStatus = ((TctlmCubeCommonBaseBootloader5_Errors_class_obj_t *) MP_OBJ_TO_PTR(p_args[2]))->class_data;
    // control_program_file_name
    p_self->class_data.sControl_program_file_name = ((FName_class_obj_t *) MP_OBJ_TO_PTR(p_args[3]))->class_data;
    // configuration_file_name
    p_self->class_data.sConfiguration_file_name = ((FName_class_obj_t *) MP_OBJ_TO_PTR(p_args[4]))->class_data;
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'cube_computer_fw_update_status' getters
//

STATIC mp_obj_t cube_computer_fw_update_status_get_err_code(mp_obj_t self_in) 
{
    const cube_computer_fw_update_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.tErr_code);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(cube_computer_fw_update_status_get_err_code_obj, cube_computer_fw_update_status_get_err_code);

STATIC mp_obj_t cube_computer_fw_update_status_get_force(mp_obj_t self_in) 
{
    const cube_computer_fw_update_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bForce);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(cube_computer_fw_update_status_get_force_obj, cube_computer_fw_update_status_get_force);

STATIC mp_obj_t cube_computer_fw_update_status_get_status(mp_obj_t self_in) 
{
    const cube_computer_fw_update_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return TctlmCubeCommonBaseBootloader5_Errors_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_TctlmCubeCommonBaseBootloader5_Errors_t), (const uint8_t *) &p_self->class_data.sStatus));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(cube_computer_fw_update_status_get_status_obj, cube_computer_fw_update_status_get_status);

STATIC mp_obj_t cube_computer_fw_update_status_get_control_program_file_name(mp_obj_t self_in) 
{
    const cube_computer_fw_update_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return FName_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_FName_t), (const uint8_t *) &p_self->class_data.sControl_program_file_name));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(cube_computer_fw_update_status_get_control_program_file_name_obj, cube_computer_fw_update_status_get_control_program_file_name);

STATIC mp_obj_t cube_computer_fw_update_status_get_configuration_file_name(mp_obj_t self_in) 
{
    const cube_computer_fw_update_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return FName_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_FName_t), (const uint8_t *) &p_self->class_data.sConfiguration_file_name));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(cube_computer_fw_update_status_get_configuration_file_name_obj, cube_computer_fw_update_status_get_configuration_file_name);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t cube_computer_fw_update_status_locals_dict_table[5] = {
    { MP_ROM_QSTR(MP_QSTR_get_err_code), MP_ROM_PTR(&cube_computer_fw_update_status_get_err_code_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_force), MP_ROM_PTR(&cube_computer_fw_update_status_get_force_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&cube_computer_fw_update_status_get_status_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_control_program_file_name), MP_ROM_PTR(&cube_computer_fw_update_status_get_control_program_file_name_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_configuration_file_name), MP_ROM_PTR(&cube_computer_fw_update_status_get_configuration_file_name_obj) },
};

STATIC MP_DEFINE_CONST_DICT(cube_computer_fw_update_status_locals_dict, cube_computer_fw_update_status_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    cube_computer_fw_update_status_type,
    MP_QSTR_cube_computer_fw_update_status,
    MP_TYPE_FLAG_NONE,
    make_new, cube_computer_fw_update_status_make_new,
    locals_dict, (mp_obj_dict_t*)&cube_computer_fw_update_status_locals_dict
);

STATIC mp_obj_t cube_computer_fw_update_status_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_cube_computer_fw_update_status_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    cube_computer_fw_update_status_class_obj_t *p_self = m_new_obj(cube_computer_fw_update_status_class_obj_t);
    p_self->base.type = &cube_computer_fw_update_status_type;
    
    const OBC_CUBEADCS_GEN2_cube_computer_fw_update_status_t *p_data = (const OBC_CUBEADCS_GEN2_cube_computer_fw_update_status_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// cube_computer_fw_update_status class constructor from a byte buffer
STATIC mp_obj_t cube_computer_fw_update_status_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return cube_computer_fw_update_status_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_cube_computer_fw_update_status_t, cube_computer_fw_update_status_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_cube_computer_fw_update_status_t, cube_computer_fw_update_status_class_obj_t, cube_computer_fw_update_status)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(cube_computer_fw_update_status_make_from_buf_obj, cube_computer_fw_update_status_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'TctlmCubeComputerCommon3_TelemtryLogStatus'
 *
 **********************************************************************/
    
// class structure for type TctlmCubeComputerCommon3_TelemtryLogStatus
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_TelemtryLogStatus_t class_data;
} PACKED_STRUCT TctlmCubeComputerCommon3_TelemtryLogStatus_class_obj_t;

// TctlmCubeComputerCommon3_TelemtryLogStatus class constructor from field arguments
STATIC mp_obj_t TctlmCubeComputerCommon3_TelemtryLogStatus_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 7, 7, false);
    
    TctlmCubeComputerCommon3_TelemtryLogStatus_class_obj_t *p_self = m_new_obj(TctlmCubeComputerCommon3_TelemtryLogStatus_class_obj_t);
    p_self->base.type = type;
    
    // numberOfEntriesQueued
    p_self->class_data.u8NumberOfEntriesQueued = (uint8_t) mp_obj_get_int(p_args[0]);
    // numberOfTlmIterations
    p_self->class_data.u8NumberOfTlmIterations = (uint8_t) mp_obj_get_int(p_args[1]);
    // numberOfEntries
    p_self->class_data.u32NumberOfEntries = (uint32_t) mp_obj_get_int(p_args[2]);
    // oldestEntryUnix
    p_self->class_data.u32OldestEntryUnix = (uint32_t) mp_obj_get_int(p_args[3]);
    // latestEntryUnix
    p_self->class_data.u32LatestEntryUnix = (uint32_t) mp_obj_get_int(p_args[4]);
    // writeCounter
    p_self->class_data.u32WriteCounter = (uint32_t) mp_obj_get_int(p_args[5]);
    // readQueueState
    p_self->class_data.eReadQueueState = (uint8_t) mp_obj_get_int(p_args[6]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'TctlmCubeComputerCommon3_TelemtryLogStatus' getters
//

STATIC mp_obj_t TctlmCubeComputerCommon3_TelemtryLogStatus_get_numberOfEntriesQueued(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_TelemtryLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u8NumberOfEntriesQueued);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_TelemtryLogStatus_get_numberOfEntriesQueued_obj, TctlmCubeComputerCommon3_TelemtryLogStatus_get_numberOfEntriesQueued);

STATIC mp_obj_t TctlmCubeComputerCommon3_TelemtryLogStatus_get_numberOfTlmIterations(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_TelemtryLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u8NumberOfTlmIterations);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_TelemtryLogStatus_get_numberOfTlmIterations_obj, TctlmCubeComputerCommon3_TelemtryLogStatus_get_numberOfTlmIterations);

STATIC mp_obj_t TctlmCubeComputerCommon3_TelemtryLogStatus_get_numberOfEntries(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_TelemtryLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32NumberOfEntries);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_TelemtryLogStatus_get_numberOfEntries_obj, TctlmCubeComputerCommon3_TelemtryLogStatus_get_numberOfEntries);

STATIC mp_obj_t TctlmCubeComputerCommon3_TelemtryLogStatus_get_oldestEntryUnix(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_TelemtryLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32OldestEntryUnix);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_TelemtryLogStatus_get_oldestEntryUnix_obj, TctlmCubeComputerCommon3_TelemtryLogStatus_get_oldestEntryUnix);

STATIC mp_obj_t TctlmCubeComputerCommon3_TelemtryLogStatus_get_latestEntryUnix(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_TelemtryLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32LatestEntryUnix);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_TelemtryLogStatus_get_latestEntryUnix_obj, TctlmCubeComputerCommon3_TelemtryLogStatus_get_latestEntryUnix);

STATIC mp_obj_t TctlmCubeComputerCommon3_TelemtryLogStatus_get_writeCounter(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_TelemtryLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32WriteCounter);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_TelemtryLogStatus_get_writeCounter_obj, TctlmCubeComputerCommon3_TelemtryLogStatus_get_writeCounter);

STATIC mp_obj_t TctlmCubeComputerCommon3_TelemtryLogStatus_get_readQueueState(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_TelemtryLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eReadQueueState);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_TelemtryLogStatus_get_readQueueState_obj, TctlmCubeComputerCommon3_TelemtryLogStatus_get_readQueueState);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t TctlmCubeComputerCommon3_TelemtryLogStatus_locals_dict_table[7] = {
    { MP_ROM_QSTR(MP_QSTR_get_numberOfEntriesQueued), MP_ROM_PTR(&TctlmCubeComputerCommon3_TelemtryLogStatus_get_numberOfEntriesQueued_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numberOfTlmIterations), MP_ROM_PTR(&TctlmCubeComputerCommon3_TelemtryLogStatus_get_numberOfTlmIterations_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numberOfEntries), MP_ROM_PTR(&TctlmCubeComputerCommon3_TelemtryLogStatus_get_numberOfEntries_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_oldestEntryUnix), MP_ROM_PTR(&TctlmCubeComputerCommon3_TelemtryLogStatus_get_oldestEntryUnix_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_latestEntryUnix), MP_ROM_PTR(&TctlmCubeComputerCommon3_TelemtryLogStatus_get_latestEntryUnix_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_writeCounter), MP_ROM_PTR(&TctlmCubeComputerCommon3_TelemtryLogStatus_get_writeCounter_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_readQueueState), MP_ROM_PTR(&TctlmCubeComputerCommon3_TelemtryLogStatus_get_readQueueState_obj) },
};

STATIC MP_DEFINE_CONST_DICT(TctlmCubeComputerCommon3_TelemtryLogStatus_locals_dict, TctlmCubeComputerCommon3_TelemtryLogStatus_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    TctlmCubeComputerCommon3_TelemtryLogStatus_type,
    MP_QSTR_TctlmCubeComputerCommon3_TelemtryLogStatus,
    MP_TYPE_FLAG_NONE,
    make_new, TctlmCubeComputerCommon3_TelemtryLogStatus_make_new,
    locals_dict, (mp_obj_dict_t*)&TctlmCubeComputerCommon3_TelemtryLogStatus_locals_dict
);

STATIC mp_obj_t TctlmCubeComputerCommon3_TelemtryLogStatus_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_TelemtryLogStatus_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    TctlmCubeComputerCommon3_TelemtryLogStatus_class_obj_t *p_self = m_new_obj(TctlmCubeComputerCommon3_TelemtryLogStatus_class_obj_t);
    p_self->base.type = &TctlmCubeComputerCommon3_TelemtryLogStatus_type;
    
    const OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_TelemtryLogStatus_t *p_data = (const OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_TelemtryLogStatus_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// TctlmCubeComputerCommon3_TelemtryLogStatus class constructor from a byte buffer
STATIC mp_obj_t TctlmCubeComputerCommon3_TelemtryLogStatus_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return TctlmCubeComputerCommon3_TelemtryLogStatus_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_TelemtryLogStatus_t, TctlmCubeComputerCommon3_TelemtryLogStatus_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_TelemtryLogStatus_t, TctlmCubeComputerCommon3_TelemtryLogStatus_class_obj_t, TctlmCubeComputerCommon3_TelemtryLogStatus)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_TelemtryLogStatus_make_from_buf_obj, TctlmCubeComputerCommon3_TelemtryLogStatus_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'BootStatus'
 *
 **********************************************************************/
    
// class structure for type BootStatus
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_BootStatus_t class_data;
} PACKED_STRUCT BootStatus_class_obj_t;

// BootStatus class constructor from field arguments
STATIC mp_obj_t BootStatus_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 9, 9, false);
    
    BootStatus_class_obj_t *p_self = m_new_obj(BootStatus_class_obj_t);
    p_self->base.type = type;
    
    // State
    p_self->class_data.eState = (uint8_t) mp_obj_get_int(p_args[0]);
    // ResetReason
    p_self->class_data.eResetReason = (uint8_t) mp_obj_get_int(p_args[1]);
    // SharedParamsError
    p_self->class_data.bSharedParamsError = (bool) mp_obj_get_int(p_args[2]);
    // PortValidationError
    p_self->class_data.bPortValidationError = (bool) mp_obj_get_int(p_args[3]);
    // PortDiscoveryError
    p_self->class_data.bPortDiscoveryError = (bool) mp_obj_get_int(p_args[4]);
    // OtpSerialError
    p_self->class_data.bOtpSerialError = (bool) mp_obj_get_int(p_args[5]);
    // CfgSerialError
    p_self->class_data.bCfgSerialError = (bool) mp_obj_get_int(p_args[6]);
    // SerialMismatchError
    p_self->class_data.bSerialMismatchError = (bool) mp_obj_get_int(p_args[7]);
    // ConfigInvalidError
    p_self->class_data.bConfigInvalidError = (bool) mp_obj_get_int(p_args[8]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'BootStatus' getters
//

STATIC mp_obj_t BootStatus_get_State(mp_obj_t self_in) 
{
    const BootStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eState);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(BootStatus_get_State_obj, BootStatus_get_State);

STATIC mp_obj_t BootStatus_get_ResetReason(mp_obj_t self_in) 
{
    const BootStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eResetReason);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(BootStatus_get_ResetReason_obj, BootStatus_get_ResetReason);

STATIC mp_obj_t BootStatus_get_SharedParamsError(mp_obj_t self_in) 
{
    const BootStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSharedParamsError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(BootStatus_get_SharedParamsError_obj, BootStatus_get_SharedParamsError);

STATIC mp_obj_t BootStatus_get_PortValidationError(mp_obj_t self_in) 
{
    const BootStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bPortValidationError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(BootStatus_get_PortValidationError_obj, BootStatus_get_PortValidationError);

STATIC mp_obj_t BootStatus_get_PortDiscoveryError(mp_obj_t self_in) 
{
    const BootStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bPortDiscoveryError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(BootStatus_get_PortDiscoveryError_obj, BootStatus_get_PortDiscoveryError);

STATIC mp_obj_t BootStatus_get_OtpSerialError(mp_obj_t self_in) 
{
    const BootStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bOtpSerialError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(BootStatus_get_OtpSerialError_obj, BootStatus_get_OtpSerialError);

STATIC mp_obj_t BootStatus_get_CfgSerialError(mp_obj_t self_in) 
{
    const BootStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bCfgSerialError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(BootStatus_get_CfgSerialError_obj, BootStatus_get_CfgSerialError);

STATIC mp_obj_t BootStatus_get_SerialMismatchError(mp_obj_t self_in) 
{
    const BootStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSerialMismatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(BootStatus_get_SerialMismatchError_obj, BootStatus_get_SerialMismatchError);

STATIC mp_obj_t BootStatus_get_ConfigInvalidError(mp_obj_t self_in) 
{
    const BootStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bConfigInvalidError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(BootStatus_get_ConfigInvalidError_obj, BootStatus_get_ConfigInvalidError);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t BootStatus_locals_dict_table[9] = {
    { MP_ROM_QSTR(MP_QSTR_get_State), MP_ROM_PTR(&BootStatus_get_State_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ResetReason), MP_ROM_PTR(&BootStatus_get_ResetReason_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_SharedParamsError), MP_ROM_PTR(&BootStatus_get_SharedParamsError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_PortValidationError), MP_ROM_PTR(&BootStatus_get_PortValidationError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_PortDiscoveryError), MP_ROM_PTR(&BootStatus_get_PortDiscoveryError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_OtpSerialError), MP_ROM_PTR(&BootStatus_get_OtpSerialError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_CfgSerialError), MP_ROM_PTR(&BootStatus_get_CfgSerialError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_SerialMismatchError), MP_ROM_PTR(&BootStatus_get_SerialMismatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ConfigInvalidError), MP_ROM_PTR(&BootStatus_get_ConfigInvalidError_obj) },
};

STATIC MP_DEFINE_CONST_DICT(BootStatus_locals_dict, BootStatus_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    BootStatus_type,
    MP_QSTR_BootStatus,
    MP_TYPE_FLAG_NONE,
    make_new, BootStatus_make_new,
    locals_dict, (mp_obj_dict_t*)&BootStatus_locals_dict
);

STATIC mp_obj_t BootStatus_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_BootStatus_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    BootStatus_class_obj_t *p_self = m_new_obj(BootStatus_class_obj_t);
    p_self->base.type = &BootStatus_type;
    
    const OBC_CUBEADCS_GEN2_BootStatus_t *p_data = (const OBC_CUBEADCS_GEN2_BootStatus_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// BootStatus class constructor from a byte buffer
STATIC mp_obj_t BootStatus_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return BootStatus_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_BootStatus_t, BootStatus_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_BootStatus_t, BootStatus_class_obj_t, BootStatus)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(BootStatus_make_from_buf_obj, BootStatus_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'TctlmCubeComputerControlProgram8_FileTransferStatus'
 *
 **********************************************************************/
    
// class structure for type TctlmCubeComputerControlProgram8_FileTransferStatus
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_TctlmCubeComputerControlProgram8_FileTransferStatus_t class_data;
} PACKED_STRUCT TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t;

// TctlmCubeComputerControlProgram8_FileTransferStatus class constructor from field arguments
STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 22, 22, false);
    
    TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = m_new_obj(TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t);
    p_self->base.type = type;
    
    // ftp_state
    p_self->class_data.eFtp_state = (uint8_t) mp_obj_get_int(p_args[0]);
    // upgradeState
    p_self->class_data.eUpgradeState = (uint8_t) mp_obj_get_int(p_args[1]);
    // dataRemain
    p_self->class_data.u32DataRemain = (uint32_t) mp_obj_get_int(p_args[2]);
    // errorCode
    p_self->class_data.u32ErrorCode = (uint32_t) mp_obj_get_int(p_args[3]);
    // busyError
    p_self->class_data.bBusyError = (bool) mp_obj_get_int(p_args[4]);
    // fileMetaError
    p_self->class_data.bFileMetaError = (bool) mp_obj_get_int(p_args[5]);
    // versionError
    p_self->class_data.bVersionError = (bool) mp_obj_get_int(p_args[6]);
    // nodeExistError
    p_self->class_data.bNodeExistError = (bool) mp_obj_get_int(p_args[7]);
    // nodeExpectError
    p_self->class_data.bNodeExpectError = (bool) mp_obj_get_int(p_args[8]);
    // fileCrcError
    p_self->class_data.bFileCrcError = (bool) mp_obj_get_int(p_args[9]);
    // fileSizeError
    p_self->class_data.bFileSizeError = (bool) mp_obj_get_int(p_args[10]);
    // fileError
    p_self->class_data.bFileError = (bool) mp_obj_get_int(p_args[11]);
    // fileInvalidError
    p_self->class_data.bFileInvalidError = (bool) mp_obj_get_int(p_args[12]);
    // fileFullError
    p_self->class_data.bFileFullError = (bool) mp_obj_get_int(p_args[13]);
    // fileEmptyError
    p_self->class_data.bFileEmptyError = (bool) mp_obj_get_int(p_args[14]);
    // readError
    p_self->class_data.bReadError = (bool) mp_obj_get_int(p_args[15]);
    // writeError
    p_self->class_data.bWriteError = (bool) mp_obj_get_int(p_args[16]);
    // eraseError
    p_self->class_data.bEraseError = (bool) mp_obj_get_int(p_args[17]);
    // frameSizeError
    p_self->class_data.bFrameSizeError = (bool) mp_obj_get_int(p_args[18]);
    // timeoutError
    p_self->class_data.bTimeoutError = (bool) mp_obj_get_int(p_args[19]);
    // nodeCommsError
    p_self->class_data.bNodeCommsError = (bool) mp_obj_get_int(p_args[20]);
    // nodeUsedError
    p_self->class_data.bNodeUsedError = (bool) mp_obj_get_int(p_args[21]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'TctlmCubeComputerControlProgram8_FileTransferStatus' getters
//

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_ftp_state(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eFtp_state);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_ftp_state_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_ftp_state);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_upgradeState(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eUpgradeState);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_upgradeState_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_upgradeState);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_dataRemain(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32DataRemain);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_dataRemain_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_dataRemain);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_errorCode(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32ErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_errorCode_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_errorCode);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_busyError(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bBusyError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_busyError_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_busyError);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileMetaError(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bFileMetaError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileMetaError_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileMetaError);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_versionError(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bVersionError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_versionError_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_versionError);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_nodeExistError(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bNodeExistError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_nodeExistError_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_nodeExistError);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_nodeExpectError(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bNodeExpectError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_nodeExpectError_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_nodeExpectError);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileCrcError(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bFileCrcError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileCrcError_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileCrcError);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileSizeError(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bFileSizeError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileSizeError_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileSizeError);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileError(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bFileError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileError_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileError);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileInvalidError(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bFileInvalidError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileInvalidError_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileInvalidError);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileFullError(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bFileFullError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileFullError_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileFullError);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileEmptyError(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bFileEmptyError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileEmptyError_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileEmptyError);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_readError(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bReadError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_readError_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_readError);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_writeError(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWriteError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_writeError_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_writeError);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_eraseError(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bEraseError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_eraseError_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_eraseError);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_frameSizeError(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bFrameSizeError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_frameSizeError_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_frameSizeError);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_timeoutError(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bTimeoutError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_timeoutError_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_timeoutError);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_nodeCommsError(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bNodeCommsError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_nodeCommsError_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_nodeCommsError);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_get_nodeUsedError(mp_obj_t self_in) 
{
    const TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bNodeUsedError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_get_nodeUsedError_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_get_nodeUsedError);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t TctlmCubeComputerControlProgram8_FileTransferStatus_locals_dict_table[22] = {
    { MP_ROM_QSTR(MP_QSTR_get_ftp_state), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_ftp_state_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_upgradeState), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_upgradeState_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_dataRemain), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_dataRemain_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_errorCode), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_errorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_busyError), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_busyError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fileMetaError), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileMetaError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_versionError), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_versionError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_nodeExistError), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_nodeExistError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_nodeExpectError), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_nodeExpectError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fileCrcError), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileCrcError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fileSizeError), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileSizeError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fileError), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fileInvalidError), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileInvalidError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fileFullError), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileFullError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fileEmptyError), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_fileEmptyError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_readError), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_readError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_writeError), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_writeError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_eraseError), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_eraseError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_frameSizeError), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_frameSizeError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_timeoutError), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_timeoutError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_nodeCommsError), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_nodeCommsError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_nodeUsedError), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_get_nodeUsedError_obj) },
};

STATIC MP_DEFINE_CONST_DICT(TctlmCubeComputerControlProgram8_FileTransferStatus_locals_dict, TctlmCubeComputerControlProgram8_FileTransferStatus_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    TctlmCubeComputerControlProgram8_FileTransferStatus_type,
    MP_QSTR_TctlmCubeComputerControlProgram8_FileTransferStatus,
    MP_TYPE_FLAG_NONE,
    make_new, TctlmCubeComputerControlProgram8_FileTransferStatus_make_new,
    locals_dict, (mp_obj_dict_t*)&TctlmCubeComputerControlProgram8_FileTransferStatus_locals_dict
);

STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_TctlmCubeComputerControlProgram8_FileTransferStatus_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *p_self = m_new_obj(TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t);
    p_self->base.type = &TctlmCubeComputerControlProgram8_FileTransferStatus_type;
    
    const OBC_CUBEADCS_GEN2_TctlmCubeComputerControlProgram8_FileTransferStatus_t *p_data = (const OBC_CUBEADCS_GEN2_TctlmCubeComputerControlProgram8_FileTransferStatus_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// TctlmCubeComputerControlProgram8_FileTransferStatus class constructor from a byte buffer
STATIC mp_obj_t TctlmCubeComputerControlProgram8_FileTransferStatus_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return TctlmCubeComputerControlProgram8_FileTransferStatus_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_TctlmCubeComputerControlProgram8_FileTransferStatus_t, TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_TctlmCubeComputerControlProgram8_FileTransferStatus_t, TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t, TctlmCubeComputerControlProgram8_FileTransferStatus)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerControlProgram8_FileTransferStatus_make_from_buf_obj, TctlmCubeComputerControlProgram8_FileTransferStatus_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup'
 *
 **********************************************************************/
    
// class structure for type TctlmCubeComputerCommon3_EventLogFilterTransferSetup
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_EventLogFilterTransferSetup_t class_data;
} PACKED_STRUCT TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t;

// TctlmCubeComputerCommon3_EventLogFilterTransferSetup class constructor from field arguments
STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 26, 26, false);
    
    TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = m_new_obj(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t);
    p_self->base.type = type;
    
    // filterType
    p_self->class_data.eFilterType = (uint8_t) mp_obj_get_int(p_args[0]);
    // startTimeUnix
    p_self->class_data.u32StartTimeUnix = (uint32_t) mp_obj_get_int(p_args[1]);
    // endTimeUnix
    p_self->class_data.u32EndTimeUnix = (uint32_t) mp_obj_get_int(p_args[2]);
    // numEntries
    p_self->class_data.u32NumEntries = (uint32_t) mp_obj_get_int(p_args[3]);
    // writeCounter
    p_self->class_data.u32WriteCounter = (uint32_t) mp_obj_get_int(p_args[4]);
    // includeClassCritical
    p_self->class_data.bIncludeClassCritical = (bool) mp_obj_get_int(p_args[5]);
    // includeClassMajorWarning
    p_self->class_data.bIncludeClassMajorWarning = (bool) mp_obj_get_int(p_args[6]);
    // includeClassMinorWarning
    p_self->class_data.bIncludeClassMinorWarning = (bool) mp_obj_get_int(p_args[7]);
    // includeClassInfo
    p_self->class_data.bIncludeClassInfo = (bool) mp_obj_get_int(p_args[8]);
    // includeSourceCubeComputer
    p_self->class_data.bIncludeSourceCubeComputer = (bool) mp_obj_get_int(p_args[9]);
    // includeSourceRwl0
    p_self->class_data.bIncludeSourceRwl0 = (bool) mp_obj_get_int(p_args[10]);
    // includeSourceRwl1
    p_self->class_data.bIncludeSourceRwl1 = (bool) mp_obj_get_int(p_args[11]);
    // includeSourceRwl2
    p_self->class_data.bIncludeSourceRwl2 = (bool) mp_obj_get_int(p_args[12]);
    // includeSourceRwl3
    p_self->class_data.bIncludeSourceRwl3 = (bool) mp_obj_get_int(p_args[13]);
    // includeSourceFss0
    p_self->class_data.bIncludeSourceFss0 = (bool) mp_obj_get_int(p_args[14]);
    // includeSourceFss1
    p_self->class_data.bIncludeSourceFss1 = (bool) mp_obj_get_int(p_args[15]);
    // includeSourceFss2
    p_self->class_data.bIncludeSourceFss2 = (bool) mp_obj_get_int(p_args[16]);
    // includeSourceFss3
    p_self->class_data.bIncludeSourceFss3 = (bool) mp_obj_get_int(p_args[17]);
    // includeSourceHss0
    p_self->class_data.bIncludeSourceHss0 = (bool) mp_obj_get_int(p_args[18]);
    // includeSourceHss1
    p_self->class_data.bIncludeSourceHss1 = (bool) mp_obj_get_int(p_args[19]);
    // includeSourceStr0
    p_self->class_data.bIncludeSourceStr0 = (bool) mp_obj_get_int(p_args[20]);
    // includeSourceStr1
    p_self->class_data.bIncludeSourceStr1 = (bool) mp_obj_get_int(p_args[21]);
    // includeSourceMag0
    p_self->class_data.bIncludeSourceMag0 = (bool) mp_obj_get_int(p_args[22]);
    // includeSourceMag1
    p_self->class_data.bIncludeSourceMag1 = (bool) mp_obj_get_int(p_args[23]);
    // includeSourceExt0
    p_self->class_data.bIncludeSourceExt0 = (bool) mp_obj_get_int(p_args[24]);
    // includeSourceExt1
    p_self->class_data.bIncludeSourceExt1 = (bool) mp_obj_get_int(p_args[25]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup' getters
//

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_filterType(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eFilterType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_filterType_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_filterType);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_startTimeUnix(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32StartTimeUnix);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_startTimeUnix_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_startTimeUnix);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_endTimeUnix(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32EndTimeUnix);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_endTimeUnix_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_endTimeUnix);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_numEntries(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32NumEntries);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_numEntries_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_numEntries);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_writeCounter(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32WriteCounter);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_writeCounter_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_writeCounter);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeClassCritical(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeClassCritical);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeClassCritical_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeClassCritical);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeClassMajorWarning(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeClassMajorWarning);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeClassMajorWarning_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeClassMajorWarning);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeClassMinorWarning(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeClassMinorWarning);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeClassMinorWarning_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeClassMinorWarning);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeClassInfo(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeClassInfo);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeClassInfo_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeClassInfo);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceCubeComputer(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceCubeComputer);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceCubeComputer_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceCubeComputer);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceRwl0(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceRwl0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceRwl0_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceRwl0);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceRwl1(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceRwl1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceRwl1_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceRwl1);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceRwl2(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceRwl2);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceRwl2_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceRwl2);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceRwl3(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceRwl3);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceRwl3_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceRwl3);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceFss0(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceFss0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceFss0_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceFss0);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceFss1(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceFss1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceFss1_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceFss1);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceFss2(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceFss2);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceFss2_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceFss2);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceFss3(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceFss3);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceFss3_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceFss3);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceHss0(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceHss0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceHss0_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceHss0);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceHss1(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceHss1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceHss1_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceHss1);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceStr0(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceStr0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceStr0_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceStr0);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceStr1(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceStr1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceStr1_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceStr1);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceMag0(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceMag0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceMag0_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceMag0);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceMag1(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceMag1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceMag1_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceMag1);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceExt0(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceExt0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceExt0_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceExt0);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceExt1(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceExt1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceExt1_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceExt1);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_locals_dict_table[26] = {
    { MP_ROM_QSTR(MP_QSTR_get_filterType), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_filterType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_startTimeUnix), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_startTimeUnix_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_endTimeUnix), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_endTimeUnix_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numEntries), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_numEntries_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_writeCounter), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_writeCounter_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeClassCritical), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeClassCritical_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeClassMajorWarning), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeClassMajorWarning_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeClassMinorWarning), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeClassMinorWarning_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeClassInfo), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeClassInfo_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceCubeComputer), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceCubeComputer_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceRwl0), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceRwl0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceRwl1), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceRwl1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceRwl2), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceRwl2_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceRwl3), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceRwl3_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceFss0), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceFss0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceFss1), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceFss1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceFss2), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceFss2_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceFss3), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceFss3_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceHss0), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceHss0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceHss1), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceHss1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceStr0), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceStr0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceStr1), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceStr1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceMag0), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceMag0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceMag1), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceMag1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceExt0), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceExt0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceExt1), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_get_includeSourceExt1_obj) },
};

STATIC MP_DEFINE_CONST_DICT(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_locals_dict, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    TctlmCubeComputerCommon3_EventLogFilterTransferSetup_type,
    MP_QSTR_TctlmCubeComputerCommon3_EventLogFilterTransferSetup,
    MP_TYPE_FLAG_NONE,
    make_new, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_make_new,
    locals_dict, (mp_obj_dict_t*)&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_locals_dict
);

STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_EventLogFilterTransferSetup_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *p_self = m_new_obj(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t);
    p_self->base.type = &TctlmCubeComputerCommon3_EventLogFilterTransferSetup_type;
    
    const OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_EventLogFilterTransferSetup_t *p_data = (const OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_EventLogFilterTransferSetup_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// TctlmCubeComputerCommon3_EventLogFilterTransferSetup class constructor from a byte buffer
STATIC mp_obj_t TctlmCubeComputerCommon3_EventLogFilterTransferSetup_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return TctlmCubeComputerCommon3_EventLogFilterTransferSetup_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_EventLogFilterTransferSetup_t, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_EventLogFilterTransferSetup_t, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t, TctlmCubeComputerCommon3_EventLogFilterTransferSetup)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_EventLogFilterTransferSetup_make_from_buf_obj, TctlmCubeComputerCommon3_EventLogFilterTransferSetup_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'TctlmCubeComputerCommon3_TelemetryLogTransferSetup'
 *
 **********************************************************************/
    
// class structure for type TctlmCubeComputerCommon3_TelemetryLogTransferSetup
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_TelemetryLogTransferSetup_t class_data;
} PACKED_STRUCT TctlmCubeComputerCommon3_TelemetryLogTransferSetup_class_obj_t;

// TctlmCubeComputerCommon3_TelemetryLogTransferSetup class constructor from field arguments
STATIC mp_obj_t TctlmCubeComputerCommon3_TelemetryLogTransferSetup_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 7, 7, false);
    
    TctlmCubeComputerCommon3_TelemetryLogTransferSetup_class_obj_t *p_self = m_new_obj(TctlmCubeComputerCommon3_TelemetryLogTransferSetup_class_obj_t);
    p_self->base.type = type;
    
    // filterType
    p_self->class_data.eFilterType = (uint8_t) mp_obj_get_int(p_args[0]);
    // startTimeUnix
    p_self->class_data.u32StartTimeUnix = (uint32_t) mp_obj_get_int(p_args[1]);
    // endTimeUnix
    p_self->class_data.u32EndTimeUnix = (uint32_t) mp_obj_get_int(p_args[2]);
    // numEntries
    p_self->class_data.u32NumEntries = (uint32_t) mp_obj_get_int(p_args[3]);
    // writeCounter
    p_self->class_data.u32WriteCounter = (uint32_t) mp_obj_get_int(p_args[4]);
    // tlmLogReturnInterval
    p_self->class_data.eTlmLogReturnInterval = (uint8_t) mp_obj_get_int(p_args[5]);
    // logIdBitmask
    upy_sd_copy_fidl_scalar_array_from_py_list_uint8_t(p_self->class_data.au8LogIdBitmask, 5, p_args[6]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'TctlmCubeComputerCommon3_TelemetryLogTransferSetup' getters
//

STATIC mp_obj_t TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_filterType(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_TelemetryLogTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eFilterType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_filterType_obj, TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_filterType);

STATIC mp_obj_t TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_startTimeUnix(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_TelemetryLogTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32StartTimeUnix);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_startTimeUnix_obj, TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_startTimeUnix);

STATIC mp_obj_t TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_endTimeUnix(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_TelemetryLogTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32EndTimeUnix);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_endTimeUnix_obj, TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_endTimeUnix);

STATIC mp_obj_t TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_numEntries(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_TelemetryLogTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32NumEntries);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_numEntries_obj, TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_numEntries);

STATIC mp_obj_t TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_writeCounter(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_TelemetryLogTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32WriteCounter);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_writeCounter_obj, TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_writeCounter);

STATIC mp_obj_t TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_tlmLogReturnInterval(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_TelemetryLogTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eTlmLogReturnInterval);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_tlmLogReturnInterval_obj, TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_tlmLogReturnInterval);

STATIC mp_obj_t TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_logIdBitmask(mp_obj_t self_in) 
{
    const TctlmCubeComputerCommon3_TelemetryLogTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return upy_sd_copy_fidl_scalar_array_to_py_list_uint8_t(p_self->class_data.au8LogIdBitmask, 5);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_logIdBitmask_obj, TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_logIdBitmask);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t TctlmCubeComputerCommon3_TelemetryLogTransferSetup_locals_dict_table[7] = {
    { MP_ROM_QSTR(MP_QSTR_get_filterType), MP_ROM_PTR(&TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_filterType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_startTimeUnix), MP_ROM_PTR(&TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_startTimeUnix_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_endTimeUnix), MP_ROM_PTR(&TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_endTimeUnix_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numEntries), MP_ROM_PTR(&TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_numEntries_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_writeCounter), MP_ROM_PTR(&TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_writeCounter_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_tlmLogReturnInterval), MP_ROM_PTR(&TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_tlmLogReturnInterval_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_logIdBitmask), MP_ROM_PTR(&TctlmCubeComputerCommon3_TelemetryLogTransferSetup_get_logIdBitmask_obj) },
};

STATIC MP_DEFINE_CONST_DICT(TctlmCubeComputerCommon3_TelemetryLogTransferSetup_locals_dict, TctlmCubeComputerCommon3_TelemetryLogTransferSetup_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    TctlmCubeComputerCommon3_TelemetryLogTransferSetup_type,
    MP_QSTR_TctlmCubeComputerCommon3_TelemetryLogTransferSetup,
    MP_TYPE_FLAG_NONE,
    make_new, TctlmCubeComputerCommon3_TelemetryLogTransferSetup_make_new,
    locals_dict, (mp_obj_dict_t*)&TctlmCubeComputerCommon3_TelemetryLogTransferSetup_locals_dict
);

STATIC mp_obj_t TctlmCubeComputerCommon3_TelemetryLogTransferSetup_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_TelemetryLogTransferSetup_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    TctlmCubeComputerCommon3_TelemetryLogTransferSetup_class_obj_t *p_self = m_new_obj(TctlmCubeComputerCommon3_TelemetryLogTransferSetup_class_obj_t);
    p_self->base.type = &TctlmCubeComputerCommon3_TelemetryLogTransferSetup_type;
    
    const OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_TelemetryLogTransferSetup_t *p_data = (const OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_TelemetryLogTransferSetup_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// TctlmCubeComputerCommon3_TelemetryLogTransferSetup class constructor from a byte buffer
STATIC mp_obj_t TctlmCubeComputerCommon3_TelemetryLogTransferSetup_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return TctlmCubeComputerCommon3_TelemetryLogTransferSetup_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_TelemetryLogTransferSetup_t, TctlmCubeComputerCommon3_TelemetryLogTransferSetup_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_TelemetryLogTransferSetup_t, TctlmCubeComputerCommon3_TelemetryLogTransferSetup_class_obj_t, TctlmCubeComputerCommon3_TelemetryLogTransferSetup)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TctlmCubeComputerCommon3_TelemetryLogTransferSetup_make_from_buf_obj, TctlmCubeComputerCommon3_TelemetryLogTransferSetup_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'ControlModeConfig'
 *
 **********************************************************************/
    
// class structure for type ControlModeConfig
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_ControlModeConfig_t class_data;
} PACKED_STRUCT ControlModeConfig_class_obj_t;

// ControlModeConfig class constructor from field arguments
STATIC mp_obj_t ControlModeConfig_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 2, 2, false);
    
    ControlModeConfig_class_obj_t *p_self = m_new_obj(ControlModeConfig_class_obj_t);
    p_self->base.type = type;
    
    // control_mode
    p_self->class_data.eControl_mode = (uint8_t) mp_obj_get_int(p_args[0]);
    // timeout
    p_self->class_data.u16Timeout = (uint16_t) mp_obj_get_int(p_args[1]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'ControlModeConfig' getters
//

STATIC mp_obj_t ControlModeConfig_get_control_mode(mp_obj_t self_in) 
{
    const ControlModeConfig_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eControl_mode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ControlModeConfig_get_control_mode_obj, ControlModeConfig_get_control_mode);

STATIC mp_obj_t ControlModeConfig_get_timeout(mp_obj_t self_in) 
{
    const ControlModeConfig_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16Timeout);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ControlModeConfig_get_timeout_obj, ControlModeConfig_get_timeout);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t ControlModeConfig_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_control_mode), MP_ROM_PTR(&ControlModeConfig_get_control_mode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_timeout), MP_ROM_PTR(&ControlModeConfig_get_timeout_obj) },
};

STATIC MP_DEFINE_CONST_DICT(ControlModeConfig_locals_dict, ControlModeConfig_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    ControlModeConfig_type,
    MP_QSTR_ControlModeConfig,
    MP_TYPE_FLAG_NONE,
    make_new, ControlModeConfig_make_new,
    locals_dict, (mp_obj_dict_t*)&ControlModeConfig_locals_dict
);

STATIC mp_obj_t ControlModeConfig_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_ControlModeConfig_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    ControlModeConfig_class_obj_t *p_self = m_new_obj(ControlModeConfig_class_obj_t);
    p_self->base.type = &ControlModeConfig_type;
    
    const OBC_CUBEADCS_GEN2_ControlModeConfig_t *p_data = (const OBC_CUBEADCS_GEN2_ControlModeConfig_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// ControlModeConfig class constructor from a byte buffer
STATIC mp_obj_t ControlModeConfig_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return ControlModeConfig_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_ControlModeConfig_t, ControlModeConfig_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_ControlModeConfig_t, ControlModeConfig_class_obj_t, ControlModeConfig)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ControlModeConfig_make_from_buf_obj, ControlModeConfig_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'state_change_core_args'
 *
 **********************************************************************/
    
// class structure for type state_change_core_args
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_state_change_core_args_t class_data;
} PACKED_STRUCT state_change_core_args_class_obj_t;

// state_change_core_args class constructor from field arguments
STATIC mp_obj_t state_change_core_args_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 4, 4, false);
    
    state_change_core_args_class_obj_t *p_self = m_new_obj(state_change_core_args_class_obj_t);
    p_self->base.type = type;
    
    // control_mode
    p_self->class_data.eControl_mode = (uint8_t) mp_obj_get_int(p_args[0]);
    // estimation_mode_main
    p_self->class_data.eEstimation_mode_main = (uint8_t) mp_obj_get_int(p_args[1]);
    // estimation_mode_backup
    p_self->class_data.eEstimation_mode_backup = (uint8_t) mp_obj_get_int(p_args[2]);
    // nodes_pwr_states
    p_self->class_data.sNodes_pwr_states = ((PowerState_class_obj_t *) MP_OBJ_TO_PTR(p_args[3]))->class_data;
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'state_change_core_args' getters
//

STATIC mp_obj_t state_change_core_args_get_control_mode(mp_obj_t self_in) 
{
    const state_change_core_args_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eControl_mode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(state_change_core_args_get_control_mode_obj, state_change_core_args_get_control_mode);

STATIC mp_obj_t state_change_core_args_get_estimation_mode_main(mp_obj_t self_in) 
{
    const state_change_core_args_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eEstimation_mode_main);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(state_change_core_args_get_estimation_mode_main_obj, state_change_core_args_get_estimation_mode_main);

STATIC mp_obj_t state_change_core_args_get_estimation_mode_backup(mp_obj_t self_in) 
{
    const state_change_core_args_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eEstimation_mode_backup);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(state_change_core_args_get_estimation_mode_backup_obj, state_change_core_args_get_estimation_mode_backup);

STATIC mp_obj_t state_change_core_args_get_nodes_pwr_states(mp_obj_t self_in) 
{
    const state_change_core_args_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return PowerState_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_PowerState_t), (const uint8_t *) &p_self->class_data.sNodes_pwr_states));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(state_change_core_args_get_nodes_pwr_states_obj, state_change_core_args_get_nodes_pwr_states);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t state_change_core_args_locals_dict_table[4] = {
    { MP_ROM_QSTR(MP_QSTR_get_control_mode), MP_ROM_PTR(&state_change_core_args_get_control_mode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_estimation_mode_main), MP_ROM_PTR(&state_change_core_args_get_estimation_mode_main_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_estimation_mode_backup), MP_ROM_PTR(&state_change_core_args_get_estimation_mode_backup_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_nodes_pwr_states), MP_ROM_PTR(&state_change_core_args_get_nodes_pwr_states_obj) },
};

STATIC MP_DEFINE_CONST_DICT(state_change_core_args_locals_dict, state_change_core_args_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    state_change_core_args_type,
    MP_QSTR_state_change_core_args,
    MP_TYPE_FLAG_NONE,
    make_new, state_change_core_args_make_new,
    locals_dict, (mp_obj_dict_t*)&state_change_core_args_locals_dict
);

STATIC mp_obj_t state_change_core_args_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_state_change_core_args_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    state_change_core_args_class_obj_t *p_self = m_new_obj(state_change_core_args_class_obj_t);
    p_self->base.type = &state_change_core_args_type;
    
    const OBC_CUBEADCS_GEN2_state_change_core_args_t *p_data = (const OBC_CUBEADCS_GEN2_state_change_core_args_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// state_change_core_args class constructor from a byte buffer
STATIC mp_obj_t state_change_core_args_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return state_change_core_args_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_state_change_core_args_t, state_change_core_args_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_state_change_core_args_t, state_change_core_args_class_obj_t, state_change_core_args)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(state_change_core_args_make_from_buf_obj, state_change_core_args_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'OpStatusCommon'
 *
 **********************************************************************/
    
// class structure for type OpStatusCommon
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_OpStatusCommon_t class_data;
} PACKED_STRUCT OpStatusCommon_class_obj_t;

// OpStatusCommon class constructor from field arguments
STATIC mp_obj_t OpStatusCommon_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 4, 4, false);
    
    OpStatusCommon_class_obj_t *p_self = m_new_obj(OpStatusCommon_class_obj_t);
    p_self->base.type = type;
    
    // boot_status
    p_self->class_data.sBoot_status = ((BootStatus_class_obj_t *) MP_OBJ_TO_PTR(p_args[0]))->class_data;
    // power_state
    p_self->class_data.sPower_state = ((PowerState_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    // comp_err_codes
    p_self->class_data.sComp_err_codes = ((CompErrCodes_class_obj_t *) MP_OBJ_TO_PTR(p_args[2]))->class_data;
    // is_valid
    p_self->class_data.bIs_valid = (bool) mp_obj_get_int(p_args[3]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'OpStatusCommon' getters
//

STATIC mp_obj_t OpStatusCommon_get_boot_status(mp_obj_t self_in) 
{
    const OpStatusCommon_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return BootStatus_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_BootStatus_t), (const uint8_t *) &p_self->class_data.sBoot_status));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(OpStatusCommon_get_boot_status_obj, OpStatusCommon_get_boot_status);

STATIC mp_obj_t OpStatusCommon_get_power_state(mp_obj_t self_in) 
{
    const OpStatusCommon_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return PowerState_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_PowerState_t), (const uint8_t *) &p_self->class_data.sPower_state));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(OpStatusCommon_get_power_state_obj, OpStatusCommon_get_power_state);

STATIC mp_obj_t OpStatusCommon_get_comp_err_codes(mp_obj_t self_in) 
{
    const OpStatusCommon_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return CompErrCodes_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_CompErrCodes_t), (const uint8_t *) &p_self->class_data.sComp_err_codes));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(OpStatusCommon_get_comp_err_codes_obj, OpStatusCommon_get_comp_err_codes);

STATIC mp_obj_t OpStatusCommon_get_is_valid(mp_obj_t self_in) 
{
    const OpStatusCommon_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIs_valid);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(OpStatusCommon_get_is_valid_obj, OpStatusCommon_get_is_valid);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t OpStatusCommon_locals_dict_table[4] = {
    { MP_ROM_QSTR(MP_QSTR_get_boot_status), MP_ROM_PTR(&OpStatusCommon_get_boot_status_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_power_state), MP_ROM_PTR(&OpStatusCommon_get_power_state_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_comp_err_codes), MP_ROM_PTR(&OpStatusCommon_get_comp_err_codes_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_is_valid), MP_ROM_PTR(&OpStatusCommon_get_is_valid_obj) },
};

STATIC MP_DEFINE_CONST_DICT(OpStatusCommon_locals_dict, OpStatusCommon_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    OpStatusCommon_type,
    MP_QSTR_OpStatusCommon,
    MP_TYPE_FLAG_NONE,
    make_new, OpStatusCommon_make_new,
    locals_dict, (mp_obj_dict_t*)&OpStatusCommon_locals_dict
);

STATIC mp_obj_t OpStatusCommon_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_OpStatusCommon_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    OpStatusCommon_class_obj_t *p_self = m_new_obj(OpStatusCommon_class_obj_t);
    p_self->base.type = &OpStatusCommon_type;
    
    const OBC_CUBEADCS_GEN2_OpStatusCommon_t *p_data = (const OBC_CUBEADCS_GEN2_OpStatusCommon_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// OpStatusCommon class constructor from a byte buffer
STATIC mp_obj_t OpStatusCommon_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return OpStatusCommon_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_OpStatusCommon_t, OpStatusCommon_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_OpStatusCommon_t, OpStatusCommon_class_obj_t, OpStatusCommon)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(OpStatusCommon_make_from_buf_obj, OpStatusCommon_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'cube_node_fw_update_status'
 *
 **********************************************************************/
    
// class structure for type cube_node_fw_update_status
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_cube_node_fw_update_status_t class_data;
} PACKED_STRUCT cube_node_fw_update_status_class_obj_t;

// cube_node_fw_update_status class constructor from field arguments
STATIC mp_obj_t cube_node_fw_update_status_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 7, 7, false);
    
    cube_node_fw_update_status_class_obj_t *p_self = m_new_obj(cube_node_fw_update_status_class_obj_t);
    p_self->base.type = type;
    
    // err_code
    p_self->class_data.tErr_code = (int32_t) mp_obj_get_int(p_args[0]);
    // force
    p_self->class_data.bForce = (bool) mp_obj_get_int(p_args[1]);
    // node_type
    p_self->class_data.eNode_type = (uint8_t) mp_obj_get_int(p_args[2]);
    // serial_int
    p_self->class_data.u32Serial_int = (uint32_t) mp_obj_get_int(p_args[3]);
    // status
    p_self->class_data.sStatus = ((TctlmCubeComputerControlProgram8_FileTransferStatus_class_obj_t *) MP_OBJ_TO_PTR(p_args[4]))->class_data;
    // control_program_file_name
    p_self->class_data.sControl_program_file_name = ((FName_class_obj_t *) MP_OBJ_TO_PTR(p_args[5]))->class_data;
    // configuration_file_name
    p_self->class_data.sConfiguration_file_name = ((FName_class_obj_t *) MP_OBJ_TO_PTR(p_args[6]))->class_data;
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'cube_node_fw_update_status' getters
//

STATIC mp_obj_t cube_node_fw_update_status_get_err_code(mp_obj_t self_in) 
{
    const cube_node_fw_update_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.tErr_code);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(cube_node_fw_update_status_get_err_code_obj, cube_node_fw_update_status_get_err_code);

STATIC mp_obj_t cube_node_fw_update_status_get_force(mp_obj_t self_in) 
{
    const cube_node_fw_update_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bForce);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(cube_node_fw_update_status_get_force_obj, cube_node_fw_update_status_get_force);

STATIC mp_obj_t cube_node_fw_update_status_get_node_type(mp_obj_t self_in) 
{
    const cube_node_fw_update_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eNode_type);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(cube_node_fw_update_status_get_node_type_obj, cube_node_fw_update_status_get_node_type);

STATIC mp_obj_t cube_node_fw_update_status_get_serial_int(mp_obj_t self_in) 
{
    const cube_node_fw_update_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Serial_int);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(cube_node_fw_update_status_get_serial_int_obj, cube_node_fw_update_status_get_serial_int);

STATIC mp_obj_t cube_node_fw_update_status_get_status(mp_obj_t self_in) 
{
    const cube_node_fw_update_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return TctlmCubeComputerControlProgram8_FileTransferStatus_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_TctlmCubeComputerControlProgram8_FileTransferStatus_t), (const uint8_t *) &p_self->class_data.sStatus));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(cube_node_fw_update_status_get_status_obj, cube_node_fw_update_status_get_status);

STATIC mp_obj_t cube_node_fw_update_status_get_control_program_file_name(mp_obj_t self_in) 
{
    const cube_node_fw_update_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return FName_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_FName_t), (const uint8_t *) &p_self->class_data.sControl_program_file_name));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(cube_node_fw_update_status_get_control_program_file_name_obj, cube_node_fw_update_status_get_control_program_file_name);

STATIC mp_obj_t cube_node_fw_update_status_get_configuration_file_name(mp_obj_t self_in) 
{
    const cube_node_fw_update_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return FName_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_FName_t), (const uint8_t *) &p_self->class_data.sConfiguration_file_name));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(cube_node_fw_update_status_get_configuration_file_name_obj, cube_node_fw_update_status_get_configuration_file_name);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t cube_node_fw_update_status_locals_dict_table[7] = {
    { MP_ROM_QSTR(MP_QSTR_get_err_code), MP_ROM_PTR(&cube_node_fw_update_status_get_err_code_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_force), MP_ROM_PTR(&cube_node_fw_update_status_get_force_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_node_type), MP_ROM_PTR(&cube_node_fw_update_status_get_node_type_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_serial_int), MP_ROM_PTR(&cube_node_fw_update_status_get_serial_int_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&cube_node_fw_update_status_get_status_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_control_program_file_name), MP_ROM_PTR(&cube_node_fw_update_status_get_control_program_file_name_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_configuration_file_name), MP_ROM_PTR(&cube_node_fw_update_status_get_configuration_file_name_obj) },
};

STATIC MP_DEFINE_CONST_DICT(cube_node_fw_update_status_locals_dict, cube_node_fw_update_status_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    cube_node_fw_update_status_type,
    MP_QSTR_cube_node_fw_update_status,
    MP_TYPE_FLAG_NONE,
    make_new, cube_node_fw_update_status_make_new,
    locals_dict, (mp_obj_dict_t*)&cube_node_fw_update_status_locals_dict
);

STATIC mp_obj_t cube_node_fw_update_status_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_cube_node_fw_update_status_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    cube_node_fw_update_status_class_obj_t *p_self = m_new_obj(cube_node_fw_update_status_class_obj_t);
    p_self->base.type = &cube_node_fw_update_status_type;
    
    const OBC_CUBEADCS_GEN2_cube_node_fw_update_status_t *p_data = (const OBC_CUBEADCS_GEN2_cube_node_fw_update_status_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// cube_node_fw_update_status class constructor from a byte buffer
STATIC mp_obj_t cube_node_fw_update_status_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return cube_node_fw_update_status_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_cube_node_fw_update_status_t, cube_node_fw_update_status_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_cube_node_fw_update_status_t, cube_node_fw_update_status_class_obj_t, cube_node_fw_update_status)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(cube_node_fw_update_status_make_from_buf_obj, cube_node_fw_update_status_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'download_event_status'
 *
 **********************************************************************/
    
// class structure for type download_event_status
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_download_event_status_t class_data;
} PACKED_STRUCT download_event_status_class_obj_t;

// download_event_status class constructor from field arguments
STATIC mp_obj_t download_event_status_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 4, 4, false);
    
    download_event_status_class_obj_t *p_self = m_new_obj(download_event_status_class_obj_t);
    p_self->base.type = type;
    
    // err
    p_self->class_data.tErr = (int32_t) mp_obj_get_int(p_args[0]);
    // setup
    p_self->class_data.sSetup = ((TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    // status
    p_self->class_data.sStatus = ((TctlmCubeComputerCommon3_EventLogStatus_class_obj_t *) MP_OBJ_TO_PTR(p_args[2]))->class_data;
    // file_name
    p_self->class_data.sFile_name = ((FName_class_obj_t *) MP_OBJ_TO_PTR(p_args[3]))->class_data;
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'download_event_status' getters
//

STATIC mp_obj_t download_event_status_get_err(mp_obj_t self_in) 
{
    const download_event_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.tErr);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(download_event_status_get_err_obj, download_event_status_get_err);

STATIC mp_obj_t download_event_status_get_setup(mp_obj_t self_in) 
{
    const download_event_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return TctlmCubeComputerCommon3_EventLogFilterTransferSetup_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_EventLogFilterTransferSetup_t), (const uint8_t *) &p_self->class_data.sSetup));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(download_event_status_get_setup_obj, download_event_status_get_setup);

STATIC mp_obj_t download_event_status_get_status(mp_obj_t self_in) 
{
    const download_event_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return TctlmCubeComputerCommon3_EventLogStatus_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_EventLogStatus_t), (const uint8_t *) &p_self->class_data.sStatus));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(download_event_status_get_status_obj, download_event_status_get_status);

STATIC mp_obj_t download_event_status_get_file_name(mp_obj_t self_in) 
{
    const download_event_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return FName_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_FName_t), (const uint8_t *) &p_self->class_data.sFile_name));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(download_event_status_get_file_name_obj, download_event_status_get_file_name);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t download_event_status_locals_dict_table[4] = {
    { MP_ROM_QSTR(MP_QSTR_get_err), MP_ROM_PTR(&download_event_status_get_err_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_setup), MP_ROM_PTR(&download_event_status_get_setup_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&download_event_status_get_status_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_file_name), MP_ROM_PTR(&download_event_status_get_file_name_obj) },
};

STATIC MP_DEFINE_CONST_DICT(download_event_status_locals_dict, download_event_status_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    download_event_status_type,
    MP_QSTR_download_event_status,
    MP_TYPE_FLAG_NONE,
    make_new, download_event_status_make_new,
    locals_dict, (mp_obj_dict_t*)&download_event_status_locals_dict
);

STATIC mp_obj_t download_event_status_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_download_event_status_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    download_event_status_class_obj_t *p_self = m_new_obj(download_event_status_class_obj_t);
    p_self->base.type = &download_event_status_type;
    
    const OBC_CUBEADCS_GEN2_download_event_status_t *p_data = (const OBC_CUBEADCS_GEN2_download_event_status_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// download_event_status class constructor from a byte buffer
STATIC mp_obj_t download_event_status_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return download_event_status_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_download_event_status_t, download_event_status_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_download_event_status_t, download_event_status_class_obj_t, download_event_status)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(download_event_status_make_from_buf_obj, download_event_status_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'download_telemetry_status'
 *
 **********************************************************************/
    
// class structure for type download_telemetry_status
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_download_telemetry_status_t class_data;
} PACKED_STRUCT download_telemetry_status_class_obj_t;

// download_telemetry_status class constructor from field arguments
STATIC mp_obj_t download_telemetry_status_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 4, 4, false);
    
    download_telemetry_status_class_obj_t *p_self = m_new_obj(download_telemetry_status_class_obj_t);
    p_self->base.type = type;
    
    // err
    p_self->class_data.tErr = (int32_t) mp_obj_get_int(p_args[0]);
    // setup
    p_self->class_data.sSetup = ((TctlmCubeComputerCommon3_TelemetryLogTransferSetup_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    // status
    p_self->class_data.sStatus = ((TctlmCubeComputerCommon3_TelemtryLogStatus_class_obj_t *) MP_OBJ_TO_PTR(p_args[2]))->class_data;
    // file_name
    p_self->class_data.sFile_name = ((FName_class_obj_t *) MP_OBJ_TO_PTR(p_args[3]))->class_data;
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'download_telemetry_status' getters
//

STATIC mp_obj_t download_telemetry_status_get_err(mp_obj_t self_in) 
{
    const download_telemetry_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.tErr);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(download_telemetry_status_get_err_obj, download_telemetry_status_get_err);

STATIC mp_obj_t download_telemetry_status_get_setup(mp_obj_t self_in) 
{
    const download_telemetry_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return TctlmCubeComputerCommon3_TelemetryLogTransferSetup_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_TelemetryLogTransferSetup_t), (const uint8_t *) &p_self->class_data.sSetup));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(download_telemetry_status_get_setup_obj, download_telemetry_status_get_setup);

STATIC mp_obj_t download_telemetry_status_get_status(mp_obj_t self_in) 
{
    const download_telemetry_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return TctlmCubeComputerCommon3_TelemtryLogStatus_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_TelemtryLogStatus_t), (const uint8_t *) &p_self->class_data.sStatus));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(download_telemetry_status_get_status_obj, download_telemetry_status_get_status);

STATIC mp_obj_t download_telemetry_status_get_file_name(mp_obj_t self_in) 
{
    const download_telemetry_status_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return FName_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_FName_t), (const uint8_t *) &p_self->class_data.sFile_name));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(download_telemetry_status_get_file_name_obj, download_telemetry_status_get_file_name);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t download_telemetry_status_locals_dict_table[4] = {
    { MP_ROM_QSTR(MP_QSTR_get_err), MP_ROM_PTR(&download_telemetry_status_get_err_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_setup), MP_ROM_PTR(&download_telemetry_status_get_setup_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&download_telemetry_status_get_status_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_file_name), MP_ROM_PTR(&download_telemetry_status_get_file_name_obj) },
};

STATIC MP_DEFINE_CONST_DICT(download_telemetry_status_locals_dict, download_telemetry_status_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    download_telemetry_status_type,
    MP_QSTR_download_telemetry_status,
    MP_TYPE_FLAG_NONE,
    make_new, download_telemetry_status_make_new,
    locals_dict, (mp_obj_dict_t*)&download_telemetry_status_locals_dict
);

STATIC mp_obj_t download_telemetry_status_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_download_telemetry_status_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    download_telemetry_status_class_obj_t *p_self = m_new_obj(download_telemetry_status_class_obj_t);
    p_self->base.type = &download_telemetry_status_type;
    
    const OBC_CUBEADCS_GEN2_download_telemetry_status_t *p_data = (const OBC_CUBEADCS_GEN2_download_telemetry_status_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// download_telemetry_status class constructor from a byte buffer
STATIC mp_obj_t download_telemetry_status_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return download_telemetry_status_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_download_telemetry_status_t, download_telemetry_status_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_download_telemetry_status_t, download_telemetry_status_class_obj_t, download_telemetry_status)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(download_telemetry_status_make_from_buf_obj, download_telemetry_status_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'OpStatusApp'
 *
 **********************************************************************/
    
// class structure for type OpStatusApp
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_OpStatusApp_t class_data;
} PACKED_STRUCT OpStatusApp_class_obj_t;

// OpStatusApp class constructor from field arguments
STATIC mp_obj_t OpStatusApp_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 5, 5, false);
    
    OpStatusApp_class_obj_t *p_self = m_new_obj(OpStatusApp_class_obj_t);
    p_self->base.type = type;
    
    // run_mode
    p_self->class_data.eRun_mode = (uint8_t) mp_obj_get_int(p_args[0]);
    // control_mode
    p_self->class_data.sControl_mode = ((ControlModeConfig_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    // estimation_mode
    p_self->class_data.sEstimation_mode = ((EstModeConfig_class_obj_t *) MP_OBJ_TO_PTR(p_args[2]))->class_data;
    // op_state
    p_self->class_data.eOp_state = (uint8_t) mp_obj_get_int(p_args[3]);
    // is_valid
    p_self->class_data.bIs_valid = (bool) mp_obj_get_int(p_args[4]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'OpStatusApp' getters
//

STATIC mp_obj_t OpStatusApp_get_run_mode(mp_obj_t self_in) 
{
    const OpStatusApp_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eRun_mode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(OpStatusApp_get_run_mode_obj, OpStatusApp_get_run_mode);

STATIC mp_obj_t OpStatusApp_get_control_mode(mp_obj_t self_in) 
{
    const OpStatusApp_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return ControlModeConfig_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_ControlModeConfig_t), (const uint8_t *) &p_self->class_data.sControl_mode));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(OpStatusApp_get_control_mode_obj, OpStatusApp_get_control_mode);

STATIC mp_obj_t OpStatusApp_get_estimation_mode(mp_obj_t self_in) 
{
    const OpStatusApp_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return EstModeConfig_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_EstModeConfig_t), (const uint8_t *) &p_self->class_data.sEstimation_mode));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(OpStatusApp_get_estimation_mode_obj, OpStatusApp_get_estimation_mode);

STATIC mp_obj_t OpStatusApp_get_op_state(mp_obj_t self_in) 
{
    const OpStatusApp_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eOp_state);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(OpStatusApp_get_op_state_obj, OpStatusApp_get_op_state);

STATIC mp_obj_t OpStatusApp_get_is_valid(mp_obj_t self_in) 
{
    const OpStatusApp_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIs_valid);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(OpStatusApp_get_is_valid_obj, OpStatusApp_get_is_valid);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t OpStatusApp_locals_dict_table[5] = {
    { MP_ROM_QSTR(MP_QSTR_get_run_mode), MP_ROM_PTR(&OpStatusApp_get_run_mode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_control_mode), MP_ROM_PTR(&OpStatusApp_get_control_mode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_estimation_mode), MP_ROM_PTR(&OpStatusApp_get_estimation_mode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_op_state), MP_ROM_PTR(&OpStatusApp_get_op_state_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_is_valid), MP_ROM_PTR(&OpStatusApp_get_is_valid_obj) },
};

STATIC MP_DEFINE_CONST_DICT(OpStatusApp_locals_dict, OpStatusApp_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    OpStatusApp_type,
    MP_QSTR_OpStatusApp,
    MP_TYPE_FLAG_NONE,
    make_new, OpStatusApp_make_new,
    locals_dict, (mp_obj_dict_t*)&OpStatusApp_locals_dict
);

STATIC mp_obj_t OpStatusApp_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_OpStatusApp_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    OpStatusApp_class_obj_t *p_self = m_new_obj(OpStatusApp_class_obj_t);
    p_self->base.type = &OpStatusApp_type;
    
    const OBC_CUBEADCS_GEN2_OpStatusApp_t *p_data = (const OBC_CUBEADCS_GEN2_OpStatusApp_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// OpStatusApp class constructor from a byte buffer
STATIC mp_obj_t OpStatusApp_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return OpStatusApp_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_OpStatusApp_t, OpStatusApp_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_OpStatusApp_t, OpStatusApp_class_obj_t, OpStatusApp)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(OpStatusApp_make_from_buf_obj, OpStatusApp_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'state_change_args'
 *
 **********************************************************************/
    
// class structure for type state_change_args
typedef struct 
{
    mp_obj_base_t base;
    OBC_CUBEADCS_GEN2_state_change_args_t class_data;
} PACKED_STRUCT state_change_args_class_obj_t;

// state_change_args class constructor from field arguments
STATIC mp_obj_t state_change_args_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 3, 3, false);
    
    state_change_args_class_obj_t *p_self = m_new_obj(state_change_args_class_obj_t);
    p_self->base.type = type;
    
    // core_args
    p_self->class_data.sCore_args = ((state_change_core_args_class_obj_t *) MP_OBJ_TO_PTR(p_args[0]))->class_data;
    // ref_params
    p_self->class_data.sRef_params = ((RefParams_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    // req_state_id
    p_self->class_data.u8Req_state_id = (uint8_t) mp_obj_get_int(p_args[2]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'state_change_args' getters
//

STATIC mp_obj_t state_change_args_get_core_args(mp_obj_t self_in) 
{
    const state_change_args_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return state_change_core_args_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_state_change_core_args_t), (const uint8_t *) &p_self->class_data.sCore_args));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(state_change_args_get_core_args_obj, state_change_args_get_core_args);

STATIC mp_obj_t state_change_args_get_ref_params(mp_obj_t self_in) 
{
    const state_change_args_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return RefParams_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_RefParams_t), (const uint8_t *) &p_self->class_data.sRef_params));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(state_change_args_get_ref_params_obj, state_change_args_get_ref_params);

STATIC mp_obj_t state_change_args_get_req_state_id(mp_obj_t self_in) 
{
    const state_change_args_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u8Req_state_id);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(state_change_args_get_req_state_id_obj, state_change_args_get_req_state_id);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t state_change_args_locals_dict_table[3] = {
    { MP_ROM_QSTR(MP_QSTR_get_core_args), MP_ROM_PTR(&state_change_args_get_core_args_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ref_params), MP_ROM_PTR(&state_change_args_get_ref_params_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_req_state_id), MP_ROM_PTR(&state_change_args_get_req_state_id_obj) },
};

STATIC MP_DEFINE_CONST_DICT(state_change_args_locals_dict, state_change_args_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    state_change_args_type,
    MP_QSTR_state_change_args,
    MP_TYPE_FLAG_NONE,
    make_new, state_change_args_make_new,
    locals_dict, (mp_obj_dict_t*)&state_change_args_locals_dict
);

STATIC mp_obj_t state_change_args_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(OBC_CUBEADCS_GEN2_state_change_args_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    state_change_args_class_obj_t *p_self = m_new_obj(state_change_args_class_obj_t);
    p_self->base.type = &state_change_args_type;
    
    const OBC_CUBEADCS_GEN2_state_change_args_t *p_data = (const OBC_CUBEADCS_GEN2_state_change_args_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// state_change_args class constructor from a byte buffer
STATIC mp_obj_t state_change_args_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return state_change_args_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_state_change_args_t, state_change_args_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(OBC_CUBEADCS_GEN2_state_change_args_t, state_change_args_class_obj_t, state_change_args)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(state_change_args_make_from_buf_obj, state_change_args_make_from_buf);

/**********************************************************************
 *
 *  Enumeration classes
 *
 **********************************************************************/
//
// Enumeration classes for type 'sys_states'
//
STATIC const mp_rom_map_elem_t sys_states_locals_dict_table[14] = 
{
    { MP_ROM_QSTR(MP_QSTR_SYS_STATES_NO_CONTROL), MP_ROM_INT(OBC_CUBEADCS_GEN2_SYS_STATES_NO_CONTROL)},
    { MP_ROM_QSTR(MP_QSTR_SYS_STATES_NORMAL_DETUMBLING), MP_ROM_INT(OBC_CUBEADCS_GEN2_SYS_STATES_NORMAL_DETUMBLING)},
    { MP_ROM_QSTR(MP_QSTR_SYS_STATES_Y_THOMSON), MP_ROM_INT(OBC_CUBEADCS_GEN2_SYS_STATES_Y_THOMSON)},
    { MP_ROM_QSTR(MP_QSTR_SYS_STATES_Y_THOMSON_MEMS_RATE), MP_ROM_INT(OBC_CUBEADCS_GEN2_SYS_STATES_Y_THOMSON_MEMS_RATE)},
    { MP_ROM_QSTR(MP_QSTR_SYS_STATES_FAST_DETUMBLING), MP_ROM_INT(OBC_CUBEADCS_GEN2_SYS_STATES_FAST_DETUMBLING)},
    { MP_ROM_QSTR(MP_QSTR_SYS_STATES_VERY_FAST_DETUMBLING), MP_ROM_INT(OBC_CUBEADCS_GEN2_SYS_STATES_VERY_FAST_DETUMBLING)},
    { MP_ROM_QSTR(MP_QSTR_SYS_STATES_Y_MOMENTUM), MP_ROM_INT(OBC_CUBEADCS_GEN2_SYS_STATES_Y_MOMENTUM)},
    { MP_ROM_QSTR(MP_QSTR_SYS_STATES_Y_MOMENTUM_FULL_STATE_EKF), MP_ROM_INT(OBC_CUBEADCS_GEN2_SYS_STATES_Y_MOMENTUM_FULL_STATE_EKF)},
    { MP_ROM_QSTR(MP_QSTR_SYS_STATES_THREE_AXIS), MP_ROM_INT(OBC_CUBEADCS_GEN2_SYS_STATES_THREE_AXIS)},
    { MP_ROM_QSTR(MP_QSTR_SYS_STATES_SUN_TRACKING), MP_ROM_INT(OBC_CUBEADCS_GEN2_SYS_STATES_SUN_TRACKING)},
    { MP_ROM_QSTR(MP_QSTR_SYS_STATES_TARGET_TRACKING), MP_ROM_INT(OBC_CUBEADCS_GEN2_SYS_STATES_TARGET_TRACKING)},
    { MP_ROM_QSTR(MP_QSTR_SYS_STATES_USER1), MP_ROM_INT(OBC_CUBEADCS_GEN2_SYS_STATES_USER1)},
    { MP_ROM_QSTR(MP_QSTR_SYS_STATES_USER2), MP_ROM_INT(OBC_CUBEADCS_GEN2_SYS_STATES_USER2)},
    { MP_ROM_QSTR(MP_QSTR_SYS_STATES_USER3), MP_ROM_INT(OBC_CUBEADCS_GEN2_SYS_STATES_USER3)},
};

STATIC MP_DEFINE_CONST_DICT(sys_states_class_locals_dict, sys_states_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    sys_states_class_type,
    MP_QSTR_sys_states,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&sys_states_class_locals_dict
);
//
// Enumeration classes for type 'TctlmCommonFrameworkEnums_NodeType'
//
STATIC const mp_rom_map_elem_t tctlmcommonframeworkenums_nodetype_locals_dict_table[17] = 
{
    { MP_ROM_QSTR(MP_QSTR_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_INVALID), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_INVALID)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_COMPUTER), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_COMPUTER)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_SENSE), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_SENSE)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_WHEEL), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_WHEEL)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_IR), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_IR)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_MAG_DEPLOY), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_MAG_DEPLOY)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_MAG_COMPACT), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_MAG_COMPACT)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_STAR), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_STAR)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_AURIGA), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_AURIGA)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_SLT), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_SLT)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_PST3S), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_PST3S)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_NSSRWL), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_NSSRWL)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_QUAD), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_QUAD)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_QUAD_PST3S), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_QUAD_PST3S)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_QUAD_NSSRWL), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_QUAD_NSSRWL)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_QUAD_LITEFUFORS), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCOMMONFRAMEWORKENUMS_NODETYPE_TCTLM_COMMON_FRAMEWORK_ENUMS__NODE_TYPE_CUBE_NODE_QUAD_LITEFUFORS)},
};

STATIC MP_DEFINE_CONST_DICT(tctlmcommonframeworkenums_nodetype_class_locals_dict, tctlmcommonframeworkenums_nodetype_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    tctlmcommonframeworkenums_nodetype_class_type,
    MP_QSTR_TctlmCommonFrameworkEnums_NodeType,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&tctlmcommonframeworkenums_nodetype_class_locals_dict
);
//
// Enumeration classes for type 'AbstractImagingNodeType'
//
STATIC const mp_rom_map_elem_t abstractimagingnodetype_locals_dict_table[8] = 
{
    { MP_ROM_QSTR(MP_QSTR_ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_STR_0), MP_ROM_INT(OBC_CUBEADCS_GEN2_ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_STR_0)},
    { MP_ROM_QSTR(MP_QSTR_ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_STR_1), MP_ROM_INT(OBC_CUBEADCS_GEN2_ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_STR_1)},
    { MP_ROM_QSTR(MP_QSTR_ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_FSS_0), MP_ROM_INT(OBC_CUBEADCS_GEN2_ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_FSS_0)},
    { MP_ROM_QSTR(MP_QSTR_ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_FSS_1), MP_ROM_INT(OBC_CUBEADCS_GEN2_ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_FSS_1)},
    { MP_ROM_QSTR(MP_QSTR_ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_FSS_2), MP_ROM_INT(OBC_CUBEADCS_GEN2_ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_FSS_2)},
    { MP_ROM_QSTR(MP_QSTR_ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_FSS_3), MP_ROM_INT(OBC_CUBEADCS_GEN2_ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_FSS_3)},
    { MP_ROM_QSTR(MP_QSTR_ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_HSS_0), MP_ROM_INT(OBC_CUBEADCS_GEN2_ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_HSS_0)},
    { MP_ROM_QSTR(MP_QSTR_ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_HSS_1), MP_ROM_INT(OBC_CUBEADCS_GEN2_ABSTRACTIMAGINGNODETYPE_TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_HSS_1)},
};

STATIC MP_DEFINE_CONST_DICT(abstractimagingnodetype_class_locals_dict, abstractimagingnodetype_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    abstractimagingnodetype_class_type,
    MP_QSTR_AbstractImagingNodeType,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&abstractimagingnodetype_class_locals_dict
);
//
// Enumeration classes for type 'TctlmCubeComputerControlProgram8_FtpUpgradeState'
//
STATIC const mp_rom_map_elem_t tctlmcubecomputercontrolprogram8_ftpupgradestate_locals_dict_table[7] = 
{
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_IDLE), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_IDLE)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_INIT), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_INIT)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_TRANS), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_TRANS)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_INIT_BIN), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_INIT_BIN)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_INIT_CFG), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_INIT_CFG)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_BUSY_BIN), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_BUSY_BIN)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_BUSY_CFG), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPUPGRADESTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__UPGRADE_BUSY_CFG)},
};

STATIC MP_DEFINE_CONST_DICT(tctlmcubecomputercontrolprogram8_ftpupgradestate_class_locals_dict, tctlmcubecomputercontrolprogram8_ftpupgradestate_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    tctlmcubecomputercontrolprogram8_ftpupgradestate_class_type,
    MP_QSTR_TctlmCubeComputerControlProgram8_FtpUpgradeState,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&tctlmcubecomputercontrolprogram8_ftpupgradestate_class_locals_dict
);
//
// Enumeration classes for type 'AdcsRunMode'
//
STATIC const mp_rom_map_elem_t adcsrunmode_locals_dict_table[4] = 
{
    { MP_ROM_QSTR(MP_QSTR_ADCSRUNMODE_ADCSOFF), MP_ROM_INT(OBC_CUBEADCS_GEN2_ADCSRUNMODE_AdcsOff)},
    { MP_ROM_QSTR(MP_QSTR_ADCSRUNMODE_ADCSENABLED), MP_ROM_INT(OBC_CUBEADCS_GEN2_ADCSRUNMODE_AdcsEnabled)},
    { MP_ROM_QSTR(MP_QSTR_ADCSRUNMODE_ADCSTRIGGERED), MP_ROM_INT(OBC_CUBEADCS_GEN2_ADCSRUNMODE_AdcsTriggered)},
    { MP_ROM_QSTR(MP_QSTR_ADCSRUNMODE_ADCSSIMULATION), MP_ROM_INT(OBC_CUBEADCS_GEN2_ADCSRUNMODE_AdcsSimulation)},
};

STATIC MP_DEFINE_CONST_DICT(adcsrunmode_class_locals_dict, adcsrunmode_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    adcsrunmode_class_type,
    MP_QSTR_AdcsRunMode,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&adcsrunmode_class_locals_dict
);
//
// Enumeration classes for type 'events_enum'
//
STATIC const mp_rom_map_elem_t events_enum_locals_dict_table[15] = 
{
    { MP_ROM_QSTR(MP_QSTR_EVENTS_ENUM_NODE_COMMUNICATION_ERROR), MP_ROM_INT(OBC_CUBEADCS_GEN2_EVENTS_ENUM_NODE_COMMUNICATION_ERROR)},
    { MP_ROM_QSTR(MP_QSTR_EVENTS_ENUM_ADCS_CONFIG_VALIDATION_ERROR), MP_ROM_INT(OBC_CUBEADCS_GEN2_EVENTS_ENUM_ADCS_CONFIG_VALIDATION_ERROR)},
    { MP_ROM_QSTR(MP_QSTR_EVENTS_ENUM_NODE_SETUP_ERROR), MP_ROM_INT(OBC_CUBEADCS_GEN2_EVENTS_ENUM_NODE_SETUP_ERROR)},
    { MP_ROM_QSTR(MP_QSTR_EVENTS_ENUM_NODE_JUMP_ERROR), MP_ROM_INT(OBC_CUBEADCS_GEN2_EVENTS_ENUM_NODE_JUMP_ERROR)},
    { MP_ROM_QSTR(MP_QSTR_EVENTS_ENUM_MAG_DEPLOY_ERROR), MP_ROM_INT(OBC_CUBEADCS_GEN2_EVENTS_ENUM_MAG_DEPLOY_ERROR)},
    { MP_ROM_QSTR(MP_QSTR_EVENTS_ENUM_CONTROL_LOOP_FAILURE), MP_ROM_INT(OBC_CUBEADCS_GEN2_EVENTS_ENUM_CONTROL_LOOP_FAILURE)},
    { MP_ROM_QSTR(MP_QSTR_EVENTS_ENUM_NODE_FAILURE), MP_ROM_INT(OBC_CUBEADCS_GEN2_EVENTS_ENUM_NODE_FAILURE)},
    { MP_ROM_QSTR(MP_QSTR_EVENTS_ENUM_CONFIG_PERSIST_ERROR), MP_ROM_INT(OBC_CUBEADCS_GEN2_EVENTS_ENUM_CONFIG_PERSIST_ERROR)},
    { MP_ROM_QSTR(MP_QSTR_EVENTS_ENUM_VIRTUAL_WATCHDOG_WARNING), MP_ROM_INT(OBC_CUBEADCS_GEN2_EVENTS_ENUM_VIRTUAL_WATCHDOG_WARNING)},
    { MP_ROM_QSTR(MP_QSTR_EVENTS_ENUM_PORT_VALIDATION_ERROR), MP_ROM_INT(OBC_CUBEADCS_GEN2_EVENTS_ENUM_PORT_VALIDATION_ERROR)},
    { MP_ROM_QSTR(MP_QSTR_EVENTS_ENUM_AUTO_DISCOVERY_ERROR), MP_ROM_INT(OBC_CUBEADCS_GEN2_EVENTS_ENUM_AUTO_DISCOVERY_ERROR)},
    { MP_ROM_QSTR(MP_QSTR_EVENTS_ENUM_CONTROL_LOOP_CRITICAL), MP_ROM_INT(OBC_CUBEADCS_GEN2_EVENTS_ENUM_CONTROL_LOOP_CRITICAL)},
    { MP_ROM_QSTR(MP_QSTR_EVENTS_ENUM_GYRO_VOLTAGE_ERROR), MP_ROM_INT(OBC_CUBEADCS_GEN2_EVENTS_ENUM_GYRO_VOLTAGE_ERROR)},
    { MP_ROM_QSTR(MP_QSTR_EVENTS_ENUM_GYRO_CRITICAL), MP_ROM_INT(OBC_CUBEADCS_GEN2_EVENTS_ENUM_GYRO_CRITICAL)},
    { MP_ROM_QSTR(MP_QSTR_EVENTS_ENUM_VIRTUAL_WATCHDOG_ERROR), MP_ROM_INT(OBC_CUBEADCS_GEN2_EVENTS_ENUM_VIRTUAL_WATCHDOG_ERROR)},
};

STATIC MP_DEFINE_CONST_DICT(events_enum_class_locals_dict, events_enum_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    events_enum_class_type,
    MP_QSTR_events_enum,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&events_enum_class_locals_dict
);
//
// Enumeration classes for type 'StandardResult'
//
STATIC const mp_rom_map_elem_t standardresult_locals_dict_table[4] = 
{
    { MP_ROM_QSTR(MP_QSTR_STANDARDRESULT_SUCCESS), MP_ROM_INT(OBC_CUBEADCS_GEN2_STANDARDRESULT_SUCCESS)},
    { MP_ROM_QSTR(MP_QSTR_STANDARDRESULT_ERROR), MP_ROM_INT(OBC_CUBEADCS_GEN2_STANDARDRESULT_ERROR)},
    { MP_ROM_QSTR(MP_QSTR_STANDARDRESULT_INVALID_ARGS), MP_ROM_INT(OBC_CUBEADCS_GEN2_STANDARDRESULT_INVALID_ARGS)},
    { MP_ROM_QSTR(MP_QSTR_STANDARDRESULT_NOT_SUPPORTED), MP_ROM_INT(OBC_CUBEADCS_GEN2_STANDARDRESULT_NOT_SUPPORTED)},
};

STATIC MP_DEFINE_CONST_DICT(standardresult_class_locals_dict, standardresult_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    standardresult_class_type,
    MP_QSTR_StandardResult,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&standardresult_class_locals_dict
);
//
// Enumeration classes for type 'NodePowerState'
//
STATIC const mp_rom_map_elem_t nodepowerstate_locals_dict_table[5] = 
{
    { MP_ROM_QSTR(MP_QSTR_NODEPOWERSTATE_OFF), MP_ROM_INT(OBC_CUBEADCS_GEN2_NODEPOWERSTATE_OFF)},
    { MP_ROM_QSTR(MP_QSTR_NODEPOWERSTATE_ON), MP_ROM_INT(OBC_CUBEADCS_GEN2_NODEPOWERSTATE_ON)},
    { MP_ROM_QSTR(MP_QSTR_NODEPOWERSTATE_NO_CHANGE), MP_ROM_INT(OBC_CUBEADCS_GEN2_NODEPOWERSTATE_NO_CHANGE)},
    { MP_ROM_QSTR(MP_QSTR_NODEPOWERSTATE_AUTO), MP_ROM_INT(OBC_CUBEADCS_GEN2_NODEPOWERSTATE_AUTO)},
    { MP_ROM_QSTR(MP_QSTR_NODEPOWERSTATE_POWER_ON_PASS), MP_ROM_INT(OBC_CUBEADCS_GEN2_NODEPOWERSTATE_POWER_ON_PASS)},
};

STATIC MP_DEFINE_CONST_DICT(nodepowerstate_class_locals_dict, nodepowerstate_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    nodepowerstate_class_type,
    MP_QSTR_NodePowerState,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&nodepowerstate_class_locals_dict
);
//
// Enumeration classes for type 'TctlmCubeComputerCommon3_EventReadQueueState'
//
STATIC const mp_rom_map_elem_t tctlmcubecomputercommon3_eventreadqueuestate_locals_dict_table[3] = 
{
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_TCTLM_CUBE_COMPUTER_COMMON_3__EVT_READ_QIDLE), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_TCTLM_CUBE_COMPUTER_COMMON_3__EVT_READ_QIDLE)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_TCTLM_CUBE_COMPUTER_COMMON_3__EVT_READ_QDOWNLOAD), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_TCTLM_CUBE_COMPUTER_COMMON_3__EVT_READ_QDOWNLOAD)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_TCTLM_CUBE_COMPUTER_COMMON_3__EVT_READ_QERASE), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_TCTLM_CUBE_COMPUTER_COMMON_3__EVT_READ_QERASE)},
};

STATIC MP_DEFINE_CONST_DICT(tctlmcubecomputercommon3_eventreadqueuestate_class_locals_dict, tctlmcubecomputercommon3_eventreadqueuestate_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    tctlmcubecomputercommon3_eventreadqueuestate_class_type,
    MP_QSTR_TctlmCubeComputerCommon3_EventReadQueueState,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&tctlmcubecomputercommon3_eventreadqueuestate_class_locals_dict
);
//
// Enumeration classes for type 'StateMachineEvents'
//
STATIC const mp_rom_map_elem_t statemachineevents_locals_dict_table[9] = 
{
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINEEVENTS_RESET), MP_ROM_INT(OBC_CUBEADCS_GEN2_STATEMACHINEEVENTS_RESET)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINEEVENTS_EVENT_MARKER_ACQUIRED), MP_ROM_INT(OBC_CUBEADCS_GEN2_STATEMACHINEEVENTS_EVENT_MARKER_ACQUIRED)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINEEVENTS_REQUEST_FDIR), MP_ROM_INT(OBC_CUBEADCS_GEN2_STATEMACHINEEVENTS_REQUEST_FDIR)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINEEVENTS_REQUEST_STATE_CHANGE), MP_ROM_INT(OBC_CUBEADCS_GEN2_STATEMACHINEEVENTS_REQUEST_STATE_CHANGE)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINEEVENTS_CHECK_COMPLETED), MP_ROM_INT(OBC_CUBEADCS_GEN2_STATEMACHINEEVENTS_CHECK_COMPLETED)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINEEVENTS_EVENT_DOWNLOAD_COMPLETED), MP_ROM_INT(OBC_CUBEADCS_GEN2_STATEMACHINEEVENTS_EVENT_DOWNLOAD_COMPLETED)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINEEVENTS_STATE_CHANGE_COMPLETED), MP_ROM_INT(OBC_CUBEADCS_GEN2_STATEMACHINEEVENTS_STATE_CHANGE_COMPLETED)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINEEVENTS_FDIR_COMPLETED), MP_ROM_INT(OBC_CUBEADCS_GEN2_STATEMACHINEEVENTS_FDIR_COMPLETED)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINEEVENTS_ADCS_RESETED), MP_ROM_INT(OBC_CUBEADCS_GEN2_STATEMACHINEEVENTS_ADCS_RESETED)},
};

STATIC MP_DEFINE_CONST_DICT(statemachineevents_class_locals_dict, statemachineevents_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    statemachineevents_class_type,
    MP_QSTR_StateMachineEvents,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&statemachineevents_class_locals_dict
);
//
// Enumeration classes for type 'TctlmCubeComputerCommon3_ImageTransferState'
//
STATIC const mp_rom_map_elem_t tctlmcubecomputercommon3_imagetransferstate_locals_dict_table[3] = 
{
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_TCTLM_CUBE_COMPUTER_COMMON_3__STATE_IDLE), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_TCTLM_CUBE_COMPUTER_COMMON_3__STATE_IDLE)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_TCTLM_CUBE_COMPUTER_COMMON_3__STATE_BUSY_STORE), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_TCTLM_CUBE_COMPUTER_COMMON_3__STATE_BUSY_STORE)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_TCTLM_CUBE_COMPUTER_COMMON_3__STATE_BUSY_DOWNLOAD), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_TCTLM_CUBE_COMPUTER_COMMON_3__STATE_BUSY_DOWNLOAD)},
};

STATIC MP_DEFINE_CONST_DICT(tctlmcubecomputercommon3_imagetransferstate_class_locals_dict, tctlmcubecomputercommon3_imagetransferstate_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    tctlmcubecomputercommon3_imagetransferstate_class_type,
    MP_QSTR_TctlmCubeComputerCommon3_ImageTransferState,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&tctlmcubecomputercommon3_imagetransferstate_class_locals_dict
);
//
// Enumeration classes for type 'EstimationModes'
//
STATIC const mp_rom_map_elem_t estimationmodes_locals_dict_table[8] = 
{
    { MP_ROM_QSTR(MP_QSTR_ESTIMATIONMODES_EST_NO_ESIMATOR), MP_ROM_INT(OBC_CUBEADCS_GEN2_ESTIMATIONMODES_EST_NO_ESIMATOR)},
    { MP_ROM_QSTR(MP_QSTR_ESTIMATIONMODES_EST_GYRO_MEASURED_RATES), MP_ROM_INT(OBC_CUBEADCS_GEN2_ESTIMATIONMODES_EST_GYRO_MEASURED_RATES)},
    { MP_ROM_QSTR(MP_QSTR_ESTIMATIONMODES_EST_MAG_EST_RATES), MP_ROM_INT(OBC_CUBEADCS_GEN2_ESTIMATIONMODES_EST_MAG_EST_RATES)},
    { MP_ROM_QSTR(MP_QSTR_ESTIMATIONMODES_EST_MAG_EST_RATES_WITH_PITCH_EST), MP_ROM_INT(OBC_CUBEADCS_GEN2_ESTIMATIONMODES_EST_MAG_EST_RATES_WITH_PITCH_EST)},
    { MP_ROM_QSTR(MP_QSTR_ESTIMATIONMODES_EST_TRIAD), MP_ROM_INT(OBC_CUBEADCS_GEN2_ESTIMATIONMODES_EST_TRIAD)},
    { MP_ROM_QSTR(MP_QSTR_ESTIMATIONMODES_EST_FULL_STATE_EKF), MP_ROM_INT(OBC_CUBEADCS_GEN2_ESTIMATIONMODES_EST_FULL_STATE_EKF)},
    { MP_ROM_QSTR(MP_QSTR_ESTIMATIONMODES_EST_GYRO_EKF), MP_ROM_INT(OBC_CUBEADCS_GEN2_ESTIMATIONMODES_EST_GYRO_EKF)},
    { MP_ROM_QSTR(MP_QSTR_ESTIMATIONMODES_EST_USER), MP_ROM_INT(OBC_CUBEADCS_GEN2_ESTIMATIONMODES_EST_USER)},
};

STATIC MP_DEFINE_CONST_DICT(estimationmodes_class_locals_dict, estimationmodes_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    estimationmodes_class_type,
    MP_QSTR_EstimationModes,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&estimationmodes_class_locals_dict
);
//
// Enumeration classes for type 'CommissioningStatus'
//
STATIC const mp_rom_map_elem_t commissioningstatus_locals_dict_table[2] = 
{
    { MP_ROM_QSTR(MP_QSTR_COMMISSIONINGSTATUS_CMS_STATUS_NOT_DONE), MP_ROM_INT(OBC_CUBEADCS_GEN2_COMMISSIONINGSTATUS_CMS_STATUS_NOT_DONE)},
    { MP_ROM_QSTR(MP_QSTR_COMMISSIONINGSTATUS_CMS_STATUS_COMPLETE), MP_ROM_INT(OBC_CUBEADCS_GEN2_COMMISSIONINGSTATUS_CMS_STATUS_COMPLETE)},
};

STATIC MP_DEFINE_CONST_DICT(commissioningstatus_class_locals_dict, commissioningstatus_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    commissioningstatus_class_type,
    MP_QSTR_CommissioningStatus,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&commissioningstatus_class_locals_dict
);
//
// Enumeration classes for type 'BootState'
//
STATIC const mp_rom_map_elem_t bootstate_locals_dict_table[20] = 
{
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_BOOTLOADERRUNNING), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_BootloaderRunning)},
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_BOOTLOADERBACKOFF), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_BootloaderBackoff)},
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_BOOTLOADERPORTVALIDATION), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_BootloaderPortValidation)},
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_BOOTLOADERAUTODISCOVER), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_BootloaderAutoDiscover)},
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_BOOTLOADERHALT), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_BootloaderHalt)},
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_BOOTLOADERJUMP), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_BootloaderJump)},
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_BOOTLOADEREXITERROR), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_BootloaderExitError)},
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_APPLICATIONRUNNING), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_ApplicationRunning)},
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_BOOTLOADERCFGUNLOCK), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_BootloaderCfgUnlock)},
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_BOOTLOADERBOOTPINEN), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_BootloaderBootPinEn)},
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_BOOTLOADERBOOTPINDIS), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_BootloaderBootPinDis)},
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_BOOTLOADERWRPCLEAR), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_BootloaderWrpClear)},
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_BOOTLOADERCFGUNLOCKERROR), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_BootloaderCfgUnlockError)},
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_BOOTLOADERBOOTPINENERROR), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_BootloaderBootPinEnError)},
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_BOOTLOADERBOOTPINDISERROR), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_BootloaderBootPinDisError)},
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_BOOTLOADERWRPCLEARERROR), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_BootloaderWrpClearError)},
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_BOOTLOADERAUTODISCOVERERROR), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_BootloaderAutoDiscoverError)},
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_BOOTLOADERBANKSYNCERROR), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_BootloaderBankSyncError)},
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_BOOTLOADERHALTRESET), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_BootloaderHaltReset)},
    { MP_ROM_QSTR(MP_QSTR_BOOTSTATE_ASSERTERROR), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTSTATE_AssertError)},
};

STATIC MP_DEFINE_CONST_DICT(bootstate_class_locals_dict, bootstate_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    bootstate_class_type,
    MP_QSTR_BootState,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&bootstate_class_locals_dict
);
//
// Enumeration classes for type 'TctlmCubeComputerCommon3_TlmLogReadQueueState'
//
STATIC const mp_rom_map_elem_t tctlmcubecomputercommon3_tlmlogreadqueuestate_locals_dict_table[3] = 
{
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TCTLM_CUBE_COMPUTER_COMMON_3__TLM_READ_QIDLE), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TCTLM_CUBE_COMPUTER_COMMON_3__TLM_READ_QIDLE)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TCTLM_CUBE_COMPUTER_COMMON_3__TLM_READ_QDOWNLOAD), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TCTLM_CUBE_COMPUTER_COMMON_3__TLM_READ_QDOWNLOAD)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TCTLM_CUBE_COMPUTER_COMMON_3__TLM_READ_QERASE), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TCTLM_CUBE_COMPUTER_COMMON_3__TLM_READ_QERASE)},
};

STATIC MP_DEFINE_CONST_DICT(tctlmcubecomputercommon3_tlmlogreadqueuestate_class_locals_dict, tctlmcubecomputercommon3_tlmlogreadqueuestate_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    tctlmcubecomputercommon3_tlmlogreadqueuestate_class_type,
    MP_QSTR_TctlmCubeComputerCommon3_TlmLogReadQueueState,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&tctlmcubecomputercommon3_tlmlogreadqueuestate_class_locals_dict
);
//
// Enumeration classes for type 'BootResetReason'
//
STATIC const mp_rom_map_elem_t bootresetreason_locals_dict_table[20] = 
{
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETUNKNOWN), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetUnknown)},
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETFIREWALL), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetFirewall)},
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETOBL), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetObl)},
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETEXTPIN), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetExtPin)},
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETBROWNOUT), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetBrownOut)},
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETSOFT), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetSoft)},
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETWATCHDOG), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetWatchdog)},
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETLOWPOWER), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetLowPower)},
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETENTERBOOTLOADER), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetEnterBootloader)},
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETCFGUNLOCK), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetCfgUnlock)},
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETBOOTPINEN), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetBootPinEn)},
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETBOOTPINDIS), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetBootPinDis)},
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETWRPCLEARALL), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetWrpClearAll)},
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETCFGUNLOCKERR), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetCfgUnlockErr)},
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETBOOTPINENERR), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetBootPinEnErr)},
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETBOOTPINDISERR), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetBootPinDisErr)},
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETWRPCLEARALLERR), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetWrpClearAllErr)},
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETBOOTLOADEREXITERR), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetBootloaderExitErr)},
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETBOOTLOADERBANKSYNCERR), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetBootloaderBankSyncErr)},
    { MP_ROM_QSTR(MP_QSTR_BOOTRESETREASON_RESETASSERTERR), MP_ROM_INT(OBC_CUBEADCS_GEN2_BOOTRESETREASON_ResetAssertErr)},
};

STATIC MP_DEFINE_CONST_DICT(bootresetreason_class_locals_dict, bootresetreason_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    bootresetreason_class_type,
    MP_QSTR_BootResetReason,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&bootresetreason_class_locals_dict
);
//
// Enumeration classes for type 'TctlmCubeComputerControlProgram8_FtpState'
//
STATIC const mp_rom_map_elem_t tctlmcubecomputercontrolprogram8_ftpstate_locals_dict_table[4] = 
{
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPSTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__IDLE), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPSTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__IDLE)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPSTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__INIT), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPSTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__INIT)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPSTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__BUSY), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPSTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__BUSY)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPSTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__LOCKED), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCONTROLPROGRAM8_FTPSTATE_TCTLM_CUBE_COMPUTER_CONTROL_PROGRAM_8__LOCKED)},
};

STATIC MP_DEFINE_CONST_DICT(tctlmcubecomputercontrolprogram8_ftpstate_class_locals_dict, tctlmcubecomputercontrolprogram8_ftpstate_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    tctlmcubecomputercontrolprogram8_ftpstate_class_type,
    MP_QSTR_TctlmCubeComputerControlProgram8_FtpState,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&tctlmcubecomputercontrolprogram8_ftpstate_class_locals_dict
);
//
// Enumeration classes for type 'StateMachineStates'
//
STATIC const mp_rom_map_elem_t statemachinestates_locals_dict_table[9] = 
{
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINESTATES_ROOT), MP_ROM_INT(OBC_CUBEADCS_GEN2_STATEMACHINESTATES_ROOT)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINESTATES_INIT), MP_ROM_INT(OBC_CUBEADCS_GEN2_STATEMACHINESTATES_INIT)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINESTATES_FIRMWARE_UPDATE), MP_ROM_INT(OBC_CUBEADCS_GEN2_STATEMACHINESTATES_FIRMWARE_UPDATE)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINESTATES_EVENT_MARKER_ACQUISITION), MP_ROM_INT(OBC_CUBEADCS_GEN2_STATEMACHINESTATES_EVENT_MARKER_ACQUISITION)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINESTATES_IDLE), MP_ROM_INT(OBC_CUBEADCS_GEN2_STATEMACHINESTATES_IDLE)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINESTATES_CHECK), MP_ROM_INT(OBC_CUBEADCS_GEN2_STATEMACHINESTATES_CHECK)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINESTATES_EVENT_DOWNLOAD), MP_ROM_INT(OBC_CUBEADCS_GEN2_STATEMACHINESTATES_EVENT_DOWNLOAD)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINESTATES_STATE_CHANGE), MP_ROM_INT(OBC_CUBEADCS_GEN2_STATEMACHINESTATES_STATE_CHANGE)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINESTATES_FDIR), MP_ROM_INT(OBC_CUBEADCS_GEN2_STATEMACHINESTATES_FDIR)},
};

STATIC MP_DEFINE_CONST_DICT(statemachinestates_class_locals_dict, statemachinestates_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    statemachinestates_class_type,
    MP_QSTR_StateMachineStates,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&statemachinestates_class_locals_dict
);
//
// Enumeration classes for type 'AdcsOpState'
//
STATIC const mp_rom_map_elem_t adcsopstate_locals_dict_table[4] = 
{
    { MP_ROM_QSTR(MP_QSTR_ADCSOPSTATE_OPSTATEMANUAL), MP_ROM_INT(OBC_CUBEADCS_GEN2_ADCSOPSTATE_OpStateManual)},
    { MP_ROM_QSTR(MP_QSTR_ADCSOPSTATE_OPSTATEAUTO), MP_ROM_INT(OBC_CUBEADCS_GEN2_ADCSOPSTATE_OpStateAuto)},
    { MP_ROM_QSTR(MP_QSTR_ADCSOPSTATE_OPSTATESAFE), MP_ROM_INT(OBC_CUBEADCS_GEN2_ADCSOPSTATE_OpStateSafe)},
    { MP_ROM_QSTR(MP_QSTR_ADCSOPSTATE_OPSTATEFAULT), MP_ROM_INT(OBC_CUBEADCS_GEN2_ADCSOPSTATE_OpStateFault)},
};

STATIC MP_DEFINE_CONST_DICT(adcsopstate_class_locals_dict, adcsopstate_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    adcsopstate_class_type,
    MP_QSTR_AdcsOpState,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&adcsopstate_class_locals_dict
);
//
// Enumeration classes for type 'AdcsProgType'
//
STATIC const mp_rom_map_elem_t adcsprogtype_locals_dict_table[2] = 
{
    { MP_ROM_QSTR(MP_QSTR_ADCSPROGTYPE_BOOTLOADER), MP_ROM_INT(OBC_CUBEADCS_GEN2_ADCSPROGTYPE_BOOTLOADER)},
    { MP_ROM_QSTR(MP_QSTR_ADCSPROGTYPE_APPLICATION), MP_ROM_INT(OBC_CUBEADCS_GEN2_ADCSPROGTYPE_APPLICATION)},
};

STATIC MP_DEFINE_CONST_DICT(adcsprogtype_class_locals_dict, adcsprogtype_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    adcsprogtype_class_type,
    MP_QSTR_AdcsProgType,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&adcsprogtype_class_locals_dict
);
//
// Enumeration classes for type 'TctlmCubeComputerCommon3_LogReadFilterType'
//
STATIC const mp_rom_map_elem_t tctlmcubecomputercommon3_logreadfiltertype_locals_dict_table[6] = 
{
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_TCTLM_CUBE_COMPUTER_COMMON_3__FILTER_NONE), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_TCTLM_CUBE_COMPUTER_COMMON_3__FILTER_NONE)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_TCTLM_CUBE_COMPUTER_COMMON_3__FILTER_TIME_SPAN), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_TCTLM_CUBE_COMPUTER_COMMON_3__FILTER_TIME_SPAN)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_TCTLM_CUBE_COMPUTER_COMMON_3__FILTER_TIME_NEXT_X), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_TCTLM_CUBE_COMPUTER_COMMON_3__FILTER_TIME_NEXT_X)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_TCTLM_CUBE_COMPUTER_COMMON_3__FILTER_FIRST_X), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_TCTLM_CUBE_COMPUTER_COMMON_3__FILTER_FIRST_X)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_TCTLM_CUBE_COMPUTER_COMMON_3__FILTER_LAST_X), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_TCTLM_CUBE_COMPUTER_COMMON_3__FILTER_LAST_X)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_TCTLM_CUBE_COMPUTER_COMMON_3__FILTER_COUNTER_NEXT_X), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_TCTLM_CUBE_COMPUTER_COMMON_3__FILTER_COUNTER_NEXT_X)},
};

STATIC MP_DEFINE_CONST_DICT(tctlmcubecomputercommon3_logreadfiltertype_class_locals_dict, tctlmcubecomputercommon3_logreadfiltertype_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    tctlmcubecomputercommon3_logreadfiltertype_class_type,
    MP_QSTR_TctlmCubeComputerCommon3_LogReadFilterType,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&tctlmcubecomputercommon3_logreadfiltertype_class_locals_dict
);
//
// Enumeration classes for type 'TctlmCubeComputerCommon3_TlmLogReturnIntervalValues'
//
STATIC const mp_rom_map_elem_t tctlmcubecomputercommon3_tlmlogreturnintervalvalues_locals_dict_table[10] = 
{
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL_200MS), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL_200MS)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL1S), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL1S)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL2S), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL2S)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL3S), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL3S)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL4S), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL4S)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL5S), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL5S)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL_10S), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL_10S)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL_20S), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL_20S)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL_50S), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL_50S)},
    { MP_ROM_QSTR(MP_QSTR_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL_100S), MP_ROM_INT(OBC_CUBEADCS_GEN2_TCTLMCUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_TCTLM_CUBE_COMPUTER_COMMON_3__INTERVAL_100S)},
};

STATIC MP_DEFINE_CONST_DICT(tctlmcubecomputercommon3_tlmlogreturnintervalvalues_class_locals_dict, tctlmcubecomputercommon3_tlmlogreturnintervalvalues_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    tctlmcubecomputercommon3_tlmlogreturnintervalvalues_class_type,
    MP_QSTR_TctlmCubeComputerCommon3_TlmLogReturnIntervalValues,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&tctlmcubecomputercommon3_tlmlogreturnintervalvalues_class_locals_dict
);
//
// Enumeration classes for type 'ControlModes'
//
STATIC const mp_rom_map_elem_t controlmodes_locals_dict_table[31] = 
{
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_NO_CONTROL), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_NO_CONTROL)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_1_AXIS_BDOT), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_1_AXIS_BDOT)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_Y_THOMSON), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_Y_THOMSON)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_3_AXIS_BDOT), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_3_AXIS_BDOT)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_3_AXIS_LOW_POWER), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_3_AXIS_LOW_POWER)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_SUN_Y_AXIS_SPIN_DETUMB), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_SUN_Y_AXIS_SPIN_DETUMB)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_Z_THOMSON), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_Z_THOMSON)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_SUN_Z_AXIS_SPIN_DETUMB), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_SUN_Z_AXIS_SPIN_DETUMB)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_MAG_CNTRL_GG_BOOM_AND_YAW), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_MAG_CNTRL_GG_BOOM_AND_YAW)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_MAG_CNTRL_GG_BOOM_AND_Z), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_MAG_CNTRL_GG_BOOM_AND_Z)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_INITIAL_Y_WHEEL_RAMP_UP), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_INITIAL_Y_WHEEL_RAMP_UP)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_INITIAL_Y_WHEEL_PITCH_CNTRL), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_INITIAL_Y_WHEEL_PITCH_CNTRL)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_RW_3_AXIS), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_RW_3_AXIS)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_RW_SUN_TRACKING), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_RW_SUN_TRACKING)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_RW_EO_TARGET_TRACKING), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_RW_EO_TARGET_TRACKING)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_RW_EARTH_TARGET_STEERING), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_RW_EARTH_TARGET_STEERING)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_RW_GS_TARGET_TRACKING), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_RW_GS_TARGET_TRACKING)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_RW_INERTIAL_TARGET_TRACKING), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_RW_INERTIAL_TARGET_TRACKING)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_RW_MOON_TRACKING), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_RW_MOON_TRACKING)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_RW_SAT_TARGET_TRACKING), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_RW_SAT_TARGET_TRACKING)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_NADIR_AND_YAW_TO_SUN), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_NADIR_AND_YAW_TO_SUN)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_NADIR_AND_YAW_TO_GROUND_TARGET), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_NADIR_AND_YAW_TO_GROUND_TARGET)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_VELOCITY_AND_ROLL_TO_SUN), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_VELOCITY_AND_ROLL_TO_SUN)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_VELOCITY_AND_ROLL_TO_GROUND_TARGET), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_VELOCITY_AND_ROLL_TO_GROUND_TARGET)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_NADIR_AND_YAW_BEST_TO_GS), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_NADIR_AND_YAW_BEST_TO_GS)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_FMC_TARGET), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_FMC_TARGET)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_YAW_SUN_SPIN), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_YAW_SUN_SPIN)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_SUN_DETUMBLE), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_SUN_DETUMBLE)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_STOP_RW_CONTROLLED), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_STOP_RW_CONTROLLED)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_OPEN_LOOP_RW), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_OPEN_LOOP_RW)},
    { MP_ROM_QSTR(MP_QSTR_CONTROLMODES_CNTRL_USER), MP_ROM_INT(OBC_CUBEADCS_GEN2_CONTROLMODES_CNTRL_USER)},
};

STATIC MP_DEFINE_CONST_DICT(controlmodes_class_locals_dict, controlmodes_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    controlmodes_class_type,
    MP_QSTR_ControlModes,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&controlmodes_class_locals_dict
);

/**********************************************************************
 *
 *  Static function definitions
 *
 **********************************************************************/
// uPy request function for method 'reqStateMachineStateChange'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2reqStateMachineStateChangeRequestData_t data;
} req_reqStateMachineStateChange_fp_t;

STATIC mp_obj_t req_reqStateMachineStateChange(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_reqStateMachineStateChange_fp_t * p_req_data = m_malloc(sizeof(req_reqStateMachineStateChange_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'reqStateMachineStateChange' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 10;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eSm_event = (uint8_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.sState_change_event_args = ((state_change_args_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_reqStateMachineStateChange_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'reqStateMachineStateChange'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2reqStateMachineStateChangeResponseData_t data;
} resp_reqStateMachineStateChange_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_reqStateMachineStateChange_fp_t class_data;
} resp_reqStateMachineStateChange_class_obj_t;

STATIC mp_obj_t resp_reqStateMachineStateChange_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_reqStateMachineStateChange_class_obj_t *p_self = m_new_obj(resp_reqStateMachineStateChange_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_reqStateMachineStateChange_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_reqStateMachineStateChange_fp_t *p_data = (resp_reqStateMachineStateChange_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "reqStateMachineStateChange" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_reqStateMachineStateChange_get_op_result(mp_obj_t self_in) 
{
    const resp_reqStateMachineStateChange_class_obj_t *p_resp_data = ((resp_reqStateMachineStateChange_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_reqStateMachineStateChange_get_op_result_obj, resp_reqStateMachineStateChange_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_reqStateMachineStateChange_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_reqStateMachineStateChange_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_reqStateMachineStateChange_locals_dict, resp_reqStateMachineStateChange_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2reqStateMachineStateChangeResponseData,
    MP_QSTR_resp_reqStateMachineStateChange,
    MP_TYPE_FLAG_NONE,
    make_new, resp_reqStateMachineStateChange_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_reqStateMachineStateChange_locals_dict    
);

// uPy request function for method 'getStateMachineState'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_getStateMachineState_fp_t;

STATIC mp_obj_t req_getStateMachineState(void)
{

    // allocate memory on the MicroPython heap
    req_getStateMachineState_fp_t * p_req_data = m_malloc(sizeof(req_getStateMachineState_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getStateMachineState' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 11;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getStateMachineState_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getStateMachineState'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2getStateMachineStateResponseData_t data;
} resp_getStateMachineState_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getStateMachineState_fp_t class_data;
} resp_getStateMachineState_class_obj_t;

STATIC mp_obj_t resp_getStateMachineState_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getStateMachineState_class_obj_t *p_self = m_new_obj(resp_getStateMachineState_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getStateMachineState_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getStateMachineState_fp_t *p_data = (resp_getStateMachineState_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "getStateMachineState" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getStateMachineState_get_sm_state(mp_obj_t self_in) 
{
    const resp_getStateMachineState_class_obj_t *p_resp_data = ((resp_getStateMachineState_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eSm_state);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getStateMachineState_get_sm_state_obj, resp_getStateMachineState_get_sm_state);

STATIC mp_obj_t resp_getStateMachineState_get_op_result(mp_obj_t self_in) 
{
    const resp_getStateMachineState_class_obj_t *p_resp_data = ((resp_getStateMachineState_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getStateMachineState_get_op_result_obj, resp_getStateMachineState_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getStateMachineState_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_sm_state), MP_ROM_PTR(&resp_getStateMachineState_get_sm_state_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_getStateMachineState_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getStateMachineState_locals_dict, resp_getStateMachineState_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2getStateMachineStateResponseData,
    MP_QSTR_resp_getStateMachineState,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getStateMachineState_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getStateMachineState_locals_dict    
);

// uPy request function for method 'getOpStatus'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_getOpStatus_fp_t;

STATIC mp_obj_t req_getOpStatus(void)
{

    // allocate memory on the MicroPython heap
    req_getOpStatus_fp_t * p_req_data = m_malloc(sizeof(req_getOpStatus_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getOpStatus' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 12;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getOpStatus_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getOpStatus'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2getOpStatusResponseData_t data;
} resp_getOpStatus_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getOpStatus_fp_t class_data;
} resp_getOpStatus_class_obj_t;

STATIC mp_obj_t resp_getOpStatus_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getOpStatus_class_obj_t *p_self = m_new_obj(resp_getOpStatus_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getOpStatus_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getOpStatus_fp_t *p_data = (resp_getOpStatus_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "getOpStatus" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getOpStatus_get_op_status_common(mp_obj_t self_in) 
{
    const resp_getOpStatus_class_obj_t *p_resp_data = ((resp_getOpStatus_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return OpStatusCommon_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_OpStatusCommon_t), (const uint8_t *) &p_resp_data->class_data.data.sOp_status_common));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getOpStatus_get_op_status_common_obj, resp_getOpStatus_get_op_status_common);

STATIC mp_obj_t resp_getOpStatus_get_op_status_app(mp_obj_t self_in) 
{
    const resp_getOpStatus_class_obj_t *p_resp_data = ((resp_getOpStatus_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return OpStatusApp_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_OpStatusApp_t), (const uint8_t *) &p_resp_data->class_data.data.sOp_status_app));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getOpStatus_get_op_status_app_obj, resp_getOpStatus_get_op_status_app);

STATIC mp_obj_t resp_getOpStatus_get_op_result(mp_obj_t self_in) 
{
    const resp_getOpStatus_class_obj_t *p_resp_data = ((resp_getOpStatus_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getOpStatus_get_op_result_obj, resp_getOpStatus_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getOpStatus_locals_dict_table[3] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_status_common), MP_ROM_PTR(&resp_getOpStatus_get_op_status_common_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_op_status_app), MP_ROM_PTR(&resp_getOpStatus_get_op_status_app_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_getOpStatus_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getOpStatus_locals_dict, resp_getOpStatus_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2getOpStatusResponseData,
    MP_QSTR_resp_getOpStatus,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getOpStatus_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getOpStatus_locals_dict    
);

// uPy request function for method 'reqSoftResetAndMode'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2reqSoftResetAndModeRequestData_t data;
} req_reqSoftResetAndMode_fp_t;

STATIC mp_obj_t req_reqSoftResetAndMode(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_reqSoftResetAndMode_fp_t * p_req_data = m_malloc(sizeof(req_reqSoftResetAndMode_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'reqSoftResetAndMode' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 13;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eProg_type = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_reqSoftResetAndMode_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'reqSoftResetAndMode'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2reqSoftResetAndModeResponseData_t data;
} resp_reqSoftResetAndMode_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_reqSoftResetAndMode_fp_t class_data;
} resp_reqSoftResetAndMode_class_obj_t;

STATIC mp_obj_t resp_reqSoftResetAndMode_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_reqSoftResetAndMode_class_obj_t *p_self = m_new_obj(resp_reqSoftResetAndMode_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_reqSoftResetAndMode_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_reqSoftResetAndMode_fp_t *p_data = (resp_reqSoftResetAndMode_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "reqSoftResetAndMode" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_reqSoftResetAndMode_get_op_result(mp_obj_t self_in) 
{
    const resp_reqSoftResetAndMode_class_obj_t *p_resp_data = ((resp_reqSoftResetAndMode_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_reqSoftResetAndMode_get_op_result_obj, resp_reqSoftResetAndMode_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_reqSoftResetAndMode_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_reqSoftResetAndMode_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_reqSoftResetAndMode_locals_dict, resp_reqSoftResetAndMode_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2reqSoftResetAndModeResponseData,
    MP_QSTR_resp_reqSoftResetAndMode,
    MP_TYPE_FLAG_NONE,
    make_new, resp_reqSoftResetAndMode_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_reqSoftResetAndMode_locals_dict    
);

// uPy request function for method 'get_events_since_last_power_up'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_get_events_since_last_power_up_fp_t;

STATIC mp_obj_t req_get_events_since_last_power_up(void)
{

    // allocate memory on the MicroPython heap
    req_get_events_since_last_power_up_fp_t * p_req_data = m_malloc(sizeof(req_get_events_since_last_power_up_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'get_events_since_last_power_up' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 14;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_get_events_since_last_power_up_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'get_events_since_last_power_up'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2get_events_since_last_power_upResponseData_t data;
} resp_get_events_since_last_power_up_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_get_events_since_last_power_up_fp_t class_data;
} resp_get_events_since_last_power_up_class_obj_t;

STATIC mp_obj_t resp_get_events_since_last_power_up_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_get_events_since_last_power_up_class_obj_t *p_self = m_new_obj(resp_get_events_since_last_power_up_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_get_events_since_last_power_up_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_get_events_since_last_power_up_fp_t *p_data = (resp_get_events_since_last_power_up_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "get_events_since_last_power_up" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_get_events_since_last_power_up_get_all_events(mp_obj_t self_in) 
{
    const resp_get_events_since_last_power_up_class_obj_t *p_resp_data = ((resp_get_events_since_last_power_up_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return events_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_events_t), (const uint8_t *) &p_resp_data->class_data.data.sAll_events));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_events_since_last_power_up_get_all_events_obj, resp_get_events_since_last_power_up_get_all_events);

STATIC mp_obj_t resp_get_events_since_last_power_up_get_op_result(mp_obj_t self_in) 
{
    const resp_get_events_since_last_power_up_class_obj_t *p_resp_data = ((resp_get_events_since_last_power_up_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_events_since_last_power_up_get_op_result_obj, resp_get_events_since_last_power_up_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_get_events_since_last_power_up_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_all_events), MP_ROM_PTR(&resp_get_events_since_last_power_up_get_all_events_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_get_events_since_last_power_up_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_get_events_since_last_power_up_locals_dict, resp_get_events_since_last_power_up_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2get_events_since_last_power_upResponseData,
    MP_QSTR_resp_get_events_since_last_power_up,
    MP_TYPE_FLAG_NONE,
    make_new, resp_get_events_since_last_power_up_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_get_events_since_last_power_up_locals_dict    
);

// uPy request function for method 'clear_events_since_last_power_up'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_clear_events_since_last_power_up_fp_t;

STATIC mp_obj_t req_clear_events_since_last_power_up(void)
{

    // allocate memory on the MicroPython heap
    req_clear_events_since_last_power_up_fp_t * p_req_data = m_malloc(sizeof(req_clear_events_since_last_power_up_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'clear_events_since_last_power_up' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 15;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_clear_events_since_last_power_up_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'clear_events_since_last_power_up'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2clear_events_since_last_power_upResponseData_t data;
} resp_clear_events_since_last_power_up_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_clear_events_since_last_power_up_fp_t class_data;
} resp_clear_events_since_last_power_up_class_obj_t;

STATIC mp_obj_t resp_clear_events_since_last_power_up_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_clear_events_since_last_power_up_class_obj_t *p_self = m_new_obj(resp_clear_events_since_last_power_up_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_clear_events_since_last_power_up_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_clear_events_since_last_power_up_fp_t *p_data = (resp_clear_events_since_last_power_up_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "clear_events_since_last_power_up" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_clear_events_since_last_power_up_get_op_result(mp_obj_t self_in) 
{
    const resp_clear_events_since_last_power_up_class_obj_t *p_resp_data = ((resp_clear_events_since_last_power_up_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_clear_events_since_last_power_up_get_op_result_obj, resp_clear_events_since_last_power_up_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_clear_events_since_last_power_up_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_clear_events_since_last_power_up_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_clear_events_since_last_power_up_locals_dict, resp_clear_events_since_last_power_up_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2clear_events_since_last_power_upResponseData,
    MP_QSTR_resp_clear_events_since_last_power_up,
    MP_TYPE_FLAG_NONE,
    make_new, resp_clear_events_since_last_power_up_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_clear_events_since_last_power_up_locals_dict    
);

// uPy request function for method 'download_evt'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2download_evtRequestData_t data;
} req_download_evt_fp_t;

STATIC mp_obj_t req_download_evt(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_download_evt_fp_t * p_req_data = m_malloc(sizeof(req_download_evt_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'download_evt' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 16;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.sFile_name = ((FName_class_obj_t *) MP_OBJ_TO_PTR(p_args[0]))->class_data;
    p_req_data->data.sSetup = ((TctlmCubeComputerCommon3_EventLogFilterTransferSetup_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_download_evt_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'download_evt'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2download_evtResponseData_t data;
} resp_download_evt_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_download_evt_fp_t class_data;
} resp_download_evt_class_obj_t;

STATIC mp_obj_t resp_download_evt_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_download_evt_class_obj_t *p_self = m_new_obj(resp_download_evt_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_download_evt_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_download_evt_fp_t *p_data = (resp_download_evt_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "download_evt" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_download_evt_get_err(mp_obj_t self_in) 
{
    const resp_download_evt_class_obj_t *p_resp_data = ((resp_download_evt_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tErr);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_download_evt_get_err_obj, resp_download_evt_get_err);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_download_evt_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_err), MP_ROM_PTR(&resp_download_evt_get_err_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_download_evt_locals_dict, resp_download_evt_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2download_evtResponseData,
    MP_QSTR_resp_download_evt,
    MP_TYPE_FLAG_NONE,
    make_new, resp_download_evt_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_download_evt_locals_dict    
);

// uPy request function for method 'download_evt_status'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_download_evt_status_fp_t;

STATIC mp_obj_t req_download_evt_status(void)
{

    // allocate memory on the MicroPython heap
    req_download_evt_status_fp_t * p_req_data = m_malloc(sizeof(req_download_evt_status_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'download_evt_status' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 17;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_download_evt_status_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'download_evt_status'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2download_evt_statusResponseData_t data;
} resp_download_evt_status_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_download_evt_status_fp_t class_data;
} resp_download_evt_status_class_obj_t;

STATIC mp_obj_t resp_download_evt_status_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_download_evt_status_class_obj_t *p_self = m_new_obj(resp_download_evt_status_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_download_evt_status_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_download_evt_status_fp_t *p_data = (resp_download_evt_status_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "download_evt_status" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_download_evt_status_get_err(mp_obj_t self_in) 
{
    const resp_download_evt_status_class_obj_t *p_resp_data = ((resp_download_evt_status_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tErr);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_download_evt_status_get_err_obj, resp_download_evt_status_get_err);

STATIC mp_obj_t resp_download_evt_status_get_status(mp_obj_t self_in) 
{
    const resp_download_evt_status_class_obj_t *p_resp_data = ((resp_download_evt_status_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return download_event_status_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_download_event_status_t), (const uint8_t *) &p_resp_data->class_data.data.sStatus));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_download_evt_status_get_status_obj, resp_download_evt_status_get_status);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_download_evt_status_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_err), MP_ROM_PTR(&resp_download_evt_status_get_err_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_download_evt_status_get_status_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_download_evt_status_locals_dict, resp_download_evt_status_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2download_evt_statusResponseData,
    MP_QSTR_resp_download_evt_status,
    MP_TYPE_FLAG_NONE,
    make_new, resp_download_evt_status_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_download_evt_status_locals_dict    
);

// uPy request function for method 'download_tlm'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2download_tlmRequestData_t data;
} req_download_tlm_fp_t;

STATIC mp_obj_t req_download_tlm(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_download_tlm_fp_t * p_req_data = m_malloc(sizeof(req_download_tlm_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'download_tlm' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 18;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.sFile_name = ((FName_class_obj_t *) MP_OBJ_TO_PTR(p_args[0]))->class_data;
    p_req_data->data.sSetup = ((TctlmCubeComputerCommon3_TelemetryLogTransferSetup_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_download_tlm_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'download_tlm'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2download_tlmResponseData_t data;
} resp_download_tlm_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_download_tlm_fp_t class_data;
} resp_download_tlm_class_obj_t;

STATIC mp_obj_t resp_download_tlm_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_download_tlm_class_obj_t *p_self = m_new_obj(resp_download_tlm_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_download_tlm_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_download_tlm_fp_t *p_data = (resp_download_tlm_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "download_tlm" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_download_tlm_get_err(mp_obj_t self_in) 
{
    const resp_download_tlm_class_obj_t *p_resp_data = ((resp_download_tlm_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tErr);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_download_tlm_get_err_obj, resp_download_tlm_get_err);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_download_tlm_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_err), MP_ROM_PTR(&resp_download_tlm_get_err_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_download_tlm_locals_dict, resp_download_tlm_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2download_tlmResponseData,
    MP_QSTR_resp_download_tlm,
    MP_TYPE_FLAG_NONE,
    make_new, resp_download_tlm_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_download_tlm_locals_dict    
);

// uPy request function for method 'download_tlm_status'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_download_tlm_status_fp_t;

STATIC mp_obj_t req_download_tlm_status(void)
{

    // allocate memory on the MicroPython heap
    req_download_tlm_status_fp_t * p_req_data = m_malloc(sizeof(req_download_tlm_status_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'download_tlm_status' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 19;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_download_tlm_status_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'download_tlm_status'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2download_tlm_statusResponseData_t data;
} resp_download_tlm_status_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_download_tlm_status_fp_t class_data;
} resp_download_tlm_status_class_obj_t;

STATIC mp_obj_t resp_download_tlm_status_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_download_tlm_status_class_obj_t *p_self = m_new_obj(resp_download_tlm_status_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_download_tlm_status_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_download_tlm_status_fp_t *p_data = (resp_download_tlm_status_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "download_tlm_status" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_download_tlm_status_get_err(mp_obj_t self_in) 
{
    const resp_download_tlm_status_class_obj_t *p_resp_data = ((resp_download_tlm_status_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tErr);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_download_tlm_status_get_err_obj, resp_download_tlm_status_get_err);

STATIC mp_obj_t resp_download_tlm_status_get_status(mp_obj_t self_in) 
{
    const resp_download_tlm_status_class_obj_t *p_resp_data = ((resp_download_tlm_status_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return download_telemetry_status_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_download_telemetry_status_t), (const uint8_t *) &p_resp_data->class_data.data.sStatus));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_download_tlm_status_get_status_obj, resp_download_tlm_status_get_status);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_download_tlm_status_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_err), MP_ROM_PTR(&resp_download_tlm_status_get_err_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_download_tlm_status_get_status_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_download_tlm_status_locals_dict, resp_download_tlm_status_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2download_tlm_statusResponseData,
    MP_QSTR_resp_download_tlm_status,
    MP_TYPE_FLAG_NONE,
    make_new, resp_download_tlm_status_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_download_tlm_status_locals_dict    
);

// uPy request function for method 'download_img_direct'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2download_img_directRequestData_t data;
} req_download_img_direct_fp_t;

STATIC mp_obj_t req_download_img_direct(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 3)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 3 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_download_img_direct_fp_t * p_req_data = m_malloc(sizeof(req_download_img_direct_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'download_img_direct' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 20;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.sFile_name = ((FName_class_obj_t *) MP_OBJ_TO_PTR(p_args[0]))->class_data;
    p_req_data->data.eNode = (uint8_t) mp_obj_get_int(p_args[1]);
    p_req_data->data.u32File_handle = (uint32_t) mp_obj_get_int(p_args[2]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_download_img_direct_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'download_img_direct'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2download_img_directResponseData_t data;
} resp_download_img_direct_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_download_img_direct_fp_t class_data;
} resp_download_img_direct_class_obj_t;

STATIC mp_obj_t resp_download_img_direct_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_download_img_direct_class_obj_t *p_self = m_new_obj(resp_download_img_direct_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_download_img_direct_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_download_img_direct_fp_t *p_data = (resp_download_img_direct_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "download_img_direct" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_download_img_direct_get_err(mp_obj_t self_in) 
{
    const resp_download_img_direct_class_obj_t *p_resp_data = ((resp_download_img_direct_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tErr);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_download_img_direct_get_err_obj, resp_download_img_direct_get_err);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_download_img_direct_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_err), MP_ROM_PTR(&resp_download_img_direct_get_err_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_download_img_direct_locals_dict, resp_download_img_direct_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2download_img_directResponseData,
    MP_QSTR_resp_download_img_direct,
    MP_TYPE_FLAG_NONE,
    make_new, resp_download_img_direct_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_download_img_direct_locals_dict    
);

// uPy request function for method 'download_img_direct_status'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_download_img_direct_status_fp_t;

STATIC mp_obj_t req_download_img_direct_status(void)
{

    // allocate memory on the MicroPython heap
    req_download_img_direct_status_fp_t * p_req_data = m_malloc(sizeof(req_download_img_direct_status_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'download_img_direct_status' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 21;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_download_img_direct_status_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'download_img_direct_status'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2download_img_direct_statusResponseData_t data;
} resp_download_img_direct_status_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_download_img_direct_status_fp_t class_data;
} resp_download_img_direct_status_class_obj_t;

STATIC mp_obj_t resp_download_img_direct_status_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_download_img_direct_status_class_obj_t *p_self = m_new_obj(resp_download_img_direct_status_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_download_img_direct_status_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_download_img_direct_status_fp_t *p_data = (resp_download_img_direct_status_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "download_img_direct_status" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_download_img_direct_status_get_err(mp_obj_t self_in) 
{
    const resp_download_img_direct_status_class_obj_t *p_resp_data = ((resp_download_img_direct_status_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tErr);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_download_img_direct_status_get_err_obj, resp_download_img_direct_status_get_err);

STATIC mp_obj_t resp_download_img_direct_status_get_file_name(mp_obj_t self_in) 
{
    const resp_download_img_direct_status_class_obj_t *p_resp_data = ((resp_download_img_direct_status_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return FName_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_FName_t), (const uint8_t *) &p_resp_data->class_data.data.sFile_name));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_download_img_direct_status_get_file_name_obj, resp_download_img_direct_status_get_file_name);

STATIC mp_obj_t resp_download_img_direct_status_get_status(mp_obj_t self_in) 
{
    const resp_download_img_direct_status_class_obj_t *p_resp_data = ((resp_download_img_direct_status_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return TctlmCubeComputerCommon3_ImageTransferStatus_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_TctlmCubeComputerCommon3_ImageTransferStatus_t), (const uint8_t *) &p_resp_data->class_data.data.sStatus));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_download_img_direct_status_get_status_obj, resp_download_img_direct_status_get_status);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_download_img_direct_status_locals_dict_table[3] = {
    { MP_ROM_QSTR(MP_QSTR_get_err), MP_ROM_PTR(&resp_download_img_direct_status_get_err_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_file_name), MP_ROM_PTR(&resp_download_img_direct_status_get_file_name_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_download_img_direct_status_get_status_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_download_img_direct_status_locals_dict, resp_download_img_direct_status_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2download_img_direct_statusResponseData,
    MP_QSTR_resp_download_img_direct_status,
    MP_TYPE_FLAG_NONE,
    make_new, resp_download_img_direct_status_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_download_img_direct_status_locals_dict    
);

// uPy request function for method 'get_fdir_persistent_errors'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_get_fdir_persistent_errors_fp_t;

STATIC mp_obj_t req_get_fdir_persistent_errors(void)
{

    // allocate memory on the MicroPython heap
    req_get_fdir_persistent_errors_fp_t * p_req_data = m_malloc(sizeof(req_get_fdir_persistent_errors_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'get_fdir_persistent_errors' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 24;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_get_fdir_persistent_errors_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'get_fdir_persistent_errors'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2get_fdir_persistent_errorsResponseData_t data;
} resp_get_fdir_persistent_errors_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_get_fdir_persistent_errors_fp_t class_data;
} resp_get_fdir_persistent_errors_class_obj_t;

STATIC mp_obj_t resp_get_fdir_persistent_errors_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_get_fdir_persistent_errors_class_obj_t *p_self = m_new_obj(resp_get_fdir_persistent_errors_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_get_fdir_persistent_errors_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_get_fdir_persistent_errors_fp_t *p_data = (resp_get_fdir_persistent_errors_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "get_fdir_persistent_errors" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_get_fdir_persistent_errors_get_errors(mp_obj_t self_in) 
{
    const resp_get_fdir_persistent_errors_class_obj_t *p_resp_data = ((resp_get_fdir_persistent_errors_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.u32Errors);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_fdir_persistent_errors_get_errors_obj, resp_get_fdir_persistent_errors_get_errors);

STATIC mp_obj_t resp_get_fdir_persistent_errors_get_op_result(mp_obj_t self_in) 
{
    const resp_get_fdir_persistent_errors_class_obj_t *p_resp_data = ((resp_get_fdir_persistent_errors_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_fdir_persistent_errors_get_op_result_obj, resp_get_fdir_persistent_errors_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_get_fdir_persistent_errors_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_errors), MP_ROM_PTR(&resp_get_fdir_persistent_errors_get_errors_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_get_fdir_persistent_errors_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_get_fdir_persistent_errors_locals_dict, resp_get_fdir_persistent_errors_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2get_fdir_persistent_errorsResponseData,
    MP_QSTR_resp_get_fdir_persistent_errors,
    MP_TYPE_FLAG_NONE,
    make_new, resp_get_fdir_persistent_errors_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_get_fdir_persistent_errors_locals_dict    
);

// uPy request function for method 'clear_fdir_persistent_errors'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_clear_fdir_persistent_errors_fp_t;

STATIC mp_obj_t req_clear_fdir_persistent_errors(void)
{

    // allocate memory on the MicroPython heap
    req_clear_fdir_persistent_errors_fp_t * p_req_data = m_malloc(sizeof(req_clear_fdir_persistent_errors_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'clear_fdir_persistent_errors' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 25;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_clear_fdir_persistent_errors_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'clear_fdir_persistent_errors'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2clear_fdir_persistent_errorsResponseData_t data;
} resp_clear_fdir_persistent_errors_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_clear_fdir_persistent_errors_fp_t class_data;
} resp_clear_fdir_persistent_errors_class_obj_t;

STATIC mp_obj_t resp_clear_fdir_persistent_errors_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_clear_fdir_persistent_errors_class_obj_t *p_self = m_new_obj(resp_clear_fdir_persistent_errors_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_clear_fdir_persistent_errors_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_clear_fdir_persistent_errors_fp_t *p_data = (resp_clear_fdir_persistent_errors_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "clear_fdir_persistent_errors" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_clear_fdir_persistent_errors_get_op_result(mp_obj_t self_in) 
{
    const resp_clear_fdir_persistent_errors_class_obj_t *p_resp_data = ((resp_clear_fdir_persistent_errors_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_clear_fdir_persistent_errors_get_op_result_obj, resp_clear_fdir_persistent_errors_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_clear_fdir_persistent_errors_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_clear_fdir_persistent_errors_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_clear_fdir_persistent_errors_locals_dict, resp_clear_fdir_persistent_errors_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2clear_fdir_persistent_errorsResponseData,
    MP_QSTR_resp_clear_fdir_persistent_errors,
    MP_TYPE_FLAG_NONE,
    make_new, resp_clear_fdir_persistent_errors_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_clear_fdir_persistent_errors_locals_dict    
);

// uPy request function for method 'get_fdir_stats'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_get_fdir_stats_fp_t;

STATIC mp_obj_t req_get_fdir_stats(void)
{

    // allocate memory on the MicroPython heap
    req_get_fdir_stats_fp_t * p_req_data = m_malloc(sizeof(req_get_fdir_stats_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'get_fdir_stats' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 26;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_get_fdir_stats_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'get_fdir_stats'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2get_fdir_statsResponseData_t data;
} resp_get_fdir_stats_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_get_fdir_stats_fp_t class_data;
} resp_get_fdir_stats_class_obj_t;

STATIC mp_obj_t resp_get_fdir_stats_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_get_fdir_stats_class_obj_t *p_self = m_new_obj(resp_get_fdir_stats_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_get_fdir_stats_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_get_fdir_stats_fp_t *p_data = (resp_get_fdir_stats_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "get_fdir_stats" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_get_fdir_stats_get_fdir_logic(mp_obj_t self_in) 
{
    const resp_get_fdir_stats_class_obj_t *p_resp_data = ((resp_get_fdir_stats_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return upy_sd_copy_fidl_scalar_array_to_py_list_OBC_CUBEADCS_GEN2_fdir_stat_t(p_resp_data->class_data.data.asFdir_logic, 15);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_fdir_stats_get_fdir_logic_obj, resp_get_fdir_stats_get_fdir_logic);

STATIC mp_obj_t resp_get_fdir_stats_get_op_result(mp_obj_t self_in) 
{
    const resp_get_fdir_stats_class_obj_t *p_resp_data = ((resp_get_fdir_stats_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_fdir_stats_get_op_result_obj, resp_get_fdir_stats_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_get_fdir_stats_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_fdir_logic), MP_ROM_PTR(&resp_get_fdir_stats_get_fdir_logic_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_get_fdir_stats_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_get_fdir_stats_locals_dict, resp_get_fdir_stats_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2get_fdir_statsResponseData,
    MP_QSTR_resp_get_fdir_stats,
    MP_TYPE_FLAG_NONE,
    make_new, resp_get_fdir_stats_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_get_fdir_stats_locals_dict    
);

// uPy request function for method 'clear_fdir_stats'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_clear_fdir_stats_fp_t;

STATIC mp_obj_t req_clear_fdir_stats(void)
{

    // allocate memory on the MicroPython heap
    req_clear_fdir_stats_fp_t * p_req_data = m_malloc(sizeof(req_clear_fdir_stats_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'clear_fdir_stats' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 27;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_clear_fdir_stats_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'clear_fdir_stats'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2clear_fdir_statsResponseData_t data;
} resp_clear_fdir_stats_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_clear_fdir_stats_fp_t class_data;
} resp_clear_fdir_stats_class_obj_t;

STATIC mp_obj_t resp_clear_fdir_stats_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_clear_fdir_stats_class_obj_t *p_self = m_new_obj(resp_clear_fdir_stats_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_clear_fdir_stats_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_clear_fdir_stats_fp_t *p_data = (resp_clear_fdir_stats_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "clear_fdir_stats" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_clear_fdir_stats_get_op_result(mp_obj_t self_in) 
{
    const resp_clear_fdir_stats_class_obj_t *p_resp_data = ((resp_clear_fdir_stats_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_clear_fdir_stats_get_op_result_obj, resp_clear_fdir_stats_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_clear_fdir_stats_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_clear_fdir_stats_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_clear_fdir_stats_locals_dict, resp_clear_fdir_stats_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2clear_fdir_statsResponseData,
    MP_QSTR_resp_clear_fdir_stats,
    MP_TYPE_FLAG_NONE,
    make_new, resp_clear_fdir_stats_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_clear_fdir_stats_locals_dict    
);

// uPy request function for method 'get_commissioning_status'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_get_commissioning_status_fp_t;

STATIC mp_obj_t req_get_commissioning_status(void)
{

    // allocate memory on the MicroPython heap
    req_get_commissioning_status_fp_t * p_req_data = m_malloc(sizeof(req_get_commissioning_status_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'get_commissioning_status' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 28;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_get_commissioning_status_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'get_commissioning_status'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2get_commissioning_statusResponseData_t data;
} resp_get_commissioning_status_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_get_commissioning_status_fp_t class_data;
} resp_get_commissioning_status_class_obj_t;

STATIC mp_obj_t resp_get_commissioning_status_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_get_commissioning_status_class_obj_t *p_self = m_new_obj(resp_get_commissioning_status_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_get_commissioning_status_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_get_commissioning_status_fp_t *p_data = (resp_get_commissioning_status_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "get_commissioning_status" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_get_commissioning_status_get_status(mp_obj_t self_in) 
{
    const resp_get_commissioning_status_class_obj_t *p_resp_data = ((resp_get_commissioning_status_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eStatus);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_commissioning_status_get_status_obj, resp_get_commissioning_status_get_status);

STATIC mp_obj_t resp_get_commissioning_status_get_opResult(mp_obj_t self_in) 
{
    const resp_get_commissioning_status_class_obj_t *p_resp_data = ((resp_get_commissioning_status_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOpResult);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_commissioning_status_get_opResult_obj, resp_get_commissioning_status_get_opResult);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_get_commissioning_status_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_get_commissioning_status_get_status_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_opResult), MP_ROM_PTR(&resp_get_commissioning_status_get_opResult_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_get_commissioning_status_locals_dict, resp_get_commissioning_status_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2get_commissioning_statusResponseData,
    MP_QSTR_resp_get_commissioning_status,
    MP_TYPE_FLAG_NONE,
    make_new, resp_get_commissioning_status_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_get_commissioning_status_locals_dict    
);

// uPy request function for method 'set_commissioning_status'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2set_commissioning_statusRequestData_t data;
} req_set_commissioning_status_fp_t;

STATIC mp_obj_t req_set_commissioning_status(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_set_commissioning_status_fp_t * p_req_data = m_malloc(sizeof(req_set_commissioning_status_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'set_commissioning_status' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 29;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eStatus = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_set_commissioning_status_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'set_commissioning_status'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2set_commissioning_statusResponseData_t data;
} resp_set_commissioning_status_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_set_commissioning_status_fp_t class_data;
} resp_set_commissioning_status_class_obj_t;

STATIC mp_obj_t resp_set_commissioning_status_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_set_commissioning_status_class_obj_t *p_self = m_new_obj(resp_set_commissioning_status_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_set_commissioning_status_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_set_commissioning_status_fp_t *p_data = (resp_set_commissioning_status_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "set_commissioning_status" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_set_commissioning_status_get_opResult(mp_obj_t self_in) 
{
    const resp_set_commissioning_status_class_obj_t *p_resp_data = ((resp_set_commissioning_status_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOpResult);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_set_commissioning_status_get_opResult_obj, resp_set_commissioning_status_get_opResult);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_set_commissioning_status_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_opResult), MP_ROM_PTR(&resp_set_commissioning_status_get_opResult_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_set_commissioning_status_locals_dict, resp_set_commissioning_status_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2set_commissioning_statusResponseData,
    MP_QSTR_resp_set_commissioning_status,
    MP_TYPE_FLAG_NONE,
    make_new, resp_set_commissioning_status_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_set_commissioning_status_locals_dict    
);

// uPy request function for method 'get_tlm_cfg'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_get_tlm_cfg_fp_t;

STATIC mp_obj_t req_get_tlm_cfg(void)
{

    // allocate memory on the MicroPython heap
    req_get_tlm_cfg_fp_t * p_req_data = m_malloc(sizeof(req_get_tlm_cfg_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'get_tlm_cfg' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 30;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_get_tlm_cfg_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'get_tlm_cfg'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2get_tlm_cfgResponseData_t data;
} resp_get_tlm_cfg_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_get_tlm_cfg_fp_t class_data;
} resp_get_tlm_cfg_class_obj_t;

STATIC mp_obj_t resp_get_tlm_cfg_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_get_tlm_cfg_class_obj_t *p_self = m_new_obj(resp_get_tlm_cfg_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_get_tlm_cfg_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_get_tlm_cfg_fp_t *p_data = (resp_get_tlm_cfg_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "get_tlm_cfg" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_get_tlm_cfg_get_mask_0(mp_obj_t self_in) 
{
    const resp_get_tlm_cfg_class_obj_t *p_resp_data = ((resp_get_tlm_cfg_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return telemetry_mask_0_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_telemetry_mask_0_t), (const uint8_t *) &p_resp_data->class_data.data.sMask_0));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_tlm_cfg_get_mask_0_obj, resp_get_tlm_cfg_get_mask_0);

STATIC mp_obj_t resp_get_tlm_cfg_get_mask_1(mp_obj_t self_in) 
{
    const resp_get_tlm_cfg_class_obj_t *p_resp_data = ((resp_get_tlm_cfg_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return telemetry_mask_1_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_telemetry_mask_1_t), (const uint8_t *) &p_resp_data->class_data.data.sMask_1));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_tlm_cfg_get_mask_1_obj, resp_get_tlm_cfg_get_mask_1);

STATIC mp_obj_t resp_get_tlm_cfg_get_mask_2(mp_obj_t self_in) 
{
    const resp_get_tlm_cfg_class_obj_t *p_resp_data = ((resp_get_tlm_cfg_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return telemetry_mask_2_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_telemetry_mask_2_t), (const uint8_t *) &p_resp_data->class_data.data.sMask_2));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_tlm_cfg_get_mask_2_obj, resp_get_tlm_cfg_get_mask_2);

STATIC mp_obj_t resp_get_tlm_cfg_get_mask_3(mp_obj_t self_in) 
{
    const resp_get_tlm_cfg_class_obj_t *p_resp_data = ((resp_get_tlm_cfg_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return telemetry_mask_3_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_telemetry_mask_3_t), (const uint8_t *) &p_resp_data->class_data.data.sMask_3));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_tlm_cfg_get_mask_3_obj, resp_get_tlm_cfg_get_mask_3);

STATIC mp_obj_t resp_get_tlm_cfg_get_mask_4(mp_obj_t self_in) 
{
    const resp_get_tlm_cfg_class_obj_t *p_resp_data = ((resp_get_tlm_cfg_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return telemetry_mask_4_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_telemetry_mask_4_t), (const uint8_t *) &p_resp_data->class_data.data.sMask_4));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_tlm_cfg_get_mask_4_obj, resp_get_tlm_cfg_get_mask_4);

STATIC mp_obj_t resp_get_tlm_cfg_get_op_result(mp_obj_t self_in) 
{
    const resp_get_tlm_cfg_class_obj_t *p_resp_data = ((resp_get_tlm_cfg_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_tlm_cfg_get_op_result_obj, resp_get_tlm_cfg_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_get_tlm_cfg_locals_dict_table[6] = {
    { MP_ROM_QSTR(MP_QSTR_get_mask_0), MP_ROM_PTR(&resp_get_tlm_cfg_get_mask_0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_mask_1), MP_ROM_PTR(&resp_get_tlm_cfg_get_mask_1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_mask_2), MP_ROM_PTR(&resp_get_tlm_cfg_get_mask_2_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_mask_3), MP_ROM_PTR(&resp_get_tlm_cfg_get_mask_3_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_mask_4), MP_ROM_PTR(&resp_get_tlm_cfg_get_mask_4_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_get_tlm_cfg_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_get_tlm_cfg_locals_dict, resp_get_tlm_cfg_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2get_tlm_cfgResponseData,
    MP_QSTR_resp_get_tlm_cfg,
    MP_TYPE_FLAG_NONE,
    make_new, resp_get_tlm_cfg_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_get_tlm_cfg_locals_dict    
);

// uPy request function for method 'set_tlm_cfg'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2set_tlm_cfgRequestData_t data;
} req_set_tlm_cfg_fp_t;

STATIC mp_obj_t req_set_tlm_cfg(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 5)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 5 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_set_tlm_cfg_fp_t * p_req_data = m_malloc(sizeof(req_set_tlm_cfg_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'set_tlm_cfg' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 31;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.sMask_0 = ((telemetry_mask_0_class_obj_t *) MP_OBJ_TO_PTR(p_args[0]))->class_data;
    p_req_data->data.sMask_1 = ((telemetry_mask_1_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    p_req_data->data.sMask_2 = ((telemetry_mask_2_class_obj_t *) MP_OBJ_TO_PTR(p_args[2]))->class_data;
    p_req_data->data.sMask_3 = ((telemetry_mask_3_class_obj_t *) MP_OBJ_TO_PTR(p_args[3]))->class_data;
    p_req_data->data.sMask_4 = ((telemetry_mask_4_class_obj_t *) MP_OBJ_TO_PTR(p_args[4]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_set_tlm_cfg_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'set_tlm_cfg'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2set_tlm_cfgResponseData_t data;
} resp_set_tlm_cfg_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_set_tlm_cfg_fp_t class_data;
} resp_set_tlm_cfg_class_obj_t;

STATIC mp_obj_t resp_set_tlm_cfg_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_set_tlm_cfg_class_obj_t *p_self = m_new_obj(resp_set_tlm_cfg_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_set_tlm_cfg_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_set_tlm_cfg_fp_t *p_data = (resp_set_tlm_cfg_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "set_tlm_cfg" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_set_tlm_cfg_get_op_result(mp_obj_t self_in) 
{
    const resp_set_tlm_cfg_class_obj_t *p_resp_data = ((resp_set_tlm_cfg_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_set_tlm_cfg_get_op_result_obj, resp_set_tlm_cfg_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_set_tlm_cfg_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_set_tlm_cfg_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_set_tlm_cfg_locals_dict, resp_set_tlm_cfg_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2set_tlm_cfgResponseData,
    MP_QSTR_resp_set_tlm_cfg,
    MP_TYPE_FLAG_NONE,
    make_new, resp_set_tlm_cfg_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_set_tlm_cfg_locals_dict    
);

// uPy request function for method 'get_nvm_system_states_cfg'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2get_nvm_system_states_cfgRequestData_t data;
} req_get_nvm_system_states_cfg_fp_t;

STATIC mp_obj_t req_get_nvm_system_states_cfg(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_get_nvm_system_states_cfg_fp_t * p_req_data = m_malloc(sizeof(req_get_nvm_system_states_cfg_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'get_nvm_system_states_cfg' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 32;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eSys_state_to_get = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_get_nvm_system_states_cfg_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'get_nvm_system_states_cfg'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2get_nvm_system_states_cfgResponseData_t data;
} resp_get_nvm_system_states_cfg_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_get_nvm_system_states_cfg_fp_t class_data;
} resp_get_nvm_system_states_cfg_class_obj_t;

STATIC mp_obj_t resp_get_nvm_system_states_cfg_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_get_nvm_system_states_cfg_class_obj_t *p_self = m_new_obj(resp_get_nvm_system_states_cfg_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_get_nvm_system_states_cfg_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_get_nvm_system_states_cfg_fp_t *p_data = (resp_get_nvm_system_states_cfg_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "get_nvm_system_states_cfg" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_get_nvm_system_states_cfg_get_sys_states_cfg(mp_obj_t self_in) 
{
    const resp_get_nvm_system_states_cfg_class_obj_t *p_resp_data = ((resp_get_nvm_system_states_cfg_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return state_change_core_args_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_state_change_core_args_t), (const uint8_t *) &p_resp_data->class_data.data.sSys_states_cfg));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_nvm_system_states_cfg_get_sys_states_cfg_obj, resp_get_nvm_system_states_cfg_get_sys_states_cfg);

STATIC mp_obj_t resp_get_nvm_system_states_cfg_get_op_result(mp_obj_t self_in) 
{
    const resp_get_nvm_system_states_cfg_class_obj_t *p_resp_data = ((resp_get_nvm_system_states_cfg_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_nvm_system_states_cfg_get_op_result_obj, resp_get_nvm_system_states_cfg_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_get_nvm_system_states_cfg_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_sys_states_cfg), MP_ROM_PTR(&resp_get_nvm_system_states_cfg_get_sys_states_cfg_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_get_nvm_system_states_cfg_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_get_nvm_system_states_cfg_locals_dict, resp_get_nvm_system_states_cfg_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2get_nvm_system_states_cfgResponseData,
    MP_QSTR_resp_get_nvm_system_states_cfg,
    MP_TYPE_FLAG_NONE,
    make_new, resp_get_nvm_system_states_cfg_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_get_nvm_system_states_cfg_locals_dict    
);

// uPy request function for method 'set_nvm_system_states_cfg'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2set_nvm_system_states_cfgRequestData_t data;
} req_set_nvm_system_states_cfg_fp_t;

STATIC mp_obj_t req_set_nvm_system_states_cfg(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_set_nvm_system_states_cfg_fp_t * p_req_data = m_malloc(sizeof(req_set_nvm_system_states_cfg_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'set_nvm_system_states_cfg' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 33;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.sSys_states_cfg = ((state_change_core_args_class_obj_t *) MP_OBJ_TO_PTR(p_args[0]))->class_data;
    p_req_data->data.eSys_state_to_set = (uint8_t) mp_obj_get_int(p_args[1]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_set_nvm_system_states_cfg_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'set_nvm_system_states_cfg'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2set_nvm_system_states_cfgResponseData_t data;
} resp_set_nvm_system_states_cfg_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_set_nvm_system_states_cfg_fp_t class_data;
} resp_set_nvm_system_states_cfg_class_obj_t;

STATIC mp_obj_t resp_set_nvm_system_states_cfg_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_set_nvm_system_states_cfg_class_obj_t *p_self = m_new_obj(resp_set_nvm_system_states_cfg_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_set_nvm_system_states_cfg_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_set_nvm_system_states_cfg_fp_t *p_data = (resp_set_nvm_system_states_cfg_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "set_nvm_system_states_cfg" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_set_nvm_system_states_cfg_get_op_result(mp_obj_t self_in) 
{
    const resp_set_nvm_system_states_cfg_class_obj_t *p_resp_data = ((resp_set_nvm_system_states_cfg_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_set_nvm_system_states_cfg_get_op_result_obj, resp_set_nvm_system_states_cfg_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_set_nvm_system_states_cfg_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_set_nvm_system_states_cfg_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_set_nvm_system_states_cfg_locals_dict, resp_set_nvm_system_states_cfg_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2set_nvm_system_states_cfgResponseData,
    MP_QSTR_resp_set_nvm_system_states_cfg,
    MP_TYPE_FLAG_NONE,
    make_new, resp_set_nvm_system_states_cfg_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_set_nvm_system_states_cfg_locals_dict    
);

// uPy request function for method 'fw_update_cube_computer'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2fw_update_cube_computerRequestData_t data;
} req_fw_update_cube_computer_fp_t;

STATIC mp_obj_t req_fw_update_cube_computer(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 3)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 3 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_fw_update_cube_computer_fp_t * p_req_data = m_malloc(sizeof(req_fw_update_cube_computer_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'fw_update_cube_computer' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 34;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.sControl_program_file_name = ((FName_class_obj_t *) MP_OBJ_TO_PTR(p_args[0]))->class_data;
    p_req_data->data.sConfiguration_file_name = ((FName_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    p_req_data->data.bForce = (bool) mp_obj_get_int(p_args[2]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_fw_update_cube_computer_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'fw_update_cube_computer'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2fw_update_cube_computerResponseData_t data;
} resp_fw_update_cube_computer_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_fw_update_cube_computer_fp_t class_data;
} resp_fw_update_cube_computer_class_obj_t;

STATIC mp_obj_t resp_fw_update_cube_computer_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_fw_update_cube_computer_class_obj_t *p_self = m_new_obj(resp_fw_update_cube_computer_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_fw_update_cube_computer_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_fw_update_cube_computer_fp_t *p_data = (resp_fw_update_cube_computer_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "fw_update_cube_computer" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_fw_update_cube_computer_get_err(mp_obj_t self_in) 
{
    const resp_fw_update_cube_computer_class_obj_t *p_resp_data = ((resp_fw_update_cube_computer_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tErr);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_fw_update_cube_computer_get_err_obj, resp_fw_update_cube_computer_get_err);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_fw_update_cube_computer_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_err), MP_ROM_PTR(&resp_fw_update_cube_computer_get_err_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_fw_update_cube_computer_locals_dict, resp_fw_update_cube_computer_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2fw_update_cube_computerResponseData,
    MP_QSTR_resp_fw_update_cube_computer,
    MP_TYPE_FLAG_NONE,
    make_new, resp_fw_update_cube_computer_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_fw_update_cube_computer_locals_dict    
);

// uPy request function for method 'fw_update_cube_computer_status'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_fw_update_cube_computer_status_fp_t;

STATIC mp_obj_t req_fw_update_cube_computer_status(void)
{

    // allocate memory on the MicroPython heap
    req_fw_update_cube_computer_status_fp_t * p_req_data = m_malloc(sizeof(req_fw_update_cube_computer_status_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'fw_update_cube_computer_status' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 35;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_fw_update_cube_computer_status_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'fw_update_cube_computer_status'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2fw_update_cube_computer_statusResponseData_t data;
} resp_fw_update_cube_computer_status_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_fw_update_cube_computer_status_fp_t class_data;
} resp_fw_update_cube_computer_status_class_obj_t;

STATIC mp_obj_t resp_fw_update_cube_computer_status_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_fw_update_cube_computer_status_class_obj_t *p_self = m_new_obj(resp_fw_update_cube_computer_status_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_fw_update_cube_computer_status_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_fw_update_cube_computer_status_fp_t *p_data = (resp_fw_update_cube_computer_status_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "fw_update_cube_computer_status" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_fw_update_cube_computer_status_get_err(mp_obj_t self_in) 
{
    const resp_fw_update_cube_computer_status_class_obj_t *p_resp_data = ((resp_fw_update_cube_computer_status_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tErr);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_fw_update_cube_computer_status_get_err_obj, resp_fw_update_cube_computer_status_get_err);

STATIC mp_obj_t resp_fw_update_cube_computer_status_get_status(mp_obj_t self_in) 
{
    const resp_fw_update_cube_computer_status_class_obj_t *p_resp_data = ((resp_fw_update_cube_computer_status_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return cube_computer_fw_update_status_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_cube_computer_fw_update_status_t), (const uint8_t *) &p_resp_data->class_data.data.sStatus));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_fw_update_cube_computer_status_get_status_obj, resp_fw_update_cube_computer_status_get_status);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_fw_update_cube_computer_status_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_err), MP_ROM_PTR(&resp_fw_update_cube_computer_status_get_err_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_fw_update_cube_computer_status_get_status_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_fw_update_cube_computer_status_locals_dict, resp_fw_update_cube_computer_status_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2fw_update_cube_computer_statusResponseData,
    MP_QSTR_resp_fw_update_cube_computer_status,
    MP_TYPE_FLAG_NONE,
    make_new, resp_fw_update_cube_computer_status_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_fw_update_cube_computer_status_locals_dict    
);

// uPy request function for method 'fw_update_cube_node'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2fw_update_cube_nodeRequestData_t data;
} req_fw_update_cube_node_fp_t;

STATIC mp_obj_t req_fw_update_cube_node(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 5)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 5 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_fw_update_cube_node_fp_t * p_req_data = m_malloc(sizeof(req_fw_update_cube_node_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'fw_update_cube_node' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 36;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.sControl_program_file_name = ((FName_class_obj_t *) MP_OBJ_TO_PTR(p_args[0]))->class_data;
    p_req_data->data.sConfiguration_file_name = ((FName_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    p_req_data->data.bForce = (bool) mp_obj_get_int(p_args[2]);
    p_req_data->data.eNode_type = (uint8_t) mp_obj_get_int(p_args[3]);
    p_req_data->data.u32Serial_int = (uint32_t) mp_obj_get_int(p_args[4]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_fw_update_cube_node_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'fw_update_cube_node'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2fw_update_cube_nodeResponseData_t data;
} resp_fw_update_cube_node_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_fw_update_cube_node_fp_t class_data;
} resp_fw_update_cube_node_class_obj_t;

STATIC mp_obj_t resp_fw_update_cube_node_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_fw_update_cube_node_class_obj_t *p_self = m_new_obj(resp_fw_update_cube_node_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_fw_update_cube_node_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_fw_update_cube_node_fp_t *p_data = (resp_fw_update_cube_node_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "fw_update_cube_node" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_fw_update_cube_node_get_err(mp_obj_t self_in) 
{
    const resp_fw_update_cube_node_class_obj_t *p_resp_data = ((resp_fw_update_cube_node_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tErr);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_fw_update_cube_node_get_err_obj, resp_fw_update_cube_node_get_err);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_fw_update_cube_node_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_err), MP_ROM_PTR(&resp_fw_update_cube_node_get_err_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_fw_update_cube_node_locals_dict, resp_fw_update_cube_node_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2fw_update_cube_nodeResponseData,
    MP_QSTR_resp_fw_update_cube_node,
    MP_TYPE_FLAG_NONE,
    make_new, resp_fw_update_cube_node_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_fw_update_cube_node_locals_dict    
);

// uPy request function for method 'fw_update_cube_node_status'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_fw_update_cube_node_status_fp_t;

STATIC mp_obj_t req_fw_update_cube_node_status(void)
{

    // allocate memory on the MicroPython heap
    req_fw_update_cube_node_status_fp_t * p_req_data = m_malloc(sizeof(req_fw_update_cube_node_status_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'fw_update_cube_node_status' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 33;
    p_req_data->fp_hdr.func_id = 37;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_fw_update_cube_node_status_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'fw_update_cube_node_status'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    OBC_CUBEADCS_GEN2fw_update_cube_node_statusResponseData_t data;
} resp_fw_update_cube_node_status_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_fw_update_cube_node_status_fp_t class_data;
} resp_fw_update_cube_node_status_class_obj_t;

STATIC mp_obj_t resp_fw_update_cube_node_status_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_fw_update_cube_node_status_class_obj_t *p_self = m_new_obj(resp_fw_update_cube_node_status_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_fw_update_cube_node_status_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_fw_update_cube_node_status_fp_t *p_data = (resp_fw_update_cube_node_status_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "fw_update_cube_node_status" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_fw_update_cube_node_status_get_err(mp_obj_t self_in) 
{
    const resp_fw_update_cube_node_status_class_obj_t *p_resp_data = ((resp_fw_update_cube_node_status_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tErr);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_fw_update_cube_node_status_get_err_obj, resp_fw_update_cube_node_status_get_err);

STATIC mp_obj_t resp_fw_update_cube_node_status_get_status(mp_obj_t self_in) 
{
    const resp_fw_update_cube_node_status_class_obj_t *p_resp_data = ((resp_fw_update_cube_node_status_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return cube_node_fw_update_status_make_from_buf(mp_obj_new_bytearray(sizeof(OBC_CUBEADCS_GEN2_cube_node_fw_update_status_t), (const uint8_t *) &p_resp_data->class_data.data.sStatus));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_fw_update_cube_node_status_get_status_obj, resp_fw_update_cube_node_status_get_status);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_fw_update_cube_node_status_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_err), MP_ROM_PTR(&resp_fw_update_cube_node_status_get_err_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_fw_update_cube_node_status_get_status_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_fw_update_cube_node_status_locals_dict, resp_fw_update_cube_node_status_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_OBC_CUBEADCS_GEN2fw_update_cube_node_statusResponseData,
    MP_QSTR_resp_fw_update_cube_node_status,
    MP_TYPE_FLAG_NONE,
    make_new, resp_fw_update_cube_node_status_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_fw_update_cube_node_status_locals_dict    
);


/**********************************************************************
 *
 *  uPy function reference definitions
 *
 **********************************************************************/
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_reqStateMachineStateChange_obj, 2, req_reqStateMachineStateChange);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_getStateMachineState_obj, req_getStateMachineState);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_getOpStatus_obj, req_getOpStatus);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_reqSoftResetAndMode_obj, 1, req_reqSoftResetAndMode);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_get_events_since_last_power_up_obj, req_get_events_since_last_power_up);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_clear_events_since_last_power_up_obj, req_clear_events_since_last_power_up);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_download_evt_obj, 2, req_download_evt);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_download_evt_status_obj, req_download_evt_status);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_download_tlm_obj, 2, req_download_tlm);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_download_tlm_status_obj, req_download_tlm_status);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_download_img_direct_obj, 3, req_download_img_direct);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_download_img_direct_status_obj, req_download_img_direct_status);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_get_fdir_persistent_errors_obj, req_get_fdir_persistent_errors);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_clear_fdir_persistent_errors_obj, req_clear_fdir_persistent_errors);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_get_fdir_stats_obj, req_get_fdir_stats);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_clear_fdir_stats_obj, req_clear_fdir_stats);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_get_commissioning_status_obj, req_get_commissioning_status);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_set_commissioning_status_obj, 1, req_set_commissioning_status);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_get_tlm_cfg_obj, req_get_tlm_cfg);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_set_tlm_cfg_obj, 5, req_set_tlm_cfg);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_get_nvm_system_states_cfg_obj, 1, req_get_nvm_system_states_cfg);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_set_nvm_system_states_cfg_obj, 2, req_set_nvm_system_states_cfg);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_fw_update_cube_computer_obj, 3, req_fw_update_cube_computer);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_fw_update_cube_computer_status_obj, req_fw_update_cube_computer_status);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_fw_update_cube_node_obj, 5, req_fw_update_cube_node);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_fw_update_cube_node_status_obj, req_fw_update_cube_node_status);

STATIC const mp_rom_map_elem_t upy_obc_cubeadcs_gen2_module_globals_table[134] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_upy_obc_cubeadcs_gen2) },
    // export FIDL methods
    // export request serializer function for method 'reqStateMachineStateChange'
    { MP_ROM_QSTR(MP_QSTR_req_reqStateMachineStateChange), MP_ROM_PTR(&req_reqStateMachineStateChange_obj) },
    // export class for method 'reqStateMachineStateChange' response
    { MP_ROM_QSTR(MP_QSTR_resp_reqStateMachineStateChange), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2reqStateMachineStateChangeResponseData) },
    // export request serializer function for method 'getStateMachineState'
    { MP_ROM_QSTR(MP_QSTR_req_getStateMachineState), MP_ROM_PTR(&req_getStateMachineState_obj) },
    // export class for method 'getStateMachineState' response
    { MP_ROM_QSTR(MP_QSTR_resp_getStateMachineState), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2getStateMachineStateResponseData) },
    // export request serializer function for method 'getOpStatus'
    { MP_ROM_QSTR(MP_QSTR_req_getOpStatus), MP_ROM_PTR(&req_getOpStatus_obj) },
    // export class for method 'getOpStatus' response
    { MP_ROM_QSTR(MP_QSTR_resp_getOpStatus), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2getOpStatusResponseData) },
    // export request serializer function for method 'reqSoftResetAndMode'
    { MP_ROM_QSTR(MP_QSTR_req_reqSoftResetAndMode), MP_ROM_PTR(&req_reqSoftResetAndMode_obj) },
    // export class for method 'reqSoftResetAndMode' response
    { MP_ROM_QSTR(MP_QSTR_resp_reqSoftResetAndMode), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2reqSoftResetAndModeResponseData) },
    // export request serializer function for method 'get_events_since_last_power_up'
    { MP_ROM_QSTR(MP_QSTR_req_get_events_since_last_power_up), MP_ROM_PTR(&req_get_events_since_last_power_up_obj) },
    // export class for method 'get_events_since_last_power_up' response
    { MP_ROM_QSTR(MP_QSTR_resp_get_events_since_last_power_up), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2get_events_since_last_power_upResponseData) },
    // export request serializer function for method 'clear_events_since_last_power_up'
    { MP_ROM_QSTR(MP_QSTR_req_clear_events_since_last_power_up), MP_ROM_PTR(&req_clear_events_since_last_power_up_obj) },
    // export class for method 'clear_events_since_last_power_up' response
    { MP_ROM_QSTR(MP_QSTR_resp_clear_events_since_last_power_up), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2clear_events_since_last_power_upResponseData) },
    // export request serializer function for method 'download_evt'
    { MP_ROM_QSTR(MP_QSTR_req_download_evt), MP_ROM_PTR(&req_download_evt_obj) },
    // export class for method 'download_evt' response
    { MP_ROM_QSTR(MP_QSTR_resp_download_evt), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2download_evtResponseData) },
    // export request serializer function for method 'download_evt_status'
    { MP_ROM_QSTR(MP_QSTR_req_download_evt_status), MP_ROM_PTR(&req_download_evt_status_obj) },
    // export class for method 'download_evt_status' response
    { MP_ROM_QSTR(MP_QSTR_resp_download_evt_status), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2download_evt_statusResponseData) },
    // export request serializer function for method 'download_tlm'
    { MP_ROM_QSTR(MP_QSTR_req_download_tlm), MP_ROM_PTR(&req_download_tlm_obj) },
    // export class for method 'download_tlm' response
    { MP_ROM_QSTR(MP_QSTR_resp_download_tlm), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2download_tlmResponseData) },
    // export request serializer function for method 'download_tlm_status'
    { MP_ROM_QSTR(MP_QSTR_req_download_tlm_status), MP_ROM_PTR(&req_download_tlm_status_obj) },
    // export class for method 'download_tlm_status' response
    { MP_ROM_QSTR(MP_QSTR_resp_download_tlm_status), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2download_tlm_statusResponseData) },
    // export request serializer function for method 'download_img_direct'
    { MP_ROM_QSTR(MP_QSTR_req_download_img_direct), MP_ROM_PTR(&req_download_img_direct_obj) },
    // export class for method 'download_img_direct' response
    { MP_ROM_QSTR(MP_QSTR_resp_download_img_direct), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2download_img_directResponseData) },
    // export request serializer function for method 'download_img_direct_status'
    { MP_ROM_QSTR(MP_QSTR_req_download_img_direct_status), MP_ROM_PTR(&req_download_img_direct_status_obj) },
    // export class for method 'download_img_direct_status' response
    { MP_ROM_QSTR(MP_QSTR_resp_download_img_direct_status), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2download_img_direct_statusResponseData) },
    // export request serializer function for method 'get_fdir_persistent_errors'
    { MP_ROM_QSTR(MP_QSTR_req_get_fdir_persistent_errors), MP_ROM_PTR(&req_get_fdir_persistent_errors_obj) },
    // export class for method 'get_fdir_persistent_errors' response
    { MP_ROM_QSTR(MP_QSTR_resp_get_fdir_persistent_errors), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2get_fdir_persistent_errorsResponseData) },
    // export request serializer function for method 'clear_fdir_persistent_errors'
    { MP_ROM_QSTR(MP_QSTR_req_clear_fdir_persistent_errors), MP_ROM_PTR(&req_clear_fdir_persistent_errors_obj) },
    // export class for method 'clear_fdir_persistent_errors' response
    { MP_ROM_QSTR(MP_QSTR_resp_clear_fdir_persistent_errors), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2clear_fdir_persistent_errorsResponseData) },
    // export request serializer function for method 'get_fdir_stats'
    { MP_ROM_QSTR(MP_QSTR_req_get_fdir_stats), MP_ROM_PTR(&req_get_fdir_stats_obj) },
    // export class for method 'get_fdir_stats' response
    { MP_ROM_QSTR(MP_QSTR_resp_get_fdir_stats), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2get_fdir_statsResponseData) },
    // export request serializer function for method 'clear_fdir_stats'
    { MP_ROM_QSTR(MP_QSTR_req_clear_fdir_stats), MP_ROM_PTR(&req_clear_fdir_stats_obj) },
    // export class for method 'clear_fdir_stats' response
    { MP_ROM_QSTR(MP_QSTR_resp_clear_fdir_stats), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2clear_fdir_statsResponseData) },
    // export request serializer function for method 'get_commissioning_status'
    { MP_ROM_QSTR(MP_QSTR_req_get_commissioning_status), MP_ROM_PTR(&req_get_commissioning_status_obj) },
    // export class for method 'get_commissioning_status' response
    { MP_ROM_QSTR(MP_QSTR_resp_get_commissioning_status), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2get_commissioning_statusResponseData) },
    // export request serializer function for method 'set_commissioning_status'
    { MP_ROM_QSTR(MP_QSTR_req_set_commissioning_status), MP_ROM_PTR(&req_set_commissioning_status_obj) },
    // export class for method 'set_commissioning_status' response
    { MP_ROM_QSTR(MP_QSTR_resp_set_commissioning_status), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2set_commissioning_statusResponseData) },
    // export request serializer function for method 'get_tlm_cfg'
    { MP_ROM_QSTR(MP_QSTR_req_get_tlm_cfg), MP_ROM_PTR(&req_get_tlm_cfg_obj) },
    // export class for method 'get_tlm_cfg' response
    { MP_ROM_QSTR(MP_QSTR_resp_get_tlm_cfg), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2get_tlm_cfgResponseData) },
    // export request serializer function for method 'set_tlm_cfg'
    { MP_ROM_QSTR(MP_QSTR_req_set_tlm_cfg), MP_ROM_PTR(&req_set_tlm_cfg_obj) },
    // export class for method 'set_tlm_cfg' response
    { MP_ROM_QSTR(MP_QSTR_resp_set_tlm_cfg), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2set_tlm_cfgResponseData) },
    // export request serializer function for method 'get_nvm_system_states_cfg'
    { MP_ROM_QSTR(MP_QSTR_req_get_nvm_system_states_cfg), MP_ROM_PTR(&req_get_nvm_system_states_cfg_obj) },
    // export class for method 'get_nvm_system_states_cfg' response
    { MP_ROM_QSTR(MP_QSTR_resp_get_nvm_system_states_cfg), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2get_nvm_system_states_cfgResponseData) },
    // export request serializer function for method 'set_nvm_system_states_cfg'
    { MP_ROM_QSTR(MP_QSTR_req_set_nvm_system_states_cfg), MP_ROM_PTR(&req_set_nvm_system_states_cfg_obj) },
    // export class for method 'set_nvm_system_states_cfg' response
    { MP_ROM_QSTR(MP_QSTR_resp_set_nvm_system_states_cfg), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2set_nvm_system_states_cfgResponseData) },
    // export request serializer function for method 'fw_update_cube_computer'
    { MP_ROM_QSTR(MP_QSTR_req_fw_update_cube_computer), MP_ROM_PTR(&req_fw_update_cube_computer_obj) },
    // export class for method 'fw_update_cube_computer' response
    { MP_ROM_QSTR(MP_QSTR_resp_fw_update_cube_computer), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2fw_update_cube_computerResponseData) },
    // export request serializer function for method 'fw_update_cube_computer_status'
    { MP_ROM_QSTR(MP_QSTR_req_fw_update_cube_computer_status), MP_ROM_PTR(&req_fw_update_cube_computer_status_obj) },
    // export class for method 'fw_update_cube_computer_status' response
    { MP_ROM_QSTR(MP_QSTR_resp_fw_update_cube_computer_status), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2fw_update_cube_computer_statusResponseData) },
    // export request serializer function for method 'fw_update_cube_node'
    { MP_ROM_QSTR(MP_QSTR_req_fw_update_cube_node), MP_ROM_PTR(&req_fw_update_cube_node_obj) },
    // export class for method 'fw_update_cube_node' response
    { MP_ROM_QSTR(MP_QSTR_resp_fw_update_cube_node), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2fw_update_cube_nodeResponseData) },
    // export request serializer function for method 'fw_update_cube_node_status'
    { MP_ROM_QSTR(MP_QSTR_req_fw_update_cube_node_status), MP_ROM_PTR(&req_fw_update_cube_node_status_obj) },
    // export class for method 'fw_update_cube_node_status' response
    { MP_ROM_QSTR(MP_QSTR_resp_fw_update_cube_node_status), MP_ROM_PTR(&mp_type_OBC_CUBEADCS_GEN2fw_update_cube_node_statusResponseData) },
    // export enumeration class for type 'sys_states'
    { MP_ROM_QSTR(MP_QSTR_sys_states), MP_ROM_PTR(&sys_states_class_type) },                        
    // export enumeration class for type 'TctlmCommonFrameworkEnums_NodeType'
    { MP_ROM_QSTR(MP_QSTR_TctlmCommonFrameworkEnums_NodeType), MP_ROM_PTR(&tctlmcommonframeworkenums_nodetype_class_type) },                        
    // export enumeration class for type 'AbstractImagingNodeType'
    { MP_ROM_QSTR(MP_QSTR_AbstractImagingNodeType), MP_ROM_PTR(&abstractimagingnodetype_class_type) },                        
    // export enumeration class for type 'TctlmCubeComputerControlProgram8_FtpUpgradeState'
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeComputerControlProgram8_FtpUpgradeState), MP_ROM_PTR(&tctlmcubecomputercontrolprogram8_ftpupgradestate_class_type) },                        
    // export enumeration class for type 'AdcsRunMode'
    { MP_ROM_QSTR(MP_QSTR_AdcsRunMode), MP_ROM_PTR(&adcsrunmode_class_type) },                        
    // export enumeration class for type 'events_enum'
    { MP_ROM_QSTR(MP_QSTR_events_enum), MP_ROM_PTR(&events_enum_class_type) },                        
    // export enumeration class for type 'StandardResult'
    { MP_ROM_QSTR(MP_QSTR_StandardResult), MP_ROM_PTR(&standardresult_class_type) },                        
    // export enumeration class for type 'NodePowerState'
    { MP_ROM_QSTR(MP_QSTR_NodePowerState), MP_ROM_PTR(&nodepowerstate_class_type) },                        
    // export enumeration class for type 'TctlmCubeComputerCommon3_EventReadQueueState'
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeComputerCommon3_EventReadQueueState), MP_ROM_PTR(&tctlmcubecomputercommon3_eventreadqueuestate_class_type) },                        
    // export enumeration class for type 'StateMachineEvents'
    { MP_ROM_QSTR(MP_QSTR_StateMachineEvents), MP_ROM_PTR(&statemachineevents_class_type) },                        
    // export enumeration class for type 'TctlmCubeComputerCommon3_ImageTransferState'
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeComputerCommon3_ImageTransferState), MP_ROM_PTR(&tctlmcubecomputercommon3_imagetransferstate_class_type) },                        
    // export enumeration class for type 'EstimationModes'
    { MP_ROM_QSTR(MP_QSTR_EstimationModes), MP_ROM_PTR(&estimationmodes_class_type) },                        
    // export enumeration class for type 'CommissioningStatus'
    { MP_ROM_QSTR(MP_QSTR_CommissioningStatus), MP_ROM_PTR(&commissioningstatus_class_type) },                        
    // export enumeration class for type 'BootState'
    { MP_ROM_QSTR(MP_QSTR_BootState), MP_ROM_PTR(&bootstate_class_type) },                        
    // export enumeration class for type 'TctlmCubeComputerCommon3_TlmLogReadQueueState'
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeComputerCommon3_TlmLogReadQueueState), MP_ROM_PTR(&tctlmcubecomputercommon3_tlmlogreadqueuestate_class_type) },                        
    // export enumeration class for type 'BootResetReason'
    { MP_ROM_QSTR(MP_QSTR_BootResetReason), MP_ROM_PTR(&bootresetreason_class_type) },                        
    // export enumeration class for type 'TctlmCubeComputerControlProgram8_FtpState'
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeComputerControlProgram8_FtpState), MP_ROM_PTR(&tctlmcubecomputercontrolprogram8_ftpstate_class_type) },                        
    // export enumeration class for type 'StateMachineStates'
    { MP_ROM_QSTR(MP_QSTR_StateMachineStates), MP_ROM_PTR(&statemachinestates_class_type) },                        
    // export enumeration class for type 'AdcsOpState'
    { MP_ROM_QSTR(MP_QSTR_AdcsOpState), MP_ROM_PTR(&adcsopstate_class_type) },                        
    // export enumeration class for type 'AdcsProgType'
    { MP_ROM_QSTR(MP_QSTR_AdcsProgType), MP_ROM_PTR(&adcsprogtype_class_type) },                        
    // export enumeration class for type 'TctlmCubeComputerCommon3_LogReadFilterType'
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeComputerCommon3_LogReadFilterType), MP_ROM_PTR(&tctlmcubecomputercommon3_logreadfiltertype_class_type) },                        
    // export enumeration class for type 'TctlmCubeComputerCommon3_TlmLogReturnIntervalValues'
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeComputerCommon3_TlmLogReturnIntervalValues), MP_ROM_PTR(&tctlmcubecomputercommon3_tlmlogreturnintervalvalues_class_type) },                        
    // export enumeration class for type 'ControlModes'
    { MP_ROM_QSTR(MP_QSTR_ControlModes), MP_ROM_PTR(&controlmodes_class_type) },                        
    // export struct class objects for type 'FName'
    { MP_ROM_QSTR(MP_QSTR_FName_make_from_buf), MP_ROM_PTR(&FName_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_FName), MP_ROM_PTR(&FName_type)},
    // export struct class objects for type 'telemetry_mask_2'
    { MP_ROM_QSTR(MP_QSTR_telemetry_mask_2_make_from_buf), MP_ROM_PTR(&telemetry_mask_2_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_telemetry_mask_2), MP_ROM_PTR(&telemetry_mask_2_type)},
    // export struct class objects for type 'CompErrCodes'
    { MP_ROM_QSTR(MP_QSTR_CompErrCodes_make_from_buf), MP_ROM_PTR(&CompErrCodes_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_CompErrCodes), MP_ROM_PTR(&CompErrCodes_type)},
    // export struct class objects for type 'telemetry_mask_1'
    { MP_ROM_QSTR(MP_QSTR_telemetry_mask_1_make_from_buf), MP_ROM_PTR(&telemetry_mask_1_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_telemetry_mask_1), MP_ROM_PTR(&telemetry_mask_1_type)},
    // export struct class objects for type 'telemetry_mask_4'
    { MP_ROM_QSTR(MP_QSTR_telemetry_mask_4_make_from_buf), MP_ROM_PTR(&telemetry_mask_4_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_telemetry_mask_4), MP_ROM_PTR(&telemetry_mask_4_type)},
    // export struct class objects for type 'telemetry_mask_3'
    { MP_ROM_QSTR(MP_QSTR_telemetry_mask_3_make_from_buf), MP_ROM_PTR(&telemetry_mask_3_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_telemetry_mask_3), MP_ROM_PTR(&telemetry_mask_3_type)},
    // export struct class objects for type 'telemetry_mask_0'
    { MP_ROM_QSTR(MP_QSTR_telemetry_mask_0_make_from_buf), MP_ROM_PTR(&telemetry_mask_0_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_telemetry_mask_0), MP_ROM_PTR(&telemetry_mask_0_type)},
    // export struct class objects for type 'events'
    { MP_ROM_QSTR(MP_QSTR_events_make_from_buf), MP_ROM_PTR(&events_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_events), MP_ROM_PTR(&events_type)},
    // export struct class objects for type 'TctlmCubeCommonBaseBootloader5_Errors'
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeCommonBaseBootloader5_Errors_make_from_buf), MP_ROM_PTR(&TctlmCubeCommonBaseBootloader5_Errors_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeCommonBaseBootloader5_Errors), MP_ROM_PTR(&TctlmCubeCommonBaseBootloader5_Errors_type)},
    // export struct class objects for type 'RefParams'
    { MP_ROM_QSTR(MP_QSTR_RefParams_make_from_buf), MP_ROM_PTR(&RefParams_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_RefParams), MP_ROM_PTR(&RefParams_type)},
    // export struct class objects for type 'fdir_stat'
    { MP_ROM_QSTR(MP_QSTR_fdir_stat_make_from_buf), MP_ROM_PTR(&fdir_stat_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_fdir_stat), MP_ROM_PTR(&fdir_stat_type)},
    // export struct class objects for type 'PowerState'
    { MP_ROM_QSTR(MP_QSTR_PowerState_make_from_buf), MP_ROM_PTR(&PowerState_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_PowerState), MP_ROM_PTR(&PowerState_type)},
    // export struct class objects for type 'TctlmCubeComputerCommon3_EventLogStatus'
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeComputerCommon3_EventLogStatus_make_from_buf), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogStatus_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeComputerCommon3_EventLogStatus), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogStatus_type)},
    // export struct class objects for type 'TctlmCubeComputerCommon3_ImageTransferStatus'
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeComputerCommon3_ImageTransferStatus_make_from_buf), MP_ROM_PTR(&TctlmCubeComputerCommon3_ImageTransferStatus_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeComputerCommon3_ImageTransferStatus), MP_ROM_PTR(&TctlmCubeComputerCommon3_ImageTransferStatus_type)},
    // export struct class objects for type 'EstModeConfig'
    { MP_ROM_QSTR(MP_QSTR_EstModeConfig_make_from_buf), MP_ROM_PTR(&EstModeConfig_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_EstModeConfig), MP_ROM_PTR(&EstModeConfig_type)},
    // export struct class objects for type 'cube_computer_fw_update_status'
    { MP_ROM_QSTR(MP_QSTR_cube_computer_fw_update_status_make_from_buf), MP_ROM_PTR(&cube_computer_fw_update_status_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_cube_computer_fw_update_status), MP_ROM_PTR(&cube_computer_fw_update_status_type)},
    // export struct class objects for type 'TctlmCubeComputerCommon3_TelemtryLogStatus'
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeComputerCommon3_TelemtryLogStatus_make_from_buf), MP_ROM_PTR(&TctlmCubeComputerCommon3_TelemtryLogStatus_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeComputerCommon3_TelemtryLogStatus), MP_ROM_PTR(&TctlmCubeComputerCommon3_TelemtryLogStatus_type)},
    // export struct class objects for type 'BootStatus'
    { MP_ROM_QSTR(MP_QSTR_BootStatus_make_from_buf), MP_ROM_PTR(&BootStatus_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_BootStatus), MP_ROM_PTR(&BootStatus_type)},
    // export struct class objects for type 'TctlmCubeComputerControlProgram8_FileTransferStatus'
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeComputerControlProgram8_FileTransferStatus_make_from_buf), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeComputerControlProgram8_FileTransferStatus), MP_ROM_PTR(&TctlmCubeComputerControlProgram8_FileTransferStatus_type)},
    // export struct class objects for type 'TctlmCubeComputerCommon3_EventLogFilterTransferSetup'
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeComputerCommon3_EventLogFilterTransferSetup_make_from_buf), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeComputerCommon3_EventLogFilterTransferSetup), MP_ROM_PTR(&TctlmCubeComputerCommon3_EventLogFilterTransferSetup_type)},
    // export struct class objects for type 'TctlmCubeComputerCommon3_TelemetryLogTransferSetup'
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeComputerCommon3_TelemetryLogTransferSetup_make_from_buf), MP_ROM_PTR(&TctlmCubeComputerCommon3_TelemetryLogTransferSetup_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_TctlmCubeComputerCommon3_TelemetryLogTransferSetup), MP_ROM_PTR(&TctlmCubeComputerCommon3_TelemetryLogTransferSetup_type)},
    // export struct class objects for type 'ControlModeConfig'
    { MP_ROM_QSTR(MP_QSTR_ControlModeConfig_make_from_buf), MP_ROM_PTR(&ControlModeConfig_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_ControlModeConfig), MP_ROM_PTR(&ControlModeConfig_type)},
    // export struct class objects for type 'state_change_core_args'
    { MP_ROM_QSTR(MP_QSTR_state_change_core_args_make_from_buf), MP_ROM_PTR(&state_change_core_args_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_state_change_core_args), MP_ROM_PTR(&state_change_core_args_type)},
    // export struct class objects for type 'OpStatusCommon'
    { MP_ROM_QSTR(MP_QSTR_OpStatusCommon_make_from_buf), MP_ROM_PTR(&OpStatusCommon_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_OpStatusCommon), MP_ROM_PTR(&OpStatusCommon_type)},
    // export struct class objects for type 'cube_node_fw_update_status'
    { MP_ROM_QSTR(MP_QSTR_cube_node_fw_update_status_make_from_buf), MP_ROM_PTR(&cube_node_fw_update_status_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_cube_node_fw_update_status), MP_ROM_PTR(&cube_node_fw_update_status_type)},
    // export struct class objects for type 'download_event_status'
    { MP_ROM_QSTR(MP_QSTR_download_event_status_make_from_buf), MP_ROM_PTR(&download_event_status_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_download_event_status), MP_ROM_PTR(&download_event_status_type)},
    // export struct class objects for type 'download_telemetry_status'
    { MP_ROM_QSTR(MP_QSTR_download_telemetry_status_make_from_buf), MP_ROM_PTR(&download_telemetry_status_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_download_telemetry_status), MP_ROM_PTR(&download_telemetry_status_type)},
    // export struct class objects for type 'OpStatusApp'
    { MP_ROM_QSTR(MP_QSTR_OpStatusApp_make_from_buf), MP_ROM_PTR(&OpStatusApp_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_OpStatusApp), MP_ROM_PTR(&OpStatusApp_type)},
    // export struct class objects for type 'state_change_args'
    { MP_ROM_QSTR(MP_QSTR_state_change_args_make_from_buf), MP_ROM_PTR(&state_change_args_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_state_change_args), MP_ROM_PTR(&state_change_args_type)},
};

/**********************************************************************
 *
 *  uPy C module registration
 *
 **********************************************************************/
STATIC MP_DEFINE_CONST_DICT(upy_obc_cubeadcs_gen2_module_globals,
                            upy_obc_cubeadcs_gen2_module_globals_table);

const mp_obj_module_t upy_obc_cubeadcs_gen2_user_cmodule = {
    .base    = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&upy_obc_cubeadcs_gen2_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_upy_obc_cubeadcs_gen2, upy_obc_cubeadcs_gen2_user_cmodule);
