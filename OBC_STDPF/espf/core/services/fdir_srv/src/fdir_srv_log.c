/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup fdir_srv
 * @{
 *
 * @file     fdir_srv_log.c
 * @brief    FDIR logging implementation
 *
 * @}
 */


#include "fdir_srv.h"
#include "fdir_srv_log.h"
#include "fdir_srv_internal.h"
#include "rlf.h"
#include "sys_time.h"
#include "cobs_inplace.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <assert.h>

/** @brief Name pattern for the rolling file used by the file trace channel */
#define FDIR_RLF_FILE_PATTERN "fdir.__.log"

/** @brief Maximum size of one instance of the rolling file */
#define FDIR_RLF_SIZE_PER_FILE (1<<20) // 1MB

/** @brief Maximum number of rolling file instances */
#define FDIR_RLF_FILE_COUNT (10)

/** @brief Index in the rolling file name pattern of the marker of active/inactive file */
#define FDIR_RLF_NAME_MARKER_POS (5)

/** @brief Index in the rolling file name pattern of the file instance index */
#define FDIR_RLF_NAME_INDEX_POS (6)

/** @brief Marker in the rolling file name for the currently active file */
#define FDIR_RLF_MARKER_ACTIVE 'o'

/** @brief Marker in the rolling file name for currently inactive files */
#define FDIR_RLF_MARKER_INACTIVE 'x'

/** @brief Marker in the rolling file name for currently inactive files */
#define FDIR_LOG_BUFFER_SIZE (256)

/**
 * @brief Configuration for the rolling file used by the FDIR log. See @ref rlf_cfg_t for details.
 */
static const rlf_cfg_t fdir_rlf_cfg =
{
    .max_size        = FDIR_RLF_SIZE_PER_FILE,
    .pattern         = FDIR_RLF_FILE_PATTERN,
    .pos_marker      = FDIR_RLF_NAME_MARKER_POS,
    .pos_index       = FDIR_RLF_NAME_INDEX_POS,
    .max_count       = FDIR_RLF_FILE_COUNT,
    .marker_active   = FDIR_RLF_MARKER_ACTIVE,
    .marker_inactive = FDIR_RLF_MARKER_INACTIVE,
};

/**
 * @brief File object for the currently active rolling file used by the FDIR log.
 */
static fm_file_obj_t fdir_rlf_file_obj;

/**
 * @brief Context for the rolling file used by the FDIR log. Se
 */
static rlf_ctx_t fdir_rlf_ctx =
{
    .filename                 = "",
    .p_cfg                    = &fdir_rlf_cfg,
    .current_index            = 0,
    .is_open                  = false,
    .handle                   = &fdir_rlf_file_obj,
    .use_internal_file_object = false,
    .index_strlen             = 0
};

/**
 * @brief Log a message to the FDIR log to be called by a ... log function.
 *
 * @param fault_id The fault ID. See @ref fdir_fault_id_t
 * @param agent_id The agent ID. See @ref fdir_agent_id_t
 * @param fmt The format string. Same as sprintf capabilities
 * @param ap A va_list var initialized by the caller with va_start()
 */
static void fdir_srv_vlog(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent_id, const char * fmt, va_list ap);

void fdir_srv_log_if_not_same(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent_id, bool cond, const char * fmt, ...)
{
    if (cond != fdir_faults_dyn[fault_id].fault_active)
    {
        va_list ap;
        va_start(ap, fmt);
        fdir_srv_vlog(fault_id, agent_id, fmt, ap);
        va_end(ap);
    }
}

void fdir_srv_log_if_raised(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent_id, const char * fmt, ...)
{
    if (true == fdir_faults_dyn[fault_id].fault_active)
    {
        va_list ap;
        va_start(ap, fmt);
        fdir_srv_vlog(fault_id, agent_id, fmt, ap);
        va_end(ap);
    }
}

void fdir_srv_log_if_clear(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent_id, const char * fmt, ...)
{
    if (false == fdir_faults_dyn[fault_id].fault_active)
    {
        va_list ap;
        va_start(ap, fmt);
        fdir_srv_vlog(fault_id, agent_id, fmt, ap);
        va_end(ap);
    }
}

void fdir_srv_log(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent_id, const char * fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fdir_srv_vlog(fault_id, agent_id, fmt, ap);
    va_end(ap);
}

static void fdir_srv_vlog(const fdir_fault_id_t fault_id, const fdir_agent_id_t agent_id, const char * fmt, va_list ap)
{
    char str[FDIR_LOG_BUFFER_SIZE];
    char * pc = str;
    size_t len;
    int ilen = 0;
    sys_date_t sys_date;
    sys_time_t sys_time;

    if ((true == fdir_srv_fault_is_detection_enabled(fault_id)) &&
        (FM_RES_OK == rlf_open(&fdir_rlf_ctx)))
    {
        sys_time_get_stamp(&sys_date, &sys_time);
        ilen += sprintf(pc, "%04u-%02u-%02u %02u-%02u-%02u,f:%2d,a:%2d, "
            , sys_date.year, sys_date.mon, sys_date.day
            , sys_time.hour, sys_time.min, sys_time.sec
            , fault_id, agent_id);
        pc += ilen;
        len = (size_t)ilen;
        ilen += vsnprintf(pc, sizeof(str) - len, fmt, ap);

        if (ilen > 0)
        {
            len = (size_t)ilen;
            if (len < sizeof(str) - 1)
            {
                strcat(str, "\n");
                len += 1;
            }
            else
            {
                strcpy(&str[sizeof(str) - 5], "...\n");
                len = sizeof(str);
            }
            rlf_write_unbroken(&fdir_rlf_ctx, str, len, NULL);
        }

        (void)rlf_close(&fdir_rlf_ctx);
    }
}
