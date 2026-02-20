#ifndef WINDOW_H
#define WINDOW_H

typedef struct h2ot3_window h2ot3_window_t;

h2ot3_window_t* init_h2ot3_window(int, int, int, int);
void            free_h2ot3_window(h2ot3_window_t*);

int             get_h2ot3_window_properties();

#endif