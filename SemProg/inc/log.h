#ifndef LOG_H
#define LOG_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

void warning(char* msg);
void debug(char* msg);
void fatal(char* msg);
void error(char* msg);
void info(char* msg);
void inner_error();

#endif