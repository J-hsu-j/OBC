/******************************** INCLUDE FILES *******************************/
#include "es_services_routing_table.h"

#include "es_log.h"
/******************************** LOCAL DEFINES *******************************/
#define ES_MODULE_NAME "es_services_routing"
/**
 * ES Services configuration parameters
 */

/* Lowest port number available for es default service binding*/
#define ES_DFLT_SERVICE_MIN                      0
/* Highest port number available for es default service binding*/
#define ES_DFLT_SERVICE_MAX                      9
/* Lowest port number available for es RPC (TCP) service binding*/
#define ES_RPC_SERVICE_MIN                       10
/* Highest port number available for es RPC (TCP) service binding*/
#define ES_RPC_SERVICE_MAX                       19
/* Lowest port number available for es data stream (TCP) service binding*/
#define ES_DATA_STREAM_SERVICE_MIN               20
/* Highest port number available for es data stream (TCP) service binding*/
#define ES_DATA_STREAM_SERVICE_MAX               39
/* Lowest port number available for user service binding*/
#define ES_USER_SERVICE_MIN                      60
/* Highest port number available for user service binding*/
#define ES_USER_SERVICE_MAX                      70

/********************************** TYPEDEFS **********************************/
/*ES Services Struct*/
typedef struct _es_services_t
{
    es_services_port_t port;
    const char         *service_port_str;
} es_services_t;

/*************************** FUNCTION PROTOTYPES ******************************/

/******************************* LOCAL DATA ***********************************/

/********
 *  ROUTING TABLE
 *  *********/
#define ES_SERVICE_ID_LEN                        8
static const es_services_t es_services_routing_table [ES_SERVICE_ID_LEN] = {
    {TEST_SERVICE_ID, "TEST_SERVICE"},
    {ADRV9009_SERVICE_ID, "ADRV9009_SERVICE"},
    {BOARD_INFO_SERVICE_ID, "BOARD_INFO_SERVICE"},
    {IPRIUM_DVB_S2_SERVICE_ID, "IPRIUM_DVB_S2_SERVICE"},
    {BOARD_MGR_SERVICE_ID, "BOARD_MGR_SERVICE"},
    {REMOTE_CODE_EXECUTION_SERVICE_ID, "REMOTE_CODE_EXECUTION_SERVICE"},
    {VYOMA_SERVICE_ID, "VYOMA_SERVICE"},
    {ES_SERVICE_INVALID, "ES_INVALID_SERVICE"},
} ;

/***************************** LOCAL FUNCTIONS ********************************/

/**************************** INTERFACE FUNCTIONS *****************************/

const char *es_services_routing_table_port_to_service(es_services_port_t port)
{
    int i = 0;

    if (port < 0)
        return NULL;

    for (i = 0; i <= ES_SERVICE_ID_LEN; ++i)
    {
        if (es_services_routing_table[i].port == port)
            return es_services_routing_table[i].service_port_str;
    }

    return NULL;
}

/************
 *  PORT MAPPING
 *************/
es_services_handlers_t es_services_routing_table_handler_get(es_services_port_t port)
{
     es_services_handlers_t handler_id = ES_INVALID_HANDLER;

     if ((port >= ES_DFLT_SERVICE_MIN) && (port <= ES_DFLT_SERVICE_MAX))
     {
           return ES_DEFAULT_HANDLER;
     }
     if ((port >= ES_RPC_SERVICE_MIN) && (port <= ES_RPC_SERVICE_MAX))
     {
           return ES_RPC_HANDLER;
     }
     if ((port >= ES_DATA_STREAM_SERVICE_MIN) && (port <= ES_DATA_STREAM_SERVICE_MAX))
     {
           return ES_DATA_STREAM_HANDLER;
     }
     if ((port >= ES_USER_SERVICE_MIN) && (port <= ES_USER_SERVICE_MAX))
     {
           return ES_USER_RPC_HANDLER;
     }

     return handler_id;
}

void es_services_routing_table_print(void)
{
    int i = 0;

    /* Server routing tables info */
    ES_LOG_MSG(ES_TRACE, "ES Services RPC Routing Table");
    ES_LOG_MSG(ES_TRACE, "|%30s\t|%20s\t|", "Service ID", "Port");
    for (i = 0; i < ES_SERVICE_ID_LEN - 1; i++)
    {
        if ((es_services_routing_table[i].port >= ES_RPC_SERVICE_MIN) &&
            (es_services_routing_table[i].port <= ES_RPC_SERVICE_MAX))
            ES_LOG_MSG(ES_TRACE, "|%30s\t|%20d\t|", es_services_routing_table[i].service_port_str,
                es_services_routing_table[i].port);
    }

    ES_LOG_MSG(ES_TRACE, "ES User Services RPC Routing Table");
    ES_LOG_MSG(ES_TRACE, "|%30s\t|%20s\t|", "Service ID", "Port");
    for (i = 0; i < ES_SERVICE_ID_LEN - 1; i++)
    {
        if ((es_services_routing_table[i].port >= ES_USER_SERVICE_MIN) &&
            (es_services_routing_table[i].port <= ES_USER_SERVICE_MAX))
            ES_LOG_MSG(ES_TRACE, "|%30s\t|%20d\t|", es_services_routing_table[i].service_port_str,
                es_services_routing_table[i].port);
    }

    ES_LOG_MSG(ES_TRACE, "ES Services Data Stream Proxy Table");
    ES_LOG_MSG(ES_TRACE, "|%30s\t|%20s\t|", "Service ID", "Port");
    for (i = 0; i < ES_SERVICE_ID_LEN - 1; i++)
    {
        if ((es_services_routing_table[i].port >= ES_DATA_STREAM_SERVICE_MIN) &&
            (es_services_routing_table[i].port <= ES_DATA_STREAM_SERVICE_MAX))
            ES_LOG_MSG(ES_TRACE, "|%30s\t|%20d\t|", es_services_routing_table[i].service_port_str,
                es_services_routing_table[i].port);
    }
}
