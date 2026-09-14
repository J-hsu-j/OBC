/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/**
 * @addtogroup eps_ii
 * @{
 *
 * @file     eps_ii_telemetry.c
 * @brief    Telemetry definitions for gathering EPS II telemetry
 *
 * @}
 */
#include <string.h>

#include "eps_ii_telemetry.h"
#include "eps_ii_config.h"

#include "debug.h"
#include "cmsis_os.h"
#include "taskmon.h"
#include "es_cdef.h"
#include "assertions.h"
#include "taskmon_stat.h"
#include "fdir_srv.h"

#include "fp/EPSII_PDM_1/v1.0/EPSII_PDM_1_client/FP_EPSII_PDM_1ProtocolClient.h"
#include "fp/EPSII_BP_1/v3.0/EPSII_BP_1_client/FP_EPSII_BP_1ProtocolClient.h"
#include "fp/data_cache/v0.1/data_cache_server/FP_data_cacheProtocolTypes.h"
#include "fp/nvm_eps/v0.1/nvm_eps_server/FP_nvm_epsProtocolTypes.h"

#include "eps_ii_telemetry_cfg.h"
#include "conops.h"
#include "ESSA_Stack_Facade.h"

/**
 * @brief Enumeration with IDs of each FD command used for gathering information from the Battery Pack. It is used to provide common configuration
 * of each battery pack. In the configuration file for each element of this enum a specific DC_DID has to be provided
 */
typedef enum
{
    BP_INFO,
    BP_HEALTH_INFO,
    BP_INA_SENSOR1,
    BP_INA_SENSOR2,
    BP_BALANCER_INFO,
    BP_BALANCER_STATUS,
    BP_BALANCER_CELLS_INFO,
    BP_CHARGERS_MAIN_INFO_XP,
    BP_CHARGERS_MAIN_INFO_XR,
    BP_CHARGERS_MAIN_INFO_YP,
    BP_CHARGERS_MAIN_INFO_YR,
    BP_CHARGERS_MAIN_INFO_ZP,
    BP_CHARGERS_MAIN_INFO_ZR,
    BP_FDIR_EXEC_STATUS,
    BP_DATACACHE_CMD_COUNT
} bp_datacache_info_types_t;

/**
 * @brief Common Battery Pack faults enumerator. Those faults will be checked for each Battery Pack
 *
 */
typedef enum
{
    BP_FDIR_CMD_EXEC_FAILURE,
    BP_FDIR_BATT_VOLTAGE_BELOW_SAFE,
    BP_FDIR_BATT_TEMP_BELOW_SAFE,
    BP_FDIR_BATT_TEMP_ABOVE_SAFE,
    BP_FDIR_COUNT
} bp_fdir_faults_t;

/**
 * @brief A type defining a context for each Battery Pack.
 *
 */
typedef struct
{
    uint8_t        *p_address;
    dc_did_id       datacache_cmd_list[BP_DATACACHE_CMD_COUNT];
    fdir_fault_id_t fdir_faults[BP_FDIR_COUNT];
} bp_context_type;

/**
 * @enum
 * @brief Enumerator with all possible command execution errors for a Battery Pack.
 * Normally it is based on that what are the FP commands used by the telemetry service for a Battery Pack.
 *
 */
typedef enum
{
    BP_FDIR_CMD_EXEC_GET_BATTERY_INFO,
    BP_FDIR_CMD_EXEC_GET_DEVICE_HEALTH_INFO,
    BP_FDIR_CMD_EXEC_GET_RAW_SENSORS_1,
    BP_FDIR_CMD_EXEC_GET_RAW_SENSORS_2,
    BP_FDIR_CMD_EXEC_GET_RAW_SENSORS_3,
    BP_FDIR_CMD_EXEC_COUNT
} bp_fdir_cmd_exec_type;

typedef enum
{
    COM_STATE_UNKOWN,
    COM_STATE_ONLINE,
    COM_STATE_ERROR,
    COM_STATE_COUNT
} com_state_type;

/**
 * @brief Type used to provide needed information for logging each FDIR Command Execution failure.
 *
 */
typedef struct
{
    const char *cmd_name;
    uint8_t     dc_element;
} eps_fdir_cmd_exec_info_type;

/**
 * @brief This type is kind of extension to the  ESSATMAC_ErrCodes type as there are some errors
 * additional errors which can be detected for Communication failure.
 *
 */
typedef enum
{
    FDIR_CMD_EXEC_OK                   = ESSATMAC_EC_OK,
    FDIR_CMD_EXEC_ERROR                = ESSATMAC_EC_ERROR,
    FDIR_CMD_EXEC_NULL                 = ESSATMAC_EC_NULL,
    FDIR_CMD_EXEC_BUSY                 = ESSATMAC_EC_BUSY,
    FDIR_CMD_EXEC_NO_MEM               = ESSATMAC_EC_NO_MEM,
    FDIR_CMD_EXEC_Q_FULL               = ESSATMAC_EC_Q_FULL,
    FDIR_CMD_EXEC_Q_NOT_EMPTY          = ESSATMAC_EC_Q_NOT_EMPTY,
    FDIR_CMD_EXEC_RETRY_COUNT_LIMIT    = ESSATMAC_EC_RETRY_COUNT_LIMIT,
    FDIR_CMD_EXEC_TX_COLLISION         = ESSATMAC_EC_TX_COLLISION,
    FDIR_CMD_EXEC_UNSUPPORTED_NET_TYPE = ESSATMAC_EC_UNSUPPORTED_NET_TYPE,
    FDIR_CMD_EXEC_INVALID_PARAMS       = ESSATMAC_EC_INVALID_PARAMS,
    FDIR_CMD_EXEC_BUS_BUSY             = ESSATMAC_EC_BUS_BUSSY,
    FDIR_CMD_EXEC_TIMEOUT
} EPS_FDIR_CMD_EXEC_ErrCodes;

/**
 * @brief Enumerator with all possible command execution errors for a PDM.
 * Normally it is based on that what are the FP commands used by the telemetry service for a Battery Pack.
 *
 */
typedef enum
{
    PDM_FDIR_CMD_EXEC_GET_POWER_DISTRIBUTIONINFO,
    PDM_FDIR_CMD_EXEC_GET_DEVICE_HEALTH_INFO,
    PDM_FDIR_CMD_EXEC_GET_RAW_SENSORS1,
    PDM_FDIR_CMD_EXEC_GET_RAW_SENSORS2,
    PDM_FDIR_CMD_EXEC_COUNT
} pdm_fdir_cmd_exec_type;

/**
 * @enum
 * @brief Enumeration with IDs of each FD command used for gathering information from the PDM. It is used to provide common configuration
 * of each PDM. In the configuration file for each element of this enum a specific DC_DID has to be provided
 *
 */
typedef enum
{
    PDM_GET_POWER_DISTRIBUTION_INFO,
    PDM_GET_DEVICE_HEALTH_INFO,
    PDM_GET_RAW_SENSORS1,
    PDM_GET_RAW_SENSORS2,
    PDM_DATACACHE_CMD_COUNT
} pdm_datacache_info_types_t;

/*
 * DEFINITIONS
 *************/

#define SENSREPO_SV_UNKNOWN_VAL ((int32_t)0x7FFFFFFF) /* Value us unknown at the moment - not error state */
#define SENSREPO_SV_ERROR_VAL   ((int32_t)0x7FFFFFFE) /* Error getting sensor value */

#define BATTERY_INFO_ERROR_VAL ((int64_t)0x8000000000000000LL)

#define UINT16_UNKOWN_VAL ((uint16_t)0xFFFF)
#define UINT16_ERROR_VAL  ((uint16_t)0xFFFE)

#define UINT32_ERROR_VAL ((uint32_t)0xFFFFFFFE)
#define INT32_ERROR_VAL  ((uint32_t)0x7FFFFFFE)

#define INT16_UNKOWN_VAL ((int16_t)0x7FFF)
#define INT16_ERROR_VAL  ((int16_t)0x7FFE)

#define EPS_II_RAW_SENSORS_PDM_REQ_1           11 /* Values from PDM 1-50 */
#define EPS_II_RAW_SENSORS_PDM_REQ_2           12 /* Values from PDM 51-54 */
#define EPS_II_RAW_SENSORS_BP_REQ_INA_BALANCER 21 /* Values from BP with data from INA sensors and the BLANCER */
#define EPS_II_RAW_SENSORS_BP_REQ_XP_XR_YP     22 /* Values from BP with data from XP, XR and YP chargers */
#define EPS_II_RAW_SENSORS_BP_REQ_YR_ZP_ZR     23 /* Values from BP with data from YR, ZP and ZR chargers */

