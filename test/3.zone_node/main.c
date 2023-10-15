#include <stdio.h>
#include <stdlib.h>

// #define CONFIG_FLATMEM
// #undef CONFIG_NEED_MULTIPLE_NODES
// #define CONFIG_ARM64_PAGE_SHIFT 12
// #define CONFIG_PHYS_ADDR_T_64BIT

// #define CONFIG_FLAT_NODE_MEM_MAP
// #undef CONFIG_NUMA
// #undef CONFIG_ZONE_DMA
// #undef CONFIG_ZONE_DMA32
// #undef CONFIG_HIGHMEM
// #undef CONFIG_ZONE_DEVICE
// #define CONFIG_HAVE_MEMBLOCK
// #undef CONFIG_HAVE_MEMBLOCK_NODE_MAP
// #define CONFIG_NO_BOOTMEM
// #undef CONFIG_HAVE_ARCH_ALLOC_REMAP
// #undef CONFIG_FORCE_MAX_ZONEORDER

#include "asm-generic/memory_model.h"
#include "linux/mm_types.h"
#include "asm/page.h"
#include "asm/memory.h"
#include "linux/pfn.h"
#include <linux/bootmem.h>

void free_area_init_node(int nid, unsigned long *zones_size,
		unsigned long node_start_pfn, unsigned long *zholes_size);

int main(int argc, char const *argv[]) {
    int nid = 0;
    unsigned long node_start_pfn = 0;
    unsigned long zone_size[MAX_NR_ZONES] = {40, 60};//page_num
    unsigned long zhole_size[MAX_NR_ZONES] = {0, 0};

    free_area_init_node(nid, zone_size, node_start_pfn, zhole_size);
    printf("node0's node_mem_map: %p\n", contig_page_data.node_mem_map);
    printf("node0's start_pfn: %d\n", contig_page_data.node_start_pfn);
    printf("node0's spanned_pages: %d\n", contig_page_data.node_spanned_pages);
    printf("node0's present_pages: %d\n", contig_page_data.node_present_pages);
    printf("node0's zone_num: %d\n", MAX_NR_ZONES);
    unsigned int zone;
    for(zone = 0; zone < MAX_NR_ZONES; zone++) {
        printf("zone%d's name: %s\n", zone, contig_page_data.node_zones[zone].name);
        printf("zone%d's start_pfn: %d\n", zone, contig_page_data.node_zones[zone].zone_start_pfn);
        printf("zone%d's managed_pages: %d\n", zone, contig_page_data.node_zones[zone].managed_pages);
        printf("zone%d's spanned_pages: %d\n", zone, contig_page_data.node_zones[zone].spanned_pages);
        printf("zone%d's present_pages: %d\n", zone, contig_page_data.node_zones[zone].present_pages);
    }
    return 0;
}
