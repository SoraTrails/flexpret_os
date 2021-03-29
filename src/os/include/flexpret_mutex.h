#ifndef FLEXPRET_MUTEX_H
#define FLEXPRET_MUTEX_H
#include "cmsis_os2.h"

typedef struct mutex_state {
    osThreadId_t owner;
    const char *name;
    int csr_addr;
    int count;
    unsigned char ifRecursive;
    unsigned char ifRobust;
    unsigned char active;
} mutex_state;

#define FLEXPRET_MUTEX_MAX_NUM 8
// #define FLEXPRET_MUTEX_WIDTH 4

#define FLEXPRET_MUTEX_INACTIVE 1
#define FLEXPRET_MUTEX_ACTIVE 0

void write_mutex_csr(int i, int val);
int swap_mutex_csr(int i, int val);

#endif