#define RAW_SENSOR_FP_CMD_SIZE (uint8_t)(50)

// those defines are here to be used for check in case of breaking change in
// fidl has been made. On each fidl change that affect those IDs the code
// should be reviewed, because modification may be needed.
#define INA_BAT_OUT_1_I_ID      ((uint16_t)1)
#define BALANCER1_CONTROL3_ID   ((uint16_t)29)
#define CHRG_XP_STAT_CHARGER_ID ((uint16_t)35)
#define CHRG_YP_TELE_VINR_ID    ((uint16_t)73)
#define CHRG_YR_STAT_CHARGER_ID ((uint16_t)74)
#define CHRG_ZR_TELE_VINR_ID    ((uint16_t)112)

#define BATTERY_PACKS_COUNT NVM_EPS_EPSBPIDTYPE_MAX_CNT

#define STATUS_REGISTERS_COUNT ((uint8_t)4)
#define BATTERY_CELLS_COUNT    ((uint8_t)8)

/**
 * @brief Time to wait between checking if ESSA stack is initialized. If the ESSA stack is not initialized the EPS II driver component
 * will not continue.
 *
 */
#define TIME_CHECK_ESSA_INIT_MS ((uint32_t)10)

/**
 * @brief Checks for Command execution failures in BP and sets or clears the corresponding FDIR. The function is used for each Battery Pack
 *
 * @param battery_ctx context of the battery pack to check for command execution failures.
 * @param p_exec_status pointer to placeholder for current iteration errors gathered for the specific Battery Pack.
 */
static void eps_ii_bp_cmd_exec_fdir_checks(const bp_context_type *const battery_ctx, DATA_CACHE_Eps2Inst0_FDIR_CMD_EXEC_STATUS_type_t *p_exec_status);

/**
 * @brief Checks for Command execution failures in PDM and sets or clears the corresponding FDIR.
 *
 * @param p_exec_status pointer to placeholder for current iteration errors gathered for the specific PDM.
 */
static void eps_ii_pdm_cmd_exec_fdir_checks(DATA_CACHE_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_t *p_exec_status);

/**
 * @brief Checks all other than command execution FDIR problems.
 *
 * @param battery_ctx context of the battery pack to check for command execution failures.
 * @param thresh_cfg thresholds configuration needed for judging if there is FDIR error or not
 */
static void eps_ii_bp_fdir_checks(const bp_context_type *const battery_ctx,
                                  CONOPS_ThresholdValues_t     thresh_cfg);
/**
 * @brief Send the FP requests `getRAWSensors` to a BP
 *
 * @param p_fp_ctx      context of the FP interface to be used to send commands fore getting raw sensor values of Battery Pack.
 * @param p_exec_status pointer to data containing all possible BP execution statuses. The idea is that it has to be updated according to the
 *                      status returned by the commands executed within this function.
 */
static void request_bp_raw_sensors(ReqContext_t *p_fp_ctx, DATA_CACHE_Eps2Inst0_FDIR_CMD_EXEC_STATUS_type_t *p_exec_status);

/**
 * @brief Send the FP requests `getRAWSensors` to a PDM
 *
 * @param p_fp_ctx      context of the FP interface to be used to send commands fore getting raw sensor values of PDM.
 * @param p_exec_status pointer to data containing all possible PDM execution statuses. The idea is that it has to be updated according to the
 *                      status returned by the commands executed within this function.
 */
static void request_pdm_raw_sensors(ReqContext_t *p_fp_ctx, DATA_CACHE_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_t *p_exec_status);

/**
 * @brief Function that search through the list of battery packs and returns the ID of the battery with the requested address
 *
 * @param addr address of the battery pack to be searched.
 * @return id of the battery pack in the battery pack array
 */
static uint8_t get_id_by_addr(uint8_t addr);

/**
 * @brief  function which extracts the data received from Raw sensor data and converts to the suitable type the values for INA sensors
 *
 * @param pi32SensorValues array with raw INA sensor data received by the BP.
 * @param battery_ctx      context of the Battery Pack used.
 */
static void update_ina_values(const int32_t *const pi32SensorValues, const bp_context_type *const battery_ctx);

/**
 * @brief  function which extracts the data received from the Balancer and converts to the suitable types
 *
 * @param pi32SensorValues array with raw Balancer data received by the BP.
 * @param battery_ctx      context of the Battery Pack used.
 */
static void update_balancer_values(const int32_t *const pi32SensorValues, const bp_context_type *const battery_ctx);

/**
 * @brief  function which extracts the data received from a charger and converts to the suitable types
 *
 * @param pi32SensorValues array with raw Charger data received by the BP.
 * @param battery_ctx      context of the Battery Pack used.
 */
static void update_charger_values(const dc_did_id set_charger_data_id, const int32_t *const pi32SensorValues);

/**
 * @brief Calculates mean average of all voltages and energies from all BPs in the stack and update the Datacache which stores the overall data.
 */
static void calculate_average_values_for_all_bps(void);

/**
 * @brief Main task for the eps ii telemetry. Periodically requests the battery info.
 *
 * @param args
 */
static void eps_ii_telemetry_task(void *args);

/**
 * @brief Function used to convert sensor values to int16 type. This function also takes care to convert
 * the error values to the error values expected from different types
 *
 * @param i32SensorValue - input sensor value to be converted.
 * @return
 */
static int16_t convert_sensor_value_to_int16(const int32_t i32SensorValue);

/**
 * @brief Function used to convert sensor values to uint16 type. This function also takes care to convert
 * the error values to the error values expected from different types
 *
 * @param i32SensorValue - input sensor value to be converted.
 * @return
 */
static uint16_t convert_sensor_value_to_uint16(const int32_t i32SensorValue);

// stores all addresses of battery packs available.
static uint8_t eps_bp_mac_address[BATTERY_PACKS_COUNT];

static uint8_t pdm_mac_address = 0x00;

static const dc_did_id pdm_datacache_cmd_list[PDM_DATACACHE_CMD_COUNT] = {
    DC_DID_EPS_9_DATA,
    DC_DID_EPS_10_DATA,
    DC_DID_EPS_14_DATA,
    DC_DID_EPS_14_DATA
};

static const eps_fdir_cmd_exec_info_type bp_map_dc_to_cmd[BP_FDIR_CMD_EXEC_COUNT] = {
    {"EPSII_BP_1_GetBatteryInfoReq",       BP_INFO                 }, /* BP_FDIR_CMD_EXEC_GET_BATTERY_INFO */
    { "EPSII_BP_1_GetDeviceHealthInfoReq", BP_HEALTH_INFO          }, /* BP_FDIR_CMD_EXEC_GET_DEVICE_HEALTH_INFO */
    { "EPSII_BP_1_GetRAWSensorsReq1",      BP_INA_SENSOR1          }, /* BP_FDIR_CMD_EXEC_GET_RAW_SENSORS_1 */
    { "EPSII_BP_1_GetRAWSensorsReq2",      BP_CHARGERS_MAIN_INFO_XP}, /* BP_FDIR_CMD_EXEC_GET_RAW_SENSORS_2 */
    { "EPSII_BP_1_GetRAWSensorsReq3",      BP_CHARGERS_MAIN_INFO_YR}  /* BP_FDIR_CMD_EXEC_GET_RAW_SENSORS_3 */
};

static const eps_fdir_cmd_exec_info_type pdm_map_dc_to_cmd[PDM_FDIR_CMD_EXEC_COUNT] = {
    {"EPSII_PDM_1_GetPowerDistributionInfo", PDM_GET_POWER_DISTRIBUTION_INFO}, /* PDM_FDIR_CMD_EXEC_GET_POWER_DISTRIBUTIONINFO */
    { "EPSII_PDM_1_GetDeviceHealthInfo",     PDM_GET_DEVICE_HEALTH_INFO     }, /* PDM_FDIR_CMD_EXEC_GET_DEVICE_HEALTH_INFO */
    { "EPSII_PDM_1_GetRAWSensors1",          PDM_GET_RAW_SENSORS1           }, /* PDM_FDIR_CMD_EXEC_GET_RAW_SENSORS1 */
    { "EPSII_PDM_1_GetRAWSensors2",          PDM_GET_RAW_SENSORS2           }  /* PDM_FDIR_CMD_EXEC_GET_RAW_SENSORS1 */
};

