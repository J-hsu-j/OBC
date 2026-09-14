/*!
********************************************************************************************
* @file upy_cubeadcs_gen2_cubecomputercommon3.c
* @brief uPy C bindings generator
********************************************************************************************
* @version           interface CubeADCS_Gen2_CubeComputerCommon3 v6.0
*
* @copyright         (C) Copyright EnduroSat
*
*                    Contents and presentations are protected world-wide.
*                    Any kind of using, copying etc. is prohibited without prior permission.
*                    All rights - incl. industrial property rights - are reserved.
*
*-------------------------------------------------------------------------------------------
* GENERATOR: org.endurosat.generators.macchiato.binders.Gen_uPy v0.8
*-------------------------------------------------------------------------------------------
* !!! Please note that this code is fully GENERATED and shall not be manually modified as
* all changes will be overwritten !!!
********************************************************************************************
*/

/**
 * @defgroup CubeADCS_Gen2_CubeComputerCommon3 CubeADCS_Gen2_CubeComputerCommon3
 * @{
 *
 * Interface for Cube ADCS Gen2 - CubeComputerCommon3
 *
 * @file upy_cubeadcs_gen2_cubecomputercommon3.c
 * @brief CubeADCS_Gen2_CubeComputerCommon3 uPython C wrapper module implementation
 *
 * This module is fully generated from a FIDL file and represents a uPython C extension module which
 * registers specific classes related to the communication interfaces of the CubeADCS_Gen2_CubeComputerCommon3 API. Users of
 * this module can import it in a uPython script and serialize/deserialize FP requests and responses
 * via the provided services here.
 *
 * @}
 */         

// Note: The 'const' qualifiers get discarded because all generated uPy types must be placed in FLASH ROM
//       to conserve RAM and the APIs always assume that the data is placed in RAM although these structures
//       are not actually modified by the code 
#pragma GCC diagnostic ignored "-Wdiscarded-qualifiers"

// Note: This warning occurs for variables of type float and double which are defined inside packed structures.
//       Accessing those variables by the FPU may cause an unaligned memory access MCU exception if they are not 
//       aligned to a 4-byte boundary and since we require packed structures as a shortcut for straightforward type 
//       serialization/deserialization, all such accesses are performed by the code generator in a byte-wise manner, 
//       hence the error is actually handled and can be suppressed.
#pragma GCC diagnostic ignored "-Waddress-of-packed-member"

// Note: The current version of the uPy C generator takes the easy path of providing all flavors of copy functions
//       without tracking dependencies and thus the compiler emits an "unused-function" warning when those are not
//       used in any other part of the generated code. Since the overhead of having the functions is not big and the 
//       unused functions are finally removed from the final image by the linker, the warnings are suppressed here.
#pragma GCC diagnostic ignored "-Wunused-function"

#include "upy_cfg.h"
#include "py/runtime.h"
#include "py/obj.h"
#include "upy_sd.h"
#include "FP_CubeADCS_Gen2_CubeComputerCommon3ProtocolTypes.h"

/**********************************************************************
 *
 *  uPy class definitions for struct types
 *
 **********************************************************************/

/**********************************************************************
 *
 *  uPy class definition for struct 'PortDiagnostics'
 *
 **********************************************************************/
    
// class structure for type PortDiagnostics
typedef struct 
{
    mp_obj_base_t base;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PortDiagnostics_t class_data;
} PACKED_STRUCT PortDiagnostics_class_obj_t;

// PortDiagnostics class constructor from field arguments
STATIC mp_obj_t PortDiagnostics_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 103, 103, false);
    
    PortDiagnostics_class_obj_t *p_self = m_new_obj(PortDiagnostics_class_obj_t);
    p_self->base.type = type;
    
    // GlobalErrorCode
    p_self->class_data.u32GlobalErrorCode = (uint32_t) mp_obj_get_int(p_args[0]);
    // NoneExpected
    p_self->class_data.bNoneExpected = (bool) mp_obj_get_int(p_args[1]);
    // NoneDiscoveredError
    p_self->class_data.bNoneDiscoveredError = (bool) mp_obj_get_int(p_args[2]);
    // ExpectedMatchError
    p_self->class_data.bExpectedMatchError = (bool) mp_obj_get_int(p_args[3]);
    // AddrAssignError
    p_self->class_data.bAddrAssignError = (bool) mp_obj_get_int(p_args[4]);
    // AbstractTypeError
    p_self->class_data.bAbstractTypeError = (bool) mp_obj_get_int(p_args[5]);
    // ConfigPersistError
    p_self->class_data.bConfigPersistError = (bool) mp_obj_get_int(p_args[6]);
    // Sensor1ErrorCode
    p_self->class_data.u32Sensor1ErrorCode = (uint32_t) mp_obj_get_int(p_args[7]);
    // Sensor1UnexpectedError
    p_self->class_data.bSensor1UnexpectedError = (bool) mp_obj_get_int(p_args[8]);
    // Sensor1CommsError
    p_self->class_data.bSensor1CommsError = (bool) mp_obj_get_int(p_args[9]);
    // Sensor1NodeTypeMatchError
    p_self->class_data.bSensor1NodeTypeMatchError = (bool) mp_obj_get_int(p_args[10]);
    // Sensor1SerialMatchError
    p_self->class_data.bSensor1SerialMatchError = (bool) mp_obj_get_int(p_args[11]);
    // Sensor1AddrAssignError
    p_self->class_data.bSensor1AddrAssignError = (bool) mp_obj_get_int(p_args[12]);
    // Sensor1AbstractTypeError
    p_self->class_data.bSensor1AbstractTypeError = (bool) mp_obj_get_int(p_args[13]);
    // Sensor1SerialResolveError
    p_self->class_data.bSensor1SerialResolveError = (bool) mp_obj_get_int(p_args[14]);
    // Sensor2ErrorCode
    p_self->class_data.u32Sensor2ErrorCode = (uint32_t) mp_obj_get_int(p_args[15]);
    // Sensor2UnexpectedError
    p_self->class_data.bSensor2UnexpectedError = (bool) mp_obj_get_int(p_args[16]);
    // Sensor2CommsError
    p_self->class_data.bSensor2CommsError = (bool) mp_obj_get_int(p_args[17]);
    // Sensor2NodeTypeMatchError
    p_self->class_data.bSensor2NodeTypeMatchError = (bool) mp_obj_get_int(p_args[18]);
    // Sensor2SerialMatchError
    p_self->class_data.bSensor2SerialMatchError = (bool) mp_obj_get_int(p_args[19]);
    // Sensor2AddrAssignError
    p_self->class_data.bSensor2AddrAssignError = (bool) mp_obj_get_int(p_args[20]);
    // Sensor2AbstractTypeError
    p_self->class_data.bSensor2AbstractTypeError = (bool) mp_obj_get_int(p_args[21]);
    // Sensor2SerialResolveError
    p_self->class_data.bSensor2SerialResolveError = (bool) mp_obj_get_int(p_args[22]);
    // Sensor3ErrorCode
    p_self->class_data.u32Sensor3ErrorCode = (uint32_t) mp_obj_get_int(p_args[23]);
    // Sensor3UnexpectedError
    p_self->class_data.bSensor3UnexpectedError = (bool) mp_obj_get_int(p_args[24]);
    // Sensor3CommsError
    p_self->class_data.bSensor3CommsError = (bool) mp_obj_get_int(p_args[25]);
    // Sensor3NodeTypeMatchError
    p_self->class_data.bSensor3NodeTypeMatchError = (bool) mp_obj_get_int(p_args[26]);
    // Sensor3SerialMatchError
    p_self->class_data.bSensor3SerialMatchError = (bool) mp_obj_get_int(p_args[27]);
    // Sensor3AddrAssignError
    p_self->class_data.bSensor3AddrAssignError = (bool) mp_obj_get_int(p_args[28]);
    // Sensor3AbstractTypeError
    p_self->class_data.bSensor3AbstractTypeError = (bool) mp_obj_get_int(p_args[29]);
    // Sensor3SerialResolveError
    p_self->class_data.bSensor3SerialResolveError = (bool) mp_obj_get_int(p_args[30]);
    // Sensor4ErrorCode
    p_self->class_data.u32Sensor4ErrorCode = (uint32_t) mp_obj_get_int(p_args[31]);
    // Sensor4UnexpectedError
    p_self->class_data.bSensor4UnexpectedError = (bool) mp_obj_get_int(p_args[32]);
    // Sensor4CommsError
    p_self->class_data.bSensor4CommsError = (bool) mp_obj_get_int(p_args[33]);
    // Sensor4NodeTypeMatchError
    p_self->class_data.bSensor4NodeTypeMatchError = (bool) mp_obj_get_int(p_args[34]);
    // Sensor4SerialMatchError
    p_self->class_data.bSensor4SerialMatchError = (bool) mp_obj_get_int(p_args[35]);
    // Sensor4AddrAssignError
    p_self->class_data.bSensor4AddrAssignError = (bool) mp_obj_get_int(p_args[36]);
    // Sensor4AbstractTypeError
    p_self->class_data.bSensor4AbstractTypeError = (bool) mp_obj_get_int(p_args[37]);
    // Sensor4SerialResolveError
    p_self->class_data.bSensor4SerialResolveError = (bool) mp_obj_get_int(p_args[38]);
    // Sensor5ErrorCode
    p_self->class_data.u32Sensor5ErrorCode = (uint32_t) mp_obj_get_int(p_args[39]);
    // Sensor5UnexpectedError
    p_self->class_data.bSensor5UnexpectedError = (bool) mp_obj_get_int(p_args[40]);
    // Sensor5CommsError
    p_self->class_data.bSensor5CommsError = (bool) mp_obj_get_int(p_args[41]);
    // Sensor5NodeTypeMatchError
    p_self->class_data.bSensor5NodeTypeMatchError = (bool) mp_obj_get_int(p_args[42]);
    // Sensor5SerialMatchError
    p_self->class_data.bSensor5SerialMatchError = (bool) mp_obj_get_int(p_args[43]);
    // Sensor5AddrAssignError
    p_self->class_data.bSensor5AddrAssignError = (bool) mp_obj_get_int(p_args[44]);
    // Sensor5AbstractTypeError
    p_self->class_data.bSensor5AbstractTypeError = (bool) mp_obj_get_int(p_args[45]);
    // Sensor5SerialResolveError
    p_self->class_data.bSensor5SerialResolveError = (bool) mp_obj_get_int(p_args[46]);
    // Sensor6ErrorCode
    p_self->class_data.u32Sensor6ErrorCode = (uint32_t) mp_obj_get_int(p_args[47]);
    // Sensor6UnexpectedError
    p_self->class_data.bSensor6UnexpectedError = (bool) mp_obj_get_int(p_args[48]);
    // Sensor6CommsError
    p_self->class_data.bSensor6CommsError = (bool) mp_obj_get_int(p_args[49]);
    // Sensor6NodeTypeMatchError
    p_self->class_data.bSensor6NodeTypeMatchError = (bool) mp_obj_get_int(p_args[50]);
    // Sensor6SerialMatchError
    p_self->class_data.bSensor6SerialMatchError = (bool) mp_obj_get_int(p_args[51]);
    // Sensor6AddrAssignError
    p_self->class_data.bSensor6AddrAssignError = (bool) mp_obj_get_int(p_args[52]);
    // Sensor6AbstractTypeError
    p_self->class_data.bSensor6AbstractTypeError = (bool) mp_obj_get_int(p_args[53]);
    // Sensor6SerialResolveError
    p_self->class_data.bSensor6SerialResolveError = (bool) mp_obj_get_int(p_args[54]);
    // Sensor7ErrorCode
    p_self->class_data.u32Sensor7ErrorCode = (uint32_t) mp_obj_get_int(p_args[55]);
    // Sensor7UnexpectedError
    p_self->class_data.bSensor7UnexpectedError = (bool) mp_obj_get_int(p_args[56]);
    // Sensor7CommsError
    p_self->class_data.bSensor7CommsError = (bool) mp_obj_get_int(p_args[57]);
    // Sensor7NodeTypeMatchError
    p_self->class_data.bSensor7NodeTypeMatchError = (bool) mp_obj_get_int(p_args[58]);
    // Sensor7SerialMatchError
    p_self->class_data.bSensor7SerialMatchError = (bool) mp_obj_get_int(p_args[59]);
    // Sensor7AddrAssignError
    p_self->class_data.bSensor7AddrAssignError = (bool) mp_obj_get_int(p_args[60]);
    // Sensor7AbstractTypeError
    p_self->class_data.bSensor7AbstractTypeError = (bool) mp_obj_get_int(p_args[61]);
    // Sensor7SerialResolveError
    p_self->class_data.bSensor7SerialResolveError = (bool) mp_obj_get_int(p_args[62]);
    // Sensor8ErrorCode
    p_self->class_data.u32Sensor8ErrorCode = (uint32_t) mp_obj_get_int(p_args[63]);
    // Sensor8UnexpectedError
    p_self->class_data.bSensor8UnexpectedError = (bool) mp_obj_get_int(p_args[64]);
    // Sensor8CommsError
    p_self->class_data.bSensor8CommsError = (bool) mp_obj_get_int(p_args[65]);
    // Sensor8NodeTypeMatchError
    p_self->class_data.bSensor8NodeTypeMatchError = (bool) mp_obj_get_int(p_args[66]);
    // Sensor8SerialMatchError
    p_self->class_data.bSensor8SerialMatchError = (bool) mp_obj_get_int(p_args[67]);
    // Sensor8AddrAssignError
    p_self->class_data.bSensor8AddrAssignError = (bool) mp_obj_get_int(p_args[68]);
    // Sensor8AbstractTypeError
    p_self->class_data.bSensor8AbstractTypeError = (bool) mp_obj_get_int(p_args[69]);
    // Sensor8SerialResolveError
    p_self->class_data.bSensor8SerialResolveError = (bool) mp_obj_get_int(p_args[70]);
    // Wheel1ErrorCode
    p_self->class_data.u32Wheel1ErrorCode = (uint32_t) mp_obj_get_int(p_args[71]);
    // Wheel1UnexpectedError
    p_self->class_data.bWheel1UnexpectedError = (bool) mp_obj_get_int(p_args[72]);
    // Wheel1CommsError
    p_self->class_data.bWheel1CommsError = (bool) mp_obj_get_int(p_args[73]);
    // Wheel1NodeTypeMatchError
    p_self->class_data.bWheel1NodeTypeMatchError = (bool) mp_obj_get_int(p_args[74]);
    // Wheel1SerialMatchError
    p_self->class_data.bWheel1SerialMatchError = (bool) mp_obj_get_int(p_args[75]);
    // Wheel1AddrAssignError
    p_self->class_data.bWheel1AddrAssignError = (bool) mp_obj_get_int(p_args[76]);
    // Wheel1AbstractTypeError
    p_self->class_data.bWheel1AbstractTypeError = (bool) mp_obj_get_int(p_args[77]);
    // Wheel1SerialResolveError
    p_self->class_data.bWheel1SerialResolveError = (bool) mp_obj_get_int(p_args[78]);
    // Wheel2ErrorCode
    p_self->class_data.u32Wheel2ErrorCode = (uint32_t) mp_obj_get_int(p_args[79]);
    // Wheel2UnexpectedError
    p_self->class_data.bWheel2UnexpectedError = (bool) mp_obj_get_int(p_args[80]);
    // Wheel2CommsError
    p_self->class_data.bWheel2CommsError = (bool) mp_obj_get_int(p_args[81]);
    // Wheel2NodeTypeMatchError
    p_self->class_data.bWheel2NodeTypeMatchError = (bool) mp_obj_get_int(p_args[82]);
    // Wheel2SerialMatchError
    p_self->class_data.bWheel2SerialMatchError = (bool) mp_obj_get_int(p_args[83]);
    // Wheel2AddrAssignError
    p_self->class_data.bWheel2AddrAssignError = (bool) mp_obj_get_int(p_args[84]);
    // Wheel2AbstractTypeError
    p_self->class_data.bWheel2AbstractTypeError = (bool) mp_obj_get_int(p_args[85]);
    // Wheel2SerialResolveError
    p_self->class_data.bWheel2SerialResolveError = (bool) mp_obj_get_int(p_args[86]);
    // Wheel3ErrorCode
    p_self->class_data.u32Wheel3ErrorCode = (uint32_t) mp_obj_get_int(p_args[87]);
    // Wheel3UnexpectedError
    p_self->class_data.bWheel3UnexpectedError = (bool) mp_obj_get_int(p_args[88]);
    // Wheel3CommsError
    p_self->class_data.bWheel3CommsError = (bool) mp_obj_get_int(p_args[89]);
    // Wheel3NodeTypeMatchError
    p_self->class_data.bWheel3NodeTypeMatchError = (bool) mp_obj_get_int(p_args[90]);
    // Wheel3SerialMatchError
    p_self->class_data.bWheel3SerialMatchError = (bool) mp_obj_get_int(p_args[91]);
    // Wheel3AddrAssignError
    p_self->class_data.bWheel3AddrAssignError = (bool) mp_obj_get_int(p_args[92]);
    // Wheel3AbstractTypeError
    p_self->class_data.bWheel3AbstractTypeError = (bool) mp_obj_get_int(p_args[93]);
    // Wheel3SerialResolveError
    p_self->class_data.bWheel3SerialResolveError = (bool) mp_obj_get_int(p_args[94]);
    // Wheel4ErrorCode
    p_self->class_data.u32Wheel4ErrorCode = (uint32_t) mp_obj_get_int(p_args[95]);
    // Wheel4UnexpectedError
    p_self->class_data.bWheel4UnexpectedError = (bool) mp_obj_get_int(p_args[96]);
    // Wheel4CommsError
    p_self->class_data.bWheel4CommsError = (bool) mp_obj_get_int(p_args[97]);
    // Wheel4NodeTypeMatchError
    p_self->class_data.bWheel4NodeTypeMatchError = (bool) mp_obj_get_int(p_args[98]);
    // Wheel4SerialMatchError
    p_self->class_data.bWheel4SerialMatchError = (bool) mp_obj_get_int(p_args[99]);
    // Wheel4AddrAssignError
    p_self->class_data.bWheel4AddrAssignError = (bool) mp_obj_get_int(p_args[100]);
    // Wheel4AbstractTypeError
    p_self->class_data.bWheel4AbstractTypeError = (bool) mp_obj_get_int(p_args[101]);
    // Wheel4SerialResolveError
    p_self->class_data.bWheel4SerialResolveError = (bool) mp_obj_get_int(p_args[102]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'PortDiagnostics' getters
//

STATIC mp_obj_t PortDiagnostics_get_GlobalErrorCode(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32GlobalErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_GlobalErrorCode_obj, PortDiagnostics_get_GlobalErrorCode);

STATIC mp_obj_t PortDiagnostics_get_NoneExpected(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bNoneExpected);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_NoneExpected_obj, PortDiagnostics_get_NoneExpected);

STATIC mp_obj_t PortDiagnostics_get_NoneDiscoveredError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bNoneDiscoveredError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_NoneDiscoveredError_obj, PortDiagnostics_get_NoneDiscoveredError);

STATIC mp_obj_t PortDiagnostics_get_ExpectedMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bExpectedMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_ExpectedMatchError_obj, PortDiagnostics_get_ExpectedMatchError);

STATIC mp_obj_t PortDiagnostics_get_AddrAssignError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bAddrAssignError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_AddrAssignError_obj, PortDiagnostics_get_AddrAssignError);

STATIC mp_obj_t PortDiagnostics_get_AbstractTypeError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bAbstractTypeError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_AbstractTypeError_obj, PortDiagnostics_get_AbstractTypeError);

STATIC mp_obj_t PortDiagnostics_get_ConfigPersistError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bConfigPersistError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_ConfigPersistError_obj, PortDiagnostics_get_ConfigPersistError);

STATIC mp_obj_t PortDiagnostics_get_Sensor1ErrorCode(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor1ErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor1ErrorCode_obj, PortDiagnostics_get_Sensor1ErrorCode);

STATIC mp_obj_t PortDiagnostics_get_Sensor1UnexpectedError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor1UnexpectedError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor1UnexpectedError_obj, PortDiagnostics_get_Sensor1UnexpectedError);

STATIC mp_obj_t PortDiagnostics_get_Sensor1CommsError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor1CommsError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor1CommsError_obj, PortDiagnostics_get_Sensor1CommsError);

STATIC mp_obj_t PortDiagnostics_get_Sensor1NodeTypeMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor1NodeTypeMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor1NodeTypeMatchError_obj, PortDiagnostics_get_Sensor1NodeTypeMatchError);

STATIC mp_obj_t PortDiagnostics_get_Sensor1SerialMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor1SerialMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor1SerialMatchError_obj, PortDiagnostics_get_Sensor1SerialMatchError);

STATIC mp_obj_t PortDiagnostics_get_Sensor1AddrAssignError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor1AddrAssignError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor1AddrAssignError_obj, PortDiagnostics_get_Sensor1AddrAssignError);

STATIC mp_obj_t PortDiagnostics_get_Sensor1AbstractTypeError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor1AbstractTypeError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor1AbstractTypeError_obj, PortDiagnostics_get_Sensor1AbstractTypeError);

STATIC mp_obj_t PortDiagnostics_get_Sensor1SerialResolveError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor1SerialResolveError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor1SerialResolveError_obj, PortDiagnostics_get_Sensor1SerialResolveError);

STATIC mp_obj_t PortDiagnostics_get_Sensor2ErrorCode(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor2ErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor2ErrorCode_obj, PortDiagnostics_get_Sensor2ErrorCode);

STATIC mp_obj_t PortDiagnostics_get_Sensor2UnexpectedError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor2UnexpectedError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor2UnexpectedError_obj, PortDiagnostics_get_Sensor2UnexpectedError);

STATIC mp_obj_t PortDiagnostics_get_Sensor2CommsError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor2CommsError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor2CommsError_obj, PortDiagnostics_get_Sensor2CommsError);

STATIC mp_obj_t PortDiagnostics_get_Sensor2NodeTypeMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor2NodeTypeMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor2NodeTypeMatchError_obj, PortDiagnostics_get_Sensor2NodeTypeMatchError);

STATIC mp_obj_t PortDiagnostics_get_Sensor2SerialMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor2SerialMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor2SerialMatchError_obj, PortDiagnostics_get_Sensor2SerialMatchError);

STATIC mp_obj_t PortDiagnostics_get_Sensor2AddrAssignError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor2AddrAssignError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor2AddrAssignError_obj, PortDiagnostics_get_Sensor2AddrAssignError);

STATIC mp_obj_t PortDiagnostics_get_Sensor2AbstractTypeError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor2AbstractTypeError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor2AbstractTypeError_obj, PortDiagnostics_get_Sensor2AbstractTypeError);

STATIC mp_obj_t PortDiagnostics_get_Sensor2SerialResolveError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor2SerialResolveError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor2SerialResolveError_obj, PortDiagnostics_get_Sensor2SerialResolveError);

STATIC mp_obj_t PortDiagnostics_get_Sensor3ErrorCode(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor3ErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor3ErrorCode_obj, PortDiagnostics_get_Sensor3ErrorCode);

STATIC mp_obj_t PortDiagnostics_get_Sensor3UnexpectedError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor3UnexpectedError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor3UnexpectedError_obj, PortDiagnostics_get_Sensor3UnexpectedError);

STATIC mp_obj_t PortDiagnostics_get_Sensor3CommsError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor3CommsError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor3CommsError_obj, PortDiagnostics_get_Sensor3CommsError);

STATIC mp_obj_t PortDiagnostics_get_Sensor3NodeTypeMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor3NodeTypeMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor3NodeTypeMatchError_obj, PortDiagnostics_get_Sensor3NodeTypeMatchError);

STATIC mp_obj_t PortDiagnostics_get_Sensor3SerialMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor3SerialMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor3SerialMatchError_obj, PortDiagnostics_get_Sensor3SerialMatchError);

STATIC mp_obj_t PortDiagnostics_get_Sensor3AddrAssignError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor3AddrAssignError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor3AddrAssignError_obj, PortDiagnostics_get_Sensor3AddrAssignError);

STATIC mp_obj_t PortDiagnostics_get_Sensor3AbstractTypeError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor3AbstractTypeError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor3AbstractTypeError_obj, PortDiagnostics_get_Sensor3AbstractTypeError);

STATIC mp_obj_t PortDiagnostics_get_Sensor3SerialResolveError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor3SerialResolveError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor3SerialResolveError_obj, PortDiagnostics_get_Sensor3SerialResolveError);

STATIC mp_obj_t PortDiagnostics_get_Sensor4ErrorCode(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor4ErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor4ErrorCode_obj, PortDiagnostics_get_Sensor4ErrorCode);

STATIC mp_obj_t PortDiagnostics_get_Sensor4UnexpectedError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor4UnexpectedError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor4UnexpectedError_obj, PortDiagnostics_get_Sensor4UnexpectedError);

STATIC mp_obj_t PortDiagnostics_get_Sensor4CommsError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor4CommsError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor4CommsError_obj, PortDiagnostics_get_Sensor4CommsError);

STATIC mp_obj_t PortDiagnostics_get_Sensor4NodeTypeMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor4NodeTypeMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor4NodeTypeMatchError_obj, PortDiagnostics_get_Sensor4NodeTypeMatchError);

STATIC mp_obj_t PortDiagnostics_get_Sensor4SerialMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor4SerialMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor4SerialMatchError_obj, PortDiagnostics_get_Sensor4SerialMatchError);

STATIC mp_obj_t PortDiagnostics_get_Sensor4AddrAssignError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor4AddrAssignError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor4AddrAssignError_obj, PortDiagnostics_get_Sensor4AddrAssignError);

STATIC mp_obj_t PortDiagnostics_get_Sensor4AbstractTypeError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor4AbstractTypeError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor4AbstractTypeError_obj, PortDiagnostics_get_Sensor4AbstractTypeError);

STATIC mp_obj_t PortDiagnostics_get_Sensor4SerialResolveError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor4SerialResolveError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor4SerialResolveError_obj, PortDiagnostics_get_Sensor4SerialResolveError);

STATIC mp_obj_t PortDiagnostics_get_Sensor5ErrorCode(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor5ErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor5ErrorCode_obj, PortDiagnostics_get_Sensor5ErrorCode);

STATIC mp_obj_t PortDiagnostics_get_Sensor5UnexpectedError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor5UnexpectedError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor5UnexpectedError_obj, PortDiagnostics_get_Sensor5UnexpectedError);

STATIC mp_obj_t PortDiagnostics_get_Sensor5CommsError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor5CommsError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor5CommsError_obj, PortDiagnostics_get_Sensor5CommsError);

STATIC mp_obj_t PortDiagnostics_get_Sensor5NodeTypeMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor5NodeTypeMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor5NodeTypeMatchError_obj, PortDiagnostics_get_Sensor5NodeTypeMatchError);

STATIC mp_obj_t PortDiagnostics_get_Sensor5SerialMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor5SerialMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor5SerialMatchError_obj, PortDiagnostics_get_Sensor5SerialMatchError);

STATIC mp_obj_t PortDiagnostics_get_Sensor5AddrAssignError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor5AddrAssignError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor5AddrAssignError_obj, PortDiagnostics_get_Sensor5AddrAssignError);

STATIC mp_obj_t PortDiagnostics_get_Sensor5AbstractTypeError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor5AbstractTypeError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor5AbstractTypeError_obj, PortDiagnostics_get_Sensor5AbstractTypeError);

STATIC mp_obj_t PortDiagnostics_get_Sensor5SerialResolveError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor5SerialResolveError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor5SerialResolveError_obj, PortDiagnostics_get_Sensor5SerialResolveError);

STATIC mp_obj_t PortDiagnostics_get_Sensor6ErrorCode(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor6ErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor6ErrorCode_obj, PortDiagnostics_get_Sensor6ErrorCode);

STATIC mp_obj_t PortDiagnostics_get_Sensor6UnexpectedError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor6UnexpectedError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor6UnexpectedError_obj, PortDiagnostics_get_Sensor6UnexpectedError);

STATIC mp_obj_t PortDiagnostics_get_Sensor6CommsError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor6CommsError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor6CommsError_obj, PortDiagnostics_get_Sensor6CommsError);

STATIC mp_obj_t PortDiagnostics_get_Sensor6NodeTypeMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor6NodeTypeMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor6NodeTypeMatchError_obj, PortDiagnostics_get_Sensor6NodeTypeMatchError);

STATIC mp_obj_t PortDiagnostics_get_Sensor6SerialMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor6SerialMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor6SerialMatchError_obj, PortDiagnostics_get_Sensor6SerialMatchError);

STATIC mp_obj_t PortDiagnostics_get_Sensor6AddrAssignError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor6AddrAssignError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor6AddrAssignError_obj, PortDiagnostics_get_Sensor6AddrAssignError);

STATIC mp_obj_t PortDiagnostics_get_Sensor6AbstractTypeError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor6AbstractTypeError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor6AbstractTypeError_obj, PortDiagnostics_get_Sensor6AbstractTypeError);

STATIC mp_obj_t PortDiagnostics_get_Sensor6SerialResolveError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor6SerialResolveError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor6SerialResolveError_obj, PortDiagnostics_get_Sensor6SerialResolveError);

STATIC mp_obj_t PortDiagnostics_get_Sensor7ErrorCode(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor7ErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor7ErrorCode_obj, PortDiagnostics_get_Sensor7ErrorCode);

STATIC mp_obj_t PortDiagnostics_get_Sensor7UnexpectedError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor7UnexpectedError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor7UnexpectedError_obj, PortDiagnostics_get_Sensor7UnexpectedError);

STATIC mp_obj_t PortDiagnostics_get_Sensor7CommsError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor7CommsError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor7CommsError_obj, PortDiagnostics_get_Sensor7CommsError);

STATIC mp_obj_t PortDiagnostics_get_Sensor7NodeTypeMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor7NodeTypeMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor7NodeTypeMatchError_obj, PortDiagnostics_get_Sensor7NodeTypeMatchError);

STATIC mp_obj_t PortDiagnostics_get_Sensor7SerialMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor7SerialMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor7SerialMatchError_obj, PortDiagnostics_get_Sensor7SerialMatchError);

STATIC mp_obj_t PortDiagnostics_get_Sensor7AddrAssignError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor7AddrAssignError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor7AddrAssignError_obj, PortDiagnostics_get_Sensor7AddrAssignError);

STATIC mp_obj_t PortDiagnostics_get_Sensor7AbstractTypeError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor7AbstractTypeError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor7AbstractTypeError_obj, PortDiagnostics_get_Sensor7AbstractTypeError);

STATIC mp_obj_t PortDiagnostics_get_Sensor7SerialResolveError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor7SerialResolveError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor7SerialResolveError_obj, PortDiagnostics_get_Sensor7SerialResolveError);

STATIC mp_obj_t PortDiagnostics_get_Sensor8ErrorCode(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor8ErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor8ErrorCode_obj, PortDiagnostics_get_Sensor8ErrorCode);

STATIC mp_obj_t PortDiagnostics_get_Sensor8UnexpectedError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor8UnexpectedError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor8UnexpectedError_obj, PortDiagnostics_get_Sensor8UnexpectedError);

STATIC mp_obj_t PortDiagnostics_get_Sensor8CommsError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor8CommsError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor8CommsError_obj, PortDiagnostics_get_Sensor8CommsError);

STATIC mp_obj_t PortDiagnostics_get_Sensor8NodeTypeMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor8NodeTypeMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor8NodeTypeMatchError_obj, PortDiagnostics_get_Sensor8NodeTypeMatchError);

