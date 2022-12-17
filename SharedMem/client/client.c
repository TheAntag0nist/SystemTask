#include <global.h>
#include <core.h>

char buffer[512];

int main(void) {
	// 1. Create shared memory
	create_shared_memory("/tmp", 'a', 512);
	// 2. Read from shared memory
	read_from_mem( shm_id, buffer);
	// 3. Destroy shared memory
	destroy_shared_memory(shm_id);
	return 0;
}