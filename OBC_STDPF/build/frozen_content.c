//
// Content for MICROPY_MODULE_FROZEN_STR
//
#include <stdint.h>
#define MP_FROZEN_STR_NAMES \

const uint32_t mp_frozen_str_sizes[] = { 0 };
const char mp_frozen_str_content[] = {
"\0"
};

//
// Content for MICROPY_MODULE_FROZEN_MPY
//
#include "py/mpconfig.h"
#include "py/objint.h"
#include "py/objstr.h"
#include "py/emitglue.h"
#include "py/nativeglue.h"

#if MICROPY_LONGINT_IMPL != 2
#error "incompatible MICROPY_LONGINT_IMPL"
#endif

#if MPZ_DIG_SIZE != 16
#error "incompatible MPZ_DIG_SIZE"
#endif

#if MICROPY_PY_BUILTINS_FLOAT
typedef struct _mp_obj_float_t {
    mp_obj_base_t base;
    mp_float_t value;
} mp_obj_float_t;
#endif

#if MICROPY_PY_BUILTINS_COMPLEX
typedef struct _mp_obj_complex_t {
    mp_obj_base_t base;
    mp_float_t real;
    mp_float_t imag;
} mp_obj_complex_t;
#endif

enum {
    MP_QSTR_struct_dot_py = MP_QSTRnumber_of,
    MP_QSTR_ustruct,
    MP_QSTR_Struct,
    MP_QSTR_size,
    MP_QSTR_buf,
};

const qstr_hash_t mp_qstr_frozen_const_hashes[] = {
    4981,
    2119,
    38130,
    42272,
    18804,
};

const qstr_len_t mp_qstr_frozen_const_lengths[] = {
    9,
    7,
    6,
    4,
    3,
};

extern const qstr_pool_t mp_qstr_const_pool;
const qstr_pool_t mp_qstr_frozen_const_pool = {
    &mp_qstr_const_pool, // previous pool
    MP_QSTRnumber_of, // previous pool size
    5, // allocated entries
    5, // used entries
    (qstr_hash_t *)mp_qstr_frozen_const_hashes,
    (qstr_len_t *)mp_qstr_frozen_const_lengths,
    {
        "struct.py",
        "ustruct",
        "Struct",
        "size",
        "buf",
    },
};

////////////////////////////////////////////////////////////////////////////////
// frozen module struct
// - original source file: C:/PYRASOBC-main/OBC_STDPF/build/frozen_mpy/struct.mpy
// - frozen file name: struct.py
// - .mpy header: 4d:06:00:1f