static const bp_context_type battery_packs[BATTERY_PACKS_COUNT] = {
    EPS_BP_CONFIGURATION
};

/*
 * EPS II TASK DEFINITIONS
 *************************/

/**
 * eps ii thread handler
 */
static osThreadId_t eps_ii_task_handle = NULL;
/**
 * eps ii thread attributes
 */
static const osThreadAttr_t eps_ii_task_attributes = {
    .name       = "EPS_II_TLM_Task",
    .priority   = (osPriority_t)osPriorityNormal,
    .stack_size = 2048
};

void eps_ii_tlm_init_memory(void)
{
    // Get MAC Adderesses from NVM

    eps_ii_cfg_get_bp_mac_addresses(eps_bp_mac_address, BATTERY_PACKS_COUNT);

    pdm_mac_address = eps_ii_cfg_get_pdm_mac_address();

    // initialize all datacache elements which the component has to fill in

    for (uint8_t battery_pack_id = 0; battery_pack_id < BATTERY_PACKS_COUNT; battery_pack_id++)
    {
        for (uint8_t cmd_id = 0; cmd_id < BP_DATACACHE_CMD_COUNT; cmd_id++)
        {
            uint32_t data_size = dc_get_data_size(battery_packs[battery_pack_id].datacache_cmd_list[cmd_id]);
            uint8_t  buffer_to_write[data_size];

            memset(buffer_to_write, 0, data_size);

            dc_set_raw_data(DC_DATA_INPUT_INTERNAL,
                            battery_packs[battery_pack_id].datacache_cmd_list[cmd_id],
                            &buffer_to_write,
                            data_size);
        }
    }
}

void eps_ii_tlm_init_os(void)
{
    eps_ii_task_handle = osThreadNew(&eps_ii_telemetry_task, NULL, &eps_ii_task_attributes);
    CRIT_ASSERT(eps_ii_task_handle);
    task_mon_register_for_stats(TASK_ID_EPS_II, eps_ii_task_handle);

    // Notify task_mon
    task_mon_set_task_policy(TASK_ID_EPS_II, TASK_MON_POLICY_MONITOR);
    task_mon_task_initialized(TASK_ID_EPS_II);
}

/*
 * DATA CACHE
 ************/
// Process response GetDistributionInfo

void eps_ii_batt_info_notif(const RespContext_t *const pRespCtx, const EPSII_BP_1GetBatteryInfoResponseData_t *const battery_info)
{

    uint8_t battery_pack_id = get_id_by_addr(pRespCtx->nAddr);

    if ((NULL != battery_info) && (BATTERY_PACKS_COUNT > battery_pack_id))
    {
        DATA_CACHE_Eps2Inst0BatteryInfoType_t bp_info = { 0 };

        // Populate the DATA_CACHE_EPS_7_t struct
        bp_info.u8Bp_mode = battery_info->eBp_mode;
        if (BATTERY_INFO_ERROR_VAL == battery_info->i64BattChargeCapacity)
        {
            bp_info.u32Capacity = UINT32_ERROR_VAL;
        }
        else
        {
            bp_info.u32Capacity = (uint32_t)battery_info->i64BattChargeCapacity;
        }

        if (BATTERY_INFO_ERROR_VAL == battery_info->i64BattCurrent)
        {
            bp_info.i16Current = INT16_ERROR_VAL;
        }
        else
        {
            bp_info.i16Current = (int16_t)battery_info->i64BattCurrent;
        }

        if (BATTERY_INFO_ERROR_VAL == battery_info->i64BattVoltage)
        {
            bp_info.u16Voltage = UINT16_ERROR_VAL;
        }
        else
        {
            bp_info.u16Voltage = (uint16_t)battery_info->i64BattVoltage;
        }

        if (BATTERY_INFO_ERROR_VAL == battery_info->i64BattTemperature)
        {
            bp_info.i32Temperature = INT32_ERROR_VAL;
        }
        else
        {
            bp_info.i32Temperature = (int32_t)battery_info->i64BattTemperature;
        }

        // Update the datacache
        dc_set_raw_data(DC_DATA_INPUT_INTERNAL, battery_packs[battery_pack_id].datacache_cmd_list[BP_INFO], &bp_info, sizeof(bp_info));
    }
}

void eps_ii_bp_dev_health_notif(const RespContext_t *const pRespCtx, const EPSII_BP_1GetDeviceHealthInfoResponseData_t *const p_dev_health_info)
{
    uint8_t battery_pack_id = get_id_by_addr(pRespCtx->nAddr);

    if ((NULL != p_dev_health_info) && (BATTERY_PACKS_COUNT > battery_pack_id))
    {
        DATA_CACHE_Eps2Inst0DeviceHealthInfoType_t eps_device_health_info = { 0 };

        eps_device_health_info.i32ActiveCPU_RunningTime = p_dev_health_info->i32ActiveCPU_RunningTime;
        eps_device_health_info.i32ActiveCPU_Voltage     = p_dev_health_info->i32ActiveCPU_Voltage;
        eps_device_health_info.i32ActiveCPU_Temperature = p_dev_health_info->i32ActiveCPU_Temperature;
        eps_device_health_info.i32PCB_Temperature_1     = p_dev_health_info->i32PCB_Temperature_1;
        eps_device_health_info.i32PCB_Temperature_2     = p_dev_health_info->i32PCB_Temperature_2;
        eps_device_health_info.u8BALANCER_CHIP_1        = p_dev_health_info->eBALANCER_CHIP_1;
        eps_device_health_info.u8LT8491_IC_XP           = p_dev_health_info->eLT8491_IC_XP;
        eps_device_health_info.u8LT8491_IC_XR           = p_dev_health_info->eLT8491_IC_XR;
        eps_device_health_info.u8LT8491_IC_YP           = p_dev_health_info->eLT8491_IC_YP;
        eps_device_health_info.u8LT8491_IC_YR           = p_dev_health_info->eLT8491_IC_YR;
        eps_device_health_info.u8LT8491_IC_ZP           = p_dev_health_info->eLT8491_IC_ZP;
        eps_device_health_info.u8LT8491_IC_ZR           = p_dev_health_info->eLT8491_IC_ZR;
        eps_device_health_info.u8INA_BAT_OUT_1          = p_dev_health_info->eINA_BAT_OUT_1;
        eps_device_health_info.u8INA_BAT_OUT_2          = p_dev_health_info->eINA_BAT_OUT_2;
        eps_device_health_info.u8TMP117_U810            = p_dev_health_info->eTMP117_U810;
        eps_device_health_info.u8TMP117_U811            = p_dev_health_info->eTMP117_U811;
        eps_device_health_info.u8GPIO_PCA9538_U2001     = p_dev_health_info->eGPIO_PCA9538_U2001;
        eps_device_health_info.u8GPIO_PCA9538_U2002     = p_dev_health_info->eGPIO_PCA9538_U2002;

        dc_set_raw_data(DC_DATA_INPUT_INTERNAL, battery_packs[battery_pack_id].datacache_cmd_list[BP_HEALTH_INFO], &eps_device_health_info, sizeof(eps_device_health_info));
    }
}

