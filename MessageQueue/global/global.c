#ifndef GLOBAL_H
#define GLOBAL_H

#include "global.h"

int user_id = INCORRECT_USER_ID;
char user_cnt = USER_START_ID;
int msg_id = -1;

void create_msg_queue(char* path, int uid){    
    // 1. Unique Key
    key_t key;

    // 2. Create key
    key = ftok(path, 'a');
    printf("key: %x\n", key);

    // 3. Create message queue resource
    msg_id = msgget(key, 0666 | IPC_CREAT);
    printf("msg_id: %x\n", msg_id);

    // 4. If message queue was not created
    if(msg_id == -1)
        fatal("INCORRECT_MSG_ID");
}

void destroy_msg_queue(int msg_id){
    // 1. Display the message
    debug("Destroying message queue");
    // 2. Destroying message queue
    msgctl( msg_id, IPC_RMID, NULL);
}

void send_message(int id, int msg_type, char* data){
    // 1. Local variables 
    int data_len = strlen(data);
    msgbuf msg = {};    

    // 2. Check message size
    if(data_len > MESSAGE_SIZE - 1){
        data_len = MESSAGE_SIZE - 1;
        data[MESSAGE_SIZE - 1] = '\0';
    }

    // 3. Save data to struct
    strncpy(msg.data, data, data_len);
    msg.type = msg_type;

    // 4. Display data
    //printf("\tMessage ID: %d\n", id);
    //printf("\tSend type: %ld\n", msg.type);
    //printf("\tSend data: %s\n", msg.data);

    // 5. Send data
    int result = msgsnd(id, &msg, MESSAGE_SIZE, 0);
    if(result == -1)
        error("Can't send message");
    
    return;
}

void broadcast(int id, char* data){
    for(int i = 0; i < user_cnt - USER_START_ID; ++i)
        send_message(id, USER_START_ID + i, data);
}

int recieve_msg(int id, long msg_type, msgbuf* buf){
    // 1. Recive message
    return msgrcv(id, buf, MESSAGE_SIZE, msg_type, IPC_NOWAIT);
}

int recieve_msg_wait(int id, long msg_type, msgbuf* buf){
    // 1. Wait message and recieve
    return msgrcv(id, buf, MESSAGE_SIZE, msg_type, 0);
}

int on_register_user(int id) {
    // 1. Local variables
    int user_id = INCORRECT_USER_ID;
    msgbuf buffer = {};

    // 2. Send message
    send_message(id, REQUEST_REGISTER, "on_register");

    // 3. Recieve message
    recieve_msg_wait(id, REQUEST_REGISTER, &buffer);
    
    // 4. Save user_id
    user_id = buffer.data[0];
    return user_id;
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

#endif