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
 * @file trace_config.c
 * @brief `trace` configuration implementation
 *
 * @}
 */
#include "trace_config.h"
#include "trace.h"
#include "trace_defs.h"
#include "rlf.h"
#include "if_sys_conf.h"
#include "es_cdef.h"
#include "cmsis_os2.h"
#include "stm32h7xx_hal.h"
#include "assertions.h"
#include "taskmon.h"
#include "taskmon_stat.h"

/*
***************************************************************************************************
* INTERNAL DEFINES
***************************************************************************************************
*/

/** @brief Period of the OS threads that service the trace channel buffers */
#define TRACE_SERVE_MS (25)

/** @brief Check the stack level each second. */
#define STACK_CHECK_COUNTER (1000 / TRACE_SERVE_MS)

/** Maximum size in bytes of the buffer for a single channel of trace data */
#define CHAN_BUF_SZ (1024)

/** Maximum size in bytes of the channel data that is read on a single execution of a servicing thread */
#define WORK_BUF_SZ (CHAN_BUF_SZ / 2)

/** Name pattern for the rolling file used by the file trace channel */
#define ROLLING_FILE_NAME "trace_log.d__"

/** Maximum size of one instance of the rolling file */
#define ROLLING_FILE_SIZE (10485760) // 10MB

/** Maximum number of rolling file instances */
#define ROLLING_FILE_CNT (10)

/** Index in the rolling file name pattern of the marker of active/inactive file */
#define ROLLING_FILE_MARK_POS (11)

/** Index in the rolling file name pattern of the file instance index */
#define ROLLING_FILE_IDX_POS (12)

/** Marker in the rolling file name for the currently active file */
#define ROLLING_FILE_ACTIVE 'o'

/** Marker in the rolling file name for currently inactive files */
#define ROLLING_FILE_INACTIVE 'x'

/** Trace UART channel baud rate */
#define TRACE_UART_BAUD_RATE (115200U)

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

/*
***************************************************************************************************
* INTERNAL (STATIC) VARIABLES DEFINITION/DECLARATION
***************************************************************************************************
*/

static osThreadId_t         thread_handle[TRACE_CHANNEL_COUNT];
static osThreadAttr_t       thread_attr[TRACE_CHANNEL_COUNT];
static const osThreadFunc_t thread_routine[TRACE_CHANNEL_COUNT];
static const uint16_t       thread_stack_sz[TRACE_CHANNEL_COUNT] = {
    [TRACE_CHANNEL_UART] = 512,
    [TRACE_CHANNEL_FILE] = 2048,
#if defined(STM32_SWV_SUPPORT) && defined(DEBUG_ENABLED)
    [TRACE_CHANNEL_SWV] = 512
#endif
};

static trace_channel_t channel_list[TRACE_CHANNEL_COUNT];
static uint8_t         channel_buf[TRACE_CHANNEL_COUNT][CHAN_BUF_SZ];

static uint8_t work_buf[TRACE_CHANNEL_COUNT][WORK_BUF_SZ];

static UART_HandleTypeDef huart;

static const rlf_cfg_t trace_rlf_cfg = {
    .max_size        = ROLLING_FILE_SIZE,
    .pattern         = ROLLING_FILE_NAME,
    .pos_marker      = ROLLING_FILE_MARK_POS,
    .pos_index       = ROLLING_FILE_IDX_POS,
    .max_count       = ROLLING_FILE_CNT,
    .marker_active   = ROLLING_FILE_ACTIVE,
    .marker_inactive = ROLLING_FILE_INACTIVE
};

static fm_file_obj_t rlf_file_obj;

static rlf_ctx_t rolling_file = {
    .filename                 = "",
    .p_cfg                    = &trace_rlf_cfg,
    .current_index            = 0,
    .is_open                  = false,
    .handle                   = &rlf_file_obj,
    .use_internal_file_object = false
};

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DECLARATION
***************************************************************************************************
*/