void eps_ii_pow_dist_info_notif(const EPSII_PDM_1GetPowerDistributionInfoResponseData_t *const p_pow_dist_info)
{
    if (NULL != p_pow_dist_info)
    {
        DATA_CACHE_EPS_9_t eps_9_data = { 0 };

        eps_9_data.i32In_SysBUS_Voltage         = p_pow_dist_info->sPowerDistributionInfo.i32In_SysBUS_Voltage;
        eps_9_data.i32Out_BatRAW_Output_Sense_U = p_pow_dist_info->sPowerDistributionInfo.sOut_BatRAW_Output_Sense.i32U;
        eps_9_data.i32Out_BatRAW_Output_Sense_I = p_pow_dist_info->sPowerDistributionInfo.sOut_BatRAW_Output_Sense.i32I;
        eps_9_data.i32Out_BatRAW_Output_Sense_P = p_pow_dist_info->sPowerDistributionInfo.sOut_BatRAW_Output_Sense.i32P;
        eps_9_data.i32Out_12V_Output_Sense_U    = p_pow_dist_info->sPowerDistributionInfo.sOut_12V_Output_Sense.i32U;
        eps_9_data.i32Out_12V_Output_Sense_I    = p_pow_dist_info->sPowerDistributionInfo.sOut_12V_Output_Sense.i32I;
        eps_9_data.i32Out_12V_Output_Sense_P    = p_pow_dist_info->sPowerDistributionInfo.sOut_12V_Output_Sense.i32P;
        eps_9_data.i32Out_12V_Output_ILimit     = p_pow_dist_info->sPowerDistributionInfo.i32Out_12V_Output_ILimit;
        eps_9_data.i32Out_5V_Output1_Sense_U    = p_pow_dist_info->sPowerDistributionInfo.sOut_5V_Output1_Sense.i32U;
        eps_9_data.i32Out_5V_Output1_Sense_I    = p_pow_dist_info->sPowerDistributionInfo.sOut_5V_Output1_Sense.i32I;
        eps_9_data.i32Out_5V_Output1_Sense_P    = p_pow_dist_info->sPowerDistributionInfo.sOut_5V_Output1_Sense.i32P;
        eps_9_data.i32Out_5V_Output1_ILimit     = p_pow_dist_info->sPowerDistributionInfo.i32Out_5V_Output1_ILimit;
        eps_9_data.i32Out_5V_Output2_Sense_U    = p_pow_dist_info->sPowerDistributionInfo.sOut_5V_Output2_Sense.i32U;
        eps_9_data.i32Out_5V_Output2_Sense_I    = p_pow_dist_info->sPowerDistributionInfo.sOut_5V_Output2_Sense.i32I;
        eps_9_data.i32Out_5V_Output2_Sense_P    = p_pow_dist_info->sPowerDistributionInfo.sOut_5V_Output2_Sense.i32P;
        eps_9_data.i32Out_5V_Output2_ILimit     = p_pow_dist_info->sPowerDistributionInfo.i32Out_5V_Output2_ILimit;
        eps_9_data.i32Out_3V3_Output1_Sense_U   = p_pow_dist_info->sPowerDistributionInfo.sOut_3V3_Output1_Sense.i32U;
        eps_9_data.i32Out_3V3_Output1_Sense_I   = p_pow_dist_info->sPowerDistributionInfo.sOut_3V3_Output1_Sense.i32I;
        eps_9_data.i32Out_3V3_Output1_Sense_P   = p_pow_dist_info->sPowerDistributionInfo.sOut_3V3_Output1_Sense.i32P;
        eps_9_data.i32Out_3V3_Output1_ILimit    = p_pow_dist_info->sPowerDistributionInfo.i32Out_3V3_Output1_ILimit;
        eps_9_data.i32Out_3V3_Output2_Sense_U   = p_pow_dist_info->sPowerDistributionInfo.sOut_3V3_Output2_Sense.i32U;
        eps_9_data.i32Out_3V3_Output2_Sense_I   = p_pow_dist_info->sPowerDistributionInfo.sOut_3V3_Output2_Sense.i32I;
        eps_9_data.i32Out_3V3_Output2_Sense_P   = p_pow_dist_info->sPowerDistributionInfo.sOut_3V3_Output2_Sense.i32P;
        eps_9_data.i32Out_3V3_Output2_ILimit    = p_pow_dist_info->sPowerDistributionInfo.i32Out_3V3_Output2_ILimit;

        // Update the datacache
        dc_set_eps_9_data(&eps_9_data);
    }
}

void eps_ii_pdm_dev_health_notif(const EPSII_PDM_1GetDeviceHealthInfoResponseData_t *const p_dev_health_info)
{
    if (NULL != p_dev_health_info)
    {
        DATA_CACHE_EPS_10_t eps_10_data = { 0 };

        eps_10_data.i32ActiveCPU_RunningTime  = p_dev_health_info->sGetDeviceHealthInfo.i32ActiveCPU_RunningTime;
        eps_10_data.i32ActiveCPU_Voltage      = p_dev_health_info->sGetDeviceHealthInfo.i32ActiveCPU_Voltage;
        eps_10_data.i32ActiveCPU_Temperature  = p_dev_health_info->sGetDeviceHealthInfo.i32ActiveCPU_Temperature;
        eps_10_data.i32PCB_Temperature_1      = p_dev_health_info->sGetDeviceHealthInfo.i32PCB_Temperature_1;
        eps_10_data.i32PCB_Temperature_2      = p_dev_health_info->sGetDeviceHealthInfo.i32PCB_Temperature_2;
        eps_10_data.i32NVM_AllocatedSize      = p_dev_health_info->sGetDeviceHealthInfo.i32NVM_AllocatedSize;
        eps_10_data.i32NVM_UsedSize           = p_dev_health_info->sGetDeviceHealthInfo.i32NVM_UsedSize;
        eps_10_data.i32Stack_AllocatedSize    = p_dev_health_info->sGetDeviceHealthInfo.i32Stack_AllocatedSize;
        eps_10_data.i32Stack_UsedSize         = p_dev_health_info->sGetDeviceHealthInfo.i32Stack_UsedSize;
        eps_10_data.u8DPOT_MCP4562_LUP_3V3_1P = p_dev_health_info->sGetDeviceHealthInfo.eDPOT_MCP4562_LUP_3V3_1P;
        eps_10_data.u8DPOT_MCP4562_LUP_3V3_1R = p_dev_health_info->sGetDeviceHealthInfo.eDPOT_MCP4562_LUP_3V3_1R;
        eps_10_data.u8DPOT_MCP4562_LUP_3V3_2P = p_dev_health_info->sGetDeviceHealthInfo.eDPOT_MCP4562_LUP_3V3_2P;
        eps_10_data.u8DPOT_MCP4562_LUP_3V3_2R = p_dev_health_info->sGetDeviceHealthInfo.eDPOT_MCP4562_LUP_3V3_2R;
        eps_10_data.u8DPOT_MCP4562_LUP_5V_1P  = p_dev_health_info->sGetDeviceHealthInfo.eDPOT_MCP4562_LUP_5V_1P;
        eps_10_data.u8DPOT_MCP4562_LUP_5V_1R  = p_dev_health_info->sGetDeviceHealthInfo.eDPOT_MCP4562_LUP_5V_1R;
        eps_10_data.u8DPOT_MCP4562_LUP_5V_2P  = p_dev_health_info->sGetDeviceHealthInfo.eDPOT_MCP4562_LUP_5V_2P;
        eps_10_data.u8DPOT_MCP4562_LUP_5V_2R  = p_dev_health_info->sGetDeviceHealthInfo.eDPOT_MCP4562_LUP_5V_2R;
        eps_10_data.u8DPOT_MCP4562_LUP_12V_P  = p_dev_health_info->sGetDeviceHealthInfo.eDPOT_MCP4562_LUP_12V_P;
        eps_10_data.u8DPOT_MCP4562_LUP_12V_R  = p_dev_health_info->sGetDeviceHealthInfo.eDPOT_MCP4562_LUP_12V_R;
        eps_10_data.u8DPOT_MCP4562_OUTU_12V_P = p_dev_health_info->sGetDeviceHealthInfo.eDPOT_MCP4562_OUTU_12V_P;
        eps_10_data.u8DPOT_MCP4562_OUTU_12V_R = p_dev_health_info->sGetDeviceHealthInfo.eDPOT_MCP4562_OUTU_12V_R;
        eps_10_data.u8GPIO_PCA9538_U1001      = p_dev_health_info->sGetDeviceHealthInfo.eGPIO_PCA9538_U1001;
        eps_10_data.u8GPIO_PCA9538_U1000      = p_dev_health_info->sGetDeviceHealthInfo.eGPIO_PCA9538_U1000;
        eps_10_data.u8GPIO_PCA9538_U1004      = p_dev_health_info->sGetDeviceHealthInfo.eGPIO_PCA9538_U1004;
        eps_10_data.u8GPIO_PCA9538_U1011      = p_dev_health_info->sGetDeviceHealthInfo.eGPIO_PCA9538_U1011;
        eps_10_data.u8INA_LUP_IN_3V3_1P       = p_dev_health_info->sGetDeviceHealthInfo.eINA_LUP_IN_3V3_1P;
        eps_10_data.u8INA_LUP_IN_3V3_1R       = p_dev_health_info->sGetDeviceHealthInfo.eINA_LUP_IN_3V3_1R;
        eps_10_data.u8INA_LUP_IN_3V3_2P       = p_dev_health_info->sGetDeviceHealthInfo.eINA_LUP_IN_3V3_2P;
        eps_10_data.u8INA_LUP_IN_3V3_2R       = p_dev_health_info->sGetDeviceHealthInfo.eINA_LUP_IN_3V3_2R;
        eps_10_data.u8INA_LUP_IN_5V_1P        = p_dev_health_info->sGetDeviceHealthInfo.eINA_LUP_IN_5V_1P;
        eps_10_data.u8INA_LUP_IN_5V_1R        = p_dev_health_info->sGetDeviceHealthInfo.eINA_LUP_IN_5V_1R;
        eps_10_data.u8INA_LUP_IN_5V_2P        = p_dev_health_info->sGetDeviceHealthInfo.eINA_LUP_IN_5V_2P;
        eps_10_data.u8INA_LUP_IN_5V_2R        = p_dev_health_info->sGetDeviceHealthInfo.eINA_LUP_IN_5V_2R;
        eps_10_data.u8INA_LUP_IN_12V_P        = p_dev_health_info->sGetDeviceHealthInfo.eINA_LUP_IN_12V_P;
        eps_10_data.u8INA_LUP_IN_12V_R        = p_dev_health_info->sGetDeviceHealthInfo.eINA_LUP_IN_12V_R;
        eps_10_data.u8TMP117_U1014            = p_dev_health_info->sGetDeviceHealthInfo.eTMP117_U1014;
        eps_10_data.u8TMP117_U1031            = p_dev_health_info->sGetDeviceHealthInfo.eTMP117_U1031;

        // Update the datacache
        dc_set_eps_10_data(&eps_10_data);
    }
}

