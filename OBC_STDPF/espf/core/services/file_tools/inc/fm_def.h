
#ifndef __FM_DEF_H__
#define __FM_DEF_H__

/**
 * @addtogroup service_file_tools
 * @{
 *
 * @file fm_def.h
 *
 * @brief Common definitions for the file tools service, that may be used outside the service.
 *
 * @}
 *
 */


/**
 * @brief The maximum string length of a file path.
 * @details The maximum string length of a file path in char (single byte) elements + terminating zero that would be processed. Anything more will return an error.
 */
#define FM_MAX_PATH (47LU)

/**
 * @brief The path for the SD card volume.
 */
#define FM_VOL_SD_PATH "/sd"

#endif // __FM_DEF_H__