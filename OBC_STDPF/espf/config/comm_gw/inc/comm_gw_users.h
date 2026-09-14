/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

/**
 * @addtogroup Services
 * @{
 *
 * @defgroup comm_gw
 * @{
 *
 * @file comm_gw_users.h
 * @brief COMM GW configuration file
 *
 * @}
 * @}
 */

#ifndef COMM_GW_USERS_H
#define COMM_GW_USERS_H

/** @brief FP GW users list
 *
 *  Each user is assigned a static slot which will be used to facilitate FP GW communication and to
 *  avoid mixing up communication between one user and another going through the FP GW.
 *
 * */
typedef enum
{
    COMM_GW_USER_ID_UPY = 0,       /**< COMM GW calls from uPy scripts */
    COMM_GW_USER_ID_OBC_SCHEDULER, /**< COMM GW calls from the on-board scheduler */
    COMM_GW_USER_ID_CP_HANDLER,    /**< COMM GW calls from an ESPS CP handler */
    COMM_GW_USER_ID_CSP_FP_SRV,    /**< COMM GW calls from the CSP FP server */
    COMM_GW_USER_ID_XBAND_FE,      /**< COMM GW calls from XBand FE service */
    COMM_GW_USER_ID_MAX            /**< used for validity checking only */
} comm_gw_user_id_t;

#endif /* COMM_GW_USERS_H */
