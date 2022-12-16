#include "test_3.h"

#define INPUT 0
#define OUTPUT 1

int core_test_3(){
    int io[2], nbytes;
    pid_t pid;
    char string[] = "Hello, world!\n";
    char readbuffer[80];
    pipe(io);
    
    if((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }

    if(pid == 0) {
        close(io[INPUT]);
        write(io[OUTPUT], string, (strlen(string)+1));
        exit(0);
    }
    else {
        close(io[OUTPUT]);
        nbytes = read(io[INPUT], readbuffer, sizeof(readbuffer));
        printf("Read string: %s\n", readbuffer);
    }
}
