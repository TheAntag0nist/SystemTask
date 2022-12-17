#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pthread.h>

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

// 0. Global defines
#define TRUE 1
#define FALSE 0

#define true 1
#define false 0

#ifdef USER_PART
extern int user_id;
#endif
#ifdef SERVER_PART
extern char user_cnt;
#endif
extern int msg_id;

// 1. Message types
// User ID equals Message Type 
// (user_id <-> msgbuf.type)
#define DEBUG_MSG 1
#define REQUEST_REGISTER 2
#define ANSWER_REGISTER 3

#define USER_START_ID 32
#define MESSAGE_SIZE 128
#define COMMAND_SIZE 128
#define INCORRECT_USER_ID -1

// 2. Default struct
// TODO: add dynamic message size
typedef struct msgbuf{
    long type;
    char data[MESSAGE_SIZE];
} msgbuf;

// 3. Message functions
void create_msg_queue(char* path, int uid);
void destroy_msg_queue(int msg_id);

// 4. On Send message
void send_message(int id, int msg_type, char* data);
void broadcast(int id, char* data);

// 5. On Receive message
int recieve_msg_wait(int id, long msg_type, msgbuf* buf);
int recieve_msg(int id, long msg_type, msgbuf* buf);

// 6. On register user
int on_register_user();

// 7. Display messages
void warning(char* msg);
void debug(char* msg);
void fatal(char* msg);
void error(char* msg);
void info(char* msg);
void inner_error();