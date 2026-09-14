/**
 * Copyright (c) 2024 EnduroSat AD. All rights reserved
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup libtrace
 * @{
 *
 * @file trace.c
 * @brief Implementation of tracing functionality for software events.
 *
 * @}
 */
#include "trace.h"
#include "trace_defs.h"
#include "trace_config.h"
#include "cobs_inplace.h"
#include "irq.h"
#include "datetime.h"
#include "crc16-ccitt.h"
#include "sys_printf.h"
#include "assertions.h"
#include "file_helper.h"

#include <stddef.h>
#include <string.h>
#include <stdio.h>

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

// Here is an example of a valid format string as specified below:
// "libhsm_trace.c,95,DEBUG,2000-01-01 08:15:33.705505,"
#define TRACE_HDR_FMT "%.*s,%d,%.*s,%0*d.%0*d%0*d,"

/**
 * @brief Maximum number of characters for a file name.  Value chosen based on latest measured longest source file name - 47 characters
 */
#define TRACE_HDR_FILENAME_SZ (50)

/**
 * @brief Maximum number of characters for a line number. Assumption is that files with traces are unlikely to be > 999 999 lines
 */
#define TRACE_HDR_LINE_SZ (6)

#define TRACE_HDR_LVL_SZ       (5)
#define TRACE_HDR_TSTAMP_SZ    (10)
#define TRACE_HDR_TSTAMP_MS_SZ (3)
#define TRACE_HDR_TSTAMP_US_SZ (3)

/* +4 because of ',' symbol */
#define TRACE_HDR_FMT_SZ (TRACE_HDR_FILENAME_SZ + TRACE_HDR_LINE_SZ + TRACE_HDR_LVL_SZ + TRACE_HDR_TSTAMP_SZ + TRACE_HDR_TSTAMP_MS_SZ + TRACE_HDR_TSTAMP_US_SZ + 4)

#define TRACE_FTR_FMT    ",%0*d"
#define TRACE_FTR_CRC_SZ (5)

/* +2 because of ',' and null symbols*/
#define TRACE_FTR_FMT_SZ (TRACE_FTR_CRC_SZ + 2)

#define TRACE_COBS_OVERHEAD (2)

/**
 * @brief Index of the first COBS sentinel value in the bytes of a trace entry
 */
#define TRACE_COBS_FIRST_IDX (0)

#define TRACE_OVERHEAD_SZ (TRACE_HDR_FMT_SZ + TRACE_FTR_FMT_SZ + TRACE_COBS_OVERHEAD)
#define TRACE_USER_SZ     (128)
#define TRACE_BUF_SZ      (TRACE_OVERHEAD_SZ + TRACE_USER_SZ)

/**
 * @brief Mask representing all channels active state
 */
#define TRACE_CH_MASK_ALL (0xff)

/*
***************************************************************************************************
* INTERNAL TYPES DEFINITION
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL VARIABLES DEFINITION
***************************************************************************************************
*/
extern uint8_t _logger_descriptors_start;
extern uint8_t _logger_descriptors_end;
/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/

static trace_channel_t *channel_list    = NULL;
static uint32_t         channel_list_sz = 0;
static bool             b_init_done     = false;

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/

static void                 fs_send_data_to_channels(const uint8_t *data, const uint32_t data_sz, const trace_level_t level, bool b_encoded);
static inline trace_level_t trace_get_level(const uint8_t chan_level_mask);

/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

void trace_init(void)
{
    trace_channel_t *chan_list    = NULL;
    uint32_t         chan_list_sz = 0;
    trace_config_init(&chan_list, &chan_list_sz);

    if ((NULL != chan_list) &&
        (0 < chan_list_sz) &&
        (true != b_init_done))
    {
        channel_list    = chan_list;
        channel_list_sz = chan_list_sz;

        for (uint32_t i = 0; i < chan_list_sz; i++)
        {
            BREAK_ASSERT(NULL != chan_list[i].name);
            BREAK_ASSERT(NULL != chan_list[i].data_send);
            BREAK_ASSERT(NULL != chan_list[i].buf);
            BREAK_ASSERT(0 < chan_list[i].buf_sz);

            chan_list[i].lock = trace_lock_new();

            BREAK_ASSERT(NULL != chan_list[i].lock);

            cbuf_init(&chan_list[i].cbuf, chan_list[i].buf, chan_list[i].buf_sz);
        }

        b_init_done = true;
    }
    else
    {
        BREAK_ASSERT(false);
    }
}

