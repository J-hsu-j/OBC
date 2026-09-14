#ifndef __ES_SERVICE_ROUTING_TABLE_H__
#define __ES_SERVICE_ROUTING_TABLE_H__

/******************************** INCLUDE FILES *******************************/
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*********************************** TYPEDEFS *********************************/

/********************************* DEFINES ************************************/
/**
 *  ES service Port definitions
 */
typedef enum _es_services_port_t {
    TEST_SERVICE_ID = 10,
    ADRV9009_SERVICE_ID = 12,
    BOARD_INFO_SERVICE_ID = 13,
    IPRIUM_DVB_S2_SERVICE_ID = 14,
    BOARD_MGR_SERVICE_ID = 15,
    REMOTE_CODE_EXECUTION_SERVICE_ID = 60,
    VYOMA_SERVICE_ID = 61,
    ES_SERVICE_INVALID,
} es_services_port_t;

/**
 *  ES Port service handlers
 */
typedef enum _es_services_handlers_t {
    ES_DEFAULT_HANDLER = 0,
    ES_RPC_HANDLER,
    ES_DATA_STREAM_HANDLER,
    ES_USER_RPC_HANDLER,
    ES_DATAGRAM_HANDLER,
    ES_SERVICE_HANDLERS,
    ES_INVALID_HANDLER,
} es_services_handlers_t;

/*************************** INTERFACE FUNCTIONS ******************************/

void es_services_routing_table_print(void);
const char *es_services_routing_table_port_to_service(es_services_port_t port);
es_services_handlers_t es_services_routing_table_handler_get(es_services_port_t port);

#ifdef __cplusplus
}
#endif /* _cplusplus */


#endif /* __ES_SERVICE_ROUTING_TABLE_H__ */
