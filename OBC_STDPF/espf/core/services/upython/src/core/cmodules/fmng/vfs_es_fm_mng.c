/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#include <py/mpconfig.h>
#if MICROPY_VFS_ES_FM_MNG

#include "vfs_es_fm_mng.h"
#include <py/mperrno.h>
#include <py/runtime.h>

#include "fm_mng.h"

#if !MICROPY_ENABLE_FINALISER
#error "MICROPY_VFS_ES_FM_MNG requires MICROPY_ENABLE_FINALISER"
#endif

#if !MICROPY_VFS
#error "with MICROPY_VFS_ES_FM_MNG enabled, must also enable MICROPY_VFS"
#endif

#include <string.h>
#include "shared/timeutils/timeutils.h"
#include "py/stream.h"
#include "py/obj.h"

#define ES_FM_MNG_RAWFILE_DICT_SIZE (12)
#define ES_FM_MNG_VFS_DICT_SIZE     (11)

typedef int errno_t;

// this table converts from fm_result_t to POSIX errno
static const errno_t fm_result_to_errno_table[FM_RES_COUNT] = {
    [FM_RES_OK]                  = 0,
    [FM_RES_DISK_ERR]            = MP_EIO,
    [FM_RES_INT_ERR]             = MP_EIO,
    [FM_RES_NOT_READY]           = MP_EBUSY,
    [FM_RES_NO_FILE]             = MP_ENOENT,
    [FM_RES_NO_PATH]             = MP_ENOENT,
    [FM_RES_INVALID_NAME]        = MP_EINVAL,
    [FM_RES_DENIED]              = MP_EACCES,
    [FM_RES_EXIST]               = MP_EEXIST,
    [FM_RES_INVALID_OBJECT]      = MP_EINVAL,
    [FM_RES_WRITE_PROTECTED]     = MP_EROFS,
    [FM_RES_INVALID_DRIVE]       = MP_ENODEV,
    [FM_RES_NOT_ENABLED]         = MP_ENODEV,
    [FM_RES_NO_FILESYSTEM]       = MP_ENODEV,
    [FM_RES_MKFS_ABORTED]        = MP_EIO,
    [FM_RES_TIMEOUT]             = MP_EIO,
    [FM_RES_LOCKED]              = MP_EIO,
    [FM_RES_NOT_ENOUGH_CORE]     = MP_ENOMEM,
    [FM_RES_TOO_MANY_OPEN_FILES] = MP_EMFILE,
    [FM_RES_INVALID_PARAMETER]   = MP_EINVAL,
};

typedef struct pyb_es_fm_mng_file_obj_tag
{
    mp_obj_base_t base;
    fm_file_obj_t fp;
} pyb_es_fm_mng_file_obj_t;

STATIC void file_obj_print(const mp_print_t *print, mp_obj_t self_in, mp_print_kind_t kind)
{
    (void)kind;
    mp_printf(print, "<io.%s %p>", mp_obj_get_type_str(self_in), MP_OBJ_TO_PTR(self_in));
}

STATIC mp_uint_t file_obj_read(mp_obj_t self_in, void *buf, mp_uint_t size, int *errcode)
{
    pyb_es_fm_mng_file_obj_t *self = MP_OBJ_TO_PTR(self_in);
    uint32_t                  sz_out;
    fm_result_t               res = fm_read(&self->fp, buf, size, &sz_out);
    if (res != FM_RES_OK)
    {
        *errcode = fm_result_to_errno_table[res];
        return MP_STREAM_ERROR;
    }
    return sz_out;
}

STATIC mp_uint_t file_obj_write(mp_obj_t self_in, const void *buf, mp_uint_t size, int *errcode)
{
    pyb_es_fm_mng_file_obj_t *self = MP_OBJ_TO_PTR(self_in);
    uint32_t                  sz_out;
    fm_result_t               res = fm_write(&self->fp, buf, size, &sz_out);
    if (res != FM_RES_OK)
    {
        *errcode = fm_result_to_errno_table[res];
        return MP_STREAM_ERROR;
    }
    if (sz_out != size)
    {
        *errcode = MP_ENOSPC;
        return MP_STREAM_ERROR;
    }
    return sz_out;
}

