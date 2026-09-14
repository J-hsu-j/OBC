/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup cubeadcs_gen2
 * @{
 *
 * @file     cubeadcs_gen2_gw.c
 * @brief    Gateway for accessing the API of CubeADCS Gen2. File is partially generated!
 *
 * @}
 */

/*
********************************************************************************************
* INCLUDES
********************************************************************************************
*/
#include "../inc/cubeadcs_gen2_gw.h"
#include "cubeObc/arch/cubeObc_critical.h"
#include "es_cdef.h"

/*
*********************************************************************************************
* INTERNAL DEFINES
*********************************************************************************************
*/

/*
*********************************************************************************************
* INTERNAL TYPES DEFINITION
*********************************************************************************************
*/

/*
*********************************************************************************************
* EXTERNAL VARIABLES DEFINITION
*********************************************************************************************
*/

/*
*********************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
*********************************************************************************************
*/

/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
*********************************************************************************************
*/

/**
 * @brief Gain exclusive access to the CubeADCS Gen2 API.
 */
static inline bool cubeadcs_gen2_crit_section_start(const uint32_t timeout)
{
    return cubeObc_critical_enter(timeout);
}

/**
 * @brief Relinquish exclusive access to the CubeADCS Gen2 API.
 */
static inline void cubeadcs_gen2_crit_section_end(void)
{
    cubeObc_critical_exit();
}

