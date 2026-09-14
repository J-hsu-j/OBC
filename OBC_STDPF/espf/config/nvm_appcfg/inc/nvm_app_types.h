/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/*
 * datapool_types.h
 *
 *  Created on: Jun 25, 2021
 *      Author: Ivan Petrov
 */

#ifndef NVM_INC_NVM_APP_TYPES_H_
#define NVM_INC_NVM_APP_TYPES_H_

#include "es_cdef.h"
#include "nvm_bootcfg/inc/nvm_boot_types.h"
#include "datacache.h"
#include "fp/conops/v2.0/conops_server/FP_conopsProtocolTypes.h"
#include "fp/onboard_sched/v0.1/onboard_sched_server/FP_onboard_schedProtocolTypes.h"
#include "fp/telemetry/v2.0/telemetry_server/FP_telemetryProtocolTypes.h"
#include "fp/Beacons/v1.0/Beacons_server/FP_BeaconsProtocolTypes.h"
#include "fp/OBC_CUBEADCS_GEN2/v5.0/OBC_CUBEADCS_GEN2_server/FP_OBC_CUBEADCS_GEN2ProtocolTypes.h"
#include "sys_time.h"
#include "fp/gnss/v1.2/gnss_server/FP_gnssProtocolTypes.h"
#include "coordsys_types.h"
#include "sds_events_types.h"
#include "adis16265_driver.h"
#include "aocs_pm.h"
#include "drv_gpo.h"
#include "onboard_sched_cfg.h"
#include "fdir_srv_cfg.h"
#include "../../../arch/stm32h753iit/drivers/positioning/libcubeadcs/inc/cubeadcs_tc_tlm_descr.h"
#include "../../../arch/stm32h753iit/drivers/positioning/libcubeadcs/cfg/cubeadcs_sysstate_cfg.h"
#include "inc/cubeadcs_gen2_types.h"
#include "inc/cubeadcs_gen2_sys_states.h"
#include "inc/cubeadcs_gen2_tlm.h"
#include "../../../arch/stm32h753iit/drivers/arm_fault_handler/inc/arm_fault_handler.h"
#include "csp_access.h"
#include "fm_def.h"

#include "fp/SDS/v1.0/SDS_server/FP_SDSProtocolTypes.h"
#include "fp/nvm_eps/v0.1/nvm_eps_server/FP_nvm_epsProtocolTypes.h"

#define NVM_BLOCK_DEFINE_START(blockType) \
    typedef struct                        \
    {
#define NVM_BLOCK_DEFINE_END(blockType) \
    uint32_t u32Crc;                    \
    }                                   \
    blockType;

#pragma pack(push)
#pragma pack(1)

/** @brief Number of allocated NVM fault blocks */
#define MAX_FAULT_BLOCKS_CNT (5U)

/** @brief Number of preallocated slots for beacon messages.
 *
 * A DataCache entry type can be associated to any of those slots for transmission inside beacon frames.
 */
#ifndef MAX_BEACON_MSG_SLOTS
#define MAX_BEACON_MSG_SLOTS (20U)
#endif

/** @brief Maximum number of presets to keep as different becon slot configurations which can be changed
 *            at runtime. Usually this is tied to the operational modes but different naming is kept here for better
 *            abstraction.
 */
#ifndef BEACON_PRESETS_COUNT
#define BEACON_PRESETS_COUNT (3U)
#endif

/** @brief This number denotes an invalid becaon slot assignment */
#define INVALID_BEACON_SLOT_ASSIGNMENT (0xFFFFU)

/** @brief This number denotes an invalid telemetry slot assignment */
#define INVALID_TLM_SLOT_ASSIGNMENT (0xFFFFU)

/** @brief Maximum number of presets to keep as different telemetry slot configurations which can be changed
 *            at runtime. Usually this is tied to the operational modes but different naming is kept here for better
 *            abstraction.
 */
#ifndef TELEMETRY_PRESETS_COUNT
#define TELEMETRY_PRESETS_COUNT (3U)
#endif

/** @brief Maximum number of configurable telemetry entries for each individual preset.
 */
#ifndef TELEMETRY_MAX_CONFIGURABLE_ENTRIES
#define TELEMETRY_MAX_CONFIGURABLE_ENTRIES (10U)
#endif

typedef struct
{
    bool pull_up_4k7;
    bool pull_up_10k;
} bus_pull_up_state_t;

typedef enum
{
    I2C_BUS_SYSTEM,
    I2C_BUS_PAYLOAD,
    I2C_BUS_MAX
} i2c_bus_t;

/** @brief MAC addresses for any external modules
 */

