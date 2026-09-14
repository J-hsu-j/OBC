#ifndef __ES_SERVICE_ROUTING_PDU_H__
#define __ES_SERVICE_ROUTING_PDU_H__

/******************************** INCLUDE FILES *******************************/
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*********************************** TYPEDEFS *********************************/
typedef uint16_t es_service_port_t;
typedef uint16_t es_service_conn_status_t;

/**
 * This status represents the state of the proxy service connection
 *  to the service.
 */
typedef enum _es_service_conn_statuses_t {
    ES_SERVICE_CONN_SUCCESS = 0,
    ES_SERVICE_CONN_SEND_ERR,
    ES_SERVICE_CONN_RECV_ERR,
    ES_SERVICE_CONN_UNKNOW_ERR,
    ES_SERVICE_CONN_STATUSES,
} es_service_conn_statuses_t;

typedef struct _es_services_routing_pdu_t {
    /**
     * Keep these fields aligned to 4 byte memory blocks to avoid issues with
     * memory allignemnt & fetching.
     */
    es_service_port_t service_port;
    es_service_conn_status_t conn_status;
    uint32_t data_length;
    uint8_t data[];

}__attribute__((packed, aligned(4))) es_services_routing_pdu_t;

/********************************* DEFINES SIZE *******************************/
#define ES_SERVICE_ROUTING_SIZE    (sizeof(es_services_routing_pdu_t))
#define ES_SERVICE_ROUTING_HDR_LEN (sizeof(es_service_port_t) + \
                                    sizeof(es_service_conn_status_t) + \
                                    sizeof(uint32_t))

/*************************** INTERFACE FUNCTIONS ******************************/

es_services_routing_pdu_t *es_services_routing_pdu_new(uint8_t *);

void es_services_routing_pdu_data_len_set(es_services_routing_pdu_t *, uint32_t);
uint32_t es_services_routing_pdu_data_len_get(es_services_routing_pdu_t *);

void es_services_routing_pdu_port_set(es_services_routing_pdu_t *, es_service_port_t);
es_service_port_t es_services_routing_pdu_port_get(es_services_routing_pdu_t *);

void es_services_routing_pdu_conn_status_set(es_services_routing_pdu_t *, es_service_conn_statuses_t);
es_service_conn_statuses_t es_services_routing_pdu_conn_status_get(es_services_routing_pdu_t *);
const char *es_services_routing_pdu_conn_status_print(es_service_conn_statuses_t status);

#ifdef __cplusplus
}
#endif /* _cplusplus */

#endif /* __ES_SERVICE_ROUTING_PDU_H__ */
