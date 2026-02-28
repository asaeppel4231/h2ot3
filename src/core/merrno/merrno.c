/**
 * @file merrno.h
 * @brief My own errno - implementation.
 * @author asaeppel4231
 * @version 0.1
 */

#include "merrno.h"

merrno_ec_t global_merrno = MERRNO_EC_OK;

void set_merrno(merrno_ec_t ec, merrno_ec_t* alt, merrno_use_global_t use_global){
    if(use_global == 1){
        global_merrno = ec;
    }
    else if (use_global == 0){
        if( NULL != alt){
            *alt = ec;
        }
    }
}