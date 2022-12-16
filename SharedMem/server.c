#include "global/global.h"

int main(void) {
	// 1. Create shared memory
	create_shared_memory("/tmp", 'a', 512);
	// 2. Write data to shared memory
	write_to_mem( shm_id, "Hello, world!");
	// 3. Destroy shared memory
	// destroy_shared_memory(shm_id);
	return 0;
}
