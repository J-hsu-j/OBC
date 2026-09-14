/**
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup cubeadcs_gen2
 * @{
 *
 * @file cubeadcs_gen2_transfer.c
 *
 * @}
 */

#include "cubeadcs_gen2_transfer.h"
#include "cubeadcs_gen2_gw.h"
#include "cubeadcs_gen2_types.h"
#include "cubeadcs_gen2.h"
#include "assertions.h"
#include "taskmon.h"
#include "taskmon_stat.h"
#include "fm_mng.h"
#include "cmsis_os2.h"
#include <cubeObc/arch/cubeObc_critical.h>
#include "tctlmCubeComputerCommon3.h"
#include <string.h>

/** @brief flag used to signal main task for upload/download requests */
#define FS_START_TRANSFER_FLAG (0x01)

/** @brief mutex acquire timeout */
#define FS_LOCK_TIMEOUT (0)

/** @brief mutex acquire timeout */
#define FILE_STATUS_LOCK_TIMEOUT (5)

/** @brief lock to prevent concurrent file uploads/downloads */
static osMutexId_t fs_lock = NULL;

/** @brief upload/download task handle */
static osThreadId_t fs_task = NULL;

/** @brief event download parameters */
static cubeadcs_gen2_transfer_evt_status_t fs_evt = { 0 };

/** @brief telemetry download parameters */
static cubeadcs_gen2_transfer_tlm_status_t fs_tlm = { 0 };

/** @brief direct image download parameters */
static cubeadcs_gen2_transfer_img_direct_status_t fs_img_direct = { 0 };

/** @brief bootloader cube space file upload parameters */
static cubeadcs_gen2_transfer_boot_cube_space_file_status_t fs_csf_bl = { 0 };

/** @brief application cube space file upload parameters */
static cubeadcs_gen2_transfer_appl_cube_space_file_status_t fs_csf_ap = { 0 };

/** @brief used to keep the ongoing file transfer context information */
static cubeadcs_gen2_file_context_t fs_file_ctx;

/** @brief File name lock */
static osMutexId_t file_status_lock = NULL;

static void fs_transfer_task(void *args);

ErrorCode cubeadcs_gen2_transfer_init(void)
{
    ErrorCode ret = CUBEOBC_ERROR_OK;

    if (NULL == fs_lock)
    {
        fs_evt.err_code        = CUBEOBC_ERROR_USAGE;
        fs_tlm.err_code        = CUBEOBC_ERROR_USAGE;
        fs_img_direct.err_code = CUBEOBC_ERROR_USAGE;
        fs_csf_bl.err_code     = CUBEOBC_ERROR_USAGE;
        fs_csf_ap.err_code     = CUBEOBC_ERROR_USAGE;

        osMutexAttr_t attr = {
            .name      = "cube_transfer",
            .attr_bits = osMutexRecursive | osMutexPrioInherit,
            .cb_mem    = NULL,
            .cb_size   = 0U
        };

        fs_lock = osMutexNew(&attr);

        if (NULL == fs_lock)
        {
            ret = CUBEOBC_ERROR_USAGE;
        }
    }

    if (NULL == file_status_lock)
    {
        osMutexAttr_t attr = {
            .name      = "cube_file_name_transfer",
            .attr_bits = osMutexRecursive | osMutexPrioInherit,
            .cb_mem    = NULL,
            .cb_size   = 0U
        };

        file_status_lock = osMutexNew(&attr);

        if (NULL == file_status_lock)
        {
            ret = CUBEOBC_ERROR_USAGE;
        }
    }

    if ((CUBEOBC_ERROR_OK == ret) && (NULL == fs_task))
    {
        osThreadAttr_t attr = {
            .attr_bits  = osThreadDetached,
            .name       = "cube_transfer",
            .priority   = osPriorityNormal,
            .cb_mem     = NULL,
            .cb_size    = 0U,
            .stack_mem  = NULL,
            .stack_size = 2048,
            .tz_module  = 0U,
            .reserved   = 0U,
        };

        fs_task = osThreadNew(fs_transfer_task, NULL, &attr);
        task_mon_register_for_stats(TASK_ID_CUBEADCS_GEN2_TRANSFER, fs_task);

        if (NULL == fs_task)
        {
            ret = CUBEOBC_ERROR_USAGE;
        }
    }

    return ret;
}