void trace(const char *const filename, const int32_t line, trace_level_t lvl, const char *fmt, ...)
{
    static const char *lvl_str[TRACE_LVL_COUNT] = {
        "DEBUG",
        "INFO",
        "WARN",
        "ERROR",
        "FATAL",
    };

    if ((false == irq_active()) &&
        (NULL != filename) &&
        (TRACE_LVL_COUNT > lvl) &&
        (NULL != fmt) &&
        (false != b_init_done))
    {
        /* local buffer to format user data */
        uint8_t  trc_buf[TRACE_BUF_SZ];
        uint32_t trc_sz = 0;

        /* 1st byte set as required by COBS implementation */
        trc_buf[trc_sz++] = COBS_INPLACE_SENTINEL_VALUE;

        unix_time_precise_t trace_ts = datetime_to_unix_precise_now();

        /* add header in readable format */
        int ret = sys_snprintf(
            (char *)&trc_buf[trc_sz], TRACE_HDR_FMT_SZ,
            TRACE_HDR_FMT,
            TRACE_HDR_FILENAME_SZ, filename,
            line,
            TRACE_HDR_LVL_SZ, lvl_str[lvl],
            TRACE_HDR_TSTAMP_SZ, trace_ts.unix_ts,
            TRACE_HDR_TSTAMP_MS_SZ, trace_ts.ms,
            TRACE_HDR_TSTAMP_US_SZ, trace_ts.us);

        ret = (ret > 0) ? ret : 0;
        trc_sz += ret;

        /* add user data in readable format */
        va_list va;
        va_start(va, fmt);

        ret = sys_vsnprintf((char *)&trc_buf[trc_sz], TRACE_USER_SZ, fmt, va);
        ret = (ret > 0) ? ret : 0;
        trc_sz += (ret > TRACE_USER_SZ) ? TRACE_USER_SZ : ret;

        va_end(va);

        /* send data to the active channels without encoding */
        fs_send_data_to_channels(
            &trc_buf[TRACE_COBS_FIRST_IDX + 1], trc_sz - 1, lvl, false);

        /* calculate data crc, format and append it */
        uint16_t trc_crc = crc16_ccitt_calc(
            &trc_buf[TRACE_COBS_FIRST_IDX + 1], trc_sz - 1);

        ret = sys_snprintf(
            (char *)&trc_buf[trc_sz], TRACE_FTR_FMT_SZ,
            TRACE_FTR_FMT, TRACE_FTR_CRC_SZ, trc_crc);

        ret = (ret > 0) ? ret : 0;
        trc_sz += ret;

        /* last byte set as required by COBS implementation */
        trc_buf[trc_sz++] = COBS_INPLACE_SENTINEL_VALUE;

        BREAK_ASSERT(COBS_INPLACE_SAFE_BUFFER_SIZE >= trc_sz);

        /* send data to the active channels with encoding */
        if (cobs_inplace_encode(trc_buf, trc_sz))
        {
            fs_send_data_to_channels(trc_buf, trc_sz, lvl, true);
        }
        else
        {
            BREAK_ASSERT(false);
        }
    }
}

void trace_serve_chan(const uint32_t channel, uint8_t *buf, const uint32_t buf_sz)
{
    BREAK_ASSERT(b_init_done);
    BREAK_ASSERT(NULL != buf);
    BREAK_ASSERT(channel_list_sz > channel);

    trace_channel_t *chan = &channel_list[channel];

    trace_lock_acquire(chan->lock);

    uint32_t read_sz = cbuf_peek(&chan->cbuf, buf, buf_sz);

    trace_lock_release(chan->lock);

    uint32_t sent_sz = 0;

    if ((0 < read_sz) &&
        (buf_sz >= read_sz))
    {
        sent_sz = chan->data_send(buf, read_sz);
    }

    if (0 < sent_sz)
    {
        trace_lock_acquire(chan->lock);

        (void)cbuf_free(&chan->cbuf, sent_sz);

        trace_lock_release(chan->lock);
    }
}

bool trace_get_chan_active(const uint32_t channel)
{
    BREAK_ASSERT(b_init_done);
    BREAK_ASSERT(channel_list_sz > channel);

    bool b_active;

    trace_lock_acquire(channel_list[channel].lock);

    b_active = channel_list[channel].b_active;

    trace_lock_release(channel_list[channel].lock);

    return b_active;
}

const char *trace_get_chan_name(const uint32_t channel)
{
    BREAK_ASSERT(b_init_done);
    BREAK_ASSERT(channel_list_sz > channel);

    return channel_list[channel].name;
}

bool trace_set_channel_level(const trace_channels_t channel, const trace_level_t channel_level)
{
    bool b_ret_val = false;

    if ((true == b_init_done) && (channel < channel_list_sz))
    {
        trace_lock_acquire(channel_list[channel].lock);

        channel_list[channel].levels = (uint8_t)((uint8_t)TRACE_CH_MASK_ALL << (uint8_t)channel_level);

        trace_lock_release(channel_list[channel].lock);

        b_ret_val = true;
    }

    return b_ret_val;
}

bool trace_set_all_channels_level(const trace_level_t channel_level)
{
    bool b_ret_val = false;

    if (true == b_init_done)
    {
        for (uint8_t trace_channel = TRACE_CHANNEL_UART; trace_channel < channel_list_sz; trace_channel++)
        {
            b_ret_val = trace_set_channel_level(trace_channel, channel_level);

            if (false == b_ret_val)
            {
                break;
            }
        }
    }

    return b_ret_val;
}

