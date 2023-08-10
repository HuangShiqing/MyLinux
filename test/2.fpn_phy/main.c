#include <stdio.h>
#include <stdlib.h>

// #define CONFIG_FLATMEM
// #undef CONFIG_NEED_MULTIPLE_NODES
// #define CONFIG_ARM64_PAGE_SHIFT 12
// #define CONFIG_PHYS_ADDR_T_64BIT

#include "asm-generic/memory_model.h"
#include "linux/mm_types.h"
#include "asm/page.h"
#include "asm/memory.h"
#include "linux/pfn.h"

extern struct page *mem_map;

int main(int argc, char const *argv[]) {
    int total_mem_size = 100 * 4 * 1024;  // byte
    int page_num = total_mem_size / PAGE_SIZE;
    mem_map = (struct page*)malloc(page_num * sizeof(struct page));

    struct page* pg = pfn_to_page(5);

    printf("total_mem_size(byte): %d\n", total_mem_size);
    printf("page_size(byte): %d\n", PAGE_SIZE);
    printf("page_num: %d\n", page_num);
    printf("pg.flags: %d\n", pg->flags);

    phys_addr_t addr = page_to_phys(pg);
    printf("addr: %p\n", addr);
    free(mem_map);
    return 0;
}
