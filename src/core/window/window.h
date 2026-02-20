#ifndef WINDOW_H
#define WINDOW_H

typedef struct h2ot3_window h2ot3_window_t;

typedef unsigned int uint;

h2ot3_window_t* new_h2ot3_window(uint, uint, uint, int);
void            free_h2ot3_window(h2ot3_window_t*);

int             get_h2ot3_window_properties();

#endif