static void     thread_uart(void *args);
static void     thread_file(void *args);
static uint32_t channel_data_send_to_uart(const uint8_t *data, const uint32_t data_sz);
static uint32_t channel_data_send_to_file(const uint8_t *data, const uint32_t data_sz);
static void     trace_uart_init(void);
#if defined(STM32_SWV_SUPPORT) && defined(DEBUG_ENABLED)
static void     thread_swv(void *args);
static uint32_t channel_data_send_to_swv(const uint8_t *data, const uint32_t data_sz);
#endif

// clang-format off

/*These static variables are defined here because they are dependant on some funcion declarations.*/
static const osThreadFunc_t thread_routine[TRACE_CHANNEL_COUNT] = {
    [TRACE_CHANNEL_UART] = thread_uart,
    [TRACE_CHANNEL_FILE] = thread_file,
#if defined(STM32_SWV_SUPPORT) && defined(DEBUG_ENABLED)
    [TRACE_CHANNEL_SWV] = thread_swv,
#endif
};


static trace_channel_t channel_list[TRACE_CHANNEL_COUNT] = {
    [TRACE_CHANNEL_UART] = {
                            .name      = "trc_uart",
                            .b_active  = true,
                            .encoded   = true,
                            .lock      = NULL,
                            .data_send = channel_data_send_to_uart,
                            .cbuf      = { .head = 0, .tail = 0, .buf = NULL, .buf_sz = 0, .space = 0 },
                            .buf       = channel_buf[TRACE_CHANNEL_UART],
                            .buf_sz    = sizeof(channel_buf[TRACE_CHANNEL_UART]),
                            .levels    = (uint8_t)(TRACE_LVL_ENABLE(TRACE_LVL_INFO) |
                            TRACE_LVL_ENABLE(TRACE_LVL_WARN) |
                            TRACE_LVL_ENABLE(TRACE_LVL_ERROR) |
                            TRACE_LVL_ENABLE(TRACE_LVL_FATAL) |
                            TRACE_LVL_ENABLE(TRACE_LVL_DEBUG)),
                            .task_id   = TASK_ID_TRACE_UART
                           },
    [TRACE_CHANNEL_FILE] = {
                            .name = "trc_file",
                            .b_active = true,
                            .encoded = true,
                            .lock = NULL,
                            .data_send = channel_data_send_to_file,
                            .cbuf = { .head = 0, .tail = 0, .buf = NULL, .buf_sz = 0, .space = 0 },
                            .buf = channel_buf[TRACE_CHANNEL_FILE],
                            .buf_sz = sizeof(channel_buf[TRACE_CHANNEL_FILE]),
                            .levels = (uint8_t)(TRACE_LVL_ENABLE(TRACE_LVL_ERROR) |
                            TRACE_LVL_ENABLE(TRACE_LVL_WARN) |
                            TRACE_LVL_ENABLE(TRACE_LVL_FATAL)),
                            .task_id = TASK_ID_TRACE_FILE
                           },
#if defined(STM32_SWV_SUPPORT) && defined(DEBUG_ENABLED)
    [TRACE_CHANNEL_SWV] = {
                           .name = "trc_swv",
                           .b_active = true,
                           .encoded = false,
                           .lock = NULL,
                           .data_send = channel_data_send_to_swv,
                           .cbuf = { .head = 0, .tail = 0, .buf = NULL, .buf_sz = 0, .space = 0 },
                           .buf = channel_buf[TRACE_CHANNEL_SWV],
                           .buf_sz = sizeof(channel_buf[TRACE_CHANNEL_SWV]),
                           .levels = (uint8_t)(TRACE_LVL_ENABLE(TRACE_LVL_INFO) |
                           TRACE_LVL_ENABLE(TRACE_LVL_WARN) |
                           TRACE_LVL_ENABLE(TRACE_LVL_ERROR) |
                           TRACE_LVL_ENABLE(TRACE_LVL_FATAL) |
                           TRACE_LVL_ENABLE(TRACE_LVL_DEBUG)),
                           .task_id = TASK_ID_TRACE_SWV
                          }
#endif
};

