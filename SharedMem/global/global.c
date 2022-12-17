#include "global.h"

int shm_id = -1;

void create_shared_memory(char* path, int uid, int size){
    // 1. Create unique key
    key_t key = ftok(path, uid);
    // 2. Create shared memory 
    shm_id = shmget(key, size, IPC_CREAT | 0666);
    // 3. Check id
    if(shm_id == -1)
        fatal("Can't create shared memory");
    // 4. Info message
    info("Shared memory was created"); 
}

void destroy_shared_memory(int id){
    // 1. Destroying shared memory
    shmctl( id, IPC_RMID, NULL);
    // 2, Display message
    info("Shared memory was destroyed");
}

void detach_shared_memory(void* ptr){
    // 1. Detaching shared memory
    shmdt(ptr);
    // 2. Display message
    info("Shared memory was detached");
}

// TODO: upgrade (currently unsafe)
void write_to_mem(int id, char* buf){
    // 1. Get data pointer
    char* data = (char*) shmat(id, NULL, 0);
    // 2. Copy data to shared memory
    strcpy(data, buf);
    // 3. Display message
    info("Data was copied to shared memory");
    // 4. Detaching shared memory
    detach_shared_memory(data);
}

// TODO: upgrade (currently unsafe)
void read_from_mem(int id, char* buf){
    // 1. Get data pointer
    char* data = (char*) shmat(id, NULL, 0);
    // 2. Read data from shared memory
    strcpy(buf, data);
    // 3. Display message
    info("Data was readed from memory");    
    // 4. Detaching shared memory
    detach_shared_memory(data);
}

char* get_mem(int id){
    return (char*) shmat(id, NULL, 0);
}
