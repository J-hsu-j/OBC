/*****************************************************************************
 * **File:** es_sdr_client.h
 *
 * **Description:** SDR API for command and control. This module initializes the
 * sdr library with a given transport layer and takes care of sending/receiving
 * commands to the SDR module. The `sdr-api` library expects that CSP has been
 * initialized and configured properly with a phyiscal interface.
 *
 * **Example Usage**
 *
 * .. code-block:: C
 *        :caption: Initialize & use the ES SDR Client module over CSP
 *        :linenos:
 *        :lineno-start: 1
 *        :name: <es_sdr_client>
 *
 *        es_loopback_req loopback_req = es_loopback_req_init_default;
 *        es_loopback_res loopback_res = es_loopback_res_init_default;
 *
 *        es_sdr_client_init();
 *        es_sdr_client_csp_tl_init(10);
 *        // Send the command
 *        es_sdr_client_rpc(ES_TEST_SERDES_ID, es_test_rpc_loopback_tag,
 *        &loopback_req, &loopback_res);
 *
 ****************************************************************************/
#ifndef __ES_CLIENT_H_INCLUDED__
#define __ES_CLIENT_H_INCLUDED__

#include <stdint.h>
#include "es_cdef.h"
#include "es_tftp_pkt_codes.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************** DEFINES **********************************/

/**
 * Ser/des of the IDs of each of the services supported by the es_sdr_client
 */
typedef enum _es_sdr_client_ser_des_handlers_t
{
    ES_TEST_SERDES_ID = 0,      /**< Test Service ID */
    ES_ADRV9009_SERDES_ID,      /**<  ADRV9009 Service ID */
    ES_BOARD_INFO_SERDES_ID,    /**< BOARD INFO Service ID */
    ES_IPRIUM_DVB_S2_SERDES_ID, /**< DVB S2 Service ID */
    ES_BOARD_MGR_SERDES_ID,     /**< Board Mgr Service ID */
    ES_RCE_SERDES_ID,           /**< Remote code execution ID */
    VYOMA_SERDES_ID,            /**< VYOMA Service ID */
    ES_SERVICES_SERDES_IDS,
} es_sdr_client_ser_des_handlers_t;

typedef struct _es_sdr_client_conn_t {
       void *descriptor;  /**< Connection descriptor */
       uint16_t dest_port;  /**< Destination port */
} es_sdr_client_conn_t;
#define es_sdr_client_conn_init_default {NULL, 0}

/*********************************** TYPEDEFS *********************************/

/******************************* INTERFACE FUNCTIONS **************************/

/**
 * Initializes sdr client lib.
 *
 * @return true on success, false in case of failure
 */
bool es_sdr_client_init(void);

/**
 * Deinit es_sdr_client object.
 */
void es_sdr_client_deinit(void);

/**
 * Initialize CSP as a transport layer for es_sdr_client
 *
 * @param[in] dest_addr: Destination address of the SDR module.
 * @return true if successful, false if initialization failed.
 */
bool es_sdr_client_csp_tl_init(uint16_t dest_addr);

/**
 * Check if the transport layer has been initialized.
 *
 * @return true if the transport layer has been initialized, false otherwise.
 */
bool es_client_transport_init_done(void);

/**
 * Upload a file to the SDR module.
 *
 * @param[in] src_file: Name of the file to be uploaded.
 * @param[in] dest_file: Remote location (path) on the SDR file system where to store the file.
 * @return es_tftp_err_code_t code.
 */
es_tftp_err_code_t es_sdr_client_file_upload(const char *src_file, const char *dest_file);

/**
 * Download a file from the SDR module.
 *
 * @param[in] src_file: Path of the file to be downloaded.
 * @param[in] dest_file Location on the host file system where
 *  to store the file.
 * @return es_tftp_err_code_t code.
 */
es_tftp_err_code_t es_sdr_client_file_download(const char *src_file, const char *dest_file);

/**
 * Send / recv an RPC to a service defined by service_id and rpc_id.
 *
 * @param[in] service_id ser/des (service id) as defined in es_sdr_client_ser_des_handlers_t.
 * @param[in] rpc_id Tag that identifies the rpc. All the tags follow a common pattern
 *                    which is SERVICE_NAME_rpc_NAME_OF_THE_RPC_tag.
 *                    All the tags and the associated RPCs with them can be found
 *                    under "RPC ID" section of each RPC described in 'ES Services'.
 * @param[in] req Reference to the _req structure.
 * @param[out] res Reference to the _res structure.
 * @return es_tftp_err_code_t code.
 */
es_sdr_rpc_code_t es_sdr_client_rpc(uint32_t service_id, uint32_t rpc_id, void *req, void *res);

/**
 * Send a PDU to a service defined by service_id.
 *
 * @param[in] conn Connection descriptor.
 * @param[in] service_id ser/des (service id) as defined in es_sdr_client_ser_des_handlers_t.
 * @param[in] o_buffer Output buffer.
 * @param[in] o_buffer_size Output buffer size.
 * @return es_tftp_err_code_t code.
 */
es_tftp_err_code_t es_sdr_client_send_pdu(void *conn, int service_id, char *o_buffer, uint32_t o_buffer_size);

/**
 * Receive a PDU from a service defined by the service_id used in es_sdr_client_send_pdu().
 *
 * @param[in] conn Connection descriptor.
 * @param[in] i_buffer Input buffer.
 * @param[in] i_buffer_size Input buffer size.
 * @return es_tftp_err_code_t code.
 */
int8_t es_sdr_client_recv_pdu(void *conn, char *i_buffer, uint32_t *i_buffer_size);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif /* __ES_CLIENT_H_INCLUDED__ */
