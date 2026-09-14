/*
 * FP_trace.c
 *
 * This is a temporary trace implementation for use by the FP-generated code until macchiato is updated to use the
 * new libtrace interface.
 *
 */

#include "trace.h"
#include "ESPLATFORM_NETWORK_STACK/ES_SAT_API/include/ESSA_Stack.h"
#include "ES_SAT_MAC_Context.h"

INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

void TRACE_ERROR(const uint16_t protocolId, const funcIdType_t functionId, const ESSATMAC_ErrCodes errorCode)
{
    ES_TRACE_ERROR("FP ERROR: Protocol ID = %lu, Function ID = %lu, Error Code = %lu", (uint32_t)protocolId, (uint32_t)functionId, (uint32_t)errorCode);
}
