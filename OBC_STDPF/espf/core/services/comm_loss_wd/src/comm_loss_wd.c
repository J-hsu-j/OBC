/*
 * Copyright (c) 2020-2024 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup Services
 * @{
 *
 * @defgroup comm_loss_wd
 * @{
 *
 * @file comm_loss_wd.c
 * @brief comm_loss_wd service core implementation
 *
 * @}
 * @}
 */
#include "timer.h"
#include "cmsis_os2.h"
#include "taskmon.h"
#include "datetime.h"
#include "taskmon_stat.h"
#include "comm_loss_wd.h"
#include "ESSA_StackConfigTypes.h"
#include "core/services/espsi/fp/UHF/v0.5/UHF_client/FP_UHFProtocolClient.h"
#include "nvm.h"
#include "arch/stm32h753iit/drivers/radio/sband_tmtc/fp/SBAND_TMTC/v1.12/SBAND_TMTC_client/FP_SBAND_TMTCProtocolClient.h"
#include "arch/stm32h753iit/drivers/power/eps_ii/fp/EPSII_PDM_1/v1.0/EPSII_PDM_1_client/FP_EPSII_PDM_1ProtocolClient.h"
#include "arch/stm32h753iit/drivers/power/eps_ii/fp/EPSII_PDM_1/v1.0/EPSII_PDM_1_client/FP_EPSII_PDM_1ProtocolTypes.h"
#include "config/beacons/beacons_cfg_user.h"
#include "eps_ctrl.h"
#include "eps_ctrl_cfg.h"

#define MS_IN_1_MIN            (60000U)
#define MINIMUM_TIMEOUT_PERIOD (1U)

static timer_handle_t comm_loss_wd_timeout_timer; /**< Timer handler used by the WD definition. */

static eps_ctrl_result_t eps_ctrl_result; /**< Variable to get the result from EPS control execution function. */

static uint32_t timeout_loop_cnt      = 0; /**< Counter showing how many loops the WD did before initiating reboot. */
static uint32_t reboot_iterations_cnt = 0; /**< Counter showing actual iterations to reboot after timeout expired. */

// UHF related counters registers
static uint32_t uhf_gs_handshake_register;      /**< Current counter value of the UHF GS Handshake register. */
static uint32_t uhf_gs_handshake_register_prev; /**< Previous counter value of the UHF GS Handshake register. */
static uint32_t uhf_rx_packets_count;           /**< Current counter value of the UHF RX counter register. */
static uint32_t uhf_rx_packets_count_prev;      /**< Previous counter value of the UHF RX counter register. */

// SBAND TMTC related counters registers
static uint32_t sband_gs_handshake_register;      /**< Current counter value of the SBAND TMTC GS Handshake register. */
static uint32_t sband_gs_handshake_register_prev; /**< Previous counter value of the SBAND TMTC GS Handshake register. */
static uint32_t sband_rx_packets_count;           /**< Current counter value of the SBAND TMTC RX counter register. */
static uint32_t sband_rx_packets_count_prev;      /**< Previous counter value of the SBAND TMTC RX counter register. */

static mac_address_book_t address_book = { 0 }; /**< Mac address book variable to get radio module address from the NVM. */

static osThreadId_t start_comm_loss_wd_task; /**< Defining the communication lost WD task. */

// Configure communication loss WD task parameters,
static const osThreadAttr_t comm_loss_wd_task_attributes = {
    .name       = "CommLossWdTask",
    .priority   = (osPriority_t)osPriorityNormal,
    .stack_size = 1024
};

static osMutexId_t         comm_loss_wd_mutex_id; /**< Defining MUTEX to protect comm_loss_wd_nvm_data. */
static const osMutexAttr_t wd_lock_attr = { "CommLossMutex", 0, NULL, 0 };

// Init ground station communication loss WatchDog.
// Create and set default communication loss timeout and minimal value 24h;
void comm_loss_wd_init(void)
{
    // Should avoid any potential risk of shorter WD timeout period.
    // Just in case something messed up in the NVM we have to avoid deadlock.
    if (comm_loss_wd_get_timeout() < MINIMUM_TIMEOUT_PERIOD) // Just for testing is 1 minute here should be 24h in release version
    {
        comm_loss_wd_set_timeout(1);
    }

    comm_loss_wd_mutex_id = osMutexNew(&wd_lock_attr);
    BREAK_ASSERT(comm_loss_wd_mutex_id != NULL); // Ensure mutex was created successfully

    start_comm_loss_wd_task = osThreadNew(comm_loss_wd_task, NULL, &comm_loss_wd_task_attributes);
    task_mon_register_for_stats(TASK_ID_APP, start_comm_loss_wd_task);
    BREAK_ASSERT(start_comm_loss_wd_task);
}