STATIC mp_obj_t PortDiagnostics_get_Sensor8SerialMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor8SerialMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor8SerialMatchError_obj, PortDiagnostics_get_Sensor8SerialMatchError);

STATIC mp_obj_t PortDiagnostics_get_Sensor8AddrAssignError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor8AddrAssignError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor8AddrAssignError_obj, PortDiagnostics_get_Sensor8AddrAssignError);

STATIC mp_obj_t PortDiagnostics_get_Sensor8AbstractTypeError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor8AbstractTypeError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor8AbstractTypeError_obj, PortDiagnostics_get_Sensor8AbstractTypeError);

STATIC mp_obj_t PortDiagnostics_get_Sensor8SerialResolveError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSensor8SerialResolveError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Sensor8SerialResolveError_obj, PortDiagnostics_get_Sensor8SerialResolveError);

STATIC mp_obj_t PortDiagnostics_get_Wheel1ErrorCode(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Wheel1ErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel1ErrorCode_obj, PortDiagnostics_get_Wheel1ErrorCode);

STATIC mp_obj_t PortDiagnostics_get_Wheel1UnexpectedError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel1UnexpectedError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel1UnexpectedError_obj, PortDiagnostics_get_Wheel1UnexpectedError);

STATIC mp_obj_t PortDiagnostics_get_Wheel1CommsError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel1CommsError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel1CommsError_obj, PortDiagnostics_get_Wheel1CommsError);

STATIC mp_obj_t PortDiagnostics_get_Wheel1NodeTypeMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel1NodeTypeMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel1NodeTypeMatchError_obj, PortDiagnostics_get_Wheel1NodeTypeMatchError);

STATIC mp_obj_t PortDiagnostics_get_Wheel1SerialMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel1SerialMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel1SerialMatchError_obj, PortDiagnostics_get_Wheel1SerialMatchError);

STATIC mp_obj_t PortDiagnostics_get_Wheel1AddrAssignError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel1AddrAssignError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel1AddrAssignError_obj, PortDiagnostics_get_Wheel1AddrAssignError);

STATIC mp_obj_t PortDiagnostics_get_Wheel1AbstractTypeError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel1AbstractTypeError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel1AbstractTypeError_obj, PortDiagnostics_get_Wheel1AbstractTypeError);

STATIC mp_obj_t PortDiagnostics_get_Wheel1SerialResolveError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel1SerialResolveError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel1SerialResolveError_obj, PortDiagnostics_get_Wheel1SerialResolveError);

STATIC mp_obj_t PortDiagnostics_get_Wheel2ErrorCode(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Wheel2ErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel2ErrorCode_obj, PortDiagnostics_get_Wheel2ErrorCode);

STATIC mp_obj_t PortDiagnostics_get_Wheel2UnexpectedError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel2UnexpectedError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel2UnexpectedError_obj, PortDiagnostics_get_Wheel2UnexpectedError);

STATIC mp_obj_t PortDiagnostics_get_Wheel2CommsError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel2CommsError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel2CommsError_obj, PortDiagnostics_get_Wheel2CommsError);

STATIC mp_obj_t PortDiagnostics_get_Wheel2NodeTypeMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel2NodeTypeMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel2NodeTypeMatchError_obj, PortDiagnostics_get_Wheel2NodeTypeMatchError);

STATIC mp_obj_t PortDiagnostics_get_Wheel2SerialMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel2SerialMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel2SerialMatchError_obj, PortDiagnostics_get_Wheel2SerialMatchError);

STATIC mp_obj_t PortDiagnostics_get_Wheel2AddrAssignError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel2AddrAssignError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel2AddrAssignError_obj, PortDiagnostics_get_Wheel2AddrAssignError);

STATIC mp_obj_t PortDiagnostics_get_Wheel2AbstractTypeError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel2AbstractTypeError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel2AbstractTypeError_obj, PortDiagnostics_get_Wheel2AbstractTypeError);

STATIC mp_obj_t PortDiagnostics_get_Wheel2SerialResolveError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel2SerialResolveError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel2SerialResolveError_obj, PortDiagnostics_get_Wheel2SerialResolveError);

STATIC mp_obj_t PortDiagnostics_get_Wheel3ErrorCode(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Wheel3ErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel3ErrorCode_obj, PortDiagnostics_get_Wheel3ErrorCode);

STATIC mp_obj_t PortDiagnostics_get_Wheel3UnexpectedError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel3UnexpectedError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel3UnexpectedError_obj, PortDiagnostics_get_Wheel3UnexpectedError);

STATIC mp_obj_t PortDiagnostics_get_Wheel3CommsError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel3CommsError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel3CommsError_obj, PortDiagnostics_get_Wheel3CommsError);

STATIC mp_obj_t PortDiagnostics_get_Wheel3NodeTypeMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel3NodeTypeMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel3NodeTypeMatchError_obj, PortDiagnostics_get_Wheel3NodeTypeMatchError);

STATIC mp_obj_t PortDiagnostics_get_Wheel3SerialMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel3SerialMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel3SerialMatchError_obj, PortDiagnostics_get_Wheel3SerialMatchError);

STATIC mp_obj_t PortDiagnostics_get_Wheel3AddrAssignError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel3AddrAssignError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel3AddrAssignError_obj, PortDiagnostics_get_Wheel3AddrAssignError);

STATIC mp_obj_t PortDiagnostics_get_Wheel3AbstractTypeError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel3AbstractTypeError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel3AbstractTypeError_obj, PortDiagnostics_get_Wheel3AbstractTypeError);

STATIC mp_obj_t PortDiagnostics_get_Wheel3SerialResolveError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel3SerialResolveError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel3SerialResolveError_obj, PortDiagnostics_get_Wheel3SerialResolveError);

STATIC mp_obj_t PortDiagnostics_get_Wheel4ErrorCode(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Wheel4ErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel4ErrorCode_obj, PortDiagnostics_get_Wheel4ErrorCode);

STATIC mp_obj_t PortDiagnostics_get_Wheel4UnexpectedError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel4UnexpectedError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel4UnexpectedError_obj, PortDiagnostics_get_Wheel4UnexpectedError);

STATIC mp_obj_t PortDiagnostics_get_Wheel4CommsError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel4CommsError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel4CommsError_obj, PortDiagnostics_get_Wheel4CommsError);

STATIC mp_obj_t PortDiagnostics_get_Wheel4NodeTypeMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel4NodeTypeMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel4NodeTypeMatchError_obj, PortDiagnostics_get_Wheel4NodeTypeMatchError);

STATIC mp_obj_t PortDiagnostics_get_Wheel4SerialMatchError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel4SerialMatchError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel4SerialMatchError_obj, PortDiagnostics_get_Wheel4SerialMatchError);

STATIC mp_obj_t PortDiagnostics_get_Wheel4AddrAssignError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel4AddrAssignError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel4AddrAssignError_obj, PortDiagnostics_get_Wheel4AddrAssignError);

STATIC mp_obj_t PortDiagnostics_get_Wheel4AbstractTypeError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel4AbstractTypeError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel4AbstractTypeError_obj, PortDiagnostics_get_Wheel4AbstractTypeError);

STATIC mp_obj_t PortDiagnostics_get_Wheel4SerialResolveError(mp_obj_t self_in) 
{
    const PortDiagnostics_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bWheel4SerialResolveError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_get_Wheel4SerialResolveError_obj, PortDiagnostics_get_Wheel4SerialResolveError);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t PortDiagnostics_locals_dict_table[103] = {
    { MP_ROM_QSTR(MP_QSTR_get_GlobalErrorCode), MP_ROM_PTR(&PortDiagnostics_get_GlobalErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_NoneExpected), MP_ROM_PTR(&PortDiagnostics_get_NoneExpected_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_NoneDiscoveredError), MP_ROM_PTR(&PortDiagnostics_get_NoneDiscoveredError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ExpectedMatchError), MP_ROM_PTR(&PortDiagnostics_get_ExpectedMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_AddrAssignError), MP_ROM_PTR(&PortDiagnostics_get_AddrAssignError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_AbstractTypeError), MP_ROM_PTR(&PortDiagnostics_get_AbstractTypeError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ConfigPersistError), MP_ROM_PTR(&PortDiagnostics_get_ConfigPersistError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor1ErrorCode), MP_ROM_PTR(&PortDiagnostics_get_Sensor1ErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor1UnexpectedError), MP_ROM_PTR(&PortDiagnostics_get_Sensor1UnexpectedError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor1CommsError), MP_ROM_PTR(&PortDiagnostics_get_Sensor1CommsError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor1NodeTypeMatchError), MP_ROM_PTR(&PortDiagnostics_get_Sensor1NodeTypeMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor1SerialMatchError), MP_ROM_PTR(&PortDiagnostics_get_Sensor1SerialMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor1AddrAssignError), MP_ROM_PTR(&PortDiagnostics_get_Sensor1AddrAssignError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor1AbstractTypeError), MP_ROM_PTR(&PortDiagnostics_get_Sensor1AbstractTypeError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor1SerialResolveError), MP_ROM_PTR(&PortDiagnostics_get_Sensor1SerialResolveError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor2ErrorCode), MP_ROM_PTR(&PortDiagnostics_get_Sensor2ErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor2UnexpectedError), MP_ROM_PTR(&PortDiagnostics_get_Sensor2UnexpectedError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor2CommsError), MP_ROM_PTR(&PortDiagnostics_get_Sensor2CommsError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor2NodeTypeMatchError), MP_ROM_PTR(&PortDiagnostics_get_Sensor2NodeTypeMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor2SerialMatchError), MP_ROM_PTR(&PortDiagnostics_get_Sensor2SerialMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor2AddrAssignError), MP_ROM_PTR(&PortDiagnostics_get_Sensor2AddrAssignError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor2AbstractTypeError), MP_ROM_PTR(&PortDiagnostics_get_Sensor2AbstractTypeError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor2SerialResolveError), MP_ROM_PTR(&PortDiagnostics_get_Sensor2SerialResolveError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor3ErrorCode), MP_ROM_PTR(&PortDiagnostics_get_Sensor3ErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor3UnexpectedError), MP_ROM_PTR(&PortDiagnostics_get_Sensor3UnexpectedError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor3CommsError), MP_ROM_PTR(&PortDiagnostics_get_Sensor3CommsError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor3NodeTypeMatchError), MP_ROM_PTR(&PortDiagnostics_get_Sensor3NodeTypeMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor3SerialMatchError), MP_ROM_PTR(&PortDiagnostics_get_Sensor3SerialMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor3AddrAssignError), MP_ROM_PTR(&PortDiagnostics_get_Sensor3AddrAssignError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor3AbstractTypeError), MP_ROM_PTR(&PortDiagnostics_get_Sensor3AbstractTypeError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor3SerialResolveError), MP_ROM_PTR(&PortDiagnostics_get_Sensor3SerialResolveError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor4ErrorCode), MP_ROM_PTR(&PortDiagnostics_get_Sensor4ErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor4UnexpectedError), MP_ROM_PTR(&PortDiagnostics_get_Sensor4UnexpectedError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor4CommsError), MP_ROM_PTR(&PortDiagnostics_get_Sensor4CommsError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor4NodeTypeMatchError), MP_ROM_PTR(&PortDiagnostics_get_Sensor4NodeTypeMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor4SerialMatchError), MP_ROM_PTR(&PortDiagnostics_get_Sensor4SerialMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor4AddrAssignError), MP_ROM_PTR(&PortDiagnostics_get_Sensor4AddrAssignError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor4AbstractTypeError), MP_ROM_PTR(&PortDiagnostics_get_Sensor4AbstractTypeError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor4SerialResolveError), MP_ROM_PTR(&PortDiagnostics_get_Sensor4SerialResolveError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor5ErrorCode), MP_ROM_PTR(&PortDiagnostics_get_Sensor5ErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor5UnexpectedError), MP_ROM_PTR(&PortDiagnostics_get_Sensor5UnexpectedError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor5CommsError), MP_ROM_PTR(&PortDiagnostics_get_Sensor5CommsError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor5NodeTypeMatchError), MP_ROM_PTR(&PortDiagnostics_get_Sensor5NodeTypeMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor5SerialMatchError), MP_ROM_PTR(&PortDiagnostics_get_Sensor5SerialMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor5AddrAssignError), MP_ROM_PTR(&PortDiagnostics_get_Sensor5AddrAssignError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor5AbstractTypeError), MP_ROM_PTR(&PortDiagnostics_get_Sensor5AbstractTypeError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor5SerialResolveError), MP_ROM_PTR(&PortDiagnostics_get_Sensor5SerialResolveError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor6ErrorCode), MP_ROM_PTR(&PortDiagnostics_get_Sensor6ErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor6UnexpectedError), MP_ROM_PTR(&PortDiagnostics_get_Sensor6UnexpectedError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor6CommsError), MP_ROM_PTR(&PortDiagnostics_get_Sensor6CommsError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor6NodeTypeMatchError), MP_ROM_PTR(&PortDiagnostics_get_Sensor6NodeTypeMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor6SerialMatchError), MP_ROM_PTR(&PortDiagnostics_get_Sensor6SerialMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor6AddrAssignError), MP_ROM_PTR(&PortDiagnostics_get_Sensor6AddrAssignError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor6AbstractTypeError), MP_ROM_PTR(&PortDiagnostics_get_Sensor6AbstractTypeError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor6SerialResolveError), MP_ROM_PTR(&PortDiagnostics_get_Sensor6SerialResolveError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor7ErrorCode), MP_ROM_PTR(&PortDiagnostics_get_Sensor7ErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor7UnexpectedError), MP_ROM_PTR(&PortDiagnostics_get_Sensor7UnexpectedError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor7CommsError), MP_ROM_PTR(&PortDiagnostics_get_Sensor7CommsError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor7NodeTypeMatchError), MP_ROM_PTR(&PortDiagnostics_get_Sensor7NodeTypeMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor7SerialMatchError), MP_ROM_PTR(&PortDiagnostics_get_Sensor7SerialMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor7AddrAssignError), MP_ROM_PTR(&PortDiagnostics_get_Sensor7AddrAssignError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor7AbstractTypeError), MP_ROM_PTR(&PortDiagnostics_get_Sensor7AbstractTypeError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor7SerialResolveError), MP_ROM_PTR(&PortDiagnostics_get_Sensor7SerialResolveError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor8ErrorCode), MP_ROM_PTR(&PortDiagnostics_get_Sensor8ErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor8UnexpectedError), MP_ROM_PTR(&PortDiagnostics_get_Sensor8UnexpectedError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor8CommsError), MP_ROM_PTR(&PortDiagnostics_get_Sensor8CommsError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor8NodeTypeMatchError), MP_ROM_PTR(&PortDiagnostics_get_Sensor8NodeTypeMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor8SerialMatchError), MP_ROM_PTR(&PortDiagnostics_get_Sensor8SerialMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor8AddrAssignError), MP_ROM_PTR(&PortDiagnostics_get_Sensor8AddrAssignError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor8AbstractTypeError), MP_ROM_PTR(&PortDiagnostics_get_Sensor8AbstractTypeError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor8SerialResolveError), MP_ROM_PTR(&PortDiagnostics_get_Sensor8SerialResolveError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel1ErrorCode), MP_ROM_PTR(&PortDiagnostics_get_Wheel1ErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel1UnexpectedError), MP_ROM_PTR(&PortDiagnostics_get_Wheel1UnexpectedError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel1CommsError), MP_ROM_PTR(&PortDiagnostics_get_Wheel1CommsError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel1NodeTypeMatchError), MP_ROM_PTR(&PortDiagnostics_get_Wheel1NodeTypeMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel1SerialMatchError), MP_ROM_PTR(&PortDiagnostics_get_Wheel1SerialMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel1AddrAssignError), MP_ROM_PTR(&PortDiagnostics_get_Wheel1AddrAssignError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel1AbstractTypeError), MP_ROM_PTR(&PortDiagnostics_get_Wheel1AbstractTypeError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel1SerialResolveError), MP_ROM_PTR(&PortDiagnostics_get_Wheel1SerialResolveError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel2ErrorCode), MP_ROM_PTR(&PortDiagnostics_get_Wheel2ErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel2UnexpectedError), MP_ROM_PTR(&PortDiagnostics_get_Wheel2UnexpectedError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel2CommsError), MP_ROM_PTR(&PortDiagnostics_get_Wheel2CommsError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel2NodeTypeMatchError), MP_ROM_PTR(&PortDiagnostics_get_Wheel2NodeTypeMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel2SerialMatchError), MP_ROM_PTR(&PortDiagnostics_get_Wheel2SerialMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel2AddrAssignError), MP_ROM_PTR(&PortDiagnostics_get_Wheel2AddrAssignError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel2AbstractTypeError), MP_ROM_PTR(&PortDiagnostics_get_Wheel2AbstractTypeError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel2SerialResolveError), MP_ROM_PTR(&PortDiagnostics_get_Wheel2SerialResolveError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel3ErrorCode), MP_ROM_PTR(&PortDiagnostics_get_Wheel3ErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel3UnexpectedError), MP_ROM_PTR(&PortDiagnostics_get_Wheel3UnexpectedError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel3CommsError), MP_ROM_PTR(&PortDiagnostics_get_Wheel3CommsError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel3NodeTypeMatchError), MP_ROM_PTR(&PortDiagnostics_get_Wheel3NodeTypeMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel3SerialMatchError), MP_ROM_PTR(&PortDiagnostics_get_Wheel3SerialMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel3AddrAssignError), MP_ROM_PTR(&PortDiagnostics_get_Wheel3AddrAssignError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel3AbstractTypeError), MP_ROM_PTR(&PortDiagnostics_get_Wheel3AbstractTypeError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel3SerialResolveError), MP_ROM_PTR(&PortDiagnostics_get_Wheel3SerialResolveError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel4ErrorCode), MP_ROM_PTR(&PortDiagnostics_get_Wheel4ErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel4UnexpectedError), MP_ROM_PTR(&PortDiagnostics_get_Wheel4UnexpectedError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel4CommsError), MP_ROM_PTR(&PortDiagnostics_get_Wheel4CommsError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel4NodeTypeMatchError), MP_ROM_PTR(&PortDiagnostics_get_Wheel4NodeTypeMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel4SerialMatchError), MP_ROM_PTR(&PortDiagnostics_get_Wheel4SerialMatchError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel4AddrAssignError), MP_ROM_PTR(&PortDiagnostics_get_Wheel4AddrAssignError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel4AbstractTypeError), MP_ROM_PTR(&PortDiagnostics_get_Wheel4AbstractTypeError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel4SerialResolveError), MP_ROM_PTR(&PortDiagnostics_get_Wheel4SerialResolveError_obj) },
};

STATIC MP_DEFINE_CONST_DICT(PortDiagnostics_locals_dict, PortDiagnostics_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    PortDiagnostics_type,
    MP_QSTR_PortDiagnostics,
    MP_TYPE_FLAG_NONE,
    make_new, PortDiagnostics_make_new,
    locals_dict, (mp_obj_dict_t*)&PortDiagnostics_locals_dict
);

STATIC mp_obj_t PortDiagnostics_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PortDiagnostics_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    PortDiagnostics_class_obj_t *p_self = m_new_obj(PortDiagnostics_class_obj_t);
    p_self->base.type = &PortDiagnostics_type;
    
    const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PortDiagnostics_t *p_data = (const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PortDiagnostics_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// PortDiagnostics class constructor from a byte buffer
STATIC mp_obj_t PortDiagnostics_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return PortDiagnostics_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PortDiagnostics_t, PortDiagnostics_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PortDiagnostics_t, PortDiagnostics_class_obj_t, PortDiagnostics)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortDiagnostics_make_from_buf_obj, PortDiagnostics_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'ComponentErrorCodes'
 *
 **********************************************************************/
    
// class structure for type ComponentErrorCodes
typedef struct 
{
    mp_obj_base_t base;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ComponentErrorCodes_t class_data;
} PACKED_STRUCT ComponentErrorCodes_class_obj_t;

// ComponentErrorCodes class constructor from field arguments
STATIC mp_obj_t ComponentErrorCodes_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 6, 6, false);
    
    ComponentErrorCodes_class_obj_t *p_self = m_new_obj(ComponentErrorCodes_class_obj_t);
    p_self->base.type = type;
    
    // MasterSvc
    p_self->class_data.u32MasterSvc = (uint32_t) mp_obj_get_int(p_args[0]);
    // FramFsSvc
    p_self->class_data.u32FramFsSvc = (uint32_t) mp_obj_get_int(p_args[1]);
    // EventLogSvc
    p_self->class_data.u32EventLogSvc = (uint32_t) mp_obj_get_int(p_args[2]);
    // ImgLogSvc
    p_self->class_data.u32ImgLogSvc = (uint32_t) mp_obj_get_int(p_args[3]);
    // TlmLogSvc
    p_self->class_data.u32TlmLogSvc = (uint32_t) mp_obj_get_int(p_args[4]);
    // ImuSvc
    p_self->class_data.u32ImuSvc = (uint32_t) mp_obj_get_int(p_args[5]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'ComponentErrorCodes' getters
//

STATIC mp_obj_t ComponentErrorCodes_get_MasterSvc(mp_obj_t self_in) 
{
    const ComponentErrorCodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32MasterSvc);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ComponentErrorCodes_get_MasterSvc_obj, ComponentErrorCodes_get_MasterSvc);

STATIC mp_obj_t ComponentErrorCodes_get_FramFsSvc(mp_obj_t self_in) 
{
    const ComponentErrorCodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32FramFsSvc);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ComponentErrorCodes_get_FramFsSvc_obj, ComponentErrorCodes_get_FramFsSvc);

STATIC mp_obj_t ComponentErrorCodes_get_EventLogSvc(mp_obj_t self_in) 
{
    const ComponentErrorCodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32EventLogSvc);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ComponentErrorCodes_get_EventLogSvc_obj, ComponentErrorCodes_get_EventLogSvc);

STATIC mp_obj_t ComponentErrorCodes_get_ImgLogSvc(mp_obj_t self_in) 
{
    const ComponentErrorCodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32ImgLogSvc);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ComponentErrorCodes_get_ImgLogSvc_obj, ComponentErrorCodes_get_ImgLogSvc);

STATIC mp_obj_t ComponentErrorCodes_get_TlmLogSvc(mp_obj_t self_in) 
{
    const ComponentErrorCodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32TlmLogSvc);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ComponentErrorCodes_get_TlmLogSvc_obj, ComponentErrorCodes_get_TlmLogSvc);

STATIC mp_obj_t ComponentErrorCodes_get_ImuSvc(mp_obj_t self_in) 
{
    const ComponentErrorCodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32ImuSvc);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ComponentErrorCodes_get_ImuSvc_obj, ComponentErrorCodes_get_ImuSvc);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t ComponentErrorCodes_locals_dict_table[6] = {
    { MP_ROM_QSTR(MP_QSTR_get_MasterSvc), MP_ROM_PTR(&ComponentErrorCodes_get_MasterSvc_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_FramFsSvc), MP_ROM_PTR(&ComponentErrorCodes_get_FramFsSvc_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_EventLogSvc), MP_ROM_PTR(&ComponentErrorCodes_get_EventLogSvc_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ImgLogSvc), MP_ROM_PTR(&ComponentErrorCodes_get_ImgLogSvc_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_TlmLogSvc), MP_ROM_PTR(&ComponentErrorCodes_get_TlmLogSvc_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ImuSvc), MP_ROM_PTR(&ComponentErrorCodes_get_ImuSvc_obj) },
};

STATIC MP_DEFINE_CONST_DICT(ComponentErrorCodes_locals_dict, ComponentErrorCodes_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    ComponentErrorCodes_type,
    MP_QSTR_ComponentErrorCodes,
    MP_TYPE_FLAG_NONE,
    make_new, ComponentErrorCodes_make_new,
    locals_dict, (mp_obj_dict_t*)&ComponentErrorCodes_locals_dict
);

STATIC mp_obj_t ComponentErrorCodes_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ComponentErrorCodes_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    ComponentErrorCodes_class_obj_t *p_self = m_new_obj(ComponentErrorCodes_class_obj_t);
    p_self->base.type = &ComponentErrorCodes_type;
    
    const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ComponentErrorCodes_t *p_data = (const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ComponentErrorCodes_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// ComponentErrorCodes class constructor from a byte buffer
STATIC mp_obj_t ComponentErrorCodes_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return ComponentErrorCodes_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ComponentErrorCodes_t, ComponentErrorCodes_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ComponentErrorCodes_t, ComponentErrorCodes_class_obj_t, ComponentErrorCodes)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ComponentErrorCodes_make_from_buf_obj, ComponentErrorCodes_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'TelemtryLogInclusionMasks'
 *
 **********************************************************************/
    
// class structure for type TelemtryLogInclusionMasks
typedef struct 
{
    mp_obj_base_t base;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemtryLogInclusionMasks_t class_data;
} PACKED_STRUCT TelemtryLogInclusionMasks_class_obj_t;

// TelemtryLogInclusionMasks class constructor from field arguments
STATIC mp_obj_t TelemtryLogInclusionMasks_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 2, 2, false);
    
    TelemtryLogInclusionMasks_class_obj_t *p_self = m_new_obj(TelemtryLogInclusionMasks_class_obj_t);
    p_self->base.type = type;
    
    // fastBitMask
    upy_sd_copy_fidl_scalar_array_from_py_list_uint8_t(p_self->class_data.au8FastBitMask, 5, p_args[0]);
    // slowBitMask
    upy_sd_copy_fidl_scalar_array_from_py_list_uint8_t(p_self->class_data.au8SlowBitMask, 5, p_args[1]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'TelemtryLogInclusionMasks' getters
//

STATIC mp_obj_t TelemtryLogInclusionMasks_get_fastBitMask(mp_obj_t self_in) 
{
    const TelemtryLogInclusionMasks_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return upy_sd_copy_fidl_scalar_array_to_py_list_uint8_t(p_self->class_data.au8FastBitMask, 5);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TelemtryLogInclusionMasks_get_fastBitMask_obj, TelemtryLogInclusionMasks_get_fastBitMask);

STATIC mp_obj_t TelemtryLogInclusionMasks_get_slowBitMask(mp_obj_t self_in) 
{
    const TelemtryLogInclusionMasks_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return upy_sd_copy_fidl_scalar_array_to_py_list_uint8_t(p_self->class_data.au8SlowBitMask, 5);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TelemtryLogInclusionMasks_get_slowBitMask_obj, TelemtryLogInclusionMasks_get_slowBitMask);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t TelemtryLogInclusionMasks_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_fastBitMask), MP_ROM_PTR(&TelemtryLogInclusionMasks_get_fastBitMask_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_slowBitMask), MP_ROM_PTR(&TelemtryLogInclusionMasks_get_slowBitMask_obj) },
};

STATIC MP_DEFINE_CONST_DICT(TelemtryLogInclusionMasks_locals_dict, TelemtryLogInclusionMasks_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    TelemtryLogInclusionMasks_type,
    MP_QSTR_TelemtryLogInclusionMasks,
    MP_TYPE_FLAG_NONE,
    make_new, TelemtryLogInclusionMasks_make_new,
    locals_dict, (mp_obj_dict_t*)&TelemtryLogInclusionMasks_locals_dict
);

STATIC mp_obj_t TelemtryLogInclusionMasks_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemtryLogInclusionMasks_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    TelemtryLogInclusionMasks_class_obj_t *p_self = m_new_obj(TelemtryLogInclusionMasks_class_obj_t);
    p_self->base.type = &TelemtryLogInclusionMasks_type;
    
    const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemtryLogInclusionMasks_t *p_data = (const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemtryLogInclusionMasks_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// TelemtryLogInclusionMasks class constructor from a byte buffer
STATIC mp_obj_t TelemtryLogInclusionMasks_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return TelemtryLogInclusionMasks_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemtryLogInclusionMasks_t, TelemtryLogInclusionMasks_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemtryLogInclusionMasks_t, TelemtryLogInclusionMasks_class_obj_t, TelemtryLogInclusionMasks)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TelemtryLogInclusionMasks_make_from_buf_obj, TelemtryLogInclusionMasks_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'UnsolicitedEventSetup'
 *
 **********************************************************************/
    
// class structure for type UnsolicitedEventSetup
typedef struct 
{
    mp_obj_base_t base;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedEventSetup_t class_data;
} PACKED_STRUCT UnsolicitedEventSetup_class_obj_t;

// UnsolicitedEventSetup class constructor from field arguments
STATIC mp_obj_t UnsolicitedEventSetup_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 12, 12, false);
    
    UnsolicitedEventSetup_class_obj_t *p_self = m_new_obj(UnsolicitedEventSetup_class_obj_t);
    p_self->base.type = type;
    
    // uartInfo
    p_self->class_data.bUartInfo = (bool) mp_obj_get_int(p_args[0]);
    // uartWarnMinor
    p_self->class_data.bUartWarnMinor = (bool) mp_obj_get_int(p_args[1]);
    // uartWarnMajor
    p_self->class_data.bUartWarnMajor = (bool) mp_obj_get_int(p_args[2]);
    // uartCritical
    p_self->class_data.bUartCritical = (bool) mp_obj_get_int(p_args[3]);
    // uart2Info
    p_self->class_data.bUart2Info = (bool) mp_obj_get_int(p_args[4]);
    // uart2WarnMinor
    p_self->class_data.bUart2WarnMinor = (bool) mp_obj_get_int(p_args[5]);
    // uart2WarnMajor
    p_self->class_data.bUart2WarnMajor = (bool) mp_obj_get_int(p_args[6]);
    // uart2Critical
    p_self->class_data.bUart2Critical = (bool) mp_obj_get_int(p_args[7]);
    // canInfo
    p_self->class_data.bCanInfo = (bool) mp_obj_get_int(p_args[8]);
    // canWarnMinor
    p_self->class_data.bCanWarnMinor = (bool) mp_obj_get_int(p_args[9]);
    // canWarnMajor
    p_self->class_data.bCanWarnMajor = (bool) mp_obj_get_int(p_args[10]);
    // canCritical
    p_self->class_data.bCanCritical = (bool) mp_obj_get_int(p_args[11]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'UnsolicitedEventSetup' getters
//

STATIC mp_obj_t UnsolicitedEventSetup_get_uartInfo(mp_obj_t self_in) 
{
    const UnsolicitedEventSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bUartInfo);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedEventSetup_get_uartInfo_obj, UnsolicitedEventSetup_get_uartInfo);

STATIC mp_obj_t UnsolicitedEventSetup_get_uartWarnMinor(mp_obj_t self_in) 
{
    const UnsolicitedEventSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bUartWarnMinor);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedEventSetup_get_uartWarnMinor_obj, UnsolicitedEventSetup_get_uartWarnMinor);

STATIC mp_obj_t UnsolicitedEventSetup_get_uartWarnMajor(mp_obj_t self_in) 
{
    const UnsolicitedEventSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bUartWarnMajor);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedEventSetup_get_uartWarnMajor_obj, UnsolicitedEventSetup_get_uartWarnMajor);

STATIC mp_obj_t UnsolicitedEventSetup_get_uartCritical(mp_obj_t self_in) 
{
    const UnsolicitedEventSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bUartCritical);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedEventSetup_get_uartCritical_obj, UnsolicitedEventSetup_get_uartCritical);

STATIC mp_obj_t UnsolicitedEventSetup_get_uart2Info(mp_obj_t self_in) 
{
    const UnsolicitedEventSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bUart2Info);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedEventSetup_get_uart2Info_obj, UnsolicitedEventSetup_get_uart2Info);

STATIC mp_obj_t UnsolicitedEventSetup_get_uart2WarnMinor(mp_obj_t self_in) 
{
    const UnsolicitedEventSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bUart2WarnMinor);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedEventSetup_get_uart2WarnMinor_obj, UnsolicitedEventSetup_get_uart2WarnMinor);

