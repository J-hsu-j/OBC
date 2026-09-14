/*!
********************************************************************************************
* @file upy_sdr.c
* @brief uPy C bindings generator
********************************************************************************************
* @version           interface sdr v2.0
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
 * @defgroup sdr sdr
 * @{
 *
 * Interface for VW-SDR
 *
 * @file upy_sdr.c
 * @brief sdr uPython C wrapper module implementation
 *
 * This module is fully generated from a FIDL file and represents a uPython C extension module which
 * registers specific classes related to the communication interfaces of the sdr API. Users of
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
#include "FP_sdrProtocolTypes.h"

/**********************************************************************
 *
 *  uPy class definitions for struct types
 *
 **********************************************************************/

/**********************************************************************
 *
 *  uPy class definition for struct 'FileOp'
 *
 **********************************************************************/
    
// class structure for type FileOp
typedef struct 
{
    mp_obj_base_t base;
    SDR_FileOp_t class_data;
} PACKED_STRUCT FileOp_class_obj_t;

// FileOp class constructor from field arguments
STATIC mp_obj_t FileOp_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 2, 2, false);
    
    FileOp_class_obj_t *p_self = m_new_obj(FileOp_class_obj_t);
    p_self->base.type = type;
    
    // obc_file
    upy_sd_copy_fidl_buf_from_py_buf((uint8_t *) p_self->class_data.strObc_file, 47, &((FileOp_class_obj_t *) p_args[0])->class_data.u8Obc_fileSize, p_args[0]);
    // sdr_file
    upy_sd_copy_fidl_buf_from_py_buf((uint8_t *) p_self->class_data.strSdr_file, 197, &((FileOp_class_obj_t *) p_args[1])->class_data.u8Sdr_fileSize, p_args[1]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'FileOp' getters
//

STATIC mp_obj_t FileOp_get_obc_file(mp_obj_t self_in) 
{
    const FileOp_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_bytearray(p_self->class_data.u8Obc_fileSize, (uint8_t *) p_self->class_data.strObc_file);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(FileOp_get_obc_file_obj, FileOp_get_obc_file);

STATIC mp_obj_t FileOp_get_sdr_file(mp_obj_t self_in) 
{
    const FileOp_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_bytearray(p_self->class_data.u8Sdr_fileSize, (uint8_t *) p_self->class_data.strSdr_file);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(FileOp_get_sdr_file_obj, FileOp_get_sdr_file);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t FileOp_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_obc_file), MP_ROM_PTR(&FileOp_get_obc_file_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_sdr_file), MP_ROM_PTR(&FileOp_get_sdr_file_obj) },
};

STATIC MP_DEFINE_CONST_DICT(FileOp_locals_dict, FileOp_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    FileOp_type,
    MP_QSTR_FileOp,
    MP_TYPE_FLAG_NONE,
    make_new, FileOp_make_new,
    locals_dict, (mp_obj_dict_t*)&FileOp_locals_dict
);

