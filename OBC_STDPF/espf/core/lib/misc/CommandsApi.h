/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
#ifndef COMMANDSAPI_H
#define COMMANDSAPI_H

/**
 * @addtogroup Libraries
 * @{
 *
 * @defgroup misc Miscellaneous
 * @{
 *
 * Different libraries or utilities.
 *
 * - Commands API
 *
 * @file CommandsApi.h
 * @brief Public interface of the Commands API
 *
 * @}
 * @}
 */
#include "DAT_Inputs.h"
#include "nvm/inc/nvm.h"

#pragma pack(push)
#pragma pack(1)

typedef enum
{
    STDRESULT_SUCCESS,
    STDRESULT_ERROR,
    STDRESULT_INVALID_ARGS
} StdResult_t;

typedef enum
{
    APPMODE_APPLICATION,
    APPMODE_BOOTLOADER,
    APPMODE_AUTO_FW_UPDATE,
    APPMODE_MAX
} AppMode_t;

#pragma pack(pop)

StdResult_t WriteHandler_ResetInBootOrAppMode(const AppMode_t appMode);

#endif /* COMMANDSAPI_H */
