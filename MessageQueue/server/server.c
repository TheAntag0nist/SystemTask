#define SERVER_PART
#include <global.h>

void* registration_thread(void* data);

int main(){
    // 1. Local variables
    char command[COMMAND_SIZE];
    char msg[MESSAGE_SIZE];
    pthread_t reg_thread;

    // 2. Init server
    create_msg_queue("/tmp", 97);
    pthread_create(&reg_thread, NULL, registration_thread, NULL);

    // 3. Main loop
    while(true){
        // 3.1. Read command
        printf("command:> ");
        scanf("%s", command);

        // 3.2. Send message
        if(!strcmp("send", command)){
            // 3.2.1. Read message
            printf("\tmsg = ");
            scanf("%s", msg);

            // 3.2.2. Read user id
            int user_id = -1;
            printf("\tUSER_ID = ");
            scanf("%d", &user_id);

            // 3.2.3. Send message to user
            send_message(msg_id, user_id, msg);
            continue;
        }

        // 3.3 Exit from program
        if(!strcmp("exit", command)){
            send_message(msg_id, DEBUG_MSG, "exit");
            break;
        }

        // 3.4. Multicast message
        if(!strcmp("multi_send", command)){
            printf("\tmsg = ");
            scanf("%s", msg);

            broadcast(msg_id, msg);
            continue;
        }

        // 3. On incorrect command
        warning("Incorrect command");
    }

    // 4. Destroy resources
    debug("Exit from program");
    pthread_cancel(reg_thread);
    destroy_msg_queue(msg_id);
    return EXIT_SUCCESS; 
}

void* registration_thread(void* data){
    // 1. Local variables
    msgbuf msg = {}; 
    int value = -1;

    // 2. Registration loop
    while(true) {
        // 2.1. Recieve message
        value = recieve_msg(msg_id, REQUEST_REGISTER, &msg);
        if(value != -1){
            
            info("Register new user");
            printf("User ID: %d\n", user_cnt);

            char data[] = { user_cnt, '\0'};
            send_message(msg_id, REQUEST_REGISTER, data);

            value = -1;
            ++user_cnt;
        }
    }

	pthread_exit(0);
}