#ifndef __ES_PORT_H__
#define __ES_PORT_H__

/******************************** INCLUDE FILES *******************************/
#include <stdint.h>
#include <unistd.h>

#include "fm_mng.h"

/*************************************** DEFINES ******************************/

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    /********************************* LOCAL DATA *********************************/

    /*********************************** TYPEDEFS *********************************/

    /***************************** INTERFACE FUNCTIONS ****************************/
    fm_result_t es_port_file_open(fm_handle_t fp, const char *const filename, const uint32_t mode);
    fm_result_t es_port_file_close(fm_handle_t fp);
    fm_result_t es_port_file_remove(const uint8_t *filename);
    fm_result_t es_port_file_size(fm_handle_t fp, uint32_t *const p_out_size);
    fm_result_t es_port_file_read(fm_handle_t fp, void *const data, const uint32_t bytes_to_read, uint32_t *const p_out_bytes_read);
    fm_result_t es_port_file_write(fm_handle_t fp, const void *p_in_buff, const uint32_t bytes_to_write, uint32_t *const p_out_bytes_written);

#ifdef __cplusplus
}
#endif /* _cplusplus */
#endif /* __ES_PORT_H__ */