/*
*********************************************************************************************
* EXTERNAL (NON-STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/

void cubeadcs_gen2_setup_endpoint(TypeDef_TctlmEndpoint *const    p_endpoint,
                                  const TypeDef_CommsEndpointType endpoint_type,
                                  const U32                       timeout)
{
    if (p_endpoint != NULL)
    {
        // OBC communicates directly only with the CubeComputer node.
        p_endpoint->nodeType    = TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_TYPE_CUBE_COMPUTER;
        p_endpoint->type        = endpoint_type;
        p_endpoint->proto       = TYPEDEF__COMMS_PROTOCOL_CUBESPACE;
        p_endpoint->addr        = 0;
        p_endpoint->addrPass    = 0;
        p_endpoint->cspSrcPort  = 0;
        p_endpoint->timeout     = timeout;
        p_endpoint->passthrough = FALSE;
    }
}

ErrorCode cubeadcs_gen2_setup_passthrough(TypeDef_TctlmEndpoint *const                  p_endpoint,
                                          const TypesCommonFrameworkTypes1_AbstractNode node_id)
{
    ErrorCode result = CUBEOBC_ERROR_TODO;

    if ((node_id != TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_INVALID) && (node_id != TYPES_COMMON_FRAMEWORK_TYPES_1__NODE_COMPUTER))
    {
        if (p_endpoint != NULL)
        {
            // Do not allow the endpoint to be used for pass-through communication unless the target node is successfully set.
            p_endpoint->passthrough = FALSE;
            // Command CubeADCS to set a target node for pass-through communication.
            TypesCubeComputerCommon3_PassThrough pt;
            pt.targetNode = node_id;
            result        = tctlmCubeComputerCommon3_setPassThrough(p_endpoint, &pt);
            if (result == CUBEOBC_ERROR_OK)
            {
                // Target node successfully set. Enable pass-through communication via the node.
                p_endpoint->passthrough = TRUE;
            }
        }
    }
    else
    {
        // No pass-through is actually requested
        result = CUBEOBC_ERROR_OK;
    }

    return result;
}

// CUBE_ADCS_GEN_SECTION_START
ErrorCode CubeADCS_Gen2_CommonFramework1_setResetRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonFramework1_Reset *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_setReset(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonFramework1_setUnixTimeRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonFramework1_UnixTime *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_setUnixTime(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonFramework1_setErrorLogIndexRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonFramework1_ErrorLogIndex *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_setErrorLogIndex(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonFramework1_setErrorLogEntryRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonFramework1_ErrorLogEntry *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_setErrorLogEntry(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonFramework1_setErrorLogClearRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_setErrorLogClear(&endpoint);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonFramework1_setErrorLogSettingsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonFramework1_ErrorLogSettings *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_setErrorLogSettings(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonFramework1_setConfigPersistRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_setConfigPersist(&endpoint);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonFramework1_getIdentificationRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonFramework1_Identification *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_getIdentification(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonFramework1_getSerialNumberRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonFramework1_SerialNumber *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_getSerialNumber(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonFramework1_getErrorLogIndexRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonFramework1_ErrorLogIndex *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_getErrorLogIndex(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonFramework1_getErrorLogEntryRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonFramework1_ErrorLogEntry *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_getErrorLogEntry(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonFramework1_getErrorLogSettingsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonFramework1_ErrorLogSettings *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_getErrorLogSettings(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonFramework1_getUnixTimeRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonFramework1_UnixTime *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_getUnixTime(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonFramework1_getConfigPersistDiagnosticsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonFramework1_ConfigPersistDiagnostics *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_getConfigPersistDiagnostics(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonFramework1_getCommsStatusRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonFramework1_CommsStatus *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_getCommsStatus(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonFramework1_getVersionRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonFramework1_Version *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_getVersion(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonFramework1_getBootStatusRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonFramework1_BootStatus *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_getBootStatus(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonFramework1_getTelecommandAcknowledgeRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonFramework1_TelecommandAcknowledge *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_getTelecommandAcknowledge(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonFramework1_getCommonErrorCodesRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonFramework1_CommonErrorCodes *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_getCommonErrorCodes(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonFramework1_getIdentification2RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonFramework1_Identification2 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonFramework1_getIdentification2(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonTransfer1_setTransferFrameRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonTransfer1_TransferFrame *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonTransfer1_setTransferFrame(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonTransfer1_setFrameRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonTransfer1_Frame *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonTransfer1_setFrame(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonTransfer1_getFrameInfoRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonTransfer1_FrameInfo *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonTransfer1_getFrameInfo(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CommonTransfer1_getFrameRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCommonTransfer1_Frame *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCommonTransfer1_getFrame(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeAurigaControlProgram1_setOhPowerStatesRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeAurigaControlProgram1_OhPowerStates *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeAurigaControlProgram1_setOhPowerStates(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeAurigaControlProgram1_setRtcSyncRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeAurigaControlProgram1_setRtcSync(&endpoint);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeAurigaControlProgram1_setConfigurationRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeAurigaControlProgram1_Configuration *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeAurigaControlProgram1_setConfiguration(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeAurigaControlProgram1_setAurigaSelfTestRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeAurigaControlProgram1_AurigaSelfTest *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeAurigaControlProgram1_setAurigaSelfTest(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeAurigaControlProgram1_setExtMemTestRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeAurigaControlProgram1_ExtMemTest *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeAurigaControlProgram1_setExtMemTest(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeAurigaControlProgram1_setSpwTestRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeAurigaControlProgram1_SpwTest *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeAurigaControlProgram1_setSpwTest(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeAurigaControlProgram1_getOhPowerStatesRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeAurigaControlProgram1_OhPowerStates *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeAurigaControlProgram1_getOhPowerStates(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeAurigaControlProgram1_getHealthTlmRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeAurigaControlProgram1_HealthTlm *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeAurigaControlProgram1_getHealthTlm(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeAurigaControlProgram1_getAurigaStatusRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeAurigaControlProgram1_AurigaStatus *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeAurigaControlProgram1_getAurigaStatus(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeAurigaControlProgram1_getAurigaAttitudeDataRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeAurigaControlProgram1_AurigaAttitudeData *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeAurigaControlProgram1_getAurigaAttitudeData(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeAurigaControlProgram1_getConfigurationRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeAurigaControlProgram1_Configuration *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeAurigaControlProgram1_getConfiguration(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeAurigaControlProgram1_getAurigaSelfTestResultsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeAurigaControlProgram1_AurigaSelfTestResults *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeAurigaControlProgram1_getAurigaSelfTestResults(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeAurigaControlProgram1_getExtMemTestResultRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeAurigaControlProgram1_ExtMemTestResult *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeAurigaControlProgram1_getExtMemTestResult(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeAurigaControlProgram1_getSpwTestResultRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeAurigaControlProgram1_SpwTestResult *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeAurigaControlProgram1_getSpwTestResult(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader6_setEccSimRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader6_EccSim *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader6_setEccSim(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader6_getWarningsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader6_Warnings *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader6_getWarnings(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_setResetRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_Reset *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_setReset(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_setHaltRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_setHalt(&endpoint);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_setConfigRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_Config *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_setConfig(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_setDefaultAppTargetRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_DefaultAppTarget *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_setDefaultAppTarget(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_setJumpToDefaultAppRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_setJumpToDefaultApp(&endpoint);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_setJumpToAppRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_JumpToApp *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_setJumpToApp(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_setJumpToAddressRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_JumpToAddress *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_setJumpToAddress(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_setResetFileInfoIdxRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_setResetFileInfoIdx(&endpoint);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_setWriteFileSetupRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_WriteFileSetup *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_setWriteFileSetup(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_setDeleteFileEntryRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_DeleteFileEntry *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_setDeleteFileEntry(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_setWriteMemorySetupRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_WriteMemorySetup *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_setWriteMemorySetup(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_setReadMemorySetupRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_ReadMemorySetup *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_setReadMemorySetup(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_setEraseMemorySetupRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_EraseMemorySetup *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_setEraseMemorySetup(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_setOptionBytesRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_OptionBytes *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_setOptionBytes(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_setCommitOptionBytesRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_CommitOptionBytes *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_setCommitOptionBytes(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_setOptionBytesF7RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_OptionBytesF7 *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_setOptionBytesF7(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_getIdentificationRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_Identification *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_getIdentification(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_getSerialNumberRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_SerialNumber *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_getSerialNumber(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_getConfigRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_Config *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_getConfig(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_getStateRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_State *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_getState(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_getErrorsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_Errors *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_getErrors(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_getFileInfoRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_FileInfo *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_getFileInfo(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_getDefaultAppTargetRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_DefaultAppTarget *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_getDefaultAppTarget(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_getOptionBytesRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_OptionBytes *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_getOptionBytes(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_getCommsStatusRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_CommsStatus *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_getCommsStatus(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_getMemMapRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_MemMap *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_getMemMap(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_getOptionBytesF7RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_OptionBytesF7 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_getOptionBytesF7(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeCommonBaseBootloader5_getTelecommandAcknowledgeRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeCommonBaseBootloader5_TelecommandAcknowledge *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeCommonBaseBootloader5_getTelecommandAcknowledge(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setConfigDefaultModesRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigDefaultModes *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setConfigDefaultModes(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMountRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigMount *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setConfigMount(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMag0OrbitCalRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigMag0OrbitCal *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setConfigMag0OrbitCal(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMag1OrbitCalRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigMag1OrbitCal *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setConfigMag1OrbitCal(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAdcsControllerRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigAdcsController *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setConfigAdcsController(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAdcsEstimatorRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigAdcsEstimator *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setConfigAdcsEstimator(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAdcsSatelliteRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigAdcsSatellite *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setConfigAdcsSatellite(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setConfigOrbitSatParamsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigOrbitSatParams *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setConfigOrbitSatParams(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setConfigOrbitTargetParamsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigOrbitTargetParams *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setConfigOrbitTargetParams(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setConfigNodeSelectionRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigNodeSelection *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setConfigNodeSelection(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setConfigActuatorRwlRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigActuatorRwl *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setConfigActuatorRwl(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setConfigActuatorMtqRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigActuatorMtq *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setConfigActuatorMtq(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setConfigMagSensingElementRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigMagSensingElement *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setConfigMagSensingElement(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setConfigAsgp4RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigAsgp4 *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setConfigAsgp4(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setConModeRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConMode *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setConMode(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setEstModeRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_EstMode *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setEstMode(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setOrbModeRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_OrbMode *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setOrbMode(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setAdcsRunModeRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_AdcsRunMode *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setAdcsRunMode(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setAdcsOpStateRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_AdcsOpState *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setAdcsOpState(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setSimSensorRawRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_SimSensorRaw *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setSimSensorRaw(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setOpenLoopCommandMtqRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_OpenLoopCommandMtq *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setOpenLoopCommandMtq(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setOpenLoopCommandRwlRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_OpenLoopCommandRwl *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setOpenLoopCommandRwl(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setOpenLoopCommandHxyzRWRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_OpenLoopCommandHxyzRW *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setOpenLoopCommandHxyzRW(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceRpyRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ReferenceRpy *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setReferenceRpy(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceTargetRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ReferenceTarget *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setReferenceTarget(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceIrcVectorRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ReferenceIrcVector *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setReferenceIrcVector(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setReferenceFmcParamRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ReferenceFmcParam *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setReferenceFmcParam(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setDeployCommandMagRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_DeployCommandMag *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setDeployCommandMag(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setGnssSensorCmdRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_GnssSensorCmd *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setGnssSensorCmd(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_setFileTransferSetupRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_FileTransferSetup *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_setFileTransferSetup(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getConfigDefaultModesRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigDefaultModes *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getConfigDefaultModes(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMountRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigMount *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getConfigMount(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMag0OrbitCalRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigMag0OrbitCal *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getConfigMag0OrbitCal(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMag1OrbitCalRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigMag1OrbitCal *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getConfigMag1OrbitCal(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAdcsControllerRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigAdcsController *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getConfigAdcsController(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAdcsEstimatorRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigAdcsEstimator *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getConfigAdcsEstimator(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAdcsSatelliteRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigAdcsSatellite *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getConfigAdcsSatellite(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getConfigOrbitSatParamsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigOrbitSatParams *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getConfigOrbitSatParams(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getConfigOrbitTargetParamsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigOrbitTargetParams *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getConfigOrbitTargetParams(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getConfigNodeSelectionRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigNodeSelection *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getConfigNodeSelection(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getConfigActuatorRwlRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigActuatorRwl *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getConfigActuatorRwl(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getConfigActuatorMtqRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigActuatorMtq *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getConfigActuatorMtq(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getConfigMagSensingElementRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigMagSensingElement *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getConfigMagSensingElement(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getConfigAsgp4RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConfigAsgp4 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getConfigAsgp4(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getConModeRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ConMode *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getConMode(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getEstModeRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_EstMode *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getEstMode(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getOrbModeRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_OrbMode *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getOrbMode(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getAdcsRunModeRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_AdcsRunMode *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getAdcsRunMode(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getAdcsOpStateRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_AdcsOpState *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getAdcsOpState(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getSimSensorRawRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_SimSensorRaw *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getSimSensorRaw(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getOpenLoopCommandMtqRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_OpenLoopCommandMtq *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getOpenLoopCommandMtq(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getOpenLoopCommandRwlRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_OpenLoopCommandRwl *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getOpenLoopCommandRwl(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getOpenLoopCommandHxyzRWRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_OpenLoopCommandHxyzRW *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getOpenLoopCommandHxyzRW(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceRpyRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ReferenceRpy *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getReferenceRpy(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceTargetRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ReferenceTarget *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getReferenceTarget(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceIrcVectorRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ReferenceIrcVector *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getReferenceIrcVector(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getReferenceFmcParamRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_ReferenceFmcParam *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getReferenceFmcParam(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getCubeNodePortMapRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_CubeNodePortMap *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getCubeNodePortMap(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmHilRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmHil *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmHil(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmExecutionPointRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmExecutionPoint *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmExecutionPoint(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmAsgp4RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmAsgp4 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmAsgp4(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmNodeInitStateRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmNodeInitState *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmNodeInitState(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmLitefuforsHealthRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmLitefuforsHealth *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmLitefuforsHealth(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getFileTransferSetupRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_FileTransferSetup *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getFileTransferSetup(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getFileTransferStatusRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_FileTransferStatus *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getFileTransferStatus(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getFileInfoRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_FileInfo *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getFileInfo(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawCssRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmSensorRawCss *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmSensorRawCss(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawMagRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmSensorRawMag *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmSensorRawMag(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawGyroRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmSensorRawGyro *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmSensorRawGyro(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorRawRwlRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmSensorRawRwl *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmSensorRawRwl(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalFssRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmSensorCalFss *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmSensorCalFss(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalCssRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmSensorCalCss *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmSensorCalCss(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalMagRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmSensorCalMag *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmSensorCalMag(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalGyroRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmSensorCalGyro *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmSensorCalGyro(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalHssRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmSensorCalHss *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmSensorCalHss(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalStrRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmSensorCalStr *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmSensorCalStr(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalGnssRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmSensorCalGnss *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmSensorCalGnss(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmSensorCalRwlRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmSensorCalRwl *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmSensorCalRwl(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmModelsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmModels *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmModels(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmEstimatorMainRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmEstimatorMain *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmEstimatorMain(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmEstimatorBackupRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmEstimatorBackup *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmEstimatorBackup(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmEstimatorMainHighResRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmEstimatorMainHighRes *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmEstimatorMainHighRes(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmControllerRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmController *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmController(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmGnssRawRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmGnssRaw *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmGnssRaw(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmExtSensorRawRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmExtSensorRaw *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmExtSensorRaw(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrPst3sRawRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmStrPst3sRaw *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmStrPst3sRaw(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmFssCubeSenseSunRawRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmFssCubeSenseSunRaw *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmFssCubeSenseSunRaw(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmHssCubeSenseEarthRawRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmHssCubeSenseEarthRaw *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmHssCubeSenseEarthRaw(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmRwlNssRwlRawRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmRwlNssRwlRaw *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmRwlNssRwlRaw(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrCubeStarRawRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmStrCubeStarRaw *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmStrCubeStarRaw(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmGyrLitefuforsRawRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmGyrLitefuforsRaw *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmGyrLitefuforsRaw(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrCubeAurigaRawRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmStrCubeAurigaRaw *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmStrCubeAurigaRaw(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmAcpExecutionRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmAcpExecution *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmAcpExecution(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmTorquerCurrentsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmTorquerCurrents *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmTorquerCurrents(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmCubeComputerHealthRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmCubeComputerHealth *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmCubeComputerHealth(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmFssCubeSenseSunHealthRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmFssCubeSenseSunHealth *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmFssCubeSenseSunHealth(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmHssCubeSenseEarthHealthRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmHssCubeSenseEarthHealth *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmHssCubeSenseEarthHealth(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmCubeMagHealthRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmCubeMagHealth *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmCubeMagHealth(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmRwlHealthRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmRwlHealth *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmRwlHealth(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrPst3sHealthRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmStrPst3sHealth *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmStrPst3sHealth(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmNssRwlHealthRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmNssRwlHealth *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmNssRwlHealth(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrHealthRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmStrHealth *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmStrHealth(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmGnssUartStatusRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmGnssUartStatus *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmGnssUartStatus(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerControlProgram8_getTlmStrAurigaHealthRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerControlProgram8_TlmStrAurigaHealth *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerControlProgram8_getTlmStrAurigaHealth(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_setPassThroughRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_PassThrough *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_setPassThrough(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_setPowerStateRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_PowerState *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_setPowerState(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_setImageTransferSetupRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_ImageTransferSetup *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_setImageTransferSetup(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_setImageFileInfoResetRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_setImageFileInfoReset(&endpoint);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_setPortMapRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_PortMap *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_setPortMap(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_setEraseLogDataRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_EraseLogData *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_setEraseLogData(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_setEventLogFilterTransferSetupRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_EventLogFilterTransferSetup *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_setEventLogFilterTransferSetup(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_setTelemetryLogTransferSetupRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_TelemetryLogTransferSetup *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_setTelemetryLogTransferSetup(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_setDummyEventRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_DummyEvent *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_setDummyEvent(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_setUnsolicitedEventSetupRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_UnsolicitedEventSetup *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_setUnsolicitedEventSetup(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_setUnsolicitedTlmSetupRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_UnsolicitedTlmSetup *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_setUnsolicitedTlmSetup(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_getPassThroughRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_PassThrough *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_getPassThrough(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_getPowerStateRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_PowerState *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_getPowerState(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_getPortDiagnosticsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_PortDiagnostics *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_getPortDiagnostics(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_getPortMapRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_PortMap *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_getPortMap(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_getExpectedNodesRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_ExpectedNodes *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_getExpectedNodes(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_getImageTransferStatusRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_ImageTransferStatus *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_getImageTransferStatus(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_getImageFileInfoRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_ImageFileInfo *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_getImageFileInfo(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_getComponentErrorCodesRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_ComponentErrorCodes *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_getComponentErrorCodes(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_getEventLogStatusRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_EventLogStatus *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_getEventLogStatus(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_getTelemtryLogStatusRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_TelemtryLogStatus *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_getTelemtryLogStatus(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_getUnsolicitedEventSetupRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_UnsolicitedEventSetup *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_getUnsolicitedEventSetup(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_getUnsolicitedTlmSetupRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_UnsolicitedTlmSetup *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_getUnsolicitedTlmSetup(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeComputerCommon3_getTelemtryLogInclusionMasksRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeComputerCommon3_TelemtryLogInclusionMasks *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeComputerCommon3_getTelemtryLogInclusionMasks(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeIrControlProgram1_setConfigurationRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeIrControlProgram1_Configuration *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeIrControlProgram1_setConfiguration(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeIrControlProgram1_setImageTransferSetupRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeIrControlProgram1_ImageTransferSetup *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeIrControlProgram1_setImageTransferSetup(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeIrControlProgram1_setDeadPixelsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeIrControlProgram1_DeadPixels *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeIrControlProgram1_setDeadPixels(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeIrControlProgram1_setRequestDeadPixelRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeIrControlProgram1_RequestDeadPixel *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeIrControlProgram1_setRequestDeadPixel(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeIrControlProgram1_getMeasurementAndTriggerRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeIrControlProgram1_MeasurementAndTrigger *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeIrControlProgram1_getMeasurementAndTrigger(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeIrControlProgram1_getMeasurementRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeIrControlProgram1_Measurement *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeIrControlProgram1_getMeasurement(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeIrControlProgram1_getMeasurementMetadataRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeIrControlProgram1_MeasurementMetadata *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeIrControlProgram1_getMeasurementMetadata(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeIrControlProgram1_getHealthTlmRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeIrControlProgram1_HealthTlm *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeIrControlProgram1_getHealthTlm(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeIrControlProgram1_getConfigurationRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeIrControlProgram1_Configuration *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeIrControlProgram1_getConfiguration(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeIrControlProgram1_getProfileTimingRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeIrControlProgram1_ProfileTiming *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeIrControlProgram1_getProfileTiming(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeIrControlProgram1_getRequestedDeadPixelRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeIrControlProgram1_RequestedDeadPixel *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeIrControlProgram1_getRequestedDeadPixel(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramCommon1_setMmcConfigRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramCommon1_MmcConfig *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramCommon1_setMmcConfig(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramCommon1_setSamplePrimaryRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramCommon1_setSamplePrimary(&endpoint);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramCommon1_setConfigRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramCommon1_Config *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramCommon1_setConfig(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramCommon1_setMmcCalibrationRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramCommon1_MmcCalibration *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramCommon1_setMmcCalibration(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramCommon1_getMmcConfigRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramCommon1_MmcConfig *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramCommon1_getMmcConfig(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramCommon1_getStateRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramCommon1_State *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramCommon1_getState(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagMeasurementRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramCommon1_PrimaryMagMeasurement *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramCommon1_getPrimaryMagMeasurement(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagMeasurementRawRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramCommon1_PrimaryMagMeasurementRaw *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramCommon1_getPrimaryMagMeasurementRaw(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagTempRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramCommon1_PrimaryMagTemp *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramCommon1_getPrimaryMagTemp(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramCommon1_getConfigRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramCommon1_Config *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramCommon1_getConfig(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramCommon1_getPrimaryMagDiagnosticsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramCommon1_PrimaryMagDiagnostics *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramCommon1_getPrimaryMagDiagnostics(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramCommon1_getMmcCalibrationRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramCommon1_MmcCalibration *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramCommon1_getMmcCalibration(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramCompact1_getHealthTlmRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramCompact1_HealthTlm *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramCompact1_getHealthTlm(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramDeploy1_setPniConfigRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramDeploy1_PniConfig *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramDeploy1_setPniConfig(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramDeploy1_setSampleRedRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramDeploy1_setSampleRed(&endpoint);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramDeploy1_setDeployRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramDeploy1_Deploy *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramDeploy1_setDeploy(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramDeploy1_setDeployArmRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramDeploy1_DeployArm *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramDeploy1_setDeployArm(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramDeploy1_setPniCalibrationRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramDeploy1_PniCalibration *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramDeploy1_setPniCalibration(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramDeploy1_getHealthTlmRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramDeploy1_HealthTlm *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramDeploy1_getHealthTlm(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramDeploy1_getPniConfigRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramDeploy1_PniConfig *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramDeploy1_getPniConfig(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagMeasurementRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramDeploy1_RedMagMeasurement *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramDeploy1_getRedMagMeasurement(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagMeasurementRawRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramDeploy1_RedMagMeasurementRaw *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramDeploy1_getRedMagMeasurementRaw(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagTempRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramDeploy1_RedMagTemp *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramDeploy1_getRedMagTemp(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramDeploy1_getDeploymentStatusRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramDeploy1_DeploymentStatus *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramDeploy1_getDeploymentStatus(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramDeploy1_getRedMagDiagnosticsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramDeploy1_RedMagDiagnostics *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramDeploy1_getRedMagDiagnostics(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeMagControlProgramDeploy1_getPniCalibrationRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeMagControlProgramDeploy1_PniCalibration *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeMagControlProgramDeploy1_getPniCalibration(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_setUforsPowerRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramLitefufors1_UforsPower *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramLitefufors1_setUforsPower(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_setNodeSvcSettingsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramLitefufors1_NodeSvcSettings *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramLitefufors1_setNodeSvcSettings(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_setUforsSvcSettingsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramLitefufors1_UforsSvcSettings *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramLitefufors1_setUforsSvcSettings(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getNodeSvcSettingsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramLitefufors1_NodeSvcSettings *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramLitefufors1_getNodeSvcSettings(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsSvcSettingsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramLitefufors1_UforsSvcSettings *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramLitefufors1_getUforsSvcSettings(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getNodeSvcStatusRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramLitefufors1_NodeSvcStatus *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramLitefufors1_getNodeSvcStatus(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsSvcStatusRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramLitefufors1_UforsSvcStatus *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramLitefufors1_getUforsSvcStatus(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramLitefufors1_UforsTlm *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramLitefufors1_getUforsTlm(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort1RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramLitefufors1_UforsTlmPort1 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramLitefufors1_getUforsTlmPort1(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort2RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramLitefufors1_UforsTlmPort2 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramLitefufors1_getUforsTlmPort2(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort3RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramLitefufors1_UforsTlmPort3 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramLitefufors1_getUforsTlmPort3(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramLitefufors1_getUforsTlmPort4RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramLitefufors1_UforsTlmPort4 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramLitefufors1_getUforsTlmPort4(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNodeSvcSettingsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlCommon1_NodeSvcSettings *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlCommon1_setNodeSvcSettings(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlSvcSettingsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlCommon1_NssRwlSvcSettings *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlCommon1_setNssRwlSvcSettings(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlPowerRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlCommon1_NssRwlPower *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlCommon1_setNssRwlPower(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlWheelSpeedRefRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlCommon1_NssRwlWheelSpeedRef *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlCommon1_setNssRwlWheelSpeedRef(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlTorqueRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlCommon1_NssRwlTorque *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlCommon1_setNssRwlTorque(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlMotorCurrentRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlCommon1_NssRwlMotorCurrent *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlCommon1_setNssRwlMotorCurrent(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_setNssRwlSoftwareResetRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlCommon1_NssRwlSoftwareReset *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlCommon1_setNssRwlSoftwareReset(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNodeSvcSettingsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlCommon1_NodeSvcSettings *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlCommon1_getNodeSvcSettings(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNodeSvcStatusRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlCommon1_NodeSvcStatus *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlCommon1_getNodeSvcStatus(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlSvcSettingsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlCommon1_NssRwlSvcSettings *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlCommon1_getNssRwlSvcSettings(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlSvcStatusRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlCommon1_NssRwlSvcStatus *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlCommon1_getNssRwlSvcStatus(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlWheelSpeed1RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlCommon1_NssRwlWheelSpeed1 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlCommon1_getNssRwlWheelSpeed1(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlTlmStandard1RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlCommon1_NssRwlTlmStandard1 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlCommon1_getNssRwlTlmStandard1(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlTlmExtended1RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlCommon1_NssRwlTlmExtended1 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlCommon1_getNssRwlTlmExtended1(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlTlmSystem1RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlCommon1_NssRwlTlmSystem1 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlCommon1_getNssRwlTlmSystem1(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlCommon1_getNssRwlWheelSpeedAllRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlCommon1_NssRwlWheelSpeedAll *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlCommon1_getNssRwlWheelSpeedAll(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlWheelSpeed2RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlQuad1_NssRwlWheelSpeed2 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlQuad1_getNssRwlWheelSpeed2(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlWheelSpeed3RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlQuad1_NssRwlWheelSpeed3 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlQuad1_getNssRwlWheelSpeed3(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlWheelSpeed4RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlQuad1_NssRwlWheelSpeed4 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlQuad1_getNssRwlWheelSpeed4(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmStandard2RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmStandard2 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlQuad1_getNssRwlTlmStandard2(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmStandard3RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmStandard3 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlQuad1_getNssRwlTlmStandard3(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmStandard4RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmStandard4 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlQuad1_getNssRwlTlmStandard4(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmExtended2RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmExtended2 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlQuad1_getNssRwlTlmExtended2(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmExtended3RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmExtended3 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlQuad1_getNssRwlTlmExtended3(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmExtended4RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmExtended4 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlQuad1_getNssRwlTlmExtended4(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmSystem2RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmSystem2 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlQuad1_getNssRwlTlmSystem2(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmSystem3RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmSystem3 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlQuad1_getNssRwlTlmSystem3(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramNssrwlQuad1_getNssRwlTlmSystem4RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramNssrwlQuad1_NssRwlTlmSystem4 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramNssrwlQuad1_getNssRwlTlmSystem4(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sNumberNavigationStarsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sNumberNavigationStars *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_setPst3sNumberNavigationStars(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sExposureRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sExposure *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_setPst3sExposure(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sFSSTRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sFSST *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_setPst3sFSST(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSecondCalibrationRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sSecondCalibration *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_setPst3sSecondCalibration(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sTrackingModeThresholdRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sTrackingModeThreshold *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_setPst3sTrackingModeThreshold(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sQuaternionFilteringRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sQuaternionFiltering *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_setPst3sQuaternionFiltering(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSystemResetRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sSystemReset *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_setPst3sSystemReset(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sPowerRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sPower *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_setPst3sPower(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sImageFixedThresholdRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sImageFixedThreshold *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_setPst3sImageFixedThreshold(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSvcSettingsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sSvcSettings *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_setPst3sSvcSettings(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setNodeSvcSettingsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_NodeSvcSettings *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_setNodeSvcSettings(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSaaModeRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sSaaMode *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_setPst3sSaaMode(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sSaaThresholdRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sSaaThreshold *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_setPst3sSaaThreshold(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sDynamicModeRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sDynamicMode *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_setPst3sDynamicMode(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_setPst3sEdacOffRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sEdacOff *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_setPst3sEdacOff(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sSvcStatusRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sSvcStatus *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_getPst3sSvcStatus(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sTlm1RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sTlm1 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_getPst3sTlm1(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sAttitude1RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sAttitude1 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_getPst3sAttitude1(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sHousekeeping1RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sHousekeeping1 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_getPst3sHousekeeping1(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sConfig1RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sConfig1 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_getPst3sConfig1(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getPst3sSvcSettingsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_Pst3sSvcSettings *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_getPst3sSvcSettings(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getNodeSvcStatusRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_NodeSvcStatus *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_getNodeSvcStatus(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sCommon1_getNodeSvcSettingsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sCommon1_NodeSvcSettings *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sCommon1_getNodeSvcSettings(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sTlm2RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sQuad1_Pst3sTlm2 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sQuad1_getPst3sTlm2(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sTlm3RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sQuad1_Pst3sTlm3 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sQuad1_getPst3sTlm3(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sTlm4RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sQuad1_Pst3sTlm4 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sQuad1_getPst3sTlm4(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sAttitude2RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sQuad1_Pst3sAttitude2 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sQuad1_getPst3sAttitude2(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sAttitude3RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sQuad1_Pst3sAttitude3 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sQuad1_getPst3sAttitude3(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sAttitude4RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sQuad1_Pst3sAttitude4 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sQuad1_getPst3sAttitude4(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sHousekeeping2RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sQuad1_Pst3sHousekeeping2 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sQuad1_getPst3sHousekeeping2(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sHousekeeping3RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sQuad1_Pst3sHousekeeping3 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sQuad1_getPst3sHousekeeping3(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sHousekeeping4RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sQuad1_Pst3sHousekeeping4 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sQuad1_getPst3sHousekeeping4(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sConfig2RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sQuad1_Pst3sConfig2 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sQuad1_getPst3sConfig2(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sConfig3RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sQuad1_Pst3sConfig3 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sQuad1_getPst3sConfig3(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeControlProgramPst3sQuad1_getPst3sConfig4RequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeControlProgramPst3sQuad1_Pst3sConfig4 *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeControlProgramPst3sQuad1_getPst3sConfig4(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeCommon1_setPowerSwitchStateRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeCommon1_PowerSwitchState *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeCommon1_setPowerSwitchState(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeCommon1_getHealthTlmRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeCommon1_HealthTlm *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeCommon1_getHealthTlm(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeCommon1_getPowerSwitchStateRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeCommon1_PowerSwitchState *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeCommon1_getPowerSwitchState(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeNodeCommon1_getNodeModelRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeNodeCommon1_NodeModel *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeNodeCommon1_getNodeModel(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseControlProgram5_setCamLensDistortionRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeSenseControlProgram5_CamLensDistortion *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseControlProgram5_setCamLensDistortion(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseControlProgram5_setCaptureDetectRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseControlProgram5_setCaptureDetect(&endpoint);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseControlProgram5_setDetectRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseControlProgram5_setDetect(&endpoint);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseControlProgram5_setClearOvercurrentFlagsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseControlProgram5_setClearOvercurrentFlags(&endpoint);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseControlProgram5_setImageCaptureRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeSenseControlProgram5_ImageCapture *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseControlProgram5_setImageCapture(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseControlProgram5_setImageTransferSetupRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeSenseControlProgram5_ImageTransferSetup *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseControlProgram5_setImageTransferSetup(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseControlProgram5_setCamBoresightRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeSenseControlProgram5_CamBoresight *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseControlProgram5_setCamBoresight(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseControlProgram5_setCamMaskRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeSenseControlProgram5_CamMask *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseControlProgram5_setCamMask(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseControlProgram5_setCamThresholdRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeSenseControlProgram5_CamThreshold *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseControlProgram5_setCamThreshold(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseControlProgram5_setDetectionAreaRowSelectRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeSenseControlProgram5_DetectionAreaRowSelect *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseControlProgram5_setDetectionAreaRowSelect(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseControlProgram5_getSensorResultsTimestampRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeSenseControlProgram5_SensorResultsTimestamp *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseControlProgram5_getSensorResultsTimestamp(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseControlProgram5_getCamLensDistortionRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeSenseControlProgram5_CamLensDistortion *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseControlProgram5_getCamLensDistortion(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseControlProgram5_getCamMasksRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeSenseControlProgram5_CamMasks *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseControlProgram5_getCamMasks(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseControlProgram5_getSensorResultsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeSenseControlProgram5_SensorResults *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseControlProgram5_getSensorResults(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseControlProgram5_getSensorResultTriggerRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeSenseControlProgram5_SensorResultTrigger *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseControlProgram5_getSensorResultTrigger(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseControlProgram5_getAutoCamSensorRawRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeSenseControlProgram5_AutoCamSensorRaw *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseControlProgram5_getAutoCamSensorRaw(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseControlProgram5_getDetectionAreaRowRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeSenseControlProgram5_DetectionAreaRow *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseControlProgram5_getDetectionAreaRow(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseControlProgram5_getCamBoresightRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeSenseControlProgram5_CamBoresight *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseControlProgram5_getCamBoresight(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseCommon1_setCamAutoAdjustRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeSenseCommon1_CamAutoAdjust *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseCommon1_setCamAutoAdjust(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseCommon1_setCamSettingsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeSenseCommon1_CamSettings *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseCommon1_setCamSettings(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseCommon1_getConfigRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeSenseCommon1_Config *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseCommon1_getConfig(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeSenseCommon1_getHealthTlmRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeSenseCommon1_HealthTlm *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeSenseCommon1_getHealthTlm(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_setCaptureDetectRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeStarControlProgram6_CaptureDetect *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_setCaptureDetect(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_setCaptureOnlyRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_setCaptureOnly(&endpoint);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_setDetectIdOnlyRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_setDetectIdOnly(&endpoint);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_setLensDistortionRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeStarControlProgram6_LensDistortion *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_setLensDistortion(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_setDetectionSettingsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeStarControlProgram6_DetectionSettings *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_setDetectionSettings(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_setSensorSettingsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeStarControlProgram6_SensorSettings *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_setSensorSettings(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_setImageTransferSetupRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeStarControlProgram6_ImageTransferSetup *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_setImageTransferSetup(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_setSensorRegisterReadRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeStarControlProgram6_SensorRegisterRead *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_setSensorRegisterRead(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_setSensorRegisterWriteRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeStarControlProgram6_SensorRegisterWrite *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_setSensorRegisterWrite(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_setSubsystemPowerRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeStarControlProgram6_SubsystemPower *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_setSubsystemPower(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_getLensDistortionRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeStarControlProgram6_LensDistortion *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_getLensDistortion(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_getDetectionSettingsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeStarControlProgram6_DetectionSettings *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_getDetectionSettings(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_getSensorSettingsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeStarControlProgram6_SensorSettings *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_getSensorSettings(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_getStatusRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeStarControlProgram6_Status *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_getStatus(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_getDetectionMetaDataRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeStarControlProgram6_DetectionMetaData *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_getDetectionMetaData(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_getDetectedStarsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeStarControlProgram6_DetectedStars *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_getDetectedStars(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_getHealthTlmRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeStarControlProgram6_HealthTlm *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_getHealthTlm(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_getSensorRegisterValueRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeStarControlProgram6_SensorRegisterValue *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_getSensorRegisterValue(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_getBestStarsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeStarControlProgram6_BestStars *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_getBestStars(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeStarControlProgram6_getAttitudeRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeStarControlProgram6_Attitude *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeStarControlProgram6_getAttitude(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_setWheelSpeedRefRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_WheelSpeedRef *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_setWheelSpeedRef(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_setWheelTorqueRefRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_WheelTorqueRef *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_setWheelTorqueRef(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_setWheelTravelRefRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_WheelTravelRef *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_setWheelTravelRef(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_setWheelRefRampRateLimitRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_WheelRefRampRateLimit *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_setWheelRefRampRateLimit(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_setBackupWheelModeRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_BackupWheelMode *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_setBackupWheelMode(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_setClearErrorsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_setClearErrors(&endpoint);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_setMainGainRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_MainGain *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_setMainGain(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_setBackupGainRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_BackupGain *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_setBackupGain(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_setPWMGainRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_PWMGain *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_setPWMGain(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_setMotorPowerRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_MotorPower *setVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_setMotorPower(&endpoint, setVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_getWheelRefRampRateLimitRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_WheelRefRampRateLimit *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_getWheelRefRampRateLimit(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_getStatorRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_Stator *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_getStator(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_getWheelTorqueRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_WheelTorque *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_getWheelTorque(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_getBackupGainRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_BackupGain *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_getBackupGain(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_getMainGainRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_MainGain *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_getMainGain(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_getPWMGainRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_PWMGain *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_getPWMGain(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_getStatusErrorFlagsRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_StatusErrorFlags *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_getStatusErrorFlags(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_getWheelDataRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_WheelData *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_getWheelData(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_getWheelDutyRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_WheelDuty *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_getWheelDuty(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_getHealthTlmRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_HealthTlm *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_getHealthTlm(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_getWheelSpeedRefRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_WheelSpeedRef *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_getWheelSpeedRef(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_getWheelTorqueRefRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_WheelTorqueRef *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_getWheelTorqueRef(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_getWheelSpeedRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_WheelSpeed *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_getWheelSpeed(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_getMotorPowerRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_MotorPower *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_getMotorPower(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_getControlModeRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_ControlMode *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_getControlMode(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_getBackupWheelModeRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_BackupWheelMode *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_getBackupWheelMode(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_getWheelModelRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_WheelModel *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_getWheelModel(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

ErrorCode CubeADCS_Gen2_CubeWheelControlProgram3_getWheelPosDataRequestGw(const TypesCommonFrameworkTypes1_AbstractNode nodeId, TypesCubeWheelControlProgram3_WheelPosData *returnVal, const U32 timeout)
{
    ErrorCode             err = CUBEADCS_GEN2_CRIT_SECT_ERR;
    TypeDef_TctlmEndpoint endpoint;
    cubeadcs_gen2_setup_endpoint(&endpoint, TYPEDEF__COMMS_ENDPOINT_UART, CUBEADCS_GEN2_DEFAULT_CONN_TIMEOUT);
    if (true == cubeadcs_gen2_crit_section_start(timeout))
    {
        err = cubeadcs_gen2_setup_passthrough(&endpoint, nodeId);
        if (err == CUBEOBC_ERROR_OK)
        {
            err = tctlmCubeWheelControlProgram3_getWheelPosData(&endpoint, returnVal);
        }
        cubeadcs_gen2_crit_section_end();
    }
    return err;
}

// CUBE_ADCS_GEN_SECTION_END

/*
*********************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
*********************************************************************************************
*/

/* ******************************************************************************************* */