ErrorCode cubeadcs_gen2_transfer_evt(const char *file_name, const TypesCubeComputerCommon3_EventLogFilterTransferSetup *setup)
{
    ErrorCode ret = CUBEOBC_ERROR_USAGE;
    uint32_t  len = strnlen(file_name, CUBEADCS_GEN2_BDT_FILE_NAME_SZ);

    if ((NULL != file_name) &&
        (0 < len) &&
        (NULL != setup))
    {
        if (osOK == osMutexAcquire(fs_lock, FS_LOCK_TIMEOUT))
        {
            memset(&fs_evt, 0, sizeof(fs_evt));
            memset(&fs_file_ctx, 0, sizeof(fs_file_ctx));
            memcpy(fs_evt.file_name, file_name, len);
            memcpy(&fs_evt.setup, setup, sizeof(fs_evt.setup));

            // null termination already added by memset()
            memcpy(fs_file_ctx.file_name, file_name, len);

            fs_file_ctx.context = CUBEADCS_GEN2_BDT_CTX_EVT_CC;

            // create the file
            if (FM_RES_OK == fm_open(&fs_file_ctx.file_handle, fs_file_ctx.file_name, FM_MODE_CREATE_ALWAYS | FM_MODE_WRITE))
            {
                ret = CUBEOBC_ERROR_OK;

                (void)fm_close(&fs_file_ctx.file_handle);
                (void)osThreadFlagsSet(fs_task, FS_START_TRANSFER_FLAG);
            }
            else
            {
                ret = CUBEOBC_ERROR_UNKNOWN;
            }

            (void)osMutexRelease(fs_lock);
        }
        else
        {
            ret = CUBEOBC_ERROR_BUSY;
        }
    }

    return ret;
}

ErrorCode cubeadcs_gen2_transfer_evt_status(cubeadcs_gen2_transfer_evt_status_t *status)
{
    ErrorCode ret = CUBEOBC_ERROR_USAGE;

    if (NULL != status)
    {
        if (osOK == osMutexAcquire(fs_lock, FS_LOCK_TIMEOUT))
        {
            memcpy(status, &fs_evt, sizeof(fs_evt));

            ret = CUBEOBC_ERROR_OK;

            (void)osMutexRelease(fs_lock);
        }
        else
        {
            ret = CUBEOBC_ERROR_BUSY;
        }
    }

    return ret;
}

ErrorCode cubeadcs_gen2_transfer_tlm(const char *file_name, const TypesCubeComputerCommon3_TelemetryLogTransferSetup *setup)
{
    ErrorCode ret = CUBEOBC_ERROR_USAGE;
    uint32_t  len = strnlen(file_name, CUBEADCS_GEN2_BDT_FILE_NAME_SZ);

    if ((NULL != file_name) &&
        (0 < len) &&
        (NULL != setup))
    {
        if (osOK == osMutexAcquire(fs_lock, FS_LOCK_TIMEOUT))
        {
            memset(&fs_tlm, 0, sizeof(fs_tlm));
            memset(&fs_file_ctx, 0, sizeof(fs_file_ctx));
            memcpy(fs_tlm.file_name, file_name, len);
            memcpy(&fs_tlm.setup, setup, sizeof(fs_tlm.setup));

            // null termination already added by memset()
            memcpy(fs_file_ctx.file_name, file_name, len);

            fs_file_ctx.context = CUBEADCS_GEN2_BDT_CTX_TLM_CC;

            // create the file
            if (FM_RES_OK == fm_open(&fs_file_ctx.file_handle, fs_file_ctx.file_name, FM_MODE_CREATE_ALWAYS | FM_MODE_WRITE))
            {
                ret = CUBEOBC_ERROR_OK;

                (void)fm_close(&fs_file_ctx.file_handle);
                (void)osThreadFlagsSet(fs_task, FS_START_TRANSFER_FLAG);
            }
            else
            {
                ret = CUBEOBC_ERROR_UNKNOWN;
            }

            (void)osMutexRelease(fs_lock);
        }
        else
        {
            ret = CUBEOBC_ERROR_BUSY;
        }
    }

    return ret;
}

