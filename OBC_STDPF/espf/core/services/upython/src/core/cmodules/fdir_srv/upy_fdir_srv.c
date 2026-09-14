/*!
********************************************************************************************
* @file upy_fdir_srv.c
* @brief uPy C bindings generator
********************************************************************************************
* @version           interface fdir_srv v0.2
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
 * @defgroup fdir_srv fdir_srv
 * @{
 *
 * Control and configuration interface of the FDIR service on OBC
 *
 * @file upy_fdir_srv.c
 * @brief fdir_srv uPython C wrapper module implementation
 *
 * This module is fully generated from a FIDL file and represents a uPython C extension module which
 * registers specific classes related to the communication interfaces of the fdir_srv API. Users of
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
#include "FP_fdir_srvProtocolTypes.h"

/**********************************************************************
 *
 *  uPy class definitions for struct types
 *
 **********************************************************************/


/**********************************************************************
 *
 *  Enumeration classes
 *
 **********************************************************************/
//
// Enumeration classes for type 'return_status'
//
STATIC const mp_rom_map_elem_t return_status_locals_dict_table[7] = 
{
    { MP_ROM_QSTR(MP_QSTR_RETURN_STATUS_SUCCESS), MP_ROM_INT(FDIR_SRV_RETURN_STATUS_SUCCESS)},
    { MP_ROM_QSTR(MP_QSTR_RETURN_STATUS_ERROR_INVALID_FAULT_ID), MP_ROM_INT(FDIR_SRV_RETURN_STATUS_ERROR_INVALID_FAULT_ID)},
    { MP_ROM_QSTR(MP_QSTR_RETURN_STATUS_ERROR_INVALID_AGENT_ID), MP_ROM_INT(FDIR_SRV_RETURN_STATUS_ERROR_INVALID_AGENT_ID)},
    { MP_ROM_QSTR(MP_QSTR_RETURN_STATUS_ERROR_INVALID_FDIR_LEVEL), MP_ROM_INT(FDIR_SRV_RETURN_STATUS_ERROR_INVALID_FDIR_LEVEL)},
    { MP_ROM_QSTR(MP_QSTR_RETURN_STATUS_ERROR_FAULT_DETECTION_DISABLED), MP_ROM_INT(FDIR_SRV_RETURN_STATUS_ERROR_FAULT_DETECTION_DISABLED)},
    { MP_ROM_QSTR(MP_QSTR_RETURN_STATUS_ERROR_FAULT_LEVEL_ABOVE_AUTOCLEAR), MP_ROM_INT(FDIR_SRV_RETURN_STATUS_ERROR_FAULT_LEVEL_ABOVE_AUTOCLEAR)},
    { MP_ROM_QSTR(MP_QSTR_RETURN_STATUS_ERROR_INTERNAL), MP_ROM_INT(FDIR_SRV_RETURN_STATUS_ERROR_INTERNAL)},
};

STATIC MP_DEFINE_CONST_DICT(return_status_class_locals_dict, return_status_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    return_status_class_type,
    MP_QSTR_return_status,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&return_status_class_locals_dict
);

/**********************************************************************
 *
 *  Static function definitions
 *
 **********************************************************************/
// uPy request function for method 'get_system_fdir_level'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_get_system_fdir_level_fp_t;