// Call ground station communication loss WatchDog service.
void comm_loss_wd_task(void *argument)
{
    task_mon_task_initialized(TASK_ID_APP); // The task is initialized and is ready.

    comm_loss_wd_nvm_data_t comm_loss_wd_nvm_data; /**< Data field required by the communication loss WD stored in NVM. */

    Nvm_GetBlockById(NVM_MAC_ADDRESS_BOOK, &address_book);

    Nvm_GetBlockById(NVM_BLOCK_COMM_LOSS_WD, &comm_loss_wd_nvm_data);

    ReqContext_t sband_req_ctx = { .nAddr            = (uint8_t)address_book.a_mac_address[MAC_ADDR_SBAND_TMTC], // Default 0x44,
                                   .nInterfaceNumber = ESSASNI_SYS_PRI,
                                   .netType          = ESSASNETT_INTERNAL,
                                   .seqId            = 0 };

    ReqContext_t uhf_req_ctx = { .nAddr            = (uint8_t)address_book.a_mac_address[MAC_ADDR_UHF], // Default: BEACONS_UHF_SINK_ESPS_ADDRESS,
                                 .nInterfaceNumber = ESSASNI_SYS_PRI,
                                 .netType          = ESSASNETT_INTERNAL,
                                 .seqId            = 0 };

    timer_start(&comm_loss_wd_timeout_timer);

    while (1)
    {
        Nvm_GetBlockById(NVM_BLOCK_COMM_LOSS_WD, &comm_loss_wd_nvm_data);

        if (osMutexAcquire(comm_loss_wd_mutex_id, osWaitForever) == osOK)
        {
            if ((uhf_gs_handshake_register_prev == uhf_gs_handshake_register) &&
                (uhf_rx_packets_count_prev == uhf_rx_packets_count) &&
                (sband_rx_packets_count_prev == sband_rx_packets_count) &&
                (sband_gs_handshake_register_prev == sband_gs_handshake_register) &&
                (true == comm_loss_wd_nvm_data.comm_loss_wd_enable))
            {
                if (timer_is_elapsed(&comm_loss_wd_timeout_timer, (comm_loss_wd_nvm_data.comm_loss_wd_timeout_period_min * MS_IN_1_MIN))) // Timeout is in minutes so multiply by 60000
                {
                    // Restart WD timer again
                    timer_start(&comm_loss_wd_timeout_timer);

                    // Run system reboot procedure...
                    reboot_iterations_cnt++;
                    TODO("Execute real power ON/OFF command here, after integration of EPS3!")

                    eps_ctrl_result = EPS_CTRL_FAIL;
                }
            }
            else
            {
                timer_start(&comm_loss_wd_timeout_timer); // Update and ReStart the timeout counter
            }
            osMutexRelease(comm_loss_wd_mutex_id);
        }

        // Get SBAND_TMTC related communication status:
        SBAND_TMTC_ReadErrorCountersReq(&sband_req_ctx); // Request handshake counter from SBAND TMTC
        SBAND_TMTC_GetPacketCountersReq(&sband_req_ctx); // Request number of packets counter from SBAND TMTC

        // Get UHF related communication status:
        UHF_ReadCountersReq(&uhf_req_ctx);          // Request handshake counter reading from UHF
        UHF_ReadNumberOfRxPacketsReq(&uhf_req_ctx); // Request number of RX packets from UHF

        osDelay(10000); // Task loop delay time and update counters time.

        timeout_loop_cnt++; // Test counter for easy debug, not required by functionality!
    }
}

// Set ground station communication loss WatchDog timeout period.
bool comm_loss_wd_set_timeout(uint32_t timeout_period_min)
{
    // Should not be possible to set too short WD timeout period.
    TODO("Do be defined in detailed requirements, currently set to 1 minute only for testing!")
    if (timeout_period_min > MINIMUM_TIMEOUT_PERIOD)
    {
        comm_loss_wd_nvm_data_t temp_comm_loss_wd_nvm_data;

        Nvm_GetBlockById(NVM_BLOCK_COMM_LOSS_WD, &temp_comm_loss_wd_nvm_data);

        temp_comm_loss_wd_nvm_data.comm_loss_wd_timeout_period_min = timeout_period_min;

        Nvm_SetBlockById(NVM_BLOCK_COMM_LOSS_WD, &temp_comm_loss_wd_nvm_data, NVMSETBLOCK_STORE_IMMEDIATELY);

        return true;
    }
    return false;
}

