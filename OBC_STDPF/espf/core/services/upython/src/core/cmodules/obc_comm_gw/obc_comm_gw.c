/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#include "upy_cfg.h"
#include "py/runtime.h"
#include "esps_drv_config.h"
#include "core/services/comm_gw/inc/comm_gw.h"
#include "config/csp/inc/csp_service_cfg.h"
#include "csp_access.h"
#include "ESCP_CommandsLocalConf.h"

#define DEF_MAC_IF_ID       ((const eMACInterface_t)ESSASNI_SYS_PRI) /**< default MAC interface to use for the FP send operation */
#define DEF_RESP_TIMEOUT_MS (4000UL)                                 /**< default time period to wait before timing out the response */

/**
 * @brief Send an FP request from a uPy script
 *
 * If the optional parameters are not specified, appropriate default values are assumed. If none of the optional
 * parameters are specified, the function executes the request locally and no outside bus communication is performed.
 *
 * @param[in] n_args number of uPy function arguments passed by the script user
 * @param[in/out] p_args uPy script function argument pointers
 *  p_args[0] (mandatory) an object containing the FP data buffer to send as a request
 *  p_args[1] (mandatory) buffer an object providing where the FP response buffer shall be stored
 *            after calling the requested FP command (the actual response buffer storage shall be
 *            reserved on the uPy heap by the script developer)
 *  p_args[2] (optional) target ESPS node address (default value: local node address)
 *  p_args[3] (optional) MAC interface ID to send the request through   (default value: DEF_MAC_IF_ID)
 *  p_args[4] (optional) ESPS request frame priority (default value: ESSASMP_NORMAL)
 *  p_args[5] (optional) number of milliseconds to wait for response before timing out (default value: DEF_FP_RESP_TIMEOUT_MS)
 *
 * @return result of the command execution formatted as a Python tuple:
 * (op status: int, response size in bytes: int)
 *
 */
STATIC mp_obj_t obc_fp_gw_send(size_t n_args, const mp_obj_t *p_args)
{
    mp_buffer_info_t         py_req_data;
    mp_buffer_info_t         py_resp_data;
    comm_gw_comm_res_t       res = COMM_GW_RES_ERR;
    comm_gw_send_ctx_t       send_params;
    comm_gw_fp_comm_params_t fp_comm_params;
    mp_obj_t                 tuple_res[2];
    uint32_t                 gw_resp_size = 0UL;

    if (n_args < 2)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 2 arguments expected"));
    }

    if ((true == mp_get_buffer(p_args[0], &py_req_data, MP_BUFFER_READ)) &&
        (true == mp_get_buffer(p_args[1], &py_resp_data, MP_BUFFER_WRITE)))
    {
        uint8_t local_mac_addr = MacCfg_u8GetMacAddress(DEF_MAC_IF_ID);

        send_params.p_req_data         = py_req_data.buf;
        send_params.req_data_size      = (uint32_t)py_req_data.len;
        send_params.p_resp_data        = py_resp_data.buf;
        send_params.resp_data_max_size = (uint32_t)py_resp_data.len;
        send_params.p_resp_data_size   = &gw_resp_size;

        // get optional args
        fp_comm_params.target_node_addr = (n_args >= 3) ? (uint8_t)mp_obj_get_int(p_args[2]) : local_mac_addr;
        fp_comm_params.mac_if_id        = (n_args >= 4) ? (uint8_t)mp_obj_get_int(p_args[3]) : DEF_MAC_IF_ID;
        fp_comm_params.msg_prio         = (n_args >= 5) ? (ESSATMAC_MsgPriority)mp_obj_get_int(p_args[4]) : ESSASMP_NORMAL;

        // using a local stack pointer here is safe because the comm_gw_send() function is blocking and will not return control
        // until it finishes
        send_params.p_comm_params = &fp_comm_params;

        send_params.resp_timeout = (n_args >= 6) ? (uint32_t)mp_obj_get_int(p_args[5]) : DEF_RESP_TIMEOUT_MS;

        res = comm_gw_send(COMM_GW_IF_ID_FP, COMM_GW_USER_ID_UPY, &send_params);
    }

    tuple_res[0] = mp_obj_new_int((mp_int_t)res);
    tuple_res[1] = mp_obj_new_int((mp_int_t)gw_resp_size);

    return mp_obj_new_tuple(CDEF_ELEMENT_COUNT(tuple_res), tuple_res);
}

