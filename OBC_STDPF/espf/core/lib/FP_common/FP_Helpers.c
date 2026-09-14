/*!
********************************************************************************************
* @file FP_Helpers.c
* @brief Protocol helpers implementation
********************************************************************************************
* @version
*
* @copyright         (C) Copyright EnduroSat
*
*                    Contents and presentations are protected world-wide.
*                    Any kind of using, copying etc. is prohibited without prior permission.
*                    All rights - incl. industrial property rights - are reserved.
*
*-------------------------------------------------------------------------------------------
* GENERATOR: org.endurosat.generators.macchiato.binders.Gen_C v2.14
*-------------------------------------------------------------------------------------------
* !!! Please note that this code is fully GENERATED and shall not be manually modified as
* all changes will be overwritten !!!
********************************************************************************************
*/

#include "FP_Helpers.h"
#include "FP_ProtocolServerCommon.h"

static SeqId_t msgId = 0U;

SeqId_t FP_Helpers_GenMsgId(void)
{
    return msgId++;
}

bool FP_Helpers_HandleDataInternal(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo, const ProtocolFuncArrayEntry_t *const p_func_array, const uint16_t func_array_size)
{
    // Basic header validity check
    if ((NULL == fp_DataInfo) ||
        (NULL == p_func_array) ||
        (fp_DataInfo->u16DataSize < sizeof(ESSA_Stack_FP_MsgHdr_t)) ||
        (NULL == fp_DataInfo->pu8Data))
    {
        return false;
    }
    ESSA_Stack_FP_MsgHdr_t *pHdr             = (ESSA_Stack_FP_MsgHdr_t *)fp_DataInfo->pu8Data;
    bool                    bIsFuncSupported = false;
    funcIdType_t            func_id          = pHdr->funcId;
    if (true == IS_RESPONSE(*pHdr))
    {
        func_id = GET_FUNC_ID(*pHdr);
    }
    for (uint16_t i = 0; i < func_array_size; i++)
    {
        if (p_func_array[i].funcId == func_id)
        {
            if (p_func_array[i].pfFunc != NULL)
            {
                bIsFuncSupported = true;
                p_func_array[i].pfFunc(fp_DataInfo);
            }
            break;
        }
    }
    if (true == IS_REQUEST(*pHdr))
    {
        if (!bIsFuncSupported)
        {
            (void)ProtocolSendErrorResp(fp_DataInfo, (uint8_t)ESSA_FP_ERRCODE_FUNC_NOT_SUPPORTED);
        }
    }
    return bIsFuncSupported;
}
