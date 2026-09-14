/**
 * Copyright (c) 2020-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef GNSS_UART_H
#define GNSS_UART_H

/**
 * @addtogroup Drivers
 * @{
 * @defgroup gnss
 * @{
 * @file gnss_uart.h
 * @}
 * @}
 */

#include "es_cdef.h"
#include "FP_gnssProtocolTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/
/** @brief single RX buffer data field maximum size */
#define GNSS_UART_BUFFER_DATA_SZ (512U)

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/
/** @brief defines the structure of a gnss receive message */
typedef struct
{
    uint8_t  data[GNSS_UART_BUFFER_DATA_SZ]; /**< received data buffer */
    uint32_t data_sz;                        /**< received data size */
} gnss_uart_resp_t;

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
 * @brief initialise UART peripheral with specific baudrate
 * @retval true  gnss uart initialization succeeded
 * @retval false gnss uart initialization failed
 */
bool gnss_uart_init(void);

/**
 * @brief is the gnss uart peripheral initialized
 *
 * @return true the gnss uart peripheral is initialized
 * @return false the gnss uart peripheral is not initialized
 */
bool is_gnss_uart_init(void);

/**
 * @brief set the baudrate of the gnss uart
 *
 * @param[in] baudrate pointer to the baudrate value to set
 *
 * @retval true  gnss uart baudrate setting succeeded
 * @retval false gnss uart baudrate setting failed
 */
bool gnss_uart_baudrate_set(const GNSS_BaudRate_t *const baudrate);

/**
 * @brief get the baudrate from the nvm
 *
 * @param[out] baudrate_nvm     pointer to the baudrate value stored in nvm
 * @param[out] baudrate_current pointer to the current baudrate value
 *
 * @retval true  gnss uart baudrate retrieval succeeded
 * @retval false gnss uart baudrate retrieval failed
 */
bool gnss_uart_baudrate_get(GNSS_BaudRate_t *const baudrate_nvm, GNSS_BaudRate_t *const baudrate_current);

/**
 * @brief convert BaudRate enum fields to uint32_t baud rate values
 *
 * @param[in] baudrate enum field to map to a uint32_t value
 *
 * @return uint32_t gnss baudrate value
 */
uint32_t gnss_uart_baudrate_map(GNSS_BaudRate_t baudrate);

/**
 * @brief deinitialise UART peripheral
 *
 * @retval true  gnss uart deinitialization succeeded
 * @retval false gnss uart deinitialization failed
 */
bool gnss_uart_deinit(void);

/**
 * @brief receive raw ASCII response
 *
 * @param[out] p_resp pointer to structure for response to be written in
 *
 * @retval true  successfully retrieved a response message from the receive queue
 * @retval false failed to retrieve a message from the receive queue
 */
bool gnss_uart_rx(gnss_uart_resp_t *p_resp, uint16_t timeout);

/**
 * @brief transmit ascii data to gnss
 *
 * @param[in] p_data  pointer to data to transmit
 * @param[in] data_sz size of the data to transmit
 *
 * @retval true  transmission success
 * @retval false transmission failure
 */
bool gnss_uart_tx(const uint8_t *p_data, const uint16_t data_sz);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // GNSS_UART_H