ErrorCode cubeadcs_gen2_transfer_tlm_status(cubeadcs_gen2_transfer_tlm_status_t *status)
{
    ErrorCode ret = CUBEOBC_ERROR_USAGE;

    if (NULL != status)
    {
        if (osOK == osMutexAcquire(fs_lock, FS_LOCK_TIMEOUT))
        {
            memcpy(status, &fs_tlm, sizeof(fs_tlm));

            ret = CUBEOBC_ERROR_OK;

            (void)osMutexRelease(fs_lock);
        }
        else
        {
            ret = CUBEOBC_ERROR_BUSY;
        }
    }

    return ret;
}

ErrorCode cubeadcs_gen2_transfer_img_direct(const char *file_name, const U32 file_handle, TypesCommonFrameworkTypes1_AbstractNode node)
{
    ErrorCode ret = CUBEOBC_ERROR_USAGE;
    uint32_t  len = strnlen(file_name, CUBEADCS_GEN2_BDT_FILE_NAME_SZ);

    if ((NULL != file_name) &&
        (0 < len))
    {
        if (osOK == osMutexAcquire(fs_lock, FS_LOCK_TIMEOUT))
        {
            memset(&fs_img_direct, 0, sizeof(fs_img_direct));
            memset(&fs_file_ctx, 0, sizeof(fs_file_ctx));
            if (osOK == osMutexAcquire(file_status_lock, FILE_STATUS_LOCK_TIMEOUT))
            {
                memcpy(fs_img_direct.file_name, file_name, len);
                (void)osMutexRelease(file_status_lock);
            }

            // null termination already added by memset()
            memcpy(fs_file_ctx.file_name, file_name, len);

            fs_file_ctx.context     = CUBEADCS_GEN2_BDT_CTX_IMG_CC;
            fs_img_direct.setup     = file_handle;
            fs_img_direct.node_type = node;
            // create the file
            if (FM_RES_OK == fm_open(&fs_file_ctx.file_handle, fs_file_ctx.file_name, FM_MODE_CREATE_ALWAYS | FM_MODE_WRITE))
            {
                ret = CUBEOBC_ERROR_OK;

                (void)fm_close(&fs_file_ctx.file_handle);
                (void)osThreadFlagsSet(fs_task, FS_START_TRANSFER_FLAG);
            }
            else
            {
                ret = CUBEOBC_ERROR_UNKNOWN;
            }

            (void)osMutexRelease(fs_lock);
        }
        else
        {
            ret = CUBEOBC_ERROR_BUSY;
        }
    }

    return ret;
}

ErrorCode cubeadcs_gen2_transfer_img_direct_status(TypesCubeComputerCommon3_ImageTransferStatus *p_ret_val, uint8_t *p_file_name)
{
    ErrorCode ret = CUBEOBC_ERROR_USAGE;

    if ((NULL != p_ret_val) && (NULL != p_file_name))
    {
        if (osOK == osMutexAcquire(file_status_lock, FILE_STATUS_LOCK_TIMEOUT))
        {
            // The node ID is hard coded because this function can take the status only from the cubeComputer
            ret = CubeADCS_Gen2_CubeComputerCommon3_getImageTransferStatusRequestGw(TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, p_ret_val, CUBEOBC_CRITICAL_WAIT_FOREVER);
            memcpy(p_file_name, fs_img_direct.file_name, sizeof(fs_img_direct.file_name));

            (void)osMutexRelease(file_status_lock);
        }
    }

    return ret;
}

ErrorCode cubeadcs_gen2_transfer_boot_cube_space_file(
    const char *cp_file_name,
    const char *cfg_file_name,
    const bool  force)
{
    ErrorCode ret     = CUBEOBC_ERROR_USAGE;
    uint32_t  cp_len  = strnlen(cp_file_name, CUBEADCS_GEN2_BDT_FILE_NAME_SZ);
    uint32_t  cfg_len = strnlen(cfg_file_name, CUBEADCS_GEN2_BDT_FILE_NAME_SZ);

    if ((NULL != cp_file_name) && (0 < cp_len) &&
        (NULL != cfg_file_name) && (0 < cfg_len))
    {
        if (osOK == osMutexAcquire(fs_lock, FS_LOCK_TIMEOUT))
        {
            memset(&fs_csf_bl, 0, sizeof(fs_csf_bl));
            memset(&fs_file_ctx, 0, sizeof(fs_file_ctx));

            // null termination already added by memset()
            memcpy(fs_csf_bl.cp_file_name, cp_file_name, cp_len);
            memcpy(fs_csf_bl.cfg_file_name, cfg_file_name, cfg_len);

            fs_file_ctx.context = CUBEADCS_GEN2_BDT_CTX_FTP_BL;
            fs_csf_bl.force     = force;

            ret = CUBEOBC_ERROR_OK;

            (void)osThreadFlagsSet(fs_task, FS_START_TRANSFER_FLAG);
            (void)osMutexRelease(fs_lock);
        }
        else
        {
            ret = CUBEOBC_ERROR_BUSY;
        }
    }

    return ret;
}