void eps_ii_raw_sensors_notif(const RespContext_t *const pRespCtx, const void *p_raw_sensors)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waddress-of-packed-member"
    uint8_t battery_pack_id = get_id_by_addr(pRespCtx->nAddr);

    if ((NULL != p_raw_sensors) && (BATTERY_PACKS_COUNT > battery_pack_id))
    {
        // This could also be treated as EPSII_BP_1GetRAWSensorsResponseData_t
        EPSII_PDM_1GetRAWSensorsResponseData_t const *p_data = p_raw_sensors;
        DATA_CACHE_EPS_14_t                           eps_14_data;

        switch (p_data->u32PktID)
        {
            case EPS_II_RAW_SENSORS_BP_REQ_INA_BALANCER:

                update_ina_values(&p_data->ai32SensorValues[0],
                                  &battery_packs[battery_pack_id]);

                update_balancer_values(&p_data->ai32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_BALANCER1_BAT_U_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_1_I_ID],
                                       &battery_packs[battery_pack_id]);

                break;

            case EPS_II_RAW_SENSORS_BP_REQ_XP_XR_YP:

                update_charger_values(battery_packs[battery_pack_id].datacache_cmd_list[BP_CHARGERS_MAIN_INFO_XP], &p_data->ai32SensorValues[0]);

                update_charger_values(battery_packs[battery_pack_id].datacache_cmd_list[BP_CHARGERS_MAIN_INFO_XR], &p_data->ai32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XR_STAT_CHARGER_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_STAT_CHARGER_ID]);

                update_charger_values(battery_packs[battery_pack_id].datacache_cmd_list[BP_CHARGERS_MAIN_INFO_YP], &p_data->ai32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_YP_STAT_CHARGER_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_STAT_CHARGER_ID]);

                break;

            case EPS_II_RAW_SENSORS_BP_REQ_YR_ZP_ZR:

                update_charger_values(battery_packs[battery_pack_id].datacache_cmd_list[BP_CHARGERS_MAIN_INFO_YR], &p_data->ai32SensorValues[0]);

                update_charger_values(battery_packs[battery_pack_id].datacache_cmd_list[BP_CHARGERS_MAIN_INFO_ZP], &p_data->ai32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_ZP_STAT_CHARGER_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_YR_STAT_CHARGER_ID]);

                update_charger_values(battery_packs[battery_pack_id].datacache_cmd_list[BP_CHARGERS_MAIN_INFO_ZR], &p_data->ai32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_ZR_STAT_CHARGER_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_YR_STAT_CHARGER_ID]);

                break;

            case EPS_II_RAW_SENSORS_PDM_REQ_1:
                dc_get_eps_14_data(&eps_14_data);

                // Update the values with the data received from EPS II
                memcpy(eps_14_data.ai32Pdm_1_54_values, p_data->ai32SensorValues, sizeof(int32_t) * RAW_SENSOR_FP_CMD_SIZE);

                // Update the datacache
                dc_set_eps_14_data(&eps_14_data);
                break;

            case EPS_II_RAW_SENSORS_PDM_REQ_2:
                dc_get_eps_14_data(&eps_14_data);

                // Update the values with the data received from EPS II
                memcpy(&eps_14_data.ai32Pdm_1_54_values[RAW_SENSOR_FP_CMD_SIZE], p_data->ai32SensorValues, sizeof(int32_t) * 4);

                // Update the datacache
                dc_set_eps_14_data(&eps_14_data);
                break;

            default:
                CRIT_ASSERT(false);
                break;
        }
    }
#pragma GCC diagnostic pop
}

static void eps_ii_telemetry_task(void *args)
{
    (void)args;

    // FP context
    static ReqContext_t fp_ctx = {
        .nAddr            = 0,
        .nInterfaceNumber = ESSASNI_SYS_PRI,
        .seqId            = 0, // Value to be updated by the ESPS Stack once the request is sent
        .netType          = ESSASNETT_INTERNAL
    };

    while (SAFE_TRUE != ESSA_Stack_Facade_Is_Init())
    {
        osDelay(TIME_CHECK_ESSA_INIT_MS);
    }

    for (;;)
    {
        CONOPS_ThresholdValues_t thresh_cfg;
        bool                     is_cfg_read = conops_get_all_thresh_val(&thresh_cfg);

        // Set MAC address to BP
        for (uint8_t battery_pack_id = 0; battery_pack_id < BATTERY_PACKS_COUNT; battery_pack_id++)
        {
            DATA_CACHE_Eps2Inst0_FDIR_CMD_EXEC_STATUS_type_t bp_exec_status;
            fp_ctx.nAddr = *battery_packs[battery_pack_id].p_address;
            // Battery Information
            bp_exec_status.u8EPSII_BP_1_GetBatteryInfo_ErrorCode = (uint8_t)EPSII_BP_1_GetBatteryInfoReq(&fp_ctx);

            // BP Health Info
            bp_exec_status.u8EPSII_BP_1_GetDeviceHealthInfo_ErrorCode = (uint8_t)EPSII_BP_1_GetDeviceHealthInfoReq(&fp_ctx);
            osDelay(EPS_II_NEEDED_DELAY_FOR_PROCESSING);

            request_bp_raw_sensors(&fp_ctx, &bp_exec_status);

            eps_ii_bp_cmd_exec_fdir_checks(&battery_packs[battery_pack_id], &bp_exec_status);

            if (is_cfg_read)
            {
                eps_ii_bp_fdir_checks(&battery_packs[battery_pack_id], thresh_cfg);
            }

            osDelay(EPS_II_NEEDED_DELAY_FOR_PROCESSING);
        }

        calculate_average_values_for_all_bps();

        DATA_CACHE_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_t pdm_exec_status;

        // Change to PDM MAC address
        fp_ctx.nAddr = pdm_mac_address;
        // PDM
        pdm_exec_status.u8EPSII_PDM_1_GetPowerDistributionInfo_ErrorCode = (uint8_t)EPSII_PDM_1_GetPowerDistributionInfoReq(&fp_ctx);
        // PDM
        pdm_exec_status.u8EPSII_PDM_1_GetDeviceHealthInfo_ErrorCode = (uint8_t)EPSII_PDM_1_GetDeviceHealthInfoReq(&fp_ctx);

        osDelay(EPS_II_NEEDED_DELAY_FOR_PROCESSING);
        // PDM
        request_pdm_raw_sensors(&fp_ctx, &pdm_exec_status);

        eps_ii_pdm_cmd_exec_fdir_checks(&pdm_exec_status);

        osDelay(EPS_II_NEEDED_DELAY_FOR_PROCESSING);

        task_mon_i_am_alive(TASK_ID_EPS_II);
        task_mon_low_stack_check(TASK_ID_EPS_II);
    }
}

