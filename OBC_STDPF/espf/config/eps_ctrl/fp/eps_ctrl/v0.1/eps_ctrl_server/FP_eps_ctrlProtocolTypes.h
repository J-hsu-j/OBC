/*!
********************************************************************************************
* @file FP_eps_ctrlProtocolTypes.h
* @brief Protocol public type declarations
********************************************************************************************
* @version           interface eps_ctrl v0.1
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

#ifndef FP_EPS_CTRLPROTOCOLTYPES_H
#define FP_EPS_CTRLPROTOCOLTYPES_H

#include <stddef.h>
#include "FP_common/FP_BaseProtocolTypes.h"
#include "FP_common/FP_Helpers.h"

/**********************************************************************
 *
 *  Shared defines
 *
 **********************************************************************/
#define ES_SAT_FUNC_PROTOCOL_ID_EPS_CTRL ((uint16_t) (0x0000001F))

#define EPS_CTRL_GET_CH_OUTPUT_FUNC_ID ((funcIdType_t) 0x00000001)
#define EPS_CTRL_SET_CH_OUTPUT_FUNC_ID ((funcIdType_t) 0x00000002)
#define EPS_CTRL_GET_CH_OUTPUT_FUNCRESP_ID ((funcIdType_t) 0x00000001)
#define EPS_CTRL_SET_CH_OUTPUT_FUNCRESP_ID ((funcIdType_t) 0x00000002)

/**********************************************************************
 *
 *  Type definitions
 *
 **********************************************************************/
/*
    General status type used for SW-related communication and/or settings.
*/
#define EPS_CTRL_STANDARDRESULT_SUCCESS ((uint8_t) 0)
#define EPS_CTRL_STANDARDRESULT_ERROR ((uint8_t) 1)
#define EPS_CTRL_STANDARDRESULT_INVALID_ARGS ((uint8_t) 2)
#define EPS_CTRL_STANDARDRESULT_NOT_SUPPORTED ((uint8_t) 3)
#define EPS_CTRL_STANDARDRESULT_MAX_CNT  ((uint8_t) 4)
typedef uint8_t EPS_CTRL_StandardResult_t;


typedef struct {
    uint8_t u8Ch_id;
} PACKED_STRUCT eps_ctrlget_ch_outputRequestData_t;

typedef struct {
    uint8_t u8Ch_id;
    bool bNew_state;
} PACKED_STRUCT eps_ctrlset_ch_outputRequestData_t;


typedef struct {
    bool bCh_state;
    EPS_CTRL_StandardResult_t eOp_result;
} PACKED_STRUCT eps_ctrlget_ch_outputResponseData_t;

typedef struct {
    EPS_CTRL_StandardResult_t eOp_result;
} PACKED_STRUCT eps_ctrlset_ch_outputResponseData_t;


#endif  // #ifndef FP_EPS_CTRLPROTOCOLTYPES_H

