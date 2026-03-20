/**
 * @file merrno.h
 * @brief My own errno - implementation.
 * @author asaeppel4231
 * @version 1.0.2
 */

#include "merrno.h"
#include "_internal_merrno.h"

int get_merrno_token(){
    return _internal_get_merrno_token();
}

int remove_merrno_token(int token){
    return _internal_remove_merrno_token(token);
}

void set_merrno(merrno_ec_t ec, int token){
    _internal_set_merrno(ec, token);
}

merrno_ec_t get_merrno_error_code(int token){
    return _internal_get_merrno_error_code(token);
}

time_t get_merrno_timestamp(int token){
    return _internal_get_merrno_timestamp(token);
}