// Set ground station communication loss WatchDog Enable/Disable.
bool comm_loss_wd_set_enable(bool enable_flag)
{
    comm_loss_wd_nvm_data_t temp_comm_loss_wd_nvm_data;

    Nvm_GetBlockById(NVM_BLOCK_COMM_LOSS_WD, &temp_comm_loss_wd_nvm_data);

    temp_comm_loss_wd_nvm_data.comm_loss_wd_enable = enable_flag;

    Nvm_SetBlockById(NVM_BLOCK_COMM_LOSS_WD, &temp_comm_loss_wd_nvm_data, NVMSETBLOCK_STORE_IMMEDIATELY);

    return true;
}

// Get current ground station communication loss WatchDog timeout period in minutes.
uint32_t comm_loss_wd_get_timeout(void)
{
    comm_loss_wd_nvm_data_t temp_comm_loss_wd_nvm_data;

    Nvm_GetBlockById(NVM_BLOCK_COMM_LOSS_WD, &temp_comm_loss_wd_nvm_data);

    return temp_comm_loss_wd_nvm_data.comm_loss_wd_timeout_period_min;
}

// Get current ground station communication loss WatchDog enable status.
bool comm_loss_wd_get_enable(void)
{
    comm_loss_wd_nvm_data_t temp_comm_loss_wd_nvm_data;

    Nvm_GetBlockById(NVM_BLOCK_COMM_LOSS_WD, &temp_comm_loss_wd_nvm_data);

    return temp_comm_loss_wd_nvm_data.comm_loss_wd_enable;
}

// Read back counter registers from the UHF radio module
void comm_loss_wd_check_uhf_counter_registers(const UHFReadCountersResponseData_t *const p_uhf_counters)
{
    BREAK_ASSERT(NULL != p_uhf_counters);

    if (NULL == p_uhf_counters)
    {
        return;
    }

    if (osMutexAcquire(comm_loss_wd_mutex_id, osWaitForever) == osOK)
    {
        // Save current handshake counter and prepare to compare with the new count later.
        uhf_gs_handshake_register_prev = uhf_gs_handshake_register;

        // Get new handshake counter and prepare to compare with the new count later.
        uhf_gs_handshake_register = p_uhf_counters->sCfg.u32GS_Handshakes;

        osMutexRelease(comm_loss_wd_mutex_id);
    }
}

// Read back RX packet count from the UHF radio module
void comm_loss_wd_check_uhf_rx_packet_count(const UHFReadNumberOfRxPacketsResponseData_t *const p_uhf_rx_packets)
{
    BREAK_ASSERT(NULL != p_uhf_rx_packets);

    if (NULL == p_uhf_rx_packets)
    {
        return;
    }

    if (osMutexAcquire(comm_loss_wd_mutex_id, osWaitForever) == osOK)
    {
        // Save current RX packets number and prepare to compare with the new count later.
        uhf_rx_packets_count_prev = uhf_rx_packets_count;

        // Get new RX packets number and prepare to compare with the new count later.
        uhf_rx_packets_count = p_uhf_rx_packets->u32Packets;
        osMutexRelease(comm_loss_wd_mutex_id);
    }
}

// Read back counter registers from the SBAND radio module
void comm_loss_wd_check_sband_error_counters(const SBAND_TMTCReadErrorCountersResponseData_t *const p_tmtc_err_counters)
{
    BREAK_ASSERT(NULL != p_tmtc_err_counters);

    if (NULL == p_tmtc_err_counters)
    {
        return;
    }

    if (osMutexAcquire(comm_loss_wd_mutex_id, osWaitForever) == osOK)
    {
        // Save current handshake counter and prepare to compare with the new count later.
        sband_gs_handshake_register_prev = sband_gs_handshake_register;

        // Get new handshake counter and prepare to compare with the new count later.
        sband_gs_handshake_register = p_tmtc_err_counters->sErrCounters.u32GS_Handshakes;

        osMutexRelease(comm_loss_wd_mutex_id);
    }
}

// Read back RX packet count from the SBAND radio module
void comm_loss_wd_check_sband_packet_counters(const SBAND_TMTCGetPacketCountersResponseData_t *const p_sband_packets)
{
    BREAK_ASSERT(NULL != p_sband_packets);

    if (NULL == p_sband_packets)
    {
        return;
    }

    if (osMutexAcquire(comm_loss_wd_mutex_id, osWaitForever) == osOK)
    {
        // Save current RX packets number and prepare to compare with the new count later.
        sband_rx_packets_count_prev = sband_rx_packets_count;

        // Get new RX packets number and prepare to compare with the new count later.
        sband_rx_packets_count = p_sband_packets->sCounters.u32ReceivedPackets;

        osMutexRelease(comm_loss_wd_mutex_id);
    }
}
