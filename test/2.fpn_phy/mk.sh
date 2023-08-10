set -x

CONFIGS="-DCONFIG_FLATMEM \
        -DCONFIG_ARM64_PAGE_SHIFT=12 \
        -UCONFIG_NEED_MULTIPLE_NODES \
        -DCONFIG_PHYS_ADDR_T_64BIT"
PROJECT_DIR=../..
TEST_DIR=test/2.fpn_phy
OBJ=${TEST_DIR}/obj

cd ${PROJECT_DIR}
rm -rf ${OBJ}
rm -rf ${OBJ}/../main
mkdir -p ${OBJ}

gcc mm/memory.c \
    -I./include \
    ${CONFIGS} \
    -c -o ${OBJ}/memory.o
gcc ${TEST_DIR}/main.c ${OBJ}/memory.o \
    -I./include -I./arch/arm64/include \
    ${CONFIGS} \
    -o ${OBJ}/../main
