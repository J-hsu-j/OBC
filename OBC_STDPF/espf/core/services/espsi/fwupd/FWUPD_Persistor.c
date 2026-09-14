/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup fwupd
 * @{
 *
 * @file    FWUPD_Persistor.h
 * @brief   FWUPD persistor configuration definitions
 *
 * @}
 */

#include <stdbool.h>
#include <stdint.h>
#include "FWUPD_Persistor.h"
#include "assertions.h"
#include "cmsis_os2.h"
#include "MACCRC32_Classic_Impl.h"

#define APP_BUNDLE_CRC_SIZE (4U)

#define FWUPD_PERSISTOR_STORAGE_DIR ""

INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

static const char aActiveTidFileName[] = "fwu.tid";
const char        aTempImageFileName[] = "fwu.tmp";

// verification is disabled in this version of the protocol
#if 0
static uint8_t au8VerifyBuffer[256];
#endif

typedef struct
{
    // file handle for the current transfer
    fm_file_obj_t fHnd;
    // overall maximum time for writing a single block to file system for
    // the current transfer
    uint32_t u32MaxWriteTime;
} sPersistorContext_t;

static sPersistorContext_t persistCtx;

static void fs_vInit(sPersistorContext_t *const pCtx);
static bool fs_bGetPendingTransferInfo(sTransferInfo_t *const pTransferInfo);

static void fs_vInit(sPersistorContext_t *const pCtx)
{
    CRIT_ASSERT(pCtx != NULL);

    pCtx->u32MaxWriteTime = 0U;
}

static bool fs_bGetPendingTransferInfo(sTransferInfo_t *const pTransferInfo)
{
    fm_file_obj_t tempHandle;
    fm_result_t   fres;
    bool          bPendingTransferExists = false;
    uint32_t      bytesRead              = 0;

    CRIT_ASSERT(pTransferInfo != NULL);

    fres = fm_open(&tempHandle, aActiveTidFileName, FM_MODE_OPEN_EXISTING | FM_MODE_READ);

    if (fres == FM_RES_OK)
    {
        fres = fm_read(&tempHandle,
                       (void *)pTransferInfo,
                       sizeof(sTransferInfo_t),
                       &bytesRead);

        (void)fres;
        (void)fm_close(&tempHandle);

        if (bytesRead == sizeof(sTransferInfo_t))
        {
            bPendingTransferExists = true;
        }
    }
    else
    {
        (void)memset(pTransferInfo, 0U, sizeof(sTransferInfo_t));
    }

    return bPendingTransferExists;
}

static bool fs_u32GetStartingPosForTransfer(const uint64_t u64TransferId, uint32_t *pu32StartPos)
{
    fm_result_t     fres;
    uint32_t        u32StartPos = 0U;
    sTransferInfo_t tinfo;
    bool            bPendingTransferExists = fs_bGetPendingTransferInfo(&tinfo);

    if (bPendingTransferExists)
    {
        if (u64TransferId == tinfo.u64TransferId)
        {
            // TID file exists and TID matches the new transfer ID -->
            // try to obtain the size of the downloaded image to
            // attempt resuming of the active transfer (probably an OBC restart occurred)
            fres = fm_open(&persistCtx.fHnd, aTempImageFileName, FM_MODE_OPEN_EXISTING | FM_MODE_READ);

            if (fres == FM_RES_OK)
            {
                (void)fm_size(&persistCtx.fHnd, &u32StartPos);
                (void)fm_close(&persistCtx.fHnd);
            }
        }
    }

    // if the starting pos is more than zero, then the transfer size shall also include the size of the update header
    // which is not written as part of the downloaded file but GS assumes the start of transfer from the beginning of this header;
    // providing a value 0 here, means that we also want to receive the header again
    if (pu32StartPos != NULL)
    {
        *pu32StartPos = bPendingTransferExists ? u32StartPos + sizeof(SESSoftwareUPD_Bundle) : u32StartPos;
    }

    return bPendingTransferExists;
}

eFwUpdPersistorResult FWUPD_Persistor_GetPartialTransferInfo(sTransferInfo_t *const pTransferInfo,
                                                             uint32_t *const        pu32StartPos)
{
    eFwUpdPersistorResult res = EFWUPDPERSISTORRESULT_ERROR;

    if ((pTransferInfo != NULL) &&
        (pu32StartPos != NULL))
    {
        if (fs_bGetPendingTransferInfo(pTransferInfo))
        {
            (void)fs_u32GetStartingPosForTransfer(pTransferInfo->u64TransferId, pu32StartPos);
            res = EFWUPDPERSISTORRESULT_OK;
        }
        else
        {
            *pu32StartPos = 0U;
        }
    }

    return res;
}

