#include "my_string.h"

void init(my_string* struct_str){
    struct_str->data = NULL;
    struct_str->size = 0;
}

int add_char(my_string* struct_str, char c){
    if(struct_str->data == NULL){
        struct_str->data = (char*) malloc(DEFAULT_STR_SIZE_ADD);
        struct_str->real_size = DEFAULT_STR_SIZE_ADD;
        struct_str->size = 1;
    }
    else{
        // copy string in temp
        char* temp_str = (char*) malloc(struct_str->size);
        memcpy(temp_str, struct_str->data, struct_str->size);
        
        int old_size = struct_str->size;
    
        // resize
        if(struct_str->size == struct_str->real_size) {
            size_t new_size = struct_str->real_size + DEFAULT_STR_SIZE_ADD;
            struct_str->real_size = new_size;

            struct_str->data = realloc(struct_str->data, new_size);
            memcpy( struct_str->data, temp_str, old_size);
        }
    }

    ++struct_str->size;
    int pos = struct_str->size;
    struct_str->data[pos - 2] = c;
    struct_str->data[pos - 1] = '\0';

    return 0;
}

int erase_char(my_string* struct_str, int pos){

    return 0;
}

int add_string(my_string* struct_str, char* added){
    size_t i;

    size_t len = strlen(added);
    for(i = 0; i < len; ++i)
        add_char(struct_str, added[i]);

    return 0;
}

size_t get_real_size(my_string* struct_str){
    return struct_str->real_size;
}

size_t get_size(my_string* struct_str){
    return struct_str->size;
}

int destroy(my_string* struct_str){
    struct_str->real_size = 0;
    free(struct_str->data);
    struct_str->size = 1;
    struct_str->data = NULL;
    return 0;
}

char equals_struct(my_string* str1, my_string* str2){
    size_t str1_size = str1->size;
    size_t str2_size = str2->size;

    size_t size_1 = 0;
    size_t size_2 = 0;

    char flag = TRUE;

    while(size_1 < str1_size && size_2 < str2_size) { 
        if(str1->data[size_1] != str2->data[size_2] )
            flag = FALSE;

        ++size_2;
        ++size_1;
    }
    
    return flag;
}

char equals_string(my_string* str1, char* str2){
    size_t str1_size = str1->size;
    size_t str2_size = strlen(str2);

    size_t size_1 = 0;
    size_t size_2 = 0;

    char flag = TRUE;

    while(size_1 < str1_size && size_2 < str2_size) { 
        if(str1->data[size_1] != str2[size_2] )
            flag = FALSE;

        ++size_2;
        ++size_1;
    }
    
    return flag;
}

void clear(my_string* str){
    str->size = 1;
}