enum
{
    MAC_ADDR_EPS_I,
    MAC_ADDR_EPS_II_BP,
    MAC_ADDR_EPS_II_PDM,
    MAC_ADDR_UHF,
    MAC_ADDR_SBAND_TMTC,
    MAC_ADDR_SP1,
    MAC_ADDR_SP2,
    MAC_ADDR_SP3,
    MAC_ADDR_SP4,
    MAC_ADDR_PAYLOAD_1,
    MAC_ADDR_PAYLOAD_2,
    MAC_ADDR_RESERVED_1,
    MAC_ADDR_RESERVED_2,
    MAC_ADDR_RESERVED_3,
    MAC_ADDR_RESERVED_4,
    MAC_ADDR_BOOK_MAX
};

// Note: ensure this parameter is aligned to the maximum value in fm_result_t enum
#define FM_VOL_API_ERR_MAX_CNT (FM_RES_INVALID_PARAMETER + 1)

NVM_BLOCK_DEFINE_START(reserved_dummy_t)
uint8_t dummy;
NVM_BLOCK_DEFINE_END(reserved_dummy_t)

NVM_BLOCK_DEFINE_START(beacons_cfg_t)
safe_bool_t beacons_en;
safe_bool_t chunk_based_transfer_en;
uint32_t    bcn_tx_period;
uint32_t    bcn_inter_frame_period;
NVM_BLOCK_DEFINE_END(beacons_cfg_t)

NVM_BLOCK_DEFINE_START(beacons_presets_cfg_t)
uint16_t beacon_slots_setting[BEACON_PRESETS_COUNT][MAX_BEACON_MSG_SLOTS];
NVM_BLOCK_DEFINE_END(beacons_presets_cfg_t)

// The following checks ensure that the FIDL-specified sizes of the beacons configuration are at least matching the size of the allocated NVM buffer.
static_assert(sizeof(((BeaconssetBeaconPresetConfigRequestData_t *)NULL)->au16Beacon_preset_cfg) == sizeof(((beacons_presets_cfg_t *)NULL)->beacon_slots_setting));
static_assert(sizeof(((BeaconsgetBeaconPresetConfigResponseData_t *)NULL)->au16Beacon_preset_cfg) == sizeof(((beacons_presets_cfg_t *)NULL)->beacon_slots_setting));

NVM_BLOCK_DEFINE_START(conops_config_t)
CONOPS_ThresholdValues_t thresh;
CONOPS_ControlMode_t     def_control[CONOPS_MODESWITHDEFCTRL_MAX_CNT];
NVM_BLOCK_DEFINE_END(conops_config_t)

NVM_BLOCK_DEFINE_START(telemetry_cfg_t)
TELEMETRY_tlm_general_cfg_t params;
NVM_BLOCK_DEFINE_END(telemetry_cfg_t)

NVM_BLOCK_DEFINE_START(telemetry_preset_cfg_t)
TELEMETRY_tlm_preset_cfg_t tlm_slots_setting[TELEMETRY_PRESETS_COUNT][TELEMETRY_MAX_CONFIGURABLE_ENTRIES];
NVM_BLOCK_DEFINE_END(telemetry_preset_cfg_t)

// The following checks ensure that the FIDL-specified sizes of the telemetry configuration are at least matching the size of the allocated NVM buffer.
static_assert(sizeof(((telemetrysetTelemetryPresetConfigRequestData_t *)NULL)->asTelemetry_preset_cfg) == sizeof(((telemetry_preset_cfg_t *)NULL)->tlm_slots_setting));
static_assert(sizeof(((telemetrygetTelemetryPresetConfigResponseData_t *)NULL)->asTelemetry_preset_cfg) == sizeof(((telemetry_preset_cfg_t *)NULL)->tlm_slots_setting));

NVM_BLOCK_DEFINE_START(telemetry_file_cfg_t)
TELEMETRY_tlm_file_logging_type_t   cfg_type; /**< Active configuration type for file-based storage of telemetry data */
TELEMETRY_tlm_file_size_limit_cfg_t params;   /**< File telemetry configuration parameters */
NVM_BLOCK_DEFINE_END(telemetry_file_cfg_t)

NVM_BLOCK_DEFINE_START(telemetry_persistent_data_t)
uint16_t last_file_slot_idx; /**< holds the index of the last written telemetry file slot */
NVM_BLOCK_DEFINE_END(telemetry_persistent_data_t)

NVM_BLOCK_DEFINE_START(EPS_M_Config_t)
safe_bool_t reserved1;
safe_bool_t reserved2;
safe_bool_t reserved3;
safe_bool_t reserved4;
safe_bool_t reserved5;
safe_bool_t reserved6;
int16_t     reserved7;
safe_bool_t reserved8;
safe_bool_t reserved9;
NVM_BLOCK_DEFINE_END(EPS_M_Config_t)