STATIC mp_obj_t UnsolicitedEventSetup_get_uart2WarnMajor(mp_obj_t self_in) 
{
    const UnsolicitedEventSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bUart2WarnMajor);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedEventSetup_get_uart2WarnMajor_obj, UnsolicitedEventSetup_get_uart2WarnMajor);

STATIC mp_obj_t UnsolicitedEventSetup_get_uart2Critical(mp_obj_t self_in) 
{
    const UnsolicitedEventSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bUart2Critical);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedEventSetup_get_uart2Critical_obj, UnsolicitedEventSetup_get_uart2Critical);

STATIC mp_obj_t UnsolicitedEventSetup_get_canInfo(mp_obj_t self_in) 
{
    const UnsolicitedEventSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bCanInfo);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedEventSetup_get_canInfo_obj, UnsolicitedEventSetup_get_canInfo);

STATIC mp_obj_t UnsolicitedEventSetup_get_canWarnMinor(mp_obj_t self_in) 
{
    const UnsolicitedEventSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bCanWarnMinor);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedEventSetup_get_canWarnMinor_obj, UnsolicitedEventSetup_get_canWarnMinor);

STATIC mp_obj_t UnsolicitedEventSetup_get_canWarnMajor(mp_obj_t self_in) 
{
    const UnsolicitedEventSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bCanWarnMajor);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedEventSetup_get_canWarnMajor_obj, UnsolicitedEventSetup_get_canWarnMajor);

STATIC mp_obj_t UnsolicitedEventSetup_get_canCritical(mp_obj_t self_in) 
{
    const UnsolicitedEventSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bCanCritical);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedEventSetup_get_canCritical_obj, UnsolicitedEventSetup_get_canCritical);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t UnsolicitedEventSetup_locals_dict_table[12] = {
    { MP_ROM_QSTR(MP_QSTR_get_uartInfo), MP_ROM_PTR(&UnsolicitedEventSetup_get_uartInfo_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_uartWarnMinor), MP_ROM_PTR(&UnsolicitedEventSetup_get_uartWarnMinor_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_uartWarnMajor), MP_ROM_PTR(&UnsolicitedEventSetup_get_uartWarnMajor_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_uartCritical), MP_ROM_PTR(&UnsolicitedEventSetup_get_uartCritical_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_uart2Info), MP_ROM_PTR(&UnsolicitedEventSetup_get_uart2Info_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_uart2WarnMinor), MP_ROM_PTR(&UnsolicitedEventSetup_get_uart2WarnMinor_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_uart2WarnMajor), MP_ROM_PTR(&UnsolicitedEventSetup_get_uart2WarnMajor_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_uart2Critical), MP_ROM_PTR(&UnsolicitedEventSetup_get_uart2Critical_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_canInfo), MP_ROM_PTR(&UnsolicitedEventSetup_get_canInfo_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_canWarnMinor), MP_ROM_PTR(&UnsolicitedEventSetup_get_canWarnMinor_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_canWarnMajor), MP_ROM_PTR(&UnsolicitedEventSetup_get_canWarnMajor_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_canCritical), MP_ROM_PTR(&UnsolicitedEventSetup_get_canCritical_obj) },
};

STATIC MP_DEFINE_CONST_DICT(UnsolicitedEventSetup_locals_dict, UnsolicitedEventSetup_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    UnsolicitedEventSetup_type,
    MP_QSTR_UnsolicitedEventSetup,
    MP_TYPE_FLAG_NONE,
    make_new, UnsolicitedEventSetup_make_new,
    locals_dict, (mp_obj_dict_t*)&UnsolicitedEventSetup_locals_dict
);

STATIC mp_obj_t UnsolicitedEventSetup_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedEventSetup_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    UnsolicitedEventSetup_class_obj_t *p_self = m_new_obj(UnsolicitedEventSetup_class_obj_t);
    p_self->base.type = &UnsolicitedEventSetup_type;
    
    const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedEventSetup_t *p_data = (const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedEventSetup_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// UnsolicitedEventSetup class constructor from a byte buffer
STATIC mp_obj_t UnsolicitedEventSetup_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return UnsolicitedEventSetup_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedEventSetup_t, UnsolicitedEventSetup_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedEventSetup_t, UnsolicitedEventSetup_class_obj_t, UnsolicitedEventSetup)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedEventSetup_make_from_buf_obj, UnsolicitedEventSetup_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'EventLogFilterTransferSetup'
 *
 **********************************************************************/
    
// class structure for type EventLogFilterTransferSetup
typedef struct 
{
    mp_obj_base_t base;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EventLogFilterTransferSetup_t class_data;
} PACKED_STRUCT EventLogFilterTransferSetup_class_obj_t;

// EventLogFilterTransferSetup class constructor from field arguments
STATIC mp_obj_t EventLogFilterTransferSetup_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 26, 26, false);
    
    EventLogFilterTransferSetup_class_obj_t *p_self = m_new_obj(EventLogFilterTransferSetup_class_obj_t);
    p_self->base.type = type;
    
    // filterType
    p_self->class_data.eFilterType = (uint8_t) mp_obj_get_int(p_args[0]);
    // startTimeUnix
    p_self->class_data.u32StartTimeUnix = (uint32_t) mp_obj_get_int(p_args[1]);
    // endTimeUnix
    p_self->class_data.u32EndTimeUnix = (uint32_t) mp_obj_get_int(p_args[2]);
    // numEntries
    p_self->class_data.u32NumEntries = (uint32_t) mp_obj_get_int(p_args[3]);
    // writeCounter
    p_self->class_data.u32WriteCounter = (uint32_t) mp_obj_get_int(p_args[4]);
    // includeClassCritical
    p_self->class_data.bIncludeClassCritical = (bool) mp_obj_get_int(p_args[5]);
    // includeClassMajorWarning
    p_self->class_data.bIncludeClassMajorWarning = (bool) mp_obj_get_int(p_args[6]);
    // includeClassMinorWarning
    p_self->class_data.bIncludeClassMinorWarning = (bool) mp_obj_get_int(p_args[7]);
    // includeClassInfo
    p_self->class_data.bIncludeClassInfo = (bool) mp_obj_get_int(p_args[8]);
    // includeSourceCubeComputer
    p_self->class_data.bIncludeSourceCubeComputer = (bool) mp_obj_get_int(p_args[9]);
    // includeSourceRwl0
    p_self->class_data.bIncludeSourceRwl0 = (bool) mp_obj_get_int(p_args[10]);
    // includeSourceRwl1
    p_self->class_data.bIncludeSourceRwl1 = (bool) mp_obj_get_int(p_args[11]);
    // includeSourceRwl2
    p_self->class_data.bIncludeSourceRwl2 = (bool) mp_obj_get_int(p_args[12]);
    // includeSourceRwl3
    p_self->class_data.bIncludeSourceRwl3 = (bool) mp_obj_get_int(p_args[13]);
    // includeSourceFss0
    p_self->class_data.bIncludeSourceFss0 = (bool) mp_obj_get_int(p_args[14]);
    // includeSourceFss1
    p_self->class_data.bIncludeSourceFss1 = (bool) mp_obj_get_int(p_args[15]);
    // includeSourceFss2
    p_self->class_data.bIncludeSourceFss2 = (bool) mp_obj_get_int(p_args[16]);
    // includeSourceFss3
    p_self->class_data.bIncludeSourceFss3 = (bool) mp_obj_get_int(p_args[17]);
    // includeSourceHss0
    p_self->class_data.bIncludeSourceHss0 = (bool) mp_obj_get_int(p_args[18]);
    // includeSourceHss1
    p_self->class_data.bIncludeSourceHss1 = (bool) mp_obj_get_int(p_args[19]);
    // includeSourceStr0
    p_self->class_data.bIncludeSourceStr0 = (bool) mp_obj_get_int(p_args[20]);
    // includeSourceStr1
    p_self->class_data.bIncludeSourceStr1 = (bool) mp_obj_get_int(p_args[21]);
    // includeSourceMag0
    p_self->class_data.bIncludeSourceMag0 = (bool) mp_obj_get_int(p_args[22]);
    // includeSourceMag1
    p_self->class_data.bIncludeSourceMag1 = (bool) mp_obj_get_int(p_args[23]);
    // includeSourceExt0
    p_self->class_data.bIncludeSourceExt0 = (bool) mp_obj_get_int(p_args[24]);
    // includeSourceExt1
    p_self->class_data.bIncludeSourceExt1 = (bool) mp_obj_get_int(p_args[25]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'EventLogFilterTransferSetup' getters
//

STATIC mp_obj_t EventLogFilterTransferSetup_get_filterType(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eFilterType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_filterType_obj, EventLogFilterTransferSetup_get_filterType);

STATIC mp_obj_t EventLogFilterTransferSetup_get_startTimeUnix(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32StartTimeUnix);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_startTimeUnix_obj, EventLogFilterTransferSetup_get_startTimeUnix);

STATIC mp_obj_t EventLogFilterTransferSetup_get_endTimeUnix(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32EndTimeUnix);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_endTimeUnix_obj, EventLogFilterTransferSetup_get_endTimeUnix);

STATIC mp_obj_t EventLogFilterTransferSetup_get_numEntries(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32NumEntries);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_numEntries_obj, EventLogFilterTransferSetup_get_numEntries);

STATIC mp_obj_t EventLogFilterTransferSetup_get_writeCounter(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32WriteCounter);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_writeCounter_obj, EventLogFilterTransferSetup_get_writeCounter);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeClassCritical(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeClassCritical);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeClassCritical_obj, EventLogFilterTransferSetup_get_includeClassCritical);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeClassMajorWarning(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeClassMajorWarning);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeClassMajorWarning_obj, EventLogFilterTransferSetup_get_includeClassMajorWarning);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeClassMinorWarning(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeClassMinorWarning);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeClassMinorWarning_obj, EventLogFilterTransferSetup_get_includeClassMinorWarning);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeClassInfo(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeClassInfo);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeClassInfo_obj, EventLogFilterTransferSetup_get_includeClassInfo);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeSourceCubeComputer(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceCubeComputer);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeSourceCubeComputer_obj, EventLogFilterTransferSetup_get_includeSourceCubeComputer);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeSourceRwl0(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceRwl0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeSourceRwl0_obj, EventLogFilterTransferSetup_get_includeSourceRwl0);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeSourceRwl1(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceRwl1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeSourceRwl1_obj, EventLogFilterTransferSetup_get_includeSourceRwl1);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeSourceRwl2(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceRwl2);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeSourceRwl2_obj, EventLogFilterTransferSetup_get_includeSourceRwl2);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeSourceRwl3(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceRwl3);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeSourceRwl3_obj, EventLogFilterTransferSetup_get_includeSourceRwl3);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeSourceFss0(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceFss0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeSourceFss0_obj, EventLogFilterTransferSetup_get_includeSourceFss0);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeSourceFss1(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceFss1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeSourceFss1_obj, EventLogFilterTransferSetup_get_includeSourceFss1);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeSourceFss2(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceFss2);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeSourceFss2_obj, EventLogFilterTransferSetup_get_includeSourceFss2);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeSourceFss3(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceFss3);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeSourceFss3_obj, EventLogFilterTransferSetup_get_includeSourceFss3);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeSourceHss0(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceHss0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeSourceHss0_obj, EventLogFilterTransferSetup_get_includeSourceHss0);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeSourceHss1(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceHss1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeSourceHss1_obj, EventLogFilterTransferSetup_get_includeSourceHss1);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeSourceStr0(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceStr0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeSourceStr0_obj, EventLogFilterTransferSetup_get_includeSourceStr0);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeSourceStr1(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceStr1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeSourceStr1_obj, EventLogFilterTransferSetup_get_includeSourceStr1);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeSourceMag0(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceMag0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeSourceMag0_obj, EventLogFilterTransferSetup_get_includeSourceMag0);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeSourceMag1(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceMag1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeSourceMag1_obj, EventLogFilterTransferSetup_get_includeSourceMag1);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeSourceExt0(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceExt0);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeSourceExt0_obj, EventLogFilterTransferSetup_get_includeSourceExt0);

STATIC mp_obj_t EventLogFilterTransferSetup_get_includeSourceExt1(mp_obj_t self_in) 
{
    const EventLogFilterTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIncludeSourceExt1);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_get_includeSourceExt1_obj, EventLogFilterTransferSetup_get_includeSourceExt1);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t EventLogFilterTransferSetup_locals_dict_table[26] = {
    { MP_ROM_QSTR(MP_QSTR_get_filterType), MP_ROM_PTR(&EventLogFilterTransferSetup_get_filterType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_startTimeUnix), MP_ROM_PTR(&EventLogFilterTransferSetup_get_startTimeUnix_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_endTimeUnix), MP_ROM_PTR(&EventLogFilterTransferSetup_get_endTimeUnix_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numEntries), MP_ROM_PTR(&EventLogFilterTransferSetup_get_numEntries_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_writeCounter), MP_ROM_PTR(&EventLogFilterTransferSetup_get_writeCounter_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeClassCritical), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeClassCritical_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeClassMajorWarning), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeClassMajorWarning_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeClassMinorWarning), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeClassMinorWarning_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeClassInfo), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeClassInfo_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceCubeComputer), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeSourceCubeComputer_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceRwl0), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeSourceRwl0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceRwl1), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeSourceRwl1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceRwl2), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeSourceRwl2_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceRwl3), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeSourceRwl3_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceFss0), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeSourceFss0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceFss1), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeSourceFss1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceFss2), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeSourceFss2_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceFss3), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeSourceFss3_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceHss0), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeSourceHss0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceHss1), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeSourceHss1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceStr0), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeSourceStr0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceStr1), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeSourceStr1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceMag0), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeSourceMag0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceMag1), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeSourceMag1_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceExt0), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeSourceExt0_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_includeSourceExt1), MP_ROM_PTR(&EventLogFilterTransferSetup_get_includeSourceExt1_obj) },
};

STATIC MP_DEFINE_CONST_DICT(EventLogFilterTransferSetup_locals_dict, EventLogFilterTransferSetup_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    EventLogFilterTransferSetup_type,
    MP_QSTR_EventLogFilterTransferSetup,
    MP_TYPE_FLAG_NONE,
    make_new, EventLogFilterTransferSetup_make_new,
    locals_dict, (mp_obj_dict_t*)&EventLogFilterTransferSetup_locals_dict
);

STATIC mp_obj_t EventLogFilterTransferSetup_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EventLogFilterTransferSetup_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    EventLogFilterTransferSetup_class_obj_t *p_self = m_new_obj(EventLogFilterTransferSetup_class_obj_t);
    p_self->base.type = &EventLogFilterTransferSetup_type;
    
    const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EventLogFilterTransferSetup_t *p_data = (const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EventLogFilterTransferSetup_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// EventLogFilterTransferSetup class constructor from a byte buffer
STATIC mp_obj_t EventLogFilterTransferSetup_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return EventLogFilterTransferSetup_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EventLogFilterTransferSetup_t, EventLogFilterTransferSetup_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EventLogFilterTransferSetup_t, EventLogFilterTransferSetup_class_obj_t, EventLogFilterTransferSetup)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogFilterTransferSetup_make_from_buf_obj, EventLogFilterTransferSetup_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'TelemetryLogTransferSetup'
 *
 **********************************************************************/
    
// class structure for type TelemetryLogTransferSetup
typedef struct 
{
    mp_obj_base_t base;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemetryLogTransferSetup_t class_data;
} PACKED_STRUCT TelemetryLogTransferSetup_class_obj_t;

// TelemetryLogTransferSetup class constructor from field arguments
STATIC mp_obj_t TelemetryLogTransferSetup_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 7, 7, false);
    
    TelemetryLogTransferSetup_class_obj_t *p_self = m_new_obj(TelemetryLogTransferSetup_class_obj_t);
    p_self->base.type = type;
    
    // filterType
    p_self->class_data.eFilterType = (uint8_t) mp_obj_get_int(p_args[0]);
    // startTimeUnix
    p_self->class_data.u32StartTimeUnix = (uint32_t) mp_obj_get_int(p_args[1]);
    // endTimeUnix
    p_self->class_data.u32EndTimeUnix = (uint32_t) mp_obj_get_int(p_args[2]);
    // numEntries
    p_self->class_data.u32NumEntries = (uint32_t) mp_obj_get_int(p_args[3]);
    // writeCounter
    p_self->class_data.u32WriteCounter = (uint32_t) mp_obj_get_int(p_args[4]);
    // tlmLogReturnInterval
    p_self->class_data.eTlmLogReturnInterval = (uint8_t) mp_obj_get_int(p_args[5]);
    // logIdBitmask
    upy_sd_copy_fidl_scalar_array_from_py_list_uint8_t(p_self->class_data.au8LogIdBitmask, 5, p_args[6]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'TelemetryLogTransferSetup' getters
//

STATIC mp_obj_t TelemetryLogTransferSetup_get_filterType(mp_obj_t self_in) 
{
    const TelemetryLogTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eFilterType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TelemetryLogTransferSetup_get_filterType_obj, TelemetryLogTransferSetup_get_filterType);

STATIC mp_obj_t TelemetryLogTransferSetup_get_startTimeUnix(mp_obj_t self_in) 
{
    const TelemetryLogTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32StartTimeUnix);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TelemetryLogTransferSetup_get_startTimeUnix_obj, TelemetryLogTransferSetup_get_startTimeUnix);

STATIC mp_obj_t TelemetryLogTransferSetup_get_endTimeUnix(mp_obj_t self_in) 
{
    const TelemetryLogTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32EndTimeUnix);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TelemetryLogTransferSetup_get_endTimeUnix_obj, TelemetryLogTransferSetup_get_endTimeUnix);

STATIC mp_obj_t TelemetryLogTransferSetup_get_numEntries(mp_obj_t self_in) 
{
    const TelemetryLogTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32NumEntries);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TelemetryLogTransferSetup_get_numEntries_obj, TelemetryLogTransferSetup_get_numEntries);

STATIC mp_obj_t TelemetryLogTransferSetup_get_writeCounter(mp_obj_t self_in) 
{
    const TelemetryLogTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32WriteCounter);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TelemetryLogTransferSetup_get_writeCounter_obj, TelemetryLogTransferSetup_get_writeCounter);

STATIC mp_obj_t TelemetryLogTransferSetup_get_tlmLogReturnInterval(mp_obj_t self_in) 
{
    const TelemetryLogTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eTlmLogReturnInterval);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TelemetryLogTransferSetup_get_tlmLogReturnInterval_obj, TelemetryLogTransferSetup_get_tlmLogReturnInterval);

STATIC mp_obj_t TelemetryLogTransferSetup_get_logIdBitmask(mp_obj_t self_in) 
{
    const TelemetryLogTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return upy_sd_copy_fidl_scalar_array_to_py_list_uint8_t(p_self->class_data.au8LogIdBitmask, 5);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TelemetryLogTransferSetup_get_logIdBitmask_obj, TelemetryLogTransferSetup_get_logIdBitmask);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t TelemetryLogTransferSetup_locals_dict_table[7] = {
    { MP_ROM_QSTR(MP_QSTR_get_filterType), MP_ROM_PTR(&TelemetryLogTransferSetup_get_filterType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_startTimeUnix), MP_ROM_PTR(&TelemetryLogTransferSetup_get_startTimeUnix_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_endTimeUnix), MP_ROM_PTR(&TelemetryLogTransferSetup_get_endTimeUnix_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numEntries), MP_ROM_PTR(&TelemetryLogTransferSetup_get_numEntries_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_writeCounter), MP_ROM_PTR(&TelemetryLogTransferSetup_get_writeCounter_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_tlmLogReturnInterval), MP_ROM_PTR(&TelemetryLogTransferSetup_get_tlmLogReturnInterval_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_logIdBitmask), MP_ROM_PTR(&TelemetryLogTransferSetup_get_logIdBitmask_obj) },
};

STATIC MP_DEFINE_CONST_DICT(TelemetryLogTransferSetup_locals_dict, TelemetryLogTransferSetup_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    TelemetryLogTransferSetup_type,
    MP_QSTR_TelemetryLogTransferSetup,
    MP_TYPE_FLAG_NONE,
    make_new, TelemetryLogTransferSetup_make_new,
    locals_dict, (mp_obj_dict_t*)&TelemetryLogTransferSetup_locals_dict
);

STATIC mp_obj_t TelemetryLogTransferSetup_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemetryLogTransferSetup_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    TelemetryLogTransferSetup_class_obj_t *p_self = m_new_obj(TelemetryLogTransferSetup_class_obj_t);
    p_self->base.type = &TelemetryLogTransferSetup_type;
    
    const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemetryLogTransferSetup_t *p_data = (const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemetryLogTransferSetup_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// TelemetryLogTransferSetup class constructor from a byte buffer
STATIC mp_obj_t TelemetryLogTransferSetup_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return TelemetryLogTransferSetup_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemetryLogTransferSetup_t, TelemetryLogTransferSetup_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemetryLogTransferSetup_t, TelemetryLogTransferSetup_class_obj_t, TelemetryLogTransferSetup)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TelemetryLogTransferSetup_make_from_buf_obj, TelemetryLogTransferSetup_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'UnsolicitedTlmSetup'
 *
 **********************************************************************/
    
// class structure for type UnsolicitedTlmSetup
typedef struct 
{
    mp_obj_base_t base;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedTlmSetup_t class_data;
} PACKED_STRUCT UnsolicitedTlmSetup_class_obj_t;

// UnsolicitedTlmSetup class constructor from field arguments
STATIC mp_obj_t UnsolicitedTlmSetup_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 6, 6, false);
    
    UnsolicitedTlmSetup_class_obj_t *p_self = m_new_obj(UnsolicitedTlmSetup_class_obj_t);
    p_self->base.type = type;
    
    // uartTlmInterval
    p_self->class_data.eUartTlmInterval = (uint8_t) mp_obj_get_int(p_args[0]);
    // uart2TlmInterval
    p_self->class_data.eUart2TlmInterval = (uint8_t) mp_obj_get_int(p_args[1]);
    // canTlmInterval
    p_self->class_data.eCanTlmInterval = (uint8_t) mp_obj_get_int(p_args[2]);
    // uartTlmIdBitmask
    upy_sd_copy_fidl_scalar_array_from_py_list_uint8_t(p_self->class_data.au8UartTlmIdBitmask, 5, p_args[3]);
    // uart2TlmIdBitmask
    upy_sd_copy_fidl_scalar_array_from_py_list_uint8_t(p_self->class_data.au8Uart2TlmIdBitmask, 5, p_args[4]);
    // canTlmIdBitmask
    upy_sd_copy_fidl_scalar_array_from_py_list_uint8_t(p_self->class_data.au8CanTlmIdBitmask, 5, p_args[5]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'UnsolicitedTlmSetup' getters
//

STATIC mp_obj_t UnsolicitedTlmSetup_get_uartTlmInterval(mp_obj_t self_in) 
{
    const UnsolicitedTlmSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eUartTlmInterval);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedTlmSetup_get_uartTlmInterval_obj, UnsolicitedTlmSetup_get_uartTlmInterval);

STATIC mp_obj_t UnsolicitedTlmSetup_get_uart2TlmInterval(mp_obj_t self_in) 
{
    const UnsolicitedTlmSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eUart2TlmInterval);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedTlmSetup_get_uart2TlmInterval_obj, UnsolicitedTlmSetup_get_uart2TlmInterval);

STATIC mp_obj_t UnsolicitedTlmSetup_get_canTlmInterval(mp_obj_t self_in) 
{
    const UnsolicitedTlmSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eCanTlmInterval);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedTlmSetup_get_canTlmInterval_obj, UnsolicitedTlmSetup_get_canTlmInterval);

STATIC mp_obj_t UnsolicitedTlmSetup_get_uartTlmIdBitmask(mp_obj_t self_in) 
{
    const UnsolicitedTlmSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return upy_sd_copy_fidl_scalar_array_to_py_list_uint8_t(p_self->class_data.au8UartTlmIdBitmask, 5);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedTlmSetup_get_uartTlmIdBitmask_obj, UnsolicitedTlmSetup_get_uartTlmIdBitmask);

STATIC mp_obj_t UnsolicitedTlmSetup_get_uart2TlmIdBitmask(mp_obj_t self_in) 
{
    const UnsolicitedTlmSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return upy_sd_copy_fidl_scalar_array_to_py_list_uint8_t(p_self->class_data.au8Uart2TlmIdBitmask, 5);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedTlmSetup_get_uart2TlmIdBitmask_obj, UnsolicitedTlmSetup_get_uart2TlmIdBitmask);

STATIC mp_obj_t UnsolicitedTlmSetup_get_canTlmIdBitmask(mp_obj_t self_in) 
{
    const UnsolicitedTlmSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return upy_sd_copy_fidl_scalar_array_to_py_list_uint8_t(p_self->class_data.au8CanTlmIdBitmask, 5);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedTlmSetup_get_canTlmIdBitmask_obj, UnsolicitedTlmSetup_get_canTlmIdBitmask);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t UnsolicitedTlmSetup_locals_dict_table[6] = {
    { MP_ROM_QSTR(MP_QSTR_get_uartTlmInterval), MP_ROM_PTR(&UnsolicitedTlmSetup_get_uartTlmInterval_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_uart2TlmInterval), MP_ROM_PTR(&UnsolicitedTlmSetup_get_uart2TlmInterval_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_canTlmInterval), MP_ROM_PTR(&UnsolicitedTlmSetup_get_canTlmInterval_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_uartTlmIdBitmask), MP_ROM_PTR(&UnsolicitedTlmSetup_get_uartTlmIdBitmask_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_uart2TlmIdBitmask), MP_ROM_PTR(&UnsolicitedTlmSetup_get_uart2TlmIdBitmask_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_canTlmIdBitmask), MP_ROM_PTR(&UnsolicitedTlmSetup_get_canTlmIdBitmask_obj) },
};

STATIC MP_DEFINE_CONST_DICT(UnsolicitedTlmSetup_locals_dict, UnsolicitedTlmSetup_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    UnsolicitedTlmSetup_type,
    MP_QSTR_UnsolicitedTlmSetup,
    MP_TYPE_FLAG_NONE,
    make_new, UnsolicitedTlmSetup_make_new,
    locals_dict, (mp_obj_dict_t*)&UnsolicitedTlmSetup_locals_dict
);

STATIC mp_obj_t UnsolicitedTlmSetup_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedTlmSetup_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    UnsolicitedTlmSetup_class_obj_t *p_self = m_new_obj(UnsolicitedTlmSetup_class_obj_t);
    p_self->base.type = &UnsolicitedTlmSetup_type;
    
    const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedTlmSetup_t *p_data = (const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedTlmSetup_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// UnsolicitedTlmSetup class constructor from a byte buffer
STATIC mp_obj_t UnsolicitedTlmSetup_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return UnsolicitedTlmSetup_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedTlmSetup_t, UnsolicitedTlmSetup_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedTlmSetup_t, UnsolicitedTlmSetup_class_obj_t, UnsolicitedTlmSetup)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(UnsolicitedTlmSetup_make_from_buf_obj, UnsolicitedTlmSetup_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'PowerState'
 *
 **********************************************************************/
    
// class structure for type PowerState
typedef struct 
{
    mp_obj_base_t base;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PowerState_t class_data;
} PACKED_STRUCT PowerState_class_obj_t;

// PowerState class constructor from field arguments
STATIC mp_obj_t PowerState_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 20, 20, false);
    
    PowerState_class_obj_t *p_self = m_new_obj(PowerState_class_obj_t);
    p_self->base.type = type;
    
    // Rwl0Power
    p_self->class_data.eRwl0Power = (uint8_t) mp_obj_get_int(p_args[0]);
    // Rwl1Power
    p_self->class_data.eRwl1Power = (uint8_t) mp_obj_get_int(p_args[1]);
    // Rwl2Power
    p_self->class_data.eRwl2Power = (uint8_t) mp_obj_get_int(p_args[2]);
    // Rwl3Power
    p_self->class_data.eRwl3Power = (uint8_t) mp_obj_get_int(p_args[3]);
    // Mag0Power
    p_self->class_data.eMag0Power = (uint8_t) mp_obj_get_int(p_args[4]);
    // Mag1Power
    p_self->class_data.eMag1Power = (uint8_t) mp_obj_get_int(p_args[5]);
    // Gyro0Power
    p_self->class_data.eGyro0Power = (uint8_t) mp_obj_get_int(p_args[6]);
    // Gyro1Power
    p_self->class_data.eGyro1Power = (uint8_t) mp_obj_get_int(p_args[7]);
    // Fss0Power
    p_self->class_data.eFss0Power = (uint8_t) mp_obj_get_int(p_args[8]);
    // Fss1Power
    p_self->class_data.eFss1Power = (uint8_t) mp_obj_get_int(p_args[9]);
    // Fss2Power
    p_self->class_data.eFss2Power = (uint8_t) mp_obj_get_int(p_args[10]);
    // Fss3Power
    p_self->class_data.eFss3Power = (uint8_t) mp_obj_get_int(p_args[11]);
    // Hss0Power
    p_self->class_data.eHss0Power = (uint8_t) mp_obj_get_int(p_args[12]);
    // Hss1Power
    p_self->class_data.eHss1Power = (uint8_t) mp_obj_get_int(p_args[13]);
    // Str0Power
    p_self->class_data.eStr0Power = (uint8_t) mp_obj_get_int(p_args[14]);
    // Str1Power
    p_self->class_data.eStr1Power = (uint8_t) mp_obj_get_int(p_args[15]);
    // ExtSensor0Power
    p_self->class_data.eExtSensor0Power = (uint8_t) mp_obj_get_int(p_args[16]);
    // ExtSensor1Power
    p_self->class_data.eExtSensor1Power = (uint8_t) mp_obj_get_int(p_args[17]);
    // ExtGyro0Power
    p_self->class_data.eExtGyro0Power = (uint8_t) mp_obj_get_int(p_args[18]);
    // ExtGyro1Power
    p_self->class_data.eExtGyro1Power = (uint8_t) mp_obj_get_int(p_args[19]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'PowerState' getters
//

STATIC mp_obj_t PowerState_get_Rwl0Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eRwl0Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_Rwl0Power_obj, PowerState_get_Rwl0Power);

STATIC mp_obj_t PowerState_get_Rwl1Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eRwl1Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_Rwl1Power_obj, PowerState_get_Rwl1Power);

STATIC mp_obj_t PowerState_get_Rwl2Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eRwl2Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_Rwl2Power_obj, PowerState_get_Rwl2Power);

STATIC mp_obj_t PowerState_get_Rwl3Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eRwl3Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_Rwl3Power_obj, PowerState_get_Rwl3Power);

STATIC mp_obj_t PowerState_get_Mag0Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eMag0Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_Mag0Power_obj, PowerState_get_Mag0Power);

STATIC mp_obj_t PowerState_get_Mag1Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eMag1Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_Mag1Power_obj, PowerState_get_Mag1Power);

STATIC mp_obj_t PowerState_get_Gyro0Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eGyro0Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_Gyro0Power_obj, PowerState_get_Gyro0Power);

STATIC mp_obj_t PowerState_get_Gyro1Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eGyro1Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_Gyro1Power_obj, PowerState_get_Gyro1Power);

STATIC mp_obj_t PowerState_get_Fss0Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eFss0Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_Fss0Power_obj, PowerState_get_Fss0Power);

STATIC mp_obj_t PowerState_get_Fss1Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eFss1Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_Fss1Power_obj, PowerState_get_Fss1Power);

STATIC mp_obj_t PowerState_get_Fss2Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eFss2Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_Fss2Power_obj, PowerState_get_Fss2Power);

