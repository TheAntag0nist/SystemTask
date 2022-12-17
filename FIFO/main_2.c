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
    char buffer[1024];
    int fd;

    // FIFO file path
    char * myfifo = "/tmp/myfifo";
    buffer[0] = '\0';

    fd = open(myfifo, O_RDONLY);
    read(fd, buffer, 1000);
    printf("%s\n", buffer);
    close(fd);

    return EXIT_SUCCESS;
}