static void request_bp_raw_sensors(ReqContext_t *p_fp_ctx, DATA_CACHE_Eps2Inst0_FDIR_CMD_EXEC_STATUS_type_t *p_exec_status)
{
    uint16_t a_sensor_ids[RAW_SENSOR_FP_CMD_SIZE] = { 0 };

    CRIT_ASSERT(NULL != p_fp_ctx);
    CRIT_ASSERT(NULL != p_exec_status);

    // Request BP 1 (1-50)
    static_assert(INA_BAT_OUT_1_I_ID == EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_1_I_ID);
    static_assert(BALANCER1_CONTROL3_ID == EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_BALANCER1_CONTROL3_ID);
    static_assert(RAW_SENSOR_FP_CMD_SIZE > (EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_BALANCER1_CONTROL3_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_1_I_ID));

    for (uint16_t i = EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_1_I_ID; i <= EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_BALANCER1_CONTROL3_ID; i++)
    {
        a_sensor_ids[i - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_1_I_ID] = i;
    }
    p_exec_status->u8EPSII_BP_1_GetRAWSensors_1_ErrorCode = (uint8_t)EPSII_BP_1_GetRAWSensorsReq(p_fp_ctx, EPS_II_RAW_SENSORS_BP_REQ_INA_BALANCER, a_sensor_ids);

    memset(a_sensor_ids, 0, sizeof(a_sensor_ids));

    // Request BP 2 (51-100)
    static_assert(CHRG_XP_STAT_CHARGER_ID == EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_STAT_CHARGER_ID);
    static_assert(CHRG_YP_TELE_VINR_ID == EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_YP_TELE_VINR_ID);
    static_assert(RAW_SENSOR_FP_CMD_SIZE > EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_YP_TELE_VINR_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_STAT_CHARGER_ID);

    for (uint16_t i = EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_STAT_CHARGER_ID; i <= EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_YP_TELE_VINR_ID; i++)
    {
        a_sensor_ids[i - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_STAT_CHARGER_ID] = i;
    }
    p_exec_status->u8EPSII_BP_1_GetRAWSensors_2_ErrorCode = (uint8_t)EPSII_BP_1_GetRAWSensorsReq(p_fp_ctx, EPS_II_RAW_SENSORS_BP_REQ_XP_XR_YP, a_sensor_ids);
    memset(a_sensor_ids, 0, sizeof(a_sensor_ids));

    // Request BP 3 (101-122)
    static_assert(CHRG_YR_STAT_CHARGER_ID == EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_YR_STAT_CHARGER_ID);
    static_assert(CHRG_ZR_TELE_VINR_ID == EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_ZR_TELE_VINR_ID);
    static_assert(RAW_SENSOR_FP_CMD_SIZE > EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_ZR_TELE_VINR_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_YR_STAT_CHARGER_ID);

    for (uint16_t i = EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_YR_STAT_CHARGER_ID; i <= EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_ZR_TELE_VINR_ID; i++)
    {
        a_sensor_ids[i - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_YR_STAT_CHARGER_ID] = i;
    }
    p_exec_status->u8EPSII_BP_1_GetRAWSensors_3_ErrorCode = (uint8_t)EPSII_BP_1_GetRAWSensorsReq(p_fp_ctx, EPS_II_RAW_SENSORS_BP_REQ_YR_ZP_ZR, a_sensor_ids);
    memset(a_sensor_ids, 0, sizeof(a_sensor_ids));
}

static void request_pdm_raw_sensors(ReqContext_t *p_fp_ctx, DATA_CACHE_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_t *p_exec_status)
{
    uint16_t a_sensor_ids[RAW_SENSOR_FP_CMD_SIZE] = { 0 };

    CRIT_ASSERT(NULL != p_fp_ctx);
    CRIT_ASSERT(NULL != p_exec_status);

    // Set PDM Address
    p_fp_ctx->nAddr = pdm_mac_address;
    // Request PDM 1 (1-50)
    for (uint16_t i = 0; i < RAW_SENSOR_FP_CMD_SIZE; i++)
    {
        a_sensor_ids[i] = i + 1;
    }
    p_exec_status->u8EPSII_PDM_1_GetRAWSensors_PDM1_ErrorCode = (uint8_t)EPSII_PDM_1_GetRAWSensorsReq(p_fp_ctx, EPS_II_RAW_SENSORS_PDM_REQ_1, a_sensor_ids);
    memset(a_sensor_ids, 0, sizeof(a_sensor_ids));
    // Request PDM 2 (51-54)
    for (uint16_t i = 0; i < 4; i++)
    {
        a_sensor_ids[i] = i + 51;
    }
    p_exec_status->u8EPSII_PDM_1_GetRAWSensors_PDM2_ErrorCode = (uint8_t)EPSII_PDM_1_GetRAWSensorsReq(p_fp_ctx, EPS_II_RAW_SENSORS_PDM_REQ_2, a_sensor_ids);
}

static void eps_ii_bp_cmd_exec_fdir_checks(const bp_context_type *const battery_ctx, DATA_CACHE_Eps2Inst0_FDIR_CMD_EXEC_STATUS_type_t *p_exec_status)
{
    ESSATMAC_ErrCodes err_code;
    bool              cmd_exec_failure = false;

    CRIT_ASSERT(NULL != battery_ctx);
    CRIT_ASSERT(NULL != p_exec_status);

    // the type with command execution statuses must be aligned with the enumerator which contains the commands
    // make sure the macro "map_dc_to_cmd" is also initialized properly.
    static_assert(BP_FDIR_CMD_EXEC_COUNT == sizeof(DATA_CACHE_Eps2Inst0_FDIR_CMD_EXEC_STATUS_type_t));

    for (uint8_t cmd_id = 0; cmd_id < BP_FDIR_CMD_EXEC_COUNT; cmd_id++)
    {
        uint8_t          buffer_to_read_in;
        dc_data_status_t res;
        res = dc_get_raw_data(battery_ctx->datacache_cmd_list[bp_map_dc_to_cmd[cmd_id].dc_element],
                              &buffer_to_read_in,
                              sizeof(uint8_t),
                              0,
                              sizeof(uint8_t));

        // this is to prevent unwanted FDIR trigger on initialization of the device.
        // when the system is not yet initialized and this problem could appear.
        if (ESSATMAC_EC_UNSUPPORTED_NET_TYPE == ((uint8_t *)p_exec_status)[cmd_id])
        {
            ((uint8_t *)p_exec_status)[cmd_id] = FDIR_CMD_EXEC_OK;
        }

        if ((FDIR_CMD_EXEC_OK == ((uint8_t *)p_exec_status)[cmd_id]) && (DC_DATA_STATUS_TOUT == res))
        {
            ((uint8_t *)p_exec_status)[cmd_id] = FDIR_CMD_EXEC_TIMEOUT;
        }
    }

    dc_set_raw_data(DC_DATA_INPUT_INTERNAL, battery_ctx->datacache_cmd_list[BP_FDIR_EXEC_STATUS], p_exec_status, sizeof(DATA_CACHE_Eps2Inst0_FDIR_CMD_EXEC_STATUS_type_t));
    dc_get_raw_data(battery_ctx->datacache_cmd_list[BP_FDIR_EXEC_STATUS],
                    p_exec_status,
                    sizeof(DATA_CACHE_Eps2Inst0_FDIR_CMD_EXEC_STATUS_type_t),
                    0,
                    sizeof(DATA_CACHE_Eps2Inst0_FDIR_CMD_EXEC_STATUS_type_t));

    for (uint8_t cmd_id = 0; cmd_id < BP_FDIR_CMD_EXEC_COUNT; cmd_id++)
    {
        // info and health
        err_code = ((uint8_t *)p_exec_status)[cmd_id];
        if (ESSATMAC_EC_OK != err_code)
        {
            cmd_exec_failure = true;
            fdir_srv_log_if_clear(battery_ctx->fdir_faults[BP_FDIR_CMD_EXEC_FAILURE], FDIR_AGENT_EPS_II,
                                  "FP %s failed with err code %d, BP mac %u", bp_map_dc_to_cmd[cmd_id].cmd_name, err_code, *(battery_ctx->p_address));
        }
    }

    if (false == cmd_exec_failure)
    {
        fdir_srv_log_if_raised(battery_ctx->fdir_faults[BP_FDIR_CMD_EXEC_FAILURE], FDIR_AGENT_EPS_II, "All EPS II commands in current cycle succeeded");
    }
    (void)fdir_srv_fault_set_state(battery_ctx->fdir_faults[BP_FDIR_CMD_EXEC_FAILURE], FDIR_AGENT_EPS_II, cmd_exec_failure, NULL);
}