ErrorCode cubeadcs_gen2_transfer_boot_cube_space_file_status(cubeadcs_gen2_transfer_boot_cube_space_file_status_t *status)
{
    ErrorCode ret = CUBEOBC_ERROR_USAGE;

    if (NULL != status)
    {
        if (osOK == osMutexAcquire(fs_lock, FS_LOCK_TIMEOUT))
        {
            memcpy(status, &fs_csf_bl, sizeof(fs_csf_bl));

            ret = CUBEOBC_ERROR_OK;

            (void)osMutexRelease(fs_lock);
        }
        else
        {
            ret = CUBEOBC_ERROR_BUSY;
        }
    }

    return ret;
}

ErrorCode cubeadcs_gen2_transfer_appl_cube_space_file(
    const char                         *cp_file_name,
    const char                         *cfg_file_name,
    const bool                          force,
    TypesCommonFrameworkTypes1_NodeType node_type,
    U32                                 serial_int)
{
    ErrorCode ret     = CUBEOBC_ERROR_USAGE;
    uint32_t  cp_len  = strnlen(cp_file_name, CUBEADCS_GEN2_BDT_FILE_NAME_SZ);
    uint32_t  cfg_len = strnlen(cfg_file_name, CUBEADCS_GEN2_BDT_FILE_NAME_SZ);

    if ((NULL != cp_file_name) && (0 < cp_len) &&
        (NULL != cfg_file_name) && (0 < cfg_len))
    {
        if (osOK == osMutexAcquire(fs_lock, FS_LOCK_TIMEOUT))
        {
            memset(&fs_csf_ap, 0, sizeof(fs_csf_ap));
            memset(&fs_file_ctx, 0, sizeof(fs_file_ctx));

            // null termination already added by memset()
            memcpy(fs_csf_ap.cp_file_name, cp_file_name, cp_len);
            memcpy(fs_csf_ap.cfg_file_name, cfg_file_name, cfg_len);

            fs_file_ctx.context  = CUBEADCS_GEN2_BDT_CTX_FTP_AP;
            fs_csf_ap.force      = force;
            fs_csf_ap.node_type  = node_type;
            fs_csf_ap.serial_int = serial_int;

            ret = CUBEOBC_ERROR_OK;

            (void)osThreadFlagsSet(fs_task, FS_START_TRANSFER_FLAG);
            (void)osMutexRelease(fs_lock);
        }
        else
        {
            ret = CUBEOBC_ERROR_BUSY;
        }
    }

    return ret;
}

ErrorCode cubeadcs_gen2_transfer_appl_cube_space_file_status(cubeadcs_gen2_transfer_appl_cube_space_file_status_t *status)
{
    ErrorCode ret = CUBEOBC_ERROR_USAGE;

    if (NULL != status)
    {
        if (osOK == osMutexAcquire(fs_lock, FS_LOCK_TIMEOUT))
        {
            memcpy(status, &fs_csf_ap, sizeof(fs_csf_ap));

            ret = CUBEOBC_ERROR_OK;

            (void)osMutexRelease(fs_lock);
        }
        else
        {
            ret = CUBEOBC_ERROR_BUSY;
        }
    }

    return ret;
}

/**
 * @brief Performs blocking upload of cube space files to the bootloader
 *
 * @return @ref ErrorCode
 */
