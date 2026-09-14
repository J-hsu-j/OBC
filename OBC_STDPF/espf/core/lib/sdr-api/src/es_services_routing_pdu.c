/******************************** INCLUDE FILES *******************************/
#include "es_services_routing_pdu.h"

#include "es_log.h"
/******************************** LOCAL DEFINES *******************************/
#define ES_MODULE_NAME         "[ES_SERVICES_ROUTING] pdu"

/********************************** TYPEDEFS **********************************/

/******************************* LOCAL DATA ***********************************/
static const char *es_service_conn_status[ES_SERVICE_CONN_STATUSES] = {
    "Connection Success",
    "Service Send Error",
    "Service Receive Error",
    "Status Unknown",
};

/***************************** LOCAL FUNCTIONS ********************************/

/**************************** INTERFACE FUNCTIONS *****************************/
es_services_routing_pdu_t *es_services_routing_pdu_new(uint8_t *buffer)
{
    return (es_services_routing_pdu_t *)buffer;
}


void es_services_routing_pdu_data_len_set(es_services_routing_pdu_t *pdu, uint32_t data_length)
{
    pdu->data_length = data_length;
}

uint32_t es_services_routing_pdu_data_len_get(es_services_routing_pdu_t *pdu)
{
    return pdu->data_length;
}


void es_services_routing_pdu_port_set(es_services_routing_pdu_t *pdu, es_service_port_t port)
{
    pdu->service_port = port;
}

es_service_port_t es_services_routing_pdu_port_get(es_services_routing_pdu_t *pdu)
{
    return pdu->service_port;
}

void es_services_routing_pdu_conn_status_set(es_services_routing_pdu_t *pdu,
    es_service_conn_statuses_t conn_status)
{
    pdu->conn_status = conn_status;
}

es_service_conn_statuses_t es_services_routing_pdu_conn_status_get(es_services_routing_pdu_t *pdu)
{
    return pdu->conn_status;
}

const char *es_services_routing_pdu_conn_status_print(es_service_conn_statuses_t status)
{
    return es_service_conn_status[status];
}