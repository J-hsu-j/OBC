/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup sdr
 * @{
 *
 * @file sdr_op.c
 * @brief SDR operation definition module
 *
 * @}
 *
 */

#include "sdr_op.h"
#include "sdr_critical.h"
#include "sdr_sm_user.h"
#include "fm_mng.h"
#include "es_cdef.h"
#include "cmsis_os2.h"
#include "assertions.h"
#include "datacache.h"
#include "fdir_srv.h"
#include "fdir_srv_log.h"
#include "trace.h"
#include "essdr.h"
#include "sdr_sm_config_user.h"
#include "sys_time.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/

/** sdr file operation buffers */
static sdr_ft_op_t sdr_ft_op = { 0 };
static char        sdr_file[SDR_MAX_FILE_NAME_LEN];
static char        obc_file[OBC_MAX_FILE_NAME_LEN];

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/
/** @brief Check if a file from an sdr download operation is empty */
static bool downloaded_file_is_empty(const char *obc_file);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/
es_tftp_err_code_t sdr_download(const sdr_file_op_t *file_op)
{
    es_tftp_err_code_t sdr_ft_status = ES_TFTP_ERR_NOT_DEFINED;
    fm_result_t        fm_res        = FM_RES_DISK_ERR;

    BREAK_ASSERT(NULL != file_op);

    if (NULL != file_op)
    {
        if (true == sdr_critical_enter(SDR_LOCK_OP_STAT_TIMEOUT_MS))
        {
            ES_TRACE_DEBUG("sdr> initiating file download");
            sdr_rt_context.sdr_ft_status = es_sdr_client_file_download(file_op->sdr_file, file_op->obc_file);

            if (ES_TFTP_STATUS_OK != sdr_rt_context.sdr_ft_status)
            {
                ES_TRACE_ERROR("sdr> file download failed: %d", sdr_rt_context.sdr_ft_status);

                DATA_CACHE_FDIR_SDR_CMD_EXEC_STATUS_t exec_status;
                exec_status.bError_occured = true;

                fdir_srv_log(FDIR_FAULT_SDR_CMD_EXEC_FAILURE, FDIR_AGENT_SDR, "sdr> file download failed with err code %d, sdr file: \"%s\", obc file: \"%s\"",
                             sdr_rt_context.sdr_ft_status,
                             file_op->sdr_file,
                             file_op->obc_file);

                dc_set_fdir_sdr_cmd_exec_status_data(&exec_status);
                (void)dc_get_fdir_sdr_cmd_exec_status_data(&exec_status);
                (void)fdir_srv_fault_set_state(FDIR_FAULT_SDR_CMD_EXEC_FAILURE, FDIR_AGENT_SDR, exec_status.bError_occured, NULL);

                // only delete the file if the transfer failed AND the file is empty
                if (downloaded_file_is_empty(file_op->obc_file))
                {
                    (void)fm_delete(file_op->obc_file);
                }
            }
            else
            {
                fm_fast_file_info_t file_info = { 0 };

                // check file is downloaded and size > 0 bytes then return status accordingly
                fm_res = fm_stat(file_op->obc_file, &file_info);

                if (FM_RES_OK == fm_res)
                {
                    sdr_rt_context.sdr_ft_status = ES_TFTP_STATUS_OK;
                    ES_TRACE_DEBUG("sdr> file download complete");
                }
                if (file_info.size <= 0)
                {
                    sdr_rt_context.sdr_ft_status = ES_TFTP_DOWNLOADED_FILE_EMPTY;
                }
            }
            sdr_ft_status = sdr_rt_context.sdr_ft_status;
            sdr_critical_exit();
        }
        else
        {
            // there is an ongoing operation
            sdr_ft_status = ES_TFTP_BUSY;
        }
    }
    return sdr_ft_status;
}

