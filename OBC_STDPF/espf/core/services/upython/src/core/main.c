/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup uPy
 * @{
 *
 * @file main.c
 * @brief OBC uPython port main implementation
 *
 * Provides:
 * - general initialization of the uPy instance (file system and heap memory)
 * - Python VFS instance initialization for OBC using fm_mng
 * - uPy script execution from file
 *
 * @}
 *
 */

#include <stdint.h>
#include <string.h>
#include <stdarg.h>

#include "py/builtin.h"
#include "py/compile.h"
#include "py/runtime.h"
#include "py/repl.h"
#include "py/gc.h"
#include "py/mperrno.h"
#include "py/objmodule.h"
#include "py/objstr.h"
#include "py/mphal.h"

#include "shared/runtime/pyexec.h"
#include "shared/runtime/gchelper.h"

#include "cmodules/fmng/vfs_es_fm_mng.h"
#include "extmod/misc.h"

#include "upy_obc_port.h"
#include "fm_mng.h"
#include "es_cdef.h"
#include "trace.h"
#include "assertions.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
#define IMPORT_MOD_SUCCESS         (0U)
#define IMPORT_MOD_ABORT_EXCEPTION (1U)
#define IMPORT_MOD_ABORT_TIME_OUT  (2U)
#define FORCED_EXIT                (0x100)

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
static void     stderr_print_strn(void *env, const char *str, size_t len);
static uint32_t handle_uncaught_exception(mp_obj_base_t *exc);

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

static const mp_print_t mp_stderr_print = { NULL, stderr_print_strn };

#if MICROPY_ENABLE_GC
static char heap[MICROPYTHON_HEAP_SIZE];
#endif

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
#if MICROPY_ENABLE_COMPILER
void do_str(const char *src, mp_parse_input_kind_t input_kind)
{
    nlr_buf_t nlr;
    if (nlr_push(&nlr) == 0)
    {
        mp_lexer_t     *lex         = mp_lexer_new_from_str_len(MP_QSTR__lt_stdin_gt_, src,
                                                                strlen(src), 0);
        qstr            source_name = lex->source_name;
        mp_parse_tree_t parse_tree  = mp_parse(lex, input_kind);
        mp_obj_t        module_fun  = mp_compile(&parse_tree, source_name, true);
        mp_call_function_0(module_fun);
        nlr_pop();
    }
    else
    {
        // uncaught exception
        mp_obj_print_exception(&mp_plat_print, (mp_obj_t)nlr.ret_val);
    }
}
#endif

#if MICROPY_ENABLE_GC
void gc_collect(void)
{
// get current time, in case we want to time the GC
#if 0
    uint32_t start = mp_hal_ticks_us();
#endif

    // start the GC
    gc_collect_start();

    // trace the stack and registers
    gc_helper_collect_regs_and_stack();

// trace root pointers from any threads
#if MICROPY_PY_THREAD
    mp_thread_gc_others();
#endif

    // trace soft timer nodes
    //    soft_timer_gc_mark_all();

    // end the GC
    gc_collect_end();

    gc_dump_info(&mp_plat_print);
}
#endif

void nlr_jump_fail(void *val)
{

    ES_TRACE_FATAL("FATAL: uncaught exception at address: %p\n",
                   (void *)*(uint32_t *)val);

    mp_obj_print_exception(&mp_plat_print, MP_OBJ_FROM_PTR(val));

    while (1)
    {
        CRIT_ASSERT(false);
    }
}

uint32_t import_module(const char *const module_name)
{
    uint32_t result = IMPORT_MOD_ABORT_EXCEPTION;
    mp_obj_t import_args[4];
    import_args[0] = mp_obj_new_str(module_name, strlen(module_name));
    import_args[1] = import_args[2] = mp_const_none;
    // Ask __import__ to handle imported module specially - set its __name__rt

    // to __main__, and also return this leaf module, not top-level package
    // containing it.
    import_args[3] = mp_const_false;
    // https://docs.python.org/3/using/cmdline.html#cmdoption-m :
    // "the first element of sys.argv will be the full path to
    // the module file (while the module file is being located,
    // the first element will be set to "-m")."

    nlr_buf_t nlr;
    if (nlr_push(&nlr) == 0)
    {
        // ensure there is a safe return path in case of VM abort via the mp_sched_vm_abort() call;
        // if this happens, we will end up in the else branch of this if block
        nlr_set_abort(&nlr);

        // all exceptions are handled in the else statement.
        (void)mp_builtin___import__(MP_ARRAY_SIZE(import_args), import_args);
        // It is assumed that everything is fine if we reach this step
        result = IMPORT_MOD_SUCCESS;
        nlr_pop();
    }
    else
    {
        // is this a regular Python exception?
        if (NULL != nlr.ret_val)
        {
            // uncaught exception
            (void)handle_uncaught_exception(nlr.ret_val);
        }
        else
        {
            // mp_sched_vm_abort() call was performed
            result = IMPORT_MOD_ABORT_TIME_OUT;
        }
    }

    return result;
}

