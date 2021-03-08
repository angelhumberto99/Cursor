#include <iostream>
#include "Cursor.h"

int main() { 
    while(true) {
        if (KBHIT()) {
            GETCHE();
            GETCH();
            break;
        }
        std::cout << "infinito" << std::endl;
        SLEEP(500);
    }
}