#ifndef GLOBAL_H
#define GLOBAL_H

#include <sys/ipc.h>
#include <sys/shm.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "log.h"

#define IPC_FAIL -1

struct shm_metadata{
    int id;
    int size;
};

// 1. Global variables
extern int shm_id;

// 2. Main functions
void create_shared_memory(char* path, int uid, int size);
void detach_shared_memory(void* ptr);
void destroy_shared_memory(int id);

void write_to_mem(int id, char* buf);
void read_from_mem(int id, char* buf);
char* get_mem(int id);

#endif