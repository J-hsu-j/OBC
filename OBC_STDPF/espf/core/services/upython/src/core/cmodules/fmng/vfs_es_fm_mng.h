/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */


#ifndef MICROPY_INCLUDED_EXTMOD_VFS_ES_FM_MNG_H
#define MICROPY_INCLUDED_EXTMOD_VFS_ES_FM_MNG_H

#include "py/obj.h"
#include "extmod/vfs.h"

typedef struct fs_es_fm_mng_mount_tag
{
    mp_obj_base_t base;
    const char* vol_name;
    size_t vol_name_len;
} fs_es_fm_mng_mount_t;

extern const mp_obj_type_t mp_es_fm_mng_vfs_type;
extern const mp_obj_type_t mp_type_vfs_es_fm_mng_fileio;

#endif // MICROPY_INCLUDED_EXTMOD_VFS_ES_FM_MNG_H