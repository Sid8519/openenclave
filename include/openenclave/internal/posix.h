// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef _OE_INTERNAL_POSIX_H
#define _OE_INTERNAL_POSIX_H

#include <openenclave/bits/defs.h>
#include <openenclave/internal/types.h>

/*
**==============================================================================
**
** posix.h
**
**     This file defines shared definitions used across the POSIX EDL interface.
**
**==============================================================================
*/

OE_EXTERNC_BEGIN

OE_PACK_BEGIN
typedef struct _oe_device_notifications
{
    /* oe_epoll_event.event */
    uint32_t event_mask;
    union {
        uint64_t data;
        struct
        {
            /* Enclave fd for the epoll device. */
            uint32_t epoll_fd;
            /* On the host side we set this into the event data. */
            uint32_t list_idx;
        };
    };
} oe_device_notifications_t;
OE_PACK_END

typedef union _oe_ev_data {
    struct
    {
        uint32_t epoll_enclave_fd;
        uint32_t event_list_idx;
    };
    uint64_t data;
} oe_ev_data_t;

/* Represents file-descriptors returned by host (64-bits on Windows). */
typedef int64_t oe_host_fd_t;

#define OE_POSIX_OCALL_FUNCTION_TABLE_ID 0
#define OE_POSIX_ECALL_FUNCTION_TABLE_ID 0

/* Register the OCALL table needed by the POSIX interface (host side). */
void oe_register_posix_ocall_function_table(void);

/* Register the ECALL table needed by the POSIX interface (enclave side). */
void oe_register_posix_ecall_function_table(void);

OE_EXTERNC_END

#endif /* _OE_INTERNAL_POSIX_H */