STATIC mp_obj_t FileOp_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(SDR_FileOp_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    FileOp_class_obj_t *p_self = m_new_obj(FileOp_class_obj_t);
    p_self->base.type = &FileOp_type;
    
    const SDR_FileOp_t *p_data = (const SDR_FileOp_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// FileOp class constructor from a byte buffer
STATIC mp_obj_t FileOp_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return FileOp_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(SDR_FileOp_t, FileOp_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(SDR_FileOp_t, FileOp_class_obj_t, FileOp)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(FileOp_make_from_buf_obj, FileOp_make_from_buf);

/**********************************************************************
 *
 *  Enumeration classes
 *
 **********************************************************************/
//
// Enumeration classes for type 'FileStatus'
//
STATIC const mp_rom_map_elem_t filestatus_locals_dict_table[25] = 
{
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_ERR_NOT_DEFINED), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_ERR_NOT_DEFINED)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_ERR_FILE_NOT_FOUND), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_ERR_FILE_NOT_FOUND)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_ERR_ACESS_VIOLATION), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_ERR_ACESS_VIOLATION)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_ERR_DISK_FULL_OR_ALLOCATION_EXCEEDED), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_ERR_DISK_FULL_OR_ALLOCATION_EXCEEDED)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_ERR_ILLEGAL_TFTP_OPERATION), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_ERR_ILLEGAL_TFTP_OPERATION)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_ERR_UNKNOWN_TRANSFER_ID), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_ERR_UNKNOWN_TRANSFER_ID)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_ERR_FILE_ALREADY_EXISTS), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_ERR_FILE_ALREADY_EXISTS)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_ERR_NO_SUCH_USER), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_ERR_NO_SUCH_USER)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_STATUS_OK), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_STATUS_OK)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_TL_NOT_INIT), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_TL_NOT_INIT)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_CANNOT_OPEN_DEST_FILE_FOR_WRITE), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_CANNOT_OPEN_DEST_FILE_FOR_WRITE)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_FAILED_TO_WRITE_TO_DEST_FILE), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_FAILED_TO_WRITE_TO_DEST_FILE)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_FAILED_TO_CLOSE_DEST_FILE), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_FAILED_TO_CLOSE_DEST_FILE)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_CANNOT_OPEN_SOURCE_FILE_FOR_READ), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_CANNOT_OPEN_SOURCE_FILE_FOR_READ)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_FILE_NOT_FOUND_ON_SOURCE), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_FILE_NOT_FOUND_ON_SOURCE)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_FAILED_TO_READ_FROM_SOURCE_FILE), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_FAILED_TO_READ_FROM_SOURCE_FILE)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_FAILED_TO_CLOSE_SOURCE_FILE), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_FAILED_TO_CLOSE_SOURCE_FILE)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_CONNECTION_TO_SERVER_FAILED), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_CONNECTION_TO_SERVER_FAILED)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_FAILED_TO_DISCONNECT_FROM_SERVER), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_FAILED_TO_DISCONNECT_FROM_SERVER)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_RECV_FAILED), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_RECV_FAILED)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_SEND_FAILED), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_SEND_FAILED)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_BLOCK_NUMBER_MISMATCH), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_BLOCK_NUMBER_MISMATCH)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_DOWNLOADED_FILE_EMPTY), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_DOWNLOADED_FILE_EMPTY)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_TRANSFER_PENDING), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_TRANSFER_PENDING)},
    { MP_ROM_QSTR(MP_QSTR_FILESTATUS_ES_TFTP_BUSY), MP_ROM_INT(SDR_FILESTATUS_ES_TFTP_BUSY)},
};

STATIC MP_DEFINE_CONST_DICT(filestatus_class_locals_dict, filestatus_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    filestatus_class_type,
    MP_QSTR_FileStatus,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&filestatus_class_locals_dict
);
//
// Enumeration classes for type 'StateMachineState'
//
STATIC const mp_rom_map_elem_t statemachinestate_locals_dict_table[6] = 
{
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINESTATE_ROOT), MP_ROM_INT(SDR_STATEMACHINESTATE_ROOT)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINESTATE_INACTIVE), MP_ROM_INT(SDR_STATEMACHINESTATE_INACTIVE)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINESTATE_BOOTING), MP_ROM_INT(SDR_STATEMACHINESTATE_BOOTING)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINESTATE_SYNCING), MP_ROM_INT(SDR_STATEMACHINESTATE_SYNCING)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINESTATE_READY), MP_ROM_INT(SDR_STATEMACHINESTATE_READY)},
    { MP_ROM_QSTR(MP_QSTR_STATEMACHINESTATE_BUSY), MP_ROM_INT(SDR_STATEMACHINESTATE_BUSY)},
};

STATIC MP_DEFINE_CONST_DICT(statemachinestate_class_locals_dict, statemachinestate_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    statemachinestate_class_type,
    MP_QSTR_StateMachineState,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&statemachinestate_class_locals_dict
);

/**********************************************************************
 *
 *  Static function definitions
 *
 **********************************************************************/
// uPy request function for method 'sdr_upload'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    sdrsdr_uploadRequestData_t data;
} req_sdr_upload_fp_t;