/**
 * @brief Send a CSP request from a uPy script
 *
 * If the optional parameters are not specified, appropriate default values are assumed. If none of the optional
 * parameters are specified, the function executes the request locally and no outside bus communication is performed.
 *
 * @param[in] n_args number of uPy function arguments passed by the script user
 * @param[in/out] p_args uPy script function argument pointers
 *  p_args[0] (mandatory) an object containing the CSP data buffer to send as a request
 *  p_args[1] (mandatory) buffer an object providing where the CSP response buffer shall be stored
 *            after calling the requested CSP command (the actual response buffer storage shall be
 *            reserved on the uPy heap by the script developer)
 *  p_args[2] (mandatory) target CSP node address
 *  p_args[3] (mandatory) target CSP port
 *  p_args[4] (optional) CSP request frame priority (default value: CSP_PRIO_NORM)
 *  p_args[5] (optional) CSP connection flags (default value: CSP_O_NONE)
 *  p_args[6] (optional) number of milliseconds to wait for response before timing out (default value: DEF_FP_RESP_TIMEOUT_MS)
 *
 * @return result of the command execution formatted as a Python tuple:
 * (op status: int, response size in bytes: int)
 *
 */
STATIC mp_obj_t obc_csp_gw_send(size_t n_args, const mp_obj_t *p_args)
{
    mp_buffer_info_t          py_req_data;
    mp_buffer_info_t          py_resp_data;
    comm_gw_comm_res_t        res = COMM_GW_RES_ERR;
    comm_gw_send_ctx_t        send_params;
    comm_gw_csp_comm_params_t csp_comm_params;
    mp_obj_t                  tuple_res[2];
    uint32_t                  gw_resp_size = 0UL;

    if (n_args < 4)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 4 arguments expected"));
    }

    if ((true == mp_get_buffer(p_args[0], &py_req_data, MP_BUFFER_READ)) &&
        (true == mp_get_buffer(p_args[1], &py_resp_data, MP_BUFFER_WRITE)))
    {
        send_params.p_req_data         = py_req_data.buf;
        send_params.req_data_size      = (uint32_t)py_req_data.len;
        send_params.p_resp_data        = py_resp_data.buf;
        send_params.resp_data_max_size = (uint32_t)py_resp_data.len;
        send_params.p_resp_data_size   = &gw_resp_size;

        csp_comm_params.target_node_addr = (uint8_t)mp_obj_get_int(p_args[2]);
        csp_comm_params.port             = (uint8_t)mp_obj_get_int(p_args[3]);

        // get optional args
        csp_comm_params.prio = (n_args >= 5) ? (uint8_t)mp_obj_get_int(p_args[4]) : CSP_PRIO_NORM;
        csp_comm_params.opts = (n_args >= 6) ? (uint32_t)mp_obj_get_int(p_args[5]) : (uint32_t)CSP_O_NONE;

        // using a local stack pointer here is safe because the comm_gw_send() function is blocking and will not return control
        // until it finishes
        send_params.p_comm_params = &csp_comm_params;

        send_params.resp_timeout = (n_args >= 7) ? (uint32_t)mp_obj_get_int(p_args[6]) : DEF_RESP_TIMEOUT_MS;

        res = comm_gw_send(COMM_GW_IF_ID_CSP, COMM_GW_USER_ID_UPY, &send_params);
    }

    tuple_res[0] = mp_obj_new_int((mp_int_t)res);
    tuple_res[1] = mp_obj_new_int((mp_int_t)gw_resp_size);

    return mp_obj_new_tuple(CDEF_ELEMENT_COUNT(tuple_res), tuple_res);
}

/**
 * @brief Send a local CP request from a uPy script
 *
 * If the optional parameters are not specified, appropriate default values are assumed.
 *
 * @param[in] n_args number of uPy function arguments passed by the script user
 * @param[in/out] p_args uPy script function argument pointers
 *  p_args[0] (mandatory) CP command identifier
 *  p_args[1] (mandatory) an object containing the FP data buffer to send as a request
 *  p_args[2] (mandatory) buffer an object providing where the CP response buffer shall be stored
 *            after calling the requested CP command (the actual response buffer storage shall be
 *            reserved on the uPy heap by the script developer)
 *  p_args[3] (optional) number of milliseconds to wait for response before timing out (default value: DEF_FP_RESP_TIMEOUT_MS)
 *
 * @return result of the command execution formatted as a Python tuple:
 * (op status: int, response size in bytes: int)
 *
 */