// clang-format on
/*
***************************************************************************************************
* EXTERNAL (NON STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

void trace_config_init(trace_channel_t **const chan_list, uint32_t *const chan_list_sz)
{
    BREAK_ASSERT(NULL != chan_list);
    BREAK_ASSERT(NULL != chan_list_sz);

    trace_uart_init();

    for (uint32_t i = 0; i < CDEF_ELEMENT_COUNT(channel_list); i++)
    {
        /* Inb_active channels shouldn't occupy OS resources */
        if (false != channel_list[i].b_active)
        {
            thread_attr[i].attr_bits  = osThreadDetached;
            thread_attr[i].name       = channel_list[i].name;
            thread_attr[i].priority   = osPriorityNormal;
            thread_attr[i].cb_mem     = NULL;
            thread_attr[i].cb_size    = 0U;
            thread_attr[i].stack_mem  = NULL;
            thread_attr[i].stack_size = thread_stack_sz[i];
            thread_attr[i].tz_module  = 0U;
            thread_attr[i].reserved   = 0U;

            thread_handle[i] = osThreadNew(thread_routine[i], NULL, &thread_attr[i]);
            task_mon_register_for_stats(channel_list[i].task_id, thread_handle[i]);

            BREAK_ASSERT(NULL != thread_handle[i]);
        }
    }

    *chan_list    = channel_list;
    *chan_list_sz = CDEF_ELEMENT_COUNT(channel_list);
}

trace_lock_t trace_lock_new(void)
{
    osMutexAttr_t attr = {
        .name      = NULL,
        .attr_bits = osMutexRecursive | osMutexPrioInherit,
        .cb_mem    = NULL,
        .cb_size   = 0U
    };

    return osMutexNew(&attr);
}

void trace_lock_acquire(trace_lock_t lock)
{
    if (NULL != lock)
    {
        (void)osMutexAcquire(lock, osWaitForever);
    }
    else
    {
        BREAK_ASSERT(false);
    }
}

void trace_lock_release(trace_lock_t lock)
{
    if (NULL != lock)
    {
        (void)osMutexRelease(lock);
    }
    else
    {
        BREAK_ASSERT(false);
    }
}

/*
***************************************************************************************************
* INTERNAL (STATIC) ROUTINES DEFINITION
***************************************************************************************************
*/

static void thread_uart(void *args)
{
    (void)args;
    uint8_t counter = 0;

    task_mon_set_task_policy(TASK_ID_TRACE_UART, TASK_MON_POLICY_DONT_CARE);
    task_mon_task_initialized(TASK_ID_TRACE_UART);

    while (1)
    {
        trace_serve_chan(
            (uint32_t)TRACE_CHANNEL_UART,
            work_buf[TRACE_CHANNEL_UART],
            sizeof(work_buf[TRACE_CHANNEL_UART]));
        counter++;
        if (STACK_CHECK_COUNTER == counter)
        {
            counter = 0;
            task_mon_low_stack_check(TASK_ID_TRACE_UART);
        }
        osDelay(TRACE_SERVE_MS);
    }
}

static void thread_file(void *args)
{
    (void)args;
    uint8_t counter = 0;

    task_mon_set_task_policy(TASK_ID_TRACE_FILE, TASK_MON_POLICY_DONT_CARE);
    task_mon_task_initialized(TASK_ID_TRACE_FILE);

    while (1)
    {
        trace_serve_chan(TRACE_CHANNEL_FILE,
                         work_buf[TRACE_CHANNEL_FILE],
                         sizeof(work_buf[TRACE_CHANNEL_FILE]));

        if (STACK_CHECK_COUNTER == counter)
        {
            counter = 0;
            task_mon_low_stack_check(TASK_ID_TRACE_FILE);
        }
        counter++;
        osDelay(TRACE_SERVE_MS);
    }
}

