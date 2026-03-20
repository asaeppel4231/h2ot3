#include "_internal_merrno.h"
#include "merrno.h"

#include <stdlib.h>
#include <string.h>

merrno_ec_t global_merrno = MERRNO_EC_OK;

struct merrno_list_entry{
    time_t timestamp;
    merrno_ec_t error_code;
    int used;
};

typedef struct merrno_list_entry merrno_list_entry_t;

merrno_list_entry_t* merrno_list = NULL;

int merrno_was_initialized = 0;

int _internal_init_merrno(){
    if(merrno_list == NULL){
        merrno_list = malloc(sizeof(merrno_list_entry_t)*MAX_MERRNO_USERS); /*Allocate memory for MAX_MERRNO_USERS times merrno_list_entries*/
        if(merrno_list == NULL){
            return -1;
        }
        memset(merrno_list, 0, sizeof(merrno_list_entry_t)*MAX_MERRNO_USERS);
        return 0;
    }
    return -2;
}

int _internal_free_merrno(){
    free(merrno_list);
    return 0;
}

void _internal_init_if_not_already_initialized(){
    if(merrno_was_initialized == 0){
        _internal_init_merrno();
        merrno_was_initialized = 1;
    }
}

int _internal_get_merrno_token(){
    int found_entry = 0;
    _internal_init_if_not_already_initialized();
    int i;
    for(i=0; i<MAX_MERRNO_USERS; i++){
        if(merrno_list[i].used == 0){
            found_entry = 1;
            break;
        } 
    }
    if(found_entry == 1){
        merrno_list[i].used = 1;
        return i;
    }else{
        return -1;
    }
}

int _internal_is_in_range(int max, int min, int num){
    return num < max && num >= min;
}

int _internal_remove_merrno_token(int token){
    if(_internal_is_in_range(MAX_MERRNO_USERS, 0, token)){ /*Basic Security Check*/
        _internal_init_if_not_already_initialized();
        merrno_list[token].used = 0;
        int use_counter = 0;
        for(int i=0; i< MAX_MERRNO_USERS; i++){
            if(merrno_list[i].used != 0){
                break;
            }else{
                use_counter++;
            }
        }
        if(use_counter == MAX_MERRNO_USERS){
            _internal_free_merrno();
        }
        return 0;
    }
    return -1;
}


void _internal_set_merrno(merrno_ec_t ec, int token){
    if(_internal_is_in_range(MAX_MERRNO_USERS, 0, token)){ /*Basic Security Check*/
        _internal_init_if_not_already_initialized();
        merrno_list[token].timestamp = time(NULL);
        merrno_list[token].error_code = ec;
    }
}

merrno_ec_t _internal_get_merrno_error_code(int token){
    if(_internal_is_in_range(MAX_MERRNO_USERS, 0, token)){ /*Basic Security Check*/
        _internal_init_if_not_already_initialized();
        return merrno_list[token].error_code;
    }
    return -1;
}

time_t _internal_get_merrno_timestamp(int token){
    if(_internal_is_in_range(MAX_MERRNO_USERS, 0, token)){ /*Basic Security Check*/
        _internal_init_if_not_already_initialized();
        return merrno_list[token].timestamp;
    }
    return -1;
}