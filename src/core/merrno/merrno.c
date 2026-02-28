/**
 * @file merrno.h
 * @brief My own errno - implementation.
 * @author asaeppel4231
 * @version 1.0.1a
 */

#include "merrno.h"

merrno_ec_t global_merrno = MERRNO_EC_OK;

void set_merrno(merrno_ec_t ec){
    global_merrno = ec;
}

merrno_ec_t get_merrno(){
    return global_merrno;
}