STATIC mp_obj_t req_sdr_upload(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_sdr_upload_fp_t * p_req_data = m_malloc(sizeof(req_sdr_upload_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'sdr_upload' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 99;
    p_req_data->fp_hdr.func_id = 0;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.sFile = ((FileOp_class_obj_t *) MP_OBJ_TO_PTR(p_args[0]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_sdr_upload_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'sdr_upload'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    sdrsdr_uploadResponseData_t data;
} resp_sdr_upload_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_sdr_upload_fp_t class_data;
} resp_sdr_upload_class_obj_t;

STATIC mp_obj_t resp_sdr_upload_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_sdr_upload_class_obj_t *p_self = m_new_obj(resp_sdr_upload_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_sdr_upload_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_sdr_upload_fp_t *p_data = (resp_sdr_upload_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "sdr_upload" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_sdr_upload_get_status(mp_obj_t self_in) 
{
    const resp_sdr_upload_class_obj_t *p_resp_data = ((resp_sdr_upload_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eStatus);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_sdr_upload_get_status_obj, resp_sdr_upload_get_status);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_sdr_upload_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_sdr_upload_get_status_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_sdr_upload_locals_dict, resp_sdr_upload_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_sdrsdr_uploadResponseData,
    MP_QSTR_resp_sdr_upload,
    MP_TYPE_FLAG_NONE,
    make_new, resp_sdr_upload_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_sdr_upload_locals_dict    
);

// uPy request function for method 'sdr_download'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    sdrsdr_downloadRequestData_t data;
} req_sdr_download_fp_t;

STATIC mp_obj_t req_sdr_download(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_sdr_download_fp_t * p_req_data = m_malloc(sizeof(req_sdr_download_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'sdr_download' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 99;
    p_req_data->fp_hdr.func_id = 1;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.sFile = ((FileOp_class_obj_t *) MP_OBJ_TO_PTR(p_args[0]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_sdr_download_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'sdr_download'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    sdrsdr_downloadResponseData_t data;
} resp_sdr_download_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_sdr_download_fp_t class_data;
} resp_sdr_download_class_obj_t;

STATIC mp_obj_t resp_sdr_download_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_sdr_download_class_obj_t *p_self = m_new_obj(resp_sdr_download_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_sdr_download_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_sdr_download_fp_t *p_data = (resp_sdr_download_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "sdr_download" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_sdr_download_get_status(mp_obj_t self_in) 
{
    const resp_sdr_download_class_obj_t *p_resp_data = ((resp_sdr_download_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eStatus);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_sdr_download_get_status_obj, resp_sdr_download_get_status);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_sdr_download_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_sdr_download_get_status_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_sdr_download_locals_dict, resp_sdr_download_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_sdrsdr_downloadResponseData,
    MP_QSTR_resp_sdr_download,
    MP_TYPE_FLAG_NONE,
    make_new, resp_sdr_download_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_sdr_download_locals_dict    
);

// uPy request function for method 'sdr_poll_latest_ft_status'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_sdr_poll_latest_ft_status_fp_t;

STATIC mp_obj_t req_sdr_poll_latest_ft_status(void)
{

    // allocate memory on the MicroPython heap
    req_sdr_poll_latest_ft_status_fp_t * p_req_data = m_malloc(sizeof(req_sdr_poll_latest_ft_status_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'sdr_poll_latest_ft_status' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 99;
    p_req_data->fp_hdr.func_id = 2;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_sdr_poll_latest_ft_status_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'sdr_poll_latest_ft_status'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    sdrsdr_poll_latest_ft_statusResponseData_t data;
} resp_sdr_poll_latest_ft_status_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_sdr_poll_latest_ft_status_fp_t class_data;
} resp_sdr_poll_latest_ft_status_class_obj_t;

STATIC mp_obj_t resp_sdr_poll_latest_ft_status_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_sdr_poll_latest_ft_status_class_obj_t *p_self = m_new_obj(resp_sdr_poll_latest_ft_status_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_sdr_poll_latest_ft_status_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_sdr_poll_latest_ft_status_fp_t *p_data = (resp_sdr_poll_latest_ft_status_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "sdr_poll_latest_ft_status" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_sdr_poll_latest_ft_status_get_status(mp_obj_t self_in) 
{
    const resp_sdr_poll_latest_ft_status_class_obj_t *p_resp_data = ((resp_sdr_poll_latest_ft_status_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eStatus);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_sdr_poll_latest_ft_status_get_status_obj, resp_sdr_poll_latest_ft_status_get_status);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_sdr_poll_latest_ft_status_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_status), MP_ROM_PTR(&resp_sdr_poll_latest_ft_status_get_status_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_sdr_poll_latest_ft_status_locals_dict, resp_sdr_poll_latest_ft_status_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_sdrsdr_poll_latest_ft_statusResponseData,
    MP_QSTR_resp_sdr_poll_latest_ft_status,
    MP_TYPE_FLAG_NONE,
    make_new, resp_sdr_poll_latest_ft_status_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_sdr_poll_latest_ft_status_locals_dict    
);

// uPy request function for method 'sdr_get_state'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
} req_sdr_get_state_fp_t;

STATIC mp_obj_t req_sdr_get_state(void)
{

    // allocate memory on the MicroPython heap
    req_sdr_get_state_fp_t * p_req_data = m_malloc(sizeof(req_sdr_get_state_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'sdr_get_state' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 99;
    p_req_data->fp_hdr.func_id = 3;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_sdr_get_state_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'sdr_get_state'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    sdrsdr_get_stateResponseData_t data;
} resp_sdr_get_state_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_sdr_get_state_fp_t class_data;
} resp_sdr_get_state_class_obj_t;

STATIC mp_obj_t resp_sdr_get_state_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_sdr_get_state_class_obj_t *p_self = m_new_obj(resp_sdr_get_state_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_sdr_get_state_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_sdr_get_state_fp_t *p_data = (resp_sdr_get_state_fp_t *) buf_info.buf;
        
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
 *  uPy getters for method "sdr_get_state" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_sdr_get_state_get_sm_state(mp_obj_t self_in) 
{
    const resp_sdr_get_state_class_obj_t *p_resp_data = ((resp_sdr_get_state_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.eSm_state);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_sdr_get_state_get_sm_state_obj, resp_sdr_get_state_get_sm_state);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_sdr_get_state_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_sm_state), MP_ROM_PTR(&resp_sdr_get_state_get_sm_state_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_sdr_get_state_locals_dict, resp_sdr_get_state_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_sdrsdr_get_stateResponseData,
    MP_QSTR_resp_sdr_get_state,
    MP_TYPE_FLAG_NONE,
    make_new, resp_sdr_get_state_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_sdr_get_state_locals_dict    
);


/**********************************************************************
 *
 *  uPy function reference definitions
 *
 **********************************************************************/
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_sdr_upload_obj, 1, req_sdr_upload);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_sdr_download_obj, 1, req_sdr_download);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_sdr_poll_latest_ft_status_obj, req_sdr_poll_latest_ft_status);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(req_sdr_get_state_obj, req_sdr_get_state);

STATIC const mp_rom_map_elem_t upy_sdr_module_globals_table[13] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_upy_sdr) },
    // export FIDL methods
    // export request serializer function for method 'sdr_upload'
    { MP_ROM_QSTR(MP_QSTR_req_sdr_upload), MP_ROM_PTR(&req_sdr_upload_obj) },
    // export class for method 'sdr_upload' response
    { MP_ROM_QSTR(MP_QSTR_resp_sdr_upload), MP_ROM_PTR(&mp_type_sdrsdr_uploadResponseData) },
    // export request serializer function for method 'sdr_download'
    { MP_ROM_QSTR(MP_QSTR_req_sdr_download), MP_ROM_PTR(&req_sdr_download_obj) },
    // export class for method 'sdr_download' response
    { MP_ROM_QSTR(MP_QSTR_resp_sdr_download), MP_ROM_PTR(&mp_type_sdrsdr_downloadResponseData) },
    // export request serializer function for method 'sdr_poll_latest_ft_status'
    { MP_ROM_QSTR(MP_QSTR_req_sdr_poll_latest_ft_status), MP_ROM_PTR(&req_sdr_poll_latest_ft_status_obj) },
    // export class for method 'sdr_poll_latest_ft_status' response
    { MP_ROM_QSTR(MP_QSTR_resp_sdr_poll_latest_ft_status), MP_ROM_PTR(&mp_type_sdrsdr_poll_latest_ft_statusResponseData) },
    // export request serializer function for method 'sdr_get_state'
    { MP_ROM_QSTR(MP_QSTR_req_sdr_get_state), MP_ROM_PTR(&req_sdr_get_state_obj) },
    // export class for method 'sdr_get_state' response
    { MP_ROM_QSTR(MP_QSTR_resp_sdr_get_state), MP_ROM_PTR(&mp_type_sdrsdr_get_stateResponseData) },
    // export enumeration class for type 'FileStatus'
    { MP_ROM_QSTR(MP_QSTR_FileStatus), MP_ROM_PTR(&filestatus_class_type) },                        
    // export enumeration class for type 'StateMachineState'
    { MP_ROM_QSTR(MP_QSTR_StateMachineState), MP_ROM_PTR(&statemachinestate_class_type) },                        
    // export struct class objects for type 'FileOp'
    { MP_ROM_QSTR(MP_QSTR_FileOp_make_from_buf), MP_ROM_PTR(&FileOp_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_FileOp), MP_ROM_PTR(&FileOp_type)},
};

/**********************************************************************
 *
 *  uPy C module registration
 *
 **********************************************************************/
STATIC MP_DEFINE_CONST_DICT(upy_sdr_module_globals,
                            upy_sdr_module_globals_table);

const mp_obj_module_t upy_sdr_user_cmodule = {
    .base    = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&upy_sdr_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_upy_sdr, upy_sdr_user_cmodule);