eFwUpdPersistorResult FWUPD_Persistor_StartNewTransfer(sTransferInfo_t *const pTransferInfo, uint32_t *const pu32StartPos)
{
    fm_result_t   fres = FM_RES_INT_ERR;
    fm_file_obj_t tempHandle;
    uint32_t      u32BytesWritten        = 0U;
    bool          bPendingTransferExists = false;

    fs_vInit(&persistCtx);

    if (pTransferInfo != NULL)
    {
        bPendingTransferExists = fs_u32GetStartingPosForTransfer(pTransferInfo->u64TransferId, pu32StartPos);

        if (pu32StartPos != NULL)
        {
            if (*pu32StartPos >= sizeof(SESSoftwareUPD_Bundle))
            {
                *pu32StartPos -= sizeof(SESSoftwareUPD_Bundle);
            }
        }

        if (!bPendingTransferExists)
        {
            // create the file which contains the ID of the currently active transfer
            fres = fm_open(&tempHandle, aActiveTidFileName, FM_MODE_WRITE | FM_MODE_CREATE_ALWAYS);
            if (fres == FM_RES_OK)
            {
                fres = fm_write(&tempHandle, (const void *)pTransferInfo, sizeof(sTransferInfo_t), &u32BytesWritten);
                (void)fm_close(&tempHandle);

                if ((fres == FM_RES_OK) && (u32BytesWritten == sizeof(sTransferInfo_t)))
                {
                    // attempt to create a zero-length file
                    fres = fm_open(&persistCtx.fHnd, aTempImageFileName, FM_MODE_WRITE | FM_MODE_CREATE_ALWAYS);
                    (void)fres;
                    fres = fm_close(&persistCtx.fHnd);
                }
                else
                {
                    FWUPD_DBG_PRINT("fres = %d\r\n", fres);
                    fres = FM_RES_INT_ERR;
                }
            }
            else
                FWUPD_DBG_PRINT("fm_open(%d)\r\n", fres);
        }
        else
        {
            fres = FM_RES_OK;
        }
    }

    return (fres == FM_RES_OK) ? EFWUPDPERSISTORRESULT_OK : EFWUPDPERSISTORRESULT_ERROR;
}

eFwUpdPersistorResult FWUPD_Persistor_CommitBuffer(const uint32_t       u32Pos,
                                                   const uint8_t *const pu8Buf,
                                                   const uint32_t       u32BufSize,
                                                   uint32_t *const      pu32BytesWritten)
{
    fm_result_t           fres;
    uint32_t              bytesWritten = 0U;
    eFwUpdPersistorResult retRes       = EFWUPDPERSISTORRESULT_ERROR;
    uint32_t              u32WriteTime;
    uint32_t              u32StartTime;

    u32StartTime = osKernelGetTickCount();

    fres = fm_open(&persistCtx.fHnd, aTempImageFileName, FM_MODE_WRITE | FM_MODE_OPEN_APPEND);

    if (fres == FM_RES_OK)
    {
        fres = fm_seek(&persistCtx.fHnd, u32Pos);

        if (fres == FM_RES_OK)
        {
            fres = fm_write(&persistCtx.fHnd, pu8Buf, u32BufSize, &bytesWritten);

            if (fres == FM_RES_OK)
            {
                if (pu32BytesWritten != NULL)
                {
                    *pu32BytesWritten = bytesWritten;
                }

                if (fres == FM_RES_OK)
                {
                    retRes = EFWUPDPERSISTORRESULT_OK;
                }
            }
            else
            {
                FWUPD_DBG_PRINT("fm_write(%d)\r\n", fres);
            }
        }
        else
        {
            FWUPD_DBG_PRINT("fm_seek(%d)\r\n", fres);
        }
    }
    else
    {
        FWUPD_DBG_PRINT("fm_open(%d)\r\n", fres);
    }

    u32WriteTime = osKernelGetTickCount() - u32StartTime;

    if (persistCtx.u32MaxWriteTime < u32WriteTime)
    {
        persistCtx.u32MaxWriteTime = u32WriteTime;
    }

    (void)fm_close(&persistCtx.fHnd);

    return retRes;
}

