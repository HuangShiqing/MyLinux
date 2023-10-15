// SPDX-License-Identifier: GPL-2.0
/*
 *  bootmem - A boot-time physical memory allocator and configurator
 *
 *  Copyright (C) 1999 Ingo Molnar
 *                1999 Kanoj Sarcar, SGI
 *                2008 Johannes Weiner
 *
 * Access to this subsystem has to be serialized externally (which is true
 * for the boot process anyway).
 */

#include <linux/bootmem.h>

#ifndef CONFIG_HAVE_MEMBLOCK
#error CONFIG_HAVE_MEMBLOCK not defined
#endif

#ifndef CONFIG_NEED_MULTIPLE_NODES
struct pglist_data contig_page_data;
// EXPORT_SYMBOL(contig_page_data);
#endif
