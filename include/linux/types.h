/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_TYPES_H
#define _LINUX_TYPES_H

#include <uapi/linux/types.h>

#ifndef __ASSEMBLY__

#ifdef CONFIG_PHYS_ADDR_T_64BIT
typedef u64 phys_addr_t;
#else
typedef u32 phys_addr_t;
#endif

#endif /* __ASSEMBLY__ */
#endif /* _LINUX_TYPES_H */