NVM_BLOCK_DEFINE_START(cubeadcs_err_handl_cfg_t)
safe_bool_t en_cubeadcs_err_handl;
NVM_BLOCK_DEFINE_END(cubeadcs_err_handl_cfg_t)

NVM_BLOCK_DEFINE_START(cubeadcs_status_t)
uint8_t  commissioning;
uint8_t  node_status;
uint16_t runtime_latched_errors;
NVM_BLOCK_DEFINE_END(cubeadcs_status_t)

NVM_BLOCK_DEFINE_START(i2c_config_t)
/**< I2C resistor pull-ups configuration
 *      - each entry of the array corresponds to an I2C bus
 * */
bus_pull_up_state_t i2c_pull_up_config[I2C_BUS_MAX];
NVM_BLOCK_DEFINE_END(i2c_config_t)

NVM_BLOCK_DEFINE_START(cubeadcs_angle_limits_t)
int32_t stable_pointing_threshold_angle;      /* Value is in millidegrees to allow the use of integers for fine precision */
int32_t stable_pointing_threshold_angle_rate; /* Value is in millidegrees to allow to allow the use of integers for fine precision */
NVM_BLOCK_DEFINE_END(cubeadcs_angle_limits_t)

NVM_BLOCK_DEFINE_START(aocs_pm_config_t)
aocs_pm_parameters_t parameters;
NVM_BLOCK_DEFINE_END(aocs_pm_config_t)

NVM_BLOCK_DEFINE_START(aocs_pm_thresholds_t)
aocs_pm_threshold_values_t value[3];
NVM_BLOCK_DEFINE_END(aocs_pm_thresholds_t)

NVM_BLOCK_DEFINE_START(sds_sens_read_freq_t)
safe_bool_t      enable;
sds_events_cfg_t sens_cfg[SDS_SENSTYPECFGNUM_MAX_CNT];
NVM_BLOCK_DEFINE_END(sds_sens_read_freq_t)

#define AES_KEY_SIZE_BYTES (32U)

NVM_BLOCK_DEFINE_START(crypto_cfg_t)
uint8_t aes_key[AES_KEY_SIZE_BYTES];
NVM_BLOCK_DEFINE_END(crypto_cfg_t)

NVM_BLOCK_DEFINE_START(cubeadcs_sim_mode_t)
safe_bool_t en_sim_mode;
NVM_BLOCK_DEFINE_END(cubeadcs_sim_mode_t)

NVM_BLOCK_DEFINE_START(rtc_calib_data_t)
uint16_t               calm;
sys_time_calp_pulses_t calp;
NVM_BLOCK_DEFINE_END(rtc_calib_data_t)

NVM_BLOCK_DEFINE_START(gyroscope_configs_t)
gyroscope_t gyroscope_array[3];
NVM_BLOCK_DEFINE_END(gyroscope_configs_t)

NVM_BLOCK_DEFINE_START(fm_stats_t)
uint16_t api_err_counters[FM_VOL_API_ERR_MAX_CNT];
NVM_BLOCK_DEFINE_END(fm_stats_t)

NVM_BLOCK_DEFINE_START(cubeADCS_sys_state_cfg_t)
CubeADCS_Cfg_t asCubeADCS_SysStates[eCUBEADCS_CFGTYPE_NUMBER];
NVM_BLOCK_DEFINE_END(cubeADCS_sys_state_cfg_t)

NVM_BLOCK_DEFINE_START(mac_address_book_t)
uint8_t a_mac_address[MAC_ADDR_BOOK_MAX];
uint8_t a_eps_batterypack_addresses[NVM_EPS_EPSBPIDTYPE_MAX_CNT];
uint8_t a_eps_iii_addresses[NVM_EPS_EPSIIIBPIDTYPE_MAX_CNT + NVM_EPS_EPSIIIPDMAIDTYPE_MAX_CNT + NVM_EPS_EPSIIIPDMBIDTYPE_MAX_CNT + NVM_EPS_EPSIIIEXPANDERIDTYPE_MAX_CNT + NVM_EPS_EPSIIIINPUTSTAGEIDTYPE_MAX_CNT];
NVM_BLOCK_DEFINE_END(mac_address_book_t)

NVM_BLOCK_DEFINE_START(cubeadcs_gen2_sys_states_cfg_t)
cubeadcs_gen2_sys_state_core_t sys_state_cfg[OBC_CUBEADCS_GEN2_SYS_STATES_MAX_CNT];
NVM_BLOCK_DEFINE_END(cubeadcs_gen2_sys_states_cfg_t)

