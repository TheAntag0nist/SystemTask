#define USER_PART
#include <global.h>

void on_debug_message();
void on_user_message();
void register_user();

int main(){
    // 1. Init client
    create_msg_queue("/tmp", 97);
    register_user();

    // 2. Main loop
    while(true){
        // 2.1. On recieve different 
        //      types of messages
        on_user_message();
        on_debug_message();
    }

    // 3. Close client
    return EXIT_SUCCESS; 
}

void register_user(){
    // 1. Register
    user_id = on_register_user(msg_id);
    if(user_id == INCORRECT_USER_ID)
        fatal("INCORRECT_USER_ID");

    // 2. Display user_id
    printf("user_id: %d\n", user_id);
    debug("Wait for messages");
}

void on_user_message(){
    // 1. Local variables
    msgbuf msg = {}; 
    int value = -1;
    
    // 2. Recieve message
    value = recieve_msg(msg_id, user_id, &msg);
    if(value != -1 && value != 0){
        // 3. Default print message
        printf("[USR_MSG]:> %s\n", msg.data);

        // 4. Exit if data equal break
        if(!strcmp("exit", msg.data)){
            info("Close client");
            exit(0);
        }
    }
}

void on_debug_message(){
    // 1. Local variables
    msgbuf msg = {}; 
    int msg_len = -1;

    // 2. Recieve message and message length
    msg_len = recieve_msg(msg_id, DEBUG_MSG, &msg);
    
    // 3. Default display
    if(msg_len != -1 && msg_len != 0){
        printf("[DBG_MSG]:> %s\n", msg.data);
        
        // 4. Exit if data equal break
        if(!strcmp("exit", msg.data)){
            info("Close client");
            exit(0);
        }
    }
}