static ErrorCode fs_start_blocking_upload_to_boot(TypeDef_TctlmEndpoint *endpoint)
{
    CRIT_ASSERT(NULL != endpoint);

    ErrorCode                            status;
    fm_fast_file_info_t                  tfi_cp;
    fm_fast_file_info_t                  tfi_cfg;
    TypesCommonFramework1_Identification identity;

    // Check if the file exists in OBC.
    // Since we are uploading, it must exist in our file system.
    if (FM_RES_OK != fm_stat(fs_csf_bl.cp_file_name, &tfi_cp))
    {
        // The file doesn't exist...
        status = CUBEOBC_ERROR_EXIST;
    }
    else
    {
        // The file exists, we can continue with next steps.
        status = CUBEOBC_ERROR_OK;
    }

    // Check if the file exists in OBC.
    // Since we are uploading, it must exist in our file system.
    if (CUBEOBC_ERROR_OK == status)
    {
        if (FM_RES_OK != fm_stat(fs_csf_bl.cfg_file_name, &tfi_cfg))
        {
            // The file doesn't exist...
            status = CUBEOBC_ERROR_EXIST;
        }
        else
        {
            // The file exists, we can continue with next steps.
            status = CUBEOBC_ERROR_OK;
        }
    }

    if (CUBEOBC_ERROR_OK == status)
    {
        status = CubeADCS_Gen2_CommonFramework1_getIdentificationRequestGw(
            TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &identity, CUBEOBC_CRITICAL_WAIT_FOREVER);
    }

    if ((CUBEOBC_ERROR_OK == status) &&
        (TYPES_COMMON_FRAMEWORK_TYPES_1__PROGRAM_TYPE_BOOTLOADER == identity.programType))
    {
        // we are already in bootloader. go directly to upload.
    }
    else if ((CUBEOBC_ERROR_OK == status) &&
             (true == fs_csf_bl.force) &&
             (TYPES_COMMON_FRAMEWORK_TYPES_1__PROGRAM_TYPE_CONTROL == identity.programType))
    {
        // reset to bootloader
        TypesCommonFramework1_Reset rst = { .resetType = TYPES_COMMON_FRAMEWORK_1__SOFT };
        (void)CubeADCS_Gen2_CommonFramework1_setResetRequestGw(
            TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &rst, CUBEOBC_CRITICAL_WAIT_FOREVER);

        // wait for boot
        cubeObc_time_delay(1000u);

        status = CubeADCS_Gen2_CommonFramework1_getIdentificationRequestGw(
            TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &identity, CUBEOBC_CRITICAL_WAIT_FOREVER);

        if ((CUBEOBC_ERROR_OK == status) &&
            ((TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_TYPE_LEGACY_CUBE_COMPUTER != identity.nodeType) ||
             (TYPES_COMMON_FRAMEWORK_TYPES_1__PROGRAM_TYPE_BOOTLOADER != identity.programType)))
        {
            // failed to enter bootloader
            status = CUBEOBC_ERROR_UNKNOWN;
        }

        if (CUBEOBC_ERROR_OK == status)
        {
            // stay in bootloader. do not jump to application
            status = CubeADCS_Gen2_CubeCommonBaseBootloader5_setHaltRequestGw(
                TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, CUBEOBC_CRITICAL_WAIT_FOREVER);
        }
    }
    else if (CUBEOBC_ERROR_OK == status)
    {
        // we do not support uploads in any other program type
        status = CUBEOBC_ERROR_UNKNOWN;
    }
    else
    {
        // nothing to do
    }

    // save context type
    U32 ctx = fs_file_ctx.context;

    if (CUBEOBC_ERROR_OK == status)
    {
        // reset whole file context
        memset(&fs_file_ctx, 0, sizeof(fs_file_ctx));

        (void)memcpy(
            fs_file_ctx.file_name,
            fs_csf_bl.cp_file_name,
            strnlen(fs_csf_bl.cp_file_name, CUBEADCS_GEN2_BDT_FILE_NAME_SZ));

        // restore context type
        fs_file_ctx.context = ctx;

        status = cubeObc_bootloader_uploadCubeSpaceFile(
            endpoint, tfi_cp.size, &fs_file_ctx, &fs_csf_bl.status);
    }

    if (CUBEOBC_ERROR_OK == status)
    {
        // reset whole file context
        memset(&fs_file_ctx, 0, sizeof(fs_file_ctx));

        (void)memcpy(
            fs_file_ctx.file_name,
            fs_csf_bl.cfg_file_name,
            strnlen(fs_csf_bl.cfg_file_name, CUBEADCS_GEN2_BDT_FILE_NAME_SZ));

        // restore context type
        fs_file_ctx.context = ctx;

        status = cubeObc_bootloader_uploadCubeSpaceFile(
            endpoint, tfi_cfg.size, &fs_file_ctx, &fs_csf_bl.status);
    }

    if ((CUBEOBC_ERROR_OK == status) && (CUBEOBC_ERROR_OK == fs_csf_bl.status.result))
    {
        status = CubeADCS_Gen2_CubeCommonBaseBootloader5_setJumpToDefaultAppRequestGw(
            TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, CUBEOBC_CRITICAL_WAIT_FOREVER);
    }

    // FW update finished clear flag
    cubeadcs_gen2_set_fw_upd_flag(false);

    return status;
}

