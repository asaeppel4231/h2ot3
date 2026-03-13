#include "window.h"

#include <unistd.h>

int main(){
    h2ot3_window_t* window = new_h2ot3_window("Test Window", 1920, 1080, 0);
    if(window == NULL){
        return -1;
    }
    sleep(1);
    set_h2ot3_window_title(window, "ABC");
    sleep(1);
    free_h2ot3_window(window);
}
