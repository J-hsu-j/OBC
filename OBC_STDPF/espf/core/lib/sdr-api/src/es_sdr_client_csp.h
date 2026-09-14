#ifndef __ES_CSP__
#define __ES_CSP__

/******************************** INCLUDE FILES *******************************/
#include "es_sdr_client_tl_iface.h"
#include "sdr_cfg.h"
#include "es_log.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*********************************** DEFINES **********************************/
#define ES_CSP_SDR_DLFT_ADDRESS SDR_CSP_DEFAULT_ADDRESS

    /*********************************** TYPEDEFS *********************************/
    typedef struct _es_csp_conf_t
    {
        int addr;
    } es_csp_conf_t;
#define es_csp_conf_init_default \
    {                            \
        ES_CSP_SDR_DLFT_ADDRESS  \
    }

    /***************************** INTERFACE DATA TYPES ***************************/

    /***************************** INTERFACE FUNCTIONS ****************************/
    es_sdr_client_tl_t *es_sdr_client_csp_get(void);

#ifdef __cplusplus
}
#endif /* _cplusplus */

#endif /* __ES_CSP__ */
