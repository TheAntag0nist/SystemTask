#ifndef STRING_H
#define STRING_H
#include <string.h>
#include <stdlib.h>

#define STR_MAX_LEN 1024
#define DEFAULT_STR_SIZE_ADD 32
#define FALSE 0
#define TRUE 1

typedef struct {
    size_t real_size;
    size_t size;
    char* data;
} my_string;

void init(my_string* struct_str);
int destroy(my_string* struct_str);

int add_char(my_string* struct_str, char c);
int add_string(my_string* struct_str, char* added);
int erase_char(my_string* struct_str, int pos);

size_t get_real_size(my_string* struct_str);
size_t get_size(my_string* struct_str);

char equals_struct(my_string* str1, my_string* str2);
char equals_string(my_string* str1, char* str2);
void clear(my_string* str);

#endif