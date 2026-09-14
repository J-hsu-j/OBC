/*!
********************************************************************************************
* @file upy_payload_ctrl.c
* @brief uPy C bindings generator
********************************************************************************************
* @version           interface payload_ctrl v2.0
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
 * @defgroup payload_ctrl payload_ctrl
 * @{
 *
 * Payload Control interface used for testing purposes
 *
 * @file upy_payload_ctrl.c
 * @brief payload_ctrl uPython C wrapper module implementation
 *
 * This module is fully generated from a FIDL file and represents a uPython C extension module which
 * registers specific classes related to the communication interfaces of the payload_ctrl API. Users of
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
#include "FP_payload_ctrlProtocolTypes.h"

/**********************************************************************
 *
 *  uPy class definitions for struct types
 *
 **********************************************************************/

/**********************************************************************
 *
 *  uPy class definition for struct 'PayloadStartCfg'
 *
 **********************************************************************/
    
// class structure for type PayloadStartCfg
typedef struct 
{
    mp_obj_base_t base;
    PAYLOAD_CTRL_PayloadStartCfg_t class_data;
} PACKED_STRUCT PayloadStartCfg_class_obj_t;

// PayloadStartCfg class constructor from field arguments
STATIC mp_obj_t PayloadStartCfg_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 2, 2, false);
    
    PayloadStartCfg_class_obj_t *p_self = m_new_obj(PayloadStartCfg_class_obj_t);
    p_self->base.type = type;
    
    // flags
    p_self->class_data.u8Flags = (uint8_t) mp_obj_get_int(p_args[0]);
    // pl_args
    upy_sd_copy_fidl_scalar_array_from_py_list_uint8_t(p_self->class_data.au8Pl_args, 47, p_args[1]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'PayloadStartCfg' getters
//

STATIC mp_obj_t PayloadStartCfg_get_flags(mp_obj_t self_in) 
{
    const PayloadStartCfg_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u8Flags);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PayloadStartCfg_get_flags_obj, PayloadStartCfg_get_flags);

STATIC mp_obj_t PayloadStartCfg_get_pl_args(mp_obj_t self_in) 
{
    const PayloadStartCfg_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return upy_sd_copy_fidl_scalar_array_to_py_list_uint8_t(p_self->class_data.au8Pl_args, 47);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PayloadStartCfg_get_pl_args_obj, PayloadStartCfg_get_pl_args);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t PayloadStartCfg_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_flags), MP_ROM_PTR(&PayloadStartCfg_get_flags_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_pl_args), MP_ROM_PTR(&PayloadStartCfg_get_pl_args_obj) },
};

STATIC MP_DEFINE_CONST_DICT(PayloadStartCfg_locals_dict, PayloadStartCfg_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    PayloadStartCfg_type,
    MP_QSTR_PayloadStartCfg,
    MP_TYPE_FLAG_NONE,
    make_new, PayloadStartCfg_make_new,
    locals_dict, (mp_obj_dict_t*)&PayloadStartCfg_locals_dict
);

STATIC mp_obj_t PayloadStartCfg_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(PAYLOAD_CTRL_PayloadStartCfg_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    PayloadStartCfg_class_obj_t *p_self = m_new_obj(PayloadStartCfg_class_obj_t);
    p_self->base.type = &PayloadStartCfg_type;
    
    const PAYLOAD_CTRL_PayloadStartCfg_t *p_data = (const PAYLOAD_CTRL_PayloadStartCfg_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// PayloadStartCfg class constructor from a byte buffer
STATIC mp_obj_t PayloadStartCfg_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return PayloadStartCfg_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(PAYLOAD_CTRL_PayloadStartCfg_t, PayloadStartCfg_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(PAYLOAD_CTRL_PayloadStartCfg_t, PayloadStartCfg_class_obj_t, PayloadStartCfg)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PayloadStartCfg_make_from_buf_obj, PayloadStartCfg_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'PayloadInfo'
 *
 **********************************************************************/
    
// class structure for type PayloadInfo
typedef struct 
{
    mp_obj_base_t base;
    PAYLOAD_CTRL_PayloadInfo_t class_data;
} PACKED_STRUCT PayloadInfo_class_obj_t;

// PayloadInfo class constructor from field arguments
STATIC mp_obj_t PayloadInfo_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 2, 2, false);
    
    PayloadInfo_class_obj_t *p_self = m_new_obj(PayloadInfo_class_obj_t);
    p_self->base.type = type;
    
    // pl_state
    p_self->class_data.ePl_state = (uint8_t) mp_obj_get_int(p_args[0]);
    // last_error_code
    p_self->class_data.u32Last_error_code = (uint32_t) mp_obj_get_int(p_args[1]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'PayloadInfo' getters
//

STATIC mp_obj_t PayloadInfo_get_pl_state(mp_obj_t self_in) 
{
    const PayloadInfo_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.ePl_state);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PayloadInfo_get_pl_state_obj, PayloadInfo_get_pl_state);

STATIC mp_obj_t PayloadInfo_get_last_error_code(mp_obj_t self_in) 
{
    const PayloadInfo_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Last_error_code);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PayloadInfo_get_last_error_code_obj, PayloadInfo_get_last_error_code);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t PayloadInfo_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_pl_state), MP_ROM_PTR(&PayloadInfo_get_pl_state_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_last_error_code), MP_ROM_PTR(&PayloadInfo_get_last_error_code_obj) },
};