es_tftp_err_code_t sdr_upload(const sdr_file_op_t *file_op)
{
    BREAK_ASSERT(NULL != file_op);

    es_tftp_err_code_t sdr_ft_status = ES_TFTP_ERR_NOT_DEFINED;

    if (NULL != file_op)
    {
        if (true == sdr_critical_enter(SDR_LOCK_OP_STAT_TIMEOUT_MS))
        {
            fm_fast_file_info_t file_info = { 0 };

            // check if file exists and initiate upload if it does
            if (FM_RES_OK == fm_stat(file_op->obc_file, &file_info))
            {
                ES_TRACE_DEBUG("sdr> initiating file upload");
                sdr_rt_context.sdr_ft_status = es_sdr_client_file_upload(file_op->obc_file, file_op->sdr_file);

                if (ES_TFTP_STATUS_OK != sdr_rt_context.sdr_ft_status)
                {
                    ES_TRACE_ERROR("sdr> file upload failed: %d", sdr_rt_context.sdr_ft_status);

                    DATA_CACHE_FDIR_SDR_CMD_EXEC_STATUS_t exec_status;
                    exec_status.bError_occured = true;

                    fdir_srv_log(FDIR_FAULT_SDR_CMD_EXEC_FAILURE, FDIR_AGENT_SDR, "sdr> file upload failed with err code %d, sdr file: \"%s\", obc file: \"%s\"",
                                 sdr_rt_context.sdr_ft_status,
                                 file_op->sdr_file,
                                 file_op->obc_file);

                    dc_set_fdir_sdr_cmd_exec_status_data(&exec_status);
                    (void)dc_get_fdir_sdr_cmd_exec_status_data(&exec_status);
                    (void)fdir_srv_fault_set_state(FDIR_FAULT_SDR_CMD_EXEC_FAILURE, FDIR_AGENT_SDR, exec_status.bError_occured, NULL);
                }
                else
                {
                    ES_TRACE_DEBUG("sdr> file upload complete");
                }
            }
            else
            {
                sdr_rt_context.sdr_ft_status = ES_TFTP_FILE_NOT_FOUND_ON_SOURCE;
            }
            sdr_ft_status = sdr_rt_context.sdr_ft_status;
            sdr_critical_exit();
        }
        else
        {
            // there is an ongoing operation
            sdr_ft_status = ES_TFTP_BUSY;
        }
    }

    return sdr_ft_status;
}

es_tftp_err_code_t sdr_poll_file_transfer_status(void)
{
    es_tftp_err_code_t current_status = ES_TFTP_ERR_NOT_DEFINED;

    if (true == sdr_critical_enter(SDR_LOCK_OP_STAT_TIMEOUT_MS))
    {
        current_status = sdr_rt_context.sdr_ft_status;
        sdr_critical_exit();
    }
    else
    {
        current_status = ES_TFTP_BUSY;
    }

    return current_status;
}

void sdr_get_state(uint8_t *const p_active_state)
{
    if (NULL != p_active_state)
    {
        if (true == sdr_critical_enter(SDR_LOCK_OP_STAT_TIMEOUT_MS))
        {
            *p_active_state = HSM_GetActiveState(sdr_sm_instance)->state_id;
            sdr_critical_exit();
        }
        else
        {
            *p_active_state = SDR_SM_MAX;
        }
    }
    else
    {
        BREAK_ASSERT(false);
    }
}

bool ft_op_set(const sdr_file_op_t *ft_req)
{
    BREAK_ASSERT(NULL != ft_req);
    bool res_op = false;

    if (NULL != ft_req)
    {
        if (true == sdr_critical_enter(SDR_LOCK_OP_STAT_TIMEOUT_MS))
        {
            memset(sdr_file, 0, sizeof(sdr_file));
            memset(obc_file, 0, sizeof(obc_file));

            // copy command parameters to internal buffers
            sdr_ft_op = ft_req->ft_op;
            memcpy(sdr_file, ft_req->sdr_file, sizeof(sdr_file));
            memcpy(obc_file, ft_req->obc_file, sizeof(obc_file));

            sdr_rt_context.sdr_ft_req.ft_op    = sdr_ft_op;
            sdr_rt_context.sdr_ft_req.obc_file = obc_file;
            sdr_rt_context.sdr_ft_req.sdr_file = sdr_file;
            sdr_rt_context.is_op_pending       = true;
            res_op                             = true;
            sdr_critical_exit();
        }
    }

    return res_op;
}

void sdr_time_sync_data_set(const datetime_stamp_t *dt)
{
    if (true == sdr_critical_enter(SDR_LOCK_OP_STAT_TIMEOUT_MS))
    {
        if ((true == sdr_rt_context.is_ready_to_sync) &&
            (false == sdr_rt_context.sync_data_rdy))
        {
            sdr_rt_context.sdr_sync_dt   = *dt;
            sdr_rt_context.sync_data_rdy = true;
        }
        sdr_critical_exit();
    }
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

static bool downloaded_file_is_empty(const char *obc_file)
{
    CRIT_ASSERT(NULL != obc_file);
    bool ret = true;

    fm_fast_file_info_t file_info = { 0 };
    fm_result_t         fm_res    = FM_RES_DISK_ERR;

    fm_res = fm_stat(obc_file, &file_info);

    if ((FM_RES_OK == fm_res) && (file_info.size > 0))
    {
        ret = false;
    }

    return ret;
}
