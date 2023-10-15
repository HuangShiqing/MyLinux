set -x

CONFIGS="-DCONFIG_FLATMEM \
        -DCONFIG_ARM64_PAGE_SHIFT=12 \
        -UCONFIG_NEED_MULTIPLE_NODES \
        -DCONFIG_PHYS_ADDR_T_64BIT \
        -DCONFIG_FLAT_NODE_MEM_MAP \
        -DCONFIG_NO_BOOTMEM \
        -DCONFIG_HAVE_MEMBLOCK \
        -UCONFIG_HAVE_MEMBLOCK_NODE_MAP"
PROJECT_DIR=../..
TEST_DIR=test/3.zone_node
OBJ=${TEST_DIR}/obj

cd ${PROJECT_DIR}
rm -rf ${OBJ}
rm -rf ${OBJ}/../main
mkdir -p ${OBJ}

gcc mm/memory.c \
    -I./include \
    ${CONFIGS} \
    -c -o ${OBJ}/memory.o
gcc mm/page_alloc.c \
    -I./include -I./arch/arm64/include \
    ${CONFIGS} \
    -O0 -g -c -o ${OBJ}/page_alloc.o
gcc mm/nobootmem.c \
    -I./include \
    ${CONFIGS} \
    -O0 -g -c -o ${OBJ}/nobootmem.o

gcc ${TEST_DIR}/main.c ${OBJ}/memory.o ${OBJ}/page_alloc.o ${OBJ}/nobootmem.o \
    -I./include -I./arch/arm64/include \
    ${CONFIGS} \
    -O0 -g -o ${OBJ}/../main
