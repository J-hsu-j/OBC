/*!
********************************************************************************************
* @file FP_Helpers.h
* @brief Protocol helpers header
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

#ifndef FP_HELPERS_H
#define FP_HELPERS_H

#include <stdint.h>
#include "FP_common/FP_BaseProtocolTypes.h"

SeqId_t FP_Helpers_GenMsgId(void);
bool    FP_Helpers_HandleDataInternal(ESSA_Stack_DataDispatchInfo_t *fp_DataInfo, const ProtocolFuncArrayEntry_t *const p_func_array, const uint16_t func_array_size);

#endif // #ifndef FP_HELPERS_H
