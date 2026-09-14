/******************************** INCLUDE FILES *******************************/
#include "es_port_fm.h"
/********************************* LOCAL DEFINES ******************************/

/******************************* LOCAL FUNCTIONS ******************************/

/***************************** INTERFACE FUNCTIONS ****************************/
fm_result_t es_port_file_open(fm_handle_t fp, const char *const filename, const uint32_t mode)
{
    fm_result_t ret = FM_RES_INVALID_PARAMETER;
    ret             = fm_open(fp, filename, mode);
    return ret;
}

fm_result_t es_port_file_close(fm_handle_t fp)
{
    fm_result_t ret = FM_RES_INVALID_PARAMETER;
    ret             = fm_close(fp);
    return ret;
}

fm_result_t es_port_file_remove(const uint8_t *filename)
{
    fm_result_t ret = FM_RES_INVALID_PARAMETER;
    ret             = fm_delete((const char *const)filename);
    return ret;
}

fm_result_t es_port_file_size(fm_handle_t fp, uint32_t *const p_out_size)
{
    fm_result_t ret = FM_RES_INVALID_PARAMETER;
    ret             = fm_size(fp, p_out_size);
    return ret;
}

fm_result_t es_port_file_read(fm_handle_t fp, void *const data, const uint32_t bytes_to_read, uint32_t *const p_out_bytes_read)
{
    fm_result_t ret = FM_RES_INVALID_PARAMETER;
    ret             = fm_read(fp, data, bytes_to_read, p_out_bytes_read);
    return ret;
}

fm_result_t es_port_file_write(fm_handle_t fp, const void *p_in_buff, const uint32_t bytes_to_write, uint32_t *const p_out_bytes_written)
{
    fm_result_t ret = FM_RES_INVALID_PARAMETER;
    ret             = fm_write(fp, p_in_buff, bytes_to_write, p_out_bytes_written);
    return ret;
}