static void eps_ii_bp_fdir_checks(const bp_context_type *const battery_ctx,
                                  CONOPS_ThresholdValues_t     thresh_cfg)
{
    DATA_CACHE_Eps2Inst0BatteryInfoType_t bp_info;

    CRIT_ASSERT(NULL != battery_ctx);

    if (DC_DATA_STATUS_OK == dc_get_raw_data(battery_ctx->datacache_cmd_list[BP_INFO],
                                             &bp_info,
                                             sizeof(DATA_CACHE_Eps2Inst0BatteryInfoType_t),
                                             0,
                                             sizeof(DATA_CACHE_Eps2Inst0BatteryInfoType_t)))
    {
        fdir_agent_id_t agent_id         = FDIR_AGENT_INVALID;
        bool            low_voltage      = false;
        bool            low_temperature  = false;
        bool            high_temperature = false;

        agent_id = FDIR_AGENT_EPS_II;

        if (bp_info.u16Voltage < thresh_cfg.i32V_batt_safe)
        {
            fdir_srv_log_if_clear(battery_ctx->fdir_faults[BP_FDIR_BATT_VOLTAGE_BELOW_SAFE], agent_id, "Battery voltage (%d mC) is below safe level (%d mC)", bp_info.u16Voltage, thresh_cfg.i32V_batt_safe);
            low_voltage = true;
        }

        if (bp_info.i32Temperature < thresh_cfg.i32T_batt_safe_lower)
        {
            fdir_srv_log_if_clear(battery_ctx->fdir_faults[BP_FDIR_BATT_TEMP_BELOW_SAFE], agent_id, "Battery temperature (%d mC) is below safe level (%d mC)", bp_info.i32Temperature, thresh_cfg.i32T_batt_safe_lower);
            low_temperature = true;
        }
        else if (bp_info.i32Temperature > thresh_cfg.i32T_batt_safe_upper)
        {
            fdir_srv_log_if_clear(battery_ctx->fdir_faults[BP_FDIR_BATT_TEMP_ABOVE_SAFE], agent_id, "Battery temperature (%d mC) is above safe level (%d mC)", bp_info.i32Temperature, thresh_cfg.i32T_batt_safe_upper);
            high_temperature = true;
        }
        else
        {
            // SonarQube warning suppression
        }

        if (true == low_voltage)
        {
            fdir_srv_fault_set_state(battery_ctx->fdir_faults[BP_FDIR_BATT_VOLTAGE_BELOW_SAFE], agent_id, true, NULL);
        }
        if (true == low_temperature)
        {
            fdir_srv_fault_set_state(battery_ctx->fdir_faults[BP_FDIR_BATT_TEMP_BELOW_SAFE], agent_id, true, NULL);
        }
        if (true == high_temperature)
        {
            fdir_srv_fault_set_state(battery_ctx->fdir_faults[BP_FDIR_BATT_TEMP_ABOVE_SAFE], agent_id, true, NULL);
        }
    }
}

static void eps_ii_pdm_cmd_exec_fdir_checks(DATA_CACHE_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_t *p_exec_status)
{
    ESSATMAC_ErrCodes err_code;
    bool              cmd_exec_failure = false;

    CRIT_ASSERT(NULL != p_exec_status);

    // the type with command execution statuses must be aligned with the enumerator which contains the commands
    // make sure the macro "map_dc_to_cmd" is also initialized properly.
    static_assert(PDM_FDIR_CMD_EXEC_COUNT == sizeof(DATA_CACHE_FDIR_EPS_II_PDM_CMD_EXEC_STATUS_t));

    for (uint8_t cmd_id = 0; cmd_id < PDM_FDIR_CMD_EXEC_COUNT; cmd_id++)
    {
        uint8_t          buffer_to_read_in;
        dc_data_status_t res;
        res = dc_get_raw_data(pdm_datacache_cmd_list[pdm_map_dc_to_cmd[cmd_id].dc_element],
                              &buffer_to_read_in,
                              sizeof(uint8_t),
                              0,
                              sizeof(uint8_t));

        // this is to prevent unwanted FDIR trigger on initialization of the device.
        // when the system is not yet initialized and this problem could appear.
        if (ESSATMAC_EC_UNSUPPORTED_NET_TYPE == ((uint8_t *)p_exec_status)[cmd_id])
        {
            ((uint8_t *)p_exec_status)[cmd_id] = FDIR_CMD_EXEC_OK;
        }

        if ((FDIR_CMD_EXEC_OK == ((uint8_t *)p_exec_status)[cmd_id]) && (DC_DATA_STATUS_TOUT == res))
        {
            ((uint8_t *)p_exec_status)[cmd_id] = FDIR_CMD_EXEC_TIMEOUT;
        }
    }

    dc_set_fdir_eps_ii_pdm_cmd_exec_status_data(p_exec_status);
    (void)dc_get_fdir_eps_ii_pdm_cmd_exec_status_data(p_exec_status);

    for (uint8_t cmd_id = 0; cmd_id < PDM_FDIR_CMD_EXEC_COUNT; cmd_id++)
    {
        // info and health
        err_code = ((uint8_t *)p_exec_status)[cmd_id];
        if (ESSATMAC_EC_OK != err_code)
        {
            cmd_exec_failure = true;
            fdir_srv_log_if_clear(FDIR_FAULT_EPS_PDM_CMD_EXEC_FAILURE, FDIR_AGENT_EPS_II,
                                  "FP %s failed with err code %d, PDM mac %u", pdm_map_dc_to_cmd[cmd_id].cmd_name, err_code, pdm_mac_address);
        }
    }

    if (false == cmd_exec_failure)
    {
        fdir_srv_log_if_raised(FDIR_FAULT_EPS_PDM_CMD_EXEC_FAILURE, FDIR_AGENT_EPS_II, "All EPS II commands in current cycle succeeded");
    }
    (void)fdir_srv_fault_set_state(FDIR_FAULT_EPS_PDM_CMD_EXEC_FAILURE, FDIR_AGENT_EPS_II, cmd_exec_failure, NULL);
}

static uint8_t get_id_by_addr(uint8_t addr)
{
    uint8_t i;

    for (i = 0; i < BATTERY_PACKS_COUNT; i++)
    {
        if (*battery_packs[i].p_address == addr)
        {
            break;
        }
    }

    return i;
}

static void update_ina_values(const int32_t *const pi32SensorValues, const bp_context_type *const battery_ctx)
{
    DATA_CACHE_Eps2Inst0InaSensors1Type_t ina_values;

    CRIT_ASSERT(NULL != battery_ctx);
    CRIT_ASSERT(NULL != pi32SensorValues);

    ina_values.i16Current = convert_sensor_value_to_int16(pi32SensorValues[0]); // EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_1_I_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_1_I_ID
    ina_values.i16Energy  = convert_sensor_value_to_int16(pi32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_1_P_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_1_I_ID]);
    // take care to convert to (degrees in C)*10 and not [mV]
    ina_values.i16Temperature = convert_sensor_value_to_int16(pi32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_1_T_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_1_I_ID] / 100);
    ina_values.u16Voltage     = convert_sensor_value_to_uint16(pi32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_1_U_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_1_I_ID]);

    dc_set_raw_data(DC_DATA_INPUT_INTERNAL, battery_ctx->datacache_cmd_list[BP_INA_SENSOR1], &ina_values, sizeof(ina_values));

    ina_values.i16Current = convert_sensor_value_to_int16(pi32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_2_I_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_1_I_ID]);
    ina_values.i16Energy  = convert_sensor_value_to_int16(pi32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_2_P_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_1_I_ID]);
    // take care to convert to (degrees in C)*10 and not [mV]
    ina_values.i16Temperature = convert_sensor_value_to_int16(pi32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_2_T_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_1_I_ID] / 100);
    ina_values.u16Voltage     = convert_sensor_value_to_uint16(pi32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_2_U_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_INA_BAT_OUT_1_I_ID]);

    dc_set_raw_data(DC_DATA_INPUT_INTERNAL, battery_ctx->datacache_cmd_list[BP_INA_SENSOR2], &ina_values, sizeof(ina_values));
}

