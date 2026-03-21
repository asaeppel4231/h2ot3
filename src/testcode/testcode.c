#include "merrno.h"

#include "window.h"

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

int main(){
    h2ot3_window_t* window = new_h2ot3_window("Test Window", 1920, 1080, 0);
    if(window == NULL){
        return -1;
    }
    sleep(1);
    set_h2ot3_window_title(window, "ABC");
    printf("Tests for merrno are running...\n");
    for(int i=0; i<10; i++){
        printf("State of merrno token %d: %d\n", i, get_merrno_error_code(i));
    }
    set_h2ot3_window_title(NULL, "ABC");
    for(int i=0; i<10; i++){
        printf("State of merrno token %d: %d\n", i, get_merrno_error_code(i));
    }
    sleep(1);
    free_h2ot3_window(window);
}
