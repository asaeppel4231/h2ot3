#ifndef HELPERS_H
#define HELPERS_H

#define GENERAL_DEBUG 1

#ifdef NDEBUG
#undef GENERAL_DEBUG
#define GENERAL_DEBUG 0
#endif

#if GENERAL_DEBUG == 1

// NOTE: Requires C99
#include <stdarg.h>

#define DEBUG "[ DEBUG ]: "

#define INFO     "[ INFO ]: "
#define WARN     "[ WARN ]: "
#define ERROR    "[ ERROR ]: "
#define CRITICAL "[ CRITICAL ]: "
#define FATAL    "[ FATAL ]: "

#define LOG_DEBUG(formated_string, ...) \
    printf( "\e[0;32m" DEBUG "\e[0m" formated_string, ##__VA_ARGS__);

#define LOG_FUNCTION_CALL(fn_name) \
    LOG_DEBUG(fn_name " was called.\n");

#define LOG_FUNCTION_BACK(fn_name) \
    LOG_DEBUG("Back in " fn_name "\n");

#define TYPE_CALL_ADDRESS 0
#define TYPE_CALL_VALUE   1

#define LOG_PARAMETER(ordinal_number, type_str, type_call, fmt, ...) \
    LOG_DEBUG(ordinal_number " parameter (type: " type_str ") with %s " fmt, \
              (type_call == TYPE_CALL_ADDRESS ? "address" : "value"), \
              ##__VA_ARGS__)

#define LOG_RETURN(type_str, type_call, fmt, ...) \
    LOG_DEBUG("Returning (type: " type_str ") %s " fmt, \
              (type_call == TYPE_CALL_ADDRESS ? "address" : "value"), \
              ##__VA_ARGS__)

#define TCA TYPE_CALL_ADDRESS
#define TCV TYPE_CALL_VALUE

#endif

#endif