STATIC mp_obj_t obc_cp_gw_send(size_t n_args, const mp_obj_t *p_args)
{
    mp_buffer_info_t         py_req_data;
    mp_buffer_info_t         py_resp_data;
    comm_gw_comm_res_t       res = COMM_GW_RES_ERR;
    comm_gw_send_ctx_t       send_params;
    comm_gw_cp_comm_params_t cp_comm_params;
    mp_obj_t                 tuple_res[2];
    uint32_t                 gw_resp_size = 0UL;

    if (n_args < 3)
    {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, "At least 3 arguments expected"));
    }

    if ((true == mp_get_buffer(p_args[0], &py_req_data, MP_BUFFER_READ)) &&
        (true == mp_get_buffer(p_args[1], &py_resp_data, MP_BUFFER_WRITE)))
    {
        send_params.p_req_data         = py_req_data.buf;
        send_params.req_data_size      = (uint32_t)py_req_data.len;
        send_params.p_resp_data        = py_resp_data.buf;
        send_params.resp_data_max_size = (uint32_t)py_resp_data.len;
        send_params.p_resp_data_size   = &gw_resp_size;

        cp_comm_params.cmd_id = (uint32_t)mp_obj_get_int(p_args[2]);

        // using a local stack pointer here is safe because the comm_gw_send() function is blocking and will not return control
        // until it finishes
        send_params.p_comm_params = &cp_comm_params;

        send_params.resp_timeout = (n_args >= 4) ? (uint32_t)mp_obj_get_int(p_args[3]) : DEF_RESP_TIMEOUT_MS;

        res = comm_gw_send(COMM_GW_IF_ID_CP, COMM_GW_USER_ID_UPY, &send_params);
    }

    tuple_res[0] = mp_obj_new_int((mp_int_t)res);
    tuple_res[1] = mp_obj_new_int((mp_int_t)gw_resp_size);

    return mp_obj_new_tuple(CDEF_ELEMENT_COUNT(tuple_res), tuple_res);
}

// Define uPy references to the functions above
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(obc_fp_gw_send_obj, 2, 6, obc_fp_gw_send);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(obc_csp_gw_send_obj, 4, 7, obc_csp_gw_send);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(obc_cp_gw_send_obj, 3, 4, obc_cp_gw_send);

