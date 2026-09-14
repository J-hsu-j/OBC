/*
 * Copyright (c) 2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef SDR_OP_H
#define SDR_OP_H

/**
 * @addtogroup sdr
 * @{
 *
 *
 * @file sdr_op.h
 * @brief SDR operations public interface
 *
 * @}
 */

#include "sdr_types.h"
#include "datetime.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL ROUTINES DECLARATIONS
***************************************************************************************************
*/

/**
 * @brief Upload file to SDR operation
 *
 * @param[in] file_op            file operation structure
 * @return    es_tftp_err_code_t file upload status
 *
 * @code  typical usage:
 *        sdr_file_op_t file_op;                                    // file operation structure
 *        file_op.obc_file = "/sd/my_dir/file_on_obc.bin";          // file on the OBC
 *        file_op.sdr_file = "/home/my_files/file_on_sdr.bin";      // file on the SDR
 *        sdr_upload(&file_op);                                     // upload file to SDR
 * @endcode
 */
es_tftp_err_code_t sdr_upload(const sdr_file_op_t *file_op);

/**
 * @brief Download file from SDR operation
 *
 * @param[in] file_op            file operation structure
 * @return    es_tftp_err_code_t file download status
 *
 * @code  typical usage:
 *        sdr_file_op_t file_op;                                    // file operation structure
 *        file_op.obc_file = "/sd/my_dir/file_on_obc.bin";          // file on the OBC
 *        file_op.sdr_file = "/home/my_files/file_on_sdr.bin";      // file on the SDR
 *        sdr_download(&file_op);                                   // download file from SDR
 * @endcode
 */
es_tftp_err_code_t sdr_download(const sdr_file_op_t *file_op);

/**
 * @brief Poll last file transfer operation status
 * @return es_tftp_err_code_t last file transfer status
 */
es_tftp_err_code_t sdr_poll_file_transfer_status(void);

/**
 * @brief Get SDR sm state
 *
 * @param[out] p_active_state active state
 */
void sdr_get_state(uint8_t *const p_active_state);

/**
 * @brief Set file transfer operation
 *
 * @param[in] ft_req file transfer operation user structure
 * @return    bool   file transfer operation get status
 */
bool ft_op_set(const sdr_file_op_t *ft_req);

/**
 * @brief Set SDR time synchronization data
 *
 * @param[in] datetime_stamp_t date time stamp
 */
void sdr_time_sync_data_set(const datetime_stamp_t *dt);

#ifdef __cplusplus
}
#endif

#endif /* SDR_OP_H */