STATIC mp_obj_t PowerState_get_Fss3Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eFss3Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_Fss3Power_obj, PowerState_get_Fss3Power);

STATIC mp_obj_t PowerState_get_Hss0Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eHss0Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_Hss0Power_obj, PowerState_get_Hss0Power);

STATIC mp_obj_t PowerState_get_Hss1Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eHss1Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_Hss1Power_obj, PowerState_get_Hss1Power);

STATIC mp_obj_t PowerState_get_Str0Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eStr0Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_Str0Power_obj, PowerState_get_Str0Power);

STATIC mp_obj_t PowerState_get_Str1Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eStr1Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_Str1Power_obj, PowerState_get_Str1Power);

STATIC mp_obj_t PowerState_get_ExtSensor0Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExtSensor0Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_ExtSensor0Power_obj, PowerState_get_ExtSensor0Power);

STATIC mp_obj_t PowerState_get_ExtSensor1Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExtSensor1Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_ExtSensor1Power_obj, PowerState_get_ExtSensor1Power);

STATIC mp_obj_t PowerState_get_ExtGyro0Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExtGyro0Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_ExtGyro0Power_obj, PowerState_get_ExtGyro0Power);

STATIC mp_obj_t PowerState_get_ExtGyro1Power(mp_obj_t self_in) 
{
    const PowerState_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExtGyro1Power);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_get_ExtGyro1Power_obj, PowerState_get_ExtGyro1Power);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t PowerState_locals_dict_table[20] = {
    { MP_ROM_QSTR(MP_QSTR_get_Rwl0Power), MP_ROM_PTR(&PowerState_get_Rwl0Power_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Rwl1Power), MP_ROM_PTR(&PowerState_get_Rwl1Power_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Rwl2Power), MP_ROM_PTR(&PowerState_get_Rwl2Power_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Rwl3Power), MP_ROM_PTR(&PowerState_get_Rwl3Power_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Mag0Power), MP_ROM_PTR(&PowerState_get_Mag0Power_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Mag1Power), MP_ROM_PTR(&PowerState_get_Mag1Power_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Gyro0Power), MP_ROM_PTR(&PowerState_get_Gyro0Power_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Gyro1Power), MP_ROM_PTR(&PowerState_get_Gyro1Power_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Fss0Power), MP_ROM_PTR(&PowerState_get_Fss0Power_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Fss1Power), MP_ROM_PTR(&PowerState_get_Fss1Power_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Fss2Power), MP_ROM_PTR(&PowerState_get_Fss2Power_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Fss3Power), MP_ROM_PTR(&PowerState_get_Fss3Power_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Hss0Power), MP_ROM_PTR(&PowerState_get_Hss0Power_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Hss1Power), MP_ROM_PTR(&PowerState_get_Hss1Power_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Str0Power), MP_ROM_PTR(&PowerState_get_Str0Power_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Str1Power), MP_ROM_PTR(&PowerState_get_Str1Power_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ExtSensor0Power), MP_ROM_PTR(&PowerState_get_ExtSensor0Power_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ExtSensor1Power), MP_ROM_PTR(&PowerState_get_ExtSensor1Power_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ExtGyro0Power), MP_ROM_PTR(&PowerState_get_ExtGyro0Power_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ExtGyro1Power), MP_ROM_PTR(&PowerState_get_ExtGyro1Power_obj) },
};

STATIC MP_DEFINE_CONST_DICT(PowerState_locals_dict, PowerState_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    PowerState_type,
    MP_QSTR_PowerState,
    MP_TYPE_FLAG_NONE,
    make_new, PowerState_make_new,
    locals_dict, (mp_obj_dict_t*)&PowerState_locals_dict
);

STATIC mp_obj_t PowerState_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PowerState_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    PowerState_class_obj_t *p_self = m_new_obj(PowerState_class_obj_t);
    p_self->base.type = &PowerState_type;
    
    const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PowerState_t *p_data = (const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PowerState_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// PowerState class constructor from a byte buffer
STATIC mp_obj_t PowerState_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return PowerState_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PowerState_t, PowerState_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PowerState_t, PowerState_class_obj_t, PowerState)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PowerState_make_from_buf_obj, PowerState_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'EraseLogData'
 *
 **********************************************************************/
    
// class structure for type EraseLogData
typedef struct 
{
    mp_obj_base_t base;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EraseLogData_t class_data;
} PACKED_STRUCT EraseLogData_class_obj_t;

// EraseLogData class constructor from field arguments
STATIC mp_obj_t EraseLogData_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    EraseLogData_class_obj_t *p_self = m_new_obj(EraseLogData_class_obj_t);
    p_self->base.type = type;
    
    // magicNumber
    p_self->class_data.eMagicNumber = (uint8_t) mp_obj_get_int(p_args[0]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'EraseLogData' getters
//

STATIC mp_obj_t EraseLogData_get_magicNumber(mp_obj_t self_in) 
{
    const EraseLogData_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eMagicNumber);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EraseLogData_get_magicNumber_obj, EraseLogData_get_magicNumber);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t EraseLogData_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_magicNumber), MP_ROM_PTR(&EraseLogData_get_magicNumber_obj) },
};

STATIC MP_DEFINE_CONST_DICT(EraseLogData_locals_dict, EraseLogData_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    EraseLogData_type,
    MP_QSTR_EraseLogData,
    MP_TYPE_FLAG_NONE,
    make_new, EraseLogData_make_new,
    locals_dict, (mp_obj_dict_t*)&EraseLogData_locals_dict
);

STATIC mp_obj_t EraseLogData_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EraseLogData_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    EraseLogData_class_obj_t *p_self = m_new_obj(EraseLogData_class_obj_t);
    p_self->base.type = &EraseLogData_type;
    
    const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EraseLogData_t *p_data = (const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EraseLogData_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// EraseLogData class constructor from a byte buffer
STATIC mp_obj_t EraseLogData_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return EraseLogData_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EraseLogData_t, EraseLogData_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EraseLogData_t, EraseLogData_class_obj_t, EraseLogData)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EraseLogData_make_from_buf_obj, EraseLogData_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'TelemtryLogStatus'
 *
 **********************************************************************/
    
// class structure for type TelemtryLogStatus
typedef struct 
{
    mp_obj_base_t base;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemtryLogStatus_t class_data;
} PACKED_STRUCT TelemtryLogStatus_class_obj_t;

// TelemtryLogStatus class constructor from field arguments
STATIC mp_obj_t TelemtryLogStatus_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 7, 7, false);
    
    TelemtryLogStatus_class_obj_t *p_self = m_new_obj(TelemtryLogStatus_class_obj_t);
    p_self->base.type = type;
    
    // numberOfEntriesQueued
    p_self->class_data.u8NumberOfEntriesQueued = (uint8_t) mp_obj_get_int(p_args[0]);
    // numberOfTlmIterations
    p_self->class_data.u8NumberOfTlmIterations = (uint8_t) mp_obj_get_int(p_args[1]);
    // numberOfEntries
    p_self->class_data.u32NumberOfEntries = (uint32_t) mp_obj_get_int(p_args[2]);
    // oldestEntryUnix
    p_self->class_data.u32OldestEntryUnix = (uint32_t) mp_obj_get_int(p_args[3]);
    // latestEntryUnix
    p_self->class_data.u32LatestEntryUnix = (uint32_t) mp_obj_get_int(p_args[4]);
    // writeCounter
    p_self->class_data.u32WriteCounter = (uint32_t) mp_obj_get_int(p_args[5]);
    // readQueueState
    p_self->class_data.eReadQueueState = (uint8_t) mp_obj_get_int(p_args[6]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'TelemtryLogStatus' getters
//

STATIC mp_obj_t TelemtryLogStatus_get_numberOfEntriesQueued(mp_obj_t self_in) 
{
    const TelemtryLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u8NumberOfEntriesQueued);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TelemtryLogStatus_get_numberOfEntriesQueued_obj, TelemtryLogStatus_get_numberOfEntriesQueued);

STATIC mp_obj_t TelemtryLogStatus_get_numberOfTlmIterations(mp_obj_t self_in) 
{
    const TelemtryLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u8NumberOfTlmIterations);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TelemtryLogStatus_get_numberOfTlmIterations_obj, TelemtryLogStatus_get_numberOfTlmIterations);

STATIC mp_obj_t TelemtryLogStatus_get_numberOfEntries(mp_obj_t self_in) 
{
    const TelemtryLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32NumberOfEntries);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TelemtryLogStatus_get_numberOfEntries_obj, TelemtryLogStatus_get_numberOfEntries);

STATIC mp_obj_t TelemtryLogStatus_get_oldestEntryUnix(mp_obj_t self_in) 
{
    const TelemtryLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32OldestEntryUnix);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TelemtryLogStatus_get_oldestEntryUnix_obj, TelemtryLogStatus_get_oldestEntryUnix);

STATIC mp_obj_t TelemtryLogStatus_get_latestEntryUnix(mp_obj_t self_in) 
{
    const TelemtryLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32LatestEntryUnix);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TelemtryLogStatus_get_latestEntryUnix_obj, TelemtryLogStatus_get_latestEntryUnix);

STATIC mp_obj_t TelemtryLogStatus_get_writeCounter(mp_obj_t self_in) 
{
    const TelemtryLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32WriteCounter);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TelemtryLogStatus_get_writeCounter_obj, TelemtryLogStatus_get_writeCounter);

STATIC mp_obj_t TelemtryLogStatus_get_readQueueState(mp_obj_t self_in) 
{
    const TelemtryLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eReadQueueState);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TelemtryLogStatus_get_readQueueState_obj, TelemtryLogStatus_get_readQueueState);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t TelemtryLogStatus_locals_dict_table[7] = {
    { MP_ROM_QSTR(MP_QSTR_get_numberOfEntriesQueued), MP_ROM_PTR(&TelemtryLogStatus_get_numberOfEntriesQueued_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numberOfTlmIterations), MP_ROM_PTR(&TelemtryLogStatus_get_numberOfTlmIterations_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numberOfEntries), MP_ROM_PTR(&TelemtryLogStatus_get_numberOfEntries_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_oldestEntryUnix), MP_ROM_PTR(&TelemtryLogStatus_get_oldestEntryUnix_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_latestEntryUnix), MP_ROM_PTR(&TelemtryLogStatus_get_latestEntryUnix_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_writeCounter), MP_ROM_PTR(&TelemtryLogStatus_get_writeCounter_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_readQueueState), MP_ROM_PTR(&TelemtryLogStatus_get_readQueueState_obj) },
};

STATIC MP_DEFINE_CONST_DICT(TelemtryLogStatus_locals_dict, TelemtryLogStatus_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    TelemtryLogStatus_type,
    MP_QSTR_TelemtryLogStatus,
    MP_TYPE_FLAG_NONE,
    make_new, TelemtryLogStatus_make_new,
    locals_dict, (mp_obj_dict_t*)&TelemtryLogStatus_locals_dict
);

STATIC mp_obj_t TelemtryLogStatus_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemtryLogStatus_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    TelemtryLogStatus_class_obj_t *p_self = m_new_obj(TelemtryLogStatus_class_obj_t);
    p_self->base.type = &TelemtryLogStatus_type;
    
    const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemtryLogStatus_t *p_data = (const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemtryLogStatus_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// TelemtryLogStatus class constructor from a byte buffer
STATIC mp_obj_t TelemtryLogStatus_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return TelemtryLogStatus_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemtryLogStatus_t, TelemtryLogStatus_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemtryLogStatus_t, TelemtryLogStatus_class_obj_t, TelemtryLogStatus)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(TelemtryLogStatus_make_from_buf_obj, TelemtryLogStatus_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'PortMap'
 *
 **********************************************************************/
    
// class structure for type PortMap
typedef struct 
{
    mp_obj_base_t base;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PortMap_t class_data;
} PACKED_STRUCT PortMap_class_obj_t;

// PortMap class constructor from field arguments
STATIC mp_obj_t PortMap_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 48, 48, false);
    
    PortMap_class_obj_t *p_self = m_new_obj(PortMap_class_obj_t);
    p_self->base.type = type;
    
    // Sensor1NodeType
    p_self->class_data.eSensor1NodeType = (uint8_t) mp_obj_get_int(p_args[0]);
    // Sensor1AbstractType
    p_self->class_data.eSensor1AbstractType = (uint8_t) mp_obj_get_int(p_args[1]);
    // Sensor1SerialInt
    p_self->class_data.u32Sensor1SerialInt = (uint32_t) mp_obj_get_int(p_args[2]);
    // Sensor1Address
    p_self->class_data.u32Sensor1Address = (uint32_t) mp_obj_get_int(p_args[3]);
    // Sensor2NodeType
    p_self->class_data.eSensor2NodeType = (uint8_t) mp_obj_get_int(p_args[4]);
    // Sensor2AbstractType
    p_self->class_data.eSensor2AbstractType = (uint8_t) mp_obj_get_int(p_args[5]);
    // Sensor2SerialInt
    p_self->class_data.u32Sensor2SerialInt = (uint32_t) mp_obj_get_int(p_args[6]);
    // Sensor2Address
    p_self->class_data.u32Sensor2Address = (uint32_t) mp_obj_get_int(p_args[7]);
    // Sensor3NodeType
    p_self->class_data.eSensor3NodeType = (uint8_t) mp_obj_get_int(p_args[8]);
    // Sensor3AbstractType
    p_self->class_data.eSensor3AbstractType = (uint8_t) mp_obj_get_int(p_args[9]);
    // Sensor3SerialInt
    p_self->class_data.u32Sensor3SerialInt = (uint32_t) mp_obj_get_int(p_args[10]);
    // Sensor3Address
    p_self->class_data.u32Sensor3Address = (uint32_t) mp_obj_get_int(p_args[11]);
    // Sensor4NodeType
    p_self->class_data.eSensor4NodeType = (uint8_t) mp_obj_get_int(p_args[12]);
    // Sensor4AbstractType
    p_self->class_data.eSensor4AbstractType = (uint8_t) mp_obj_get_int(p_args[13]);
    // Sensor4SerialInt
    p_self->class_data.u32Sensor4SerialInt = (uint32_t) mp_obj_get_int(p_args[14]);
    // Sensor4Address
    p_self->class_data.u32Sensor4Address = (uint32_t) mp_obj_get_int(p_args[15]);
    // Sensor5NodeType
    p_self->class_data.eSensor5NodeType = (uint8_t) mp_obj_get_int(p_args[16]);
    // Sensor5AbstractType
    p_self->class_data.eSensor5AbstractType = (uint8_t) mp_obj_get_int(p_args[17]);
    // Sensor5SerialInt
    p_self->class_data.u32Sensor5SerialInt = (uint32_t) mp_obj_get_int(p_args[18]);
    // Sensor5Address
    p_self->class_data.u32Sensor5Address = (uint32_t) mp_obj_get_int(p_args[19]);
    // Sensor6NodeType
    p_self->class_data.eSensor6NodeType = (uint8_t) mp_obj_get_int(p_args[20]);
    // Sensor6AbstractType
    p_self->class_data.eSensor6AbstractType = (uint8_t) mp_obj_get_int(p_args[21]);
    // Sensor6SerialInt
    p_self->class_data.u32Sensor6SerialInt = (uint32_t) mp_obj_get_int(p_args[22]);
    // Sensor6Address
    p_self->class_data.u32Sensor6Address = (uint32_t) mp_obj_get_int(p_args[23]);
    // Sensor7NodeType
    p_self->class_data.eSensor7NodeType = (uint8_t) mp_obj_get_int(p_args[24]);
    // Sensor7AbstractType
    p_self->class_data.eSensor7AbstractType = (uint8_t) mp_obj_get_int(p_args[25]);
    // Sensor7SerialInt
    p_self->class_data.u32Sensor7SerialInt = (uint32_t) mp_obj_get_int(p_args[26]);
    // Sensor7Address
    p_self->class_data.u32Sensor7Address = (uint32_t) mp_obj_get_int(p_args[27]);
    // Sensor8NodeType
    p_self->class_data.eSensor8NodeType = (uint8_t) mp_obj_get_int(p_args[28]);
    // Sensor8AbstractType
    p_self->class_data.eSensor8AbstractType = (uint8_t) mp_obj_get_int(p_args[29]);
    // Sensor8SerialInt
    p_self->class_data.u32Sensor8SerialInt = (uint32_t) mp_obj_get_int(p_args[30]);
    // Sensor8Address
    p_self->class_data.u32Sensor8Address = (uint32_t) mp_obj_get_int(p_args[31]);
    // Wheel1NodeType
    p_self->class_data.eWheel1NodeType = (uint8_t) mp_obj_get_int(p_args[32]);
    // Wheel1AbstractType
    p_self->class_data.eWheel1AbstractType = (uint8_t) mp_obj_get_int(p_args[33]);
    // Wheel1SerialInt
    p_self->class_data.u32Wheel1SerialInt = (uint32_t) mp_obj_get_int(p_args[34]);
    // Wheel1Address
    p_self->class_data.u32Wheel1Address = (uint32_t) mp_obj_get_int(p_args[35]);
    // Wheel2NodeType
    p_self->class_data.eWheel2NodeType = (uint8_t) mp_obj_get_int(p_args[36]);
    // Wheel2AbstractType
    p_self->class_data.eWheel2AbstractType = (uint8_t) mp_obj_get_int(p_args[37]);
    // Wheel2SerialInt
    p_self->class_data.u32Wheel2SerialInt = (uint32_t) mp_obj_get_int(p_args[38]);
    // Wheel2Address
    p_self->class_data.u32Wheel2Address = (uint32_t) mp_obj_get_int(p_args[39]);
    // Wheel3NodeType
    p_self->class_data.eWheel3NodeType = (uint8_t) mp_obj_get_int(p_args[40]);
    // Wheel3AbstractType
    p_self->class_data.eWheel3AbstractType = (uint8_t) mp_obj_get_int(p_args[41]);
    // Wheel3SerialInt
    p_self->class_data.u32Wheel3SerialInt = (uint32_t) mp_obj_get_int(p_args[42]);
    // Wheel3Address
    p_self->class_data.u32Wheel3Address = (uint32_t) mp_obj_get_int(p_args[43]);
    // Wheel4NodeType
    p_self->class_data.eWheel4NodeType = (uint8_t) mp_obj_get_int(p_args[44]);
    // Wheel4AbstractType
    p_self->class_data.eWheel4AbstractType = (uint8_t) mp_obj_get_int(p_args[45]);
    // Wheel4SerialInt
    p_self->class_data.u32Wheel4SerialInt = (uint32_t) mp_obj_get_int(p_args[46]);
    // Wheel4Address
    p_self->class_data.u32Wheel4Address = (uint32_t) mp_obj_get_int(p_args[47]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'PortMap' getters
//

STATIC mp_obj_t PortMap_get_Sensor1NodeType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eSensor1NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor1NodeType_obj, PortMap_get_Sensor1NodeType);

STATIC mp_obj_t PortMap_get_Sensor1AbstractType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eSensor1AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor1AbstractType_obj, PortMap_get_Sensor1AbstractType);

STATIC mp_obj_t PortMap_get_Sensor1SerialInt(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor1SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor1SerialInt_obj, PortMap_get_Sensor1SerialInt);

STATIC mp_obj_t PortMap_get_Sensor1Address(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor1Address);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor1Address_obj, PortMap_get_Sensor1Address);

STATIC mp_obj_t PortMap_get_Sensor2NodeType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eSensor2NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor2NodeType_obj, PortMap_get_Sensor2NodeType);

STATIC mp_obj_t PortMap_get_Sensor2AbstractType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eSensor2AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor2AbstractType_obj, PortMap_get_Sensor2AbstractType);

STATIC mp_obj_t PortMap_get_Sensor2SerialInt(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor2SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor2SerialInt_obj, PortMap_get_Sensor2SerialInt);

STATIC mp_obj_t PortMap_get_Sensor2Address(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor2Address);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor2Address_obj, PortMap_get_Sensor2Address);

STATIC mp_obj_t PortMap_get_Sensor3NodeType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eSensor3NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor3NodeType_obj, PortMap_get_Sensor3NodeType);

STATIC mp_obj_t PortMap_get_Sensor3AbstractType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eSensor3AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor3AbstractType_obj, PortMap_get_Sensor3AbstractType);

STATIC mp_obj_t PortMap_get_Sensor3SerialInt(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor3SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor3SerialInt_obj, PortMap_get_Sensor3SerialInt);

STATIC mp_obj_t PortMap_get_Sensor3Address(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor3Address);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor3Address_obj, PortMap_get_Sensor3Address);

STATIC mp_obj_t PortMap_get_Sensor4NodeType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eSensor4NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor4NodeType_obj, PortMap_get_Sensor4NodeType);

STATIC mp_obj_t PortMap_get_Sensor4AbstractType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eSensor4AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor4AbstractType_obj, PortMap_get_Sensor4AbstractType);

STATIC mp_obj_t PortMap_get_Sensor4SerialInt(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor4SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor4SerialInt_obj, PortMap_get_Sensor4SerialInt);

STATIC mp_obj_t PortMap_get_Sensor4Address(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor4Address);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor4Address_obj, PortMap_get_Sensor4Address);

STATIC mp_obj_t PortMap_get_Sensor5NodeType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eSensor5NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor5NodeType_obj, PortMap_get_Sensor5NodeType);

STATIC mp_obj_t PortMap_get_Sensor5AbstractType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eSensor5AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor5AbstractType_obj, PortMap_get_Sensor5AbstractType);

STATIC mp_obj_t PortMap_get_Sensor5SerialInt(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor5SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor5SerialInt_obj, PortMap_get_Sensor5SerialInt);

STATIC mp_obj_t PortMap_get_Sensor5Address(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor5Address);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor5Address_obj, PortMap_get_Sensor5Address);

STATIC mp_obj_t PortMap_get_Sensor6NodeType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eSensor6NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor6NodeType_obj, PortMap_get_Sensor6NodeType);

STATIC mp_obj_t PortMap_get_Sensor6AbstractType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eSensor6AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor6AbstractType_obj, PortMap_get_Sensor6AbstractType);

STATIC mp_obj_t PortMap_get_Sensor6SerialInt(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor6SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor6SerialInt_obj, PortMap_get_Sensor6SerialInt);

STATIC mp_obj_t PortMap_get_Sensor6Address(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor6Address);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor6Address_obj, PortMap_get_Sensor6Address);

STATIC mp_obj_t PortMap_get_Sensor7NodeType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eSensor7NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor7NodeType_obj, PortMap_get_Sensor7NodeType);

STATIC mp_obj_t PortMap_get_Sensor7AbstractType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eSensor7AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor7AbstractType_obj, PortMap_get_Sensor7AbstractType);

STATIC mp_obj_t PortMap_get_Sensor7SerialInt(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor7SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor7SerialInt_obj, PortMap_get_Sensor7SerialInt);

STATIC mp_obj_t PortMap_get_Sensor7Address(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor7Address);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor7Address_obj, PortMap_get_Sensor7Address);

STATIC mp_obj_t PortMap_get_Sensor8NodeType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eSensor8NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor8NodeType_obj, PortMap_get_Sensor8NodeType);

STATIC mp_obj_t PortMap_get_Sensor8AbstractType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eSensor8AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor8AbstractType_obj, PortMap_get_Sensor8AbstractType);

STATIC mp_obj_t PortMap_get_Sensor8SerialInt(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor8SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor8SerialInt_obj, PortMap_get_Sensor8SerialInt);

STATIC mp_obj_t PortMap_get_Sensor8Address(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Sensor8Address);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Sensor8Address_obj, PortMap_get_Sensor8Address);

STATIC mp_obj_t PortMap_get_Wheel1NodeType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eWheel1NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Wheel1NodeType_obj, PortMap_get_Wheel1NodeType);

STATIC mp_obj_t PortMap_get_Wheel1AbstractType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eWheel1AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Wheel1AbstractType_obj, PortMap_get_Wheel1AbstractType);

STATIC mp_obj_t PortMap_get_Wheel1SerialInt(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Wheel1SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Wheel1SerialInt_obj, PortMap_get_Wheel1SerialInt);

STATIC mp_obj_t PortMap_get_Wheel1Address(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Wheel1Address);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Wheel1Address_obj, PortMap_get_Wheel1Address);

STATIC mp_obj_t PortMap_get_Wheel2NodeType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eWheel2NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Wheel2NodeType_obj, PortMap_get_Wheel2NodeType);

STATIC mp_obj_t PortMap_get_Wheel2AbstractType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eWheel2AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Wheel2AbstractType_obj, PortMap_get_Wheel2AbstractType);

STATIC mp_obj_t PortMap_get_Wheel2SerialInt(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Wheel2SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Wheel2SerialInt_obj, PortMap_get_Wheel2SerialInt);

STATIC mp_obj_t PortMap_get_Wheel2Address(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Wheel2Address);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Wheel2Address_obj, PortMap_get_Wheel2Address);

STATIC mp_obj_t PortMap_get_Wheel3NodeType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eWheel3NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Wheel3NodeType_obj, PortMap_get_Wheel3NodeType);

STATIC mp_obj_t PortMap_get_Wheel3AbstractType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eWheel3AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Wheel3AbstractType_obj, PortMap_get_Wheel3AbstractType);

STATIC mp_obj_t PortMap_get_Wheel3SerialInt(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Wheel3SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Wheel3SerialInt_obj, PortMap_get_Wheel3SerialInt);

STATIC mp_obj_t PortMap_get_Wheel3Address(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Wheel3Address);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Wheel3Address_obj, PortMap_get_Wheel3Address);

STATIC mp_obj_t PortMap_get_Wheel4NodeType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eWheel4NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Wheel4NodeType_obj, PortMap_get_Wheel4NodeType);

STATIC mp_obj_t PortMap_get_Wheel4AbstractType(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eWheel4AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Wheel4AbstractType_obj, PortMap_get_Wheel4AbstractType);

STATIC mp_obj_t PortMap_get_Wheel4SerialInt(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Wheel4SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Wheel4SerialInt_obj, PortMap_get_Wheel4SerialInt);

STATIC mp_obj_t PortMap_get_Wheel4Address(mp_obj_t self_in) 
{
    const PortMap_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Wheel4Address);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_get_Wheel4Address_obj, PortMap_get_Wheel4Address);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t PortMap_locals_dict_table[48] = {
    { MP_ROM_QSTR(MP_QSTR_get_Sensor1NodeType), MP_ROM_PTR(&PortMap_get_Sensor1NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor1AbstractType), MP_ROM_PTR(&PortMap_get_Sensor1AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor1SerialInt), MP_ROM_PTR(&PortMap_get_Sensor1SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor1Address), MP_ROM_PTR(&PortMap_get_Sensor1Address_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor2NodeType), MP_ROM_PTR(&PortMap_get_Sensor2NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor2AbstractType), MP_ROM_PTR(&PortMap_get_Sensor2AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor2SerialInt), MP_ROM_PTR(&PortMap_get_Sensor2SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor2Address), MP_ROM_PTR(&PortMap_get_Sensor2Address_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor3NodeType), MP_ROM_PTR(&PortMap_get_Sensor3NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor3AbstractType), MP_ROM_PTR(&PortMap_get_Sensor3AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor3SerialInt), MP_ROM_PTR(&PortMap_get_Sensor3SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor3Address), MP_ROM_PTR(&PortMap_get_Sensor3Address_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor4NodeType), MP_ROM_PTR(&PortMap_get_Sensor4NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor4AbstractType), MP_ROM_PTR(&PortMap_get_Sensor4AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor4SerialInt), MP_ROM_PTR(&PortMap_get_Sensor4SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor4Address), MP_ROM_PTR(&PortMap_get_Sensor4Address_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor5NodeType), MP_ROM_PTR(&PortMap_get_Sensor5NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor5AbstractType), MP_ROM_PTR(&PortMap_get_Sensor5AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor5SerialInt), MP_ROM_PTR(&PortMap_get_Sensor5SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor5Address), MP_ROM_PTR(&PortMap_get_Sensor5Address_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor6NodeType), MP_ROM_PTR(&PortMap_get_Sensor6NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor6AbstractType), MP_ROM_PTR(&PortMap_get_Sensor6AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor6SerialInt), MP_ROM_PTR(&PortMap_get_Sensor6SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor6Address), MP_ROM_PTR(&PortMap_get_Sensor6Address_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor7NodeType), MP_ROM_PTR(&PortMap_get_Sensor7NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor7AbstractType), MP_ROM_PTR(&PortMap_get_Sensor7AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor7SerialInt), MP_ROM_PTR(&PortMap_get_Sensor7SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor7Address), MP_ROM_PTR(&PortMap_get_Sensor7Address_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor8NodeType), MP_ROM_PTR(&PortMap_get_Sensor8NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor8AbstractType), MP_ROM_PTR(&PortMap_get_Sensor8AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor8SerialInt), MP_ROM_PTR(&PortMap_get_Sensor8SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Sensor8Address), MP_ROM_PTR(&PortMap_get_Sensor8Address_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel1NodeType), MP_ROM_PTR(&PortMap_get_Wheel1NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel1AbstractType), MP_ROM_PTR(&PortMap_get_Wheel1AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel1SerialInt), MP_ROM_PTR(&PortMap_get_Wheel1SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel1Address), MP_ROM_PTR(&PortMap_get_Wheel1Address_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel2NodeType), MP_ROM_PTR(&PortMap_get_Wheel2NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel2AbstractType), MP_ROM_PTR(&PortMap_get_Wheel2AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel2SerialInt), MP_ROM_PTR(&PortMap_get_Wheel2SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel2Address), MP_ROM_PTR(&PortMap_get_Wheel2Address_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel3NodeType), MP_ROM_PTR(&PortMap_get_Wheel3NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel3AbstractType), MP_ROM_PTR(&PortMap_get_Wheel3AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel3SerialInt), MP_ROM_PTR(&PortMap_get_Wheel3SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel3Address), MP_ROM_PTR(&PortMap_get_Wheel3Address_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel4NodeType), MP_ROM_PTR(&PortMap_get_Wheel4NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel4AbstractType), MP_ROM_PTR(&PortMap_get_Wheel4AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel4SerialInt), MP_ROM_PTR(&PortMap_get_Wheel4SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Wheel4Address), MP_ROM_PTR(&PortMap_get_Wheel4Address_obj) },
};

STATIC MP_DEFINE_CONST_DICT(PortMap_locals_dict, PortMap_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    PortMap_type,
    MP_QSTR_PortMap,
    MP_TYPE_FLAG_NONE,
    make_new, PortMap_make_new,
    locals_dict, (mp_obj_dict_t*)&PortMap_locals_dict
);

STATIC mp_obj_t PortMap_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PortMap_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    PortMap_class_obj_t *p_self = m_new_obj(PortMap_class_obj_t);
    p_self->base.type = &PortMap_type;
    
    const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PortMap_t *p_data = (const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PortMap_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// PortMap class constructor from a byte buffer
STATIC mp_obj_t PortMap_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return PortMap_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PortMap_t, PortMap_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PortMap_t, PortMap_class_obj_t, PortMap)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PortMap_make_from_buf_obj, PortMap_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'ImageFileInfo'
 *
 **********************************************************************/
    
// class structure for type ImageFileInfo
typedef struct 
{
    mp_obj_base_t base;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageFileInfo_t class_data;
} PACKED_STRUCT ImageFileInfo_class_obj_t;

