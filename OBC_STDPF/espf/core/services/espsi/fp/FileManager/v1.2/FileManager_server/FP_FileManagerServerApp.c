/*!
********************************************************************************************
* @file FP_FileManagerServerApp.c
* @brief ServerApp implementation template generator
********************************************************************************************
* @version           interface FileManager v1.2
*
* @copyright         (C) Copyright EnduroSat
*
*                    Contents and presentations are protected world-wide.
*                    Any kind of using, copying etc. is prohibited without prior permission.
*                    All rights - incl. industrial property rights - are reserved.
*
*-------------------------------------------------------------------------------------------
* GENERATOR: org.endurosat.generators.macchiato.binders.Gen_C v2.15
*-------------------------------------------------------------------------------------------
* !!! Please note that this code is fully GENERATED and shall not be manually modified as
* all changes will be overwritten !!!
********************************************************************************************
*/

#include "FP_FileManagerProtocolServer.h"

// @START_USER@ USER_INCLUDES
// Place user includes here to preserve them during merge!!!
#include "fm_mng.h"
// @END_USER@ USER_INCLUDES

/**********************************************************************
 *
 *  Local methods declarations
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_DECL
// Place static function declarations here to preserve them during merge!!!
// @END_USER@ USER_LOCAL_FUNC_DECL
static void FileManager_fileOpenRequestHandlerImpl(ReqContext_t* pReqCtx,
            const FileManagerfileOpenRequestData_t* pRequestData);

static void FileManager_fileCloseRequestHandlerImpl(ReqContext_t* pReqCtx,
            const FileManagerfileCloseRequestData_t* pRequestData);

static void FileManager_fileReadRequestHandlerImpl(ReqContext_t* pReqCtx,
            const FileManagerfileReadRequestData_t* pRequestData);

static void FileManager_fileWriteRequestHandlerImpl(ReqContext_t* pReqCtx,
            const FileManagerfileWriteRequestData_t* pRequestData);

static void FileManager_RenameRequestHandlerImpl(ReqContext_t* pReqCtx,
            const FileManagerRenameRequestData_t* pRequestData);

static void FileManager_DeleteRequestHandlerImpl(ReqContext_t* pReqCtx,
            const FileManagerDeleteRequestData_t* pRequestData);

static void FileManager_fileGetSizeRequestHandlerImpl(ReqContext_t* pReqCtx,
            const FileManagerfileGetSizeRequestData_t* pRequestData);

static void FileManager_fileGetCheckSumRequestHandlerImpl(ReqContext_t* pReqCtx,
            const FileManagerfileGetCheckSumRequestData_t* pRequestData);

static void FileManager_fileGetOpenedHandlesCountRequestHandlerImpl(ReqContext_t* pReqCtx);

static void FileManager_formatPartitionRequestHandlerImpl(ReqContext_t* pReqCtx,
            const FileManagerformatPartitionRequestData_t* pRequestData);

static void FileManager_fileDumpDirListToFileRequestHandlerImpl(ReqContext_t* pReqCtx,
            const FileManagerfileDumpDirListToFileRequestData_t* pRequestData);

static void FileManager_getStatisticsRequestHandlerImpl(ReqContext_t* pReqCtx);

static void FileManager_clearStatisticsRequestHandlerImpl(ReqContext_t* pReqCtx);

static void FileManager_sdReinitRequestHandlerImpl(ReqContext_t* pReqCtx,
            const FileManagersdReinitRequestData_t* pRequestData);

static void FileManager_dirMakeRequestHandlerImpl(ReqContext_t* pReqCtx,
            const FileManagerdirMakeRequestData_t* pRequestData);

static void FileManager_get_sd_card_statusRequestHandlerImpl(ReqContext_t* pReqCtx);


/**********************************************************************
 *
 *  Local variables
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_VARS_DECL
// Place static variable declarations here to preserve them during merge!!!
INIT_CMP_LOGGER(true, TRACE_LVL_WARN)
// @END_USER@ USER_LOCAL_VARS_DECL

static FileManager_ServerApi_t FileManagerServerApiCtx =
{
  .FileManager_fileOpenRequestHandler = FileManager_fileOpenRequestHandlerImpl,
  .FileManager_fileCloseRequestHandler = FileManager_fileCloseRequestHandlerImpl,
  .FileManager_fileReadRequestHandler = FileManager_fileReadRequestHandlerImpl,
  .FileManager_fileWriteRequestHandler = FileManager_fileWriteRequestHandlerImpl,
  .FileManager_RenameRequestHandler = FileManager_RenameRequestHandlerImpl,
  .FileManager_DeleteRequestHandler = FileManager_DeleteRequestHandlerImpl,
  .FileManager_fileGetSizeRequestHandler = FileManager_fileGetSizeRequestHandlerImpl,
  .FileManager_fileGetCheckSumRequestHandler = FileManager_fileGetCheckSumRequestHandlerImpl,
  .FileManager_fileGetOpenedHandlesCountRequestHandler = FileManager_fileGetOpenedHandlesCountRequestHandlerImpl,
  .FileManager_formatPartitionRequestHandler = FileManager_formatPartitionRequestHandlerImpl,
  .FileManager_fileDumpDirListToFileRequestHandler = FileManager_fileDumpDirListToFileRequestHandlerImpl,
  .FileManager_getStatisticsRequestHandler = FileManager_getStatisticsRequestHandlerImpl,
  .FileManager_clearStatisticsRequestHandler = FileManager_clearStatisticsRequestHandlerImpl,
  .FileManager_sdReinitRequestHandler = FileManager_sdReinitRequestHandlerImpl,
  .FileManager_dirMakeRequestHandler = FileManager_dirMakeRequestHandlerImpl,
  .FileManager_get_sd_card_statusRequestHandler = FileManager_get_sd_card_statusRequestHandlerImpl
};

/**********************************************************************
 *
 *  Local methods implementation
 *
 **********************************************************************/