STATIC MP_DEFINE_CONST_DICT(PayloadInfo_locals_dict, PayloadInfo_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    PayloadInfo_type,
    MP_QSTR_PayloadInfo,
    MP_TYPE_FLAG_NONE,
    make_new, PayloadInfo_make_new,
    locals_dict, (mp_obj_dict_t*)&PayloadInfo_locals_dict
);

STATIC mp_obj_t PayloadInfo_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(PAYLOAD_CTRL_PayloadInfo_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    PayloadInfo_class_obj_t *p_self = m_new_obj(PayloadInfo_class_obj_t);
    p_self->base.type = &PayloadInfo_type;
    
    const PAYLOAD_CTRL_PayloadInfo_t *p_data = (const PAYLOAD_CTRL_PayloadInfo_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// PayloadInfo class constructor from a byte buffer
STATIC mp_obj_t PayloadInfo_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return PayloadInfo_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(PAYLOAD_CTRL_PayloadInfo_t, PayloadInfo_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(PAYLOAD_CTRL_PayloadInfo_t, PayloadInfo_class_obj_t, PayloadInfo)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PayloadInfo_make_from_buf_obj, PayloadInfo_make_from_buf);

/**********************************************************************
 *
 *  Enumeration classes
 *
 **********************************************************************/
//
// Enumeration classes for type 'PayloadOpResult'
//
STATIC const mp_rom_map_elem_t payloadopresult_locals_dict_table[5] = 
{
    { MP_ROM_QSTR(MP_QSTR_PAYLOADOPRESULT_NOT_INIT), MP_ROM_INT(PAYLOAD_CTRL_PAYLOADOPRESULT_NOT_INIT)},
    { MP_ROM_QSTR(MP_QSTR_PAYLOADOPRESULT_INVALID_PL_ID), MP_ROM_INT(PAYLOAD_CTRL_PAYLOADOPRESULT_INVALID_PL_ID)},
    { MP_ROM_QSTR(MP_QSTR_PAYLOADOPRESULT_REFUSE_CMD), MP_ROM_INT(PAYLOAD_CTRL_PAYLOADOPRESULT_REFUSE_CMD)},
    { MP_ROM_QSTR(MP_QSTR_PAYLOADOPRESULT_FAILED), MP_ROM_INT(PAYLOAD_CTRL_PAYLOADOPRESULT_FAILED)},
    { MP_ROM_QSTR(MP_QSTR_PAYLOADOPRESULT_OK), MP_ROM_INT(PAYLOAD_CTRL_PAYLOADOPRESULT_OK)},
};

STATIC MP_DEFINE_CONST_DICT(payloadopresult_class_locals_dict, payloadopresult_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    payloadopresult_class_type,
    MP_QSTR_PayloadOpResult,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&payloadopresult_class_locals_dict
);
//
// Enumeration classes for type 'StopMode'
//
STATIC const mp_rom_map_elem_t stopmode_locals_dict_table[2] = 
{
    { MP_ROM_QSTR(MP_QSTR_STOPMODE_NORMAL), MP_ROM_INT(PAYLOAD_CTRL_STOPMODE_NORMAL)},
    { MP_ROM_QSTR(MP_QSTR_STOPMODE_EMERGENCY), MP_ROM_INT(PAYLOAD_CTRL_STOPMODE_EMERGENCY)},
};

STATIC MP_DEFINE_CONST_DICT(stopmode_class_locals_dict, stopmode_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    stopmode_class_type,
    MP_QSTR_StopMode,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&stopmode_class_locals_dict
);
//
// Enumeration classes for type 'PayloadState'
//
STATIC const mp_rom_map_elem_t payloadstate_locals_dict_table[6] = 
{
    { MP_ROM_QSTR(MP_QSTR_PAYLOADSTATE_NOT_INIT), MP_ROM_INT(PAYLOAD_CTRL_PAYLOADSTATE_NOT_INIT)},
    { MP_ROM_QSTR(MP_QSTR_PAYLOADSTATE_STOPPED), MP_ROM_INT(PAYLOAD_CTRL_PAYLOADSTATE_STOPPED)},
    { MP_ROM_QSTR(MP_QSTR_PAYLOADSTATE_STARTED), MP_ROM_INT(PAYLOAD_CTRL_PAYLOADSTATE_STARTED)},
    { MP_ROM_QSTR(MP_QSTR_PAYLOADSTATE_STARTING), MP_ROM_INT(PAYLOAD_CTRL_PAYLOADSTATE_STARTING)},
    { MP_ROM_QSTR(MP_QSTR_PAYLOADSTATE_STOPPING), MP_ROM_INT(PAYLOAD_CTRL_PAYLOADSTATE_STOPPING)},
    { MP_ROM_QSTR(MP_QSTR_PAYLOADSTATE_ERROR), MP_ROM_INT(PAYLOAD_CTRL_PAYLOADSTATE_ERROR)},
};

STATIC MP_DEFINE_CONST_DICT(payloadstate_class_locals_dict, payloadstate_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    payloadstate_class_type,
    MP_QSTR_PayloadState,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&payloadstate_class_locals_dict
);

/**********************************************************************
 *
 *  Static function definitions
 *
 **********************************************************************/
// uPy request function for method 'start_payload'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    payload_ctrlstart_payloadRequestData_t data;
} req_start_payload_fp_t;

STATIC mp_obj_t req_start_payload(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_start_payload_fp_t * p_req_data = m_malloc(sizeof(req_start_payload_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'start_payload' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 111;
    p_req_data->fp_hdr.func_id = 0;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.u8Payload_id = (uint8_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.sStart_cfg = ((PayloadStartCfg_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_start_payload_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'start_payload'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    payload_ctrlstart_payloadResponseData_t data;
} resp_start_payload_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_start_payload_fp_t class_data;
} resp_start_payload_class_obj_t;

STATIC mp_obj_t resp_start_payload_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_start_payload_class_obj_t *p_self = m_new_obj(resp_start_payload_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_start_payload_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_start_payload_fp_t *p_data = (resp_start_payload_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "start_payload" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_start_payload_get_op_result(mp_obj_t self_in) 
{
    const resp_start_payload_class_obj_t *p_resp_data = ((resp_start_payload_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_start_payload_get_op_result_obj, resp_start_payload_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_start_payload_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_start_payload_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_start_payload_locals_dict, resp_start_payload_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_payload_ctrlstart_payloadResponseData,
    MP_QSTR_resp_start_payload,
    MP_TYPE_FLAG_NONE,
    make_new, resp_start_payload_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_start_payload_locals_dict    
);

// uPy request function for method 'stop_payload'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    payload_ctrlstop_payloadRequestData_t data;
} req_stop_payload_fp_t;

STATIC mp_obj_t req_stop_payload(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_stop_payload_fp_t * p_req_data = m_malloc(sizeof(req_stop_payload_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'stop_payload' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 111;
    p_req_data->fp_hdr.func_id = 1;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.u8Payload_id = (uint8_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.eReq_stop_mode = (uint8_t) mp_obj_get_int(p_args[1]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_stop_payload_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'stop_payload'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    payload_ctrlstop_payloadResponseData_t data;
} resp_stop_payload_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_stop_payload_fp_t class_data;
} resp_stop_payload_class_obj_t;

STATIC mp_obj_t resp_stop_payload_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_stop_payload_class_obj_t *p_self = m_new_obj(resp_stop_payload_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_stop_payload_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_stop_payload_fp_t *p_data = (resp_stop_payload_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "stop_payload" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_stop_payload_get_op_result(mp_obj_t self_in) 
{
    const resp_stop_payload_class_obj_t *p_resp_data = ((resp_stop_payload_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eOp_result);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_stop_payload_get_op_result_obj, resp_stop_payload_get_op_result);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_stop_payload_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_op_result), MP_ROM_PTR(&resp_stop_payload_get_op_result_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_stop_payload_locals_dict, resp_stop_payload_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_payload_ctrlstop_payloadResponseData,
    MP_QSTR_resp_stop_payload,
    MP_TYPE_FLAG_NONE,
    make_new, resp_stop_payload_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_stop_payload_locals_dict    
);

// uPy request function for method 'get_payload_info'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    payload_ctrlget_payload_infoRequestData_t data;
} req_get_payload_info_fp_t;

STATIC mp_obj_t req_get_payload_info(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_get_payload_info_fp_t * p_req_data = m_malloc(sizeof(req_get_payload_info_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'get_payload_info' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 111;
    p_req_data->fp_hdr.func_id = 2;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.u8Payload_id = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_get_payload_info_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'get_payload_info'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    payload_ctrlget_payload_infoResponseData_t data;
} resp_get_payload_info_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_get_payload_info_fp_t class_data;
} resp_get_payload_info_class_obj_t;

STATIC mp_obj_t resp_get_payload_info_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_get_payload_info_class_obj_t *p_self = m_new_obj(resp_get_payload_info_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_get_payload_info_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_get_payload_info_fp_t *p_data = (resp_get_payload_info_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "get_payload_info" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_get_payload_info_get_info(mp_obj_t self_in) 
{
    const resp_get_payload_info_class_obj_t *p_resp_data = ((resp_get_payload_info_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return PayloadInfo_make_from_buf(mp_obj_new_bytearray(sizeof(PAYLOAD_CTRL_PayloadInfo_t), (const uint8_t *) &p_resp_data->class_data.data.sInfo));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_payload_info_get_info_obj, resp_get_payload_info_get_info);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_get_payload_info_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_info), MP_ROM_PTR(&resp_get_payload_info_get_info_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_get_payload_info_locals_dict, resp_get_payload_info_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_payload_ctrlget_payload_infoResponseData,
    MP_QSTR_resp_get_payload_info,
    MP_TYPE_FLAG_NONE,
    make_new, resp_get_payload_info_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_get_payload_info_locals_dict    
);


/**********************************************************************
 *
 *  uPy function reference definitions
 *
 **********************************************************************/
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_start_payload_obj, 2, req_start_payload);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_stop_payload_obj, 2, req_stop_payload);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_get_payload_info_obj, 1, req_get_payload_info);

STATIC const mp_rom_map_elem_t upy_payload_ctrl_module_globals_table[14] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_upy_payload_ctrl) },
    // export FIDL methods
    // export request serializer function for method 'start_payload'
    { MP_ROM_QSTR(MP_QSTR_req_start_payload), MP_ROM_PTR(&req_start_payload_obj) },
    // export class for method 'start_payload' response
    { MP_ROM_QSTR(MP_QSTR_resp_start_payload), MP_ROM_PTR(&mp_type_payload_ctrlstart_payloadResponseData) },
    // export request serializer function for method 'stop_payload'
    { MP_ROM_QSTR(MP_QSTR_req_stop_payload), MP_ROM_PTR(&req_stop_payload_obj) },
    // export class for method 'stop_payload' response
    { MP_ROM_QSTR(MP_QSTR_resp_stop_payload), MP_ROM_PTR(&mp_type_payload_ctrlstop_payloadResponseData) },
    // export request serializer function for method 'get_payload_info'
    { MP_ROM_QSTR(MP_QSTR_req_get_payload_info), MP_ROM_PTR(&req_get_payload_info_obj) },
    // export class for method 'get_payload_info' response
    { MP_ROM_QSTR(MP_QSTR_resp_get_payload_info), MP_ROM_PTR(&mp_type_payload_ctrlget_payload_infoResponseData) },
    // export enumeration class for type 'PayloadOpResult'
    { MP_ROM_QSTR(MP_QSTR_PayloadOpResult), MP_ROM_PTR(&payloadopresult_class_type) },                        
    // export enumeration class for type 'StopMode'
    { MP_ROM_QSTR(MP_QSTR_StopMode), MP_ROM_PTR(&stopmode_class_type) },                        
    // export enumeration class for type 'PayloadState'
    { MP_ROM_QSTR(MP_QSTR_PayloadState), MP_ROM_PTR(&payloadstate_class_type) },                        
    // export struct class objects for type 'PayloadStartCfg'
    { MP_ROM_QSTR(MP_QSTR_PayloadStartCfg_make_from_buf), MP_ROM_PTR(&PayloadStartCfg_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_PayloadStartCfg), MP_ROM_PTR(&PayloadStartCfg_type)},
    // export struct class objects for type 'PayloadInfo'
    { MP_ROM_QSTR(MP_QSTR_PayloadInfo_make_from_buf), MP_ROM_PTR(&PayloadInfo_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_PayloadInfo), MP_ROM_PTR(&PayloadInfo_type)},
};

/**********************************************************************
 *
 *  uPy C module registration
 *
 **********************************************************************/
STATIC MP_DEFINE_CONST_DICT(upy_payload_ctrl_module_globals,
                            upy_payload_ctrl_module_globals_table);

const mp_obj_module_t upy_payload_ctrl_user_cmodule = {
    .base    = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&upy_payload_ctrl_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_upy_payload_ctrl, upy_payload_ctrl_user_cmodule);