// ImageFileInfo class constructor from field arguments
STATIC mp_obj_t ImageFileInfo_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 7, 7, false);
    
    ImageFileInfo_class_obj_t *p_self = m_new_obj(ImageFileInfo_class_obj_t);
    p_self->base.type = type;
    
    // FileHandle
    p_self->class_data.u32FileHandle = (uint32_t) mp_obj_get_int(p_args[0]);
    // NodeType
    p_self->class_data.eNodeType = (uint8_t) mp_obj_get_int(p_args[1]);
    // Timestamp
    p_self->class_data.u32Timestamp = (uint32_t) mp_obj_get_int(p_args[2]);
    // Size
    p_self->class_data.u32Size = (uint32_t) mp_obj_get_int(p_args[3]);
    // First
    p_self->class_data.bFirst = (bool) mp_obj_get_int(p_args[4]);
    // Last
    p_self->class_data.bLast = (bool) mp_obj_get_int(p_args[5]);
    // IsValid
    p_self->class_data.bIsValid = (bool) mp_obj_get_int(p_args[6]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'ImageFileInfo' getters
//

STATIC mp_obj_t ImageFileInfo_get_FileHandle(mp_obj_t self_in) 
{
    const ImageFileInfo_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32FileHandle);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageFileInfo_get_FileHandle_obj, ImageFileInfo_get_FileHandle);

STATIC mp_obj_t ImageFileInfo_get_NodeType(mp_obj_t self_in) 
{
    const ImageFileInfo_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eNodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageFileInfo_get_NodeType_obj, ImageFileInfo_get_NodeType);

STATIC mp_obj_t ImageFileInfo_get_Timestamp(mp_obj_t self_in) 
{
    const ImageFileInfo_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Timestamp);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageFileInfo_get_Timestamp_obj, ImageFileInfo_get_Timestamp);

STATIC mp_obj_t ImageFileInfo_get_Size(mp_obj_t self_in) 
{
    const ImageFileInfo_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Size);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageFileInfo_get_Size_obj, ImageFileInfo_get_Size);

STATIC mp_obj_t ImageFileInfo_get_First(mp_obj_t self_in) 
{
    const ImageFileInfo_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bFirst);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageFileInfo_get_First_obj, ImageFileInfo_get_First);

STATIC mp_obj_t ImageFileInfo_get_Last(mp_obj_t self_in) 
{
    const ImageFileInfo_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bLast);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageFileInfo_get_Last_obj, ImageFileInfo_get_Last);

STATIC mp_obj_t ImageFileInfo_get_IsValid(mp_obj_t self_in) 
{
    const ImageFileInfo_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bIsValid);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageFileInfo_get_IsValid_obj, ImageFileInfo_get_IsValid);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t ImageFileInfo_locals_dict_table[7] = {
    { MP_ROM_QSTR(MP_QSTR_get_FileHandle), MP_ROM_PTR(&ImageFileInfo_get_FileHandle_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_NodeType), MP_ROM_PTR(&ImageFileInfo_get_NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Timestamp), MP_ROM_PTR(&ImageFileInfo_get_Timestamp_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Size), MP_ROM_PTR(&ImageFileInfo_get_Size_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_First), MP_ROM_PTR(&ImageFileInfo_get_First_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Last), MP_ROM_PTR(&ImageFileInfo_get_Last_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_IsValid), MP_ROM_PTR(&ImageFileInfo_get_IsValid_obj) },
};

STATIC MP_DEFINE_CONST_DICT(ImageFileInfo_locals_dict, ImageFileInfo_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    ImageFileInfo_type,
    MP_QSTR_ImageFileInfo,
    MP_TYPE_FLAG_NONE,
    make_new, ImageFileInfo_make_new,
    locals_dict, (mp_obj_dict_t*)&ImageFileInfo_locals_dict
);

STATIC mp_obj_t ImageFileInfo_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageFileInfo_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    ImageFileInfo_class_obj_t *p_self = m_new_obj(ImageFileInfo_class_obj_t);
    p_self->base.type = &ImageFileInfo_type;
    
    const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageFileInfo_t *p_data = (const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageFileInfo_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// ImageFileInfo class constructor from a byte buffer
STATIC mp_obj_t ImageFileInfo_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return ImageFileInfo_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageFileInfo_t, ImageFileInfo_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageFileInfo_t, ImageFileInfo_class_obj_t, ImageFileInfo)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageFileInfo_make_from_buf_obj, ImageFileInfo_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'ImageTransferSetup'
 *
 **********************************************************************/
    
// class structure for type ImageTransferSetup
typedef struct 
{
    mp_obj_base_t base;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageTransferSetup_t class_data;
} PACKED_STRUCT ImageTransferSetup_class_obj_t;

// ImageTransferSetup class constructor from field arguments
STATIC mp_obj_t ImageTransferSetup_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 3, 3, false);
    
    ImageTransferSetup_class_obj_t *p_self = m_new_obj(ImageTransferSetup_class_obj_t);
    p_self->base.type = type;
    
    // OpCode
    p_self->class_data.eOpCode = (uint8_t) mp_obj_get_int(p_args[0]);
    // NodeType
    p_self->class_data.eNodeType = (uint8_t) mp_obj_get_int(p_args[1]);
    // FileHandle
    p_self->class_data.u32FileHandle = (uint32_t) mp_obj_get_int(p_args[2]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'ImageTransferSetup' getters
//

STATIC mp_obj_t ImageTransferSetup_get_OpCode(mp_obj_t self_in) 
{
    const ImageTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eOpCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageTransferSetup_get_OpCode_obj, ImageTransferSetup_get_OpCode);

STATIC mp_obj_t ImageTransferSetup_get_NodeType(mp_obj_t self_in) 
{
    const ImageTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eNodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageTransferSetup_get_NodeType_obj, ImageTransferSetup_get_NodeType);

STATIC mp_obj_t ImageTransferSetup_get_FileHandle(mp_obj_t self_in) 
{
    const ImageTransferSetup_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32FileHandle);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageTransferSetup_get_FileHandle_obj, ImageTransferSetup_get_FileHandle);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t ImageTransferSetup_locals_dict_table[3] = {
    { MP_ROM_QSTR(MP_QSTR_get_OpCode), MP_ROM_PTR(&ImageTransferSetup_get_OpCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_NodeType), MP_ROM_PTR(&ImageTransferSetup_get_NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_FileHandle), MP_ROM_PTR(&ImageTransferSetup_get_FileHandle_obj) },
};

STATIC MP_DEFINE_CONST_DICT(ImageTransferSetup_locals_dict, ImageTransferSetup_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    ImageTransferSetup_type,
    MP_QSTR_ImageTransferSetup,
    MP_TYPE_FLAG_NONE,
    make_new, ImageTransferSetup_make_new,
    locals_dict, (mp_obj_dict_t*)&ImageTransferSetup_locals_dict
);

STATIC mp_obj_t ImageTransferSetup_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageTransferSetup_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    ImageTransferSetup_class_obj_t *p_self = m_new_obj(ImageTransferSetup_class_obj_t);
    p_self->base.type = &ImageTransferSetup_type;
    
    const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageTransferSetup_t *p_data = (const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageTransferSetup_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// ImageTransferSetup class constructor from a byte buffer
STATIC mp_obj_t ImageTransferSetup_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return ImageTransferSetup_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageTransferSetup_t, ImageTransferSetup_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageTransferSetup_t, ImageTransferSetup_class_obj_t, ImageTransferSetup)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageTransferSetup_make_from_buf_obj, ImageTransferSetup_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'PassThrough'
 *
 **********************************************************************/
    
// class structure for type PassThrough
typedef struct 
{
    mp_obj_base_t base;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PassThrough_t class_data;
} PACKED_STRUCT PassThrough_class_obj_t;

// PassThrough class constructor from field arguments
STATIC mp_obj_t PassThrough_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    PassThrough_class_obj_t *p_self = m_new_obj(PassThrough_class_obj_t);
    p_self->base.type = type;
    
    // TargetNode
    p_self->class_data.eTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'PassThrough' getters
//

STATIC mp_obj_t PassThrough_get_TargetNode(mp_obj_t self_in) 
{
    const PassThrough_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eTargetNode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PassThrough_get_TargetNode_obj, PassThrough_get_TargetNode);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t PassThrough_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_TargetNode), MP_ROM_PTR(&PassThrough_get_TargetNode_obj) },
};

STATIC MP_DEFINE_CONST_DICT(PassThrough_locals_dict, PassThrough_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    PassThrough_type,
    MP_QSTR_PassThrough,
    MP_TYPE_FLAG_NONE,
    make_new, PassThrough_make_new,
    locals_dict, (mp_obj_dict_t*)&PassThrough_locals_dict
);

STATIC mp_obj_t PassThrough_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PassThrough_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    PassThrough_class_obj_t *p_self = m_new_obj(PassThrough_class_obj_t);
    p_self->base.type = &PassThrough_type;
    
    const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PassThrough_t *p_data = (const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PassThrough_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// PassThrough class constructor from a byte buffer
STATIC mp_obj_t PassThrough_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return PassThrough_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PassThrough_t, PassThrough_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PassThrough_t, PassThrough_class_obj_t, PassThrough)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(PassThrough_make_from_buf_obj, PassThrough_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'DummyEvent'
 *
 **********************************************************************/
    
// class structure for type DummyEvent
typedef struct 
{
    mp_obj_base_t base;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_DummyEvent_t class_data;
} PACKED_STRUCT DummyEvent_class_obj_t;

// DummyEvent class constructor from field arguments
STATIC mp_obj_t DummyEvent_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 4, 4, false);
    
    DummyEvent_class_obj_t *p_self = m_new_obj(DummyEvent_class_obj_t);
    p_self->base.type = type;
    
    // eventClass
    p_self->class_data.eEventClass = (uint8_t) mp_obj_get_int(p_args[0]);
    // eventSource
    p_self->class_data.eEventSource = (uint8_t) mp_obj_get_int(p_args[1]);
    // eventType
    p_self->class_data.u16EventType = (uint16_t) mp_obj_get_int(p_args[2]);
    // eventData
    upy_sd_copy_fidl_scalar_array_from_py_list_uint8_t(p_self->class_data.au8EventData, 8, p_args[3]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'DummyEvent' getters
//

STATIC mp_obj_t DummyEvent_get_eventClass(mp_obj_t self_in) 
{
    const DummyEvent_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eEventClass);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(DummyEvent_get_eventClass_obj, DummyEvent_get_eventClass);

STATIC mp_obj_t DummyEvent_get_eventSource(mp_obj_t self_in) 
{
    const DummyEvent_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eEventSource);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(DummyEvent_get_eventSource_obj, DummyEvent_get_eventSource);

STATIC mp_obj_t DummyEvent_get_eventType(mp_obj_t self_in) 
{
    const DummyEvent_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16EventType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(DummyEvent_get_eventType_obj, DummyEvent_get_eventType);

STATIC mp_obj_t DummyEvent_get_eventData(mp_obj_t self_in) 
{
    const DummyEvent_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return upy_sd_copy_fidl_scalar_array_to_py_list_uint8_t(p_self->class_data.au8EventData, 8);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(DummyEvent_get_eventData_obj, DummyEvent_get_eventData);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t DummyEvent_locals_dict_table[4] = {
    { MP_ROM_QSTR(MP_QSTR_get_eventClass), MP_ROM_PTR(&DummyEvent_get_eventClass_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_eventSource), MP_ROM_PTR(&DummyEvent_get_eventSource_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_eventType), MP_ROM_PTR(&DummyEvent_get_eventType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_eventData), MP_ROM_PTR(&DummyEvent_get_eventData_obj) },
};

STATIC MP_DEFINE_CONST_DICT(DummyEvent_locals_dict, DummyEvent_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    DummyEvent_type,
    MP_QSTR_DummyEvent,
    MP_TYPE_FLAG_NONE,
    make_new, DummyEvent_make_new,
    locals_dict, (mp_obj_dict_t*)&DummyEvent_locals_dict
);

STATIC mp_obj_t DummyEvent_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_DummyEvent_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    DummyEvent_class_obj_t *p_self = m_new_obj(DummyEvent_class_obj_t);
    p_self->base.type = &DummyEvent_type;
    
    const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_DummyEvent_t *p_data = (const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_DummyEvent_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// DummyEvent class constructor from a byte buffer
STATIC mp_obj_t DummyEvent_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return DummyEvent_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_DummyEvent_t, DummyEvent_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_DummyEvent_t, DummyEvent_class_obj_t, DummyEvent)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(DummyEvent_make_from_buf_obj, DummyEvent_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'ExpectedNodes'
 *
 **********************************************************************/
    
// class structure for type ExpectedNodes
typedef struct 
{
    mp_obj_base_t base;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ExpectedNodes_t class_data;
} PACKED_STRUCT ExpectedNodes_class_obj_t;

// ExpectedNodes class constructor from field arguments
STATIC mp_obj_t ExpectedNodes_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 36, 36, false);
    
    ExpectedNodes_class_obj_t *p_self = m_new_obj(ExpectedNodes_class_obj_t);
    p_self->base.type = type;
    
    // Expected0NodeType
    p_self->class_data.eExpected0NodeType = (uint8_t) mp_obj_get_int(p_args[0]);
    // Expected0AbstractType
    p_self->class_data.eExpected0AbstractType = (uint8_t) mp_obj_get_int(p_args[1]);
    // Expected0SerialInt
    p_self->class_data.u32Expected0SerialInt = (uint32_t) mp_obj_get_int(p_args[2]);
    // Expected1NodeType
    p_self->class_data.eExpected1NodeType = (uint8_t) mp_obj_get_int(p_args[3]);
    // Expected1AbstractType
    p_self->class_data.eExpected1AbstractType = (uint8_t) mp_obj_get_int(p_args[4]);
    // Expected1SerialInt
    p_self->class_data.u32Expected1SerialInt = (uint32_t) mp_obj_get_int(p_args[5]);
    // Expected2NodeType
    p_self->class_data.eExpected2NodeType = (uint8_t) mp_obj_get_int(p_args[6]);
    // Expected2AbstractType
    p_self->class_data.eExpected2AbstractType = (uint8_t) mp_obj_get_int(p_args[7]);
    // Expected2SerialInt
    p_self->class_data.u32Expected2SerialInt = (uint32_t) mp_obj_get_int(p_args[8]);
    // Expected3NodeType
    p_self->class_data.eExpected3NodeType = (uint8_t) mp_obj_get_int(p_args[9]);
    // Expected3AbstractType
    p_self->class_data.eExpected3AbstractType = (uint8_t) mp_obj_get_int(p_args[10]);
    // Expected3SerialInt
    p_self->class_data.u32Expected3SerialInt = (uint32_t) mp_obj_get_int(p_args[11]);
    // Expected4NodeType
    p_self->class_data.eExpected4NodeType = (uint8_t) mp_obj_get_int(p_args[12]);
    // Expected4AbstractType
    p_self->class_data.eExpected4AbstractType = (uint8_t) mp_obj_get_int(p_args[13]);
    // Expected4SerialInt
    p_self->class_data.u32Expected4SerialInt = (uint32_t) mp_obj_get_int(p_args[14]);
    // Expected5NodeType
    p_self->class_data.eExpected5NodeType = (uint8_t) mp_obj_get_int(p_args[15]);
    // Expected5AbstractType
    p_self->class_data.eExpected5AbstractType = (uint8_t) mp_obj_get_int(p_args[16]);
    // Expected5SerialInt
    p_self->class_data.u32Expected5SerialInt = (uint32_t) mp_obj_get_int(p_args[17]);
    // Expected6NodeType
    p_self->class_data.eExpected6NodeType = (uint8_t) mp_obj_get_int(p_args[18]);
    // Expected6AbstractType
    p_self->class_data.eExpected6AbstractType = (uint8_t) mp_obj_get_int(p_args[19]);
    // Expected6SerialInt
    p_self->class_data.u32Expected6SerialInt = (uint32_t) mp_obj_get_int(p_args[20]);
    // Expected7NodeType
    p_self->class_data.eExpected7NodeType = (uint8_t) mp_obj_get_int(p_args[21]);
    // Expected7AbstractType
    p_self->class_data.eExpected7AbstractType = (uint8_t) mp_obj_get_int(p_args[22]);
    // Expected7SerialInt
    p_self->class_data.u32Expected7SerialInt = (uint32_t) mp_obj_get_int(p_args[23]);
    // Expected8NodeType
    p_self->class_data.eExpected8NodeType = (uint8_t) mp_obj_get_int(p_args[24]);
    // Expected8AbstractType
    p_self->class_data.eExpected8AbstractType = (uint8_t) mp_obj_get_int(p_args[25]);
    // Expected8SerialInt
    p_self->class_data.u32Expected8SerialInt = (uint32_t) mp_obj_get_int(p_args[26]);
    // Expected9NodeType
    p_self->class_data.eExpected9NodeType = (uint8_t) mp_obj_get_int(p_args[27]);
    // Expected9AbstractType
    p_self->class_data.eExpected9AbstractType = (uint8_t) mp_obj_get_int(p_args[28]);
    // Expected9SerialInt
    p_self->class_data.u32Expected9SerialInt = (uint32_t) mp_obj_get_int(p_args[29]);
    // Expected10NodeType
    p_self->class_data.eExpected10NodeType = (uint8_t) mp_obj_get_int(p_args[30]);
    // Expected10AbstractType
    p_self->class_data.eExpected10AbstractType = (uint8_t) mp_obj_get_int(p_args[31]);
    // Expected10SerialInt
    p_self->class_data.u32Expected10SerialInt = (uint32_t) mp_obj_get_int(p_args[32]);
    // Expected11NodeType
    p_self->class_data.eExpected11NodeType = (uint8_t) mp_obj_get_int(p_args[33]);
    // Expected11AbstractType
    p_self->class_data.eExpected11AbstractType = (uint8_t) mp_obj_get_int(p_args[34]);
    // Expected11SerialInt
    p_self->class_data.u32Expected11SerialInt = (uint32_t) mp_obj_get_int(p_args[35]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'ExpectedNodes' getters
//

STATIC mp_obj_t ExpectedNodes_get_Expected0NodeType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected0NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected0NodeType_obj, ExpectedNodes_get_Expected0NodeType);

STATIC mp_obj_t ExpectedNodes_get_Expected0AbstractType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected0AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected0AbstractType_obj, ExpectedNodes_get_Expected0AbstractType);

STATIC mp_obj_t ExpectedNodes_get_Expected0SerialInt(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Expected0SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected0SerialInt_obj, ExpectedNodes_get_Expected0SerialInt);

STATIC mp_obj_t ExpectedNodes_get_Expected1NodeType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected1NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected1NodeType_obj, ExpectedNodes_get_Expected1NodeType);

STATIC mp_obj_t ExpectedNodes_get_Expected1AbstractType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected1AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected1AbstractType_obj, ExpectedNodes_get_Expected1AbstractType);

STATIC mp_obj_t ExpectedNodes_get_Expected1SerialInt(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Expected1SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected1SerialInt_obj, ExpectedNodes_get_Expected1SerialInt);

STATIC mp_obj_t ExpectedNodes_get_Expected2NodeType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected2NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected2NodeType_obj, ExpectedNodes_get_Expected2NodeType);

STATIC mp_obj_t ExpectedNodes_get_Expected2AbstractType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected2AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected2AbstractType_obj, ExpectedNodes_get_Expected2AbstractType);

STATIC mp_obj_t ExpectedNodes_get_Expected2SerialInt(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Expected2SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected2SerialInt_obj, ExpectedNodes_get_Expected2SerialInt);

STATIC mp_obj_t ExpectedNodes_get_Expected3NodeType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected3NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected3NodeType_obj, ExpectedNodes_get_Expected3NodeType);

STATIC mp_obj_t ExpectedNodes_get_Expected3AbstractType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected3AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected3AbstractType_obj, ExpectedNodes_get_Expected3AbstractType);

STATIC mp_obj_t ExpectedNodes_get_Expected3SerialInt(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Expected3SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected3SerialInt_obj, ExpectedNodes_get_Expected3SerialInt);

STATIC mp_obj_t ExpectedNodes_get_Expected4NodeType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected4NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected4NodeType_obj, ExpectedNodes_get_Expected4NodeType);

STATIC mp_obj_t ExpectedNodes_get_Expected4AbstractType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected4AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected4AbstractType_obj, ExpectedNodes_get_Expected4AbstractType);

STATIC mp_obj_t ExpectedNodes_get_Expected4SerialInt(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Expected4SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected4SerialInt_obj, ExpectedNodes_get_Expected4SerialInt);

STATIC mp_obj_t ExpectedNodes_get_Expected5NodeType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected5NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected5NodeType_obj, ExpectedNodes_get_Expected5NodeType);

STATIC mp_obj_t ExpectedNodes_get_Expected5AbstractType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected5AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected5AbstractType_obj, ExpectedNodes_get_Expected5AbstractType);

STATIC mp_obj_t ExpectedNodes_get_Expected5SerialInt(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Expected5SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected5SerialInt_obj, ExpectedNodes_get_Expected5SerialInt);

STATIC mp_obj_t ExpectedNodes_get_Expected6NodeType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected6NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected6NodeType_obj, ExpectedNodes_get_Expected6NodeType);

STATIC mp_obj_t ExpectedNodes_get_Expected6AbstractType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected6AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected6AbstractType_obj, ExpectedNodes_get_Expected6AbstractType);

STATIC mp_obj_t ExpectedNodes_get_Expected6SerialInt(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Expected6SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected6SerialInt_obj, ExpectedNodes_get_Expected6SerialInt);

STATIC mp_obj_t ExpectedNodes_get_Expected7NodeType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected7NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected7NodeType_obj, ExpectedNodes_get_Expected7NodeType);

STATIC mp_obj_t ExpectedNodes_get_Expected7AbstractType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected7AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected7AbstractType_obj, ExpectedNodes_get_Expected7AbstractType);

STATIC mp_obj_t ExpectedNodes_get_Expected7SerialInt(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Expected7SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected7SerialInt_obj, ExpectedNodes_get_Expected7SerialInt);

STATIC mp_obj_t ExpectedNodes_get_Expected8NodeType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected8NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected8NodeType_obj, ExpectedNodes_get_Expected8NodeType);

STATIC mp_obj_t ExpectedNodes_get_Expected8AbstractType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected8AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected8AbstractType_obj, ExpectedNodes_get_Expected8AbstractType);

STATIC mp_obj_t ExpectedNodes_get_Expected8SerialInt(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Expected8SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected8SerialInt_obj, ExpectedNodes_get_Expected8SerialInt);

STATIC mp_obj_t ExpectedNodes_get_Expected9NodeType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected9NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected9NodeType_obj, ExpectedNodes_get_Expected9NodeType);

STATIC mp_obj_t ExpectedNodes_get_Expected9AbstractType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected9AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected9AbstractType_obj, ExpectedNodes_get_Expected9AbstractType);

STATIC mp_obj_t ExpectedNodes_get_Expected9SerialInt(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Expected9SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected9SerialInt_obj, ExpectedNodes_get_Expected9SerialInt);

STATIC mp_obj_t ExpectedNodes_get_Expected10NodeType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected10NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected10NodeType_obj, ExpectedNodes_get_Expected10NodeType);

STATIC mp_obj_t ExpectedNodes_get_Expected10AbstractType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected10AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected10AbstractType_obj, ExpectedNodes_get_Expected10AbstractType);

STATIC mp_obj_t ExpectedNodes_get_Expected10SerialInt(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Expected10SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected10SerialInt_obj, ExpectedNodes_get_Expected10SerialInt);

STATIC mp_obj_t ExpectedNodes_get_Expected11NodeType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected11NodeType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected11NodeType_obj, ExpectedNodes_get_Expected11NodeType);

STATIC mp_obj_t ExpectedNodes_get_Expected11AbstractType(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eExpected11AbstractType);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected11AbstractType_obj, ExpectedNodes_get_Expected11AbstractType);

STATIC mp_obj_t ExpectedNodes_get_Expected11SerialInt(mp_obj_t self_in) 
{
    const ExpectedNodes_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32Expected11SerialInt);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_get_Expected11SerialInt_obj, ExpectedNodes_get_Expected11SerialInt);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t ExpectedNodes_locals_dict_table[36] = {
    { MP_ROM_QSTR(MP_QSTR_get_Expected0NodeType), MP_ROM_PTR(&ExpectedNodes_get_Expected0NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected0AbstractType), MP_ROM_PTR(&ExpectedNodes_get_Expected0AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected0SerialInt), MP_ROM_PTR(&ExpectedNodes_get_Expected0SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected1NodeType), MP_ROM_PTR(&ExpectedNodes_get_Expected1NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected1AbstractType), MP_ROM_PTR(&ExpectedNodes_get_Expected1AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected1SerialInt), MP_ROM_PTR(&ExpectedNodes_get_Expected1SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected2NodeType), MP_ROM_PTR(&ExpectedNodes_get_Expected2NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected2AbstractType), MP_ROM_PTR(&ExpectedNodes_get_Expected2AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected2SerialInt), MP_ROM_PTR(&ExpectedNodes_get_Expected2SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected3NodeType), MP_ROM_PTR(&ExpectedNodes_get_Expected3NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected3AbstractType), MP_ROM_PTR(&ExpectedNodes_get_Expected3AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected3SerialInt), MP_ROM_PTR(&ExpectedNodes_get_Expected3SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected4NodeType), MP_ROM_PTR(&ExpectedNodes_get_Expected4NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected4AbstractType), MP_ROM_PTR(&ExpectedNodes_get_Expected4AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected4SerialInt), MP_ROM_PTR(&ExpectedNodes_get_Expected4SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected5NodeType), MP_ROM_PTR(&ExpectedNodes_get_Expected5NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected5AbstractType), MP_ROM_PTR(&ExpectedNodes_get_Expected5AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected5SerialInt), MP_ROM_PTR(&ExpectedNodes_get_Expected5SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected6NodeType), MP_ROM_PTR(&ExpectedNodes_get_Expected6NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected6AbstractType), MP_ROM_PTR(&ExpectedNodes_get_Expected6AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected6SerialInt), MP_ROM_PTR(&ExpectedNodes_get_Expected6SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected7NodeType), MP_ROM_PTR(&ExpectedNodes_get_Expected7NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected7AbstractType), MP_ROM_PTR(&ExpectedNodes_get_Expected7AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected7SerialInt), MP_ROM_PTR(&ExpectedNodes_get_Expected7SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected8NodeType), MP_ROM_PTR(&ExpectedNodes_get_Expected8NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected8AbstractType), MP_ROM_PTR(&ExpectedNodes_get_Expected8AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected8SerialInt), MP_ROM_PTR(&ExpectedNodes_get_Expected8SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected9NodeType), MP_ROM_PTR(&ExpectedNodes_get_Expected9NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected9AbstractType), MP_ROM_PTR(&ExpectedNodes_get_Expected9AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected9SerialInt), MP_ROM_PTR(&ExpectedNodes_get_Expected9SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected10NodeType), MP_ROM_PTR(&ExpectedNodes_get_Expected10NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected10AbstractType), MP_ROM_PTR(&ExpectedNodes_get_Expected10AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected10SerialInt), MP_ROM_PTR(&ExpectedNodes_get_Expected10SerialInt_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected11NodeType), MP_ROM_PTR(&ExpectedNodes_get_Expected11NodeType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected11AbstractType), MP_ROM_PTR(&ExpectedNodes_get_Expected11AbstractType_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_Expected11SerialInt), MP_ROM_PTR(&ExpectedNodes_get_Expected11SerialInt_obj) },
};

STATIC MP_DEFINE_CONST_DICT(ExpectedNodes_locals_dict, ExpectedNodes_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    ExpectedNodes_type,
    MP_QSTR_ExpectedNodes,
    MP_TYPE_FLAG_NONE,
    make_new, ExpectedNodes_make_new,
    locals_dict, (mp_obj_dict_t*)&ExpectedNodes_locals_dict
);

STATIC mp_obj_t ExpectedNodes_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ExpectedNodes_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    ExpectedNodes_class_obj_t *p_self = m_new_obj(ExpectedNodes_class_obj_t);
    p_self->base.type = &ExpectedNodes_type;
    
    const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ExpectedNodes_t *p_data = (const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ExpectedNodes_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// ExpectedNodes class constructor from a byte buffer
STATIC mp_obj_t ExpectedNodes_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return ExpectedNodes_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ExpectedNodes_t, ExpectedNodes_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ExpectedNodes_t, ExpectedNodes_class_obj_t, ExpectedNodes)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ExpectedNodes_make_from_buf_obj, ExpectedNodes_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'ImageTransferStatus'
 *
 **********************************************************************/
    
// class structure for type ImageTransferStatus
typedef struct 
{
    mp_obj_base_t base;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageTransferStatus_t class_data;
} PACKED_STRUCT ImageTransferStatus_class_obj_t;

// ImageTransferStatus class constructor from field arguments
STATIC mp_obj_t ImageTransferStatus_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 13, 13, false);
    
    ImageTransferStatus_class_obj_t *p_self = m_new_obj(ImageTransferStatus_class_obj_t);
    p_self->base.type = type;
    
    // State
    p_self->class_data.eState = (uint8_t) mp_obj_get_int(p_args[0]);
    // ErrorCode
    p_self->class_data.u32ErrorCode = (uint32_t) mp_obj_get_int(p_args[1]);
    // TransferSize
    p_self->class_data.u32TransferSize = (uint32_t) mp_obj_get_int(p_args[2]);
    // DataRemain
    p_self->class_data.u32DataRemain = (uint32_t) mp_obj_get_int(p_args[3]);
    // InvalidNodeError
    p_self->class_data.bInvalidNodeError = (bool) mp_obj_get_int(p_args[4]);
    // TimeoutError
    p_self->class_data.bTimeoutError = (bool) mp_obj_get_int(p_args[5]);
    // CaptureError
    p_self->class_data.bCaptureError = (bool) mp_obj_get_int(p_args[6]);
    // SetupError
    p_self->class_data.bSetupError = (bool) mp_obj_get_int(p_args[7]);
    // FileOpenReadError
    p_self->class_data.bFileOpenReadError = (bool) mp_obj_get_int(p_args[8]);
    // FileOpenWriteError
    p_self->class_data.bFileOpenWriteError = (bool) mp_obj_get_int(p_args[9]);
    // FileReadError
    p_self->class_data.bFileReadError = (bool) mp_obj_get_int(p_args[10]);
    // FileWriteError
    p_self->class_data.bFileWriteError = (bool) mp_obj_get_int(p_args[11]);
    // BusyError
    p_self->class_data.bBusyError = (bool) mp_obj_get_int(p_args[12]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'ImageTransferStatus' getters
//

STATIC mp_obj_t ImageTransferStatus_get_State(mp_obj_t self_in) 
{
    const ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eState);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageTransferStatus_get_State_obj, ImageTransferStatus_get_State);

STATIC mp_obj_t ImageTransferStatus_get_ErrorCode(mp_obj_t self_in) 
{
    const ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32ErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageTransferStatus_get_ErrorCode_obj, ImageTransferStatus_get_ErrorCode);

STATIC mp_obj_t ImageTransferStatus_get_TransferSize(mp_obj_t self_in) 
{
    const ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32TransferSize);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageTransferStatus_get_TransferSize_obj, ImageTransferStatus_get_TransferSize);

STATIC mp_obj_t ImageTransferStatus_get_DataRemain(mp_obj_t self_in) 
{
    const ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32DataRemain);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageTransferStatus_get_DataRemain_obj, ImageTransferStatus_get_DataRemain);

STATIC mp_obj_t ImageTransferStatus_get_InvalidNodeError(mp_obj_t self_in) 
{
    const ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bInvalidNodeError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageTransferStatus_get_InvalidNodeError_obj, ImageTransferStatus_get_InvalidNodeError);

