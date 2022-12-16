#include "test_2.h"

#define INPUT 0
#define OUTPUT 1
#define BUFF_SIZE 4096

int core_test_2(){
    int io[2];
    pid_t pid;

    pipe(io);
    pid = fork();

    char buf[BUFF_SIZE];
    buf[0] = '\0';

    if(pid == 0) {
        close(io[INPUT]);
        dup2(io[OUTPUT], STDOUT_FILENO);
        execlp("ls", "ls", "-l", NULL);
        exit(0);
    }
    else {
        close(io[OUTPUT]);
        int nbytes = read(io[INPUT], buf, BUFF_SIZE);
        printf("Read string: %s\n", buf);
    }

    return 0;
}