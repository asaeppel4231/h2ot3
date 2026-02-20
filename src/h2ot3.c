#include "h2ot3.h"
#include "window/window.h"

int main(){
    h2ot3_window_t* window = new_h2ot3_window(180, 240, 5, 0);
    free_h2ot3_window(window);    
}