STATIC mp_obj_t ImageTransferStatus_get_TimeoutError(mp_obj_t self_in) 
{
    const ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bTimeoutError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageTransferStatus_get_TimeoutError_obj, ImageTransferStatus_get_TimeoutError);

STATIC mp_obj_t ImageTransferStatus_get_CaptureError(mp_obj_t self_in) 
{
    const ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bCaptureError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageTransferStatus_get_CaptureError_obj, ImageTransferStatus_get_CaptureError);

STATIC mp_obj_t ImageTransferStatus_get_SetupError(mp_obj_t self_in) 
{
    const ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bSetupError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageTransferStatus_get_SetupError_obj, ImageTransferStatus_get_SetupError);

STATIC mp_obj_t ImageTransferStatus_get_FileOpenReadError(mp_obj_t self_in) 
{
    const ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bFileOpenReadError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageTransferStatus_get_FileOpenReadError_obj, ImageTransferStatus_get_FileOpenReadError);

STATIC mp_obj_t ImageTransferStatus_get_FileOpenWriteError(mp_obj_t self_in) 
{
    const ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bFileOpenWriteError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageTransferStatus_get_FileOpenWriteError_obj, ImageTransferStatus_get_FileOpenWriteError);

STATIC mp_obj_t ImageTransferStatus_get_FileReadError(mp_obj_t self_in) 
{
    const ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bFileReadError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageTransferStatus_get_FileReadError_obj, ImageTransferStatus_get_FileReadError);

STATIC mp_obj_t ImageTransferStatus_get_FileWriteError(mp_obj_t self_in) 
{
    const ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bFileWriteError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageTransferStatus_get_FileWriteError_obj, ImageTransferStatus_get_FileWriteError);

STATIC mp_obj_t ImageTransferStatus_get_BusyError(mp_obj_t self_in) 
{
    const ImageTransferStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.bBusyError);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageTransferStatus_get_BusyError_obj, ImageTransferStatus_get_BusyError);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t ImageTransferStatus_locals_dict_table[13] = {
    { MP_ROM_QSTR(MP_QSTR_get_State), MP_ROM_PTR(&ImageTransferStatus_get_State_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_ErrorCode), MP_ROM_PTR(&ImageTransferStatus_get_ErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_TransferSize), MP_ROM_PTR(&ImageTransferStatus_get_TransferSize_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_DataRemain), MP_ROM_PTR(&ImageTransferStatus_get_DataRemain_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_InvalidNodeError), MP_ROM_PTR(&ImageTransferStatus_get_InvalidNodeError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_TimeoutError), MP_ROM_PTR(&ImageTransferStatus_get_TimeoutError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_CaptureError), MP_ROM_PTR(&ImageTransferStatus_get_CaptureError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_SetupError), MP_ROM_PTR(&ImageTransferStatus_get_SetupError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_FileOpenReadError), MP_ROM_PTR(&ImageTransferStatus_get_FileOpenReadError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_FileOpenWriteError), MP_ROM_PTR(&ImageTransferStatus_get_FileOpenWriteError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_FileReadError), MP_ROM_PTR(&ImageTransferStatus_get_FileReadError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_FileWriteError), MP_ROM_PTR(&ImageTransferStatus_get_FileWriteError_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_BusyError), MP_ROM_PTR(&ImageTransferStatus_get_BusyError_obj) },
};

STATIC MP_DEFINE_CONST_DICT(ImageTransferStatus_locals_dict, ImageTransferStatus_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    ImageTransferStatus_type,
    MP_QSTR_ImageTransferStatus,
    MP_TYPE_FLAG_NONE,
    make_new, ImageTransferStatus_make_new,
    locals_dict, (mp_obj_dict_t*)&ImageTransferStatus_locals_dict
);

STATIC mp_obj_t ImageTransferStatus_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageTransferStatus_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    ImageTransferStatus_class_obj_t *p_self = m_new_obj(ImageTransferStatus_class_obj_t);
    p_self->base.type = &ImageTransferStatus_type;
    
    const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageTransferStatus_t *p_data = (const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageTransferStatus_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// ImageTransferStatus class constructor from a byte buffer
STATIC mp_obj_t ImageTransferStatus_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return ImageTransferStatus_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageTransferStatus_t, ImageTransferStatus_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageTransferStatus_t, ImageTransferStatus_class_obj_t, ImageTransferStatus)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ImageTransferStatus_make_from_buf_obj, ImageTransferStatus_make_from_buf);
/**********************************************************************
 *
 *  uPy class definition for struct 'EventLogStatus'
 *
 **********************************************************************/
    
// class structure for type EventLogStatus
typedef struct 
{
    mp_obj_base_t base;
    CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EventLogStatus_t class_data;
} PACKED_STRUCT EventLogStatus_class_obj_t;

// EventLogStatus class constructor from field arguments
STATIC mp_obj_t EventLogStatus_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 12, 12, false);
    
    EventLogStatus_class_obj_t *p_self = m_new_obj(EventLogStatus_class_obj_t);
    p_self->base.type = type;
    
    // numberOfEntriesQueued
    p_self->class_data.u16NumberOfEntriesQueued = (uint16_t) mp_obj_get_int(p_args[0]);
    // numberOfEntriesBuffered
    p_self->class_data.u16NumberOfEntriesBuffered = (uint16_t) mp_obj_get_int(p_args[1]);
    // numberOfEntries
    p_self->class_data.u32NumberOfEntries = (uint32_t) mp_obj_get_int(p_args[2]);
    // numberOfEmptyEntries
    p_self->class_data.u32NumberOfEmptyEntries = (uint32_t) mp_obj_get_int(p_args[3]);
    // oldestEntryUnix
    p_self->class_data.u32OldestEntryUnix = (uint32_t) mp_obj_get_int(p_args[4]);
    // latestEntryUnix
    p_self->class_data.u32LatestEntryUnix = (uint32_t) mp_obj_get_int(p_args[5]);
    // numberOfCriticalEvents
    p_self->class_data.u32NumberOfCriticalEvents = (uint32_t) mp_obj_get_int(p_args[6]);
    // numberOfMajorWarningEvents
    p_self->class_data.u32NumberOfMajorWarningEvents = (uint32_t) mp_obj_get_int(p_args[7]);
    // numberOfMinorWarningEvents
    p_self->class_data.u32NumberOfMinorWarningEvents = (uint32_t) mp_obj_get_int(p_args[8]);
    // numberOfInfoEvents
    p_self->class_data.u32NumberOfInfoEvents = (uint32_t) mp_obj_get_int(p_args[9]);
    // writeCounter
    p_self->class_data.u32WriteCounter = (uint32_t) mp_obj_get_int(p_args[10]);
    // readQueueState
    p_self->class_data.eReadQueueState = (uint8_t) mp_obj_get_int(p_args[11]);
    
    return MP_OBJ_FROM_PTR(p_self);
}

//    
// struct 'EventLogStatus' getters
//

STATIC mp_obj_t EventLogStatus_get_numberOfEntriesQueued(mp_obj_t self_in) 
{
    const EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16NumberOfEntriesQueued);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogStatus_get_numberOfEntriesQueued_obj, EventLogStatus_get_numberOfEntriesQueued);

STATIC mp_obj_t EventLogStatus_get_numberOfEntriesBuffered(mp_obj_t self_in) 
{
    const EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u16NumberOfEntriesBuffered);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogStatus_get_numberOfEntriesBuffered_obj, EventLogStatus_get_numberOfEntriesBuffered);

STATIC mp_obj_t EventLogStatus_get_numberOfEntries(mp_obj_t self_in) 
{
    const EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32NumberOfEntries);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogStatus_get_numberOfEntries_obj, EventLogStatus_get_numberOfEntries);

STATIC mp_obj_t EventLogStatus_get_numberOfEmptyEntries(mp_obj_t self_in) 
{
    const EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32NumberOfEmptyEntries);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogStatus_get_numberOfEmptyEntries_obj, EventLogStatus_get_numberOfEmptyEntries);

STATIC mp_obj_t EventLogStatus_get_oldestEntryUnix(mp_obj_t self_in) 
{
    const EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32OldestEntryUnix);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogStatus_get_oldestEntryUnix_obj, EventLogStatus_get_oldestEntryUnix);

STATIC mp_obj_t EventLogStatus_get_latestEntryUnix(mp_obj_t self_in) 
{
    const EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32LatestEntryUnix);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogStatus_get_latestEntryUnix_obj, EventLogStatus_get_latestEntryUnix);

STATIC mp_obj_t EventLogStatus_get_numberOfCriticalEvents(mp_obj_t self_in) 
{
    const EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32NumberOfCriticalEvents);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogStatus_get_numberOfCriticalEvents_obj, EventLogStatus_get_numberOfCriticalEvents);

STATIC mp_obj_t EventLogStatus_get_numberOfMajorWarningEvents(mp_obj_t self_in) 
{
    const EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32NumberOfMajorWarningEvents);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogStatus_get_numberOfMajorWarningEvents_obj, EventLogStatus_get_numberOfMajorWarningEvents);

STATIC mp_obj_t EventLogStatus_get_numberOfMinorWarningEvents(mp_obj_t self_in) 
{
    const EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32NumberOfMinorWarningEvents);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogStatus_get_numberOfMinorWarningEvents_obj, EventLogStatus_get_numberOfMinorWarningEvents);

STATIC mp_obj_t EventLogStatus_get_numberOfInfoEvents(mp_obj_t self_in) 
{
    const EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32NumberOfInfoEvents);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogStatus_get_numberOfInfoEvents_obj, EventLogStatus_get_numberOfInfoEvents);

STATIC mp_obj_t EventLogStatus_get_writeCounter(mp_obj_t self_in) 
{
    const EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.u32WriteCounter);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogStatus_get_writeCounter_obj, EventLogStatus_get_writeCounter);

STATIC mp_obj_t EventLogStatus_get_readQueueState(mp_obj_t self_in) 
{
    const EventLogStatus_class_obj_t *p_self = MP_OBJ_TO_PTR(self_in);
    
    return mp_obj_new_int((mp_int_t) p_self->class_data.eReadQueueState);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogStatus_get_readQueueState_obj, EventLogStatus_get_readQueueState);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t EventLogStatus_locals_dict_table[12] = {
    { MP_ROM_QSTR(MP_QSTR_get_numberOfEntriesQueued), MP_ROM_PTR(&EventLogStatus_get_numberOfEntriesQueued_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numberOfEntriesBuffered), MP_ROM_PTR(&EventLogStatus_get_numberOfEntriesBuffered_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numberOfEntries), MP_ROM_PTR(&EventLogStatus_get_numberOfEntries_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numberOfEmptyEntries), MP_ROM_PTR(&EventLogStatus_get_numberOfEmptyEntries_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_oldestEntryUnix), MP_ROM_PTR(&EventLogStatus_get_oldestEntryUnix_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_latestEntryUnix), MP_ROM_PTR(&EventLogStatus_get_latestEntryUnix_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numberOfCriticalEvents), MP_ROM_PTR(&EventLogStatus_get_numberOfCriticalEvents_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numberOfMajorWarningEvents), MP_ROM_PTR(&EventLogStatus_get_numberOfMajorWarningEvents_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numberOfMinorWarningEvents), MP_ROM_PTR(&EventLogStatus_get_numberOfMinorWarningEvents_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_numberOfInfoEvents), MP_ROM_PTR(&EventLogStatus_get_numberOfInfoEvents_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_writeCounter), MP_ROM_PTR(&EventLogStatus_get_writeCounter_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_readQueueState), MP_ROM_PTR(&EventLogStatus_get_readQueueState_obj) },
};

STATIC MP_DEFINE_CONST_DICT(EventLogStatus_locals_dict, EventLogStatus_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    EventLogStatus_type,
    MP_QSTR_EventLogStatus,
    MP_TYPE_FLAG_NONE,
    make_new, EventLogStatus_make_new,
    locals_dict, (mp_obj_dict_t*)&EventLogStatus_locals_dict
);

STATIC mp_obj_t EventLogStatus_make_from_c_buf(const uint8_t *p_buf, const uint32_t buf_size) {
    if (buf_size != sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EventLogStatus_t))
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Buffer size does not match expected type size"));
    }

    EventLogStatus_class_obj_t *p_self = m_new_obj(EventLogStatus_class_obj_t);
    p_self->base.type = &EventLogStatus_type;
    
    const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EventLogStatus_t *p_data = (const CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EventLogStatus_t *) p_buf;

    // perform shallow memory copy
    p_self->class_data = *p_data;

    return MP_OBJ_FROM_PTR(p_self);
}

// EventLogStatus class constructor from a byte buffer
STATIC mp_obj_t EventLogStatus_make_from_buf(mp_obj_t bytes_obj) {
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(bytes_obj, &buf_info, MP_BUFFER_READ))
    {
        return EventLogStatus_make_from_c_buf((const uint8_t *) buf_info.buf, (uint32_t) buf_info.len);
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(NULL);
}

DEF_FUNC_COPY_FIDL_ARRAY_FROM_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EventLogStatus_t, EventLogStatus_class_obj_t)
DEF_FUNC_COPY_FIDL_ARRAY_TO_PY_LIST_STRUCT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EventLogStatus_t, EventLogStatus_class_obj_t, EventLogStatus)

STATIC MP_DEFINE_CONST_FUN_OBJ_1(EventLogStatus_make_from_buf_obj, EventLogStatus_make_from_buf);

/**********************************************************************
 *
 *  Enumeration classes
 *
 **********************************************************************/
//
// Enumeration classes for type 'CubeComputerCommon3_ImageTransferOpCode'
//
STATIC const mp_rom_map_elem_t cubecomputercommon3_imagetransferopcode_locals_dict_table[4] = 
{
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_IMAGETRANSFEROPCODE_CAPTURESTORE), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_IMAGETRANSFEROPCODE_CaptureStore)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_IMAGETRANSFEROPCODE_CAPTUREDOWNLOAD), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_IMAGETRANSFEROPCODE_CaptureDownload)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_IMAGETRANSFEROPCODE_DOWNLOAD), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_IMAGETRANSFEROPCODE_Download)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_IMAGETRANSFEROPCODE_INFORESET), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_IMAGETRANSFEROPCODE_InfoReset)},
};

STATIC MP_DEFINE_CONST_DICT(cubecomputercommon3_imagetransferopcode_class_locals_dict, cubecomputercommon3_imagetransferopcode_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    cubecomputercommon3_imagetransferopcode_class_type,
    MP_QSTR_CubeComputerCommon3_ImageTransferOpCode,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&cubecomputercommon3_imagetransferopcode_class_locals_dict
);
//
// Enumeration classes for type 'CubeComputerCommon3_LogReadFilterType'
//
STATIC const mp_rom_map_elem_t cubecomputercommon3_logreadfiltertype_locals_dict_table[6] = 
{
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FILTERNONE), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FilterNone)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FILTERTIMESPAN), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FilterTimeSpan)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FILTERTIMENEXTX), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FilterTimeNextX)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FILTERFIRSTX), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FilterFirstX)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FILTERLASTX), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FilterLastX)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FILTERCOUNTERNEXTX), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_LOGREADFILTERTYPE_FilterCounterNextX)},
};

STATIC MP_DEFINE_CONST_DICT(cubecomputercommon3_logreadfiltertype_class_locals_dict, cubecomputercommon3_logreadfiltertype_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    cubecomputercommon3_logreadfiltertype_class_type,
    MP_QSTR_CubeComputerCommon3_LogReadFilterType,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&cubecomputercommon3_logreadfiltertype_class_locals_dict
);
//
// Enumeration classes for type 'CubeComputerCommon3_TlmLogReturnIntervalValues'
//
STATIC const mp_rom_map_elem_t cubecomputercommon3_tlmlogreturnintervalvalues_locals_dict_table[10] = 
{
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL200MS), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval200ms)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL1S), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval1s)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL2S), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval2s)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL3S), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval3s)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL4S), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval4s)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL5S), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval5s)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL10S), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval10s)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL20S), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval20s)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL50S), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval50s)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_INTERVAL100S), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGRETURNINTERVALVALUES_interval100s)},
};

STATIC MP_DEFINE_CONST_DICT(cubecomputercommon3_tlmlogreturnintervalvalues_class_locals_dict, cubecomputercommon3_tlmlogreturnintervalvalues_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    cubecomputercommon3_tlmlogreturnintervalvalues_class_type,
    MP_QSTR_CubeComputerCommon3_TlmLogReturnIntervalValues,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&cubecomputercommon3_tlmlogreturnintervalvalues_class_locals_dict
);
//
// Enumeration classes for type 'CubeComputerCommon3_EventClass'
//
STATIC const mp_rom_map_elem_t cubecomputercommon3_eventclass_locals_dict_table[4] = 
{
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_EVENTCLASS_EVENTCLASSINFO), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_EVENTCLASS_EventClassInfo)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_EVENTCLASS_EVENTCLASSWARNINGMINOR), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_EVENTCLASS_EventClassWarningMinor)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_EVENTCLASS_EVENTCLASSWARNINGMAJOR), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_EVENTCLASS_EventClassWarningMajor)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_EVENTCLASS_EVENTCLASSCRITICAL), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_EVENTCLASS_EventClassCritical)},
};

STATIC MP_DEFINE_CONST_DICT(cubecomputercommon3_eventclass_class_locals_dict, cubecomputercommon3_eventclass_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    cubecomputercommon3_eventclass_class_type,
    MP_QSTR_CubeComputerCommon3_EventClass,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&cubecomputercommon3_eventclass_class_locals_dict
);
//
// Enumeration classes for type 'CommonFrameworkTypes1_NodeType'
//
STATIC const mp_rom_map_elem_t commonframeworktypes1_nodetype_locals_dict_table[17] = 
{
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPEINVALID), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeInvalid)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBECOMPUTER), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeComputer)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBESENSE), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeSense)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBEWHEEL), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeWheel)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBEIR), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeIr)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBEMAGDEPLOY), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeMagDeploy)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBEMAGCOMPACT), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeMagCompact)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBESTAR), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeStar)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBEAURIGA), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeAuriga)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBENODE), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeNode)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBENODESLT), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeNodeSlt)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBENODEPST3S), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeNodePst3s)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBENODENSSRWL), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeNodeNssrwl)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBENODEQUAD), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeNodeQuad)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBENODEQUADPST3S), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeNodeQuadPst3s)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBENODEQUADNSSRWL), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeNodeQuadNssrwl)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_NODETYPE_NODETYPECUBENODEQUADLITEFUFORS), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_NODETYPE_NodeTypeCubeNodeQuadLitefufors)},
};

STATIC MP_DEFINE_CONST_DICT(commonframeworktypes1_nodetype_class_locals_dict, commonframeworktypes1_nodetype_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    commonframeworktypes1_nodetype_class_type,
    MP_QSTR_CommonFrameworkTypes1_NodeType,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&commonframeworktypes1_nodetype_class_locals_dict
);
//
// Enumeration classes for type 'CubeComputerCommon3_PowerSelect'
//
STATIC const mp_rom_map_elem_t cubecomputercommon3_powerselect_locals_dict_table[6] = 
{
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_POWERSELECT_POWEROFF), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_POWERSELECT_PowerOff)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_POWERSELECT_POWERON), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_POWERSELECT_PowerOn)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_POWERSELECT_POWERNOCHANGE), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_POWERSELECT_PowerNoChange)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_POWERSELECT_POWERAUTO), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_POWERSELECT_PowerAuto)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_POWERSELECT_POWERONPASS), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_POWERSELECT_PowerOnPass)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_POWERSELECT_POWEROFFUPGRADE), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_POWERSELECT_PowerOffUpgrade)},
};

STATIC MP_DEFINE_CONST_DICT(cubecomputercommon3_powerselect_class_locals_dict, cubecomputercommon3_powerselect_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    cubecomputercommon3_powerselect_class_type,
    MP_QSTR_CubeComputerCommon3_PowerSelect,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&cubecomputercommon3_powerselect_class_locals_dict
);
//
// Enumeration classes for type 'CubeComputerCommon3_EraseMagicNumbers'
//
STATIC const mp_rom_map_elem_t cubecomputercommon3_erasemagicnumbers_locals_dict_table[3] = 
{
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_ERASEMAGICNUMBERS_ERASETLMLOG), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_ERASEMAGICNUMBERS_EraseTlmLog)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_ERASEMAGICNUMBERS_ERASEEVENTLOG), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_ERASEMAGICNUMBERS_EraseEventLog)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_ERASEMAGICNUMBERS_ERASEIMAGELOG), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_ERASEMAGICNUMBERS_EraseImageLog)},
};

STATIC MP_DEFINE_CONST_DICT(cubecomputercommon3_erasemagicnumbers_class_locals_dict, cubecomputercommon3_erasemagicnumbers_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    cubecomputercommon3_erasemagicnumbers_class_type,
    MP_QSTR_CubeComputerCommon3_EraseMagicNumbers,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&cubecomputercommon3_erasemagicnumbers_class_locals_dict
);
//
// Enumeration classes for type 'CubeComputerCommon3_TlmLogReadQueueState'
//
STATIC const mp_rom_map_elem_t cubecomputercommon3_tlmlogreadqueuestate_locals_dict_table[3] = 
{
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TLMREADQIDLE), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TlmReadQIdle)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TLMREADQDOWNLOAD), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TlmReadQDownload)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TLMREADQERASE), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_TLMLOGREADQUEUESTATE_TlmReadQErase)},
};

STATIC MP_DEFINE_CONST_DICT(cubecomputercommon3_tlmlogreadqueuestate_class_locals_dict, cubecomputercommon3_tlmlogreadqueuestate_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    cubecomputercommon3_tlmlogreadqueuestate_class_type,
    MP_QSTR_CubeComputerCommon3_TlmLogReadQueueState,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&cubecomputercommon3_tlmlogreadqueuestate_class_locals_dict
);
//
// Enumeration classes for type 'CommonFrameworkTypes1_AbstractNode'
//
STATIC const mp_rom_map_elem_t commonframeworktypes1_abstractnode_locals_dict_table[25] = 
{
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEINVALID), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeInvalid)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODECOMPUTER), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeComputer)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODESTR0), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeStr0)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODESTR1), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeStr1)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEFSS0), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeFss0)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEFSS1), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeFss1)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEFSS2), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeFss2)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEFSS3), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeFss3)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEHSS0), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeHss0)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEHSS1), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeHss1)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEMAG0), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeMag0)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEMAG1), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeMag1)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEEXT0), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeExt0)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEEXT1), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeExt1)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODERWL0), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeRwl0)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODERWL1), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeRwl1)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODERWL2), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeRwl2)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODERWL3), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeRwl3)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODERWL4), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeRwl4)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEEXTGYR0), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeExtGyr0)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODEEXTGYR1), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeExtGyr1)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODECQ0), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeCq0)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODECQ1), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeCq1)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODECQ2), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeCq2)},
    { MP_ROM_QSTR(MP_QSTR_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NODECQ3), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_COMMONFRAMEWORKTYPES1_ABSTRACTNODE_NodeCq3)},
};

STATIC MP_DEFINE_CONST_DICT(commonframeworktypes1_abstractnode_class_locals_dict, commonframeworktypes1_abstractnode_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    commonframeworktypes1_abstractnode_class_type,
    MP_QSTR_CommonFrameworkTypes1_AbstractNode,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&commonframeworktypes1_abstractnode_class_locals_dict
);
//
// Enumeration classes for type 'CubeComputerCommon3_ImageTransferState'
//
STATIC const mp_rom_map_elem_t cubecomputercommon3_imagetransferstate_locals_dict_table[3] = 
{
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_STATEIDLE), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_StateIdle)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_STATEBUSYSTORE), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_StateBusyStore)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_STATEBUSYDOWNLOAD), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_IMAGETRANSFERSTATE_StateBusyDownload)},
};

STATIC MP_DEFINE_CONST_DICT(cubecomputercommon3_imagetransferstate_class_locals_dict, cubecomputercommon3_imagetransferstate_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    cubecomputercommon3_imagetransferstate_class_type,
    MP_QSTR_CubeComputerCommon3_ImageTransferState,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&cubecomputercommon3_imagetransferstate_class_locals_dict
);
//
// Enumeration classes for type 'CmdTargetNode'
//
STATIC const mp_rom_map_elem_t cmdtargetnode_locals_dict_table[2] = 
{
    { MP_ROM_QSTR(MP_QSTR_CMDTARGETNODE_NODEINVALID), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CMDTARGETNODE_NodeInvalid)},
    { MP_ROM_QSTR(MP_QSTR_CMDTARGETNODE_NODECOMPUTER), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CMDTARGETNODE_NodeComputer)},
};

STATIC MP_DEFINE_CONST_DICT(cmdtargetnode_class_locals_dict, cmdtargetnode_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    cmdtargetnode_class_type,
    MP_QSTR_CmdTargetNode,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&cmdtargetnode_class_locals_dict
);
//
// Enumeration classes for type 'CubeComputerCommon3_EventReadQueueState'
//
STATIC const mp_rom_map_elem_t cubecomputercommon3_eventreadqueuestate_locals_dict_table[3] = 
{
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_EVTREADQIDLE), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_EvtReadQIdle)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_EVTREADQDOWNLOAD), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_EvtReadQDownload)},
    { MP_ROM_QSTR(MP_QSTR_CUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_EVTREADQERASE), MP_ROM_INT(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_CUBECOMPUTERCOMMON3_EVENTREADQUEUESTATE_EvtReadQErase)},
};

STATIC MP_DEFINE_CONST_DICT(cubecomputercommon3_eventreadqueuestate_class_locals_dict, cubecomputercommon3_eventreadqueuestate_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    cubecomputercommon3_eventreadqueuestate_class_type,
    MP_QSTR_CubeComputerCommon3_EventReadQueueState,
    MP_TYPE_FLAG_NONE,
    locals_dict, (mp_obj_dict_t*)&cubecomputercommon3_eventreadqueuestate_class_locals_dict
);

/**********************************************************************
 *
 *  Static function definitions
 *
 **********************************************************************/
// uPy request function for method 'setPassThrough'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setPassThroughRequestData_t data;
} req_setPassThrough_fp_t;

