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
}

char* get_mem(int id){
    return (char*) shmat(id, NULL, 0);
}

// 1. Default information message
void info(char* msg){
    printf("[INF]:> %s\n", msg);
}

// 2. Default debug message
void debug(char* msg){
    printf("[DBG]:> %s\n", msg);
}

// 3. Default warning message
void warning(char* msg){
    printf("[WRN]:> %s\n", msg);
}

// 4. Default fatal message and exit
void fatal(char* msg){
    printf("[FTL]:> %s\n", msg);
    inner_error();
    exit(-1);
}

// 5. Default error message
void error(char* msg){
    printf("[ERR]:> %s\n", msg);
    inner_error();
}

// 6. Default inner error message
void inner_error(){
    printf("[ERRNO]:> last_error = %d\n", errno);
}