/**
 * @brief Performs blocking upload of cube space files to the application
 *
 * @return @ref ErrorCode
 */
static ErrorCode fs_start_blocking_upload_to_appl(TypeDef_TctlmEndpoint *endpoint)
{
    CRIT_ASSERT(NULL != endpoint);

    ErrorCode                            status;
    fm_fast_file_info_t                  tfi_cp;
    fm_fast_file_info_t                  tfi_cfg;
    TypesCommonFramework1_Identification identity;

    // Check if the file exists in OBC.
    // Since we are uploading, it must exist in our file system.
    if (FM_RES_OK != fm_stat(fs_csf_ap.cp_file_name, &tfi_cp))
    {
        // The file doesn't exist...
        status = CUBEOBC_ERROR_EXIST;
    }
    else
    {
        // The file exists, we can continue with next steps.
        status = CUBEOBC_ERROR_OK;
    }

    // Check if the file exists in OBC.
    // Since we are uploading, it must exist in our file system.
    if (CUBEOBC_ERROR_OK == status)
    {
        if (FM_RES_OK != fm_stat(fs_csf_ap.cfg_file_name, &tfi_cfg))
        {
            // The file doesn't exist...
            status = CUBEOBC_ERROR_EXIST;
        }
        else
        {
            // The file exists, we can continue with next steps.
            status = CUBEOBC_ERROR_OK;
        }
    }

    if (CUBEOBC_ERROR_OK == status)
    {
        status = CubeADCS_Gen2_CommonFramework1_getIdentificationRequestGw(
            TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &identity, CUBEOBC_CRITICAL_WAIT_FOREVER);
    }

    if ((CUBEOBC_ERROR_OK == status) &&
        (TYPES_COMMON_FRAMEWORK_TYPES_1__PROGRAM_TYPE_CONTROL == identity.programType))
    {
        // we are already in application. go directly to upload.
    }
    else if ((CUBEOBC_ERROR_OK == status) &&
             (true == fs_csf_ap.force) &&
             (TYPES_COMMON_FRAMEWORK_TYPES_1__PROGRAM_TYPE_BOOTLOADER == identity.programType))
    {
        status = CubeADCS_Gen2_CubeCommonBaseBootloader5_setJumpToDefaultAppRequestGw(
            TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, CUBEOBC_CRITICAL_WAIT_FOREVER);

        if (CUBEOBC_ERROR_OK == status)
        {
            // wait for boot
            cubeObc_time_delay(1000u);

            // Wait for port validation/auto-discovery to complete
            status = cubeObc_common_pollForBootState(
                endpoint, TYPES_COMMON_FRAMEWORK_1__APPLICATION_RUNNING, 500u, 10000u, FALSE);
        }
    }
    else if (CUBEOBC_ERROR_OK == status)
    {
        // we do not support uploads in any other program type
        status = CUBEOBC_ERROR_UNKNOWN;
    }
    else
    {
        // nothing to do
    }

    // save context type
    U32 ctx = fs_file_ctx.context;

    if (CUBEOBC_ERROR_OK == status)
    {
        // reset whole file context
        memset(&fs_file_ctx, 0, sizeof(fs_file_ctx));

        (void)memcpy(
            fs_file_ctx.file_name,
            fs_csf_ap.cp_file_name,
            strnlen(fs_csf_ap.cp_file_name, CUBEADCS_GEN2_BDT_FILE_NAME_SZ));

        // restore context type
        fs_file_ctx.context = ctx;

        status = cubeObc_cubeComputer_uploadCubeSpaceFile(
            endpoint, tfi_cp.size, &fs_file_ctx, &fs_csf_ap.status);
    }

    if (CUBEOBC_ERROR_OK == status)
    {
        // reset whole file context
        memset(&fs_file_ctx, 0, sizeof(fs_file_ctx));

        (void)memcpy(
            fs_file_ctx.file_name,
            fs_csf_ap.cfg_file_name,
            strnlen(fs_csf_ap.cfg_file_name, CUBEADCS_GEN2_BDT_FILE_NAME_SZ));

        // restore context type
        fs_file_ctx.context = ctx;

        status = cubeObc_cubeComputer_uploadCubeSpaceFile(
            endpoint, tfi_cfg.size, &fs_file_ctx, &fs_csf_ap.status);
    }

    if ((CUBEOBC_ERROR_OK == status) && (CUBEOBC_ERROR_OK == fs_csf_ap.status.errorCode))
    {
        status = cubeObc_cubeComputer_upgrade(
            endpoint,
            fs_csf_ap.node_type,
            fs_csf_ap.serial_int,
            TYPES_COMMON_FRAMEWORK_TYPES_1__PROGRAM_TYPE_CONTROL,
            TYPES_CUBE_COMPUTER_CONTROL_PROGRAM_8__PORT_NONE,
            &fs_csf_ap.status);
    }

    return status;
}