// @START_USER@ USER_LOCAL_FUNC_IMPL
// Place static functions implementation here to preserve it during merge!!!
static FILEMANAGER_FManOpResult_t getFManOpResultForFileManagerOpResult(fm_result_t opRes)
{
    FILEMANAGER_FManOpResult_t result;

    switch (opRes)
    {
        case FM_RES_OK:
            result = FILEMANAGER_FMANOPRESULT_OK;
        break;

        case FM_RES_DISK_ERR:
            result = FILEMANAGER_FMANOPRESULT_DISK_ERR;
        break;

        case FM_RES_INT_ERR:
            result = FILEMANAGER_FMANOPRESULT_INT_ERR;
        break;

        case FM_RES_NOT_READY:
            result = FILEMANAGER_FMANOPRESULT_NOT_READY;
        break;

        case FM_RES_NO_FILE:
            result = FILEMANAGER_FMANOPRESULT_NO_FILE;
        break;

        case FM_RES_NO_PATH:
            result = FILEMANAGER_FMANOPRESULT_NO_PATH;
        break;

        case FM_RES_INVALID_NAME:
            result = FILEMANAGER_FMANOPRESULT_INVALID_NAME;
        break;

        case FM_RES_DENIED:
            result = FILEMANAGER_FMANOPRESULT_DENIED;
        break;

        case FM_RES_EXIST:
            result = FILEMANAGER_FMANOPRESULT_EXIST;
        break;

        case FM_RES_INVALID_OBJECT:
            result = FILEMANAGER_FMANOPRESULT_INVALID_OBJECT;
        break;

        case FM_RES_WRITE_PROTECTED:
            result = FILEMANAGER_FMANOPRESULT_WRITE_PROTECTED;
        break;

        case FM_RES_INVALID_DRIVE:
            result = FILEMANAGER_FMANOPRESULT_INVALID_DRIVE;
        break;

        case FM_RES_NOT_ENABLED:
            result = FILEMANAGER_FMANOPRESULT_NOT_ENABLED;
        break;

        case FM_RES_NO_FILESYSTEM:
            result = FILEMANAGER_FMANOPRESULT_NO_FILESYSTEM;
        break;

        case FM_RES_MKFS_ABORTED:
            result = FILEMANAGER_FMANOPRESULT_MKFS_ABORTED;
        break;

        case FM_RES_TIMEOUT:
            result = FILEMANAGER_FMANOPRESULT_TIMEOUT;
        break;

        case FM_RES_LOCKED:
            result = FILEMANAGER_FMANOPRESULT_LOCKED;
        break;

        case FM_RES_NOT_ENOUGH_CORE:
            result = FILEMANAGER_FMANOPRESULT_NOT_ENOUGH_CORE;
        break;

        case FM_RES_TOO_MANY_OPEN_FILES:
            result = FILEMANAGER_FMANOPRESULT_TOO_MANY_OPEN_FILES;
        break;

        case FM_RES_INVALID_PARAMETER:
            result = FILEMANAGER_FMANOPRESULT_INVALID_PARAMETER;
        break;

        default:
            result = FILEMANAGER_FMANOPRESULT_INVALID_PARAMETER;
        break;
    }

    return result;
}

