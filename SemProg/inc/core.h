#ifndef CORE_H
#define CORE_H
#include <sys/stat.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <log.h>

#define IPC_FAIL -1
#define FAILLURE 0
#define SUCCESS 1

// Main functions
int get_sem_inf(int id, struct semid_ds* sem_data);
int create_sem(char* path, int cnt_sems, int init_val);
int destroy_sem(int id);

int get_sem_val(int id, int sem_id);
int get_sem_pid(int id, int sem_id);
int get_num_sems(int id);

int set_val(int id, int sem_id, int val);
int set_val_all(int id, int val);
// Display helpres
void display_sem_inf(struct semid_ds* sem_data);
void display_sem_id_inf(int id, int sem_id);
// Helpers
char* itoa(char buf[32], int val, int base);
void strmode(mode_t mode, char * buf);
int check_sem_num(int id, int sem_id);
#endif