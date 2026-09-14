#ifndef ES_TFTP_PKT_CODES_H
#define ES_TFTP_PKT_CODES_H

/******************************** INCLUDE FILES *******************************/
#include "sdr_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

/** ES tftp opcode mnemonic */
typedef enum _es_tftp_opcode_t
{
    ES_TFTP_OPCODE_INVALID = 0,
    ES_TFTP_RRQ,   /**< Read request. Request a transfer of a file from the
                        server to the client */
    ES_TFTP_WRQ,   /**< Write request. Request a transfer of a file from the
                        client to the server */
    ES_TFTP_DATA,  /**< Data packet. */
    ES_TFTP_ACK,   /**< Acknowedge packet. */
    ES_TFTP_ERROR, /**< Error packet. */
    ES_TFTP_OPCODES
} es_tftp_opcode_t;

/** ES tftp Error Codes */
typedef enum _es_tftp_err_code_t
{
    ES_TFTP_ERR_NOT_DEFINED = 0,
    ES_TFTP_ERR_FILE_NOT_FOUND,                   /**< The client receives this error code when the
                                                       requested file does not exist. */
    ES_TFTP_ERR_ACESS_VIOLATION,                  /**< This error is seen when we ask for a file
                                                       on which we do not have the right to read or write. */
    ES_TFTP_ERR_DISK_FULL_OR_ALLOCATION_EXCEEDED, /**< TFTP client receives this
                                                       error when there is limited storage area on the server. */
    ES_TFTP_ERR_ILLEGAL_TFTP_OPERATION,           /**< Any TFTP packet does not follow the RFC is
                                                       called illegal. A packet with an unknown opcode, a packet with a malformed
                                                       payload, or a packet that is out of sequence with the normal
                                                       flow of commands/responses would all be considered "illegal" */
    ES_TFTP_ERR_UNKNOWN_TRANSFER_ID,              /**< When a TFTP client sends a duplicate read request
                                                       (typically this happens when the first read request times out),
                                                       the requests may create an unexpected situation on the server. */
    ES_TFTP_ERR_FILE_ALREADY_EXISTS,              /**  This error is received when there is a
                                                       file with the same name on the server. I produced this file with
                                                       transferring the same file to the server. */
    ES_TFTP_ERR_NO_SUCH_USER,                     /**< Unused
                                                       Once the protocol was first adopted, it supported three modes of transferring,
                                                       which were netascii, octet and mail mode, which was used for sending
                                                       files to an email address. This error is received when the recipient
                                                       username does not exist on the server. This mode is not used anymore.
                    
                                                       .. note:: We do not support the mode field */
    ES_TFTP_STATUS_OK,                            /**< No error. */
    ES_TFTP_TL_NOT_INIT,                          /**< Transport layer not initialized */
    ES_TFTP_CANNOT_OPEN_DEST_FILE_FOR_WRITE,      /**< Cannot open destination file for write */
    ES_TFTP_FAILED_TO_WRITE_TO_DEST_FILE,         /**< Failed to write to destination file */
    ES_TFTP_FAILED_TO_CLOSE_DEST_FILE,            /**< Failed to close destination file */
    ES_TFTP_CANNOT_OPEN_SOURCE_FILE_FOR_READ,     /**< Cannot open source file for read */
    ES_TFTP_FILE_NOT_FOUND_ON_SOURCE,             /**< File not found on source */
    ES_TFTP_FAILED_TO_READ_FROM_SOURCE_FILE,      /**< Failed to read from source file */
    ES_TFTP_FAILED_TO_CLOSE_SOURCE_FILE,          /**< Failed to close source file */
    ES_TFTP_CONNECTION_TO_SERVER_FAILED,          /**< Connection to server failed */
    ES_TFTP_FAILED_TO_DISCONNECT_FROM_SERVER,     /**< Failed to disconnect from server */
    ES_TFTP_RECV_FAILED,                          /**< Receive failed */
    ES_TFTP_SEND_FAILED,                          /**< Send failed */
    ES_TFTP_BLOCK_NUMBER_MISMATCH,                /**< Block number mismatch */
    ES_TFTP_DOWNLOADED_FILE_EMPTY,                /**< Successfully downloaded file, but it has zero size */
    ES_TFTP_TRANSFER_PENDING,                     /**< Transfer is pending */
    ES_TFTP_BUSY,                                 /**< Server is busy, there might be an ongoing transfer */
} es_tftp_err_code_t;

typedef enum
{
    ES_RPC_OK = 0,                              /**< RPC OK */
    ES_RPC_ERR,                                 /**< RPC Error */
    ES_RPC_INVALID_PARAMS,                      /**< RPC Invalid Parameters */
    ES_RPC_NOT_INITIALISED,                     /**< RPC Not Initialised */
    ES_RPC_NOT_SUPPORTED,                       /**< RPC Not Supported */
    ES_RPC_SEND_FAILED,                         /**< RPC Send Failed */
    ES_RPC_RECV_FAILED,                         /**< RPC Receive Failed */
    ES_RPC_ENCODE_FAILED,                       /**< RPC Encode Failed */
    ES_RPC_DECODE_FAILED,                       /**< RPC Decode Failed */
    ES_RPC_SERVICE_CONNECTION_STATUS_PARSE_ERR, /**< RPC Service Connection Status Parse Error */
} es_sdr_rpc_code_t;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // ES_TFTP_PKT_CODES_H