static bool check_file_path_string(const char* file_path, const size_t max_path_len)
{
    bool ret = true;
    const size_t max_path_index = max_path_len - 1;
    if ('\0' != file_path[max_path_index])
    {
        // generally `fm_open_internal()` is safe enough to handle a non-terminated string,
        // but the network packet may be changed/corrupted in ways that would be difficult to debug
        // this check will solve this problem
        size_t len;
        len = strnlen(file_path, max_path_index);
        if ((max_path_index == len) ||
            (FM_MAX_PATH <= len))
        {
            ret = false;
        }
    }
    return ret;
}

// @END_USER@ USER_LOCAL_FUNC_IMPL

// @START@ Request handler for method FileManager::fileOpen (ID = 0x00000000)
static void FileManager_fileOpenRequestHandlerImpl(ReqContext_t *pReqCtx,
            const FileManagerfileOpenRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FILEMANAGER_FManFileHandle_t tHandle;
    FILEMANAGER_FManOpResult_t eRes;

    // @USER_VAR_SECTION_START@FileManager::fileOpen@
    // Put your local variables in this section to preserve during merge!
    fm_result_t fmRes;
    fm_handle_t fHandle;
    // @USER_VAR_SECTION_END@FileManager::fileOpen@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@FileManager::fileOpen@

        if (true == check_file_path_string(pRequestData->strFilePath, sizeof(pRequestData->strFilePath)))
        {
            fmRes = fm_open_internal(&fHandle, pRequestData->strFilePath, pRequestData->u8Mode);
        }
        else
        {
            fmRes = FM_RES_INVALID_NAME;
        }

        static_assert(sizeof(tHandle) == sizeof(fHandle));
        tHandle = (FM_RES_OK == fmRes) ? (FILEMANAGER_FManFileHandle_t)fHandle : (FILEMANAGER_FManFileHandle_t)NULL;

        eRes = getFManOpResultForFileManagerOpResult(fmRes);

        // @USER_CODE_SECTION_END@FileManager::fileOpen@

        respResult = FileManager_fileOpenResp(
                        &respCtx,
                        tHandle,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FILEMANAGER, FILEMANAGER_FILEOPEN_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method FileManager::fileOpen (ID = 0x00000000)

// @START@ Request handler for method FileManager::fileClose (ID = 0x00000001)
static void FileManager_fileCloseRequestHandlerImpl(ReqContext_t *pReqCtx,
            const FileManagerfileCloseRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FILEMANAGER_FManOpResult_t eRes;

    // @USER_VAR_SECTION_START@FileManager::fileClose@
    // Put your local variables in this section to preserve during merge!
    fm_result_t fmRes;
    fm_handle_t fHandle;
    // @USER_VAR_SECTION_END@FileManager::fileClose@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@FileManager::fileClose@

        fHandle = (fm_handle_t)pRequestData->tHandle;
        fmRes = fm_close(fHandle);

        eRes = getFManOpResultForFileManagerOpResult(fmRes);

        // @USER_CODE_SECTION_END@FileManager::fileClose@

        respResult = FileManager_fileCloseResp(
                        &respCtx,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FILEMANAGER, FILEMANAGER_FILECLOSE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method FileManager::fileClose (ID = 0x00000001)

// @START@ Request handler for method FileManager::fileRead (ID = 0x00000002)
static void FileManager_fileReadRequestHandlerImpl(ReqContext_t *pReqCtx,
            const FileManagerfileReadRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    uint8_t au8Data[230];
    uint8_t u8DataSize;
    uint32_t u32BytesRead;
    FILEMANAGER_FManOpResult_t eRes;

    // @USER_VAR_SECTION_START@FileManager::fileRead@
    // Put your local variables in this section to preserve during merge!
    fm_result_t fmRes;
    size_t bytesToRead;
    fm_handle_t fHandle;
    // @USER_VAR_SECTION_END@FileManager::fileRead@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@FileManager::fileRead@

        u32BytesRead = 0;
        (void)memset(au8Data, 0U, sizeof(au8Data));

        bytesToRead = pRequestData->u32BytesToRead;
        if (sizeof(au8Data) < bytesToRead)
        {
            bytesToRead = sizeof(au8Data);
        }

        fHandle = (fm_handle_t)pRequestData->tHandle;

        fmRes = fm_read_at_pos(fHandle,
                                au8Data,
                                bytesToRead,
                                &u32BytesRead,
                                pRequestData->u32Pos);

        // Maximum bytes read would be 230, limited by the FP frame size.
        u8DataSize = (fmRes == FM_RES_OK) ? (uint8_t)u32BytesRead : 0;

        eRes = getFManOpResultForFileManagerOpResult(fmRes);

        // @USER_CODE_SECTION_END@FileManager::fileRead@

        respResult = FileManager_fileReadResp(
                        &respCtx,
                        au8Data,
                        u8DataSize,
                        u32BytesRead,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FILEMANAGER, FILEMANAGER_FILEREAD_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method FileManager::fileRead (ID = 0x00000002)

// @START@ Request handler for method FileManager::fileWrite (ID = 0x00000003)
static void FileManager_fileWriteRequestHandlerImpl(ReqContext_t *pReqCtx,
            const FileManagerfileWriteRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    uint32_t u32BytesWritten;
    FILEMANAGER_FManOpResult_t eRes;

    // @USER_VAR_SECTION_START@FileManager::fileWrite@
    // Put your local variables in this section to preserve during merge!
    fm_result_t fmRes;
    fm_handle_t fHandle;
    // @USER_VAR_SECTION_END@FileManager::fileWrite@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@FileManager::fileWrite@

        u32BytesWritten = 0U;

        fHandle = (fm_handle_t)pRequestData->tHandle;

        fmRes = fm_write_at_pos(fHandle,
                                pRequestData->au8Data,
                                (pRequestData->u8DataSize <= sizeof(pRequestData->au8Data))
                                    ? (pRequestData->u8DataSize)
                                    : (sizeof(pRequestData->au8Data)),
                                &u32BytesWritten,
                                pRequestData->u32Pos);

        eRes = getFManOpResultForFileManagerOpResult(fmRes);

        // @USER_CODE_SECTION_END@FileManager::fileWrite@

        respResult = FileManager_fileWriteResp(
                        &respCtx,
                        u32BytesWritten,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FILEMANAGER, FILEMANAGER_FILEWRITE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method FileManager::fileWrite (ID = 0x00000003)

// @START@ Request handler for method FileManager::Rename (ID = 0x0000000F)
static void FileManager_RenameRequestHandlerImpl(ReqContext_t *pReqCtx,
            const FileManagerRenameRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FILEMANAGER_FManOpResult_t eRes;

    // @USER_VAR_SECTION_START@FileManager::Rename@
    // Put your local variables in this section to preserve during merge!
    fm_result_t fmRes;
    // @USER_VAR_SECTION_END@FileManager::Rename@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@FileManager::Rename@

        fmRes = fm_rename(pRequestData->strOldPath, pRequestData->strNewPath);

        eRes = getFManOpResultForFileManagerOpResult(fmRes);

        // @USER_CODE_SECTION_END@FileManager::Rename@

        respResult = FileManager_RenameResp(
                        &respCtx,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FILEMANAGER, FILEMANAGER_RENAME_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method FileManager::Rename (ID = 0x0000000F)

// @START@ Request handler for method FileManager::Delete (ID = 0x00000004)
static void FileManager_DeleteRequestHandlerImpl(ReqContext_t *pReqCtx,
            const FileManagerDeleteRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FILEMANAGER_FManOpResult_t eRes;

    // @USER_VAR_SECTION_START@FileManager::Delete@
    // Put your local variables in this section to preserve during merge!
    fm_result_t fmRes;
    // @USER_VAR_SECTION_END@FileManager::Delete@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@FileManager::Delete@

        fmRes = fm_delete(pRequestData->strPath);

        eRes = getFManOpResultForFileManagerOpResult(fmRes);

        // @USER_CODE_SECTION_END@FileManager::Delete@

        respResult = FileManager_DeleteResp(
                        &respCtx,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FILEMANAGER, FILEMANAGER_DELETE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method FileManager::Delete (ID = 0x00000004)

// @START@ Request handler for method FileManager::fileGetSize (ID = 0x00000005)
static void FileManager_fileGetSizeRequestHandlerImpl(ReqContext_t *pReqCtx,
            const FileManagerfileGetSizeRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    uint32_t u32FSize;
    FILEMANAGER_FManOpResult_t eRes;

    // @USER_VAR_SECTION_START@FileManager::fileGetSize@
    // Put your local variables in this section to preserve during merge!
    fm_result_t fmRes;
    fm_fast_file_info_t gfi;
    // @USER_VAR_SECTION_END@FileManager::fileGetSize@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@FileManager::fileGetSize@

        u32FSize = 0; // Init the size variable

        (void)memset(&gfi, 0, sizeof(gfi));

        fmRes = fm_stat(pRequestData->strFilePath, &gfi);

        if (FM_RES_OK == fmRes)
        {
            u32FSize = gfi.size;
        }

        eRes = getFManOpResultForFileManagerOpResult(fmRes);

        // @USER_CODE_SECTION_END@FileManager::fileGetSize@

        respResult = FileManager_fileGetSizeResp(
                        &respCtx,
                        u32FSize,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FILEMANAGER, FILEMANAGER_FILEGETSIZE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method FileManager::fileGetSize (ID = 0x00000005)

// @START@ Request handler for method FileManager::fileGetCheckSum (ID = 0x00000006)
static void FileManager_fileGetCheckSumRequestHandlerImpl(ReqContext_t *pReqCtx,
            const FileManagerfileGetCheckSumRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    uint32_t u32Cs;
    FILEMANAGER_FManOpResult_t eRes;

    // @USER_VAR_SECTION_START@FileManager::fileGetCheckSum@
    // Put your local variables in this section to preserve during merge!
    fm_result_t fmRes;
    // @USER_VAR_SECTION_END@FileManager::fileGetCheckSum@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@FileManager::fileGetCheckSum@

        fmRes = fm_crc(pRequestData->strFilePath, &u32Cs);

        eRes = getFManOpResultForFileManagerOpResult(fmRes);

        // @USER_CODE_SECTION_END@FileManager::fileGetCheckSum@

        respResult = FileManager_fileGetCheckSumResp(
                        &respCtx,
                        u32Cs,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FILEMANAGER, FILEMANAGER_FILEGETCHECKSUM_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method FileManager::fileGetCheckSum (ID = 0x00000006)

// @START@ Request handler for method FileManager::fileGetOpenedHandlesCount (ID = 0x00000007)
static void FileManager_fileGetOpenedHandlesCountRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    uint32_t u32HandlesCount;

    // @USER_VAR_SECTION_START@FileManager::fileGetOpenedHandlesCount@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@FileManager::fileGetOpenedHandlesCount@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@FileManager::fileGetOpenedHandlesCount@

        (void)fm_get_handle_count(NULL, &u32HandlesCount);

        // @USER_CODE_SECTION_END@FileManager::fileGetOpenedHandlesCount@

        respResult = FileManager_fileGetOpenedHandlesCountResp(
                        &respCtx,
                        u32HandlesCount
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FILEMANAGER, FILEMANAGER_FILEGETOPENEDHANDLESCOUNT_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method FileManager::fileGetOpenedHandlesCount (ID = 0x00000007)

// @START@ Request handler for method FileManager::formatPartition (ID = 0x00000008)
static void FileManager_formatPartitionRequestHandlerImpl(ReqContext_t *pReqCtx,
            const FileManagerformatPartitionRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FILEMANAGER_FManOpResult_t eRes;

    // @USER_VAR_SECTION_START@FileManager::formatPartition@
    // Put your local variables in this section to preserve during merge!
    fm_result_t fmRes;
    // @USER_VAR_SECTION_END@FileManager::formatPartition@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@FileManager::formatPartition@

        switch(pRequestData->ePartitionId)
        {
            case FILEMANAGER_FMANPARTITIONS_SD_PARTITION:
                fmRes = fm_format(FM_VOL_SD_PATH);
                break;
            default:
                fmRes = FM_RES_INVALID_DRIVE;
                break;
        }

        eRes = getFManOpResultForFileManagerOpResult(fmRes);

        // @USER_CODE_SECTION_END@FileManager::formatPartition@

        respResult = FileManager_formatPartitionResp(
                        &respCtx,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FILEMANAGER, FILEMANAGER_FORMATPARTITION_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method FileManager::formatPartition (ID = 0x00000008)

// @START@ Request handler for method FileManager::fileDumpDirListToFile (ID = 0x00000009)
static void FileManager_fileDumpDirListToFileRequestHandlerImpl(ReqContext_t *pReqCtx,
            const FileManagerfileDumpDirListToFileRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FILEMANAGER_FManOpResult_t eRes;

    // @USER_VAR_SECTION_START@FileManager::fileDumpDirListToFile@
    // Put your local variables in this section to preserve during merge!
    fm_result_t fmRes;
    // @USER_VAR_SECTION_END@FileManager::fileDumpDirListToFile@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@FileManager::fileDumpDirListToFile@

        if ((true == check_file_path_string(pRequestData->strFilePath, sizeof(pRequestData->strFilePath))) &&
            (true == check_file_path_string(pRequestData->strPattern, sizeof(pRequestData->strPattern))))
        {
            fmRes = fm_list(pRequestData->strFilePath, pRequestData->strPattern);
        }
        else
        {
            fmRes = FM_RES_INVALID_NAME;
        }

        eRes = getFManOpResultForFileManagerOpResult(fmRes);

        // @USER_CODE_SECTION_END@FileManager::fileDumpDirListToFile@

        respResult = FileManager_fileDumpDirListToFileResp(
                        &respCtx,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FILEMANAGER, FILEMANAGER_FILEDUMPDIRLISTTOFILE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method FileManager::fileDumpDirListToFile (ID = 0x00000009)

// @START@ Request handler for method FileManager::getStatistics (ID = 0x0000000A)
static void FileManager_getStatisticsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FILEMANAGER_Statistics_t sStats;

    // @USER_VAR_SECTION_START@FileManager::getStatistics@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@FileManager::getStatistics@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@FileManager::getStatistics@

        (void)memset(&sStats, 0, sizeof(sStats));

        uint16_t temp_stat;
        (void)fm_get_stat_by_id(FM_RES_DISK_ERR, &temp_stat); sStats.sErrCounters.u16DISK_ERR = temp_stat;
        (void)fm_get_stat_by_id(FM_RES_INT_ERR, &temp_stat); sStats.sErrCounters.u16INT_ERR = temp_stat;
        (void)fm_get_stat_by_id(FM_RES_NOT_READY, &temp_stat); sStats.sErrCounters.u16NOT_READY = temp_stat;
        (void)fm_get_stat_by_id(FM_RES_NO_FILE, &temp_stat); sStats.sErrCounters.u16NO_FILE = temp_stat;
        (void)fm_get_stat_by_id(FM_RES_NO_PATH, &temp_stat); sStats.sErrCounters.u16NO_PATH = temp_stat;
        (void)fm_get_stat_by_id(FM_RES_INVALID_NAME, &temp_stat); sStats.sErrCounters.u16INVALID_NAME = temp_stat;
        (void)fm_get_stat_by_id(FM_RES_DENIED, &temp_stat); sStats.sErrCounters.u16DENIED = temp_stat;
        (void)fm_get_stat_by_id(FM_RES_EXIST, &temp_stat); sStats.sErrCounters.u16EXIST = temp_stat;
        (void)fm_get_stat_by_id(FM_RES_INVALID_OBJECT, &temp_stat); sStats.sErrCounters.u16INVALID_OBJECT = temp_stat;
        (void)fm_get_stat_by_id(FM_RES_WRITE_PROTECTED, &temp_stat); sStats.sErrCounters.u16WRITE_PROTECTED = temp_stat;
        (void)fm_get_stat_by_id(FM_RES_INVALID_DRIVE, &temp_stat); sStats.sErrCounters.u16INVALID_DRIVE = temp_stat;
        (void)fm_get_stat_by_id(FM_RES_NOT_ENABLED, &temp_stat); sStats.sErrCounters.u16NOT_ENABLED = temp_stat;
        (void)fm_get_stat_by_id(FM_RES_NO_FILESYSTEM, &temp_stat); sStats.sErrCounters.u16NO_FILESYSTEM = temp_stat;
        (void)fm_get_stat_by_id(FM_RES_MKFS_ABORTED, &temp_stat); sStats.sErrCounters.u16MKFS_ABORTED = temp_stat;
        (void)fm_get_stat_by_id(FM_RES_TIMEOUT, &temp_stat); sStats.sErrCounters.u16TIMEOUT = temp_stat;
        (void)fm_get_stat_by_id(FM_RES_LOCKED, &temp_stat); sStats.sErrCounters.u16LOCKED = temp_stat;
        (void)fm_get_stat_by_id(FM_RES_NOT_ENOUGH_CORE, &temp_stat); sStats.sErrCounters.u16NOT_ENOUGH_CORE = temp_stat;
        (void)fm_get_stat_by_id(FM_RES_TOO_MANY_OPEN_FILES, &temp_stat); sStats.sErrCounters.u16TOO_MANY_OPEN_FILES = temp_stat;
        (void)fm_get_stat_by_id(FM_RES_INVALID_PARAMETER, &temp_stat); sStats.sErrCounters.u16INVALID_PARAMETER = temp_stat;

        // @USER_CODE_SECTION_END@FileManager::getStatistics@

        respResult = FileManager_getStatisticsResp(
                        &respCtx,
                        &sStats
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FILEMANAGER, FILEMANAGER_GETSTATISTICS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method FileManager::getStatistics (ID = 0x0000000A)

// @START@ Request handler for method FileManager::clearStatistics (ID = 0x0000000B)
static void FileManager_clearStatisticsRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;

    // @USER_VAR_SECTION_START@FileManager::clearStatistics@
    // Put your local variables in this section to preserve during merge!
    // @USER_VAR_SECTION_END@FileManager::clearStatistics@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@FileManager::clearStatistics@

        (void)fm_clear_stats();

        // @USER_CODE_SECTION_END@FileManager::clearStatistics@

        respResult = FileManager_clearStatisticsResp(
                        &respCtx
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FILEMANAGER, FILEMANAGER_CLEARSTATISTICS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method FileManager::clearStatistics (ID = 0x0000000B)

// @START@ Request handler for method FileManager::sdReinit (ID = 0x0000000C)
static void FileManager_sdReinitRequestHandlerImpl(ReqContext_t *pReqCtx,
            const FileManagersdReinitRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    bool bStatus;

    // @USER_VAR_SECTION_START@FileManager::sdReinit@
    // Put your local variables in this section to preserve during merge!
    fm_storage_status_t status;
    // @USER_VAR_SECTION_END@FileManager::sdReinit@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@FileManager::sdReinit@

        status = STORAGE_STATUS_ERROR;

        (void)fm_storage_init(FM_VOL_SD_PATH, pRequestData->bSynchronousCall ? 5000 : 0, &status);

        bStatus = (STORAGE_STATUS_READY == status);

        // @USER_CODE_SECTION_END@FileManager::sdReinit@

        respResult = FileManager_sdReinitResp(
                        &respCtx,
                        bStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FILEMANAGER, FILEMANAGER_SDREINIT_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method FileManager::sdReinit (ID = 0x0000000C)

// @START@ Request handler for method FileManager::dirMake (ID = 0x0000000D)
static void FileManager_dirMakeRequestHandlerImpl(ReqContext_t *pReqCtx,
            const FileManagerdirMakeRequestData_t* pRequestData)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FILEMANAGER_FManOpResult_t eRes;

    // @USER_VAR_SECTION_START@FileManager::dirMake@
    // Put your local variables in this section to preserve during merge!
    fm_result_t fmRes;
    // @USER_VAR_SECTION_END@FileManager::dirMake@

    if ((pReqCtx != NULL) && (pRequestData != NULL))
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@FileManager::dirMake@

        fmRes = fm_mkdir(pRequestData->strDirName);

        eRes = getFManOpResultForFileManagerOpResult(fmRes);

        // @USER_CODE_SECTION_END@FileManager::dirMake@

        respResult = FileManager_dirMakeResp(
                        &respCtx,
                        eRes
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FILEMANAGER, FILEMANAGER_DIRMAKE_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method FileManager::dirMake (ID = 0x0000000D)

// @START@ Request handler for method FileManager::get_sd_card_status (ID = 0x0000000E)
static void FileManager_get_sd_card_statusRequestHandlerImpl(ReqContext_t* pReqCtx)
{
    ESSATMAC_ErrCodes respResult;
    RespContext_t respCtx;
    FILEMANAGER_SDCardStatus_t eStatus;

    // @USER_VAR_SECTION_START@FileManager::get_sd_card_status@
    // Put your local variables in this section to preserve during merge!
    fm_storage_status_t status = FILEMANAGER_SDCARDSTATUS_ERROR;
    // @USER_VAR_SECTION_END@FileManager::get_sd_card_status@

    if (pReqCtx != NULL)
    {
        respCtx.nInterfaceNumber = pReqCtx->nInterfaceNumber;
        respCtx.netType = pReqCtx->netType;
        respCtx.nAddr = pReqCtx->nAddr;
        respCtx.seqId = pReqCtx->seqId;

        // @USER_CODE_SECTION_START@FileManager::get_sd_card_status@

        fm_storage_status(FM_VOL_SD_PATH, &status);
        switch(status)
        {
            case STORAGE_STATUS_ERROR: eStatus = FILEMANAGER_SDCARDSTATUS_ERROR; break;
            case STORAGE_STATUS_EJECTED: eStatus = FILEMANAGER_SDCARDSTATUS_EJECTED; break;
            case STORAGE_STATUS_NOT_INIT: eStatus = FILEMANAGER_SDCARDSTATUS_NOT_INIT; break;
            case STORAGE_STATUS_INITIALIZING: eStatus = FILEMANAGER_SDCARDSTATUS_NOT_INIT; break;
            case STORAGE_STATUS_BUSY: eStatus = FILEMANAGER_SDCARDSTATUS_NOT_INIT; break;
            case STORAGE_STATUS_READY: eStatus = FILEMANAGER_SDCARDSTATUS_READY; break;
            default:
                eStatus = FILEMANAGER_SDCARDSTATUS_ERROR; break;
        }

        // @USER_CODE_SECTION_END@FileManager::get_sd_card_status@

        respResult = FileManager_get_sd_card_statusResp(
                        &respCtx,
                        eStatus
                     );

        if (respResult != ESSATMAC_EC_OK)
            TRACE_ERROR(ES_SAT_FUNC_PROTOCOL_ID_FILEMANAGER, FILEMANAGER_GET_SD_CARD_STATUS_FUNCRESP_ID, respResult);
    }
}
// @END@ Request handler for method FileManager::get_sd_card_status (ID = 0x0000000E)


/**********************************************************************
 *
 *  Public functions
 *
 **********************************************************************/
void FileManagerServerAppInit(void)
{
    FileManager_registerServerApi(&FileManagerServerApiCtx);
}
