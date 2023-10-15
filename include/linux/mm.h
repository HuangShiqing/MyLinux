/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_MM_H
#define _LINUX_MM_H

// #ifdef __KERNEL__

#include <linux/mm_types.h>
#include <linux/kernel.h> //added by myself

#include <asm/page.h>

/* to align the pointer to the (next) page boundary */
#define PAGE_ALIGN(addr) ALIGN(addr, PAGE_SIZE)

// #endif /* __KERNEL__ */
#endif /* _LINUX_MM_H */