int mp_vprintf(const mp_print_t *print, const char *fmt, va_list args);

int DEBUG_printf(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    int ret = mp_vprintf(MICROPY_DEBUG_PRINTER, fmt, ap);
    va_end(ap);
    return ret;
}

bool init_es_fm_mng_fs(void)
{
    bool result = false;
    // create vfs object
    fs_es_fm_mng_mount_t *vfs_es_fm_mng = m_new_obj_maybe(fs_es_fm_mng_mount_t);
    mp_vfs_mount_t       *vfs           = m_new_obj_maybe(mp_vfs_mount_t);
    if ((vfs != NULL) && (vfs_es_fm_mng != NULL))
    {
        if (false == fm_storage_status_ready(FM_VOL_SD_PATH))
        {
            // couldn't mount
            m_del_obj(fs_es_fm_mng_mount_t, vfs_es_fm_mng);
            m_del_obj(mp_vfs_mount_t, vfs);
        }
        else
        {
            vfs->str                    = FM_VOL_SD_PATH;
            vfs->len                    = strlen(FM_VOL_SD_PATH);
            vfs_es_fm_mng->vol_name     = FM_VOL_SD_PATH;
            vfs_es_fm_mng->vol_name_len = strlen(FM_VOL_SD_PATH);
            vfs_es_fm_mng->base.type    = &mp_es_fm_mng_vfs_type;

            vfs->obj = MP_OBJ_FROM_PTR(vfs_es_fm_mng);

            vfs->next          = NULL;
            mp_vfs_mount_t **m = &MP_STATE_VM(vfs_mount_table);
            while (NULL != (*m))
            {
                m = &(*m)->next;
            }
            *m = vfs;

            // use fm_mng as current directory
            MP_STATE_PORT(vfs_cur) = vfs;

            result = true;
        }
    }

    if (!result)
    {
        ES_TRACE_ERROR("MPY: can't mount SD card");
    }

    return result;
}

eObcPortResult_t upy_run(const char *const fp_pScriptName, uint8_t fp_u8NameLen)
{
    eObcPortResult_t result = UPY_ERROR;
    char             paName[fp_u8NameLen + 1]; // one symbol for null terminator

    if ((NULL != fp_pScriptName) && (0 != fp_u8NameLen))

    {
        // make sure that the Name is null terminated. This is done here
        // and further only the pointer to the null terminated string is passed
        strncpy(paName, fp_pScriptName, fp_u8NameLen + 1);

        MP_STATE_THREAD(stack_top) = (char *)&heap;

#if MICROPY_ENABLE_GC
        gc_init(heap, heap + sizeof(heap));
#endif
        mp_init();

        if (false != init_es_fm_mng_fs())
        {
            uint32_t import_res = import_module(paName);

            switch (import_res)
            {
                case IMPORT_MOD_SUCCESS:
                    {
                        result = UPY_OK;
                        break;
                    }

                case IMPORT_MOD_ABORT_TIME_OUT:
                    {
                        result = UPY_SCRIPT_TIMED_OUT;
                        break;
                    }

                default:
                    {
                        result = UPY_ERROR;
                        break;
                    }
            }
        }

        gc_dump_info(&mp_plat_print);

        mp_deinit();
    }
    else
    {
        result = UPY_WRONG_PARAMS;
    }

    return result;
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
static void stderr_print_strn(void *env, const char *str, size_t len)
{
    (void)env;
    mp_hal_stdout_tx_strn(str, len);
}

// If exc is SystemExit, return value where FORCED_EXIT bit set,
// and lower 8 bits are SystemExit value. For all other exceptions,
// return value of the exception.
static uint32_t handle_uncaught_exception(mp_obj_base_t *exc)
{
    // check for SystemExit
    uint32_t res = 1;

    // None is an exit value of 0; an int is its value; anything else is 1
    mp_const_obj_t exit_val = mp_obj_exception_get_value(MP_OBJ_FROM_PTR(exc));
    mp_int_t       val      = 0;
    if ((exit_val != mp_const_none) && (!mp_obj_get_int_maybe(exit_val, &val)))
    {
        val = 1;
    }

    if (true == mp_obj_is_subclass_fast(MP_OBJ_FROM_PTR(exc->type),
                                        MP_OBJ_FROM_PTR(&mp_type_SystemExit)))
    {
        res = FORCED_EXIT | ((uint32_t)val & 0xFF);
    }
    else
    {
        // Report all other exceptions
        mp_obj_print_exception(&mp_stderr_print, MP_OBJ_FROM_PTR(exc));

        res = ((uint32_t)val & 0xFF);
    }

    return res;
}