static void update_balancer_values(const int32_t *const pi32SensorValues, const bp_context_type *const battery_ctx)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waddress-of-packed-member"

    CRIT_ASSERT(NULL != battery_ctx);
    CRIT_ASSERT(NULL != pi32SensorValues);

    DATA_CACHE_Eps2Inst0BalancerStatusType_t    balancer_status = { 0 };
    DATA_CACHE_Eps2Inst0BalancerInfoType_t      balancer_info;
    DATA_CACHE_Eps2Inst0BalancerCellsInfoType_t balancer_cells_info;

    balancer_info.u16Voltage = convert_sensor_value_to_uint16(pi32SensorValues[0]); // EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_BALANCER1_BAT_U_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_BALANCER1_BAT_U_ID
    balancer_info.i16Current = convert_sensor_value_to_int16(pi32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_BALANCER1_BAT_I_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_BALANCER1_BAT_U_ID]);

    // take care to convert to (degrees in C)*10 and not [mV]
    int32_t raw_temperature = pi32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_BALANCER1_INT_TEMP_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_BALANCER1_BAT_U_ID];

    if ((SENSREPO_SV_ERROR_VAL != raw_temperature) && (SENSREPO_SV_UNKNOWN_VAL != raw_temperature))
    {
        balancer_info.i16Internal_Temperature = (int16_t)(raw_temperature / 100);
    }
    else
    {
        balancer_info.i16Internal_Temperature = INT16_ERROR_VAL;
    }

    uint8_t *pu8statusRegs = &balancer_status.u8Status_register_0;
    uint16_t status_reg_id = EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_BALANCER1_STATUS0_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_BALANCER1_BAT_U_ID;
    if ((pi32SensorValues[status_reg_id] == pi32SensorValues[status_reg_id + 1]) && (pi32SensorValues[status_reg_id] == pi32SensorValues[status_reg_id + 2]) && (pi32SensorValues[status_reg_id] == pi32SensorValues[status_reg_id + 3]))
    {
        if (SENSREPO_SV_UNKNOWN_VAL == pi32SensorValues[status_reg_id])
        {
            balancer_status.u8COM_STATE = COM_STATE_UNKOWN;
        }
        else
        {
            if (SENSREPO_SV_ERROR_VAL == pi32SensorValues[status_reg_id])
            {
                balancer_status.u8COM_STATE = COM_STATE_ERROR;
            }
            else
            {
                balancer_status.u8COM_STATE = COM_STATE_ONLINE;
            }
        }
    }
    else
    {
        balancer_status.u8COM_STATE = COM_STATE_ONLINE;
    }

    if (COM_STATE_ONLINE == balancer_status.u8COM_STATE)
    {
        for (uint8_t i = 0; i < STATUS_REGISTERS_COUNT; i++)
        {
            *pu8statusRegs = (uint8_t)pi32SensorValues[status_reg_id + i];
            pu8statusRegs++;
        }
    }

    uint16_t *pu16Cells = &balancer_cells_info.u16Cell_1;
    uint16_t  cell_id   = EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_BALANCER1_BAT_CELL_1_U_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_BALANCER1_BAT_U_ID;
    for (uint8_t i = 0; i < BATTERY_CELLS_COUNT; i++)
    {
        *pu16Cells = convert_sensor_value_to_uint16(pi32SensorValues[cell_id + i]);
        pu16Cells++;
    }

    dc_set_raw_data(DC_DATA_INPUT_INTERNAL, battery_ctx->datacache_cmd_list[BP_BALANCER_INFO], &balancer_info, sizeof(balancer_info));
    dc_set_raw_data(DC_DATA_INPUT_INTERNAL, battery_ctx->datacache_cmd_list[BP_BALANCER_STATUS], &balancer_status, sizeof(balancer_status));
    dc_set_raw_data(DC_DATA_INPUT_INTERNAL, battery_ctx->datacache_cmd_list[BP_BALANCER_CELLS_INFO], &balancer_cells_info, sizeof(balancer_cells_info));

#pragma GCC diagnostic pop
}

static void update_charger_values(const dc_did_id set_charger_data_id, const int32_t *const pi32SensorValues)
{
    DATA_CACHE_Eps2Inst0ChargerXpType_t charger_info_data = { 0 };

    CRIT_ASSERT(NULL != pi32SensorValues);

    if (SENSREPO_SV_UNKNOWN_VAL == pi32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_TELE_IOUT_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_STAT_CHARGER_ID])
    {
        charger_info_data.u8COM_STATE = COM_STATE_UNKOWN;
    }
    else
    {
        if (SENSREPO_SV_ERROR_VAL == pi32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_TELE_IOUT_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_STAT_CHARGER_ID])
        {
            charger_info_data.u8COM_STATE = COM_STATE_ERROR;
        }
        else
        {
            charger_info_data.u8COM_STATE    = COM_STATE_ONLINE;
            charger_info_data.u16STAT_SUPPLY = (uint16_t)pi32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_STAT_SUPPLY_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_STAT_CHARGER_ID];
            charger_info_data.u16TELE_IIN    = convert_sensor_value_to_uint16(pi32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_TELE_IIN_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_STAT_CHARGER_ID]);
            charger_info_data.u16TELE_IOUT   = convert_sensor_value_to_uint16(pi32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_TELE_IOUT_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_STAT_CHARGER_ID]);
            charger_info_data.u16TELE_PIN    = convert_sensor_value_to_uint16(pi32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_TELE_PIN_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_STAT_CHARGER_ID]);
            charger_info_data.u16TELE_POUT   = convert_sensor_value_to_uint16(pi32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_TELE_POUT_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_STAT_CHARGER_ID]);
            charger_info_data.u16TELE_VBAT   = convert_sensor_value_to_uint16(pi32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_TELE_VBAT_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_STAT_CHARGER_ID]);
            charger_info_data.u16TELE_VINR   = convert_sensor_value_to_uint16(pi32SensorValues[EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_TELE_VINR_ID - EPSII_BP_1_EPSIIT_SENSORIDS_EPSIIT_CHRG_XP_STAT_CHARGER_ID]);
        }
    }

    dc_set_raw_data(DC_DATA_INPUT_INTERNAL, set_charger_data_id, &charger_info_data, sizeof(charger_info_data));
}

static int16_t convert_sensor_value_to_int16(const int32_t i32SensorValue)
{
    int16_t res;
    switch (i32SensorValue)
    {
        case SENSREPO_SV_ERROR_VAL:
            res = INT16_ERROR_VAL;
            break;
        case SENSREPO_SV_UNKNOWN_VAL:
            res = INT16_UNKOWN_VAL;
            break;
        default:
            res = (int16_t)i32SensorValue;
            break;
    }
    return res;
}

static uint16_t convert_sensor_value_to_uint16(const int32_t i32SensorValue)
{
    uint16_t res;
    switch (i32SensorValue)
    {
        case SENSREPO_SV_ERROR_VAL:
            res = UINT16_ERROR_VAL;
            break;
        case SENSREPO_SV_UNKNOWN_VAL:
            res = UINT16_UNKOWN_VAL;
            break;
        default:
            res = (uint16_t)i32SensorValue;
            break;
    }
    return res;
}

static void calculate_average_values_for_all_bps(void)
{
    DATA_CACHE_EpsOverallBatteryInfoType_t overall_bp_info        = { 0 };
    uint32_t                               average_voltage        = 0;
    uint32_t                               overall_capacity       = 0;
    uint8_t                                normal_state_bps_count = 0;

    for (uint8_t battery_pack_id = 0; battery_pack_id < BATTERY_PACKS_COUNT; battery_pack_id++)
    {
        DATA_CACHE_Eps2Inst0BatteryInfoType_t bp_info;
        dc_data_status_t                      res = dc_get_raw_data(battery_packs[battery_pack_id].datacache_cmd_list[BP_INFO],
                                                                    &bp_info,
                                                                    sizeof(DATA_CACHE_Eps2Inst0BatteryInfoType_t),
                                                                    0U,
                                                                    sizeof(DATA_CACHE_Eps2Inst0BatteryInfoType_t));

        if ((DC_DATA_STATUS_OK == res) && (EPSII_BP_1_BP_MODE_TYPE_BATTERY == bp_info.u8Bp_mode))
        {
            if (UINT32_ERROR_VAL != bp_info.u32Capacity)
            {
                overall_capacity += bp_info.u32Capacity;
            }

            if (UINT16_ERROR_VAL != bp_info.u16Voltage)
            {
                normal_state_bps_count++;
                average_voltage += bp_info.u16Voltage;
            }
        }
    }

    if (0 < normal_state_bps_count)
    {
        overall_bp_info.u16Voltage = (uint16_t)(average_voltage / normal_state_bps_count);
    }

    overall_bp_info.u32Capacity = overall_capacity;

    dc_set_epsoverallbatteryinfo_data(&overall_bp_info);
}