STATIC mp_uint_t file_obj_ioctl_stream_seek(mp_obj_t o_in, uintptr_t arg, int *errcode)
{
    pyb_es_fm_mng_file_obj_t *self = MP_OBJ_TO_PTR(o_in);
    struct mp_stream_seek_t  *s    = (struct mp_stream_seek_t *)arg;
    uint32_t                  pos;
    fm_result_t               res = FM_RES_INVALID_PARAMETER;

    switch (s->whence)
    {
        case MP_SEEK_SET:
            res = fm_seek(&self->fp, (uint32_t)s->offset);
            break;
        case MP_SEEK_CUR:
            res = fm_tell(&self->fp, &pos);
            if (FM_RES_OK == res)
            {
                res = fm_seek(&self->fp, pos + (uint32_t)s->offset);
            }
            break;
        case MP_SEEK_END:
            res = fm_size(&self->fp, &pos);
            if (FM_RES_OK == res)
            {
                res = fm_seek(&self->fp, pos + (uint32_t)s->offset);
            }
            break;
        default:;
    }
    if (FM_RES_OK == res)
    {
        res = fm_tell(&self->fp, &pos);
    }
    if (FM_RES_OK == res)
    {
        s->offset = (mp_off_t)pos;
    }
    else
    {
        *errcode = fm_result_to_errno_table[res];
    }

    return 0;
}

STATIC mp_uint_t file_obj_ioctl_flush(mp_obj_t o_in, int *errcode)
{
    pyb_es_fm_mng_file_obj_t *self = MP_OBJ_TO_PTR(o_in);
    fm_result_t               res  = fm_sync(&self->fp);
    if (res != FM_RES_OK)
    {
        *errcode = fm_result_to_errno_table[res];
        return MP_STREAM_ERROR;
    }
    return 0;
}

STATIC mp_uint_t file_obj_ioctl_close(mp_obj_t o_in, int *errcode)
{
    pyb_es_fm_mng_file_obj_t *self = MP_OBJ_TO_PTR(o_in);
    fm_result_t               res  = fm_close(&self->fp);
    if (res != FM_RES_OK)
    {
        *errcode = fm_result_to_errno_table[res];
        return MP_STREAM_ERROR;
    }
    return 0;
}

STATIC mp_uint_t file_obj_ioctl(mp_obj_t o_in, mp_uint_t request, uintptr_t arg, int *errcode)
{
    mp_uint_t ret = MP_STREAM_ERROR;

    switch (request)
    {
        case MP_STREAM_SEEK:
            ret = file_obj_ioctl_stream_seek(o_in, arg, errcode);
            break;
        case MP_STREAM_FLUSH:
            ret = file_obj_ioctl_flush(o_in, errcode);
            break;
        case MP_STREAM_CLOSE:
            ret = file_obj_ioctl_close(o_in, errcode);
            break;
        default:;
            *errcode = MP_EINVAL;
    }
    return ret;
}