NVM_BLOCK_DEFINE_START(cubeadcs_gen2_tlm_cfg_t)
bool mask[CUBEADCS_GEN2_TLM_MASK_MAX][CUBEADCS_GEN2_TLM_MASK_BYTES_MAX];
NVM_BLOCK_DEFINE_END(cubeadcs_gen2_tlm_cfg_t)

NVM_BLOCK_DEFINE_START(adcs_cms_status_t)
uint8_t cms_status;
NVM_BLOCK_DEFINE_END(adcs_cms_status_t)

NVM_BLOCK_DEFINE_START(fault_index_t)
uint8_t next_free_slot_index; /*<< Fault NVM block index to which the next write will take place */
uint8_t free_slots;           /*<< Number of free fault block slots available */
NVM_BLOCK_DEFINE_END(fault_index_t)

NVM_BLOCK_DEFINE_START(fault_block_t)
persisted_ram_x_frame_t x_frame; /*<< Exception frame data */
NVM_BLOCK_DEFINE_END(fault_block_t)


NVM_BLOCK_DEFINE_START(gpo_config_t)
bool pin_value[OBC_OUT_MAX_COUNT];
NVM_BLOCK_DEFINE_END(gpo_config_t)

NVM_BLOCK_DEFINE_START(onboard_sched_nvm_data_t)
uint32_t                   active_slot_offset;
ONBOARD_SCHED_SchedState_t sched_state;
char                       last_schedule[SCHED_MAX_NAME_BUF_LEN];
NVM_BLOCK_DEFINE_END(onboard_sched_nvm_data_t)

NVM_BLOCK_DEFINE_START(fdir_srv_nvm_data_t)
uint8_t fault_automatic_clear_limit;
bool    fault_detection_active[FDIR_FAULT_COUNT];
NVM_BLOCK_DEFINE_END(fdir_srv_nvm_data_t)

NVM_BLOCK_DEFINE_START(conops_nvm_data_t)
safe_bool_t force_enable_payload;
NVM_BLOCK_DEFINE_END(conops_nvm_data_t)

NVM_BLOCK_DEFINE_START(xband_fe_config_t)
uint8_t  target_node_addr; /**< CSP node address of the XBand FE module */
uint8_t  port;             /**< CSP target port for XBand FE module requests */
uint8_t  prio;             /**< CSP message priority to use when sending requests to XBand FE module */
uint32_t opts;             /**< CSP connection options for XBand FE module */
NVM_BLOCK_DEFINE_END(xband_fe_config_t)

NVM_BLOCK_DEFINE_START(nvm_block_gnss_comm_settings_t)
GNSS_BaudRate_t gnss_comm_uart_baudrate;
NVM_BLOCK_DEFINE_END(nvm_block_gnss_comm_settings_t)

NVM_BLOCK_DEFINE_START(comm_loss_wd_nvm_data_t)
uint32_t comm_loss_wd_timeout_period_min;
bool     comm_loss_wd_enable;
NVM_BLOCK_DEFINE_END(comm_loss_wd_nvm_data_t)

NVM_BLOCK_DEFINE_START(cubeadcs_gen2_fdir_counter_t)
uint8_t cubeadcs_gen2_counter_for_resets;
uint8_t cubeadcs_gen2_counter_for_power_cycles;
bool    cubeadcs_gen2_reset_flag;
NVM_BLOCK_DEFINE_END(cubeadcs_gen2_fdir_counter_t)

NVM_BLOCK_DEFINE_START(task_stat_config_nvm_t)
bool        enabled;                    /**< General enable for all statistics. */
bool        logging;                    /**< General logging enable for all statistics */
UBaseType_t priority;                   /**< Set the priority of the statistics task. May be 1-55, recommended default is 8(Low Priority) */
uint32_t    period;                     /**< The period for sampling in milliseconds. Default is 1000 ms (ie 1 second). */
char        id_table_file[FM_MAX_PATH]; /**< The file name for the task id table. */
NVM_BLOCK_DEFINE_END(task_stat_config_nvm_t)

NVM_BLOCK_DEFINE_START(task_stat_config_specific_nvm_t)
bool enabled[TASK_ID_MAX]; /**< Enable statistics for a specific task. */
bool logging[TASK_ID_MAX]; /**< Enable logging for a specific task */
NVM_BLOCK_DEFINE_END(task_stat_config_specific_nvm_t)

#pragma pack(pop)

#endif /* NVM_INC_NVM_APP_TYPES_H_ */
