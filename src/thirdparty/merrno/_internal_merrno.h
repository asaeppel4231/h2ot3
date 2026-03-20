#ifndef INTERNAL_MERRNO_H
#define INTERNAL_MERRNO_H

#include <time.h>

#define MAX_MERRNO_USERS 5

typedef enum Merrno_Ec merrno_ec_t;

int _internal_init_merrno();
int _internal_free_merrno();

int _internal_get_merrno_token();
int _internal_remove_merrno_token(int token);

void _internal_set_merrno(merrno_ec_t ec, int token);
merrno_ec_t _internal_get_merrno_error_code(int token);

time_t _internal_get_merrno_timestamp(int token);

#endif