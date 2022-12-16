#ifndef GLOBAL_H
#define GLOBAL_H

#include <sys/ipc.h>
#include <sys/shm.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

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

// <number>. Display messages
void warning(char* msg);
void debug(char* msg);
void fatal(char* msg);
void error(char* msg);
void info(char* msg);
void inner_error();

#endif