// frozen bytecode for file struct.py, scope struct__lt_module_gt_
static const byte fun_data_struct__lt_module_gt_[23] = {
    0x10,0x04, // prelude
    0x01, // names: <module>
    0x68, // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0x10,0x02, // LOAD_CONST_STRING '*'
    0x2a,0x01, // BUILD_TUPLE 1
    0x1b,0x03, // IMPORT_NAME 'ustruct'
    0x69, // IMPORT_STAR
    0x54, // LOAD_BUILD_CLASS
    0x32,0x00, // MAKE_FUNCTION 0
    0x10,0x04, // LOAD_CONST_STRING 'Struct'
    0x34,0x02, // CALL_FUNCTION 2
    0x16,0x04, // STORE_NAME 'Struct'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of struct__lt_module_gt_
// frozen bytecode for file struct.py, scope struct_Struct
static const byte fun_data_struct_Struct[30] = {
    0x00,0x0c, // prelude
    0x04, // names: Struct
    0x68,0x20,0x64,0x20,0x64, // code info
    0x11,0x0a, // LOAD_NAME '__name__'
    0x16,0x0b, // STORE_NAME '__module__'
    0x10,0x04, // LOAD_CONST_STRING 'Struct'
    0x16,0x0c, // STORE_NAME '__qualname__'
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x05, // STORE_NAME '__init__'
    0x32,0x01, // MAKE_FUNCTION 1
    0x16,0x08, // STORE_NAME 'unpack'
    0x32,0x02, // MAKE_FUNCTION 2
    0x16,0x09, // STORE_NAME 'pack'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of struct_Struct
// frozen bytecode for file struct.py, scope struct_Struct___init__
static const byte fun_data_struct_Struct___init__[22] = {
    0x1a,0x0c, // prelude
    0x05,0x0d,0x06, // names: __init__, self, format
    0x60,0x40,0x24, // code info
    0xb1, // LOAD_FAST 1
    0xb0, // LOAD_FAST 0
    0x18,0x06, // STORE_ATTR 'format'
    0x12,0x0e, // LOAD_GLOBAL 'calcsize'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0xb0, // LOAD_FAST 0
    0x18,0x07, // STORE_ATTR 'size'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
static const mp_raw_code_t raw_code_struct_Struct___init__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_struct_Struct___init__,
    #if MICROPY_PERSISTENT_CODE_SAVE || MICROPY_DEBUG_PRINTERS
    .fun_data_len = 22,
    #endif
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .n_children = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 5,
        .line_info = fun_data_struct_Struct___init__ + 5,
        .line_info_top = fun_data_struct_Struct___init__ + 8,
        .opcodes = fun_data_struct_Struct___init__ + 8,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// child of struct_Struct
// frozen bytecode for file struct.py, scope struct_Struct_unpack
static const byte fun_data_struct_Struct_unpack[16] = {
    0x22,0x0a, // prelude
    0x08,0x0d,0x0f, // names: unpack, self, buf
    0x80,0x09, // code info
    0x12,0x08, // LOAD_GLOBAL 'unpack'
    0xb0, // LOAD_FAST 0
    0x13,0x06, // LOAD_ATTR 'format'
    0xb1, // LOAD_FAST 1
    0x34,0x02, // CALL_FUNCTION 2
    0x63, // RETURN_VALUE
};
static const mp_raw_code_t raw_code_struct_Struct_unpack = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_struct_Struct_unpack,
    #if MICROPY_PERSISTENT_CODE_SAVE || MICROPY_DEBUG_PRINTERS
    .fun_data_len = 16,
    #endif
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .n_children = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 8,
        .line_info = fun_data_struct_Struct_unpack + 5,
        .line_info_top = fun_data_struct_Struct_unpack + 7,
        .opcodes = fun_data_struct_Struct_unpack + 7,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// child of struct_Struct
// frozen bytecode for file struct.py, scope struct_Struct_pack
static const byte fun_data_struct_Struct_pack[19] = {
    0xa9,0x80,0x80,0x40,0x08, // prelude
    0x09,0x0d, // names: pack, self
    0x80,0x0c, // code info
    0x12,0x09, // LOAD_GLOBAL 'pack'
    0xb0, // LOAD_FAST 0
    0x13,0x06, // LOAD_ATTR 'format'
    0xb1, // LOAD_FAST 1
    0x82, // LOAD_CONST_SMALL_INT 2
    0x35,0x02, // CALL_FUNCTION_VAR_KW 2
    0x63, // RETURN_VALUE
};
static const mp_raw_code_t raw_code_struct_Struct_pack = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x04,
    .n_pos_args = 1,
    .fun_data = fun_data_struct_Struct_pack,
    #if MICROPY_PERSISTENT_CODE_SAVE || MICROPY_DEBUG_PRINTERS
    .fun_data_len = 19,
    #endif
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .n_children = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 4,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 9,
        .line_info = fun_data_struct_Struct_pack + 7,
        .line_info_top = fun_data_struct_Struct_pack + 9,
        .opcodes = fun_data_struct_Struct_pack + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

static const mp_raw_code_t *const children_struct_Struct[] = {
    &raw_code_struct_Struct___init__,
    &raw_code_struct_Struct_unpack,
    &raw_code_struct_Struct_pack,
};

static const mp_raw_code_t raw_code_struct_Struct = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_struct_Struct,
    #if MICROPY_PERSISTENT_CODE_SAVE || MICROPY_DEBUG_PRINTERS
    .fun_data_len = 30,
    #endif
    .children = (void *)&children_struct_Struct,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .n_children = 3,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 4,
        .line_info = fun_data_struct_Struct + 3,
        .line_info_top = fun_data_struct_Struct + 8,
        .opcodes = fun_data_struct_Struct + 8,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

static const mp_raw_code_t *const children_struct__lt_module_gt_[] = {
    &raw_code_struct_Struct,
};

static const mp_raw_code_t raw_code_struct__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_struct__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE || MICROPY_DEBUG_PRINTERS
    .fun_data_len = 23,
    #endif
    .children = (void *)&children_struct__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .n_children = 1,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 1,
        .line_info = fun_data_struct__lt_module_gt_ + 3,
        .line_info_top = fun_data_struct__lt_module_gt_ + 4,
        .opcodes = fun_data_struct__lt_module_gt_ + 4,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

static const qstr_short_t const_qstr_table_data_struct[16] = {
    MP_QSTR_struct_dot_py,
    MP_QSTR__lt_module_gt_,
    MP_QSTR__star_,
    MP_QSTR_ustruct,
    MP_QSTR_Struct,
    MP_QSTR___init__,
    MP_QSTR_format,
    MP_QSTR_size,
    MP_QSTR_unpack,
    MP_QSTR_pack,
    MP_QSTR___name__,
    MP_QSTR___module__,
    MP_QSTR___qualname__,
    MP_QSTR_self,
    MP_QSTR_calcsize,
    MP_QSTR_buf,
};

static const mp_frozen_module_t frozen_module_struct = {
    .constants = {
        .qstr_table = (qstr_short_t *)&const_qstr_table_data_struct,
        .obj_table = NULL,
    },
    .rc = &raw_code_struct__lt_module_gt_,
};

////////////////////////////////////////////////////////////////////////////////
// collection of all frozen modules

const char mp_frozen_names[] = {
    #ifdef MP_FROZEN_STR_NAMES
    MP_FROZEN_STR_NAMES
    #endif
    "struct.py\0"
    "\0"
};

const mp_frozen_module_t *const mp_frozen_mpy_content[] = {
    &frozen_module_struct,
};

#ifdef MICROPY_FROZEN_LIST_ITEM
MICROPY_FROZEN_LIST_ITEM("struct", "struct.py")
#endif

/*
byte sizes:
qstr content: 5 unique, 49 bytes
bc content: 110
const str content: 0
const int content: 0
const obj content: 0
const table qstr content: 0 entries, 0 bytes
const table ptr content: 0 entries, 0 bytes
raw code content: 5 * 4 = 80
mp_frozen_mpy_names_content: 11
mp_frozen_mpy_content_size: 4
total: 254
*/
