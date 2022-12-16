#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(){
    char* str = "Hello world!";
    int fd;

    // FIFO file path
    char * myfifo = "/tmp/myfifo";
    // All access
    //mkfifo(myfifo, 0666);
    mknod(myfifo, 0666, 0);

    fd = open(myfifo, O_WRONLY);
    write(fd, str, strlen(str));
    close(fd);

    remove(myfifo);

    return EXIT_SUCCESS;
}