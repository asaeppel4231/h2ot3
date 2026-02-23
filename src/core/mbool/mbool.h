/*
This file is a drop-in-replacement of stdbool.h to make 
h2ot3 ANSI C compatible
*/
#ifndef MBOOL_H
#define MBOOL_H

#include <stddef.h>

typedef unsigned char mbool;

#define MTRUE 1
#define MFALSE 0

int mbool_is_false(mbool boolean){
    return boolean == MFALSE;
}

int mbool_is_true(mbool boolean){
    return boolean == MTRUE;
}

int set_mbool_false(mbool* boolean){
    if(boolean == NULL){
        return MFALSE;
    }
    *boolean = MFALSE;
    return MTRUE; 
}

int set_mbool_true(mbool* boolean){
    if(boolean == NULL){
        return MFALSE;
    }
    *boolean = MTRUE;
    return MTRUE;
}

#endif