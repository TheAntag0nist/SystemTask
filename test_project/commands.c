#include "commands.h"
#include "helpers/my_string.h"

#include "projects/1/test_1.h"
#include "projects/2/test_2.h"
#include "projects/3/test_3.h"

void main_loop(){
    my_string command;
    init(&command);

    while(TRUE){
        // clear command sring
        clear(&command);

        // default command
        printf("command:> ");
        read_command(&command);

        if(equals_string(&command, "help")){
            printf("help    - display that list\n");
            printf("test_1  - start test_1 program\n");
            printf("test_2  - start test_2 program\n"); 
            printf("version - display version of program\n"); 
            continue;
        }

        if(equals_string(&command, "version")){
            printf("TestProg\n\t version 1.0.0\n");
            continue;
        }

        if(equals_string(&command, "test_1")){
            core_test_1();
            continue;
        }

        if(equals_string(&command, "test_2")){
            core_test_2();
            continue;
        }

        if(equals_string(&command, "test_3")){
            core_test_3();
            continue;
        }

        // check command
        if(equals_string(&command, "exit"))
            break;
    }

    // free memory
    destroy(&command);
}

void read_command(my_string* command){
    int max_len = 32;
    char ch = '\0';
    int i = 0;

    while((ch = getchar()) != '\n' && i < max_len){
        add_char(command, ch);
        ++i;
    }
}