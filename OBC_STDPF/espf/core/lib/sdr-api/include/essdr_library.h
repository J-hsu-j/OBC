/*  =========================================================================
    essdr - generated layer of public API

    Closed License

    Copyright (c) [2021] EnduroSat - All Rights Reserved

    Unauthorized copying of this file, via any medium is strictly prohibited
    Proprietary and confidential
    =========================================================================
*/
#ifndef ESSDR_LIBRARY_H_INCLUDED
#define ESSDR_LIBRARY_H_INCLUDED

/*  Set up environment for the application */

/*  External dependencies */
#include <stdint.h>
#include <stddef.h>

/*  ESSDR version macros for compile-time API detection */
#define ESSDR_VERSION_MAJOR 0
#define ESSDR_VERSION_MINOR 1
#define ESSDR_VERSION_PATCH 0

#define ESSDR_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))

#define ESSDR_VERSION \
    ESSDR_MAKE_VERSION(ESSDR_VERSION_MAJOR, ESSDR_VERSION_MINOR, ESSDR_VERSION_PATCH)

#define ESSDR_PRIVATE __attribute__ ((visibility ("hidden")))
#define ESSDR_EXPORT __attribute__ ((visibility ("default")))

#define ES_SDR_CLIENT_T_DEFINED
#define ES_LOG_T_DEFINED

/*  Public classes, each with its own header file */
#include "es_sdr_client.h"
#include "es_log.h"

#endif
