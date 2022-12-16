#include "test_1.h"

int core_test_1(){
    int fl = open("test_1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if(fl){
        int oldstdout = dup(STDOUT_FILENO);
        int new_fl = dup2(fl, STDOUT_FILENO);
        close(fl);

        char* buff = "Hello world!";
        write(STDOUT_FILENO, buff, strlen(buff));
        
        dup2(oldstdout, STDOUT_FILENO);
        close(oldstdout);
    }
    else
        printf("[ERR]:> Failed to create test_1.txt");

    return 0;
}