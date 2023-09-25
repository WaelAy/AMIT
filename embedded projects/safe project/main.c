#include "APP/app.h"

int main(void){
    APP_INIT();
    
    while (1)
    {
        APP_LOGIC();
    }

    return 0;
}