STATIC mp_obj_t req_setPassThrough(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_setPassThrough_fp_t * p_req_data = m_malloc(sizeof(req_setPassThrough_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'setPassThrough' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 0;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.sSetVal = ((PassThrough_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_setPassThrough_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'setPassThrough'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setPassThroughResponseData_t data;
} resp_setPassThrough_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_setPassThrough_fp_t class_data;
} resp_setPassThrough_class_obj_t;

STATIC mp_obj_t resp_setPassThrough_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_setPassThrough_class_obj_t *p_self = m_new_obj(resp_setPassThrough_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_setPassThrough_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_setPassThrough_fp_t *p_data = (resp_setPassThrough_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "setPassThrough" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_setPassThrough_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_setPassThrough_class_obj_t *p_resp_data = ((resp_setPassThrough_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_setPassThrough_get_adcsErrorCode_obj, resp_setPassThrough_get_adcsErrorCode);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_setPassThrough_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_setPassThrough_get_adcsErrorCode_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_setPassThrough_locals_dict, resp_setPassThrough_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3setPassThroughResponseData,
    MP_QSTR_resp_setPassThrough,
    MP_TYPE_FLAG_NONE,
    make_new, resp_setPassThrough_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_setPassThrough_locals_dict    
);

// uPy request function for method 'setPowerState'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setPowerStateRequestData_t data;
} req_setPowerState_fp_t;

STATIC mp_obj_t req_setPowerState(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_setPowerState_fp_t * p_req_data = m_malloc(sizeof(req_setPowerState_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'setPowerState' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 1;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.sSetVal = ((PowerState_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_setPowerState_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'setPowerState'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setPowerStateResponseData_t data;
} resp_setPowerState_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_setPowerState_fp_t class_data;
} resp_setPowerState_class_obj_t;

STATIC mp_obj_t resp_setPowerState_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_setPowerState_class_obj_t *p_self = m_new_obj(resp_setPowerState_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_setPowerState_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_setPowerState_fp_t *p_data = (resp_setPowerState_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "setPowerState" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_setPowerState_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_setPowerState_class_obj_t *p_resp_data = ((resp_setPowerState_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_setPowerState_get_adcsErrorCode_obj, resp_setPowerState_get_adcsErrorCode);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_setPowerState_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_setPowerState_get_adcsErrorCode_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_setPowerState_locals_dict, resp_setPowerState_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3setPowerStateResponseData,
    MP_QSTR_resp_setPowerState,
    MP_TYPE_FLAG_NONE,
    make_new, resp_setPowerState_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_setPowerState_locals_dict    
);

// uPy request function for method 'setImageTransferSetup'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setImageTransferSetupRequestData_t data;
} req_setImageTransferSetup_fp_t;

STATIC mp_obj_t req_setImageTransferSetup(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_setImageTransferSetup_fp_t * p_req_data = m_malloc(sizeof(req_setImageTransferSetup_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'setImageTransferSetup' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 2;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.sSetVal = ((ImageTransferSetup_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_setImageTransferSetup_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'setImageTransferSetup'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setImageTransferSetupResponseData_t data;
} resp_setImageTransferSetup_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_setImageTransferSetup_fp_t class_data;
} resp_setImageTransferSetup_class_obj_t;

STATIC mp_obj_t resp_setImageTransferSetup_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_setImageTransferSetup_class_obj_t *p_self = m_new_obj(resp_setImageTransferSetup_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_setImageTransferSetup_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_setImageTransferSetup_fp_t *p_data = (resp_setImageTransferSetup_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "setImageTransferSetup" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_setImageTransferSetup_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_setImageTransferSetup_class_obj_t *p_resp_data = ((resp_setImageTransferSetup_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_setImageTransferSetup_get_adcsErrorCode_obj, resp_setImageTransferSetup_get_adcsErrorCode);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_setImageTransferSetup_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_setImageTransferSetup_get_adcsErrorCode_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_setImageTransferSetup_locals_dict, resp_setImageTransferSetup_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3setImageTransferSetupResponseData,
    MP_QSTR_resp_setImageTransferSetup,
    MP_TYPE_FLAG_NONE,
    make_new, resp_setImageTransferSetup_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_setImageTransferSetup_locals_dict    
);

// uPy request function for method 'setImageFileInfoReset'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setImageFileInfoResetRequestData_t data;
} req_setImageFileInfoReset_fp_t;

STATIC mp_obj_t req_setImageFileInfoReset(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_setImageFileInfoReset_fp_t * p_req_data = m_malloc(sizeof(req_setImageFileInfoReset_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'setImageFileInfoReset' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 3;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_setImageFileInfoReset_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'setImageFileInfoReset'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setImageFileInfoResetResponseData_t data;
} resp_setImageFileInfoReset_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_setImageFileInfoReset_fp_t class_data;
} resp_setImageFileInfoReset_class_obj_t;

STATIC mp_obj_t resp_setImageFileInfoReset_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_setImageFileInfoReset_class_obj_t *p_self = m_new_obj(resp_setImageFileInfoReset_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_setImageFileInfoReset_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_setImageFileInfoReset_fp_t *p_data = (resp_setImageFileInfoReset_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "setImageFileInfoReset" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_setImageFileInfoReset_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_setImageFileInfoReset_class_obj_t *p_resp_data = ((resp_setImageFileInfoReset_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_setImageFileInfoReset_get_adcsErrorCode_obj, resp_setImageFileInfoReset_get_adcsErrorCode);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_setImageFileInfoReset_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_setImageFileInfoReset_get_adcsErrorCode_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_setImageFileInfoReset_locals_dict, resp_setImageFileInfoReset_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3setImageFileInfoResetResponseData,
    MP_QSTR_resp_setImageFileInfoReset,
    MP_TYPE_FLAG_NONE,
    make_new, resp_setImageFileInfoReset_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_setImageFileInfoReset_locals_dict    
);

// uPy request function for method 'setPortMap'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setPortMapRequestData_t data;
} req_setPortMap_fp_t;

STATIC mp_obj_t req_setPortMap(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_setPortMap_fp_t * p_req_data = m_malloc(sizeof(req_setPortMap_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'setPortMap' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 4;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.sSetVal = ((PortMap_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_setPortMap_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'setPortMap'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setPortMapResponseData_t data;
} resp_setPortMap_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_setPortMap_fp_t class_data;
} resp_setPortMap_class_obj_t;

STATIC mp_obj_t resp_setPortMap_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_setPortMap_class_obj_t *p_self = m_new_obj(resp_setPortMap_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_setPortMap_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_setPortMap_fp_t *p_data = (resp_setPortMap_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "setPortMap" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_setPortMap_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_setPortMap_class_obj_t *p_resp_data = ((resp_setPortMap_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_setPortMap_get_adcsErrorCode_obj, resp_setPortMap_get_adcsErrorCode);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_setPortMap_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_setPortMap_get_adcsErrorCode_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_setPortMap_locals_dict, resp_setPortMap_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3setPortMapResponseData,
    MP_QSTR_resp_setPortMap,
    MP_TYPE_FLAG_NONE,
    make_new, resp_setPortMap_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_setPortMap_locals_dict    
);

// uPy request function for method 'setEraseLogData'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setEraseLogDataRequestData_t data;
} req_setEraseLogData_fp_t;

STATIC mp_obj_t req_setEraseLogData(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_setEraseLogData_fp_t * p_req_data = m_malloc(sizeof(req_setEraseLogData_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'setEraseLogData' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 5;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.sSetVal = ((EraseLogData_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_setEraseLogData_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'setEraseLogData'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setEraseLogDataResponseData_t data;
} resp_setEraseLogData_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_setEraseLogData_fp_t class_data;
} resp_setEraseLogData_class_obj_t;

STATIC mp_obj_t resp_setEraseLogData_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_setEraseLogData_class_obj_t *p_self = m_new_obj(resp_setEraseLogData_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_setEraseLogData_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_setEraseLogData_fp_t *p_data = (resp_setEraseLogData_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "setEraseLogData" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_setEraseLogData_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_setEraseLogData_class_obj_t *p_resp_data = ((resp_setEraseLogData_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_setEraseLogData_get_adcsErrorCode_obj, resp_setEraseLogData_get_adcsErrorCode);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_setEraseLogData_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_setEraseLogData_get_adcsErrorCode_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_setEraseLogData_locals_dict, resp_setEraseLogData_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3setEraseLogDataResponseData,
    MP_QSTR_resp_setEraseLogData,
    MP_TYPE_FLAG_NONE,
    make_new, resp_setEraseLogData_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_setEraseLogData_locals_dict    
);

// uPy request function for method 'setEventLogFilterTransferSetup'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setEventLogFilterTransferSetupRequestData_t data;
} req_setEventLogFilterTransferSetup_fp_t;

STATIC mp_obj_t req_setEventLogFilterTransferSetup(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_setEventLogFilterTransferSetup_fp_t * p_req_data = m_malloc(sizeof(req_setEventLogFilterTransferSetup_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'setEventLogFilterTransferSetup' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 6;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.sSetVal = ((EventLogFilterTransferSetup_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_setEventLogFilterTransferSetup_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'setEventLogFilterTransferSetup'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setEventLogFilterTransferSetupResponseData_t data;
} resp_setEventLogFilterTransferSetup_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_setEventLogFilterTransferSetup_fp_t class_data;
} resp_setEventLogFilterTransferSetup_class_obj_t;

STATIC mp_obj_t resp_setEventLogFilterTransferSetup_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_setEventLogFilterTransferSetup_class_obj_t *p_self = m_new_obj(resp_setEventLogFilterTransferSetup_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_setEventLogFilterTransferSetup_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_setEventLogFilterTransferSetup_fp_t *p_data = (resp_setEventLogFilterTransferSetup_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "setEventLogFilterTransferSetup" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_setEventLogFilterTransferSetup_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_setEventLogFilterTransferSetup_class_obj_t *p_resp_data = ((resp_setEventLogFilterTransferSetup_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_setEventLogFilterTransferSetup_get_adcsErrorCode_obj, resp_setEventLogFilterTransferSetup_get_adcsErrorCode);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_setEventLogFilterTransferSetup_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_setEventLogFilterTransferSetup_get_adcsErrorCode_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_setEventLogFilterTransferSetup_locals_dict, resp_setEventLogFilterTransferSetup_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3setEventLogFilterTransferSetupResponseData,
    MP_QSTR_resp_setEventLogFilterTransferSetup,
    MP_TYPE_FLAG_NONE,
    make_new, resp_setEventLogFilterTransferSetup_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_setEventLogFilterTransferSetup_locals_dict    
);

// uPy request function for method 'setTelemetryLogTransferSetup'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setTelemetryLogTransferSetupRequestData_t data;
} req_setTelemetryLogTransferSetup_fp_t;

STATIC mp_obj_t req_setTelemetryLogTransferSetup(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_setTelemetryLogTransferSetup_fp_t * p_req_data = m_malloc(sizeof(req_setTelemetryLogTransferSetup_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'setTelemetryLogTransferSetup' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 7;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.sSetVal = ((TelemetryLogTransferSetup_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_setTelemetryLogTransferSetup_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'setTelemetryLogTransferSetup'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setTelemetryLogTransferSetupResponseData_t data;
} resp_setTelemetryLogTransferSetup_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_setTelemetryLogTransferSetup_fp_t class_data;
} resp_setTelemetryLogTransferSetup_class_obj_t;

STATIC mp_obj_t resp_setTelemetryLogTransferSetup_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_setTelemetryLogTransferSetup_class_obj_t *p_self = m_new_obj(resp_setTelemetryLogTransferSetup_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_setTelemetryLogTransferSetup_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_setTelemetryLogTransferSetup_fp_t *p_data = (resp_setTelemetryLogTransferSetup_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "setTelemetryLogTransferSetup" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_setTelemetryLogTransferSetup_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_setTelemetryLogTransferSetup_class_obj_t *p_resp_data = ((resp_setTelemetryLogTransferSetup_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_setTelemetryLogTransferSetup_get_adcsErrorCode_obj, resp_setTelemetryLogTransferSetup_get_adcsErrorCode);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_setTelemetryLogTransferSetup_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_setTelemetryLogTransferSetup_get_adcsErrorCode_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_setTelemetryLogTransferSetup_locals_dict, resp_setTelemetryLogTransferSetup_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3setTelemetryLogTransferSetupResponseData,
    MP_QSTR_resp_setTelemetryLogTransferSetup,
    MP_TYPE_FLAG_NONE,
    make_new, resp_setTelemetryLogTransferSetup_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_setTelemetryLogTransferSetup_locals_dict    
);

// uPy request function for method 'setDummyEvent'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setDummyEventRequestData_t data;
} req_setDummyEvent_fp_t;

STATIC mp_obj_t req_setDummyEvent(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_setDummyEvent_fp_t * p_req_data = m_malloc(sizeof(req_setDummyEvent_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'setDummyEvent' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 8;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.sSetVal = ((DummyEvent_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_setDummyEvent_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'setDummyEvent'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setDummyEventResponseData_t data;
} resp_setDummyEvent_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_setDummyEvent_fp_t class_data;
} resp_setDummyEvent_class_obj_t;

STATIC mp_obj_t resp_setDummyEvent_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_setDummyEvent_class_obj_t *p_self = m_new_obj(resp_setDummyEvent_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_setDummyEvent_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_setDummyEvent_fp_t *p_data = (resp_setDummyEvent_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "setDummyEvent" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_setDummyEvent_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_setDummyEvent_class_obj_t *p_resp_data = ((resp_setDummyEvent_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_setDummyEvent_get_adcsErrorCode_obj, resp_setDummyEvent_get_adcsErrorCode);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_setDummyEvent_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_setDummyEvent_get_adcsErrorCode_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_setDummyEvent_locals_dict, resp_setDummyEvent_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3setDummyEventResponseData,
    MP_QSTR_resp_setDummyEvent,
    MP_TYPE_FLAG_NONE,
    make_new, resp_setDummyEvent_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_setDummyEvent_locals_dict    
);

// uPy request function for method 'setUnsolicitedEventSetup'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setUnsolicitedEventSetupRequestData_t data;
} req_setUnsolicitedEventSetup_fp_t;

STATIC mp_obj_t req_setUnsolicitedEventSetup(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_setUnsolicitedEventSetup_fp_t * p_req_data = m_malloc(sizeof(req_setUnsolicitedEventSetup_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'setUnsolicitedEventSetup' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 9;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.sSetVal = ((UnsolicitedEventSetup_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_setUnsolicitedEventSetup_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'setUnsolicitedEventSetup'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setUnsolicitedEventSetupResponseData_t data;
} resp_setUnsolicitedEventSetup_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_setUnsolicitedEventSetup_fp_t class_data;
} resp_setUnsolicitedEventSetup_class_obj_t;

STATIC mp_obj_t resp_setUnsolicitedEventSetup_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_setUnsolicitedEventSetup_class_obj_t *p_self = m_new_obj(resp_setUnsolicitedEventSetup_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_setUnsolicitedEventSetup_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_setUnsolicitedEventSetup_fp_t *p_data = (resp_setUnsolicitedEventSetup_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "setUnsolicitedEventSetup" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_setUnsolicitedEventSetup_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_setUnsolicitedEventSetup_class_obj_t *p_resp_data = ((resp_setUnsolicitedEventSetup_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_setUnsolicitedEventSetup_get_adcsErrorCode_obj, resp_setUnsolicitedEventSetup_get_adcsErrorCode);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_setUnsolicitedEventSetup_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_setUnsolicitedEventSetup_get_adcsErrorCode_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_setUnsolicitedEventSetup_locals_dict, resp_setUnsolicitedEventSetup_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3setUnsolicitedEventSetupResponseData,
    MP_QSTR_resp_setUnsolicitedEventSetup,
    MP_TYPE_FLAG_NONE,
    make_new, resp_setUnsolicitedEventSetup_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_setUnsolicitedEventSetup_locals_dict    
);

// uPy request function for method 'setUnsolicitedTlmSetup'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setUnsolicitedTlmSetupRequestData_t data;
} req_setUnsolicitedTlmSetup_fp_t;

STATIC mp_obj_t req_setUnsolicitedTlmSetup(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_setUnsolicitedTlmSetup_fp_t * p_req_data = m_malloc(sizeof(req_setUnsolicitedTlmSetup_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'setUnsolicitedTlmSetup' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 10;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    p_req_data->data.sSetVal = ((UnsolicitedTlmSetup_class_obj_t *) MP_OBJ_TO_PTR(p_args[1]))->class_data;
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_setUnsolicitedTlmSetup_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'setUnsolicitedTlmSetup'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3setUnsolicitedTlmSetupResponseData_t data;
} resp_setUnsolicitedTlmSetup_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_setUnsolicitedTlmSetup_fp_t class_data;
} resp_setUnsolicitedTlmSetup_class_obj_t;

STATIC mp_obj_t resp_setUnsolicitedTlmSetup_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_setUnsolicitedTlmSetup_class_obj_t *p_self = m_new_obj(resp_setUnsolicitedTlmSetup_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_setUnsolicitedTlmSetup_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_setUnsolicitedTlmSetup_fp_t *p_data = (resp_setUnsolicitedTlmSetup_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "setUnsolicitedTlmSetup" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_setUnsolicitedTlmSetup_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_setUnsolicitedTlmSetup_class_obj_t *p_resp_data = ((resp_setUnsolicitedTlmSetup_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_setUnsolicitedTlmSetup_get_adcsErrorCode_obj, resp_setUnsolicitedTlmSetup_get_adcsErrorCode);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_setUnsolicitedTlmSetup_locals_dict_table[1] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_setUnsolicitedTlmSetup_get_adcsErrorCode_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_setUnsolicitedTlmSetup_locals_dict, resp_setUnsolicitedTlmSetup_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3setUnsolicitedTlmSetupResponseData,
    MP_QSTR_resp_setUnsolicitedTlmSetup,
    MP_TYPE_FLAG_NONE,
    make_new, resp_setUnsolicitedTlmSetup_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_setUnsolicitedTlmSetup_locals_dict    
);

// uPy request function for method 'getPassThrough'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getPassThroughRequestData_t data;
} req_getPassThrough_fp_t;

STATIC mp_obj_t req_getPassThrough(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_getPassThrough_fp_t * p_req_data = m_malloc(sizeof(req_getPassThrough_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getPassThrough' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 11;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getPassThrough_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getPassThrough'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getPassThroughResponseData_t data;
} resp_getPassThrough_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getPassThrough_fp_t class_data;
} resp_getPassThrough_class_obj_t;

STATIC mp_obj_t resp_getPassThrough_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getPassThrough_class_obj_t *p_self = m_new_obj(resp_getPassThrough_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getPassThrough_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getPassThrough_fp_t *p_data = (resp_getPassThrough_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "getPassThrough" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getPassThrough_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_getPassThrough_class_obj_t *p_resp_data = ((resp_getPassThrough_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getPassThrough_get_adcsErrorCode_obj, resp_getPassThrough_get_adcsErrorCode);

STATIC mp_obj_t resp_getPassThrough_get_returnVal(mp_obj_t self_in) 
{
    const resp_getPassThrough_class_obj_t *p_resp_data = ((resp_getPassThrough_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return PassThrough_make_from_buf(mp_obj_new_bytearray(sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PassThrough_t), (const uint8_t *) &p_resp_data->class_data.data.sReturnVal));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getPassThrough_get_returnVal_obj, resp_getPassThrough_get_returnVal);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getPassThrough_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_getPassThrough_get_adcsErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_returnVal), MP_ROM_PTR(&resp_getPassThrough_get_returnVal_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getPassThrough_locals_dict, resp_getPassThrough_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3getPassThroughResponseData,
    MP_QSTR_resp_getPassThrough,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getPassThrough_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getPassThrough_locals_dict    
);

// uPy request function for method 'getPowerState'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getPowerStateRequestData_t data;
} req_getPowerState_fp_t;

STATIC mp_obj_t req_getPowerState(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_getPowerState_fp_t * p_req_data = m_malloc(sizeof(req_getPowerState_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getPowerState' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 12;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getPowerState_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getPowerState'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getPowerStateResponseData_t data;
} resp_getPowerState_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getPowerState_fp_t class_data;
} resp_getPowerState_class_obj_t;

STATIC mp_obj_t resp_getPowerState_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getPowerState_class_obj_t *p_self = m_new_obj(resp_getPowerState_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getPowerState_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getPowerState_fp_t *p_data = (resp_getPowerState_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "getPowerState" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getPowerState_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_getPowerState_class_obj_t *p_resp_data = ((resp_getPowerState_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getPowerState_get_adcsErrorCode_obj, resp_getPowerState_get_adcsErrorCode);

STATIC mp_obj_t resp_getPowerState_get_returnVal(mp_obj_t self_in) 
{
    const resp_getPowerState_class_obj_t *p_resp_data = ((resp_getPowerState_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return PowerState_make_from_buf(mp_obj_new_bytearray(sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PowerState_t), (const uint8_t *) &p_resp_data->class_data.data.sReturnVal));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getPowerState_get_returnVal_obj, resp_getPowerState_get_returnVal);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getPowerState_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_getPowerState_get_adcsErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_returnVal), MP_ROM_PTR(&resp_getPowerState_get_returnVal_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getPowerState_locals_dict, resp_getPowerState_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3getPowerStateResponseData,
    MP_QSTR_resp_getPowerState,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getPowerState_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getPowerState_locals_dict    
);

// uPy request function for method 'getPortDiagnostics'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getPortDiagnosticsRequestData_t data;
} req_getPortDiagnostics_fp_t;

STATIC mp_obj_t req_getPortDiagnostics(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_getPortDiagnostics_fp_t * p_req_data = m_malloc(sizeof(req_getPortDiagnostics_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getPortDiagnostics' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 13;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getPortDiagnostics_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getPortDiagnostics'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getPortDiagnosticsResponseData_t data;
} resp_getPortDiagnostics_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getPortDiagnostics_fp_t class_data;
} resp_getPortDiagnostics_class_obj_t;

STATIC mp_obj_t resp_getPortDiagnostics_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getPortDiagnostics_class_obj_t *p_self = m_new_obj(resp_getPortDiagnostics_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getPortDiagnostics_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getPortDiagnostics_fp_t *p_data = (resp_getPortDiagnostics_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "getPortDiagnostics" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getPortDiagnostics_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_getPortDiagnostics_class_obj_t *p_resp_data = ((resp_getPortDiagnostics_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getPortDiagnostics_get_adcsErrorCode_obj, resp_getPortDiagnostics_get_adcsErrorCode);

STATIC mp_obj_t resp_getPortDiagnostics_get_returnVal(mp_obj_t self_in) 
{
    const resp_getPortDiagnostics_class_obj_t *p_resp_data = ((resp_getPortDiagnostics_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return PortDiagnostics_make_from_buf(mp_obj_new_bytearray(sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PortDiagnostics_t), (const uint8_t *) &p_resp_data->class_data.data.sReturnVal));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getPortDiagnostics_get_returnVal_obj, resp_getPortDiagnostics_get_returnVal);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getPortDiagnostics_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_getPortDiagnostics_get_adcsErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_returnVal), MP_ROM_PTR(&resp_getPortDiagnostics_get_returnVal_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getPortDiagnostics_locals_dict, resp_getPortDiagnostics_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3getPortDiagnosticsResponseData,
    MP_QSTR_resp_getPortDiagnostics,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getPortDiagnostics_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getPortDiagnostics_locals_dict    
);

// uPy request function for method 'getPortMap'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getPortMapRequestData_t data;
} req_getPortMap_fp_t;

STATIC mp_obj_t req_getPortMap(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_getPortMap_fp_t * p_req_data = m_malloc(sizeof(req_getPortMap_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getPortMap' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 14;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getPortMap_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getPortMap'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getPortMapResponseData_t data;
} resp_getPortMap_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getPortMap_fp_t class_data;
} resp_getPortMap_class_obj_t;

STATIC mp_obj_t resp_getPortMap_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getPortMap_class_obj_t *p_self = m_new_obj(resp_getPortMap_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getPortMap_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getPortMap_fp_t *p_data = (resp_getPortMap_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "getPortMap" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getPortMap_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_getPortMap_class_obj_t *p_resp_data = ((resp_getPortMap_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getPortMap_get_adcsErrorCode_obj, resp_getPortMap_get_adcsErrorCode);

STATIC mp_obj_t resp_getPortMap_get_returnVal(mp_obj_t self_in) 
{
    const resp_getPortMap_class_obj_t *p_resp_data = ((resp_getPortMap_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return PortMap_make_from_buf(mp_obj_new_bytearray(sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_PortMap_t), (const uint8_t *) &p_resp_data->class_data.data.sReturnVal));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getPortMap_get_returnVal_obj, resp_getPortMap_get_returnVal);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getPortMap_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_getPortMap_get_adcsErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_returnVal), MP_ROM_PTR(&resp_getPortMap_get_returnVal_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getPortMap_locals_dict, resp_getPortMap_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3getPortMapResponseData,
    MP_QSTR_resp_getPortMap,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getPortMap_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getPortMap_locals_dict    
);

// uPy request function for method 'getExpectedNodes'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getExpectedNodesRequestData_t data;
} req_getExpectedNodes_fp_t;

STATIC mp_obj_t req_getExpectedNodes(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_getExpectedNodes_fp_t * p_req_data = m_malloc(sizeof(req_getExpectedNodes_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getExpectedNodes' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 15;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getExpectedNodes_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getExpectedNodes'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getExpectedNodesResponseData_t data;
} resp_getExpectedNodes_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getExpectedNodes_fp_t class_data;
} resp_getExpectedNodes_class_obj_t;

STATIC mp_obj_t resp_getExpectedNodes_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getExpectedNodes_class_obj_t *p_self = m_new_obj(resp_getExpectedNodes_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getExpectedNodes_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getExpectedNodes_fp_t *p_data = (resp_getExpectedNodes_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "getExpectedNodes" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getExpectedNodes_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_getExpectedNodes_class_obj_t *p_resp_data = ((resp_getExpectedNodes_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getExpectedNodes_get_adcsErrorCode_obj, resp_getExpectedNodes_get_adcsErrorCode);

STATIC mp_obj_t resp_getExpectedNodes_get_returnVal(mp_obj_t self_in) 
{
    const resp_getExpectedNodes_class_obj_t *p_resp_data = ((resp_getExpectedNodes_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return ExpectedNodes_make_from_buf(mp_obj_new_bytearray(sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ExpectedNodes_t), (const uint8_t *) &p_resp_data->class_data.data.sReturnVal));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getExpectedNodes_get_returnVal_obj, resp_getExpectedNodes_get_returnVal);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getExpectedNodes_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_getExpectedNodes_get_adcsErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_returnVal), MP_ROM_PTR(&resp_getExpectedNodes_get_returnVal_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getExpectedNodes_locals_dict, resp_getExpectedNodes_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3getExpectedNodesResponseData,
    MP_QSTR_resp_getExpectedNodes,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getExpectedNodes_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getExpectedNodes_locals_dict    
);

// uPy request function for method 'getImageTransferStatus'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getImageTransferStatusRequestData_t data;
} req_getImageTransferStatus_fp_t;

STATIC mp_obj_t req_getImageTransferStatus(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_getImageTransferStatus_fp_t * p_req_data = m_malloc(sizeof(req_getImageTransferStatus_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getImageTransferStatus' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 16;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getImageTransferStatus_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getImageTransferStatus'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getImageTransferStatusResponseData_t data;
} resp_getImageTransferStatus_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getImageTransferStatus_fp_t class_data;
} resp_getImageTransferStatus_class_obj_t;

STATIC mp_obj_t resp_getImageTransferStatus_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getImageTransferStatus_class_obj_t *p_self = m_new_obj(resp_getImageTransferStatus_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getImageTransferStatus_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getImageTransferStatus_fp_t *p_data = (resp_getImageTransferStatus_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "getImageTransferStatus" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getImageTransferStatus_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_getImageTransferStatus_class_obj_t *p_resp_data = ((resp_getImageTransferStatus_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getImageTransferStatus_get_adcsErrorCode_obj, resp_getImageTransferStatus_get_adcsErrorCode);

STATIC mp_obj_t resp_getImageTransferStatus_get_returnVal(mp_obj_t self_in) 
{
    const resp_getImageTransferStatus_class_obj_t *p_resp_data = ((resp_getImageTransferStatus_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return ImageTransferStatus_make_from_buf(mp_obj_new_bytearray(sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageTransferStatus_t), (const uint8_t *) &p_resp_data->class_data.data.sReturnVal));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getImageTransferStatus_get_returnVal_obj, resp_getImageTransferStatus_get_returnVal);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getImageTransferStatus_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_getImageTransferStatus_get_adcsErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_returnVal), MP_ROM_PTR(&resp_getImageTransferStatus_get_returnVal_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getImageTransferStatus_locals_dict, resp_getImageTransferStatus_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3getImageTransferStatusResponseData,
    MP_QSTR_resp_getImageTransferStatus,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getImageTransferStatus_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getImageTransferStatus_locals_dict    
);

// uPy request function for method 'getImageFileInfo'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getImageFileInfoRequestData_t data;
} req_getImageFileInfo_fp_t;

STATIC mp_obj_t req_getImageFileInfo(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_getImageFileInfo_fp_t * p_req_data = m_malloc(sizeof(req_getImageFileInfo_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getImageFileInfo' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 17;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getImageFileInfo_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getImageFileInfo'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getImageFileInfoResponseData_t data;
} resp_getImageFileInfo_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getImageFileInfo_fp_t class_data;
} resp_getImageFileInfo_class_obj_t;

STATIC mp_obj_t resp_getImageFileInfo_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getImageFileInfo_class_obj_t *p_self = m_new_obj(resp_getImageFileInfo_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getImageFileInfo_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getImageFileInfo_fp_t *p_data = (resp_getImageFileInfo_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "getImageFileInfo" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getImageFileInfo_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_getImageFileInfo_class_obj_t *p_resp_data = ((resp_getImageFileInfo_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getImageFileInfo_get_adcsErrorCode_obj, resp_getImageFileInfo_get_adcsErrorCode);

STATIC mp_obj_t resp_getImageFileInfo_get_returnVal(mp_obj_t self_in) 
{
    const resp_getImageFileInfo_class_obj_t *p_resp_data = ((resp_getImageFileInfo_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return ImageFileInfo_make_from_buf(mp_obj_new_bytearray(sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ImageFileInfo_t), (const uint8_t *) &p_resp_data->class_data.data.sReturnVal));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getImageFileInfo_get_returnVal_obj, resp_getImageFileInfo_get_returnVal);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getImageFileInfo_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_getImageFileInfo_get_adcsErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_returnVal), MP_ROM_PTR(&resp_getImageFileInfo_get_returnVal_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getImageFileInfo_locals_dict, resp_getImageFileInfo_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3getImageFileInfoResponseData,
    MP_QSTR_resp_getImageFileInfo,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getImageFileInfo_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getImageFileInfo_locals_dict    
);

// uPy request function for method 'getComponentErrorCodes'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getComponentErrorCodesRequestData_t data;
} req_getComponentErrorCodes_fp_t;

STATIC mp_obj_t req_getComponentErrorCodes(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_getComponentErrorCodes_fp_t * p_req_data = m_malloc(sizeof(req_getComponentErrorCodes_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getComponentErrorCodes' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 18;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getComponentErrorCodes_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getComponentErrorCodes'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getComponentErrorCodesResponseData_t data;
} resp_getComponentErrorCodes_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getComponentErrorCodes_fp_t class_data;
} resp_getComponentErrorCodes_class_obj_t;

STATIC mp_obj_t resp_getComponentErrorCodes_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getComponentErrorCodes_class_obj_t *p_self = m_new_obj(resp_getComponentErrorCodes_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getComponentErrorCodes_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getComponentErrorCodes_fp_t *p_data = (resp_getComponentErrorCodes_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "getComponentErrorCodes" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getComponentErrorCodes_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_getComponentErrorCodes_class_obj_t *p_resp_data = ((resp_getComponentErrorCodes_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getComponentErrorCodes_get_adcsErrorCode_obj, resp_getComponentErrorCodes_get_adcsErrorCode);

STATIC mp_obj_t resp_getComponentErrorCodes_get_returnVal(mp_obj_t self_in) 
{
    const resp_getComponentErrorCodes_class_obj_t *p_resp_data = ((resp_getComponentErrorCodes_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return ComponentErrorCodes_make_from_buf(mp_obj_new_bytearray(sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_ComponentErrorCodes_t), (const uint8_t *) &p_resp_data->class_data.data.sReturnVal));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getComponentErrorCodes_get_returnVal_obj, resp_getComponentErrorCodes_get_returnVal);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getComponentErrorCodes_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_getComponentErrorCodes_get_adcsErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_returnVal), MP_ROM_PTR(&resp_getComponentErrorCodes_get_returnVal_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getComponentErrorCodes_locals_dict, resp_getComponentErrorCodes_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3getComponentErrorCodesResponseData,
    MP_QSTR_resp_getComponentErrorCodes,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getComponentErrorCodes_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getComponentErrorCodes_locals_dict    
);

// uPy request function for method 'getEventLogStatus'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getEventLogStatusRequestData_t data;
} req_getEventLogStatus_fp_t;

STATIC mp_obj_t req_getEventLogStatus(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_getEventLogStatus_fp_t * p_req_data = m_malloc(sizeof(req_getEventLogStatus_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getEventLogStatus' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 19;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getEventLogStatus_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getEventLogStatus'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getEventLogStatusResponseData_t data;
} resp_getEventLogStatus_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getEventLogStatus_fp_t class_data;
} resp_getEventLogStatus_class_obj_t;

STATIC mp_obj_t resp_getEventLogStatus_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getEventLogStatus_class_obj_t *p_self = m_new_obj(resp_getEventLogStatus_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getEventLogStatus_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getEventLogStatus_fp_t *p_data = (resp_getEventLogStatus_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "getEventLogStatus" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getEventLogStatus_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_getEventLogStatus_class_obj_t *p_resp_data = ((resp_getEventLogStatus_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getEventLogStatus_get_adcsErrorCode_obj, resp_getEventLogStatus_get_adcsErrorCode);

STATIC mp_obj_t resp_getEventLogStatus_get_returnVal(mp_obj_t self_in) 
{
    const resp_getEventLogStatus_class_obj_t *p_resp_data = ((resp_getEventLogStatus_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return EventLogStatus_make_from_buf(mp_obj_new_bytearray(sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_EventLogStatus_t), (const uint8_t *) &p_resp_data->class_data.data.sReturnVal));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getEventLogStatus_get_returnVal_obj, resp_getEventLogStatus_get_returnVal);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getEventLogStatus_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_getEventLogStatus_get_adcsErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_returnVal), MP_ROM_PTR(&resp_getEventLogStatus_get_returnVal_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getEventLogStatus_locals_dict, resp_getEventLogStatus_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3getEventLogStatusResponseData,
    MP_QSTR_resp_getEventLogStatus,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getEventLogStatus_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getEventLogStatus_locals_dict    
);

// uPy request function for method 'getTelemtryLogStatus'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getTelemtryLogStatusRequestData_t data;
} req_getTelemtryLogStatus_fp_t;

STATIC mp_obj_t req_getTelemtryLogStatus(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_getTelemtryLogStatus_fp_t * p_req_data = m_malloc(sizeof(req_getTelemtryLogStatus_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getTelemtryLogStatus' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 20;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getTelemtryLogStatus_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getTelemtryLogStatus'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getTelemtryLogStatusResponseData_t data;
} resp_getTelemtryLogStatus_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getTelemtryLogStatus_fp_t class_data;
} resp_getTelemtryLogStatus_class_obj_t;

STATIC mp_obj_t resp_getTelemtryLogStatus_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getTelemtryLogStatus_class_obj_t *p_self = m_new_obj(resp_getTelemtryLogStatus_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getTelemtryLogStatus_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getTelemtryLogStatus_fp_t *p_data = (resp_getTelemtryLogStatus_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "getTelemtryLogStatus" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getTelemtryLogStatus_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_getTelemtryLogStatus_class_obj_t *p_resp_data = ((resp_getTelemtryLogStatus_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getTelemtryLogStatus_get_adcsErrorCode_obj, resp_getTelemtryLogStatus_get_adcsErrorCode);

STATIC mp_obj_t resp_getTelemtryLogStatus_get_returnVal(mp_obj_t self_in) 
{
    const resp_getTelemtryLogStatus_class_obj_t *p_resp_data = ((resp_getTelemtryLogStatus_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return TelemtryLogStatus_make_from_buf(mp_obj_new_bytearray(sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemtryLogStatus_t), (const uint8_t *) &p_resp_data->class_data.data.sReturnVal));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getTelemtryLogStatus_get_returnVal_obj, resp_getTelemtryLogStatus_get_returnVal);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getTelemtryLogStatus_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_getTelemtryLogStatus_get_adcsErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_returnVal), MP_ROM_PTR(&resp_getTelemtryLogStatus_get_returnVal_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getTelemtryLogStatus_locals_dict, resp_getTelemtryLogStatus_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3getTelemtryLogStatusResponseData,
    MP_QSTR_resp_getTelemtryLogStatus,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getTelemtryLogStatus_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getTelemtryLogStatus_locals_dict    
);

// uPy request function for method 'getUnsolicitedEventSetup'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getUnsolicitedEventSetupRequestData_t data;
} req_getUnsolicitedEventSetup_fp_t;

STATIC mp_obj_t req_getUnsolicitedEventSetup(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_getUnsolicitedEventSetup_fp_t * p_req_data = m_malloc(sizeof(req_getUnsolicitedEventSetup_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getUnsolicitedEventSetup' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 21;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getUnsolicitedEventSetup_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getUnsolicitedEventSetup'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getUnsolicitedEventSetupResponseData_t data;
} resp_getUnsolicitedEventSetup_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getUnsolicitedEventSetup_fp_t class_data;
} resp_getUnsolicitedEventSetup_class_obj_t;

STATIC mp_obj_t resp_getUnsolicitedEventSetup_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getUnsolicitedEventSetup_class_obj_t *p_self = m_new_obj(resp_getUnsolicitedEventSetup_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getUnsolicitedEventSetup_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getUnsolicitedEventSetup_fp_t *p_data = (resp_getUnsolicitedEventSetup_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "getUnsolicitedEventSetup" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getUnsolicitedEventSetup_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_getUnsolicitedEventSetup_class_obj_t *p_resp_data = ((resp_getUnsolicitedEventSetup_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getUnsolicitedEventSetup_get_adcsErrorCode_obj, resp_getUnsolicitedEventSetup_get_adcsErrorCode);

STATIC mp_obj_t resp_getUnsolicitedEventSetup_get_returnVal(mp_obj_t self_in) 
{
    const resp_getUnsolicitedEventSetup_class_obj_t *p_resp_data = ((resp_getUnsolicitedEventSetup_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return UnsolicitedEventSetup_make_from_buf(mp_obj_new_bytearray(sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedEventSetup_t), (const uint8_t *) &p_resp_data->class_data.data.sReturnVal));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getUnsolicitedEventSetup_get_returnVal_obj, resp_getUnsolicitedEventSetup_get_returnVal);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getUnsolicitedEventSetup_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_getUnsolicitedEventSetup_get_adcsErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_returnVal), MP_ROM_PTR(&resp_getUnsolicitedEventSetup_get_returnVal_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getUnsolicitedEventSetup_locals_dict, resp_getUnsolicitedEventSetup_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3getUnsolicitedEventSetupResponseData,
    MP_QSTR_resp_getUnsolicitedEventSetup,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getUnsolicitedEventSetup_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getUnsolicitedEventSetup_locals_dict    
);

// uPy request function for method 'getUnsolicitedTlmSetup'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getUnsolicitedTlmSetupRequestData_t data;
} req_getUnsolicitedTlmSetup_fp_t;

STATIC mp_obj_t req_getUnsolicitedTlmSetup(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_getUnsolicitedTlmSetup_fp_t * p_req_data = m_malloc(sizeof(req_getUnsolicitedTlmSetup_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getUnsolicitedTlmSetup' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 22;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getUnsolicitedTlmSetup_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getUnsolicitedTlmSetup'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getUnsolicitedTlmSetupResponseData_t data;
} resp_getUnsolicitedTlmSetup_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getUnsolicitedTlmSetup_fp_t class_data;
} resp_getUnsolicitedTlmSetup_class_obj_t;

STATIC mp_obj_t resp_getUnsolicitedTlmSetup_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getUnsolicitedTlmSetup_class_obj_t *p_self = m_new_obj(resp_getUnsolicitedTlmSetup_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getUnsolicitedTlmSetup_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getUnsolicitedTlmSetup_fp_t *p_data = (resp_getUnsolicitedTlmSetup_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "getUnsolicitedTlmSetup" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getUnsolicitedTlmSetup_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_getUnsolicitedTlmSetup_class_obj_t *p_resp_data = ((resp_getUnsolicitedTlmSetup_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getUnsolicitedTlmSetup_get_adcsErrorCode_obj, resp_getUnsolicitedTlmSetup_get_adcsErrorCode);

STATIC mp_obj_t resp_getUnsolicitedTlmSetup_get_returnVal(mp_obj_t self_in) 
{
    const resp_getUnsolicitedTlmSetup_class_obj_t *p_resp_data = ((resp_getUnsolicitedTlmSetup_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return UnsolicitedTlmSetup_make_from_buf(mp_obj_new_bytearray(sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_UnsolicitedTlmSetup_t), (const uint8_t *) &p_resp_data->class_data.data.sReturnVal));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getUnsolicitedTlmSetup_get_returnVal_obj, resp_getUnsolicitedTlmSetup_get_returnVal);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getUnsolicitedTlmSetup_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_getUnsolicitedTlmSetup_get_adcsErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_returnVal), MP_ROM_PTR(&resp_getUnsolicitedTlmSetup_get_returnVal_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getUnsolicitedTlmSetup_locals_dict, resp_getUnsolicitedTlmSetup_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3getUnsolicitedTlmSetupResponseData,
    MP_QSTR_resp_getUnsolicitedTlmSetup,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getUnsolicitedTlmSetup_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getUnsolicitedTlmSetup_locals_dict    
);

// uPy request function for method 'getTelemtryLogInclusionMasks'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getTelemtryLogInclusionMasksRequestData_t data;
} req_getTelemtryLogInclusionMasks_fp_t;

STATIC mp_obj_t req_getTelemtryLogInclusionMasks(size_t n_args, const mp_obj_t *p_args)
{
    if (n_args < 1)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 1 arguments expected"));
    }

    // allocate memory on the MicroPython heap
    req_getTelemtryLogInclusionMasks_fp_t * p_req_data = m_malloc(sizeof(req_getTelemtryLogInclusionMasks_fp_t));
    
    if (NULL == p_req_data) 
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_MemoryError, "failed to allocate memory for 'getTelemtryLogInclusionMasks' input argument serialization"));
    }
    
    // fill-in FP header info
    p_req_data->fp_hdr.proto_id = 305;
    p_req_data->fp_hdr.func_id = 23;
    p_req_data->fp_hdr.seq_id = 0;
    p_req_data->fp_hdr.err_code = 0;
    
    p_req_data->data.eCmdTargetNode = (uint8_t) mp_obj_get_int(p_args[0]);
    
    // create uPy bytebuffer object, bind it to the allocated memory and return to the uPy host
    return mp_obj_new_bytearray(sizeof(req_getTelemtryLogInclusionMasks_fp_t), (const uint8_t *)p_req_data);
}

// uPy response function for method 'getTelemtryLogInclusionMasks'
// structure to use for serializing the full FP request (incl. FP header)
typedef struct
{
    upy_serdes_helpers_fp_hdr_t fp_hdr;
    CubeADCS_Gen2_CubeComputerCommon3getTelemtryLogInclusionMasksResponseData_t data;
} resp_getTelemtryLogInclusionMasks_fp_t;
        
typedef struct
{
    mp_obj_base_t base;
    resp_getTelemtryLogInclusionMasks_fp_t class_data;
} resp_getTelemtryLogInclusionMasks_class_obj_t;

STATIC mp_obj_t resp_getTelemtryLogInclusionMasks_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *p_args) {
    mp_arg_check_num(n_args, n_kw, 1, 1, false);
    
    resp_getTelemtryLogInclusionMasks_class_obj_t *p_self = m_new_obj(resp_getTelemtryLogInclusionMasks_class_obj_t);
    p_self->base.type = type;
    
    mp_buffer_info_t buf_info;
    
    if (true == mp_get_buffer(p_args[0], &buf_info, MP_BUFFER_READ))
    {
        if (buf_info.len < sizeof(resp_getTelemtryLogInclusionMasks_fp_t))
        {
            nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "Bad buffer length"));
        }
        
        const resp_getTelemtryLogInclusionMasks_fp_t *p_data = (resp_getTelemtryLogInclusionMasks_fp_t *) buf_info.buf;
        
        // perform shallow memory copy
        p_self->class_data = *p_data;
    }
    else
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "1 buffer argument expected"));
    }
    
    return MP_OBJ_FROM_PTR(p_self);
}

/**********************************************************************
 *
 *  uPy getters for method "getTelemtryLogInclusionMasks" response args
 *
 **********************************************************************/
STATIC mp_obj_t resp_getTelemtryLogInclusionMasks_get_adcsErrorCode(mp_obj_t self_in) 
{
    const resp_getTelemtryLogInclusionMasks_class_obj_t *p_resp_data = ((resp_getTelemtryLogInclusionMasks_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return mp_obj_new_int((mp_int_t) p_resp_data->class_data.data.tAdcsErrorCode);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getTelemtryLogInclusionMasks_get_adcsErrorCode_obj, resp_getTelemtryLogInclusionMasks_get_adcsErrorCode);

STATIC mp_obj_t resp_getTelemtryLogInclusionMasks_get_returnVal(mp_obj_t self_in) 
{
    const resp_getTelemtryLogInclusionMasks_class_obj_t *p_resp_data = ((resp_getTelemtryLogInclusionMasks_class_obj_t *) MP_OBJ_TO_PTR(self_in));
    
    return TelemtryLogInclusionMasks_make_from_buf(mp_obj_new_bytearray(sizeof(CUBEADCS_GEN2_CUBECOMPUTERCOMMON3_TelemtryLogInclusionMasks_t), (const uint8_t *) &p_resp_data->class_data.data.sReturnVal));
}

STATIC MP_DEFINE_CONST_FUN_OBJ_1(resp_getTelemtryLogInclusionMasks_get_returnVal_obj, resp_getTelemtryLogInclusionMasks_get_returnVal);

// Define a dictionary to hold the class's methods
STATIC const mp_rom_map_elem_t resp_getTelemtryLogInclusionMasks_locals_dict_table[2] = {
    { MP_ROM_QSTR(MP_QSTR_get_adcsErrorCode), MP_ROM_PTR(&resp_getTelemtryLogInclusionMasks_get_adcsErrorCode_obj) },
    { MP_ROM_QSTR(MP_QSTR_get_returnVal), MP_ROM_PTR(&resp_getTelemtryLogInclusionMasks_get_returnVal_obj) },
};

STATIC MP_DEFINE_CONST_DICT(resp_getTelemtryLogInclusionMasks_locals_dict, resp_getTelemtryLogInclusionMasks_locals_dict_table);    

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_type_CubeADCS_Gen2_CubeComputerCommon3getTelemtryLogInclusionMasksResponseData,
    MP_QSTR_resp_getTelemtryLogInclusionMasks,
    MP_TYPE_FLAG_NONE,
    make_new, resp_getTelemtryLogInclusionMasks_make_new,
    locals_dict, (mp_obj_dict_t*)&resp_getTelemtryLogInclusionMasks_locals_dict    
);


/**********************************************************************
 *
 *  uPy function reference definitions
 *
 **********************************************************************/
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_setPassThrough_obj, 2, req_setPassThrough);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_setPowerState_obj, 2, req_setPowerState);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_setImageTransferSetup_obj, 2, req_setImageTransferSetup);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_setImageFileInfoReset_obj, 1, req_setImageFileInfoReset);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_setPortMap_obj, 2, req_setPortMap);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_setEraseLogData_obj, 2, req_setEraseLogData);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_setEventLogFilterTransferSetup_obj, 2, req_setEventLogFilterTransferSetup);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_setTelemetryLogTransferSetup_obj, 2, req_setTelemetryLogTransferSetup);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_setDummyEvent_obj, 2, req_setDummyEvent);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_setUnsolicitedEventSetup_obj, 2, req_setUnsolicitedEventSetup);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_setUnsolicitedTlmSetup_obj, 2, req_setUnsolicitedTlmSetup);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_getPassThrough_obj, 1, req_getPassThrough);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_getPowerState_obj, 1, req_getPowerState);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_getPortDiagnostics_obj, 1, req_getPortDiagnostics);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_getPortMap_obj, 1, req_getPortMap);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_getExpectedNodes_obj, 1, req_getExpectedNodes);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_getImageTransferStatus_obj, 1, req_getImageTransferStatus);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_getImageFileInfo_obj, 1, req_getImageFileInfo);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_getComponentErrorCodes_obj, 1, req_getComponentErrorCodes);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_getEventLogStatus_obj, 1, req_getEventLogStatus);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_getTelemtryLogStatus_obj, 1, req_getTelemtryLogStatus);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_getUnsolicitedEventSetup_obj, 1, req_getUnsolicitedEventSetup);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_getUnsolicitedTlmSetup_obj, 1, req_getUnsolicitedTlmSetup);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(req_getTelemtryLogInclusionMasks_obj, 1, req_getTelemtryLogInclusionMasks);

STATIC const mp_rom_map_elem_t upy_cubeadcs_gen2_cubecomputercommon3_module_globals_table[97] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_upy_cubeadcs_gen2_cubecomputercommon3) },
    // export FIDL methods
    // export request serializer function for method 'setPassThrough'
    { MP_ROM_QSTR(MP_QSTR_req_setPassThrough), MP_ROM_PTR(&req_setPassThrough_obj) },
    // export class for method 'setPassThrough' response
    { MP_ROM_QSTR(MP_QSTR_resp_setPassThrough), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3setPassThroughResponseData) },
    // export request serializer function for method 'setPowerState'
    { MP_ROM_QSTR(MP_QSTR_req_setPowerState), MP_ROM_PTR(&req_setPowerState_obj) },
    // export class for method 'setPowerState' response
    { MP_ROM_QSTR(MP_QSTR_resp_setPowerState), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3setPowerStateResponseData) },
    // export request serializer function for method 'setImageTransferSetup'
    { MP_ROM_QSTR(MP_QSTR_req_setImageTransferSetup), MP_ROM_PTR(&req_setImageTransferSetup_obj) },
    // export class for method 'setImageTransferSetup' response
    { MP_ROM_QSTR(MP_QSTR_resp_setImageTransferSetup), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3setImageTransferSetupResponseData) },
    // export request serializer function for method 'setImageFileInfoReset'
    { MP_ROM_QSTR(MP_QSTR_req_setImageFileInfoReset), MP_ROM_PTR(&req_setImageFileInfoReset_obj) },
    // export class for method 'setImageFileInfoReset' response
    { MP_ROM_QSTR(MP_QSTR_resp_setImageFileInfoReset), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3setImageFileInfoResetResponseData) },
    // export request serializer function for method 'setPortMap'
    { MP_ROM_QSTR(MP_QSTR_req_setPortMap), MP_ROM_PTR(&req_setPortMap_obj) },
    // export class for method 'setPortMap' response
    { MP_ROM_QSTR(MP_QSTR_resp_setPortMap), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3setPortMapResponseData) },
    // export request serializer function for method 'setEraseLogData'
    { MP_ROM_QSTR(MP_QSTR_req_setEraseLogData), MP_ROM_PTR(&req_setEraseLogData_obj) },
    // export class for method 'setEraseLogData' response
    { MP_ROM_QSTR(MP_QSTR_resp_setEraseLogData), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3setEraseLogDataResponseData) },
    // export request serializer function for method 'setEventLogFilterTransferSetup'
    { MP_ROM_QSTR(MP_QSTR_req_setEventLogFilterTransferSetup), MP_ROM_PTR(&req_setEventLogFilterTransferSetup_obj) },
    // export class for method 'setEventLogFilterTransferSetup' response
    { MP_ROM_QSTR(MP_QSTR_resp_setEventLogFilterTransferSetup), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3setEventLogFilterTransferSetupResponseData) },
    // export request serializer function for method 'setTelemetryLogTransferSetup'
    { MP_ROM_QSTR(MP_QSTR_req_setTelemetryLogTransferSetup), MP_ROM_PTR(&req_setTelemetryLogTransferSetup_obj) },
    // export class for method 'setTelemetryLogTransferSetup' response
    { MP_ROM_QSTR(MP_QSTR_resp_setTelemetryLogTransferSetup), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3setTelemetryLogTransferSetupResponseData) },
    // export request serializer function for method 'setDummyEvent'
    { MP_ROM_QSTR(MP_QSTR_req_setDummyEvent), MP_ROM_PTR(&req_setDummyEvent_obj) },
    // export class for method 'setDummyEvent' response
    { MP_ROM_QSTR(MP_QSTR_resp_setDummyEvent), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3setDummyEventResponseData) },
    // export request serializer function for method 'setUnsolicitedEventSetup'
    { MP_ROM_QSTR(MP_QSTR_req_setUnsolicitedEventSetup), MP_ROM_PTR(&req_setUnsolicitedEventSetup_obj) },
    // export class for method 'setUnsolicitedEventSetup' response
    { MP_ROM_QSTR(MP_QSTR_resp_setUnsolicitedEventSetup), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3setUnsolicitedEventSetupResponseData) },
    // export request serializer function for method 'setUnsolicitedTlmSetup'
    { MP_ROM_QSTR(MP_QSTR_req_setUnsolicitedTlmSetup), MP_ROM_PTR(&req_setUnsolicitedTlmSetup_obj) },
    // export class for method 'setUnsolicitedTlmSetup' response
    { MP_ROM_QSTR(MP_QSTR_resp_setUnsolicitedTlmSetup), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3setUnsolicitedTlmSetupResponseData) },
    // export request serializer function for method 'getPassThrough'
    { MP_ROM_QSTR(MP_QSTR_req_getPassThrough), MP_ROM_PTR(&req_getPassThrough_obj) },
    // export class for method 'getPassThrough' response
    { MP_ROM_QSTR(MP_QSTR_resp_getPassThrough), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3getPassThroughResponseData) },
    // export request serializer function for method 'getPowerState'
    { MP_ROM_QSTR(MP_QSTR_req_getPowerState), MP_ROM_PTR(&req_getPowerState_obj) },
    // export class for method 'getPowerState' response
    { MP_ROM_QSTR(MP_QSTR_resp_getPowerState), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3getPowerStateResponseData) },
    // export request serializer function for method 'getPortDiagnostics'
    { MP_ROM_QSTR(MP_QSTR_req_getPortDiagnostics), MP_ROM_PTR(&req_getPortDiagnostics_obj) },
    // export class for method 'getPortDiagnostics' response
    { MP_ROM_QSTR(MP_QSTR_resp_getPortDiagnostics), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3getPortDiagnosticsResponseData) },
    // export request serializer function for method 'getPortMap'
    { MP_ROM_QSTR(MP_QSTR_req_getPortMap), MP_ROM_PTR(&req_getPortMap_obj) },
    // export class for method 'getPortMap' response
    { MP_ROM_QSTR(MP_QSTR_resp_getPortMap), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3getPortMapResponseData) },
    // export request serializer function for method 'getExpectedNodes'
    { MP_ROM_QSTR(MP_QSTR_req_getExpectedNodes), MP_ROM_PTR(&req_getExpectedNodes_obj) },
    // export class for method 'getExpectedNodes' response
    { MP_ROM_QSTR(MP_QSTR_resp_getExpectedNodes), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3getExpectedNodesResponseData) },
    // export request serializer function for method 'getImageTransferStatus'
    { MP_ROM_QSTR(MP_QSTR_req_getImageTransferStatus), MP_ROM_PTR(&req_getImageTransferStatus_obj) },
    // export class for method 'getImageTransferStatus' response
    { MP_ROM_QSTR(MP_QSTR_resp_getImageTransferStatus), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3getImageTransferStatusResponseData) },
    // export request serializer function for method 'getImageFileInfo'
    { MP_ROM_QSTR(MP_QSTR_req_getImageFileInfo), MP_ROM_PTR(&req_getImageFileInfo_obj) },
    // export class for method 'getImageFileInfo' response
    { MP_ROM_QSTR(MP_QSTR_resp_getImageFileInfo), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3getImageFileInfoResponseData) },
    // export request serializer function for method 'getComponentErrorCodes'
    { MP_ROM_QSTR(MP_QSTR_req_getComponentErrorCodes), MP_ROM_PTR(&req_getComponentErrorCodes_obj) },
    // export class for method 'getComponentErrorCodes' response
    { MP_ROM_QSTR(MP_QSTR_resp_getComponentErrorCodes), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3getComponentErrorCodesResponseData) },
    // export request serializer function for method 'getEventLogStatus'
    { MP_ROM_QSTR(MP_QSTR_req_getEventLogStatus), MP_ROM_PTR(&req_getEventLogStatus_obj) },
    // export class for method 'getEventLogStatus' response
    { MP_ROM_QSTR(MP_QSTR_resp_getEventLogStatus), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3getEventLogStatusResponseData) },
    // export request serializer function for method 'getTelemtryLogStatus'
    { MP_ROM_QSTR(MP_QSTR_req_getTelemtryLogStatus), MP_ROM_PTR(&req_getTelemtryLogStatus_obj) },
    // export class for method 'getTelemtryLogStatus' response
    { MP_ROM_QSTR(MP_QSTR_resp_getTelemtryLogStatus), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3getTelemtryLogStatusResponseData) },
    // export request serializer function for method 'getUnsolicitedEventSetup'
    { MP_ROM_QSTR(MP_QSTR_req_getUnsolicitedEventSetup), MP_ROM_PTR(&req_getUnsolicitedEventSetup_obj) },
    // export class for method 'getUnsolicitedEventSetup' response
    { MP_ROM_QSTR(MP_QSTR_resp_getUnsolicitedEventSetup), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3getUnsolicitedEventSetupResponseData) },
    // export request serializer function for method 'getUnsolicitedTlmSetup'
    { MP_ROM_QSTR(MP_QSTR_req_getUnsolicitedTlmSetup), MP_ROM_PTR(&req_getUnsolicitedTlmSetup_obj) },
    // export class for method 'getUnsolicitedTlmSetup' response
    { MP_ROM_QSTR(MP_QSTR_resp_getUnsolicitedTlmSetup), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3getUnsolicitedTlmSetupResponseData) },
    // export request serializer function for method 'getTelemtryLogInclusionMasks'
    { MP_ROM_QSTR(MP_QSTR_req_getTelemtryLogInclusionMasks), MP_ROM_PTR(&req_getTelemtryLogInclusionMasks_obj) },
    // export class for method 'getTelemtryLogInclusionMasks' response
    { MP_ROM_QSTR(MP_QSTR_resp_getTelemtryLogInclusionMasks), MP_ROM_PTR(&mp_type_CubeADCS_Gen2_CubeComputerCommon3getTelemtryLogInclusionMasksResponseData) },
    // export enumeration class for type 'CubeComputerCommon3_ImageTransferOpCode'
    { MP_ROM_QSTR(MP_QSTR_CubeComputerCommon3_ImageTransferOpCode), MP_ROM_PTR(&cubecomputercommon3_imagetransferopcode_class_type) },                        
    // export enumeration class for type 'CubeComputerCommon3_LogReadFilterType'
    { MP_ROM_QSTR(MP_QSTR_CubeComputerCommon3_LogReadFilterType), MP_ROM_PTR(&cubecomputercommon3_logreadfiltertype_class_type) },                        
    // export enumeration class for type 'CubeComputerCommon3_TlmLogReturnIntervalValues'
    { MP_ROM_QSTR(MP_QSTR_CubeComputerCommon3_TlmLogReturnIntervalValues), MP_ROM_PTR(&cubecomputercommon3_tlmlogreturnintervalvalues_class_type) },                        
    // export enumeration class for type 'CubeComputerCommon3_EventClass'
    { MP_ROM_QSTR(MP_QSTR_CubeComputerCommon3_EventClass), MP_ROM_PTR(&cubecomputercommon3_eventclass_class_type) },                        
    // export enumeration class for type 'CommonFrameworkTypes1_NodeType'
    { MP_ROM_QSTR(MP_QSTR_CommonFrameworkTypes1_NodeType), MP_ROM_PTR(&commonframeworktypes1_nodetype_class_type) },                        
    // export enumeration class for type 'CubeComputerCommon3_PowerSelect'
    { MP_ROM_QSTR(MP_QSTR_CubeComputerCommon3_PowerSelect), MP_ROM_PTR(&cubecomputercommon3_powerselect_class_type) },                        
    // export enumeration class for type 'CubeComputerCommon3_EraseMagicNumbers'
    { MP_ROM_QSTR(MP_QSTR_CubeComputerCommon3_EraseMagicNumbers), MP_ROM_PTR(&cubecomputercommon3_erasemagicnumbers_class_type) },                        
    // export enumeration class for type 'CubeComputerCommon3_TlmLogReadQueueState'
    { MP_ROM_QSTR(MP_QSTR_CubeComputerCommon3_TlmLogReadQueueState), MP_ROM_PTR(&cubecomputercommon3_tlmlogreadqueuestate_class_type) },                        
    // export enumeration class for type 'CommonFrameworkTypes1_AbstractNode'
    { MP_ROM_QSTR(MP_QSTR_CommonFrameworkTypes1_AbstractNode), MP_ROM_PTR(&commonframeworktypes1_abstractnode_class_type) },                        
    // export enumeration class for type 'CubeComputerCommon3_ImageTransferState'
    { MP_ROM_QSTR(MP_QSTR_CubeComputerCommon3_ImageTransferState), MP_ROM_PTR(&cubecomputercommon3_imagetransferstate_class_type) },                        
    // export enumeration class for type 'CmdTargetNode'
    { MP_ROM_QSTR(MP_QSTR_CmdTargetNode), MP_ROM_PTR(&cmdtargetnode_class_type) },                        
    // export enumeration class for type 'CubeComputerCommon3_EventReadQueueState'
    { MP_ROM_QSTR(MP_QSTR_CubeComputerCommon3_EventReadQueueState), MP_ROM_PTR(&cubecomputercommon3_eventreadqueuestate_class_type) },                        
    // export struct class objects for type 'PortDiagnostics'
    { MP_ROM_QSTR(MP_QSTR_PortDiagnostics_make_from_buf), MP_ROM_PTR(&PortDiagnostics_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_PortDiagnostics), MP_ROM_PTR(&PortDiagnostics_type)},
    // export struct class objects for type 'ComponentErrorCodes'
    { MP_ROM_QSTR(MP_QSTR_ComponentErrorCodes_make_from_buf), MP_ROM_PTR(&ComponentErrorCodes_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_ComponentErrorCodes), MP_ROM_PTR(&ComponentErrorCodes_type)},
    // export struct class objects for type 'TelemtryLogInclusionMasks'
    { MP_ROM_QSTR(MP_QSTR_TelemtryLogInclusionMasks_make_from_buf), MP_ROM_PTR(&TelemtryLogInclusionMasks_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_TelemtryLogInclusionMasks), MP_ROM_PTR(&TelemtryLogInclusionMasks_type)},
    // export struct class objects for type 'UnsolicitedEventSetup'
    { MP_ROM_QSTR(MP_QSTR_UnsolicitedEventSetup_make_from_buf), MP_ROM_PTR(&UnsolicitedEventSetup_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_UnsolicitedEventSetup), MP_ROM_PTR(&UnsolicitedEventSetup_type)},
    // export struct class objects for type 'EventLogFilterTransferSetup'
    { MP_ROM_QSTR(MP_QSTR_EventLogFilterTransferSetup_make_from_buf), MP_ROM_PTR(&EventLogFilterTransferSetup_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_EventLogFilterTransferSetup), MP_ROM_PTR(&EventLogFilterTransferSetup_type)},
    // export struct class objects for type 'TelemetryLogTransferSetup'
    { MP_ROM_QSTR(MP_QSTR_TelemetryLogTransferSetup_make_from_buf), MP_ROM_PTR(&TelemetryLogTransferSetup_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_TelemetryLogTransferSetup), MP_ROM_PTR(&TelemetryLogTransferSetup_type)},
    // export struct class objects for type 'UnsolicitedTlmSetup'
    { MP_ROM_QSTR(MP_QSTR_UnsolicitedTlmSetup_make_from_buf), MP_ROM_PTR(&UnsolicitedTlmSetup_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_UnsolicitedTlmSetup), MP_ROM_PTR(&UnsolicitedTlmSetup_type)},
    // export struct class objects for type 'PowerState'
    { MP_ROM_QSTR(MP_QSTR_PowerState_make_from_buf), MP_ROM_PTR(&PowerState_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_PowerState), MP_ROM_PTR(&PowerState_type)},
    // export struct class objects for type 'EraseLogData'
    { MP_ROM_QSTR(MP_QSTR_EraseLogData_make_from_buf), MP_ROM_PTR(&EraseLogData_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_EraseLogData), MP_ROM_PTR(&EraseLogData_type)},
    // export struct class objects for type 'TelemtryLogStatus'
    { MP_ROM_QSTR(MP_QSTR_TelemtryLogStatus_make_from_buf), MP_ROM_PTR(&TelemtryLogStatus_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_TelemtryLogStatus), MP_ROM_PTR(&TelemtryLogStatus_type)},
    // export struct class objects for type 'PortMap'
    { MP_ROM_QSTR(MP_QSTR_PortMap_make_from_buf), MP_ROM_PTR(&PortMap_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_PortMap), MP_ROM_PTR(&PortMap_type)},
    // export struct class objects for type 'ImageFileInfo'
    { MP_ROM_QSTR(MP_QSTR_ImageFileInfo_make_from_buf), MP_ROM_PTR(&ImageFileInfo_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_ImageFileInfo), MP_ROM_PTR(&ImageFileInfo_type)},
    // export struct class objects for type 'ImageTransferSetup'
    { MP_ROM_QSTR(MP_QSTR_ImageTransferSetup_make_from_buf), MP_ROM_PTR(&ImageTransferSetup_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_ImageTransferSetup), MP_ROM_PTR(&ImageTransferSetup_type)},
    // export struct class objects for type 'PassThrough'
    { MP_ROM_QSTR(MP_QSTR_PassThrough_make_from_buf), MP_ROM_PTR(&PassThrough_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_PassThrough), MP_ROM_PTR(&PassThrough_type)},
    // export struct class objects for type 'DummyEvent'
    { MP_ROM_QSTR(MP_QSTR_DummyEvent_make_from_buf), MP_ROM_PTR(&DummyEvent_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_DummyEvent), MP_ROM_PTR(&DummyEvent_type)},
    // export struct class objects for type 'ExpectedNodes'
    { MP_ROM_QSTR(MP_QSTR_ExpectedNodes_make_from_buf), MP_ROM_PTR(&ExpectedNodes_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_ExpectedNodes), MP_ROM_PTR(&ExpectedNodes_type)},
    // export struct class objects for type 'ImageTransferStatus'
    { MP_ROM_QSTR(MP_QSTR_ImageTransferStatus_make_from_buf), MP_ROM_PTR(&ImageTransferStatus_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_ImageTransferStatus), MP_ROM_PTR(&ImageTransferStatus_type)},
    // export struct class objects for type 'EventLogStatus'
    { MP_ROM_QSTR(MP_QSTR_EventLogStatus_make_from_buf), MP_ROM_PTR(&EventLogStatus_make_from_buf_obj) },                        
    { MP_ROM_QSTR(MP_QSTR_EventLogStatus), MP_ROM_PTR(&EventLogStatus_type)},
};

/**********************************************************************
 *
 *  uPy C module registration
 *
 **********************************************************************/
STATIC MP_DEFINE_CONST_DICT(upy_cubeadcs_gen2_cubecomputercommon3_module_globals,
                            upy_cubeadcs_gen2_cubecomputercommon3_module_globals_table);

const mp_obj_module_t upy_cubeadcs_gen2_cubecomputercommon3_user_cmodule = {
    .base    = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&upy_cubeadcs_gen2_cubecomputercommon3_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_upy_cubeadcs_gen2_cubecomputercommon3, upy_cubeadcs_gen2_cubecomputercommon3_user_cmodule);