STATIC const mp_rom_map_elem_t vfs_es_fm_mng_rawfile_locals_dict_table[ES_FM_MNG_RAWFILE_DICT_SIZE] = {
    {MP_ROM_QSTR(MP_QSTR_read),       MP_ROM_PTR(&mp_stream_read_obj)                },
    { MP_ROM_QSTR(MP_QSTR_readinto),  MP_ROM_PTR(&mp_stream_readinto_obj)            },
    { MP_ROM_QSTR(MP_QSTR_readline),  MP_ROM_PTR(&mp_stream_unbuffered_readline_obj) },
    { MP_ROM_QSTR(MP_QSTR_readlines), MP_ROM_PTR(&mp_stream_unbuffered_readlines_obj)},
    { MP_ROM_QSTR(MP_QSTR_write),     MP_ROM_PTR(&mp_stream_write_obj)               },
    { MP_ROM_QSTR(MP_QSTR_flush),     MP_ROM_PTR(&mp_stream_flush_obj)               },
    { MP_ROM_QSTR(MP_QSTR_close),     MP_ROM_PTR(&mp_stream_close_obj)               },
    { MP_ROM_QSTR(MP_QSTR_seek),      MP_ROM_PTR(&mp_stream_seek_obj)                },
    { MP_ROM_QSTR(MP_QSTR_tell),      MP_ROM_PTR(&mp_stream_tell_obj)                },
    { MP_ROM_QSTR(MP_QSTR___del__),   MP_ROM_PTR(&mp_stream_close_obj)               },
    { MP_ROM_QSTR(MP_QSTR___enter__), MP_ROM_PTR(&mp_identity_obj)                   },
    { MP_ROM_QSTR(MP_QSTR___exit__),  MP_ROM_PTR(&mp_stream___exit___obj)            },
};

STATIC MP_DEFINE_CONST_DICT(vfs_es_fm_mng_rawfile_locals_dict, vfs_es_fm_mng_rawfile_locals_dict_table);

STATIC const mp_stream_p_t vfs_es_fm_mng_fileio_stream_p = {
    .read    = file_obj_read,
    .write   = file_obj_write,
    .ioctl   = file_obj_ioctl,
    .is_text = 0,
};

MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_vfs_es_fm_mng_fileio,
    MP_QSTR_FileIO,
    MP_TYPE_FLAG_ITER_IS_STREAM,
    print, file_obj_print,
    protocol, &vfs_es_fm_mng_fileio_stream_p,
    locals_dict, &vfs_es_fm_mng_rawfile_locals_dict);

STATIC mp_obj_t es_fm_mng_vfs_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args)
{
    mp_arg_check_num(n_args, n_kw, 1, 1, false);

    (void)args;

    fs_es_fm_mng_mount_t *p_vfs_obj = NULL;
    mp_vfs_mount_t       *p_sys_vfs = MP_STATE_PORT(vfs_cur);

    if ((NULL == p_sys_vfs) || ((NULL != p_sys_vfs) && (NULL == p_sys_vfs->obj)))
    {
        // create new object
        fs_es_fm_mng_mount_t *p_new_vfs_inst = mp_obj_malloc(fs_es_fm_mng_mount_t, type);
        p_new_vfs_inst->vol_name             = (const char *)FM_VOL_SD_PATH;
        p_new_vfs_inst->vol_name_len         = strlen(FM_VOL_SD_PATH);
        p_new_vfs_inst->base.type            = &mp_es_fm_mng_vfs_type;

        // simply check that the filesystem is ready
        bool res = fm_storage_status_ready(p_new_vfs_inst->vol_name);
        if (false == res)
        {
            mp_raise_OSError(fm_result_to_errno_table[FM_RES_NO_FILESYSTEM]);
        }

        p_vfs_obj = p_new_vfs_inst;
    }
    else
    {
        p_vfs_obj = p_sys_vfs->obj;
    }

    return MP_OBJ_FROM_PTR(p_vfs_obj);
}

