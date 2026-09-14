/**
 * Copyright (c) 2024 EnduroSat AD. All rights reserved
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef TRACE_H_
#define TRACE_H_

/**
 * @addtogroup Libraries
 * @{
 *
 * @addtogroup libtrace
 * @{
 * Provides a tracing functionality for software events
 *
 * @file trace.h
 * @brief Provides user interface for interfacing with the library
 *
 * @}
 * @}
 */

#ifdef __cplusplus
extern "C"
{
#endif

#include "trace_types.h"

    /*
    ***************************************************************************************************
    * EXTERNAL DEFINES
    ***************************************************************************************************
    */

    /**
     * @addtogroup libtrace
     * @{
     */

#if defined(__GNUC__) && !defined(__clang__)
/**
 * @brief Helper macro to extract at compile time the file name from a given full path
 */
#define EXTRACT_FILENAME (__builtin_strrchr(__FILE__, '/') + 1) // GCC optimization - the builtin calculates pointer to substring at compile time.
#else
#include <string.h>

#define EXTRACT_FILENAME (strrchr(__FILE__, '/') + 1) // __FILE__ returns a null-terminated string so strrchr is not
                                                      // expected to read out of bounds
#endif                                                // defined(__GNUC__) && !defined(__clang__)

#ifndef OPT_VA_ARGS
#define OPT_VA_ARGS(...) , ##__VA_ARGS__
#endif // #ifndef OPT_VA_ARGS

/**
 * @brief Used to log module trace active or inactive status
 */
#define INIT_CMP_LOGGER(active, trace_level)                                                     \
    static trace_module_info_t cmp_logger __attribute__((section(".trace_logger_descriptors"))); \
    static void __attribute__((constructor)) cmp_logger_def_init(void)                           \
    {                                                                                            \
        cmp_logger.is_active   = (active);                                                       \
        cmp_logger.level       = (trace_level);                                                  \
        cmp_logger.p_file_name = EXTRACT_FILENAME;                                               \
    }

#ifdef ES_TRACE_ENABLED
/**
 * @brief Used to log entries of level ERROR
 */
#define ES_TRACE_ERROR(format, ...)                                                              \
    do                                                                                           \
    {                                                                                            \
        if ((true == cmp_logger.is_active) && (TRACE_LVL_ERROR >= cmp_logger.level))             \
            trace(EXTRACT_FILENAME, __LINE__, TRACE_LVL_ERROR, format OPT_VA_ARGS(__VA_ARGS__)); \
    } while (0)

/**
 * @brief Used to log entries of level WARNING
 */
#define ES_TRACE_WARN(format, ...)                                                              \
    do                                                                                          \
    {                                                                                           \
        if ((true == cmp_logger.is_active) && (TRACE_LVL_WARN >= cmp_logger.level))             \
            trace(EXTRACT_FILENAME, __LINE__, TRACE_LVL_WARN, format OPT_VA_ARGS(__VA_ARGS__)); \
    } while (0)

/**
 * @brief Used to log entries of level INFO
 */
#define ES_TRACE_INFO(format, ...)                                                              \
    do                                                                                          \
    {                                                                                           \
        if ((true == cmp_logger.is_active) && (TRACE_LVL_INFO >= cmp_logger.level))             \
            trace(EXTRACT_FILENAME, __LINE__, TRACE_LVL_INFO, format OPT_VA_ARGS(__VA_ARGS__)); \
    } while (0)

/**
 * @brief Used to log entries of level FATAL
 */
#define ES_TRACE_FATAL(format, ...)                                                              \
    do                                                                                           \
    {                                                                                            \
        if ((true == cmp_logger.is_active) && (TRACE_LVL_FATAL >= cmp_logger.level))             \
            trace(EXTRACT_FILENAME, __LINE__, TRACE_LVL_FATAL, format OPT_VA_ARGS(__VA_ARGS__)); \
    } while (0)

/**
 * @brief Used to log entries of level DEBUG
 */
#define ES_TRACE_DEBUG(format, ...)                                                              \
    do                                                                                           \
    {                                                                                            \
        if ((true == cmp_logger.is_active) && (TRACE_LVL_DEBUG >= cmp_logger.level))             \
            trace(EXTRACT_FILENAME, __LINE__, TRACE_LVL_DEBUG, format OPT_VA_ARGS(__VA_ARGS__)); \
    } while (0)
#else
#define ES_TRACE_ERROR(format, ...)
#define ES_TRACE_WARN(format, ...)
#define ES_TRACE_INFO(format, ...)
#define ES_TRACE_FATAL(format, ...)
#define ES_TRACE_DEBUG(format, ...)
#endif // #ifndef TRACE_ENABLED
    /*
    ***************************************************************************************************
    * EXTERNAL TYPES DECLARATIONS
    ***************************************************************************************************
    */
    typedef void (*trace_op_t)(trace_module_info_t *const p_logger_entry, void *const p_op_params);
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
     * @brief Initialises tracing
     */
    void trace_init(void);

    /**
     * @brief Logs data to active channel
     *
     * @param filename Name of the file where the data is logged. Module it is string with max size TRACE_HDR_FILE_SZ
     * @param line Number of the line where the data is logged
     * @param lvl Log level @ref logging_level
     * @param fmt Printf-like format string
     * @param ... Variable number of args to be used in the format string
     */
    void trace(const char *const filename, const int32_t line, trace_level_t lvl, const char *fmt, ...);

    /**
     * @brief If the buffer is of sufficient lenght the data is sent to the specified channel
     *
     * @param channel Channel number to check.
     * @param buf Pointer to buffer.
     * @param buf_sz Buffer size.
     */
    void trace_serve_chan(const uint32_t channel, uint8_t *buf, const uint32_t buf_sz);

    /**
     * @brief Check if logging channel number is active.
     *
     * @param channel Channel number to check
     *
     * @return logging channel status True = active
     */
    bool trace_get_chan_active(const uint32_t channel);

    /**
     * @brief Gets the logging channel name/description.
     *
     * @param channel Channel number to check
     *
     * @return Logging channel name/description
     */
    const char *trace_get_chan_name(const uint32_t channel);

    /**
     * @brief Sets the level of the specified trace channel.
     *
     * @param channel Specifies the trace channel from the trace channels enum.
     * @param channel_level Specifies the trace level from the trace levels enum.
     *
     * @retval true - Successful operation
     *
     * @retval false - Failure
     */
    bool trace_set_channel_level(const trace_channels_t channel, const trace_level_t channel_level);

    /**
     * @brief Sets the level of all trace channels.
     *
     * @param channel_level Specifies the trace level from the trace levels enum.
     *
     * @retval true - Successful operation
     *
     * @retval false - Failure
     */
    bool trace_set_all_channels_level(const trace_level_t channel_level);

    /**
     * @brief Assigns values to a structure containing the level and the status (active or inactive)
     *        of the specified trace channel.
     *
     * @param channel Specifies the trace channel from the trace channels enum.
     * @param p_chan_info (Return parameter) Pointer to a structure inside of which the channel info
     *                    will be written.
     *
     * @retval true - Successful operation
     *
     * @retval false - Failure
     */
    bool trace_get_channel_info(const trace_channels_t channel, trace_channel_info_t *p_chan_info);

    /**
     * @brief Sets the given trace channel as active or inactive.
     *
     * @param channel Specifies the trace channel from the trace channels enum.
     * @param is_channel_active Specifies the active or inactive status of the trace channel.
     *
     * @retval true - Successful operation
     *
     * @retval false - Failure
     */
    bool trace_set_channel_active(const trace_channels_t channel, const bool b_is_channel_active);

    /**
     * @brief Sets all trace channels as active or inactive.
     *
     * @param is_channel_active Specifies active or inactive status of the trace channels.
     *
     * @retval true - Successful operation
     *
     * @retval false - Failure
     */
    bool trace_set_all_channels_active(const bool is_channel_active);

    /**
     * @brief Changes the active flag of a specified trace module.
     *
     * @param p_logger_entry Input struct specifying the trace module configuration.
     * @param p_op_params Sets the active flag as true or false.
     */
    void trace_op_set_active_flag(trace_module_info_t *const p_logger_entry, void *const p_op_params);

    /**
     * @brief Changes the level of a specified trace module.
     *
     * @param p_logger_entry Input struct specifying the trace module configuration.
     * @param p_op_params Specifies the trace level.
     */
    void trace_op_set_level(trace_module_info_t *const p_logger_entry, void *const p_op_params);

    /**
     * @brief Obtains trace module configuration input.
     *
     * @param p_logger_entry Input (pointer to struct trace_module_info_t) containing the module configuration information.
     * @param p_op_params Output (pointer to struct trace_module_info_t) containing the module configuration information.
     */
    void trace_op_get_module_info(trace_module_info_t *const p_logger_entry, void *const p_op_params);

    /**
     * @brief Performs specified operation on a specified trace module, with given input parameters.
     *        Asterisk (*) wildcards can be used for level and active flag setting so that multiple modules are configured simultaneously.
     *
     * @param p_fname_wildcard Input string specifying the trace module.
     * @param p_op_func Specifies the operation that will be performed on the module.
     * @param p_op_params Specifies the parameters of the trace module configuration.
     *
     * @retval true - Successful operation
     *
     * @retval false - Failure
     */
    bool trace_perform_module_op(const char *const p_fname_wildcard, trace_op_t p_op_func, void *const p_op_params);

#ifdef __cplusplus
}
#endif

#endif /* TRACE_H_ */