// Define all properties of the module.
// Table entries are key/value pairs of the attribute name (a string)
// and the MicroPython object reference.
// All identifiers and strings are written as MP_QSTR_xxx and will be
// optimized to word-sized integers by the build system (interned strings).
STATIC const mp_rom_map_elem_t obc_comm_gw_module_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__),                        MP_ROM_QSTR(MP_QSTR_obc_comm_gw)       },
 // FP-related uPy exports
    { MP_ROM_QSTR(MP_QSTR_fp_send),                        MP_ROM_PTR(&obc_fp_gw_send_obj)        },
 // export of the default ESPS system bus address
    { MP_ROM_QSTR(MP_QSTR_ESPS_SYS_BUS_ID),                MP_ROM_INT(DEF_MAC_IF_ID)              },
 // export all values of the @ref comm_gw_comm_res_t type (make sure to align in case of changes)
    { MP_ROM_QSTR(MP_QSTR_COMM_GW_RES_OK),                 MP_ROM_INT(COMM_GW_RES_OK)             },
    { MP_ROM_QSTR(MP_QSTR_COMM_GW_RES_OK_PARTIAL),         MP_ROM_INT(COMM_GW_RES_OK_PARTIAL)     },
    { MP_ROM_QSTR(MP_QSTR_COMM_GW_RES_ERR),                MP_ROM_INT(COMM_GW_RES_ERR)            },
    { MP_ROM_QSTR(MP_QSTR_COMM_GW_RES_INVALID_ARGS),       MP_ROM_INT(COMM_GW_RES_INVALID_ARGS)   },
    { MP_ROM_QSTR(MP_QSTR_COMM_GW_RES_SEND_ERR),           MP_ROM_INT(COMM_GW_RES_SEND_ERR)       },
    { MP_ROM_QSTR(MP_QSTR_COMM_GW_RES_SND_TIMEOUT),        MP_ROM_INT(COMM_GW_RES_SND_TIMEOUT)    },
    { MP_ROM_QSTR(MP_QSTR_COMM_GW_RES_RCV_TIMEOUT),        MP_ROM_INT(COMM_GW_RES_RCV_TIMEOUT)    },
 // export all values of ESSASMP_* send priorities (make sure to align in case of changes)
    { MP_ROM_QSTR(MP_QSTR_FP_PRIO_CRITICAL),               MP_ROM_INT(ESSASMP_CRITICAL)           },
    { MP_ROM_QSTR(MP_QSTR_FP_PRIO_HIGH),                   MP_ROM_INT(ESSASMP_HIGH)               },
    { MP_ROM_QSTR(MP_QSTR_FP_PRIO_NORMAL),                 MP_ROM_INT(ESSASMP_NORMAL)             },
    { MP_ROM_QSTR(MP_QSTR_FP_PRIO_LOW),                    MP_ROM_INT(ESSASMP_LOW)                },
 // CSP-related uPy exports
    { MP_ROM_QSTR(MP_QSTR_csp_send),                       MP_ROM_PTR(&obc_csp_gw_send_obj)       },
    { MP_ROM_QSTR(MP_QSTR_CSP_LOCAL_ADDR),                 MP_ROM_INT(CSP_SERVICE_CFG_OWN_ADDRESS)},
 // export all values of CSP_PRIO_* send priorities
    { MP_ROM_QSTR(MP_QSTR_CSP_PRIO_CRITICAL),              MP_ROM_INT(CSP_PRIO_CRITICAL)          },
    { MP_ROM_QSTR(MP_QSTR_CSP_PRIO_HIGH),                  MP_ROM_INT(CSP_PRIO_HIGH)              },
    { MP_ROM_QSTR(MP_QSTR_CSP_PRIO_NORMAL),                MP_ROM_INT(CSP_PRIO_NORM)              },
    { MP_ROM_QSTR(MP_QSTR_CSP_PRIO_LOW),                   MP_ROM_INT(CSP_PRIO_LOW)               },
 // export CSP connection options
    { MP_ROM_QSTR(MP_QSTR_CSP_O_NONE),                     MP_ROM_INT(CSP_O_NONE)                 },
    { MP_ROM_QSTR(MP_QSTR_CSP_O_RDP),                      MP_ROM_INT(CSP_O_RDP)                  },
    { MP_ROM_QSTR(MP_QSTR_CSP_O_NORDP),                    MP_ROM_INT(CSP_O_NORDP)                },
    { MP_ROM_QSTR(MP_QSTR_CSP_O_HMAC),                     MP_ROM_INT(CSP_O_HMAC)                 },
    { MP_ROM_QSTR(MP_QSTR_CSP_O_NOHMAC),                   MP_ROM_INT(CSP_O_NOHMAC)               },
    { MP_ROM_QSTR(MP_QSTR_CSP_O_XTEA),                     MP_ROM_INT(CSP_O_XTEA)                 },
    { MP_ROM_QSTR(MP_QSTR_CSP_O_NOXTEA),                   MP_ROM_INT(CSP_O_NOXTEA)               },
    { MP_ROM_QSTR(MP_QSTR_CSP_O_CRC32),                    MP_ROM_INT(CSP_O_CRC32)                },
    { MP_ROM_QSTR(MP_QSTR_CSP_O_NOCRC32),                  MP_ROM_INT(CSP_O_NOCRC32)              },
    { MP_ROM_QSTR(MP_QSTR_CSP_SO_CONN_LESS),               MP_ROM_INT(CSP_SO_CONN_LESS)           },
 // CP-related uPy exports
    { MP_ROM_QSTR(MP_QSTR_cp_send),                        MP_ROM_PTR(&obc_cp_gw_send_obj)        },
 // export the accessible CP command IDs
    { MP_ROM_QSTR(MP_QSTR_CP_CMD_ID_FAULT_READ_ALL),       MP_ROM_INT(CP_CMD_FAULT_READ_ALL)      },
    { MP_ROM_QSTR(MP_QSTR_CP_CMD_ID_SXBAND_GWSEND),        MP_ROM_INT(CP_CMD_SXBAND_GWSEND)       },
    { MP_ROM_QSTR(MP_QSTR_CP_CMD_ID_CUBEADCS_GWSEND),      MP_ROM_INT(CP_CMD_CUBEADCS_GWSEND)     },
#if defined(SXBAND_SCHEDULER_ENABLED)
    { MP_ROM_QSTR(MP_QSTR_CP_CMD_ID_SXBAND_SCHED_RUN),     MP_ROM_INT(CP_CMD_SXBAND_SCHED_RUN)    },
    { MP_ROM_QSTR(MP_QSTR_CP_CMD_ID_SXBAND_SCHED_POLL),    MP_ROM_INT(CP_CMD_SXBAND_SCHED_POLL)   },
#endif
#if defined(CUBEADCS_GEN2_ENABLED)
    { MP_ROM_QSTR(MP_QSTR_CP_CMD_ID_CUBEADCS_GEN2_GWSEND), MP_ROM_INT(CP_CMD_CUBEADCS_GEN2_GWSEND)},
#endif
};
STATIC MP_DEFINE_CONST_DICT(obc_comm_gw_module_globals,
                            obc_comm_gw_module_globals_table);

// Define module object.
const mp_obj_module_t obc_comm_gw_user_cmodule = {
    .base    = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&obc_comm_gw_module_globals,
};

// Register the module to make it available in Python.
MP_REGISTER_MODULE(MP_QSTR_obc_comm_gw, obc_comm_gw_user_cmodule);