STATIC mp_obj_t es_fm_mng_vfs_mkfs(mp_obj_t bdev_in)
{
    // create new object
    const fs_es_fm_mng_mount_t *vfs = MP_OBJ_TO_PTR(es_fm_mng_vfs_make_new(&mp_es_fm_mng_vfs_type, 1, 0, &bdev_in));

    // make the filesystem
    fm_result_t res = fm_format(vfs->vol_name);
    if (FM_RES_OK != res)
    {
        mp_raise_OSError(fm_result_to_errno_table[res]);
    }

    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(es_fm_mng_vfs_mkfs_fun_obj, es_fm_mng_vfs_mkfs);
STATIC MP_DEFINE_CONST_STATICMETHOD_OBJ(es_fm_mng_vfs_mkfs_obj, MP_ROM_PTR(&es_fm_mng_vfs_mkfs_fun_obj));

// Factory function for I/O stream classes
STATIC mp_obj_t es_fm_mng_vfs_open(mp_obj_t self_in, mp_obj_t path_in, mp_obj_t mode_in)
{
    const fs_es_fm_mng_mount_t *self = MP_OBJ_TO_PTR(self_in);

    const mp_obj_type_t *type   = &mp_type_vfs_es_fm_mng_fileio;
    uint32_t             mode   = 0;
    const char          *mode_s = mp_obj_str_get_str(mode_in);
    while (0 != *mode_s)
    {
        switch (*mode_s)
        {
            case 'r':
                mode |= FM_MODE_READ;
                break;
            case 'w':
                mode |= FM_MODE_WRITE | FM_MODE_CREATE_ALWAYS;
                break;
            case 'x':
                mode |= FM_MODE_WRITE | FM_MODE_CREATE_NEW;
                break;
            case 'a':
                mode |= FM_MODE_WRITE | FM_MODE_OPEN_APPEND;
                break;
            case '+':
                mode |= FM_MODE_READ | FM_MODE_WRITE;
                break;
            default:;
        }
        mode_s++;
    }

    pyb_es_fm_mng_file_obj_t *o = m_new_obj_with_finaliser(pyb_es_fm_mng_file_obj_t);
    o->base.type                = type;

    const char *fname = mp_obj_str_get_str(path_in);
    char        namebuf[FM_MAX_PATH];
    char       *pc = namebuf;
    (void)strncpy(pc, self->vol_name, sizeof(namebuf) - 1);
    pc[sizeof(namebuf) - 1]    = '\0';
    size_t char_left_for_fname = FM_MAX_PATH - self->vol_name_len;
    size_t fnamelen            = strnlen(fname, char_left_for_fname);
    if (fnamelen < char_left_for_fname)
    {
        pc += self->vol_name_len;
        *pc = '/';
        pc++;
        strncpy(pc, fname, fnamelen);
        pc[fnamelen]    = '\0';
        fm_result_t res = fm_open(&o->fp, namebuf, mode);
        if (res != FM_RES_OK)
        {
            m_del_obj(pyb_es_fm_mng_file_obj_t, o);
            mp_raise_OSError(fm_result_to_errno_table[res]);
        }
    }
    else
    {
        m_del_obj(pyb_es_fm_mng_file_obj_t, o);
        mp_raise_OSError(fm_result_to_errno_table[FM_RES_INVALID_NAME]);
    }

    return MP_OBJ_FROM_PTR(o);
}
MP_DEFINE_CONST_FUN_OBJ_3(es_fm_mng_vfs_open_obj, es_fm_mng_vfs_open);

typedef struct mp_vfs_es_fm_mng_ilistdir_it_tag
{
    mp_obj_base_t base;
    mp_fun_1_t    iternext;
    mp_fun_1_t    finaliser;
    bool          is_str;
    bool          is_iter;
    fm_dir_obj_t  dir;
} mp_vfs_es_fm_mng_ilistdir_it_t;

STATIC mp_obj_t mp_vfs_es_fm_mng_ilistdir_it_iternext(mp_obj_t self_in)
{
    mp_vfs_es_fm_mng_ilistdir_it_t *self = MP_OBJ_TO_PTR(self_in);

    do
    {
        fm_file_info_t fno;
        fm_result_t    res;

        res = fm_dir_next(&self->dir, &fno);

        const char *fn = fno.full_path;
        if ((res != FM_RES_OK) || (fn[0] == 0))
        {
            // stop on error or end of dir
            break;
        }

        // make 4-tuple with info about this entry
        mp_obj_tuple_t *t = MP_OBJ_TO_PTR(mp_obj_new_tuple(4, NULL));
        if (true == self->is_str)
        {
            t->items[0] = mp_obj_new_str(fn, strnlen(fn, FM_MAX_PATH - 1));
        }
        else
        {
            t->items[0] = mp_obj_new_bytes((const byte *)fn, strnlen(fn, FM_MAX_PATH - 1));
        }
        if (FM_ATTR_DIR == (fno.attr & FM_ATTR_DIR))
        {
            // dir
            t->items[1] = MP_OBJ_NEW_SMALL_INT(MP_S_IFDIR);
        }
        else
        {
            // file
            t->items[1] = MP_OBJ_NEW_SMALL_INT(MP_S_IFREG);
        }
        t->items[2] = MP_OBJ_NEW_SMALL_INT(0); // no inode number
        t->items[3] = mp_obj_new_int_from_uint(fno.size);

        return MP_OBJ_FROM_PTR(t);
    } while (0);

    // ignore error because we may be closing a second time
    (void)fm_dir_close(&self->dir);

    return MP_OBJ_STOP_ITERATION;
}

STATIC mp_obj_t mp_vfs_es_fm_mng_ilistdir_it_del(mp_obj_t self_in)
{
    mp_vfs_es_fm_mng_ilistdir_it_t *self = MP_OBJ_TO_PTR(self_in);
    // ignore result / error because we may be closing a second time.
    (void)fm_dir_close(&self->dir);
    return mp_const_none;
}

STATIC mp_obj_t es_fm_mng_vfs_ilistdir_func(size_t n_args, const mp_obj_t *args)
{
    bool        is_str_type = true;
    const char *path;
    if (n_args == 2)
    {
        if (mp_obj_get_type(args[1]) == &mp_type_bytes)
        {
            is_str_type = false;
        }
        path = mp_obj_str_get_str(args[1]);
    }
    else
    {
        path = "";
    }

    // Create a new iterator object to list the dir
    mp_vfs_es_fm_mng_ilistdir_it_t *iter = m_new_obj_with_finaliser(mp_vfs_es_fm_mng_ilistdir_it_t);
    iter->base.type                      = &mp_type_polymorph_iter_with_finaliser;
    iter->iternext                       = mp_vfs_es_fm_mng_ilistdir_it_iternext;
    iter->finaliser                      = mp_vfs_es_fm_mng_ilistdir_it_del;
    iter->is_str                         = is_str_type;
    iter->is_iter                        = true;
    fm_result_t res;
    res = fm_stat(path, NULL);
    if (FM_RES_OK == res)
    {
        res = fm_dir_open(&iter->dir, path, "*");
    }
    if (FM_RES_OK != res)
    {
        mp_raise_OSError(fm_result_to_errno_table[res]);
    }

    return MP_OBJ_FROM_PTR(iter);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(es_fm_mng_vfs_ilistdir_obj, 1, 2, es_fm_mng_vfs_ilistdir_func);

STATIC mp_obj_t es_fm_mng_vfs_mkdir(mp_obj_t vfs_in, mp_obj_t path_o)
{
    (void)vfs_in;
    const char *path = mp_obj_str_get_str(path_o);
    fm_result_t res  = fm_mkdir(path);
    if (res == FM_RES_OK)
    {
        return mp_const_none;
    }
    else
    {
        mp_raise_OSError(fm_result_to_errno_table[res]);
    }
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(es_fm_mng_vfs_mkdir_obj, es_fm_mng_vfs_mkdir);

STATIC mp_obj_t es_fm_mng_vfs_remove_internal(mp_obj_t vfs_in, mp_obj_t path_in, mp_int_t attr)
{
    (void)vfs_in;
    const char *path = mp_obj_str_get_str(path_in);

    fm_fast_file_info_t fno;
    fm_result_t         res = fm_stat(path, &fno);

    if (res != FM_RES_OK)
    {
        mp_raise_OSError(fm_result_to_errno_table[res]);
    }

    // check if path is a file or directory
    if ((fno.attr & FM_ATTR_DIR) == attr)
    {
        res = fm_delete(path);

        if (res != FM_RES_OK)
        {
            mp_raise_OSError(fm_result_to_errno_table[res]);
        }
        return mp_const_none;
    }
    else
    {
        mp_raise_OSError((FM_ATTR_DIR == (((uint32_t)attr) & FM_ATTR_DIR)) ? MP_ENOTDIR : MP_EISDIR);
    }
}

STATIC mp_obj_t es_fm_mng_vfs_remove(mp_obj_t vfs_in, mp_obj_t path_in)
{
    return es_fm_mng_vfs_remove_internal(vfs_in, path_in, 0); // 0 == file attribute
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(es_fm_mng_vfs_remove_obj, es_fm_mng_vfs_remove);

STATIC mp_obj_t es_fm_mng_vfs_rmdir(mp_obj_t vfs_in, mp_obj_t path_in)
{
    return es_fm_mng_vfs_remove_internal(vfs_in, path_in, FM_ATTR_DIR);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(es_fm_mng_vfs_rmdir_obj, es_fm_mng_vfs_rmdir);

STATIC mp_obj_t es_fm_mng_vfs_rename(mp_obj_t vfs_in, mp_obj_t path_in, mp_obj_t path_out)
{
    const char *old_path = mp_obj_str_get_str(path_in);
    const char *new_path = mp_obj_str_get_str(path_out);
    fm_result_t res      = fm_rename(old_path, new_path);
    if (res == FM_RES_EXIST)
    {
        // if new_path exists then try removing it (but only if it's a file)
        es_fm_mng_vfs_remove_internal(vfs_in, path_out, 0); // 0 == file attribute
        // try to rename again
        res = fm_rename(old_path, new_path);
    }
    if (res == FM_RES_OK)
    {
        return mp_const_none;
    }
    else
    {
        mp_raise_OSError(fm_result_to_errno_table[res]);
    }
}
STATIC MP_DEFINE_CONST_FUN_OBJ_3(es_fm_mng_vfs_rename_obj, es_fm_mng_vfs_rename);

// Get the status of a file or directory.
STATIC mp_obj_t es_fm_mng_vfs_stat(mp_obj_t vfs_in, mp_obj_t path_in)
{
    (void)vfs_in;
    const char *path = mp_obj_str_get_str(path_in);

    fm_fast_file_info_t fno;
    if ((path[0] == 0) || ((path[0] == '/') && (path[1] == 0)))
    {
        // stat root directory
        fno.size       = 0;
        fno.unix_mtime = 0x2821; // Jan 1, 2000
        fno.attr       = FM_ATTR_DIR;
    }
    else
    {
        fm_result_t res = fm_stat(path, &fno);
        if (res != FM_RES_OK)
        {
            mp_raise_OSError(fm_result_to_errno_table[res]);
        }
    }

    mp_obj_tuple_t *t    = MP_OBJ_TO_PTR(mp_obj_new_tuple(10, NULL));
    mp_uint_t       mode = 0;
    if (FM_ATTR_DIR == (fno.attr & FM_ATTR_DIR))
    {
        mode |= MP_S_IFDIR;
    }
    else
    {
        mode |= MP_S_IFREG;
    }

    t->items[0] = MP_OBJ_NEW_SMALL_INT(mode);               // st_mode
    t->items[1] = MP_OBJ_NEW_SMALL_INT(0);                  // st_ino
    t->items[2] = MP_OBJ_NEW_SMALL_INT(0);                  // st_dev
    t->items[3] = MP_OBJ_NEW_SMALL_INT(0);                  // st_nlink
    t->items[4] = MP_OBJ_NEW_SMALL_INT(0);                  // st_uid
    t->items[5] = MP_OBJ_NEW_SMALL_INT(0);                  // st_gid
    t->items[6] = mp_obj_new_int_from_uint(fno.size);       // st_size
    t->items[7] = mp_obj_new_int_from_uint(fno.unix_mtime); // st_atime
    t->items[8] = mp_obj_new_int_from_uint(fno.unix_mtime); // st_mtime
    t->items[9] = mp_obj_new_int_from_uint(fno.unix_mtime); // st_ctime

    return MP_OBJ_FROM_PTR(t);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(es_fm_mng_vfs_stat_obj, es_fm_mng_vfs_stat);

// Get the status of a VFS.
STATIC mp_obj_t es_fm_mng_vfs_statvfs(mp_obj_t vfs_in, mp_obj_t path_in)
{
    const fs_es_fm_mng_mount_t *self = MP_OBJ_TO_PTR(vfs_in);
    (void)path_in;

    uint32_t    free_kb;
    fm_result_t res = fm_get_free(self->vol_name, &free_kb);
    if (FM_RES_OK != res)
    {
        mp_raise_OSError(fm_result_to_errno_table[res]);
    }

    mp_obj_tuple_t *t = MP_OBJ_TO_PTR(mp_obj_new_tuple(10, NULL));

    t->items[0] = MP_OBJ_NEW_SMALL_INT(1024);        // f_bsize
    t->items[1] = MP_OBJ_NEW_SMALL_INT(0);           // f_frsize
    t->items[2] = MP_OBJ_NEW_SMALL_INT(0);           // f_blocks
    t->items[3] = MP_OBJ_NEW_SMALL_INT(free_kb);     // f_bfree
    t->items[4] = MP_OBJ_NEW_SMALL_INT(0);           // f_bavail
    t->items[5] = MP_OBJ_NEW_SMALL_INT(0);           // f_files
    t->items[6] = MP_OBJ_NEW_SMALL_INT(0);           // f_ffree
    t->items[7] = MP_OBJ_NEW_SMALL_INT(0);           // f_favail
    t->items[8] = MP_OBJ_NEW_SMALL_INT(0);           // f_flags
    t->items[9] = MP_OBJ_NEW_SMALL_INT(FM_MAX_PATH); // f_namemax

    return MP_OBJ_FROM_PTR(t);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(es_fm_mng_vfs_statvfs_obj, es_fm_mng_vfs_statvfs);

STATIC mp_obj_t vfs_es_fm_mng_mount(mp_obj_t self_in, mp_obj_t readonly, mp_obj_t mkfs)
{
    (void)readonly;
    (void)mkfs;
    const fs_es_fm_mng_mount_t *self = MP_OBJ_TO_PTR(self_in);

    if (false == fm_storage_status_ready(self->vol_name))
    {
        mp_raise_OSError(fm_result_to_errno_table[FM_RES_NO_FILESYSTEM]);
    }

    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_3(vfs_es_fm_mng_mount_obj, vfs_es_fm_mng_mount);

STATIC mp_obj_t vfs_es_fm_mng_umount(mp_obj_t self_in)
{
    (void)self_in;
    // keep the ES_FM_MNG filesystem mounted internally so the VFS methods can still be used
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(es_fm_mng_vfs_umount_obj, vfs_es_fm_mng_umount);

STATIC mp_import_stat_t es_fm_mng_vfs_import_stat(void *vfs_in, const char *path)
{
    (void)vfs_in;
    fm_fast_file_info_t fno;
    fm_result_t         res = fm_stat(path, &fno);
    if (res == FM_RES_OK)
    {
        if ((fno.attr & FM_ATTR_DIR) != 0)
        {
            return MP_IMPORT_STAT_DIR;
        }
        else
        {
            return MP_IMPORT_STAT_FILE;
        }
    }
    return MP_IMPORT_STAT_NO_EXIST;
}

STATIC const mp_rom_map_elem_t es_fm_mng_vfs_locals_dict_table[ES_FM_MNG_VFS_DICT_SIZE] = {
    {MP_ROM_QSTR(MP_QSTR_mkfs),      MP_ROM_PTR(&es_fm_mng_vfs_mkfs_obj)    },
    { MP_ROM_QSTR(MP_QSTR_open),     MP_ROM_PTR(&es_fm_mng_vfs_open_obj)    },
    { MP_ROM_QSTR(MP_QSTR_ilistdir), MP_ROM_PTR(&es_fm_mng_vfs_ilistdir_obj)},
    { MP_ROM_QSTR(MP_QSTR_mkdir),    MP_ROM_PTR(&es_fm_mng_vfs_mkdir_obj)   },
    { MP_ROM_QSTR(MP_QSTR_rmdir),    MP_ROM_PTR(&es_fm_mng_vfs_rmdir_obj)   },
    { MP_ROM_QSTR(MP_QSTR_remove),   MP_ROM_PTR(&es_fm_mng_vfs_remove_obj)  },
    { MP_ROM_QSTR(MP_QSTR_rename),   MP_ROM_PTR(&es_fm_mng_vfs_rename_obj)  },
    { MP_ROM_QSTR(MP_QSTR_stat),     MP_ROM_PTR(&es_fm_mng_vfs_stat_obj)    },
    { MP_ROM_QSTR(MP_QSTR_statvfs),  MP_ROM_PTR(&es_fm_mng_vfs_statvfs_obj) },
    { MP_ROM_QSTR(MP_QSTR_mount),    MP_ROM_PTR(&vfs_es_fm_mng_mount_obj)   },
    { MP_ROM_QSTR(MP_QSTR_umount),   MP_ROM_PTR(&es_fm_mng_vfs_umount_obj)  },
};
STATIC MP_DEFINE_CONST_DICT(es_fm_mng_vfs_locals_dict, es_fm_mng_vfs_locals_dict_table);

STATIC const mp_vfs_proto_t es_fm_mng_vfs_proto = {
    .import_stat = &es_fm_mng_vfs_import_stat,
};

MP_DEFINE_CONST_OBJ_TYPE(
    mp_es_fm_mng_vfs_type,
    MP_QSTR_Vfs_es_fm_mng,
    MP_TYPE_FLAG_NONE,
    make_new, es_fm_mng_vfs_make_new,
    protocol, &es_fm_mng_vfs_proto,
    locals_dict, &es_fm_mng_vfs_locals_dict);

STATIC const mp_rom_map_elem_t fmng_module_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_fmng)              },
 // VFS actually relies on the use of mount() to apply file system formatting but
  // OBC doesn't support mount/unmount through uPy at this time, so we export the mkfs() operation
  // separately.
    { MP_ROM_QSTR(MP_QSTR_mkfs),    MP_ROM_PTR(&es_fm_mng_vfs_mkfs_fun_obj)},
 // The following lines provide VFS mapping to the es_fm_mng_vfs wrappers (VFS will route the calls through the
  // VFS instance created before the uPy VM is initialized (see init_es_fm_mng_fs() function which
  // initializes the uPy standard VFS object to our specific mp_es_fm_mng_vfs_type implementation.
  // This way we don't need a mp_es_fm_mng_vfs_type instance to call those operations as the
  // correct VFS object singleton instance will be provided internally by the VFS implementation.
    { MP_ROM_QSTR(MP_QSTR_listdir), MP_ROM_PTR(&mp_vfs_listdir_obj)        },
    { MP_ROM_QSTR(MP_QSTR_mkdir),   MP_ROM_PTR(&mp_vfs_mkdir_obj)          },
    { MP_ROM_QSTR(MP_QSTR_remove),  MP_ROM_PTR(&mp_vfs_remove_obj)         },
    { MP_ROM_QSTR(MP_QSTR_rename),  MP_ROM_PTR(&mp_vfs_rename_obj)         },
    { MP_ROM_QSTR(MP_QSTR_rmdir),   MP_ROM_PTR(&mp_vfs_rmdir_obj)          },
    { MP_ROM_QSTR(MP_QSTR_stat),    MP_ROM_PTR(&mp_vfs_stat_obj)           },
    { MP_ROM_QSTR(MP_QSTR_statvfs), MP_ROM_PTR(&mp_vfs_statvfs_obj)        },
};

STATIC MP_DEFINE_CONST_DICT(fmng_module_globals, fmng_module_globals_table);

// Define module object.
const mp_obj_module_t fmng_user_cmodule = {
    .base    = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&fmng_module_globals,
};

// Register the module to make it available in Python.
MP_REGISTER_MODULE(MP_QSTR_fmng, fmng_user_cmodule);

#endif // MICROPY_VFS_ES_FM_MNG
