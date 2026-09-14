from typing import Optional

#
# ESPS standard bus identifiers
#
ESPS_SYS_BUS_ID = 0

#
# Comm GW result codes
#
COMM_GW_RES_OK = 0
COMM_GW_RES_OK_PARTIAL = 1
COMM_GW_RES_ERR = 2
COMM_GW_RES_INVALID_ARGS = 3
COMM_GW_RES_SEND_ERR = 4
COMM_GW_RES_SND_TIMEOUT = 5
COMM_GW_RES_RCV_TIMEOUT = 6

#
# FP send priority codes
#
FP_PRIO_CRITICAL = 1
FP_PRIO_HIGH = 3
FP_PRIO_NORMAL = 7
FP_PRIO_LOW = 13

#
# CSP local address
#
CSP_LOCAL_ADDR = 1

#
# CSP send priority codes
#
CSP_PRIO_CRITICAL = 0
CSP_PRIO_HIGH = 1
CSP_PRIO_NORMAL = 2
CSP_PRIO_LOW = 3

#
# CSP connection option flags (bit-field masks)
#
CSP_O_NONE = 0x0000
CSP_O_RDP = 0x0001
CSP_O_NORDP = 0x0002
CSP_O_HMAC = 0x0004
CSP_O_NOHMAC = 0x0008
CSP_O_XTEA = 0x0010
CSP_O_NOXTEA = 0x0020
CSP_O_CRC32 = 0x0040
CSP_O_NOCRC32 = 0x0080
CSP_SO_CONN_LESS = 0x0100

#
# Supported CP command IDs
#
CP_CMD_ID_FAULT_READ_ALL = 1027
CP_CMD_ID_SXBAND_GWSEND = 1200
CP_CMD_ID_CUBEADCS_GWSEND = 1202
CP_CMD_ID_SXBAND_SCHED_RUN =  1451
CP_CMD_ID_SXBAND_SCHED_POLL = 1452
CP_CMD_ID_CUBEADCS_GEN2_GWSEND = 2000

def fp_send(req_buf : bytes,
            resp_buf : bytearray,
            target_node_addr : Optional[int],
            mac_if_id : Optional[int] = ESPS_SYS_BUS_ID,
            send_prio : Optional[int] = FP_PRIO_NORMAL,
            resp_timeout_ms : Optional[int] = 4000) -> tuple[int, int]:
    """
    Send a local ESPS FP request for execution or a remote request to an external node on the ESPS bus.

    The function is blocking and will return latest after resp_timeout_ms milliseconds or earlier in case of faster execution.

    Parameters
    ----------
    :param req_buf: Request buffer containing a raw FP frame (this is usually the result of a generated FIDL Python ``req_*`` API)
    :param resp_buf: A buffer to receive the node response. The buffer must be allocated by the script developer in advance, e.g.
            ``buffer_size = 200``
            ``resp_buf = bytearray(buffer_size)``
        If the buffer size is not sufficient to accept the full response, the function will return COMM_GW_RES_OK_PARTIAL status.
    :param target_node_addr: Node address to send the request to. If skipped, the local node address will be used and the request will not be
        forwarded on the external ESPS bus.
    :param mac_if_id: MAC physical interface ID to send the request through (in case multiple interfaces are supported)
    :param send_prio: Request send priority on the ESPS bus
    :param resp_timeout_ms: Number of milliseconds to wait for the reception of the response. After this time, the function returns COMM_GW_RES_RCV_TIMEOUT status.

    :returns:
        tuple[0] -> operation status (one of the COMM_GW_RES_* result codes defined above)
        tuple[1] -> size of the provided response in resp_buf
    """
    return (COMM_GW_RES_OK, 0)

def csp_send(req_buf : bytes,
            resp_buf : bytearray,
            target_node_addr : int,
            target_port : int,
            send_prio : Optional[int] = CSP_PRIO_NORMAL,
            conn_opts : Optional[int] = CSP_O_NONE,
            resp_timeout_ms : Optional[int] = 4000) -> tuple[int, int]:
    """
    Send a CSP request to an external node or for loopback execution (in case own CSP node address is specified, i.e. CSP_LOCAL_ADDR).

    The function is blocking and will return latest after resp_timeout_ms milliseconds or earlier in case of faster execution.

    Parameters
    ----------
    :param req_buf: Request buffer containing a raw FP frame (this is usually the result of a generated FIDL Python ``req_*`` API)
    :param resp_buf: A buffer to receive the node response. The buffer must be allocated by the script developer in advance, e.g.
            ``buffer_size = 200``
            ``resp_buf = bytearray(buffer_size)``
        If the buffer size is not sufficient to accept the full response, the function will return COMM_GW_RES_OK_PARTIAL status.
    :param target_node_addr: Node address to send the request to. If skipped, the local node address will be used and the request will not be
        forwarded on the external ESPS bus.
    :param target_port: target CSP port
    :param send_prio: CSP request send priority (see CSP_PRIO_* constants for available options)
    :param conn_opts: CSP connection options (see CSP_O_* constants for available options - bit-wise OR combinations of values are possible)
    :param resp_timeout_ms: Number of milliseconds to wait for the reception of the response. After this time, the function returns COMM_GW_RES_RCV_TIMEOUT status.

    :returns:
        tuple[0] -> operation status (one of the COMM_GW_RES_* result codes defined above)
        tuple[1] -> size of the provided response in resp_buf
    """
    return (COMM_GW_RES_OK, 0)

def cp_send(req_buf : bytes,
            resp_buf : bytearray,
            cmd_id : int,
            resp_timeout_ms : Optional[int] = 4000) -> tuple[int, int]:
    """
    Inject a CP command and execute locally on the OBC.

    The function is blocking and will return latest after resp_timeout_ms milliseconds or earlier in case of faster execution.

    Parameters
    ----------
    :param req_buf: Request buffer containing a raw FP frame (this is usually the result of a generated FIDL Python ``req_*`` API)
    :param resp_buf: A buffer to receive the node response. The buffer must be allocated by the script developer in advance, e.g.
            ``buffer_size = 200``
            ``resp_buf = bytearray(buffer_size)``
        If the buffer size is not sufficient to accept the full response, the function will return COMM_GW_RES_OK_PARTIAL status.
    :param cmd_id: CP command identifier
    :param resp_timeout_ms: Number of milliseconds to wait for the reception of the response. After this time, the function returns COMM_GW_RES_RCV_TIMEOUT status.

    :returns:
        tuple[0] -> operation status (one of the COMM_GW_RES_* result codes defined above)
        tuple[1] -> size of the provided response in resp_buf
    """
    return (COMM_GW_RES_OK, 0)
