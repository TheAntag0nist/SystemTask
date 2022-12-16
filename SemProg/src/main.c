#include <stdio.h>
#include <core.h>

int main(){
    // 0. Data Section
    struct semid_ds sem_data = {};
    // 1. Start programm
    info("Start semaphore programm");
    // 2. Create a semaphore
    info("Create semaphore");
    int sem_id = create_sem("sem", 3, 0);
    // 3. Get the semaphore information
    info("Get semaphore information");
    get_sem_inf(sem_id, &sem_data);
    display_sem_inf(&sem_data);
    // 4. Display foreach sem data
    info("Before update");
    display_sem_id_inf(sem_id, 0);
    display_sem_id_inf(sem_id, 1);
    display_sem_id_inf(sem_id, 2);
    // 5. Change semaphores value
    set_val(sem_id, 0, 5);
    set_val(sem_id, 1, 5);
    set_val(sem_id, 2, 5);
    // 6. Display foreach sem data
    info("After update");
    display_sem_id_inf(sem_id, 0);
    display_sem_id_inf(sem_id, 1);
    display_sem_id_inf(sem_id, 2);
    // 7. Change semaphores data
    int num = get_num_sems(sem_id);
    struct sembuf* buff = malloc(num * sizeof(struct sembuf));
    for(int i = 0; i < num; ++i){
        buff[i].sem_op = i - 1;
        buff[i].sem_num = i;
        buff[i].sem_flg = 0;
    }
    semop(sem_id, buff, num);
    free(buff);
    // 8. Display foreach sem data
    info("After update with semop");
    display_sem_id_inf(sem_id, 0);
    display_sem_id_inf(sem_id, 1);
    display_sem_id_inf(sem_id, 2);
    // 9. Destroy the semaphore
    info("Destroy semaphore");
    destroy_sem(sem_id);
    return 0;
}