STATIC mp_obj_t req_get_system_fdir_level(void)
{

    // allocate memory on the MicroPython heap
    req_get_system_fdir_level_fp_t * p_req_data = m_malloc(sizeof(req_get_system_fdir_level_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'get_system_fdir_level' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 29;
    p_req_data->fp_hdr.func_id = 1;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_get_system_fdir_level_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'get_system_fdir_level'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvget_system_fdir_levelResponseData_t data;
} resp_get_system_fdir_level_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_get_system_fdir_level_fp_t class_data;
} resp_get_system_fdir_level_class_obj_t;

STATIC mp_obj_t resp_get_system_fdir_level_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_get_system_fdir_level_class_obj_t *p_self = m_new_obj(resp_get_system_fdir_level_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_get_system_fdir_level_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_get_system_fdir_level_fp_t *p_data = (resp_get_system_fdir_level_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "get_system_fdir_level" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_get_system_fdir_level_get_status(mp_obj_t self_in) 
{
    const resp_get_system_fdir_level_class_obj_t *p_resp_data = ((resp_get_system_fdir_level_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eStatus);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_system_fdir_level_get_status_obj, resp_get_system_fdir_level_get_status);

STATIC mp_obj_t resp_get_system_fdir_level_get_fdir_level(mp_obj_t self_in) 
{
    const resp_get_system_fdir_level_class_obj_t *p_resp_data = ((resp_get_system_fdir_level_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.u8Fdir_level);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_system_fdir_level_get_fdir_level_obj, resp_get_system_fdir_level_get_fdir_level);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_get_system_fdir_level_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_get_system_fdir_level_get_status_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fdir_level), MP_ROM_PTR(&resp_get_system_fdir_level_get_fdir_level_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_get_system_fdir_level_locals_dict, resp_get_system_fdir_level_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_fdir_srvget_system_fdir_levelResponseData,
    MP_QSTR_resp_get_system_fdir_level,
    MP_TYPE_FLAG_NONE,
    make_new, resp_get_system_fdir_level_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_get_system_fdir_level_locals_dict    
);

// uPy request function for method 'get_agent_fdir_level'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvget_agent_fdir_levelRequestData_t data;
} req_get_agent_fdir_level_fp_t;

STATIC mp_obj_t req_get_agent_fdir_level(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_get_agent_fdir_level_fp_t * p_req_data = m_malloc(sizeof(req_get_agent_fdir_level_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'get_agent_fdir_level' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 29;
    p_req_data->fp_hdr.func_id = 2;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.u16Agent_id = (uint16_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_get_agent_fdir_level_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'get_agent_fdir_level'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvget_agent_fdir_levelResponseData_t data;
} resp_get_agent_fdir_level_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_get_agent_fdir_level_fp_t class_data;
} resp_get_agent_fdir_level_class_obj_t;

STATIC mp_obj_t resp_get_agent_fdir_level_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_get_agent_fdir_level_class_obj_t *p_self = m_new_obj(resp_get_agent_fdir_level_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_get_agent_fdir_level_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_get_agent_fdir_level_fp_t *p_data = (resp_get_agent_fdir_level_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "get_agent_fdir_level" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_get_agent_fdir_level_get_status(mp_obj_t self_in) 
{
    const resp_get_agent_fdir_level_class_obj_t *p_resp_data = ((resp_get_agent_fdir_level_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eStatus);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_agent_fdir_level_get_status_obj, resp_get_agent_fdir_level_get_status);

STATIC mp_obj_t resp_get_agent_fdir_level_get_fdir_level(mp_obj_t self_in) 
{
    const resp_get_agent_fdir_level_class_obj_t *p_resp_data = ((resp_get_agent_fdir_level_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.u8Fdir_level);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_agent_fdir_level_get_fdir_level_obj, resp_get_agent_fdir_level_get_fdir_level);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_get_agent_fdir_level_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_get_agent_fdir_level_get_status_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fdir_level), MP_ROM_PTR(&resp_get_agent_fdir_level_get_fdir_level_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_get_agent_fdir_level_locals_dict, resp_get_agent_fdir_level_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_fdir_srvget_agent_fdir_levelResponseData,
    MP_QSTR_resp_get_agent_fdir_level,
    MP_TYPE_FLAG_NONE,
    make_new, resp_get_agent_fdir_level_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_get_agent_fdir_level_locals_dict    
);

// uPy request function for method 'get_detection_for_fault'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvget_detection_for_faultRequestData_t data;
} req_get_detection_for_fault_fp_t;

STATIC mp_obj_t req_get_detection_for_fault(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_get_detection_for_fault_fp_t * p_req_data = m_malloc(sizeof(req_get_detection_for_fault_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'get_detection_for_fault' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 29;
    p_req_data->fp_hdr.func_id = 3;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.u16Fault_id = (uint16_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_get_detection_for_fault_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'get_detection_for_fault'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvget_detection_for_faultResponseData_t data;
} resp_get_detection_for_fault_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_get_detection_for_fault_fp_t class_data;
} resp_get_detection_for_fault_class_obj_t;

STATIC mp_obj_t resp_get_detection_for_fault_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_get_detection_for_fault_class_obj_t *p_self = m_new_obj(resp_get_detection_for_fault_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_get_detection_for_fault_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_get_detection_for_fault_fp_t *p_data = (resp_get_detection_for_fault_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "get_detection_for_fault" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_get_detection_for_fault_get_status(mp_obj_t self_in) 
{
    const resp_get_detection_for_fault_class_obj_t *p_resp_data = ((resp_get_detection_for_fault_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eStatus);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_detection_for_fault_get_status_obj, resp_get_detection_for_fault_get_status);

STATIC mp_obj_t resp_get_detection_for_fault_get_detection_enabled(mp_obj_t self_in) 
{
    const resp_get_detection_for_fault_class_obj_t *p_resp_data = ((resp_get_detection_for_fault_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.bDetection_enabled);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_detection_for_fault_get_detection_enabled_obj, resp_get_detection_for_fault_get_detection_enabled);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_get_detection_for_fault_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_get_detection_for_fault_get_status_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_detection_enabled), MP_ROM_PTR(&resp_get_detection_for_fault_get_detection_enabled_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_get_detection_for_fault_locals_dict, resp_get_detection_for_fault_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_fdir_srvget_detection_for_faultResponseData,
    MP_QSTR_resp_get_detection_for_fault,
    MP_TYPE_FLAG_NONE,
    make_new, resp_get_detection_for_fault_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_get_detection_for_fault_locals_dict    
);

// uPy request function for method 'set_detection_for_fault'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvset_detection_for_faultRequestData_t data;
} req_set_detection_for_fault_fp_t;

STATIC mp_obj_t req_set_detection_for_fault(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_set_detection_for_fault_fp_t * p_req_data = m_malloc(sizeof(req_set_detection_for_fault_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'set_detection_for_fault' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 29;
    p_req_data->fp_hdr.func_id = 4;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.u16Fault_id = (uint16_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.bSet_detection_enabled = (bool) mp_obj_get_int(p_args[1]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_set_detection_for_fault_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'set_detection_for_fault'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvset_detection_for_faultResponseData_t data;
} resp_set_detection_for_fault_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_set_detection_for_fault_fp_t class_data;
} resp_set_detection_for_fault_class_obj_t;

STATIC mp_obj_t resp_set_detection_for_fault_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_set_detection_for_fault_class_obj_t *p_self = m_new_obj(resp_set_detection_for_fault_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_set_detection_for_fault_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_set_detection_for_fault_fp_t *p_data = (resp_set_detection_for_fault_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "set_detection_for_fault" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_set_detection_for_fault_get_status(mp_obj_t self_in) 
{
    const resp_set_detection_for_fault_class_obj_t *p_resp_data = ((resp_set_detection_for_fault_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eStatus);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_set_detection_for_fault_get_status_obj, resp_set_detection_for_fault_get_status);

STATIC mp_obj_t resp_set_detection_for_fault_get_detection_enabled(mp_obj_t self_in) 
{
    const resp_set_detection_for_fault_class_obj_t *p_resp_data = ((resp_set_detection_for_fault_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.bDetection_enabled);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_set_detection_for_fault_get_detection_enabled_obj, resp_set_detection_for_fault_get_detection_enabled);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_set_detection_for_fault_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_set_detection_for_fault_get_status_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_detection_enabled), MP_ROM_PTR(&resp_set_detection_for_fault_get_detection_enabled_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_set_detection_for_fault_locals_dict, resp_set_detection_for_fault_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_fdir_srvset_detection_for_faultResponseData,
    MP_QSTR_resp_set_detection_for_fault,
    MP_TYPE_FLAG_NONE,
    make_new, resp_set_detection_for_fault_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_set_detection_for_fault_locals_dict    
);

// uPy request function for method 'set_detection_for_all_faults'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvset_detection_for_all_faultsRequestData_t data;
} req_set_detection_for_all_faults_fp_t;

STATIC mp_obj_t req_set_detection_for_all_faults(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_set_detection_for_all_faults_fp_t * p_req_data = m_malloc(sizeof(req_set_detection_for_all_faults_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'set_detection_for_all_faults' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 29;
    p_req_data->fp_hdr.func_id = 20;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.bSet_detection_enabled = (bool) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_set_detection_for_all_faults_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'set_detection_for_all_faults'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvset_detection_for_all_faultsResponseData_t data;
} resp_set_detection_for_all_faults_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_set_detection_for_all_faults_fp_t class_data;
} resp_set_detection_for_all_faults_class_obj_t;

STATIC mp_obj_t resp_set_detection_for_all_faults_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_set_detection_for_all_faults_class_obj_t *p_self = m_new_obj(resp_set_detection_for_all_faults_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_set_detection_for_all_faults_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_set_detection_for_all_faults_fp_t *p_data = (resp_set_detection_for_all_faults_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "set_detection_for_all_faults" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_set_detection_for_all_faults_get_status(mp_obj_t self_in) 
{
    const resp_set_detection_for_all_faults_class_obj_t *p_resp_data = ((resp_set_detection_for_all_faults_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eStatus);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_set_detection_for_all_faults_get_status_obj, resp_set_detection_for_all_faults_get_status);

STATIC mp_obj_t resp_set_detection_for_all_faults_get_fault_id(mp_obj_t self_in) 
{
    const resp_set_detection_for_all_faults_class_obj_t *p_resp_data = ((resp_set_detection_for_all_faults_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.u16Fault_id);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_set_detection_for_all_faults_get_fault_id_obj, resp_set_detection_for_all_faults_get_fault_id);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_set_detection_for_all_faults_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_set_detection_for_all_faults_get_status_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fault_id), MP_ROM_PTR(&resp_set_detection_for_all_faults_get_fault_id_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_set_detection_for_all_faults_locals_dict, resp_set_detection_for_all_faults_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_fdir_srvset_detection_for_all_faultsResponseData,
    MP_QSTR_resp_set_detection_for_all_faults,
    MP_TYPE_FLAG_NONE,
    make_new, resp_set_detection_for_all_faults_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_set_detection_for_all_faults_locals_dict    
);

// uPy request function for method 'get_min_active_fdir'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_get_min_active_fdir_fp_t;

STATIC mp_obj_t req_get_min_active_fdir(void)
{

    // allocate memory on the MicroPython heap
    req_get_min_active_fdir_fp_t * p_req_data = m_malloc(sizeof(req_get_min_active_fdir_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'get_min_active_fdir' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 29;
    p_req_data->fp_hdr.func_id = 21;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_get_min_active_fdir_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'get_min_active_fdir'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvget_min_active_fdirResponseData_t data;
} resp_get_min_active_fdir_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_get_min_active_fdir_fp_t class_data;
} resp_get_min_active_fdir_class_obj_t;

STATIC mp_obj_t resp_get_min_active_fdir_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_get_min_active_fdir_class_obj_t *p_self = m_new_obj(resp_get_min_active_fdir_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_get_min_active_fdir_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_get_min_active_fdir_fp_t *p_data = (resp_get_min_active_fdir_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "get_min_active_fdir" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_get_min_active_fdir_get_status(mp_obj_t self_in) 
{
    const resp_get_min_active_fdir_class_obj_t *p_resp_data = ((resp_get_min_active_fdir_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eStatus);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_min_active_fdir_get_status_obj, resp_get_min_active_fdir_get_status);

STATIC mp_obj_t resp_get_min_active_fdir_get_fdir_level_set(mp_obj_t self_in) 
{
    const resp_get_min_active_fdir_class_obj_t *p_resp_data = ((resp_get_min_active_fdir_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.u8Fdir_level_set);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_min_active_fdir_get_fdir_level_set_obj, resp_get_min_active_fdir_get_fdir_level_set);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_get_min_active_fdir_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_get_min_active_fdir_get_status_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fdir_level_set), MP_ROM_PTR(&resp_get_min_active_fdir_get_fdir_level_set_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_get_min_active_fdir_locals_dict, resp_get_min_active_fdir_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_fdir_srvget_min_active_fdirResponseData,
    MP_QSTR_resp_get_min_active_fdir,
    MP_TYPE_FLAG_NONE,
    make_new, resp_get_min_active_fdir_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_get_min_active_fdir_locals_dict    
);

// uPy request function for method 'set_min_active_fdir'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvset_min_active_fdirRequestData_t data;
} req_set_min_active_fdir_fp_t;

STATIC mp_obj_t req_set_min_active_fdir(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_set_min_active_fdir_fp_t * p_req_data = m_malloc(sizeof(req_set_min_active_fdir_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'set_min_active_fdir' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 29;
    p_req_data->fp_hdr.func_id = 5;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.u8Fdir_level = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_set_min_active_fdir_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'set_min_active_fdir'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvset_min_active_fdirResponseData_t data;
} resp_set_min_active_fdir_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_set_min_active_fdir_fp_t class_data;
} resp_set_min_active_fdir_class_obj_t;

STATIC mp_obj_t resp_set_min_active_fdir_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_set_min_active_fdir_class_obj_t *p_self = m_new_obj(resp_set_min_active_fdir_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_set_min_active_fdir_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_set_min_active_fdir_fp_t *p_data = (resp_set_min_active_fdir_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "set_min_active_fdir" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_set_min_active_fdir_get_status(mp_obj_t self_in) 
{
    const resp_set_min_active_fdir_class_obj_t *p_resp_data = ((resp_set_min_active_fdir_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eStatus);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_set_min_active_fdir_get_status_obj, resp_set_min_active_fdir_get_status);

STATIC mp_obj_t resp_set_min_active_fdir_get_fdir_level_set(mp_obj_t self_in) 
{
    const resp_set_min_active_fdir_class_obj_t *p_resp_data = ((resp_set_min_active_fdir_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.u8Fdir_level_set);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_set_min_active_fdir_get_fdir_level_set_obj, resp_set_min_active_fdir_get_fdir_level_set);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_set_min_active_fdir_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_set_min_active_fdir_get_status_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fdir_level_set), MP_ROM_PTR(&resp_set_min_active_fdir_get_fdir_level_set_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_set_min_active_fdir_locals_dict, resp_set_min_active_fdir_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_fdir_srvset_min_active_fdirResponseData,
    MP_QSTR_resp_set_min_active_fdir,
    MP_TYPE_FLAG_NONE,
    make_new, resp_set_min_active_fdir_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_set_min_active_fdir_locals_dict    
);

// uPy request function for method 'get_fault_user_clear_level'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_get_fault_user_clear_level_fp_t;

STATIC mp_obj_t req_get_fault_user_clear_level(void)
{

    // allocate memory on the MicroPython heap
    req_get_fault_user_clear_level_fp_t * p_req_data = m_malloc(sizeof(req_get_fault_user_clear_level_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'get_fault_user_clear_level' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 29;
    p_req_data->fp_hdr.func_id = 7;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_get_fault_user_clear_level_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'get_fault_user_clear_level'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvget_fault_user_clear_levelResponseData_t data;
} resp_get_fault_user_clear_level_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_get_fault_user_clear_level_fp_t class_data;
} resp_get_fault_user_clear_level_class_obj_t;

STATIC mp_obj_t resp_get_fault_user_clear_level_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_get_fault_user_clear_level_class_obj_t *p_self = m_new_obj(resp_get_fault_user_clear_level_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_get_fault_user_clear_level_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_get_fault_user_clear_level_fp_t *p_data = (resp_get_fault_user_clear_level_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "get_fault_user_clear_level" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_get_fault_user_clear_level_get_status(mp_obj_t self_in) 
{
    const resp_get_fault_user_clear_level_class_obj_t *p_resp_data = ((resp_get_fault_user_clear_level_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eStatus);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_fault_user_clear_level_get_status_obj, resp_get_fault_user_clear_level_get_status);

STATIC mp_obj_t resp_get_fault_user_clear_level_get_fdir_level(mp_obj_t self_in) 
{
    const resp_get_fault_user_clear_level_class_obj_t *p_resp_data = ((resp_get_fault_user_clear_level_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.u8Fdir_level);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_fault_user_clear_level_get_fdir_level_obj, resp_get_fault_user_clear_level_get_fdir_level);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_get_fault_user_clear_level_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_get_fault_user_clear_level_get_status_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fdir_level), MP_ROM_PTR(&resp_get_fault_user_clear_level_get_fdir_level_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_get_fault_user_clear_level_locals_dict, resp_get_fault_user_clear_level_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_fdir_srvget_fault_user_clear_levelResponseData,
    MP_QSTR_resp_get_fault_user_clear_level,
    MP_TYPE_FLAG_NONE,
    make_new, resp_get_fault_user_clear_level_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_get_fault_user_clear_level_locals_dict    
);

// uPy request function for method 'set_fault_user_clear_level'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvset_fault_user_clear_levelRequestData_t data;
} req_set_fault_user_clear_level_fp_t;

STATIC mp_obj_t req_set_fault_user_clear_level(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_set_fault_user_clear_level_fp_t * p_req_data = m_malloc(sizeof(req_set_fault_user_clear_level_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'set_fault_user_clear_level' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 29;
    p_req_data->fp_hdr.func_id = 6;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.u8Fdir_level = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_set_fault_user_clear_level_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'set_fault_user_clear_level'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvset_fault_user_clear_levelResponseData_t data;
} resp_set_fault_user_clear_level_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_set_fault_user_clear_level_fp_t class_data;
} resp_set_fault_user_clear_level_class_obj_t;

STATIC mp_obj_t resp_set_fault_user_clear_level_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_set_fault_user_clear_level_class_obj_t *p_self = m_new_obj(resp_set_fault_user_clear_level_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_set_fault_user_clear_level_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_set_fault_user_clear_level_fp_t *p_data = (resp_set_fault_user_clear_level_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "set_fault_user_clear_level" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_set_fault_user_clear_level_get_status(mp_obj_t self_in) 
{
    const resp_set_fault_user_clear_level_class_obj_t *p_resp_data = ((resp_set_fault_user_clear_level_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eStatus);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_set_fault_user_clear_level_get_status_obj, resp_set_fault_user_clear_level_get_status);

STATIC mp_obj_t resp_set_fault_user_clear_level_get_fdir_level_set(mp_obj_t self_in) 
{
    const resp_set_fault_user_clear_level_class_obj_t *p_resp_data = ((resp_set_fault_user_clear_level_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.u8Fdir_level_set);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_set_fault_user_clear_level_get_fdir_level_set_obj, resp_set_fault_user_clear_level_get_fdir_level_set);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_set_fault_user_clear_level_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_set_fault_user_clear_level_get_status_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fdir_level_set), MP_ROM_PTR(&resp_set_fault_user_clear_level_get_fdir_level_set_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_set_fault_user_clear_level_locals_dict, resp_set_fault_user_clear_level_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_fdir_srvset_fault_user_clear_levelResponseData,
    MP_QSTR_resp_set_fault_user_clear_level,
    MP_TYPE_FLAG_NONE,
    make_new, resp_set_fault_user_clear_level_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_set_fault_user_clear_level_locals_dict    
);

// uPy request function for method 'get_fault'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvget_faultRequestData_t data;
} req_get_fault_fp_t;

STATIC mp_obj_t req_get_fault(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_get_fault_fp_t * p_req_data = m_malloc(sizeof(req_get_fault_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'get_fault' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 29;
    p_req_data->fp_hdr.func_id = 8;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.u16Fault_id = (uint16_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_get_fault_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'get_fault'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvget_faultResponseData_t data;
} resp_get_fault_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_get_fault_fp_t class_data;
} resp_get_fault_class_obj_t;

STATIC mp_obj_t resp_get_fault_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_get_fault_class_obj_t *p_self = m_new_obj(resp_get_fault_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_get_fault_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_get_fault_fp_t *p_data = (resp_get_fault_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "get_fault" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_get_fault_get_status(mp_obj_t self_in) 
{
    const resp_get_fault_class_obj_t *p_resp_data = ((resp_get_fault_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eStatus);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_fault_get_status_obj, resp_get_fault_get_status);

STATIC mp_obj_t resp_get_fault_get_is_active(mp_obj_t self_in) 
{
    const resp_get_fault_class_obj_t *p_resp_data = ((resp_get_fault_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.bIs_active);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_fault_get_is_active_obj, resp_get_fault_get_is_active);

STATIC mp_obj_t resp_get_fault_get_fdir_level(mp_obj_t self_in) 
{
    const resp_get_fault_class_obj_t *p_resp_data = ((resp_get_fault_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.u8Fdir_level);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_get_fault_get_fdir_level_obj, resp_get_fault_get_fdir_level);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_get_fault_locals_dict_table[3] = {
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_get_fault_get_status_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_is_active), MP_ROM_PTR(&resp_get_fault_get_is_active_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fdir_level), MP_ROM_PTR(&resp_get_fault_get_fdir_level_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_get_fault_locals_dict, resp_get_fault_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_fdir_srvget_faultResponseData,
    MP_QSTR_resp_get_fault,
    MP_TYPE_FLAG_NONE,
    make_new, resp_get_fault_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_get_fault_locals_dict    
);

// uPy request function for method 'set_fault'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvset_faultRequestData_t data;
} req_set_fault_fp_t;

STATIC mp_obj_t req_set_fault(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 3)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 3 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_set_fault_fp_t * p_req_data = m_malloc(sizeof(req_set_fault_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'set_fault' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 29;
    p_req_data->fp_hdr.func_id = 9;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.u16Fault_id = (uint16_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.u16Agent_id = (uint16_t) mp_obj_get_int(p_args[1]);
    p_req_data->data.bActive = (bool) mp_obj_get_int(p_args[2]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_set_fault_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'set_fault'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvset_faultResponseData_t data;
} resp_set_fault_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_set_fault_fp_t class_data;
} resp_set_fault_class_obj_t;

STATIC mp_obj_t resp_set_fault_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_set_fault_class_obj_t *p_self = m_new_obj(resp_set_fault_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_set_fault_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_set_fault_fp_t *p_data = (resp_set_fault_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "set_fault" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_set_fault_get_status(mp_obj_t self_in) 
{
    const resp_set_fault_class_obj_t *p_resp_data = ((resp_set_fault_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eStatus);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_set_fault_get_status_obj, resp_set_fault_get_status);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_set_fault_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_set_fault_get_status_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_set_fault_locals_dict, resp_set_fault_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_fdir_srvset_faultResponseData,
    MP_QSTR_resp_set_fault,
    MP_TYPE_FLAG_NONE,
    make_new, resp_set_fault_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_set_fault_locals_dict    
);

// uPy request function for method 'force_clear_fault'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvforce_clear_faultRequestData_t data;
} req_force_clear_fault_fp_t;

STATIC mp_obj_t req_force_clear_fault(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_force_clear_fault_fp_t * p_req_data = m_malloc(sizeof(req_force_clear_fault_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'force_clear_fault' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 29;
    p_req_data->fp_hdr.func_id = 10;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.u16Fault_id = (uint16_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_force_clear_fault_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'force_clear_fault'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvforce_clear_faultResponseData_t data;
} resp_force_clear_fault_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_force_clear_fault_fp_t class_data;
} resp_force_clear_fault_class_obj_t;

STATIC mp_obj_t resp_force_clear_fault_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_force_clear_fault_class_obj_t *p_self = m_new_obj(resp_force_clear_fault_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_force_clear_fault_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_force_clear_fault_fp_t *p_data = (resp_force_clear_fault_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "force_clear_fault" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_force_clear_fault_get_status(mp_obj_t self_in) 
{
    const resp_force_clear_fault_class_obj_t *p_resp_data = ((resp_force_clear_fault_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eStatus);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_force_clear_fault_get_status_obj, resp_force_clear_fault_get_status);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_force_clear_fault_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_force_clear_fault_get_status_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_force_clear_fault_locals_dict, resp_force_clear_fault_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_fdir_srvforce_clear_faultResponseData,
    MP_QSTR_resp_force_clear_fault,
    MP_TYPE_FLAG_NONE,
    make_new, resp_force_clear_fault_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_force_clear_fault_locals_dict    
);

// uPy request function for method 'force_clear_all_faults'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_force_clear_all_faults_fp_t;

STATIC mp_obj_t req_force_clear_all_faults(void)
{

    // allocate memory on the MicroPython heap
    req_force_clear_all_faults_fp_t * p_req_data = m_malloc(sizeof(req_force_clear_all_faults_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'force_clear_all_faults' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 29;
    p_req_data->fp_hdr.func_id = 11;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_force_clear_all_faults_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'force_clear_all_faults'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    fdir_srvforce_clear_all_faultsResponseData_t data;
} resp_force_clear_all_faults_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_force_clear_all_faults_fp_t class_data;
} resp_force_clear_all_faults_class_obj_t;

STATIC mp_obj_t resp_force_clear_all_faults_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_force_clear_all_faults_class_obj_t *p_self = m_new_obj(resp_force_clear_all_faults_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_force_clear_all_faults_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_force_clear_all_faults_fp_t *p_data = (resp_force_clear_all_faults_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "force_clear_all_faults" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_force_clear_all_faults_get_status(mp_obj_t self_in) 
{
    const resp_force_clear_all_faults_class_obj_t *p_resp_data = ((resp_force_clear_all_faults_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eStatus);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_force_clear_all_faults_get_status_obj, resp_force_clear_all_faults_get_status);

STATIC mp_obj_t resp_force_clear_all_faults_get_fault_id(mp_obj_t self_in) 
{
    const resp_force_clear_all_faults_class_obj_t *p_resp_data = ((resp_force_clear_all_faults_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.u16Fault_id);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_force_clear_all_faults_get_fault_id_obj, resp_force_clear_all_faults_get_fault_id);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_force_clear_all_faults_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_force_clear_all_faults_get_status_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_fault_id), MP_ROM_PTR(&resp_force_clear_all_faults_get_fault_id_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_force_clear_all_faults_locals_dict, resp_force_clear_all_faults_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_fdir_srvforce_clear_all_faultsResponseData,
    MP_QSTR_resp_force_clear_all_faults,
    MP_TYPE_FLAG_NONE,
    make_new, resp_force_clear_all_faults_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_force_clear_all_faults_locals_dict    
);


/**********************************************************************
 *
 *  uPy function reference definitions
 *
 **********************************************************************/
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_get_system_fdir_level_obj, req_get_system_fdir_level);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_get_agent_fdir_level_obj, 1, req_get_agent_fdir_level);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_get_detection_for_fault_obj, 1, req_get_detection_for_fault);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_set_detection_for_fault_obj, 2, req_set_detection_for_fault);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_set_detection_for_all_faults_obj, 1, req_set_detection_for_all_faults);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_get_min_active_fdir_obj, req_get_min_active_fdir);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_set_min_active_fdir_obj, 1, req_set_min_active_fdir);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_get_fault_user_clear_level_obj, req_get_fault_user_clear_level);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_set_fault_user_clear_level_obj, 1, req_set_fault_user_clear_level);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_get_fault_obj, 1, req_get_fault);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_set_fault_obj, 3, req_set_fault);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_force_clear_fault_obj, 1, req_force_clear_fault);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_force_clear_all_faults_obj, req_force_clear_all_faults);

STATIC const mp_rom_map_elem_t upy_fdir_srv_module_globals_table[28] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_upy_fdir_srv) },
    // export FIDL methods
    // export request serializer function for method 'get_system_fdir_level'
    { MP_ROM_QSTR(MP_QSTR_req_get_system_fdir_level), MP_ROM_PTR(&req_get_system_fdir_level_obj) },
    // export class for method 'get_system_fdir_level' response
    { MP_ROM_QSTR(MP_QSTR_resp_get_system_fdir_level), MP_ROM_PTR(&mp_type_fdir_srvget_system_fdir_levelResponseData) },
    // export request serializer function for method 'get_agent_fdir_level'
    { MP_ROM_QSTR(MP_QSTR_req_get_agent_fdir_level), MP_ROM_PTR(&req_get_agent_fdir_level_obj) },
    // export class for method 'get_agent_fdir_level' response
    { MP_ROM_QSTR(MP_QSTR_resp_get_agent_fdir_level), MP_ROM_PTR(&mp_type_fdir_srvget_agent_fdir_levelResponseData) },
    // export request serializer function for method 'get_detection_for_fault'
    { MP_ROM_QSTR(MP_QSTR_req_get_detection_for_fault), MP_ROM_PTR(&req_get_detection_for_fault_obj) },
    // export class for method 'get_detection_for_fault' response
    { MP_ROM_QSTR(MP_QSTR_resp_get_detection_for_fault), MP_ROM_PTR(&mp_type_fdir_srvget_detection_for_faultResponseData) },
    // export request serializer function for method 'set_detection_for_fault'
    { MP_ROM_QSTR(MP_QSTR_req_set_detection_for_fault), MP_ROM_PTR(&req_set_detection_for_fault_obj) },
    // export class for method 'set_detection_for_fault' response
    { MP_ROM_QSTR(MP_QSTR_resp_set_detection_for_fault), MP_ROM_PTR(&mp_type_fdir_srvset_detection_for_faultResponseData) },
    // export request serializer function for method 'set_detection_for_all_faults'
    { MP_ROM_QSTR(MP_QSTR_req_set_detection_for_all_faults), MP_ROM_PTR(&req_set_detection_for_all_faults_obj) },
    // export class for method 'set_detection_for_all_faults' response
    { MP_ROM_QSTR(MP_QSTR_resp_set_detection_for_all_faults), MP_ROM_PTR(&mp_type_fdir_srvset_detection_for_all_faultsResponseData) },
    // export request serializer function for method 'get_min_active_fdir'
    { MP_ROM_QSTR(MP_QSTR_req_get_min_active_fdir), MP_ROM_PTR(&req_get_min_active_fdir_obj) },
    // export class for method 'get_min_active_fdir' response
    { MP_ROM_QSTR(MP_QSTR_resp_get_min_active_fdir), MP_ROM_PTR(&mp_type_fdir_srvget_min_active_fdirResponseData) },
    // export request serializer function for method 'set_min_active_fdir'
    { MP_ROM_QSTR(MP_QSTR_req_set_min_active_fdir), MP_ROM_PTR(&req_set_min_active_fdir_obj) },
    // export class for method 'set_min_active_fdir' response
    { MP_ROM_QSTR(MP_QSTR_resp_set_min_active_fdir), MP_ROM_PTR(&mp_type_fdir_srvset_min_active_fdirResponseData) },
    // export request serializer function for method 'get_fault_user_clear_level'
    { MP_ROM_QSTR(MP_QSTR_req_get_fault_user_clear_level), MP_ROM_PTR(&req_get_fault_user_clear_level_obj) },
    // export class for method 'get_fault_user_clear_level' response
    { MP_ROM_QSTR(MP_QSTR_resp_get_fault_user_clear_level), MP_ROM_PTR(&mp_type_fdir_srvget_fault_user_clear_levelResponseData) },
    // export request serializer function for method 'set_fault_user_clear_level'
    { MP_ROM_QSTR(MP_QSTR_req_set_fault_user_clear_level), MP_ROM_PTR(&req_set_fault_user_clear_level_obj) },
    // export class for method 'set_fault_user_clear_level' response
    { MP_ROM_QSTR(MP_QSTR_resp_set_fault_user_clear_level), MP_ROM_PTR(&mp_type_fdir_srvset_fault_user_clear_levelResponseData) },
    // export request serializer function for method 'get_fault'
    { MP_ROM_QSTR(MP_QSTR_req_get_fault), MP_ROM_PTR(&req_get_fault_obj) },
    // export class for method 'get_fault' response
    { MP_ROM_QSTR(MP_QSTR_resp_get_fault), MP_ROM_PTR(&mp_type_fdir_srvget_faultResponseData) },
    // export request serializer function for method 'set_fault'
    { MP_ROM_QSTR(MP_QSTR_req_set_fault), MP_ROM_PTR(&req_set_fault_obj) },
    // export class for method 'set_fault' response
    { MP_ROM_QSTR(MP_QSTR_resp_set_fault), MP_ROM_PTR(&mp_type_fdir_srvset_faultResponseData) },
    // export request serializer function for method 'force_clear_fault'
    { MP_ROM_QSTR(MP_QSTR_req_force_clear_fault), MP_ROM_PTR(&req_force_clear_fault_obj) },
    // export class for method 'force_clear_fault' response
    { MP_ROM_QSTR(MP_QSTR_resp_force_clear_fault), MP_ROM_PTR(&mp_type_fdir_srvforce_clear_faultResponseData) },
    // export request serializer function for method 'force_clear_all_faults'
    { MP_ROM_QSTR(MP_QSTR_req_force_clear_all_faults), MP_ROM_PTR(&req_force_clear_all_faults_obj) },
    // export class for method 'force_clear_all_faults' response
    { MP_ROM_QSTR(MP_QSTR_resp_force_clear_all_faults), MP_ROM_PTR(&mp_type_fdir_srvforce_clear_all_faultsResponseData) },
    // export enumeration class for type 'return_status'
    { MP_ROM_QSTR(MP_QSTR_return_status), MP_ROM_PTR(&return_status_class_type) },                        
};

/**********************************************************************
 *
 *  uPy C module registration
 *
 **********************************************************************/
STATIC MP_DEFINE_CONST_DICT(upy_fdir_srv_module_globals,
                            upy_fdir_srv_module_globals_table);

const mp_obj_module_t upy_fdir_srv_user_cmodule = {
    .base    = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&upy_fdir_srv_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_upy_fdir_srv, upy_fdir_srv_user_cmodule);