/**
 * @brief Performs blocking upload/download
 */
static void fs_start_blocking_transfer(void)
{
    ErrorCode                            status;
    TypeDef_TctlmEndpoint                endpoint;
    TypesCommonFramework1_Identification identity;

    // setup the endpoint to the standard configuration
    cubeadcs_gen2_setup_endpoint(
        &endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);

    status = CubeADCS_Gen2_CommonFramework1_getIdentificationRequestGw(
        TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER, &identity, CUBEOBC_CRITICAL_WAIT_FOREVER);

    if ((CUBEOBC_ERROR_OK == status) &&
        (TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_TYPE_LEGACY_CUBE_COMPUTER != identity.nodeType))
    {
        status = CUBEOBC_ERROR_NODE_TYPE;
    }

    switch (fs_file_ctx.context)
    {
        case CUBEADCS_GEN2_BDT_CTX_EVT_CC:
            {
                fs_evt.err_code = (CUBEOBC_ERROR_OK != status) ? status : cubeObc_cubeComputer_eventDownload(&endpoint, &fs_evt.setup, &fs_file_ctx, &fs_evt.status);
            }
            break;
        case CUBEADCS_GEN2_BDT_CTX_TLM_CC:
            {
                fs_tlm.err_code = (CUBEOBC_ERROR_OK != status) ? status : cubeObc_cubeComputer_tlmDownload(&endpoint, &fs_tlm.setup, &fs_file_ctx, &fs_tlm.status);
            }
            break;
        case CUBEADCS_GEN2_BDT_CTX_IMG_CC:
            {
                fs_img_direct.err_code = (CUBEOBC_ERROR_OK != status) ? status : cubeObc_cubeComputer_imageDownloadDirect(&endpoint, fs_img_direct.node_type, &fs_file_ctx, &fs_img_direct.status);
            }
            break;
        case CUBEADCS_GEN2_BDT_CTX_FTP_BL:
            {
                fs_csf_bl.err_code = (CUBEOBC_ERROR_OK != status) ? status : fs_start_blocking_upload_to_boot(&endpoint);
            }
            break;
        case CUBEADCS_GEN2_BDT_CTX_FTP_AP:
            {
                fs_csf_ap.err_code = (CUBEOBC_ERROR_OK != status) ? status : fs_start_blocking_upload_to_appl(&endpoint);
            }
            break;
        default:
            {
                // no more contexts
                CRIT_ASSERT(false);
            }
            break;
    }
}

/**
 * @brief This task is responsible for handling all upload/download requests
 */
static void fs_transfer_task(void *args)
{
    (void)args;

    task_mon_task_initialized(TASK_ID_CUBEADCS_GEN2_TRANSFER);
    task_mon_set_task_policy(TASK_ID_CUBEADCS_GEN2_TRANSFER, TASK_MON_POLICY_MONITOR);

    while (1)
    {
        task_mon_i_am_alive(TASK_ID_CUBEADCS_GEN2_TRANSFER);

        if ((FS_START_TRANSFER_FLAG == osThreadFlagsWait(FS_START_TRANSFER_FLAG, osFlagsWaitAny, 5000)) &&
            (osOK == osMutexAcquire(fs_lock, osWaitForever)))
        {
            fs_start_blocking_transfer();

            (void)osMutexRelease(fs_lock);
        }

        task_mon_low_stack_check(TASK_ID_CUBEADCS_GEN2_TRANSFER);
    }
}
