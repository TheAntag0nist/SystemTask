#include "log.h"

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