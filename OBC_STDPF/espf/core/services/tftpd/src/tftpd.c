/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */

#include <stdio.h>

#include "lwip/apps/tftp_client.h"
#include "lwip/apps/tftp_server.h"
#include <string.h>
#include "../inc/tftpd.h"
#include "fm_mng.h"
#include "trace.h"

#if LWIP_UDP

#define MAX_OPENED_HANDLES (1)

/* Define a base directory for TFTP access
 * ATTENTION: This code does NOT check for sandboxing,
 * i.e. '..' in paths is not checked! */
#ifndef LWIP_TFTP_EXAMPLE_BASE_DIR
#define LWIP_TFTP_EXAMPLE_BASE_DIR ""
#endif

/* Define this to a file to get via tftp client */
#ifndef LWIP_TFTP_EXAMPLE_CLIENT_FILENAME
#define LWIP_TFTP_EXAMPLE_CLIENT_FILENAME "test.bin"
#endif

/* Define this to a server IP string */
#ifndef LWIP_TFTP_EXAMPLE_CLIENT_REMOTEIP
#define LWIP_TFTP_EXAMPLE_CLIENT_REMOTEIP "192.168.0.1"
#endif

INIT_CMP_LOGGER(true, TRACE_LVL_WARN)

static char          full_filename[FM_MAX_PATH];
static fm_file_obj_t fhnd_pool[MAX_OPENED_HANDLES];

static fm_file_obj_t *get_free_file_hnd(void)
{
    fm_file_obj_t *p_hnd = NULL;

    for (uint8_t i = 0; i < CDEF_ELEMENT_COUNT(fhnd_pool); i++)
    {
        if (false == fm_is_open(&fhnd_pool[i]))
        {
            p_hnd = &fhnd_pool[i];
            break;
        }
    }

    return p_hnd;
}

static void *tftp_open_file(const char *fname, u8_t is_write)
{
    fm_file_obj_t *p_fhnd = NULL;
    fm_result_t    fres;

    p_fhnd = get_free_file_hnd();

    if (NULL != p_fhnd)
    {
        (void)memset(full_filename, 0U, sizeof(full_filename));
        (void)snprintf(full_filename, sizeof(full_filename), "%s%s", LWIP_TFTP_EXAMPLE_BASE_DIR, fname);
        full_filename[sizeof(full_filename) - 1] = 0;

        if (is_write)
        {
            fres = fm_open(p_fhnd, full_filename, FM_MODE_WRITE | FM_MODE_CREATE_ALWAYS);
        }
        else
        {
            fres = fm_open(p_fhnd, full_filename, FM_MODE_READ | FM_MODE_OPEN_EXISTING);
        }

        if (FM_RES_OK != fres)
        {
            ES_TRACE_ERROR("could not open file with error: %d\r\n", fres);
            p_fhnd = NULL;
        }
        else
        {
            ES_TRACE_INFO("'%s' file successfully opened!\r\n", full_filename);
        }
    }

    return p_fhnd;
}

static uint32_t max_size = 0;

static void *tftp_open(const char *fname, const char *mode, u8_t is_write)
{
    LWIP_UNUSED_ARG(mode);
    max_size = 0;
    return tftp_open_file(fname, is_write);
}

static void tftp_close(void *handle)
{
    (void)fm_close((fm_handle_t)handle);
}

static int tftp_read(void *handle, void *buf, int bytes)
{
    uint32_t    bytes_read = -1;
    fm_result_t fres;

    fres = fm_read((fm_handle_t)handle, buf, bytes, &bytes_read);

    if (FM_RES_OK != fres)
    {
        bytes_read = (uint32_t)-1;
    }

    return (int)bytes_read;
}

static int tftp_write(void *handle, struct pbuf *p)
{
    uint32_t    bytes_written = (size_t)-1;
    fm_result_t fres;

    while (p != NULL)
    {
        fres = fm_write((fm_handle_t)handle, p->payload, p->len, &bytes_written);

        if (FM_RES_OK != fres)
        {
            bytes_written = (uint32_t)-1;
            break;
        }

        p = p->next;
    }

    return (int)bytes_written;
}

/* For TFTP client only */
static void tftp_error(void *handle, int err, const char *msg, int size)
{
    char message[100];

    LWIP_UNUSED_ARG(handle);

    memset(message, 0, sizeof(message));
    MEMCPY(message, msg, LWIP_MIN(sizeof(message) - 1, (size_t)size));

    printf("TFTP error: %d (%s)", err, message);
}

static const struct tftp_context tftp = {
    tftp_open,
    tftp_close,
    tftp_read,
    tftp_write,
    tftp_error
};

void tftpd_init_server(void)
{
    for (uint8_t i = 0; i < CDEF_ELEMENT_COUNT(fhnd_pool); i++)
    {
        fm_close(&fhnd_pool[i]);
    }

    tftp_init_server(&tftp);
}

void tftpd_init_client(void)
{
    void     *f;
    err_t     err;
    ip_addr_t srv;
    int       ret = ipaddr_aton(LWIP_TFTP_EXAMPLE_CLIENT_REMOTEIP, &srv);
    LWIP_ASSERT("ipaddr_aton failed", ret == 1);

    err = tftp_init_client(&tftp);
    LWIP_ASSERT("tftp_init_client failed", err == ERR_OK);

    f = tftp_open_file(LWIP_TFTP_EXAMPLE_CLIENT_FILENAME, 1);
    LWIP_ASSERT("failed to create file", f != NULL);

    err = tftp_get(f, &srv, TFTP_PORT, LWIP_TFTP_EXAMPLE_CLIENT_FILENAME, TFTP_MODE_OCTET);
    LWIP_ASSERT("tftp_get failed", err == ERR_OK);
}

#endif /* LWIP_UDP */
