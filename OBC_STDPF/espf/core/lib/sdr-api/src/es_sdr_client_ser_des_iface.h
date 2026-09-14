#ifndef __ES_SDR_CLIENT_SER_DES_IFACE_H__
#define __ES_SDR_CLIENT_SER_DES_IFACE_H__


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/***************************** FUNCTIONS TYPEDEFS ******************************/
/*Client ser handler type*/
typedef int (* serHnldr_t) (int, char *, void *);
/*Client des handler type*/
typedef int (* desHnldr_t) (int, char *, void *);

/***************************** STRUCTURE TYPEDEFS ******************************/
/*Client ser des struct handlers*/
typedef struct _es_ser_des_t
{
    serHnldr_t  ser;
    desHnldr_t  des;
} es_ser_des_t;

#ifdef __cplusplus
}
#endif /* _cplusplus */

#endif /* __ES_SDR_CLIENT_SER_DES_IFACE_H__ */
