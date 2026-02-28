/**
 * @file merrno.h
 * @brief My own errno - header.
 * @author asaeppel4231
 * @version 0.1
 */
#ifndef MERRNO_H
#define MERRNO_H

#include <stdlib.h> /**< for the NULL macro*/

#define SET_MERRNO_AND_RETURN_IF_NULL(ptr, retcode, alt, use_global) \
    do { \
        if ((ptr) == NULL) { \
            set_merrno(MERRNO_EC_ISNULL, alt, use_global); \
            return (retcode); \
        } \
    } while(0)

#define SET_MERRNO_AND_RETURN_VOID_IF_NULL(ptr, alt, use_global) \
    do { \
        if ((ptr) == NULL) { \
            set_merrno(MERRNO_EC_ISNULL, alt, use_global); \
            return; \
        } \
    } while(0)

#define SET_MERRNO_AND_RETURN_IF_MALLOC_FAILED(ptr, retcode, alt, use_global) \
    do { \
        if ((ptr) == NULL) { \
            set_merrno(MERRNO_EC_NO_MEMORY, alt, use_global); \
            return (retcode); \
        } \
    } while(0)

#define SET_MERRNO_AND_RETURN_IF_COND_FAILED(cond, ec, retcode, alt, use_global) \
    do { \
        if (!(cond)) { \
            set_merrno(ec, alt, use_global); \
            return (retcode); \
        } \
    } while(0)
    /**
 * @enum Merrno_Ec
 * @brief My own errno Error codes
 */
typedef enum Merrno_Ec{ 
    MERRNO_EC_OK = 0,       /**< No error occured, all OK*/
    MERRNO_EC_ISNULL,       /**< A pointer is NULL*/
    MERRNO_EC_OUT_OF_RANGE, /**< A number is out of range*/
    MERRNO_EC_NO_MEMORY,    /**< Cannot allocate memory with malloc */
    MERRNO_EC_INV_ARG       /**< Invalid Argument error in a function */
}merrno_ec_t;

extern merrno_ec_t global_merrno;

typedef int merrno_use_global_t;

/**
 * @brief Sets the merrno variable
 * @param ec The Error Code that's set
 * @param alt The pointer to the alternatively error code store variable
 * @param use_global It is 1, set_merrno will set the global merrno variable to ec, it is 0,
 * set_merrno will set alt to ec
 * @note For thread safety, prefer passing an alternative error code variable
 *       instead of using the global ::global_merrno.
 */
void set_merrno(merrno_ec_t ec, merrno_ec_t* alt, merrno_use_global_t use_global);

#endif