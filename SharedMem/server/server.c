#include <global.h>
#include <core.h>

int sem_cnt = 2;
int sem_id = IPC_FAIL;

char buffer[512];

int main(void) {
	// 1. Create shared memory
	create_shared_memory("/tmp", 'a', 512);
	// 2.1. Write data to shared memory
	write_to_mem( shm_id, "Hello, world!");
	// 3. Destroy shared memory
	// destroy_shared_memory(shm_id);
	return 0;
}
