#include "core.h"

int create_sem(char* path, int cnt_sems, int init_val){
    // 1. Get key
    key_t key = ftok(path, 0);
    if(key == IPC_FAIL){
        printf("Key = -1\n");
        error("create_sem");
        return FAILLURE;
    }
    // 2. Create semaphore SYSTEM V
    int res = semget(key, cnt_sems, IPC_EXCL | IPC_CREAT | 0666);
    // 3. Init start value
    if(errno != EEXIST)
        set_val_all(res, init_val);        
    else
        res = semget(key, cnt_sems, IPC_CREAT | 0666);
    // 4. Check res
    if(res == IPC_FAIL){
        error("Can't create semaphore");
        return FAILLURE;
    }
    // 5. Return result
    return res;
}

int destroy_sem(int id){
    // 1. Execute command
    // Second argument not neccessary real value
    int res = semctl(id, 0, IPC_RMID);
    // 2. Check value
    if(res == IPC_FAIL){
        error("Can't destroy semaphore");
        return FAILLURE;
    }
    // 3. Return success
    return SUCCESS;
}


int get_sem_inf(int id, struct semid_ds* sem_data) {
    // 1. Get semaphore data
    int res = semctl(id, 0, IPC_STAT, sem_data);
    // 2. Check value
    if(res == IPC_FAIL){
        error("Can't get semaphore information");
        return FAILLURE;
    }
    // 3. Return success
    return SUCCESS;
}

int get_num_sems(int id){
    struct semid_ds sem_data;
    // 1. Get semaphore data
    int res = get_sem_inf(id, &sem_data);
    if(res == FAILLURE)
        error("Can't get number of semaphores");
    // 2. Return number of semaphores
    return sem_data.sem_nsems;
}

int get_sem_val(int id, int sem_id){
    // 0. Check sem_num
    if(check_sem_num(id, sem_id)){
        // 1. Get semaphore data
        int res = semctl(id, sem_id, GETVAL);
        // 2. Check value
        if(res == IPC_FAIL){
            error("Can't set value to semaphore");
            return FAILLURE;
        }
        // 3. Return success
        return res;
    }

    return FAILLURE;
}

int get_sem_pid(int id, int sem_id){
    // 0. Check sem_num
    if(check_sem_num(id, sem_id)){ 
        // 1. Get semaphore data
        int res = semctl(id, sem_id, GETPID);
        // 2. Check value
        if(res == IPC_FAIL){
            error("Can't get semaphore pid");
            return FAILLURE;
        }
        // 3. Return success
        return res;   
    }

    return FAILLURE;
}

int set_val(int id, int sem_id, int val){
    // 0. Check sem_num
    if(check_sem_num(id, sem_id)){
        // 1. Set semaphore data
        int res = semctl(id, sem_id, SETVAL, val);
        // 2. Check value
        if(res == IPC_FAIL){
            error("Can't set value to semaphore");
            return FAILLURE;
        }
        // 3. Return success
        return SUCCESS;
    }

    return FAILLURE;
}

int set_val_all(int id, int val){
    int sem_number;
    int* arr;
    // 1. Get number of semaphores
    sem_number = get_num_sems(id);
    // 2. Allocate memory for array and fill data
    arr = (int*) malloc(sem_number * sizeof(int));
    for(int  i = 0; i < sem_number; ++i)
        arr[i] = val;
    // 3. Get semaphore data
    int res = semctl(id, 0, SETALL, arr);
    // 4. Check value
    if(res == IPC_FAIL){
        error("Can't set value to all semaphores");
        return FAILLURE;
    }
    // 5. Free resources and Return success
    free(arr);
    return SUCCESS;
}
//////////////////////////////////////////////////////////////////
void display_sem_inf(struct semid_ds* sem_data){
    struct ipc_perm perm = {};
    char string[128];
    char temp[32];
    char* ptr;
    string[0] = '\0';
    // 1. Configure string
    // 1.1. Save number of semaphores
    strcpy(string, "Number semaphores: ");
    ptr = itoa(temp, sem_data->sem_nsems, 10);
    strcat(string, ptr);
    strcat(string, "\n");
    // 1.2. Save permissions
    perm = sem_data->sem_perm;
    strmode(perm.mode, temp);
    strcat(string, "\tPermissions: ");
    strcat(string, temp);
    // 2. Display string
    info(string);
}

void display_sem_id_inf(int id, int sem_id){
    char string[128];
    char temp[32];
    char* ptr;
    // 0. Check semaphore id
    if(check_sem_num(id, sem_id)){
        // 1. Get concrete semaphore information
        int value = get_sem_val(id, sem_id);
        pid_t pid = get_sem_pid(id, sem_id);
        // 2. Configure string
        strcpy(string, "ID: ");
        ptr = itoa(temp, sem_id, 10);
        strcat(string, ptr);
        strcat(string, "\n");

        strcat(string, "\tVALUE: ");
        ptr = itoa(temp, value, 10);
        strcat(string, ptr);
        strcat(string, "\n");

        strcat(string, "\tPID: ");
        ptr = itoa(temp, pid, 10);
        strcat(string, ptr);
        // 3. Display string
        info(string);
    }
}
////////////////////////////////////////////////////////////////
char* itoa(char buf[32], int val, int base){
	char alphabet[] = "0123456789abcdef";
    buf[31] = '\0';
	int i = 30;
    
    if(val == 0){
        buf[i] = '0';
        --i;
    }

	for(; val && i ; --i, val /= base)
		buf[i] = alphabet[val % base];
	
    return &buf[i+1];	
}

void strmode(mode_t mode, char * buf) {
    const char chars[] = "rwxrwxrwx";
    for (size_t i = 0; i < 9; i++) {
        buf[i] = (mode & (1 << (8-i))) ? chars[i] : '-';
    }
    buf[9] = '\0';
}

int check_sem_num(int id, int sem_id){
    int sem_cnt = get_num_sems(id);
    if(sem_id >= sem_cnt){
        error("Incorrect sem number");
        return FAILLURE;
    }

    return SUCCESS;
}