bool trace_get_channel_info(const trace_channels_t channel, trace_channel_info_t *const p_chan_info)
{
    bool b_ret_val = false;

    if ((true == b_init_done) && (channel < channel_list_sz) && (NULL != p_chan_info))
    {
        trace_lock_acquire(channel_list[channel].lock);

        p_chan_info->level = trace_get_level(channel_list[channel].levels);

        trace_lock_release(channel_list[channel].lock);

        p_chan_info->active = trace_get_chan_active(channel);

        b_ret_val = true;
    }

    return b_ret_val;
}

bool trace_set_channel_active(const trace_channels_t channel, const bool b_is_channel_active)
{
    bool b_ret_val = false;

    if ((true == b_init_done) && (channel < channel_list_sz))
    {
        trace_lock_acquire(channel_list[channel].lock);

        /* Changes the active status */
        channel_list[channel].b_active = b_is_channel_active;

        trace_lock_release(channel_list[channel].lock);

        b_ret_val = true;
    }

    return b_ret_val;
}

bool trace_set_all_channels_active(const bool is_channel_active)
{
    bool b_ret_val = false;

    if (true == b_init_done)
    {
        for (uint8_t trace_channel = TRACE_CHANNEL_UART; trace_channel < channel_list_sz; trace_channel++)
        {
            b_ret_val = trace_set_channel_active(trace_channel, is_channel_active);

            if (false == b_ret_val)
            {
                break;
            }
        }
    }

    return b_ret_val;
}

void trace_op_set_active_flag(trace_module_info_t *const p_logger_entry, void *const p_op_params)
{
    BREAK_ASSERT(NULL != p_logger_entry);
    BREAK_ASSERT(NULL != p_op_params);

    p_logger_entry->is_active = *((bool *)p_op_params);
}

void trace_op_set_level(trace_module_info_t *const p_logger_entry, void *const p_op_params)
{
    BREAK_ASSERT(NULL != p_logger_entry);
    BREAK_ASSERT(NULL != p_op_params);

    if (*((uint8_t *)p_op_params) < TRACE_LVL_COUNT)
    {
        p_logger_entry->level = *((uint8_t *)p_op_params);
    }
}

void trace_op_get_module_info(trace_module_info_t *const p_logger_entry, void *const p_op_params)
{
    BREAK_ASSERT(NULL != p_logger_entry);
    BREAK_ASSERT(NULL != p_op_params);

    ((trace_module_info_t *)p_op_params)->is_active   = p_logger_entry->is_active;
    ((trace_module_info_t *)p_op_params)->level       = p_logger_entry->level;
    ((trace_module_info_t *)p_op_params)->p_file_name = p_logger_entry->p_file_name;
}

bool trace_perform_module_op(const char *const p_fname_wildcard, trace_op_t p_op_func, void *const p_op_params)
{
    bool                 ret_val                = false;
    trace_module_info_t *p_logger_entry_ret_val = (trace_module_info_t *)&_logger_descriptors_start;

    if ((NULL != p_fname_wildcard) && (NULL != p_op_func) && (NULL != p_op_params))
    {
        while ((uint32_t)p_logger_entry_ret_val < (uint32_t)&_logger_descriptors_end)
        {
            if ((&trace_op_get_module_info != p_op_func) && (true == file_helper_is_wc_matching(p_fname_wildcard,
                                                                                                strlen(p_fname_wildcard),
                                                                                                p_logger_entry_ret_val->p_file_name,
                                                                                                strlen(p_logger_entry_ret_val->p_file_name))))
            {
                (*p_op_func)(p_logger_entry_ret_val, p_op_params);
                ret_val = true;
            }
            else if (0 == strcmp(p_fname_wildcard, p_logger_entry_ret_val->p_file_name))
            {
                (*p_op_func)(p_logger_entry_ret_val, p_op_params);
                ret_val = true;
                break;
            }
            else
            {
                // Else block to avoid SonarQube warning
            }
            p_logger_entry_ret_val++;
        }
    }

    return ret_val;
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

/**
 * @brief Returns trace level based on channel mask level input
 */
static inline trace_level_t trace_get_level(const uint8_t chan_level_mask)
{
    uint8_t level_mask = 1;
    uint8_t chan_level = 0;

    /* Checks at what position is the first flipped bit inside the mask and
    sets the cnannel level as equal to that position. Doesn't guarantee
    that the higher trace levels are active in the channel. */
    while ((0 == (level_mask & chan_level_mask)) && (chan_level < TRACE_LVL_COUNT))
    {
        chan_level++;
        level_mask <<= 1;
    }

    return (trace_level_t)chan_level;
}

static void fs_send_data_to_channels(const uint8_t *data, const uint32_t data_sz, const trace_level_t level, bool b_encoded)
{
    for (uint32_t i = 0; i < channel_list_sz; i++)
    {
        if ((false != trace_get_chan_active(i)) && (b_encoded == channel_list[i].encoded))
        {
            trace_lock_acquire(channel_list[i].lock);

            /* Check if the severity level of the entry is allowed on this channel */
            if (0 != ((channel_list[i].levels) &
                      (1 << (uint8_t)(level))))
            {
                (void)cbuf_push(&channel_list[i].cbuf, data, data_sz, false);
            }

            trace_lock_release(channel_list[i].lock);
        }
    }
}