static uint32_t channel_data_send_to_uart(const uint8_t *data, const uint32_t data_sz)
{
    BREAK_ASSERT(NULL != data);
    BREAK_ASSERT(0 < data_sz);

    uint32_t transmitted_sz = data_sz;

    /* Check in case the UART instance is uninitialised and
    prevents passing null pointers to the transmit function in case of run time configuration
    and transmit timeout set according to data_sz */
    if ((NULL != huart.Instance) &&
        (HAL_OK != HAL_UART_Transmit(&huart, (uint8_t *)data, (uint16_t)data_sz, data_sz)))
    {
        transmitted_sz = 0;
    }

    return transmitted_sz;
}

static uint32_t channel_data_send_to_file(const uint8_t *data, const uint32_t data_sz)
{
    BREAK_ASSERT(NULL != data);
    BREAK_ASSERT(0 < data_sz);

    uint32_t written_data = 0;
    uint32_t bw           = 0;

    if (FM_RES_OK == rlf_open(&rolling_file))
    {
        if (FM_RES_OK == rlf_write(&rolling_file, data, data_sz, &bw))
        {
            written_data = bw;
        }

        (void)rlf_close(&rolling_file);
    }

    return written_data;
}

#if defined(STM32_SWV_SUPPORT) && defined(DEBUG_ENABLED)
static void thread_swv(void *args)
{
    (void)args;
    uint8_t counter = 0;

    task_mon_set_task_policy(TASK_ID_TRACE_SWV, TASK_MON_POLICY_DONT_CARE);
    task_mon_task_initialized(TASK_ID_TRACE_SWV);

    while (1)
    {
        trace_serve_chan(TRACE_CHANNEL_SWV,
                         work_buf[TRACE_CHANNEL_SWV],
                         sizeof(work_buf[TRACE_CHANNEL_SWV]));

        counter++;
        if (STACK_CHECK_COUNTER == counter)
        {
            counter = 0;
            task_mon_low_stack_check(TASK_ID_TRACE_SWV);
        }
        osDelay(TRACE_SERVE_MS);
    }
}

static uint32_t channel_data_send_to_swv(const uint8_t *data, const uint32_t data_sz)
{
    BREAK_ASSERT(NULL != data);
    BREAK_ASSERT(0 < data_sz);

    for (uint32_t i = 0; i < data_sz; i++)
    {
        ITM_SendChar(data[i]);
    }

    return data_sz;
}
#endif

/**
 * @brief Initialization of UART for the UART trace output.
 */
static void trace_uart_init(void)
{
    huart.Instance = NULL;

    if (true != sys_conf_is_module_active(SYS_MODULE_ID_GNSS))
    {
        huart.Instance = UART5;
    }
    else
    {
#if !defined(SLIP_SUPPORT_ENABLED) || !defined(LWIP_SUPPORT_ENABLED)
        huart.Instance = UART8;
#else
        huart.Instance = UART7;
#endif
    }

    if (huart.Instance != NULL)
    {
        huart.Init.BaudRate               = TRACE_UART_BAUD_RATE;
        huart.Init.WordLength             = UART_WORDLENGTH_8B;
        huart.Init.StopBits               = UART_STOPBITS_1;
        huart.Init.Parity                 = UART_PARITY_NONE;
        huart.Init.Mode                   = UART_MODE_TX;
        huart.Init.HwFlowCtl              = UART_HWCONTROL_NONE;
        huart.Init.OverSampling           = UART_OVERSAMPLING_16;
        huart.Init.OneBitSampling         = UART_ONE_BIT_SAMPLE_DISABLE;
        huart.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;

        if (HAL_OK != HAL_UART_Init(&huart))
        {
            /* Trace channel for UART shall not be used */
            channel_list[TRACE_CHANNEL_UART].b_active = false;
            BREAK_ASSERT(false);
        }
    }
    else
    {
        /* All UARTs are occupied, so there will be no trace output via UART */
        channel_list[TRACE_CHANNEL_UART].b_active = false;
    }
}