eFwUpdPersistorResult FWUPD_Persistor_FinalizeTransfer(const uint32_t num_bytes_to_strip)
{
    fm_result_t   fres = FM_RES_INT_ERR;
    fm_file_obj_t fHnd;

    fres = fm_open(&fHnd, aTempImageFileName, FM_MODE_WRITE | FM_MODE_OPEN_APPEND);

    if (fres == FM_RES_OK)
    {
        // strip the specified number of bytes at the end of the file
        uint32_t size;
        fres = fm_size(&fHnd, &size);
        if ((size >= num_bytes_to_strip) && (fres == FM_RES_OK))
        {
            fres = fm_truncate(&fHnd, size - num_bytes_to_strip);
            (void)fm_close(&fHnd);
        }
    }
    else
    {
        FWUPD_DBG_PRINT("fm_open(%d)\r\n", fres);
    }

    return (fres == FM_RES_OK) ? EFWUPDPERSISTORRESULT_OK : EFWUPDPERSISTORRESULT_ERROR;
}

eFwUpdPersistorResult FWUPD_Persistor_PrepareImage(char *const pRequestedImageName)
{
    fm_result_t fres = FM_RES_INVALID_PARAMETER;

    if (pRequestedImageName != NULL)
    {
        // delete any previous update image if it exists
        (void)fm_delete(pRequestedImageName);

        // rename temporary image to the name requested by the user
        fres = fm_rename(aTempImageFileName, pRequestedImageName);
    }
    else
    {
        // make sure all temporary files get deleted
        (void)fm_delete(aTempImageFileName);
    }

    // delete active transfer ID file
    (void)fm_delete(aActiveTidFileName);

    return (fres == FM_RES_OK) ? EFWUPDPERSISTORRESULT_OK : EFWUPDPERSISTORRESULT_ERROR;
}

eFwUpdPersistorResult FWUPD_Persistor_VerifyImage(void)
{
// verification example (currently not enabled due to custom extensions on top of the FWUPD protocol
#if 0
    fm_file_obj_t fHnd;
    fm_result_t fres;
    UINT bytesRead = 0U;
    eFwUpdPersistorResult res = EFWUPDPERSISTORRESULT_ERROR;
    uint32_t u32Crc = 0xFFFFFFFFU;
    uint32_t u32ExpectedCrc = 0U;
    uint32_t u32FSize = 0U;

    fres = fm_open(&fHnd, aTempImageFileName, FM_MODE_READ | FM_MODE_OPEN_EXISTING);

    if (fres == FM_RES_OK)
    {
        fm_size(&fHnd, &u32FSize);

        if (u32FSize > APP_BUNDLE_CRC_SIZE)
        {
            fres = fm_seek(&fHnd, u32FSize - APP_BUNDLE_CRC_SIZE);

            if (fres == FM_RES_OK)
            {
                fres = fm_read(&fHnd, &u32ExpectedCrc, APP_BUNDLE_CRC_SIZE, &bytesRead);

                fres = fm_seek(&fHnd, 0);

                if ((fres == FM_RES_OK) && (bytesRead == APP_BUNDLE_CRC_SIZE))
                {
                    do
                    {
                        fres = fm_read(&fHnd, au8VerifyBuffer, sizeof(au8VerifyBuffer), &bytesRead);

                        if (fres == FM_RES_OK)
                        {
                            u32Crc = MACCRC32_Calc32(au8VerifyBuffer, bytesRead, u32Crc);
                        }
                        else
                        {
                            break;
                        }
                    } while (bytesRead > 0);

                    if (u32Crc == u32ExpectedCrc)
                    {
                        res = EFWUPDPERSISTORRESULT_OK;
                    }
                }
            }
        }
    }

    (void) fm_close(&fHnd);

    return res;
#else
    return EFWUPDPERSISTORRESULT_OK;
#endif
}

eFwUpdPersistorResult FWUPD_Persistor_DiscardPendingUpdate(void)
{
    (void)fm_delete(aActiveTidFileName);
    (void)fm_delete(aTempImageFileName);

    return EFWUPDPERSISTORRESULT_OK;
}

const char *const FWUPD_Persistor_GetDownloadedImageFileName(void)
{
    return aTempImageFileName;
}

const char *FWUPD_Persistor_GetStorageDir(void)
{
    return FWUPD_PERSISTOR_STORAGE_DIR;
}
